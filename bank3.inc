
		ORG $8000

		BANK_START $03

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr1A_lvl1_boss_judges
		NJSR			_nsub_obj_sarg_add_imm_test		; two instances of the object existed
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_scr_judges_tall

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SPR_IDX_SET		0,$04							; default instance set the "hat" sprite
		NJSR			_nsub_obj_sarg_add_imm_test		; this is an additional branch for using
			NARGB		SARG2,$FF						; this object on LVL5
		SJMP_SW			$01								; only for LVL1 _sloc_2C014 is executed
		SCASE			_scr_judges_intro				; for the rest this branch is skipped

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
_sloc_2C014:
		SDELAY			$01								; special branch for LVL1, wait for
		NJSR			_nsub_mcmp						; scroll of the room reach particular
			NARGW		_ppu_scroll_pos_y				; value
			NARGB		$00
		SBCCS			_sloc_2C014
		STORE8			_cur_room_x_pageB,$00			; force pageB
		NJSR			_nsub_gen_threads_off_except_cur; remove all other object (chairs maybe)
		SJSR			_ssub_boss_music_fade_and_load	; fade out music and start boss theme

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_intro:
		SPR_IDX_SET		4,$04							; finally, start to anim "hat" on the table
		SPR_IDX_INC		4								; (actually i DONT KNOW what is it and how
		SPR_IDX_DEC		4								; they called it)
		SPR_IDX_SET		4,$06
		SPR_IDX_SET		0,$04
		SDELAY			$14
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$06
		SPR_IDX_SET		4,$04
		SPR_IDX_SET		1,$07
		SPR_IDX_INC		5
		SPR_IDX_DEC		4
		SPR_IDX_SET		0,$FF							; hat disappears, this object turns to fat
		NJSR			_nsub_new_thread_start			; judge, the other instance loaded for
			NARGB		_scr1A_lvl1_boss_judges_idx		; tall judge
			NARGB		$38,$40
			NARGB		_scr_judges_tall_idx+1
			NARGB		$00
		POS_X_MOVE		0,$C0							; position of the fat judge x-64, y+64 of the
		POS_Y_MOVE		0,$40							; main object position
		NJSR			_nsub_patch_pal_load			; NOTE: this is a default value for LVL1 palette
			NARGB		$06								; for this object, this is already there, so not
			NARGW		_pal_judges_default_patch		; sure why this palette aplied here...
		SARG_SET		SARG1,$80						; face down

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sct_judges_fat_restart:
		NBG_HNDL_SET	_nbgsub_fat_judge_ctest			; init bg native collision test
		NJSR			_nsub_patch_pal_load			; NOTE: to previous, this is actual palette for
			NARGB		$06								; this enemy
			NARGW		_pal_judges_active_patch
		NJSR			_nsub_spr_dir_select			; set sprite
			NARGB		$09,$40
		SLOOP_BEGIN		$06								; at the beginning stand still animation
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 6,$FC
		SLOOP_END
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; now targeting on beamer

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sct_judges_fat_active:
		NBG_HNDL_SET	_nbgsub_fat_judge_ctest			; not sure why they set the same handler here twice
_sloc_2C06F:
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; set destination
		NJSR			_nsub_spr_dir_select
			NARGB		$09,$40							; refresh sprite idx
		SLOOP_BEGIN		$02
		SDELAY			$06								; start to move animated
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 0,$FC
		SLOOP_END
		NJSR			_nsub_obj_to_beamer_slow_turn	; adjust targeting to beamer
			NARGB		$10
		SJMPS			_sloc_2C06F						; repeat

; =============== S C R I P T ==========================s====================
_sct_judges_fat_stun:
		NBG_HNDL_SET	_nbgsub_judges_fat_catch_test
		SLOOP_BEGIN		$3C
		SJSRS			_ssub_judges_fat_shake_anim
		NJSR			_nsub_wait_for_beam_hold		; unless most of regular enemies
		SBCS_BREAK		_sct_judges_fat_restart			; when beam released, this boss start
		SLOOP_END										; to be active immediately.
		SARG_SET		SARG0,$02						; after 1 sec boss turns red,
		NJSR			_nsub_patch_pal_load			; also catch flag is raized, may
			NARGB		$06								; be catched now as usual
			NARGW		_pal_judges_red_patch
_sloc_2C0A1:
		SJSRS			_ssub_judges_fat_shake_anim		; the rest is the same as regular
		NJSR			_nsub_wait_for_beam_hold		; enemy stun handler
		SBCCS			_sloc_2C0A1
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_sct_judges_fat_restart
		SCASE			_scr_judges_fat_catch_anim_L
		SCASE			_scr_judges_fat_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_judges_fat_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$09,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_judges_fat_catch_anim_L:
		SARG_SET		SARG1,$15
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_judges_fat_catch_anim_R:
		SARG_SET		SARG1,$17
		SJMP			_ssub_common_catch_anim_R_snd19

_pal_judges_default_patch:
		.BYTE	$0F,$31,$25,$0F
_pal_judges_active_patch:
		.BYTE	$0F,$36,$22,$0F
_pal_judges_red_patch:
		.BYTE	$0F,$25,$15,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_fat_judge_ctest:
		LDY		#$00
		LDX		_cur_trd_slot				; there is no room obstacles test,
		LDA		_obj_x_pos_lo,X				; just limit the min-max X range for
		CMP		#$10						; movement
		BCS		loc_2C0E5
		LDA		#$10
		BNE		loc_2C0EB
loc_2C0E5:
		CMP		#$F0
		BCC		loc_2C0F5
		LDA		#$EF
loc_2C0EB:
		STA		_obj_x_pos_lo,X				; when edges reached, bounce in opposite
		INY									; direction on the same vector
		LDA		#$00
		SEC
		SBC		_trds_args1,X
		STA		_trds_args1,X
loc_2C0F5:
		LDA		_obj_y_pos_lo,X				; the same for Y
		CMP		#$10
		BCS		loc_2C0FF
		LDA		#$10
		BNE		loc_2C105
loc_2C0FF:
		CMP		#$E0
		BCC		loc_2C10F
		LDA		#$DF
loc_2C105:
		STA		_obj_y_pos_lo,X
		INY
		LDA		#$80
		SEC
		SBC		_trds_args1,X
		STA		_trds_args1,X
loc_2C10F:
		TYA
		BEQ		loc_2C118					; if direction is changed need to recalc sprites
		JSR		_cur_thread_reload_param	; so reload current current script from beginning
		.WORD	_sct_judges_fat_active
		RTS
loc_2C118:
		LDX		#$0C
		LDY		#$0E
		JSR		_obj_to_beam_ctest
		BCC		loc_2C127
		JSR		_cur_thread_reload_param
		.WORD	_sct_judges_fat_stun
		RTS
loc_2C127:
		LDX		#$0F
		LDY		#$12
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_judges_fat_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2C147
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_2C142
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_fat_catch_anim_L
		RTS
loc_2C142:
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_fat_catch_anim_R
locret_2C147:
		RTS

; =============== S C R I P T ==========================s====================
_scr_judges_tall:
		NBG_HNDL_SET	_nbgsub_judges_tall_ctest		; regular init, set regular
		NJSR			_nsub_patch_pal_load			; palette immediately without any
			NARGB		$07								; redundant calls this time
			NARGW		_pal_judges_active_patch
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$80
		SSCRIPT1_SET	_scr_judges_tall_spr_anim		; automatic boss, set constant anim
		SDELAY			$48
		SJMPS			_scr_judges_tall_activeA

; =============== S C R I P T ==========================s====================
_scr_judges_tall_restart_posA:
		NJSR			_nsub_judges_tall_pos_set		; one of three restart points for tall boss
			NARGB		$B8,$80							; right side of the screen, the same as for
		SARG_SET		SARG1,$80						; appearance point
		SJSR			_ssub_judges_tall_reappear

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_tall_activeA:
		SLOOP_BEGIN		$10								; do half large cirle right till the
		SARG_ALU		SARG1,_ADC,$08					; left side of the screen
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02
		SDELAY			$07
		SLOOP_END
		SJMPS			_scr_judges_tall_activeB

; =============== S C R I P T ==========================s====================
_scr_judges_tall_restart_posB:						; second reappearance point
		NJSR			_nsub_judges_tall_pos_set		; left side of the screen
			NARGB		$2A,$72
		SARG_SET		SARG1,$00
		SJSR			_ssub_judges_tall_reappear

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_tall_activeB:
		SLOOP_BEGIN		$10								; here start a small half circle to the
		SARG_ALU		SARG1,_ADC,$08					; middle, the same start for second reappearance
		NJSR			_nsub_speed_dir_select			; point
			NARGB		$00,$02
		SDELAY			$04
		SLOOP_END
		SJMPS			_scr_judges_tall_activeC

; =============== S C R I P T ==========================s====================
_scr_judges_tall_restart_posC:
		NJSR			_nsub_judges_tall_pos_set		; finally middle of the screen reappearance point
			NARGB		$7B,$7A
		SARG_SET		SARG1,$00
		SJSRS			_ssub_judges_tall_reappear

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_tall_activeC:
		SLOOP_BEGIN		$20								; here is the main loop, two full circles
		SARG_ALU		SARG1,_ADC,$F8					; with start in the middle point, also
		NJSR			_nsub_speed_dir_select			; third reappearance point
			NARGB		$00,$02
		SDELAY			$05
		SLOOP_END
		SLOOP_BEGIN		$20
		SARG_ALU		SARG1,_ADC,$08
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02
		SDELAY			$05
		SLOOP_END
		SJMPS			_scr_judges_tall_activeC

; =============== S C R I P T ==========================s====================
_scr_judges_tall_spr_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$19,$40
		SDELAY			$06
		SPR_IDX_ADD_IMM 6,$04
		SJMPS			_scr_judges_tall_spr_anim

; =============== S C R I P T ==========================s====================
_scr_judges_tall_stun:
		NBG_HNDL_SET	_nbgsub_judges_tall_catch_test	; same as for other boss object
		SLOOP_BEGIN		$3C
		SJSRS			_scr_judges_tall_shake_anim		; beam for a second, then set
		NJSR			_nsub_wait_for_beam_hold		; catch active flag, turn sprite red
		SBCS_BREAK		_sloc_2C1EF						; and continue with regular stun handler
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_judges_red_patch
_sloc_2C1E6:
		SJSRS			_scr_judges_tall_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_2C1E6
_sloc_2C1EF:
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_judges_tall_disappear
		SCASE			_scr_judges_tall_catch_anim_L
		SCASE			_scr_judges_tall_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_judges_tall_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$19,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_judges_tall_disappear:
		SLOOP_BEGIN		$1E								; start to blinking
		NJSR			_nsub_spr_dir_select			; in current sprite state
			NARGB		$19,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SDELAY			$3C								; delay, reload active pal patch
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_judges_active_patch
		SSCRIPT1_SET	_scr_judges_tall_spr_anim		; restart regular animation
		NJSR			_nsub_get_rand_probability		; get random unmber in range 0-2
			NARGB		$03
		SJMP_SW			$03
		SCASE			_scr_judges_tall_restart_posA	; restarting boss from a particular
		SCASE			_scr_judges_tall_restart_posB	; location on its movement trajectory
		SCASE			_scr_judges_tall_restart_posC	; to keep it move on the same area

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_judges_tall_reappear:
		SLOOP_BEGIN		$1E								; blink while reappearing
		SPR_IDX_SET		1,$1B
		SPR_IDX_SET		1,$FF
		SLOOP_END
		NBG_HNDL_SET	_nbgsub_judges_tall_ctest
		SRET

; =============== S C R I P T ==========================s====================
_scr_judges_tall_catch_anim_L:
		SARG_SET		SARG1,$25
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_judges_tall_catch_anim_R:
		SARG_SET		SARG1,$27
		SJMP			_ssub_common_catch_anim_R_snd19

; =============== S U B R O U T I N E ======n================================
_nbgsub_judges_tall_ctest:
		LDX		#$08
		LDY		#$0E
		JSR		_obj_to_beam_ctest
		BCC		loc_2C24E
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_tall_stun
		RTS
loc_2C24E:
		LDX		#$0B
		LDY		#$12
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_judges_tall_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2C26E
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_2C269
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_tall_catch_anim_L
		RTS
loc_2C269:
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_tall_catch_anim_R
locret_2C26E:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_judges_tall_pos_set:
		LDX		_cur_trd_slot				; read hardcoded positions from script
		JSR		_scr_getc
		STA		_obj_x_pos_lo,X
		JSR		_scr_getc
		STA		_obj_y_pos_lo,X
		RTS

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr22_lvl2_boss_train_slime
		NJSR			_nsub_obj_sarg_add_imm_test		; boss slime looking simple, but
			NARGB		SARG0,$FF						; uses 4 different entities
		SJMP_SW			$04
		SCASE			_scr_train_slime_projectileA
		SCASE			_scr_train_slime_projectileB
		SCASE			_scr_train_slime_projectileC
		SCASE			_scr_train_slime_dead

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
_scr_train_slime_active:
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_train_slime_patch
		NBG_HNDL_SET	_nbgsub_train_slime_ctest
		SJSRS			_ssub_train_slime_idle_anim		; idle anim
		SLOOP_BEGIN		$02
		SJSRS			_ssub_train_slime_shot_anim		; two shots in row
		SLOOP_END
		SJSRS			_ssub_train_slime_idle_anim		; idle
		SJSRS			_ssub_train_slime_shot_anim		; one shot
		SJSRS			_ssub_train_slime_idle_anim		; idle
		SLOOP_BEGIN		$03
		SJSRS			_ssub_train_slime_shot_anim		; three shots in row
		SLOOP_END
		SJMPS			_scr_train_slime_active

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_slime_idle_anim:
		SLOOP_BEGIN		$03
		SPR_IDX_SET		0,$29
		SDELAY			$0C
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_slime_shot_anim:
		SPR_IDX_SET		7,$2C							; turn to the player
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		NJSR			_nsub_new_thread_start			; deploy projectile
			NARGB		_scr22_lvl2_boss_train_slime_idx
			NARGB		$00,$F8
			NARGB		_scr_train_slime_projectileA_idx+1
			NARGB		$00
		SPR_IDX_INC		7								; turn back
		SPR_IDX_DEC		3
		SPR_IDX_DEC		3
		SPR_IDX_DEC		3
		SRET

; =============== S C R I P T ==========================s====================
_scr_train_slime_stun:
		NBG_HNDL_SET	_nbgsub_train_slime_catch_test
		SARG_SET		SARG0,$02
		SSCRIPT1_SET	_scr_train_slime_dodge_anim		; slime dodges the beam
_sloc_2C6A2:
		SDELAY			$01								; it is possible to catch only
		NJSR			_nsub_wait_for_beam_hold		; while dodge script starts
		SBCCS			_sloc_2C6A2						; when secondary script finishes
		SSCRIPT1_OFF									; all reloaded to active state
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_train_slime_active
		SCASE			_scr_train_slime_catch_anim_L
		SCASE			_scr_train_slime_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_train_slime_dodge_anim:
		SLOOP_BEGIN		$01								; dodge anim play
		SPR_IDX_SET		1,$29
		SPR_IDX_SET		1,$31
		SLOOP_END
		SPR_IDX_SET		1,$2C
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_DEC		1
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		NJSR			_nsub_thread_off				; custom native thread off
			NARGB		$03								; disables beam completely
		NJSR			_nsub_obj_to_beam_release_test	; then reset corresponding flags.
		SSCRIPT0_OFF									; shut down

; =============== S C R I P T ==========================s====================
_scr_train_slime_catch_anim_L:
		SJSRS			_ssub_train_slime_catch_extra
		SARG_SET		SARG1,$32
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_train_slime_catch_anim_R:
		SJSRS			_ssub_train_slime_catch_extra
		SARG_SET		SARG1,$34
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_slime_catch_extra:
		NJSR			_nsub_new_thread_start			; additional custom init
			NARGB		_scr22_lvl2_boss_train_slime_idx; for dead lvl2 boss
			NARGB		$00,$00							; start a new actor script here
			NARGB		_scr_train_slime_dead_idx+1
			NARGB		$00
		NJSR			_nsub_apu_mus_load				; and do scream sound
			NARGB		$FF
		NJSR			_nsub_apu_snd_load
			NARGB		_snd19_idx
		SRET

