
		ORG $8000

		BANK_START $06

		SECTION_START

; =============== S U B R O U T I N E ======n================================
_apu_reset:
		LDX		#$00
		STX		_APU_DMC_LOAD
		DEX
		STX		_apu_snd_volume
		STX		_apu_mus_volume
		STX		_apu_var580
		LDX		#$0F
		STX		_APU_STATUS
		LDX		#$0F
		LDA		#$0E
loc_50018:
		STA		_apu_reg_pulse0_C,X
		DEX
		BPL		loc_50018
		LDA		#$FF
		JSR		_apu_mus_load
		LDA		#$FF

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_apu_snd_load:
		STA		_tmp0
		TXA
		PHA
		TYA
		PHA
		LDA		_tmp0
		JSR		_apu_snd_load_ex
		PLA
		TAY
		PLA
		TAX
		RTS

; =============== S U B R O U T I N E ======n================================
_apu_snd_load_ex:
		TAX
		BPL		loc_5003B
		JMP		sub_500AE
loc_5003B:
		LDA		_apu_var403
		BEQ		loc_50062
		AND		_apu_snd_table0,X
		BEQ		loc_50062
		LDY		#$04
loc_50047:
		LDA		_apu_chnl_var0F,Y
		AND		_apu_snd_table0,X
		BEQ		loc_5005C
		LDA		_apu_chnl_var0F+5,Y
		CMP		_apu_snd_table1,X
		BCC		locret_50061
		LDA		#$00
		STA		_apu_mus_delay,Y
loc_5005C:
		DEY
		BPL		loc_50047
		BMI		loc_50062
locret_50061:
		RTS
loc_50062:
		STX		_apu_cur_snd_idx
		LDA		_apu_snd_table0,X
		STA		_apu_var404
		LDA		_apu_snd_table1,X
		STA		_var2
		TXA
		ASL
		TAX
		LDA		_snd_lib,X
		STA		_ptr08
		LDA		_snd_lib+1,X
		STA		_ptr08+1
		LDY		#$00
		LDA		(_ptr08),Y
		STA		_var1
		LDX		#$04
loc_50085:
		LDA		_apu_mus_delay,X
		BNE		loc_5009C
		JSR		apu_chnl_load
		PHP
		LDA		_var2
		STA		_apu_chnl_var0F+5,X
		LDA		_apu_var404
		STA		_apu_chnl_var0F,X
		PLP
		BEQ		sub_5009F
loc_5009C:
		DEX
		BPL		loc_50085

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
sub_5009F:
		LDA		_apu_chnl_var0F
		LDX		#$04
loc_500A4:
		ORA		_apu_chnl_var0F,X
		DEX
		BNE		loc_500A4
		STA		_apu_var403
		RTS

; =============== S U B R O U T I N E ======n================================
sub_500AE:
		LDX		#$04
loc_500B0:
		LDA		#$00
		STA		_apu_mus_delay,X
		STA		_apu_chnl_var0F,X
		LDA		#$FF
		STA		_apu_chnl_var0F+5,X
		DEX
		BPL		loc_500B0
		LDX		#$0F
loc_500C2:
		LDA		byte_500CC,X
		STA		_apu_reg_pulse0_A,X
		DEX
		BPL		loc_500C2
		RTS
byte_500CC:
		.BYTE	$30,$7F,$00,$FF,$30,$7F,$00,$FF,$00,$00,$00,$00,$30,$00,$00,$FF

; =============== S U B R O U T I N E ======n================================
apu_chnl_load:
		LDA		#$27
		STA		_apu_chnl_var06,X
		LDA		#$00
		STA		_apu_chnl_var08,X
		STA		_apu_chnl_var09,X
		STA		_apu_chnl_smpl,X
		STA		_apu_chnl_var0B,X
;		STA		_apu_chnl_freq_tbl,X
		LDA		_apu_stack_main_list,X
		STA		_apu_mus_sp,X
		INY
		LDA		(_ptr08),Y
		STA		_apu_mus_pc_lo,X
		INY
		LDA		(_ptr08),Y
		STA		_apu_mus_pc_hi,X
		INY
		LDA		(_ptr08),Y
		STA		_apu_chnl_type,X
		LDA		#$01
		STA		_apu_mus_delay,X
		STA		_apu_chnl_var05,X
		DEC		_var1
		RTS

; =============== S U B R O U T I N E ======n================================
_apu_mus_load:
		PHA
		LDX		#$04
loc_50118:
		LDA		#$00
		STA		_apu_mus_delay+5,X
		DEX
		BPL		loc_50118
		LDX		#$0F
loc_50122:
		LDA		byte_500CC,X
		STA		_apu_reg_pulse0_B,X
		DEX
		BPL		loc_50122
		PLA
		BMI		locret_50151
		ASL
		TAX
		LDA		_music_lib,X
		STA		_ptr08
		LDA		_music_lib+1,X
		STA		_ptr08+1
		LDY		#$00
		LDA		(_ptr08),Y
		STA		_var1
		LDX		#$09
loc_50142:
		LDA		_apu_mus_delay,X
		BNE		loc_5014C
		JSR		apu_chnl_load
		BEQ		locret_50151
loc_5014C:
		DEX
		CPX		#$04
		BNE		loc_50142
locret_50151:
		RTS

; =============== S U B R O U T I N E ======n================================
_apu_play:
		LDA		#$C0
		STA		_PAD1_REG
		LDX		#$09
loc_50159:
		LDA		_apu_mus_delay,X
		BEQ		loc_501A3
		LDA		off_5070F,X
		STA		_apu_ptr35
		LDA		off_50719,X
		STA		_apu_ptr35+1
		DEC		_apu_mus_delay,X
		BNE		loc_50184
		LDA		_apu_mus_pc_lo,X
		STA		_apu_cur_pc
		LDA		_apu_mus_pc_hi,X
		STA		_apu_cur_pc+1
		JSR		_apu_mus_fetch
		LDA		_apu_cur_pc
		STA		_apu_mus_pc_lo,X
		LDA		_apu_cur_pc+1
		STA		_apu_mus_pc_hi,X
loc_50184:
		JSR		sub_50523
		DEC		_apu_snd_delay,X
		BNE		loc_501A3
		LDA		_apu_snd_pc_lo,X
		STA		_apu_cur_pc
		LDA		_apu_snd_pc_hi,X
		STA		_apu_cur_pc+1
		JSR		_apu_snd_fetch
		LDA		_apu_cur_pc
		STA		_apu_snd_pc_lo,X
		LDA		_apu_cur_pc+1
		STA		_apu_snd_pc_hi,X
loc_501A3:
		DEX
		BPL		loc_50159
		LDX		#$04
loc_501A8:
		LDA		_apu_mus_delay,X
		BNE		loc_501B7
		LDA		#$FF
		STA		_apu_chnl_var0F+5,X
		LDA		#$00
		STA		_apu_chnl_var0F,X
loc_501B7:
		DEX
		BPL		loc_501A8
		JSR		sub_5009F
		LDA		_apu_var403
		LSR
		PHA
		LDX		#$00
		LDY		#$03
loc_501C6:
		PHP
		LDA		_apu_reg_pulse0_B,X
		BCC		loc_501CF
		LDA		_apu_reg_pulse0_A,X
loc_501CF:
		CMP		_apu_reg_pulse0_C,X
		BEQ		loc_501DA
		STA		_apu_reg_pulse0_C,X
		STA		_APU_PULSE1_ENV,X
loc_501DA:
		PLP
		INX
		DEY
		BPL		loc_501C6
		PLA
		LSR
		PHA
		LDX		#$00
		LDY		#$03
loc_501E6:
		PHP
		LDA		_apu_reg_pulse1_B,X
		BCC		loc_501EF
		LDA		_apu_reg_pulse1_A,X
loc_501EF:
		CMP		_apu_reg_pulse1_C,X
		BEQ		loc_501FA
		STA		_apu_reg_pulse1_C,X
		STA		_APU_PULSE2_ENV,X
loc_501FA:
		PLP
		INX
		DEY
		BPL		loc_501E6
		PLA
		LSR
		PHA
		LDX		#$00
		LDY		#$03
loc_50206:
		PHP
		LDA		_apu_reg_trian_B,X
		BCC		loc_5020F
		LDA		_apu_reg_trian_A,X
loc_5020F:
		CMP		_apu_reg_trian_C,X
		BEQ		loc_5021A
		STA		_apu_reg_trian_C,X
		STA		_APU_TRI_COUNT,X
loc_5021A:
		PLP
		INX
		DEY
		BPL		loc_50206
		PLA
		LSR
		LDX		#$03
loc_50223:
		PHP
		LDA		_apu_reg_noise_B,X
		BCC		loc_5022C
		LDA		_apu_reg_noise_A,X
loc_5022C:
		CMP		_apu_reg_noise_C,X
		BEQ		loc_50237
		STA		_apu_reg_noise_C,X
		STA		_APU_NOISE_ENV,X
loc_50237:
		PLP
		DEX
		BPL		loc_50223
		LDA		_APU_STATUS
		AND		#$10
		BNE		locret_50247
		LDA		#$7F
		STA		_APU_DMC_LOAD
locret_50247:
		RTS

_apu_noise_flag_mask:
		.BYTE	$08
_apu_dpcm_flag_mask:
		.BYTE	$10

; =============== S U B R O U T I N E ======n================================
_apu_mus_fetch_next:
		JSR		_apu_getc

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_apu_mus_fetch:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$E0
		CMP		#$E0
		BNE		_apu_mus_data_fetch
		JMP		_apu_mus_cmd_fetch

; =============== S U B R O U T I N E ======n================================
_apu_mus_data_fetch:
		LDA		_apu_chnl_type,X
		CMP		#$0C
		BNE		loc_50287
		LDA		(_apu_cur_pc),Y
		BIT		_apu_dpcm_flag_mask
		BNE		loc_50275
		AND		#$0F
		CMP		#$0F
		BEQ		loc_502A0
		LDY		#$0E
		STA		(_apu_ptr35),Y
		JMP		loc_502B7
loc_50275:
		AND		#$0F
		STA		_APU_DMC_FREQ
		LDA		#$0F
		STA		_APU_STATUS
		LDA		#$1F
		STA		_APU_STATUS
		JMP		loc_502B7
loc_50287:
		LDA		(_apu_cur_pc),Y
		AND		#$1F
		CMP		#$10
		BEQ		loc_502A0
		BIT		_apu_dpcm_flag_mask
		BEQ		loc_50296
		ORA		#$E0
loc_50296:
		CLC
		ADC		_apu_chnl_var06,X
		JSR		sub_504E8
		JMP		loc_502B7
loc_502A0:
		JSR		sub_50305
		PHA
		LDA		_apu_chnl_var05,X
		BEQ		loc_502AE
		LDA		#$01
		STA		_apu_chnl_var05,X
loc_502AE:
		PLA
		BEQ		loc_502B4
		JMP		_apu_getc
loc_502B4:
		JMP		_apu_mus_fetch_next
loc_502B7:
		JSR		sub_50305
		PHA
		TAY
		LDA		#$FF
		STA		_apu_chnl_var05,X
		LDA		_apu_chnl_var08,X
		BEQ		loc_502DF
		STA		_tmp19
		TXA
		PHA
		LDA		#$00
		TAX
loc_502CD:
		CLC
		ADC		_tmp19
		BCC		loc_502D3
		INX
