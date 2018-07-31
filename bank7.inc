
		ORG $C000

		BANK_START $7

		SECTION_START

		ORG [[.+$3F] & $FFC0]
_pcm0:
		.BYTE	$55,$55,$55,$95,$AA,$2A,$95,$E0,$7F,$FC,$C0,$F1,$03,$28,$FE,$FF ;	pcm data
		.BYTE	$FF,$F1,$5F,$3F,$00,$00,$00,$00,$00,$00,$08,$80,$C0,$F1,$FF,$C7
		.BYTE	$8B,$1F,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$AB,$6A,$9B,$AA,$92,$52,$25
		.BYTE	$95,$24,$25,$92,$80,$4A,$50,$05,$00,$00,$80,$20,$42,$04,$08,$E2
		.BYTE	$FF,$01,$80,$6D,$AB,$6D,$DF,$BB,$77,$7B,$AB,$AF,$DD,$D5,$7D,$DD
		.BYTE	$BF,$FF,$EF,$B6,$6D,$6F,$BB,$6D,$AF,$2A,$95,$94,$24,$49,$92,$88
_pcm0B_size	EQU [[.-_pcm0]>>4]
		.BYTE	$42,$84,$48,$88,$04,$09,$49,$92,$24,$51,$22,$A5,$92,$22,$49,$AA
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_pcm0A_size	EQU [[.-_pcm0]>>4]
_pcm0A_addr	EQU [[_pcm0-$C000]>>6]
_pcm0B_addr	EQU _pcm0A_addr

;		ECHO	"_pcm0 addr=",_pcm0_addr,"size=",_pcm0_size

		ORG [[.+$3F] & $FFC0]
_pcm1:
		.BYTE	$00,$68,$68,$00,$68,$68,$68,$68,$73,$00,$68,$68,$00,$68,$68,$68 ;	pcm data
		.BYTE	$68,$68,$68,$68,$68,$68,$68,$00,$68,$68,$00,$68,$68,$73,$00,$68
		.BYTE	$68,$00,$68,$68,$00,$68,$68,$00,$68,$68,$00,$68,$68,$00,$68,$FF
		.BYTE	$41,$10,$00,$21,$92,$20,$00,$F4,$38,$56,$5D,$EB,$F9,$9D,$3C,$BF
		.BYTE	$ED,$E7,$D7,$AA,$6C,$59,$16,$A2,$00,$61,$83,$F0,$72,$3A,$0B,$81
		.BYTE	$45,$41,$09,$DA,$F1,$FD,$FF,$FF,$5E,$AF,$C4,$4B,$D3,$C9,$8A,$82
		.BYTE	$24,$89,$28,$06,$02,$47,$55,$E1,$3D,$AE,$EF,$BC,$F4,$52,$D5,$55
		.BYTE	$BD,$BC,$7A,$1E,$57,$51,$0A,$25,$29,$A8,$A8,$38,$69,$D3,$88,$AA
		.BYTE	$18,$78,$6C,$BA,$DE,$7D,$ED,$FB,$43,$E7,$34,$4C,$2C,$25,$AD,$92
		.BYTE	$A4,$51,$A5,$C8,$62,$E2,$06,$8D,$C7,$F1,$AD,$65,$37,$B4,$AC,$5A
		.BYTE	$4D,$9F,$3E,$6D,$3C,$A5,$B2,$24,$A9,$A2,$92,$86,$A9,$44,$45,$EE
		.BYTE	$2C,$5E,$AA,$2D,$AE,$53,$9F,$4A,$9D,$3D,$4E,$8D,$3B,$8A,$A9,$E5
		.BYTE	$C8,$B2,$2C,$34,$52,$D4,$59,$B1,$D2,$8A,$55,$C3,$5B,$A9,$55,$8B
		.BYTE	$76,$7C,$79,$6C,$2B,$CE,$F2,$64,$31,$8E,$64,$45,$72,$64,$D1,$92
		.BYTE	$E3,$54,$AD,$5A,$35,$55,$D7,$58,$1E,$1D,$55,$4E,$1D,$57,$56,$55
		.BYTE	$CB,$AA,$AA,$2A,$69,$A5,$4A,$AA,$AA,$4A,$4D,$6A,$31,$4D,$D3,$A9
		.BYTE	$6A,$AD,$7A,$5C,$65,$AB,$AA,$AC,$CA,$72,$AA,$4A,$B5,$D0,$8A,$95
		.BYTE	$AC,$54,$95,$6C,$D9,$52,$5B,$A5,$AA,$D5,$4A,$B5,$2C,$4B,$B6,$D4
		.BYTE	$34,$9D,$95,$56,$55,$55,$55,$55,$9A,$2A,$15,$A7,$AA,$52,$2D,$55
		.BYTE	$69,$95,$B6,$AA,$65,$D5,$6A,$AA,$5A,$EA,$58,$55,$69,$6A,$A9,$96
		.BYTE	$D2,$34,$95,$53,$A9,$A9,$2A,$35,$55,$D3,$AA,$6A,$55,$B5,$E2,$AA
		.BYTE	$34,$B5,$9C,$C6,$B1,$95,$AA,$A9,$AA,$B4,$52,$55,$8B,$A9,$9A,$A6
		.BYTE	$AA,$9A,$5A,$6A,$A5,$56,$56,$65,$55,$55,$AD,$B4,$B2,$AA,$54,$55
		.BYTE	$2D,$D5,$AA,$AC,$AA,$52,$2B,$4B,$95,$AA,$AA,$B2,$2A,$AB,$AA,$6A
		.BYTE	$A5,$55,$D5,$B4,$AA,$AA,$AA,$A9,$AA,$AA,$52,$55,$59,$A9,$A5,$AA
		.BYTE	$56,$5A,$A5,$95,$55,$55,$55,$55,$55,$55,$55,$55,$55,$55,$55,$55
		.BYTE	$55,$55,$55,$55,$55,$55,$53,$35,$55,$D5,$54,$55,$55,$55,$A9,$A5
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_pcm1_size	EQU [[.-_pcm1]>>4]
_pcm1_addr	EQU [[_pcm1-$C000]>>6]

;		ECHO	"_pcm1 addr=",_pcm1_addr,"size=",_pcm1_size

		SECTION_END	"PCM SAMPLES"

; =============== S U B R O U T I N E ======n================================
RESET:
		INC		RESET
		LDA		#$1E
		JSR		_mmc1_ctrl
		SEI
		LDA		#$00
		STA		_PPU_CTRL
		STA		_PPU_MASK
loc_60011:
		LDA		_PPU_STATUS
		BPL		loc_60011
loc_60016:
		LDA		_PPU_STATUS
		BMI		loc_60016
loc_6001B:
		LDA		_PPU_STATUS
		BPL		loc_6001B
loc_60020:
		LDA		_PPU_STATUS
		BMI		loc_60020
		CLD
		LDX		#$FA
		TXS
		LDA		#$30
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
; REGION, the US proto version enables the left tile colums for both BG and SPRITES
;		LDA		#$1E
		LDA		#$18
; -
		STA		_ppu_mask_req
		STA		_PPU_MASK
		LDA		#$00
		STA		_chr_bank0
		STA		_chr_bank1
		STA		_apu_play_delayed_req
		STA		_mmc1_busy
		LDA		#$06
		JSR		_mmc1_prg
		JSR		_apu_reset
		LDA		#$00
		STA		_prg_cur_bank
		JSR		_mmc1_prg
		JSR		_ppu_queue_reset
		JSR		_ppu_nmi_on
		LDA		#$77
		STA		_random_seed
		STA		_random_seed+1
		LDA		#$01						; if restarting, show copyrights first
		STA		_license_screen_display_flag
		STA		_difficulty					; default difficulty is normal
		LDA		#PAD_A
		STA		_control_beam_button_code	; default controls
		LDA		#PAD_B
		STA		_control_catch_button_code
		LDA		_ram_signature				; ram signature to keep scores
		CMP		#"H"						; "HS" - HUDSON SOFT?
		BNE		loc_6007C
		LDA		_ram_signature+1
		CMP		#"S"
		BEQ		_MAIN_ENTRY
loc_6007C:
		LDA		#"H"
		STA		_ram_signature
		LDA		#"S"
		STA		_ram_signature+1
		LDA		#$64						; initial hi-scores 100(00)pts
		STA		_hi_scores
		LDA		#$00
		STA		_hi_scores+1
_MAIN_ENTRY:
		JSR		_ppu_vblank_off
		LDA		#$FF						; fill NT0 and NT1 with $FF
		LDX		#$00
		JSR		_ppu_nt_clear
		LDA		#$FF
		LDX		#$01
		JSR		_ppu_nt_clear
		JSR		_scr_trds_list_reset		; full reset threads variables
		LDA		#$00
		JSR		_event_thread_start			; load main title script
		LDA		#$00
		STA		_pause_mode_flag			; now starting the simple version of
		STA		_out_of_screen_test_flag	; threads manager
loc_600AF:
		JSR		_wait_for_nmi				; wait for nmi
		JSR		_spr_shuffle_update			; prepare sprites shuffle
		JSR		_threads_manager			; execute threads
		JSR		_spr_finish					; all sprites should be done now, finalize
		LDA		_trds_obj_idx				; repeat until main thread is stopped
		BPL		loc_600AF
_GAME_ENTRY:
		LDX		_difficulty					; this means we ready to setup game
		LDA		_scores_1st_extend_list_lo,X; load corresponding difficulty settings
		STA		_scores_1st_extend
		LDA		_scores_1st_extend_list_hi,X
		STA		_scores_1st_extend+1
		LDA		_scores_2nd_extend_list_lo,X
		STA		_scores_2nd_extend
		LDA		_scores_2nd_extend_list_hi,X
		STA		_scores_2nd_extend+1
		LDA		#$04						; init continues
		STA		_continues
#if DEBUG==1
		LDA		#DEBUG_LEVEL
		STA		_level
		LDA		#DEBUG_CHKPOINT
		STA		_lvl_last_checkpoint_idx
#else
		LDA		#$00						; also set default level and checkpoint
		STA		_level
		LDA		#$01
		STA		_lvl_last_checkpoint_idx	; note, value is +1 here
#endif
_MAIN_GAME_LOOP:
		LDA		#$00						; continue initing the other game vars
		STA		_mmc1_busy
		STA		_apu_play_delayed_req
		STA		_scores
		STA		_scores+1
;		STA		_unused_var					; REDUNDANT, removed
		LDA		_scores_1st_extend			; load first extend value
		STA		_scores_to_next_life
		LDA		_scores_1st_extend+1
		STA		_scores_to_next_life+1
		LDA		#$01						; out-of-screen check activate
		STA		_out_of_screen_test_flag
		LDA		#$04
		SEC
		SBC		_difficulty
		STA		_players_lives				; init lives
#if TWO_PLAYER_MODE==1
		STA		_players_lives+1
#endif
loc_60112:
		LDA		#$00
		STA		_lvl_cur_checkpoint_idx
		JSR		_scr_trds_list_reset		; one more cleanup of threads lists
		LDX		_level
		LDA		_lvl_scripts_list,X			; now load the level script idx
		JSR		_event_thread_start			; and start main level thread
loc_60123:
		JSR		_wait_for_nmi				; main ingame loop goes here
#if DEBUG==1
		LDA		_ppu_mask_shadow
		EOR		#$02
		STA		_PPU_MASK
#endif
;		LDA		#$00						; REDUNDANT, initialized inside
;		STA		_cur_room_doors_cnt
		JSR		_spr_shuffle_update			; all mostly the same as simple loop above
		JSR		_threads_manager			; but with extra special inits
		JSR		_spr_finish					; finalize sprites when done
		JSR		_obj_exit_arrow_position_adjust	; also extra object arrow test here
		JSR		_obj_garbage_collector		; special garbage collector
#if DEBUG==1
		LDA		_ppu_mask_shadow
		STA		_PPU_MASK
#endif
		LDA		_trds_obj_idx				; if main thread stopped, then stage completed
		BPL		loc_60123
		LDA		_game_flags					; also to complete stage you nedd $80 value here
		BPL		loc_6015A					; if not, just restart the game from the beginnging
		LDA		#$01
		STA		_lvl_last_checkpoint_idx	; reinit checkpoint for next level
		INC		_level						; increment level
;		LDA		_level						; REDUNDANT
;		CMP		#$07						; there are levels at $00 to $05 and ending
;		BCC		loc_60112					; at $06 values, there is no extra values above $06
;		LDA		#$00						; so this is a debug leftover from dev stage
;		STA		_level						; most probably meant to be used by stage skip routine
;		BEQ		loc_60112
		JMP		loc_60112
loc_6015A:
		BNE		_MAIN_GAME_LOOP				; this is the case to return after ending
		JMP		_MAIN_ENTRY

_lvl_scripts_list:
		.BYTE	_scr01_lvl1_handler_idx
		.BYTE	_scr02_lvl2_handler_idx
		.BYTE	_scr03_lvl3_handler_idx
		.BYTE	_scr04_lvl4_handler_idx
		.BYTE	_scr05_lvl5_handler_idx
		.BYTE	_scr06_lvl6_handler_idx
		.BYTE	_scr07_ending_idx

; =============== S U B R O U T I N E ======n================================
; very specific case to handle here. sometimes, they catch the object
; while beamer moving out of the screen, catcher and such object disappear.
; but since objects thread is suspended, but catcher only driven not
; suspendable native routine, catcher stop catching and return back to the
; beamer, when they both return to the previous location, you'll see
; the catch animation played alone in air. this routine prevents this
; kind of cases. its just search for any object in catching process
; out of the screen and removes them.
;
; NOTE: you lose the scores in such cases!.
;
_obj_garbage_collector:
		LDX		#$06
loc_60168:
		LDA		_trds_obj_idx,X
		BMI		loc_60193
		LDA		_trds_args0,X
		BPL		loc_60193
		LDA		_obj_out_of_screen,X
		BEQ		loc_60193
		LDA		#$FF
		STA		_trds_obj_idx,X
loc_60193:
		INX
		CPX		#$0E
		BCC		loc_60168
		RTS

_scores_1st_extend_list_lo:
		.BYTE	<[ 50]	; 00
		.BYTE	<[100]	; 00
		.BYTE	<[150]	; 00
		.BYTE	<[200]	; 00
_scores_1st_extend_list_hi:
		.BYTE	>[ 05]	; 00
		.BYTE	>[100]	; 00
		.BYTE	>[150]	; 00
		.BYTE	>[200]	; 00
_scores_2nd_extend_list_lo:
		.BYTE	<[200]	; 00
		.BYTE	<[300]	; 00
		.BYTE	<[400]	; 00
		.BYTE	<[500]	; 00
_scores_2nd_extend_list_hi:
		.BYTE	>[200]	; 00
		.BYTE	>[300]	; 00
		.BYTE	>[400]	; 00
		.BYTE	>[500]	; 00

; =============== S U B R O U T I N E ======n================================
_obj_exit_arrow_position_adjust:
		LDA		#$FF						; signal flags reset
		STA		_var0
		STA		_var1
		LDX		#$06
loc_601B1:
		LDA		_trds_obj_idx,X				; look for active objects
		BMI		loc_601C4
		CMP		#_scr13_slow_moving_slime_idx	; all above are enemies,
		BCS		loc_601C2					; increment enemies counter
		CMP		#_scr12_exit_arrow_idx		; if arrow, then
		BNE		loc_601C4					; store it's slot idx
		STX		_var0
		BEQ		loc_601C4
loc_601C2:
		INC		_var1
loc_601C4:
		INX
		CPX		#$0E
		BCC		loc_601B1
		LDA		_var1
		BPL		locret_601F6				; if any enemies in the room, skip
		LDX		_var0
		BMI		locret_601F6				; if there are no arrow in the room, skip
		LDA		_ppu_scroll_pos_x			; if arrow deployed, calculate current
		CLC									; coordinates for screen center
		ADC		#$80						; and set the arrow position there
		STA		_obj_x_pos_lo,X				; it is always positioned in the center
		LDA		_ppu_scroll_pos_x+1
		ADC		#$00
		STA		_obj_x_pos_hi,X				; so this method allows to show an arrow
		LDA		_ppu_scroll_pos_y			; object in a particular cases, despite
		CLC									; it's always active in room...
		ADC		#$78
		BCS		loc_601EA
		CMP		#$F0
		BCC		loc_601ED
loc_601EA:
		ADC		#$0F
		SEC
loc_601ED:
		STA		_obj_y_pos_lo,X
		LDA		_ppu_scroll_pos_y+1
		ADC		#$00
		STA		_obj_y_pos_hi,X
locret_601F6:
		RTS

; =============== S C R I P T ==========================s====================
; NOTE: the arrow object is always in the room and always blinking, but
; since it inserted to the room with zero cooridnates, it is always
; clipped by sprite engine
;
_scr12_exit_arrow:
		NBG_HNDL_SET	_nbgsub_exit_arrow_off_test
_sloc_601FA:
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; blink sprite constantly
			NARGB		SARG1
		SDELAY			$07
		SPR_IDX_SET		7,$FF
		SJMPS			_sloc_601FA

; =============== S U B R O U T I N E ======n================================
_nbgsub_exit_arrow_off_test:
		LDX		_cur_trd_slot				; the arrow sarg2 parameter contains
		LDA		_trds_args2,X				; an index of next room where the
		CMP		_cur_lvl_room_idx			; arrow should disappear, test it here
		BEQ		loc_6020F					; and off current thread if test passed
		RTS
loc_6020F:
		JMP		_scr_cur_trd_off

; =============== S C R I P T ==========================s====================
_scr08_beamer_handler:
		STORE8			_players_hit_flag,$00			; set when hit by ghost
		STORE8			_players_inv_timer,$00			; set when restores after hit
		STORE16			_beamer_speed,$180				; initial value for speed
		NJSR			_nsub_beamer_spr_base_reset		; copy tmp value to current index

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_beamer_reinit:
		NJSR			_nsub_mcmp						; special test for additional handler.
			NARGW		_trds_obj_idx					; after setting the control routines
			NARGB		$04								; this thread is suspended
		SBCCS			_sloc_6029B						; but object still active and controlled
		NBG_HNDL_SET	_nbgsub_beamer_controlB			; purely by native subroutine
		SUSPEND
_sloc_6029B:
		NBG_HNDL_SET	_nbgsub_beamer_controlA
		SUSPEND

#if TWO_PLAYER_MODE==1
; =============== S C R I P T ==========================s====================
_scr_beamer_hit_anim:
		SJSRS			_ssub_common_hit_anim
		SBCCS			_scr_beamer_reinit
		SSTOP

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_hit_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd04_idx
		SLOOP_BEGIN		$1E
		NJSR			_nsub_beamer_hit_spr_select
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$40
		SLOOP_END
		NJSR			_nsub_spr_dir_select
			NARGB		$A0,$40
		SDELAY			$02
		SPR_IDX_ADD_IMM 2,$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 2,$FC
		SPR_IDX_ADD_IMM 0,$FC
		SDELAY			$28
		SPR_IDX_SET		0,$FF
		SDELAY			$3C
		NJSR			_nsub_beamer_decrement_players_lives
		SRET
#else
; =============== S C R I P T ==========================s====================
; called from native routine, replaces previously suspended thread
; above, will return the control to it if has lives.
;
_scr_beamer_hit_anim:
		NJSR			_nsub_apu_snd_load				; start hit sound and do rotating
			NARGB		_snd04_idx						; animation
		SLOOP_BEGIN		$1E
		NJSR			_nsub_beamer_hit_spr_select
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$40
		SLOOP_END
		NJSR			_nsub_spr_dir_select			; draw dead body in opposite
			NARGB		$A0,$40							; direction you faced while being hit
		SDELAY			$02
		SPR_IDX_ADD_IMM 2,$04							; animate last breath, remove sprite.
		SPR_IDX_ADD_IMM 4,$04							; beacause of that weird behaviour
		SPR_IDX_ADD_IMM 2,$FC							; player will turn in opposite directions
		SPR_IDX_ADD_IMM 0,$FC							; after every hit.
		SDELAY			$28
		SPR_IDX_SET		0,$FF
		SDELAY			$3C
		NJSR			_nsub_beamer_decrement_players_lives	; if lives is over, stop thread
		SBCCS			_scr_beamer_reinit				; or restore object
		SSTOP
#endif

; =============== S C R I P T ==========================s====================
; TODO: last room before lvl3 "boss" is empty. you may walk it fast or slow.
; there is an unused track for this area but it is non-looped and too long
; for the whole scene. but it is possible to implement another script
; which will walk this last room for fixed timing, then show the cutscene,
; so full music may fit there.
;
_scr_lvl3_beamer_auto_script:
		POS_X_SET		0,$40,$00						; stand still while ghost nanny does its
		POS_Y_SET		0,$C8,$02						; work
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$40
		NJSR			_nsub_beamer_spr_idx_calc
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_lvl6_beamer_auto_scriptA:
		POS_Y_DELTA_SET 0,$80,$FF						; setup anim for slow walk up
		SLOOP_BEGIN		$F0								; do walk for 240 cycles
		SARG_ALU		SARG0,_ADC,$01					; set players spr type (walk up)
		NJSR			_nsub_beamer_spr_idx_calc		; calculate animation sprite idx and set
		SDELAY			$02
		SLOOP_END
		POS_MOVE_STOP	0								; stop when done, then return control
		SJMPS			_scr08_beamer_handler			; to the main beamer script

; =============== S C R I P T ==========================s====================
_scr_lvl6_beamer_auto_scriptB:
		NJSR			_nsub_beamer_spr_idx_calc		; first player stand still, then change
		SDELAY			$78								; direction and move down out of screen
		SARG_SET		SARG1,$80
		POS_Y_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$F0
		SARG_ALU		SARG0,_ADC,$01
		NJSR			_nsub_beamer_spr_idx_calc
		SDELAY			$01
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
; this used for other cases when players must do nothing, just dummy script
; with no nbgsub set (when called as a new thread start, which resets all
; parameters including setting the dummy nbgsub by default)
;
_scr_suspend:
		SUSPEND

; =============== S U B R O U T I N E ======n================================
; only for lvl4 here additionaly adjusting the player speed according
; to room meta tiles
;
_nbgsub_beamer_controlB:
		JSR		_lvl4_beamer_speed_modifier_calc

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nbgsub_beamer_controlA:
		LDA		_players_hit_flag			; regular beamer player native handler
		LSR									; test for collision flag is set
		BCC		loc_60316
		JSR		_cur_thread_reload_param
		.WORD	_scr_beamer_hit_anim
		RTS
loc_60316:
		LDA		_players_inv_timer			; also run after hit timer
		BEQ		loc_6031E
		DEC		_players_inv_timer
loc_6031E:
		JSR		_beamer_control_move_test
		JSR		_beamer_spr_selector
		JMP		_beamer_control_beam_test	; and finally insert the beam object

; =============== S U B R O U T I N E ======n================================
_lvl4_beamer_speed_modifier_calc:
		JSR		_lvl4_speed_modifier_calc
		STA		_beamer_speed
		STY		_beamer_speed+1
		LDA		_beamer_spr_base_tmp
		BCC		loc_60337
		ADC		#$4F
loc_60337:
		STA		_beamer_spr_base
		RTS

; =============== S U B R O U T I N E ======n================================
_lvl4_catcher_speed_modifier_calc:
		JSR		_lvl4_speed_modifier_calc
		STA		_catcher_speed
		STY		_catcher_speed+1
		LDA		_catcher_spr_base_tmp
		BCC		loc_6034B
		ADC		#$4F
loc_6034B:
		STA		_catcher_spr_base
		RTS

; =============== S U B R O U T I N E ======n================================
; this routine used on sewers level to adjust (spped up or slow down) the
; player's speed if they walking on a particular meta tiles.
;
_lvl4_speed_modifier_calc:
		LDX		_cur_trd_slot
		LDA		_obj_y_pos_lo,X				; calculate currently hovered meta pos
		CLC
		ADC		#$04
		TAY
		LDA		_obj_y_pos_hi,X
		ADC		#$00
		STA		_tmp_var1
		LDA		_obj_x_pos_hi,X
		STA		_tmp_var0
		LDA		_obj_x_pos_lo,X
		TAX
		JSR		_far_room_macro_block_read	; read room data, test if meta is in
		BEQ		loc_60388					; needed range ($01-$0C)
		CMP		#$0D
		BCS		loc_60388
		TAX
		LDA		byte_6038E-1,X				; get the corresponding speed movifier index
		PHA
		JSR		_nsub_sarg1_direction_extract	; also get the player's move direction
		STA		_tmp0
		PLA
		SEC
		SBC		_tmp0						; calculate final speed modifier
		AND		#$03
		TAX
		LDA		byte_6039A,X				; read the speed value from table
		LDY		byte_6039E,X				; 0-regular speed, 1,3 - slow, 2 - very slow
		SEC
		RTS
loc_60388:
		LDA		#$80
		LDY		#$01
		CLC
		RTS
byte_6038E:
		.BYTE	$02,$02,$02,$00,$00,$00,$01,$01,$01,$03,$03,$03
byte_6039A:
		.BYTE	$80,$00,$C0,$00
byte_6039E:
		.BYTE	$01,$01,$00,$01

; =============== S U B R O U T I N E ======n================================
_nsub_beamer_spr_base_reset:
		LDA		_beamer_spr_base_tmp
		STA		_beamer_spr_base
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_beamer_decrement_players_lives:
#if TWO_PLAYER_MODE==1
		LDX		_cur_trd_slot
		LDA		_trds_args2,X
		TAX
		DEC		_players_lives,X
#else
		DEC		_players_lives				; if lives is over, return C=1
#endif
		BNE		loc_603B7					; to stop beamer thread also start
		LDX		#$00						; game over script instatnly
		JSR		_thread_reload_param_ex
		.WORD	_scr_game_over
		SEC
		RTS
loc_603B7:
#if TWO_PLAYER_MODE==1
		LDX		_cur_trd_slot
		LDA		_trds_args2,X
		TAX
		LDA		#$00						; otherwise, clear hit flag
		STA		_players_hit_flag,X
		LDA		#$78						; init temporary invulnerability
		STA		_players_inv_timer,X
#else
		LDA		#$00						; otherwise, clear hit flag
		STA		_players_hit_flag
		LDA		#$78						; init temporary invulnerability
		STA		_players_inv_timer
#endif
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_beamer_control_move_test:
		LDA		_obj_x_pos_lo+2				; these objects moving only by 8
		ORA		_obj_y_pos_lo+2				; pixels at once, when start to
		AND		#$07						; move, you couldn't control it unless
		BNE		.beamer_speed_calc			; it reaches another gap
		LDA		_pad0_held
		AND		#$0F
		BEQ		.beamer_speed_reset
		JSR		_beamer_direction_calc		; get pressed button and calc new movement
		LDA		_beamer_direction_idx		; direction
		JSR		_players_move_obstacles_test; then test if any obstacles there
		BCS		.beamer_speed_reset
.beamer_speed_calc:
		LDA		_beamer_direction_idx		; according to speed and face direction
		LDX		_beamer_speed				; adjust current position of players
		LDY		_beamer_speed+1				; to be always at the middle of the screen
		JSR		_players_speed_calc
		TAY
		BEQ		.beamer_exit
		BNE		.beamer_step
.beamer_next_step:
		LDA		_obj_x_pos_lo+2				; while doing other steps, also test
		ORA		_obj_y_pos_lo+2				; controls only at 8x8 pixels grid
		AND		#$07
		BNE		.beamer_step
		LDA		_pad0_held
		AND		#$0F
		BEQ		.beamer_speed_reset
		JSR		_beamer_direction_calc
		LDA		_beamer_direction_idx
		JSR		_players_move_obstacles_test
		BCC		.beamer_step
.beamer_speed_reset:
		LDA		#$80
		STA		_obj_x_clk+2
		STA		_obj_y_clk+2
		BNE		.beamer_exit
.beamer_step:
		LDA		_beamer_direction_idx		; beamer direction determined only by
		JSR		_players_move_step			; player's input, do one step in given
#if TWO_PLAYER_MODE==1
		LDX		_beamer_direction_idx		; beamer direction determined only by
#endif
		JSR		_beamer_scroll_step			; direction, additionally set scroll if
		DEY									; available. Y here is number of steps
		BNE		.beamer_next_step			; for starting move
.beamer_exit:
		RTS

; =============== S U B R O U T I N E ======n================================
; NOTE: it seems this routine kinda redundant, i can't see any level where
; you may go out of the screen. even the tonnels level and vega boss levels
; are used additional macro-obstacles to not to let the players to get near
; the screen edges. also this test only used for beamer which can't go out
; of the screen because of exits...
;
; only the visible purpose for this routine is in two player mode, where
; restraint conditions for scroll does not work in the middle of the room
;
; also there is a problem with go out of screen between two rooms, the
; player object may be locked there. but this is most probably because of
; my later fixes to screen positions calculations... lol
;
_players_move_obstacles_test:
#if TWO_PLAYER_MODE==1
		PHA
		TYA
		PHA
		LDX		_cur_trd_slot
		LDA		_obj_x_screen_pos,X			; read the beamer screen position
		STA		_tmp1						; preventing walking it out of the
		LDA		_obj_y_screen_pos,X			; screen
		STA		_tmp2
		PLA
		TAY
		PLA
		STA		_tmp0
		TAX
		BNE		loc_60437
		LDA		_tmp2
		CMP		#$10						; FIX, players from infiltrating the
		BCS		loc_60455					; edges of the screen sometimes
		BCC		loc_60453
loc_60437:
		DEX
		BNE		loc_60442
		LDA		_tmp1
		CMP		#$F0						; FIX, the same
		BCC		loc_60455
		BCS		loc_60453
loc_60442:
		DEX
		BNE		loc_6044D
		LDA		_tmp2
		CMP		#$E0						; FIX, the same
		BCC		loc_60455
		BCS		loc_60453
loc_6044D:
		LDA		_tmp1
		CMP		#$10						; FIX, the same
		BCS		loc_60455					; walkable area hardwritten as $09-$F8, $09-$E8
loc_60453:
		SEC
		RTS
loc_60455:
		LDA		_tmp0						; then test for obstacles in selected direction
#endif
		JMP		_players_bound_box_to_room_test

#if TWO_PLAYER_MODE==1
; NOTE: here is an updated version of scroll adjust test for 2P mode
; by new logic both players could affect scroll. new scroll test routine
; uses additionally current movement direction for player to determine
; what scroll need adjustement. so now both players can move scroll
; when crossing the center of the screen but both need to be on the same
; screen at once. leaving the screen for one of them will cause wrong
; collision detection otherwise.
;
; =============== S U B R O U T I N E ======n================================
_catcher_scroll_step:
		TYA									; backup Y to be Y safe routine
		PHA									; X = direction of movement (different
		TXA									; than face direction)
		LDX		#$02						; catcher calculates distance to beamer
		BNE		_players_scroll_step

; =============== S U B R O U T I N E ======n================================
_beamer_scroll_step:
		TYA
		PHA
		TXA
		LDX		#$04						; beamer calculates distance to catcher

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_players_scroll_step:
		STA		_tmp1C
		LDY		#$70
		JSR		_obj_to_obj_in_range_test
		BCC		.scroll_step_exit
		LDX		_cur_trd_slot
		LDY		_obj_y_screen_pos,X
		LDA		_obj_x_screen_pos,X
		TAX
		DEC		_tmp1C
		BPL		loc_6047D
		CPY		#$78
		BCS		.scroll_step_exit
		LDA		_ppu_scroll_pos_y			; 0 scroll up
		BNE		loc_604A1
		LDA		_ppu_scroll_pos_y+1
		CMP		_cur_room_x_pageA
		BEQ		.scroll_step_exit
loc_604A1:
		LDA		_ppu_scroll_pos_y
		SEC
		SBC		#$01
		BCS		loc_604AC
		SBC		#$0F
		DEC		_ppu_scroll_pos_y+1
loc_604AC:
		STA		_ppu_scroll_pos_y
		BCS		.scroll_step_exit
loc_6047D:
		DEC		_tmp1C
		BPL		loc_60490
		CPX		#$80
		BCC		.scroll_step_exit
		LDA		_ppu_scroll_pos_x			; 1 scroll right
		BNE		loc_60488
		LDA		_ppu_scroll_pos_x+1
		CMP		_cur_room_y_pageA
		BEQ		.scroll_step_exit
loc_60488:
		INC		_ppu_scroll_pos_x
		BNE		.scroll_step_exit
		INC		_ppu_scroll_pos_x+1
		BPL		.scroll_step_exit
loc_60490:
		DEC		_tmp1C
		BPL		loc_604B0
		CPY		#$78
		BCC		.scroll_step_exit
		LDA		_ppu_scroll_pos_y			; 2 scroll down
		BNE		loc_604BB
		LDA		_ppu_scroll_pos_y+1
		CMP		_cur_room_x_pageB
		BEQ		.scroll_step_exit
loc_604BB:
		LDA		_ppu_scroll_pos_y
		CLC
		ADC		#$01
		CMP		#$F0
		BCC		loc_604C8
		ADC		#$0F
		INC		_ppu_scroll_pos_y+1
loc_604C8:
		STA		_ppu_scroll_pos_y
		BPL		.scroll_step_exit