_pal_train_slime_patch:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_slime_ctest:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_2C706
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_slime_stun
		RTS
loc_2C706:
		LDX		#$0D
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_slime_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2C72B
		PHA
		JSR		_nsub_gen_threads_off_except_cur
		LDA		#$19
		STA		_scores_obj_value
		PLA
		LSR
		BCS		loc_2C726
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_slime_catch_anim_L
		RTS
loc_2C726:
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_slime_catch_anim_R
locret_2C72B:
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_slime_dead:
		NJSR			_nsub_players_scr_suspend		; when boss dead, there is another
		SDELAY			$5A								; scenery, first players are auto controlled
		NJSR			_nsub_lvl_native_handler_disable; custom routine to disable all bg work of level
		NJSR			_nsub_patch_pal_load
			NARGB		$02
			NARGW		_pal_train_slime_dead_patch
		SDELAY			$50
		NJSR			_nsub_apu_snd_load				; train whistle
			NARGB		_snd13_idx
		SDELAY			$3C
		SLOOP_BEGIN		$3C
		STORE8			_obj_y_pos_hi+2,$05				; now do the scroll trick, set
		STORE8			_obj_y_pos_hi+4,$05				; level scroll to room 0 then 1,
		SCRL_Y_SET		0,$00,$05						; do not forget to adjust player's scrolls
		POS_Y_SET		1,$00,$05						; as well... looks like train
		STORE8			_obj_y_pos_hi+2,$06				; disappears.
		STORE8			_obj_y_pos_hi+4,$06
		SCRL_Y_SET		0,$00,$06
		POS_Y_SET		1,$00,$06
		SLOOP_END
		NJSR			_nsub_stage_complete_force		; now stage is complete.
		SSTOP

_pal_train_slime_dead_patch:
		.BYTE	$0F,$0F,$0F,$07

; =============== S U B R O U T I N E ======n================================
_nsub_lvl_native_handler_disable:
;		LDA		#$00						; REDUNDANT, never used by other code
;		ASL									; with other arguments,
;		TAX									; and $00 here is HARDCODED!
;		LDA		#<[_nbgsub_dummy]
;		STA		_trds_nbgsub_ptr,X
;		LDA		#>[_nbgsub_dummy]
;		STA		_trds_nbgsub_ptr+1,X
		LDA		#<[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr
		LDA		#>[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr+1
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectileA:
		NJSR			_nsub_train_slime_projectile_dir_select
		NJSR			_nsub_new_thread_start			; set random direction up
			NARGB		_scr22_lvl2_boss_train_slime_idx; then deploy two more projectiles
			NARGB		$F8,$00							; to the left and to the right
			NARGB		_scr_train_slime_projectileB_idx+1
			NARGB		$E0
		NJSR			_nsub_new_thread_start
			NARGB		_scr22_lvl2_boss_train_slime_idx
			NARGB		$08,$00
			NARGB		_scr_train_slime_projectileC_idx+1
			NARGB		$20
		SPR_IDX_SET		0,$37

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectile_common:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_train_slime_projectile_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02							; small projectile in the beginning
		SDELAY			$18								; then getting bigger and finally disappear
		SLOOP_BEGIN		$03
		SPR_IDX_SET		1,$39
		SPR_IDX_SET		1,$FF
		SPR_IDX_SET		1,$3A
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_slime_projectile_ctest:
		LDX		#$06
		LDY		#$07
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_train_slime_projectile_dir_select:
		LDA		#$21
		JSR		_rand
		CLC
		ADC		#$F0
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectileB:
		SPR_IDX_SET		0,$36
		SJMPS			_scr_train_slime_projectile_common

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectileC:
		SPR_IDX_SET		0,$38
		SJMPS			_scr_train_slime_projectile_common

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr2E_lvl4_boss_dragons
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$02
		SCASE			_scr_dragons_active
		SCASE			_scr_dragons_flame

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SJSR			_ssub_boss_music_fade_and_load	; boss init here, music, palette
		NJSR			_nsub_patch_pal_load			; and CHR bank
			NARGB		$07
			NARGW		_pal_dragons_patchA
		STORE8			_chr_bank0,$13
		SLOOP_BEGIN		$08								; now will deploy 8 objects
_sloc_2C99C:
		SDELAY			$01
		NJSR			_nsub_dragons_obj_num_test		; if objects count more than 3, then wait
			NARGB		$04								; when you catch some
		SBCSS			_sloc_2C99C
		NJSR			_nsub_new_thread_start			; or else deploy new clone
			NARGB		_scr2E_lvl4_boss_dragons_idx
			NARGB		$00,$00
			NARGB		_scr_dragons_active_idx+1
			NARGB		$00
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_dragons_active:
		NJSR			_nsub_dragons_start_pos_select	; set the appearance position and
		SLOOP_BEGIN		$10								; direction,
		SPR_IDX_SET		1,$3B							; then blink under water phase sprite
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_dragons_restart:
		SARG_SET		SARG0,$00
_sloc_2C9BB:
		SPR_IDX_SET		0,$3B							; retarget at the beginning of the ai loop
		NJSR			_nsub_dragons_direction_update	; by random
		NJSR			_nsub_dragons_obstacle_test		; test if any obstacles in given direction
		SBCCS			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_dragons_obstacle_test		; test all directions before start moving
		SBCCS			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_dragons_obstacle_test
		SBCCS			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_dragons_obstacle_test
		SBCSS			_sloc_2C9BB
_sloc_2C9E4:
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; now set speed
		SDELAY			$10								; and move
		POS_MOVE_STOP	0
		NJSR			_nsub_obj_to_obj_in_range_test	; check for the beamer around
			NARGB		$02,$40
		SBCCS			_sloc_2C9BB						; if no one, continue swimming
		NJSR			_nsub_obj_to_beamer_fast_right_turn
		NJSR			_nsub_apu_snd_load				; or else, target on it,
			NARGB		_snd14_idx						; play popping up sound
		NJSR			_nsub_spr_dir_select			; show up the dragon itself
			NARGB		$3C,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04							; now start active phase, also
		NBG_HNDL_SET	_nbgsub_dragons_ctest			; catchable
		SPR_IDX_ADD_IMM 4,$04							; animate popping up
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$18
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 0,$FC
		NJSR			_nsub_apu_snd_load				; play fire sound
			NARGB		_snd15_idx
		SLOOP_BEGIN		$20
		NJSR			_nsub_new_thread_start			; deploy fire projectile
			NARGB		_scr2E_lvl4_boss_dragons_idx
			NARGB		$00,$00
			NARGB		_scr_dragons_flame_idx+1
			NARGB		$00
		SDELAY			$03								; hide back
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$0C
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		NBG_HNDL_RESET									; disable collision test handler, loop
		SJMPS			_sloc_2C9BB

; =============== S C R I P T ==========================s====================
_scr_dragons_stun:
		NBG_HNDL_SET	_nbgsub_dragons_catch_test		; dragons are gone if beamed for 90 cycles
		SLOOP_BEGIN		$5A								; two frame each = 3 seconds
		SJSRS			_ssub_dragons_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCS_BREAK		_sloc_2CA7E						; wait if beam released and break
		SLOOP_END
		NJSR			_nsub_is_any_enemy_active		; test if this is a last object on the level
		SBCSS			_sloc_2CA66
		NJSR			_nsub_apu_snd_load				; if no, play disappear sound
			NARGB		_snd22_idx
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select			; and do disappear animation
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF							; remove object and stop thread then
		SLOOP_END
		SSTOP
_sloc_2CA66:
		SARG_SET		SARG0,$02						; when last one, turn it read
		NJSR			_nsub_patch_pal_load			; and wait for catch as usual
			NARGB		$07
			NARGW		_pal_dragons_patchB
_sloc_2CA6F:
		SJSRS			_ssub_dragons_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_2CA6F
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_dragons_patchA
_sloc_2CA7E:
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_dragons_retire
		SCASE			_scr_dragons_catch_anim_L
		SCASE			_scr_dragons_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_dragons_retire:
		NBG_HNDL_RESET
		SPR_IDX_ADD_IMM 6,$F4
		SPR_IDX_ADD_IMM 6,$FC
		SJMP			_scr_dragons_restart

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_dragons_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_dragons_catch_anim_L:
		SARG_SET		SARG1,$50
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_dragons_catch_anim_R:
		SARG_SET		SARG1,$52
		SJMP			_ssub_common_catch_anim_R_snd19

_pal_dragons_patchA:
		.BYTE	$0F,$25,$16,$0F
_pal_dragons_patchB:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragons_ctest:
		LDX		#$10
		LDY		#$10
		JSR		_obj_to_beam_ctest
		BCC		loc_2CABE
		JSR		_cur_thread_reload_param
		.WORD	_scr_dragons_stun
		RTS
loc_2CABE:
		LDX		#$15
		LDY		#$16
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragons_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2CADE
		LSR
		LDA		#$1E
		STA		_scores_obj_value
		BCS		loc_2CAD9
		JSR		_cur_thread_reload_param
		.WORD	_scr_dragons_catch_anim_L
		RTS
loc_2CAD9:
		JSR		_cur_thread_reload_param
		.WORD	_scr_dragons_catch_anim_R
locret_2CADE:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_obj_num_test:
		JSR		_scr_getc
		STA		_tmp0
		LDY		#$00
		LDX		#$06
loc_2CAE8:
		LDA		_trds_obj_idx,X
		BMI		loc_2CAEE
		INY
loc_2CAEE:
		INX
		CPX		#$0D
		BCC		loc_2CAE8
		CPY		_tmp0
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_obstacle_test:
		LDY		_cur_trd_slot				; since there are no actual obstacles
		LDA		_trds_args1,Y				; this test only preventing the
		ASL									; objects to get close to the screen
		ROL									; edges
		ROL
		TAX
		LDA		_obj_x_pos_lo,Y
		CMP		byte_2CB13,X
		BEQ		loc_2CB11
		LDA		_obj_y_pos_lo,Y
		CMP		byte_2CB17,X
		BEQ		loc_2CB11
		CLC
		RTS
loc_2CB11:
		SEC
		RTS

byte_2CB13:
		.BYTE	$FF,$D0,$FF,$30
byte_2CB17:
		.BYTE	$30,$FF,$A0,$FF

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_start_pos_select:
		LDA		#$0B						; select two random numbers
		JSR		_rand						; $03-$0E and
		PHA									; $03-$0A
		LDA		#$08
		JSR		_rand
		CLC
		ADC		#$03						; this selecting one of the floor
		ASL									; cells
		ASL
		ASL
		ASL
		LDX		_cur_trd_slot
		STA		_obj_y_pos_lo,X
		LDA		#$00
		STA		_obj_y_pos_hi,X
		PLA
		CLC
		ADC		#$03
		ASL
		ASL
		ASL
		ASL
		STA		_obj_x_pos_lo,X				; set current location of the object
		LDA		#$03
		STA		_obj_x_pos_hi,X
		LDA		#$00
		JSR		_rand
		AND		#$C0
		STA		_trds_args1,X				; then select movement direction
		RTS									; also randomly

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_direction_update:
		LDA		#$00						; moving randomly under water
		JSR		_rand
		LSR
		BCC		locret_2CB5E
		ASL
		AND		#$C0
		LDX		_cur_trd_slot
		STA		_trds_args1,X
locret_2CB5E:
		RTS

; =============== S C R I P T ==========================s====================
_scr_dragons_flame:
		SARG_SET		SARG0,$00
		NJSR			_nsub_sarg1_direction_extract	; four kinds of flame sprites
		SJMP_SW			$04								; for every direction
		SCASE			_scr_dragons_flame_U
		SCASE			_scr_dragons_flame_R
		SCASE			_scr_dragons_flame_D
		SCASE			_scr_dragons_flame_L

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_U:
		POS_Y_MOVE		0,$CD
		SJMPS			_scr_dragons_flame_vert

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_D:
		POS_Y_MOVE		0,$22

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_vert:
		NBG_HNDL_SET	_nbgsub_dragon_flame_vert_ctest
		SPR_IDX_SET		1,$54
		SPR_IDX_INC		2
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_R:
		POS_X_MOVE		0,$2F
		POS_Y_MOVE		0,$04
		NBG_HNDL_SET	_nbgsub_dragon_flame_hor_ctest
		SPR_IDX_SET		1,$58
		SPR_IDX_INC		2
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_L:
		POS_X_MOVE		0,$D1
		POS_Y_MOVE		0,$04
		NBG_HNDL_SET	_nbgsub_dragon_flame_hor_ctest
		SPR_IDX_SET		1,$56
		SPR_IDX_INC		2
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragon_flame_vert_ctest:
		LDX		#$09
		LDY		#$24
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragon_flame_hor_ctest:
		LDX		#$23
		LDY		#$0A
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr2F_lvl5_boss_keykeeper
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_scr_boss_keykeeperA
		SCASE			_scr_boss_keykeeperB
		SCASE			_scr_keykeeper_death
		SCASE			_scr_keykeeper_projectile

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SJSR			_ssub_boss_music_fade_and_load
		NJSR			_nsub_keykeeper_init			; init internal extra vars here
		NJSR			_nsub_spr_pal_load				; the rest is usual
			NARGW		_pal_spr_boss_keykeeper
		STORE8			_chr_bank0,$18
		SARG_SET		SARG1,$40
		NJSR			_nsub_new_thread_start			; deploy another boss instance
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_boss_keykeeperA_idx+1
			NARGB		$00								; store its thread idx to the custom array
		NJSR			_nsub_keykeeper_thread_idx_register
		SSCRIPT1_SET	_scr_keykeeper_appear_blink		; wait until second instance stopped
		SDELAY			$28								; this thread will wait until second instance walk
		SDELAY			$B4								; then two more instances finish to work


; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_main:
		NJSR			_nsub_is_boss_three_obj_left_test	; if 3 or more objects to deploy left,
		SBCCS			_sloc_2CF51						; keep deploying boss instances
		NJSR			_nsub_keykeeper_active_obj_threads_reload	; as the main object deploying entities
			NARGW		_scr_keykeeper_moveA_blink		; set all objects the same short move script
		SSCRIPT1_SET	_scr_keykeeper_appear_blink		; with no collision test handler
		SDELAY			$28								; wait for they move
		NJSR			_keykeeper_clone_to_near_thread_slot
		NJSR			_nsub_new_thread_start			; start another instance
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_boss_keykeeperB_idx+1
			NARGB		$00
		NJSR			_nsub_keykeeper_thread_idx_register
		SDELAY			$B4								; still keep walking
_sloc_2CF51:
		NJSR			_nsub_keykeeper_active_obj_threads_reload
			NARGW		_scr_keykeeper_move_solid		; when all three instances deployed, set to all
		SDELAY			$28								; objects collision testable script and walk around
		SSCRIPT1_OFF									; for one cycle, then stop and reload regular palette
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_spr_boss_keykeeper+$0C

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sub_keykeeper_active:
		SDELAY			$01
		NJSR			_nsub_keykeeper_get_beamed_status
		SJMP_SW			$02
		SCASE			_sub_keykeeper_active
		SCASE			_sub_keykeeper_reinit

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_keykeeper_pos_lock		; lock all current positions for all objects
		NJSR			_nsub_keykeeper_active_obj_threads_reload
			NARGW		_scr_keykeeper_fire				; set firing state for all except beamed one

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_stop:
		SDELAY			$01								; test if beamer is lost its target
		NJSR			_nsub_mcmp
			NARGW		_keykeeper_beam_flag
			NARGB		$00
		SBCCS			_scr_keykeeper_shake			; of no, keep shaking
		NJSR			_nsub_keykeeper_pos_unlock		; or turn targeting bosses to normal

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sub_keykeeper_reinit:
		NJSR			_nsub_keykeeper_active_obj_threads_reload
			NARGW		_scr_keykeeper_move_solid
		SJMPS			_sub_keykeeper_active

