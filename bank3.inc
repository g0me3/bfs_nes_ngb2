
		ORG $8000

		BANK_START $03

; =============== S C R I P T ===============================================
_scr1A_lvl1_boss_judges:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_2C148
		SPR_IDX_SET		0,$04
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG2,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_2C029
_sloc_2C014:
		SDELAY			$01
		NJSR			_nsub_mcmp
			NARGW		_ppu_scroll_pos_y
			NARGB		$00
		SBCC			_sloc_2C014
		STORE8			_cur_room_x_pageB,$00
		NJSR			_nsub_gen_threads_off_except_cur
		SJSR			_ssub_62E33

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_2C029:
		SPR_IDX_SET		4,$04
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
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
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_new_thread_start
			NARGB		$1A
			NARGB		$38,$40
			NARGB		$01
			NARGB		$00
		POS_X_MOVE	0,$C0
		POS_Y_MOVE		0,$40
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2C0CB
		SARG_SET		SARG1,$80
_sloc_2C054:
		NBG_HNDL_SET	_nbgsub_2C0D7
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2C0CF
		NJSR			_nsub_6273D
			NARGB		$09,$40
		SLOOP_BEGIN		$06
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 6,$FC
		SLOOP_END
		NJSR			_nsub_62ABE

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_scr_2C06C:
		NBG_HNDL_SET	_nbgsub_2C0D7
_sloc_2C06F:
		NJSR			_nsub_628D1
			NARGB		$00,$01
		NJSR			_nsub_6273D
			NARGB		$09,$40
		SLOOP_BEGIN		$02
		SDELAY			$06
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 0,$FC
		SLOOP_END
		NJSR			_nsub_62AEC
			NARGB		$10
		SJMP			_sloc_2C06F

; =============== S C R I P T ===============================================
_scr_2C089:
		NBG_HNDL_SET	_nbgsub_2C12E
		SLOOP_BEGIN		$3C
		SJSR			_ssub_2C0B5
		NJSR			_nsub_62BFD
		SBCS_BREAK	_sloc_2C054
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2C0D3
_sloc_2C0A1:
		SJSR			_ssub_2C0B5
		NJSR			_nsub_62BFD
		SBCC			_sloc_2C0A1
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sloc_2C054
		SCASE			_scr_2C0BF
		SCASE			_scr_2C0C5

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2C0B5:
		NJSR			_nsub_6273D
			NARGB		$09,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ===============================================
_scr_2C0BF:
		SARG_SET		SARG1,$15
		SJMP			_sloc_62E25

; =============== S C R I P T ===============================================
_scr_2C0C5:
		SARG_SET		SARG1,$17
		SJMP			_sloc_62E2C
byte_2C0CB:
		.BYTE	$0F,$31,$25,$0F
byte_2C0CF:
		.BYTE	$0F,$36,$22,$0F
byte_2C0D3:
		.BYTE	$0F,$25,$15,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_2C0D7:
		LDY		#$00
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,X
		CMP		#$10
		BCS		loc_2C0E5
		LDA		#$10
		BNE		loc_2C0EB
loc_2C0E5:
		CMP		#$F0
		BCC		loc_2C0F5
		LDA		#$EF
loc_2C0EB:
		STA		_scr_trds_x_pos_lo,X
		INY
		LDA		#$00
		SEC
		SBC		_scr_trds_args1,X
		STA		_scr_trds_args1,X
loc_2C0F5:
		LDA		_scr_trds_y_pos_lo,X
		CMP		#$10
		BCS		loc_2C0FF
		LDA		#$10
		BNE		loc_2C105
loc_2C0FF:
		CMP		#$E0
		BCC		loc_2C10F
		LDA		#$DF
loc_2C105:
		STA		_scr_trds_y_pos_lo,X
		INY
		LDA		#$80
		SEC
		SBC		_scr_trds_args1,X
		STA		_scr_trds_args1,X
loc_2C10F:
		TYA
		BEQ		loc_2C118
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C06C
		RTS
loc_2C118:
		LDX		#$0C
		LDY		#$0E
		JSR		sub_61DD6
		BCC		loc_2C127
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C089
		RTS
loc_2C127:
		LDX		#$0F
		LDY		#$12
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_2C12E:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_2C147
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_2C142
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C0BF
		RTS
loc_2C142:
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C0C5
locret_2C147:
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_2C148:
		NBG_HNDL_SET	_nbgsub_2C23F
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2C0CF
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$80
		SSCRIPT1_SET	_scr_2C1C2
		SDELAY			$48
		SJMP			_sloc_2C16B

; =============== S C R I P T ===============================================
_sjmp_case_2C160:
		NJSR			_nsub_2C26F
			NARGB		$B8,$80
		SARG_SET		SARG1,$80
		SJSR			_ssub_2C228
_sloc_2C16B:
		SLOOP_BEGIN		$10
		SARG_ALU		SARG1,_ADC,$08
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$07
		SLOOP_END
		SJMP			_sloc_2C187

; =============== S C R I P T ===============================================
_sjmp_case_2C17C:
		NJSR			_nsub_2C26F
			NARGB		$2A,$72
		SARG_SET		SARG1,$00
		SJSR			_ssub_2C228
_sloc_2C187:
		SLOOP_BEGIN		$10
		SARG_ALU		SARG1,_ADC,$08
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$04
		SLOOP_END
		SJMP			_sloc_2C1A3

; =============== S C R I P T ===============================================
_sjmp_case_2C198:
		NJSR			_nsub_2C26F
			NARGB		$7B,$7A
		SARG_SET		SARG1,$00
		SJSR			_ssub_2C228
_sloc_2C1A3:
		SLOOP_BEGIN		$20
		SARG_ALU		SARG1,_ADC,$F8
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$05
		SLOOP_END
		SLOOP_BEGIN		$20
		SARG_ALU		SARG1,_ADC,$08
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$05
		SLOOP_END
		SJMP			_sloc_2C1A3

; =============== S C R I P T ===============================================
_scr_2C1C2:
		NJSR			_nsub_6273D
			NARGB		$19,$40
		SDELAY			$06
		SPR_IDX_ADD_IMM 6,$04
		SJMP			_scr_2C1C2

; =============== S C R I P T ===============================================
_scr_2C1CE:
		NBG_HNDL_SET	_nbgsub_2C255
		SLOOP_BEGIN		$3C
		SJSR			_ssub_2C1FA
		NJSR			_nsub_62BFD
		SBCS_BREAK	_sloc_2C1EF
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2C0D3
_sloc_2C1E6:
		SJSR			_ssub_2C1FA
		NJSR			_nsub_62BFD
		SBCC			_sloc_2C1E6
_sloc_2C1EF:
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_2C204
		SCASE			_scr_2C233
		SCASE			_sjmp_case_2C239

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2C1FA:
		NJSR			_nsub_6273D
			NARGB		$19,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ===============================================
_sjmp_case_2C204:
		SLOOP_BEGIN		$1E
		NJSR			_nsub_6273D
			NARGB		$19,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SDELAY			$3C
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2C0CF
		SSCRIPT1_SET	_scr_2C1C2
		NJSR			_nsub_62879
			NARGB		$03
		SJMP_SW			$03
		SCASE			_sjmp_case_2C160
		SCASE			_sjmp_case_2C17C
		SCASE			_sjmp_case_2C198

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2C228:
		SLOOP_BEGIN		$1E
		SPR_IDX_SET		1,$1B
		SPR_IDX_SET		1,$FF
		SLOOP_END
		NBG_HNDL_SET	_nbgsub_2C23F
		SRET

; =============== S C R I P T ===============================================
_scr_2C233:
		SARG_SET		SARG1,$25
		SJMP			_sloc_62E25

; =============== S C R I P T ===============================================
_sjmp_case_2C239:
		SARG_SET		SARG1,$27
		SJMP			_sloc_62E2C

; =============== S U B R O U T I N E =======================================
_nbgsub_2C23F:
		LDX		#$08
		LDY		#$0E
		JSR		sub_61DD6
		BCC		loc_2C24E
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C1CE
		RTS
loc_2C24E:
		LDX		#$0B
		LDY		#$12
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_2C255:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_2C26E
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_2C269
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C233
		RTS
loc_2C269:
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_2C239
locret_2C26E:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2C26F:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_x_pos_lo,X
		JSR		_scr_getc
		STA		_scr_trds_y_pos_lo,X
		RTS
_spr_raw_lib1A_04:
		.BYTE	$02
		.BYTE	$F8,$CA,$02,$F8
		.BYTE	$F8,$DA,$02,$00
_spr_raw_lib1A_05:
		.BYTE	$02
		.BYTE	$F8,$DC,$02,$00
		.BYTE	$F8,$CC,$02,$F8
_spr_raw_lib1A_06:
		.BYTE	$02
		.BYTE	$F8,$CC,$42,$00
		.BYTE	$F8,$DC,$42,$F8
_spr_raw_lib1A_07:
		.BYTE	$03
		.BYTE	$F7,$58,$00,$FB
		.BYTE	$FD,$58,$00,$00
		.BYTE	$00,$58,$00,$F8
_spr_raw_lib1A_08:
		.BYTE	$03
		.BYTE	$FD,$48,$00,$FA
		.BYTE	$FC,$48,$00,$FE
		.BYTE	$02,$48,$00,$FB
_spr_raw_lib1A_09:
		.BYTE	$08
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$E8,$B4,$02,$04
		.BYTE	$E8,$B4,$42,$F4
		.BYTE	$E8,$A4,$02,$FC
		.BYTE	$F8,$B6,$42,$F4
		.BYTE	$F8,$B6,$02,$04
		.BYTE	$F8,$A6,$02,$FC
_spr_raw_lib1A_0D:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$84,$42,$04
		.BYTE	$E8,$84,$02,$F4
		.BYTE	$E8,$94,$02,$FC
		.BYTE	$F8,$86,$02,$F4
		.BYTE	$F8,$86,$42,$04
		.BYTE	$F8,$96,$02,$FC
_spr_raw_lib1A_0A:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$8C,$42,$04
		.BYTE	$E8,$AC,$42,$F4
		.BYTE	$E8,$9C,$42,$FC
		.BYTE	$F8,$AE,$42,$F4
		.BYTE	$F8,$8E,$42,$04
		.BYTE	$F8,$9E,$42,$FC
_spr_raw_lib1A_0E:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$88,$42,$04
		.BYTE	$E8,$A8,$42,$F4
		.BYTE	$E8,$98,$42,$FC
		.BYTE	$F8,$AA,$42,$F4
		.BYTE	$F8,$8A,$42,$04
		.BYTE	$F8,$9A,$42,$FC
_spr_raw_lib1A_0B:
		.BYTE	$08
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$E8,$80,$42,$04
		.BYTE	$E8,$80,$02,$F4
		.BYTE	$E8,$90,$02,$FC
		.BYTE	$F8,$82,$02,$F4
		.BYTE	$F8,$82,$42,$04
		.BYTE	$F8,$92,$02,$FC
_spr_raw_lib1A_0F:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$B0,$02,$04
		.BYTE	$E8,$B0,$42,$F4
		.BYTE	$E8,$A0,$02,$FC
		.BYTE	$F8,$B2,$42,$F4
		.BYTE	$F8,$B2,$02,$04
		.BYTE	$F8,$A2,$02,$FC
_spr_raw_lib1A_0C:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$AC,$02,$04
		.BYTE	$E8,$8C,$02,$F4
		.BYTE	$E8,$9C,$02,$FC
		.BYTE	$F8,$8E,$02,$F4
		.BYTE	$F8,$AE,$02,$04
		.BYTE	$F8,$9E,$02,$FC
_spr_raw_lib1A_10:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$A8,$02,$04
		.BYTE	$E8,$88,$02,$F4
		.BYTE	$E8,$98,$02,$FC
		.BYTE	$F8,$8A,$02,$F4
		.BYTE	$F8,$AA,$02,$04
		.BYTE	$F8,$9A,$02,$FC
_spr_raw_lib1A_19:
		.BYTE	$08
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$E8,$BE,$03,$00
		.BYTE	$E8,$D6,$03,$F8
		.BYTE	$08,$D4,$03,$F8
		.BYTE	$08,$D4,$43,$00
		.BYTE	$F8,$D8,$43,$00
		.BYTE	$F8,$D8,$03,$F8
_spr_raw_lib1A_1D:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$BC,$03,$00
		.BYTE	$E8,$C6,$03,$F8
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$C4,$43,$00
		.BYTE	$F8,$C8,$43,$00
		.BYTE	$F8,$C8,$03,$F8
_spr_raw_lib1A_1A:
		.BYTE	$07
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$08,$F4,$43,$F8
		.BYTE	$E8,$F0,$43,$F8
		.BYTE	$E8,$E0,$43,$00
		.BYTE	$F8,$E2,$43,$00
		.BYTE	$F8,$F2,$43,$F8
_spr_raw_lib1A_1E:
		.BYTE	$07
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$08,$E4,$43,$F8
		.BYTE	$E8,$F6,$43,$F8
		.BYTE	$E8,$E6,$43,$00
		.BYTE	$F8,$E8,$43,$00
		.BYTE	$F8,$F8,$43,$F8
_spr_raw_lib1A_1B:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$D0,$03,$F8
		.BYTE	$E8,$BA,$03,$00
		.BYTE	$08,$D4,$43,$00
		.BYTE	$08,$D4,$03,$F8
		.BYTE	$F8,$D2,$03,$F8
		.BYTE	$F8,$D2,$43,$00
_spr_raw_lib1A_1F:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$E8,$B8,$03,$00
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$C4,$43,$00
		.BYTE	$F8,$C2,$43,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib1A_1C:
		.BYTE	$07
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$E8,$E0,$03,$F8
		.BYTE	$E8,$F0,$03,$00
		.BYTE	$08,$F4,$03,$00
		.BYTE	$F8,$E2,$03,$F8
		.BYTE	$F8,$F2,$03,$00
_spr_raw_lib1A_20:
		.BYTE	$07
		.BYTE	$10,$3E,$40,$F8
		.BYTE	$10,$3E,$00,$00
		.BYTE	$08,$E4,$03,$00
		.BYTE	$E8,$F6,$03,$00
		.BYTE	$E8,$E6,$03,$F8
		.BYTE	$F8,$E8,$03,$F8
		.BYTE	$F8,$F8,$03,$00
_spr_raw_lib1A_11:
		.BYTE	$08
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$E8,$B4,$02,$06
		.BYTE	$E8,$B4,$42,$F6
		.BYTE	$E8,$A4,$02,$FE
		.BYTE	$F8,$B6,$42,$F6
		.BYTE	$F8,$B6,$02,$06
		.BYTE	$F8,$A6,$02,$FE
_spr_raw_lib1A_12:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$10,$3E,$00,$02
		.BYTE	$E8,$8C,$42,$06
		.BYTE	$E8,$AC,$42,$F6
		.BYTE	$E8,$9C,$42,$FE
		.BYTE	$F8,$AE,$42,$F6
		.BYTE	$F8,$8E,$42,$06
		.BYTE	$F8,$9E,$42,$FE
_spr_raw_lib1A_13:
		.BYTE	$08
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$E8,$80,$42,$06
		.BYTE	$E8,$80,$02,$F6
		.BYTE	$E8,$90,$02,$FE
		.BYTE	$F8,$82,$02,$F6
		.BYTE	$F8,$82,$42,$06
		.BYTE	$F8,$92,$02,$FE
_spr_raw_lib1A_14:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$10,$3E,$00,$02
		.BYTE	$E8,$AC,$02,$06
		.BYTE	$E8,$8C,$02,$F6
		.BYTE	$E8,$9C,$02,$FE
		.BYTE	$F8,$8E,$02,$F6
		.BYTE	$F8,$AE,$02,$06
		.BYTE	$F8,$9E,$02,$FE
