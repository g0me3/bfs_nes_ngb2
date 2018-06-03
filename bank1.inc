
		ORG $8000

		BANK_START $01

; =============== S C R I P T ===============================================
_scr01_lvl1_handler:
		NJSR			_nsub_sub_rom_idx_calc
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJSR_SW	$04
		SCASE			_sjsr_case_142CD
		SCASE			_sjsr_case_142CD
		SCASE			_sjsr_case_142CD
		SCASE			_sjsr_case_142E2
		NJSR			_nsub_room_register
			NARGB		$04
			NARGB		$4E,$71,$00
			NARGB		$79,$46,$03
			NARGB		$39,$6E,$03
			NARGB		$6E,$34,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$04
		SCASE			_sjmp_case_14031
		SCASE			_sjmp_case_14155
		SCASE			_sjmp_case_1409B
		SCASE			_sjmp_case_1426B

; =============== S C R I P T ===============================================
_sjmp_case_14031:
		STORE8			_cur_room_sequence_idx,$00
		NJSR			_nsub_628FA
			NARGB		$00,$02,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data00
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data00
		SJSR			_ssub_62DB1
_sloc_14048:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$03
			NARGB		$F8,$01,$88,$03
			NARGB		$00,$04,$B0,$03
			NARGB		$80,$02,$08,$03
		SBCC			_sloc_14048
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$03
			NARGB		$3C,$6E,$03
			NARGB		$82,$74,$01
			NARGB		$4E,$5A,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$03
		SCASE			_sjmp_case_1409B
		SCASE			_sjmp_case_140E9
		SCASE			_sjmp_case_14155
_lvl_doors_data00:
		.BYTE	$02,$80,$03,$D0,$00
		.WORD	_room_door_always_closed
		.BYTE	$02,$10,$03,$80,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$80,$03,$20,$00
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$E0,$03,$B0,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data00:
		.BYTE	$17,$13,$13,$00

; =============== S C R I P T ===============================================
_sjmp_case_1409B:
		STORE8			_cur_room_sequence_idx,$01
		NJSR			_nsub_628FA
			NARGB		$00,$00,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data01
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data01
		SJSR			_ssub_62DB1
_sloc_140B2:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$00,$02,$88,$03
		SBCC			_sloc_140B2
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$42,$6E,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_14031
_lvl_doors_data01:
		.BYTE	$01,$E0,$03,$80,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$F0,$03,$80,$01
		.WORD	_room_door_always_open
		.BYTE	$FF
_prize_sequence_data01:
		.BYTE	$15,$16,$14,$14,$14,$16,$16,$00

; =============== S C R I P T ===============================================
_sjmp_case_140E9:
		STORE8			_cur_room_sequence_idx,$02
		NJSR			_nsub_628FA
			NARGB		$01,$04,$02
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0D
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data02
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data02
		SJSR			_ssub_62DB1
_sloc_14104:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$03,$B0,$03
			NARGB		$F8,$03,$40,$02
		SBCC			_sloc_14104
		SJSR			_ssub_62DC5
		NJSR			_nsub_pal_patch_fade
			NARGB		$06
			NARGW		byte_14354
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$7C,$74,$03
			NARGB		$7C,$46,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14031
		SCASE			_sjmp_case_14155
_lvl_doors_data02:
		.BYTE	$04,$10,$03,$B0,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$C0,$03,$90,$00
		.WORD	_room_door_always_open
		.BYTE	$04,$C0,$02,$60,$00
		.WORD	_room_door_always_open
		.BYTE	$04,$10,$02,$40,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data02:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14155:
		STORE8			_cur_room_sequence_idx,$03
		NJSR			_nsub_628FA
			NARGB		$00,$02,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data03
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$02
		NJSR			_nsub_full_pal_load
			NARGW		byte_1433C
		STORE16			_lvl_collisions_ptr,_lvl_collisions_00
		SJSR			_ssub_62DB1
_sloc_1417E:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$04
			NARGB		$80,$02,$F8,$02
			NARGB		$00,$04,$40,$02
			NARGB		$F8,$01,$C0,$02
			NARGB		$80,$02,$08,$02
		SBCC			_sloc_1417E
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$04
			NARGB		$4E,$62,$02
			NARGB		$82,$46,$01
			NARGB		$3C,$56,$03
			NARGB		$6E,$38,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$04
		SCASE			_sjmp_case_14031
		SCASE			_sjmp_case_140E9
		SCASE			_sjmp_case_141E4
		SCASE			_sjmp_case_1426B
_lvl_doors_data03:
		.BYTE	$03,$E0,$02,$40,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$70,$02,$B0,$00
		.WORD	_room_door_always_open
		.BYTE	$02,$10,$02,$C0,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$80,$02,$E0,$00
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$80,$02,$20,$00
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data03:
; REGION, changed in the EU version
		.BYTE	$17,$18,$18,$18,$14,$13,$00
;		.BYTE	$17,$14,$18,$13,$00
; -

; =============== S C R I P T ===============================================
_sjmp_case_141E4:
		STORE8			_cur_room_sequence_idx,$04
		NJSR			_nsub_628FA
			NARGB		$02,$01,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data04
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data04
		SJSR			_ssub_62DB1
_sloc_141FB:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$00,$02,$C0,$02
		SBCC			_sloc_141FB
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$42,$56,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_14155
_lvl_doors_data04:
		.BYTE	$01,$E0,$02,$C0,$01
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$70,$02,$90,$00
		.WORD	_room_door_always_open
		.BYTE	$FF
_prize_sequence_data04:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1422B:
		STORE8			_cur_room_sequence_idx,$05
		NJSR			_nsub_628FA
			NARGB		$01,$02,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data05
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data05
		SJSR			_ssub_62DB1
_sloc_14242:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$02,$B8,$01
		SBCC			_sloc_14242
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$6E,$22,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1426B
_lvl_doors_data05:
		.BYTE	$02,$80,$01,$A0,$00
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data05:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1426B:
		STORE8			_cur_room_sequence_idx,$06
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$07
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$03
		NJSR			_nsub_full_pal_load
			NARGW		byte_1435C
		STORE16			_lvl_collisions_ptr,_lvl_collisions_01
		NJSR			_nsub_628FA
			NARGB		$02,$03,$01
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data06
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data06
		SJSR			_ssub_62DB1
_sloc_14294:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$03,$18,$01
			NARGB		$80,$03,$E8,$01
		SBCC			_sloc_14294
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$4E,$32,$00
			NARGB		$4E,$42,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_1422B
		SCASE			_sjmp_case_14155
_lvl_doors_data06:
		.BYTE	$03,$80,$01,$30,$00
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$80,$01,$D0,$00
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data06:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_142CD:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$02
		NJSR			_nsub_full_pal_load
			NARGW		byte_1433C
		STORE16			_lvl_collisions_ptr,_lvl_collisions_00
		SJMP			_sloc_142F4
; =============== S C R I P T  S U B R O U T I N E ==========================

_sjsr_case_142E2:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$07
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$03
		NJSR			_nsub_full_pal_load
			NARGW		byte_1435C
		STORE16			_lvl_collisions_ptr,_lvl_collisions_01
_sloc_142F4:
		STORE8			_lvl_data_prg_bank,$01
		NJSR			_nsub_lvl_data_ptrs_load
			NARGW		_lvl0_macroA_tbl
			NARGW		_lvl0_macroB_tbl
			NARGW		_lvl0_macroC_tbl
			NARGW		_lvl0_macroD_tbl
			NARGW		_lvl0_attrs_tbl
		STORE16			_lvl_room_lib_ptr,_lvl_room_lib00
		NJSR			_nsub_apu_mus_load
			NARGB		$00
		NJSR			_nsub_ingame_collision_watch_start
		NJSR			_nsub_ingame_player_control_start
		NBG_HNDL_SET	_j_nbgsub_1437C
		SSCRIPT1_SET	_scr_14324
		STORE16			_lvl_objects_ptr,_lvl0_objects_list
		NJSR			_nsub_lvl_room_objects_init
		SRET

; =============== S C R I P T ===============================================
_scr_14324:
		SDELAY			$01
		NJSR			_nsub_15E4A
		SBCC			_scr_14324
		NJSR			_nsub_apu_snd_load
			NARGB		$03
		SJSR			_ssub_62DC9
		NJSR			_nsub_pause_menu_handler
		SJSR			_ssub_62DB5
		SJMP			_scr_14324

byte_1433C:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$1A,$17,$0F,$37,$27,$17,$0F,$30,$05,$17
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15
byte_14354:
		.BYTE	$0F,$36,$2B,$0F,$0F,$10,$17,$07
byte_1435C:
		.BYTE	$0F,$30,$17,$07,$0F,$30,$05,$07,$0F,$10,$17,$07,$0F,$30,$10,$00
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$31,$25,$0F,$0F,$10,$17,$07

; =============== S U B R O U T I N E =======================================
_j_nbgsub_1437C:
		JMP		_lvl_room_objects_handler

; =============== S C R I P T ===============================================
_scr02_lvl2_handler:
		NJSR			_nsub_sub_rom_idx_calc
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJSR_SW	$05
		SCASE			_sjsr_case_14753
		SCASE			_sjsr_case_14753
		SCASE			_sjsr_case_14753
		SCASE			_sjsr_case_14753
		SCASE			_sjsr_case_14763
		NJSR			_nsub_room_register
			NARGB		$05
			NARGB		$06,$D1,$01
			NARGB		$2E,$D9,$00
			NARGB		$2E,$79,$00
			NARGB		$83,$46,$01
			NARGB		$A3,$06,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$05
		SCASE			_sjmp_case_143B7
		SCASE			_sjmp_case_1447E
		SCASE			_sjmp_case_14514
		SCASE			_sjmp_case_145A4
		SCASE			_sjmp_case_1462C

; =============== S C R I P T ===============================================
_sjmp_case_143B7:
		STORE8			_cur_room_sequence_idx,$00
		NJSR			_nsub_628FA
			NARGB		$02,$00,$06
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data07
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data07
		SJSR			_ssub_62DB1
_sloc_143CE:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$00,$08,$06
		SBCC			_sloc_143CE
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$0E,$B9,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_143F7
_lvl_doors_data07:
		.BYTE	$00,$80,$06,$10,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data07:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_143F7:
		STORE8			_cur_room_sequence_idx,$01
		NJSR			_nsub_628FA
			NARGB		$01,$00,$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data08
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data08
		SJSR			_ssub_62DB1
_sloc_1440E:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$78,$00,$08,$04
		SBCC			_sloc_1440E
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$0E,$73,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_14437
_lvl_doors_data08:
		.BYTE	$00,$80,$04,$20,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data08:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14437:
		STORE8			_cur_room_sequence_idx,$02
		NJSR			_nsub_628FA
			NARGB		$02,$00,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data09
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data09
		SJSR			_ssub_62DB1
_sloc_1444E:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$78,$00,$08,$03
		SBCC			_sloc_1444E
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$2E,$D9,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1447E
_lvl_doors_data09:
		.BYTE	$00,$80,$03,$10,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$80,$03,$D0,$02
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data09:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1447E:
		STORE8			_cur_room_sequence_idx,$03
		NJSR			_nsub_628FA
			NARGB		$02,$01,$06
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data0A
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data0A
		SJSR			_ssub_62DB1
_sloc_14495:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$01,$08,$06
		SBCC			_sloc_14495
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$2E,$B9,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_144BE
_lvl_doors_data0A:
		.BYTE	$01,$80,$06,$20,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data0A:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_144BE:
		STORE8			_cur_room_sequence_idx,$04
		NJSR			_nsub_628FA
			NARGB		$01,$01,$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data0B
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data0B
		SJSR			_ssub_62DB1
_sloc_144D5:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$B0,$01,$08,$04
			NARGB		$50,$01,$08,$04
		SBCC			_sloc_144D5
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$2E,$79,$00
			NARGB		$2E,$B9,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14514
		SCASE			_sjmp_case_144BE
_lvl_doors_data0B:
		.BYTE	$01,$B0,$04,$20,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$50,$04,$20,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data0B:
		.BYTE	$1D,$1D,$20,$1D,$1D,$1E,$00

; =============== S C R I P T ===============================================
_sjmp_case_14514:
		STORE8			_cur_room_sequence_idx,$05
		NJSR			_nsub_628FA
			NARGB		$01,$01,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data0C
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data0C
		SJSR			_ssub_62DB1
_sloc_1452B:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$F8,$01,$40,$02
		SBCC			_sloc_1452B
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$45,$46,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1455A
_lvl_doors_data0C:
		.BYTE	$01,$E0,$02,$40,$03
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data0C:
		.BYTE	$20,$1D,$1E,$20,$1D,$1E,$00

; =============== S C R I P T ===============================================
_sjmp_case_1455A:
		STORE8			_cur_room_sequence_idx,$06
		NJSR			_nsub_628FA
			NARGB		$00,$02,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data0D
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data0D
		SJSR			_ssub_62DB1
_sloc_14571:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$F8,$03,$40,$02
		SBCC			_sloc_14571
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$83,$46,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_145A4
_lvl_doors_data0D:
		.BYTE	$03,$E0,$02,$40,$03
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$20,$02,$40,$03
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data0D:
		.BYTE	$20,$20,$1F,$00

; =============== S C R I P T ===============================================
_sjmp_case_145A4:
		STORE8			_cur_room_sequence_idx,$07
		NJSR			_nsub_628FA
			NARGB		$02,$04,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data0E
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data0E
		SJSR			_ssub_62DB1
_sloc_145BB:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$04,$08,$02
		SBCC			_sloc_145BB
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$8E,$39,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_145E8
_lvl_doors_data0E:
		.BYTE	$04,$80,$02,$20,$02
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data0E:
		.BYTE	$1E,$1F,$1E,$20,$00

; =============== S C R I P T ===============================================
_sjmp_case_145E8:
		STORE8			_cur_room_sequence_idx,$08
		NJSR			_nsub_628FA
			NARGB		$01,$04,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data0F
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data0F
		SJSR			_ssub_62DB1
_sloc_145FF:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$00,$05,$48,$00
		SBCC			_sloc_145FF
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$A3,$06,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1462C
_lvl_doors_data0F:
		.BYTE	$04,$E0,$00,$40,$03
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data0F:
		.BYTE	$1E,$1F,$1D,$20,$00

; =============== S C R I P T ===============================================
_sjmp_case_1462C:
		STORE8			_cur_room_sequence_idx,$09
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$0B
		STORE16			_lvl_collisions_ptr,_lvl_collisions_02
		NJSR			_nsub_628FA
			NARGB		$02,$05,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data10
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data10
		SJSR			_ssub_62DB1
_sloc_1464C:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$05,$D8,$00
		SBCC			_sloc_1464C
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$AE,$26,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_14675
_lvl_doors_data10:
		.BYTE	$05,$80,$00,$D0,$04
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data10:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14675:
		STORE8			_cur_room_sequence_idx,$0A
		NJSR			_nsub_628FA
			NARGB		$01,$05,$01
		NJSR			_nsub_bg_pal_load
			NARGW		byte_147C5
		NBG_HNDL_SET	_nbgsub_147F1
		SSCRIPT1_SET	_scr_14734
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data11
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data11
		SJSR			_ssub_62DB1
_sloc_14698:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$05,$E8,$02
		SBCC			_sloc_14698
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$AE,$66,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_146C8
_lvl_doors_data11:
		.BYTE	$05,$80,$01,$20,$04
		.WORD	_room_door_always_closed
		.BYTE	$05,$80,$02,$D0,$04
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data11:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_146C8:
		STORE8			_cur_room_sequence_idx,$0B
		NJSR			_nsub_628FA
			NARGB		$01,$05,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data12
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data12
		SJSR			_ssub_62DB1
_sloc_146DF:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$78,$05,$E8,$04
		SBCC			_sloc_146DF
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$AE,$A6,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1470F
_lvl_doors_data12:
		.BYTE	$05,$80,$03,$20,$04
		.WORD	_room_door_always_closed
		.BYTE	$05,$80,$04,$D0,$04
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data12:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1470F:
		STORE8			_cur_room_sequence_idx,$0C
		NJSR			_nsub_628FA
			NARGB		$01,$05,$05
		STORE8			_cur_room_x_pageB,$05
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data13
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data13
		SJSR			_ssub_62DB1
		SUSPEND
_lvl_doors_data13:
		.BYTE	$05,$80,$05,$20,$04
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data13:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_scr_14734:
		SLOOP_BEGIN		$80
		SMEM_ALU	_apu_var402,_ADC,$FF
		SDELAY			$01
		SLOOP_END
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		NJSR			_nsub_apu_snd_load
			NARGB		$13
		SDELAY			$A0
		STORE8			_apu_var402,$FF
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		SJMP			_scr_14324

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_14753:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0C
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$0A
		STORE16			_lvl_collisions_ptr,_lvl_collisions_03
		SJMP			_sloc_14770

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_14763:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0C
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$0B
		STORE16			_lvl_collisions_ptr,_lvl_collisions_02
_sloc_14770:
		NJSR			_nsub_full_pal_load
			NARGW		byte_147A5
		STORE8			_lvl_data_prg_bank,$02
		NJSR			_nsub_lvl_data_ptrs_load
			NARGW		_lvl1_macroA_tbl
			NARGW		_lvl1_macroB_tbl
			NARGW		_lvl1_macroC_tbl
			NARGW		_lvl1_macroD_tbl
			NARGW		_lvl1_attrs_tbl
		STORE16			_lvl_room_lib_ptr,_lvl_room_lib01
		NJSR			_nsub_apu_mus_load
			NARGB		$06
		NJSR			_nsub_ingame_collision_watch_start
		NJSR			_nsub_ingame_player_control_start
		SSCRIPT1_SET	_scr_14324
		NBG_HNDL_SET	_nbgsub_1480E
		STORE16			_lvl_objects_ptr,_lvl1_objects_list
		NJSR			_nsub_lvl_room_objects_init
		SRET
