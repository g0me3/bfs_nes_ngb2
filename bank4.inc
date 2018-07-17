
		ORG $8000

		BANK_START $04

		SECTION_START

; =============== S C R I P T ==========================s====================
_scr13_slow_moving_slime:
		NJSR			_nsub_sarg1_rand08_mul8_set		; choose random initial direction
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select			; calculate sprite idx from base and divider
			NARGB		$04,$40							; base 04, divider 40
		SDELAY			$01
		SPR_IDX_SET		1,$FF							; blink next frame
		SLOOP_END										; blink 10 times before activate

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_slow_moving_slime_active:
		NBG_HNDL_SET	_nbgsub_slow_moving_slime_ctest	; set beamer test background sub
_sloc_38012:
		SLOOP_BEGIN		$0A								; every movement loop consists of two parts
		SJSRS			_slow_moving_slime_move			; 10 iterations to move in one direction
		SARG_ALU		SARG1,_ADC,$08					; then 10 iteration in opposite direction
		SLOOP_END										; direction selected randomly before this
		SLOOP_BEGIN		$0A
		SJSRS			_slow_moving_slime_move
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SJMPS			_sloc_38012

; =============== S C R I P T  S U B R O U T I N E =====s====================
_slow_moving_slime_move:
		NJSR			_nsub_speed_dir_select			; calculate linear move params
			NARGB		$80,$00
		SSCRIPT1_SET	_scr_slime_spr_anim				; load secondary animation script
		SLOOP_BEGIN		$14
		SDELAY			$01								; first tests for horizontal movements
		NJSR			_nsub_obj_to_room_x_ctestA		; test for bounce if any obstacles in front
		SBCCS			_sloc_38048
		NJSR			_nsub_cur_obj_sarg1_hor_complement	; if test pass, bounce move direction
		NJSR			_nsub_speed_dir_select			; recalclulate move params
			NARGB		$80,$00
		SSCRIPT1_SET	_scr_slime_spr_anim				; also reinit animation
_sloc_38048:
		NJSR			_nsub_obj_to_room_y_ctestA		; continue the same for vertical movements
		SBCCS			_sloc_3805A
		NJSR			_nsub_cur_obj_sarg1_vert_complement	; bounce
		NJSR			_nsub_speed_dir_select
			NARGB		$80,$00							; reset sprites again
		SSCRIPT1_SET	_scr_slime_spr_anim
_sloc_3805A:
		SLOOP_END										; move for 20 cycles
		SRET

; =============== S C R I P T ==========================s====================
_scr_slime_spr_anim:
		NJSR			_nsub_spr_dir_select			; calculate spr idx from movement direction
			NARGB		$04,$40							; using base sprite idx
_sloc_38061:
		SPR_IDX_ADD_IMM 7,$04							; animate +4, -4
		SPR_IDX_ADD_IMM 7,$FC
		SJMPS			_sloc_38061

; =============== S C R I P T ==========================s====================
_scr_slow_moving_slime_stun:
		NBG_HNDL_SET	_nbgsub_slime_catch_testA		; background test if catched or let alone
		SJSRS			_ssub_slime_stun_in_process		; keep stunned unless release, timeout or catched
		NJSR			_nsub_get_obj_stun_state		; now test what current state of obj
		SJMP_SW			$03
		SCASE			_scr_slow_moving_slime_active	; if released, keed going as usual
		SCASE			_scr_slime_catch_anim_L			; if catched, do anim
		SCASE			_scr_slime_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_slime_stun_in_process:
		SARG_SET		SARG0,$02						; reinit stun flag
_sloc_3807C:
		SJSRS			_ssub_slime_spr_stun_anim		; animate stunned while hold on beam
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3807C						; when beam released
		SLOOP_BEGIN		$14								; keep being stunned for 2/3 seconds
		SJSRS			_ssub_slime_spr_stun_anim		; (20 cycles by 2 frames each) then exit
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_slime_spr_stun_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$04,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_slime_catch_anim_L:
		SARG_SET		SARG1,$10						; base catch anim for all slimes in hor orientation
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_slime_catch_anim_R:
		SARG_SET		SARG1,$12						; same for vert orientation
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_slow_moving_slime_ctest:
		LDX		#$08						; wait while collide with beam
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_380B1
		JSR		_cur_thread_reload_param	; then reload object's script to
		.WORD	_scr_slow_moving_slime_stun	; stunned mode
		RTS
loc_380B1:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_slime_catch_testA:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X				; test if catched
		BPL		locret_380D1
		LSR
		LDA		#$01
		STA		_scores_obj_value			; set the corresponding script
		BCS		loc_380CC					; when beamed
		JSR		_cur_thread_reload_param
		.WORD	_scr_slime_catch_anim_L
		RTS
loc_380CC:
		JSR		_cur_thread_reload_param
		.WORD	_scr_slime_catch_anim_R
locret_380D1:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_sarg1_rand08_mul8_set:
		LDA		#$08
		JSR		_rand
		ASL
		ASL
		ASL
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr14_fast_moving_slime:
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; fast slime always targeted on player
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select			; also do initial blink
			NARGB		$04,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_fast_moving_slime_active:
		NBG_HNDL_SET	_nbgsub_fast_moving_slime_ctest	; ai mostly the same as slow slime
_sloc_38249:
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_slime_spr_anim
		SLOOP_BEGIN		$0A								; shorter retarget periods
		SDELAY			$01
		NJSR			_nsub_obj_to_room_x_ctestA
		SBCCS			_sloc_38268
		NJSR			_nsub_cur_obj_sarg1_hor_complement
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00							; faster speed than slow slime
		SSCRIPT1_SET	_scr_slime_spr_anim
_sloc_38268:
		NJSR			_nsub_obj_to_room_y_ctestA
		SBCCS			_sloc_3827A
		NJSR			_nsub_cur_obj_sarg1_vert_complement
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_slime_spr_anim
_sloc_3827A:
		SLOOP_END
		NJSR			_nsub_obj_to_beamer_slow_turn	; not sure now what this routine does
			NARGB		$08								; but looks like some kind of readjust vectors
		SJMPS			_sloc_38249

; =============== S C R I P T ==========================s====================
_scr_fast_moving_slime_stun:
		NBG_HNDL_SET	_nbgsub_slime_catch_testB
		SJSR			_ssub_slime_stun_in_process
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_fast_moving_slime_active
		SCASE			_scr_slime_catch_anim_L
		SCASE			_scr_slime_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_fast_moving_slime_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_382A2
		JSR		_cur_thread_reload_param
		.WORD	_scr_fast_moving_slime_stun
		RTS
loc_382A2:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_slime_catch_testB:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_382C2
		LSR
		LDA		#$02						; both are the same except scores
		STA		_scores_obj_value
		BCS		loc_382BD
		JSR		_cur_thread_reload_param
		.WORD	_scr_slime_catch_anim_L
		RTS
loc_382BD:
		JSR		_cur_thread_reload_param
		.WORD	_scr_slime_catch_anim_R
locret_382C2:
		RTS

; =============== S C R I P T ==========================s====================
_scr15_trolley_kick_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_scr_trolley_kick_slime_trolley

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SARG_SET		SARG1,$40						; he is not moving, keep
		SLOOP_BEGIN		$10								; face in one particular direction
		SPR_IDX_SET		1,$05							; sprite also fixed, easy
		SPR_IDX_SET		1,$FF							; do blink
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_trolley_kick_slime_active:
		NBG_HNDL_SET	_nbgsub_trolley_kick_slime_ctest
_sloc_382D9:
		NJSR			_nsub_new_thread_start			; deploy trolley as soon as appear
			NARGB		_scr15_trolley_kick_slime_idx
			NARGB		$00,$08
			NARGB		_scr_trolley_kick_slime_trolley_idx+1
			NARGB		$00
		SLOOP_BEGIN		$0A								; still phase, just animate
		SPR_IDX_SET		7,$05
		SPR_IDX_SET		7,$09
		SLOOP_END
		SJMPS			_sloc_382D9						; repeat

; =============== S C R I P T ==========================s====================
_scr_trolley_kick_slime_stun:
		NBG_HNDL_SET	_nbgsub_slime_catch_testB
		SJSR			_ssub_slime_stun_in_process
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_trolley_kick_slime_active
		SCASE			_scr_slime_catch_anim_L
		SCASE			_scr_slime_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_trolley_kick_slime_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3830B
		JSR		_cur_thread_reload_param
		.WORD	_scr_trolley_kick_slime_stun
		RTS
loc_3830B:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
_scr_trolley_kick_slime_trolley:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_trolley_kick_slime_trolley_ctest
		POS_X_DELTA_SET 0,$00,$02						; move right
		SPR_IDX_SET		0,$14							; single sprite
		SUSPEND											; script suspended, but obj is moving!

; =============== S U B R O U T I N E ======n================================
_nbgsub_trolley_kick_slime_trolley_ctest:
		LDX		#$0D
		LDY		#$0E
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S C R I P T ==========================s====================
_scr16_still_throw_forward_slime:
		NJSR			_nsub_obj_sarg_add_imm_test		; still slimes does not blink
			NARGB		SARG0,$FF						; they sitting on its places alays
		SJMP_SW			$01
		SCASE			_scr_still_throw_forward_slime_proj

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
_scr_still_throw_forward_slime_active:
		NBG_HNDL_SET	_nbgsub_still_throw_forward_slime_ctest
		NJSR			_nsub_apu_snd_load				; they when appear
			NARGB		_snd08_idx
_sloc_38363:
		SLOOP_BEGIN		$03
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; calcs to turn face to beamer
		NJSR			_nsub_spr_dir_select			; update directions
			NARGB		$04,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04							; initial anim slowly
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$04
		SLOOP_END
		NJSR			_nsub_new_thread_start			; then deploy projectile
			NARGB		_scr16_still_throw_forward_slime_idx
			NARGB		$00,$00
			NARGB		_scr_still_throw_forward_slime_proj_idx+1
			NARGB		$00
		SJMPS			_sloc_38363

; =============== S C R I P T ==========================s====================
_scr_still_throw_forward_slime_stun:
		NBG_HNDL_SET	_nbgsub_slime_catch_testB
		SJSR			_ssub_slime_stun_in_process
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_still_throw_forward_slime_active
		SCASE			_scr_slime_catch_anim_L
		SCASE			_scr_slime_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_still_throw_forward_slime_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_383A1
		JSR		_cur_thread_reload_param
		.WORD	_scr_still_throw_forward_slime_stun
		RTS
loc_383A1:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
_scr_still_throw_forward_slime_proj:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_still_throw_forward_slime_proj_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$80,$01
		NJSR			_nsub_still_throw_forward_slime_proj_spr_set
_sloc_383D0:
		SDELAY			$07								; every thrown object has 4 frames animations
		SPR_IDX_INC		7
		SPR_IDX_INC		7
		SPR_IDX_INC		7
		SPR_IDX_ADD_IMM 0,$FD
		SJMPS			_sloc_383D0

; =============== S U B R O U T I N E ======n================================
_nbgsub_still_throw_forward_slime_proj_ctest:
		LDX		#$07
		LDY		#$08
		JSR		_obj_to_player_ctest		; NOTE, this projecties can't avoid
		JSR		_cur_obj_out_of_screen_test	; obstacles! you can hide!
		JMP		_obj_to_room_macro_ctest_raw

; =============== S U B R O U T I N E ======n================================
_nsub_still_throw_forward_slime_proj_spr_set:
		LDA		#$00
		JSR		_rand
		AND		#$0C
		CLC
		ADC		#$15
		LDX		_cur_trd_slot
		STA		_obj_spr_idx,X
		RTS

; =============== S C R I P T ==========================s====================
_scr1B_court_chair:
		SLOOP_BEGIN		$10								; simple invincible objects
		SPR_IDX_SET		1,$25							; also blinking at start
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SARG_SET		SARG2,$00
		NBG_HNDL_SET	_nbgsub_court_chair_ctest
_sloc_38442:
		SPR_IDX_SET		0,$25							; start from still position
		SDELAY			$0A
		NJSR			_nsub_apu_snd_load				; chair sound
			NARGB		_snd12_idx
		POS_Y_MOVE		0,$FF							; slowly lift up
		SPR_IDX_INC		3								; the chair is actually moving on grid
		POS_Y_MOVE		0,$FE							; 16x16 per tile, shadow of chairs is
		SPR_IDX_INC		3								; part of its sprite as well, so
		POS_Y_MOVE		0,$FE							; technically it won't move up
		SPR_IDX_INC		3								; sprite just shrinks up
		POS_Y_MOVE		0,$FD
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FC
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FA
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FA
		SPR_IDX_INC		3
		NJSR			_nsub_court_chair_move			; replay movements data
		POS_MOVE_STOP	0
		SDELAY			$10
		POS_Y_MOVE		0,$06
		SPR_IDX_DEC		1
		POS_Y_MOVE		0,$06
		SPR_IDX_DEC		1
		POS_Y_MOVE		0,$04
		SPR_IDX_DEC		1
		POS_Y_MOVE		0,$05
		SPR_IDX_ADD_IMM 1,$FE
		POS_Y_MOVE		0,$03
		SJMPS			_sloc_38442

; =============== S U B R O U T I N E ======n================================
_nbgsub_court_chair_ctest:
		LDX		#$0B
		LDY		#$0C
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E ======n================================
_nsub_court_chair_move:
		LDX		_cur_trd_slot
		LDY		_trds_args1,X				; NOTE, sarg1 is a parameter of object list data
		LDA		off_384BF,Y					; there are total 4 chair used (0-3)
		STA		_ptr06						; the array for animation data is 5 items long
		LDA		off_384C4,Y					; so one is unused. seems they planned 5 chairs
		STA		_ptr06+1					; in this place, but only 4 are allowed at once
		LDY		_trds_args2,X				; in the released version.
loc_38491:
		TYA
		PHA
		LDA		(_ptr06),Y
		BPL		loc_3849C					; loop back to the beginning of sequence
		PLA
		LDY		#$00
		BEQ		loc_38491
loc_3849C:
		TAY									; read delta table, move one direction at once
		LDA		byte_384BA+1,Y
		STA		_obj_x_delta,X
		LDA		byte_384BA,Y
		STA		_obj_y_delta,X
		PLA
		TAY
		INY
		LDX		_cur_trd_scr_slot			; load movement duration (delay)
		LDA		(_ptr06),Y
		STA		_trds_scr_delay,X
		INY
		LDX		_cur_trd_slot				; store position
		TYA
		STA		_trds_args2,X
		RTS

; 0 = y--	U
; 1 = x++	R
; 2 = y++	D
; 3 = x--	L
;
;  0123456789AB
; 0
; 1 4* **** **
; 2
; 3 ** 3**  **
; 4
; 5 *2 **** 1*
; 6
; 7 ** *0** **
; 8
;
byte_384BA:
		.BYTE	$FF,$00,$01,$00,$FF
off_384BF:
		.BYTE	<[_court_chair_seq0]		; START: 57
		.BYTE	<[_court_chair_seq1]
		.BYTE	<[_court_chair_seq2]
		.BYTE	<[_court_chair_seq3]
;		.BYTE	<[_court_chair_seq4]		; unused
off_384C4:
		.BYTE	>[_court_chair_seq0]
		.BYTE	>[_court_chair_seq1]
		.BYTE	>[_court_chair_seq2]
		.BYTE	>[_court_chair_seq3]
;		.BYTE	>[_court_chair_seq4]		; unused
_court_chair_seq0:
		.BYTE	$03,$20	; L2				; 57,37,07,37,57,37,57,87,57
		.BYTE	$03,$30 ; L3
		.BYTE	$01,$30 ; R3
		.BYTE	$01,$20 ; R2
		.BYTE	$03,$20 ; L2
		.BYTE	$01,$20 ; R2
		.BYTE	$01,$30 ; R3
		.BYTE	$03,$30 ; L3
		.BYTE	$FF
_court_chair_seq1:
		.BYTE	$02,$10 ; D1				; 95,96,98,78,76,B6,96,95
		.BYTE	$02,$20 ; D2
		.BYTE	$03,$20 ; L2
		.BYTE	$00,$20 ; U2
		.BYTE	$01,$40 ; R4
		.BYTE	$03,$20 ; L2
		.BYTE	$00,$10 ; U1
		.BYTE	$FF
_court_chair_seq2:
		.BYTE	$03,$20 ; L2				; 25,05,05,04,24,04,03,03,05,02
		.BYTE	$00,$00 ; U0
		.BYTE	$00,$10 ; U1
		.BYTE	$01,$20 ; R2
		.BYTE	$03,$20 ; L2
		.BYTE	$00,$10 ; U1
		.BYTE	$00,$00 ; U0
		.BYTE	$02,$20 ; D2
		.BYTE	$01,$20 ; R2
		.BYTE	$FF
_court_chair_seq3:
		.BYTE	$00,$10 ; U1				; 43,42,40,50,50,52,52,52,42,,43,43
		.BYTE	$00,$20 ; U2
		.BYTE	$01,$10 ; R1
		.BYTE	$00,$00 ; U0
		.BYTE	$02,$20 ; D2
		.BYTE	$00,$00 ; U0
		.BYTE	$00,$00 ; U0
		.BYTE	$03,$10 ; L1
		.BYTE	$02,$10 ; D1
		.BYTE	$00,$00 ; U0
		.BYTE	$FF
;_court_chair_seq4:
;		.BYTE	$03,$10 ; L1				; judging from area this chair is jumping on
;		.BYTE	$00,$00 ; U0				; there are two possible starting points for it
;		.BYTE	$01,$10 ; R1				; one is the same as point 01 - 95, another
;		.BYTE	$00,$10 ; U1				; is 11 - top-left corner of the field
;		.BYTE	$00,$00 ; U0				; 11,01,11,10,10,00,30,31,31,11,11,11
;		.BYTE	$03,$10 ; L1
;		.BYTE	$01,$30 ; R3
;		.BYTE	$02,$10 ; D1
;		.BYTE	$00,$00 ; U0
;		.BYTE	$03,$20 ; L2
;		.BYTE	$00,$00 ; U0
;		.BYTE	$00,$00 ; U0
;		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_scr1D_air_hammer_miner:
		SLOOP_BEGIN		$10								; just blink at the beginning
		SPR_IDX_SET		1,$2F
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
; NOTE: as against most of the objects, structure of this one is different
; they do animations work in loops inside main active section of script
; and wall collision tests in native bg sub
; other scripts doint animations in secondary scripts, and wall collisions inside
; main active section.
; anyway, both methods are valid here, maybe this one a bit faster if there a lot
; objects on the screen, need testing...
; in any case, if we can set all work to native subs, why we need scripts then? lol
; the same work may be programmed in scripts using eisting commands actually...
;
_nbgsub_air_hammer_miner_active:
		NBG_HNDL_SET	_nbgsub_air_hammer_miner_ctest
_sloc_385BC:
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; object also tergeted on beamer
		POS_MOVE_STOP	0								; first we run animation while
		SLOOP_BEGIN		$08								; standing still
		SPR_IDX_SET		2,$2D
		SPR_IDX_INC		2
		SLOOP_END
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00							; then run in destination point
		SLOOP_BEGIN		$1E
		SPR_IDX_SET		2,$2D
		SPR_IDX_INC		2
		SLOOP_END
		SJMPS			_sloc_385BC						; repeat

; =============== S C R I P T ==========================s====================
_scr_air_hammer_miner_stun:
		NBG_HNDL_SET	_scr_miner_catch_testA
		SARG_SET		SARG0,$02
_sloc_385DA:
		SPR_IDX_SET		1,$2D							; shake if beamed
		SPR_IDX_SET		1,$2F
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_385DA
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$2D							; final shake if let go
		SPR_IDX_SET		1,$2F
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state		; return to one of the states
		SJMP_SW			$03
		SCASE			_nbgsub_air_hammer_miner_active
		SCASE			_scr_miner_catch_anim_L
		SCASE			_scr_miner_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_miner_catch_anim_L:
		SARG_SET		SARG1,$30
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_miner_catch_anim_R:
		SARG_SET		SARG1,$32
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_air_hammer_miner_ctest:
		JSR		_nsub_obj_to_room_x_ctestA	; NOTE: in case of this object
		BCC		loc_38611					; they handle its collisions at native
		LDX		_cur_trd_slot				; bg subroutine, while all others objects
		LDA		#$00						; doing this in active section of its scripts!
		STA		_obj_x_speed,X				; when reach obstacles, stop in this direction!
		STA		_obj_x_delta,X
loc_38611:
		JSR		_nsub_obj_to_room_y_ctestA
		BCC		loc_38620					; when stopped, just wait to next retarget
		LDX		_cur_trd_slot				; move again
		LDA		#$00
		STA		_obj_y_speed,X				; there are a script commands to write imm to delta
		STA		_obj_y_delta,X				; X/Y separately which may be used same way
loc_38620:
		LDX		#$0A
		LDY		#$0E
		JSR		_obj_to_beam_ctest
		BCC		loc_3862F
		JSR		_cur_thread_reload_param
		.WORD	_scr_air_hammer_miner_stun
		RTS
loc_3862F:
		LDX		#$0B
		LDY		#$10
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_scr_miner_catch_testA:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3864F
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3864A
		JSR		_cur_thread_reload_param
		.WORD	_scr_miner_catch_anim_L
		RTS
loc_3864A:
		JSR		_cur_thread_reload_param
		.WORD	_scr_miner_catch_anim_R
locret_3864F:
		RTS

; =============== S C R I P T ==========================s====================
_scr1E_pick_axe_miner:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$36
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SARG_SET		SARG1,$80						; axe miners always goes down first

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_pick_axe_miner_active:
		NBG_HNDL_SET	_nbgscr_pick_axe_miner_ctest
_sloc_386EC:
		NJSR			_nsub_spr_dir_select
			NARGB		$34,$40							; select current sprite idx
		POS_MOVE_STOP	0
		SDELAY			$14
		NJSR			_nsub_obj_to_beamer_fast_right_turn	; object cannot move diagonally
		NJSR			_nsub_obj_to_room_sarg1_square_ctest; adjust destination based
		SBCCS			_sloc_3871B						; on surrounding obstacles
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3871B
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3871B
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCSS			_sloc_386EC
_sloc_3871B:
		NJSR			_nsub_spr_dir_select			; now when destination finally decided
			NARGB		$34,$40
		SLOOP_BEGIN		$03
		SPR_IDX_ADD_IMM 6,$04							; start to shake spear
		SPR_IDX_ADD_IMM 6,$FC							; two beer or not two beer
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$08							; set high speed, to destination
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01
		SLOOP_BEGIN		$0A								; start moving while watching new obstacles
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCS_BREAK		_sloc_38739						; if any or end of route, start to retarget
		SDELAY			$08
		SLOOP_END
_sloc_38739:
		SJMPS			_sloc_386EC

; =============== S C R I P T ==========================s====================
_scr_pick_axe_miner_stun:
		NBG_HNDL_SET	_scr_miner_catch_testA
		SARG_SET		SARG0,$02
_sloc_38742:
		SJSRS			_ssub_pick_axe_miner_spr_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_38742
		SLOOP_BEGIN		$14
		SJSRS			_ssub_pick_axe_miner_spr_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_pick_axe_miner_active
		SCASE			_scr_miner_catch_anim_L
		SCASE			_scr_miner_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pick_axe_miner_spr_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$34,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$0C
		SRET

; =============== S U B R O U T I N E ======n================================
_nbgscr_pick_axe_miner_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_38775
		JSR		_cur_thread_reload_param
		.WORD	_scr_pick_axe_miner_stun
		RTS
loc_38775:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
; NOTE: object exactly the same as axe miner but with different sprite ONLY
; but there are two complete set of scripts for both of them...
;
_scr1F_hammer_miner:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$46
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SARG_SET		SARG1,$80

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_hammer_miner_active:
		NBG_HNDL_SET	_nbgsub_hammer_miner_ctest
_sloc_38973:
		NJSR			_nsub_spr_dir_select
			NARGB		$44,$40
		POS_MOVE_STOP	0								; when run into the obstacle
		SDELAY			$14								; run in circles left up right down, etc
		NJSR			_nsub_obj_to_beamer_fast_right_turn
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_389A2
		SARG_ALU		SARG1,_ADC,$40					; retarget until get free direction
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_389A2
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_389A2
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCSS			_sloc_38973
_sloc_389A2:
		NJSR			_nsub_spr_dir_select			; if no collisions
			NARGB		$44,$40							; recalibrate destination
		SLOOP_BEGIN		$03
		SPR_IDX_ADD_IMM 6,$04							; shake with pick-axe
		SPR_IDX_ADD_IMM 6,$FC
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$08							; then slide to destination
		NJSR			_nsub_speed_dir_select			; retarget at the end
			NARGB		$00,$01
		SLOOP_BEGIN		$0A
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCS_BREAK		_sloc_389C0
		SDELAY			$08
		SLOOP_END
_sloc_389C0:
		SJMPS			_sloc_38973

; =============== S C R I P T ==========================s====================
_scr_hammer_miner_stun:
		NBG_HNDL_SET	_scr_miner_catch_testA
		SARG_SET		SARG0,$02
_sloc_389C9:
		SJSRS			_scr_hammer_miner_spr_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_389C9
		SLOOP_BEGIN		$14
		SJSRS			_scr_hammer_miner_spr_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_hammer_miner_active
		SCASE			_scr_miner_catch_anim_L
		SCASE			_scr_miner_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_hammer_miner_spr_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$0C
		SRET

; =============== S U B R O U T I N E ======n================================
_nbgsub_hammer_miner_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_389FC
		JSR		_cur_thread_reload_param
		.WORD	_scr_hammer_miner_stun
		RTS
loc_389FC:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
_scr0E_empty_mine_trolley:
		NBG_HNDL_SET	_nbgsub_empty_miner_trolley_ctest	; only collide with player
_sloc_38C30:
		NJSR			_nsub_empty_miner_trolley_path_select	; also collide with any non-rails
		SBCSS			_sloc_38C46						; obstacles
		NJSR			_nsub_spr_dir_select			; or else move on them
			NARGB		$54,$40
		NJSR			_nsub_speed_dir_select			; very high speed
			NARGB		$00,$02
		SDELAY			$08								; every 8 cycles stop and retarget
		POS_MOVE_STOP	0								; you can't see when it constantly
		SJMPS			_sloc_38C30						; tracking its path
_sloc_38C46:
		NBG_HNDL_RESET									; when nothing to move, reset collisions
		SLOOP_BEGIN		$10								; start to blink
		NJSR			_nsub_spr_dir_select
			NARGB		$54,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP											; then disappear

; =============== S U B R O U T I N E ======n================================
_nbgsub_empty_miner_trolley_ctest:
		LDX		#$0D
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_empty_miner_trolley_path_select:
		LDX		_cur_trd_slot
		LDY		_obj_y_pos_lo,X
		LDA		_obj_y_pos_hi,X
		STA		_tmp_var1
		LDA		_obj_x_pos_hi,X
		STA		_tmp_var0
		LDA		_obj_x_pos_lo,X
		TAX
		JSR		_far_room_macro_block_read	; read the current rail macro from level data
		LDY		#$0B
loc_38C71:
		CMP		_mac_rails_list,Y			; check if this tile is valid rail macro
		BEQ		loc_38C7B
		DEY
		BPL		loc_38C71
loc_38C79:
		SEC									; if not, stop
		RTS
loc_38C7B:
		LDX		_cur_trd_slot				; if yes, get the direction of current
		LDA		_trds_args1,X				; movement
		ASL
		ROL
		ROL
		TAX
		LDA		_mac_rails_allow_lib_lo,X	; and read corresponding patterns list
		STA		_ptr06
		LDA		_mac_rails_allow_lib_hi,X
		STA		_ptr06+1
		LDA		(_ptr06),Y					; find valid destination point based on
		STA		_var0						; current tile and destination.
		BIT		_var0
		BVS		loc_38C79					; if obstacle, stop
		BPL		loc_38CA5					; if no crossroads, continue moving the same dir
		PHA
		LDA		#$00						; or else decide one of two random turns
		JSR		_rand
		LSR
		PLA
		BCS		loc_38CA3
		LSR
		LSR
loc_38CA3:
		AND		#$03
loc_38CA5:
		LSR
		ROR
		ROR
		LDX		_cur_trd_slot
		STA		_trds_args1,X				; update direction parameter
		RTS
_mac_rails_list:
		.BYTE	$01	; vert plain
		.BYTE	$10	; vert gap
		.BYTE	$02	; vert up-right turn
		.BYTE	$12	; vert up-left turn
		.BYTE	$03 ; vert down-right turn
		.BYTE	$13 ; vert down-left turn
		.BYTE	$04 ; up-right turn
		.BYTE	$C4 ; up-left turn
		.BYTE	$05 ; down-right turn
		.BYTE	$15 ; down-left turn
		.BYTE	$06 ; hor plain
		.BYTE	$16 ; hor gap
_mac_rails_allow_lib_lo:
		.BYTE	<[_mac_rails_allow_up]
		.BYTE	<[_mac_rails_allow_left]
		.BYTE	<[_mac_rails_allow_down]
		.BYTE	<[_mac_rails_allow_right]
_mac_rails_allow_lib_hi:
		.BYTE	>[_mac_rails_allow_up]
		.BYTE	>[_mac_rails_allow_left]
		.BYTE	>[_mac_rails_allow_down]
		.BYTE	>[_mac_rails_allow_right]
_mac_rails_allow_up:
		.BYTE	$00,$00,$81,$83,$00,$00,$01,$03,$40,$40,$40,$40
_mac_rails_allow_left:
		.BYTE	$40,$40,$40,$02,$40,$00,$40,$02,$40,$00,$01,$01
_mac_rails_allow_down:
		.BYTE	$02,$02,$02,$02,$89,$8B,$40,$40,$01,$03,$40,$40
_mac_rails_allow_right:
		.BYTE	$40,$40,$02,$40,$00,$40,$02,$40,$00,$40,$03,$03

; =============== S C R I P T ==========================s====================
_scr20_trolley_miner:
		NBG_HNDL_SET	_nbgsub_trolley_miner_ctest
_sloc_38D16:
		NJSR			_nsub_empty_miner_trolley_path_select	; same as for empty trolley
		SBCSS			_sloc_38D2C
		NJSR			_nsub_spr_dir_select
			NARGB		$58,$40
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02
		SDELAY			$08
		POS_MOVE_STOP	0
		SJMPS			_sloc_38D16