_spr_raw_lib1A_21:
		.BYTE	$08
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$E8,$BE,$03,$02
		.BYTE	$E8,$D6,$03,$FA
		.BYTE	$08,$D4,$03,$FA
		.BYTE	$08,$D4,$43,$02
		.BYTE	$F8,$D8,$43,$02
		.BYTE	$F8,$D8,$03,$FA
_spr_raw_lib1A_22:
		.BYTE	$07
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$08,$F4,$43,$FA
		.BYTE	$E8,$F0,$43,$FA
		.BYTE	$E8,$E0,$43,$02
		.BYTE	$F8,$E2,$43,$02
		.BYTE	$F8,$F2,$43,$FA
_spr_raw_lib1A_23:
		.BYTE	$08
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$10,$3E,$00,$02
		.BYTE	$E8,$D0,$03,$FA
		.BYTE	$E8,$BA,$03,$02
		.BYTE	$08,$D4,$43,$02
		.BYTE	$08,$D4,$03,$FA
		.BYTE	$F8,$D2,$03,$FA
		.BYTE	$F8,$D2,$43,$02
_spr_raw_lib1A_24:
		.BYTE	$07
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
		.BYTE	$E8,$E0,$03,$FA
		.BYTE	$E8,$F0,$03,$02
		.BYTE	$08,$F4,$03,$02
		.BYTE	$F8,$E2,$03,$FA
		.BYTE	$F8,$F2,$03,$02
_spr_raw_lib1A_25:
		.BYTE	$05
		.BYTE	$E6,$F6,$03,$FE
		.BYTE	$E6,$E6,$03,$F6
		.BYTE	$FF,$FA,$03,$FA
		.BYTE	$F6,$E8,$03,$F5
		.BYTE	$F6,$F8,$03,$FD
_spr_raw_lib1A_26:
		.BYTE	$03
		.BYTE	$F6,$E6,$03,$F7
		.BYTE	$F4,$F6,$03,$FF
		.BYTE	$FF,$FA,$03,$FA
_spr_raw_lib1A_27:
		.BYTE	$05
		.BYTE	$E6,$F6,$43,$FB
		.BYTE	$E6,$E6,$43,$03
		.BYTE	$FF,$FA,$43,$FF
		.BYTE	$F6,$E8,$43,$04
		.BYTE	$F6,$F8,$43,$FC
_spr_raw_lib1A_28:
		.BYTE	$03
		.BYTE	$F6,$E6,$43,$02
		.BYTE	$F4,$F6,$43,$FA
		.BYTE	$FF,$FA,$43,$FF
_spr_raw_lib1A_15:
		.BYTE	$05
		.BYTE	$F0,$A8,$02,$FE
		.BYTE	$EF,$98,$02,$F6
		.BYTE	$EF,$88,$02,$EE
		.BYTE	$FF,$CE,$02,$F2
		.BYTE	$FF,$DE,$02,$FA
_spr_raw_lib1A_16:
		.BYTE	$05
		.BYTE	$F8,$A8,$02,$FE
		.BYTE	$F7,$98,$02,$F6
		.BYTE	$F6,$88,$02,$EE
		.BYTE	$FF,$CE,$02,$F2
		.BYTE	$FF,$DE,$02,$FA
_spr_raw_lib1A_17:
		.BYTE	$05
		.BYTE	$F0,$A8,$42,$FB
		.BYTE	$EF,$98,$42,$03
		.BYTE	$EF,$88,$42,$0B
		.BYTE	$FF,$CE,$42,$07
		.BYTE	$FF,$DE,$42,$FF
_spr_raw_lib1A_18:
		.BYTE	$05
		.BYTE	$F8,$A8,$42,$FB
		.BYTE	$F7,$98,$42,$03
		.BYTE	$F6,$88,$42,$0B
		.BYTE	$FF,$CE,$42,$07
		.BYTE	$FF,$DE,$42,$FF

; =============== S C R I P T ===============================================
_scr22_lvl2_boss_train_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_sjmp_case_2C91D
		SCASE			_sjmp_case_2C978
		SCASE			_sjmp_case_2C97D
		SCASE			_sjmp_case_2C8D1

; =============== S C R I P T ===============================================
_sjmp_case_2C658:
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2C6F3
		NBG_HNDL_SET	_nbgsub_2C6F7
		SJSR			_ssub_2C67C
		SLOOP_BEGIN		$02
		SJSR			_ssub_2C686
		SLOOP_END
		SJSR			_ssub_2C67C
		SJSR			_ssub_2C686
		SJSR			_ssub_2C67C
		SLOOP_BEGIN		$03
		SJSR			_ssub_2C686
		SLOOP_END
		SJMP			_sjmp_case_2C658

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2C67C:
		SLOOP_BEGIN		$03
		SPR_IDX_SET		0,$29
		SDELAY			$0C
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2C686:
		SPR_IDX_SET		7,$2C
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		NJSR			_nsub_new_thread_start
			NARGB		$22
			NARGB		$00,$F8
			NARGB		$01
			NARGB		$00
		SPR_IDX_INC		7
		SPR_IDX_DEC		3
		SPR_IDX_DEC		3
		SPR_IDX_DEC		3
		SRET

; =============== S C R I P T ===============================================
_scr_2C698:
		NBG_HNDL_SET	_nbgsub_2C70D
		SARG_SET		SARG0,$02
		SSCRIPT1_SET	_scr_2C6B7
_sloc_2C6A2:
		SDELAY			$01
		NJSR			_nsub_62BFD
		SBCC			_sloc_2C6A2
		SSCRIPT1_OFF
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_2C658
		SCASE			_scr_2C6D0
		SCASE			_scr_2C6D9

; =============== S C R I P T ===============================================
_scr_2C6B7:
		SLOOP_BEGIN		$01
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
		NJSR			_nsub_626F1
			NARGB		$03
		NJSR			_nsub_60EF1
		SSCRIPT0_OFF

; =============== S C R I P T ===============================================
_scr_2C6D0:
		SJSR			_ssub_2C6E2
		SARG_SET		SARG1,$32
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_2C6D9:
		SJSR			_ssub_2C6E2
		SARG_SET		SARG1,$34
		SJMP			_sloc_62E02

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2C6E2:
		NJSR			_nsub_new_thread_start
			NARGB		$22
			NARGB		$00,$00
			NARGB		$04
			NARGB		$00
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$19
		SRET
byte_2C6F3:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_2C6F7:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		loc_2C706
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C698
		RTS
loc_2C706:
		LDX		#$0D
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_2C70D:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_2C72B
		PHA
		JSR		_nsub_gen_threads_off_except_cur
		LDA		#$19
		STA		_scores_obj_value
		PLA
		LSR
		BCS		loc_2C726
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C6D0
		RTS
loc_2C726:
		JSR		_cur_thread_reload_param
		.WORD	_scr_2C6D9
locret_2C72B:
		RTS
_spr_raw_lib1A_29:
		.BYTE	$0B
		.BYTE	$FD,$E7,$00,$0A
		.BYTE	$FD,$D7,$00,$02
		.BYTE	$FD,$C7,$00,$FA
		.BYTE	$E7,$E3,$40,$00
		.BYTE	$E7,$E3,$00,$F8
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$08,$3E,$03,$00
		.BYTE	$00,$E2,$02,$F8
		.BYTE	$00,$E2,$42,$00
		.BYTE	$F0,$E0,$42,$00
		.BYTE	$F0,$E0,$02,$F8
_spr_raw_lib1A_2A:
		.BYTE	$0B
		.BYTE	$FF,$E7,$00,$0A
		.BYTE	$FF,$D7,$00,$02
		.BYTE	$FF,$C7,$00,$FA
		.BYTE	$E7,$E3,$40,$00
		.BYTE	$E7,$E3,$00,$F8
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$08,$3E,$03,$00
		.BYTE	$01,$E2,$02,$F8
		.BYTE	$01,$E2,$42,$00
		.BYTE	$F1,$F0,$42,$00
		.BYTE	$F1,$F0,$02,$F8
_spr_raw_lib1A_2B:
		.BYTE	$0B
		.BYTE	$FE,$E7,$00,$0A
		.BYTE	$FE,$D7,$00,$02
		.BYTE	$FE,$C7,$00,$FA
		.BYTE	$E8,$E3,$40,$00
		.BYTE	$E8,$E3,$00,$F8
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$08,$3E,$03,$00
		.BYTE	$01,$E2,$02,$F8
		.BYTE	$01,$E2,$42,$00
		.BYTE	$F1,$F0,$42,$00
		.BYTE	$F1,$F0,$02,$F8
_spr_raw_lib1A_2C:
		.BYTE	$0A
		.BYTE	$FD,$F5,$00,$02
		.BYTE	$FD,$E5,$00,$FA
		.BYTE	$E8,$D5,$00,$01
		.BYTE	$E8,$C5,$00,$F9
		.BYTE	$06,$3E,$03,$00
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$00,$C4,$42,$00
		.BYTE	$00,$D4,$42,$F8
		.BYTE	$F0,$D2,$42,$F8
		.BYTE	$F0,$C2,$42,$00
_spr_raw_lib1A_2D:
		.BYTE	$0B
		.BYTE	$F8,$E7,$00,$0A
		.BYTE	$F8,$D7,$00,$02
		.BYTE	$F8,$C7,$00,$FA
		.BYTE	$E8,$D5,$00,$01
		.BYTE	$E8,$C5,$00,$F9
		.BYTE	$06,$3E,$03,$00
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$00,$C4,$42,$00
		.BYTE	$00,$D4,$42,$F8
		.BYTE	$F0,$D2,$42,$F8
		.BYTE	$F0,$C2,$42,$00
_spr_raw_lib1A_2E:
		.BYTE	$09
		.BYTE	$EA,$F3,$40,$00
		.BYTE	$FF,$F4,$42,$00
		.BYTE	$EF,$F2,$42,$00
		.BYTE	$F1,$F5,$80,$05
		.BYTE	$EA,$F3,$00,$F8
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$06,$3E,$03,$00
		.BYTE	$FF,$F4,$02,$F8
		.BYTE	$EF,$F2,$02,$F8
_spr_raw_lib1A_2F:
		.BYTE	$09
		.BYTE	$EA,$F3,$40,$00
		.BYTE	$EA,$F3,$00,$F8
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$06,$3E,$03,$00
		.BYTE	$FE,$F4,$02,$F8
		.BYTE	$FE,$F4,$42,$00
		.BYTE	$EE,$F2,$42,$00
		.BYTE	$EE,$F2,$02,$F8
		.BYTE	$E6,$F7,$00,$FA
_spr_raw_lib1A_30:
		.BYTE	$09
		.BYTE	$E9,$F3,$40,$00
		.BYTE	$E9,$F3,$00,$F8
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$06,$3E,$03,$00
		.BYTE	$FD,$F4,$02,$F8
		.BYTE	$FD,$F4,$42,$00
		.BYTE	$ED,$F2,$42,$00
		.BYTE	$ED,$F2,$02,$F8
		.BYTE	$ED,$F5,$C0,$F0
_spr_raw_lib1A_31:
		.BYTE	$0B
		.BYTE	$FD,$E7,$00,$0C
		.BYTE	$FD,$D7,$00,$04
		.BYTE	$FD,$C7,$00,$FC
		.BYTE	$E7,$E3,$40,$02
		.BYTE	$E7,$E3,$00,$FA
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$08,$3E,$03,$02
		.BYTE	$00,$E2,$02,$FA
		.BYTE	$00,$E2,$42,$02
		.BYTE	$F0,$E0,$42,$02
		.BYTE	$F0,$E0,$02,$FA
_spr_raw_lib1A_32:
		.BYTE	$03
		.BYTE	$00,$C6,$02,$F8
		.BYTE	$F0,$E6,$02,$FA
		.BYTE	$F0,$D6,$02,$F2
_spr_raw_lib1A_33:
		.BYTE	$02
		.BYTE	$F8,$F6,$02,$F8
		.BYTE	$F8,$E4,$02,$F0
_spr_raw_lib1A_34:
		.BYTE	$03		; *--
		.BYTE	$00,$C6,$42,$00	; *--
		.BYTE	$F0,$E6,$42,$00	; *--
		.BYTE	$F0,$D6,$42,$08	; *--
_spr_raw_lib1A_35:
		.BYTE	$02		; *--
		.BYTE	$F8,$E4,$42,$08	; *--
		.BYTE	$F8,$F6,$42,$00	; *--

; =============== S C R I P T ===============================================
_sjmp_case_2C8D1:
		NJSR			_nsub_players_scr_suspend
		SDELAY			$5A
		NJSR			_nsub_2C90E
		NJSR			_nsub_patch_pal_load
			NARGB		$02
			NARGW		byte_2C90A
		SDELAY			$50
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$13
		SDELAY			$3C
		SLOOP_BEGIN		$3C
		STORE8			_scr_trds_y_pos_hi+2,$05
		STORE8			_scr_trds_y_pos_hi+4,$05
		SCRL_Y_SET	0,$00,$05
		POS_Y_SET		1,$00,$05
		STORE8			_scr_trds_y_pos_hi+2,$06
		STORE8			_scr_trds_y_pos_hi+4,$06
		SCRL_Y_SET	0,$00,$06
		POS_Y_SET		1,$00,$06
		SLOOP_END
		NJSR			_nsub_62BA9
		SSTOP
byte_2C90A:
		.BYTE	$0F,$0F,$0F,$07

; =============== S U B R O U T I N E =======================================
_nsub_2C90E:
		LDA		#$00
		ASL
		TAX
		LDA		#<[_nbgsub_dummy]
		STA		_scr_trds_nbgsub_ptr,X
		LDA		#>[_nbgsub_dummy]
		STA		_scr_trds_nbgsub_ptr+1,X
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_2C91D:
		NJSR			_nsub_2C952
		NJSR			_nsub_new_thread_start
			NARGB		$22
			NARGB		$F8,$00
			NARGB		$02
			NARGB		$E0
		NJSR			_nsub_new_thread_start
			NARGB		$22
			NARGB		$08,$00
			NARGB		$03
			NARGB		$20
		SPR_IDX_SET		0,$37
_sloc_2C932:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_2C94B
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$18
		SLOOP_BEGIN		$03
		SPR_IDX_SET		1,$39
		SPR_IDX_SET		1,$FF
		SPR_IDX_SET		1,$3A
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_2C94B:
		LDX		#$06
		LDY		#$07
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nsub_2C952:
		LDA		#$21
		JSR		_rand
		CLC
		ADC		#$F0
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS
_spr_raw_lib1A_36:
		.BYTE	$01
		.BYTE	$F8,$C0,$01,$FC
_spr_raw_lib1A_37:
		.BYTE	$01
		.BYTE	$F8,$D0,$01,$FC
_spr_raw_lib1A_38:
		.BYTE	$01
		.BYTE	$F8,$C0,$41,$FC
_spr_raw_lib1A_39:
		.BYTE	$01
		.BYTE	$F8,$C8,$01,$FC
_spr_raw_lib1A_3A:
		.BYTE	$01
		.BYTE	$F8,$C8,$41,$FC

; =============== S C R I P T ===============================================
_sjmp_case_2C978:
		SPR_IDX_SET		0,$36
		SJMP			_sloc_2C932

; =============== S C R I P T ===============================================
_sjmp_case_2C97D:
		SPR_IDX_SET		0,$38
		SJMP			_sloc_2C932

; =============== S C R I P T ===============================================
_scr2E_lvl4_boss_dragons:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$02
		SCASE			_sjmp_case_2C9AE
		SCASE			_sjmp_case_2CE6C
		SJSR			_ssub_62E33
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2CAA7
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$13
		SLOOP_BEGIN		$08
_sloc_2C99C:
		SDELAY			$01
		NJSR			_nsub_2CADF
			NARGB		$04
		SBCS			_sloc_2C99C
		NJSR			_nsub_new_thread_start
			NARGB		$2E
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		SLOOP_END