loc_502D3:
		DEY
		BNE		loc_502CD
		STX		_tmp19
		PLA
		TAX
		LDA		_tmp19
		STA		_apu_chnl_var05,X
loc_502DF:
		JSR		_apu_sample_A_load
		JMP		loc_502AE

; =============== S U B R O U T I N E ======n================================
_apu_sample_A_load:
		LDA		_apu_chnl_smpl,X
		BMI		nullsub_2

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_apu_sample_A_force:
		ASL
		ASL
		TAY

; FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_apu_sample_load_ex:
		LDA		_samples_lib,Y
		STA		_apu_snd_pc_lo,X
		LDA		_samples_lib+1,Y
		STA		_apu_snd_pc_hi,X
		LDA		_apu_stack_sample_list,X
		STA		_apu_snd_sp,X
		LDA		#$01
		STA		_apu_snd_delay,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
nullsub_2:
		RTS

; =============== S U B R O U T I N E ======n================================
sub_50305:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$E0
		CMP		#$C0
		BNE		loc_50315
		JSR		_apu_getc
		JMP		loc_50321
loc_50315:
		LSR
		LSR
		LSR
		LSR
		LSR
		ADC		_apu_chnl_var0B,X
		TAY
		LDA		_apu_len_table,Y
loc_50321:
		STA		_apu_mus_delay,X
		RTS

; =============== S U B R O U T I N E ======n================================
_apu_mus_cmd_fetch:
		LDA		(_apu_cur_pc),Y
		CMP		#$F0
		BNE		loc_50344
		JSR		_apu_getc
loc_5032E:
		ASL
		ASL
		ASL
		ASL
		STA		_tmp19
		LDA		_apu_chnl_var09,X
		AND		#$0F
		ORA		_tmp19
		STA		_apu_chnl_var09,X
		JSR		sub_505F2
		JMP		_apu_mus_fetch_next
loc_50344:
		CMP		#$F1
		BNE		loc_50368
		JSR		_apu_getc
		STA		_tmp19
		LDA		_apu_chnl_var09,X
		LSR
		LSR
		LSR
		LSR
		CLC
		ADC		_tmp19
		BIT		_tmp19
		BMI		loc_50361
		BCC		loc_50365
		LDA		#$0F
		BNE		loc_50365
loc_50361:
		BCS		loc_50365
		LDA		#$00
loc_50365:
		JMP		loc_5032E
loc_50368:
		CMP		#$F2
		BNE		loc_5037B
		JSR		_apu_getc
		ASL
		STA		_tmp1A
		ASL
		ADC		_tmp1A
		STA		_apu_chnl_var0B,X
		JMP		_apu_mus_fetch_next
loc_5037B:
		CMP		#$F3
		BNE		loc_5038D
		JSR		_apu_getc
		STA		_apu_mus_delay,X
		LDA		#$FF
		STA		_apu_chnl_var05,X
		JMP		_apu_getc
loc_5038D:
		CMP		#$F4
		BNE		loc_5039A
		JSR		_apu_getc
		STA		_apu_chnl_var08,X
		JMP		_apu_mus_fetch_next
loc_5039A:
		CMP		#$F5
		BNE		loc_503A7
		JSR		_apu_getc
		STA		_apu_chnl_var06,X
		JMP		_apu_mus_fetch_next
loc_503A7:
		CMP		#$F6
		BNE		loc_503B9
		JSR		_apu_getc
		STA		_apu_chnl_smpl,X
		BPL		loc_503B6
		JSR		_apu_sample_A_force
loc_503B6:
		JMP		_apu_mus_fetch_next
loc_503B9:
;		CMP		#$F7						; REDUNDANT, CMDF7, frequency table selector
;		BNE		loc_503C6					; there is only one frequence table in this
;		JSR		_apu_getc					; engine so this command completely unused
;		STA		_apu_chnl_freq_tbl,X
;		JMP		_apu_mus_fetch_next
loc_503C6:
#if OPTIMIZATION==1
		CMP		#$E4
		BNE		loc_503DA
		LDY		#_pcm0A_addr
		LDA		#_pcm0A_size
		BNE		loc_503D9
loc_503DA:
		CMP		#$E5
		BNE		loc_503DB
		LDY		#_pcm0B_addr
		LDA		#_pcm0B_size
		BNE		loc_503D9
loc_503DB:
		CMP		#$E6
		BNE		loc_503DC
		LDY		#_pcm1_addr
		LDA		#_pcm1_size
loc_503D9:
		STY		_APU_DMC_ADDR
		STA		_APU_DMC_LEN
		JMP		_apu_mus_fetch_next
loc_503DC:
#else
		CMP		#$E0
		BNE		loc_503D9
		JSR		_apu_getc
		STA		_APU_DMC_ADDR
		JSR		_apu_getc
		STA		_APU_DMC_LEN
		JMP		_apu_mus_fetch_next
loc_503D9:
#endif
		CMP		#$E2
		BNE		loc_50403
		JSR		_apu_getc
		PHA
		JSR		_apu_getc
		LDY		_apu_chnl_type,X
		INY
		INY
		INY
		AND		#$0F
		STA		_tmp19
		LDA		_apu_reg_pulse0_C,Y
		AND		#$10
		EOR		#$10
		ORA		_tmp19
		STA		(_apu_ptr35),Y
		PLA
		DEY
		STA		(_apu_ptr35),Y
		JSR		_apu_sample_A_load
		JMP		_apu_mus_fetch_next
loc_50403:
		CMP		#$E3
		BNE		loc_50413
		JSR		_apu_getc
		BPL		loc_5040D
		DEY
loc_5040D:
		JSR		sub_50665
		JMP		_apu_mus_fetch_next
loc_50413:
		CMP		#$E1
		BNE		loc_50420
		JSR		_apu_getc
		STA		_apu_var400
		JMP		_apu_mus_fetch_next
loc_50420:
		CMP		#$FF
		BNE		loc_50430
		LDA		#$00
		STA		_apu_mus_delay,X
		STA		_apu_snd_delay,X
		JSR		sub_505E6
		RTS
loc_50430:
		LDA		_apu_mus_sp,X
		STA		_apu_cur_sp
		JSR		_apu_logic_cmd_exec
		LDA		_apu_cur_sp
		STA		_apu_mus_sp,X
		JMP		_apu_mus_fetch

; =============== S U B R O U T I N E ======n================================
_apu_logic_cmd_exec:
		LDA		(_apu_cur_pc),Y
		CMP		#$F8
		BNE		loc_50453
		INY
		LDA		(_apu_cur_pc),Y
		PHA
		INY
		LDA		(_apu_cur_pc),Y
		STA		_apu_cur_pc+1
		PLA
		STA		_apu_cur_pc
		RTS
loc_50453:
		CMP		#$FA
		BNE		loc_50479
		JSR		_apu_getc
		PHA
		JSR		_apu_getc
		PHA
		JSR		_apu_getc
		LDY		_apu_cur_sp
		LDA		_apu_cur_pc+1
		DEY
		STA		_apu_stack,Y
		LDA		_apu_cur_pc
		DEY
		STA		_apu_stack,Y
		STY		_apu_cur_sp
		PLA
		STA		_apu_cur_pc+1
		PLA
		STA		_apu_cur_pc
		RTS
loc_50479:
		CMP		#$FB
		BNE		loc_5048E
		LDY		_apu_cur_sp
		LDA		_apu_stack,Y
		STA		_apu_cur_pc
		INY
		LDA		_apu_stack,Y
		STA		_apu_cur_pc+1
		INY
		STY		_apu_cur_sp
		RTS
loc_5048E:
		CMP		#$FC
		BNE		loc_504AF
		JSR		_apu_getc
		PHA
		JSR		_apu_getc
		LDY		_apu_cur_sp
		LDA		_apu_cur_pc+1
		DEY
		STA		_apu_stack,Y
		LDA		_apu_cur_pc
		DEY
		STA		_apu_stack,Y
		PLA
		DEY
		STA		_apu_stack,Y
		STY		_apu_cur_sp
		RTS
loc_504AF:
		CMP		#$FD
		BNE		loc_504D4
		LDY		_apu_cur_sp
		LDA		_apu_stack,Y
		SEC
		SBC		#$01
		STA		_apu_stack,Y
		BEQ		loc_504CB
		LDA		_apu_stack+1,Y
		STA		_apu_cur_pc
		LDA		_apu_stack+2,Y
		STA		_apu_cur_pc+1
loc_504D4:
		RTS
loc_504CB:
		INC		_apu_cur_sp
		INC		_apu_cur_sp
		INC		_apu_cur_sp
		JMP		_apu_getc
;		CMP		#$FE						; REDUNDANT, CMDFE also unused command,
;		BNE		locret_504DE				; literally 2-byte ANOP operation.
;		JSR		_apu_getc
;		JMP		_apu_getc
;locret_504DE:
;		RTS

; =============== S U B R O U T I N E ======n================================
_apu_getc:
		INC		_apu_cur_pc
		BNE		loc_504E5
		INC		_apu_cur_pc+1
loc_504E5:
		LDA		(_apu_cur_pc),Y
		RTS

; =============== S U B R O U T I N E ======n================================
sub_504E8:
;		PHA
;		LDA		_apu_chnl_freq_tbl,X
;		ASL
;		TAY
;		LDA		_apu_freq_table_ofs,Y
;		STA		_ptr17
;		LDA		_apu_freq_table_ofs+1,Y
;		STA		_ptr17+1
;		PLA
		ASL
		TAY
;		LDA		(_ptr17),Y
		LDA		_apu_freq_table,Y
		STA		_tmp19
;		INY
;		LDA		(_ptr17),Y
		LDA		_apu_freq_table+1,Y
		LDY		_apu_chnl_type,X
		INY
		INY
		STA		(_apu_ptr35),Y
		INY
		LDA		_apu_reg_pulse0_C,Y
		AND		#$10
		EOR		#$10
		ORA		byte_50519,X
		ORA		_tmp19
		STA		(_apu_ptr35),Y
		RTS
byte_50519:
		.BYTE	$00,$00,$00,$00,$00,$20,$20,$20,$20,$20

; =============== S U B R O U T I N E ======n================================
sub_50523:
		LDA		_apu_chnl_var05,X
		BEQ		locret_5053C
		CMP		#$FF
		BEQ		locret_5053C
		DEC		_apu_chnl_var05,X
		BNE		locret_5053C
		LDA		_apu_chnl_smpl,X
		ASL
		ASL
		TAY
		INY
		INY
		JMP		_apu_sample_load_ex
locret_5053C:
		RTS

; =============== S U B R O U T I N E ======n================================
_apu_snd_fetch_next:
		JSR		_apu_getc

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_apu_snd_fetch:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$E0
		BNE		loc_50552
		LDA		(_apu_cur_pc),Y
		AND		#$1F
		STA		_apu_snd_delay,X
		JMP		_apu_getc
loc_50552:
		CMP		#$20
		BNE		loc_5056C
		JSR		sub_50647
		JSR		sub_50665
loc_5055C:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$10
		BEQ		_apu_snd_fetch_next
		LDA		#$01
		STA		_apu_snd_delay,X
		JMP		_apu_getc
loc_5056C:
		CMP		#$40
		BNE		loc_50577
		LDA		(_apu_cur_pc),Y
		AND		#$0F
		JMP		loc_50592