; =============== S C R I P T ==========================s====================
_scr_keykeeper_shake:
		NJSR			_nsub_mcmp						; here we test if object catched
			NARGW		_keykeeper_beam_flag			; _keykeeper_beam_flag == $02
			NARGB		$02
		SBCCS			_scr_keykeeper_stop
		NJSR			_nsub_keykeeper_pos_unlock		; when catched, decrement boss counter
		SMEM_ALU		_keykeeper_counter,_ADC,$FF
		NJSR			_nsub_is_boss_last_obj_left_test; test if there are few
		SBCCS			_scr_keykeeper_main				; restart base script then or stop cur entity
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_keykeeper_appear_blink:
		NJSR			_nsub_patch_pal_load			; black blinking while
			NARGB		$07								; appear and move
			NARGW		_pal_keykeeper_patch
		SDELAY			$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_spr_boss_keykeeper+$0C
		SDELAY			$02
		SJMPS			_scr_keykeeper_appear_blink

; =============== S C R I P T ==========================s====================
_scr_boss_keykeeperA:
		SARG_SET		SARG0,$00
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$28
		NJSR			_nsub_new_thread_start
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_boss_keykeeperB_idx+1
			NARGB		$00
		NJSR			_nsub_keykeeper_thread_idx_register
		SJMPS			_scr_keykeeper_move_common

; =============== S C R I P T ==========================s====================
_scr_boss_keykeeperB:
		SARG_SET		SARG0,$00
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$B4

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_moveA_blink:
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$28
		SJMPS			_scr_keykeeper_move_common

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_solid:
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$28
		NBG_HNDL_SET	_nbgsub_keykeeper_ctest

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_common:
		NJSR			_nsub_sarg1_direction_extract	; constantly moving around the
		SJSR_SW	$04										; corner, when reach corresponding limit
		SCASE			_scr_keykeeper_move_U			; turn to the next corner
		SCASE			_scr_keykeeper_move_R			; never stop
		SCASE			_scr_keykeeper_move_D
		SCASE			_scr_keykeeper_move_L
		POS_MOVE_STOP	0
		SARG_ALU		SARG1,_ADC,$40
		SJMPS			_scr_keykeeper_move_common

; =============== S C R I P T ==========================s====================
_scr_keykeeper_fire:
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; keep firing state unless
		SDELAY			$01								; beamed object lost or catched
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		NJSR			_nsub_keykeeper_spr_reverse
		SDELAY			$01
		NJSR			_nsub_new_thread_start			; deploy projectile
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_keykeeper_projectile_idx+1
			NARGB		$00
		SDELAY			$3C
		SJMPS			_scr_keykeeper_fire				; loop unless beamed object change state

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_R:
		SSCRIPT1_SET	_scr_keykeeper_move_R_anim
_sloc_2D022:
		NJSR			_nsub_keykeeper_R_limit_test	; test for reaching the limit
			NARGB		$C8
		SBCSS			_sloc_2D02E						; then exit to retarget
		SDELAY			$01								; else keep going
		SJMPS			_sloc_2D022
_sloc_2D02E:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_R_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5B
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$5F
		SDELAY			$08
		POS_X_DELTA_SET 0,$80,$00
		SPR_IDX_SET		0,$63
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$5F
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_R_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_L:
		SSCRIPT1_SET	_scr_keykeeper_move_L_anim
_sloc_2D050:
		NJSR			_nsub_keykeeper_L_limit_test
			NARGB		$30
		SBCSS			_sloc_2D05C
		SDELAY			$01
		SJMPS			_sloc_2D050
_sloc_2D05C:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_L_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5D
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$61
		SDELAY			$08
		POS_X_DELTA_SET 0,$80,$FF
		SPR_IDX_SET		0,$65
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$61
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_L_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_U:
		SSCRIPT1_SET	_scr_keykeeper_move_U_anim
_sloc_2D07E:
		NJSR			_nsub_keykeeper_U_limit_test
			NARGB		$40
		SBCSS			_sloc_2D08A
		SDELAY			$01
		SJMPS			_sloc_2D07E
_sloc_2D08A:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_U_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5A
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$5E
		SDELAY			$08
		POS_Y_DELTA_SET 0,$80,$FF
		SPR_IDX_SET		0,$62
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$5E
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_U_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_D:
		SSCRIPT1_SET	_scr_keykeeper_move_D_anim
_sloc_2D0AC:
		NJSR			_nsub_keykeeper_D_limit_test
			NARGB		$A8
		SBCSS			_sloc_2D0B8
		SDELAY			$01
		SJMPS			_sloc_2D0AC
_sloc_2D0B8:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_D_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5C
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$60
		SDELAY			$08
		POS_Y_DELTA_SET 0,$80,$00
		SPR_IDX_SET		0,$64
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$60
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_D_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_stun:
		NBG_HNDL_SET	_nbgsub_keykeeper_catch_test	; also two-part handler
		NJSR			_nsub_spr_dir_select			; first part waiting for beaming time
			NARGB		$5A,$40
		SLOOP_BEGIN		$5A
		SPR_IDX_ADD_IMM 1,$0C
		SPR_IDX_ADD_IMM 1,$F4
		NJSR			_nsub_wait_for_beam_hold
		SBCS_BREAK		_sloc_2D112
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_is_boss_one_obj_left_test	; also additional test if there is a last
		SBCSS			_sloc_2D103						; object
		SPR_IDX_ADD_IMM 0,$10							; set new sprite with red palette set
_sloc_2D0F6:
		SPR_IDX_ADD_IMM 1,$04							; because all objects uses the same pal
		SPR_IDX_ADD_IMM 1,$FC							; we just can't use the same pal trick as
		NJSR			_nsub_wait_for_beam_hold		; for lvl1 boss for exmple...
		SBCCS			_sloc_2D0F6
		SJMPS			_sloc_2D112
_sloc_2D103:
		NJSR			_nsub_spr_dir_select			; start to disappear and baby appear
			NARGB		$5A,$40
		SDELAY			$01
		SPR_IDX_SET		1,$76
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_2D103
_sloc_2D112:
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_keykeeper_lost
		SCASE			_scr_keykeeper_catch_anim_L
		SCASE			_scr_keykeeper_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_keykeeper_lost:
		STORE8			_keykeeper_beam_flag,$00		; reset flag, the rest is up to other part of script
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_keykeeper_catch_anim_L:
		NJSR			_nsub_keykeeper_thread_idx_remove	; remove it from local tmp list
		NJSR			_nsub_is_boss_one_obj_left_test	; test if there is not the last boss
		SBCCS			_sloc_2D133						; if yes, deploy death anim
		NJSR			_nsub_new_thread_start
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$18
			NARGB		_scr_keykeeper_death_idx+1
			NARGB		$00
_sloc_2D133:
		SARG_SET		SARG1,$72						; or just play catch anim with sound
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_keykeeper_catch_anim_R:
		NJSR			_nsub_keykeeper_thread_idx_remove
		NJSR			_nsub_is_boss_one_obj_left_test
		SBCCS			_sloc_2D14A
		NJSR			_nsub_new_thread_start
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$18
			NARGB		_scr_keykeeper_death_idx+1
			NARGB		$00
_sloc_2D14A:
		SARG_SET		SARG1,$74
		SJMP			_ssub_common_catch_anim_R_snd19

_pal_spr_boss_keykeeper:
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$25,$15,$0F,$0F,$36,$1B,$0F
_pal_keykeeper_patch:
		.BYTE	$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_keykeeper_ctest:
		LDX		#$10
		LDY		#$16
		JSR		_obj_to_beam_ctest
		BCC		loc_2D178
		LDA		#$01
		STA		_keykeeper_beam_flag
		JSR		_cur_thread_reload_param
		.WORD	_scr_keykeeper_stun
		RTS
loc_2D178:
		LDX		#$0F
		LDY		#$18
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_keykeeper_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2D198
		LSR
		LDA		#$0F
		STA		_scores_obj_value
		BCS		loc_2D193
		JSR		_cur_thread_reload_param
		.WORD	_scr_keykeeper_catch_anim_L
		RTS
loc_2D193:
		JSR		_cur_thread_reload_param
		.WORD	_scr_keykeeper_catch_anim_R
locret_2D198:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_boss_three_obj_left_test:
		LDA		_keykeeper_counter
		CMP		#$03
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_boss_last_obj_left_test:
		LDA		_keykeeper_counter
		BNE		loc_2D1A6
		SEC
		RTS
loc_2D1A6:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_boss_one_obj_left_test:
		LDA		_keykeeper_counter
		CMP		#$01
		BEQ		locret_2D1B0
		CLC
locret_2D1B0:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_spr_reverse:
		LDX		_cur_trd_slot
		LDY		_obj_spr_idx,X
		LDA		byte_2D1BB-$5A,Y
		STA		_obj_spr_idx,X
		RTS
byte_2D1BB:
		.BYTE	$5D,$5A,$5B,$5C

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_active_obj_threads_reload:
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		STA		_tmp2
		LDY		#$02
loc_2D1CB:
		TYA
		PHA
		LDX		_boss_tmp_list,Y
		BMI		loc_2D1EC
		LDA		_trds_obj_idx,X
		BMI		loc_2D1EC
		LDA		_trds_args0,X
		BNE		loc_2D1EC
		LDA		_tmp2
		PHA
		LDA		_tmp0
		PHA
		LDY		_tmp2
		JSR		_thread_load
		PLA
		STA		_tmp0
		PLA
		STA		_tmp2
loc_2D1EC:
		PLA
		TAY
		DEY
		BPL		loc_2D1CB
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_get_beamed_status:
		LDA		_keykeeper_beam_flag		; return $00 if no beamed at all
		BEQ		locret_2D214
		LDY		#$02
loc_2D1F9:
		LDX		_boss_tmp_list,Y			; look for currently beamed
		BMI		loc_2D207					; return $02 if any
		LDA		_trds_obj_idx,X
		BMI		loc_2D207
		LDA		_trds_args0,X
		BNE		loc_2D212
loc_2D207:
		DEY
		BPL		loc_2D1F9
		LDA		#$00						; if beamed flag set but no beamed
		STA		_keykeeper_beam_flag		; objects left, reset beamed flag,
		LDA		#$01						; return $01
		RTS
loc_2D212:
		LDA		#$02
locret_2D214:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_pos_lock:
		LDY		#$02
loc_2D217:
		LDX		_boss_tmp_list,Y
		BMI		loc_2D225
		LDA		_trds_obj_idx,X
		BMI		loc_2D225
		LDA		_trds_args1,X
		STA		_trds_args2,X
loc_2D225:
		DEY
		BPL		loc_2D217
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_pos_unlock:
		LDY		#$02
loc_2D22B:
		LDX		_boss_tmp_list,Y
		BMI		loc_2D239
		LDA		_trds_obj_idx,X
		BMI		loc_2D239
		LDA		_trds_args2,X
		STA		_trds_args1,X
loc_2D239:
		DEY
		BPL		loc_2D22B
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_thread_idx_remove:
		LDY		#$02
loc_2D23F:
		LDA		_boss_tmp_list,Y
		CMP		_cur_trd_slot
		BEQ		loc_2D24C
		DEY
		BPL		loc_2D23F
loc_2D249:
		JMP		loc_2D249					; original DEBUG assert here
loc_2D24C:
		LDA		#$FF
		STA		_boss_tmp_list,Y
		LDA		#$02
		STA		_keykeeper_beam_flag
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_thread_idx_register:
		LDX		#$00
loc_2D259:
		LDA		_boss_tmp_list,X
		BMI		loc_2D266
		INX
		CPX		#$03
		BCC		loc_2D259
loc_2D263:
		JMP		loc_2D263					; original DEBUG assert here also
loc_2D266:
		LDA		_nsub_return_value
		STA		_boss_tmp_list,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_init:
		LDA		#$FF
		STA		_boss_tmp_list
		STA		_boss_tmp_list+1
		STA		_boss_tmp_list+2
		LDA		#$00
		STA		_keykeeper_beam_flag
		LDA		#$0A
		STA		_keykeeper_counter
		RTS

; =============== S U B R O U T I N E ======n================================
_keykeeper_clone_to_near_thread_slot:
		JSR		_keykeeper_get_near_thread_idx_slot
		TAY
		LDX		_boss_tmp_list,Y
		LDY		_cur_trd_slot
		LDA		_obj_x_pos_lo,X
		STA		_obj_x_pos_lo,Y
		LDA		_obj_x_pos_hi,X
		STA		_obj_x_pos_hi,Y
		LDA		_obj_y_pos_lo,X
		STA		_obj_y_pos_lo,Y
		LDA		_obj_y_pos_hi,X
		STA		_obj_y_pos_hi,Y
		LDA		_trds_args1,X
		STA		_trds_args1,Y
		RTS

; =============== S U B R O U T I N E ======n================================
_keykeeper_get_near_thread_idx_slot:
		LDY		#$02
loc_2D2A9:
		LDA		_boss_tmp_list,Y
		BMI		loc_2D2B4
		DEY
		BPL		loc_2D2A9
loc_2D2B1:
		JMP		loc_2D2B1					; original DEBUG assert here also
loc_2D2B4:
		LDA		byte_2D2B8,Y
		RTS
byte_2D2B8:
		.BYTE	$02,$00,$01

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_R_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_x_pos_lo,X
		BEQ		loc_2D2C8
		BCS		loc_2D2CA
		STA		_obj_x_pos_lo,X
loc_2D2C8:
		SEC
		RTS
loc_2D2CA:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_L_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_x_pos_lo,X
		BCC		locret_2D2D7
		STA		_obj_x_pos_lo,X
locret_2D2D7:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_U_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_y_pos_lo,X
		BCC		locret_2D2E3
		STA		_obj_y_pos_lo,X
locret_2D2E3:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_D_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_y_pos_lo,X
		BEQ		loc_2D2F1
		BCS		loc_2D2F3
		STA		_obj_y_pos_lo,X
loc_2D2F1:
		SEC
		RTS
loc_2D2F3:
		CLC
		RTS

; =============== S C R I P T ==========================s====================
_scr_keykeeper_death:
		SARG_SET		SARG0,$00						; remove main boss object
		SPR_IDX_SET		0,$76							; set baby keykeeper sprite
		SDELAY			$20
		POS_Y_DELTA_SET 4,$00,$02						; animate it
		POS_MOVE_STOP	0
		SPR_IDX_SET		4,$78
		SPR_IDX_INC		4
		SPR_IDX_SET		0,$76							; set stage complete script
		SDELAY			$3C
		NJSR			_nsub_stage_complete_force
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_keykeeper_projectile:
		SARG_SET		SARG0,$00
		NJSR			_nsub_keykeeper_projectile_init	; init starting pos and direction
		SLOOP_BEGIN		$03
		SPR_IDX_SET		2,$FF							; start to animate it first around
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; head
			NARGB		SARG2
		SDELAY			$02
		SLOOP_END										; then start to move in targets direction
		NJSR			_nsub_apu_snd_load
			NARGB		_snd0F_idx
		NBG_HNDL_SET	_nbgsub_keykeeper_projectile_ctest	; deadly projectile collision test
		NJSR			_nsub_spr_dir_select			; reinit sprite
			NARGB		$7C,$20
		NJSR			_nsub_speed_dir_select			; keep going, script is done here
			NARGB		$00,$03
		SUSPEND

; =============== S U B R O U T I N E ======n================================
_nbgsub_keykeeper_projectile_ctest:
		LDX		#$09
		LDY		#$0A
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_projectile_init:
		LDY		_cur_trd_slot
		LDA		_trds_args1,Y
		CLC
		ADC		#$20
		AND		#$C0
		ASL
		ROL
		ROL
		TAX
		LDA		_obj_x_pos_lo,Y
		CLC
		ADC		byte_2D886,X
		STA		_obj_x_pos_lo,Y
		LDA		_obj_x_pos_hi,Y
		ADC		byte_2D88A,X
		STA		_obj_x_pos_hi,Y
		LDA		_obj_y_pos_lo,Y
		CLC
		ADC		byte_2D88E,X
		STA		_obj_y_pos_lo,Y
		LDA		_obj_y_pos_hi,Y
		ADC		byte_2D892,X
		STA		_obj_y_pos_hi,Y
		TXA
		AND		#$01
		CLC
		ADC		#$7A
		STA		_trds_args2,Y
		RTS