; =============== S C R I P T ===============================================
_sjmp_case_2C9AE:
		NJSR			_nsub_2CB1B
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$3B
		SPR_IDX_SET		1,$FF
		SLOOP_END
_sloc_2C9B8:
		SARG_SET		SARG0,$00
_sloc_2C9BB:
		SPR_IDX_SET		0,$3B
		NJSR			_nsub_2CB4F
		NJSR			_nsub_2CAF6
		SBCC			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_2CAF6
		SBCC			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_2CAF6
		SBCC			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_2CAF6
		SBCS			_sloc_2C9BB
_sloc_2C9E4:
		NJSR			_nsub_628D1
			NARGB		$00,$01
		SDELAY			$10
		POS_MOVE_STOP	0
		NJSR			_nsub_62B1E
			NARGB		$02,$40
		SBCC			_sloc_2C9BB
		NJSR			_nsub_62CC4
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$14
		NJSR			_nsub_6273D
			NARGB		$3C,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04
		NBG_HNDL_SET	_nbgsub_2CAAF
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$18
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 0,$FC
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$15
		SLOOP_BEGIN		$20
		NJSR			_nsub_new_thread_start
			NARGB		$2E
			NARGB		$00,$00
			NARGB		$02
			NARGB		$00
		SDELAY			$03
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$0C
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		NBG_HNDL_RESET
		SJMP			_sloc_2C9BB

; =============== S C R I P T ===============================================
_scr_2CA40:
		NBG_HNDL_SET	_nbgsub_2CAC5
		SLOOP_BEGIN		$5A
		SJSR			_ssub_2CA91
		NJSR			_nsub_62BFD
		SBCS_BREAK	_sloc_2CA7E
		SLOOP_END
		NJSR			_nsub_62BE5
		SBCS			_sloc_2CA66
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$22
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP
_sloc_2CA66:
		SARG_SET		SARG0,$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2CAAB
_sloc_2CA6F:
		SJSR			_ssub_2CA91
		NJSR			_nsub_62BFD
		SBCC			_sloc_2CA6F
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2CAA7
_sloc_2CA7E:
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_2CA89
		SCASE			_scr_2CA9B
		SCASE			_scr_2CAA1

; =============== S C R I P T ===============================================
_sjmp_case_2CA89:
		NBG_HNDL_RESET
		SPR_IDX_ADD_IMM 6,$F4
		SPR_IDX_ADD_IMM 6,$FC
		SJMP			_sloc_2C9B8

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_2CA91:
		NJSR			_nsub_6273D
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ===============================================
_scr_2CA9B:
		SARG_SET		SARG1,$50
		SJMP			_sloc_62E25

; =============== S C R I P T ===============================================
_scr_2CAA1:
		SARG_SET		SARG1,$52
		SJMP			_sloc_62E2C
byte_2CAA7:
		.BYTE	$0F,$25,$16,$0F
byte_2CAAB:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_2CAAF:
		LDX		#$10
		LDY		#$10
		JSR		sub_61DD6
		BCC		loc_2CABE
		JSR		_cur_thread_reload_param
		.WORD	_scr_2CA40
		RTS
loc_2CABE:
		LDX		#$15
		LDY		#$16
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_2CAC5:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_2CADE
		LSR
		LDA		#$1E
		STA		_scores_obj_value
		BCS		loc_2CAD9
		JSR		_cur_thread_reload_param
		.WORD	_scr_2CA9B
		RTS
loc_2CAD9:
		JSR		_cur_thread_reload_param
		.WORD	_scr_2CAA1
locret_2CADE:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2CADF:
		JSR		_scr_getc
		STA		_tmp0
		LDY		#$00
		LDX		#$06
loc_2CAE8:
		LDA		_scr_trds_idx,X
		BMI		loc_2CAEE
		INY
loc_2CAEE:
		INX
		CPX		#$0D
		BCC		loc_2CAE8
		CPY		_tmp0
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2CAF6:
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_args1,Y
		ASL
		ROL
		ROL
		TAX
		LDA		_scr_trds_x_pos_lo,Y
		CMP		byte_2CB13,X
		BEQ		loc_2CB11
		LDA		_scr_trds_y_pos_lo,Y
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

; =============== S U B R O U T I N E =======================================
_nsub_2CB1B:
		LDA		#$0B
		JSR		_rand
		PHA
		LDA		#$08
		JSR		_rand
		CLC
		ADC		#$03
		ASL
		ASL
		ASL
		ASL
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_y_pos_lo,X
		LDA		#$00
		STA		_scr_trds_y_pos_hi,X
		PLA
		CLC
		ADC		#$03
		ASL
		ASL
		ASL
		ASL
		STA		_scr_trds_x_pos_lo,X
		LDA		#$03
		STA		_scr_trds_x_pos_hi,X
		LDA		#$00
		JSR		_rand
		AND		#$C0
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2CB4F:
		LDA		#$00
		JSR		_rand
		LSR
		BCC		locret_2CB5E
		ASL
		AND		#$C0
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
locret_2CB5E:
		RTS
_spr_raw_lib1A_3B:
		.BYTE	$03
		.BYTE	$08,$82,$00,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$80,$00,$FC
_spr_raw_lib1A_44:
		.BYTE	$09
		.BYTE	$F0,$A4,$03,$EC
		.BYTE	$00,$86,$03,$04
		.BYTE	$F0,$A4,$43,$0C
		.BYTE	$00,$B6,$03,$F4
		.BYTE	$E0,$A6,$03,$FC
		.BYTE	$F0,$B4,$43,$04
		.BYTE	$F0,$B4,$03,$F4
		.BYTE	$00,$C6,$03,$FC
		.BYTE	$F0,$C4,$03,$FC
_spr_raw_lib1A_48:
		.BYTE	$09
		.BYTE	$F0,$F4,$43,$EC
		.BYTE	$00,$96,$03,$F4
		.BYTE	$F0,$E4,$43,$F4
		.BYTE	$E0,$F6,$03,$FC
		.BYTE	$F0,$F4,$03,$0C
		.BYTE	$F0,$E4,$03,$04
		.BYTE	$00,$E6,$03,$04
		.BYTE	$F0,$D4,$03,$FC
		.BYTE	$00,$D6,$03,$FC
_spr_raw_lib1A_45:
		.BYTE	$0A
		.BYTE	$E0,$A8,$43,$04
		.BYTE	$E0,$B8,$43,$FC
		.BYTE	$00,$CA,$43,$0C
		.BYTE	$F0,$C8,$43,$0C
		.BYTE	$00,$DA,$43,$04
		.BYTE	$F0,$D8,$43,$04
		.BYTE	$F0,$F8,$43,$F4
		.BYTE	$F0,$E8,$43,$FC
		.BYTE	$00,$EA,$43,$FC
		.BYTE	$00,$FA,$43,$F4
_spr_raw_lib1A_49:
		.BYTE	$09
		.BYTE	$E0,$AA,$43,$04
		.BYTE	$E0,$BA,$43,$FC
		.BYTE	$F0,$BC,$43,$0C
		.BYTE	$00,$CE,$43,$04
		.BYTE	$F0,$CC,$43,$04
		.BYTE	$F0,$EC,$43,$F4
		.BYTE	$F0,$DC,$43,$FC
		.BYTE	$00,$DE,$43,$FC
		.BYTE	$00,$EE,$43,$F4
_spr_raw_lib1A_46:
		.BYTE	$09
		.BYTE	$00,$B2,$03,$F4
		.BYTE	$00,$84,$03,$04
		.BYTE	$F0,$A0,$43,$0C
		.BYTE	$F0,$A0,$03,$EC
		.BYTE	$F0,$B0,$03,$F4
		.BYTE	$F0,$B0,$43,$04
		.BYTE	$E0,$A2,$03,$FC
		.BYTE	$F0,$C0,$03,$FC
		.BYTE	$00,$C2,$03,$FC
_spr_raw_lib1A_4A:
		.BYTE	$09
		.BYTE	$F0,$F0,$03,$0C
		.BYTE	$F0,$F0,$43,$EC
		.BYTE	$F0,$E0,$03,$04
		.BYTE	$F0,$E0,$43,$F4
		.BYTE	$00,$E2,$03,$04
		.BYTE	$00,$94,$03,$F4
		.BYTE	$00,$D2,$03,$FC
		.BYTE	$E0,$F2,$03,$FC
		.BYTE	$F0,$D0,$03,$FC
_spr_raw_lib1A_47:
		.BYTE	$0A
		.BYTE	$E0,$B8,$03,$00
		.BYTE	$E0,$A8,$03,$F8
		.BYTE	$F0,$C8,$03,$F0
		.BYTE	$00,$CA,$03,$F0
		.BYTE	$00,$DA,$03,$F8
		.BYTE	$F0,$F8,$03,$08
		.BYTE	$00,$FA,$03,$08
		.BYTE	$00,$EA,$03,$00
		.BYTE	$F0,$E8,$03,$00
		.BYTE	$F0,$D8,$03,$F8
_spr_raw_lib1A_4B:
		.BYTE	$09
		.BYTE	$E0,$AA,$03,$F8
		.BYTE	$E0,$BA,$03,$00
		.BYTE	$00,$CE,$03,$F8
		.BYTE	$00,$DE,$03,$00
		.BYTE	$00,$EE,$03,$08
		.BYTE	$F0,$EC,$03,$08
		.BYTE	$F0,$DC,$03,$00
		.BYTE	$F0,$CC,$03,$F8
		.BYTE	$F0,$BC,$03,$F0
_spr_raw_lib1A_3C:
		.BYTE	$03
		.BYTE	$08,$82,$00,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$98,$03,$FC
_spr_raw_lib1A_40:
		.BYTE	$09
		.BYTE	$EE,$A6,$03,$FC
		.BYTE	$FE,$A4,$03,$EC
		.BYTE	$FE,$A4,$43,$0C
		.BYTE	$FE,$B4,$43,$04
		.BYTE	$FE,$B4,$03,$F4
		.BYTE	$FE,$C4,$03,$FC
		.BYTE	$08,$82,$00,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$80,$00,$FC
_spr_raw_lib1A_3D:
		.BYTE	$03
		.BYTE	$08,$90,$43,$F4
		.BYTE	$08,$8A,$43,$04
		.BYTE	$08,$9A,$43,$FC
_spr_raw_lib1A_41:
		.BYTE	$08
		.BYTE	$FE,$D8,$43,$04
		.BYTE	$FE,$C8,$43,$0C
		.BYTE	$FE,$E8,$43,$FC
		.BYTE	$FE,$F8,$43,$F4
		.BYTE	$EE,$B8,$43,$FC
		.BYTE	$EE,$A8,$43,$04
		.BYTE	$08,$80,$43,$00
		.BYTE	$08,$80,$43,$F8
_spr_raw_lib1A_3E:
		.BYTE	$03
		.BYTE	$08,$82,$00,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$88,$03,$FC
_spr_raw_lib1A_42:
		.BYTE	$09
		.BYTE	$EE,$A2,$03,$FC
		.BYTE	$FE,$A0,$03,$EC
		.BYTE	$FE,$A0,$43,$0C
		.BYTE	$FE,$B0,$43,$04
		.BYTE	$FE,$B0,$03,$F4
		.BYTE	$FE,$C0,$03,$FC
		.BYTE	$08,$80,$03,$FC
		.BYTE	$08,$90,$03,$04
		.BYTE	$08,$82,$03,$F4
_spr_raw_lib1A_3F:
		.BYTE	$03
		.BYTE	$08,$8A,$03,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$9A,$03,$FC
_spr_raw_lib1A_43:
		.BYTE	$08
		.BYTE	$FE,$D8,$03,$F4
		.BYTE	$FE,$C8,$03,$EC
		.BYTE	$FE,$E8,$03,$FC
		.BYTE	$FE,$F8,$03,$04
		.BYTE	$EE,$B8,$03,$FC
		.BYTE	$EE,$A8,$03,$F4
		.BYTE	$08,$80,$03,$F8
		.BYTE	$08,$80,$03,$00
_spr_raw_lib1A_4C:
		.BYTE	$09
		.BYTE	$F0,$A4,$03,$EE
		.BYTE	$00,$86,$03,$06
		.BYTE	$F0,$A4,$43,$0E
		.BYTE	$00,$B6,$03,$F6
		.BYTE	$E0,$A6,$03,$FE
		.BYTE	$F0,$B4,$43,$06
		.BYTE	$F0,$B4,$03,$F6
		.BYTE	$00,$C6,$03,$FE
		.BYTE	$F0,$C4,$03,$FE
_spr_raw_lib1A_4D:
		.BYTE	$0A
		.BYTE	$E0,$A8,$43,$06
		.BYTE	$E0,$B8,$43,$FE
		.BYTE	$00,$CA,$43,$0E
		.BYTE	$F0,$C8,$43,$0E
		.BYTE	$00,$DA,$43,$06
		.BYTE	$F0,$D8,$43,$06
		.BYTE	$F0,$F8,$43,$F6
		.BYTE	$F0,$E8,$43,$FE
		.BYTE	$00,$EA,$43,$FE
		.BYTE	$00,$FA,$43,$F6
_spr_raw_lib1A_4E:
		.BYTE	$09
		.BYTE	$00,$B2,$03,$F7
		.BYTE	$00,$84,$03,$07
		.BYTE	$F0,$A0,$43,$0F
		.BYTE	$F0,$A0,$03,$EF
		.BYTE	$F0,$B0,$03,$F7
		.BYTE	$F0,$B0,$43,$07
		.BYTE	$E0,$A2,$03,$FF
		.BYTE	$F0,$C0,$03,$FF
		.BYTE	$00,$C2,$03,$FF
_spr_raw_lib1A_4F:
		.BYTE	$0A
		.BYTE	$E0,$B8,$03,$02
		.BYTE	$E0,$A8,$03,$FA
		.BYTE	$F0,$C8,$03,$F2
		.BYTE	$00,$CA,$03,$F2
		.BYTE	$00,$DA,$03,$FA
		.BYTE	$F0,$F8,$03,$0A
		.BYTE	$00,$FA,$03,$0A
		.BYTE	$00,$EA,$03,$02
		.BYTE	$F0,$E8,$03,$02
		.BYTE	$F0,$D8,$03,$FA
_spr_raw_lib1A_52:
		.BYTE	$0A		; *--
		.BYTE	$DF,$AA,$43,$07	; *--
		.BYTE	$DF,$BA,$43,$FF	; *--
		.BYTE	$FF,$CA,$43,$0F	; *--
		.BYTE	$EF,$C8,$43,$0F	; *--
		.BYTE	$EF,$D8,$43,$07	; *--
		.BYTE	$EF,$E8,$43,$FF	; *--
		.BYTE	$EF,$F8,$43,$F7	; *--
		.BYTE	$FF,$9E,$43,$07	; *--
		.BYTE	$FF,$AE,$43,$FF	; *--
		.BYTE	$FF,$BE,$43,$F7	; *--
_spr_raw_lib1A_53:
		.BYTE	$04		; *--
		.BYTE	$F6,$F8,$43,$FA	; *--
		.BYTE	$F6,$C8,$43,$02	; *--
		.BYTE	$06,$BE,$43,$FA	; *--
		.BYTE	$06,$8E,$43,$02	; *--
_spr_raw_lib1A_50:
		.BYTE	$0A
		.BYTE	$DF,$AA,$03,$F2
		.BYTE	$DF,$BA,$03,$FA
		.BYTE	$FF,$CA,$03,$EA
		.BYTE	$EF,$C8,$03,$EA
		.BYTE	$EF,$D8,$03,$F2
		.BYTE	$EF,$E8,$03,$FA
		.BYTE	$EF,$F8,$03,$02
		.BYTE	$FF,$9E,$03,$F2
		.BYTE	$FF,$AE,$03,$FA
		.BYTE	$FF,$BE,$03,$02
_spr_raw_lib1A_51:
		.BYTE	$04
		.BYTE	$F7,$F8,$03,$01
		.BYTE	$F7,$C8,$03,$F9
		.BYTE	$07,$BE,$03,$01
		.BYTE	$07,$8E,$03,$F9