byte_147A5:
		.BYTE	$0F,$30,$10,$00,$0F,$10,$00,$07,$0F,$10,$00,$08,$0F,$10,$00,$17
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$10,$00,$0F,$0F,$36,$27,$0F
byte_147C5:
		.BYTE	$0F,$30,$10,$00,$0F,$10,$00,$07,$0F,$27,$17,$07,$0F,$01,$00,$07
_unused_2:
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$2B,$0F,$0F,$10,$17,$07 ;	*--
byte_147E5:
		.BYTE	$0F,$0F,$07,$0F,$0F,$07,$0F,$0F,$0F,$0F,$0F,$07

; =============== S U B R O U T I N E =======================================
_nbgsub_147F1:
		LDA		_scr_trds_args0
		CLC
		ADC		#$01
		CMP		#$03
		BCC		loc_147FC
		LDA		#$00
loc_147FC:
		STA		_scr_trds_args0
		ASL
		ASL
		ADC		#<[byte_147E5]
		PHA
		LDA		#$00
		ADC		#>[byte_147E5]
		TAX
		PLA
		LDY		#$02
		JSR		_pal_patch_fade

; =============== S U B R O U T I N E =======================================
_nbgsub_1480E:
		JMP		_lvl_room_objects_handler

; =============== S C R I P T ===============================================
_scr03_lvl3_handler:
		NJSR			_nsub_sub_rom_idx_calc
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJSR			_ssub_15117
		NJSR			_nsub_room_register
			NARGB		$07
			NARGB		$0E,$34,$00
			NARGB		$4E,$06,$02
			NARGB		$AE,$06,$02
			NARGB		$CE,$06,$02
			NARGB		$2E,$66,$02
			NARGB		$4E,$66,$02
			NARGB		$AE,$66,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$07
		SCASE			_sjmp_case_1484A
		SCASE			_sjmp_case_148E1
		SCASE			_sjmp_case_14A2E
		SCASE			_sjmp_case_14B83
		SCASE			_sjmp_case_14CD8
		SCASE			_sjmp_case_14E2F
		SCASE			_sjmp_case_14F89

; =============== S C R I P T ===============================================
_sjmp_case_1484A:
		STORE8			_cur_room_sequence_idx,$00
		NJSR			_nsub_628FA
			NARGB		$00,$00,$01
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data14
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data14
		SJSR			_ssub_62DB1
_sloc_14861:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$80,$01,$08,$01
		SBCC			_sloc_14861
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$2E,$18,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_14891
_lvl_doors_data14:
		.BYTE	$01,$80,$01,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$90,$01,$D0,$06
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data14:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14891:
		STORE8			_cur_room_sequence_idx,$01
		NJSR			_nsub_628FA
			NARGB		$00,$00,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data15
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data15
		SJSR			_ssub_62DB1
_sloc_148A8:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$00,$08,$00
			NARGB		$80,$01,$F8,$00
		SBCC			_sloc_148A8
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$4E,$02,$02
			NARGB		$2E,$22,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_148E1
		SCASE			_sjmp_case_1484A
_lvl_doors_data15:
		.BYTE	$00,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$80,$00,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data15:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_148E1:
		STORE8			_cur_room_sequence_idx,$02
		NJSR			_nsub_628FA
			NARGB		$01,$02,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data16
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data16
		SJSR			_ssub_62DB1
_sloc_148F8:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$02,$F8,$01
			NARGB		$80,$02,$08,$00
		SBCC			_sloc_148F8
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$44,$42,$02
			NARGB		$0E,$02,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14952
		SCASE			_sjmp_case_14891
_lvl_doors_data16:
		.BYTE	$02,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$40,$00,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$80,$00,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$B0,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$70,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$30,$01,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data16:
		.BYTE	$25,$25,$25,$28,$28,$00

; =============== S C R I P T ===============================================
_sjmp_case_14952:
		STORE8			_cur_room_sequence_idx,$03
		NJSR			_nsub_628FA
			NARGB		$00,$02,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data17
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data17
		SJSR			_ssub_62DB1
_sloc_14969:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$D0,$03,$08,$02
			NARGB		$30,$02,$08,$02
		SBCC			_sloc_14969
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$78,$38,$00
			NARGB		$44,$38,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_149BE
		SCASE			_sjmp_case_148E1
_lvl_doors_data17:
		.BYTE	$02,$30,$02,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$40,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$C0,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$50,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$C0,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$02,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data17:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_149BE:
		STORE8			_cur_room_sequence_idx,$04
		NJSR			_nsub_628FA
			NARGB		$01,$03,$00
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data18
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data18
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		SJSR			_ssub_62DB1
_sloc_149E3:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$03,$08,$00
			NARGB		$D0,$03,$F8,$01
		SBCC			_sloc_149E3
		SJSR			_ssub_62DC5
		NJSR			_nsub_apu_mus_load
			NARGB		$07
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$AE,$02,$02
			NARGB		$78,$42,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14A2E
		SCASE			_sjmp_case_14952
_lvl_doors_data18:
		.BYTE	$03,$80,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$40,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$01,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data18:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14A2E:
		STORE8			_cur_room_sequence_idx,$05
		NJSR			_nsub_628FA
			NARGB		$01,$05,$00
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data19
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data19
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15175
		SJSR			_ssub_62DB1
_sloc_14A4F:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$D0,$05,$F8,$01
			NARGB		$80,$05,$08,$00
		SBCC			_sloc_14A4F
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$B8,$42,$02
			NARGB		$6E,$02,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14AA7
		SCASE			_sjmp_case_149BE
_lvl_doors_data19:
		.BYTE	$05,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$05,$70,$00,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$B0,$00,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$80,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$40,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$01,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data19:
; REGION, changed in the EU version
		.BYTE	$28,$26,$26,$00
;		.BYTE	$28,$28,$26,$00
; -

; =============== S C R I P T ===============================================
_sjmp_case_14AA7:
		STORE8			_cur_room_sequence_idx,$06
		NJSR			_nsub_628FA
			NARGB		$00,$04,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data1A
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data1A
		SJSR			_ssub_62DB1
_sloc_14ABE:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$04,$08,$02
			NARGB		$D0,$05,$08,$02
		SBCC			_sloc_14ABE
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$84,$38,$00
			NARGB		$B8,$38,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14B13
		SCASE			_sjmp_case_14A2E
_lvl_doors_data1A:
		.BYTE	$04,$30,$02,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$40,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$D0,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$30,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$C0,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$02,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data1A:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14B13:
		STORE8			_cur_room_sequence_idx,$07
		NJSR			_nsub_628FA
			NARGB		$01,$04,$00
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data1B
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data1B
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		SJSR			_ssub_62DB1
_sloc_14B38:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$04,$08,$00
			NARGB		$30,$04,$F8,$01
		SBCC			_sloc_14B38
		SJSR			_ssub_62DC5
		NJSR			_nsub_apu_mus_load
			NARGB		$07
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$CE,$02,$02
			NARGB		$84,$42,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14B83
		SCASE			_sjmp_case_14AA7
_lvl_doors_data1B:
		.BYTE	$04,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$B0,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$04,$70,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$30,$01,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data1B:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14B83:
		STORE8			_cur_room_sequence_idx,$08
		NJSR			_nsub_628FA
			NARGB		$01,$06,$00
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15175
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data1C
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data1C
		SJSR			_ssub_62DB1
_sloc_14BA4:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$06,$F8,$01
			NARGB		$80,$06,$08,$00
		SBCC			_sloc_14BA4
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$C4,$42,$02
			NARGB		$8E,$02,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14BFC
		SCASE			_sjmp_case_14B13
_lvl_doors_data1C:
		.BYTE	$06,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$06,$40,$00,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$06,$80,$00,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$06,$B0,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$06,$70,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$06,$30,$01,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data1C:
		.BYTE	$27,$27,$28,$00

; =============== S C R I P T ===============================================
_sjmp_case_14BFC:
		STORE8			_cur_room_sequence_idx,$09
		NJSR			_nsub_628FA
			NARGB		$00,$06,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data1D
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data1D
		SJSR			_ssub_62DB1
_sloc_14C13:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$D0,$07,$08,$02
			NARGB		$30,$06,$08,$02
		SBCC			_sloc_14C13
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$F8,$38,$00
			NARGB		$C4,$38,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14C68
		SCASE			_sjmp_case_14B83
_lvl_doors_data1D:
		.BYTE	$06,$30,$02,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$06,$40,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$06,$C0,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$07,$50,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$07,$C0,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$07,$D0,$02,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data1D:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14C68:
		STORE8			_cur_room_sequence_idx,$0A
		NJSR			_nsub_628FA
			NARGB		$01,$07,$00
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data1E
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data1E
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		SJSR			_ssub_62DB1
_sloc_14C8D:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$07,$08,$00
			NARGB		$C0,$07,$F8,$01
		SBCC			_sloc_14C8D
		SJSR			_ssub_62DC5
		NJSR			_nsub_apu_mus_load
			NARGB		$07
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$2E,$62,$02
			NARGB		$F8,$42,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14CD8
		SCASE			_sjmp_case_14BFC
_lvl_doors_data1E:
		.BYTE	$07,$80,$00,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$07,$80,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$07,$40,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$07,$D0,$01,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data1E:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14CD8:
		STORE8			_cur_room_sequence_idx,$0B
		NJSR			_nsub_628FA
			NARGB		$01,$01,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15175
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data1F
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data1F
		SJSR			_ssub_62DB1
_sloc_14CF9:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$D0,$01,$F8,$04
			NARGB		$80,$01,$08,$03
		SBCC			_sloc_14CF9
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$38,$A2,$02
			NARGB		$EE,$02,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14D4E
		SCASE			_sjmp_case_14C68
_lvl_doors_data1F:
		.BYTE	$01,$80,$03,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$70,$03,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$01,$B0,$03,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$80,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$40,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$01,$D0,$04,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data1F:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14D4E:
		STORE8			_cur_room_sequence_idx,$0C
		NJSR			_nsub_628FA
			NARGB		$00,$00,$05
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data20
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data20
		SJSR			_ssub_62DB1
_sloc_14D65:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$00,$08,$05
			NARGB		$D0,$01,$08,$05
		SBCC			_sloc_14D65
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$04,$98,$00
			NARGB		$38,$98,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14DBF
		SCASE			_sjmp_case_14CD8
_lvl_doors_data20:
		.BYTE	$00,$30,$05,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$40,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$00,$C0,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$50,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$C0,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$01,$D0,$05,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data20:
		.BYTE	$28,$24,$24,$24,$28,$00

; =============== S C R I P T ===============================================
_sjmp_case_14DBF:
		STORE8			_cur_room_sequence_idx,$0D
		NJSR			_nsub_628FA
			NARGB		$01,$00,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data21
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data21
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		SJSR			_ssub_62DB1
_sloc_14DE4:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$00,$08,$03
			NARGB		$30,$00,$F8,$04
		SBCC			_sloc_14DE4
		SJSR			_ssub_62DC5
		NJSR			_nsub_apu_mus_load
			NARGB		$07
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$4E,$62,$02
			NARGB		$04,$A2,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14E2F
		SCASE			_sjmp_case_14D4E
_lvl_doors_data21:
		.BYTE	$00,$80,$03,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$B0,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$00,$70,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$00,$30,$04,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data21:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14E2F:
		STORE8			_cur_room_sequence_idx,$0E
		NJSR			_nsub_628FA
			NARGB		$01,$02,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15175
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data22
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data22
		SJSR			_ssub_62DB1
_sloc_14E50:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$02,$F8,$04
			NARGB		$80,$02,$08,$03
		SBCC			_sloc_14E50
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$44,$A2,$02
			NARGB		$0E,$62,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14EAD
		SCASE			_sjmp_case_14DBF
_lvl_doors_data22:
		.BYTE	$02,$80,$03,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$80,$03,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$40,$03,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$B0,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$70,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$30,$04,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data22:
		.BYTE	$28,$24,$24,$24,$24,$24,$24,$25,$00

; =============== S C R I P T ===============================================
_sjmp_case_14EAD:
		STORE8			_cur_room_sequence_idx,$0F
		NJSR			_nsub_628FA
			NARGB		$00,$02,$05
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data23
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data23
		SJSR			_ssub_62DB1
_sloc_14EC4:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$D0,$03,$08,$05
			NARGB		$30,$02,$08,$05
		SBCC			_sloc_14EC4
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$78,$98,$00
			NARGB		$44,$98,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14F19
		SCASE			_sjmp_case_14E2F
_lvl_doors_data23:
		.BYTE	$02,$30,$05,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$40,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$D0,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$30,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$C0,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$05,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data23:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14F19:
		STORE8			_cur_room_sequence_idx,$10
		NJSR			_nsub_628FA
			NARGB		$01,$03,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data24
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data24
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		SJSR			_ssub_62DB1
_sloc_14F3E:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$80,$03,$08,$03
			NARGB		$C0,$03,$F8,$04
		SBCC			_sloc_14F3E
		SJSR			_ssub_62DC5
		NJSR			_nsub_apu_mus_load
			NARGB		$07
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$AE,$62,$02
			NARGB		$78,$A2,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14F89
		SCASE			_sjmp_case_14EAD
_lvl_doors_data24:
		.BYTE	$03,$80,$03,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$80,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$40,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$04,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data24:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14F89:
		STORE8			_cur_room_sequence_idx,$14
		NJSR			_nsub_628FA
			NARGB		$01,$05,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data25
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data25
		SJSR			_ssub_62DB1
_sloc_14FAA:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$D0,$05,$F8,$04
			NARGB		$80,$05,$08,$03
		SBCC			_sloc_14FAA
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$B8,$A2,$02
			NARGB		$6E,$62,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_14FFF
		SCASE			_sjmp_case_14F19
_lvl_doors_data25:
		.BYTE	$05,$80,$03,$20,$06
		.WORD	_room_door_gen_clear_open
		.BYTE	$05,$70,$03,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$B0,$03,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$80,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$40,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$04,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data25:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_14FFF:
		STORE8			_cur_room_sequence_idx,$15
		NJSR			_nsub_628FA
			NARGB		$00,$04,$05
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data26
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data26
		SJSR			_ssub_62DB1
_sloc_15016:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$04,$08,$05
			NARGB		$D0,$05,$08,$05
		SBCC			_sloc_15016
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$84,$98,$00
			NARGB		$B8,$98,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_1506B
		SCASE			_sjmp_case_14F89
_lvl_doors_data26:
		.BYTE	$04,$30,$05,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$40,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$C0,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$50,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$C0,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$05,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data26:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1506B:
		STORE8			_cur_room_sequence_idx,$16
		NJSR			_nsub_628FA
			NARGB		$01,$04,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data27
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data27
		NJSR			_nsub_apu_mus_load
			NARGB		$01
		SJSR			_ssub_62DB1
_sloc_15086:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$30,$04,$08,$03
			NARGB		$30,$04,$F8,$04
		SBCC			_sloc_15086
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$06,$56,$01
			NARGB		$84,$A2,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_150CD
		SCASE			_sjmp_case_14FFF
_lvl_doors_data27:
		.BYTE	$04,$B0,$04,$70,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$80,$04,$A0,$05
		.WORD	_room_door_always_open
		.BYTE	$04,$30,$04,$D0,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$30,$03,$20,$05
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data27:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_150CD:
		STORE8			_cur_room_sequence_idx,$17
		NJSR			_nsub_628FA
			NARGB		$02,$00,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data28
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data28
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15175
		SJSR			_ssub_62DB1
_sloc_150EE:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$30,$00,$F8,$02
		SBCC			_sloc_150EE
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$84,$63,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1506B
_lvl_doors_data28:
		.BYTE	$00,$30,$02,$E0,$05
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data28:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_15117:
		STORE8			_lvl_data_prg_bank,$02
		STORE16			_lvl_room_lib_ptr,_lvl2_room_lib
		NJSR			_nsub_lvl_data_ptrs_load
			NARGW		_lvl2_macroA_tbl
			NARGW		_lvl2_macroB_tbl
			NARGW		_lvl2_macroC_tbl
			NARGW		_lvl2_macroD_tbl
			NARGW		_lvl2_attrs_tbl
		STORE16			_lvl_collisions_ptr,_lvl_collisions_04
		NJSR			_nsub_full_pal_load
			NARGW		byte_15159
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$10
		NJSR			_nsub_apu_mus_load
			NARGB		$07
		NBG_HNDL_SET	_j_nbgsub_1437C_0
		NJSR			_nsub_ingame_collision_watch_start
		NJSR			_nsub_ingame_player_control_start
		SSCRIPT1_SET	_scr_14324
		STORE16			_lvl_objects_ptr,_lvl2_objects_list
		NJSR			_nsub_lvl_room_objects_init
		SRET
byte_15159:
		.BYTE	$0F,$30,$10,$00,$0F,$19,$10,$17,$0F,$37,$27,$17,$0F,$30,$10,$1A
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$37,$27,$17
byte_15175:
		.BYTE	$0F,$36,$25,$0F
byte_15179:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E =======================================
_j_nbgsub_1437C_0:
		JMP		_lvl_room_objects_handler