_sloc_38D2C:
		NBG_HNDL_RESET									; disappear with miner if obstacle
		SARG_SET		SARG0,$80
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select
			NARGB		$58,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_trolley_miner_disappear:
		NBG_HNDL_RESET									; when let alone, disappears as well
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select
			NARGB		$5C,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_trolley_miner_stun:
		NJSR			_nsub_new_thread_start			; when beamed, separates with trolley
			NARGB		_scr0E_empty_mine_trolley_idx	; run trolley alone
			NARGB		$00,$00
			NARGB		$00
			NARGB		$00
		NBG_HNDL_SET	_nbgsub_trolley_miner_catch_test
		SARG_SET		SARG0,$02
_sloc_38D59:
		SJSRS			_scr_trolley_miner_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_38D59
		SLOOP_BEGIN		$14
		SJSRS			_scr_trolley_miner_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_trolley_miner_disappear
		SCASE			_scr_miner_catch_anim_L
		SCASE			_scr_miner_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_trolley_miner_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$5C,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S U B R O U T I N E ======n================================
_nbgsub_trolley_miner_ctest:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_38D8C
		JSR		_cur_thread_reload_param
		.WORD	_scr_trolley_miner_stun
		RTS
loc_38D8C:
		LDX		#$0D
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_trolley_miner_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_38DAC
		LSR
		LDA		#$07						; very valuable enemy, but you may miss it!
		STA		_scores_obj_value
		BCS		loc_38DA7
		JSR		_cur_thread_reload_param
		.WORD	_scr_miner_catch_anim_L
		RTS
loc_38DA7:
		JSR		_cur_thread_reload_param
		.WORD	_scr_miner_catch_anim_R
locret_38DAC:
		RTS

; =============== S C R I P T ==========================s====================
; set of similar objects different only in sprite appearance
;
_scr21_train_ghost:
		NJSR			_nsub_obj_sarg_add_imm_test		; all main objects has idx 0-5
			NARGB		SARG0,$FA						; here is the test for 6th object
		SJMP_SW			$01								; which is projectile
		SCASE			_scr_train_ghost_proj

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_train_ghost_spr_idx_select; select sprite idx based on SARG2 value
		SARG_SET		SARG0,$00
		NJSR			_nsub_sarg1_rand08_mul8_set		; now choose random move direction
		SLOOP_BEGIN		$10
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; but blink first
			NARGB		SARG2
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_train_ghost_active:
		NBG_HNDL_SET	_nbgsub_train_ghost_ctest
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; set sprite from SARG2
			NARGB		SARG2
_sloc_38EFD:
		SLOOP_BEGIN		$0A
		SJSRS			_ssub_train_ghost_move_anim		; move one direction,
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SJSRS			_ssub_train_ghost_shoot			; then shoot,
		SLOOP_BEGIN		$0A
		SJSRS			_ssub_train_ghost_move_anim		; then move opposite direction
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SJSRS			_ssub_train_ghost_shoot			; shot again, repeat
		SJMPS			_sloc_38EFD

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_ghost_shoot:
		POS_MOVE_STOP	0
		SPR_IDX_ADD_IMM 0,$02							; stop, spit face, shoot
		NJSR			_nsub_new_thread_start
			NARGB		_scr21_train_ghost_idx
			NARGB		$00,$00
			NARGB		_scr_train_ghost_proj_idx+6
			NARGB		$00
		SDELAY			$14
		SPR_IDX_ADD_IMM 0,$FE							; restore face
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_ghost_move_anim:
		NJSR			_nsub_speed_dir_select
			NARGB		$80,$00							; slow speed
		SLOOP_BEGIN		$14
		SDELAY			$01
		NJSR			_nsub_obj_to_room_x_ctestA		; obstacle collision tests here
		SBCCS			_sloc_38F41
		NJSR			_nsub_cur_obj_sarg1_hor_complement	; same as for slow slime
		NJSR			_nsub_speed_dir_select
			NARGB		$80,$00
_sloc_38F41:
		NJSR			_nsub_obj_to_room_y_ctestA
		SBCCS			_sloc_38F4F
		NJSR			_nsub_cur_obj_sarg1_vert_complement
		NJSR			_nsub_speed_dir_select
			NARGB		$80,$00
_sloc_38F4F:
		SLOOP_END
		SRET

; =============== S C R I P T ==========================s====================
_scr_train_ghost_stun:
		NBG_HNDL_SET	_nbgsub_train_ghost_catch_test
		SARG_SET		SARG0,$02
_sloc_38F57:
		SJSRS			_scr_train_ghost_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_38F57
		SLOOP_BEGIN		$14
		SJSRS			_scr_train_ghost_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_train_ghost_active
		SCASE			_scr_train_ghost_catch_anim_L
		SCASE			_scr_train_ghost_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_train_ghost_shake_anim:
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG2
		SDELAY			$01
		SPR_IDX_INC		1
		SRET

; =============== S C R I P T ==========================s====================
_scr_train_ghost_catch_anim_L:
		SARG_SET		SARG1,$76
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_train_ghost_catch_anim_R:
		SARG_SET		SARG1,$78
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_ghost_ctest:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_38F94
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_ghost_stun
		RTS
loc_38F94:
		LDX		#$07
		LDY		#$08
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_ghost_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_38FB4
		LSR
		LDA		#$01						; very cheap enemy but there are a lot of them
		STA		_scores_obj_value
		BCS		loc_38FAF
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_ghost_catch_anim_L
		RTS
loc_38FAF:
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_ghost_catch_anim_R
locret_38FB4:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_train_ghost_spr_idx_select:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		ASL
		ADC		_trds_args0,X
		ADC		#$64
		STA		_trds_args2,X
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_ghost_proj:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_train_ghost_proj_ctest
		NJSR			_nsub_train_ghost_proj_target_set
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; target is random
		SLOOP_BEGIN		$08								; first its move
		SPR_IDX_SET		4,$7A
		SPR_IDX_INC		4
		SLOOP_END
		POS_MOVE_STOP	0								; at the end it stops
		SLOOP_BEGIN		$04								; but keeps pulsating for a while
		SPR_IDX_SET		2,$7A
		SPR_IDX_INC		2
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_ghost_proj_ctest:
		LDX		#$06
		LDY		#$07
		JSR		_obj_to_player_ctest
		JSR		_obj_to_room_macro_ctest_raw
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E ======n================================
_nsub_train_ghost_proj_target_set:
		LDA		#$21
		JSR		_rand
		CLC
		ADC		#$70						; spit always goes down
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr2B_still_throw_ballistic_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_scr_slime_ballistic_proj

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SLOOP_BEGIN		$10								; here is the main slime script init
		SPR_IDX_SET		1,$05							; blink for a while
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_still_throw_ballistic_slime_active:
		NJSR			_nsub_apu_snd_load				; also laughs
			NARGB		_snd08_idx
		NBG_HNDL_SET	_nbgsub_still_throw_ballistic_slime_ctest
_sloc_39114:
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; target on beamer as well
		NJSR			_nsub_spr_dir_select			; calc sprite idx for slime
			NARGB		$04,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04							; throw animation
		NJSR			_nsub_new_thread_start			; deploy projectile
			NARGB		_scr2B_still_throw_ballistic_slime_idx
			NARGB		$00,$00
			NARGB		_scr_slime_ballistic_proj_idx+1
			NARGB		$00
		SLOOP_BEGIN		$05								; after throw anim
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$04
		SLOOP_END
		SJMPS			_sloc_39114

; =============== S C R I P T ==========================s====================
_scr_still_throw_ballistic_slime_stun:
		NBG_HNDL_SET	_nbgsub_still_throw_ballistic_slime_catch_test
		SJSR			_ssub_slime_stun_in_process		; regular enemy stun handler
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_still_throw_ballistic_slime_active
		SCASE			_scr_slime_catch_anim_L
		SCASE			_scr_slime_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_still_throw_ballistic_slime_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_39152
		JSR		_cur_thread_reload_param
		.WORD	_scr_still_throw_ballistic_slime_stun
		RTS
loc_39152:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_still_throw_ballistic_slime_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_39172
		LSR
		LDA		#$05						; more differently vlued slimes
		STA		_scores_obj_value
		BCS		loc_3916D
		JSR		_cur_thread_reload_param
		.WORD	_scr_slime_catch_anim_L
		RTS
loc_3916D:
		JSR		_cur_thread_reload_param
		.WORD	_scr_slime_catch_anim_R
locret_39172:
		RTS

; =============== S C R I P T ==========================s====================
_scr_slime_ballistic_proj:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_slime_ballistic_proj_ctest
		NJSR			_nsub_slime_ballistic_proj_spr_idx_select
		SSCRIPT1_SET	_nsub_slime_ballistic_proj_spr_anim
		NJSR			_nsub_speed_dir_select
			NARGB		$40,$02							; sarg1 inherited from main object!
		POS_Y_DELTA_ADD 0,$00,$FD						; ballistic trajectory delta Y init
		SLOOP_BEGIN		$48								; then slowly increment, first go up
		POS_Y_DELTA_ADD 1,$18,$00						; then start go down...
		SLOOP_END
		POS_MOVE_STOP	0
		SSCRIPT1_OFF
		SDELAY			$04
		SSTOP

; =============== S C R I P T ==========================s====================
_nsub_slime_ballistic_proj_spr_anim:
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_ADD_IMM 4,$FD
		SJMPS			_nsub_slime_ballistic_proj_spr_anim

; =============== S U B R O U T I N E ======n================================
_nbgsub_slime_ballistic_proj_ctest:
		LDX		#$06
		LDY		#$07
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E ======n================================
_nsub_slime_ballistic_proj_spr_idx_select:
		LDA		#$07
		JSR		_rand
		ASL
		ASL
		ADC		#$7C
		LDX		_cur_trd_slot
		STA		_obj_spr_idx,X
		RTS

; =============== S C R I P T ==========================s====================
_scr2C_fast_throw_forward_slime:
		NJSR			_nsub_obj_sarg_add_imm_test		; usual 2-branch script
			NARGB		SARG0,$FF						; one is a main object, second is
		SJMP_SW			$01								; its projectile
		SCASE			_scr_fast_throw_forward_slime_proj

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_cur_obj_to_beamer_dir_set
		SLOOP_BEGIN		$10								; target to beamer as usual
		NJSR			_nsub_spr_dir_select			; calculate appearance sprite
			NARGB		$04,$40							; blink, but this time while
		SDELAY			$01								; tracking beamer position!
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_fast_throw_forward_slime_active:
		NBG_HNDL_SET	_nbgsub_fast_throw_forward_slime_ctest
_sloc_3927A:
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00							; actually, this routine is more like SPEED calc
		SSCRIPT1_SET	_scr_slime_spr_anim				; regular slime anim routine reused
		SLOOP_BEGIN		$06								; two loops here
		SLOOP_BEGIN		$0A
		SDELAY			$01
		NJSR			_nsub_obj_to_room_x_ctestA		; first object moves as usual fast slime
		SBCCS			_sloc_3929B
		NJSR			_nsub_cur_obj_sarg1_hor_complement
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_slime_spr_anim
_sloc_3929B:
		NJSR			_nsub_obj_to_room_y_ctestA
		SBCCS			_sloc_392AD
		NJSR			_nsub_cur_obj_sarg1_vert_complement
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_slime_spr_anim
_sloc_392AD:
		SLOOP_END
		NJSR			_nsub_obj_to_beamer_slow_turn	; this code mostly the same as for fast slime
			NARGB		$08								; but with extra shoot cycles inside
		SLOOP_END										; when move and readjust vectors, shoot
		NJSR			_nsub_new_thread_start
			NARGB		_scr2C_fast_throw_forward_slime_idx	; deploy object
			NARGB		$00,$00
			NARGB		_scr_fast_throw_forward_slime_proj_idx+1
			NARGB		$00
		SJMPS			_sloc_3927A

; =============== S C R I P T ==========================s====================
_scr_fast_throw_forward_slime_stun:
		NBG_HNDL_SET	_nbgsub_slime_catch_testB
		SJSR			_ssub_slime_stun_in_process		; very regular common handler
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_fast_throw_forward_slime_active
		SCASE			_scr_slime_catch_anim_L
		SCASE			_scr_slime_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_fast_throw_forward_slime_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_392DE
		JSR		_cur_thread_reload_param
		.WORD	_scr_fast_throw_forward_slime_stun
		RTS
loc_392DE:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
_scr_fast_throw_forward_slime_proj:
		SARG_SET		SARG0,$00						; uses the same init routines as ballistic projectile
		NBG_HNDL_SET	_nbgsub_fast_throw_forward_slime_proj_ctest
		NJSR			_nsub_slime_ballistic_proj_spr_idx_select
		NJSR			_nsub_speed_dir_select
			NARGB		$80,$01
_sloc_3930D:
		SPR_IDX_INC		4								; but moving in linear direction...
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_ADD_IMM 4,$FD
		SJMPS			_sloc_3930D

; =============== S U B R O U T I N E ======n================================
_nbgsub_fast_throw_forward_slime_proj_ctest:
		LDX		#$06
		LDY		#$07
		JSR		_obj_to_player_ctest
		JSR		_cur_obj_out_of_screen_test
		JMP		_obj_to_room_macro_ctest_raw

; =============== S C R I P T ==========================s====================
_scr23_halloween:
		NJSR			_nsub_cur_obj_to_beamer_dir_set
		SLOOP_BEGIN		$10								; beamer targeting start
		SPR_IDX_SET		1,$C2							; this is first objec t here using
		SPR_IDX_SET		1,$FF							; extended sprires mode
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_halloween_active:
		NBG_HNDL_SET	_nbgsub_halloween_ctest
_sloc_3945F:
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_halloween_spr_anim
		SLOOP_BEGIN		$14
		SDELAY			$01								; regular collision tests
		NJSR			_nsub_obj_to_room_x_ctestA
		SBCCS			_sloc_3947E						; with restarting the animanions
		NJSR			_nsub_cur_obj_sarg1_hor_complement;	if obstacle occured
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_halloween_spr_anim
_sloc_3947E:
		NJSR			_nsub_obj_to_room_y_ctestA
		SBCCS			_sloc_39490
		NJSR			_nsub_cur_obj_sarg1_vert_complement
		NJSR			_nsub_speed_dir_select
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_halloween_spr_anim
_sloc_39490:
		SLOOP_END
		NJSR			_nsub_obj_to_beamer_slow_turn	; retarget to beamer at the end
			NARGB		$10									; ...period
		SJMPS			_sloc_3945F

; =============== S C R I P T ==========================s====================
_scr_halloween_spr_anim:
		NJSR			_nsub_spr_dir_select			; recalc sprite idx
			NARGB		$C0,$40							; at restart of this script
_sloc_3949D:
		SPR_IDX_ADD_IMM 0,$04							; animate
		SDELAY			$0A
		SPR_IDX_ADD_IMM 0,$FC
		SDELAY			$0A
		SJMPS			_sloc_3949D

; =============== S C R I P T ==========================s====================
_scr_halloween_stun:
		NBG_HNDL_SET	_nbgsub_halloween_catch_test	; usual handler for most objects again
		SARG_SET		SARG0,$02
_sloc_394AE:
		SJSRS			_ssub_halloween_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_394AE
		SLOOP_BEGIN		$14
		SJSRS			_ssub_halloween_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_halloween_active
		SCASE			_scr_halloween_catch_anim_L
		SCASE			_scr_halloween_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_halloween_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$C0,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_halloween_catch_anim_L:
		SARG_SET		SARG1,$04
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_halloween_catch_anim_R:
		SARG_SET		SARG1,$06
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_halloween_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_394ED
		JSR		_cur_thread_reload_param
		.WORD	_scr_halloween_stun
		RTS
loc_394ED:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_halloween_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3950D
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_39508
		JSR		_cur_thread_reload_param
		.WORD	_scr_halloween_catch_anim_L
		RTS
loc_39508:
		JSR		_cur_thread_reload_param
		.WORD	_scr_halloween_catch_anim_R
locret_3950D:
		RTS

; =============== S C R I P T ==========================s====================
_scr24_flying_elephant:
		SLOOP_BEGIN		$10								; another object with extended
		NJSR			_nsub_spr_dir_select			; sprites mode
			NARGB		$CC,$40							; starting directcion of each object
		SDELAY			$01								; here is set in objects data extra agrs
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_flying_elephant_active:
		NBG_HNDL_SET	_nbgsub_flying_elephant_ctest
_sloc_396F1:
		NJSR			_nsub_sarg1_direction_extract	; get the direction index
		SJSR_SW	$04
		SCASE			_ssub_flying_elephant_move_U	; do movement in given direction
		SCASE			_ssub_flying_elephant_move_R
		SCASE			_ssub_flying_elephant_move_D
		SCASE			_ssub_flying_elephant_move_L
		POS_MOVE_STOP	0
		SARG_ALU		SARG1,_ADC,$40					; turn clockwise, repeat
		SJMPS			_sloc_396F1

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_flying_elephant_move_U:
		POS_Y_DELTA_SET 0,$80,$FE
_sloc_39709:
		SPR_IDX_SET		0,$CC							; this object flying on the
		SJSRS			_ssub_flying_elephant_spr_anim	; limited area, hardcoded in script
		NJSR			_nsub_cur_pos_y_lo_icmp
			NARGB		$50
		SBCCS			_sloc_39709
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_flying_elephant_move_R:
		POS_X_DELTA_SET 0,$80,$01
_sloc_39719:
		SPR_IDX_SET		0,$CD
		SJSRS			_ssub_flying_elephant_spr_anim
		NJSR			_nsub_cur_pos_x_lo_icmp
			NARGB		$B0
		SBCSS			_sloc_39719
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_flying_elephant_move_D:
		POS_Y_DELTA_SET 0,$80,$01
_sloc_39729:
		SPR_IDX_SET		0,$CE
		SJSRS			_ssub_flying_elephant_spr_anim
		NJSR			_nsub_cur_pos_y_lo_icmp
			NARGB		$A0
		SBCSS			_sloc_39729
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_flying_elephant_move_L:
		POS_X_DELTA_SET 0,$80,$FE
_sloc_39739:
		SPR_IDX_SET		0,$CF
		SJSRS			_ssub_flying_elephant_spr_anim
		NJSR			_nsub_cur_pos_x_lo_icmp
			NARGB		$50
		SBCCS			_sloc_39739
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_flying_elephant_spr_anim:
		SDELAY			$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$FC
		SRET

; =============== S C R I P T ==========================s====================
_scr_flying_elephant_stun:
		NBG_HNDL_SET	_nbgsub_flying_elephant_catch_test
		SARG_SET		SARG0,$02
_sloc_39755:
		SJSRS			_sub_flying_elephant_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_39755
		SLOOP_BEGIN		$14
		SJSRS			_sub_flying_elephant_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_flying_elephant_active
		SCASE			_scr_flying_elephant_catch_anim_L
		SCASE			_scr_flying_elephant_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_sub_flying_elephant_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$CC,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$18
		SRET

; =============== S C R I P T ==========================s====================
_scr_flying_elephant_catch_anim_L:
		SARG_SET		SARG1,$08
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_flying_elephant_catch_anim_R:
		SARG_SET		SARG1,$0A
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_flying_elephant_ctest:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_39794
		JSR		_cur_thread_reload_param
		.WORD	_scr_flying_elephant_stun
		RTS
loc_39794:
		LDX		#$0D
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_flying_elephant_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_397B4
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_397AF
		JSR		_cur_thread_reload_param
		.WORD	_scr_flying_elephant_catch_anim_L
		RTS
loc_397AF:
		JSR		_cur_thread_reload_param
		.WORD	_scr_flying_elephant_catch_anim_R
locret_397B4:
		RTS

; =============== S C R I P T ==========================s====================
_scr25_stinging_elephant:
		NJSR			_nsub_obj_sarg_add_imm_test		; this elephant is not moving
			NARGB		SARG0,$FF						; also direction set in objects data
		SJMP_SW			$01
		SCASE			_scr_stinging_elephant_sting	; also have an additional "projectile"

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SLOOP_BEGIN		$10								; start blinking here as usual
		NJSR			_nsub_spr_dir_select
			NARGB		$D8,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_active:
		NBG_HNDL_SET	_nbgsub_stinging_elephant_ctest
_sloc_399E9:
		SLOOP_BEGIN		$06								; no special targeting
		NJSR			_nsub_spr_dir_select
			NARGB		$D8,$40
		SDELAY			$04
		SPR_IDX_ADD_IMM 4,$04							; idle anim
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$FC
		SLOOP_END
		NJSR			_nsub_new_thread_start			; deploy sting
			NARGB		_scr25_stinging_elephant_idx
			NARGB		$00,$00
			NARGB		_scr_stinging_elephant_sting_idx+1
			NARGB		$00
		SJMPS			_sloc_399E9						; repeat

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_stun:
		NBG_HNDL_SET	_nbgsub_stinging_elephant_catch_test
		SARG_SET		SARG0,$02
_sloc_39A0A:
		SJSRS			_ssub_stinging_elephant_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_39A0A
		SLOOP_BEGIN		$14
		SJSRS			_ssub_stinging_elephant_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_stinging_elephant_active
		SCASE			_scr_flying_elephant_catch_anim_L
		SCASE			_scr_flying_elephant_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_stinging_elephant_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$D8,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$0C
		SRET

; =============== S U B R O U T I N E ======n================================
_nbgsub_stinging_elephant_ctest:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_39A3D
		JSR		_cur_thread_reload_param
		.WORD	_scr_stinging_elephant_stun
		RTS
loc_39A3D:
		LDX		#$0D
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_stinging_elephant_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_39A5D
		LSR
		LDA		#$05						; same as other elephant with more scores
		STA		_scores_obj_value
		BCS		loc_39A58
		JSR		_cur_thread_reload_param
		.WORD	_scr_flying_elephant_catch_anim_L
		RTS
loc_39A58:
		JSR		_cur_thread_reload_param
		.WORD	_scr_flying_elephant_catch_anim_R
locret_39A5D:
		RTS

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_sting:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_stinging_elephant_sting_ctest
		NJSR			_nsub_sarg1_direction_extract
		SJMP_SW			$04
		SCASE			_scr_stinging_elephant_U
		SCASE			_scr_stinging_elephant_R
		SCASE			_scr_stinging_elephant_D
		SCASE			_scr_stinging_elephant_L

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_U:
		POS_X_MOVE		0,$02							; set the relative position to object
		POS_Y_MOVE		0,$EC
		SPR_IDX_SET		2,$0C							; init sprite (inside of the object)
		SLOOP_BEGIN		$04								; move sprite out of the object
		POS_Y_MOVE		0,$F8
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14								; move it back
		SLOOP_BEGIN		$04
		POS_Y_MOVE		0,$08
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP											; kill projectile

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_R:
		POS_X_MOVE		0,$08							; all the same with other directions
		POS_Y_MOVE		0,$FE
		SPR_IDX_SET		2,$11
		SLOOP_BEGIN		$03
		POS_X_MOVE		0,$08
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14
		SLOOP_BEGIN		$03								; NOTE, horizontal stings are shorter
		POS_X_MOVE		0,$F8
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_D:
		POS_X_MOVE		0,$FB							; due to forementioned lack of
		POS_Y_MOVE		0,$0B							; down directed object, this branch
		SPR_IDX_SET		2,$15							; never used as well
		SLOOP_BEGIN		$04
		POS_Y_MOVE		0,$08
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14
		SLOOP_BEGIN		$04
		POS_Y_MOVE		0,$F8
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_stinging_elephant_L:
		POS_X_MOVE		0,$F2
		POS_Y_MOVE		0,$FE
		SPR_IDX_SET		2,$1A
		SLOOP_BEGIN		$03
		POS_X_MOVE		0,$F8
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14
		SLOOP_BEGIN		$03
		POS_X_MOVE		0,$08
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_stinging_elephant_sting_ctest:
		LDX		#$06
		LDY		#$07
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
; there is a second object after slime in LVL1 with different appearance method
;
_scr26_sword_ninja:
		SDELAY			$01								; first set the appearance point
		NJSR			_nsub_ninja_appear_pos_set		; randomly, but not in any obstacles
		SBCSS			_scr26_sword_ninja				; loop while any valid positions calculated
		SARG_SET		SARG1,$80						; appears always left-sided
		SJSRS			_ssub_sword_ninja_spr_blink
		NBG_HNDL_SET	_nbgsub_swird_ninja_ctest
		NJSR			_nsub_obj_to_beamer_fast_right_turn	; target to beamer with diagonal forbid
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_39D06
		SARG_ALU		SARG1,_ADC,$40					; test if there is an obstacle in selected direction
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_39D06						; continue until...
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_39D06
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCSS			_sloc_39D1A						; no valid paths... then just shut down the object
_sloc_39D06:
		NJSR			_nsub_speed_dir_select			; if direction is valid, set speed
			NARGB		$00,$02
		SSCRIPT1_SET	_scr_sword_ninja_spr_anim		; set animation script
		SLOOP_BEGIN		$0A
		SDELAY			$04								; then move with loccisions test as well
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCS_BREAK		_sloc_39D1A
		SLOOP_END
_sloc_39D1A:
		SSCRIPT1_OFF
		POS_MOVE_STOP	0								; stop object

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_sword_ninja_hide:
		NBG_HNDL_RESET
		SJSRS			_ssub_sword_ninja_spr_blink		; then hide it and set delay for 1 second
		SDELAY			$3C
		SJMPS			_scr26_sword_ninja

; =============== S C R I P T ==========================s====================
_scr_sword_ninja_spr_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$1E,$40
_sloc_39D2B:
		SPR_IDX_ADD_IMM 7,$04
		SPR_IDX_ADD_IMM 7,$04
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		SJMPS			_sloc_39D2B

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_sword_ninja_spr_blink:
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select
			NARGB		$1E,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SRET

; =============== S C R I P T ==========================s====================
_scr_sword_ninja_stun:
		NBG_HNDL_SET	_nbgsub_sword_ninja_catch_test
		SARG_SET		SARG0,$02
_sloc_39D49:
		SJSRS			_scr_sword_ninja_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_39D49
		SLOOP_BEGIN		$14
		SJSRS			_scr_sword_ninja_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_sword_ninja_hide
		SCASE			_scr_ninja_catch_anim_L
		SCASE			_scr_ninja_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_sword_ninja_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$2A,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S C R I P T ==========================s====================
_scr_ninja_catch_anim_L:
		SARG_SET		SARG1,$32
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_ninja_catch_anim_R:
		SARG_SET		SARG1,$34
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_swird_ninja_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_39D88
		JSR		_cur_thread_reload_param
		.WORD	_scr_sword_ninja_stun
		RTS
loc_39D88:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
; NOTE, first time they used one handler for two objects.
;
_nbgsub_sword_ninja_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_39DA8
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_39DA3
		JSR		_cur_thread_reload_param
		.WORD	_scr_ninja_catch_anim_L
		RTS
loc_39DA3:
		JSR		_cur_thread_reload_param
		.WORD	_scr_ninja_catch_anim_R
locret_39DA8:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_ninja_appear_pos_set:
		LDA		#$06						; select two random points in area
		JSR		_rand						; 80-160, 80-176
		ASL
		ASL
		ASL
		ASL
		ADC		#$50
		PHA
		LDA		#$07
		JSR		_rand
		ASL
		ASL
		ASL
		ASL
		ADC		#$50
		TAX
		PLA
		TAY
		JSR		_obj_new_lvl_pos_set		; calculate object room pos
		LDA		#<[_ninja_bounds_data]		; test if object not stuck in obstacles
		LDY		#>[_ninja_bounds_data]		; at the beginning
		JMP		_obj_to_room_bound_box_ctest

_ninja_bounds_data:
		.BYTE	$04
		.BYTE	$00,$00
		.BYTE	$00,$08
		.BYTE	$08,$00
		.BYTE	$08,$08

; =============== S C R I P T ==========================s====================
_scr27_shuriken_ninja:
		NJSR			_nsub_obj_sarg_add_imm_test		; same as sword ninja
			NARGB		SARG0,$FF						; but with projectile object
		SJMP_SW			$01
		SCASE			_scr_shuriken_ninja_proj

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
_scr_shuriken_ninja_active:
		SDELAY			$01								; reused shuriken ninja script here
		NJSR			_nsub_ninja_appear_pos_set
		SBCSS			_scr_shuriken_ninja_active
		NJSR			_nsub_obj_to_beamer_fast_right_turn	; beamer targeted without diagonals
		SJSRS			_ssub_shuriken_ninja_spr_blink
		NBG_HNDL_SET	_nbgsub_shuriken_ninja_ctest
		NJSR			_nsub_spr_dir_select
			NARGB		$36,$40
		SDELAY			$10								; pause before shoot
		SARG_ALU		SARG1,_ADC,$F0
		SLOOP_BEGIN		$03
		NJSR			_nsub_new_thread_start			; deploy 3 objects
			NARGB		_scr27_shuriken_ninja_idx		; while animate ninja itself
			NARGB		$00,$00
			NARGB		_scr_shuriken_ninja_proj_idx+1
			NARGB		$00
		SPR_IDX_ADD_IMM 5,$04
		SPR_IDX_ADD_IMM 5,$04
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 5,$FC
		SARG_ALU		SARG1,_ADC,$10					; change direction of shot, first -16
		SLOOP_END										; then 0 ,then +16 from cur y delta
		SARG_ALU		SARG1,_ADC,$F0					; set delta 0 again
		SDELAY			$10								; wait before disappear

; =============== S C R I P T ==========================s====================
_sloc_shuriken_ninja_hide:
		NBG_HNDL_RESET
		SJSRS			_ssub_shuriken_ninja_spr_blink
		SDELAY			$3C
		SJMPS			_scr_shuriken_ninja_active

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_shuriken_ninja_spr_blink:
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select
			NARGB		$36,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SRET

; =============== S C R I P T ==========================s====================
_scr_shuriken_ninja_stun:
		NBG_HNDL_SET	_nbgsub_sword_ninja_catch_test	; reused from swork ninja as well
		SARG_SET		SARG0,$02
