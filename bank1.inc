
		ORG $8000

		BANK_START $01

_scr1_lvl1_handler:
		.BYTE	$07		; NJSR		  _nsub_sub_rom_idx_calc
		.WORD	_nsub_sub_rom_idx_calc
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$12,$04		; SJSR_SW	  $04
		.WORD	_sjsr_case_142CD	; CASE	  _sjsr_case_142CD
		.WORD	_sjsr_case_142CD	; CASE	  _sjsr_case_142CD
		.WORD	_sjsr_case_142CD	; CASE	  _sjsr_case_142CD
		.WORD	_sjsr_case_142E2	; CASE	  _sjsr_case_142E2
		.BYTE	$07		; NJSR		  _nsub_room_register,$04
		.WORD	_nsub_room_register
		.BYTE	$04
		.BYTE	$4E,$71,$00	; DATA	  $4E,$71,$00
		.BYTE	$79,$46,$03	; DATA	  $79,$46,$03
		.BYTE	$39,$6E,$03	; DATA	  $39,$6E,$03
		.BYTE	$6E,$34,$00	; DATA	  $6E,$34,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$04		; SJMP_SW	  $04
		.WORD	_sjmp_case_14031	; CASE	  _sjmp_case_14031
		.WORD	_sjmp_case_14155	; CASE	  _sjmp_case_14155
		.WORD	_sjmp_case_1409B	; CASE	  _sjmp_case_1409B
		.WORD	_sjmp_case_1426B	; CASE	  _sjmp_case_1426B
_sjmp_case_14031:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$00
		.WORD	_cur_room_sequence_idx
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$03
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data00
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data00
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data00
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data00
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14048:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$03
		.WORD	_nsub_6294B
		.BYTE	$03
		.BYTE	$F8,$01,$88,$03	; DATA	  $F8,$01,$88,$03
		.BYTE	$00,$04,$B0,$03	; DATA	  $00,$04,$B0,$03
		.BYTE	$80,$02,$08,$03	; DATA	  $80,$02,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_14048
		.WORD	_sloc_14048
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$03
		.WORD	_nsub_room_register
		.BYTE	$03
		.BYTE	$3C,$6E,$03	; DATA	  $3C,$6E,$03
		.BYTE	$82,$74,$01	; DATA	  $82,$74,$01
		.BYTE	$4E,$5A,$00	; DATA	  $4E,$5A,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$03		; SJMP_SW	  $03
		.WORD	_sjmp_case_1409B	; CASE	  _sjmp_case_1409B
		.WORD	_sjmp_case_140E9	; CASE	  _sjmp_case_140E9
		.WORD	_sjmp_case_14155	; CASE	  _sjmp_case_14155
_lvl_doors_data00:
		.BYTE	$02,$80,$03,$D0,$00
		.WORD	_room_door_always_closed
		.BYTE	$02,$10,$03,$80,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$80,$03,$20,$00
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$E0,$03,$B0,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data00:
		.BYTE	$17,$13,$13,$00
_sjmp_case_1409B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$01
		.WORD	_cur_room_sequence_idx
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$03
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data01
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data01
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data01
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data01
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_140B2:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$00,$02,$88,$03	; DATA	  $00,$02,$88,$03
		.BYTE	$0C		; SBCC		  _sloc_140B2
		.WORD	_sloc_140B2
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$42,$6E,$01	; DATA	  $42,$6E,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_14031	; CASE	  _sjmp_case_14031
_lvl_doors_data01:
		.BYTE	$01,$E0,$03,$80,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$F0,$03,$80,$01
		.WORD	_room_door_always_open
		.BYTE	$FF
_prize_sequence_data01:
		.BYTE	$15,$16,$14,$14,$14,$16,$16,$00
_sjmp_case_140E9:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$02
		.WORD	_cur_room_sequence_idx
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$04,$02
		.WORD	_nsub_628FA
		.BYTE	$01,$04,$02
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0D
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0D
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data02
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data02
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data02
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data02
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14104:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$03,$B0,$03	; DATA	  $F8,$03,$B0,$03
		.BYTE	$F8,$03,$40,$02	; DATA	  $F8,$03,$40,$02
		.BYTE	$0C		; SBCC		  _sloc_14104
		.WORD	_sloc_14104
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_626B7,$06,byte_14354
		.WORD	_nsub_626B7
		.BYTE	$06
		.WORD	byte_14354
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$7C,$74,$03	; DATA	  $7C,$74,$03
		.BYTE	$7C,$46,$03	; DATA	  $7C,$46,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14031	; CASE	  _sjmp_case_14031
		.WORD	_sjmp_case_14155	; CASE	  _sjmp_case_14155
_lvl_doors_data02:
		.BYTE	$04,$10,$03,$B0,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$C0,$03,$90,$00
		.WORD	_room_door_always_open
		.BYTE	$04,$C0,$02,$60,$00
		.WORD	_room_door_always_open
		.BYTE	$04,$10,$02,$40,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data02:
		.BYTE	$FF
_sjmp_case_14155:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$03
		.WORD	_cur_room_sequence_idx
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data03
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data03
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data03
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$02
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_1433C
		.WORD	_nsub_full_pal_load
		.WORD	byte_1433C
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr0
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr0
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1417E:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$04
		.WORD	_nsub_6294B
		.BYTE	$04
		.BYTE	$80,$02,$F8,$02	; DATA	  $80,$02,$F8,$02
		.BYTE	$00,$04,$40,$02	; DATA	  $00,$04,$40,$02
		.BYTE	$F8,$01,$C0,$02	; DATA	  $F8,$01,$C0,$02
		.BYTE	$80,$02,$08,$02	; DATA	  $80,$02,$08,$02
		.BYTE	$0C		; SBCC		  _sloc_1417E
		.WORD	_sloc_1417E
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$04
		.WORD	_nsub_room_register
		.BYTE	$04
		.BYTE	$4E,$62,$02	; DATA	  $4E,$62,$02
		.BYTE	$82,$46,$01	; DATA	  $82,$46,$01
		.BYTE	$3C,$56,$03	; DATA	  $3C,$56,$03
		.BYTE	$6E,$38,$00	; DATA	  $6E,$38,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$04		; SJMP_SW	  $04
		.WORD	_sjmp_case_14031	; CASE	  _sjmp_case_14031
		.WORD	_sjmp_case_140E9	; CASE	  _sjmp_case_140E9
		.WORD	_sjmp_case_141E4	; CASE	  _sjmp_case_141E4
		.WORD	_sjmp_case_1426B	; CASE	  _sjmp_case_1426B
_lvl_doors_data03:
		.BYTE	$03,$E0,$02,$40,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$70,$02,$B0,$00
		.WORD	_room_door_always_open
		.BYTE	$02,$10,$02,$C0,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$80,$02,$E0,$00
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$80,$02,$20,$00
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data03:
		.BYTE	$17,$18,$18,$18,$14,$13,$00
_sjmp_case_141E4:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$04
		.WORD	_cur_room_sequence_idx
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$01,$02
		.WORD	_nsub_628FA
		.BYTE	$02,$01,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data04
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data04
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data04
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data04
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_141FB:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$00,$02,$C0,$02	; DATA	  $00,$02,$C0,$02
		.BYTE	$0C		; SBCC		  _sloc_141FB
		.WORD	_sloc_141FB
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$42,$56,$01	; DATA	  $42,$56,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_14155	; CASE	  _sjmp_case_14155
_lvl_doors_data04:
		.BYTE	$01,$E0,$02,$C0,$01
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$70,$02,$90,$00
		.WORD	_room_door_always_open
		.BYTE	$FF
_prize_sequence_data04:
		.BYTE	$FF
_sjmp_case_1422B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$05
		.WORD	_cur_room_sequence_idx
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$02,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$02,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data05
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data05
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data05
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data05
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14242:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$02,$B8,$01	; DATA	  $80,$02,$B8,$01
		.BYTE	$0C		; SBCC		  _sloc_14242
		.WORD	_sloc_14242
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$6E,$22,$02	; DATA	  $6E,$22,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1426B	; CASE	  _sjmp_case_1426B
_lvl_doors_data05:
		.BYTE	$02,$80,$01,$A0,$00
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data05:
		.BYTE	$FF
_sjmp_case_1426B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$06
		.WORD	_cur_room_sequence_idx
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$07
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$03
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_1435C
		.WORD	_nsub_full_pal_load
		.WORD	byte_1435C
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr1
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$03,$01
		.WORD	_nsub_628FA
		.BYTE	$02,$03,$01
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data06
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data06
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data06
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data06
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14294:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$03,$18,$01	; DATA	  $80,$03,$18,$01
		.BYTE	$80,$03,$E8,$01	; DATA	  $80,$03,$E8,$01
		.BYTE	$0C		; SBCC		  _sloc_14294
		.WORD	_sloc_14294
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$4E,$32,$00	; DATA	  $4E,$32,$00
		.BYTE	$4E,$42,$02	; DATA	  $4E,$42,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_1422B	; CASE	  _sjmp_case_1422B
		.WORD	_sjmp_case_14155	; CASE	  _sjmp_case_14155
_lvl_doors_data06:
		.BYTE	$03,$80,$01,$30,$00
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$80,$01,$D0,$00
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data06:
		.BYTE	$FF	; *--
_sjsr_case_142CD:
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$02
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_1433C
		.WORD	_nsub_full_pal_load
		.WORD	byte_1433C
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr0
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr0
		.BYTE	$03		; SJMP		  _sloc_142F4
		.WORD	_sloc_142F4
_sjsr_case_142E2:
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$07
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$03
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_1435C
		.WORD	_nsub_full_pal_load
		.WORD	byte_1435C
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr1
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr1
_sloc_142F4:
		.BYTE	$13		; STORE8	  _lvl_data_prg_bank,$01
		.WORD	_lvl_data_prg_bank
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_lvl_data_ptrs_load
		.WORD	_nsub_lvl_data_ptrs_load
		.WORD	_lvl0_macroA_tbl	; DATA	  _lvl0_macroA_tbl
		.WORD	_lvl0_macroB_tbl	; DATA	  _lvl0_macroB_tbl
		.WORD	_lvl0_macroC_tbl	; DATA	  _lvl0_macroC_tbl
		.WORD	_lvl0_macroD_tbl	; DATA	  _lvl0_macroD_tbl
		.WORD	_lvl0_attrs_tbl	; DATA	  _lvl0_attrs_tbl
		.BYTE	$16		; STORE16	  _lvl_room_lib_ptr,_lvl_room_lib00
		.WORD	_lvl_room_lib_ptr
		.WORD	_lvl_room_lib00
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$00
		.WORD	_nsub_apu_mus_load
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_ingame_collision_watch_start
		.WORD	_nsub_ingame_collision_watch_start
		.BYTE	$07		; NJSR		  _nsub_ingame_player_control_start
		.WORD	_nsub_ingame_player_control_start
		.BYTE	$09		; NBG_HNDL_SET	  _j_nbgsub_1437C
		.WORD	_j_nbgsub_1437C
		.BYTE	$08,$01		; SRUN		  $01,_scr_14324
		.WORD	_scr_14324
		.BYTE	$16		; STORE16	  _lvl_objects_ptr,_lvl0_objects_list
		.WORD	_lvl_objects_ptr
		.WORD	_lvl0_objects_list
		.BYTE	$07		; NJSR		  _nsub_lvl_room_objects_init
		.WORD	_nsub_lvl_room_objects_init
		.BYTE	$05		; SRET
_scr_14324:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_15E4A
		.WORD	_nsub_15E4A
		.BYTE	$0C		; SBCC		  _scr_14324
		.WORD	_scr_14324
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$03
		.WORD	_nsub_apu_snd_load
		.BYTE	$03
		.BYTE	$04		; SJSR		  _ssub_62DC9
		.WORD	_ssub_62DC9
		.BYTE	$07		; NJSR		  _nsub_pause_menu_handler
		.WORD	_nsub_pause_menu_handler
		.BYTE	$04		; SJSR		  _ssub_62DB5
		.WORD	_ssub_62DB5
		.BYTE	$03		; SJMP		  _scr_14324
		.WORD	_scr_14324
byte_1433C:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$1A,$17,$0F,$37,$27,$17,$0F,$30,$05,$17
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15
byte_14354:
		.BYTE	$0F,$36,$2B,$0F,$0F,$10,$17,$07
byte_1435C:
		.BYTE	$0F,$30,$17,$07,$0F,$30,$05,$07,$0F,$10,$17,$07,$0F,$30,$10,$00
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$31,$25,$0F,$0F,$10,$17,$07

; =============== S U B	R O U T	I N E =======================================
_j_nbgsub_1437C:
		JMP		_lvl_room_objects_handler
_scr2_lvl2_handler:
		.BYTE	$07		; NJSR		  _nsub_sub_rom_idx_calc
		.WORD	_nsub_sub_rom_idx_calc
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$12,$05		; SJSR_SW	  $05
		.WORD	_sjsr_case_14753	; CASE	  _sjsr_case_14753
		.WORD	_sjsr_case_14753	; CASE	  _sjsr_case_14753
		.WORD	_sjsr_case_14753	; CASE	  _sjsr_case_14753
		.WORD	_sjsr_case_14753	; CASE	  _sjsr_case_14753
		.WORD	_sjsr_case_14763	; CASE	  _sjsr_case_14763
		.BYTE	$07		; NJSR		  _nsub_room_register,$05
		.WORD	_nsub_room_register
		.BYTE	$05
		.BYTE	$06,$D1,$01	; DATA	  $06,$D1,$01
		.BYTE	$2E,$D9,$00	; DATA	  $2E,$D9,$00
		.BYTE	$2E,$79,$00	; DATA	  $2E,$79,$00
		.BYTE	$83,$46,$01	; DATA	  $83,$46,$01
		.BYTE	$A3,$06,$01	; DATA	  $A3,$06,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$05		; SJMP_SW	  $05
		.WORD	_sjmp_case_143B7	; CASE	  _sjmp_case_143B7
		.WORD	_sjmp_case_1447E	; CASE	  _sjmp_case_1447E
		.WORD	_sjmp_case_14514	; CASE	  _sjmp_case_14514
		.WORD	_sjmp_case_145A4	; CASE	  _sjmp_case_145A4
		.WORD	_sjmp_case_1462C	; CASE	  _sjmp_case_1462C
_sjmp_case_143B7:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$00
		.WORD	_cur_room_sequence_idx
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$00,$06
		.WORD	_nsub_628FA
		.BYTE	$02,$00,$06
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data07
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data07
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data07
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data07
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_143CE:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$00,$08,$06	; DATA	  $80,$00,$08,$06
		.BYTE	$0C		; SBCC		  _sloc_143CE
		.WORD	_sloc_143CE
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$0E,$B9,$00	; DATA	  $0E,$B9,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_143F7	; CASE	  _sjmp_case_143F7
_lvl_doors_data07:
		.BYTE	$00,$80,$06,$10,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data07:
		.BYTE	$FF
_sjmp_case_143F7:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$01
		.WORD	_cur_room_sequence_idx
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$00,$04
		.WORD	_nsub_628FA
		.BYTE	$01,$00,$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data08
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data08
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data08
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data08
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1440E:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$78,$00,$08,$04	; DATA	  $78,$00,$08,$04
		.BYTE	$0C		; SBCC		  _sloc_1440E
		.WORD	_sloc_1440E
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$0E,$73,$00	; DATA	  $0E,$73,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_14437	; CASE	  _sjmp_case_14437
_lvl_doors_data08:
		.BYTE	$00,$80,$04,$20,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data08:
		.BYTE	$FF
_sjmp_case_14437:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$02
		.WORD	_cur_room_sequence_idx
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$00,$03
		.WORD	_nsub_628FA
		.BYTE	$02,$00,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data09
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data09
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data09
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data09
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1444E:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$78,$00,$08,$03	; DATA	  $78,$00,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_1444E
		.WORD	_sloc_1444E
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$2E,$D9,$00	; DATA	  $2E,$D9,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1447E	; CASE	  _sjmp_case_1447E
_lvl_doors_data09:
		.BYTE	$00,$80,$03,$10,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$80,$03,$D0,$02
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data09:
		.BYTE	$FF