loc_50577:
		CMP		#$60
		BNE		loc_50598
		JSR		sub_50647
		CLC
		STA		_tmp19
		LDA		_apu_chnl_var09,X
		AND		#$0F
		ADC		_tmp19
		BPL		loc_5058C
		LDA		#$00
loc_5058C:
		CMP		#$10
		BCC		loc_50592
		LDA		#$0F
loc_50592:
		JSR		sub_505E6
		JMP		loc_5055C
loc_50598:
		CMP		#$80
		BNE		loc_505B5
		LDA		(_apu_cur_pc),Y
		AND		#$0F
		LDY		_apu_chnl_type,X
		ROR
		ROR
		ROR
		AND		#$C0
		STA		_tmp19
		LDA		(_apu_ptr35),Y
		AND		#$3F
		ORA		_tmp19
		STA		(_apu_ptr35),Y
		JMP		loc_5055C
loc_505B5:
		CMP		#$E0
		BNE		locret_505E5
		LDA		(_apu_cur_pc),Y
		CMP		#$F0
		BNE		loc_505CB
		JSR		_apu_getc
		LDY		_apu_chnl_type,X
		INY
		STA		(_apu_ptr35),Y
		JMP		_apu_snd_fetch_next
loc_505CB:
		CMP		#$FF
		BNE		loc_505D5
		LDA		#$00
		STA		_apu_snd_delay,X
		RTS
loc_505D5:
		LDA		_apu_snd_sp,X
		STA		_apu_cur_sp
		JSR		_apu_logic_cmd_exec
		LDA		_apu_cur_sp
		STA		_apu_snd_sp,X
		JMP		_apu_snd_fetch
locret_505E5:
		RTS

; =============== S U B R O U T I N E ======n================================
sub_505E6:
		STA		_tmp19
		LDA		_apu_chnl_var09,X
		AND		#$F0
		ORA		_tmp19
		STA		_apu_chnl_var09,X

; =============== S U B R O U T I N E ======n================================
sub_505F2:
		LDA		#$FF
		SEC
		SBC		_apu_chnl_var09,X
		LSR
		LSR
		LSR
		LSR
		STA		_tmp19
		LDA		_apu_chnl_var09,X
		AND		#$0F
		SEC
		SBC		_tmp19
		BPL		loc_5060A
		LDA		#$00
loc_5060A:
		STA		_tmp19
		LDY		#$00
		CPX		#$05
		BCC		loc_50613
		INY
loc_50613:
		LDA		#$FF
		SEC
		SBC		_apu_snd_volume,Y
		LSR
		LSR
		LSR
		LSR
		EOR		#$FF
		SEC
		ADC		_tmp19
		BPL		loc_50626
		LDA		#$00
loc_50626:
		STA		_tmp19
		LDY		_apu_chnl_type,X
		CPY		#$08
		BEQ		loc_5063A
		LDA		(_apu_ptr35),Y
		AND		#$C0
		ORA		#$30
		ORA		_tmp19
		STA		(_apu_ptr35),Y
		RTS
loc_5063A:
		LDA		_tmp19
		CMP		#$04
		LDA		#$00
		BCC		loc_50644
		LDA		#$FF
loc_50644:
		STA		(_apu_ptr35),Y
		RTS

; =============== S U B R O U T I N E ======n================================
sub_50647:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$0F
		BIT		_apu_noise_flag_mask
		BEQ		locret_50655
		ORA		#$F0
		DEY
locret_50655:
		RTS

; =============== S U B R O U T I N E ======n================================
;_apu_unref:
;		LDY		#$00
;		LDA		(_apu_cur_pc),Y
;		AND		#$1F
;		BIT		_apu_dpcm_flag_mask
;		BEQ		locret_50664
;		ORA		#$E0
;		DEY
;locret_50664:
;		RTS

; =============== S U B R O U T I N E ======n================================
sub_50665:
		STY		_tmp19
		LDY		_apu_chnl_type,X
		CLC
		INY
		INY
		ADC		(_apu_ptr35),Y
		STA		(_apu_ptr35),Y
		INY
		LDA		_tmp19
		ADC		(_apu_ptr35),Y
		STA		(_apu_ptr35),Y
		RTS
_apu_freq_table:
		.BYTE	$07,$FF,$07,$87,$07,$1C,$06,$B1,$06,$52,$05,$F4,$05,$A0,$05,$4E
		.BYTE	$05,$05,$04,$BD,$04,$78,$04,$36,$03,$FC,$03,$C0,$03,$89,$03,$58
		.BYTE	$03,$29,$02,$FA,$02,$D0,$02,$A7,$02,$80,$02,$5D,$02,$3B,$02,$1B
		.BYTE	$01,$FD,$01,$E0,$01,$C5,$01,$AB,$01,$93,$01,$7D,$01,$67,$01,$53
		.BYTE	$01,$40,$01,$2E,$01,$1D,$01,$0D,$00,$FE,$00,$F0,$00,$E2,$00,$D5
		.BYTE	$00,$C9,$00,$BE,$00,$B3,$00,$A9,$00,$A0,$00,$97,$00,$8E,$00,$86
		.BYTE	$00,$7F,$00,$78,$00,$71,$00,$6A,$00,$64,$00,$5F,$00,$59,$00,$54
		.BYTE	$00,$50,$00,$4B,$00,$47,$00,$43,$00,$3F,$00,$3C,$00,$38,$00,$35
		.BYTE	$00,$32,$00,$2F,$00,$2C,$00,$2A,$00,$28,$00,$25,$00,$23,$00,$21
		.BYTE	$00,$1F,$00,$1E,$00,$1C
off_5070F:
		.BYTE	<[_apu_reg_pulse0_A]
		.BYTE	<[_apu_reg_pulse0_A]
		.BYTE	<[_apu_reg_pulse0_A]
		.BYTE	<[_apu_reg_pulse0_A]
		.BYTE	<[_apu_reg_pulse0_A]
		.BYTE	<[_apu_reg_pulse0_B]
		.BYTE	<[_apu_reg_pulse0_B]
		.BYTE	<[_apu_reg_pulse0_B]
		.BYTE	<[_apu_reg_pulse0_B]
		.BYTE	<[_apu_reg_pulse0_B]
off_50719:
		.BYTE	>[_apu_reg_pulse0_A]
		.BYTE	>[_apu_reg_pulse0_A]
		.BYTE	>[_apu_reg_pulse0_A]
		.BYTE	>[_apu_reg_pulse0_A]
		.BYTE	>[_apu_reg_pulse0_A]
		.BYTE	>[_apu_reg_pulse0_B]
		.BYTE	>[_apu_reg_pulse0_B]
		.BYTE	>[_apu_reg_pulse0_B]
		.BYTE	>[_apu_reg_pulse0_B]
		.BYTE	>[_apu_reg_pulse0_B]
_apu_stack_main_list:
		.BYTE	$10,$20,$30,$40,$50,$60,$70,$80,$90,$A0
_apu_stack_sample_list:
		.BYTE	$06,$16,$26,$36,$46,$56,$66,$76,$86,$96
; NOTE: all games with the same engine uses this table to select freq tables.
; however, in all such games/engines there is only one freq table always.
;
;_apu_freq_table_ofs:
;		.WORD	_apu_freq_table
_apu_len_table:
		.BYTE	$01,$02,$03,$04,$05,$06,$07,$0E,$15,$1C,$23,$38,$08,$10,$18,$20
		.BYTE	$80,$40,$08,$10,$18,$20,$28,$30,$06,$0C,$12,$18,$1E,$24,$05,$0A
		.BYTE	$0F,$14,$19,$1E,$09,$12,$1B,$24,$8A,$06,$11,$0C,$05,$03,$88,$1D
; REGION, the additional lengths table for PAL version of the music data
;		.BYTE	$01,$04,$08,$09,$0C,$0D,$06,$07,$14,$1A,$1B,$35,$04,$08,$0C,$0D
;		.BYTE	$19,$09,$05,$06,$0B,$0C,$16,$17,$06,$0C,$12,$18,$1E,$30,$04,$05
;		.BYTE	$08,$09,$11,$19,$0E,$0A,$04,$02,$70,$18,$04,$05,$08,$0C,$0D,$19
_apu_snd_table0:
		.BYTE	$02,$02,$0A,$0F,$03,$0A,$0A,$0A,$02,$0A,$0A,$02,$02,$02,$03,$0A
		.BYTE	$02,$02,$0A,$0B,$08,$08,$08,$03,$0A,$0B,$0F,$08,$02,$02,$03,$08
		.BYTE	$02,$02,$02,$0C
_apu_snd_table1:
		.BYTE	$3C,$32,$32,$00,$0A,$28,$32,$32,$32,$32,$32,$32,$32,$28,$1E,$32
		.BYTE	$3C,$3C,$32,$28,$3C,$32,$28,$28,$3C,$1E,$0B,$3C,$32,$32,$00,$46
		.BYTE	$32,$32,$28,$32

		SECTION_END	"APU ENGINE"

		SECTION_START

_samples_lib:
		SMPL_PTR	_sample00,_sample_00A,_sample_00B
		SMPL_PTR	_sample01,_sample_01A,_sample_00B
		SMPL_PTR	_sample02,_sample_02A,_sample_00B
		SMPL_PTR	_sample03,_sample_03A,_sample_00B
		SMPL_PTR	_sample04,_sample_04A,_sample_00B
		SMPL_PTR	_sample05,_sample_05A,_sample_05B
		SMPL_PTR	_sample06,_sample_05A,_sample_06B
		SMPL_PTR	_sample07,_sample_07A,_sample_05B
		SMPL_PTR	_sample08,_sample_08A,_sample_05B
		SMPL_PTR	_sample09,_sample_08A,_sample_06B
		SMPL_PTR	_sample0A,_sample_0AA,_sample_05B
		SMPL_PTR	_sample0B,_sample_0AA,_sample_06B
		SMPL_PTR	_sample0C,_sample_0CA,_sample_05B
		SMPL_PTR	_sample0D,_sample_07A,_sample_06B
		SMPL_PTR	_sample0E,_sample_0EA,_sample_05B
		SMPL_PTR	_sample0F,_sample_0EA,_sample_06B
		SMPL_PTR	_sample10,_sample_10A,_sample_05B
		SMPL_PTR	_sample11,_sample_10A,_sample_06B
		SMPL_PTR	_sample12,_sample_12A,_sample_05B
		SMPL_PTR	_sample13,_sample_13A,_sample_05B
		SMPL_PTR	_sample14,_sample_14A,_sample_05B
		SMPL_PTR	_sample15,_sample_15A,_sample_15B
		SMPL_PTR	_sample16,_sample_15A,_sample_16B
		SMPL_PTR	_sample17,_sample_17A,_sample_15B
		SMPL_PTR	_sample18,_sample_17A,_sample_16B
		SMPL_PTR	_sample19,_sample_19A,_sample_00B
		SMPL_PTR	_sample1A,_sample_1AA,_sample_1AB
		SMPL_PTR	_sample1B,_sample_19A,_sample_00B
		SMPL_PTR	_sample1C,_sample_1CA,_sample_06B
		SMPL_PTR	_sample1D,_sample_1DA,_sample_1DB
		SMPL_PTR	_sample1E,_sample_1EA,_sample_06B
		SMPL_PTR	_sample1F,_sample_1FA,_sample_16B
		SMPL_PTR	_sample20,_sample_20A,_sample_1DB
		SMPL_PTR	_sample21,_sample_21A,_sample_00B
		SMPL_PTR	_sample22,_sample_22A,_sample_22B
		SMPL_PTR	_sample23,_sample_23A,_sample_00B
		SMPL_PTR	_sample24,_sample_24A,_sample_22B
		SMPL_PTR	_sample25,_sample_25A,_sample_25B
		SMPL_PTR	_sample26,_sample_26A,_sample_00B
		SMPL_PTR	_sample27,_sample_27A,_sample_00B
		SMPL_PTR	_sample28,_sample_28A,_sample_22B
		SMPL_PTR	_sample29,_sample_29A,_sample_22B
		SMPL_PTR	_sample2A,_sample_2AA,_sample_16B
		SMPL_PTR	_sample2B,_sample_2BA,_sample_2BB
		SMPL_PTR	_sample2C,_sample_2CA,_sample_2BB
		SMPL_PTR	_sample2D,_sample_2DA,_sample_22B

