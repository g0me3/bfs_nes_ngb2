
		ORG $C000

		BANK_START $7

;		INCBIN "..\copyrights.txt"

; REGION: for some reason, EU version has this byte added here
;		.BYTE	$FF

; =============== S U B R O U T I N E =======================================
RESET:
		INC		RESET
		LDA		#$1E
		JSR		_mmc1_ctrl
		SEI
		LDA		#$00
		STA		_PPU_CTRL
		STA		_PPU_MASK
loc_60011:
		LDA		_PPU_STATUS
		BPL		loc_60011
loc_60016:
		LDA		_PPU_STATUS
		BMI		loc_60016
loc_6001B:
		LDA		_PPU_STATUS
		BPL		loc_6001B
loc_60020:
		LDA		_PPU_STATUS
		BMI		loc_60020
		CLD
		LDX		#$FA
		TXS
		LDA		#$30
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
; REGION, the US proto version enables the left tile colums for both BG and SPRITES
;		LDA		#$1E
		LDA		#$18
; -
		STA		_ppu_mask_req
		STA		_PPU_MASK
		LDA		#$00
		STA		_chr_bank0
		STA		_chr_bank1
		STA		_apu_play_delayed_req
		STA		_mmc1_busy
		LDA		#$06
		JSR		_mmc1_prg
		JSR		_apu_reset
		LDA		#$00
		STA		_prg_cur_bank
		JSR		_mmc1_prg
		JSR		_ppu_queue_reset
		JSR		_ppu_nmi_on
		LDA		#$77
		STA		_random_seed
		STA		_random_seed+1
		LDA		#$01
		STA		_license_screen_display_flag
		STA		_difficulty
		LDA		#$80
		STA		_control_jump_button_code
		LDA		#$40
		STA		_control_fire_button_code
		LDA		_ram_signature
		CMP		#$48
		BNE		loc_6007C
		LDA		_ram_signature+1
		CMP		#$53
		BEQ		_MAIN_ENTRY
loc_6007C:
		LDA		#$48
		STA		_ram_signature
		LDA		#$53
		STA		_ram_signature+1
		LDA		#$64
		STA		_hi_scores
		LDA		#$00
		STA		_hi_scores+1
_MAIN_ENTRY:
		JSR		_ppu_vblank_off
		LDA		#$FF
		LDX		#$00
		JSR		sub_61FFC
		LDA		#$FF
		LDX		#$01
		JSR		sub_61FFC
		JSR		_scr_trds_list_reset
		LDA		#$00
		JSR		_event_thread_start
		LDA		#$00
		STA		_scr_trds_pause_mode
		STA		_scr_trds_out_of_screen_test
loc_600AF:
		JSR		_wait_for_nmi
		JSR		_ppu_spr_shuffle_pos
		JSR		_threads_manager
		JSR		_ppu_spr_clear
		LDA		_scr_trds_idx
		BPL		loc_600AF
_GAME_ENTRY:
		LDX		_difficulty
		LDA		_scores_to_next_live_max_list_lo,X
		STA		_scores_to_next_live_max
		LDA		_scores_to_next_live_max_list_hi,X
		STA		_scores_to_next_live_max+1
		LDA		_scores_to_next_live_step_list_lo,X
		STA		_scores_to_next_live_step
		LDA		_scores_to_next_live_step_list_hi,X
		STA		_scores_to_next_live_step+1
		LDA		#$04
		STA		_continues
#if DEBUG==1
		LDA		#$00
		STA		_level
		LDA		#$04
		STA		_lvl_last_checkpoint_idx
#else
		LDA		#$00
		STA		_level
		LDA		#$01
		STA		_lvl_last_checkpoint_idx
#endif
_MAIN_GAME_LOOP:
		LDA		#$00
		STA		_mmc1_busy
		STA		_apu_play_delayed_req
		STA		_scores
		STA		_scores+1
		STA		_unused_var
		LDA		_scores_to_next_live_max
		STA		_scores_to_next_live
		LDA		_scores_to_next_live_max+1
		STA		_scores_to_next_live+1
		LDA		#$01
		STA		_scr_trds_out_of_screen_test
		LDA		#$04
		SEC
		SBC		_difficulty
		STA		_lives
loc_60112:
		LDA		#$00
		STA		_lvl_cur_checkpoint_idx
		JSR		_scr_trds_list_reset
		LDX		_level
		LDA		_lvl_scripts_list,X
		JSR		_event_thread_start
loc_60123:
		JSR		_wait_for_nmi
		LDA		#$00
		STA		_cur_room_doors_cnt
		JSR		_ppu_spr_shuffle_pos
		JSR		_threads_manager
		JSR		_ppu_spr_clear
		JSR		_obj_exit_arrow_activate_test
		JSR		sub_60166
		LDA		_scr_trds_idx
		BPL		loc_60123
		LDA		_game_flags
		BPL		loc_6015A
		LDA		#$01
		STA		_lvl_last_checkpoint_idx
		INC		_level
		LDA		_level
		CMP		#$07
		BCC		loc_60112
		LDA		#$00
		STA		_level
		BEQ		loc_60112
loc_6015A:
		BNE		_MAIN_GAME_LOOP
		JMP		_MAIN_ENTRY

_lvl_scripts_list:
		.BYTE	$01,$02,$03,$04,$05,$06,$07

; =============== S U B R O U T I N E =======================================
sub_60166:
		LDX		#$06
loc_60168:
		LDA		_scr_trds_idx,X
		BMI		loc_60193
		LDA		_scr_trds_args0,X
		BPL		loc_60193
		LDA		_scr_trds_x_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_x
		LDA		_scr_trds_x_pos_hi,X
		SBC		_ppu_scroll_pos_x+1
		BNE		loc_6018E
		LDA		_scr_trds_y_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_y
		BCS		loc_60187
		SBC		#$0F
		CLC
loc_60187:
		LDA		_scr_trds_y_pos_hi,X
		SBC		_ppu_scroll_pos_y+1
		BEQ		loc_60193
loc_6018E:
		LDA		#$FF
		STA		_scr_trds_idx,X
loc_60193:
		INX
		CPX		#$0E
		BCC		loc_60168
		RTS
_scores_to_next_live_max_list_lo:
		.BYTE	$32,$64,$96,$C8
_scores_to_next_live_max_list_hi:
		.BYTE	$00,$00,$00,$00
_scores_to_next_live_step_list_lo:
		.BYTE	$C8,$2C,$90,$F4
_scores_to_next_live_step_list_hi:
		.BYTE	$00,$01,$01,$01

; =============== S U B R O U T I N E =======================================
_obj_exit_arrow_activate_test:
		LDA		#$FF
		STA		_var0
		STA		_var1
		LDX		#$06
loc_601B1:
		LDA		_scr_trds_idx,X
		BMI		loc_601C4
		CMP		#$13
		BCS		loc_601C2
		CMP		#$12
		BNE		loc_601C4
		STX		_var0
		BEQ		loc_601C4
loc_601C2:
		INC		_var1
loc_601C4:
		INX
		CPX		#$0E
		BCC		loc_601B1
		LDA		_var1
		BPL		locret_601F6
		LDX		_var0
		BMI		locret_601F6
		LDA		_ppu_scroll_pos_x
		CLC
		ADC		#$80
		STA		_scr_trds_x_pos_lo,X
		LDA		_ppu_scroll_pos_x+1
		ADC		#$00
		STA		_scr_trds_x_pos_hi,X
		LDA		_ppu_scroll_pos_y
		CLC
		ADC		#$78
		BCS		loc_601EA
		CMP		#$F0
		BCC		loc_601ED
loc_601EA:
		ADC		#$0F
		SEC
loc_601ED:
		STA		_scr_trds_y_pos_lo,X
		LDA		_ppu_scroll_pos_y+1
		ADC		#$00
		STA		_scr_trds_y_pos_hi,X
locret_601F6:
		RTS

; =============== S C R I P T ===============================================
_scr12_exit_arrow:
		NBG_HNDL_SET	_nbgsub_60205
_sloc_601FA:
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$07
		SPR_IDX_SET		7,$FF
		SJMP			_sloc_601FA

; =============== S U B R O U T I N E =======================================
_nbgsub_60205:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args2,X
		CMP		_cur_lvl_room_idx
		BEQ		loc_6020F
		RTS
loc_6020F:
		JMP		_scr_cur_trd_off

_spr_raw_lib08_AD:
		.BYTE	$07
		.BYTE	$FC,$9F,$80,$06
		.BYTE	$FC,$9D,$00,$0E
		.BYTE	$FC,$8F,$00,$06
		.BYTE	$F4,$9F,$00,$06
		.BYTE	$FC,$8F,$00,$EE
		.BYTE	$FC,$8F,$00,$F6
		.BYTE	$F4,$8F,$80,$FE
_spr_raw_lib08_AC:
		.BYTE	$06
		.BYTE	$F2,$9F,$40,$F4
		.BYTE	$F2,$9F,$00,$04
		.BYTE	$0A,$8F,$00,$FC
		.BYTE	$02,$8F,$00,$FC
		.BYTE	$FA,$8F,$00,$FC
		.BYTE	$EA,$8D,$00,$FC
_spr_raw_lib08_AF:
		.BYTE	$07
		.BYTE	$FC,$9D,$40,$EA
		.BYTE	$FC,$9F,$C0,$F2
		.BYTE	$F4,$9F,$40,$F2
		.BYTE	$FC,$8F,$00,$F2
		.BYTE	$F4,$8F,$80,$0A
		.BYTE	$F4,$8F,$80,$02
		.BYTE	$F4,$8F,$80,$FA
_spr_raw_lib08_AE:
		.BYTE	$06
		.BYTE	$FE,$9F,$80,$04
		.BYTE	$FE,$9F,$C0,$F4
		.BYTE	$E6,$8F,$80,$FC
		.BYTE	$EE,$8F,$80,$FC
		.BYTE	$F6,$8F,$80,$FC
		.BYTE	$06,$8D,$80,$FC

; =============== S C R I P T ===============================================
_scr08_beamer_handler:
		STORE8			_collision_flag,$00
		STORE8			_player_inv_timer,$00
		STORE16			_tmp7B1,$180
		NJSR			_nsub_603A2
_sloc_6028E:
		NJSR			_nsub_mcmp
			NARGW		_scr_trds_idx
			NARGB		$04
		SBCC			_sloc_6029B
		NBG_HNDL_SET	_nbgsub_60307
		SUSPEND
_sloc_6029B:
		NBG_HNDL_SET	_nbgsub_collision_flag_test
		SUSPEND

; =============== S C R I P T ===============================================
_scr_hit_anim:
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$04
		SLOOP_BEGIN		$1E
		NJSR			_nsub_60623
		SDELAY			$03
		SARG_ALU		SARG1,_ADC,$40
		SLOOP_END
		NJSR			_nsub_6273D
			NARGB		$A0,$40
		SDELAY			$02
		SPR_IDX_ADD_IMM 2,$04
		SPR_IDX_ADD_IMM 4,$04
		SPR_IDX_ADD_IMM 2,$FC
		SPR_IDX_ADD_IMM 0,$FC
		SDELAY			$28
		SPR_IDX_SET		0,$FF
		SDELAY			$3C
		NJSR			_nsub_player_hit_action
		SBCC			_sloc_6028E
		SSTOP

; =============== S C R I P T ===============================================
_scr_602CB:
		POS_X_SET		0,$40,$00
		POS_Y_SET		0,$C8,$02
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$40
		NJSR			_nsub_beamer_spr_idx_calc
		SUSPEND

; =============== S C R I P T ===============================================
_scr_beamer_auto_walk:
		POS_Y_DELTA_SET 0,$80,$FF					; setup anim for slow walk up
		SLOOP_BEGIN		$F0							; do walk for 240 cycles
		SARG_ALU		SARG0,_ADC,$01				; set players spr type (walk up)
		NJSR			_nsub_beamer_spr_idx_calc	; calculate animation sprite idx and set
		SDELAY			$02
		SLOOP_END
		POS_MOVE_STOP	0							; stop when done, then return control
		SJMP			_scr08_beamer_handler		; to the main beamer script

; =============== S C R I P T ===============================================
_scr_602EE:
		NJSR			_nsub_beamer_spr_idx_calc
		SDELAY			$78
		SARG_SET		SARG1,$80
		POS_Y_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$F0
		SARG_ALU		SARG0,_ADC,$01
		NJSR			_nsub_beamer_spr_idx_calc
		SDELAY			$01
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_scr_suspend:
		SUSPEND

; =============== S U B R O U T I N E =======================================
_nbgsub_60307:
		JSR		sub_60327

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nbgsub_collision_flag_test:
		LDA		_collision_flag
		LSR
		BCC		loc_60316
		JSR		_cur_thread_reload_param
		.WORD	_scr_hit_anim
		RTS
loc_60316:
		LDA		_player_inv_timer
		BEQ		loc_6031E
		DEC		_player_inv_timer
loc_6031E:
		JSR		sub_603C3
		JSR		sub_605C7
		JMP		_player_beam_obj_insert_test

; =============== S U B R O U T I N E =======================================
sub_60327:
		JSR		sub_6034F
		STA		_tmp7B1
		STY		_tmp7B2
		LDA		_beamer_idxA
		BCC		loc_60337
		ADC		#$4F
loc_60337:
		STA		_beamer_idxB
		RTS

; =============== S U B R O U T I N E =======================================
sub_6033B:
		JSR		sub_6034F
		STA		_tmp7B3
		STY		_tmp7B3+1
		LDA		_catcher_idxA
		BCC		loc_6034B
		ADC		#$4F
loc_6034B:
		STA		_catcher_idxB
		RTS

; =============== S U B R O U T I N E =======================================
sub_6034F:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_y_pos_lo,X
		CLC
		ADC		#$04
		TAY
		LDA		_scr_trds_y_pos_hi,X
		ADC		#$00
		STA		_tmp_var1
		LDA		_scr_trds_x_pos_hi,X
		STA		_tmp_var0
		LDA		_scr_trds_x_pos_lo,X
		TAX
		JSR		_far_lvl_room_ofs_calc
		BEQ		loc_60388
		CMP		#$0D
		BCS		loc_60388
		TAX
		LDA		byte_6038E-1,X
		PHA
		JSR		_nsub_604CD
		STA		_tmp0
		PLA
		SEC
		SBC		_tmp0
		AND		#$03
		TAX
		LDA		byte_6039A,X
		LDY		byte_6039E,X
		SEC
		RTS
loc_60388:
		LDA		#$80
		LDY		#$01
		CLC
		RTS
byte_6038E:
		.BYTE	$02,$02,$02,$00,$00,$00,$01,$01,$01,$03,$03,$03
byte_6039A:
		.BYTE	$80,$00,$C0,$00
byte_6039E:
		.BYTE	$01,$01,$00,$01

; =============== S U B R O U T I N E =======================================
_nsub_603A2:
		LDA		_beamer_idxA
		STA		_beamer_idxB
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_player_hit_action:
		DEC		_lives
		BNE		loc_603B7
		LDX		#$00
		JSR		_thread_reload_param_ex
		.WORD	_scr_16111
		SEC
		RTS
loc_603B7:
		LDA		#$00
		STA		_collision_flag
		LDA		#$78
		STA		_player_inv_timer
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
sub_603C3:
		LDA		_scr_trds_x_pos_lo+2
		ORA		_scr_trds_y_pos_lo+2
		AND		#$07
		BNE		loc_603DC
		LDA		_pad0_held
		AND		#$0F
		BEQ		loc_60406
		JSR		sub_60598
		LDA		_tmp7B0
		JSR		sub_6041D
		BCS		loc_60406
loc_603DC:
		LDA		_tmp7B0
		LDX		_tmp7B1
		LDY		_tmp7B2
		JSR		sub_6050D
		TAY
		BEQ		locret_6041C
		BNE		loc_60410
loc_603ED:
		LDA		_scr_trds_x_pos_lo+2
		ORA		_scr_trds_y_pos_lo+2
		AND		#$07
		BNE		loc_60410
		LDA		_pad0_held
		AND		#$0F
		BEQ		loc_60406
		JSR		sub_60598
		LDA		_tmp7B0
		JSR		sub_6041D
		BCC		loc_60410
loc_60406:
		LDA		#$80
		STA		_scr_trds_x_move_clk+2
		STA		_scr_trds_y_move_clk+2
		BNE		locret_6041C
loc_60410:
		LDA		_tmp7B0
		JSR		sub_60553
		JSR		sub_6045A
		DEY
		BNE		loc_603ED
locret_6041C:
		RTS

; =============== S U B R O U T I N E =======================================
sub_6041D:
		PHA
		TYA
		PHA
		JSR		_cur_obj_screen_pos_calc
		STX		_tmp1
		STY		_tmp2
		PLA
		TAY
		PLA
		STA		_tmp0
		TAX
		BNE		loc_60437
		LDA		_tmp2
		CMP		#$09
		BCS		loc_60455
		BCC		loc_60453
loc_60437:
		DEX
		BNE		loc_60442
		LDA		_tmp1
		CMP		#$F8
		BCC		loc_60455
		BCS		loc_60453
loc_60442:
		DEX
		BNE		loc_6044D
		LDA		_tmp2
		CMP		#$E8
		BCC		loc_60455
		BCS		loc_60453
loc_6044D:
		LDA		_tmp1
		CMP		#$09
		BCS		loc_60455
loc_60453:
		SEC
		RTS
loc_60455:
		LDA		_tmp0
		JMP		sub_604E0

; =============== S U B R O U T I N E =======================================
sub_6045A:
		TYA
		PHA
		JSR		_cur_obj_screen_pos_calc
		CPX		#$80
		BEQ		loc_60490
		BCS		loc_6047D
		LDA		_ppu_scroll_pos_x
		BNE		loc_60470
		LDA		_ppu_scroll_pos_x+1
		CMP		_cur_room_y_pageB
		BEQ		loc_60490
loc_60470:
		LDA		_ppu_scroll_pos_x
		SEC
		SBC		#$01
		STA		_ppu_scroll_pos_x
		BCS		loc_60490
		DEC		_ppu_scroll_pos_x+1
		BPL		loc_60490
loc_6047D:
		LDA		_ppu_scroll_pos_x
		BNE		loc_60488
		LDA		_ppu_scroll_pos_x+1
		CMP		_cur_room_y_pageA
		BEQ		loc_60490
loc_60488:
		INC		_ppu_scroll_pos_x
		BNE		loc_60490
		INC		_ppu_scroll_pos_x+1
		BPL		loc_60490
loc_60490:
		CPY		#$78
		BEQ		loc_604CA
		BCS		loc_604B0
		LDA		_ppu_scroll_pos_y
		BNE		loc_604A1
		LDA		_ppu_scroll_pos_y+1
		CMP		_cur_room_x_pageA
		BEQ		loc_604CA
loc_604A1:
		LDA		_ppu_scroll_pos_y
		SEC
		SBC		#$01
		BCS		loc_604AC
		SBC		#$0F
		DEC		_ppu_scroll_pos_y+1
loc_604AC:
		STA		_ppu_scroll_pos_y
		BCS		loc_604CA
loc_604B0:
		LDA		_ppu_scroll_pos_y
		BNE		loc_604BB
		LDA		_ppu_scroll_pos_y+1
		CMP		_cur_room_x_pageB
		BEQ		loc_604CA
loc_604BB:
		LDA		_ppu_scroll_pos_y
		CLC
		ADC		#$01
		CMP		#$F0
		BCC		loc_604C8
		ADC		#$0F
		INC		_ppu_scroll_pos_y+1
loc_604C8:
		STA		_ppu_scroll_pos_y
loc_604CA:
		PLA
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_604CD:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		ASL
		ROL
		ROL
		RTS

; =============== S U B R O U T I N E =======================================
sub_604D5:
		PHA
		LDY		_scr_cur_trd_idx
		LSR
		ROR
		ROR
		STA		_scr_trds_args1,Y
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
sub_604E0:
		PHA
		TAX
		TYA
		PHA
		LDA		off_604F1,X
		LDY		off_604F5,X
		JSR		_obj_to_room_bound_box_collision_test
		PLA
		TAY
		PLA
		RTS
off_604F1:
		.BYTE	<[byte_604F9]
		.BYTE	<[byte_604FE]
		.BYTE	<[byte_60503]
		.BYTE	<[byte_60508]
off_604F5:
		.BYTE	>[byte_604F9]
		.BYTE	>[byte_604FE]
		.BYTE	>[byte_60503]
		.BYTE	>[byte_60508]
byte_604F9:
		.BYTE	$02
		.BYTE	$F8,$F0
		.BYTE	$00,$F0
byte_604FE:
		.BYTE	$02
		.BYTE	$08,$F8
		.BYTE	$08,$00
byte_60503:
		.BYTE	$02
		.BYTE	$F8,$08
		.BYTE	$00,$08
byte_60508:
		.BYTE	$02
		.BYTE	$F0,$F8
		.BYTE	$F0,$00

; =============== S U B R O U T I N E =======================================
sub_6050D:
		STX		_var0
		STY		_var1
		LDX		_scr_cur_trd_idx
		TAY
		BNE		loc_60523
		LDA		_scr_trds_y_move_clk,X
		SEC
		SBC		_var0
		STA		_scr_trds_y_move_clk,X
		BCS		loc_60550
		BCC		loc_6054E
loc_60523:
		DEY
		BNE		loc_60533
		LDA		_scr_trds_x_move_clk,X
		CLC
		ADC		_var0
		STA		_scr_trds_x_move_clk,X
		BCC		loc_60550
		BCS		loc_6054E
loc_60533:
		DEY
		BNE		loc_60543
		LDA		_scr_trds_y_move_clk,X
		CLC
		ADC		_var0
		STA		_scr_trds_y_move_clk,X
		BCC		loc_60550
		BCS		loc_6054E
loc_60543:
		LDA		_scr_trds_x_move_clk,X
		SEC
		SBC		_var0
		STA		_scr_trds_x_move_clk,X
		BCS		loc_60550
loc_6054E:
		INC		_var1
loc_60550:
		LDA		_var1
		RTS

; =============== S U B R O U T I N E =======================================
sub_60553:
		STA		_tmp0
		LDX		_scr_cur_trd_idx
		DEC		_tmp0
		BPL		loc_6056A
		LDA		_scr_trds_y_pos_lo,X
		SEC
		SBC		#$01
		BCS		loc_60567
		SBC		#$0F
		DEC		_scr_trds_y_pos_hi,X
loc_60567:
		STA		_scr_trds_y_pos_lo,X
		RTS
loc_6056A:
		DEC		_tmp0
		BPL		loc_60576
		INC		_scr_trds_x_pos_lo,X
		BNE		locret_60575
		INC		_scr_trds_x_pos_hi,X
locret_60575:
		RTS
loc_60576:
		DEC		_tmp0
		BPL		loc_6058B
		LDA		_scr_trds_y_pos_lo,X
		CLC
		ADC		#$01
		CMP		#$F0
		BCC		loc_60588
		ADC		#$0F
		INC		_scr_trds_y_pos_hi,X
loc_60588:
		STA		_scr_trds_y_pos_lo,X
		RTS
loc_6058B:
		LDA		_scr_trds_x_pos_lo,X
		SEC
		SBC		#$01
		BCS		loc_60595
		DEC		_scr_trds_x_pos_hi,X
loc_60595:
		STA		_scr_trds_x_pos_lo,X
		RTS

; =============== S U B R O U T I N E =======================================
sub_60598:
		LDA		_pad0_held
		AND		#$08
		BEQ		loc_605A2
		LDA		#$00
		BEQ		loc_605BE
loc_605A2:
		LDA		_pad0_held
		AND		#$01
		BEQ		loc_605AC
		LDA		#$40
		BNE		loc_605BE
loc_605AC:
		LDA		_pad0_held
		AND		#$04
		BEQ		loc_605B6
		LDA		#$80
		BNE		loc_605BE
loc_605B6:
		LDA		_pad0_held
		AND		#$02
		BEQ		locret_605C6
		LDA		#$C0
loc_605BE:
		STA		_scr_trds_args1+2
		ASL
		ROL
		ROL
		STA		_tmp7B0
locret_605C6:
		RTS

; =============== S U B R O U T I N E =======================================
sub_605C7:
		LDA		_scr_trds_idx+3
		BMI		loc_605D5
		LDA		_scr_trds_args0+3
		BMI		loc_605D5
		JSR		sub_61AB9
		STA		_scr_trds_args1+2
loc_605D5:
		LDA		_pad0_held
		AND		#$0F
		BEQ		loc_605DD
		INC		_scr_trds_args0+2
loc_605DD:
		LDA		_player_inv_timer
		LSR
		BCC		_nsub_beamer_spr_idx_calc
		LDA		#$FF
		STA		_scr_trds_spr_idx+2
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_beamer_spr_idx_calc:
		LDA		_beamer_idxB

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_players_spr_idx_calc:
		STA		_tmp0
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		CLC
		ADC		#$20
		AND		#$C0
		LSR
		LSR
		LSR
		LSR
		STA		_var0
		LDA		_scr_trds_args0,X
		AND		#$0C
		LSR
		LSR
		ADC		_var0
		ADC		_tmp0
		STA		_scr_trds_spr_idx,X
		RTS

; =============== S U B R O U T I N E =======================================
_player_beam_obj_insert_test:
		LDA		_pad0_pressed
		AND		_control_jump_button_code
		BEQ		locret_60622
		LDA		_scr_trds_idx+3
		BPL		locret_60622
		LDA		#$03
		STA		_var4
		LDA		#$04
		STA		_var5
		LDA		#$09
		JSR		_thread_lib_load
locret_60622:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_60623:
		LDA		_beamer_idxB
		STA		_tmp0
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args1,X
		CLC
		ADC		#$20
		AND		#$C0
		LSR
		LSR
		LSR
		LSR
		ADC		_tmp0
		STA		_scr_trds_spr_idx,X
		RTS

_spr_raw_lib08_02:
		.BYTE	$04
		.BYTE	$00,$36,$00,$00
		.BYTE	$00,$26,$00,$F8
		.BYTE	$F0,$18,$40,$00
		.BYTE	$F0,$18,$00,$F8
_spr_raw_lib08_01:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$18,$40,$00
		.BYTE	$F1,$18,$00,$F8
_spr_raw_lib08_03:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$18,$40,$00
		.BYTE	$F1,$18,$00,$F8
_spr_raw_lib08_06:
		.BYTE	$04
		.BYTE	$00,$28,$40,$00
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$10,$40,$F8
		.BYTE	$F0,$00,$40,$00
_spr_raw_lib08_05:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$10,$40,$F8
		.BYTE	$F1,$00,$40,$00
_spr_raw_lib08_07:
		.BYTE	$04
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$00,$3A,$00,$00
		.BYTE	$F1,$10,$40,$F8
		.BYTE	$F1,$00,$40,$00
_spr_raw_lib08_0A:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$08,$40,$00
		.BYTE	$F0,$08,$00,$F8
_spr_raw_lib08_09:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$08,$40,$00
		.BYTE	$F1,$08,$00,$F8
_spr_raw_lib08_0B:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$08,$40,$00
		.BYTE	$F1,$08,$00,$F8
_spr_raw_lib08_0E:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$10,$00,$00
		.BYTE	$F0,$00,$00,$F8
_spr_raw_lib08_0D:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$10,$00,$00
		.BYTE	$F1,$00,$00,$F8
_spr_raw_lib08_0F:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$10,$00,$00
		.BYTE	$F1,$00,$00,$F8
_spr_raw_lib08_12:
		.BYTE	$04
		.BYTE	$00,$36,$00,$00
		.BYTE	$00,$26,$00,$F8
		.BYTE	$F0,$1A,$40,$00
		.BYTE	$F0,$1A,$00,$F8
_spr_raw_lib08_11:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$1A,$40,$00
		.BYTE	$F1,$1A,$00,$F8
_spr_raw_lib08_13:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$1A,$40,$00
		.BYTE	$F1,$1A,$00,$F8
_spr_raw_lib08_16:
		.BYTE	$04
		.BYTE	$00,$28,$40,$00
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$12,$40,$F8
		.BYTE	$F0,$02,$40,$00
_spr_raw_lib08_15:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$12,$40,$F8
		.BYTE	$F1,$02,$40,$00
_spr_raw_lib08_17:
		.BYTE	$04
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$00,$3A,$00,$00
		.BYTE	$F1,$12,$40,$F8
		.BYTE	$F1,$02,$40,$00
_spr_raw_lib08_1A:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$0A,$40,$00
		.BYTE	$F0,$0A,$00,$F8
_spr_raw_lib08_19:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$0A,$40,$00
		.BYTE	$F1,$0A,$00,$F8
_spr_raw_lib08_1B:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$0A,$40,$00
		.BYTE	$F1,$0A,$00,$F8
_spr_raw_lib08_1E:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$12,$00,$00
		.BYTE	$F0,$02,$00,$F8
_spr_raw_lib08_1D:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$12,$00,$00
		.BYTE	$F1,$02,$00,$F8
_spr_raw_lib08_1F:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$12,$00,$00
		.BYTE	$F1,$02,$00,$F8
_spr_raw_lib08_22:
		.BYTE	$04
		.BYTE	$00,$36,$00,$00
		.BYTE	$00,$26,$00,$F8
		.BYTE	$F0,$1C,$40,$00
		.BYTE	$F0,$1C,$00,$F8
_spr_raw_lib08_21:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$1C,$40,$00
		.BYTE	$F1,$1C,$00,$F8
_spr_raw_lib08_23:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$1C,$40,$00
		.BYTE	$F1,$1C,$00,$F8
_spr_raw_lib08_26:
		.BYTE	$04
		.BYTE	$00,$28,$40,$00
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$14,$40,$F8
		.BYTE	$F0,$04,$40,$00
_spr_raw_lib08_25:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$14,$40,$F8
		.BYTE	$F1,$04,$40,$00
_spr_raw_lib08_27:
		.BYTE	$04
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$00,$3A,$00,$00
		.BYTE	$F1,$14,$40,$F8
		.BYTE	$F1,$04,$40,$00
_spr_raw_lib08_2A:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$0C,$40,$00
		.BYTE	$F0,$0C,$00,$F8
_spr_raw_lib08_29:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$0C,$40,$00
		.BYTE	$F1,$0C,$00,$F8
_spr_raw_lib08_2B:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$0C,$40,$00
		.BYTE	$F1,$0C,$00,$F8
_spr_raw_lib08_2E:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$14,$00,$00
		.BYTE	$F0,$04,$00,$F8
_spr_raw_lib08_2D:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$14,$00,$00
		.BYTE	$F1,$04,$00,$F8
_spr_raw_lib08_2F:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$14,$00,$00
		.BYTE	$F1,$04,$00,$F8
_spr_raw_lib08_32:
		.BYTE	$04
		.BYTE	$00,$36,$00,$00
		.BYTE	$00,$26,$00,$F8
		.BYTE	$F0,$1E,$40,$00
		.BYTE	$F0,$1E,$00,$F8
_spr_raw_lib08_31:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$1E,$40,$00
		.BYTE	$F1,$1E,$00,$F8
_spr_raw_lib08_33:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$1E,$40,$00
		.BYTE	$F1,$1E,$00,$F8
_spr_raw_lib08_36:
		.BYTE	$04
		.BYTE	$00,$28,$40,$00
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$16,$40,$F8
		.BYTE	$F0,$06,$40,$00
_spr_raw_lib08_35:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$16,$40,$F8
		.BYTE	$F1,$06,$40,$00
_spr_raw_lib08_37:
		.BYTE	$04
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$00,$3A,$00,$00
		.BYTE	$F1,$16,$40,$F8
		.BYTE	$F1,$06,$40,$00
_spr_raw_lib08_3A:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$0E,$40,$00
		.BYTE	$F0,$0E,$00,$F8
_spr_raw_lib08_39:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$0E,$40,$00
		.BYTE	$F1,$0E,$00,$F8
_spr_raw_lib08_3B:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$0E,$40,$00
		.BYTE	$F1,$0E,$00,$F8
_spr_raw_lib08_3E:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$16,$00,$00
		.BYTE	$F0,$06,$00,$F8
_spr_raw_lib08_3D:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$16,$00,$00
		.BYTE	$F1,$06,$00,$F8