byte_2D886:
		.BYTE	$00,$05,$00,$FB
byte_2D88A:
		.BYTE	$00,$00,$00,$FF
byte_2D88E:
		.BYTE	$E8,$FE,$FD,$FE
byte_2D892:
		.BYTE	$FF,$FF,$FF,$FF

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr30_lvl6_boss_vega
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_scr_vega_projectileA
		SCASE			_scr_vega_fireball
		SCASE			_scr_vega_projectileB
		SCASE			_scr_vega_mother

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SLOOP_BEGIN		$C8								; default initialization
		SMEM_ALU		_apu_mus_volume,_ADC,$FF		; slowly lower the music volume
		SDELAY			$02								; in about 6 seconds
		SLOOP_END
		NJSR			_nsub_apu_snd_load				; start laughing sound effect
			NARGB		_snd0E_idx
		SDELAY			$64
		STORE8			_apu_mus_volume,$FF				; restore music volume and play
		NJSR			_nsub_apu_mus_load				; custom boss music
			NARGB		_musB_idx
		SPR_IDX_SET		0,$C0							; display sprite (hidden)
		SLOOP_BEGIN		$04								; slowly reveal through the
		NJSR			_nsub_pal_fade_req_inc_by_mask	; palette fade in effect
			NARGB		$22
		SDELAY			$06
		SLOOP_END
		STORE16			_boss_tmp_list,$800				; set HP for this boss
		NBG_HNDL_SET	_nbgsub_vega_ctest				; set bg damage detection routine
		SSCRIPT1_SET	_scr_vega_blinker				; start damage blinker secondary script
		SDELAY			$B4								; now wait for a while
		POS_Y_DELTA_SET 0,$80,$00						; and move forth from the painting
		SDELAY			$60
		POS_MOVE_STOP	0								; stop, get to the main loop
_sloc_2D90E:
		SPR_IDX_SET		0,$C0							; delay before attack
		SDELAY			$62
		SARG_SET		SARG1,$00						; reset attack tmp var
		NJSR			_nsub_new_thread_start			; start to attack
			NARGB		_scr30_lvl6_boss_vega_idx		; deploy four projectiles
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$20
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$60
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$A0
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$E0
		SDELAY			$2E								; animate vega controlling projectiles
		SLOOP_BEGIN		$04
		SPR_IDX_SET		0,$C1
		SDELAY			$0C
		SLOOP_BEGIN		$03
		SPR_IDX_INC		0
		SDELAY			$0C
		SLOOP_END
		SLOOP_END
		SPR_IDX_DEC		0
		SDELAY			$0C
		NJSR			_nsub_new_thread_start			; all fireballs shrinked to one single
			NARGB		_scr30_lvl6_boss_vega_idx		; pulsating ball
			NARGB		$00,$00
			NARGB		_scr_vega_fireball_idx+1
			NARGB		$00
		SDELAY			$20								; some more hands shaking
		SPR_IDX_SET		0,$C0
		SDELAY			$10
		SPR_IDX_SET		0,$C5
		SDELAY			$08
		NJSR			_nsub_vega_shot_targeting		; random targering to fire
		NJSR			_nsub_new_thread_start			; deploy three fire balls
			NARGB		_scr30_lvl6_boss_vega_idx		; from one hand
			NARGB		$10,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$4C
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$6C
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$8C
		SDELAY			$10								; then the same from another hand
		SPR_IDX_INC		0
		SDELAY			$08
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$74
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$94
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$B4
		SDELAY			$10
		SJMP			_sloc_2D90E						; repeat boss pattern

; =============== S C R I P T ==========================s====================
_scr_vega_blinker:
		SDELAY			$01
		NJSR			_nsub_obj_sarg_add_imm_test		; wait when need to blink
			NARGB		SARG0,$00
		SJMP_SW			$01
		SCASE			_scr_vega_blinker				; and blink!

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_vega_blink_patch
		SDELAY			$01
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_vega_normal_patch
		SDELAY			$01
		SJMPS			_scr_vega_blinker

_pal_vega_normal_patch:
		.BYTE	$0F,$36,$17,$0F
_pal_vega_blink_patch:
		.BYTE	$0F,$20,$20,$20

; =============== S C R I P T ==========================s====================
_scr_vega_death:
		NJSR			_nsub_gen_threads_off_except_cur; start final boss death cutscene
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_vega_normal_patch
		SPR_IDX_SET		0,$C1							; stop animating
		SDELAY			$40
		SPR_IDX_SET		0,$C7
		SDELAY			$10								; start scream sound
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		NJSR			_nsub_apu_snd_load
			NARGB		_snd1A_idx
		POS_Y_DELTA_SET 0,$00,$FC						; now dodging back to painting
		SPR_IDX_SET		4,$84
		SPR_IDX_INC		4
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_INC		4
		POS_Y_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		4
		POS_MOVE_STOP	0
		SPR_IDX_INC		4
		SPR_IDX_SET		0,$FF
		SDELAY			$5A								; final scene starts, auto play script
		NJSR			_nsub_lvl6_players_auto_scriptsB_set	; for players
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$98,$00						; show blinking baby
		SPR_IDX_SET		1,$91
		SPR_IDX_SET		2,$FF
		SPR_IDX_SET		3,$91
		SPR_IDX_SET		4,$FF
		SPR_IDX_SET		5,$91
		SPR_IDX_SET		6,$FF
		SPR_IDX_SET		7,$91
		SPR_IDX_SET		0,$FF
		SDELAY			$08
		SPR_IDX_SET		0,$91
		SDELAY			$09
		SPR_IDX_SET		0,$FF
		SDELAY			$0A
		SPR_IDX_SET		0,$91
		SDELAY			$0B
		SPR_IDX_SET		0,$FF
		SDELAY			$0C
		SPR_IDX_SET		0,$91
		SDELAY			$0D
		SPR_IDX_SET		0,$FF
		SDELAY			$0E
		SPR_IDX_SET		0,$91
		SDELAY			$96
		NJSR			_nsub_new_thread_start			; deploy mother script, walk to baby
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$58
			NARGB		_scr_vega_mother_idx+1
			NARGB		$00
		SDELAY			$40
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask	; fade out
			NARGB		$FF
		SDELAY			$08
		SLOOP_END
		STORE8			_game_flags,$80					; no sclear screen here, just silently exit
		NJSR			_nsub_all_threads_off_except_cur; script with complere stage flag
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_vega_ctest:
		LDX		#$15
		LDY		#$26
		JSR		_obj_to_player_ctest
		LDX		#$10
		LDY		#$18
		JSR		_obj_to_beam_ctest			; this is not regular ctest for beam
		LDX		_cur_trd_slot				; we don't have stun or beamed scripts for vega
		LDA		_trds_args0,X				; it is only an amount of beam damage
		BEQ		locret_2DA6F				; that counts
		LDA		_boss_tmp_list
		SEC
		SBC		#$01
		STA		_boss_tmp_list
		LDA		_boss_tmp_list+1
		SBC		#$00
		STA		_boss_tmp_list+1
		ORA		_boss_tmp_list				; beam it until death, thats all
		BNE		locret_2DA6F
		JSR		_cur_thread_reload_param
		.WORD	_scr_vega_death
		LDA		#$C8
		JSR		_scores_add
locret_2DA6F:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_vega_shot_targeting:
		LDA		#$21
		JSR		_rand
		SEC
		SBC		#$10
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_lvl6_players_auto_scriptsB_set:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl6_beamer_auto_scriptB
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl6_catcher_auto_scriptB
		RTS

; =============== S C R I P T ==========================s====================
_scr_vega_projectileA:
		SARG_SET		SARG0,$00						; this projectile moves in circles
		SSCRIPT1_SET	_scr_vega_projectileA_anim		; around vega
		NBG_HNDL_SET	_nbgsub_vega_projectileA_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$04
		SDELAY			$10
		POS_MOVE_STOP	0
		SDELAY			$4E
		SARG_ALU		SARG1,_ADC,$40
		SLOOP_BEGIN		$80
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$06
		SDELAY			$01
		SARG_ALU		SARG1,_ADC,$04
		SLOOP_END
		SARG_SET		SARG2,$04
		SLOOP_BEGIN		$07
		SLOOP_BEGIN		$04
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$06
		SDELAY			$01
		NJSR			_nsub_vega_projectileA_shrink
		SLOOP_END
		SARG_ALU		SARG2,_ADC,$01					; final shrinking
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_vega_projectileA_anim:
		SPR_IDX_SET		1,$8B
		SPR_IDX_INC		1
		SJMPS			_scr_vega_projectileA_anim

; =============== S U B R O U T I N E ======n================================
_nbgsub_vega_projectileA_ctest:
		LDX		#$08
		LDY		#$09
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_vega_projectileA_shrink:
		LDX		_cur_trd_slot
		LDA		_trds_args1,X
		CLC
		ADC		_trds_args2,X
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr_vega_fireball:
		SARG_SET		SARG0,$00
		SPR_IDX_SET		0,$8A
		SLOOP_BEGIN		$03
		SLOOP_BEGIN		$03
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$02
		SLOOP_END
		SLOOP_BEGIN		$07
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_vega_projectileB:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_vega_projectileB_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$03
		SPR_IDX_SET		0,$8A
		SLOOP_BEGIN		$03
		SLOOP_BEGIN		$02
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$02
		SLOOP_END
_sloc_2DF73:
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SJMPS			_sloc_2DF73

; =============== S U B R O U T I N E ======n================================
_nbgsub_vega_projectileB_ctest:
		LDX		#$08
		LDY		#$09
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S C R I P T ==========================s====================
_scr_vega_mother:
		POS_Y_DELTA_SET 0,$00,$FF
		SLOOP_BEGIN		$04
		SPR_IDX_SET		4,$92
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SLOOP_END
		POS_MOVE_STOP	0
		SUSPEND

		SECTION_END	"OBJECT SCRIPTS B (BOSSES)"

		SECTION_START

_spr_libA1A:
		.WORD	_sprA1A_00	; catch, uses copies in CHR1 for every level
		.WORD	_sprA1A_01
		.WORD	_sprA1A_02
		.WORD	_sprA1A_03
		.WORD	_sprA1A_04	; lvl1 boss judges (CHR0 07, CHR1 none)
		.WORD	_sprA1A_05
		.WORD	_sprA1A_06
		.WORD	_sprA1A_07
		.WORD	_sprA1A_08
		.WORD	_sprA1A_09
		.WORD	_sprA1A_0A
		.WORD	_sprA1A_0B
		.WORD	_sprA1A_0C
		.WORD	_sprA1A_0D
		.WORD	_sprA1A_0E
		.WORD	_sprA1A_0F
		.WORD	_sprA1A_10
		.WORD	_sprA1A_11
		.WORD	_sprA1A_12
		.WORD	_sprA1A_13
		.WORD	_sprA1A_14
		.WORD	_sprA1A_15
		.WORD	_sprA1A_16
		.WORD	_sprA1A_17
		.WORD	_sprA1A_18
		.WORD	_sprA1A_19
		.WORD	_sprA1A_1A
		.WORD	_sprA1A_1B
		.WORD	_sprA1A_1C
		.WORD	_sprA1A_1D
		.WORD	_sprA1A_1E
		.WORD	_sprA1A_1F
		.WORD	_sprA1A_20
		.WORD	_sprA1A_21
		.WORD	_sprA1A_22
		.WORD	_sprA1A_23
		.WORD	_sprA1A_24
		.WORD	_sprA1A_25
		.WORD	_sprA1A_26
		.WORD	_sprA1A_27
		.WORD	_sprA1A_28
		.WORD	_sprA1A_29	; lvl2 boss train slime (CHR0 0C, CHR1 0A)
		.WORD	_sprA1A_2A
		.WORD	_sprA1A_2B
		.WORD	_sprA1A_2C
		.WORD	_sprA1A_2D
		.WORD	_sprA1A_2E
		.WORD	_sprA1A_2F
		.WORD	_sprA1A_30
		.WORD	_sprA1A_31
		.WORD	_sprA1A_32
		.WORD	_sprA1A_33
		.WORD	_sprA1A_34
		.WORD	_sprA1A_35
		.WORD	_sprA1A_36
		.WORD	_sprA1A_37
		.WORD	_sprA1A_38
		.WORD	_sprA1A_39
		.WORD	_sprA1A_3A
		.WORD	_sprA1A_3B	; lvl3 boss sewer dragons (CHR0 13, CHR1 none)
		.WORD	_sprA1A_3C
		.WORD	_sprA1A_3D
		.WORD	_sprA1A_3E
		.WORD	_sprA1A_3F
		.WORD	_sprA1A_40
		.WORD	_sprA1A_41
		.WORD	_sprA1A_42
		.WORD	_sprA1A_43
		.WORD	_sprA1A_44
		.WORD	_sprA1A_45
		.WORD	_sprA1A_46
		.WORD	_sprA1A_47
		.WORD	_sprA1A_48
		.WORD	_sprA1A_49
		.WORD	_sprA1A_4A
		.WORD	_sprA1A_4B
		.WORD	_sprA1A_4C
		.WORD	_sprA1A_4D
		.WORD	_sprA1A_4E
		.WORD	_sprA1A_4F
		.WORD	_sprA1A_50
		.WORD	_sprA1A_51
		.WORD	_sprA1A_52
		.WORD	_sprA1A_53
		.WORD	_sprA1A_54
		.WORD	_sprA1A_55
		.WORD	_sprA1A_56
		.WORD	_sprA1A_57
		.WORD	_sprA1A_58
		.WORD	_sprA1A_59
		.WORD	_sprA1A_5A	; lvl5 boss keykeeper (CHR0 18, CHR1 none)
		.WORD	_sprA1A_5B
		.WORD	_sprA1A_5C
		.WORD	_sprA1A_5D
		.WORD	_sprA1A_5E
		.WORD	_sprA1A_5F
		.WORD	_sprA1A_60
		.WORD	_sprA1A_61
		.WORD	_sprA1A_62
		.WORD	_sprA1A_63
		.WORD	_sprA1A_64
		.WORD	_sprA1A_65
		.WORD	_sprA1A_66
		.WORD	_sprA1A_67
		.WORD	_sprA1A_68
		.WORD	_sprA1A_69
		.WORD	_sprA1A_6A
		.WORD	_sprA1A_6B
		.WORD	_sprA1A_6C
		.WORD	_sprA1A_6D
		.WORD	_sprA1A_6E
		.WORD	_sprA1A_6F
		.WORD	_sprA1A_70
		.WORD	_sprA1A_71
		.WORD	_sprA1A_72
		.WORD	_sprA1A_73
		.WORD	_sprA1A_74
		.WORD	_sprA1A_75
		.WORD	_sprA1A_76
; NOTE: this is a floor phase for baby keykeeper after it fall down to the floor
; but script use only two next frames rendered this one unused.
		.WORD	_sprA1A_77	; unused
		.WORD	_sprA1A_78
		.WORD	_sprA1A_79
		.WORD	_sprA1A_7A
		.WORD	_sprA1A_7B
		.WORD	_sprA1A_80
		.WORD	_sprA1A_81
		.WORD	_sprA1A_82
		.WORD	_sprA1A_83
		.WORD	_sprA1A_80
		.WORD	_sprA1A_81
		.WORD	_sprA1A_82
		.WORD	_sprA1A_83
		.WORD	_sprA1A_84	; lvl6 boss vega dead phase (CHR0 17, CHR1 none)
		.WORD	_sprA1A_85
		.WORD	_sprA1A_86
		.WORD	_sprA1A_87
		.WORD	_sprA1A_88
		.WORD	_sprA1A_89
		.WORD	_sprA1A_8A
		.WORD	_sprA1A_8B
		.WORD	_sprA1A_8C
		.WORD	_sprA1A_8D
		.WORD	_sprA1A_8E
		.WORD	_sprA1A_8F
		.WORD	_sprA1A_90
		.WORD	_sprA1A_91	; ending cutscene sprites (CHR1 none, CHR1 16)
		.WORD	_sprA1A_92
		.WORD	_sprA1A_93
		.WORD	_sprA1A_94
