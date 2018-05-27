
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

		BANK_START $00


_scr0_intro_title_select:
		.BYTE	$07	; NJSR		  _nsub_obj_sarg_add_imm_test,$00,$FF
		.WORD	_nsub_obj_sarg_add_imm_test
		.BYTE	$00,$FF
		.BYTE	$11,$0C		; SJMP_SW	  $0C
		.WORD	_sjmp_case_8635	; CASE	  _sjmp_case_8635
		.WORD	_sjmp_case_866A	; CASE	  _sjmp_case_866A
		.WORD	_sjmp_case_8746	; CASE	  _sjmp_case_8746
		.WORD	_sjmp_case_8812	; CASE	  _sjmp_case_8812
		.WORD	_sjmp_case_88DE	; CASE	  _sjmp_case_88DE
		.WORD	_sjmp_case_8CC9	; CASE	  _sjmp_case_8CC9
		.WORD	_sjmp_case_8E09	; CASE	  _sjmp_case_8E09
		.WORD	_sjmp_case_8E14	; CASE	  _sjmp_case_8E14
		.WORD	_sjmp_case_8E1F	; CASE	  _sjmp_case_8E1F
		.WORD	_sjmp_case_8E2A	; CASE	  _sjmp_case_8E2A
		.WORD	_sjmp_case_89AC	; CASE	  _sjmp_case_89AC
		.WORD	_sjmp_case_8A5D	; CASE	  _sjmp_case_8A5D
		.BYTE	$07		; NJSR		  _nsub_mcmp,_license_screen_display_flag,$01
		.WORD	_nsub_mcmp
		.WORD	_license_screen_display_flag
		.BYTE	1
		.BYTE	$0C		; SBCC		  _sloc_805E
		.WORD	_sloc_805E
		.BYTE	$13		; STORE8	  _license_screen_display_flag,$00
		.WORD	_license_screen_display_flag
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_init_counters,$FC
		.WORD	_nsub_init_counters
		.BYTE	$FC
		.BYTE	$07		; NJSR		  _nsub_62775,$00
		.WORD	_nsub_62775
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$08
		.WORD	_nsub_far_prg0_tlm_lib_unpack
		.BYTE	$08
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$1B
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$1B
		.BYTE	$07		; NJSR		  _nsub_bg_pal_load,_pal0
		.WORD	_nsub_bg_pal_load
		.WORD	_pal0
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$06,$5A		; SDELAY	  $5A
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$06
		.WORD	_nsub_far_prg0_tlm_lib_unpack ; copyrights
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$09
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_bg_pal_load,_pal1
		.WORD	_nsub_bg_pal_load
		.WORD	_pal1
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$06,$5A		; SDELAY	  $5A
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
_sloc_805E:
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$05
		.WORD	_nsub_apu_mus_load
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,_pal2
		.WORD	_nsub_full_pal_load
		.WORD	_pal2
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$01
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$00
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$00
		.WORD	_nsub_far_prg0_tlm_lib_unpack
		.BYTE	$00
		.BYTE	$0F,$02,$00	; SARG_SET	  $02,$00
		.BYTE	$01,$12		; SLOOP_BEGIN	  $12
		.BYTE	$07		; NJSR		  _nsub_tlm_raw_arg2_idx_line_draw,_tlm_raw_title
		.WORD	_nsub_tlm_raw_arg2_idx_line_draw
		.WORD	_tlm_raw_title
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_title_attr_select,$00
		.WORD	_nsub_title_attr_select
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_script_start,$00,$00,$00,$0C,$00
		.WORD	_nsub_script_start
		.BYTE	$00,$00,$00,$0C,$00
		.BYTE	$28,$80,$00	; POS_X_SET	  0,$80,$00
		.BYTE	$30,$88,$00	; POS_Y_SET	  0,$88,$00
		.BYTE	$21,$00		; SPR_IDX_SET	  1,$00
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_title_input
		.WORD	_nbgsub_title_input
_sloc_809A:
		.BYTE	$06,$3B		; SDELAY	  $3B
		.BYTE	$9B		; SPR_IDX_INC	  3
		.BYTE	$22,$FF		; SPR_IDX_SET	  2,$FF
		.BYTE	$07		; NJSR		  _nsub_arg12_load_data_ofs,_script_chain_data0
		.WORD	_nsub_arg12_load_data_ofs
		.WORD	_script_chain_data0
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$07		; NJSR		  _nsub_script_chain_start
		.WORD	_nsub_script_chain_start
		.BYTE	$02		; SLOOP_END
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$04		; SJSR		  _ssub_812C
		.WORD	_ssub_812C
		.BYTE	$0F,$02,$00	; SARG_SET	  $02,$00
		.BYTE	$01,$12		; SLOOP_BEGIN	  $12
		.BYTE	$07		; NJSR		  _nsub_tlm_raw_arg2_idx_line_draw,_tlm_text_title
		.WORD	_nsub_tlm_raw_arg2_idx_line_draw
		.WORD	_tlm_text_title
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_title_attr_select,$01
		.WORD	_nsub_title_attr_select
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_hi_scores_display,$0F,$0A
		.WORD	_nsub_hi_scores_display
		.BYTE	$0F,$0A
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,_pal3
		.WORD	_nsub_full_pal_load
		.WORD	_pal3
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$09
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_script_start,$00,$00,$00,$0B,$00
		.WORD	_nsub_script_start
		.BYTE	$00,$00,$00,$0B,$00
		.BYTE	$04		; SJSR		  _ssub_8136
		.WORD	_ssub_8136
		.BYTE	$08,$01		; SRUN		  $01,_scr_810E
		.WORD	_scr_810E
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$06,$67		; SDELAY	  $67
		.BYTE	$14,$01		; SDISABLE	  $01
		.BYTE	$07		; NJSR		  _nsub_init_counters,$00
		.WORD	_nsub_init_counters
		.BYTE	$00
		.BYTE	$04		; SJSR		  _ssub_812C
		.WORD	_ssub_812C
		.BYTE	$0F,$02,$00	; SARG_SET	  $02,$00
		.BYTE	$01,$12		; SLOOP_BEGIN	  $12
		.BYTE	$07		; NJSR		  _nsub_tlm_raw_arg2_idx_line_draw,_tlm_raw_title
		.WORD	_nsub_tlm_raw_arg2_idx_line_draw
		.WORD	_tlm_raw_title
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_title_attr_select,$00
		.WORD	_nsub_title_attr_select
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,_pal2
		.WORD	_nsub_full_pal_load
		.WORD	_pal2
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$00
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$00
		.BYTE	$21,$00		; SPR_IDX_SET	  1,$00
		.BYTE	$04		; SJSR		  _ssub_8136
		.WORD	_ssub_8136
		.BYTE	$03		; SJMP		  _sloc_809A
		.WORD	_sloc_809A
_scr_810E:
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$40
		.WORD	_nsub_counters_inc
		.BYTE	$40
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$40
		.WORD	_nsub_counters_dec
		.BYTE	$40
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$40
		.WORD	_nsub_counters_inc
		.BYTE	$40
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$03		; SJMP		  _scr_810E
		.WORD	_scr_810E
_ssub_812C:
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$DB
		.WORD	_nsub_counters_dec
		.BYTE	$DB
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$05		; SRET
_ssub_8136:
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$DB
		.WORD	_nsub_counters_inc
		.BYTE	$DB
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$05		; SRET
_scr_select_busters_start:
		.BYTE	$04	; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$03		; SJMP		  _scr_select_busters
		.WORD	_scr_select_busters
_scr_secret_menu_start:
		.BYTE	$04	; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$03		; SJMP		  _scr_secret_menu
		.WORD	_scr_secret_menu
_script_chain_data0:
		.BYTE	$01,$00,$08,$60
		.BYTE	$02,$00,$10,$20
		.BYTE	$03,$F8,$10,$00
		.BYTE	$04,$08,$10,$20
		.BYTE	$05,$00,$10,$00
_pal0:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00
_pal1:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00,$0F,$30,$10,$00
_pal2:
		.BYTE	$0F,$30,$15,$29,$0F,$30,$01,$29,$0F,$21,$11,$01,$0F,$14,$10,$30
		.BYTE	$0F,$36,$1C,$0F,$0F,$30,$35,$0F,$0F,$30,$15,$29,$0F,$36,$2B,$0F
_pal3:
		.BYTE	$0F,$35,$15,$05,$0F,$25,$10,$00,$0F,$21,$11,$01,$0F,$30,$2A,$01
		.BYTE	$0F,$30,$15,$29,$0F,$30,$35,$0F,$0F,$30,$10,$00,$0F,$30,$2A,$01
_tlm_raw_title:
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
_tlm_text_title:
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

; =============== S U B	R O U T	I N E =======================================
_nbgsub_title_input:
		LDA		_pad0_pressed
		AND		#$10
		BEQ		locret_8539
		LDA		_pad0_held
		AND		#$C0
		CMP		#$C0
		BNE		loc_8534
		JSR		_script_load_param
		.WORD	_scr_secret_menu_start
		RTS
loc_8534:
		JSR		_script_load_param
		.WORD	_scr_select_busters_start
locret_8539:
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_title_attr_select:
		JSR		_scr_getc
		BNE		loc_8545
		JSR		_ppu_res_send_param
		.WORD	_attr_title0
		RTS
loc_8545:
		JSR		_ppu_res_send_param
		.WORD	_attr_title1
		RTS
_attr_title0:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$0A,$5A,$5A,$5A,$5A,$5A,$AA,$AA,$00,$05,$05,$05,$05,$05,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$00,$AA,$AA,$00,$00,$00,$00,$00,$00,$AA
		.BYTE	$AA,$00,$00,$00,$00,$00,$00,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A
_attr_title1:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$0A,$0A,$0A,$0A,$0A,$0A,$AA,$AA,$00,$00,$00,$00,$00,$0F,$AA
		.BYTE	$AA,$00,$C0,$F0,$F0,$30,$00,$AA,$AA,$00,$00,$00,$10,$51,$00,$AA
		.BYTE	$AA,$C0,$F5,$F5,$F5,$F5,$31,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A
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
_sjmp_case_8635:
		.BYTE	$08,$01		; SRUN		  $01,_scr_8642
		.WORD	_scr_8642
		.BYTE	$56,$00,$01	; POS_Y_DELTA_SET 6,$00,$01
		.BYTE	$50,$80,$00	; POS_Y_DELTA_SET 0,$80,$00
		.BYTE	$06,$C8		; SDELAY	  $C8
		.BYTE	$00		; STOP
_scr_8642:
		.BYTE	$26,$02		; SPR_IDX_SET	  6,$02
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$03		; SJMP		  _scr_8642
		.WORD	_scr_8642
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
_sjmp_case_866A:
		.BYTE	$20,$04		; SPR_IDX_SET	  0,$04
_sloc_866C:
		.BYTE	$50,$00,$02	; POS_Y_DELTA_SET 0,$00,$02
		.BYTE	$06,$0C		; SDELAY	  $0C
