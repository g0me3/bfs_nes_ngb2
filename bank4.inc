
		ORG $8000

		BANK_START $04

; =============== S C R I P T ===============================================
_scr13_slow_moving_slime:
		NJSR			_nsub_380D2
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$04,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3800F:
		NBG_HNDL_SET	_nbgsub_380A2
_sloc_38012:
		SLOOP_BEGIN		$0A
		SJSR			_ssub_38029
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SLOOP_BEGIN		$0A
		SJSR			_ssub_38029
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SJMP			_sloc_38012

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_38029:
		NJSR			_nsub_628D1
			NARGB		$80,$00
		SSCRIPT1_SET	_scr_3805C
		SLOOP_BEGIN		$14
		SDELAY			$01
		NJSR			_nsub_62C49
		SBCC			_sloc_38048
		NJSR			_nsub_62CB0
		NJSR			_nsub_628D1
			NARGB		$80,$00
		SSCRIPT1_SET	_scr_3805C
_sloc_38048:
		NJSR			_nsub_62C7A
		SBCC			_sloc_3805A
		NJSR			_nsub_62CBA
		NJSR			_nsub_628D1
			NARGB		$80,$00
		SSCRIPT1_SET	_scr_3805C
_sloc_3805A:
		SLOOP_END
		SRET

; =============== S C R I P T ===============================================
_scr_3805C:
		NJSR			_nsub_6273D
			NARGB		$04,$40
_sloc_38061:
		SPR_IDX_ADD_IMM 7,$04
		SPR_IDX_ADD_IMM 7,$FC
		SJMP			_sloc_38061

; =============== S C R I P T ===============================================
_scr_38068:
		NBG_HNDL_SET	_nbgsub_380B8
		SJSR			_ssub_38079
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3800F
		SCASE			_scr_38096
		SCASE			_scr_3809C

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_38079:
		SARG_SET		SARG0,$02
_sloc_3807C:
		SJSR			_ssub_3808C
		NJSR			_nsub_62BFD
		SBCC			_sloc_3807C
		SLOOP_BEGIN		$14
		SJSR			_ssub_3808C
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3808C:
		NJSR			_nsub_6273D
			NARGB		$04,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ===============================================
_scr_38096:
		SARG_SET		SARG1,$10
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3809C:
		SARG_SET		SARG1,$12
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_380A2:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_380B1
		JSR		_cur_thread_reload_param
		.WORD	_scr_38068
		RTS
loc_380B1:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_380B8:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_380D1
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_380CC
		JSR		_cur_thread_reload_param
		.WORD	_scr_38096
		RTS
loc_380CC:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3809C
locret_380D1:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_380D2:
		LDA		#$08
		JSR		_rand
		ASL
		ASL
		ASL
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS
_spr_raw_lib0E_04:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$01,$A4,$02,$F8
		.BYTE	$01,$A4,$42,$00
		.BYTE	$F1,$94,$42,$00
		.BYTE	$F1,$94,$02,$F8
_spr_raw_lib0E_05:
		.BYTE	$06
		.BYTE	$06,$3E,$02,$00
		.BYTE	$06,$3E,$42,$F8
		.BYTE	$01,$A2,$42,$00
		.BYTE	$01,$B2,$42,$F8
		.BYTE	$F1,$B0,$42,$F8
		.BYTE	$F1,$92,$42,$00
_spr_raw_lib0E_06:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$01,$82,$02,$F8
		.BYTE	$01,$82,$42,$00
		.BYTE	$F1,$90,$42,$00
		.BYTE	$F1,$90,$02,$F8
_spr_raw_lib0E_07:
		.BYTE	$06
		.BYTE	$06,$3E,$42,$F8
		.BYTE	$06,$3E,$02,$00
		.BYTE	$01,$B2,$02,$00
		.BYTE	$01,$A2,$02,$F8
		.BYTE	$F1,$B0,$02,$00
		.BYTE	$F1,$92,$02,$F8
_spr_raw_lib0E_08:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$00,$A4,$42,$00
		.BYTE	$00,$A4,$02,$F8
		.BYTE	$F0,$84,$02,$F8
		.BYTE	$F0,$84,$42,$00
_spr_raw_lib0E_09:
		.BYTE	$06
		.BYTE	$06,$3E,$02,$00
		.BYTE	$06,$3E,$42,$F8
		.BYTE	$00,$A2,$42,$00
		.BYTE	$00,$B2,$42,$F8
		.BYTE	$F0,$B0,$42,$F8
		.BYTE	$F0,$A0,$42,$00
_spr_raw_lib0E_0A:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$00,$82,$42,$00
		.BYTE	$00,$82,$02,$F8
		.BYTE	$F0,$80,$02,$F8
		.BYTE	$F0,$80,$42,$00
_spr_raw_lib0E_0B:
		.BYTE	$06
		.BYTE	$06,$3E,$42,$F8
		.BYTE	$06,$3E,$02,$00
		.BYTE	$00,$B2,$02,$00
		.BYTE	$00,$A2,$02,$F8
		.BYTE	$F0,$B0,$02,$00
		.BYTE	$F0,$A0,$02,$F8
_spr_raw_lib0E_0C:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$02
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$00,$A4,$42,$02
		.BYTE	$00,$A4,$02,$FA
		.BYTE	$F0,$84,$02,$FA
		.BYTE	$F0,$84,$42,$02
_spr_raw_lib0E_0D:
		.BYTE	$06
		.BYTE	$06,$3E,$02,$02
		.BYTE	$06,$3E,$42,$FA
		.BYTE	$00,$A2,$42,$02
		.BYTE	$00,$B2,$42,$FA
		.BYTE	$F0,$B0,$42,$FA
		.BYTE	$F0,$A0,$42,$02
_spr_raw_lib0E_0E:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$02
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$00,$82,$42,$02
		.BYTE	$00,$82,$02,$FA
		.BYTE	$F0,$80,$02,$FA
		.BYTE	$F0,$80,$42,$02
_spr_raw_lib0E_0F:
		.BYTE	$06
		.BYTE	$06,$3E,$42,$FA
		.BYTE	$06,$3E,$02,$02
		.BYTE	$00,$B2,$02,$02
		.BYTE	$00,$A2,$02,$FA
		.BYTE	$F0,$B0,$02,$02
		.BYTE	$F0,$A0,$02,$FA
_spr_raw_lib0E_10:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F8
		.BYTE	$F0,$96,$02,$F8
		.BYTE	$F0,$86,$02,$F0
_spr_raw_lib0E_11:
		.BYTE	$02
		.BYTE	$F8,$B6,$02,$F8
		.BYTE	$F8,$A6,$02,$F0
_spr_raw_lib0E_12:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$00
		.BYTE	$F0,$96,$42,$00
		.BYTE	$F0,$86,$42,$08
_spr_raw_lib0E_13:
		.BYTE	$02
		.BYTE	$F8,$A6,$42,$08
		.BYTE	$F8,$B6,$42,$00

; =============== S C R I P T ===============================================
_scr14_fast_moving_slime:
		NJSR			_nsub_62ABE
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$04,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_38246:
		NBG_HNDL_SET	_nbgsub_38293
_sloc_38249:
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_3805C
		SLOOP_BEGIN		$0A
		SDELAY			$01
		NJSR			_nsub_62C49
		SBCC			_sloc_38268
		NJSR			_nsub_62CB0
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_3805C
_sloc_38268:
		NJSR			_nsub_62C7A
		SBCC			_sloc_3827A
		NJSR			_nsub_62CBA
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_3805C
_sloc_3827A:
		SLOOP_END
		NJSR			_nsub_62AEC
			NARGB		$08
		SJMP			_sloc_38249

; =============== S C R I P T ===============================================
_scr_38282:
		NBG_HNDL_SET	_nbgsub_382A9
		SJSR			_ssub_38079
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_38246
		SCASE			_scr_38096
		SCASE			_scr_3809C

; =============== S U B R O U T I N E =======================================
_nbgsub_38293:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_382A2
		JSR		_cur_thread_reload_param
		.WORD	_scr_38282
		RTS
loc_382A2:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_382A9:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_382C2
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_382BD
		JSR		_cur_thread_reload_param
		.WORD	_scr_38096
		RTS
loc_382BD:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3809C
locret_382C2:
		RTS

; =============== S C R I P T ===============================================
_scr15_trolley_kick_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_3832C
		SARG_SET		SARG1,$40
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$05
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_382D6:
		NBG_HNDL_SET	_nbgsub_382FC
_sloc_382D9:
		NJSR			_nsub_new_thread_start
			NARGB		$15
			NARGB		$00,$08
			NARGB		$01
			NARGB		$00
		SLOOP_BEGIN		$0A
		SPR_IDX_SET		7,$05
		SPR_IDX_SET		7,$09
		SLOOP_END
		SJMP			_sloc_382D9

; =============== S C R I P T ===============================================
_scr_382EB:
		NBG_HNDL_SET	_nbgsub_38312
		SJSR			_ssub_38079
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_382D6
		SCASE			_scr_38096
		SCASE			_scr_3809C

; =============== S U B R O U T I N E =======================================
_nbgsub_382FC:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3830B
		JSR		_cur_thread_reload_param
		.WORD	_scr_382EB
		RTS
loc_3830B:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_38312:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3832B
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_38326
		JSR		_cur_thread_reload_param
		.WORD	_scr_38096
		RTS
loc_38326:
		; *--
		JSR		_cur_thread_reload_param
		.WORD	_scr_3809C	; *--
locret_3832B:
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_3832C:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_38338
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$14
		SUSPEND

; =============== S U B R O U T I N E =======================================
_nbgsub_38338:
		LDX		#$0D
		LDY		#$0E
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test
_spr_raw_lib0E_14:
		.BYTE	$04
		.BYTE	$00,$F9,$00,$02
		.BYTE	$00,$F9,$00,$F7
		.BYTE	$F0,$E9,$43,$00
		.BYTE	$F0,$E9,$03,$F8

; =============== S C R I P T ===============================================
_scr16_still_throw_forward_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_383C2

; =============== S C R I P T ===============================================
_sjmp_case_3835C:
		NBG_HNDL_SET	_nbgsub_38392
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$08
_sloc_38363:
		SLOOP_BEGIN		$03
		NJSR			_nsub_62ABE
		NJSR			_nsub_6273D
			NARGB		$04,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$04
		SLOOP_END
		NJSR			_nsub_new_thread_start
			NARGB		$16
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		SJMP			_sloc_38363

; =============== S C R I P T ===============================================
_scr_38381:
		NBG_HNDL_SET	_nbgsub_383A8
		SJSR			_ssub_38079
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3835C
		SCASE			_scr_38096
		SCASE			_scr_3809C

; =============== S U B R O U T I N E =======================================
_nbgsub_38392:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_383A1
		JSR		_cur_thread_reload_param
		.WORD	_scr_38381
		RTS
loc_383A1:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_383A8:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_383C1
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_383BC
		JSR		_cur_thread_reload_param
		.WORD	_scr_38096
		RTS
loc_383BC:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3809C
locret_383C1:
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_383C2:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_383DA
		NJSR			_nsub_628D1
			NARGB		$80,$01
		NJSR			_nsub_383E7
_sloc_383D0:
		SDELAY			$07
		SPR_IDX_INC		7
		SPR_IDX_INC		7
		SPR_IDX_INC		7
		SPR_IDX_ADD_IMM 0,$FD
		SJMP			_sloc_383D0

; =============== S U B R O U T I N E =======================================
_nbgsub_383DA:
		LDX		#$07
		LDY		#$08
		JSR		_player_to_obj_collision_test
		JSR		_cur_obj_out_of_screen_test
		JMP		_obj_to_room_macro_collision_test_raw

; =============== S U B R O U T I N E =======================================
_nsub_383E7:
		LDA		#$00
		JSR		_rand
		AND		#$0C
		CLC
		ADC		#$15
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_spr_idx,X
		RTS
_spr_raw_lib0E_1C:
		.BYTE	$02
		.BYTE	$F8,$E1,$00,$F8
		.BYTE	$F8,$F1,$00,$00
_spr_raw_lib0E_18:
		.BYTE	$02
		.BYTE	$F8,$CF,$03,$F8
		.BYTE	$F8,$DF,$03,$00
_spr_raw_lib0E_20:
		.BYTE	$02
		.BYTE	$F8,$F7,$03,$00
		.BYTE	$F8,$E7,$03,$F8
_spr_raw_lib0E_21:
		.BYTE	$02
		.BYTE	$F8,$CB,$03,$F8
		.BYTE	$F8,$DB,$03,$00
_spr_raw_lib0E_22:
		.BYTE	$02
		.BYTE	$F8,$DB,$43,$F8
		.BYTE	$F8,$CB,$43,$00
_spr_raw_lib0E_23:
		.BYTE	$02
		.BYTE	$F8,$CB,$C3,$00
		.BYTE	$F8,$DB,$C3,$F8
_spr_raw_lib0E_24:
		.BYTE	$02
		.BYTE	$F8,$DB,$83,$00
		.BYTE	$F8,$CB,$83,$F8

; =============== S C R I P T ===============================================
_scr1B_court_chair:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$25
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SARG_SET		SARG2,$00
		NBG_HNDL_SET	_nbgsub_38477
_sloc_38442:
		SPR_IDX_SET		0,$25
		SDELAY			$0A
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$12
		POS_Y_MOVE		0,$FF
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FE
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FE
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FD
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FC
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FA
		SPR_IDX_INC		3
		POS_Y_MOVE		0,$FA
		SPR_IDX_INC		3
		NJSR			_nsub_38481
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
		SJMP			_sloc_38442

; =============== S U B R O U T I N E =======================================
_nbgsub_38477:
		LDX		#$0B
		LDY		#$0C
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E =======================================
_nsub_38481:
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_args1,X
		LDA		off_384BF,Y
		STA		_ptr06
		LDA		off_384C4,Y
		STA		_ptr06+1
		LDY		_scr_trds_args2,X
loc_38491:
		TYA
		PHA
		LDA		(_ptr06),Y
		BPL		loc_3849C
		PLA
		LDY		#$00
		BEQ		loc_38491
loc_3849C:
		TAY
		LDA		byte_384BA+1,Y
		STA		_scr_trds_x_move_delta,X
		LDA		byte_384BA,Y
		STA		_scr_trds_y_mov_delta,X
		PLA
		TAY
		INY
		LDX		_scr_cur_trd_idxw
		LDA		(_ptr06),Y
		STA		_scr_trds_delay,X
		INY
		LDX		_scr_cur_trd_idx
		TYA
		STA		_scr_trds_args2,X
		RTS
byte_384BA:
		.BYTE	$FF,$00,$01,$00,$FF
off_384BF:
		.BYTE	<[byte_384C9]
		.BYTE	<[byte_384DA]
		.BYTE	<[byte_384E9]
		.BYTE	<[byte_384FC]
		.BYTE	<[byte_38511]	; *--
off_384C4:
		.BYTE	>[byte_384C9]
		.BYTE	>[byte_384DA]
		.BYTE	>[byte_384E9]
		.BYTE	>[byte_384FC]
		.BYTE	>[byte_38511]	; *--
byte_384C9:
		.BYTE	$03,$20,$03,$30,$01,$30,$01,$20,$03,$20,$01,$20,$01,$30,$03,$30
		.BYTE	$FF
byte_384DA:
		.BYTE	$02,$10,$02,$20,$03,$20,$00,$20,$01,$40,$03,$20,$00,$10,$FF
byte_384E9:
		.BYTE	$03,$20,$00,$00,$00,$10,$01,$20,$03,$20,$00,$10,$00,$00,$02,$20
		.BYTE	$01,$20,$FF
byte_384FC:
		.BYTE	$00,$10,$00,$20,$01,$10,$00,$00,$02,$20,$00,$00,$00,$00,$03,$10
		.BYTE	$02,$10,$00,$00,$FF
byte_38511:
		.BYTE	$03,$10,$00,$00,$01,$10,$00,$10,$00,$00,$03,$10,$01,$30,$02,$10 ;	*--
		.BYTE	$00,$00,$03,$20,$00,$00,$00,$00,$FF
_spr_raw_lib0E_25:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$F9,$4B,$40,$01
		.BYTE	$F9,$4B,$00,$F9
_spr_raw_lib0E_26:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$FA,$4B,$40,$01
		.BYTE	$FA,$4B,$00,$F9
_spr_raw_lib0E_27:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$FC,$4B,$40,$01
		.BYTE	$FC,$4B,$00,$F9
_spr_raw_lib0E_28:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$FE,$4B,$40,$01
		.BYTE	$FE,$4B,$00,$F9
_spr_raw_lib0E_29:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$01,$4B,$40,$01
		.BYTE	$01,$4B,$00,$F9
_spr_raw_lib0E_2A:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$05,$4B,$40,$01
		.BYTE	$05,$4B,$00,$F9
_spr_raw_lib0E_2B:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$0B,$4B,$40,$01
		.BYTE	$0B,$4B,$00,$F9
_spr_raw_lib0E_2C:
		.BYTE	$04
		.BYTE	$F8,$5B,$43,$00
		.BYTE	$F8,$5B,$03,$F8
		.BYTE	$11,$4B,$40,$01
		.BYTE	$11,$4B,$00,$F9

; =============== S C R I P T ===============================================
_scr1D_air_hammer_miner:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$2F
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_385B9:
		NBG_HNDL_SET	_nbgsub_38602
_sloc_385BC:
		NJSR			_nsub_62ABE
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$08
		SPR_IDX_SET		2,$2D
		SPR_IDX_INC		2
		SLOOP_END
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SLOOP_BEGIN		$1E
		SPR_IDX_SET		2,$2D
		SPR_IDX_INC		2
		SLOOP_END
		SJMP			_sloc_385BC

; =============== S C R I P T ===============================================
_scr_385D4:
		NBG_HNDL_SET	_nbgsub_38636
		SARG_SET		SARG0,$02
_sloc_385DA:
		SPR_IDX_SET		1,$2D
		SPR_IDX_SET		1,$2F
		NJSR			_nsub_62BFD
		SBCC			_sloc_385DA
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$2D
		SPR_IDX_SET		1,$2F
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_385B9
		SCASE			_scr_385F6
		SCASE			_scr_385FC

; =============== S C R I P T ===============================================
_scr_385F6:
		SARG_SET		SARG1,$30
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_385FC:
		SARG_SET		SARG1,$32
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_38602:
		JSR		_nsub_62C49
		BCC		loc_38611
		LDX		_scr_cur_trd_idx
		LDA		#$00
		STA		_scr_trds_x_move_speed,X
		STA		_scr_trds_x_move_delta,X
loc_38611:
		JSR		_nsub_62C7A
		BCC		loc_38620
		LDX		_scr_cur_trd_idx
		LDA		#$00
		STA		_scr_trds_y_move_speed,X
		STA		_scr_trds_y_mov_delta,X
loc_38620:
		LDX		#$0A
		LDY		#$0E
		JSR		sub_61DD6
		BCC		loc_3862F
		JSR		_cur_thread_reload_param
		.WORD	_scr_385D4
		RTS
loc_3862F:
		LDX		#$0B
		LDY		#$10
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_38636:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3864F
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3864A
		JSR		_cur_thread_reload_param
		.WORD	_scr_385F6
		RTS
loc_3864A:
		JSR		_cur_thread_reload_param
		.WORD	_scr_385FC
locret_3864F:
		RTS
_spr_raw_lib0E_2D:
		.BYTE	$08
		.BYTE	$F6,$BC,$00,$F8
		.BYTE	$F6,$BC,$40,$00
		.BYTE	$02,$3E,$43,$F8
		.BYTE	$02,$3E,$03,$00
		.BYTE	$FA,$A4,$03,$F8
		.BYTE	$FA,$A4,$43,$00
		.BYTE	$EA,$BA,$43,$00
		.BYTE	$EA,$BA,$03,$F8
_spr_raw_lib0E_2E:
		.BYTE	$08
		.BYTE	$F9,$BC,$00,$F8
		.BYTE	$F9,$BC,$40,$00
		.BYTE	$03,$3E,$43,$F8
		.BYTE	$03,$3E,$03,$00
		.BYTE	$FB,$A4,$03,$F8
		.BYTE	$FB,$A4,$43,$00
		.BYTE	$EB,$BA,$43,$00
		.BYTE	$EB,$BA,$03,$F8
_spr_raw_lib0E_2F:
		.BYTE	$08
		.BYTE	$F6,$BC,$00,$FA
		.BYTE	$F6,$BC,$40,$02
		.BYTE	$02,$3E,$43,$FA
		.BYTE	$02,$3E,$03,$02
		.BYTE	$FA,$A4,$03,$FA
		.BYTE	$FA,$A4,$43,$02
		.BYTE	$EA,$BA,$43,$02
		.BYTE	$EA,$BA,$03,$FA
_spr_raw_lib0E_30:
		.BYTE	$03
		.BYTE	$00,$C6,$03,$F8
		.BYTE	$F0,$98,$03,$FB
		.BYTE	$F0,$88,$03,$F3
_spr_raw_lib0E_31:
		.BYTE	$02
		.BYTE	$F8,$BE,$03,$F8
		.BYTE	$F8,$AE,$03,$F0
_spr_raw_lib0E_32:
		.BYTE	$03
		.BYTE	$00,$C6,$43,$00
		.BYTE	$F0,$98,$43,$FD
		.BYTE	$F0,$88,$43,$05
_spr_raw_lib0E_33:
		.BYTE	$02
		.BYTE	$F8,$AE,$43,$08
		.BYTE	$F8,$BE,$43,$00

; =============== S C R I P T ===============================================
_scr1E_pick_axe_miner:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$36
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SARG_SET		SARG1,$80

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_386E9:
		NBG_HNDL_SET	_nbgsub_38766
_sloc_386EC:
		NJSR			_nsub_6273D
			NARGB		$34,$40
		POS_MOVE_STOP	0
		SDELAY			$14
		NJSR			_nsub_62CC4
		NJSR			_nsub_62CD3
		SBCC			_sloc_3871B
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_62CD3
		SBCC			_sloc_3871B
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_62CD3
		SBCC			_sloc_3871B
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_62CD3
		SBCS			_sloc_386EC
_sloc_3871B:
		NJSR			_nsub_6273D
			NARGB		$34,$40
		SLOOP_BEGIN		$03
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 6,$FC
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$08
		NJSR			_nsub_628D1
			NARGB		$00,$01
		SLOOP_BEGIN		$0A
		NJSR			_nsub_62CD3
		SBCS_BREAK	_sloc_38739
		SDELAY			$08
		SLOOP_END
_sloc_38739:
		SJMP			_sloc_386EC

; =============== S C R I P T ===============================================
_scr_3873C:
		NBG_HNDL_SET	_nbgsub_3877C
		SARG_SET		SARG0,$02
_sloc_38742:
		SJSR			_ssub_3875C
		NJSR			_nsub_62BFD
		SBCC			_sloc_38742
		SLOOP_BEGIN		$14
		SJSR			_ssub_3875C
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_386E9
		SCASE			_scr_385F6
		SCASE			_scr_385FC

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3875C:
		NJSR			_nsub_6273D
			NARGB		$34,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$0C
		SRET

; =============== S U B R O U T I N E =======================================
_nbgsub_38766:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_38775
		JSR		_cur_thread_reload_param
		.WORD	_scr_3873C
		RTS
loc_38775:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3877C:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_38795
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_38790
		JSR		_cur_thread_reload_param
		.WORD	_scr_385F6
		RTS
loc_38790:
		JSR		_cur_thread_reload_param
		.WORD	_scr_385FC
locret_38795:
		RTS
_spr_raw_lib0E_34:
		.BYTE	$07
		.BYTE	$F0,$E1,$42,$F0
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$AA,$43,$00
		.BYTE	$02,$AA,$03,$F8
		.BYTE	$F2,$B8,$03,$00
		.BYTE	$F2,$A8,$03,$F8
_spr_raw_lib0E_35:
		.BYTE	$07
		.BYTE	$F1,$E1,$42,$F0
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$86,$43,$00
		.BYTE	$02,$96,$43,$F8
		.BYTE	$F2,$94,$43,$F8
		.BYTE	$F2,$84,$43,$00
_spr_raw_lib0E_36:
		.BYTE	$07
		.BYTE	$F1,$E1,$02,$08
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$F2,$B0,$03,$00
		.BYTE	$F2,$A0,$03,$F8
_spr_raw_lib0E_37:
		.BYTE	$07
		.BYTE	$F1,$E1,$02,$08
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$02,$96,$03,$00
		.BYTE	$02,$86,$03,$F8
		.BYTE	$F2,$94,$03,$00
		.BYTE	$F2,$84,$03,$F8
_spr_raw_lib0E_38:
		.BYTE	$07
		.BYTE	$EC,$E1,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$AA,$43,$00
		.BYTE	$02,$AA,$03,$F8
		.BYTE	$F2,$B6,$03,$00
		.BYTE	$F2,$A6,$03,$F8
_spr_raw_lib0E_39:
		.BYTE	$07
		.BYTE	$EA,$E1,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$96,$43,$F8
		.BYTE	$02,$86,$43,$00
		.BYTE	$F2,$98,$43,$F8
		.BYTE	$F2,$88,$43,$00
_spr_raw_lib0E_3A:
		.BYTE	$07
		.BYTE	$E9,$E1,$02,$03
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$F2,$B2,$03,$00
		.BYTE	$F2,$A2,$03,$F8
_spr_raw_lib0E_3B:
		.BYTE	$07
		.BYTE	$EA,$E1,$02,$07
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$02,$96,$03,$00
		.BYTE	$02,$86,$03,$F8
		.BYTE	$F2,$98,$03,$00
		.BYTE	$F2,$88,$03,$F8
_spr_raw_lib0E_3C:
		.BYTE	$07
		.BYTE	$EC,$E1,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$F2,$B6,$03,$00
		.BYTE	$F2,$A6,$03,$F8
_spr_raw_lib0E_3D:
		.BYTE	$07
		.BYTE	$EA,$E1,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$8A,$43,$00
		.BYTE	$02,$9A,$43,$F8
		.BYTE	$F2,$98,$43,$F8
		.BYTE	$F2,$88,$43,$00
_spr_raw_lib0E_3E:
		.BYTE	$07
		.BYTE	$E9,$E1,$02,$03
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$B4,$43,$00
		.BYTE	$02,$B4,$03,$F8
		.BYTE	$F2,$B2,$03,$00
		.BYTE	$F2,$A2,$03,$F8
_spr_raw_lib0E_3F:
		.BYTE	$07
		.BYTE	$EA,$E1,$02,$07
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$02,$9A,$03,$00
		.BYTE	$02,$8A,$03,$F8
		.BYTE	$F2,$98,$03,$00
		.BYTE	$F2,$88,$03,$F8