_sloc_39FF4:
		SJSR			_scr_sword_ninja_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_39FF4
		SLOOP_BEGIN		$14
		SJSR			_scr_sword_ninja_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_sloc_shuriken_ninja_hide
		SCASE			_scr_ninja_catch_anim_L
		SCASE			_scr_ninja_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_shuriken_ninja_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3A01D
		JSR		_cur_thread_reload_param
		.WORD	_scr_shuriken_ninja_stun
		RTS
loc_3A01D:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
_scr_shuriken_ninja_proj:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_shuriken_ninja_proj_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02							; calc direction from arg1
		SLOOP_BEGIN		$04								; derived from main object
		SPR_IDX_SET		2,$42							; simple short living projectile
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_shuriken_ninja_proj_ctest:
		LDX		#$06
		LDY		#$07
		JSR		_obj_to_player_ctest
		JSR		_cur_obj_out_of_screen_test
		JMP		_obj_to_room_macro_ctest_raw

; =============== S C R I P T ==========================s====================
_scr28_pink_goo:
		SLOOP_BEGIN		$10								; pink goo also uses
		SPR_IDX_SET		1,$E8							; alt sprite mode
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_pink_goo_active:
		NBG_HNDL_SET	_nbgsub_pink_goo_active_ctestA
_sloc_3A15F:
		SLOOP_BEGIN		$02								; jelly bouncing before jump
		SPR_IDX_SET		0,$E8
		SDELAY			$10
		SPR_IDX_INC		4
		SPR_IDX_DEC		5
		SPR_IDX_ADD_IMM 4,$02
		SLOOP_END
		SPR_IDX_SET		5,$E8							; prepare to jump
		SPR_IDX_INC		4
		SPR_IDX_DEC		5
		SPR_IDX_ADD_IMM 4,$02
		NJSR			_nsub_obj_to_beamer_fast_right_turn	; target to beamer
		NJSR			_nsub_pink_goo_bounds_test		; test for valid location to jump
		SBCCS			_sloc_3A197
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_pink_goo_bounds_test
		SBCCS			_sloc_3A197
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_pink_goo_bounds_test
		SBCCS			_sloc_3A197
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_pink_goo_bounds_test
		SBCSS			_sloc_3A15F						; if no such direction, repeat bouncing forever
_sloc_3A197:
		NBG_HNDL_SET	_nbgsub_pink_goo_active_ctestB	; while jumping, can't be catched
		SPR_IDX_SET		0,$EB
		NJSR			_nsub_sarg1_direction_extract	; select jumping anim sub-routine
		SJSR_SW	$04
		SCASE			_ssub_pink_goo_jump_U
		SCASE			_ssub_pink_goo_jump_R
		SCASE			_ssub_pink_goo_jump_D
		SCASE			_ssub_pink_goo_jump_L
		POS_MOVE_STOP	0								; return to still state
		SJMPS			_scr_pink_goo_active

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pink_goo_jump_U:
		POS_Y_DELTA_ADD 0,$80,$FE
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_Y_DELTA_ADD 2,$40,$00
		POS_Y_DELTA_ADD 6,$00,$04
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pink_goo_jump_R:
		POS_X_DELTA_ADD 0,$80,$01
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_X_DELTA_ADD 2,$C0,$FF
		POS_Y_DELTA_ADD 6,$00,$04
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pink_goo_jump_D:
		POS_Y_DELTA_ADD 0,$80,$01
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_Y_DELTA_ADD 2,$C0,$FF
		POS_Y_DELTA_ADD 6,$00,$04
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pink_goo_jump_L:
		POS_X_DELTA_ADD 0,$80,$FE
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_X_DELTA_ADD 2,$40,$00
		POS_Y_DELTA_ADD 6,$00,$04
		SRET

; =============== S C R I P T ==========================s====================
_scr_pink_goo_stun:
		NBG_HNDL_SET	_nbgsub_pink_goo_catch_test
		SARG_SET		SARG0,$02
_sloc_3A1EA:
		SPR_IDX_SET		1,$E8							; shake anim inline
		SPR_IDX_SET		1,$46
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3A1EA
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$E8
		SPR_IDX_SET		1,$46
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_pink_goo_active
		SCASE			_sloc_pink_goo_catch_anim_L
		SCASE			_sloc_pink_goo_catch_anim_R

; =============== S C R I P T ==========================s====================
_sloc_pink_goo_catch_anim_L:
		SARG_SET		SARG1,$47
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_sloc_pink_goo_catch_anim_R:
		SARG_SET		SARG1,$49
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_pink_goo_active_ctestA:
		LDX		#$0A
		LDY		#$0A
		JSR		_obj_to_beam_ctest
		BCC		_nbgsub_pink_goo_active_ctestB
		JSR		_cur_thread_reload_param
		.WORD	_scr_pink_goo_stun
		RTS

; =============== S U B R O U T I N E ======n================================
_nbgsub_pink_goo_active_ctestB:
		LDX		#$09
		LDY		#$0A
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_pink_goo_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3A241
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_3A23C
		JSR		_cur_thread_reload_param
		.WORD	_sloc_pink_goo_catch_anim_L
		RTS
loc_3A23C:
		JSR		_cur_thread_reload_param
		.WORD	_sloc_pink_goo_catch_anim_R
locret_3A241:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_pink_goo_bounds_test:
		JSR		_nsub_sarg1_direction_extract
		TAX
		LDA		off_3A24F,X
		LDY		off_3A253,X
		JMP		_obj_to_room_bound_box_ctest

off_3A24F:
		.BYTE	<[byte_3A257]
		.BYTE	<[byte_3A260]
		.BYTE	<[byte_3A269]
		.BYTE	<[byte_3A272]
off_3A253:
		.BYTE	>[byte_3A257]
		.BYTE	>[byte_3A260]
		.BYTE	>[byte_3A269]
		.BYTE	>[byte_3A272]
byte_3A257:
		.BYTE	$04
		.BYTE	$F0,$F8
		.BYTE	$F0,$00
		.BYTE	$F8,$F8
		.BYTE	$F8,$00
byte_3A260:
		.BYTE	$04
		.BYTE	$08,$F8
		.BYTE	$10,$F8
		.BYTE	$08,$00
		.BYTE	$10,$00
byte_3A269:
		.BYTE	$04
		.BYTE	$F8,$08
		.BYTE	$00,$08
		.BYTE	$F8,$10
		.BYTE	$00,$10
byte_3A272:
		.BYTE	$04
		.BYTE	$E8,$F8
		.BYTE	$F0,$F8
		.BYTE	$E8,$00
		.BYTE	$F0,$00

; =============== S C R I P T ==========================s====================
_scr29_sewer_worm:
		NJSR			_nsub_obj_sarg_add_imm_test		; also has a projectile
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_scr_sewer_worm_proj

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$4B
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sloc_sewer_worm_state_loop:
		NBG_HNDL_SET	_nbgsub_sewer_worm_ctestA
; NOTE: for some reason, there is the only place this routine ever used
; for anything other than player's object. this vars are used to keep players
; object in the middle of the screen and adjust screen scrolls according
; to movement direction. this never used for any other objects at all
; seems here we have some kind of early leftover...
		NJSR			_nsub_cur_center_reset

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sloc_sewer_worm_active:
		SDELAY			$01
		NJSR			_nsub_sewer_worm_move_anim		; select direction and test
		SBCSS			_sloc_sewer_worm_active			; untile it could swim there
		NJSR			_nsub_speed_dir_select			; set speed in given direction
			NARGB		$40,$00
		SPR_IDX_SET		0,$4B							; move slowly
		SDELAY			$22
		SPR_IDX_INC		5
		SPR_IDX_INC		5
		SPR_IDX_ADD_IMM 5,$FE
		SPR_IDX_INC		5
		SPR_IDX_DEC		5
		SPR_IDX_ADD_IMM 5,$02
		POS_MOVE_STOP	0								; stop
		NJSR			_nsub_get_rand_probability		; test 1/4 probability for shot
			NARGB		$04
		SBCCS			_sloc_sewer_worm_active			; if not, then repeat swim phase
		SPR_IDX_SET		0,$4B							; if yes, show up the head
		SDELAY			$28
		SPR_IDX_SET		6,$53							; then full extent
		NBG_HNDL_SET	_nbgsub_sewer_worm_ctestB		; bounding box settings are changed then
		POS_Y_MOVE		0,$F8							; animate shoot
		SLOOP_BEGIN		$04
		NJSR			_nsub_new_thread_start			; shot 4 projectiles
			NARGB		_scr29_sewer_worm_idx
			NARGB		$00,$F8
			NARGB		_scr_sewer_worm_proj_idx+1
			NARGB		$00
		SLOOP_BEGIN		$02
		SPR_IDX_SET		6,$54
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SLOOP_END
		POS_Y_MOVE		0,$08							; return to swim mode
		SPR_IDX_SET		0,$53
		SJMPS			_sloc_sewer_worm_state_loop

; =============== S C R I P T ==========================s====================
;
_scr_sewer_worm_active_after_stun:
		NBG_HNDL_SET	_nbgsub_sewer_worm_ctestA
		NJSR			_nsub_speed_dir_select
			NARGB		$40,$00
		SPR_IDX_SET		0,$4B
_sloc_3A335:
		NJSR			_nsub_sewer_worm_pos_test		; wait for position resets
		SBCSS			_sloc_sewer_worm_active			; then return to main active state
		SDELAY			$01
		SJMPS			_sloc_3A335

; =============== S C R I P T ==========================s====================
_scr_sewer_worm_stunA:
		NBG_HNDL_SET	_nbgsub_sewer_worm_catch_testA
		SARG_SET		SARG0,$02
_sloc_3A346:
		SPR_IDX_SET		1,$4B							; inline shake anim
		SPR_IDX_SET		1,$4E
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3A346
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$4B
		SPR_IDX_SET		1,$4E
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_sewer_worm_active_after_stun
		SCASE			_scr_sewer_worm_catch_anim_LA
		SCASE			_scr_sewer_worm_catch_anim_RA

; =============== S C R I P T ==========================s====================
; when beamed in secondary state, it should return to floating state immediately
; after release, so there is only one difference in Y adjustment
_scr_sewer_worm_stunB:
		NBG_HNDL_SET	_nbgsub_sewer_worm_catch_testB
		SARG_SET		SARG0,$02
_sloc_3A368:
		SPR_IDX_SET		1,$54
		SPR_IDX_SET		1,$57
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3A368
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$54
		SPR_IDX_SET		1,$57
		SLOOP_END
		POS_Y_MOVE		0,$08							; here adjust Y pos to set object
		NJSR			_nsub_get_obj_stun_state		; on water when shrinked
		SJMP_SW			$03
		SCASE			_scr_sewer_worm_active_after_stun
		SCASE			_scr_sewer_worm_catch_anim_LB
		SCASE			_scr_sewer_worm_catch_anim_RB

; =============== S C R I P T ==========================s====================
_scr_sewer_worm_catch_anim_LA:
		SARG_SET		SARG1,$4F
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_sewer_worm_catch_anim_RA:
		SARG_SET		SARG1,$51
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S C R I P T ==========================s====================
_scr_sewer_worm_catch_anim_LB:
		SARG_SET		SARG1,$58
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_sewer_worm_catch_anim_RB:
		SARG_SET		SARG1,$5A
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_sewer_worm_ctestA:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_3A3AD
		JSR		_cur_thread_reload_param
		.WORD	_scr_sewer_worm_stunA
		RTS
loc_3A3AD:
		LDX		#$0B
		LDY		#$09
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_sewer_worm_catch_testA:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3A3CD
		LSR
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3A3C8
		JSR		_cur_thread_reload_param
		.WORD	_scr_sewer_worm_catch_anim_LA
		RTS
loc_3A3C8:
		JSR		_cur_thread_reload_param
		.WORD	_scr_sewer_worm_catch_anim_RA
locret_3A3CD:
		RTS

; =============== S U B R O U T I N E ======n================================
_nbgsub_sewer_worm_ctestB:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3A3DD
		JSR		_cur_thread_reload_param
		.WORD	_scr_sewer_worm_stunB
		RTS
loc_3A3DD:
		LDX		#$0B
		LDY		#$10
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_sewer_worm_catch_testB:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3A3FD
		LSR
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3A3F8
		JSR		_cur_thread_reload_param
		.WORD	_scr_sewer_worm_catch_anim_LB
		RTS
loc_3A3F8:
		JSR		_cur_thread_reload_param
		.WORD	_scr_sewer_worm_catch_anim_RB
locret_3A3FD:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_sewer_worm_move_anim:
		LDA		#$04						; select random movement direction
		JSR		_rand
		LDX		_cur_trd_slot
		TAY
		LSR
		ROR
		ROR
		STA		_trds_args1,X				; store it to SARG1
		LDA		_obj_x_pos_lo,X				; calculate next tile position
		CLC									; in given direction
		ADC		byte_3A439,Y
		PHA
		LDA		_obj_x_pos_hi,X
		ADC		byte_3A43D,Y
		STA		_tmp_var0
		LDA		_obj_y_pos_lo,X
		CLC
		ADC		byte_3A441,Y
		PHA
		LDA		_obj_y_pos_hi,X
		ADC		byte_3A445,Y
		STA		_tmp_var1
		PLA
		TAY
		PLA
		TAX
		JSR		_far_room_macro_block_read	; calculate room offset,
		BEQ		loc_3A437					; and read out macro tile data
		CMP		#$0D						; macroses $01-$0C are floatable
		BCS		loc_3A437
		RTS
loc_3A437:
		SEC
		RTS
byte_3A439:
		.BYTE	$00,$10,$00,$F0
byte_3A43D:
		.BYTE	$00,$00,$00,$FF
byte_3A441:
		.BYTE	$F0,$00,$10,$00
byte_3A445:
		.BYTE	$FF,$00,$00,$00

; =============== S U B R O U T I N E ======n================================
_nsub_sewer_worm_pos_test:
		LDX		_cur_trd_slot				; wait for worm reached particular
		LDA		_obj_x_pos_lo,X				; position for release, most of the
		AND		#$0F						; time, test here is passed, Y test
		CMP		#$08						; never performed. also Y set in release
		BEQ		locret_3A45C				; script to 8 manually as well
		LDA		_obj_y_pos_lo,X
		AND		#$0F
		CMP		#$08
		BEQ		locret_3A45C
		CLC
locret_3A45C:
		RTS

; =============== S C R I P T ==========================s====================
_scr_sewer_worm_proj:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_sewer_worm_proj_ctest
		NJSR			_nsub_sewer_worm_proj_direction_select
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; select random destination
		POS_Y_DELTA_ADD 0,$00,$FE						; ballistic animate
		SPR_IDX_SET		0,$5C
		SLOOP_BEGIN		$3C
		POS_Y_DELTA_ADD 1,$10,$00
		SLOOP_END
		POS_MOVE_STOP	0								; final splash spr set
		SPR_IDX_INC		4
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_sewer_worm_proj_ctest:
		LDX		#$06
		LDY		#$07
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E ======n================================
_nsub_sewer_worm_proj_direction_select:
		LDA		#$00
		JSR		_rand
		AND		#$E0						; choose cardinal directions as well
		LDX		_cur_trd_slot				; as diagonal ones, 8 possible ways
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr2D_rotator:
		SLOOP_BEGIN		$10								; simple object, nothing special
		SPR_IDX_SET		1,$62
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_rotator_active:
		NBG_HNDL_SET	_nbgsub_rotator_ctest
_sloc_3A55B:
		SPR_IDX_SET		5,$5E							; not move, slow spin up
		SLOOP_BEGIN		$07
		SPR_IDX_INC		5
		SLOOP_END
		SPR_IDX_SET		3,$5E							; spin faster
		SLOOP_BEGIN		$07
		SPR_IDX_INC		3
		SLOOP_END
		SLOOP_BEGIN		$03								; and faster a lot
		SPR_IDX_SET		1,$5E
		SLOOP_BEGIN		$07
		SPR_IDX_INC		1
		SLOOP_END
		SLOOP_END
		NJSR			_nsub_obj_to_beamer_fast_right_turn
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3A597						; now retarget to beamer and test for obstacles
		SARG_ALU		SARG1,_ADC,$40					; in that direction close to object
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3A597						; same as for most square walking objects
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3A597
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCSS			_sloc_3A5AB
_sloc_3A597:
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; set speed
		SLOOP_BEGIN		$0A
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCS_BREAK		_sloc_3A5AB						; slide until end of the loop or obstacle appears
		SPR_IDX_SET		1,$5E							; repeat for 10 cycles
		SLOOP_BEGIN		$07
		SPR_IDX_INC		1
		SLOOP_END
		SLOOP_END
_sloc_3A5AB:
		POS_MOVE_STOP	0								; stop, reset initial sprite idx
		SPR_IDX_SET		3,$5E							; final slow down rotation
		SLOOP_BEGIN		$07
		SPR_IDX_INC		3
		SLOOP_END
		SJMPS			_sloc_3A55B

; =============== S C R I P T ==========================s====================
_scr_rotator_stun:
		NBG_HNDL_SET	_nbgsub_rotator_catch_test
		SARG_SET		SARG0,$02
_sloc_3A5BB:
		SPR_IDX_SET		1,$66							; more inline shake anims, since
		SPR_IDX_SET		1,$62
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3A5BB
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$66
		SPR_IDX_SET		1,$62
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_rotator_active
		SCASE			_scr_rotator_catch_anim_L
		SCASE			_scr_rotator_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_rotator_catch_anim_L:
		SARG_SET		SARG1,$67
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_rotator_catch_anim_R:
		SARG_SET		SARG1,$69
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_rotator_ctest:
		LDX		#$04
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3A5F2
		JSR		_cur_thread_reload_param
		.WORD	_scr_rotator_stun
		RTS
loc_3A5F2:
		LDX		#$08
		LDY		#$10
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_rotator_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3A612
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_3A60D
		JSR		_cur_thread_reload_param
		.WORD	_scr_rotator_catch_anim_L
		RTS
loc_3A60D:
		JSR		_cur_thread_reload_param
		.WORD	_scr_rotator_catch_anim_R
locret_3A612:
		RTS

; =============== S C R I P T ==========================s====================
; this is an actor object, non-enemy type. every object lights up three
; sets of candles, two flames at once to the left and to the right for
; every instance.
_scr0F_candle:
		NJSR			_nsub_obj_sarg_add_imm_test		; base candle object run two more
			NARGB		SARG0,$FF						; entities after start, all three
		SJMP_SW			$01								; candle lines are for 1 single screen
		SCASE			_scr_candle_light_up

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_new_thread_start			; default entry for every base object
			NARGB		_scr0F_candle_idx				; the second object in first room
			NARGB		$00,$B0							; adds three candles as well, but the last
			NARGB		_scr_candle_light_up_idx+1		; one object positioned above the exit area
			NARGB		$00								; so it never happen to light up there.
		NJSR			_nsub_new_thread_start
			NARGB		_scr0F_candle_idx
			NARGB		$00,$50
			NARGB		_scr_candle_light_up_idx+1
			NARGB		$00

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_candle_light_up:
		SDELAY			$01								; all objects goes here finally to wait
		NJSR			_nsub_candle_activate_test		; for player passes particular position
		SBCCS			_scr_candle_light_up			; the same as the candle Y position of
		NJSR			_nsub_apu_snd_load				; the every thread object instance,
			NARGB		_snd23_idx
_sloc_3A745:
		SPR_IDX_SET		3,$6B							; and animate fire
		SPR_IDX_INC		3
		SPR_IDX_SET		3,$FF
		SJMPS			_sloc_3A745

; =============== S U B R O U T I N E ======n================================
_nsub_candle_activate_test:
		LDX		_cur_trd_slot
		LDA		_obj_y_pos_hi+2				; test beamer Y pos with object's Y pos
		CMP		_obj_y_pos_hi,X
		BCC		loc_3A761
		BNE		loc_3A763
		LDA		_obj_y_pos_lo+2
		CMP		_obj_y_pos_lo,X
		BCC		loc_3A761
		BNE		loc_3A763
loc_3A761:
		SEC
		RTS
loc_3A763:
		CLC
		RTS

; =============== S C R I P T ==========================s====================
; another actor object for last part of the LVL2 - the train.
;
_scr10_train_semaphores:
		SPR_IDX_SET		0,$6D							; single sprite
		POS_X_SET		0,$38,$05						; show at tle left side
		SJSRS			_ssub_semaphore_anim			; animate Y position
		POS_X_SET		0,$C8,$05						; then at the right side
		SJSRS			_ssub_semaphore_anim			; animate next Y position
		SJMPS			_scr10_train_semaphores			; repeat

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_semaphore_anim:
		NJSR			_nsub_semaphore_screen_pos_init	; init Y by current scroll position
		POS_Y_DELTA_SET 0,$75,$FD						; set movement delta
_sloc_3A78E:
		SDELAY			$01								; animate until next tile (every 8 pixels)
		NJSR			_nsub_semaphore_screen_pos_adjust
		SBCCS			_sloc_3A78E
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_semaphore_screen_pos_init:
		LDX		_cur_trd_slot
		LDA		_ppu_scroll_pos_y
		CLC
		ADC		#$E8
		STA		_obj_y_pos_lo,X
		LDA		_ppu_scroll_pos_y+1
		ADC		#$00
		STA		_obj_y_pos_hi,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_semaphore_screen_pos_adjust:
		LDX		_cur_trd_slot
		LDA		_obj_y_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_y
		STA		_tmp0
		LDA		_obj_y_pos_hi,X
		SBC		_ppu_scroll_pos_y+1
		BNE		loc_3A7C0
		LDA		_tmp0
		CMP		#$08
		BCS		loc_3A7C0
		SEC
		RTS
loc_3A7C0:
		CLC
		RTS

; =============== S C R I P T ==========================s====================
; here continues the regular enemies scripts for LVL1
;
_scr17_runner:
		SARG_SET		SARG1,$80
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$0C
		SPR_IDX_SET		1,$FF
		SLOOP_END

; =============== S C R I P T ==========================s====================
_scr_runner_active:
		POS_MOVE_STOP	0
		NBG_HNDL_SET	_nbgsub_runner_ctest
		NJSR			_nsub_sarg1_direction_extract
		SJMP_SW			$03
		SCASE			_scr_runner_move_U				; NOTE, unless most other scripts above
		SCASE			_scr_runner_move_R				; this one optimizes the case table size
		SCASE			_scr_runner_move_D				; with using the last one as a default case

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SSCRIPT1_SET	_scr_runner_move_anim_L
		SJMPS			_scr_runner_active_loop

; =============== S C R I P T ==========================s====================
_scr_runner_move_U:
		SSCRIPT1_SET	_scr_runner_move_anim_U
		SJMPS			_scr_runner_active_loop

; =============== S C R I P T ==========================s====================
_scr_runner_move_R:
		SSCRIPT1_SET	_scr_runner_move_anim_R
		SJMPS			_scr_runner_active_loop

; =============== S C R I P T ==========================s====================
_scr_runner_move_D:
		SSCRIPT1_SET	_scr_runner_move_anim_D

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_runner_active_loop:
		SDELAY			$01
		NJSR			_nsub_runner_to_room_sarg1_square_ctest
		SBCCS			_scr_runner_active_loop
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_runner_to_room_sarg1_square_ctest
		SBCCS			_scr_runner_active
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_runner_to_room_sarg1_square_ctest
		SBCCS			_scr_runner_active
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_runner_to_room_sarg1_square_ctest
		SJMPS			_scr_runner_active

; =============== S C R I P T ==========================s====================
_scr_runner_move_anim_L:
		POS_X_DELTA_SET 0,$80,$FE
		SPR_IDX_SET		0,$10
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		6
		POS_X_DELTA_SET 0,$80,$FE
		SPR_IDX_INC		0
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		6
		SJMPS			_scr_runner_move_anim_L

; =============== S C R I P T ==========================s====================
_scr_runner_move_anim_U:
		POS_Y_DELTA_SET 0,$80,$FE
		SPR_IDX_SET		0,$04
		SDELAY			$08
		POS_Y_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		6
		POS_Y_DELTA_SET 0,$80,$FE
		SPR_IDX_INC		0
		SDELAY			$08
		POS_Y_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		6
		SJMPS			_scr_runner_move_anim_U

; =============== S C R I P T ==========================s====================
_scr_runner_move_anim_R:
		POS_X_DELTA_SET 0,$80,$01
		SPR_IDX_SET		0,$08
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$01
		SPR_IDX_INC		6
		POS_X_DELTA_SET 0,$80,$01
		SPR_IDX_INC		0
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$01
		SPR_IDX_INC		6
		SJMPS			_scr_runner_move_anim_R

; =============== S C R I P T ==========================s====================
_scr_runner_move_anim_D:
		POS_Y_DELTA_SET 0,$80,$01
		SPR_IDX_SET		0,$0C
		SDELAY			$08
		POS_Y_DELTA_SET 0,$00,$01
		SPR_IDX_INC		6
		POS_Y_DELTA_SET 0,$80,$01
		SPR_IDX_INC		0
		SDELAY			$08
		POS_Y_DELTA_SET 0,$00,$01
		SPR_IDX_INC		6
		SJMPS			_scr_runner_move_anim_D

; =============== S C R I P T ==========================s====================
_scr_runner_stun:
		NBG_HNDL_SET	_nbgsub_runner_catch_test
		SARG_SET		SARG0,$02
_sloc_3A97E:
		SJSRS			_ssub_runner_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3A97E
		SLOOP_BEGIN		$14
		SJSRS			_ssub_runner_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_runner_active
		SCASE			_scr_runner_catch_anim_L
		SCASE			_scr_runner_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_runner_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$04,$10
		SDELAY			$01
		NJSR			_nsub_spr_dir_select
			NARGB		$14,$40
		SDELAY			$01
		SRET

; =============== S C R I P T ==========================s====================
_scr_runner_catch_anim_L:
		SARG_SET		SARG1,$18
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_runner_catch_anim_R:
		SARG_SET		SARG1,$1A
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_runner_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3A9C2
		JSR		_cur_thread_reload_param
		.WORD	_scr_runner_stun
		RTS
loc_3A9C2:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_runner_to_room_sarg1_square_ctest:
		JSR		_nsub_sarg1_direction_extract
		TAX
		LDA		off_3AA15,X
		LDY		off_3AA19,X
		JMP		_obj_to_room_bound_box_ctest

off_3AA15:
		.BYTE	<[byte_3AA1D]
		.BYTE	<[byte_3AA22]
		.BYTE	<[byte_3AA27]
		.BYTE	<[byte_3AA2C]
off_3AA19:
		.BYTE	>[byte_3AA1D]
		.BYTE	>[byte_3AA22]
		.BYTE	>[byte_3AA27]
		.BYTE	>[byte_3AA2C]
byte_3AA1D:
		.BYTE	$02
		.BYTE	$F8,$F6
		.BYTE	$00,$F6
byte_3AA22:
		.BYTE	$02
		.BYTE	$09,$F8
		.BYTE	$09,$00
byte_3AA27:
		.BYTE	$02
		.BYTE	$F8,$09
		.BYTE	$00,$09
byte_3AA2C:
		.BYTE	$02
		.BYTE	$F6,$F8
		.BYTE	$F6,$00

; =============== S U B R O U T I N E ======n================================
_nbgsub_runner_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3AA4A
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3AA45
		JSR		_cur_thread_reload_param
		.WORD	_scr_runner_catch_anim_L
		RTS
loc_3AA45:
		JSR		_cur_thread_reload_param
		.WORD	_scr_runner_catch_anim_R
locret_3AA4A:
		RTS

; =============== S C R I P T ==========================s====================
; chainsaw ghost has two phases, invisible and visible. while invisible
; cannot be catched.
;
_scr18_chain_saw:
		SPR_IDX_SET		0,$34							; set invisible state
_sloc_3AC3B:
		POS_MOVE_STOP	0
		SDELAY			$14								; wait, then target on beamer
		NJSR			_nsub_obj_to_beamer_fast_right_turn
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3AC65						; check next position for obstacles
		SARG_ALU		SARG1,_ADC,$40					; if obstacles detected in front of object
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCCS			_sloc_3AC65						; first turn right clockwize first
		SARG_ALU		SARG1,_ADC,$80					; then bounce back, and then turn counter
		NJSR			_nsub_obj_to_room_sarg1_square_ctest	; clockwize and run back.
		SBCCS			_sloc_3AC65
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_obj_to_room_sarg1_square_ctest
		SBCSS			_sloc_3AC3B
_sloc_3AC65:
		NJSR			_nsub_speed_dir_select			; set speed
			NARGB		$80,$00
		SDELAY			$10
		NJSR			_nsub_obj_to_obj_in_range_test	; additional trigger if beamer gets in
			NARGB		$02,$40							; object's range ($02 - beamer slot idx, $40 - range)
		SBCCS			_sloc_3AC3B						; stay invisible and move randomly if no beamer nearby
		NBG_HNDL_SET	_nbgsub_chain_saw_ctest			; otherwize, show up, activate collision test
		NJSR			_nsub_obj_to_beamer_fast_right_turn
		SJSRS			_ssub_chain_saw_attack_spr_anim	; target on beamer and do attack animation
		SSCRIPT1_SET	_ssub_chain_saw_slide_spr_anim	; then set movement speed and secondary
		NJSR			_nsub_speed_dir_select			; slide animation
			NARGB		$00,$01
		SLOOP_BEGIN		$06								; slide in selected direction until end of loop
		NJSR			_nsub_obj_to_room_sarg1_square_ctest	; or until any obstacle
		SBCS_BREAK		_sloc_3AC91
		SDELAY			$08
		SLOOP_END
_sloc_3AC91:
		SSCRIPT1_OFF									; disable anim and return to invisible state

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_chain_saw_turn_invisible:
		SJSRS			_ssub_chain_saw_attack_spr_anim
		NBG_HNDL_RESET
		SJMPS			_scr18_chain_saw

; =============== S C R I P T ==========================s====================
_ssub_chain_saw_slide_spr_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$28,$40
_sloc_3AC9F:
		SPR_IDX_ADD_IMM 4,$FC
		SPR_IDX_ADD_IMM 4,$04
		SJMPS			_sloc_3AC9F

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_chain_saw_attack_spr_anim:
		POS_MOVE_STOP	0
		NJSR			_nsub_spr_dir_select
			NARGB		$20,$40
		SLOOP_BEGIN		$04
		SPR_IDX_ADD_IMM 4,$FC
		SPR_IDX_ADD_IMM 4,$04
		SLOOP_END
		SRET