_spr_raw_lib08_3F:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$16,$00,$00
		.BYTE	$F1,$06,$00,$F8
_spr_raw_lib08_42:
		.BYTE	$04
		.BYTE	$00,$36,$00,$00
		.BYTE	$00,$26,$00,$F8
		.BYTE	$F0,$32,$40,$00
		.BYTE	$F0,$32,$00,$F8
_spr_raw_lib08_41:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$32,$40,$00
		.BYTE	$F1,$32,$00,$F8
_spr_raw_lib08_43:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$32,$40,$00
		.BYTE	$F1,$32,$00,$F8
_spr_raw_lib08_46:
		.BYTE	$04
		.BYTE	$00,$28,$40,$00
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$30,$40,$F8
		.BYTE	$F0,$20,$40,$00
_spr_raw_lib08_45:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$30,$40,$F8
		.BYTE	$F1,$20,$40,$00
_spr_raw_lib08_47:
		.BYTE	$04
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$00,$3A,$00,$00
		.BYTE	$F1,$30,$40,$F8
		.BYTE	$F1,$20,$40,$00
_spr_raw_lib08_4A:
		.BYTE	$04
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
		.BYTE	$F0,$22,$40,$00
		.BYTE	$F0,$22,$00,$F8
_spr_raw_lib08_49:
		.BYTE	$04
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
		.BYTE	$F1,$22,$40,$00
		.BYTE	$F1,$22,$00,$F8
_spr_raw_lib08_4B:
		.BYTE	$04
		.BYTE	$00,$34,$40,$F8
		.BYTE	$00,$24,$40,$00
		.BYTE	$F1,$22,$40,$00
		.BYTE	$F1,$22,$00,$F8
_spr_raw_lib08_4E:
		.BYTE	$04
		.BYTE	$00,$38,$00,$00
		.BYTE	$00,$28,$00,$F8
		.BYTE	$F0,$30,$00,$00
		.BYTE	$F0,$20,$00,$F8
_spr_raw_lib08_4D:
		.BYTE	$04
		.BYTE	$00,$3A,$00,$00
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$F1,$30,$00,$00
		.BYTE	$F1,$20,$00,$F8
_spr_raw_lib08_4F:
		.BYTE	$04
		.BYTE	$00,$3A,$40,$F8
		.BYTE	$00,$2A,$40,$00
		.BYTE	$F1,$30,$00,$00
		.BYTE	$F1,$20,$00,$F8
_spr_raw_lib08_52:
		.BYTE	$02
		.BYTE	$F4,$18,$40,$00
		.BYTE	$F4,$18,$00,$F8
_spr_raw_lib08_53:
		.BYTE	$02
		.BYTE	$F5,$18,$40,$00
		.BYTE	$F5,$18,$00,$F8
_spr_raw_lib08_56:
		.BYTE	$02
		.BYTE	$F4,$10,$40,$F8
		.BYTE	$F4,$00,$40,$00
_spr_raw_lib08_57:
		.BYTE	$02
		.BYTE	$F5,$10,$40,$F8
		.BYTE	$F5,$00,$40,$00
_spr_raw_lib08_5A:
		.BYTE	$02
		.BYTE	$F4,$08,$40,$00
		.BYTE	$F4,$08,$00,$F8
_spr_raw_lib08_5B:
		.BYTE	$02
		.BYTE	$F5,$08,$40,$00
		.BYTE	$F5,$08,$00,$F8
_spr_raw_lib08_5E:
		.BYTE	$02
		.BYTE	$F4,$10,$00,$00
		.BYTE	$F4,$00,$00,$F8
_spr_raw_lib08_5F:
		.BYTE	$02
		.BYTE	$F5,$10,$00,$00
		.BYTE	$F5,$00,$00,$F8
_spr_raw_lib08_62:
		.BYTE	$02
		.BYTE	$F4,$1A,$40,$00
		.BYTE	$F4,$1A,$00,$F8
_spr_raw_lib08_63:
		.BYTE	$02
		.BYTE	$F5,$1A,$40,$00
		.BYTE	$F5,$1A,$00,$F8
_spr_raw_lib08_66:
		.BYTE	$02
		.BYTE	$F4,$12,$40,$F8
		.BYTE	$F4,$02,$40,$00
_spr_raw_lib08_67:
		.BYTE	$02
		.BYTE	$F5,$12,$40,$F8
		.BYTE	$F5,$02,$40,$00
_spr_raw_lib08_6A:
		.BYTE	$02
		.BYTE	$F4,$0A,$40,$00
		.BYTE	$F4,$0A,$00,$F8
_spr_raw_lib08_6B:
		.BYTE	$02
		.BYTE	$F5,$0A,$40,$00
		.BYTE	$F5,$0A,$00,$F8
_spr_raw_lib08_6E:
		.BYTE	$02
		.BYTE	$F4,$12,$00,$00
		.BYTE	$F4,$02,$00,$F8
_spr_raw_lib08_6F:
		.BYTE	$02
		.BYTE	$F5,$12,$00,$00
		.BYTE	$F5,$02,$00,$F8
_spr_raw_lib08_72:
		.BYTE	$02
		.BYTE	$F4,$1C,$40,$00
		.BYTE	$F4,$1C,$00,$F8
_spr_raw_lib08_73:
		.BYTE	$02
		.BYTE	$F5,$1C,$40,$00
		.BYTE	$F5,$1C,$00,$F8
_spr_raw_lib08_76:
		.BYTE	$02
		.BYTE	$F4,$14,$40,$F8
		.BYTE	$F4,$04,$40,$00
_spr_raw_lib08_77:
		.BYTE	$02
		.BYTE	$F5,$14,$40,$F8
		.BYTE	$F5,$04,$40,$00
_spr_raw_lib08_7A:
		.BYTE	$02
		.BYTE	$F4,$0C,$40,$00
		.BYTE	$F4,$0C,$00,$F8
_spr_raw_lib08_7B:
		.BYTE	$02
		.BYTE	$F5,$0C,$40,$00
		.BYTE	$F5,$0C,$00,$F8
_spr_raw_lib08_7E:
		.BYTE	$02
		.BYTE	$F4,$14,$00,$00
		.BYTE	$F4,$04,$00,$F8
_spr_raw_lib08_7F:
		.BYTE	$02
		.BYTE	$F5,$14,$00,$00
		.BYTE	$F5,$04,$00,$F8
_spr_raw_lib08_82:
		.BYTE	$02
		.BYTE	$F4,$1E,$40,$00
		.BYTE	$F4,$1E,$00,$F8
_spr_raw_lib08_83:
		.BYTE	$02
		.BYTE	$F5,$1E,$40,$00
		.BYTE	$F5,$1E,$00,$F8
_spr_raw_lib08_86:
		.BYTE	$02
		.BYTE	$F4,$16,$40,$F8
		.BYTE	$F4,$06,$40,$00
_spr_raw_lib08_87:
		.BYTE	$02
		.BYTE	$F5,$16,$40,$F8
		.BYTE	$F5,$06,$40,$00
_spr_raw_lib08_8A:
		.BYTE	$02
		.BYTE	$F4,$0E,$40,$00
		.BYTE	$F4,$0E,$00,$F8
_spr_raw_lib08_8B:
		.BYTE	$02
		.BYTE	$F5,$0E,$40,$00
		.BYTE	$F5,$0E,$00,$F8
_spr_raw_lib08_8E:
		.BYTE	$02
		.BYTE	$F4,$16,$00,$00
		.BYTE	$F4,$06,$00,$F8
_spr_raw_lib08_8F:
		.BYTE	$02
		.BYTE	$F5,$16,$00,$00
		.BYTE	$F5,$06,$00,$F8
_spr_raw_lib08_92:
		.BYTE	$02		; *--
		.BYTE	$F4,$32,$40,$00	; *--
		.BYTE	$F4,$32,$00,$F8	; *--
_spr_raw_lib08_93:
		.BYTE	$02		; *--
		.BYTE	$F5,$32,$40,$00	; *--
		.BYTE	$F5,$32,$00,$F8	; *--
_spr_raw_lib08_96:
		.BYTE	$02		; *--
		.BYTE	$F4,$30,$40,$F8	; *--
		.BYTE	$F4,$20,$40,$00	; *--
_spr_raw_lib08_97:
		.BYTE	$02		; *--
		.BYTE	$F5,$30,$40,$F8	; *--
		.BYTE	$F5,$20,$40,$00	; *--
_spr_raw_lib08_9A:
		.BYTE	$02		; *--
		.BYTE	$F4,$22,$40,$00	; *--
		.BYTE	$F4,$22,$00,$F8	; *--
_spr_raw_lib08_9B:
		.BYTE	$02		; *--
		.BYTE	$F5,$22,$40,$00	; *--
		.BYTE	$F5,$22,$00,$F8	; *--
_spr_raw_lib08_9E:
		.BYTE	$02		; *--
		.BYTE	$F4,$30,$00,$00	; *--
		.BYTE	$F4,$20,$00,$F8	; *--
_spr_raw_lib08_9F:
		.BYTE	$02		; *--
		.BYTE	$F5,$30,$00,$00	; *--
		.BYTE	$F5,$20,$00,$F8	; *--
_spr_raw_lib08_A0:
		.BYTE	$04
		.BYTE	$00,$4E,$00,$F8
		.BYTE	$00,$4E,$40,$00
		.BYTE	$F0,$4C,$40,$00
		.BYTE	$F0,$4C,$00,$F8
_spr_raw_lib08_A4:
		.BYTE	$06
		.BYTE	$FC,$48,$00,$F2
		.BYTE	$F3,$48,$00,$07
		.BYTE	$00,$4E,$00,$F8
		.BYTE	$00,$4E,$40,$00
		.BYTE	$F0,$4C,$40,$00
		.BYTE	$F0,$4C,$00,$F8
_spr_raw_lib08_A8:
		.BYTE	$06
		.BYTE	$F0,$58,$00,$0B
		.BYTE	$FE,$58,$00,$EF
		.BYTE	$00,$4E,$00,$F8
		.BYTE	$00,$4E,$40,$00
		.BYTE	$F0,$4C,$40,$00
		.BYTE	$F0,$4C,$00,$F8
_spr_raw_lib08_A1:
		.BYTE	$03
		.BYTE	$F8,$2E,$40,$F4
		.BYTE	$F8,$3C,$40,$FC
		.BYTE	$F8,$2C,$40,$04
_spr_raw_lib08_A5:
		.BYTE	$04
		.BYTE	$01,$48,$40,$0A
		.BYTE	$F8,$2E,$40,$F4
		.BYTE	$F8,$3C,$40,$FC
		.BYTE	$F8,$2C,$40,$04
_spr_raw_lib08_A9:
		.BYTE	$04
		.BYTE	$FC,$58,$40,$0D
		.BYTE	$F8,$2E,$40,$F4
		.BYTE	$F8,$3C,$40,$FC
		.BYTE	$F8,$2C,$40,$04
_spr_raw_lib08_A2:
		.BYTE	$04
		.BYTE	$00,$4C,$80,$F8
		.BYTE	$00,$4C,$C0,$00
		.BYTE	$F0,$4E,$C0,$00
		.BYTE	$F0,$4E,$80,$F8
_spr_raw_lib08_A6:
		.BYTE	$06
		.BYTE	$FB,$48,$80,$F1
		.BYTE	$F3,$48,$80,$06
		.BYTE	$00,$4C,$80,$F8
		.BYTE	$00,$4C,$C0,$00
		.BYTE	$F0,$4E,$C0,$00
		.BYTE	$F0,$4E,$80,$F8
_spr_raw_lib08_AA:
		.BYTE	$06
		.BYTE	$FE,$58,$80,$ED
		.BYTE	$F0,$58,$80,$09
		.BYTE	$00,$4C,$80,$F8
		.BYTE	$00,$4C,$C0,$00
		.BYTE	$F0,$4E,$C0,$00
		.BYTE	$F0,$4E,$80,$F8
_spr_raw_lib08_A3:
		.BYTE	$03
		.BYTE	$F8,$2E,$00,$06
		.BYTE	$F8,$3C,$00,$FE
		.BYTE	$F8,$2C,$00,$F6
_spr_raw_lib08_A7:
		.BYTE	$04
		.BYTE	$01,$48,$00,$F0
		.BYTE	$F8,$2E,$00,$06
		.BYTE	$F8,$3C,$00,$FE
		.BYTE	$F8,$2C,$00,$F6
_spr_raw_lib08_AB:
		.BYTE	$04
		.BYTE	$FC,$58,$00,$ED
		.BYTE	$F8,$2E,$00,$06
		.BYTE	$F8,$3C,$00,$FE
		.BYTE	$F8,$2C,$00,$F6

; =============== S C R I P T ===============================================
_scr09_player_beam:
		NBG_HNDL_SET	_nbgsub_60CA3
		SARG_SET		SARG0,$FF
		SLOOP_BEGIN		$14
		NJSR			_nsub_60CE0
		SDELAY			$01
		SLOOP_END
		SSTOP

; =============== S C R I P T ===============================================
_scr_60C91:
		NBG_HNDL_SET	_nbgsub_60CA3
		SLOOP_BEGIN		$F0
		NJSR			_nsub_60D27
		SBCS_BREAK	_sloc_60C9F
		SDELAY			$01
		SLOOP_END
_sloc_60C9F:
		NJSR			_nsub_60EF1
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_60CA3:
		LDA		_pad0_held
		AND		_control_jump_button_code
		BEQ		loc_60CD0
		LDA		_collision_flag
		BNE		loc_60CD0
		LDA		_tmp7C4
		CMP		#$00
		BNE		loc_60CBB
		LDA		_apu_var400
		BNE		loc_60CC0
loc_60CBB:
		LDA		#$00
		JSR		_far_prg6_apu_snd_load_safe
loc_60CC0:
		LDX		_scr_trds_args0+3
		BMI		locret_60CCF
		LDA		_scr_trds_idx,X
		BMI		loc_60CDD
		LDA		_scr_trds_args0,X
		BMI		loc_60CDD
		BEQ		loc_60CDD
locret_60CCF:
		RTS
loc_60CD0:
		LDX		_scr_trds_args0+3
		BMI		loc_60CDD
		LDA		_scr_trds_args0,X
		BMI		loc_60CDD
		BEQ		loc_60CDD
		JSR		_nsub_60EF1
loc_60CDD:
		JMP		_scr_cur_trd_off

; =============== S U B R O U T I N E =======================================
_nsub_60CE0:
		LDX		#$02
		JSR		_obj_screen_pos_calc
		STY		_tmp2
		LDA		_scr_trds_args1+2
		CLC
		ADC		#$20
		AND		#$C0
		STA		_scr_trds_args1+3
		ASL
		ROL
		ROL
		TAY
		TXA
		CLC
		ADC		byte_60D1F,Y
		STA		_tmp7AB
		TAX
		LDA		_tmp2
		CLC
		ADC		byte_60D23,Y
		STA		_tmp7AC
		TAY
		JSR		sub_61A41
		LDA		_nmi_counter
		AND		#$07
		STA		_tmp0
		LDA		_scr_trds_args1+3
		AND		#$40
		LSR
		LSR
		LSR
		ORA		_tmp0
		CLC
		ADC		#$00
		STA		_scr_trds_spr_idx+3
		RTS
byte_60D1F:
		.BYTE	$00,$1C,$00,$E4
byte_60D23:
		.BYTE	$DC,$FC,$18,$FC

; =============== S U B R O U T I N E =======================================
_nsub_60D27:
		LDX		_scr_trds_args0+3
		JSR		_obj_screen_pos_calc
		BCC		loc_60D2F
locret_60D2E:
		RTS
loc_60D2F:
		TXA
		PHA
		STA		_var0
		TYA
		PHA
		STA		_var1
		LDX		#$02
		JSR		_obj_screen_pos_calc
		STX		_tmp1
		LDA		_scr_trds_args1+2
		CLC
		ADC		#$20
		AND		#$C0
		ASL
		ROL
		ROL
		TAX
		LDA		_tmp1
		ADC		byte_60E67,X
		STA		_scr_trds_x_pos_lo+3
		STA		_var2
		TYA
		CLC
		ADC		byte_60E6B,X
		STA		_scr_trds_y_pos_lo+3
		STA		_var3
		JSR		sub_61BC2
		STA		_var7
		LDA		#$00
		STA		_scr_trds_x_pos_hi+3
		STA		_scr_trds_y_pos_hi+3
		PLA
		STA		_tmp0
		PLA
		SEC
		SBC		_scr_trds_x_pos_lo+3
		BCS		loc_60D78
		DEC		_scr_trds_x_pos_hi+3
		EOR		#$FF
		ADC		#$01
loc_60D78:
		CMP		#$50
		BCS		locret_60D2E
		STA		_scr_trds_x_move_delta+3
		LDA		_tmp0
		SEC
		SBC		_scr_trds_y_pos_lo+3
		BCS		loc_60D8D
		DEC		_scr_trds_y_pos_hi+3
		EOR		#$FF
		ADC		#$01
loc_60D8D:
		CMP		#$50
		BCS		locret_60D2E
		STA		_scr_trds_y_mov_delta+3
		LDX		_scr_trds_x_move_delta+3
		LDA		#$00
		LDY		#$05
		JSR		sub_621BD
		STA		_scr_trds_x_move_speed+3
		STX		_scr_trds_x_move_delta+3
		LDA		_scr_trds_x_pos_hi+3
		BPL		loc_60DBE
		LDA		_scr_trds_x_move_speed+3
		EOR		#$FF
		CLC
		ADC		#$01
		STA		_scr_trds_x_move_speed+3
		LDA		_scr_trds_x_move_delta+3
		EOR		#$FF
		ADC		#$00
		STA		_scr_trds_x_move_delta+3
loc_60DBE:
		LDX		_scr_trds_y_mov_delta+3
		LDA		#$00
		LDY		#$05
		JSR		sub_621BD
		STA		_scr_trds_y_move_speed+3
		STX		_scr_trds_y_mov_delta+3
		LDA		_scr_trds_y_pos_hi+3
		BPL		loc_60DE8
		LDA		_scr_trds_y_move_speed+3
		EOR		#$FF
		CLC
		ADC		#$01
		STA		_scr_trds_y_move_speed+3
		LDA		_scr_trds_y_mov_delta+3
		EOR		#$FF
		ADC		#$00
		STA		_scr_trds_y_mov_delta+3
loc_60DE8:
		LDA		_nmi_counter
		AND		#$01
		TAX
		LDA		byte_60E6F,X
		STA		_var0
		LDA		_var7
		CLC
		ADC		#$08
		AND		#$70
		LSR
		STA		_var7
		LDA		_nmi_counter
		AND		#$06
		ORA		_var7
		ASL
		TAX
		LDA		#$80
		STA		_scr_trds_x_move_clk+3
		STA		_scr_trds_y_move_clk+3
		LDA		#$05
		STA		_var1
		LDY		_spr_buf_pos
loc_60E12:
		LSR		_var0
		BCC		loc_60E3D
; REGION, missing in the US proto version, this is a BUG fix for sprite
; glitches when clipping out sprites does not write X position in RAM
; buffer, not initialized it will contain a previous random garbage.
; so clipped sprite may appear randomly.
; this is also an evidence that the US proto were early version of the game
; (later EU version is based on it)
		LDA		#$00
		STA		_ppu_spr_buf+3,Y
; -
		LDA		_scr_trds_y_pos_lo+3
		CLC
		ADC		byte_60E71,X
		STA		_ppu_spr_buf,Y
		INY
		LDA		byte_60E71+1,X
		STA		_ppu_spr_buf,Y
		INY
		LDA		byte_60E71+2,X
		STA		_ppu_spr_buf,Y
		INY
		LDA		_scr_trds_x_pos_lo+3
		CLC
		ADC		byte_60E71+3,X
		STA		_ppu_spr_buf,Y
		INY
loc_60E3D:
		LDA		_scr_trds_x_move_clk+3
		CLC
		ADC		_scr_trds_x_move_speed+3
		STA		_scr_trds_x_move_clk+3
		LDA		_scr_trds_x_pos_lo+3
		ADC		_scr_trds_x_move_delta+3
		STA		_scr_trds_x_pos_lo+3
		LDA		_scr_trds_y_move_clk+3
		CLC
		ADC		_scr_trds_y_move_speed+3
		STA		_scr_trds_y_move_clk+3
		LDA		_scr_trds_y_pos_lo+3
		ADC		_scr_trds_y_mov_delta+3
		STA		_scr_trds_y_pos_lo+3
		DEC		_var1
		BNE		loc_60E12
		STY		_spr_buf_pos
		CLC
		RTS
byte_60E67:
		.BYTE	$00,$08,$FF,$F8
byte_60E6B:
		.BYTE	$F0,$FC,$03,$FC
byte_60E6F:
		.BYTE	$15,$0A
byte_60E71:
		.BYTE	$FC,$60,$01,$FC
		.BYTE	$FC,$60,$41,$FC
		.BYTE	$FC,$70,$01,$FC
		.BYTE	$FC,$70,$41,$FC
		.BYTE	$FC,$62,$01,$FC
		.BYTE	$FC,$72,$01,$FC
		.BYTE	$FC,$64,$01,$FC
		.BYTE	$FC,$74,$01,$FC
		.BYTE	$FC,$66,$01,$FC
		.BYTE	$F4,$66,$C1,$FC
		.BYTE	$FC,$76,$01,$FC
		.BYTE	$F4,$76,$C1,$FC
		.BYTE	$FC,$68,$01,$FC
		.BYTE	$FC,$78,$01,$FC
		.BYTE	$FC,$6A,$01,$FC
		.BYTE	$FC,$7A,$01,$FC
		.BYTE	$FC,$6C,$01,$FC
		.BYTE	$F4,$6C,$81,$FC
		.BYTE	$FC,$7C,$01,$FC
		.BYTE	$F4,$7C,$81,$FC
		.BYTE	$FC,$68,$41,$FC
		.BYTE	$FC,$78,$41,$FC
		.BYTE	$FC,$6A,$41,$FC
		.BYTE	$FC,$7A,$41,$FC
		.BYTE	$FC,$66,$41,$FC
		.BYTE	$F4,$66,$81,$FC
		.BYTE	$FC,$76,$41,$FC
		.BYTE	$F4,$76,$81,$FC
		.BYTE	$FC,$62,$41,$FC
		.BYTE	$FC,$72,$41,$FC
		.BYTE	$FC,$64,$41,$FC
		.BYTE	$FC,$74,$41,$FC

; =============== S U B R O U T I N E =======================================
_nsub_60EF1:
		LDX		_scr_trds_args0+3
		LDA		_scr_trds_args0,X
		BMI		locret_60F02
		CMP		#$02
		BNE		loc_60EFE
		INC		_scr_trds_args0,X
		RTS
loc_60EFE:
		LDA		#$00
		STA		_scr_trds_args0,X
locret_60F02:
		RTS
_spr_raw_lib09_00:
		.BYTE	$03
		.BYTE	$0C,$60,$01,$FC
		.BYTE	$EC,$60,$01,$FC
		.BYTE	$FC,$60,$01,$FC
_spr_raw_lib09_01:
		.BYTE	$02
		.BYTE	$F4,$60,$01,$FC
		.BYTE	$04,$60,$01,$FC
_spr_raw_lib09_02:
		.BYTE	$03
		.BYTE	$EC,$60,$41,$FC
		.BYTE	$0C,$60,$41,$FC
		.BYTE	$FC,$60,$41,$FC
_spr_raw_lib09_03:
		.BYTE	$02
		.BYTE	$F4,$60,$41,$FC
		.BYTE	$04,$60,$41,$FC
_spr_raw_lib09_04:
		.BYTE	$03
		.BYTE	$EC,$70,$01,$FC
		.BYTE	$0C,$70,$01,$FC
		.BYTE	$FC,$70,$01,$FC
_spr_raw_lib09_05:
		.BYTE	$02
		.BYTE	$F4,$70,$01,$FC
		.BYTE	$04,$70,$01,$FC
_spr_raw_lib09_06:
		.BYTE	$02
		.BYTE	$F4,$70,$41,$FC
		.BYTE	$04,$70,$41,$FC
_spr_raw_lib09_07:
		.BYTE	$03
		.BYTE	$0C,$70,$41,$FC
		.BYTE	$EC,$70,$41,$FC
		.BYTE	$FC,$70,$41,$FC
_spr_raw_lib09_08:
		.BYTE	$03
		.BYTE	$FC,$6C,$01,$0C
		.BYTE	$FC,$6C,$01,$EC
		.BYTE	$FC,$6C,$01,$FC
_spr_raw_lib09_09:
		.BYTE	$02
		.BYTE	$FC,$6C,$01,$F4
		.BYTE	$FC,$6C,$01,$04
_spr_raw_lib09_0A:
		.BYTE	$03
		.BYTE	$F4,$6C,$81,$EC
		.BYTE	$F4,$6C,$81,$0C
		.BYTE	$F4,$6C,$81,$FC
_spr_raw_lib09_0B:
		.BYTE	$02
		.BYTE	$F4,$6C,$81,$F4
		.BYTE	$F4,$6C,$81,$04
_spr_raw_lib09_0C:
		.BYTE	$03
		.BYTE	$FC,$7C,$01,$EC
		.BYTE	$FC,$7C,$01,$0C
		.BYTE	$FC,$7C,$01,$FC
_spr_raw_lib09_0D:
		.BYTE	$02
		.BYTE	$FC,$7C,$01,$F4
		.BYTE	$FC,$7C,$01,$04
_spr_raw_lib09_0E:
		.BYTE	$03
		.BYTE	$F4,$7C,$81,$0C
		.BYTE	$F4,$7C,$81,$FC
		.BYTE	$F4,$7C,$81,$EC
_spr_raw_lib09_0F:
		.BYTE	$02
		.BYTE	$F4,$7C,$81,$04
		.BYTE	$F4,$7C,$81,$F4

; =============== S C R I P T ===============================================
_scr0A_catcher_handler:
		STORE8			_tmp7AF,$00
		STORE8			_tmp7BB,$02
		STORE8			_tmp7BC,$18
		STORE16			_tmp7B3,$180
		NJSR			_nsub_61347
		NBG_HNDL_SET	_nbgsub_ingame_player_control
		SUSPEND

; =============== S C R I P T ===============================================
_scr_60FCB:
		POS_X_SET		0,$30,$00
		POS_Y_SET		0,$C8,$02
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$40
		NJSR			_nsub_catcher_spr_idx_calc
		SUSPEND

; =============== S C R I P T ===============================================
_scr_catcher_auto_walk:
		POS_Y_DELTA_SET 0,$80,$FF					; same as for beamer
		SLOOP_BEGIN		$F0							; just walk up, then jump to
		SARG_ALU		SARG0,_ADC,$01				; common handler, returning
		NJSR			_nsub_catcher_spr_idx_calc	; control to the player and AI
		SDELAY			$02
		SLOOP_END
		POS_MOVE_STOP	0
		SJMP			_scr0A_catcher_handler

; =============== S C R I P T ===============================================
_scr_60FEE:
		NJSR			_nsub_catcher_spr_idx_calc
		SDELAY			$78
		SARG_SET		SARG1,$80
		POS_Y_DELTA_SET 0,$00,$01
		SLOOP_BEGIN		$F0
		SARG_ALU		SARG0,_ADC,$01
		NJSR			_nsub_catcher_spr_idx_calc
		SDELAY			$01
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_ingame_player_control:
		LDA		_scr_trds_idx+5
		BPL		locret_6101E
		LDA		_scr_trds_idx
		CMP		#$04
		BNE		loc_61015
		JSR		sub_6033B
loc_61015:
		JSR		_player_catch_obj_insert_test
		JSR		sub_6101F
		JMP		sub_610B2
locret_6101E:
		RTS

; =============== S U B R O U T I N E =======================================
sub_6101F:
		LDA		_scr_trds_x_pos_lo+4
		ORA		_scr_trds_y_pos_lo+4
		AND		#$07
		BNE		loc_6102F
		JSR		sub_610BF
		LDA		_tmp7B6
		BMI		loc_61050
loc_6102F:
		JSR		_nsub_604CD
		LDX		_tmp7B3
		LDY		_tmp7B3+1
		JSR		sub_6050D
		TAY
		BEQ		locret_61063
		BNE		loc_6105A
loc_61040:
		LDA		_scr_trds_x_pos_lo+4
		ORA		_scr_trds_y_pos_lo+4
		AND		#$07
		BNE		loc_6105A
		JSR		sub_610BF
		LDA		_tmp7B6
		BPL		loc_6105A
loc_61050:
		LDA		#$80
		STA		_scr_trds_x_move_clk+4
		STA		_scr_trds_y_move_clk+4
		BNE		locret_61063
loc_6105A:
		JSR		_nsub_604CD
		JSR		sub_60553
		DEY
		BNE		loc_61040
locret_61063:
		RTS

; =============== S U B R O U T I N E =======================================
_player_catch_obj_insert_test:
		LDA		_pad0_pressed
		AND		_control_fire_button_code
		BEQ		locret_610A9
		JSR		_cur_obj_screen_pos_calc
		BCS		locret_610A9
		STX		_tmp1
		STY		_tmp2
		JSR		_nsub_604CD
		PHA
		TAX
		LDA		_tmp2
		CLC
		ADC		byte_610AE,X
		TAY
		LDA		_tmp1
		CLC
		ADC		byte_610AA,X
		TAX
		JSR		sub_61A59
		LDA		#$00
		STA		_tmp7AF
		STA		_var0
		PLA
		LSR
		ROR
		ROR
		STA		_var1
		LDA		#$05
		STA		_var4
		LDA		#$06
		STA		_var5
		LDA		#$0B
		JSR		_thread_lib_load
		LDA		#$01
		JMP		_far_prg6_apu_snd_load_safe
locret_610A9:
		RTS
byte_610AA:
		.BYTE	$00,$09,$00,$F7
byte_610AE:
		.BYTE	$E8,$00,$0C,$00

; =============== S U B R O U T I N E =======================================
sub_610B2:
		LDA		_tmp7B6
		BMI		_nsub_catcher_spr_idx_calc
		INC		_scr_trds_args0+4

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_nsub_catcher_spr_idx_calc:
		LDA		_catcher_idxB
		JMP		_players_spr_idx_calc

; =============== S U B R O U T I N E =======================================
sub_610BF:
		TYA
		PHA
		LDX		_tmp7BB
		CPX		#$02
		BNE		loc_610CF
		JSR		sub_6118D
		BCS		loc_610F5
		BCC		loc_610E2
loc_610CF:
		LDA		_scr_trds_idx,X
		BMI		loc_610DD
		LDA		_scr_trds_args0,X
		BEQ		loc_610DD
		JSR		_obj_screen_pos_calc
		BCC		loc_610F5
loc_610DD:
		JSR		sub_6118D
		BCS		loc_610E6
loc_610E2:
		LDA		#$30
		BNE		loc_610EA
loc_610E6:
		LDX		#$02
		LDA		#$18
loc_610EA:
		STX		_tmp7BB
		STA		_tmp7BC
		LDA		#$00
		STA		_tmp7AF
loc_610F5:
		LDX		_tmp7BB
		LDY		_tmp7BC
		INY
		JSR		sub_6121E
		BCC		loc_6111B
		LDA		_tmp7BB
		CMP		#$02
		BEQ		loc_61112
		JSR		sub_61AB9
		CLC
		ADC		#$20
		AND		#$C0
		STA		_scr_trds_args1+4
loc_61112:
		LDA		#$00
		STA		_tmp7AF
		LDA		#$FF
		BNE		loc_61187
loc_6111B:
		LDA		_tmp7AF
		BEQ		loc_61133
		JSR		sub_61283
		JSR		sub_604E0
		BCS		loc_6112E
		JSR		sub_61272
		JMP		loc_61184
loc_6112E:
		JSR		_nsub_604CD
		BPL		loc_61146
loc_61133:
		JSR		_nsub_604CD
		LDY		#$07
		LDX		_tmp7BB
		JSR		sub_6129F
		BCC		loc_61146
		LDY		_tmp7BB
		JSR		sub_611A9