_spr_libB1A:
		.WORD	_sprB1A_C0	; lvl6 boss vega main sprites (CHR0 17, CHR1 none)
		.WORD	_sprB1A_C1
		.WORD	_sprB1A_C2
		.WORD	_sprB1A_C3
		.WORD	_sprB1A_C4
		.WORD	_sprB1A_C5
		.WORD	_sprB1A_C6
		.WORD	_sprB1A_C7

_sprA1A_04:
		.BYTE	$02
		.BYTE	$F8,$CA,$02,$F8
		.BYTE	$F8,$DA,$02,$00
_sprA1A_05:
		.BYTE	$02
		.BYTE	$F8,$CC,$02,$F8
		.BYTE	$F8,$DC,$02,$00
_sprA1A_06:
		.BYTE	$02
		.BYTE	$F8,$CC,$42,$00
		.BYTE	$F8,$DC,$42,$F8
_sprA1A_07:
		.BYTE	$03
		.BYTE	$00,$58,$00,$F8
		.BYTE	$F7,$58,$00,$FB
		.BYTE	$FD,$58,$00,$00
_sprA1A_08:
		.BYTE	$03
		.BYTE	$02,$48,$00,$FB
		.BYTE	$FC,$48,$00,$FE
		.BYTE	$FD,$48,$00,$FA
_sprA1A_09:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_09_B
_sprA1A_09_A:
		.BYTE	$02
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
_sprA1A_09_B:
		.BYTE	$06
		.BYTE	$E8,$A4,$02,$FC
		.BYTE	$E8,$B4,$02,$04
		.BYTE	$E8,$B4,$42,$F4
		.BYTE	$F8,$A6,$02,$FC
		.BYTE	$F8,$B6,$02,$04
		.BYTE	$F8,$B6,$42,$F4
_sprA1A_0A:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_0A_B
_sprA1A_0A_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$42,$04
		.BYTE	$E8,$9C,$42,$FC
		.BYTE	$E8,$AC,$42,$F4
		.BYTE	$F8,$8E,$42,$04
		.BYTE	$F8,$9E,$42,$FC
		.BYTE	$F8,$AE,$42,$F4
_sprA1A_0B:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_0B_B
_sprA1A_0B_B:
		.BYTE	$06
		.BYTE	$E8,$80,$02,$F4
		.BYTE	$E8,$80,$42,$04
		.BYTE	$E8,$90,$02,$FC
		.BYTE	$F8,$82,$02,$F4
		.BYTE	$F8,$82,$42,$04
		.BYTE	$F8,$92,$02,$FC
_sprA1A_0C:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_0C_B
_sprA1A_0C_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$02,$F4
		.BYTE	$E8,$9C,$02,$FC
		.BYTE	$E8,$AC,$02,$04
		.BYTE	$F8,$8E,$02,$F4
		.BYTE	$F8,$9E,$02,$FC
		.BYTE	$F8,$AE,$02,$04
_sprA1A_0D:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_0D_B
_sprA1A_0D_B:
		.BYTE	$06
		.BYTE	$E8,$84,$02,$F4
		.BYTE	$E8,$84,$42,$04
		.BYTE	$E8,$94,$02,$FC
		.BYTE	$F8,$86,$02,$F4
		.BYTE	$F8,$86,$42,$04
		.BYTE	$F8,$96,$02,$FC
_sprA1A_0E:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_0E_B
_sprA1A_0E_B:
		.BYTE	$06
		.BYTE	$E8,$88,$42,$04
		.BYTE	$E8,$98,$42,$FC
		.BYTE	$E8,$A8,$42,$F4
		.BYTE	$F8,$8A,$42,$04
		.BYTE	$F8,$9A,$42,$FC
		.BYTE	$F8,$AA,$42,$F4
_sprA1A_0F:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_0F_B
_sprA1A_0F_B:
		.BYTE	$06
		.BYTE	$E8,$A0,$02,$FC
		.BYTE	$E8,$B0,$02,$04
		.BYTE	$E8,$B0,$42,$F4
		.BYTE	$F8,$A2,$02,$FC
		.BYTE	$F8,$B2,$02,$04
		.BYTE	$F8,$B2,$42,$F4
_sprA1A_10:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_10_B
_sprA1A_10_B:
		.BYTE	$06
		.BYTE	$E8,$88,$02,$F4
		.BYTE	$E8,$98,$02,$FC
		.BYTE	$E8,$A8,$02,$04
		.BYTE	$F8,$8A,$02,$F4
		.BYTE	$F8,$9A,$02,$FC
		.BYTE	$F8,$AA,$02,$04
_sprA1A_11:
		.BYTE	$82
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_11_B
_sprA1A_11_A:
		.BYTE	$02
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
_sprA1A_11_B:
		.BYTE	$06
		.BYTE	$E8,$A4,$02,$FE
		.BYTE	$E8,$B4,$02,$06
		.BYTE	$E8,$B4,$42,$F6
		.BYTE	$F8,$A6,$02,$FE
		.BYTE	$F8,$B6,$02,$06
		.BYTE	$F8,$B6,$42,$F6
_sprA1A_12:
		.BYTE	$82
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_12_B
_sprA1A_12_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$42,$06
		.BYTE	$E8,$9C,$42,$FE
		.BYTE	$E8,$AC,$42,$F6
		.BYTE	$F8,$8E,$42,$06
		.BYTE	$F8,$9E,$42,$FE
		.BYTE	$F8,$AE,$42,$F6
_sprA1A_13:
		.BYTE	$82
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_13_B
_sprA1A_13_B:
		.BYTE	$06
		.BYTE	$E8,$80,$02,$F6
		.BYTE	$E8,$80,$42,$06
		.BYTE	$E8,$90,$02,$FE
		.BYTE	$F8,$82,$02,$F6
		.BYTE	$F8,$82,$42,$06
		.BYTE	$F8,$92,$02,$FE
_sprA1A_14:
		.BYTE	$82
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_14_B
_sprA1A_14_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$02,$F6
		.BYTE	$E8,$9C,$02,$FE
		.BYTE	$E8,$AC,$02,$06
		.BYTE	$F8,$8E,$02,$F6
		.BYTE	$F8,$9E,$02,$FE
		.BYTE	$F8,$AE,$02,$06
_sprA1A_15:
		.BYTE	$82
		.WORD	_sprA1A_15_A
		.WORD	_sprA1A_15_B
_sprA1A_15_A:
		.BYTE	$02
		.BYTE	$FF,$CE,$02,$F2
		.BYTE	$FF,$DE,$02,$FA
_sprA1A_15_B:
		.BYTE	$03
		.BYTE	$EF,$88,$02,$EE
		.BYTE	$EF,$98,$02,$F6
		.BYTE	$F0,$A8,$02,$FE
_sprA1A_16:
		.BYTE	$82
		.WORD	_sprA1A_15_A
		.WORD	_sprA1A_16_B
_sprA1A_16_B
		.BYTE	$03
		.BYTE	$F6,$88,$02,$EE
		.BYTE	$F7,$98,$02,$F6
		.BYTE	$F8,$A8,$02,$FE
_sprA1A_17:
		.BYTE	$82
		.WORD	_sprA1A_17_A
		.WORD	_sprA1A_17_B
_sprA1A_17_A:
		.BYTE	$02
		.BYTE	$FF,$CE,$42,$07
		.BYTE	$FF,$DE,$42,$FF
_sprA1A_17_B:
		.BYTE	$03
		.BYTE	$EF,$88,$42,$0B
		.BYTE	$EF,$98,$42,$03
		.BYTE	$F0,$A8,$42,$FB
_sprA1A_18:
		.BYTE	$82
		.WORD	_sprA1A_17_A
		.WORD	_sprA1A_18_B
_sprA1A_18_B:
		.BYTE	$03
		.BYTE	$F6,$88,$42,$0B
		.BYTE	$F7,$98,$42,$03
		.BYTE	$F8,$A8,$42,$FB
_sprA1A_19:
		.BYTE	$83
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_19_B
		.WORD	_sprA1A_19_C
_sprA1A_19_B:
		.BYTE	$02
		.BYTE	$08,$D4,$03,$F8
		.BYTE	$08,$D4,$43,$00
_sprA1A_19_C:
		.BYTE	$04
		.BYTE	$E8,$BE,$03,$00
		.BYTE	$E8,$D6,$03,$F8
		.BYTE	$F8,$D8,$03,$F8
		.BYTE	$F8,$D8,$43,$00
_sprA1A_1A:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_1A_B
_sprA1A_1A_B:
		.BYTE	$05
		.BYTE	$08,$F4,$43,$F8
		.BYTE	$E8,$E0,$43,$00
		.BYTE	$E8,$F0,$43,$F8
		.BYTE	$F8,$E2,$43,$00
		.BYTE	$F8,$F2,$43,$F8
_sprA1A_1B:
		.BYTE	$83
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_19_B
		.WORD	_sprA1A_1B_C
_sprA1A_1B_C:
		.BYTE	$04
		.BYTE	$E8,$BA,$03,$00
		.BYTE	$E8,$D0,$03,$F8
		.BYTE	$F8,$D2,$03,$F8
		.BYTE	$F8,$D2,$43,$00
_sprA1A_1C:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_1C_B
_sprA1A_1C_B:
		.BYTE	$05
		.BYTE	$08,$F4,$03,$00
		.BYTE	$E8,$E0,$03,$F8
		.BYTE	$E8,$F0,$03,$00
		.BYTE	$F8,$E2,$03,$F8
		.BYTE	$F8,$F2,$03,$00
_sprA1A_1D:
		.BYTE	$83
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_1D_B
		.WORD	_sprA1A_1D_C
_sprA1A_1D_B:
		.BYTE	$02
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$C4,$43,$00
_sprA1A_1D_C:
		.BYTE	$04
		.BYTE	$E8,$BC,$03,$00
		.BYTE	$E8,$C6,$03,$F8
		.BYTE	$F8,$C8,$03,$F8
		.BYTE	$F8,$C8,$43,$00
_sprA1A_1E:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_1E_B
_sprA1A_1E_B:
		.BYTE	$05
		.BYTE	$08,$E4,$43,$F8
		.BYTE	$E8,$E6,$43,$00
		.BYTE	$E8,$F6,$43,$F8
		.BYTE	$F8,$E8,$43,$00
		.BYTE	$F8,$F8,$43,$F8
_sprA1A_1F:
		.BYTE	$83
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_1D_B
		.WORD	_sprA1A_1F_C
_sprA1A_1F_C:
		.BYTE	$04
		.BYTE	$E8,$B8,$03,$00
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$C2,$43,$00
_sprA1A_20:
		.BYTE	$82
		.WORD	_sprA1A_09_A
		.WORD	_sprA1A_20_B
_sprA1A_20_B:
		.BYTE	$05
		.BYTE	$08,$E4,$03,$00
		.BYTE	$E8,$E6,$03,$F8
		.BYTE	$E8,$F6,$03,$00
		.BYTE	$F8,$E8,$03,$F8
		.BYTE	$F8,$F8,$03,$00
_sprA1A_21:
		.BYTE	$83
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_21_B
		.WORD	_sprA1A_21_C
_sprA1A_21_B:
		.BYTE	$02
		.BYTE	$08,$D4,$03,$FA
		.BYTE	$08,$D4,$43,$02
_sprA1A_21_C
		.BYTE	$04
		.BYTE	$E8,$BE,$03,$02
		.BYTE	$E8,$D6,$03,$FA
		.BYTE	$F8,$D8,$03,$FA
		.BYTE	$F8,$D8,$43,$02
_sprA1A_22:
		.BYTE	$82
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_22_B
_sprA1A_22_B:
		.BYTE	$05
		.BYTE	$08,$F4,$43,$FA
		.BYTE	$E8,$E0,$43,$02
		.BYTE	$E8,$F0,$43,$FA
		.BYTE	$F8,$E2,$43,$02
		.BYTE	$F8,$F2,$43,$FA
_sprA1A_23:
		.BYTE	$83
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_21_B
		.WORD	_sprA1A_23_C
_sprA1A_23_C:
		.BYTE	$04
		.BYTE	$E8,$BA,$03,$02
		.BYTE	$E8,$D0,$03,$FA
		.BYTE	$F8,$D2,$03,$FA
		.BYTE	$F8,$D2,$43,$02
_sprA1A_24:
		.BYTE	$82
		.WORD	_sprA1A_11_A
		.WORD	_sprA1A_24_B
_sprA1A_24_B:
		.BYTE	$05
		.BYTE	$08,$F4,$03,$02
		.BYTE	$E8,$E0,$03,$FA
		.BYTE	$E8,$F0,$03,$02
		.BYTE	$F8,$E2,$03,$FA
		.BYTE	$F8,$F2,$03,$02
_sprA1A_25:
		.BYTE	$05
		.BYTE	$E6,$E6,$03,$F6
		.BYTE	$E6,$F6,$03,$FE
		.BYTE	$F6,$E8,$03,$F5
		.BYTE	$F6,$F8,$03,$FD
		.BYTE	$FF,$FA,$03,$FA
_sprA1A_26:
		.BYTE	$03
		.BYTE	$F4,$F6,$03,$FF
		.BYTE	$F6,$E6,$03,$F7
		.BYTE	$FF,$FA,$03,$FA
_sprA1A_27:
		.BYTE	$05
		.BYTE	$E6,$E6,$43,$03
		.BYTE	$E6,$F6,$43,$FB
		.BYTE	$F6,$E8,$43,$04
		.BYTE	$F6,$F8,$43,$FC
		.BYTE	$FF,$FA,$43,$FF
_sprA1A_28:
		.BYTE	$03
		.BYTE	$F4,$F6,$43,$FA
		.BYTE	$F6,$E6,$43,$02
		.BYTE	$FF,$FA,$43,$FF
_sprA1A_29:
		.BYTE	$82
		.WORD	_sprA1A_29_A
		.WORD	_sprA1A_29_B
_sprA1A_29_A:
		.BYTE	$04
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$E7,$E3,$00,$F8
		.BYTE	$E7,$E3,$40,$00
_sprA1A_29_B:
		.BYTE	$07
		.BYTE	$00,$E2,$02,$F8
		.BYTE	$00,$E2,$42,$00
		.BYTE	$F0,$E0,$02,$F8
		.BYTE	$F0,$E0,$42,$00
		.BYTE	$FD,$C7,$00,$FA
		.BYTE	$FD,$D7,$00,$02
		.BYTE	$FD,$E7,$00,$0A
_sprA1A_2A:
		.BYTE	$83
		.WORD	_sprA1A_29_A
		.WORD	_sprA1A_2B_A
		.WORD	_sprA1A_2A_C
_sprA1A_2A_C:
		.BYTE	$03
		.BYTE	$FF,$C7,$00,$FA
		.BYTE	$FF,$D7,$00,$02
		.BYTE	$FF,$E7,$00,$0A
_sprA1A_2B:
		.BYTE	$82
		.WORD	_sprA1A_2B_A
		.WORD	_sprA1A_2B_B
_sprA1A_2B_A:
		.BYTE	$04
		.BYTE	$01,$E2,$02,$F8
		.BYTE	$01,$E2,$42,$00
		.BYTE	$F1,$F0,$02,$F8
		.BYTE	$F1,$F0,$42,$00
_sprA1A_2B_B:
		.BYTE	$07
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$E8,$E3,$00,$F8
		.BYTE	$E8,$E3,$40,$00
		.BYTE	$FE,$C7,$00,$FA
		.BYTE	$FE,$D7,$00,$02
		.BYTE	$FE,$E7,$00,$0A