_sloc_8671:
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$50,$80,$00	; POS_Y_DELTA_SET 0,$80,$00
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$AE,$02		; SPR_IDX_ADD_IMM 6,$02
		.BYTE	$AE,$FE		; SPR_IDX_ADD_IMM 6,$FE
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_8746:
		.BYTE	$20,$10		; SPR_IDX_SET	  0,$10
		.BYTE	$48,$40,$FF	; POS_X_DELTA_SET 0,$40,$FF
		.BYTE	$03		; SJMP		  _sloc_866C
		.WORD	_sloc_866C
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
_sjmp_case_8812:
		.BYTE	$20,$1C		; SPR_IDX_SET	  0,$1C
		.BYTE	$48,$C0,$00	; POS_X_DELTA_SET 0,$C0,$00
		.BYTE	$03		; SJMP		  _sloc_866C
		.WORD	_sloc_866C
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
_sjmp_case_88DE:
		.BYTE	$20,$28		; SPR_IDX_SET	  0,$28
		.BYTE	$50,$00,$02	; POS_Y_DELTA_SET 0,$00,$02
		.BYTE	$06,$0A		; SDELAY	  $0A
		.BYTE	$03		; SJMP		  _sloc_8671
		.WORD	_sloc_8671
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
_sjmp_case_89AC:
		.BYTE	$28,$80,$00	; POS_X_SET	  0,$80,$00
		.BYTE	$30,$68,$00	; POS_Y_SET	  0,$68,$00
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$20,$46		; SPR_IDX_SET	  0,$46
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$A7		; SPR_IDX_DEC	  7
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_8A5D:
		.BYTE	$28,$30,$00	; POS_X_SET	  0,$30,$00
		.BYTE	$30,$20,$00	; POS_Y_SET	  0,$20,$00
		.BYTE	$20,$4C		; SPR_IDX_SET	  0,$4C
_sloc_8A65:
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$07		; NJSR		  _nsub_pal_patch_load,byte_8A91,$16,$00
		.WORD	_nsub_pal_patch_load
		.WORD	byte_8A91
		.BYTE	$16,$00
		.BYTE	$15,$00,$02,$01	; SARG_ALU	  $00,ADC,$01
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$03		; SJMP		  _sloc_8A65
		.WORD	_sloc_8A65
_sloc_8A7B_unref:
		.BYTE	$0F,$01,$00	; SARG_SET	  $01,$00
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$07		; NJSR		  _nsub_pal_patch_load,byte_8A97,$17,$01
		.WORD	_nsub_pal_patch_load
		.WORD	_unref_unused
		.BYTE	$17,$01
		.BYTE	$15,$01,$02,$01	; SARG_ALU	  $01,ADC,$01
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$03		; SJMP		  _sloc_8A7B_unref
		.WORD	_sloc_8A7B_unref
byte_8A91:
		.BYTE	$35,$25,$15,$05,$15,$25
_unref_unused:
		.BYTE	$0F,$10,$20,$30,$20,$10,$01 ; *--

; =============== S U B	R O U T	I N E =======================================
_nsub_pal_patch_load:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
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
		JMP		sub_62141
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
_scr_select_busters:
		.BYTE	$07		; NJSR		  _nsub_62B40
		.WORD	_nsub_62B40
		.BYTE	$07		; NJSR		  _nsub_mmc1_mirror_horizontal
		.WORD	_nsub_mmc1_mirror_horizontal
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$02
		.WORD	_nsub_far_prg0_tlm_lib_unpack
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_mmc1_mirror_vertical
		.WORD	_nsub_mmc1_mirror_vertical
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_8B8A
		.WORD	_nsub_full_pal_load
		.WORD	byte_8B8A
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$06
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$06
		.BYTE	$13		; STORE8	  _tmp7B7,$FF
		.WORD	_tmp7B7
		.BYTE	$FF
		.BYTE	$13		; STORE8	  _tmp7B8,$FF
		.WORD	_tmp7B8
		.BYTE	$FF
		.BYTE	$13		; STORE8	  _cur_room_x_pageA,$00
		.WORD	_cur_room_x_pageA
		.BYTE	$00
		.BYTE	$13		; STORE8	  _cur_room_x_pageB,$00
		.WORD	_cur_room_x_pageB
		.BYTE	$00
		.BYTE	$28,$00,$01	; POS_X_SET	  0,$00,$01
		.BYTE	$07		; NJSR		  _nsub_arg12_load_data_ofs,_script_chain_data1
		.WORD	_nsub_arg12_load_data_ofs
		.WORD	_script_chain_data1
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$07		; NJSR		  _nsub_script_chain_start
		.WORD	_nsub_script_chain_start
		.BYTE	$02		; SLOOP_END
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$01
		.WORD	_nsub_apu_mus_load
		.BYTE	$01
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
_sloc_8B3D:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_62B70,$A6,$07
		.WORD	_nsub_62B70
		.BYTE	$A6,$07
		.BYTE	$0C		; SBCC		  _sloc_8B3D
		.WORD	_sloc_8B3D
		.BYTE	$07		; NJSR		  _nsub_8BC8
		.WORD	_nsub_8BC8
		.BYTE	$0C		; SBCC		  _sloc_8B3D
		.WORD	_sloc_8B3D
_sloc_8B4D:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_62B70,$A6,$07
		.WORD	_nsub_62B70
		.BYTE	$A6,$07
		.BYTE	$0C		; SBCC		  _sloc_8B4D
		.WORD	_sloc_8B4D
		.BYTE	$07		; NJSR		  _nsub_8BC8
		.WORD	_nsub_8BC8
		.BYTE	$0C		; SBCC		  _sloc_8B4D
		.WORD	_sloc_8B4D
_sloc_8B5D:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_62B70,$A8,$07
		.WORD	_nsub_62B70
		.BYTE	$A8,$07
		.BYTE	$0C		; SBCC		  _sloc_8B5D
		.WORD	_sloc_8B5D
		.BYTE	$06,$5A		; SDELAY	  $5A
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$FF
		.WORD	_nsub_counters_dec
		.BYTE	$FF
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_8BAA
		.WORD	_nsub_8BAA
		.BYTE	$00		; STOP
_script_chain_data1:
		.BYTE	$06,$00,$F8,$00
		.BYTE	$07,$18,$F8,$00
		.BYTE	$08,$30,$F8,$00
		.BYTE	$09,$48,$F8,$00
		.BYTE	$0A,$E0,$40,$00
byte_8B8A:
		.BYTE	$0F,$00,$16,$07,$0F,$10,$00,$07,$0F,$27,$17,$07,$0F,$30,$0F,$0F
		.BYTE	$0F,$36,$1C,$0F,$0F,$0F,$0F,$0F,$0F,$30,$0F,$0F,$0F,$0F,$0F,$0F

; =============== S U B	R O U T	I N E =======================================
_nsub_8BAA:
		LDY		_tmp7B7
		LDA		byte_8BC3,Y
		STA		_tmp7B7
		STA		_tmp7B9
		LDY		_tmp7B8
		LDA		byte_8BC3,Y
		STA		_tmp7B8
		STA		_tmp7BA
		RTS
byte_8BC3:
		.BYTE	$00,$10,$20,$30,$40

; =============== S U B	R O U T	I N E =======================================
_nsub_8BC8:
		LDX		_scr_cur_trd_idx
		LDA		_pad0_pressed
		AND		#$01
		BEQ		loc_8BE6
		LDA		#$0B
		JSR		_far_prg6_apu_snd_load
loc_8BD5:
		INC		_scr_trds_args0,X
		LDA		_scr_trds_args0,X
		CMP		#$05
		BCC		loc_8BE1
		LDA		#$00
		STA		_scr_trds_args0,X
loc_8BE1:
		CMP		_tmp7B7
		BEQ		loc_8BD5
loc_8BE6:
		LDA		_pad0_pressed
		AND		#$02
		BEQ		loc_8C00
		LDA		#$0B
		JSR		_far_prg6_apu_snd_load
loc_8BF1:
		DEC		_scr_trds_args0,X
		BPL		loc_8BF9
		LDA		#$04
		STA		_scr_trds_args0,X
loc_8BF9:
		LDA		_scr_trds_args0,X
		CMP		_tmp7B7
		BEQ		loc_8BF1
loc_8C00:
		LDA		_pad0_pressed
		AND		#$80
		BEQ		loc_8C36
		LDA		#$0C
		JSR		_far_prg6_apu_snd_load
		LDA		_scr_trds_args0,X
		LDY		_tmp7B7
		BPL		loc_8C17
		STA		_tmp7B7
		BMI		loc_8C1A
loc_8C17:
		STA		_tmp7B8
loc_8C1A:
		LDA		#$FF
		STA		_scr_trds_spr_idx,X
		LDA		#$00
		STA		_cur_room_x_pageA
loc_8C23:
		INC		_scr_trds_args0,X
		LDA		_scr_trds_args0,X
		CMP		#$05
		BCC		loc_8C2F
		LDA		#$00
		STA		_scr_trds_args0,X
loc_8C2F:
		CMP		_tmp7B7
		BEQ		loc_8C23
		SEC
		RTS
loc_8C36:
		LDY		_scr_trds_args0,X
		LDA		byte_8C51,Y
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
_sjmp_case_8CC9:
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
		.BYTE	$0F,$01,$08	; SARG_SET	  $01,$08
		.BYTE	$20,$09		; SPR_IDX_SET	  0,$09
		.BYTE	$04		; SJSR		  _ssub_8CD5
		.WORD	_ssub_8CD5
		.BYTE	$0A		; SUSPEND
_ssub_8CD5:
		.BYTE	$48,$00,$FC	; POS_X_DELTA_SET 0,$00,$FC
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$AB,$FE		; SPR_IDX_ADD_IMM 3,$FE
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$06,$03		; SDELAY	  $03
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$48,$80,$FF	; POS_X_DELTA_SET 0,$80,$FF
		.BYTE	$06,$03		; SDELAY	  $03
		.BYTE	$48,$E0,$FF	; POS_X_DELTA_SET 0,$E0,$FF
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$A8,$FE		; SPR_IDX_ADD_IMM 0,$FE
		.BYTE	$06,$0F		; SDELAY	  $0F
		.BYTE	$50,$00,$01	; POS_Y_DELTA_SET 0,$00,$01
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$AC,$02		; SPR_IDX_ADD_IMM 4,$02
		.BYTE	$AC,$FE		; SPR_IDX_ADD_IMM 4,$FE
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$02		; SLOOP_END
		.BYTE	$13		; STORE8	  _cur_room_x_pageA,$01
		.WORD	_cur_room_x_pageA
		.BYTE	$01
_sloc_8D0C:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_8DDD
		.WORD	_nsub_8DDD
		.BYTE	$0C		; SBCC		  _sloc_8D0C
		.WORD	_sloc_8D0C
		.BYTE	$07		; NJSR		  _nsub_8DE6
		.WORD	_nsub_8DE6
		.BYTE	$0B		; SBCS		  _sloc_8D29
		.WORD	_sloc_8D29
_sloc_8D1A:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_8DF3
		.WORD	_nsub_8DF3
		.BYTE	$0C		; SBCC		  _sloc_8D1A
		.WORD	_sloc_8D1A
		.BYTE	$07		; NJSR		  _nsub_8DFC
		.WORD	_nsub_8DFC
		.BYTE	$0B		; SBCS		  _sloc_8D88
		.WORD	_sloc_8D88
		.BYTE	$0A		; SUSPEND
_sloc_8D29:
		.BYTE	$04		; SJSR		  _ssub_8DC2
		.WORD	_ssub_8DC2
		.BYTE	$A8,$03		; SPR_IDX_ADD_IMM 0,$03
_sloc_8D2E:
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$08,$01		; SRUN		  $01,_scr_8DD2
		.WORD	_scr_8DD2