; =============== S C R I P T ===============================================
_sjmp_case_2CE6C:
		SARG_SET		SARG0,$00
		NJSR			_nsub_604CD
		SJMP_SW			$04
		SCASE			_sjmp_case_2CE7C
		SCASE			_sjmp_case_2CE8A
		SCASE			_sjmp_case_2CE81
		SCASE			_sjmp_case_2CE95

; =============== S C R I P T ===============================================
_sjmp_case_2CE7C:
		POS_Y_MOVE		0,$CD
		SJMP			_sloc_2CE83

; =============== S C R I P T ===============================================
_sjmp_case_2CE81:
		POS_Y_MOVE		0,$22
_sloc_2CE83:
		NBG_HNDL_SET	_nbgsub_2CEA0
		SPR_IDX_SET		1,$54
		SPR_IDX_INC		2
		SSTOP

; =============== S C R I P T ===============================================
_sjmp_case_2CE8A:
		POS_X_MOVE	0,$2F
		POS_Y_MOVE		0,$04
		NBG_HNDL_SET	_nbgsub_2CEA7
		SPR_IDX_SET		1,$58
		SPR_IDX_INC		2
		SSTOP

; =============== S C R I P T ===============================================
_sjmp_case_2CE95:
		POS_X_MOVE	0,$D1
		POS_Y_MOVE		0,$04
		NBG_HNDL_SET	_nbgsub_2CEA7
		SPR_IDX_SET		1,$56
		SPR_IDX_INC		2
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_2CEA0:
		LDX		#$09
		LDY		#$24
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_2CEA7:
		LDX		#$23
		LDY		#$0A
		JMP		_player_to_obj_collision_test
_spr_raw_lib1A_54:
		.BYTE	$03
		.BYTE	$E3,$92,$01,$FC
		.BYTE	$F9,$92,$41,$FC
		.BYTE	$0E,$92,$01,$FC
_spr_raw_lib1A_55:
		.BYTE	$03
		.BYTE	$D8,$92,$41,$FC
		.BYTE	$EE,$92,$41,$FC
		.BYTE	$04,$92,$01,$FC
_spr_raw_lib1A_58:
		.BYTE	$03
		.BYTE	$F0,$92,$01,$E0
		.BYTE	$F7,$92,$01,$0C
		.BYTE	$F3,$92,$41,$F6
_spr_raw_lib1A_59:
		.BYTE	$03
		.BYTE	$F8,$92,$01,$18
		.BYTE	$F2,$92,$41,$EB
		.BYTE	$F5,$92,$01,$01
_spr_raw_lib1A_56:
		.BYTE	$03
		.BYTE	$F8,$92,$41,$E1
		.BYTE	$F2,$92,$01,$0D
		.BYTE	$F5,$92,$41,$F7
_spr_raw_lib1A_57:
		.BYTE	$03
		.BYTE	$F0,$92,$41,$18
		.BYTE	$F7,$92,$41,$EC
		.BYTE	$F3,$92,$01,$02

; =============== S C R I P T ===============================================
_scr2F_lvl5_boss_key_keeper:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_sjmp_case_2CFB4
		SCASE			_sjmp_case_2CFCC
		SCASE			_sjmp_case_2D7B1
		SCASE			_sjmp_case_2D81B
		SJSR			_ssub_62E33
		NJSR			_nsub_2D26C
		NJSR			_nsub_spr_pal_load
			NARGW		byte_2D150
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$18
		SARG_SET		SARG1,$40
		NJSR			_nsub_new_thread_start
			NARGB		$2F
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		NJSR			_nsub_2D257
		SSCRIPT1_SET	_scr_2CFA1
		SDELAY			$28
		SDELAY			$B4
_sloc_2CF30:
		NJSR			_nsub_2D199
		SBCC			_sloc_2CF51
		NJSR			_nsub_2D1BF
			NARGW		_sloc_2CFD9
		SSCRIPT1_SET	_scr_2CFA1
		SDELAY			$28
		NJSR			_nsub_2D282
		NJSR			_nsub_new_thread_start
			NARGB		$2F
			NARGB		$00,$00
			NARGB		$02
			NARGB		$00
		NJSR			_nsub_2D257
		SDELAY			$B4
_sloc_2CF51:
		NJSR			_nsub_2D1BF
			NARGW		_sloc_2CFE3
		SDELAY			$28
		SSCRIPT1_OFF
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2D15C

; =============== S C R I P T ===============================================
_sjmp_case_2CF60:
		SDELAY			$01
		NJSR			_nsub_2D1F2
		SJMP_SW			$02
		SCASE			_sjmp_case_2CF60
		SCASE			_sjmp_case_2CF81
		NJSR			_nsub_2D215
		NJSR			_nsub_2D1BF
			NARGW		_sloc_2D002
_sloc_2CF73:
		SDELAY			$01
		NJSR			_nsub_mcmp
			NARGW		byte_7DA
			NARGB		$00
		SBCC			_sloc_2CF89
		NJSR			_nsub_2D229

; =============== S C R I P T ===============================================
_sjmp_case_2CF81:
		NJSR			_nsub_2D1BF
			NARGW		_sloc_2CFE3
		SJMP			_sjmp_case_2CF60
_sloc_2CF89:
		NJSR			_nsub_mcmp
			NARGW		byte_7DA
			NARGB		$02
		SBCC			_sloc_2CF73
		NJSR			_nsub_2D229
		SMEM_ALU		byte_7DB,_ADC,$FF
		NJSR			_nsub_2D19F
		SBCC			_sloc_2CF30
		SSTOP

; =============== S C R I P T ===============================================
_scr_2CFA1:
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2D160
		SDELAY			$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		byte_2D15C
		SDELAY			$02
		SJMP			_scr_2CFA1

; =============== S C R I P T ===============================================
_sjmp_case_2CFB4:
		SARG_SET		SARG0,$00
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		SDELAY			$28
		NJSR			_nsub_new_thread_start
			NARGB		$2F
			NARGB		$00,$00
			NARGB		$02
			NARGB		$00
		NJSR			_nsub_2D257
		SJMP			_sloc_2CFED

; =============== S C R I P T ===============================================
_sjmp_case_2CFCC:
		SARG_SET		SARG0,$00
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		SDELAY			$B4
		SJMP			_sloc_2CFD9
_sloc_2CFD9:
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		SDELAY			$28
		SJMP			_sloc_2CFED
_sloc_2CFE3:
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		SDELAY			$28
		NBG_HNDL_SET	_nbgsub_2D164
_sloc_2CFED:
		NJSR			_nsub_604CD
		SJSR_SW	$04
		SCASE			_sjsr_case_2D07A
		SCASE			_sjsr_case_2D01E
		SCASE			_sjsr_case_2D0A8
		SCASE			_sjsr_case_2D04C
		POS_MOVE_STOP	0
		SARG_ALU		SARG1,_ADC,$40
		SJMP			_sloc_2CFED
_sloc_2D002:
		NJSR			_nsub_62ABE
		SDELAY			$01
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		NJSR			_nsub_2D1B1
		SDELAY			$01
		NJSR			_nsub_new_thread_start
			NARGB		$2F
			NARGB		$00,$00
			NARGB		$04
			NARGB		$00
		SDELAY			$3C
		SJMP			_sloc_2D002
_sjsr_case_2D01E:
		SSCRIPT1_SET	_scr_2D02F
_sloc_2D022:
		NJSR			_nsub_2D2BB
			NARGB		$C8
		SBCS			_sloc_2D02E
		SDELAY			$01
		SJMP			_sloc_2D022
_sloc_2D02E:
		SRET

; =============== S C R I P T ===============================================
_scr_2D02F:
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
		SJMP			_scr_2D02F
_sjsr_case_2D04C:
		SSCRIPT1_SET	_scr_2D05D
_sloc_2D050:
		NJSR			_nsub_2D2CC
			NARGB		$30
		SBCS			_sloc_2D05C
		SDELAY			$01
		SJMP			_sloc_2D050
_sloc_2D05C:
		SRET

; =============== S C R I P T ===============================================
_scr_2D05D:
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
		SJMP			_scr_2D05D
_sjsr_case_2D07A:
		SSCRIPT1_SET	_scr_2D08B
_sloc_2D07E:
		NJSR			_nsub_2D2D8
			NARGB		$40
		SBCS			_sloc_2D08A
		SDELAY			$01
		SJMP			_sloc_2D07E
_sloc_2D08A:
		SRET

; =============== S C R I P T ===============================================
_scr_2D08B:
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
		SJMP			_scr_2D08B
_sjsr_case_2D0A8:
		SSCRIPT1_SET	_scr_2D0B9
_sloc_2D0AC:
		NJSR			_nsub_2D2E4
			NARGB		$A8
		SBCS			_sloc_2D0B8
		SDELAY			$01
		SJMP			_sloc_2D0AC
_sloc_2D0B8:
		SRET

; =============== S C R I P T ===============================================
_scr_2D0B9:
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
		SJMP			_scr_2D0B9

; =============== S C R I P T ===============================================
_scr_2D0D6:
		NBG_HNDL_SET	_nbgsub_2D17F
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		SLOOP_BEGIN		$5A
		SPR_IDX_ADD_IMM 1,$0C
		SPR_IDX_ADD_IMM 1,$F4
		NJSR			_nsub_62BFD
		SBCS_BREAK	_sloc_2D112
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_2D1A8
		SBCS			_sloc_2D103
		SPR_IDX_ADD_IMM 0,$10
_sloc_2D0F6:
		SPR_IDX_ADD_IMM 1,$04
		SPR_IDX_ADD_IMM 1,$FC
		NJSR			_nsub_62BFD
		SBCC			_sloc_2D0F6
		SJMP			_sloc_2D112
_sloc_2D103:
		NJSR			_nsub_6273D
			NARGB		$5A,$40
		SDELAY			$01
		SPR_IDX_SET		1,$76
		NJSR			_nsub_62BFD
		SBCC			_sloc_2D103
_sloc_2D112:
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_2D11D
		SCASE			_scr_2D122
		SCASE			_scr_2D139

; =============== S C R I P T ===============================================
_sjmp_case_2D11D:
		STORE8			byte_7DA,$00
		SUSPEND

; =============== S C R I P T ===============================================
_scr_2D122:
		NJSR			_nsub_2D23D
		NJSR			_nsub_2D1A8
		SBCC			_sloc_2D133
		NJSR			_nsub_new_thread_start
			NARGB		$2F
			NARGB		$00,$18
			NARGB		$03
			NARGB		$00
_sloc_2D133:
		SARG_SET		SARG1,$72
		SJMP			_sloc_62E25

; =============== S C R I P T ===============================================
_scr_2D139:
		NJSR			_nsub_2D23D
		NJSR			_nsub_2D1A8
		SBCC			_sloc_2D14A
		NJSR			_nsub_new_thread_start
			NARGB		$2F
			NARGB		$00,$18
			NARGB		$03
			NARGB		$00
_sloc_2D14A:
		SARG_SET		SARG1,$74
		SJMP			_sloc_62E2C
byte_2D150:
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$25,$15,$0F
byte_2D15C:
		.BYTE	$0F,$36,$1B,$0F
byte_2D160:
		.BYTE	$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_2D164:
		LDX		#$10
		LDY		#$16
		JSR		sub_61DD6
		BCC		loc_2D178
		LDA		#$01
		STA		byte_7DA
		JSR		_cur_thread_reload_param
		.WORD	_scr_2D0D6
		RTS
loc_2D178:
		LDX		#$0F
		LDY		#$18
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_2D17F:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_2D198
		LSR
		LDA		#$0F
		STA		_scores_obj_value
		BCS		loc_2D193
		JSR		_cur_thread_reload_param
		.WORD	_scr_2D122
		RTS
loc_2D193:
		JSR		_cur_thread_reload_param
		.WORD	_scr_2D139
locret_2D198:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D199:
		LDA		byte_7DB
		CMP		#$03
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D19F:
		LDA		byte_7DB
		BNE		loc_2D1A6
		SEC
		RTS
loc_2D1A6:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D1A8:
		LDA		byte_7DB
		CMP		#$01
		BEQ		locret_2D1B0
		CLC
locret_2D1B0:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D1B1:
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_spr_idx,X
		LDA		byte_2D1BB-$5A,Y
		STA		_scr_trds_spr_idx,X
		RTS
byte_2D1BB:
		.BYTE	$5D,$5A,$5B,$5C

; =============== S U B R O U T I N E =======================================
_nsub_2D1BF:
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		STA		_tmp2
		LDY		#$02
loc_2D1CB:
		TYA
		PHA
		LDX		byte_7D7,Y
		BMI		loc_2D1EC
		LDA		_scr_trds_idx,X
		BMI		loc_2D1EC
		LDA		_scr_trds_args0,X
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

; =============== S U B R O U T I N E =======================================
_nsub_2D1F2:
		LDA		byte_7DA
		BEQ		locret_2D214
		LDY		#$02
loc_2D1F9:
		LDX		byte_7D7,Y
		BMI		loc_2D207
		LDA		_scr_trds_idx,X
		BMI		loc_2D207
		LDA		_scr_trds_args0,X
		BNE		loc_2D212
loc_2D207:
		DEY
		BPL		loc_2D1F9
		LDA		#$00
		STA		byte_7DA
		LDA		#$01
		RTS
loc_2D212:
		LDA		#$02
locret_2D214:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D215:
		LDY		#$02
loc_2D217:
		LDX		byte_7D7,Y
		BMI		loc_2D225
		LDA		_scr_trds_idx,X
		BMI		loc_2D225
		LDA		_scr_trds_args1,X
		STA		_scr_trds_args2,X
loc_2D225:
		DEY
		BPL		loc_2D217
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D229:
		LDY		#$02
loc_2D22B:
		LDX		byte_7D7,Y
		BMI		loc_2D239
		LDA		_scr_trds_idx,X
		BMI		loc_2D239
		LDA		_scr_trds_args2,X
		STA		_scr_trds_args1,X
loc_2D239:
		DEY
		BPL		loc_2D22B
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D23D:
		LDY		#$02
loc_2D23F:
		LDA		byte_7D7,Y
		CMP		_scr_cur_trd_idx
		BEQ		loc_2D24C
		DEY
		BPL		loc_2D23F
loc_2D249:
		JMP		loc_2D249
loc_2D24C:
		LDA		#$FF
		STA		byte_7D7,Y
		LDA		#$02
		STA		byte_7DA
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D257:
		LDX		#$00
loc_2D259:
		LDA		byte_7D7,X
		BMI		loc_2D266
		INX
		CPX		#$03
		BCC		loc_2D259
loc_2D263:
		JMP		loc_2D263
loc_2D266:
		LDA		_nsub_return_value
		STA		byte_7D7,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D26C:
		LDA		#$FF
		STA		byte_7D7
		STA		byte_7D7+1
		STA		byte_7D7+2
		LDA		#$00
		STA		byte_7DA
		LDA		#$0A
		STA		byte_7DB
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D282:
		JSR		sub_2D2A7
		TAY
		LDX		byte_7D7,Y
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,X
		STA		_scr_trds_x_pos_lo,Y
		LDA		_scr_trds_x_pos_hi,X
		STA		_scr_trds_x_pos_hi,Y
		LDA		_scr_trds_y_pos_lo,X
		STA		_scr_trds_y_pos_lo,Y
		LDA		_scr_trds_y_pos_hi,X
		STA		_scr_trds_y_pos_hi,Y
		LDA		_scr_trds_args1,X
		STA		_scr_trds_args1,Y
		RTS

; =============== S U B R O U T I N E =======================================
sub_2D2A7:
		LDY		#$02
loc_2D2A9:
		LDA		byte_7D7,Y
		BMI		loc_2D2B4
		DEY
		BPL		loc_2D2A9
loc_2D2B1:
		JMP		loc_2D2B1
