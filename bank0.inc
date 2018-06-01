
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

		BANK_START $00

		SECTION_START

; =============== S C R I P T ===============================================
_scr00_intro_title_select:
; NOTE: if switch case index higher than maximum number of entries in table,
; then switch case skipped, so default branch is always just after the case
; but. there are scripts isn't using this method rather than using raw direct
; indexes and never skips the switch itself, so they may have any other data
; after case table instead of any actual code...
; TODO: also not sure why they not use default branch as case with index 00 here
; then with corresponding adjusting of other indexes...
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$0C
		SCASE			_sub01_intro_slime		; 01
		SCASE			_sub02_intro_busterA	; 02
		SCASE			_sub03_intro_busterB	; 03
		SCASE			_sub04_intro_busterC	; 04
		SCASE			_sub05_intro_busterD	; 05
		SCASE			_sub06_select_peter		; 06
		SCASE			_sub07_select_ray		; 07
		SCASE			_sub08_select_egon		; 08
		SCASE			_sub09_select_winston	; 09
		SCASE			_sub0A_select_louis		; 0A
		SCASE			_intro_sub0B_title_ghost; 0B
		SCASE			_intro_sub0C_title_new	; 0C

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
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
		SDELAY			$5A
		SJSR			_ssub_pal_fade_out				; shut down the picture
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; load new packed tilemap with license info
			NARGB		_tlm6_copyrights_idx
		NJSR			_nsub_mmc1_chr1_set				; CHR bank
			NARGB		$09
		NJSR			_nsub_bg_pal_load				; load another palette
			NARGW		_pal1							; NOTE: both palettes are the same
		SJSR			_ssub_pal_fade_in				; and again show it for 1.5 seconds
		SDELAY			$5A
		SJSR			_ssub_pal_fade_out

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sloc_title_start:
		NJSR			_nsub_apu_mus_load				; start title music theme
			NARGB		$05
		NJSR			_nsub_full_pal_load				; load title palette
			NARGW		_pal2
; TODO: for some reason, this native subroutines just does write
; to the _chr_bank0/_chr_bank1 variables, why they need to set a separate
; function for that, if STORE8 opcode can be used instead? however
; this won't save us a byte, opcode sizes are the same... that would
; be useful if there is an opcode with offset to zero ram existed...
; or maybe an additional opcode may be assigned to set exactly chr banks
; which may be shorter (one 3-byte opcode or two 2-byte)
		NJSR			_nsub_mmc1_chr0_set				; set CHR for bg and sprites
			NARGB		$01
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$00
; -
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack title screen frame window
			NARGB		_tlm0_title_screen_idx
		SARG_SET		SARG2,$00						; init one of internal tmp vars
		SLOOP_BEGIN		$12								; in this case this is a line counter
; NOTE: the lib tilemap seems can't draw smaller rects than the screen itself
; so they did such workaround for displaying the title graphics on the fly
;
		NJSR			_nsub_tlm_raw_arg2_idx_line_draw; draw tilemap of the title logo in
			NARGW		_tlm_title_logo					; the middle line by line...
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_title_attr_select			; load one of two attributes data
			NARGB		$00								; for title screen, select with arg
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
		SPR_IDX_INC		3								; after 1sec animate title sprite patch to show
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
		NJSR			_nsub_title_attr_select			; load second set of attrs
			NARGB		$01
		NJSR			_nsub_hi_scores_display			; draw additional hi-scores
			NARGB		$0F,$0A
		NJSR			_nsub_full_pal_load				; load new paletter for this portion
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
; TODO: this portion mostly the same as the first part of the title script
; it may be reduced in size by separating the common operations to a
; _ssub function, or just rearranged to allow just restarting from position
; where it redraws the screen...
;
		SARG_SET		SARG2,$00						; now redraw the title logo again
		SLOOP_BEGIN		$12
		NJSR			_nsub_tlm_raw_arg2_idx_line_draw
			NARGW		_tlm_title_logo
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_title_attr_select			; restore attribs...
			NARGB		$00
		NJSR			_nsub_full_pal_load				; ...palettes
			NARGW		_pal2
		NJSR			_nsub_mmc1_chr1_set				; ...and CHR bank 0
			NARGB		$00
		SPR_IDX_SET		1,$00							; not sure whey they restore the sprite here
		SJSR			_ssub_title_maskDB_fade_in		; fade in and do loop
		SJMP			_sloc_title_loop

; =============== S C R I P T ===============================================
_scr_title_push_start_anim:
		SLOOP_BEGIN		$02								; just does masked fade for
		NJSR			_nsub_pal_fade_req_inc_by_mask	; particular paletter entry
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

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_title_maskDB_fade_out:
		SLOOP_BEGIN		$04								; masked fade out for middle part
		NJSR			_nsub_pal_fade_req_dec_by_mask	; of the title screen, excluding curtains
			NARGB		$DB
		SDELAY			$04
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_title_maskDB_fade_in:
		SLOOP_BEGIN		$04								; fade in the same area
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$DB
		SDELAY			$04
		SLOOP_END
		SRET

; =============== S C R I P T ===============================================
_scr_select_busters_start:
		SJSR			_ssub_pal_fade_out				; TODO: this helper is redundant
		SJMP			_scr_select_busters

; =============== S C R I P T ===============================================
_scr_secret_menu_start:
		SJSR			_ssub_pal_fade_out				; TODO: this too, why not load directly?
		SJMP			_scr_secret_menu

_chain_title_anim_scripts_data:
		.BYTE	_sub01_intro_slime_idx+1,	$00,$08,$60
		.BYTE	_sub02_intro_busterA_idx+1,	$00,$10,$20
		.BYTE	_sub03_intro_busterB_idx+1,	$F8,$10,$00
		.BYTE	_sub04_intro_busterC_idx+1,	$08,$10,$20
		.BYTE	_sub05_intro_busterD_idx+1,	$00,$10,$00

; TODO: both paletters are the same for released versions, however, the prototype
; version uses different palettes, so they just not changed scripts but changed
; only palettes
_pal0:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00
_pal1:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00
; -
_pal2:
		.BYTE	$0F,$30,$15,$29,$0F,$30,$01,$29,$0F,$21,$11,$01,$0F,$14,$10,$30
		.BYTE	$0F,$36,$1C,$0F,$0F,$30,$35,$0F,$0F,$30,$15,$29,$0F,$36,$2B,$0F
_pal3:
		.BYTE	$0F,$35,$15,$05,$0F,$25,$10,$00,$0F,$21,$11,$01,$0F,$30,$2A,$01
		.BYTE	$0F,$30,$15,$29,$0F,$30,$35,$0F,$0F,$30,$10,$00,$0F,$30,$2A,$01
_tlm_title_logo:
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$2C,$3C,$20,$30,$40,$50,$60,$70,$80,$90,$A0,$B0,$C0,$D0,$E0,$F0,$F5,$23,$33,$43
		.BYTE	$FE,$FE,$FE,$FE,$2D,$3D,$21,$31,$41,$51,$61,$71,$81,$91,$A1,$B1,$C1,$D1,$E1,$F1,$F6,$24,$34,$44
		.BYTE	$FE,$FE,$FE,$FE,$2E,$3E,$22,$32,$42,$52,$62,$72,$82,$EC,$EB,$88,$98,$72,$E2,$F2,$F7,$25,$35,$45
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$83,$93,$A3,$B3,$C3,$D3,$E3,$F3,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$74,$84,$94,$A4,$B3,$C3,$D4,$E4,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$55,$65,$75,$85,$95,$A5,$B5,$C5,$D5,$E5,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$56,$EE,$76,$86,$96,$A6,$B6,$C6,$D6,$E6,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$47,$57,$67,$77,$87,$97,$EE,$B6,$C7,$D7,$E7,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$48,$58,$68,$78,$EE,$97,$EE,$B8,$C8,$D8,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$49,$59,$69,$EE,$89,$99,$A9,$B9,$C9,$D9,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$4A,$5A,$6A,$89,$8A,$EF,$AA,$BA,$CA,$DA,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$4B,$5B,$6B,$7B,$EF,$9B,$EE,$4C,$CB,$DB,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$2F,$EF,$46,$26,$36,$53,$63,$EA,$FA,$DC,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$3F,$EF,$EF,$27,$FF,$FF,$FF,$FF,$FB,$DD,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$73,$EF,$28,$38,$FF,$FF,$FF,$FC,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$66,$29,$39,$54,$64,$ED,$FD,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
; REGION, "HAL lab." changed in the US proto version
_tlm_title_text:
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$54,$4D,$FF
		.BYTE	$FF,$FF,$60,$70,$80,$90,$A0,$B0,$C0,$D0,$E0,$F0,$63,$73,$83,$93,$A3,$B3,$C3,$D3,$E3,$F3,$FF,$FF
		.BYTE	$FF,$FF,$61,$71,$81,$91,$A1,$B1,$C1,$D1,$E1,$F1,$64,$74,$84,$94,$A4,$B4,$C4,$D4,$E4,$F4,$FF,$FF
		.BYTE	$FF,$FF,$62,$72,$82,$92,$A2,$B2,$C2,$D2,$E2,$F2,$65,$75,$85,$95,$A5,$B5,$C5,$D5,$E5,$F5,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$54,$30,$50,$FF,$20,$20,$20,$20,$20,$30,$30,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$50,$55,$53,$48,$FF,$53,$54,$41,$52,$54,$FF,$42,$55,$54,$54,$4F,$4E,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$20,$20,$20,$20,$42,$59,$20,$48,$41,$4C,$20,$4C,$41,$42,$4F,$52,$41,$54,$4F,$52,$59,$20,$20,$20

; =============== S U B R O U T I N E =======================================
_nbgsub_title_input:
		LDA		_pad0_pressed				; this is native background routine for
		AND		#PAD_START					; title thread. when START pressed, test
		BEQ		locret_8539					; additionally for A+B held
		LDA		_pad0_held
		AND		#PAD_A|PAD_B
		CMP		#PAD_A|PAD_B
		BNE		loc_8534					; if true, restart current thread with
		JSR		_cur_thread_reload_param	; secret menu script
		.WORD	_scr_secret_menu_start
		RTS
loc_8534:
		JSR		_cur_thread_reload_param	; if false, restart this thread with
		.WORD	_scr_select_busters_start	; busters select script
locret_8539:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_title_attr_select:
		JSR		_scr_getc					; TODO: if assign new _nsub_ppu_res_send_param
		BNE		loc_8545					; routine, all this stuff may be called from
		JSR		_ppu_res_send_param			; script directly using script commands...
		.WORD	_attr_title0
		RTS
loc_8545:
		JSR		_ppu_res_send_param
		.WORD	_attr_title1
		RTS

; NOTE: there is no point in sending attrs in rectangular format, we may send it as raw 64x1 line as well (up to 127 allowed)
;
_attr_title0:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$0A,$5A,$5A,$5A,$5A,$5A,$AA,$AA,$00,$05,$05,$05,$05,$05,$AA,$AA,$00,$00,$00,$00,$00,$00,$AA,$AA,$00,$00,$00,$00,$00,$00,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$00,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A
_attr_title1:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$0A,$0A,$0A,$0A,$0A,$0A,$AA,$AA,$00,$00,$00,$00,$00,$0F,$AA,$AA,$00,$C0,$F0,$F0,$30,$00,$AA,$AA,$00,$00,$00,$10,$51,$00,$AA
		.BYTE	$AA,$C0,$F5,$F5,$F5,$F5,$31,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A

_spr_raw_lib00_00:
		.BYTE	$0C
		.BYTE	$F0,$D4,$02,$10
		.BYTE	$F0,$C4,$02,$08
		.BYTE	$F0,$B4,$02,$00
		.BYTE	$F0,$A4,$02,$F8
		.BYTE	$F0,$94,$02,$F0
		.BYTE	$F0,$84,$02,$E8
		.BYTE	$00,$86,$02,$E8
		.BYTE	$00,$96,$02,$F0
		.BYTE	$00,$A6,$02,$F8
		.BYTE	$00,$C6,$02,$08
		.BYTE	$00,$D6,$02,$10
		.BYTE	$00,$B6,$02,$00
_spr_raw_lib00_01:
		.BYTE	$0C
		.BYTE	$F0,$D0,$02,$10
		.BYTE	$F0,$C0,$02,$08
		.BYTE	$F0,$B0,$02,$00
		.BYTE	$F0,$A0,$02,$F8
		.BYTE	$F0,$90,$02,$F0
		.BYTE	$F0,$80,$02,$E8
		.BYTE	$00,$82,$02,$E8
		.BYTE	$00,$92,$02,$F0
		.BYTE	$00,$A2,$02,$F8
		.BYTE	$00,$C2,$02,$08
		.BYTE	$00,$D2,$02,$10
		.BYTE	$00,$B2,$02,$00

; =============== S C R I P T ===============================================
_sub01_intro_slime:
		SSCRIPT1_SET	_scr_intro_slime_anim	; run additionall parallel script for
		POS_Y_DELTA_SET 6,$00,$01		; this object, while main script just
		POS_Y_DELTA_SET 0,$80,$00		; set the moving parameters and then
		SDELAY			$C8				; wait before stop
		SSTOP

; NOTE: don't know why they decided to use secondary script for some kind of
; work, since there is possible to do that in regular script form using loops
; which is actually used in many other times using loops/delays and delayed
; commands... probably this looks simplier.
;
; =============== S C R I P T ===============================================
_scr_intro_slime_anim:
		SPR_IDX_SET		6,$02			; secondary slime script for sprite
		SPR_IDX_INC		6				; animation. when main script
		SJMP			_scr_intro_slime_anim	; stops, this will disable as well

_spr_raw_lib00_02:
		.BYTE	$04
		.BYTE	$F0,$88,$43,$00
		.BYTE	$F0,$88,$03,$F8
		.BYTE	$00,$8A,$03,$F8
		.BYTE	$00,$8A,$43,$00
_spr_raw_lib00_03:
		.BYTE	$04
		.BYTE	$00,$8E,$43,$00
		.BYTE	$00,$8E,$03,$F8
		.BYTE	$F0,$8C,$03,$F8
		.BYTE	$F0,$8C,$43,$00

; =============== S C R I P T ===============================================
_sub02_intro_busterA:
		SPR_IDX_SET		0,$04

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sloc_intro_busters_delay:
		POS_Y_DELTA_SET 0,$00,$02
		SDELAY			$0C

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
; all intro busters animations are the same difference only in initial sprite index
; and an appearance delay, every single buster script also set the starting position
;
_sloc_intro_busters_no_delay:
		SPR_IDX_INC		0					; +1 (5)
		POS_MOVE_STOP	0
		SDELAY			$10
		POS_Y_DELTA_SET 0,$80,$00
		SLOOP_BEGIN		$06					; loop 6-5-7-5... period
		SPR_IDX_INC		6					; +1 (6)
		SPR_IDX_DEC		6					; -1 (5)
		SPR_IDX_ADD_IMM 6,$02				; +2 (7)
		SPR_IDX_ADD_IMM 6,$FE				; -2 (5)
		SLOOP_END
		SSTOP

; NOTE: even if all these sprites are set in libraries 08 and 09, they copied here
; as well. also an ending libraries contains more copies... this is fine for
; not care about actual sprite data locations or not care about optimizations
; (at least there are a lot of free space anyway), however, this may be optimized
; as well
;
_spr_raw_lib00_04:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$08,$40,$00
		.BYTE	$F0,$08,$00,$F8
_spr_raw_lib00_05:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$08,$40,$00
		.BYTE	$F0,$08,$00,$F8
_spr_raw_lib00_06:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$08,$40,$00
		.BYTE	$F1,$08,$00,$F8
_spr_raw_lib00_07:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$08,$40,$00
		.BYTE	$F1,$08,$00,$F8
_spr_raw_lib00_08:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$10,$00,$00
		.BYTE	$F0,$00,$00,$F8
_spr_raw_lib00_09:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$10,$00,$00
		.BYTE	$F1,$00,$00,$F8
_spr_raw_lib00_0A:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$10,$00,$00
		.BYTE	$F1,$00,$00,$F8
_spr_raw_lib00_0B:
		.BYTE	$04
		.BYTE	$00,$7E,$00,$06
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$F0,$D8,$00,$06
		.BYTE	$F0,$C8,$00,$FE
_spr_raw_lib00_0C:
		.BYTE	$04
		.BYTE	$00,$EC,$40,$00
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$F0,$F0,$00,$00
		.BYTE	$F0,$E0,$00,$F8
_spr_raw_lib00_0D:
		.BYTE	$04
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$F0,$D8,$40,$F2
		.BYTE	$F0,$C8,$40,$FA
_spr_raw_lib00_0E:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$18,$40,$00
		.BYTE	$F0,$18,$00,$F8
_spr_raw_lib00_0F:
		.BYTE	$02
		.BYTE	$F0,$D8,$40,$F2
		.BYTE	$F0,$C8,$40,$FA

; =============== S C R I P T ===============================================
_sub03_intro_busterB:
		SPR_IDX_SET		0,$10
		POS_X_DELTA_SET 0,$40,$FF
		SJMP			_sloc_intro_busters_delay

_spr_raw_lib00_10:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$0C,$40,$00
		.BYTE	$F0,$0C,$00,$F8