_spr_raw_lib0E_40:
		.BYTE	$07
		.BYTE	$EC,$E1,$42,$F3
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$02,$A4,$43,$02
		.BYTE	$02,$A4,$03,$FA
		.BYTE	$F2,$B6,$03,$02
		.BYTE	$F2,$A6,$03,$FA
_spr_raw_lib0E_41:
		.BYTE	$07
		.BYTE	$EA,$E1,$42,$F3
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$02,$8A,$43,$02
		.BYTE	$02,$9A,$43,$FA
		.BYTE	$F2,$98,$43,$FA
		.BYTE	$F2,$88,$43,$02
_spr_raw_lib0E_42:
		.BYTE	$07
		.BYTE	$E9,$E1,$02,$05
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$02,$B4,$43,$02
		.BYTE	$02,$B4,$03,$FA
		.BYTE	$F2,$B2,$03,$02
		.BYTE	$F2,$A2,$03,$FA
_spr_raw_lib0E_43:
		.BYTE	$07
		.BYTE	$EA,$E1,$02,$09
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$02,$9A,$03,$02
		.BYTE	$02,$8A,$03,$FA
		.BYTE	$F2,$98,$03,$02
		.BYTE	$F2,$88,$03,$FA

; =============== S C R I P T ===============================================
_scr1F_hammer_miner:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$46
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SARG_SET		SARG1,$80

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_38970:
		NBG_HNDL_SET	_nbgsub_389ED
_sloc_38973:
		NJSR			_nsub_6273D
			NARGB		$44,$40
		POS_MOVE_STOP	0
		SDELAY			$14
		NJSR			_nsub_62CC4
		NJSR			_nsub_62CD3
		SBCC			_sloc_389A2
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_62CD3
		SBCC			_sloc_389A2
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_62CD3
		SBCC			_sloc_389A2
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_62CD3
		SBCS			_sloc_38973
_sloc_389A2:
		NJSR			_nsub_6273D
			NARGB		$44,$40
		SLOOP_BEGIN		$03
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 6,$FC
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$08
		NJSR			_nsub_628D1
			NARGB		$00,$01
		SLOOP_BEGIN		$0A
		NJSR			_nsub_62CD3
		SBCS_BREAK	_sloc_389C0
		SDELAY			$08
		SLOOP_END
_sloc_389C0:
		SJMP			_sloc_38973

; =============== S C R I P T ===============================================
_scr_389C3:
		NBG_HNDL_SET	_nbgsub_38A03
		SARG_SET		SARG0,$02
_sloc_389C9:
		SJSR			_ssub_389E3
		NJSR			_nsub_62BFD
		SBCC			_sloc_389C9
		SLOOP_BEGIN		$14
		SJSR			_ssub_389E3
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_38970
		SCASE			_scr_385F6
		SCASE			_scr_385FC

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_389E3:
		NJSR			_nsub_6273D
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$0C
		SRET

; =============== S U B R O U T I N E =======================================
_nbgsub_389ED:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_389FC
		JSR		_cur_thread_reload_param
		.WORD	_scr_389C3
		RTS
loc_389FC:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_38A03:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_38A1C
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_38A17
		JSR		_cur_thread_reload_param
		.WORD	_scr_385F6
		RTS
loc_38A17:
		JSR		_cur_thread_reload_param
		.WORD	_scr_385FC
locret_38A1C:
		RTS
_spr_raw_lib0E_44:
		.BYTE	$08
		.BYTE	$F0,$D3,$42,$E8
		.BYTE	$F0,$C3,$42,$F0
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$AA,$43,$00
		.BYTE	$02,$AA,$03,$F8
		.BYTE	$F2,$B8,$03,$00
		.BYTE	$F2,$A8,$03,$F8
_spr_raw_lib0E_45:
		.BYTE	$08
		.BYTE	$F1,$D3,$42,$E8
		.BYTE	$F1,$C3,$42,$F0
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$86,$43,$00
		.BYTE	$02,$96,$43,$F8
		.BYTE	$F2,$94,$43,$F8
		.BYTE	$F2,$84,$43,$00
_spr_raw_lib0E_46:
		.BYTE	$08
		.BYTE	$F1,$D3,$02,$10
		.BYTE	$F1,$C3,$02,$08
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$F2,$B0,$03,$00
		.BYTE	$F2,$A0,$03,$F8
_spr_raw_lib0E_47:
		.BYTE	$08
		.BYTE	$F1,$D3,$02,$10
		.BYTE	$F1,$C3,$02,$08
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$02,$96,$03,$00
		.BYTE	$02,$86,$03,$F8
		.BYTE	$F2,$94,$03,$00
		.BYTE	$F2,$84,$03,$F8
_spr_raw_lib0E_48:
		.BYTE	$08
		.BYTE	$EC,$D3,$42,$E9
		.BYTE	$EC,$C3,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$AA,$43,$00
		.BYTE	$02,$AA,$03,$F8
		.BYTE	$F2,$B6,$03,$00
		.BYTE	$F2,$A6,$03,$F8
_spr_raw_lib0E_49:
		.BYTE	$08
		.BYTE	$EA,$D3,$42,$E9
		.BYTE	$EA,$C3,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$96,$43,$F8
		.BYTE	$02,$86,$43,$00
		.BYTE	$F2,$98,$43,$F8
		.BYTE	$F2,$88,$43,$00
_spr_raw_lib0E_4A:
		.BYTE	$08
		.BYTE	$E9,$D3,$02,$0B
		.BYTE	$E9,$C3,$02,$03
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$F2,$B2,$03,$00
		.BYTE	$F2,$A2,$03,$F8
_spr_raw_lib0E_4B:
		.BYTE	$08
		.BYTE	$EA,$D3,$02,$0F
		.BYTE	$EA,$C3,$02,$07
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$02,$96,$03,$00
		.BYTE	$02,$86,$03,$F8
		.BYTE	$F2,$98,$03,$00
		.BYTE	$F2,$88,$03,$F8
_spr_raw_lib0E_4C:
		.BYTE	$08
		.BYTE	$EC,$D3,$42,$E9
		.BYTE	$EC,$C3,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$A4,$43,$00
		.BYTE	$02,$A4,$03,$F8
		.BYTE	$F2,$B6,$03,$00
		.BYTE	$F2,$A6,$03,$F8
_spr_raw_lib0E_4D:
		.BYTE	$08
		.BYTE	$EA,$D3,$42,$E9
		.BYTE	$EA,$C3,$42,$F1
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$9A,$43,$F8
		.BYTE	$02,$8A,$43,$00
		.BYTE	$F2,$98,$43,$F8
		.BYTE	$F2,$88,$43,$00
_spr_raw_lib0E_4E:
		.BYTE	$08
		.BYTE	$E9,$D3,$02,$0B
		.BYTE	$E9,$C3,$02,$03
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$02,$B4,$43,$00
		.BYTE	$02,$B4,$03,$F8
		.BYTE	$F2,$B2,$03,$00
		.BYTE	$F2,$A2,$03,$F8
_spr_raw_lib0E_4F:
		.BYTE	$08
		.BYTE	$EA,$D3,$02,$0F
		.BYTE	$EA,$C3,$02,$07
		.BYTE	$0A,$3E,$43,$F8
		.BYTE	$0A,$3E,$03,$00
		.BYTE	$02,$9A,$03,$00
		.BYTE	$02,$8A,$03,$F8
		.BYTE	$F2,$98,$03,$00
		.BYTE	$F2,$88,$03,$F8
_spr_raw_lib0E_50:
		.BYTE	$08
		.BYTE	$EC,$D3,$42,$EB
		.BYTE	$EC,$C3,$42,$F3
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$02,$A4,$43,$02
		.BYTE	$02,$A4,$03,$FA
		.BYTE	$F2,$B6,$03,$02
		.BYTE	$F2,$A6,$03,$FA
_spr_raw_lib0E_51:
		.BYTE	$08
		.BYTE	$EA,$D3,$42,$EB
		.BYTE	$EA,$C3,$42,$F3
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$02,$9A,$43,$FA
		.BYTE	$02,$8A,$43,$02
		.BYTE	$F2,$98,$43,$FA
		.BYTE	$F2,$88,$43,$02
_spr_raw_lib0E_52:
		.BYTE	$08
		.BYTE	$E9,$D3,$02,$0D
		.BYTE	$E9,$C3,$02,$05
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$02,$B4,$43,$02
		.BYTE	$02,$B4,$03,$FA
		.BYTE	$F2,$B2,$03,$02
		.BYTE	$F2,$A2,$03,$FA
_spr_raw_lib0E_53:
		.BYTE	$08
		.BYTE	$EA,$D3,$02,$11
		.BYTE	$EA,$C3,$02,$09
		.BYTE	$0A,$3E,$43,$FA
		.BYTE	$0A,$3E,$03,$02
		.BYTE	$02,$9A,$03,$02
		.BYTE	$02,$8A,$03,$FA
		.BYTE	$F2,$98,$03,$02
		.BYTE	$F2,$88,$03,$FA

; =============== S C R I P T ===============================================
_scr0E_empty_mine_trolley:
		NBG_HNDL_SET	_nbgsub_38C54
_sloc_38C30:
		NJSR			_nsub_38C5B
		SBCS			_sloc_38C46
		NJSR			_nsub_6273D
			NARGB		$54,$40
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$08
		POS_MOVE_STOP	0
		SJMP			_sloc_38C30
_sloc_38C46:
		NBG_HNDL_RESET
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$54,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_38C54:
		LDX		#$0D
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nsub_38C5B:
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_y_pos_lo,X
		LDA		_scr_trds_y_pos_hi,X
		STA		_tmp_var1
		LDA		_scr_trds_x_pos_hi,X
		STA		_tmp_var0
		LDA		_scr_trds_x_pos_lo,X
		TAX
		JSR		_far_lvl_room_ofs_calc
		LDY		#$0B
loc_38C71:
		CMP		byte_38CAD,Y
		BEQ		loc_38C7B
		DEY
		BPL		loc_38C71
loc_38C79:
		SEC
		RTS
loc_38C7B:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		ASL
		ROL
		ROL
		TAX
		LDA		off_38CB9,X
		STA		_ptr06
		LDA		off_38CBD,X
		STA		_ptr06+1
		LDA		(_ptr06),Y
		STA		_var0
		BIT		_var0
		BVS		loc_38C79
		BPL		loc_38CA5
		PHA
		LDA		#$00
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
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS
byte_38CAD:
		.BYTE	$01,$10,$02,$12,$03,$13,$04,$C4,$05,$15,$06,$16
off_38CB9:
		.BYTE	<[byte_38CC1]
		.BYTE	<[byte_38CCD]
		.BYTE	<[byte_38CD9]
		.BYTE	<[byte_38CE5]
off_38CBD:
		.BYTE	>[byte_38CC1]
		.BYTE	>[byte_38CCD]
		.BYTE	>[byte_38CD9]
		.BYTE	>[byte_38CE5]
byte_38CC1:
		.BYTE	$00,$00,$81,$83,$00,$00,$01,$03,$40,$40,$40,$40
byte_38CCD:
		.BYTE	$40,$40,$40,$02,$40,$00,$40,$02,$40,$00,$01,$01 ;	*--
byte_38CD9:
		.BYTE	$02,$02,$02,$02,$89,$8B,$40,$40,$01,$03,$40,$40
byte_38CE5:
		.BYTE	$40,$40,$02,$40,$00,$40,$02,$40,$00,$40,$03,$03 ;	*--
_spr_raw_lib0E_56:
		.BYTE	$04
		.BYTE	$00,$82,$02,$F8
		.BYTE	$00,$82,$42,$00
		.BYTE	$F0,$80,$42,$00
		.BYTE	$F0,$80,$02,$F8
_spr_raw_lib0E_57:
		.BYTE	$04
		.BYTE	$F8,$90,$42,$08
		.BYTE	$F8,$90,$02,$F0
		.BYTE	$F8,$92,$42,$00
		.BYTE	$F8,$92,$02,$F8

; =============== S C R I P T ===============================================
_scr20_trolley_miner:
		NBG_HNDL_SET	_nbgsub_38D7D
_sloc_38D16:
		NJSR			_nsub_38C5B
		SBCS			_sloc_38D2C
		NJSR			_nsub_6273D
			NARGB		$58,$40
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SDELAY			$08
		POS_MOVE_STOP	0
		SJMP			_sloc_38D16
_sloc_38D2C:
		NBG_HNDL_RESET
		SARG_SET		SARG0,$80
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$58,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_sjmp_case_38D3D:
		NBG_HNDL_RESET
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$5C,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_scr_38D4B:
		NJSR			_nsub_new_thread_start
			NARGB		$0E
			NARGB		$00,$00
			NARGB		$00
			NARGB		$00
		NBG_HNDL_SET	_nbgsub_38D93
		SARG_SET		SARG0,$02
_sloc_38D59:
		SJSR			_ssub_38D73
		NJSR			_nsub_62BFD
		SBCC			_sloc_38D59
		SLOOP_BEGIN		$14
		SJSR			_ssub_38D73
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_38D3D
		SCASE			_scr_385F6
		SCASE			_scr_385FC

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_38D73:
		NJSR			_nsub_6273D
			NARGB		$5C,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S U B R O U T I N E =======================================
_nbgsub_38D7D:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		loc_38D8C
		JSR		_cur_thread_reload_param
		.WORD	_scr_38D4B
		RTS
loc_38D8C:
		LDX		#$0D
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_38D93:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_38DAC
		LSR
		LDA		#$07
		STA		_scores_obj_value
		BCS		loc_38DA7
		JSR		_cur_thread_reload_param
		.WORD	_scr_385F6
		RTS
loc_38DA7:
		JSR		_cur_thread_reload_param
		.WORD	_scr_385FC
locret_38DAC:
		RTS
_spr_raw_lib0E_58:
		.BYTE	$06
		.BYTE	$F1,$9C,$43,$00
		.BYTE	$F1,$9C,$03,$F8
		.BYTE	$00,$82,$02,$F8
		.BYTE	$00,$82,$42,$00
		.BYTE	$F0,$80,$42,$00
		.BYTE	$F0,$80,$02,$F8
_spr_raw_lib0E_59:
		.BYTE	$06
		.BYTE	$F2,$9E,$43,$F9
		.BYTE	$F2,$8E,$43,$01
		.BYTE	$F8,$90,$42,$08
		.BYTE	$F8,$90,$02,$F0
		.BYTE	$F8,$92,$42,$00
		.BYTE	$F8,$92,$02,$F8
_spr_raw_lib0E_5A:
		.BYTE	$06
		.BYTE	$F3,$8C,$03,$F8
		.BYTE	$F3,$8C,$43,$00
		.BYTE	$00,$82,$02,$F8
		.BYTE	$00,$82,$42,$00
		.BYTE	$F0,$80,$42,$00
		.BYTE	$F0,$80,$02,$F8
_spr_raw_lib0E_5B:
		.BYTE	$06
		.BYTE	$F2,$8E,$03,$F7
		.BYTE	$F2,$9E,$03,$FF
		.BYTE	$F8,$90,$42,$08
		.BYTE	$F8,$90,$02,$F0
		.BYTE	$F8,$92,$42,$00
		.BYTE	$F8,$92,$02,$F8
_spr_raw_lib0E_5C:
		.BYTE	$06
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$00,$A4,$43,$00
		.BYTE	$00,$A4,$03,$F8
		.BYTE	$F0,$B6,$03,$00
		.BYTE	$F0,$A6,$03,$F8
_spr_raw_lib0E_5D:
		.BYTE	$06
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$00,$8A,$43,$00
		.BYTE	$00,$9A,$43,$F8
		.BYTE	$F0,$98,$43,$F8
		.BYTE	$F0,$88,$43,$00
_spr_raw_lib0E_5E:
		.BYTE	$06
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$00,$B4,$43,$00
		.BYTE	$00,$B4,$03,$F8
		.BYTE	$F0,$B2,$03,$00
		.BYTE	$F0,$A2,$03,$F8
_spr_raw_lib0E_5F:
		.BYTE	$06
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$08,$3E,$03,$00
		.BYTE	$00,$9A,$03,$00
		.BYTE	$00,$8A,$03,$F8
		.BYTE	$F0,$98,$03,$00
		.BYTE	$F0,$88,$03,$F8
_spr_raw_lib0E_60:
		.BYTE	$06
		.BYTE	$08,$3E,$03,$02
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$00,$A4,$43,$02
		.BYTE	$00,$A4,$03,$FA
		.BYTE	$F0,$B6,$03,$02
		.BYTE	$F0,$A6,$03,$FA
_spr_raw_lib0E_61:
		.BYTE	$06
		.BYTE	$08,$3E,$03,$02
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$00,$8A,$43,$02
		.BYTE	$00,$9A,$43,$FA
		.BYTE	$F0,$98,$43,$FA
		.BYTE	$F0,$88,$43,$02
_spr_raw_lib0E_62:
		.BYTE	$06
		.BYTE	$08,$3E,$03,$02
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$00,$B4,$43,$02
		.BYTE	$00,$B4,$03,$FA
		.BYTE	$F0,$B2,$03,$02
		.BYTE	$F0,$A2,$03,$FA
_spr_raw_lib0E_63:
		.BYTE	$06
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$08,$3E,$03,$02
		.BYTE	$00,$9A,$03,$02
		.BYTE	$00,$8A,$03,$FA
		.BYTE	$F0,$98,$03,$02
		.BYTE	$F0,$88,$03,$FA

; =============== S C R I P T ===============================================
_scr21_train_ghost:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FA
		SJMP_SW			$01
		SCASE			_sjmp_case_390BD
		NJSR			_nsub_38FB5
		SARG_SET		SARG0,$00
		NJSR			_nsub_380D2
		SLOOP_BEGIN		$10
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG2
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_38EF6:
		NBG_HNDL_SET	_nbgsub_38F85
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG2
_sloc_38EFD:
		SLOOP_BEGIN		$0A
		SJSR			_ssub_38F2A
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SJSR			_ssub_38F1A
		SLOOP_BEGIN		$0A
		SJSR			_ssub_38F2A
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SJSR			_ssub_38F1A
		SJMP			_sloc_38EFD

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_38F1A:
		POS_MOVE_STOP	0
		SPR_IDX_ADD_IMM 0,$02
		NJSR			_nsub_new_thread_start
			NARGB		$21
			NARGB		$00,$00
			NARGB		$06
			NARGB		$00
		SDELAY			$14
		SPR_IDX_ADD_IMM 0,$FE
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_38F2A:
		NJSR			_nsub_628D1
			NARGB		$80,$00
		SLOOP_BEGIN		$14
		SDELAY			$01
		NJSR			_nsub_62C49
		SBCC			_sloc_38F41
		NJSR			_nsub_62CB0
		NJSR			_nsub_628D1
			NARGB		$80,$00
_sloc_38F41:
		NJSR			_nsub_62C7A
		SBCC			_sloc_38F4F
		NJSR			_nsub_62CBA
		NJSR			_nsub_628D1
			NARGB		$80,$00
_sloc_38F4F:
		SLOOP_END
		SRET

; =============== S C R I P T ===============================================
_scr_38F51:
		NBG_HNDL_SET	_nbgsub_38F9B
		SARG_SET		SARG0,$02
_sloc_38F57:
		SJSR			_ssub_38F71
		NJSR			_nsub_62BFD
		SBCC			_sloc_38F57
		SLOOP_BEGIN		$14
		SJSR			_ssub_38F71
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_38EF6
		SCASE			_scr_38F79
		SCASE			_scr_38F7F

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_38F71:
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG2
		SDELAY			$01
		SPR_IDX_INC		1
		SRET

; =============== S C R I P T ===============================================
_scr_38F79:
		SARG_SET		SARG1,$76
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_38F7F:
		SARG_SET		SARG1,$78
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_38F85:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		loc_38F94
		JSR		_cur_thread_reload_param
		.WORD	_scr_38F51
		RTS
loc_38F94:
		LDX		#$07
		LDY		#$08
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_38F9B:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_38FB4
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_38FAF
		JSR		_cur_thread_reload_param
		.WORD	_scr_38F79
		RTS
loc_38FAF:
		JSR		_cur_thread_reload_param
		.WORD	_scr_38F7F
locret_38FB4:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_38FB5:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		ASL
		ADC		_scr_trds_args0,X
		ADC		#$64
		STA		_scr_trds_args2,X
		RTS
_spr_raw_lib0E_64:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$E8,$43,$00
		.BYTE	$F6,$E8,$03,$F8
_spr_raw_lib0E_66:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$F8,$43,$00
		.BYTE	$F6,$F8,$03,$F8
_spr_raw_lib0E_65:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$F8,$43,$02
		.BYTE	$F6,$F8,$03,$FA
_spr_raw_lib0E_67:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$EA,$43,$00
		.BYTE	$F6,$EA,$03,$F8
_spr_raw_lib0E_69:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$FA,$43,$00
		.BYTE	$F6,$FA,$03,$F8
_spr_raw_lib0E_68:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$FA,$43,$02
		.BYTE	$F6,$FA,$03,$FA
_spr_raw_lib0E_6A:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$EC,$43,$00
		.BYTE	$F6,$EC,$03,$F8
_spr_raw_lib0E_6C:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$FC,$43,$00
		.BYTE	$F6,$FC,$03,$F8
_spr_raw_lib0E_6B:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$FC,$43,$02
		.BYTE	$F6,$FC,$03,$FA
_spr_raw_lib0E_6D:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$CA,$43,$00
		.BYTE	$F6,$CA,$03,$F8
_spr_raw_lib0E_6F:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$DA,$43,$00
		.BYTE	$F6,$DA,$03,$F8
_spr_raw_lib0E_6E:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$DA,$43,$02
		.BYTE	$F6,$DA,$03,$FA
_spr_raw_lib0E_70:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$CC,$43,$00
		.BYTE	$F6,$CC,$03,$F8
_spr_raw_lib0E_72:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$DC,$43,$00
		.BYTE	$F6,$DC,$03,$F8
_spr_raw_lib0E_71:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$DC,$43,$02
		.BYTE	$F6,$DC,$03,$FA
_spr_raw_lib0E_73:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$CE,$03,$F8
		.BYTE	$F6,$CE,$43,$00
_spr_raw_lib0E_75:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FC
		.BYTE	$F6,$DE,$43,$00
		.BYTE	$F6,$DE,$03,$F8
_spr_raw_lib0E_74:
		.BYTE	$03
		.BYTE	$02,$AC,$00,$FE
		.BYTE	$F6,$DE,$43,$02
		.BYTE	$F6,$DE,$03,$FA
_spr_raw_lib0E_77:
		.BYTE	$02
		.BYTE	$F4,$DA,$03,$F0
		.BYTE	$F4,$FE,$03,$F8
_spr_raw_lib0E_79:
		.BYTE	$02
		.BYTE	$F4,$FE,$43,$00
		.BYTE	$F4,$DA,$43,$08

; =============== S C R I P T ===============================================
_sjmp_case_390BD:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_390D9
		NJSR			_nsub_390E6
		NJSR			_nsub_628D1
			NARGB		$00,$01
		SLOOP_BEGIN		$08
		SPR_IDX_SET		4,$7A
		SPR_IDX_INC		4
		SLOOP_END
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$04
		SPR_IDX_SET		2,$7A
		SPR_IDX_INC		2
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_390D9:
		LDX		#$06
		LDY		#$07
		JSR		_player_to_obj_collision_test
		JSR		_obj_to_room_macro_collision_test_raw
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E =======================================
_nsub_390E6:
		LDA		#$21
		JSR		_rand
		CLC
		ADC		#$70
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS
_spr_raw_lib0E_7A:
		.BYTE	$01
		.BYTE	$F8,$D8,$03,$FC
_spr_raw_lib0E_7B:
		.BYTE	$01
		.BYTE	$F8,$D8,$C3,$FC

; =============== S C R I P T ===============================================
_scr2B_still_throw_ballistic_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_39173
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$05
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3910D:
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$08
		NBG_HNDL_SET	_nbgsub_39143
_sloc_39114:
		NJSR			_nsub_62ABE
		NJSR			_nsub_6273D
			NARGB		$04,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04
		NJSR			_nsub_new_thread_start
			NARGB		$2B
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		SLOOP_BEGIN		$05
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$04
		SLOOP_END
		SJMP			_sloc_39114

; =============== S C R I P T ===============================================
_scr_39132:
		NBG_HNDL_SET	_nbgsub_39159
		SJSR			_ssub_38079
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3910D
		SCASE			_scr_38096
		SCASE			_scr_3809C

; =============== S U B R O U T I N E =======================================
_nbgsub_39143:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_39152
		JSR		_cur_thread_reload_param
		.WORD	_scr_39132
		RTS
loc_39152:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_39159:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_39172
		LSR
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3916D
		JSR		_cur_thread_reload_param
		.WORD	_scr_38096
		RTS
loc_3916D:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3809C
locret_39172:
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_39173:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_3919C
		NJSR			_nsub_391A6
		SSCRIPT1_SET	_scr_39194
		NJSR			_nsub_628D1
			NARGB		$40,$02
		POS_Y_DELTA_ADD 0,$00,$FD
		SLOOP_BEGIN		$48
		POS_Y_DELTA_ADD 1,$18,$00
		SLOOP_END
		POS_MOVE_STOP	0
		SSCRIPT1_OFF
		SDELAY			$04
		SSTOP

; =============== S C R I P T ===============================================
_scr_39194:
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_ADD_IMM 4,$FD
		SJMP			_scr_39194

; =============== S U B R O U T I N E =======================================
_nbgsub_3919C:
		LDX		#$06
		LDY		#$07
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E =======================================
_nsub_391A6:
		LDA		#$07
		JSR		_rand
		ASL
		ASL
		ADC		#$7C
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_spr_idx,X
		RTS
_spr_raw_lib0E_7C:
		.BYTE	$02
		.BYTE	$F8,$98,$00,$00
		.BYTE	$F8,$88,$00,$F8
_spr_raw_lib0E_7D:
		.BYTE	$02
		.BYTE	$F8,$88,$80,$F8
		.BYTE	$F8,$98,$80,$00
_spr_raw_lib0E_7E:
		.BYTE	$02
		.BYTE	$F8,$98,$C0,$F8
		.BYTE	$F8,$88,$C0,$00
_spr_raw_lib0E_7F:
		.BYTE	$02
		.BYTE	$F8,$88,$40,$00
		.BYTE	$F8,$98,$40,$F8
_spr_raw_lib0E_80:
		.BYTE	$02
		.BYTE	$F8,$B8,$00,$00
		.BYTE	$F8,$A8,$00,$F8
