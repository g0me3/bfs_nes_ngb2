
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

		INCBIN "..\copyrights.txt"

		BANK_START $00

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr00_intro_title_select
; NOTE: if switch case index higher than maximum number of entries in table,
; then switch case skipped, so default branch is always just after the case
; but. there are scripts isn't using this method rather than using raw direct
; indexes and never skips the switch itself, so they may have any other data
; after case table instead of any actual code...
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$0C
		SCASE			_sub01_intro_slime				; 01
		SCASE			_sub02_intro_busterA			; 02
		SCASE			_sub03_intro_busterB			; 03
		SCASE			_sub04_intro_busterC			; 04
		SCASE			_sub05_intro_busterD			; 05
		SCASE			_sub06_select_peter				; 06
		SCASE			_sub07_select_ray				; 07
		SCASE			_sub08_select_egon				; 08
		SCASE			_sub09_select_winston			; 09
		SCASE			_sub0A_select_louis				; 0A
		SCASE			_intro_sub0B_title_ghost		; 0B
		SCASE			_intro_sub0C_title_new			; 0C

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_mcmp						; default case for script startup
			NARGW		_license_screen_display_flag	; check for special flag, set at reset
			NARGB		$01								; preventing from show license screens
		SBCC			_sloc_title_start				; after game over, if clear, jump to title
		STORE8			_license_screen_display_flag,$00; if set, clear it, then load first
		NJSR			_nsub_full_pal_fade_set			; do full palette fade
			NARGB		$FC								; $FC = fade out at max peed (sub 40)
		NJSR			_nsub_scroll_page_set			; set nt page
			NARGB		$00
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack HAL logo tilemap
			NARGB		_tlm8_HAL_idx
		NJSR			_nsub_mmc1_chr1_set				; set corresponding CHR bank
			NARGB		$1B
		NJSR			_nsub_bg_pal_load				; load actual palette into pal buf
			NARGW		_pal0
		SJSR			_ssub_pal_fade_in				; show the picture, wait for 90 frames (1.5 sec)
		SJSR			_ssub_skip_wait					; NEW, skip intro
		SJSR			_ssub_pal_fade_out				; shut down the picture
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; load new packed tilemap with license info
			NARGB		_tlm6_copyrights_idx
		NJSR			_nsub_mmc1_chr1_set				; CHR bank
			NARGB		$09
		NJSR			_nsub_bg_pal_load				; load another palette
;			NARGW		_pal1							; REDUNDANT: both palettes are the same
			NARGW		_pal0
; -
		SJSR			_ssub_pal_fade_in				; and again show it for 1.5 seconds
		SJSR			_ssub_skip_wait					; NEW, skip intro

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_title_restart:
		SJSR			_ssub_pal_fade_out

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sloc_title_start:
		NJSR			_nsub_apu_mus_load				; start title music theme
			NARGB		_mus5_idx
; NOTE: for some reason, this native subroutines just does write
; to the _chr_bank0/_chr_bank1 variables, why they need to set a separate
; function for that, if STORE8 opcode can be used instead? however
; this won't save us a byte, opcode sizes are the same... that would
; be useful if there is an opcode with offset to zero ram existed...
; or maybe an additional opcode may be assigned to set exactly chr banks
; which may be shorter (one 3-byte opcode or two 2-byte)
		NJSR			_nsub_mmc1_chr0_set				; set CHR for bg and sprites
			NARGB		$01
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack title screen frame window
			NARGB		_tlm0_title_screen_idx
		SJSR			_ssub_title_logo_init			; NEW, merged to common code routine
; NOTE: there is another NARGI macro to automaticly add "_idx" to mnemonics, but
; here for different switch cases we need to add +1 sometimes, so this may now
; work here or need assign another one macro.. too much macroses bad too, so let's
; just use the _idx postfix by now.
		NJSR			_nsub_new_thread_start			; load additional title script
			NARGB		_scr00_intro_title_select_idx	; technically the same
			NARGB		$00,$00							; _scr00_intro_title_select but with
			NARGB		_intro_sub0C_title_new_idx+1	; different switch case index: 0C
			NARGB		$00								; also indexes here are +1 by default
		POS_X_SET		0,$80,$00						; initialize title picture patch sprite
		POS_Y_SET		0,$88,$00						; with ghost's foot with no hole
		SPR_IDX_SET		1,$00							; the original tilemap for title has this hole
		SJSR			_ssub_pal_fade_in				; show the picture
		NBG_HNDL_SET	_nbgsub_title_input				; set the background handler for input tests
_sloc_title_loop:
		SDELAY			$3B								; here starting the main title loop
		SPR_IDX_INC		7								; after 1sec animate title sprite patch to show
		SPR_IDX_SET		2,$FF							; small hole for 3 frames (too small), then turn sprite off
		NJSR			_nsub_sarg01_load_data_ofs		; load animation sequence data pointer to SARG0/SARG1
			NARGW		_chain_title_anim_scripts_data
		SLOOP_BEGIN		$05								; load the current script 5 more times with different
		NJSR			_nsub_chain_thread_lib_load_enemy	; settings for every single instance. this includes position
		SLOOP_END										; offset, delay and an SJMP_SW index to each object
		SDELAY			$F0								; when scripts loaded, they run immediately. wait while they stop
		SJSR			_ssub_title_maskDB_fade_out		; now fade out middle part of the screen only
		SARG_SET		SARG2,$00						; while window is black, replace logo with title text
		SLOOP_BEGIN		$12
		NJSR			_nsub_tlm_raw_arg2_idx_line_draw
			NARGW		_tlm_title_text
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_title_attr_select1		; load second set of attrs
		NJSR			_nsub_hi_scores_display			; draw additional hi-scores
			NARGB		$0F,$0A
		NJSR			_nsub_full_pal_load				; load new palette for this portion
			NARGW		_pal3
		NJSR			_nsub_mmc1_chr1_set				; and change the CHR page, pages 00 and 09 shares
			NARGB		$09								; title curtain graphics, so nothing is changes there
		NJSR			_nsub_new_thread_start			; start new thread to display an additional
			NARGB		_scr00_intro_title_select_idx	; animated sprite object - small ghost in "stop" sign
			NARGB		$00,$00							; this object has limited lifetime and stopped
			NARGB		_intro_sub0B_title_ghost_idx+1	; automatically after about 10 seconds
			NARGB		$00
		SJSR			_ssub_title_maskDB_fade_in		; fade in palette for the center of the screen
		SSCRIPT1_SET	_scr_title_push_start_anim		; run secondary script to animate palette for "push start button"
		SDELAY			$F0								; just wait about 9 seconds
		SDELAY			$F0
		SDELAY			$67
		SSCRIPT1_OFF									; then kill the "push start button" animation
		NJSR			_nsub_full_pal_fade_set			; restore full palette
			NARGB		$00
		SJSR			_ssub_title_maskDB_fade_out		; and then fade it out
		SJSR			_ssub_title_logo_init			; NEW, merged to common code routine
		SPR_IDX_SET		1,$00							; restore "new" sprite
		SJSR			_ssub_title_maskDB_fade_in		; fade in and do loop
		SJMP			_sloc_title_loop

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_title_logo_init:
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$00
		NJSR			_nsub_full_pal_load				; load title palette
			NARGW		_pal2
		SARG_SET		SARG2,$00						; init one of internal tmp vars
		SLOOP_BEGIN		$12								; in this case this is a line counter
; NOTE: the lib tilemap seems can't draw smaller rects than the screen itself
; so they did such workaround for displaying the title graphics on the fly
;
		NJSR			_nsub_tlm_raw_arg2_idx_line_draw; draw tilemap of the title logo in
			NARGW		_tlm_title_logo					; the middle line by line...
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_title_attr_select0		; load one of two attributes data
		SRET											; for title screen, select with arg

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_skip_wait:
		SLOOP_BEGIN		$5A
		SDELAY			$01
		NJSR			_nsub_intro_skip
		SBCS_BREAK		_skip
		SLOOP_END
_skip:
		SRET

; =============== S C R I P T ==========================s====================
_scr_title_push_start_anim:
		SLOOP_BEGIN		$02								; just does masked fade for
		NJSR			_nsub_pal_fade_req_inc_by_mask	; particular palette entry
			NARGB		$40
		SDELAY			$04
		SLOOP_END
		SLOOP_BEGIN		$05
		NJSR			_nsub_pal_fade_req_dec_by_mask
			NARGB		$40
		SDELAY			$04
		SLOOP_END
		SLOOP_BEGIN		$03
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$40
		SDELAY			$04
		SLOOP_END
		SJMP			_scr_title_push_start_anim

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_title_maskDB_fade_out:
		SLOOP_BEGIN		$04								; masked fade out for middle part
		NJSR			_nsub_pal_fade_req_dec_by_mask	; of the title screen, excluding curtains
			NARGB		$DB
		SDELAY			$04
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_title_maskDB_fade_in:
		SLOOP_BEGIN		$04								; fade in the same area
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$DB
		SDELAY			$04
		SLOOP_END
		SRET

_chain_title_anim_scripts_data:
		.BYTE	_sub01_intro_slime_idx+1,	$00,$08,$60
		.BYTE	_sub02_intro_busterA_idx+1,	$00,$10,$20
		.BYTE	_sub03_intro_busterB_idx+1,	$F8,$10,$00
		.BYTE	_sub04_intro_busterC_idx+1,	$08,$10,$20
		.BYTE	_sub05_intro_busterD_idx+1,	$00,$10,$00

; NOTE: both palettes are the same for released versions, however, the prototype
; version uses different palettes, so they just not changed scripts but changed
; only palettes
_pal0:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00

; REDUNDANT, same pal removed, may be restored if different HAL logo is used
;_pal1:
;		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00
; -
_pal2:
		.BYTE	$0F,$30,$15,$29,$0F,$30,$01,$29,$0F,$21,$11,$01,$0F,$14,$10,$30
		.BYTE	$0F,$36,$1C,$0F,$0F,$30,$35,$0F,$0F,$30,$15,$29,$0F,$36,$2B,$0F
_pal3:
		.BYTE	$0F,$35,$15,$05,$0F,$25,$10,$00,$0F,$21,$11,$01,$0F,$30,$2A,$01
		.BYTE	$0F,$30,$15,$29,$0F,$30,$35,$0F,$0F,$30,$10,$00,$0F,$30,$2A,$01

; =============== S U B R O U T I N E ======n================================
; NEW, helper skip input test for intro
;
_nsub_intro_skip:
		LDA		_pad0_pressed
		AND		#PAD_START|PAD_A
		BEQ		locret_853A
		SEC
		RTS
locret_853A:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nbgsub_title_input:
		LDA		_pad0_pressed				; this is native background routine for
		AND		#PAD_START					; NEW, now both buttons are available
		BEQ		locret_8539					; additionally for A+B held
		LDA		_pad0_held
		AND		#PAD_A|PAD_B
		CMP		#PAD_A|PAD_B
		BNE		loc_8534					; if true, restart current thread with
		JSR		_cur_thread_reload_param	; secret menu script
		.WORD	_scr_secret_menu
		RTS
loc_8534:
		JSR		_cur_thread_reload_param	; if false, restart this thread with
		.WORD	_scr_select_busters			; busters select script
locret_8539:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_title_attr_select0:
		JSR		_ppu_res_send_param			; script directly using script commands...
		.WORD	_attr_title0
		RTS
loc_8545:

_attr_title0:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$0A,$5A,$5A,$5A,$5A,$5A,$AA
		.BYTE	$AA,$00,$05,$05,$05,$05,$05,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$00,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$00,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$00,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A

; =============== S U B R O U T I N E ======n================================
_nsub_title_attr_select1:
		JSR		_ppu_res_send_param
		.WORD	_attr_title1
		RTS

; NOTE: there is no point in sending attrs in rectangular format, we may send it as raw 64x1 line as well (up to 127 allowed)
;
_attr_title1:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$0A,$0A,$0A,$0A,$0A,$0A,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$0F,$AA
		.BYTE	$AA,$00,$C0,$F0,$F0,$30,$00,$AA
		.BYTE	$AA,$00,$00,$00,$10,$51,$00,$AA
		.BYTE	$AA,$C0,$F5,$F5,$F5,$F5,$31,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A

; =============== S C R I P T ==========================s====================
_sub01_intro_slime:
		SSCRIPT1_SET	_scr_intro_slime_anim			; run additionall parallel script for
		POS_Y_DELTA_SET 6,$00,$01						; this object, while main script just
		POS_Y_DELTA_SET 0,$80,$00						; set the moving parameters and then
		SDELAY			$C8								; wait before stop
		SSTOP

; NOTE: don't know why they decided to use secondary script for some kind of
; work, since there is possible to do that in regular script form using loops
; which is actually used in many other times using loops/delays and delayed
; commands... probably this looks simplier.
;
; =============== S C R I P T ==========================s====================
_scr_intro_slime_anim:
		SPR_IDX_SET		6,$02							; secondary slime script for sprite
		SPR_IDX_INC		6								; animation. when main script
		SJMP			_scr_intro_slime_anim			; stops, this will disable as well

; =============== S C R I P T ==========================s====================
_sub02_intro_busterA:
		SPR_IDX_SET		0,$04

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sloc_intro_busters_delay:
		POS_Y_DELTA_SET 0,$00,$02
		SDELAY			$0C

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
; all intro busters animations are the same difference only in initial sprite index
; and an appearance delay, every single buster script also set the starting position
;
_sloc_intro_busters_no_delay:
		SPR_IDX_INC		0								; +1 (5)
		POS_MOVE_STOP	0
		SDELAY			$10
		POS_Y_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$06								; loop 6-5-7-5... period
		SPR_IDX_INC		6								; +1 (6)
		SPR_IDX_DEC		6								; -1 (5)
		SPR_IDX_ADD_IMM 6,$02							; +2 (7)
		SPR_IDX_ADD_IMM 6,$FE							; -2 (5)
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_sub03_intro_busterB:
		SPR_IDX_SET		0,$10
		POS_X_DELTA_SET 0,$40,$FF
		SJMP			_sloc_intro_busters_delay

; =============== S C R I P T ==========================s====================
_sub04_intro_busterC:
		SPR_IDX_SET		0,$1C
		POS_X_DELTA_SET 0,$C0,$00
		SJMP			_sloc_intro_busters_delay

; =============== S C R I P T ==========================s====================
_sub05_intro_busterD:
		SPR_IDX_SET		0,$28
		POS_Y_DELTA_SET 0,$00,$02
		SDELAY			$0A
		SJMP			_sloc_intro_busters_no_delay

; =============== S C R I P T ==========================s====================
_intro_sub0B_title_ghost:
		POS_X_SET		0,$80,$00						; animation loop for small ghost
		POS_Y_SET		0,$68,$00						; showing "victory" on the second
		SLOOP_BEGIN		$05								; text portion of the title screen
		SPR_IDX_SET		0,$46							; spr 46 start, repeat 6 times
		SDELAY			$20
		SPR_IDX_INC		6								; +1 (47)
		SPR_IDX_INC		6								; +1 (48)
		SPR_IDX_INC		6								; +1 (49)
		SPR_IDX_INC		0								; +1 (4A)
		SDELAY			$10
		SPR_IDX_INC		0								; +1 (4B)
		SDELAY			$20
		SPR_IDX_DEC		7								; -1 (4A)
		SPR_IDX_DEC		6								; -1 (49)
		SPR_IDX_DEC		6								; -1 (48)
		SPR_IDX_DEC		6								; -1 (47)
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_intro_sub0C_title_new:
		POS_X_SET		0,$30,$00						; set "NEW" sprite position
		POS_Y_SET		0,$20,$00
		SPR_IDX_SET		0,$4C							; select sprite index from lib00
_sloc_8A65:
		SARG_SET		SARG0,$00						; init tmp counter var
		SLOOP_BEGIN		$06
		NJSR			_nsub_patch_pal_blink			; read pal byte from selected array
			NARGW		_pal_new_blink					; with index SARG0, put it on
			NARGB		$16,SARG0						; selected position of palette buffer (16),
		SARG_ALU		SARG0,_ADC,$01					; then blit it and increment idx
		SDELAY			$01								; sync to fluch buffers, loop 6 times
		SLOOP_END
		SJMP			_sloc_8A65						; repeat infinitely

_pal_new_blink:
		.BYTE	$35,$25,$15,$05,$15,$25

; =============== S C R I P T ==========================s====================
; REDUNDANT: same blinking routine intended to blink black letters of the same "NEW"
; sprite instead of pink border. it uses different SARG1 variable for some reason
; but since it goes to infinite loop as well, they planned to run it separately
; in some unknown cases.
;
;_intro_sub0C_title_new_unref:
;		SARG_SET		SARG1,$00
;		SLOOP_BEGIN		$06
;		NJSR			_nsub_patch_pal_blink
;			NARGW		_pal_new_blink_unused
;			NARGB		$17,SARG1
;		SARG_ALU		SARG1,_ADC,$01
;		SDELAY			$01
;		SLOOP_END
;		SJMP			_intro_sub0C_title_new_unref
;
;_pal_new_blink_unused:
;		.BYTE	$0F,$10,$20,$30,$20,$10,$01

; =============== S U B R O U T I N E ======n================================
_nsub_patch_pal_blink:
		JSR		_scr_getc					; this is custom palette blink routine used
		STA		_ptr06						; only for this place... in other cases they
		JSR		_scr_getc					; used common pal fade _nsub routine with
		STA		_ptr06+1					; mask arguments...
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		TAY
		LDA		_trds_args_ptrs_lo,Y
		STA		_ptr08
		LDA		_trds_args_ptrs_hi,Y
		STA		_ptr08+1
		LDY		_cur_trd_slot
		LDA		(_ptr08),Y
		TAY
		LDA		(_ptr06),Y
		STA		_pal_buf,X
		JMP		_full_pal_fade

; =============== S C R I P T ==========================s====================
; this script replaces the main thread's 00 script at slot 00 when you press
; START at the title.
;
_scr_select_busters:
		SJSR			_ssub_pal_fade_out				; NEW: moved from redundant helper
		NJSR			_nsub_all_threads_off_except_cur; disable all other thread leftovers
		NJSR			_nsub_mmc1_mirror_horizontal	; the rest is usual screen preparations
		NJSR			_nsub_far_prg0_tlm_lib_unpack
			NARGB		_tlm2_busterselect_idx
		NJSR			_nsub_mmc1_mirror_vertical
		NJSR			_nsub_full_pal_load
			NARGW		_pal_select_busters
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$06
		STORE8			_beamer_spr_base_tmp,$FF		; no players selected yet, reset
		STORE8			_catcher_spr_base_tmp,$FF
		STORE8			_cur_room_x_pageA,$00			; these vars used here as a temp veriables
		STORE8			_cur_room_x_pageB,$00			; not by its ingame meanings
		POS_X_SET		0,$00,$01						; main offset for screen objects here
; NOTE: here script loads the selection screen objects, each object loaded from library
; and derived the current library index 00, so all following scripts will load with
; _scr00_intro_title_select script at start but will use the rest of its internal SWITCH
; case table indexes: 06-0A. current script still running at slot 00.
;
		NJSR			_nsub_sarg01_load_data_ofs
			NARGW		_select_buster_chain_scripts