loc_604B0:
		CPX		#$80
		BCS		.scroll_step_exit
		LDA		_ppu_scroll_pos_x			; 3 scroll left
		BNE		loc_60470
		LDA		_ppu_scroll_pos_x+1
		CMP		_cur_room_y_pageB
		BEQ		.scroll_step_exit
loc_60470:
		LDA		_ppu_scroll_pos_x
		SEC
		SBC		#$01
		STA		_ppu_scroll_pos_x
		BCS		.scroll_step_exit
		DEC		_ppu_scroll_pos_x+1
.scroll_step_exit:
		PLA
		TAY
		RTS
#else
; =============== S U B R O U T I N E ======n================================
_beamer_scroll_step:
		TYA
		PHA
		LDX		_cur_trd_slot				; get beamer screen position and check
		LDY		_obj_y_screen_pos,X			; if it scroll move needed
		LDA		_obj_x_screen_pos,X
		TAX
		CPX		#$80
		BEQ		loc_60490
		BCS		loc_6047D
		LDA		_ppu_scroll_pos_x			; test for scroll limit
		BNE		loc_60470
		LDA		_ppu_scroll_pos_x+1
		CMP		_cur_room_y_pageB
		BEQ		loc_60490
loc_60470:
		LDA		_ppu_scroll_pos_x			; if there is a scroll available, move it
		SEC
		SBC		#$01
		STA		_ppu_scroll_pos_x
		BCS		loc_60490
		DEC		_ppu_scroll_pos_x+1
		BPL		loc_60490
loc_6047D:
		LDA		_ppu_scroll_pos_x
		BNE		loc_60488
		LDA		_ppu_scroll_pos_x+1
		CMP		_cur_room_y_pageA
		BEQ		loc_60490
loc_60488:
		INC		_ppu_scroll_pos_x
		BNE		loc_60490
		INC		_ppu_scroll_pos_x+1
		BPL		loc_60490
loc_60490:
		CPY		#$78						; if already centered, do nothing
		BEQ		.scroll_step_exit
		BCS		loc_604B0
		LDA		_ppu_scroll_pos_y
		BNE		loc_604A1
		LDA		_ppu_scroll_pos_y+1
		CMP		_cur_room_x_pageA
		BEQ		.scroll_step_exit
loc_604A1:
		LDA		_ppu_scroll_pos_y
		SEC
		SBC		#$01
		BCS		loc_604AC
		SBC		#$0F
		DEC		_ppu_scroll_pos_y+1
loc_604AC:
		STA		_ppu_scroll_pos_y
		BCS		.scroll_step_exit
loc_604B0:
		LDA		_ppu_scroll_pos_y
		BNE		loc_604BB
		LDA		_ppu_scroll_pos_y+1
		CMP		_cur_room_x_pageB
		BEQ		.scroll_step_exit
loc_604BB:
		LDA		_ppu_scroll_pos_y
		CLC
		ADC		#$01
		CMP		#$F0
		BCC		loc_604C8
		ADC		#$0F
		INC		_ppu_scroll_pos_y+1
loc_604C8:
		STA		_ppu_scroll_pos_y
.scroll_step_exit:
		PLA
		TAY
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_nsub_sarg1_direction_extract:
		LDX		_cur_trd_slot				; get the direction bits of the obj
		LDA		_trds_args1,X				; orientation value
		ASL
		ROL
		ROL
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_sarg1_direction_update:
		PHA									; put back orientation value
		LDY		_cur_trd_slot
		LSR
		ROR
		ROR
		STA		_trds_args1,Y
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
_players_bound_box_to_room_test:
		PHA
		TAX
		TYA
		PHA
		LDA		off_604F1,X					; this is lib of the bounding boxes for
		LDY		off_604F5,X					; player objects for all directions
		JSR		_obj_to_room_bound_box_ctest
		PLA
		TAY
		PLA
		RTS
off_604F1:
		.BYTE	<[byte_604F9]
		.BYTE	<[byte_604FE]
		.BYTE	<[byte_60503]
		.BYTE	<[byte_60508]
off_604F5:
		.BYTE	>[byte_604F9]
		.BYTE	>[byte_604FE]
		.BYTE	>[byte_60503]
		.BYTE	>[byte_60508]
byte_604F9:
		.BYTE	$02
		.BYTE	$F8,$F0
		.BYTE	$00,$F0
byte_604FE:
		.BYTE	$02
		.BYTE	$08,$F8
		.BYTE	$08,$00
byte_60503:
		.BYTE	$02
		.BYTE	$F8,$08
		.BYTE	$00,$08
byte_60508:
		.BYTE	$02
		.BYTE	$F0,$F8
		.BYTE	$F0,$00

; =============== S U B R O U T I N E ======n================================
_players_speed_calc:
		STX		_var0
		STY		_var1
		LDX		_cur_trd_slot
		TAY
		BNE		loc_60523
		LDA		_obj_y_clk,X
		SEC
		SBC		_var0
		STA		_obj_y_clk,X
		BCS		loc_60550
		BCC		loc_6054E
loc_60523:
		DEY
		BNE		loc_60533
		LDA		_obj_x_clk,X
		CLC
		ADC		_var0
		STA		_obj_x_clk,X
		BCC		loc_60550
		BCS		loc_6054E
loc_60533:
		DEY
		BNE		loc_60543
		LDA		_obj_y_clk,X
		CLC
		ADC		_var0
		STA		_obj_y_clk,X
		BCC		loc_60550
		BCS		loc_6054E
loc_60543:
		LDA		_obj_x_clk,X
		SEC
		SBC		_var0
		STA		_obj_x_clk,X
		BCS		loc_60550
loc_6054E:
		INC		_var1
loc_60550:
		LDA		_var1
		RTS

; =============== S U B R O U T I N E ======n================================
; this routine adjust players position for continuous walking when
; D-Pad button is pressed once. so player objects can only walk by
; some kind of grid, moving automatically between edges.
;
_players_move_step:
		STA		_tmp0
		LDX		_cur_trd_slot
		DEC		_tmp0
		BPL		loc_6056A
		LDA		_obj_y_pos_lo,X
		SEC
		SBC		#$01
		BCS		loc_60567
		SBC		#$0F
		DEC		_obj_y_pos_hi,X
loc_60567:
		STA		_obj_y_pos_lo,X
		RTS
loc_6056A:
		DEC		_tmp0
		BPL		loc_60576
		INC		_obj_x_pos_lo,X
		BNE		locret_60575
		INC		_obj_x_pos_hi,X
locret_60575:
		RTS
loc_60576:
		DEC		_tmp0
		BPL		loc_6058B
		LDA		_obj_y_pos_lo,X
		CLC
		ADC		#$01
		CMP		#$F0
		BCC		loc_60588
		ADC		#$0F
		INC		_obj_y_pos_hi,X
loc_60588:
		STA		_obj_y_pos_lo,X
		RTS
loc_6058B:
		LDA		_obj_x_pos_lo,X
		SEC
		SBC		#$01
		BCS		loc_60595
		DEC		_obj_x_pos_hi,X
loc_60595:
		STA		_obj_x_pos_lo,X
		RTS

#if TWO_PLAYER_MODE==1
; =============== S U B R O U T I N E ======n================================
_beamer_direction_calc:
_catcher_direction_calc:
		TYA
		PHA
		LDX		_cur_trd_slot
		LDY		_trds_args2,X
		LDA		_pad0_held,Y
		LSR
		BCC		loc_605AC
		LDA		#$40
		BNE		loc_605BE
loc_605AC:
		LSR
		BCC		loc_605A2
		LDA		#$C0
		BNE		loc_605BE
loc_605A2:
		LSR
		BCC		loc_605B6
		LDA		#$80
		BNE		loc_605BE
loc_605B6:
		LSR
		BCC		locret_605C6
		LDA		#$00
loc_605BE:
		STA		_trds_args1,X
		ASL
		ROL
		ROL
		STA		_beamer_direction_idx,Y
locret_605C6:
		PLA
		TAY
		RTS
#else
; =============== S U B R O U T I N E ======n================================
; TODO: there is a problem with such method of D-Pad test, a priority.
; if you hold one button and then press and hold another, you may not
; move in a new direction, because previous button has a priority
; and handled first.
; here is a table for this routine:
;
; LEFT+UP	=UP
; LEFT+DOWN	=DOWN
; RIGHT+UP	=UP
; RIGHT+DOWN=RIGHT
; UP+RIGHT	=UP
; UP+LEFT	=UP
; DOWN+LEFT =DOWN
; DOWN+RIGHT=RIGHT
;
; the main problem here is to deterine what button is held last
;
_beamer_direction_calc:
		LDA		_pad0_held					; set base sprite direction as well
		AND		#$08						; as update beaber direction tmp idx
		BEQ		loc_605A2
		LDA		#$00
		BEQ		loc_605BE
loc_605A2:
		LDA		_pad0_held
		AND		#$01
		BEQ		loc_605AC
		LDA		#$40
		BNE		loc_605BE
loc_605AC:
		LDA		_pad0_held
		AND		#$04
		BEQ		loc_605B6
		LDA		#$80
		BNE		loc_605BE
loc_605B6:
		LDA		_pad0_held
		AND		#$02
		BEQ		locret_605C6
		LDA		#$C0
loc_605BE:
		STA		_trds_args1+2
		ASL
		ROL
		ROL
		STA		_beamer_direction_idx
locret_605C6:
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_beamer_spr_selector:
		LDA		_trds_obj_idx+3				; if beam is deployed
		BMI		loc_605D5					; adjust the beamer sprite and direction
		LDA		_trds_args0+3
		BMI		loc_605D5
		JSR		_obj_to_obj_dir_calc
		STA		_trds_args1+2
loc_605D5:
		LDA		_pad0_held
		AND		#$0F
		BEQ		loc_605DD
		INC		_trds_args0+2
loc_605DD:
		LDA		_players_inv_timer			; otherwise just select either empty
		LSR									; sprite if blinked or actual beamer sprite
		BCC		_nsub_beamer_spr_idx_calc	; beamer object will be displayed as
		LDA		#$FF						; regular objects after thread manager finished
		STA		_obj_spr_idx+2				; with all other threads
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_beamer_spr_idx_calc:
		LDA		_beamer_spr_base

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_players_spr_idx_calc:
		STA		_tmp0
		LDX		_cur_trd_slot
		LDA		_trds_args1,X
		CLC
		ADC		#$20
		AND		#$C0
		LSR
		LSR
		LSR
		LSR
		STA		_var0
		LDA		_trds_args0,X
		AND		#$0C
		LSR
		LSR
		ADC		_var0
		ADC		_tmp0
		STA		_obj_spr_idx,X
		RTS

; =============== S U B R O U T I N E ======n================================
_beamer_control_beam_test:
		LDA		_pad0_pressed
		AND		_control_beam_button_code	; reploy beam object if beam button
		BEQ		locret_60622				; pressed, also if there is no
		LDA		_trds_obj_idx+3				; beam object already deployed
		BPL		locret_60622
		LDA		#$03						; slot start (always here!)
		STA		_var4
		LDA		#$04						; slot max (only one slot)
		STA		_var5
		LDA		#_scr09_player_beam_idx
		JSR		_thread_lib_load
locret_60622:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_beamer_hit_spr_select:
#if TWO_PLAYER_MODE==1
		LDX		_cur_trd_slot
		LDA		_trds_args2,X
		TAX
		LDA		_beamer_spr_base,X
#else
		LDA		_beamer_spr_base
#endif
		STA		_tmp0
		LDX		_cur_trd_slot
		LDA		_trds_args1,X
		CLC
		ADC		#$20
		AND		#$C0
		LSR
		LSR
		LSR
		LSR
		ADC		_tmp0
		STA		_obj_spr_idx,X
		RTS

; =============== S C R I P T ==========================s====================
_scr09_player_beam:
		NBG_HNDL_SET	_nbgsub_beam_input_control		; keep beamer input working
		SARG_SET		SARG0,$FF						; there is no beamed obkects yet
		SLOOP_BEGIN		$14								; when started, lasts for 20 frames (1/3 sec)
		NJSR			_nsub_beam_idle_draw			; if no object catched
		SDELAY			$01								; while doing this, update beam target and spr
		SLOOP_END										; then disappear automatically
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_beam_active:
		NBG_HNDL_SET	_nbgsub_beam_input_control		; when someone catched, turns to this mode
		SLOOP_BEGIN		$F0								; catched state lasts from 240 cycles (4 sec)
		NJSR			_nsub_beam_active_draw			; draw elastic beam unless out of screen or
		SBCS_BREAK		_sloc_60C9F						; too long, then break
		SDELAY			$01
		SLOOP_END										; when exceeded, break also
_sloc_60C9F:
		NJSR			_nsub_obj_to_beam_release_test	; final test if someone catched ghost, if no, release it
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_beam_input_control:
		LDA		_pad0_held					; test if beamer still held the button
		AND		_control_beam_button_code
		BEQ		loc_60CD0
		LDA		_players_hit_flag			; also test if beamer not hit
		BNE		loc_60CD0
		LDA		_apu_cur_snd_idx			; check if current se is a beam sound
		CMP		#_snd00_idx
		BNE		loc_60CBB
		LDA		_apu_var400					; additional check if sound done playing
		BNE		loc_60CC0
loc_60CBB:
		LDA		#_snd00_idx					; in both cases restart beam sound
		JSR		_far_prg6_apu_snd_load
loc_60CC0:
		LDX		_trds_args0+3				; fetch beamed object idx
		BMI		locret_60CCF
		LDA		_trds_obj_idx,X				; check if it still active
		BMI		loc_60CDD
		LDA		_trds_args0,X				; get its beamed state also
		BMI		loc_60CDD					; when if 00 or FF, stop beam
		BEQ		loc_60CDD
locret_60CCF:
		RTS									; otherwise, do nothing
loc_60CD0:
		LDX		_trds_args0+3				; same set of test for case when you
		BMI		loc_60CDD					; release buttons,
		LDA		_trds_args0,X
		BMI		loc_60CDD
		BEQ		loc_60CDD
		JSR		_nsub_obj_to_beam_release_test	; if release, then release lol
loc_60CDD:
		JMP		_scr_cur_trd_off

; =============== S U B R O U T I N E ======n================================
; when you just fire the beam in air its sprite is plain and simple
_nsub_beam_idle_draw:
		LDA		_trds_args1+2				; fetch beamer position and direction
		CLC
		ADC		#$20
		AND		#$C0
		STA		_trds_args1+3				; update object parameters
		ASL
		ROL
		ROL
		TAY
		LDA		_obj_x_screen_pos+2
		CLC
		ADC		byte_60D1F,Y
		STA		_beam_target_x_pos			; update target position as well
		TAX
		LDA		_obj_y_screen_pos+2
		CLC
		ADC		byte_60D23,Y
		STA		_beam_target_y_pos
		TAY
		JSR		_obj_new_lvl_pos_set		; recalc current position
		LDA		_nmi_counter				; here we calculate time based
		AND		#$07						; animation frame for beam
		STA		_tmp0
		LDA		_trds_args1+3
		AND		#$40
		LSR
		LSR
		LSR
		ORA		_tmp0
		CLC
		ADC		#$00
		STA		_obj_spr_idx+3				; finally set sprite idx
		RTS
byte_60D1F:
		.BYTE	$00,$1C,$00,$E4
byte_60D23:
		.BYTE	$DC,$FC,$18,$FC

; =============== S U B R O U T I N E ======n================================
_nsub_beam_active_draw:
		LDX		_trds_args0+3				; active beam much harder, it's flexible
		LDA		_obj_out_of_screen,X		; get the beamed object out of screen flag
		BEQ		loc_60D2F
locret_60D2E:
		RTS
loc_60D2F:
		LDA		_obj_x_screen_pos,X			; continue if object on the screen
		PHA
		STA		_var0						; store beamed object position
		LDA		_obj_y_screen_pos,X
		PHA
		STA		_var1
		LDA		_trds_args1+2
		CLC
		ADC		#$20
		AND		#$C0
		ASL
		ROL
		ROL
		TAX
		LDA		_obj_x_screen_pos+2
		ADC		byte_60E67,X
		STA		_obj_x_pos_lo+3				; lots of vector/calcs follows
		STA		_var2						; to calculate current beam sprite
		LDA		_obj_y_screen_pos+2
		CLC
		ADC		byte_60E6B,X
		STA		_obj_y_pos_lo+3
		STA		_var3
		JSR		_point_to_point_dir_calc
		STA		_var7
		LDA		#$00
		STA		_obj_x_pos_hi+3
		STA		_obj_y_pos_hi+3
		PLA
		STA		_tmp0
		PLA
		SEC
		SBC		_obj_x_pos_lo+3
		BCS		loc_60D78
		DEC		_obj_x_pos_hi+3
		EOR		#$FF
		ADC		#$01
loc_60D78:
		CMP		#$50
		BCS		locret_60D2E
		STA		_obj_x_delta+3
		LDA		_tmp0
		SEC
		SBC		_obj_y_pos_lo+3
		BCS		loc_60D8D
		DEC		_obj_y_pos_hi+3
		EOR		#$FF
		ADC		#$01
loc_60D8D:
		CMP		#$50
		BCS		locret_60D2E
		STA		_obj_y_delta+3
		LDX		_obj_x_delta+3
		LDA		#$00
		LDY		#$05
		JSR		_div16
		STA		_obj_x_speed+3
		STX		_obj_x_delta+3
		LDA		_obj_x_pos_hi+3
		BPL		loc_60DBE
		LDA		#$00
		SEC
		SBC		_obj_x_speed+3
		STA		_obj_x_speed+3
		LDA		#$00
		SBC		_obj_x_delta+3
		STA		_obj_x_delta+3
loc_60DBE:
		LDX		_obj_y_delta+3
		LDA		#$00
		LDY		#$05
		JSR		_div16
		STA		_obj_y_speed+3
		STX		_obj_y_delta+3
		LDA		_obj_y_pos_hi+3
		BPL		loc_60DE8
		LDA		#$00
		SEC
		SBC		_obj_y_speed+3
		STA		_obj_y_speed+3
		LDA		#$00
		SBC		_obj_y_delta+3
		STA		_obj_y_delta+3
loc_60DE8:
		LDA		_nmi_counter
		AND		#$01
		TAX
		LDA		byte_60E6F,X
		STA		_var0
		LDA		_var7
		CLC
		ADC		#$08
		AND		#$70
		LSR
		STA		_var7
		LDA		_nmi_counter
		AND		#$06
		ORA		_var7
		ASL
		TAX
		LDA		#$80
		STA		_obj_x_clk+3
		STA		_obj_y_clk+3
		LDA		#$05						; when calcs are done, draw 5 segments
		STA		_var1						; of the beam manually, using raw spr
		LDY		_spr_buf_pos				; buffer access
loc_60E12:
		LSR		_var0
		BCC		loc_60E3D
; REGION, missing in the US proto version,
; NOTE, this is workaround for sprite glitches in heavy load. it disables current
; sprite slot. when NMI occurs during the sprite generation here, the current
; sprite won't appear. however, this not protecting from sprite buffer being not
; finished yet at the time of NMI.
		LDA		#$00
		STA		_ppu_spr_buf+3,Y
; -
		LDA		_obj_y_pos_lo+3
		CLC
		ADC		byte_60E71,X
		STA		_ppu_spr_buf,Y
		INY
		LDA		byte_60E71+1,X
		STA		_ppu_spr_buf,Y
		INY
		LDA		byte_60E71+2,X
		STA		_ppu_spr_buf,Y
		INY
		LDA		_obj_x_pos_lo+3
		CLC
		ADC		byte_60E71+3,X
		STA		_ppu_spr_buf,Y
		INY
loc_60E3D:
		LDA		_obj_x_clk+3
		CLC
		ADC		_obj_x_speed+3
		STA		_obj_x_clk+3
		LDA		_obj_x_pos_lo+3
		ADC		_obj_x_delta+3
		STA		_obj_x_pos_lo+3
		LDA		_obj_y_clk+3
		CLC
		ADC		_obj_y_speed+3
		STA		_obj_y_clk+3
		LDA		_obj_y_pos_lo+3
		ADC		_obj_y_delta+3
		STA		_obj_y_pos_lo+3
		DEC		_var1
		BNE		loc_60E12
		STY		_spr_buf_pos
		CLC
		RTS
byte_60E67:
		.BYTE	$00,$08,$FF,$F8
byte_60E6B:
		.BYTE	$F0,$FC,$03,$FC
byte_60E6F:
		.BYTE	$15,$0A
byte_60E71:
		.BYTE	$FC,$60,$01,$FC
		.BYTE	$FC,$60,$41,$FC
		.BYTE	$FC,$70,$01,$FC
		.BYTE	$FC,$70,$41,$FC
		.BYTE	$FC,$62,$01,$FC
		.BYTE	$FC,$72,$01,$FC
		.BYTE	$FC,$64,$01,$FC
		.BYTE	$FC,$74,$01,$FC
		.BYTE	$FC,$66,$01,$FC
		.BYTE	$F4,$66,$C1,$FC
		.BYTE	$FC,$76,$01,$FC
		.BYTE	$F4,$76,$C1,$FC
		.BYTE	$FC,$68,$01,$FC
		.BYTE	$FC,$78,$01,$FC
		.BYTE	$FC,$6A,$01,$FC
		.BYTE	$FC,$7A,$01,$FC
		.BYTE	$FC,$6C,$01,$FC
		.BYTE	$F4,$6C,$81,$FC
		.BYTE	$FC,$7C,$01,$FC
		.BYTE	$F4,$7C,$81,$FC
		.BYTE	$FC,$68,$41,$FC
		.BYTE	$FC,$78,$41,$FC
		.BYTE	$FC,$6A,$41,$FC
		.BYTE	$FC,$7A,$41,$FC
		.BYTE	$FC,$66,$41,$FC
		.BYTE	$F4,$66,$81,$FC
		.BYTE	$FC,$76,$41,$FC
		.BYTE	$F4,$76,$81,$FC
		.BYTE	$FC,$62,$41,$FC
		.BYTE	$FC,$72,$41,$FC
		.BYTE	$FC,$64,$41,$FC
		.BYTE	$FC,$74,$41,$FC

; =============== S U B R O U T I N E ======n================================
_nsub_obj_to_beam_release_test:
		LDX		_trds_args0+3				; get the beamed object idx
		LDA		_trds_args0,X				; test if it is still not catched
		BMI		locret_60F02
		CMP		#$02
		BNE		loc_60EFE					; also test if it stunned by beam
		INC		_trds_args0,X
		RTS
loc_60EFE:
		LDA		#$00
		STA		_trds_args0,X
locret_60F02:
		RTS

; =============== S C R I P T ==========================s====================
_scr0A_catcher_handler:
#if TWO_PLAYER_MODE==1
		STORE8			_players_hit_flag+1,$00
		STORE8			_players_inv_timer+1,$00
#endif
		STORE8			_catcher_turns_count,$00		; mostly the same as for
		STORE8			_catcher_target_slot_idx,$02	; beamer, but additional
		STORE8			_catcher_target_distance,$18	; speed modifier called from other
		STORE16			_catcher_speed,$180				; place now
		NJSR			_nsub_catcher_spr_base_reset

; =============== S C R I P T ==========================s====================
_scr_catcher_reinit:
		NBG_HNDL_SET	_nbgsub_catcher_control
		SUSPEND

#if TWO_PLAYER_MODE==1
; =============== S C R I P T ==========================s====================
_scr_catcher_hit_anim:
		SJSR			_ssub_common_hit_anim
		SBCCS			_scr_catcher_reinit
		SSTOP
#endif

; =============== S C R I P T ==========================s====================
_scr_lvl3_catcher_auto_script:
		POS_X_SET		0,$30,$00
		POS_Y_SET		0,$C8,$02
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$40
		NJSR			_nsub_catcher_spr_idx_calc
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_lvl6_catcher_auto_scriptA:
		POS_Y_DELTA_SET 0,$80,$FF						; same as for beamer
		SLOOP_BEGIN		$F0								; just walk up, then jump to
		SARG_ALU		SARG0,_ADC,$01					; common handler, returning
		NJSR			_nsub_catcher_spr_idx_calc		; control to the player and AI
		SDELAY			$02
		SLOOP_END
		POS_MOVE_STOP	0
		SJMPS			_scr0A_catcher_handler

; =============== S C R I P T ==========================s====================
_scr_lvl6_catcher_auto_scriptB:
		NJSR			_nsub_catcher_spr_idx_calc
		SDELAY			$78
		SARG_SET		SARG1,$80
		POS_Y_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$F0
		SARG_ALU		SARG0,_ADC,$01
		NJSR			_nsub_catcher_spr_idx_calc
		SDELAY			$01
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_catcher_control:
#if TWO_PLAYER_MODE==1
		LDA		_players_hit_flag+1
		LSR
		BCC		loc_60317
		JSR		_cur_thread_reload_param
		.WORD	_scr_catcher_hit_anim
		RTS
loc_60317:
		LDA		_players_inv_timer+1
		BEQ		loc_6031F
		DEC		_players_inv_timer+1
loc_6031F:
#endif
		LDA		_trds_obj_idx+5				; do nothing, while catch is deployed
		BPL		locret_6101E
		LDA		_trds_obj_idx				; also additionally test if current level is 4
		CMP		#$04
		BNE		loc_61015
		JSR		_lvl4_catcher_speed_modifier_calc
loc_61015:
		JSR		_catcher_control_catch_test	; test if player pressed catch button
		JSR		_catcher_control_move_test
		JMP		_catcher_spr_selector
locret_6101E:
		RTS

#if TWO_PLAYER_MODE==1
; =============== S U B R O U T I N E ======n================================
_catcher_control_move_test:
		LDA		_obj_x_pos_lo+4
		ORA		_obj_y_pos_lo+4
		AND		#$07
		BNE		.catcher_speed_calc
		LDA		_pad1_held
		AND		#$0F
		BEQ		.catcher_speed_reset
		JSR		_catcher_direction_calc
		LDA		_catcher_direction_idx
		JSR		_players_move_obstacles_test
		BCS		.catcher_speed_reset
.catcher_speed_calc:
		LDA		_catcher_direction_idx
		LDX		_catcher_speed
		LDY		_catcher_speed+1
		JSR		_players_speed_calc
		TAY
		BEQ		.catcher_exit
		BNE		.catcher_step
.catcher_next_step:
		LDA		_obj_x_pos_lo+4
		ORA		_obj_y_pos_lo+4
		AND		#$07
		BNE		.catcher_step
		LDA		_pad1_held
		AND		#$0F
		BEQ		.catcher_speed_reset
		JSR		_catcher_direction_calc
		LDA		_catcher_direction_idx
		JSR		_players_move_obstacles_test
		BCC		.catcher_step
.catcher_speed_reset:
		LDA		#$80
		STA		_obj_x_clk+4
		STA		_obj_y_clk+4
		BNE		.catcher_exit
.catcher_step:
		LDA		_catcher_direction_idx
		JSR		_players_move_step
		LDX		_catcher_direction_idx
		JSR		_catcher_scroll_step
		DEY
		BNE		.catcher_next_step
.catcher_exit:
		RTS
#else
; =============== S U B R O U T I N E ======n================================
_catcher_control_move_test:
		LDA		_obj_x_pos_lo+4				; move control for catcher mostly the same
		ORA		_obj_y_pos_lo+4				; as for beemer, but with some difference
		AND		#$07
		BNE		.catcher_speed_calc
		JSR		_catcher_target_follow		; here is the AI routine to follow the target
		LDA		_catcher_direction_idx
		BMI		.catcher_speed_reset
.catcher_speed_calc:
		JSR		_nsub_sarg1_direction_extract
		LDX		_catcher_speed
		LDY		_catcher_speed+1
		JSR		_players_speed_calc
		TAY
		BEQ		.catcher_exit
		BNE		.catcher_step
.catcher_next_step:
		LDA		_obj_x_pos_lo+4
		ORA		_obj_y_pos_lo+4
		AND		#$07
		BNE		.catcher_step
		JSR		_catcher_target_follow
		LDA		_catcher_direction_idx
		BPL		.catcher_step
.catcher_speed_reset:
		LDA		#$80
		STA		_obj_x_clk+4
		STA		_obj_y_clk+4
		BNE		.catcher_exit
.catcher_step:
		JSR		_nsub_sarg1_direction_extract
		JSR		_players_move_step			; and here is no scroll update routine
		DEY
		BNE		.catcher_next_step
.catcher_exit:
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_catcher_control_catch_test:
#if TWO_PLAYER_MODE==1
		LDA		_pad1_pressed
#else
		LDA		_pad0_pressed				; only controllable by the player action here
#endif
		AND		_control_catch_button_code
		BEQ		locret_610A9
		LDX		_cur_trd_slot
		LDA		_obj_out_of_screen,X
		BNE		locret_610A9
		LDA		_obj_x_screen_pos,X			; get the current catcher position
		STA		_tmp1						; and store
		LDA		_obj_y_screen_pos,X
		STA		_tmp2
#if TWO_PLAYER_MODE==1
		LDA		_catcher_direction_idx
#else
		JSR		_nsub_sarg1_direction_extract; calculate its direction
#endif
		PHA
		TAX
		LDA		_tmp2
		CLC
		ADC		byte_610AE,X				; calculate destination point to catch object
		TAY
		LDA		_tmp1
		CLC
		ADC		byte_610AA,X
		TAX
		JSR		_obj_new_lvl_pos_calc
		LDA		#$00
		STA		_catcher_turns_count
		STA		_var0
		PLA
		LSR
		ROR
		ROR
		STA		_var1						; now deploy new catch object
		LDA		#$05						; also fixed single slot requested
		STA		_var4						; position already calculated before
		LDA		#$06
		STA		_var5
		LDA		#_scr0B_player_catch_idx
		JSR		_thread_lib_load
		LDA		#_snd01_idx					; and play sound
		JMP		_far_prg6_apu_snd_load
locret_610A9:
		RTS
byte_610AA:
		.BYTE	$00,$09,$00,$F7
byte_610AE:
		.BYTE	$E8,$00,$0C,$00

; =============== S U B R O U T I N E ======n================================
_catcher_spr_selector:
#if TWO_PLAYER_MODE==1
		LDA		_pad1_held
		AND		#$0F
		BEQ		loc_605DE
		INC		_trds_args0+4
loc_605DE:
		LDA		_players_inv_timer+1
		LSR
		BCC		_nsub_catcher_spr_idx_calc
		LDA		#$FF
		STA		_obj_spr_idx+4
		RTS
#else
		LDA		_catcher_direction_idx		; when catcher stand still its direction idx
		BMI		_nsub_catcher_spr_idx_calc	; =$FF.
		INC		_trds_args0+4				; run player's animation counter
#endif

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nsub_catcher_spr_idx_calc:
		LDA		_catcher_spr_base
		JMP		_players_spr_idx_calc

#if TWO_PLAYER_MODE==0
; =============== S U B R O U T I N E ======n================================
; now, here is the main AI routine of the game. path search and target
; selection for catcher. fully CPU controlled here
;
_catcher_target_follow:
		TYA									; backup Y, now routine Y safe
		PHA
		LDX		_catcher_target_slot_idx	; default mode is to follow beamer
		CPX		#$02						; its slot is always 02, so do it
		BNE		.catcher_beamed_follow		; skip to enemy test if beamed object
		JSR		_beamed_enemy_lookup		; already targeted
		BCS		.catcher_do_targeting
		BCC		.catcher_beamed_found
.catcher_beamed_follow:
		LDA		_trds_obj_idx,X
		BMI		.catcher_beamed_lookup		; if already catched, restart lookup
		LDA		_trds_args0,X				; for other beamed objects
		BEQ		.catcher_beamed_lookup
		LDA		_obj_out_of_screen,X		; when still beamed, recalc its position
		BEQ		.catcher_do_targeting		; again. it won't change, but previously
.catcher_beamed_lookup:						; calculated values are lost in tmp vars
		JSR		_beamed_enemy_lookup		; finally, if beamed object inactive and
		BCS		.catcher_beamer_follow		; no new beamed objects, reset targeting
.catcher_beamed_found:
		LDA		#$30
		BNE		.catcher_follow_idx_update	; update targeting parameters with beamed
.catcher_beamer_follow:						; object
		LDX		#$02						; retarget to the beamer player
		LDA		#$18
.catcher_follow_idx_update:
		STX		_catcher_target_slot_idx	; update following parameters if any
		STA		_catcher_target_distance
		LDA		#$00
		STA		_catcher_turns_count
.catcher_do_targeting:
		LDX		_catcher_target_slot_idx	; now let's test if we need to move
		LDY		_catcher_target_distance
		INY
		JSR		_catcher_is_target_nearby_test	; test if we reached our target to closest
		BCC		.catcher_search_path		; range
; TODO: remove it to update beamer direction even in the close range
		LDA		_catcher_target_slot_idx	; if in range, reset movements counter
		CMP		#$02						; and direction variables,
		BEQ		loc_61112
; -
		JSR		_obj_to_obj_dir_calc		; also if we targeted to beamed object
		CLC									; position the face to the direction
		ADC		#$20						; of the object. but actually I see it
		AND		#$C0						; a lot more funnier when catcher always
		STA		_trds_args1+4				; turns to the beamer dynamically
loc_61112:
		LDA		#$00						; for beamer target we don't have to face it
		STA		_catcher_turns_count		; all the way.
		LDA		#$FF
		BNE		.catcher_exit2