_sloc_8D35:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_62B60,$50
		.WORD	_nsub_62B60
		.BYTE	$50
		.BYTE	$0C		; SBCC		  _sloc_8D35
		.WORD	_sloc_8D35
		.BYTE	$14,$01		; SDISABLE	  $01
		.BYTE	$07		; NJSR		  _nsub_obj_spr_idx_set_from_sarg,$01
		.WORD	_nsub_obj_spr_idx_set_from_sarg
		.BYTE	$01
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$13		; STORE8	  _cur_room_x_pageA,$01
		.WORD	_cur_room_x_pageA
		.BYTE	$01
_sloc_8D49:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_62B70,$A8,$07
		.WORD	_nsub_62B70
		.BYTE	$A8,$07
		.BYTE	$0C		; SBCC		  _sloc_8D49
		.WORD	_sloc_8D49
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$50,$00,$FE	; POS_Y_DELTA_SET 0,$00,$FE
		.BYTE	$06,$0C		; SDELAY	  $0C
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$80,$00,$02	; SCRL_Y_MOVE_SET 0,$00,$02
_sloc_8D5F:
		.BYTE	$50,$00,$02	; POS_Y_DELTA_SET 0,$00,$02
		.BYTE	$A8,$03		; SPR_IDX_ADD_IMM 0,$03
		.BYTE	$06,$05		; SDELAY	  $05
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$05		; SDELAY	  $05
		.BYTE	$A8,$03		; SPR_IDX_ADD_IMM 0,$03
		.BYTE	$06,$05		; SDELAY	  $05
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$06,$19		; SDELAY	  $19
		.BYTE	$20,$45		; SPR_IDX_SET	  0,$45
		.BYTE	$06,$05		; SDELAY	  $05
		.BYTE	$07		; NJSR		  _nsub_obj_spr_idx_set_from_sarg,$01
		.WORD	_nsub_obj_spr_idx_set_from_sarg
		.BYTE	$01
		.BYTE	$A8,$03		; SPR_IDX_ADD_IMM 0,$03
_sloc_8D7B:
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$02		; SLOOP_END
		.BYTE	$A8,$FD		; SPR_IDX_ADD_IMM 0,$FD
		.BYTE	$03		; SJMP		  _sloc_8D7B
		.WORD	_sloc_8D7B
_sloc_8D88:
		.BYTE	$04		; SJSR		  _ssub_8DC2
		.WORD	_ssub_8DC2
		.BYTE	$A8,$03		; SPR_IDX_ADD_IMM 0,$03
_sloc_8D8D:
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$08,$01		; SRUN		  $01,_scr_8DD2
		.WORD	_scr_8DD2
_sloc_8D94:
		.BYTE	$07		; NJSR		  _nsub_62B60,$68
		.WORD	_nsub_62B60
		.BYTE	$68
		.BYTE	$0B		; SBCS		  _sloc_8DA0
		.WORD	_sloc_8DA0
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$03		; SJMP		  _sloc_8D94
		.WORD	_sloc_8D94
_sloc_8DA0:
		.BYTE	$13		; STORE8	  _cur_room_x_pageB,$01
		.WORD	_cur_room_x_pageB
		.BYTE	$01
_sloc_8DA4:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_62B60,$50
		.WORD	_nsub_62B60
		.BYTE	$50
		.BYTE	$0C		; SBCC		  _sloc_8DA4
		.WORD	_sloc_8DA4
		.BYTE	$14,$01		; SDISABLE	  $01
		.BYTE	$07		; NJSR		  _nsub_obj_spr_idx_set_from_sarg,$01
		.WORD	_nsub_obj_spr_idx_set_from_sarg
		.BYTE	$01
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$02		; SDELAY	  $02
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$50,$00,$FE	; POS_Y_DELTA_SET 0,$00,$FE
		.BYTE	$06,$0C		; SDELAY	  $0C
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$03		; SJMP		  _sloc_8D5F
		.WORD	_sloc_8D5F
_ssub_8DC2:
		.BYTE	$50,$00,$01	; POS_Y_DELTA_SET 0,$00,$01
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$AC,$02		; SPR_IDX_ADD_IMM 4,$02
		.BYTE	$A8,$FE		; SPR_IDX_ADD_IMM 0,$FE
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$05		; SRET
_scr_8DD2:
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$AC,$02		; SPR_IDX_ADD_IMM 4,$02
		.BYTE	$A8,$FE		; SPR_IDX_ADD_IMM 0,$FE
		.BYTE	$03		; SJMP		  _scr_8DD2
		.WORD	_scr_8DD2

; =============== S U B	R O U T	I N E =======================================
_nsub_8DDD:
		LDA		_tmp7B7
		BPL		loc_8DE4
		CLC
		RTS
loc_8DE4:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_8DE6:
		LDX		_scr_cur_trd_idx
		LDA		_tmp7B7
		CMP		_scr_trds_args0,X
		BEQ		loc_8DF1
		CLC
		RTS
loc_8DF1:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_8DF3:
		LDA		_tmp7B8
		BPL		loc_8DFA
		CLC
		RTS
loc_8DFA:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_8DFC:
		LDX		_scr_cur_trd_idx
		LDA		_tmp7B8
		CMP		_scr_trds_args0,X
		BEQ		loc_8E07
		CLC
		RTS
loc_8E07:
		SEC
		RTS
_sjmp_case_8E09:
		.BYTE	$0F,$00,$01	; SARG_SET	  $00,$01
		.BYTE	$0F,$01,$2C	; SARG_SET	  $01,$2C
		.BYTE	$20,$2D		; SPR_IDX_SET	  0,$2D
		.BYTE	$03		; SJMP		  _ssub_8CD5
		.WORD	_ssub_8CD5
_sjmp_case_8E14:
		.BYTE	$0F,$00,$02	; SARG_SET	  $00,$02
		.BYTE	$0F,$01,$14	; SARG_SET	  $01,$14
		.BYTE	$20,$15		; SPR_IDX_SET	  0,$15
		.BYTE	$03		; SJMP		  _ssub_8CD5
		.WORD	_ssub_8CD5
_sjmp_case_8E1F:
		.BYTE	$0F,$00,$03	; SARG_SET	  $00,$03
		.BYTE	$0F,$01,$20	; SARG_SET	  $01,$20
		.BYTE	$20,$21		; SPR_IDX_SET	  0,$21
		.BYTE	$03		; SJMP		  _ssub_8CD5
		.WORD	_ssub_8CD5
_sjmp_case_8E2A:
		.BYTE	$0F,$00,$04	; SARG_SET	  $00,$04
		.BYTE	$0F,$01,$38	; SARG_SET	  $01,$38
		.BYTE	$20,$34		; SPR_IDX_SET	  0,$34
_sloc_8E32:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_8DDD
		.WORD	_nsub_8DDD
		.BYTE	$0C		; SBCC		  _sloc_8E32
		.WORD	_sloc_8E32
		.BYTE	$07		; NJSR		  _nsub_8DE6
		.WORD	_nsub_8DE6
		.BYTE	$0B		; SBCS		  _sloc_8E4F
		.WORD	_sloc_8E4F
_sloc_8E40:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_8DF3
		.WORD	_nsub_8DF3
		.BYTE	$0C		; SBCC		  _sloc_8E40
		.WORD	_sloc_8E40
		.BYTE	$07		; NJSR		  _nsub_8DFC
		.WORD	_nsub_8DFC
		.BYTE	$0B		; SBCS		  _sloc_8E55
		.WORD	_sloc_8E55
		.BYTE	$0A		; SUSPEND
_sloc_8E4F:
		.BYTE	$04		; SJSR		  _ssub_8E5B
		.WORD	_ssub_8E5B
		.BYTE	$03		; SJMP		  _sloc_8D2E
		.WORD	_sloc_8D2E
_sloc_8E55:
		.BYTE	$04		; SJSR		  _ssub_8E5B
		.WORD	_ssub_8E5B
		.BYTE	$03		; SJMP		  _sloc_8D8D
		.WORD	_sloc_8D8D
_ssub_8E5B:
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$24,$38		; SPR_IDX_SET	  4,$38
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$AC,$02		; SPR_IDX_ADD_IMM 4,$02
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$50,$00,$FF	; POS_Y_DELTA_SET 0,$00,$FF
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$24,$35		; SPR_IDX_SET	  4,$35
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$AC,$02		; SPR_IDX_ADD_IMM 4,$02
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$38		; SPR_IDX_SET	  0,$38
		.BYTE	$05		; SRET
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
_scr_secret_menu:
		.BYTE	$07		; NJSR		  _nsub_secret_menu_init
		.WORD	_nsub_secret_menu_init
		.BYTE	$07		; NJSR		  _nsub_62B40
		.WORD	_nsub_62B40
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$FF
		.WORD	_nsub_apu_mus_load
		.BYTE	$FF
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$09
		.WORD	_nsub_far_prg0_tlm_lib_unpack ; secret_menu
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_8FED
		.WORD	_nsub_8FED
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$05
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_bg_pal_load,byte_8F70
		.WORD	_nsub_bg_pal_load
		.WORD	byte_8F70
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_8F80
		.WORD	_nbgsub_8F80
_sloc_8F5C:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_secret_menu_UD_input
		.WORD	_nsub_secret_menu_UD_input
		.BYTE	$07		; NJSR		  _nsub_secret_menu_LR_input
		.WORD	_nsub_secret_menu_LR_input
		.BYTE	$07		; NJSR		  _nsub_91AF
		.WORD	_nsub_91AF
		.BYTE	$03		; SJMP		  _sloc_8F5C
		.WORD	_sloc_8F5C
_scr_8F6A:
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$03		; SJMP		  _sloc_805E
		.WORD	_sloc_805E
byte_8F70:
		.BYTE	$0F,$11,$11,$11,$0F,$30,$30,$30,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F

; =============== S U B	R O U T	I N E =======================================
_nbgsub_8F80:
		LDA		_pad0_pressed
		AND		#$10
		BEQ		locret_8FAA
		LDX		_menu_controls_idx
		LDA		_ab_controls_,X
		STA		_control_jump_button_code
		LDA		_ba_controls_,X
		STA		_control_fire_button_code
		LDA		_menu_difficulty_idx
		STA		_difficulty
		LDA		#$FF
		JSR		_far_prg6_apu_mus_load
		LDA		#$FF
		JSR		_far_prg6_apu_snd_load
		JSR		_script_load_param
		.WORD	_scr_8F6A
locret_8FAA:
		RTS
_ab_controls_:
		.BYTE	$80,$40
_ba_controls_:
		.BYTE	$40,$80

; =============== S U B	R O U T	I N E =======================================
_nsub_secret_menu_init:
		LDX		#$00
		STX		_cur_room_doors_cnt
		STX		_menu_controls_idx
		STX		_sound_test_mus_idx
		STX		_sound_test_ssnd_idx
		INX
		STX		_menu_difficulty_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_secret_menu_UD_input:
		LDA		_pad0_pressed
		AND		#$08
		BEQ		loc_8FD4
		LDA		_cur_room_doors_cnt
		SEC
		SBC		#$01
		BPL		loc_8FE6
		LDA		#$03
		BNE		loc_8FE6
loc_8FD4:
		LDA		_pad0_pressed
		AND		#$04
		BEQ		locret_8FEC
		LDA		_cur_room_doors_cnt
		CLC
		ADC		#$01
		CMP		#$04
		BCC		loc_8FE6
		LDA		#$00
loc_8FE6:
		STA		_cur_room_doors_cnt
		JMP		_nsub_8FED
locret_8FEC:
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_8FED:
		JSR		_ppu_res_send_param_repeat_no_ofs_0
		.WORD	word_9004
		JSR		_wait_for_nmi
		LDX		_cur_room_doors_cnt
		LDA		off_9009,X
		LDY		off_900D,X
		JSR		_ppu_res_send_ptr_repeat
		JMP		_wait_for_nmi