; =============== S C R I P T ==========================s====================
_scr_chain_saw_stun:
		NBG_HNDL_SET	_nbgsub_chain_saw_catch_test
		SARG_SET		SARG0,$02
_sloc_3ACBA:
		SJSRS			_ssub_chain_saw_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3ACBA
		SLOOP_BEGIN		$14
		SJSRS			_ssub_chain_saw_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_chain_saw_turn_invisible
		SCASE			_scr_chain_saw_catch_anim_L
		SCASE			_scr_chain_saw_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_chain_saw_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$24,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_chain_saw_catch_anim_L:
		SARG_SET		SARG1,$30
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_chain_saw_catch_anim_R:
		SARG_SET		SARG1,$32
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_chain_saw_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3ACF9
		JSR		_cur_thread_reload_param
		.WORD	_scr_chain_saw_stun
		RTS
loc_3ACF9:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_chain_saw_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3AD19
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_3AD14
		JSR		_cur_thread_reload_param
		.WORD	_scr_chain_saw_catch_anim_L
		RTS
loc_3AD14:
		JSR		_cur_thread_reload_param
		.WORD	_scr_chain_saw_catch_anim_R
locret_3AD19:
		RTS

; =============== S C R I P T ==========================s====================
_scr19_toilet_snake:
		SPR_IDX_SET		0,$35							; one more hiding object invincible
		SDELAY			$1E								; in this state
_sloc_3AFDF:
		SDELAY			$01
		NJSR			_nsub_obj_to_obj_in_range_test	; wait for beamer nearby
			NARGB		$02,$40
		SBCCS			_sloc_3AFDF
		POS_Y_MOVE		0,$04							; then expand
		SPR_IDX_INC		1
		POS_Y_MOVE		0,$03
		SPR_IDX_INC		1
		POS_Y_MOVE		0,$03
		SPR_IDX_INC		1
		POS_Y_MOVE		0,$02
		SPR_IDX_INC		2
		POS_Y_MOVE		0,$03
		SPR_IDX_INC		2
		POS_Y_MOVE		0,$02
		SPR_IDX_INC		3
		NBG_HNDL_SET	_nbgsub_toilet_snake_ctest		; enable collision tests
		POS_Y_MOVE		0,$03
		SPR_IDX_INC		0
		SDELAY			$2D								; wait for 45 frames (3/4 sec)

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_toilet_snake_hide:
		NBG_HNDL_RESET									; disable collisions test
		POS_Y_MOVE		0,$FD							; shrink back
		SPR_IDX_SET		0,$3B
		POS_Y_MOVE		0,$FE
		SPR_IDX_DEC		4
		POS_Y_MOVE		0,$FD
		SPR_IDX_DEC		4
		POS_Y_MOVE		0,$FE
		SPR_IDX_DEC		4
		POS_Y_MOVE		0,$FD
		SPR_IDX_DEC		4
		POS_Y_MOVE		0,$FD
		SPR_IDX_DEC		4
		POS_Y_MOVE		0,$FC
		SPR_IDX_DEC		4
		SJMPS			_scr19_toilet_snake				; return to default state

; =============== S C R I P T ==========================s====================
_scr_toliet_snake_stun:
		NBG_HNDL_SET	_nbgsub_toilet_snake_catch_test
		SARG_SET		SARG0,$02
_sloc_3B023:
		SPR_IDX_SET		1,$3D
		SPR_IDX_SET		1,$3C
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3B023
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$3D
		SPR_IDX_SET		1,$3C
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_toilet_snake_hide
		SCASE			_scr_toilet_snake_catch_anim_L
		SCASE			_scr_toilet_snake_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_toilet_snake_catch_anim_L:
		SARG_SET		SARG1,$3E
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_toilet_snake_catch_anim_R:
		SARG_SET		SARG1,$40
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_toilet_snake_ctest:
		LDX		#$04
		LDY		#$16
		JSR		_obj_to_beam_ctest
		BCC		loc_3B05A
		JSR		_cur_thread_reload_param
		.WORD	_scr_toliet_snake_stun
		RTS
loc_3B05A:
		LDX		#$09
		LDY		#$1C
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_toilet_snake_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3B07A
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3B075
		JSR		_cur_thread_reload_param
		.WORD	_scr_toilet_snake_catch_anim_L
		RTS
loc_3B075:
		JSR		_cur_thread_reload_param
		.WORD	_scr_toilet_snake_catch_anim_R
locret_3B07A:
		RTS

; =============== S C R I P T ==========================s====================
_scr2A_morning_star_troll:
		NJSR			_nsub_obj_sarg_add_imm_test		; morning star troll also has a
			NARGB		SARG0,$FF						; "projectile" - end of the morning
		SJMP_SW			$01								; start spiked ball.
		SCASE			_scr_morning_star_projectile

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SLOOP_BEGIN		$10								; blink as usual
		SPR_IDX_SET		1,$C0
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_morning_start_troll_active:
		NBG_HNDL_SET	_nbgsub_morning_start_troll_ctest; start default state with default
		SSCRIPT1_SET	_scr_morning_star_troll_idle_anim; chain spinning anim
_sloc_3B21B:
		NJSR			_nsub_morning_star_troll_action_select	; randomly move left-to-right
		SJSR_SW	$03										; bouncing of obstacles
		SCASE			_ssub_morning_star_troll_attack	; return 0 - attack
		SCASE			_ssub_morning_star_troll_move_R	; 1 - move right
		SCASE			_ssub_morning_star_troll_move_L ; 2 - move left
		SJMPS			_sloc_3B21B						; loop

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_morning_star_troll_move_R:
		POS_X_DELTA_SET 0,$80,$00
		SDELAY			$10
		POS_MOVE_STOP	0
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_morning_star_troll_move_L:
		POS_X_DELTA_SET 0,$80,$FF
		SDELAY			$10
		POS_MOVE_STOP	0
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_morning_star_troll_attack:
		SDELAY			$18
		SSCRIPT1_OFF									; stop idle spinning animation
		SPR_IDX_SET		0,$C8							; start to attack
		NJSR			_nsub_new_thread_start			; deploy extra damaging object
			NARGB		_scr2A_morning_star_troll_idx
			NARGB		$F7,$20
			NARGB		_scr_morning_star_projectile_idx+1
			NARGB		$00
		SDELAY			$18
		SSCRIPT1_SET	_scr_morning_star_troll_idle_anim; return to idle state
		SRET

; =============== S C R I P T ==========================s====================
_scr_morning_star_troll_idle_anim:
		SPR_IDX_SET		3,$C0							; spin chai above the head
		SLOOP_BEGIN		$07
		SPR_IDX_INC		3
		SLOOP_END
		SJMPS			_scr_morning_star_troll_idle_anim

; =============== S C R I P T ==========================s====================
_scr_morning_start_troll_stun:
		NBG_HNDL_SET	_nbgsub_morning_star_troll_catch_test
		SARG_SET		SARG0,$02
_sloc_3B25B:
		SPR_IDX_SET		1,$C9
		SPR_IDX_INC		1
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3B25B
		SLOOP_BEGIN		$0F
		SPR_IDX_SET		1,$C9
		SPR_IDX_INC		1
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_morning_start_troll_active
		SCASE			_scr_morning_start_troll_catch_anim_L
		SCASE			_scr_morning_start_troll_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_morning_start_troll_catch_anim_L:
		SARG_SET		SARG1,$42
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_morning_start_troll_catch_anim_R:
		SARG_SET		SARG1,$42
		SJMP			_ssub_common_catch_anim_R_snd19

; =============== S U B R O U T I N E ======n================================
_nbgsub_morning_start_troll_ctest:
		LDX		#$08
		LDY		#$0C
		JSR		_obj_to_beam_ctest
		BCC		loc_3B290
		JSR		_cur_thread_reload_param
		.WORD	_scr_morning_start_troll_stun
		RTS
loc_3B290:
		LDX		#$0A
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_morning_star_troll_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3B2B0
		LSR
		LDA		#$0F						; valuable bastart
		STA		_scores_obj_value
		BCS		loc_3B2AB
		JSR		_cur_thread_reload_param
		.WORD	_scr_morning_start_troll_catch_anim_L
		RTS
loc_3B2AB:
		JSR		_cur_thread_reload_param
		.WORD	_scr_morning_start_troll_catch_anim_R
locret_3B2B0:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_morning_star_troll_action_select:
		LDA		#$13						; get random value in range $00-$12
		JSR		_rand
		CMP		#$0F
		BCC		loc_3B2BD					; for values $0F-$12 (4/19) - return $00
		LDA		#$00
		RTS
loc_3B2BD:
		ADC		#$01						; rest values range $00-$0E turns to $01-$0F
		STA		_tmp0
		LDX		_cur_trd_slot
		LDA		_obj_x_pos_lo,X				; calculate X/16
		LSR
		LSR
		LSR
		LSR
		CLC
		ADC		#$01
		CMP		_tmp0						; compare with random number
		PHP									; extract carry flag, store it
		PLA									; if cur X/16 more equal than random, then C=1
		AND		#$01						; this selecting the side it will move
		PHA
		TAX
		LDA		off_3B2E6,X					; check the obstacle in follosing direction
		LDY		off_3B2E8,X
		JSR		_obj_to_room_bound_box_ctest
		PLA
		BCC		loc_3B2E2					; if any, invert direction
		EOR		#$01
loc_3B2E2:
		CLC									; finally, shift value to actual index
		ADC		#$01						; so return $01 or $02 accordingly
		RTS
off_3B2E6:
		.BYTE	<[byte_3B2EF]
		.BYTE	<[byte_3B2EA]
off_3B2E8:
		.BYTE	>[byte_3B2EF]
		.BYTE	>[byte_3B2EA]
byte_3B2EA:
		.BYTE	$02
		.BYTE	$F0,$F8
		.BYTE	$F0,$00
byte_3B2EF:
		.BYTE	$02
		.BYTE	$08,$F8
		.BYTE	$08,$00

; =============== S C R I P T ==========================s====================
_scr_morning_star_projectile:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_morning_star_projectile_ctest
		SPR_IDX_SET		2,$44							; extend chain with ball
		SLOOP_BEGIN		$05
		POS_Y_MOVE		0,$10
		SPR_IDX_INC		2
		SLOOP_END
		POS_MOVE_STOP	0								; max 5 sprites
		SDELAY			$02
		SLOOP_BEGIN		$05
		POS_Y_MOVE		0,$F0							; shrink it back
		SPR_IDX_DEC		2
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_morning_star_projectile_ctest:
		LDX		#$0B
		LDY		#$0C
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S C R I P T ==========================s====================
_scr1C_girl_and_floaters:
		NJSR			_nsub_obj_sarg_add_imm_test		; mini-boss of the very first stage
			NARGB		SARG0,$FF
		SJMP_SW			$03
		SCASE			_scr_girl_and_floaters_floaterB	; secondary floater
		SCASE			_scr_girl_and_floaters_girl		; girl
		SCASE			_scr_girl_and_floaters_jumpers	; small jumpers

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_patch_pal_load			; main object default handler
			NARGB		$06
			NARGW		_pal_girl_floaters_patch
		SARG_SET		SARG1,$00
		NJSR			_nsub_new_thread_start			; create new object
			NARGB		_scr1C_girl_and_floaters_idx
			NARGB		$E0,$00
			NARGB		_scr_girl_and_floaters_floaterB_idx+1
			NARGB		$00								; store it's
		NJSR			_nsub_obj_sarg_set_from_nsub_return_value	; slot index in SARG2 here,
			NARGB		SARG2							; now both objects linked
		NJSR			_nsub_new_thread_start			; start girl object
			NARGB		_scr1C_girl_and_floaters_idx
			NARGB		$F0,$00
			NARGB		_scr_girl_and_floaters_girl_idx+1
			NARGB		$00
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$4C
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_floaterA_active:
		NBG_HNDL_SET	_nbgsub_floaterA_ctest			; both floaters has the same scripts...
_sloc_3B634:
		SLOOP_BEGIN		$02								; adjust spite idx according to
		NJSR			_nsub_spr_dir_select			; face direction
			NARGB		$4C,$40
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$03							; set vector position with given radius
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$F8					; ...with one exception. they move in opposite
		SLOOP_END										; directions
		SLOOP_BEGIN		$02
		NJSR			_nsub_spr_dir_select			; repeat the same for secondary sprite idx
			NARGB		$50,$40
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SJMPS			_sloc_3B634						; repeat floating in circles

; =============== S C R I P T ==========================s====================
_scr_floaterA_stun:
		NBG_HNDL_SET	_nbgsub_floaterA_catch_test		; regular stun routine here
		SARG_SET		SARG0,$02
_sloc_3B663:
		SJSRS			_scr_floaterA_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3B663
		SLOOP_BEGIN		$0F
		SJSRS			_scr_floaterA_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_floaterA_active
		SCASE			_scr_floaterA_catch_anim_L
		SCASE			_scr_floaterA_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_floaterA_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$50,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S C R I P T ==========================s====================
_scr_floaterA_catch_anim_L:
		SARG_SET		SARG1,$58
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_floaterA_catch_anim_R:
		SARG_SET		SARG1,$5A
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S C R I P T ==========================s====================
_scr_floater_start_to_evolve:
		SPR_IDX_SET		7,$4C							; this script is called by enemy why
		SPR_IDX_INC		7								; second floater is catched, first
		SPR_IDX_INC		7								; spin up
		SPR_IDX_INC		7
		SPR_IDX_SET		6,$4C
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SPR_IDX_SET		5,$4C
		SPR_IDX_INC		5
		SPR_IDX_INC		5
		SPR_IDX_INC		5
		SPR_IDX_SET		4,$50
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_SET		3,$50
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		SPR_IDX_SET		2,$50
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SSCRIPT1_SET	_scr_floater_deploy_jumpers		; then start to deploy jumpers
		SLOOP_BEGIN		$14								; and then spin up slow down
		SPR_IDX_SET		1,$5C
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SLOOP_END
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$5F
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SLOOP_END
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SSTOP											; and finally disappear

; =============== S C R I P T ==========================s====================
_scr_floater_deploy_jumpers:
		SLOOP_BEGIN		$06
		NJSR			_nsub_new_thread_start
			NARGB		_scr1C_girl_and_floaters_idx	; deploy 6 jumpers here
			NARGB		$00,$00
			NARGB		_scr_girl_and_floaters_jumpers_idx+1
			NARGB		$00
		SDELAY			$14
		SLOOP_END
		SSCRIPT0_OFF

_pal_girl_floaters_patch:
		.BYTE	$0F,$36,$25,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_floaterA_ctest:
		LDX		#$06
		LDY		#$06
		JSR		_obj_to_beam_ctest
		BCC		loc_3B6E9
		JSR		_cur_thread_reload_param
		.WORD	_scr_floaterA_stun
		RTS
loc_3B6E9:
		LDX		#$0B
		LDY		#$0C
		JSR		_obj_to_player_ctest

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nsub_floater_pairing_test:
		LDX		_cur_trd_slot				; common additional test if other
		LDA		_trds_args2,X				; paired object is not active anymore
		BPL		locret_3B6FB
		JSR		_cur_thread_reload_param
		.WORD	_scr_floater_start_to_evolve; turn current active floater into jumpers then
locret_3B6FB:
		RTS

; =============== S U B R O U T I N E ======n================================
_nbgsub_floaterA_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3B71E
		LSR
		LDY		_trds_args2,X				; this is extra initialization, when one
		BMI		loc_3B70C					; of floaters being catched, remove link
		LDA		#$FF
		STA		_trds_args2,Y
loc_3B70C:
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3B719
		JSR		_cur_thread_reload_param
		.WORD	_scr_floaterA_catch_anim_L
		RTS
loc_3B719:
		JSR		_cur_thread_reload_param
		.WORD	_scr_floaterA_catch_anim_R
locret_3B71E:
		RTS

; =============== S C R I P T ==========================s====================
_scr_girl_and_floaters_floaterB:
		SARG_SET		SARG0,$00
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$4C
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_floaterB_active:
		NBG_HNDL_SET	_nbgsub_floaterB_ctest
_sloc_3B72C:
		SLOOP_BEGIN		$02
		NJSR			_nsub_spr_dir_select
			NARGB		$4C,$40
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SLOOP_BEGIN		$02
		NJSR			_nsub_spr_dir_select
			NARGB		$50,$40
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SJMPS			_sloc_3B72C

; =============== S C R I P T ==========================s====================
_scr_floaterB_stun:
		NBG_HNDL_SET	_nbgsub_floaterA_catch_test
		SARG_SET		SARG0,$02
_sloc_3B75B:
		SJSR			_scr_floaterA_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3B75B
		SLOOP_BEGIN		$0F
		SJSR			_scr_floaterA_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_floaterB_active
		SCASE			_scr_floaterA_catch_anim_L
		SCASE			_scr_floaterA_catch_anim_R

; =============== S U B R O U T I N E ======n================================
_nbgsub_floaterB_ctest:
		LDX		#$06
		LDY		#$06
		JSR		_obj_to_beam_ctest
		BCC		loc_3B784
		JSR		_cur_thread_reload_param
		.WORD	_scr_floaterB_stun
		RTS
loc_3B784:
		LDX		#$0B
		LDY		#$0C
		JSR		_obj_to_player_ctest
		JMP		_nsub_floater_pairing_test

; =============== S C R I P T ==========================s====================
_scr_girl_and_floaters_girl:
		SARG_SET		SARG0,$00
_sloc_3B9C7:
		SPR_IDX_SET		6,$66
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		NJSR			_nsub_is_any_enemy_active		; waiting for all enemies are
		SBCCS			_sloc_3B9C7						; disappear
		SLOOP_BEGIN		$03
		SPR_IDX_SET		0,$6A							; then start bow anim for a while
		SDELAY			$0F
		SPR_IDX_INC		0
		SDELAY			$1E
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_girl_and_floaters_jumpers:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_jumpers_ctestA
_sloc_3BA49:
		SDELAY			$01								; decide the jumping direction
		NJSR			_nsub_jumpers_dst_select		; randomly if there are no obstacles
		SBCSS			_sloc_3BA49
		NBG_HNDL_SET	_nbgsub_jumpers_ctestB			; while in mid-air change collision test
		SJSR_SW	$04										; to non-catchable, only harmful
		SCASE			_ssub_floaters_move_U			; do anim in calculated direction
		SCASE			_ssub_floaters_move_R
		SCASE			_ssub_floaters_move_D
		SCASE			_ssub_floaters_move_L
		NBG_HNDL_SET	_nbgsub_jumpers_ctestA			; when jumped, restore regular collision test
		SPR_IDX_ADD_IMM 0,$FC
		POS_MOVE_STOP	0
		SDELAY			$1E
		SJMPS			_sloc_3BA49						; stop and wait for a next jump

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_U:
		SPR_IDX_SET		0,$70
		POS_Y_DELTA_SET 4,$00,$FA
		POS_Y_DELTA_SET 4,$00,$02
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_R:
		SPR_IDX_SET		0,$71
		POS_X_DELTA_SET 0,$00,$02
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$02
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_D:
		SPR_IDX_SET		0,$72
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$06
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_L:
		SPR_IDX_SET		0,$73
		POS_X_DELTA_SET 0,$00,$FE
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$02
		SRET

; =============== S C R I P T ==========================s====================
_scr_jumpers_stun:
		NBG_HNDL_SET	_nbgsub_jumpers_catch_test
		SARG_SET		SARG0,$02
_sloc_3BA99:
		SJSRS			_ssub_jumpers_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_3BA99
		SLOOP_BEGIN		$0F
		SJSRS			_ssub_jumpers_shake_anim
		SLOOP_END
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_girl_and_floaters_jumpers
		SCASE			_scr_jumpers_catch_anim_L
		SCASE			_scr_jumpers_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_jumpers_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$70,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S C R I P T ==========================s====================
_scr_jumpers_catch_anim_L:
		SARG_SET		SARG1,$78
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_jumpers_catch_anim_R:
		SARG_SET		SARG1,$7A
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S U B R O U T I N E ======n================================
_nbgsub_jumpers_ctestA:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		_nbgsub_jumpers_ctestB
		JSR		_cur_thread_reload_param
		.WORD	_scr_jumpers_stun
		RTS

; =============== S U B R O U T I N E ======n================================
_nbgsub_jumpers_ctestB:
		LDX		#$08
		LDY		#$09
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_jumpers_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_3BAF8
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3BAF3
		JSR		_cur_thread_reload_param
		.WORD	_scr_jumpers_catch_anim_L
		RTS
loc_3BAF3:
		JSR		_cur_thread_reload_param
		.WORD	_scr_jumpers_catch_anim_R
locret_3BAF8:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_jumpers_dst_select:
		LDA		#$00
		JSR		_rand
		AND		#$03
		PHA
		TAX
		LDA		off_3BB0D,X
		LDY		off_3BB11,X
		JSR		_obj_to_room_bound_box_ctest
		PLA
		RTS

off_3BB0D:
		.BYTE	<[byte_3BB15]
		.BYTE	<[byte_3BB1E]
		.BYTE	<[byte_3BB27]
		.BYTE	<[byte_3BB30]
off_3BB11:
		.BYTE	>[byte_3BB15]
		.BYTE	>[byte_3BB1E]
		.BYTE	>[byte_3BB27]
		.BYTE	>[byte_3BB30]
byte_3BB15:
		.BYTE	$04
		.BYTE	$F8,$F8
		.BYTE	$00,$F8
		.BYTE	$F8,$F0
		.BYTE	$00,$F0
byte_3BB1E:
		.BYTE	$04
		.BYTE	$08,$F8
		.BYTE	$08,$00
		.BYTE	$10,$F8
		.BYTE	$10,$00
byte_3BB27:
		.BYTE	$04
		.BYTE	$F8,$08
		.BYTE	$00,$08
		.BYTE	$F8,$10
		.BYTE	$00,$10
byte_3BB30:
		.BYTE	$04
		.BYTE	$F0,$F8
		.BYTE	$F0,$00
		.BYTE	$E8,$F8
		.BYTE	$E8,$00

; =============== S C R I P T ==========================s====================
; pure automated script animation with no harm to the player...
;
_scr11_lvl2_ghost_nanny:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$02
		SCASE			_scr_ghost_nanny_baby
		SCASE			_scr_ghost_nanny_itself

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
; main script body handles the mother animation
;
		NJSR			_nsub_lvl3_players_auto_scripts_set
		STORE8			_chr_bank0,$14
		NJSR			_nsub_apu_mus_load				; start music
			NARGB		_musC_idx
		NJSR			_nsub_new_thread_start			; set baby animated object
			NARGB		_scr11_lvl2_ghost_nanny_idx
			NARGB		$00,$00
			NARGB		_scr_ghost_nanny_baby_idx+1
			NARGB		$00
		POS_X_SET		0,$90,$00
		POS_Y_SET		0,$C0,$02
		SLOOP_BEGIN		$02								; do mother walk two times
		SJSRS			_ssub_ghost_nanny_mother_anim
		SLOOP_END
		NJSR			_nsub_new_thread_start			; nanny appears
			NARGB		_scr11_lvl2_ghost_nanny_idx
			NARGB		$00,$00
			NARGB		_scr_ghost_nanny_itself_idx+1
			NARGB		$00
		SLOOP_BEGIN		$04
		SJSRS			_ssub_ghost_nanny_mother_anim	; mother continues to walk
		SLOOP_END
		POS_MOVE_STOP	0								; when ghost kidnap the baby
		SPR_IDX_SET		0,$7E							; mother runs to the right edge
		SDELAY			$10								; of the roof...
		POS_X_DELTA_SET 0,$80,$01
		SLOOP_BEGIN		$03
		SPR_IDX_SET		6,$7D
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SPR_IDX_SET		0,$FF							; ...then disappears
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$80
		SMEM_ALU		_apu_mus_volume,_ADC,$FF		; music now fades
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_stage_complete_force		; force stage complete script
		SSTOP

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_ghost_nanny_mother_anim:
		POS_MOVE_STOP	0								; just walk left, then right
		SPR_IDX_SET		6,$7C							; once for one cycle
		POS_X_DELTA_SET 0,$C0,$00
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		POS_MOVE_STOP	0
		SPR_IDX_INC		6
		POS_X_DELTA_SET 0,$40,$FF
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_lvl3_players_auto_scripts_set:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl3_beamer_auto_script
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl3_catcher_auto_script
		RTS

; =============== S C R I P T ==========================s====================
_scr_ghost_nanny_baby:
		SARG_SET		SARG0,$00						; baby waving the hands for a while
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$A0,$02
		SLOOP_BEGIN		$0F
		SPR_IDX_SET		7,$84
		SPR_IDX_INC		7
		SLOOP_END
		SPR_IDX_SET		7,$84							; do two final wavings before being
		SPR_IDX_INC		3								; grabbed by nanny and then disappear
		SSTOP											; from roow, now it's drawn by nanny sprite

; =============== S C R I P T ==========================s====================
_scr_ghost_nanny_itself:
		SARG_SET		SARG0,$00						; ghost nanny appears from the top
		POS_X_SET		0,$70,$00						; descent carefully
		POS_Y_SET		0,$00,$02
		POS_Y_DELTA_SET 0,$40,$01
		SPR_IDX_SET		0,$86
		SDELAY			$3A
		POS_X_DELTA_SET 0,$20,$00
		SDELAY			$10
		POS_X_DELTA_SET 0,$80,$00
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$0A
		POS_MOVE_STOP	0
		SPR_IDX_INC		0								; extend it's hand
		SDELAY			$0A
		SPR_IDX_INC		0
		SDELAY			$0A
		SPR_IDX_INC		4								; grab baby
		SPR_IDX_INC		0
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$0A
		SPR_IDX_INC		0
		SDELAY			$0A								; shrink the hand
		POS_X_DELTA_SET 0,$40,$01						; set movement to the right
		SPR_IDX_SET		0,$87							; disable the baby sprite also
		SDELAY			$50
		SSTOP

		SECTION_END	"OBJECT SCRIPTS A (ENEMY/ACTORS)"

		SECTION_START

_spr_libA05:
		.WORD	_sprA08_00
		.WORD	_sprA08_01
		.WORD	_sprA08_02
		.WORD	_sprA08_03
		.WORD	_sprA05_04
		.WORD	_sprA05_05
		.WORD	_sprA05_06
		.WORD	_sprA05_07
		.WORD	_sprA05_08
		.WORD	_sprA05_09
		.WORD	_sprA05_0A
		.WORD	_sprA05_0B
		.WORD	_sprA05_0C
		.WORD	_sprA05_0D
		.WORD	_sprA05_0E
		.WORD	_sprA05_0F
		.WORD	_sprA05_10
		.WORD	_sprA05_11
		.WORD	_sprA05_12
		.WORD	_sprA05_13
		.WORD	_sprA05_14
; NOTE: there are 4 diifferent objects to throw only one of them has full rorate
; animations the rest are same for all 4 frames.
; why they did not animated all of them, don't know, seems most probably
; because lack of free space in this particular bank.
;
; NEW: restored animations for three throwable objects
;
		.WORD	_sprA05_15	; meat
		.WORD	_sprA05_16
		.WORD	_sprA05_17
		.WORD	_sprA05_18
		.WORD	_sprA05_19	; pan
		.WORD	_sprA05_1A
		.WORD	_sprA05_1B
		.WORD	_sprA05_1C
		.WORD	_sprA05_1D	; pineaple
		.WORD	_sprA05_1E
		.WORD	_sprA05_1F
		.WORD	_sprA05_20
		.WORD	_sprA05_21	; coat rack
		.WORD	_sprA05_22
		.WORD	_sprA05_23
		.WORD	_sprA05_24
		.WORD	_sprA05_25
		.WORD	_sprA05_26
		.WORD	_sprA05_27
		.WORD	_sprA05_28
		.WORD	_sprA05_29
		.WORD	_sprA05_2A
		.WORD	_sprA05_2B
		.WORD	_sprA05_2C
		.WORD	_sprA05_2D
		.WORD	_sprA05_2E
		.WORD	_sprA05_2F
		.WORD	_sprA05_30
		.WORD	_sprA05_31
		.WORD	_sprA05_32
		.WORD	_sprA05_33
		.WORD	_sprA05_34
		.WORD	_sprA05_35
		.WORD	_sprA05_36
		.WORD	_sprA05_37
		.WORD	_sprA05_38
		.WORD	_sprA05_39
		.WORD	_sprA05_3A
		.WORD	_sprA05_3B
		.WORD	_sprA05_3C
		.WORD	_sprA05_3D
		.WORD	_sprA05_3E
		.WORD	_sprA05_3F
		.WORD	_sprA05_40
		.WORD	_sprA05_41
		.WORD	_sprA05_42
		.WORD	_sprA05_43
		.WORD	_sprA05_44
		.WORD	_sprA05_45
		.WORD	_sprA05_46
		.WORD	_sprA05_47
		.WORD	_sprA05_48
		.WORD	_sprA05_49
		.WORD	_sprA05_4A
		.WORD	_sprA05_4B
		.WORD	_sprA05_4C
		.WORD	_sprA05_4D
		.WORD	_sprA05_4E
		.WORD	_sprA05_4F
		.WORD	_sprA05_50
		.WORD	_sprA05_51
		.WORD	_sprA05_52
		.WORD	_sprA05_53
		.WORD	_sprA05_56
		.WORD	_sprA05_57
		.WORD	_sprA05_56
		.WORD	_sprA05_57
		.WORD	_sprA05_58
		.WORD	_sprA05_59
		.WORD	_sprA05_5A
		.WORD	_sprA05_5B
		.WORD	_sprA05_5C
		.WORD	_sprA05_5D
		.WORD	_sprA05_5E
		.WORD	_sprA05_5F
		.WORD	_sprA05_60
		.WORD	_sprA05_61
		.WORD	_sprA05_62
		.WORD	_sprA05_63
		.WORD	_sprA05_64
		.WORD	_sprA05_65
		.WORD	_sprA05_66
		.WORD	_sprA05_67
		.WORD	_sprA05_68
		.WORD	_sprA05_69
		.WORD	_sprA05_6A
		.WORD	_sprA05_6B
		.WORD	_sprA05_6C
		.WORD	_sprA05_6D
		.WORD	_sprA05_6E
		.WORD	_sprA05_6F
		.WORD	_sprA05_70
		.WORD	_sprA05_71
		.WORD	_sprA05_72
		.WORD	_sprA05_73
		.WORD	_sprA05_74
		.WORD	_sprA05_75
		.WORD	_sprA05_77
		.WORD	_sprA05_77
		.WORD	_sprA05_79
		.WORD	_sprA05_79
		.WORD	_sprA05_7A
		.WORD	_sprA05_7B