_spr_raw_lib0E_81:
		.BYTE	$02
		.BYTE	$F8,$A8,$80,$F8
		.BYTE	$F8,$B8,$80,$00
_spr_raw_lib0E_82:
		.BYTE	$02
		.BYTE	$F8,$B8,$C0,$F8
		.BYTE	$F8,$A8,$C0,$00
_spr_raw_lib0E_83:
		.BYTE	$02
		.BYTE	$F8,$A8,$40,$00
		.BYTE	$F8,$B8,$40,$F8
_spr_raw_lib0E_88:
		.BYTE	$02
		.BYTE	$F8,$9A,$00,$00
		.BYTE	$F8,$8A,$00,$F8
_spr_raw_lib0E_89:
		.BYTE	$02
		.BYTE	$F8,$8A,$40,$00
		.BYTE	$F8,$9A,$40,$F8
_spr_raw_lib0E_8A:
		.BYTE	$02
		.BYTE	$F8,$9A,$C0,$F8
		.BYTE	$F8,$8A,$C0,$00
_spr_raw_lib0E_8B:
		.BYTE	$02
		.BYTE	$F8,$8A,$80,$F8
		.BYTE	$F8,$9A,$80,$00
_spr_raw_lib0E_8F:
		.BYTE	$02
		.BYTE	$F8,$BA,$00,$00
		.BYTE	$F8,$AA,$00,$F8
_spr_raw_lib0E_93:
		.BYTE	$02
		.BYTE	$F8,$9C,$00,$00
		.BYTE	$F8,$8C,$00,$F8
_spr_raw_lib0E_97:
		.BYTE	$02
		.BYTE	$F8,$BC,$00,$00
		.BYTE	$F8,$AC,$00,$F8
_spr_raw_lib0E_84:
		.BYTE	$02
		.BYTE	$F8,$9E,$00,$00
		.BYTE	$F8,$8E,$00,$F8
_spr_raw_lib0E_85:
		.BYTE	$02
		.BYTE	$F8,$8E,$40,$00
		.BYTE	$F8,$9E,$40,$F8
_spr_raw_lib0E_86:
		.BYTE	$02
		.BYTE	$F8,$9E,$C0,$F8
		.BYTE	$F8,$8E,$C0,$00
_spr_raw_lib0E_87:
		.BYTE	$02
		.BYTE	$F8,$9E,$80,$00
		.BYTE	$F8,$8E,$80,$F8

; =============== S C R I P T ===============================================
_scr2C_fast_throw_forward_slime:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_392FF
		NJSR			_nsub_62ABE
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$04,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_39277:
		NBG_HNDL_SET	_nbgsub_392CF
_sloc_3927A:
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_3805C
		SLOOP_BEGIN		$06
		SLOOP_BEGIN		$0A
		SDELAY			$01
		NJSR			_nsub_62C49
		SBCC			_sloc_3929B
		NJSR			_nsub_62CB0
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_3805C
_sloc_3929B:
		NJSR			_nsub_62C7A
		SBCC			_sloc_392AD
		NJSR			_nsub_62CBA
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_3805C
_sloc_392AD:
		SLOOP_END
		NJSR			_nsub_62AEC
			NARGB		$08
		SLOOP_END
		NJSR			_nsub_new_thread_start
			NARGB		$2C
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		SJMP			_sloc_3927A

; =============== S C R I P T ===============================================
_scr_392BE:
		NBG_HNDL_SET	_nbgsub_392E5
		SJSR			_ssub_38079
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_39277
		SCASE			_scr_38096
		SCASE			_scr_3809C

; =============== S U B R O U T I N E =======================================
_nbgsub_392CF:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_392DE
		JSR		_cur_thread_reload_param
		.WORD	_scr_392BE
		RTS
loc_392DE:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_392E5:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_392FE
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_392F9
		JSR		_cur_thread_reload_param
		.WORD	_scr_38096
		RTS
loc_392F9:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3809C
locret_392FE:
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_392FF:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_39315
		NJSR			_nsub_391A6
		NJSR			_nsub_628D1
			NARGB		$80,$01
_sloc_3930D:
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_ADD_IMM 4,$FD
		SJMP			_sloc_3930D

; =============== S U B R O U T I N E =======================================
_nbgsub_39315:
		LDX		#$06
		LDY		#$07
		JSR		_player_to_obj_collision_test
		JSR		_cur_obj_out_of_screen_test
		JMP		_obj_to_room_macro_collision_test_raw
_spr_raw_lib0E:
		.WORD	_spr_raw_lib1A_00
		.WORD	_spr_raw_lib1A_01
		.WORD	_spr_raw_lib1A_02
		.WORD	_spr_raw_lib1A_03
		.WORD	_spr_raw_lib0E_04
		.WORD	_spr_raw_lib0E_05
		.WORD	_spr_raw_lib0E_06
		.WORD	_spr_raw_lib0E_07
		.WORD	_spr_raw_lib0E_08
		.WORD	_spr_raw_lib0E_09
		.WORD	_spr_raw_lib0E_0A
		.WORD	_spr_raw_lib0E_0B
		.WORD	_spr_raw_lib0E_0C
		.WORD	_spr_raw_lib0E_0D
		.WORD	_spr_raw_lib0E_0E
		.WORD	_spr_raw_lib0E_0F
		.WORD	_spr_raw_lib0E_10
		.WORD	_spr_raw_lib0E_11
		.WORD	_spr_raw_lib0E_12
		.WORD	_spr_raw_lib0E_13
		.WORD	_spr_raw_lib0E_14
		.WORD	_spr_raw_lib0E_18
		.WORD	_spr_raw_lib0E_18
		.WORD	_spr_raw_lib0E_18
		.WORD	_spr_raw_lib0E_18
		.WORD	_spr_raw_lib0E_1C
		.WORD	_spr_raw_lib0E_1C
		.WORD	_spr_raw_lib0E_1C
		.WORD	_spr_raw_lib0E_1C
		.WORD	_spr_raw_lib0E_20
		.WORD	_spr_raw_lib0E_20
		.WORD	_spr_raw_lib0E_20
		.WORD	_spr_raw_lib0E_20
		.WORD	_spr_raw_lib0E_21
		.WORD	_spr_raw_lib0E_22
		.WORD	_spr_raw_lib0E_23
		.WORD	_spr_raw_lib0E_24
		.WORD	_spr_raw_lib0E_25
		.WORD	_spr_raw_lib0E_26
		.WORD	_spr_raw_lib0E_27
		.WORD	_spr_raw_lib0E_28
		.WORD	_spr_raw_lib0E_29
		.WORD	_spr_raw_lib0E_2A
		.WORD	_spr_raw_lib0E_2B
		.WORD	_spr_raw_lib0E_2C
		.WORD	_spr_raw_lib0E_2D
		.WORD	_spr_raw_lib0E_2E
		.WORD	_spr_raw_lib0E_2F
		.WORD	_spr_raw_lib0E_30
		.WORD	_spr_raw_lib0E_31
		.WORD	_spr_raw_lib0E_32
		.WORD	_spr_raw_lib0E_33
		.WORD	_spr_raw_lib0E_34
		.WORD	_spr_raw_lib0E_35
		.WORD	_spr_raw_lib0E_36
		.WORD	_spr_raw_lib0E_37
		.WORD	_spr_raw_lib0E_38
		.WORD	_spr_raw_lib0E_39
		.WORD	_spr_raw_lib0E_3A
		.WORD	_spr_raw_lib0E_3B
		.WORD	_spr_raw_lib0E_3C
		.WORD	_spr_raw_lib0E_3D
		.WORD	_spr_raw_lib0E_3E
		.WORD	_spr_raw_lib0E_3F
		.WORD	_spr_raw_lib0E_40
		.WORD	_spr_raw_lib0E_41
		.WORD	_spr_raw_lib0E_42
		.WORD	_spr_raw_lib0E_43
		.WORD	_spr_raw_lib0E_44
		.WORD	_spr_raw_lib0E_45
		.WORD	_spr_raw_lib0E_46
		.WORD	_spr_raw_lib0E_47
		.WORD	_spr_raw_lib0E_48
		.WORD	_spr_raw_lib0E_49
		.WORD	_spr_raw_lib0E_4A
		.WORD	_spr_raw_lib0E_4B
		.WORD	_spr_raw_lib0E_4C
		.WORD	_spr_raw_lib0E_4D
		.WORD	_spr_raw_lib0E_4E
		.WORD	_spr_raw_lib0E_4F
		.WORD	_spr_raw_lib0E_50
		.WORD	_spr_raw_lib0E_51
		.WORD	_spr_raw_lib0E_52
		.WORD	_spr_raw_lib0E_53
		.WORD	_spr_raw_lib0E_56
		.WORD	_spr_raw_lib0E_57
		.WORD	_spr_raw_lib0E_56
		.WORD	_spr_raw_lib0E_57
		.WORD	_spr_raw_lib0E_58
		.WORD	_spr_raw_lib0E_59
		.WORD	_spr_raw_lib0E_5A
		.WORD	_spr_raw_lib0E_5B
		.WORD	_spr_raw_lib0E_5C
		.WORD	_spr_raw_lib0E_5D
		.WORD	_spr_raw_lib0E_5E
		.WORD	_spr_raw_lib0E_5F
		.WORD	_spr_raw_lib0E_60
		.WORD	_spr_raw_lib0E_61
		.WORD	_spr_raw_lib0E_62
		.WORD	_spr_raw_lib0E_63
		.WORD	_spr_raw_lib0E_64
		.WORD	_spr_raw_lib0E_65
		.WORD	_spr_raw_lib0E_66
		.WORD	_spr_raw_lib0E_67
		.WORD	_spr_raw_lib0E_68
		.WORD	_spr_raw_lib0E_69
		.WORD	_spr_raw_lib0E_6A
		.WORD	_spr_raw_lib0E_6B
		.WORD	_spr_raw_lib0E_6C
		.WORD	_spr_raw_lib0E_6D
		.WORD	_spr_raw_lib0E_6E
		.WORD	_spr_raw_lib0E_6F
		.WORD	_spr_raw_lib0E_70
		.WORD	_spr_raw_lib0E_71
		.WORD	_spr_raw_lib0E_72
		.WORD	_spr_raw_lib0E_73
		.WORD	_spr_raw_lib0E_74
		.WORD	_spr_raw_lib0E_75
		.WORD	_spr_raw_lib0E_77
		.WORD	_spr_raw_lib0E_77
		.WORD	_spr_raw_lib0E_79
		.WORD	_spr_raw_lib0E_79
		.WORD	_spr_raw_lib0E_7A
		.WORD	_spr_raw_lib0E_7B
		.WORD	_spr_raw_lib0E_7C
		.WORD	_spr_raw_lib0E_7D
		.WORD	_spr_raw_lib0E_7E
		.WORD	_spr_raw_lib0E_7F
		.WORD	_spr_raw_lib0E_80
		.WORD	_spr_raw_lib0E_81
		.WORD	_spr_raw_lib0E_82
		.WORD	_spr_raw_lib0E_83
		.WORD	_spr_raw_lib0E_84
		.WORD	_spr_raw_lib0E_85
		.WORD	_spr_raw_lib0E_86
		.WORD	_spr_raw_lib0E_87
		.WORD	_spr_raw_lib0E_88
		.WORD	_spr_raw_lib0E_89
		.WORD	_spr_raw_lib0E_8A
		.WORD	_spr_raw_lib0E_8B
		.WORD	_spr_raw_lib0E_8F
		.WORD	_spr_raw_lib0E_8F
		.WORD	_spr_raw_lib0E_8F
		.WORD	_spr_raw_lib0E_8F
		.WORD	_spr_raw_lib0E_93
		.WORD	_spr_raw_lib0E_93
		.WORD	_spr_raw_lib0E_93
		.WORD	_spr_raw_lib0E_93
		.WORD	_spr_raw_lib0E_97
		.WORD	_spr_raw_lib0E_97
		.WORD	_spr_raw_lib0E_97
		.WORD	_spr_raw_lib0E_97

; =============== S C R I P T ===============================================
_scr23_halloween:
		NJSR			_nsub_62ABE
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$C2
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3945C:
		NBG_HNDL_SET	_nbgsub_394DE
_sloc_3945F:
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_39498
		SLOOP_BEGIN		$14
		SDELAY			$01
		NJSR			_nsub_62C49
		SBCC			_sloc_3947E
		NJSR			_nsub_62CB0
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_39498
_sloc_3947E:
		NJSR			_nsub_62C7A
		SBCC			_sloc_39490
		NJSR			_nsub_62CBA
		NJSR			_nsub_628D1
			NARGB		$C0,$00
		SSCRIPT1_SET	_scr_39498
_sloc_39490:
		SLOOP_END
		NJSR			_nsub_62AEC
			NARGB		$10
		SJMP			_sloc_3945F

; =============== S C R I P T ===============================================
_scr_39498:
		NJSR			_nsub_6273D
			NARGB		$C0,$40
_sloc_3949D:
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$0A
		SPR_IDX_ADD_IMM 0,$FC
		SDELAY			$0A
		SJMP			_sloc_3949D

; =============== S C R I P T ===============================================
_scr_394A8:
		NBG_HNDL_SET	_nbgsub_394F4
		SARG_SET		SARG0,$02
_sloc_394AE:
		SJSR			_ssub_394C8
		NJSR			_nsub_62BFD
		SBCC			_sloc_394AE
		SLOOP_BEGIN		$14
		SJSR			_ssub_394C8
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3945C
		SCASE			_sjmp_case_394D2
		SCASE			_sjmp_case_394D8

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_394C8:
		NJSR			_nsub_6273D
			NARGB		$C0,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ===============================================
_sjmp_case_394D2:
		SARG_SET		SARG1,$04
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_sjmp_case_394D8:
		SARG_SET		SARG1,$06
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_394DE:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_394ED
		JSR		_cur_thread_reload_param
		.WORD	_scr_394A8
		RTS
loc_394ED:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_394F4:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3950D
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_39508
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_394D2
		RTS
loc_39508:
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_394D8
locret_3950D:
		RTS

_spr_res_lib0F_00:
		.BYTE	$01
		.WORD	_spr_res_lib0F_00_A
_spr_res_lib0F_01:
		.BYTE	$01
		.WORD	_spr_res_lib0F_01_A
_spr_res_lib0F_02:
		.BYTE	$01
		.WORD	_spr_res_lib0F_02_A
_spr_res_lib0F_03:
		.BYTE	$01
		.WORD	_spr_res_lib0F_03_A
_spr_res_lib0F_04:
		.BYTE	$01
		.WORD	_spr_res_lib0F_04_A
_spr_res_lib0F_05:
		.BYTE	$01
		.WORD	_spr_res_lib0F_05_A
_spr_res_lib0F_06:
		.BYTE	$01
		.WORD	_spr_res_lib0F_06_A
_spr_res_lib0F_07:
		.BYTE	$01
		.WORD	_spr_res_lib0F_07_A
_spr_res_lib0F_08:
		.BYTE	$01
		.WORD	_spr_res_lib0F_08_A
_spr_res_lib0F_09:
		.BYTE	$01
		.WORD	_spr_res_lib0F_09_A
_spr_res_lib0F_0A:
		.BYTE	$01
		.WORD	_spr_res_lib0F_0A_A
_spr_res_lib0F_0B:
		.BYTE	$01
		.WORD	_spr_res_lib0F_0B_A
_spr_res_lib0F_00_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$EC,$B8,$03,$08
		.BYTE	$FC,$8A,$03,$F8
		.BYTE	$EC,$88,$03,$F8
		.BYTE	$FC,$9A,$03,$00
		.BYTE	$EC,$98,$03,$00
_spr_res_lib0F_04_A:
		.BYTE	$06
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$88,$43,$00
		.BYTE	$FC,$8A,$43,$00
		.BYTE	$FC,$AA,$03,$F8
		.BYTE	$EC,$A8,$03,$F8
_spr_res_lib0F_01_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$EC,$BC,$43,$08
		.BYTE	$FC,$AC,$43,$08
		.BYTE	$FC,$86,$43,$00
		.BYTE	$FC,$96,$43,$F8
		.BYTE	$EC,$94,$43,$F8
		.BYTE	$EC,$84,$43,$00
_spr_res_lib0F_05_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$FC,$BA,$43,$08
		.BYTE	$EC,$A4,$43,$00
		.BYTE	$FC,$A6,$43,$00
		.BYTE	$FC,$B6,$43,$F8
		.BYTE	$EC,$B4,$43,$F8
_spr_res_lib0F_02_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$90,$03,$00
		.BYTE	$EC,$80,$03,$F8
		.BYTE	$EC,$9C,$03,$F0
		.BYTE	$FC,$9E,$03,$F0
		.BYTE	$FC,$82,$03,$F8
		.BYTE	$FC,$92,$03,$00
_spr_res_lib0F_06_A:
		.BYTE	$06
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$A0,$03,$F8
		.BYTE	$EC,$B0,$03,$00
		.BYTE	$FC,$A2,$03,$F8
		.BYTE	$FC,$B2,$03,$00
_spr_res_lib0F_03_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$EC,$BC,$03,$F0
		.BYTE	$FC,$AC,$03,$F0
		.BYTE	$FC,$86,$03,$F8
		.BYTE	$FC,$96,$03,$00
		.BYTE	$EC,$94,$03,$00
		.BYTE	$EC,$84,$03,$F8
_spr_res_lib0F_07_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$40,$F8
		.BYTE	$0A,$3E,$00,$00
		.BYTE	$FC,$BA,$03,$F0
		.BYTE	$EC,$A4,$03,$F8
		.BYTE	$FC,$A6,$03,$F8
		.BYTE	$FC,$B6,$03,$00
		.BYTE	$EC,$B4,$03,$00
_spr_res_lib0F_08_A:
		.BYTE	$07
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$EC,$B8,$03,$0A
		.BYTE	$FC,$8A,$03,$FA
		.BYTE	$EC,$88,$03,$FA
		.BYTE	$FC,$9A,$03,$02
		.BYTE	$EC,$98,$03,$02
_spr_res_lib0F_09_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$EC,$BC,$43,$0A
		.BYTE	$FC,$AC,$43,$0A
		.BYTE	$FC,$86,$43,$02
		.BYTE	$FC,$96,$43,$FA
		.BYTE	$EC,$94,$43,$FA
		.BYTE	$EC,$84,$43,$02
_spr_res_lib0F_0A_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$EC,$90,$03,$02
		.BYTE	$EC,$80,$03,$FA
		.BYTE	$EC,$9C,$03,$F2
		.BYTE	$FC,$9E,$03,$F2
		.BYTE	$FC,$82,$03,$FA
		.BYTE	$FC,$92,$03,$02
_spr_res_lib0F_0B_A:
		.BYTE	$08
		.BYTE	$0A,$3E,$00,$02
		.BYTE	$0A,$3E,$40,$FA
		.BYTE	$EC,$BC,$03,$F2
		.BYTE	$FC,$AC,$03,$F2
		.BYTE	$FC,$86,$03,$FA
		.BYTE	$FC,$96,$03,$02
		.BYTE	$EC,$94,$03,$02
		.BYTE	$EC,$84,$03,$FA
_spr_raw_lib0F_04:
		.BYTE	$04
		.BYTE	$EE,$94,$03,$F8
		.BYTE	$EE,$84,$03,$F0
		.BYTE	$FE,$8C,$03,$F0
		.BYTE	$FE,$8E,$03,$F8
_spr_raw_lib0F_05:
		.BYTE	$04
		.BYTE	$F6,$94,$03,$F8
		.BYTE	$F6,$84,$03,$F0
		.BYTE	$FE,$6E,$03,$F0
		.BYTE	$FE,$7E,$03,$F8
_spr_raw_lib0F_06:
		.BYTE	$04
		.BYTE	$EE,$94,$43,$00
		.BYTE	$EE,$84,$43,$08
		.BYTE	$FE,$8C,$43,$08
		.BYTE	$FE,$8E,$43,$00
_spr_raw_lib0F_07:
		.BYTE	$04
		.BYTE	$F6,$94,$43,$00
		.BYTE	$F6,$84,$43,$08
		.BYTE	$FE,$6E,$43,$08
		.BYTE	$FE,$7E,$43,$00

; =============== S C R I P T ===============================================
_scr24_flying_wing_elephant:
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$CC,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_396EE:
		NBG_HNDL_SET	_nbgsub_39785
_sloc_396F1:
		NJSR			_nsub_604CD
		SJSR_SW	$04
		SCASE			_sjsr_case_39706
		SCASE			_sjsr_case_39716
		SCASE			_sjsr_case_39726
		SCASE			_sjsr_case_39736
		POS_MOVE_STOP	0
		SARG_ALU		SARG1,_ADC,$40
		SJMP			_sloc_396F1
_sjsr_case_39706:
		POS_Y_DELTA_SET 0,$80,$FE
_sloc_39709:
		SPR_IDX_SET		0,$CC
		SJSR			_ssub_39746
		NJSR			_nsub_cur_pos_y_lo_icmp
			NARGB		$50
		SBCC			_sloc_39709
		SRET
_sjsr_case_39716:
		POS_X_DELTA_SET 0,$80,$01
_sloc_39719:
		SPR_IDX_SET		0,$CD
		SJSR			_ssub_39746
		NJSR			_nsub_cur_pos_x_lo_icmp
			NARGB		$B0
		SBCS			_sloc_39719
		SRET
_sjsr_case_39726:
		POS_Y_DELTA_SET 0,$80,$01
_sloc_39729:
		SPR_IDX_SET		0,$CE
		SJSR			_ssub_39746
		NJSR			_nsub_cur_pos_y_lo_icmp
			NARGB		$A0
		SBCS			_sloc_39729
		SRET
_sjsr_case_39736:
		POS_X_DELTA_SET 0,$80,$FE
_sloc_39739:
		SPR_IDX_SET		0,$CF
		SJSR			_ssub_39746
		NJSR			_nsub_cur_pos_x_lo_icmp
			NARGB		$50
		SBCC			_sloc_39739
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_39746:
		SDELAY			$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$FC
		SRET

; =============== S C R I P T ===============================================
_scr_3974F:
		NBG_HNDL_SET	_nbgsub_3979B
		SARG_SET		SARG0,$02
_sloc_39755:
		SJSR			_ssub_3976F
		NJSR			_nsub_62BFD
		SBCC			_sloc_39755
		SLOOP_BEGIN		$14
		SJSR			_ssub_3976F
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_396EE
		SCASE			_sjmp_case_39779
		SCASE			_sjmp_case_3977F

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3976F:
		NJSR			_nsub_6273D
			NARGB		$CC,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$18
		SRET

; =============== S C R I P T ===============================================
_sjmp_case_39779:
		SARG_SET		SARG1,$08
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_sjmp_case_3977F:
		SARG_SET		SARG1,$0A
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_39785:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		loc_39794
		JSR		_cur_thread_reload_param
		.WORD	_scr_3974F
		RTS
loc_39794:
		LDX		#$0D
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3979B:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_397B4
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_397AF
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_39779
		RTS
loc_397AF:
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_3977F
locret_397B4:
		RTS
_spr_res_lib0F_0C:
		.BYTE	$01
		.WORD	_spr_res_lib0F_0C_A
_spr_res_lib0F_10:
		.BYTE	$01
		.WORD	_spr_res_lib0F_10_A
_spr_res_lib0F_14:
		.BYTE	$01
		.WORD	_spr_res_lib0F_14_A
_spr_res_lib0F_0D:
		.BYTE	$01
		.WORD	_spr_res_lib0F_0D_A
_spr_res_lib0F_11:
		.BYTE	$01
		.WORD	_spr_res_lib0F_11_A
_spr_res_lib0F_15:
		.BYTE	$01
		.WORD	_spr_res_lib0F_15_A
_spr_res_lib0F_0E:
		.BYTE	$01
		.WORD	_spr_res_lib0F_0E_A
_spr_res_lib0F_12:
		.BYTE	$01
		.WORD	_spr_res_lib0F_12_A
_spr_res_lib0F_16:
		.BYTE	$01
		.WORD	_spr_res_lib0F_16_A
_spr_res_lib0F_0F:
		.BYTE	$01
		.WORD	_spr_res_lib0F_0F_A
_spr_res_lib0F_13:
		.BYTE	$01
		.WORD	_spr_res_lib0F_13_A
_spr_res_lib0F_17:
		.BYTE	$01
		.WORD	_spr_res_lib0F_17_A
_spr_res_lib0F_24:
		.BYTE	$01
		.WORD	_spr_res_lib0F_24_A
_spr_res_lib0F_25:
		.BYTE	$01
		.WORD	_spr_res_lib0F_25_A
_spr_res_lib0F_26:
		.BYTE	$01
		.WORD	_spr_res_lib0F_26_A
_spr_res_lib0F_27:
		.BYTE	$01
		.WORD	_spr_res_lib0F_27_A
_spr_res_lib0F_0C_A:
		.BYTE	$06
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$F4,$AC,$43,$00
		.BYTE	$F4,$AC,$03,$F8
_spr_res_lib0F_10_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$AA,$43,$00
		.BYTE	$EB,$BA,$C3,$00
		.BYTE	$F3,$AA,$03,$F8
_spr_res_lib0F_14_A:
		.BYTE	$07
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$A8,$43,$00
		.BYTE	$EA,$B8,$C3,$00
		.BYTE	$F2,$A8,$03,$F8
_spr_res_lib0F_0D_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F4,$A2,$43,$10
		.BYTE	$F4,$B2,$43,$08
		.BYTE	$E4,$B4,$43,$F8
		.BYTE	$F4,$B6,$43,$F8
		.BYTE	$F4,$A6,$43,$00
_spr_res_lib0F_11_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$82,$43,$10
		.BYTE	$F3,$92,$43,$08
		.BYTE	$F3,$A6,$43,$00
		.BYTE	$F3,$96,$43,$F8
_spr_res_lib0F_15_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$84,$43,$10
		.BYTE	$F2,$94,$43,$08
		.BYTE	$F2,$A6,$43,$00
		.BYTE	$F2,$86,$43,$F8
_spr_res_lib0F_0E_A:
		.BYTE	$07
		.BYTE	$04,$BC,$03,$F8
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$F4,$9C,$03,$F8
		.BYTE	$F4,$9C,$43,$00
_spr_res_lib0F_12_A:
		.BYTE	$07
		.BYTE	$03,$BA,$43,$F8
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$9A,$43,$00
		.BYTE	$F3,$9A,$03,$F8
_spr_res_lib0F_16_A:
		.BYTE	$07
		.BYTE	$02,$B8,$43,$F8
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$98,$43,$00
		.BYTE	$F2,$98,$03,$F8