; =============== S C R I P T ===============================================
_scr04_lvl4_handler:
		NJSR			_nsub_sub_rom_idx_calc
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJSR			_ssub_154D2
		NJSR			_nsub_room_register
			NARGB		$06
			NARGB		$26,$AE,$01
			NARGB		$3A,$90,$03
			NARGB		$03,$66,$02
			NARGB		$08,$34,$01
			NARGB		$51,$27,$02
			NARGB		$79,$54,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$06
		SCASE			_sjmp_case_151B4
		SCASE			_sjmp_case_151F4
		SCASE			_sjmp_case_152EB
		SCASE			_sjmp_case_15331
		SCASE			_sjmp_case_15388
		SCASE			_sjmp_case_1543A

; =============== S C R I P T ===============================================
_sjmp_case_151B4:
		STORE8			_cur_room_sequence_idx,$00
		NJSR			_nsub_628FA
			NARGB		$02,$01,$05
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data29
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data29
		SJSR			_ssub_62DB1
_sloc_151CB:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$98,$01,$08,$05
		SBCC			_sloc_151CB
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$32,$97,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_151F4
_lvl_doors_data29:
		.BYTE	$01,$A0,$05,$20,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data29:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_151F4:
		STORE8			_cur_room_sequence_idx,$01
		NJSR			_nsub_628FA
			NARGB		$01,$01,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data2A
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data2A
		SJSR			_ssub_62DB1
_sloc_1520B:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$01,$A8,$04
			NARGB		$B0,$01,$08,$03
		SBCC			_sloc_1520B
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$43,$92,$01
			NARGB		$34,$57,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_1524B
		SCASE			_sjmp_case_1528B
_lvl_doors_data2A:
		.BYTE	$01,$90,$04,$D0,$08
		.WORD	_room_door_always_closed
		.BYTE	$01,$E0,$04,$A0,$09
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$B0,$03,$20,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data2A:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1524B:
		STORE8			_cur_room_sequence_idx,$02
		NJSR			_nsub_628FA
			NARGB		$00,$02,$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data2B
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data2B
		SJSR			_ssub_62DB1
_sloc_15262:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$00,$02,$98,$04
		SBCC			_sloc_15262
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$3C,$92,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_151F4
_lvl_doors_data2B:
		.BYTE	$02,$10,$04,$A0,$0A
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data2B:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1528B:
		STORE8			_cur_room_sequence_idx,$03
		NJSR			_nsub_628FA
			NARGB		$00,$00,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data2C
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data2C
		SJSR			_ssub_62DB1
_sloc_152A2:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$03
			NARGB		$B0,$01,$F0,$02
			NARGB		$48,$00,$F0,$02
			NARGB		$50,$00,$08,$02
		SBCC			_sloc_152A2
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$03
			NARGB		$34,$63,$02
			NARGB		$08,$63,$02
			NARGB		$08,$37,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$03
		SCASE			_sjmp_case_151F4
		SCASE			_sjmp_case_152EB
		SCASE			_sjmp_case_15331
_lvl_doors_data2C:
		.BYTE	$01,$B0,$02,$D0,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$50,$02,$D0,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$50,$02,$20,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data2C:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_152EB:
		STORE8			_cur_room_sequence_idx,$04
		NJSR			_nsub_628FA
			NARGB		$01,$00,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data2D
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data2D
		SJSR			_ssub_62DB1
_sloc_15302:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$50,$00,$08,$03
		SBCC			_sloc_15302
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$08,$57,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1528B
_lvl_doors_data2D:
		.BYTE	$00,$50,$03,$20,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data2D:
		.BYTE	$2C,$2C,$2C,$29,$29,$2C,$00

; =============== S C R I P T ===============================================
_sjmp_case_15331:
		STORE8			_cur_room_sequence_idx,$05
		NJSR			_nsub_628FA
			NARGB		$00,$00,$01
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data2E
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data2E
		SJSR			_ssub_62DB1
_sloc_15348:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$50,$00,$F0,$01
			NARGB		$F8,$01,$28,$01
		SBCC			_sloc_15348
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$08,$43,$02
			NARGB		$44,$24,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_1528B
		SCASE			_sjmp_case_15388
_lvl_doors_data2E:
		.BYTE	$00,$50,$01,$D0,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$E0,$01,$30,$10
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$00,$01,$80,$0B
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data2E:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15388:
		STORE8			_cur_room_sequence_idx,$06
		NJSR			_nsub_628FA
			NARGB		$01,$02,$01
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data2F
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data2F
		SJSR			_ssub_62DB1
_sloc_1539F:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$00,$02,$30,$01
			NARGB		$60,$02,$F0,$02
		SBCC			_sloc_1539F
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$3C,$24,$03
			NARGB		$4A,$63,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15331
		SCASE			_sjmp_case_153E1
_lvl_doors_data2F:
		.BYTE	$02,$10,$01,$30,$0C
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$60,$02,$D0,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data2F:
; REGION, changed in the EU version
		.BYTE	$2B,$2B,$2B,$2B,$2D,$2D,$2D,$2D,$2C,$00
;		.BYTE	$2B,$2B,$2B,$2B,$2D,$2D,$2D,$2D,$00
; -

; =============== S C R I P T ===============================================
_sjmp_case_153E1:
		STORE8			_cur_room_sequence_idx,$07
		NJSR			_nsub_628FA
			NARGB		$00,$02,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data30
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data30
		SJSR			_ssub_62DB1
_sloc_153F8:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$60,$02,$08,$03
			NARGB		$C0,$03,$08,$03
		SBCC			_sloc_153F8
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$4A,$57,$00
			NARGB		$76,$57,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15388
		SCASE			_sjmp_case_1543A
_lvl_doors_data30:
		.BYTE	$02,$60,$03,$20,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$C0,$03,$20,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data30:
; REGION, changed in the EU version
		.BYTE	$29,$2D,$29,$2D,$29,$29,$2D,$2D,$2B,$00
;		.BYTE	$29,$2D,$29,$2D,$29,$29,$2D,$2D,$00
; -

; =============== S C R I P T ===============================================
_sjmp_case_1543A:
		STORE8			_cur_room_sequence_idx,$08
		NJSR			_nsub_628FA
			NARGB		$01,$03,$01
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data31
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data31
		SJSR			_ssub_62DB1
_sloc_15451:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$C0,$03,$F0,$02
			NARGB		$28,$03,$08,$01
		SBCC			_sloc_15451
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$76,$64,$02
			NARGB		$63,$17,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_153E1
		SCASE			_sjmp_case_15492
_lvl_doors_data31:
		.BYTE	$03,$C0,$02,$D0,$08
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$20,$01,$20,$0D
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data31:
		.BYTE	$29,$2D,$2D,$2C,$29,$2D,$2C,$2D,$00

; =============== S C R I P T ===============================================
_sjmp_case_15492:
		STORE8			_cur_room_sequence_idx,$09
		NJSR			_nsub_628FA
			NARGB		$02,$03,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data32
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data32
		SJSR			_ssub_62DB1
_sloc_154A9:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$18,$03,$F0,$00
		SBCC			_sloc_154A9
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$63,$23,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_1543A
_lvl_doors_data32:
		.BYTE	$03,$20,$00,$D0,$0D
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data32:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_154D2:
		STORE8			_lvl_data_prg_bank,$05
		NJSR			_nsub_lvl_data_ptrs_load
			NARGW		_lvl3_macroA_tbl
			NARGW		_lvl3_macroB_tbl
			NARGW		_lvl3_macroC_tbl
			NARGW		_lvl3_macroD_tbl
			NARGW		_lvl3_attrs_tbl
		STORE16			_lvl_room_lib_ptr,_lvl3_room_lib
		STORE16			_lvl_collisions_ptr,_lvl_collisions_05
		NJSR			_nsub_full_pal_load
			NARGW		byte_15514
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$12
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$11
		NJSR			_nsub_apu_mus_load
			NARGB		$08
		NBG_HNDL_SET	_nbgsub_15534
		NJSR			_nsub_ingame_collision_watch_start
		NJSR			_nsub_ingame_player_control_start
		SSCRIPT1_SET	_scr_14324
		STORE16			_lvl_objects_ptr,_lvl3_objects_list
		NJSR			_nsub_lvl_room_objects_init
		SRET
byte_15514:
		.BYTE	$0F,$30,$10,$00,$0F,$26,$17,$05,$0F,$37,$17,$08,$0F,$07,$15,$05
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$39,$2C,$0F,$0F,$15,$0F,$0F

; =============== S U B R O U T I N E =======================================
_nbgsub_15534:
		LDA		_nmi_counter
		AND		#$07
		BNE		loc_15558
		LDA		_scr_trds_args0
		ASL
		ASL
		ADC		#<[byte_1555B]
		PHA
		LDA		#$00
		ADC		#>[byte_1555B]
		TAX
		PLA
		LDY		#$03
		JSR		_pal_patch_fade
		INC		_scr_trds_args0
		LDA		_scr_trds_args0
		CMP		#$06
		BCC		loc_15558
		LDA		#$00
		STA		_scr_trds_args0
loc_15558:
		JMP		_lvl_room_objects_handler
byte_1555B:
		.BYTE	$0F,$07,$15,$05,$0F,$05,$07,$15,$0F,$15,$05,$07,$0F,$07,$16,$05
		.BYTE	$0F,$05,$07,$16,$0F,$16,$05,$07

; =============== S C R I P T ===============================================
_scr05_lvl5_handler:
		NJSR			_nsub_sub_rom_idx_calc
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJSR			_ssub_15CDB
		NJSR			_nsub_room_register
			NARGB		$05
			NARGB		$4D,$D4,$00
			NARGB		$98,$92,$02
			NARGB		$08,$93,$01
			NARGB		$23,$29,$02
			NARGB		$94,$34,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$05
		SCASE			_sjmp_case_155A2
		SCASE			_sjmp_case_15691
		SCASE			_sjmp_case_158DB
		SCASE			_sjmp_case_15A91
		SCASE			_sjmp_case_15BE7

; =============== S C R I P T ===============================================
_sjmp_case_155A2:
		STORE8			_cur_room_sequence_idx,$00
		NJSR			_nsub_628FA
			NARGB		$02,$02,$06
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data33
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data33
		SJSR			_ssub_62DB1
_sloc_155B9:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$40,$02,$08,$06
		SBCC			_sloc_155B9
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$46,$B9,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_155E9
_lvl_doors_data33:
		.BYTE	$02,$40,$06,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$40,$06,$D0,$0E
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data33:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_155E9:
		STORE8			_cur_room_sequence_idx,$01
		NJSR			_nsub_628FA
			NARGB		$00,$02,$05
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data34
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data34
		SJSR			_ssub_62DB1
_sloc_15604:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$03,$50,$05
			NARGB		$40,$02,$F8,$05
		SBCC			_sloc_15604
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$83,$A7,$01
			NARGB		$46,$C3,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_1563D
		SCASE			_sjmp_case_155A2
_lvl_doors_data34:
		.BYTE	$02,$40,$05,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$E0,$05,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data34:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1563D:
		STORE8			_cur_room_sequence_idx,$02
		NJSR			_nsub_628FA
			NARGB		$02,$04,$05
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data35
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data35
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0D
		SJSR			_ssub_62DB1
_sloc_15658:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$A8,$04,$08,$05
			NARGB		$00,$04,$48,$05
		SBCC			_sloc_15658
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$94,$99,$00
			NARGB		$7C,$A7,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15691
		SCASE			_sjmp_case_155E9
_lvl_doors_data35:
		.BYTE	$04,$10,$05,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$B0,$05,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data35:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15691:
		STORE8			_cur_room_sequence_idx,$03
		NJSR			_nsub_628FA
			NARGB		$01,$04,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data36
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data36
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_pal_patch_fade
			NARGB		$06
			NARGW		byte_15D35
		SJSR			_ssub_62DB1
_sloc_156B2:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$03
			NARGB		$00,$04,$50,$03
			NARGB		$F8,$04,$50,$03
			NARGB		$B0,$04,$F8,$04
		SBCC			_sloc_156B2
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$03
			NARGB		$7C,$67,$03
			NARGB		$A3,$67,$01
			NARGB		$94,$A3,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$03
		SCASE			_sjmp_case_1573F
		SCASE			_sjmp_case_156FB
		SCASE			_sjmp_case_1563D
_lvl_doors_data36:
		.BYTE	$04,$B0,$04,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$E0,$03,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$10,$03,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data36:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_156FB:
		STORE8			_cur_room_sequence_idx,$04
		NJSR			_nsub_628FA
			NARGB		$02,$05,$03
; REGION, removed in the EU version
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
; -
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_room_doors_data37
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data37
		SJSR			_ssub_62DB1
_sloc_15716:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$00,$05,$50,$03
		SBCC			_sloc_15716
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$9C,$67,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
; NOTE: SJMP_SW		 here has only single case entry, but counter here is $02
; this not cause any bugs, but incorrect.
; FIXME
		SJMP_SW			$02
; -
		SCASE			_sjmp_case_15691
_room_doors_data37:
		.BYTE	$05,$10,$03,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data37:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_1573F:
		STORE8			_cur_room_sequence_idx,$05
		NJSR			_nsub_628FA
			NARGB		$02,$03,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$12
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data38
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data38
		SJSR			_ssub_62DB1
_sloc_1575A:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$03,$50,$03
			NARGB		$B0,$03,$F8,$03
		SBCC			_sloc_1575A
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$83,$67,$01
			NARGB		$74,$83,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15691
		SCASE			_sjmp_case_15793
_lvl_doors_data38:
		.BYTE	$03,$E0,$03,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$B0,$03,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data38:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15793:
		STORE8			_cur_room_sequence_idx,$06
		NJSR			_nsub_628FA
			NARGB		$00,$02,$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data39
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data39
		SJSR			_ssub_62DB1
_sloc_157AA:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$B0,$03,$08,$04
			NARGB		$00,$02,$50,$04
		SBCC			_sloc_157AA
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$74,$79,$00
			NARGB		$3C,$87,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_1573F
		SCASE			_sjmp_case_157E3
_lvl_doors_data39:
		.BYTE	$03,$B0,$04,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$10,$04,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data39:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_157E3:
		STORE8			_cur_room_sequence_idx,$07
		NJSR			_nsub_628FA
			NARGB		$01,$01,$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data3A
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data3A
		SJSR			_ssub_62DB1
_sloc_157FA:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$03
			NARGB		$F8,$01,$50,$04
			NARGB		$B0,$01,$F8,$05
			NARGB		$00,$01,$A0,$05
		SBCC			_sloc_157FA
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$03
			NARGB		$43,$87,$01
			NARGB		$34,$C3,$02
			NARGB		$1C,$B1,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$03
		SCASE			_sjmp_case_15793
		SCASE			_sjmp_case_15843
		SCASE			_sjmp_case_15887
_lvl_doors_data3A:
		.BYTE	$01,$E0,$04,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$B0,$05,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$10,$05,$A0,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data3A:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15843:
		STORE8			_cur_room_sequence_idx,$08
		NJSR			_nsub_628FA
			NARGB		$02,$01,$06
; REGION, removed in the EU version
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$12
; -
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data3B
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data3B
		SJSR			_ssub_62DB1
_sloc_1585E:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$B0,$01,$08,$06
		SBCC			_sloc_1585E
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$34,$B9,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_157E3
_lvl_doors_data3B:
		.BYTE	$01,$B0,$06,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data3B:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15887:
		STORE8			_cur_room_sequence_idx,$09
		NJSR			_nsub_628FA
			NARGB		$02,$00,$05
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$07
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data3C
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data3C
		SJSR			_ssub_62DB1
_sloc_158A2:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$00,$A0,$05
			NARGB		$40,$00,$08,$05
		SBCC			_sloc_158A2
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$23,$B1,$01
			NARGB		$06,$99,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_157E3
		SCASE			_sjmp_case_158DB
_lvl_doors_data3C:
		.BYTE	$00,$40,$05,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$E0,$05,$A0,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data3C:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_158DB:
		STORE8			_cur_room_sequence_idx,$0A
		NJSR			_nsub_628FA
			NARGB		$01,$00,$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_full_pal_load
			NARGW		byte_15D1D
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data3D
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data3D
		SJSR			_ssub_62DB1
_sloc_158FB:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$40,$00,$F8,$04
			NARGB		$F8,$00,$50,$03
		SBCC			_sloc_158FB
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$06,$A3,$02
			NARGB		$23,$67,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15887
		SCASE			_sjmp_case_15934
_lvl_doors_data3D:
		.BYTE	$00,$40,$04,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$E0,$03,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data3D:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15934:
		STORE8			_cur_room_sequence_idx,$0B
		NJSR			_nsub_628FA
			NARGB		$02,$01,$03
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data3E
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data3E
		SJSR			_ssub_62DB1
_sloc_1594B:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$01,$A0,$03
			NARGB		$00,$01,$50,$03
		SBCC			_sloc_1594B
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$43,$71,$01
			NARGB		$1C,$67,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15984
		SCASE			_sjmp_case_158DB
_lvl_doors_data3E:
		.BYTE	$01,$10,$03,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$E0,$03,$A0,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data3E:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15984:
		STORE8			_cur_room_sequence_idx,$0C
		NJSR			_nsub_628FA
			NARGB		$01,$02,$02
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data3F
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data3F
		SJSR			_ssub_62DB1
_sloc_1599F:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$00,$02,$50,$02
			NARGB		$00,$02,$A0,$03
		SBCC			_sloc_1599F
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$3C,$47,$03
			NARGB		$3C,$71,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_159DF
		SCASE			_sjmp_case_15934
