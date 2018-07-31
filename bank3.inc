
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

		SPR_LIB_START	_spr_libA08

		SPR_IDX	_sprA08_00	; catch, uses copies in CHR1 for every level
		SPR_IDX	_sprA08_01
		SPR_IDX	_sprA08_02
		SPR_IDX	_sprA08_03
		SPR_IDX	_sprA08_04	; lvl1 boss judges (CHR0 07, CHR1 none)
		SPR_IDX	_sprA08_05
		SPR_IDX	_sprA08_06
		SPR_IDX	_sprA08_07
		SPR_IDX	_sprA08_08
		SPR_IDX	_sprA08_09
		SPR_IDX	_sprA08_0A
		SPR_IDX	_sprA08_0B
		SPR_IDX	_sprA08_0C
		SPR_IDX	_sprA08_0D
		SPR_IDX	_sprA08_0E
		SPR_IDX	_sprA08_0F
		SPR_IDX	_sprA08_10
		SPR_IDX	_sprA08_11
		SPR_IDX	_sprA08_12
		SPR_IDX	_sprA08_13
		SPR_IDX	_sprA08_14
		SPR_IDX	_sprA08_15
		SPR_IDX	_sprA08_16
		SPR_IDX	_sprA08_17
		SPR_IDX	_sprA08_18
		SPR_IDX	_sprA08_19
		SPR_IDX	_sprA08_1A
		SPR_IDX	_sprA08_1B
		SPR_IDX	_sprA08_1C
		SPR_IDX	_sprA08_1D
		SPR_IDX	_sprA08_1E
		SPR_IDX	_sprA08_1F
		SPR_IDX	_sprA08_20
		SPR_IDX	_sprA08_21
		SPR_IDX	_sprA08_22
		SPR_IDX	_sprA08_23
		SPR_IDX	_sprA08_24
		SPR_IDX	_sprA08_25
		SPR_IDX	_sprA08_26
		SPR_IDX	_sprA08_27
		SPR_IDX	_sprA08_28
		SPR_IDX	_sprA08_29	; lvl2 boss train slime (CHR0 0C, CHR1 0A)
		SPR_IDX	_sprA08_2A
		SPR_IDX	_sprA08_2B
		SPR_IDX	_sprA08_2C
		SPR_IDX	_sprA08_2D
		SPR_IDX	_sprA08_2E
		SPR_IDX	_sprA08_2F
		SPR_IDX	_sprA08_30
		SPR_IDX	_sprA08_31
		SPR_IDX	_sprA08_32
		SPR_IDX	_sprA08_33
		SPR_IDX	_sprA08_34
		SPR_IDX	_sprA08_35
		SPR_IDX	_sprA08_36
		SPR_IDX	_sprA08_37
		SPR_IDX	_sprA08_38
		SPR_IDX	_sprA08_39
		SPR_IDX	_sprA08_3A
		SPR_IDX	_sprA08_3B	; lvl3 boss sewer dragons (CHR0 13, CHR1 none)
		SPR_IDX	_sprA08_3C
		SPR_IDX	_sprA08_3D
		SPR_IDX	_sprA08_3E
		SPR_IDX	_sprA08_3F
		SPR_IDX	_sprA08_40
		SPR_IDX	_sprA08_41
		SPR_IDX	_sprA08_42
		SPR_IDX	_sprA08_43
		SPR_IDX	_sprA08_44
		SPR_IDX	_sprA08_45
		SPR_IDX	_sprA08_46
		SPR_IDX	_sprA08_47
		SPR_IDX	_sprA08_48
		SPR_IDX	_sprA08_49
		SPR_IDX	_sprA08_4A
		SPR_IDX	_sprA08_4B
		SPR_IDX	_sprA08_4C
		SPR_IDX	_sprA08_4D
		SPR_IDX	_sprA08_4E
		SPR_IDX	_sprA08_4F
		SPR_IDX	_sprA08_50
		SPR_IDX	_sprA08_51
		SPR_IDX	_sprA08_52
		SPR_IDX	_sprA08_53
		SPR_IDX	_sprA08_54
		SPR_IDX	_sprA08_55
		SPR_IDX	_sprA08_56
		SPR_IDX	_sprA08_57
		SPR_IDX	_sprA08_58
		SPR_IDX	_sprA08_59
		SPR_IDX	_sprA08_5A	; lvl5 boss keykeeper (CHR0 18, CHR1 none)
		SPR_IDX	_sprA08_5B
		SPR_IDX	_sprA08_5C
		SPR_IDX	_sprA08_5D
		SPR_IDX	_sprA08_5E
		SPR_IDX	_sprA08_5F
		SPR_IDX	_sprA08_60
		SPR_IDX	_sprA08_61
		SPR_IDX	_sprA08_62
		SPR_IDX	_sprA08_63
		SPR_IDX	_sprA08_64
		SPR_IDX	_sprA08_65
		SPR_IDX	_sprA08_66
		SPR_IDX	_sprA08_67
		SPR_IDX	_sprA08_68
		SPR_IDX	_sprA08_69
		SPR_IDX	_sprA08_6A
		SPR_IDX	_sprA08_6B
		SPR_IDX	_sprA08_6C
		SPR_IDX	_sprA08_6D
		SPR_IDX	_sprA08_6E
		SPR_IDX	_sprA08_6F
		SPR_IDX	_sprA08_70
		SPR_IDX	_sprA08_71
		SPR_IDX	_sprA08_72
		SPR_IDX	_sprA08_73
		SPR_IDX	_sprA08_74
		SPR_IDX	_sprA08_75
		SPR_IDX	_sprA08_76