word_9004:
		.WORD	$23C8
		.BYTE	$20,$02
		.BYTE	$00
off_9009:
		.BYTE	<[word_9011]
		.BYTE	<[word_9016]
		.BYTE	<[word_901B]
		.BYTE	<[word_9020]
off_900D:
		.BYTE	>[word_9011]
		.BYTE	>[word_9016]
		.BYTE	>[word_901B]
		.BYTE	>[word_9020]
word_9011:
		.WORD	$23C8
		.BYTE	$08,$01
		.BYTE	$55
word_9016:
		.WORD	$23D0
		.BYTE	$18,$01
		.BYTE	$55
word_901B:
		.WORD	$23E8
		.BYTE	$08,$01
		.BYTE	$05
word_9020:
		.WORD	$23E8
		.BYTE	$08,$01
		.BYTE	$50

; =============== S U B	R O U T	I N E =======================================
_nsub_secret_menu_LR_input:
		LDX		_cur_room_doors_cnt
		LDA		_pad0_pressed
		AND		#$02
		BEQ		loc_903B
		LDA		_menu_controls_idx,X
		SEC
		SBC		#$01
		BPL		loc_9050
		LDA		byte_9057,X
		BNE		loc_9050
loc_903B:
		LDA		_pad0_pressed
		AND		#$01
		BEQ		locret_9056
		LDA		_menu_controls_idx,X
		CLC
		ADC		#$01
		CMP		byte_9057,X
		BCC		loc_9050
		BEQ		loc_9050
		LDA		#$00
loc_9050:
		STA		_menu_controls_idx,X
		JSR		_menu_update_draw
locret_9056:
		RTS
byte_9057:
		.BYTE	$01,$03,$0C,$23

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
_tlm_ab_controls:
		.WORD	$20EA
		.BYTE	$0E,$01
		.BYTE	"A-BEAM  B-TRAP"
_tlm_ba_controls:
		.WORD	$20EA
		.BYTE	$0E,$01
		.BYTE	"B-BEAM  A-TRAP"

; =============== S U B	R O U T	I N E =======================================
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
word_90D1:
		.WORD	$216A
		.BYTE	$06,$01
		.BYTE	"EASY  "
word_90DB:
		.WORD	$216A
		.BYTE	$06,$01
		.BYTE	"NORMAL"
word_90E5:
		.WORD	$216A
		.BYTE	$06,$01
		.BYTE	"HARD  "
word_90EF:
		.WORD	$216A
		.BYTE	$06,$01
		.BYTE	"PRO   "
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
word_9101:
		.WORD	$21B4
		.BYTE	$01,$01
		.BYTE	"4"
word_9106:
		.WORD	$21B4
		.BYTE	$01,$01
		.BYTE	"3"
word_910B:
		.WORD	$21B4
		.BYTE	$01,$01
		.BYTE	"2"
word_9110:
		.WORD	$21B4
		.BYTE	$01,$01
		.BYTE	"1"
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

; =============== S U B	R O U T	I N E =======================================
_sound_test_mus_draw:
		LDA		_sound_test_mus_idx
		LDX		#$00
		JSR		_bin2dec
		LDX		#$07
		LDY		#$15
		JMP		_printfd

; =============== S U B	R O U T	I N E =======================================
_sound_test_se_draw:
		LDA		_sound_test_ssnd_idx
		LDX		#$00
		JSR		_bin2dec
		LDX		#$07
		LDY		#$17
		JMP		_printfd

; =============== S U B	R O U T	I N E =======================================
_nsub_91AF:
		LDA		_pad0_pressed
		AND		#$80
		BEQ		loc_91D1
		LDA		_cur_room_doors_cnt
		CMP		#$02
		BNE		loc_91C2
		LDA		_sound_test_mus_idx
		JMP		_far_prg6_apu_mus_load
loc_91C2:
		CMP		#$03
		BNE		locret_91EC
		LDA		#$FF
		JSR		_far_prg6_apu_snd_load
		LDA		_sound_test_ssnd_idx
		JMP		_far_prg6_apu_snd_load
loc_91D1:
		LDA		_pad0_pressed
		AND		#$40
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
_scr7_ending:
		.BYTE	$07		; NJSR		  _nsub_obj_sarg_add_imm_test,$00,$FF
		.WORD	_nsub_obj_sarg_add_imm_test
		.BYTE	$00,$FF
		.BYTE	$11,$16		; SJMP_SW	  $16
		.WORD	_sjmp_case_971E	; CASE	  _sjmp_case_971E
		.WORD	_sjmp_case_97DD	; CASE	  _sjmp_case_97DD
		.WORD	_sjmp_case_98D0	; CASE	  _sjmp_case_98D0
		.WORD	_sjmp_case_9914	; CASE	  _sjmp_case_9914
		.WORD	_sjmp_case_99DB	; CASE	  _sjmp_case_99DB
		.WORD	_sjmp_case_9A58	; CASE	  _sjmp_case_9A58
		.WORD	_sjmp_case_9AD8	; CASE	  _sjmp_case_9AD8
		.WORD	_sjmp_case_9BAC	; CASE	  _sjmp_case_9BAC
		.WORD	_sjmp_case_A008	; CASE	  _sjmp_case_A008
		.WORD	_sjmp_case_A05B	; CASE	  _sjmp_case_A05B
		.WORD	_sjmp_case_A0AB	; CASE	  _sjmp_case_A0AB
		.WORD	_sjmp_case_A1B7	; CASE	  _sjmp_case_A1B7
		.WORD	_sjmp_case_A1EA	; CASE	  _sjmp_case_A1EA
		.WORD	_sjmp_case_A510	; CASE	  _sjmp_case_A510
		.WORD	_sjmp_case_A54B	; CASE	  _sjmp_case_A54B
		.WORD	_sjmp_case_A5DB	; CASE	  _sjmp_case_A5DB
		.WORD	_sjmp_case_A5F5	; CASE	  _sjmp_case_A5F5
		.WORD	_sjmp_case_A63A	; CASE	  _sjmp_case_A63A
		.WORD	_sjmp_case_A67F	; CASE	  _sjmp_case_A67F
		.WORD	_sjmp_case_A6C4	; CASE	  _sjmp_case_A6C4
		.WORD	_sjmp_case_A782	; CASE	  _sjmp_case_A782
		.WORD	_sjmp_case_A2E5	; CASE	  _sjmp_case_A2E5
		.BYTE	$13		; STORE8	  _scr_trds_priority_enable,$00
		.WORD	_scr_trds_priority_enable
		.BYTE	$00
		.BYTE	$06,$5A		; SDELAY	  $5A
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$09
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_62775,$00
		.WORD	_nsub_62775
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$07
		.WORD	_nsub_far_prg0_tlm_lib_unpack
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_9367
		.WORD	_nsub_full_pal_load
		.WORD	byte_9367
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$05
		.WORD	_nsub_apu_mus_load
		.BYTE	$05
		.BYTE	$06,$64		; SDELAY	  $64
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$28,$80,$00	; POS_X_SET	  0,$80,$00
		.BYTE	$30,$80,$00	; POS_Y_SET	  0,$80,$00
		.BYTE	$07		; NJSR		  _nsub_arg12_load_data_ofs,_script_chain_data2
		.WORD	_nsub_arg12_load_data_ofs
		.WORD	_script_chain_data2
_sloc_92E5:
		.BYTE	$07		; NJSR		  _nsub_9474
		.WORD	_nsub_9474
		.BYTE	$12,$04		; SJSR_SW	  $04
		.WORD	_sjsr_case_92F5	; CASE	  _sjsr_case_92F5
		.WORD	_sjsr_case_92F9	; CASE	  _sjsr_case_92F9
		.WORD	_sjsr_case_9304	; CASE	  _sjsr_case_9304
		.WORD	_sjsr_case_932D	; CASE	  _sjsr_case_932D
		.BYTE	$03		; SJMP		  _sloc_92E5
		.WORD	_sloc_92E5
_sjsr_case_92F5:
		.BYTE	$07		; NJSR		  _nsub_script_chain_start
		.WORD	_nsub_script_chain_start
		.BYTE	$05		; SRET
_sjsr_case_92F9:
		.BYTE	$07		; NJSR		  _nsub_9492
		.WORD	_nsub_9492
		.BYTE	$01,$10		; SLOOP_BEGIN	  $10
		.BYTE	$07		; NJSR		  _nsub_obj_delay_set_from_sarg,$02
		.WORD	_nsub_obj_delay_set_from_sarg
		.BYTE	$02
		.BYTE	$02		; SLOOP_END
		.BYTE	$05		; SRET
_sjsr_case_9304:
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$D0
		.WORD	_nsub_counters_dec
		.BYTE	$D0
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$0F,$02,$00	; SARG_SET	  $02,$00
		.BYTE	$01,$12		; SLOOP_BEGIN	  $12
		.BYTE	$07		; NJSR		  _nsub_9498
		.WORD	_nsub_9498
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_94CF
		.WORD	_nsub_94CF
_sloc_931B:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_94DA
		.WORD	_nsub_94DA
		.BYTE	$0C		; SBCC		  _sloc_931B
		.WORD	_sloc_931B
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$D0
		.WORD	_nsub_counters_inc
		.BYTE	$D0
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$05		; SRET
_sjsr_case_932D:
		.BYTE	$01,$15		; SLOOP_BEGIN	  $15
		.BYTE	$06,$3C		; SDELAY	  $3C
		.BYTE	$02		; SLOOP_END
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$D0
		.WORD	_nsub_counters_dec
		.BYTE	$D0
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$0F,$02,$00	; SARG_SET	  $02,$00
		.BYTE	$01,$12		; SLOOP_BEGIN	  $12
		.BYTE	$07		; NJSR		  _nsub_9498
		.WORD	_nsub_9498
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_bg_pal_load,byte_9387
		.WORD	_nsub_bg_pal_load
		.WORD	byte_9387
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$1C
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$1C
		.BYTE	$07		; NJSR		  _nsub_941F
		.WORD	_nsub_941F
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$D0
		.WORD	_nsub_counters_inc
		.BYTE	$D0
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_9413
		.WORD	_nbgsub_9413
		.BYTE	$0A		; SUSPEND
_scr_935F:
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$13		; STORE8	  _game_flags,$00
		.WORD	_game_flags
		.BYTE	$00
		.BYTE	$00		; STOP
byte_9367:
		.BYTE	$0F,$20,$15,$29,$0F,$20,$01,$29,$0F,$21,$11,$01,$0F,$20,$10,$00
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$37,$27,$17,$0F,$20,$10,$00
byte_9387:
		.BYTE	$0F,$20,$20,$20,$0F,$20,$20,$20,$0F,$21,$11,$01,$0F,$20,$20,$20
_script_chain_data2:
		.BYTE	$01,$AB,$13,$00,$80,$0A
		.WORD	byte_9402
		.BYTE	$07,$00,$80,$1A,$81
		.WORD	off_94FD
		.BYTE	$03,$80,$10,$00,$04,$7F,$0C,$00,$80,$1E,$81
		.WORD	off_9506
		.BYTE	$05,$80,$08,$00,$06,$80,$10,$00,$07,$80,$0C,$00,$80,$20,$81
		.WORD	off_950F
		.BYTE	$80,$20,$81
		.WORD	off_951A
		.BYTE	$08,$88,$C0,$00,$09,$98,$10,$00,$0A,$68,$10,$00,$80,$20,$81
		.WORD	off_951F
		.BYTE	$80,$20,$81
		.WORD	off_9524
		.BYTE	$0B,$78,$10,$00,$80,$06,$0D,$78,$18,$00,$80,$20,$81
		.WORD	off_9533
		.BYTE	$80,$20,$16,$00,$00,$00,$80,$08,$0E,$A8,$08,$00,$0F,$58,$08,$00
		.BYTE	$11,$88,$28,$00