_lvl_doors_data3F:
		.BYTE	$02,$10,$03,$A0,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$10,$02,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data3F:
		.BYTE	$19,$18,$19,$19,$19,$18,$18,$00

; =============== S C R I P T ===============================================
_sjmp_case_159DF:
		STORE8			_cur_room_sequence_idx,$0D
		NJSR			_nsub_628FA
			NARGB		$00,$00,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data40
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data40
		SJSR			_ssub_62DB1
_sloc_159F6:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$40,$00,$08,$02
			NARGB		$F8,$01,$50,$02
		SBCC			_sloc_159F6
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$06,$39,$00
			NARGB		$42,$47,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15A37
		SCASE			_sjmp_case_15984
_lvl_doors_data40:
		.BYTE	$01,$E0,$02,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$40,$02,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data40:
		.BYTE	$13,$13,$19,$19,$19,$19,$17,$17,$00

; =============== S C R I P T ===============================================
_sjmp_case_15A37:
		STORE8			_cur_room_sequence_idx,$0E
		NJSR			_nsub_628FA
			NARGB		$02,$00,$01
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15179
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data41
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data41
		SJSR			_ssub_62DB1
_sloc_15A58:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$00,$50,$01
			NARGB		$40,$00,$F8,$01
		SBCC			_sloc_15A58
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$23,$27,$01
			NARGB		$06,$43,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15A91
		SCASE			_sjmp_case_159DF
_lvl_doors_data41:
		.BYTE	$00,$E0,$01,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$00,$40,$01,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data41:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15A91:
		STORE8			_cur_room_sequence_idx,$0F
		NJSR			_nsub_628FA
			NARGB		$00,$01,$01
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15D39
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data42
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data42
		SJSR			_ssub_62DB1
_sloc_15AB2:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$03
			NARGB		$F8,$02,$50,$01
			NARGB		$00,$01,$50,$01
			NARGB		$70,$01,$08,$01
		SBCC			_sloc_15AB2
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$03
			NARGB		$63,$27,$01
			NARGB		$1C,$27,$03
			NARGB		$2C,$19,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$03
		SCASE			_sjmp_case_15B3F
		SCASE			_sjmp_case_15A37
		SCASE			_sjmp_case_15AFB
_lvl_doors_data42:
		.BYTE	$01,$70,$01,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$01,$10,$01,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$02,$E0,$01,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data42:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15AFB:
		STORE8			_cur_room_sequence_idx,$10
		NJSR			_nsub_628FA
			NARGB		$02,$01,$00
; REGION, removed in the EU version
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
; -
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data43
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data43
		SJSR			_ssub_62DB1
_sloc_15B16:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$70,$01,$F8,$00
		SBCC			_sloc_15B16
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$2C,$23,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_15A91
_lvl_doors_data43:
		.BYTE	$01,$70,$00,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data43:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15B3F:
		STORE8			_cur_room_sequence_idx,$11
		NJSR			_nsub_628FA
			NARGB		$01,$03,$01
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data44
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data44
		SJSR			_ssub_62DB1
_sloc_15B5A:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$F8,$03,$A0,$02
			NARGB		$00,$03,$50,$01
		SBCC			_sloc_15B5A
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$83,$51,$01
			NARGB		$5C,$27,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15B93
		SCASE			_sjmp_case_15A91
_lvl_doors_data44:
		.BYTE	$03,$10,$01,$50,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$E0,$02,$A0,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data44:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15B93:
		STORE8			_cur_room_sequence_idx,$12
		NJSR			_nsub_628FA
			NARGB		$02,$04,$02
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data45
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data45
		SJSR			_ssub_62DB1
_sloc_15BAE:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$B0,$04,$08,$02
			NARGB		$00,$04,$A0,$02
		SBCC			_sloc_15BAE
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$94,$39,$00
			NARGB		$7C,$51,$03
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15BE7
		SCASE			_sjmp_case_15B3F
_lvl_doors_data45:
		.BYTE	$04,$10,$02,$A0,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$B0,$02,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data45:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15BE7:
		STORE8			_cur_room_sequence_idx,$13
		NJSR			_nsub_628FA
			NARGB		$02,$04,$01
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0C
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15D3D
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data46
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data46
		SJSR			_ssub_62DB1
_sloc_15C08:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$B0,$04,$08,$01
			NARGB		$B4,$04,$F8,$01
		SBCC			_sloc_15C08
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$94,$19,$00
			NARGB		$94,$43,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15C41
		SCASE			_sjmp_case_15B93
_lvl_doors_data46:
		.BYTE	$04,$B0,$01,$20,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$04,$B0,$01,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data46:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15C41:
		STORE8			_cur_room_sequence_idx,$14
		NJSR			_nsub_628FA
			NARGB		$00,$03,$00
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$18
		NJSR			_nsub_pal_patch_fade
			NARGB		$07
			NARGW		byte_15D39
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data47
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data47
		SJSR			_ssub_62DB1
_sloc_15C62:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$00,$03,$70,$00
			NARGB		$B0,$04,$F8,$00
		SBCC			_sloc_15C62
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$5C,$0C,$03
			NARGB		$94,$23,$02
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15C9B
		SCASE			_sjmp_case_15BE7
_lvl_doors_data47:
		.BYTE	$04,$B0,$00,$D0,$0E
		.WORD	_room_door_gen_clear_open
		.BYTE	$03,$10,$00,$70,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data47:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15C9B:
		STORE8			_cur_room_sequence_idx,$15
		NJSR			_nsub_628FA
			NARGB		$02,$02,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data48
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data48
		SJSR			_ssub_62DB1
_sloc_15CB2:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$01
			NARGB		$F8,$02,$70,$00
		SBCC			_sloc_15CB2
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$63,$0C,$01
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_15C41
_lvl_doors_data48:
		.BYTE	$02,$E0,$00,$70,$0F
		.WORD	_room_door_gen_clear_open
		.BYTE	$FF
_prize_sequence_data48:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_15CDB:
		STORE8			_lvl_data_prg_bank,$05
		STORE16			_lvl_room_lib_ptr,_lvl4_room_lib
		NJSR			_nsub_lvl_data_ptrs_load
			NARGW		_lvl4_macroA_tbl
			NARGW		_lvl4_macroB_tbl
			NARGW		_lvl4_macroC_tbl
			NARGW		_lvl4_macroD_tbl
			NARGW		_lvl4_attrs_tbl
		STORE16			_lvl_collisions_ptr,_lvl_collisions_06
		NJSR			_nsub_full_pal_load
			NARGW		byte_15D1D
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$15
		NBG_HNDL_SET	_j_nbgsub_1437C_1
		NJSR			_nsub_apu_mus_load
			NARGB		$09
		NJSR			_nsub_ingame_collision_watch_start
		NJSR			_nsub_ingame_player_control_start
		SSCRIPT1_SET	_scr_14324
		STORE16			_lvl_objects_ptr,_lvl4_objects_list
		NJSR			_nsub_lvl_room_objects_init
		SRET
byte_15D1D:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$01,$0F,$30,$27,$01,$0F,$30,$15,$07
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15
byte_15D35:
		.BYTE	$0F,$36,$26,$0F
byte_15D39:
		.BYTE	$0F,$36,$26,$0F
byte_15D3D:
		.BYTE	$0F,$36,$27,$0F

; =============== S U B R O U T I N E =======================================
_j_nbgsub_1437C_1:
		JMP		_lvl_room_objects_handler

; =============== S C R I P T ===============================================
_scr06_lvl6_handler:
		NJSR			_nsub_sub_rom_idx_calc
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJSR			_ssub_15DD6
		NJSR			_nsub_room_register
			NARGB		$01
			NARGB		$0E,$73,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$01
		SCASE			_sjmp_case_15D5F

; =============== S C R I P T ===============================================
_sjmp_case_15D5F:
		STORE8			_cur_room_sequence_idx,$00
		NJSR			_nsub_628FA
			NARGB		$01,$00,$02
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data49
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data49
		SJSR			_ssub_62DB1
_sloc_15D76:
		SDELAY			$01
		NJSR			_nsub_6294B
			NARGB		$02
			NARGB		$70,$00,$10,$02
			NARGB		$90,$00,$10,$02
		SBCC			_sloc_15D76
		SJSR			_ssub_62DC5
		NJSR			_nsub_room_register
			NARGB		$02
			NARGB		$0E,$36,$00
			NARGB		$0E,$36,$00
		NJSR			_nsub_read_mem
			NARGW		_sub_room_idx
		SJMP_SW			$02
		SCASE			_sjmp_case_15DA1
		SCASE			_sjmp_case_15DA1
_lvl_doors_data49:
		.BYTE	$FF
_prize_sequence_data49:
		.BYTE	$FF

; =============== S C R I P T ===============================================
_sjmp_case_15DA1:
		STORE8			_cur_room_sequence_idx,$01
		NJSR			_nsub_628FA
			NARGB		$01,$00,$00
		NJSR			_nsub_room_doors_handler_and_data_init
			NARGW		_lvl_doors_data4A
		STORE16			_room_prize_sequence_ptr,_prize_sequence_data4A
		SDELAY			$01
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$DD
		SDELAY			$03
		SLOOP_END
		STORE8			_scr_trds_pause_mode,$00
		NJSR			_nsub_15E3B
		SCRL_Y_MOVE_SET 0,$80,$FF
		SDELAY			$F0
		SDELAY			$F0
		SCRL_MOVE_STOP  0
		STORE8			_cur_room_x_pageB,$00
		SUSPEND
_lvl_doors_data4A:
		.BYTE	$FF
_prize_sequence_data4A:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_15DD6:
		STORE8			_lvl_data_prg_bank,$03
		NJSR			_nsub_lvl_data_ptrs_load
			NARGW		_lvl5_macroA_tbl
			NARGW		_lvl5_macroB_tbl
			NARGW		_lvl5_macroC_tbl
			NARGW		_lvl5_macroD_tbl
			NARGW		_lvl5_macroE_tbl
		STORE16			_lvl_room_lib_ptr,_lvl5_room_lib
		STORE16			_lvl_collisions_ptr,_lvl_collisions_07
		NJSR			_nsub_full_pal_load
			NARGW		byte_15E18
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$17
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$16
		NJSR			_nsub_apu_mus_load
			NARGB		$0A
		NBG_HNDL_SET	_j_nbgsub_1437C_2
		NJSR			_nsub_ingame_collision_watch_start
		NJSR			_nsub_ingame_player_control_start
		SSCRIPT1_SET	_scr_14324
		STORE16			_lvl_objects_ptr,_lvl5_objects_list
		NJSR			_nsub_lvl_room_objects_init
		SRET
byte_15E18:
		.BYTE	$0F,$30,$10,$1B,$0F,$10,$1B,$06,$0F,$26,$17,$07,$0F,$09,$10,$0B
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$17,$0F,$0F,$36,$25,$0F

; =============== S U B R O U T I N E =======================================
_j_nbgsub_1437C_2:
		JMP		_lvl_room_objects_handler

; =============== S U B R O U T I N E =======================================
_nsub_15E3B:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_602DB
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_60FDB
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_15E4A:
		LDA		_scr_trds_pause_mode
		BNE		loc_15E56
		LDA		_pad0_pressed
		AND		#$10
		BEQ		loc_15E56
		SEC
		RTS
loc_15E56:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_unref_0:
		LDA		_pad0_pressed
		AND		#$20
		BEQ		loc_15E65
		LDA		#$80
		STA		_game_flags
		SEC
		RTS
loc_15E65:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_pause_menu_handler:
		LDA		#$FF
		JSR		_far_prg6_apu_mus_load_ex
		LDA		_ppu_scroll_pos_x
		PHA
		LDA		_ppu_scroll_pos_x+1
		PHA
		LDA		_ppu_scroll_pos_y
		PHA
		LDA		_ppu_scroll_pos_y+1
		PHA
		LDA		_cur_room_x_pageA
		PHA
		LDA		_cur_room_y_pageA
		PHA
		LDA		_cur_room_x_pageB
		PHA
		LDA		_cur_room_y_pageB
		PHA
		LDA		#$00
		STA		_ppu_scroll_pos_x
		STA		_ppu_scroll_pos_x+1
		STA		_ppu_scroll_pos_y
		STA		_ppu_scroll_pos_y+1
		LDA		_chr_bank1
		PHA
		LDA		#_tlm1_score_idx
		JSR		_far_prg0_tlm_lib_unpack
		JSR		_nsub_pause_info_display
		JSR		_ppu_res_send_param
		.WORD	_res_pause_pal
loc_15EA2:
		JSR		_wait_for_nmi
		LDA		#$00
		STA		_spr_buf_pos
		STA		_spr_buf_shuffle
		JSR		_pause_menu_anim
		LDA		_pad0_pressed
		AND		#$10
		BEQ		loc_15EA2
		JSR		_full_pal_fade
		JSR		sub_6290C
		PLA
		JSR		_mmc1_chr1_set
		LDY		_near_room_door_data_pos
		BMI		loc_15ED8
		INY
		INY
		INY
		INY
		LDA		(_room_doors_data_ptr),Y
		ASL
		TAY
		LDA		off_15F18,Y
		STA		_ptr06
		LDA		off_15F18+1,Y
		STA		_ptr06+1
		JSR		_jump_ptr_ind
loc_15ED8:
		PLA
		STA		_cur_room_y_pageB
		PLA
		STA		_cur_room_x_pageB
		PLA
		STA		_cur_room_y_pageA
		PLA
		STA		_cur_room_x_pageA
		PLA
		STA		_ppu_scroll_pos_y+1
		PLA
		STA		_ppu_scroll_pos_y
		PLA
		STA		_ppu_scroll_pos_x+1
		PLA
		STA		_ppu_scroll_pos_x
		LDA		_apu_req_idx
		JMP		_far_prg6_apu_mus_load

; =============== S U B R O U T I N E =======================================
_pause_menu_anim:
		LDA		#$00
		STA		_tmpD8
		STA		_tmpD9
		LDA		_beam_player_idxA
		AND		#$F0
		LSR
		LSR
		STA		_tmp0
		LDA		_nmi_counter
		AND		#$0C
		LSR
		LSR
		ADC		_tmp0
		LDX		#$90
		LDY		#$B8
		JMP		_spr_clip_pause_player_insert
off_15F18:
		.WORD	_nsub_16444
		.WORD	_nsub_164DE
		.WORD	_nsub_1655A
		.WORD	_nsub_16602
		.WORD	_nsub_1663E
		.WORD	_nsub_1667D
		.WORD	_nsub_166C4
		.WORD	_nsub_1670B
		.WORD	_nsub_16736
		.WORD	sub_1679C
		.WORD	sub_167A0
		.WORD	sub_167A4
		.WORD	sub_167A8
		.WORD	_nsub_1681A
		.WORD	_nsub_16894
		.WORD	_nsub_16913
		.WORD	_nsub_16855
_res_pause_pal:
		.WORD	$3F00
		.BYTE	$18,$01
		.BYTE	$0F,$31,$11,$01,$0F,$00,$10,$20,$0F,$00,$10,$20,$0F,$00,$10,$20
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15

; =============== S C R I P T ===============================================
_scr_15F56:
		NJSR			_nsub_62CF3
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		STORE8			_apu_var402,$FF
		SDELAY			$10
		STORE8			_scr_trds_pause_mode,$01
		SDELAY			$4B
		NJSR			_nsub_all_threads_off_except_cur
		SDELAY			$2D
		NJSR			_nsub_apu_mus_load
			NARGB		$03
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$05
		NJSR			_nsub_62BB1
			NARGB		$80,$7C
		SPR_IDX_SET		0,$17
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_15FD6
		SDELAY			$78
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask
			NARGB		$FE
		SDELAY			$06
		SLOOP_END
		NJSR			_nsub_far_prg0_tlm_lib_unpack
			NARGB		_tlm1_score_idx
		NJSR			_nsub_pause_info_display
		NJSR			_nsub_bg_pal_load
			NARGW		byte_15FC3
		NJSR			_nsub_scroll_page_set
			NARGB		$00
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$7C,$00
		NBG_HNDL_SET	_nbgsub_15FD3
		SPR_IDX_INC		0
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$05
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$FE
		SDELAY			$06
		SLOOP_END
		SDELAY			$F0
		SJSR			_ssub_pal_fade_out
		STORE8			_game_flags,$80
		SSTOP
byte_15FC3:
		.BYTE	$0F,$30,$0F,$0F,$0F,$30,$10,$00,$0F,$35,$25,$15,$0F,$30,$3B,$2B

; =============== S U B R O U T I N E =======================================
_nbgsub_15FD3:
		JSR		_pause_menu_anim

; =============== S U B R O U T I N E =======================================
_nbgsub_15FD6:
		LDA		_nmi_counter
		AND		#$03
		BNE		locret_15FFD
		LDA		_scr_trds_args0
		ASL
		ASL
		TAY
		LDX		#$00
loc_15FE3:
		LDA		byte_15FFE,Y
		STA		_pal_buf+$1C,X
		INY
		INX
		CPX		#$04
		BCC		loc_15FE3
		JSR		_full_pal_fade
		INC		_scr_trds_args0
		LDA		_scr_trds_args0
		CMP		#$0E
		BCC		locret_15FFD
		LDA		#$00
		STA		_scr_trds_args0
locret_15FFD:
		RTS