.catcher_search_path:
		LDA		_catcher_turns_count
		BEQ		.catcher_start_move
		JSR		_catchet_turn_test
		JSR		_players_bound_box_to_room_test
		BCS		loc_6112E
		JSR		_catcher_turn_sub
		JMP		loc_61184
loc_6112E:
		JSR		_nsub_sarg1_direction_extract
		BPL		loc_61146
.catcher_start_move:
		JSR		_nsub_sarg1_direction_extract; get current direction, test if
		LDY		#$07						; target object in the same direction
		LDX		_catcher_target_slot_idx	; or else retarget
		JSR		_catcher_direction_to_target_test
		BCC		loc_61146
		LDY		_catcher_target_slot_idx
		JSR		_cur_obj_to_target_nearest_path_calc
loc_61146:
		STA		_var4
		JSR		_players_bound_box_to_room_test
		BCC		loc_61184
		JSR		_catcher_turn_add
		LDY		_catcher_target_slot_idx
		JSR		_cur_obj_to_target_nearest_path_calc
		STA		_tmp0
		EOR		_var4
		LSR
		BCC		loc_61161
		LDA		_tmp0
		BPL		loc_61163
loc_61161:
		LDA		_var5
loc_61163:
		STA		_var5
		JSR		_players_bound_box_to_room_test
		BCC		loc_61184
		ADC		#$01
		AND		#$03
		JSR		_players_bound_box_to_room_test
		BCC		loc_61184
		LDA		_var5
		JSR		_catcher_turn_add
		LDA		_var4
		CLC
		ADC		#$02
		AND		#$03
		JSR		_players_bound_box_to_room_test
		BCS		loc_61112
loc_61184:
		JSR		_nsub_sarg1_direction_update
.catcher_exit2:
		STA		_catcher_direction_idx
		PLA
		TAY
		RTS

; =============== S U B R O U T I N E ======n================================
_beamed_enemy_lookup:
		LDX		#$06						; look for enemy object in gen slots
loc_6118F:
		LDA		_trds_obj_idx,X				; with beamed active flag set
		BMI		loc_611A3
		LDA		_trds_args0,X
		CMP		#$02
		BNE		loc_611A3
		LDA		_obj_out_of_screen,X		; if found, test if it not out of screen
		BNE		loc_611A3
		CLC									; return object slot idx in X
		RTS
loc_611A3:
		INX
		CPX		#$0E
		BCC		loc_6118F					; C=1 if nothing found
		RTS

; =============== S U B R O U T I N E ======n================================
; calculates distance between two objects (used for catcher/enemy test)
; and choses shortest one.
;
_cur_obj_to_target_nearest_path_calc:
		LDX		#$00
		STX		_tmp1
		INX
		STX		_tmp2
		LDX		_cur_trd_slot
		LDA		_obj_x_pos_lo,Y
		SEC
		SBC		_obj_x_pos_lo,X
		STA		_var0
		LDA		_obj_x_pos_hi,Y
		SBC		_obj_x_pos_hi,X
		BCS		loc_611D2
		INC		_tmp1
		PHA
		LDA		#$00
		SEC
		SBC		_var0
		STA		_var0
		PLA
		EOR		#$FF
		ADC		#$00
loc_611D2:
		STA		_var1
		LDA		_tmp1
		ASL
		ADC		#$01
		STA		_tmp1
		LDA		_obj_y_pos_lo,Y
		SEC
		SBC		_obj_y_pos_lo,X
		STA		_var2
		LDA		_obj_y_pos_hi,Y
		SBC		_obj_y_pos_hi,X
		BCS		loc_611FB
		DEC		_tmp2
		PHA
		LDA		#$00
		SEC
		SBC		_var2
		STA		_var2
		PLA
		EOR		#$FF
		ADC		#$00
loc_611FB:
		STA		_var3
		LDA		_tmp2
		ASL
		STA		_tmp2
		LDA		_var1
		CMP		_var3
		BCC		loc_61210
		BNE		loc_61217
		LDA		_var0
		CMP		_var2
		BCS		loc_61217
loc_61210:
		LDA		_tmp1
		STA		_var5
		LDA		_tmp2
		RTS
loc_61217:
		LDA		_tmp2
		STA		_var5
		LDA		_tmp1
		RTS

; =============== S U B R O U T I N E ======n================================
_catcher_is_target_nearby_test:
		JSR		_obj_to_obj_in_range_test	; test if selected target in range
		BCC		locret_61238				; $18 for beamer, $30 for enemies
		LDA		_catcher_target_slot_idx	; then if we in range, test fine
		CMP		#$02						; tuned distance, not greater than
		BNE		loc_6122E					; $07 for beamer, or $18 for enemy
		LDA		#$18
		BNE		loc_61230
loc_6122E:
		LDA		#$07
loc_61230:
		CMP		_tmp1						; tmp1/tmpw loaded with X/Y
		BCS		locret_61236				; distance to the object
		CMP		_tmp2
locret_61236:
		RTS
;_unref_1:
;		CLC									; NOTE, obviously redundant but not removed
locret_61238:
		RTS

; =============== S U B R O U T I N E ======n================================
; when obstacle found, try to avoid it by the right hand rule in the labyrinth
; however, we need to store previous move direction to return to previous path
; every time it get into the obstacle, it saves previous walk direction,
; turn right and continues...
;
_catcher_turn_add:
		PHA
		STA		_tmp0
		LDA		_catcher_turns_count
		AND		#$03
		TAX
		TAY
		BEQ		loc_6124C
loc_61245:
		ASL		_tmp0
		ASL		_tmp0
		DEY
		BNE		loc_61245
loc_6124C:
		LDA		_catcher_turns_count
		LSR
		LSR
		TAY
		LDA		_catcher_turns_flags,Y
		AND		_catcher_turns_masks,X
		ORA		_tmp0
		STA		_catcher_turns_flags,Y
		INC		_catcher_turns_count
		LDA		_catcher_turns_count
		AND		#$07
		STA		_catcher_turns_count
		PLA
		RTS
_catcher_turns_masks:
		.BYTE	$FC,$F3,$CF,$3F
_catcher_turns_bits:
		.BYTE	$03,$0C,$30,$C0

; =============== S U B R O U T I N E ======n================================
_catcher_turn_sub:
		JSR		_catchet_turn_test			; do turn
		PHA
		DEC		_catcher_turns_count
		LDA		_catcher_turns_count
		AND		#$07
		STA		_catcher_turns_count
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
_catchet_turn_test:
		LDX		_catcher_turns_count		; test if turn needed
		DEX
		TXA
		PHA
		AND		#$03
		TAX
		PLA
		LSR
		LSR
		TAY
		LDA		_catcher_turns_flags,Y
		AND		_catcher_turns_bits,X
		DEX
		BMI		locret_6129E
loc_61299:
		LSR
		LSR
		DEX
		BPL		loc_61299
locret_6129E:
		RTS

; =============== S U B R O U T I N E ======n================================
_catcher_direction_to_target_test:
		PHA									; store current direction
		STA		_var1						; tmp current direction
		STY		_var0						; relative distance treshold (always $07)
		DEC		_var1
		BPL		loc_612C2					; branch for catcher walk UP
		JSR		_catcher_screen_y_pos_calc	; calculate catcher screen pos
		BEQ		loc_612B1
		BCC		.exit_true					; if out of screen, continue
		BCS		.exit_false					; choose direction to next room
loc_612B1:
		JSR		_obj_screen_y_pos_calc		; now calculate object screen pos
		STA		_tmp0						; which is already cannot be out
		TYA									; of screen
		SEC
		SBC		_tmp0
		BCC		.exit_true					; adjust new direction according
		CMP		_var0						; to relative locations of two objects
		BCC		.exit_true
		BCS		.exit_false
loc_612C2:
		DEC		_var1
		BPL		loc_612DF					; branch for catcher walk RIGHT
		JSR		_catcher_screen_x_pos_calc	; all the same for other directions
		BEQ		loc_612CF
		BCS		.exit_true
		BCC		.exit_false
loc_612CF:
		STY		_tmp0
		JSR		_obj_screen_x_pos_calc
		SEC
		SBC		_tmp0
		BCC		.exit_true
		CMP		_var0
		BCC		.exit_true
		BCS		.exit_false
loc_612DF:
		DEC		_var1
		BPL		loc_612FC					; branch for catcher walk DOWN
		JSR		_catcher_screen_y_pos_calc
		BEQ		loc_612EC
		BCS		.exit_true
		BCC		.exit_false
loc_612EC:
		STY		_tmp0
		JSR		_obj_screen_y_pos_calc
		SEC
		SBC		_tmp0
		BCC		.exit_true
		CMP		_var0
		BCC		.exit_true
		BCS		.exit_false
loc_612FC:
		JSR		_catcher_screen_x_pos_calc	; what is left is walk LEFT
		BEQ		loc_61305
		BCC		.exit_true
		BCS		.exit_false
loc_61305:
		JSR		_obj_screen_x_pos_calc
		STA		_tmp0
		TYA
		SEC
		SBC		_tmp0
		BCC		.exit_true
		CMP		_var0
		BCS		.exit_false
.exit_true:
		PLA
		SEC
		RTS
.exit_false:
		PLA
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
; TODO: use screen positions as well
;
_catcher_screen_x_pos_calc:
		LDA		_obj_x_pos_lo+4
		SEC
		SBC		_ppu_scroll_pos_x
		TAY
		LDA		_obj_x_pos_hi+4
		SBC		_ppu_scroll_pos_x+1
		RTS

; =============== S U B R O U T I N E ======n================================
_catcher_screen_y_pos_calc:
		LDA		_obj_y_pos_lo+4
		SEC
		SBC		_ppu_scroll_pos_y
		BCS		loc_61330
		SBC		#$0F
		CLC
loc_61330:
		TAY
		LDA		_obj_y_pos_hi+4
		SBC		_ppu_scroll_pos_y+1
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_screen_x_pos_calc:
		LDA		_obj_x_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_x
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_screen_y_pos_calc:
		LDA		_obj_y_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_y
		BCS		locret_61346
		SBC		#$0F
locret_61346:
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_nsub_catcher_spr_base_reset:
		LDA		_catcher_spr_base_tmp
		STA		_catcher_spr_base
		RTS

; =============== S C R I P T ==========================s====================
_scr0B_player_catch:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_catch_ctest				; init catch collision test
		NJSR			_nsub_catch_deploy_init			; set speed and direction of catch
_sloc_61357:
		NJSR			_nsub_catch_deploy_anim			; animate catch deploy
		SDELAY			$01
		NJSR			_nsub_catch_deploy_stop_test	; wait for 8 frames
		SBCCS			_sloc_61357
		SJMPS			_scr_catch_remove				; remove catch

; =============== S C R I P T ==========================s====================
_scr_catch_active:
		NJSR			_nsub_catch_work_anim			; animate catch opens
		SDELAY			$0E

; =============== S C R I P T ==========================s====================
_scr_catch_remove:
		NJSR			_nsub_catch_remove_init			; the reverse process
_sloc_6136D:
		NJSR			_nsub_catch_remove_anim
		SDELAY			$01
		NJSR			_nsub_catch_remove_stop_test
		SBCCS			_sloc_6136D
		SSTOP											; then stop

; =============== S U B R O U T I N E ======n================================
_nbgsub_catch_ctest:
		JSR		_catch_obj_beamed_search	; search for any beamed object first
		BCS		locret_613C4
		LDA		_trds_obj_idx+3				; if beam is not active, skip this part
		BMI		loc_6138C
		CPX		_trds_args0+3				; if beamed object and object we found is the same
		BNE		loc_6138C					; disable the beam, it's work done
		LDA		#$FF
		STA		_trds_obj_idx+3
loc_6138C:
		LDY		#$00						; calc X distance betwee beamed obj and catch
		LDA		_obj_x_pos_lo+5
		SEC
		SBC		_obj_x_pos_lo,X
		LDA		_obj_x_pos_hi+5
		SBC		_obj_x_pos_hi,X
		BCS		loc_6139C
		INY
loc_6139C:
		TYA									; force beamed object to be at catch now
		ORA		#$80						; adjust positions
		STA		_trds_args0,X
		LDA		_obj_x_pos_lo+5
		STA		_obj_x_pos_lo,X
		LDA		_obj_x_pos_hi+5
		STA		_obj_x_pos_hi,X
		LDA		_obj_y_pos_lo+5
		SEC
		SBC		#$12
		BCS		loc_613B5
		SBC		#$0F
		CLC
loc_613B5:
		STA		_obj_y_pos_lo,X
		LDA		_obj_y_pos_hi+5
		SBC		#$00
		STA		_obj_y_pos_hi,X
		JSR		_cur_thread_reload_param	; now reload the current script with active type
		.WORD	_scr_catch_active
locret_613C4:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_catch_deploy_init:
		JSR		_nsub_sarg1_direction_extract
		ASL
		TAY
		LDA		byte_613E3+6,Y
		STA		_obj_x_speed+5
		LDA		byte_613E3+7,Y
		STA		_obj_x_delta+5
		LDA		byte_613E3+4,Y
		STA		_obj_y_speed+5
		LDA		byte_613E3+5,Y
		STA		_obj_y_delta+5
		RTS
byte_613E3:
		.BYTE	$00,$04,$00,$00,$00,$FC,$00
		.BYTE	$00,$00,$04,$00,$00,$00,$FC

; =============== S U B R O U T I N E ======n================================
_nsub_catch_deploy_anim:
		JSR		_catch_spr_idx_select
		INC		_trds_args0+5
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_catch_deploy_stop_test:
		LDA		_trds_args0+5
		CMP		#$08
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_catch_remove_init:
		JSR		_nsub_sarg1_direction_extract
		ASL
		TAY
		LDA		byte_613E3+2,Y
		STA		_obj_x_speed+5
		LDA		byte_613E3+3,Y
		STA		_obj_x_delta+5
		LDA		byte_613E3,Y
		STA		_obj_y_speed+5
		LDA		byte_613E3+1,Y
		STA		_obj_y_delta+5
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_catch_remove_anim:
		LDX		_cur_trd_slot
		DEC		_trds_args0+5
		JMP		_catch_spr_idx_select

; =============== S U B R O U T I N E ======n================================
_nsub_catch_remove_stop_test:
		LDA		_trds_args0+5
		BNE		loc_61427
		SEC
		RTS
loc_61427:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_catch_work_anim:
		DEC		_trds_args0+5
		JSR		_catch_spr_idx_select
		LDA		_obj_spr_idx+5
		CLC
		ADC		#$10
		STA		_obj_spr_idx+5
		INC		_trds_args0+5
		RTS

; =============== S U B R O U T I N E ======n================================
_catch_spr_idx_select:
		JSR		_nsub_sarg1_direction_extract
		STA		_tmp0
		LDA		_trds_args0+5
		AND		#$06
		ASL
		ADC		_tmp0
		ADC		#$10
		STA		_obj_spr_idx+5
		RTS

; =============== S U B R O U T I N E ======n================================
_catch_obj_beamed_search:
		LDX		_cur_trd_slot
		LDA		_obj_x_screen_pos,X			; get the current catch position
		STA		_tmp1
		LDA		_obj_y_screen_pos,X
		STA		_tmp2
		LDX		#$06
loc_61452:
		TXA									; now look for any object in beamed state
		PHA
		LDA		_trds_obj_idx,X				; skip inactive objects
		BMI		loc_61480
		LDA		_trds_args0,X				; beamed object has $02 here
		BMI		loc_61480
		CMP		#$02
		BCC		loc_61480
		LDA		_obj_out_of_screen,X		; if object is on the screens
		BNE		loc_61480					; then get position of it
		LDA		_obj_x_screen_pos,X			; and calc distance between
		SBC		_tmp1
		BCS		loc_6146F
		EOR		#$FF
		ADC		#$01
loc_6146F:
		CMP		#$11
		BCS		loc_61480
		LDA		_obj_y_screen_pos,X
		SBC		_tmp2
		BCS		loc_6147C
		EOR		#$FF
		ADC		#$01
loc_6147C:
		CMP		#$11
		BCC		loc_61488
loc_61480:
		PLA
		TAX
		INX
		CPX		#$0E
		BCC		loc_61452					; return C=1 if no such objects found
		RTS
loc_61488:
		PLA
		TAX									; return C=0 and X= object idx
		RTS

; =============== S U B R O U T I N E ======n================================
; input data is a set of bounding box points to ckeck the macro tile type
; in corresponding direction
;
_obj_to_room_bound_box_ctest:
		STA		_ptr08
		STY		_ptr08+1
		TXA
		PHA
		LDY		#$00
		STY		_var0
		LDA		(_ptr08),Y
		TAX
		INY
loc_617E1:
		TXA
		PHA
		LDA		(_ptr08),Y
		TAX
		INY
		LDA		(_ptr08),Y
		STA		_tmp2
		INY
		TYA
		PHA
		LDY		_tmp2
		LDA		_var0
		PHA
		JSR		_obj_to_room_macro_ctest
		PLA
		ROL
		STA		_var0
		PLA
		TAY
		PLA
		TAX
		DEX
		BNE		loc_617E1
		PLA
		TAX
		LDA		_var0
		BNE		loc_61809
		CLC
		RTS
loc_61809:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
; doors are different kind of objects, they may be opened or may be closed
; although they drawn with the same macro blocks as other level obstacles
; and macro collision test performed on it also, when opened, we may
; just skip the macro test, so here we use room position and dimensions data
; to test if we in collide with the door area.
;
_room_doors_ctest:
		STY		_tmp2						; store Y pos of tested object for now
		LDY		_cur_room_doors_cnt			; check if any room data in buffers
		BEQ		loc_61860					; if any, go test the positions
loc_61812:
		TXA
		SEC
		SBC		_doors_x_pos_hi,Y			; calculate distance to object
		STA		_tmp0
		LDA		_tmp_var0
		SBC		_doors_x_pos_lo,Y
		BCS		loc_6182E
		PHA
		LDA		#$00
		SEC
		SBC		_tmp0
		STA		_tmp0
		PLA
		EOR		#$FF
		ADC		#$00
loc_6182E:
		BNE		loc_6185D
		LDA		_doors_width,Y				; now test if we in door bound box
		CMP		_tmp0
		BCC		loc_6185D
		LDA		_tmp2
		SEC
		SBC		_doors_y_pos_hi,Y
		STA		_tmp0
		LDA		_tmp_var1
		SBC		_doors_y_pos_lo,Y
		BCS		loc_61854
		PHA
		LDA		#$00
		SEC
		SBC		_tmp0
		STA		_tmp0
		PLA
		EOR		#$FF
		ADC		#$00
loc_61854:
		BNE		loc_6185D
		LDA		_doors_height,Y
		CMP		_tmp0
		BCS		loc_61861
loc_6185D:
		DEY
		BNE		loc_61812
loc_61860:
		CLC
loc_61861:
		LDY		_tmp2
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_to_room_macro_ctest:
		LDA		#$00
		STA		_tmp_var0					; again, calculate bound box vertex
		STA		_tmp_var1					; room position, then read out the macro
		TXA									; block data for it
		BPL		loc_6186F
		DEC		_tmp_var0
loc_6186F:
		LDX		_cur_trd_slot
		CLC
		ADC		_obj_x_pos_lo,X
		PHA
		LDA		_tmp_var0
		ADC		_obj_x_pos_hi,X
		STA		_tmp_var0
		CLC
		TYA
		BPL		loc_6188B
		DEC		_tmp_var1
		ADC		_obj_y_pos_lo,X
		BCS		loc_61896
		SBC		#$0F
		CLC
		BCC		loc_61896
loc_6188B:
		ADC		_obj_y_pos_lo,X
		BCS		loc_61893
		CMP		#$F0
		BCC		loc_61896
loc_61893:
		ADC		#$0F
		SEC
loc_61896:
		TAY
		LDA		_tmp_var1
		ADC		_obj_y_pos_hi,X
		STA		_tmp_var1
		PLA
		TAX

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_room_macro_ctest_ex:
		JSR		_room_doors_ctest			; skip if stand in a door
		BCC		loc_618A6
		RTS
loc_618A6:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank			; read macro data, then extract
		STA		_prg_cur_bank				; collision bit data
		JSR		_mmc1_prg_safe
		JSR		_room_macro_tile_read
		JSR		_macro_collision_read
		PHP
		PLA
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		LSR
		RTS

; =============== S U B R O U T I N E ======n================================
; this is far routine to read out the collision data bit only for a
; given macro index read somewhere else... never used in this here.
;
;_far_macro_collision_read_unref:
;		STA		_tmp0
;		LDA		_prg_cur_bank
;		PHA
;		LDA		_lvl_data_prg_bank
;		STA		_prg_cur_bank
;		JSR		_mmc1_prg_safe
;		LDA		_tmp0
;		JSR		_macro_collision_read
;		PHP
;		PLA
;		STA		_tmp0
;		PLA
;		STA		_prg_cur_bank
;		JSR		_mmc1_prg_safe
;		LDA		_tmp0
;		LSR
;		RTS

; =============== S U B R O U T I N E ======n================================
_macro_collision_read:
		STA		_tmp0
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		_tmp0
		LSR
		LSR
		LSR
		TAY
		LDA		_tmp0
		AND		#$07
		TAX
;		LDA		_prg_cur_bank				; REDUNDANT: for some reason, this routine also
;		PHA									; set the bank, already set in routine above.
;		LDA		_lvl_data_prg_bank			; redundant setting may be removed
;		STA		_prg_cur_bank
;		JSR		_mmc1_prg_safe
		LDA		(_lvl_collisions_ptr),Y
		STA		_tmp0
;		PLA
;		STA		_prg_cur_bank
;		JSR		_mmc1_prg_safe
		LDA		_tmp0
		AND		_bit_mask,X
		BNE		loc_61913
		CLC
		BCC		loc_61914
loc_61913:
		SEC
loc_61914:
		PLA
		TAY
		PLA
		TAX
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
; one more unused unreferenced far call helper to only to read
; macro data this time.
;
;_far_room_macro_tile_read_unref:
;		LDA		_prg_cur_bank
;		PHA
;		LDA		_lvl_data_prg_bank
;		STA		_prg_cur_bank
;		JSR		_mmc1_prg_safe
;		JSR		_room_macro_tile_read
;		STA		_tmp0
;		PLA
;		STA		_prg_cur_bank
;		JSR		_mmc1_prg_safe
;		LDA		_tmp0
;		RTS

; =============== S U B R O U T I N E ======n================================
_room_macro_tile_read:
		TYA
		PHA
		AND		#$08
		LSR
		STA		_tmp0
		TXA
		PHA
		AND		#$08
		LSR
		LSR
		ORA		_tmp0
		PHA
		JSR		_room_macro_block_read		; read macro block idx first
		TAY
		PLA
		TAX
		LDA		_lvl_macroA_ptr,X			; NOTE: all macro ptrs are stored
		STA		_ptr06						; continuosly, we read only one at once
		LDA		_lvl_macroA_ptr+1,X
		STA		_ptr06+1
		LDA		(_ptr06),Y					; read corresponding macro tile (1/4)
		STA		_tmp0
		PLA
		TAX
		PLA
		TAY
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E ======n================================
; this is the only helper used in other portions of the engine
;
_far_room_macro_block_read:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		JSR		_room_macro_block_read
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E ======n================================
_room_macro_block_read:
		TYA
		PHA
		AND		#$F0
		STA		_tmp0
		TXA
		LSR
		LSR
		LSR
		LSR
		ORA		_tmp0
		PHA
		LDA		_tmp_var1
		ASL
		ASL
		ASL
		ORA		_tmp_var0
		ASL
		TAY
		LDA		(_lvl_rooms_lib_ptr),Y
		STA		_ptr06
		INY
		LDA		(_lvl_rooms_lib_ptr),Y
		STA		_ptr06+1
		PLA
		TAY
		LDA		(_ptr06),Y
		STA		_tmp0
		PLA
		TAY
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E ======n================================
_far_ppu_macro_block_draw:
		STA		_tmp0
		LDA		_prg_cur_bank				; get the macro idx
		PHA
		LDA		_lvl_data_prg_bank			; set the data bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp_var0
		LSR
		TXA
		PHA
		ROR
		LSR
		LSR
		TAX
		LDA		_tmp_var1
		LSR
		TYA
		PHA
		ROR
		LSR
		LSR
		PHA
		LDY		_tmp0
		LDA		(_lvl_macroA_ptr),Y			; fetch the macro tiles data
		STA		_tmp_buf+4
		LDA		(_lvl_macroB_ptr),Y
		STA		_tmp_buf+5
		LDA		(_lvl_macroC_ptr),Y
		STA		_tmp_buf+6
		LDA		(_lvl_macroD_ptr),Y
		STA		_tmp_buf+7
		LDA		(_lvl_attrs_ptr),Y			; also attributes
		STA		_tmp0
		PLA
		TAY
		LDA		_tmp0
		JSR		_ppu_macro_attr_transfer	; send attributes first
		LDA		#$02
		STA		_tmp_buf+2					; form macro tile chunk and sent
		STA		_tmp_buf+3					; it to ppu queue
		JSR		_ppu_offset_calc
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		PLA
		TAY
		PLA
		TAX
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
; this routine fills the room data in one single name table at once.
;
_ppu_room_screen_draw:
		LDY		#$00
loc_619F9:
		LDX		#$00
loc_619FB:
		JSR		_far_room_macro_block_read	; NOTE: looks unoptimal, but since we
		JSR		_far_ppu_macro_block_draw	; have optimization in mmc1_prg routine
		TXA									; here we will change bank once for
		CLC									; all loops
		ADC		#$10
		TAX
		BCC		loc_619FB
		TYA
		CLC
		ADC		#$10
		TAY
		CPY		#$F0
		BCC		loc_619F9
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_new_lvl_pos_set:
		JSR		_obj_new_lvl_pos_calc
		TXA
		PHA
		LDX		_cur_trd_slot
		PLA
		STA		_obj_x_pos_lo,X
		TYA
		STA		_obj_y_pos_lo,X
		LDA		_tmp_var0
		STA		_obj_x_pos_hi,X
		LDA		_tmp_var1
		STA		_obj_y_pos_hi,X
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_new_lvl_pos_calc:
		TXA
		CLC
		ADC		_ppu_scroll_pos_x
		TAX
		LDA		#$00
		ADC		_ppu_scroll_pos_x+1
		STA		_tmp_var0
		TYA
		CLC
		ADC		_ppu_scroll_pos_y
		BCS		loc_61A6E
		CMP		#$F0
		BCC		loc_61A71
loc_61A6E:
		ADC		#$0F
		SEC
loc_61A71:
		TAY
		LDA		#$00
		ADC		_ppu_scroll_pos_y+1
		STA		_tmp_var1
		RTS

; =============== S U B R O U T I N E ======n================================
; smilar to previous one, but with x wrapping for some reason, never used in
; this game.
;
;_unref_4:
;		TXA
;		CLC
;		ADC		_ppu_scroll_pos_x
;		PHA
;		LDA		#$00
;		ADC		_ppu_scroll_pos_x+1
;		LSR
;		PLA
;		ROR
;		LSR
;		LSR
;		TAX
;		TYA
;		CLC
;		ADC		_ppu_scroll_pos_y
;		BCS		loc_61A92
;		CMP		#$F0
;		BCC		loc_61A95
;loc_61A92:
;		ADC		#$0F
;		SEC
;loc_61A95:
;		PHA
;		LDA		#$00
;		ADC		_ppu_scroll_pos_y+1
;		LSR
;		PLA
;		ROR
;		LSR
;		LSR
;		TAY
;		RTS

; =============== S U B R O U T I N E ======n================================
; NEW, previously this function used raw object coordinates but not screen
; coordinates so calcs appears to be wrong when two objects are at the
; different room pages at the same time (still on the same screen!)
; this is the reason the fast slimes are too dumb sometimes... usually
; they should pursuit player in any direction, but when player goes out of
; current page that has fast slime, the latter turns in the opposite direction
; leave the screen at all...
;
_obj_to_beamer_dir_calc:
		LDX		_cur_trd_slot
		LDA		_obj_x_screen_pos+2
		STA		_var0
		LDA		_obj_y_screen_pos+2
		SEC
		SBC		#$10
		STA		_var1
		LDA		_obj_x_screen_pos,X
		STA		_var2
		LDA		_obj_y_screen_pos,X
		STA		_var3
		JMP		_point_to_point_dir_calc

; =============== S U B R O U T I N E ======n================================
_obj_to_obj_dir_calc:
		TAX
		LDA		_obj_x_screen_pos,X
		STA		_var0
		LDA		_obj_y_screen_pos,X
		STA		_var1
		LDX		_cur_trd_slot
		LDA		_obj_x_screen_pos,X
		STA		_var2
		LDA		_obj_y_screen_pos,X
		STA		_var3
		JMP		_point_to_point_dir_calc

; =============== S U B R O U T I N E ======n================================
_linear_dst_pos_calc:
		STA		_ptr0A
		STX		_ptr0A+1
		STY		_tmp2
		TYA
		AND		#$3F
		BNE		loc_61AE9
		TYA
		AND		#$40
		BEQ		loc_61AE3
		LDA		_ptr0A
		STA		_ptr06
		LDA		_ptr0A+1
		BPL		loc_61B0E
loc_61AE3:
		LDA		#$00
		STA		_ptr06
		BEQ		loc_61B0E
loc_61AE9:
		TAX
		LDA		_tmp2
		AND		#$40
		BEQ		loc_61AF5
		TXA
		EOR		#$3F
		TAX
		INX
loc_61AF5:
		LDA		byte_61B82,X
		PHA
		LDX		_ptr0A
		JSR		_mul8
		STX		_ptr06
		PLA
		LDX		_ptr0A+1
		JSR		_mul8
		CLC
		ADC		_ptr06
		STA		_ptr06
		TXA
		ADC		#$00
loc_61B0E:
		STA		_ptr06+1
		LDA		_tmp2
		BPL		loc_61B25
		LDA		#$00
		SEC
		SBC		_ptr06
		STA		_ptr06
		LDA		#$00
		SBC		_ptr06+1
		STA		_ptr06+1
loc_61B25:
		LDA		_tmp2
		AND		#$3F
		BNE		loc_61B3F
		LDA		_tmp2
		AND		#$40
		BNE		loc_61B39
		LDA		_ptr0A
		STA		_ptr08
		LDA		_ptr0A+1
		BPL		loc_61B64
loc_61B39:
		LDA		#$00
		STA		_ptr08
		BEQ		loc_61B64
loc_61B3F:
		TAX
		LDA		_tmp2
		AND		#$40
		BNE		loc_61B4B
		TXA
		EOR		#$3F
		TAX
		INX
loc_61B4B:
		LDA		byte_61B82,X
		PHA
		LDX		_ptr0A
		JSR		_mul8
		STX		_ptr08
		PLA
		LDX		_ptr0A+1
		JSR		_mul8
		CLC
		ADC		_ptr08
		STA		_ptr08
		TXA
		ADC		#$00
loc_61B64:
		STA		_ptr08+1
		LDA		_tmp2
		CMP		#$40
		BCC		loc_61B70
		CMP		#$C0
		BCC		locret_61B81
loc_61B70:
		LDA		#$00
		SEC
		SBC		_ptr08
		STA		_ptr08
		LDA		#$00
		SBC		_ptr08+1
		STA		_ptr08+1
locret_61B81:
		RTS
byte_61B82:
		.BYTE	$00,$06,$0C,$12,$19,$1F,$25,$2B,$31,$38,$3E,$44,$4A,$50,$56,$5C
		.BYTE	$61,$67,$6D,$73,$78,$7E,$83,$88,$8E,$93,$98,$9D,$A2,$A7,$AB,$B0
		.BYTE	$B5,$B9,$BD,$C1,$C5,$C9,$CD,$D1,$D4,$D8,$DB,$DE,$E1,$E4,$E7,$EA
		.BYTE	$EC,$EE,$F1,$F3,$F4,$F6,$F8,$F9,$FB,$FC,$FD,$FE,$FE,$FF,$FF,$FF

; =============== S U B R O U T I N E ======n================================
_point_to_point_dir_calc:
		LDA		_var0
		SEC
		SBC		_var2
		PHP
		BCS		loc_61BCE
		EOR		#$FF
		ADC		#$01
loc_61BCE:
		STA		_var0
		LDA		_var3
		SEC
		SBC		_var1
		PHP
		BCS		loc_61BDC
		EOR		#$FF
		ADC		#$01
loc_61BDC:
		TAY
		PLA
		LSR
		PLA
		ROL
		STA		_tmp0
		TXA
		PHA
		LDA		_tmp0
		AND		#$03
		PHA
		TYA
		BNE		loc_61BF1
		LDY		#$10
		BNE		loc_61C11
loc_61BF1:
		LDX		_var0
		LDA		#$00
		JSR		_div16
		STA		_var0
		STX		_var1
		LDY		#$10
loc_61BFE:
		LDA		_var1
		CMP		byte_61C4D,Y
		BCC		loc_61C0E
		BNE		loc_61C11
		LDA		_var0
		CMP		byte_61C3C,Y
		BCS		loc_61C11
loc_61C0E:
		DEY
		BNE		loc_61BFE
loc_61C11:
		PLA
		TAX
		STA		_tmp0
		TYA
		LSR		_tmp0
		BCS		loc_61C20
		STA		_var0
		LDA		#$11
		SBC		_var0
loc_61C20:
		LSR		_tmp0
		BCS		loc_61C2A
		STA		_var0
		LDA		#$11
		SBC		_var0