; NOTE: this routine mainly used in ending sequence to fetch continuosly object
; for every single staff screen. here just some kind of hacky reuse of it... wouldn't
; here be easier to set one single _nsub routine with offset to data in argument or even
; with all data after it? maybe it is easier to merge some code to have two sets
; of such routines...
		SLOOP_BEGIN		$05
		NJSR			_nsub_chain_thread_lib_load_enemy
		SLOOP_END
		SJSR			_ssub_pal_fade_in				; finally preparations is done,
		NJSR			_nsub_apu_mus_load				; show the screen and play the music
			NARGB		_mus1_idx
		SARG_SET		SARG0,$00						; init tmp index
_sloc_8B3D:
		SDELAY			$01
		NJSR			_nsub_mtest_bit0				; animated objects are working now,
			NARGW		_cur_room_x_pageA				; will wait for it's over and flag raized
		SBCC			_sloc_8B3D						; if set, we'll start input handling
		NJSR			_nsub_select_buster_input		; loop until selection is complete
		SBCC			_sloc_8B3D
_sloc_8B4D:
		SDELAY			$01								; now the same for second player
		NJSR			_nsub_mtest_bit0				; wait for animations in over again
			NARGW		_cur_room_x_pageA				; and run input handler
		SBCC			_sloc_8B4D
		NJSR			_nsub_select_buster_input
		SBCC			_sloc_8B4D
_sloc_8B5D:
		SDELAY			$01								; when both players selected, wait
		NJSR			_nsub_mtest_bit0				; for animation is over again, this
			NARGW		_cur_room_x_pageB				; and pole slide animation is started
		SBCC			_sloc_8B5D						;(_cur_room_x_pageB = 1 is set then)
		SDELAY			$5A								; main script just has to wait
		SLOOP_BEGIN		$04								; and then fade out the screen
		NJSR			_nsub_pal_fade_req_dec_by_mask	; asyncronously.
			NARGB		$FF
		SDELAY			$08
		SLOOP_END
		NJSR			_nsub_players_idx_init			; final initializations of game vars
		SSTOP

_select_buster_chain_scripts:
		.BYTE	_sub06_select_peter_idx+1,	$00,$F8,$00
		.BYTE	_sub07_select_ray_idx+1,	$18,$F8,$00
		.BYTE	_sub08_select_egon_idx+1,	$30,$F8,$00
		.BYTE	_sub09_select_winston_idx+1,$48,$F8,$00
		.BYTE	_sub0A_select_louis_idx+1,	$E0,$40,$00
_pal_select_busters:
		.BYTE	$0F,$00,$16,$07,$0F,$10,$00,$07,$0F,$27,$17,$07,$0F,$30,$0F,$0F
		.BYTE	$0F,$36,$1C,$0F,$0F,$0F,$0F,$0F,$0F,$30,$0F,$0F,$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nsub_players_idx_init:
		LDY		_beamer_spr_base_tmp
		LDA		byte_8BC3,Y
		STA		_beamer_spr_base_tmp
		STA		_beamer_spr_base
		LDY		_catcher_spr_base_tmp
		LDA		byte_8BC3,Y
		STA		_catcher_spr_base_tmp
		STA		_catcher_spr_base
		RTS
byte_8BC3:
		.BYTE	$00,$10,$20,$30,$40

; =============== S U B R O U T I N E ======n================================
_nsub_select_buster_input:
		LDX		_cur_trd_slot
		LDA		_pad0_pressed				; test for L/R buttons press
		AND		#PAD_R
		BEQ		loc_8BE6
		LDA		#_snd0B_idx
		JSR		_far_prg6_apu_snd_load
loc_8BD5:
		INC		_trds_args0,X				; increment current selection index
		LDA		_trds_args0,X
		CMP		#$05
		BCC		loc_8BE1
		LDA		#$00
		STA		_trds_args0,X
loc_8BE1:
		CMP		_beamer_spr_base_tmp		; skip if first player already selected
		BEQ		loc_8BD5					; jump to increment one more time
loc_8BE6:
		LDA		_pad0_pressed
		AND		#PAD_L
		BEQ		loc_8C00
		LDA		#_snd0B_idx
		JSR		_far_prg6_apu_snd_load
loc_8BF1:
		DEC		_trds_args0,X				; same but for decrement
		BPL		loc_8BF9
		LDA		#$04
		STA		_trds_args0,X
loc_8BF9:
		LDA		_trds_args0,X
		CMP		_beamer_spr_base_tmp
		BEQ		loc_8BF1
loc_8C00:
		LDA		_pad0_pressed				; select with A
		AND		#PAD_START|PAD_A			; NEW, also here
		BEQ		loc_8C36
		LDA		#_snd0C_idx
		JSR		_far_prg6_apu_snd_load		; init one of two players indexes
		LDA		_trds_args0,X
		LDY		_beamer_spr_base_tmp
		BPL		loc_8C17
		STA		_beamer_spr_base_tmp
		BMI		loc_8C1A
loc_8C17:
		STA		_catcher_spr_base_tmp
loc_8C1A:
		LDA		#$FF
		STA		_obj_spr_idx,X				; disable obj name sprite, jump to
		LDA		#$00						; next object
		STA		_cur_room_x_pageA
loc_8C23:
		INC		_trds_args0,X
		LDA		_trds_args0,X
		CMP		#$05
		BCC		loc_8C2F
		LDA		#$00
		STA		_trds_args0,X
loc_8C2F:
		CMP		_beamer_spr_base_tmp
		BEQ		loc_8C23
		SEC									; when selection is done, set carry to
		RTS									; signal the main code to do next part
loc_8C36:
		LDY		_trds_args0,X				; display the name sprite for currently
		LDA		byte_8C51,Y					; highlighted player
		STA		_obj_x_pos_lo,X
		LDA		byte_8C56,Y
		STA		_obj_y_pos_lo,X
		LDA		#$00
		STA		_obj_x_pos_hi,X
		STA		_obj_y_pos_hi,X
		TYA
		CLC
		ADC		#$40
		STA		_obj_spr_idx,X
		RTS

byte_8C51:
		.BYTE	$68,$80,$98,$B0,$E0
byte_8C56:
		.BYTE	$70,$70,$70,$70,$B0

; =============== S C R I P T ==========================s====================
; PETER
_sub06_select_peter:
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$08						; set default left-oriented sprite for this object
		SPR_IDX_SET		0,$09							; set current anim walk start sprite
		SJSR			_ssub_select_busters
		SUSPEND

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_select_busters:
		POS_X_DELTA_SET 0,$00,$FC						; first animate the entry of 4 busters
		SDELAY			$20								; horizontally left without walk anim
		SPR_IDX_ADD_IMM 3,$FE							; turn face to the screen while slowdown
		POS_X_DELTA_SET 0,$00,$FE						; step by step in 14 frames
		SDELAY			$03
		POS_X_DELTA_SET 0,$00,$FF
		SDELAY			$04
		POS_X_DELTA_SET 0,$80,$FF
		SDELAY			$03
		POS_X_DELTA_SET 0,$E0,$FF
		SDELAY			$04
		POS_MOVE_STOP	0								; stop move
		SPR_IDX_ADD_IMM 0,$FE							; change sprite to step forward
		SDELAY			$0F								; and move vertically down a little
		POS_Y_DELTA_SET 0,$00,$01
		SDELAY			$04
		SPR_IDX_INC		4								; return standing anim
		SPR_IDX_DEC		0
		POS_MOVE_STOP	0								; stop again
		SLOOP_BEGIN		$02								; and then walk a little at the same pos
		SDELAY			$04
		SPR_IDX_ADD_IMM 4,$02
		SPR_IDX_ADD_IMM 4,$FE
		SPR_IDX_INC		4
		SPR_IDX_DEC		0
		SLOOP_END
		STORE8			_cur_room_x_pageA,$01			; now enable selection input
_sloc_8D0C:
		SDELAY			$01								; common portion for any object
		NJSR			_nsub_is_beamer_selected
		SBCC			_sloc_8D0C						; wait if select is done
		NJSR			_nsub_is_cur_buster_select_for_beam_player
		SBCS			_sloc_beamer_selected			; then test if this object selected
_sloc_8D1A:
		SDELAY			$01								; for both players one by one
		NJSR			_nsub_is_catcher_selected
		SBCC			_sloc_8D1A
		NJSR			_nsub_is_cur_buster_select_for_catch_player
		SBCS			_sloc_catcher_selected
		SUSPEND
_sloc_beamer_selected:									; here is common beginning for step out
		SJSR			_ssub_buster_selected_step_out	; of selected regular busters
		SPR_IDX_ADD_IMM 0,$03

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
; here is common walk to pole anim for selected beam player
_scr_beamer_walk_common:
		POS_X_DELTA_SET 0,$00,$FF						; move left init
		SSCRIPT1_SET	_scr_buster_walk_left_anim		; load secondary script for walk anim
_sloc_8D35:
		SDELAY			$01
		NJSR			_nsub_cur_pos_x_lo_icmp			; move left to x=50
			NARGB		$50
		SBCC			_sloc_8D35
		SSCRIPT1_OFF									; stop animation
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1							; get sprite index for stand anim loaded
		POS_MOVE_STOP	0								; at the thread start in SARG1
		STORE8			_cur_room_x_pageA,$01			; raise anim busy flag
_sloc_8D49:
		SDELAY			$01								; first selected player must wait until
		NJSR			_nsub_mtest_bit0				; second player is step aside
			NARGW		_cur_room_x_pageB				; when this occurs, the flag riased
		SBCC			_sloc_8D49
		POS_X_DELTA_SET 0,$00,$FE						; finally start the pole jump up animation
		POS_Y_DELTA_SET 0,$00,$FE						; move up left
		SDELAY			$0C
		POS_MOVE_STOP	0
		SCRL_Y_MOVE_SET 0,$00,$02						; adjust scroll pos

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_nsub_buster_slide_down:
		POS_Y_DELTA_SET 0,$00,$02						; then setup constant scroll move down
		SPR_IDX_ADD_IMM 0,$03							; busters jump up on the pole by linear
		SDELAY			$05								; path, not ballistic. just touch the pole
		SPR_IDX_INC		0								; then and go down
		SDELAY			$05
		SPR_IDX_ADD_IMM 0,$03							; here is the trick to hide object while
		SDELAY			$05								; sliding throught the floor. after a while
		SPR_IDX_SET		0,$FF							; it disables the sprite but object continues
		SDELAY			$19								; to move down. when he about to appear below
		SPR_IDX_SET		0,$45							; draw small dummy sprite representing FOOT
		SDELAY			$05								; show it for some time
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; then load an actual sprite
			NARGB		SARG1							; and continue to animate it... very tricky
		SPR_IDX_ADD_IMM 0,$03							; but no need to make additional clipping!
; NOTE: this looks very funny in slo-mo when only the ass appears from below and move for some
; pixels down alone lol. then the whole sprite appears.
_sloc_8D7B:
		SDELAY			$08								; continue sliding till the end of second page
		SLOOP_BEGIN		$03								; the main script will control the timing
		SPR_IDX_INC		0
		SDELAY			$08
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$FD
		SJMP			_sloc_8D7B

; =============== S C R I P T ==========================s====================
_sloc_catcher_selected:
		SJSR			_ssub_buster_selected_step_out
		SPR_IDX_ADD_IMM 0,$03

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_catcher_walk_common:
		POS_X_DELTA_SET 0,$00,$FF						; same start as for catch player, but...
		SSCRIPT1_SET	_scr_buster_walk_left_anim
_sloc_8D94:
		SDELAY			$01
		NJSR			_nsub_cur_pos_x_lo_icmp			; he must stop earlier, at x=68
			NARGB		$68								; REDUNDANT: same loop as for beamer
		SBCC			_sloc_8D94
_sloc_8DA0:
		STORE8			_cur_room_x_pageB,$01			; ok, second player is ready, start to slide down
_sloc_8DA4:
		SDELAY			$01
		NJSR			_nsub_cur_pos_x_lo_icmp			; while first player is jumping up, he need
			NARGB		$50								; to reach the same position x=50 first
		SBCC			_sloc_8DA4
		SSCRIPT1_OFF									; now walk is over, start to jump up
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		POS_MOVE_STOP	0
		SDELAY			$02								; set the same move direction, animate
		POS_X_DELTA_SET 0,$00,$FE
		POS_Y_DELTA_SET 0,$00,$FE
		SDELAY			$0C
		POS_MOVE_STOP	0								; stop on the pole, then jump on common code
		SJMP			_nsub_buster_slide_down

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_buster_selected_step_out:
		POS_Y_DELTA_SET 0,$00,$01						; every buster must step out of the line
		SLOOP_BEGIN		$02								; setup y speed and walk anim, run
		SDELAY			$04
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SPR_IDX_ADD_IMM 0,$FE
		SLOOP_END
		POS_MOVE_STOP	0								; all animations uses frame based timings
		SRET

; =============== S C R I P T ==========================s====================
_scr_buster_walk_left_anim:
		SDELAY			$04								; secondary thread for constant walking animation
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SPR_IDX_ADD_IMM 0,$FE
		SJMP			_scr_buster_walk_left_anim

; =============== S U B R O U T I N E ======n================================
_nsub_is_beamer_selected:
		LDA		_beamer_spr_base_tmp		; names are selfexplanatory here and below
		BPL		loc_8DE4
		CLC
		RTS
loc_8DE4:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_cur_buster_select_for_beam_player:
		LDX		_cur_trd_slot
		LDA		_beamer_spr_base_tmp
		CMP		_trds_args0,X
		BEQ		loc_8DF1
		CLC
		RTS
loc_8DF1:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_catcher_selected:
		LDA		_catcher_spr_base_tmp
		BPL		loc_8DFA
		CLC
		RTS
loc_8DFA:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_cur_buster_select_for_catch_player:
		LDX		_cur_trd_slot
		LDA		_catcher_spr_base_tmp
		CMP		_trds_args0,X
		BEQ		loc_8E07
		CLC
		RTS
loc_8E07:
		SEC
		RTS

; =============== S C R I P T ==========================s====================
; RAY
_sub07_select_ray:
		SARG_SET		SARG0,$01
		SARG_SET		SARG1,$2C						; final sprite index for object as well
		SPR_IDX_SET		0,$2D
		SJMP			_ssub_select_busters

; =============== S C R I P T ==========================s====================
; EGON
_sub08_select_egon:
		SARG_SET		SARG0,$02
		SARG_SET		SARG1,$14						; the same for all busters here
		SPR_IDX_SET		0,$15
		SJMP			_ssub_select_busters

; =============== S C R I P T ==========================s====================
; WINSTON
_sub09_select_winston:
		SARG_SET		SARG0,$03
		SARG_SET		SARG1,$20
		SPR_IDX_SET		0,$21
		SJMP			_ssub_select_busters

; =============== S C R I P T ==========================s====================
; LOUIS
_sub0A_select_louis:
		SARG_SET		SARG0,$04						; this object has no animation on start
		SARG_SET		SARG1,$38						; so it have it's own script handler
		SPR_IDX_SET		0,$34
_sloc_8E32:
		SDELAY			$01								; wait for beam player selected in main thread
		NJSR			_nsub_is_beamer_selected
		SBCC			_sloc_8E32						; then there are two options
		NJSR			_nsub_is_cur_buster_select_for_beam_player
		SBCS			_sloc_8E4F
_sloc_8E40:
		SDELAY			$01								; here goes if buster not selected as beam player
		NJSR			_nsub_is_catcher_selected
		SBCC			_sloc_8E40						; then we just wait for chatch player selection
		NJSR			_nsub_is_cur_buster_select_for_catch_player
		SBCS			_sloc_8E55						; again two options
		SUSPEND											; suspend, if buster not selected for anything
_sloc_8E4F:												; here goes if buster were selected for beam player
		SJSR			_ssub_louis_selected_base_anim
		SJMP			_scr_beamer_walk_common
_sloc_8E55:												; here goest if buster were selected for catch player
		SJSR			_ssub_louis_selected_base_anim
		SJMP			_scr_catcher_walk_common

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_louis_selected_base_anim:
		POS_X_DELTA_SET 0,$00,$FF						; first part of louis path common for any selection
		SLOOP_BEGIN		$02								; move left,
		SPR_IDX_SET		4,$38
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SLOOP_END
		POS_MOVE_STOP	0
		POS_Y_DELTA_SET 0,$00,$FF						; move up,
		SLOOP_BEGIN		$02
		SPR_IDX_SET		4,$35
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$38							; prepare to move left to finish
		SRET

; =============== S C R I P T ==========================s====================
_scr_secret_menu:
		SJSR			_ssub_pal_fade_out				; NEW: moved from redundant helper
		NJSR			_nsub_secret_menu_init			; init menu variables
		NJSR			_nsub_all_threads_off_except_cur; kill all leftover threads
		NJSR			_nsub_apu_mus_load				; music stop
			NARGB		$FF
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack menu tilemap
			NARGB		_tlm9_secret_menu_idx
		NJSR			_nsub_menu_init_draw			; update dynamic info
		NJSR			_nsum_menu_option_attr_highlight; set highlight to default option
		NJSR			_nsub_mmc1_chr1_set				; CHR setup
			NARGB		$05
		NJSR			_nsub_bg_pal_load				; also palette
			NARGW		_pal_secret_menu
		SJSR			_ssub_pal_fade_in				; show screen
		NBG_HNDL_SET	_nbgsub_secret_menu_exit_wait	; load native bg input
_sloc_8F5C:
		SDELAY			$01								; go main menu loop
		NJSR			_nsub_secret_menu_UD_input		; input separated in three subs
		NJSR			_nsub_secret_menu_LR_input		; for hor/vert/AB buttons
		NJSR			_nsub_secret_menu_AB_input
		SJMP			_sloc_8F5C

_pal_secret_menu:
		.BYTE	$0F,$11,$11,$11,$0F,$30,$30,$30,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_secret_menu_exit_wait:
		LDA		_pad0_pressed				; background native sub to wait
		AND		#PAD_START					; if START is pressed
		BEQ		locret_8FAA
		LDX		_menu_controls_idx			; apply changes to the game vars
		LDA		_ab_controls_,X
		STA		_control_beam_button_code
		LDA		_ba_controls_,X
		STA		_control_catch_button_code
		LDA		_menu_difficulty_idx
		STA		_difficulty
		LDA		#$FF
		JSR		_far_prg6_apu_mus_load		; if sound test used, shut all sounds
		LDA		#$FF
		JSR		_far_prg6_apu_snd_load
		JSR		_cur_thread_reload_param	; load intro script again starting
		.WORD	_scr_title_restart			; directly from title screen
locret_8FAA:
		RTS

_ab_controls_:
		.BYTE	PAD_A,PAD_B
_ba_controls_:
		.BYTE	PAD_B,PAD_A

; =============== S U B R O U T I N E ======n================================
_nsub_secret_menu_init:
		LDX		#$00
		STX		_cur_room_doors_cnt			; this var used here as a menu index
		STX		_menu_controls_idx
		STX		_sound_test_mus_idx
		STX		_sound_test_snd_idx
		INX
		STX		_menu_difficulty_idx
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_secret_menu_UD_input:
		LDA		_pad0_pressed
		AND		#PAD_U
		BEQ		loc_8FD4
		LDA		_cur_room_doors_cnt
		SEC
		SBC		#$01
		BPL		loc_8FE6
		LDA		#$03
		BNE		loc_8FE6
loc_8FD4:
		LDA		_pad0_pressed
		AND		#PAD_D
		BEQ		locret_8FEC
		LDA		_cur_room_doors_cnt
		CLC
		ADC		#$01
		CMP		#$04
		BCC		loc_8FE6
		LDA		#$00