byte_9402:
		.BYTE	$12,$78,$28,$00,$13,$78,$28,$00,$14,$88,$28,$00,$15,$00,$E0,$00
		.BYTE	$82

; =============== S U B	R O U T	I N E =======================================
_nbgsub_9413:
		LDA		_pad0_pressed
		AND		#$10
		BEQ		locret_941E
		JSR		_script_load_param
		.WORD	_scr_935F
locret_941E:
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_941F:
		LDA		#$FF
		STA		_scores_to_next_live
		STA		_scores_to_next_live+1
		LDA		_lives
		BEQ		loc_9436
loc_942C:
		LDA		#$64
		JSR		_scores_add
		DEC		_lives
		BNE		loc_942C
loc_9436:
		JSR		_ppu_res_send_param
		.WORD	_res_top_score
		JSR		_ppu_res_send_param
		.WORD	_res_score
		LDX		#$11
		LDY		#$07
		JSR		_printf_hi_scores
		LDX		#$0F
		LDY		#$0F
		JMP		_printf_scores
_res_top_score:
		.WORD	$20E7
		.BYTE	$11,$01
		.BYTE	"TOP SCORE      00"
_res_score:
		.WORD	$21E9
		.BYTE	$0D,$01
		.BYTE	"SCORE      00"

; =============== S U B	R O U T	I N E =======================================
_nsub_9474:
		LDA		_scr_trds_args0
		STA		_ptr06
		LDA		_scr_trds_args1
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		BMI		loc_9484
		TYA
		RTS
loc_9484:
		AND		#$7F
		CLC
		ADC		#$01
		PHA
		INC		_scr_trds_args0
		BNE		loc_9490
		INC		_scr_trds_args1	; *--
loc_9490:
		PLA
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_9492:
		JSR		sub_94BC
		STA		_scr_trds_args2
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_9498:
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

; =============== S U B	R O U T	I N E =======================================
sub_94BC:
		LDA		_scr_trds_args0
		STA		_ptr06
		LDA		_scr_trds_args1
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		INC		_scr_trds_args0
		BNE		locret_94CE
		INC		_scr_trds_args1	; *--
locret_94CE:
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_94CF:
		JSR		sub_94BC
		STA		_lvl_room_lib_ptr
		JSR		sub_94BC
		STA		_lvl_room_lib_ptr+1
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_94DA:
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
off_94FD:
		.BYTE	>[_res_executive_producer]
		.BYTE	<[_res_executive_producer]
		.BYTE	>[_res_tsuyoshi_ikeda]
		.BYTE	<[_res_tsuyoshi_ikeda]
		.BYTE	>[_res_producer]
		.BYTE	<[_res_producer]
		.BYTE	>[_res_miko_ikeda]
		.BYTE	<[_res_miko_ikeda]
		.BYTE	$00
off_9506:
		.BYTE	>[_res_director]
		.BYTE	<[_res_director]
		.BYTE	>[_res_gsx_suga]
		.BYTE	<[_res_gsx_suga]
		.BYTE	>[_res_assistant_director]
		.BYTE	<[_res_assistant_director]
		.BYTE	>[_res_osamu_kobiyama]
		.BYTE	<[_res_osamu_kobiyama]
		.BYTE	$00
off_950F:
		.BYTE	>[_res_designer]
		.BYTE	<[_res_designer]
		.BYTE	>[_res_shigeru_hashiguchi]
		.BYTE	<[_res_shigeru_hashiguchi]
		.BYTE	>[_res_tsuyoshi_wakayama]
		.BYTE	<[_res_tsuyoshi_wakayama]
		.BYTE	>[_res_programmer]
		.BYTE	<[_res_programmer]
		.BYTE	>[_res_gsx_suga_0]
		.BYTE	<[_res_gsx_suga_0]
		.BYTE	$00
off_951A:
		.BYTE	>[_res_sound_creator]
		.BYTE	<[_res_sound_creator]
		.BYTE	>[_res_jun_isikawa]
		.BYTE	<[_res_jun_isikawa]
		.BYTE	$00
off_951F:
		.BYTE	>[_res_technical_supervisor]
		.BYTE	<[_res_technical_supervisor]
		.BYTE	>[_res_satoru_iwate]
		.BYTE	<[_res_satoru_iwate]
		.BYTE	$00
off_9524:
		.BYTE	>[_res_special_thanks]
		.BYTE	<[_res_special_thanks]
		.BYTE	>[_res_makoto_kanai]
		.BYTE	<[_res_makoto_kanai]
		.BYTE	>[_res_satoshi_ishida]
		.BYTE	<[_res_satoshi_ishida]
		.BYTE	>[_res_hitoshi_kikkawa]
		.BYTE	<[_res_hitoshi_kikkawa]
		.BYTE	>[_res_takashi_saito]
		.BYTE	<[_res_takashi_saito]
		.BYTE	>[_res_satoshi_mitsuhara]
		.BYTE	<[_res_satoshi_mitsuhara]
		.BYTE	>[_res_mitsuru_kakuta]
		.BYTE	<[_res_mitsuru_kakuta]
		.BYTE	$00
off_9533:
		.BYTE	>[_res_and]
		.BYTE	<[_res_and]
		.BYTE	>[_res_all_test_players]
		.BYTE	<[_res_all_test_players]
		.BYTE	>[_res_and_0]
		.BYTE	<[_res_and_0]
		.BYTE	>[_res_you_too]
		.BYTE	<[_res_you_too]
		.BYTE	>[_res_by_hal_laboratory]
		.BYTE	<[_res_by_hal_laboratory]
		.BYTE	$00
_res_executive_producer:
		.WORD	$2065
		.BYTE	$12,$01
		.BYTE	"EXECUTIVE PRODUCER"
_res_tsuyoshi_ikeda:
		.WORD	$20AD
		.BYTE	$0E,$01
		.BYTE	"TSUYOSHI IKEDA"
_res_producer:
		.WORD	$2125
		.BYTE	$08,$01
		.BYTE	"PRODUCER"
_res_miko_ikeda:
		.WORD	$2170
		.BYTE	$0B,$01
		.BYTE	"MIKIO IKEDA"
_res_director:
		.WORD	$2065
		.BYTE	$08,$01
		.BYTE	"DIRECTOR"
_res_gsx_suga:
		.WORD	$20B3
		.BYTE	$08,$01
		.BYTE	"GSX SUGA"
_res_assistant_director:
		.WORD	$2125
		.BYTE	$12,$01
		.BYTE	"ASSISTANT DIRECTOR"
_res_osamu_kobiyama:
		.WORD	$216D
		.BYTE	$0E,$01
		.BYTE	"OSAMU KOBIYAMA"
_res_designer:
		.WORD	$2065
		.BYTE	$08,$01
		.BYTE	"DESIGNER"
_res_shigeru_hashiguchi:
		.WORD	$20A9
		.BYTE	$12,$01
		.BYTE	"SHIGERU HASHIGUCHI"
_res_tsuyoshi_wakayama:
		.WORD	$20E9
		.BYTE	$11,$01
		.BYTE	"TSUYOSHI WAKAYAMA"
_res_programmer:
		.WORD	$2165
		.BYTE	$0A,$01
		.BYTE	"PROGRAMMER"
_res_gsx_suga_0:
		.WORD	$21B3
		.BYTE	$08,$01
		.BYTE	"GSX SUGA"
_res_sound_creator:
		.WORD	$2065
		.BYTE	$0D,$01
		.BYTE	"SOUND CREATOR"
_res_jun_isikawa:
		.WORD	$20AF
		.BYTE	$0C,$01
		.BYTE	"JUN ISHIKAWA"
_res_technical_supervisor:
		.WORD	$2065
		.BYTE	$14,$01
		.BYTE	"TECHNICAL SUPERVISOR"
_res_satoru_iwate:
		.WORD	$20AF
		.BYTE	$0C,$01
		.BYTE	"SATORU IWATA"
_res_special_thanks:
		.WORD	$2065
		.BYTE	$0E,$01
		.BYTE	"SPECIAL THANKS"
_res_makoto_kanai:
		.WORD	$20AB
		.BYTE	$0C,$01
		.BYTE	"MAKOTO KANAI"
_res_satoshi_ishida:
		.WORD	$20EA
		.BYTE	$0E,$01
		.BYTE	"SATOSHI ISHIDA"
_res_hitoshi_kikkawa:
		.WORD	$212A
		.BYTE	$0F,$01
		.BYTE	"HITOSHI KIKKAWA"
_res_takashi_saito:
		.WORD	$216A
		.BYTE	$0D,$01
		.BYTE	"TAKASHI SAITO"
_res_satoshi_mitsuhara:
		.WORD	$21AA
		.BYTE	$11,$01
		.BYTE	"SATOSHI MITSUHARA"
_res_mitsuru_kakuta:
		.WORD	$21EA
		.BYTE	$0E,$01
		.BYTE	"MITSURU KAKUTA"
_res_and:
		.WORD	$208E
		.BYTE	$03,$01
		.BYTE	"AND"
_res_all_test_players:
		.WORD	$20E8
		.BYTE	$11,$01
		.BYTE	"ALL TEST PLAYERS,"
_res_and_0:
		.WORD	$214E
		.BYTE	$03,$01
		.BYTE	"AND"
_res_you_too:
		.WORD	$21AC
		.BYTE	$08,$01
		.BYTE	"YOU TOO/"
_res_by_hal_laboratory:
		.WORD	$2267
		.BYTE	$11,$01
		.BYTE	"BY HAL LABORATORY"
_sjmp_case_971E:
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$19
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$19
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$26,$00		; SPR_IDX_SET	  6,$00
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$02		; SPR_IDX_SET	  6,$02
		.BYTE	$02		; SLOOP_END
		.BYTE	$26,$00		; SPR_IDX_SET	  6,$00
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$03		; SPR_IDX_SET	  0,$03
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$02		; SLOOP_END
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$05		; SPR_IDX_SET	  0,$05
		.BYTE	$06,$0A		; SDELAY	  $0A
		.BYTE	$20,$06		; SPR_IDX_SET	  0,$06
		.BYTE	$56,$00,$FE	; POS_Y_DELTA_SET 6,$00,$FE
		.BYTE	$56,$00,$02	; POS_Y_DELTA_SET 6,$00,$02
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$26,$05		; SPR_IDX_SET	  6,$05
		.BYTE	$26,$03		; SPR_IDX_SET	  6,$03
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$26,$00		; SPR_IDX_SET	  6,$00
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$02		; SPR_IDX_SET	  6,$02
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_97DD:
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$20,$08		; SPR_IDX_SET	  0,$08
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$02		; SLOOP_END
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$0B		; SDELAY	  $0B
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$14		; SLOOP_BEGIN	  $14
		.BYTE	$22,$0A		; SPR_IDX_SET	  2,$0A
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_98D0:
		.BYTE	$07		; NJSR		  _nsub_626B7,$06,byte_9910
		.WORD	_nsub_626B7
		.BYTE	$06
		.WORD	byte_9910
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$20,$4D		; SPR_IDX_SET	  0,$4D
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$4F		; SPR_IDX_SET	  0,$4F
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$02		; SLOOP_END
		.BYTE	$20,$4D		; SPR_IDX_SET	  0,$4D
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$60		; SDELAY	  $60
		.BYTE	$20,$4A		; SPR_IDX_SET	  0,$4A
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$47		; SPR_IDX_SET	  0,$47
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$24,$4A		; SPR_IDX_SET	  4,$4A
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$24,$4D		; SPR_IDX_SET	  4,$4D
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$4F		; SPR_IDX_SET	  4,$4F
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
byte_9910:
		.BYTE	$0F,$36,$2B,$0F