loc_61C2A:
		CLC
		ADC		byte_61C38,X
		AND		#$3F
		TAY
		PLA
		TAX
		TYA
		ASL
		ASL
		TAY
		RTS
byte_61C38:
		.BYTE	$20,$30,$10,$00
byte_61C3C:
		.BYTE	$00,$0C,$25,$40,$5B,$79,$99,$BD,$E8,$1A,$59,$AB,$1D,$CB,$FE,$BD
		.BYTE	$5B
byte_61C4D:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$01,$01,$01,$02,$02,$03,$06
		.BYTE	$14

; =============== S U B R O U T I N E ======n================================
_obj_to_obj_in_range_test:
		STY		_tmp0						; store desired range value
		LDY		_cur_trd_slot				; load current object idx in Y
		LDA		_obj_x_pos_lo,Y				; X has already object target idx
		SEC
		SBC		_obj_x_pos_lo,X				; calculate X pos delta
		STA		_tmp1
		LDA		_obj_x_pos_hi,Y
		SBC		_obj_x_pos_hi,X
		BCS		loc_61C80					; when negative, do ABS operation
		PHA
		LDA		#$00
		SEC
		SBC		_tmp1
		STA		_tmp1
		PLA
		EOR		#$FF
		ADC		#$00
loc_61C80:
		BNE		loc_61CD4					; if high nibble non zero, then too far
		LDA		_tmp1						; if zero, then compare with desired dist
		CMP		_tmp0
		BCS		loc_61CD4
		LDA		#$00						; if passed, do the same for Y delta
		STA		_var0
		LDA		_obj_y_pos_lo,Y				; for Y is little bit harder since
		SEC									; there is a case when both players
		SBC		_obj_y_pos_lo,X				; may be in different NT pages and
		STA		_tmp2						; thus need the warp by 16 pixels
		BCS		loc_61C98
		INC		_var0
loc_61C98:
		LDA		_obj_y_pos_hi,Y
		SBC		_obj_y_pos_hi,X
		BCS		loc_61CB4
		PHA
		LDA		_var0
		EOR		#$01
		STA		_var0
		LDA		#$00
		SEC
		SBC		_tmp2
		STA		_tmp2
		PLA
		EOR		#$FF
		ADC		#$00
loc_61CB4:
		STA		_tmp_var1
		CLC
		ADC		_var0
		ASL
		ASL
		ASL
		ASL
		STA		_var0
		LDA		_tmp2
		SEC
		SBC		_var0
		STA		_tmp2
		LDA		_tmp_var1
		SBC		#$00
		BNE		loc_61CD4
		LDA		_tmp2
		CMP		_tmp0
		BCS		loc_61CD4					; then compare Y also
		SEC
		RTS
loc_61CD4:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
; the main object gandler routine for levels
; get the data pointer, then fetch room data and wait if player get to
; corresponding room, then deploy enemies max 4 at once on the same screen
; when objects are removed from level, adds the rest one until reach
; next room marker, then again wait when player arrive in this room
; a special command for checkpoint does increment for current checkpoint
; position index, next time engine restarting the level, room data
; will start from previously saved checkpoint data offset
;
_nbgsub_room_obj_handler:
		LDA		_prg_cur_bank				; backup current PRG bank
		PHA
		LDA		_lvl_data_prg_bank			; set the level data bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_lvl_objects_ptr+1			; test if object list isn't empty
		BNE		loc_61CE7
		JMP		_ld1_exit
loc_61CE7:
		LDY		#$00						; read next entry
		LDA		(_lvl_objects_ptr),Y
		BPL		loc_61D19
		INY									; special commands goes here
		LDA		(_lvl_objects_ptr),Y
		BNE		loc_61CF6
		STA		_lvl_objects_ptr+1			; CMD FF 00, end of list, write 0 to high ptr nibble
		BEQ		_ld1_exit
loc_61CF6:
		CMP		#$01
		BNE		loc_61D0D
		INY									; CMD FF 01, room idx, wait for player get to
		LDA		(_lvl_objects_ptr),Y		; particular room with corresponding index
		CMP		_cur_lvl_room_idx			; or just exit, no objects are set in wrong rooms
		BNE		_ld1_exit					; also order of rooms is linear, you couldn't skip
		LDA		_pal_fade_req_list			; or change order.
		BMI		_ld1_exit
		LDA		_active_door_data_pos
		BPL		_ld1_exit
		BMI		loc_61D6A
loc_61D0D:
;		CMP		#$02						; REDUNDANT, since we have all data correct here
;		BNE		_assert_error
		INC		_lvl_cur_checkpoint_idx		; CMD FF 02, checkpoint increment, fetch another comand
		BNE		loc_61D6A
;_assert_error:
;		JMP		_assert_error				; original debug assert if any wrong commands occurs
loc_61D19:
		STA		_tmp0						; store object idx
		STY		_var0
		INY
		LDA		(_lvl_objects_ptr),Y		; fetch object data finally
		STA		_tmp1
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp_var0
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp2
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp_var1
		LDX		_tmp0
		LDA		_scr_flags,X				; fetch objects flags to see if extra arguments assigned
		STA		_var7
		ASL		_var7
		BCC		loc_61D41
		INY
		LDA		(_lvl_objects_ptr),Y		; load sargs with extra parameters
		STA		_var0
loc_61D41:
		ASL		_var7
		BCC		loc_61D4A
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_var1
loc_61D4A:
		ASL		_var7
		BCC		loc_61D53
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_var2
loc_61D53:
		TYA
		PHA
		LDX		_tmp1						; finally deploy the object
		LDY		_tmp2
		LDA		#$06
		STA		_var4						; start from slot 6
#if DEBUG==1
		LDA		#DEBUG_MAX_ENEMY
#else
		LDA		#$0A						; up to slot 9, so max 4 objects at a time on the screen
#endif
		STA		_var5
		LDA		_tmp0
		JSR		_thread_lib_load			; return C=1 if can't add any objects
		PLA
		TAY
		BCS		_ld1_exit					; if can't add, exit manager until any slot opens
loc_61D6A:
		INY									; adjust pointer position to the next entry
		TYA
		CLC
		ADC		_lvl_objects_ptr
		STA		_lvl_objects_ptr
		BCC		_ld1_exit
		INC		_lvl_objects_ptr+1
_ld1_exit:
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
; look for a beginning of the object data section corresponding to current
; checkpoint index to continue the game after game over.
;
_nsub_lvl_room_objects_init:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
loc_61D85:
		LDY		#$00
		LDA		(_lvl_objects_ptr),Y
		BPL		loc_61DA2
		INY
		LDA		(_lvl_objects_ptr),Y
		CMP		#$01
		BNE		loc_61D96
		INY
		JMP		loc_61DBD
loc_61D96:
		CMP		#$02
		BNE		loc_61D9F
		INC		_lvl_cur_checkpoint_idx
		BNE		loc_61DBD
loc_61D9F:
		JMP		loc_61D9F
loc_61DA2:
		PHA
		INY
		INY
		INY
		INY
		PLA
		TAX
		LDA		_scr_flags,X
		STA		_var7
		ASL		_var7
		BCC		loc_61DB3
		INY
loc_61DB3:
		ASL		_var7
		BCC		loc_61DB8
		INY
loc_61DB8:
		ASL		_var7
		BCC		loc_61DBD
		INY
loc_61DBD:
		INY
		TYA
		CLC
		ADC		_lvl_objects_ptr
		STA		_lvl_objects_ptr
		BCC		loc_61DC8
		INC		_lvl_objects_ptr+1
loc_61DC8:
		LDA		_lvl_cur_checkpoint_idx
		CMP		_lvl_last_checkpoint_idx
		BCC		loc_61D85
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
_obj_to_beam_ctest:
		LDA		_trds_obj_idx+3				; check if beam object deployed
		BMI		loc_61E28
		LDA		_trds_args0+3				; also check if nothing is catched already
		BPL		loc_61E28
		TXA
		PHA
		LDA		_trds_args1+3				; get the beam direction value from arg1
		ASL
		ROL
		ROL
		TAX
		PLA
		ADC		byte_61E2A,X				; calculate bounding box
		STA		_var0
		TYA
		CLC
		ADC		byte_61E2E,X
		STA		_var1
		LDX		_cur_trd_slot				; get current object screen position
		LDA		_obj_out_of_screen,X
		BNE		loc_61E28
		LDA		_obj_x_screen_pos,X
		SEC
		SBC		_beam_target_x_pos			; calculate distance from beam target point
		BCS		loc_61E04
		EOR		#$FF
		ADC		#$01
loc_61E04:
		CMP		_var0						; test if get into the area
		BCS		loc_61E28
		LDA		_obj_y_screen_pos,X
		SEC
		SBC		_beam_target_y_pos
		BCS		loc_61E13
		EOR		#$FF
		ADC		#$01
loc_61E13:
		CMP		_var1
		BCS		loc_61E28
		LDX		_cur_trd_slot				; if yes, switch beam to active state,
		LDA		#$01						; set object's args0 "beamed" flag
		STA		_trds_args0,X				; also save objects idx to args0 of beam
		STX		_trds_args0+3
		LDX		#$03
		JSR		_thread_reload_param_ex
		.WORD	_scr_beam_active
		SEC
		RTS
loc_61E28:
		CLC
		RTS
byte_61E2A:
		.BYTE	$01,$14,$01,$14
byte_61E2E:
		.BYTE	$14,$01,$14,$01

#if TWO_PLAYER_MODE==1
; =============== S U B R O U T I N E ======n================================
_obj_to_player_ctest:
		STX		_var0
		STY		_var1
		LDX		_cur_trd_slot				; this extra allows to have correct collision
		LDA		_obj_out_of_screen,X		; tests for object out of the screen (now allowed)
		BNE		locret_61E6C
		LDA		_obj_x_screen_pos,X
		STA		_tmp1C
		LDA		_obj_y_screen_pos,X
		STA		_tmp1D
		LDA		_players_inv_timer
		BNE		loc_61E6B
		LDX		#$02
		JSR		_obj_to_player_ctest_ex
		BCS		loc_61E6B
		LDA		_players_hit_flag
#if DEBUG==1
;		ORA		#$00
#else
		ORA		#$01
#endif
		STA		_players_hit_flag
loc_61E6B:
		LDA		_players_inv_timer+1
		BNE		locret_61E6C
		LDX		#$04
		JSR		_obj_to_player_ctest_ex
		BCS		locret_61E6C
		LDA		_players_hit_flag+1
#if DEBUG==1
;		ORA		#$00
#else
		ORA		#$01
#endif
		STA		_players_hit_flag+1
locret_61E6C:
		RTS

; =============== S U B R O U T I N E ======n================================
_prize_to_player_ctest:
		STX		_var0
		STY		_var1
		LDX		_cur_trd_slot
		LDA		_obj_out_of_screen,X		; NEW, this extra allows to have correct collision
		BNE		locret_61E6C				; tests for object out of the screen (now allowed)
		LDA		_obj_x_screen_pos,X
		STA		_tmp1C
		LDA		_obj_y_screen_pos,X
		STA		_tmp1D
		LDX		#$02
		JSR		_obj_to_player_ctest_ex
		BCC		.prize_scores_apply
		LDX		#$04
		JSR		_obj_to_player_ctest_ex
		BCS		locret_61E6E
.prize_scores_apply:
		LDX		_cur_trd_slot				; when collide, shut down the money bag thread
		LDA		#$FF						; and add a scores from its ARG2 parameter
		STA		_trds_obj_idx,X
		LDA		_trds_args2,X
		JSR		_scores_add					; add scores from sarg2 var
		LDA		#_snd0D_idx					; play a sound
		JMP		_far_prg6_apu_snd_load
locret_61E6E:
		RTS

; =============== S U B R O U T I N E ======n================================
; TODO: there are a couple of similar calculations here and in PRG1,
; maybe we may merge them!
;
_obj_to_player_ctest_ex:
		LDA		_tmp1C
		SEC
		SBC		_obj_x_screen_pos,X
		BCS		loc_61E51
		EOR		#$FF
		ADC		#$01
loc_61E51:
		CMP		_var0
		BCS		locret_61E6D
		LDA		_tmp1D
		SEC
		SBC		_obj_y_screen_pos,X
		BCS		loc_61E5F
		EOR		#$FF
		ADC		#$01
loc_61E5F:
		CMP		_var1
locret_61E6D:
		RTS
#else
; =============== S U B R O U T I N E ======n================================
_obj_to_player_ctest:
		LDA		_players_inv_timer
		BNE		locret_61E6B
		JSR		_obj_to_player_ctest_ex
		BCS		locret_61E6B
		LDA		_players_hit_flag
#if DEBUG==1
;		ORA		#$00
#else
		ORA		#$01
#endif
		STA		_players_hit_flag
locret_61E6B:
		RTS

; =============== S U B R O U T I N E ======n================================
; NOTE: most probably this routine may be intended to be used more than
; for collecting one money bag, presumably for more bonuses during the game
; like boots and wests... this is the reason they uses scores to be
; passed to this routine from object itself...
;
_prize_to_player_ctest:
		JSR		_obj_to_player_ctest_ex
		BCS		locret_61EA9
		LDX		_cur_trd_slot				; when collide, shut down the money bag thread
		LDA		#$FF						; and add a scores from its ARG2 parameter
		STA		_trds_obj_idx,X
		LDA		_trds_args2,X
		JSR		_scores_add					; add scores from sarg2 var
		LDA		#_snd0D_idx					; play a sound
		JSR		_far_prg6_apu_snd_load
locret_61EA9:
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_to_player_ctest_ex:
		STX		_var0						; original game does enemy collision test
		STY		_var1						; only for beamer player.
		LDX		_cur_trd_slot				; then read current object screen position
		LDA		_obj_out_of_screen,X		; NEW, this extra allows to have correct collision
		BEQ		loc_61E86					; tests for object out of the screen
		SEC
		RTS
loc_61E86:
		LDA		_obj_x_screen_pos,X
		SEC
		SBC		_obj_x_screen_pos+2
		BCS		loc_61E87
		EOR		#$FF
		ADC		#$01
loc_61E87:
		CMP		_var0
		BCS		locret_61EAA
		LDA		_obj_y_screen_pos,X
		SEC
		SBC		_obj_y_screen_pos+2
		BCS		loc_61E98
		EOR		#$FF
		ADC		#$01
loc_61E98:
		CMP		_var1
locret_61EAA:
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_bin2dec:
		STA		_var4						; converts 16-bit integer value
		STX		_var5						; to 6-byte decimal value
		LDX		#$00
loc_61EB0:
		LDY		#$00
loc_61EB2:
		LDA		_var5
		CMP		byte_61EE1,X
		BCC		loc_61ED4
		BNE		loc_61EC2
		LDA		_var4
		CMP		byte_61EDD,X
		BCC		loc_61ED4
loc_61EC2:
		LDA		_var4
		SEC
		SBC		byte_61EDD,X
		STA		_var4
		LDA		_var5
		SBC		byte_61EE1,X
		STA		_var5
		INY
		BNE		loc_61EB2
loc_61ED4:
		TYA
		STA		_var0,X
		INX
		CPX		#$04
		BCC		loc_61EB0
		RTS
byte_61EDD:
		.BYTE	$10,$E8,$64,$0A
byte_61EE1:
		.BYTE	$27,$03,$00,$00

; =============== S U B R O U T I N E ======n================================
_print_num99999:
		JSR		_ppu_offset_calc			; covert 5-byte decimal value to
		LDX		#$00						; a string with removing leftmost zeroes
		STX		_var5						; then print it
loc_61EEC:
		LDA		_var0,X
		ORA		_var5
		BNE		loc_61EFA
		CPX		#$04
		BEQ		loc_61EFA
		LDA		#$20
		BNE		loc_61F00
loc_61EFA:
		INC		_var5
		LDA		_var0,X
		ORA		#$30
loc_61F00:
		STA		_tmp_buf+4,X
		INX
		CPX		#$05
		BCC		loc_61EEC
		LDA		#$05
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_offset_calc:
		TXA									; convert X/Y tile screen position
		AND		#$1F						; to PPU offset
		STA		_tmp0
		LDA		#$00
		STA		_ptr08+1
		TYA
		ASL
		ASL
		ASL
		ASL
		ROL		_ptr08+1
		ASL
		ROL		_ptr08+1
		ADC		_tmp0
		STA		_ptr08
		TYA
		AND		#$20
		STA		_tmp0
		TXA
		AND		#$20
		LSR
		ORA		_tmp0
		LSR
		LSR
		LSR
		STA		_tmp0
		LDA		_mmc1_ctrl_shadow			; also adjust the high nibble according
		AND		#$01						; to current mirroring setting
		ORA		_tmp0
		TAX
		LDA		byte_61F4E,X
		ORA		_ptr08+1
		STA		_ptr08+1
		RTS
byte_61F4E:
		.BYTE	$20,$20,$24,$28,$24,$28,$20,$20

; =============== S U B R O U T I N E ======n================================
_ppu_macro_attr_transfer:
		JSR		_ppu_attr_ofs_calc			; calculate attributes values offsets
		STA		_tmp0						; then extract corresponding attr bits pos
		TXA
		PHA
		AND		#$02
		LSR
		STA		_var0
		TYA
		PHA
		AND		#$02
		ORA		_var0
		STA		_var0
		TAX
		LDA		_tmp0
loc_61F6D:
		DEX
		BMI		loc_61F74
		ASL
		ASL
		BCC		loc_61F6D
loc_61F74:
		STA		_tmp0
		LDX		_var0
		LDY		#$00
		LDA		(_ptr06),Y
		AND		byte_61F98,X
		ORA		_tmp0
		STA		(_ptr06),Y
		STA		_tmp_buf+$A
		LDA		#$01
		STA		_tmp_buf+8
		STA		_tmp_buf+9
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+8
		PLA
		TAY
		PLA
		TAX
		RTS
; TODO: accidentally, this attr maksk list is the same as _catcher_turns_masks
; which may be also merged.
;
byte_61F98:
		.BYTE	$FC,$F3,$CF,$3F

; =============== S U B R O U T I N E ======n================================
_ppu_attr_ofs_calc:
		PHA
		TXA
		PHA
		AND		#$1C
		LSR
		LSR
		STA		_var0
		TYA
		AND		#$20
		STA		_tmp0
		TXA
		AND		#$20
		LSR
		ORA		_tmp0
		LSR
		LSR
		LSR
		STA		_tmp0
		LDA		_mmc1_ctrl_shadow
		AND		#$01
		ORA		_tmp0
		TAX
		TYA
		AND		#$1C
		ASL
		ADC		_var0
		PHA
		ADC		_attrs_pos_list_lo,X
		STA		_ptr08
		LDA		#$00
		ADC		_attrs_pos_list_hi,X
		STA		_ptr08+1
		TXA
		LSR
		TAX
		PLA
		CLC
		ADC		_attr_bufs_list_lo,X
		STA		_ptr06
		LDA		#$00
		ADC		_attr_bufs_list_hi,X
		STA		_ptr06+1
		PLA
		TAX
		PLA
		RTS
_attrs_pos_list_lo:
		.BYTE	$C0,$C0,$C0,$C0,$C0,$C0,$C0,$C0
_attrs_pos_list_hi:
		.BYTE	$23,$23,$27,$2B,$27,$2B,$23,$23
_attr_bufs_list_lo:
		.BYTE	<[_attr_buf_pageA]
		.BYTE	<[_attr_buf_pageB]
		.BYTE	<[_attr_buf_pageB]
		.BYTE	<[_attr_buf_pageA]
_attr_bufs_list_hi:
		.BYTE	>[_attr_buf_pageA]
		.BYTE	>[_attr_buf_pageB]
		.BYTE	>[_attr_buf_pageB]
		.BYTE	>[_attr_buf_pageA]

; =============== S U B R O U T I N E ======n================================
_ppu_nt_clear:
		STA		_tmp_buf+4					; set ppu fill value to buf
		LDA		byte_6201B,X				; TODO: low nibble always 00, redundant!
		STA		_tmp_buf
		LDA		byte_6201F,X				; set offset
		STA		_tmp_buf+1					; set rect params: $20x$1E - full screen
		LDA		#$20
		STA		_tmp_buf+2
		LDA		#$1E
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_repeat	; send buffer to PPU in repeat mode
		.WORD	_tmp_buf
		RTS
byte_6201B:
		.BYTE	$00,$00,$00,$00
byte_6201F:
		.BYTE	$20,$24,$28,$2C

; =============== S U B R O U T I N E ======n================================
;_ppu_arrt_clear_unref:
;		STA		_tmp_buf+4					; similar routine but for clear attributes
;		LDA		_unused_unref,X				; not used here also
;		STA		_tmp_buf
;		LDA		_unused_unref_0,X
;		STA		_tmp_buf+1
;		LDA		#$20
;		STA		_tmp_buf+2
;		LDA		#$02
;		STA		_tmp_buf+3
;		JSR		_ppu_res_send_param_repeat
;		.WORD	_tmp_buf
;		RTS
;_unused_unref:
;		.BYTE	$C0,$C0,$C0,$C0
;_unused_unref_0:
;		.BYTE	$23,$27,$27,$23

; =============== S U B R O U T I N E ======n================================
_scroll_page_set:
		PHA
		AND		#$01
		STA		_ppu_scroll_pos_x+1
		PLA
		LSR
		STA		_ppu_scroll_pos_y+1
		LDA		#$00
		STA		_ppu_scroll_pos_x
		STA		_ppu_scroll_pos_y
		RTS

; =============== S U B R O U T I N E ======n================================
;_unref_6:
;		JSR		_wait_for_nmi
;		DEX
;		BNE		_unref_6
;		RTS

; =============== S U B R O U T I N E ======n================================
;_init_pal_fade_unused:
;		LDX		#$07
;loc_62063:
;		STA		_pal_fade_req_list,X
;		DEX
;		BPL		loc_62063
;		RTS

; =============== S U B R O U T I N E ======n================================
_patch_pal_load:
		STA		_ptr06
		STX		_ptr06+1
		TYA
		PHA
		ASL
		ASL
		ADC		#<[_pal_buf]
		STA		_ptr08
		LDA		#$00
		ADC		#>[_pal_buf]
		STA		_ptr08+1
		LDY		#$03
loc_6207D:
		LDA		(_ptr06),Y
		STA		(_ptr08),Y
		DEY
		BPL		loc_6207D
		LDY		#$00
		LDA		(_ptr06),Y
		LDX		#$07
loc_6208A:
		STA		_pal_buf,Y
		INY
		INY
		INY
		INY
		DEX
		BPL		loc_6208A
		PLA
		TAX
		ASL
		ASL
		PHA
		ADC		#<[_pal_buf]
		STA		_ptr06
		LDA		#$00
		ADC		#>[_pal_buf]
		STA		_ptr06+1
		LDY		#$00
		LDA		_pal_fade_req_list,X
		BMI		loc_620D2
		CMP		#$05
		BCC		loc_620AF
		LDA		#$04
loc_620AF:
		TAX
loc_620B0:
		LDA		(_ptr06),Y
		CMP		#$0F
		BNE		loc_620B8
		LDA		#$F0
loc_620B8:
		CLC
		ADC		byte_621B8,X
		CMP		#$F0
		BNE		loc_620C2
		LDA		#$0F
loc_620C2:
		CMP		#$40
		BCC		loc_620C8
		LDA		#$30
loc_620C8:
		STA		_tmp_buf+4,Y
		INY
		CPY		#$04
		BCC		loc_620B0
		BCS		loc_620F0
loc_620D2:
		CMP		#$FC
		BCS		loc_620D8
		LDA		#$FC
loc_620D8:
		EOR		#$FF
		CLC
		ADC		#$01
		TAX
loc_620DE:
		LDA		(_ptr06),Y
		SEC
		SBC		byte_621B8,X
		BCS		loc_620E8
		LDA		#$0F
loc_620E8:
		STA		_tmp_buf+4,Y
		INY
		CPY		#$04
		BCC		loc_620DE
loc_620F0:
		PLA
		CLC
		ADC		#$00
		STA		_tmp_buf
		LDA		#$00
		ADC		#$3F
		STA		_tmp_buf+1
		LDA		#$04
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param
		.WORD	_tmp_buf
		RTS

; =============== S U B R O U T I N E ======n================================
_spr_pal_load:
		STA		_ptr06
		STX		_ptr06+1
		LDY		#$0F
loc_62114:
		LDA		(_ptr06),Y
		STA		_pal_buf+$10,Y
		DEY
		BPL		loc_62114
		JMP		_pal_def_color_set

; =============== S U B R O U T I N E ======n================================
_bg_pal_load:
		LDY		#$0F
		BNE		_pal_load_ex

; =============== S U B R O U T I N E ======n================================
_full_pal_load:
		LDY		#$1F

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_pal_load_ex:
		STA		_ptr06
		STX		_ptr06+1
loc_62129:
		LDA		(_ptr06),Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_62129

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_pal_def_color_set:
		LDY		#$00
		LDA		(_ptr06),Y
		LDX		#$07
loc_62137:
		STA		_pal_buf,Y
		INY
		INY
		INY
		INY
		DEX
		BPL		loc_62137

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_full_pal_fade:
		LDY		#$00
loc_62143:
		TYA
		LSR
		LSR
		TAX
		LDA		_pal_fade_req_list,X
		BMI		loc_6217A
		CMP		#$05
		BCC		loc_62151
		LDA		#$04
loc_62151:
		TAX
loc_62152:
		LDA		_pal_buf,Y
		CMP		#$0F
		BNE		loc_6215B
		LDA		#$F0
loc_6215B:
		CLC
		ADC		byte_621B8,X
		CMP		#$F0
		BNE		loc_62165
		LDA		#$0F
loc_62165:
		CMP		#$40
		BCC		loc_6216B
		LDA		#$30
loc_6216B:
		STA		_tmp_buf+4,Y
		INY
		TYA
		AND		#$03
		BNE		loc_62152
		CPY		#$20
		BCC		loc_62143
		BCS		loc_6219E
loc_6217A:
		CMP		#$FC
		BCS		loc_62180
		LDA		#$FC
loc_62180:
		EOR		#$FF
		CLC
		ADC		#$01
		TAX
loc_62186:
		LDA		_pal_buf,Y
		SEC
		SBC		byte_621B8,X
		BCS		loc_62191
		LDA		#$0F
loc_62191:
		STA		_tmp_buf+4,Y
		INY
		TYA
		AND		#$03
		BNE		loc_62186
		CPY		#$20
		BCC		loc_62143
loc_6219E:
		LDA		#$00
		STA		_tmp_buf
		LDA		#$3F
		STA		_tmp_buf+1
		LDA		#$20
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param
		.WORD	_tmp_buf
		RTS
byte_621B8:
		.BYTE	$00,$10,$20,$30,$40

; =============== S U B R O U T I N E ======n================================
; fast div, input  A = divident low nibble
;                  X = divident high nibble
;                  Y = divider
;           result A = result low nibble
;                  X = result high nibble
_div16:
		CPY		#$02						; we don't mul by 0 and 1 by obvious reasons
		BCC		locret_621EB
		DEY
		DEY
		STA		_tmp0
		TXA
		PHA
		LDA		_tmp0
		LDX		_div16_tbl,Y				; and yes, this is a fixed point multiplication
		JSR		_mul8						; magic!
		STX		_tmp1
		PLA
		STA		_tmp0
		LDA		_tmp1
		PHA
		LDA		_tmp0
		LDX		_div16_tbl,Y
		JSR		_mul8						; two multiply to div!
		STA		_tmp0
		PLA
		CLC
		ADC		_tmp0
		PHA
		TXA
		ADC		#$00
		TAX
		PLA
locret_621EB:
		RTS
_div16_tbl:
		.BYTE	$80,$55,$40,$33,$2A,$24,$20,$1C,$19,$17,$15,$13,$12,$11,$10,$0F
		.BYTE	$0E,$0D,$0C,$0C,$0B,$0B,$0A,$0A,$09,$09,$09,$08,$08,$08,$08,$07
		.BYTE	$07,$07,$07,$06,$06,$06,$06,$06,$06,$05,$05,$05,$05,$05,$05,$05
		.BYTE	$05,$05,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01

; =============== S U B R O U T I N E ======n================================
_rand:
		STA		_tmp0						; NOTE: this routine kinda heavy
		TXA									; for frequent usage, it used mostly once
		PHA									; per phase of most object targeted randomly.
		LDA		_tmp0						; also it called only when needed, so most
		PHA									; of the other time _random_seed is the same.
		LDA		_random_seed				; other games may call randomizers constantly
		LDX		#$0B						; in system loop, then just read seed value
loc_622F5:
		ASL		_random_seed
		ROL		_random_seed+1
		ROL
		ROL
		EOR		_random_seed
		ROL
		EOR		_random_seed
		LSR
		LSR
		EOR		#$FF
		AND		#$01
		ORA		_random_seed
		STA		_random_seed
		DEX
		BNE		loc_622F5
		TAX
		PLA
		BEQ		loc_62314
		JSR		_mul8
loc_62314:
		STX		_tmp1
		PLA
		TAX
		LDA		_tmp1
		RTS

; =============== S U B R O U T I N E ======n================================
; fast mul8 routine however uses as much as 512k of div tables
;
_mul8:
		STA		_tmp0
		STX		_tmp1
		STX		_var0
		AND		_tmp1
		AND		#$01
		STA		_var1
		LDX		_tmp0
		LDA		_mul8_tbl1,X
		STA		_var2
		CLC
		LDA		_var1
		ADC		_mul8_tbl0,X
		LDX		_tmp1
		ADC		_mul8_tbl0,X
		STA		_var1
		LDA		_var2
		ADC		_mul8_tbl1,X
		STA		_var2
		LDA		_tmp0
		CMP		_tmp1
		BCS		loc_6234C
		STA		_var0
		LDA		_tmp1
loc_6234C:
		SEC
		SBC		_var0
		TAX
		LDA		_var1
		SBC		_mul8_tbl0,X
		STA		_tmp0
		LDA		_var2
		SBC		_mul8_tbl1,X
		TAX
		LDA		_tmp0
		RTS
_mul8_tbl0:
		.BYTE	$00,$00,$02,$04,$08,$0C,$12,$18,$20,$28,$32,$3C,$48,$54,$62,$70
		.BYTE	$80,$90,$A2,$B4,$C8,$DC,$F2,$08,$20,$38,$52,$6C,$88,$A4,$C2,$E0
		.BYTE	$00,$20,$42,$64,$88,$AC,$D2,$F8,$20,$48,$72,$9C,$C8,$F4,$22,$50
		.BYTE	$80,$B0,$E2,$14,$48,$7C,$B2,$E8,$20,$58,$92,$CC,$08,$44,$82,$C0
		.BYTE	$00,$40,$82,$C4,$08,$4C,$92,$D8,$20,$68,$B2,$FC,$48,$94,$E2,$30
		.BYTE	$80,$D0,$22,$74,$C8,$1C,$72,$C8,$20,$78,$D2,$2C,$88,$E4,$42,$A0
		.BYTE	$00,$60,$C2,$24,$88,$EC,$52,$B8,$20,$88,$F2,$5C,$C8,$34,$A2,$10
		.BYTE	$80,$F0,$62,$D4,$48,$BC,$32,$A8,$20,$98,$12,$8C,$08,$84,$02,$80
		.BYTE	$00,$80,$02,$84,$08,$8C,$12,$98,$20,$A8,$32,$BC,$48,$D4,$62,$F0
		.BYTE	$80,$10,$A2,$34,$C8,$5C,$F2,$88,$20,$B8,$52,$EC,$88,$24,$C2,$60
		.BYTE	$00,$A0,$42,$E4,$88,$2C,$D2,$78,$20,$C8,$72,$1C,$C8,$74,$22,$D0
		.BYTE	$80,$30,$E2,$94,$48,$FC,$B2,$68,$20,$D8,$92,$4C,$08,$C4,$82,$40
		.BYTE	$00,$C0,$82,$44,$08,$CC,$92,$58,$20,$E8,$B2,$7C,$48,$14,$E2,$B0
		.BYTE	$80,$50,$22,$F4,$C8,$9C,$72,$48,$20,$F8,$D2,$AC,$88,$64,$42,$20
		.BYTE	$00,$E0,$C2,$A4,$88,$6C,$52,$38,$20,$08,$F2,$DC,$C8,$B4,$A2,$90
		.BYTE	$80,$70,$62,$54,$48,$3C,$32,$28,$20,$18,$12,$0C,$08,$04,$02,$00