_spr_raw_lib00_11:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$0C,$40,$00
		.BYTE	$F0,$0C,$00,$F8
_spr_raw_lib00_12:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$0C,$40,$00
		.BYTE	$F1,$0C,$00,$F8
_spr_raw_lib00_13:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$0C,$40,$00
		.BYTE	$F1,$0C,$00,$F8
_spr_raw_lib00_14:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$14,$00,$00
		.BYTE	$F0,$04,$00,$F8
_spr_raw_lib00_15:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$14,$00,$00
		.BYTE	$F1,$04,$00,$F8
_spr_raw_lib00_16:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$14,$00,$00
		.BYTE	$F1,$04,$00,$F8
_spr_raw_lib00_17:
		.BYTE	$04
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$00,$7E,$00,$06
		.BYTE	$F0,$DC,$00,$06
		.BYTE	$F0,$CC,$00,$FE
_spr_raw_lib00_18:
		.BYTE	$04
		.BYTE	$00,$EC,$40,$00
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$F0,$F4,$00,$00
		.BYTE	$F0,$E4,$00,$F8
_spr_raw_lib00_19:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$DC,$40,$F2
		.BYTE	$F0,$CC,$40,$FA
_spr_raw_lib00_1A:
		.BYTE	$04
		.BYTE	$00,$EE,$40,$00
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$F0,$1C,$00,$F8
		.BYTE	$F0,$1C,$40,$00
_spr_raw_lib00_1B:
		.BYTE	$02
		.BYTE	$F0,$DC,$40,$F2
		.BYTE	$F0,$CC,$40,$FA

; =============== S C R I P T ===============================================
_sub04_intro_busterC:
		SPR_IDX_SET		0,$1C
		POS_X_DELTA_SET 0,$C0,$00
		SJMP			_sloc_intro_busters_delay

_spr_raw_lib00_1C:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$0E,$40,$00
		.BYTE	$F0,$0E,$00,$F8
_spr_raw_lib00_1D:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$0E,$40,$00
		.BYTE	$F0,$0E,$00,$F8
_spr_raw_lib00_1E:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$0E,$40,$00
		.BYTE	$F1,$0E,$00,$F8
_spr_raw_lib00_1F:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$0E,$40,$00
		.BYTE	$F1,$0E,$00,$F8
_spr_raw_lib00_20:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$16,$00,$00
		.BYTE	$F0,$06,$00,$F8
_spr_raw_lib00_21:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$16,$00,$00
		.BYTE	$F1,$06,$00,$F8
_spr_raw_lib00_22:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$16,$00,$00
		.BYTE	$F1,$06,$00,$F8
_spr_raw_lib00_23:
		.BYTE	$04
		.BYTE	$00,$7E,$00,$06
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$F0,$DE,$00,$06
		.BYTE	$F0,$CE,$00,$FE
_spr_raw_lib00_24:
		.BYTE	$04
		.BYTE	$00,$EC,$40,$00
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$F0,$F6,$00,$00
		.BYTE	$F0,$E6,$00,$F8
_spr_raw_lib00_25:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$DE,$40,$F2
		.BYTE	$F0,$CE,$40,$FA
_spr_raw_lib00_26:
		.BYTE	$04
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00
		.BYTE	$F0,$1E,$40,$00
		.BYTE	$F0,$1E,$00,$F8
_spr_raw_lib00_27:
		.BYTE	$02
		.BYTE	$F0,$DE,$40,$F2
		.BYTE	$F0,$CE,$40,$FA

; =============== S C R I P T ===============================================
_sub05_intro_busterD:
		SPR_IDX_SET		0,$28
		POS_Y_DELTA_SET 0,$00,$02
		SDELAY			$0A
		SJMP			_sloc_intro_busters_no_delay

_spr_raw_lib00_28:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$0A,$40,$00
		.BYTE	$F0,$0A,$00,$F8
_spr_raw_lib00_29:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$0A,$40,$00
		.BYTE	$F0,$0A,$00,$F8
_spr_raw_lib00_2A:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$0A,$40,$00
		.BYTE	$F1,$0A,$00,$F8
_spr_raw_lib00_2B:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$0A,$40,$00
		.BYTE	$F1,$0A,$00,$F8
_spr_raw_lib00_2C:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$12,$00,$00
		.BYTE	$F0,$02,$00,$F8
_spr_raw_lib00_2D:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$12,$00,$00
		.BYTE	$F1,$02,$00,$F8
_spr_raw_lib00_2E:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$12,$00,$00
		.BYTE	$F1,$02,$00,$F8
_spr_raw_lib00_2F:
		.BYTE	$04
		.BYTE	$00,$7E,$00,$06
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$F0,$DA,$00,$06
		.BYTE	$F0,$CA,$00,$FE
_spr_raw_lib00_30:
		.BYTE	$04
		.BYTE	$00,$EC,$40,$00
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$F0,$F2,$00,$00
		.BYTE	$F0,$E2,$00,$F8
_spr_raw_lib00_31:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$DA,$40,$F2
		.BYTE	$F0,$CA,$40,$FA
_spr_raw_lib00_32:
		.BYTE	$04
		.BYTE	$00,$EE,$40,$00
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$F0,$1A,$00,$F8
		.BYTE	$F0,$1A,$40,$00
_spr_raw_lib00_33:
		.BYTE	$02
		.BYTE	$F0,$DA,$40,$F2
		.BYTE	$F0,$CA,$40,$FA

; =============== S C R I P T ===============================================
_intro_sub0B_title_ghost:
		POS_X_SET		0,$80,$00			; animation loop for small ghost
		POS_Y_SET		0,$68,$00			; showing "victory" on the second
		SLOOP_BEGIN		$05					; text portion of the title screen
		SPR_IDX_SET		0,$46				; spr 46 start, repeat 6 times
		SDELAY			$20
		SPR_IDX_INC		6					; +1 (47)
		SPR_IDX_INC		6					; +1 (48)
		SPR_IDX_INC		6					; +1 (49)
		SPR_IDX_INC		0					; +1 (4A)
		SDELAY			$10
		SPR_IDX_INC		0					; +1 (4B)
		SDELAY			$20
		SPR_IDX_DEC		7					; -1 (4A)
		SPR_IDX_DEC		6					; -1 (49)
		SPR_IDX_DEC		6					; -1 (48)
		SPR_IDX_DEC		6					; -1 (47)
		SLOOP_END
		SSTOP

_spr_raw_lib00_46:
		.BYTE	$06
		.BYTE	$F0,$DB,$02,$F4
		.BYTE	$F0,$FB,$02,$04
		.BYTE	$00,$FD,$02,$04
		.BYTE	$00,$DD,$02,$F4
		.BYTE	$00,$ED,$02,$FC
		.BYTE	$F0,$EB,$02,$FC
_spr_raw_lib00_47:
		.BYTE	$04
		.BYTE	$00,$E9,$02,$F8
		.BYTE	$00,$F9,$02,$00
		.BYTE	$F0,$F7,$02,$00
		.BYTE	$F0,$E7,$02,$F8
_spr_raw_lib00_48:
		.BYTE	$04
		.BYTE	$00,$D9,$02,$00
		.BYTE	$00,$C9,$02,$F8
		.BYTE	$F0,$C7,$02,$F8
		.BYTE	$F0,$D7,$02,$00
_spr_raw_lib00_49:
		.BYTE	$04
		.BYTE	$00,$B9,$02,$00
		.BYTE	$00,$A9,$02,$F8
		.BYTE	$F0,$A7,$02,$F8
		.BYTE	$F0,$B7,$02,$00
_spr_raw_lib00_4A:
		.BYTE	$07
		.BYTE	$F0,$97,$02,$0C
		.BYTE	$F0,$87,$02,$04
		.BYTE	$00,$89,$02,$04
		.BYTE	$00,$79,$02,$FC
		.BYTE	$F0,$77,$02,$FC
		.BYTE	$00,$69,$02,$F4
		.BYTE	$F0,$67,$02,$F4
_spr_raw_lib00_4B:
		.BYTE	$0B
		.BYTE	$F0,$9B,$00,$04
		.BYTE	$00,$8B,$00,$04
		.BYTE	$00,$7B,$00,$FC
		.BYTE	$00,$6B,$00,$F4
		.BYTE	$F0,$99,$02,$F4
		.BYTE	$F0,$17,$02,$0C
		.BYTE	$F0,$07,$02,$04
		.BYTE	$F0,$19,$02,$FC
		.BYTE	$00,$2B,$02,$04
		.BYTE	$00,$1B,$02,$FC
		.BYTE	$00,$CB,$02,$F4

; =============== S C R I P T ===============================================
_intro_sub0C_title_new:
		POS_X_SET		0,$30,$00				; set "NEW" sprite position
		POS_Y_SET		0,$20,$00
		SPR_IDX_SET		0,$4C					; select sprite index from lib00
_sloc_8A65:
		SARG_SET		SARG0,$00				; init tmp counter var
		SLOOP_BEGIN		$06
		NJSR			_nsub_pal_patch_load	; read pal byte from selected array
			NARGW		_pal_new_blink			; with index SARG0, put it on
			NARGB		$16,SARG0				; selected position of palette buffer (16),
		SARG_ALU		$00,_ADC,$01			; then blit it and increment idx
		SDELAY			$01						; sync to fluch buffers, loop 6 times
		SLOOP_END
		SJMP			_sloc_8A65				; repeat infinitely

; =============== S C R I P T ===============================================
; NOTE: same blinking routine intended to blink black letters of the same "NEW"
; sprite instead of pink border. it uses different SARG1 variable for some reason
; but since it goes to infinite loop as well, they planned to run it separately
; in some unknown cases.
;
_intro_sub0C_title_new_unref:
		SARG_SET		SARG1,$00
		SLOOP_BEGIN		$06
		NJSR			_nsub_pal_patch_load
			NARGW		_pal_new_blink_unused
			NARGB		$17,SARG1
		SARG_ALU		$01,_ADC,$01
		SDELAY			$01
		SLOOP_END
		SJMP			_intro_sub0C_title_new_unref

_pal_new_blink:
		.BYTE	$35,$25,$15,$05,$15,$25
_pal_new_blink_unused:
		.BYTE	$0F,$10,$20,$30,$20,$10,$01 ; *--

; =============== S U B R O U T I N E =======================================
_nsub_pal_patch_load:
		JSR		_scr_getc					; this is custom palette blink routine used
		STA		_ptr06						; only for this place... in other cases they
		JSR		_scr_getc					; used common pal fade _nsub routine with
		STA		_ptr06+1					; mask arguments...
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		TAY
		LDA		_scr_args_list_ptr_lo,Y
		STA		_ptr08
		LDA		_scr_args_list_ptr_hi,Y
		STA		_ptr08+1
		LDY		_scr_cur_trd_idx
		LDA		(_ptr08),Y
		TAY
		LDA		(_ptr06),Y
		STA		_pal_buf,X
		JMP		_full_pal_fade

_spr_raw_lib00_4C:
		.BYTE	$0E
		.BYTE	$00,$CF,$01,$10
		.BYTE	$F0,$CD,$01,$10
		.BYTE	$F0,$BD,$01,$08
		.BYTE	$00,$BF,$01,$08
		.BYTE	$00,$AF,$01,$00
		.BYTE	$F0,$AD,$01,$00
		.BYTE	$F0,$9D,$01,$F8
		.BYTE	$00,$9F,$01,$F8
		.BYTE	$00,$8F,$01,$F0
		.BYTE	$F0,$8D,$01,$F0
		.BYTE	$F0,$7D,$01,$E8
		.BYTE	$00,$7F,$01,$E8
		.BYTE	$00,$6F,$01,$E0
		.BYTE	$F0,$6D,$01,$E0

; =============== S C R I P T ===============================================
; this script replaces the main thread's 00 script at slot 00 when you press
; START at the title.
;
_scr_select_busters:
		NJSR			_nsub_all_threads_off_except_cur; disable all other thread leftovers
		NJSR			_nsub_mmc1_mirror_horizontal	; the rest is usual screen preparations
		NJSR			_nsub_far_prg0_tlm_lib_unpack
			NARGB		_tlm2_busterselect_idx
		NJSR			_nsub_mmc1_mirror_vertical
		NJSR			_nsub_full_pal_load
			NARGW		_pal_select_busters
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$06
		STORE8			_beam_player_idxA,$FF			; no players selected yet, reset
		STORE8			_catch_player_idxA,$FF
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
			NARGB		$01
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

; =============== S U B R O U T I N E =======================================
_nsub_players_idx_init:
		LDY		_beam_player_idxA
		LDA		byte_8BC3,Y
		STA		_beam_player_idxA
		STA		_beam_player_idxB
		LDY		_catch_player_idxA
		LDA		byte_8BC3,Y
		STA		_catch_player_idxA
		STA		_catch_player_idxB
		RTS
byte_8BC3:
		.BYTE	$00,$10,$20,$30,$40

; =============== S U B R O U T I N E =======================================
_nsub_select_buster_input:
		LDX		_scr_cur_trd_idx
		LDA		_pad0_pressed				; test for L/R buttons press
		AND		#PAD_R
		BEQ		loc_8BE6
		LDA		#$0B
		JSR		_far_prg6_apu_snd_load
loc_8BD5:
		INC		_scr_trds_args0,X			; increment current selection index
		LDA		_scr_trds_args0,X
		CMP		#$05
		BCC		loc_8BE1
		LDA		#$00
		STA		_scr_trds_args0,X
loc_8BE1:
		CMP		_beam_player_idxA			; skip if first player already selected
		BEQ		loc_8BD5					; jump to increment one more time
loc_8BE6:
		LDA		_pad0_pressed
		AND		#PAD_L
		BEQ		loc_8C00
		LDA		#$0B
		JSR		_far_prg6_apu_snd_load
loc_8BF1:
		DEC		_scr_trds_args0,X			; same but for decrement
		BPL		loc_8BF9
		LDA		#$04
		STA		_scr_trds_args0,X
loc_8BF9:
		LDA		_scr_trds_args0,X
		CMP		_beam_player_idxA
		BEQ		loc_8BF1
loc_8C00:
; TODO: very annoying, title accepts only START, select busters only A
; maybe fix it with allow START to be input here a well
		LDA		_pad0_pressed				; select with A
		AND		#PAD_A
		BEQ		loc_8C36
		LDA		#$0C
		JSR		_far_prg6_apu_snd_load		; init one of two players indexes
		LDA		_scr_trds_args0,X
		LDY		_beam_player_idxA
		BPL		loc_8C17
		STA		_beam_player_idxA
		BMI		loc_8C1A
loc_8C17:
		STA		_catch_player_idxA
loc_8C1A:
		LDA		#$FF
		STA		_scr_trds_spr_idx,X			; disable obj name sprite, jump to
		LDA		#$00						; next object
		STA		_cur_room_x_pageA
loc_8C23:
		INC		_scr_trds_args0,X
		LDA		_scr_trds_args0,X
		CMP		#$05
		BCC		loc_8C2F
		LDA		#$00
		STA		_scr_trds_args0,X
loc_8C2F:
		CMP		_beam_player_idxA
		BEQ		loc_8C23
		SEC									; when selection is done, set carry to
		RTS									; signal the main code to do next part
loc_8C36:
		LDY		_scr_trds_args0,X			; display the name sprite for currently
		LDA		byte_8C51,Y					; highlighted player
		STA		_scr_trds_x_pos_lo,X
		LDA		byte_8C56,Y
		STA		_scr_trds_y_pos_lo,X
		LDA		#$00
		STA		_scr_trds_x_pos_hi,X
		STA		_scr_trds_y_pos_hi,X
		TYA
		CLC
		ADC		#$40
		STA		_scr_trds_spr_idx,X
		RTS

byte_8C51:
		.BYTE	$68,$80,$98,$B0,$E0
byte_8C56:
		.BYTE	$70,$70,$70,$70,$B0

_spr_raw_lib00_40:
		.BYTE	$05
		.BYTE	$F4,$ED,$02,$0C
		.BYTE	$F4,$E9,$02,$EC
		.BYTE	$F4,$D3,$02,$04
		.BYTE	$F4,$D3,$02,$F4
		.BYTE	$F4,$F1,$02,$FC
_spr_raw_lib00_41:
		.BYTE	$03
		.BYTE	$F4,$FB,$02,$04
		.BYTE	$F4,$ED,$02,$F4
		.BYTE	$F4,$CB,$02,$FC
_spr_raw_lib00_42:
		.BYTE	$04
		.BYTE	$F4,$E5,$02,$08
		.BYTE	$F4,$E7,$02,$00
		.BYTE	$F4,$D7,$02,$F8
		.BYTE	$F4,$D3,$02,$F0
_spr_raw_lib00_43:
		.BYTE	$07
		.BYTE	$F4,$E5,$02,$14
		.BYTE	$F4,$E7,$02,$0C
		.BYTE	$F4,$F1,$02,$04
		.BYTE	$F4,$EF,$02,$FC
		.BYTE	$F4,$E5,$02,$F4
		.BYTE	$F4,$DB,$02,$EC
		.BYTE	$F4,$F7,$02,$E4