loc_2D2B4:
		LDA		byte_2D2B8,Y
		RTS
byte_2D2B8:
		.BYTE	$02,$00,$01

; =============== S U B R O U T I N E =======================================
_nsub_2D2BB:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_x_pos_lo,X
		BEQ		loc_2D2C8
		BCS		loc_2D2CA
		STA		_scr_trds_x_pos_lo,X
loc_2D2C8:
		SEC
		RTS
loc_2D2CA:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D2CC:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_x_pos_lo,X
		BCC		locret_2D2D7
		STA		_scr_trds_x_pos_lo,X
locret_2D2D7:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D2D8:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_y_pos_lo,X
		BCC		locret_2D2E3
		STA		_scr_trds_y_pos_lo,X
locret_2D2E3:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2D2E4:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_y_pos_lo,X
		BEQ		loc_2D2F1
		BCS		loc_2D2F3
		STA		_scr_trds_y_pos_lo,X
loc_2D2F1:
		SEC
		RTS
loc_2D2F3:
		CLC
		RTS
_spr_raw_lib1A_6B:
		.BYTE	$0C
		.BYTE	$08,$84,$42,$08
		.BYTE	$F8,$82,$42,$08
		.BYTE	$E8,$80,$42,$08
		.BYTE	$08,$94,$42,$00
		.BYTE	$F8,$92,$42,$00
		.BYTE	$E8,$90,$42,$00
		.BYTE	$08,$84,$02,$F0
		.BYTE	$F8,$82,$02,$F0
		.BYTE	$E8,$80,$02,$F0
		.BYTE	$08,$94,$02,$F8
		.BYTE	$F8,$92,$02,$F8
		.BYTE	$E8,$90,$02,$F8
_spr_raw_lib1A_6C:
		.BYTE	$0A
		.BYTE	$08,$9E,$42,$F0
		.BYTE	$08,$9E,$02,$08
		.BYTE	$08,$8C,$02,$F8
		.BYTE	$08,$9C,$02,$00
		.BYTE	$F8,$AA,$02,$04
		.BYTE	$F8,$9A,$02,$FC
		.BYTE	$F8,$8A,$02,$F4
		.BYTE	$E8,$A8,$02,$04
		.BYTE	$E8,$98,$02,$FC
		.BYTE	$E8,$88,$02,$F4
_spr_raw_lib1A_6D:
		.BYTE	$0C
		.BYTE	$E8,$B0,$42,$F0
		.BYTE	$F8,$B2,$42,$F0
		.BYTE	$08,$B4,$42,$F0
		.BYTE	$08,$A4,$42,$F8
		.BYTE	$F8,$A2,$42,$F8
		.BYTE	$E8,$A0,$42,$F8
		.BYTE	$08,$B4,$02,$08
		.BYTE	$08,$A4,$02,$00
		.BYTE	$F8,$B2,$02,$08
		.BYTE	$F8,$A2,$02,$00
		.BYTE	$E8,$B0,$02,$08
		.BYTE	$E8,$A0,$02,$00
_spr_raw_lib1A_6A:
		.BYTE	$0A
		.BYTE	$08,$9E,$02,$08
		.BYTE	$08,$8C,$42,$00
		.BYTE	$08,$9E,$42,$F0
		.BYTE	$08,$9C,$42,$F8
		.BYTE	$F8,$AA,$42,$F4
		.BYTE	$F8,$9A,$42,$FC
		.BYTE	$F8,$8A,$42,$04
		.BYTE	$E8,$A8,$42,$F4
		.BYTE	$E8,$98,$42,$FC
		.BYTE	$E8,$88,$42,$04
_spr_raw_lib1A_6F:
		.BYTE	$0C
		.BYTE	$08,$84,$42,$0A
		.BYTE	$F8,$82,$42,$0A
		.BYTE	$E8,$80,$42,$0A
		.BYTE	$08,$94,$42,$02
		.BYTE	$F8,$92,$42,$02
		.BYTE	$E8,$90,$42,$02
		.BYTE	$08,$84,$02,$F2
		.BYTE	$F8,$82,$02,$F2
		.BYTE	$E8,$80,$02,$F2
		.BYTE	$08,$94,$02,$FA
		.BYTE	$F8,$92,$02,$FA
		.BYTE	$E8,$90,$02,$FA
_spr_raw_lib1A_70:
		.BYTE	$0A
		.BYTE	$08,$9E,$42,$F2
		.BYTE	$08,$9E,$02,$0A
		.BYTE	$08,$8C,$02,$FA
		.BYTE	$08,$9C,$02,$02
		.BYTE	$F8,$AA,$02,$06
		.BYTE	$F8,$9A,$02,$FE
		.BYTE	$F8,$8A,$02,$F6
		.BYTE	$E8,$A8,$02,$06
		.BYTE	$E8,$98,$02,$FE
		.BYTE	$E8,$88,$02,$F6
_spr_raw_lib1A_71:
		.BYTE	$0C
		.BYTE	$E8,$B0,$42,$F2
		.BYTE	$F8,$B2,$42,$F2
		.BYTE	$08,$B4,$42,$F2
		.BYTE	$08,$A4,$42,$FA
		.BYTE	$F8,$A2,$42,$FA
		.BYTE	$E8,$A0,$42,$FA
		.BYTE	$08,$B4,$02,$0A
		.BYTE	$08,$A4,$02,$02
		.BYTE	$F8,$B2,$02,$0A
		.BYTE	$F8,$A2,$02,$02
		.BYTE	$E8,$B0,$02,$0A
		.BYTE	$E8,$A0,$02,$02
_spr_raw_lib1A_6E:
		.BYTE	$0A
		.BYTE	$08,$9E,$02,$0A
		.BYTE	$08,$8C,$42,$02
		.BYTE	$08,$9E,$42,$F2
		.BYTE	$08,$9C,$42,$FA
		.BYTE	$F8,$AA,$42,$F6
		.BYTE	$F8,$9A,$42,$FE
		.BYTE	$F8,$8A,$42,$06
		.BYTE	$E8,$A8,$42,$F6
		.BYTE	$E8,$98,$42,$FE
		.BYTE	$E8,$88,$42,$06
_spr_raw_lib1A_5B:
		.BYTE	$0C
		.BYTE	$08,$84,$43,$08
		.BYTE	$F8,$82,$43,$08
		.BYTE	$E8,$80,$43,$08
		.BYTE	$08,$94,$43,$00
		.BYTE	$F8,$92,$43,$00
		.BYTE	$E8,$90,$43,$00
		.BYTE	$08,$84,$03,$F0
		.BYTE	$F8,$82,$03,$F0
		.BYTE	$E8,$80,$03,$F0
		.BYTE	$08,$94,$03,$F8
		.BYTE	$F8,$92,$03,$F8
		.BYTE	$E8,$90,$03,$F8
_spr_raw_lib1A_5F:
		.BYTE	$0C
		.BYTE	$07,$8E,$03,$00
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8E,$43,$F8
		.BYTE	$F7,$82,$43,$08
		.BYTE	$F7,$92,$43,$00
		.BYTE	$E7,$80,$43,$08
		.BYTE	$E7,$90,$43,$00
		.BYTE	$F7,$92,$03,$F8
		.BYTE	$F7,$82,$03,$F0
		.BYTE	$E7,$80,$03,$F0
		.BYTE	$E7,$90,$03,$F8
_spr_raw_lib1A_63:
		.BYTE	$0C
		.BYTE	$08,$9E,$43,$F0
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$BE,$03,$00
		.BYTE	$08,$AE,$03,$F8
		.BYTE	$F8,$82,$43,$08
		.BYTE	$E8,$80,$43,$08
		.BYTE	$F8,$92,$43,$00
		.BYTE	$E8,$90,$43,$00
		.BYTE	$F8,$82,$03,$F0
		.BYTE	$E8,$80,$03,$F0
		.BYTE	$F8,$92,$03,$F8
		.BYTE	$E8,$90,$03,$F8
_spr_raw_lib1A_5C:
		.BYTE	$0A
		.BYTE	$08,$9E,$43,$F0
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$8C,$03,$F8
		.BYTE	$08,$9C,$03,$00
		.BYTE	$F8,$AA,$03,$04
		.BYTE	$F8,$9A,$03,$FC
		.BYTE	$F8,$8A,$03,$F4
		.BYTE	$E8,$A8,$03,$04
		.BYTE	$E8,$98,$03,$FC
		.BYTE	$E8,$88,$03,$F4
_spr_raw_lib1A_60:
		.BYTE	$0A
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$8C,$03,$F8
		.BYTE	$07,$BC,$03,$00
		.BYTE	$F7,$AA,$03,$04
		.BYTE	$F7,$9A,$03,$FC
		.BYTE	$F7,$8A,$03,$F4
		.BYTE	$E7,$A8,$03,$04
		.BYTE	$E7,$98,$03,$FC
		.BYTE	$E7,$88,$03,$F4
_spr_raw_lib1A_64:
		.BYTE	$0A
		.BYTE	$08,$9E,$43,$F0
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$AC,$03,$F8
		.BYTE	$08,$BC,$03,$00
		.BYTE	$F8,$AA,$03,$05
		.BYTE	$F8,$9A,$03,$FD
		.BYTE	$F8,$8A,$03,$F5
		.BYTE	$E8,$A8,$03,$05
		.BYTE	$E8,$98,$03,$FD
		.BYTE	$E8,$88,$03,$F5
_spr_raw_lib1A_5D:
		.BYTE	$0C
		.BYTE	$E8,$B0,$43,$F0
		.BYTE	$F8,$B2,$43,$F0
		.BYTE	$08,$B4,$43,$F0
		.BYTE	$08,$A4,$43,$F8
		.BYTE	$F8,$A2,$43,$F8
		.BYTE	$E8,$A0,$43,$F8
		.BYTE	$08,$B4,$03,$08
		.BYTE	$08,$A4,$03,$00
		.BYTE	$F8,$B2,$03,$08
		.BYTE	$F8,$A2,$03,$00
		.BYTE	$E8,$B0,$03,$08
		.BYTE	$E8,$A0,$03,$00
_spr_raw_lib1A_61:
		.BYTE	$0C
		.BYTE	$E7,$B0,$43,$F0
		.BYTE	$F7,$B2,$43,$F0
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8E,$43,$F8
		.BYTE	$F7,$A2,$43,$F8
		.BYTE	$E7,$A0,$43,$F8
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$8E,$03,$00
		.BYTE	$F7,$B2,$03,$08
		.BYTE	$F7,$A2,$03,$00
		.BYTE	$E7,$B0,$03,$08
		.BYTE	$E7,$A0,$03,$00
_spr_raw_lib1A_65:
		.BYTE	$0C
		.BYTE	$E8,$B0,$43,$F0
		.BYTE	$F8,$B2,$43,$F0
		.BYTE	$08,$9E,$43,$F0
		.BYTE	$08,$B8,$03,$F8
		.BYTE	$F8,$A2,$43,$F8
		.BYTE	$E8,$A0,$43,$F8
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$BA,$03,$00
		.BYTE	$F8,$B2,$03,$08
		.BYTE	$F8,$A2,$03,$00
		.BYTE	$E8,$B0,$03,$08
		.BYTE	$E8,$A0,$03,$00
_spr_raw_lib1A_5A:
		.BYTE	$0A
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$8C,$43,$00
		.BYTE	$08,$9E,$43,$F0
		.BYTE	$08,$9C,$43,$F8
		.BYTE	$F8,$AA,$43,$F4
		.BYTE	$F8,$9A,$43,$FC
		.BYTE	$F8,$8A,$43,$04
		.BYTE	$E8,$A8,$43,$F4
		.BYTE	$E8,$98,$43,$FC
		.BYTE	$E8,$88,$43,$04
_spr_raw_lib1A_5E:
		.BYTE	$0A
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8C,$43,$00
		.BYTE	$07,$BC,$43,$F8
		.BYTE	$F7,$AA,$43,$F4
		.BYTE	$F7,$9A,$43,$FC
		.BYTE	$F7,$8A,$43,$04
		.BYTE	$E7,$A8,$43,$F4
		.BYTE	$E7,$98,$43,$FC
		.BYTE	$E7,$88,$43,$04
_spr_raw_lib1A_62:
		.BYTE	$0A
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$9E,$43,$F0
		.BYTE	$08,$AC,$43,$00
		.BYTE	$08,$BC,$43,$F8
		.BYTE	$F8,$AA,$43,$F3
		.BYTE	$F8,$9A,$43,$FB
		.BYTE	$F8,$8A,$43,$03
		.BYTE	$E8,$A8,$43,$F3
		.BYTE	$E8,$98,$43,$FB
		.BYTE	$E8,$88,$43,$03
_spr_raw_lib1A_67:
		.BYTE	$0C
		.BYTE	$08,$84,$43,$0A
		.BYTE	$F8,$82,$43,$0A
		.BYTE	$E8,$80,$43,$0A
		.BYTE	$08,$94,$43,$02
		.BYTE	$F8,$92,$43,$02
		.BYTE	$E8,$90,$43,$02
		.BYTE	$08,$84,$03,$F2
		.BYTE	$F8,$82,$03,$F2
		.BYTE	$E8,$80,$03,$F2
		.BYTE	$08,$94,$03,$FA
		.BYTE	$F8,$92,$03,$FA
		.BYTE	$E8,$90,$03,$FA
_spr_raw_lib1A_68:
		.BYTE	$0A
		.BYTE	$08,$9E,$43,$F2
		.BYTE	$08,$9E,$03,$0A
		.BYTE	$08,$8C,$03,$FA
		.BYTE	$08,$9C,$03,$02
		.BYTE	$F8,$AA,$03,$06
		.BYTE	$F8,$9A,$03,$FE
		.BYTE	$F8,$8A,$03,$F6
		.BYTE	$E8,$A8,$03,$06
		.BYTE	$E8,$98,$03,$FE
		.BYTE	$E8,$88,$03,$F6
_spr_raw_lib1A_69:
		.BYTE	$0C
		.BYTE	$E8,$B0,$43,$F2
		.BYTE	$F8,$B2,$43,$F2
		.BYTE	$08,$B4,$43,$F2
		.BYTE	$08,$A4,$43,$FA
		.BYTE	$F8,$A2,$43,$FA
		.BYTE	$E8,$A0,$43,$FA
		.BYTE	$08,$B4,$03,$0A
		.BYTE	$08,$A4,$03,$02
		.BYTE	$F8,$B2,$03,$0A
		.BYTE	$F8,$A2,$03,$02
		.BYTE	$E8,$B0,$03,$0A
		.BYTE	$E8,$A0,$03,$02
_spr_raw_lib1A_66:
		.BYTE	$0A
		.BYTE	$08,$9E,$03,$0A
		.BYTE	$08,$8C,$43,$02
		.BYTE	$08,$9E,$43,$F2
		.BYTE	$08,$9C,$43,$FA
		.BYTE	$F8,$AA,$43,$F6
		.BYTE	$F8,$9A,$43,$FE
		.BYTE	$F8,$8A,$43,$06
		.BYTE	$E8,$A8,$43,$F6
		.BYTE	$E8,$98,$43,$FE
		.BYTE	$E8,$88,$43,$06
_spr_raw_lib1A_72:
		.BYTE	$0A
		.BYTE	$08,$E0,$03,$F8
		.BYTE	$08,$D0,$03,$F0
		.BYTE	$F8,$92,$03,$F0
		.BYTE	$F8,$92,$43,$F8
		.BYTE	$F8,$C0,$43,$E8
		.BYTE	$F8,$C0,$03,$00
		.BYTE	$E8,$80,$03,$E8
		.BYTE	$E8,$80,$43,$00
		.BYTE	$E8,$90,$43,$F8
		.BYTE	$E8,$90,$03,$F0