_sample_00A:
		ADATA		$80
		ADATA		$4F
		ASTOP
_sample_01A:
		ADATA		$81
		ADATA		$4F
		ASTOP
_sample_02A:
		ADATA		$82
		ADATA		$4F
		ASTOP
_sample_03A:
		ADATA		$83
		ADATA		$4F
		ASTOP
_sample_00B:
		ADATA		$40
		ASTOP
_sample_1AB:
		ADATA		$42
		ADATA		$02
		ADATA		$41
		ADATA		$04
		ADATA		$40
		ASTOP
_sample_05B:
		ADATA		$42
		ASTOP
_sample_04A:
		ADATA		$4C
		ADATA		$03
		ALOOP_START	$0C
		ADATA		$6F
		ADATA		$03
		ALOOP_END
		ASTOP
_aloc_53148:
		ADATA		$57
		ADATA		$56
		ADATA		$45
		ADATA		$03
		ADATA		$44
		ADATA		$0F
_aloc_5314E:
		ADATA		$6F
		ADATA		$04
		ADATA		$61
		ADATA		$04
		AJMP		_aloc_5314E
_sample_05A:
		ADATA		$80
		ADATA		$58
		ADATA		$81
		AJMP		_aloc_53148
_sample_06B:
		ADATA		$44
		ADATA		$04
		ADATA		$43
		ALOOP_START	$05
		ADATA		$6F
		ADATA		$04
		ADATA		$61
		ADATA		$04
		ADATA		$6F
		ALOOP_END
		ADATA		$20
		ASTOP
_sample_07A:
		ADATA		$81
		ADATA		$58
		ADATA		$80
		AJMP		_aloc_53148
_sample_08A:
		ADATA		$80
		ADATA		$58
		ADATA		$82
		AJMP		_aloc_53148
_sample_0AA:
		ADATA		$82
		ADATA		$58
		ADATA		$80
		AJMP		_aloc_53148
;_sample_unref:
;		ADATA		$80
;		ADATA		$57
;		ADATA		$82
;		ADATA		$04
;		AJMP		_aloc_53185
_sample_0CA:
		ADATA		$81
		ADATA		$57
		ADATA		$80
		ADATA		$04
_aloc_53185:
		ADATA		$40
_aloc_53186:
		ADATA		$2E
		ADATA		$62
		ADATA		$04
		ADATA		$22
		ADATA		$6E
		ADATA		$04
		AJMP		_aloc_53186
_sample_0EA:
		ADATA		$80
		ADATA		$58
		ADATA		$83
		AJMP		_aloc_53148
_sample_10A:
		ADATA		$83
		ADATA		$58
		ADATA		$80
		AJMP		_aloc_53148
;_sample_unref_0:
;		ADATA		$44
_aloc_5319C:
		ADATA		$2F
		ADATA		$02
		ADATA		$21
		ADATA		$02
		ADATA		$21
		ADATA		$02
		ADATA		$2F
		ADATA		$02
		AJMP		_aloc_5319C
_sample_12A:
		AJSR		_asub_531AD
		AJMP		_aloc_531B7
_asub_531AD:
		ADATA		$80
		ADATA		$43
		ALOOP_START	$03
		ADATA		$72
		ALOOP_END
		ADATA		$91
		ADATA		$6E
		ADATA		$83
		ARET
_aloc_531B7:
		ALOOP_START	$02
		ADATA		$6E
		ADATA		$02
		ALOOP_END
		ADATA		$7F
_aloc_531BD:
		ADATA		$61
		ADATA		$04
		ADATA		$6F
		ADATA		$04
		AJMP		_aloc_531BD
_sample_13A:
		ADATA		$49
		ALOOP_START	$03
		ADATA		$01
		ADATA		$6B
		ALOOP_END
		ASTOP
_sample_14A:
		ADATA		$49
		ALOOP_START	$02
		ADATA		$7E
		ALOOP_END
		ALOOP_START	$05
		ADATA		$6F
		ADATA		$02
		ALOOP_END
		ASTOP
_sample_15A:
		ADATA		$82
		ADATA		$58
		ADATA		$20
		ADATA		$83
		AJMP		_aloc_53148
_sample_17A:
		ADATA		$80
		ADATA		$58
		ADATA		$82
		AJMP		_aloc_53148
_sample_15B:
		ADATA		$2E
		ADATA		$42
		ASTOP
_sample_16B:
		ADATA		$44
		ADATA		$04
		ADATA		$43
		ALOOP_START	$0A
		ADATA		$6F
		ADATA		$04
		ADATA		$61
		ADATA		$04
		ADATA		$6F
		ALOOP_END
		ADATA		$22
		ASTOP
_sample_19A:
		ADATA		$4B
		ADATA		$92
		ADATA		$48
		ADATA		$83
		ALOOP_START	$08
		ADATA		$6F
		ADATA		$02
		ALOOP_END
		ASTOP
_sample_1AA:
		ADATA		$83
		ADATA		$46
		ALOOP_START	$02
		ADATA		$71
		ADATA		$80
		ALOOP_END
		ALOOP_START	$02
		ADATA		$6E
		ADATA		$03
		ALOOP_END
_aloc_53209:
		ADATA		$42
		ADATA		$02
		ADATA		$41
		ADATA		$0C
		AJMP		_aloc_53209
_sample_1CA:
		ADATA		$81
		ADATA		$45
		ALOOP_START	$02
		ADATA		$72
		ALOOP_END
		ADATA		$82
_aloc_53217:
		ADATA		$22
		ADATA		$02
		ADATA		$23
		ADATA		$02
		ADATA		$22
		ADATA		$02
		ADATA		$2E
		ADATA		$02
		ADATA		$2D
		ADATA		$02
		ADATA		$2E
		ADATA		$02
		AJMP		_aloc_53217
_sample_1DA:
		ADATA		$4A
		ADATA		$83
		ADATA		$02
		ADATA		$81
		ALOOP_START	$03
		ADATA		$7E
		ALOOP_END
_aloc_5322E:
		ADATA		$83
		ADATA		$02
		ADATA		$72
		ADATA		$7E
		AJMP		_aloc_5322E
_sample_1DB:
		ALOOP_START	$05
		ADATA		$6F
		ADATA		$03
		ALOOP_END
_sample_1EA:
		ADATA		$80
		ADATA		$4D
		ADATA		$02
		ADATA		$81
		ADATA		$4A
		ALOOP_START	$02
		ADATA		$7D
		ALOOP_END
		ADATA		$82
		ALOOP_START	$02
		ADATA		$7F
		ALOOP_END
_sample_1FA:
		ADATA		$80
		ADATA		$4A
		ADATA		$02
		ADATA		$6E
		ADATA		$83
		ADATA		$02
_aloc_5324E:
		ADATA		$22
		ADATA		$02
		ADATA		$21
		ADATA		$03
		ADATA		$2E
		ADATA		$02
		ADATA		$2F
		ADATA		$03
		AJMP		_aloc_5324E
_sample_20A:
		ADATA		$57
		ADATA		$31
		ADATA		$6F
		ADATA		$21
		ADATA		$02
		ADATA		$21
		ADATA		$03
		ADATA		$6F
_aloc_53261:
		ADATA		$21
		ADATA		$05
		AJMP		_aloc_53261
_sample_21A:
		ADATA		$83
		ADATA		$5A
		ADATA		$81
		ADATA		$59
		ADATA		$80
		ADATA		$47
		ADATA		$03
_aloc_5326D:
		ADATA		$21
		ADATA		$03
		ADATA		$2F
		ADATA		$03
		AJMP		_aloc_5326D
_sample_22A:
		ADATA		$82
		ADATA		$5A
		ADATA		$80
		ADATA		$58
		ALOOP_START	$02
		ADATA		$7E
		ADATA		$80
		ADATA		$7E
		ALOOP_END
_aloc_5327E:
		ADATA		$46
		ADATA		$03
		ADATA		$42
		ADATA		$02
		ADATA		$46
		ADATA		$03
		ADATA		$42
		ADATA		$02
		AJMP		_aloc_5327E
;		ASTOP
_sample_23A:
		ADATA		$83
		ADATA		$22
		ADATA		$5A
		ADATA		$81
		ADATA		$59
		ADATA		$80
		ADATA		$47
		ADATA		$03
_aloc_53292:
		ADATA		$21
		ADATA		$03
		ADATA		$2F
		ADATA		$03
		AJMP		_aloc_53292
_sample_22B:
		ADATA		$53
		ADATA		$55
		ADATA		$53
		ADATA		$42
		ADATA		$02
		ADATA		$40
		ASTOP
_sample_24A:
		ADATA		$23
		AJMP		_sample_22A
;		ASTOP
_sample_25A:
		ADATA		$82
		ADATA		$59
		ADATA		$81
		ADATA		$5A
		ADATA		$83
		ADATA		$5B
		ADATA		$21
		ADATA		$5D
		ADATA		$2F
		ADATA		$5A
_aloc_532AF:
		ADATA		$49
		ADATA		$21
		ADATA		$02
		ADATA		$2F
		ADATA		$02
		AJMP		_aloc_532AF
_sample_26A:
		ADATA		$80
		ADATA		$5D
		ADATA		$81
		ADATA		$5D
		ADATA		$82
		ADATA		$5A
		ALOOP_START	$05
		ADATA		$7F
		ALOOP_END
_aloc_532C1:
		ADATA		$55
		AJMP		_aloc_532C1
_sample_25B:
		ADATA		$42
		ADATA		$03
		ADATA		$44
		ADATA		$04
		AJMP		_sample_25B
;		ASTOP
_sample_27A:
		ADATA		$83
		ADATA		$4D
		ADATA		$02
		ADATA		$82
		ADATA		$4B
		ADATA		$04
		ADATA		$4A
		ADATA		$04
		ADATA		$49
		ADATA		$06
_aloc_532D7:
		ADATA		$22
		ADATA		$02
		ADATA		$2E
		ADATA		$02
		ADATA		$2E
		ADATA		$02
		ADATA		$22
		ADATA		$02
		AJMP		_aloc_532D7
_sample_28A:
		ADATA		$82
		ADATA		$5D
		ADATA		$83
		ADATA		$5B
		ADATA		$7E
		ADATA		$6F
		ADATA		$02
		ADATA		$81
_aloc_532EA:
		ADATA		$31
		ADATA		$3F
		ADATA		$3F
		ADATA		$31
		AJMP		_aloc_532EA