_mul8_tbl1:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$03,$03,$03,$03,$03,$03,$04,$04
		.BYTE	$04,$04,$04,$05,$05,$05,$05,$05,$06,$06,$06,$06,$07,$07,$07,$07
		.BYTE	$08,$08,$08,$08,$09,$09,$09,$09,$0A,$0A,$0A,$0A,$0B,$0B,$0B,$0C
		.BYTE	$0C,$0C,$0D,$0D,$0D,$0E,$0E,$0E,$0F,$0F,$0F,$10,$10,$10,$11,$11
		.BYTE	$12,$12,$12,$13,$13,$13,$14,$14,$15,$15,$15,$16,$16,$17,$17,$18
		.BYTE	$18,$18,$19,$19,$1A,$1A,$1B,$1B,$1C,$1C,$1D,$1D,$1E,$1E,$1F,$1F
		.BYTE	$20,$20,$21,$21,$22,$22,$23,$23,$24,$24,$25,$25,$26,$26,$27,$27
		.BYTE	$28,$29,$29,$2A,$2A,$2B,$2B,$2C,$2D,$2D,$2E,$2E,$2F,$30,$30,$31
		.BYTE	$32,$32,$33,$33,$34,$35,$35,$36,$37,$37,$38,$39,$39,$3A,$3B,$3B
		.BYTE	$3C,$3D,$3D,$3E,$3F,$3F,$40,$41,$42,$42,$43,$44,$45,$45,$46,$47
		.BYTE	$48,$48,$49,$4A,$4B,$4B,$4C,$4D,$4E,$4E,$4F,$50,$51,$52,$52,$53
		.BYTE	$54,$55,$56,$56,$57,$58,$59,$5A,$5B,$5B,$5C,$5D,$5E,$5F,$60,$61
		.BYTE	$62,$62,$63,$64,$65,$66,$67,$68,$69,$6A,$6A,$6B,$6C,$6D,$6E,$6F
		.BYTE	$70,$71,$72,$73,$74,$75,$76,$77,$78,$79,$7A,$7B,$7C,$7D,$7E,$7F

; =============== S U B R O U T I N E ======n================================
_nsub_prize_sequence_test:
		LDA		_prg_cur_bank				; routine used in a catch anim script
		PHA									; to test if enemies catched in a particular
		LDA		#$01						; sequence. need to activate bonus prize -
		STA		_prg_cur_bank				; bag with money.
		JSR		_mmc1_prg_safe				; all data is a part of level handlers
		LDY		#$00
		LDA		(_room_prize_sequence_ptr),Y
		LDX		_cur_trd_slot
		CMP		_trds_obj_idx,X
		BNE		loc_62583
		INC		_room_prize_sequence_ptr
		BNE		loc_6257B
		INC		_room_prize_sequence_ptr+1
loc_6257B:
		LDA		(_room_prize_sequence_ptr),Y; when list completed, zero the pointer
		BNE		loc_62583					; this will activate hidden object
		STA		_room_prize_sequence_ptr
		STA		_room_prize_sequence_ptr+1
loc_62583:
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
_nsub_obj_scores_add:
		LDA		_scores_obj_value			; collision test must init this var first

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_scores_add:
		CLC
		ADC		_scores						; increment scores by given value
		STA		_scores
		BCC		loc_62598
		INC		_scores+1
loc_62598:
		LDA		_scores+1					; compare with next life score value
		CMP		_scores_to_next_life+1		; compare with current score range
		BCC		loc_625DF					; if current score equal or higher
		BNE		loc_625AA					; than current extend,
		LDA		_scores
		CMP		_scores_to_next_life
		BCC		loc_625DF
loc_625AA:
		LDA		_scores_to_next_life+1		; check if current extend equal to 1st
		CMP		_scores_1st_extend+1		; then load 2nd extend as next one
		BNE		loc_625C3
		LDA		_scores_to_next_life
		CMP		_scores_1st_extend
		BNE		loc_625C3
		LDY		_scores_2nd_extend
		LDA		_scores_2nd_extend+1
		JMP		loc_625D1
loc_625C3:
		LDA		_scores_to_next_life		; in all other cases all next extends are
		CLC									; the same as 2nd one
		ADC		_scores_2nd_extend
		TAY
		LDA		_scores_to_next_life+1
		ADC		_scores_2nd_extend+1
loc_625D1:
		STY		_scores_to_next_life
		STA		_scores_to_next_life+1
		INC		_players_lives
#if TWO_PLAYER_MODE==1
		INC		_players_lives+1
#endif
		LDA		#_snd1E_idx
		JSR		_far_prg6_apu_snd_load
loc_625DF:
		LDA		_scores+1					; test for hi-scores update
		CMP		_hi_scores+1
		BCC		locret_625FD
		BNE		loc_625F1
		LDA		_scores
		CMP		_hi_scores
		BCC		locret_625FD
loc_625F1:
		LDA		_scores
		STA		_hi_scores
		LDA		_scores+1
		STA		_hi_scores+1
locret_625FD:
		RTS

; =============== S U B R O U T I N E ======n================================
;_nsub_scores_display_unref:
;		JSR		_scr_getc					; never called from script here
;		PHA
;		JSR		_scr_getc
;		PHA
;		JMP		_printf_scores_ex

; =============== S U B R O U T I N E ======n================================
_printf_scores:
		TXA									; actual used sub is native called
		PHA									; to draw status/complete screen
		TYA
		PHA

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_printf_scores_ex:
		LDA		_scores						; common scores printf routine
		LDX		_scores+1
		JSR		_bin2dec					; convert to decimal first
		PLA									; retrieve the screen position
		TAY									; and draw with leftmost zeroes
		PLA									; trimmed
		TAX
		JMP		_print_num99999

; =============== S U B R O U T I N E ======n================================
_nsub_hi_scores_display:
		JSR		_scr_getc					; this nsub routine called from
		PHA									; title script
		JSR		_scr_getc
		PHA
		JMP		_printf_hi_scores_ex

; =============== S U B R O U T I N E ======n================================
_printf_hi_scores:
		TXA									; also used for status/complete screens
		PHA
		TYA
		PHA

; =============== S U B R O U T I N E ======n================================
_printf_hi_scores_ex:
		LDA		_hi_scores					; common sub different only in var used
		LDX		_hi_scores+1
		JSR		_bin2dec
		PLA
		TAY
		PLA
		TAX
		JMP		_print_num99999

; =============== S U B R O U T I N E ======n================================
_nsub_apu_mus_load:
		JSR		_scr_getc					; helper to call this routine from script

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_far_prg6_apu_mus_load:
		STA		_apu_cur_mus_idx			; helper to call from native procedures

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_far_prg6_apu_mus_load_ex:
		STA		_tmp0						; main mus load routine here
		LDA		_prg_cur_bank				; executed here for pause
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_apu_mus_load
		PLA
		TAY
		PLA
		TAX
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
_nsub_apu_snd_load:
		JSR		_scr_getc					; same for snd for script loading

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_far_prg6_apu_snd_load:
		STA		_tmp0						; the currently played snd index
		LDA		_prg_cur_bank				; stored in main apu code instead
		PHA									; so don't need to store it here as
		TXA									; for mus
		PHA
		TYA
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_apu_snd_load
		PLA
		TAY
		PLA
		TAX
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
_nsub_full_pal_fade_set:
		JSR		_scr_getc					; nsub for palette loading from scipts
		LDY		#$07
loc_62688:
		STA		_pal_fade_req_list,Y
		DEY
		BPL		loc_62688
		JMP		_full_pal_fade

; =============== S U B R O U T I N E ======n================================
_nsub_pal_fade_req_inc_by_mask:
		JSR		_scr_getc
		STA		_var0
		LDX		#$07
loc_62698:
		LSR		_var0
		BCC		loc_6269E
		INC		_pal_fade_req_list,X
loc_6269E:
		DEX
		BPL		loc_62698
		JMP		_full_pal_fade

; =============== S U B R O U T I N E ======n================================
_nsub_pal_fade_req_dec_by_mask:
		JSR		_scr_getc
		STA		_var0
		LDX		#$07
loc_626AB:
		LSR		_var0
		BCC		loc_626B1
		DEC		_pal_fade_req_list,X
loc_626B1:
		DEX
		BPL		loc_626AB
		JMP		_full_pal_fade

; =============== S U B R O U T I N E ======n================================
_nsub_patch_pal_load:
		JSR		_scr_getc					; -> Y
		PHA
		JSR		_scr_getc					; -> tmp0
		PHA
		JSR		_scr_getc					; -> X
		TAX
		PLA
		STA		_tmp0
		PLA
		TAY
		LDA		_tmp0
		JMP		_patch_pal_load

; =============== S U B R O U T I N E ======n================================
_nsub_bg_pal_load:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAX
		PLA
		JMP		_bg_pal_load

; =============== S U B R O U T I N E ======n================================
_nsub_spr_pal_load:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAX
		PLA
		JMP		_spr_pal_load

; =============== S U B R O U T I N E ======n================================
_nsub_full_pal_load:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAX
		PLA
		JMP		_full_pal_load

; =============== S U B R O U T I N E ======n================================
_nsub_thread_off:
		JSR		_scr_getc
		TAX
		LDA		#$FF
		STA		_trds_obj_idx,X
		RTS

; =============== S U B R O U T I N E ======n================================
;_nsub_trd_scr_disable_unref:
;		JSR		_scr_getc
;		PHA
;		JSR		_scr_getc
;		STA		_tmp0
;		PLA
;		ASL
;		ADC		_tmp0
;		ASL
;		TAX
;		LDA		#$00
;		STA		_trd_ptr+1,X
;		RTS

; =============== S U B R O U T I N E ======n================================
; TODO: this is ending scenario only routine, why they put it here, unknown
;
_nsub_obj_delay_set_from_sarg:
		JSR		_scr_getc
		TAX
		LDA		_trds_args_ptrs_lo,X
		STA		_ptr06
		LDA		_trds_args_ptrs_hi,X
		STA		_ptr06+1
		LDY		_cur_trd_slot
		LDA		(_ptr06),Y
		LDX		_cur_trd_scr_slot
		STA		_trds_scr_delay,X
		RTS

; =============== S U B R O U T I N E ======n================================
;_nsub_cur_obj_delay_rand_set_unref:
;		JSR		_scr_getc
;		PHA
;		JSR		_scr_getc
;		JSR		_rand
;		TAX
;		PLA
;		JSR		_mul8
;		LDX		_cur_trd_scr_slot
;		STA		_trds_scr_delay,X
;		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_spr_dir_select:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		STA		_tmp0
		LSR
		LDX		_cur_trd_slot
		CLC
		ADC		_trds_args1,X
		LDX		#$00						; NEW, replaced slow _div16 with
		STX		_var0						; fast shifter
		ASL
		ROL		_var0
		ASL		_tmp0
		BCS		.div_stop
		ASL
		ROL		_var0
		ASL		_tmp0
		BCS		.div_stop
		ASL
		ROL		_var0
		ASL		_tmp0
		BCS		.div_stop
		ASL
		ROL		_var0						; up to 4 bits, there aren't something else
.div_stop:
		PLA
		CLC
		ADC		_var0
		LDX		_cur_trd_slot
		STA		_obj_spr_idx,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_far_prg0_tlm_lib_unpack:
		JSR		_scr_getc

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_far_prg0_tlm_lib_unpack:
		STA		_tmp0
		LDA		_prg_cur_bank
		PHA
		LDA		#_tlm_lib_unpack_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_tlm_lib_unpack
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
_nsub_scroll_page_set:
		JSR		_scr_getc
		JMP		_scroll_page_set

; =============== S U B R O U T I N E ======n================================
_nsub_mmc1_mirror_horizontal:
		LDA		#$1E
		JMP		_mmc1_ctrl

; =============== S U B R O U T I N E ======n================================
_nsub_mmc1_mirror_vertical:
		LDA		#$1F
		JMP		_mmc1_ctrl

; =============== S U B R O U T I N E ======n================================
;_nsub_mmc1_prg_set_unused:
;		JSR		_scr_getc					; prg set helper as well never used here
;		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E ======n================================
_nsub_new_thread_start:
		LDX		_cur_trd_slot				; start a new thread from current thread
		JSR		_scr_getc					; usually loads the same script with different
		PHA									; parameters
		LDA		#$00
		STA		_var6
		STA		_var7
		JSR		_scr_getc					; here is the relative position of new
		STA		_tmp1						; object from current object calculated
		BPL		loc_627AE
		DEC		_var6
loc_627AE:
		JSR		_scr_getc
		STA		_tmp2
		BPL		loc_627B7
		DEC		_var7
loc_627B7:
		JSR		_scr_getc					; also read two parameters, sarg0 as
		STA		_var0						; thread entity selector
		JSR		_scr_getc					; sarg1 as direction modifier
		CLC
		ADC		_trds_args1,X
		STA		_var1
		LDA		_obj_y_pos_lo,X				; calc new position
		CLC
		ADC		_tmp2
		TAY
		LDA		_obj_y_pos_hi,X
		ADC		_var7
		STA		_tmp_var1
		LDA		_obj_x_pos_lo,X
		CLC
		ADC		_tmp1
		PHA
		LDA		_obj_x_pos_hi,X
		ADC		_var6
		STA		_tmp_var0
		PLA
		TAX
		PLA
		JSR		_thread_lib_load_gen_ex
		TXA
		LSR									; X here is last added slot idx *4
		LSR									; so div it back
		TAX									; store current thread idx into SARG2
		LDA		_cur_trd_slot				; to link it
		STA		_trds_args2,X
		TXA									; and return back the new object IDX
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_sarg01_load_data_ofs:
		LDX		_cur_trd_slot				; custom usage of sargs with general purpose
		JSR		_scr_getc					; scripts as a pointer for example
		STA		_trds_args0,X
		JSR		_scr_getc
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
; get the pointer to chain data in current thread's ARG0/ARG1 parameters,
; reload given thread with the same lib idx as a new scripts with selected
; arguments from data, also get the position and delays there.
; so this routine will create a number of copies of the current thread with
; predefined parameters.
;
; also used by general purpose scripts, uses ptr loaded in sargs with prev
; nsub routine
;
_nsub_chain_thread_lib_load_enemy:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X				; load chain scripts data ptr
		STA		_ptr06
		LDA		_trds_args1,X
		STA		_ptr06+1
		LDA		#$00
		STA		_var4
		STA		_var5
		TAY
		LDA		(_ptr06),Y					; read next chunk
		STA		_var0
		INY
		LDA		(_ptr06),Y
		STA		_tmp1
		BPL		loc_62819
		DEC		_var4
loc_62819:
		INY
		LDA		(_ptr06),Y
		STA		_tmp2
		BPL		loc_62822
		DEC		_var5
loc_62822:
		INY
		LDA		(_ptr06),Y					; every new script will have its own
		LDX		_cur_trd_scr_slot			; delay value at start
		STA		_trds_scr_delay,X
		LDX		_cur_trd_slot
		INY
		TYA
		CLC
		ADC		_ptr06
		STA		_trds_args0,X				; put ptr to the next chunk
		LDA		_ptr06+1
		ADC		#$00
		STA		_trds_args1,X
		LDA		_trds_obj_idx,X
		PHA
		LDA		_obj_y_pos_lo,X				; deploy currently loaded thread, one
		CLC									; at a time. to read out all data you
		ADC		_tmp2						; need this routine as much times as
		TAY									; much chunks in data
		LDA		_obj_y_pos_hi,X
		ADC		_var5
		STA		_tmp_var1
		LDA		_obj_x_pos_lo,X
		CLC
		ADC		_tmp1
		PHA
		LDA		_obj_x_pos_hi,X
		ADC		_var4
		STA		_tmp_var0
		PLA
		TAX
		PLA
		JMP		_thread_lib_load_gen_ex

; =============== S U B R O U T I N E ======n================================
_nsub_obj_sarg_add_imm_test:
		JSR		_scr_getc					; main commonly used nsub routine
		TAX									; to getch sarg value and test its value
		LDA		_trds_args_ptrs_lo,X		; after selected displacement. used
		STA		_ptr06						; to get indexes of the script switch cases
		LDA		_trds_args_ptrs_hi,X
		STA		_ptr06+1
		JSR		_scr_getc
		LDY		_cur_trd_slot
		CLC
		ADC		(_ptr06),Y
		BMI		loc_62877
		CLC
		RTS
loc_62877:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_get_rand_probability:
		JSR		_scr_getc					; get rand value of 1/getc probability
		JSR		_rand
		BEQ		loc_62883
		CLC
		RTS
loc_62883:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_level_init:
		JSR		_scr_getc
		STA		_lvl_data_prg_bank
		JSR		_scr_getc					; common data load for current stage
		STA		_lvl_macroA_ptr
		JSR		_scr_getc
		STA		_lvl_macroA_ptr+1
		JSR		_scr_getc
		STA		_lvl_macroB_ptr
		JSR		_scr_getc
		STA		_lvl_macroB_ptr+1
		JSR		_scr_getc
		STA		_lvl_macroC_ptr
		JSR		_scr_getc
		STA		_lvl_macroC_ptr+1
		JSR		_scr_getc
		STA		_lvl_macroD_ptr
		JSR		_scr_getc
		STA		_lvl_macroD_ptr+1
		JSR		_scr_getc
		STA		_lvl_attrs_ptr
		JSR		_scr_getc
		STA		_lvl_attrs_ptr+1
		JSR		_scr_getc
		STA		_lvl_rooms_lib_ptr
		JSR		_scr_getc
		STA		_lvl_rooms_lib_ptr+1
		JSR		_scr_getc
		STA		_lvl_objects_ptr
		JSR		_scr_getc
		STA		_lvl_objects_ptr+1
		JMP		_nsub_apu_mus_load

; =============== S U B R O U T I N E ======n================================
;_nsub_room_page_set_unref:
;		JSR		_scr_getc					; this routine never used to load
;		STA		_cur_room_x_pageA			; current room screens layouts
;		JSR		_scr_getc
;		STA		_cur_room_x_pageB
;		JSR		_scr_getc
;		STA		_cur_room_y_pageB
;		JSR		_scr_getc
;		STA		_cur_room_y_pageA
;		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_speed_dir_select:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		LDX		_cur_trd_slot
		LDY		_trds_args1,X
		PLA
		TAX
		PLA
		JSR		_linear_dst_pos_calc
		LDX		_cur_trd_slot
		LDA		_ptr06
		STA		_obj_x_speed,X
		LDA		_ptr06+1
		STA		_obj_x_delta,X
		LDA		_ptr08
		STA		_obj_y_speed,X
		LDA		_ptr08+1
		STA		_obj_y_delta,X
		RTS

; =============== S U B R O U T I N E ======n================================
; there are three types of rooms, size 1x1 screens, 1x2 and 2x1. this routine
; determines the room type and number of screens in it, then draw one or
; two at once. this engine does not draw room data while scrolling as in other
; games. single room always fit into two name tables for one mirroring mode.
;
_room_draw:
		JSR		_ppu_vblank_off				; this is the only routine for native callers
		LDA		_cur_room_orientation_idx	; used when redraw pause screen.
		ORA		#$1E
		JSR		_mmc1_ctrl
		LDA		_cur_room_data_col
		STA		_tmp_var0
		STA		_cur_room_y_pageB
		STA		_cur_room_y_pageA
		LDA		_cur_room_data_row
		STA		_tmp_var1
		STA		_cur_room_x_pageA
		STA		_cur_room_x_pageB
		JSR		_ppu_room_screen_draw
		LDA		_cur_room_orientation_idx
		BNE		loc_6293C
		INC		_cur_room_y_pageA
		INC		_tmp_var0
		BNE		loc_62945
loc_6293C:
		CMP		#$01
		BNE		loc_62948
		INC		_cur_room_x_pageB
		INC		_tmp_var1
loc_62945:
		JSR		_ppu_room_screen_draw
loc_62948:
		JMP		_ppu_vblank_on

#if TWO_PLAYER_MODE==1
; =============== S U B R O U T I N E ======n================================
; in two players mode lets the second player to exit the rooms
;
_nsub_players_room_exit_test_from_ptr:
		LDX		#$02
		JSR		_nsub_player_room_exit_test_from_ptr
		BCS		.exit_found
		LDX		#$04
		JMP		_nsub_player_room_exit_test_from_ptr
.exit_found:
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
#if TWO_PLAYER_MODE==1
_nsub_player_room_exit_test_from_ptr:
		LDY		#$00
#else
_nsub_players_room_exit_test_from_ptr:
#endif

		LDA		(_room_exits_ptr),Y
		INY									; fetches the exit locations of the level
		STA		_var0						; and compares with current beamed position
		LDA		#$00						; return flag if position reached
		STA		_var3
loc_62954:
		LDA		(_room_exits_ptr),Y
		INY
		SEC									; but exits are always active
#if TWO_PLAYER_MODE==1
		SBC		_obj_x_pos_lo,X
#else
		SBC		_obj_x_pos_lo+2
#endif
		STA		_var1
		LDA		(_room_exits_ptr),Y
		INY
#if TWO_PLAYER_MODE==1
		SBC		_obj_x_pos_hi,X
#else
		SBC		_obj_x_pos_hi+2
#endif
		STA		_var2
		BCS		loc_62976
		LDA		#$00
		SEC
		SBC		_var1
		STA		_var1
		LDA		#$00
		SBC		_var2
loc_62976:
		BNE		loc_629A8
		LDA		_var1
		CMP		#$11
		BCS		loc_629A8
		LDA		(_room_exits_ptr),Y
		INY
		SEC
#if TWO_PLAYER_MODE==1
		SBC		_obj_y_pos_lo,X
#else
		SBC		_obj_y_pos_lo+2
#endif
		STA		_var1
		LDA		(_room_exits_ptr),Y
		INY
#if TWO_PLAYER_MODE==1
		SBC		_obj_y_pos_hi,X
#else
		SBC		_obj_y_pos_hi+2
#endif
		STA		_var2
		BCS		loc_629A0
		LDA		#$00
		SEC
		SBC		_var1
		STA		_var1
		LDA		#$00
		SBC		_var2
loc_629A0:
		BNE		loc_629B2
		LDA		_var1
		CMP		#$11
		BCC		loc_629BA
		BCS		loc_629B2
loc_629A8:
		INY
		INY
loc_629B2:
		INC		_var3
		DEC		_var0
		BNE		loc_62954
		CLC									; exit with C=0 if no exit reached
		RTS
loc_629BA:
		LDA		_var3						; exit with C=1 if exit reached
		STA		_tmp_idx
		SEC
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
; common routine for init starting position of players at the lbeginning
; of the level or at the beginning of new room
;
_nsub_players_room_start_pos_init_from_ptr:
		LDA		(_room_exits_ptr),Y			; NEW, this pointer always set to
		ASL									; exits data, which need to be skipped first
		ASL									; also we know for sure its size here
		SEC
		ADC		_room_exits_ptr
		STA		_room_exits_ptr
		BCC		.no_increment
		INC		_room_exits_ptr+1
.no_increment:
		LDA		_tmp_idx
		ASL
		ADC		_tmp_idx
		TAY
		LDA		#$00
		STA		_obj_x_pos_hi+2
		STA		_obj_y_pos_hi+2
		LDA		(_room_exits_ptr),Y
		ASL
		ROL		_obj_x_pos_hi+2
		ASL
		ROL		_obj_x_pos_hi+2
		ASL
		ROL		_obj_x_pos_hi+2
		STA		_obj_x_pos_lo+2
		INY
		LDA		(_room_exits_ptr),Y
		ASL
		ROL		_obj_y_pos_hi+2
		ASL
		ROL		_obj_y_pos_hi+2
		ASL
		ROL		_obj_y_pos_hi+2
		STA		_obj_y_pos_lo+2
		INY
		LDA		(_room_exits_ptr),Y
		TAX
		LSR
		ROR
		ROR
		STA		_trds_args1+2				; position data stored only for beamer
		STA		_trds_args1+4				; position of catched auto calculated
		LDA		_obj_x_pos_lo+2				; by direction of beamer and starting position
		CLC									; at the door
		ADC		byte_62A87,X
		STA		_obj_x_pos_lo+2
		LDA		_obj_x_pos_hi+2
		ADC		byte_62A8B,X
		STA		_obj_x_pos_hi+2
		STA		_ppu_scroll_pos_x+1
		LDA		_obj_y_pos_lo+2
		CLC
		ADC		byte_62A8F,X
		STA		_obj_y_pos_lo+2
		LDA		_obj_y_pos_hi+2
		ADC		byte_62A93,X
		STA		_obj_y_pos_hi+2
		STA		_ppu_scroll_pos_y+1
		LDA		_obj_x_pos_lo+2
		CLC
		ADC		byte_62A97,X
		STA		_obj_x_pos_lo+4
		LDA		_obj_x_pos_hi+2
		ADC		byte_62A9B,X
		STA		_obj_x_pos_hi+4
		LDA		_obj_y_pos_lo+2
		CLC
		ADC		byte_62A9F,X
		STA		_obj_y_pos_lo+4
		LDA		_obj_y_pos_hi+2
		ADC		byte_62AA3,X
		STA		_obj_y_pos_hi+4
		LDA		_trds_args1+2
		ASL
		ROL
		ROL
		ASL
		ASL
		ADC		_beamer_spr_base_tmp
		STA		_obj_spr_idx+2
		LDA		_trds_args1+4
		ASL
		ROL
		ROL
		ASL
		ASL
		ADC		_catcher_spr_base_tmp
		STA		_obj_spr_idx+4
		LDA		#$00						; also this routine resets the scrolls
		STA		_ppu_scroll_pos_x			; and removes all possible threads garbage
		STA		_ppu_scroll_pos_y
		JMP		_nsub_gen_threads_off_except_cur

byte_62A87:
		.BYTE	$10,$10,$10,$F8
byte_62A8B:
		.BYTE	$00,$00,$00,$FF
byte_62A8F:
		.BYTE	$00,$18,$20,$18
byte_62A93:
		.BYTE	$00,$00,$00,$00
byte_62A97:
		.BYTE	$00,$F0,$00,$10
byte_62A9B:
		.BYTE	$00,$FF,$00,$00
byte_62A9F:
		.BYTE	$18,$00,$E8,$00
byte_62AA3:
		.BYTE	$00,$00,$FF,$00

; =============== S U B R O U T I N E ======n================================
_nsub_read_mem:
		JSR		_scr_getc					; workaround to read mem due to
		STA		_ptr06						; lack such command in the scrips
		JSR		_scr_getc
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_get_checkpoint_tmp_idx:
		LDX		_lvl_last_checkpoint_idx
		DEX
		STX		_tmp_idx
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_cur_obj_to_beamer_dir_set:
		JSR		_obj_to_beamer_dir_calc
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
;_nsub_cur_obj_linear_dst_pos_to_beamer_set_unref:
;		JSR		_scr_getc
;		PHA
;		JSR		_scr_getc
;		PHA
;		JSR		_obj_to_beamer_dir_calc
;		PLA
;		TAX
;		PLA
;		JSR		_linear_dst_pos_calc
;		LDX		_cur_trd_slot
;		LDA		_ptr06
;		STA		_obj_x_speed,X
;		LDA		_ptr06+1
;		STA		_obj_x_delta,X
;		LDA		_ptr08
;		STA		_obj_y_speed,X
;		LDA		_ptr08+1
;		STA		_obj_y_delta,X
;		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_obj_to_beamer_slow_turn:
		JSR		_scr_getc
		PHA
		PHA
		JSR		_obj_to_beamer_dir_calc		; get direction to beamer
		STA		_tmp0						; store it by now
		PLA
		STA		_var1						; calculate complement of turn speed
		SEC									; to use it as turn speed limit
		SBC		#$01
		EOR		#$FF
		STA		_var0
		PLA
		LSR
		CLC
		ADC		_tmp0						; also adding 1/2 of speed to smooth
		AND		_var0						; results
		SEC
		SBC		_trds_args1,X				; test against current direction, if the same
		BEQ		locret_62B1D				; do not update,
		BMI		loc_62B16
		LDA		_trds_args1,X				; if different, add turn speed amount to current
		CLC									; direction vector
		ADC		_var1
		JMP		loc_62B1B
loc_62B16:
		LDA		_trds_args1,X
		SEC
		SBC		_var1
loc_62B1B:
		STA		_trds_args1,X
locret_62B1D:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_obj_to_obj_in_range_test:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		TAY
		INY
		JMP		_obj_to_obj_in_range_test

; =============== S U B R O U T I N E ======n================================
_nsub_obj_spr_idx_set_from_sarg:
		JSR		_scr_getc
		TAX
		LDA		_trds_args_ptrs_lo,X
		STA		_ptr06
		LDA		_trds_args_ptrs_hi,X
		STA		_ptr06+1
		LDY		_cur_trd_slot
		LDA		(_ptr06),Y
		STA		_obj_spr_idx,Y
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_all_threads_off_except_cur:
		LDX		#$0D
		LDA		#$FF
loc_62B44:
		CPX		_cur_trd_slot
		BEQ		loc_62B4B
		STA		_trds_obj_idx,X
loc_62B4B:
		DEX
		BPL		loc_62B44
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_gen_threads_off_except_cur:
		LDX		#$06
		LDA		#$FF
loc_62B53:
		CPX		_cur_trd_slot
		BEQ		loc_62B5A
		STA		_trds_obj_idx,X
loc_62B5A:
		INX
		CPX		#$0E
		BCC		loc_62B53
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_cur_pos_x_lo_icmp:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_x_pos_lo,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_cur_pos_y_lo_icmp:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_y_pos_lo,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_mtest_bit0:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		LDA		(_ptr06),Y
		LSR
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_mcmp:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_scr_getc
		STA		_tmp0
		LDA		(_ptr06),Y
		CMP		_tmp0
		BEQ		locret_62B94
		CLC
locret_62B94:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_stage_complete_test:
		LDA		_lvl_objects_ptr+1			; stage completed when object list
		BNE		locret_62BB0				; reaches its end, and all enemies
		LDX		#$06						; are inactive anymore
loc_62B9B:
		LDA		_trds_obj_idx,X
		BMI		loc_62BA4
		CPX		_cur_trd_slot
		BNE		locret_62BB0
loc_62BA4:
		INX
		CPX		#$0E
		BCC		loc_62B9B

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nsub_stage_complete_force:
		LDX		#$00						; idx for stage thread slot is $00
		JSR		_thread_reload_param_ex		; so need to make sure this script
		.WORD	_scr_stage_complete			; and its data are in the same bank
locret_62BB0:
		RTS

; =============== S U B R O U T I N E ======n================================
; NOTE: this routine used only for "STAGE CLEAR" sprite position set
; only once in all scripts, but still using the parametric positions.
; seems they used this routine before as part of scripting library
; but now its usage seems very redundant.
;
_nsub_obj_screen_pos_set:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_pos_x
		STA		_obj_x_pos_lo,X
		LDA		_ppu_scroll_pos_x+1
		ADC		#$00
		STA		_obj_x_pos_hi,X
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_pos_y
		STA		_obj_y_pos_lo,X
		LDA		_ppu_scroll_pos_y+1
		STA		_obj_y_pos_hi,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_obj_sarg_set_from_nsub_return_value:
		JSR		_scr_getc
		TAX
		LDA		_trds_args_ptrs_lo,X
		STA		_ptr06
		LDA		_trds_args_ptrs_hi,X
		STA		_ptr06+1
		LDY		_cur_trd_slot
		LDA		_nsub_return_value
		STA		(_ptr06),Y
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_any_enemy_active:
		LDX		#$06
loc_62BE7:
		LDA		_trds_obj_idx,X				; test if there are no enemies, used
		BMI		loc_62BF4					; mostly for special small cutscenes
		CMP		#$13						; on the stages
		BCC		loc_62BF4
		CPX		_cur_trd_slot
		BNE		loc_62BFB
loc_62BF4:
		INX
		CPX		#$0E
		BCC		loc_62BE7
		SEC
		RTS
loc_62BFB:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_wait_for_beam_hold:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BEQ		loc_62C09
		CMP		#$03
		BEQ		loc_62C09
		CLC
		RTS
loc_62C09:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_get_obj_stun_state:
		LDY		#$00
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		loc_62C18
		INY
		LSR
		BCC		loc_62C18
		INY
loc_62C18:
		LDA		#$00
		STA		_trds_args0,X
		TYA
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_beamer_handler_start:
		JSR		_players_thread_vars_init
#if TWO_PLAYER_MODE==1
		LDA		#$00						; 2p hack player idx
		STA		_var2
#endif
		LDA		#$02
		STA		_var4
		LDA		#$03
		STA		_var5
		LDA		#_scr08_beamer_handler_idx
		JMP		_thread_lib_load

; =============== S U B R O U T I N E ======n================================
_players_thread_vars_init:
		LDA		#$00
		STA		_var1
		STA		_tmp_var0
		STA		_tmp_var1
		TAY
		TAX
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_catcher_handler_start:
		JSR		_players_thread_vars_init
#if TWO_PLAYER_MODE==1
		LDA		#$01						; 2p hack player idx
		STA		_var2
#endif
		LDA		#$04
		STA		_var4
		LDA		#$05
		STA		_var5
		LDA		#_scr0A_catcher_handler_idx
		JMP		_thread_lib_load

; =============== S U B R O U T I N E ======n================================
_nsub_obj_to_room_x_ctestA:
		LDY		_cur_trd_slot
		LDA		_obj_x_pos_lo,Y
		AND		#$07
		CMP		#$04
		BNE		loc_62C6A
		TXA
		PHA
		LDX		#$00
		LDA		_trds_args1,Y
		BMI		loc_62C5E
		INX
loc_62C5E:
		LDA		off_62C6C,X
		LDY		off_62C6E,X
		JSR		_obj_to_room_bound_box_ctest
		PLA
		TAX
		RTS
loc_62C6A:
		CLC
		RTS
off_62C6C:
		.BYTE	<[byte_62C70]
		.BYTE	<[byte_62C75]
off_62C6E:
		.BYTE	>[byte_62C70]
		.BYTE	>[byte_62C75]
byte_62C70:
		.BYTE	$02
		.BYTE	$FB,$FB
		.BYTE	$FB,$04