loc_61146:
		STA		_var4
		JSR		sub_604E0
		BCC		loc_61184
		JSR		sub_61239
		LDY		_tmp7BB
		JSR		sub_611A9
		STA		_tmp0
		EOR		_var4
		LSR
		BCC		loc_61161
		LDA		_tmp0
		BPL		loc_61163
loc_61161:
		LDA		_var5
loc_61163:
		STA		_var5
		JSR		sub_604E0
		BCC		loc_61184
		ADC		#$01
		AND		#$03
		JSR		sub_604E0
		BCC		loc_61184
		LDA		_var5
		JSR		sub_61239
		LDA		_var4
		CLC
		ADC		#$02
		AND		#$03
		JSR		sub_604E0
		BCS		loc_61112
loc_61184:
		JSR		sub_604D5
loc_61187:
		STA		_tmp7B6
		PLA
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
sub_6118D:
		LDX		#$06
loc_6118F:
		LDA		_scr_trds_idx,X
		BMI		loc_611A3
		LDA		_scr_trds_args0,X
		CMP		#$02
		BNE		loc_611A3
		TXA
		PHA
		JSR		_obj_screen_pos_calc
		PLA
		TAX
		BCC		locret_611A8
loc_611A3:
		INX
		CPX		#$0E
		BCC		loc_6118F
locret_611A8:
		RTS

; =============== S U B R O U T I N E =======================================
sub_611A9:
		LDX		#$00
		STX		_tmp1
		INX
		STX		_tmp2
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,Y
		SEC
		SBC		_scr_trds_x_pos_lo,X
		STA		_var0
		LDA		_scr_trds_x_pos_hi,Y
		SBC		_scr_trds_x_pos_hi,X
		BCS		loc_611D2
		INC		_tmp1
		PHA
		LDA		_var0
		EOR		#$FF
		ADC		#$01
		STA		_var0
		PLA
		EOR		#$FF
		ADC		#$00
loc_611D2:
		STA		_var1
		LDA		_tmp1
		ASL
		ADC		#$01
		STA		_tmp1
		LDA		_scr_trds_y_pos_lo,Y
		SEC
		SBC		_scr_trds_y_pos_lo,X
		STA		_var2
		LDA		_scr_trds_y_pos_hi,Y
		SBC		_scr_trds_y_pos_hi,X
		BCS		loc_611FB
		DEC		_tmp2
		PHA
		LDA		_var2
		EOR		#$FF
		ADC		#$01
		STA		_var2
		PLA
		EOR		#$FF
		ADC		#$00
loc_611FB:
		STA		_var3
		LDA		_tmp2
		ASL
		STA		_tmp2
		LDA		_var1
		CMP		_var3
		BCC		loc_61210
		BNE		loc_61217
		LDA		_var0
		CMP		_var2
		BCS		loc_61217
loc_61210:
		LDA		_tmp1
		STA		_var5
		LDA		_tmp2
		RTS
loc_61217:
		LDA		_tmp2
		STA		_var5
		LDA		_tmp1
		RTS

; =============== S U B R O U T I N E =======================================
sub_6121E:
		JSR		sub_61C5E
		BCC		locret_61238
		LDA		_tmp7BB
		CMP		#$02
		BNE		loc_6122E
		LDA		#$18
		BNE		loc_61230
loc_6122E:
		LDA		#$07
loc_61230:
		CMP		_tmp1
		BCS		locret_61236
		CMP		_tmp2
locret_61236:
		RTS
_unref_1:
		; *--
		CLC
locret_61238:
		RTS

; =============== S U B R O U T I N E =======================================
sub_61239:
		PHA
		STA		_tmp0
		LDA		_tmp7AF
		AND		#$03
		TAX
		TAY
		BEQ		loc_6124C
loc_61245:
		ASL			_tmp0
		ASL			_tmp0
		DEY
		BNE		loc_61245
loc_6124C:
		LDA		_tmp7AF
		LSR
		LSR
		TAY
		LDA		_tmp7AD,Y
		AND		byte_6126A,X
		ORA		_tmp0
		STA		_tmp7AD,Y
		INC		_tmp7AF
		LDA		_tmp7AF
		AND		#$07
		STA		_tmp7AF
		PLA
		RTS
byte_6126A:
		.BYTE	$FC,$F3,$CF,$3F
byte_6126E:
		.BYTE	$03,$0C,$30,$C0

; =============== S U B R O U T I N E =======================================
sub_61272:
		JSR		sub_61283
		PHA
		DEC		_tmp7AF
		LDA		_tmp7AF
		AND		#$07
		STA		_tmp7AF
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
sub_61283:
		LDX		_tmp7AF
		DEX
		TXA
		PHA
		AND		#$03
		TAX
		PLA
		LSR
		LSR
		TAY
		LDA		_tmp7AD,Y
		AND		byte_6126E,X
		DEX
		BMI		locret_6129E
loc_61299:
		LSR
		LSR
		DEX
		BPL		loc_61299
locret_6129E:
		RTS

; =============== S U B R O U T I N E =======================================
sub_6129F:
		PHA
		STA		_var1
		STY		_var0
		DEC		_var1
		BPL		loc_612C2
		JSR		sub_61326
		BEQ		loc_612B1
		BCC		loc_61314
		BCS		loc_61317
loc_612B1:
		JSR		sub_6133D
		STA		_tmp0
		TYA
		SEC
		SBC		_tmp0
		BCC		loc_61314
		CMP		_var0
		BCC		loc_61314
		BCS		loc_61317
loc_612C2:
		DEC		_var1
		BPL		loc_612DF
		JSR		sub_6131A
		BEQ		loc_612CF
		BCS		loc_61314
		BCC		loc_61317
loc_612CF:
		STY		_tmp0
		JSR		sub_61337
		SEC
		SBC		_tmp0
		BCC		loc_61314
		CMP		_var0
		BCC		loc_61314
		BCS		loc_61317
loc_612DF:
		DEC		_var1
		BPL		loc_612FC
		JSR		sub_61326
		BEQ		loc_612EC
		BCS		loc_61314
		BCC		loc_61317
loc_612EC:
		STY		_tmp0
		JSR		sub_6133D
		SEC
		SBC		_tmp0
		BCC		loc_61314
		CMP		_var0
		BCC		loc_61314
		BCS		loc_61317
loc_612FC:
		JSR		sub_6131A
		BEQ		loc_61305
		BCC		loc_61314
		BCS		loc_61317
loc_61305:
		JSR		sub_61337
		STA		_tmp0
		TYA
		SEC
		SBC		_tmp0
		BCC		loc_61314
		CMP		_var0
		BCS		loc_61317
loc_61314:
		PLA
		SEC
		RTS
loc_61317:
		PLA
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
sub_6131A:
		LDA		_scr_trds_x_pos_lo+4
		SEC
		SBC		_ppu_scroll_pos_x
		TAY
		LDA		_scr_trds_x_pos_hi+4
		SBC		_ppu_scroll_pos_x+1
		RTS

; =============== S U B R O U T I N E =======================================
sub_61326:
		LDA		_scr_trds_y_pos_lo+4
		SEC
		SBC		_ppu_scroll_pos_y
		BCS		loc_61330
		SBC		#$0F
		CLC
loc_61330:
		TAY
		LDA		_scr_trds_y_pos_hi+4
		SBC		_ppu_scroll_pos_y+1
		RTS

; =============== S U B R O U T I N E =======================================
sub_61337:
		LDA		_scr_trds_x_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_x
		RTS

; =============== S U B R O U T I N E =======================================
sub_6133D:
		LDA		_scr_trds_y_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_y
		BCS		locret_61346
		SBC		#$0F
locret_61346:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_61347:
		LDA		_catcher_idxA
		STA		_catcher_idxB
		RTS

; =============== S C R I P T ===============================================
_scr0B_player_catch:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_61379
		NJSR			_nsub_613C5
_sloc_61357:
		NJSR			_nsub_613F1
		SDELAY			$01
		NJSR			_nsub_613F7
		SBCC			_sloc_61357
		SJMP			_sloc_6136A

; =============== S C R I P T ===============================================
_scr_61365:
		NJSR			_nsub_61429
		SDELAY			$0E
_sloc_6136A:
		NJSR			_nsub_613FC
_sloc_6136D:
		NJSR			_nsub_6141A
		SDELAY			$01
		NJSR			_nsub_61421
		SBCC			_sloc_6136D
		SSTOP

; =============== S U B R O U T I N E =======================================
_nbgsub_61379:
		JSR		sub_61449
		BCS		locret_613C4
		LDA		_scr_trds_idx+3
		BMI		loc_6138C
		CPX		_scr_trds_args0+3
		BNE		loc_6138C
		LDA		#$FF
		STA		_scr_trds_idx+3
loc_6138C:
		LDY		#$00
		LDA		_scr_trds_x_pos_lo+5
		SEC
		SBC		_scr_trds_x_pos_lo,X
		LDA		_scr_trds_x_pos_hi+5
		SBC		_scr_trds_x_pos_hi,X
		BCS		loc_6139C
		INY
loc_6139C:
		TYA
		ORA		#$80
		STA		_scr_trds_args0,X
		LDA		_scr_trds_x_pos_lo+5
		STA		_scr_trds_x_pos_lo,X
		LDA		_scr_trds_x_pos_hi+5
		STA		_scr_trds_x_pos_hi,X
		LDA		_scr_trds_y_pos_lo+5
		SEC
		SBC		#$12
		BCS		loc_613B5
		SBC		#$0F
		CLC
loc_613B5:
		STA		_scr_trds_y_pos_lo,X
		LDA		_scr_trds_y_pos_hi+5
		SBC		#$00
		STA		_scr_trds_y_pos_hi,X
		JSR		_cur_thread_reload_param
		.WORD	_scr_61365
locret_613C4:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_613C5:
		JSR		_nsub_604CD
		ASL
		TAY
		LDA		byte_613E3+6,Y
		STA		_scr_trds_x_move_speed+5
		LDA		byte_613E3+7,Y
		STA		_scr_trds_x_move_delta+5
		LDA		byte_613E3+4,Y
		STA		_scr_trds_y_move_speed+5
		LDA		byte_613E3+5,Y
		STA		_scr_trds_y_mov_delta+5
		RTS
byte_613E3:
		.BYTE	$00,$04,$00,$00,$00,$FC,$00
		.BYTE	$00,$00,$04,$00,$00,$00,$FC

; =============== S U B R O U T I N E =======================================
_nsub_613F1:
		JSR		sub_61438
		INC		_scr_trds_args0+5
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_613F7:
		LDA		_scr_trds_args0+5
		CMP		#$08
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_613FC:
		JSR		_nsub_604CD
		ASL
		TAY
		LDA		byte_613E3+2,Y
		STA		_scr_trds_x_move_speed+5
		LDA		byte_613E3+3,Y
		STA		_scr_trds_x_move_delta+5
		LDA		byte_613E3,Y
		STA		_scr_trds_y_move_speed+5
		LDA		byte_613E3+1,Y
		STA		_scr_trds_y_mov_delta+5
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_6141A:
		LDX		_scr_cur_trd_idx
		DEC		_scr_trds_args0+5
		JMP		sub_61438

; =============== S U B R O U T I N E =======================================
_nsub_61421:
		LDA		_scr_trds_args0+5
		BNE		loc_61427
		SEC
		RTS
loc_61427:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_61429:
		DEC		_scr_trds_args0+5
		JSR		sub_61438
		LDA		_scr_trds_spr_idx+5
		CLC
		ADC		#$10
		STA		_scr_trds_spr_idx+5
		INC		_scr_trds_args0+5
		RTS

; =============== S U B R O U T I N E =======================================
sub_61438:
		JSR		_nsub_604CD
		STA		_tmp0
		LDA		_scr_trds_args0+5
		AND		#$06
		ASL
		ADC		_tmp0
		ADC		#$10
		STA		_scr_trds_spr_idx+5
		RTS

; =============== S U B R O U T I N E =======================================
sub_61449:
		JSR		_cur_obj_screen_pos_calc
		STX		_tmp1
		STY		_tmp2
		LDX		#$06
loc_61452:
		TXA
		PHA
		LDA		_scr_trds_idx,X
		BMI		loc_61480
		LDA		_scr_trds_args0,X
		BMI		loc_61480
		CMP		#$02
		BCC		loc_61480
		JSR		_obj_screen_pos_calc
		BCS		loc_61480
		TXA
		SBC		_tmp1
		BCS		loc_6146F
		EOR		#$FF
		ADC		#$01
loc_6146F:
		CMP		#$11
		BCS		loc_61480
		TYA
		SBC		_tmp2
		BCS		loc_6147C
		EOR		#$FF
		ADC		#$01
loc_6147C:
		CMP		#$11
		BCC		loc_61488
loc_61480:
		PLA
		TAX
		INX
		CPX		#$0E
		BCC		loc_61452
		RTS
loc_61488:
		PLA
		TAX
		RTS
_spr_raw_lib09_13:
		.BYTE	$03
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$50,$00,$00
		.BYTE	$F4,$40,$00,$F8
_spr_raw_lib09_17:
		.BYTE	$04
		.BYTE	$F4,$46,$00,$10
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$50,$00,$00
		.BYTE	$F4,$40,$00,$F8
_spr_raw_lib09_1B:
		.BYTE	$05
		.BYTE	$F4,$46,$00,$18
		.BYTE	$F4,$46,$00,$10
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$50,$00,$00
		.BYTE	$F4,$40,$00,$F8
_spr_raw_lib09_1F:
		.BYTE	$06
		.BYTE	$F4,$46,$00,$20
		.BYTE	$F4,$46,$00,$18
		.BYTE	$F4,$46,$00,$10
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$50,$00,$00
		.BYTE	$F4,$40,$00,$F8
_spr_raw_lib09_23:
		.BYTE	$03
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$52,$00,$00
		.BYTE	$F4,$42,$00,$F8
_spr_raw_lib09_27:
		.BYTE	$04
		.BYTE	$F4,$46,$00,$10
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$52,$00,$00
		.BYTE	$F4,$42,$00,$F8
_spr_raw_lib09_2B:
		.BYTE	$05
		.BYTE	$F4,$46,$00,$18
		.BYTE	$F4,$46,$00,$10
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$52,$00,$00
		.BYTE	$F4,$42,$00,$F8
_spr_raw_lib09_2F:
		.BYTE	$06
		.BYTE	$F4,$46,$00,$20
		.BYTE	$F4,$46,$00,$18
		.BYTE	$F4,$46,$00,$10
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$52,$00,$00
		.BYTE	$F4,$42,$00,$F8
_spr_raw_lib09_11:
		.BYTE	$03
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$50,$40,$F8
		.BYTE	$F4,$40,$40,$00
_spr_raw_lib09_15:
		.BYTE	$04
		.BYTE	$F4,$46,$40,$E8
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$50,$40,$F8
		.BYTE	$F4,$40,$40,$00
_spr_raw_lib09_19:
		.BYTE	$05
		.BYTE	$F4,$46,$40,$E0
		.BYTE	$F4,$46,$40,$E8
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$50,$40,$F8
		.BYTE	$F4,$40,$40,$00
_spr_raw_lib09_1D:
		.BYTE	$06
		.BYTE	$F4,$46,$40,$D8
		.BYTE	$F4,$46,$40,$E0
		.BYTE	$F4,$46,$40,$E8
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$50,$40,$F8
		.BYTE	$F4,$40,$40,$00
_spr_raw_lib09_21:
		.BYTE	$03
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$42,$40,$00
		.BYTE	$F4,$52,$40,$F8
_spr_raw_lib09_25:
		.BYTE	$04
		.BYTE	$F4,$46,$40,$E8
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$42,$40,$00
		.BYTE	$F4,$52,$40,$F8
_spr_raw_lib09_29:
		.BYTE	$05
		.BYTE	$F4,$46,$40,$E0
		.BYTE	$F4,$46,$40,$E8
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$42,$40,$00
		.BYTE	$F4,$52,$40,$F8
_spr_raw_lib09_2D:
		.BYTE	$06
		.BYTE	$F4,$46,$40,$D8
		.BYTE	$F4,$46,$40,$E0
		.BYTE	$F4,$46,$40,$E8
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$42,$40,$00
		.BYTE	$F4,$52,$40,$F8
_spr_raw_lib09_14:
		.BYTE	$02
		.BYTE	$08,$56,$00,$FC
		.BYTE	$F8,$54,$00,$FC
_spr_raw_lib09_1C:
		.BYTE	$03
		.BYTE	$18,$56,$00,$FC
		.BYTE	$08,$56,$00,$FC
		.BYTE	$F8,$54,$00,$FC
_spr_raw_lib09_24:
		.BYTE	$02
		.BYTE	$08,$56,$00,$FC
		.BYTE	$F8,$44,$00,$FC
_spr_raw_lib09_2C:
		.BYTE	$03
		.BYTE	$18,$56,$00,$FC
		.BYTE	$08,$56,$00,$FC
		.BYTE	$F8,$44,$00,$FC
_spr_raw_lib09_16:
		.BYTE	$02
		.BYTE	$E8,$56,$00,$FC
		.BYTE	$F8,$54,$00,$FC
_spr_raw_lib09_1E:
		.BYTE	$03
		.BYTE	$D8,$56,$00,$FC
		.BYTE	$E8,$56,$00,$FC
		.BYTE	$F8,$54,$00,$FC
_spr_raw_lib09_26:
		.BYTE	$02
		.BYTE	$E8,$56,$00,$FC
		.BYTE	$F8,$44,$00,$FC
_spr_raw_lib09_2E:
		.BYTE	$03
		.BYTE	$D8,$56,$00,$FC
		.BYTE	$E8,$56,$00,$FC
		.BYTE	$F8,$44,$00,$FC
_spr_raw_lib08:
		.WORD	_spr_raw_lib08_02
		.WORD	_spr_raw_lib08_01
		.WORD	_spr_raw_lib08_02
		.WORD	_spr_raw_lib08_03
		.WORD	_spr_raw_lib08_06
		.WORD	_spr_raw_lib08_05
		.WORD	_spr_raw_lib08_06
		.WORD	_spr_raw_lib08_07
		.WORD	_spr_raw_lib08_0A
		.WORD	_spr_raw_lib08_09
		.WORD	_spr_raw_lib08_0A
		.WORD	_spr_raw_lib08_0B
		.WORD	_spr_raw_lib08_0E
		.WORD	_spr_raw_lib08_0D
		.WORD	_spr_raw_lib08_0E
		.WORD	_spr_raw_lib08_0F
		.WORD	_spr_raw_lib08_12
		.WORD	_spr_raw_lib08_11
		.WORD	_spr_raw_lib08_12
		.WORD	_spr_raw_lib08_13
		.WORD	_spr_raw_lib08_16
		.WORD	_spr_raw_lib08_15
		.WORD	_spr_raw_lib08_16
		.WORD	_spr_raw_lib08_17
		.WORD	_spr_raw_lib08_1A
		.WORD	_spr_raw_lib08_19
		.WORD	_spr_raw_lib08_1A
		.WORD	_spr_raw_lib08_1B
		.WORD	_spr_raw_lib08_1E
		.WORD	_spr_raw_lib08_1D
		.WORD	_spr_raw_lib08_1E
		.WORD	_spr_raw_lib08_1F
		.WORD	_spr_raw_lib08_22
		.WORD	_spr_raw_lib08_21
		.WORD	_spr_raw_lib08_22
		.WORD	_spr_raw_lib08_23
		.WORD	_spr_raw_lib08_26
		.WORD	_spr_raw_lib08_25
		.WORD	_spr_raw_lib08_26
		.WORD	_spr_raw_lib08_27
		.WORD	_spr_raw_lib08_2A
		.WORD	_spr_raw_lib08_29
		.WORD	_spr_raw_lib08_2A
		.WORD	_spr_raw_lib08_2B
		.WORD	_spr_raw_lib08_2E
		.WORD	_spr_raw_lib08_2D
		.WORD	_spr_raw_lib08_2E
		.WORD	_spr_raw_lib08_2F
		.WORD	_spr_raw_lib08_32
		.WORD	_spr_raw_lib08_31
		.WORD	_spr_raw_lib08_32
		.WORD	_spr_raw_lib08_33
		.WORD	_spr_raw_lib08_36
		.WORD	_spr_raw_lib08_35
		.WORD	_spr_raw_lib08_36
		.WORD	_spr_raw_lib08_37
		.WORD	_spr_raw_lib08_3A
		.WORD	_spr_raw_lib08_39
		.WORD	_spr_raw_lib08_3A
		.WORD	_spr_raw_lib08_3B
		.WORD	_spr_raw_lib08_3E
		.WORD	_spr_raw_lib08_3D
		.WORD	_spr_raw_lib08_3E
		.WORD	_spr_raw_lib08_3F
		.WORD	_spr_raw_lib08_42
		.WORD	_spr_raw_lib08_41
		.WORD	_spr_raw_lib08_42
		.WORD	_spr_raw_lib08_43
		.WORD	_spr_raw_lib08_46
		.WORD	_spr_raw_lib08_45
		.WORD	_spr_raw_lib08_46
		.WORD	_spr_raw_lib08_47
		.WORD	_spr_raw_lib08_4A
		.WORD	_spr_raw_lib08_49
		.WORD	_spr_raw_lib08_4A
		.WORD	_spr_raw_lib08_4B
		.WORD	_spr_raw_lib08_4E
		.WORD	_spr_raw_lib08_4D
		.WORD	_spr_raw_lib08_4E
		.WORD	_spr_raw_lib08_4F
		.WORD	_spr_raw_lib08_52
		.WORD	_spr_raw_lib08_53
		.WORD	_spr_raw_lib08_52
		.WORD	_spr_raw_lib08_53
		.WORD	_spr_raw_lib08_56
		.WORD	_spr_raw_lib08_57
		.WORD	_spr_raw_lib08_56
		.WORD	_spr_raw_lib08_57
		.WORD	_spr_raw_lib08_5A
		.WORD	_spr_raw_lib08_5B
		.WORD	_spr_raw_lib08_5A
		.WORD	_spr_raw_lib08_5B
		.WORD	_spr_raw_lib08_5E
		.WORD	_spr_raw_lib08_5F
		.WORD	_spr_raw_lib08_5E
		.WORD	_spr_raw_lib08_5F
		.WORD	_spr_raw_lib08_62
		.WORD	_spr_raw_lib08_63
		.WORD	_spr_raw_lib08_62
		.WORD	_spr_raw_lib08_63
		.WORD	_spr_raw_lib08_66
		.WORD	_spr_raw_lib08_67
		.WORD	_spr_raw_lib08_66
		.WORD	_spr_raw_lib08_67
		.WORD	_spr_raw_lib08_6A
		.WORD	_spr_raw_lib08_6B
		.WORD	_spr_raw_lib08_6A
		.WORD	_spr_raw_lib08_6B
		.WORD	_spr_raw_lib08_6E
		.WORD	_spr_raw_lib08_6F
		.WORD	_spr_raw_lib08_6E
		.WORD	_spr_raw_lib08_6F
		.WORD	_spr_raw_lib08_72
		.WORD	_spr_raw_lib08_73
		.WORD	_spr_raw_lib08_72
		.WORD	_spr_raw_lib08_73
		.WORD	_spr_raw_lib08_76
		.WORD	_spr_raw_lib08_77
		.WORD	_spr_raw_lib08_76
		.WORD	_spr_raw_lib08_77
		.WORD	_spr_raw_lib08_7A
		.WORD	_spr_raw_lib08_7B
		.WORD	_spr_raw_lib08_7A
		.WORD	_spr_raw_lib08_7B
		.WORD	_spr_raw_lib08_7E
		.WORD	_spr_raw_lib08_7F
		.WORD	_spr_raw_lib08_7E
		.WORD	_spr_raw_lib08_7F
		.WORD	_spr_raw_lib08_82
		.WORD	_spr_raw_lib08_83
		.WORD	_spr_raw_lib08_82
		.WORD	_spr_raw_lib08_83
		.WORD	_spr_raw_lib08_86
		.WORD	_spr_raw_lib08_87
		.WORD	_spr_raw_lib08_86
		.WORD	_spr_raw_lib08_87
		.WORD	_spr_raw_lib08_8A
		.WORD	_spr_raw_lib08_8B
		.WORD	_spr_raw_lib08_8A
		.WORD	_spr_raw_lib08_8B
		.WORD	_spr_raw_lib08_8E
		.WORD	_spr_raw_lib08_8F
		.WORD	_spr_raw_lib08_8E
		.WORD	_spr_raw_lib08_8F
		.WORD	_spr_raw_lib08_92	; *--
		.WORD	_spr_raw_lib08_93	; *--
		.WORD	_spr_raw_lib08_92	; *--
		.WORD	_spr_raw_lib08_93	; *--
		.WORD	_spr_raw_lib08_96	; *--
		.WORD	_spr_raw_lib08_97	; *--
		.WORD	_spr_raw_lib08_96	; *--
		.WORD	_spr_raw_lib08_97	; *--
		.WORD	_spr_raw_lib08_9A	; *--
		.WORD	_spr_raw_lib08_9B	; *--
		.WORD	_spr_raw_lib08_9A	; *--
		.WORD	_spr_raw_lib08_9B	; *--
		.WORD	_spr_raw_lib08_9E	; *--
		.WORD	_spr_raw_lib08_9F	; *--
		.WORD	_spr_raw_lib08_9E	; *--
		.WORD	_spr_raw_lib08_9F	; *--
		.WORD	_spr_raw_lib08_A0
		.WORD	_spr_raw_lib08_A1
		.WORD	_spr_raw_lib08_A2
		.WORD	_spr_raw_lib08_A3
		.WORD	_spr_raw_lib08_A4
		.WORD	_spr_raw_lib08_A5
		.WORD	_spr_raw_lib08_A6
		.WORD	_spr_raw_lib08_A7
		.WORD	_spr_raw_lib08_A8
		.WORD	_spr_raw_lib08_A9
		.WORD	_spr_raw_lib08_AA
		.WORD	_spr_raw_lib08_AB
		.WORD	_spr_raw_lib08_AC
		.WORD	_spr_raw_lib08_AD
		.WORD	_spr_raw_lib08_AE
		.WORD	_spr_raw_lib08_AF
_spr_raw_lib09:
		.WORD	_spr_raw_lib09_00
		.WORD	_spr_raw_lib09_01
		.WORD	_spr_raw_lib09_02
		.WORD	_spr_raw_lib09_03
		.WORD	_spr_raw_lib09_04
		.WORD	_spr_raw_lib09_05
		.WORD	_spr_raw_lib09_06
		.WORD	_spr_raw_lib09_07
		.WORD	_spr_raw_lib09_08
		.WORD	_spr_raw_lib09_09
		.WORD	_spr_raw_lib09_0A
		.WORD	_spr_raw_lib09_0B
		.WORD	_spr_raw_lib09_0C
		.WORD	_spr_raw_lib09_0D
		.WORD	_spr_raw_lib09_0E
		.WORD	_spr_raw_lib09_0F
		.WORD	_spr_raw_lib09_14
		.WORD	_spr_raw_lib09_11
		.WORD	_spr_raw_lib09_16
		.WORD	_spr_raw_lib09_13
		.WORD	_spr_raw_lib09_14
		.WORD	_spr_raw_lib09_15
		.WORD	_spr_raw_lib09_16
		.WORD	_spr_raw_lib09_17
		.WORD	_spr_raw_lib09_1C
		.WORD	_spr_raw_lib09_19
		.WORD	_spr_raw_lib09_1E
		.WORD	_spr_raw_lib09_1B
		.WORD	_spr_raw_lib09_1C
		.WORD	_spr_raw_lib09_1D
		.WORD	_spr_raw_lib09_1E
		.WORD	_spr_raw_lib09_1F
		.WORD	_spr_raw_lib09_24
		.WORD	_spr_raw_lib09_21
		.WORD	_spr_raw_lib09_26
		.WORD	_spr_raw_lib09_23
		.WORD	_spr_raw_lib09_24
		.WORD	_spr_raw_lib09_25
		.WORD	_spr_raw_lib09_26
		.WORD	_spr_raw_lib09_27
		.WORD	_spr_raw_lib09_2C
		.WORD	_spr_raw_lib09_29
		.WORD	_spr_raw_lib09_2E
		.WORD	_spr_raw_lib09_2B
		.WORD	_spr_raw_lib09_2C
		.WORD	_spr_raw_lib09_2D
		.WORD	_spr_raw_lib09_2E
		.WORD	_spr_raw_lib09_2F

; =============== S U B R O U T I N E =======================================
_obj_to_room_bound_box_collision_test:
		STA		_ptr08
		STY		_ptr08+1
		TXA
		PHA
		LDY		#$00
		STY		_var0
		LDA		(_ptr08),Y
		TAX
		INY
loc_617E1:
		TXA
		PHA
		LDA		(_ptr08),Y
		TAX
		INY
		LDA		(_ptr08),Y
		STA		_tmp2
		INY
		TYA
		PHA
		LDY		_tmp2
		LDA		_var0
		PHA
		JSR		_obj_to_room_macro_collision_test_box
		PLA
		ROL
		STA		_var0
		PLA
		TAY
		PLA
		TAX
		DEX
		BNE		loc_617E1
		PLA
		TAX
		LDA		_var0
		BNE		loc_61809
		CLC
		RTS
loc_61809:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_room_doors_collision_test:
		STY		_tmp2
		LDY		_cur_room_doors_cnt
		BEQ		loc_61860
loc_61812:
		TXA
		SEC
		SBC		_obj_door_x_hi_poss,Y
		STA		_tmp0
		LDA		_tmp_var0
		SBC		_obj_door_x_lo_poss,Y
		BCS		loc_6182E
		PHA
		LDA		_tmp0
		EOR		#$FF
		ADC		#$01
		STA		_tmp0
		PLA
		EOR		#$FF
		ADC		#$00
loc_6182E:
		BNE		loc_6185D
		LDA		_obj_doors_widths,Y
		CMP		_tmp0
		BCC		loc_6185D
		LDA		_tmp2
		SEC
		SBC		_obj_doors_y_hi_poss,Y
		STA		_tmp0
		LDA		_tmp_var1
		SBC		_obj_doors_y_lo_poss,Y
		BCS		loc_61854
		PHA
		LDA		_tmp0
		EOR		#$FF
		ADC		#$01
		STA		_tmp0
		PLA
		EOR		#$FF
		ADC		#$00
loc_61854:
		BNE		loc_6185D
		LDA		_obj_doors_heights,Y
		CMP		_tmp0
		BCS		loc_61861
loc_6185D:
		DEY
		BNE		loc_61812
loc_61860:
		CLC
loc_61861:
		LDY		_tmp2
		RTS

; =============== S U B R O U T I N E =======================================
_obj_to_room_macro_collision_test_box:
		LDA		#$00
		STA		_tmp_var0
		STA		_tmp_var1
		TXA
		BPL		loc_6186F
		DEC		_tmp_var0
loc_6186F:
		LDX		_scr_cur_trd_idx
		CLC
		ADC		_scr_trds_x_pos_lo,X
		PHA
		LDA		_tmp_var0
		ADC		_scr_trds_x_pos_hi,X
		STA		_tmp_var0
		CLC
		TYA
		BPL		loc_6188B
		DEC		_tmp_var1
		ADC		_scr_trds_y_pos_lo,X
		BCS		loc_61896
		SBC		#$0F
		CLC
		BCC		loc_61896
loc_6188B:
		ADC		_scr_trds_y_pos_lo,X
		BCS		loc_61893
		CMP		#$F0
		BCC		loc_61896
loc_61893:
		ADC		#$0F
		SEC
loc_61896:
		TAY
		LDA		_tmp_var1
		ADC		_scr_trds_y_pos_hi,X
		STA		_tmp_var1
		PLA
		TAX

; =============== S U B R O U T I N E =======================================
_room_macro_collision_test_ex:
		JSR		_room_doors_collision_test
		BCC		loc_618A6
		RTS
loc_618A6:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		JSR		_room_macro_read
		JSR		_macro_collision_read
		PHP
		PLA
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		LSR
		RTS

; =============== S U B R O U T I N E =======================================
_far_macro_collision_read_unref:
		STA		_tmp0
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_macro_collision_read
		PHP
		PLA
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		LSR
		RTS