_sample_29A:
		ADATA		$80
		ADATA		$5E
		ADATA		$81
		ADATA		$47
		ADATA		$02
		ADATA		$80
		ADATA		$5B
		ADATA		$5A
		ALOOP_START	$0A
		ADATA		$7F
		ALOOP_END
		ASTOP
_sample_2AA:
		ADATA		$83
		ADATA		$5F
		ADATA		$80
		ADATA		$4C
		ADATA		$02
		ADATA		$82
		ADATA		$49
_aloc_53305:
		ADATA		$21
		ADATA		$02
		ADATA		$2F
		ADATA		$02
		ADATA		$2F
		ADATA		$02
		ADATA		$21
		ADATA		$02
		AJMP		_aloc_53305
;		ASTOP
_sample_2BA:
		ADATA		$83
		ADATA		$47
		ALOOP_START	$06
		ADATA		$61
		ADATA		$02
		ALOOP_END
_aloc_53318:
		ADATA		$22
		ADATA		$02
		ADATA		$2F
		ADATA		$02
		ADATA		$2E
		ADATA		$02
		ADATA		$21
		ADATA		$02
		AJMP		_aloc_53318
;		ASTOP
_sample_2BB:
		ALOOP_START	$0D
		ADATA		$7E
		ADATA		$7F
		ADATA		$7F
		ADATA		$6F
		ADATA		$02
		ADATA		$71
		ADATA		$71
		ADATA		$62
		ADATA		$02
		ALOOP_END
		ASTOP
_sample_2CA:
		ADATA		$82
		ADATA		$4E
		ADATA		$03
		ADATA		$4B
		ALOOP_START	$0B
		ADATA		$6F
		ADATA		$03
		ALOOP_END
		ASTOP
_sample_2DA:
		ADATA		$5F
		ADATA		$5E
		ADATA		$58
		ADATA		$5C
		ADATA		$5A
		ALOOP_START	$0A
		ADATA		$7F
		ALOOP_END
		ASTOP

		SECTION_END	"APU SAMPLES"

		SECTION_START

_snd_lib:
		SND		_snd00	; beam
		SND		_snd01	; catch release
		SND		_snd02	; ghost catch scream
		SND		_snd03	; pause
		SND		_snd04	; beamer hit
		SND		_snd05	; bounce -unused-
		SND		_snd06	; doors close
		SND		_snd07	; doors open
		SND		_snd08	; slime laugh
		SND		_snd09	; train ride -unused-
		SND		_snd0A	; door06 close
		SND		_snd0B	; buster select input
		SND		_snd0C	; buster select apply
		SND		_snd0D	; prize taken
		SND		_snd0E	; vega laugh
		SND		_snd0F	; key keeper shoot
		SND		_snd10	; key keepr step? jump A? -unused-
		SND		_snd11	; urraaap! -unused-
		SND		_snd12	; court chair
		SND		_snd13	; train whistle
		SND		_snd14	; sewers dragon appear
		SND		_snd15	; sewers dragon fire
		SND		_snd16	; sewers dragon explode? -unused-
		SND		_snd17	; fall down -unused-
		SND		_snd18	; jump B? -unused-
		SND		_snd19	; boss catch scream
		SND		_snd1A	; vega death scream
		SND		_snd1B	; wind/pssst -unused-
		SND		_snd1C	; zanac like fire -unused-
		SND		_snd1D	; zanac like beam A -unused-
		SND		_snd1E	; live add
		SND		_snd1F	; rolling boulder? helicopter? -unused-
		SND		_snd20	; zanac like beam B -unused-
		SND		_snd21	; zanac like beam C -unused-
		SND		_snd22	; sewers dragon disappear
		SND		_snd23	; candle light up

_snd00:
		.BYTE	$01
		.WORD	_snd00_A
		.BYTE	$04
_snd01:
		.BYTE	$01
		.WORD	_snd01_A
		.BYTE	$04
_snd02:
		.BYTE	$02
		.WORD	_snd02_A
		.BYTE	$0C
		.WORD	_snd02_B
		.BYTE	$04
_snd03:
		.BYTE	$05
		.WORD	_snd03_A
		.BYTE	$08
		.WORD	_snd03_B
		.BYTE	$0C
		.WORD	_snd03_C
		.BYTE	$04
		.WORD	_snd03_D
		.BYTE	$00
		.WORD	_snd03_E
		.BYTE	$0C
_snd04:
		.BYTE	$02
		.WORD	_snd04_A
		.BYTE	$04
		.WORD	_snd04_B
		.BYTE	$00
_snd05:
		.BYTE	$02
		.WORD	_snd05_A
		.BYTE	$04
		.WORD	_snd05_B
		.BYTE	$0C
_snd06:
		.BYTE	$02
		.WORD	_snd06_A
		.BYTE	$0C
		.WORD	_snd06_B
		.BYTE	$04
_snd07:
		.BYTE	$02
		.WORD	_snd07_A
		.BYTE	$04
		.WORD	_snd07_B
		.BYTE	$0C
_snd08:
		.BYTE	$01
		.WORD	_snd08_A
		.BYTE	$04
_snd09:
		.BYTE	$02
		.WORD	_snd09_A
		.BYTE	$04
		.WORD	_snd09_B
		.BYTE	$0C
_snd0A:
		.BYTE	$02
		.WORD	_snd0A_A
		.BYTE	$04
		.WORD	_snd0A_B
		.BYTE	$0C
_snd0B:
		.BYTE	$01
		.WORD	_snd0B_A
		.BYTE	$04
_snd0C:
		.BYTE	$01
		.WORD	_snd0C_A
		.BYTE	$04
_snd0D:
		.BYTE	$01
		.WORD	_snd0D_A
		.BYTE	$04
_snd0E:
		.BYTE	$02
		.WORD	_snd0E_A
		.BYTE	$04
		.WORD	_snd0E_B
		.BYTE	$00
_snd0F:
		.BYTE	$02
		.WORD	_snd0F_A
		.BYTE	$04
		.WORD	_snd0F_B
		.BYTE	$0C
_snd10:
		.BYTE	$01
		.WORD	_snd10_A
		.BYTE	$04
_snd11:
		.BYTE	$01
		.WORD	_snd11_A
		.BYTE	$04
_snd12:
		.BYTE	$02
		.WORD	_snd12_A
		.BYTE	$0C
		.WORD	_snd12_B
		.BYTE	$04
_snd13:
		.BYTE	$03
		.WORD	_snd13_A
		.BYTE	$00
		.WORD	_snd13_B
		.BYTE	$04
		.WORD	_snd13_C
		.BYTE	$0C
_snd14:
		.BYTE	$01
		.WORD	_snd14_A
		.BYTE	$0C
_snd15:
		.BYTE	$01
		.WORD	_snd15_A
		.BYTE	$0C
_snd16:
		.BYTE	$01
		.WORD	_snd16_A
		.BYTE	$0C
_snd17:
		.BYTE	$02
		.WORD	_snd17_A
		.BYTE	$04
		.WORD	_snd17_B
		.BYTE	$00
_snd18:
		.BYTE	$02
		.WORD	_snd18_A
		.BYTE	$04
		.WORD	_snd18_B
		.BYTE	$0C
_snd19:
		.BYTE	$03
		.WORD	_snd19_A
		.BYTE	$04
		.WORD	_snd19_B
		.BYTE	$00
		.WORD	_snd19_C
		.BYTE	$0C
_snd1A:
		.BYTE	$04
		.WORD	_snd1A_A
		.BYTE	$0C
		.WORD	_snd1A_B
		.BYTE	$04
		.WORD	_snd1A_C
		.BYTE	$00
		.WORD	_snd1A_D
		.BYTE	$08
_snd1B:
		.BYTE	$01
		.WORD	_snd1B_A
		.BYTE	$0C
_snd1C:
		.BYTE	$01
		.WORD	_snd1C_A
		.BYTE	$04
_snd1D:
		.BYTE	$01
		.WORD	_snd1D_A
		.BYTE	$04
_snd1E:
		.BYTE	$02
		.WORD	_snd1E_A
		.BYTE	$04
		.WORD	_snd1E_B
		.BYTE	$00
_snd1F:
		.BYTE	$01
		.WORD	_snd1F_A
		.BYTE	$0C
_snd20:
		.BYTE	$01
		.WORD	_snd20_A
		.BYTE	$04
_snd21:
		.BYTE	$01
		.WORD	_snd21_A
		.BYTE	$04
_snd22:
		.BYTE	$01
		.WORD	_snd22_A
		.BYTE	$04
_snd23:
		.BYTE	$02
		.WORD	_snd23_A
		.BYTE	$0C
		.WORD	_snd23_B
		.BYTE	$08
_snd00_A:
		ACMDF2		$00
		ACMDF0		$0A
		ASMPL		_sample00
		ACMDF4		$00
		ACMDF5		$2B
		ACMDE1		$01
		ADATA		$09
		ADATA		$07
		ADATA		$04
		ADATA		$0B
		ADATA		$09
		ADATA		$0E
		ADATA		$03
		ACMDE1		$00
		ASTOP
_snd01_A:
		ACMDF2		$00
		ACMDF0		$0E
		ASMPL		_sample01
		ACMDF4		$00
		ACMDF5		$18
		ADATA		$13
		ADATA		$1A
		ADATA		$15
		ADATA		$1C
		ADATA		$16
		ADATA		$1D
		ADATA		$16
		ADATA		$1D
		ADATA		$1C
		ADATA		$04
		ACMDF5		$35
		ACMDF1		$F8
		ASMPL		_sample00
		ADATA		$16
		ADATA		$1F
		ADATA		$0D
		ASTOP
_snd02_A:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00|SMPL_FORCE
		ADATA		$0A
		ADATA		$0D
		ADATA		$0B
		ADATAEX		$CE,$00
		ALOOP_START	$05
		ACMDE3		$FE
		ACMDF3		$02
		ALOOP_END
		ASTOP
_snd02_B:
		ACMDF2		$00
		ACMDF0		$0E
		ACMDF4		$00
		ACMDF5		$1B
		ASMPL		_sample03
		ADATA		$31
		ADATA		$14
		ADATA		$01
		ACMDF0		$07
		ADATA		$17
		ADATA		$04
		ACMDF1		$01
		ADATA		$1A
		ACMDF1		$01
		ADATA		$07
		ACMDF1		$01
		ADATA		$1D
		ACMDF1		$01
		ADATA		$0A
		ASMPL		_sample02
		ACMDF1		$02
		ACMDF5		$35
		ADATA		$18
		ADATA		$05
		ADATA		$06
		ASTOP
_snd03_E:
		ACMDF2		$04
		ACMDF0		$0F
		ACMDF4		$DC
		ASMPL		_sample14
		ADATA		$05
		ADATA		$06
		ADATA		$07
		ADATA		$28
		ACMDF0		$00
		ADATA		$AF
		ASTOP
_snd03_C:
		ACMDF2		$04
		ACMDF0		$0F
		ACMDF5		$0F
		ACMDF4		$00
		ASMPL		_sample23
		ADATA		$1E
		ADATA		$1B
		ADATA		$00
		ADATA		$39
		ASTOP
_snd03_D:
		ACMDF2		$04
		ACMDF0		$0F
		ACMDF5		$1B
		ACMDF4		$00
		ASMPL		_sample1F
		ADATA		$1E
		ADATA		$1B
		ADATA		$00
		ADATA		$39
		ASTOP