_spr_res_lib0F_0F_A:
		.BYTE	$07
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F4,$A2,$03,$E8
		.BYTE	$F4,$B2,$03,$F0
		.BYTE	$E4,$B4,$03,$00
		.BYTE	$F4,$B6,$03,$00
		.BYTE	$F4,$A6,$03,$F8
_spr_res_lib0F_13_A:
		.BYTE	$06
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F3,$82,$03,$E8
		.BYTE	$F3,$92,$03,$F0
		.BYTE	$F3,$A6,$03,$F8
		.BYTE	$F3,$96,$03,$00
_spr_res_lib0F_17_A:
		.BYTE	$06
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F2,$84,$03,$E8
		.BYTE	$F2,$94,$03,$F0
		.BYTE	$F2,$A6,$03,$F8
		.BYTE	$F2,$86,$03,$00
_spr_res_lib0F_24_A:
		.BYTE	$06
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$06,$3E,$00,$02
		.BYTE	$E4,$8C,$03,$FA
		.BYTE	$E4,$8C,$43,$02
		.BYTE	$F4,$AC,$43,$02
		.BYTE	$F4,$AC,$03,$FA
_spr_res_lib0F_25_A:
		.BYTE	$07
		.BYTE	$06,$3E,$00,$02
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$F4,$A2,$43,$12
		.BYTE	$F4,$B2,$43,$0A
		.BYTE	$E4,$B4,$43,$FA
		.BYTE	$F4,$B6,$43,$FA
		.BYTE	$F4,$A6,$43,$02
_spr_res_lib0F_26_A:
		.BYTE	$07
		.BYTE	$04,$BC,$03,$FA
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$06,$3E,$00,$02
		.BYTE	$E4,$8C,$43,$02
		.BYTE	$E4,$8C,$03,$FA
		.BYTE	$F4,$9C,$03,$FA
		.BYTE	$F4,$9C,$43,$02
_spr_res_lib0F_27_A:
		.BYTE	$07
		.BYTE	$06,$3E,$40,$FA
		.BYTE	$06,$3E,$00,$02
		.BYTE	$F4,$A2,$03,$EA
		.BYTE	$F4,$B2,$03,$F2
		.BYTE	$E4,$B4,$03,$02
		.BYTE	$F4,$B6,$03,$02
		.BYTE	$F4,$A6,$03,$FA
_spr_raw_lib0F_0A:
		.BYTE	$04
		.BYTE	$EE,$8C,$03,$FE
		.BYTE	$EE,$8C,$43,$06
		.BYTE	$FE,$B0,$43,$FE
		.BYTE	$FE,$A0,$43,$06
_spr_raw_lib0F_0B:
		.BYTE	$02
		.BYTE	$FD,$90,$43,$FF
		.BYTE	$FD,$80,$43,$07
_spr_raw_lib0F_08:
		.BYTE	$04
		.BYTE	$EE,$8C,$43,$FB
		.BYTE	$EE,$8C,$03,$F3
		.BYTE	$FE,$B0,$03,$FB
		.BYTE	$FE,$A0,$03,$F3
_spr_raw_lib0F_09:
		.BYTE	$02
		.BYTE	$FD,$90,$03,$FA
		.BYTE	$FD,$80,$03,$F2

; =============== S C R I P T ===============================================
_scr25_stinging_wing_elephant:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_39B86
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$D8,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_399E6:
		NBG_HNDL_SET	_nbgsub_39A2E
_sloc_399E9:
		SLOOP_BEGIN		$06
		NJSR			_nsub_6273D
			NARGB		$D8,$40
		SDELAY			$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 4,$FC
		SLOOP_END
		NJSR			_nsub_new_thread_start
			NARGB		$25
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		SJMP			_sloc_399E9

; =============== S C R I P T ===============================================
_scr_39A04:
		NBG_HNDL_SET	_nbgsub_39A44
		SARG_SET		SARG0,$02
_sloc_39A0A:
		SJSR			_ssub_39A24
		NJSR			_nsub_62BFD
		SBCC			_sloc_39A0A
		SLOOP_BEGIN		$14
		SJSR			_ssub_39A24
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_399E6
		SCASE			_sjmp_case_39779
		SCASE			_sjmp_case_3977F

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_39A24:
		NJSR			_nsub_6273D
			NARGB		$D8,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$0C
		SRET

; =============== S U B R O U T I N E =======================================
_nbgsub_39A2E:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		loc_39A3D
		JSR		_cur_thread_reload_param
		.WORD	_scr_39A04
		RTS
loc_39A3D:
		LDX		#$0D
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_39A44:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_39A5D
		LSR
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_39A58
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_39779
		RTS
loc_39A58:
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_3977F
locret_39A5D:
		RTS
_spr_res_lib0F_18:
		.BYTE	$01
		.WORD	_spr_res_lib0F_18_A
_spr_res_lib0F_1C:
		.BYTE	$01
		.WORD	_spr_res_lib0F_1C_A
_spr_res_lib0F_20:
		.BYTE	$01
		.WORD	_spr_res_lib0F_20_A
_spr_res_lib0F_19:
		.BYTE	$01
		.WORD	_spr_res_lib0F_19_A
_spr_res_lib0F_1D:
		.BYTE	$01
		.WORD	_spr_res_lib0F_1D_A
_spr_res_lib0F_21:
		.BYTE	$01
		.WORD	_spr_res_lib0F_21_A
_spr_res_lib0F_1A:
		.BYTE	$01		; *--
		.WORD	_spr_res_lib0F_1A_A	; *--
_spr_res_lib0F_1E:
		.BYTE	$01		; *--
		.WORD	_spr_res_lib0F_1E_A	; *--
_spr_res_lib0F_22:
		.BYTE	$01		; *--
		.WORD	_spr_res_lib0F_22_A	; *--
_spr_res_lib0F_1B:
		.BYTE	$01
		.WORD	_spr_res_lib0F_1B_A
_spr_res_lib0F_1F:
		.BYTE	$01
		.WORD	_spr_res_lib0F_1F_A
_spr_res_lib0F_23:
		.BYTE	$01
		.WORD	_spr_res_lib0F_23_A
_spr_res_lib0F_18_A:
		.BYTE	$06
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$E4,$8C,$03,$F8
		.BYTE	$E4,$8C,$43,$00
		.BYTE	$F4,$AC,$43,$00
		.BYTE	$F4,$AC,$03,$F8
_spr_res_lib0F_1C_A:
		.BYTE	$06
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$8A,$03,$F0
		.BYTE	$F3,$8A,$43,$08
		.BYTE	$F3,$AA,$43,$00
		.BYTE	$F3,$AA,$03,$F8
_spr_res_lib0F_20_A:
		.BYTE	$06
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F2,$88,$03,$F0
		.BYTE	$F2,$88,$43,$08
		.BYTE	$F2,$A8,$43,$00
		.BYTE	$F2,$A8,$03,$F8
_spr_res_lib0F_19_A:
		.BYTE	$05
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$E4,$B4,$43,$F8
		.BYTE	$F4,$B6,$43,$F8
		.BYTE	$F4,$A6,$43,$00
_spr_res_lib0F_1D_A:
		.BYTE	$04
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F3,$A6,$43,$00
		.BYTE	$F3,$96,$43,$F8
_spr_res_lib0F_21_A:
		.BYTE	$04
		.BYTE	$06,$3E,$00,$00
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$F2,$A6,$43,$00
		.BYTE	$F2,$86,$43,$F8
_spr_res_lib0F_1A_A:
		.BYTE	$06		; *--
		.BYTE	$06,$3E,$40,$F8	; *--
		.BYTE	$06,$3E,$00,$00	; *--
		.BYTE	$E4,$8C,$43,$00	; *--
		.BYTE	$E4,$8C,$03,$F8	; *--
		.BYTE	$F4,$9C,$03,$F8	; *--
		.BYTE	$F4,$9C,$43,$00	; *--
_spr_res_lib0F_1E_A:
		.BYTE	$06		; *--
		.BYTE	$06,$3E,$40,$F8	; *--
		.BYTE	$06,$3E,$00,$00	; *--
		.BYTE	$F3,$8A,$03,$F0	; *--
		.BYTE	$F3,$8A,$43,$08	; *--
		.BYTE	$F3,$9A,$43,$00	; *--
		.BYTE	$F3,$9A,$03,$F8	; *--
_spr_res_lib0F_22_A:
		.BYTE	$06		; *--
		.BYTE	$06,$3E,$40,$F8	; *--
		.BYTE	$06,$3E,$00,$00	; *--
		.BYTE	$F2,$88,$03,$F0	; *--
		.BYTE	$F2,$88,$43,$08	; *--
		.BYTE	$F2,$98,$43,$00	; *--
		.BYTE	$F2,$98,$03,$F8	; *--
_spr_res_lib0F_1B_A:
		.BYTE	$05
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$E4,$B4,$03,$00
		.BYTE	$F4,$B6,$03,$00
		.BYTE	$F4,$A6,$03,$F8
_spr_res_lib0F_1F_A:
		.BYTE	$04
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F3,$A6,$03,$F8
		.BYTE	$F3,$96,$03,$00
_spr_res_lib0F_23_A:
		.BYTE	$04
		.BYTE	$06,$3E,$40,$F8
		.BYTE	$06,$3E,$00,$00
		.BYTE	$F2,$A6,$03,$F8
		.BYTE	$F2,$86,$03,$00

; =============== S C R I P T ===============================================
_sjmp_case_39B86:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_39BED
		NJSR			_nsub_604CD
		SJMP_SW			$04
		SCASE			_sjmp_case_39B99
		SCASE			_sjmp_case_39BAE
		SCASE			_sjmp_case_39BC3
		SCASE			_sjmp_case_39BD8

; =============== S C R I P T ===============================================
_sjmp_case_39B99:
		POS_X_MOVE	0,$02
		POS_Y_MOVE		0,$EC
		SPR_IDX_SET		2,$0C
		SLOOP_BEGIN		$04
		POS_Y_MOVE		0,$F8
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14
		SLOOP_BEGIN		$04
		POS_Y_MOVE		0,$08
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_sjmp_case_39BAE:
		POS_X_MOVE	0,$08
		POS_Y_MOVE		0,$FE
		SPR_IDX_SET		2,$11
		SLOOP_BEGIN		$03
		POS_X_MOVE	0,$08
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14
		SLOOP_BEGIN		$03
		POS_X_MOVE	0,$F8
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_sjmp_case_39BC3:
		POS_X_MOVE	0,$FB
		POS_Y_MOVE		0,$0B
		SPR_IDX_SET		2,$15
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

; =============== S C R I P T ===============================================
_sjmp_case_39BD8:
		POS_X_MOVE	0,$F2
		POS_Y_MOVE		0,$FE
		SPR_IDX_SET		2,$1A
		SLOOP_BEGIN		$03
		POS_X_MOVE	0,$F8
		SPR_IDX_INC		2
		SLOOP_END
		SDELAY			$14
		SLOOP_BEGIN		$03
		POS_X_MOVE	0,$08
		SPR_IDX_DEC		4
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_39BED:
		LDX		#$06
		LDY		#$07
		JMP		_player_to_obj_collision_test
_spr_raw_lib0F_0C:
		.BYTE	$01
		.BYTE	$F8,$B8,$83,$FC
_spr_raw_lib0F_0D:
		.BYTE	$02
		.BYTE	$F8,$B8,$83,$FC
		.BYTE	$00,$8E,$83,$FC
_spr_raw_lib0F_0E:
		.BYTE	$02
		.BYTE	$F8,$B8,$83,$FC
		.BYTE	$08,$8E,$83,$FC
_spr_raw_lib0F_0F:
		.BYTE	$03
		.BYTE	$10,$8E,$03,$FC
		.BYTE	$F8,$B8,$83,$FC
		.BYTE	$08,$8E,$83,$FC
_spr_raw_lib0F_10:
		.BYTE	$03
		.BYTE	$18,$8E,$03,$FC
		.BYTE	$F8,$B8,$83,$FC
		.BYTE	$08,$8E,$83,$FC
_spr_raw_lib0F_11:
		.BYTE	$02
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$84,$43,$00
_spr_raw_lib0F_12:
		.BYTE	$03
		.BYTE	$F5,$A4,$43,$F0
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$84,$43,$00
_spr_raw_lib0F_13:
		.BYTE	$04
		.BYTE	$F5,$A4,$43,$E8
		.BYTE	$F5,$A4,$43,$F0
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$84,$43,$00
_spr_raw_lib0F_14:
		.BYTE	$05
		.BYTE	$F5,$A4,$43,$E0
		.BYTE	$F5,$A4,$43,$E8
		.BYTE	$F5,$A4,$43,$F0
		.BYTE	$F5,$94,$43,$F8
		.BYTE	$F5,$84,$43,$00
_spr_raw_lib0F_15:
		.BYTE	$01		; *--
		.BYTE	$F8,$B8,$03,$FC	; *--
_spr_raw_lib0F_16:
		.BYTE	$02		; *--
		.BYTE	$F8,$B8,$03,$FC	; *--
		.BYTE	$F0,$8E,$03,$FC	; *--
_spr_raw_lib0F_17:
		.BYTE	$02		; *--
		.BYTE	$F8,$B8,$03,$FC	; *--
		.BYTE	$E8,$8E,$03,$FC	; *--
_spr_raw_lib0F_18:
		.BYTE	$03		; *--
		.BYTE	$E1,$8E,$03,$FC	; *--
		.BYTE	$F8,$B8,$03,$FC	; *--
		.BYTE	$E8,$8E,$03,$FC	; *--
_spr_raw_lib0F_19:
		.BYTE	$03		; *--
		.BYTE	$D8,$8E,$03,$FC	; *--
		.BYTE	$F8,$B8,$03,$FC	; *--
		.BYTE	$E8,$8E,$03,$FC	; *--
_spr_raw_lib0F_1A:
		.BYTE	$02
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$84,$03,$F8
_spr_raw_lib0F_1B:
		.BYTE	$03
		.BYTE	$F5,$A4,$03,$08
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$84,$03,$F8
_spr_raw_lib0F_1C:
		.BYTE	$04
		.BYTE	$F5,$A4,$03,$10
		.BYTE	$F5,$A4,$03,$08
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$84,$03,$F8
_spr_raw_lib0F_1D:
		.BYTE	$05
		.BYTE	$F5,$A4,$03,$18
		.BYTE	$F5,$A4,$03,$10
		.BYTE	$F5,$A4,$03,$08
		.BYTE	$F5,$94,$03,$00
		.BYTE	$F5,$84,$03,$F8

; =============== S C R I P T ===============================================
_scr26_sword_ninja:
		SDELAY			$01
		NJSR			_nsub_39DA9
		SBCS			_scr26_sword_ninja
		SARG_SET		SARG1,$80
		SJSR			_ssub_39D36
		NBG_HNDL_SET	_nbgsub_39D79
		NJSR			_nsub_62CC4
		NJSR			_nsub_62CD3
		SBCC			_sloc_39D06
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_62CD3
		SBCC			_sloc_39D06
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_62CD3
		SBCC			_sloc_39D06
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_62CD3
		SBCS			_sloc_39D1A
_sloc_39D06:
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SSCRIPT1_SET	_scr_39D26
		SLOOP_BEGIN		$0A
		SDELAY			$04
		NJSR			_nsub_62CD3
		SBCS_BREAK	_sloc_39D1A
		SLOOP_END
_sloc_39D1A:
		SSCRIPT1_OFF
		POS_MOVE_STOP	0

; FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_39D1D:
		NBG_HNDL_RESET
		SJSR			_ssub_39D36
		SDELAY			$3C
		SJMP			_scr26_sword_ninja

; =============== S C R I P T ===============================================
_scr_39D26:
		NJSR			_nsub_6273D
			NARGB		$1E,$40
_sloc_39D2B:
		SPR_IDX_ADD_IMM 7,$04
		SPR_IDX_ADD_IMM 7,$04
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		SJMP			_sloc_39D2B

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_39D36:
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$1E,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SRET

; =============== S C R I P T ===============================================
_scr_39D43:
		NBG_HNDL_SET	_nbgsub_39D8F
		SARG_SET		SARG0,$02
_sloc_39D49:
		SJSR			_ssub_39D63
		NJSR			_nsub_62BFD
		SBCC			_sloc_39D49
		SLOOP_BEGIN		$14
		SJSR			_ssub_39D63
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_39D1D
		SCASE			_sjmp_case_39D6D
		SCASE			_sjmp_case_39D73

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_39D63:
		NJSR			_nsub_6273D
			NARGB		$2A,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S C R I P T ===============================================
_sjmp_case_39D6D:
		SARG_SET		SARG1,$32
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_sjmp_case_39D73:
		SARG_SET		SARG1,$34
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_39D79:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_39D88
		JSR		_cur_thread_reload_param
		.WORD	_scr_39D43
		RTS
loc_39D88:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_39D8F:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_39DA8
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_39DA3
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_39D6D
		RTS
loc_39DA3:
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_39D73
locret_39DA8:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_39DA9:
		LDA		#$06
		JSR		_rand
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
		JSR		sub_61A41
		LDA		#<[byte_39DCD]
		LDY		#>[byte_39DCD]
		JMP		_obj_to_room_bound_box_collision_test
byte_39DCD:
		.BYTE	$04
		.BYTE	$00,$00
		.BYTE	$00,$08
		.BYTE	$08,$00
		.BYTE	$08,$08
_spr_raw_lib0F_1E:
		.BYTE	$04
		.BYTE	$F1,$F8,$00,$00
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$E8,$00,$F8
_spr_raw_lib0F_22:
		.BYTE	$05
		.BYTE	$F0,$F8,$00,$00
		.BYTE	$E8,$FA,$80,$FE
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$E8,$00,$F8
_spr_raw_lib0F_26:
		.BYTE	$04
		.BYTE	$F1,$E8,$00,$F8
		.BYTE	$F1,$F8,$00,$00
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
_spr_raw_lib0F_1F:
		.BYTE	$06
		.BYTE	$F2,$C8,$40,$09
		.BYTE	$F2,$D8,$40,$01
		.BYTE	$00,$C6,$40,$00
		.BYTE	$00,$D6,$40,$F8
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F1,$E4,$40,$00
_spr_raw_lib0F_23:
		.BYTE	$05
		.BYTE	$EC,$FA,$C0,$01
		.BYTE	$00,$E6,$40,$00
		.BYTE	$00,$F6,$40,$F8
		.BYTE	$F0,$F4,$40,$F8
		.BYTE	$F0,$E4,$40,$00
_spr_raw_lib0F_27:
		.BYTE	$06
		.BYTE	$F2,$C8,$40,$09
		.BYTE	$F2,$D8,$40,$01
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F1,$E4,$40,$00
_spr_raw_lib0F_20:
		.BYTE	$05
		.BYTE	$E8,$FA,$80,$FC
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$C4,$00,$F8
		.BYTE	$F1,$D4,$00,$00
_spr_raw_lib0F_24:
		.BYTE	$05
		.BYTE	$0D,$FA,$00,$FC
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$C4,$00,$F8
		.BYTE	$F0,$D4,$00,$00
_spr_raw_lib0F_28:
		.BYTE	$05
		.BYTE	$E8,$FA,$80,$FC
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$C4,$00,$F8
		.BYTE	$F1,$D4,$00,$00
_spr_raw_lib0F_21:
		.BYTE	$06
		.BYTE	$F2,$C8,$00,$EF
		.BYTE	$F2,$D8,$00,$F7
		.BYTE	$00,$C6,$00,$F8
		.BYTE	$00,$D6,$00,$00
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F1,$E4,$00,$F8
_spr_raw_lib0F_25:
		.BYTE	$05
		.BYTE	$EC,$FA,$80,$F7
		.BYTE	$00,$E6,$00,$F8
		.BYTE	$00,$F6,$00,$00
		.BYTE	$F0,$F4,$00,$00
		.BYTE	$F0,$E4,$00,$F8
_spr_raw_lib0F_29:
		.BYTE	$06
		.BYTE	$F2,$C8,$00,$EF
		.BYTE	$F2,$D8,$00,$F7
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F1,$E4,$00,$F8
_spr_raw_lib0F_2A:
		.BYTE	$04
		.BYTE	$00,$F2,$00,$00
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$F0,$D0,$00,$00
		.BYTE	$F0,$C0,$00,$F8
_spr_raw_lib0F_2E:
		.BYTE	$04
		.BYTE	$00,$F2,$00,$02
		.BYTE	$00,$E2,$00,$FA
		.BYTE	$F0,$D0,$00,$02
		.BYTE	$F0,$C0,$00,$FA
_spr_raw_lib0F_2B:
		.BYTE	$04
		.BYTE	$00,$F2,$40,$F8
		.BYTE	$00,$E2,$40,$00
		.BYTE	$F0,$F4,$40,$F8
		.BYTE	$F0,$E4,$40,$00
_spr_raw_lib0F_2F:
		.BYTE	$04
		.BYTE	$00,$F2,$40,$FA
		.BYTE	$00,$E2,$40,$02
		.BYTE	$F0,$F4,$40,$FA
		.BYTE	$F0,$E4,$40,$02
_spr_raw_lib0F_2C:
		.BYTE	$04
		.BYTE	$00,$F2,$00,$00
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$F0,$F0,$00,$00
		.BYTE	$F0,$E0,$00,$F8
_spr_raw_lib0F_30:
		.BYTE	$04
		.BYTE	$00,$F2,$00,$02
		.BYTE	$00,$E2,$00,$FA
		.BYTE	$F0,$F0,$00,$02
		.BYTE	$F0,$E0,$00,$FA
_spr_raw_lib0F_2D:
		.BYTE	$04
		.BYTE	$00,$F2,$00,$00
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$F0,$E4,$00,$F8
		.BYTE	$F0,$F4,$00,$00
_spr_raw_lib0F_31:
		.BYTE	$04
		.BYTE	$00,$F2,$00,$02
		.BYTE	$00,$E2,$00,$FA
		.BYTE	$F0,$E4,$00,$FA
		.BYTE	$F0,$F4,$00,$02
_spr_raw_lib0F_34:
		.BYTE	$04
		.BYTE	$F8,$E4,$40,$07
		.BYTE	$F8,$F4,$40,$FF
		.BYTE	$08,$EC,$40,$07
		.BYTE	$08,$FC,$40,$FF
_spr_raw_lib0F_35:
		.BYTE	$02
		.BYTE	$FF,$CC,$40,$07
		.BYTE	$FF,$DC,$40,$FF
_spr_raw_lib0F_32:
		.BYTE	$04
		.BYTE	$F7,$E4,$00,$F2
		.BYTE	$F7,$F4,$00,$FA
		.BYTE	$07,$EC,$00,$F2
		.BYTE	$07,$FC,$00,$FA
_spr_raw_lib0F_33:
		.BYTE	$02
		.BYTE	$FF,$CC,$00,$F2
		.BYTE	$FF,$DC,$00,$FA

; =============== S C R I P T ===============================================
_scr27_shuriken_ninja:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_3A120
_sloc_39F9F:
		SDELAY			$01
		NJSR			_nsub_39DA9
		SBCS			_sloc_39F9F
		NJSR			_nsub_62CC4
		SJSR			_ssub_39FE1
		NBG_HNDL_SET	_nbgsub_3A00E
		NJSR			_nsub_6273D
			NARGB		$36,$40
		SDELAY			$10
		SARG_ALU		SARG1,_ADC,$F0
		SLOOP_BEGIN		$03
		NJSR			_nsub_new_thread_start
			NARGB		$27
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		SPR_IDX_ADD_IMM 5,$04
		SPR_IDX_ADD_IMM 5,$04
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 5,$FC
		SARG_ALU		SARG1,_ADC,$10
		SLOOP_END
		SARG_ALU		SARG1,_ADC,$F0
		SDELAY			$10

; =============== S C R I P T ===============================================
_sjmp_case_39FD8:
		NBG_HNDL_RESET
		SJSR			_ssub_39FE1
		SDELAY			$3C
		SJMP			_sloc_39F9F

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_39FE1:
		SLOOP_BEGIN		$10
		NJSR			_nsub_6273D
			NARGB		$36,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SRET

; =============== S C R I P T ===============================================
_scr_39FEE:
		NBG_HNDL_SET	_nbgsub_39D8F
		SARG_SET		SARG0,$02
_sloc_39FF4:
		SJSR			_ssub_39D63
		NJSR			_nsub_62BFD
		SBCC			_sloc_39FF4
		SLOOP_BEGIN		$14
		SJSR			_ssub_39D63
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_39FD8
		SCASE			_sjmp_case_39D6D
		SCASE			_sjmp_case_39D73

; =============== S U B R O U T I N E =======================================
_nbgsub_3A00E:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3A01D
		JSR		_cur_thread_reload_param
		.WORD	_scr_39FEE
		RTS
loc_3A01D:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test
_spr_raw_lib0F_36:
		.BYTE	$05
		.BYTE	$F1,$F8,$00,$00
		.BYTE	$F1,$C0,$00,$F8
		.BYTE	$EE,$EA,$00,$FC
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
_spr_raw_lib0F_3A:
		.BYTE	$05
		.BYTE	$E9,$EA,$40,$FF
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$F8,$00,$00
		.BYTE	$F0,$C0,$00,$F8
_spr_raw_lib0F_3E:
		.BYTE	$05
		.BYTE	$F1,$F8,$00,$00
		.BYTE	$F1,$C0,$00,$F8
		.BYTE	$EE,$EA,$00,$FC
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
_spr_raw_lib0F_37:
		.BYTE	$05
		.BYTE	$F7,$EA,$00,$FD
		.BYTE	$00,$C6,$40,$00
		.BYTE	$00,$D6,$40,$F8
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F1,$E4,$40,$00
_spr_raw_lib0F_3B:
		.BYTE	$05
		.BYTE	$F5,$DA,$40,$02
		.BYTE	$00,$E6,$40,$00
		.BYTE	$00,$F6,$40,$F8
		.BYTE	$F0,$F4,$40,$F8
		.BYTE	$F0,$E4,$40,$00
_spr_raw_lib0F_3F:
		.BYTE	$05
		.BYTE	$F7,$EA,$40,$FD
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$00,$D2,$00,$00
		.BYTE	$F1,$F4,$40,$F8
		.BYTE	$F1,$E4,$40,$00
_spr_raw_lib0F_38:
		.BYTE	$05
		.BYTE	$F4,$DA,$80,$FC
		.BYTE	$00,$D2,$00,$00
		.BYTE	$00,$C2,$00,$F8
		.BYTE	$F1,$D4,$00,$00
		.BYTE	$F1,$E0,$00,$F8
_spr_raw_lib0F_3C:
		.BYTE	$05
		.BYTE	$F5,$EA,$80,$01
		.BYTE	$00,$E2,$00,$F8
		.BYTE	$00,$F2,$00,$00
		.BYTE	$F0,$D4,$00,$00
		.BYTE	$F0,$E0,$00,$F8