; =============== S U B R O U T I N E =======================================
_macro_collision_read:
		STA		_tmp0
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		_tmp0
		LSR
		LSR
		LSR
		TAY
		LDA		_tmp0
		AND		#$07
		TAX
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		(_lvl_collisions_ptr),Y
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		AND		_bit_mask,X
		BNE		loc_61913
		CLC
		BCC		loc_61914
loc_61913:
		SEC
loc_61914:
		PLA
		TAY
		PLA
		TAX
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
_far_room_macro_read_unref:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		JSR		_room_macro_read
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E =======================================
_room_macro_read:
		TYA
		PHA
		AND		#$08
		LSR
		STA		_tmp0
		TXA
		PHA
		AND		#$08
		LSR
		LSR
		ORA		_tmp0
		PHA
		JSR		_lvl_room_ofs_calc
		TAY
		PLA
		TAX
		LDA		_lvl_macroA_ptr,X
		STA		_ptr06
		LDA		_lvl_macroA_ptr+1,X
		STA		_ptr06+1
		LDA		(_ptr06),Y
		STA		_tmp0
		PLA
		TAX
		PLA
		TAY
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E =======================================
_far_lvl_room_ofs_calc:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		JSR		_lvl_room_ofs_calc
		STA		_tmp0
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E =======================================
_lvl_room_ofs_calc:
		TYA
		PHA
		AND		#$F0
		STA		_tmp0
		TXA
		LSR
		LSR
		LSR
		LSR
		ORA		_tmp0
		PHA
		LDA		_tmp_var1
		ASL
		ASL
		ASL
		ORA		_tmp_var0
		ASL
		TAY
		LDA		(_lvl_rooms_lib_ptr),Y
		STA		_ptr06
		INY
		LDA		(_lvl_rooms_lib_ptr),Y
		STA		_ptr06+1
		PLA
		TAY
		LDA		(_ptr06),Y
		STA		_tmp0
		PLA
		TAY
		LDA		_tmp0
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_macro_block_draw:
		STA		_tmp0
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp_var0
		LSR
		TXA
		PHA
		ROR
		LSR
		LSR
		TAX
		LDA		_tmp_var1
		LSR
		TYA
		PHA
		ROR
		LSR
		LSR
		PHA
		LDY		_tmp0
		LDA		(_lvl_macroA_ptr),Y
		STA		_tmp_buf+4
		LDA		(_lvl_macroB_ptr),Y
		STA		_tmp_buf+5
		LDA		(_lvl_macroC_ptr),Y
		STA		_tmp_buf+6
		LDA		(_lvl_macroD_ptr),Y
		STA		_tmp_buf+7
		LDA		(_lvl_attrs_ptr),Y
		STA		_tmp0
		PLA
		TAY
		LDA		_tmp0
		JSR		_ppu_macro_attr_transfer
		LDA		#$02
		STA		_tmp_buf+2
		STA		_tmp_buf+3
		JSR		_ppu_offset_calc
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		PLA
		TAY
		PLA
		TAX
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
sub_619F7:
		LDY		#$00
loc_619F9:
		LDX		#$00
loc_619FB:
		JSR		_far_lvl_room_ofs_calc
		JSR		_ppu_macro_block_draw
		TXA
		CLC
		ADC		#$10
		TAX
		BCC		loc_619FB
		TYA
		CLC
		ADC		#$10
		TAY
		CPY		#$F0
		BCC		loc_619F9
		RTS

; =============== S U B R O U T I N E =======================================
_cur_obj_screen_pos_calc:
		LDX		_scr_cur_trd_idx

; =============== S U B R O U T I N E =======================================
_obj_screen_pos_calc:
		LDA		_scr_trds_x_pos_hi,X
		STA		_tmp_var0
		LDA		_scr_trds_y_pos_hi,X
		STA		_tmp_var1
		LDY		_scr_trds_y_pos_lo,X
		LDA		_scr_trds_x_pos_lo,X
		TAX

; =============== S U B R O U T I N E =======================================
_screen_pos_calc_ex:
		TXA
		SEC
		SBC		_ppu_scroll_pos_x
		TAX
		LDA		_tmp_var0
		SBC		_ppu_scroll_pos_x+1
		BNE		loc_61A3F
		TYA
		SBC		_ppu_scroll_pos_y
		BCS		loc_61A36
		SBC		#$0F
		CLC
loc_61A36:
		TAY
		LDA		_tmp_var1
		SBC		_ppu_scroll_pos_y+1
		BNE		loc_61A3F
		CLC
		RTS
loc_61A3F:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
sub_61A41:
		JSR		sub_61A59
		TXA
		PHA
		LDX		_scr_cur_trd_idx
		PLA
		STA		_scr_trds_x_pos_lo,X
		TYA
		STA		_scr_trds_y_pos_lo,X
		LDA		_tmp_var0
		STA		_scr_trds_x_pos_hi,X
		LDA		_tmp_var1
		STA		_scr_trds_y_pos_hi,X
		RTS

; =============== S U B R O U T I N E =======================================
sub_61A59:
		TXA
		CLC
		ADC		_ppu_scroll_pos_x
		TAX
		LDA		#$00
		ADC		_ppu_scroll_pos_x+1
		STA		_tmp_var0
		TYA
		CLC
		ADC		_ppu_scroll_pos_y
		BCS		loc_61A6E
		CMP		#$F0
		BCC		loc_61A71
loc_61A6E:
		ADC		#$0F
		SEC
loc_61A71:
		TAY
		LDA		#$00
		ADC		_ppu_scroll_pos_y+1
		STA		_tmp_var1
		RTS

; =============== S U B R O U T I N E =======================================
_unref_4:
		TXA
		CLC
		ADC		_ppu_scroll_pos_x
		PHA
		LDA		#$00
		ADC		_ppu_scroll_pos_x+1
		LSR
		PLA
		ROR
		LSR
		LSR
		TAX
		TYA
		CLC
		ADC		_ppu_scroll_pos_y
		BCS		loc_61A92
		CMP		#$F0
		BCC		loc_61A95
loc_61A92:
		ADC		#$0F
		SEC
loc_61A95:
		PHA
		LDA		#$00
		ADC		_ppu_scroll_pos_y+1
		LSR
		PLA
		ROR
		LSR
		LSR
		TAY
		RTS

; =============== S U B R O U T I N E =======================================
sub_61AA1:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo+2
		STA		_var0
		LDA		_scr_trds_y_pos_lo+2
		SEC
		SBC		#$10
		STA		_var1
		LDA		_scr_trds_x_pos_lo,X
		STA		_var2
		LDA		_scr_trds_y_pos_lo,X
		STA		_var3
		JMP		sub_61BC2

; =============== S U B R O U T I N E =======================================
sub_61AB9:
		TAX
		JSR		_obj_screen_pos_calc
		STX		_var0
		STY		_var1
		JSR		_cur_obj_screen_pos_calc
		STX		_var2
		STY		_var3
		JMP		sub_61BC2

; =============== S U B R O U T I N E =======================================
sub_61ACB:
		STA		_ptr0A
		STX		_ptr0A+1
		STY		_tmp2
		TYA
		AND		#$3F
		BNE		loc_61AE9
		TYA
		AND		#$40
		BEQ		loc_61AE3
		LDA		_ptr0A
		STA		_ptr06
		LDA		_ptr0A+1
		BPL		loc_61B0E
loc_61AE3:
		LDA		#$00
		STA		_ptr06
		BEQ		loc_61B0E
loc_61AE9:
		TAX
		LDA		_tmp2
		AND		#$40
		BEQ		loc_61AF5
		TXA
		EOR		#$3F
		TAX
		INX
loc_61AF5:
		LDA		byte_61B82,X
		PHA
		LDX		_ptr0A
		JSR		_div8
		STX		_ptr06
		PLA
		LDX		_ptr0A+1
		JSR		_div8
		CLC
		ADC		_ptr06
		STA		_ptr06
		TXA
		ADC		#$00
loc_61B0E:
		STA		_ptr06+1
		LDA		_tmp2
		BPL		loc_61B25
		LDA		_ptr06
		EOR		#$FF
		CLC
		ADC		#$01
		STA		_ptr06
		LDA		_ptr06+1
		EOR		#$FF
		ADC		#$00
		STA		_ptr06+1
loc_61B25:
		LDA		_tmp2
		AND		#$3F
		BNE		loc_61B3F
		LDA		_tmp2
		AND		#$40
		BNE		loc_61B39
		LDA		_ptr0A
		STA		_ptr08
		LDA		_ptr0A+1
		BPL		loc_61B64
loc_61B39:
		LDA		#$00
		STA		_ptr08
		BEQ		loc_61B64
loc_61B3F:
		TAX
		LDA		_tmp2
		AND		#$40
		BNE		loc_61B4B
		TXA
		EOR		#$3F
		TAX
		INX
loc_61B4B:
		LDA		byte_61B82,X
		PHA
		LDX		_ptr0A
		JSR		_div8
		STX		_ptr08
		PLA
		LDX		_ptr0A+1
		JSR		_div8
		CLC
		ADC		_ptr08
		STA		_ptr08
		TXA
		ADC		#$00
loc_61B64:
		STA		_ptr08+1
		LDA		_tmp2
		CMP		#$40
		BCC		loc_61B70
		CMP		#$C0
		BCC		locret_61B81
loc_61B70:
		LDA		_ptr08
		EOR		#$FF
		CLC
		ADC		#$01
		STA		_ptr08
		LDA		_ptr08+1
		EOR		#$FF
		ADC		#$00
		STA		_ptr08+1
locret_61B81:
		RTS
byte_61B82:
		.BYTE	$00,$06,$0C,$12,$19,$1F,$25,$2B,$31,$38,$3E,$44,$4A,$50,$56,$5C
		.BYTE	$61,$67,$6D,$73,$78,$7E,$83,$88,$8E,$93,$98,$9D,$A2,$A7,$AB,$B0
		.BYTE	$B5,$B9,$BD,$C1,$C5,$C9,$CD,$D1,$D4,$D8,$DB,$DE,$E1,$E4,$E7,$EA
		.BYTE	$EC,$EE,$F1,$F3,$F4,$F6,$F8,$F9,$FB,$FC,$FD,$FE,$FE,$FF,$FF,$FF

; =============== S U B R O U T I N E =======================================
sub_61BC2:
		LDA		_var0
		SEC
		SBC		_var2
		PHP
		BCS		loc_61BCE
		EOR		#$FF
		ADC		#$01
loc_61BCE:
		STA		_var0
		LDA		_var3
		SEC
		SBC		_var1
		PHP
		BCS		loc_61BDC
		EOR		#$FF
		ADC		#$01
loc_61BDC:
		TAY
		PLA
		LSR
		PLA
		ROL
		STA		_tmp0
		TXA
		PHA
		LDA		_tmp0
		AND		#$03
		PHA
		TYA
		BNE		loc_61BF1
		LDY		#$10
		BNE		loc_61C11
loc_61BF1:
		LDX		_var0
		LDA		#$00
		JSR		sub_621BD
		STA		_var0
		STX		_var1
		LDY		#$10
loc_61BFE:
		LDA		_var1
		CMP		byte_61C4D,Y
		BCC		loc_61C0E
		BNE		loc_61C11
		LDA		_var0
		CMP		byte_61C3C,Y
		BCS		loc_61C11
loc_61C0E:
		DEY
		BNE		loc_61BFE
loc_61C11:
		PLA
		TAX
		STA		_tmp0
		TYA
		LSR		_tmp0
		BCS		loc_61C20
		STA		_var0
		LDA		#$11
		SBC		_var0
loc_61C20:
		LSR		_tmp0
		BCS		loc_61C2A
		STA		_var0
		LDA		#$11
		SBC		_var0
loc_61C2A:
		CLC
		ADC		byte_61C38,X
		AND		#$3F
		TAY
		PLA
		TAX
		TYA
		ASL
		ASL
		TAY
		RTS
byte_61C38:
		.BYTE	$20,$30,$10,$00
byte_61C3C:
		.BYTE	$00,$0C,$25,$40,$5B,$79,$99,$BD,$E8,$1A,$59,$AB,$1D,$CB,$FE,$BD
		.BYTE	$5B
byte_61C4D:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$01,$01,$01,$02,$02,$03,$06
		.BYTE	$14

; =============== S U B R O U T I N E =======================================
sub_61C5E:
		STY		_tmp0
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,Y
		SEC
		SBC		_scr_trds_x_pos_lo,X
		STA		_tmp1
		LDA		_scr_trds_x_pos_hi,Y
		SBC		_scr_trds_x_pos_hi,X
		BCS		loc_61C80
		PHA
		LDA		_tmp1
		EOR		#$FF
		ADC		#$01
		STA		_tmp1
		PLA
		EOR		#$FF
		ADC		#$00
loc_61C80:
		BNE		loc_61CD4
		LDA		_tmp1
		CMP		_tmp0
		BCS		loc_61CD4
		LDA		#$00
		STA		_var0
		LDA		_scr_trds_y_pos_lo,Y
		SEC
		SBC		_scr_trds_y_pos_lo,X
		STA		_tmp2
		BCS		loc_61C98
		INC		_var0
loc_61C98:
		LDA		_scr_trds_y_pos_hi,Y
		SBC		_scr_trds_y_pos_hi,X
		BCS		loc_61CB4
		PHA
		LDA		_var0
		EOR		#$01
		STA		_var0
		LDA		_tmp2
		EOR		#$FF
		ADC		#$01
		STA		_tmp2
		PLA
		EOR		#$FF
		ADC		#$00
loc_61CB4:
		STA		_tmp_var1
		CLC
		ADC		_var0
		ASL
		ASL
		ASL
		ASL
		STA		_var0
		LDA		_tmp2
		SEC
		SBC		_var0
		STA		_tmp2
		LDA		_tmp_var1
		SBC		#$00
		BNE		loc_61CD4
		LDA		_tmp2
		CMP		_tmp0
		BCS		loc_61CD4
		SEC
		RTS
loc_61CD4:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_nbgsub_lvl_room_objects_handler:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_lvl_objects_ptr+1
		BNE		loc_61CE7
		JMP		_ld1_exit
loc_61CE7:
		LDY		#$00
		LDA		(_lvl_objects_ptr),Y
		BPL		loc_61D19
		INY
		LDA		(_lvl_objects_ptr),Y
		BNE		loc_61CF6
		STA		_lvl_objects_ptr+1
		BEQ		_ld1_exit
loc_61CF6:
		CMP		#$01
		BNE		loc_61D0D
		INY
		LDA		(_lvl_objects_ptr),Y
		CMP		_cur_lvl_room_idx
		BNE		_ld1_exit
		LDA		_pal_fade_req_list
		BMI		_ld1_exit
		LDA		_near_room_door_data_pos
		BPL		_ld1_exit
		BMI		loc_61D6A
loc_61D0D:
		CMP		#$02
		BNE		_assert_error
		INC		_lvl_cur_checkpoint_idx
		BNE		loc_61D6A
_assert_error:
		JMP		_assert_error
loc_61D19:
		STA		_tmp0
		STY		_var0
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp1
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp_var0
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp2
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_tmp_var1
		LDX		_tmp0
		LDA		_scr_flags,X
		STA		_var7
		ASL			_var7
		BCC		loc_61D41
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_var0
loc_61D41:
		ASL			_var7
		BCC		loc_61D4A
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_var1
loc_61D4A:
		ASL			_var7
		BCC		loc_61D53
		INY
		LDA		(_lvl_objects_ptr),Y
		STA		_var2
loc_61D53:
		TYA
		PHA
		LDX		_tmp1
		LDY		_tmp2
		LDA		#$06
		STA		_var4
		LDA		#$0A
		STA		_var5
		LDA		_tmp0
		JSR		_thread_lib_load
		PLA
		TAY
		BCS		_ld1_exit
loc_61D6A:
		INY
		TYA
		CLC
		ADC		_lvl_objects_ptr
		STA		_lvl_objects_ptr
		BCC		_ld1_exit
		INC		_lvl_objects_ptr+1
_ld1_exit:
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
; look for a beginning of the object data section corresponding to current
; check point index.
;
_nsub_lvl_room_objects_init:
		LDA		_prg_cur_bank
		PHA
		LDA		_lvl_data_prg_bank
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
loc_61D85:
		LDY		#$00
		LDA		(_lvl_objects_ptr),Y
		BPL		loc_61DA2
		INY
		LDA		(_lvl_objects_ptr),Y
		CMP		#$01
		BNE		loc_61D96
		INY
		JMP		loc_61DBD
loc_61D96:
		CMP		#$02
		BNE		loc_61D9F
		INC		_lvl_cur_checkpoint_idx
		BNE		loc_61DBD
loc_61D9F:
		JMP		loc_61D9F
loc_61DA2:
		PHA
		INY
		INY
		INY
		INY
		PLA
		TAX
		LDA		_scr_flags,X
		STA		_var7
		ASL			_var7
		BCC		loc_61DB3
		INY
loc_61DB3:
		ASL			_var7
		BCC		loc_61DB8
		INY
loc_61DB8:
		ASL			_var7
		BCC		loc_61DBD
		INY
loc_61DBD:
		INY
		TYA
		CLC
		ADC		_lvl_objects_ptr
		STA		_lvl_objects_ptr
		BCC		loc_61DC8
		INC		_lvl_objects_ptr+1
loc_61DC8:
		LDA		_lvl_cur_checkpoint_idx
		CMP		_lvl_last_checkpoint_idx
		BCC		loc_61D85
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
sub_61DD6:
		LDA		_scr_trds_idx+3
		BMI		loc_61E28
		LDA		_scr_trds_args0+3
		BPL		loc_61E28
		TXA
		PHA
		LDA		_scr_trds_args1+3
		ASL
		ROL
		ROL
		TAX
		PLA
		ADC		byte_61E2A,X
		STA		_var0
		TYA
		CLC
		ADC		byte_61E2E,X
		STA		_var1
		JSR		_cur_obj_screen_pos_calc
		BCS		loc_61E28
		TXA
		SEC
		SBC		_tmp7AB
		BCS		loc_61E04
		EOR		#$FF
		ADC		#$01
loc_61E04:
		CMP		_var0
		BCS		loc_61E28
		TYA
		SEC
		SBC		_tmp7AC
		BCS		loc_61E13
		EOR		#$FF
		ADC		#$01
loc_61E13:
		CMP		_var1
		BCS		loc_61E28
		LDX		_scr_cur_trd_idx
		LDA		#$01
		STA		_scr_trds_args0,X
		STX		_scr_trds_args0+3
		LDX		#$03
		JSR		_thread_reload_param_ex
		.WORD	_scr_60C91
		SEC
		RTS
loc_61E28:
		CLC
		RTS
byte_61E2A:
		.BYTE	$01,$14,$01,$14
byte_61E2E:
		.BYTE	$14,$01,$14,$01

; =============== S U B R O U T I N E =======================================
_player_to_obj_collision_test:
		LDA		_player_inv_timer
		BNE		locret_61E6B
		STX		_var0
		STY		_var1
		LDX		#$02
		JSR		_obj_screen_pos_calc
		STX		_var2
		STY		_var3
		JSR		_cur_obj_screen_pos_calc
		TXA
		SEC
		SBC		_var2
		BCS		loc_61E51
		EOR		#$FF
		ADC		#$01
loc_61E51:
		CMP		_var0
		BCS		locret_61E6B
		TYA
		SEC
		SBC		_var3
		BCS		loc_61E5F
		EOR		#$FF
		ADC		#$01
loc_61E5F:
		CMP		_var1
		BCS		locret_61E6B
		LDA		_collision_flag
		ORA		#$01
		STA		_collision_flag
locret_61E6B:
		RTS

; =============== S U B R O U T I N E =======================================
_money_prize_collision_test:
		STX		_var0
		STY		_var1
		LDX		#$02
		JSR		_obj_screen_pos_calc
		STX		_var2
		STY		_var3
		JSR		_cur_obj_screen_pos_calc
		TXA
		SEC
		SBC		_var2
		BCS		loc_61E86
		EOR		#$FF
		ADC		#$01
loc_61E86:
		CMP		_var0
		BCS		locret_61EA9
		TYA
		SEC
		SBC		_var3
		BCS		loc_61E94
		EOR		#$FF
		ADC		#$01
loc_61E94:
		CMP		_var1
		BCS		locret_61EA9
		LDX		_scr_cur_trd_idx
		LDA		#$FF
		STA		_scr_trds_idx,X
		LDA		_scr_trds_args2,X
		JSR		_scores_add
		LDA		#$0D
		JSR		_far_prg6_apu_snd_load_safe
locret_61EA9:
		RTS

; =============== S U B R O U T I N E =======================================
_bin2dec:
		STA		_var4
		STX		_var5
		LDX		#$00
loc_61EB0:
		LDY		#$00
loc_61EB2:
		LDA		_var5
		CMP		byte_61EE1,X
		BCC		loc_61ED4
		BNE		loc_61EC2
		LDA		_var4
		CMP		byte_61EDD,X
		BCC		loc_61ED4
loc_61EC2:
		LDA		_var4
		SEC
		SBC		byte_61EDD,X
		STA		_var4
		LDA		_var5
		SBC		byte_61EE1,X
		STA		_var5
		INY
		BNE		loc_61EB2
loc_61ED4:
		TYA
		STA		_var0,X
		INX
		CPX		#$04
		BCC		loc_61EB0
		RTS
byte_61EDD:
		.BYTE	$10,$E8,$64,$0A
byte_61EE1:
		.BYTE	$27,$03,$00,$00

; =============== S U B R O U T I N E =======================================
_print_num99999:
		JSR		_ppu_offset_calc
		LDX		#$00
		STX		_var5
loc_61EEC:
		LDA		_var0,X
		ORA		_var5
		BNE		loc_61EFA
		CPX		#$04
		BEQ		loc_61EFA
		LDA		#$20
		BNE		loc_61F00
loc_61EFA:
		INC		_var5
		LDA		_var0,X
		ORA		#$30
loc_61F00:
		STA		_tmp_buf+4,X
		INX
		CPX		#$05
		BCC		loc_61EEC
		LDA		#$05
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_offset_calc:
		TXA
		AND		#$1F
		STA		_tmp0
		LDA		#$00
		STA		_ptr08+1
		TYA
		ASL
		ASL
		ASL
		ASL
		ROL		_ptr08+1
		ASL
		ROL		_ptr08+1
		ADC		_tmp0
		STA		_ptr08
		TYA
		AND		#$20
		STA		_tmp0
		TXA
		AND		#$20
		LSR
		ORA		_tmp0
		LSR
		LSR
		LSR
		STA		_tmp0
		LDA		_mmc1_ctrl_shadow
		AND		#$01
		ORA		_tmp0
		TAX
		LDA		byte_61F4E,X
		ORA		_ptr08+1
		STA		_ptr08+1
		RTS
byte_61F4E:
		.BYTE	$20,$20,$24,$28,$24,$28,$20,$20

; =============== S U B R O U T I N E =======================================
_ppu_macro_attr_transfer:
		JSR		_ppu_attr_ofs_calc
		STA		_tmp0
		TXA
		PHA
		AND		#$02
		LSR
		STA		_var0
		TYA
		PHA
		AND		#$02
		ORA		_var0
		STA		_var0
		TAX
		LDA		_tmp0
loc_61F6D:
		DEX
		BMI		loc_61F74
		ASL
		ASL
		BCC		loc_61F6D
loc_61F74:
		STA		_tmp0
		LDX		_var0
		LDY		#$00
		LDA		(_ptr06),Y
		AND		byte_61F98,X
		ORA		_tmp0
		STA		(_ptr06),Y
		STA		_tmp_buf+$A
		LDA		#$01
		STA		_tmp_buf+8
		STA		_tmp_buf+9
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+8
		PLA
		TAY
		PLA
		TAX
		RTS
byte_61F98:
		.BYTE	$FC,$F3,$CF,$3F

; =============== S U B R O U T I N E =======================================
_ppu_attr_ofs_calc:
		PHA
		TXA
		PHA
		AND		#$1C
		LSR
		LSR
		STA		_var0
		TYA
		AND		#$20
		STA		_tmp0
		TXA
		AND		#$20
		LSR
		ORA		_tmp0
		LSR
		LSR
		LSR
		STA		_tmp0
		LDA		_mmc1_ctrl_shadow
		AND		#$01
		ORA		_tmp0
		TAX
		TYA
		AND		#$1C
		ASL
		ADC		_var0
		PHA
		ADC		_attrs_pos_list_lo,X
		STA		_ptr08
		LDA		#$00
		ADC		_attrs_pos_list_hi,X
		STA		_ptr08+1
		TXA
		LSR
		TAX
		PLA
		CLC
		ADC		_attr_bufs_list_lo,X
		STA		_ptr06
		LDA		#$00
		ADC		_attr_bufs_list_hi,X
		STA		_ptr06+1
		PLA
		TAX
		PLA
		RTS
_attrs_pos_list_lo:
		.BYTE	$C0,$C0,$C0,$C0,$C0,$C0,$C0,$C0
_attrs_pos_list_hi:
		.BYTE	$23,$23,$27,$2B,$27,$2B,$23,$23
_attr_bufs_list_lo:
		.BYTE	<[_attr_buf_pageA]
		.BYTE	<[_attr_buf_pageB]
		.BYTE	<[_attr_buf_pageB]
		.BYTE	<[_attr_buf_pageA]
_attr_bufs_list_hi:
		.BYTE	>[_attr_buf_pageA]
		.BYTE	>[_attr_buf_pageB]
		.BYTE	>[_attr_buf_pageB]
		.BYTE	>[_attr_buf_pageA]

; =============== S U B R O U T I N E =======================================
sub_61FFC:
		STA		_tmp_buf+4
		LDA		byte_6201B,X
		STA		_tmp_buf
		LDA		byte_6201F,X
		STA		_tmp_buf+1
		LDA		#$20
		STA		_tmp_buf+2
		LDA		#$1E
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_repeat
		.WORD	_tmp_buf
		RTS
byte_6201B:
		.BYTE	$00,$00,$00,$00
byte_6201F:
		.BYTE	$20,$24,$28,$2C

; =============== S U B R O U T I N E =======================================
_ppu_attr_fill_unref:
		STA		_tmp_buf+4
		LDA		_unused_unref,X
		STA		_tmp_buf
		LDA		_unused_unref_0,X
		STA		_tmp_buf+1
		LDA		#$20
		STA		_tmp_buf+2
		LDA		#$02
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_repeat
		.WORD	_tmp_buf
		RTS
_unused_unref:
		.BYTE	$C0,$C0,$C0,$C0
_unused_unref_0:
		.BYTE	$23,$27,$27,$23

; =============== S U B R O U T I N E =======================================
_scroll_page_set:
		PHA
		AND		#$01
		STA		_ppu_scroll_pos_x+1
		PLA
		LSR
		STA		_ppu_scroll_pos_y+1
		LDA		#$00
		STA		_ppu_scroll_pos_x
		STA		_ppu_scroll_pos_y
		RTS

; =============== S U B R O U T I N E =======================================
_unref_6:
		JSR		_wait_for_nmi
		DEX
		BNE		_unref_6
		RTS

; =============== S U B R O U T I N E =======================================
_init_pal_fade_unused:
		LDX		#$07
loc_62063:
		STA		_pal_fade_req_list,X
		DEX
		BPL		loc_62063
		RTS

; =============== S U B R O U T I N E =======================================
_patch_pal_load:
		STA		_ptr06
		STX		_ptr06+1
		TYA
		PHA
		ASL
		ASL
		ADC		#<[_pal_buf]
		STA		_ptr08
		LDA		#$00
		ADC		#>[_pal_buf]
		STA		_ptr08+1
		LDY		#$03
loc_6207D:
		LDA		(_ptr06),Y
		STA		(_ptr08),Y
		DEY
		BPL		loc_6207D
		LDY		#$00
		LDA		(_ptr06),Y
		LDX		#$07
loc_6208A:
		STA		_pal_buf,Y
		INY
		INY
		INY
		INY
		DEX
		BPL		loc_6208A
		PLA
		TAX
		ASL
		ASL
		PHA
		ADC		#<[_pal_buf]
		STA		_ptr06
		LDA		#$00
		ADC		#>[_pal_buf]
		STA		_ptr06+1
		LDY		#$00
		LDA		_pal_fade_req_list,X
		BMI		loc_620D2
		CMP		#$05
		BCC		loc_620AF
		LDA		#$04
loc_620AF:
		TAX
loc_620B0:
		LDA		(_ptr06),Y
		CMP		#$0F
		BNE		loc_620B8
		LDA		#$F0
loc_620B8:
		CLC
		ADC		byte_621B8,X
		CMP		#$F0
		BNE		loc_620C2
		LDA		#$0F
loc_620C2:
		CMP		#$40
		BCC		loc_620C8
		LDA		#$30
loc_620C8:
		STA		_tmp_buf+4,Y
		INY
		CPY		#$04
		BCC		loc_620B0
		BCS		loc_620F0
loc_620D2:
		CMP		#$FC
		BCS		loc_620D8
		LDA		#$FC
loc_620D8:
		EOR		#$FF
		CLC
		ADC		#$01
		TAX
loc_620DE:
		LDA		(_ptr06),Y
		SEC
		SBC		byte_621B8,X
		BCS		loc_620E8
		LDA		#$0F
loc_620E8:
		STA		_tmp_buf+4,Y
		INY
		CPY		#$04
		BCC		loc_620DE
loc_620F0:
		PLA
		CLC
		ADC		#$00
		STA		_tmp_buf
		LDA		#$00
		ADC		#$3F
		STA		_tmp_buf+1
		LDA		#$04
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param
		.WORD	_tmp_buf
		RTS

; =============== S U B R O U T I N E =======================================
_spr_pal_load:
		STA		_ptr06
		STX		_ptr06+1
		LDY		#$0F
loc_62114:
		LDA		(_ptr06),Y
		STA		_pal_buf+$10,Y
		DEY
		BPL		loc_62114
		JMP		_pal_def_color_set

; =============== S U B R O U T I N E =======================================
_bg_pal_load:
		LDY		#$0F
		BNE		_pal_load_ex

; =============== S U B R O U T I N E =======================================
_full_pal_load:
		LDY		#$1F

; =============== S U B R O U T I N E =======================================
_pal_load_ex:
		STA		_ptr06
		STX		_ptr06+1
loc_62129:
		LDA		(_ptr06),Y
		STA		_pal_buf,Y
		DEY
		BPL		loc_62129

; =============== S U B R O U T I N E =======================================
_pal_def_color_set:
		LDY		#$00
		LDA		(_ptr06),Y
		LDX		#$07
loc_62137:
		STA		_pal_buf,Y
		INY
		INY
		INY
		INY
		DEX
		BPL		loc_62137

; =============== S U B R O U T I N E =======================================
_full_pal_fade:
		LDY		#$00
loc_62143:
		TYA
		LSR
		LSR
		TAX
		LDA		_pal_fade_req_list,X
		BMI		loc_6217A
		CMP		#$05
		BCC		loc_62151
		LDA		#$04
loc_62151:
		TAX
loc_62152:
		LDA		_pal_buf,Y
		CMP		#$0F
		BNE		loc_6215B
		LDA		#$F0
loc_6215B:
		CLC
		ADC		byte_621B8,X
		CMP		#$F0
		BNE		loc_62165
		LDA		#$0F
loc_62165:
		CMP		#$40
		BCC		loc_6216B
		LDA		#$30
loc_6216B:
		STA		_tmp_buf+4,Y
		INY
		TYA
		AND		#$03
		BNE		loc_62152
		CPY		#$20
		BCC		loc_62143
		BCS		loc_6219E
loc_6217A:
		CMP		#$FC
		BCS		loc_62180
		LDA		#$FC
loc_62180:
		EOR		#$FF
		CLC
		ADC		#$01
		TAX
loc_62186:
		LDA		_pal_buf,Y
		SEC
		SBC		byte_621B8,X
		BCS		loc_62191
		LDA		#$0F
loc_62191:
		STA		_tmp_buf+4,Y
		INY
		TYA
		AND		#$03
		BNE		loc_62186
		CPY		#$20
		BCC		loc_62143