; NOTE: the same case for these projectile... most objects are animated in
; 4 frame as rotaded sprite. but 3 out of 7 objects doesn't
;
		.WORD	_sprA05_7C	; bottle
		.WORD	_sprA05_7D
		.WORD	_sprA05_7E
		.WORD	_sprA05_7F
		.WORD	_sprA05_80	; key
		.WORD	_sprA05_81
		.WORD	_sprA05_82
		.WORD	_sprA05_83
		.WORD	_sprA05_84	; coat rack
		.WORD	_sprA05_85
		.WORD	_sprA05_86
		.WORD	_sprA05_87
		.WORD	_sprA05_88	; hammer
		.WORD	_sprA05_89
		.WORD	_sprA05_8A
		.WORD	_sprA05_8B
; TODO: animate
;
		.WORD	_sprA05_8F	; 8C pan
		.WORD	_sprA05_8F	; 8D
		.WORD	_sprA05_8F	; 8E
		.WORD	_sprA05_8F	; 8F
		.WORD	_sprA05_93	; 90 rock
		.WORD	_sprA05_93	; 91
		.WORD	_sprA05_93	; 92
		.WORD	_sprA05_93	; 93
		.WORD	_sprA05_97	; 94 brick
		.WORD	_sprA05_97	; 95
		.WORD	_sprA05_97	; 96
		.WORD	_sprA05_97	; 97

_sprA05_04:
		.BYTE	$82
		.WORD	_sprA05_04_B
		.WORD	_sprA05_04_A
_sprA05_04_A:
		.BYTE	$02
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
_sprA05_04_B:
		.BYTE	$04
		.BYTE	$01,$A4,$02,$F8
		.BYTE	$01,$A4,$42,$00
		.BYTE	$F1,$94,$02,$F8
		.BYTE	$F1,$94,$42,$00
_sprA05_05:
		.BYTE	$82
		.WORD	_sprA05_05_B
		.WORD	_sprA05_05_A
_sprA05_05_A:
		.BYTE	$02
		.BYTE	$06,$3E,$02,$00
		.BYTE	$06,$3E,$42,$F8
_sprA05_05_B:
		.BYTE	$04
		.BYTE	$01,$A2,$42,$00
		.BYTE	$01,$B2,$42,$F8
		.BYTE	$F1,$92,$42,$00
		.BYTE	$F1,$B0,$42,$F8
_sprA05_06:
		.BYTE	$82
		.WORD	_sprA05_06_B
		.WORD	_sprA05_04_A
_sprA05_06_B
		.BYTE	$04
		.BYTE	$01,$82,$02,$F8
		.BYTE	$01,$82,$42,$00
		.BYTE	$F1,$90,$02,$F8
		.BYTE	$F1,$90,$42,$00
_sprA05_07:
		.BYTE	$82
		.WORD	_sprA05_07_B
		.WORD	_sprA05_05_A
_sprA05_07_B
		.BYTE	$04
		.BYTE	$01,$A2,$02,$F8
		.BYTE	$01,$B2,$02,$00
		.BYTE	$F1,$92,$02,$F8
		.BYTE	$F1,$B0,$02,$00
_sprA05_08:
		.BYTE	$82
		.WORD	_sprA05_08_B
		.WORD	_sprA05_04_A
_sprA05_08_B
		.BYTE	$04
		.BYTE	$00,$A4,$02,$F8
		.BYTE	$00,$A4,$42,$00
		.BYTE	$F0,$84,$02,$F8
		.BYTE	$F0,$84,$42,$00
_sprA05_09:
		.BYTE	$82
		.WORD	_sprA05_09_B
		.WORD	_sprA05_05_A
_sprA05_09_B
		.BYTE	$04
		.BYTE	$00,$A2,$42,$00
		.BYTE	$00,$B2,$42,$F8
		.BYTE	$F0,$A0,$42,$00
		.BYTE	$F0,$B0,$42,$F8
_sprA05_0A:
		.BYTE	$82
		.WORD	_sprA05_56
		.WORD	_sprA05_04_A
_sprA05_0B:
		.BYTE	$82
		.WORD	_sprA05_0B_B
		.WORD	_sprA05_05_A
_sprA05_0B_B
		.BYTE	$04
		.BYTE	$00,$A2,$02,$F8
		.BYTE	$00,$B2,$02,$00
		.BYTE	$F0,$A0,$02,$F8
		.BYTE	$F0,$B0,$02,$00
_sprA05_0C:
		.BYTE	$82
		.WORD	_sprA05_0C_B
		.WORD	_sprA05_0C_A
_sprA05_0C_A:
		.BYTE	$02
		.BYTE	$08,$3E,$02,$02
		.BYTE	$08,$3E,$42,$FA
_sprA05_0C_B:
		.BYTE	$04
		.BYTE	$00,$A4,$02,$FA
		.BYTE	$00,$A4,$42,$02
		.BYTE	$F0,$84,$02,$FA
		.BYTE	$F0,$84,$42,$02
_sprA05_0D:
		.BYTE	$06
		.BYTE	$00,$A2,$42,$02
		.BYTE	$00,$B2,$42,$FA
		.BYTE	$06,$3E,$02,$02
		.BYTE	$06,$3E,$42,$FA
		.BYTE	$F0,$A0,$42,$02
		.BYTE	$F0,$B0,$42,$FA
_sprA05_0E:
		.BYTE	$82
		.WORD	_sprA05_0E_B
		.WORD	_sprA05_0C_A
_sprA05_0E_B
		.BYTE	$04
		.BYTE	$00,$82,$02,$FA
		.BYTE	$00,$82,$42,$02
		.BYTE	$F0,$80,$02,$FA
		.BYTE	$F0,$80,$42,$02
_sprA05_0F:
		.BYTE	$06
		.BYTE	$00,$A2,$02,$FA
		.BYTE	$00,$B2,$02,$02
		.BYTE	$06,$3E,$02,$02
		.BYTE	$06,$3E,$42,$FA
		.BYTE	$F0,$A0,$02,$FA
		.BYTE	$F0,$B0,$02,$02
_sprA05_10:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F8
		.BYTE	$F0,$96,$02,$F8
		.BYTE	$F0,$86,$02,$F0
_sprA05_11:
		.BYTE	$02
		.BYTE	$F8,$B6,$02,$F8
		.BYTE	$F8,$A6,$02,$F0
_sprA05_12:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$00
		.BYTE	$F0,$96,$42,$00
		.BYTE	$F0,$86,$42,$08
_sprA05_13:
		.BYTE	$02
		.BYTE	$F8,$A6,$42,$08
		.BYTE	$F8,$B6,$42,$00
_sprA05_14:
		.BYTE	$04
		.BYTE	$00,$F9,$00,$02
		.BYTE	$00,$F9,$00,$F7
		.BYTE	$F0,$E9,$03,$F8
		.BYTE	$F0,$E9,$43,$00
_sprA05_15:
		.BYTE	$02
		.BYTE	$F8,$CF,$03,$F8
		.BYTE	$F8,$DF,$03,$00
_sprA05_16:
		.BYTE	$02
		.BYTE	$F8,$DF,$43,$F8
		.BYTE	$F8,$CF,$43,$00
_sprA05_17:
		.BYTE	$02
		.BYTE	$F8,$CF,$C3,$00
		.BYTE	$F8,$DF,$C3,$F8
_sprA05_18:
		.BYTE	$02
		.BYTE	$F8,$DF,$83,$00
		.BYTE	$F8,$CF,$83,$F8
_sprA05_19:
		.BYTE	$02
		.BYTE	$F8,$E1,$00,$F8
		.BYTE	$F8,$F1,$00,$00
_sprA05_1A:
		.BYTE	$02
		.BYTE	$F8,$F1,$40,$F8
		.BYTE	$F8,$E1,$40,$00
_sprA05_1B:
		.BYTE	$02
		.BYTE	$F8,$E1,$C0,$00
		.BYTE	$F8,$F1,$C0,$F8
_sprA05_1C:
		.BYTE	$02
		.BYTE	$F8,$F1,$80,$00
		.BYTE	$F8,$E1,$80,$F8
_sprA05_1D:
		.BYTE	$02
		.BYTE	$F8,$E7,$03,$F8
		.BYTE	$F8,$F7,$03,$00
_sprA05_1E:
		.BYTE	$02
		.BYTE	$F8,$F7,$43,$F8
		.BYTE	$F8,$E7,$43,$00
_sprA05_1F:
		.BYTE	$02
		.BYTE	$F8,$E7,$C3,$00
		.BYTE	$F8,$F7,$C3,$F8
_sprA05_20:
		.BYTE	$02
		.BYTE	$F8,$F7,$83,$00
		.BYTE	$F8,$E7,$83,$F8
_sprA05_21:
		.BYTE	$02
		.BYTE	$F8,$CB,$03,$F8
		.BYTE	$F8,$DB,$03,$00
_sprA05_22:
		.BYTE	$02
		.BYTE	$F8,$DB,$43,$F8
		.BYTE	$F8,$CB,$43,$00
_sprA05_23:
		.BYTE	$02
		.BYTE	$F8,$CB,$C3,$00
		.BYTE	$F8,$DB,$C3,$F8
_sprA05_24:
		.BYTE	$02
		.BYTE	$F8,$DB,$83,$00
		.BYTE	$F8,$CB,$83,$F8
_sprA05_25:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_25_B
_sprA05_25_A:
		.BYTE	$02
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$F8,$5B,$43,$00
_sprA05_25_B:
		.BYTE	$02
		.BYTE	$F9,$4B,$00,$F9
		.BYTE	$F9,$4B,$40,$01
_sprA05_26:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_26_B
_sprA05_26_B:
		.BYTE	$02
		.BYTE	$FA,$4B,$00,$F9
		.BYTE	$FA,$4B,$40,$01
_sprA05_27:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_27_B
_sprA05_27_B:
		.BYTE	$02
		.BYTE	$FC,$4B,$00,$F9
		.BYTE	$FC,$4B,$40,$01
_sprA05_28:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_28_B
_sprA05_28_B:
		.BYTE	$02
		.BYTE	$FE,$4B,$00,$F9
		.BYTE	$FE,$4B,$40,$01
_sprA05_29:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_29_B
_sprA05_29_B:
		.BYTE	$02
		.BYTE	$01,$4B,$00,$F9
		.BYTE	$01,$4B,$40,$01
_sprA05_2A:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_2A_B
_sprA05_2A_B:
		.BYTE	$02
		.BYTE	$05,$4B,$00,$F9
		.BYTE	$05,$4B,$40,$01
_sprA05_2B:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_2B_B
_sprA05_2B_B:
		.BYTE	$02
		.BYTE	$0B,$4B,$00,$F9
		.BYTE	$0B,$4B,$40,$01
_sprA05_2C:
		.BYTE	$82
		.WORD	_sprA05_25_A
		.WORD	_sprA05_2C_B
_sprA05_2C_B:
		.BYTE	$02
		.BYTE	$11,$4B,$00,$F9
		.BYTE	$11,$4B,$40,$01
_sprA05_2D:
		.BYTE	$08
		.BYTE	$EA,$BA,$03,$F8
		.BYTE	$EA,$BA,$43,$00
		.BYTE	$F6,$BC,$00,$F8
		.BYTE	$F6,$BC,$40,$00
		.BYTE	$FA,$A4,$03,$F8
		.BYTE	$FA,$A4,$43,$00
		.BYTE	$02,$3E,$03,$00
		.BYTE	$02,$3E,$43,$F8
_sprA05_2E:
		.BYTE	$08
		.BYTE	$EB,$BA,$03,$F8
		.BYTE	$EB,$BA,$43,$00
		.BYTE	$F9,$BC,$00,$F8
		.BYTE	$F9,$BC,$40,$00
		.BYTE	$FB,$A4,$03,$F8
		.BYTE	$FB,$A4,$43,$00
		.BYTE	$03,$3E,$03,$00
		.BYTE	$03,$3E,$43,$F8
_sprA05_2F:
		.BYTE	$08
		.BYTE	$EA,$BA,$03,$FA
		.BYTE	$EA,$BA,$43,$02
		.BYTE	$F6,$BC,$00,$FA
		.BYTE	$F6,$BC,$40,$02
		.BYTE	$FA,$A4,$03,$FA
		.BYTE	$FA,$A4,$43,$02
		.BYTE	$02,$3E,$03,$02
		.BYTE	$02,$3E,$43,$FA
_sprA05_30:
		.BYTE	$03
		.BYTE	$00,$C6,$03,$F8
		.BYTE	$F0,$88,$03,$F3
		.BYTE	$F0,$98,$03,$FB
_sprA05_31:
		.BYTE	$02
		.BYTE	$F8,$AE,$03,$F0
		.BYTE	$F8,$BE,$03,$F8
_sprA05_32:
		.BYTE	$03
		.BYTE	$00,$C6,$43,$00
		.BYTE	$F0,$88,$43,$05
		.BYTE	$F0,$98,$43,$FD
_sprA05_33:
		.BYTE	$02
		.BYTE	$F8,$AE,$43,$08
		.BYTE	$F8,$BE,$43,$00
_sprA05_34:
		.BYTE	$82
		.WORD	_sprA05_34_A
		.WORD	_sprA05_34_B
		.WORD	_sprA05_34_C
_sprA05_34_A:
		.BYTE	$04
		.BYTE	$02,$AA,$03,$F8
		.BYTE	$02,$AA,$43,$00
		.BYTE	$F2,$A8,$03,$F8
		.BYTE	$F2,$B8,$03,$00
_sprA05_34_C:
		.BYTE	$02
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
_sprA05_34_B:
		.BYTE	$01
		.BYTE	$F0,$E1,$42,$F0
_sprA05_35:
		.BYTE	$83
		.WORD	_sprA05_35_A
		.WORD	_sprA05_35_B
		.WORD	_sprA05_34_C
_sprA05_35_A:
		.BYTE	$04
		.BYTE	$02,$86,$43,$00
		.BYTE	$02,$96,$43,$F8
		.BYTE	$F2,$84,$43,$00
		.BYTE	$F2,$94,$43,$F8
_sprA05_35_B:
		.BYTE	$01
		.BYTE	$F1,$E1,$42,$F0
_sprA05_36:
		.BYTE	$83
		.WORD	_sprA05_36_A
		.WORD	_sprA05_36_B
		.WORD	_sprA05_34_C
_sprA05_36_A:
		.BYTE	$04
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$F2,$A0,$03,$F8
		.BYTE	$F2,$B0,$03,$00
_sprA05_36_B:
		.BYTE	$01
		.BYTE	$F1,$E1,$02,$08
_sprA05_37:
		.BYTE	$83
		.WORD	_sprA05_37_A
		.WORD	_sprA05_37_B
		.WORD	_sprA05_34_C
_sprA05_37_A:
		.BYTE	$04
		.BYTE	$02,$86,$03,$F8
		.BYTE	$02,$96,$03,$00
		.BYTE	$F2,$84,$03,$F8
		.BYTE	$F2,$94,$03,$00
_sprA05_37_B
		.BYTE	$01
		.BYTE	$F1,$E1,$02,$08
_sprA05_38:
		.BYTE	$83
		.WORD	_sprA05_38_A
		.WORD	_sprA05_38_B
		.WORD	_sprA05_34_C
_sprA05_38_A:
		.BYTE	$04
		.BYTE	$02,$AA,$03,$F8
		.BYTE	$02,$AA,$43,$00
		.BYTE	$F2,$A6,$03,$F8
		.BYTE	$F2,$B6,$03,$00
_sprA05_38_B:
		.BYTE	$01
		.BYTE	$EC,$E1,$42,$F1
_sprA05_39:
		.BYTE	$83
		.WORD	_sprA05_39_A
		.WORD	_sprA05_39_B
		.WORD	_sprA05_34_C
_sprA05_39_A:
		.BYTE	$04
		.BYTE	$02,$86,$43,$00
		.BYTE	$02,$96,$43,$F8
		.BYTE	$F2,$88,$43,$00
		.BYTE	$F2,$98,$43,$F8
_sprA05_39_B:
		.BYTE	$01
		.BYTE	$EA,$E1,$42,$F1
_sprA05_3A:
		.BYTE	$83
		.WORD	_sprA05_3A_A
		.WORD	_sprA05_3A_B
		.WORD	_sprA05_34_C
_sprA05_3A_A:
		.BYTE	$04
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$F2,$A2,$03,$F8
		.BYTE	$F2,$B2,$03,$00
_sprA05_3A_B:
		.BYTE	$01
		.BYTE	$E9,$E1,$02,$03
_sprA05_3B:
		.BYTE	$83
		.WORD	_sprA05_3B_A
		.WORD	_sprA05_3B_B
		.WORD	_sprA05_34_C
_sprA05_3B_A:
		.BYTE	$04
		.BYTE	$02,$86,$03,$F8
		.BYTE	$02,$96,$03,$00
		.BYTE	$F2,$88,$03,$F8
		.BYTE	$F2,$98,$03,$00
_sprA05_3B_B:
		.BYTE	$01
		.BYTE	$EA,$E1,$02,$07
_sprA05_3C:
		.BYTE	$83
		.WORD	_sprA05_3C_A
		.WORD	_sprA05_3C_B
		.WORD	_sprA05_34_C
_sprA05_3C_A:
		.BYTE	$04
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$F2,$A6,$03,$F8
		.BYTE	$F2,$B6,$03,$00
_sprA05_3C_B:
		.BYTE	$01
		.BYTE	$EC,$E1,$42,$F1
_sprA05_3D:
		.BYTE	$83
		.WORD	_sprA05_3D_A
		.WORD	_sprA05_3D_B
		.WORD	_sprA05_34_C
_sprA05_3D_A:
		.BYTE	$04
		.BYTE	$02,$8A,$43,$00
		.BYTE	$02,$9A,$43,$F8
		.BYTE	$F2,$88,$43,$00
		.BYTE	$F2,$98,$43,$F8
_sprA05_3D_B:
		.BYTE	$01
		.BYTE	$EA,$E1,$42,$F1
_sprA05_3E:
		.BYTE	$83
		.WORD	_sprA05_3E_A
		.WORD	_sprA05_3E_B
		.WORD	_sprA05_34_C
_sprA05_3E_A:
		.BYTE	$04
		.BYTE	$02,$B4,$03,$F8
		.BYTE	$02,$B4,$43,$00
		.BYTE	$F2,$A2,$03,$F8
		.BYTE	$F2,$B2,$03,$00
_sprA05_3E_B:
		.BYTE	$01
		.BYTE	$E9,$E1,$02,$03
_sprA05_3F:
		.BYTE	$83
		.WORD	_sprA05_3F_A
		.WORD	_sprA05_3F_B
		.WORD	_sprA05_34_C
_sprA05_3F_A:
		.BYTE	$04
		.BYTE	$02,$8A,$03,$F8
		.BYTE	$02,$9A,$03,$00
		.BYTE	$F2,$88,$03,$F8
		.BYTE	$F2,$98,$03,$00
_sprA05_3F_B:
		.BYTE	$01
		.BYTE	$EA,$E1,$02,$07
_sprA05_40:
		.BYTE	$82
		.WORD	_sprA05_40_A
		.WORD	_sprA05_40_B
_sprA05_40_A:
		.BYTE	$06
		.BYTE	$02,$A4,$03,$FA
		.BYTE	$02,$A4,$43,$02
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$F2,$A6,$03,$FA
		.BYTE	$F2,$B6,$03,$02
_sprA05_40_B:
		.BYTE	$01
		.BYTE	$EC,$E1,$42,$F3
_sprA05_41:
		.BYTE	$82
		.WORD	_sprA05_41_A
		.WORD	_sprA05_41_B
_sprA05_41_A:
		.BYTE	$06
		.BYTE	$02,$8A,$43,$02
		.BYTE	$02,$9A,$43,$FA
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$F2,$88,$43,$02
		.BYTE	$F2,$98,$43,$FA
_sprA05_41_B:
		.BYTE	$01
		.BYTE	$EA,$E1,$42,$F3
_sprA05_42:
		.BYTE	$82
		.WORD	_sprA05_42_A
		.WORD	_sprA05_42_B
_sprA05_42_A:
		.BYTE	$06
		.BYTE	$02,$B4,$03,$FA
		.BYTE	$02,$B4,$43,$02
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$F2,$A2,$03,$FA
		.BYTE	$F2,$B2,$03,$02
_sprA05_42_B:
		.BYTE	$01
		.BYTE	$E9,$E1,$02,$05
_sprA05_43:
		.BYTE	$82
		.WORD	_sprA05_43_A
		.WORD	_sprA05_43_B
_sprA05_43_A:
		.BYTE	$06
		.BYTE	$02,$8A,$03,$FA
		.BYTE	$02,$9A,$03,$02
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$F2,$88,$03,$FA
		.BYTE	$F2,$98,$03,$02
_sprA05_43_B:
		.BYTE	$01
		.BYTE	$EA,$E1,$02,$09
_sprA05_44:
		.BYTE	$82
		.WORD	_sprA05_34_A
		.WORD	_sprA05_44_B
_sprA05_44_B:
		.BYTE	$02
		.BYTE	$F0,$C3,$42,$F0
		.BYTE	$F0,$D3,$42,$E8
_sprA05_45:
		.BYTE	$82
		.WORD	_sprA05_35_A
		.WORD	_sprA05_45_B
_sprA05_45_B:
		.BYTE	$02
		.BYTE	$F1,$C3,$42,$F0
		.BYTE	$F1,$D3,$42,$E8
_sprA05_46:
		.BYTE	$82
		.WORD	_sprA05_36_A
		.WORD	_sprA05_46_B
_sprA05_46_B:
		.BYTE	$02
		.BYTE	$F1,$C3,$02,$08
		.BYTE	$F1,$D3,$02,$10
_sprA05_47:
		.BYTE	$82
		.WORD	_sprA05_37_A
		.WORD	_sprA05_47_B
_sprA05_47_B:
		.BYTE	$02
		.BYTE	$F1,$C3,$02,$08
		.BYTE	$F1,$D3,$02,$10
_sprA05_48:
		.BYTE	$82
		.WORD	_sprA05_38_A
		.WORD	_sprA05_48_B
_sprA05_48_B:
		.BYTE	$02
		.BYTE	$EC,$C3,$42,$F1
		.BYTE	$EC,$D3,$42,$E9
_sprA05_49:
		.BYTE	$82
		.WORD	_sprA05_39_A
		.WORD	_sprA05_49_B
_sprA05_49_B:
		.BYTE	$02
		.BYTE	$EA,$C3,$42,$F1
		.BYTE	$EA,$D3,$42,$E9
_sprA05_4A:
		.BYTE	$82
		.WORD	_sprA05_3A_A
		.WORD	_sprA05_4A_B
_sprA05_4A_B:
		.BYTE	$02
		.BYTE	$E9,$C3,$02,$03
		.BYTE	$E9,$D3,$02,$0B
_sprA05_4B:
		.BYTE	$82
		.WORD	_sprA05_3B_A
		.WORD	_sprA05_4B_B
_sprA05_4B_B:
		.BYTE	$02
		.BYTE	$EA,$C3,$02,$07
		.BYTE	$EA,$D3,$02,$0F
_sprA05_4C:
		.BYTE	$82
		.WORD	_sprA05_3C_A
		.WORD	_sprA05_4C_B
_sprA05_4C_B:
		.BYTE	$02
		.BYTE	$EC,$C3,$42,$F1
		.BYTE	$EC,$D3,$42,$E9
_sprA05_4D:
		.BYTE	$82
		.WORD	_sprA05_3D_A
		.WORD	_sprA05_4D_B
_sprA05_4D_B:
		.BYTE	$02
		.BYTE	$EA,$C3,$42,$F1
		.BYTE	$EA,$D3,$42,$E9
_sprA05_4E:
		.BYTE	$82
		.WORD	_sprA05_3E_A
		.WORD	_sprA05_4E_B
_sprA05_4E_B:
		.BYTE	$02
		.BYTE	$E9,$C3,$02,$03
		.BYTE	$E9,$D3,$02,$0B
_sprA05_4F:
		.BYTE	$82
		.WORD	_sprA05_3F_A
		.WORD	_sprA05_4F_B
_sprA05_4F_B:
		.BYTE	$02
		.BYTE	$EA,$C3,$02,$07
		.BYTE	$EA,$D3,$02,$0F
_sprA05_50:
		.BYTE	$82
		.WORD	_sprA05_40_A
		.WORD	_sprA05_50_B
_sprA05_50_B:
		.BYTE	$02
		.BYTE	$EC,$C3,$42,$F3
		.BYTE	$EC,$D3,$42,$EB
_sprA05_51:
		.BYTE	$82
		.WORD	_sprA05_41_A
		.WORD	_sprA05_51_B
_sprA05_51_B:
		.BYTE	$02
		.BYTE	$EA,$C3,$42,$F3
		.BYTE	$EA,$D3,$42,$EB
_sprA05_52:
		.BYTE	$82
		.WORD	_sprA05_42_A
		.WORD	_sprA05_52_B
_sprA05_52_B:
		.BYTE	$02
		.BYTE	$E9,$C3,$02,$05
		.BYTE	$E9,$D3,$02,$0D
_sprA05_53:
		.BYTE	$82
		.WORD	_sprA05_43_A
		.WORD	_sprA05_53_B
_sprA05_53_B:
		.BYTE	$02
		.BYTE	$EA,$C3,$02,$09
		.BYTE	$EA,$D3,$02,$11
_sprA05_56:
		.BYTE	$04
		.BYTE	$00,$82,$02,$F8
		.BYTE	$00,$82,$42,$00
		.BYTE	$F0,$80,$02,$F8
		.BYTE	$F0,$80,$42,$00
_sprA05_57:
		.BYTE	$04
		.BYTE	$F8,$90,$02,$F0
		.BYTE	$F8,$90,$42,$08
		.BYTE	$F8,$92,$02,$F8
		.BYTE	$F8,$92,$42,$00
_sprA05_58:
		.BYTE	$82
		.WORD	_sprA05_58_B
		.WORD	_sprA05_56
_sprA05_58_B:
		.BYTE	$02
		.BYTE	$F1,$9C,$03,$F8
		.BYTE	$F1,$9C,$43,$00
_sprA05_59:
		.BYTE	$82
		.WORD	_sprA05_59_B
		.WORD	_sprA05_57
_sprA05_59_B:
		.BYTE	$02
		.BYTE	$F2,$8E,$43,$01
		.BYTE	$F2,$9E,$43,$F9
_sprA05_5A:
		.BYTE	$82
		.WORD	_sprA05_5A_B
		.WORD	_sprA05_56
_sprA05_5A_B:
		.BYTE	$02
		.BYTE	$F3,$8C,$03,$F8
		.BYTE	$F3,$8C,$43,$00
_sprA05_5B:
		.BYTE	$82
		.WORD	_sprA05_5B_B
		.WORD	_sprA05_57
_sprA05_5B_B:
		.BYTE	$02
		.BYTE	$F2,$8E,$03,$F7
		.BYTE	$F2,$9E,$03,$FF
_sprA05_5C:
		.BYTE	$82
		.WORD	_sprA05_5C_A
		.WORD	_sprA05_5C_B
_sprA05_5C_A:
		.BYTE	$02
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
_sprA05_5C_B:
		.BYTE	$04
		.BYTE	$00,$A4,$03,$F8
		.BYTE	$00,$A4,$43,$00
		.BYTE	$F0,$A6,$03,$F8
		.BYTE	$F0,$B6,$03,$00
_sprA05_5D:
		.BYTE	$82
		.WORD	_sprA05_5C_A
		.WORD	_sprA05_5D_B
_sprA05_5D_B:
		.BYTE	$04
		.BYTE	$00,$8A,$43,$00
		.BYTE	$00,$9A,$43,$F8
		.BYTE	$F0,$88,$43,$00
		.BYTE	$F0,$98,$43,$F8
_sprA05_5E:
		.BYTE	$82
		.WORD	_sprA05_5C_A
		.WORD	_sprA05_5E_B
_sprA05_5E_B:
		.BYTE	$04
		.BYTE	$00,$B4,$03,$F8
		.BYTE	$00,$B4,$43,$00
		.BYTE	$F0,$A2,$03,$F8
		.BYTE	$F0,$B2,$03,$00
_sprA05_5F:
		.BYTE	$82
		.WORD	_sprA05_5C_A
		.WORD	_sprA05_5F_B
_sprA05_5F_B:
		.BYTE	$04
		.BYTE	$00,$8A,$03,$F8
		.BYTE	$00,$9A,$03,$00
		.BYTE	$F0,$88,$03,$F8
		.BYTE	$F0,$98,$03,$00
_sprA05_60:
		.BYTE	$82
		.WORD	_sprA05_60_A
		.WORD	_sprA05_60_B
_sprA05_60_A:
		.BYTE	$02
		.BYTE	$08,$3E,$03,$02
		.BYTE	$08,$3E,$43,$FA
_sprA05_60_B:
		.BYTE	$04
		.BYTE	$00,$A4,$03,$FA
		.BYTE	$00,$A4,$43,$02
		.BYTE	$F0,$A6,$03,$FA
		.BYTE	$F0,$B6,$03,$02
_sprA05_61:
		.BYTE	$82
		.WORD	_sprA05_60_A
		.WORD	_sprA05_61_B
_sprA05_61_B:
		.BYTE	$04
		.BYTE	$00,$8A,$43,$02
		.BYTE	$00,$9A,$43,$FA
		.BYTE	$F0,$88,$43,$02
		.BYTE	$F0,$98,$43,$FA
_sprA05_62:
		.BYTE	$82
		.WORD	_sprA05_60_A
		.WORD	_sprA05_62_B
_sprA05_62_B:
		.BYTE	$04
		.BYTE	$00,$B4,$03,$FA
		.BYTE	$00,$B4,$43,$02
		.BYTE	$F0,$A2,$03,$FA
		.BYTE	$F0,$B2,$03,$02