_snd03_A:
		ACMDF2		$04
		ACMDF0		$0F
		ACMDF5		$1B
		ASMPL		_sample00
		ACMDF4		$FF
		ADATA		$1E
		ADATA		$1B
		ADATA		$00
		ADATA		$39
		ASTOP
_snd03_B:
		ACMDF2		$04
		ADMC		_pcm1
		ADATA		$1F
		ADATA		$1E
		ADATA		$1D
		ADATA		$3C
		ASTOP
_snd04_A:
		ACMDF2		$00
		ASMPL		_sample02
		ACMDF0		$00
		ACMDF4		$00
		ACMDF5		$21
		ADATAEX		$C2,$00
		ALOOP_START	$06
		ACMDE3		$EC
		ACMDF3		$01
		ACMDF1		$01
		ALOOP_END
		ALOOP_START	$07
		ALOOP_START	$06
		ACMDE3		$FA
		ACMDF3		$01
		ALOOP_END
		ALOOP_START	$06
		ACMDE3		$08
		ACMDF3		$01
		ALOOP_END
		ALOOP_END
		ACMDF0		$0D
		ACMDF5		$38
		ADATA		$3E
		ADATA		$70
		ADATA		$2A
		ASTOP
_snd04_B:
		ACMDF2		$00
		ACMDF0		$0F
		ASMPL		_sample00
		ACMDF4		$00
		ALOOP_START	$03
		ACMDF5		$0F
		AJSR		_asub_52A42
		ACMDF5		$03
		AJSR		_asub_52A42
		ACMDF1		$FB
		ALOOP_END
		ASTOP
_asub_52A42:
		ADATA		$09
		ADATA		$07
		ADATA		$05
		ADATA		$03
		ADATA		$01
		ADATA		$1F
		ARET
_snd05_A:
		ACMDF2		$00
		ACMDF0		$0B
		ASMPL		_sample01
		ACMDF4		$00
		ACMDF5		$14
		ADATA		$2B
		ADATA		$28
		ACMDF1		$FF
		ADATA		$24
		ADATA		$20
		ACMDF1		$FE
		ADATA		$3D
		ADATA		$3A
		ASTOP
_snd05_B:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$26
		ADATA		$09
		ADATA		$0B
		ADATA		$4D
		ASTOP
_snd06_A:
		ACMDF2		$00
		ACMDF0		$05
		ASMPL		_sample02
		ACMDF4		$00
		ADATAEX		$C1,$00
		ALOOP_START	$03
		ACMDE3		$01
		ACMDF3		$02
		ACMDF1		$01
		ALOOP_END
		ACMDF0		$0F
		ADATA		$05
		ADATA		$07
		ADATA		$08
		ALOOP_START	$05
		ADATA		$0E
		ADATA		$0D
		ADATA		$0B
		ACMDF1		$FD
		ALOOP_END
		ASTOP
_snd06_B:
		ACMDF2		$00
		ACMDF0		$05
		ACMDF5		$33
		ASMPL		_sample00
		ADATA		$0E
		ADATA		$0F
		ADATA		$0C
		ADATA		$0D
		ADATA		$0A
		ADATA		$0B
		ACMDF0		$0D
		ASMPL		_sample02
		ACMDF5		$0F
		ADATA		$0F
		ADATA		$0B
		ADATA		$0A
		ALOOP_START	$03
		ADATA		$1B
		ADATA		$00
		ADATA		$17
		ADATA		$10
		ADATA		$1C
		ADATA		$16
		ADATA		$1B
		ACMDF1		$FC
		ALOOP_END
		ASTOP
_snd07_A:
		ACMDF2		$00
		ASMPL		_sample03
		ACMDF0		$0D
		ACMDF4		$00
		ACMDF5		$0F
		ADATA		$11
		ADATA		$12
		ADATA		$15
		ADATA		$18
		ADATA		$19
		ADATA		$1C
		ADATA		$1F
		ADATA		$1D
		ADATA		$00
		ACMDF5		$11
		ADATA		$1E
		ADATA		$01
		ADATA		$02
		ADATA		$03
		ASTOP
_snd07_B:
		ACMDF2		$00
		ACMDF0		$0F
		ASMPL		_sample00
		ACMDF4		$00
		ADATA		$4E
		ADATA		$4D
		ADATA		$4C
		ACMDF0		$0A
		ADATA		$0C
		ADATA		$0B
		ADATA		$0A
		ACMDF1		$FF
		ADATA		$09
		ADATA		$08
		ADATA		$07
		ACMDF1		$FD
		ADATA		$06
		ADATA		$05
		ASTOP
_snd08_A:
		ACMDF2		$00
		ASMPL		_sample00
		ACMDF0		$0F
		ACMDF4		$00
		ACMDF5		$35
		ADATA		$1B
		ADATA		$1C
		ADATA		$1D
		ADATA		$1F
		ADATA		$01
		ALOOP_START	$06
		ADATA		$03
		ADATA		$04
		ALOOP_END
		ACMDF5		$3C
		ADATA		$10
		ALOOP_START	$02
		ADATA		$19
		ADATA		$1A
		ADATA		$1B
		ADATA		$30
		ALOOP_END
		ACMDF1		$FF
		ADATA		$18
		ADATA		$19
		ADATA		$1A
		ADATA		$10
		ADATA		$16
		ADATA		$17
		ADATA		$18
		ADATA		$10
		ACMDF1		$FD
		ADATA		$15
		ADATA		$16
		ADATA		$17
		ASTOP
_snd09_A:
		ACMDF2		$00
		ACMDF0		$02
		ASMPL		_sample02
		ACMDF4		$00
		ACMDF5		$20
		ADATAEX		$D4,$00
		ALOOP_START	$06
		ACMDE3		$EB
		ACMDF3		$02
		ACMDF1		$01
		ALOOP_END
_aloc_52B27:
		ACMDE3		$20
		ACMDF3		$01
		ACMDE3		$E0
		ACMDF3		$01
		ACMDE3		$2C
		ACMDF3		$01
		ACMDE3		$D4
		ACMDF3		$01
		AJMP		_aloc_52B27
;		ASTOP
_snd09_B:
		ACMDF2		$00
		ACMDF0		$05
		ASMPL		_sample00
		ACMDF4		$00
_aloc_52B43:
		ADATA		$26
		ADATAEX		$CC,$0A
		ADATA		$A9
		ADATA		$4F
		ADATA		$47
		ADATA		$8F
		ADATA		$68
		AJMP		_aloc_52B43
_snd0A_A:
		ACMDF2		$00
		ACMDF0		$0D
		ACMDF4		$00
		ASMPL		_sample2C
		ACMDF5		$3F
		ADATAEX		$CB,$64
		ASTOP
_snd0A_B:
		ACMDF2		$00
		ADATA		$AF
		ACMDF0		$07
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$0E
		ACMDF1		$04
		ADATA		$2D
		ACMDF1		$04
		ALOOP_START	$04
		ADATA		$2C
		ADATA		$0B
		ALOOP_END
		ADATA		$2B
		ADATA		$2A
		ADATA		$29
		ADATA		$28
		ADATA		$07
		ASTOP
_snd0B_A:
		ACMDF2		$00
		ACMDF0		$0B
		ACMDF4		$00
		ASMPL		_sample01
		ACMDF5		$33
		ADATA		$26
		ADATA		$28
		ACMDF0		$05
		ALOOP_START	$03
		ADATA		$06
		ADATA		$28
		ACMDF1		$FE
		ALOOP_END
		ASTOP
_snd0C_A:
		ACMDF2		$00
		ACMDF0		$0C
		ACMDF4		$00
		ASMPL		_sample01
		ACMDF5		$33
		ADATA		$46
		ADATA		$8D
		ACMDF0		$04
		ALOOP_START	$04
		ADATA		$46
		ADATA		$AD
		ACMDF1		$FF
		ALOOP_END
		ASTOP
_snd0D_A:
		ACMDF2		$00
		ACMDF0		$00
		ACMDF4		$00
		ACMDF5		$27
		ASMPL		_sample02
		ADATAEX		$C6,$00
		ALOOP_START	$08
		ACMDE3		$F9
		ACMDF3		$01
		ACMDF1		$F9
		ACMDE3		$F9
		ACMDF3		$01
		ACMDF1		$08
		ALOOP_END
		ASTOP
_snd0E_A:
		ACMDF2		$00
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF0		$0F
		ACMDF5		$17
		ADATA		$10
		ADATA		$11
		ADATA		$14
		ADATA		$18
		ADATA		$1C
		ASMPL		_sample03
		ALOOP_START	$02
		ADATA		$01
		ADATA		$02
		ADATA		$1B
		ALOOP_END
		ADATAEX		$D0,$10
		ACMDF5		$0F
		AJSR		_asub_52BF8
		ADATAEX		$D0,$0C
		ACMDF5		$0C
		AJSR		_asub_52BF8
		ADATAEX		$D0,$0A
		ACMDF5		$09
		AJSR		_asub_52BF8
		ADATAEX		$D0,$08
		ACMDF5		$06
		AJSR		_asub_52BF8
		ADATAEX		$D0,$06
		ACMDF5		$04
		AJSR		_asub_52BF8
		ASTOP
_asub_52BF8:
		ADATA		$10
		ASMPL		_sample01
		ADATA		$0A
		ADATA		$07
		ADATA		$03
		ADATA		$1E
		ASMPL		_sample00
		ADATA		$1E
		ADATA		$1A
		ARET
_snd0E_B:
		ACMDF2		$00
		ACMDF0		$0D
		ASMPL		_sample00
		ACMDF4		$00
		ACMDF5		$14
		ADATA		$11
		ADATA		$14
		ADATA		$18
		ADATA		$1C
		ALOOP_START	$02
		ADATA		$0A
		ADATA		$00
		ADATA		$1E
		ALOOP_END
		ADATAEX		$D0,$10
		ACMDF5		$0F
		AJSR		_asub_52C3C
		ADATAEX		$D0,$0C
		ACMDF5		$0E
		AJSR		_asub_52C3C
		ADATAEX		$D0,$0A
		ACMDF5		$0A
		AJSR		_asub_52C3C
		ADATAEX		$D0,$08
		ACMDF5		$05
		AJSR		_asub_52C3C
		ADATAEX		$D0,$06
		ACMDF5		$04
		AJSR		_asub_52C3C
		ASTOP
_asub_52C3C:
		ACMDF0		$0C
		ADATA		$0D
		ADATA		$0A
		ACMDF1		$FC
		ADATA		$06
		ADATA		$01
		ACMDF1		$FB
		ADATA		$1C
		ADATA		$1D
		ADATA		$1B
		ACMDF0		$0F
		ARET
_snd0F_A:
		ACMDF2		$00
		ACMDF0		$0F
		ASMPL		_sample00
		ACMDF4		$00
		ACMDF5		$3F
		ADATAEX		$C0,$00
		ALOOP_START	$0A
		ACMDE3		$01
		ACMDF3		$01
		ACMDF1		$FA
		ACMDE3		$FF
		ACMDF3		$01
		ACMDF1		$04
		ALOOP_END
		ASTOP
_snd0F_B:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$28
		ALOOP_START	$07
		ADATA		$22
		ACMDF1		$FE
		ALOOP_END
		ASTOP
