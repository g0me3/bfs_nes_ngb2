
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

		BANK_START $00

		INCBIN "../copyrights.txt"

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
		SJMP_SW			$0D
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
		SCASE			_ssub_select_2p					; 0D, NEW

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_mcmp						; default case for script startup
			NARGW		_license_screen_display_flag	; check for special flag, set at reset
			NARGB		$01								; preventing from show license screens
		SBCCS			_sloc_title_start				; after game over, if clear, jump to title
		STORE8			_license_screen_display_flag,$00; if set, clear it, then load first
		NJSR			_nsub_full_pal_fade_set			; do full palette fade
			NARGB		$FC								; $FC = fade out at max peed (sub 40)
		NJSR			_nsub_scroll_page_set			; set nt page
			NARGB		$00
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack HAL logo tilemap
			NARGB		_tlm8_HAL_idx
		STORE8			_chr_bank1,$1B					; set corresponding CHR bank
		NJSR			_nsub_bg_pal_load				; load actual palette into pal buf
			NARGW		_pal0
		SJSR			_ssub_pal_fade_in				; show the picture, wait for 90 frames (1.5 sec)
		SJSR			_ssub_skip_wait					; NEW, skip intro
		SJSR			_ssub_pal_fade_out				; shut down the picture
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; load new packed tilemap with license info
			NARGB		_tlm6_copyrights_idx
		STORE8			_chr_bank1,$09					; CHR bank
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
; NEW: for some reason they used a native routine to store CHR bank
; index into corresponding variable, nistead of using simple STORE8
; opcode same size. optimized store opcodes to be one byte shorter
; if variable offset is in zero RAM, so may now replace all natives
; to opcodes with convinience.
		STORE8			_chr_bank0,$01					; set CHR for bg and sprites
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack title screen frame window
			NARGB		_tlm0_title_screen_idx
		SJSRS			_ssub_title_logo_init			; NEW, merged to common code routine
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
			NARGW		_pal3							; and change the CHR page, pages 00 and 09 shares
		STORE8			_chr_bank1,$09					; title curtain graphics, so nothing is changes there
		NJSR			_nsub_new_thread_start			; start new thread to display an additional
			NARGB		_scr00_intro_title_select_idx	; animated sprite object - small ghost in "stop" sign
			NARGB		$00,$00							; this object has limited lifetime and stopped
			NARGB		_intro_sub0B_title_ghost_idx+1	; automatically after about 10 seconds
			NARGB		$00
		SJSRS			_ssub_title_maskDB_fade_in		; fade in palette for the center of the screen
		SSCRIPT1_SET	_scr_title_push_start_anim		; run secondary script to animate palette for "push start button"
		SDELAY			$F0								; just wait about 9 seconds
		SDELAY			$F0
		SDELAY			$67
		SSCRIPT1_OFF									; then kill the "push start button" animation
		NJSR			_nsub_full_pal_fade_set			; restore full palette
			NARGB		$00
		SJSRS			_ssub_title_maskDB_fade_out		; and then fade it out
		SJSRS			_ssub_title_logo_init			; NEW, merged to common code routine
		SPR_IDX_SET		1,$00							; restore "new" sprite
		SJSRS			_ssub_title_maskDB_fade_in		; fade in and do loop
		SJMPS			_sloc_title_loop

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_title_logo_init:
		STORE8			_chr_bank1,$00
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
		SJMPS			_scr_title_push_start_anim

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

; NOTE: us proto uses two different palettes for logo and copyrights screens
; in the rest releases they are the same, now removed. if you need another
; palette, add it
_pal0:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00
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
		LDA		_pads_press+2
		AND		#PAD_START|PAD_A
		BEQ		locret_853A
		SEC
		RTS
locret_853A:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nbgsub_title_input:
		LDA		_pads_press+2				; this is native background routine for
		AND		#PAD_START					; NEW, now both buttons are available
		BEQ		locret_8539					; additionally for A+B held
		LDA		_pads_held+2
		AND		#PAD_A|PAD_B
		CMP		#PAD_A|PAD_B
		BNE		loc_8534					; if true, restart current thread with
		JSR		_cur_thread_reload_param	; secret options menu script
		.WORD	_scr_secret_menu
		RTS