_spr_raw_lib1A_73:
		.BYTE	$06
		.BYTE	$00,$D2,$03,$F8
		.BYTE	$00,$C2,$03,$F0
		.BYTE	$F0,$80,$03,$E8
		.BYTE	$F0,$80,$43,$00
		.BYTE	$F0,$90,$43,$F8
		.BYTE	$F0,$90,$03,$F0
_spr_raw_lib1A_74:
		.BYTE	$0A
		.BYTE	$08,$E0,$43,$00
		.BYTE	$08,$D0,$43,$08
		.BYTE	$F8,$92,$43,$08
		.BYTE	$F8,$92,$03,$00
		.BYTE	$F8,$C0,$03,$10
		.BYTE	$F8,$C0,$43,$F8
		.BYTE	$E8,$80,$43,$10
		.BYTE	$E8,$80,$03,$F8
		.BYTE	$E8,$90,$03,$00
		.BYTE	$E8,$90,$43,$08
_spr_raw_lib1A_75:
		.BYTE	$06
		.BYTE	$00,$D2,$43,$00
		.BYTE	$00,$C2,$43,$08
		.BYTE	$F0,$80,$43,$10
		.BYTE	$F0,$80,$03,$F8
		.BYTE	$F0,$90,$03,$00
		.BYTE	$F0,$90,$43,$08

; =============== S C R I P T ===============================================
_sjmp_case_2D7B1:
		SARG_SET		SARG0,$00
		SPR_IDX_SET		0,$76
		SDELAY			$20
		POS_Y_DELTA_SET 4,$00,$02
		POS_MOVE_STOP	0
		SPR_IDX_SET		4,$78
		SPR_IDX_INC		4
		SPR_IDX_SET		0,$76
		SDELAY			$3C
		NJSR			_nsub_62BA9
		SUSPEND
_spr_raw_lib1A_76:
		.BYTE	$04
		.BYTE	$00,$36,$03,$00
		.BYTE	$00,$36,$43,$F8
		.BYTE	$F0,$A6,$43,$00
		.BYTE	$F0,$A6,$03,$F8
_spr_raw_lib1A_77:
		.BYTE	$04		; *--
		.BYTE	$00,$4E,$03,$F8	; *--
		.BYTE	$00,$4E,$43,$00	; *--
		.BYTE	$F0,$A6,$43,$00	; *--
		.BYTE	$F0,$A6,$03,$F8	; *--
_spr_raw_lib1A_78:
		.BYTE	$06
		.BYTE	$F8,$58,$03,$08
		.BYTE	$F0,$58,$03,$F0
		.BYTE	$00,$4E,$03,$F8
		.BYTE	$00,$4E,$43,$00
		.BYTE	$F0,$A6,$43,$00
		.BYTE	$F0,$A6,$03,$F8
_spr_raw_lib1A_79:
		.BYTE	$06
		.BYTE	$F8,$48,$03,$08
		.BYTE	$F0,$48,$03,$F0
		.BYTE	$00,$4E,$03,$F8
		.BYTE	$00,$4E,$43,$00
		.BYTE	$F0,$A6,$43,$00
		.BYTE	$F0,$A6,$03,$F8

; =============== S C R I P T ===============================================
_sjmp_case_2D81B:
		SARG_SET		SARG0,$00
		NJSR			_nsub_2D848
		SLOOP_BEGIN		$03
		SPR_IDX_SET		2,$FF
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG2
		SDELAY			$02
		SLOOP_END
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$0F
		NBG_HNDL_SET	_nbgsub_2D83E
		NJSR			_nsub_6273D
			NARGB		$7C,$20
		NJSR			_nsub_628D1
			NARGB		$00,$03
		SUSPEND

; =============== S U B R O U T I N E =======================================
_nbgsub_2D83E:
		LDX		#$09
		LDY		#$0A
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E =======================================
_nsub_2D848:
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_args1,Y
		CLC
		ADC		#$20
		AND		#$C0
		ASL
		ROL
		ROL
		TAX
		LDA		_scr_trds_x_pos_lo,Y
		CLC
		ADC		byte_2D886,X
		STA		_scr_trds_x_pos_lo,Y
		LDA		_scr_trds_x_pos_hi,Y
		ADC		byte_2D88A,X
		STA		_scr_trds_x_pos_hi,Y
		LDA		_scr_trds_y_pos_lo,Y
		CLC
		ADC		byte_2D88E,X
		STA		_scr_trds_y_pos_lo,Y
		LDA		_scr_trds_y_pos_hi,Y
		ADC		byte_2D892,X
		STA		_scr_trds_y_pos_hi,Y
		TXA
		AND		#$01
		CLC
		ADC		#$7A
		STA		_scr_trds_args2,Y
		RTS
byte_2D886:
		.BYTE	$00,$05,$00,$FB
byte_2D88A:
		.BYTE	$00,$00,$00,$FF
byte_2D88E:
		.BYTE	$E8,$FE,$FD,$FE
byte_2D892:
		.BYTE	$FF,$FF,$FF,$FF
_spr_raw_lib1A_7A:
		.BYTE	$02
		.BYTE	$FC,$96,$01,$00
		.BYTE	$FC,$96,$01,$F8
_spr_raw_lib1A_7B:
		.BYTE	$01
		.BYTE	$FC,$96,$01,$FC
_spr_raw_lib1A_80:
		.BYTE	$02
		.BYTE	$F8,$86,$41,$00
		.BYTE	$F8,$86,$01,$F8
_spr_raw_lib1A_81:
		.BYTE	$02
		.BYTE	$F8,$F0,$C1,$00
		.BYTE	$F8,$F0,$01,$F8
_spr_raw_lib1A_82:
		.BYTE	$02
		.BYTE	$F8,$B6,$01,$F8
		.BYTE	$F8,$B6,$41,$00
_spr_raw_lib1A_83:
		.BYTE	$02
		.BYTE	$F8,$F0,$41,$00
		.BYTE	$F8,$F0,$81,$F8

; =============== S C R I P T ===============================================
_scr30_lvl6_boss_vega:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_lvl6_boss_vega_sub1
		SCASE			_lvl6_boss_vega_sub2
		SCASE			_lvl6_boss_vega_sub3
		SCASE			_lvl6_boss_vega_sub4
		SLOOP_BEGIN		$C8							; default initialization
		SMEM_ALU		_apu_mus_volume,_ADC,$FF	; slowly lower the music volume
		SDELAY			$02							; in about 6 seconds
		SLOOP_END
		NJSR			_nsub_apu_snd_load_safe		; start laughing sound effect
			NARGB		$0E
		SDELAY			$64
		STORE8			_apu_mus_volume,$FF			; restore music volume and play
		NJSR			_nsub_apu_mus_load			; boss music
			NARGB		$0B
		SPR_IDX_SET		0,$C0						; display sprite (hidden)
		SLOOP_BEGIN		$04							; slowly reveal through the
		NJSR			_nsub_pal_fade_req_inc_by_mask	; palette fade in effect
			NARGB		$22
		SDELAY			$06
		SLOOP_END
		STORE16			byte_7D7,$800				; set HP for this boss
		NBG_HNDL_SET	_nbgsub_lvl6_boss_vega_damage_count	; set bg damage detection routine
		SSCRIPT1_SET	_scr_lvl6_boss_vega_blinker	; start damage blinker secondary script
		SDELAY			$B4							; now wait for a while
		POS_Y_DELTA_SET 0,$80,$00					; and move forth from the painting
		SDELAY			$60
		POS_MOVE_STOP	0							; stop, get to the main loop
_sloc_2D90E:
		SPR_IDX_SET		0,$C0						; delay before attack
		SDELAY			$62
		SARG_SET		SARG1,$00					; reset attack tmp var
		NJSR			_nsub_new_thread_start		; start to attack
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_lvl6_boss_vega_sub1_idx+1
			NARGB		$20
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_lvl6_boss_vega_sub1_idx+1
			NARGB		$60
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_lvl6_boss_vega_sub1_idx+1
			NARGB		$A0
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_lvl6_boss_vega_sub1_idx+1
			NARGB		$E0
		SDELAY			$2E
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
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_lvl6_boss_vega_sub2_idx+1
			NARGB		$00
		SDELAY			$20
		SPR_IDX_SET		0,$C0
		SDELAY			$10
		SPR_IDX_SET		0,$C5
		SDELAY			$08
		NJSR			_nsub_2DA70
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_lvl6_boss_vega_sub3_idx+1
			NARGB		$4C
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_lvl6_boss_vega_sub3_idx+1
			NARGB		$6C
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_lvl6_boss_vega_sub3_idx+1
			NARGB		$8C
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$08
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_lvl6_boss_vega_sub3_idx+1
			NARGB		$74
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_lvl6_boss_vega_sub3_idx+1
			NARGB		$94
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_lvl6_boss_vega_sub3_idx+1
			NARGB		$B4
		SDELAY			$10
		SJMP			_sloc_2D90E

; =============== S C R I P T ===============================================
_scr_lvl6_boss_vega_blinker:
		SDELAY			$01
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$00
		SJMP_SW			$01
		SCASE			_scr_lvl6_boss_vega_blinker
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2D9B8
		SDELAY			$01
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2D9B4
		SDELAY			$01
		SJMP			_scr_lvl6_boss_vega_blinker
byte_2D9B4:
		.BYTE	$0F,$36,$17,$0F
byte_2D9B8:
		.BYTE	$0F,$20,$20,$20

; =============== S C R I P T ===============================================
_scr_lvl6_boss_vega_death:
		NJSR			_nsub_gen_threads_off_except_cur
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_2D9B4
		SPR_IDX_SET		0,$C1
		SDELAY			$40
		SPR_IDX_SET		0,$C7
		SDELAY			$10
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$1A
		POS_Y_DELTA_SET 0,$00,$FC
		SPR_IDX_SET		4,$84
		SPR_IDX_INC		4
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_INC		4
		POS_Y_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		4
		POS_MOVE_STOP	0
		SPR_IDX_INC		4
		SPR_IDX_SET		0,$FF
		SDELAY			$5A
		NJSR			_nsub_2DA7D
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$98,$00
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
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$58
			NARGB		_lvl6_boss_vega_sub4_idx+1
			NARGB		$00
		SDELAY			$40
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask
			NARGB		$FF
		SDELAY			$08
		SLOOP_END
		STORE8			_game_flags,$80
		NJSR			_nsub_all_threads_off_except_cur
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_lvl6_boss_vega_damage_count:
		LDX		#$15
		LDY		#$26
		JSR		_player_to_obj_collision_test
		LDX		#$10
		LDY		#$18
		JSR		sub_61DD6
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BEQ		locret_2DA6F
		LDA		byte_7D7
		SEC
		SBC		#$01
		STA		byte_7D7
		LDA		byte_7D7+1
		SBC		#$00
		STA		byte_7D7+1
		ORA		byte_7D7
		BNE		locret_2DA6F
		JSR		_cur_thread_reload_param
		.WORD	_scr_lvl6_boss_vega_death
		LDA		#$C8
		JSR		_scores_add
locret_2DA6F:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2DA70:
		LDA		#$21
		JSR		_rand
		SEC
		SBC		#$10
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_2DA7D:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_602EE
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_60FEE
		RTS
_spr_res_lib1A_00:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_00_B
_spr_res_lib1A_03:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_03_B
_spr_res_lib1A_01:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_01_B
_spr_res_lib1A_04:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_04_B
_spr_res_lib1A_02:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_02_B
_spr_res_lib1A_05:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_05_B
_spr_res_lib1A_06:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_06_B
_spr_res_lib1A_07:
		.BYTE	$02
		.WORD	_spr_res_lib1A_00_A
		.WORD	_spr_res_lib1A_07_B
_spr_res_lib1A_00_A:
		.BYTE	$12
		.BYTE	$17,$9A,$42,$10
		.BYTE	$27,$9C,$42,$10
		.BYTE	$27,$AC,$42,$08
		.BYTE	$17,$AA,$42,$08
		.BYTE	$07,$A8,$42,$08
		.BYTE	$C7,$A0,$42,$08
		.BYTE	$17,$BA,$42,$00
		.BYTE	$07,$B8,$42,$00
		.BYTE	$F7,$B6,$42,$00
		.BYTE	$17,$9A,$02,$E8
		.BYTE	$27,$9C,$02,$E8
		.BYTE	$27,$AC,$02,$F0
		.BYTE	$17,$AA,$02,$F0
		.BYTE	$07,$A8,$02,$F0
		.BYTE	$C7,$A0,$02,$F0
		.BYTE	$17,$BA,$02,$F8
		.BYTE	$07,$B8,$02,$F8
		.BYTE	$F7,$B6,$02,$F8
_spr_res_lib1A_00_B:
		.BYTE	$14
		.BYTE	$E8,$84,$42,$18
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$94,$42,$10
		.BYTE	$F8,$96,$42,$10
		.BYTE	$F8,$A6,$42,$08
		.BYTE	$E8,$A4,$42,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$84,$02,$E0
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$94,$02,$E8
		.BYTE	$F8,$96,$02,$E8
		.BYTE	$F8,$A6,$02,$F0
		.BYTE	$E8,$A4,$02,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$E8,$B4,$02,$F8
_spr_res_lib1A_03_B:
		.BYTE	$10
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$AE,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$9E,$02,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$E8,$8E,$02,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$AE,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$9E,$42,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$E8,$8E,$42,$F8
_spr_res_lib1A_01_B:
		.BYTE	$10
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$E8,$B4,$02,$F8
_spr_res_lib1A_04_B:
		.BYTE	$11
		.BYTE	$E8,$EE,$42,$E8
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$D8,$02,$10
		.BYTE	$F8,$F8,$02,$10
		.BYTE	$F8,$E8,$02,$08
		.BYTE	$E8,$C8,$02,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$D8,$EC,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$DE,$42,$F0
		.BYTE	$D8,$DC,$42,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$CC,$42,$F8
		.BYTE	$E8,$CE,$42,$F8
_spr_res_lib1A_02_B:
		.BYTE	$11
		.BYTE	$E8,$EE,$02,$10
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$D8,$42,$E8
		.BYTE	$F8,$F8,$42,$E8
		.BYTE	$F8,$E8,$42,$F0
		.BYTE	$E8,$C8,$42,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$E8,$B4,$02,$F8
		.BYTE	$D8,$EC,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$DE,$02,$08
		.BYTE	$D8,$DC,$02,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$CC,$02,$00
		.BYTE	$E8,$CE,$02,$00
_spr_res_lib1A_05_B:
		.BYTE	$12
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$84,$02,$E0
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$94,$02,$E8
		.BYTE	$F8,$96,$02,$E8
		.BYTE	$F8,$A6,$02,$F0
		.BYTE	$E8,$A4,$02,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$E8,$B4,$02,$F8
_spr_res_lib1A_06_B:
		.BYTE	$12
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$E8,$B4,$02,$F8
		.BYTE	$E8,$84,$42,$18
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$94,$42,$10
		.BYTE	$F8,$96,$42,$10
		.BYTE	$F8,$A6,$42,$08
		.BYTE	$E8,$A4,$42,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$E8,$B4,$42,$00
_spr_res_lib1A_07_B:
		.BYTE	$10
		.BYTE	$D8,$92,$42,$10
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$C8,$80,$42,$00
		.BYTE	$D8,$82,$42,$00
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$C8,$80,$02,$F8
		.BYTE	$D8,$82,$02,$F8
		.BYTE	$E8,$B4,$02,$F8