loc_8FE6:
		STA		_cur_room_doors_cnt
		JMP		_nsum_menu_option_attr_highlight
locret_8FEC:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsum_menu_option_attr_highlight:
		JSR		_ppu_res_send_param_repeat
		.WORD	_res_attr_clear
		JSR		_wait_for_nmi
		LDX		_cur_room_doors_cnt
		LDA		_attr_option_lib,X
		LDY		off_900D,X
		JSR		_ppu_res_send_ptr_repeat
		JMP		_wait_for_nmi

; NOTE: weird, this should clear attrs for nt0, but starts 8 bytes later
; so will erase first 8 bytes of nt1 as well. why?
_res_attr_clear:
		.WORD	$23C8
		.BYTE	$20,$02,$00
_attr_option_lib:
		.BYTE	<[_res_attr_option0]
		.BYTE	<[_res_attr_option1]
		.BYTE	<[_res_attr_option2]
		.BYTE	<[_res_attr_option3]
off_900D:
		.BYTE	>[_res_attr_option0]
		.BYTE	>[_res_attr_option1]
		.BYTE	>[_res_attr_option2]
		.BYTE	>[_res_attr_option3]
_res_attr_option0:
		.WORD	$23C8
		.BYTE	$08,$01,$55
_res_attr_option1:
		.WORD	$23D0
		.BYTE	$18,$01,$55
_res_attr_option2:
		.WORD	$23E8
		.BYTE	$08,$01,$05
_res_attr_option3:
		.WORD	$23E8
		.BYTE	$08,$01,$50

; =============== S U B R O U T I N E ======n================================
_nsub_secret_menu_LR_input:
		LDX		_cur_room_doors_cnt
		LDA		_pad0_pressed
		AND		#PAD_L
		BEQ		loc_903B
		LDA		_menu_controls_idx,X
		SEC
		SBC		#$01
		BPL		loc_9050
		LDA		_menu_controls_max_val_list,X
		BNE		loc_9050
loc_903B:
		LDA		_pad0_pressed
		AND		#PAD_R
		BEQ		locret_9056
		LDA		_menu_controls_idx,X
		CLC
		ADC		#$01
		CMP		_menu_controls_max_val_list,X
		BCC		loc_9050
		BEQ		loc_9050
		LDA		#$00
loc_9050:
		STA		_menu_controls_idx,X
		JSR		_menu_update_draw
locret_9056:
		RTS
; NEW, added music track 0D
_menu_controls_max_val_list:
		.BYTE	$01,$03,$0D,$23

; =============== S U B R O U T I N E ======n================================
_nsub_menu_init_draw:
		LDX		#$00
		JSR		_menu_update_draw
		LDX		#$01
		JSR		_menu_update_draw
		LDX		#$02
		JSR		_menu_update_draw
		LDX		#$03

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_menu_update_draw:
		LDA		off_9068,X
		STA		_ptr06
		LDA		off_906C,X
		STA		_ptr06+1
		JMP		(_ptr06)

off_9068:
		.BYTE	<[_controls_draw]
		.BYTE	<[_difficult_draw]
		.BYTE	<[_sound_test_mus_draw]
		.BYTE	<[_sound_test_se_draw]
off_906C:
		.BYTE	>[_controls_draw]
		.BYTE	>[_difficult_draw]
		.BYTE	>[_sound_test_mus_draw]
		.BYTE	>[_sound_test_se_draw]

; =============== S U B R O U T I N E ======n================================
_controls_draw:
		LDA		_menu_controls_idx
		BNE		loc_907B
		JSR		_ppu_res_send_param
		.WORD	_tlm_ab_controls
		RTS
loc_907B:
		JSR		_ppu_res_send_param
		.WORD	_tlm_ba_controls
		RTS

		TXT		$20E9,"A-BEAM  B-TRAP",	_tlm_ab_controls
		TXT		$20E9,"B-BEAM  A-TRAP",	_tlm_ba_controls

; =============== S U B R O U T I N E ======n================================
_difficult_draw:
		LDX		_menu_difficulty_idx
		LDA		off_90C9,X
		LDY		off_90CD,X
		JSR		_ppu_res_send_ptr
		LDA		#$04
		SEC
		SBC		_menu_difficulty_idx
		LDX		#$00
		JSR		_bin2dec
		LDX		#$11
		LDY		#$0D
		JSR		_print_num99999
		LDY		_menu_difficulty_idx
		LDA		_scores_1st_extend_list_lo,Y
		LDX		_scores_1st_extend_list_hi,Y
		JSR		_bin2dec
		LDY		#$0F
		JSR		_score_extent_draw
		JSR		_2nd_extent_convert
		LDY		#$11
		JSR		_score_extent_draw
		JSR		_2nd_extent_convert
		LDY		#$13

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_score_extent_draw:
		LDX		#$16
		BNE		_j_print_num99999_ex

; =============== S U B R O U T I N E ======n================================
_2nd_extent_convert:
		LDY		_menu_difficulty_idx
		LDA		_scores_2nd_extend_list_lo,Y
		LDX		_scores_2nd_extend_list_hi,Y
		JMP		_bin2dec

; =============== S U B R O U T I N E ======n================================
_sound_test_mus_draw:
		LDA		_sound_test_mus_idx
		LDX		#$00
		JSR		_bin2dec
		LDY		#$15
		BNE		_j_print_num99999

; =============== S U B R O U T I N E ======n================================
_sound_test_se_draw:
		LDA		_sound_test_snd_idx
		LDX		#$00
		JSR		_bin2dec
		LDY		#$17

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_j_print_num99999:
		LDX		#$07

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_j_print_num99999_ex:
		JMP		_print_num99999

off_90C9:
		.BYTE	<[word_90D1]
		.BYTE	<[word_90DB]
		.BYTE	<[word_90E5]
		.BYTE	<[word_90EF]
off_90CD:
		.BYTE	>[word_90D1]
		.BYTE	>[word_90DB]
		.BYTE	>[word_90E5]
		.BYTE	>[word_90EF]

		TXT		$2169,"EASY  ",	word_90D1
		TXT		$2169,"NORMAL",	word_90DB
		TXT		$2169,"HARD  ",	word_90E5
		TXT		$2169,"PRO   ",	word_90EF

; =============== S U B R O U T I N E ======n================================
_nsub_secret_menu_AB_input:
		LDA		_pad0_pressed				; buttons used if sound test options
		AND		#PAD_A						; are selected
		BEQ		loc_91D1
		LDA		_cur_room_doors_cnt			; A starts the sounds
		CMP		#$02
		BNE		loc_91C2
		LDA		_sound_test_mus_idx
		JMP		_far_prg6_apu_mus_load
loc_91C2:
		CMP		#$03
		BNE		locret_91EC
		LDA		#$FF
		JSR		_far_prg6_apu_snd_load
		LDA		_sound_test_snd_idx
		JMP		_far_prg6_apu_snd_load
loc_91D1:
		LDA		_pad0_pressed				; B stops them
		AND		#PAD_B
		BEQ		locret_91EC
		LDA		_cur_room_doors_cnt
		CMP		#$02
		BNE		loc_91E3
		LDA		#$FF
		JMP		_far_prg6_apu_mus_load
loc_91E3:
		CMP		#$03
		BNE		locret_91EC
		LDA		#$FF
		JMP		_far_prg6_apu_snd_load
locret_91EC:
		RTS

		SECTION_END	"SCR0 CODE AND DATA"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr07_ending
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$16
		SCASE			_scr_ending_sub01
		SCASE			_scr_ending_sub02
		SCASE			_scr_ending_sub03
		SCASE			_scr_ending_sub04
		SCASE			_scr_ending_sub05
		SCASE			_scr_ending_sub06
		SCASE			_scr_ending_sub07
		SCASE			_scr_ending_sub08
		SCASE			_scr_ending_sub09
		SCASE			_scr_ending_sub0A
		SCASE			_scr_ending_sub0B
		SCASE			_scr_ending_sub0C
		SCASE			_scr_ending_sub0D
		SCASE			_scr_ending_sub0E
		SCASE			_scr_ending_sub0F
		SCASE			_scr_ending_sub10
		SCASE			_scr_ending_sub11
		SCASE			_scr_ending_sub12
		SCASE			_scr_ending_sub13
		SCASE			_scr_ending_sub14
		SCASE			_scr_ending_sub15
		SCASE			_scr_ending_sub16

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		STORE8			_out_of_screen_test_flag,$00; default
		SDELAY			$5A								; delay before start
		NJSR			_nsub_mmc1_chr1_set				; setup CHR for BG
			NARGB		$09
		NJSR			_nsub_scroll_page_set			; setup NT page
			NARGB		$00
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack starr screen
			NARGB		_tlm7_staff_idx					; similar to title curtains
		NJSR			_nsub_full_pal_load
			NARGW		_pal_ending
		NJSR			_nsub_apu_mus_load				; misc setups.. whatever
			NARGB		_mus5_idx
		SDELAY			$64								; more delay to let music begin
		SJSR			_ssub_pal_fade_in				; show screen
		POS_X_SET		0,$80,$00						; set base offset for main object
		POS_Y_SET		0,$80,$00
		NJSR			_nsub_sarg01_load_data_ofs		; load scenario data offset
			NARGW		_ending_scenario_data
_sloc_92E5:
		NJSR			_nsub_ending_scenario_data_fetch; play it continuosly
		SJSR_SW			$04
		SCASE			_ssub_scenario_player_sub0_thread_start
		SCASE			_ssub_scenario_player_sub1_delay
		SCASE			_ssub_scenario_player_sub2_text_draw
		SCASE			_ssub_scenario_player_sub3_scores_draw
		SJMP			_sloc_92E5

; =============== S C R I P T  S U B R O U T I N E =====s====================
; default option for all non-zero
_ssub_scenario_player_sub0_thread_start:
		NJSR			_nsub_chain_thread_lib_load_enemy; fetch and load new thread
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
; set delay for ARG*16 frames
_ssub_scenario_player_sub1_delay:
		NJSR			_nsub_next_scenario_byte_sarg2_store; fetch byte from scenario data
		SLOOP_BEGIN		$10								; put it to SARG2
		NJSR			_nsub_obj_delay_set_from_sarg	; then write it to delay...
			NARGB		SARG2							; 16 times for every value
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_scenario_player_sub2_text_draw:
		SLOOP_BEGIN		$04								; fade out palette for window
		NJSR			_nsub_pal_fade_req_dec_by_mask	; only, keep curtains shown
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SARG_SET		SARG2,$00
		SLOOP_BEGIN		$12
		NJSR			_nsub_window_line_clear			; clear frame window line by line
		SDELAY			$01								; $18x$12 area
		SLOOP_END
		NJSR			_nsub_scenario_txt_lib_ptr_load	; fetch current screen text lib ptr
_sloc_931B:
		SDELAY			$01								; draw line by line the text until
		NJSR			_nsub_scenario_txt_lib_line_draw; end of strings
		SBCC			_sloc_931B
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask	; fade in again to show it
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
; last finishes command, shows the final scores and wait for START to
; return to the main game.
;
_ssub_scenario_player_sub3_scores_draw:
		SLOOP_BEGIN		$15								; long delay $15x$3C = 21 sec
		SDELAY			$3C
		SLOOP_END
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask	; fade out window
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SARG_SET		SARG2,$00						; clear window
		SLOOP_BEGIN		$12
		NJSR			_nsub_window_line_clear
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_bg_pal_load				; screen setup
			NARGW		_pal_ending_scores
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$1C
		NJSR			_nsub_ending_scores_draw		; sraw hi-scores
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask	; show screen
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		NBG_HNDL_SET	_nbgsub_ending_scores_exit		; load native bg input handler
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_ending_close:
		SJSR			_ssub_pal_fade_out				; fade out the screen
		STORE8			_game_flags,$00					; then set main loop flag to
		SSTOP											; jump to main entry

_pal_ending:
		.BYTE	$0F,$20,$15,$29,$0F,$20,$01,$29,$0F,$21,$11,$01,$0F,$20,$10,$00
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$37,$27,$17,$0F,$20,$10,$00
_pal_ending_scores:
		.BYTE	$0F,$20,$20,$20,$0F,$20,$20,$20,$0F,$21,$11,$01,$0F,$20,$20,$20

		MAC	ECMD_THRED
		.BYTE	{1}_idx+1,{2},{3},{4}
		ENDM

		MAC	ECMD_DELAY
		.BYTE	[_ssub_scenario_player_sub1_delay_idx-1]|$80
		.BYTE	{1}
		ENDM

		MAC	ECMD_PRINT
		.BYTE	[_ssub_scenario_player_sub2_text_draw_idx-1]|$80
		.WORD	{1}
		ENDM

		MAC	ECMD_WAIT
		.BYTE	[_ssub_scenario_player_sub3_scores_draw_idx-1]|$80
		ENDM

_ending_scenario_data:
		ECMD_THRED	_scr_ending_sub01,$AB,$13,$00
		ECMD_DELAY	$0A
		ECMD_THRED	_scr_ending_sub02,$94,$07,$00
		ECMD_DELAY	$1A
		ECMD_PRINT	_staff_txt0
		ECMD_THRED	_scr_ending_sub03,$80,$10,$00
		ECMD_THRED	_scr_ending_sub04,$7F,$0C,$00
		ECMD_DELAY	$1E
		ECMD_PRINT	_staff_txt1
		ECMD_THRED	_scr_ending_sub05,$80,$08,$00
		ECMD_THRED	_scr_ending_sub06,$80,$10,$00
		ECMD_THRED	_scr_ending_sub07,$80,$0C,$00
		ECMD_DELAY	$20
		ECMD_PRINT	_staff_txt2
		ECMD_DELAY	$20
		ECMD_PRINT	_staff_txt3
		ECMD_THRED	_scr_ending_sub08,$88,$C0,$00
		ECMD_THRED	_scr_ending_sub09,$98,$10,$00
		ECMD_THRED	_scr_ending_sub0A,$68,$10,$00
		ECMD_DELAY	$20
		ECMD_PRINT	_staff_txt4
		ECMD_DELAY	$20
		ECMD_PRINT	_staff_txt5
		ECMD_THRED	_scr_ending_sub0B,$78,$10,$00
		ECMD_DELAY	$06
		ECMD_THRED	_scr_ending_sub0D,$78,$18,$00
		ECMD_DELAY	$20
		ECMD_PRINT	_staff_txt6
		ECMD_DELAY	$20
		ECMD_THRED	_scr_ending_sub16,$00,$00,$00
		ECMD_DELAY	$08
		ECMD_THRED	_scr_ending_sub0E,$A8,$08,$00
		ECMD_THRED	_scr_ending_sub0F,$58,$08,$00
		ECMD_THRED	_scr_ending_sub11,$88,$28,$00
		ECMD_THRED	_scr_ending_sub12,$78,$28,$00
		ECMD_THRED	_scr_ending_sub13,$78,$28,$00
		ECMD_THRED	_scr_ending_sub14,$88,$28,$00
		ECMD_THRED	_scr_ending_sub15,$00,$E0,$00
		ECMD_WAIT

; =============== S U B R O U T I N E ======n================================
_nbgsub_ending_scores_exit:
		LDA		_pad0_pressed				; wait if START is pressed
		AND		#PAD_START
		BEQ		locret_941E
		JSR		_cur_thread_reload_param	; load another script to restart game
		.WORD	_scr_ending_close
locret_941E:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_ending_scores_draw:
		LDA		#$FF						; disable lives bonus vars
		STA		_scores_to_next_life
		STA		_scores_to_next_life+1
		LDA		_players_lives				; if you finish the game with more
		BEQ		loc_9436
loc_942C:
		LDA		#$64						; add 100x scores for every life
		JSR		_scores_add
		DEC		_players_lives
		BNE		loc_942C
loc_9436:
#if TWO_PLAYER_MODE==1
; TODO: second players lives add to scores?
#endif
		JSR		_ppu_res_send_param			; draw text resources
		.WORD	_res_top_score
		JSR		_ppu_res_send_param
		.WORD	_res_score
		LDX		#$11
		LDY		#$07
		JSR		_printf_hi_scores			; print actual scores
		LDX		#$0F
		LDY		#$0F
		JMP		_printf_scores

		TXT		$20E7,"TOP SCORE      00",	_res_top_score
		TXT		$21E9,"SCORE      00",	_res_score

; =============== S U B R O U T I N E ======n================================
_nsub_ending_scenario_data_fetch:
		LDA		_trds_args0
		STA		_ptr06
		LDA		_trds_args1
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y					; any value in this script below 80 is
		BMI		loc_9484					; thread start data, fetches with sub0
		TYA									; of the player
		RTS
loc_9484:
		AND		#$7F						; any other values are other subs calls
		CLC									; sub_idx = (cmd & 0x7F) + 1
		ADC		#$01
		PHA
		INC		_trds_args0
		BNE		loc_9490
		INC		_trds_args1
loc_9490:
		PLA
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_next_scenario_byte_sarg2_store:
		JSR		_next_scenario_byte_get
		STA		_trds_args2
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_window_line_clear:
		LDA		#$20
		STA		_tmp_buf+4
		LDX		_cur_trd_slot
		LDY		_trds_args2,X
		INY
		INY
		LDX		#$04
		JSR		_ppu_offset_calc
		LDA		#$18
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_repeat_no_ofs
		.WORD	_tmp_buf+2
		LDX		_cur_trd_slot
		INC		_trds_args2,X
		RTS

; =============== S U B R O U T I N E ======n================================
_next_scenario_byte_get:
		LDA		_trds_args0
		STA		_ptr06
		LDA		_trds_args1
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		INC		_trds_args0
		BNE		locret_94CE
		INC		_trds_args1
locret_94CE:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_scenario_txt_lib_ptr_load:
		JSR		_next_scenario_byte_get
		STA		_lvl_rooms_lib_ptr
		JSR		_next_scenario_byte_get
		STA		_lvl_rooms_lib_ptr+1
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_scenario_txt_lib_line_draw:
		LDY		#$00
		LDA		(_lvl_rooms_lib_ptr),Y
		STA		_tmp2
		INY
		LDA		(_lvl_rooms_lib_ptr),Y
		LDY		_tmp2
		JSR		_ppu_res_send_ptr
		LDA		_lvl_rooms_lib_ptr
		CLC
		ADC		#$02
		STA		_lvl_rooms_lib_ptr
		BCC		loc_94F3
		INC		_lvl_rooms_lib_ptr+1
loc_94F3:
		LDY		#$00
		LDA		(_lvl_rooms_lib_ptr),Y
		BEQ		loc_94FB
		CLC
		RTS
loc_94FB:
		SEC
		RTS

		MAC		STAFF
		.BYTE	>[{1}]
		.BYTE	<[{1}]
		ENDM

_staff_txt0:
		STAFF	_res_executive_producer
		STAFF	_res_tsuyoshi_ikeda
		STAFF	_res_producer
		STAFF	_res_miko_ikeda
		.BYTE	$00
_staff_txt1:
		STAFF	_res_director
		STAFF	_res_gsx_suga
		STAFF	_res_assistant_director
		STAFF	_res_osamu_kobiyama
		.BYTE	$00
_staff_txt2:
		STAFF	_res_designer
		STAFF	_res_shigeru_hashiguchi
		STAFF	_res_tsuyoshi_wakayama
		STAFF	_res_programmer
		STAFF	_res_gsx_suga_0
		.BYTE	$00