loc_8534:
		LDA		_pads_held+2
		AND		#PAD_B|PAD_SEL
		CMP		#PAD_B|PAD_SEL
		BNE		loc_8535					; if true, restart current thread with
		JSR		_cur_thread_reload_param	; secret sprite debug menu
		.WORD	_scr_sprite_debug
		RTS
loc_8535:
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
		SJMPS			_scr_intro_slime_anim			; stops, this will disable as well

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
		SJMPS			_sloc_intro_busters_delay

; =============== S C R I P T ==========================s====================
_sub04_intro_busterC:
		SPR_IDX_SET		0,$1C
		POS_X_DELTA_SET 0,$C0,$00
		SJMPS			_sloc_intro_busters_delay

; =============== S C R I P T ==========================s====================
_sub05_intro_busterD:
		SPR_IDX_SET		0,$28
		POS_Y_DELTA_SET 0,$00,$02
		SDELAY			$0A
		SJMPS			_sloc_intro_busters_no_delay

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
;			NARGW		_pal_new_blink					; REDUNDANT, with index SARG0, put it on
;			NARGB		$16,SARG0						; selected position of palette buffer (16),
		SARG_ALU		SARG0,_ADC,$01					; then blit it and increment idx
		SDELAY			$01								; sync to fluch buffers, loop 6 times
		SLOOP_END
		SJMPS			_sloc_8A65						; repeat infinitely

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
;		SJMPS			_intro_sub0C_title_new_unref
;
;_pal_new_blink_unused:
;		.BYTE	$0F,$10,$20,$30,$20,$10,$01

; =============== S U B R O U T I N E ======n================================
; this is custom palette blink routine used only for this place...
; in other cases they used common pal fade _nsub routine with mask arguments...
; NOTE: if you need another blinker to be restored, make another custom
; blinker..
;
_nsub_patch_pal_blink:
;		JSR		_scr_getc					; REDUNDANT now
;		STA		_ptr06
;		JSR		_scr_getc
;		STA		_ptr06+1
;		JSR		_scr_getc
;		TAX
;		JSR		_scr_getc
;		TAY
;		LDA		_trds_args_ptrs_lo,Y
;		STA		_ptr08
;		LDA		_trds_args_ptrs_hi,Y
;		STA		_ptr08+1
;		LDY		_cur_trd_slot
;		LDA		(_ptr08),Y
;		TAY
;		LDA		(_ptr06),Y
;		STA		_pal_buf,X
		LDY		_cur_trd_slot				; NEW, hardcoded values are better lol
		LDA		_trds_args0,Y
		TAY
		LDA		_pal_new_blink,Y
		STA		_pal_buf+$16
		JMP		_full_pal_fade

_pal_new_blink:
		.BYTE	$35,$25,$15,$05,$15,$25

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
		STORE8			_chr_bank1,$06
		STORE8			_beamer_spr_base_tmp,$FF		; no players selected yet, reset
		STORE8			_catcher_spr_base_tmp,$FF
		STORE8			_two_player_selections,$FF		; NEW, reset player's selections
		STORE8			_two_player_selections+1,$FF
		STORE8			_buster_select_anim_busyA,$00	; these vars used here as a temp veriables
		STORE8			_buster_select_anim_busyB,$00	; not by its ingame meanings
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
		NJSR			_nsub_mcmp						; NEW, test for players number flag
			NARGW		_two_player_mode_flag			; if clear, then jump to regular buster select
			NARGB		$01								; script
		SBCCS			_ssub_select_1p
		NJSR			_nsub_2p_thread_load			; start 2p input thread here

; !FALLTHROUG!

; =============== S C R I P T ==========================s====================
_ssub_select_2p:
		SARG_SET		SARG0,$00						; init tmp index
		SARG_SET		SARG2,_sprA00_401_idx			; NEW, base sprite idx for 2p mode player 1
		SJMPS			_ssub_select_common				; just one loop here for 2p