_spr_raw_lib0F_40:
		.BYTE	$05
		.BYTE	$F4,$DA,$80,$FC
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$D4,$00,$00
		.BYTE	$F1,$E0,$00,$F8
_spr_raw_lib0F_39:
		.BYTE	$05
		.BYTE	$F7,$EA,$40,$FB
		.BYTE	$00,$C6,$00,$F8
		.BYTE	$00,$D6,$00,$00
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F1,$E4,$00,$F8
_spr_raw_lib0F_3D:
		.BYTE	$05
		.BYTE	$F5,$DA,$00,$F6
		.BYTE	$00,$E6,$00,$F8
		.BYTE	$00,$F6,$00,$00
		.BYTE	$F0,$F4,$00,$00
		.BYTE	$F0,$E4,$00,$F8
_spr_raw_lib0F_41:
		.BYTE	$05
		.BYTE	$F7,$EA,$00,$FB
		.BYTE	$00,$C2,$40,$00
		.BYTE	$00,$D2,$40,$F8
		.BYTE	$F1,$F4,$00,$00
		.BYTE	$F1,$E4,$00,$F8

; =============== S C R I P T ===============================================
_sjmp_case_3A120:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_3A134
		NJSR			_nsub_628D1
			NARGB		$00,$02
		SLOOP_BEGIN		$04
		SPR_IDX_SET		2,$42
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_3A134:
		LDX		#$06
		LDY		#$07
		JSR		_player_to_obj_collision_test
		JSR		_cur_obj_out_of_screen_test
		JMP		_obj_to_room_macro_collision_test_raw
_spr_raw_lib0F_42:
		.BYTE	$01
		.BYTE	$FD,$CA,$00,$FD
_spr_raw_lib0F_43:
		.BYTE	$01
		.BYTE	$FD,$CA,$40,$FD
_spr_raw_lib0F_44:
		.BYTE	$01
		.BYTE	$F5,$CA,$C0,$FD
_spr_raw_lib0F_45:
		.BYTE	$01
		.BYTE	$F5,$CA,$80,$FD

; =============== S C R I P T ===============================================
_scr28_pink_goo:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$E8
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3A15C:
		NBG_HNDL_SET	_nbgsub_3A212
_sloc_3A15F:
		SLOOP_BEGIN		$02
		SPR_IDX_SET		0,$E8
		SDELAY			$10
		SPR_IDX_INC		4
		SPR_IDX_DEC		5
		SPR_IDX_ADD_IMM 4,$02
		SLOOP_END
		SPR_IDX_SET		5,$E8
		SPR_IDX_INC		4
		SPR_IDX_DEC		5
		SPR_IDX_ADD_IMM 4,$02
		NJSR			_nsub_62CC4
		NJSR			_nsub_3A242
		SBCC			_sloc_3A197
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_3A242
		SBCC			_sloc_3A197
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_3A242
		SBCC			_sloc_3A197
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_3A242
		SBCS			_sloc_3A15F
_sloc_3A197:
		NBG_HNDL_SET	_nbgsub_3A221
		SPR_IDX_SET		0,$EB
		NJSR			_nsub_604CD
		SJSR_SW	$04
		SCASE			_sjsr_case_3A1B0
		SCASE			_sjsr_case_3A1BD
		SCASE			_sjsr_case_3A1CA
		SCASE			_sjsr_case_3A1D7
		POS_MOVE_STOP	0
		NBG_HNDL_SET	_nbgsub_3A212
		SJMP			_sloc_3A15F
_sjsr_case_3A1B0:
		POS_Y_DELTA_ADD 0,$80,$FE
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_Y_DELTA_ADD 2,$40,$00
		POS_Y_DELTA_ADD 6,$00,$04
		SRET
_sjsr_case_3A1BD:
		POS_X_DELTA_ADD 0,$80,$01
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_X_DELTA_ADD 2,$C0,$FF
		POS_Y_DELTA_ADD 6,$00,$04
		SRET
_sjsr_case_3A1CA:
		POS_Y_DELTA_ADD 0,$80,$01
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_Y_DELTA_ADD 2,$C0,$FF
		POS_Y_DELTA_ADD 6,$00,$04
		SRET
_sjsr_case_3A1D7:
		POS_X_DELTA_ADD 0,$80,$FE
		POS_Y_DELTA_ADD 4,$00,$FE
		POS_X_DELTA_ADD 2,$40,$00
		POS_Y_DELTA_ADD 6,$00,$04
		SRET

; =============== S C R I P T ===============================================
_scr_3A1E4:
		NBG_HNDL_SET	_nbgsub_3A228
		SARG_SET		SARG0,$02
_sloc_3A1EA:
		SPR_IDX_SET		1,$E8
		SPR_IDX_SET		1,$46
		NJSR			_nsub_62BFD
		SBCC			_sloc_3A1EA
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$E8
		SPR_IDX_SET		1,$46
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3A15C
		SCASE			_sjmp_case_3A206
		SCASE			_sjmp_case_3A20C

; =============== S C R I P T ===============================================
_sjmp_case_3A206:
		SARG_SET		SARG1,$47
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_sjmp_case_3A20C:
		SARG_SET		SARG1,$49
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3A212:
		LDX		#$0A
		LDY		#$0A
		JSR		sub_61DD6
		BCC		_nbgsub_3A221
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A1E4
		RTS

; =============== S U B R O U T I N E =======================================
_nbgsub_3A221:
		LDX		#$09
		LDY		#$0A
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3A228:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3A241
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_3A23C
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_3A206
		RTS
loc_3A23C:
		JSR		_cur_thread_reload_param
		.WORD	_sjmp_case_3A20C
locret_3A241:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_3A242:
		JSR		_nsub_604CD
		TAX
		LDA		off_3A24F,X
		LDY		off_3A253,X
		JMP		_obj_to_room_bound_box_collision_test
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
_spr_res_lib0F_28:
		.BYTE	$01
		.WORD	_spr_res_lib0F_28_A
_spr_res_lib0F_29:
		.BYTE	$01
		.WORD	_spr_res_lib0F_29_A
_spr_res_lib0F_2A:
		.BYTE	$01
		.WORD	_spr_res_lib0F_2A_A
_spr_res_lib0F_2B:
		.BYTE	$01
		.WORD	_spr_res_lib0F_2B_A
_spr_res_lib0F_28_A:
		.BYTE	$02
		.BYTE	$F8,$CE,$03,$00
		.BYTE	$F8,$BE,$03,$F8
_spr_res_lib0F_29_A:
		.BYTE	$02
		.BYTE	$F8,$EE,$03,$00
		.BYTE	$F8,$DE,$03,$F8
_spr_res_lib0F_2A_A:
		.BYTE	$02
		.BYTE	$F8,$EE,$43,$F8
		.BYTE	$F8,$DE,$43,$00
_spr_res_lib0F_2B_A:
		.BYTE	$02
		.BYTE	$F8,$9E,$03,$F8
		.BYTE	$F8,$AE,$03,$00
_spr_raw_lib0F_46:
		.BYTE	$02
		.BYTE	$F8,$CE,$03,$02
		.BYTE	$F8,$BE,$03,$FA
_spr_raw_lib0F_49:
		.BYTE	$02
		.BYTE	$FF,$BE,$43,$08
		.BYTE	$FF,$6E,$43,$00
_spr_raw_lib0F_4A:
		.BYTE	$01
		.BYTE	$FF,$FE,$43,$00
_spr_raw_lib0F_47:
		.BYTE	$02
		.BYTE	$FF,$BE,$03,$F1
		.BYTE	$FF,$6E,$03,$F9
_spr_raw_lib0F_48:
		.BYTE	$01
		.BYTE	$FF,$FE,$03,$F9

; =============== S C R I P T ===============================================
_scr29_sewer_worm:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_3A515
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$4B
		SPR_IDX_SET		1,$FF
		SLOOP_END
_sloc_3A2E0:
		NBG_HNDL_SET	_nbgsub_3A39E
		NJSR			_nsub_62CE8
_sloc_3A2E6:
		SDELAY			$01
		NJSR			_nsub_3A3FE
		SBCS			_sloc_3A2E6
		NJSR			_nsub_628D1
			NARGB		$40,$00
		SPR_IDX_SET		0,$4B
		SDELAY			$22
		SPR_IDX_INC		5
		SPR_IDX_INC		5
		SPR_IDX_ADD_IMM 5,$FE
		SPR_IDX_INC		5
		SPR_IDX_DEC		5
		SPR_IDX_ADD_IMM 5,$02
		POS_MOVE_STOP	0
		NJSR			_nsub_62879
			NARGB		$04
		SBCC			_sloc_3A2E6
		SPR_IDX_SET		0,$4B
		SDELAY			$28
		SPR_IDX_SET		6,$53
		NBG_HNDL_SET	_nbgsub_3A3CE
		POS_Y_MOVE		0,$F8
		SLOOP_BEGIN		$04
		NJSR			_nsub_new_thread_start
			NARGB		$29
			NARGB		$00,$F8
			NARGB		$01
			NARGB		$00
		SLOOP_BEGIN		$02
		SPR_IDX_SET		6,$54
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SLOOP_END
		POS_Y_MOVE		0,$08
		SPR_IDX_SET		0,$53
		SJMP			_sloc_3A2E0

; =============== S C R I P T ===============================================
_sjmp_case_3A32B:
		NBG_HNDL_SET	_nbgsub_3A39E
		NJSR			_nsub_628D1
			NARGB		$40,$00
		SPR_IDX_SET		0,$4B
_sloc_3A335:
		NJSR			_nsub_3A449
		SBCS			_sloc_3A2E6
		SDELAY			$01
		SJMP			_sloc_3A335

; =============== S C R I P T ===============================================
_scr_3A340:
		NBG_HNDL_SET	_nbgsub_3A3B4
		SARG_SET		SARG0,$02
_sloc_3A346:
		SPR_IDX_SET		1,$4B
		SPR_IDX_SET		1,$4E
		NJSR			_nsub_62BFD
		SBCC			_sloc_3A346
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$4B
		SPR_IDX_SET		1,$4E
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3A32B
		SCASE			_scr_3A386
		SCASE			_scr_3A38C

; =============== S C R I P T ===============================================
_scr_3A362:
		NBG_HNDL_SET	_nbgsub_3A3E4
		SARG_SET		SARG0,$02
_sloc_3A368:
		SPR_IDX_SET		1,$54
		SPR_IDX_SET		1,$57
		NJSR			_nsub_62BFD
		SBCC			_sloc_3A368
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$54
		SPR_IDX_SET		1,$57
		SLOOP_END
		POS_Y_MOVE		0,$08
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3A32B
		SCASE			_scr_3A392
		SCASE			_scr_3A398

; =============== S C R I P T ===============================================
_scr_3A386:
		SARG_SET		SARG1,$4F
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3A38C:
		SARG_SET		SARG1,$51
		SJMP			_sloc_62E02

; =============== S C R I P T ===============================================
_scr_3A392:
		SARG_SET		SARG1,$58
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3A398:
		SARG_SET		SARG1,$5A
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3A39E:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		loc_3A3AD
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A340
		RTS
loc_3A3AD:
		LDX		#$0B
		LDY		#$09
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3A3B4:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3A3CD
		LSR
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3A3C8
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A386
		RTS
loc_3A3C8:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A38C
locret_3A3CD:
		RTS

; =============== S U B R O U T I N E =======================================
_nbgsub_3A3CE:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3A3DD
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A362
		RTS
loc_3A3DD:
		LDX		#$0B
		LDY		#$10
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3A3E4:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3A3FD
		LSR
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3A3F8
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A392
		RTS
loc_3A3F8:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A398
locret_3A3FD:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_3A3FE:
		LDA		#$04
		JSR		_rand
		LDX		_scr_cur_trd_idx
		TAY
		LSR
		ROR
		ROR
		STA		_scr_trds_args1,X
		LDA		_scr_trds_x_pos_lo,X
		CLC
		ADC		byte_3A439,Y
		PHA
		LDA		_scr_trds_x_pos_hi,X
		ADC		byte_3A43D,Y
		STA		_tmp_var0
		LDA		_scr_trds_y_pos_lo,X
		CLC
		ADC		byte_3A441,Y
		PHA
		LDA		_scr_trds_y_pos_hi,X
		ADC		byte_3A445,Y
		STA		_tmp_var1
		PLA
		TAY
		PLA
		TAX
		JSR		_far_lvl_room_ofs_calc
		BEQ		loc_3A437
		CMP		#$0D
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

; =============== S U B R O U T I N E =======================================
_nsub_3A449:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,X
		AND		#$0F
		CMP		#$08
		BEQ		locret_3A45C
		LDA		_scr_trds_y_pos_lo,X ; *--
		AND		#$0F		; *--
		CMP		#$08		; *--
		BEQ		locret_3A45C	; *--
		CLC				; *--
locret_3A45C:
		RTS
_spr_raw_lib0F_4B:
		.BYTE	$02
		.BYTE	$F4,$E0,$43,$00
		.BYTE	$F4,$E0,$03,$F8
_spr_raw_lib0F_4C:
		.BYTE	$02
		.BYTE	$F4,$E2,$03,$F8
		.BYTE	$F4,$E2,$43,$00
_spr_raw_lib0F_4D:
		.BYTE	$02
		.BYTE	$F4,$E4,$03,$F8
		.BYTE	$F4,$E4,$43,$00
_spr_raw_lib0F_53:
		.BYTE	$02
		.BYTE	$F4,$F0,$03,$F8
		.BYTE	$F4,$F0,$43,$00
_spr_raw_lib0F_54:
		.BYTE	$04
		.BYTE	$04,$F4,$03,$F8
		.BYTE	$F4,$F2,$03,$F8
		.BYTE	$F4,$F2,$43,$00
		.BYTE	$04,$F4,$43,$00
_spr_raw_lib0F_55:
		.BYTE	$04
		.BYTE	$F4,$E6,$03,$F8
		.BYTE	$04,$E8,$03,$F8
		.BYTE	$F4,$E6,$43,$00
		.BYTE	$04,$E8,$43,$00
_spr_raw_lib0F_56:
		.BYTE	$04
		.BYTE	$04,$F8,$03,$F8
		.BYTE	$F4,$F6,$03,$F8
		.BYTE	$F4,$F6,$43,$00
		.BYTE	$04,$F8,$43,$00
_spr_raw_lib0F_4E:
		.BYTE	$02
		.BYTE	$F4,$E0,$43,$02
		.BYTE	$F4,$E0,$03,$FA
_spr_raw_lib0F_57:
		.BYTE	$04
		.BYTE	$04,$F4,$03,$FA
		.BYTE	$F4,$F2,$03,$FA
		.BYTE	$F4,$F2,$43,$02
		.BYTE	$04,$F4,$43,$02
_spr_raw_lib0F_5A:
		.BYTE	$04
		.BYTE	$F6,$F2,$03,$FF
		.BYTE	$F6,$F2,$43,$07
		.BYTE	$06,$EA,$43,$07
		.BYTE	$06,$FA,$43,$FF
_spr_raw_lib0F_5B:
		.BYTE	$02
		.BYTE	$FD,$EC,$43,$09
		.BYTE	$FD,$FC,$43,$01
_spr_raw_lib0F_58:
		.BYTE	$04
		.BYTE	$F5,$F2,$43,$FB
		.BYTE	$F5,$F2,$03,$F3
		.BYTE	$05,$EA,$03,$F3
		.BYTE	$05,$FA,$03,$FB
_spr_raw_lib0F_59:
		.BYTE	$02
		.BYTE	$FE,$EC,$03,$F1
		.BYTE	$FE,$FC,$03,$F9
_spr_raw_lib0F_51:
		.BYTE	$02
		.BYTE	$02,$E4,$C3,$00
		.BYTE	$02,$E4,$83,$F8
_spr_raw_lib0F_50:
		.BYTE	$01
		.BYTE	$05,$CE,$03,$FA
_spr_raw_lib0F_52:
		.BYTE	$01
		.BYTE	$05,$CE,$43,$FF

; =============== S C R I P T ===============================================
_sjmp_case_3A515:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_3A531
		NJSR			_nsub_3A53B
		NJSR			_nsub_628D1
			NARGB		$00,$01
		POS_Y_DELTA_ADD 0,$00,$FE
		SPR_IDX_SET		0,$5C
		SLOOP_BEGIN		$3C
		POS_Y_DELTA_ADD 1,$10,$00
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_INC		4
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_3A531:
		LDX		#$06
		LDY		#$07
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E =======================================
_nsub_3A53B:
		LDA		#$00
		JSR		_rand
		AND		#$E0
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS
_spr_raw_lib0F_5C:
		.BYTE	$01
		.BYTE	$FC,$FE,$01,$FD
_spr_raw_lib0F_5D:
		.BYTE	$01
		.BYTE	$FC,$EE,$01,$FC

; =============== S C R I P T ===============================================
_scr2D_rotator:
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$62
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3A558:
		NBG_HNDL_SET	_nbgsub_3A5E3
_sloc_3A55B:
		SPR_IDX_SET		5,$5E
		SLOOP_BEGIN		$07
		SPR_IDX_INC		5
		SLOOP_END
		SPR_IDX_SET		3,$5E
		SLOOP_BEGIN		$07
		SPR_IDX_INC		3
		SLOOP_END
		SLOOP_BEGIN		$03
		SPR_IDX_SET		1,$5E
		SLOOP_BEGIN		$07
		SPR_IDX_INC		1
		SLOOP_END
		SLOOP_END
		NJSR			_nsub_62CC4
		NJSR			_nsub_62CD3
		SBCC			_sloc_3A597
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_62CD3
		SBCC			_sloc_3A597
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_62CD3
		SBCC			_sloc_3A597
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_62CD3
		SBCS			_sloc_3A5AB
_sloc_3A597:
		NJSR			_nsub_628D1
			NARGB		$00,$01
		SLOOP_BEGIN		$0A
		NJSR			_nsub_62CD3
		SBCS_BREAK	_sloc_3A5AB
		SPR_IDX_SET		1,$5E
		SLOOP_BEGIN		$07
		SPR_IDX_INC		1
		SLOOP_END
		SLOOP_END
_sloc_3A5AB:
		POS_MOVE_STOP	0
		SPR_IDX_SET		3,$5E
		SLOOP_BEGIN		$07
		SPR_IDX_INC		3
		SLOOP_END
		SJMP			_sloc_3A55B

; =============== S C R I P T ===============================================
_scr_3A5B5:
		NBG_HNDL_SET	_nbgsub_3A5F9
		SARG_SET		SARG0,$02
_sloc_3A5BB:
		SPR_IDX_SET		1,$66
		SPR_IDX_SET		1,$62
		NJSR			_nsub_62BFD
		SBCC			_sloc_3A5BB
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$66
		SPR_IDX_SET		1,$62
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3A558
		SCASE			_scr_3A5D7
		SCASE			_scr_3A5DD

; =============== S C R I P T ===============================================
_scr_3A5D7:
		SARG_SET		SARG1,$67
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3A5DD:
		SARG_SET		SARG1,$69
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3A5E3:
		LDX		#$04
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3A5F2
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A5B5
		RTS
loc_3A5F2:
		LDX		#$08
		LDY		#$10
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3A5F9:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3A612
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_3A60D
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A5D7
		RTS
loc_3A60D:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A5DD
locret_3A612:
		RTS
_spr_raw_lib0F_5E:
		.BYTE	$06
		.BYTE	$F4,$D0,$43,$F4
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$D2,$03,$04
		.BYTE	$F4,$D0,$03,$04
		.BYTE	$04,$C2,$03,$FC
		.BYTE	$F4,$DE,$03,$FC
_spr_raw_lib0F_5F:
		.BYTE	$06
		.BYTE	$F4,$CC,$03,$F4
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$DA,$03,$04
		.BYTE	$F4,$D8,$03,$04
		.BYTE	$04,$CA,$03,$FC
		.BYTE	$F4,$DC,$03,$FC
_spr_raw_lib0F_60:
		.BYTE	$06
		.BYTE	$F4,$C6,$43,$F4
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$D2,$03,$04
		.BYTE	$F4,$C4,$43,$04
		.BYTE	$04,$D6,$03,$FC
		.BYTE	$F4,$D4,$43,$FC
_spr_raw_lib0F_61:
		.BYTE	$06
		.BYTE	$04,$D2,$43,$00
		.BYTE	$F4,$CC,$43,$04
		.BYTE	$04,$DA,$43,$F4
		.BYTE	$04,$CA,$43,$FC
		.BYTE	$F4,$D8,$43,$F4
		.BYTE	$F4,$C8,$43,$FC
_spr_raw_lib0F_62:
		.BYTE	$06
		.BYTE	$F4,$D0,$43,$F4
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$D2,$03,$04
		.BYTE	$F4,$D0,$03,$04
		.BYTE	$04,$C2,$03,$FC
		.BYTE	$F4,$C0,$03,$FC
_spr_raw_lib0F_63:
		.BYTE	$06
		.BYTE	$04,$D2,$03,$FB
		.BYTE	$F4,$CC,$03,$F4
		.BYTE	$04,$DA,$03,$04
		.BYTE	$04,$CA,$03,$FC
		.BYTE	$F4,$D8,$03,$04
		.BYTE	$F4,$C8,$03,$FC
_spr_raw_lib0F_64:
		.BYTE	$06
		.BYTE	$F4,$C4,$03,$F4
		.BYTE	$04,$D2,$43,$F4
		.BYTE	$04,$D2,$03,$04
		.BYTE	$F4,$C6,$03,$04
		.BYTE	$04,$D6,$03,$FC
		.BYTE	$F4,$D4,$03,$FC
_spr_raw_lib0F_65:
		.BYTE	$06
		.BYTE	$F4,$D8,$43,$F4
		.BYTE	$04,$DA,$43,$F4
		.BYTE	$04,$D2,$03,$04
		.BYTE	$F4,$CC,$43,$04
		.BYTE	$04,$CA,$43,$FC
		.BYTE	$F4,$DC,$43,$FC
_spr_raw_lib0F_66:
		.BYTE	$06
		.BYTE	$F4,$D0,$43,$F6
		.BYTE	$04,$D2,$43,$F6
		.BYTE	$04,$D2,$03,$06
		.BYTE	$F4,$D0,$03,$06
		.BYTE	$04,$C2,$03,$FE
		.BYTE	$F4,$C0,$03,$FE
_spr_raw_lib0F_69:
		.BYTE	$04
		.BYTE	$F7,$C6,$03,$08
		.BYTE	$F7,$C6,$43,$F8
		.BYTE	$07,$CE,$43,$00
		.BYTE	$F7,$C0,$43,$00
_spr_raw_lib0F_6A:
		.BYTE	$01
		.BYTE	$FE,$BE,$43,$FF
_spr_raw_lib0F_67:
		.BYTE	$04
		.BYTE	$F7,$C6,$43,$F2
		.BYTE	$F7,$C6,$03,$02
		.BYTE	$07,$CE,$03,$FA
		.BYTE	$F7,$C0,$03,$FA
_spr_raw_lib0F_68:
		.BYTE	$01
		.BYTE	$FE,$BE,$03,$FA

; =============== S C R I P T ===============================================
_scr0F_candle:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_3A739
		NJSR			_nsub_new_thread_start
			NARGB		$0F
			NARGB		$00,$B0
			NARGB		$01
			NARGB		$00
		NJSR			_nsub_new_thread_start
			NARGB		$0F
			NARGB		$00,$50
			NARGB		$01
			NARGB		$00

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3A739:
		SDELAY			$01
		NJSR			_nsub_3A74D
		SBCC			_sjmp_case_3A739
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$23
_sloc_3A745:
		SPR_IDX_SET		3,$6B
		SPR_IDX_INC		3
		SPR_IDX_SET		3,$FF
		SJMP			_sloc_3A745

; =============== S U B R O U T I N E =======================================
_nsub_3A74D:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_y_pos_hi+2
		CMP		_scr_trds_y_pos_hi,X
		BCC		loc_3A761
		BNE		loc_3A763
		LDA		_scr_trds_y_pos_lo+2
		CMP		_scr_trds_y_pos_lo,X
		BCC		loc_3A761
		BNE		loc_3A763
loc_3A761:
		SEC
		RTS
loc_3A763:
		CLC
		RTS
_spr_raw_lib0F_6B:
		.BYTE	$02
		.BYTE	$F8,$C9,$01,$D8
		.BYTE	$F8,$C9,$01,$20
_spr_raw_lib0F_6C:
		.BYTE	$02
		.BYTE	$F8,$C7,$01,$D8
		.BYTE	$F8,$C7,$01,$20

; =============== S C R I P T ===============================================
_scr10_train_semaphores:
		SPR_IDX_SET		0,$6D
		POS_X_SET		0,$38,$05
		SJSR			_ssub_3A788
		POS_X_SET		0,$C8,$05
		SJSR			_ssub_3A788
		SJMP			_scr10_train_semaphores

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3A788:
		NJSR			_nsub_3A797
		POS_Y_DELTA_SET 0,$75,$FD
_sloc_3A78E:
		SDELAY			$01
		NJSR			_nsub_3A7A8
		SBCC			_sloc_3A78E
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_3A797:
		LDX		_scr_cur_trd_idx
		LDA		_ppu_scroll_pos_y
		CLC
		ADC		#$E8
		STA		_scr_trds_y_pos_lo,X
		LDA		_ppu_scroll_pos_y+1
		ADC		#$00
		STA		_scr_trds_y_pos_hi,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_3A7A8:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_y_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_y
		STA		_tmp0
		LDA		_scr_trds_y_pos_hi,X
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
_spr_raw_lib0F_6D:
		.BYTE	$02
		.BYTE	$00,$05,$00,$FC
		.BYTE	$F0,$03,$00,$FC