byte_15FFE:
		.BYTE	$0F,$06,$0F,$0F
		.BYTE	$0F,$17,$06,$0F
		.BYTE	$0F,$27,$17,$06
		.BYTE	$0F,$37,$27,$17
		.BYTE	$0F,$30,$37,$27
		.BYTE	$0F,$30,$30,$37
		.BYTE	$0F,$37,$30,$30
		.BYTE	$0F,$27,$37,$30
		.BYTE	$0F,$17,$27,$37
		.BYTE	$0F,$06,$17,$27
		.BYTE	$0F,$0F,$06,$17
		.BYTE	$0F,$0F,$0F,$06
		.BYTE	$0F,$0F,$0F,$0F
		.BYTE	$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E =======================================
_nsub_pause_info_display:
		LDA		#$05
		JSR		_mmc1_chr1_set
		JSR		sub_63A73
		LDA		_lives
		LDX		#$00
		JSR		_bin2dec
		LDA		_var3
		BNE		loc_1604E
		LDA		#$20
		BNE		loc_16050
loc_1604E:
		ORA		#$30
loc_16050:
		STA		_tmp_buf+4
		LDA		_var4
		ORA		#$30
		STA		_tmp_buf+5
		LDX		#$15
		LDY		#$16
		JSR		_ppu_offset_calc
		LDX		#$01
		STX		_tmp_buf+3
		INX
		STX		_tmp_buf+2
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		LDA		_hi_scores
		LDX		_hi_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$08
		JSR		_printfd
		LDA		_scores
		LDX		_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$0A
		JMP		_printfd
_spr_raw_lib01_17:
		.BYTE	$10
		.BYTE	$00,$8E,$03,$18
		.BYTE	$00,$8C,$03,$10
		.BYTE	$00,$8A,$03,$08
		.BYTE	$00,$88,$03,$00
		.BYTE	$00,$7E,$03,$F8
		.BYTE	$00,$7C,$03,$F0
		.BYTE	$00,$7A,$03,$E8
		.BYTE	$00,$78,$03,$E0
		.BYTE	$F0,$76,$03,$18
		.BYTE	$F0,$74,$03,$10
		.BYTE	$F0,$72,$03,$08
		.BYTE	$F0,$68,$03,$E0
		.BYTE	$F0,$6A,$03,$E8
		.BYTE	$F0,$6C,$03,$F0
		.BYTE	$F0,$6E,$03,$F8
		.BYTE	$F0,$70,$03,$00
_spr_raw_lib01_18:
		.BYTE	$10
		.BYTE	$00,$8F,$03,$18
		.BYTE	$00,$8D,$03,$10
		.BYTE	$00,$8B,$03,$08
		.BYTE	$00,$89,$03,$00
		.BYTE	$00,$7F,$03,$F8
		.BYTE	$00,$7D,$03,$F0
		.BYTE	$00,$7B,$03,$E8
		.BYTE	$00,$79,$03,$E0
		.BYTE	$F0,$77,$03,$18
		.BYTE	$F0,$75,$03,$10
		.BYTE	$F0,$73,$03,$08
		.BYTE	$F0,$69,$03,$E0
		.BYTE	$F0,$6B,$03,$E8
		.BYTE	$F0,$6D,$03,$F0
		.BYTE	$F0,$6F,$03,$F8
		.BYTE	$F0,$71,$03,$00

; =============== S C R I P T ===============================================
_scr_16111:
		SJSR			_ssub_62DC5
		NJSR			_nsub_all_threads_off_except_cur
		NJSR			_nsub_far_prg0_tlm_lib_unpack
			NARGB		_tlm3_game_over_idx
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$05
		NJSR			_nsub_full_pal_load
			NARGW		byte_16176
		NJSR			_nsub_scroll_page_set
			NARGB		$00
		NJSR			_nsub_game_over_draw
		SJSR			_ssub_pal_fade_in
		STORE8			_apu_var402,$FF
		NJSR			_nsub_apu_mus_load
			NARGB		$02
		NJSR			_nsub_mcmp
			NARGW		_continues
			NARGB		$00
		SBCS			_sloc_16162
		POS_X_SET		0,$58,$00
		SSCRIPT1_SET	_scr_1616A
_sloc_16146:
		POS_X_DELTA_SET 0,$00,$01
		SPR_IDX_SET		0,$15
		SLOOP_BEGIN		$50
		NJSR			_nsub_161F3
		SDELAY			$01
		SLOOP_END
		POS_X_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		0
		SLOOP_BEGIN		$50
		NJSR			_nsub_161F3
		SDELAY			$01
		SLOOP_END
		SJMP			_sloc_16146
_sloc_16162:
		SDELAY			$F0
		SDELAY			$3C
		SJSR			_ssub_pal_fade_out
		SSTOP

; =============== S C R I P T ===============================================
_scr_1616A:
		SDELAY			$01
		NJSR			_nsub_16213
		SBCC			_scr_1616A
		SJSR			_ssub_pal_fade_out
		SSTOP
byte_16176:
		.BYTE	$0F,$30,$15,$03,$0F,$30,$10,$0F,$0F,$37,$27,$17,$0F,$0F,$0F,$0F
		.BYTE	$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$31,$12,$0F,$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E =======================================
_nsub_game_over_draw:
		LDA		_lvl_room_checkpoint_idx
		STA		_lvl_room_cur_idx
		LDA		_hi_scores
		LDX		_hi_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$04
		JSR		_printfd
		LDA		_scores
		LDX		_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$06
		JSR		_printfd
		DEC		_continues
		BEQ		loc_161E3
		LDA		_continues
		ORA		#$30
		STA		_tmp_buf+4
		LDA		#$01
		STA		_tmp_buf+2
		STA		_tmp_buf+3
		LDX		#$14
		LDY		#$12
		JSR		_ppu_offset_calc
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		LDA		#$01
		STA		_game_flags
		RTS
loc_161E3:
		JSR		_ppu_res_send_param_repeat
		.WORD	word_161EE
		LDA		#$00
		STA		_game_flags
		RTS
word_161EE:
		.WORD	$224B
		.BYTE	$0A,$05
		.BYTE	$20

; =============== S U B R O U T I N E =======================================
_nsub_161F3:
		LDA		_pad0_pressed
		AND		#$2C
		BEQ		loc_16201
		LDA		_game_flags
		EOR		#$01
		STA		_game_flags
loc_16201:
		LDX		_scr_cur_trd_idx
		LDY		_game_flags
		LDA		byte_16211,Y
		STA		_scr_trds_y_pos_lo,X
		LDA		#$00
		STA		_scr_trds_y_pos_hi,X
		RTS
byte_16211:
		.BYTE	$AD,$8D

; =============== S U B R O U T I N E =======================================
_nsub_16213:
		LDA		_pad0_pressed
		AND		#$10
		BEQ		loc_1621B
		SEC
		RTS
loc_1621B:
		CLC
		RTS
_spr_raw_lib01_15:
		.BYTE	$07
		.BYTE	$F0,$3B,$22,$00
		.BYTE	$00,$3D,$22,$08
		.BYTE	$00,$3F,$22,$00
		.BYTE	$00,$0F,$22,$F0
		.BYTE	$00,$1F,$22,$F8
		.BYTE	$F0,$0D,$22,$F0
		.BYTE	$F0,$1D,$22,$F8
_spr_raw_lib01_16:
		.BYTE	$07
		.BYTE	$00,$3D,$62,$F0
		.BYTE	$00,$3F,$62,$F8
		.BYTE	$F0,$3B,$62,$F8
		.BYTE	$00,$1F,$62,$00
		.BYTE	$00,$0F,$62,$08
		.BYTE	$F0,$0D,$62,$08
		.BYTE	$F0,$1D,$62,$00

; =============== S C R I P T ===============================================
_scr0C_room_doors_handler:
		NBG_HNDL_SET	_nbgsub_room_doors_data_load
		NJSR			_nsub_room_door_exit_allow_test
		SBCC			_sloc_16284
		SJSR_SW	$11
		SCASE			_sjsr_case_1641B
		SCASE			_sjsr_case_164BE
		SCASE			_sjsr_case_16536
		SCASE			_sjsr_case_165E0
		SCASE			_sjsr_case_1661E
		SCASE			_sjsr_case_1665D
		SCASE			_sjsr_case_166A4
		SCASE			_sjsr_case_166EB
		SCASE			_sjsr_case_16716
		SCASE			_sjsr_case_1675D
		SCASE			_sjsr_case_167CA
		SCASE			_sjsr_case_167DA
		SCASE			_sjsr_case_167EA
		SCASE			_sjsr_case_167FA
		SCASE			_sjsr_case_16870
		SCASE			_sjsr_case_168ED
		SCASE			_sjsr_case_16835
_sloc_16284:
		SDELAY			$01
		NJSR			_nsub_room_door_exit_allow_test
		SBCC			_sloc_16284
		SJSR_SW	$11
		SCASE			_sjsr_case_16421
		SCASE			_sjsr_case_164C4
		SCASE			_sjsr_case_1653C
		SCASE			_sjsr_case_165E6
		SCASE			_sjsr_case_16624
		SCASE			_sjsr_case_16663
		SCASE			_sjsr_case_166AA
		SCASE			_sjsr_case_166F1
		SCASE			_sjsr_case_1671C
		SCASE			_sjsr_case_16766
		SCASE			_sjsr_case_167D0
		SCASE			_sjsr_case_167E0
		SCASE			_sjsr_case_167F0
		SCASE			_sjsr_case_16800
		SCASE			_sjsr_case_16876
		SCASE			_sjsr_case_168F3
		SCASE			_sjsr_case_1683B
		SJMP			_sloc_16284

; =============== S U B R O U T I N E =======================================
_nbgsub_room_doors_data_load:
		LDX		_cur_room_doors_cnt
		LDY		#$00
loc_162B8:
		LDA		(_room_doors_data_ptr),Y
		BMI		loc_162F7
		CPY		_near_room_door_data_pos
		BEQ		loc_162F0
		STA		_obj_door_x_lo_poss+1,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_door_x_hi_poss+1,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_doors_y_lo_poss+1,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_doors_y_hi_poss+1,X
		INY
		TYA
		PHA
		LDA		(_room_doors_data_ptr),Y
		TAY
		LDA		_obj_doors_widths_list,Y
		STA		_obj_doors_widths+1,X
		LDA		_obj_doors_heights_list,Y
		STA		_obj_doors_heights+1,X
		PLA
		TAY
		INY
		INY
		INY
		INX
		BNE		loc_162B8
loc_162F0:
		TYA
		CLC
		ADC		#$07
		TAY
		BNE		loc_162B8
loc_162F7:
		STX		_cur_room_doors_cnt
		RTS
_obj_doors_widths_list:
		.BYTE	$10,$04,$10,$04,$08,$10,$10,$10,$10,$04,$04,$04,$04,$04,$10,$04
		.BYTE	$04
_obj_doors_heights_list:
		.BYTE	$0F,$10,$04,$10,$0F,$0F,$0F,$0F,$0F,$10,$10,$10,$10,$08,$0F,$10
		.BYTE	$10

; =============== S U B R O U T I N E =======================================
_nsub_room_doors_handler_and_data_init:
		JSR		_scr_getc
		STA		_room_doors_data_ptr
		JSR		_scr_getc
		STA		_room_doors_data_ptr+1
		LDA		#$FF
		STA		_near_room_door_data_pos
		STA		_scr_trds_idx+1
		LDA		#$01
		STA		_var4
		LDA		#$02
		STA		_var5
		LDA		#$0C
		JMP		_thread_lib_load

; =============== S U B R O U T I N E =======================================
_nsub_room_door_exit_allow_test:
		LDA		#$00
		STA		_near_room_door_data_pos
loc_16341:
		LDY		_near_room_door_data_pos
		LDA		(_room_doors_data_ptr),Y
		BMI		loc_16366
		JSR		_room_door_screen_pos_calc
		BCS		loc_1635B
		LDA		#$02
		JSR		_obj_to_room_door_distance_test
		BCC		loc_1636B
		LDA		#$04
		JSR		_obj_to_room_door_distance_test
		BCC		loc_1636B
loc_1635B:
		LDA		_near_room_door_data_pos
		CLC
		ADC		#$07
		STA		_near_room_door_data_pos
		BNE		loc_16341
loc_16366:
		STA		_near_room_door_data_pos
		CLC
		RTS
loc_1636B:
		TYA
		PHA
		LDY		_near_room_door_data_pos
		INY
		INY
		INY
		INY
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_ptr06
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_ptr06+1
		PLA
		TAY
		JSR		_jump_ptr_ind
		BCC		loc_1635B
		LDX		_scr_cur_trd_idx
		LDY		_near_room_door_data_pos
		LDA		(_room_doors_data_ptr),Y
		STA		_scr_trds_x_pos_hi,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_scr_trds_x_pos_lo,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_scr_trds_y_pos_hi,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_scr_trds_y_pos_lo,X
		INY
		LDA		(_room_doors_data_ptr),Y
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_players_to_near_room_door_distance_test:
		JSR		_near_room_door_screen_pos_calc
		LDA		#$02
		JSR		_obj_to_room_door_distance_test
		BCC		locret_163B3
		LDA		#$04
		JSR		_obj_to_room_door_distance_test
locret_163B3:
		RTS

; =============== S U B R O U T I N E =======================================
_obj_to_room_door_distance_test:
		STA		_tmp0
		TXA
		PHA
		TYA
		PHA
		LDX		_tmp0
		JSR		_obj_screen_pos_calc
		STX		_tmp1
		STY		_tmp2
		PLA
		TAY
		PLA
		TAX
		BCS		locret_163E0
		SBC		_tmp1
		BCS		loc_163D1
		EOR		#$FF
		ADC		#$01
loc_163D1:
		CMP		#$20
		BCS		locret_163E0
		TYA
		SBC		_tmp2
		BCS		loc_163DE
		EOR		#$FF
		ADC		#$01
loc_163DE:
		CMP		#$20
locret_163E0:
		RTS

; =============== S U B R O U T I N E =======================================
_near_room_door_screen_pos_calc:
		LDY		_near_room_door_data_pos
		LDA		(_room_doors_data_ptr),Y

; =============== S U B R O U T I N E =======================================
_room_door_screen_pos_calc:
		STA		_tmp_var0
		INY
		LDA		(_room_doors_data_ptr),Y
		TAX
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_tmp_var1
		INY
		LDA		(_room_doors_data_ptr),Y
		TAY
		JMP		_screen_pos_calc_ex

; =============== S U B R O U T I N E =======================================
_room_door_always_open:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_room_door_always_closed:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_room_door_gen_clear_open:
		STX		_tmp1
		LDX		#$06
loc_16400:
		LDA		_scr_trds_idx,X
		BMI		loc_16409
		CMP		#$13
		BCS		loc_16419
loc_16409:
		INX
		CPX		#$0E
		BCC		loc_16400
		LDX		_tmp1
		LDA		#$02
		JSR		_obj_to_room_door_distance_test
		BCS		loc_16419
		SEC
		RTS
loc_16419:
		CLC
		RTS

; =============== S C R I P T  S U B R O U T I N E ==========================

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1641B:
		NJSR			_nsub_16444
		SJMP			_sloc_1642C

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16421:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16444
		SPR_IDX_SET		6,$00
		SPR_IDX_SET		0,$FF
_sloc_1642C:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$00
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_1644F
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_1643B:
		SDELAY			$01
		NJSR			_nsub_players_to_near_room_door_distance_test
		SBCC			_ssub_1643B
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_16444:
		LDA		#<[byte_1644B]
		LDX		#>[byte_1644B]
		JMP		sub_1645A
byte_1644B:
		.BYTE	$14,$14,$14,$14

; =============== S U B R O U T I N E =======================================
_nsub_1644F:
		LDA		#<[byte_16456]
		LDX		#>[byte_16456]
		JMP		sub_1645A
byte_16456:
		.BYTE	$0A,$1A,$0B,$1B

; =============== S U B R O U T I N E =======================================
sub_1645A:
		STA		_ptr06
		STX		_ptr06+1
		LDY		#$03
loc_16460:
		TYA
		PHA
		LDA		_ptr06
		PHA
		LDA		_ptr06+1
		PHA
		LDA		(_ptr06),Y
		PHA
		LDA		_scr_trds_x_pos_lo+1
		CLC
		ADC		byte_1649D,Y
		PHA
		LDA		_scr_trds_x_pos_hi+1
		ADC		byte_164A1,Y
		STA		_tmp_var0
		LDA		_scr_trds_y_pos_lo+1
		CLC
		ADC		byte_164A5,Y
		PHA
		LDA		_scr_trds_y_pos_hi+1
		ADC		byte_164A9,Y
		STA		_tmp_var1
		PLA
		TAY
		PLA
		TAX
		PLA
		JSR		_ppu_macro_block_draw
		PLA
		STA		_ptr06+1
		PLA
		STA		_ptr06
		PLA
		TAY
		DEY
		BPL		loc_16460
		RTS
byte_1649D:
		.BYTE	$F0,$00,$F0,$00
byte_164A1:
		.BYTE	$FF,$00,$FF,$00
byte_164A5:
		.BYTE	$F0,$F0,$00,$00
byte_164A9:
		.BYTE	$FF,$FF,$00,$00
_spr_raw_lib01_00:
		.BYTE	$04
		.BYTE	$F0,$31,$43,$08
		.BYTE	$00,$33,$43,$08
		.BYTE	$00,$33,$03,$F0
		.BYTE	$F0,$31,$03,$F0

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_164BE:
		NJSR			_nsub_164DE
		SJMP			_sloc_164CF

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_164C4:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_164DE
		SPR_IDX_SET		6,$01
		SPR_IDX_SET		0,$FF
_sloc_164CF:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$01
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_164E7
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_164DE:
		LDA		#<[byte_164E5]
		LDX		#>[byte_164E5]
		JMP		sub_164F0
byte_164E5:
		.BYTE	$00,$00