; =============== S C R I P T ==========================s====================
_ssub_select_1p:
		SARG_SET		SARG0,$00						; init tmp index
		SARG_SET		SARG2,_sprA00_40_idx			; NEW, default name sprite idx for 1p mode
		SJSRS			_ssub_input_wait_loop			; animated objects are working now

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_ssub_select_common:
		SJSRS			_ssub_input_wait_loop			; now the same for second player

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_finish_selection:
		NJSR			_nsub_is_catcher_selected		; test if we get here after last selection
		SBCCS			_just_stop						; otherwize just stop
		SDELAY			$01								; wait when both players finishes its
		NJSR			_nsub_mtest_bit0				; selection and the final animation is
			NARGW		_buster_select_anim_busyB		; ready (_buster_select_anim_busyB = 1)
		SBCCS			_scr_finish_selection			;
		SDELAY			$5A								; when animation started, setup delay
		SLOOP_BEGIN		$04								; then fade palette out and close the scripts
		NJSR			_nsub_pal_fade_req_dec_by_mask	;
			NARGB		$FF
		SDELAY			$08
		SLOOP_END
		NJSR			_nsub_players_idx_init			; final initializations of game vars
_just_stop:
		SSTOP

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_input_wait_loop:
		SDELAY			$01
		NJSR			_nsub_mtest_bit0
			NARGW		_buster_select_anim_busyA		; wait for anim is over and flag raized
		SBCCS			_ssub_input_wait_loop			; if set, we'll start input handling
		NJSR			_nsub_select_buster_input		; loop until selection is complete
		SBCCS			_ssub_input_wait_loop
		SRET

_select_buster_chain_scripts:
		.BYTE	_sub06_select_peter_idx+1,	$00,$F8,$00
		.BYTE	_sub07_select_ray_idx+1,	$18,$F8,$00
		.BYTE	_sub08_select_egon_idx+1,	$30,$F8,$00
		.BYTE	_sub09_select_winston_idx+1,$48,$F8,$00
		.BYTE	_sub0A_select_louis_idx+1,	$E0,$40,$00
_pal_select_busters:
		.BYTE	$0F,$00,$16,$07,$0F,$10,$00,$07,$0F,$27,$17,$07,$0F,$30,$0F,$0F
		.BYTE	$0F,$36,$1C,$0F,$0F,$0F,$0F,$0F,$0F,$30,$0F,$0F,$0F,$0F,$0F,$0F

_nsub_test

; =============== S U B R O U T I N E ======n================================
_nsub_2p_thread_load:
		LDA		#_ssub_select_2p_idx+1		; load additional script case
		STA		_var0
		LDA		#$01						; load into slot 01
		STA		_var4
		LDA		#$02
		STA		_var5
		LDA		#_scr00_intro_title_select_idx	; base object is the main object here also
		JMP		_thread_lib_load

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
		LDA		_pads_press,X				; test for L/R buttons press
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
		LDA		_pads_press,X
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
		LDA		_pads_press,X				; select with A
		AND		#PAD_START|PAD_A			; NEW, also here
		BEQ		loc_8C36
		LDA		#_snd0C_idx
		JSR		_far_prg6_apu_snd_load		; init one of two players indexes
		LDA		_trds_args0,X
		LDY		_beamer_spr_base_tmp
		BPL		loc_8C17
		STA		_beamer_spr_base_tmp
		LDA		#$00						; now init which pad will control
		BEQ		loc_8C1A					; which player
loc_8C17:
		STA		_catcher_spr_base_tmp		; if 00, then player controls beamer
		LDA		#$01
loc_8C1A:
		STA		_two_player_selections,X	; if 01, then player controls catcher
		LDA		#$FF
		STA		_obj_spr_idx				; disable obj name sprites
		STA		_obj_spr_idx+1				;
		LDA		#$00						; disable selection input for now
		STA		_buster_select_anim_busyA
		SEC									; when selection is done, set carry to
		RTS									; signal the main code to do next part
loc_8C36:
		LDA		_trds_args0,X				; check for already selected items first
		CMP		_beamer_spr_base_tmp
		BEQ		loc_8C2F
		CMP		_catcher_spr_base_tmp		; also check for 2p mode
		BNE		loc_8C30