_spr_raw_lib0F:
		.WORD	_spr_raw_lib1A_00
		.WORD	_spr_raw_lib1A_01
		.WORD	_spr_raw_lib1A_02
		.WORD	_spr_raw_lib1A_03
		.WORD	_spr_raw_lib0F_04
		.WORD	_spr_raw_lib0F_05
		.WORD	_spr_raw_lib0F_06
		.WORD	_spr_raw_lib0F_07
		.WORD	_spr_raw_lib0F_08
		.WORD	_spr_raw_lib0F_09
		.WORD	_spr_raw_lib0F_0A
		.WORD	_spr_raw_lib0F_0B
		.WORD	_spr_raw_lib0F_0C
		.WORD	_spr_raw_lib0F_0D
		.WORD	_spr_raw_lib0F_0E
		.WORD	_spr_raw_lib0F_0F
		.WORD	_spr_raw_lib0F_10
		.WORD	_spr_raw_lib0F_11
		.WORD	_spr_raw_lib0F_12
		.WORD	_spr_raw_lib0F_13
		.WORD	_spr_raw_lib0F_14
		.WORD	_spr_raw_lib0F_15	; *--
		.WORD	_spr_raw_lib0F_16	; *--
		.WORD	_spr_raw_lib0F_17	; *--
		.WORD	_spr_raw_lib0F_18	; *--
		.WORD	_spr_raw_lib0F_19	; *--
		.WORD	_spr_raw_lib0F_1A
		.WORD	_spr_raw_lib0F_1B
		.WORD	_spr_raw_lib0F_1C
		.WORD	_spr_raw_lib0F_1D
		.WORD	_spr_raw_lib0F_1E
		.WORD	_spr_raw_lib0F_1F
		.WORD	_spr_raw_lib0F_20
		.WORD	_spr_raw_lib0F_21
		.WORD	_spr_raw_lib0F_22
		.WORD	_spr_raw_lib0F_23
off_3A813:
		.WORD	_spr_raw_lib0F_24
		.WORD	_spr_raw_lib0F_25
off_3A817:
		.WORD	_spr_raw_lib0F_26
		.WORD	_spr_raw_lib0F_27
		.WORD	_spr_raw_lib0F_28
		.WORD	_spr_raw_lib0F_29
		.WORD	_spr_raw_lib0F_2A
		.WORD	_spr_raw_lib0F_2B
		.WORD	_spr_raw_lib0F_2C
		.WORD	_spr_raw_lib0F_2D
		.WORD	_spr_raw_lib0F_2E
		.WORD	_spr_raw_lib0F_2F
off_3A82B:
		.WORD	_spr_raw_lib0F_30
		.WORD	_spr_raw_lib0F_31
		.WORD	_spr_raw_lib0F_32
		.WORD	_spr_raw_lib0F_33
		.WORD	_spr_raw_lib0F_34
		.WORD	_spr_raw_lib0F_35
		.WORD	_spr_raw_lib0F_36
		.WORD	_spr_raw_lib0F_37
		.WORD	_spr_raw_lib0F_38
		.WORD	_spr_raw_lib0F_39
		.WORD	_spr_raw_lib0F_3A
		.WORD	_spr_raw_lib0F_3B
		.WORD	_spr_raw_lib0F_3C
		.WORD	_spr_raw_lib0F_3D
		.WORD	_spr_raw_lib0F_3E
		.WORD	_spr_raw_lib0F_3F
		.WORD	_spr_raw_lib0F_40
		.WORD	_spr_raw_lib0F_41
		.WORD	_spr_raw_lib0F_42
		.WORD	_spr_raw_lib0F_43
		.WORD	_spr_raw_lib0F_44
		.WORD	_spr_raw_lib0F_45
		.WORD	_spr_raw_lib0F_46
		.WORD	_spr_raw_lib0F_47
		.WORD	_spr_raw_lib0F_48
		.WORD	_spr_raw_lib0F_49
		.WORD	_spr_raw_lib0F_4A
		.WORD	_spr_raw_lib0F_4B
		.WORD	_spr_raw_lib0F_4C
		.WORD	_spr_raw_lib0F_4D
		.WORD	_spr_raw_lib0F_4E
		.WORD	_spr_raw_lib0F_51
		.WORD	_spr_raw_lib0F_50
		.WORD	_spr_raw_lib0F_51
		.WORD	_spr_raw_lib0F_52
		.WORD	_spr_raw_lib0F_53
		.WORD	_spr_raw_lib0F_54
		.WORD	_spr_raw_lib0F_55
		.WORD	_spr_raw_lib0F_56
		.WORD	_spr_raw_lib0F_57
		.WORD	_spr_raw_lib0F_58
		.WORD	_spr_raw_lib0F_59
		.WORD	_spr_raw_lib0F_5A
		.WORD	_spr_raw_lib0F_5B
		.WORD	_spr_raw_lib0F_5C
		.WORD	_spr_raw_lib0F_5D
		.WORD	_spr_raw_lib0F_5E
		.WORD	_spr_raw_lib0F_5F
		.WORD	_spr_raw_lib0F_60
		.WORD	_spr_raw_lib0F_61
		.WORD	_spr_raw_lib0F_62
		.WORD	_spr_raw_lib0F_63
		.WORD	_spr_raw_lib0F_64
		.WORD	_spr_raw_lib0F_65
		.WORD	_spr_raw_lib0F_66
		.WORD	_spr_raw_lib0F_67
		.WORD	_spr_raw_lib0F_68
		.WORD	_spr_raw_lib0F_69
		.WORD	_spr_raw_lib0F_6A
		.WORD	_spr_raw_lib0F_6B
		.WORD	_spr_raw_lib0F_6C
		.WORD	_spr_raw_lib0F_6D
_spr_res_lib0F:
		.WORD	_spr_res_lib0F_00
		.WORD	_spr_res_lib0F_01
		.WORD	_spr_res_lib0F_02
		.WORD	_spr_res_lib0F_03
		.WORD	_spr_res_lib0F_04
		.WORD	_spr_res_lib0F_05
		.WORD	_spr_res_lib0F_06
		.WORD	_spr_res_lib0F_07
		.WORD	_spr_res_lib0F_08
		.WORD	_spr_res_lib0F_09
		.WORD	_spr_res_lib0F_0A
		.WORD	_spr_res_lib0F_0B
		.WORD	_spr_res_lib0F_0C
		.WORD	_spr_res_lib0F_0D
		.WORD	_spr_res_lib0F_0E
		.WORD	_spr_res_lib0F_0F
		.WORD	_spr_res_lib0F_10
		.WORD	_spr_res_lib0F_11
		.WORD	_spr_res_lib0F_12
		.WORD	_spr_res_lib0F_13
		.WORD	_spr_res_lib0F_14
		.WORD	_spr_res_lib0F_15
		.WORD	_spr_res_lib0F_16
		.WORD	_spr_res_lib0F_17
		.WORD	_spr_res_lib0F_18
		.WORD	_spr_res_lib0F_19
		.WORD	_spr_res_lib0F_1A	; *--
		.WORD	_spr_res_lib0F_1B
		.WORD	_spr_res_lib0F_1C
		.WORD	_spr_res_lib0F_1D
		.WORD	_spr_res_lib0F_1E	; *--
		.WORD	_spr_res_lib0F_1F
		.WORD	_spr_res_lib0F_20
		.WORD	_spr_res_lib0F_21
		.WORD	_spr_res_lib0F_22	; *--
		.WORD	_spr_res_lib0F_23
		.WORD	_spr_res_lib0F_24
		.WORD	_spr_res_lib0F_25
		.WORD	_spr_res_lib0F_26
		.WORD	_spr_res_lib0F_27
		.WORD	_spr_res_lib0F_28
		.WORD	_spr_res_lib0F_29
		.WORD	_spr_res_lib0F_2A
		.WORD	_spr_res_lib0F_2B

; =============== S C R I P T ===============================================
_scr17_runner:
		SARG_SET		SARG1,$80
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$0C
		SPR_IDX_SET		1,$FF
		SLOOP_END

; =============== S C R I P T ===============================================
_scr_3A909:
		POS_MOVE_STOP	0
		NBG_HNDL_SET	_nbgsub_3A9B3
		NJSR			_nsub_604CD
		SJMP_SW			$03
		SCASE			_sjmp_case_3A930
		SCASE			_sjmp_case_3A948
		SCASE			_sjmp_case_3A960
_sloc_3A918:
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
		SJMP			_sloc_3A918

; =============== S C R I P T ===============================================
_sjmp_case_3A930:
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
		SJMP			_sjmp_case_3A930

; =============== S C R I P T ===============================================
_sjmp_case_3A948:
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
		SJMP			_sjmp_case_3A948

; =============== S C R I P T ===============================================
_sjmp_case_3A960:
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
		SJMP			_sjmp_case_3A960

; =============== S C R I P T ===============================================
_scr_3A978:
		NBG_HNDL_SET	_nbgsub_3AA31
		SARG_SET		SARG0,$02
_sloc_3A97E:
		SJSR			_ssub_3A998
		NJSR			_nsub_62BFD
		SBCC			_sloc_3A97E
		SLOOP_BEGIN		$14
		SJSR			_ssub_3A998
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_scr_3A909
		SCASE			_scr_3A9A7
		SCASE			_scr_3A9AD

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3A998:
		NJSR			_nsub_6273D
			NARGB		$04,$10
		SDELAY			$01
		NJSR			_nsub_6273D
			NARGB		$14,$40
		SDELAY			$01
		SRET

; =============== S C R I P T ===============================================
_scr_3A9A7:
		SARG_SET		SARG1,$18
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3A9AD:
		SARG_SET		SARG1,$1A
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3A9B3:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3A9C2
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A978
		RTS
loc_3A9C2:
		LDX		#$0A
		LDY		#$0E
		JSR		_player_to_obj_collision_test
		JSR		_nsub_604CD
		TAX
		LDA		off_3AA15,X
		LDY		off_3AA19,X
		JSR		_obj_to_room_bound_box_collision_test
		BCC		locret_3AA14
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		CLC
		ADC		#$40
		STA		_scr_trds_args1,X
		JSR		_nsub_604CD
		TAX
		LDA		off_3AA15,X
		LDY		off_3AA19,X
		JSR		_obj_to_room_bound_box_collision_test
		BCC		loc_3AA0F
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		CLC
		ADC		#$80
		STA		_scr_trds_args1,X
		JSR		_nsub_604CD
		TAX
		LDA		off_3AA15,X
		LDY		off_3AA19,X
		JSR		_obj_to_room_bound_box_collision_test
		BCC		loc_3AA0F
		LDA		_scr_trds_args1,X
		CLC
		ADC		#$40
		STA		_scr_trds_args1,X
loc_3AA0F:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A909
locret_3AA14:
		RTS
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

; =============== S U B R O U T I N E =======================================
_nbgsub_3AA31:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3AA4A
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3AA45
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A9A7
		RTS
loc_3AA45:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3A9AD
locret_3AA4A:
		RTS
_spr_raw_lib11_0C:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$02,$9A,$02,$00
		.BYTE	$02,$8A,$02,$F8
		.BYTE	$F2,$98,$02,$00
		.BYTE	$F2,$88,$02,$F8
_spr_raw_lib11_0E:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$02,$9A,$42,$F8
		.BYTE	$02,$8A,$42,$00
		.BYTE	$F2,$98,$42,$F8
		.BYTE	$F2,$88,$42,$00
_spr_raw_lib11_0F:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$03,$9A,$02,$00
		.BYTE	$03,$9A,$42,$F8
		.BYTE	$F3,$98,$42,$F8
		.BYTE	$F3,$98,$02,$00
_spr_raw_lib11_10:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$02,$9C,$02,$00
		.BYTE	$02,$8C,$02,$F8
		.BYTE	$F2,$B8,$02,$00
		.BYTE	$F2,$A8,$02,$F8
_spr_raw_lib11_12:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$02,$9C,$42,$F8
		.BYTE	$02,$8C,$42,$00
		.BYTE	$F2,$BA,$02,$00
		.BYTE	$F2,$AA,$02,$F8
_spr_raw_lib11_11:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$F3,$AA,$02,$F8
		.BYTE	$F3,$B8,$02,$00
_spr_raw_lib11_13:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$F3,$BA,$02,$00
		.BYTE	$F3,$AA,$02,$F8
_spr_raw_lib11_08:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$02,$9C,$42,$F8
		.BYTE	$02,$8C,$42,$00
		.BYTE	$F2,$A8,$42,$00
		.BYTE	$F2,$B8,$42,$F8
_spr_raw_lib11_0A:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$02,$9C,$02,$00
		.BYTE	$02,$8C,$02,$F8
		.BYTE	$F2,$BA,$42,$F8
		.BYTE	$F2,$AA,$42,$00
_spr_raw_lib11_09:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$F3,$AA,$42,$00
		.BYTE	$F3,$B8,$42,$F8
_spr_raw_lib11_0B:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$03,$AC,$02,$F8
		.BYTE	$03,$AC,$42,$00
		.BYTE	$F3,$BA,$42,$F8
		.BYTE	$F3,$AA,$42,$00
_spr_raw_lib11_04:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$02,$9A,$02,$00
		.BYTE	$02,$8A,$02,$F8
		.BYTE	$F2,$9E,$02,$00
		.BYTE	$F2,$8E,$02,$F8
_spr_raw_lib11_06:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$02,$9A,$42,$F8
		.BYTE	$02,$8A,$42,$00
		.BYTE	$F2,$8E,$42,$00
		.BYTE	$F2,$9E,$42,$F8
_spr_raw_lib11_07:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$04,$9A,$02,$00
		.BYTE	$04,$9A,$42,$F8
		.BYTE	$F4,$9E,$42,$F8
		.BYTE	$F4,$9E,$02,$00
_spr_raw_lib11_16:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$02
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$02,$9A,$02,$02
		.BYTE	$02,$8A,$02,$FA
		.BYTE	$F2,$98,$02,$02
		.BYTE	$F2,$88,$02,$FA
_spr_raw_lib11_17:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$08,$3E,$02,$02
		.BYTE	$02,$9C,$02,$02
		.BYTE	$02,$8C,$02,$FA
		.BYTE	$F2,$B8,$02,$02
		.BYTE	$F2,$A8,$02,$FA
_spr_raw_lib11_15:
		.BYTE	$06
		.BYTE	$08,$3E,$02,$02
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$02,$9C,$42,$FA
		.BYTE	$02,$8C,$42,$02
		.BYTE	$F2,$A8,$42,$02
		.BYTE	$F2,$B8,$42,$FA
_spr_raw_lib11_14:
		.BYTE	$06
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$08,$3E,$02,$02
		.BYTE	$02,$9A,$02,$02
		.BYTE	$02,$8A,$02,$FA
		.BYTE	$F2,$9E,$02,$02
		.BYTE	$F2,$8E,$02,$FA
_spr_raw_lib11_18:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F6
		.BYTE	$F0,$B8,$02,$F8
		.BYTE	$F0,$A8,$02,$F0
_spr_raw_lib11_19:
		.BYTE	$02
		.BYTE	$F8,$BE,$02,$F8
		.BYTE	$F8,$AE,$02,$F0
_spr_raw_lib11_1A:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$02
		.BYTE	$F0,$A8,$42,$08
		.BYTE	$F0,$B8,$42,$00
_spr_raw_lib11_1B:
		.BYTE	$02
		.BYTE	$F8,$BE,$42,$00
		.BYTE	$F8,$AE,$42,$08

; =============== S C R I P T ===============================================
_scr18_chain_saw:
		SPR_IDX_SET		0,$34
_sloc_3AC3B:
		POS_MOVE_STOP	0
		SDELAY			$14
		NJSR			_nsub_62CC4
		NJSR			_nsub_62CD3
		SBCC			_sloc_3AC65
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_62CD3
		SBCC			_sloc_3AC65
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_62CD3
		SBCC			_sloc_3AC65
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_62CD3
		SBCS			_sloc_3AC3B
_sloc_3AC65:
		NJSR			_nsub_628D1
			NARGB		$80,$00
		SDELAY			$10
		NJSR			_nsub_62B1E
			NARGB		$02,$40
		SBCC			_sloc_3AC3B
		NBG_HNDL_SET	_nbgsub_3ACEA
		NJSR			_nsub_62CC4
		SJSR			_ssub_3ACA6
		SSCRIPT1_SET	_scr_3AC9A
		NJSR			_nsub_628D1
			NARGB		$00,$01
		SLOOP_BEGIN		$06
		NJSR			_nsub_62CD3
		SBCS_BREAK	_sloc_3AC91
		SDELAY			$08
		SLOOP_END
_sloc_3AC91:
		SSCRIPT1_OFF

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3AC93:
		SJSR			_ssub_3ACA6
		NBG_HNDL_RESET
		SJMP			_scr18_chain_saw

; =============== S C R I P T ===============================================
_scr_3AC9A:
		NJSR			_nsub_6273D
			NARGB		$28,$40
_sloc_3AC9F:
		SPR_IDX_ADD_IMM 4,$FC
		SPR_IDX_ADD_IMM 4,$04
		SJMP			_sloc_3AC9F

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3ACA6:
		POS_MOVE_STOP	0
		NJSR			_nsub_6273D
			NARGB		$20,$40
		SLOOP_BEGIN		$04
		SPR_IDX_ADD_IMM 4,$FC
		SPR_IDX_ADD_IMM 4,$04
		SLOOP_END
		SRET

; =============== S C R I P T ===============================================
_scr_3ACB4:
		NBG_HNDL_SET	_nbgsub_3AD00
		SARG_SET		SARG0,$02
_sloc_3ACBA:
		SJSR			_ssub_3ACD4
		NJSR			_nsub_62BFD
		SBCC			_sloc_3ACBA
		SLOOP_BEGIN		$14
		SJSR			_ssub_3ACD4
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3AC93
		SCASE			_scr_3ACDE
		SCASE			_scr_3ACE4

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3ACD4:
		NJSR			_nsub_6273D
			NARGB		$24,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ===============================================
_scr_3ACDE:
		SARG_SET		SARG1,$30
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3ACE4:
		SARG_SET		SARG1,$32
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3ACEA:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3ACF9
		JSR		_cur_thread_reload_param
		.WORD	_scr_3ACB4
		RTS
loc_3ACF9:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3AD00:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3AD19
		LSR
		LDA		#$02
		STA		_scores_obj_value
		BCS		loc_3AD14
		JSR		_cur_thread_reload_param
		.WORD	_scr_3ACDE
		RTS
loc_3AD14:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3ACE4
locret_3AD19:
		RTS
_spr_raw_lib11_1C:
		.BYTE	$07
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$C8,$02,$F8
		.BYTE	$00,$C8,$42,$00
		.BYTE	$F0,$C6,$42,$00
		.BYTE	$F0,$C6,$02,$F8
		.BYTE	$F4,$E6,$40,$F4
_spr_raw_lib11_1D:
		.BYTE	$08
		.BYTE	$F9,$E6,$00,$05
		.BYTE	$F9,$D6,$00,$FD
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$FC,$02,$00
		.BYTE	$00,$EC,$02,$F8
		.BYTE	$F0,$FA,$02,$00
		.BYTE	$F0,$EA,$02,$F8
_spr_raw_lib11_1E:
		.BYTE	$08
		.BYTE	$F9,$E6,$00,$02
		.BYTE	$F9,$D6,$00,$FA
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$F0,$C4,$42,$00
		.BYTE	$F0,$C4,$02,$F8
_spr_raw_lib11_1F:
		.BYTE	$08
		.BYTE	$F9,$E6,$40,$F3
		.BYTE	$F9,$D6,$40,$FB
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$00,$EC,$42,$00
		.BYTE	$00,$FC,$42,$F8
		.BYTE	$F0,$EA,$42,$00
		.BYTE	$F0,$FA,$42,$F8
_spr_raw_lib11_20:
		.BYTE	$07
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$C8,$02,$F8
		.BYTE	$00,$C8,$42,$00
		.BYTE	$F0,$C6,$42,$00
		.BYTE	$F0,$C6,$02,$F8
		.BYTE	$F4,$E8,$40,$F4
_spr_raw_lib11_21:
		.BYTE	$08
		.BYTE	$F9,$E8,$00,$05
		.BYTE	$F9,$D8,$00,$FD
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$FC,$02,$00
		.BYTE	$00,$EC,$02,$F8
		.BYTE	$F0,$FA,$02,$00
		.BYTE	$F0,$EA,$02,$F8
_spr_raw_lib11_22:
		.BYTE	$08
		.BYTE	$F9,$E8,$00,$02
		.BYTE	$F9,$D8,$00,$FA
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$F0,$C4,$42,$00
		.BYTE	$F0,$C4,$02,$F8
_spr_raw_lib11_23:
		.BYTE	$08
		.BYTE	$F9,$E8,$40,$F3
		.BYTE	$F9,$D8,$40,$FB
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$00,$EC,$42,$00
		.BYTE	$00,$FC,$42,$F8
		.BYTE	$F0,$EA,$42,$00
		.BYTE	$F0,$FA,$42,$F8
_spr_raw_lib11_24:
		.BYTE	$08
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$F6,$02,$F8
		.BYTE	$00,$F6,$42,$00
		.BYTE	$F0,$F4,$42,$00
		.BYTE	$F0,$F4,$02,$F8
		.BYTE	$E9,$E6,$40,$F8
		.BYTE	$E9,$D6,$40,$00
_spr_raw_lib11_25:
		.BYTE	$08
		.BYTE	$EE,$E6,$00,$02
		.BYTE	$EE,$D6,$00,$FA
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$DC,$02,$00
		.BYTE	$00,$CC,$02,$F8
		.BYTE	$F0,$DA,$02,$00
		.BYTE	$F0,$CA,$02,$F8
_spr_raw_lib11_26:
		.BYTE	$08
		.BYTE	$ED,$E6,$00,$01
		.BYTE	$ED,$D6,$00,$F9
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$F0,$D4,$42,$00
		.BYTE	$F0,$D4,$02,$F8
_spr_raw_lib11_27:
		.BYTE	$08
		.BYTE	$EE,$E6,$40,$F6
		.BYTE	$EE,$D6,$40,$FE
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$00,$DC,$42,$F8
		.BYTE	$00,$CC,$42,$00
		.BYTE	$F0,$CA,$42,$00
		.BYTE	$F0,$DA,$42,$F8
_spr_raw_lib11_28:
		.BYTE	$08
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$F6,$02,$F8
		.BYTE	$00,$F6,$42,$00
		.BYTE	$F0,$F4,$42,$00
		.BYTE	$F0,$F4,$02,$F8
		.BYTE	$E9,$E8,$40,$F8
		.BYTE	$E9,$D8,$40,$00
_spr_raw_lib11_29:
		.BYTE	$08
		.BYTE	$EE,$E8,$00,$02
		.BYTE	$EE,$D8,$00,$FA
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$DC,$02,$00
		.BYTE	$00,$CC,$02,$F8
		.BYTE	$F0,$DA,$02,$00
		.BYTE	$F0,$CA,$02,$F8
_spr_raw_lib11_2A:
		.BYTE	$08
		.BYTE	$ED,$E8,$00,$01
		.BYTE	$ED,$D8,$00,$F9
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$08,$3E,$02,$00
		.BYTE	$00,$E4,$02,$F8
		.BYTE	$00,$E4,$42,$00
		.BYTE	$F0,$D4,$42,$00
		.BYTE	$F0,$D4,$02,$F8
_spr_raw_lib11_2B:
		.BYTE	$08
		.BYTE	$EE,$E8,$40,$F6
		.BYTE	$EE,$D8,$40,$FE
		.BYTE	$08,$3E,$02,$00
		.BYTE	$08,$3E,$42,$F8
		.BYTE	$00,$DC,$42,$F8
		.BYTE	$00,$CC,$42,$00
		.BYTE	$F0,$CA,$42,$00
		.BYTE	$F0,$DA,$42,$F8
_spr_raw_lib11_2C:
		.BYTE	$08
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$08,$3E,$02,$02
		.BYTE	$00,$F6,$02,$FA
		.BYTE	$00,$F6,$42,$02
		.BYTE	$F0,$F4,$42,$02
		.BYTE	$F0,$F4,$02,$FA
		.BYTE	$E9,$E6,$40,$FA
		.BYTE	$E9,$D6,$40,$02
_spr_raw_lib11_2D:
		.BYTE	$08
		.BYTE	$EE,$E6,$00,$04
		.BYTE	$EE,$D6,$00,$FC
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$08,$3E,$02,$02
		.BYTE	$00,$DC,$02,$02
		.BYTE	$00,$CC,$02,$FA
		.BYTE	$F0,$DA,$02,$02
		.BYTE	$F0,$CA,$02,$FA
_spr_raw_lib11_2E:
		.BYTE	$08
		.BYTE	$ED,$E6,$00,$03
		.BYTE	$ED,$D6,$00,$FB
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$08,$3E,$02,$02
		.BYTE	$00,$E4,$02,$FA
		.BYTE	$00,$E4,$42,$02
		.BYTE	$F0,$D4,$42,$02
		.BYTE	$F0,$D4,$02,$FA
_spr_raw_lib11_2F:
		.BYTE	$08
		.BYTE	$EE,$E6,$40,$F8
		.BYTE	$EE,$D6,$40,$00
		.BYTE	$08,$3E,$02,$02
		.BYTE	$08,$3E,$42,$FA
		.BYTE	$00,$DC,$42,$FA
		.BYTE	$00,$CC,$42,$02
		.BYTE	$F0,$CA,$42,$02
		.BYTE	$F0,$DA,$42,$FA
_spr_raw_lib11_30:
		.BYTE	$03
		.BYTE	$00,$B4,$02,$F8
		.BYTE	$F0,$CA,$42,$F8
		.BYTE	$F0,$DA,$42,$F0
_spr_raw_lib11_31:
		.BYTE	$02
		.BYTE	$F8,$CE,$42,$F8
		.BYTE	$F8,$DE,$42,$F0
_spr_raw_lib11_32:
		.BYTE	$03
		.BYTE	$00,$B4,$42,$00
		.BYTE	$F0,$CA,$02,$00
		.BYTE	$F0,$DA,$02,$08
_spr_raw_lib11_33:
		.BYTE	$02
		.BYTE	$F8,$CE,$02,$00
		.BYTE	$F8,$DE,$02,$08
_spr_raw_lib11_34:
		.BYTE	$02
		.BYTE	$08,$3E,$40,$F8
		.BYTE	$08,$3E,$00,$00

; =============== S C R I P T ===============================================
_scr19_toilet_snake:
		SPR_IDX_SET		0,$35
		SDELAY			$1E
_sloc_3AFDF:
		SDELAY			$01
		NJSR			_nsub_62B1E
			NARGB		$02,$40
		SBCC			_sloc_3AFDF
		POS_Y_MOVE		0,$04
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
		NBG_HNDL_SET	_nbgsub_3B04B
		POS_Y_MOVE		0,$03
		SPR_IDX_INC		0
		SDELAY			$2D

; =============== S C R I P T ===============================================
_sjmp_case_3B003:
		NBG_HNDL_RESET
		POS_Y_MOVE		0,$FD
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
		SJMP			_scr19_toilet_snake

; =============== S C R I P T ===============================================
_scr_3B01D:
		NBG_HNDL_SET	_nbgsub_3B061
		SARG_SET		SARG0,$02
_sloc_3B023:
		SPR_IDX_SET		1,$3D
		SPR_IDX_SET		1,$3C
		NJSR			_nsub_62BFD
		SBCC			_sloc_3B023
		SLOOP_BEGIN		$14
		SPR_IDX_SET		1,$3D
		SPR_IDX_SET		1,$3C
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3B003
		SCASE			_scr_3B03F
		SCASE			_scr_3B045