_sjmp_case_9914:
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$20,$0E		; SPR_IDX_SET	  0,$0E
		.BYTE	$06,$78		; SDELAY	  $78
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$B0		; SDELAY	  $B0
		.BYTE	$20,$10		; SPR_IDX_SET	  0,$10
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$01,$0E		; SLOOP_BEGIN	  $0E
		.BYTE	$24,$0E		; SPR_IDX_SET	  4,$0E
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$02		; SLOOP_END
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$24,$12		; SPR_IDX_SET	  4,$12
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_99DB:
		.BYTE	$06,$60		; SDELAY	  $60
		.BYTE	$48,$40,$01	; POS_X_DELTA_SET 0,$40,$01
		.BYTE	$01,$0C		; SLOOP_BEGIN	  $0C
		.BYTE	$24,$18		; SPR_IDX_SET	  4,$18
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$19		; SPR_IDX_SET	  4,$19
		.BYTE	$24,$17		; SPR_IDX_SET	  4,$17
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$28,$00,$01	; POS_X_SET	  0,$00,$01
		.BYTE	$48,$C0,$FE	; POS_X_DELTA_SET 0,$C0,$FE
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$24,$1D		; SPR_IDX_SET	  4,$1D
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$1F		; SPR_IDX_SET	  4,$1F
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$1A		; SPR_IDX_SET	  0,$1A
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$20,$50		; SPR_IDX_SET	  0,$50
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$02		; SLOOP_END
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$20,$50		; SPR_IDX_SET	  0,$50
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$20,$1A		; SPR_IDX_SET	  0,$1A
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$48,$40,$01	; POS_X_DELTA_SET 0,$40,$01
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$24,$17		; SPR_IDX_SET	  4,$17
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$19		; SPR_IDX_SET	  4,$19
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_9A58:
		.BYTE	$06,$70		; SDELAY	  $70
		.BYTE	$48,$40,$01	; POS_X_DELTA_SET 0,$40,$01
		.BYTE	$01,$0C		; SLOOP_BEGIN	  $0C
		.BYTE	$24,$24		; SPR_IDX_SET	  4,$24
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$25		; SPR_IDX_SET	  4,$25
		.BYTE	$24,$23		; SPR_IDX_SET	  4,$23
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$28,$00,$01	; POS_X_SET	  0,$00,$01
		.BYTE	$40,$F8		; POS_Y_MOVE	  0,$F8
		.BYTE	$48,$C0,$FE	; POS_X_DELTA_SET 0,$C0,$FE
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$24,$29		; SPR_IDX_SET	  4,$29
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$2B		; SPR_IDX_SET	  4,$2B
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$26		; SPR_IDX_SET	  0,$26
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$20,$54		; SPR_IDX_SET	  0,$54
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$02		; SLOOP_END
		.BYTE	$20,$55		; SPR_IDX_SET	  0,$55
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$20,$53		; SPR_IDX_SET	  0,$53
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$20,$26		; SPR_IDX_SET	  0,$26
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$48,$40,$01	; POS_X_DELTA_SET 0,$40,$01
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$24,$23		; SPR_IDX_SET	  4,$23
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$A4		; SPR_IDX_DEC	  4
		.BYTE	$24,$25		; SPR_IDX_SET	  4,$25
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_9AD8:
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$04		; SJSR		  _ssub_9B0B
		.WORD	_ssub_9B0B
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$06,$58		; SDELAY	  $58
		.BYTE	$28,$00,$01	; POS_X_SET	  0,$00,$01
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$20,$5A		; SPR_IDX_SET	  0,$5A
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$06,$18		; SDELAY	  $18
		.BYTE	$28,$00,$00	; POS_X_SET	  0,$00,$00
		.BYTE	$40,$14		; POS_Y_MOVE	  0,$14
		.BYTE	$04		; SJSR		  _ssub_9B0B
		.WORD	_ssub_9B0B
		.BYTE	$00		; STOP
_ssub_9B0B:
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$48,$00,$02	; POS_X_DELTA_SET 0,$00,$02
		.BYTE	$20,$56		; SPR_IDX_SET	  0,$56
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$48,$00,$02	; POS_X_DELTA_SET 0,$00,$02
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$02		; SLOOP_END
		.BYTE	$05		; SRET
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
_sjmp_case_9BAC:
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_9C20
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_9C20
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$48,$C0,$00	; POS_X_DELTA_SET 0,$C0,$00
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$24,$C0		; SPR_IDX_SET	  4,$C0
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$02		; SLOOP_END
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$24,$C0		; SPR_IDX_SET	  4,$C0
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$02		; SLOOP_END
		.BYTE	$02		; SLOOP_END
		.BYTE	$24,$C0		; SPR_IDX_SET	  4,$C0
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$24,$C8		; SPR_IDX_SET	  4,$C8
		.BYTE	$01,$09		; SLOOP_BEGIN	  $09
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$02		; SLOOP_END
		.BYTE	$50,$80,$00	; POS_Y_DELTA_SET 0,$80,$00
		.BYTE	$26,$CE		; SPR_IDX_SET	  6,$CE
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$02		; SLOOP_END
		.BYTE	$01,$11		; SLOOP_BEGIN	  $11
		.BYTE	$22,$D2		; SPR_IDX_SET	  2,$D2
		.BYTE	$22,$C8		; SPR_IDX_SET	  2,$C8
		.BYTE	$02		; SLOOP_END
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$24,$C8		; SPR_IDX_SET	  4,$C8
		.BYTE	$20,$D2		; SPR_IDX_SET	  0,$D2
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$02		; SLOOP_END
		.BYTE	$20,$C8		; SPR_IDX_SET	  0,$C8
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$22,$D2		; SPR_IDX_SET	  2,$D2
		.BYTE	$20,$C8		; SPR_IDX_SET	  0,$C8
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$50,$C0,$00	; POS_Y_DELTA_SET 0,$C0,$00
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$04		; SJSR		  _ssub_9C15
		.WORD	_ssub_9C15
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$04		; SJSR		  _ssub_9C15
		.WORD	_ssub_9C15
		.BYTE	$02		; SLOOP_END
		.BYTE	$48,$C0,$00	; POS_X_DELTA_SET 0,$C0,$00
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$04		; SJSR		  _ssub_9C15
		.WORD	_ssub_9C15
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_ssub_9C15:
		.BYTE	$24,$C5		; SPR_IDX_SET	  4,$C5
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$24,$C0		; SPR_IDX_SET	  4,$C0
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$9C		; SPR_IDX_INC	  4
		.BYTE	$05		; SRET
byte_9C20:
		.BYTE	$0F,$36,$2B,$0F
_spr_lib07_00:
		.BYTE	$01
		.WORD	_spr_lib07_00_A
_spr_lib07_01:
		.BYTE	$01
		.WORD	_spr_lib07_01_A
_spr_lib07_02:
		.BYTE	$01
		.WORD	_spr_lib07_02_A
_spr_lib07_03:
		.BYTE	$01
		.WORD	_spr_lib07_03_A
_spr_lib07_04:
		.BYTE	$01
		.WORD	_spr_lib07_04_A
_spr_lib07_05:
		.BYTE	$01
		.WORD	_spr_lib07_05_A
_spr_lib07_06:
		.BYTE	$01
		.WORD	_spr_lib07_06_A
_spr_lib07_07:
		.BYTE	$01
		.WORD	_spr_lib07_07_A
_spr_lib07_08:
		.BYTE	$01
		.WORD	_spr_lib07_08_A
_spr_lib07_09:
		.BYTE	$01
		.WORD	_spr_lib07_09_A
_spr_lib07_0A:
		.BYTE	$01
		.WORD	_spr_lib07_0A_A
_spr_lib07_0B:
		.BYTE	$01
		.WORD	_spr_lib07_0B_A
_spr_lib07_0C:
		.BYTE	$01
		.WORD	_spr_lib07_0C_A
_spr_lib07_0D:
		.BYTE	$01
		.WORD	_spr_lib07_0D_A
_spr_lib07_0E:
		.BYTE	$01
		.WORD	_spr_lib07_0E_A
_spr_lib07_0F:
		.BYTE	$01
		.WORD	_spr_lib07_0F_A
_spr_lib07_10:
		.BYTE	$01
		.WORD	_spr_lib07_10_A
_spr_lib07_11:
		.BYTE	$01
		.WORD	_spr_lib07_11_A
_spr_lib07_12:
		.BYTE	$01
		.WORD	_spr_lib07_12_A
_spr_lib07_00_A:
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
_spr_lib07_01_A:
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
_spr_lib07_02_A:
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
_spr_lib07_03_A:
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
_spr_lib07_04_A:
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
_spr_lib07_05_A:
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
_spr_lib07_06_A:
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
_spr_lib07_07_A:
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
_spr_lib07_08_A:
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
_spr_lib07_09_A:
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
_spr_lib07_0A_A:
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
_spr_lib07_0B_A:
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
_spr_lib07_0C_A:
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
_spr_lib07_0D_A:
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
_spr_lib07_0E_A:
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
_spr_lib07_0F_A:
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
_spr_lib07_10_A:
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
_spr_lib07_11_A:
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
_spr_lib07_12_A:
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
_sjmp_case_A008:
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$26,$2F		; SPR_IDX_SET	  6,$2F
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$31		; SPR_IDX_SET	  6,$31
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$2C		; SPR_IDX_SET	  0,$2C
		.BYTE	$06,$D0		; SDELAY	  $D0
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$26,$35		; SPR_IDX_SET	  6,$35
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$37		; SPR_IDX_SET	  6,$37
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$2C		; SPR_IDX_SET	  0,$2C
		.BYTE	$06,$60		; SDELAY	  $60
		.BYTE	$20,$2F		; SPR_IDX_SET	  0,$2F
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$20,$2C		; SPR_IDX_SET	  0,$2C
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$2F		; SPR_IDX_SET	  0,$2F
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$2C		; SPR_IDX_SET	  0,$2C
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$20,$5E		; SPR_IDX_SET	  0,$5E
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$24,$2C		; SPR_IDX_SET	  4,$2C
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$26,$35		; SPR_IDX_SET	  6,$35
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$37		; SPR_IDX_SET	  6,$37
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_5E:
		.BYTE	$04
		.BYTE	$E8,$1C,$60,$00
		.BYTE	$E8,$1C,$20,$F8
		.BYTE	$F5,$5E,$23,$00
		.BYTE	$F5,$5E,$23,$FB