loc_8C2F:
		INC		_trds_args0,X				; skip already selected
		LDA		_trds_args0,X
		CMP		#$05
		BCC		loc_8C36
		LDA		#$00
		STA		_trds_args0,X
		BEQ		loc_8C36
loc_8C30:
		TAY									; display the name sprite for currently
		LDA		byte_8C51,Y					; highlighted player
		STA		_obj_x_pos_lo,X
		TYA									; adjust the 2p position if needed
		CLC
		ADC		byte_8C57,X
		TAY
		LDA		byte_8C56,Y
		STA		_obj_y_pos_lo,X
		LDA		#$00
		STA		_obj_x_pos_hi,X
		STA		_obj_y_pos_hi,X
		TYA
		CLC
		ADC		_trds_args2,X				; WARNING, Y here is already +5 for 2p!
		STA		_obj_spr_idx,X				; no need to init sprite base for it separately!
		RTS

byte_8C51:
		.BYTE	$68,$80,$98,$B0,$E0
byte_8C56:
		.BYTE	$70,$70,$70,$70,$B0
		.BYTE	$60,$60,$60,$60,$A0
byte_8C57:
		.BYTE	$00,$05

; =============== S C R I P T ==========================s====================
; PETER
_sub06_select_peter:
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$08						; set default left-oriented sprite for this object
		SPR_IDX_SET		0,$09							; set current anim walk start sprite
		SJSRS			_ssub_select_busters
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
		STORE8			_buster_select_anim_busyA,$01	; now enable selection input
_sloc_8D0C:
		SDELAY			$01								; common portion for any object
		NJSR			_nsub_is_beamer_selected
		SBCCS			_sloc_8D0C						; wait if select is done
		NJSR			_nsub_is_cur_buster_select_for_beam_player
		SBCSS			_sloc_beamer_selected			; then test if this object selected
_sloc_8D1A:
		SDELAY			$01								; for both players one by one
		NJSR			_nsub_is_catcher_selected
		SBCCS			_sloc_8D1A
		NJSR			_nsub_is_cur_buster_select_for_catch_player
		SBCSS			_sloc_catcher_selected
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
		SBCCS			_sloc_8D35
		SSCRIPT1_OFF									; stop animation
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1							; get sprite index for stand anim loaded
		POS_MOVE_STOP	0								; at the thread start in SARG1
		STORE8			_buster_select_anim_busyA,$01	; raise anim busy flag
_sloc_8D49:
		SDELAY			$01								; first selected player must wait until
		NJSR			_nsub_mtest_bit0				; second player is step aside
			NARGW		_buster_select_anim_busyB		; when this occurs, the flag riased
		SBCCS			_sloc_8D49
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
		SJMPS			_sloc_8D7B

; =============== S C R I P T ==========================s====================
_sloc_catcher_selected:
		SJSRS			_ssub_buster_selected_step_out
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
		SBCCS			_sloc_8D94
_sloc_8DA0:
		STORE8			_buster_select_anim_busyB,$01	; ok, second player is ready, start to slide down
_sloc_8DA4:
		SDELAY			$01
		NJSR			_nsub_cur_pos_x_lo_icmp			; while first player is jumping up, he need
			NARGB		$50								; to reach the same position x=50 first
		SBCCS			_sloc_8DA4
		SSCRIPT1_OFF									; now walk is over, start to jump up
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		POS_MOVE_STOP	0
		SDELAY			$02								; set the same move direction, animate
		POS_X_DELTA_SET 0,$00,$FE
		POS_Y_DELTA_SET 0,$00,$FE
		SDELAY			$0C
		POS_MOVE_STOP	0								; stop on the pole, then jump on common code
		SJMPS			_nsub_buster_slide_down

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
		SJMPS			_scr_buster_walk_left_anim

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
		SBCCS			_sloc_8E32						; then there are two options
		NJSR			_nsub_is_cur_buster_select_for_beam_player
		SBCSS			_sloc_8E4F