_sjmp_case_1447E:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$03
		.WORD	_cur_room_sequence_idx
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$01,$06
		.WORD	_nsub_628FA
		.BYTE	$02,$01,$06
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data0A
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data0A
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data0A
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data0A
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14495:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$01,$08,$06	; DATA	  $80,$01,$08,$06
		.BYTE	$0C		; SBCC		  _sloc_14495
		.WORD	_sloc_14495
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$2E,$B9,$00	; DATA	  $2E,$B9,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_144BE	; CASE	  _sjmp_case_144BE
_lvl_doors_data0A:
		.BYTE	$01,$80,$06,$20,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data0A:
		.BYTE	$FF
_sjmp_case_144BE:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$04
		.WORD	_cur_room_sequence_idx
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$01,$04
		.WORD	_nsub_628FA
		.BYTE	$01,$01,$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data0B
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data0B
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data0B
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data0B
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_144D5:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$B0,$01,$08,$04	; DATA	  $B0,$01,$08,$04
		.BYTE	$50,$01,$08,$04	; DATA	  $50,$01,$08,$04
		.BYTE	$0C		; SBCC		  _sloc_144D5
		.WORD	_sloc_144D5
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$2E,$79,$00	; DATA	  $2E,$79,$00
		.BYTE	$2E,$B9,$00	; DATA	  $2E,$B9,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14514	; CASE	  _sjmp_case_14514
		.WORD	_sjmp_case_144BE	; CASE	  _sjmp_case_144BE
_lvl_doors_data0B:
		.BYTE	$01,$B0,$04,$20,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$50,$04,$20,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data0B:
		.BYTE	$1D,$1D,$20,$1D,$1D,$1E,$00
_sjmp_case_14514:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$05
		.WORD	_cur_room_sequence_idx
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$01,$02
		.WORD	_nsub_628FA
		.BYTE	$01,$01,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data0C
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data0C
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data0C
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data0C
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1452B:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$F8,$01,$40,$02	; DATA	  $F8,$01,$40,$02
		.BYTE	$0C		; SBCC		  _sloc_1452B
		.WORD	_sloc_1452B
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$45,$46,$01	; DATA	  $45,$46,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1455A	; CASE	  _sjmp_case_1455A
_lvl_doors_data0C:
		.BYTE	$01,$E0,$02,$40,$03
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data0C:
		.BYTE	$20,$1D,$1E,$20,$1D,$1E,$00
_sjmp_case_1455A:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$06
		.WORD	_cur_room_sequence_idx
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data0D
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data0D
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data0D
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data0D
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14571:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$F8,$03,$40,$02	; DATA	  $F8,$03,$40,$02
		.BYTE	$0C		; SBCC		  _sloc_14571
		.WORD	_sloc_14571
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$83,$46,$01	; DATA	  $83,$46,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_145A4	; CASE	  _sjmp_case_145A4
_lvl_doors_data0D:
		.BYTE	$03,$E0,$02,$40,$03
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$20,$02,$40,$03
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data0D:
		.BYTE	$20,$20,$1F,$00
_sjmp_case_145A4:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$07
		.WORD	_cur_room_sequence_idx
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$04,$02
		.WORD	_nsub_628FA
		.BYTE	$02,$04,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data0E
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data0E
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data0E
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data0E
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_145BB:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$04,$08,$02	; DATA	  $80,$04,$08,$02
		.BYTE	$0C		; SBCC		  _sloc_145BB
		.WORD	_sloc_145BB
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$8E,$39,$00	; DATA	  $8E,$39,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_145E8	; CASE	  _sjmp_case_145E8
_lvl_doors_data0E:
		.BYTE	$04,$80,$02,$20,$02
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data0E:
		.BYTE	$1E,$1F,$1E,$20,$00
_sjmp_case_145E8:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$08
		.WORD	_cur_room_sequence_idx
		.BYTE	$08
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$04,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$04,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data0F
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data0F
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data0F
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data0F
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_145FF:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$00,$05,$48,$00	; DATA	  $00,$05,$48,$00
		.BYTE	$0C		; SBCC		  _sloc_145FF
		.WORD	_sloc_145FF
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$A3,$06,$01	; DATA	  $A3,$06,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1462C	; CASE	  _sjmp_case_1462C
_lvl_doors_data0F:
		.BYTE	$04,$E0,$00,$40,$03
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data0F:
		.BYTE	$1E,$1F,$1D,$20,$00
_sjmp_case_1462C:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$09
		.WORD	_cur_room_sequence_idx
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$0B
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$0B
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr2
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr2
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$05,$00
		.WORD	_nsub_628FA
		.BYTE	$02,$05,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data10
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data10
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data10
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data10
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1464C:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$05,$D8,$00	; DATA	  $80,$05,$D8,$00
		.BYTE	$0C		; SBCC		  _sloc_1464C
		.WORD	_sloc_1464C
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$AE,$26,$02	; DATA	  $AE,$26,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_14675	; CASE	  _sjmp_case_14675
_lvl_doors_data10:
		.BYTE	$05,$80,$00,$D0,$04
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data10:
		.BYTE	$FF	; *--
_sjmp_case_14675:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0A
		.WORD	_cur_room_sequence_idx
		.BYTE	$0A
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$05,$01
		.WORD	_nsub_628FA
		.BYTE	$01,$05,$01
		.BYTE	$07		; NJSR		  _nsub_bg_pal_load,byte_147C5
		.WORD	_nsub_bg_pal_load
		.WORD	byte_147C5
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_147F1
		.WORD	_nbgsub_147F1
		.BYTE	$08,$01		; SRUN		  $01,_scr_14734
		.WORD	_scr_14734
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data11
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data11
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data11
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data11
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14698:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$05,$E8,$02	; DATA	  $80,$05,$E8,$02
		.BYTE	$0C		; SBCC		  _sloc_14698
		.WORD	_sloc_14698
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$AE,$66,$02	; DATA	  $AE,$66,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_146C8	; CASE	  _sjmp_case_146C8
_lvl_doors_data11:
		.BYTE	$05,$80,$01,$20,$04
		.WORD	_room_door_always_closed
		.BYTE	$05,$80,$02,$D0,$04
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data11:
		.BYTE	$FF
_sjmp_case_146C8:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0B
		.WORD	_cur_room_sequence_idx
		.BYTE	$0B
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$05,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$05,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data12
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data12
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data12
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data12
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_146DF:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$78,$05,$E8,$04	; DATA	  $78,$05,$E8,$04
		.BYTE	$0C		; SBCC		  _sloc_146DF
		.WORD	_sloc_146DF
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$AE,$A6,$02	; DATA	  $AE,$A6,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1470F	; CASE	  _sjmp_case_1470F
_lvl_doors_data12:
		.BYTE	$05,$80,$03,$20,$04
		.WORD	_room_door_always_closed
		.BYTE	$05,$80,$04,$D0,$04
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data12:
		.BYTE	$FF
_sjmp_case_1470F:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0C
		.WORD	_cur_room_sequence_idx
		.BYTE	$0C
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$05,$05
		.WORD	_nsub_628FA
		.BYTE	$01,$05,$05
		.BYTE	$13		; STORE8	  _cur_room_x_pageB,$05
		.WORD	_cur_room_x_pageB
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data13
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data13
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data13
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data13
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
		.BYTE	$0A		; SUSPEND
_lvl_doors_data13:
		.BYTE	$05,$80,$05,$20,$04
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data13:
		.BYTE	$FF
_scr_14734:
		.BYTE	$01,$80		; SLOOP_BEGIN	  $80
		.BYTE	$0E		; SMEM_ALU	  _apu_var402,ADC,$02X
		.WORD	_apu_var402
		.BYTE	$02,$FF
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$FF
		.WORD	_nsub_apu_mus_load
		.BYTE	$FF
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$13
		.WORD	_nsub_apu_snd_load
		.BYTE	$13
		.BYTE	$06,$A0		; SDELAY	  $A0
		.BYTE	$13		; STORE8	  _apu_var402,$FF
		.WORD	_apu_var402
		.BYTE	$FF
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$04
		.WORD	_nsub_apu_mus_load
		.BYTE	$04
		.BYTE	$03		; SJMP		  _scr_14324
		.WORD	_scr_14324
_sjsr_case_14753:
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0C
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0C
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$0A
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$0A
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr3
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr3
		.BYTE	$03		; SJMP		  _sloc_14770
		.WORD	_sloc_14770
_sjsr_case_14763:
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0C
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0C
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$0B
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$0B
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr2
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr2
_sloc_14770:
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_147A5
		.WORD	_nsub_full_pal_load
		.WORD	byte_147A5
		.BYTE	$13		; STORE8	  _lvl_data_prg_bank,$02
		.WORD	_lvl_data_prg_bank
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_lvl_data_ptrs_load
		.WORD	_nsub_lvl_data_ptrs_load
		.WORD	_lvl1_macroA_tbl	; DATA	  _lvl1_macroA_tbl
		.WORD	_lvl1_macroB_tbl	; DATA	  _lvl1_macroB_tbl
		.WORD	_lvl1_macroC_tbl	; DATA	  _lvl1_macroC_tbl
		.WORD	_lvl1_macroD_tbl	; DATA	  _lvl1_macroD_tbl
		.WORD	_lvl1_attrs_tbl	; DATA	  _lvl1_attrs_tbl
		.BYTE	$16		; STORE16	  _lvl_room_lib_ptr,_lvl_room_lib01
		.WORD	_lvl_room_lib_ptr
		.WORD	_lvl_room_lib01
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$06
		.WORD	_nsub_apu_mus_load
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_ingame_collision_watch_start
		.WORD	_nsub_ingame_collision_watch_start
		.BYTE	$07		; NJSR		  _nsub_ingame_player_control_start
		.WORD	_nsub_ingame_player_control_start
		.BYTE	$08,$01		; SRUN		  $01,_scr_14324
		.WORD	_scr_14324
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_1480E
		.WORD	_nbgsub_1480E
		.BYTE	$16		; STORE16	  _lvl_objects_ptr,_lvl1_objects_list
		.WORD	_lvl_objects_ptr
		.WORD	_lvl1_objects_list
		.BYTE	$07		; NJSR		  _nsub_lvl_room_objects_init
		.WORD	_nsub_lvl_room_objects_init
		.BYTE	$05		; SRET
byte_147A5:
		.BYTE	$0F,$30,$10,$00,$0F,$10,$00,$07,$0F,$10,$00,$08,$0F,$10,$00,$17
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$10,$00,$0F,$0F,$36,$27,$0F
byte_147C5:
		.BYTE	$0F,$30,$10,$00,$0F,$10,$00,$07,$0F,$27,$17,$07,$0F,$01,$00,$07
_unused_2:
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$2B,$0F,$0F,$10,$17,$07 ;	*--
byte_147E5:
		.BYTE	$0F,$0F,$07,$0F,$0F,$07,$0F,$0F,$0F,$0F,$0F,$07

; =============== S U B	R O U T	I N E =======================================
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
		JSR		sub_62069

; =============== S U B	R O U T	I N E =======================================
_nbgsub_1480E:
		JMP		_lvl_room_objects_handler
_scr3_lvl3_handler:
		.BYTE	$07		; NJSR		  _nsub_sub_rom_idx_calc
		.WORD	_nsub_sub_rom_idx_calc
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$04		; SJSR		  _ssub_15117
		.WORD	_ssub_15117
		.BYTE	$07		; NJSR		  _nsub_room_register,$07
		.WORD	_nsub_room_register
		.BYTE	$07
		.BYTE	$0E,$34,$00	; DATA	  $0E,$34,$00
		.BYTE	$4E,$06,$02	; DATA	  $4E,$06,$02
		.BYTE	$AE,$06,$02	; DATA	  $AE,$06,$02
		.BYTE	$CE,$06,$02	; DATA	  $CE,$06,$02
		.BYTE	$2E,$66,$02	; DATA	  $2E,$66,$02
		.BYTE	$4E,$66,$02	; DATA	  $4E,$66,$02
		.BYTE	$AE,$66,$02	; DATA	  $AE,$66,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$07		; SJMP_SW	  $07
		.WORD	_sjmp_case_1484A	; CASE	  _sjmp_case_1484A
		.WORD	_sjmp_case_148E1	; CASE	  _sjmp_case_148E1
		.WORD	_sjmp_case_14A2E	; CASE	  _sjmp_case_14A2E
		.WORD	_sjmp_case_14B83	; CASE	  _sjmp_case_14B83
		.WORD	_sjmp_case_14CD8	; CASE	  _sjmp_case_14CD8
		.WORD	_sjmp_case_14E2F	; CASE	  _sjmp_case_14E2F
		.WORD	_sjmp_case_14F89	; CASE	  _sjmp_case_14F89
_sjmp_case_1484A:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$00
		.WORD	_cur_room_sequence_idx
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$01
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$01
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data14
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data14
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data14
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data14
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14861:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$80,$01,$08,$01	; DATA	  $80,$01,$08,$01
		.BYTE	$0C		; SBCC		  _sloc_14861
		.WORD	_sloc_14861
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$2E,$18,$00	; DATA	  $2E,$18,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_14891	; CASE	  _sjmp_case_14891
_lvl_doors_data14:
		.BYTE	$01,$80,$01,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$90,$01,$D0,$06
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data14:
		.BYTE	$FF
_sjmp_case_14891:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$01
		.WORD	_cur_room_sequence_idx
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$00
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data15
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data15
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data15
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data15
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_148A8:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$00,$08,$00	; DATA	  $80,$00,$08,$00
		.BYTE	$80,$01,$F8,$00	; DATA	  $80,$01,$F8,$00
		.BYTE	$0C		; SBCC		  _sloc_148A8
		.WORD	_sloc_148A8
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$4E,$02,$02	; DATA	  $4E,$02,$02
		.BYTE	$2E,$22,$02	; DATA	  $2E,$22,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_148E1	; CASE	  _sjmp_case_148E1
		.WORD	_sjmp_case_1484A	; CASE	  _sjmp_case_1484A
_lvl_doors_data15:
		.BYTE	$00,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$80,$00,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data15:
		.BYTE	$FF
_sjmp_case_148E1:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$02
		.WORD	_cur_room_sequence_idx
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$02,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$02,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data16
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data16
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data16
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data16
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_148F8:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$02,$F8,$01	; DATA	  $30,$02,$F8,$01
		.BYTE	$80,$02,$08,$00	; DATA	  $80,$02,$08,$00
		.BYTE	$0C		; SBCC		  _sloc_148F8
		.WORD	_sloc_148F8
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$44,$42,$02	; DATA	  $44,$42,$02
		.BYTE	$0E,$02,$02	; DATA	  $0E,$02,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14952	; CASE	  _sjmp_case_14952
		.WORD	_sjmp_case_14891	; CASE	  _sjmp_case_14891
_lvl_doors_data16:
		.BYTE	$02,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$40,$00,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$80,$00,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$B0,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$70,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$30,$01,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data16:
		.BYTE	$25,$25,$25,$28,$28,$00
_sjmp_case_14952:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$03
		.WORD	_cur_room_sequence_idx
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data17
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data17
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data17
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data17
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14969:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$D0,$03,$08,$02	; DATA	  $D0,$03,$08,$02
		.BYTE	$30,$02,$08,$02	; DATA	  $30,$02,$08,$02
		.BYTE	$0C		; SBCC		  _sloc_14969
		.WORD	_sloc_14969
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$78,$38,$00	; DATA	  $78,$38,$00
		.BYTE	$44,$38,$00	; DATA	  $44,$38,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_149BE	; CASE	  _sjmp_case_149BE
		.WORD	_sjmp_case_148E1	; CASE	  _sjmp_case_148E1
_lvl_doors_data17:
		.BYTE	$02,$30,$02,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$40,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$C0,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$50,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$C0,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$02,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data17:
		.BYTE	$FF
_sjmp_case_149BE:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$04
		.WORD	_cur_room_sequence_idx
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$03,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$03,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data18
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data18
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data18
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data18
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$04
		.WORD	_nsub_apu_mus_load
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_149E3:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$03,$08,$00	; DATA	  $80,$03,$08,$00
		.BYTE	$D0,$03,$F8,$01	; DATA	  $D0,$03,$F8,$01
		.BYTE	$0C		; SBCC		  _sloc_149E3
		.WORD	_sloc_149E3
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$07
		.WORD	_nsub_apu_mus_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$AE,$02,$02	; DATA	  $AE,$02,$02
		.BYTE	$78,$42,$02	; DATA	  $78,$42,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14A2E	; CASE	  _sjmp_case_14A2E
		.WORD	_sjmp_case_14952	; CASE	  _sjmp_case_14952