_snd10_A:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample02
		ACMDF5		$14
		ADATA		$13
		ADATA		$17
		ADATA		$19
		ADATA		$70
		ACMDF1		$FF
		ASMPL		_sample01
		ACMDF5		$22
		ADATA		$12
		ADATA		$15
		ADATA		$18
		ADATA		$19
		ASTOP
_snd11_A:
		ACMDF2		$00
		ACMDF0		$05
		ASMPL		_sample01
		ACMDF4		$00
		ACMDF5		$27
		ADATA		$21
		ACMDF1		$01
		ADATA		$02
		ACMDF1		$01
		ADATA		$04
		ACMDF1		$01
		ADATA		$06
		ACMDF1		$02
		ADATA		$08
		ACMDF1		$02
		ADATA		$0D
		ACMDF1		$01
		ACMDF5		$33
		ADATA		$04
		ACMDF1		$02
		ADATA		$05
		ADATA		$04
		ASTOP
_snd12_A:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$0C
		ADATA		$0E
		ACMDF0		$0A
		ADATA		$0D
		ACMDF1		$01
		ADATA		$0C
		ACMDF1		$01
		ADATA		$0B
		ACMDF1		$01
		ADATA		$09
		ACMDF1		$01
		ADATA		$08
		ALOOP_START	$05
		ADATA		$05
		ACMDF1		$FF
		ADATA		$03
		ACMDF1		$FE
		ALOOP_END
		ASTOP
_snd12_B:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample01
		ACMDF5		$0F
		ADATA		$11
		ADATA		$13
		ACMDF1		$FF
		ADATA		$11
		ACMDF1		$FF
		ADATA		$12
		ACMDF1		$FF
		ADATA		$13
		ACMDF1		$FF
		ADATA		$16
		ACMDF1		$FF
		ADATA		$19
		ACMDF1		$FF
		ADATA		$17
		ACMDF1		$FF
		ADATA		$1A
		ACMDF1		$FF
		ADATA		$1D
		ADATA		$1E
		ADATA		$1D
		ADATA		$1E
		ASTOP
_snd13_A:
		ACMDF5		$20
_aloc_52D02:
		ACMDF0		$03
		ACMDF4		$00
		ASMPL		_sample02
		ACMDF2		$00
		ADATAEX		$C7,$00
		ACMDE3		$FC
		ACMDF3		$01
		ACMDF1		$02
		ACMDE3		$FD
		ACMDF3		$01
		ACMDF1		$02
		ACMDE3		$03
		ACMDF3		$01
		ACMDF1		$02
		ALOOP_START	$09
		ACMDE3		$FD
		ACMDF3		$01
		ALOOP_END
		ACMDE3		$00
		ACMDF3		$32
		ALOOP_START	$0A
		ACMDE3		$05
		ACMDF3		$01
		ACMDF1		$FF
		ALOOP_END
		ACMDF0		$01
		ADATAEX		$CA,$00
		ACMDE3		$00
		ACMDF3		$04
		ALOOP_START	$12
		ACMDE3		$02
		ACMDF3		$01
		ALOOP_END
		ASTOP
_snd13_B:
		ACMDF5		$1B
		AJMP		_aloc_52D02
_snd13_C:
		ACMDF2		$00
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF0		$07
		ADATA		$28
		ADATA		$A7
		ADATA		$A6
		ALOOP_START	$19
		ADATA		$07
		ADATA		$06
		ALOOP_END
		ADATA		$06
		ADATA		$87
		ACMDF1		$FE
		ADATA		$89
		ACMDF1		$FE
		ACMDF0		$03
		ADATA		$A7
		ADATA		$A8
		ADATA		$A9
		ACMDF1		$FF
		ADATA		$AA
		ASTOP
_snd14_A:
		ACMDF2		$00
		ACMDF0		$08
		ASMPL		_sample00
		ACMDF4		$00
		ADATA		$0E
		ACMDF1		$02
		ADATA		$0D
		ACMDF1		$02
		ADATA		$0E
		ACMDF1		$02
		ADATA		$0C
		ACMDF1		$01
		ADATA		$0D
		ADATA		$0C
		ADATA		$0D
		ADATA		$0B
		ADATA		$0C
		ADATA		$0A
		ADATA		$0B
		ADATA		$09
		ADATA		$0A
		ACMDF0		$0F
		ALOOP_START	$02
		ACMDF1		$FF
		ADATA		$09
		ACMDF1		$FF
		ADATA		$08
		ACMDF1		$FF
		ADATA		$27
		ACMDF1		$FF
		ADATA		$26
		ACMDF1		$FF
		ADATA		$45
		ACMDF0		$06
		ALOOP_END
		ASTOP
_snd15_A:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ALOOP_START	$02
		ADATA		$05
		ADATA		$07
		ADATA		$06
		ADATA		$08
		ALOOP_END
		ADATA		$07
		ADATA		$09
		ADATA		$08
		ADATA		$0A
		ADATA		$09
		ADATA		$0B
		ADATA		$0A
		ADATA		$09
		ADATA		$0C
		ALOOP_START	$0F
		ADATA		$0B
		ADATA		$0E
		ADATA		$0C
		ADATA		$0E
		ALOOP_END
		ALOOP_START	$07
		ADATA		$0B
		ADATA		$0E
		ADATA		$0C
		ADATA		$0E
		ACMDF1		$FE
		ALOOP_END
		ASTOP
_snd16_A:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$07
		ADATA		$06
		ADATA		$07
		AJSR		_asub_52DF9
		AJSR		_asub_52DFF
		ACMDF1		$FB
		AJSR		_asub_52DF9
		AJSR		_asub_52DFF
		ACMDF1		$01
		AJSR		_asub_52DF9
		AJSR		_asub_52DFF
		ACMDF0		$0F
		ALOOP_START	$02
		ADATA		$05
		ADATA		$06
		ADATA		$07
		ALOOP_END
		AJSR		_asub_52DF9
		ALOOP_START	$05
		AJSR		_asub_52E09
		ACMDF1		$FD
		ALOOP_END
		ASTOP
_asub_52DF9:
		ADATA		$06
		ADATA		$08
		ADATA		$07
		ADATA		$08
		ADATA		$09
		ARET
_asub_52DFF:
		ALOOP_START	$02
		ADATA		$0C
		ADATA		$0E
		ADATA		$0D
		ADATA		$0E
		ADATA		$0D
		ADATA		$0E
		ALOOP_END
		ARET
_asub_52E09:
		ADATA		$2D
		ADATA		$2C
		ADATA		$2D
		ADATA		$2E
		ARET
_snd17_A:
		ACMDF2		$00
		ACMDF0		$00
		ACMDF4		$00
		ASMPL		_sample02
		ACMDF5		$2C
		ADATAEX		$CE,$00
		ALOOP_START	$08
		ACMDE3		$00
		ACMDF3		$03
		ACMDF1		$01
		ALOOP_END
		ALOOP_START	$02
		ACMDE3		$01
		ACMDF3		$03
		ACMDF1		$01
		ALOOP_END
		ALOOP_START	$03
		ACMDE3		$01
		ACMDF3		$05
		ALOOP_END
		ALOOP_START	$08
		ACMDE3		$01
		ACMDF3		$03
		ACMDE3		$01
		ACMDF3		$03
		ACMDF1		$FF
		ALOOP_END
		ALOOP_START	$05
		ACMDE3		$01
		ACMDF3		$04
		ALOOP_END
		ACMDF1		$FF
		ALOOP_START	$03
		ACMDE3		$01
		ACMDF3		$05
		ALOOP_END
		ASTOP
_snd17_B:
		ADATAEX		$D0,$04
		AJMP		_snd17_A
_snd18_A:
		ACMDF2		$00
		ACMDF0		$03
		ASMPL		_sample03
		ACMDF4		$00
		ACMDF5		$24
		ADATA		$12
		ADATA		$13
		ACMDF1		$02
		ADATA		$16
		ADATA		$19
		ACMDF1		$03
		ADATA		$1C
		ADATA		$1F
		ACMDF1		$03
		ADATA		$02
		ADATA		$05
		ASTOP
_snd18_B:
		ACMDF2		$00
		ACMDF0		$0A
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$0D
		ADATA		$0E
		ACMDF1		$01
		ADATA		$0D
		ADATA		$0C
		ACMDF1		$01
		ADATA		$0B
		ADATA		$0C
		ACMDF1		$02
		ADATA		$0B
		ADATA		$0A
		ACMDF1		$01
		ADATA		$09
		ADATA		$07
		ASTOP
_snd19_A:
		ACMDF2		$00
		ACMDF0		$0B
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF5		$2F
		AJSR		_asub_52EA6
		ACMDF0		$0C
		ACMDF5		$18
		AJSR		_asub_52EBE
		ACMDF5		$2F
		ASMPL		_sample02
		AJSR		_asub_52ED4
		ASTOP
_asub_52EA6:
		ADATA		$1E
		ADATA		$00
		ADATA		$02
		ADATA		$05
		ADATA		$08
		ADATA		$0B
		ALOOP_START	$06
		ADATA		$0E
		ADATA		$0F
		ALOOP_END
		ADATA		$0D
		ADATA		$0E
		ADATA		$0C
		ADATA		$0D
		ADATA		$0B
		ADATA		$0C
		ADATA		$0A
		ADATA		$09
		ADATA		$08
		ADATA		$09
		ADATA		$07
		ADATA		$08
		ARET
_asub_52EBE:
		ASMPL		_sample00
		ADATA		$31
		ADATA		$14
		ADATA		$01
		ACMDF0		$04
		ADATA		$17
		ADATA		$04
		ACMDF1		$01
		ADATA		$1A
		ACMDF1		$01
		ADATA		$07
		ACMDF1		$01
		ADATA		$1D
		ACMDF1		$01
		ADATA		$0A
		ARET
_asub_52ED4:
		ACMDF1		$02
		ADATA		$18
		ADATA		$05
		ADATA		$06
		ARET
_snd19_B:
		ACMDF2		$00
		ACMDF0		$0D
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF5		$2C
		AJSR		_asub_52EA6
		ACMDF5		$1B
		ACMDF0		$0C
		AJSR		_asub_52EBE
		ACMDF5		$36
		ASMPL		_sample01
		AJSR		_asub_52ED4
		ASTOP
_snd19_C:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$07
		ADATA		$06
		ADATA		$05
		ADATA		$04
		ADATA		$03
		ADATA		$02
		ALOOP_START	$04
		ADATA		$02
		ADATA		$03
		ADATA		$01
		ALOOP_END
		ADATA		$23
		ADATA		$24
		ADATA		$25
		ADATA		$26
		ADATA		$27
		ADATA		$28
		ADATA		$08
		ADATA		$02
		ADATA		$0C
		ADATAEX		$CE,$00
		ALOOP_START	$05
		ACMDE3		$FE
		ACMDF3		$02
		ALOOP_END
		ASTOP
_snd1A_A:
		ACMDF2		$00
		ACMDF0		$09
		ACMDF4		$00
		ASMPL		_sample00
		AJSR		_asub_52F38
		ACMDF0		$08
		ALOOP_START	$04
		AJSR		_asub_52F4C
		ACMDF1		$FE
		ALOOP_END
		ACMDF0		$01
		AJSR		_asub_52F4C
		ASTOP