_sprA1A_2C:
		.BYTE	$82
		.WORD	_sprA1A_2C_A
		.WORD	_sprA1A_2C_B
_sprA1A_2C_A:
		.BYTE	$07
		.BYTE	$00,$C4,$42,$00
		.BYTE	$00,$D4,$42,$F8
		.BYTE	$06,$3E,$03,$00
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$E8,$C5,$00,$F9
		.BYTE	$E8,$D5,$00,$01
		.BYTE	$F0,$C2,$42,$00
_sprA1A_2C_B:
		.BYTE	$03
		.BYTE	$F0,$D2,$42,$F8
		.BYTE	$FD,$E5,$00,$FA
		.BYTE	$FD,$F5,$00,$02
_sprA1A_2D:
		.BYTE	$82
		.WORD	_sprA1A_2C_A
		.WORD	_sprA1A_2D_B
_sprA1A_2D_B:
		.BYTE	$04
		.BYTE	$F0,$D2,$42,$F8
		.BYTE	$F8,$C7,$00,$FA
		.BYTE	$F8,$D7,$00,$02
		.BYTE	$F8,$E7,$00,$0A
_sprA1A_2E:
		.BYTE	$83
		.WORD	_sprA1A_2E_A
		.WORD	_sprA1A_2E_B
		.WORD	_sprA1A_2E_C
_sprA1A_2E_A:
		.BYTE	$02
		.BYTE	$06,$3E,$03,$00
		.BYTE	$06,$3E,$43,$F8
_sprA1A_2E_B:
		.BYTE	$02
		.BYTE	$EA,$F3,$00,$F8
		.BYTE	$EA,$F3,$40,$00
_sprA1A_2E_C:
		.BYTE	$05
		.BYTE	$EF,$F2,$02,$F8
		.BYTE	$EF,$F2,$42,$00
		.BYTE	$F1,$F5,$80,$05
		.BYTE	$FF,$F4,$02,$F8
		.BYTE	$FF,$F4,$42,$00
_sprA1A_2F:
		.BYTE	$83
		.WORD	_sprA1A_2E_A
		.WORD	_sprA1A_2E_B
		.WORD	_sprA1A_2F_C
_sprA1A_2F_C:
		.BYTE	$05
		.BYTE	$E6,$F7,$00,$FA
		.BYTE	$EE,$F2,$02,$F8
		.BYTE	$EE,$F2,$42,$00
		.BYTE	$FE,$F4,$02,$F8
		.BYTE	$FE,$F4,$42,$00
_sprA1A_30:
		.BYTE	$82
		.WORD	_sprA1A_2E_A
		.WORD	_sprA1A_30_B
_sprA1A_30_B:
		.BYTE	$07
		.BYTE	$E9,$F3,$00,$F8
		.BYTE	$E9,$F3,$40,$00
		.BYTE	$ED,$F2,$02,$F8
		.BYTE	$ED,$F2,$42,$00
		.BYTE	$ED,$F5,$C0,$F0
		.BYTE	$FD,$F4,$02,$F8
		.BYTE	$FD,$F4,$42,$00
_sprA1A_31:
		.BYTE	$0B
		.BYTE	$00,$E2,$02,$FA
		.BYTE	$00,$E2,$42,$02
		.BYTE	$08,$3E,$03,$02
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$E7,$E3,$00,$FA
		.BYTE	$E7,$E3,$40,$02
		.BYTE	$F0,$E0,$02,$FA
		.BYTE	$F0,$E0,$42,$02
		.BYTE	$FD,$C7,$00,$FC
		.BYTE	$FD,$D7,$00,$04
		.BYTE	$FD,$E7,$00,$0C
_sprA1A_32:
		.BYTE	$03
		.BYTE	$00,$C6,$02,$F8
		.BYTE	$F0,$D6,$02,$F2
		.BYTE	$F0,$E6,$02,$FA
_sprA1A_33:
		.BYTE	$02
		.BYTE	$F8,$E4,$02,$F0
		.BYTE	$F8,$F6,$02,$F8
_sprA1A_34:
		.BYTE	$03
		.BYTE	$00,$C6,$42,$00
		.BYTE	$F0,$D6,$42,$08
		.BYTE	$F0,$E6,$42,$00
_sprA1A_35:
		.BYTE	$02
		.BYTE	$F8,$E4,$42,$08
		.BYTE	$F8,$F6,$42,$00
_sprA1A_36:
		.BYTE	$01
		.BYTE	$F8,$C0,$01,$FC
_sprA1A_37:
		.BYTE	$01
		.BYTE	$F8,$D0,$01,$FC
_sprA1A_38:
		.BYTE	$01
		.BYTE	$F8,$C0,$41,$FC
_sprA1A_39:
		.BYTE	$01
		.BYTE	$F8,$C8,$01,$FC
_sprA1A_3A:
		.BYTE	$01
		.BYTE	$F8,$C8,$41,$FC
_sprA1A_3B:
		.BYTE	$82
		.WORD	_sprA1A_3B_A
		.WORD	_sprA1A_3B_B
_sprA1A_3B_A:
		.BYTE	$02
		.BYTE	$08,$82,$00,$F4
		.BYTE	$08,$90,$00,$04
_sprA1A_3B_B:
		.BYTE	$01
		.BYTE	$08,$80,$00,$FC
_sprA1A_3C:
		.BYTE	$82
		.WORD	_sprA1A_3B_A
		.WORD	_sprA1A_3C_B
_sprA1A_3C_B:
		.BYTE	$01
		.BYTE	$08,$98,$03,$FC
_sprA1A_3D:
		.BYTE	$03
		.BYTE	$08,$8A,$43,$04
		.BYTE	$08,$90,$43,$F4
		.BYTE	$08,$9A,$43,$FC
_sprA1A_3E:
		.BYTE	$82
		.WORD	_sprA1A_3B_A
		.WORD	_sprA1A_3E_B
_sprA1A_3E_B:
		.BYTE	$01
		.BYTE	$08,$88,$03,$FC
_sprA1A_3F:
		.BYTE	$03
		.BYTE	$08,$8A,$03,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$9A,$03,$FC
_sprA1A_40:
		.BYTE	$82
		.WORD	_sprA1A_3B_A
		.WORD	_sprA1A_40_B
_sprA1A_40_B:
		.BYTE	$07
		.BYTE	$08,$80,$00,$FC
		.BYTE	$EE,$A6,$03,$FC
		.BYTE	$FE,$A4,$03,$EC
		.BYTE	$FE,$A4,$43,$0C
		.BYTE	$FE,$B4,$03,$F4
		.BYTE	$FE,$B4,$43,$04
		.BYTE	$FE,$C4,$03,$FC
_sprA1A_41:
		.BYTE	$08
		.BYTE	$08,$80,$43,$00
		.BYTE	$08,$80,$43,$F8
		.BYTE	$EE,$A8,$43,$04
		.BYTE	$EE,$B8,$43,$FC
		.BYTE	$FE,$C8,$43,$0C
		.BYTE	$FE,$D8,$43,$04
		.BYTE	$FE,$E8,$43,$FC
		.BYTE	$FE,$F8,$43,$F4
_sprA1A_42:
		.BYTE	$09
		.BYTE	$08,$80,$03,$FC
		.BYTE	$08,$82,$03,$F4
		.BYTE	$08,$90,$03,$04
		.BYTE	$EE,$A2,$03,$FC
		.BYTE	$FE,$A0,$03,$EC
		.BYTE	$FE,$A0,$43,$0C
		.BYTE	$FE,$B0,$03,$F4
		.BYTE	$FE,$B0,$43,$04
		.BYTE	$FE,$C0,$03,$FC
_sprA1A_43:
		.BYTE	$08
		.BYTE	$08,$80,$03,$00
		.BYTE	$08,$80,$03,$F8
		.BYTE	$EE,$A8,$03,$F4
		.BYTE	$EE,$B8,$03,$FC
		.BYTE	$FE,$C8,$03,$EC
		.BYTE	$FE,$D8,$03,$F4
		.BYTE	$FE,$E8,$03,$FC
		.BYTE	$FE,$F8,$03,$04
_sprA1A_44:
		.BYTE	$09
		.BYTE	$00,$86,$03,$04
		.BYTE	$00,$B6,$03,$F4
		.BYTE	$00,$C6,$03,$FC
		.BYTE	$E0,$A6,$03,$FC
		.BYTE	$F0,$A4,$03,$EC
		.BYTE	$F0,$A4,$43,$0C
		.BYTE	$F0,$B4,$03,$F4
		.BYTE	$F0,$B4,$43,$04
		.BYTE	$F0,$C4,$03,$FC
_sprA1A_45:
		.BYTE	$0A
		.BYTE	$00,$CA,$43,$0C
		.BYTE	$00,$DA,$43,$04
		.BYTE	$00,$EA,$43,$FC
		.BYTE	$00,$FA,$43,$F4
		.BYTE	$E0,$A8,$43,$04
		.BYTE	$E0,$B8,$43,$FC
		.BYTE	$F0,$C8,$43,$0C
		.BYTE	$F0,$D8,$43,$04
		.BYTE	$F0,$E8,$43,$FC
		.BYTE	$F0,$F8,$43,$F4
_sprA1A_46:
		.BYTE	$09
		.BYTE	$00,$84,$03,$04
		.BYTE	$00,$B2,$03,$F4
		.BYTE	$00,$C2,$03,$FC
		.BYTE	$E0,$A2,$03,$FC
		.BYTE	$F0,$A0,$03,$EC
		.BYTE	$F0,$A0,$43,$0C
		.BYTE	$F0,$B0,$03,$F4
		.BYTE	$F0,$B0,$43,$04
		.BYTE	$F0,$C0,$03,$FC
_sprA1A_47:
		.BYTE	$0A
		.BYTE	$00,$CA,$03,$F0
		.BYTE	$00,$DA,$03,$F8
		.BYTE	$00,$EA,$03,$00
		.BYTE	$00,$FA,$03,$08
		.BYTE	$E0,$A8,$03,$F8
		.BYTE	$E0,$B8,$03,$00
		.BYTE	$F0,$C8,$03,$F0
		.BYTE	$F0,$D8,$03,$F8
		.BYTE	$F0,$E8,$03,$00
		.BYTE	$F0,$F8,$03,$08
_sprA1A_48:
		.BYTE	$09
		.BYTE	$00,$96,$03,$F4
		.BYTE	$00,$D6,$03,$FC
		.BYTE	$00,$E6,$03,$04
		.BYTE	$E0,$F6,$03,$FC
		.BYTE	$F0,$D4,$03,$FC
		.BYTE	$F0,$E4,$03,$04
		.BYTE	$F0,$E4,$43,$F4
		.BYTE	$F0,$F4,$03,$0C
		.BYTE	$F0,$F4,$43,$EC
_sprA1A_49:
		.BYTE	$09
		.BYTE	$00,$CE,$43,$04
		.BYTE	$00,$DE,$43,$FC
		.BYTE	$00,$EE,$43,$F4
		.BYTE	$E0,$AA,$43,$04
		.BYTE	$E0,$BA,$43,$FC
		.BYTE	$F0,$BC,$43,$0C
		.BYTE	$F0,$CC,$43,$04
		.BYTE	$F0,$DC,$43,$FC
		.BYTE	$F0,$EC,$43,$F4
_sprA1A_4A:
		.BYTE	$09
		.BYTE	$00,$94,$03,$F4
		.BYTE	$00,$D2,$03,$FC
		.BYTE	$00,$E2,$03,$04
		.BYTE	$E0,$F2,$03,$FC
		.BYTE	$F0,$D0,$03,$FC
		.BYTE	$F0,$E0,$03,$04
		.BYTE	$F0,$E0,$43,$F4
		.BYTE	$F0,$F0,$03,$0C
		.BYTE	$F0,$F0,$43,$EC
_sprA1A_4B:
		.BYTE	$09
		.BYTE	$00,$CE,$03,$F8
		.BYTE	$00,$DE,$03,$00
		.BYTE	$00,$EE,$03,$08
		.BYTE	$E0,$AA,$03,$F8
		.BYTE	$E0,$BA,$03,$00
		.BYTE	$F0,$BC,$03,$F0
		.BYTE	$F0,$CC,$03,$F8
		.BYTE	$F0,$DC,$03,$00
		.BYTE	$F0,$EC,$03,$08
_sprA1A_4C:
		.BYTE	$09
		.BYTE	$00,$86,$03,$06
		.BYTE	$00,$B6,$03,$F6
		.BYTE	$00,$C6,$03,$FE
		.BYTE	$E0,$A6,$03,$FE
		.BYTE	$F0,$A4,$03,$EE
		.BYTE	$F0,$A4,$43,$0E
		.BYTE	$F0,$B4,$03,$F6
		.BYTE	$F0,$B4,$43,$06
		.BYTE	$F0,$C4,$03,$FE
_sprA1A_4D:
		.BYTE	$0A
		.BYTE	$00,$CA,$43,$0E
		.BYTE	$00,$DA,$43,$06
		.BYTE	$00,$EA,$43,$FE
		.BYTE	$00,$FA,$43,$F6
		.BYTE	$E0,$A8,$43,$06
		.BYTE	$E0,$B8,$43,$FE
		.BYTE	$F0,$C8,$43,$0E
		.BYTE	$F0,$D8,$43,$06
		.BYTE	$F0,$E8,$43,$FE
		.BYTE	$F0,$F8,$43,$F6
_sprA1A_4E:
		.BYTE	$09
		.BYTE	$00,$84,$03,$07
		.BYTE	$00,$B2,$03,$F7
		.BYTE	$00,$C2,$03,$FF
		.BYTE	$E0,$A2,$03,$FF
		.BYTE	$F0,$A0,$03,$EF
		.BYTE	$F0,$A0,$43,$0F
		.BYTE	$F0,$B0,$03,$F7
		.BYTE	$F0,$B0,$43,$07
		.BYTE	$F0,$C0,$03,$FF
_sprA1A_4F:
		.BYTE	$0A
		.BYTE	$00,$CA,$03,$F2
		.BYTE	$00,$DA,$03,$FA
		.BYTE	$00,$EA,$03,$02
		.BYTE	$00,$FA,$03,$0A
		.BYTE	$E0,$A8,$03,$FA
		.BYTE	$E0,$B8,$03,$02
		.BYTE	$F0,$C8,$03,$F2
		.BYTE	$F0,$D8,$03,$FA
		.BYTE	$F0,$E8,$03,$02
		.BYTE	$F0,$F8,$03,$0A
_sprA1A_50:
		.BYTE	$0A
		.BYTE	$DF,$AA,$03,$F2
		.BYTE	$DF,$BA,$03,$FA
		.BYTE	$EF,$C8,$03,$EA
		.BYTE	$EF,$D8,$03,$F2
		.BYTE	$EF,$E8,$03,$FA
		.BYTE	$EF,$F8,$03,$02
		.BYTE	$FF,$9E,$03,$F2
		.BYTE	$FF,$AE,$03,$FA
		.BYTE	$FF,$BE,$03,$02
		.BYTE	$FF,$CA,$03,$EA
_sprA1A_51:
		.BYTE	$04
		.BYTE	$07,$8E,$03,$F9
		.BYTE	$07,$BE,$03,$01
		.BYTE	$F7,$C8,$03,$F9
		.BYTE	$F7,$F8,$03,$01
_sprA1A_52:
		.BYTE	$0A
		.BYTE	$DF,$AA,$43,$07
		.BYTE	$DF,$BA,$43,$FF
		.BYTE	$EF,$C8,$43,$0F
		.BYTE	$EF,$D8,$43,$07
		.BYTE	$EF,$E8,$43,$FF
		.BYTE	$EF,$F8,$43,$F7
		.BYTE	$FF,$9E,$43,$07
		.BYTE	$FF,$AE,$43,$FF
		.BYTE	$FF,$BE,$43,$F7
		.BYTE	$FF,$CA,$43,$0F
_sprA1A_53:
		.BYTE	$04
		.BYTE	$06,$8E,$43,$02
		.BYTE	$06,$BE,$43,$FA
		.BYTE	$F6,$C8,$43,$02
		.BYTE	$F6,$F8,$43,$FA