_sjmp_case_A05B:
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$26,$41		; SPR_IDX_SET	  6,$41
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$43		; SPR_IDX_SET	  6,$43
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$38		; SPR_IDX_SET	  0,$38
		.BYTE	$06,$D0		; SDELAY	  $D0
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$26,$3B		; SPR_IDX_SET	  6,$3B
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$38		; SPR_IDX_SET	  0,$38
		.BYTE	$06,$6C		; SDELAY	  $6C
		.BYTE	$20,$41		; SPR_IDX_SET	  0,$41
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$20,$38		; SPR_IDX_SET	  0,$38
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$41		; SPR_IDX_SET	  0,$41
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$38		; SPR_IDX_SET	  0,$38
		.BYTE	$06,$50		; SDELAY	  $50
		.BYTE	$20,$5F		; SPR_IDX_SET	  0,$5F
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$24,$38		; SPR_IDX_SET	  4,$38
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$26,$3B		; SPR_IDX_SET	  6,$3B
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$3D		; SPR_IDX_SET	  6,$3D
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_5F:
		.BYTE	$04
		.BYTE	$E8,$1E,$60,$00
		.BYTE	$E8,$1E,$20,$F8
		.BYTE	$F5,$5E,$63,$F8
		.BYTE	$F5,$5E,$23,$00
_sjmp_case_A0AB:
		.BYTE	$48,$40,$FF	; POS_X_DELTA_SET 0,$40,$FF
		.BYTE	$01,$0E		; SLOOP_BEGIN	  $0E
		.BYTE	$27,$60		; SPR_IDX_SET	  7,$60
		.BYTE	$9F		; SPR_IDX_INC	  7
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$27,$60		; SPR_IDX_SET	  7,$60
		.BYTE	$9F		; SPR_IDX_INC	  7
		.BYTE	$02		; SLOOP_END
		.BYTE	$A0		; SPR_IDX_DEC	  0
		.BYTE	$56,$00,$FA	; POS_Y_DELTA_SET 6,$00,$FA
		.BYTE	$56,$00,$06	; POS_Y_DELTA_SET 6,$00,$06
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$07		; NJSR		  _nsub_script_start,$07,$00,$00,$0C,$00
		.WORD	_nsub_script_start
		.BYTE	$07,$00,$00,$0C,$00
		.BYTE	$20,$65		; SPR_IDX_SET	  0,$65
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$01,$02		; SLOOP_BEGIN	  $02
		.BYTE	$26,$65		; SPR_IDX_SET	  6,$65
		.BYTE	$26,$68		; SPR_IDX_SET	  6,$68
		.BYTE	$26,$67		; SPR_IDX_SET	  6,$67
		.BYTE	$26,$68		; SPR_IDX_SET	  6,$68
		.BYTE	$02		; SLOOP_END
		.BYTE	$48,$C0,$00	; POS_X_DELTA_SET 0,$C0,$00
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$27,$66		; SPR_IDX_SET	  7,$66
		.BYTE	$9F		; SPR_IDX_INC	  7
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$27,$68		; SPR_IDX_SET	  7,$68
		.BYTE	$48,$40,$FF	; POS_X_DELTA_SET 0,$40,$FF
		.BYTE	$01,$0E		; SLOOP_BEGIN	  $0E
		.BYTE	$27,$64		; SPR_IDX_SET	  7,$64
		.BYTE	$9F		; SPR_IDX_INC	  7
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$06,$A0		; SDELAY	  $A0
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$0F		; SLOOP_BEGIN	  $0F
		.BYTE	$27,$62		; SPR_IDX_SET	  7,$62
		.BYTE	$9F		; SPR_IDX_INC	  7
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_A1B7:
		.BYTE	$20,$69		; SPR_IDX_SET	  0,$69
		.BYTE	$4E,$00,$02	; POS_X_DELTA_SET 6,$00,$02
		.BYTE	$48,$C0,$00	; POS_X_DELTA_SET 0,$C0,$00
		.BYTE	$56,$00,$02	; POS_Y_DELTA_SET 6,$00,$02
		.BYTE	$4A,$00,$00	; POS_X_DELTA_SET 2,$00,$00
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$26,$FF		; SPR_IDX_SET	  6,$FF
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$06,$48		; SDELAY	  $48
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$06		; SDELAY	  $06
		.BYTE	$20,$69		; SPR_IDX_SET	  0,$69
		.BYTE	$48,$00,$FE	; POS_X_DELTA_SET 0,$00,$FE
		.BYTE	$50,$00,$FD	; POS_Y_DELTA_SET 0,$00,$FD
		.BYTE	$01,$66		; SLOOP_BEGIN	  $66
		.BYTE	$61,$0F,$00	; POS_Y_DELTA_ADD 1,$0F,$00
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_69:
		.BYTE	$02
		.BYTE	$F8,$BB,$23,$00
		.BYTE	$F8,$AB,$23,$F8
_sjmp_case_A1EA:
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$26,$4D		; SPR_IDX_SET	  6,$4D
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$4F		; SPR_IDX_SET	  6,$4F
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$4D		; SPR_IDX_SET	  0,$4D
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$21,$6B		; SPR_IDX_SET	  1,$6B
		.BYTE	$20,$6A		; SPR_IDX_SET	  0,$6A
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$20,$6B		; SPR_IDX_SET	  0,$6B
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$4D		; SPR_IDX_SET	  0,$4D
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$26,$6C		; SPR_IDX_SET	  6,$6C
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$26,$6D		; SPR_IDX_SET	  6,$6D
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$6F		; SPR_IDX_SET	  6,$6F
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$26,$6C		; SPR_IDX_SET	  6,$6C
		.BYTE	$26,$70		; SPR_IDX_SET	  6,$70
		.BYTE	$20,$4D		; SPR_IDX_SET	  0,$4D
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$48,$40,$FF	; POS_X_DELTA_SET 0,$40,$FF
		.BYTE	$01,$03		; SLOOP_BEGIN	  $03
		.BYTE	$26,$4D		; SPR_IDX_SET	  6,$4D
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$4F		; SPR_IDX_SET	  6,$4F
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$4D		; SPR_IDX_SET	  0,$4D
		.BYTE	$06,$70		; SDELAY	  $70
		.BYTE	$20,$6A		; SPR_IDX_SET	  0,$6A
		.BYTE	$06,$08		; SDELAY	  $08
		.BYTE	$26,$4D		; SPR_IDX_SET	  6,$4D
		.BYTE	$21,$4A		; SPR_IDX_SET	  1,$4A
		.BYTE	$48,$40,$01	; POS_X_DELTA_SET 0,$40,$01
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$25,$47		; SPR_IDX_SET	  5,$47
		.BYTE	$9D		; SPR_IDX_INC	  5
		.BYTE	$A5		; SPR_IDX_DEC	  5
		.BYTE	$25,$49		; SPR_IDX_SET	  5,$49
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_A2E5:
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$D0
		.WORD	_nsub_counters_dec
		.BYTE	$D0
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$0F,$02,$00	; SARG_SET	  $02,$00
		.BYTE	$01,$12		; SLOOP_BEGIN	  $12
		.BYTE	$07		; NJSR		  _nsub_tlm_raw_arg2_idx_line_draw,_title_image0
		.WORD	_nsub_tlm_raw_arg2_idx_line_draw
		.WORD	_title_image0
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_A316
		.WORD	_nsub_A316
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$14
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$14
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$00
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_626B7,$03,byte_A547
		.WORD	_nsub_626B7
		.BYTE	$03
		.WORD	byte_A547
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$D0
		.WORD	_nsub_counters_inc
		.BYTE	$D0
		.BYTE	$06,$04		; SDELAY	  $04
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP

; =============== S U B	R O U T	I N E =======================================
_nsub_A316:
		JSR		_ppu_res_send_param
		.WORD	word_A31C
		RTS
word_A31C:
		.WORD	$23C0
		.BYTE	$20,$02
		.BYTE	$AA,$FA,$FA,$FA,$FA,$FA,$FA,$AA,$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA,$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA
		.BYTE	$AA,$FF,$FF,$FF,$FF,$FF,$FF,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA
		.BYTE	$AA,$AA,$AA,$AA,$AA,$AA,$AA,$AA,$0A,$0A,$0A,$0A,$0A,$0A,$0A,$0A
_title_image0:
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
_sjmp_case_A510:
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$26,$74		; SPR_IDX_SET	  6,$74
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$76		; SPR_IDX_SET	  6,$76
		.BYTE	$02		; SLOOP_END
		.BYTE	$26,$74		; SPR_IDX_SET	  6,$74
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$4E,$C0,$00	; POS_X_DELTA_SET 6,$C0,$00
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$07		; NJSR		  _nsub_script_start,$07,$00,$00,$10,$00
		.WORD	_nsub_script_start
		.BYTE	$07,$00,$00,$10,$00
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$48,$40,$FF	; POS_X_DELTA_SET 0,$40,$FF
		.BYTE	$26,$7A		; SPR_IDX_SET	  6,$7A
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$06,$90		; SDELAY	  $90
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$08		; SLOOP_BEGIN	  $08
		.BYTE	$26,$74		; SPR_IDX_SET	  6,$74
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$76		; SPR_IDX_SET	  6,$76
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$26,$74		; SPR_IDX_SET	  6,$74
		.BYTE	$00		; STOP
byte_A547:
		.BYTE	$0F,$10,$05,$0F
_sjmp_case_A54B:
		.BYTE	$48,$80,$FF	; POS_X_DELTA_SET 0,$80,$FF
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$26,$AD		; SPR_IDX_SET	  6,$AD
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$AF		; SPR_IDX_SET	  6,$AF
		.BYTE	$02		; SLOOP_END
		.BYTE	$26,$AD		; SPR_IDX_SET	  6,$AD
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$48,$40,$FF	; POS_X_DELTA_SET 0,$40,$FF
		.BYTE	$26,$AF		; SPR_IDX_SET	  6,$AF
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$AD		; SPR_IDX_SET	  0,$AD
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$06,$80		; SDELAY	  $80
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$26,$B0		; SPR_IDX_SET	  6,$B0
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$B2		; SPR_IDX_SET	  6,$B2
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_A5DB:
		.BYTE	$28,$80,$00	; POS_X_SET	  0,$80,$00
		.BYTE	$30,$78,$00	; POS_Y_SET	  0,$78,$00
		.BYTE	$20,$B3		; SPR_IDX_SET	  0,$B3
		.BYTE	$50,$C0,$FF	; POS_Y_DELTA_SET 0,$C0,$FF
		.BYTE	$01,$7A		; SLOOP_BEGIN	  $7A
		.BYTE	$49,$08,$00	; POS_X_DELTA_SET 1,$08,$00
		.BYTE	$49,$F8,$FF	; POS_X_DELTA_SET 1,$F8,$FF
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_B3:
		.BYTE	$01
		.BYTE	$FC,$6E,$41,$FD
_sjmp_case_A5F5:
		.BYTE	$06,$06		; SDELAY	  $06
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$26,$80		; SPR_IDX_SET	  6,$80
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$82		; SPR_IDX_SET	  6,$82
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$83		; SPR_IDX_SET	  0,$83
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$20,$83		; SPR_IDX_SET	  0,$83
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$B4		; SPR_IDX_SET	  0,$B4
		.BYTE	$56,$00,$FD	; POS_Y_DELTA_SET 6,$00,$FD
		.BYTE	$56,$00,$03	; POS_Y_DELTA_SET 6,$00,$03
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$02		; SLOOP_END
		.BYTE	$20,$86		; SPR_IDX_SET	  0,$86
		.BYTE	$06,$80		; SDELAY	  $80
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$0E		; SLOOP_BEGIN	  $0E
		.BYTE	$26,$80		; SPR_IDX_SET	  6,$80
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$82		; SPR_IDX_SET	  6,$82
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_B4:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$F0,$0A,$40,$00
		.BYTE	$F0,$0A,$00,$F8