loc_6219E:
		LDA		#$00
		STA		_tmp_buf
		LDA		#$3F
		STA		_tmp_buf+1
		LDA		#$20
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param
		.WORD	_tmp_buf
		RTS
byte_621B8:
		.BYTE	$00,$10,$20,$30,$40

; =============== S U B R O U T I N E =======================================
sub_621BD:
		CPY		#$02
		BCC		locret_621EB
		DEY
		DEY
		STA		_tmp0
		TXA
		PHA
		LDA		_tmp0
		LDX		byte_621EC,Y
		JSR		_div8
		STX		_tmp1
		PLA
		STA		_tmp0
		LDA		_tmp1
		PHA
		LDA		_tmp0
		LDX		byte_621EC,Y
		JSR		_div8
		STA		_tmp0
		PLA
		CLC
		ADC		_tmp0
		PHA
		TXA
		ADC		#$00
		TAX
		PLA
locret_621EB:
		RTS
byte_621EC:
		.BYTE	$80,$55,$40,$33,$2A,$24,$20,$1C,$19,$17,$15,$13,$12,$11,$10,$0F
		.BYTE	$0E,$0D,$0C,$0C,$0B,$0B,$0A,$0A,$09,$09,$09,$08,$08,$08,$08,$07
		.BYTE	$07,$07,$07,$06,$06,$06,$06,$06,$06,$05,$05,$05,$05,$05,$05,$05
		.BYTE	$05,$05,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01

; =============== S U B R O U T I N E =======================================
_rand:
		STA		_tmp0
		TXA
		PHA
		LDA		_tmp0
		PHA
		LDA		_random_seed
		LDX		#$0B
loc_622F5:
		ASL			_random_seed
		ROL		_random_seed+1
		ROL
		ROL
		EOR		_random_seed
		ROL
		EOR		_random_seed
		LSR
		LSR
		EOR		#$FF
		AND		#$01
		ORA		_random_seed
		STA		_random_seed
		DEX
		BNE		loc_622F5
		TAX
		PLA
		BEQ		loc_62314
		JSR		_div8
loc_62314:
		STX		_tmp1
		PLA
		TAX
		LDA		_tmp1
		RTS

; =============== S U B R O U T I N E =======================================
_div8:
		STA		_tmp0
		STX		_tmp1
		STX		_var0
		AND		_tmp1
		AND		#$01
		STA		_var1
		LDX		_tmp0
		LDA		_div_tbl0,X
		STA		_var2
		CLC
		LDA		_var1
		ADC		_div_tbl1,X
		LDX		_tmp1
		ADC		_div_tbl1,X
		STA		_var1
		LDA		_var2
		ADC		_div_tbl0,X
		STA		_var2
		LDA		_tmp0
		CMP		_tmp1
		BCS		loc_6234C
		STA		_var0
		LDA		_tmp1
loc_6234C:
		SEC
		SBC		_var0
		TAX
		LDA		_var1
		SBC		_div_tbl1,X
		STA		_tmp0
		LDA		_var2
		SBC		_div_tbl0,X
		TAX
		LDA		_tmp0
		RTS
_div_tbl1:
		.BYTE	$00,$00,$02,$04,$08,$0C,$12,$18,$20,$28,$32,$3C,$48,$54,$62,$70
		.BYTE	$80,$90,$A2,$B4,$C8,$DC,$F2,$08,$20,$38,$52,$6C,$88,$A4,$C2,$E0
		.BYTE	$00,$20,$42,$64,$88,$AC,$D2,$F8,$20,$48,$72,$9C,$C8,$F4,$22,$50
		.BYTE	$80,$B0,$E2,$14,$48,$7C,$B2,$E8,$20,$58,$92,$CC,$08,$44,$82,$C0
		.BYTE	$00,$40,$82,$C4,$08,$4C,$92,$D8,$20,$68,$B2,$FC,$48,$94,$E2,$30
		.BYTE	$80,$D0,$22,$74,$C8,$1C,$72,$C8,$20,$78,$D2,$2C,$88,$E4,$42,$A0
		.BYTE	$00,$60,$C2,$24,$88,$EC,$52,$B8,$20,$88,$F2,$5C,$C8,$34,$A2,$10
		.BYTE	$80,$F0,$62,$D4,$48,$BC,$32,$A8,$20,$98,$12,$8C,$08,$84,$02,$80
		.BYTE	$00,$80,$02,$84,$08,$8C,$12,$98,$20,$A8,$32,$BC,$48,$D4,$62,$F0
		.BYTE	$80,$10,$A2,$34,$C8,$5C,$F2,$88,$20,$B8,$52,$EC,$88,$24,$C2,$60
		.BYTE	$00,$A0,$42,$E4,$88,$2C,$D2,$78,$20,$C8,$72,$1C,$C8,$74,$22,$D0
		.BYTE	$80,$30,$E2,$94,$48,$FC,$B2,$68,$20,$D8,$92,$4C,$08,$C4,$82,$40
		.BYTE	$00,$C0,$82,$44,$08,$CC,$92,$58,$20,$E8,$B2,$7C,$48,$14,$E2,$B0
		.BYTE	$80,$50,$22,$F4,$C8,$9C,$72,$48,$20,$F8,$D2,$AC,$88,$64,$42,$20
		.BYTE	$00,$E0,$C2,$A4,$88,$6C,$52,$38,$20,$08,$F2,$DC,$C8,$B4,$A2,$90
		.BYTE	$80,$70,$62,$54,$48,$3C,$32,$28,$20,$18,$12,$0C,$08,$04,$02,$00
_div_tbl0:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$03,$03,$03,$03,$03,$03,$04,$04
		.BYTE	$04,$04,$04,$05,$05,$05,$05,$05,$06,$06,$06,$06,$07,$07,$07,$07
		.BYTE	$08,$08,$08,$08,$09,$09,$09,$09,$0A,$0A,$0A,$0A,$0B,$0B,$0B,$0C
		.BYTE	$0C,$0C,$0D,$0D,$0D,$0E,$0E,$0E,$0F,$0F,$0F,$10,$10,$10,$11,$11
		.BYTE	$12,$12,$12,$13,$13,$13,$14,$14,$15,$15,$15,$16,$16,$17,$17,$18
		.BYTE	$18,$18,$19,$19,$1A,$1A,$1B,$1B,$1C,$1C,$1D,$1D,$1E,$1E,$1F,$1F
		.BYTE	$20,$20,$21,$21,$22,$22,$23,$23,$24,$24,$25,$25,$26,$26,$27,$27
		.BYTE	$28,$29,$29,$2A,$2A,$2B,$2B,$2C,$2D,$2D,$2E,$2E,$2F,$30,$30,$31
		.BYTE	$32,$32,$33,$33,$34,$35,$35,$36,$37,$37,$38,$39,$39,$3A,$3B,$3B
		.BYTE	$3C,$3D,$3D,$3E,$3F,$3F,$40,$41,$42,$42,$43,$44,$45,$45,$46,$47
		.BYTE	$48,$48,$49,$4A,$4B,$4B,$4C,$4D,$4E,$4E,$4F,$50,$51,$52,$52,$53
		.BYTE	$54,$55,$56,$56,$57,$58,$59,$5A,$5B,$5B,$5C,$5D,$5E,$5F,$60,$61
		.BYTE	$62,$62,$63,$64,$65,$66,$67,$68,$69,$6A,$6A,$6B,$6C,$6D,$6E,$6F
		.BYTE	$70,$71,$72,$73,$74,$75,$76,$77,$78,$79,$7A,$7B,$7C,$7D,$7E,$7F

; =============== S U B R O U T I N E =======================================
_nsub_prize_sequence_test:
		LDA		_prg_cur_bank
		PHA
		LDA		#$01
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDY		#$00
		LDA		(_room_prize_sequence_ptr),Y
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_idx,X
		BNE		loc_62583
		INC		_room_prize_sequence_ptr
		BNE		loc_6257B
		INC		_room_prize_sequence_ptr+1
loc_6257B:
		LDA		(_room_prize_sequence_ptr),Y
		BNE		loc_62583
		STA		_room_prize_sequence_ptr
		STA		_room_prize_sequence_ptr+1
loc_62583:
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
_nsub_scores_add_obj_value:
		LDA		_scores_obj_value

; =============== S U B R O U T I N E =======================================
_scores_add:
		CLC
		ADC		_scores
		STA		_scores
		BCC		loc_62598
		INC		_scores+1
loc_62598:
		LDA		_scores+1
		CMP		_scores_to_next_live+1
		BCC		loc_625DF
		BNE		loc_625AA
		LDA		_scores
		CMP		_scores_to_next_live
		BCC		loc_625DF
loc_625AA:
		LDA		_scores_to_next_live+1
		CMP		_scores_to_next_live_max+1
		BNE		loc_625C3
		LDA		_scores_to_next_live
		CMP		_scores_to_next_live_max
		BNE		loc_625C3
		LDY		_scores_to_next_live_step
		LDA		_scores_to_next_live_step+1
		JMP		loc_625D1
loc_625C3:
		LDA		_scores_to_next_live
		CLC
		ADC		_scores_to_next_live_step
		TAY
		LDA		_scores_to_next_live+1
		ADC		_scores_to_next_live_step+1
loc_625D1:
		STY		_scores_to_next_live
		STA		_scores_to_next_live+1
		INC		_lives
		LDA		#$1E
		JSR		_far_prg6_apu_snd_load_safe
loc_625DF:
		LDA		_scores+1
		CMP		_hi_scores+1
		BCC		locret_625FD
		BNE		loc_625F1
		LDA		_scores
		CMP		_hi_scores
		BCC		locret_625FD
loc_625F1:
		LDA		_scores
		STA		_hi_scores
		LDA		_scores+1
		STA		_hi_scores+1
locret_625FD:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_scores_display_unref:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		JMP		_printf_scores_ex

; =============== S U B R O U T I N E =======================================
_printf_scores:
		TXA
		PHA
		TYA
		PHA

; =============== S U B R O U T I N E =======================================
_printf_scores_ex:
		LDA		_scores
		LDX		_scores+1
		JSR		_bin2dec
		PLA
		TAY
		PLA
		TAX
		JMP		_print_num99999

; =============== S U B R O U T I N E =======================================
_nsub_hi_scores_display:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		JMP		_printf_hi_scores_ex

; =============== S U B R O U T I N E =======================================
_printf_hi_scores:
		TXA
		PHA
		TYA
		PHA

; =============== S U B R O U T I N E =======================================
_printf_hi_scores_ex:
		LDA		_hi_scores
		LDX		_hi_scores+1
		JSR		_bin2dec
		PLA
		TAY
		PLA
		TAX
		JMP		_print_num99999

; =============== S U B R O U T I N E =======================================
_nsub_apu_mus_load:
		JSR		_scr_getc

; =============== S U B R O U T I N E =======================================
_far_prg6_apu_mus_load:
		STA		_apu_req_idx

; =============== S U B R O U T I N E =======================================
_far_prg6_apu_mus_load_ex:
		STA		_tmp0
		LDA		_prg_cur_bank
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_apu_mus_load
		PLA
		TAY
		PLA
		TAX
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
_nsub_apu_snd_load_safe:
		JSR		_scr_getc

; =============== S U B R O U T I N E =======================================
_far_prg6_apu_snd_load_safe:
		STA		_tmp0
		LDA		_prg_cur_bank
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_apu_snd_load_safe
		PLA
		TAY
		PLA
		TAX
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
_nsub_full_pal_fade_set:
		JSR		_scr_getc
		LDY		#$07
loc_62688:
		STA		_pal_fade_req_list,Y
		DEY
		BPL		loc_62688
		JMP		_full_pal_fade

; =============== S U B R O U T I N E =======================================
_nsub_pal_fade_req_inc_by_mask:
		JSR		_scr_getc
		STA		_var0
		LDX		#$07
loc_62698:
		LSR		_var0
		BCC		loc_6269E
		INC		_pal_fade_req_list,X
loc_6269E:
		DEX
		BPL		loc_62698
		JMP		_full_pal_fade

; =============== S U B R O U T I N E =======================================
_nsub_pal_fade_req_dec_by_mask:
		JSR		_scr_getc
		STA		_var0
		LDX		#$07
loc_626AB:
		LSR		_var0
		BCC		loc_626B1
		DEC		_pal_fade_req_list,X
loc_626B1:
		DEX
		BPL		loc_626AB
		JMP		_full_pal_fade

; =============== S U B R O U T I N E =======================================
_nsub_patch_pal_load:
		JSR		_scr_getc	; -> Y
		PHA
		JSR		_scr_getc	; -> tmp0
		PHA
		JSR		_scr_getc	; -> X
		TAX
		PLA
		STA		_tmp0
		PLA
		TAY
		LDA		_tmp0
		JMP		_patch_pal_load

; =============== S U B R O U T I N E =======================================
_nsub_bg_pal_load:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAX
		PLA
		JMP		_bg_pal_load

; =============== S U B R O U T I N E =======================================
_nsub_spr_pal_load:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAX
		PLA
		JMP		_spr_pal_load

; =============== S U B R O U T I N E =======================================
_nsub_full_pal_load:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAX
		PLA
		JMP		_full_pal_load

; =============== S U B R O U T I N E =======================================
_nsub_626F1:
		JSR		_scr_getc
		TAX
		LDA		#$FF
		STA		_scr_trds_idx,X
		RTS

; =============== S U B R O U T I N E =======================================
; arg2
_nsub_trd_scr_disable_unref:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		STA		_tmp0
		PLA
		ASL
		ADC		_tmp0
		ASL
		TAX
		LDA		#$00
		STA		_scr_trds_ptr+1,X
		RTS

; =============== S U B R O U T I N E =======================================
; TODO: this is ending scenario only routine, why they put it here, unknown
;
_nsub_obj_delay_set_from_sarg:
		JSR		_scr_getc
		TAX
		LDA		_scr_args_list_ptr_lo,X
		STA		_ptr06
		LDA		_scr_args_list_ptr_hi,X
		STA		_ptr06+1
		LDY		_scr_cur_trd_idx
		LDA		(_ptr06),Y
		LDX		_scr_cur_trd_idxw
		STA		_scr_trds_delay,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_cur_obj_rand_delay_set_unref:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		JSR		_rand
		TAX
		PLA
		JSR		_div8
		LDX		_scr_cur_trd_idxw
		STA		_scr_trds_delay,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_6273D:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		TAY
		LSR
		LDX		_scr_cur_trd_idx
		CLC
		ADC		_scr_trds_args1,X
		LDX		#$00
		JSR		sub_621BD
		STA		_var0
		PLA
		CLC
		ADC		_var0
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_spr_idx,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_far_prg0_tlm_lib_unpack:
		JSR		_scr_getc

; =============== S U B R O U T I N E =======================================
_far_prg0_tlm_lib_unpack:
		STA		_tmp0
		LDA		_prg_cur_bank
		PHA
		LDA		#$00
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		LDA		_tmp0
		JSR		_tlm_lib_unpack
		PLA
		STA		_prg_cur_bank
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
_nsub_scroll_page_set:
		JSR		_scr_getc
		JMP		_scroll_page_set

; =============== S U B R O U T I N E =======================================
_nsub_mmc1_mirror_horizontal:
		LDA		#$1E
		JMP		_mmc1_ctrl

; =============== S U B R O U T I N E =======================================
_nsub_mmc1_mirror_vertical:
		LDA		#$1E
		ORA		#$01
		JMP		_mmc1_ctrl

; =============== S U B R O U T I N E =======================================
_nsub_mmc1_chr0_set:
		JSR		_scr_getc
		STA		_chr_bank0
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_mmc1_chr1_set:
		JSR		_scr_getc

; =============== S U B R O U T I N E =======================================
_mmc1_chr1_set:
		STA		_chr_bank1
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_mmc1_prg_set_unused:
		JSR		_scr_getc
		JMP		_mmc1_prg_safe

; =============== S U B R O U T I N E =======================================
_nsub_new_thread_start:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		PHA
		LDA		#$00
		STA		_var6
		STA		_var7
		JSR		_scr_getc
		STA		_tmp1
		BPL		loc_627AE
		DEC		_var6
loc_627AE:
		JSR		_scr_getc
		STA		_tmp2
		BPL		loc_627B7
		DEC		_var7
loc_627B7:
		JSR		_scr_getc
		STA		_var0
		JSR		_scr_getc
		CLC
		ADC		_scr_trds_args1,X
		STA		_var1
		LDA		_scr_trds_y_pos_lo,X
		CLC
		ADC		_tmp2
		TAY
		LDA		_scr_trds_y_pos_hi,X
		ADC		_var7
		STA		_tmp_var1
		LDA		_scr_trds_x_pos_lo,X
		CLC
		ADC		_tmp1
		PHA
		LDA		_scr_trds_x_pos_hi,X
		ADC		_var6
		STA		_tmp_var0
		PLA
		TAX
		PLA
		JSR		_thread_lib_load_gen_ex
		TXA
		LSR
		LSR
		TAX
		LDA		_scr_cur_trd_idx
		STA		_scr_trds_args2,X
		TXA
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_sarg01_load_data_ofs:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_args0,X
		JSR		_scr_getc
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
; get the pointer to chain data in current thread's ARG0/ARG1 parameters,
; reload given thread with the same lib idx as a new scripts with selected
; arguments from data, also get the position and delays there.
; so this routine will create a number of copies of the current thread with
; predefined parameters.
;
_nsub_chain_thread_lib_load_enemy:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		STA		_ptr06
		LDA		_scr_trds_args1,X
		STA		_ptr06+1
		LDA		#$00
		STA		_var4
		STA		_var5
		TAY
		LDA		(_ptr06),Y
		STA		_var0
		INY
		LDA		(_ptr06),Y
		STA		_tmp1
		BPL		loc_62819
		DEC		_var4
loc_62819:
		INY
		LDA		(_ptr06),Y
		STA		_tmp2
		BPL		loc_62822
		DEC		_var5
loc_62822:
		INY
		LDA		(_ptr06),Y
		LDX		_scr_cur_trd_idxw
		STA		_scr_trds_delay,X
		LDX		_scr_cur_trd_idx
		INY
		TYA
		CLC
		ADC		_ptr06
		STA		_scr_trds_args0,X
		LDA		_ptr06+1
		ADC		#$00
		STA		_scr_trds_args1,X
		LDA		_scr_trds_idx,X
		PHA
		LDA		_scr_trds_y_pos_lo,X
		CLC
		ADC		_tmp2
		TAY
		LDA		_scr_trds_y_pos_hi,X
		ADC		_var5
		STA		_tmp_var1
		LDA		_scr_trds_x_pos_lo,X
		CLC
		ADC		_tmp1
		PHA
		LDA		_scr_trds_x_pos_hi,X
		ADC		_var4
		STA		_tmp_var0
		PLA
		TAX
		PLA
		JMP		_thread_lib_load_gen_ex

; =============== S U B R O U T I N E =======================================
_nsub_obj_sarg_add_imm_test:
		JSR		_scr_getc
		TAX
		LDA		_scr_args_list_ptr_lo,X
		STA		_ptr06
		LDA		_scr_args_list_ptr_hi,X
		STA		_ptr06+1
		JSR		_scr_getc
		LDY		_scr_cur_trd_idx
		CLC
		ADC		(_ptr06),Y
		BMI		loc_62877
		CLC
		RTS
loc_62877:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62879:
		JSR		_scr_getc
		JSR		_rand
		BEQ		loc_62883
		CLC
		RTS
loc_62883:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_lvl_data_ptrs_load:
		JSR		_scr_getc
		STA		_lvl_macroA_ptr
		JSR		_scr_getc
		STA		_lvl_macroA_ptr+1
		JSR		_scr_getc
		STA		_lvl_macroB_ptr
		JSR		_scr_getc
		STA		_lvl_macroB_ptr+1
		JSR		_scr_getc
		STA		_lvl_macroC_ptr
		JSR		_scr_getc
		STA		_lvl_macroC_ptr+1
		JSR		_scr_getc
		STA		_lvl_macroD_ptr
		JSR		_scr_getc
		STA		_lvl_macroD_ptr+1
		JSR		_scr_getc
		STA		_lvl_attrs_ptr
		JSR		_scr_getc
		STA		_lvl_attrs_ptr+1
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_room_page_set_unref:
		JSR		_scr_getc
		STA		_cur_room_x_pageA
		JSR		_scr_getc
		STA		_cur_room_x_pageB
		JSR		_scr_getc
		STA		_cur_room_y_pageB
		JSR		_scr_getc
		STA		_cur_room_y_pageA
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_628D1:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		LDX		_scr_cur_trd_idx
		LDY		_scr_trds_args1,X
		PLA
		TAX
		PLA
		JSR		sub_61ACB
		LDX		_scr_cur_trd_idx
		LDA		_ptr06
		STA		_scr_trds_x_move_speed,X
		LDA		_ptr06+1
		STA		_scr_trds_x_move_delta,X
		LDA		_ptr08
		STA		_scr_trds_y_move_speed,X
		LDA		_ptr08+1
		STA		_scr_trds_y_mov_delta,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_room_draw:
		JSR		_scr_getc
		STA		_cur_room_orientation_idx
		JSR		_scr_getc
		STA		_cur_room_data_col
		JSR		_scr_getc
		STA		_cur_room_data_row

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_room_draw:
		JSR		_ppu_vblank_off
		LDA		_cur_room_orientation_idx
		ORA		#$1E
		JSR		_mmc1_ctrl
		LDA		_cur_room_data_col
		STA		_tmp_var0
		STA		_cur_room_y_pageB
		STA		_cur_room_y_pageA
		LDA		_cur_room_data_row
		STA		_tmp_var1
		STA		_cur_room_x_pageA
		STA		_cur_room_x_pageB
		JSR		sub_619F7
		LDA		_cur_room_orientation_idx
		BNE		loc_6293C
		INC		_cur_room_y_pageA
		INC		_tmp_var0
		BNE		loc_62945
loc_6293C:
		CMP		#$01
		BNE		loc_62948
		INC		_cur_room_x_pageB
		INC		_tmp_var1
loc_62945:
		JSR		sub_619F7
loc_62948:
		JMP		_ppu_vblank_on

; =============== S U B R O U T I N E =======================================
_nsub_players_room_exit_test:
		JSR		_scr_getc
		STA		_var0
		LDA		#$00
		STA		_var3
loc_62954:
		LDX		#$02
		JSR		_scr_getc
		SEC
		SBC		_scr_trds_x_pos_lo+2
		STA		_var1
		JSR		_scr_getc
		SBC		_scr_trds_x_pos_hi+2
		STA		_var2
		BCS		loc_62976
		LDA		_var1
		EOR		#$FF
		ADC		#$01
		STA		_var1
		LDA		_var2
		EOR		#$FF
		ADC		#$00
loc_62976:
		BNE		loc_629A8
		LDA		_var1
		CMP		#$11
		BCS		loc_629A8
		DEX
		DEX
		JSR		_scr_getc
		SEC
		SBC		_scr_trds_y_pos_lo+2
		STA		_var1
		JSR		_scr_getc
		SBC		_scr_trds_y_pos_hi+2
		STA		_var2
		BCS		loc_629A0
		LDA		_var1
		EOR		#$FF
		ADC		#$01
		STA		_var1
		LDA		_var2
		EOR		#$FF
		ADC		#$00
loc_629A0:
		BNE		loc_629A8
		LDA		_var1
		CMP		#$11
		BCC		loc_629BA
loc_629A8:
		TXA
		CLC
		ADC		_scr_pc
		STA		_scr_pc
		BCC		loc_629B2
		INC		_scr_pc+1
loc_629B2:
		INC		_var3
		DEC		_var0
		BNE		loc_62954
		CLC
		RTS
loc_629BA:
		DEC		_var0
		LDA		_var0
		ASL
		ASL
		ADC		_scr_pc
		STA		_scr_pc
		BCC		loc_629C8
		INC		_scr_pc+1
loc_629C8:
		LDA		_var3
		STA		_tmp_idx
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_players_room_start_pos_init:
		JSR		_scr_getc
		PHA
		LDA		_tmp_idx
		ASL
		ADC		_tmp_idx
		TAY
		INY
		LDA		#$00
		STA		_scr_trds_x_pos_hi+2
		STA		_scr_trds_y_pos_hi+2
		LDA		(_scr_pc),Y
		ASL
		ROL		_scr_trds_x_pos_hi+2
		ASL
		ROL		_scr_trds_x_pos_hi+2
		ASL
		ROL		_scr_trds_x_pos_hi+2
		STA		_scr_trds_x_pos_lo+2
		INY
		LDA		(_scr_pc),Y
		ASL
		ROL		_scr_trds_y_pos_hi+2
		ASL
		ROL		_scr_trds_y_pos_hi+2
		ASL
		ROL		_scr_trds_y_pos_hi+2
		STA		_scr_trds_y_pos_lo+2
		INY
		LDA		(_scr_pc),Y
		TAX
		LSR
		ROR
		ROR
		STA		_scr_trds_args1+2
		STA		_scr_trds_args1+4
		LDA		_scr_trds_x_pos_lo+2
		CLC
		ADC		byte_62A87,X
		STA		_scr_trds_x_pos_lo+2
		LDA		_scr_trds_x_pos_hi+2
		ADC		byte_62A8B,X
		STA		_scr_trds_x_pos_hi+2
		STA		_ppu_scroll_pos_x+1
		LDA		_scr_trds_y_pos_lo+2
		CLC
		ADC		byte_62A8F,X
		STA		_scr_trds_y_pos_lo+2
		LDA		_scr_trds_y_pos_hi+2
		ADC		byte_62A93,X
		STA		_scr_trds_y_pos_hi+2
		STA		_ppu_scroll_pos_y+1
		LDA		_scr_trds_x_pos_lo+2
		CLC
		ADC		byte_62A97,X
		STA		_scr_trds_x_pos_lo+4
		LDA		_scr_trds_x_pos_hi+2
		ADC		byte_62A9B,X
		STA		_scr_trds_x_pos_hi+4
		LDA		_scr_trds_y_pos_lo+2
		CLC
		ADC		byte_62A9F,X
		STA		_scr_trds_y_pos_lo+4
		LDA		_scr_trds_y_pos_hi+2
		ADC		byte_62AA3,X
		STA		_scr_trds_y_pos_hi+4
		LDA		_scr_trds_args1+2
		ASL
		ROL
		ROL
		ASL
		ASL
		ADC		_beamer_idxA
		STA		_scr_trds_spr_idx+2
		LDA		_scr_trds_args1+4
		ASL
		ROL
		ROL
		ASL
		ASL
		ADC		_catcher_idxA
		STA		_scr_trds_spr_idx+4
		PLA
		STA		_tmp0
		ASL
		ADC		_tmp0
		ADC		_scr_pc
		STA		_scr_pc
		BCC		loc_62A7E
		INC		_scr_pc+1
loc_62A7E:
		LDA		#$00
		STA		_ppu_scroll_pos_x
		STA		_ppu_scroll_pos_y
		JMP		_nsub_gen_threads_off_except_cur
byte_62A87:
		.BYTE	$10,$10,$10,$F8
byte_62A8B:
		.BYTE	$00,$00,$00,$FF
byte_62A8F:
		.BYTE	$00,$18,$20,$18
byte_62A93:
		.BYTE	$00,$00,$00,$00
byte_62A97:
		.BYTE	$00,$F0,$00,$10
byte_62A9B:
		.BYTE	$00,$FF,$00,$00
byte_62A9F:
		.BYTE	$18,$00,$E8,$00
byte_62AA3:
		.BYTE	$00,$00,$FF,$00

; =============== S U B R O U T I N E =======================================
_nsub_read_mem:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_get_checkpoint_tmp_idx:
		LDX		_lvl_last_checkpoint_idx
		DEX
		STX		_tmp_idx
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62ABE:
		JSR		sub_61AA1
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
_unref_12:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		JSR		sub_61AA1
		PLA
		TAX
		PLA
		JSR		sub_61ACB
		LDX		_scr_cur_trd_idx
		LDA		_ptr06
		STA		_scr_trds_x_move_speed,X
		LDA		_ptr06+1
		STA		_scr_trds_x_move_delta,X
		LDA		_ptr08
		STA		_scr_trds_y_move_speed,X
		LDA		_ptr08+1
		STA		_scr_trds_y_mov_delta,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62AEC:
		JSR		_scr_getc
		PHA
		PHA
		JSR		sub_61AA1
		STA		_tmp0
		PLA
		STA		_var1
		SEC
		SBC		#$01
		EOR		#$FF
		STA		_var0
		PLA
		LSR
		CLC
		ADC		_tmp0
		AND		_var0
		SEC
		SBC		_scr_trds_args1,X
		BEQ		locret_62B1D
		BMI		loc_62B16
		LDA		_scr_trds_args1,X
		CLC
		ADC		_var1
		JMP		loc_62B1B
loc_62B16:
		LDA		_scr_trds_args1,X
		SEC
		SBC		_var1
loc_62B1B:
		STA		_scr_trds_args1,X
locret_62B1D:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62B1E:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		TAY
		INY
		JMP		sub_61C5E

; =============== S U B R O U T I N E =======================================
_nsub_obj_spr_idx_set_from_sarg:
		JSR		_scr_getc
		TAX
		LDA		_scr_args_list_ptr_lo,X
		STA		_ptr06
		LDA		_scr_args_list_ptr_hi,X
		STA		_ptr06+1
		LDY		_scr_cur_trd_idx
		LDA		(_ptr06),Y
		STA		_scr_trds_spr_idx,Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_all_threads_off_except_cur:
		LDX		#$0D
		LDA		#$FF
loc_62B44:
		CPX		_scr_cur_trd_idx
		BEQ		loc_62B4B
		STA		_scr_trds_idx,X
loc_62B4B:
		DEX
		BPL		loc_62B44
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_gen_threads_off_except_cur:
		LDX		#$06
		LDA		#$FF
loc_62B53:
		CPX		_scr_cur_trd_idx
		BEQ		loc_62B5A
		STA		_scr_trds_idx,X
loc_62B5A:
		INX
		CPX		#$0E
		BCC		loc_62B53
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_cur_pos_x_lo_icmp:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_x_pos_lo,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_cur_pos_y_lo_icmp:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CMP		_scr_trds_y_pos_lo,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_mtest_bit0:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		LDA		(_ptr06),Y
		LSR
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_mcmp:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_scr_getc
		STA		_tmp0
		LDA		(_ptr06),Y
		CMP		_tmp0
		BEQ		locret_62B94
		CLC
locret_62B94:
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62B95:
		LDA		_lvl_objects_ptr+1
		BNE		locret_62BB0
		LDX		#$06
loc_62B9B:
		LDA		_scr_trds_idx,X
		BMI		loc_62BA4
		CPX		_scr_cur_trd_idx
		BNE		locret_62BB0
loc_62BA4:
		INX
		CPX		#$0E
		BCC		loc_62B9B
_nsub_62BA9:
		LDX		#$00
		JSR		_thread_reload_param_ex
		.WORD	_scr_stage_complete
locret_62BB0:
		RTS

; =============== S U B R O U T I N E =======================================
; NOTE: this routine used only for "STAGE CLEAR" sprite position set
; only once in all scripts, but still using the parametric positions.
; seems they used this routine before as part of scripting library
; but now its usage seems very redundant.
;
_nsub_obj_screen_pos_set:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_pos_x
		STA		_scr_trds_x_pos_lo,X
		LDA		_ppu_scroll_pos_x+1
		ADC		#$00
		STA		_scr_trds_x_pos_hi,X
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_pos_y
		STA		_scr_trds_y_pos_lo,X
		LDA		_ppu_scroll_pos_y+1
		STA		_scr_trds_y_pos_hi,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_obj_sarg_set_from_nsub_return_value:
		JSR		_scr_getc
		TAX
		LDA		_scr_args_list_ptr_lo,X
		STA		_ptr06
		LDA		_scr_args_list_ptr_hi,X
		STA		_ptr06+1
		LDY		_scr_cur_trd_idx
		LDA		_nsub_return_value
		STA		(_ptr06),Y
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62BE5:
		LDX		#$06