_sprA1A_54:
		.BYTE	$03
		.BYTE	$0E,$92,$01,$FC
		.BYTE	$E3,$92,$01,$FC
		.BYTE	$F9,$92,$41,$FC
_sprA1A_55:
		.BYTE	$03
		.BYTE	$04,$92,$01,$FC
		.BYTE	$D8,$92,$41,$FC
		.BYTE	$EE,$92,$41,$FC
_sprA1A_56:
		.BYTE	$03
		.BYTE	$F2,$92,$01,$0D
		.BYTE	$F5,$92,$41,$F7
		.BYTE	$F8,$92,$41,$E1
_sprA1A_57:
		.BYTE	$03
		.BYTE	$F0,$92,$41,$18
		.BYTE	$F3,$92,$01,$02
		.BYTE	$F7,$92,$41,$EC
_sprA1A_58:
		.BYTE	$03
		.BYTE	$F0,$92,$01,$E0
		.BYTE	$F3,$92,$41,$F6
		.BYTE	$F7,$92,$01,$0C
_sprA1A_59:
		.BYTE	$03
		.BYTE	$F2,$92,$41,$EB
		.BYTE	$F5,$92,$01,$01
		.BYTE	$F8,$92,$01,$18
_sprA1A_5A:
		.BYTE	$82
		.WORD	_sprA1A_5A_A
		.WORD	_sprA1A_5A_B
_sprA1A_5A_A:
		.BYTE	$02
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$9E,$43,$F0
_sprA1A_5A_B:
		.BYTE	$08
		.BYTE	$08,$8C,$43,$00
		.BYTE	$08,$9C,$43,$F8
		.BYTE	$E8,$88,$43,$04
		.BYTE	$E8,$98,$43,$FC
		.BYTE	$E8,$A8,$43,$F4
		.BYTE	$F8,$8A,$43,$04
		.BYTE	$F8,$9A,$43,$FC
		.BYTE	$F8,$AA,$43,$F4
_sprA1A_5B:
		.BYTE	$82
		.WORD	_sprA1A_5B_A
		.WORD	_sprA1A_5B_B
_sprA1A_5B_A:
		.BYTE	$04
		.BYTE	$08,$84,$03,$F0
		.BYTE	$08,$84,$43,$08
		.BYTE	$08,$94,$03,$F8
		.BYTE	$08,$94,$43,$00
_sprA1A_5B_B:
		.BYTE	$08
		.BYTE	$E8,$80,$03,$F0
		.BYTE	$E8,$80,$43,$08
		.BYTE	$E8,$90,$03,$F8
		.BYTE	$E8,$90,$43,$00
		.BYTE	$F8,$82,$03,$F0
		.BYTE	$F8,$82,$43,$08
		.BYTE	$F8,$92,$03,$F8
		.BYTE	$F8,$92,$43,$00
_sprA1A_5C:
		.BYTE	$82
		.WORD	_sprA1A_5A_A
		.WORD	_sprA1A_5C_B
_sprA1A_5C_B:
		.BYTE	$08
		.BYTE	$08,$8C,$03,$F8
		.BYTE	$08,$9C,$03,$00
		.BYTE	$E8,$88,$03,$F4
		.BYTE	$E8,$98,$03,$FC
		.BYTE	$E8,$A8,$03,$04
		.BYTE	$F8,$8A,$03,$F4
		.BYTE	$F8,$9A,$03,$FC
		.BYTE	$F8,$AA,$03,$04
_sprA1A_5D:
		.BYTE	$82
		.WORD	_sprA1A_5D_A
		.WORD	_sprA1A_5D_B
_sprA1A_5D_A:
		.BYTE	$08
		.BYTE	$E8,$A0,$03,$00
		.BYTE	$E8,$A0,$43,$F8
		.BYTE	$E8,$B0,$03,$08
		.BYTE	$E8,$B0,$43,$F0
		.BYTE	$F8,$A2,$03,$00
		.BYTE	$F8,$A2,$43,$F8
		.BYTE	$F8,$B2,$03,$08
		.BYTE	$F8,$B2,$43,$F0
_sprA1A_5D_B:
		.BYTE	$04
		.BYTE	$08,$A4,$03,$00
		.BYTE	$08,$A4,$43,$F8
		.BYTE	$08,$B4,$03,$08
		.BYTE	$08,$B4,$43,$F0
_sprA1A_5E:
		.BYTE	$0A
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8C,$43,$00
		.BYTE	$07,$BC,$43,$F8
		.BYTE	$E7,$88,$43,$04
		.BYTE	$E7,$98,$43,$FC
		.BYTE	$E7,$A8,$43,$F4
		.BYTE	$F7,$8A,$43,$04
		.BYTE	$F7,$9A,$43,$FC
		.BYTE	$F7,$AA,$43,$F4
_sprA1A_5F:
		.BYTE	$82
		.WORD	_sprA1A_5F_A
		.WORD	_sprA1A_5F_B
_sprA1A_5F_A:
		.BYTE	$04
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8E,$03,$00
		.BYTE	$07,$8E,$43,$F8
_sprA1A_5F_B
		.BYTE	$08
		.BYTE	$E7,$80,$03,$F0
		.BYTE	$E7,$80,$43,$08
		.BYTE	$E7,$90,$03,$F8
		.BYTE	$E7,$90,$43,$00
		.BYTE	$F7,$82,$03,$F0
		.BYTE	$F7,$82,$43,$08
		.BYTE	$F7,$92,$03,$F8
		.BYTE	$F7,$92,$43,$00
_sprA1A_60:
		.BYTE	$0A
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8C,$03,$F8
		.BYTE	$07,$BC,$03,$00
		.BYTE	$E7,$88,$03,$F4
		.BYTE	$E7,$98,$03,$FC
		.BYTE	$E7,$A8,$03,$04
		.BYTE	$F7,$8A,$03,$F4
		.BYTE	$F7,$9A,$03,$FC
		.BYTE	$F7,$AA,$03,$04
_sprA1A_61:
		.BYTE	$82
		.WORD	_sprA1A_5F_A
		.WORD	_sprA1A_61_B
_sprA1A_61_B
		.BYTE	$08
		.BYTE	$E7,$A0,$03,$00
		.BYTE	$E7,$A0,$43,$F8
		.BYTE	$E7,$B0,$03,$08
		.BYTE	$E7,$B0,$43,$F0
		.BYTE	$F7,$A2,$03,$00
		.BYTE	$F7,$A2,$43,$F8
		.BYTE	$F7,$B2,$03,$08
		.BYTE	$F7,$B2,$43,$F0
_sprA1A_62:
		.BYTE	$82
		.WORD	_sprA1A_5A_A
		.WORD	_sprA1A_62_B
_sprA1A_62_B:
		.BYTE	$08
		.BYTE	$08,$AC,$43,$00
		.BYTE	$08,$BC,$43,$F8
		.BYTE	$E8,$88,$43,$03
		.BYTE	$E8,$98,$43,$FB
		.BYTE	$E8,$A8,$43,$F3
		.BYTE	$F8,$8A,$43,$03
		.BYTE	$F8,$9A,$43,$FB
		.BYTE	$F8,$AA,$43,$F3
_sprA1A_63:
		.BYTE	$83
		.WORD	_sprA1A_5A_A
		.WORD	_sprA1A_63_B
		.WORD	_sprA1A_5B_B
_sprA1A_63_B:
		.BYTE	$02
		.BYTE	$08,$AE,$03,$F8
		.BYTE	$08,$BE,$03,$00
_sprA1A_64:
		.BYTE	$82
		.WORD	_sprA1A_5A_A
		.WORD	_sprA1A_64_B
_sprA1A_64_B:
		.BYTE	$08
		.BYTE	$08,$AC,$03,$F8
		.BYTE	$08,$BC,$03,$00
		.BYTE	$E8,$88,$03,$F5
		.BYTE	$E8,$98,$03,$FD
		.BYTE	$E8,$A8,$03,$05
		.BYTE	$F8,$8A,$03,$F5
		.BYTE	$F8,$9A,$03,$FD
		.BYTE	$F8,$AA,$03,$05
_sprA1A_65:
		.BYTE	$83
		.WORD	_sprA1A_5A_A
		.WORD	_sprA1A_5D_A
		.WORD	_sprA1A_65_C
_sprA1A_65_C:
		.BYTE	$02
		.BYTE	$08,$B8,$03,$F8
		.BYTE	$08,$BA,$03,$00
_sprA1A_66:
		.BYTE	$0A
		.BYTE	$08,$8C,$43,$02
		.BYTE	$08,$9C,$43,$FA
		.BYTE	$08,$9E,$03,$0A
		.BYTE	$08,$9E,$43,$F2
		.BYTE	$E8,$88,$43,$06
		.BYTE	$E8,$98,$43,$FE
		.BYTE	$E8,$A8,$43,$F6
		.BYTE	$F8,$8A,$43,$06
		.BYTE	$F8,$9A,$43,$FE
		.BYTE	$F8,$AA,$43,$F6
_sprA1A_67:
		.BYTE	$0C
		.BYTE	$08,$84,$03,$F2
		.BYTE	$08,$84,$43,$0A
		.BYTE	$08,$94,$03,$FA
		.BYTE	$08,$94,$43,$02
		.BYTE	$E8,$80,$03,$F2
		.BYTE	$E8,$80,$43,$0A
		.BYTE	$E8,$90,$03,$FA
		.BYTE	$E8,$90,$43,$02
		.BYTE	$F8,$82,$03,$F2
		.BYTE	$F8,$82,$43,$0A
		.BYTE	$F8,$92,$03,$FA
		.BYTE	$F8,$92,$43,$02
_sprA1A_68:
		.BYTE	$0A
		.BYTE	$08,$8C,$03,$FA
		.BYTE	$08,$9C,$03,$02
		.BYTE	$08,$9E,$03,$0A
		.BYTE	$08,$9E,$43,$F2
		.BYTE	$E8,$88,$03,$F6
		.BYTE	$E8,$98,$03,$FE
		.BYTE	$E8,$A8,$03,$06
		.BYTE	$F8,$8A,$03,$F6
		.BYTE	$F8,$9A,$03,$FE
		.BYTE	$F8,$AA,$03,$06
_sprA1A_69:
		.BYTE	$0C
		.BYTE	$08,$A4,$03,$02
		.BYTE	$08,$A4,$43,$FA
		.BYTE	$08,$B4,$03,$0A
		.BYTE	$08,$B4,$43,$F2
		.BYTE	$E8,$A0,$03,$02
		.BYTE	$E8,$A0,$43,$FA
		.BYTE	$E8,$B0,$03,$0A
		.BYTE	$E8,$B0,$43,$F2
		.BYTE	$F8,$A2,$03,$02
		.BYTE	$F8,$A2,$43,$FA
		.BYTE	$F8,$B2,$03,$0A
		.BYTE	$F8,$B2,$43,$F2
_sprA1A_6A:
		.BYTE	$82
		.WORD	_sprA1A_6A_A
		.WORD	_sprA1A_0E_B
_sprA1A_6A_A:
		.BYTE	$04
		.BYTE	$08,$8C,$42,$00
		.BYTE	$08,$9C,$42,$F8
		.BYTE	$08,$9E,$02,$08
		.BYTE	$08,$9E,$42,$F0
_sprA1A_6B:
		.BYTE	$0C
		.BYTE	$08,$84,$02,$F0
		.BYTE	$08,$84,$42,$08
		.BYTE	$08,$94,$02,$F8
		.BYTE	$08,$94,$42,$00
		.BYTE	$E8,$80,$02,$F0
		.BYTE	$E8,$80,$42,$08
		.BYTE	$E8,$90,$02,$F8
		.BYTE	$E8,$90,$42,$00
		.BYTE	$F8,$82,$02,$F0
		.BYTE	$F8,$82,$42,$08
		.BYTE	$F8,$92,$02,$F8
		.BYTE	$F8,$92,$42,$00
_sprA1A_6C:
		.BYTE	$82
		.WORD	_sprA1A_6C_A
		.WORD	_sprA1A_10_B
_sprA1A_6C_A:
		.BYTE	$04
		.BYTE	$08,$8C,$02,$F8
		.BYTE	$08,$9C,$02,$00
		.BYTE	$08,$9E,$02,$08
		.BYTE	$08,$9E,$42,$F0
_sprA1A_6D:
		.BYTE	$0C
		.BYTE	$08,$A4,$02,$00
		.BYTE	$08,$A4,$42,$F8
		.BYTE	$08,$B4,$02,$08
		.BYTE	$08,$B4,$42,$F0
		.BYTE	$E8,$A0,$02,$00
		.BYTE	$E8,$A0,$42,$F8
		.BYTE	$E8,$B0,$02,$08
		.BYTE	$E8,$B0,$42,$F0
		.BYTE	$F8,$A2,$02,$00
		.BYTE	$F8,$A2,$42,$F8
		.BYTE	$F8,$B2,$02,$08
		.BYTE	$F8,$B2,$42,$F0
_sprA1A_6E:
		.BYTE	$0A
		.BYTE	$08,$8C,$42,$02
		.BYTE	$08,$9C,$42,$FA
		.BYTE	$08,$9E,$02,$0A
		.BYTE	$08,$9E,$42,$F2
		.BYTE	$E8,$88,$42,$06
		.BYTE	$E8,$98,$42,$FE
		.BYTE	$E8,$A8,$42,$F6
		.BYTE	$F8,$8A,$42,$06
		.BYTE	$F8,$9A,$42,$FE
		.BYTE	$F8,$AA,$42,$F6
_sprA1A_6F:
		.BYTE	$0C
		.BYTE	$08,$84,$02,$F2
		.BYTE	$08,$84,$42,$0A
		.BYTE	$08,$94,$02,$FA
		.BYTE	$08,$94,$42,$02
		.BYTE	$E8,$80,$02,$F2
		.BYTE	$E8,$80,$42,$0A
		.BYTE	$E8,$90,$02,$FA
		.BYTE	$E8,$90,$42,$02
		.BYTE	$F8,$82,$02,$F2
		.BYTE	$F8,$82,$42,$0A
		.BYTE	$F8,$92,$02,$FA
		.BYTE	$F8,$92,$42,$02
_sprA1A_70:
		.BYTE	$0A
		.BYTE	$08,$8C,$02,$FA
		.BYTE	$08,$9C,$02,$02
		.BYTE	$08,$9E,$02,$0A
		.BYTE	$08,$9E,$42,$F2
		.BYTE	$E8,$88,$02,$F6
		.BYTE	$E8,$98,$02,$FE
		.BYTE	$E8,$A8,$02,$06
		.BYTE	$F8,$8A,$02,$F6
		.BYTE	$F8,$9A,$02,$FE
		.BYTE	$F8,$AA,$02,$06
_sprA1A_71:
		.BYTE	$0C
		.BYTE	$08,$A4,$02,$02
		.BYTE	$08,$A4,$42,$FA
		.BYTE	$08,$B4,$02,$0A
		.BYTE	$08,$B4,$42,$F2
		.BYTE	$E8,$A0,$02,$02
		.BYTE	$E8,$A0,$42,$FA
		.BYTE	$E8,$B0,$02,$0A
		.BYTE	$E8,$B0,$42,$F2
		.BYTE	$F8,$A2,$02,$02
		.BYTE	$F8,$A2,$42,$FA
		.BYTE	$F8,$B2,$02,$0A
		.BYTE	$F8,$B2,$42,$F2
_sprA1A_72:
		.BYTE	$0A
		.BYTE	$08,$D0,$03,$F0
		.BYTE	$08,$E0,$03,$F8
		.BYTE	$E8,$80,$03,$E8
		.BYTE	$E8,$80,$43,$00
		.BYTE	$E8,$90,$03,$F0
		.BYTE	$E8,$90,$43,$F8
		.BYTE	$F8,$92,$03,$F0
		.BYTE	$F8,$92,$43,$F8
		.BYTE	$F8,$C0,$03,$00
		.BYTE	$F8,$C0,$43,$E8