_sloc_8E40:
		SDELAY			$01								; here goes if buster not selected as beam player
		NJSR			_nsub_is_catcher_selected
		SBCCS			_sloc_8E40						; then we just wait for chatch player selection
		NJSR			_nsub_is_cur_buster_select_for_catch_player
		SBCSS			_sloc_8E55						; again two options
		SUSPEND											; suspend, if buster not selected for anything
_sloc_8E4F:												; here goes if buster were selected for beam player
		SJSRS			_ssub_louis_selected_base_anim
		SJMP			_scr_beamer_walk_common
_sloc_8E55:												; here goest if buster were selected for catch player
		SJSRS			_ssub_louis_selected_base_anim
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
_scr_sprite_debug:
		SJSR			_ssub_pal_fade_out
		NJSR			_nsub_all_threads_off_except_cur
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		NJSR			_nsub_far_prg0_tlm_lib_unpack
			NARGB		_tlmA_blank_idx
		NJSR			_nsub_debug_menu_init
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_spr_sprite_debug_patch
		NJSR			_nsub_bg_pal_load				; also palette
			NARGW		_pal_bg_sprite_debug
		SJSR			_ssub_pal_fade_in				; show screen
		NBG_HNDL_SET	_nbgsub_sprite_debug_exit_wait	; load native bg input
_sloc_8F5C:
		SDELAY			$01								; go main menu loop
		NJSR			_nsub_debug_input
		SJMPS			_sloc_8F5C

_pal_bg_sprite_debug:
		.BYTE	$10,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
_pal_spr_sprite_debug_patch:
		.BYTE	$0F,$36,$17,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_sprite_debug_exit_wait:
		LDA		#$80
		STA		_tmp1
		STA		_tmp2
		JSR		_spr_y_pos_adjust
		JSR		_debug_spr_insert
		LDA		_pads_press+2				; background native sub to wait
		AND		#PAD_START					; if START is pressed
		BEQ		locret_8FAB
		JSR		_cur_thread_reload_param	; load intro script again starting
		.WORD	_scr_title_restart			; directly from title screen
locret_8FAB:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_debug_menu_init:
		LDA		#DEBUG_CHR0
		STA		_debug_chr0
		STA		_chr_bank0
		LDA		#DEBUG_LIBA
		STA		_debug_lib_idx
		LDA		#DEBUG_LIBB
		STA		_debug_lib_type
		LDA		#DEBUG_IDX
		STA		_debug_spr
		LDA		#$04
		STA		_debug_pos_idx
		LDA		#$05
		STA		_debug_chr1
		STA		_chr_bank1
		JSR		_debug_draw
		JMP		_debug_cursor_draw

; =============== S U B R O U T I N E ======n================================
_nsub_debug_input:
		LDA		_pads_press+2
		AND		#PAD_L
		BEQ		.1
		LDA		_debug_pos_idx
		BEQ		.1
		DEC		_debug_pos_idx
		JSR		_debug_cursor_draw
.1:
		LDA		_pads_press+2
		AND		#PAD_R
		BEQ		.2
		LDA		_debug_pos_idx
		CMP		#$04
		BEQ		.2
		INC		_debug_pos_idx
		JSR		_debug_cursor_draw
.2:
		LDY		_debug_pos_idx
		LDA		_pads_press+2
		AND		#PAD_U
		BEQ		.3
		LDA		_debug_vars_list,Y
		CLC
		ADC		#$01
		CMP		_debug_mode_limits,Y
		BEQ		.skip
		STA		_debug_vars_list,Y
		JMP		.update
.3:
		LDA		_pads_press+2
		AND		#PAD_D
		BEQ		.skip
		LDA		_debug_vars_list,Y
		SEC
		SBC		#$01
		CMP		#$FF
		BEQ		.skip
		STA		_debug_vars_list,Y
.update:
		LDA		_debug_chr0
		STA		_chr_bank0
		LDA		_debug_chr1
		STA		_chr_bank1
		CPY		#$02
		BNE		.4
		LDA		#$00
		STA		_debug_lib_type
		STA		_debug_spr
		BEQ		_debug_draw
.4:
		LDX		_debug_lib_idx
		CPY		#$03
		BNE		.5
		LDA		_debug_typeB_limits,X
		BNE		.55
		STA		_debug_lib_type
		BEQ		_debug_draw