loc_62BE7:
		LDA		_scr_trds_idx,X
		BMI		loc_62BF4
		CMP		#$13
		BCC		loc_62BF4
		CPX		_scr_cur_trd_idx
		BNE		loc_62BFB
loc_62BF4:
		INX
		CPX		#$0E
		BCC		loc_62BE7
		SEC
		RTS
loc_62BFB:
		CLC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62BFD:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BEQ		loc_62C09
		CMP		#$03
		BEQ		loc_62C09
		CLC
		RTS
loc_62C09:
		SEC
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62C0B:
		LDY		#$00
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_args0,X
		BPL		loc_62C18
		INY
		LSR
		BCC		loc_62C18
		INY
loc_62C18:
		LDA		#$00
		STA		_scr_trds_args0,X
		TYA
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_beamer_handler_start:
		JSR		sub_62C2E
		LDA		#$02
		STA		_var4
		LDA		#$03
		STA		_var5
		LDA		#$08
		JMP		_thread_lib_load

; =============== S U B R O U T I N E =======================================
sub_62C2E:
		LDA		#$00
		STA		_var1
		STA		_tmp_var0
		STA		_tmp_var1
		TAY
		TAX
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_catcher_handler_start:
		JSR		sub_62C2E
		LDA		#$04
		STA		_var4
		LDA		#$05
		STA		_var5
		LDA		#$0A
		JMP		_thread_lib_load

; =============== S U B R O U T I N E =======================================
_nsub_62C49:
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_lo,Y
		AND		#$07
		CMP		#$04
		BNE		loc_62C6A
		TXA
		PHA
		LDX		#$00
		LDA		_scr_trds_args1,Y
		BMI		loc_62C5E
		INX
loc_62C5E:
		LDA		off_62C6C,X
		LDY		off_62C6E,X
		JSR		_obj_to_room_bound_box_collision_test
		PLA
		TAX
		RTS
loc_62C6A:
		CLC
		RTS
off_62C6C:
		.BYTE	<[byte_62C70]
		.BYTE	<[byte_62C75]
off_62C6E:
		.BYTE	>[byte_62C70]
		.BYTE	>[byte_62C75]
byte_62C70:
		.BYTE	$02
		.BYTE	$FB,$FB
		.BYTE	$FB,$04
byte_62C75:
		.BYTE	$02
		.BYTE	$04,$FB
		.BYTE	$04,$04

; =============== S U B R O U T I N E =======================================
_nsub_62C7A:
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_y_pos_lo,Y
		AND		#$07
		CMP		#$04
		BNE		loc_62CA0
		TXA
		PHA
		LDX		#$00
		LDY		_scr_cur_trd_idx
		LDA		_scr_trds_args1,Y
		CLC
		ADC		#$40
		BPL		loc_62C94
		INX
loc_62C94:
		LDA		off_62CA2,X
		LDY		off_62CA4,X
		JSR		_obj_to_room_bound_box_collision_test
		PLA
		TAX
		RTS
loc_62CA0:
		CLC
		RTS
off_62CA2:
		.BYTE	<[byte_62CA6]
		.BYTE	<[byte_62CAB]
off_62CA4:
		.BYTE	>[byte_62CA6]
		.BYTE	>[byte_62CAB]
byte_62CA6:
		.BYTE	$02
		.BYTE	$FB,$FB
		.BYTE	$04,$FB
byte_62CAB:
		.BYTE	$02
		.BYTE	$FB,$04
		.BYTE	$04,$04

; =============== S U B R O U T I N E =======================================
_nsub_62CB0:
		LDX		_scr_cur_trd_idx
		LDA		#$00
		SEC
		SBC		_scr_trds_args1,X
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62CBA:
		LDX		_scr_cur_trd_idx
		LDA		#$80
		SEC
		SBC		_scr_trds_args1,X
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62CC4:
		LDA		#$02
		JSR		sub_61AB9
		CLC
		ADC		#$20
		AND		#$C0
		LDX		_scr_cur_trd_idx
		STA		_scr_trds_args1,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_62CD3:
		JSR		_nsub_604CD
		TAX
		LDA		off_62CE0,X
		LDY		off_62CE4,X
		JMP		_obj_to_room_bound_box_collision_test
off_62CE0:
		.BYTE	<[byte_62CA6]
		.BYTE	<[byte_62C75]
		.BYTE	<[byte_62CAB]
		.BYTE	<[byte_62C70]
off_62CE4:
		.BYTE	>[byte_62CA6]
		.BYTE	>[byte_62C75]
		.BYTE	>[byte_62CAB]
		.BYTE	>[byte_62C70]

; =============== S U B R O U T I N E =======================================
_nsub_62CE8:
		LDX		_scr_cur_trd_idx
		LDA		#$80
		STA		_scr_trds_x_move_clk,X
		STA		_scr_trds_y_move_clk,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_players_scr_suspend:
		LDX		#$02						; suspend player's scripts
		LDA		_scr_trds_spr_idx,X			; but keed it's current sprite idxes
		PHA
		JSR		_thread_reload_param_ex
		.WORD	_scr_suspend
		PLA
		LDX		#$02
		STA		_scr_trds_spr_idx,X
		LDX		#$04
		LDA		_scr_trds_spr_idx,X
		PHA
		JSR		_thread_reload_param_ex
		.WORD	_scr_suspend
		PLA
		LDX		#$04
		STA		_scr_trds_spr_idx,X
		RTS

; =============== S U B R O U T I N E =======================================
_nsub_tlm_raw_arg2_idx_line_draw:
		JSR		_scr_getc
		STA		_ptr08
		JSR		_scr_getc
		STA		_ptr08+1
		LDX		_scr_cur_trd_idx
		LDA		#$00
		STA		_ptr06+1
		LDA		_scr_trds_args2,X
		ASL
		ASL
		ASL
		STA		_ptr06
		ASL
		ROL		_ptr06+1
		ADC		_ptr06
		BCC		loc_62D32
		INC		_ptr06+1
loc_62D32:
		CLC
		ADC		_ptr08
		STA		_ptr06
		LDA		_ptr06+1
		ADC		_ptr08+1
		STA		_ptr06+1
		LDY		#$17
loc_62D3F:
		LDA		(_ptr06),Y
		STA		_tmp_buf+4,Y
		DEY
		BPL		loc_62D3F
		LDY		_scr_trds_args2,X
		INC		_scr_trds_args2,X
		INY
		INY
		LDX		#$04
		JSR		_ppu_offset_calc
		LDA		#$18
		STA		_tmp_buf+2
		LDA		#$01
		STA		_tmp_buf+3
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		RTS

; =============== S U B R O U T I N E =======================================
_cur_obj_out_of_screen_test:
		JSR		_cur_obj_screen_pos_calc
		CPX		#$04
		BCC		loc_62D76
		CPX		#$F8
		BCS		loc_62D76
		CPY		#$04
		BCC		loc_62D76
		CPY		#$E8
		BCS		loc_62D76
		RTS
loc_62D76:
		JMP		_scr_cur_trd_off

; =============== S U B R O U T I N E =======================================
_obj_to_room_macro_collision_test_raw:
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_x_pos_hi,X
		STA		_tmp_var0
		LDA		_scr_trds_y_pos_hi,X
		STA		_tmp_var1
		LDY		_scr_trds_y_pos_lo,X
		LDA		_scr_trds_x_pos_lo,X
		TAX
		JSR		_room_macro_collision_test_ex
		BCS		loc_62D90
		RTS
loc_62D90:
		JMP		_scr_cur_trd_off

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_pal_fade_in:
		NJSR			_nsub_full_pal_fade_set			; fast shut down the palette in one
			NARGB		$FC								; call, FC=max fade out speed
		SDELAY			$01								; wait for buffers flush
		SLOOP_BEGIN		$04								; now send pal fade reqests 4 times
		NJSR			_nsub_pal_fade_req_inc_by_mask	; with increasing negative fade out value
			NARGB		$FF								; FD->FE->FF->00 (note, inc goes before fade)
		SDELAY			$03								; 3 frames of delay for fade effect
		SLOOP_END										; when finish, a full palette is loaded
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_pal_fade_out:
		NJSR			_nsub_full_pal_fade_set			; same with fade out, but starts from
			NARGB		$00								; applying current palette at full bright
		SLOOP_BEGIN		$04								; then decreasing the fade depth to make
		NJSR			_nsub_pal_fade_req_dec_by_mask	; fade it out.
			NARGB		$FF								; FF->FE->FD->FC (note, dec goes before fade)
		SDELAY			$03
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_room_entry_pal_fade_in:
		NJSR			_nsub_full_pal_fade_set
			NARGB		$FC

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_room_entry_pal_fade_in_ex:
		SDELAY			$01
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$FF
		SDELAY			$03
		SLOOP_END
		STORE8			_scr_trds_pause_mode,$00
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_room_exit_pal_fade_out:
		NJSR			_nsub_full_pal_fade_set
			NARGB		$00

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_room_exit_pal_fade_out_ex:
		STORE8			_scr_trds_pause_mode,$01
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask
			NARGB		$FF
		SDELAY			$03
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_sloc_62DD7:
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$02
_sloc_62DDB:
		SLOOP_BEGIN		$03
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$00
		SLOOP_END
		SARG_ALU		SARG1,_ADC,$01
		SLOOP_BEGIN		$02
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$01
		SLOOP_END
		SPR_IDX_SET		2,$00
_sloc_62DF7:
		SPR_IDX_INC		2
		NJSR			_nsub_scores_add_obj_value
		NJSR			_nsub_prize_sequence_test
		NJSR			_nsub_62B95
		SRET

; =============== S C R I P T  S U B R O U T I N E ==========================
_sloc_62E02:
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$02
_sloc_62E06:
		SLOOP_BEGIN		$03
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$02
		SLOOP_END
		SARG_ALU		SARG1,_ADC,$01
		SLOOP_BEGIN		$02
		NJSR			_nsub_obj_spr_idx_set_from_sarg
			NARGB		SARG1
		SDELAY			$01
		SPR_IDX_SET		1,$03
		SLOOP_END
		SPR_IDX_SET		2,$02
		SJMP			_sloc_62DF7
_sloc_62E25:
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$19
		SJMP			_sloc_62DDB
_sloc_62E2C:
		NJSR			_nsub_apu_snd_load_safe
			NARGB		$19
		SJMP			_sloc_62E06

; =============== S C R I P T  S U B R O U T I N E ==========================
_ssub_62E33:
		SLOOP_BEGIN		$80
		SMEM_ALU		_apu_mus_volume,_ADC,$FF
		SDELAY			$01
		SLOOP_END
		STORE8			_apu_mus_volume,$FF
		NJSR			_nsub_apu_mus_load
			NARGB		$04
		SRET

_spr_raw_lib1A_00:
		.BYTE	$03
		.BYTE	$F0,$C1,$00,$F8
		.BYTE	$F8,$C1,$00,$F0
		.BYTE	$00,$D1,$00,$F8
_spr_raw_lib1A_01:
		.BYTE	$01
		.BYTE	$00,$D1,$00,$F8
_spr_raw_lib1A_02:
		.BYTE	$03
		.BYTE	$F0,$C1,$40,$00
		.BYTE	$F8,$C1,$40,$08
		.BYTE	$00,$D1,$40,$00
_spr_raw_lib1A_03:
		.BYTE	$01
		.BYTE	$00,$D1,$40,$00

; =============== S U B R O U T I N E =======================================
_scr_trds_list_reset:
		LDA		#$FF
		LDX		#$0D
loc_62E6E:
		STA		_scr_trds_idx,X
		DEX
		BPL		loc_62E6E
		LDA		#$00
		STA		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_shift+1
		STA		_ppu_scroll_y_shift
		STA		_ppu_scroll_y_shift+1
		STA		_ppu_scroll_x_page
		STA		_ppu_scroll_y_page
		LDA		#$80
		STA		_ppu_scroll_x_clk
		STA		_ppu_scroll_y_clk
		LDA		#$20
		STA		_spr_buf_pos
		RTS

; =============== S U B R O U T I N E =======================================
_thread_lib_load_gen_ex:
		PHA
		LDA		#$06
		STA		_var4
		LDA		#$0E
		STA		_var5
		PLA
		JMP		_thread_lib_load

; =============== S U B R O U T I N E =======================================
_event_thread_start:
		PHA
		LDA		#$00
		STA		_var0
		STA		_var1
		STA		_var2
		STA		_var4
		LDA		#$0E
		STA		_var5
		PLA

; =============== S U B R O U T I N E =======================================
_thread_lib_load:
		STA		_tmp0
		STX		_tmp1
		STY		_tmp2
		LDX		_var4
loc_62EB2:
		LDA		_scr_trds_idx,X
		BMI		loc_62EBD
		INX
		CPX		_var5
		BCC		loc_62EB2
		RTS
loc_62EBD:
		LDA		_tmp1
		STA		_scr_trds_x_pos_lo,X
		LDA		_tmp2
		STA		_scr_trds_y_pos_lo,X
		LDA		_tmp_var0
		STA		_scr_trds_x_pos_hi,X
		LDA		_tmp_var1
		STA		_scr_trds_y_pos_hi,X
		LDA		_var0
		STA		_scr_trds_args0,X
		LDA		_var1
		STA		_scr_trds_args1,X
		LDA		_var2
		STA		_scr_trds_args2,X
		LDA		#$80
		STA		_scr_trds_x_move_clk,X
		STA		_scr_trds_y_move_clk,X
		LDA		_tmp0
		STA		_scr_trds_idx,X
		BMI		_nbgsub_dummy
		TAY
		LDA		_scr_lib_lo,Y
		PHA
		LDA		_scr_lib_hi,Y
		TAY
		PLA

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_thread_load:
		PHA
		TYA
		PHA
		LDA		#$FF
		STA		_scr_trds_spr_idx,X
		STA		_trds_manager_restart_flag
		LDA		#$00
		STA		_scr_trds_x_move_speed,X
		STA		_scr_trds_x_move_delta,X
		STA		_scr_trds_y_move_speed,X
		STA		_scr_trds_y_mov_delta,X
		LDA		#$01
		STA		_scr_trds_exec_req,X
		TXA
		ASL
		PHA
		TAX
		LDA		#<[_nbgsub_dummy]
		STA		_scr_trds_nbgsub_ptr,X
		LDA		#>[_nbgsub_dummy]
		STA		_scr_trds_nbgsub_ptr+1,X
		LDA		#$00
		STA		_scr_trds_sp,X
		STA		_scr_trds_sp+1,X
		STA		_scr_trds_delay,X
		STA		_scr_trds_delay+1,X
		PLA
		ASL
		TAX
		LDA		#$00
		STA		_scr_trds_ptr._ptr1+1,X		; set secondary script pointer to 00
		PLA
		STA		_scr_trds_ptr._ptr0+1,X		; load first script pointer with main script
		PLA
		STA		_scr_trds_ptr._ptr0,X

; =============== S U B R O U T I N E =======================================
_nbgsub_dummy:
		CLC
		RTS

_unused_7:
		.BYTE	$80,$C0,$E0,$F0

; =============== S U B R O U T I N E =======================================
; main core for script engine.
;
_threads_manager:
		LDX		#$0D						; set thread execution request at new iteration
		LDA		#$01						; every thread with flag set to 1 marked for execution
loc_62F45:
		STA		_scr_trds_exec_req,X		; total 14 threads here
		DEX
		BPL		loc_62F45
.trds_manager_restart:
		LDA		#$00
		STA		_scr_cur_trd_idx			; init thread index counter, start from thread 0
		STA		_trds_manager_restart_flag	; this flag may be set if any new script loaded runtime
.trds_manager_loop:
		LDX		_scr_cur_trd_idx			; here we check thread execution request first,
		LDA		_scr_trds_exec_req,X		; on the first loop they are all 1, so pass here
		BEQ		.trds_skip_exec
		DEC		_scr_trds_exec_req,X		; clear request as soon as we start to manage thread
		LDA		_scr_trds_idx,X				; check if thread initialized with script index
		BMI		.trds_skip_exec				; if FF, then thrd is empty, skip it
		LDA		_scr_trds_out_of_screen_test; check if out-of-screen test needed beforehead
		BEQ		.trds_do_exec				; if no, then just execute
		LDA		_scr_trds_pause_mode		; if not paused, performing out-of-screen test for
		BEQ		loc_62F6A					; all level threads, skip system threads (<6)
; NOTE: this TXA is redundant, comparison performed on X red directly!
; and A never used after that...
		TXA
; -
		CPX		#$02						; if paused, hold all other threads, excluding the
		BCS		.trds_skip_exec				; system threads: 0 - level, 1 - level doors
loc_62F6A:
		CPX		#$06
		BCC		.trds_do_exec
		JSR		_obj_screen_pos_calc		; when object out of screen, hold it, so any object
		BCS		.trds_skip_exec				; halted, but will resume if visible again...
.trds_do_exec:
		LDX		_scr_cur_trd_idx			; now, finally do execute. fetch current thread index
		LDY		_scr_trds_idx,X				; and set corresponding PRG bank before executing
		LDA		_scr_bank_lib,Y				; scripts may be executed independently, but must
		STA		_prg_cur_bank				; inherit one of existing library indexes to be able
		JSR		_mmc1_prg_safe				; to use proper programm bank and sprite library
		JSR		_thread_exec
.trds_skip_exec:
		INC		_scr_cur_trd_idx			; repeat for all 14 threds
		LDA		_scr_cur_trd_idx
		CMP		#$0E
		BCC		.trds_manager_loop
		LDA		_trds_manager_restart_flag	; if one of threads added a new script, it must set
		BNE		.trds_manager_restart		; restart flag. execution loop starts again, but
		LDA		_ppu_scroll_x_shift+1		; will exec only that new added thread, because all
		CLC									; others has execution request clear already.
		ADC		_ppu_scroll_x_page			; next, time to adjust scrolls
		STA		_tmp0						; and global objects shift parameter
		LDA		#$00						; first for X scrolls
		STA		_ppu_scroll_x_page
		LDX		#$00
		LDA		_tmp0
		BPL		loc_62FA1
		DEX
loc_62FA1:
		LDA		_ppu_scroll_x_clk
		CLC
		ADC		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_clk
		LDA		_ppu_scroll_pos_x
		ADC		_tmp0
		STA		_ppu_scroll_pos_x
		TXA
		ADC		_ppu_scroll_pos_x+1
		STA		_ppu_scroll_pos_x+1
		LDA		_ppu_scroll_y_shift+1		; then for Y scrolls
		CLC
		ADC		_ppu_scroll_y_page
		STA		_tmp0
		LDA		#$00
		STA		_ppu_scroll_y_page
		LDA		_tmp0
		BMI		loc_62FDA
		LDA		_ppu_scroll_y_shift
		CLC
		ADC		_ppu_scroll_y_clk
		STA		_ppu_scroll_y_clk
		LDA		_ppu_scroll_pos_y
		ADC		_tmp0
		CMP		#$F0
		BCC		loc_62FD5					; do not forget to wrap around 240 scanline
		ADC		#$0F						; because of PPU specific
		INC		_ppu_scroll_pos_y+1
loc_62FD5:
		STA		_ppu_scroll_pos_y
		JMP		loc_62FFE
loc_62FDA:
		LDA		_ppu_scroll_y_shift
		EOR		#$FF
		CLC
		ADC		#$01
		STA		_var0
		LDA		_tmp0
		EOR		#$FF
		ADC		#$00
		STA		_var1
		LDA		_ppu_scroll_y_clk
		SEC
		SBC		_var0
		STA		_ppu_scroll_y_clk
		LDA		_ppu_scroll_pos_y
		SBC		_var1
		BCS		loc_62FFC
		SBC		#$0F
		DEC		_ppu_scroll_pos_y+1
loc_62FFC:
		STA		_ppu_scroll_pos_y
loc_62FFE:
		LDX		#$00
loc_63000:
		LDY		_scr_trds_idx,X				; after all scroll and shifts are recalculated
		BMI		loc_63014					; we may draw sprite finally. one sprite for one thread
		LDA		_scr_bank_lib,Y				; every object has its own sprite library in a
		STA		_prg_cur_bank				; corresponding bank, so select bank again
		JSR		_mmc1_prg_safe				; and perform sprite insertion procedure according
		TXA									; to sprite index assigned in thread arrays
		PHA
		JSR		_obj_spr_insert
		PLA
		TAX
loc_63014:
		INX
		CPX		#$0E
		BCC		loc_63000					; repeat for all threads...
		RTS

; =============== S U B R O U T I N E =======================================
_obj_spr_insert:
		LDA		_scr_trds_x_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_x
		STA		_tmp1
		LDA		_scr_trds_x_pos_hi,X
		SBC		_ppu_scroll_pos_x+1
		BNE		locret_6309C
		LDA		_scr_trds_y_pos_lo,X
		SEC
		SBC		_ppu_scroll_pos_y
		BCS		loc_63032
		SBC		#$0F
		CLC
loc_63032:
		STA		_tmp2
		LDA		_scr_trds_y_pos_hi,X
		SBC		_ppu_scroll_pos_y+1
		BNE		locret_6309C
		LDY		_scr_trds_idx,X
		LDA		_scr_trds_spr_idx,X
		CMP		#$C0
		BCS		loc_6309D
		LDA		#$00
		STA		_var0
		LDA		_scr_trds_spr_idx,X
		ASL
		ROL		_var0
		ADC		_spr_raw_lib_lo,Y
		STA		_ptr06
		LDA		_var0
		ADC		_spr_raw_lib_hi,Y
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		STA		_ptr08
		INY
		LDA		(_ptr06),Y
		STA		_ptr08+1
; REGION: replaced in the EU version, using the clipped version of the
; sprite insert routine. this fixes the original japanese version BUG
; when object clipped with the left corner of the screen appears at the
; right side.
		DEC		_tmp2
		LDY		#$00
		LDA		(_ptr08),Y
		STA		_var0
		INY
		LDX		_spr_buf_pos
loc_6306F:
; REGION, this also missing in the US proto version
		LDA		#$00
		STA		_ppu_spr_buf+3,X
; -
		LDA		(_ptr08),Y
		CLC
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+1,X
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+2,X
		INY
		LDA		(_ptr08),Y
		CLC
		ADC		_tmp1
		STA		_ppu_spr_buf+3,X
		INY
		INX
		INX
		INX
		INX
		DEC		_var0
		BNE		loc_6306F
		STX		_spr_buf_pos
; -
;		LDA		#$00
;		STA		_tmpD8
;		STA		_tmpD9
;		JSR		_spr_clip_insert_ex
; -
locret_6309C:
		RTS
loc_6309D:
		CMP		#$FF
		BEQ		locret_6309C
		SBC		#$BF
		ASL
		ADC		_spr_res_lib_lo,Y
		STA		_ptr06
		LDA		#$00
		ADC		_spr_res_lib_hi,Y
		STA		_ptr06+1
		LDY		#$00
		LDA		(_ptr06),Y
		STA		_scr_pc
		INY
		LDA		(_ptr06),Y
		STA		_scr_pc+1
		DEY
		LDA		(_scr_pc),Y
		BMI		loc_630E5
		STA		_scr_loop_count
		INY
loc_630C3:
		LDA		(_scr_pc),Y
		STA		_ptr08
		INY
		LDA		(_scr_pc),Y
		STA		_ptr08+1
		INY
		TYA
		PHA
		LDX		_scr_cur_trd_idx
		LDA		#$00
		STA		_tmpD8
		STA		_tmpD9
		LDY		_tmp2
		LDX		_tmp1
		JSR		_spr_clip_insert
		PLA
		TAY
		DEC		_scr_loop_count
		BNE		loc_630C3
		RTS
; NOTE: this is a special case for sprite data, never used
; in this game
loc_630E5:
		AND		#$7F
		STA		_scr_loop_count
		INY
loc_630EA:
		LDA		_tmp1
		PHA
		LDA		_tmp2
		PHA
		LDA		#$00
		STA		_tmpD8
		STA		_tmpD9
		LDA		(_scr_pc),Y
		BPL		loc_630FC
		DEC		_tmpD8
loc_630FC:
		ADC		_tmp1
		STA		_tmp1
		BCC		loc_63104
		INC		_tmpD8
loc_63104:
		INY
		LDA		(_scr_pc),Y
		BPL		loc_6310B
		DEC		_tmpD9
loc_6310B:
		CLC
		ADC		_tmp2
		STA		_tmp2
		BCC		loc_63114
		INC		_tmpD9
loc_63114:
		INY
		LDA		(_scr_pc),Y
		STA		_ptr08
		INY
		LDA		(_scr_pc),Y
		STA		_ptr08+1
		INY
		TYA
		PHA
		LDX		_tmp1
		LDY		_tmp2
		JSR		_spr_clip_insert
		PLA
		TAY
		PLA
		STA		_tmp2
		PLA
		STA		_tmp1
		DEC		_scr_loop_count
		BNE		loc_630EA
		RTS

; =============== S U B R O U T I N E =======================================
; main thread execution routine
; every thread able to run TWO parallel scripts. all threads started with just
; one default script in slot 0, but at runtime it may run additional parallel
; script to perform any background work, like animation.
; also, every thread may have an additional native code sub-thread. it also
; assigned inside thread and used mostly for native IO operations, like pad
; tests.
;
_thread_exec:
		LDA		#$00
		STA		_scr_loop_count				; init scripts counter here
loc_63139:
		LDA		_scr_cur_trd_idx			; calc the current script pointer offset
		ASL										; NOTE, _scr_cur_trd_idxw is used to separate
		ADC		_scr_loop_count				; both script stack operations, delays and exec flow.
		STA		_scr_cur_trd_idxw			; but both scripts will refer as _scr_cur_trd_idx
		ASL										; for all other parameters
		TAX									;
		LDA		_scr_trds_ptr+1,X			; if high nibble of script offset is zero
		BEQ		loc_6314A					; then this script is disabled, skip it
		JSR		_script_exec				; execute if not
loc_6314A:
		INC		_scr_loop_count				; repeat for both scripts
		LDA		_scr_loop_count
		CMP		#$02
		BCC		loc_63139
		LDA		_scr_cur_trd_idx			; now execute additional native
		ASL										; background routine, this routine always
		TAX									; defined to some dummy procedure by default
		LDA		_scr_trds_nbgsub_ptr,X		; so no need to check if it used at all
		STA		_ptr06
		LDA		_scr_trds_nbgsub_ptr+1,X
		STA		_ptr06+1
		JSR		_jump_ptr_ind
		LDX		_scr_cur_trd_idx
		LDA		_scr_trds_idx,X				; if thread not stopped during execution,
		BPL		_scr_trd_adjust_pos			; calculate new objexct position with parameters given
		RTS
_scr_trd_adjust_pos:
		LDA		#$00
		STA		_var0
		STA		_var1
		LDA		_scr_trds_x_move_delta,X	; all move parameters are defined, so just calculate
		BPL		loc_63178					; final positions and update them
		DEC		_var0
loc_63178:
		LDA		_scr_trds_y_mov_delta,X
		BPL		loc_6317F
		DEC		_var1
loc_6317F:
		LDA		_scr_trds_x_move_clk,X
		CLC
		ADC		_scr_trds_x_move_speed,X
		STA		_scr_trds_x_move_clk,X
		LDA		_scr_trds_x_pos_lo,X
		ADC		_scr_trds_x_move_delta,X
		STA		_scr_trds_x_pos_lo,X
		LDA		_scr_trds_x_pos_hi,X
		ADC		_var0
		STA		_scr_trds_x_pos_hi,X
		LDA		_scr_trds_y_move_speed,X
		CLC
		ADC		_scr_trds_y_move_clk,X
		STA		_scr_trds_y_move_clk,X
		LDA		_scr_trds_y_mov_delta,X
		BMI		loc_631B4
		ADC		_scr_trds_y_pos_lo,X
		BCS		loc_631AF
		CMP		#$F0
		BCC		loc_631BB
loc_631AF:
		ADC		#$0F
		SEC
		BCS		loc_631BB
loc_631B4:
		ADC		_scr_trds_y_pos_lo,X
		BCS		loc_631BB
		SBC		#$0F
		CLC
loc_631BB:
		STA		_scr_trds_y_pos_lo,X
		LDA		_var1
		ADC		_scr_trds_y_pos_hi,X
		STA		_scr_trds_y_pos_hi,X		; that's all here
		RTS

; =============== S U B R O U T I N E =======================================
; scripts execution routine, run code until delay is set either with
; SDELAY command or with any delayed command
;
_script_exec:
		LDX		_scr_cur_trd_idxw			; every script has delay priority option
		LDA		_scr_trds_delay,X			; if not zero, skip this iteration
		BNE		loc_63240					; and decrement delay
		TXA
		ASL
		TAX
		LDA		_scr_trds_ptr,X				; fetch corresponding script pointer
		STA		_scr_pc
		LDA		_scr_trds_ptr+1,X
		STA		_scr_pc+1
		LDA		#$00
		STA		_scr_cur_trd_stack_ptr+1	; calculate current stack array pos
		TXA
		ASL
		ASL
		ROL		_scr_cur_trd_stack_ptr+1
		ADC		#<[_scr_trds_stack]
		STA		_scr_cur_trd_stack_ptr
		LDA		_scr_cur_trd_stack_ptr+1
		ADC		#>[_scr_trds_stack]
		STA		_scr_cur_trd_stack_ptr+1
loc_631ED:
		LDY		#$00						; start to fetch comand
		LDA		(_scr_pc),Y
		PHA
		CMP		#$20						; commands below 0x20 are regular
		BCS		.script_delayed_cmd			; continuos commands except SDELAY
		PLA									; which forced the script execution
		BNE		.script_regular_cmd			; flow interruption
		LDX		_scr_cur_trd_idx			; command 00 is a STOP command
		LDA		#$FF						; disables the thread idx flag and
		STA		_scr_trds_idx,X				; exit from _thread_exec as well
		PLA
		PLA
		RTS
.script_regular_cmd:
		TAX
		LDA		_scmd_lib_lo-1,X
		STA		_ptr06
		LDA		_scmd_lib_hi-1,X
		BNE		.script_cmd_exec
.script_delayed_cmd:
		LDX		_scr_cur_trd_idxw			; delayed cmd may be executed continuosly
		PLA									; if no delay set, if set, every time it
		PHA									; executed, script flow stopped to the next
		AND		#$07						; iteration
		STA		_scr_trds_delay,X
		PLA
		SEC
		SBC		#$20
		LSR
		LSR
		LSR
		TAX
		LDA		_dcmd_lib_lo,X
		STA		_ptr06
		LDA		_dcmd_lib_hi,X
.script_cmd_exec:
		STA		_ptr06+1
		JSR		_jump_ptr_ind
		LDX		_scr_cur_trd_idxw			; if no delays set during execution, continue
		LDA		_scr_trds_delay,X			; script code flow
		BEQ		loc_631ED					; otherwise stop execution and continue to the
		TXA									; next script/thread
		ASL
		TAX
		LDA		_scr_pc						; flush current PC pointer
		STA		_scr_trds_ptr,X
		LDA		_scr_pc+1
		STA		_scr_trds_ptr+1,X
loc_63240:
		LDX		_scr_cur_trd_idxw			; do delays count as well
		DEC		_scr_trds_delay,X
		RTS

; NOTE: there are two sets of script comands. this block describes
; the immediate opcodes, executed immediately and continue code flow
; after that.
_scmd_lib_lo:
		CMD_IDX_LO	_scmd01_loop_begin
		CMD_IDX_LO	_scmd02_loop_end
		CMD_IDX_LO	_scmd03_sjmp
		CMD_IDX_LO	_scmd04_sjsr
		CMD_IDX_LO	_scmd05_ret
		CMD_IDX_LO	_scmd06_delay
		CMD_IDX_LO	_scmd07_njsr
		CMD_IDX_LO	_scmd08_script1_start
		CMD_IDX_LO	_scmd09_nbg_hndl_set
		CMD_IDX_LO	_scmd0A_suspend
		CMD_IDX_LO	_scmd0B_bcs
		CMD_IDX_LO	_scmd0C_bcc
		CMD_IDX_LO	_scmd0A_script0_off
		CMD_IDX_LO	_scmd0E_smem_alu
		CMD_IDX_LO	_scmd0F_sarg_set
		CMD_IDX_LO	_scmd10_nbg_hndl_reset
		CMD_IDX_LO	_scmd11_sjmp_sw
		CMD_IDX_LO	_scmd12_sjsr_sw
		CMD_IDX_LO	_scmd13_store8
		CMD_IDX_LO	_scmd14_script1_off
		CMD_IDX_LO	_scmd15_sarg_alu
		CMD_IDX_LO	_scmd16_store16
		CMD_IDX_LO	_scmd17_sbcs_break
		CMD_IDX_LO	_scmd18_sbcc_break	; unused
		CMD_IDX_LO	_scmd19_njsr_sw		; unused