_staff_txt3:
		STAFF	_res_sound_creator
		STAFF	_res_jun_isikawa
		.BYTE	$00
_staff_txt4:
		STAFF	_res_technical_supervisor
		STAFF	_res_satoru_iwate
		.BYTE	$00
_staff_txt5:
		STAFF	_res_special_thanks
		STAFF	_res_makoto_kanai
		STAFF	_res_satoshi_ishida
		STAFF	_res_hitoshi_kikkawa
		STAFF	_res_takashi_saito
		STAFF	_res_satoshi_mitsuhara
		STAFF	_res_mitsuru_kakuta
		.BYTE	$00
_staff_txt6:
		STAFF	_res_and
		STAFF	_res_all_test_players
		STAFF	_res_and_0
		STAFF	_res_you_too
		STAFF	_res_by_hal_laboratory
		.BYTE	$00

		TXT		$2065,"EXECUTIVE PRODUCER",	_res_executive_producer
		TXT		$20AD,"TSUYOSHI IKEDA",	_res_tsuyoshi_ikeda
		TXT		$2125,"PRODUCER",	_res_producer
		TXT		$2170,"MIKIO IKEDA",	_res_miko_ikeda
		TXT		$2065,"DIRECTOR",	_res_director
		TXT		$20B3,"GSX SUGA",	_res_gsx_suga
		TXT		$2125,"ASSISTANT DIRECTOR",	_res_assistant_director
		TXT		$216D,"OSAMU KOBIYAMA",	_res_osamu_kobiyama
		TXT		$2065,"DESIGNER",	_res_designer
		TXT		$20A9,"SHIGERU HASHIGUCHI",	_res_shigeru_hashiguchi
		TXT		$20E9,"TSUYOSHI WAKAYAMA",	_res_tsuyoshi_wakayama
		TXT		$2165,"PROGRAMMER",	_res_programmer
		TXT		$21B3,"GSX SUGA",	_res_gsx_suga_0
		TXT		$2065,"SOUND CREATOR",	_res_sound_creator
		TXT		$20AF,"JUN ISHIKAWA",	_res_jun_isikawa
		TXT		$2065,"TECHNICAL SUPERVISOR",	_res_technical_supervisor
		TXT		$20AF,"SATORU IWATA",	_res_satoru_iwate
		TXT		$2065,"SPECIAL THANKS",	_res_special_thanks
		TXT		$20AB,"MAKOTO KANAI",	_res_makoto_kanai
		TXT		$20EA,"SATOSHI ISHIDA",	_res_satoshi_ishida
		TXT		$212A,"HITOSHI KIKKAWA",	_res_hitoshi_kikkawa
		TXT		$216A,"TAKASHI SAITO",	_res_takashi_saito
		TXT		$21AA,"SATOSHI MITSUHARA",	_res_satoshi_mitsuhara
		TXT		$21EA,"MITSURU KAKUTA",	_res_mitsuru_kakuta
		TXT		$208E,"AND",	_res_and
; NOTE: so sad, dasm can treat "" operators but can't disable "," inside
; this will cause the macros error until now (tried on 2014 year build also)
_res_all_test_players:
		.WORD	$20E8
		.BYTE	$11,$01
		.BYTE	"ALL TEST PLAYERS,"
		TXT		$214E,"AND",	_res_and_0
		TXT		$21AC,"YOU TOO/",	_res_you_too
		TXT		$2267,"BY HAL LABORATORY",	_res_by_hal_laboratory

; =============== S C R I P T ==========================s====================
_scr_ending_sub01:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$19
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$03
		SPR_IDX_SET		6,$00
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$02
		SLOOP_END
		SPR_IDX_SET		6,$00
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$03
		SDELAY			$20
		SLOOP_BEGIN		$02
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SLOOP_END
		SPR_IDX_INC		6
		SPR_IDX_DEC		0
		SDELAY			$20
		SPR_IDX_SET		0,$05
		SDELAY			$0A
		SPR_IDX_SET		0,$06
		POS_Y_DELTA_SET 6,$00,$FE
		POS_Y_DELTA_SET 6,$00,$02
		POS_MOVE_STOP	0
		SPR_IDX_SET		6,$05
		SPR_IDX_SET		6,$03
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$04
		SPR_IDX_SET		6,$00
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$02
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub02:
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$04
		SPR_IDX_SET		0,$08
		SDELAY			$0B
		SPR_IDX_DEC		0
		SDELAY			$0B
		SPR_IDX_INC		0
		SDELAY			$0B
		SPR_IDX_INC		0
		SDELAY			$0B
		SLOOP_END
		SPR_IDX_DEC		0
		SDELAY			$0B
		SPR_IDX_DEC		0
		SDELAY			$0B
		SPR_IDX_INC		0
		SDELAY			$0B
		POS_MOVE_STOP	0
		SDELAY			$10
		SLOOP_BEGIN		$14
		SPR_IDX_SET		2,$0A
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub03:
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_9910
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$03
		SPR_IDX_SET		0,$4D
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$10
		SPR_IDX_DEC		0
		SDELAY			$10
		SPR_IDX_SET		0,$4F
		SDELAY			$10
		SLOOP_END
		SPR_IDX_SET		0,$4D
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$10
		POS_MOVE_STOP	0
		SPR_IDX_DEC		0
		SDELAY			$60
		SPR_IDX_SET		0,$4A
		SDELAY			$10
		SPR_IDX_SET		0,$47
		SDELAY			$50
		SPR_IDX_SET		4,$4A
		POS_X_DELTA_SET 0,$00,$FE
		SLOOP_BEGIN		$04
		SPR_IDX_SET		4,$4D
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$4F
		SLOOP_END
		SSTOP

byte_9910:
		.BYTE	$0F,$36,$2B,$0F

; =============== S C R I P T ==========================s====================
_scr_ending_sub04:
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_SET		0,$0E
		SDELAY			$78
		POS_MOVE_STOP	0
		SDELAY			$B0
		SPR_IDX_SET		0,$10
		SDELAY			$08
		SPR_IDX_INC		0
		SDELAY			$08
		SLOOP_BEGIN		$0E
		SPR_IDX_SET		4,$0E
		SPR_IDX_INC		4
		SLOOP_END
		POS_X_DELTA_SET 0,$00,$FE
		SLOOP_BEGIN		$07
		SPR_IDX_SET		4,$12
		SPR_IDX_INC		4
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub05:
		SDELAY			$60
		POS_X_DELTA_SET 0,$40,$01
		SLOOP_BEGIN		$0C
		SPR_IDX_SET		4,$18
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$19
		SPR_IDX_SET		4,$17
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$FF
		SDELAY			$50
		POS_X_SET		0,$00,$01
		POS_X_DELTA_SET 0,$C0,$FE
		SLOOP_BEGIN		$07
		SPR_IDX_SET		4,$1D
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$1F
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$1A
		SDELAY			$10
		SLOOP_BEGIN		$07
		SPR_IDX_SET		0,$50
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$10
		SLOOP_END
		SPR_IDX_INC		0
		SDELAY			$30
		SPR_IDX_SET		0,$50
		SDELAY			$30
		SPR_IDX_SET		0,$1A
		SDELAY			$08
		POS_X_DELTA_SET 0,$40,$01
		SLOOP_BEGIN		$07
		SPR_IDX_SET		4,$17
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$19
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub06:
		SDELAY			$70
		POS_X_DELTA_SET 0,$40,$01
		SLOOP_BEGIN		$0C
		SPR_IDX_SET		4,$24
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$25
		SPR_IDX_SET		4,$23
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$FF
		SDELAY			$50
		POS_X_SET		0,$00,$01
		POS_Y_MOVE		0,$F8
		POS_X_DELTA_SET 0,$C0,$FE
		SLOOP_BEGIN		$06
		SPR_IDX_SET		4,$29
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$2B
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$26
		SDELAY			$10
		SLOOP_BEGIN		$07
		SPR_IDX_SET		0,$54
		SDELAY			$10
		SPR_IDX_DEC		0
		SDELAY			$10
		SLOOP_END
		SPR_IDX_SET		0,$55
		SDELAY			$30
		SPR_IDX_SET		0,$53
		SDELAY			$30
		SPR_IDX_SET		0,$26
		SDELAY			$08
		POS_X_DELTA_SET 0,$40,$01
		SLOOP_BEGIN		$06
		SPR_IDX_SET		4,$23
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$25
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub07:
		SDELAY			$50
		SJSR			_ssub_9B0B
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$FF
		SDELAY			$58
		POS_X_SET		0,$00,$01
		SLOOP_BEGIN		$06
		POS_X_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$5A
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		6
		POS_X_DELTA_SET 0,$00,$FE
		SPR_IDX_INC		0
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		6
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$FF
		SDELAY			$18
		POS_X_SET		0,$00,$00
		POS_Y_MOVE		0,$14
		SJSR			_ssub_9B0B
		SSTOP

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_9B0B:
		SLOOP_BEGIN		$06
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$56
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$01
		SPR_IDX_INC		6
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_INC		0
		SDELAY			$08
		POS_X_DELTA_SET 0,$00,$01
		SPR_IDX_INC		6
		SLOOP_END
		SRET

; =============== S C R I P T ==========================s====================
_scr_ending_sub08:
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_9C20
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		POS_X_DELTA_SET 0,$C0,$00
		SLOOP_BEGIN		$05
		SPR_IDX_SET		4,$C0
		SLOOP_BEGIN		$07
		SPR_IDX_INC		4
		SLOOP_END
		SLOOP_END
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$04
		SPR_IDX_SET		4,$C0
		SLOOP_BEGIN		$07
		SPR_IDX_INC		4
		SLOOP_END
		SLOOP_END
		SPR_IDX_SET		4,$C0
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_SET		4,$C8
		SLOOP_BEGIN		$09
		SPR_IDX_INC		4
		SLOOP_END
		POS_Y_DELTA_SET 0,$80,$00
		SPR_IDX_SET		6,$CE
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$06
		SPR_IDX_DEC		6
		SLOOP_END
		SLOOP_BEGIN		$11
		SPR_IDX_SET		2,$D2
		SPR_IDX_SET		2,$C8
		SLOOP_END
		SLOOP_BEGIN		$02
		SPR_IDX_SET		4,$C8
		SPR_IDX_SET		0,$D2
		SDELAY			$10
		SLOOP_END
		SPR_IDX_SET		0,$C8
		SDELAY			$50
		SPR_IDX_SET		2,$D2
		SPR_IDX_SET		0,$C8
		SDELAY			$10
		POS_Y_DELTA_SET 0,$C0,$00
		SLOOP_BEGIN		$03
		SJSR			_ssub_9C15
		SLOOP_END
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$05
		SJSR			_ssub_9C15
		SLOOP_END
		POS_X_DELTA_SET 0,$C0,$00
		SLOOP_BEGIN		$05
		SJSR			_ssub_9C15
		SLOOP_END
		SSTOP

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_9C15:
		SPR_IDX_SET		4,$C5
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_SET		4,$C0
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SRET

byte_9C20:
		.BYTE	$0F,$36,$2B,$0F

; =============== S C R I P T ==========================s====================
_scr_ending_sub09:
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$04
		SPR_IDX_SET		6,$2F
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$31
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$2C
		SDELAY			$D0
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_SET		6,$35
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$37
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$2C
		SDELAY			$60
		SPR_IDX_SET		0,$2F
		SDELAY			$30
		SPR_IDX_SET		0,$2C
		SDELAY			$20
		SPR_IDX_SET		0,$2F
		SDELAY			$10
		SPR_IDX_SET		0,$2C
		SDELAY			$50
		SPR_IDX_SET		0,$5E
		SDELAY			$08
		SPR_IDX_SET		4,$2C
		POS_X_DELTA_SET 0,$00,$FF
		SLOOP_BEGIN		$05
		SPR_IDX_SET		6,$35
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$37
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub0A:
		POS_X_DELTA_SET 0,$00,$FF
		SLOOP_BEGIN		$04
		SPR_IDX_SET		6,$41
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$43
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$38
		SDELAY			$D0
		POS_X_DELTA_SET 0,$00,$01
		SPR_IDX_SET		6,$3B
		SPR_IDX_INC		6
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$38
		SDELAY			$6C
		SPR_IDX_SET		0,$41
		SDELAY			$30
		SPR_IDX_SET		0,$38
		SDELAY			$20
		SPR_IDX_SET		0,$41
		SDELAY			$10
		SPR_IDX_SET		0,$38
		SDELAY			$50
		SPR_IDX_SET		0,$5F
		SDELAY			$08
		SPR_IDX_SET		4,$38
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$05
		SPR_IDX_SET		6,$3B
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$3D
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub0B:
		POS_X_DELTA_SET 0,$40,$FF
		SLOOP_BEGIN		$0E
		SPR_IDX_SET		7,$60
		SPR_IDX_INC		7
		SLOOP_END
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$05
		SPR_IDX_SET		7,$60
		SPR_IDX_INC		7
		SLOOP_END
		SPR_IDX_DEC		0
		POS_Y_DELTA_SET 6,$00,$FA
		POS_Y_DELTA_SET 6,$00,$06
		POS_MOVE_STOP	0
		NJSR			_nsub_new_thread_start
			NARGB		_scr07_ending_idx
			NARGB		$00,$00
			NARGB		_scr_ending_sub0C_idx+1
			NARGB		$00
		SPR_IDX_SET		0,$65
		SDELAY			$20
		SLOOP_BEGIN		$02
		SPR_IDX_SET		6,$65
		SPR_IDX_SET		6,$68
		SPR_IDX_SET		6,$67
		SPR_IDX_SET		6,$68
		SLOOP_END
		POS_X_DELTA_SET 0,$C0,$00
		SLOOP_BEGIN		$06
		SPR_IDX_SET		7,$66
		SPR_IDX_INC		7
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		7,$68
		POS_X_DELTA_SET 0,$40,$FF
		SLOOP_BEGIN		$0E
		SPR_IDX_SET		7,$64
		SPR_IDX_INC		7
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$FF
		SDELAY			$A0
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$0F
		SPR_IDX_SET		7,$62
		SPR_IDX_INC		7
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub0C:
		SPR_IDX_SET		0,$69
		POS_X_DELTA_SET 6,$00,$02
		POS_X_DELTA_SET 0,$C0,$00
		POS_Y_DELTA_SET 6,$00,$02
		POS_X_DELTA_SET 2,$00,$00
		POS_MOVE_STOP	0
		SDELAY			$10
		SPR_IDX_SET		6,$FF
		POS_X_DELTA_SET 0,$00,$01
		SDELAY			$48
		POS_MOVE_STOP	0
		SDELAY			$06
		SPR_IDX_SET		0,$69
		POS_X_DELTA_SET 0,$00,$FE
		POS_Y_DELTA_SET 0,$00,$FD
		SLOOP_BEGIN		$66
		POS_Y_DELTA_ADD 1,$0F,$00
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub0D:
		POS_X_DELTA_SET 0,$00,$FF
		SLOOP_BEGIN		$05
		SPR_IDX_SET		6,$4D
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$4F
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$4D
		SDELAY			$20
		SPR_IDX_SET		1,$6B
		SPR_IDX_SET		0,$6A
		SDELAY			$08
		SPR_IDX_SET		0,$6B
		SDELAY			$20
		SPR_IDX_SET		0,$4D
		SDELAY			$10
		SPR_IDX_SET		6,$6C
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$03
		SPR_IDX_SET		6,$6D
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$6F
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		6,$6C
		SPR_IDX_SET		6,$70
		SPR_IDX_SET		0,$4D
		SDELAY			$F0
		POS_X_DELTA_SET 0,$40,$FF
		SLOOP_BEGIN		$03
		SPR_IDX_SET		6,$4D
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$4F
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$4D
		SDELAY			$70
		SPR_IDX_SET		0,$6A
		SDELAY			$08
		SPR_IDX_SET		6,$4D
		SPR_IDX_SET		1,$4A
		POS_X_DELTA_SET 0,$40,$01
		SLOOP_BEGIN		$04
		SPR_IDX_SET		5,$47
		SPR_IDX_INC		5
		SPR_IDX_DEC		5
		SPR_IDX_SET		5,$49
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub16:
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SARG_SET		SARG2,$00
		SLOOP_BEGIN		$12
		NJSR			_nsub_tlm_raw_arg2_idx_line_draw
			NARGW		_tlm_ending_logo
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_ending_logo_attr_load
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$14
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$00
		NJSR			_nsub_patch_pal_load
			NARGB		$03
			NARGW		byte_A547
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nsub_ending_logo_attr_load:
		JSR		_ppu_res_send_param
		.WORD	_attr_ending_logo
		RTS

_attr_ending_logo:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$FA,$FA,$FA,$FA,$FA,$FA,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A

; =============== S C R I P T ==========================s====================
_scr_ending_sub0E:
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$06
		SPR_IDX_SET		6,$74
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$76
		SLOOP_END
		SPR_IDX_SET		6,$74
		SPR_IDX_INC		6
		POS_MOVE_STOP	0
		SPR_IDX_DEC		6
		POS_X_DELTA_SET 6,$C0,$00
		POS_MOVE_STOP	0
		NJSR			_nsub_new_thread_start
			NARGB		_scr07_ending_idx
			NARGB		$00,$00
			NARGB		_scr_ending_sub10_idx+1
			NARGB		$00
		SDELAY			$F0
		POS_X_DELTA_SET 0,$40,$FF
		SPR_IDX_SET		6,$7A
		POS_MOVE_STOP	0
		SDELAY			$90
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$08
		SPR_IDX_SET		6,$74
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$76
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		6,$74
		SSTOP

byte_A547:
		.BYTE	$0F,$10,$05,$0F