_sjmp_case_A63A:
		.BYTE	$06,$06		; SDELAY	  $06
		.BYTE	$48,$80,$FF	; POS_X_DELTA_SET 0,$80,$FF
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$26,$92		; SPR_IDX_SET	  6,$92
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$94		; SPR_IDX_SET	  6,$94
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$8F		; SPR_IDX_SET	  0,$8F
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$20,$8F		; SPR_IDX_SET	  0,$8F
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$B5		; SPR_IDX_SET	  0,$B5
		.BYTE	$56,$00,$FD	; POS_Y_DELTA_SET 6,$00,$FD
		.BYTE	$56,$00,$03	; POS_Y_DELTA_SET 6,$00,$03
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$02		; SLOOP_END
		.BYTE	$20,$92		; SPR_IDX_SET	  0,$92
		.BYTE	$06,$90		; SDELAY	  $90
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$26,$8C		; SPR_IDX_SET	  6,$8C
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$8E		; SPR_IDX_SET	  6,$8E
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_B5:
		.BYTE	$04
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$00,$5E,$00,$00
		.BYTE	$F0,$0C,$00,$F8
		.BYTE	$F0,$0C,$40,$00
_sjmp_case_A67F:
		.BYTE	$06,$40		; SDELAY	  $40
		.BYTE	$48,$80,$FF	; POS_X_DELTA_SET 0,$80,$FF
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$26,$9E		; SPR_IDX_SET	  6,$9E
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$A0		; SPR_IDX_SET	  6,$A0
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$9B		; SPR_IDX_SET	  0,$9B
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$07		; SLOOP_BEGIN	  $07
		.BYTE	$20,$9B		; SPR_IDX_SET	  0,$9B
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$B6		; SPR_IDX_SET	  0,$B6
		.BYTE	$56,$00,$FD	; POS_Y_DELTA_SET 6,$00,$FD
		.BYTE	$56,$00,$03	; POS_Y_DELTA_SET 6,$00,$03
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$02		; SLOOP_END
		.BYTE	$20,$9E		; SPR_IDX_SET	  0,$9E
		.BYTE	$06,$70		; SDELAY	  $70
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$26,$98		; SPR_IDX_SET	  6,$98
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$9A		; SPR_IDX_SET	  6,$9A
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
_spr_raw_lib07_B6:
		.BYTE	$04
		.BYTE	$00,$5E,$00,$00
		.BYTE	$00,$5E,$40,$F8
		.BYTE	$F0,$0E,$00,$F8
		.BYTE	$F0,$0E,$40,$00
_sjmp_case_A6C4:
		.BYTE	$06,$40		; SDELAY	  $40
		.BYTE	$48,$80,$00	; POS_X_DELTA_SET 0,$80,$00
		.BYTE	$01,$05		; SLOOP_BEGIN	  $05
		.BYTE	$26,$A4		; SPR_IDX_SET	  6,$A4
		.BYTE	$9E		; SPR_IDX_INC	  6
		.BYTE	$A6		; SPR_IDX_DEC	  6
		.BYTE	$26,$A6		; SPR_IDX_SET	  6,$A6
		.BYTE	$02		; SLOOP_END
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$20,$A7		; SPR_IDX_SET	  0,$A7
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$01,$06		; SLOOP_BEGIN	  $06
		.BYTE	$20,$A7		; SPR_IDX_SET	  0,$A7
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$20,$B7		; SPR_IDX_SET	  0,$B7
		.BYTE	$56,$00,$FD	; POS_Y_DELTA_SET 6,$00,$FD
		.BYTE	$56,$00,$03	; POS_Y_DELTA_SET 6,$00,$03
		.BYTE	$C0		; POS_MOVE_STOP	  0
		.BYTE	$02		; SLOOP_END
		.BYTE	$22,$B8		; SPR_IDX_SET	  2,$B8
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$20,$B8		; SPR_IDX_SET	  0,$B8
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$06,$E0		; SDELAY	  $E0
		.BYTE	$20,$A7		; SPR_IDX_SET	  0,$A7
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$A4		; SPR_IDX_SET	  0,$A4
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$26,$A7		; SPR_IDX_SET	  6,$A7
		.BYTE	$20,$AA		; SPR_IDX_SET	  0,$AA
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$A7		; SPR_IDX_SET	  0,$A7
		.BYTE	$06,$20		; SDELAY	  $20
		.BYTE	$20,$A4		; SPR_IDX_SET	  0,$A4
		.BYTE	$06,$30		; SDELAY	  $30
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$01,$09		; SLOOP_BEGIN	  $09
		.BYTE	$25,$A4		; SPR_IDX_SET	  5,$A4
		.BYTE	$9D		; SPR_IDX_INC	  5
		.BYTE	$A5		; SPR_IDX_DEC	  5
		.BYTE	$25,$A6		; SPR_IDX_SET	  5,$A6
		.BYTE	$02		; SLOOP_END
		.BYTE	$00		; STOP
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
_sjmp_case_A782:
		.BYTE	$20,$BC		; SPR_IDX_SET	  0,$BC
_sloc_A784:
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
		.BYTE	$01,$0C		; SLOOP_BEGIN	  $0C
		.BYTE	$07		; NJSR		  _nsub_A792
		.WORD	_nsub_A792
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$03		; SJMP		  _sloc_A784
		.WORD	_sloc_A784

; =============== S U B	R O U T	I N E =======================================
_nsub_A792:
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
		JMP		sub_62069
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
_spr_lib07:
		.WORD	_spr_lib07_00
		.WORD	_spr_lib07_01
		.WORD	_spr_lib07_02
		.WORD	_spr_lib07_03
		.WORD	_spr_lib07_04
		.WORD	_spr_lib07_05
		.WORD	_spr_lib07_06
		.WORD	_spr_lib07_07
		.WORD	_spr_lib07_08
		.WORD	_spr_lib07_09
		.WORD	_spr_lib07_0A
		.WORD	_spr_lib07_0B
		.WORD	_spr_lib07_0C
		.WORD	_spr_lib07_0D
		.WORD	_spr_lib07_0E
		.WORD	_spr_lib07_0F
		.WORD	_spr_lib07_10
		.WORD	_spr_lib07_11
		.WORD	_spr_lib07_12

; =============== S U B	R O U T	I N E =======================================
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
		LDA		_ptr_table,X
		STA		_ptr06
		LDA		_ptr_table+1,X
		STA		_ptr06+1
		LDA		_ofs_table,X
		STA		_ptr0A
		LDA		_ofs_table+1,X
		STA		_ptr0A+1
		JSR		_tlm_unpack
		JSR		_ppu_nmi_on
		JMP		_ppu_vblank_on
_ptr_table:
		.WORD	_tlm0_title_screen
_ofs_table:
		.WORD	$2000
		.WORD	_tlm1_score
		.WORD	$2000
		.WORD	_tlm2_busterselect
		.WORD	$2000
		.WORD	_tlm3_game_over
		.WORD	$2000
		.WORD	_tlm4_score_unused
		.WORD	$2000
		.WORD	_tlm5_kanji_unused
		.WORD	$2000
		.WORD	_tlm6_copyrights
		.WORD	$2000
		.WORD	_tlm7_staff
		.WORD	$2000
		.WORD	_tlm8_HAL
		.WORD	$2000
		.WORD	_tlm9_secret_menu
		.WORD	$2000

; =============== S U B	R O U T	I N E =======================================
_tlm_unpack:
		LDA		_ptr0A
		STA		_var2
		LDA		_ptr0A+1
		STA		_var3
loc_AE02:
		LDY		#$00
		LDA		(_ptr06),Y
		CMP		#$FF
		BNE		loc_AE0B
		RTS
loc_AE0B:
		AND		#$E0
		CMP		#$E0
		BNE		loc_AE2D
		LDA		(_ptr06),Y
		ASL
		ASL
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
		BNE		loc_AE3C
loc_AE2D:
		PHA
		LDA		(_ptr06),Y
		INY
		AND		#$1F
		CLC
		ADC		#$01
		STA		_ptr08
		LDA		#$00
		STA		_ptr08+1
loc_AE3C:
		PLA
		BPL		loc_AE42
		JMP		loc_AECC
loc_AE42:
		LDX		_ptr0A+1
		STX		_PPU_ADDR
		LDX		_ptr0A
		STX		_PPU_ADDR
		LDX		_ptr08+1
		STX		_var4
		LDX		_ptr08
		BNE		loc_AE56
		DEC		_var4
loc_AE56:
		CMP		#$20
		BEQ		loc_AE8D
		CMP		#$40
		BEQ		loc_AE9D
		CMP		#$60
		BEQ		loc_AEB9
loc_AE62:
		LDA		(_ptr06),Y
		INY
		BNE		loc_AE69
		INC		_ptr06+1	; *--
loc_AE69:
		STA		_PPU_DATA
		DEX
		BNE		loc_AE62
		DEC		_var4
		BPL		loc_AE62
loc_AE73:
		TYA
		CLC
		ADC		_ptr06
		STA		_ptr06
		BCC		loc_AE7D
		INC		_ptr06+1
loc_AE7D:
		LDA		_ptr0A
		CLC
		ADC		_ptr08
		STA		_ptr0A
		LDA		_ptr0A+1
		ADC		_ptr08+1
		STA		_ptr0A+1
		JMP		loc_AE02
loc_AE8D:
		LDA		(_ptr06),Y
		INY
loc_AE90:
		STA		_PPU_DATA
		DEX
		BNE		loc_AE90
		DEC		_var4
		BPL		loc_AE90
		JMP		loc_AE73
loc_AE9D:
		LDA		(_ptr06),Y
		INY
		STA		_PPU_DATA
		LDA		(_ptr06),Y
		DEY
		STA		_PPU_DATA
		DEX
		BNE		loc_AE9D
		DEC		_var4
		BPL		loc_AE9D
		INY
		INY
		ASL		_ptr08
		ROL		_ptr08+1
		JMP		loc_AE73
loc_AEB9:
		LDA		(_ptr06),Y
		INY
loc_AEBC:
		STA		_PPU_DATA
		CLC
		ADC		#$01
		DEX
		BNE		loc_AEBC
		DEC		_var4
		BPL		loc_AEBC
		JMP		loc_AE73
loc_AECC:
		PHA
		LDA		(_ptr06),Y
		INY
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
		BEQ		loc_AEFD
		CMP		#$A0
		BEQ		loc_AF0F
		CMP		#$C0
		BEQ		loc_AF24
loc_AEFD:
		JSR		sub_AF34
		JSR		sub_AF3F
		JSR		sub_AF56
		INC		_var1
		DEC		_ptr08+1
		BPL		loc_AEFD
		JMP		loc_AE02
loc_AF0F:
		JSR		sub_AF34
		JSR		sub_AF3F
		JSR		sub_AF79
		JSR		sub_AF56
		INC		_var1
		DEC		_ptr08+1
		BPL		loc_AF0F
		JMP		loc_AE02
loc_AF24:
		JSR		sub_AF34
		JSR		sub_AF8F
		JSR		sub_AF56
		DEC		_ptr08+1
		BPL		loc_AF24
		JMP		loc_AE02

; =============== S U B	R O U T	I N E =======================================
sub_AF34:
		LDX		_ptr08
		LDA		_ptr08+1
		BEQ		loc_AF3C
		LDX		#$00
loc_AF3C:
		STX		_tmp1
		RTS

; =============== S U B	R O U T	I N E =======================================
sub_AF3F:
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

; =============== S U B	R O U T	I N E =======================================
sub_AF56:
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

; =============== S U B	R O U T	I N E =======================================
sub_AF79:
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

; =============== S U B	R O U T	I N E =======================================
sub_AF8F:
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

		BANK_END 0,$C000