.55:
		LDA		#$00
		STA		_debug_spr
		BEQ		_debug_draw
.5:
		CPY		#$04
		BNE		_debug_draw
		LDA		_debug_lib_type
		BNE		.6
		LDA		_debug_typeA_limits,X
		BNE		.7
.6:
		LDA		_debug_typeB_limits,X
.7:
		CMP		_debug_spr
		BNE		_debug_draw
		DEC		_debug_spr

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_debug_draw:
		LDY		#$00
		STY		_var0
.8:
		LDY		_var0
		CPY		#$05
		BEQ		.skip
		LDA		_debug_vars_list,Y
		LDX		_hex_pos,Y
		LDY		#OUTPUT_POS_Y
		JSR		_print_hex
		INC		_var0
		BNE		.8
.skip:
		RTS

OUTPUT_POS_X	EQU	$03
OUTPUT_POS_Y	EQU $02

_debug_mode_limits:
		.BYTE	$20,$20,$09,$02,$00
_debug_typeA_limits:
		.BYTE	$4D,$1F,$BD,$B0,$30,$98,$6E,$8E,$95
_debug_typeB_limits:
		.BYTE	$00,$00,$13,$00,$00,$00,$2C,$0B,$08
_hex_pos:
		.BYTE	OUTPUT_POS_X
		.BYTE	OUTPUT_POS_X+3
		.BYTE	OUTPUT_POS_X+6
		.BYTE	OUTPUT_POS_X+9
		.BYTE	OUTPUT_POS_X+12

; =============== S U B R O U T I N E ======n================================
_debug_cursor_draw:
		LDY		_debug_pos_idx
		LDX		_hex_pos,Y
		DEX
		DEX
		LDY		#[OUTPUT_POS_Y+1]
		JSR		_ppu_offset_calc
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tlm_cur
		LDX		#OUTPUT_POS_X
		LDY		#[OUTPUT_POS_Y-1]
		JSR		_ppu_offset_calc
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tlm_legend
		RTS
_tlm_cur:
		.BYTE	$07,$01,$FF,$FF,$FF,$90,$FF,$FF,$FF
_tlm_legend:
		.BYTE	$0E,$01,"C0",$FF,"C1",$FF," A",$FF," B",$FF,"ID"

; =============== S U B R O U T I N E ======n================================
; input: X/Y printf position
;        A   number to printf
_print_hex:
		PHA
		JSR		_ppu_offset_calc
		PLA
		PHA
		LSR
		LSR
		LSR
		LSR
		TAX
		LDA		_hex_chars,X
		STA		_tmp_buf+4
		PLA
		AND		#$0F
		TAX
		LDA		_hex_chars,X
		STA		_tmp_buf+5
		LDA		#$02
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		RTS
_hex_chars:
		.BYTE	$30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$41,$42,$43,$44,$45,$46,

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
		STORE8			_chr_bank1,$05					; CHR setup
		NJSR			_nsub_bg_pal_load				; also palette
			NARGW		_pal_bg_secret_menuB
		SJSR			_ssub_pal_fade_in				; show screen
		NBG_HNDL_SET	_nbgsub_secret_menu_exit_waitB	; load native bg input
_sloc_8F5D:
		SDELAY			$01								; go main menu loop
		NJSR			_nsub_secret_menu_UD_input		; input separated in three subs
		NJSR			_nsub_secret_menu_LR_input		; for hor/vert/AB buttons
		NJSR			_nsub_secret_menu_AB_input
		SJMPS			_sloc_8F5D

_pal_bg_secret_menuB:
		.BYTE	$0F,$11,$11,$11,$0F,$30,$30,$30,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_secret_menu_exit_waitB:
		LDA		_pads_press+2				; background native sub to wait
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
		LDA		_pads_press+2
		AND		#PAD_U
		BEQ		loc_8FD4
		LDA		_cur_room_doors_cnt
		SEC
		SBC		#$01
		BPL		loc_8FE6
		LDA		#$03
		BNE		loc_8FE6