_spr_raw_lib00_44:
		.BYTE	$05
		.BYTE	$F4,$E1,$02,$EC
		.BYTE	$F4,$EF,$02,$0C
		.BYTE	$F4,$DB,$02,$04
		.BYTE	$F4,$F3,$02,$FC
		.BYTE	$F4,$E7,$02,$F4
_spr_raw_lib00_45:
		.BYTE	$02
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$00,$EE,$40,$00

; =============== S C R I P T ===============================================
; PETER
_sub06_select_peter:
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$08				; set default left-oriented sprite for this object
		SPR_IDX_SET		0,$09					; set current anim walk start sprite
		SJSR			_ssub_select_busters
		SUSPEND

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_select_busters:
		POS_X_DELTA_SET 0,$00,$FC				; first animate the entry of 4 busters
		SDELAY			$20						; horizontally left without walk anim
		SPR_IDX_ADD_IMM 3,$FE					; turn face to the screen while slowdown
		POS_X_DELTA_SET 0,$00,$FE				; step by step in 14 frames
		SDELAY			$03						;
		POS_X_DELTA_SET 0,$00,$FF
		SDELAY			$04
		POS_X_DELTA_SET 0,$80,$FF
		SDELAY			$03
		POS_X_DELTA_SET 0,$E0,$FF
		SDELAY			$04
		POS_MOVE_STOP	0						; stop move
		SPR_IDX_ADD_IMM 0,$FE					; change sprite to step forward
		SDELAY			$0F						; and move vertically down a little
		POS_Y_DELTA_SET 0,$00,$01
		SDELAY			$04
		SPR_IDX_INC		4						; return standing anim
		SPR_IDX_DEC		0
		POS_MOVE_STOP	0						; stop again
		SLOOP_BEGIN		$02						; and then walk a little at the same pos
		SDELAY			$04
		SPR_IDX_ADD_IMM 4,$02
		SPR_IDX_ADD_IMM 4,$FE
		SPR_IDX_INC		4
		SPR_IDX_DEC		0
		SLOOP_END
		STORE8			_cur_room_x_pageA,$01	; now enable selection input
_sloc_8D0C:
		SDELAY			$01						; common portion for any object
		NJSR			_nsub_is_beam_player_selected
		SBCC			_sloc_8D0C				; wait if select is done
		NJSR			_nsub_is_cur_buster_select_for_beam_player
		SBCS			_sloc_beam_player_selected	; then test if this object selected
_sloc_8D1A:
		SDELAY			$01						; for both players one by one
		NJSR			_nsub_is_catch_player_selected
		SBCC			_sloc_8D1A
		NJSR			_nsub_is_cur_buster_select_for_catch_player
		SBCS			_sloc_catch_player_selected
		SUSPEND
_sloc_beam_player_selected:						; here is common beginning for step out
		SJSR			_ssub_buster_selected_step_out	; of selected regular busters
		SPR_IDX_ADD_IMM 0,$03

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
; here is common walk to pole anim for selected beam player
_scr_beam_player_walk_common:
		POS_X_DELTA_SET 0,$00,$FF				; move left init
		SSCRIPT1_SET	_scr_buster_walk_left_anim	; load secondary script for walk anim
_sloc_8D35:
		SDELAY			$01
		NJSR			_nsub_cur_pos_x_lo_icmp	; move left to x=50
			NARGB		$50
		SBCC			_sloc_8D35
		SSCRIPT1_OFF							; stop animation
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1					; get sprite index for stand anim loaded
		POS_MOVE_STOP	0						; at the thread start in SARG1
		STORE8			_cur_room_x_pageA,$01	; raise anim busy flag
_sloc_8D49:
		SDELAY			$01						; first selected player must wait until
		NJSR			_nsub_mtest_bit0		; second player is step aside
			NARGW		_cur_room_x_pageB		; when this occurs, the flag riased
		SBCC			_sloc_8D49
		POS_X_DELTA_SET 0,$00,$FE				; finally start the pole jump up animation
		POS_Y_DELTA_SET 0,$00,$FE				; move up left
		SDELAY			$0C
		POS_MOVE_STOP	0
		SCRL_Y_MOVE_SET 0,$00,$02				; adjust scroll pos

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_nsub_buster_slide_down:
		POS_Y_DELTA_SET 0,$00,$02				; then setup constant scroll move down
		SPR_IDX_ADD_IMM 0,$03					; busters jump up on the pole by linear
		SDELAY			$05						; path, not ballistic. just touch the pole
		SPR_IDX_INC		0						; then and go down
		SDELAY			$05
		SPR_IDX_ADD_IMM 0,$03					; here is the trick to hide object while
		SDELAY			$05						; sliding throught the floor. after a while
		SPR_IDX_SET		0,$FF					; it disables the sprite but object continues
		SDELAY			$19						; to move down. when he about to appear below
		SPR_IDX_SET		0,$45					; draw small dummy sprite representing FOOT
		SDELAY			$05						; show it for some time
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; then load an actual sprite
			NARGB		SARG1					; and continue to animate it... very tricky
		SPR_IDX_ADD_IMM 0,$03					; but no need to make additional clipping!
; NOTE: this looks very funny in slo-mo when only the ass appears from below and move for some
; pixels down alone lol. then the whole sprite appears.
_sloc_8D7B:
		SDELAY			$08						; continue sliding till the end of second page
		SLOOP_BEGIN		$03						; the main script will control the timing
		SPR_IDX_INC		0
		SDELAY			$08
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$FD
		SJMP			_sloc_8D7B

; =============== S C R I P T ===============================================
_sloc_catch_player_selected:
		SJSR			_ssub_buster_selected_step_out
		SPR_IDX_ADD_IMM 0,$03

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_scr_catch_player_walk_common:
		POS_X_DELTA_SET 0,$00,$FF				; same start as for catch player, but...
		SSCRIPT1_SET	_scr_buster_walk_left_anim
_sloc_8D94:
		NJSR			_nsub_cur_pos_x_lo_icmp	; he must stop earlier, at x=68
			NARGB		$68						; TODO: for some reason, the structure of this
		SBCS			_sloc_8DA0				; loop uses different SDELAY layout lol thus
		SDELAY			$01						; need one more branch, very odd
		SJMP			_sloc_8D94
_sloc_8DA0:
		STORE8			_cur_room_x_pageB,$01	; ok, second player is ready, start to slide down
_sloc_8DA4:
		SDELAY			$01
		NJSR			_nsub_cur_pos_x_lo_icmp	; while first player is jumping up, he need
			NARGB		$50						; to reach the same position x=50 first
		SBCC			_sloc_8DA4
		SSCRIPT1_OFF							; now walk is over, start to jump up
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		POS_MOVE_STOP	0
		SDELAY			$02						; set the same move direction, animate
		POS_X_DELTA_SET 0,$00,$FE
		POS_Y_DELTA_SET 0,$00,$FE
		SDELAY			$0C
		POS_MOVE_STOP	0						; stop on the pole, then jump on common code
		SJMP			_nsub_buster_slide_down

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_buster_selected_step_out:
		POS_Y_DELTA_SET 0,$00,$01				; every buster must step out of the line
		SLOOP_BEGIN		$02						; setup y speed and walk anim, run
		SDELAY			$04
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SPR_IDX_ADD_IMM 0,$FE
		SLOOP_END
		POS_MOVE_STOP	0						; all animations uses frame based timings
		SRET

; =============== S C R I P T ===============================================
_scr_buster_walk_left_anim:
		SDELAY			$04						; secondary thread for constant walking animation
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SPR_IDX_ADD_IMM 0,$FE
		SJMP			_scr_buster_walk_left_anim

; =============== S U B R O U T I N E =======================================
_nsub_is_beam_player_selected:
		LDA		_beam_player_idxA				; names are selfexplanatory here and below
		BPL		loc_8DE4
		CLC
		RTS
loc_8DE4:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_is_cur_buster_select_for_beam_player:
		LDX		_scr_cur_trd_idx
		LDA		_beam_player_idxA
		CMP		_scr_trds_args0,X
		BEQ		loc_8DF1
		CLC
		RTS
loc_8DF1:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_is_catch_player_selected:
		LDA		_catch_player_idxA
		BPL		loc_8DFA
		CLC
		RTS
loc_8DFA:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_is_cur_buster_select_for_catch_player:
		LDX		_scr_cur_trd_idx
		LDA		_catch_player_idxA
		CMP		_scr_trds_args0,X
		BEQ		loc_8E07
		CLC
		RTS
loc_8E07:
		SEC
		RTS

; =============== S C R I P T ===============================================
; RAY
_sub07_select_ray:
		SARG_SET		SARG0,$01
		SARG_SET		SARG1,$2C		; final sprite index for object as well
		SPR_IDX_SET		0,$2D
		SJMP			_ssub_select_busters

; =============== S C R I P T ===============================================
; EGON
_sub08_select_egon:
		SARG_SET		SARG0,$02
		SARG_SET		SARG1,$14		; the same for all busters here
		SPR_IDX_SET		0,$15
		SJMP			_ssub_select_busters

; =============== S C R I P T ===============================================
; WINSTON
_sub09_select_winston:
		SARG_SET		SARG0,$03
		SARG_SET		SARG1,$20
		SPR_IDX_SET		0,$21
		SJMP			_ssub_select_busters

; =============== S C R I P T ===============================================
; LOUIS
_sub0A_select_louis:
		SARG_SET		SARG0,$04			; this object has no animation on start
		SARG_SET		SARG1,$38			; so it have it's own script handler
		SPR_IDX_SET		0,$34
_sloc_8E32:
		SDELAY			$01					; wait for beam player selected in main thread
		NJSR			_nsub_is_beam_player_selected
		SBCC			_sloc_8E32			; then there are two options
		NJSR			_nsub_is_cur_buster_select_for_beam_player
		SBCS			_sloc_8E4F
_sloc_8E40:
		SDELAY			$01					; here goes if buster not selected as beam player
		NJSR			_nsub_is_catch_player_selected
		SBCC			_sloc_8E40			; then we just wait for chatch player selection
		NJSR			_nsub_is_cur_buster_select_for_catch_player
		SBCS			_sloc_8E55			; again two options
		SUSPEND								; suspend, if buster not selected for anything
_sloc_8E4F:									; here goes if buster were selected for beam player
		SJSR			_ssub_louis_selected_base_anim
		SJMP			_scr_beam_player_walk_common
_sloc_8E55:									; here goest if buster were selected for catch player
		SJSR			_ssub_louis_selected_base_anim
		SJMP			_scr_catch_player_walk_common

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_louis_selected_base_anim:
		POS_X_DELTA_SET 0,$00,$FF			; first part of louis path common for any selection
		SLOOP_BEGIN		$02					; move left,
		SPR_IDX_SET		4,$38
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SLOOP_END
		POS_MOVE_STOP	0
		POS_Y_DELTA_SET 0,$00,$FF			; move up,
		SLOOP_BEGIN		$02
		SPR_IDX_SET		4,$35
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_ADD_IMM 4,$02
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$38				; prepare to move left to finish
		SRET

_spr_raw_lib00_34:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$22,$40,$00
		.BYTE	$F0,$22,$00,$F8
_spr_raw_lib00_35:
		.BYTE	$04
		.BYTE	$00,$36,$00,$00
		.BYTE	$00,$26,$00,$F8
		.BYTE	$F0,$32,$40,$00
		.BYTE	$F0,$32,$00,$F8
_spr_raw_lib00_36:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$32,$40,$00
		.BYTE	$F1,$32,$00,$F8
_spr_raw_lib00_37:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$32,$40,$00
		.BYTE	$F1,$32,$00,$F8
_spr_raw_lib00_38:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$30,$00,$00
		.BYTE	$F0,$20,$00,$F8
_spr_raw_lib00_39:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$30,$00,$00
		.BYTE	$F1,$20,$00,$F8
_spr_raw_lib00_3A:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$30,$00,$00
		.BYTE	$F1,$20,$00,$F8
_spr_raw_lib00_3B:
		.BYTE	$04
		.BYTE	$00,$7E,$00,$06
		.BYTE	$00,$6E,$00,$FE
		.BYTE	$F0,$FA,$00,$06
		.BYTE	$F0,$EA,$00,$FE
_spr_raw_lib00_3C:
		.BYTE	$04
		.BYTE	$00,$EC,$40,$00
		.BYTE	$00,$EC,$00,$F8
		.BYTE	$F0,$F8,$00,$00
		.BYTE	$F0,$E8,$00,$F8
_spr_raw_lib00_3D:
		.BYTE	$04
		.BYTE	$00,$6E,$40,$FA
		.BYTE	$00,$7E,$40,$F2
		.BYTE	$F0,$FA,$40,$F2
		.BYTE	$F0,$EA,$40,$FA
_spr_raw_lib00_3E:
		.BYTE	$04
		.BYTE	$00,$EE,$40,$00
		.BYTE	$00,$EE,$00,$F8
		.BYTE	$F0,$32,$00,$F8
		.BYTE	$F0,$32,$40,$00
_spr_raw_lib00_3F:
		.BYTE	$02
		.BYTE	$F0,$FA,$40,$F2
		.BYTE	$F0,$EA,$40,$FA

		SECTION_END	"SCR0 TITLE/INTRO/SELECT CODE AND DATA"

		SECTION_START

; =============== S C R I P T ===============================================
_scr_secret_menu:
		NJSR			_nsub_secret_menu_init			; init menu variables
		NJSR			_nsub_all_threads_off_except_cur; kill all leftover threads
		NJSR			_nsub_apu_mus_load				; music stop
			NARGB		$FF
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; unpack menu tilemap
			NARGB		_tlm9_secret_menu_idx
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

; =============== S C R I P T ===============================================
_scr_title_restart:
		SJSR			_ssub_pal_fade_out
		SJMP			_sloc_title_start

_pal_secret_menu:
		.BYTE	$0F,$11,$11,$11,$0F,$30,$30,$30,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_secret_menu_exit_wait:
		LDA		_pad0_pressed				; background native sub to wait
		AND		#PAD_START					; if START is pressed
		BEQ		locret_8FAA
		LDX		_menu_controls_idx			; apply changes to the game vars
		LDA		_ab_controls_,X
		STA		_control_jump_button_code
		LDA		_ba_controls_,X
		STA		_control_fire_button_code
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

; =============== S U B R O U T I N E =======================================
_nsub_secret_menu_init:
		LDX		#$00
		STX		_cur_room_doors_cnt			; this var used here as a menu index
		STX		_menu_controls_idx
		STX		_sound_test_mus_idx
		STX		_sound_test_snd_idx
		INX
		STX		_menu_difficulty_idx
		RTS

; =============== S U B R O U T I N E =======================================
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

; =============== S U B R O U T I N E =======================================
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

; =============== S U B R O U T I N E =======================================
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
_menu_controls_max_val_list:
		.BYTE	$01,$03,$0C,$23

; =============== S U B R O U T I N E =======================================
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

; =============== S U B R O U T I N E =======================================
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

		TXT		$20EA,"A-BEAM  B-TRAP",	_tlm_ab_controls
		TXT		$20EA,"B-BEAM  A-TRAP",	_tlm_ba_controls

; =============== S U B R O U T I N E =======================================
_difficult_draw:
		LDX		_menu_difficulty_idx
		LDA		off_90C9,X
		LDY		off_90CD,X
		JSR		_ppu_res_send_ptr
		LDX		_menu_difficulty_idx
		LDA		off_90F9,X
		LDY		off_90FD,X
		JSR		_ppu_res_send_ptr
		LDX		_menu_difficulty_idx
		LDA		off_9115,X
		LDY		off_9119,X
		JMP		_ppu_res_send_ptr

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

		TXT		$216A,"EASY  ",	word_90D1
		TXT		$216A,"NORMAL",	word_90DB
		TXT		$216A,"HARD  ",	word_90E5
		TXT		$216A,"PRO   ",	word_90EF

off_90F9:
		.BYTE	<[word_9101]
		.BYTE	<[word_9106]
		.BYTE	<[word_910B]
		.BYTE	<[word_9110]
off_90FD:
		.BYTE	>[word_9101]
		.BYTE	>[word_9106]
		.BYTE	>[word_910B]
		.BYTE	>[word_9110]

		TXT		$21B4,"4",	word_9101
		TXT		$21B4,"3",	word_9106
		TXT		$21B4,"2",	word_910B
		TXT		$21B4,"1",	word_9110

off_9115:
		.BYTE	<[word_911D]
		.BYTE	<[word_913A]
		.BYTE	<[word_9157]
		.BYTE	<[word_9174]
off_9119:
		.BYTE	>[word_911D]
		.BYTE	>[word_913A]
		.BYTE	>[word_9157]
		.BYTE	>[word_9174]
word_911D:
		.WORD	$21F8
		.BYTE	$05,$05
		.BYTE	" 5000"
		.BYTE	"     "
		.BYTE	"20000"
		.BYTE	"     "
		.BYTE	"20000"
word_913A:
		.WORD	$21F8
		.BYTE	$05,$05
		.BYTE	"10000"
		.BYTE	"     "
		.BYTE	"30000"
		.BYTE	"     "
		.BYTE	"30000"
word_9157:
		.WORD	$21F8
		.BYTE	$05,$05
		.BYTE	"15000"
		.BYTE	"     "
		.BYTE	"40000"
		.BYTE	"     "
		.BYTE	"40000"