_lvl_doors_data18:
		.BYTE	$03,$80,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$40,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$01,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data18:
		.BYTE	$FF
_sjmp_case_14A2E:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$05
		.WORD	_cur_room_sequence_idx
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$05,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$05,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data19
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data19
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data19
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data19
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15175
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15175
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14A4F:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$D0,$05,$F8,$01	; DATA	  $D0,$05,$F8,$01
		.BYTE	$80,$05,$08,$00	; DATA	  $80,$05,$08,$00
		.BYTE	$0C		; SBCC		  _sloc_14A4F
		.WORD	_sloc_14A4F
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$B8,$42,$02	; DATA	  $B8,$42,$02
		.BYTE	$6E,$02,$02	; DATA	  $6E,$02,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14AA7	; CASE	  _sjmp_case_14AA7
		.WORD	_sjmp_case_149BE	; CASE	  _sjmp_case_149BE
_lvl_doors_data19:
		.BYTE	$05,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$05,$70,$00,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$B0,$00,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$80,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$40,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$01,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data19:
		.BYTE	$28,$26,$26,$00
_sjmp_case_14AA7:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$06
		.WORD	_cur_room_sequence_idx
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$04,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$04,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data1A
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data1A
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data1A
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data1A
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14ABE:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$04,$08,$02	; DATA	  $30,$04,$08,$02
		.BYTE	$D0,$05,$08,$02	; DATA	  $D0,$05,$08,$02
		.BYTE	$0C		; SBCC		  _sloc_14ABE
		.WORD	_sloc_14ABE
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$84,$38,$00	; DATA	  $84,$38,$00
		.BYTE	$B8,$38,$00	; DATA	  $B8,$38,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14B13	; CASE	  _sjmp_case_14B13
		.WORD	_sjmp_case_14A2E	; CASE	  _sjmp_case_14A2E
_lvl_doors_data1A:
		.BYTE	$04,$30,$02,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$40,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$D0,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$30,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$C0,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$02,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data1A:
		.BYTE	$FF
_sjmp_case_14B13:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$07
		.WORD	_cur_room_sequence_idx
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$04,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$04,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data1B
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data1B
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data1B
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data1B
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$04
		.WORD	_nsub_apu_mus_load
		.BYTE	$04
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14B38:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$04,$08,$00	; DATA	  $80,$04,$08,$00
		.BYTE	$30,$04,$F8,$01	; DATA	  $30,$04,$F8,$01
		.BYTE	$0C		; SBCC		  _sloc_14B38
		.WORD	_sloc_14B38
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$07
		.WORD	_nsub_apu_mus_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$CE,$02,$02	; DATA	  $CE,$02,$02
		.BYTE	$84,$42,$02	; DATA	  $84,$42,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14B83	; CASE	  _sjmp_case_14B83
		.WORD	_sjmp_case_14AA7	; CASE	  _sjmp_case_14AA7
_lvl_doors_data1B:
		.BYTE	$04,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$B0,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$04,$70,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$30,$01,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data1B:
		.BYTE	$FF
_sjmp_case_14B83:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$08
		.WORD	_cur_room_sequence_idx
		.BYTE	$08
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$06,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$06,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15175
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15175
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data1C
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data1C
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data1C
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data1C
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14BA4:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$06,$F8,$01	; DATA	  $30,$06,$F8,$01
		.BYTE	$80,$06,$08,$00	; DATA	  $80,$06,$08,$00
		.BYTE	$0C		; SBCC		  _sloc_14BA4
		.WORD	_sloc_14BA4
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$C4,$42,$02	; DATA	  $C4,$42,$02
		.BYTE	$8E,$02,$02	; DATA	  $8E,$02,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14BFC	; CASE	  _sjmp_case_14BFC
		.WORD	_sjmp_case_14B13	; CASE	  _sjmp_case_14B13
_lvl_doors_data1C:
		.BYTE	$06,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$06,$40,$00,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$06,$80,$00,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$06,$B0,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$06,$70,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$06,$30,$01,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data1C:
		.BYTE	$27,$27,$28,$00
_sjmp_case_14BFC:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$09
		.WORD	_cur_room_sequence_idx
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$06,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$06,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data1D
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data1D
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data1D
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data1D
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14C13:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$D0,$07,$08,$02	; DATA	  $D0,$07,$08,$02
		.BYTE	$30,$06,$08,$02	; DATA	  $30,$06,$08,$02
		.BYTE	$0C		; SBCC		  _sloc_14C13
		.WORD	_sloc_14C13
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$F8,$38,$00	; DATA	  $F8,$38,$00
		.BYTE	$C4,$38,$00	; DATA	  $C4,$38,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14C68	; CASE	  _sjmp_case_14C68
		.WORD	_sjmp_case_14B83	; CASE	  _sjmp_case_14B83
_lvl_doors_data1D:
		.BYTE	$06,$30,$02,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$06,$40,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$06,$C0,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$07,$50,$02,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$07,$C0,$02,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$07,$D0,$02,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data1D:
		.BYTE	$FF
_sjmp_case_14C68:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0A
		.WORD	_cur_room_sequence_idx
		.BYTE	$0A
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$07,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$07,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data1E
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data1E
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data1E
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data1E
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$04
		.WORD	_nsub_apu_mus_load
		.BYTE	$04
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14C8D:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$07,$08,$00	; DATA	  $80,$07,$08,$00
		.BYTE	$C0,$07,$F8,$01	; DATA	  $C0,$07,$F8,$01
		.BYTE	$0C		; SBCC		  _sloc_14C8D
		.WORD	_sloc_14C8D
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$07
		.WORD	_nsub_apu_mus_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$2E,$62,$02	; DATA	  $2E,$62,$02
		.BYTE	$F8,$42,$02	; DATA	  $F8,$42,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14CD8	; CASE	  _sjmp_case_14CD8
		.WORD	_sjmp_case_14BFC	; CASE	  _sjmp_case_14BFC
_lvl_doors_data1E:
		.BYTE	$07,$80,$00,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$07,$80,$01,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$07,$40,$01,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$07,$D0,$01,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data1E:
		.BYTE	$FF
_sjmp_case_14CD8:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0B
		.WORD	_cur_room_sequence_idx
		.BYTE	$0B
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$01,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$01,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15175
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15175
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data1F
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data1F
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data1F
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data1F
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14CF9:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$D0,$01,$F8,$04	; DATA	  $D0,$01,$F8,$04
		.BYTE	$80,$01,$08,$03	; DATA	  $80,$01,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_14CF9
		.WORD	_sloc_14CF9
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$38,$A2,$02	; DATA	  $38,$A2,$02
		.BYTE	$EE,$02,$02	; DATA	  $EE,$02,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14D4E	; CASE	  _sjmp_case_14D4E
		.WORD	_sjmp_case_14C68	; CASE	  _sjmp_case_14C68
_lvl_doors_data1F:
		.BYTE	$01,$80,$03,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$70,$03,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$01,$B0,$03,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$80,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$40,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$01,$D0,$04,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data1F:
		.BYTE	$FF
_sjmp_case_14D4E:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0C
		.WORD	_cur_room_sequence_idx
		.BYTE	$0C
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$05
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$05
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data20
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data20
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data20
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data20
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14D65:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$00,$08,$05	; DATA	  $30,$00,$08,$05
		.BYTE	$D0,$01,$08,$05	; DATA	  $D0,$01,$08,$05
		.BYTE	$0C		; SBCC		  _sloc_14D65
		.WORD	_sloc_14D65
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$04,$98,$00	; DATA	  $04,$98,$00
		.BYTE	$38,$98,$00	; DATA	  $38,$98,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14DBF	; CASE	  _sjmp_case_14DBF
		.WORD	_sjmp_case_14CD8	; CASE	  _sjmp_case_14CD8
_lvl_doors_data20:
		.BYTE	$00,$30,$05,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$40,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$00,$C0,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$50,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$01,$C0,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$01,$D0,$05,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data20:
		.BYTE	$28,$24,$24,$24,$28,$00
_sjmp_case_14DBF:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0D
		.WORD	_cur_room_sequence_idx
		.BYTE	$0D
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$00,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$00,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data21
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data21
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data21
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data21
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$04
		.WORD	_nsub_apu_mus_load
		.BYTE	$04
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14DE4:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$00,$08,$03	; DATA	  $80,$00,$08,$03
		.BYTE	$30,$00,$F8,$04	; DATA	  $30,$00,$F8,$04
		.BYTE	$0C		; SBCC		  _sloc_14DE4
		.WORD	_sloc_14DE4
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$07
		.WORD	_nsub_apu_mus_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$4E,$62,$02	; DATA	  $4E,$62,$02
		.BYTE	$04,$A2,$02	; DATA	  $04,$A2,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14E2F	; CASE	  _sjmp_case_14E2F
		.WORD	_sjmp_case_14D4E	; CASE	  _sjmp_case_14D4E
_lvl_doors_data21:
		.BYTE	$00,$80,$03,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$B0,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$00,$70,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$00,$30,$04,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data21:
		.BYTE	$FF
_sjmp_case_14E2F:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0E
		.WORD	_cur_room_sequence_idx
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$02,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$02,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15175
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15175
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data22
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data22
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data22
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data22
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14E50:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$02,$F8,$04	; DATA	  $30,$02,$F8,$04
		.BYTE	$80,$02,$08,$03	; DATA	  $80,$02,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_14E50
		.WORD	_sloc_14E50
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$44,$A2,$02	; DATA	  $44,$A2,$02
		.BYTE	$0E,$62,$02	; DATA	  $0E,$62,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14EAD	; CASE	  _sjmp_case_14EAD
		.WORD	_sjmp_case_14DBF	; CASE	  _sjmp_case_14DBF
_lvl_doors_data22:
		.BYTE	$02,$80,$03,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$80,$03,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$40,$03,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$B0,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$02,$70,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$30,$04,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data22:
		.BYTE	$28,$24,$24,$24,$24,$24,$24,$25,$00
_sjmp_case_14EAD:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0F
		.WORD	_cur_room_sequence_idx
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$05
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$05
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data23
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data23
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data23
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data23
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14EC4:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$D0,$03,$08,$05	; DATA	  $D0,$03,$08,$05
		.BYTE	$30,$02,$08,$05	; DATA	  $30,$02,$08,$05
		.BYTE	$0C		; SBCC		  _sloc_14EC4
		.WORD	_sloc_14EC4
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$78,$98,$00	; DATA	  $78,$98,$00
		.BYTE	$44,$98,$00	; DATA	  $44,$98,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14F19	; CASE	  _sjmp_case_14F19
		.WORD	_sjmp_case_14E2F	; CASE	  _sjmp_case_14E2F
_lvl_doors_data23:
		.BYTE	$02,$30,$05,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$40,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$02,$D0,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$30,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$C0,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$05,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data23:
		.BYTE	$FF
_sjmp_case_14F19:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$10
		.WORD	_cur_room_sequence_idx
		.BYTE	$10
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$03,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$03,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data24
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data24
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data24
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data24
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$04
		.WORD	_nsub_apu_mus_load
		.BYTE	$04
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14F3E:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$80,$03,$08,$03	; DATA	  $80,$03,$08,$03
		.BYTE	$C0,$03,$F8,$04	; DATA	  $C0,$03,$F8,$04
		.BYTE	$0C		; SBCC		  _sloc_14F3E
		.WORD	_sloc_14F3E
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$07
		.WORD	_nsub_apu_mus_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$AE,$62,$02	; DATA	  $AE,$62,$02
		.BYTE	$78,$A2,$02	; DATA	  $78,$A2,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14F89	; CASE	  _sjmp_case_14F89
		.WORD	_sjmp_case_14EAD	; CASE	  _sjmp_case_14EAD
_lvl_doors_data24:
		.BYTE	$03,$80,$03,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$80,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$03,$40,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$03,$D0,$04,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data24:
		.BYTE	$FF
_sjmp_case_14F89:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$14
		.WORD	_cur_room_sequence_idx
		.BYTE	$14
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$05,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$05,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data25
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data25
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data25
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data25
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_14FAA:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$D0,$05,$F8,$04	; DATA	  $D0,$05,$F8,$04
		.BYTE	$80,$05,$08,$03	; DATA	  $80,$05,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_14FAA
		.WORD	_sloc_14FAA
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$B8,$A2,$02	; DATA	  $B8,$A2,$02
		.BYTE	$6E,$62,$02	; DATA	  $6E,$62,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_14FFF	; CASE	  _sjmp_case_14FFF
		.WORD	_sjmp_case_14F19	; CASE	  _sjmp_case_14F19
_lvl_doors_data25:
		.BYTE	$05,$80,$03,$20,$06
		.WORD	_room_door_enemy_clear_open
		.BYTE	$05,$70,$03,$B0,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$B0,$03,$E0,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$80,$04,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$40,$04,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$04,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data25:
		.BYTE	$FF
_sjmp_case_14FFF:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$15
		.WORD	_cur_room_sequence_idx
		.BYTE	$15
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$04,$05
		.WORD	_nsub_628FA
		.BYTE	$00,$04,$05
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data26
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data26
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data26
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data26
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15016:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$04,$08,$05	; DATA	  $30,$04,$08,$05
		.BYTE	$D0,$05,$08,$05	; DATA	  $D0,$05,$08,$05
		.BYTE	$0C		; SBCC		  _sloc_15016
		.WORD	_sloc_15016
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$84,$98,$00	; DATA	  $84,$98,$00
		.BYTE	$B8,$98,$00	; DATA	  $B8,$98,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_1506B	; CASE	  _sjmp_case_1506B
		.WORD	_sjmp_case_14F89	; CASE	  _sjmp_case_14F89
_lvl_doors_data26:
		.BYTE	$04,$30,$05,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$40,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$C0,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$50,$05,$50,$05
		.WORD	_room_door_always_open
		.BYTE	$05,$C0,$05,$80,$07
		.WORD	_room_door_always_open
		.BYTE	$05,$D0,$05,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data26:
		.BYTE	$FF
_sjmp_case_1506B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$16
		.WORD	_cur_room_sequence_idx
		.BYTE	$16
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$04,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$04,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data27
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data27
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data27
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data27
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$01
		.WORD	_nsub_apu_mus_load
		.BYTE	$01
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15086:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$30,$04,$08,$03	; DATA	  $30,$04,$08,$03
		.BYTE	$30,$04,$F8,$04	; DATA	  $30,$04,$F8,$04
		.BYTE	$0C		; SBCC		  _sloc_15086
		.WORD	_sloc_15086
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$06,$56,$01	; DATA	  $06,$56,$01
		.BYTE	$84,$A2,$02	; DATA	  $84,$A2,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_150CD	; CASE	  _sjmp_case_150CD
		.WORD	_sjmp_case_14FFF	; CASE	  _sjmp_case_14FFF
_lvl_doors_data27:
		.BYTE	$04,$B0,$04,$70,$07
		.WORD	_room_door_always_open
		.BYTE	$04,$80,$04,$A0,$05
		.WORD	_room_door_always_open
		.BYTE	$04,$30,$04,$D0,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$30,$03,$20,$05
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data27:
		.BYTE	$FF	; *--
_sjmp_case_150CD:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$17
		.WORD	_cur_room_sequence_idx
		.BYTE	$17
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$00,$02
		.WORD	_nsub_628FA
		.BYTE	$02,$00,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data28
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data28
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data28
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data28
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15175
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15175
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_150EE:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$30,$00,$F8,$02	; DATA	  $30,$00,$F8,$02
		.BYTE	$0C		; SBCC		  _sloc_150EE
		.WORD	_sloc_150EE
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$84,$63,$02	; DATA	  $84,$63,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1506B	; CASE	  _sjmp_case_1506B
_lvl_doors_data28:
		.BYTE	$00,$30,$02,$E0,$05
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data28:
		.BYTE	$FF	; *--