byte_62C75:
		.BYTE	$02
		.BYTE	$04,$FB
		.BYTE	$04,$04

; =============== S U B R O U T I N E ======n================================
_nsub_obj_to_room_y_ctestA:
		LDY		_cur_trd_slot
		LDA		_obj_y_pos_lo,Y
		AND		#$07
		CMP		#$04
		BNE		loc_62CA0
		TXA
		PHA
		LDX		#$00
		LDY		_cur_trd_slot
		LDA		_trds_args1,Y
		CLC
		ADC		#$40
		BPL		loc_62C94
		INX
loc_62C94:
		LDA		off_62CA2,X
		LDY		off_62CA4,X
		JSR		_obj_to_room_bound_box_ctest
		PLA
		TAX
		RTS
loc_62CA0:
		CLC
		RTS
off_62CA2:
		.BYTE	<[byte_62CA6]
		.BYTE	<[byte_62CAB]
off_62CA4:
		.BYTE	>[byte_62CA6]
		.BYTE	>[byte_62CAB]
byte_62CA6:
		.BYTE	$02
		.BYTE	$FB,$FB
		.BYTE	$04,$FB
byte_62CAB:
		.BYTE	$02
		.BYTE	$FB,$04
		.BYTE	$04,$04

; =============== S U B R O U T I N E ======n================================
_nsub_cur_obj_sarg1_hor_complement:
		LDX		_cur_trd_slot
		LDA		#$00
		SEC
		SBC		_trds_args1,X
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_cur_obj_sarg1_vert_complement:
		LDX		_cur_trd_slot
		LDA		#$80
		SEC
		SBC		_trds_args1,X
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
; some enemies couldn't move diagonally due to lack of
; diagonal symmetry in sprites. so when targeted on beamer, they
; can move only vertically or horizontally, so this routine first
; calculates the linear vector, but then mask out one of the
; direction...
;
_nsub_obj_to_beamer_fast_right_turn:
		LDA		#$02
		JSR		_obj_to_obj_dir_calc
		CLC
		ADC		#$20
		AND		#$C0
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_obj_to_room_sarg1_square_ctest:
		JSR		_nsub_sarg1_direction_extract
		TAX
		LDA		off_62CE0,X
		LDY		off_62CE4,X
		JMP		_obj_to_room_bound_box_ctest

off_62CE0:
		.BYTE	<[byte_62CA6]
		.BYTE	<[byte_62C75]
		.BYTE	<[byte_62CAB]
		.BYTE	<[byte_62C70]
off_62CE4:
		.BYTE	>[byte_62CA6]
		.BYTE	>[byte_62C75]
		.BYTE	>[byte_62CAB]
		.BYTE	>[byte_62C70]

; =============== S U B R O U T I N E ======n================================
_nsub_cur_center_reset:
		LDX		_cur_trd_slot
		LDA		#$80
		STA		_obj_x_clk,X
		STA		_obj_y_clk,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_players_scr_suspend:
		LDX		#$02						; suspend player's scripts
		LDA		_obj_spr_idx,X				; but keed it's current sprite idxes
		PHA
		JSR		_thread_reload_param_ex
		.WORD	_scr_suspend
		PLA
		LDX		#$02
		STA		_obj_spr_idx,X
		LDX		#$04
		LDA		_obj_spr_idx,X
		PHA
		JSR		_thread_reload_param_ex
		.WORD	_scr_suspend
		PLA
		LDX		#$04
		STA		_obj_spr_idx,X
		RTS

; =============== S U B R O U T I N E ======n================================
; routine to remove objects that have to disappear off screen
_cur_obj_out_of_screen_test:
		LDX		_cur_trd_slot
		LDA		_obj_x_screen_pos,X
		CMP		#$04
		BCC		loc_62D76
		CMP		#$F8
		BCS		loc_62D76
		LDA		_obj_y_screen_pos,X
		CMP		#$04
		BCC		loc_62D76
		CMP		#$E8
		BCS		loc_62D76
		RTS
loc_62D76:
		JMP		_scr_cur_trd_off

; =============== S U B R O U T I N E ======n================================
_obj_to_room_macro_ctest_raw:
		LDX		_cur_trd_slot
		LDA		_obj_x_pos_hi,X
		STA		_tmp_var0
		LDA		_obj_y_pos_hi,X
		STA		_tmp_var1
		LDY		_obj_y_pos_lo,X
		LDA		_obj_x_pos_lo,X
		TAX
		JSR		_room_macro_ctest_ex
		BCS		loc_62D90
		RTS
loc_62D90:
		JMP		_scr_cur_trd_off

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pal_fade_in:
		NJSR			_nsub_full_pal_fade_set			; fast shut down the palette in one
			NARGB		$FC								; call, FC=max fade out speed
		SDELAY			$01								; wait for buffers flush
		SLOOP_BEGIN		$04								; now send pal fade reqests 4 times
		NJSR			_nsub_pal_fade_req_inc_by_mask	; with increasing negative fade out value
			NARGB		$FF								; FD->FE->FF->00 (note, inc goes before fade)
		SDELAY			$03								; 3 frames of delay for fade effect
		SLOOP_END										; when finish, a full palette is loaded
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_pal_fade_out:
		NJSR			_nsub_full_pal_fade_set			; same with fade out, but starts from
			NARGB		$00								; applying current palette at full bright
		SLOOP_BEGIN		$04								; then decreasing the fade depth to make
		NJSR			_nsub_pal_fade_req_dec_by_mask	; fade it out.
			NARGB		$FF								; FF->FE->FD->FC (note, dec goes before fade)
		SDELAY			$03
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_room_entry_pal_fade_in:
		NJSR			_nsub_full_pal_fade_set
			NARGB		$FC

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_room_entry_pal_fade_in_ex:
		SDELAY			$01
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$FF
		SDELAY			$03
		SLOOP_END
		STORE8			_pause_mode_flag,$00
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_room_exit_pal_fade_out:
		NJSR			_nsub_full_pal_fade_set
			NARGB		$00

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_room_exit_pal_fade_out_ex:
		STORE8			_pause_mode_flag,$01
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask
			NARGB		$FF
		SDELAY			$03
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_catch_anim_L_snd02:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd02_idx

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_catch_anim_L_ex:
		SLOOP_BEGIN		$03
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$00
		SLOOP_END
		SARG_ALU		SARG1,_ADC,$01
		SLOOP_BEGIN		$02
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$01
		SLOOP_END
		SPR_IDX_SET		2,$00

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_catch_finish:
		SPR_IDX_INC		2
		NJSR			_nsub_obj_scores_add
		NJSR			_nsub_prize_sequence_test
		NJSR			_nsub_stage_complete_test
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_catch_anim_R_snd02:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd02_idx

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_catch_anim_R_ex:
		SLOOP_BEGIN		$03
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$02
		SLOOP_END
		SARG_ALU		SARG1,_ADC,$01
		SLOOP_BEGIN		$02
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$03
		SLOOP_END
		SPR_IDX_SET		2,$02
		SJMPS			_ssub_common_catch_finish

; =============== S C R I P T  S U B R O U T I N E =====s====================

_ssub_common_catch_anim_L_snd19:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd19_idx
		SJMPS			_ssub_common_catch_anim_L_ex

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_common_catch_anim_R_snd19:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd19_idx
		SJMPS			_ssub_common_catch_anim_R_ex

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_boss_music_fade_and_load:
		SLOOP_BEGIN		$80								; special common boss music start routine
		SMEM_ALU		_apu_mus_volume,_ADC,$FF		; fade out the current music first
		SDELAY			$01
		SLOOP_END
		STORE8			_apu_mus_volume,$FF
		NJSR			_nsub_apu_mus_load
			NARGB		_mus4_idx
		SRET

; =============== S U B R O U T I N E ======n================================
_scr_trds_list_reset:
		LDA		#$FF
		LDX		#$0D
loc_62E6E:
		STA		_trds_obj_idx,X
		DEX
		BPL		loc_62E6E
		LDA		#$00
		STA		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_shift+1
		STA		_ppu_scroll_y_shift
		STA		_ppu_scroll_y_shift+1
		STA		_ppu_scroll_x_page
		STA		_ppu_scroll_y_page
		LDA		#$80
		STA		_ppu_scroll_x_clk
		STA		_ppu_scroll_y_clk
		LDA		#$20
		STA		_spr_buf_pos
		RTS

; =============== S U B R O U T I N E ======n================================
_thread_lib_load_gen_ex:
		PHA									; load new thread, slots 06-0D allowed only
		LDA		#$06
		STA		_var4
		LDA		#$0E
		STA		_var5
		PLA
		JMP		_thread_lib_load

; =============== S U B R O U T I N E ======n================================
_event_thread_start:
		PHA
		LDA		#$00						; load thread without parameters and limits
		STA		_var0
		STA		_var1
		STA		_var2
		STA		_var4
		LDA		#$0E
		STA		_var5
		PLA

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_thread_lib_load:
		STA		_tmp0						; look for free threads slot
		STX		_tmp1						; and load selected library script
		STY		_tmp2
		LDX		_var4
loc_62EB2:
		LDA		_trds_obj_idx,X
		BMI		loc_62EBD
		INX
		CPX		_var5
		BCC		loc_62EB2
		RTS
loc_62EBD:
		LDA		_tmp1
		STA		_obj_x_pos_lo,X
		LDA		_tmp2
		STA		_obj_y_pos_lo,X
		LDA		_tmp_var0
		STA		_obj_x_pos_hi,X
		LDA		_tmp_var1
		STA		_obj_y_pos_hi,X
		LDA		_var0
		STA		_trds_args0,X
		LDA		_var1
		STA		_trds_args1,X
		LDA		_var2
		STA		_trds_args2,X
		LDA		#$80
		STA		_obj_x_clk,X
		STA		_obj_y_clk,X
		JSR		_obj_screen_pos_update
		LDA		_tmp0
		STA		_trds_obj_idx,X
		BMI		_nbgsub_dummy
		TAY
		LDA		_scr_lib_lo,Y
		PHA
		LDA		_scr_lib_hi,Y
		TAY
		PLA

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_thread_load:
		PHA									; raw thread load, if you need something
		TYA									; to load that not in the library
		PHA
		LDA		#$FF
		STA		_obj_spr_idx,X
		STA		_trds_manager_restart_flag
		LDA		#$00
		STA		_obj_x_speed,X
		STA		_obj_x_delta,X
		STA		_obj_y_speed,X
		STA		_obj_y_delta,X
		LDA		#$01
		STA		_trds_exec_req,X
		TXA
		ASL
		PHA
		TAX
		LDA		#<[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr,X
		LDA		#>[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr+1,X
		LDA		#$00
		STA		_trds_scr_sp,X
		STA		_trds_scr_sp+1,X
		STA		_trds_scr_delay,X
		STA		_trds_scr_delay+1,X
		PLA
		ASL
		TAX
		LDA		#$00
		STA		_trd_ptr._ptr1+1,X			; set secondary script pointer to 00
		PLA
		STA		_trd_ptr._ptr0+1,X			; load first script pointer with main script
		PLA
		STA		_trd_ptr._ptr0,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nbgsub_dummy:
		CLC
		RTS

;_unused_7:
;		.BYTE	$80,$C0,$E0,$F0

; =============== S U B R O U T I N E ======n================================
; main core for script engine.
;
_threads_manager:
		LDX		#$0D						; set thread execution request at new iteration
		LDA		#$01						; every thread with flag set to 1 marked for execution
loc_62F45:
		STA		_trds_exec_req,X			; total 14 threads here
		DEX
		BPL		loc_62F45
.trds_manager_restart:
		LDA		#$00
		STA		_cur_trd_slot				; init thread index counter, start from thread 0
		STA		_trds_manager_restart_flag	; this flag may be set if any new script loaded runtime
.trds_manager_loop:
		LDX		_cur_trd_slot				; here we check thread execution request first,
		LDA		_trds_exec_req,X			; on the first loop they are all 1, so pass here
		BEQ		.trds_skip_exec
		DEC		_trds_exec_req,X			; clear request as soon as we start to manage thread
		LDA		_trds_obj_idx,X				; check if thread initialized with script index
		BMI		.trds_skip_exec				; if FF, then thrd is empty, skip it
		LDA		_out_of_screen_test_flag	; check if out-of-screen test needed beforehead
		BEQ		.trds_do_exec				; if no, then just execute
		LDA		_pause_mode_flag			; if not paused, performing out-of-screen test for
		BEQ		loc_62F6A					; all level threads, skip system threads (<6)
		CPX		#$02						; if paused, hold all other threads, excluding the
		BCS		.trds_skip_exec				; system threads: 0 - level, 1 - level doors
loc_62F6A:
#if OOS_ACTIVE==0
		CPX		#$06
		BCC		.trds_do_exec
		LDA		_obj_out_of_screen,X		; when object out of screen, hold it, so any object
		BNE		.trds_skip_exec				; halted, but will resume if visible again...
#endif
.trds_do_exec:
		LDX		_cur_trd_slot				; now, finally do execute. fetch current thread index
		LDY		_trds_obj_idx,X				; and set corresponding PRG bank before executing
		LDA		_scr_bank_lib,Y				; scripts may be executed independently, but must
		STA		_prg_cur_bank				; inherit one of existing library indexes to be able
		JSR		_mmc1_prg_safe				; to use proper programm bank and sprite library
		JSR		_thread_exec
.trds_skip_exec:
		INC		_cur_trd_slot				; repeat for all 14 threds
		LDA		_cur_trd_slot
		CMP		#$0E
		BCC		.trds_manager_loop
		LDA		_trds_manager_restart_flag	; if one of threads added a new script, it must set
		BNE		.trds_manager_restart		; restart flag. execution loop starts again, but
		LDA		_ppu_scroll_x_shift+1		; will exec only that new added thread, because all
		CLC									; others has execution request clear already.
		ADC		_ppu_scroll_x_page			; next, time to adjust scrolls
		STA		_tmp0						; and global objects shift parameter
		LDA		#$00						; first for X scrolls
		STA		_ppu_scroll_x_page
		LDX		#$00
		LDA		_tmp0
		BPL		loc_62FA1
		DEX
loc_62FA1:
		LDA		_ppu_scroll_x_clk
		CLC
		ADC		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_clk
		LDA		_ppu_scroll_pos_x
		ADC		_tmp0
		STA		_ppu_scroll_pos_x
		TXA
		ADC		_ppu_scroll_pos_x+1
		STA		_ppu_scroll_pos_x+1
		LDA		_ppu_scroll_y_shift+1		; then for Y scrolls
		CLC
		ADC		_ppu_scroll_y_page
		STA		_tmp0
		LDA		#$00
		STA		_ppu_scroll_y_page
		LDA		_tmp0
		BMI		loc_62FDA
		LDA		_ppu_scroll_y_shift
		CLC
		ADC		_ppu_scroll_y_clk
		STA		_ppu_scroll_y_clk
		LDA		_ppu_scroll_pos_y
		ADC		_tmp0
		CMP		#$F0
		BCC		loc_62FD5					; do not forget to wrap around 240 scanline
		ADC		#$0F						; because of PPU specific
		INC		_ppu_scroll_pos_y+1
loc_62FD5:
		STA		_ppu_scroll_pos_y
		JMP		loc_62FFE
loc_62FDA:
		LDA		#$00
		SEC
		SBC		_ppu_scroll_y_shift
		STA		_var0
		LDA		#$00
		SBC		_tmp0
		STA		_var1
		LDA		_ppu_scroll_y_clk
		SEC
		SBC		_var0
		STA		_ppu_scroll_y_clk
		LDA		_ppu_scroll_pos_y
		SBC		_var1
		BCS		loc_62FFC
		SBC		#$0F
		DEC		_ppu_scroll_pos_y+1
loc_62FFC:
		STA		_ppu_scroll_pos_y
loc_62FFE:
		LDX		#$00
loc_63000:
		LDY		_trds_obj_idx,X				; after all scroll and shifts are recalculated
		BMI		loc_63014					; we may draw sprite finally. one sprite for one thread
		LDA		_spr_libs_list,Y			; every object has its own sprite library in a
		TAY									; corresponding bank, so select bank again
		LDA		_spr_libs_bank_list,Y		; and perform sprite insertion procedure according
		CMP		#$07						; to sprite index assigned in thread arrays
		BEQ		.no_need_prg7				; NOTE, little quirk to not to set prg7 here
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
.no_need_prg7:
		TXA
		PHA
		JSR		_obj_spr_insert
		PLA
		TAX
loc_63014:
		INX
		CPX		#$0E
		BCC		loc_63000					; repeat for all threads...
		RTS

#if DEBUG==1
; =============== S U B R O U T I N E ======n================================
_debug_spr_insert:
		LDY		_debug_lib_idx
		LDA		_prg_cur_bank
		PHA
		LDA		_spr_libs_bank_list,Y
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_debug_lib_type
		BNE		.debug_typeB
		LDA		#$00
		STA		_var0
		LDA		_debug_spr
		ASL
		ROL		_var0
		CLC
		ADC		_spr_libA_ofs_tbl_lo,Y
		STA		_ptr06
		LDA		_var0
		ADC		_spr_libA_ofs_tbl_hi,Y
		STA		_ptr06+1
		JSR		_spr_lib_fetch
		JMP		.debug_end
.debug_typeB:
		LDA		_debug_spr
		ASL
		ADC		_spr_libB_ofs_tbl_lo,Y
		STA		_ptr06
		LDA		#$00
		ADC		_spr_libB_ofs_tbl_hi,Y
		STA		_ptr06+1
		JSR		_spr_lib_fetch
.debug_end:
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe
#endif

; =============== S U B R O U T I N E ======n================================
_spr_y_pos_adjust:
		LDA		#$00
		STA		_spr_y_clip_flag
		LDA		_tmp2						; adjust vertical sprite pos to match
		BNE		loc_6373A					; real PPU sprite line
		DEC		_spr_y_clip_flag
loc_6373A:
		DEC		_tmp2
		RTS

; =============== S U B R O U T I N E ======n================================
_obj_spr_insert:
		JSR		_obj_screen_pos_update
		LDA		_obj_out_of_screen,X
		BNE		locret_6309C
		LDA		_obj_x_screen_pos,X
		STA		_tmp1
		LDA		_obj_y_screen_pos,X
		STA		_tmp2
		JSR		_spr_y_pos_adjust
		LDY		_trds_obj_idx,X
		LDA		_spr_libs_list,Y
		TAY
		LDA		_obj_spr_idx,X				; chose sprite library by it's index
		CMP		#$C0
		BCS		loc_6309D
		LDA		#$00
		STA		_var0
		LDA		_obj_spr_idx,X
		ASL
		ROL		_var0
		CLC
		ADC		_spr_libA_ofs_tbl_lo,Y		; library A offset
		STA		_ptr06
		LDA		_var0
		ADC		_spr_libA_ofs_tbl_hi,Y
		STA		_ptr06+1
		BNE		_spr_lib_fetch
locret_6309C:
		RTS
loc_6309D:
		CMP		#$FF
		BEQ		locret_6309C				; "no sprite" index
		SBC		#$BF						; adjust idx
		ASL
		ADC		_spr_libB_ofs_tbl_lo,Y		; library B offset
		STA		_ptr06
		LDA		#$00
		ADC		_spr_libB_ofs_tbl_hi,Y		; calc library ptr offset
		STA		_ptr06+1

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
; NEW, convert sprites format a little to allow any sprite be either
; typeA or typeB, no matter what library type you using. first attempt
; to remove secondary sprites lib at all.
;
_spr_lib_fetch:
		LDY		#$00						; fetch library ptr
		LDA		(_ptr06),Y
		STA		_ptr1E
		INY
		LDA		(_ptr06),Y
		STA		_ptr1E+1

; !FALLTHROUGH!

#if NEW_SPRITES==1
; =============== S U B R O U T I N E ======n================================
_spr_lib_fetch_ex:
		LDA		#$FF
		STA		_tmp1D						; reset attrs removes value
		LDA		#$00
		STA		_tmp1C						; reset attrs override value
		TAY
		LDA		(_ptr1E),Y					; fetch command/counter
		STA		_var0						; store command, set data ptr
		AND		#$20
		BNE		_spr_clip_insert			; last sprite block flag, do not loop then
		JSR		_spr_clip_insert
		JMP		_spr_lib_fetch_ex

; =============== S U B R O U T I N E ======n================================
_spr_clip_insert:
		INC		_ptr1E						; to actual data for command
		BNE		.spr_fetch
		INC		_ptr1E+1
.spr_fetch:
		BIT		_var0						; test command bits
		BPL		.spr_raw_insert
		BVC		.spr_no_override
		LDA		(_ptr1E),Y					; next byte here is an override bits
		STA		_tmp1C
		INY									; will be 3 bytes to skip for next cmd
.spr_no_override:
		LDA		_var0						; clear command bits
		AND		#$1F
		STA		_var0						; remove extra flags, counter remains
		LDA		(_ptr1E),Y					; offset flag set, next data for this
		STA		_ptr08						; command is a link offset to already
		INY									; existing data copy
		LDA		(_ptr1E),Y					; use it as sprite data addres
		STA		_ptr08+1
		INY									; two more bytes to skip
		TYA									; now retrieve actual value
		CLC
		BNE		.spr_common_skip
.spr_raw_insert:
		BVC		.spr_full_attrs
		LDA		(_ptr1E),Y					; read and store attrs value for block
		STA		_tmp1D						;
		INC		_ptr1E						; adjust again actual data ptr
		BNE		.spr_fetch1
		INC		_ptr1E+1
.spr_fetch1:
		LDA		_ptr1E						; copy pointer one more time
		STA		_ptr08
		LDA		_ptr1E+1
		STA		_ptr08+1
		LDA		_var0						; calculate size of raw data, without
		AND		#$1F						; attributes (3 bytes per sprite)
		STA		_var0						; since we couldn't send more than 64 sprites
		ASL									; at all, there will be no carry, safe
		ADC		_var0
		BCC		.spr_common_skip
.spr_full_attrs:
		LDA		_ptr1E						; no offset/override flags, raw data
		STA		_ptr08						; use current data offset as sprite data
		LDA		_ptr1E+1					; offset
		STA		_ptr08+1
		LDA		_var0						; calculate size of raw data, move
		AND		#$1F
		STA		_var0
		ASL									; current pointer to next command
		ASL
.spr_common_skip:
		ADC		_ptr1E
		STA		_ptr1E
		BCC		.spr_common_ins
		INC		_ptr1E+1
.spr_common_ins:
		LDX		_spr_buf_pos
		LDY		#$00
.spr_ins_loop:
		LDA		#$00
		STA		_ppu_spr_buf+3,X
		CLC
		LDA		(_ptr08),Y
		BPL		loc_6375D
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		LDA		_spr_y_clip_flag
		SBC		#$00
		AND		#$01
		BEQ		loc_6376A
		BNE		loc_6379F
loc_6375D:
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		BCS		loc_6379F
loc_6376A:
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+1,X
		INY
		LDA		_tmp1D
		CMP		#$FF
		BEQ		.no_attrs_skip
		STA		_ppu_spr_buf+2,X
		BNE		.no_attrs_done
.no_attrs_skip:
		LDA		(_ptr08),Y
		ORA		_tmp1C						; apply override if any
		STA		_ppu_spr_buf+2,X
		INY
.no_attrs_done:
		CLC
		LDA		(_ptr08),Y
		BPL		loc_6378B
		ADC		_tmp1
		BCS		loc_63798
		BCC		loc_637A2
loc_6378B:
		ADC		_tmp1
		BCS		loc_637A2
loc_63798:
		STA		_ppu_spr_buf+3,X
		INX
		INX
		INX
		INX
		JMP		loc_637A2
loc_6379F:
		INY
		INY
		LDA		_tmp1D
		CMP		#$FF
		BNE		loc_637A2
		INY
loc_637A2:
		INY
		DEC		_var0
		BNE		.spr_ins_loop
		STX		_spr_buf_pos
		RTS
#else
; =============== S U B R O U T I N E ======n================================
_spr_lib_fetch_ex:
		LDY		#$00
		LDA		(_ptr1E),Y
		BMI		.spr_typeB_insert
		LDA		_ptr1E						; sprite mode A, simple sprite
		STA		_ptr08
		LDA		_ptr1E+1
		STA		_ptr08+1
		JMP		_spr_clip_insert
.spr_typeB_insert:
		AND		#$7F
		STA		_tmp_loop_cnt
		INY
.spr_typeB_loop:
		LDA		(_ptr1E),Y
		STA		_ptr08
		INY
		LDA		(_ptr1E),Y
		STA		_ptr08+1
		INY
		TYA
		PHA
; NOTE! there was an original game "bug" for typeB sprites
; the draw routine decrement the Y position every time it is
; called, in the original code, every single chunk of typeB
; sprites shifted up with every single sprite chunk. since this
; affects only typeB multiple chunk sprites, and only place
; they use it is vega boss sprites, they fixed not the code,
; they fixed Y positions of all secondary sprite chunks for
; vega boss.
; most probably, other object not using the multiple chunks mode
; because of the same case, but just merged all of them in single
; chunk to avoid repositioning...
; NEW, took the y position adjust out of the loop at all
; so this is not a case anymore. vega y pos also adjusted.
		JSR		_spr_clip_insert
		PLA
		TAY
		DEC		_tmp_loop_cnt
		BNE		.spr_typeB_loop
		RTS

; =============== S U B R O U T I N E ======n================================
_spr_clip_insert:
		LDX		_spr_buf_pos
		LDY		#$00
		LDA		(_ptr08),Y
		STA		_var0
		INY
.spr_ins_loop:
; FIX: for some reason, same workaround for glitched sprites here were used once
; before the sprite insertion loop, and affects only first sprite, but not the
; rest ones.
		LDA		#$00
		STA		_ppu_spr_buf+3,X
; -
		CLC
		LDA		(_ptr08),Y
		BPL		loc_6375D
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		LDA		_spr_y_clip_flag
		SBC		#$00
		AND		#$01
		BEQ		loc_6376A
		BNE		loc_6379F
loc_6375D:
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		BCS		loc_6379F
loc_6376A:
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+1,X
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+2,X
		INY
		CLC
		LDA		(_ptr08),Y
		BPL		loc_6378B
		ADC		_tmp1
; NEW: fixed when this sprite may be clipped out, but will write
; the out of screen position for X anyway, if NMI occurs here,
; glitch may happen
; NEW: also get rid of unused _spr_x_clip_flags here, since even if
; mode for these flags will be implemented, there are a lot of
; sprites changes will need, also may be too slow.
		BCS		loc_63798
		BCC		loc_637A2
loc_6378B:
		ADC		_tmp1
		BCS		loc_637A2
loc_63798:
		STA		_ppu_spr_buf+3,X
		INX
		INX
		INX
		INX
		JMP		loc_637A2
loc_6379F:
		INY
		INY
		INY
loc_637A2:
		INY
		DEC		_var0
		BNE		.spr_ins_loop
		STX		_spr_buf_pos
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
; main thread execution routine
; every thread able to run TWO parallel scripts. all threads started with just
; one default script in slot 0, but at runtime it may run additional parallel
; script to perform any background work, like animation.
; also, every thread may have an additional native code sub-thread. it also
; assigned inside thread and used mostly for native IO operations, like pad
; tests.
;
_thread_exec:
		LDA		#$00
		STA		_tmp_loop_cnt				; init scripts counter here
loc_63139:
		LDA		_cur_trd_slot				; calc the current script pointer offset
		ASL									; NOTE, _cur_trd_scr_slot is used to separate
		ADC		_tmp_loop_cnt				; both script stack operations, delays and exec flow.
		STA		_cur_trd_scr_slot			; but both scripts will refer as _cur_trd_slot
		ASL									; for all other parameters
		TAX
		LDA		_trd_ptr+1,X				; if high nibble of script offset is zero
		BEQ		loc_6314A					; then this script is disabled, skip it
		JSR		_script_exec				; execute if not
loc_6314A:
		INC		_tmp_loop_cnt				; repeat for both scripts
		LDA		_tmp_loop_cnt
		CMP		#$02
		BCC		loc_63139
		LDA		_cur_trd_slot				; now execute additional native
		ASL									; background routine, this routine always
		TAX									; defined to some dummy procedure by default
		LDA		_trds_nbgsub_ptr,X			; so no need to check if it used at all
		STA		_ptr06
		LDA		_trds_nbgsub_ptr+1,X
		STA		_ptr06+1
		JSR		_jmp_ptr06
		LDX		_cur_trd_slot
		LDA		_trds_obj_idx,X				; if thread not stopped during execution,
		BPL		_scr_trd_adjust_pos			; calculate new objexct position with parameters given
		RTS
_scr_trd_adjust_pos:
		LDA		#$00
		STA		_var0
		STA		_var1
		LDA		_obj_x_delta,X				; all move parameters are defined, so just calculate
		BPL		loc_63178					; final positions and update them
		DEC		_var0
loc_63178:
		LDA		_obj_y_delta,X
		BPL		loc_6317F
		DEC		_var1
loc_6317F:
		LDA		_obj_x_clk,X
		CLC
		ADC		_obj_x_speed,X
		STA		_obj_x_clk,X
		LDA		_obj_x_pos_lo,X
		ADC		_obj_x_delta,X
		STA		_obj_x_pos_lo,X
		LDA		_obj_x_pos_hi,X
		ADC		_var0
		STA		_obj_x_pos_hi,X
		LDA		_obj_y_speed,X
		CLC
		ADC		_obj_y_clk,X
		STA		_obj_y_clk,X
		LDA		_obj_y_delta,X
		BMI		loc_631B4
		ADC		_obj_y_pos_lo,X
		BCS		loc_631AF
		CMP		#$F0
		BCC		loc_631BB
loc_631AF:
		ADC		#$0F
		SEC
		BCS		loc_631BB
loc_631B4:
		ADC		_obj_y_pos_lo,X
		BCS		loc_631BB
		SBC		#$0F
		CLC
loc_631BB:
		STA		_obj_y_pos_lo,X
		LDA		_var1
		ADC		_obj_y_pos_hi,X
		STA		_obj_y_pos_hi,X				; that's all here

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
; NEW: update also screen position here and keep it in array for other
; scripts usage instead of multiple recalculating for every object.
;
_obj_screen_pos_update:
		LDA		_obj_x_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_x
		STA		_obj_x_screen_pos,X
		LDA		_obj_x_pos_hi,X
		SBC		_ppu_scroll_pos_x+1
		BNE		.out_of_screen_update
		LDA		_obj_y_pos_lo,X
		SBC		_ppu_scroll_pos_y
		BCS		.skip_adjust
		SBC		#$0F
		CLC
.skip_adjust:
		STA		_obj_y_screen_pos,X
		LDA		_obj_y_pos_hi,X
		SBC		_ppu_scroll_pos_y+1
.out_of_screen_update:
		STA		_obj_out_of_screen,X
		RTS

; =============== S U B R O U T I N E ======n================================
; scripts execution routine, run code until delay is set either with
; SDELAY command or with any delayed command
;
_script_exec:
		LDX		_cur_trd_scr_slot			; every script has delay priority option
		LDA		_trds_scr_delay,X			; if not zero, skip this iteration
		BNE		.scr_exec_delay_skip		; and decrement delay
		TXA
		ASL
		TAX
		LDA		_trd_ptr,X					; fetch corresponding script pointer
		STA		_cur_scr_pc
		LDA		_trd_ptr+1,X
		STA		_cur_scr_pc+1
		LDA		#$00
		STA		_cur_scr_sp+1				; calculate current stack array pos
		TXA
		ASL
		ASL
		ROL		_cur_scr_sp+1
		ADC		#<[_trds_scr_stack]
		STA		_cur_scr_sp
		LDA		_cur_scr_sp+1
		ADC		#>[_trds_scr_stack]
		STA		_cur_scr_sp+1
.scr_exec_loop:
		LDY		#$00						; start to fetch comand
		LDA		(_cur_scr_pc),Y
		PHA
		CMP		#$20						; commands below 0x20 are regular
		BCS		.script_delayed_cmd			; continuos commands except SDELAY
		PLA									; which forced the script execution
		BNE		.script_regular_cmd			; flow interruption
		LDX		_cur_trd_slot				; command 00 is a STOP command
		LDA		#$FF						; disables the thread idx flag and
		STA		_trds_obj_idx,X				; exit from _thread_exec as well
		PLA
		PLA
		RTS
.script_regular_cmd:
		TAX
		LDA		_scmd_lib_lo-1,X
		STA		_ptr06
		LDA		_scmd_lib_hi-1,X
		BNE		.script_cmd_exec
.script_delayed_cmd:
		LDX		_cur_trd_scr_slot			; delayed cmd may be executed continuosly
		PLA									; if no delay set, if set, every time it
		PHA									; executed, script flow stopped to the next
		AND		#$07						; iteration
		STA		_trds_scr_delay,X
		PLA
		SEC
		SBC		#$20
		LSR
		LSR
		LSR
		TAX
		LDA		_dcmd_lib_lo,X
		STA		_ptr06
		LDA		_dcmd_lib_hi,X
.script_cmd_exec:
		STA		_ptr06+1
		JSR		_jmp_ptr06
		LDX		_cur_trd_scr_slot			; if no delays set during execution, continue
		LDA		_trds_scr_delay,X			; script code flow
		BEQ		.scr_exec_loop				; otherwise stop execution and continue to the
		TXA									; next script/thread
		ASL
		TAX
		LDA		_cur_scr_pc					; flush current PC pointer
		STA		_trd_ptr,X
		LDA		_cur_scr_pc+1
		STA		_trd_ptr+1,X