loc_8FD4:
		LDA		_pads_press+2
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
		LDA		_pads_press+2
		AND		#PAD_L
		BEQ		loc_903B
		LDA		_menu_controls_idx,X
		SEC
		SBC		#$01
		BPL		loc_9050
		LDA		_menu_controls_max_val_list,X
		BNE		loc_9050
loc_903B:
		LDA		_pads_press+2
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
		LDA		_pads_press+2				; buttons used if sound test options
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
		LDA		_pads_press+2				; B stops them
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
		STORE8			_chr_bank1,$09					; setup CHR for BG
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
		SJMPS			_sloc_92E5

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
		SBCCS			_sloc_931B
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
		STORE8			_chr_bank1,$1C
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
		LDA		_pads_press+2				; wait if START is pressed
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
		LDA		#$64						; add 10000 scores for every life
		JSR		_scores_add
		DEC		_players_lives
		BNE		loc_942C
loc_9436:
		LDA		_two_player_mode_flag
		BEQ		loc_9437
		LDA		_players_lives+1
		BEQ		loc_9437
loc_942D:
		LDA		#$64
		JSR		_scores_add
		DEC		_players_lives+1
		BNE		loc_942D
loc_9437:
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
		STORE8			_chr_bank0,$19
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
		STORE8			_chr_bank0,$04
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
		SJSRS			_ssub_9B0B
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
		SJSRS			_ssub_9B0B
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
		STORE8			_chr_bank0,$0F
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
		SJSRS			_ssub_9C15
		SLOOP_END
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$05
		SJSRS			_ssub_9C15
		SLOOP_END
		POS_X_DELTA_SET 0,$C0,$00
		SLOOP_BEGIN		$05
		SJSRS			_ssub_9C15
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
		STORE8			_chr_bank0,$14
		STORE8			_chr_bank1,$00
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
		SJMPS			_sloc_A784

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

; =============== S C R I P T ==========================s====================
		FAR_OFS	_scr13_slow_moving_slime
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
		FAR_OFS	_scr14_fast_moving_slime
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
		FAR_OFS	_scr15_trolley_kick_slime
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
		FAR_OFS	_scr16_still_throw_forward_slime
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
		FAR_OFS	_scr1B_court_chair
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
		FAR_OFS	_scr1D_air_hammer_miner
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
		FAR_OFS _scr1E_pick_axe_miner
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
		FAR_OFS _scr1F_hammer_miner
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
		FAR_OFS	_scr0E_empty_mine_trolley
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
		FAR_OFS	_scr20_trolley_miner
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
		FAR_OFS	_scr21_train_ghost
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
		FAR_OFS	_scr2B_still_throw_ballistic_slime
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
		FAR_OFS	_scr2C_fast_throw_forward_slime
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
		FAR_OFS _scr23_halloween
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
		FAR_OFS _scr24_flying_elephant
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
		FAR_OFS _scr25_stinging_elephant
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
		FAR_OFS _scr26_sword_ninja
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
		FAR_OFS _scr27_shuriken_ninja
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
		FAR_OFS	_scr28_pink_goo
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
		FAR_OFS _scr29_sewer_worm
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
		FAR_OFS _scr2D_rotator
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
		FAR_OFS _scr0F_candle
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
		FAR_OFS	_scr10_train_semaphores
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
		FAR_OFS	_scr17_runner
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
		FAR_OFS	_scr18_chain_saw
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
		FAR_OFS	_scr19_toilet_snake
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
		FAR_OFS	_scr2A_morning_star_troll
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
		FAR_OFS	_scr1C_girl_and_floaters
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
		NJSR			_nsub_apu_snd_load				; NEW, let's make some fun with unused sounds
			NARGB		_snd10_idx
		SPR_IDX_SET		0,$70
		POS_Y_DELTA_SET 4,$00,$FA
		POS_Y_DELTA_SET 4,$00,$02
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_R:
		NJSR			_nsub_apu_snd_load				; NEW, let's make some fun with unused sounds
			NARGB		_snd10_idx
		SPR_IDX_SET		0,$71
		POS_X_DELTA_SET 0,$00,$02
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$02
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_D:
		NJSR			_nsub_apu_snd_load				; NEW, let's make some fun with unused sounds
			NARGB		_snd10_idx
		SPR_IDX_SET		0,$72
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$06
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_floaters_move_L:
		NJSR			_nsub_apu_snd_load				; NEW, let's make some fun with unused sounds
			NARGB		_snd10_idx
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
		FAR_OFS	_scr11_lvl2_ghost_nanny
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