_scmd_lib_hi:
		CMD_IDX_HI	_scmd01_loop_begin
		CMD_IDX_HI	_scmd02_loop_end
		CMD_IDX_HI	_scmd03_sjmp
		CMD_IDX_HI	_scmd04_sjsr
		CMD_IDX_HI	_scmd05_ret
		CMD_IDX_HI	_scmd06_delay
		CMD_IDX_HI	_scmd07_njsr
		CMD_IDX_HI	_scmd08_script1_start
		CMD_IDX_HI	_scmd09_nbg_hndl_set
		CMD_IDX_HI	_scmd0A_suspend
		CMD_IDX_HI	_scmd0B_bcs
		CMD_IDX_HI	_scmd0C_bcc
		CMD_IDX_HI	_scmd0A_script0_off
		CMD_IDX_HI	_scmd0E_smem_alu
		CMD_IDX_HI	_scmd0F_sarg_set
		CMD_IDX_HI	_scmd10_nbg_hndl_reset
		CMD_IDX_HI	_scmd11_sjmp_sw
		CMD_IDX_HI	_scmd12_sjsr_sw
		CMD_IDX_HI	_scmd13_store8
		CMD_IDX_HI	_scmd14_script1_off
		CMD_IDX_HI	_scmd15_sarg_alu
		CMD_IDX_HI	_scmd16_store16
		CMD_IDX_HI	_scmd17_sbcs_break
		CMD_IDX_HI	_scmd18_sbcc_break
		CMD_IDX_HI	_scmd19_njsr_sw
; NOTE: every opcode in this block has additional parameter of delay
; command is executed then script delayed for a number of frames from
; 1 to 7. if delay 0 selected, then there is no delay there.
; delay means that current script will skip selected amount of frames
; after execution. for sprite management this means setting of this
; sprite will be applied and shown for selected amont of time.
_dcmd_lib_lo:
		DCMD_IDX_LO	_dcmd00_spr_idx_set
		DCMD_IDX_LO	_dcmd01_pos_x_set
		DCMD_IDX_LO	_dcmd02_pos_y_set
		DCMD_IDX_LO	_dcmd03_pos_x_move
		DCMD_IDX_LO	_dcmd04_pos_y_move
		DCMD_IDX_LO	_dcmd05_pos_x_delta
		DCMD_IDX_LO	_dcmd06_pos_y_delta
		DCMD_IDX_LO	_dcmd07_pos_x_delta_add
		DCMD_IDX_LO	_dcmd08_pos_y_delta_add
		DCMD_IDX_LO	_dcmd09_scrl_x_set		; unused
		DCMD_IDX_LO	_dcmd0A_scrl_y_sey
		DCMD_IDX_LO	_dcmd0B_scrl_x_move_set
		DCMD_IDX_LO	_dcmd0C_scrl_move_y_set	; unused
		DCMD_IDX_LO	_dcmd0D_scrl_x_move_add	; unused
		DCMD_IDX_LO	_dcmd0E_scrl_y_move_add	; unused
		DCMD_IDX_LO	_dcmd0F_spr_idx_inc
		DCMD_IDX_LO	_dcmd10_spr_idx_dec
		DCMD_IDX_LO	_dcmd11_spr_idx_add_imm
		DCMD_IDX_LO	_dcmd12_byte_D5_add		; unused
		DCMD_IDX_LO	_dcmd13_byte_D6_add		; unused
		DCMD_IDX_LO	_dcmd14_pos_move_stop
		DCMD_IDX_LO	_dcmd15_scrl_move_stop
_dcmd_lib_hi:
		DCMD_IDX_HI	_dcmd00_spr_idx_set
		DCMD_IDX_HI	_dcmd01_pos_x_set
		DCMD_IDX_HI	_dcmd02_pos_y_set
		DCMD_IDX_HI	_dcmd03_pos_x_move
		DCMD_IDX_HI	_dcmd04_pos_y_move
		DCMD_IDX_HI	_dcmd05_pos_x_delta
		DCMD_IDX_HI	_dcmd06_pos_y_delta
		DCMD_IDX_HI	_dcmd07_pos_x_delta_add
		DCMD_IDX_HI	_dcmd08_pos_y_delta_add
		DCMD_IDX_HI	_dcmd09_scrl_x_set
		DCMD_IDX_HI	_dcmd0A_scrl_y_sey
		DCMD_IDX_HI	_dcmd0B_scrl_x_move_set
		DCMD_IDX_HI	_dcmd0C_scrl_move_y_set
		DCMD_IDX_HI	_dcmd0D_scrl_x_move_add
		DCMD_IDX_HI	_dcmd0E_scrl_y_move_add
		DCMD_IDX_HI	_dcmd0F_spr_idx_inc
		DCMD_IDX_HI	_dcmd10_spr_idx_dec
		DCMD_IDX_HI	_dcmd11_spr_idx_add_imm
		DCMD_IDX_HI	_dcmd12_byte_D5_add
		DCMD_IDX_HI	_dcmd13_byte_D6_add
		DCMD_IDX_HI	_dcmd14_pos_move_stop
		DCMD_IDX_HI	_dcmd15_scrl_move_stop

; =============== S U B R O U T I N E =======================================
_scmd01_loop_begin:
		JSR		_scr_getc
		PHA
		LDX		_scr_cur_trd_idxw
		LDY		_scr_trds_sp,X
		LDA		_scr_pc
		CLC
		ADC		#$01
		PHA
		LDA		_scr_pc+1
		ADC		#$00
		STA		(_scr_cur_trd_stack_ptr),Y
		INY
		PLA
		STA		(_scr_cur_trd_stack_ptr),Y
		INY
		PLA
		STA		(_scr_cur_trd_stack_ptr),Y
		INY
		TYA
		STA		_scr_trds_sp,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd02_loop_end:
		LDX		_scr_cur_trd_idxw
		LDY		_scr_trds_sp,X
		DEY
		LDA		(_scr_cur_trd_stack_ptr),Y
		SEC
		SBC		#$01
		STA		(_scr_cur_trd_stack_ptr),Y
		BNE		loc_632E1
		DEY
		DEY
		TYA
		STA		_scr_trds_sp,X
		JMP		_scr_pc_inc
loc_632E1:
		DEY
		LDA		(_scr_cur_trd_stack_ptr),Y
		STA		_scr_pc
		DEY
		LDA		(_scr_cur_trd_stack_ptr),Y
		STA		_scr_pc+1
		RTS

; =============== S U B R O U T I N E =======================================
_scmd03_sjmp:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		STA		_scr_pc+1
		PLA
		STA		_scr_pc
		RTS

; =============== S U B R O U T I N E =======================================
_scmd04_sjsr:
		JSR		_scr_getc
		PHA
		JSR		_scr_getc
		PHA
		JSR		_scr_pc_inc
		LDX		_scr_cur_trd_idxw
		LDY		_scr_trds_sp,X
		LDA		_scr_pc+1
		STA		(_scr_cur_trd_stack_ptr),Y
		INY
		LDA		_scr_pc
		STA		(_scr_cur_trd_stack_ptr),Y
		INY
		TYA
		STA		_scr_trds_sp,X
		PLA
		STA		_scr_pc+1
		PLA
		STA		_scr_pc
		RTS

; =============== S U B R O U T I N E =======================================
_scmd05_ret:
		LDX		_scr_cur_trd_idxw				; NOTE, the method of handling parallel
		LDY		_scr_trds_sp,X					; scripts sometime causes clear script
		BEQ		loc_63334						; stacks during execution of the sub routines...
		DEY
		LDA		(_scr_cur_trd_stack_ptr),Y
		STA		_scr_pc
		DEY
		LDA		(_scr_cur_trd_stack_ptr),Y
		STA		_scr_pc+1
		TYA
		STA		_scr_trds_sp,X
		RTS
loc_63334:
		LDX		_scr_cur_trd_idx				; ...so if script trying to return from _ssub
		LDA		#$FF							; with empty stack, we just silently exit it
		STA		_scr_trds_idx,X					; and keep executing the res.
		PLA
		PLA
		PLA
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
_scmd06_delay:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idxw
		STA		_scr_trds_delay,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd00_spr_idx_set:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_spr_idx,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd01_pos_x_set:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_x_pos_lo,X
		JSR		_scr_getc
		STA		_scr_trds_x_pos_hi,X
		LDA		#$80
		STA		_scr_trds_x_move_clk,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd02_pos_y_set:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_y_pos_lo,X
		JSR		_scr_getc
		STA		_scr_trds_y_pos_hi,X
		LDA		#$80
		STA		_scr_trds_y_move_clk,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd05_pos_x_delta:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_x_move_speed,X
		JSR		_scr_getc
		STA		_scr_trds_x_move_delta,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd06_pos_y_delta:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		STA		_scr_trds_y_move_speed,X
		JSR		_scr_getc
		STA		_scr_trds_y_mov_delta,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd07_pos_x_delta_add:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		CLC
		ADC		_scr_trds_x_move_speed,X
		STA		_scr_trds_x_move_speed,X
		PHP
		JSR		_scr_getc
		PLP
		ADC		_scr_trds_x_move_delta,X
		STA		_scr_trds_x_move_delta,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd08_pos_y_delta_add:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		CLC
		ADC		_scr_trds_y_move_speed,X
		STA		_scr_trds_y_move_speed,X
		PHP
		JSR		_scr_getc
		PLP
		ADC		_scr_trds_y_mov_delta,X
		STA		_scr_trds_y_mov_delta,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; unused
_dcmd09_scrl_x_set:
		JSR		_scr_getc
		STA		_ppu_scroll_pos_x
		JSR		_scr_getc
		STA		_ppu_scroll_pos_x+1
		LDA		#$80
		STA		_ppu_scroll_x_clk
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd0A_scrl_y_sey:
		JSR		_scr_getc
		STA		_ppu_scroll_pos_y
		JSR		_scr_getc
		STA		_ppu_scroll_pos_y+1
		LDA		#$80
		STA		_ppu_scroll_y_clk
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; unused
_dcmd0B_scrl_x_move_set:
		JSR		_scr_getc
		STA		_ppu_scroll_x_shift
		JSR		_scr_getc
		STA		_ppu_scroll_x_shift+1
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd0C_scrl_move_y_set:
		JSR		_scr_getc
		STA		_ppu_scroll_y_shift
		JSR		_scr_getc
		STA		_ppu_scroll_y_shift+1
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; unused
_dcmd0D_scrl_x_move_add:
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_shift
		PHP
		JSR		_scr_getc
		PLP
		ADC		_ppu_scroll_x_shift+1
		STA		_ppu_scroll_x_shift+1
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; unused
_dcmd0E_scrl_y_move_add:
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_y_shift
		STA		_ppu_scroll_y_shift
		PHP
		JSR		_scr_getc
		PLP
		ADC		_ppu_scroll_y_shift+1
		STA		_ppu_scroll_y_shift+1
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd03_pos_x_move:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		LDY		#$00
		STY		_var0
		TAY
		BPL		loc_63447
		DEC		_var0
loc_63447:
		CLC
		ADC		_scr_trds_x_pos_lo,X
		STA		_scr_trds_x_pos_lo,X
		LDA		_scr_trds_x_pos_hi,X
		ADC		_var0
		STA		_scr_trds_x_pos_hi,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd04_pos_y_move:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		CLC
		BMI		loc_63471
		ADC		_scr_trds_y_pos_lo,X
		BCS		loc_63467
		CMP		#$F0
		BCC		loc_6346C
loc_63467:
		ADC		#$0F
		INC		_scr_trds_y_pos_hi,X
loc_6346C:
		STA		_scr_trds_y_pos_lo,X
		JMP		_scr_pc_inc
loc_63471:
		ADC		_scr_trds_y_pos_lo,X
		BCS		loc_6347A
		SBC		#$0F
		DEC		_scr_trds_y_pos_hi,X
loc_6347A:
		STA		_scr_trds_y_pos_lo,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; unused
_dcmd12_byte_D5_add:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_x_page
		STA		_ppu_scroll_x_page
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; unused
_dcmd13_byte_D6_add:
		LDX		_scr_cur_trd_idx
		JSR		_scr_getc
		CLC
		ADC		_ppu_scroll_y_page
		STA		_ppu_scroll_y_page
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd14_pos_move_stop:
		LDX		_scr_cur_trd_idx
		LDA		#$00
		STA		_scr_trds_x_move_speed,X
		STA		_scr_trds_x_move_delta,X
		STA		_scr_trds_y_move_speed,X
		STA		_scr_trds_y_mov_delta,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd15_scrl_move_stop:
		LDX		_scr_cur_trd_idx
		LDA		#$00
		STA		_ppu_scroll_x_shift
		STA		_ppu_scroll_x_shift+1
		STA		_ppu_scroll_y_shift
		STA		_ppu_scroll_y_shift+1
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd07_njsr:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_jump_ptr_ind
		STA		_nsub_return_value
		PHP
		PLA
		STA		_nsub_return_flags
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd0C_bcc:
		LDA		_nsub_return_flags
		PHA
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		TAX
		PLA
		LSR
		BCS		_j_scr_pc_incB

; =============== S U B R O U T I N E =======================================
_scr_pc_set:
		STX		_scr_pc+1
		LDA		_tmp0
		STA		_scr_pc
		RTS

; =============== S U B R O U T I N E =======================================
_j_scr_pc_incB:
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd0B_bcs:
		LDA		_nsub_return_flags
		PHA
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		TAX
		PLA
		LSR
		BCC		_j_scr_pc_incB
		BCS		_scr_pc_set

; =============== S U B R O U T I N E =======================================
_scmd11_sjmp_sw:
		JSR		_scr_getc
		JSR		_scr_pc_inc
		CMP		_nsub_return_value
		BCC		_scmd_skip
		BNE		_cmd_switch_case

; =============== S U B R O U T I N E =======================================
_scmd_skip:
		ASL
		ADC		_scr_pc
		STA		_scr_pc
		BCC		locret_63512
		INC		_scr_pc+1
locret_63512:
		RTS

; =============== S U B R O U T I N E =======================================
_cmd_switch_case:
		LDA		_nsub_return_value
		ASL
		TAY
		LDA		(_scr_pc),Y
		PHA
		INY
		LDA		(_scr_pc),Y
		STA		_scr_pc+1
		PLA
		STA		_scr_pc
		RTS

; =============== S U B R O U T I N E =======================================
_scmd12_sjsr_sw:
		JSR		_scr_getc
		JSR		_scr_pc_inc
		CMP		_nsub_return_value
		BCC		_scmd_skip
		BEQ		_scmd_skip
		LDX		_scr_cur_trd_idxw
		LDY		_scr_trds_sp,X
		INY
		ASL
		ADC		_scr_pc
		STA		(_scr_cur_trd_stack_ptr),Y
		DEY
		LDA		#$00
		ADC		_scr_pc+1
		STA		(_scr_cur_trd_stack_ptr),Y
		INY
		INY
		TYA
		STA		_scr_trds_sp,X
		BNE		_cmd_switch_case

; =============== S U B R O U T I N E =======================================
; unused
_scmd19_njsr_sw:
		JSR		_scr_getc
		JSR		_scr_pc_inc
		CMP		_nsub_return_value
		BCC		_scmd_skip
		BEQ		_scmd_skip
		PHA
		LDA		_nsub_return_value
		ASL
		TAY
		LDA		(_scr_pc),Y
		STA		_ptr06
		INY
		LDA		(_scr_pc),Y
		STA		_ptr06+1
		JSR		_jump_ptr_ind
		STA		_nsub_return_value
		PHP
		PLA
		STA		_nsub_return_flags
		PLA
		JMP		_scmd_skip

; =============== S U B R O U T I N E =======================================
; disables currently executing script for given thread
;
_scmd0A_script0_off:
		LDA		_scr_cur_trd_idxw
		ASL
		TAX
		LDA		#$00
		STA		_scr_trds_ptr+1,X
		PLA
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
; sets a new script pointer for current thread, select one of two script
; slots with first parameter. never used for re-load the main script, only
; for loading an additional secondary sub-script.
;
; TODO: remove redundant param (always 01!) to optimize opcode!
;
_scmd08_script1_start:
		JSR		_scr_getc
		STA		_var0
		JSR		_scr_getc
		STA		_var1
		JSR		_scr_getc
		STA		_var2
		LDA		_scr_cur_trd_idx
		ASL
		ADC		_var0
		TAX
		LDA		#$00
		STA		_scr_trds_sp,X
		STA		_scr_trds_delay,X
		TXA
		ASL
		TAX
		LDA		_var1
		STA		_scr_trds_ptr,X
		LDA		_var2
		STA		_scr_trds_ptr+1,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
; disables the selected script for current thread. also never used to disable
; main script for thread, only for secondary one... in any cases that need
; to disable main script, SSCRIPT0_OFF command used!
;
; TODO: may be reduced in size by removing redundant argument (always 01!)
;
_scmd14_script1_off:
		JSR		_scr_getc
		STA		_tmp0
		LDA		_scr_cur_trd_idx
		ASL
		ADC		_tmp0
		ASL
		TAX
		LDA		#$00
		STA		_scr_trds_ptr+1,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd09_nbg_hndl_set:
		LDA		_scr_cur_trd_idx
		ASL
		TAX
		JSR		_scr_getc
		STA		_scr_trds_nbgsub_ptr,X
		JSR		_scr_getc
		STA		_scr_trds_nbgsub_ptr+1,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd0A_suspend:
		LDX		_scr_cur_trd_idxw
		LDA		#$FF
		STA		_scr_trds_delay,X
		RTS

; =============== S U B R O U T I N E =======================================
_dcmd0F_spr_idx_inc:
		LDX		_scr_cur_trd_idx
		INC		_scr_trds_spr_idx,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd10_spr_idx_dec:
		LDX		_scr_cur_trd_idx
		DEC		_scr_trds_spr_idx,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_dcmd11_spr_idx_add_imm:
		JSR		_scr_getc
		LDX		_scr_cur_trd_idx
		CLC
		ADC		_scr_trds_spr_idx,X
		STA		_scr_trds_spr_idx,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd15_sarg_alu:
		JSR		_scr_getc
		TAX
		LDA		_scr_args_list_ptr_lo,X
		CLC
		ADC		_scr_cur_trd_idx
		STA		_ptr08
		LDA		_scr_args_list_ptr_hi,X
		ADC		#$00
		STA		_ptr08+1
		BCC		_scr_alu_exec

; =============== S U B R O U T I N E =======================================
_scmd0E_smem_alu:
		JSR		_scr_getc
		STA		_ptr08
		JSR		_scr_getc
		STA		_ptr08+1

; =============== S U B R O U T I N E =======================================
; NOTE, two of three ALU operations in this game never used as well AND and ORA
_scr_alu_exec:
		JSR		_scr_getc
		TAX
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_pc_inc
		LDA		_scmd0E_sub_lib_lo,X
		STA		_ptr06
		LDA		_scmd0E_sub_lib_hi,X
		STA		_ptr06+1
		JMP		(_ptr06)
_scmd0E_sub_lib_lo:
		.BYTE	<[_scmd0E_and]
		.BYTE	<[_scmd0E_ora]
		.BYTE	<[_scmd0E_adc]
_scmd0E_sub_lib_hi:
		.BYTE	>[_scmd0E_and]
		.BYTE	>[_scmd0E_ora]
		.BYTE	>[_scmd0E_adc]

; =============== S U B R O U T I N E =======================================
; AND subfunction unused
_scmd0E_and:
		LDA		(_ptr08),Y
		AND		_tmp0
		STA		(_ptr08),Y
		RTS

; =============== S U B R O U T I N E =======================================
; ORA subfunction unused
_scmd0E_ora:
		LDA		(_ptr08),Y
		ORA		_tmp0
		STA		(_ptr08),Y
		RTS

; =============== S U B R O U T I N E =======================================
_scmd0E_adc:
		LDA		(_ptr08),Y
		CLC
		ADC		_tmp0
		STA		(_ptr08),Y
		RTS

; =============== S U B R O U T I N E =======================================
_scmd0F_sarg_set:
		JSR		_scr_getc
		TAX
		LDA		_scr_args_list_ptr_lo,X
		STA		_ptr06
		LDA		_scr_args_list_ptr_hi,X
		STA		_ptr06+1
		JSR		_scr_getc
		LDY		_scr_cur_trd_idx
		STA		(_ptr06),Y
		JMP		_scr_pc_inc
_scr_args_list_ptr_lo:
		.BYTE	<[_scr_trds_args0]
		.BYTE	<[_scr_trds_args1]
		.BYTE	<[_scr_trds_args2]
_scr_args_list_ptr_hi:
		.BYTE	>[_scr_trds_args0]
		.BYTE	>[_scr_trds_args1]
		.BYTE	>[_scr_trds_args2]

; =============== S U B R O U T I N E =======================================
_scmd10_nbg_hndl_reset:
		LDA		_scr_cur_trd_idx
		ASL
		TAX
		LDA		#<[_nbgsub_dummy]
		STA		_scr_trds_nbgsub_ptr,X
		LDA		#>[_nbgsub_dummy]
		STA		_scr_trds_nbgsub_ptr+1,X
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd13_store8:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_scr_getc
		STA		(_ptr06),Y
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd16_store16:
		JSR		_scr_getc
		STA		_ptr06
		JSR		_scr_getc
		STA		_ptr06+1
		JSR		_scr_getc
		STA		(_ptr06),Y
		JSR		_scr_getc
		INY
		STA		(_ptr06),Y
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd18_sbcc_break:
		LDA		_nsub_return_flags
		PHA
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		TAX
		PLA
		LSR
		BCS		_j_scr_pc_incA

; =============== S U B R O U T I N E =======================================
_scr_break:
		STX		_scr_pc+1
		LDA		_tmp0
		STA		_scr_pc
		LDX		_scr_cur_trd_idxw
		LDA		_scr_trds_sp,X
		SEC
		SBC		#$03
		STA		_scr_trds_sp,X
		RTS

; =============== S U B R O U T I N E =======================================
_j_scr_pc_incA:
		JMP		_scr_pc_inc

; =============== S U B R O U T I N E =======================================
_scmd17_sbcs_break:
		LDA		_nsub_return_flags
		PHA
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		TAX
		PLA
		LSR
		BCC		_j_scr_pc_incA
		BCS		_scr_break

; =============== S U B R O U T I N E =======================================
_scr_getc:
		INC		_scr_pc
		BNE		loc_636DD
		INC		_scr_pc+1
loc_636DD:
		LDA		(_scr_pc),Y
		RTS

; =============== S U B R O U T I N E =======================================
_scr_pc_inc:
		INC		_scr_pc
		BNE		locret_636E6
		INC		_scr_pc+1
locret_636E6:
		RTS

_inv_bitmask_unref:
		.BYTE	$7F,$BF,$DF,$EF,$F7,$FB,$FD,$FE
_bit_mask:
		.BYTE	$80,$40,$20,$10,$08,$04,$02,$01

; =============== S U B R O U T I N E =======================================
_ppu_spr_shuffle_pos:
		LDA		_spr_buf_pos
		CMP		#$21
		BCS		loc_63702
		SBC		#$1F
		JMP		loc_63706
loc_63702:
		LDA		_spr_buf_shuffle
		ADC		#$DF
loc_63706:
		STA		_spr_buf_shuffle
		STA		_spr_buf_pos
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_spr_clear:
		LDA		#$F0
		LDY		_spr_buf_pos
loc_6370F:
		STA		_ppu_spr_buf,Y
		INY
		INY
		INY
		INY
		CPY		_spr_buf_shuffle
		BNE		loc_6370F
		RTS

; =============== S U B R O U T I N E =======================================
_spr_clip_pause_player_insert:
		STA		_tmp0
		TYA
		PHA
		LDY		_tmp0
		LDA		_spr_pause_player_lib_lo,Y
		STA		_ptr08
		LDA		_spr_pause_player_lib_hi,Y
		STA		_ptr08+1
		PLA
		TAY

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
_spr_clip_insert:
		STX		_tmp1
		STY		_tmp2

; REGION: replaced in the US version, linked with optmized portion of the code above.
; =============== S U B R O U T I N E =======================================
;_spr_clip_insert_ex:
;		LDA		_tmp2
		TYA
; -
		BNE		loc_6373A
		LDA		_tmpD9
		EOR		#$01
		STA		_tmpD9
loc_6373A:
		DEC		_tmp2
		LDX		_spr_buf_pos
; REGION, this also missing in the US proto version
		LDA		#$00
		STA		_ppu_spr_buf+3,X
; -
		TAY
		LDA		(_ptr08),Y
		STA		_var0
		INY
loc_63749:
		CLC
		LDA		(_ptr08),Y
		BPL		loc_6375D
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		LDA		_tmpD9
		SBC		#$00
		AND		#$01
		BEQ		loc_6376A
		BNE		loc_6379F
loc_6375D:
		ADC		_tmp2
		STA		_ppu_spr_buf,X
		LDA		_tmpD9
		ADC		#$00
		AND		#$01
		BNE		loc_6379F
loc_6376A:
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+1,X
		INY
		LDA		(_ptr08),Y
		STA		_ppu_spr_buf+2,X
		INY
		CLC
		LDA		(_ptr08),Y
		BPL		loc_6378B
		ADC		_tmp1
		STA		_ppu_spr_buf+3,X
		LDA		_tmpD8
		SBC		#$00
		AND		#$01
		BEQ		loc_63798
		BNE		loc_637A2
loc_6378B:
		ADC		_tmp1
		STA		_ppu_spr_buf+3,X
		LDA		_tmpD8
		ADC		#$00
		AND		#$01
		BNE		loc_637A2
loc_63798:
		INX
		INX
		INX
		INX
		JMP		loc_637A2
loc_6379F:
		INY
		INY
		INY
loc_637A2:
		INY
		DEC		_var0
		BNE		loc_63749
		STX		_spr_buf_pos
		RTS

; =============== S U B R O U T I N E =======================================
_jump_ptr_ind:
		JMP		(_ptr06)

; =============== S U B R O U T I N E =======================================
; this is a special thread loading routine to replace currently executing
; script for given thread with a new one with full reset of the execution
; flow. after this thread started from the beginning with all parameters
; reset but still have the same _scr_cur_trd_idx thus using the same data
; bank
;
_cur_thread_reload_param:
		LDX		_scr_cur_trd_idx

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
; in case we need to reload a script for a particular thread, nit the same one
; but all other is the same.
;
_thread_reload_param_ex:
		PLA
		STA		_ptr06
		PLA
		STA		_ptr06+1
		LDA		_ptr06
		CLC
		ADC		#$02
		STA		_tmp0
		LDA		_ptr06+1
		ADC		#$00
		PHA
		LDA		_tmp0
		PHA
		LDY		#$01
		LDA		(_ptr06),Y
		PHA
		INY
		LDA		(_ptr06),Y
		TAY
		PLA
		JMP		_thread_load

; =============== S U B R O U T I N E =======================================
_scr_cur_trd_off:
		LDX		_scr_cur_trd_idx
		LDA		#$FF
		STA		_scr_trds_idx,X
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_queue_reset:
		LDA		#$00
		STA		_ppu_queue_tail
		STA		_ppu_queue_head
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_nmi_off:
		LDA		_ppu_ctrl_shadow
		AND		#$7F

; =============== S U B R O U T I N E =======================================
_ppu_ctrl_write:
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_nmi_on:
		LDA		_ppu_ctrl_shadow
		ORA		#$80
		BNE		_ppu_ctrl_write

; =============== S U B R O U T I N E =======================================
_wait_for_nmi:
		PHA
		LDA		_ppu_ctrl_shadow
		BPL		loc_637FF
loc_637F5:
		LDA		_nmi_flag
		BEQ		loc_637F5
		LDA		#$00
		STA		_nmi_flag
		PLA
		RTS
loc_637FF:
		LDA		_PPU_STATUS
		BMI		loc_637FF
loc_63804:
		LDA		_PPU_STATUS
		BPL		loc_63804
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_vblank_off:
		LDA		#$00

; =============== S U B R O U T I N E =======================================
_ppu_vblank_ex:
		JSR		_wait_for_nmi
		STA		_PPU_MASK
		STA		_ppu_mask_shadow
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_vblank_on:
		LDA		_ppu_mask_req
		JSR		_ppu_vblank_ex
		JMP		_ppu_set_scroll

; =============== S U B R O U T I N E =======================================
; two shortcuts with manual loading of PPU offset goes here.
; note, there are no common raw/direct _nsub type ruotines for this kind of
; procedure (like it does for threads loading), so any rectangular areas has
; to be displayed from custom _nsubs for all particular case.
;
_ppu_res_send_ptr:
		STA		_ptr0A
		STY		_ptr0A+1
		LDA		#$00
		STA		_var3
		JMP		_ppu_res_send_ex

; =============== S U B R O U T I N E =======================================
_ppu_res_send_ptr_repeat:
		STA		_ptr0A
		STY		_ptr0A+1
		LDA		#$01
		STA		_var3
		JMP		_ppu_res_send_ex

; =============== S U B R O U T I N E =======================================

_ppu_res_send_param_repeat:
		STA		_tmp0
		LDA		#$01
		BNE		_ppu_res_send_param_ex

; =============== S U B R O U T I N E =======================================
_ppu_res_send_param_no_ofs:
		STA		_tmp0
		LDA		#$02
		BNE		_ppu_res_send_param_ex

; =============== S U B R O U T I N E =======================================
_ppu_res_send_param_repeat_no_ofs:
		STA		_tmp0
		LDA		#$03
		BNE		_ppu_res_send_param_ex

; =============== S U B R O U T I N E =======================================
; commonly used automatic routine goes here. a variety of routines above
; set the various combinations of flags for convinience.
;
_ppu_res_send_param:
		STA		_tmp0
		LDA		#$00

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
; parametric version of this routine.
;
_ppu_res_send_param_ex:
		STA		_var3
		STX		_tmp1
		STY		_tmp2
		PLA
		STA		_ptr06
		PLA
		STA		_ptr06+1
		LDY		#$01
		LDA		(_ptr06),Y
		STA		_ptr0A
		INY
		LDA		(_ptr06),Y
		STA		_ptr0A+1
		LDA		_ptr06
		CLC
		ADC		#$02
		STA		_ptr06
		BCC		loc_6386C
		INC		_ptr06+1
loc_6386C:
		LDA		_ptr06+1
		PHA
		LDA		_ptr06
		PHA

; !FALLTHROUGH!

; =============== S U B R O U T I N E =======================================
; common routine for sending data in specific format to PPU. as many of
; system//library routines here this one includes a lot of special cases
; which allows to use it in any game mode and you don't have to know if
; render is on or off (which is the case for many other games)..
; this routine checking current PPU status and decided how to send the data
; by self, wether the directly to PPU or via queue buffer.
; additionally, this routine has a special control flags (_var3) to be more
; flexible for various types of data. if flag 01 is set, routine switched in
; repeat mode. the data byte for the whole rect repeated a required number of
; times. flag 02 disables the PPU offset loading at the beginning of the resource
; so other code must load it manually beforehead.
; NOTE: as some other procedures here, it has an option never used in the game.
; when transferring rectangular screen tilemaps, it check additionally if
; it's width less than height and then will use procedure to vertical
; ppu increments, so this is an obvious optimization for speed, because of
; in this case there are less line feed operations... no rectangular resources
; in this game has height greater than width...
;
_ppu_res_send_ex:
		LDY		#$00
		LDA		_var3
		AND		#$02
		BNE		loc_63884
		LDA		(_ptr0A),Y
		STA		_ptr08
		INY
		LDA		(_ptr0A),Y
		STA		_ptr08+1
		INY