; =============== S U B R O U T I N E =======================================
_nsub_164E7:
		LDA		#<[byte_164EE]
		LDX		#>[byte_164EE]
		JMP		sub_164F0
byte_164EE:
		.BYTE	$29,$29

; =============== S U B R O U T I N E =======================================
sub_164F0:
		STA		_ptr06
		STX		_ptr06+1
		LDY		#$01
loc_164F6:
		TYA
		PHA
		LDA		_ptr06
		PHA
		LDA		_ptr06+1
		PHA
		LDA		(_ptr06),Y
		PHA
		LDX		_scr_trds_x_pos_lo+1
		LDA		_scr_trds_x_pos_hi+1
		STA		_tmp_var0
		LDA		_scr_trds_y_pos_lo+1
		CLC
		ADC		byte_16529,Y
		PHA
		LDA		_scr_trds_y_pos_hi+1
		ADC		byte_1652B,Y
		STA		_tmp_var1
		PLA
		TAY
		PLA
		JSR		_ppu_macro_block_draw
		PLA
		STA		_ptr06+1
		PLA
		STA		_ptr06
		PLA
		TAY
		DEY
		BPL		loc_164F6
		RTS
byte_16529:
		.BYTE	$F0,$00
byte_1652B:
		.BYTE	$FF,$00
_spr_raw_lib01_01:
		.BYTE	$02
		.BYTE	$F0,$EF,$83,$00
		.BYTE	$00,$EF,$03,$00

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16536:
		NJSR			_nsub_1655A
		SJMP			_sloc_16549

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1653C:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_1655A
		SPR_IDX_SET		2,$02
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_SET		0,$FF
_sloc_16549:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		2,$04
		SPR_IDX_DEC		2
		SPR_IDX_DEC		2
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_16583
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_1655A:
		LDY		#$01
loc_1655C:
		TYA
		PHA
		LDA		_scr_trds_x_pos_lo+1
		CLC
		ADC		byte_1657F,Y
		TAX
		LDA		_scr_trds_x_pos_hi+1
		ADC		byte_16581,Y
		STA		_tmp_var0
		LDY		_scr_trds_y_pos_lo+1
		LDA		_scr_trds_y_pos_hi+1
		STA		_tmp_var1
		LDA		#$14
		JSR		_ppu_macro_block_draw
		PLA
		TAY
		DEY
		BPL		loc_1655C
		RTS
byte_1657F:
		.BYTE	$F0,$00
byte_16581:
		.BYTE	$FF,$00

; =============== S U B R O U T I N E =======================================
_nsub_16583:
		LDY		#$03
loc_16585:
		TYA
		PHA
		LDA		byte_165AB,Y
		PHA
		LDA		_scr_trds_x_pos_lo+1
		CLC
		ADC		byte_1657F,Y
		TAX
		LDA		_scr_trds_x_pos_hi+1
		ADC		byte_16581,Y
		STA		_tmp_var0
		LDY		_scr_trds_y_pos_lo+1
		LDA		_scr_trds_y_pos_hi+1
		STA		_tmp_var1
		PLA
		JSR		_ppu_macro_block_draw
		PLA
		TAY
		DEY
		BPL		loc_16585
		RTS
byte_165AB:
		.BYTE	$0B,$1B
_spr_raw_lib01_02:
		.BYTE	$06
		.BYTE	$0B,$F9,$43,$00
		.BYTE	$0B,$F9,$43,$F8
		.BYTE	$0B,$F9,$03,$F0
		.BYTE	$F8,$FB,$03,$00
		.BYTE	$F8,$EB,$03,$F8
		.BYTE	$F8,$DB,$03,$F0
_spr_raw_lib01_03:
		.BYTE	$04
		.BYTE	$0B,$F9,$03,$F8
		.BYTE	$0B,$F9,$03,$F0
		.BYTE	$F8,$DD,$03,$F8
		.BYTE	$F8,$CD,$03,$F0
_spr_raw_lib01_04:
		.BYTE	$02
		.BYTE	$0B,$F9,$03,$F0
		.BYTE	$F4,$CB,$03,$F1

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_165E0:
		NJSR			_nsub_16602
		SJMP			_sloc_165F2

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_165E6:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16602
		SPR_IDX_SET		3,$05
		SPR_IDX_INC		3
		SPR_IDX_SET		0,$FF
_sloc_165F2:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		3,$06
		SPR_IDX_DEC		3
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_1660B
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_16602:
		LDA		#<[byte_16609]
		LDX		#>[byte_16609]
		JMP		sub_164F0
byte_16609:
		.BYTE	$2C,$14

; =============== S U B R O U T I N E =======================================
_nsub_1660B:
		LDA		#<[byte_16612]
		LDX		#>[byte_16612]
		JMP		sub_164F0
byte_16612:
		.BYTE	$D3,$D2

_spr_raw_lib01_05:
		.BYTE	$01
		.BYTE	$00,$D9,$03,$FF
_spr_raw_lib01_06:
		.BYTE	$01
		.BYTE	$00,$E9,$03,$FF

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1661E:
		NJSR			_nsub_1663E
		SJMP			_sloc_1662F

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16624:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_1663E
		SPR_IDX_SET		6,$07
		SPR_IDX_SET		0,$FF
_sloc_1662F:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$07
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_16649
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_1663E:
		LDA		#<[byte_16645]
		LDX		#>[byte_16645]
		JMP		sub_1645A
byte_16645:
		.BYTE	$87,$97,$88,$98

; =============== S U B R O U T I N E =======================================
_nsub_16649:
		LDA		#<[byte_16650]
		LDX		#>[byte_16650]
		JMP		sub_1645A
byte_16650:
		.BYTE	$D4,$D6,$D5,$D7

_spr_raw_lib01_07:
		.BYTE	$02
		.BYTE	$F0,$AF,$40,$F8
		.BYTE	$00,$8B,$40,$F8

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1665D:
		NJSR			_nsub_1667D
		SJMP			_sloc_1666E

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16663:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_1667D
		SPR_IDX_SET		6,$08
		SPR_IDX_SET		0,$FF
_sloc_1666E:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$08
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_16688
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_1667D:
		LDA		#<[byte_16684]
		LDX		#>[byte_16684]
		JMP		sub_1645A
byte_16684:
		.BYTE	$01,$01,$01,$01

; =============== S U B R O U T I N E =======================================
_nsub_16688:
		LDA		#<[byte_1668F]
		LDX		#>[byte_1668F]
		JMP		sub_1645A
byte_1668F:
		.BYTE	$0A,$1A,$0B,$1B
_spr_raw_lib01_08:
		.BYTE	$04
		.BYTE	$00,$43,$02,$08
		.BYTE	$F0,$41,$02,$08
		.BYTE	$F0,$41,$42,$F0
		.BYTE	$00,$43,$42,$F0

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_166A4:
		NJSR			_nsub_166C4
		SJMP			_sloc_166B5

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_166AA:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_166C4
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF
_sloc_166B5:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$0A
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_166CF
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_166C4:
		LDA		#<[byte_166CB]
		LDX		#>[byte_166CB]
		JMP		sub_1645A
byte_166CB:
		.BYTE	$00,$00,$00,$00

; =============== S U B R O U T I N E =======================================
_nsub_166CF:
		LDA		#<[byte_166D6]
		LDX		#>[byte_166D6]
		JMP		sub_1645A
byte_166D6:
		.BYTE	$40,$50,$41,$51
_spr_raw_lib01_09:
		.BYTE	$04
		.BYTE	$00,$23,$02,$08
		.BYTE	$F0,$21,$02,$08
		.BYTE	$00,$33,$02,$F0
		.BYTE	$F0,$31,$02,$F0

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_166EB:
		NJSR			_nsub_1670B
		SJMP			_sloc_166FC

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_166F1:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_1670B
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF
_sloc_166FC:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_166CF
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_1670B:
		LDA		#<[byte_16712]
		LDX		#>[byte_16712]
		JMP		sub_1645A
byte_16712:
		.BYTE	$26,$26,$26,$26

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16716:
		NJSR			_nsub_16736
		SJMP			_sloc_16727

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1671C:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16736
		SPR_IDX_SET		6,$0A
		SPR_IDX_SET		0,$FF
_sloc_16727:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$0A
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_16741
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_16736:
		LDA		#<[byte_1673D]
		LDX		#>[byte_1673D]
		JMP		sub_1645A
byte_1673D:
		.BYTE	$20,$20,$96,$97

; =============== S U B R O U T I N E =======================================
_nsub_16741:
		LDA		#<[byte_16748]
		LDX		#>[byte_16748]
		JMP		sub_1645A
byte_16748:
		.BYTE	$8B,$8D,$8C,$8E
_spr_raw_lib01_0A:
		.BYTE	$04
		.BYTE	$00,$CF,$00,$08
		.BYTE	$00,$CF,$00,$00
		.BYTE	$00,$CF,$00,$F0
		.BYTE	$00,$CF,$00,$F8

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1675D:
		SARG_SET		SARG0,$00
_sloc_16760:
		NJSR			_nsub_16787
		SJMP			_sloc_16774

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16766:
		SARG_SET		SARG0,$00
_sloc_16769:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16787
		SPR_IDX_SET		6,$0B
		SPR_IDX_SET		0,$FF
_sloc_16774:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$0B
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_167AC
		SRET
byte_16783:
		.BYTE	$17,$98
byte_16785:
		.BYTE	$95,$91

; =============== S U B R O U T I N E =======================================
_nsub_16787:
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_args0,X

; =============== S U B R O U T I N E =======================================
sub_1678B:
		LDA		off_16794,Y
		LDX		off_16798,Y
		JMP		sub_164F0
off_16794:
		.BYTE	<[byte_16783]
		.BYTE	<[byte_167D6]
		.BYTE	<[byte_167E6]
		.BYTE	<[byte_167F6]
off_16798:
		.BYTE	>[byte_16783]
		.BYTE	>[byte_167D6]
		.BYTE	>[byte_167E6]
		.BYTE	>[byte_167F6]

; =============== S U B R O U T I N E =======================================
sub_1679C:
		LDY		#$00
		BEQ		sub_1678B

; =============== S U B R O U T I N E =======================================
sub_167A0:
		LDY		#$01
		BNE		sub_1678B

; =============== S U B R O U T I N E =======================================
sub_167A4:
		LDY		#$02
		BNE		sub_1678B

; =============== S U B R O U T I N E =======================================
sub_167A8:
		LDY		#$03
		BNE		sub_1678B

; =============== S U B R O U T I N E =======================================
_nsub_167AC:
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_args0,X
		LDA		off_167B9,Y
		LDX		off_167BD,Y
		JMP		sub_164F0
off_167B9:
		.BYTE	<[byte_16785]
		.BYTE	<[byte_167D8]
		.BYTE	<[byte_167E8]
		.BYTE	<[byte_167F8]
off_167BD:
		.BYTE	>[byte_16785]
		.BYTE	>[byte_167D8]
		.BYTE	>[byte_167E8]
		.BYTE	>[byte_167F8]
_spr_raw_lib01_0B:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$00
		.BYTE	$00,$DF,$00,$00

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167CA:
		SARG_SET		SARG0,$01
		SJMP			_sloc_16760

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167D0:
		SARG_SET		SARG0,$01
		SJMP			_sloc_16769
byte_167D6:
		.BYTE	$4E,$98
byte_167D8:
		.BYTE	$99,$91

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167DA:
		SARG_SET		SARG0,$02
		SJMP			_sloc_16760

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167E0:
		SARG_SET		SARG0,$02
		SJMP			_sloc_16769
byte_167E6:
		.BYTE	$51,$9B
byte_167E8:
		.BYTE	$8F,$9A

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167EA:
		SARG_SET		SARG0,$03
		SJMP			_sloc_16760

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167F0:
		SARG_SET		SARG0,$03
		SJMP			_sloc_16769
byte_167F6:
		.BYTE	$22,$98
byte_167F8:
		.BYTE	$90,$91

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_167FA:
		NJSR			_nsub_1681A
		SJMP			_sloc_1680B

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16800:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_1681A
		SPR_IDX_SET		6,$0C
		SPR_IDX_SET		0,$FF
_sloc_1680B:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$0C
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_16823
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_1681A:
		LDA		#<[byte_16821]
		LDX		#>[byte_16821]
		JMP		sub_164F0
byte_16821:
		.BYTE	$20,$96

; =============== S U B R O U T I N E =======================================
_nsub_16823:
		LDA		#<[byte_1682A]
		LDX		#>[byte_1682A]
		JMP		sub_164F0
byte_1682A:
		.BYTE	$8B,$8C
_spr_raw_lib01_0C:
		.BYTE	$02
		.BYTE	$00,$CF,$00,$08
		.BYTE	$00,$CF,$00,$00

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16835:
		NJSR			_nsub_16855
		SJMP			_sloc_16846

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_1683B:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16855
		SPR_IDX_SET		6,$0D
		SPR_IDX_SET		0,$FF
_sloc_16846:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		6,$0D
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_1685E
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_16855:
		LDA		#<[byte_1685C]
		LDX		#>[byte_1685C]
		JMP		sub_164F0
byte_1685C:
		.BYTE	$22,$9E

; =============== S U B R O U T I N E =======================================
_nsub_1685E:
		LDA		#<[byte_16865]
		LDX		#>[byte_16865]
		JMP		sub_164F0
byte_16865:
		.BYTE	$9C,$9D

_spr_raw_lib01_0D:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$08
		.BYTE	$00,$DF,$00,$08

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16870:
		NJSR			_nsub_16894
		SJMP			_sloc_16883

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_16876:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16894
		SPR_IDX_SET		1,$0E
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_SET		0,$FF
_sloc_16883:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		1,$10
		SPR_IDX_DEC		1
		SPR_IDX_DEC		1
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_1689F
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_16894:
		LDA		#<[byte_1689B]
		LDX		#>[byte_1689B]
		JMP		sub_1645A
byte_1689B:
		.BYTE	$14,$14,$55,$55

; =============== S U B R O U T I N E =======================================
_nsub_1689F:
		LDA		#<[byte_168A6]
		LDX		#>[byte_168A6]
		JMP		sub_1645A
byte_168A6:
		.BYTE	$0A,$1A,$0B,$1B
_spr_raw_lib01_0E:
		.BYTE	$08
		.BYTE	$F0,$7D,$00,$08
		.BYTE	$F0,$7D,$00,$00
		.BYTE	$F0,$7D,$00,$F8
		.BYTE	$F0,$7D,$00,$F0
		.BYTE	$00,$7F,$00,$F0
		.BYTE	$00,$7F,$00,$08
		.BYTE	$00,$7F,$00,$00
		.BYTE	$00,$7F,$00,$F8
_spr_raw_lib01_0F:
		.BYTE	$04
		.BYTE	$00,$6F,$00,$08
		.BYTE	$00,$6F,$00,$00
		.BYTE	$00,$6F,$00,$F8
		.BYTE	$00,$6F,$00,$F0
_spr_raw_lib01_10:
		.BYTE	$04
		.BYTE	$00,$7D,$00,$08
		.BYTE	$00,$7D,$00,$00
		.BYTE	$00,$7D,$00,$F8
		.BYTE	$00,$7D,$00,$F0

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_168ED:
		NJSR			_nsub_16913
		SJMP			_sloc_16901

; =============== S C R I P T  S U B R O U T I N E ==========================
_sjsr_case_168F3:
		NJSR			_nsub_apu_snd_load
			NARGB		$07
		NJSR			_nsub_16913
		SPR_IDX_SET		2,$11
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_SET		0,$FF
_sloc_16901:
		SJSR			_ssub_1643B
		NJSR			_nsub_apu_snd_load
			NARGB		$06
		SPR_IDX_SET		2,$14
		SPR_IDX_DEC		2
		SPR_IDX_DEC		2
		SPR_IDX_DEC		2
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_1691C
		SRET

; =============== S U B R O U T I N E =======================================
_nsub_16913:
		LDA		#<[byte_1691A]
		LDX		#>[byte_1691A]
		JMP		sub_164F0
byte_1691A:
		.BYTE	$00,$00

; =============== S U B R O U T I N E =======================================
_nsub_1691C:
		LDA		#<[byte_16923]
		LDX		#>[byte_16923]
		JMP		sub_164F0
byte_16923:
		.BYTE	$29,$29
_spr_raw_lib01_11:
		.BYTE	$02
		.BYTE	$F4,$5F,$00,$00
		.BYTE	$00,$5F,$00,$00
_spr_raw_lib01_12:
		.BYTE	$02
		.BYTE	$F8,$5D,$00,$00
		.BYTE	$00,$5D,$00,$00
_spr_raw_lib01_13:
		.BYTE	$02
		.BYTE	$FC,$5D,$00,$00
		.BYTE	$00,$5D,$00,$00
_spr_raw_lib01_14:
		.BYTE	$01
		.BYTE	$00,$6D,$00,$00

; =============== S C R I P T ===============================================
_scr0D_money_bag:
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_sjmp_case_16966

_spr_unref:
		.BYTE	$02
		.BYTE	$F8,$BB,$00,$00
		.BYTE	$F8,$AB,$00,$F8
_spr_unref_0:
		.BYTE	$01
		.BYTE	$F8,$BF,$00,$FC
_spr_unref_1:
		.BYTE	$01
		.BYTE	$F8,$AF,$00,$FC
_spr_unref_2:
		.BYTE	$01
		.BYTE	$F8,$BF,$40,$FC

; =============== S C R I P T ===============================================
_sjmp_case_16966:
		SARG_SET		SARG0,$00