word_9174:
		.WORD	$21F8
		.BYTE	$05,$05
		.BYTE	"20000"
		.BYTE	"     "
		.BYTE	"50000"
		.BYTE	"     "
		.BYTE	"50000"

; =============== S U B R O U T I N E =======================================
_sound_test_mus_draw:
		LDA		_sound_test_mus_idx
		LDX		#$00
		JSR		_bin2dec
		LDX		#$07
		LDY		#$15
		JMP		_printfd

; =============== S U B R O U T I N E =======================================
_sound_test_se_draw:
		LDA		_sound_test_snd_idx
		LDX		#$00
		JSR		_bin2dec
		LDX		#$07
		LDY		#$17
		JMP		_printfd

; =============== S U B R O U T I N E =======================================
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

		SECTION_END	"SCR0 SECRET MENU CODE AND DATA"

		SECTION_START

_spr_raw_lib00:
		.WORD	_spr_raw_lib00_00
		.WORD	_spr_raw_lib00_01
		.WORD	_spr_raw_lib00_02
		.WORD	_spr_raw_lib00_03
		.WORD	_spr_raw_lib00_04
		.WORD	_spr_raw_lib00_05
		.WORD	_spr_raw_lib00_06
		.WORD	_spr_raw_lib00_07
		.WORD	_spr_raw_lib00_08
		.WORD	_spr_raw_lib00_09
		.WORD	_spr_raw_lib00_0A
		.WORD	_spr_raw_lib00_0B
		.WORD	_spr_raw_lib00_0C
		.WORD	_spr_raw_lib00_0D
		.WORD	_spr_raw_lib00_0E
		.WORD	_spr_raw_lib00_0F
		.WORD	_spr_raw_lib00_10
		.WORD	_spr_raw_lib00_11
		.WORD	_spr_raw_lib00_12
		.WORD	_spr_raw_lib00_13
		.WORD	_spr_raw_lib00_14
		.WORD	_spr_raw_lib00_15
		.WORD	_spr_raw_lib00_16
		.WORD	_spr_raw_lib00_17
		.WORD	_spr_raw_lib00_18
		.WORD	_spr_raw_lib00_19
		.WORD	_spr_raw_lib00_1A
		.WORD	_spr_raw_lib00_1B
		.WORD	_spr_raw_lib00_1C
		.WORD	_spr_raw_lib00_1D
		.WORD	_spr_raw_lib00_1E
		.WORD	_spr_raw_lib00_1F
		.WORD	_spr_raw_lib00_20
		.WORD	_spr_raw_lib00_21
		.WORD	_spr_raw_lib00_22
		.WORD	_spr_raw_lib00_23
		.WORD	_spr_raw_lib00_24
		.WORD	_spr_raw_lib00_25
		.WORD	_spr_raw_lib00_26
		.WORD	_spr_raw_lib00_27
		.WORD	_spr_raw_lib00_28
		.WORD	_spr_raw_lib00_29
		.WORD	_spr_raw_lib00_2A
		.WORD	_spr_raw_lib00_2B
		.WORD	_spr_raw_lib00_2C
		.WORD	_spr_raw_lib00_2D
		.WORD	_spr_raw_lib00_2E
		.WORD	_spr_raw_lib00_2F
		.WORD	_spr_raw_lib00_30
		.WORD	_spr_raw_lib00_31
		.WORD	_spr_raw_lib00_32
		.WORD	_spr_raw_lib00_33
		.WORD	_spr_raw_lib00_34
		.WORD	_spr_raw_lib00_35
		.WORD	_spr_raw_lib00_36
		.WORD	_spr_raw_lib00_37
		.WORD	_spr_raw_lib00_38
		.WORD	_spr_raw_lib00_39
		.WORD	_spr_raw_lib00_3A
		.WORD	_spr_raw_lib00_3B
		.WORD	_spr_raw_lib00_3C
		.WORD	_spr_raw_lib00_3D
		.WORD	_spr_raw_lib00_3E
		.WORD	_spr_raw_lib00_3F
		.WORD	_spr_raw_lib00_40
		.WORD	_spr_raw_lib00_41
		.WORD	_spr_raw_lib00_42
		.WORD	_spr_raw_lib00_43
		.WORD	_spr_raw_lib00_44
		.WORD	_spr_raw_lib00_45
		.WORD	_spr_raw_lib00_46
		.WORD	_spr_raw_lib00_47
		.WORD	_spr_raw_lib00_48
		.WORD	_spr_raw_lib00_49
		.WORD	_spr_raw_lib00_4A
		.WORD	_spr_raw_lib00_4B
		.WORD	_spr_raw_lib00_4C

		SECTION_END	"RAW LIB00 SPRITES LIST"

		SECTION_START

; =============== S C R I P T ===============================================
_scr07_ending:
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

; !FALLTRHOUGH!

; =============== S C R I P T ===============================================
		STORE8			_scr_trds_out_of_screen_test,$00	; default
		SDELAY			$5A									; delay before start
		NJSR			_nsub_mmc1_chr1_set					; setup CHR for BG
			NARGB		$09
		NJSR			_nsub_scroll_page_set				; setup NT page
			NARGB		$00
		NJSR			_nsub_far_prg0_tlm_lib_unpack		; unpack starr screen
			NARGB		_tlm7_staff_idx						; similar to title curtains
		NJSR			_nsub_full_pal_load
			NARGW		_pal_ending
		NJSR			_nsub_apu_mus_load					; misc setups.. whatever
			NARGB		$05
		SDELAY			$64									; more delay to let music begin
		SJSR			_ssub_pal_fade_in					; show screen
		POS_X_SET		0,$80,$00							; set base offset for main object
		POS_Y_SET		0,$80,$00
		NJSR			_nsub_sarg01_load_data_ofs			; load scenario data offset
			NARGW		_ending_scenario_data
_sloc_92E5:
		NJSR			_nsub_ending_scenario_data_fetch	; play it continuosly
		SJSR_SW			$04
		SCASE			_sjsr_scenario_player_sub0_thread_start
		SCASE			_sjsr_scenario_player_sub1_delay
		SCASE			_sjsr_scenario_player_sub2_text_draw
		SCASE			_sjsr_scenario_player_sub3_scores_draw
		SJMP			_sloc_92E5

; =============== S C R I P T  S U B R O U T I N E ==========================
; default option for all non-zero
_sjsr_scenario_player_sub0_thread_start:
		NJSR			_nsub_chain_thread_lib_load_enemy	; fetch and load new thread
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
; set delay for ARG*16 frames
_sjsr_scenario_player_sub1_delay:
		NJSR			_nsub_next_scenario_byte_sarg2_store; fetch byte from scenario data
		SLOOP_BEGIN		$10									; put it to SARG2
		NJSR			_nsub_obj_delay_set_from_sarg		; then write it to delay...
			NARGB		SARG2								; 16 times for every value
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_scenario_player_sub2_text_draw:
		SLOOP_BEGIN		$04									; fade out palette for window
		NJSR			_nsub_pal_fade_req_dec_by_mask		; only, keep curtains shown
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SARG_SET		SARG2,$00
		SLOOP_BEGIN		$12
		NJSR			_nsub_window_line_clear				; clear frame window line by line
		SDELAY			$01									; $18x$12 area
		SLOOP_END
		NJSR			_nsub_scenario_txt_lib_ptr_load		; fetch current screen text lib ptr
_sloc_931B:
		SDELAY			$01									; draw line by line the text until
		NJSR			_nsub_scenario_txt_lib_line_draw	; end of strings
		SBCC			_sloc_931B
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask		; fade in again to show it
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
; last finishes command, shows the final scores and wait for START to
; return to the main game.
;
_sjsr_scenario_player_sub3_scores_draw:
		SLOOP_BEGIN		$15									; long delay $15x$3C = 21 sec
		SDELAY			$3C
		SLOOP_END
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask		; fade out window
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SARG_SET		SARG2,$00							; clear window
		SLOOP_BEGIN		$12
		NJSR			_nsub_window_line_clear
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_bg_pal_load					; screen setup
			NARGW		_pal_ending_scores
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$1C
		NJSR			_nsub_ending_scores_draw			; sraw hi-scores
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask		; show screen
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		NBG_HNDL_SET	_nbgsub_ending_scores_exit			; load native bg input handler
		SUSPEND

; =============== S C R I P T ===============================================
_scr_ending_close:
		SJSR			_ssub_pal_fade_out					; fade out the screen
		STORE8			_game_flags,$00						; then set main loop flag to
		SSTOP												; jump to main entry

_pal_ending:
		.BYTE	$0F,$20,$15,$29,$0F,$20,$01,$29,$0F,$21,$11,$01,$0F,$20,$10,$00
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$37,$27,$17,$0F,$20,$10,$00
_pal_ending_scores:
		.BYTE	$0F,$20,$20,$20,$0F,$20,$20,$20,$0F,$21,$11,$01,$0F,$20,$20,$20

		MAC	ECMD_THRED
		.BYTE	{1}_idx+1,{2},{3},{4}
		ENDM

		MAC	ECMD_DELAY
		.BYTE	[_sjsr_scenario_player_sub1_delay_idx-1]|$80
		.BYTE	{1}
		ENDM

		MAC	ECMD_PRINT
		.BYTE	[_sjsr_scenario_player_sub2_text_draw_idx-1]|$80
		.WORD	{1}
		ENDM

		MAC	ECMD_WAIT
		.BYTE	[_sjsr_scenario_player_sub3_scores_draw_idx-1]|$80
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

; =============== S U B R O U T I N E =======================================
_nbgsub_ending_scores_exit:
		LDA		_pad0_pressed				; wait if START is pressed
		AND		#PAD_START
		BEQ		locret_941E
		JSR		_cur_thread_reload_param	; load another script to restart game
		.WORD	_scr_ending_close
locret_941E:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_ending_scores_draw:
		LDA		#$FF						; disable lives bonus vars
		STA		_scores_to_next_live
		STA		_scores_to_next_live+1
		LDA		_lives						; if you finish the game with more
		BEQ		loc_9436
loc_942C:
		LDA		#$64						; add 100x scores for every life
		JSR		_scores_add
		DEC		_lives
		BNE		loc_942C
loc_9436:
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
		TXT		$21E9,  "SCORE      00",	_res_score

; =============== S U B R O U T I N E =======================================
_nsub_ending_scenario_data_fetch:
		LDA		_scr_trds_args0
		STA		_ptr06
		LDA		_scr_trds_args1
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y				; any value in this script below 80 is
		BMI		loc_9484				; thread start data, fetches with sub0
		TYA								; of the player
		RTS
loc_9484:
		AND		#$7F					; any other values are other subs calls
		CLC								; sub_idx = (cmd & 0x7F) + 1
		ADC		#$01
		PHA
		INC		_scr_trds_args0
		BNE		loc_9490
		INC		_scr_trds_args1	; *--
loc_9490:
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_next_scenario_byte_sarg2_store:
		JSR		_next_scenario_byte_get
		STA		_scr_trds_args2
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_window_line_clear:
		LDA		#$20
		STA		_tmp_buf+4
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_args2,X
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
		LDX		_scr_cur_trd_idx
		INC		_scr_trds_args2,X
		RTS

; =============== S U B R O U T I N E =======================================
_next_scenario_byte_get:
		LDA		_scr_trds_args0
		STA		_ptr06
		LDA		_scr_trds_args1
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		INC		_scr_trds_args0
		BNE		locret_94CE
		INC		_scr_trds_args1
locret_94CE:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_scenario_txt_lib_ptr_load:
		JSR		_next_scenario_byte_get
		STA		_lvl_room_lib_ptr
		JSR		_next_scenario_byte_get
		STA		_lvl_room_lib_ptr+1
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_scenario_txt_lib_line_draw:
		LDY		#$00
		LDA		(_lvl_room_lib_ptr),Y
		STA		_tmp2
		INY
		LDA		(_lvl_room_lib_ptr),Y
		LDY		_tmp2
		JSR		_ppu_res_send_ptr
		LDA		_lvl_room_lib_ptr
		CLC
		ADC		#$02
		STA		_lvl_room_lib_ptr
		BCC		loc_94F3
		INC		_lvl_room_lib_ptr+1
loc_94F3:
		LDY		#$00
		LDA		(_lvl_room_lib_ptr),Y
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
; this will cause the macros error until now (tried on 2014 year build)
_res_all_test_players:
		.WORD	$20E8
		.BYTE	$11,$01
		.BYTE	"ALL TEST PLAYERS,"
		TXT		$214E,"AND",	_res_and_0
		TXT		$21AC,"YOU TOO/",	_res_you_too
		TXT		$2267,"BY HAL LABORATORY",	_res_by_hal_laboratory

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_00:
		.BYTE	$04
		.BYTE	$F0,$B0,$22,$00
		.BYTE	$F0,$A0,$22,$F8
		.BYTE	$00,$A2,$22,$F8
		.BYTE	$00,$B2,$22,$00
_spr_raw_lib07_01:
		.BYTE	$05
		.BYTE	$EF,$94,$20,$F8
		.BYTE	$F0,$90,$22,$00
		.BYTE	$F0,$80,$22,$F8
		.BYTE	$00,$82,$22,$F8
		.BYTE	$00,$92,$22,$00
_spr_raw_lib07_02:
		.BYTE	$05
		.BYTE	$F1,$94,$20,$F4
		.BYTE	$F0,$90,$22,$00
		.BYTE	$F0,$80,$22,$F8
		.BYTE	$00,$82,$22,$F8
		.BYTE	$00,$92,$22,$00
_spr_raw_lib07_03:
		.BYTE	$04
		.BYTE	$00,$D2,$62,$F8
		.BYTE	$F0,$D0,$62,$F8
		.BYTE	$00,$C2,$62,$00
		.BYTE	$F0,$C0,$62,$00
_spr_raw_lib07_04:
		.BYTE	$04
		.BYTE	$00,$D2,$62,$F8
		.BYTE	$F1,$D0,$62,$F8
		.BYTE	$00,$C2,$62,$00
		.BYTE	$F1,$C0,$62,$00
_spr_raw_lib07_05:
		.BYTE	$04
		.BYTE	$00,$F2,$22,$00
		.BYTE	$00,$E2,$22,$F8
		.BYTE	$F0,$E0,$22,$F8
		.BYTE	$F0,$F0,$22,$00
_spr_raw_lib07_06:
		.BYTE	$04
		.BYTE	$00,$F6,$22,$00
		.BYTE	$00,$E6,$22,$F8
		.BYTE	$F0,$E4,$22,$F8
		.BYTE	$F0,$F4,$22,$00

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_07:
		.BYTE	$07
		.BYTE	$D9,$84,$21,$FA
		.BYTE	$E8,$96,$23,$00
		.BYTE	$E8,$86,$23,$F8
		.BYTE	$08,$9A,$23,$00
		.BYTE	$08,$8A,$23,$F8
		.BYTE	$F8,$98,$23,$00
		.BYTE	$F8,$88,$23,$F8
_spr_raw_lib07_08:
		.BYTE	$07
		.BYTE	$D7,$B4,$21,$FA
		.BYTE	$E7,$B6,$23,$00
		.BYTE	$E7,$A6,$23,$F8
		.BYTE	$07,$BA,$23,$00
		.BYTE	$07,$AA,$23,$F8
		.BYTE	$F7,$B8,$23,$00
		.BYTE	$F7,$A8,$23,$F8
_spr_raw_lib07_09:
		.BYTE	$07
		.BYTE	$D9,$84,$61,$FB
		.BYTE	$E8,$96,$23,$00
		.BYTE	$E8,$86,$23,$F8
		.BYTE	$08,$DA,$23,$00
		.BYTE	$08,$CA,$23,$F8
		.BYTE	$F8,$98,$23,$00
		.BYTE	$F8,$88,$23,$F8
_spr_raw_lib07_0A:
		.BYTE	$07
		.BYTE	$D8,$84,$01,$F7
		.BYTE	$08,$D8,$03,$00
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$E8,$C4,$03,$F8
_spr_raw_lib07_0C:
		.BYTE	$07
		.BYTE	$D8,$84,$41,$F8
		.BYTE	$08,$D8,$03,$00
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$E8,$C4,$03,$F8
_spr_raw_lib07_0B:
		.BYTE	$07
		.BYTE	$D8,$B4,$01,$F7
		.BYTE	$08,$D8,$03,$00
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$E8,$C4,$03,$F8
_spr_raw_lib07_0D:
		.BYTE	$07
		.BYTE	$D7,$B4,$41,$F8
		.BYTE	$08,$D8,$03,$00
		.BYTE	$08,$C8,$03,$F8
		.BYTE	$F8,$C6,$03,$F8
		.BYTE	$F8,$D6,$03,$00
		.BYTE	$E8,$D4,$03,$00
		.BYTE	$E8,$C4,$03,$F8