_ssub_15117:
		.BYTE	$13		; STORE8	  _lvl_data_prg_bank,$02
		.WORD	_lvl_data_prg_bank
		.BYTE	$02
		.BYTE	$16		; STORE16	  _lvl_room_lib_ptr,_lvl2_room_lib
		.WORD	_lvl_room_lib_ptr
		.WORD	_lvl2_room_lib
		.BYTE	$07		; NJSR		  _nsub_lvl_data_ptrs_load
		.WORD	_nsub_lvl_data_ptrs_load
		.WORD	_lvl2_macroA_tbl	; DATA	  _lvl2_macroA_tbl
		.WORD	_lvl2_macroB_tbl	; DATA	  _lvl2_macroB_tbl
		.WORD	_lvl2_macroC_tbl	; DATA	  _lvl2_macroC_tbl
		.WORD	_lvl2_macroD_tbl	; DATA	  _lvl2_macroD_tbl
		.WORD	_lvl2_attrs_tbl	; DATA	  _lvl2_attrs_tbl
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr4
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr4
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_15159
		.WORD	_nsub_full_pal_load
		.WORD	byte_15159
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$10
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$10
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$07
		.WORD	_nsub_apu_mus_load
		.BYTE	$07
		.BYTE	$09		; NBG_HNDL_SET	  _j_nbgsub_1437C_0
		.WORD	_j_nbgsub_1437C_0
		.BYTE	$07		; NJSR		  _nsub_ingame_collision_watch_start
		.WORD	_nsub_ingame_collision_watch_start
		.BYTE	$07		; NJSR		  _nsub_ingame_player_control_start
		.WORD	_nsub_ingame_player_control_start
		.BYTE	$08,$01		; SRUN		  $01,_scr_14324
		.WORD	_scr_14324
		.BYTE	$16		; STORE16	  _lvl_objects_ptr,_lvl2_objects_list
		.WORD	_lvl_objects_ptr
		.WORD	_lvl2_objects_list
		.BYTE	$07		; NJSR		  _nsub_lvl_room_objects_init
		.WORD	_nsub_lvl_room_objects_init
		.BYTE	$05		; SRET
byte_15159:
		.BYTE	$0F,$30,$10,$00,$0F,$19,$10,$17,$0F,$37,$27,$17,$0F,$30,$10,$1A
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$37,$27,$17
byte_15175:
		.BYTE	$0F,$36,$25,$0F
byte_15179:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B	R O U T	I N E =======================================
_j_nbgsub_1437C_0:
		JMP		_lvl_room_objects_handler
_scr4_lvl4_handler:
		.BYTE	$07		; NJSR		  _nsub_sub_rom_idx_calc
		.WORD	_nsub_sub_rom_idx_calc
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$04		; SJSR		  _ssub_154D2
		.WORD	_ssub_154D2
		.BYTE	$07		; NJSR		  _nsub_room_register,$06
		.WORD	_nsub_room_register
		.BYTE	$06
		.BYTE	$26,$AE,$01	; DATA	  $26,$AE,$01
		.BYTE	$3A,$90,$03	; DATA	  $3A,$90,$03
		.BYTE	$03,$66,$02	; DATA	  $03,$66,$02
		.BYTE	$08,$34,$01	; DATA	  $08,$34,$01
		.BYTE	$51,$27,$02	; DATA	  $51,$27,$02
		.BYTE	$79,$54,$00	; DATA	  $79,$54,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$06		; SJMP_SW	  $06
		.WORD	_sjmp_case_151B4	; CASE	  _sjmp_case_151B4
		.WORD	_sjmp_case_151F4	; CASE	  _sjmp_case_151F4
		.WORD	_sjmp_case_152EB	; CASE	  _sjmp_case_152EB
		.WORD	_sjmp_case_15331	; CASE	  _sjmp_case_15331
		.WORD	_sjmp_case_15388	; CASE	  _sjmp_case_15388
		.WORD	_sjmp_case_1543A	; CASE	  _sjmp_case_1543A
_sjmp_case_151B4:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$00
		.WORD	_cur_room_sequence_idx
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$01,$05
		.WORD	_nsub_628FA
		.BYTE	$02,$01,$05
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data29
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data29
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data29
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data29
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_151CB:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$98,$01,$08,$05	; DATA	  $98,$01,$08,$05
		.BYTE	$0C		; SBCC		  _sloc_151CB
		.WORD	_sloc_151CB
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$32,$97,$00	; DATA	  $32,$97,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_151F4	; CASE	  _sjmp_case_151F4
_lvl_doors_data29:
		.BYTE	$01,$A0,$05,$20,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data29:
		.BYTE	$FF
_sjmp_case_151F4:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$01
		.WORD	_cur_room_sequence_idx
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$01,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$01,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data2A
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data2A
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data2A
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data2A
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1520B:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$01,$A8,$04	; DATA	  $F8,$01,$A8,$04
		.BYTE	$B0,$01,$08,$03	; DATA	  $B0,$01,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_1520B
		.WORD	_sloc_1520B
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$43,$92,$01	; DATA	  $43,$92,$01
		.BYTE	$34,$57,$00	; DATA	  $34,$57,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_1524B	; CASE	  _sjmp_case_1524B
		.WORD	_sjmp_case_1528B	; CASE	  _sjmp_case_1528B
_lvl_doors_data2A:
		.BYTE	$01,$90,$04,$D0,$08
		.WORD	_room_door_always_closed
		.BYTE	$01,$E0,$04,$A0,$09
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$B0,$03,$20,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data2A:
		.BYTE	$FF
_sjmp_case_1524B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$02
		.WORD	_cur_room_sequence_idx
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$04
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data2B
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data2B
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data2B
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data2B
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15262:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$00,$02,$98,$04	; DATA	  $00,$02,$98,$04
		.BYTE	$0C		; SBCC		  _sloc_15262
		.WORD	_sloc_15262
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$3C,$92,$03	; DATA	  $3C,$92,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_151F4	; CASE	  _sjmp_case_151F4
_lvl_doors_data2B:
		.BYTE	$02,$10,$04,$A0,$0A
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data2B:
		.BYTE	$FF
_sjmp_case_1528B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$03
		.WORD	_cur_room_sequence_idx
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data2C
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data2C
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data2C
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data2C
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_152A2:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$03
		.WORD	_nsub_6294B
		.BYTE	$03
		.BYTE	$B0,$01,$F0,$02	; DATA	  $B0,$01,$F0,$02
		.BYTE	$48,$00,$F0,$02	; DATA	  $48,$00,$F0,$02
		.BYTE	$50,$00,$08,$02	; DATA	  $50,$00,$08,$02
		.BYTE	$0C		; SBCC		  _sloc_152A2
		.WORD	_sloc_152A2
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$03
		.WORD	_nsub_room_register
		.BYTE	$03
		.BYTE	$34,$63,$02	; DATA	  $34,$63,$02
		.BYTE	$08,$63,$02	; DATA	  $08,$63,$02
		.BYTE	$08,$37,$00	; DATA	  $08,$37,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$03		; SJMP_SW	  $03
		.WORD	_sjmp_case_151F4	; CASE	  _sjmp_case_151F4
		.WORD	_sjmp_case_152EB	; CASE	  _sjmp_case_152EB
		.WORD	_sjmp_case_15331	; CASE	  _sjmp_case_15331
_lvl_doors_data2C:
		.BYTE	$01,$B0,$02,$D0,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$50,$02,$D0,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$50,$02,$20,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data2C:
		.BYTE	$FF
_sjmp_case_152EB:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$04
		.WORD	_cur_room_sequence_idx
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$00,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$00,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data2D
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data2D
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data2D
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data2D
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15302:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$50,$00,$08,$03	; DATA	  $50,$00,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_15302
		.WORD	_sloc_15302
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$08,$57,$00	; DATA	  $08,$57,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1528B	; CASE	  _sjmp_case_1528B
_lvl_doors_data2D:
		.BYTE	$00,$50,$03,$20,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data2D:
		.BYTE	$2C,$2C,$2C,$29,$29,$2C,$00
_sjmp_case_15331:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$05
		.WORD	_cur_room_sequence_idx
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$01
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$01
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data2E
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data2E
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data2E
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data2E
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15348:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$50,$00,$F0,$01	; DATA	  $50,$00,$F0,$01
		.BYTE	$F8,$01,$28,$01	; DATA	  $F8,$01,$28,$01
		.BYTE	$0C		; SBCC		  _sloc_15348
		.WORD	_sloc_15348
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$08,$43,$02	; DATA	  $08,$43,$02
		.BYTE	$44,$24,$01	; DATA	  $44,$24,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_1528B	; CASE	  _sjmp_case_1528B
		.WORD	_sjmp_case_15388	; CASE	  _sjmp_case_15388
_lvl_doors_data2E:
		.BYTE	$00,$50,$01,$D0,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$E0,$01,$30,$10
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$00,$01,$80,$0B
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data2E:
		.BYTE	$FF
_sjmp_case_15388:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$06
		.WORD	_cur_room_sequence_idx
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$02,$01
		.WORD	_nsub_628FA
		.BYTE	$01,$02,$01
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data2F
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data2F
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data2F
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data2F
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1539F:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$00,$02,$30,$01	; DATA	  $00,$02,$30,$01
		.BYTE	$60,$02,$F0,$02	; DATA	  $60,$02,$F0,$02
		.BYTE	$0C		; SBCC		  _sloc_1539F
		.WORD	_sloc_1539F
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$3C,$24,$03	; DATA	  $3C,$24,$03
		.BYTE	$4A,$63,$02	; DATA	  $4A,$63,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15331	; CASE	  _sjmp_case_15331
		.WORD	_sjmp_case_153E1	; CASE	  _sjmp_case_153E1
_lvl_doors_data2F:
		.BYTE	$02,$10,$01,$30,$0C
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$60,$02,$D0,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data2F:
		.BYTE	$2B,$2B,$2B,$2B,$2D,$2D,$2D,$2D,$2C,$00
_sjmp_case_153E1:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$07
		.WORD	_cur_room_sequence_idx
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$03
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data30
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data30
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data30
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data30
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_153F8:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$60,$02,$08,$03	; DATA	  $60,$02,$08,$03
		.BYTE	$C0,$03,$08,$03	; DATA	  $C0,$03,$08,$03
		.BYTE	$0C		; SBCC		  _sloc_153F8
		.WORD	_sloc_153F8
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$4A,$57,$00	; DATA	  $4A,$57,$00
		.BYTE	$76,$57,$00	; DATA	  $76,$57,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15388	; CASE	  _sjmp_case_15388
		.WORD	_sjmp_case_1543A	; CASE	  _sjmp_case_1543A
_lvl_doors_data30:
		.BYTE	$02,$60,$03,$20,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$C0,$03,$20,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data30:
		.BYTE	$29,$2D,$29,$2D,$29,$29,$2D,$2D,$2B,$00
_sjmp_case_1543A:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$08
		.WORD	_cur_room_sequence_idx
		.BYTE	$08
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$03,$01
		.WORD	_nsub_628FA
		.BYTE	$01,$03,$01
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data31
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data31
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data31
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data31
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15451:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$C0,$03,$F0,$02	; DATA	  $C0,$03,$F0,$02
		.BYTE	$28,$03,$08,$01	; DATA	  $28,$03,$08,$01
		.BYTE	$0C		; SBCC		  _sloc_15451
		.WORD	_sloc_15451
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$76,$64,$02	; DATA	  $76,$64,$02
		.BYTE	$63,$17,$00	; DATA	  $63,$17,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_153E1	; CASE	  _sjmp_case_153E1
		.WORD	_sjmp_case_15492	; CASE	  _sjmp_case_15492
_lvl_doors_data31:
		.BYTE	$03,$C0,$02,$D0,$08
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$20,$01,$20,$0D
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data31:
		.BYTE	$29,$2D,$2D,$2C,$29,$2D,$2C,$2D,$00
_sjmp_case_15492:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$09
		.WORD	_cur_room_sequence_idx
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$03,$00
		.WORD	_nsub_628FA
		.BYTE	$02,$03,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data32
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data32
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data32
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data32
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_154A9:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$18,$03,$F0,$00	; DATA	  $18,$03,$F0,$00
		.BYTE	$0C		; SBCC		  _sloc_154A9
		.WORD	_sloc_154A9
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$63,$23,$02	; DATA	  $63,$23,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_1543A	; CASE	  _sjmp_case_1543A
_lvl_doors_data32:
		.BYTE	$03,$20,$00,$D0,$0D
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data32:
		.BYTE	$FF
_ssub_154D2:
		.BYTE	$13		; STORE8	  _lvl_data_prg_bank,$05
		.WORD	_lvl_data_prg_bank
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_lvl_data_ptrs_load
		.WORD	_nsub_lvl_data_ptrs_load
		.WORD	_lvl3_macroA_tbl	; DATA	  _lvl3_macroA_tbl
		.WORD	_lvl3_macroB_tbl	; DATA	  _lvl3_macroB_tbl
		.WORD	_lvl3_macroC_tbl	; DATA	  _lvl3_macroC_tbl
		.WORD	_lvl3_macroD_tbl	; DATA	  _lvl3_macroD_tbl
		.WORD	_lvl3_attrs_tbl	; DATA	  _lvl3_attrs_tbl
		.BYTE	$16		; STORE16	  _lvl_room_lib_ptr,_lvl3_room_lib
		.WORD	_lvl_room_lib_ptr
		.WORD	_lvl3_room_lib
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr5
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr5
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_15514
		.WORD	_nsub_full_pal_load
		.WORD	byte_15514
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$12
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$12
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$11
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$11
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$08
		.WORD	_nsub_apu_mus_load
		.BYTE	$08
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_15534
		.WORD	_nbgsub_15534
		.BYTE	$07		; NJSR		  _nsub_ingame_collision_watch_start
		.WORD	_nsub_ingame_collision_watch_start
		.BYTE	$07		; NJSR		  _nsub_ingame_player_control_start
		.WORD	_nsub_ingame_player_control_start
		.BYTE	$08,$01		; SRUN		  $01,_scr_14324
		.WORD	_scr_14324
		.BYTE	$16		; STORE16	  _lvl_objects_ptr,_lvl3_objects_list
		.WORD	_lvl_objects_ptr
		.WORD	_lvl3_objects_list
		.BYTE	$07		; NJSR		  _nsub_lvl_room_objects_init
		.WORD	_nsub_lvl_room_objects_init
		.BYTE	$05		; SRET
byte_15514:
		.BYTE	$0F,$30,$10,$00,$0F,$26,$17,$05,$0F,$37,$17,$08,$0F,$07,$15,$05
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$39,$2C,$0F,$0F,$15,$0F,$0F

; =============== S U B	R O U T	I N E =======================================
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
		JSR		sub_62069
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
_scr5_lvl5_handler:
		.BYTE	$07		; NJSR		  _nsub_sub_rom_idx_calc
		.WORD	_nsub_sub_rom_idx_calc
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$04		; SJSR		  _ssub_15CDB
		.WORD	_ssub_15CDB
		.BYTE	$07		; NJSR		  _nsub_room_register,$05
		.WORD	_nsub_room_register
		.BYTE	$05
		.BYTE	$4D,$D4,$00	; DATA	  $4D,$D4,$00
		.BYTE	$98,$92,$02	; DATA	  $98,$92,$02
		.BYTE	$08,$93,$01	; DATA	  $08,$93,$01
		.BYTE	$23,$29,$02	; DATA	  $23,$29,$02
		.BYTE	$94,$34,$00	; DATA	  $94,$34,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$05		; SJMP_SW	  $05
		.WORD	_sjmp_case_155A2	; CASE	  _sjmp_case_155A2
		.WORD	_sjmp_case_15691	; CASE	  _sjmp_case_15691
		.WORD	_sjmp_case_158DB	; CASE	  _sjmp_case_158DB
		.WORD	_sjmp_case_15A91	; CASE	  _sjmp_case_15A91
		.WORD	_sjmp_case_15BE7	; CASE	  _sjmp_case_15BE7
_sjmp_case_155A2:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$00
		.WORD	_cur_room_sequence_idx
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$02,$06
		.WORD	_nsub_628FA
		.BYTE	$02,$02,$06
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data33
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data33
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data33
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data33
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_155B9:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$40,$02,$08,$06	; DATA	  $40,$02,$08,$06
		.BYTE	$0C		; SBCC		  _sloc_155B9
		.WORD	_sloc_155B9
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$46,$B9,$00	; DATA	  $46,$B9,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_155E9	; CASE	  _sjmp_case_155E9
_lvl_doors_data33:
		.BYTE	$02,$40,$06,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$40,$06,$D0,$0E
		.WORD	_room_door_always_closed
		.BYTE	$FF
_prize_sequence_data33:
		.BYTE	$FF	; *--