_sloc_16969:
		SDELAY			$01
		NJSR			_nsub_prize_sequence_completed_test
		SBCC			_sloc_16969
		SARG_SET		SARG2,$1E
		NBG_HNDL_SET	_nbgsub_money_bag_collision_test
_sloc_16977:
		SPR_IDX_SET		2,$19
		SPR_IDX_INC		2
		SJMP			_sloc_16977

; =============== S U B R O U T I N E =======================================
_nbgsub_money_bag_collision_test:
		LDX		#$0D
		LDY		#$0E
		JMP		_money_prize_collision_test

; =============== S U B R O U T I N E =======================================
_nsub_prize_sequence_completed_test:
		LDA		_room_prize_sequence_ptr
		ORA		_room_prize_sequence_ptr+1
		BNE		loc_1698C
		SEC
		RTS
loc_1698C:
		CLC
		RTS
_spr_raw_lib01_19:
		.BYTE	$02
		.BYTE	$F8,$BD,$00,$00
		.BYTE	$F8,$AD,$00,$F8
_spr_raw_lib01_1A:
		.BYTE	$02
		.BYTE	$F8,$BD,$01,$00
		.BYTE	$F8,$AD,$01,$F8
_spr_raw_lib01:
		.WORD	_spr_raw_lib01_00
		.WORD	_spr_raw_lib01_01
		.WORD	_spr_raw_lib01_02
		.WORD	_spr_raw_lib01_03
		.WORD	_spr_raw_lib01_04
		.WORD	_spr_raw_lib01_05
		.WORD	_spr_raw_lib01_06
		.WORD	_spr_raw_lib01_07
		.WORD	_spr_raw_lib01_08
		.WORD	_spr_raw_lib01_09
		.WORD	_spr_raw_lib01_0A
		.WORD	_spr_raw_lib01_0B
		.WORD	_spr_raw_lib01_0C
		.WORD	_spr_raw_lib01_0D
		.WORD	_spr_raw_lib01_0E
		.WORD	_spr_raw_lib01_0F
		.WORD	_spr_raw_lib01_10
		.WORD	_spr_raw_lib01_11
		.WORD	_spr_raw_lib01_12
		.WORD	_spr_raw_lib01_13
		.WORD	_spr_raw_lib01_14
		.WORD	_spr_raw_lib01_15
		.WORD	_spr_raw_lib01_16
		.WORD	_spr_raw_lib01_17
		.WORD	_spr_raw_lib01_18
		.WORD	_spr_raw_lib01_19
		.WORD	_spr_raw_lib01_1A

_lvl0_objects_list:
		.BYTE	$FF,$02
		OBJ_SET	_scr13_slow_moving_slime,			$30,$02,$88,$03,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$70,$03,$98,$03,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$A0,$03,$78,$03,_NON,_NON,_NON
		OBJ_SET	_scr17_runner,						$D0,$03,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$70,$03,$A0,$03,$01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AD,$02,_NON
		.BYTE	$FF,$01,$02
		OBJ_SET	_scr1C_girl_and_floaters,			$90,$04,$E0,$02,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AF,$03,_NON
		.BYTE	$FF,$01,$03
		.BYTE	$FF,$02
		OBJ_SET	_scr17_runner,						$A8,$03,$C0,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr18_chain_saw,					$C8,$03,$70,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr18_chain_saw,					$50,$03,$40,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr18_chain_saw,					$10,$03,$60,$02,_NON,_NON,_NON
; -
; REGION, changed in the EU version
		OBJ_SET	_scr13_slow_moving_slime,			$70,$02,$A0,$02,_NON,_NON,_NON
;		OBJ_SET	_scr13_slow_moving_slime,			$90,$02,$A0,$02,_NON,_NON,_NON
;
		OBJ_SET	_scr14_fast_moving_slime,			$D0,$02,$48,$02,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$80,$02,$50,$02,$01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AF,$04,_NON
		.BYTE	$FF,$01,$04
		OBJ_SET	_scr19_toilet_snake,				$78,$01,$50,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr13_slow_moving_slime,			$C8,$01,$68,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AD,$03,_NON
		.BYTE	$FF,$01,$03
		OBJ_SET	_scr13_slow_moving_slime,			$60,$02,$70,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr14_fast_moving_slime,			$A0,$02,$70,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AE,$00,_NON
		.BYTE	$FF,$01,$00
		OBJ_SET	_scr13_slow_moving_slime,			$98,$02,$A8,$03,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr14_fast_moving_slime,			$78,$02,$98,$03,_NON,_NON,_NON
; -
		OBJ_SET	_scr17_runner,						$80,$02,$48,$03,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AF,$01,_NON
		.BYTE	$FF,$01,$01
		.BYTE	$FF,$02
		OBJ_SET	_scr15_trolley_kick_slime,			$08,$01,$80,$03,_NON,_NON,_NON
		OBJ_SET	_scr16_still_throw_forward_slime,	$B8,$00,$A0,$03,_NON,_NON,_NON
		OBJ_SET	_scr16_still_throw_forward_slime,	$80,$00,$50,$03,_NON,_NON,_NON
		OBJ_SET	_scr16_still_throw_forward_slime,	$60,$00,$B0,$03,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$48,$01,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$40,$01,$B8,$03,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$B8,$01,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$A0,$01,$B8,$03,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$B0,$00,$60,$03,$01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AD,$00,_NON
		.BYTE	$FF,$01,$00
		OBJ_SET	_scr18_chain_saw,					$78,$02,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr18_chain_saw,					$B8,$02,$88,$03,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr18_chain_saw,					$88,$02,$98,$03,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AC,$03,_NON
		.BYTE	$FF,$01,$03
		OBJ_SET	_scr17_runner,						$48,$02,$C8,$02,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$A8,$02,$88,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr17_runner,						$C8,$02,$C8,$02,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$58,$02,$68,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,$AC,$05,_NON
		.BYTE	$FF,$01,$06
		.BYTE	$FF,$02
; REGION, added in the EU version
;		.BYTE	_scr12_exit_arrow,					$00,$00,$00,$00,$AC,$05,_NON
; -
		.BYTE	$FF,$01,$05
		OBJ_SET	_scr1B_court_chair,					$78,$02,$78,$01,$00,_NON,_NON
		OBJ_SET	_scr1B_court_chair,					$B8,$02,$58,$01,$01,_NON,_NON
		OBJ_SET	_scr1B_court_chair,					$48,$02,$58,$01,$02,_NON,_NON
		OBJ_SET	_scr1B_court_chair,					$68,$02,$38,$01,$03,_NON,_NON
		OBJ_SET	_scr1A_lvl1_boss_judges,			$80,$02,$40,$00,$00,_NON,_NON
		.BYTE	$FF,$00
_lvl_collisions_00:
		.BYTE	$FF,$FC,$FB,$F3,$03,$DB,$03,$F7,$03,$F8,$0F,$FF,$7E,$FF,$7E,$7F
		.BYTE	$01,$00,$01,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl_collisions_01:
		.BYTE	$FC,$F7,$F8,$FB,$0C,$CE,$0F,$FF,$0B,$00,$07,$00,$F7,$00,$FB,$02
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_unused_11:
		.BYTE	$7F,$CE,$F7,$CF,$BC,$2E,$B3,$2C,$00,$00,$00,$04,$FE,$8F,$FC,$EC ;	*--
		.BYTE	$2F,$E0,$3E,$7F,$F8,$FD,$F4,$FF,$FF,$FF,$00,$03,$00,$00,$00,$00
_lvl0_macroA_tbl:
		.BYTE	$FF,$11,$12,$13,$05,$06,$08,$09,$1A,$00,$20,$22,$26,$28,$10,$24
		.BYTE	$00,$01,$02,$03,$15,$10,$00,$1A,$0A,$00,$20,$42,$46,$48,$09,$09
		.BYTE	$1F,$1C,$00,$55,$55,$6D,$FF,$1C,$15,$0E,$10,$2D,$2F,$2F,$6B,$26
		.BYTE	$4A,$15,$2B,$6F,$FF,$FF,$05,$28,$15,$5A,$09,$15,$2D,$2D,$1C,$05
		.BYTE	$15,$15,$15,$15,$64,$65,$65,$26,$3D,$67,$69,$1C,$1C,$15,$05,$6C
		.BYTE	$71,$72,$72,$15,$6A,$68,$67,$46,$5F,$26,$15,$67,$15,$05,$05,$15
		.BYTE	$0D,$26,$29,$5B,$46,$49,$FF,$1D,$0C,$FF,$FF,$4E,$11,$60,$01,$00
		.BYTE	$05,$36,$39,$5C,$39,$5C,$3D,$15,$FF,$FF,$7D,$7D,$0B,$70,$0A,$0C
		.BYTE	$2D,$45,$28,$6A,$04,$7D,$04,$24,$04,$14,$02,$1A,$2A,$40,$0A,$2C
		.BYTE	$63,$7D,$36,$38,$08,$46,$46,$7D,$6A,$15,$46,$7D,$76,$66,$18,$0C
		.BYTE	$00,$00,$0A,$10,$01,$7D,$7D,$7D,$18,$56,$66,$18,$56,$46,$0C,$0C
		.BYTE	$00,$00,$00,$00,$15,$01,$20,$FF,$1F,$09,$09,$00,$00,$05,$09,$97
		.BYTE	$60,$70,$05,$19,$05,$05,$00,$10,$10,$15,$0E,$3E,$00,$0D,$09,$97
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$60,$70
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl0_macroB_tbl:
		.BYTE	$FF,$00,$00,$05,$05,$16,$18,$00,$1A,$00,$30,$32,$36,$38,$4B,$34
		.BYTE	$00,$FF,$FF,$FF,$15,$FF,$00,$0A,$1A,$00,$30,$52,$56,$58,$FF,$00
		.BYTE	$1F,$15,$00,$55,$55,$7D,$15,$15,$15,$FF,$1F,$2D,$2D,$2D,$7B,$46
		.BYTE	$05,$15,$3A,$5A,$FF,$15,$05,$48,$15,$15,$00,$15,$3F,$3F,$15,$1A
		.BYTE	$15,$61,$62,$15,$74,$75,$74,$36,$5E,$15,$15,$68,$67,$15,$05,$7C
		.BYTE	$15,$1C,$1C,$15,$7A,$15,$15,$FF,$2A,$5C,$15,$69,$15,$05,$05,$44
		.BYTE	$05,$5C,$39,$5B,$26,$29,$4B,$15,$05,$4D,$4F,$15,$00,$7D,$FF,$00
		.BYTE	$05,$5C,$39,$46,$49,$5C,$5F,$15,$00,$4B,$7D,$7D,$FF,$FF,$1A,$1C
		.BYTE	$3D,$7D,$36,$7D,$6A,$04,$04,$04,$14,$24,$12,$2A,$3A,$40,$1A,$3C
		.BYTE	$73,$75,$36,$7D,$76,$15,$76,$7D,$7D,$76,$08,$46,$7D,$18,$56,$0C
		.BYTE	$00,$00,$FF,$00,$34,$7D,$7D,$7D,$76,$66,$18,$56,$66,$18,$0C,$0C
		.BYTE	$00,$00,$00,$00,$15,$00,$30,$FF,$FF,$FF,$4B,$09,$09,$87,$00,$05
		.BYTE	$7D,$FF,$05,$05,$05,$05,$00,$4B,$0E,$15,$1E,$15,$09,$87,$00,$05
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$7D,$00
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl0_macroC_tbl:
		.BYTE	$FF,$10,$13,$14,$05,$07,$15,$10,$1B,$1F,$21,$23,$27,$29,$10,$25
		.BYTE	$0C,$10,$03,$04,$15,$10,$05,$1B,$0B,$05,$41,$43,$47,$49,$10,$FF
		.BYTE	$1F,$1D,$55,$55,$6C,$6E,$15,$1C,$44,$0F,$10,$2D,$2E,$2D,$05,$29
		.BYTE	$4B,$15,$2C,$7F,$FF,$1D,$26,$29,$15,$5B,$05,$FF,$2D,$2D,$6B,$6A
		.BYTE	$15,$15,$15,$15,$65,$66,$65,$27,$15,$68,$15,$1C,$1C,$6B,$6A,$6D
		.BYTE	$72,$72,$73,$6B,$3D,$69,$77,$47,$15,$27,$15,$77,$78,$0C,$15,$45
		.BYTE	$0D,$28,$2D,$15,$48,$2D,$FF,$15,$0D,$FF,$4D,$4F,$60,$61,$01,$7D
		.BYTE	$05,$38,$2D,$5D,$2D,$5D,$15,$1C,$FF,$FF,$7D,$7D,$70,$71,$0B,$0D
		.BYTE	$44,$7D,$29,$6B,$05,$7D,$05,$25,$05,$7E,$03,$1B,$2A,$40,$2B,$2D
		.BYTE	$64,$7D,$37,$39,$57,$47,$46,$6A,$6A,$67,$47,$7D,$77,$57,$57,$7D
		.BYTE	$2C,$1C,$01,$01,$01,$65,$7D,$55,$57,$57,$57,$57,$57,$47,$7D,$65
		.BYTE	$62,$7D,$7D,$0D,$15,$01,$FF,$39,$1F,$1F,$1F,$05,$05,$05,$97,$97
		.BYTE	$60,$70,$1E,$05,$05,$19,$05,$10,$10,$15,$0F,$3F,$0C,$0D,$97,$97
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$7D,$7D
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl0_macroD_tbl:
		.BYTE	$FF,$4A,$05,$05,$05,$17,$15,$4A,$1B,$1F,$31,$33,$37,$39,$4C,$35
		.BYTE	$05,$FF,$FF,$FF,$15,$FF,$05,$0B,$1B,$54,$51,$53,$57,$59,$FF,$4A
		.BYTE	$1F,$15,$55,$55,$7C,$7E,$FF,$15,$15,$FF,$1F,$2D,$2D,$2D,$05,$49
		.BYTE	$05,$3C,$3B,$55,$FF,$FF,$46,$49,$45,$1D,$05,$15,$3E,$2D,$5A,$5A
		.BYTE	$60,$61,$63,$70,$74,$76,$74,$37,$15,$78,$15,$69,$77,$7B,$7A,$7D
		.BYTE	$1C,$1C,$1D,$7B,$5F,$15,$78,$FF,$15,$79,$68,$78,$15,$05,$15,$15
		.BYTE	$05,$5D,$2D,$15,$28,$2D,$4C,$15,$05,$4E,$15,$15,$7D,$7D,$FF,$7D
		.BYTE	$05,$5D,$2D,$48,$2D,$5D,$15,$15,$4A,$4C,$7D,$7D,$FF,$FF,$1B,$1D
		.BYTE	$54,$7D,$37,$7D,$6B,$05,$05,$05,$7E,$25,$13,$2A,$3B,$40,$3B,$3D
		.BYTE	$74,$7D,$37,$7D,$77,$67,$76,$7D,$7D,$77,$57,$47,$6A,$67,$57,$55
		.BYTE	$3C,$7D,$FF,$1D,$35,$7D,$55,$65,$77,$67,$57,$09,$57,$57,$7D,$7D
		.BYTE	$72,$1C,$0D,$7D,$15,$1D,$FF,$39,$FF,$FF,$4C,$05,$87,$87,$05,$05
		.BYTE	$7D,$FF,$05,$05,$19,$05,$19,$0E,$0F,$2E,$1F,$2F,$87,$87,$54,$05
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$7D,$7D
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl0_attrs_tbl:
		.BYTE	$00,$00,$00,$03,$00,$01,$03,$00,$00,$00,$02,$02,$02,$02,$00,$03
		.BYTE	$00,$00,$00,$00,$03,$00,$00,$00,$00,$00,$02,$02,$02,$02,$00,$00
		.BYTE	$00,$03,$00,$00,$00,$00,$02,$03,$03,$02,$00,$03,$03,$03,$03,$02
		.BYTE	$00,$03,$02,$00,$00,$02,$00,$00,$03,$03,$00,$03,$03,$03,$03,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$00,$03,$03,$03,$03,$03,$03,$03,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$00,$03,$00,$03,$03,$03,$00,$00,$00
		.BYTE	$00,$02,$02,$03,$02,$02,$00,$03,$00,$03,$03,$03,$00,$03,$00,$00
		.BYTE	$01,$02,$02,$02,$02,$02,$03,$03,$00,$00,$03,$02,$00,$03,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$01,$01,$01,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$00,$00,$02,$00,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$00,$00,$00,$00,$01,$00,$02,$02,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$03,$03,$00,$00,$00,$00,$00,$00,$00,$01,$02,$01,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$03,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl_room_lib00:
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	byte_17062
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	byte_17152
		.WORD	byte_17AB2
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	byte_17242
		.WORD	byte_17332
		.WORD	byte_17422
		.WORD	byte_17512
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	byte_17602
		.WORD	byte_176F2
		.WORD	byte_177E2
		.WORD	byte_178D2
		.WORD	byte_179C2
		.WORD	$0000		; *--
		.WORD	$0000		; *--
		.WORD	$0000		; *--