; =============== S C R I P T ===============================================
_scr_ending_sub03:
		NJSR			_nsub_pal_patch_fade
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

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_0E:
		.BYTE	$06
		.BYTE	$F8,$E8,$60,$F2
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
_spr_raw_lib07_0F:
		.BYTE	$06
		.BYTE	$F8,$E6,$60,$F2
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
_spr_raw_lib07_10:
		.BYTE	$08
		.BYTE	$EF,$58,$60,$F3
		.BYTE	$02,$58,$60,$EF
		.BYTE	$F8,$E6,$60,$F2
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
_spr_raw_lib07_11:
		.BYTE	$08
		.BYTE	$EF,$48,$60,$F3
		.BYTE	$02,$48,$60,$EF
		.BYTE	$F8,$E8,$60,$F2
		.BYTE	$F8,$D8,$60,$FA
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$EA,$62,$00
		.BYTE	$F0,$FA,$62,$F8
_spr_raw_lib07_12:
		.BYTE	$06
		.BYTE	$EE,$E8,$60,$F3
		.BYTE	$EE,$D8,$60,$FB
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$CA,$62,$00
		.BYTE	$F0,$DA,$62,$F8
_spr_raw_lib07_13:
		.BYTE	$06
		.BYTE	$EE,$E6,$60,$F3
		.BYTE	$EE,$D6,$60,$FB
		.BYTE	$00,$CC,$62,$00
		.BYTE	$00,$DC,$62,$F8
		.BYTE	$F0,$CA,$62,$00
		.BYTE	$F0,$DA,$62,$F8

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_50:
		.BYTE	$04
		.BYTE	$01,$4E,$60,$00
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$F4,$08,$60,$00
		.BYTE	$F4,$08,$20,$F8
_spr_raw_lib07_51:
		.BYTE	$04
		.BYTE	$01,$4E,$60,$00
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$F5,$08,$60,$00
		.BYTE	$F5,$08,$20,$F8
_spr_raw_lib07_52:
		.BYTE	$04
		.BYTE	$01,$4E,$60,$00
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$F4,$00,$60,$00
		.BYTE	$F4,$10,$60,$F8

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_53:
		.BYTE	$04
		.BYTE	$01,$4E,$60,$00
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$F4,$0A,$60,$00
		.BYTE	$F4,$0A,$20,$F8
_spr_raw_lib07_54:
		.BYTE	$04
		.BYTE	$01,$4E,$60,$00
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$F5,$0A,$60,$00
		.BYTE	$F5,$0A,$20,$F8
_spr_raw_lib07_55:
		.BYTE	$04
		.BYTE	$01,$4E,$60,$00
		.BYTE	$01,$4E,$20,$F8
		.BYTE	$F4,$12,$20,$00
		.BYTE	$F4,$02,$20,$F8

; =============== S C R I P T ===============================================
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

; =============== S C R I P T  S U B R O U T I N E ==========================
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

_spr_raw_lib07_56:
		.BYTE	$04
		.BYTE	$FF,$9C,$62,$F8
		.BYTE	$FF,$8C,$62,$00
		.BYTE	$EF,$A8,$62,$00
		.BYTE	$EF,$B8,$62,$F8
_spr_raw_lib07_57:
		.BYTE	$04
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$00,$AC,$62,$00
		.BYTE	$F0,$AA,$62,$00
		.BYTE	$F0,$B8,$62,$F8
_spr_raw_lib07_58:
		.BYTE	$04
		.BYTE	$FF,$9C,$22,$00
		.BYTE	$FF,$8C,$22,$F8
		.BYTE	$EF,$BA,$62,$F8
		.BYTE	$EF,$AA,$62,$00
_spr_raw_lib07_59:
		.BYTE	$04
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$00,$AC,$62,$00
		.BYTE	$F0,$AA,$62,$00
		.BYTE	$F0,$BA,$62,$F8
_spr_raw_lib07_5A:
		.BYTE	$04
		.BYTE	$FF,$9C,$22,$00
		.BYTE	$FF,$8C,$22,$F8
		.BYTE	$EF,$A8,$22,$F8
		.BYTE	$EF,$B8,$22,$00
_spr_raw_lib07_5B:
		.BYTE	$04
		.BYTE	$00,$AC,$62,$00
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$F0,$AA,$22,$F8
		.BYTE	$F0,$B8,$22,$00
_spr_raw_lib07_5C:
		.BYTE	$04
		.BYTE	$FF,$9C,$62,$F8
		.BYTE	$FF,$8C,$62,$00
		.BYTE	$EF,$BA,$22,$00
		.BYTE	$EF,$AA,$22,$F8
_spr_raw_lib07_5D:
		.BYTE	$04
		.BYTE	$00,$AC,$62,$00
		.BYTE	$00,$AC,$22,$F8
		.BYTE	$F0,$AA,$22,$F8
		.BYTE	$F0,$BA,$22,$00

; =============== S C R I P T ===============================================
_scr_ending_sub08:
		NJSR			_nsub_pal_patch_fade
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

; =============== S C R I P T  S U B R O U T I N E ==========================
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

_spr_res_lib07_00:
		.BYTE	$01
		.WORD	_spr_res_lib07_00_A
_spr_res_lib07_01:
		.BYTE	$01
		.WORD	_spr_res_lib07_01_A
_spr_res_lib07_02:
		.BYTE	$01
		.WORD	_spr_res_lib07_02_A
_spr_res_lib07_03:
		.BYTE	$01
		.WORD	_spr_res_lib07_03_A
_spr_res_lib07_04:
		.BYTE	$01
		.WORD	_spr_res_lib07_04_A
_spr_res_lib07_05:
		.BYTE	$01
		.WORD	_spr_res_lib07_05_A
_spr_res_lib07_06:
		.BYTE	$01
		.WORD	_spr_res_lib07_06_A
_spr_res_lib07_07:
		.BYTE	$01
		.WORD	_spr_res_lib07_07_A
_spr_res_lib07_08:
		.BYTE	$01
		.WORD	_spr_res_lib07_08_A
_spr_res_lib07_09:
		.BYTE	$01
		.WORD	_spr_res_lib07_09_A
_spr_res_lib07_0A:
		.BYTE	$01
		.WORD	_spr_res_lib07_0A_A
_spr_res_lib07_0B:
		.BYTE	$01
		.WORD	_spr_res_lib07_0B_A
_spr_res_lib07_0C:
		.BYTE	$01
		.WORD	_spr_res_lib07_0C_A
_spr_res_lib07_0D:
		.BYTE	$01
		.WORD	_spr_res_lib07_0D_A
_spr_res_lib07_0E:
		.BYTE	$01
		.WORD	_spr_res_lib07_0E_A
_spr_res_lib07_0F:
		.BYTE	$01
		.WORD	_spr_res_lib07_0F_A
_spr_res_lib07_10:
		.BYTE	$01
		.WORD	_spr_res_lib07_10_A
_spr_res_lib07_11:
		.BYTE	$01
		.WORD	_spr_res_lib07_11_A
_spr_res_lib07_12:
		.BYTE	$01
		.WORD	_spr_res_lib07_12_A
_spr_res_lib07_00_A:
		.BYTE	$09
		.BYTE	$CE,$FC,$23,$F8
		.BYTE	$CE,$EC,$23,$F0
		.BYTE	$DC,$C8,$23,$F4
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$C2,$23,$04
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$F8,$E2,$23,$FC
_spr_res_lib07_01_A:
		.BYTE	$0A
		.BYTE	$D4,$FC,$23,$09
		.BYTE	$D4,$EC,$23,$01
		.BYTE	$DD,$DC,$23,$00
		.BYTE	$DD,$CC,$23,$F8
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$C2,$23,$04
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$F8,$E2,$23,$FC
_spr_res_lib07_02_A:
		.BYTE	$0A
		.BYTE	$E4,$FC,$23,$0A
		.BYTE	$E4,$EC,$23,$02
		.BYTE	$E8,$CA,$23,$FF
		.BYTE	$E8,$CA,$23,$F7
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F8,$F6,$23,$04
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$F8,$E6,$23,$FC
_spr_res_lib07_03_A:
		.BYTE	$0A
		.BYTE	$F4,$FC,$23,$09
		.BYTE	$F4,$EC,$23,$01
		.BYTE	$F5,$DC,$63,$FF
		.BYTE	$E4,$CC,$63,$F8
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F8,$F6,$23,$04
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$F8,$E6,$23,$FC
_spr_res_lib07_04_A:
		.BYTE	$09
		.BYTE	$FB,$FC,$23,$F9
		.BYTE	$FB,$EC,$23,$F1
		.BYTE	$EF,$C8,$23,$F5
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$C2,$23,$04
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$F8,$E2,$23,$FC
_spr_res_lib07_05_A:
		.BYTE	$0A
		.BYTE	$F6,$FC,$23,$E8
		.BYTE	$F6,$EC,$23,$E0
		.BYTE	$EE,$CC,$23,$E9
		.BYTE	$EE,$DC,$23,$F1
		.BYTE	$F8,$D2,$23,$F4
		.BYTE	$F8,$C6,$23,$04
		.BYTE	$E8,$F0,$23,$04
		.BYTE	$E8,$D0,$23,$F4
		.BYTE	$E8,$E0,$23,$FC
		.BYTE	$F8,$E2,$23,$FC
_spr_res_lib07_06_A:
		.BYTE	$0A
		.BYTE	$E6,$EC,$23,$DF
		.BYTE	$E6,$FC,$23,$E7
		.BYTE	$EA,$CA,$63,$E8
		.BYTE	$EA,$CA,$23,$EE
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F8,$F6,$23,$04
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$F8,$E6,$23,$FC
_spr_res_lib07_07_A:
		.BYTE	$0A
		.BYTE	$D7,$EC,$23,$E0
		.BYTE	$D7,$FC,$23,$E8
		.BYTE	$DD,$DC,$63,$E7
		.BYTE	$DD,$CC,$63,$EF
		.BYTE	$E8,$F4,$23,$04
		.BYTE	$F8,$F6,$23,$04
		.BYTE	$F8,$C4,$23,$F4
		.BYTE	$E8,$D4,$23,$F4
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$F8,$E6,$23,$FC
_spr_res_lib07_08_A:
		.BYTE	$09
		.BYTE	$09,$FC,$23,$F7
		.BYTE	$09,$EC,$23,$EF
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_09_A:
		.BYTE	$0A
		.BYTE	$1B,$FC,$23,$F7
		.BYTE	$1B,$EC,$23,$EF
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_0A_A:
		.BYTE	$0B
		.BYTE	$2C,$FC,$23,$F8
		.BYTE	$2C,$EC,$23,$F0
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_0B_A:
		.BYTE	$0C
		.BYTE	$3C,$FC,$23,$F8
		.BYTE	$3C,$EC,$23,$F0
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_0C_A:
		.BYTE	$0D
		.BYTE	$4D,$FC,$23,$F8
		.BYTE	$4D,$EC,$23,$F0
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_0D_A:
		.BYTE	$0E
		.BYTE	$5C,$FC,$23,$F8
		.BYTE	$5C,$EC,$23,$F0
		.BYTE	$4E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_0E_A:
		.BYTE	$10
		.BYTE	$D7,$EC,$63,$F8
		.BYTE	$D7,$EC,$23,$F0
		.BYTE	$C8,$C8,$23,$F3
		.BYTE	$5E,$C8,$23,$F3
		.BYTE	$4E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_0F_A:
		.BYTE	$14
		.BYTE	$EF,$48,$23,$EB
		.BYTE	$E3,$48,$23,$FC
		.BYTE	$BB,$C8,$23,$F4
		.BYTE	$E4,$EC,$63,$F7
		.BYTE	$E4,$EC,$23,$EF
		.BYTE	$D8,$C8,$23,$F3
		.BYTE	$C8,$C8,$23,$F3
		.BYTE	$5E,$C8,$23,$F3
		.BYTE	$4E,$C8,$23,$F3
		.BYTE	$3E,$C8,$23,$F3
		.BYTE	$2E,$C8,$23,$F3
		.BYTE	$1E,$C8,$23,$F3
		.BYTE	$0E,$C8,$23,$F3
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E8,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC
_spr_res_lib07_10_A:
		.BYTE	$14
		.BYTE	$F8,$58,$23,$EC
		.BYTE	$E5,$58,$23,$FE
		.BYTE	$C0,$C8,$23,$F4
		.BYTE	$E9,$EC,$63,$F7
		.BYTE	$E9,$EC,$23,$EF
		.BYTE	$DD,$C8,$23,$F3
		.BYTE	$CD,$C8,$23,$F3
		.BYTE	$63,$C8,$23,$F3
		.BYTE	$53,$C8,$23,$F3
		.BYTE	$43,$C8,$23,$F3
		.BYTE	$33,$C8,$23,$F3
		.BYTE	$23,$C8,$23,$F3
		.BYTE	$13,$C8,$23,$F3
		.BYTE	$03,$C8,$23,$F3
		.BYTE	$FD,$FA,$23,$04
		.BYTE	$ED,$F8,$23,$04
		.BYTE	$ED,$E4,$23,$FC
		.BYTE	$ED,$D8,$23,$F4
		.BYTE	$FD,$DA,$23,$F4
		.BYTE	$FD,$EA,$23,$FC
_spr_res_lib07_11_A:
		.BYTE	$12
		.BYTE	$C0,$C8,$23,$F4
		.BYTE	$E9,$EC,$63,$F7
		.BYTE	$E9,$EC,$23,$EF
		.BYTE	$DD,$C8,$23,$F3
		.BYTE	$CD,$C8,$23,$F3
		.BYTE	$63,$C8,$23,$F3
		.BYTE	$53,$C8,$23,$F3
		.BYTE	$43,$C8,$23,$F3
		.BYTE	$33,$C8,$23,$F3
		.BYTE	$23,$C8,$23,$F3
		.BYTE	$13,$C8,$23,$F3
		.BYTE	$03,$C8,$23,$F3
		.BYTE	$FD,$FA,$23,$04
		.BYTE	$ED,$F8,$23,$04
		.BYTE	$ED,$E8,$23,$FC
		.BYTE	$ED,$D8,$23,$F4
		.BYTE	$FD,$DA,$23,$F4
		.BYTE	$FD,$EA,$23,$FC
_spr_res_lib07_12_A:
		.BYTE	$09
		.BYTE	$09,$FC,$23,$F7
		.BYTE	$09,$EC,$23,$EF
		.BYTE	$FE,$C8,$23,$F3
		.BYTE	$F8,$FA,$23,$04
		.BYTE	$E8,$F8,$23,$04
		.BYTE	$E8,$E4,$23,$FC
		.BYTE	$E8,$D8,$23,$F4
		.BYTE	$F8,$DA,$23,$F4
		.BYTE	$F8,$EA,$23,$FC

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_5E:
		.BYTE	$04
		.BYTE	$E8,$1C,$60,$00
		.BYTE	$E8,$1C,$20,$F8
		.BYTE	$F5,$5E,$23,$00
		.BYTE	$F5,$5E,$23,$FB

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_5F:
		.BYTE	$04
		.BYTE	$E8,$1E,$60,$00
		.BYTE	$E8,$1E,$20,$F8
		.BYTE	$F5,$5E,$63,$F8
		.BYTE	$F5,$5E,$23,$00

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_60:
		.BYTE	$05
		.BYTE	$00,$BA,$23,$F0
		.BYTE	$00,$B6,$23,$00
		.BYTE	$F0,$B4,$23,$00
		.BYTE	$F0,$A4,$23,$F8
		.BYTE	$00,$A6,$23,$F8
_spr_raw_lib07_61:
		.BYTE	$05
		.BYTE	$F0,$BC,$23,$F0
		.BYTE	$00,$96,$23,$00
		.BYTE	$00,$86,$23,$F8
		.BYTE	$F0,$94,$23,$00
		.BYTE	$F0,$84,$23,$F8
_spr_raw_lib07_62:
		.BYTE	$05
		.BYTE	$00,$BA,$63,$08
		.BYTE	$00,$B6,$63,$F8
		.BYTE	$F0,$B4,$63,$F8
		.BYTE	$F0,$A4,$63,$00
		.BYTE	$00,$A6,$63,$00
_spr_raw_lib07_63:
		.BYTE	$05
		.BYTE	$F0,$BC,$63,$08
		.BYTE	$00,$96,$63,$F8
		.BYTE	$00,$86,$63,$00
		.BYTE	$F0,$94,$63,$F8
		.BYTE	$F0,$84,$63,$00
_spr_raw_lib07_64:
		.BYTE	$05
		.BYTE	$F0,$25,$23,$00
		.BYTE	$F0,$23,$23,$F8
		.BYTE	$F0,$9C,$23,$F0
		.BYTE	$00,$96,$23,$00
		.BYTE	$00,$86,$23,$F8
_spr_raw_lib07_65:
		.BYTE	$05
		.BYTE	$00,$BA,$23,$F0
		.BYTE	$00,$A6,$23,$F8
		.BYTE	$00,$B6,$23,$00
		.BYTE	$F0,$29,$23,$00
		.BYTE	$F0,$27,$23,$F8
_spr_raw_lib07_66:
		.BYTE	$05
		.BYTE	$F0,$25,$63,$F8
		.BYTE	$F0,$23,$63,$00
		.BYTE	$F0,$9C,$63,$08
		.BYTE	$00,$96,$63,$F8
		.BYTE	$00,$86,$63,$00