; =============== S C R I P T ===============================================
_scr_3B03F:
		SARG_SET		SARG1,$3E
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3B045:
		SARG_SET		SARG1,$40
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3B04B:
		LDX		#$04
		LDY		#$16
		JSR		sub_61DD6
		BCC		loc_3B05A
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B01D
		RTS
loc_3B05A:
		LDX		#$09
		LDY		#$1C
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3B061:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3B07A
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3B075
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B03F
		RTS
loc_3B075:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B045
locret_3B07A:
		RTS
_spr_raw_lib11_35:
		.BYTE	$01
		.BYTE	$F8,$F8,$02,$FC
_spr_raw_lib11_36:
		.BYTE	$03
		.BYTE	$FC,$E0,$42,$00
		.BYTE	$FC,$E0,$02,$F8
		.BYTE	$F4,$F8,$02,$FC
_spr_raw_lib11_37:
		.BYTE	$0B
		.BYTE	$00,$E0,$02,$F8
		.BYTE	$00,$E0,$42,$00
		.BYTE	$FD,$E2,$C2,$00
		.BYTE	$FD,$E2,$82,$F8
		.BYTE	$FA,$E2,$C2,$00
		.BYTE	$FA,$E2,$82,$F8
		.BYTE	$F7,$E2,$C2,$00
		.BYTE	$F7,$E2,$82,$F8
		.BYTE	$F4,$E2,$C2,$00
		.BYTE	$F4,$E2,$82,$F8
		.BYTE	$F1,$F8,$02,$FC
_spr_raw_lib11_38:
		.BYTE	$0B
		.BYTE	$02,$E0,$02,$F8
		.BYTE	$02,$E0,$42,$00
		.BYTE	$FE,$E2,$C2,$00
		.BYTE	$FE,$E2,$82,$F8
		.BYTE	$FA,$E2,$C2,$00
		.BYTE	$FA,$E2,$82,$F8
		.BYTE	$F6,$E2,$C2,$00
		.BYTE	$F6,$E2,$82,$F8
		.BYTE	$F2,$E2,$C2,$00
		.BYTE	$F2,$E2,$82,$F8
		.BYTE	$EE,$F8,$02,$FC
_spr_raw_lib11_39:
		.BYTE	$0B
		.BYTE	$05,$E0,$02,$F8
		.BYTE	$05,$E0,$42,$00
		.BYTE	$00,$E2,$C2,$00
		.BYTE	$00,$E2,$82,$F8
		.BYTE	$FB,$E2,$C2,$00
		.BYTE	$FB,$E2,$82,$F8
		.BYTE	$F6,$E2,$C2,$00
		.BYTE	$F6,$E2,$82,$F8
		.BYTE	$F1,$E2,$C2,$00
		.BYTE	$F1,$E2,$82,$F8
		.BYTE	$EC,$F8,$02,$FC
_spr_raw_lib11_3A:
		.BYTE	$0B
		.BYTE	$07,$E0,$02,$F8
		.BYTE	$07,$E0,$42,$00
		.BYTE	$01,$E2,$C2,$00
		.BYTE	$01,$E2,$82,$F8
		.BYTE	$FB,$E2,$C2,$00
		.BYTE	$FB,$E2,$82,$F8
		.BYTE	$F5,$E2,$C2,$00
		.BYTE	$F5,$E2,$82,$F8
		.BYTE	$EF,$E2,$C2,$00
		.BYTE	$EF,$E2,$82,$F8
		.BYTE	$E9,$F8,$02,$FC
_spr_raw_lib11_3B:
		.BYTE	$0B
		.BYTE	$0A,$E0,$02,$F8
		.BYTE	$0A,$E0,$42,$00
		.BYTE	$03,$E2,$C2,$00
		.BYTE	$03,$E2,$82,$F8
		.BYTE	$FC,$E2,$C2,$00
		.BYTE	$FC,$E2,$82,$F8
		.BYTE	$F5,$E2,$C2,$00
		.BYTE	$F5,$E2,$82,$F8
		.BYTE	$EE,$E2,$C2,$00
		.BYTE	$EE,$E2,$82,$F8
		.BYTE	$E7,$F8,$02,$FC
_spr_raw_lib11_3C:
		.BYTE	$0B
		.BYTE	$0C,$E0,$02,$F8
		.BYTE	$0C,$E0,$42,$00
		.BYTE	$04,$E2,$C2,$00
		.BYTE	$04,$E2,$82,$F8
		.BYTE	$FC,$E2,$C2,$00
		.BYTE	$FC,$E2,$82,$F8
		.BYTE	$F4,$E2,$C2,$00
		.BYTE	$F4,$E2,$82,$F8
		.BYTE	$EC,$E2,$C2,$00
		.BYTE	$EC,$E2,$82,$F8
		.BYTE	$E4,$F8,$02,$FC
_spr_raw_lib11_3D:
		.BYTE	$0B
		.BYTE	$0C,$E0,$02,$FA
		.BYTE	$0C,$E0,$42,$02
		.BYTE	$04,$E2,$C2,$02
		.BYTE	$04,$E2,$82,$FA
		.BYTE	$FC,$E2,$C2,$02
		.BYTE	$FC,$E2,$82,$FA
		.BYTE	$F4,$E2,$C2,$02
		.BYTE	$F4,$E2,$82,$FA
		.BYTE	$EC,$E2,$C2,$02
		.BYTE	$EC,$E2,$82,$FA
		.BYTE	$E4,$F8,$02,$FE
_spr_raw_lib11_3E:
		.BYTE	$04
		.BYTE	$F4,$C0,$02,$EC
		.BYTE	$F4,$D0,$02,$F4
		.BYTE	$FD,$F2,$02,$F8
		.BYTE	$F8,$F2,$C2,$F3
_spr_raw_lib11_3F:
		.BYTE	$03
		.BYTE	$F8,$C0,$02,$F0
		.BYTE	$F8,$D0,$02,$F8
		.BYTE	$00,$B4,$02,$F8
_spr_raw_lib11_40:
		.BYTE	$04
		.BYTE	$F4,$C0,$42,$0D
		.BYTE	$F4,$D0,$42,$05
		.BYTE	$FD,$F2,$42,$01
		.BYTE	$F8,$F2,$82,$06
_spr_raw_lib11_41:
		.BYTE	$03
		.BYTE	$F8,$C0,$42,$08
		.BYTE	$F8,$D0,$42,$00
		.BYTE	$00,$B4,$42,$00

; =============== S C R I P T ===============================================
_scr2A_morning_star_troll:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_3B4E6
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$C0
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3B214:
		NBG_HNDL_SET	_nbgsub_3B281
		SSCRIPT1_SET	_scr_3B24C
_sloc_3B21B:
		NJSR			_nsub_3B2B1
		SJSR_SW	$03
		SCASE			_sjsr_case_3B237
		SCASE			_sjsr_case_3B229
		SCASE			_sjsr_case_3B230
		SJMP			_sloc_3B21B
_sjsr_case_3B229:
		POS_X_DELTA_SET 0,$80,$00
		SDELAY			$10
		POS_MOVE_STOP	0
		SRET
_sjsr_case_3B230:
		POS_X_DELTA_SET 0,$80,$FF
		SDELAY			$10
		POS_MOVE_STOP	0
		SRET
_sjsr_case_3B237:
		SDELAY			$18
		SSCRIPT1_OFF
		SPR_IDX_SET		0,$C8
		NJSR			_nsub_new_thread_start
			NARGB		$2A
			NARGB		$F7,$20
			NARGB		$01
			NARGB		$00
		SDELAY			$18
		SSCRIPT1_SET	_scr_3B24C
		SRET

; =============== S C R I P T ===============================================
_scr_3B24C:
		SPR_IDX_SET		3,$C0
		SLOOP_BEGIN		$07
		SPR_IDX_INC		3
		SLOOP_END
		SJMP			_scr_3B24C

; =============== S C R I P T ===============================================
_scr_3B255:
		NBG_HNDL_SET	_nbgsub_3B297
		SARG_SET		SARG0,$02
_sloc_3B25B:
		SPR_IDX_SET		1,$C9
		SPR_IDX_INC		1
		NJSR			_nsub_62BFD
		SBCC			_sloc_3B25B
		SLOOP_BEGIN		$0F
		SPR_IDX_SET		1,$C9
		SPR_IDX_INC		1
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3B214
		SCASE			_scr_3B275
		SCASE			_scr_3B27B

; =============== S C R I P T ===============================================
_scr_3B275:
		SARG_SET		SARG1,$42
		SJMP			_sloc_62E25

; =============== S C R I P T ===============================================
_scr_3B27B:
		SARG_SET		SARG1,$42
		SJMP			_sloc_62E2C

; =============== S U B R O U T I N E =======================================
_nbgsub_3B281:
		LDX		#$08
		LDY		#$0C
		JSR		sub_61DD6
		BCC		loc_3B290
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B255
		RTS
loc_3B290:
		LDX		#$0A
		LDY		#$0E
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3B297:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3B2B0
		LSR
		LDA		#$0F
		STA		_scores_obj_value
		BCS		loc_3B2AB
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B275
		RTS
loc_3B2AB:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B27B
locret_3B2B0:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_3B2B1:
		LDA		#$13
		JSR		_rand
		CMP		#$0F
		BCC		loc_3B2BD
		LDA		#$00
		RTS
loc_3B2BD:
		ADC		#$01
		STA		_tmp0
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,X
		LSR
		LSR
		LSR
		LSR
		CLC
		ADC		#$01
		CMP		_tmp0
		PHP
		PLA
		AND		#$01
		PHA
		TAX
		LDA		off_3B2E6,X
		LDY		off_3B2E8,X
		JSR		_obj_to_room_bound_box_collision_test
		PLA
		BCC		loc_3B2E2
		EOR		#$01
loc_3B2E2:
		CLC
		ADC		#$01
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
_spr_res_lib11_00:
		.BYTE	$01
		.WORD	_spr_res_lib11_00_A
_spr_res_lib11_01:
		.BYTE	$01
		.WORD	_spr_res_lib11_01_A
_spr_res_lib11_02:
		.BYTE	$01
		.WORD	_spr_res_lib11_02_A
_spr_res_lib11_03:
		.BYTE	$01
		.WORD	_spr_res_lib11_03_A
_spr_res_lib11_04:
		.BYTE	$01
		.WORD	_spr_res_lib11_04_A
_spr_res_lib11_05:
		.BYTE	$01
		.WORD	_spr_res_lib11_05_A
_spr_res_lib11_06:
		.BYTE	$01
		.WORD	_spr_res_lib11_06_A
_spr_res_lib11_07:
		.BYTE	$01
		.WORD	_spr_res_lib11_07_A
_spr_res_lib11_08:
		.BYTE	$01
		.WORD	_spr_res_lib11_08_A
_spr_res_lib11_09:
		.BYTE	$01
		.WORD	_spr_res_lib11_09_A
_spr_res_lib11_0A:
		.BYTE	$01
		.WORD	_spr_res_lib11_0A_A
_spr_res_lib11_00_A:
		.BYTE	$09
		.BYTE	$D6,$EC,$00,$F0
		.BYTE	$D6,$FC,$00,$F8
		.BYTE	$DE,$C8,$00,$F4
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$FA,$D6,$03,$F4
		.BYTE	$FA,$C6,$03,$04
		.BYTE	$FA,$E6,$03,$FC
_spr_res_lib11_01_A:
		.BYTE	$09
		.BYTE	$DA,$FC,$00,$02
		.BYTE	$DA,$EC,$00,$FA
		.BYTE	$DF,$CC,$00,$F7
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$FA,$D6,$03,$F4
		.BYTE	$FA,$C6,$03,$04
		.BYTE	$FA,$E6,$03,$FC
_spr_res_lib11_02_A:
		.BYTE	$0A
		.BYTE	$E8,$FC,$00,$0F
		.BYTE	$E8,$EC,$00,$07
		.BYTE	$EC,$CA,$00,$01
		.BYTE	$EC,$CA,$00,$F9
		.BYTE	$FA,$C2,$03,$04
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$FA,$D2,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$EA,$E0,$03,$FC
_spr_res_lib11_03_A:
		.BYTE	$0A
		.BYTE	$FA,$FC,$00,$0B
		.BYTE	$FA,$EC,$00,$03
		.BYTE	$EF,$CC,$40,$FD
		.BYTE	$F0,$DC,$40,$F7
		.BYTE	$FA,$C2,$03,$04
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$FA,$D2,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$EA,$E0,$03,$FC
_spr_res_lib11_04_A:
		.BYTE	$0A
		.BYTE	$02,$FC,$00,$F7
		.BYTE	$02,$EC,$00,$EF
		.BYTE	$F8,$C8,$00,$F3
		.BYTE	$F0,$C8,$00,$F3
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$FA,$C4,$03,$F4
		.BYTE	$FA,$F6,$03,$04
		.BYTE	$FA,$E6,$03,$FC
_spr_res_lib11_05_A:
		.BYTE	$0A
		.BYTE	$FA,$EC,$00,$DE
		.BYTE	$FA,$FC,$00,$E6
		.BYTE	$F0,$CC,$00,$E7
		.BYTE	$F0,$DC,$00,$EF
		.BYTE	$EA,$F4,$03,$04
		.BYTE	$EA,$E4,$03,$FC
		.BYTE	$EA,$D4,$03,$F4
		.BYTE	$FA,$C4,$03,$F4
		.BYTE	$FA,$F6,$03,$04
		.BYTE	$FA,$E6,$03,$FC
_spr_res_lib11_06_A:
		.BYTE	$0A
		.BYTE	$E8,$EC,$00,$D9
		.BYTE	$E8,$FC,$00,$E1
		.BYTE	$EC,$CA,$00,$E6
		.BYTE	$EC,$CA,$00,$EE
		.BYTE	$FA,$F2,$03,$04
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$FA,$C0,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$EA,$E0,$03,$FC
_spr_res_lib11_07_A:
		.BYTE	$09
		.BYTE	$DB,$EC,$00,$E2
		.BYTE	$DB,$FC,$00,$EA
		.BYTE	$DF,$CC,$40,$EF
		.BYTE	$FA,$F2,$03,$04
		.BYTE	$EA,$F0,$03,$04
		.BYTE	$EA,$D0,$03,$F4
		.BYTE	$FA,$C0,$03,$F4
		.BYTE	$FA,$E2,$03,$FC
		.BYTE	$EA,$E0,$03,$FC
_spr_res_lib11_08_A:
		.BYTE	$06
		.BYTE	$EA,$F8,$03,$04
		.BYTE	$EA,$E8,$03,$FC
		.BYTE	$EA,$D8,$03,$F4
		.BYTE	$FA,$DA,$03,$F4
		.BYTE	$FA,$FA,$03,$04
		.BYTE	$FA,$EA,$03,$FC
_spr_res_lib11_09_A:
		.BYTE	$09
		.BYTE	$02,$FC,$00,$F8
		.BYTE	$02,$EC,$00,$F0
		.BYTE	$FF,$C8,$00,$F4
		.BYTE	$EA,$F8,$03,$04
		.BYTE	$EA,$E8,$03,$FC
		.BYTE	$EA,$D8,$03,$F4
		.BYTE	$FA,$DA,$03,$F4
		.BYTE	$FA,$FA,$03,$04
		.BYTE	$FA,$EA,$03,$FC
_spr_res_lib11_0A_A:
		.BYTE	$09
		.BYTE	$02,$FC,$00,$FA
		.BYTE	$02,$EC,$00,$F2
		.BYTE	$FF,$C8,$00,$F6
		.BYTE	$EA,$F8,$03,$06
		.BYTE	$EA,$E8,$03,$FE
		.BYTE	$EA,$D8,$03,$F6
		.BYTE	$FA,$DA,$03,$F6
		.BYTE	$FA,$FA,$03,$06
		.BYTE	$FA,$EA,$03,$FE
_spr_raw_lib11_42:
		.BYTE	$08
		.BYTE	$FC,$EC,$00,$EE
		.BYTE	$FC,$FC,$00,$F6
		.BYTE	$FE,$EE,$03,$02
		.BYTE	$EE,$F0,$03,$02
		.BYTE	$EE,$D8,$03,$F2
		.BYTE	$FE,$CE,$03,$F2
		.BYTE	$FE,$DE,$03,$FA
		.BYTE	$EE,$E0,$03,$FA
_spr_raw_lib11_43:
		.BYTE	$04
		.BYTE	$06,$BE,$03,$02
		.BYTE	$F6,$F0,$03,$02
		.BYTE	$06,$AE,$03,$FA
		.BYTE	$F6,$E0,$03,$FA

; =============== S C R I P T ===============================================
_sjmp_case_3B4E6:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_3B4FE
		SPR_IDX_SET		2,$44
		SLOOP_BEGIN		$05
		POS_Y_MOVE		0,$10
		SPR_IDX_INC		2
		SLOOP_END
		POS_MOVE_STOP	0
		SDELAY			$02
		SLOOP_BEGIN		$05
		POS_Y_MOVE		0,$F0
		SPR_IDX_DEC		2
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_3B4FE:
		LDX		#$0B
		LDY		#$0C
		JSR		_player_to_obj_collision_test
		JMP		_cur_obj_out_of_screen_test
_spr_raw_lib11_44:
		.BYTE	$04
		.BYTE	$F8,$FC,$00,$00
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
_spr_raw_lib11_45:
		.BYTE	$05
		.BYTE	$F8,$FC,$00,$00
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
_spr_raw_lib11_46:
		.BYTE	$06
		.BYTE	$F8,$FC,$00,$00
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
_spr_raw_lib11_47:
		.BYTE	$07
		.BYTE	$F8,$FC,$00,$00
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
_spr_raw_lib11_48:
		.BYTE	$08
		.BYTE	$F8,$FC,$00,$00
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$9A,$C8,$00,$FC
_spr_raw_lib11_49:
		.BYTE	$09
		.BYTE	$F8,$FC,$00,$00
		.BYTE	$F8,$EC,$00,$F8
		.BYTE	$EA,$C8,$00,$FC
		.BYTE	$DA,$C8,$00,$FC
		.BYTE	$CA,$C8,$00,$FC
		.BYTE	$BA,$C8,$00,$FC
		.BYTE	$AA,$C8,$00,$FC
		.BYTE	$9A,$C8,$00,$FC
		.BYTE	$8A,$C8,$00,$FC
_spr_raw_lib11_4A:
		.BYTE	$0A		; *--
		.BYTE	$F8,$FC,$00,$00	; *--
		.BYTE	$F8,$EC,$00,$F8	; *--
		.BYTE	$EA,$C8,$00,$FC	; *--
		.BYTE	$DA,$C8,$00,$FC	; *--
		.BYTE	$CA,$C8,$00,$FC	; *--
		.BYTE	$BA,$C8,$00,$FC	; *--
		.BYTE	$AA,$C8,$00,$FC	; *--
		.BYTE	$9A,$C8,$00,$FC	; *--
		.BYTE	$8A,$C8,$00,$FC	; *--
		.BYTE	$7A,$C8,$00,$FC	; *--
_spr_raw_lib11_4B:
		.BYTE	$0B		; *--
		.BYTE	$F8,$FC,$00,$00	; *--
		.BYTE	$F8,$EC,$00,$F8	; *--
		.BYTE	$EA,$C8,$00,$FC	; *--
		.BYTE	$DA,$C8,$00,$FC	; *--
		.BYTE	$CA,$C8,$00,$FC	; *--
		.BYTE	$BA,$C8,$00,$FC	; *--
		.BYTE	$AA,$C8,$00,$FC	; *--
		.BYTE	$9A,$C8,$00,$FC	; *--
		.BYTE	$8A,$C8,$00,$FC	; *--
		.BYTE	$7A,$C8,$00,$FC	; *--
		.BYTE	$6A,$C8,$00,$FC	; *--

; =============== S C R I P T ===============================================
_scr1C_girl_and_floaters:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$03
		SCASE			_sjmp_case_3B71F
		SCASE			_sjmp_case_3B9C4
		SCASE			_sjmp_case_3BA43
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		byte_3B6D6
		SARG_SET		SARG1,$00
		NJSR			_nsub_new_thread_start
			NARGB		$1C
			NARGB		$E0,$00
			NARGB		$01
			NARGB		$00
		NJSR			_nsub_obj_sarg_set_from_nsub_return_value
			NARGB		$02
		NJSR			_nsub_new_thread_start
			NARGB		$1C
			NARGB		$F0,$00
			NARGB		$02
			NARGB		$00
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$4C
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3B631:
		NBG_HNDL_SET	_nbgsub_3B6DA
_sloc_3B634:
		SLOOP_BEGIN		$02
		NJSR			_nsub_6273D
			NARGB		$4C,$40
		NJSR			_nsub_628D1
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SLOOP_BEGIN		$02
		NJSR			_nsub_6273D
			NARGB		$50,$40
		NJSR			_nsub_628D1
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$F8
		SLOOP_END
		SJMP			_sloc_3B634

; =============== S C R I P T ===============================================
_scr_3B65D:
		NBG_HNDL_SET	_nbgsub_3B6FC
		SARG_SET		SARG0,$02
_sloc_3B663:
		SJSR			_ssub_3B67D
		NJSR			_nsub_62BFD
		SBCC			_sloc_3B663
		SLOOP_BEGIN		$0F
		SJSR			_ssub_3B67D
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3B631
		SCASE			_scr_3B687
		SCASE			_scr_3B68D

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3B67D:
		NJSR			_nsub_6273D
			NARGB		$50,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S C R I P T ===============================================
_scr_3B687:
		SARG_SET		SARG1,$58
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3B68D:
		SARG_SET		SARG1,$5A
		SJMP			_sloc_62E02

; =============== S C R I P T ===============================================
_scr_3B693:
		SPR_IDX_SET		7,$4C
		SPR_IDX_INC		7
		SPR_IDX_INC		7
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
		SSCRIPT1_SET	_scr_3B6C8
		SLOOP_BEGIN		$14
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
		SSTOP

; =============== S C R I P T ===============================================
_scr_3B6C8:
		SLOOP_BEGIN		$06
		NJSR			_nsub_new_thread_start
			NARGB		$1C
			NARGB		$00,$00
			NARGB		$03
			NARGB		$00
		SDELAY			$14
		SLOOP_END
		SSCRIPT0_OFF
byte_3B6D6:
		.BYTE	$0F,$36,$25,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_3B6DA:
		LDX		#$06
		LDY		#$06
		JSR		sub_61DD6
		BCC		loc_3B6E9
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B65D
		RTS
loc_3B6E9:
		LDX		#$0B
		LDY		#$0C
		JSR		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
sub_3B6F0:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args2,X
		BPL		locret_3B6FB
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B693
locret_3B6FB:
		RTS

; =============== S U B R O U T I N E =======================================
_nbgsub_3B6FC:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3B71E
		LSR
		LDY		_scr_trds_args2,X
		BMI		loc_3B70C
		LDA		#$FF
		STA		_scr_trds_args2,Y
loc_3B70C:
		LDA		#$05
		STA		_scores_obj_value
		BCS		loc_3B719
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B687
		RTS
loc_3B719:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B68D
locret_3B71E:
		RTS

; =============== S C R I P T ===============================================
_sjmp_case_3B71F:
		SARG_SET		SARG0,$00
		SLOOP_BEGIN		$10
		SPR_IDX_SET		1,$4C
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ===============================================
_sjmp_case_3B729:
		NBG_HNDL_SET	_nbgsub_3B775
_sloc_3B72C:
		SLOOP_BEGIN		$02
		NJSR			_nsub_6273D
			NARGB		$4C,$40
		NJSR			_nsub_628D1
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SLOOP_BEGIN		$02
		NJSR			_nsub_6273D
			NARGB		$50,$40
		NJSR			_nsub_628D1
			NARGB		$00,$03
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$08
		SLOOP_END
		SJMP			_sloc_3B72C

; =============== S C R I P T ===============================================
_scr_3B755:
		NBG_HNDL_SET	_nbgsub_3B6FC
		SARG_SET		SARG0,$02
_sloc_3B75B:
		SJSR			_ssub_3B67D
		NJSR			_nsub_62BFD
		SBCC			_sloc_3B75B
		SLOOP_BEGIN		$0F
		SJSR			_ssub_3B67D
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3B729
		SCASE			_scr_3B687
		SCASE			_scr_3B68D

; =============== S U B R O U T I N E =======================================
_nbgsub_3B775:
		LDX		#$06
		LDY		#$06
		JSR		sub_61DD6
		BCC		loc_3B784
		JSR		_cur_thread_reload_param
		.WORD	_scr_3B755
		RTS
loc_3B784:
		LDX		#$0B
		LDY		#$0C
		JSR		_player_to_obj_collision_test
		JMP		sub_3B6F0
_spr_raw_lib11_4C:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$94,$42,$00
		.BYTE	$04,$96,$42,$00
		.BYTE	$04,$96,$02,$F8
		.BYTE	$F4,$94,$02,$F8
_spr_raw_lib11_50:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$F4,$84,$42,$00
		.BYTE	$04,$86,$42,$00
		.BYTE	$04,$86,$02,$F8
		.BYTE	$F4,$84,$02,$F8
_spr_raw_lib11_4D:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$F4,$88,$42,$00
		.BYTE	$04,$8A,$42,$00
		.BYTE	$04,$9A,$42,$F8
		.BYTE	$F4,$98,$42,$F8
_spr_raw_lib11_51:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$8C,$42,$00
		.BYTE	$04,$8E,$42,$00
		.BYTE	$04,$9E,$42,$F8
		.BYTE	$F4,$9C,$42,$F8
_spr_raw_lib11_4E:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$F4,$90,$42,$00
		.BYTE	$04,$92,$42,$00
		.BYTE	$04,$92,$02,$F8
		.BYTE	$F4,$90,$02,$F8
_spr_raw_lib11_52:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$F4,$80,$42,$00
		.BYTE	$04,$82,$42,$00
		.BYTE	$04,$82,$02,$F8
		.BYTE	$F4,$80,$02,$F8
_spr_raw_lib11_4F:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$04,$9A,$02,$00
		.BYTE	$F4,$98,$02,$00
		.BYTE	$04,$8A,$02,$F8
		.BYTE	$F4,$88,$02,$F8
_spr_raw_lib11_53:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$10,$E8,$40,$00
		.BYTE	$04,$9E,$02,$00
		.BYTE	$F4,$9C,$02,$00
		.BYTE	$04,$8E,$02,$F8
		.BYTE	$F4,$8C,$02,$F8