; =============== S C R I P T ==========================s====================
_scr_ending_sub0F:
		POS_X_DELTA_SET 0,$80,$FF
		SLOOP_BEGIN		$06
		SPR_IDX_SET		6,$AD
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$AF
		SLOOP_END
		SPR_IDX_SET		6,$AD
		SPR_IDX_INC		6
		POS_MOVE_STOP	0
		SPR_IDX_DEC		6
		POS_X_DELTA_SET 0,$40,$FF
		SPR_IDX_SET		6,$AF
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$AD
		SDELAY			$F0
		SDELAY			$80
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$07
		SPR_IDX_SET		6,$B0
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$B2
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub10:
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$78,$00
		SPR_IDX_SET		0,$B3
		POS_Y_DELTA_SET 0,$C0,$FF
		SLOOP_BEGIN		$7A
		POS_X_DELTA_SET 1,$08,$00
		POS_X_DELTA_SET 1,$F8,$FF
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub11:
		SDELAY			$06
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$07
		SPR_IDX_SET		6,$80
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$82
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$83
		SDELAY			$10
		SLOOP_BEGIN		$07
		SPR_IDX_SET		0,$83
		SDELAY			$10
		SPR_IDX_SET		0,$B4
		POS_Y_DELTA_SET 6,$00,$FD
		POS_Y_DELTA_SET 6,$00,$03
		POS_MOVE_STOP	0
		SLOOP_END
		SPR_IDX_SET		0,$86
		SDELAY			$80
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$0E
		SPR_IDX_SET		6,$80
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$82
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub12:
		SDELAY			$06
		POS_X_DELTA_SET 0,$80,$FF
		SLOOP_BEGIN		$07
		SPR_IDX_SET		6,$92
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$94
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$8F
		SDELAY			$10
		SLOOP_BEGIN		$07
		SPR_IDX_SET		0,$8F
		SDELAY			$10
		SPR_IDX_SET		0,$B5
		POS_Y_DELTA_SET 6,$00,$FD
		POS_Y_DELTA_SET 6,$00,$03
		POS_MOVE_STOP	0
		SLOOP_END
		SPR_IDX_SET		0,$92
		SDELAY			$90
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$07
		SPR_IDX_SET		6,$8C
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$8E
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub13:
		SDELAY			$40
		POS_X_DELTA_SET 0,$80,$FF
		SLOOP_BEGIN		$05
		SPR_IDX_SET		6,$9E
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$A0
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$9B
		SDELAY			$10
		SLOOP_BEGIN		$07
		SPR_IDX_SET		0,$9B
		SDELAY			$10
		SPR_IDX_SET		0,$B6
		POS_Y_DELTA_SET 6,$00,$FD
		POS_Y_DELTA_SET 6,$00,$03
		POS_MOVE_STOP	0
		SLOOP_END
		SPR_IDX_SET		0,$9E
		SDELAY			$70
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$05
		SPR_IDX_SET		6,$98
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$9A
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub14:
		SDELAY			$40
		POS_X_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$05
		SPR_IDX_SET		6,$A4
		SPR_IDX_INC		6
		SPR_IDX_DEC		6
		SPR_IDX_SET		6,$A6
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$A7
		SDELAY			$10
		SLOOP_BEGIN		$06
		SPR_IDX_SET		0,$A7
		SDELAY			$10
		SPR_IDX_SET		0,$B7
		POS_Y_DELTA_SET 6,$00,$FD
		POS_Y_DELTA_SET 6,$00,$03
		POS_MOVE_STOP	0
		SLOOP_END
		SPR_IDX_SET		2,$B8
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_SET		0,$B8
		SDELAY			$F0
		SDELAY			$E0
		SPR_IDX_SET		0,$A7
		SDELAY			$20
		SPR_IDX_SET		0,$A4
		SDELAY			$20
		SPR_IDX_SET		6,$A7
		SPR_IDX_SET		0,$AA
		SDELAY			$20
		SPR_IDX_SET		0,$A7
		SDELAY			$20
		SPR_IDX_SET		0,$A4
		SDELAY			$30
		POS_X_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$09
		SPR_IDX_SET		5,$A4
		SPR_IDX_INC		5
		SPR_IDX_DEC		5
		SPR_IDX_SET		5,$A6
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_ending_sub15:
		SPR_IDX_SET		0,$BC
_sloc_A784:
		SARG_SET		SARG0,$00
		SLOOP_BEGIN		$0C
		NJSR			_nsub_end_spr_pal_anim
		SDELAY			$01
		SLOOP_END
		SJMP			_sloc_A784

; =============== S U B R O U T I N E ======n================================
_nsub_end_spr_pal_anim:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		INC		_trds_args0,X
		ASL
		ASL
		ADC		#<[_pal_end_sprite_lib]
		PHA
		LDA		#$00
		ADC		#>[_pal_end_sprite_lib]
		TAX
		PLA
		LDY		#$07
		JMP		_patch_pal_load
_pal_end_sprite_lib:
		.BYTE	$0F,$31,$0F,$35
		.BYTE	$0F,$31,$0F,$25
		.BYTE	$0F,$31,$00,$15
		.BYTE	$0F,$31,$00,$05
		.BYTE	$0F,$31,$10,$15
		.BYTE	$0F,$31,$10,$25
		.BYTE	$0F,$31,$20,$35
		.BYTE	$0F,$31,$20,$25
		.BYTE	$0F,$31,$10,$15
		.BYTE	$0F,$31,$10,$05
		.BYTE	$0F,$31,$00,$15
		.BYTE	$0F,$31,$00,$25

		SECTION_END	"SCR7 CODE AND DATA"

		SECTION_START

; NOTE: even if all these sprites are set in libraries 08 and 09, they copied here
; as well. also an ending libraries contains more copies... this is fine for
; not care about actual sprite data locations or not care about optimizations
; (at least there are a lot of free space anyway), however, this may be optimized
; as well
;
		SPR_LIB_START	_spr_libA00

		SPR_IDX	_sprA00_00	; title logo patch for ghost hole
		SPR_IDX	_sprA00_01
		SPR_IDX	_sprA00_02	; title slime animation
		SPR_IDX	_sprA00_03
		SPR_IDX	_sprA00_04	; title buster A animations
		SPR_IDX	_sprA08_0A
		SPR_IDX	_sprA08_09
		SPR_IDX	_sprA08_0B
		SPR_IDX	_sprA08_0E
		SPR_IDX	_sprA08_0D
		SPR_IDX	_sprA08_0F
		SPR_IDX	_sprA00_0B
		SPR_IDX	_sprA00_0C
		SPR_IDX	_sprA00_0D
		SPR_IDX	_sprA00_0E
		SPR_IDX	_sprA00_0F
		SPR_IDX	_sprA00_10	; title buster B anim
		SPR_IDX	_sprA08_2A
		SPR_IDX	_sprA08_29
		SPR_IDX	_sprA08_2B
		SPR_IDX	_sprA08_2E
		SPR_IDX	_sprA08_2D
		SPR_IDX	_sprA08_2F
		SPR_IDX	_sprA00_17
		SPR_IDX	_sprA00_18
		SPR_IDX	_sprA00_19
		SPR_IDX	_sprA00_1A
		SPR_IDX	_sprA00_1B
		SPR_IDX	_sprA00_1C	; title buster C anim
		SPR_IDX	_sprA08_3A
		SPR_IDX	_sprA08_39
		SPR_IDX	_sprA08_3B
		SPR_IDX	_sprA08_3E
		SPR_IDX	_sprA08_3D
		SPR_IDX	_sprA08_3F
		SPR_IDX	_sprA00_23
		SPR_IDX	_sprA00_24
		SPR_IDX	_sprA00_25
		SPR_IDX	_sprA00_26
		SPR_IDX	_sprA00_27
		SPR_IDX	_sprA00_28	; title buster D anim
		SPR_IDX	_sprA08_1A
		SPR_IDX	_sprA08_19
		SPR_IDX	_sprA08_1B
		SPR_IDX	_sprA08_1E
		SPR_IDX	_sprA08_1D
		SPR_IDX	_sprA08_1F
		SPR_IDX	_sprA00_2F
		SPR_IDX	_sprA00_30
		SPR_IDX	_sprA00_31
		SPR_IDX	_sprA00_32
		SPR_IDX	_sprA00_33
		SPR_IDX	_sprA08_4A	; buster select louis
		SPR_IDX	_sprA08_42
		SPR_IDX	_sprA08_41
		SPR_IDX	_sprA08_43
		SPR_IDX	_sprA08_4E
		SPR_IDX	_sprA08_4D
		SPR_IDX	_sprA08_4F
		SPR_IDX	_sprA00_3B
		SPR_IDX	_sprA00_3C
		SPR_IDX	_sprA00_3D
		SPR_IDX	_sprA00_3E
		SPR_IDX	_sprA00_3F
		SPR_IDX	_sprA00_40	; select buster name overlays
		SPR_IDX	_sprA00_41
		SPR_IDX	_sprA00_42
		SPR_IDX	_sprA00_43
		SPR_IDX	_sprA00_44
		SPR_IDX	_sprA00_45
		SPR_IDX	_sprA00_46	; title ghost logo
		SPR_IDX	_sprA00_47
		SPR_IDX	_sprA00_48
		SPR_IDX	_sprA00_49
		SPR_IDX	_sprA00_4A
		SPR_IDX	_sprA00_4B
		SPR_IDX	_sprA00_4C

_sprA00_00:
		.BYTE	$0C
		.BYTE	$00,$86,$02,$E8
		.BYTE	$00,$96,$02,$F0
		.BYTE	$00,$A6,$02,$F8
		.BYTE	$00,$B6,$02,$00
		.BYTE	$00,$C6,$02,$08
		.BYTE	$00,$D6,$02,$10
		.BYTE	$F0,$84,$02,$E8
		.BYTE	$F0,$94,$02,$F0
		.BYTE	$F0,$A4,$02,$F8
		.BYTE	$F0,$B4,$02,$00
		.BYTE	$F0,$C4,$02,$08
		.BYTE	$F0,$D4,$02,$10
_sprA00_01:
		.BYTE	$0C
		.BYTE	$00,$82,$02,$E8
		.BYTE	$00,$92,$02,$F0
		.BYTE	$00,$A2,$02,$F8
		.BYTE	$00,$B2,$02,$00
		.BYTE	$00,$C2,$02,$08
		.BYTE	$00,$D2,$02,$10
		.BYTE	$F0,$80,$02,$E8
		.BYTE	$F0,$90,$02,$F0
		.BYTE	$F0,$A0,$02,$F8
		.BYTE	$F0,$B0,$02,$00
		.BYTE	$F0,$C0,$02,$08
		.BYTE	$F0,$D0,$02,$10
_sprA00_02:
		.BYTE	$04
		.BYTE	$00,$8A,$03,$F8
		.BYTE	$00,$8A,$43,$00
		.BYTE	$F0,$88,$03,$F8
		.BYTE	$F0,$88,$43,$00
_sprA00_03:
		.BYTE	$04
		.BYTE	$00,$8E,$03,$F8
		.BYTE	$00,$8E,$43,$00
		.BYTE	$F0,$8C,$03,$F8
		.BYTE	$F0,$8C,$43,$00
_sprA00_04:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$08,$00,$F8 ; _sprA08_0A_B
		.BYTE	$F0,$08,$40,$00
_sprA00_0B:
		.BYTE	$04
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$00,$7E,$00,$06
		.BYTE	$F0,$C8,$00,$FE
		.BYTE	$F0,$D8,$00,$06
_sprA00_0C:
		.BYTE	$04
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$00,$EC,$40,$00
		.BYTE	$F0,$E0,$00,$F8
		.BYTE	$F0,$F0,$00,$00
_sprA00_0D:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$C8,$40,$FA
		.BYTE	$F0,$D8,$40,$F2
_sprA00_0E:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$18,$00,$F8 ; _sprA08_02_B
		.BYTE	$F0,$18,$40,$00
_sprA00_0F:
		.BYTE	$02
		.BYTE	$F0,$C8,$40,$FA
		.BYTE	$F0,$D8,$40,$F2
_sprA00_10:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$0C,$00,$F8 ; _sprA08_2A_B
		.BYTE	$F0,$0C,$40,$00
_sprA00_17:
		.BYTE	$04
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$00,$7E,$00,$06
		.BYTE	$F0,$CC,$00,$FE
		.BYTE	$F0,$DC,$00,$06
_sprA00_18:
		.BYTE	$04
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$00,$EC,$40,$00
		.BYTE	$F0,$E4,$00,$F8
		.BYTE	$F0,$F4,$00,$00
_sprA00_19:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$CC,$40,$FA
		.BYTE	$F0,$DC,$40,$F2
_sprA00_1A:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$1C,$00,$F8 ; _sprA08_22_B
		.BYTE	$F0,$1C,$40,$00
_sprA00_1B:
		.BYTE	$02
		.BYTE	$F0,$CC,$40,$FA
		.BYTE	$F0,$DC,$40,$F2
_sprA00_1C:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$0E,$00,$F8 ; _sprA08_3A_B
		.BYTE	$F0,$0E,$40,$00
_sprA00_23:
		.BYTE	$04
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$00,$7E,$00,$06
		.BYTE	$F0,$CE,$00,$FE
		.BYTE	$F0,$DE,$00,$06
_sprA00_24:
		.BYTE	$04
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$00,$EC,$40,$00
		.BYTE	$F0,$E6,$00,$F8
		.BYTE	$F0,$F6,$00,$00
_sprA00_25:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$CE,$40,$FA
		.BYTE	$F0,$DE,$40,$F2
_sprA00_26:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$1E,$00,$F8 ; _sprA08_32_B
		.BYTE	$F0,$1E,$40,$00
_sprA00_27:
		.BYTE	$02
		.BYTE	$F0,$CE,$40,$FA
		.BYTE	$F0,$DE,$40,$F2
_sprA00_28:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$0A,$00,$F8 ; _sprA08_1A_B
		.BYTE	$F0,$0A,$40,$00
_sprA00_2F:
		.BYTE	$04
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$00,$7E,$00,$06
		.BYTE	$F0,$CA,$00,$FE
		.BYTE	$F0,$DA,$00,$06
_sprA00_30:
		.BYTE	$04
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$00,$EC,$40,$00
		.BYTE	$F0,$E2,$00,$F8
		.BYTE	$F0,$F2,$00,$00
_sprA00_31:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$CA,$40,$FA
		.BYTE	$F0,$DA,$40,$F2
_sprA00_32:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$1A,$00,$F8 ; _sprA08_12_B
		.BYTE	$F0,$1A,$40,$00
_sprA00_33:
		.BYTE	$02
		.BYTE	$F0,$CA,$40,$FA
		.BYTE	$F0,$DA,$40,$F2
_sprA00_3B:
		.BYTE	$04
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$00,$7E,$00,$06
		.BYTE	$F0,$EA,$00,$FE
		.BYTE	$F0,$FA,$00,$06
_sprA00_3C:
		.BYTE	$04
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$00,$EC,$40,$00
		.BYTE	$F0,$E8,$00,$F8
		.BYTE	$F0,$F8,$00,$00
_sprA00_3D:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$EA,$40,$FA
		.BYTE	$F0,$FA,$40,$F2
_sprA00_3E:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$32,$00,$F8 ; _sprA08_42_B
		.BYTE	$F0,$32,$40,$00
_sprA00_3F:
		.BYTE	$02
		.BYTE	$F0,$EA,$40,$FA
		.BYTE	$F0,$FA,$40,$F2
_sprA00_40:
		.BYTE	$05
		.BYTE	$F4,$D3,$02,$04
		.BYTE	$F4,$D3,$02,$F4
		.BYTE	$F4,$E9,$02,$EC
		.BYTE	$F4,$ED,$02,$0C
		.BYTE	$F4,$F1,$02,$FC
_sprA00_41:
		.BYTE	$03
		.BYTE	$F4,$CB,$02,$FC
		.BYTE	$F4,$ED,$02,$F4
		.BYTE	$F4,$FB,$02,$04
_sprA00_42:
		.BYTE	$04
		.BYTE	$F4,$D3,$02,$F0
		.BYTE	$F4,$D7,$02,$F8
		.BYTE	$F4,$E5,$02,$08
		.BYTE	$F4,$E7,$02,$00
_sprA00_43:
		.BYTE	$07
		.BYTE	$F4,$DB,$02,$EC
		.BYTE	$F4,$E5,$02,$14
		.BYTE	$F4,$E5,$02,$F4
		.BYTE	$F4,$E7,$02,$0C
		.BYTE	$F4,$EF,$02,$FC
		.BYTE	$F4,$F1,$02,$04
		.BYTE	$F4,$F7,$02,$E4
_sprA00_44:
		.BYTE	$05
		.BYTE	$F4,$DB,$02,$04
		.BYTE	$F4,$E1,$02,$EC
		.BYTE	$F4,$E7,$02,$F4
		.BYTE	$F4,$EF,$02,$0C
		.BYTE	$F4,$F3,$02,$FC
_sprA00_45:
		.BYTE	$02
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
_sprA00_46:
		.BYTE	$06
		.BYTE	$00,$DD,$02,$F4
		.BYTE	$00,$ED,$02,$FC
		.BYTE	$00,$FD,$02,$04
		.BYTE	$F0,$DB,$02,$F4
		.BYTE	$F0,$EB,$02,$FC
		.BYTE	$F0,$FB,$02,$04
_sprA00_47:
		.BYTE	$04
		.BYTE	$00,$E9,$02,$F8
		.BYTE	$00,$F9,$02,$00
		.BYTE	$F0,$E7,$02,$F8
		.BYTE	$F0,$F7,$02,$00
_sprA00_48:
		.BYTE	$04
		.BYTE	$00,$C9,$02,$F8
		.BYTE	$00,$D9,$02,$00
		.BYTE	$F0,$C7,$02,$F8
		.BYTE	$F0,$D7,$02,$00
_sprA00_49:
		.BYTE	$04
		.BYTE	$00,$A9,$02,$F8
		.BYTE	$00,$B9,$02,$00
		.BYTE	$F0,$A7,$02,$F8
		.BYTE	$F0,$B7,$02,$00
_sprA00_4A:
		.BYTE	$07
		.BYTE	$00,$69,$02,$F4
		.BYTE	$00,$79,$02,$FC
		.BYTE	$00,$89,$02,$04
		.BYTE	$F0,$67,$02,$F4
		.BYTE	$F0,$77,$02,$FC
		.BYTE	$F0,$87,$02,$04
		.BYTE	$F0,$97,$02,$0C
_sprA00_4B:
		.BYTE	$0B
		.BYTE	$00,$1B,$02,$FC
		.BYTE	$00,$2B,$02,$04
		.BYTE	$00,$6B,$00,$F4
		.BYTE	$00,$7B,$00,$FC
		.BYTE	$00,$8B,$00,$04
		.BYTE	$00,$CB,$02,$F4
		.BYTE	$F0,$07,$02,$04
		.BYTE	$F0,$17,$02,$0C
		.BYTE	$F0,$19,$02,$FC
		.BYTE	$F0,$99,$02,$F4
		.BYTE	$F0,$9B,$00,$04
_sprA00_4C:
		.BYTE	$0E
		.BYTE	$00,$6F,$01,$E0
		.BYTE	$00,$7F,$01,$E8
		.BYTE	$00,$8F,$01,$F0
		.BYTE	$00,$9F,$01,$F8
		.BYTE	$00,$AF,$01,$00
		.BYTE	$00,$BF,$01,$08
		.BYTE	$00,$CF,$01,$10
		.BYTE	$F0,$6D,$01,$E0
		.BYTE	$F0,$7D,$01,$E8
		.BYTE	$F0,$8D,$01,$F0
		.BYTE	$F0,$9D,$01,$F8
		.BYTE	$F0,$AD,$01,$00
		.BYTE	$F0,$BD,$01,$08
		.BYTE	$F0,$CD,$01,$10