_sprA1A_73:
		.BYTE	$06
		.BYTE	$00,$C2,$03,$F0
		.BYTE	$00,$D2,$03,$F8
		.BYTE	$F0,$80,$03,$E8
		.BYTE	$F0,$80,$43,$00
		.BYTE	$F0,$90,$03,$F0
		.BYTE	$F0,$90,$43,$F8
_sprA1A_74:
		.BYTE	$0A
		.BYTE	$08,$D0,$43,$08
		.BYTE	$08,$E0,$43,$00
		.BYTE	$E8,$80,$03,$F8
		.BYTE	$E8,$80,$43,$10
		.BYTE	$E8,$90,$03,$00
		.BYTE	$E8,$90,$43,$08
		.BYTE	$F8,$92,$03,$00
		.BYTE	$F8,$92,$43,$08
		.BYTE	$F8,$C0,$03,$10
		.BYTE	$F8,$C0,$43,$F8
_sprA1A_75:
		.BYTE	$06
		.BYTE	$00,$C2,$43,$08
		.BYTE	$00,$D2,$43,$00
		.BYTE	$F0,$80,$03,$F8
		.BYTE	$F0,$80,$43,$10
		.BYTE	$F0,$90,$03,$00
		.BYTE	$F0,$90,$43,$08
_sprA1A_76:
		.BYTE	$04
		.BYTE	$00,$36,$03,$00
		.BYTE	$00,$36,$43,$F8
		.BYTE	$F0,$A6,$03,$F8
		.BYTE	$F0,$A6,$43,$00
_sprA1A_77:
		.BYTE	$04
		.BYTE	$F0,$A6,$03,$F8
		.BYTE	$F0,$A6,$43,$00
		.BYTE	$00,$4E,$03,$F8
		.BYTE	$00,$4E,$43,$00
_sprA1A_78:
		.BYTE	$82
		.WORD	_sprA1A_77
		.WORD	_sprA1A_78_B
_sprA1A_78_B
		.BYTE	$02
		.BYTE	$F0,$58,$03,$F0
		.BYTE	$F8,$58,$03,$08
_sprA1A_79:
		.BYTE	$82
		.WORD	_sprA1A_77
		.WORD	_sprA1A_79_B
_sprA1A_79_B:
		.BYTE	$02
		.BYTE	$F0,$48,$03,$F0
		.BYTE	$F8,$48,$03,$08
_sprA1A_7A:
		.BYTE	$02
		.BYTE	$FC,$96,$01,$00
		.BYTE	$FC,$96,$01,$F8
_sprA1A_7B:
		.BYTE	$01
		.BYTE	$FC,$96,$01,$FC
_sprA1A_80:
		.BYTE	$02
		.BYTE	$F8,$86,$41,$00
		.BYTE	$F8,$86,$01,$F8
_sprA1A_81:
		.BYTE	$02
		.BYTE	$F8,$F0,$C1,$00
		.BYTE	$F8,$F0,$01,$F8
_sprA1A_82:
		.BYTE	$02
		.BYTE	$F8,$B6,$01,$F8
		.BYTE	$F8,$B6,$41,$00
_sprA1A_83:
		.BYTE	$02
		.BYTE	$F8,$F0,$41,$00
		.BYTE	$F8,$F0,$81,$F8
_sprA1A_84:
		.BYTE	$82
		.WORD	_sprA1A_84_A
		.WORD	_sprA1A_84_B
_sprA1A_84_A:
		.BYTE	$1B
		.BYTE	$05,$A8,$42,$07
		.BYTE	$06,$A8,$02,$F0
		.BYTE	$06,$B8,$02,$F8
		.BYTE	$06,$B8,$42,$00
		.BYTE	$14,$AA,$02,$F1
		.BYTE	$14,$AA,$42,$08
		.BYTE	$14,$BA,$02,$F8
		.BYTE	$14,$BA,$42,$00
		.BYTE	$18,$9A,$02,$E8
		.BYTE	$22,$9C,$02,$EA
		.BYTE	$22,$9C,$42,$10
		.BYTE	$22,$AC,$02,$F1
		.BYTE	$24,$AC,$42,$08
		.BYTE	$CC,$80,$02,$F8
		.BYTE	$CC,$80,$42,$00
		.BYTE	$CC,$A0,$02,$F0
		.BYTE	$CC,$A0,$42,$08
		.BYTE	$DA,$92,$02,$EC
		.BYTE	$DA,$92,$42,$0C
		.BYTE	$DC,$82,$02,$F8
		.BYTE	$DC,$82,$42,$00
		.BYTE	$DC,$A2,$02,$F1
		.BYTE	$DC,$A2,$42,$08
		.BYTE	$EA,$B4,$02,$F8
		.BYTE	$EA,$B4,$42,$00
		.BYTE	$EA,$DA,$02,$0B
		.BYTE	$EA,$DA,$42,$EE
_sprA1A_84_B:
		.BYTE	$04
		.BYTE	$F8,$B6,$02,$F8
		.BYTE	$F8,$B6,$42,$00
		.BYTE	$F8,$BE,$02,$07
		.BYTE	$F8,$BE,$42,$F1
_sprA1A_85:
		.BYTE	$82
		.WORD	_sprA1A_85_A
		.WORD	_sprA1A_84_B
_sprA1A_85_A:
		.BYTE	$16
		.BYTE	$03,$A8,$42,$07
		.BYTE	$04,$A8,$02,$F1
		.BYTE	$04,$B8,$02,$F8
		.BYTE	$04,$B8,$42,$00
		.BYTE	$11,$AA,$02,$F1
		.BYTE	$11,$AA,$42,$08
		.BYTE	$12,$BA,$02,$F8
		.BYTE	$12,$BA,$42,$00
		.BYTE	$1D,$9C,$02,$EA
		.BYTE	$1F,$9C,$42,$10
		.BYTE	$1F,$AC,$02,$F1
		.BYTE	$20,$AC,$42,$08
		.BYTE	$CE,$80,$02,$F8
		.BYTE	$CE,$80,$42,$00
		.BYTE	$DA,$92,$42,$08
		.BYTE	$DC,$92,$02,$F0
		.BYTE	$DE,$82,$02,$F8
		.BYTE	$DE,$82,$42,$00
		.BYTE	$EA,$DA,$02,$08
		.BYTE	$EA,$DA,$42,$F0
		.BYTE	$EC,$B4,$02,$F8
		.BYTE	$EC,$B4,$42,$00
_sprA1A_86:
		.BYTE	$0E
		.BYTE	$00,$C4,$02,$F0
		.BYTE	$00,$C4,$42,$08
		.BYTE	$00,$D4,$02,$F8
		.BYTE	$00,$D4,$42,$00
		.BYTE	$10,$C6,$02,$F0
		.BYTE	$10,$C6,$42,$08
		.BYTE	$10,$D6,$02,$F8
		.BYTE	$10,$D6,$42,$00
		.BYTE	$E0,$D0,$02,$F8
		.BYTE	$E0,$D0,$42,$00
		.BYTE	$F0,$C2,$02,$F0
		.BYTE	$F0,$C2,$42,$08
		.BYTE	$F0,$D2,$02,$F8
		.BYTE	$F0,$D2,$42,$00
_sprA1A_87:
		.BYTE	$0E
		.BYTE	$00,$E4,$02,$F0
		.BYTE	$00,$E4,$42,$08
		.BYTE	$00,$F4,$02,$F8
		.BYTE	$00,$F4,$42,$00
		.BYTE	$10,$E6,$02,$F0
		.BYTE	$10,$E6,$42,$08
		.BYTE	$10,$F6,$02,$F8
		.BYTE	$10,$F6,$42,$00
		.BYTE	$E0,$F0,$02,$F8
		.BYTE	$E0,$F0,$42,$00
		.BYTE	$F0,$E2,$02,$F0
		.BYTE	$F0,$E2,$42,$08
		.BYTE	$F0,$F2,$02,$F8
		.BYTE	$F0,$F2,$42,$00
_sprA1A_88:
		.BYTE	$0C
		.BYTE	$00,$FA,$82,$F8
		.BYTE	$00,$FA,$C2,$00
		.BYTE	$10,$FA,$82,$00
		.BYTE	$10,$FA,$82,$F0
		.BYTE	$10,$FA,$C2,$08
		.BYTE	$10,$FA,$C2,$F8
		.BYTE	$E0,$FA,$02,$F8
		.BYTE	$E0,$FA,$42,$00
		.BYTE	$F0,$EA,$02,$F0
		.BYTE	$F0,$EA,$42,$08
		.BYTE	$F0,$FA,$02,$F8
		.BYTE	$F0,$FA,$42,$00
_sprA1A_89:
		.BYTE	$01
		.BYTE	$F8,$8C,$01,$FC
_sprA1A_8A:
		.BYTE	$01
		.BYTE	$F8,$8C,$00,$FC
_sprA1A_8B:
		.BYTE	$01
		.BYTE	$F8,$8A,$01,$FC
_sprA1A_8C:
		.BYTE	$01
		.BYTE	$F8,$8A,$00,$FC
_sprA1A_8D:
		.BYTE	$02
		.BYTE	$F8,$88,$41,$00
		.BYTE	$F8,$88,$01,$F8
_sprA1A_8E:
		.BYTE	$02
		.BYTE	$F8,$88,$40,$00
		.BYTE	$F8,$88,$00,$F8
_sprA1A_8F:
		.BYTE	$02
		.BYTE	$F8,$98,$41,$00
		.BYTE	$F8,$98,$01,$F8
_sprA1A_90:
		.BYTE	$02
		.BYTE	$F8,$98,$40,$00
		.BYTE	$F8,$98,$00,$F8
_sprA1A_91:
		.BYTE	$02
		.BYTE	$F8,$9B,$00,$00
		.BYTE	$F8,$8B,$00,$F8
_sprA1A_92:
		.BYTE	$04
		.BYTE	$00,$D5,$00,$F8
		.BYTE	$00,$E5,$00,$00
		.BYTE	$F1,$C5,$00,$00
		.BYTE	$F1,$C5,$40,$F8
_sprA1A_93:
		.BYTE	$04
		.BYTE	$00,$E5,$00,$00
		.BYTE	$00,$E5,$40,$F8
		.BYTE	$F0,$C5,$00,$00
		.BYTE	$F0,$C5,$40,$F8
_sprA1A_94:
		.BYTE	$04
		.BYTE	$00,$D5,$40,$00
		.BYTE	$00,$E5,$40,$F8
		.BYTE	$F1,$C5,$00,$00
		.BYTE	$F1,$C5,$40,$F8

_sprB1A_C0:
		.BYTE	$85
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C0_B
		.WORD	_sprB1A_C0_C
		.WORD	_sprB1A_C0_D
		.WORD	_sprB1A_C0_E
_sprB1A_C1:
		.BYTE	$84
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C0_B
		.WORD	_sprB1A_C1_C
		.WORD	_sprB1A_C1_D
_sprB1A_C2:
		.BYTE	$82
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C2_B
_sprB1A_C3:
		.BYTE	$83
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C0_B
		.WORD	_sprB1A_C3_B
_sprB1A_C4:
		.BYTE	$82
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C4_B
_sprB1A_C5:
		.BYTE	$84
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C0_B
		.WORD	_sprB1A_C0_C
		.WORD	_sprB1A_C5_B
_sprB1A_C6:
		.BYTE	$84
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C0_B
		.WORD	_sprB1A_C0_D
		.WORD	_sprB1A_C6_B
_sprB1A_C7:
		.BYTE	$83
		.WORD	_sprB1A_C0_A
		.WORD	_sprB1A_C1_C
		.WORD	_sprB1A_C7_B
; NOTE: this is the only multiple chunked sprite in original game
; and because of sprite manager bug, it need to have adjusted
; Y position. when i fix the Y pos bug in sprite routine, i fixed
; Y here as well
_sprB1A_C0_A:
		.BYTE	$12
		.BYTE	$08,$A8,$02,$F0
		.BYTE	$08,$A8,$42,$08
		.BYTE	$08,$B8,$02,$F8
		.BYTE	$08,$B8,$42,$00
		.BYTE	$18,$9A,$02,$E8
		.BYTE	$18,$9A,$42,$10
		.BYTE	$18,$AA,$02,$F0
		.BYTE	$18,$AA,$42,$08
		.BYTE	$18,$BA,$02,$F8
		.BYTE	$18,$BA,$42,$00
		.BYTE	$28,$9C,$02,$E8
		.BYTE	$28,$9C,$42,$10
		.BYTE	$28,$AC,$02,$F0
		.BYTE	$28,$AC,$42,$08
		.BYTE	$C8,$A0,$02,$F0
		.BYTE	$C8,$A0,$42,$08
		.BYTE	$F8,$B6,$02,$F8
		.BYTE	$F8,$B6,$42,$00
_sprB1A_C0_B:
		.BYTE	$08
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$D8,$92,$42,$10
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$D8,$B2,$42,$00
_sprB1A_C0_C:
		.BYTE	$04
		.BYTE	$E8,$A4,$02,$F0
		.BYTE	$E8,$B4,$02,$F8
		.BYTE	$F8,$96,$02,$E8
		.BYTE	$F8,$A6,$02,$F0
_sprB1A_C0_D:
		.BYTE	$04
		.BYTE	$E8,$A4,$42,$08
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$F8,$96,$42,$10
		.BYTE	$F8,$A6,$42,$08
_sprB1A_C0_E:
		.BYTE	$04
		.BYTE	$E8,$84,$02,$E0
		.BYTE	$E8,$84,$42,$18
		.BYTE	$E8,$94,$02,$E8
		.BYTE	$E8,$94,$42,$10
_sprB1A_C1_C:
		.BYTE	$07
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
_sprB1A_C1_D:
		.BYTE	$01
		.BYTE	$E8,$B4,$02,$F8
_sprB1A_C2_B:
		.BYTE	$11
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$D8,$CC,$02,$00
		.BYTE	$D8,$DC,$02,$08
		.BYTE	$D8,$EC,$02,$10
		.BYTE	$E8,$B4,$02,$F8
		.BYTE	$E8,$C8,$42,$F0
		.BYTE	$E8,$CE,$02,$00
		.BYTE	$E8,$D8,$42,$E8
		.BYTE	$E8,$DE,$02,$08
		.BYTE	$E8,$EE,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$F8,$E8,$42,$F0
		.BYTE	$F8,$F8,$42,$E8
_sprB1A_C3_B:
		.BYTE	$08
		.BYTE	$E8,$8E,$02,$00
		.BYTE	$E8,$8E,$42,$F8
		.BYTE	$E8,$9E,$02,$08
		.BYTE	$E8,$9E,$42,$F0
		.BYTE	$E8,$AE,$02,$10
		.BYTE	$E8,$AE,$42,$E8
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$F8,$BE,$42,$F0
_sprB1A_C4_B:
		.BYTE	$11
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$92,$42,$10
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$D8,$CC,$42,$F8
		.BYTE	$D8,$DC,$42,$F0
		.BYTE	$D8,$EC,$42,$E8
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$C8,$02,$08
		.BYTE	$E8,$CE,$42,$F8
		.BYTE	$E8,$D8,$02,$10
		.BYTE	$E8,$DE,$42,$F0
		.BYTE	$E8,$EE,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$F8,$E8,$02,$08
		.BYTE	$F8,$F8,$02,$10
_sprB1A_C5_B:
		.BYTE	$06
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$84,$02,$E0
		.BYTE	$E8,$94,$02,$E8
_sprB1A_C6_B:
		.BYTE	$06
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$84,$42,$18
		.BYTE	$E8,$94,$42,$10
		.BYTE	$E8,$B4,$02,$F8
_sprB1A_C7_B:
		.BYTE	$09
		.BYTE	$C8,$80,$02,$F8
		.BYTE	$C8,$80,$42,$00
		.BYTE	$D8,$82,$02,$F8
		.BYTE	$D8,$82,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$D8,$92,$42,$10
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$E8,$B4,$02,$F8

		SECTION_END	"PRG3 SPRITES"

		BANK_END 3,$C000