_asub_52F38:
		ADATA		$24
		ADATA		$05
		ACMDF1		$01
		ADATA		$26
		ADATA		$07
		ACMDF1		$02
		ADATA		$08
		ADATA		$09
		ACMDF1		$02
		ADATA		$0A
		ADATA		$0B
		ACMDF1		$01
		ADATA		$0C
		ADATA		$0D
		ADATA		$2E
		ARET
_asub_52F4C:
		ADATA		$2B
		ADATA		$2E
		ADATA		$2D
		ADATA		$2E
		ADATA		$2C
		ADATA		$0F
		ARET
_snd1A_B:
		ACMDF2		$00
		ACMDF0		$08
		ASMPL		_sample00
		ACMDF4		$00
		ACMDF5		$27
		AJSR		_asub_52F87
		ACMDF5		$23
		ACMDF0		$04
		AJSR		_asub_52F9B
		ACMDF0		$03
		ACMDF5		$1D
		AJSR		_asub_52F9B
		ACMDF0		$02
		ACMDF5		$19
		AJSR		_asub_52F9B
		ACMDF0		$01
		ACMDF5		$14
		AJSR		_asub_52F9B
		ACMDF5		$13
		AJSR		_asub_52F9B
		ACMDF5		$12
		AJSR		_asub_52F9B
		ASTOP
_asub_52F87:
		ADATA		$2F
		ADATA		$0E
		ACMDF1		$01
		ADATA		$2D
		ADATA		$0C
		ACMDF1		$02
		ADATA		$0A
		ADATA		$08
		ACMDF1		$01
		ADATA		$06
		ADATA		$01
		ACMDF1		$02
		ADATA		$1C
		ADATA		$17
		ADATA		$32
		ARET
_asub_52F9B:
		ADATA		$0F
		ADATA		$0E
		ADATA		$0D
		ADATA		$0C
		ADATA		$0A
		ADATA		$08
		ADATA		$06
		ADATA		$01
		ADATA		$1C
		ADATA		$17
		ADATA		$12
		ARET
_snd1A_C:
		ACMDF2		$00
		ACMDF0		$08
		ASMPL		_sample02
		ACMDF4		$00
		ACMDF5		$22
		AJSR		_asub_52F87
		ACMDF5		$23
		ACMDF0		$04
		AJSR		_asub_52F9B
		ACMDF5		$24
		ACMDF0		$03
		AJSR		_asub_52F9B
		ACMDF5		$25
		ACMDF0		$02
		AJSR		_asub_52F9B
		ACMDF5		$26
		ACMDF0		$01
		AJSR		_asub_52F9B
		ACMDF5		$27
		AJSR		_asub_52F9B
		AJSR		_asub_52F9B
		ASTOP
_snd1A_D:
		ACMDF2		$00
		ACMDF0		$0F
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF5		$18
		ADATA		$2F
		ADATA		$0E
		ADATA		$2D
		ADATA		$0C
		ADATA		$0A
		ADATA		$08
		ADATA		$06
		ADATA		$01
		ADATA		$1C
		ADATA		$17
		ADATA		$32
		ASTOP
_snd1B_A:
		ACMDF2		$00
		ACMDF0		$01
		ASMPL		_sample00
		ACMDF4		$00
		ALOOP_START	$07
		ADATA		$03
		ADATA		$04
		ADATA		$05
		ACMDF1		$02
		ALOOP_END
		ALOOP_START	$0F
		ADATA		$04
		ADATA		$05
		ADATA		$06
		ACMDF1		$FF
		ALOOP_END
		ASTOP
_snd1C_A:
		ACMDF2		$00
		ACMDF0		$09
		ASMPL		_sample00
		ACMDF4		$00
		ACMDF5		$32
		AJSR		_asub_53023
		ACMDF0		$08
		ALOOP_START	$03
		AJSR		_asub_53023
		ACMDF1		$FE
		ALOOP_END
		AJSR		_asub_53023
		ASTOP
_asub_53023:
		ADATA		$09
		ADATA		$07
		ADATA		$0A
		ADATA		$08
		ADATAEX		$D0,$00
		ADATAEX		$CA,$00
		ADATA		$0E
		ADATA		$08
		ADATA		$09
		ADATA		$0F
		ARET
_snd1D_A:
		ACMDF5		$2E
		ACMDF2		$00
		ACMDF0		$09
		ACMDF4		$00
		ASMPL		_sample00
		ADATA		$02
		ADATA		$0B
		ADATA		$07
		ADATA		$08
		ADATA		$05
		ADATA		$0D
		ADATA		$04
		AJMP		_snd1D_A
_snd1E_A:
		ACMDF2		$00
		ASMPL		_sample00
_aloc_53048:
		ACMDF0		$0C
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF5		$33
		ADATA		$3E
		ADATA		$1E
		ADATA		$20
		ADATA		$00
		ADATA		$23
		ADATA		$03
		ADATA		$24
		ADATA		$04
		ADATA		$2A
		ADATA		$0A
		ADATA		$24
		ADATA		$04
		ADATA		$27
		ADATA		$27
		ADATA		$29
		ADATA		$29
		ADATA		$4A
		ADATA		$4A
		ASTOP
_snd1E_B:
		ACMDF2		$00
		ADATA		$10
		ASMPL		_sample23
		AJMP		_aloc_53048
_snd1F_A:
		ACMDF2		$00
		ACMDF0		$05
		ACMDF4		$00
		ASMPL		_sample00
		ALOOP_START	$05
		AJSR		_asub_53092
		ACMDF1		$02
		ALOOP_END
		ALOOP_START	$05
		AJSR		_asub_53092
		ALOOP_END
		ALOOP_START	$07
		AJSR		_asub_53092
		ACMDF1		$FE
		ALOOP_END
		AJSR		_asub_53092
		ACMDF1		$FF
		AJSR		_asub_53092
		ASTOP
_asub_53092:
		ADATA		$2E
		ADATA		$2D
		ADATA		$0F
		ADATA		$4E
		ADATA		$0C
		ADATA		$0F
		ARET
_snd20_A:
		ACMDF2		$00
		ACMDF0		$09
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF5		$2C
		ADATA		$05
		ADATA		$07
		ADATA		$0C
		ADATA		$09
		ADATA		$0E
		AJMP		_snd20_A
_snd21_A:
		ACMDF2		$00
		ACMDF0		$0A
		ACMDF4		$00
		ASMPL		_sample00
		ACMDF5		$2C
		ADATA		$09
		ADATA		$07
		ADATA		$04
		ADATA		$0B
		ADATA		$09
		ADATA		$0E
		ADATA		$02
		AJMP		_snd21_A
_snd22_A:
		ACMDF2		$00
		ACMDF0		$0A
		ACMDF4		$00
		ACMDF5		$2B
		ASMPL		_sample00
		AJSR		_asub_530DE
		ACMDF5		$26
		ACMDF0		$0B
		AJSR		_asub_530EC
		ACMDF0		$09
		ALOOP_START	$04
		AJSR		_asub_530EE
		ACMDF1		$FE
		ALOOP_END
		ASTOP
_asub_530DE:
		ALOOP_START	$02
		ADATA		$0D
		ADATA		$0F
		ACMDF1		$02
		ALOOP_END
		ADATA		$0D
		ADATA		$0E
		ADATA		$0C
		ADATA		$0D
		ADATA		$0B
		ADATA		$0C
		ADATA		$0A
_asub_530EC:
		ADATA		$09
		ADATA		$08
_asub_530EE:
		ADATA		$09
		ADATA		$07
		ADATA		$08
		ADATA		$04
		ADATA		$07
		ADATA		$03
		ADATA		$06
		ADATA		$01
		ARET
_snd23_A:
		ACMDF2		$00
		ACMDF0		$05
		ASMPL		_sample01
		ACMDF4		$00
		ADATA		$0A
		ACMDF0		$08
		ACMDE2		$0F,$00
		ACMDF3		$01
		ADATA		$0E
		ACMDF0		$0C
		ADATA		$0D
		ACMDF0		$0E
		ADATA		$0C
		ACMDF0		$04
		ADATA		$2A
		ACMDF0		$03
		ADATA		$27
		ACMDF0		$02
		ADATA		$64
		ACMDF0		$01
		ADATA		$22
		ASTOP
_snd23_B:
		ACMDF2		$00
		ASMPL		_sample00
		ACMDF4		$00
		ACMDF5		$22
		ACMDF0		$0F
		ADATA		$14
		ADATA		$16
		ADATA		$12
		ADATA		$17
		ASTOP

		SECTION_END	"APU SOUND EFFECTS DATA"

		SECTION_START

_music_lib:
		MUS		_mus0	; lvl1 theme
		MUS		_mus1	; busters select
		MUS		_mus2	; game over
		MUS		_mus3	; stage complete
		MUS		_mus4	; mid-boss theme
		MUS		_mus5	; title theme
		MUS		_mus6	; lvl2 theme
		MUS		_mus7	; lvl3 theme
		MUS		_mus8	; lvl4 theme
		MUS		_mus9	; lvl5 theme
		MUS		_musA	; final boss prellude
		MUS		_musB	; final boss theme
		MUS		_musC	; lvl3 final cutscene
		MUS		_musD	; -unused-, see NOTE

_mus0:
		INCLUDE	"../mus/mus0_ntsc.inc"
_mus1:
		INCLUDE	"../mus/mus1_ntsc.inc"
_mus2:
		INCLUDE	"../mus/mus2_ntsc.inc"
_mus3:
		INCLUDE	"../mus/mus3_ntsc.inc"

; NOTE: this data is an exact copy of full library of _sampleXX codes.
; it has no pointer table associated, but all offsets are fixed to
; this particular location, so somehow they have his copy linked to
; the sources as well. definitely this is not just rtash from uninitialized
; RAM...
;
;		INCLUDE	"../mus/unused_jp.inc"

_mus4:
		INCLUDE	"../mus/mus4_ntsc.inc"
_mus5:
		INCLUDE	"../mus/mus5_ntsc.inc"
_mus6:
		INCLUDE	"../mus/mus6_ntsc.inc"
_mus7:
		INCLUDE	"../mus/mus7_ntsc.inc"
_mus8:
		INCLUDE	"../mus/mus8_ntsc.inc"
_mus9:
		INCLUDE	"../mus/mus9_ntsc.inc"
_musA:
		INCLUDE	"../mus/musA_ntsc.inc"
_musB:
		INCLUDE	"../mus/musB_ntsc.inc"
_musC:
		INCLUDE	"../mus/musC_ntsc.inc"

; NOTE: unused data for missing music track from the EU version
; there are no either header nor music library entry, literally
; can't be even played in any known nsf records.
;
; this is actually completely previously unknown track. main
; loop of this track is used at the end of Stage 3 in cutscene
; with ghost nunny (track 0C)... this track is a full version of
; it without loop. it has intro and outro and not looped at all.
;
; i added proper header with table of channels in order to be able
; to play it. will be possible to play it in the sound test later.
;
; need to mention, that although all tracks in PAL version were
; rewritten to play on 50Hz the same way as on 60Hz for NTSC,
; this particular unused track uses NTSC scheme. probably it is
; always been in the games sources but slipped throught only on
; this later re-release for some reason.
;
; on a second thought, there is possible they did it later based on
; short looped jingle of the Stage 3 ending but never actually used
;
_musD:
		INCLUDE	"../mus/musD_ntsc.inc"

		SECTION_END	"APU MUSIC DATA"

		BANK_END 6,$C000