_sjmp_case_155E9:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$01
		.WORD	_cur_room_sequence_idx
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$05
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$05
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data34
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data34
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data34
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data34
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15604:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$03,$50,$05	; DATA	  $F8,$03,$50,$05
		.BYTE	$40,$02,$F8,$05	; DATA	  $40,$02,$F8,$05
		.BYTE	$0C		; SBCC		  _sloc_15604
		.WORD	_sloc_15604
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$83,$A7,$01	; DATA	  $83,$A7,$01
		.BYTE	$46,$C3,$02	; DATA	  $46,$C3,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_1563D	; CASE	  _sjmp_case_1563D
		.WORD	_sjmp_case_155A2	; CASE	  _sjmp_case_155A2
_lvl_doors_data34:
		.BYTE	$02,$40,$05,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$E0,$05,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data34:
		.BYTE	$FF
_sjmp_case_1563D:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$02
		.WORD	_cur_room_sequence_idx
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$04,$05
		.WORD	_nsub_628FA
		.BYTE	$02,$04,$05
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data35
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data35
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data35
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data35
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0D
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0D
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15658:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$A8,$04,$08,$05	; DATA	  $A8,$04,$08,$05
		.BYTE	$00,$04,$48,$05	; DATA	  $00,$04,$48,$05
		.BYTE	$0C		; SBCC		  _sloc_15658
		.WORD	_sloc_15658
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$94,$99,$00	; DATA	  $94,$99,$00
		.BYTE	$7C,$A7,$03	; DATA	  $7C,$A7,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15691	; CASE	  _sjmp_case_15691
		.WORD	_sjmp_case_155E9	; CASE	  _sjmp_case_155E9
_lvl_doors_data35:
		.BYTE	$04,$10,$05,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$B0,$05,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data35:
		.BYTE	$FF
_sjmp_case_15691:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$03
		.WORD	_cur_room_sequence_idx
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$04,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$04,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data36
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data36
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data36
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data36
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_626B7,$06,byte_15D35
		.WORD	_nsub_626B7
		.BYTE	$06
		.WORD	byte_15D35
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_156B2:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$03
		.WORD	_nsub_6294B
		.BYTE	$03
		.BYTE	$00,$04,$50,$03	; DATA	  $00,$04,$50,$03
		.BYTE	$F8,$04,$50,$03	; DATA	  $F8,$04,$50,$03
		.BYTE	$B0,$04,$F8,$04	; DATA	  $B0,$04,$F8,$04
		.BYTE	$0C		; SBCC		  _sloc_156B2
		.WORD	_sloc_156B2
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$03
		.WORD	_nsub_room_register
		.BYTE	$03
		.BYTE	$7C,$67,$03	; DATA	  $7C,$67,$03
		.BYTE	$A3,$67,$01	; DATA	  $A3,$67,$01
		.BYTE	$94,$A3,$02	; DATA	  $94,$A3,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$03		; SJMP_SW	  $03
		.WORD	_sjmp_case_1573F	; CASE	  _sjmp_case_1573F
		.WORD	_sjmp_case_156FB	; CASE	  _sjmp_case_156FB
		.WORD	_sjmp_case_1563D	; CASE	  _sjmp_case_1563D
_lvl_doors_data36:
		.BYTE	$04,$B0,$04,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$E0,$03,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$10,$03,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data36:
		.BYTE	$FF
_sjmp_case_156FB:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$04
		.WORD	_cur_room_sequence_idx
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$05,$03
		.WORD	_nsub_628FA
		.BYTE	$02,$05,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_room_doors_data37
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_room_doors_data37
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data37
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data37
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15716:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$00,$05,$50,$03	; DATA	  $00,$05,$50,$03
		.BYTE	$0C		; SBCC		  _sloc_15716
		.WORD	_sloc_15716
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$9C,$67,$03	; DATA	  $9C,$67,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
; NOTE: SJMP_SW here has only single case entry, but number here is 2
; this not cause any bugs, but incorrect.
;
		.BYTE	$11,$02		; SJMP_SW	  $01
		.WORD	_sjmp_case_15691	; CASE	  _sjmp_case_15691
_room_doors_data37:
		.BYTE	$05,$10,$03,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data37:
		.BYTE	$FF
_sjmp_case_1573F:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$05
		.WORD	_cur_room_sequence_idx
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$03,$03
		.WORD	_nsub_628FA
		.BYTE	$02,$03,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$12
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$12
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data38
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data38
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data38
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data38
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1575A:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$03,$50,$03	; DATA	  $F8,$03,$50,$03
		.BYTE	$B0,$03,$F8,$03	; DATA	  $B0,$03,$F8,$03
		.BYTE	$0C		; SBCC		  _sloc_1575A
		.WORD	_sloc_1575A
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$83,$67,$01	; DATA	  $83,$67,$01
		.BYTE	$74,$83,$02	; DATA	  $74,$83,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15691	; CASE	  _sjmp_case_15691
		.WORD	_sjmp_case_15793	; CASE	  _sjmp_case_15793
_lvl_doors_data38:
		.BYTE	$03,$E0,$03,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$B0,$03,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data38:
		.BYTE	$FF
_sjmp_case_15793:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$06
		.WORD	_cur_room_sequence_idx
		.BYTE	$06
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$02,$04
		.WORD	_nsub_628FA
		.BYTE	$00,$02,$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data39
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data39
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data39
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data39
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_157AA:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$B0,$03,$08,$04	; DATA	  $B0,$03,$08,$04
		.BYTE	$00,$02,$50,$04	; DATA	  $00,$02,$50,$04
		.BYTE	$0C		; SBCC		  _sloc_157AA
		.WORD	_sloc_157AA
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$74,$79,$00	; DATA	  $74,$79,$00
		.BYTE	$3C,$87,$03	; DATA	  $3C,$87,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_1573F	; CASE	  _sjmp_case_1573F
		.WORD	_sjmp_case_157E3	; CASE	  _sjmp_case_157E3
_lvl_doors_data39:
		.BYTE	$03,$B0,$04,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$10,$04,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data39:
		.BYTE	$FF
_sjmp_case_157E3:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$07
		.WORD	_cur_room_sequence_idx
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$01,$04
		.WORD	_nsub_628FA
		.BYTE	$01,$01,$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data3A
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data3A
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data3A
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data3A
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_157FA:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$03
		.WORD	_nsub_6294B
		.BYTE	$03
		.BYTE	$F8,$01,$50,$04	; DATA	  $F8,$01,$50,$04
		.BYTE	$B0,$01,$F8,$05	; DATA	  $B0,$01,$F8,$05
		.BYTE	$00,$01,$A0,$05	; DATA	  $00,$01,$A0,$05
		.BYTE	$0C		; SBCC		  _sloc_157FA
		.WORD	_sloc_157FA
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$03
		.WORD	_nsub_room_register
		.BYTE	$03
		.BYTE	$43,$87,$01	; DATA	  $43,$87,$01
		.BYTE	$34,$C3,$02	; DATA	  $34,$C3,$02
		.BYTE	$1C,$B1,$03	; DATA	  $1C,$B1,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$03		; SJMP_SW	  $03
		.WORD	_sjmp_case_15793	; CASE	  _sjmp_case_15793
		.WORD	_sjmp_case_15843	; CASE	  _sjmp_case_15843
		.WORD	_sjmp_case_15887	; CASE	  _sjmp_case_15887
_lvl_doors_data3A:
		.BYTE	$01,$E0,$04,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$B0,$05,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$10,$05,$A0,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data3A:
		.BYTE	$FF
_sjmp_case_15843:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$08
		.WORD	_cur_room_sequence_idx
		.BYTE	$08
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$01,$06
		.WORD	_nsub_628FA
		.BYTE	$02,$01,$06
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$12
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$12
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data3B
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data3B
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data3B
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data3B
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1585E:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$B0,$01,$08,$06	; DATA	  $B0,$01,$08,$06
		.BYTE	$0C		; SBCC		  _sloc_1585E
		.WORD	_sloc_1585E
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$34,$B9,$00	; DATA	  $34,$B9,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_157E3	; CASE	  _sjmp_case_157E3
_lvl_doors_data3B:
		.BYTE	$01,$B0,$06,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data3B:
		.BYTE	$FF
_sjmp_case_15887:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$09
		.WORD	_cur_room_sequence_idx
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$00,$05
		.WORD	_nsub_628FA
		.BYTE	$02,$00,$05
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$07
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data3C
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data3C
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data3C
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data3C
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_158A2:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$00,$A0,$05	; DATA	  $F8,$00,$A0,$05
		.BYTE	$40,$00,$08,$05	; DATA	  $40,$00,$08,$05
		.BYTE	$0C		; SBCC		  _sloc_158A2
		.WORD	_sloc_158A2
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$23,$B1,$01	; DATA	  $23,$B1,$01
		.BYTE	$06,$99,$00	; DATA	  $06,$99,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_157E3	; CASE	  _sjmp_case_157E3
		.WORD	_sjmp_case_158DB	; CASE	  _sjmp_case_158DB
_lvl_doors_data3C:
		.BYTE	$00,$40,$05,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$E0,$05,$A0,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data3C:
		.BYTE	$FF
_sjmp_case_158DB:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0A
		.WORD	_cur_room_sequence_idx
		.BYTE	$0A
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$00,$03
		.WORD	_nsub_628FA
		.BYTE	$01,$00,$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_15D1D
		.WORD	_nsub_full_pal_load
		.WORD	byte_15D1D
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data3D
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data3D
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data3D
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data3D
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_158FB:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$40,$00,$F8,$04	; DATA	  $40,$00,$F8,$04
		.BYTE	$F8,$00,$50,$03	; DATA	  $F8,$00,$50,$03
		.BYTE	$0C		; SBCC		  _sloc_158FB
		.WORD	_sloc_158FB
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$06,$A3,$02	; DATA	  $06,$A3,$02
		.BYTE	$23,$67,$01	; DATA	  $23,$67,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15887	; CASE	  _sjmp_case_15887
		.WORD	_sjmp_case_15934	; CASE	  _sjmp_case_15934
_lvl_doors_data3D:
		.BYTE	$00,$40,$04,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$E0,$03,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data3D:
		.BYTE	$FF
_sjmp_case_15934:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0B
		.WORD	_cur_room_sequence_idx
		.BYTE	$0B
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$01,$03
		.WORD	_nsub_628FA
		.BYTE	$02,$01,$03
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data3E
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data3E
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data3E
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data3E
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1594B:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$01,$A0,$03	; DATA	  $F8,$01,$A0,$03
		.BYTE	$00,$01,$50,$03	; DATA	  $00,$01,$50,$03
		.BYTE	$0C		; SBCC		  _sloc_1594B
		.WORD	_sloc_1594B
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$43,$71,$01	; DATA	  $43,$71,$01
		.BYTE	$1C,$67,$03	; DATA	  $1C,$67,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15984	; CASE	  _sjmp_case_15984
		.WORD	_sjmp_case_158DB	; CASE	  _sjmp_case_158DB
_lvl_doors_data3E:
		.BYTE	$01,$10,$03,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$E0,$03,$A0,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data3E:
		.BYTE	$FF
_sjmp_case_15984:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0C
		.WORD	_cur_room_sequence_idx
		.BYTE	$0C
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$02,$02
		.WORD	_nsub_628FA
		.BYTE	$01,$02,$02
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data3F
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data3F
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data3F
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data3F
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_1599F:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$00,$02,$50,$02	; DATA	  $00,$02,$50,$02
		.BYTE	$00,$02,$A0,$03	; DATA	  $00,$02,$A0,$03
		.BYTE	$0C		; SBCC		  _sloc_1599F
		.WORD	_sloc_1599F
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$3C,$47,$03	; DATA	  $3C,$47,$03
		.BYTE	$3C,$71,$03	; DATA	  $3C,$71,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_159DF	; CASE	  _sjmp_case_159DF
		.WORD	_sjmp_case_15934	; CASE	  _sjmp_case_15934
_lvl_doors_data3F:
		.BYTE	$02,$10,$03,$A0,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$10,$02,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data3F:
		.BYTE	$19,$18,$19,$19,$19,$18,$18,$00
_sjmp_case_159DF:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0D
		.WORD	_cur_room_sequence_idx
		.BYTE	$0D
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$00,$02
		.WORD	_nsub_628FA
		.BYTE	$00,$00,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data40
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data40
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data40
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data40
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_159F6:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$40,$00,$08,$02	; DATA	  $40,$00,$08,$02
		.BYTE	$F8,$01,$50,$02	; DATA	  $F8,$01,$50,$02
		.BYTE	$0C		; SBCC		  _sloc_159F6
		.WORD	_sloc_159F6
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$06,$39,$00	; DATA	  $06,$39,$00
		.BYTE	$42,$47,$01	; DATA	  $42,$47,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15A37	; CASE	  _sjmp_case_15A37
		.WORD	_sjmp_case_15984	; CASE	  _sjmp_case_15984
_lvl_doors_data40:
		.BYTE	$01,$E0,$02,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$40,$02,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data40:
		.BYTE	$13,$13,$19,$19,$19,$19,$17,$17,$00
_sjmp_case_15A37:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0E
		.WORD	_cur_room_sequence_idx
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$00,$01
		.WORD	_nsub_628FA
		.BYTE	$02,$00,$01
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0F
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15179
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15179
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data41
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data41
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data41
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data41
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15A58:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$00,$50,$01	; DATA	  $F8,$00,$50,$01
		.BYTE	$40,$00,$F8,$01	; DATA	  $40,$00,$F8,$01
		.BYTE	$0C		; SBCC		  _sloc_15A58
		.WORD	_sloc_15A58
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$23,$27,$01	; DATA	  $23,$27,$01
		.BYTE	$06,$43,$02	; DATA	  $06,$43,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15A91	; CASE	  _sjmp_case_15A91
		.WORD	_sjmp_case_159DF	; CASE	  _sjmp_case_159DF
_lvl_doors_data41:
		.BYTE	$00,$E0,$01,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$00,$40,$01,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data41:
		.BYTE	$FF
_sjmp_case_15A91:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$0F
		.WORD	_cur_room_sequence_idx
		.BYTE	$0F
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$01,$01
		.WORD	_nsub_628FA
		.BYTE	$00,$01,$01
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15D39
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15D39
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data42
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data42
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data42
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data42
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15AB2:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$03
		.WORD	_nsub_6294B
		.BYTE	$03
		.BYTE	$F8,$02,$50,$01	; DATA	  $F8,$02,$50,$01
		.BYTE	$00,$01,$50,$01	; DATA	  $00,$01,$50,$01
		.BYTE	$70,$01,$08,$01	; DATA	  $70,$01,$08,$01
		.BYTE	$0C		; SBCC		  _sloc_15AB2
		.WORD	_sloc_15AB2
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$03
		.WORD	_nsub_room_register
		.BYTE	$03
		.BYTE	$63,$27,$01	; DATA	  $63,$27,$01
		.BYTE	$1C,$27,$03	; DATA	  $1C,$27,$03
		.BYTE	$2C,$19,$00	; DATA	  $2C,$19,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$03		; SJMP_SW	  $03
		.WORD	_sjmp_case_15B3F	; CASE	  _sjmp_case_15B3F
		.WORD	_sjmp_case_15A37	; CASE	  _sjmp_case_15A37
		.WORD	_sjmp_case_15AFB	; CASE	  _sjmp_case_15AFB
_lvl_doors_data42:
		.BYTE	$01,$70,$01,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$01,$10,$01,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$02,$E0,$01,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data42:
		.BYTE	$FF
_sjmp_case_15AFB:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$10
		.WORD	_cur_room_sequence_idx
		.BYTE	$10
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$01,$00
		.WORD	_nsub_628FA
		.BYTE	$02,$01,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data43
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data43
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data43
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data43
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15B16:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$70,$01,$F8,$00	; DATA	  $70,$01,$F8,$00
		.BYTE	$0C		; SBCC		  _sloc_15B16
		.WORD	_sloc_15B16
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$2C,$23,$02	; DATA	  $2C,$23,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_15A91	; CASE	  _sjmp_case_15A91
_lvl_doors_data43:
		.BYTE	$01,$70,$00,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data43:
		.BYTE	$FF