_spr_raw_lib1A_84:
		.BYTE	$1F
		.BYTE	$DA,$92,$42,$0C
		.BYTE	$EA,$DA,$02,$0B
		.BYTE	$22,$9C,$42,$10
		.BYTE	$24,$AC,$42,$08
		.BYTE	$14,$AA,$42,$08
		.BYTE	$05,$A8,$42,$07
		.BYTE	$F8,$BE,$02,$07
		.BYTE	$DC,$A2,$42,$08
		.BYTE	$CC,$A0,$42,$08
		.BYTE	$14,$BA,$42,$00
		.BYTE	$06,$B8,$42,$00
		.BYTE	$CC,$80,$42,$00
		.BYTE	$DC,$82,$42,$00
		.BYTE	$EA,$B4,$42,$00
		.BYTE	$F8,$B6,$42,$00
		.BYTE	$DA,$92,$02,$EC
		.BYTE	$EA,$DA,$42,$EE
		.BYTE	$18,$9A,$02,$E8
		.BYTE	$22,$9C,$02,$EA
		.BYTE	$22,$AC,$02,$F1
		.BYTE	$14,$AA,$02,$F1
		.BYTE	$06,$A8,$02,$F0
		.BYTE	$F8,$BE,$42,$F1
		.BYTE	$DC,$A2,$02,$F1
		.BYTE	$CC,$A0,$02,$F0
		.BYTE	$CC,$80,$02,$F8
		.BYTE	$DC,$82,$02,$F8
		.BYTE	$14,$BA,$02,$F8
		.BYTE	$06,$B8,$02,$F8
		.BYTE	$EA,$B4,$02,$F8
		.BYTE	$F8,$B6,$02,$F8
_spr_raw_lib1A_85:
		.BYTE	$1A
		.BYTE	$DA,$92,$42,$08
		.BYTE	$EA,$DA,$02,$08
		.BYTE	$1F,$9C,$42,$10
		.BYTE	$20,$AC,$42,$08
		.BYTE	$11,$AA,$42,$08
		.BYTE	$03,$A8,$42,$07
		.BYTE	$F8,$BE,$02,$07
		.BYTE	$12,$BA,$42,$00
		.BYTE	$04,$B8,$42,$00
		.BYTE	$CE,$80,$42,$00
		.BYTE	$DE,$82,$42,$00
		.BYTE	$EC,$B4,$42,$00
		.BYTE	$F8,$B6,$42,$00
		.BYTE	$DC,$92,$02,$F0
		.BYTE	$EA,$DA,$42,$F0
		.BYTE	$1D,$9C,$02,$EA
		.BYTE	$1F,$AC,$02,$F1
		.BYTE	$11,$AA,$02,$F1
		.BYTE	$04,$A8,$02,$F1
		.BYTE	$F8,$BE,$42,$F1
		.BYTE	$CE,$80,$02,$F8
		.BYTE	$DE,$82,$02,$F8
		.BYTE	$12,$BA,$02,$F8
		.BYTE	$04,$B8,$02,$F8
		.BYTE	$EC,$B4,$02,$F8
		.BYTE	$F8,$B6,$02,$F8
_spr_raw_lib1A_86:
		.BYTE	$0E
		.BYTE	$F0,$C2,$42,$08
		.BYTE	$00,$C4,$42,$08
		.BYTE	$10,$C6,$42,$08
		.BYTE	$10,$D6,$42,$00
		.BYTE	$00,$D4,$42,$00
		.BYTE	$F0,$D2,$42,$00
		.BYTE	$E0,$D0,$42,$00
		.BYTE	$F0,$C2,$02,$F0
		.BYTE	$00,$C4,$02,$F0
		.BYTE	$10,$C6,$02,$F0
		.BYTE	$10,$D6,$02,$F8
		.BYTE	$00,$D4,$02,$F8
		.BYTE	$F0,$D2,$02,$F8
		.BYTE	$E0,$D0,$02,$F8
_spr_raw_lib1A_87:
		.BYTE	$0E
		.BYTE	$F0,$E2,$42,$08
		.BYTE	$00,$E4,$42,$08
		.BYTE	$10,$E6,$42,$08
		.BYTE	$10,$F6,$42,$00
		.BYTE	$00,$F4,$42,$00
		.BYTE	$F0,$F2,$42,$00
		.BYTE	$E0,$F0,$42,$00
		.BYTE	$F0,$E2,$02,$F0
		.BYTE	$00,$E4,$02,$F0
		.BYTE	$10,$E6,$02,$F0
		.BYTE	$10,$F6,$02,$F8
		.BYTE	$00,$F4,$02,$F8
		.BYTE	$F0,$F2,$02,$F8
		.BYTE	$E0,$F0,$02,$F8
_spr_raw_lib1A_88:
		.BYTE	$0C
		.BYTE	$10,$FA,$C2,$08
		.BYTE	$10,$FA,$82,$00
		.BYTE	$10,$FA,$C2,$F8
		.BYTE	$10,$FA,$82,$F0
		.BYTE	$00,$FA,$C2,$00
		.BYTE	$00,$FA,$82,$F8
		.BYTE	$F0,$EA,$42,$08
		.BYTE	$F0,$EA,$02,$F0
		.BYTE	$F0,$FA,$02,$F8
		.BYTE	$F0,$FA,$42,$00
		.BYTE	$E0,$FA,$42,$00
		.BYTE	$E0,$FA,$02,$F8
_spr_raw_lib1A_91:
		.BYTE	$02
		.BYTE	$F8,$9B,$00,$00
		.BYTE	$F8,$8B,$00,$F8
_spr_raw_lib1A_92:
		.BYTE	$04
		.BYTE	$00,$E5,$00,$00
		.BYTE	$00,$D5,$00,$F8
		.BYTE	$F1,$C5,$40,$F8
		.BYTE	$F1,$C5,$00,$00
_spr_raw_lib1A_93:
		.BYTE	$04
		.BYTE	$00,$E5,$00,$00
		.BYTE	$00,$E5,$40,$F8
		.BYTE	$F0,$C5,$40,$F8
		.BYTE	$F0,$C5,$00,$00
_spr_raw_lib1A_94:
		.BYTE	$04
		.BYTE	$00,$E5,$40,$F8
		.BYTE	$00,$D5,$40,$00
		.BYTE	$F1,$C5,$40,$F8
		.BYTE	$F1,$C5,$00,$00

; =============== S C R I P T ===============================================
_lvl6_boss_vega_sub1:
		SARG_SET		SARG0,$00
		SSCRIPT1_SET	_scr_2DF30
		NBG_HNDL_SET	_nbgsub_2DF36
		NJSR			_nsub_628D1
			NARGB		$00,$04
		SDELAY			$10
		POS_MOVE_STOP	0
		SDELAY			$4E
		SARG_ALU		SARG1,_ADC,$40
		SLOOP_BEGIN		$80
		NJSR			_nsub_628D1
			NARGB		$00,$06
		SDELAY			$01
		SARG_ALU		SARG1,_ADC,$04
		SLOOP_END
		SARG_SET		SARG2,$04
		SLOOP_BEGIN		$07
		SLOOP_BEGIN		$04
		NJSR			_nsub_628D1
			NARGB		$00,$06
		SDELAY			$01
		NJSR			_nsub_2DF3D
		SLOOP_END
		SARG_ALU		SARG2,_ADC,$01
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_scr_2DF30:
		SPR_IDX_SET		1,$8B
		SPR_IDX_INC		1
		SJMP			_scr_2DF30

; =============== S U B R O U T I N E =======================================
_nbgsub_2DF36:
		LDX		#$08
		LDY		#$09
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nsub_2DF3D:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		CLC
		ADC		_scr_trds_args2,X
		STA		_scr_trds_args1,X
		RTS

; =============== S C R I P T ===============================================
_lvl6_boss_vega_sub2:
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

; =============== S C R I P T ===============================================
_lvl6_boss_vega_sub3:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_2DF78
		NJSR			_nsub_628D1
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
		SJMP			_sloc_2DF73

; =============== S U B R O U T I N E =======================================
_nbgsub_2DF78:
		LDX		#$08
		LDY		#$09
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test
_spr_raw_lib1A_89:
		.BYTE	$01
		.BYTE	$F8,$8C,$01,$FC
_spr_raw_lib1A_8A:
		.BYTE	$01
		.BYTE	$F8,$8C,$00,$FC
_spr_raw_lib1A_8B:
		.BYTE	$01
		.BYTE	$F8,$8A,$01,$FC
_spr_raw_lib1A_8C:
		.BYTE	$01
		.BYTE	$F8,$8A,$00,$FC
_spr_raw_lib1A_8D:
		.BYTE	$02
		.BYTE	$F8,$88,$41,$00
		.BYTE	$F8,$88,$01,$F8
_spr_raw_lib1A_8E:
		.BYTE	$02
		.BYTE	$F8,$88,$40,$00
		.BYTE	$F8,$88,$00,$F8
_spr_raw_lib1A_8F:
		.BYTE	$02
		.BYTE	$F8,$98,$41,$00
		.BYTE	$F8,$98,$01,$F8
_spr_raw_lib1A_90:
		.BYTE	$02
		.BYTE	$F8,$98,$40,$00
		.BYTE	$F8,$98,$00,$F8

; =============== S C R I P T ===============================================
_lvl6_boss_vega_sub4:
		POS_Y_DELTA_SET 0,$00,$FF
		SLOOP_BEGIN		$04
		SPR_IDX_SET		4,$92
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SLOOP_END
		POS_MOVE_STOP	0
		SUSPEND
_spr_raw_lib1A:
		.WORD	_spr_raw_lib1A_00
		.WORD	_spr_raw_lib1A_01
		.WORD	_spr_raw_lib1A_02
		.WORD	_spr_raw_lib1A_03
		.WORD	_spr_raw_lib1A_04
		.WORD	_spr_raw_lib1A_05
		.WORD	_spr_raw_lib1A_06
		.WORD	_spr_raw_lib1A_07
		.WORD	_spr_raw_lib1A_08
		.WORD	_spr_raw_lib1A_09
		.WORD	_spr_raw_lib1A_0A
		.WORD	_spr_raw_lib1A_0B
		.WORD	_spr_raw_lib1A_0C
		.WORD	_spr_raw_lib1A_0D
		.WORD	_spr_raw_lib1A_0E
		.WORD	_spr_raw_lib1A_0F
		.WORD	_spr_raw_lib1A_10
		.WORD	_spr_raw_lib1A_11
		.WORD	_spr_raw_lib1A_12
		.WORD	_spr_raw_lib1A_13
		.WORD	_spr_raw_lib1A_14
		.WORD	_spr_raw_lib1A_15
		.WORD	_spr_raw_lib1A_16
		.WORD	_spr_raw_lib1A_17
		.WORD	_spr_raw_lib1A_18
		.WORD	_spr_raw_lib1A_19
		.WORD	_spr_raw_lib1A_1A
		.WORD	_spr_raw_lib1A_1B
		.WORD	_spr_raw_lib1A_1C
		.WORD	_spr_raw_lib1A_1D
		.WORD	_spr_raw_lib1A_1E
		.WORD	_spr_raw_lib1A_1F
		.WORD	_spr_raw_lib1A_20
		.WORD	_spr_raw_lib1A_21
		.WORD	_spr_raw_lib1A_22
		.WORD	_spr_raw_lib1A_23
		.WORD	_spr_raw_lib1A_24
		.WORD	_spr_raw_lib1A_25
		.WORD	_spr_raw_lib1A_26
		.WORD	_spr_raw_lib1A_27
		.WORD	_spr_raw_lib1A_28
		.WORD	_spr_raw_lib1A_29
		.WORD	_spr_raw_lib1A_2A
		.WORD	_spr_raw_lib1A_2B
		.WORD	_spr_raw_lib1A_2C
		.WORD	_spr_raw_lib1A_2D
		.WORD	_spr_raw_lib1A_2E
		.WORD	_spr_raw_lib1A_2F
		.WORD	_spr_raw_lib1A_30
		.WORD	_spr_raw_lib1A_31
		.WORD	_spr_raw_lib1A_32
		.WORD	_spr_raw_lib1A_33
		.WORD	_spr_raw_lib1A_34	; *--
		.WORD	_spr_raw_lib1A_35	; *--
		.WORD	_spr_raw_lib1A_36
		.WORD	_spr_raw_lib1A_37
		.WORD	_spr_raw_lib1A_38
		.WORD	_spr_raw_lib1A_39
		.WORD	_spr_raw_lib1A_3A
		.WORD	_spr_raw_lib1A_3B
		.WORD	_spr_raw_lib1A_3C
		.WORD	_spr_raw_lib1A_3D
		.WORD	_spr_raw_lib1A_3E
		.WORD	_spr_raw_lib1A_3F
		.WORD	_spr_raw_lib1A_40
		.WORD	_spr_raw_lib1A_41
		.WORD	_spr_raw_lib1A_42
		.WORD	_spr_raw_lib1A_43
		.WORD	_spr_raw_lib1A_44
		.WORD	_spr_raw_lib1A_45
		.WORD	_spr_raw_lib1A_46
		.WORD	_spr_raw_lib1A_47
		.WORD	_spr_raw_lib1A_48
		.WORD	_spr_raw_lib1A_49
		.WORD	_spr_raw_lib1A_4A
		.WORD	_spr_raw_lib1A_4B
		.WORD	_spr_raw_lib1A_4C
		.WORD	_spr_raw_lib1A_4D
		.WORD	_spr_raw_lib1A_4E
		.WORD	_spr_raw_lib1A_4F
		.WORD	_spr_raw_lib1A_50
		.WORD	_spr_raw_lib1A_51
		.WORD	_spr_raw_lib1A_52	; *--
		.WORD	_spr_raw_lib1A_53	; *--
		.WORD	_spr_raw_lib1A_54
		.WORD	_spr_raw_lib1A_55
		.WORD	_spr_raw_lib1A_56
		.WORD	_spr_raw_lib1A_57
		.WORD	_spr_raw_lib1A_58
		.WORD	_spr_raw_lib1A_59
		.WORD	_spr_raw_lib1A_5A
		.WORD	_spr_raw_lib1A_5B
		.WORD	_spr_raw_lib1A_5C
		.WORD	_spr_raw_lib1A_5D
		.WORD	_spr_raw_lib1A_5E
		.WORD	_spr_raw_lib1A_5F
		.WORD	_spr_raw_lib1A_60
		.WORD	_spr_raw_lib1A_61
		.WORD	_spr_raw_lib1A_62
		.WORD	_spr_raw_lib1A_63
		.WORD	_spr_raw_lib1A_64
		.WORD	_spr_raw_lib1A_65
		.WORD	_spr_raw_lib1A_66
		.WORD	_spr_raw_lib1A_67
		.WORD	_spr_raw_lib1A_68
		.WORD	_spr_raw_lib1A_69
		.WORD	_spr_raw_lib1A_6A
		.WORD	_spr_raw_lib1A_6B
		.WORD	_spr_raw_lib1A_6C
		.WORD	_spr_raw_lib1A_6D
		.WORD	_spr_raw_lib1A_6E
		.WORD	_spr_raw_lib1A_6F
		.WORD	_spr_raw_lib1A_70
		.WORD	_spr_raw_lib1A_71
		.WORD	_spr_raw_lib1A_72
		.WORD	_spr_raw_lib1A_73
		.WORD	_spr_raw_lib1A_74
		.WORD	_spr_raw_lib1A_75
		.WORD	_spr_raw_lib1A_76
		.WORD	_spr_raw_lib1A_77	; *--
		.WORD	_spr_raw_lib1A_78
		.WORD	_spr_raw_lib1A_79
		.WORD	_spr_raw_lib1A_7A
		.WORD	_spr_raw_lib1A_7B
		.WORD	_spr_raw_lib1A_80
		.WORD	_spr_raw_lib1A_81
		.WORD	_spr_raw_lib1A_82
		.WORD	_spr_raw_lib1A_83
		.WORD	_spr_raw_lib1A_80
		.WORD	_spr_raw_lib1A_81
		.WORD	_spr_raw_lib1A_82
		.WORD	_spr_raw_lib1A_83
		.WORD	_spr_raw_lib1A_84
		.WORD	_spr_raw_lib1A_85
		.WORD	_spr_raw_lib1A_86
		.WORD	_spr_raw_lib1A_87
		.WORD	_spr_raw_lib1A_88
		.WORD	_spr_raw_lib1A_89
		.WORD	_spr_raw_lib1A_8A
		.WORD	_spr_raw_lib1A_8B
		.WORD	_spr_raw_lib1A_8C
		.WORD	_spr_raw_lib1A_8D
		.WORD	_spr_raw_lib1A_8E
		.WORD	_spr_raw_lib1A_8F
		.WORD	_spr_raw_lib1A_90
		.WORD	_spr_raw_lib1A_91
		.WORD	_spr_raw_lib1A_92
		.WORD	_spr_raw_lib1A_93
		.WORD	_spr_raw_lib1A_94