_sprA05_63:
		.BYTE	$82
		.WORD	_sprA05_60_A
		.WORD	_sprA05_63_B
_sprA05_63_B:
		.BYTE	$04
		.BYTE	$00,$8A,$03,$FA
		.BYTE	$00,$9A,$03,$02
		.BYTE	$F0,$88,$03,$FA
		.BYTE	$F0,$98,$03,$02
_sprA05_64:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$E8,$03,$F8
		.BYTE	$F6,$E8,$43,$00
_sprA05_65:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$F8,$03,$FA
		.BYTE	$F6,$F8,$43,$02
_sprA05_66:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$F8,$03,$F8
		.BYTE	$F6,$F8,$43,$00
_sprA05_67:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$EA,$03,$F8
		.BYTE	$F6,$EA,$43,$00
_sprA05_68:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$FA,$03,$FA
		.BYTE	$F6,$FA,$43,$02
_sprA05_69:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$FA,$03,$F8
		.BYTE	$F6,$FA,$43,$00
_sprA05_6A:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$EC,$03,$F8
		.BYTE	$F6,$EC,$43,$00
_sprA05_6B:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$FC,$03,$FA
		.BYTE	$F6,$FC,$43,$02
_sprA05_6C:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$FC,$03,$F8
		.BYTE	$F6,$FC,$43,$00
_sprA05_6D:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$CA,$03,$F8
		.BYTE	$F6,$CA,$43,$00
_sprA05_6E:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$DA,$03,$FA
		.BYTE	$F6,$DA,$43,$02
_sprA05_6F:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$DA,$03,$F8
		.BYTE	$F6,$DA,$43,$00
_sprA05_70:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$CC,$03,$F8
		.BYTE	$F6,$CC,$43,$00
_sprA05_71:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$DC,$03,$FA
		.BYTE	$F6,$DC,$43,$02
_sprA05_72:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$DC,$03,$F8
		.BYTE	$F6,$DC,$43,$00
_sprA05_73:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$CE,$03,$F8
		.BYTE	$F6,$CE,$43,$00
_sprA05_74:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$DE,$03,$FA
		.BYTE	$F6,$DE,$43,$02
_sprA05_75:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$DE,$03,$F8
		.BYTE	$F6,$DE,$43,$00
_sprA05_77:
		.BYTE	$02
		.BYTE	$F4,$DA,$03,$F0
		.BYTE	$F4,$FE,$03,$F8
_sprA05_79:
		.BYTE	$02
		.BYTE	$F4,$FE,$43,$00
		.BYTE	$F4,$DA,$43,$08
_sprA05_7A:
		.BYTE	$01
		.BYTE	$F8,$D8,$03,$FC
_sprA05_7B:
		.BYTE	$01
		.BYTE	$F8,$D8,$C3,$FC
_sprA05_7C:
		.BYTE	$02
		.BYTE	$F8,$98,$00,$00
		.BYTE	$F8,$88,$00,$F8
_sprA05_7D:
		.BYTE	$02
		.BYTE	$F8,$88,$80,$F8
		.BYTE	$F8,$98,$80,$00
_sprA05_7E:
		.BYTE	$02
		.BYTE	$F8,$98,$C0,$F8
		.BYTE	$F8,$88,$C0,$00
_sprA05_7F:
		.BYTE	$02
		.BYTE	$F8,$88,$40,$00
		.BYTE	$F8,$98,$40,$F8
_sprA05_80:
		.BYTE	$02
		.BYTE	$F8,$B8,$00,$00
		.BYTE	$F8,$A8,$00,$F8
_sprA05_81:
		.BYTE	$02
		.BYTE	$F8,$A8,$80,$F8
		.BYTE	$F8,$B8,$80,$00
_sprA05_82:
		.BYTE	$02
		.BYTE	$F8,$B8,$C0,$F8
		.BYTE	$F8,$A8,$C0,$00
_sprA05_83:
		.BYTE	$02
		.BYTE	$F8,$A8,$40,$00
		.BYTE	$F8,$B8,$40,$F8
_sprA05_84:
		.BYTE	$02
		.BYTE	$F8,$9E,$00,$00
		.BYTE	$F8,$8E,$00,$F8
_sprA05_85:
		.BYTE	$02
		.BYTE	$F8,$8E,$40,$00
		.BYTE	$F8,$9E,$40,$F8
_sprA05_86:
		.BYTE	$02
		.BYTE	$F8,$9E,$C0,$F8
		.BYTE	$F8,$8E,$C0,$00
_sprA05_87:
		.BYTE	$02
		.BYTE	$F8,$9E,$80,$00
		.BYTE	$F8,$8E,$80,$F8
_sprA05_88:
		.BYTE	$02
		.BYTE	$F8,$9A,$00,$00
		.BYTE	$F8,$8A,$00,$F8
_sprA05_89:
		.BYTE	$02
		.BYTE	$F8,$8A,$40,$00
		.BYTE	$F8,$9A,$40,$F8
_sprA05_8A:
		.BYTE	$02
		.BYTE	$F8,$9A,$C0,$F8
		.BYTE	$F8,$8A,$C0,$00
_sprA05_8B:
		.BYTE	$02
		.BYTE	$F8,$8A,$80,$F8
		.BYTE	$F8,$9A,$80,$00
_sprA05_8F:
		.BYTE	$02
		.BYTE	$F8,$BA,$00,$00
		.BYTE	$F8,$AA,$00,$F8
_sprA05_93:
		.BYTE	$02
		.BYTE	$F8,$9C,$00,$00
		.BYTE	$F8,$8C,$00,$F8
_sprA05_97:
		.BYTE	$02
		.BYTE	$F8,$BC,$00,$00
		.BYTE	$F8,$AC,$00,$F8

_spr_libA06:
		.WORD	_sprA08_00
		.WORD	_sprA08_01
		.WORD	_sprA08_02
		.WORD	_sprA08_03
		.WORD	_sprA06_04
		.WORD	_sprA06_05
		.WORD	_sprA06_06
		.WORD	_sprA06_07
		.WORD	_sprA06_08
		.WORD	_sprA06_09
		.WORD	_sprA06_0A
		.WORD	_sprA06_0B
		.WORD	_sprA06_0C
		.WORD	_sprA06_0D
		.WORD	_sprA06_0E
		.WORD	_sprA06_0F
		.WORD	_sprA06_10
		.WORD	_sprA06_11
		.WORD	_sprA06_12
		.WORD	_sprA06_13
		.WORD	_sprA06_14
		.WORD	_sprA06_15	; NOTE, animation of spear for elephant
		.WORD	_sprA06_16	; with dir DOWN, never used. there are
		.WORD	_sprA06_17	; no such enemies in this game
		.WORD	_sprA06_18	;
		.WORD	_sprA06_19	; all unused
		.WORD	_sprA06_1A
		.WORD	_sprA06_1B
		.WORD	_sprA06_1C
		.WORD	_sprA06_1D
		.WORD	_sprA06_1E
		.WORD	_sprA06_1F
		.WORD	_sprA06_20
		.WORD	_sprA06_21
		.WORD	_sprA06_22
		.WORD	_sprA06_23
; NOTE: odd sprite, dir DOWN with sword strike down, the sword tile
; put a lot way lower than even the shadow of the ninja (lol)
; maybe this was done by purpose (to not to overlap a lot of sprites)
; or maybe just bug..
		.WORD	_sprA06_24
		.WORD	_sprA06_25
		.WORD	_sprA06_26
		.WORD	_sprA06_27
		.WORD	_sprA06_28
		.WORD	_sprA06_29
		.WORD	_sprA06_2A
		.WORD	_sprA06_2B
		.WORD	_sprA06_2C
		.WORD	_sprA06_2D
		.WORD	_sprA06_2E
		.WORD	_sprA06_2F
		.WORD	_sprA06_30
		.WORD	_sprA06_31
		.WORD	_sprA06_32
		.WORD	_sprA06_33
		.WORD	_sprA06_34
		.WORD	_sprA06_35
		.WORD	_sprA06_36
		.WORD	_sprA06_37
		.WORD	_sprA06_38
		.WORD	_sprA06_39
		.WORD	_sprA06_3A
		.WORD	_sprA06_3B
		.WORD	_sprA06_3C
		.WORD	_sprA06_3D
		.WORD	_sprA06_3E
		.WORD	_sprA06_3F
		.WORD	_sprA06_40
		.WORD	_sprA06_41
		.WORD	_sprA06_42
		.WORD	_sprA06_43
		.WORD	_sprA06_44
		.WORD	_sprA06_45
		.WORD	_sprA06_46
		.WORD	_sprA06_47
		.WORD	_sprA06_48
		.WORD	_sprA06_49
		.WORD	_sprA06_4A
		.WORD	_sprA06_4B
		.WORD	_sprA06_4C
		.WORD	_sprA06_4D
		.WORD	_sprA06_4E
		.WORD	_sprA06_51
		.WORD	_sprA06_50
		.WORD	_sprA06_51
		.WORD	_sprA06_52
		.WORD	_sprA06_53
		.WORD	_sprA06_54
		.WORD	_sprA06_55
		.WORD	_sprA06_56
		.WORD	_sprA06_57
		.WORD	_sprA06_58
		.WORD	_sprA06_59
		.WORD	_sprA06_5A
		.WORD	_sprA06_5B
		.WORD	_sprA06_5C
		.WORD	_sprA06_5D
		.WORD	_sprA06_5E
		.WORD	_sprA06_5F
		.WORD	_sprA06_60
		.WORD	_sprA06_61	; NOTE: objects tile a little bit odd, test
		.WORD	_sprA06_62
		.WORD	_sprA06_63
		.WORD	_sprA06_64
		.WORD	_sprA06_65
		.WORD	_sprA06_66
		.WORD	_sprA06_67
		.WORD	_sprA06_68
		.WORD	_sprA06_69
		.WORD	_sprA06_6A
		.WORD	_sprA06_6B
		.WORD	_sprA06_6C
		.WORD	_sprA06_6D
; NOTE: the second type of sprites here used as an optimization for
; very large objects with large parts being the same, so they decide
; to split such sprites and keep only one copy of common data and
; then just using pointer links to them.
; however, most of the time such method (if used) draws the same single
; sprites! in this game they used such optimization only once! rest of
; objects even if using this sprites type, doesn't have it split, only
; single data chunks...
;
; NOTE: as noted before, one of the reasons is it seems they made a little
; bug in sprite engine, so they has to fix sprites to avoid this. probably
; this set of sprites added later in the dev process and not finished at
; all... also one of the reasons may be speed issues with split chunks
; single chunks works faster after all, and there is an issue with sprite
; glitches because of that in the released version.
;
_spr_libB06:
		.WORD	_sprB06_C0
		.WORD	_sprB06_C1
		.WORD	_sprB06_C2
		.WORD	_sprB06_C3
		.WORD	_sprB06_C4
		.WORD	_sprB06_C5
		.WORD	_sprB06_C6
		.WORD	_sprB06_C7
		.WORD	_sprB06_C8
		.WORD	_sprB06_C9
		.WORD	_sprB06_CA
		.WORD	_sprB06_CB
		.WORD	_sprB06_CC
		.WORD	_sprB06_CD
		.WORD	_sprB06_CE
		.WORD	_sprB06_CF
		.WORD	_sprB06_D0
		.WORD	_sprB06_D1
		.WORD	_sprB06_D2
		.WORD	_sprB06_D3
		.WORD	_sprB06_D4
		.WORD	_sprB06_D5
		.WORD	_sprB06_D6
		.WORD	_sprB06_D7
; NOTE: there are no object of such type set the DOWN direction
; so there is no usage for corresponding sprites...
;
		.WORD	_sprB06_D8
		.WORD	_sprB06_D9
		.WORD	_sprB06_DA	; unused
		.WORD	_sprB06_DB
		.WORD	_sprB06_DC
		.WORD	_sprB06_DD
		.WORD	_sprB06_DE	; unused
		.WORD	_sprB06_DF
		.WORD	_sprB06_E0
		.WORD	_sprB06_E1
		.WORD	_sprB06_E2	; unused
		.WORD	_sprB06_E3
		.WORD	_sprB06_E4
		.WORD	_sprB06_E5
		.WORD	_sprB06_E6
		.WORD	_sprB06_E7
		.WORD	_sprB06_E8
		.WORD	_sprB06_E9
		.WORD	_sprB06_EA
		.WORD	_sprB06_EB

_sprA06_04:
		.BYTE	$04
		.BYTE	$EE,$84,$03,$F0
		.BYTE	$EE,$94,$03,$F8
		.BYTE	$FE,$8C,$03,$F0
		.BYTE	$FE,$8E,$03,$F8
_sprA06_05:
		.BYTE	$04
		.BYTE	$F6,$84,$03,$F0
		.BYTE	$F6,$94,$03,$F8
		.BYTE	$FE,$6E,$03,$F0
		.BYTE	$FE,$7E,$03,$F8
_sprA06_06:
		.BYTE	$04
		.BYTE	$EE,$84,$43,$08
		.BYTE	$EE,$94,$43,$00
		.BYTE	$FE,$8C,$43,$08
		.BYTE	$FE,$8E,$43,$00
_sprA06_07:
		.BYTE	$04
		.BYTE	$F6,$84,$43,$08
		.BYTE	$F6,$94,$43,$00
		.BYTE	$FE,$6E,$43,$08
		.BYTE	$FE,$7E,$43,$00
_sprA06_08:
		.BYTE	$04
		.BYTE	$EE,$8C,$03,$F3
		.BYTE	$EE,$8C,$43,$FB
		.BYTE	$FE,$A0,$03,$F3
		.BYTE	$FE,$B0,$03,$FB
_sprA06_09:
		.BYTE	$02
		.BYTE	$FD,$80,$03,$F2
		.BYTE	$FD,$90,$03,$FA
_sprA06_0A:
		.BYTE	$04
		.BYTE	$EE,$8C,$03,$FE
		.BYTE	$EE,$8C,$43,$06
		.BYTE	$FE,$A0,$43,$06
		.BYTE	$FE,$B0,$43,$FE
_sprA06_0B:
		.BYTE	$02
		.BYTE	$FD,$80,$43,$07
		.BYTE	$FD,$90,$43,$FF
_sprA06_0C:
		.BYTE	$01
		.BYTE	$F8,$B8,$83,$FC
_sprA06_0D:
		.BYTE	$02
		.BYTE	$00,$8E,$83,$FC
		.BYTE	$F8,$B8,$83,$FC
_sprA06_0E:
		.BYTE	$02
		.BYTE	$08,$8E,$83,$FC
		.BYTE	$F8,$B8,$83,$FC
_sprA06_0F:
		.BYTE	$03
		.BYTE	$08,$8E,$83,$FC
		.BYTE	$10,$8E,$03,$FC
		.BYTE	$F8,$B8,$83,$FC
_sprA06_10:
		.BYTE	$03
		.BYTE	$08,$8E,$83,$FC
		.BYTE	$18,$8E,$03,$FC
		.BYTE	$F8,$B8,$83,$FC
_sprA06_11:
		.BYTE	$02
		.BYTE	$F5,$84,$43,$00
		.BYTE	$F5,$94,$43,$F8
_sprA06_12:
		.BYTE	$03
		.BYTE	$F5,$84,$43,$00
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$A4,$43,$F0
_sprA06_13:
		.BYTE	$04
		.BYTE	$F5,$84,$43,$00
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$A4,$43,$E8
		.BYTE	$F5,$A4,$43,$F0
_sprA06_14:
		.BYTE	$05
		.BYTE	$F5,$84,$43,$00
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$A4,$43,$E0
		.BYTE	$F5,$A4,$43,$E8
		.BYTE	$F5,$A4,$43,$F0
_sprA06_15:
		.BYTE	$01
		.BYTE	$F8,$B8,$03,$FC
_sprA06_16:
		.BYTE	$02
		.BYTE	$F0,$8E,$03,$FC
		.BYTE	$F8,$B8,$03,$FC
_sprA06_17:
		.BYTE	$02
		.BYTE	$E8,$8E,$03,$FC
		.BYTE	$F8,$B8,$03,$FC
_sprA06_18:
		.BYTE	$03
		.BYTE	$E1,$8E,$03,$FC
		.BYTE	$E8,$8E,$03,$FC
		.BYTE	$F8,$B8,$03,$FC
_sprA06_19:
		.BYTE	$03
		.BYTE	$D8,$8E,$03,$FC
		.BYTE	$E8,$8E,$03,$FC
		.BYTE	$F8,$B8,$03,$FC
_sprA06_1A:
		.BYTE	$02
		.BYTE	$F5,$84,$03,$F8
		.BYTE	$F5,$94,$03,$00
_sprA06_1B:
		.BYTE	$03
		.BYTE	$F5,$84,$03,$F8
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$A4,$03,$08
_sprA06_1C:
		.BYTE	$04
		.BYTE	$F5,$84,$03,$F8
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$A4,$03,$08
		.BYTE	$F5,$A4,$03,$10
_sprA06_1D:
		.BYTE	$05
		.BYTE	$F5,$84,$03,$F8
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$A4,$03,$08
		.BYTE	$F5,$A4,$03,$10
		.BYTE	$F5,$A4,$03,$18
_sprA06_1E:
		.BYTE	$04
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$E8,$00,$F8
		.BYTE	$F1,$F8,$00,$00
_sprA06_1F:
		.BYTE	$06
		.BYTE	$00,$C6,$40,$00
		.BYTE	$00,$D6,$40,$F8
		.BYTE	$F1,$E4,$40,$00
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F2,$C8,$40,$09
		.BYTE	$F2,$D8,$40,$01
_sprA06_20:
		.BYTE	$05
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$E8,$FA,$80,$FC
		.BYTE	$F1,$C4,$00,$F8
		.BYTE	$F1,$D4,$00,$00
_sprA06_21:
		.BYTE	$06
		.BYTE	$00,$C6,$00,$F8
		.BYTE	$00,$D6,$00,$00
		.BYTE	$F1,$E4,$00,$F8
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F2,$C8,$00,$EF
		.BYTE	$F2,$D8,$00,$F7
_sprA06_22:
		.BYTE	$05
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$E8,$FA,$80,$FE
		.BYTE	$F0,$E8,$00,$F8
		.BYTE	$F0,$F8,$00,$00
_sprA06_23:
		.BYTE	$05
		.BYTE	$00,$E6,$40,$00
		.BYTE	$00,$F6,$40,$F8
		.BYTE	$EC,$FA,$C0,$01
		.BYTE	$F0,$E4,$40,$00
		.BYTE	$F0,$F4,$40,$F8
_sprA06_24:
		.BYTE	$05
		.BYTE	$00,$FA,$00,$FC		; FIX to
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
;		.BYTE	$0D,$FA,$00,$FC		; BUG? check if this is correct
		.BYTE	$F0,$C4,$00,$F8
		.BYTE	$F0,$D4,$00,$00
_sprA06_25:
		.BYTE	$05
		.BYTE	$00,$E6,$00,$F8
		.BYTE	$00,$F6,$00,$00
		.BYTE	$EC,$FA,$80,$F7
		.BYTE	$F0,$E4,$00,$F8
		.BYTE	$F0,$F4,$00,$00
_sprA06_26:
		.BYTE	$04
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$E8,$00,$F8
		.BYTE	$F1,$F8,$00,$00
_sprA06_27:
		.BYTE	$06
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$E4,$40,$00
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F2,$C8,$40,$09
		.BYTE	$F2,$D8,$40,$01
_sprA06_28:
		.BYTE	$05
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$E8,$FA,$80,$FC
		.BYTE	$F1,$C4,$00,$F8
		.BYTE	$F1,$D4,$00,$00
_sprA06_29:
		.BYTE	$06
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$E4,$00,$F8
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F2,$C8,$00,$EF
		.BYTE	$F2,$D8,$00,$F7
_sprA06_2A:
		.BYTE	$04
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$C0,$00,$F8
		.BYTE	$F0,$D0,$00,$00
_sprA06_2B:
		.BYTE	$04
		.BYTE	$00,$E2,$40,$00
		.BYTE	$00,$F2,$40,$F8
		.BYTE	$F0,$E4,$40,$00
		.BYTE	$F0,$F4,$40,$F8
_sprA06_2C:
		.BYTE	$04
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$E0,$00,$F8
		.BYTE	$F0,$F0,$00,$00
_sprA06_2D:
		.BYTE	$04
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$E4,$00,$F8
		.BYTE	$F0,$F4,$00,$00
_sprA06_2E:
		.BYTE	$04
		.BYTE	$00,$E2,$00,$FA
		.BYTE	$00,$F2,$00,$02
		.BYTE	$F0,$C0,$00,$FA
		.BYTE	$F0,$D0,$00,$02
_sprA06_2F:
		.BYTE	$04
		.BYTE	$00,$E2,$40,$02
		.BYTE	$00,$F2,$40,$FA
		.BYTE	$F0,$E4,$40,$02
		.BYTE	$F0,$F4,$40,$FA
_sprA06_30:
		.BYTE	$04
		.BYTE	$00,$E2,$00,$FA
		.BYTE	$00,$F2,$00,$02
		.BYTE	$F0,$E0,$00,$FA
		.BYTE	$F0,$F0,$00,$02
_sprA06_31:
		.BYTE	$04
		.BYTE	$00,$E2,$00,$FA
		.BYTE	$00,$F2,$00,$02
		.BYTE	$F0,$E4,$00,$FA
		.BYTE	$F0,$F4,$00,$02
_sprA06_32:
		.BYTE	$04
		.BYTE	$07,$EC,$00,$F2
		.BYTE	$07,$FC,$00,$FA
		.BYTE	$F7,$E4,$00,$F2
		.BYTE	$F7,$F4,$00,$FA
_sprA06_33:
		.BYTE	$02
		.BYTE	$FF,$CC,$00,$F2
		.BYTE	$FF,$DC,$00,$FA
_sprA06_34:
		.BYTE	$04
		.BYTE	$08,$EC,$40,$07
		.BYTE	$08,$FC,$40,$FF
		.BYTE	$F8,$E4,$40,$07
		.BYTE	$F8,$F4,$40,$FF
_sprA06_35:
		.BYTE	$02
		.BYTE	$FF,$CC,$40,$07
		.BYTE	$FF,$DC,$40,$FF
_sprA06_36:
		.BYTE	$05
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$EE,$EA,$00,$FC
		.BYTE	$F1,$C0,$00,$F8
		.BYTE	$F1,$F8,$00,$00
_sprA06_37:
		.BYTE	$05
		.BYTE	$00,$C6,$40,$00
		.BYTE	$00,$D6,$40,$F8
		.BYTE	$F1,$E4,$40,$00
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F7,$EA,$00,$FD
_sprA06_38:
		.BYTE	$05
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$D4,$00,$00
		.BYTE	$F1,$E0,$00,$F8
		.BYTE	$F4,$DA,$80,$FC
_sprA06_39:
		.BYTE	$05
		.BYTE	$00,$C6,$00,$F8
		.BYTE	$00,$D6,$00,$00
		.BYTE	$F1,$E4,$00,$F8
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F7,$EA,$40,$FB
_sprA06_3A:
		.BYTE	$05
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$E9,$EA,$40,$FF
		.BYTE	$F0,$C0,$00,$F8
		.BYTE	$F0,$F8,$00,$00
_sprA06_3B:
		.BYTE	$05
		.BYTE	$00,$E6,$40,$00
		.BYTE	$00,$F6,$40,$F8
		.BYTE	$F0,$E4,$40,$00
		.BYTE	$F0,$F4,$40,$F8
		.BYTE	$F5,$DA,$40,$02
_sprA06_3C:
		.BYTE	$05
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$D4,$00,$00
		.BYTE	$F0,$E0,$00,$F8
		.BYTE	$F5,$EA,$80,$01
_sprA06_3D:
		.BYTE	$05
		.BYTE	$00,$E6,$00,$F8
		.BYTE	$00,$F6,$00,$00
		.BYTE	$F0,$E4,$00,$F8
		.BYTE	$F0,$F4,$00,$00
		.BYTE	$F5,$DA,$00,$F6
_sprA06_3E:
		.BYTE	$05
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$EE,$EA,$00,$FC
		.BYTE	$F1,$C0,$00,$F8
		.BYTE	$F1,$F8,$00,$00
_sprA06_3F:
		.BYTE	$05
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$E4,$40,$00
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F7,$EA,$40,$FD
_sprA06_40:
		.BYTE	$05
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$D4,$00,$00
		.BYTE	$F1,$E0,$00,$F8
		.BYTE	$F4,$DA,$80,$FC
_sprA06_41:
		.BYTE	$05
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$E4,$00,$F8
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F7,$EA,$00,$FB
_sprA06_42:
		.BYTE	$01
		.BYTE	$FD,$CA,$00,$FD
_sprA06_43:
		.BYTE	$01
		.BYTE	$FD,$CA,$40,$FD
_sprA06_44:
		.BYTE	$01
		.BYTE	$F5,$CA,$C0,$FD
_sprA06_45:
		.BYTE	$01
		.BYTE	$F5,$CA,$80,$FD
_sprA06_46:
		.BYTE	$02
		.BYTE	$F8,$CE,$03,$02
		.BYTE	$F8,$BE,$03,$FA
_sprA06_47:
		.BYTE	$02
		.BYTE	$FF,$BE,$03,$F1
		.BYTE	$FF,$6E,$03,$F9
_sprA06_48:
		.BYTE	$01
		.BYTE	$FF,$FE,$03,$F9
_sprA06_49:
		.BYTE	$02
		.BYTE	$FF,$BE,$43,$08
		.BYTE	$FF,$6E,$43,$00
_sprA06_4A:
		.BYTE	$01
		.BYTE	$FF,$FE,$43,$00
_sprA06_4B:
		.BYTE	$02
		.BYTE	$F4,$E0,$03,$F8
		.BYTE	$F4,$E0,$43,$00
_sprA06_4C:
		.BYTE	$02
		.BYTE	$F4,$E2,$03,$F8
		.BYTE	$F4,$E2,$43,$00
_sprA06_4D:
		.BYTE	$02
		.BYTE	$F4,$E4,$03,$F8
		.BYTE	$F4,$E4,$43,$00
_sprA06_4E:
		.BYTE	$02
		.BYTE	$F4,$E0,$03,$FA
		.BYTE	$F4,$E0,$43,$02
_sprA06_50:
		.BYTE	$01
		.BYTE	$05,$CE,$03,$FA
_sprA06_51:
		.BYTE	$02
		.BYTE	$02,$E4,$83,$F8
		.BYTE	$02,$E4,$C3,$00
_sprA06_52:
		.BYTE	$01
		.BYTE	$05,$CE,$43,$FF
_sprA06_53:
		.BYTE	$02
		.BYTE	$F4,$F0,$03,$F8
		.BYTE	$F4,$F0,$43,$00
_sprA06_54:
		.BYTE	$04
		.BYTE	$04,$F4,$03,$F8
		.BYTE	$04,$F4,$43,$00
		.BYTE	$F4,$F2,$03,$F8
		.BYTE	$F4,$F2,$43,$00
_sprA06_55:
		.BYTE	$04
		.BYTE	$04,$E8,$03,$F8
		.BYTE	$04,$E8,$43,$00
		.BYTE	$F4,$E6,$03,$F8
		.BYTE	$F4,$E6,$43,$00
_sprA06_56:
		.BYTE	$04
		.BYTE	$04,$F8,$03,$F8
		.BYTE	$04,$F8,$43,$00
		.BYTE	$F4,$F6,$03,$F8
		.BYTE	$F4,$F6,$43,$00
_sprA06_57:
		.BYTE	$04
		.BYTE	$04,$F4,$03,$FA
		.BYTE	$04,$F4,$43,$02
		.BYTE	$F4,$F2,$03,$FA
		.BYTE	$F4,$F2,$43,$02
_sprA06_58:
		.BYTE	$04
		.BYTE	$05,$EA,$03,$F3
		.BYTE	$05,$FA,$03,$FB
		.BYTE	$F5,$F2,$03,$F3
		.BYTE	$F5,$F2,$43,$FB
_sprA06_59:
		.BYTE	$02
		.BYTE	$FE,$EC,$03,$F1
		.BYTE	$FE,$FC,$03,$F9
_sprA06_5A:
		.BYTE	$04
		.BYTE	$06,$EA,$43,$07
		.BYTE	$06,$FA,$43,$FF
		.BYTE	$F6,$F2,$03,$FF
		.BYTE	$F6,$F2,$43,$07
_sprA06_5B:
		.BYTE	$02
		.BYTE	$FD,$EC,$43,$09
		.BYTE	$FD,$FC,$43,$01
_sprA06_5C:
		.BYTE	$01
		.BYTE	$FC,$FE,$01,$FD
_sprA06_5D:
		.BYTE	$01
		.BYTE	$FC,$EE,$01,$FC
_sprA06_5E:
		.BYTE	$06
		.BYTE	$04,$C2,$03,$FC
		.BYTE	$04,$D2,$03,$04
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$F4,$D0,$03,$04
		.BYTE	$F4,$D0,$43,$F4
		.BYTE	$F4,$DE,$03,$FC
_sprA06_5F:
		.BYTE	$06
		.BYTE	$04,$CA,$03,$FC
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$DA,$03,$04
		.BYTE	$F4,$CC,$03,$F4
		.BYTE	$F4,$D8,$03,$04
		.BYTE	$F4,$DC,$03,$FC
_sprA06_60:
		.BYTE	$06
		.BYTE	$04,$D2,$03,$04
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$D6,$03,$FC
		.BYTE	$F4,$C4,$43,$04
		.BYTE	$F4,$C6,$43,$F4
		.BYTE	$F4,$D4,$43,$FC
_sprA06_61:
		.BYTE	$06
		.BYTE	$04,$CA,$43,$FC
		.BYTE	$04,$D2,$43,$00
		.BYTE	$04,$DA,$43,$F4
		.BYTE	$F4,$C8,$43,$FC
		.BYTE	$F4,$CC,$43,$04
		.BYTE	$F4,$D8,$43,$F4
_sprA06_62:
		.BYTE	$06
		.BYTE	$04,$C2,$03,$FC
		.BYTE	$04,$D2,$03,$04
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$F4,$C0,$03,$FC
		.BYTE	$F4,$D0,$03,$04
		.BYTE	$F4,$D0,$43,$F4