; =============== S U B R O U T I N E ======n================================
; custom helper for drawing raw strided tilemaps for the title and ending screens
; draw one line per call.
;
; NEW: optimized these tilemaps by now using pointer tables to similar lines to
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
		FAR_OFS	_tlm_lib_unpack
		TAX
		JSR		_ppu_vblank_off
		JSR		_ppu_nmi_off
		LDA		#$0F
		STA		_APU_STATUS
		LDA		_tlm_pak_lib,X
		STA		_ptr06
		LDA		_tlm_pak_lib+1,X
		STA		_ptr06+1
		LDA		#$00						; NEW, always fixed 2000 ppu offset
		STA		_ptr0A
		LDA		#$20
		STA		_ptr0A+1
		JSR		_tlm_unpack
		JSR		_ppu_nmi_on
		JMP		_ppu_vblank_on

_tlm_pak_lib:
		TLM_PAK	_tlm0_title_screen
		TLM_PAK	_tlm1_1p_score
		TLM_PAK	_tlm1_2p_score
		TLM_PAK	_tlm2_busterselect
		TLM_PAK	_tlm3_game_over
;		TLM_PAK	_tlm4_score_unused
;		TLM_PAK	_tlm5_kanji_unused
		TLM_PAK	_tlm6_copyrights
		TLM_PAK	_tlm7_staff
		TLM_PAK	_tlm8_HAL
		TLM_PAK	_tlm9_secret_menu
		TLM_PAK	_tlmA_blank

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
		STA		_ppu_queue_buf,X
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
		LDA		_ppu_queue_buf,X
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
		LDA		_ppu_queue_buf,X
		STA		_var4
		LDY		#$08
loc_AF82:
		ASL		_var4
		ROR
		DEY
		BNE		loc_AF82
		STA		_ppu_queue_buf,X
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
		STA		_ppu_queue_buf,X
		CPX		_tmp1
		BNE		loc_AFAF
		RTS

_tlm0_title_screen:
		INCBIN	"../tlm/tlm0.pak"
_tlm1_1p_score:
		INCBIN	"../tlm/tlm1.pak"
_tlm1_2p_score:
		INCBIN	"../tlm/tlm1_2p.pak"
_tlm2_busterselect:
		INCBIN	"../tlm/tlm2.pak"
_tlm3_game_over:
		INCBIN	"../tlm/tlm3.pak"
;_tlm4_score_unused:
;		INCBIN	"../tlm/tlm4.pak"
;_tlm5_kanji_unused:
;		INCBIN	"../tlm/tlm5.pak"
_tlm6_copyrights:
; REGION, first typo fixed in the EU version, however, not the second one lol
;		INCBIN	"../tlm/tlm6_eu.pak"
; REGION, same typos as in the JP version, HAL lab changed to HAL america
;		INCBIN	"../tlm/tlm6_us.pak"
; REGION, JP
;		INCBIN	"../tlm/tlm6_jp.pak"
; NEW, fixed "ghostbust" typo, added "cah4e3 bfs gmbh"
		INCBIN	"../tlm/tlm6_bfs.pak"
; -
_tlm7_staff:
		INCBIN	"../tlm/tlm7.pak"
_tlm8_HAL:
; REGION, different type of HAL logo for US region
;		INCBIN	"../tlm/tlm8_hal_us.pak"
		INCBIN	"../tlm/tlm8_hal_jp_eu.pak"
; -
_tlm9_secret_menu:
;		INCBIN	"../tlm/tlm9.pak"
; NEW, changed the layout of secret menu
		INCBIN	"../tlm/tlm9_bfs.pak"

_tlmA_blank:
		INCBIN	"../tlm/tlmA_bfs.pak"

		SECTION_END	"TLM UNPACKER AND DATA"

		BANK_END 0,$C000