_spr_res_lib1A:
		.WORD	_spr_res_lib1A_00
		.WORD	_spr_res_lib1A_01
		.WORD	_spr_res_lib1A_02
		.WORD	_spr_res_lib1A_03
		.WORD	_spr_res_lib1A_04
		.WORD	_spr_res_lib1A_05
		.WORD	_spr_res_lib1A_06
		.WORD	_spr_res_lib1A_07

		SECTION_START

_lvl6_objects_list:
		CHECKPOINT
		OBJ_SET	_scr0F_candle,$80,$00,$5C,$03,_NON,_NON,_NON
		OBJ_SET	_scr0F_candle,$80,$00,$5C,$02,_NON,_NON,_NON
		ROOM	$01
		OBJ_SET	_scr30_lvl6_boss_vega,$80,$00,$48,$00,_NON,_NON,_NON
		OBJ_END

_lvl6_collisions:
		.BYTE	$A1,$78,$A1,$7F,$E1,$7F,$41,$43,$01,$43,$01,$00,$FB,$FF,$EF,$F0
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$E0,$37,$00,$FF,$03,$FE,$03,$F0
_lvl6_macroA_tbl:
		.BYTE	$FF,$7E,$7F,$7E,$7F,$7E,$7F,$7F,$7E,$7F,$7F,$7C,$7C,$7F,$7C,$7C
		.BYTE	$7F,$7C,$13,$15,$17,$33,$35,$37,$7D,$7D,$C2,$53,$55,$57,$68,$69
		.BYTE	$7E,$0F,$5F,$7E,$4B,$4D,$CA,$EA,$CC,$EC,$30,$7E,$52,$FF,$20,$22
		.BYTE	$20,$12,$20,$02,$20,$FF,$20,$FF,$67,$20,$63,$FF,$FF,$FF,$75,$6B
		.BYTE	$77,$FF,$6E,$FF,$6B,$22,$FF,$12,$FF,$02,$FF,$FF,$FF,$22,$12,$12
		.BYTE	$02,$02,$FF,$FF,$FF,$FF,$49,$29,$39,$49,$39,$19,$19,$39,$29,$2A
		.BYTE	$2C,$2E,$39,$19,$09,$09,$39,$39,$4E,$29,$39,$09,$19,$19,$29,$09
		.BYTE	$29,$49,$29,$09,$29,$29,$09,$29,$39,$49,$29,$39,$39,$19,$0B,$39
		.BYTE	$7D,$7A,$D8,$7D,$7D,$7D,$E8,$7D,$7D,$CD,$CF,$7D,$D7,$ED,$7F,$ED
		.BYTE	$7E,$ED,$7E,$ED,$7F,$ED,$C0,$ED,$C0,$C1,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroB_tbl:
		.BYTE	$FF,$7E,$7F,$7E,$7F,$7F,$7F,$7E,$7F,$7E,$7C,$7F,$7F,$7C,$7C,$7C
		.BYTE	$7F,$7C,$23,$25,$27,$43,$45,$47,$03,$05,$07,$7D,$7D,$C2,$78,$79
		.BYTE	$7E,$3B,$3D,$7E,$5B,$5D,$DA,$FA,$DC,$FC,$30,$42,$7E,$21,$FF,$21
		.BYTE	$22,$21,$12,$21,$02,$21,$FF,$21,$61,$FF,$6E,$FF,$FF,$75,$FF,$77
		.BYTE	$67,$FF,$6E,$FF,$6E,$FF,$22,$FF,$12,$FF,$02,$FF,$FF,$12,$22,$02
		.BYTE	$12,$FF,$02,$FF,$FF,$FF,$49,$29,$39,$1C,$1E,$29,$19,$29,$29,$49
		.BYTE	$39,$3E,$39,$29,$09,$19,$29,$39,$29,$09,$49,$09,$09,$19,$09,$09
		.BYTE	$19,$39,$39,$19,$39,$39,$19,$39,$29,$49,$39,$49,$49,$29,$39,$39
		.BYTE	$7A,$7D,$7D,$D8,$7D,$7D,$F8,$7D,$D9,$DD,$DF,$7D,$7D,$ED,$ED,$7F
		.BYTE	$ED,$7E,$ED,$7E,$ED,$7F,$ED,$C0,$C1,$C0,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroC_tbl:
		.BYTE	$FF,$7E,$7E,$7F,$7E,$7F,$7F,$7F,$7E,$7F,$7F,$7C,$7C,$7C,$7F,$7C
		.BYTE	$7C,$7F,$14,$16,$18,$34,$36,$38,$7D,$7D,$7D,$54,$56,$58,$68,$7E
		.BYTE	$0E,$5E,$7E,$4A,$4C,$7E,$CB,$EB,$7D,$7D,$7E,$7E,$7E,$FF,$20,$FF
		.BYTE	$20,$22,$20,$12,$20,$02,$20,$66,$6F,$20,$64,$FF,$74,$6A,$76,$6C
		.BYTE	$6F,$6D,$6F,$6A,$6C,$FF,$FF,$22,$FF,$12,$FF,$02,$FF,$FF,$FF,$12
		.BYTE	$12,$02,$02,$10,$FF,$31,$39,$29,$39,$49,$29,$19,$39,$29,$39,$2B
		.BYTE	$2D,$2F,$29,$29,$19,$29,$49,$39,$4F,$29,$49,$19,$09,$19,$29,$19
		.BYTE	$39,$49,$09,$19,$39,$19,$09,$19,$49,$39,$39,$49,$29,$0A,$0C,$39
		.BYTE	$7D,$7B,$D9,$7D,$D7,$E7,$E9,$7D,$D7,$CE,$7D,$EE,$7D,$ED,$7F,$ED
		.BYTE	$7E,$ED,$ED,$ED,$7F,$ED,$C0,$ED,$C0,$C1,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroD_tbl:
		.BYTE	$FF,$7E,$7E,$7F,$7F,$7F,$7E,$7F,$7F,$7E,$7C,$7F,$7C,$7C,$7C,$7F
		.BYTE	$7C,$7F,$24,$26,$28,$44,$46,$48,$04,$06,$08,$7D,$7D,$7D,$78,$7E
		.BYTE	$3A,$3C,$7E,$5A,$5C,$7E,$DB,$FB,$7D,$7D,$7E,$7E,$7E,$21,$FF,$21
		.BYTE	$FF,$21,$22,$21,$12,$21,$02,$60,$62,$6D,$6F,$74,$FF,$76,$66,$6F
		.BYTE	$6F,$6D,$6F,$6D,$6F,$FF,$FF,$FF,$22,$FF,$12,$FF,$02,$FF,$FF,$12
		.BYTE	$12,$02,$02,$FF,$00,$31,$39,$29,$1B,$1D,$1F,$19,$29,$09,$39,$39
		.BYTE	$49,$3F,$29,$39,$19,$09,$39,$39,$19,$39,$49,$09,$19,$19,$19,$19
		.BYTE	$29,$49,$29,$29,$49,$29,$29,$29,$39,$39,$39,$49,$39,$39,$49,$39
		.BYTE	$7B,$7D,$D7,$D9,$7D,$F7,$F9,$D8,$7D,$DE,$7D,$7D,$7D,$ED,$ED,$7F
		.BYTE	$ED,$7E,$ED,$ED,$ED,$7F,$ED,$C0,$C1,$C0,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroE_tbl:
		.BYTE	$00,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$00,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$01,$01,$01,$01,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$03,$03,$03,$03,$03
		.BYTE	$03,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$03,$03,$00,$00,$00
		.BYTE	$00,$03,$03,$00,$00,$00,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl6_rooms_lib:
		.WORD	_l6_r01,      0,      0,      0,      0,      0,      0,      0
		.WORD	_l6_r02,      0,      0,      0,      0,      0,      0,      0
		.WORD	_l6_r03,      0,      0,      0,      0,      0,      0,      0
		.WORD	_l6_r04,      0,      0,      0,      0,      0,      0,      0
_l6_r01:
		.BYTE	$00,$00,$1E,$00,$54,$55,$55,$55,$55,$55,$55,$53,$00,$1E,$00,$00
		.BYTE	$00,$4B,$1E,$4C,$35,$56,$5D,$64,$6B,$72,$79,$36,$4B,$1E,$4C,$00
		.BYTE	$52,$49,$1E,$4A,$33,$57,$5E,$65,$6C,$73,$7A,$34,$49,$1E,$4A,$51
		.BYTE	$50,$47,$1E,$48,$31,$58,$5F,$66,$6D,$74,$7B,$32,$47,$1E,$48,$4F
		.BYTE	$4E,$45,$1E,$46,$2F,$59,$60,$67,$6E,$75,$7C,$30,$45,$1E,$46,$4D
		.BYTE	$00,$00,$1E,$3B,$2D,$5A,$61,$68,$6F,$76,$7D,$2E,$3C,$1E,$00,$00
		.BYTE	$41,$41,$1E,$3D,$37,$5B,$62,$69,$70,$77,$7E,$39,$3E,$1E,$43,$41
		.BYTE	$42,$42,$1E,$3F,$38,$5C,$63,$6A,$71,$78,$7F,$3A,$40,$1E,$44,$42
		.BYTE	$91,$01,$1F,$01,$2B,$2A,$2A,$2A,$2A,$2A,$2A,$2C,$01,$1F,$01,$90
		.BYTE	$91,$01,$01,$01,$01,$01,$01,$26,$27,$01,$01,$01,$01,$01,$01,$90
		.BYTE	$91,$01,$01,$01,$01,$01,$01,$28,$29,$01,$01,$01,$01,$01,$01,$90
		.BYTE	$8F,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$8E
		.BYTE	$8F,$0B,$02,$04,$0B,$02,$02,$02,$02,$02,$02,$0A,$06,$02,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$01,$18,$12,$15,$1B,$01,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0B,$01,$19,$13,$16,$1C,$01,$0A,$11,$11,$0E,$8E
_l6_r02:
		.BYTE	$97,$99,$9A,$97,$99,$9A,$1A,$14,$17,$1D,$9A,$98,$96,$9A,$98,$96
		.BYTE	$8F,$0B,$03,$05,$0B,$03,$03,$03,$03,$03,$03,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0F,$0E,$11,$11,$11,$11,$0F,$0E,$11,$11,$0E,$8E
		.BYTE	$8F,$0B,$01,$08,$0B,$0A,$09,$20,$23,$08,$0B,$0A,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$0A,$09,$21,$24,$08,$0B,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0B,$0A,$09,$22,$25,$08,$0B,$0A,$11,$11,$0E,$8E
		.BYTE	$8F,$0B,$01,$08,$0C,$0D,$10,$10,$10,$10,$0C,$0D,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$02,$02,$0A,$0B,$02,$02,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0B,$01,$01,$0A,$0B,$01,$01,$0A,$11,$11,$0E,$8E
		.BYTE	$8F,$0B,$01,$08,$0B,$01,$01,$0A,$0B,$01,$01,$0A,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$01,$08,$0B,$01,$01,$0A,$0B,$01,$01,$0A,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$03,$03,$0A,$0B,$03,$03,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$8E
		.BYTE	$91,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$90
		.BYTE	$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D
_l6_r03:
		.BYTE	$8D,$8D,$8D,$8D,$8D,$8D,$09,$01,$01,$08,$8D,$8D,$8D,$8D,$8D,$8D
		.BYTE	$91,$01,$89,$8B,$85,$01,$09,$01,$01,$08,$01,$01,$01,$87,$01,$90
		.BYTE	$91,$01,$8A,$01,$86,$84,$09,$01,$01,$08,$85,$01,$83,$88,$8C,$90
		.BYTE	$91,$01,$01,$01,$87,$82,$09,$01,$01,$08,$86,$84,$01,$89,$8B,$90
		.BYTE	$91,$01,$85,$83,$88,$8C,$09,$01,$01,$08,$01,$82,$01,$8A,$01,$90
		.BYTE	$91,$01,$86,$84,$89,$8B,$09,$01,$01,$08,$01,$89,$8B,$85,$01,$90
		.BYTE	$91,$85,$87,$01,$8A,$80,$09,$01,$01,$08,$81,$8A,$82,$86,$84,$90
		.BYTE	$91,$86,$88,$82,$85,$01,$09,$01,$01,$08,$01,$85,$87,$82,$01,$90
		.BYTE	$91,$01,$82,$01,$86,$84,$09,$01,$01,$08,$01,$86,$88,$8C,$01,$90
		.BYTE	$91,$01,$01,$01,$83,$84,$09,$01,$01,$08,$89,$8B,$01,$01,$01,$90
		.BYTE	$91,$01,$01,$85,$82,$01,$09,$01,$01,$08,$8A,$82,$01,$89,$8B,$90
		.BYTE	$91,$89,$8B,$86,$84,$80,$09,$01,$01,$08,$81,$01,$85,$8A,$01,$90
		.BYTE	$91,$8A,$82,$01,$01,$01,$09,$01,$01,$08,$83,$84,$86,$84,$01,$90
		.BYTE	$91,$01,$01,$89,$8B,$82,$09,$01,$01,$08,$01,$85,$87,$01,$01,$90
		.BYTE	$91,$82,$01,$8A,$85,$01,$09,$01,$01,$08,$01,$86,$88,$8C,$01,$90
_l6_r04:
		.BYTE	$91,$01,$01,$01,$86,$84,$09,$01,$01,$08,$01,$83,$84,$85,$01,$90
		.BYTE	$91,$01,$89,$8B,$82,$80,$09,$01,$01,$08,$81,$01,$87,$86,$84,$90
		.BYTE	$91,$01,$8A,$01,$85,$01,$09,$01,$01,$08,$85,$83,$88,$8C,$01,$90
		.BYTE	$91,$01,$83,$84,$86,$84,$09,$01,$01,$08,$86,$84,$01,$89,$8B,$90
		.BYTE	$91,$85,$01,$01,$87,$01,$09,$01,$01,$08,$01,$89,$8B,$8A,$01,$90
		.BYTE	$91,$86,$84,$83,$88,$8C,$09,$01,$01,$08,$01,$8A,$83,$84,$01,$90
		.BYTE	$91,$01,$01,$89,$8B,$80,$09,$01,$01,$08,$81,$01,$01,$85,$01,$90
		.BYTE	$91,$83,$84,$8A,$01,$01,$09,$01,$01,$08,$83,$84,$87,$86,$84,$90
		.BYTE	$91,$01,$01,$01,$82,$01,$09,$01,$01,$08,$01,$83,$88,$8C,$01,$90
		.BYTE	$91,$01,$01,$85,$83,$84,$09,$01,$01,$08,$01,$01,$89,$8B,$01,$90
		.BYTE	$91,$89,$8B,$86,$84,$01,$09,$01,$01,$08,$01,$85,$8A,$01,$01,$90
		.BYTE	$91,$8A,$83,$84,$82,$80,$09,$01,$01,$08,$81,$86,$84,$82,$01,$90
		.BYTE	$91,$01,$82,$01,$89,$8B,$09,$01,$01,$08,$01,$89,$8B,$83,$84,$90
		.BYTE	$91,$01,$01,$82,$8A,$01,$09,$01,$01,$08,$82,$8A,$01,$01,$01,$90
		.BYTE	$8D,$8D,$8D,$8D,$8D,$8D,$94,$8D,$8D,$95,$8D,$8D,$8D,$8D,$8D,$8D

		SECTION_END	"LVL6 DATA"

		BANK_END 3,$C000