_spr_raw_lib07_67:
		.BYTE	$05
		.BYTE	$00,$BA,$63,$08
		.BYTE	$00,$A6,$63,$00
		.BYTE	$00,$B6,$63,$F8
		.BYTE	$F0,$29,$63,$F8
		.BYTE	$F0,$27,$63,$00
_spr_raw_lib07_68:
		.BYTE	$04
		.BYTE	$00,$B2,$23,$00
		.BYTE	$00,$A2,$23,$F8
		.BYTE	$F0,$3D,$23,$00
		.BYTE	$F0,$3B,$23,$F8

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_69:
		.BYTE	$02
		.BYTE	$F8,$BB,$23,$00
		.BYTE	$F8,$AB,$23,$F8

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_6A:
		.BYTE	$04
		.BYTE	$F0,$4A,$20,$F8
		.BYTE	$F0,$5A,$20,$00
		.BYTE	$E0,$30,$20,$00
		.BYTE	$E0,$20,$20,$F8
_spr_raw_lib07_6B:
		.BYTE	$04
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F2,$20,$20,$F8
		.BYTE	$F2,$30,$20,$00
_spr_raw_lib07_6C:
		.BYTE	$06
		.BYTE	$F9,$BB,$23,$00
		.BYTE	$F9,$AB,$23,$F8
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$22,$60,$00
		.BYTE	$F0,$22,$20,$F8
_spr_raw_lib07_6D:
		.BYTE	$06
		.BYTE	$F8,$BB,$23,$0B
		.BYTE	$F8,$AB,$23,$03
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$20,$60,$00
		.BYTE	$F0,$30,$60,$F8
_spr_raw_lib07_6E:
		.BYTE	$06
		.BYTE	$F9,$BB,$23,$0C
		.BYTE	$F9,$AB,$23,$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$F1,$30,$60,$F8
		.BYTE	$F1,$20,$60,$00
		.BYTE	$00,$2A,$60,$00
_spr_raw_lib07_6F:
		.BYTE	$06
		.BYTE	$F9,$BB,$23,$0C
		.BYTE	$F9,$AB,$23,$04
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$30,$60,$F8
		.BYTE	$F1,$20,$60,$00
		.BYTE	$00,$2A,$20,$F8
_spr_raw_lib07_70:
		.BYTE	$06
		.BYTE	$F8,$BB,$63,$ED
		.BYTE	$F8,$AB,$63,$F5
		.BYTE	$00,$28,$20,$F8
		.BYTE	$00,$38,$20,$00
		.BYTE	$F0,$20,$20,$F8
		.BYTE	$F0,$30,$20,$00

; =============== S C R I P T ===============================================
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
		NJSR			_nsub_pal_patch_fade
			NARGB		$03
			NARGW		byte_A547
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$D0
		SDELAY			$04
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nsub_ending_logo_attr_load:
		JSR		_ppu_res_send_param
		.WORD	_attr_ending_logo
		RTS

_attr_ending_logo:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$FA,$FA,$FA,$FA,$FA,$FA,$AA,$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA,$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A

_tlm_ending_logo:
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$5D,$79,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$83,$93,$A3,$B3,$C3,$D3,$E3,$F3,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$74,$84,$94,$A4,$B3,$C3,$D4,$E4,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$55,$65,$75,$85,$95,$A5,$B5,$C5,$D5,$E5,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$56,$EE,$76,$86,$96,$A6,$B6,$C6,$D6,$E6,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$47,$57,$67,$77,$87,$97,$EE,$B6,$C7,$D7,$E7,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$48,$58,$68,$78,$EE,$97,$EE,$B8,$C8,$D8,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$49,$59,$69,$EE,$89,$99,$A9,$B9,$C9,$D9,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$4A,$5A,$6A,$89,$8A,$EF,$AA,$BA,$CA,$DA,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$4B,$5B,$6B,$7B,$EF,$9B,$EE,$BB,$CB,$DB,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$2F,$EF,$46,$EF,$9B,$EE,$EE,$4C,$5C,$DC,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$3F,$EF,$EF,$37,$A8,$AB,$EE,$4D,$EF,$DD,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$73,$EF,$9A,$E8,$F8,$DE,$4E,$5E,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$66,$8B,$E9,$F9,$DF,$4F,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE
		.BYTE	$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE,$FE

; =============== S C R I P T ===============================================
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

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_B0:
		.BYTE	$04
		.BYTE	$F0,$92,$40,$F8
		.BYTE	$00,$38,$40,$F8
		.BYTE	$00,$28,$40,$00
		.BYTE	$F0,$82,$40,$00
_spr_raw_lib07_B1:
		.BYTE	$04
		.BYTE	$00,$94,$40,$F8
		.BYTE	$00,$84,$40,$00
		.BYTE	$F1,$82,$40,$00
		.BYTE	$F1,$92,$40,$F8
_spr_raw_lib07_B2:
		.BYTE	$04
		.BYTE	$00,$94,$00,$00
		.BYTE	$00,$84,$00,$F8
		.BYTE	$F1,$82,$40,$00
		.BYTE	$F1,$92,$40,$F8
_spr_raw_lib07_AD:
		.BYTE	$04
		.BYTE	$F0,$92,$00,$00
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$82,$00,$F8
_spr_raw_lib07_AE:
		.BYTE	$04
		.BYTE	$00,$94,$00,$00
		.BYTE	$00,$84,$00,$F8
		.BYTE	$F1,$82,$00,$F8
		.BYTE	$F1,$92,$00,$00
_spr_raw_lib07_AF:
		.BYTE	$04
		.BYTE	$00,$94,$40,$F8
		.BYTE	$00,$84,$40,$00
		.BYTE	$F1,$82,$00,$F8
		.BYTE	$F1,$92,$00,$00

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_B3:
		.BYTE	$01
		.BYTE	$FC,$6E,$41,$FD

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_B4:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$F0,$0A,$40,$00
		.BYTE	$F0,$0A,$00,$F8

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_B5:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$0C,$00,$F8
		.BYTE	$F0,$0C,$40,$00

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_B6:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$F0,$0E,$00,$F8
		.BYTE	$F0,$0E,$40,$00

; =============== S C R I P T ===============================================
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

_spr_raw_lib07_B7:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$22,$40,$00
		.BYTE	$F0,$22,$00,$F8
_spr_raw_lib07_B8:
		.BYTE	$04
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$F8,$4C,$C0,$00
		.BYTE	$F8,$4C,$80,$F8
_spr_raw_lib07_B9:
		.BYTE	$06
		.BYTE	$F1,$48,$80,$F3
		.BYTE	$F0,$48,$80,$06
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$F8,$4C,$C0,$00
		.BYTE	$F8,$4C,$80,$F8
_spr_raw_lib07_BA:
		.BYTE	$06
		.BYTE	$EC,$58,$80,$F1
		.BYTE	$ED,$58,$80,$08
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$F8,$4C,$C0,$00
		.BYTE	$F8,$4C,$80,$F8
_spr_raw_lib07_BB:
		.BYTE	$06
		.BYTE	$EA,$48,$80,$F0
		.BYTE	$EA,$48,$80,$09
		.BYTE	$E8,$4E,$80,$F8
		.BYTE	$E8,$4E,$C0,$00
		.BYTE	$F8,$4C,$C0,$00
		.BYTE	$F8,$4C,$80,$F8

; =============== S C R I P T ===============================================
_scr_ending_sub15:
		SPR_IDX_SET		0,$BC
_sloc_A784:
		SARG_SET		SARG0,$00
		SLOOP_BEGIN		$0C
		NJSR			_nsub_end_spr_pal_anim
		SDELAY			$01
		SLOOP_END
		SJMP			_sloc_A784

; =============== S U B R O U T I N E =======================================
_nsub_end_spr_pal_anim:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		INC		_scr_trds_args0,X
		ASL
		ASL
		ADC		#<[byte_A7A8]
		PHA
		LDA		#$00
		ADC		#>[byte_A7A8]
		TAX
		PLA
		LDY		#$07
		JMP		_pal_patch_fade
byte_A7A8:
		.BYTE	$0F,$31,$0F,$35,$0F,$31,$0F,$25,$0F,$31,$00,$15,$0F,$31,$00,$05
		.BYTE	$0F,$31,$10,$15,$0F,$31,$10,$25,$0F,$31,$20,$35,$0F,$31,$20,$25
		.BYTE	$0F,$31,$10,$15,$0F,$31,$10,$05,$0F,$31,$00,$15,$0F,$31,$00,$25

_spr_raw_lib07_BC:
		.BYTE	$0C
		.BYTE	$00,$BE,$03,$00
		.BYTE	$00,$AE,$03,$F8
		.BYTE	$F0,$BC,$03,$00
		.BYTE	$F0,$AC,$03,$F8
		.BYTE	$F0,$88,$03,$10
		.BYTE	$00,$8A,$03,$10
		.BYTE	$00,$9A,$03,$18
		.BYTE	$F0,$98,$03,$18
		.BYTE	$F0,$9C,$03,$E8
		.BYTE	$00,$9E,$03,$E8
		.BYTE	$00,$8E,$03,$E0
		.BYTE	$F0,$8C,$03,$E0
; NOTE: here is the rest of ending sprites, many of them copy the regular players
; sprites and may of them not used in the ending at all...
;
_spr_raw_lib07_14:
		.BYTE	$04		; *--
		.BYTE	$00,$36,$20,$00	; *--
		.BYTE	$00,$26,$20,$F8	; *--
		.BYTE	$F0,$18,$60,$00	; *--
		.BYTE	$F0,$18,$20,$F8	; *--
_spr_raw_lib07_15:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$18,$60,$00	; *--
		.BYTE	$F1,$18,$20,$F8	; *--
_spr_raw_lib07_16:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$18,$60,$00	; *--
		.BYTE	$F1,$18,$20,$F8	; *--
_spr_raw_lib07_17:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$10,$60,$F8
		.BYTE	$F0,$00,$60,$00
_spr_raw_lib07_18:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$10,$60,$F8
		.BYTE	$F1,$00,$60,$00
_spr_raw_lib07_19:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$10,$60,$F8
		.BYTE	$F1,$00,$60,$00
_spr_raw_lib07_1A:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$08,$60,$00
		.BYTE	$F0,$08,$20,$F8
_spr_raw_lib07_1B:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$08,$60,$00	; *--
		.BYTE	$F1,$08,$20,$F8	; *--
_spr_raw_lib07_1C:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$08,$60,$00	; *--
		.BYTE	$F1,$08,$20,$F8	; *--
_spr_raw_lib07_1D:
		.BYTE	$04
		.BYTE	$00,$38,$20,$00
		.BYTE	$00,$28,$20,$F8
		.BYTE	$F0,$10,$20,$00
		.BYTE	$F0,$00,$20,$F8
_spr_raw_lib07_1E:
		.BYTE	$04
		.BYTE	$00,$3A,$20,$00
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$F1,$10,$20,$00
		.BYTE	$F1,$00,$20,$F8
_spr_raw_lib07_1F:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$10,$20,$00
		.BYTE	$F1,$00,$20,$F8
_spr_raw_lib07_20:
		.BYTE	$04		; *--
		.BYTE	$00,$36,$20,$00	; *--
		.BYTE	$00,$26,$20,$F8	; *--
		.BYTE	$F0,$1A,$60,$00	; *--
		.BYTE	$F0,$1A,$20,$F8	; *--
_spr_raw_lib07_21:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$1A,$60,$00	; *--
		.BYTE	$F1,$1A,$20,$F8	; *--
_spr_raw_lib07_22:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$1A,$60,$00	; *--
		.BYTE	$F1,$1A,$20,$F8	; *--
_spr_raw_lib07_23:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$12,$60,$F8
		.BYTE	$F0,$02,$60,$00
_spr_raw_lib07_24:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$12,$60,$F8
		.BYTE	$F1,$02,$60,$00
_spr_raw_lib07_25:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$12,$60,$F8
		.BYTE	$F1,$02,$60,$00
_spr_raw_lib07_26:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$0A,$60,$00
		.BYTE	$F0,$0A,$20,$F8
_spr_raw_lib07_27:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$0A,$60,$00	; *--
		.BYTE	$F1,$0A,$20,$F8	; *--
_spr_raw_lib07_28:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$0A,$60,$00	; *--
		.BYTE	$F1,$0A,$20,$F8	; *--
_spr_raw_lib07_29:
		.BYTE	$04
		.BYTE	$00,$38,$20,$00
		.BYTE	$00,$28,$20,$F8
		.BYTE	$F0,$12,$20,$00
		.BYTE	$F0,$02,$20,$F8
_spr_raw_lib07_2A:
		.BYTE	$04
		.BYTE	$00,$3A,$20,$00
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$F1,$12,$20,$00
		.BYTE	$F1,$02,$20,$F8
_spr_raw_lib07_2B:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$12,$20,$00
		.BYTE	$F1,$02,$20,$F8
_spr_raw_lib07_2C:
		.BYTE	$04
		.BYTE	$00,$36,$20,$00
		.BYTE	$00,$26,$20,$F8
		.BYTE	$F0,$1C,$60,$00
		.BYTE	$F0,$1C,$20,$F8
_spr_raw_lib07_2D:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$1C,$60,$00	; *--
		.BYTE	$F1,$1C,$20,$F8	; *--
_spr_raw_lib07_2E:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$1C,$60,$00	; *--
		.BYTE	$F1,$1C,$20,$F8	; *--
_spr_raw_lib07_2F:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$14,$60,$F8
		.BYTE	$F0,$04,$60,$00
_spr_raw_lib07_30:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$14,$60,$F8
		.BYTE	$F1,$04,$60,$00
_spr_raw_lib07_31:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$14,$60,$F8
		.BYTE	$F1,$04,$60,$00
_spr_raw_lib07_32:
		.BYTE	$04		; *--
		.BYTE	$00,$26,$20,$F8	; *--
		.BYTE	$00,$36,$20,$00	; *--
		.BYTE	$F0,$0C,$60,$00	; *--
		.BYTE	$F0,$0C,$20,$F8	; *--
_spr_raw_lib07_33:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$0C,$60,$00	; *--
		.BYTE	$F1,$0C,$20,$F8	; *--
_spr_raw_lib07_34:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$0C,$60,$00	; *--
		.BYTE	$F1,$0C,$20,$F8	; *--
_spr_raw_lib07_35:
		.BYTE	$04
		.BYTE	$00,$38,$20,$00
		.BYTE	$00,$28,$20,$F8
		.BYTE	$F0,$14,$20,$00
		.BYTE	$F0,$04,$20,$F8
_spr_raw_lib07_36:
		.BYTE	$04
		.BYTE	$00,$3A,$20,$00
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$F1,$14,$20,$00
		.BYTE	$F1,$04,$20,$F8
_spr_raw_lib07_37:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$14,$20,$00
		.BYTE	$F1,$04,$20,$F8
_spr_raw_lib07_38:
		.BYTE	$04
		.BYTE	$00,$36,$20,$00
		.BYTE	$00,$26,$20,$F8
		.BYTE	$F0,$1E,$60,$00
		.BYTE	$F0,$1E,$20,$F8
_spr_raw_lib07_39:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$1E,$60,$00	; *--
		.BYTE	$F1,$1E,$20,$F8	; *--
_spr_raw_lib07_3A:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$1E,$60,$00	; *--
		.BYTE	$F1,$1E,$20,$F8	; *--
_spr_raw_lib07_3B:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$16,$60,$F8
		.BYTE	$F0,$06,$60,$00
_spr_raw_lib07_3C:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$16,$60,$F8
		.BYTE	$F1,$06,$60,$00
_spr_raw_lib07_3D:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$16,$60,$F8
		.BYTE	$F1,$06,$60,$00
_spr_raw_lib07_3E:
		.BYTE	$04		; *--
		.BYTE	$00,$26,$20,$F8	; *--
		.BYTE	$00,$36,$20,$00	; *--
		.BYTE	$F0,$0E,$60,$00	; *--
		.BYTE	$F0,$0E,$20,$F8	; *--
_spr_raw_lib07_3F:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$0E,$60,$00	; *--
		.BYTE	$F1,$0E,$20,$F8	; *--
_spr_raw_lib07_40:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$0E,$60,$00	; *--
byte_AB02:
		.BYTE	$F1,$0E,$20,$F8	; *--
_spr_raw_lib07_41:
		.BYTE	$04
		.BYTE	$00,$38,$20,$00
		.BYTE	$00,$28,$20,$F8
		.BYTE	$F0,$16,$20,$00
		.BYTE	$F0,$06,$20,$F8
_spr_raw_lib07_42:
		.BYTE	$04
		.BYTE	$00,$3A,$20,$00
		.BYTE	$00,$2A,$20,$F8
byte_AB20:
		.BYTE	$F1,$16,$20,$00
		.BYTE	$F1,$06,$20,$F8
_spr_raw_lib07_43:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$16,$20,$00
		.BYTE	$F1,$06,$20,$F8
_spr_raw_lib07_44:
		.BYTE	$04		; *--
		.BYTE	$00,$36,$20,$00	; *--
		.BYTE	$00,$26,$20,$F8	; *--
		.BYTE	$F0,$32,$60,$00	; *--
		.BYTE	$F0,$32,$20,$F8	; *--