_sprA06_63:
		.BYTE	$06
		.BYTE	$04,$CA,$03,$FC
		.BYTE	$04,$D2,$03,$FB
		.BYTE	$04,$DA,$03,$04
		.BYTE	$F4,$C8,$03,$FC
		.BYTE	$F4,$CC,$03,$F4
		.BYTE	$F4,$D8,$03,$04
_sprA06_64:
		.BYTE	$06
		.BYTE	$04,$D2,$03,$04
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$D6,$03,$FC
		.BYTE	$F4,$C4,$03,$F4
		.BYTE	$F4,$C6,$03,$04
		.BYTE	$F4,$D4,$03,$FC
_sprA06_65:
		.BYTE	$06
		.BYTE	$04,$CA,$43,$FC
		.BYTE	$04,$D2,$03,$04
		.BYTE	$04,$DA,$43,$F4
		.BYTE	$F4,$CC,$43,$04
		.BYTE	$F4,$D8,$43,$F4
		.BYTE	$F4,$DC,$43,$FC
_sprA06_66:
		.BYTE	$06
		.BYTE	$04,$C2,$03,$FE
		.BYTE	$04,$D2,$03,$06
		.BYTE	$04,$D2,$43,$F6
		.BYTE	$F4,$C0,$03,$FE
		.BYTE	$F4,$D0,$03,$06
		.BYTE	$F4,$D0,$43,$F6
_sprA06_67:
		.BYTE	$04
		.BYTE	$07,$CE,$03,$FA
		.BYTE	$F7,$C0,$03,$FA
		.BYTE	$F7,$C6,$03,$02
		.BYTE	$F7,$C6,$43,$F2
_sprA06_68:
		.BYTE	$01
		.BYTE	$FE,$BE,$03,$FA
_sprA06_69:
		.BYTE	$04
		.BYTE	$07,$CE,$43,$00
		.BYTE	$F7,$C0,$43,$00
		.BYTE	$F7,$C6,$03,$08
		.BYTE	$F7,$C6,$43,$F8
_sprA06_6A:
		.BYTE	$01
		.BYTE	$FE,$BE,$43,$FF
_sprA06_6B:
		.BYTE	$02
		.BYTE	$F8,$C9,$01,$D8
		.BYTE	$F8,$C9,$01,$20
_sprA06_6C:
		.BYTE	$02
		.BYTE	$F8,$C7,$01,$D8
		.BYTE	$F8,$C7,$01,$20
_sprA06_6D:
		.BYTE	$02
		.BYTE	$00,$05,$00,$FC
		.BYTE	$F0,$03,$00,$FC
_sprB06_C0:
		.BYTE	$81
		.WORD	_sprB06_C0_A
_sprB06_C1:
		.BYTE	$81
		.WORD	_sprB06_C1_A
_sprB06_C2:
		.BYTE	$81
		.WORD	_sprB06_C2_A
_sprB06_C3:
		.BYTE	$81
		.WORD	_sprB06_C3_A
_sprB06_C4:
		.BYTE	$81
		.WORD	_sprB06_C4_A
_sprB06_C5:
		.BYTE	$81
		.WORD	_sprB06_C5_A
_sprB06_C6:
		.BYTE	$81
		.WORD	_sprB06_C6_A
_sprB06_C7:
		.BYTE	$81
		.WORD	_sprB06_C7_A
_sprB06_C8:
		.BYTE	$81
		.WORD	_sprB06_C8_A
_sprB06_C9:
		.BYTE	$81
		.WORD	_sprB06_C9_A
_sprB06_CA:
		.BYTE	$81
		.WORD	_sprB06_CA_A
_sprB06_CB:
		.BYTE	$81
		.WORD	_sprB06_CB_A
_sprB06_CC:
		.BYTE	$81
		.WORD	_sprB06_CC_A
_sprB06_CD:
		.BYTE	$81
		.WORD	_sprB06_CD_A
_sprB06_CE:
		.BYTE	$81
		.WORD	_sprB06_CE_A
_sprB06_CF:
		.BYTE	$81
		.WORD	_sprB06_CF_A
_sprB06_D0:
		.BYTE	$81
		.WORD	_sprB06_D0_A
_sprB06_D1:
		.BYTE	$81
		.WORD	_sprB06_D1_A
_sprB06_D2:
		.BYTE	$81
		.WORD	_sprB06_D2_A
_sprB06_D3:
		.BYTE	$81
		.WORD	_sprB06_D3_A
_sprB06_D4:
		.BYTE	$81
		.WORD	_sprB06_D4_A
_sprB06_D5:
		.BYTE	$81
		.WORD	_sprB06_D5_A
_sprB06_D6:
		.BYTE	$81
		.WORD	_sprB06_D6_A
_sprB06_D7:
		.BYTE	$81
		.WORD	_sprB06_D7_A
_sprB06_D8:
		.BYTE	$81
		.WORD	_sprB06_D8_A
_sprB06_D9:
		.BYTE	$81
		.WORD	_sprB06_D9_A
_sprB06_DA:
		.BYTE	$81
		.WORD	_sprB06_DA_A
_sprB06_DB:
		.BYTE	$81
		.WORD	_sprB06_DB_A
_sprB06_DC:
		.BYTE	$81
		.WORD	_sprB06_DC_A
_sprB06_DD:
		.BYTE	$81
		.WORD	_sprB06_DD_A
_sprB06_DE:
		.BYTE	$81
		.WORD	_sprB06_DE_A
_sprB06_DF:
		.BYTE	$81
		.WORD	_sprB06_DF_A
_sprB06_E0:
		.BYTE	$81
		.WORD	_sprB06_E0_A
_sprB06_E1:
		.BYTE	$81
		.WORD	_sprB06_E1_A
_sprB06_E2:
		.BYTE	$81
		.WORD	_sprB06_E2_A
_sprB06_E3:
		.BYTE	$81
		.WORD	_sprB06_E3_A
_sprB06_E4:
		.BYTE	$81
		.WORD	_sprB06_E4_A
_sprB06_E5:
		.BYTE	$81
		.WORD	_sprB06_E5_A
_sprB06_E6:
		.BYTE	$81
		.WORD	_sprB06_E6_A
_sprB06_E7:
		.BYTE	$81
		.WORD	_sprB06_E7_A
_sprB06_E8:
		.BYTE	$81
		.WORD	_sprB06_E8_A
_sprB06_E9:
		.BYTE	$81
		.WORD	_sprB06_E9_A
_sprB06_EA:
		.BYTE	$81
		.WORD	_sprB06_EA_A
_sprB06_EB:
		.BYTE	$81
		.WORD	_sprB06_EB_A
_sprB06_C0_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$88,$03,$F8
		.BYTE	$EC,$98,$03,$00
		.BYTE	$EC,$B8,$03,$08
		.BYTE	$FC,$8A,$03,$F8
		.BYTE	$FC,$9A,$03,$00
_sprB06_C1_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$84,$43,$00
		.BYTE	$EC,$94,$43,$F8
		.BYTE	$EC,$BC,$43,$08
		.BYTE	$FC,$86,$43,$00
		.BYTE	$FC,$96,$43,$F8
		.BYTE	$FC,$AC,$43,$08
_sprB06_C2_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$80,$03,$F8
		.BYTE	$EC,$90,$03,$00
		.BYTE	$EC,$9C,$03,$F0
		.BYTE	$FC,$82,$03,$F8
		.BYTE	$FC,$92,$03,$00
		.BYTE	$FC,$9E,$03,$F0
_sprB06_C3_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$84,$03,$F8
		.BYTE	$EC,$94,$03,$00
		.BYTE	$EC,$BC,$03,$F0
		.BYTE	$FC,$86,$03,$F8
		.BYTE	$FC,$96,$03,$00
		.BYTE	$FC,$AC,$03,$F0
_sprB06_C4_A:
		.BYTE	$06
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$88,$43,$00
		.BYTE	$EC,$A8,$03,$F8
		.BYTE	$FC,$8A,$43,$00
		.BYTE	$FC,$AA,$03,$F8
_sprB06_C5_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$A4,$43,$00
		.BYTE	$EC,$B4,$43,$F8
		.BYTE	$FC,$A6,$43,$00
		.BYTE	$FC,$B6,$43,$F8
		.BYTE	$FC,$BA,$43,$08
_sprB06_C6_A:
		.BYTE	$06
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$A0,$03,$F8
		.BYTE	$EC,$B0,$03,$00
		.BYTE	$FC,$A2,$03,$F8
		.BYTE	$FC,$B2,$03,$00
_sprB06_C7_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$A4,$03,$F8
		.BYTE	$EC,$B4,$03,$00
		.BYTE	$FC,$A6,$03,$F8
		.BYTE	$FC,$B6,$03,$00
		.BYTE	$FC,$BA,$03,$F0
_sprB06_C8_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$EC,$88,$03,$FA
		.BYTE	$EC,$98,$03,$02
		.BYTE	$EC,$B8,$03,$0A
		.BYTE	$FC,$8A,$03,$FA
		.BYTE	$FC,$9A,$03,$02
_sprB06_C9_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$EC,$84,$43,$02
		.BYTE	$EC,$94,$43,$FA
		.BYTE	$EC,$BC,$43,$0A
		.BYTE	$FC,$86,$43,$02
		.BYTE	$FC,$96,$43,$FA
		.BYTE	$FC,$AC,$43,$0A
_sprB06_CA_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$EC,$80,$03,$FA
		.BYTE	$EC,$90,$03,$02
		.BYTE	$EC,$9C,$03,$F2
		.BYTE	$FC,$82,$03,$FA
		.BYTE	$FC,$92,$03,$02
		.BYTE	$FC,$9E,$03,$F2
_sprB06_CB_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$EC,$84,$03,$FA
		.BYTE	$EC,$94,$03,$02
		.BYTE	$EC,$BC,$03,$F2
		.BYTE	$FC,$86,$03,$FA
		.BYTE	$FC,$96,$03,$02
		.BYTE	$FC,$AC,$03,$F2
_sprB06_CC_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$F4,$AC,$03,$F8
		.BYTE	$F4,$AC,$43,$00
_sprB06_CD_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$B4,$43,$F8
		.BYTE	$F4,$A2,$43,$10
		.BYTE	$F4,$A6,$43,$00
		.BYTE	$F4,$B2,$43,$08
		.BYTE	$F4,$B6,$43,$F8
_sprB06_CE_A:
		.BYTE	$07
		.BYTE	$04,$BC,$03,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$F4,$9C,$03,$F8
		.BYTE	$F4,$9C,$43,$00
_sprB06_CF_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$B4,$03,$00
		.BYTE	$F4,$A2,$03,$E8
		.BYTE	$F4,$A6,$03,$F8
		.BYTE	$F4,$B2,$03,$F0
		.BYTE	$F4,$B6,$03,$00
_sprB06_D0_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$EB,$BA,$C3,$00
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$AA,$03,$F8
		.BYTE	$F3,$AA,$43,$00
_sprB06_D1_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$82,$43,$10
		.BYTE	$F3,$92,$43,$08
		.BYTE	$F3,$96,$43,$F8
		.BYTE	$F3,$A6,$43,$00
_sprB06_D2_A:
		.BYTE	$07
		.BYTE	$03,$BA,$43,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$9A,$03,$F8
		.BYTE	$F3,$9A,$43,$00
_sprB06_D3_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$82,$03,$E8
		.BYTE	$F3,$92,$03,$F0
		.BYTE	$F3,$96,$03,$00
		.BYTE	$F3,$A6,$03,$F8
_sprB06_D4_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$EA,$B8,$C3,$00
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$A8,$03,$F8
		.BYTE	$F2,$A8,$43,$00
_sprB06_D5_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$84,$43,$10
		.BYTE	$F2,$86,$43,$F8
		.BYTE	$F2,$94,$43,$08
		.BYTE	$F2,$A6,$43,$00
_sprB06_D6_A:
		.BYTE	$07
		.BYTE	$02,$B8,$43,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$98,$03,$F8
		.BYTE	$F2,$98,$43,$00
_sprB06_D7_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$84,$03,$E8
		.BYTE	$F2,$86,$03,$00
		.BYTE	$F2,$94,$03,$F0
		.BYTE	$F2,$A6,$03,$F8
_sprB06_D8_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$F4,$AC,$03,$F8
		.BYTE	$F4,$AC,$43,$00
_sprB06_D9_A:
		.BYTE	$05
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$B4,$43,$F8
		.BYTE	$F4,$A6,$43,$00
		.BYTE	$F4,$B6,$43,$F8
_sprB06_DA_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$F4,$9C,$03,$F8
		.BYTE	$F4,$9C,$43,$00
_sprB06_DB_A:
		.BYTE	$05
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$B4,$03,$00
		.BYTE	$F4,$A6,$03,$F8
		.BYTE	$F4,$B6,$03,$00
_sprB06_DC_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$AA,$03,$F8
		.BYTE	$F3,$AA,$43,$00
_sprB06_DD_A:
		.BYTE	$04
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$96,$43,$F8
		.BYTE	$F3,$A6,$43,$00
_sprB06_DE_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$9A,$03,$F8
		.BYTE	$F3,$9A,$43,$00
_sprB06_DF_A:
		.BYTE	$04
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$96,$03,$00
		.BYTE	$F3,$A6,$03,$F8
_sprB06_E0_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$A8,$03,$F8
		.BYTE	$F2,$A8,$43,$00
_sprB06_E1_A:
		.BYTE	$04
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$86,$43,$F8
		.BYTE	$F2,$A6,$43,$00
_sprB06_E2_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$98,$03,$F8
		.BYTE	$F2,$98,$43,$00
_sprB06_E3_A:
		.BYTE	$04
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$86,$03,$00
		.BYTE	$F2,$A6,$03,$F8
_sprB06_E4_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$02
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$E4,$8C,$03,$FA
		.BYTE	$E4,$8C,$43,$02
		.BYTE	$F4,$AC,$03,$FA
		.BYTE	$F4,$AC,$43,$02
_sprB06_E5_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$02
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$E4,$B4,$43,$FA
		.BYTE	$F4,$A2,$43,$12
		.BYTE	$F4,$A6,$43,$02
		.BYTE	$F4,$B2,$43,$0A
		.BYTE	$F4,$B6,$43,$FA
_sprB06_E6_A:
		.BYTE	$07
		.BYTE	$04,$BC,$03,$FA
		.BYTE	$06,$3E,$00,$02
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$E4,$8C,$03,$FA
		.BYTE	$E4,$8C,$43,$02
		.BYTE	$F4,$9C,$03,$FA
		.BYTE	$F4,$9C,$43,$02
_sprB06_E7_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$02
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$E4,$B4,$03,$02
		.BYTE	$F4,$A2,$03,$EA
		.BYTE	$F4,$A6,$03,$FA
		.BYTE	$F4,$B2,$03,$F2
		.BYTE	$F4,$B6,$03,$02
_sprB06_E8_A:
		.BYTE	$02
		.BYTE	$F8,$CE,$03,$00
		.BYTE	$F8,$BE,$03,$F8
_sprB06_E9_A:
		.BYTE	$02
		.BYTE	$F8,$EE,$03,$00
		.BYTE	$F8,$DE,$03,$F8
_sprB06_EA_A:
		.BYTE	$02
		.BYTE	$F8,$EE,$43,$F8
		.BYTE	$F8,$DE,$43,$00
_sprB06_EB_A:
		.BYTE	$02
		.BYTE	$F8,$9E,$03,$F8
		.BYTE	$F8,$AE,$03,$00

_spr_libA07:
		.WORD	_sprA08_00
		.WORD	_sprA08_01
		.WORD	_sprA08_02
		.WORD	_sprA08_03
		.WORD	_sprA07_04
		.WORD	_sprA07_07
		.WORD	_sprA07_06
		.WORD	_sprA07_07
		.WORD	_sprA07_08
		.WORD	_sprA07_09
		.WORD	_sprA07_0A
		.WORD	_sprA07_0B
		.WORD	_sprA07_0C
		.WORD	_sprA07_0F
		.WORD	_sprA07_0E
		.WORD	_sprA07_0F
		.WORD	_sprA07_10
		.WORD	_sprA07_11
		.WORD	_sprA07_12
		.WORD	_sprA07_13
		.WORD	_sprA07_14
		.WORD	_sprA07_15
		.WORD	_sprA07_16
		.WORD	_sprA07_17
		.WORD	_sprA07_18
		.WORD	_sprA07_19
		.WORD	_sprA07_1A
		.WORD	_sprA07_1B
		.WORD	_sprA07_1C
		.WORD	_sprA07_1D
		.WORD	_sprA07_1E
		.WORD	_sprA07_1F
		.WORD	_sprA07_20
		.WORD	_sprA07_21
		.WORD	_sprA07_22
		.WORD	_sprA07_23
		.WORD	_sprA07_24
		.WORD	_sprA07_25
		.WORD	_sprA07_26
		.WORD	_sprA07_27
		.WORD	_sprA07_28
		.WORD	_sprA07_29
		.WORD	_sprA07_2A
		.WORD	_sprA07_2B
		.WORD	_sprA07_2C
		.WORD	_sprA07_2D
		.WORD	_sprA07_2E
		.WORD	_sprA07_2F
		.WORD	_sprA07_30
		.WORD	_sprA07_31
		.WORD	_sprA07_32
		.WORD	_sprA07_33
		.WORD	_sprA07_34
		.WORD	_sprA07_35
		.WORD	_sprA07_36
		.WORD	_sprA07_37
		.WORD	_sprA07_38
		.WORD	_sprA07_39
		.WORD	_sprA07_3A
		.WORD	_sprA07_3B
		.WORD	_sprA07_3C
		.WORD	_sprA07_3D
		.WORD	_sprA07_3E
		.WORD	_sprA07_3F
		.WORD	_sprA07_40
		.WORD	_sprA07_41
		.WORD	_sprA07_42
		.WORD	_sprA07_43
		.WORD	_sprA07_44
		.WORD	_sprA07_45
		.WORD	_sprA07_46
		.WORD	_sprA07_47
		.WORD	_sprA07_48
		.WORD	_sprA07_49
; NOTE: the morning star projectile only 9 sprites long max (5 frames)
; here are two more frames with 10 and 11 lengths, they are unused
;
		.WORD	_sprA07_4A	; unused
		.WORD	_sprA07_4B	; unused
		.WORD	_sprA07_4C
		.WORD	_sprA07_4D
		.WORD	_sprA07_4E
		.WORD	_sprA07_4F
		.WORD	_sprA07_50
		.WORD	_sprA07_51
		.WORD	_sprA07_52
		.WORD	_sprA07_53
		.WORD	_sprA07_54
		.WORD	_sprA07_55
		.WORD	_sprA07_56
		.WORD	_sprA07_57
		.WORD	_sprA07_58
		.WORD	_sprA07_59
		.WORD	_sprA07_5A
		.WORD	_sprA07_5B
		.WORD	_sprA07_5C
		.WORD	_sprA07_5D
		.WORD	_sprA07_5E
		.WORD	_sprA07_5F
		.WORD	_sprA07_60
		.WORD	_sprA07_61
		.WORD	_sprA07_62
		.WORD	_sprA07_63
		.WORD	_sprA07_64
		.WORD	_sprA07_65
		.WORD	_sprA07_66
		.WORD	_sprA07_67
		.WORD	_sprA07_68
		.WORD	_sprA07_69
		.WORD	_sprA07_6A
		.WORD	_sprA07_6B
		.WORD	_sprA07_6C
		.WORD	_sprA07_6D
		.WORD	_sprA07_6E
		.WORD	_sprA07_6F
		.WORD	_sprA07_70
		.WORD	_sprA07_71
		.WORD	_sprA07_72
		.WORD	_sprA07_73
		.WORD	_sprA07_74
		.WORD	_sprA07_75
		.WORD	_sprA07_76
		.WORD	_sprA07_77
		.WORD	_sprA07_78
		.WORD	_sprA07_79
		.WORD	_sprA07_7A
		.WORD	_sprA07_7B
		.WORD	_sprA07_7C
		.WORD	_sprA07_7D
		.WORD	_sprA07_7E
		.WORD	_sprA07_7F
		.WORD	_sprA07_80
		.WORD	_sprA07_81
		.WORD	_sprA07_82
		.WORD	_sprA07_83
		.WORD	_sprA07_84
		.WORD	_sprA07_85
		.WORD	_sprA07_86
		.WORD	_sprA07_87
		.WORD	_sprA07_88
		.WORD	_sprA07_89
		.WORD	_sprA07_8A
		.WORD	_sprA07_8B
		.WORD	_sprA07_8C
		.WORD	_sprA07_8D
_spr_libB07:
		.WORD	_sprB07_C0
		.WORD	_sprB07_C1
		.WORD	_sprB07_C2
		.WORD	_sprB07_C3
		.WORD	_sprB07_C4
		.WORD	_sprB07_C5
		.WORD	_sprB07_C6
		.WORD	_sprB07_C7
		.WORD	_sprB07_C8
		.WORD	_sprB07_C9
		.WORD	_sprB07_CA

_sprA07_04:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_04_B
_sprA07_04_B
		.BYTE	$04
		.BYTE	$02,$8A,$02,$F8
		.BYTE	$02,$9A,$02,$00
		.BYTE	$F2,$8E,$02,$F8
		.BYTE	$F2,$9E,$02,$00
_sprA07_06:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_06_B
_sprA07_06_B
		.BYTE	$04
		.BYTE	$02,$8A,$42,$00
		.BYTE	$02,$9A,$42,$F8
		.BYTE	$F2,$8E,$42,$00
		.BYTE	$F2,$9E,$42,$F8
_sprA07_07:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_07_B
_sprA07_07_B
		.BYTE	$04
		.BYTE	$04,$9A,$02,$00
		.BYTE	$04,$9A,$42,$F8
		.BYTE	$F4,$9E,$02,$00
		.BYTE	$F4,$9E,$42,$F8
_sprA07_08:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_08_B
_sprA07_08_B
		.BYTE	$04
		.BYTE	$02,$8C,$42,$00
		.BYTE	$02,$9C,$42,$F8
		.BYTE	$F2,$A8,$42,$00
		.BYTE	$F2,$B8,$42,$F8
_sprA07_09:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_09_B
_sprA07_09_B
		.BYTE	$04
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$F3,$AA,$42,$00
		.BYTE	$F3,$B8,$42,$F8
_sprA07_0A:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_0A_B
_sprA07_0A_B
		.BYTE	$04
		.BYTE	$02,$8C,$02,$F8
		.BYTE	$02,$9C,$02,$00
		.BYTE	$F2,$AA,$42,$00
		.BYTE	$F2,$BA,$42,$F8
_sprA07_0B:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_0B_B
_sprA07_0B_B
		.BYTE	$04
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$F3,$AA,$42,$00
		.BYTE	$F3,$BA,$42,$F8
_sprA07_0C:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_0C_B
_sprA07_0C_B
		.BYTE	$04
		.BYTE	$02,$8A,$02,$F8
		.BYTE	$02,$9A,$02,$00
		.BYTE	$F2,$88,$02,$F8
		.BYTE	$F2,$98,$02,$00
_sprA07_0E:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_0E_B
_sprA07_0E_B
		.BYTE	$04
		.BYTE	$02,$8A,$42,$00
		.BYTE	$02,$9A,$42,$F8
		.BYTE	$F2,$88,$42,$00
		.BYTE	$F2,$98,$42,$F8
_sprA07_0F:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_0F_B
_sprA07_0F_B
		.BYTE	$04
		.BYTE	$03,$9A,$02,$00
		.BYTE	$03,$9A,$42,$F8
		.BYTE	$F3,$98,$02,$00
		.BYTE	$F3,$98,$42,$F8
_sprA07_10:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_10_B
_sprA07_10_B
		.BYTE	$04
		.BYTE	$02,$8C,$02,$F8
		.BYTE	$02,$9C,$02,$00
		.BYTE	$F2,$A8,$02,$F8
		.BYTE	$F2,$B8,$02,$00
_sprA07_11:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_11_B
_sprA07_11_B
		.BYTE	$04
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$F3,$AA,$02,$F8
		.BYTE	$F3,$B8,$02,$00
_sprA07_12:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_12_B
_sprA07_12_B
		.BYTE	$04
		.BYTE	$02,$8C,$42,$00
		.BYTE	$02,$9C,$42,$F8
		.BYTE	$F2,$AA,$02,$F8
		.BYTE	$F2,$BA,$02,$00
_sprA07_13:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_13_B
_sprA07_13_B
		.BYTE	$04
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$F3,$AA,$02,$F8
		.BYTE	$F3,$BA,$02,$00
_sprA07_14:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_14_B
_sprA07_14_B
		.BYTE	$04
		.BYTE	$02,$8A,$02,$FA
		.BYTE	$02,$9A,$02,$02
		.BYTE	$F2,$8E,$02,$FA
		.BYTE	$F2,$9E,$02,$02
_sprA07_15:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_15_B
_sprA07_15_B
		.BYTE	$04
		.BYTE	$02,$8C,$42,$02
		.BYTE	$02,$9C,$42,$FA
		.BYTE	$F2,$A8,$42,$02
		.BYTE	$F2,$B8,$42,$FA
_sprA07_16:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_16_B
_sprA07_16_B
		.BYTE	$04
		.BYTE	$02,$8A,$02,$FA
		.BYTE	$02,$9A,$02,$02
		.BYTE	$F2,$88,$02,$FA
		.BYTE	$F2,$98,$02,$02
_sprA07_17:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_17_B
_sprA07_17_B
		.BYTE	$04
		.BYTE	$02,$8C,$02,$FA
		.BYTE	$02,$9C,$02,$02
		.BYTE	$F2,$A8,$02,$FA
		.BYTE	$F2,$B8,$02,$02
_sprA07_18:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F6
		.BYTE	$F0,$A8,$02,$F0
		.BYTE	$F0,$B8,$02,$F8
_sprA07_19:
		.BYTE	$02
		.BYTE	$F8,$AE,$02,$F0
		.BYTE	$F8,$BE,$02,$F8
_sprA07_1A:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$02
		.BYTE	$F0,$A8,$42,$08
		.BYTE	$F0,$B8,$42,$00
_sprA07_1B:
		.BYTE	$02
		.BYTE	$F8,$AE,$42,$08
		.BYTE	$F8,$BE,$42,$00
_sprA07_1C:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_1C_B
_sprA07_1C_B
		.BYTE	$05
		.BYTE	$00,$C8,$02,$F8
		.BYTE	$00,$C8,$42,$00
		.BYTE	$F0,$C6,$02,$F8
		.BYTE	$F0,$C6,$42,$00
		.BYTE	$F4,$E6,$40,$F4
_sprA07_1D:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_1D_B
_sprA07_1D_B
		.BYTE	$06
		.BYTE	$00,$EC,$02,$F8
		.BYTE	$00,$FC,$02,$00
		.BYTE	$F0,$EA,$02,$F8
		.BYTE	$F0,$FA,$02,$00
		.BYTE	$F9,$D6,$00,$FD
		.BYTE	$F9,$E6,$00,$05
_sprA07_1E:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_1E_B
_sprA07_1E_B
		.BYTE	$06
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$F0,$C4,$02,$F8
		.BYTE	$F0,$C4,$42,$00
		.BYTE	$F9,$D6,$00,$FA
		.BYTE	$F9,$E6,$00,$02
_sprA07_1F:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_1F_B
_sprA07_1F_B
		.BYTE	$06
		.BYTE	$00,$EC,$42,$00
		.BYTE	$00,$FC,$42,$F8
		.BYTE	$F0,$EA,$42,$00
		.BYTE	$F0,$FA,$42,$F8
		.BYTE	$F9,$D6,$40,$FB
		.BYTE	$F9,$E6,$40,$F3
_sprA07_20:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_20_B
_sprA07_20_B
		.BYTE	$05
		.BYTE	$00,$C8,$02,$F8
		.BYTE	$00,$C8,$42,$00
		.BYTE	$F0,$C6,$02,$F8
		.BYTE	$F0,$C6,$42,$00
		.BYTE	$F4,$E8,$40,$F4
_sprA07_21:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_21_B
_sprA07_21_B
		.BYTE	$06
		.BYTE	$00,$EC,$02,$F8
		.BYTE	$00,$FC,$02,$00
		.BYTE	$F0,$EA,$02,$F8
		.BYTE	$F0,$FA,$02,$00
		.BYTE	$F9,$D8,$00,$FD
		.BYTE	$F9,$E8,$00,$05
_sprA07_22:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_22_B
_sprA07_22_B
		.BYTE	$06
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$F0,$C4,$02,$F8
		.BYTE	$F0,$C4,$42,$00
		.BYTE	$F9,$D8,$00,$FA
		.BYTE	$F9,$E8,$00,$02
_sprA07_23:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_23_B
_sprA07_23_B
		.BYTE	$06
		.BYTE	$00,$EC,$42,$00
		.BYTE	$00,$FC,$42,$F8
		.BYTE	$F0,$EA,$42,$00
		.BYTE	$F0,$FA,$42,$F8
		.BYTE	$F9,$D8,$40,$FB
		.BYTE	$F9,$E8,$40,$F3
_sprA07_24:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_24_B
_sprA07_24_B
		.BYTE	$06
		.BYTE	$00,$F6,$02,$F8
		.BYTE	$00,$F6,$42,$00
		.BYTE	$E9,$D6,$40,$00
		.BYTE	$E9,$E6,$40,$F8
		.BYTE	$F0,$F4,$02,$F8
		.BYTE	$F0,$F4,$42,$00
_sprA07_25:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_25_B
_sprA07_25_B
		.BYTE	$06
		.BYTE	$00,$CC,$02,$F8
		.BYTE	$00,$DC,$02,$00
		.BYTE	$EE,$D6,$00,$FA
		.BYTE	$EE,$E6,$00,$02
		.BYTE	$F0,$CA,$02,$F8
		.BYTE	$F0,$DA,$02,$00
_sprA07_26:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_26_B
_sprA07_26_B
		.BYTE	$06
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$ED,$D6,$00,$F9
		.BYTE	$ED,$E6,$00,$01
		.BYTE	$F0,$D4,$02,$F8
		.BYTE	$F0,$D4,$42,$00