_sjmp_case_15B3F:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$11
		.WORD	_cur_room_sequence_idx
		.BYTE	$11
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$03,$01
		.WORD	_nsub_628FA
		.BYTE	$01,$03,$01
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data44
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data44
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data44
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data44
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15B5A:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$F8,$03,$A0,$02	; DATA	  $F8,$03,$A0,$02
		.BYTE	$00,$03,$50,$01	; DATA	  $00,$03,$50,$01
		.BYTE	$0C		; SBCC		  _sloc_15B5A
		.WORD	_sloc_15B5A
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$83,$51,$01	; DATA	  $83,$51,$01
		.BYTE	$5C,$27,$03	; DATA	  $5C,$27,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15B93	; CASE	  _sjmp_case_15B93
		.WORD	_sjmp_case_15A91	; CASE	  _sjmp_case_15A91
_lvl_doors_data44:
		.BYTE	$03,$10,$01,$50,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$E0,$02,$A0,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data44:
		.BYTE	$FF
_sjmp_case_15B93:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$12
		.WORD	_cur_room_sequence_idx
		.BYTE	$12
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$04,$02
		.WORD	_nsub_628FA
		.BYTE	$02,$04,$02
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data45
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data45
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data45
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data45
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15BAE:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$B0,$04,$08,$02	; DATA	  $B0,$04,$08,$02
		.BYTE	$00,$04,$A0,$02	; DATA	  $00,$04,$A0,$02
		.BYTE	$0C		; SBCC		  _sloc_15BAE
		.WORD	_sloc_15BAE
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$94,$39,$00	; DATA	  $94,$39,$00
		.BYTE	$7C,$51,$03	; DATA	  $7C,$51,$03
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15BE7	; CASE	  _sjmp_case_15BE7
		.WORD	_sjmp_case_15B3F	; CASE	  _sjmp_case_15B3F
_lvl_doors_data45:
		.BYTE	$04,$10,$02,$A0,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$B0,$02,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data45:
		.BYTE	$FF
_sjmp_case_15BE7:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$13
		.WORD	_cur_room_sequence_idx
		.BYTE	$13
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$04,$01
		.WORD	_nsub_628FA
		.BYTE	$02,$04,$01
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0C
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0C
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15D3D
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15D3D
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data46
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data46
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data46
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data46
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15C08:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$B0,$04,$08,$01	; DATA	  $B0,$04,$08,$01
		.BYTE	$B4,$04,$F8,$01	; DATA	  $B4,$04,$F8,$01
		.BYTE	$0C		; SBCC		  _sloc_15C08
		.WORD	_sloc_15C08
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$94,$19,$00	; DATA	  $94,$19,$00
		.BYTE	$94,$43,$02	; DATA	  $94,$43,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15C41	; CASE	  _sjmp_case_15C41
		.WORD	_sjmp_case_15B93	; CASE	  _sjmp_case_15B93
_lvl_doors_data46:
		.BYTE	$04,$B0,$01,$20,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$04,$B0,$01,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data46:
		.BYTE	$FF
_sjmp_case_15C41:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$14
		.WORD	_cur_room_sequence_idx
		.BYTE	$14
		.BYTE	$07		; NJSR		  _nsub_628FA,$00,$03,$00
		.WORD	_nsub_628FA
		.BYTE	$00,$03,$00
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$18
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$18
		.BYTE	$07		; NJSR		  _nsub_626B7,$07,byte_15D39
		.WORD	_nsub_626B7
		.BYTE	$07
		.WORD	byte_15D39
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data47
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data47
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data47
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data47
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15C62:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$00,$03,$70,$00	; DATA	  $00,$03,$70,$00
		.BYTE	$B0,$04,$F8,$00	; DATA	  $B0,$04,$F8,$00
		.BYTE	$0C		; SBCC		  _sloc_15C62
		.WORD	_sloc_15C62
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$5C,$0C,$03	; DATA	  $5C,$0C,$03
		.BYTE	$94,$23,$02	; DATA	  $94,$23,$02
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15C9B	; CASE	  _sjmp_case_15C9B
		.WORD	_sjmp_case_15BE7	; CASE	  _sjmp_case_15BE7
_lvl_doors_data47:
		.BYTE	$04,$B0,$00,$D0,$0E
		.WORD	_room_door_enemy_clear_open
		.BYTE	$03,$10,$00,$70,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data47:
		.BYTE	$FF	; *--
_sjmp_case_15C9B:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$15
		.WORD	_cur_room_sequence_idx
		.BYTE	$15
		.BYTE	$07		; NJSR		  _nsub_628FA,$02,$02,$00
		.WORD	_nsub_628FA
		.BYTE	$02,$02,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data48
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data48
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data48
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data48
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15CB2:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$01
		.WORD	_nsub_6294B
		.BYTE	$01
		.BYTE	$F8,$02,$70,$00	; DATA	  $F8,$02,$70,$00
		.BYTE	$0C		; SBCC		  _sloc_15CB2
		.WORD	_sloc_15CB2
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$63,$0C,$01	; DATA	  $63,$0C,$01
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_15C41	; CASE	  _sjmp_case_15C41
_lvl_doors_data48:
		.BYTE	$02,$E0,$00,$70,$0F
		.WORD	_room_door_enemy_clear_open
		.BYTE	$FF
_prize_sequence_data48:
		.BYTE	$FF
_ssub_15CDB:
		.BYTE	$13		; STORE8	  _lvl_data_prg_bank,$05
		.WORD	_lvl_data_prg_bank
		.BYTE	$05
		.BYTE	$16		; STORE16	  _lvl_room_lib_ptr,_lvl4_room_lib
		.WORD	_lvl_room_lib_ptr
		.WORD	_lvl4_room_lib
		.BYTE	$07		; NJSR		  _nsub_lvl_data_ptrs_load
		.WORD	_nsub_lvl_data_ptrs_load
		.WORD	_lvl4_macroA_tbl	; DATA	  _lvl4_macroA_tbl
		.WORD	_lvl4_macroB_tbl	; DATA	  _lvl4_macroB_tbl
		.WORD	_lvl4_macroC_tbl	; DATA	  _lvl4_macroC_tbl
		.WORD	_lvl4_macroD_tbl	; DATA	  _lvl4_macroD_tbl
		.WORD	_lvl4_attrs_tbl	; DATA	  _lvl4_attrs_tbl
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl_data0_ptr6
		.WORD	_lvl_data0_ptr
		.WORD	_lvl_data0_ptr6
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_15D1D
		.WORD	_nsub_full_pal_load
		.WORD	byte_15D1D
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$0E
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$0E
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$15
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$15
		.BYTE	$09		; NBG_HNDL_SET	  _j_nbgsub_1437C_1
		.WORD	_j_nbgsub_1437C_1
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$09
		.WORD	_nsub_apu_mus_load
		.BYTE	$09
		.BYTE	$07		; NJSR		  _nsub_ingame_collision_watch_start
		.WORD	_nsub_ingame_collision_watch_start
		.BYTE	$07		; NJSR		  _nsub_ingame_player_control_start
		.WORD	_nsub_ingame_player_control_start
		.BYTE	$08,$01		; SRUN		  $01,_scr_14324
		.WORD	_scr_14324
		.BYTE	$16		; STORE16	  _lvl_objects_ptr,_lvl4_objects_list
		.WORD	_lvl_objects_ptr
		.WORD	_lvl4_objects_list
		.BYTE	$07		; NJSR		  _nsub_lvl_room_objects_init
		.WORD	_nsub_lvl_room_objects_init
		.BYTE	$05		; SRET
byte_15D1D:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$01,$0F,$30,$27,$01,$0F,$30,$15,$07
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15
byte_15D35:
		.BYTE	$0F,$36,$26,$0F
byte_15D39:
		.BYTE	$0F,$36,$26,$0F
byte_15D3D:
		.BYTE	$0F,$36,$27,$0F

; =============== S U B	R O U T	I N E =======================================
_j_nbgsub_1437C_1:
		JMP		_lvl_room_objects_handler
_scr6_lvl6_handler:
		.BYTE	$07		; NJSR		  _nsub_sub_rom_idx_calc
		.WORD	_nsub_sub_rom_idx_calc
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$04		; SJSR		  _ssub_15DD6
		.WORD	_ssub_15DD6
		.BYTE	$07		; NJSR		  _nsub_room_register,$01
		.WORD	_nsub_room_register
		.BYTE	$01
		.BYTE	$0E,$73,$00	; DATA	  $0E,$73,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_15D5F	; CASE	  _sjmp_case_15D5F
_sjmp_case_15D5F:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$00
		.WORD	_cur_room_sequence_idx
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$00,$02
		.WORD	_nsub_628FA
		.BYTE	$01,$00,$02
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data49
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data49
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data49
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data49
		.BYTE	$04		; SJSR		  _ssub_62DB1
		.WORD	_ssub_62DB1
_sloc_15D76:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_6294B,$02
		.WORD	_nsub_6294B
		.BYTE	$02
		.BYTE	$70,$00,$10,$02	; DATA	  $70,$00,$10,$02
		.BYTE	$90,$00,$10,$02	; DATA	  $90,$00,$10,$02
		.BYTE	$0C		; SBCC		  _sloc_15D76
		.WORD	_sloc_15D76
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_room_register,$02
		.WORD	_nsub_room_register
		.BYTE	$02
		.BYTE	$0E,$36,$00	; DATA	  $0E,$36,$00
		.BYTE	$0E,$36,$00	; DATA	  $0E,$36,$00
		.BYTE	$07		; NJSR		  _nsub_read_mem,_sub_room_idx
		.WORD	_nsub_read_mem
		.WORD	_sub_room_idx
		.BYTE	$11,$02		; SJMP_SW	  $02
		.WORD	_sjmp_case_15DA1	; CASE	  _sjmp_case_15DA1
		.WORD	_sjmp_case_15DA1	; CASE	  _sjmp_case_15DA1
_lvl_doors_data49:
		.BYTE	$FF
_prize_sequence_data49:
		.BYTE	$FF	; *--
_sjmp_case_15DA1:
		.BYTE	$13		; STORE8	  _cur_room_sequence_idx,$01
		.WORD	_cur_room_sequence_idx
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_628FA,$01,$00,$00
		.WORD	_nsub_628FA
		.BYTE	$01,$00,$00
		.BYTE	$07		; NJSR		  _nsub_room_doors_handler_and_data_init,_lvl_doors_data4A
		.WORD	_nsub_room_doors_handler_and_data_init
		.WORD	_lvl_doors_data4A
		.BYTE	$16		; STORE16	  _room_prize_sequence_ptr,_prize_sequence_data4A
		.WORD	_room_prize_sequence_ptr
		.WORD	_prize_sequence_data4A
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$DD
		.WORD	_nsub_counters_inc
		.BYTE	$DD
		.BYTE	$06,$03		; SDELAY	  $03
		.BYTE	$02		; SLOOP_END
		.BYTE	$13		; STORE8	  _scr_trds_priority_mode,$00
		.WORD	_scr_trds_priority_mode
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_15E3B
		.WORD	_nsub_15E3B
		.BYTE	$80,$80,$FF	; SCRL_Y_MOVE_SET 0,$80,$FF
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$C8		; SCRL_MOVE_STOP  0
		.BYTE	$13		; STORE8	  _cur_room_x_pageB,$00
		.WORD	_cur_room_x_pageB
		.BYTE	$00
		.BYTE	$0A		; SUSPEND
_lvl_doors_data4A:
		.BYTE	$FF
_prize_sequence_data4A:
		.BYTE	$FF	; *--
_ssub_15DD6:
		.BYTE	$13		; STORE8	  _lvl_data_prg_bank,$03
		.WORD	_lvl_data_prg_bank
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_lvl_data_ptrs_load
		.WORD	_nsub_lvl_data_ptrs_load
		.WORD	_lvl5_macroA_tbl	; DATA	  _lvl5_macroA_tbl
		.WORD	_lvl5_macroB_tbl	; DATA	  _lvl5_macroB_tbl
		.WORD	_lvl5_macroC_tbl	; DATA	  _lvl5_macroC_tbl
		.WORD	_lvl5_macroD_tbl	; DATA	  _lvl5_macroD_tbl
		.WORD	_lvl5_macroE_tbl	; DATA	  _lvl5_macroE_tbl
		.BYTE	$16		; STORE16	  _lvl_room_lib_ptr,_lvl5_room_lib
		.WORD	_lvl_room_lib_ptr
		.WORD	_lvl5_room_lib
		.BYTE	$16		; STORE16	  _lvl_data0_ptr,_lvl5_data0_list
		.WORD	_lvl_data0_ptr
		.WORD	_lvl5_data0_list
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_15E18
		.WORD	_nsub_full_pal_load
		.WORD	byte_15E18
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$17
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$17
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$16
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$16
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$0A
		.WORD	_nsub_apu_mus_load
		.BYTE	$0A
		.BYTE	$09		; NBG_HNDL_SET	  _j_nbgsub_1437C_2
		.WORD	_j_nbgsub_1437C_2
		.BYTE	$07		; NJSR		  _nsub_ingame_collision_watch_start
		.WORD	_nsub_ingame_collision_watch_start
		.BYTE	$07		; NJSR		  _nsub_ingame_player_control_start
		.WORD	_nsub_ingame_player_control_start
		.BYTE	$08,$01		; SRUN		  $01,_scr_14324
		.WORD	_scr_14324
		.BYTE	$16		; STORE16	  _lvl_objects_ptr,_lvl5_objects_list
		.WORD	_lvl_objects_ptr
		.WORD	_lvl5_objects_list
		.BYTE	$07		; NJSR		  _nsub_lvl_room_objects_init
		.WORD	_nsub_lvl_room_objects_init
		.BYTE	$05		; SRET
byte_15E18:
		.BYTE	$0F,$30,$10,$1B,$0F,$10,$1B,$06,$0F,$26,$17,$07,$0F,$09,$10,$0B
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$17,$0F,$0F,$36,$25,$0F

; =============== S U B	R O U T	I N E =======================================
_j_nbgsub_1437C_2:
		JMP		_lvl_room_objects_handler

; =============== S U B	R O U T	I N E =======================================
_nsub_15E3B:
		LDX		#$02
		JSR		_script_load_param_ex
		.WORD	_scr_602DB
		LDX		#$04
		JSR		_script_load_param_ex
		.WORD	_scr_60FDB
		RTS

; =============== S U B	R O U T	I N E =======================================
_nsub_15E4A:
		LDA		_scr_trds_priority_mode
		BNE		loc_15E56
		LDA		_pad0_pressed
		AND		#$10
		BEQ		loc_15E56
		SEC
		RTS
loc_15E56:
		CLC
		RTS

; =============== S U B	R O U T	I N E =======================================
_unref_0:
		LDA		_pad0_pressed	; *--
		AND		#$20       ; *--
		BEQ		loc_15E65	; *--
		LDA		#$80       ; *--
		STA		_game_flags	; *--
		SEC				; *--
		RTS				; *--
loc_15E65:
		; *--
		CLC
		RTS				; *--

; =============== S U B	R O U T	I N E =======================================
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
		LDA		#$01
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
		JSR		sub_62141
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

; =============== S U B	R O U T	I N E =======================================
_pause_menu_anim:
		LDA		#$00
		STA		_tmpD8
		STA		_tmpD9
		LDA		_tmp7B7
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
		JMP		sub_6371B
off_15F18:
		.WORD	_nsub_16444
		.WORD	_nsub_164DE
		.WORD	_nsub_1655A	; *--
		.WORD	_nsub_16602	; *--
		.WORD	_nsub_1663E	; *--
		.WORD	_nsub_1667D
		.WORD	_nsub_166C4	; *--
		.WORD	_nsub_1670B
		.WORD	_nsub_16736	; *--
		.WORD	sub_1679C		; *--
		.WORD	sub_167A0		; *--
		.WORD	sub_167A4		; *--
		.WORD	sub_167A8		; *--
		.WORD	_nsub_1681A	; *--
		.WORD	_nsub_16894	; *--
		.WORD	_nsub_16913	; *--
		.WORD	_nsub_16855	; *--