_spr_raw_lib11_54:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$F4,$94,$42,$02
		.BYTE	$04,$96,$42,$02
		.BYTE	$04,$96,$02,$FA
		.BYTE	$F4,$94,$02,$FA
_spr_raw_lib11_55:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$02
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$F4,$88,$42,$02
		.BYTE	$04,$8A,$42,$02
		.BYTE	$04,$9A,$42,$FA
		.BYTE	$F4,$98,$42,$FA
_spr_raw_lib11_56:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$F4,$90,$42,$02
		.BYTE	$04,$92,$42,$02
		.BYTE	$04,$92,$02,$FA
		.BYTE	$F4,$90,$02,$FA
_spr_raw_lib11_57:
		.BYTE	$06
		.BYTE	$10,$E8,$00,$FA
		.BYTE	$10,$E8,$40,$02
		.BYTE	$04,$9A,$02,$02
		.BYTE	$F4,$98,$02,$02
		.BYTE	$04,$8A,$02,$FA
		.BYTE	$F4,$88,$02,$FA
_spr_raw_lib11_58:
		.BYTE	$04
		.BYTE	$FD,$D4,$02,$FB
		.BYTE	$FD,$C4,$02,$F3
		.BYTE	$ED,$C2,$02,$F3
		.BYTE	$ED,$D2,$02,$FB
_spr_raw_lib11_59:
		.BYTE	$02
		.BYTE	$FC,$D6,$02,$FB
		.BYTE	$FC,$C6,$02,$F3
_spr_raw_lib11_5A:
		.BYTE	$04
		.BYTE	$FD,$D4,$42,$FE
		.BYTE	$FD,$C4,$42,$06
		.BYTE	$ED,$C2,$42,$06
		.BYTE	$ED,$D2,$42,$FE
_spr_raw_lib11_5B:
		.BYTE	$02
		.BYTE	$FC,$D6,$42,$FE
		.BYTE	$FC,$C6,$42,$06
_spr_raw_lib11_5C:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$F4,$F0,$02,$00
		.BYTE	$04,$F2,$02,$00
		.BYTE	$04,$E2,$02,$F8
		.BYTE	$F4,$E0,$02,$F8
_spr_raw_lib11_5D:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$04,$E2,$42,$00
		.BYTE	$F4,$E0,$42,$00
		.BYTE	$04,$F2,$42,$F8
		.BYTE	$F4,$F0,$42,$F8
_spr_raw_lib11_5E:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$F4,$F0,$42,$F8
		.BYTE	$04,$F2,$42,$F8
		.BYTE	$04,$F2,$02,$00
		.BYTE	$F4,$F0,$02,$00
_spr_raw_lib11_5F:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$04,$F6,$02,$00
		.BYTE	$04,$E6,$02,$F8
		.BYTE	$F4,$E4,$02,$F8
		.BYTE	$F4,$F4,$02,$00
_spr_raw_lib11_60:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$04,$E6,$42,$00
		.BYTE	$04,$F6,$42,$F8
		.BYTE	$F4,$F4,$42,$F8
		.BYTE	$F4,$E4,$42,$00
_spr_raw_lib11_61:
		.BYTE	$06
		.BYTE	$10,$E8,$40,$00
		.BYTE	$10,$E8,$00,$F8
		.BYTE	$F4,$F4,$02,$00
		.BYTE	$04,$F6,$02,$00
		.BYTE	$04,$F6,$42,$F8
		.BYTE	$F4,$F4,$42,$F8
_spr_raw_lib11_63:
		.BYTE	$03
		.BYTE	$F4,$58,$00,$FC
		.BYTE	$FA,$58,$00,$F8
		.BYTE	$FA,$58,$00,$00
_spr_raw_lib11_62:
		.BYTE	$02
		.BYTE	$FA,$48,$00,$FA
		.BYTE	$FC,$48,$00,$FF
_spr_raw_lib11_64:
		.BYTE	$05
		.BYTE	$F7,$58,$00,$08
		.BYTE	$FD,$58,$00,$FC
		.BYTE	$F4,$58,$00,$F1
		.BYTE	$E7,$58,$00,$F6
		.BYTE	$E8,$58,$00,$02
_spr_raw_lib11_65:
		.BYTE	$05
		.BYTE	$E5,$48,$00,$06
		.BYTE	$FC,$48,$00,$0F
		.BYTE	$05,$48,$00,$FC
		.BYTE	$F7,$48,$00,$EE
		.BYTE	$E4,$48,$00,$F4

; =============== S C R I P T ===============================================
_sjmp_case_3B9C4:
		SARG_SET		SARG0,$00
_sloc_3B9C7:
		SPR_IDX_SET		6,$66
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		NJSR			_nsub_62BE5
		SBCC			_sloc_3B9C7
		SLOOP_BEGIN		$03
		SPR_IDX_SET		0,$6A
		SDELAY			$0F
		SPR_IDX_INC		0
		SDELAY			$1E
		SLOOP_END
		SSTOP
_spr_raw_lib11_66:
		.BYTE	$04
		.BYTE	$00,$BA,$00,$00
		.BYTE	$00,$AA,$00,$F8
		.BYTE	$F0,$A8,$00,$F8
		.BYTE	$F0,$B8,$00,$00
_spr_raw_lib11_67:
		.BYTE	$04
		.BYTE	$00,$AA,$40,$01
		.BYTE	$00,$BA,$40,$F9
		.BYTE	$F0,$A8,$40,$01
		.BYTE	$F0,$B8,$40,$F9
_spr_raw_lib11_68:
		.BYTE	$04
		.BYTE	$00,$AA,$00,$F8
		.BYTE	$F0,$D8,$40,$F8
		.BYTE	$F0,$C8,$40,$00
		.BYTE	$00,$BA,$00,$00
_spr_raw_lib11_69:
		.BYTE	$04
		.BYTE	$00,$BA,$40,$F9
		.BYTE	$00,$AA,$40,$01
		.BYTE	$F0,$C8,$00,$F9
		.BYTE	$F0,$D8,$00,$01
_spr_raw_lib11_6A:
		.BYTE	$04
		.BYTE	$F0,$BC,$00,$00
		.BYTE	$F0,$BC,$40,$F8
		.BYTE	$00,$AE,$00,$F8
		.BYTE	$00,$AE,$40,$00
_spr_raw_lib11_6B:
		.BYTE	$04
		.BYTE	$00,$AE,$40,$00
		.BYTE	$00,$AE,$00,$F8
		.BYTE	$F0,$AC,$00,$F8
		.BYTE	$F0,$AC,$40,$00

; =============== S C R I P T ===============================================
_sjmp_case_3BA43:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_3BAC9
_sloc_3BA49:
		SDELAY			$01
		NJSR			_nsub_3BAF9
		SBCS			_sloc_3BA49
		NBG_HNDL_SET	_nbgsub_3BAD8
		SJSR_SW	$04
		SCASE			_sjsr_case_3BA69
		SCASE			_sjsr_case_3BA72
		SCASE			_sjsr_case_3BA7E
		SCASE			_sjsr_case_3BA87
		NBG_HNDL_SET	_nbgsub_3BAC9
		SPR_IDX_ADD_IMM 0,$FC
		POS_MOVE_STOP	0
		SDELAY			$1E
		SJMP			_sloc_3BA49
_sjsr_case_3BA69:
		SPR_IDX_SET		0,$70
		POS_Y_DELTA_SET 4,$00,$FA
		POS_Y_DELTA_SET 4,$00,$02
		SRET
_sjsr_case_3BA72:
		SPR_IDX_SET		0,$71
		POS_X_DELTA_SET 0,$00,$02
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$02
		SRET
_sjsr_case_3BA7E:
		SPR_IDX_SET		0,$72
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$06
		SRET
_sjsr_case_3BA87:
		SPR_IDX_SET		0,$73
		POS_X_DELTA_SET 0,$00,$FE
		POS_Y_DELTA_SET 4,$00,$FE
		POS_Y_DELTA_SET 4,$00,$02
		SRET

; =============== S C R I P T ===============================================
_scr_3BA93:
		NBG_HNDL_SET	_nbgsub_3BADF
		SARG_SET		SARG0,$02
_sloc_3BA99:
		SJSR			_ssub_3BAB3
		NJSR			_nsub_62BFD
		SBCC			_sloc_3BA99
		SLOOP_BEGIN		$0F
		SJSR			_ssub_3BAB3
		SLOOP_END
		NJSR			_nsub_62C0B
		SJMP_SW			$03
		SCASE			_sjmp_case_3BA43
		SCASE			_scr_3BABD
		SCASE			_scr_3BAC3

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3BAB3:
		NJSR			_nsub_6273D
			NARGB		$70,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$04
		SRET

; =============== S C R I P T ===============================================
_scr_3BABD:
		SARG_SET		SARG1,$78
		SJMP			_sloc_62DD7

; =============== S C R I P T ===============================================
_scr_3BAC3:
		SARG_SET		SARG1,$7A
		SJMP			_sloc_62E02

; =============== S U B R O U T I N E =======================================
_nbgsub_3BAC9:
		LDX		#$08
		LDY		#$08
		JSR		sub_61DD6
		BCC		_nbgsub_3BAD8
		JSR		_cur_thread_reload_param
		.WORD	_scr_3BA93
		RTS

; =============== S U B R O U T I N E =======================================
_nbgsub_3BAD8:
		LDX		#$08
		LDY		#$09
		JMP		_player_to_obj_collision_test

; =============== S U B R O U T I N E =======================================
_nbgsub_3BADF:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		locret_3BAF8
		LSR
		LDA		#$01
		STA		_scores_obj_value
		BCS		loc_3BAF3
		JSR		_cur_thread_reload_param
		.WORD	_scr_3BABD
		RTS
loc_3BAF3:
		JSR		_cur_thread_reload_param
		.WORD	_scr_3BAC3
locret_3BAF8:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_3BAF9:
		LDA		#$00
		JSR		_rand
		AND		#$03
		PHA
		TAX
		LDA		off_3BB0D,X
		LDY		off_3BB11,X
		JSR		_obj_to_room_bound_box_collision_test
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
_spr_raw_lib11_6C:
		.BYTE	$01
		.BYTE	$FC,$A6,$02,$FC
_spr_raw_lib11_70:
		.BYTE	$01
		.BYTE	$FC,$B6,$02,$FC
_spr_raw_lib11_6D:
		.BYTE	$01
		.BYTE	$FC,$A4,$42,$FC
_spr_raw_lib11_71:
		.BYTE	$01
		.BYTE	$FC,$B4,$42,$FC
_spr_raw_lib11_6E:
		.BYTE	$01
		.BYTE	$FC,$A2,$42,$FC
_spr_raw_lib11_72:
		.BYTE	$01
		.BYTE	$FC,$B2,$42,$FC
_spr_raw_lib11_6F:
		.BYTE	$01
		.BYTE	$FC,$A4,$02,$FC
_spr_raw_lib11_73:
		.BYTE	$01
		.BYTE	$FC,$B4,$02,$FC
_spr_raw_lib11_74:
		.BYTE	$01
		.BYTE	$FC,$B6,$02,$FE
_spr_raw_lib11_75:
		.BYTE	$01
		.BYTE	$FC,$B4,$42,$FE
_spr_raw_lib11_76:
		.BYTE	$01
		.BYTE	$FC,$B2,$42,$FE
_spr_raw_lib11_77:
		.BYTE	$01
		.BYTE	$FC,$B4,$02,$FE
_spr_raw_lib11_7A:
		.BYTE	$01
		.BYTE	$02,$B4,$42,$FE
_spr_raw_lib11_7B:
		.BYTE	$01
		.BYTE	$02,$A4,$42,$FE
_spr_raw_lib11_78:
		.BYTE	$01
		.BYTE	$02,$B4,$02,$FB
_spr_raw_lib11_79:
		.BYTE	$01
		.BYTE	$02,$A4,$02,$FA

; =============== S C R I P T ===============================================
_scr11_lvl2_ghost_nanny:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$02
		SCASE			_sjmp_case_3BC8A
		SCASE			_sjmp_case_3BCAF
		NJSR			_nsub_3BBF3
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$14
		NJSR			_nsub_apu_mus_load
			NARGB		$0C
		NJSR			_nsub_new_thread_start
			NARGB		$11
			NARGB		$00,$00
			NARGB		$01
			NARGB		$00
		POS_X_SET		0,$90,$00
		POS_Y_SET		0,$C0,$02
		SLOOP_BEGIN		$02
		SJSR			_ssub_3BBE1
		SLOOP_END
		NJSR			_nsub_new_thread_start
			NARGB		$11
			NARGB		$00,$00
			NARGB		$02
			NARGB		$00
		SLOOP_BEGIN		$04
		SJSR			_ssub_3BBE1
		SLOOP_END
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$7E
		SDELAY			$10
		POS_X_DELTA_SET 0,$80,$01
		SLOOP_BEGIN		$03
		SPR_IDX_SET		6,$7D
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SPR_IDX_SET		0,$FF
		POS_MOVE_STOP	0
		SLOOP_BEGIN		$80
		SMEM_ALU		_apu_mus_volume,_ADC,$FF
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_62BA9
		SSTOP

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_3BBE1:
		POS_MOVE_STOP	0
		SPR_IDX_SET		6,$7C
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

; =============== S U B R O U T I N E =======================================
_nsub_3BBF3:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_602CB
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_60FCB
		RTS
_spr_raw_lib11_7C:
		.BYTE	$04
		.BYTE	$08,$B4,$00,$00
		.BYTE	$08,$B4,$40,$F8
		.BYTE	$F8,$A2,$40,$F8
		.BYTE	$F8,$A2,$00,$00
_spr_raw_lib11_7D:
		.BYTE	$04
		.BYTE	$08,$94,$40,$F8
		.BYTE	$08,$84,$40,$00
		.BYTE	$F9,$92,$40,$F8
		.BYTE	$F9,$82,$40,$00
_spr_raw_lib11_7E:
		.BYTE	$04
		.BYTE	$08,$38,$40,$F8
		.BYTE	$08,$28,$40,$00
		.BYTE	$F8,$92,$40,$F8
		.BYTE	$F8,$82,$40,$00
_spr_raw_lib11_7F:
		.BYTE	$04
		.BYTE	$08,$94,$00,$00
		.BYTE	$08,$84,$00,$F8
		.BYTE	$F9,$92,$40,$F8
		.BYTE	$F9,$82,$40,$00
_spr_raw_lib11_80:
		.BYTE	$04
		.BYTE	$08,$B4,$00,$00
		.BYTE	$08,$B4,$40,$F8
		.BYTE	$F8,$B2,$40,$F8
		.BYTE	$F8,$B2,$00,$00
_spr_raw_lib11_81:
		.BYTE	$04
		.BYTE	$08,$84,$40,$00
		.BYTE	$08,$94,$40,$F8
		.BYTE	$F9,$92,$00,$00
		.BYTE	$F9,$82,$00,$F8
_spr_raw_lib11_82:
		.BYTE	$04
		.BYTE	$08,$38,$00,$00
		.BYTE	$08,$28,$00,$F8
		.BYTE	$F8,$92,$00,$00
		.BYTE	$F8,$82,$00,$F8
_spr_raw_lib11_83:
		.BYTE	$04
		.BYTE	$08,$94,$00,$00
		.BYTE	$08,$84,$00,$F8
		.BYTE	$F9,$92,$00,$00
		.BYTE	$F9,$82,$00,$F8

; =============== S C R I P T ===============================================
_sjmp_case_3BC8A:
		SARG_SET		SARG0,$00
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$A0,$02
		SLOOP_BEGIN		$0F
		SPR_IDX_SET		7,$84
		SPR_IDX_INC		7
		SLOOP_END
		SPR_IDX_SET		7,$84
		SPR_IDX_INC		3
		SSTOP
_spr_raw_lib11_84:
		.BYTE	$02
		.BYTE	$F8,$F0,$00,$00
		.BYTE	$F8,$E0,$00,$F8
_spr_raw_lib11_85:
		.BYTE	$02
		.BYTE	$F8,$B0,$00,$00
		.BYTE	$F8,$A0,$00,$F8

; =============== S C R I P T ===============================================
_sjmp_case_3BCAF:
		SARG_SET		SARG0,$00
		POS_X_SET		0,$70,$00
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
		SPR_IDX_INC		0
		SDELAY			$0A
		SPR_IDX_INC		0
		SDELAY			$0A
		SPR_IDX_INC		4
		SPR_IDX_INC		0
		SDELAY			$10
		SPR_IDX_INC		0
		SDELAY			$0A
		SPR_IDX_INC		0
		SDELAY			$0A
		POS_X_DELTA_SET 0,$40,$01
		SPR_IDX_SET		0,$87
		SDELAY			$50
		SSTOP
_spr_raw_lib11_86:
		.BYTE	$0C
		.BYTE	$F0,$F8,$43,$F0
		.BYTE	$F0,$F8,$03,$08
		.BYTE	$F8,$DC,$03,$F8
		.BYTE	$F8,$EC,$03,$00
		.BYTE	$08,$EE,$03,$00
		.BYTE	$08,$DE,$03,$F8
		.BYTE	$00,$EA,$03,$00
		.BYTE	$00,$EA,$43,$F8
		.BYTE	$E0,$F6,$03,$F8
		.BYTE	$E0,$E6,$03,$00
		.BYTE	$F0,$E8,$43,$F8
		.BYTE	$F0,$E8,$03,$00
_spr_raw_lib11_87:
		.BYTE	$0B
		.BYTE	$FA,$FC,$03,$01
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11_88:
		.BYTE	$0D
		.BYTE	$0B,$CA,$03,$F8
		.BYTE	$0A,$DA,$03,$00
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11_89:
		.BYTE	$0E
		.BYTE	$15,$DA,$03,$01
		.BYTE	$16,$CA,$03,$F9
		.BYTE	$0E,$D8,$03,$01
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11_8A:
		.BYTE	$10
		.BYTE	$24,$DA,$03,$03
		.BYTE	$26,$CA,$03,$FB
		.BYTE	$16,$D8,$03,$03
		.BYTE	$06,$D6,$03,$03
		.BYTE	$16,$C8,$03,$FB
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11_8B:
		.BYTE	$12
		.BYTE	$26,$80,$00,$FD
		.BYTE	$26,$90,$00,$05
		.BYTE	$24,$DA,$03,$03
		.BYTE	$26,$CA,$03,$FB
		.BYTE	$16,$D8,$03,$03
		.BYTE	$06,$D6,$03,$03
		.BYTE	$16,$C8,$03,$FB
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11_8C:
		.BYTE	$10
		.BYTE	$16,$80,$00,$FB
		.BYTE	$16,$90,$00,$03
		.BYTE	$15,$DA,$03,$01
		.BYTE	$16,$CA,$03,$F9
		.BYTE	$0E,$D8,$03,$01
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11_8D:
		.BYTE	$0F
		.BYTE	$0B,$80,$00,$F8
		.BYTE	$0B,$90,$00,$00
		.BYTE	$0B,$CA,$03,$F8
		.BYTE	$0B,$DA,$03,$FF
		.BYTE	$06,$C6,$03,$FB
		.BYTE	$08,$F4,$03,$10
		.BYTE	$F8,$F2,$03,$10
		.BYTE	$F8,$E2,$03,$08
		.BYTE	$08,$E4,$03,$08
		.BYTE	$08,$D4,$03,$00
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$E8,$D0,$03,$00
		.BYTE	$F8,$D2,$03,$00
		.BYTE	$F8,$C2,$03,$F8
_spr_raw_lib11:
		.WORD	_spr_raw_lib1A_00
		.WORD	_spr_raw_lib1A_01
		.WORD	_spr_raw_lib1A_02
		.WORD	_spr_raw_lib1A_03
		.WORD	_spr_raw_lib11_04
		.WORD	_spr_raw_lib11_07
		.WORD	_spr_raw_lib11_06
		.WORD	_spr_raw_lib11_07
		.WORD	_spr_raw_lib11_08
		.WORD	_spr_raw_lib11_09
		.WORD	_spr_raw_lib11_0A
		.WORD	_spr_raw_lib11_0B
		.WORD	_spr_raw_lib11_0C
		.WORD	_spr_raw_lib11_0F
		.WORD	_spr_raw_lib11_0E
		.WORD	_spr_raw_lib11_0F
		.WORD	_spr_raw_lib11_10
		.WORD	_spr_raw_lib11_11
		.WORD	_spr_raw_lib11_12
		.WORD	_spr_raw_lib11_13
		.WORD	_spr_raw_lib11_14
		.WORD	_spr_raw_lib11_15
		.WORD	_spr_raw_lib11_16
		.WORD	_spr_raw_lib11_17
		.WORD	_spr_raw_lib11_18
		.WORD	_spr_raw_lib11_19
		.WORD	_spr_raw_lib11_1A
		.WORD	_spr_raw_lib11_1B
		.WORD	_spr_raw_lib11_1C
		.WORD	_spr_raw_lib11_1D
		.WORD	_spr_raw_lib11_1E
		.WORD	_spr_raw_lib11_1F
		.WORD	_spr_raw_lib11_20
		.WORD	_spr_raw_lib11_21
		.WORD	_spr_raw_lib11_22
		.WORD	_spr_raw_lib11_23
		.WORD	_spr_raw_lib11_24
		.WORD	_spr_raw_lib11_25
		.WORD	_spr_raw_lib11_26
		.WORD	_spr_raw_lib11_27
		.WORD	_spr_raw_lib11_28
		.WORD	_spr_raw_lib11_29
		.WORD	_spr_raw_lib11_2A
		.WORD	_spr_raw_lib11_2B
		.WORD	_spr_raw_lib11_2C
		.WORD	_spr_raw_lib11_2D
		.WORD	_spr_raw_lib11_2E
		.WORD	_spr_raw_lib11_2F
		.WORD	_spr_raw_lib11_30
		.WORD	_spr_raw_lib11_31
		.WORD	_spr_raw_lib11_32
		.WORD	_spr_raw_lib11_33
		.WORD	_spr_raw_lib11_34
		.WORD	_spr_raw_lib11_35
		.WORD	_spr_raw_lib11_36
		.WORD	_spr_raw_lib11_37
		.WORD	_spr_raw_lib11_38
		.WORD	_spr_raw_lib11_39
		.WORD	_spr_raw_lib11_3A
		.WORD	_spr_raw_lib11_3B
		.WORD	_spr_raw_lib11_3C
		.WORD	_spr_raw_lib11_3D
		.WORD	_spr_raw_lib11_3E
		.WORD	_spr_raw_lib11_3F
		.WORD	_spr_raw_lib11_40
		.WORD	_spr_raw_lib11_41
		.WORD	_spr_raw_lib11_42
		.WORD	_spr_raw_lib11_43
		.WORD	_spr_raw_lib11_44
		.WORD	_spr_raw_lib11_45
		.WORD	_spr_raw_lib11_46
		.WORD	_spr_raw_lib11_47
		.WORD	_spr_raw_lib11_48
		.WORD	_spr_raw_lib11_49
		.WORD	_spr_raw_lib11_4A	; *--
		.WORD	_spr_raw_lib11_4B	; *--
		.WORD	_spr_raw_lib11_4C
		.WORD	_spr_raw_lib11_4D
		.WORD	_spr_raw_lib11_4E
		.WORD	_spr_raw_lib11_4F
		.WORD	_spr_raw_lib11_50
		.WORD	_spr_raw_lib11_51
		.WORD	_spr_raw_lib11_52
		.WORD	_spr_raw_lib11_53
		.WORD	_spr_raw_lib11_54
		.WORD	_spr_raw_lib11_55
		.WORD	_spr_raw_lib11_56
		.WORD	_spr_raw_lib11_57
		.WORD	_spr_raw_lib11_58
		.WORD	_spr_raw_lib11_59
		.WORD	_spr_raw_lib11_5A
		.WORD	_spr_raw_lib11_5B
		.WORD	_spr_raw_lib11_5C
		.WORD	_spr_raw_lib11_5D
		.WORD	_spr_raw_lib11_5E
		.WORD	_spr_raw_lib11_5F
		.WORD	_spr_raw_lib11_60
		.WORD	_spr_raw_lib11_61
		.WORD	_spr_raw_lib11_62
		.WORD	_spr_raw_lib11_63
		.WORD	_spr_raw_lib11_64
		.WORD	_spr_raw_lib11_65
		.WORD	_spr_raw_lib11_66
		.WORD	_spr_raw_lib11_67
		.WORD	_spr_raw_lib11_68
		.WORD	_spr_raw_lib11_69
		.WORD	_spr_raw_lib11_6A
		.WORD	_spr_raw_lib11_6B
		.WORD	_spr_raw_lib11_6C
		.WORD	_spr_raw_lib11_6D
		.WORD	_spr_raw_lib11_6E
		.WORD	_spr_raw_lib11_6F
		.WORD	_spr_raw_lib11_70
		.WORD	_spr_raw_lib11_71
		.WORD	_spr_raw_lib11_72
		.WORD	_spr_raw_lib11_73
		.WORD	_spr_raw_lib11_74
		.WORD	_spr_raw_lib11_75
		.WORD	_spr_raw_lib11_76
		.WORD	_spr_raw_lib11_77
		.WORD	_spr_raw_lib11_78
		.WORD	_spr_raw_lib11_79
		.WORD	_spr_raw_lib11_7A
		.WORD	_spr_raw_lib11_7B
		.WORD	_spr_raw_lib11_7C
		.WORD	_spr_raw_lib11_7D
		.WORD	_spr_raw_lib11_7E
		.WORD	_spr_raw_lib11_7F
		.WORD	_spr_raw_lib11_80
		.WORD	_spr_raw_lib11_81
		.WORD	_spr_raw_lib11_82
		.WORD	_spr_raw_lib11_83
		.WORD	_spr_raw_lib11_84
		.WORD	_spr_raw_lib11_85
		.WORD	_spr_raw_lib11_86
		.WORD	_spr_raw_lib11_87
		.WORD	_spr_raw_lib11_88
		.WORD	_spr_raw_lib11_89
		.WORD	_spr_raw_lib11_8A
		.WORD	_spr_raw_lib11_8B
		.WORD	_spr_raw_lib11_8C
		.WORD	_spr_raw_lib11_8D
_spr_res_lib11:
		.WORD	_spr_res_lib11_00
		.WORD	_spr_res_lib11_01
		.WORD	_spr_res_lib11_02
		.WORD	_spr_res_lib11_03
		.WORD	_spr_res_lib11_04
		.WORD	_spr_res_lib11_05
		.WORD	_spr_res_lib11_06
		.WORD	_spr_res_lib11_07
		.WORD	_spr_res_lib11_08
		.WORD	_spr_res_lib11_09
		.WORD	_spr_res_lib11_0A

		BANK_END 4,$C000