.scr_exec_delay_skip:
		LDX		_cur_trd_scr_slot			; do delays count as well
		DEC		_trds_scr_delay,X
		RTS

; NOTE: there are two sets of script comands. this block describes
; the immediate opcodes, executed immediately and continue code flow
; after that.
_scmd_lib_lo:
		CMD_IDX_LO	_scmd01_loop_begin
		CMD_IDX_LO	_scmd02_loop_end
		CMD_IDX_LO	_scmd03_sjmp
		CMD_IDX_LO	_scmd04_sjsr
		CMD_IDX_LO	_scmd05_ret
		CMD_IDX_LO	_scmd06_delay
		CMD_IDX_LO	_scmd07_njsr
		CMD_IDX_LO	_scmd08_script1_set
		CMD_IDX_LO	_scmd09_nbg_hndl_set
		CMD_IDX_LO	_scmd0A_suspend
#if OPTIMIZATION==1
		CMD_IDX_LO	_scmd1C_bcss
		CMD_IDX_LO	_scmd1D_bccs
#else
		CMD_IDX_LO	_scmd0B_bcs
		CMD_IDX_LO	_scmd0C_bcc
#endif
		CMD_IDX_LO	_scmd0A_script0_off
		CMD_IDX_LO	_scmd0E_smem_alu
		CMD_IDX_LO	_scmd0F_sarg_set
		CMD_IDX_LO	_scmd10_nbg_hndl_reset
		CMD_IDX_LO	_scmd11_sloc_sw
		CMD_IDX_LO	_scmd12_ssub_sw
		CMD_IDX_LO	_scmd13_store8
		CMD_IDX_LO	_scmd14_script1_off
		CMD_IDX_LO	_scmd15_sarg_alu
		CMD_IDX_LO	_scmd16_store16
		CMD_IDX_LO	_scmd17_sbcs_break
;		CMD_IDX_LO	_scmd18_sbcc_break		; unused
;		CMD_IDX_LO	_scmd19_njsr_sw			; unused
#if OPTIMIZATION==1
		CMD_IDX_LO	_scmd1A_sjmps
		CMD_IDX_LO	_scmd1B_sjsrs
		CMD_IDX_LO	_scmd1C_store8s
		CMD_IDX_LO	_scmd1D_store16s
#endif
_scmd_lib_hi:
		CMD_IDX_HI	_scmd01_loop_begin
		CMD_IDX_HI	_scmd02_loop_end
		CMD_IDX_HI	_scmd03_sjmp
		CMD_IDX_HI	_scmd04_sjsr
		CMD_IDX_HI	_scmd05_ret
		CMD_IDX_HI	_scmd06_delay
		CMD_IDX_HI	_scmd07_njsr
		CMD_IDX_HI	_scmd08_script1_set
		CMD_IDX_HI	_scmd09_nbg_hndl_set
		CMD_IDX_HI	_scmd0A_suspend
#if OPTIMIZATION==1
		CMD_IDX_HI	_scmd1C_bcss
		CMD_IDX_HI	_scmd1D_bccs
#else
		CMD_IDX_HI	_scmd0B_bcs
		CMD_IDX_HI	_scmd0C_bcc
#endif
		CMD_IDX_HI	_scmd0A_script0_off
		CMD_IDX_HI	_scmd0E_smem_alu
		CMD_IDX_HI	_scmd0F_sarg_set
		CMD_IDX_HI	_scmd10_nbg_hndl_reset
		CMD_IDX_HI	_scmd11_sloc_sw
		CMD_IDX_HI	_scmd12_ssub_sw
		CMD_IDX_HI	_scmd13_store8
		CMD_IDX_HI	_scmd14_script1_off
		CMD_IDX_HI	_scmd15_sarg_alu
		CMD_IDX_HI	_scmd16_store16
		CMD_IDX_HI	_scmd17_sbcs_break
;		CMD_IDX_HI	_scmd18_sbcc_break
;		CMD_IDX_HI	_scmd19_njsr_sw
#if OPTIMIZATION==1
		CMD_IDX_HI	_scmd1A_sjmps
		CMD_IDX_HI	_scmd1B_sjsrs
		CMD_IDX_HI	_scmd1C_store8s
		CMD_IDX_HI	_scmd1D_store16s
#endif
; NOTE: every opcode in this block has additional parameter of delay
; command is executed then script delayed for a number of frames from
; 1 to 7. if delay 0 selected, then there is no delay there.
; delay means that current script will skip selected amount of frames
; after execution. for sprite management this means setting of this
; sprite will be applied and shown for selected amont of time.
_dcmd_lib_lo:
		DCMD_IDX_LO	_dcmd00_spr_idx_set
		DCMD_IDX_LO	_dcmd01_pos_x_set
		DCMD_IDX_LO	_dcmd02_pos_y_set
		DCMD_IDX_LO	_dcmd03_pos_x_move
		DCMD_IDX_LO	_dcmd04_pos_y_move
		DCMD_IDX_LO	_dcmd05_pos_x_delta
		DCMD_IDX_LO	_dcmd06_pos_y_delta
		DCMD_IDX_LO	_dcmd07_pos_x_delta_add
		DCMD_IDX_LO	_dcmd08_pos_y_delta_add
		DCMD_IDX_LO	_dcmd09_scrl_x_set		; unused
		DCMD_IDX_LO	_dcmd0A_scrl_y_sey
		DCMD_IDX_LO	_dcmd0B_scrl_x_move_set
		DCMD_IDX_LO	_dcmd0C_scrl_y_move_set	; unused
;		DCMD_IDX_LO	_dcmd0D_scrl_x_move_add	; unused
;		DCMD_IDX_LO	_dcmd0E_scrl_y_move_add	; unused
		DCMD_IDX_LO	_dcmd0F_spr_idx_inc
		DCMD_IDX_LO	_dcmd10_spr_idx_dec
		DCMD_IDX_LO	_dcmd11_spr_idx_add_imm
;		DCMD_IDX_LO	_dcmd12_scrl_x_page_add	; unused
;		DCMD_IDX_LO	_dcmd13_scrl_y_page_add	; unused
		DCMD_IDX_LO	_dcmd14_pos_move_stop
		DCMD_IDX_LO	_dcmd15_scrl_move_stop
_dcmd_lib_hi:
		DCMD_IDX_HI	_dcmd00_spr_idx_set
		DCMD_IDX_HI	_dcmd01_pos_x_set
		DCMD_IDX_HI	_dcmd02_pos_y_set
		DCMD_IDX_HI	_dcmd03_pos_x_move
		DCMD_IDX_HI	_dcmd04_pos_y_move
		DCMD_IDX_HI	_dcmd05_pos_x_delta
		DCMD_IDX_HI	_dcmd06_pos_y_delta
		DCMD_IDX_HI	_dcmd07_pos_x_delta_add
		DCMD_IDX_HI	_dcmd08_pos_y_delta_add
		DCMD_IDX_HI	_dcmd09_scrl_x_set
		DCMD_IDX_HI	_dcmd0A_scrl_y_sey
		DCMD_IDX_HI	_dcmd0B_scrl_x_move_set
		DCMD_IDX_HI	_dcmd0C_scrl_y_move_set
;		DCMD_IDX_HI	_dcmd0D_scrl_x_move_add
;		DCMD_IDX_HI	_dcmd0E_scrl_y_move_add
		DCMD_IDX_HI	_dcmd0F_spr_idx_inc
		DCMD_IDX_HI	_dcmd10_spr_idx_dec
		DCMD_IDX_HI	_dcmd11_spr_idx_add_imm
;		DCMD_IDX_HI	_dcmd12_scrl_x_page_add
;		DCMD_IDX_HI	_dcmd13_scrl_y_page_add
		DCMD_IDX_HI	_dcmd14_pos_move_stop
		DCMD_IDX_HI	_dcmd15_scrl_move_stop

; =============== S U B R O U T I N E ======n================================
_scmd01_loop_begin:
		JSR		_scr_getc
		PHA
		LDX		_cur_trd_scr_slot
		LDY		_trds_scr_sp,X
		LDA		_cur_scr_pc
		CLC
		ADC		#$01
		PHA
		LDA		_cur_scr_pc+1
		ADC		#$00
		STA		(_cur_scr_sp),Y
		INY
		PLA
		STA		(_cur_scr_sp),Y
		INY
		PLA
		STA		(_cur_scr_sp),Y
		INY
		TYA
		STA		_trds_scr_sp,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd02_loop_end:
		LDX		_cur_trd_scr_slot
		LDY		_trds_scr_sp,X
		DEY
		LDA		(_cur_scr_sp),Y
		SEC
		SBC		#$01
		STA		(_cur_scr_sp),Y
		BNE		loc_632E1
		DEY
		DEY
		TYA
		STA		_trds_scr_sp,X
		JMP		_cur_scr_pc_inc
loc_632E1:
		DEY
		LDA		(_cur_scr_sp),Y
		STA		_cur_scr_pc
		DEY
		LDA		(_cur_scr_sp),Y
		STA		_cur_scr_pc+1
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd03_sjmp:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		STA		_cur_scr_pc+1
		PLA
		STA		_cur_scr_pc
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd04_sjsr:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		JSR		_cur_scr_pc_inc
		LDX		_cur_trd_scr_slot
		LDY		_trds_scr_sp,X
		LDA		_cur_scr_pc+1
		STA		(_cur_scr_sp),Y
		INY
		LDA		_cur_scr_pc
		STA		(_cur_scr_sp),Y
		INY
		TYA
		STA		_trds_scr_sp,X
		PLA
		STA		_cur_scr_pc+1
		PLA
		STA		_cur_scr_pc
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd05_ret:
		LDX		_cur_trd_scr_slot			; NOTE, the method of handling parallel
		LDY		_trds_scr_sp,X				; scripts sometime causes clear script
		BEQ		loc_63334					; stacks during execution of the sub routines...
		DEY
		LDA		(_cur_scr_sp),Y
		STA		_cur_scr_pc
		DEY
		LDA		(_cur_scr_sp),Y
		STA		_cur_scr_pc+1
		TYA
		STA		_trds_scr_sp,X
		RTS
loc_63334:
		LDX		_cur_trd_slot				; ...so if script trying to return from _ssub
		LDA		#$FF						; with empty stack, we just silently exit it
		STA		_trds_obj_idx,X				; and keep executing the res.
		PLA
		PLA
		PLA
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd06_delay:
		JSR		_scr_getc
		LDX		_cur_trd_scr_slot
		STA		_trds_scr_delay,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd00_spr_idx_set:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		STA		_obj_spr_idx,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd01_pos_x_set:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		STA		_obj_x_pos_lo,X
		JSR		_scr_getc
		STA		_obj_x_pos_hi,X
		LDA		#$80
		STA		_obj_x_clk,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd02_pos_y_set:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		STA		_obj_y_pos_lo,X
		JSR		_scr_getc
		STA		_obj_y_pos_hi,X
		LDA		#$80
		STA		_obj_y_clk,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd05_pos_x_delta:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		STA		_obj_x_speed,X
		JSR		_scr_getc
		STA		_obj_x_delta,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd06_pos_y_delta:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		STA		_obj_y_speed,X
		JSR		_scr_getc
		STA		_obj_y_delta,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd07_pos_x_delta_add:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		CLC
		ADC		_obj_x_speed,X
		STA		_obj_x_speed,X
		PHP
		JSR		_scr_getc
		PLP
		ADC		_obj_x_delta,X
		STA		_obj_x_delta,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd08_pos_y_delta_add:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		CLC
		ADC		_obj_y_speed,X
		STA		_obj_y_speed,X
		PHP
		JSR		_scr_getc
		PLP
		ADC		_obj_y_delta,X
		STA		_obj_y_delta,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; unused
_dcmd09_scrl_x_set:
		JSR		_scr_getc
		STA		_ppu_scroll_pos_x
		JSR		_scr_getc
		STA		_ppu_scroll_pos_x+1
		LDA		#$80
		STA		_ppu_scroll_x_clk
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd0A_scrl_y_sey:
		JSR		_scr_getc
		STA		_ppu_scroll_pos_y
		JSR		_scr_getc
		STA		_ppu_scroll_pos_y+1
		LDA		#$80
		STA		_ppu_scroll_y_clk
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; unused
_dcmd0B_scrl_x_move_set:
		JSR		_scr_getc
		STA		_ppu_scroll_x_shift
		JSR		_scr_getc
		STA		_ppu_scroll_x_shift+1
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd0C_scrl_y_move_set:
		JSR		_scr_getc
		STA		_ppu_scroll_y_shift
		JSR		_scr_getc
		STA		_ppu_scroll_y_shift+1
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; unused
;_dcmd0D_scrl_x_move_add:
;		JSR		_scr_getc
;		CLC
;		ADC		_ppu_scroll_x_shift
;		STA		_ppu_scroll_x_shift
;		PHP
;		JSR		_scr_getc
;		PLP
;		ADC		_ppu_scroll_x_shift+1
;		STA		_ppu_scroll_x_shift+1
;		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; unused
;_dcmd0E_scrl_y_move_add:
;		JSR		_scr_getc
;		CLC
;		ADC		_ppu_scroll_y_shift
;		STA		_ppu_scroll_y_shift
;		PHP
;		JSR		_scr_getc
;		PLP
;		ADC		_ppu_scroll_y_shift+1
;		STA		_ppu_scroll_y_shift+1
;		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd03_pos_x_move:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		LDY		#$00
		STY		_var0
		TAY
		BPL		loc_63447
		DEC		_var0
loc_63447:
		CLC
		ADC		_obj_x_pos_lo,X
		STA		_obj_x_pos_lo,X
		LDA		_obj_x_pos_hi,X
		ADC		_var0
		STA		_obj_x_pos_hi,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd04_pos_y_move:
		LDX		_cur_trd_slot
		JSR		_scr_getc
		CLC
		BMI		loc_63471
		ADC		_obj_y_pos_lo,X
		BCS		loc_63467
		CMP		#$F0
		BCC		loc_6346C
loc_63467:
		ADC		#$0F
		INC		_obj_y_pos_hi,X
loc_6346C:
		STA		_obj_y_pos_lo,X
		JMP		_cur_scr_pc_inc
loc_63471:
		ADC		_obj_y_pos_lo,X
		BCS		loc_6347A
		SBC		#$0F
		DEC		_obj_y_pos_hi,X
loc_6347A:
		STA		_obj_y_pos_lo,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; unused
;_dcmd12_scrl_x_page_add:
;		LDX		_cur_trd_slot
;		JSR		_scr_getc
;		CLC
;		ADC		_ppu_scroll_x_page
;		STA		_ppu_scroll_x_page
;		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; unused
;_dcmd13_scrl_y_page_add:
;		LDX		_cur_trd_slot
;		JSR		_scr_getc
;		CLC
;		ADC		_ppu_scroll_y_page
;		STA		_ppu_scroll_y_page
;		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd14_pos_move_stop:
		LDX		_cur_trd_slot
		LDA		#$00
		STA		_obj_x_speed,X
		STA		_obj_x_delta,X
		STA		_obj_y_speed,X
		STA		_obj_y_delta,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd15_scrl_move_stop:
		LDX		_cur_trd_slot
		LDA		#$00
		STA		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_shift+1
		STA		_ppu_scroll_y_shift
		STA		_ppu_scroll_y_shift+1
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd07_njsr:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_jmp_ptr06
		STA		_nsub_return_value
		PHP
		PLA
		STA		_nsub_return_flags
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd11_sloc_sw:
		JSR		_scr_getc
		JSR		_cur_scr_pc_inc
		CMP		_nsub_return_value
		BCC		_scmd_skip
		BNE		_cmd_switch_case

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_scmd_skip:
		ASL
		ADC		_cur_scr_pc
		STA		_cur_scr_pc
		BCC		locret_63512
		INC		_cur_scr_pc+1
locret_63512:
		RTS

; =============== S U B R O U T I N E ======n================================
_cmd_switch_case:
		LDA		_nsub_return_value
		ASL
		TAY
		LDA		(_cur_scr_pc),Y
		PHA
		INY
		LDA		(_cur_scr_pc),Y
		STA		_cur_scr_pc+1
		PLA
		STA		_cur_scr_pc
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd12_ssub_sw:
		JSR		_scr_getc
		JSR		_cur_scr_pc_inc
		CMP		_nsub_return_value
		BCC		_scmd_skip
		BEQ		_scmd_skip
		LDX		_cur_trd_scr_slot
		LDY		_trds_scr_sp,X
		INY
		ASL
		ADC		_cur_scr_pc
		STA		(_cur_scr_sp),Y
		DEY
		LDA		#$00
		ADC		_cur_scr_pc+1
		STA		(_cur_scr_sp),Y
		INY
		INY
		TYA
		STA		_trds_scr_sp,X
		BNE		_cmd_switch_case

; =============== S U B R O U T I N E ======n================================
; unused
;_scmd19_njsr_sw:
;		JSR		_scr_getc
;		JSR		_cur_scr_pc_inc
;		CMP		_nsub_return_value
;		BCC		_scmd_skip
;		BEQ		_scmd_skip
;		PHA
;		LDA		_nsub_return_value
;		ASL
;		TAY
;		LDA		(_cur_scr_pc),Y
;		STA		_ptr06
;		INY
;		LDA		(_cur_scr_pc),Y
;		STA		_ptr06+1
;		JSR		_jmp_ptr06
;		STA		_nsub_return_value
;		PHP
;		PLA
;		STA		_nsub_return_flags
;		PLA
;		JMP		_scmd_skip

; =============== S U B R O U T I N E ======n================================
; disables currently executing script for given thread
;
_scmd0A_script0_off:
		LDA		_cur_trd_scr_slot
		ASL
		TAX
		LDA		#$00
		STA		_trd_ptr+1,X
		PLA
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
; sets a new script pointer for current thread, select one of two script
; slots with first parameter. never used for re-load the main script, only
; for loading an additional secondary sub-script.
;
_scmd08_script1_set:
#if OPTIMIZATION==0
		JSR		_scr_getc
		STA		_var0
#endif
		JSR		_scr_getc
		STA		_var1
		JSR		_scr_getc
		STA		_var2
		LDA		_cur_trd_slot
		ASL
#if OPTIMIZATION==1
		TAX
		INX
#else
		ADC		_var0
		TAX
#endif
		LDA		#$00
		STA		_trds_scr_sp,X
		STA		_trds_scr_delay,X
		TXA
		ASL
		TAX
		LDA		_var1
		STA		_trd_ptr,X
		LDA		_var2
		STA		_trd_ptr+1,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
; disables the selected script for current thread. also never used to disable
; main script for thread, only for secondary one... in any cases that need
; to disable main script, SSCRIPT0_OFF command used!
;
_scmd14_script1_off:
#if OPTIMIZATION==0
		JSR		_scr_getc
		STA		_tmp0
#endif
		LDA		_cur_trd_slot
		ASL
#if OPTIMIZATION==1
		ADC		#$01
#else
		ADC		_tmp0
#endif
		ASL
		TAX
		LDA		#$00
		STA		_trd_ptr+1,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd09_nbg_hndl_set:
		LDA		_cur_trd_slot
		ASL
		TAX
		JSR		_scr_getc
		STA		_trds_nbgsub_ptr,X
		JSR		_scr_getc
		STA		_trds_nbgsub_ptr+1,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd0A_suspend:
		LDX		_cur_trd_scr_slot
		LDA		#$FF
		STA		_trds_scr_delay,X
		RTS

; =============== S U B R O U T I N E ======n================================
_dcmd0F_spr_idx_inc:
		LDX		_cur_trd_slot
		INC		_obj_spr_idx,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd10_spr_idx_dec:
		LDX		_cur_trd_slot
		DEC		_obj_spr_idx,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_dcmd11_spr_idx_add_imm:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CLC
		ADC		_obj_spr_idx,X
		STA		_obj_spr_idx,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd15_sarg_alu:
		JSR		_scr_getc
		TAX
		LDA		_trds_args_ptrs_lo,X
		CLC
		ADC		_cur_trd_slot
		STA		_ptr08
		LDA		_trds_args_ptrs_hi,X
		ADC		#$00
		STA		_ptr08+1
		BCC		_scr_alu_exec

; =============== S U B R O U T I N E ======n================================
_scmd0E_smem_alu:
		JSR		_scr_getc					; get RAM offset
		STA		_ptr08
		JSR		_scr_getc
		STA		_ptr08+1

; =============== S U B R O U T I N E ======n================================
; REDUNDANT, two of three ALU operations in this game never used (AND and ORA)
; since we don't need the rest, we may remove it for optimized build.
_scr_alu_exec:
#if OPTIMIZATION==0
		JSR		_scr_getc
		TAX
#endif
		JSR		_scr_getc					; also get argument
		STA		_tmp0
		JSR		_cur_scr_pc_inc
#if OPTIMIZATION==0
		LDA		_scmd0E_sub_lib_lo,X
		STA		_ptr06
		LDA		_scmd0E_sub_lib_hi,X
		STA		_ptr06+1
		JMP		(_ptr06)
_scmd0E_sub_lib_lo:
		.BYTE	<[_scmd0E_and]
		.BYTE	<[_scmd0E_ora]
		.BYTE	<[_scmd0E_adc]
_scmd0E_sub_lib_hi:
		.BYTE	>[_scmd0E_and]
		.BYTE	>[_scmd0E_ora]
		.BYTE	>[_scmd0E_adc]

; =============== S U B R O U T I N E ======n================================
; AND subfunction unused
_scmd0E_and:
		LDA		(_ptr08),Y
		AND		_tmp0
		STA		(_ptr08),Y
		RTS

; =============== S U B R O U T I N E ======n================================
; ORA subfunction unused
_scmd0E_ora:
		LDA		(_ptr08),Y
		ORA		_tmp0
		STA		(_ptr08),Y
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd0E_adc:
#endif
		LDA		(_ptr08),Y					; now just add
		CLC
		ADC		_tmp0
		STA		(_ptr08),Y
		RTS

; =============== S U B R O U T I N E ======n================================
_scmd0F_sarg_set:
		JSR		_scr_getc
		TAX
		LDA		_trds_args_ptrs_lo,X
		STA		_ptr06
		LDA		_trds_args_ptrs_hi,X
		STA		_ptr06+1
		JSR		_scr_getc
		LDY		_cur_trd_slot
		STA		(_ptr06),Y
		JMP		_cur_scr_pc_inc

_trds_args_ptrs_lo:
		.BYTE	<[_trds_args0]
		.BYTE	<[_trds_args1]
		.BYTE	<[_trds_args2]
_trds_args_ptrs_hi:
		.BYTE	>[_trds_args0]
		.BYTE	>[_trds_args1]
		.BYTE	>[_trds_args2]

; =============== S U B R O U T I N E ======n================================
_scmd10_nbg_hndl_reset:
		LDA		_cur_trd_slot
		ASL
		TAX
		LDA		#<[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr,X
		LDA		#>[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr+1,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd13_store8:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_scr_getc
		STA		(_ptr06),Y
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd16_store16:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_scr_getc
		STA		(_ptr06),Y
		JSR		_scr_getc
		INY
		STA		(_ptr06),Y
		JMP		_cur_scr_pc_inc

#if OPTIMIZATION==1
; =============== S U B R O U T I N E ======n================================
_scmd1C_store8s:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		STA		$00,X
		JMP		_cur_scr_pc_inc

; =============== S U B R O U T I N E ======n================================
_scmd1D_store16s:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		STA		$00,X
		JSR		_scr_getc
		INX
		STA		$00,X
		JMP		_cur_scr_pc_inc
#endif

; =============== S U B R O U T I N E ======n================================
; unused
;_scmd18_sbcc_break:
;		LDA		_nsub_return_flags
;		LSR
;		BCC		_scr_break
;		JMP		_scr_long_ofs_skip

; =============== S U B R O U T I N E ======n================================
_scr_break:
		LDX		_cur_trd_scr_slot
		LDA		_trds_scr_sp,X
		SEC
		SBC		#$03
		STA		_trds_scr_sp,X
		JMP		_scmd03_sjmp

; =============== S U B R O U T I N E ======n================================
_scmd17_sbcs_break:
		LDA		_nsub_return_flags
		LSR
		BCS		_scr_break
		JMP		_scr_long_ofs_skip

; =============== S U B R O U T I N E ======n================================
_scr_getc:
		INC		_cur_scr_pc
		BNE		loc_636DD
		INC		_cur_scr_pc+1
loc_636DD:
		LDA		(_cur_scr_pc),Y
		RTS

; =============== S U B R O U T I N E ======n================================
_cur_scr_pc_inc:
		INC		_cur_scr_pc
		BNE		locret_636E6
		INC		_cur_scr_pc+1
locret_636E6:
		RTS

#if OPTIMIZATION==1
; =============== S U B R O U T I N E =======================================
_scr_get_short_ofs:
		LDA		#$00
		STA		_tmp0
		JSR		_scr_getc
		BPL		.positive
		DEC		_tmp0
.positive:
		RTS

; =============== S U B R O U T I N E =======================================
_scmd1A_sjmps:
		JSR		_scr_get_short_ofs
#endif

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_cur_scr_pc_add:
		CLC
		ADC		_cur_scr_pc
		STA		_cur_scr_pc
		LDA		_cur_scr_pc+1
		ADC		_tmp0
		STA		_cur_scr_pc+1
		RTS

#if OPTIMIZATION==1
; =============== S U B R O U T I N E ======n================================
_scmd1B_sjsrs:
		JSR		_scr_get_short_ofs
		PHA
		JSR		_cur_scr_pc_inc
		LDX		_cur_trd_scr_slot
		LDY		_trds_scr_sp,X
		LDA		_cur_scr_pc+1
		STA		(_cur_scr_sp),Y
		INY
		LDA		_cur_scr_pc
		STA		(_cur_scr_sp),Y
		INY
		TYA
		STA		_trds_scr_sp,X
		PLA
		JMP		_cur_scr_pc_add

; =============== S U B R O U T I N E ======n================================
_scmd1C_bcss:
		LDA		_nsub_return_flags
		LSR
		BCS		_scmd1A_sjmps

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_scr_short_ofs_skip:
		LDA		#$00
		STA		_tmp0
		LDA		#$02
		BNE		_cur_scr_pc_add

; =============== S U B R O U T I N E ======n================================
_scmd1D_bccs:
		LDA		_nsub_return_flags
		LSR
		BCS		_scr_short_ofs_skip
		BCC		_scmd1A_sjmps
#endif

#if OPTIMIZATION==0
; =============== S U B R O U T I N E ======n================================
; NEW: both functions here while OPTIMIZATION option is enabled, never used!
;
_scmd0C_bcc:
		LDA		_nsub_return_flags
		LSR
		BCS		_scr_long_ofs_skip
		JMP		_scmd03_sjmp

; =============== S U B R O U T I N E ======n================================
_scmd0B_bcs:
		LDA		_nsub_return_flags
		LSR
		BCC		_scr_long_ofs_skip
		JMP		_scmd03_sjmp
#endif

; =============== S U B R O U T I N E ======n================================
_scr_long_ofs_skip:
		LDA		#$00
		STA		_tmp0
		LDA		#$03
		JMP		_cur_scr_pc_add

;_inv_bitmask_unref:
;		.BYTE	$7F,$BF,$DF,$EF,$F7,$FB,$FD,$FE
_bit_mask:
		.BYTE	$80,$40,$20,$10,$08,$04,$02,$01

; =============== S U B R O U T I N E ======n================================
_spr_shuffle_update:
		LDA		_spr_buf_pos
		CMP		#$21
		BCS		loc_63702
		SBC		#$1F
		JMP		loc_63706
loc_63702:
		LDA		_spr_buf_shuffle
		ADC		#$DF
loc_63706:
		STA		_spr_buf_shuffle
		STA		_spr_buf_pos
		RTS

; =============== S U B R O U T I N E ======n================================
_spr_finish:
		LDA		#$F0
		LDY		_spr_buf_pos
loc_6370F:
		STA		_ppu_spr_buf,Y
		INY
		INY
		INY
		INY
		CPY		_spr_buf_shuffle
		BNE		loc_6370F
		RTS

; =============== S U B R O U T I N E ======n================================
_jmp_ptr06:
		JMP		(_ptr06)

; =============== S U B R O U T I N E ======n================================
; this is a special thread loading routine to replace currently executing
; script for given thread with a new one with full reset of the execution
; flow. after this thread started from the beginning with all parameters
; reset but still have the same _cur_trd_slot thus using the same data
; bank
;
_cur_thread_reload_param:
		LDX		_cur_trd_slot

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
; in case we need to reload a script for a particular thread instead of current
; one
;
_thread_reload_param_ex:
		PLA
		STA		_ptr06
		PLA
		STA		_ptr06+1
		LDA		_ptr06
		CLC
		ADC		#$02
		STA		_tmp0
		LDA		_ptr06+1
		ADC		#$00
		PHA
		LDA		_tmp0
		PHA
		LDY		#$01
		LDA		(_ptr06),Y
		PHA
		INY
		LDA		(_ptr06),Y
		TAY
		PLA
		JMP		_thread_load

; =============== S U B R O U T I N E ======n================================
_scr_cur_trd_off:
		LDX		_cur_trd_slot
		LDA		#$FF
		STA		_trds_obj_idx,X
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_queue_reset:
		LDA		#$00
		STA		_ppu_queue_tail
		STA		_ppu_queue_head
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_nmi_off:
		LDA		_ppu_ctrl_shadow
		AND		#$7F

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_ppu_ctrl_write:
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_nmi_on:
		LDA		_ppu_ctrl_shadow
		ORA		#$80
		BNE		_ppu_ctrl_write

; =============== S U B R O U T I N E ======n================================
_wait_for_nmi:
		PHA									; in case routine is called during
		LDA		_ppu_ctrl_shadow			; render being off, wait nmi using
		BPL		loc_637FF					; _PPU_STATUS flags instead. never
#if DEBUG==1
		LDA		#$00
		STA		_debug_cnt
		STA		_debug_cnt+1
#endif
loc_637F5:									; happens in this game
#if DEBUG==1
		INC		_debug_cnt
		BNE		.deb1
		INC		_debug_cnt+1
.deb1:
#endif
		LDA		_nmi_flag
		BEQ		loc_637F5
		LDA		#$00
		STA		_nmi_flag
		PLA
		RTS
loc_637FF:
		LDA		_PPU_STATUS
		BMI		loc_637FF
loc_63804:
		LDA		_PPU_STATUS
		BPL		loc_63804
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_vblank_off:
		LDA		#$00

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_ppu_vblank_ex:
		JSR		_wait_for_nmi
		STA		_PPU_MASK
		STA		_ppu_mask_shadow
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_vblank_on:
		LDA		_ppu_mask_req
		JSR		_ppu_vblank_ex
		JMP		_ppu_set_scroll

; =============== S U B R O U T I N E ======n================================
; two shortcuts with manual loading of PPU offset goes here.
; note, there are no common raw/direct _nsub type ruotines for this kind of
; procedure (like it does for threads loading), so any rectangular areas has
; to be displayed from custom _nsubs for all particular case.
;
_ppu_res_send_ptr:
		STA		_ptr0A
		STY		_ptr0A+1
		LDA		#$00
		STA		_var3
		JMP		_ppu_res_send_ex

; =============== S U B R O U T I N E ======n================================
_ppu_res_send_ptr_repeat:
		STA		_ptr0A
		STY		_ptr0A+1
		LDA		#$01
		STA		_var3
		JMP		_ppu_res_send_ex

; =============== S U B R O U T I N E ======n================================

_ppu_res_send_param_repeat:
		STA		_tmp0
		LDA		#$01
		BNE		_ppu_res_send_param_ex

; =============== S U B R O U T I N E ======n================================
_ppu_res_send_param_no_ofs:
		STA		_tmp0
		LDA		#$02
		BNE		_ppu_res_send_param_ex

; =============== S U B R O U T I N E ======n================================
_ppu_res_send_param_repeat_no_ofs:
		STA		_tmp0
		LDA		#$03
		BNE		_ppu_res_send_param_ex

; =============== S U B R O U T I N E ======n================================
; commonly used automatic routine goes here. a variety of routines above
; set the various combinations of flags for convinience.
;
_ppu_res_send_param:
		STA		_tmp0
		LDA		#$00

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
; parametric version of this routine.
;
_ppu_res_send_param_ex:
		STA		_var3
		STX		_tmp1
		STY		_tmp2
		PLA
		STA		_ptr06
		PLA
		STA		_ptr06+1
		LDY		#$01
		LDA		(_ptr06),Y
		STA		_ptr0A
		INY
		LDA		(_ptr06),Y
		STA		_ptr0A+1
		LDA		_ptr06
		CLC
		ADC		#$02
		STA		_ptr06
		BCC		loc_6386C
		INC		_ptr06+1