; NOTE: here is the ending sprites, many of them copy the regular players
; sprites and may of them not used in the ending at all...
;
		SPR_LIB_START	_spr_libA07

		SPR_IDX	_sprA07_00
		SPR_IDX	_sprA07_01
		SPR_IDX	_sprA07_02
		SPR_IDX	_sprA07_03
		SPR_IDX	_sprA07_04
		SPR_IDX	_sprA07_05
		SPR_IDX	_sprA07_06
		SPR_IDX	_sprA07_07
		SPR_IDX	_sprA07_08
		SPR_IDX	_sprA07_09
		SPR_IDX	_sprA07_0A
		SPR_IDX	_sprA07_0B
		SPR_IDX	_sprA07_0C
		SPR_IDX	_sprA07_0D
		SPR_IDX	_sprA07_0E
		SPR_IDX	_sprA07_0F
		SPR_IDX	_sprA07_10
		SPR_IDX	_sprA07_11
		SPR_IDX	_sprA07_12
		SPR_IDX	_sprA07_13
		SPR_IDX	_sprA07_14	; unused
		SPR_IDX	_sprA07_15	; unused
		SPR_IDX	_sprA07_16	; unused
		SPR_IDX	_sprA07_17
		SPR_IDX	_sprA07_18
		SPR_IDX	_sprA07_19
		SPR_IDX	_sprA07_1A
		SPR_IDX	_sprA07_1B	; unused
		SPR_IDX	_sprA07_1C	; unused
		SPR_IDX	_sprA07_1D
		SPR_IDX	_sprA07_1E
		SPR_IDX	_sprA07_1F
		SPR_IDX	_sprA07_20	; unused
		SPR_IDX	_sprA07_21	; unused
		SPR_IDX	_sprA07_22	; unused
		SPR_IDX	_sprA07_23
		SPR_IDX	_sprA07_24
		SPR_IDX	_sprA07_25
		SPR_IDX	_sprA07_26
		SPR_IDX	_sprA07_27	; unused
		SPR_IDX	_sprA07_28	; unused
		SPR_IDX	_sprA07_29
		SPR_IDX	_sprA07_2A
		SPR_IDX	_sprA07_2B
		SPR_IDX	_sprA07_2C
		SPR_IDX	_sprA07_2D	; unused
		SPR_IDX	_sprA07_2E	; unused
		SPR_IDX	_sprA07_2F
		SPR_IDX	_sprA07_30
		SPR_IDX	_sprA07_31
		SPR_IDX	_sprA07_32	; unused
		SPR_IDX	_sprA07_33	; unused
		SPR_IDX	_sprA07_34	; unused
		SPR_IDX	_sprA07_35
		SPR_IDX	_sprA07_36
		SPR_IDX	_sprA07_37
		SPR_IDX	_sprA07_38
		SPR_IDX	_sprA07_39	; unused
		SPR_IDX	_sprA07_3A	; unused
		SPR_IDX	_sprA07_3B
		SPR_IDX	_sprA07_3C
		SPR_IDX	_sprA07_3D
		SPR_IDX	_sprA07_3E	; unused
		SPR_IDX	_sprA07_3F	; unused
		SPR_IDX	_sprA07_40	; unused
		SPR_IDX	_sprA07_41
		SPR_IDX	_sprA07_42
		SPR_IDX	_sprA07_43
		SPR_IDX	_sprA07_44	; unused
		SPR_IDX	_sprA07_45	; unused
		SPR_IDX	_sprA07_46	; unused
		SPR_IDX	_sprA07_47
		SPR_IDX	_sprA07_48
		SPR_IDX	_sprA07_49
		SPR_IDX	_sprA07_4A
		SPR_IDX	_sprA07_4B	; unused
		SPR_IDX	_sprA07_4C	; unused
		SPR_IDX	_sprA07_4D
		SPR_IDX	_sprA07_4E
		SPR_IDX	_sprA07_4F
		SPR_IDX	_sprA07_50
		SPR_IDX	_sprA07_51
		SPR_IDX	_sprA07_52
		SPR_IDX	_sprA07_53
		SPR_IDX	_sprA07_54
		SPR_IDX	_sprA07_55
		SPR_IDX	_sprA07_56
		SPR_IDX	_sprA07_57
		SPR_IDX	_sprA07_58
		SPR_IDX	_sprA07_59
		SPR_IDX	_sprA07_5A
		SPR_IDX	_sprA07_5B
		SPR_IDX	_sprA07_5C
		SPR_IDX	_sprA07_5D
		SPR_IDX	_sprA07_5E
		SPR_IDX	_sprA07_5F
		SPR_IDX	_sprA07_60
		SPR_IDX	_sprA07_61
		SPR_IDX	_sprA07_62
		SPR_IDX	_sprA07_63
		SPR_IDX	_sprA07_64
		SPR_IDX	_sprA07_65
		SPR_IDX	_sprA07_66
		SPR_IDX	_sprA07_67
		SPR_IDX	_sprA07_68
		SPR_IDX	_sprA07_69
		SPR_IDX	_sprA07_6A
		SPR_IDX	_sprA07_6B
		SPR_IDX	_sprA07_6C
		SPR_IDX	_sprA07_6D
		SPR_IDX	_sprA07_6E
		SPR_IDX	_sprA07_6F
		SPR_IDX	_sprA07_70
; NOTE, sprites between 70 and AE are shared in system bank
; to optimize sprites data
		SPR_IDX	_sprA08_02	; unused
		SPR_IDX	_sprA08_01	; unused
		SPR_IDX	_sprA08_03	; unused
		SPR_IDX	_sprA08_06
		SPR_IDX	_sprA08_05
		SPR_IDX	_sprA08_07
		SPR_IDX	_sprA08_0A	; unused
		SPR_IDX	_sprA08_09	; unused
		SPR_IDX	_sprA08_0B	; unused
		SPR_IDX	_sprA08_0E
		SPR_IDX	_sprA08_0D	; unused
		SPR_IDX	_sprA08_0F	; unused
		SPR_IDX	_sprA08_12	; unused
		SPR_IDX	_sprA08_11	; unused
		SPR_IDX	_sprA08_13	; unused
		SPR_IDX	_sprA08_16
		SPR_IDX	_sprA08_15
		SPR_IDX	_sprA08_17
		SPR_IDX	_sprA08_1A
		SPR_IDX	_sprA08_19	; unused
		SPR_IDX	_sprA08_1B	; unused
		SPR_IDX	_sprA08_1E
		SPR_IDX	_sprA08_1D	; unused
		SPR_IDX	_sprA08_1F	; unused
		SPR_IDX	_sprA08_22	; unused
		SPR_IDX	_sprA08_21	; unused
		SPR_IDX	_sprA08_23	; unused
		SPR_IDX	_sprA08_26
		SPR_IDX	_sprA08_25
		SPR_IDX	_sprA08_27
		SPR_IDX	_sprA08_2A
		SPR_IDX	_sprA08_29	; unused
		SPR_IDX	_sprA08_2B	; unused
		SPR_IDX	_sprA08_2E
		SPR_IDX	_sprA08_2D
		SPR_IDX	_sprA08_2F
		SPR_IDX	_sprA08_32	; unused
		SPR_IDX	_sprA08_31	; unused
		SPR_IDX	_sprA08_33	; unused
		SPR_IDX	_sprA08_36
		SPR_IDX	_sprA08_35
		SPR_IDX	_sprA08_37
		SPR_IDX	_sprA08_3A
		SPR_IDX	_sprA08_39	; unused
		SPR_IDX	_sprA08_3B	; unused
		SPR_IDX	_sprA08_3E
		SPR_IDX	_sprA08_3D
		SPR_IDX	_sprA08_3F
		SPR_IDX	_sprA08_42	; unused
		SPR_IDX	_sprA08_41	; unused
		SPR_IDX	_sprA08_43	; unused
		SPR_IDX	_sprA08_46
		SPR_IDX	_sprA08_45
		SPR_IDX	_sprA08_47
		SPR_IDX	_sprA08_4A
		SPR_IDX	_sprA08_49	; unused
		SPR_IDX	_sprA08_4B	; unused
		SPR_IDX	_sprA08_4E
		SPR_IDX	_sprA08_4D	; unused
		SPR_IDX	_sprA08_4F	; unused
		SPR_IDX	_sprA07_AD
		SPR_IDX	_sprA07_AE
		SPR_IDX	_sprA07_AF
		SPR_IDX	_sprA07_B0
		SPR_IDX	_sprA07_B1
		SPR_IDX	_sprA07_B2
		SPR_IDX	_sprA07_B3
		SPR_IDX	_sprA07_B4
		SPR_IDX	_sprA07_B5
		SPR_IDX	_sprA07_B6
		SPR_IDX	_sprA07_B7
		SPR_IDX	_sprA07_B8
		SPR_IDX	_sprA07_B9
		SPR_IDX	_sprA07_BA
		SPR_IDX	_sprA07_BB
		SPR_IDX	_sprA07_BC

		SPR_LIB_START	_spr_libB07

		SPR_IDX	_sprB07_C0
		SPR_IDX	_sprB07_C1
		SPR_IDX	_sprB07_C2
		SPR_IDX	_sprB07_C3
		SPR_IDX	_sprB07_C4
		SPR_IDX	_sprB07_C5
		SPR_IDX	_sprB07_C6
		SPR_IDX	_sprB07_C7
		SPR_IDX	_sprB07_C8
		SPR_IDX	_sprB07_C9
		SPR_IDX	_sprB07_CA
		SPR_IDX	_sprB07_CB
		SPR_IDX	_sprB07_CC
		SPR_IDX	_sprB07_CD
		SPR_IDX	_sprB07_CE
		SPR_IDX	_sprB07_CF
		SPR_IDX	_sprB07_D0
		SPR_IDX	_sprB07_D1
		SPR_IDX	_sprB07_D2

_sprA07_00:
		.BYTE	$04
		.BYTE	$00,$A2,$22,$F8
		.BYTE	$00,$B2,$22,$00
		.BYTE	$F0,$A0,$22,$F8
		.BYTE	$F0,$B0,$22,$00
_sprA07_01:
		.BYTE	$05
		.BYTE	$00,$82,$22,$F8
		.BYTE	$00,$92,$22,$00
		.BYTE	$EF,$94,$20,$F8
		.BYTE	$F0,$80,$22,$F8
		.BYTE	$F0,$90,$22,$00
_sprA07_02:
		.BYTE	$05
		.BYTE	$00,$82,$22,$F8
		.BYTE	$00,$92,$22,$00
		.BYTE	$F0,$80,$22,$F8
		.BYTE	$F0,$90,$22,$00
		.BYTE	$F1,$94,$20,$F4
_sprA07_03:
		.BYTE	$04
		.BYTE	$00,$C2,$62,$00
		.BYTE	$00,$D2,$62,$F8
		.BYTE	$F0,$C0,$62,$00
		.BYTE	$F0,$D0,$62,$F8
_sprA07_04:
		.BYTE	$04
		.BYTE	$00,$C2,$62,$00
		.BYTE	$00,$D2,$62,$F8
		.BYTE	$F1,$C0,$62,$00
		.BYTE	$F1,$D0,$62,$F8
_sprA07_05:
		.BYTE	$04
		.BYTE	$00,$E2,$22,$F8
		.BYTE	$00,$F2,$22,$00
		.BYTE	$F0,$E0,$22,$F8
		.BYTE	$F0,$F0,$22,$00
_sprA07_06:
		.BYTE	$04
		.BYTE	$00,$E6,$22,$F8
		.BYTE	$00,$F6,$22,$00
		.BYTE	$F0,$E4,$22,$F8
		.BYTE	$F0,$F4,$22,$00
_sprA07_07:
		.BYTE	$07
		.BYTE	$08,$8A,$23,$F8
		.BYTE	$08,$9A,$23,$00
		.BYTE	$D9,$84,$21,$FA
		.BYTE	$E8,$86,$23,$F8
		.BYTE	$E8,$96,$23,$00
		.BYTE	$F8,$88,$23,$F8
		.BYTE	$F8,$98,$23,$00
_sprA07_08:
		.BYTE	$07
		.BYTE	$07,$AA,$23,$F8
		.BYTE	$07,$BA,$23,$00
		.BYTE	$D7,$B4,$21,$FA
		.BYTE	$E7,$A6,$23,$F8
		.BYTE	$E7,$B6,$23,$00
		.BYTE	$F7,$A8,$23,$F8
		.BYTE	$F7,$B8,$23,$00
_sprA07_09:
		.BYTE	$07
		.BYTE	$08,$CA,$23,$F8
		.BYTE	$08,$DA,$23,$00
		.BYTE	$D9,$84,$61,$FB
		.BYTE	$E8,$86,$23,$F8
		.BYTE	$E8,$96,$23,$00
		.BYTE	$F8,$88,$23,$F8
		.BYTE	$F8,$98,$23,$00
_sprA07_0A:
		.BYTE	$07
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$08,$D8,$03,$00
		.BYTE	$D8,$84,$01,$F7
		.BYTE	$E8,$C4,$03,$F8
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
_sprA07_0B:
		.BYTE	$07
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$08,$D8,$03,$00
		.BYTE	$D8,$B4,$01,$F7
		.BYTE	$E8,$C4,$03,$F8
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
_sprA07_0C:
		.BYTE	$07
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$08,$D8,$03,$00
		.BYTE	$D8,$84,$41,$F8
		.BYTE	$E8,$C4,$03,$F8
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
_sprA07_0D:
		.BYTE	$07
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$08,$D8,$03,$00
		.BYTE	$D7,$B4,$41,$F8
		.BYTE	$E8,$C4,$03,$F8
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
_sprA07_0E:
		.BYTE	$06
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$F8,$E8,$60,$F2
_sprA07_0F:
		.BYTE	$06
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$F8,$E6,$60,$F2
_sprA07_10:
		.BYTE	$08
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$02,$58,$60,$EF
		.BYTE	$EF,$58,$60,$F3
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$F8,$E6,$60,$F2
_sprA07_11:
		.BYTE	$08
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$02,$48,$60,$EF
		.BYTE	$EF,$48,$60,$F3
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$F8,$E8,$60,$F2
_sprA07_12:
		.BYTE	$06
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$EE,$D8,$60,$FB
		.BYTE	$EE,$E8,$60,$F3
		.BYTE	$F0,$CA,$62,$00
		.BYTE	$F0,$DA,$62,$F8
_sprA07_13:
		.BYTE	$06
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$EE,$D6,$60,$FB
		.BYTE	$EE,$E6,$60,$F3
		.BYTE	$F0,$CA,$62,$00
		.BYTE	$F0,$DA,$62,$F8
_sprA07_14:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$18,$20,$F8
		.BYTE	$F0,$18,$60,$00
_sprA07_15:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$18,$20,$F8
		.BYTE	$F1,$18,$60,$00
_sprA07_16:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$18,$20,$F8
		.BYTE	$F1,$18,$60,$00
_sprA07_17:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$00,$60,$00
		.BYTE	$F0,$10,$60,$F8
_sprA07_18:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$00,$60,$00
		.BYTE	$F1,$10,$60,$F8
_sprA07_19:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$00,$60,$00
		.BYTE	$F1,$10,$60,$F8
_sprA07_1A:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$08,$20,$F8
		.BYTE	$F0,$08,$60,$00
_sprA07_1B:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$08,$20,$F8
		.BYTE	$F1,$08,$60,$00
_sprA07_1C:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$08,$20,$F8
		.BYTE	$F1,$08,$60,$00
_sprA07_1D:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$00,$20,$F8
		.BYTE	$F0,$10,$20,$00
_sprA07_1E:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$00,$20,$F8
		.BYTE	$F1,$10,$20,$00
_sprA07_1F:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$00,$20,$F8
		.BYTE	$F1,$10,$20,$00
_sprA07_20:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$1A,$20,$F8
		.BYTE	$F0,$1A,$60,$00
_sprA07_21:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$1A,$20,$F8
		.BYTE	$F1,$1A,$60,$00
_sprA07_22:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$1A,$20,$F8
		.BYTE	$F1,$1A,$60,$00
_sprA07_23:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$02,$60,$00
		.BYTE	$F0,$12,$60,$F8
_sprA07_24:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$02,$60,$00
		.BYTE	$F1,$12,$60,$F8
_sprA07_25:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$02,$60,$00
		.BYTE	$F1,$12,$60,$F8
_sprA07_26:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$0A,$20,$F8
		.BYTE	$F0,$0A,$60,$00
_sprA07_27:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$0A,$20,$F8
		.BYTE	$F1,$0A,$60,$00
_sprA07_28:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$0A,$20,$F8
		.BYTE	$F1,$0A,$60,$00
_sprA07_29:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$02,$20,$F8
		.BYTE	$F0,$12,$20,$00
_sprA07_2A:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$02,$20,$F8
		.BYTE	$F1,$12,$20,$00
_sprA07_2B:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$02,$20,$F8
		.BYTE	$F1,$12,$20,$00
_sprA07_2C:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$1C,$20,$F8
		.BYTE	$F0,$1C,$60,$00
_sprA07_2D:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$1C,$20,$F8
		.BYTE	$F1,$1C,$60,$00
_sprA07_2E:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$1C,$20,$F8
		.BYTE	$F1,$1C,$60,$00
_sprA07_2F:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$04,$60,$00
		.BYTE	$F0,$14,$60,$F8
_sprA07_30:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$04,$60,$00
		.BYTE	$F1,$14,$60,$F8
_sprA07_31:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$04,$60,$00
		.BYTE	$F1,$14,$60,$F8
_sprA07_32:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$0C,$20,$F8
		.BYTE	$F0,$0C,$60,$00
_sprA07_33:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$0C,$20,$F8
		.BYTE	$F1,$0C,$60,$00
_sprA07_34:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$0C,$20,$F8
		.BYTE	$F1,$0C,$60,$00
_sprA07_35:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$04,$20,$F8
		.BYTE	$F0,$14,$20,$00
_sprA07_36:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$04,$20,$F8
		.BYTE	$F1,$14,$20,$00
_sprA07_37:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$04,$20,$F8
		.BYTE	$F1,$14,$20,$00
_sprA07_38:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$1E,$20,$F8
		.BYTE	$F0,$1E,$60,$00
_sprA07_39:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$1E,$20,$F8
		.BYTE	$F1,$1E,$60,$00
_sprA07_3A:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$1E,$20,$F8
		.BYTE	$F1,$1E,$60,$00
_sprA07_3B:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$06,$60,$00
		.BYTE	$F0,$16,$60,$F8
_sprA07_3C:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$06,$60,$00
		.BYTE	$F1,$16,$60,$F8
_sprA07_3D:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$06,$60,$00
		.BYTE	$F1,$16,$60,$F8
_sprA07_3E:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$0E,$20,$F8
		.BYTE	$F0,$0E,$60,$00
_sprA07_3F:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$0E,$20,$F8
		.BYTE	$F1,$0E,$60,$00
_sprA07_40:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$0E,$20,$F8
		.BYTE	$F1,$0E,$60,$00
_sprA07_41:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$06,$20,$F8
		.BYTE	$F0,$16,$20,$00
_sprA07_42:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$06,$20,$F8
		.BYTE	$F1,$16,$20,$00
_sprA07_43:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$06,$20,$F8
		.BYTE	$F1,$16,$20,$00
_sprA07_44:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$32,$20,$F8
		.BYTE	$F0,$32,$60,$00
_sprA07_45:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$32,$20,$F8
		.BYTE	$F1,$32,$60,$00
_sprA07_46:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$32,$20,$F8
		.BYTE	$F1,$32,$60,$00
_sprA07_47:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$20,$60,$00
		.BYTE	$F0,$30,$60,$F8
_sprA07_48:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$20,$60,$00
		.BYTE	$F1,$30,$60,$F8
_sprA07_49:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$20,$60,$00
		.BYTE	$F1,$30,$60,$F8
_sprA07_4A:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$22,$20,$F8
		.BYTE	$F0,$22,$60,$00
_sprA07_4B:
		.BYTE	$04
		.BYTE	$00,$24,$20,$F8
		.BYTE	$00,$34,$20,$00
		.BYTE	$F1,$22,$20,$F8
		.BYTE	$F1,$22,$60,$00
_sprA07_4C:
		.BYTE	$04
		.BYTE	$00,$24,$60,$00
		.BYTE	$00,$34,$60,$F8
		.BYTE	$F1,$22,$20,$F8
		.BYTE	$F1,$22,$60,$00
_sprA07_4D:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$20,$20,$F8
		.BYTE	$F0,$30,$20,$00
_sprA07_4E:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$20,$20,$F8
		.BYTE	$F1,$30,$20,$00