_sprA07_27:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_27_B
_sprA07_27_B
		.BYTE	$06
		.BYTE	$00,$CC,$42,$00
		.BYTE	$00,$DC,$42,$F8
		.BYTE	$EE,$D6,$40,$FE
		.BYTE	$EE,$E6,$40,$F6
		.BYTE	$F0,$CA,$42,$00
		.BYTE	$F0,$DA,$42,$F8
_sprA07_28:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_28_B
_sprA07_28_B
		.BYTE	$06
		.BYTE	$00,$F6,$02,$F8
		.BYTE	$00,$F6,$42,$00
		.BYTE	$E9,$D8,$40,$00
		.BYTE	$E9,$E8,$40,$F8
		.BYTE	$F0,$F4,$02,$F8
		.BYTE	$F0,$F4,$42,$00
_sprA07_29:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_29_B
_sprA07_29_B
		.BYTE	$06
		.BYTE	$00,$CC,$02,$F8
		.BYTE	$00,$DC,$02,$00
		.BYTE	$EE,$D8,$00,$FA
		.BYTE	$EE,$E8,$00,$02
		.BYTE	$F0,$CA,$02,$F8
		.BYTE	$F0,$DA,$02,$00
_sprA07_2A:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_2A_B
_sprA07_2A_B
		.BYTE	$06
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$ED,$D8,$00,$F9
		.BYTE	$ED,$E8,$00,$01
		.BYTE	$F0,$D4,$02,$F8
		.BYTE	$F0,$D4,$42,$00
_sprA07_2B:
		.BYTE	$82
		.WORD	_sprA05_04_A
		.WORD	_sprA07_2B_B
_sprA07_2B_B
		.BYTE	$06
		.BYTE	$00,$CC,$42,$00
		.BYTE	$00,$DC,$42,$F8
		.BYTE	$EE,$D8,$40,$FE
		.BYTE	$EE,$E8,$40,$F6
		.BYTE	$F0,$CA,$42,$00
		.BYTE	$F0,$DA,$42,$F8
_sprA07_2C:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_2C_B
_sprA07_2C_B
		.BYTE	$06
		.BYTE	$00,$F6,$02,$FA
		.BYTE	$00,$F6,$42,$02
		.BYTE	$E9,$D6,$40,$02
		.BYTE	$E9,$E6,$40,$FA
		.BYTE	$F0,$F4,$02,$FA
		.BYTE	$F0,$F4,$42,$02
_sprA07_2D:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_2D_B
_sprA07_2D_B
		.BYTE	$06
		.BYTE	$00,$CC,$02,$FA
		.BYTE	$00,$DC,$02,$02
		.BYTE	$EE,$D6,$00,$FC
		.BYTE	$EE,$E6,$00,$04
		.BYTE	$F0,$CA,$02,$FA
		.BYTE	$F0,$DA,$02,$02
_sprA07_2E:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_2E_B
_sprA07_2E_B
		.BYTE	$06
		.BYTE	$00,$E4,$02,$FA
		.BYTE	$00,$E4,$42,$02
		.BYTE	$ED,$D6,$00,$FB
		.BYTE	$ED,$E6,$00,$03
		.BYTE	$F0,$D4,$02,$FA
		.BYTE	$F0,$D4,$42,$02
_sprA07_2F:
		.BYTE	$82
		.WORD	_sprA05_0C_A
		.WORD	_sprA07_2F_B
_sprA07_2F_B
		.BYTE	$06
		.BYTE	$00,$CC,$42,$02
		.BYTE	$00,$DC,$42,$FA
		.BYTE	$EE,$D6,$40,$00
		.BYTE	$EE,$E6,$40,$F8
		.BYTE	$F0,$CA,$42,$02
		.BYTE	$F0,$DA,$42,$FA
_sprA07_30:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F8
		.BYTE	$F0,$CA,$42,$F8
		.BYTE	$F0,$DA,$42,$F0
_sprA07_31:
		.BYTE	$02
		.BYTE	$F8,$CE,$42,$F8
		.BYTE	$F8,$DE,$42,$F0
_sprA07_32:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$00
		.BYTE	$F0,$CA,$02,$00
		.BYTE	$F0,$DA,$02,$08
_sprA07_33:
		.BYTE	$02
		.BYTE	$F8,$CE,$02,$00
		.BYTE	$F8,$DE,$02,$08
_sprA07_34:
		.BYTE	$02
		.BYTE	$08,$3E,$40,$F8
		.BYTE	$08,$3E,$00,$00
_sprA07_35:
		.BYTE	$01
		.BYTE	$F8,$F8,$02,$FC
_sprA07_36:
		.BYTE	$03
		.BYTE	$F4,$F8,$02,$FC
		.BYTE	$FC,$E0,$02,$F8
		.BYTE	$FC,$E0,$42,$00
_sprA07_37:
		.BYTE	$0B
		.BYTE	$00,$E0,$02,$F8
		.BYTE	$00,$E0,$42,$00
		.BYTE	$F1,$F8,$02,$FC
		.BYTE	$F4,$E2,$82,$F8
		.BYTE	$F4,$E2,$C2,$00
		.BYTE	$F7,$E2,$82,$F8
		.BYTE	$F7,$E2,$C2,$00
		.BYTE	$FA,$E2,$82,$F8
		.BYTE	$FA,$E2,$C2,$00
		.BYTE	$FD,$E2,$82,$F8
		.BYTE	$FD,$E2,$C2,$00
_sprA07_38:
		.BYTE	$0B
		.BYTE	$02,$E0,$02,$F8
		.BYTE	$02,$E0,$42,$00
		.BYTE	$EE,$F8,$02,$FC
		.BYTE	$F2,$E2,$82,$F8
		.BYTE	$F2,$E2,$C2,$00
		.BYTE	$F6,$E2,$82,$F8
		.BYTE	$F6,$E2,$C2,$00
		.BYTE	$FA,$E2,$82,$F8
		.BYTE	$FA,$E2,$C2,$00
		.BYTE	$FE,$E2,$82,$F8
		.BYTE	$FE,$E2,$C2,$00
_sprA07_39:
		.BYTE	$0B
		.BYTE	$00,$E2,$82,$F8
		.BYTE	$00,$E2,$C2,$00
		.BYTE	$05,$E0,$02,$F8
		.BYTE	$05,$E0,$42,$00
		.BYTE	$EC,$F8,$02,$FC
		.BYTE	$F1,$E2,$82,$F8
		.BYTE	$F1,$E2,$C2,$00
		.BYTE	$F6,$E2,$82,$F8
		.BYTE	$F6,$E2,$C2,$00
		.BYTE	$FB,$E2,$82,$F8
		.BYTE	$FB,$E2,$C2,$00
_sprA07_3A:
		.BYTE	$0B
		.BYTE	$01,$E2,$82,$F8
		.BYTE	$01,$E2,$C2,$00
		.BYTE	$07,$E0,$02,$F8
		.BYTE	$07,$E0,$42,$00
		.BYTE	$E9,$F8,$02,$FC
		.BYTE	$EF,$E2,$82,$F8
		.BYTE	$EF,$E2,$C2,$00
		.BYTE	$F5,$E2,$82,$F8
		.BYTE	$F5,$E2,$C2,$00
		.BYTE	$FB,$E2,$82,$F8
		.BYTE	$FB,$E2,$C2,$00
_sprA07_3B:
		.BYTE	$0B
		.BYTE	$03,$E2,$82,$F8
		.BYTE	$03,$E2,$C2,$00
		.BYTE	$0A,$E0,$02,$F8
		.BYTE	$0A,$E0,$42,$00
		.BYTE	$E7,$F8,$02,$FC
		.BYTE	$EE,$E2,$82,$F8
		.BYTE	$EE,$E2,$C2,$00
		.BYTE	$F5,$E2,$82,$F8
		.BYTE	$F5,$E2,$C2,$00
		.BYTE	$FC,$E2,$82,$F8
		.BYTE	$FC,$E2,$C2,$00
_sprA07_3C:
		.BYTE	$0B
		.BYTE	$04,$E2,$82,$F8
		.BYTE	$04,$E2,$C2,$00
		.BYTE	$0C,$E0,$02,$F8
		.BYTE	$0C,$E0,$42,$00
		.BYTE	$E4,$F8,$02,$FC
		.BYTE	$EC,$E2,$82,$F8
		.BYTE	$EC,$E2,$C2,$00
		.BYTE	$F4,$E2,$82,$F8
		.BYTE	$F4,$E2,$C2,$00
		.BYTE	$FC,$E2,$82,$F8
		.BYTE	$FC,$E2,$C2,$00
_sprA07_3D:
		.BYTE	$0B
		.BYTE	$04,$E2,$82,$FA
		.BYTE	$04,$E2,$C2,$02
		.BYTE	$0C,$E0,$02,$FA
		.BYTE	$0C,$E0,$42,$02
		.BYTE	$E4,$F8,$02,$FE
		.BYTE	$EC,$E2,$82,$FA
		.BYTE	$EC,$E2,$C2,$02
		.BYTE	$F4,$E2,$82,$FA
		.BYTE	$F4,$E2,$C2,$02
		.BYTE	$FC,$E2,$82,$FA
		.BYTE	$FC,$E2,$C2,$02
_sprA07_3E:
		.BYTE	$04
		.BYTE	$F4,$C0,$02,$EC
		.BYTE	$F4,$D0,$02,$F4
		.BYTE	$F8,$F2,$C2,$F3
		.BYTE	$FD,$F2,$02,$F8
_sprA07_3F:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F8
		.BYTE	$F8,$C0,$02,$F0
		.BYTE	$F8,$D0,$02,$F8
_sprA07_40:
		.BYTE	$04
		.BYTE	$F4,$C0,$42,$0D
		.BYTE	$F4,$D0,$42,$05
		.BYTE	$F8,$F2,$82,$06
		.BYTE	$FD,$F2,$42,$01
_sprA07_41:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$00
		.BYTE	$F8,$C0,$42,$08
		.BYTE	$F8,$D0,$42,$00
_sprA07_42:
		.BYTE	$08
		.BYTE	$EE,$D8,$03,$F2
		.BYTE	$EE,$E0,$03,$FA
		.BYTE	$EE,$F0,$03,$02
		.BYTE	$FC,$EC,$00,$EE
		.BYTE	$FC,$FC,$00,$F6
		.BYTE	$FE,$CE,$03,$F2
		.BYTE	$FE,$DE,$03,$FA
		.BYTE	$FE,$EE,$03,$02
_sprA07_43:
		.BYTE	$04
		.BYTE	$06,$AE,$03,$FA
		.BYTE	$06,$BE,$03,$02
		.BYTE	$F6,$E0,$03,$FA
		.BYTE	$F6,$F0,$03,$02
_sprA07_44:
		.BYTE	$04
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_45:
		.BYTE	$05
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_46:
		.BYTE	$06
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_47:
		.BYTE	$07
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_48:
		.BYTE	$08
		.BYTE	$9A,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_49:
		.BYTE	$09
		.BYTE	$8A,$C8,$00,$FC
		.BYTE	$9A,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_4A:
		.BYTE	$0A
		.BYTE	$7A,$C8,$00,$FC
		.BYTE	$8A,$C8,$00,$FC
		.BYTE	$9A,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_4B:
		.BYTE	$0B
		.BYTE	$6A,$C8,$00,$FC
		.BYTE	$7A,$C8,$00,$FC
		.BYTE	$8A,$C8,$00,$FC
		.BYTE	$9A,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$F8,$FC,$00,$00
_sprA07_4C:
		.BYTE	$06
		.BYTE	$04,$96,$02,$F8
		.BYTE	$04,$96,$42,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$94,$02,$F8
		.BYTE	$F4,$94,$42,$00
_sprA07_4D:
		.BYTE	$06
		.BYTE	$04,$8A,$42,$00
		.BYTE	$04,$9A,$42,$F8
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$88,$42,$00
		.BYTE	$F4,$98,$42,$F8
_sprA07_4E:
		.BYTE	$06
		.BYTE	$04,$92,$02,$F8
		.BYTE	$04,$92,$42,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$90,$02,$F8
		.BYTE	$F4,$90,$42,$00
_sprA07_4F:
		.BYTE	$06
		.BYTE	$04,$8A,$02,$F8
		.BYTE	$04,$9A,$02,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$88,$02,$F8
		.BYTE	$F4,$98,$02,$00
_sprA07_50:
		.BYTE	$06
		.BYTE	$04,$86,$02,$F8
		.BYTE	$04,$86,$42,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$84,$02,$F8
		.BYTE	$F4,$84,$42,$00
_sprA07_51:
		.BYTE	$06
		.BYTE	$04,$8E,$42,$00
		.BYTE	$04,$9E,$42,$F8
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$8C,$42,$00
		.BYTE	$F4,$9C,$42,$F8
_sprA07_52:
		.BYTE	$06
		.BYTE	$04,$82,$02,$F8
		.BYTE	$04,$82,$42,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$80,$02,$F8
		.BYTE	$F4,$80,$42,$00
_sprA07_53:
		.BYTE	$06
		.BYTE	$04,$8E,$02,$F8
		.BYTE	$04,$9E,$02,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$8C,$02,$F8
		.BYTE	$F4,$9C,$02,$00
_sprA07_54:
		.BYTE	$06
		.BYTE	$04,$96,$02,$FA
		.BYTE	$04,$96,$42,$02
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$F4,$94,$02,$FA
		.BYTE	$F4,$94,$42,$02
_sprA07_55:
		.BYTE	$06
		.BYTE	$04,$8A,$42,$02
		.BYTE	$04,$9A,$42,$FA
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$F4,$88,$42,$02
		.BYTE	$F4,$98,$42,$FA
_sprA07_56:
		.BYTE	$06
		.BYTE	$04,$92,$02,$FA
		.BYTE	$04,$92,$42,$02
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$F4,$90,$02,$FA
		.BYTE	$F4,$90,$42,$02
_sprA07_57:
		.BYTE	$06
		.BYTE	$04,$8A,$02,$FA
		.BYTE	$04,$9A,$02,$02
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$F4,$88,$02,$FA
		.BYTE	$F4,$98,$02,$02
_sprA07_58:
		.BYTE	$04
		.BYTE	$ED,$C2,$02,$F3
		.BYTE	$ED,$D2,$02,$FB
		.BYTE	$FD,$C4,$02,$F3
		.BYTE	$FD,$D4,$02,$FB
_sprA07_59:
		.BYTE	$02
		.BYTE	$FC,$C6,$02,$F3
		.BYTE	$FC,$D6,$02,$FB
_sprA07_5A:
		.BYTE	$04
		.BYTE	$ED,$C2,$42,$06
		.BYTE	$ED,$D2,$42,$FE
		.BYTE	$FD,$C4,$42,$06
		.BYTE	$FD,$D4,$42,$FE
_sprA07_5B:
		.BYTE	$02
		.BYTE	$FC,$C6,$42,$06
		.BYTE	$FC,$D6,$42,$FE
_sprA07_5C:
		.BYTE	$06
		.BYTE	$04,$E2,$02,$F8
		.BYTE	$04,$F2,$02,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$E0,$02,$F8
		.BYTE	$F4,$F0,$02,$00
_sprA07_5D:
		.BYTE	$06
		.BYTE	$04,$E2,$42,$00
		.BYTE	$04,$F2,$42,$F8
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$E0,$42,$00
		.BYTE	$F4,$F0,$42,$F8
_sprA07_5E:
		.BYTE	$06
		.BYTE	$04,$F2,$02,$00
		.BYTE	$04,$F2,$42,$F8
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$F0,$02,$00
		.BYTE	$F4,$F0,$42,$F8
_sprA07_5F:
		.BYTE	$06
		.BYTE	$04,$E6,$02,$F8
		.BYTE	$04,$F6,$02,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$E4,$02,$F8
		.BYTE	$F4,$F4,$02,$00
_sprA07_60:
		.BYTE	$06
		.BYTE	$04,$E6,$42,$00
		.BYTE	$04,$F6,$42,$F8
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$E4,$42,$00
		.BYTE	$F4,$F4,$42,$F8
_sprA07_61:
		.BYTE	$06
		.BYTE	$04,$F6,$02,$00
		.BYTE	$04,$F6,$42,$F8
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$F4,$02,$00
		.BYTE	$F4,$F4,$42,$F8
_sprA07_62:
		.BYTE	$02
		.BYTE	$FA,$48,$00,$FA
		.BYTE	$FC,$48,$00,$FF
_sprA07_63:
		.BYTE	$03
		.BYTE	$F4,$58,$00,$FC
		.BYTE	$FA,$58,$00,$00
		.BYTE	$FA,$58,$00,$F8
_sprA07_64:
		.BYTE	$05
		.BYTE	$E7,$58,$00,$F6
		.BYTE	$E8,$58,$00,$02
		.BYTE	$F4,$58,$00,$F1
		.BYTE	$F7,$58,$00,$08
		.BYTE	$FD,$58,$00,$FC
_sprA07_65:
		.BYTE	$05
		.BYTE	$05,$48,$00,$FC
		.BYTE	$E4,$48,$00,$F4
		.BYTE	$E5,$48,$00,$06
		.BYTE	$F7,$48,$00,$EE
		.BYTE	$FC,$48,$00,$0F
_sprA07_66:
		.BYTE	$04
		.BYTE	$00,$AA,$00,$F8
		.BYTE	$00,$BA,$00,$00
		.BYTE	$F0,$A8,$00,$F8
		.BYTE	$F0,$B8,$00,$00
_sprA07_67:
		.BYTE	$04
		.BYTE	$00,$AA,$40,$01
		.BYTE	$00,$BA,$40,$F9
		.BYTE	$F0,$A8,$40,$01
		.BYTE	$F0,$B8,$40,$F9
_sprA07_68:
		.BYTE	$04
		.BYTE	$00,$AA,$00,$F8
		.BYTE	$00,$BA,$00,$00
		.BYTE	$F0,$C8,$40,$00
		.BYTE	$F0,$D8,$40,$F8
_sprA07_69:
		.BYTE	$04
		.BYTE	$00,$AA,$40,$01
		.BYTE	$00,$BA,$40,$F9
		.BYTE	$F0,$C8,$00,$F9
		.BYTE	$F0,$D8,$00,$01
_sprA07_6A:
		.BYTE	$04
		.BYTE	$00,$AE,$00,$F8
		.BYTE	$00,$AE,$40,$00
		.BYTE	$F0,$BC,$00,$00
		.BYTE	$F0,$BC,$40,$F8
_sprA07_6B:
		.BYTE	$04
		.BYTE	$00,$AE,$00,$F8
		.BYTE	$00,$AE,$40,$00
		.BYTE	$F0,$AC,$00,$F8
		.BYTE	$F0,$AC,$40,$00
_sprA07_6C:
		.BYTE	$01
		.BYTE	$FC,$A6,$02,$FC
_sprA07_6D:
		.BYTE	$01
		.BYTE	$FC,$A4,$42,$FC
_sprA07_6E:
		.BYTE	$01
		.BYTE	$FC,$A2,$42,$FC
_sprA07_6F:
		.BYTE	$01
		.BYTE	$FC,$A4,$02,$FC
_sprA07_70:
		.BYTE	$01
		.BYTE	$FC,$B6,$02,$FC
_sprA07_71:
		.BYTE	$01
		.BYTE	$FC,$B4,$42,$FC
_sprA07_72:
		.BYTE	$01
		.BYTE	$FC,$B2,$42,$FC
_sprA07_73:
		.BYTE	$01
		.BYTE	$FC,$B4,$02,$FC
_sprA07_74:
		.BYTE	$01
		.BYTE	$FC,$B6,$02,$FE
_sprA07_75:
		.BYTE	$01
		.BYTE	$FC,$B4,$42,$FE
_sprA07_76:
		.BYTE	$01
		.BYTE	$FC,$B2,$42,$FE
_sprA07_77:
		.BYTE	$01
		.BYTE	$FC,$B4,$02,$FE
_sprA07_78:
		.BYTE	$01
		.BYTE	$02,$B4,$02,$FB
_sprA07_79:
		.BYTE	$01
		.BYTE	$02,$A4,$02,$FA
_sprA07_7A:
		.BYTE	$01
		.BYTE	$02,$B4,$42,$FE
_sprA07_7B:
		.BYTE	$01
		.BYTE	$02,$A4,$42,$FE
_sprA07_7C:
		.BYTE	$04
		.BYTE	$08,$B4,$00,$00
		.BYTE	$08,$B4,$40,$F8
		.BYTE	$F8,$A2,$00,$00
		.BYTE	$F8,$A2,$40,$F8
_sprA07_7D:
		.BYTE	$04
		.BYTE	$08,$84,$40,$00
		.BYTE	$08,$94,$40,$F8
		.BYTE	$F9,$82,$40,$00
		.BYTE	$F9,$92,$40,$F8
_sprA07_7E:
		.BYTE	$04
		.BYTE	$08,$28,$40,$00
		.BYTE	$08,$38,$40,$F8
		.BYTE	$F8,$82,$40,$00
		.BYTE	$F8,$92,$40,$F8
_sprA07_7F:
		.BYTE	$04
		.BYTE	$08,$84,$00,$F8
		.BYTE	$08,$94,$00,$00
		.BYTE	$F9,$82,$40,$00
		.BYTE	$F9,$92,$40,$F8
_sprA07_80:
		.BYTE	$04
		.BYTE	$08,$B4,$00,$00
		.BYTE	$08,$B4,$40,$F8
		.BYTE	$F8,$B2,$00,$00
		.BYTE	$F8,$B2,$40,$F8
_sprA07_81:
		.BYTE	$04
		.BYTE	$08,$84,$40,$00
		.BYTE	$08,$94,$40,$F8
		.BYTE	$F9,$82,$00,$F8
		.BYTE	$F9,$92,$00,$00
_sprA07_82:
		.BYTE	$04
		.BYTE	$08,$28,$00,$F8
		.BYTE	$08,$38,$00,$00
		.BYTE	$F8,$82,$00,$F8
		.BYTE	$F8,$92,$00,$00
_sprA07_83:
		.BYTE	$04
		.BYTE	$08,$84,$00,$F8
		.BYTE	$08,$94,$00,$00
		.BYTE	$F9,$82,$00,$F8
		.BYTE	$F9,$92,$00,$00
_sprA07_84:
		.BYTE	$02
		.BYTE	$F8,$E0,$00,$F8
		.BYTE	$F8,$F0,$00,$00
_sprA07_85:
		.BYTE	$02
		.BYTE	$F8,$A0,$00,$F8
		.BYTE	$F8,$B0,$00,$00
_sprA07_86:
		.BYTE	$0C
		.BYTE	$00,$EA,$03,$00
		.BYTE	$00,$EA,$43,$F8
		.BYTE	$08,$DE,$03,$F8
		.BYTE	$08,$EE,$03,$00
		.BYTE	$E0,$E6,$03,$00
		.BYTE	$E0,$F6,$03,$F8
		.BYTE	$F0,$E8,$03,$00
		.BYTE	$F0,$E8,$43,$F8
		.BYTE	$F0,$F8,$03,$08
		.BYTE	$F0,$F8,$43,$F0
		.BYTE	$F8,$DC,$03,$F8
		.BYTE	$F8,$EC,$03,$00
_sprA07_87:
		.BYTE	$0B
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$FA,$FC,$03,$01
_sprA07_88:
		.BYTE	$0D
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$0A,$DA,$03,$00
		.BYTE	$0B,$CA,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
_sprA07_89:
		.BYTE	$0E
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$0E,$D8,$03,$01
		.BYTE	$15,$DA,$03,$01
		.BYTE	$16,$CA,$03,$F9
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
_sprA07_8A:
		.BYTE	$10
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$06,$D6,$03,$03
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$16,$C8,$03,$FB
		.BYTE	$16,$D8,$03,$03
		.BYTE	$24,$DA,$03,$03
		.BYTE	$26,$CA,$03,$FB
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
_sprA07_8B:
		.BYTE	$12
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$06,$D6,$03,$03
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$16,$C8,$03,$FB
		.BYTE	$16,$D8,$03,$03
		.BYTE	$24,$DA,$03,$03
		.BYTE	$26,$80,$00,$FD
		.BYTE	$26,$90,$00,$05
		.BYTE	$26,$CA,$03,$FB
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
_sprA07_8C:
		.BYTE	$10
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$0E,$D8,$03,$01
		.BYTE	$15,$DA,$03,$01
		.BYTE	$16,$80,$00,$FB
		.BYTE	$16,$90,$00,$03
		.BYTE	$16,$CA,$03,$F9
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
_sprA07_8D:
		.BYTE	$0F
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$F4,$03,$10
		.BYTE	$0B,$80,$00,$F8
		.BYTE	$0B,$90,$00,$00
		.BYTE	$0B,$CA,$03,$F8
		.BYTE	$0B,$DA,$03,$FF
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$F8,$F2,$03,$10
_sprB07_C0:
		.BYTE	$81
		.WORD	_sprB07_C0_A
_sprB07_C1:
		.BYTE	$81
		.WORD	_sprB07_C1_A
_sprB07_C2:
		.BYTE	$81
		.WORD	_sprB07_C2_A
_sprB07_C3:
		.BYTE	$81
		.WORD	_sprB07_C3_A
_sprB07_C4:
		.BYTE	$81
		.WORD	_sprB07_C4_A
_sprB07_C5:
		.BYTE	$81
		.WORD	_sprB07_C5_A
_sprB07_C6:
		.BYTE	$81
		.WORD	_sprB07_C6_A
_sprB07_C7:
		.BYTE	$81
		.WORD	_sprB07_C7_A
_sprB07_C8:
		.BYTE	$81
		.WORD	_sprB07_C8_A
_sprB07_C9:
		.BYTE	$81
		.WORD	_sprB07_C9_A
_sprB07_CA:
		.BYTE	$81
		.WORD	_sprB07_CA_A
_sprB07_C0_A:
		.BYTE	$09
		.BYTE	$D6,$EC,$00,$F0
		.BYTE	$D6,$FC,$00,$F8
		.BYTE	$DE,$C8,$00,$F4
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$FA,$C6,$03,$04
		.BYTE	$FA,$D6,$03,$F4
		.BYTE	$FA,$E6,$03,$FC
_sprB07_C1_A:
		.BYTE	$09
		.BYTE	$DA,$EC,$00,$FA
		.BYTE	$DA,$FC,$00,$02
		.BYTE	$DF,$CC,$00,$F7
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$FA,$C6,$03,$04
		.BYTE	$FA,$D6,$03,$F4
		.BYTE	$FA,$E6,$03,$FC
_sprB07_C2_A:
		.BYTE	$0A
		.BYTE	$E8,$EC,$00,$07
		.BYTE	$E8,$FC,$00,$0F
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$EA,$E0,$03,$FC
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EC,$CA,$00,$01
		.BYTE	$EC,$CA,$00,$F9
		.BYTE	$FA,$C2,$03,$04
		.BYTE	$FA,$D2,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
_sprB07_C3_A:
		.BYTE	$0A
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$EA,$E0,$03,$FC
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EF,$CC,$40,$FD
		.BYTE	$F0,$DC,$40,$F7
		.BYTE	$FA,$C2,$03,$04
		.BYTE	$FA,$D2,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$FA,$EC,$00,$03
		.BYTE	$FA,$FC,$00,$0B
_sprB07_C4_A:
		.BYTE	$0A
		.BYTE	$02,$EC,$00,$EF
		.BYTE	$02,$FC,$00,$F7
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$F0,$C8,$00,$F3
		.BYTE	$F8,$C8,$00,$F3
		.BYTE	$FA,$C4,$03,$F4
		.BYTE	$FA,$E6,$03,$FC
		.BYTE	$FA,$F6,$03,$04
_sprB07_C5_A:
		.BYTE	$0A
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$F0,$CC,$00,$E7
		.BYTE	$F0,$DC,$00,$EF
		.BYTE	$FA,$C4,$03,$F4
		.BYTE	$FA,$E6,$03,$FC
		.BYTE	$FA,$EC,$00,$DE
		.BYTE	$FA,$F6,$03,$04
		.BYTE	$FA,$FC,$00,$E6
_sprB07_C6_A:
		.BYTE	$0A
		.BYTE	$E8,$EC,$00,$D9
		.BYTE	$E8,$FC,$00,$E1
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$EA,$E0,$03,$FC
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EC,$CA,$00,$E6
		.BYTE	$EC,$CA,$00,$EE
		.BYTE	$FA,$C0,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$FA,$F2,$03,$04
_sprB07_C7_A:
		.BYTE	$09
		.BYTE	$DB,$EC,$00,$E2
		.BYTE	$DB,$FC,$00,$EA
		.BYTE	$DF,$CC,$40,$EF
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$EA,$E0,$03,$FC
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$FA,$C0,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$FA,$F2,$03,$04
_sprB07_C8_A:
		.BYTE	$06
		.BYTE	$EA,$D8,$03,$F4
		.BYTE	$EA,$E8,$03,$FC
		.BYTE	$EA,$F8,$03,$04
		.BYTE	$FA,$DA,$03,$F4
		.BYTE	$FA,$EA,$03,$FC
		.BYTE	$FA,$FA,$03,$04
_sprB07_C9_A:
		.BYTE	$09
		.BYTE	$02,$EC,$00,$F0
		.BYTE	$02,$FC,$00,$F8
		.BYTE	$EA,$D8,$03,$F4
		.BYTE	$EA,$E8,$03,$FC
		.BYTE	$EA,$F8,$03,$04
		.BYTE	$FA,$DA,$03,$F4
		.BYTE	$FA,$EA,$03,$FC
		.BYTE	$FA,$FA,$03,$04
		.BYTE	$FF,$C8,$00,$F4
_sprB07_CA_A:
		.BYTE	$09
		.BYTE	$02,$EC,$00,$F2
		.BYTE	$02,$FC,$00,$FA
		.BYTE	$EA,$D8,$03,$F6
		.BYTE	$EA,$E8,$03,$FE
		.BYTE	$EA,$F8,$03,$06
		.BYTE	$FA,$DA,$03,$F6
		.BYTE	$FA,$EA,$03,$FE
		.BYTE	$FA,$FA,$03,$06
		.BYTE	$FF,$C8,$00,$F6

		SECTION_END	"PRG4 SPRITES"

		BANK_END 4,$C000