loc_6386C:
		LDA		_ptr06+1
		PHA
		LDA		_ptr06
		PHA

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
; common routine for sending data in specific format to PPU. as many of
; system//library routines here this one includes a lot of special cases
; which allows to use it in any game mode and you don't have to know if
; render is on or off (which is the case for many other games)..
; this routine checking current PPU status and decided how to send the data
; by self, wether the directly to PPU or via queue buffer.
; additionally, this routine has a special control flags (_var3) to be more
; flexible for various types of data. if flag 01 is set, routine switched in
; repeat mode. the data byte for the whole rect repeated a required number of
; times. flag 02 disables the PPU offset loading at the beginning of the resource
; so other code must load it manually beforehead.
; NOTE: as some other procedures here, it has an option never used in the game.
; when transferring rectangular screen tilemaps, it check additionally if
; it's width less than height and then will use procedure to vertical
; ppu increments, so this is an obvious optimization for speed, because of
; in this case there are less line feed operations... no rectangular resources
; in this game has height greater than width...
;
_ppu_res_send_ex:
		LDY		#$00
		LDA		_var3
		AND		#$02
		BNE		loc_63884
		LDA		(_ptr0A),Y
		STA		_ptr08
		INY
		LDA		(_ptr0A),Y
		STA		_ptr08+1
		INY
loc_63884:
		LDA		(_ptr0A),Y
		STA		_var1
		INY
		LDA		(_ptr0A),Y
		STA		_var2
		INY
;		LDA		_var1						; REDUNDANT, currently not neded
;		CMP		_var2
;		BCC		_vertical_mode
		LDX		_var2
.res_send_hor_loop:
		TXA
		PHA
		LDA		_ppu_mask_shadow
		BNE		.res_send_hor_queue
; REGION, replaced in the EU version
		LDA		#$01
		STA		_ppu_forbid_flag
;		LDA		_ppu_ctrl_shadow
;		PHA
;		JSR		_ppu_nmi_off
; -
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_ptr08+1
		STA		_PPU_ADDR
		LDA		_ptr08
		STA		_PPU_ADDR
		LDX		_var1
loc_638B3:
		LDA		(_ptr0A),Y
		STA		_PPU_DATA
		LDA		_var3
		LSR
		BCS		loc_638C3
		INC		_ptr0A
		BNE		loc_638C3
		INC		_ptr0A+1
loc_638C3:
		DEX
		BNE		loc_638B3
; REGION, replaced in the EU version
		LDA		#$00
		STA		_ppu_forbid_flag
;		PLA
;		JSR		_ppu_ctrl_write
; -
		JMP		loc_638EC
.res_send_hor_queue:
		JSR		_ppu_queue_putw
		LDX		_var1
		TXA
		JSR		_ppu_queue_putc
loc_638D6:
		LDA		(_ptr0A),Y
		JSR		_ppu_queue_putc
		LDA		_var3
		LSR
		BCS		loc_638E6
		INC		_ptr0A
		BNE		loc_638E6
		INC		_ptr0A+1
loc_638E6:
		DEX
		BNE		loc_638D6
		JSR		_ppu_queue_head_update
loc_638EC:
		LDA		_ptr08
		CLC
		ADC		#$20
		STA		_ptr08
		BCC		loc_638F7
		INC		_ptr08+1
loc_638F7:
		PLA
		TAX
		DEX
		BNE		.res_send_hor_loop
		LDA		_tmp0
		LDX		_tmp1
		LDY		_tmp2
		RTS
; NOTE: there are no resources with vertical rectangles, so this branch never used
;_vertical_mode:
;		LDA		_ptr08+1
;		ORA		#$80
;		STA		_ptr08+1
;		LDX		_var1
;.res_send_vert_loop:
;		TXA
;		PHA
;		LDA		_ptr0A
;		PHA
;		LDA		_ptr0A+1
;		PHA
;		LDA		_ppu_mask_shadow
;		BNE		.res_send_vert_queue
;; REGION, replaced in the EU version
;		LDA		#$01
;		STA		_ppu_forbid_flag
;;		LDA		_ppu_ctrl_shadow
;;		PHA
;;		JSR		_ppu_nmi_off
;; -
;		LDA		_ppu_ctrl_shadow
;		ORA		#$04
;		STA		_PPU_CTRL
;		LDA		_ptr08+1
;		AND		#$7F
;		STA		_PPU_ADDR
;		LDA		_ptr08
;		STA		_PPU_ADDR
;		LDX		_var2
;loc_63932:
;		LDA		(_ptr0A),Y
;		STA		_PPU_DATA
;		LDA		_var3
;		LSR
;		BCS		loc_63947
;		LDA		_ptr0A
;		CLC
;		ADC		_var1
;		STA		_ptr0A
;		BCC		loc_63947
;		INC		_ptr0A+1
;loc_63947:
;		DEX
;		BNE		loc_63932
;; REGION, replaced in the EU version
;		LDA		#$00
;		STA		_ppu_forbid_flag
;;		PLA
;;		JSR		_ppu_ctrl_write
;; -
;		JMP		loc_63975
;.res_send_vert_queue:
;		JSR		_ppu_queue_putw
;		LDX		_var2
;		TXA
;		JSR		_ppu_queue_putc
;loc_6395A:
;		LDA		(_ptr0A),Y
;		JSR		_ppu_queue_putc
;		LDA		_var3
;		LSR
;		BCS		loc_6396F
;		LDA		_ptr0A
;		CLC
;		ADC		_var1
;		STA		_ptr0A
;		BCC		loc_6396F
;		INC		_ptr0A+1
;loc_6396F:
;		DEX
;		BNE		loc_6395A
;		JSR		_ppu_queue_head_update
;loc_63975:
;		INC		_ptr08
;		BNE		loc_6397B
;		INC		_ptr08+1
;loc_6397B:
;		PLA
;		STA		_ptr0A+1
;		PLA
;		STA		_ptr0A
;		LDA		_var3
;		LSR
;		BCS		loc_6398C
;		INC		_ptr0A
;		BNE		loc_6398C
;		INC		_ptr0A+1
;loc_6398C:
;		PLA
;		TAX
;		DEX
;		BEQ		loc_63994
;		JMP		.res_send_vert_loop
;loc_63994:
;		LDA		_tmp0
;		LDX		_tmp1
;		LDY		_tmp2
;		RTS

; =============== S U B R O U T I N E ======n================================
;_ppu_queue_reset_unref:
;		LDA		_ppu_queue_tail
;		STA		_ppu_queue_head
;		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_queue_putw:
		LDA		_ppu_queue_head
		SEC
		SBC		_ppu_queue_tail
		CMP		#$40
		BCC		loc_639AF
		JSR		_wait_for_nmi
		JMP		_ppu_queue_putw
loc_639AF:
		STX		_var4
		LDX		_ppu_queue_head
		LDA		_ptr08+1
		STA		_ppu_queue_buf,X
		INX
		LDA		_ptr08
		STA		_ppu_queue_buf,X
		INX
		STX		_ppu_queue_pos
		LDX		_var4
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_queue_putc:
		STX		_var4
		LDX		_ppu_queue_pos
		STA		_ppu_queue_buf,X
		INC		_ppu_queue_pos
		LDX		_var4
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_queue_head_update:
		LDA		_ppu_queue_pos
		STA		_ppu_queue_head
		RTS

; =============== S U B R O U T I N E ======n================================
_ppu_dequeue:
		LDA		_ppu_queue_tail
		STA		_ppu_queue_tail_tmp
		CMP		_ppu_queue_head
		BNE		loc_639DE
		RTS
loc_639DE:
		LDA		_ppu_queue_tail
		SEC
		SBC		_ppu_queue_tail_tmp
		CMP		#$30
		BCS		locret_63A30
		LDX		_ppu_queue_tail
		LDA		_ppu_queue_buf,X
		INX
		STA		_tmp1A
		AND		#$7F
		STA		_PPU_ADDR
		LDA		_ppu_queue_buf,X
		INX
		STA		_PPU_ADDR
		LDA		_ppu_ctrl_shadow
		LDY		_tmp1A
		BPL		loc_63A03
		ORA		#$04
loc_63A03:
		STA		_PPU_CTRL
		LDY		_ppu_queue_buf,X
		INX
loc_63A0A:
		LDA		_ppu_queue_buf,X
		INX
		STA		_PPU_DATA
		DEY
		BNE		loc_63A0A
		LDA		_tmp1A
		CMP		#$3F
		BNE		loc_63A2A
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
loc_63A2A:
		STX		_ppu_queue_tail
		CPX		_ppu_queue_head
		BNE		loc_639DE
locret_63A30:
		RTS

#if TWO_PLAYER_MODE==1
; =============== S U B R O U T I N E ======n================================
_get_input:
		LDY		#$00
		JSR		_calc_pad
		INY
_calc_pad:
		JSR		_read_pads
		STA		_tmp1A
		JSR		_read_pads
		AND		_tmp1A
		STA		_tmp1A
		LDA		_pad0_held,Y
		EOR		#$FF
		AND		_tmp1A
		STA		_pad0_pressed,Y
		LDA		_tmp1A
		STA		_pad0_held,Y
		RTS

; =============== S U B R O U T I N E ======n================================
_read_pads:
		LDX		#$01
		STX		_PAD0_REG
		DEX
		STX		_PAD0_REG
		LDX		#$08
loc_63A63:
		PHA
		LDA		_PAD0_REG,Y
		STA		_tmp19
		LSR
		ORA		_tmp19
		LSR
		PLA
		ROL
		DEX
		BNE		loc_63A63
		RTS
#else
; =============== S U B R O U T I N E ======n================================
_get_input:
		JSR		_read_pads					; too paranoid to pad reading on NES
		STA		_tmp1A						; but seems important for real HW
		JSR		_read_pads
		AND		_tmp1A
		STA		_tmp1B
		JSR		_read_pads
		STA		_tmp1A
		JSR		_read_pads
		AND		_tmp1A
		ORA		_tmp1B
		STA		_tmp1A
		LDA		_pad0_held
		EOR		#$FF
		AND		_tmp1A
		STA		_pad0_pressed
		LDA		_tmp1A
		STA		_pad0_held
		RTS

; =============== S U B R O U T I N E ======n================================
_read_pads:
		LDX		#$01
		STX		_PAD0_REG
		DEX
		STX		_PAD0_REG
		LDY		#$08
loc_63A63:
		PHA
		LDA		_PAD0_REG
		STA		_tmp19
		LSR
		ORA		_tmp19
		LSR
		PLA
		ROL
		DEY
		BNE		loc_63A63
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_ppu_spr_fill_F1:
		LDX		#$00
		LDA		#$F1
loc_63A77:
		STA		_ppu_spr_buf,X
		INX
		BNE		loc_63A77
		RTS

; =============== S U B R O U T I N E ======n================================
NMI:
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		#$00
		STA		_PPU_OAM_ADDR
		LDA		#$02
		STA		_PPU_OAM_DMA
; REGION, added in EU version
		LDA		_ppu_forbid_flag
		BNE		loc_63AA1
; -
		JSR		_ppu_dequeue
		JSR		_ppu_set_scroll
loc_63AA1:
		INC		_nmi_flag
		INC		_nmi_counter
		JSR		_get_input
		LDA		_mmc1_busy
		BEQ		loc_63AA2
		STA		_apu_play_delayed_req
		BNE		loc_63ADF
loc_63AA2:
		LDA		_chr_bank0
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LDA		_chr_bank1
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LDA		_prg_cur_bank
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg
		JSR		_apu_play
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg
loc_63ADF:
		PLA
		TAY
		PLA
		TAX
		PLA
		RTI

; =============== S U B R O U T I N E ======n================================
_ppu_set_scroll:
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		_ppu_scroll_pos_x+1
		EOR		_ppu_scroll_pos_y+1
		LSR
		PHP
		LDA		_ppu_scroll_pos_y+1
		EOR		_ppu_scroll_pos_x+1
		LSR
		PHP
		LDA		_ppu_ctrl_shadow
		LSR
		LSR
		PLP
		ROL
		PLP
		ROL
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_ppu_scroll_pos_x
		STA		_PPU_SCROLL
		LDA		_ppu_scroll_pos_y
		STA		_PPU_SCROLL
		RTS

; =============== S U B R O U T I N E ======n================================
_mmc1_ctrl:
		STA		_mmc1_ctrl_shadow
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		RTS

; =============== S U B R O U T I N E ======n================================
_mmc1_prg_safe:
		CMP		_prg_bank
		BEQ		locret_63B6E
		PHA									; very safe bank switching routine and
		STA		_prg_bank					; may be very SLOOOOOW because of that
		INC		_mmc1_busy
		LDA		_prg_bank					; occurs, it will skip any mapper operations
		STA		$FFF9						; this includes calling apu player routine
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		DEC		_mmc1_busy
		LDA		_apu_play_delayed_req		; test if nmi occurs in the middle of process
		BEQ		loc_63B6E					; if yes, then we need to call apu player manually
		LDA		#$00						; this preventing music from slow downs when
		STA		_apu_play_delayed_req		; frames skipped.
		TXA									; also backup current X,Y registers here
		PHA									; to not to break something in caller code
		TYA
		PHA
		LDA		_prg_cur_bank
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		JSR		_apu_play
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		PLA
		TAY
		PLA
		TAX
loc_63B6E:
		PLA
locret_63B6E:
		RTS

; =============== S U B R O U T I N E ======n================================
_mmc1_prg:
		STA		$FFF9						; fastest raw routine to switch banks in mmc1
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		RTS

; =============== S U B R O U T I N E ======n================================
IRQ:
		RTI

; NOTE: flags used to additionally load external arguments for selected script
; index. bits 80, 40 and 20 are corresponds to ARG0, ARG1, ARG2 additionally
; loaded values.
_scr_flags:
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$80
		.BYTE	$40
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$60
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$20
		.BYTE	$40
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$40
		.BYTE	$80
		.BYTE	$00
		.BYTE	$00
		.BYTE	$40
		.BYTE	$40
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
_scr_bank_lib:
		.BYTE	$00
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$00
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$01
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$01
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$03
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$03
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$04
		.BYTE	$03
		.BYTE	$03
		.BYTE	$03
_scr_lib_lo:
;	SYSTEM scripts, never used in level objects lists, ran manually
; 	by the system or by the other scripts
;
		SCR_IDX_LO	_scr00_intro_title_select
		SCR_IDX_LO	_scr01_lvl1_handler
		SCR_IDX_LO	_scr02_lvl2_handler
		SCR_IDX_LO	_scr03_lvl3_handler
		SCR_IDX_LO	_scr04_lvl4_handler
		SCR_IDX_LO	_scr05_lvl5_handler
		SCR_IDX_LO	_scr06_lvl6_handler
		SCR_IDX_LO	_scr07_ending
		SCR_IDX_LO	_scr08_beamer_handler
		SCR_IDX_LO	_scr09_player_beam
		SCR_IDX_LO	_scr0A_catcher_handler
		SCR_IDX_LO	_scr0B_player_catch
		SCR_IDX_LO	_scr0C_room_doors_handler
; 	GAME OBJECT scripts, used in the level objects lists, may run
;	other instances of self
;
		SCR_IDX_LO	_scr0D_money_bag			; sargs 100
; NOTE: for some reason, this object has a redundant in this version
; flag setting. however, there is no empry trolleys used as the room
; objects data, and args are derived from its main object _scr20_trolley_miner
		SCR_IDX_LO	_scr0E_empty_mine_trolley	; sargs 010 except this
		SCR_IDX_LO	_scr0F_candle
		SCR_IDX_LO	_scr10_train_semaphores
		SCR_IDX_LO	_scr11_lvl2_ghost_nanny
		SCR_IDX_LO	_scr12_exit_arrow			; sargs 011
		SCR_IDX_LO	_scr13_slow_moving_slime
		SCR_IDX_LO	_scr14_fast_moving_slime
		SCR_IDX_LO	_scr15_trolley_kick_slime
		SCR_IDX_LO	_scr16_still_throw_forward_slime
		SCR_IDX_LO	_scr17_runner
		SCR_IDX_LO	_scr18_chain_saw
		SCR_IDX_LO	_scr19_toilet_snake
		SCR_IDX_LO	_scr1A_lvl1_boss_judges		; sargs 001
		SCR_IDX_LO	_scr1B_court_chair			; sargs 010
		SCR_IDX_LO	_scr1C_girl_and_floaters
		SCR_IDX_LO	_scr1D_air_hammer_miner
		SCR_IDX_LO	_scr1E_pick_axe_miner
		SCR_IDX_LO	_scr1F_hammer_miner
		SCR_IDX_LO	_scr20_trolley_miner		; sargs 010
		SCR_IDX_LO	_scr21_train_ghost			; sargs 100
		SCR_IDX_LO	_scr22_lvl2_boss_train_slime
		SCR_IDX_LO	_scr23_halloween
		SCR_IDX_LO	_scr24_flying_elephant		; sargs 010
		SCR_IDX_LO	_scr25_stinging_elephant	; sargs 010
		SCR_IDX_LO	_scr26_sword_ninja
		SCR_IDX_LO	_scr27_shuriken_ninja
		SCR_IDX_LO	_scr28_pink_goo
		SCR_IDX_LO	_scr29_sewer_worm
		SCR_IDX_LO	_scr2A_morning_star_troll
		SCR_IDX_LO	_scr2B_still_throw_ballistic_slime
		SCR_IDX_LO	_scr2C_fast_throw_forward_slime
		SCR_IDX_LO	_scr2D_rotator
		SCR_IDX_LO	_scr2E_lvl4_boss_dragons
		SCR_IDX_LO	_scr2F_lvl5_boss_keykeeper
		SCR_IDX_LO	_scr30_lvl6_boss_vega
_scr_lib_hi:
		SCR_IDX_HI	_scr00_intro_title_select
		SCR_IDX_HI	_scr01_lvl1_handler
		SCR_IDX_HI	_scr02_lvl2_handler
		SCR_IDX_HI	_scr03_lvl3_handler
		SCR_IDX_HI	_scr04_lvl4_handler
		SCR_IDX_HI	_scr05_lvl5_handler
		SCR_IDX_HI	_scr06_lvl6_handler
		SCR_IDX_HI	_scr07_ending
		SCR_IDX_HI	_scr08_beamer_handler
		SCR_IDX_HI	_scr09_player_beam
		SCR_IDX_HI	_scr0A_catcher_handler
		SCR_IDX_HI	_scr0B_player_catch
		SCR_IDX_HI	_scr0C_room_doors_handler
		SCR_IDX_HI	_scr0D_money_bag
		SCR_IDX_HI	_scr0E_empty_mine_trolley
		SCR_IDX_HI	_scr0F_candle
		SCR_IDX_HI	_scr10_train_semaphores
		SCR_IDX_HI	_scr11_lvl2_ghost_nanny
		SCR_IDX_HI	_scr12_exit_arrow
		SCR_IDX_HI	_scr13_slow_moving_slime
		SCR_IDX_HI	_scr14_fast_moving_slime
		SCR_IDX_HI	_scr15_trolley_kick_slime
		SCR_IDX_HI	_scr16_still_throw_forward_slime
		SCR_IDX_HI	_scr17_runner
		SCR_IDX_HI	_scr18_chain_saw
		SCR_IDX_HI	_scr19_toilet_snake
		SCR_IDX_HI	_scr1A_lvl1_boss_judges
		SCR_IDX_HI	_scr1B_court_chair
		SCR_IDX_HI	_scr1C_girl_and_floaters
		SCR_IDX_HI	_scr1D_air_hammer_miner
		SCR_IDX_HI	_scr1E_pick_axe_miner
		SCR_IDX_HI	_scr1F_hammer_miner
		SCR_IDX_HI	_scr20_trolley_miner
		SCR_IDX_HI	_scr21_train_ghost
		SCR_IDX_HI	_scr22_lvl2_boss_train_slime
		SCR_IDX_HI	_scr23_halloween
		SCR_IDX_HI	_scr24_flying_elephant
		SCR_IDX_HI	_scr25_stinging_elephant
		SCR_IDX_HI	_scr26_sword_ninja
		SCR_IDX_HI	_scr27_shuriken_ninja
		SCR_IDX_HI	_scr28_pink_goo
		SCR_IDX_HI	_scr29_sewer_worm
		SCR_IDX_HI	_scr2A_morning_star_troll
		SCR_IDX_HI	_scr2B_still_throw_ballistic_slime
		SCR_IDX_HI	_scr2C_fast_throw_forward_slime
		SCR_IDX_HI	_scr2D_rotator
		SCR_IDX_HI	_scr2E_lvl4_boss_dragons
		SCR_IDX_HI	_scr2F_lvl5_boss_keykeeper
		SCR_IDX_HI	_scr30_lvl6_boss_vega

_spr_libs_list:
		.BYTE	$00,$01,$01,$01,$01,$01,$01,$02,$03,$04,$03,$04,$01,$01,$05,$06
		.BYTE	$06,$07,$03,$05,$05,$05,$05,$07,$07,$07,$08,$05,$07,$05,$05,$05
		.BYTE	$05,$05,$08,$06,$06,$06,$06,$06,$06,$06,$07,$05,$05,$06,$08,$08
		.BYTE	$08

_spr_libs_bank_list:
		.BYTE	<[_spr_libA00_bank]	; 00 bank
		.BYTE	<[_spr_libA01_bank]	; 01 bank
		.BYTE	<[_spr_libA02_bank]	; 00 bank
		.BYTE	<[_spr_libA03_bank]	; 01 bank
		.BYTE	<[_spr_libA04_bank]	; 01 bank
		.BYTE	<[_spr_libA05_bank]	; 04 bank
		.BYTE	<[_spr_libA06_bank]	; 04 bank
		.BYTE	<[_spr_libA07_bank]	; 04 bank
		.BYTE	<[_spr_libA08_bank]	; 03 bank
_spr_libA_ofs_tbl_lo:
		.BYTE	<[_spr_libA00]	; 00 bank
		.BYTE	<[_spr_libA01]	; 01 bank
		.BYTE	<[_spr_libA02]	; 00 bank
		.BYTE	<[_spr_libA03]	; 01 bank
		.BYTE	<[_spr_libA04]	; 01 bank
		.BYTE	<[_spr_libA05]	; 04 bank
		.BYTE	<[_spr_libA06]	; 04 bank
		.BYTE	<[_spr_libA07]	; 04 bank
		.BYTE	<[_spr_libA08]	; 03 bank
_spr_libA_ofs_tbl_hi:
		.BYTE	>[_spr_libA00]
		.BYTE	>[_spr_libA01]
		.BYTE	>[_spr_libA02]
		.BYTE	>[_spr_libA03]
		.BYTE	>[_spr_libA04]
		.BYTE	>[_spr_libA05]
		.BYTE	>[_spr_libA06]
		.BYTE	>[_spr_libA07]
		.BYTE	>[_spr_libA08]
_spr_libB_ofs_tbl_lo:
		.BYTE	$00
		.BYTE	$00
		.BYTE	<[_spr_libB02]
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	<[_spr_libB06]
		.BYTE	<[_spr_libB07]
		.BYTE	<[_spr_libB08]
_spr_libB_ofs_tbl_hi:
		.BYTE	$00
		.BYTE	$00
		.BYTE	>[_spr_libB02]
		.BYTE	$00
		.BYTE	$00
		.BYTE	$00
		.BYTE	>[_spr_libB06]
		.BYTE	>[_spr_libB07]
		.BYTE	>[_spr_libB08]

		SECTION_START

		SPR_LIB_START	_spr_libA03

		SPR_IDX	_sprA03_02	; peter	U	A
		SPR_IDX	_sprA03_01	; 			B
		SPR_IDX	_sprA03_02	;			C
		SPR_IDX	_sprA03_03	;			D
		SPR_IDX	_sprA03_06	;		R	A
		SPR_IDX	_sprA03_05	;			B
		SPR_IDX	_sprA03_06	;			C
		SPR_IDX	_sprA03_07	;			D
		SPR_IDX	_sprA03_0A
		SPR_IDX	_sprA03_09
		SPR_IDX	_sprA03_0A
		SPR_IDX	_sprA03_0B
		SPR_IDX	_sprA03_0E
		SPR_IDX	_sprA03_0D
		SPR_IDX	_sprA03_0E
		SPR_IDX	_sprA03_0F
		SPR_IDX	_sprA03_12
		SPR_IDX	_sprA03_11
		SPR_IDX	_sprA03_12
		SPR_IDX	_sprA03_13
		SPR_IDX	_sprA03_16
		SPR_IDX	_sprA03_15
		SPR_IDX	_sprA03_16
		SPR_IDX	_sprA03_17
		SPR_IDX	_sprA03_1A
		SPR_IDX	_sprA03_19
		SPR_IDX	_sprA03_1A
		SPR_IDX	_sprA03_1B
		SPR_IDX	_sprA03_1E
		SPR_IDX	_sprA03_1D
		SPR_IDX	_sprA03_1E
		SPR_IDX	_sprA03_1F
		SPR_IDX	_sprA03_22
		SPR_IDX	_sprA03_21
		SPR_IDX	_sprA03_22
		SPR_IDX	_sprA03_23
		SPR_IDX	_sprA03_26
		SPR_IDX	_sprA03_25
		SPR_IDX	_sprA03_26
		SPR_IDX	_sprA03_27
		SPR_IDX	_sprA03_2A
		SPR_IDX	_sprA03_29
		SPR_IDX	_sprA03_2A
		SPR_IDX	_sprA03_2B
		SPR_IDX	_sprA03_2E
		SPR_IDX	_sprA03_2D
		SPR_IDX	_sprA03_2E
		SPR_IDX	_sprA03_2F
		SPR_IDX	_sprA03_32
		SPR_IDX	_sprA03_31
		SPR_IDX	_sprA03_32
		SPR_IDX	_sprA03_33
		SPR_IDX	_sprA03_36
		SPR_IDX	_sprA03_35
		SPR_IDX	_sprA03_36
		SPR_IDX	_sprA03_37
		SPR_IDX	_sprA03_3A
		SPR_IDX	_sprA03_39
		SPR_IDX	_sprA03_3A
		SPR_IDX	_sprA03_3B
		SPR_IDX	_sprA03_3E
		SPR_IDX	_sprA03_3D
		SPR_IDX	_sprA03_3E
		SPR_IDX	_sprA03_3F
		SPR_IDX	_sprA03_42
		SPR_IDX	_sprA03_41
		SPR_IDX	_sprA03_42
		SPR_IDX	_sprA03_43
		SPR_IDX	_sprA03_46
		SPR_IDX	_sprA03_45
		SPR_IDX	_sprA03_46
		SPR_IDX	_sprA03_47
		SPR_IDX	_sprA03_4A
		SPR_IDX	_sprA03_49
		SPR_IDX	_sprA03_4A
		SPR_IDX	_sprA03_4B
		SPR_IDX	_sprA03_4E
		SPR_IDX	_sprA03_4D
		SPR_IDX	_sprA03_4E
		SPR_IDX	_sprA03_4F
		SPR_IDX	_sprA03_52
		SPR_IDX	_sprA03_53
		SPR_IDX	_sprA03_52
		SPR_IDX	_sprA03_53
		SPR_IDX	_sprA03_56
		SPR_IDX	_sprA03_57
		SPR_IDX	_sprA03_56
		SPR_IDX	_sprA03_57
		SPR_IDX	_sprA03_5A
		SPR_IDX	_sprA03_5B
		SPR_IDX	_sprA03_5A
		SPR_IDX	_sprA03_5B
		SPR_IDX	_sprA03_5E
		SPR_IDX	_sprA03_5F
		SPR_IDX	_sprA03_5E
		SPR_IDX	_sprA03_5F
		SPR_IDX	_sprA03_62
		SPR_IDX	_sprA03_63
		SPR_IDX	_sprA03_62
		SPR_IDX	_sprA03_63
		SPR_IDX	_sprA03_66
		SPR_IDX	_sprA03_67
		SPR_IDX	_sprA03_66
		SPR_IDX	_sprA03_67
		SPR_IDX	_sprA03_6A
		SPR_IDX	_sprA03_6B
		SPR_IDX	_sprA03_6A
		SPR_IDX	_sprA03_6B
		SPR_IDX	_sprA03_6E
		SPR_IDX	_sprA03_6F
		SPR_IDX	_sprA03_6E
		SPR_IDX	_sprA03_6F
		SPR_IDX	_sprA03_72
		SPR_IDX	_sprA03_73
		SPR_IDX	_sprA03_72
		SPR_IDX	_sprA03_73
		SPR_IDX	_sprA03_76
		SPR_IDX	_sprA03_77
		SPR_IDX	_sprA03_76
		SPR_IDX	_sprA03_77
		SPR_IDX	_sprA03_7A
		SPR_IDX	_sprA03_7B
		SPR_IDX	_sprA03_7A
		SPR_IDX	_sprA03_7B
		SPR_IDX	_sprA03_7E
		SPR_IDX	_sprA03_7F
		SPR_IDX	_sprA03_7E
		SPR_IDX	_sprA03_7F
		SPR_IDX	_sprA03_82
		SPR_IDX	_sprA03_83
		SPR_IDX	_sprA03_82
		SPR_IDX	_sprA03_83
		SPR_IDX	_sprA03_86
		SPR_IDX	_sprA03_87
		SPR_IDX	_sprA03_86
		SPR_IDX	_sprA03_87
		SPR_IDX	_sprA03_8A
		SPR_IDX	_sprA03_8B
		SPR_IDX	_sprA03_8A
		SPR_IDX	_sprA03_8B
		SPR_IDX	_sprA03_8E
		SPR_IDX	_sprA03_8F
		SPR_IDX	_sprA03_8E
		SPR_IDX	_sprA03_8F
		SPR_IDX	_sprA03_92
		SPR_IDX	_sprA03_93
		SPR_IDX	_sprA03_92
		SPR_IDX	_sprA03_93
		SPR_IDX	_sprA03_96
		SPR_IDX	_sprA03_97
		SPR_IDX	_sprA03_96
		SPR_IDX	_sprA03_97
		SPR_IDX	_sprA03_9A
		SPR_IDX	_sprA03_9B
		SPR_IDX	_sprA03_9A
		SPR_IDX	_sprA03_9B
		SPR_IDX	_sprA03_9E
		SPR_IDX	_sprA03_9F
		SPR_IDX	_sprA03_9E
		SPR_IDX	_sprA03_9F
		SPR_IDX	_sprA03_A0	; death	A	U
		SPR_IDX	_sprA03_A1	; 			R
		SPR_IDX	_sprA03_A2	;			D
		SPR_IDX	_sprA03_A3	;			L
		SPR_IDX	_sprA03_A4	; death B	U
		SPR_IDX	_sprA03_A5	;			R
		SPR_IDX	_sprA03_A6	;			D
		SPR_IDX	_sprA03_A7	;			L
		SPR_IDX	_sprA03_A8	; death C	U
		SPR_IDX	_sprA03_A9	;			R
		SPR_IDX	_sprA03_AA	;			D
		SPR_IDX	_sprA03_AB	;			L
		SPR_IDX	_sprA03_AC	; exit arrowU
		SPR_IDX	_sprA03_AD	;			R
		SPR_IDX	_sprA03_AE	; 			D
		SPR_IDX	_sprA03_AF	;			L

		SPR_LIB_SIZE	_spr_libA03

		SPR_LIB_START	_spr_libA04

		SPR_IDX	_sprA04_00
		SPR_IDX	_sprA04_01
		SPR_IDX	_sprA04_02
		SPR_IDX	_sprA04_03
		SPR_IDX	_sprA04_04
		SPR_IDX	_sprA04_05
		SPR_IDX	_sprA04_06
		SPR_IDX	_sprA04_07
		SPR_IDX	_sprA04_08
		SPR_IDX	_sprA04_09
		SPR_IDX	_sprA04_0A
		SPR_IDX	_sprA04_0B
		SPR_IDX	_sprA04_0C
		SPR_IDX	_sprA04_0D
		SPR_IDX	_sprA04_0E
		SPR_IDX	_sprA04_0F
		SPR_IDX	_sprA04_14
		SPR_IDX	_sprA04_11
		SPR_IDX	_sprA04_16
		SPR_IDX	_sprA04_13
		SPR_IDX	_sprA04_14
		SPR_IDX	_sprA04_15
		SPR_IDX	_sprA04_16
		SPR_IDX	_sprA04_17
		SPR_IDX	_sprA04_1C
		SPR_IDX	_sprA04_19
		SPR_IDX	_sprA04_1E
		SPR_IDX	_sprA04_1B
		SPR_IDX	_sprA04_1C
		SPR_IDX	_sprA04_1D
		SPR_IDX	_sprA04_1E
		SPR_IDX	_sprA04_1F
		SPR_IDX	_sprA04_24
		SPR_IDX	_sprA04_21
		SPR_IDX	_sprA04_26
		SPR_IDX	_sprA04_23
		SPR_IDX	_sprA04_24
		SPR_IDX	_sprA04_25
		SPR_IDX	_sprA04_26
		SPR_IDX	_sprA04_27
		SPR_IDX	_sprA04_2C
		SPR_IDX	_sprA04_29
		SPR_IDX	_sprA04_2E
		SPR_IDX	_sprA04_2B
		SPR_IDX	_sprA04_2C
		SPR_IDX	_sprA04_2D
		SPR_IDX	_sprA04_2E
		SPR_IDX	_sprA04_2F

		SPR_LIB_SIZE	_spr_libA04

#if SPR_SIZE_TEST==0
#if NEW_SPRITES==1
		INCLUDE		"../spr/spr_data4_new.inc"
#else
		INCLUDE		"../spr/spr_data4.inc"
#endif
#endif

		SECTION_END	"PRG7 SPRITES"

		LAST_BANK_END 7,$10000

total_banks	= 8
total_size	= 8*16384