_res_pause_pal:
		.WORD	$3F00
		.BYTE	$18,$01
		.BYTE	$0F,$31,$11,$01,$0F,$00,$10,$20,$0F,$00,$10,$20,$0F,$00,$10,$20
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15
_scr_15F56:
		.BYTE	$07		; NJSR		  _nsub_62CF3
		.WORD	_nsub_62CF3
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$FF
		.WORD	_nsub_apu_mus_load
		.BYTE	$FF
		.BYTE	$13		; STORE8	  _apu_var402,$FF
		.WORD	_apu_var402
		.BYTE	$FF
		.BYTE	$06,$10		; SDELAY	  $10
		.BYTE	$13		; STORE8	  _scr_trds_priority_mode,$01
		.WORD	_scr_trds_priority_mode
		.BYTE	$01
		.BYTE	$06,$4B		; SDELAY	  $4B
		.BYTE	$07		; NJSR		  _nsub_62B40
		.WORD	_nsub_62B40
		.BYTE	$06,$2D		; SDELAY	  $2D
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$03
		.WORD	_nsub_apu_mus_load
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$05
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_62BB1,$80,$7C
		.WORD	_nsub_62BB1
		.BYTE	$80,$7C
		.BYTE	$20,$17		; SPR_IDX_SET	  0,$17
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_15FD6
		.WORD	_nbgsub_15FD6
		.BYTE	$06,$78		; SDELAY	  $78
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_dec,$FE
		.WORD	_nsub_counters_dec
		.BYTE	$FE
		.BYTE	$06,$06		; SDELAY	  $06
		.BYTE	$02		; SLOOP_END
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$01
		.WORD	_nsub_far_prg0_tlm_lib_unpack
		.BYTE	$01
		.BYTE	$07		; NJSR		  _nsub_pause_info_display
		.WORD	_nsub_pause_info_display
		.BYTE	$07		; NJSR		  _nsub_bg_pal_load,byte_15FC3
		.WORD	_nsub_bg_pal_load
		.WORD	byte_15FC3
		.BYTE	$07		; NJSR		  _nsub_62775,$00
		.WORD	_nsub_62775
		.BYTE	$00
		.BYTE	$28,$80,$00	; POS_X_SET	  0,$80,$00
		.BYTE	$30,$7C,$00	; POS_Y_SET	  0,$7C,$00
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_15FD3
		.WORD	_nbgsub_15FD3
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr0_set,$04
		.WORD	_nsub_mmc1_chr0_set
		.BYTE	$04
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$05
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$05
		.BYTE	$01,$04		; SLOOP_BEGIN	  $04
		.BYTE	$07		; NJSR		  _nsub_counters_inc,$FE
		.WORD	_nsub_counters_inc
		.BYTE	$FE
		.BYTE	$06,$06		; SDELAY	  $06
		.BYTE	$02		; SLOOP_END
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$13		; STORE8	  _game_flags,$80
		.WORD	_game_flags
		.BYTE	$80
		.BYTE	$00		; STOP
byte_15FC3:
		.BYTE	$0F,$30,$0F,$0F,$0F,$30,$10,$00,$0F,$35,$25,$15,$0F,$30,$3B,$2B

; =============== S U B	R O U T	I N E =======================================
_nbgsub_15FD3:
		JSR		_pause_menu_anim

; =============== S U B	R O U T	I N E =======================================
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
		JSR		sub_62141
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

; =============== S U B	R O U T	I N E =======================================
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
_scr_16111:
		.BYTE	$04		; SJSR		  _ssub_62DC5
		.WORD	_ssub_62DC5
		.BYTE	$07		; NJSR		  _nsub_62B40
		.WORD	_nsub_62B40
		.BYTE	$07		; NJSR		  _nsub_far_prg0_tlm_lib_unpack,$03
		.WORD	_nsub_far_prg0_tlm_lib_unpack
		.BYTE	$03
		.BYTE	$07		; NJSR		  _nsub_mmc1_chr1_set,$05
		.WORD	_nsub_mmc1_chr1_set
		.BYTE	$05
		.BYTE	$07		; NJSR		  _nsub_full_pal_load,byte_16176
		.WORD	_nsub_full_pal_load
		.WORD	byte_16176
		.BYTE	$07		; NJSR		  _nsub_62775,$00
		.WORD	_nsub_62775
		.BYTE	$00
		.BYTE	$07		; NJSR		  _nsub_game_over_draw
		.WORD	_nsub_game_over_draw
		.BYTE	$04		; SJSR		  _ssub_62D93
		.WORD	_ssub_62D93
		.BYTE	$13		; STORE8	  _apu_var402,$FF
		.WORD	_apu_var402
		.BYTE	$FF
		.BYTE	$07		; NJSR		  _nsub_apu_mus_load,$02
		.WORD	_nsub_apu_mus_load
		.BYTE	$02
		.BYTE	$07		; NJSR		  _nsub_mcmp,_continues,$00
		.WORD	_nsub_mcmp
		.WORD	_continues
		.BYTE	$00
		.BYTE	$0B		; SBCS		  _sloc_16162
		.WORD	_sloc_16162
		.BYTE	$28,$58,$00	; POS_X_SET	  0,$58,$00
		.BYTE	$08,$01		; SRUN		  $01,_scr_1616A
		.WORD	_scr_1616A
_sloc_16146:
		.BYTE	$48,$00,$01	; POS_X_DELTA_SET 0,$00,$01
		.BYTE	$20,$15		; SPR_IDX_SET	  0,$15
		.BYTE	$01,$50		; SLOOP_BEGIN	  $50
		.BYTE	$07		; NJSR		  _nsub_161F3
		.WORD	_nsub_161F3
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$48,$00,$FF	; POS_X_DELTA_SET 0,$00,$FF
		.BYTE	$98		; SPR_IDX_INC	  0
		.BYTE	$01,$50		; SLOOP_BEGIN	  $50
		.BYTE	$07		; NJSR		  _nsub_161F3
		.WORD	_nsub_161F3
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$02		; SLOOP_END
		.BYTE	$03		; SJMP		  _sloc_16146
		.WORD	_sloc_16146
_sloc_16162:
		.BYTE	$06,$F0		; SDELAY	  $F0
		.BYTE	$06,$3C		; SDELAY	  $3C
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$00		; STOP
_scr_1616A:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_16213
		.WORD	_nsub_16213
		.BYTE	$0C		; SBCC		  _scr_1616A
		.WORD	_scr_1616A
		.BYTE	$04		; SJSR		  _ssub_62DA3
		.WORD	_ssub_62DA3
		.BYTE	$00		; STOP
byte_16176:
		.BYTE	$0F,$30,$15,$03,$0F,$30,$10,$0F,$0F,$37,$27,$17,$0F,$0F,$0F,$0F
		.BYTE	$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$31,$12,$0F,$0F,$0F,$0F,$0F

; =============== S U B	R O U T	I N E =======================================
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
		JSR		_ppu_res_send_param_repeat_no_ofs_0
		.WORD	word_161EE
		LDA		#$00
		STA		_game_flags
		RTS
word_161EE:
		.WORD	$224B
		.BYTE	$0A,$05
		.BYTE	$20

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
_scrC_room_doors_handler:
		.BYTE	$09	; NBG_HNDL_SET	  _nbgsub_room_doors_data_load
		.WORD	_nbgsub_room_doors_data_load
		.BYTE	$07		; NJSR		  _nsub_room_door_exit_allow_test
		.WORD	_nsub_room_door_exit_allow_test
		.BYTE	$0C		; SBCC		  _sloc_16284
		.WORD	_sloc_16284
		.BYTE	$12,$11		; SJSR_SW	  $11
		.WORD	_sjsr_case_1641B	; CASE	  _sjsr_case_1641B
		.WORD	_sjsr_case_164BE	; CASE	  _sjsr_case_164BE
		.WORD	_sjsr_case_16536	; CASE	  _sjsr_case_16536
		.WORD	_sjsr_case_165E0	; CASE	  _sjsr_case_165E0
		.WORD	_sjsr_case_1661E	; CASE	  _sjsr_case_1661E
		.WORD	_sjsr_case_1665D	; CASE	  _sjsr_case_1665D
		.WORD	_sjsr_case_166A4	; CASE	  _sjsr_case_166A4
		.WORD	_sjsr_case_166EB	; CASE	  _sjsr_case_166EB
		.WORD	_sjsr_case_16716	; CASE	  _sjsr_case_16716
		.WORD	_sjsr_case_1675D	; CASE	  _sjsr_case_1675D
		.WORD	_sjsr_case_167CA	; CASE	  _sjsr_case_167CA
		.WORD	_sjsr_case_167DA	; CASE	  _sjsr_case_167DA
		.WORD	_sjsr_case_167EA	; CASE	  _sjsr_case_167EA
		.WORD	_sjsr_case_167FA	; CASE	  _sjsr_case_167FA
		.WORD	_sjsr_case_16870	; CASE	  _sjsr_case_16870
		.WORD	_sjsr_case_168ED	; CASE	  _sjsr_case_168ED
		.WORD	_sjsr_case_16835	; CASE	  _sjsr_case_16835
_sloc_16284:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_room_door_exit_allow_test
		.WORD	_nsub_room_door_exit_allow_test
		.BYTE	$0C		; SBCC		  _sloc_16284
		.WORD	_sloc_16284
		.BYTE	$12,$11		; SJSR_SW	  $11
		.WORD	_sjsr_case_16421	; CASE	  _sjsr_case_16421
		.WORD	_sjsr_case_164C4	; CASE	  _sjsr_case_164C4
		.WORD	_sjsr_case_1653C	; CASE	  _sjsr_case_1653C
		.WORD	_sjsr_case_165E6	; CASE	  _sjsr_case_165E6
		.WORD	_sjsr_case_16624	; CASE	  _sjsr_case_16624
		.WORD	_sjsr_case_16663	; CASE	  _sjsr_case_16663
		.WORD	_sjsr_case_166AA	; CASE	  _sjsr_case_166AA
		.WORD	_sjsr_case_166F1	; CASE	  _sjsr_case_166F1
		.WORD	_sjsr_case_1671C	; CASE	  _sjsr_case_1671C
		.WORD	_sjsr_case_16766	; CASE	  _sjsr_case_16766
		.WORD	_sjsr_case_167D0	; CASE	  _sjsr_case_167D0
		.WORD	_sjsr_case_167E0	; CASE	  _sjsr_case_167E0
		.WORD	_sjsr_case_167F0	; CASE	  _sjsr_case_167F0
		.WORD	_sjsr_case_16800	; CASE	  _sjsr_case_16800
		.WORD	_sjsr_case_16876	; CASE	  _sjsr_case_16876
		.WORD	_sjsr_case_168F3	; CASE	  _sjsr_case_168F3
		.WORD	_sjsr_case_1683B	; CASE	  _sjsr_case_1683B
		.BYTE	$03		; SJMP		  _sloc_16284
		.WORD	_sloc_16284

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
		JMP		_script_load

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_nsub_players_to_near_room_door_distance_test:
		JSR		_near_room_door_screen_pos_calc
		LDA		#$02
		JSR		_obj_to_room_door_distance_test
		BCC		locret_163B3
		LDA		#$04
		JSR		_obj_to_room_door_distance_test
locret_163B3:
		RTS

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_near_room_door_screen_pos_calc:
		LDY		_near_room_door_data_pos
		LDA		(_room_doors_data_ptr),Y

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
_room_door_always_open:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_door_always_closed:
		CLC
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_door_enemy_clear_open:
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
_sjsr_case_1641B:
		.BYTE	$07		; NJSR		  _nsub_16444
		.WORD	_nsub_16444
		.BYTE	$03		; SJMP		  _sloc_1642C
		.WORD	_sloc_1642C
_sjsr_case_16421:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16444
		.WORD	_nsub_16444
		.BYTE	$26,$00		; SPR_IDX_SET	  6,$00
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_1642C:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$00		; SPR_IDX_SET	  6,$00
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_1644F
		.WORD	_nsub_1644F
		.BYTE	$05		; SRET
_ssub_1643B:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_players_to_near_room_door_distance_test
		.WORD	_nsub_players_to_near_room_door_distance_test
		.BYTE	$0C		; SBCC		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_16444:
		LDA		#<[byte_1644B]
		LDX		#>[byte_1644B]
		JMP		sub_1645A
byte_1644B:
		.BYTE	$14,$14,$14,$14

; =============== S U B	R O U T	I N E =======================================
_nsub_1644F:
		LDA		#<[byte_16456]
		LDX		#>[byte_16456]
		JMP		sub_1645A
byte_16456:
		.BYTE	$0A,$1A,$0B,$1B

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_164BE:
		.BYTE	$07		; NJSR		  _nsub_164DE
		.WORD	_nsub_164DE
		.BYTE	$03		; SJMP		  _sloc_164CF
		.WORD	_sloc_164CF
_sjsr_case_164C4:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_164DE
		.WORD	_nsub_164DE
		.BYTE	$26,$01		; SPR_IDX_SET	  6,$01
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_164CF:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$01		; SPR_IDX_SET	  6,$01
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_164E7
		.WORD	_nsub_164E7
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_164DE:
		LDA		#<[byte_164E5]
		LDX		#>[byte_164E5]
		JMP		sub_164F0
byte_164E5:
		.BYTE	$00,$00

; =============== S U B	R O U T	I N E =======================================
_nsub_164E7:
		LDA		#<[byte_164EE]
		LDX		#>[byte_164EE]
		JMP		sub_164F0
byte_164EE:
		.BYTE	$29,$29

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_16536:
		.BYTE	$07		; NJSR		  _nsub_1655A
		.WORD	_nsub_1655A
		.BYTE	$03		; SJMP		  _sloc_16549
		.WORD	_sloc_16549
_sjsr_case_1653C:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_1655A
		.WORD	_nsub_1655A
		.BYTE	$22,$02		; SPR_IDX_SET	  2,$02
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_16549:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$22,$04		; SPR_IDX_SET	  2,$04
		.BYTE	$A2		; SPR_IDX_DEC	  2
		.BYTE	$A2		; SPR_IDX_DEC	  2
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_16583
		.WORD	_nsub_16583
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
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

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_165E0:
		.BYTE	$07		; NJSR		  _nsub_16602
		.WORD	_nsub_16602
		.BYTE	$03		; SJMP		  _sloc_165F2
		.WORD	_sloc_165F2
_sjsr_case_165E6:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16602
		.WORD	_nsub_16602
		.BYTE	$23,$05		; SPR_IDX_SET	  3,$05
		.BYTE	$9B		; SPR_IDX_INC	  3
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_165F2:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$23,$06		; SPR_IDX_SET	  3,$06
		.BYTE	$A3		; SPR_IDX_DEC	  3
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_1660B
		.WORD	_nsub_1660B
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_16602:
		LDA		#<[byte_16609]
		LDX		#>[byte_16609]
		JMP		sub_164F0
byte_16609:
		.BYTE	$2C,$14

; =============== S U B	R O U T	I N E =======================================
_nsub_1660B:
		LDA		#<[byte_16612] ; *--
		LDX		#>[byte_16612] ; *--
		JMP		sub_164F0	; *--
byte_16612:
		.BYTE	$D3,$D2		; *--
_spr_raw_lib01_05:
		.BYTE	$01
		.BYTE	$00,$D9,$03,$FF
_spr_raw_lib01_06:
		.BYTE	$01
		.BYTE	$00,$E9,$03,$FF
_sjsr_case_1661E:
		.BYTE	$07		; NJSR		  _nsub_1663E
		.WORD	_nsub_1663E
		.BYTE	$03		; SJMP		  _sloc_1662F
		.WORD	_sloc_1662F
_sjsr_case_16624:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_1663E
		.WORD	_nsub_1663E
		.BYTE	$26,$07		; SPR_IDX_SET	  6,$07
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_1662F:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$07		; SPR_IDX_SET	  6,$07
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_16649
		.WORD	_nsub_16649
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_1663E:
		LDA		#<[byte_16645]
		LDX		#>[byte_16645]
		JMP		sub_1645A
byte_16645:
		.BYTE	$87,$97,$88,$98

; =============== S U B	R O U T	I N E =======================================
_nsub_16649:
		LDA		#<[byte_16650] ; *--
		LDX		#>[byte_16650] ; *--
		JMP		sub_1645A	; *--
byte_16650:
		.BYTE	$D4,$D6,$D5,$D7	; *--
_spr_raw_lib01_07:
		.BYTE	$02
		.BYTE	$F0,$AF,$40,$F8
		.BYTE	$00,$8B,$40,$F8
_sjsr_case_1665D:
		.BYTE	$07		; NJSR		  _nsub_1667D
		.WORD	_nsub_1667D
		.BYTE	$03		; SJMP		  _sloc_1666E
		.WORD	_sloc_1666E
_sjsr_case_16663:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_1667D
		.WORD	_nsub_1667D
		.BYTE	$26,$08		; SPR_IDX_SET	  6,$08
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_1666E:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$08		; SPR_IDX_SET	  6,$08
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_16688
		.WORD	_nsub_16688
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_1667D:
		LDA		#<[byte_16684]
		LDX		#>[byte_16684]
		JMP		sub_1645A