loc_63884:
		LDA		(_ptr0A),Y
		STA		_var1
		INY
		LDA		(_ptr0A),Y
		STA		_var2
		INY
		LDA		_var1
		CMP		_var2
		BCC		_vertical_mode
		LDX		_var2
.res_send_hor_loop:
		TXA
		PHA
		LDA		_ppu_mask_shadow
		BNE		.res_send_hor_queue
; REGION, replaced in the EU version
;		LDA		#$01
;		STA		_ppu_forbid_flag
		LDA		_ppu_ctrl_shadow
		PHA
		JSR		_ppu_nmi_off
; -
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_ptr08+1
		STA		_PPU_ADDR
		LDA		_ptr08
		STA		_PPU_ADDR
		LDX		_var1
loc_638B3:
		LDA		(_ptr0A),Y
		STA		_PPU_DATA
		LDA		_var3
		LSR
		BCS		loc_638C3
		INC		_ptr0A
		BNE		loc_638C3
		INC		_ptr0A+1
loc_638C3:
		DEX
		BNE		loc_638B3
; REGION, replaced in the EU version
;		LDA		#$00
;		STA		_ppu_forbid_flag
		PLA
		JSR		_ppu_ctrl_write
; -
		JMP		loc_638EC
.res_send_hor_queue:
		JSR		_ppu_queue_putw
		LDX		_var1
		TXA
		JSR		_ppu_queue_putc
loc_638D6:
		LDA		(_ptr0A),Y
		JSR		_ppu_queue_putc
		LDA		_var3
		LSR
		BCS		loc_638E6
		INC		_ptr0A
		BNE		loc_638E6
		INC		_ptr0A+1
loc_638E6:
		DEX
		BNE		loc_638D6
		JSR		_ppu_queue_head_update
loc_638EC:
		LDA		_ptr08
		CLC
		ADC		#$20
		STA		_ptr08
		BCC		loc_638F7
		INC		_ptr08+1
loc_638F7:
		PLA
		TAX
		DEX
		BNE		.res_send_hor_loop
		LDA		_tmp0
		LDX		_tmp1
		LDY		_tmp2
		RTS
; NOTE: there are no resources with vertical rectangles, so this
; branch never used
_vertical_mode:
		LDA		_ptr08+1
		ORA		#$80
		STA		_ptr08+1
		LDX		_var1
.res_send_vert_loop:
		TXA
		PHA
		LDA		_ptr0A
		PHA
		LDA		_ptr0A+1
		PHA
		LDA		_ppu_mask_shadow
		BNE		.res_send_vert_queue
; REGION, replaced in the EU version
;		LDA		#$01
;		STA		_ppu_forbid_flag
		LDA		_ppu_ctrl_shadow
		PHA
		JSR		_ppu_nmi_off
; -
		LDA		_ppu_ctrl_shadow
		ORA		#$04
		STA		_PPU_CTRL
		LDA		_ptr08+1
		AND		#$7F
		STA		_PPU_ADDR
		LDA		_ptr08
		STA		_PPU_ADDR
		LDX		_var2
loc_63932:
		LDA		(_ptr0A),Y
		STA		_PPU_DATA
		LDA		_var3
		LSR
		BCS		loc_63947
		LDA		_ptr0A
		CLC
		ADC		_var1
		STA		_ptr0A
		BCC		loc_63947
		INC		_ptr0A+1
loc_63947:
		DEX
		BNE		loc_63932
; REGION, replaced in the EU version
;		LDA		#$00
;		STA		_ppu_forbid_flag
		PLA
		JSR		_ppu_ctrl_write
; -
		JMP		loc_63975
.res_send_vert_queue:
		JSR		_ppu_queue_putw
		LDX		_var2
		TXA
		JSR		_ppu_queue_putc
loc_6395A:
		LDA		(_ptr0A),Y
		JSR		_ppu_queue_putc
		LDA		_var3
		LSR
		BCS		loc_6396F
		LDA		_ptr0A
		CLC
		ADC		_var1
		STA		_ptr0A
		BCC		loc_6396F
		INC		_ptr0A+1
loc_6396F:
		DEX
		BNE		loc_6395A
		JSR		_ppu_queue_head_update
loc_63975:
		INC		_ptr08
		BNE		loc_6397B
		INC		_ptr08+1
loc_6397B:
		PLA
		STA		_ptr0A+1
		PLA
		STA		_ptr0A
		LDA		_var3
		LSR
		BCS		loc_6398C
		INC		_ptr0A
		BNE		loc_6398C
		INC		_ptr0A+1
loc_6398C:
		PLA
		TAX
		DEX
		BEQ		loc_63994
		JMP		.res_send_vert_loop
loc_63994:
		LDA		_tmp0
		LDX		_tmp1
		LDY		_tmp2
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_queue_reset_unref:
		LDA		_ppu_queue_tail
		STA		_ppu_queue_head
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_queue_putw:
		LDA		_ppu_queue_head
		SEC
		SBC		_ppu_queue_tail
		CMP		#$40
		BCC		loc_639AF
		JSR		_wait_for_nmi
		JMP		_ppu_queue_putw
loc_639AF:
		STX		_var4
		LDX		_ppu_queue_head
		LDA		_ptr08+1
		STA		_ppu_queue_data,X
		INX
		LDA		_ptr08
		STA		_ppu_queue_data,X
		INX
		STX		_ppu_queue_pos
		LDX		_var4
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_queue_putc:
		STX		_var4
		LDX		_ppu_queue_pos
		STA		_ppu_queue_data,X
		INC		_ppu_queue_pos
		LDX		_var4
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_queue_head_update:
		LDA		_ppu_queue_pos
		STA		_ppu_queue_head
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_dequeue:
		LDA		_ppu_queue_tail
		STA		_ppu_queue_tail_tmp
		CMP		_ppu_queue_head
		BNE		loc_639DE
		RTS
loc_639DE:
		LDA		_ppu_queue_tail
		SEC
		SBC		_ppu_queue_tail_tmp
		CMP		#$30
		BCS		locret_63A30
		LDX		_ppu_queue_tail
		LDA		_ppu_queue_data,X
		INX
		STA		_tmp1A
		AND		#$7F
		STA		_PPU_ADDR
		LDA		_ppu_queue_data,X
		INX
		STA		_PPU_ADDR
		LDA		_ppu_ctrl_shadow
		LDY		_tmp1A
		BPL		loc_63A03
		ORA		#$04
loc_63A03:
		STA		_PPU_CTRL
		LDY		_ppu_queue_data,X
		INX
loc_63A0A:
		LDA		_ppu_queue_data,X
		INX
		STA		_PPU_DATA
		DEY
		BNE		loc_63A0A
		LDA		_tmp1A
		CMP		#$3F
		BNE		loc_63A2A
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
loc_63A2A:
		STX		_ppu_queue_tail
		CPX		_ppu_queue_head
		BNE		loc_639DE
locret_63A30:
		RTS

; =============== S U B R O U T I N E =======================================
_get_input:
		JSR		_read_pads
		STA		_tmp1A
		JSR		_read_pads
		AND		_tmp1A
		STA		_tmp1B
		JSR		_read_pads
		STA		_tmp1A
		JSR		_read_pads
		AND		_tmp1A
		ORA		_tmp1B
		STA		_tmp1A
		LDA		_pad0_held
		EOR		#$FF
		AND		_tmp1A
		STA		_pad0_pressed
		LDA		_tmp1A
		STA		_pad0_held
		RTS

; =============== S U B R O U T I N E =======================================
_read_pads:
		LDX		#$01
		STX		_PAD0_REG
		DEX
		STX		_PAD0_REG
		LDY		#$08
loc_63A63:
		PHA
		LDA		_PAD0_REG
		STA		_tmp19
		LSR
		ORA		_tmp19
		LSR
		PLA
		ROL
		DEY
		BNE		loc_63A63
		RTS

; =============== S U B R O U T I N E =======================================
_ppu_spr_fill_F1:
		LDX		#$00
		LDA		#$F1
loc_63A77:
		STA		_ppu_spr_buf,X
		INX
		BNE		loc_63A77
		RTS

; =============== S U B R O U T I N E =======================================
NMI:
		PHA
		TXA
		PHA
		TYA
		PHA
		LDA		#$00
		STA		_PPU_OAM_ADDR
		LDA		#$02
		STA		_PPU_OAM_DMA
; REGION, added in EU version
;		LDA		_ppu_forbid_flag
;		BNE
; -
		JSR		_ppu_dequeue
		JSR		_ppu_set_scroll
;loc_63AA1:
		INC		_nmi_flag
		INC		_nmi_counter
		JSR		_get_input
		LDA		_mmc1_busy
		BEQ		loc_63AA2
		STA		_apu_play_delayed_req
		BNE		loc_63ADF
loc_63AA2:
		LDA		_chr_bank0
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LSR
		STA		$BFFF
		LDA		_chr_bank1
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LSR
		STA		$DFFF
		LDA		_prg_cur_bank
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg
		JSR		_apu_play
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg
loc_63ADF:
		PLA
		TAY
		PLA
		TAX
		PLA
		RTI

; =============== S U B R O U T I N E =======================================
_ppu_set_scroll:
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		_ppu_scroll_pos_x+1
		EOR		_ppu_scroll_pos_y+1
		LSR
		PHP
		LDA		_ppu_scroll_pos_y+1
		EOR		_ppu_scroll_pos_x+1
		LSR
		PHP
		LDA		_ppu_ctrl_shadow
		LSR
		LSR
		PLP
		ROL
		PLP
		ROL
		STA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_ppu_scroll_pos_x
		STA		_PPU_SCROLL
		LDA		_ppu_scroll_pos_y
		STA		_PPU_SCROLL
		RTS

; =============== S U B R O U T I N E =======================================
_mmc1_ctrl:
		STA		_mmc1_ctrl_shadow
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		LSR
		STA		$9FFF
		RTS

; =============== S U B R O U T I N E =======================================
_mmc1_prg_safe:
		PHA								; very safe bank switching routine and
		STA		_prg_bank				; very SLOOOOOW because of that sometimes
		LDA		_mmc1_busy				; backup busy flag, however thechnically
		PHA								; no one else set it, so we basicly just
		LDA		#$01					; save zero then restore it, thus clear it again
		STA		_mmc1_busy				; set our own busy flag, now when nmi
		LDA		_prg_bank				; occurs, it will skip any mapper operations
		STA		$FFF9					; this includes calling apu player routine
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		PLA
		STA		_mmc1_busy				; so after changing the bank here, we need to
		LDA		_apu_play_delayed_req	; test if nmi occurs in the middle of process
		BEQ		loc_63B6E				; if yes, then we need to call apu player manually
		LDA		#$00					; this preventing music from slow downs when
		STA		_apu_play_delayed_req	; frames skipped.
		TXA								; also backup current X,Y registers here
		PHA								; to not to break something in caller code
		TYA
		PHA
		LDA		_prg_cur_bank
		PHA
		LDA		#$06
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		JSR		_apu_play
		PLA
		STA		_prg_cur_bank
		JSR		_mmc1_prg_safe
		PLA
		TAY
		PLA
		TAX
loc_63B6E:
		PLA
		RTS

; =============== S U B R O U T I N E =======================================
_mmc1_prg:
		STA		$FFF9					; fastest raw routine to switch banks in mmc1
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		LSR
		STA		$FFF9
		RTS

; =============== S U B R O U T I N E =======================================
IRQ:
		RTI

; NOTE: flags used to additionally load external arguments for selected script
; index. bits 80, 40 and 20 are corresponds to ARG0, ARG1, ARG2 additionally
; loaded values.
_scr_flags:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$80,$40,$00
		.BYTE	$00,$00,$60,$00,$00,$00,$00,$00,$00,$00,$20,$40,$00,$00,$00,$00
		.BYTE	$40,$80,$00,$00,$40,$40,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00
_scr_bank_lib:
		.BYTE	$00,$01,$01,$01,$01,$01,$01,$00,$01,$01,$01,$01,$01,$01,$04,$04
		.BYTE	$04,$04,$01,$04,$04,$04,$04,$04,$04,$04,$03,$04,$04,$04,$04,$04
		.BYTE	$04,$04,$03,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$04,$03,$03
		.BYTE	$03
_scr_lib_lo:
;		SYSTEM scripts, never used in level objects lists, ran manually
; 		by the system or by the other scripts
;
		SCR_IDX_LO	_scr00_intro_title_select
		SCR_IDX_LO	_scr01_lvl1_handler
		SCR_IDX_LO	_scr02_lvl2_handler
		SCR_IDX_LO	_scr03_lvl3_handler
		SCR_IDX_LO	_scr04_lvl4_handler
		SCR_IDX_LO	_scr05_lvl5_handler
		SCR_IDX_LO	_scr06_lvl6_handler
		SCR_IDX_LO	_scr07_ending
		SCR_IDX_LO	_scr08_beamer_handler
		SCR_IDX_LO	_scr09_player_beam
		SCR_IDX_LO	_scr0A_catcher_handler
		SCR_IDX_LO	_scr0B_player_catch
		SCR_IDX_LO	_scr0C_room_doors_handler
; 		GAME OBJECT scripts, used in the level objects lists, may run
;		other instances of self
;
		SCR_IDX_LO	_scr0D_money_bag
		SCR_IDX_LO	_scr0E_empty_mine_trolley	; except this
		SCR_IDX_LO	_scr0F_candle
		SCR_IDX_LO	_scr10_train_semaphores
		SCR_IDX_LO	_scr11_lvl2_ghost_nanny
		SCR_IDX_LO	_scr12_exit_arrow
		SCR_IDX_LO	_scr13_slow_moving_slime
		SCR_IDX_LO	_scr14_fast_moving_slime
		SCR_IDX_LO	_scr15_trolley_kick_slime
		SCR_IDX_LO	_scr16_still_throw_forward_slime
		SCR_IDX_LO	_scr17_runner
		SCR_IDX_LO	_scr18_chain_saw
		SCR_IDX_LO	_scr19_toilet_snake
		SCR_IDX_LO	_scr1A_lvl1_boss_judges
		SCR_IDX_LO	_scr1B_court_chair
		SCR_IDX_LO	_scr1C_girl_and_floaters
		SCR_IDX_LO	_scr1D_air_hammer_miner
		SCR_IDX_LO	_scr1E_pick_axe_miner
		SCR_IDX_LO	_scr1F_hammer_miner
		SCR_IDX_LO	_scr20_trolley_miner
		SCR_IDX_LO	_scr21_train_ghost
		SCR_IDX_LO	_scr22_lvl2_boss_train_slime
		SCR_IDX_LO	_scr23_halloween
		SCR_IDX_LO	_scr24_flying_wing_elephant
		SCR_IDX_LO	_scr25_stinging_wing_elephant
		SCR_IDX_LO	_scr26_sword_ninja
		SCR_IDX_LO	_scr27_shuriken_ninja
		SCR_IDX_LO	_scr28_pink_goo
		SCR_IDX_LO	_scr29_sewer_worm
		SCR_IDX_LO	_scr2A_morning_star_troll
		SCR_IDX_LO	_scr2B_still_throw_ballistic_slime
		SCR_IDX_LO	_scr2C_fast_throw_forward_slime
		SCR_IDX_LO	_scr2D_rotator
		SCR_IDX_LO	_scr2E_lvl4_boss_dragons
		SCR_IDX_LO	_scr2F_lvl5_boss_key_keeper
		SCR_IDX_LO	_scr30_lvl6_boss_vega
_scr_lib_hi:
		SCR_IDX_HI	_scr00_intro_title_select
		SCR_IDX_HI	_scr01_lvl1_handler
		SCR_IDX_HI	_scr02_lvl2_handler
		SCR_IDX_HI	_scr03_lvl3_handler
		SCR_IDX_HI	_scr04_lvl4_handler
		SCR_IDX_HI	_scr05_lvl5_handler
		SCR_IDX_HI	_scr06_lvl6_handler
		SCR_IDX_HI	_scr07_ending
		SCR_IDX_HI	_scr08_beamer_handler
		SCR_IDX_HI	_scr09_player_beam
		SCR_IDX_HI	_scr0A_catcher_handler
		SCR_IDX_HI	_scr0B_player_catch
		SCR_IDX_HI	_scr0C_room_doors_handler
		SCR_IDX_HI	_scr0D_money_bag
		SCR_IDX_HI	_scr0E_empty_mine_trolley
		SCR_IDX_HI	_scr0F_candle
		SCR_IDX_HI	_scr10_train_semaphores
		SCR_IDX_HI	_scr11_lvl2_ghost_nanny
		SCR_IDX_HI	_scr12_exit_arrow
		SCR_IDX_HI	_scr13_slow_moving_slime
		SCR_IDX_HI	_scr14_fast_moving_slime
		SCR_IDX_HI	_scr15_trolley_kick_slime
		SCR_IDX_HI	_scr16_still_throw_forward_slime
		SCR_IDX_HI	_scr17_runner
		SCR_IDX_HI	_scr18_chain_saw
		SCR_IDX_HI	_scr19_toilet_snake
		SCR_IDX_HI	_scr1A_lvl1_boss_judges
		SCR_IDX_HI	_scr1B_court_chair
		SCR_IDX_HI	_scr1C_girl_and_floaters
		SCR_IDX_HI	_scr1D_air_hammer_miner
		SCR_IDX_HI	_scr1E_pick_axe_miner
		SCR_IDX_HI	_scr1F_hammer_miner
		SCR_IDX_HI	_scr20_trolley_miner
		SCR_IDX_HI	_scr21_train_ghost
		SCR_IDX_HI	_scr22_lvl2_boss_train_slime
		SCR_IDX_HI	_scr23_halloween
		SCR_IDX_HI	_scr24_flying_wing_elephant
		SCR_IDX_HI	_scr25_stinging_wing_elephant
		SCR_IDX_HI	_scr26_sword_ninja
		SCR_IDX_HI	_scr27_shuriken_ninja
		SCR_IDX_HI	_scr28_pink_goo
		SCR_IDX_HI	_scr29_sewer_worm
		SCR_IDX_HI	_scr2A_morning_star_troll
		SCR_IDX_HI	_scr2B_still_throw_ballistic_slime
		SCR_IDX_HI	_scr2C_fast_throw_forward_slime
		SCR_IDX_HI	_scr2D_rotator
		SCR_IDX_HI	_scr2E_lvl4_boss_dragons
		SCR_IDX_HI	_scr2F_lvl5_boss_key_keeper
		SCR_IDX_HI	_scr30_lvl6_boss_vega

_spr_raw_lib_lo:
		.BYTE	<[_spr_raw_lib00]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib07]
		.BYTE	<[_spr_raw_lib08]
		.BYTE	<[_spr_raw_lib09]
		.BYTE	<[_spr_raw_lib08]
		.BYTE	<[_spr_raw_lib09]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib01]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib11]
		.BYTE	<[_spr_raw_lib08]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib11]
		.BYTE	<[_spr_raw_lib11]
		.BYTE	<[_spr_raw_lib11]
		.BYTE	<[_spr_raw_lib1A]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib11]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib1A]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib11]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0E]
		.BYTE	<[_spr_raw_lib0F]
		.BYTE	<[_spr_raw_lib1A]
		.BYTE	<[_spr_raw_lib1A]
		.BYTE	<[_spr_raw_lib1A]
_spr_raw_lib_hi:
		.BYTE	>[_spr_raw_lib00]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib07]
		.BYTE	>[_spr_raw_lib08]
		.BYTE	>[_spr_raw_lib09]
		.BYTE	>[_spr_raw_lib08]
		.BYTE	>[_spr_raw_lib09]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib01]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib11]
		.BYTE	>[_spr_raw_lib08]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib11]
		.BYTE	>[_spr_raw_lib11]
		.BYTE	>[_spr_raw_lib11]
		.BYTE	>[_spr_raw_lib1A]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib11]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib1A]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib11]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0E]
		.BYTE	>[_spr_raw_lib0F]
		.BYTE	>[_spr_raw_lib1A]
		.BYTE	>[_spr_raw_lib1A]
		.BYTE	>[_spr_raw_lib1A]
_spr_res_lib_lo:
		.BYTE	$87		; *--
		.BYTE	$D6		; *--
		.BYTE	$D6		; *--
		.BYTE	$D6		; *--
		.BYTE	$D6		; *--
		.BYTE	$D6		; *--
		.BYTE	$D6		; *--
		.BYTE	<[_spr_res_lib07]
		.BYTE	$73		; *--
		.BYTE	$D3		; *--
		.BYTE	$73		; *--
		.BYTE	$D3		; *--
		.BYTE	$D6		; *--
		.BYTE	$D6		; *--
		.BYTE	$52		; *--
		.BYTE	<[_spr_res_lib0F]	; *--
		.BYTE	<[_spr_res_lib0F]	; *--
		.BYTE	<[_spr_res_lib11]	; *--
		.BYTE	$73		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	<[_spr_res_lib11]	; *--
		.BYTE	<[_spr_res_lib11]	; *--
		.BYTE	<[_spr_res_lib11]	; *--
		.BYTE	<[_spr_res_lib1A]	; *--
		.BYTE	$52		; *--
		.BYTE	<[_spr_res_lib11]	; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	<[_spr_res_lib0F]
		.BYTE	<[_spr_res_lib0F]
		.BYTE	<[_spr_res_lib0F]
		.BYTE	<[_spr_res_lib0F]	; *--
		.BYTE	<[_spr_res_lib0F]	; *--
		.BYTE	<[_spr_res_lib0F]
		.BYTE	<[_spr_res_lib0F]	; *--
		.BYTE	<[_spr_res_lib11]
		.BYTE	$52		; *--
		.BYTE	$52		; *--
		.BYTE	<[_spr_res_lib0F]	; *--
		.BYTE	<[_spr_res_lib1A]	; *--
		.BYTE	<[_spr_res_lib1A]	; *--
		.BYTE	<[_spr_res_lib1A]
_spr_res_lib_hi:
		.BYTE	$92		; *--
		.BYTE	$A9		; *--
		.BYTE	$A9		; *--
		.BYTE	$A9		; *--
		.BYTE	$A9		; *--
		.BYTE	$A9		; *--
		.BYTE	$A9		; *--
		.BYTE	>[_spr_res_lib07]
		.BYTE	$D7		; *--
		.BYTE	$D7		; *--
		.BYTE	$D7		; *--
		.BYTE	$D7		; *--
		.BYTE	$A9		; *--
		.BYTE	$A9		; *--
		.BYTE	$94		; *--
		.BYTE	>[_spr_res_lib0F]	; *--
		.BYTE	>[_spr_res_lib0F]	; *--
		.BYTE	>[_spr_res_lib11]	; *--
		.BYTE	$D7		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	>[_spr_res_lib11]	; *--
		.BYTE	>[_spr_res_lib11]	; *--
		.BYTE	>[_spr_res_lib11]	; *--
		.BYTE	>[_spr_res_lib1A]	; *--
		.BYTE	$94		; *--
		.BYTE	>[_spr_res_lib11]	; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	>[_spr_res_lib0F]
		.BYTE	>[_spr_res_lib0F]
		.BYTE	>[_spr_res_lib0F]
		.BYTE	>[_spr_res_lib0F]	; *--
		.BYTE	>[_spr_res_lib0F]	; *--
		.BYTE	>[_spr_res_lib0F]
		.BYTE	>[_spr_res_lib0F]	; *--
		.BYTE	>[_spr_res_lib11]
		.BYTE	$94		; *--
		.BYTE	$94		; *--
		.BYTE	>[_spr_res_lib0F]	; *--
		.BYTE	>[_spr_res_lib1A]	; *--
		.BYTE	>[_spr_res_lib1A]	; *--
		.BYTE	>[_spr_res_lib1A]

_spr_pause_player_lib_lo:
		.BYTE	<[_spr_raw_lib08_0A]
		.BYTE	<[_spr_raw_lib08_09]
		.BYTE	<[_spr_raw_lib08_0A]
		.BYTE	<[_spr_raw_lib08_0B]
		.BYTE	<[_spr_raw_lib08_1A]
		.BYTE	<[_spr_raw_lib08_19]
		.BYTE	<[_spr_raw_lib08_1A]
		.BYTE	<[_spr_raw_lib08_1B]
		.BYTE	<[_spr_raw_lib08_2A]
		.BYTE	<[_spr_raw_lib08_29]
		.BYTE	<[_spr_raw_lib08_2A]
		.BYTE	<[_spr_raw_lib08_2B]
		.BYTE	<[_spr_raw_lib08_3A]
		.BYTE	<[_spr_raw_lib08_39]
		.BYTE	<[_spr_raw_lib08_3A]
		.BYTE	<[_spr_raw_lib08_3B]
		.BYTE	<[_spr_raw_lib08_4A]
		.BYTE	<[_spr_raw_lib08_49]
		.BYTE	<[_spr_raw_lib08_4A]
		.BYTE	<[_spr_raw_lib08_4B]
_spr_pause_player_lib_hi:
		.BYTE	>[_spr_raw_lib08_0A]
		.BYTE	>[_spr_raw_lib08_09]
		.BYTE	>[_spr_raw_lib08_0A]
		.BYTE	>[_spr_raw_lib08_0B]
		.BYTE	>[_spr_raw_lib08_1A]
		.BYTE	>[_spr_raw_lib08_19]
		.BYTE	>[_spr_raw_lib08_1A]
		.BYTE	>[_spr_raw_lib08_1B]
		.BYTE	>[_spr_raw_lib08_2A]
		.BYTE	>[_spr_raw_lib08_29]
		.BYTE	>[_spr_raw_lib08_2A]
		.BYTE	>[_spr_raw_lib08_2B]
		.BYTE	>[_spr_raw_lib08_3A]
		.BYTE	>[_spr_raw_lib08_39]
		.BYTE	>[_spr_raw_lib08_3A]
		.BYTE	>[_spr_raw_lib08_3B]
		.BYTE	>[_spr_raw_lib08_4A]
		.BYTE	>[_spr_raw_lib08_49]
		.BYTE	>[_spr_raw_lib08_4A]
		.BYTE	>[_spr_raw_lib08_4B]

;		ORG [[.+$3F] & $FFC0]
		ORG		$FD80
_pcm0:
		.BYTE	$55,$55,$55,$95,$AA,$2A,$95,$E0,$7F,$FC,$C0,$F1,$03,$28,$FE,$FF ;	pcm data
		.BYTE	$FF,$F1,$5F,$3F,$00,$00,$00,$00,$00,$00,$08,$80,$C0,$F1,$FF,$C7
		.BYTE	$8B,$1F,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$AB,$6A,$9B,$AA,$92,$52,$25
		.BYTE	$95,$24,$25,$92,$80,$4A,$50,$05,$00,$00,$80,$20,$42,$04,$08,$E2
		.BYTE	$FF,$01,$80,$6D,$AB,$6D,$DF,$BB,$77,$7B,$AB,$AF,$DD,$D5,$7D,$DD
		.BYTE	$BF,$FF,$EF,$B6,$6D,$6F,$BB,$6D,$AF,$2A,$95,$94,$24,$49,$92,$88
_pcm0B_size	EQU [[.-_pcm0]>>4]
		.BYTE	$42,$84,$48,$88,$04,$09,$49,$92,$24,$51,$22,$A5,$92,$22,$49,$AA
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_pcm0A_size	EQU [[.-_pcm0]>>4]
_pcm0A_addr	EQU [[_pcm0-$C000]>>6]
_pcm0B_addr	EQU _pcm0A_addr

;		ECHO	"_pcm0 addr=",_pcm0_addr,"size=",_pcm0_size

;		ORG [[.+$3F] & $FFC0]
		ORG		$FE00
_pcm1:
		.BYTE	$00,$68,$68,$00,$68,$68,$68,$68,$73,$00,$68,$68,$00,$68,$68,$68 ;	pcm data
		.BYTE	$68,$68,$68,$68,$68,$68,$68,$00,$68,$68,$00,$68,$68,$73,$00,$68
		.BYTE	$68,$00,$68,$68,$00,$68,$68,$00,$68,$68,$00,$68,$68,$00,$68,$FF
		.BYTE	$41,$10,$00,$21,$92,$20,$00,$F4,$38,$56,$5D,$EB,$F9,$9D,$3C,$BF
		.BYTE	$ED,$E7,$D7,$AA,$6C,$59,$16,$A2,$00,$61,$83,$F0,$72,$3A,$0B,$81
		.BYTE	$45,$41,$09,$DA,$F1,$FD,$FF,$FF,$5E,$AF,$C4,$4B,$D3,$C9,$8A,$82
		.BYTE	$24,$89,$28,$06,$02,$47,$55,$E1,$3D,$AE,$EF,$BC,$F4,$52,$D5,$55
		.BYTE	$BD,$BC,$7A,$1E,$57,$51,$0A,$25,$29,$A8,$A8,$38,$69,$D3,$88,$AA
		.BYTE	$18,$78,$6C,$BA,$DE,$7D,$ED,$FB,$43,$E7,$34,$4C,$2C,$25,$AD,$92
		.BYTE	$A4,$51,$A5,$C8,$62,$E2,$06,$8D,$C7,$F1,$AD,$65,$37,$B4,$AC,$5A
		.BYTE	$4D,$9F,$3E,$6D,$3C,$A5,$B2,$24,$A9,$A2,$92,$86,$A9,$44,$45,$EE
		.BYTE	$2C,$5E,$AA,$2D,$AE,$53,$9F,$4A,$9D,$3D,$4E,$8D,$3B,$8A,$A9,$E5
		.BYTE	$C8,$B2,$2C,$34,$52,$D4,$59,$B1,$D2,$8A,$55,$C3,$5B,$A9,$55,$8B
		.BYTE	$76,$7C,$79,$6C,$2B,$CE,$F2,$64,$31,$8E,$64,$45,$72,$64,$D1,$92
		.BYTE	$E3,$54,$AD,$5A,$35,$55,$D7,$58,$1E,$1D,$55,$4E,$1D,$57,$56,$55
		.BYTE	$CB,$AA,$AA,$2A,$69,$A5,$4A,$AA,$AA,$4A,$4D,$6A,$31,$4D,$D3,$A9
		.BYTE	$6A,$AD,$7A,$5C,$65,$AB,$AA,$AC,$CA,$72,$AA,$4A,$B5,$D0,$8A,$95
		.BYTE	$AC,$54,$95,$6C,$D9,$52,$5B,$A5,$AA,$D5,$4A,$B5,$2C,$4B,$B6,$D4
		.BYTE	$34,$9D,$95,$56,$55,$55,$55,$55,$9A,$2A,$15,$A7,$AA,$52,$2D,$55
		.BYTE	$69,$95,$B6,$AA,$65,$D5,$6A,$AA,$5A,$EA,$58,$55,$69,$6A,$A9,$96
		.BYTE	$D2,$34,$95,$53,$A9,$A9,$2A,$35,$55,$D3,$AA,$6A,$55,$B5,$E2,$AA
		.BYTE	$34,$B5,$9C,$C6,$B1,$95,$AA,$A9,$AA,$B4,$52,$55,$8B,$A9,$9A,$A6
		.BYTE	$AA,$9A,$5A,$6A,$A5,$56,$56,$65,$55,$55,$AD,$B4,$B2,$AA,$54,$55
		.BYTE	$2D,$D5,$AA,$AC,$AA,$52,$2B,$4B,$95,$AA,$AA,$B2,$2A,$AB,$AA,$6A
		.BYTE	$A5,$55,$D5,$B4,$AA,$AA,$AA,$A9,$AA,$AA,$52,$55,$59,$A9,$A5,$AA
		.BYTE	$56,$5A,$A5,$95,$55,$55,$55,$55,$55,$55,$55,$55,$55,$55,$55,$55
		.BYTE	$55,$55,$55,$55,$55,$55,$53,$35,$55,$D5,$54,$55,$55,$55,$A9,$A5
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_pcm1_size	EQU [[.-_pcm1]>>4]
_pcm1_addr	EQU [[_pcm1-$C000]>>6]

;		ECHO	"_pcm1 addr=",_pcm1_addr,"size=",_pcm1_size

		LAST_BANK_END 7,$10000

total_banks	= 8
total_size	= 8*16384