_sprA07_4F:
		.BYTE	$04
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$20,$20,$F8
		.BYTE	$F1,$30,$20,$00
_sprA07_50:
		.BYTE	$04
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$01,$4E,$60,$00
		.BYTE	$F4,$08,$20,$F8
		.BYTE	$F4,$08,$60,$00
_sprA07_51:
		.BYTE	$04
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$01,$4E,$60,$00
		.BYTE	$F5,$08,$20,$F8
		.BYTE	$F5,$08,$60,$00
_sprA07_52:
		.BYTE	$04
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$01,$4E,$60,$00
		.BYTE	$F4,$00,$60,$00
		.BYTE	$F4,$10,$60,$F8
_sprA07_53:
		.BYTE	$04
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$01,$4E,$60,$00
		.BYTE	$F4,$0A,$20,$F8
		.BYTE	$F4,$0A,$60,$00
_sprA07_54:
		.BYTE	$04
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$01,$4E,$60,$00
		.BYTE	$F5,$0A,$20,$F8
		.BYTE	$F5,$0A,$60,$00
_sprA07_55:
		.BYTE	$04
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$01,$4E,$60,$00
		.BYTE	$F4,$02,$20,$F8
		.BYTE	$F4,$12,$20,$00
_sprA07_56:
		.BYTE	$04
		.BYTE	$EF,$A8,$62,$00
		.BYTE	$EF,$B8,$62,$F8
		.BYTE	$FF,$8C,$62,$00
		.BYTE	$FF,$9C,$62,$F8
_sprA07_57:
		.BYTE	$04
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$00,$AC,$62,$00
		.BYTE	$F0,$AA,$62,$00
		.BYTE	$F0,$B8,$62,$F8
_sprA07_58:
		.BYTE	$04
		.BYTE	$EF,$AA,$62,$00
		.BYTE	$EF,$BA,$62,$F8
		.BYTE	$FF,$8C,$22,$F8
		.BYTE	$FF,$9C,$22,$00
_sprA07_59:
		.BYTE	$04
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$00,$AC,$62,$00
		.BYTE	$F0,$AA,$62,$00
		.BYTE	$F0,$BA,$62,$F8
_sprA07_5A:
		.BYTE	$04
		.BYTE	$EF,$A8,$22,$F8
		.BYTE	$EF,$B8,$22,$00
		.BYTE	$FF,$8C,$22,$F8
		.BYTE	$FF,$9C,$22,$00
_sprA07_5B:
		.BYTE	$04
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$00,$AC,$62,$00
		.BYTE	$F0,$AA,$22,$F8
		.BYTE	$F0,$B8,$22,$00
_sprA07_5C:
		.BYTE	$04
		.BYTE	$EF,$AA,$22,$F8
		.BYTE	$EF,$BA,$22,$00
		.BYTE	$FF,$8C,$62,$00
		.BYTE	$FF,$9C,$62,$F8
_sprA07_5D:
		.BYTE	$04
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$00,$AC,$62,$00
		.BYTE	$F0,$AA,$22,$F8
		.BYTE	$F0,$BA,$22,$00
_sprA07_5E:
		.BYTE	$04
		.BYTE	$E8,$1C,$20,$F8
		.BYTE	$E8,$1C,$60,$00
		.BYTE	$F5,$5E,$23,$00
		.BYTE	$F5,$5E,$23,$FB
_sprA07_5F:
		.BYTE	$04
		.BYTE	$E8,$1E,$20,$F8
		.BYTE	$E8,$1E,$60,$00
		.BYTE	$F5,$5E,$23,$00
		.BYTE	$F5,$5E,$63,$F8
_sprA07_60:
		.BYTE	$05
		.BYTE	$00,$A6,$23,$F8
		.BYTE	$00,$B6,$23,$00
		.BYTE	$00,$BA,$23,$F0
		.BYTE	$F0,$A4,$23,$F8
		.BYTE	$F0,$B4,$23,$00
_sprA07_61:
		.BYTE	$05
		.BYTE	$00,$86,$23,$F8
		.BYTE	$00,$96,$23,$00
		.BYTE	$F0,$84,$23,$F8
		.BYTE	$F0,$94,$23,$00
		.BYTE	$F0,$BC,$23,$F0
_sprA07_62:
		.BYTE	$05
		.BYTE	$00,$A6,$63,$00
		.BYTE	$00,$B6,$63,$F8
		.BYTE	$00,$BA,$63,$08
		.BYTE	$F0,$A4,$63,$00
		.BYTE	$F0,$B4,$63,$F8
_sprA07_63:
		.BYTE	$05
		.BYTE	$00,$86,$63,$00
		.BYTE	$00,$96,$63,$F8
		.BYTE	$F0,$84,$63,$00
		.BYTE	$F0,$94,$63,$F8
		.BYTE	$F0,$BC,$63,$08
_sprA07_64:
		.BYTE	$05
		.BYTE	$00,$86,$23,$F8
		.BYTE	$00,$96,$23,$00
		.BYTE	$F0,$23,$23,$F8
		.BYTE	$F0,$25,$23,$00
		.BYTE	$F0,$9C,$23,$F0
_sprA07_65:
		.BYTE	$05
		.BYTE	$00,$A6,$23,$F8
		.BYTE	$00,$B6,$23,$00
		.BYTE	$00,$BA,$23,$F0
		.BYTE	$F0,$27,$23,$F8
		.BYTE	$F0,$29,$23,$00
_sprA07_66:
		.BYTE	$05
		.BYTE	$00,$86,$63,$00
		.BYTE	$00,$96,$63,$F8
		.BYTE	$F0,$23,$63,$00
		.BYTE	$F0,$25,$63,$F8
		.BYTE	$F0,$9C,$63,$08
_sprA07_67:
		.BYTE	$05
		.BYTE	$00,$A6,$63,$00
		.BYTE	$00,$B6,$63,$F8
		.BYTE	$00,$BA,$63,$08
		.BYTE	$F0,$27,$63,$00
		.BYTE	$F0,$29,$63,$F8
_sprA07_68:
		.BYTE	$04
		.BYTE	$00,$A2,$23,$F8
		.BYTE	$00,$B2,$23,$00
		.BYTE	$F0,$3B,$23,$F8
		.BYTE	$F0,$3D,$23,$00
_sprA07_69:
		.BYTE	$02
		.BYTE	$F8,$AB,$23,$F8
		.BYTE	$F8,$BB,$23,$00
_sprA07_6A:
		.BYTE	$04
		.BYTE	$E0,$20,$20,$F8
		.BYTE	$E0,$30,$20,$00
		.BYTE	$F0,$4A,$20,$F8
		.BYTE	$F0,$5A,$20,$00
_sprA07_6B:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F2,$20,$20,$F8
		.BYTE	$F2,$30,$20,$00
_sprA07_6C:
		.BYTE	$06
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$22,$20,$F8
		.BYTE	$F0,$22,$60,$00
		.BYTE	$F9,$AB,$23,$F8
		.BYTE	$F9,$BB,$23,$00
_sprA07_6D:
		.BYTE	$06
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$20,$60,$00
		.BYTE	$F0,$30,$60,$F8
		.BYTE	$F8,$AB,$23,$03
		.BYTE	$F8,$BB,$23,$0B
_sprA07_6E:
		.BYTE	$06
		.BYTE	$00,$2A,$60,$00
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$20,$60,$00
		.BYTE	$F1,$30,$60,$F8
		.BYTE	$F9,$AB,$23,$04
		.BYTE	$F9,$BB,$23,$0C
_sprA07_6F:
		.BYTE	$06
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$20,$60,$00
		.BYTE	$F1,$30,$60,$F8
		.BYTE	$F9,$AB,$23,$04
		.BYTE	$F9,$BB,$23,$0C
_sprA07_70:
		.BYTE	$06
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$20,$20,$F8
		.BYTE	$F0,$30,$20,$00
		.BYTE	$F8,$AB,$63,$F5
		.BYTE	$F8,$BB,$63,$ED
_sprA07_AD:
		.BYTE	$04
		.BYTE	$00,$28,$00,$F8 ; _sprA08_0E_A
		.BYTE	$00,$38,$00,$00
		.BYTE	$F0,$82,$00,$F8
		.BYTE	$F0,$92,$00,$00
_sprA07_AE:
		.BYTE	$04
		.BYTE	$00,$84,$00,$F8
		.BYTE	$00,$94,$00,$00
		.BYTE	$F1,$82,$00,$F8
		.BYTE	$F1,$92,$00,$00
_sprA07_AF:
		.BYTE	$04
		.BYTE	$00,$84,$40,$00
		.BYTE	$00,$94,$40,$F8
		.BYTE	$F1,$82,$00,$F8
		.BYTE	$F1,$92,$00,$00
_sprA07_B0:
		.BYTE	$04
		.BYTE	$00,$28,$40,$00 ; _sprA08_06_A
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$82,$40,$00
		.BYTE	$F0,$92,$40,$F8
_sprA07_B1:
		.BYTE	$04
		.BYTE	$00,$84,$40,$00
		.BYTE	$00,$94,$40,$F8
		.BYTE	$F1,$82,$40,$00
		.BYTE	$F1,$92,$40,$F8
_sprA07_B2:
		.BYTE	$04
		.BYTE	$00,$84,$00,$F8
		.BYTE	$00,$94,$00,$00
		.BYTE	$F1,$82,$40,$00
		.BYTE	$F1,$92,$40,$F8
_sprA07_B3:
		.BYTE	$01
		.BYTE	$FC,$6E,$41,$FD
_sprA07_B4:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$0A,$00,$F8 ; _sprA08_1A_B
		.BYTE	$F0,$0A,$40,$00
_sprA07_B5:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$0C,$00,$F8 ; _sprA08_2A_B
		.BYTE	$F0,$0C,$40,$00
_sprA07_B6:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$0E,$00,$F8 ; _sprA08_3A_B
		.BYTE	$F0,$0E,$40,$00
_sprA07_B7:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00 ; 001
		.BYTE	$00,$5E,$40,$F8 ; 002
		.BYTE	$F0,$22,$00,$F8 ; _sprA08_4A_B
		.BYTE	$F0,$22,$40,$00
_sprA07_B8:
		.BYTE	$04
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$F8,$4C,$80,$F8
		.BYTE	$F8,$4C,$C0,$00
_sprA07_B9:
		.BYTE	$06
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$F0,$48,$80,$06
		.BYTE	$F1,$48,$80,$F3
		.BYTE	$F8,$4C,$80,$F8
		.BYTE	$F8,$4C,$C0,$00
_sprA07_BA:
		.BYTE	$06
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$EC,$58,$80,$F1
		.BYTE	$ED,$58,$80,$08
		.BYTE	$F8,$4C,$80,$F8
		.BYTE	$F8,$4C,$C0,$00
_sprA07_BB:
		.BYTE	$06
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$EA,$48,$80,$09
		.BYTE	$EA,$48,$80,$F0
		.BYTE	$F8,$4C,$80,$F8
		.BYTE	$F8,$4C,$C0,$00
_sprA07_BC:
		.BYTE	$0C
		.BYTE	$00,$8A,$03,$10
		.BYTE	$00,$8E,$03,$E0
		.BYTE	$00,$9A,$03,$18
		.BYTE	$00,$9E,$03,$E8
		.BYTE	$00,$AE,$03,$F8
		.BYTE	$00,$BE,$03,$00
		.BYTE	$F0,$88,$03,$10
		.BYTE	$F0,$8C,$03,$E0
		.BYTE	$F0,$98,$03,$18
		.BYTE	$F0,$9C,$03,$E8
		.BYTE	$F0,$AC,$03,$F8
		.BYTE	$F0,$BC,$03,$00
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
_sprB07_CB:
		.BYTE	$81
		.WORD	_sprB07_CB_A
_sprB07_CC:
		.BYTE	$81
		.WORD	_sprB07_CC_A
_sprB07_CD:
		.BYTE	$81
		.WORD	_sprB07_CD_A
_sprB07_CE:
		.BYTE	$81
		.WORD	_sprB07_CE_A
_sprB07_CF:
		.BYTE	$81
		.WORD	_sprB07_CF_A
_sprB07_D0:
		.BYTE	$81
		.WORD	_sprB07_D0_A
_sprB07_D1:
		.BYTE	$81
		.WORD	_sprB07_D1_A
_sprB07_D2:
		.BYTE	$81
		.WORD	_sprB07_D2_A
_sprB07_C0_A:
		.BYTE	$09
		.BYTE	$CE,$EC,$23,$F0
		.BYTE	$CE,$FC,$23,$F8
		.BYTE	$DC,$C8,$23,$F4
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$F8,$C2,$23,$04
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$E2,$23,$FC
_sprB07_C1_A:
		.BYTE	$0A
		.BYTE	$D4,$EC,$23,$01
		.BYTE	$D4,$FC,$23,$09
		.BYTE	$DD,$CC,$23,$F8
		.BYTE	$DD,$DC,$23,$00
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$F8,$C2,$23,$04
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$E2,$23,$FC
_sprB07_C2_A:
		.BYTE	$0A
		.BYTE	$E4,$EC,$23,$02
		.BYTE	$E4,$FC,$23,$0A
		.BYTE	$E8,$CA,$23,$F7
		.BYTE	$E8,$CA,$23,$FF
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$F8,$E6,$23,$FC
		.BYTE	$F8,$F6,$23,$04
_sprB07_C3_A:
		.BYTE	$0A
		.BYTE	$E4,$CC,$63,$F8
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F4,$EC,$23,$01
		.BYTE	$F4,$FC,$23,$09
		.BYTE	$F5,$DC,$63,$FF
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$F8,$E6,$23,$FC
		.BYTE	$F8,$F6,$23,$04
_sprB07_C4_A:
		.BYTE	$09
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$EF,$C8,$23,$F5
		.BYTE	$F8,$C2,$23,$04
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$E2,$23,$FC
		.BYTE	$FB,$EC,$23,$F1
		.BYTE	$FB,$FC,$23,$F9
_sprB07_C5_A:
		.BYTE	$0A
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$EE,$CC,$23,$E9
		.BYTE	$EE,$DC,$23,$F1
		.BYTE	$F6,$EC,$23,$E0
		.BYTE	$F6,$FC,$23,$E8
		.BYTE	$F8,$C6,$23,$04
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$E2,$23,$FC
_sprB07_C6_A:
		.BYTE	$0A
		.BYTE	$E6,$EC,$23,$DF
		.BYTE	$E6,$FC,$23,$E7
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$EA,$CA,$23,$EE
		.BYTE	$EA,$CA,$63,$E8
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$F8,$E6,$23,$FC
		.BYTE	$F8,$F6,$23,$04
_sprB07_C7_A:
		.BYTE	$0A
		.BYTE	$D7,$EC,$23,$E0
		.BYTE	$D7,$FC,$23,$E8
		.BYTE	$DD,$CC,$63,$EF
		.BYTE	$DD,$DC,$63,$E7
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$F8,$E6,$23,$FC
		.BYTE	$F8,$F6,$23,$04
_sprB07_C8_A:
		.BYTE	$09
		.BYTE	$09,$EC,$23,$EF
		.BYTE	$09,$FC,$23,$F7
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_C9_A:
		.BYTE	$0A
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1B,$EC,$23,$EF
		.BYTE	$1B,$FC,$23,$F7
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_CA_A:
		.BYTE	$0B
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$2C,$EC,$23,$F0
		.BYTE	$2C,$FC,$23,$F8
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_CB_A:
		.BYTE	$0C
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$3C,$EC,$23,$F0
		.BYTE	$3C,$FC,$23,$F8
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_CC_A:
		.BYTE	$0D
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$4D,$EC,$23,$F0
		.BYTE	$4D,$FC,$23,$F8
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_CD_A:
		.BYTE	$0E
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$4E,$C8,$23,$F3
		.BYTE	$5C,$EC,$23,$F0
		.BYTE	$5C,$FC,$23,$F8
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_CE_A:
		.BYTE	$10
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$4E,$C8,$23,$F3
		.BYTE	$5E,$C8,$23,$F3
		.BYTE	$C8,$C8,$23,$F3
		.BYTE	$D7,$EC,$23,$F0
		.BYTE	$D7,$EC,$63,$F8
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_CF_A:
		.BYTE	$14
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$4E,$C8,$23,$F3
		.BYTE	$5E,$C8,$23,$F3
		.BYTE	$BB,$C8,$23,$F4
		.BYTE	$C8,$C8,$23,$F3
		.BYTE	$D8,$C8,$23,$F3
		.BYTE	$E3,$48,$23,$FC
		.BYTE	$E4,$EC,$23,$EF
		.BYTE	$E4,$EC,$63,$F7
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$EF,$48,$23,$EB
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3
_sprB07_D0_A:
		.BYTE	$14
		.BYTE	$03,$C8,$23,$F3
		.BYTE	$13,$C8,$23,$F3
		.BYTE	$23,$C8,$23,$F3
		.BYTE	$33,$C8,$23,$F3
		.BYTE	$43,$C8,$23,$F3
		.BYTE	$53,$C8,$23,$F3
		.BYTE	$63,$C8,$23,$F3
		.BYTE	$C0,$C8,$23,$F4
		.BYTE	$CD,$C8,$23,$F3
		.BYTE	$DD,$C8,$23,$F3
		.BYTE	$E5,$58,$23,$FE
		.BYTE	$E9,$EC,$23,$EF
		.BYTE	$E9,$EC,$63,$F7
		.BYTE	$ED,$D8,$23,$F4
		.BYTE	$ED,$E4,$23,$FC
		.BYTE	$ED,$F8,$23,$04
		.BYTE	$F8,$58,$23,$EC
		.BYTE	$FD,$DA,$23,$F4
		.BYTE	$FD,$EA,$23,$FC
		.BYTE	$FD,$FA,$23,$04
_sprB07_D1_A:
		.BYTE	$12
		.BYTE	$03,$C8,$23,$F3
		.BYTE	$13,$C8,$23,$F3
		.BYTE	$23,$C8,$23,$F3
		.BYTE	$33,$C8,$23,$F3
		.BYTE	$43,$C8,$23,$F3
		.BYTE	$53,$C8,$23,$F3
		.BYTE	$63,$C8,$23,$F3
		.BYTE	$C0,$C8,$23,$F4
		.BYTE	$CD,$C8,$23,$F3
		.BYTE	$DD,$C8,$23,$F3
		.BYTE	$E9,$EC,$23,$EF
		.BYTE	$E9,$EC,$63,$F7
		.BYTE	$ED,$D8,$23,$F4
		.BYTE	$ED,$E8,$23,$FC
		.BYTE	$ED,$F8,$23,$04
		.BYTE	$FD,$DA,$23,$F4
		.BYTE	$FD,$EA,$23,$FC
		.BYTE	$FD,$FA,$23,$04
_sprB07_D2_A:
		.BYTE	$09
		.BYTE	$09,$EC,$23,$EF
		.BYTE	$09,$FC,$23,$F7
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$FE,$C8,$23,$F3

		SECTION_END	"PRG0 SPRITES"

		SECTION_START