byte_17062:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$A3,$6F,$A0,$B0,$A1,$B2,$A0,$B0,$B3,$B1,$A0,$B0,$6F,$A2,$00
		.BYTE	$00,$A4,$89,$86,$89,$86,$89,$86,$89,$86,$89,$86,$89,$86,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$A7,$A6,$A5,$A7,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$AD,$AC,$AB,$AA,$A9,$A8,$97,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$88,$87,$88,$87,$88,$87,$83,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$AE,$AE,$9F,$AF,$AE,$AE,$AE,$AE,$9F,$AF,$AE,$AE,$6E,$00
		.BYTE	$00,$6E,$7B,$9B,$9E,$9D,$9C,$7B,$7B,$9B,$9E,$9D,$9C,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$85,$88,$87,$84,$7B,$7B,$85,$88,$87,$84,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$96,$97,$7B,$80,$90,$7B,$7B,$96,$97,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$9A,$99,$98,$7B,$81,$91,$7B,$7B,$95,$94,$97,$6E,$00
		.BYTE	$00,$6E,$7B,$88,$87,$83,$7B,$7B,$7B,$7B,$7B,$88,$87,$83,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$8A,$8A,$8A,$8A,$7B,$7B,$7B,$8A,$6E,$00
		.BYTE	$00,$6E,$7B,$82,$92,$92,$92,$92,$92,$92,$92,$92,$93,$7B,$6E,$00
byte_17152:
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$8A,$7B,$8A,$8A,$8A,$8A,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$8A,$8A,$7B,$7B,$8A,$8A,$7B,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$8A,$7B,$7B,$8A,$8A,$8A,$8A,$7B,$7B,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$8A,$8A,$7B,$8A,$7B,$8A,$8A,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$B5,$6F,$6F,$6F,$6F,$6F,$0A,$1A,$6F,$6F,$6F,$6F,$6F,$6E,$00
		.BYTE	$00,$A4,$89,$86,$89,$86,$89,$0B,$1B,$89,$86,$89,$86,$89,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$C9,$B4,$B4,$CB,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$CA,$8B,$8C,$B4,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6C,$6F,$6F,$6F,$6F,$6F,$8B,$8C,$6F,$6F,$6F,$6F,$6F,$7C,$00
		.BYTE	$00,$6D,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$7D,$00
byte_17242:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$01,$16
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$0E,$C5
		.BYTE	$00,$00,$00,$00,$01,$22,$22,$22,$22,$22,$22,$22,$22,$C6,$1E,$14
		.BYTE	$00,$00,$00,$00,$0E,$23,$23,$24,$23,$33,$23,$23,$20,$68,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$26,$26,$25,$26,$26,$26,$26,$08,$35,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$26,$26,$26,$26,$26,$26,$26,$26,$26,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$26,$26,$26,$26,$26,$47,$57,$26,$26,$15,$14
		.BYTE	$00,$00,$00,$00,$07,$BC,$0A,$1A,$BE,$16,$16,$16,$16,$C6,$1E,$14
		.BYTE	$00,$00,$00,$00,$0E,$BD,$0B,$1B,$BF,$C3,$70,$C2,$C4,$70,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$14,$2F,$77,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$00,$00,$00,$00,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$16,$16,$16,$C6,$3A,$16,$16,$C6,$07,$16,$16,$C6,$16,$16,$07,$C6
		.BYTE	$C3,$C2,$04,$C5,$C3,$05,$C4,$04,$0E,$C5,$05,$04,$C3,$70,$0E,$04
byte_17332:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$01,$16,$09,$10,$C6,$BC,$0A,$1A,$BE,$C6,$16,$16,$16,$16,$07
		.BYTE	$00,$0E,$C5,$17,$60,$05,$BD,$0B,$1B,$BF,$04,$C2,$C5,$C3,$05,$0E
		.BYTE	$C6,$1E,$14,$18,$21,$06,$14,$14,$14,$14,$14,$14,$14,$14,$06,$15
		.BYTE	$68,$15,$14,$0F,$38,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15
		.BYTE	$35,$15,$14,$40,$14,$38,$39,$14,$14,$14,$39,$14,$43,$14,$14,$15
		.BYTE	$26,$15,$14,$41,$50,$14,$14,$14,$14,$14,$14,$14,$44,$77,$14,$15
		.BYTE	$26,$15,$14,$41,$51,$14,$14,$14,$14,$14,$14,$14,$46,$27,$14,$15
		.BYTE	$C6,$1E,$14,$41,$51,$14,$53,$14,$14,$14,$14,$14,$46,$27,$14,$15
		.BYTE	$70,$15,$14,$41,$51,$14,$54,$21,$14,$39,$14,$14,$46,$27,$14,$15
		.BYTE	$14,$15,$14,$42,$52,$14,$14,$14,$14,$14,$14,$14,$45,$21,$14,$02
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$03
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14
		.BYTE	$16,$07,$C6,$09,$09,$09,$CC,$0A,$1A,$CE,$09,$09,$09,$09,$10,$07
		.BYTE	$70,$0E,$04,$17,$08,$18,$CD,$0B,$1B,$CF,$08,$18,$17,$18,$60,$0E
byte_17422:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$16,$16,$C6,$16,$16,$C6,$16,$16,$16,$07,$C6,$16,$16,$16,$07,$16
		.BYTE	$04,$C3,$04,$C5,$04,$C3,$04,$C2,$C5,$0E,$C4,$04,$C3,$C5,$0E,$C3
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$14,$14,$14,$14,$29,$14
		.BYTE	$14,$14,$0C,$1C,$77,$14,$0C,$1C,$77,$15,$14,$14,$14,$14,$29,$14
		.BYTE	$14,$14,$0D,$1D,$21,$28,$0D,$1D,$21,$15,$14,$01,$BC,$21,$07,$C6
		.BYTE	$14,$14,$14,$38,$14,$14,$38,$14,$14,$15,$14,$0E,$BD,$14,$0E,$05
		.BYTE	$14,$14,$31,$14,$28,$0F,$28,$14,$14,$15,$14,$15,$14,$14,$15,$06
		.BYTE	$14,$28,$32,$14,$38,$14,$28,$2F,$77,$15,$14,$15,$28,$14,$15,$49
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$28,$14,$15,$14,$15,$14,$38,$15,$4A
		.BYTE	$16,$C6,$16,$16,$C6,$BC,$0A,$1A,$BE,$12,$14,$15,$14,$14,$15,$14
		.BYTE	$C4,$C2,$C3,$04,$C5,$BD,$0B,$1B,$BF,$13,$14,$15,$14,$14,$15,$28
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$59,$57,$15,$14
		.BYTE	$16,$16,$16,$16,$C6,$16,$16,$07,$C6,$16,$16,$3A,$16,$C6,$1E,$14
		.BYTE	$04,$C4,$C3,$C2,$C5,$04,$C4,$0E,$04,$04,$C3,$C4,$04,$04,$15,$14
byte_17512:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$16,$07,$16,$C6,$16,$16,$16,$16,$C6,$16,$16,$C6,$16,$16,$11,$00
		.BYTE	$C5,$0E,$C3,$04,$C3,$04,$C2,$C4,$04,$C5,$04,$C3,$04,$C4,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$28,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$21,$07,$C6,$16,$09,$09,$09,$09,$10,$C6,$BC,$0A,$1A,$BE,$1E,$00
		.BYTE	$14,$0E,$05,$C5,$08,$17,$08,$08,$60,$05,$BD,$0B,$1B,$BF,$15,$00
		.BYTE	$14,$15,$06,$14,$08,$18,$17,$18,$21,$06,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$49,$38,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$4A,$14,$28,$0F,$28,$14,$14,$14,$14,$14,$14,$31,$15,$00
		.BYTE	$38,$15,$14,$14,$38,$14,$28,$14,$14,$14,$14,$28,$14,$32,$15,$00
		.BYTE	$14,$15,$28,$14,$14,$38,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$28,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$57,$15,$14,$14,$14,$14,$14,$14,$28,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$C6,$1E,$14,$38,$14,$14,$38,$14,$14,$14,$14,$14,$14,$14,$15,$00
byte_17602:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$01,$16,$C6,$16,$16,$16,$C6,$16,$16,$C6,$16,$16,$16,$16,$07
		.BYTE	$00,$C7,$5E,$5D,$C2,$C4,$05,$04,$C4,$04,$04,$C3,$04,$C4,$05,$0E
		.BYTE	$00,$C8,$4F,$27,$14,$14,$06,$39,$14,$53,$14,$14,$47,$57,$06,$15
		.BYTE	$00,$C8,$4E,$27,$2E,$77,$38,$14,$56,$54,$21,$14,$48,$58,$38,$15
		.BYTE	$00,$C8,$2F,$21,$04,$27,$14,$14,$14,$38,$14,$14,$14,$56,$14,$07
		.BYTE	$00,$C8,$27,$14,$04,$27,$0F,$14,$28,$14,$14,$14,$14,$14,$14,$0E
		.BYTE	$00,$C8,$3E,$14,$04,$27,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29
		.BYTE	$00,$C8,$3F,$27,$04,$27,$14,$14,$5A,$14,$28,$14,$56,$14,$14,$29
		.BYTE	$00,$C8,$2E,$27,$04,$27,$14,$14,$47,$57,$14,$14,$14,$28,$14,$07
		.BYTE	$00,$C8,$4E,$27,$54,$21,$38,$4D,$48,$58,$14,$14,$55,$14,$14,$0E
		.BYTE	$00,$2A,$20,$3B,$38,$14,$14,$54,$55,$14,$14,$14,$59,$57,$14,$15
		.BYTE	$00,$02,$C6,$16,$16,$16,$16,$16,$C6,$16,$16,$C6,$16,$16,$16,$3A
		.BYTE	$00,$03,$04,$C4,$C2,$04,$C3,$C5,$04,$04,$04,$C4,$C3,$04,$04,$C2
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
byte_176F2:
		.BYTE	$00,$00,$00,$00,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$16,$16,$16,$C6,$3A,$16,$16,$C6,$07,$16,$16,$C6,$16,$16,$07,$C6
		.BYTE	$C3,$C2,$04,$C5,$C3,$05,$C4,$04,$0E,$C5,$05,$04,$C3,$70,$0E,$04
		.BYTE	$14,$31,$0F,$38,$14,$06,$0C,$1C,$15,$14,$06,$38,$2F,$77,$15,$14
		.BYTE	$14,$32,$28,$14,$14,$14,$0D,$1D,$15,$28,$14,$14,$14,$14,$15,$14
		.BYTE	$BC,$14,$14,$BE,$16,$C6,$16,$16,$3A,$BC,$14,$14,$BE,$C6,$1E,$14
		.BYTE	$BD,$21,$14,$BF,$05,$C5,$C2,$05,$C3,$BD,$21,$14,$BF,$C2,$15,$14
		.BYTE	$14,$14,$14,$14,$06,$14,$14,$06,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$16,$C6,$16,$BC,$14,$14,$BE,$07,$BC,$14,$14,$BE,$16,$16,$1E,$14
		.BYTE	$C4,$05,$C4,$BD,$21,$14,$BF,$0E,$BD,$21,$14,$BF,$C5,$C3,$15,$14
		.BYTE	$21,$06,$2F,$77,$14,$14,$14,$15,$14,$14,$28,$14,$14,$14,$15,$14
		.BYTE	$16,$16,$16,$16,$16,$16,$C6,$3A,$16,$16,$16,$16,$16,$16,$3A,$16
		.BYTE	$C4,$04,$C3,$04,$04,$C4,$04,$04,$04,$C5,$04,$04,$04,$C5,$04,$04
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
byte_177E2:
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14
		.BYTE	$16,$07,$C6,$09,$09,$09,$CC,$0A,$1A,$CE,$09,$09,$09,$09,$10,$07
		.BYTE	$70,$0E,$04,$17,$08,$18,$CD,$0B,$1B,$CF,$08,$18,$17,$18,$60,$0E
		.BYTE	$14,$15,$14,$18,$17,$18,$21,$14,$14,$14,$17,$08,$18,$17,$21,$15
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$28,$14,$14,$14,$14,$14,$14,$14,$15
		.BYTE	$C6,$1E,$14,$61,$75,$64,$75,$73,$61,$71,$64,$75,$73,$14,$14,$B9
		.BYTE	$C2,$15,$14,$62,$72,$65,$72,$74,$62,$72,$65,$72,$74,$27,$14,$B8
		.BYTE	$14,$29,$14,$63,$63,$63,$63,$63,$63,$63,$63,$63,$63,$67,$14,$14
		.BYTE	$14,$29,$14,$14,$38,$0F,$38,$14,$14,$14,$28,$14,$14,$14,$14,$14
		.BYTE	$16,$1E,$14,$40,$14,$28,$14,$14,$14,$14,$14,$38,$43,$14,$14,$1E
		.BYTE	$C3,$15,$14,$41,$50,$14,$14,$14,$14,$38,$14,$14,$44,$77,$14,$15
		.BYTE	$14,$15,$14,$42,$52,$14,$39,$14,$14,$14,$14,$14,$45,$21,$14,$15
		.BYTE	$16,$3A,$16,$C6,$16,$16,$BC,$0A,$1A,$BE,$16,$16,$C6,$16,$16,$3A
		.BYTE	$C5,$04,$04,$C5,$04,$C2,$BD,$0B,$1B,$BF,$04,$C5,$04,$C3,$04,$C5
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
byte_178D2:
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$59,$57,$15,$14
		.BYTE	$16,$16,$16,$16,$C6,$16,$16,$07,$C6,$16,$16,$3A,$16,$C6,$1E,$14
		.BYTE	$04,$C4,$C3,$C2,$C5,$04,$C4,$0E,$04,$04,$C3,$C4,$04,$04,$15,$14
		.BYTE	$14,$14,$14,$14,$38,$14,$14,$15,$14,$14,$14,$14,$14,$14,$15,$14
		.BYTE	$14,$14,$01,$BC,$14,$14,$14,$B9,$14,$BE,$C6,$11,$14,$14,$15,$28
		.BYTE	$14,$14,$0E,$BD,$21,$14,$31,$B8,$14,$BF,$C2,$15,$14,$14,$15,$14
		.BYTE	$14,$14,$15,$14,$14,$14,$32,$14,$14,$14,$14,$15,$14,$14,$15,$14
		.BYTE	$14,$14,$15,$14,$14,$38,$14,$14,$14,$39,$14,$15,$14,$14,$15,$14
		.BYTE	$14,$14,$15,$14,$14,$14,$14,$28,$14,$14,$14,$15,$14,$28,$07,$C6
		.BYTE	$14,$14,$15,$14,$0C,$1C,$77,$14,$0C,$1C,$77,$15,$14,$14,$0E,$04
		.BYTE	$14,$14,$15,$14,$0D,$1D,$21,$14,$0D,$1D,$21,$15,$14,$14,$29,$14
		.BYTE	$14,$14,$15,$14,$38,$14,$14,$14,$14,$14,$14,$15,$14,$14,$29,$14
		.BYTE	$16,$C6,$3A,$C6,$16,$16,$16,$C6,$16,$16,$16,$3A,$16,$C6,$3A,$16
		.BYTE	$04,$C4,$04,$04,$C2,$04,$04,$C5,$C3,$04,$04,$C4,$04,$04,$C2,$C3
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
byte_179C2:
		.BYTE	$04,$15,$14,$14,$14,$14,$14,$14,$14,$28,$14,$14,$14,$28,$15,$00
		.BYTE	$14,$15,$14,$14,$28,$14,$14,$28,$0F,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$38,$14,$14,$28,$14,$56,$14,$15,$00
		.BYTE	$14,$15,$14,$38,$14,$38,$14,$14,$14,$14,$14,$31,$14,$14,$15,$00
		.BYTE	$14,$15,$28,$14,$14,$14,$14,$14,$14,$14,$14,$32,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$14,$38,$14,$14,$14,$14,$14,$14,$28,$14,$5A,$15,$00
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$5B,$15,$00
		.BYTE	$28,$07,$C6,$16,$C6,$16,$16,$16,$16,$C6,$BC,$0A,$1A,$BE,$1E,$00
		.BYTE	$14,$0E,$04,$04,$C5,$C3,$04,$C2,$C3,$04,$BD,$0B,$1B,$BF,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$C6,$3A,$16,$16,$C6,$16,$16,$16,$16,$16,$16,$16,$C6,$16,$12,$00
		.BYTE	$04,$C2,$C3,$04,$C3,$C4,$04,$04,$C5,$C3,$04,$04,$04,$C5,$13,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
byte_17AB2:
		.BYTE	$00,$6E,$7B,$8A,$8A,$7B,$8A,$7B,$8A,$8A,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$B5,$6F,$6F,$6F,$6F,$6F,$0A,$1A,$6F,$6F,$6F,$6F,$6F,$6E,$00
		.BYTE	$00,$A4,$89,$86,$89,$86,$89,$0B,$1B,$89,$86,$89,$86,$89,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$C9,$B4,$B4,$CB,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$CA,$8B,$8C,$B4,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6C,$6F,$6F,$6F,$6F,$6F,$8B,$8C,$6F,$6F,$6F,$6F,$6F,$7C,$00
		.BYTE	$00,$C0,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$C1,$00
		.BYTE	$6F,$DE,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$DF,$6F
		.BYTE	$7A,$7A,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$7A,$7A
		.BYTE	$B4,$B4,$B4,$B4,$B4,$B4,$B4,$8B,$8C,$CB,$C9,$B4,$B4,$B4,$B4,$B4
		.BYTE	$B4,$B4,$B4,$B4,$B4,$B4,$CB,$B4,$B4,$B4,$CA,$B4,$B4,$B4,$B4,$B4
		.BYTE	$6F,$6F,$6F,$6F,$6F,$6F,$6F,$0A,$1A,$6F,$6F,$6F,$6F,$6F,$6F,$6F
		.BYTE	$7A,$7A,$7A,$7A,$7A,$7A,$7A,$0B,$1B,$7A,$7A,$7A,$7A,$7A,$7A,$7A
		.BYTE	$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4

		BANK_END 1,$C000