_spr_raw_lib07_45:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$32,$60,$00	; *--
		.BYTE	$F1,$32,$20,$F8	; *--
_spr_raw_lib07_46:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$32,$60,$00	; *--
		.BYTE	$F1,$32,$20,$F8	; *--
_spr_raw_lib07_47:
		.BYTE	$04
		.BYTE	$00,$28,$60,$00
		.BYTE	$00,$38,$60,$F8
		.BYTE	$F0,$30,$60,$F8
		.BYTE	$F0,$20,$60,$00
_spr_raw_lib07_48:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$30,$60,$F8
		.BYTE	$F1,$20,$60,$00
_spr_raw_lib07_49:
		.BYTE	$04
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$00,$3A,$20,$00
		.BYTE	$F1,$30,$60,$F8
		.BYTE	$F1,$20,$60,$00
_spr_raw_lib07_4A:
		.BYTE	$04
		.BYTE	$00,$26,$20,$F8
		.BYTE	$00,$36,$20,$00
		.BYTE	$F0,$22,$60,$00
		.BYTE	$F0,$22,$20,$F8
_spr_raw_lib07_4B:
		.BYTE	$04		; *--
		.BYTE	$00,$24,$20,$F8	; *--
		.BYTE	$00,$34,$20,$00	; *--
		.BYTE	$F1,$22,$60,$00	; *--
		.BYTE	$F1,$22,$20,$F8	; *--
_spr_raw_lib07_4C:
		.BYTE	$04		; *--
		.BYTE	$00,$34,$60,$F8	; *--
		.BYTE	$00,$24,$60,$00	; *--
		.BYTE	$F1,$22,$60,$00	; *--
		.BYTE	$F1,$22,$20,$F8	; *--
_spr_raw_lib07_4D:
		.BYTE	$04
		.BYTE	$00,$38,$20,$00
		.BYTE	$00,$28,$20,$F8
		.BYTE	$F0,$30,$20,$00
		.BYTE	$F0,$20,$20,$F8
_spr_raw_lib07_4E:
		.BYTE	$04
		.BYTE	$00,$3A,$20,$00
		.BYTE	$00,$2A,$20,$F8
		.BYTE	$F1,$30,$20,$00
		.BYTE	$F1,$20,$20,$F8
_spr_raw_lib07_4F:
		.BYTE	$04
		.BYTE	$00,$3A,$60,$F8
		.BYTE	$00,$2A,$60,$00
		.BYTE	$F1,$30,$20,$00
		.BYTE	$F1,$20,$20,$F8

_spr_raw_lib07:
		.WORD	_spr_raw_lib07_00
		.WORD	_spr_raw_lib07_01
		.WORD	_spr_raw_lib07_02
		.WORD	_spr_raw_lib07_03
		.WORD	_spr_raw_lib07_04
		.WORD	_spr_raw_lib07_05
		.WORD	_spr_raw_lib07_06
		.WORD	_spr_raw_lib07_07
		.WORD	_spr_raw_lib07_08
		.WORD	_spr_raw_lib07_09
		.WORD	_spr_raw_lib07_0A
		.WORD	_spr_raw_lib07_0B
		.WORD	_spr_raw_lib07_0C
		.WORD	_spr_raw_lib07_0D
		.WORD	_spr_raw_lib07_0E
		.WORD	_spr_raw_lib07_0F
		.WORD	_spr_raw_lib07_10
		.WORD	_spr_raw_lib07_11
		.WORD	_spr_raw_lib07_12
		.WORD	_spr_raw_lib07_13
		.WORD	_spr_raw_lib07_14	; *--
		.WORD	_spr_raw_lib07_15	; *--
		.WORD	_spr_raw_lib07_16	; *--
		.WORD	_spr_raw_lib07_17
		.WORD	_spr_raw_lib07_18
		.WORD	_spr_raw_lib07_19
		.WORD	_spr_raw_lib07_1A
		.WORD	_spr_raw_lib07_1B	; *--
		.WORD	_spr_raw_lib07_1C	; *--
		.WORD	_spr_raw_lib07_1D
		.WORD	_spr_raw_lib07_1E
		.WORD	_spr_raw_lib07_1F
		.WORD	_spr_raw_lib07_20	; *--
		.WORD	_spr_raw_lib07_21	; *--
		.WORD	_spr_raw_lib07_22	; *--
		.WORD	_spr_raw_lib07_23
		.WORD	_spr_raw_lib07_24
		.WORD	_spr_raw_lib07_25
		.WORD	_spr_raw_lib07_26
		.WORD	_spr_raw_lib07_27	; *--
		.WORD	_spr_raw_lib07_28	; *--
		.WORD	_spr_raw_lib07_29
		.WORD	_spr_raw_lib07_2A
		.WORD	_spr_raw_lib07_2B
		.WORD	_spr_raw_lib07_2C
		.WORD	_spr_raw_lib07_2D	; *--
		.WORD	_spr_raw_lib07_2E	; *--
		.WORD	_spr_raw_lib07_2F
		.WORD	_spr_raw_lib07_30
		.WORD	_spr_raw_lib07_31
		.WORD	_spr_raw_lib07_32	; *--
		.WORD	_spr_raw_lib07_33	; *--
		.WORD	_spr_raw_lib07_34	; *--
		.WORD	_spr_raw_lib07_35
		.WORD	_spr_raw_lib07_36
		.WORD	_spr_raw_lib07_37
		.WORD	_spr_raw_lib07_38
		.WORD	_spr_raw_lib07_39	; *--
		.WORD	_spr_raw_lib07_3A	; *--
		.WORD	_spr_raw_lib07_3B
		.WORD	_spr_raw_lib07_3C
		.WORD	_spr_raw_lib07_3D
		.WORD	_spr_raw_lib07_3E	; *--
		.WORD	_spr_raw_lib07_3F	; *--
		.WORD	_spr_raw_lib07_40	; *--
		.WORD	_spr_raw_lib07_41
		.WORD	_spr_raw_lib07_42
		.WORD	_spr_raw_lib07_43
		.WORD	_spr_raw_lib07_44	; *--
		.WORD	_spr_raw_lib07_45	; *--
		.WORD	_spr_raw_lib07_46	; *--
		.WORD	_spr_raw_lib07_47
		.WORD	_spr_raw_lib07_48
		.WORD	_spr_raw_lib07_49
		.WORD	_spr_raw_lib07_4A
		.WORD	_spr_raw_lib07_4B	; *--
		.WORD	_spr_raw_lib07_4C	; *--
		.WORD	_spr_raw_lib07_4D
		.WORD	_spr_raw_lib07_4E
		.WORD	_spr_raw_lib07_4F
		.WORD	_spr_raw_lib07_50
		.WORD	_spr_raw_lib07_51
		.WORD	_spr_raw_lib07_52
		.WORD	_spr_raw_lib07_53
		.WORD	_spr_raw_lib07_54
		.WORD	_spr_raw_lib07_55
		.WORD	_spr_raw_lib07_56
		.WORD	_spr_raw_lib07_57
		.WORD	_spr_raw_lib07_58
		.WORD	_spr_raw_lib07_59
		.WORD	_spr_raw_lib07_5A
		.WORD	_spr_raw_lib07_5B
		.WORD	_spr_raw_lib07_5C
		.WORD	_spr_raw_lib07_5D
		.WORD	_spr_raw_lib07_5E
		.WORD	_spr_raw_lib07_5F
		.WORD	_spr_raw_lib07_60
		.WORD	_spr_raw_lib07_61
		.WORD	_spr_raw_lib07_62
		.WORD	_spr_raw_lib07_63
		.WORD	_spr_raw_lib07_64
		.WORD	_spr_raw_lib07_65
		.WORD	_spr_raw_lib07_66
		.WORD	_spr_raw_lib07_67
		.WORD	_spr_raw_lib07_68
		.WORD	_spr_raw_lib07_69
		.WORD	_spr_raw_lib07_6A
		.WORD	_spr_raw_lib07_6B
		.WORD	_spr_raw_lib07_6C
		.WORD	_spr_raw_lib07_6D
		.WORD	_spr_raw_lib07_6E
		.WORD	_spr_raw_lib07_6F
		.WORD	_spr_raw_lib07_70
		.WORD	_spr_raw_lib08_02	; *--
		.WORD	_spr_raw_lib08_01	; *--
		.WORD	_spr_raw_lib08_03	; *--
		.WORD	_spr_raw_lib08_06
		.WORD	_spr_raw_lib08_05
		.WORD	_spr_raw_lib08_07
		.WORD	_spr_raw_lib08_0A	; *--
		.WORD	_spr_raw_lib08_09	; *--
		.WORD	_spr_raw_lib08_0B	; *--
		.WORD	_spr_raw_lib08_0E
		.WORD	_spr_raw_lib08_0D	; *--
		.WORD	_spr_raw_lib08_0F	; *--
		.WORD	_spr_raw_lib08_12	; *--
		.WORD	_spr_raw_lib08_11	; *--
		.WORD	_spr_raw_lib08_13	; *--
		.WORD	_spr_raw_lib08_16
		.WORD	_spr_raw_lib08_15
		.WORD	_spr_raw_lib08_17
		.WORD	_spr_raw_lib08_1A
		.WORD	_spr_raw_lib08_19	; *--
		.WORD	_spr_raw_lib08_1B	; *--
		.WORD	_spr_raw_lib08_1E
		.WORD	_spr_raw_lib08_1D	; *--
		.WORD	_spr_raw_lib08_1F	; *--
		.WORD	_spr_raw_lib08_22	; *--
		.WORD	_spr_raw_lib08_21	; *--
		.WORD	_spr_raw_lib08_23	; *--
		.WORD	_spr_raw_lib08_26
		.WORD	_spr_raw_lib08_25
		.WORD	_spr_raw_lib08_27
		.WORD	_spr_raw_lib08_2A
		.WORD	_spr_raw_lib08_29	; *--
		.WORD	_spr_raw_lib08_2B	; *--
		.WORD	_spr_raw_lib08_2E
		.WORD	_spr_raw_lib08_2D
		.WORD	_spr_raw_lib08_2F
		.WORD	_spr_raw_lib08_32	; *--
		.WORD	_spr_raw_lib08_31	; *--
		.WORD	_spr_raw_lib08_33	; *--
		.WORD	_spr_raw_lib08_36
		.WORD	_spr_raw_lib08_35
		.WORD	_spr_raw_lib08_37
		.WORD	_spr_raw_lib08_3A
		.WORD	_spr_raw_lib08_39	; *--
		.WORD	_spr_raw_lib08_3B	; *--
		.WORD	_spr_raw_lib08_3E
		.WORD	_spr_raw_lib08_3D
		.WORD	_spr_raw_lib08_3F
		.WORD	_spr_raw_lib08_42	; *--
		.WORD	_spr_raw_lib08_41	; *--
		.WORD	_spr_raw_lib08_43	; *--
		.WORD	_spr_raw_lib08_46
		.WORD	_spr_raw_lib08_45
		.WORD	_spr_raw_lib08_47
		.WORD	_spr_raw_lib08_4A
		.WORD	_spr_raw_lib08_49	; *--
		.WORD	_spr_raw_lib08_4B	; *--
		.WORD	_spr_raw_lib08_4E
		.WORD	_spr_raw_lib08_4D	; *--
		.WORD	_spr_raw_lib08_4F	; *--
		.WORD	_spr_raw_lib07_AD
		.WORD	_spr_raw_lib07_AE
		.WORD	_spr_raw_lib07_AF
		.WORD	_spr_raw_lib07_B0
		.WORD	_spr_raw_lib07_B1
		.WORD	_spr_raw_lib07_B2
		.WORD	_spr_raw_lib07_B3
		.WORD	_spr_raw_lib07_B4
		.WORD	_spr_raw_lib07_B5
		.WORD	_spr_raw_lib07_B6
		.WORD	_spr_raw_lib07_B7
		.WORD	_spr_raw_lib07_B8
		.WORD	_spr_raw_lib07_B9
		.WORD	_spr_raw_lib07_BA
		.WORD	_spr_raw_lib07_BB
		.WORD	_spr_raw_lib07_BC
_spr_res_lib07:
		.WORD	_spr_res_lib07_00
		.WORD	_spr_res_lib07_01
		.WORD	_spr_res_lib07_02
		.WORD	_spr_res_lib07_03
		.WORD	_spr_res_lib07_04
		.WORD	_spr_res_lib07_05
		.WORD	_spr_res_lib07_06
		.WORD	_spr_res_lib07_07
		.WORD	_spr_res_lib07_08
		.WORD	_spr_res_lib07_09
		.WORD	_spr_res_lib07_0A
		.WORD	_spr_res_lib07_0B
		.WORD	_spr_res_lib07_0C
		.WORD	_spr_res_lib07_0D
		.WORD	_spr_res_lib07_0E
		.WORD	_spr_res_lib07_0F
		.WORD	_spr_res_lib07_10
		.WORD	_spr_res_lib07_11
		.WORD	_spr_res_lib07_12

		SECTION_END	"SCR7 ENDING/CREDITS CODE AND DATA"

		SECTION_START

; =============== S U B R O U T I N E =======================================
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
		TLM_PAK	_tlm4_score_unused,$2000
		TLM_PAK	_tlm5_kanji_unused,$2000
		TLM_PAK	_tlm6_copyrights,$2000
		TLM_PAK	_tlm7_staff,$2000
		TLM_PAK	_tlm8_HAL,$2000
		TLM_PAK	_tlm9_secret_menu,$2000

; =============== S U B R O U T I N E =======================================
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
		CMP		#$80						; TODO: may be optimized as well
		BEQ		.cmd80
		CMP		#$A0
		BEQ		.cmdA0
		CMP		#$C0
		BEQ		.cmdC0
.cmd80:
		JSR		_hi_cmd_cnt_init			; cmd80, copy given number of bytes from
		JSR		_hi_cmd_ppu_byte_read_reverse; ppu ram (offset following) to current
		JSR		_hi_cmd_ppu_data_writeback	; ppu write offset in reverse order!
		INC		_var1
		DEC		_ptr08+1
		BPL		.cmd80
		JMP		.unpack_loop
.cmdA0:
		JSR		_hi_cmd_cnt_init			; cmdA0, read ppu data already written,
		JSR		_hi_cmd_ppu_byte_read_reverse; reverse bit order of all bytes read
		JSR		_hi_cmd_invert_data			; then write it back in reverse order
		JSR		_hi_cmd_ppu_data_writeback
		INC		_var1
		DEC		_ptr08+1
		BPL		.cmdA0
		JMP		.unpack_loop
.cmdC0:
		JSR		_hi_cmd_cnt_init			; cmdC0, read ppu data already written,
		JSR		_hi_cmd_ppu_byte_read		; and write back in original order
		JSR		_hi_cmd_ppu_data_writeback
		DEC		_ptr08+1
		BPL		.cmdC0
		JMP		.unpack_loop

; =============== S U B R O U T I N E =======================================
_hi_cmd_cnt_init:
		LDX		_ptr08
		LDA		_ptr08+1
		BEQ		loc_AF3C
		LDX		#$00
loc_AF3C:
		STX		_tmp1
		RTS

; =============== S U B R O U T I N E =======================================
_hi_cmd_ppu_byte_read_reverse:
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

; =============== S U B R O U T I N E =======================================
_hi_cmd_ppu_data_writeback:
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

; =============== S U B R O U T I N E =======================================
_hi_cmd_invert_data:
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

; =============== S U B R O U T I N E =======================================
_hi_cmd_ppu_byte_read:
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
		.BYTE	$3F,$EF,$23,$12,$37,$FF,$23,$02,$23,$13,$37,$FF,$23,$03,$9F,$00
		.BYTE	$40,$F0,$3F,$00,$40,$F0,$7F,$00,$40,$F0,$FF,$00,$40,$F0,$3F,$00
		.BYTE	$40,$23,$14,$37,$FF,$23,$04,$3F,$EE,$2C,$05,$00,$0D,$23,$1C,$00
		.BYTE	$1D,$2C,$05,$2C,$15,$00,$0E,$23,$08,$00,$1E,$2C,$15,$41,$00,$10
		.BYTE	$00,$FF,$43,$00,$10,$00,$0F,$23,$0C,$00,$1F,$43,$00,$10,$84,$03
		.BYTE	$04,$41,$01,$11,$00,$FF,$43,$01,$11,$25,$FF,$88,$03,$25,$41,$01
		.BYTE	$11,$8C,$03,$00,$04,$FF,$FF,$18,$06,$16,$89,$03,$44,$91,$03,$1C
		.BYTE	$03,$09,$19,$07,$17,$9B,$03,$32,$03,$0A,$1A,$2A,$FF,$9B,$03,$52
		.BYTE	$02,$0B,$1B,$2B,$8E,$03,$31,$00,$AA,$25,$0A,$01,$AA,$AA,$25,$00
		.BYTE	$87,$03,$C7,$8F,$03,$C7,$30,$AA,$27,$0A,$FF
_tlm1_score:
		.BYTE	$E4,$FF,$FF,$27,$20,$03,$FF,$54,$4F,$50,$88,$00,$FC,$00,$30,$C5
		.BYTE	$01,$15,$2B,$20,$8F,$00,$F8,$90,$01,$18,$04,$53,$43,$4F,$52,$45
		.BYTE	$F0,$39,$01,$0E,$E5,$4B,$20,$02,$40,$20,$33,$E4,$E8,$20,$E4,$3F
		.BYTE	$00,$FF