byte_16684:
		.BYTE	$01,$01,$01,$01

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_166A4:
		.BYTE	$07		; NJSR		  _nsub_166C4
		.WORD	_nsub_166C4
		.BYTE	$03		; SJMP		  _sloc_166B5
		.WORD	_sloc_166B5
_sjsr_case_166AA:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_166C4
		.WORD	_nsub_166C4
		.BYTE	$26,$09		; SPR_IDX_SET	  6,$09
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_166B5:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$0A
		.WORD	_nsub_apu_snd_load
		.BYTE	$0A
		.BYTE	$26,$09		; SPR_IDX_SET	  6,$09
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_166CF
		.WORD	_nsub_166CF
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_166C4:
		LDA		#<[byte_166CB]
		LDX		#>[byte_166CB]
		JMP		sub_1645A
byte_166CB:
		.BYTE	$00,$00,$00,$00

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_166EB:
		.BYTE	$07		; NJSR		  _nsub_1670B
		.WORD	_nsub_1670B
		.BYTE	$03		; SJMP		  _sloc_166FC
		.WORD	_sloc_166FC
_sjsr_case_166F1:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_1670B
		.WORD	_nsub_1670B
		.BYTE	$26,$09		; SPR_IDX_SET	  6,$09
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_166FC:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$09		; SPR_IDX_SET	  6,$09
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_166CF
		.WORD	_nsub_166CF
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_1670B:
		LDA		#<[byte_16712]
		LDX		#>[byte_16712]
		JMP		sub_1645A
byte_16712:
		.BYTE	$26,$26,$26,$26
_sjsr_case_16716:
		.BYTE	$07		; NJSR		  _nsub_16736
		.WORD	_nsub_16736
		.BYTE	$03		; SJMP		  _sloc_16727
		.WORD	_sloc_16727
_sjsr_case_1671C:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16736
		.WORD	_nsub_16736
		.BYTE	$26,$0A		; SPR_IDX_SET	  6,$0A
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_16727:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$0A		; SPR_IDX_SET	  6,$0A
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_16741
		.WORD	_nsub_16741
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_16736:
		LDA		#<[byte_1673D]
		LDX		#>[byte_1673D]
		JMP		sub_1645A
byte_1673D:
		.BYTE	$20,$20,$96,$97

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_1675D:
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
_sloc_16760:
		.BYTE	$07		; NJSR		  _nsub_16787
		.WORD	_nsub_16787
		.BYTE	$03		; SJMP		  _sloc_16774
		.WORD	_sloc_16774
_sjsr_case_16766:
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
_sloc_16769:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16787
		.WORD	_nsub_16787
		.BYTE	$26,$0B		; SPR_IDX_SET	  6,$0B
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_16774:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$0B		; SPR_IDX_SET	  6,$0B
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_167AC
		.WORD	_nsub_167AC
		.BYTE	$05		; SRET
byte_16783:
		.BYTE	$17,$98
byte_16785:
		.BYTE	$95,$91

; =============== S U B	R O U T	I N E =======================================
_nsub_16787:
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_args0,X

; =============== S U B	R O U T	I N E =======================================
sub_1678B:
		LDA		off_16794,Y
		LDX		off_16798,Y
		JMP		sub_164F0
off_16794:
		.BYTE	<[byte_16783]
		.BYTE	<[byte_167D6]
		.BYTE	<[byte_167E6]
		.BYTE	<[byte_167F6]	; *--
off_16798:
		.BYTE	>[byte_16783]
		.BYTE	>[byte_167D6]
		.BYTE	>[byte_167E6]
		.BYTE	>[byte_167F6]	; *--

; =============== S U B	R O U T	I N E =======================================
sub_1679C:
		LDY		#$00		; *--
		BEQ		sub_1678B	; *--

; =============== S U B	R O U T	I N E =======================================
sub_167A0:
		LDY		#$01		; *--
		BNE		sub_1678B	; *--

; =============== S U B	R O U T	I N E =======================================
sub_167A4:
		LDY		#$02		; *--
		BNE		sub_1678B	; *--

; =============== S U B	R O U T	I N E =======================================
sub_167A8:
		LDY		#$03		; *--
		BNE		sub_1678B	; *--

; =============== S U B	R O U T	I N E =======================================
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
		.BYTE	<[byte_167F8]	; *--
off_167BD:
		.BYTE	>[byte_16785]
		.BYTE	>[byte_167D8]
		.BYTE	>[byte_167E8]
		.BYTE	>[byte_167F8]	; *--
_spr_raw_lib01_0B:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$00
		.BYTE	$00,$DF,$00,$00
_sjsr_case_167CA:
		.BYTE	$0F,$00,$01	; SARG_SET	  $00,$01
		.BYTE	$03		; SJMP		  _sloc_16760
		.WORD	_sloc_16760
_sjsr_case_167D0:
		.BYTE	$0F,$00,$01	; SARG_SET	  $00,$01
		.BYTE	$03		; SJMP		  _sloc_16769
		.WORD	_sloc_16769
byte_167D6:
		.BYTE	$4E,$98
byte_167D8:
		.BYTE	$99,$91
_sjsr_case_167DA:
		.BYTE	$0F,$00,$02	; SARG_SET	  $00,$02
		.BYTE	$03		; SJMP		  _sloc_16760
		.WORD	_sloc_16760
_sjsr_case_167E0:
		.BYTE	$0F,$00,$02	; SARG_SET	  $00,$02
		.BYTE	$03		; SJMP		  _sloc_16769
		.WORD	_sloc_16769
byte_167E6:
		.BYTE	$51,$9B
byte_167E8:
		.BYTE	$8F,$9A
_sjsr_case_167EA:
		.BYTE	$0F,$00,$03	; SARG_SET	  $00,$03
		.BYTE	$03		; SJMP		  _sloc_16760
		.WORD	_sloc_16760
_sjsr_case_167F0:
		.BYTE	$0F,$00,$03	; SARG_SET	  $00,$03
		.BYTE	$03		; SJMP		  _sloc_16769
		.WORD	_sloc_16769
byte_167F6:
		.BYTE	$22,$98		; *--
byte_167F8:
		.BYTE	$90,$91		; *--
_sjsr_case_167FA:
		.BYTE	$07		; NJSR		  _nsub_1681A
		.WORD	_nsub_1681A
		.BYTE	$03		; SJMP		  _sloc_1680B
		.WORD	_sloc_1680B
_sjsr_case_16800:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_1681A
		.WORD	_nsub_1681A
		.BYTE	$26,$0C		; SPR_IDX_SET	  6,$0C
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_1680B:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$0C		; SPR_IDX_SET	  6,$0C
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_16823
		.WORD	_nsub_16823
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_1681A:
		LDA		#<[byte_16821]
		LDX		#>[byte_16821]
		JMP		sub_164F0
byte_16821:
		.BYTE	$20,$96

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_16835:
		.BYTE	$07		; NJSR		  _nsub_16855
		.WORD	_nsub_16855
		.BYTE	$03		; SJMP		  _sloc_16846
		.WORD	_sloc_16846
_sjsr_case_1683B:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16855
		.WORD	_nsub_16855
		.BYTE	$26,$0D		; SPR_IDX_SET	  6,$0D
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_16846:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$26,$0D		; SPR_IDX_SET	  6,$0D
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_1685E
		.WORD	_nsub_1685E
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_16855:
		LDA		#<[byte_1685C]
		LDX		#>[byte_1685C]
		JMP		sub_164F0
byte_1685C:
		.BYTE	$22,$9E

; =============== S U B	R O U T	I N E =======================================
_nsub_1685E:
		LDA		#<[byte_16865] ; *--
		LDX		#>[byte_16865] ; *--
		JMP		sub_164F0	; *--
byte_16865:
		.BYTE	$9C,$9D		; *--
_spr_raw_lib01_0D:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$08
		.BYTE	$00,$DF,$00,$08
_sjsr_case_16870:
		.BYTE	$07		; NJSR		  _nsub_16894
		.WORD	_nsub_16894
		.BYTE	$03		; SJMP		  _sloc_16883
		.WORD	_sloc_16883
_sjsr_case_16876:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16894
		.WORD	_nsub_16894
		.BYTE	$21,$0E		; SPR_IDX_SET	  1,$0E
		.BYTE	$99		; SPR_IDX_INC	  1
		.BYTE	$99		; SPR_IDX_INC	  1
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_16883:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$21,$10		; SPR_IDX_SET	  1,$10
		.BYTE	$A1		; SPR_IDX_DEC	  1
		.BYTE	$A1		; SPR_IDX_DEC	  1
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_1689F
		.WORD	_nsub_1689F
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_16894:
		LDA		#<[byte_1689B]
		LDX		#>[byte_1689B]
		JMP		sub_1645A
byte_1689B:
		.BYTE	$14,$14,$55,$55

; =============== S U B	R O U T	I N E =======================================
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
_sjsr_case_168ED:
		.BYTE	$07		; NJSR		  _nsub_16913
		.WORD	_nsub_16913
		.BYTE	$03		; SJMP		  _sloc_16901
		.WORD	_sloc_16901
_sjsr_case_168F3:
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$07
		.WORD	_nsub_apu_snd_load
		.BYTE	$07
		.BYTE	$07		; NJSR		  _nsub_16913
		.WORD	_nsub_16913
		.BYTE	$22,$11		; SPR_IDX_SET	  2,$11
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
_sloc_16901:
		.BYTE	$04		; SJSR		  _ssub_1643B
		.WORD	_ssub_1643B
		.BYTE	$07		; NJSR		  _nsub_apu_snd_load,$06
		.WORD	_nsub_apu_snd_load
		.BYTE	$06
		.BYTE	$22,$14		; SPR_IDX_SET	  2,$14
		.BYTE	$A2		; SPR_IDX_DEC	  2
		.BYTE	$A2		; SPR_IDX_DEC	  2
		.BYTE	$A2		; SPR_IDX_DEC	  2
		.BYTE	$20,$FF		; SPR_IDX_SET	  0,$FF
		.BYTE	$07		; NJSR		  _nsub_1691C
		.WORD	_nsub_1691C
		.BYTE	$05		; SRET

; =============== S U B	R O U T	I N E =======================================
_nsub_16913:
		LDA		#<[byte_1691A]
		LDX		#>[byte_1691A]
		JMP		sub_164F0
byte_1691A:
		.BYTE	$00,$00

; =============== S U B	R O U T	I N E =======================================
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
_scrD_money_bag:
		.BYTE	$07		; NJSR		  _nsub_obj_sarg_add_imm_test,$00,$FF
		.WORD	_nsub_obj_sarg_add_imm_test
		.BYTE	$00,$FF
		.BYTE	$11,$01		; SJMP_SW	  $01
		.WORD	_sjmp_case_16966	; CASE	  _sjmp_case_16966
_spr_unref:
		.BYTE	$02		; *--
		.BYTE	$F8,$BB,$00,$00	; *--
		.BYTE	$F8,$AB,$00,$F8	; *--
_spr_unref_0:
		.BYTE	$01		; *--
		.BYTE	$F8,$BF,$00,$FC	; *--
_spr_unref_1:
		.BYTE	$01		; *--
		.BYTE	$F8,$AF,$00,$FC	; *--
_spr_unref_2:
		.BYTE	$01		; *--
		.BYTE	$F8,$BF,$40,$FC	; *--
_sjmp_case_16966:
		.BYTE	$0F,$00,$00	; SARG_SET	  $00,$00
_sloc_16969:
		.BYTE	$06,$01		; SDELAY	  $01
		.BYTE	$07		; NJSR		  _nsub_prize_sequence_completed_test
		.WORD	_nsub_prize_sequence_completed_test
		.BYTE	$0C		; SBCC		  _sloc_16969
		.WORD	_sloc_16969
		.BYTE	$0F,$02,$1E	; SARG_SET	  $02,$1E
		.BYTE	$09		; NBG_HNDL_SET	  _nbgsub_money_bag_collision_test
		.WORD	_nbgsub_money_bag_collision_test
_sloc_16977:
		.BYTE	$22,$19		; SPR_IDX_SET	  2,$19
		.BYTE	$9A		; SPR_IDX_INC	  2
		.BYTE	$03		; SJMP		  _sloc_16977
		.WORD	_sloc_16977

; =============== S U B	R O U T	I N E =======================================
_nbgsub_money_bag_collision_test:
		LDX		#$0D
		LDY		#$0E
		JMP		_money_prize_collision_test

; =============== S U B	R O U T	I N E =======================================
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
		.BYTE	$13,$30,$02,$88,$03
		.BYTE	$13,$70,$03,$98,$03
		.BYTE	$13,$A0,$03,$78,$03
		.BYTE	$17,$D0,$03,$40,$03
		.BYTE	$0D,$70,$03,$A0,$03,$01
		.BYTE	$12,$00,$00,$00,$00,$AD,$02
		.BYTE	$FF,$01,$02
		.BYTE	$1C,$90,$04,$E0,$02
		.BYTE	$12,$00,$00,$00,$00,$AF,$03
		.BYTE	$FF,$01,$03
		.BYTE	$FF,$02
		.BYTE	$17,$A8,$03,$C0,$02
		.BYTE	$18,$C8,$03,$70,$02
		.BYTE	$18,$50,$03,$40,$02
		.BYTE	$18,$10,$03,$60,$02
		.BYTE	$13,$70,$02,$A0,$02
		.BYTE	$14,$D0,$02,$48,$02
		.BYTE	$0D,$80,$02,$50,$02,$01
		.BYTE	$12,$00,$00,$00,$00,$AF,$04
		.BYTE	$FF,$01,$04
		.BYTE	$19,$78,$01,$50,$02
		.BYTE	$13,$C8,$01,$68,$02
		.BYTE	$12,$00,$00,$00,$00,$AD,$03
		.BYTE	$FF,$01,$03
		.BYTE	$13,$60,$02,$70,$02
		.BYTE	$14,$A0,$02,$70,$02
		.BYTE	$12,$00,$00,$00,$00,$AE,$00
		.BYTE	$FF,$01,$00
		.BYTE	$13,$98,$02,$A8,$03
		.BYTE	$14,$78,$02,$98,$03
		.BYTE	$17,$80,$02,$48,$03
		.BYTE	$12,$00,$00,$00,$00,$AF,$01
		.BYTE	$FF,$01,$01
		.BYTE	$FF,$02
		.BYTE	$15,$08,$01,$80,$03
		.BYTE	$16,$B8,$00,$A0,$03
		.BYTE	$16,$80,$00,$50,$03
		.BYTE	$16,$60,$00,$B0,$03
		.BYTE	$14,$48,$01,$40,$03
		.BYTE	$14,$40,$01,$B8,$03
		.BYTE	$13,$B8,$01,$40,$03
		.BYTE	$14,$A0,$01,$B8,$03
		.BYTE	$0D,$B0,$00,$60,$03,$01
		.BYTE	$12,$00,$00,$00,$00,$AD,$00
		.BYTE	$FF,$01,$00
		.BYTE	$18,$78,$02,$40,$03
		.BYTE	$18,$B8,$02,$88,$03
		.BYTE	$18,$88,$02,$98,$03
		.BYTE	$12,$00,$00,$00,$00,$AC,$03
		.BYTE	$FF,$01,$03
		.BYTE	$17,$48,$02,$C8,$02
		.BYTE	$14,$A8,$02,$88,$02
		.BYTE	$17,$C8,$02,$C8,$02
		.BYTE	$14,$58,$02,$68,$02
		.BYTE	$12,$00,$00,$00,$00,$AC,$05
		.BYTE	$FF,$01,$06
		.BYTE	$FF,$02
		.BYTE	$FF,$01,$05
		.BYTE	$1B,$78,$02,$78,$01,$00
		.BYTE	$1B,$B8,$02,$58,$01,$01
		.BYTE	$1B,$48,$02,$58,$01,$02
		.BYTE	$1B,$68,$02,$38,$01,$03
		.BYTE	$1A,$80,$02,$40,$00,$00
		.BYTE	$FF,$00
_lvl_data0_ptr0:
		.BYTE	$FF,$FC,$FB,$F3,$03,$DB,$03,$F7,$03,$F8,$0F,$FF,$7E,$FF,$7E,$7F
		.BYTE	$01,$00,$01,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl_data0_ptr1:
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