; NOTE: this is a floor phase for baby keykeeper after it fall down to the floor
; but script use only two next frames rendered this one unused.
		SPR_IDX	_sprA08_77	; unused
		SPR_IDX	_sprA08_78
		SPR_IDX	_sprA08_79
		SPR_IDX	_sprA08_7A
		SPR_IDX	_sprA08_7B
		SPR_IDX	_sprA08_80
		SPR_IDX	_sprA08_81
		SPR_IDX	_sprA08_82
		SPR_IDX	_sprA08_83
		SPR_IDX	_sprA08_80
		SPR_IDX	_sprA08_81
		SPR_IDX	_sprA08_82
		SPR_IDX	_sprA08_83
		SPR_IDX	_sprA08_84	; lvl6 boss vega dead phase (CHR0 17, CHR1 none)
		SPR_IDX	_sprA08_85
		SPR_IDX	_sprA08_86
		SPR_IDX	_sprA08_87
		SPR_IDX	_sprA08_88
		SPR_IDX	_sprA08_89
		SPR_IDX	_sprA08_8A
		SPR_IDX	_sprA08_8B
		SPR_IDX	_sprA08_8C
		SPR_IDX	_sprA08_8D
		SPR_IDX	_sprA08_8E
		SPR_IDX	_sprA08_8F
		SPR_IDX	_sprA08_90
		SPR_IDX	_sprA08_91	; ending cutscene sprites (CHR1 none, CHR1 16)
		SPR_IDX	_sprA08_92
		SPR_IDX	_sprA08_93
		SPR_IDX	_sprA08_94

		SPR_LIB_SIZE	_spr_libA08

		SPR_LIB_START	_spr_libB08

; NOTE: this is the only multiple chunked sprite in original game
; and because of sprite manager bug, it need to have adjusted
; Y position. when i fix the Y pos bug in sprite routine, i fixed
; Y here as well

		SPR_IDX	_sprB08_C0	; lvl6 boss vega main sprites (CHR0 17, CHR1 none)
		SPR_IDX	_sprB08_C1
		SPR_IDX	_sprB08_C2
		SPR_IDX	_sprB08_C3
		SPR_IDX	_sprB08_C4
		SPR_IDX	_sprB08_C5
		SPR_IDX	_sprB08_C6
		SPR_IDX	_sprB08_C7

		SPR_LIB_SIZE	_spr_libB08

#if SPR_SIZE_TEST==0
#if NEW_SPRITES==1
		INCLUDE		"../spr/spr_data2_new.inc"
#else
		INCLUDE		"../spr/spr_data2.inc"
#endif
#endif

		SECTION_END	"PRG3 SPRITES"

		BANK_END 3,$C000