_tlm2_busterselect:
		.BYTE	$E4,$61,$FF,$0C,$EF,$D3,$E1,$D3,$CF,$F1,$FF,$CD,$F3,$EF,$F1,$D3
		.BYTE	$ED,$F8,$50,$00,$62,$24,$00,$02,$10,$20,$30,$85,$00,$C0,$26,$00
		.BYTE	$87,$00,$CD,$02,$10,$00,$00,$24,$01,$02,$11,$21,$31,$85,$00,$E0
		.BYTE	$26,$01,$87,$00,$ED,$02,$11,$01,$01,$24,$02,$02,$12,$22,$32,$23
		.BYTE	$02,$00,$42,$C5,$01,$05,$87,$01,$0B,$01,$02,$02,$87,$01,$15,$00
		.BYTE	$29,$85,$01,$06,$03,$02,$29,$02,$02,$C4,$01,$0C,$00,$29,$83,$01
		.BYTE	$2F,$01,$40,$50,$85,$01,$34,$00,$42,$86,$01,$03,$83,$01,$42,$8B
		.BYTE	$01,$16,$05,$41,$51,$43,$12,$02,$02,$24,$44,$02,$13,$23,$33,$85
		.BYTE	$01,$60,$25,$44,$00,$52,$86,$01,$6D,$83,$01,$6C,$07,$04,$14,$06
		.BYTE	$04,$14,$06,$24,$34,$83,$01,$82,$85,$01,$80,$88,$01,$89,$84,$01
		.BYTE	$80,$07,$05,$15,$07,$05,$15,$07,$25,$35,$83,$01,$A2,$85,$01,$A0
		.BYTE	$88,$01,$A9,$84,$01,$A0,$25,$16,$01,$26,$36,$29,$16,$01,$08,$09
		.BYTE	$8B,$01,$C8,$02,$16,$16,$19,$85,$01,$C3,$83,$01,$E2,$87,$01,$CD
		.BYTE	$01,$08,$09,$89,$01,$E8,$C4,$01,$E5,$85,$01,$C6,$88,$01,$D2,$85
		.BYTE	$01,$E9,$85,$01,$E9,$84,$01,$E9,$01,$26,$36,$87,$01,$DE,$41,$19
		.BYTE	$16,$8A,$01,$FB,$C6,$02,$36,$8E,$01,$E6,$86,$02,$12,$03,$2A,$3A
		.BYTE	$45,$55,$88,$01,$E0,$C7,$02,$31,$8A,$02,$30,$03,$2B,$5A,$46,$56
		.BYTE	$84,$02,$01,$03,$17,$27,$37,$47,$CB,$02,$40,$83,$01,$E2,$06,$53
		.BYTE	$57,$16,$2B,$4A,$5A,$5A,$24,$16,$03,$18,$28,$38,$48,$87,$01,$E9
		.BYTE	$00,$19,$86,$01,$D2,$06,$54,$58,$1C,$2B,$5A,$3B,$5A,$84,$01,$E9
		.BYTE	$8A,$02,$8C,$88,$01,$D2,$03,$49,$59,$1D,$2C,$22,$3C,$86,$01,$E9
		.BYTE	$8F,$02,$0C,$05,$19,$16,$39,$1B,$0C,$2D,$22,$3D,$84,$01,$CF,$86
		.BYTE	$01,$E9,$86,$02,$30,$89,$02,$52,$8B,$01,$F8,$32,$16,$83,$01,$E2
		.BYTE	$4F,$0A,$1A,$25,$FF,$00,$0B,$9D,$00,$A7,$00,$00,$86,$00,$C6,$32
		.BYTE	$00,$25,$0D,$01,$0E,$1E,$37,$0D,$00,$C0,$22,$F0,$23,$00,$01,$52
		.BYTE	$51,$25,$50,$36,$55,$00,$65,$26,$55,$00,$AA,$29,$05,$00,$01,$24
		.BYTE	$05,$9F,$03,$A0,$9F,$03,$A0,$F0,$3F,$04,$00,$F0,$7F,$04,$00,$F0
		.BYTE	$FF,$04,$00,$F1,$BF,$04,$00,$E4,$37,$55,$27,$05,$FF
_tlm3_game_over:
		.BYTE	$E4,$88,$FF,$02,$54,$4F,$50,$23,$FF,$24,$20,$01,$30,$30,$C4,$00
		.BYTE	$90,$33,$FF,$27,$20,$30,$FF,$04,$53,$43,$4F,$52,$45,$F0,$3A,$00
		.BYTE	$8E,$B6,$00,$73,$30,$FF,$02,$0A,$1A,$28,$29,$FF,$00,$0B,$28,$FF
		.BYTE	$0F,$00,$10,$2B,$02,$12,$22,$04,$14,$FF,$24,$06,$16,$26,$04,$08
		.BYTE	$18,$8F,$01,$19,$10,$01,$11,$21,$03,$13,$23,$05,$15,$FF,$25,$07
		.BYTE	$17,$27,$05,$09,$19,$29,$85,$01,$1A,$F8,$27,$01,$1F,$36,$FF,$01
		.BYTE	$0B,$1B,$DB,$01,$20,$23,$2A,$DB,$01,$BE,$03,$0B,$2A,$2A,$1B,$9C
		.BYTE	$01,$7E,$04,$2A,$2A,$FF,$2A,$1B,$9A,$01,$A4,$84,$02,$1C,$88,$01
		.BYTE	$7E,$02,$64,$65,$62,$62,$60,$03,$66,$67,$FF,$33,$86,$00,$97,$83
		.BYTE	$02,$1D,$01,$0B,$FF,$91,$02,$21,$87,$00,$B6,$00,$1B,$83,$02,$3B
		.BYTE	$DA,$01,$21,$25,$2A,$99,$01,$E0,$C4,$02,$20,$84,$02,$41,$87,$01
		.BYTE	$7E,$02,$67,$62,$63,$8E,$02,$B0,$00,$0B,$C3,$02,$61,$96,$02,$1F
		.BYTE	$41,$0B,$FF,$85,$02,$41,$96,$01,$7F,$85,$02,$3E,$8A,$02,$C3,$93
		.BYTE	$02,$2E,$C5,$03,$07,$8F,$02,$11,$89,$02,$58,$83,$01,$3E,$CD,$01
		.BYTE	$BF,$01,$2A,$1B,$85,$03,$66,$00,$1B,$83,$03,$65,$92,$03,$21,$C8
		.BYTE	$03,$5F,$22,$2A,$01,$1B,$0B,$84,$02,$E2,$8E,$03,$47,$85,$01,$7E
		.BYTE	$C3,$01,$E0,$35,$00,$02,$10,$88,$20,$25,$00,$0D,$A8,$AA,$00,$40
		.BYTE	$50,$50,$00,$00,$AA,$AA,$80,$00,$40,$10,$83,$03,$E5,$00,$88,$22
		.BYTE	$00,$04,$A0,$00,$AA,$0A,$08,$22,$00,$02,$0A,$00,$0A,$FF
_tlm4_score_unused:
		.BYTE	$E5,$08,$FF,$04,$54,$4F,$50,$FF,$FF,$26,$20,$02,$30,$30,$20,$37
		.BYTE	$FF,$27,$20,$30,$FF,$04,$53,$43,$4F,$52,$45,$F0,$3A,$01,$0E,$F8
		.BYTE	$27,$01,$3E,$96,$01,$31,$2B,$20,$8B,$01,$C6,$9F,$01,$C0,$8B,$01
		.BYTE	$28,$8B,$01,$28,$93,$01,$20,$9F,$02,$0C,$F8,$23,$01,$D3,$F0,$58
		.BYTE	$01,$70,$03,$90,$90,$91,$91,$26,$20,$02,$40,$20,$33,$9C,$01,$D7
		.BYTE	$F0,$23,$02,$6C,$E4,$A7,$FF,$E4,$29,$00,$01,$A0,$20,$33,$00,$FF
_tlm5_kanji_unused:
		.BYTE	$E5,$43,$00,$16,$10,$20,$30,$60,$70,$80,$80,$90,$A0,$B0,$D0,$E0
		.BYTE	$08,$18,$28,$38,$48,$68,$78,$88,$98,$A8,$B8,$27,$00,$19,$01,$11
		.BYTE	$21,$31,$61,$71,$81,$91,$A1,$B1,$C1,$D1,$E1,$09,$19,$29,$39,$49
		.BYTE	$69,$79,$89,$99,$A9,$B9,$C9,$D9,$25,$00,$19,$02,$12,$22,$32,$62
		.BYTE	$72,$82,$92,$92,$B2,$C2,$D2,$E2,$0A,$1A,$2A,$3A,$4A,$6A,$7A,$8A
		.BYTE	$9A,$AA,$BA,$CA,$DA,$26,$00,$18,$13,$23,$33,$63,$73,$83,$00,$00
		.BYTE	$B3,$C3,$D3,$E3,$0B,$1B,$2B,$3B,$4B,$6B,$7B,$8B,$9B,$AB,$BB,$CB
		.BYTE	$DB,$25,$00,$18,$04,$14,$24,$34,$64,$74,$84,$B6,$C6,$B4,$C4,$D4
		.BYTE	$E4,$0C,$1C,$2C,$3C,$4C,$6C,$7C,$8C,$9C,$AC,$BC,$CC,$26,$00,$18
		.BYTE	$05,$15,$25,$35,$65,$75,$85,$B7,$C7,$B5,$C5,$D5,$E5,$0D,$1D,$2D
		.BYTE	$3D,$4D,$6D,$7D,$8D,$9D,$AD,$BD,$CD,$27,$00,$04,$16,$26,$36,$66
		.BYTE	$76,$25,$00,$0C,$D6,$0E,$1E,$2E,$3E,$4E,$6E,$7E,$8E,$9E,$AE,$BE
		.BYTE	$CE,$27,$00,$05,$07,$17,$27,$37,$67,$77,$25,$00,$09,$D7,$D7,$E7
		.BYTE	$0F,$00,$2F,$6F,$7F,$8F,$9F,$E5,$C5,$00,$FF
; REGION, typo fixed partially in the EU version
_tlm6_copyrights:
		.BYTE	$E4,$48,$FF,$0D,$47,$48,$4F,$53,$54,$42,$55,$53,$54,$FF,$5B,$FF
		.BYTE	$54,$4D,$E4,$2E,$FF,$13,$4D,$4F,$56,$49,$45,$FF,$5C,$31,$39,$38
		.BYTE	$39,$FF,$43,$4F,$4C,$55,$4D,$42,$49,$41,$E4,$29,$FF,$17,$50,$49
		.BYTE	$43,$54,$55,$52,$45,$53,$FF,$49,$4E,$44,$55,$53,$54,$52,$49,$45
		.BYTE	$53,$2C,$49,$4E,$43,$2E,$F8,$2A,$00,$C3,$11,$4C,$4C,$FF,$52,$49
		.BYTE	$47,$48,$54,$53,$FF,$52,$45,$53,$45,$52,$56,$45,$44,$E4,$4A,$FF
		.BYTE	$01,$55,$53,$83,$01,$17,$10,$55,$4E,$44,$45,$52,$FF,$FF,$53,$55
		.BYTE	$42,$4C,$49,$43,$45,$4E,$53,$45,$E4,$2C,$FF,$0E,$46,$52,$4F,$4D
		.BYTE	$FF,$41,$43,$54,$49,$56,$49,$53,$49,$4F,$4E,$F0,$3A,$00,$18,$03
		.BYTE	$54,$48,$45,$4D,$F0,$2D,$01,$7A,$83,$00,$8C,$13,$34,$FF,$47,$4F
		.BYTE	$4C,$44,$45,$4E,$FF,$54,$4F,$52,$43,$48,$FF,$4D,$55,$53,$49,$43
		.BYTE	$E4,$27,$FF,$11,$43,$4F,$52,$50,$2E,$FF,$41,$4E,$44,$FF,$52,$41
		.BYTE	$59,$44,$49,$4F,$4C,$41,$F0,$2D,$02,$36,$01,$FF,$FF,$86,$01,$74
		.BYTE	$0C,$44,$FF,$42,$59,$FF,$4E,$49,$4E,$54,$45,$4E,$44,$4F,$E4,$4D
		.BYTE	$FF,$03,$43,$4F,$50,$59,$84,$01,$0A,$83,$00,$8B,$01,$39,$30,$E4
		.BYTE	$2D,$FF,$10,$42,$59,$FF,$48,$41,$4C,$FF,$4C,$41,$42,$4F,$52,$41
		.BYTE	$54,$4F,$52,$59,$F0,$2E,$00,$D7,$E4,$3A,$FF,$01,$00,$00,$23,$50
		.BYTE	$22,$00,$00,$54,$23,$55,$00,$51,$87,$03,$C7,$22,$00,$23,$55,$86
		.BYTE	$03,$D7,$83,$03,$DC,$00,$44,$23,$05,$00,$11,$8A,$03,$CF,$25,$00
		.BYTE	$FF
_tlm7_staff:
		.BYTE	$3F,$EF,$23,$12,$37,$FF,$23,$02,$23,$13,$37,$FF,$23,$03,$9F,$00
		.BYTE	$40,$86,$00,$40,$10,$47,$48,$4F,$53,$54,$42,$55,$53,$54,$45,$52
		.BYTE	$53,$FF,$5B,$FF,$54,$4D,$F0,$2E,$00,$58,$F0,$3F,$00,$47,$F0,$43
		.BYTE	$00,$A7,$06,$2D,$FF,$53,$54,$41,$46,$46,$C8,$01,$4C,$F0,$AF,$00
		.BYTE	$9B,$F0,$74,$00,$AB,$23,$14,$37,$FF,$23,$04,$3F,$EE,$2C,$05,$00
		.BYTE	$0D,$23,$1C,$00,$1D,$2C,$05,$2C,$15,$00,$0E,$23,$08,$00,$1E,$2C
		.BYTE	$15,$41,$00,$10,$00,$FF,$43,$00,$10,$00,$0F,$23,$0C,$00,$1F,$43
		.BYTE	$00,$10,$84,$03,$04,$41,$01,$11,$00,$FF,$43,$01,$11,$25,$FF,$88
		.BYTE	$03,$25,$41,$01,$11,$8C,$03,$00,$04,$FF,$FF,$18,$06,$16,$89,$03
		.BYTE	$44,$91,$03,$1C,$03,$09,$19,$07,$17,$9B,$03,$32,$03,$0A,$1A,$2A
		.BYTE	$FF,$9B,$03,$52,$02,$0B,$1B,$2B,$8E,$03,$31,$00,$AA,$25,$FA,$01
		.BYTE	$AA,$AA,$25,$FF,$87,$03,$C7,$8F,$03,$C7,$30,$AA,$27,$0A,$FF
_tlm8_HAL:
		.BYTE	$E5,$6A,$FF,$62,$00,$04,$10,$03,$13,$23,$30,$98,$01,$53,$05,$11
		.BYTE	$21,$10,$04,$14,$24,$99,$01,$72,$08,$01,$02,$20,$05,$15,$25,$31
		.BYTE	$12,$22,$E4,$33,$FF,$0E,$06,$16,$26,$36,$08,$18,$28,$38,$0A,$1A
		.BYTE	$2A,$3A,$0C,$1C,$2C,$30,$FF,$0E,$07,$17,$27,$37,$09,$19,$29,$39
		.BYTE	$0B,$1B,$2B,$3B,$0D,$1D,$2D,$E5,$A7,$FF,$E4,$3F,$00,$FF
_tlm9_secret_menu:
		.BYTE	$E4,$E3,$FF,$02,$4B,$45,$59,$22,$FF,$0D,$41,$2D,$42,$45,$41,$4D
		.BYTE	$FF,$FF,$42,$2D,$54,$52,$41,$50,$E4,$6A,$FF,$02,$52,$41,$4E,$C3
		.BYTE	$00,$E4,$05,$4E,$4F,$52,$4D,$41,$4C,$E4,$39,$FF,$83,$00,$EC,$06
		.BYTE	$45,$52,$FF,$2D,$FF,$FF,$33,$E4,$34,$FF,$0E,$45,$58,$54,$45,$4E
		.BYTE	$44,$FF,$96,$FF,$FF,$31,$53,$54,$FF,$31,$23,$30,$33,$FF,$00,$98
		.BYTE	$3E,$FF,$07,$97,$FF,$FF,$32,$4E,$44,$FF,$33,$F0,$37,$01,$F9,$05
		.BYTE	$99,$45,$56,$45,$52,$59,$99,$02,$37,$93,$01,$97,$01,$47,$4D,$C4
		.BYTE	$02,$00,$E4,$38,$FF,$00,$53,$C4,$01,$EA,$F0,$39,$02,$AB,$E4,$9A
		.BYTE	$FF,$29,$00,$00,$10,$2E,$00,$00,$01,$2E,$00,$00,$11,$34,$00,$FF

		SECTION_END	"TLM PACKED CODE AND DATA"

		BANK_END 0,$C000