; =============== S U B R O U T I N E ======n================================
; custom helper for drawing raw strided tilemaps for the title and ending screens
; draw one line per call.
;
; TODO: adding a special commands to regular packer with line stride and position
; options may optimize these tilemaps as well in the common way. also they don't
; need to be drawn line by line then...
;
; NEW: optimize these tilemaps by now using pointer tables to similar lines to
; avoid duplication. more than 600 bytes saved.
;
_nsub_tlm_raw_arg2_idx_line_draw:
		JSR		_scr_getc					; NEW, this is a ofs to a pointer table now
		STA		_ptr08
		JSR		_scr_getc
		STA		_ptr08+1
		LDX		_cur_trd_slot				; fetch counter from sarg2 of script
		LDA		_trds_args2,X
		ASL
		TAY
		LDA		(_ptr08),Y
		STA		_ptr06
		INY
		LDA		(_ptr08),Y
		STA		_ptr06+1
		LDY		#$17						; now form the data packet
loc_62D3F:
		LDA		(_ptr06),Y					; copy data
		STA		_tmp_buf+4,Y
		DEY
		BPL		loc_62D3F
		LDY		_trds_args2,X				; calculate position offset
		INC		_trds_args2,X
		INY									; position X=4, Y=2+N
		INY
		LDX		#$04
		JSR		_ppu_offset_calc
		LDA		#$18						; width of data chunk
		STA		_tmp_buf+2
		LDA		#$01						; height of data chunk
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_no_ofs	; send data buffer
		.WORD	_tmp_buf+2
		RTS

_tlm_title_logo:
		.WORD	_tlm_dummy_FE
		.WORD	_tlm_title_logo01
		.WORD	_tlm_title_logo02
		.WORD	_tlm_title_logo03
		.WORD	_tlm_title_logo04
		.WORD	_tlm_title_logo05
		.WORD	_tlm_title_logo06
		.WORD	_tlm_title_logo07
		.WORD	_tlm_title_logo08
		.WORD	_tlm_title_logo09
		.WORD	_tlm_title_logo0A
		.WORD	_tlm_title_logo0B
		.WORD	_tlm_title_logo0C
		.WORD	_tlm_title_logo0D
		.WORD	_tlm_title_logo0E
		.WORD	_tlm_title_logo0F
		.WORD	_tlm_title_logo10
		.WORD	_tlm_dummy_FE

_tlm_ending_logo:
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FE
		.WORD	_tlm_ending_logo02
		.WORD	_tlm_title_logo04
		.WORD	_tlm_title_logo05
		.WORD	_tlm_title_logo06
		.WORD	_tlm_title_logo07
		.WORD	_tlm_title_logo08
		.WORD	_tlm_title_logo09
		.WORD	_tlm_title_logo0A
		.WORD	_tlm_title_logo0B
		.WORD	_tlm_title_logo0C
		.WORD	_tlm_ending_logo0C
		.WORD	_tlm_ending_logo0D
		.WORD	_tlm_ending_logo0E
		.WORD	_tlm_ending_logo0F
		.WORD	_tlm_dummy_FE
		.WORD	_tlm_dummy_FE

_tlm_title_text:
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_title_text03
		.WORD	_tlm_title_text04
		.WORD	_tlm_title_text05
		.WORD	_tlm_title_text06
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_title_text08
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_title_text0E
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_dummy_FF
		.WORD	_tlm_title_text11

_tlm_title_logo01:
		.BYTE	$FE,$FE,$FE,$FE,$2C,$3C,$20,$30,$40,$50,$60,$70,$80,$90,$A0,$B0,$C0,$D0,$E0,$F0,$F5,$23,$33,$43
_tlm_title_logo02:
		.BYTE	$FE,$FE,$FE,$FE,$2D,$3D,$21,$31,$41,$51,$61,$71,$81,$91,$A1,$B1,$C1,$D1,$E1,$F1,$F6,$24,$34,$44
_tlm_title_logo03:
		.BYTE	$FE,$FE,$FE,$FE,$2E,$3E,$22,$32,$42,$52,$62,$72,$82,$EC,$EB,$88,$98,$72,$E2,$F2,$F7,$25,$35,$45
_tlm_title_logo04:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$83,$93,$A3,$B3,$C3,$D3,$E3,$F3
_tlm_title_logo05:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$74,$84,$94,$A4,$B4,$C4,$D4,$E4	; BUGFIX: $B3,$C4->$B4,$C4, fix fingers
_tlm_title_logo06:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$55,$65,$75,$85,$95,$A5,$B5,$C5,$D5,$E5
_tlm_title_logo07:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$56,$EE,$76,$86,$96,$A6,$B6,$C6,$D6,$E6,$FE
_tlm_title_logo08:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$47,$57,$67,$77,$87,$97,$EE,$B7,$C7,$D7,$E7,$FE	; BUGFIX: $B6->$B7, fix palm
_tlm_title_logo09:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$48,$58,$68,$78,$EE,$97,$EE,$B8,$C8,$D8,$FE,$FE
_tlm_title_logo0A:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$49,$59,$69,$EE,$89,$99,$A9,$B9,$C9,$D9,$FE,$FE
_tlm_title_logo0B:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$4A,$5A,$6A,$89,$8A,$EF,$AA,$BA,$CA,$DA,$FE,$FE
_tlm_title_logo0C:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$4B,$5B,$6B,$7B,$EF,$9B,$EE,$BB,$CB,$DB,$FE,$FE	; BUGFIX: $4C->$BB, fix belly
_tlm_title_logo0D:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$2F,$EF,$46,$26,$36,$53,$63,$EA,$FA,$DC,$FE,$FE
_tlm_title_logo0E:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$3F,$EF,$EF,$27,$FF,$FF,$FF,$FF,$FB,$DD,$FE
_tlm_title_logo0F:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$73,$EF,$28,$38,$FF,$FF,$FF,$FC,$FE,$FE
_tlm_title_logo10:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$66,$29,$39,$54,$64,$ED,$FD
_tlm_ending_logo02:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$5D,$79,$FE,$FE,$FE
_tlm_ending_logo0C:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$2F,$EF,$46,$EF,$9B,$EE,$EE,$4C,$5C,$DC,$FE,$FE
_tlm_ending_logo0D:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$3F,$EF,$EF,$37,$A8,$AB,$EE,$4D,$EF,$DD,$FE
_tlm_ending_logo0E:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$73,$EF,$9A,$E8,$F8,$DE,$4E,$5E,$FE
_tlm_ending_logo0F:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$66,$8B,$E9,$F9,$DF,$4F
_tlm_dummy_FE:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
_tlm_dummy_FF:
		.BYTE	$FF,$FF,$FF
_tlm_title_text03:
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$54,$4D
_tlm_title_text04:
		.BYTE	$FF,$FF,$60,$70,$80,$90,$A0,$B0,$C0,$D0,$E0,$F0,$63,$73,$83,$93,$A3,$B3,$C3,$D3,$E3,$F3
_tlm_title_text05:
		.BYTE	$FF,$FF,$61,$71,$81,$91,$A1,$B1,$C1,$D1,$E1,$F1,$64,$74,$84,$94,$A4,$B4,$C4,$D4,$E4,$F4
_tlm_title_text06:
		.BYTE	$FF,$FF,$62,$72,$82,$92,$A2,$B2,$C2,$D2,$E2,$F2,$65,$75,$85,$95,$A5,$B5,$C5,$D5,$E5,$F5
_tlm_title_text08:
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,"T","O","P",$FF,$FF,$FF,$FF,$FF,$FF,"0","0",$FF,$FF
_tlm_title_text0E:
		.BYTE	$FF,$FF,$FF,$FF,"P","U","S","H",$FF,"S","T","A","R","T",$FF,"B","U","T","T","O","N"
_tlm_title_text11:
; REGION, "HAL lab." changed in the US proto version, also in EU and JP versions spaces are $20 instead $FF
;		.BYTE	$FF,$FF,$FF,"B","Y",$FF,"H","A","L",$FF,"A","M","E","R","I","C","A",",","I","N","C",".",$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,"B","Y",$FF,"H","A","L",$FF,"L","A","B","O","R","A","T","O","R","Y",$FF,$FF,$FF	; NEW, spaces fixed to optimize
; -

; =============== S U B R O U T I N E ======n================================
_tlm_lib_unpack:
		PHA
		JSR		_ppu_vblank_off
		JSR		_ppu_nmi_off
		LDA		#$0F
		STA		_APU_STATUS
		PLA
		ASL
		ASL
		TAX
		LDA		_tlm_pak_lib,X
		STA		_ptr06
		LDA		_tlm_pak_lib+1,X
		STA		_ptr06+1
		LDA		_tlm_pak_lib+2,X
		STA		_ptr0A
		LDA		_tlm_pak_lib+3,X
		STA		_ptr0A+1
		JSR		_tlm_unpack
		JSR		_ppu_nmi_on
		JMP		_ppu_vblank_on

; TODO: all tilemaps are starting from the same position... may be optimized here
; and redundant bytes removed.
;
_tlm_pak_lib:
		TLM_PAK	_tlm0_title_screen,$2000
		TLM_PAK	_tlm1_score,$2000
		TLM_PAK	_tlm2_busterselect,$2000
		TLM_PAK	_tlm3_game_over,$2000
;		TLM_PAK	_tlm4_score_unused,$2000
;		TLM_PAK	_tlm5_kanji_unused,$2000
		TLM_PAK	_tlm6_copyrights,$2000
		TLM_PAK	_tlm7_staff,$2000
		TLM_PAK	_tlm8_HAL,$2000
		TLM_PAK	_tlm9_secret_menu,$2000

; =============== S U B R O U T I N E ======n================================
; since this is a HAL game, they used similar packer routine
; as in Kirby later on... the same LZ/RLE mix algo with a lot of
; various options
;
_tlm_unpack:
		LDA		_ptr0A						; store destination offset
		STA		_var2						; temp vars
		LDA		_ptr0A+1
		STA		_var3
.unpack_loop:
		LDY		#$00						; fetch cmd here
		LDA		(_ptr06),Y					; stop byte is $FF
		CMP		#$FF
		BNE		.cmd_parse					; exit or go to command parse
		RTS
.cmd_parse:
		AND		#$E0						; code format: xxxccccc, where
		CMP		#$E0						; x - cmd index
		BNE		.short_cmd					; c - counter
		LDA		(_ptr06),Y					; x = 111 (E0) - special case
		ASL									; format changes: 111xxxcc cccccccc
		ASL									; coounter always less than value by 1
		ASL
		AND		#$E0
		PHA
		LDA		(_ptr06),Y
		INY
		AND		#$03
		STA		_ptr08+1
		LDA		(_ptr06),Y
		INY
		STA		_ptr08
		INC		_ptr08
		BNE		loc_AE2B
		INC		_ptr08+1
loc_AE2B:
		BNE		.cmd_continue
.short_cmd:
		PHA
		LDA		(_ptr06),Y
		INY
		AND		#$1F
		CLC
		ADC		#$01
		STA		_ptr08
		LDA		#$00
		STA		_ptr08+1
.cmd_continue:
		PLA
		BPL		.cmds_00_20_40_60			; here entry for commands 0xx
		JMP		.cmds_80_A0_C0				; here entry for commands 1xx
.cmds_00_20_40_60:
		LDX		_ptr0A+1					; for all commands, set cur ppu addr
		STX		_PPU_ADDR
		LDX		_ptr0A
		STX		_PPU_ADDR
		LDX		_ptr08+1					; for optimization, low nibble of 16bit
		STX		_var4						; counter loaded in X register, high
		LDX		_ptr08						; nibble in _var4, if X=0 at the beginning
		BNE		loc_AE56					; decrement high nibble because X-1 in loop
		DEC		_var4						; will cause one more 256 cycles loop below
loc_AE56:
		CMP		#$20
		BEQ		.cmd20
		CMP		#$40
		BEQ		.cmd40
		CMP		#$60
		BEQ		.cmd60
loc_AE62:
		LDA		(_ptr06),Y					; cmd00, copy a number of
		INY									; following bytes
		BNE		loc_AE69					; adjust _ptr06 when switching to another page
		INC		_ptr06+1
loc_AE69:
		STA		_PPU_DATA					; first use X as fast counter
		DEX									; then decrement high nibble and
		BNE		loc_AE62					; repeat until high nibble is zero
		DEC		_var4
		BPL		loc_AE62
.unpack_adjust_ptrs:
		TYA									; update data pointer by adding last
		CLC									; used Y value
		ADC		_ptr06
		STA		_ptr06
		BCC		loc_AE7D
		INC		_ptr06+1
loc_AE7D:
		LDA		_ptr0A						; also increment ppu offset by number
		CLC									; of bytes read. now we ready to get another
		ADC		_ptr08						; command
		STA		_ptr0A
		LDA		_ptr0A+1
		ADC		_ptr08+1
		STA		_ptr0A+1
		JMP		.unpack_loop
.cmd20:
		LDA		(_ptr06),Y					; cmd20, repeat a number of
		INY									; following bytes
loc_AE90:
		STA		_PPU_DATA
		DEX
		BNE		loc_AE90
		DEC		_var4
		BPL		loc_AE90
		JMP		.unpack_adjust_ptrs			; adjust ptrs as for cmd00
.cmd40:
		LDA		(_ptr06),Y					; cmd40, copy a number of
		INY									; following words
		STA		_PPU_DATA
		LDA		(_ptr06),Y
		DEY
		STA		_PPU_DATA
		DEX
		BNE		.cmd40
		DEC		_var4
		BPL		.cmd40
		INY
		INY
		ASL		_ptr08
		ROL		_ptr08+1
		JMP		.unpack_adjust_ptrs
.cmd60:
		LDA		(_ptr06),Y					; cmd60, send the arithm progression
		INY									; starting from next byte value
loc_AEBC:									; up to counter bytes (01 02 03 04... etc)
		STA		_PPU_DATA
		CLC
		ADC		#$01
		DEX
		BNE		loc_AEBC
		DEC		_var4
		BPL		loc_AEBC
		JMP		.unpack_adjust_ptrs
.cmds_80_A0_C0:
		PHA									; for all these cmds there are two
		LDA		(_ptr06),Y					; bytes of relative offset goes first
		INY									; adding to starting position of ppu ofs
		STA		_var1
		LDA		(_ptr06),Y
		INY
		CLC
		ADC		_var2
		STA		_var0
		LDA		_var3
		ADC		_var1
		STA		_var1
		TYA
		CLC
		ADC		_ptr06
		STA		_ptr06
		BCC		loc_AEEA
		INC		_ptr06+1
loc_AEEA:
		LDA		_ptr08
		BNE		loc_AEF0
		DEC		_ptr08+1
loc_AEF0:
		PLA
		CMP		#$80
		BEQ		.cmd80
		CMP		#$A0
		BEQ		.cmdA0
		CMP		#$C0
		BEQ		.cmdC0
.cmd80:
		JSR		_hi_cmd_set_counter			; cmd80, copy given number of bytes from
		JSR		_hi_cmd_ppu_data_read		; ppu ram (offset following) to current
		JSR		_hi_cmd_ppu_data_write		; ppu write offset in reverse order!
		INC		_var1
		DEC		_ptr08+1
		BPL		.cmd80
		JMP		.unpack_loop
.cmdA0:
		JSR		_hi_cmd_set_counter			; cmdA0, read ppu data already written,
		JSR		_hi_cmd_ppu_data_read		; reverse bit order of all bytes read
		JSR		_hi_cmd_data_rotate			; then write it back in reverse order
		JSR		_hi_cmd_ppu_data_write
		INC		_var1
		DEC		_ptr08+1
		BPL		.cmdA0
		JMP		.unpack_loop
.cmdC0:
		JSR		_hi_cmd_set_counter			; cmdC0, read ppu data already written,
		JSR		_hi_cmd_ppu_data_read_invert; and write back in original order
		JSR		_hi_cmd_ppu_data_write
		DEC		_ptr08+1
		BPL		.cmdC0
		JMP		.unpack_loop

; =============== S U B R O U T I N E ======n================================
_hi_cmd_set_counter:
		LDX		_ptr08
		LDA		_ptr08+1
		BEQ		loc_AF3C
		LDX		#$00
loc_AF3C:
		STX		_tmp1
		RTS

; =============== S U B R O U T I N E ======n================================
_hi_cmd_ppu_data_read:
		LDA		_var1
		STA		_PPU_ADDR
		LDA		_var0
		STA		_PPU_ADDR
		LDA		_PPU_DATA
loc_AF4C:
		LDA		_PPU_DATA
		STA		_ppu_queue_data,X
		DEX
		BNE		loc_AF4C
		RTS

; =============== S U B R O U T I N E ======n================================
_hi_cmd_ppu_data_write:
		LDX		_tmp1
		LDA		_ptr0A+1
		STA		_PPU_ADDR
		LDA		_ptr0A
		STA		_PPU_ADDR
loc_AF62:
		LDA		_ppu_queue_data,X
		STA		_PPU_DATA
		DEX
		BNE		loc_AF62
		DEC		_tmp1
		LDA		_tmp1
		SEC
		ADC		_ptr0A
		STA		_ptr0A
		BCC		locret_AF78
		INC		_ptr0A+1
locret_AF78:
		RTS

; =============== S U B R O U T I N E ======n================================
_hi_cmd_data_rotate:
		LDX		_tmp1
loc_AF7B:
		LDA		_ppu_queue_data,X
		STA		_var4
		LDY		#$08
loc_AF82:
		ASL		_var4
		ROR
		DEY
		BNE		loc_AF82
		STA		_ppu_queue_data,X
		DEX
		BNE		loc_AF7B
		RTS

; =============== S U B R O U T I N E ======n================================
_hi_cmd_ppu_data_read_invert:
		STX		_var4
		DEC		_var4
		LDA		_var0
		CLC
		SBC		_var4
		STA		_var0
		TAY
		LDA		_var1
		SBC		#$00
		STA		_var1
		STA		_PPU_ADDR
		STY		_PPU_ADDR
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		LDX		#$00
loc_AFAF:
		INX
		LDA		_PPU_DATA
		STA		_ppu_queue_data,X
		CPX		_tmp1
		BNE		loc_AFAF
		RTS

_tlm0_title_screen:
		INCBIN	"..\tlm\tlm0.pak"
_tlm1_score:
		INCBIN	"..\tlm\tlm1.pak"
_tlm2_busterselect:
		INCBIN	"..\tlm\tlm2.pak"
_tlm3_game_over:
		INCBIN	"..\tlm\tlm3.pak"
;_tlm4_score_unused:
;		INCBIN	"..\tlm\tlm4.pak"
;_tlm5_kanji_unused:
;		INCBIN	"..\tlm\tlm5.pak"
_tlm6_copyrights:
; REGION, first typo fixed in the EU version, however, not the second one lol
;		INCBIN	"..\tlm\tlm6_eu.pak"
; REGION, same typos as in the JP version, HAL lab changed to HAL america
;		INCBIN	"..\tlm\tlm6_us.pak"
; REGION, JP
;		INCBIN	"..\tlm\tlm6_jp.pak"
; NEW, fixed "ghostbust" type, added cah4e3 bfs gmbh
		INCBIN	"..\tlm\tlm6_bfs.pak"
; -
_tlm7_staff:
		INCBIN	"..\tlm\tlm7.pak"
_tlm8_HAL:
; REGION, different type of HAL logo for US region
;		INCBIN	"..\tlm\tlm8_hal_us.pak"
		INCBIN	"..\tlm\tlm8_hal_jp_eu.pak"
; -
_tlm9_secret_menu:
;		INCBIN	"..\tlm\tlm9.pak"
; NEW, changed the layout of secret menu
		INCBIN	"..\tlm\tlm9_bfs.pak"

		SECTION_END	"TLM UNPACKER AND DATA"

		BANK_END 0,$C000
