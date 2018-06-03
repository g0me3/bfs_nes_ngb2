
		ORG $8000

		BANK_START $06

; =============== S U B R O U T I N E =======================================
_apu_reset:
		LDX		#$00
		STX		_APU_DMC_LOAD
		DEX
		STX		_apu_var401
		STX		_apu_var402
		STX		_apu_var580
		LDX		#$0F
		STX		_APU_STATUS
		LDX		#$0F
		LDA		#$0E
loc_50018:
		STA		_apu_reg_var08,X
		DEX
		BPL		loc_50018
		LDA		#$FF
		JSR		_apu_mus_load
		LDA		#$FF

; =============== S U B R O U T I N E =======================================
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

; =============== S U B R O U T I N E =======================================
_apu_snd_load_ex:
		TAX
		BPL		loc_5003B
		JMP		sub_500AE
loc_5003B:
		LDA		_apu_var403
		BEQ		loc_50062
		AND		byte_5348F,X
		BEQ		loc_50062
		LDY		#$04
loc_50047:
		LDA		_apu_chnl_var0F,Y
		AND		byte_5348F,X
		BEQ		loc_5005C
		LDA		_apu_chnl_var0F+5,Y
		CMP		byte_534B3,X
		BCC		locret_50061
		LDA		#$00
		STA		_apu_chnl_var01,Y
loc_5005C:
		DEY
		BPL		loc_50047
		BMI		loc_50062
locret_50061:
		RTS
loc_50062:
		STX		_tmp7C4
		LDA		byte_5348F,X
		STA		_apu_var404
		LDA		byte_534B3,X
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
		LDA		_apu_chnl_var01,X
		BNE		loc_5009C
		JSR		sub_500DC
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

; =============== S U B R O U T I N E =======================================
sub_5009F:
		LDA		_apu_chnl_var0F
		LDX		#$04
loc_500A4:
		ORA		_apu_chnl_var0F,X
		DEX
		BNE		loc_500A4
		STA		_apu_var403
		RTS

; =============== S U B R O U T I N E =======================================
sub_500AE:
		LDX		#$04
loc_500B0:
		LDA		#$00
		STA		_apu_chnl_var01,X
		STA		_apu_chnl_var0F,X
		LDA		#$FF
		STA		_apu_chnl_var0F+5,X
		DEX
		BPL		loc_500B0
		LDX		#$0F
loc_500C2:
		LDA		byte_500CC,X
		STA		_apu_reg_var00,X
		DEX
		BPL		loc_500C2
		RTS
byte_500CC:
		.BYTE	$30,$7F,$00,$FF,$30,$7F,$00,$FF,$00,$00,$00,$00,$30,$00,$00,$FF

; =============== S U B R O U T I N E =======================================
sub_500DC:
		LDA		#$27
		STA		_apu_chnl_var06,X
		LDA		#$00
		STA		_apu_chnl_var08,X
		STA		_apu_chnl_var09,X
		STA		_apu_chnl_var0A,X
		STA		_apu_chnl_var0B,X
		STA		_apu_chnl_var0C,X
		LDA		byte_50723,X
		STA		_apu_chnl_var0D,X
		INY
		LDA		(_ptr08),Y
		STA		_apu_mus_pc_lo,X
		INY
		LDA		(_ptr08),Y
		STA		_apu_mus_pc_hi,X
		INY
		LDA		(_ptr08),Y
		STA		_apu_chnl_var00,X
		LDA		#$01
		STA		_apu_chnl_var01,X
		STA		_apu_chnl_var05,X
		DEC		_var1
		RTS

; =============== S U B R O U T I N E =======================================
_apu_mus_load:
		PHA
		LDX		#$04
loc_50118:
		LDA		#$00
		STA		_apu_chnl_var01+5,X
		DEX
		BPL		loc_50118
		LDX		#$0F
loc_50122:
		LDA		byte_500CC,X
		STA		_apu_reg_var04,X
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
		LDA		_apu_chnl_var01,X
		BNE		loc_5014C
		JSR		sub_500DC
		BEQ		locret_50151
loc_5014C:
		DEX
		CPX		#$04
		BNE		loc_50142
locret_50151:
		RTS

; =============== S U B R O U T I N E =======================================
_apu_play:
		LDA		#$C0
		STA		_PAD1_REG
		LDX		#$09
loc_50159:
		LDA		_apu_chnl_var01,X
		BEQ		loc_501A3
		LDA		off_5070F,X
		STA		_apu_ptr35
		LDA		off_50719,X
		STA		_apu_ptr35+1
		DEC		_apu_chnl_var01,X
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
		DEC		_apu_chnl_var02,X
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
		LDA		_apu_chnl_var01,X
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
		LDA		_apu_reg_var04,X
		BCC		loc_501CF
		LDA		_apu_reg_var00,X
loc_501CF:
		CMP		_apu_reg_var08,X
		BEQ		loc_501DA
		STA		_apu_reg_var08,X
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
		LDA		_apu_reg_var05,X
		BCC		loc_501EF
		LDA		_apu_reg_var01,X
loc_501EF:
		CMP		_apu_reg_var09,X
		BEQ		loc_501FA
		STA		_apu_reg_var09,X
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
		LDA		_apu_reg_var06,X
		BCC		loc_5020F
		LDA		_apu_reg_var02,X
loc_5020F:
		CMP		_apu_reg_var0A,X
		BEQ		loc_5021A
		STA		_apu_reg_var0A,X
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
		LDA		_apu_reg_var07,X
		BCC		loc_5022C
		LDA		_apu_reg_var03,X
loc_5022C:
		CMP		_apu_reg_var0B,X
		BEQ		loc_50237
		STA		_apu_reg_var0B,X
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
byte_50248:
		.BYTE	$08
byte_50249:
		.BYTE	$10

; =============== S U B R O U T I N E =======================================
_apu_fetch_next_cmd:
		JSR		_apu_getc

; =============== S U B R O U T I N E =======================================
_apu_mus_fetch:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$E0
		CMP		#$E0
		BNE		_apu_mus_data_fetch
		JMP		_apu_mus_cmd_fetch

; =============== S U B R O U T I N E =======================================
_apu_mus_data_fetch:
		LDA		_apu_chnl_var00,X
		CMP		#$0C
		BNE		loc_50287
		LDA		(_apu_cur_pc),Y
		BIT		byte_50249
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
		BIT		byte_50249
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
		JMP		_apu_fetch_next_cmd
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
		JSR		sub_502E5
		JMP		loc_502AE

; =============== S U B R O U T I N E =======================================
sub_502E5:
		LDA		_apu_chnl_var0A,X
		BMI		nullsub_2

; =============== S U B R O U T I N E =======================================
sub_502EA:
		ASL
		ASL
		TAY

; =============== S U B R O U T I N E =======================================
sub_502ED:
		LDA		_samples_lib,Y
		STA		_apu_snd_pc_lo,X
		LDA		_samples_lib+1,Y
		STA		_apu_snd_pc_hi,X
		LDA		byte_5072D,X
		STA		_apu_chnl_var0E,X
		LDA		#$01
		STA		_apu_chnl_var02,X

; =============== S U B R O U T I N E =======================================
nullsub_2:
		RTS

; =============== S U B R O U T I N E =======================================
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
		LDA		byte_533FD,Y
loc_50321:
		STA		_apu_chnl_var01,X
		RTS

; =============== S U B R O U T I N E =======================================
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
		JMP		_apu_fetch_next_cmd
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
		LDA		#$0F		; *--
		BNE		loc_50365	; *--
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
		JMP		_apu_fetch_next_cmd
loc_5037B:
		CMP		#$F3
		BNE		loc_5038D
		JSR		_apu_getc
		STA		_apu_chnl_var01,X
		LDA		#$FF
		STA		_apu_chnl_var05,X
		JMP		_apu_getc
loc_5038D:
		CMP		#$F4
		BNE		loc_5039A
		JSR		_apu_getc
		STA		_apu_chnl_var08,X
		JMP		_apu_fetch_next_cmd
loc_5039A:
		CMP		#$F5
		BNE		loc_503A7
		JSR		_apu_getc
		STA		_apu_chnl_var06,X
		JMP		_apu_fetch_next_cmd
loc_503A7:
		CMP		#$F6
		BNE		loc_503B9
		JSR		_apu_getc
		STA		_apu_chnl_var0A,X
		BPL		loc_503B6
		JSR		sub_502EA
loc_503B6:
		JMP		_apu_fetch_next_cmd
loc_503B9:
		CMP		#$F7
		BNE		loc_503C6
		JSR		_apu_getc	; *--
		STA		_apu_chnl_var0C,X ; *--
		JMP		_apu_fetch_next_cmd ; *--
loc_503C6:
		CMP		#$E0
		BNE		loc_503D9
		JSR		_apu_getc
		STA		_APU_DMC_ADDR
		JSR		_apu_getc
		STA		_APU_DMC_LEN
		JMP		_apu_fetch_next_cmd
loc_503D9:
		CMP		#$E2
		BNE		loc_50403
		JSR		_apu_getc
		PHA
		JSR		_apu_getc
		LDY		_apu_chnl_var00,X
		INY
		INY
		INY
		AND		#$0F
		STA		_tmp19
		LDA		_apu_reg_var08,Y
		AND		#$10
		EOR		#$10
		ORA		_tmp19
		STA		(_apu_ptr35),Y
		PLA
		DEY
		STA		(_apu_ptr35),Y
		JSR		sub_502E5
		JMP		_apu_fetch_next_cmd
loc_50403:
		CMP		#$E3
		BNE		loc_50413
		JSR		_apu_getc
		BPL		loc_5040D
		DEY
loc_5040D:
		JSR		sub_50665
		JMP		_apu_fetch_next_cmd
loc_50413:
		CMP		#$E1
		BNE		loc_50420
		JSR		_apu_getc
		STA		_apu_var400
		JMP		_apu_fetch_next_cmd
loc_50420:
		CMP		#$FF
		BNE		loc_50430
		LDA		#$00
		STA		_apu_chnl_var01,X
		STA		_apu_chnl_var02,X
		JSR		sub_505E6
		RTS
loc_50430:
		LDA		_apu_chnl_var0D,X
		STA		_apu_sp
		JSR		_apu_logic_cmd_exec
		LDA		_apu_sp
		STA		_apu_chnl_var0D,X
		JMP		_apu_mus_fetch

; =============== S U B R O U T I N E =======================================
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
		LDY		_apu_sp
		LDA		_apu_cur_pc+1
		DEY
		STA		_apu_stack,Y
		LDA		_apu_cur_pc
		DEY
		STA		_apu_stack,Y
		STY		_apu_sp
		PLA
		STA		_apu_cur_pc+1
		PLA
		STA		_apu_cur_pc
		RTS
loc_50479:
		CMP		#$FB
		BNE		loc_5048E
		LDY		_apu_sp
		LDA		_apu_stack,Y
		STA		_apu_cur_pc
		INY
		LDA		_apu_stack,Y
		STA		_apu_cur_pc+1
		INY
		STY		_apu_sp
		RTS
loc_5048E:
		CMP		#$FC
		BNE		loc_504AF
		JSR		_apu_getc
		PHA
		JSR		_apu_getc
		LDY		_apu_sp
		LDA		_apu_cur_pc+1
		DEY
		STA		_apu_stack,Y
		LDA		_apu_cur_pc
		DEY
		STA		_apu_stack,Y
		PLA
		DEY
		STA		_apu_stack,Y
		STY		_apu_sp
		RTS
loc_504AF:
		CMP		#$FD
		BNE		loc_504D4
		LDY		_apu_sp
		LDA		_apu_stack,Y
		SEC
		SBC		#$01
		STA		_apu_stack,Y
		BEQ		loc_504CB
		LDA		_apu_stack+1,Y
		STA		_apu_cur_pc
		LDA		_apu_stack+2,Y
		STA		_apu_cur_pc+1
		RTS
loc_504CB:
		INC		_apu_sp
		INC		_apu_sp
		INC		_apu_sp
		JMP		_apu_getc
loc_504D4:
		; *--
		CMP		#$FE
		BNE		locret_504DE	; *--
		JSR		_apu_getc	; *--
		JMP		_apu_getc	; *--
locret_504DE:
		; *--
		RTS

; =============== S U B R O U T I N E =======================================
_apu_getc:
		INC		_apu_cur_pc
		BNE		loc_504E5
		INC		_apu_cur_pc+1
loc_504E5:
		LDA		(_apu_cur_pc),Y
		RTS

; =============== S U B R O U T I N E =======================================
sub_504E8:
		PHA
		LDA		_apu_chnl_var0C,X
		ASL
		TAY
		LDA		off_50737,Y
		STA		_ptr17
		LDA		off_50737+1,Y
		STA		_ptr17+1
		PLA
		ASL
		TAY
		LDA		(_ptr17),Y
		STA		_tmp19
		INY
		LDA		(_ptr17),Y
		LDY		_apu_chnl_var00,X
		INY
		INY
		STA		(_apu_ptr35),Y
		INY
		LDA		_apu_reg_var08,Y
		AND		#$10
		EOR		#$10
		ORA		byte_50519,X
		ORA		_tmp19
		STA		(_apu_ptr35),Y
		RTS
byte_50519:
		.BYTE	$00,$00,$00,$00,$00,$20,$20,$20,$20,$20 ;	*--

; =============== S U B R O U T I N E =======================================
sub_50523:
		LDA		_apu_chnl_var05,X
		BEQ		locret_5053C
		CMP		#$FF
		BEQ		locret_5053C
		DEC		_apu_chnl_var05,X
		BNE		locret_5053C
		LDA		_apu_chnl_var0A,X
		ASL
		ASL
		TAY
		INY
		INY
		JMP		sub_502ED
locret_5053C:
		RTS

; =============== S U B R O U T I N E =======================================
sub_5053D:
		JSR		_apu_getc

; =============== S U B R O U T I N E =======================================
_apu_snd_fetch:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$E0
		BNE		loc_50552
		LDA		(_apu_cur_pc),Y
		AND		#$1F
		STA		_apu_chnl_var02,X
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
		BEQ		sub_5053D
		LDA		#$01
		STA		_apu_chnl_var02,X
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
		LDA		#$0F		; *--
loc_50592:
		JSR		sub_505E6
		JMP		loc_5055C
loc_50598:
		CMP		#$80
		BNE		loc_505B5
		LDA		(_apu_cur_pc),Y
		AND		#$0F
		LDY		_apu_chnl_var00,X
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
		JSR		_apu_getc	; *--
		LDY		_apu_chnl_var00,X ; *--
		INY				; *--
		STA		(_apu_ptr35),Y	; *--
		JMP		sub_5053D	; *--
loc_505CB:
		CMP		#$FF
		BNE		loc_505D5
		LDA		#$00
		STA		_apu_chnl_var02,X
		RTS
loc_505D5:
		LDA		_apu_chnl_var0E,X
		STA		_apu_sp
		JSR		_apu_logic_cmd_exec
		LDA		_apu_sp
		STA		_apu_chnl_var0E,X
		JMP		_apu_snd_fetch
locret_505E5:
		; *--
		RTS

; =============== S U B R O U T I N E =======================================
sub_505E6:
		STA		_tmp19
		LDA		_apu_chnl_var09,X
		AND		#$F0
		ORA		_tmp19
		STA		_apu_chnl_var09,X

; =============== S U B R O U T I N E =======================================
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
		SBC		_apu_var401,Y
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
		LDY		_apu_chnl_var00,X
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

; =============== S U B R O U T I N E =======================================
sub_50647:
		LDY		#$00
		LDA		(_apu_cur_pc),Y
		AND		#$0F
		BIT		byte_50248
		BEQ		locret_50655
		ORA		#$F0
		DEY
locret_50655:
		RTS

; =============== S U B R O U T I N E =======================================
_apu_unref:
		LDY		#$00		; *--
		LDA		(_apu_cur_pc),Y	; *--
		AND		#$1F		; *--
		BIT		byte_50249	; *--
		BEQ		locret_50664	; *--
		ORA		#$E0       ; *--
		DEY				; *--
locret_50664:
		; *--
		RTS

; =============== S U B R O U T I N E =======================================
sub_50665:
		STY		_tmp19
		LDY		_apu_chnl_var00,X
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
byte_50679:
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
		.BYTE	<[_apu_reg_var00]
		.BYTE	<[_apu_reg_var00]
		.BYTE	<[_apu_reg_var00]
		.BYTE	<[_apu_reg_var00]
		.BYTE	<[_apu_reg_var00]
		.BYTE	<[_apu_reg_var04]
		.BYTE	<[_apu_reg_var04]
		.BYTE	<[_apu_reg_var04]
		.BYTE	<[_apu_reg_var04]
		.BYTE	<[_apu_reg_var04]
off_50719:
		.BYTE	>[_apu_reg_var00]
		.BYTE	>[_apu_reg_var00]
		.BYTE	>[_apu_reg_var00]
		.BYTE	>[_apu_reg_var00]
		.BYTE	>[_apu_reg_var00]
		.BYTE	>[_apu_reg_var04]
		.BYTE	>[_apu_reg_var04]
		.BYTE	>[_apu_reg_var04]
		.BYTE	>[_apu_reg_var04]
		.BYTE	>[_apu_reg_var04]
byte_50723:
		.BYTE	$10,$20,$30,$40,$50,$60,$70,$80,$90,$A0
byte_5072D:
		.BYTE	$06,$16,$26,$36,$46,$56,$66,$76,$86,$96
off_50737:
		.WORD	byte_50679
; REGION, proper restoration of this music track header to be able to play it normally
;
;_musD:
;		.BYTE	$05
;		.WORD	_musD_A
;		.BYTE	$00
;		.WORD	_musD_B
;		.BYTE	$08
;		.WORD	_musD_C
;		.BYTE	$04
;		.WORD	_musD_D
;		.BYTE	$0C
;		.WORD	_musD_E
;		.BYTE	$0C
; REGION, unused data for missing music track from the EU version
; there are no either header nor music library entry, literally
; can't be even played in any known nsf records.
;
; this is actually not completely previously unknown track. main
; loop of this track is used at the end of Stage 3 in cutscene
; with ghost nunny (track 0C)... this track is a full version of
; it without loop. it has intro and outro and not looped at all.
;
;_musD_A:
;		.BYTE	$F2,$01		; ACMDF2      $01
;		.BYTE	$F0,$0D		; ACMDF0      $0D
;		.BYTE	$F6,$29		; ACMDF6      $29
;		.BYTE	$F5,$0F		; ACMDF5      $0F
;		.BYTE	$F4,$C8		; ACMDF4      $C8
;		.BYTE	$FA		; AJSR	_asub_9A20C
;		.WORD	_asub_9A20C
;		.BYTE	$FA		; AJSR	_asub_9A223
;		.WORD	_asub_9A223
;		.BYTE	$F6,$15		; ACMDF6      $15
;		.BYTE	$F0,$0E		; ACMDF0      $0E
;		.BYTE	$FA		; AJSR	_asub_9A223
;		.WORD	_asub_9A223
;		.BYTE	$F5,$1B		; ACMDF5      $1B
;		.BYTE	$F0,$0D		; ACMDF0      $0D
;		.BYTE	$F6,$29		; ACMDF6      $29
;		.BYTE	$FA		; AJSR	_asub_9A239
;		.WORD	_asub_9A239
;		.BYTE	$FF		; ASTOP
;_asub_9A20C:
;		.BYTE	$FC,$08		; ALOOP_START $08
;		.BYTE	$38		; ADATA	$38
;		.BYTE	$37		; ADATA	$37
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$F4,$FF		; ACMDF4      $FF
;		.BYTE	$FC,$08		; ALOOP_START $08
;		.BYTE	$18		; ADATA	$18
;		.BYTE	$F1,$FE		; ACMDF1      $FE
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$F1,$02		; ACMDF1      $02
;		.BYTE	$17		; ADATA	$17
;		.BYTE	$F1,$FE		; ACMDF1      $FE
;		.BYTE	$03		; ADATA	$03
;		.BYTE	$F1,$02		; ACMDF1      $02
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FB		; ARET
;_asub_9A223:
;		.BYTE	$FC,$02		; ALOOP_START $02
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$18		; ADATA	$18
;		.BYTE	$0F		; ADATA	$0F
;		.BYTE	$1F		; ADATA	$1F
;		.BYTE	$0F		; ADATA	$0F
;		.BYTE	$00		; ADATA	$00
;		.BYTE	$0F		; ADATA	$0F
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$17		; ADATA	$17
;		.BYTE	$0E		; ADATA	$0E
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$0E		; ADATA	$0E
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$0E		; ADATA	$0E
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FB		; ARET
;_asub_9A239:
;		.BYTE	$19		; ADATA	$19
;		.BYTE	$23		; ADATA	$23
;		.BYTE	$19		; ADATA	$19
;		.BYTE	$23		; ADATA	$23
;		.BYTE	$19		; ADATA	$19
;		.BYTE	$03		; ADATA	$03
;		.BYTE	$29		; ADATA	$29
;		.BYTE	$08		; ADATA	$08
;		.BYTE	$10		; ADATA	$10
;		.BYTE	$19		; ADATA	$19
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$08		; ADATA	$08
;		.BYTE	$19		; ADATA	$19
;		.BYTE	$03		; ADATA	$03
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$0F		; ADATA	$0F
;		.BYTE	$2F		; ADATA	$2F
;		.BYTE	$FB		; ARET
;_musD_B:
;		.BYTE	$F2,$01		; ACMDF2      $01
;		.BYTE	$F0,$0E		; ACMDF0      $0E
;		.BYTE	$F5,$1B		; ACMDF5      $1B
;		.BYTE	$F6,$00		; ACMDF6      $00
;		.BYTE	$F4,$FF		; ACMDF4      $FF
;		.BYTE	$FA		; AJSR	_asub_9A20C
;		.WORD	_asub_9A20C
;		.BYTE	$F4,$00		; ACMDF4      $00
;		.BYTE	$FA		; AJSR	_asub_9A266
;		.WORD	_asub_9A266
;		.BYTE	$FA		; AJSR	_asub_9A266
;		.WORD	_asub_9A266
;		.BYTE	$F5,$1B		; ACMDF5      $1B
;		.BYTE	$FA		; AJSR	_asub_9A27C
;		.WORD	_asub_9A27C
;		.BYTE	$FF		; ASTOP
;_asub_9A266:
;		.BYTE	$FC,$02		; ALOOP_START $02
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$18		; ADATA	$18
;		.BYTE	$05		; ADATA	$05
;		.BYTE	$1F		; ADATA	$1F
;		.BYTE	$05		; ADATA	$05
;		.BYTE	$00		; ADATA	$00
;		.BYTE	$05		; ADATA	$05
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$17		; ADATA	$17
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FB		; ARET
;_asub_9A27C:
;		.BYTE	$1B		; ADATA	$1B
;		.BYTE	$25		; ADATA	$25
;		.BYTE	$1B		; ADATA	$1B
;		.BYTE	$25		; ADATA	$25
;		.BYTE	$1B		; ADATA	$1B
;		.BYTE	$05		; ADATA	$05
;		.BYTE	$2A		; ADATA	$2A
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$10		; ADATA	$10
;		.BYTE	$1B		; ADATA	$1B
;		.BYTE	$0B		; ADATA	$0B
;		.BYTE	$0A		; ADATA	$0A
;		.BYTE	$1B		; ADATA	$1B
;		.BYTE	$05		; ADATA	$05
;		.BYTE	$0B		; ADATA	$0B
;		.BYTE	$F4,$E6		; ACMDF4      $E6
;		.BYTE	$F5,$27		; ACMDF5      $27
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$24		; ADATA	$24
;		.BYTE	$FB		; ARET
;_musD_C:
;		.BYTE	$F2,$01		; ACMDF2      $01
;		.BYTE	$F0,$05		; ACMDF0      $05
;		.BYTE	$F6,$2B		; ACMDF6      $2B
;		.BYTE	$F4,$00		; ACMDF4      $00
;		.BYTE	$F5,$27		; ACMDF5      $27
;		.BYTE	$C3,$70		; ADATAEX     $C3,$70
;		.BYTE	$C2,$70		; ADATAEX     $C2,$70
;		.BYTE	$C1,$70		; ADATAEX     $C1,$70
;		.BYTE	$F1,$FF		; ACMDF1      $FF
;		.BYTE	$C0,$70		; ADATAEX     $C0,$70
;		.BYTE	$F0,$0C		; ACMDF0      $0C
;		.BYTE	$F6,$29		; ACMDF6      $29
;		.BYTE	$F5,$0F		; ACMDF5      $0F
;		.BYTE	$FA		; AJSR	_asub_9A2C0
;		.WORD	_asub_9A2C0
;		.BYTE	$F0,$0C		; ACMDF0      $0C
;		.BYTE	$F6,$23		; ACMDF6      $23
;		.BYTE	$FA		; AJSR	_asub_9A2C0
;		.WORD	_asub_9A2C0
;		.BYTE	$F5,$1B		; ACMDF5      $1B
;		.BYTE	$F0,$0D		; ACMDF0      $0D
;		.BYTE	$F6,$29		; ACMDF6      $29
;		.BYTE	$FA		; AJSR	_asub_9A2D6
;		.WORD	_asub_9A2D6
;		.BYTE	$FF		; ASTOP
;_asub_9A2C0:
;		.BYTE	$FC,$02		; ALOOP_START $02
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$18		; ADATA	$18
;		.BYTE	$0A		; ADATA	$0A
;		.BYTE	$1F		; ADATA	$1F
;		.BYTE	$0A		; ADATA	$0A
;		.BYTE	$00		; ADATA	$00
;		.BYTE	$0A		; ADATA	$0A
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$17		; ADATA	$17
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FB		; ARET
;_asub_9A2D6:
;		.BYTE	$14		; ADATA	$14
;		.BYTE	$3E		; ADATA	$3E
;		.BYTE	$14		; ADATA	$14
;		.BYTE	$3E		; ADATA	$3E
;		.BYTE	$14		; ADATA	$14
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$23		; ADATA	$23
;		.BYTE	$02		; ADATA	$02
;		.BYTE	$10		; ADATA	$10
;		.BYTE	$14		; ADATA	$14
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$03		; ADATA	$03
;		.BYTE	$14		; ADATA	$14
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$08		; ADATA	$08
;		.BYTE	$28		; ADATA	$28
;		.BYTE	$FB		; ARET
;_musD_D:
;		.BYTE	$F2,$01		; ACMDF2      $01
;		.BYTE	$E0,$F6,$06	; ACMDE0      $F6,$06
;		.BYTE	$FC,$04		; ALOOP_START $04
;		.BYTE	$DF,$70		; ADATAEX     $DF,$70
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$FC,$08		; ALOOP_START $08
;		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
;		.BYTE	$1F		; ADATA	$1F
;		.BYTE	$9F		; ADATA	$9F
;		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
;		.BYTE	$3C		; ADATA	$3C
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$5E		; ADATA	$5E
;		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
;		.BYTE	$1F		; ADATA	$1F
;		.BYTE	$9F		; ADATA	$9F
;		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
;		.BYTE	$5D		; ADATA	$5D
;		.BYTE	$1C		; ADATA	$1C
;		.BYTE	$3B		; ADATA	$3B
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
;		.BYTE	$1C		; ADATA	$1C
;		.BYTE	$3E		; ADATA	$3E
;		.BYTE	$1C		; ADATA	$1C
;		.BYTE	$3E		; ADATA	$3E
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$3C		; ADATA	$3C
;		.BYTE	$3C		; ADATA	$3C
;		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
;		.BYTE	$1F		; ADATA	$1F
;		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
;		.BYTE	$1E		; ADATA	$1E
;		.BYTE	$3B		; ADATA	$3B
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$1C		; ADATA	$1C
;		.BYTE	$1D		; ADATA	$1D
;		.BYTE	$3B		; ADATA	$3B
;		.BYTE	$FF		; ASTOP
;_musD_E:
;		.BYTE	$F2,$01		; ACMDF2      $01
;		.BYTE	$F0,$0A		; ACMDF0      $0A
;		.BYTE	$F4,$00		; ACMDF4      $00
;		.BYTE	$F6,$13		; ACMDF6      $13
;		.BYTE	$FC,$20		; ALOOP_START $20
;		.BYTE	$26		; ADATA	$26
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$F0,$0D		; ACMDF0      $0D
;		.BYTE	$F6,$1A		; ACMDF6      $1A
;		.BYTE	$FC,$08		; ALOOP_START $08
;		.BYTE	$0D		; ADATA	$0D
;		.BYTE	$8D		; ADATA	$8D
;		.BYTE	$F6,$20		; ACMDF6      $20
;		.BYTE	$24		; ADATA	$24
;		.BYTE	$F6,$14		; ACMDF6      $14
;		.BYTE	$08		; ADATA	$08
;		.BYTE	$45		; ADATA	$45
;		.BYTE	$F6,$1A		; ACMDF6      $1A
;		.BYTE	$0D		; ADATA	$0D
;		.BYTE	$8D		; ADATA	$8D
;		.BYTE	$F6,$20		; ACMDF6      $20
;		.BYTE	$44		; ADATA	$44
;		.BYTE	$07		; ADATA	$07
;		.BYTE	$28		; ADATA	$28
;		.BYTE	$FD		; ALOOP_END
;		.BYTE	$F6,$19		; ACMDF6      $19
;		.BYTE	$07		; ADATA	$07
;		.BYTE	$06		; ADATA	$06
;		.BYTE	$0D		; ADATA	$0D
;		.BYTE	$06		; ADATA	$06
;		.BYTE	$07		; ADATA	$07
;		.BYTE	$0D		; ADATA	$0D
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$06		; ADATA	$06
;		.BYTE	$F6,$20		; ACMDF6      $20
;		.BYTE	$24		; ADATA	$24
;		.BYTE	$05		; ADATA	$05
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$F4,$FF		; ACMDF4      $FF
;		.BYTE	$F6,$13		; ACMDF6      $13
;		.BYTE	$C7,$02		; ADATAEX     $C7,$02
;		.BYTE	$F6,$19		; ACMDF6      $19
;		.BYTE	$C6,$05		; ADATAEX     $C6,$05
;		.BYTE	$07		; ADATA	$07
;		.BYTE	$F1,$02		; ACMDF1      $02
;		.BYTE	$F6,$14		; ACMDF6      $14
;		.BYTE	$06		; ADATA	$06
;		.BYTE	$0F		; ADATA	$0F
;		.BYTE	$09		; ADATA	$09
;		.BYTE	$08		; ADATA	$08
;		.BYTE	$F6,$20		; ACMDF6      $20
;		.BYTE	$04		; ADATA	$04
;		.BYTE	$23		; ADATA	$23
;		.BYTE	$FF	; ASTOP
; -
_musC:
		.BYTE	$05
		.WORD	_musC_A
		.BYTE	$00
		.WORD	_musC_B
		.BYTE	$08
		.WORD	_musC_C
		.BYTE	$04
		.WORD	_musC_D
		.BYTE	$0C
		.WORD	_musC_E
		.BYTE	$0C
_musC_A:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$00		; ADATA	$00
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17		; ADATA	$17
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50749
		.WORD	_musC_A
_musC_B:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$05		; ADATA	$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$05		; ADATA	$05
		.BYTE	$00		; ADATA	$00
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17		; ADATA	$17
		.BYTE	$04		; ADATA	$04
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50768
		.WORD	_musC_B
_musC_C:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$16		; ADATA	$16
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$09		; ADATA	$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$09		; ADATA	$09
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50787
		.WORD	_musC_C
_musC_D:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$5C		; ADATA	$5C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$F8		; AJMP	_aloc_507A6
		.WORD	_musC_D
_musC_E:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$0D		; ADATA	$0D
_aloc_507CC:
		.BYTE	$8D		; ADATA	$8D
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$08		; ADATA	$08
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$CD,$1B		; ADATAEX     $CD,$1B
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C9,$08		; ADATAEX     $C9,$08
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$07		; ADATA	$07
		.BYTE	$48		; ADATA	$48
		.BYTE	$F8		; AJMP	_aloc_507CC
		.WORD	_aloc_507CC
_mus1:
		.BYTE	$05
		.WORD	_mus1_A
		.BYTE	$0C
		.WORD	_mus1_B
		.BYTE	$00
		.WORD	_mus1_C
		.BYTE	$08
		.WORD	_mus1_D
		.BYTE	$04
		.WORD	_mus1_E
		.BYTE	$0C
_mus1_A:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$70		; ADATA	$70
_aloc_507FA:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F8		; AJMP	_aloc_507FA
		.WORD	_aloc_507FA
_mus1_B:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$06		; ACMDF5      $06
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_50829:
		.BYTE	$00		; ADATA	$00
		.BYTE	$23		; ADATA	$23
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$27		; ADATA	$27
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$23		; ADATA	$23
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$23		; ADATA	$23
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$00		; ADATA	$00
		.BYTE	$23		; ADATA	$23
		.BYTE	$40		; ADATA	$40
		.BYTE	$26		; ADATA	$26
		.BYTE	$40		; ADATA	$40
		.BYTE	$27		; ADATA	$27
		.BYTE	$40		; ADATA	$40
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$40		; ADATA	$40
		.BYTE	$27		; ADATA	$27
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$23		; ADATA	$23
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$F8		; AJMP	_aloc_50829
		.WORD	_aloc_50829
_mus1_C:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$70		; ADATA	$70
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$EB		; ACMDF4      $EB
		.BYTE	$F5,$12		; ACMDF5      $12
		.BYTE	$F8		; AJMP	_aloc_50829
		.WORD	_aloc_50829
_mus1_D:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$81		; ADATA	$81
		.BYTE	$80		; ADATA	$80
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$81		; ADATA	$81
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_50858
		.WORD	_mus1_D
_mus1_E:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_50872:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$44		; ADATA	$44
		.BYTE	$FD		; ALOOP_END
		.BYTE	$24		; ADATA	$24
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50872
		.WORD	_aloc_50872
_mus2:
		.BYTE	$05
		.WORD	_mus2_A
		.BYTE	$0C
		.WORD	_mus2_B
		.BYTE	$0C
		.WORD	_mus2_C
		.BYTE	$00
		.WORD	_mus2_D
		.BYTE	$08
		.WORD	_mus2_E
		.BYTE	$04
_mus2_A:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FF		; ASTOP
_mus2_B:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$05		; ADATA	$05
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$23		; ADATA	$23
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$06		; ADATA	$06
		.BYTE	$47		; ADATA	$47
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$63		; ADATA	$63
		.BYTE	$FF		; ASTOP
_mus2_C:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$11		; ACMDF5      $11
_aloc_508FF:
		.BYTE	$FA		; AJSR	_asub_50909
		.WORD	_asub_50909
		.BYTE	$FA		; AJSR	_asub_50912
		.WORD	_asub_50912
		.BYTE	$FA		; AJSR	_asub_5091C
		.WORD	_asub_5091C
		.BYTE	$FF		; ASTOP
_asub_50909:
		.BYTE	$31		; ADATA	$31
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$20		; ADATA	$20
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_50912:
		.BYTE	$30		; ADATA	$30
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$39		; ADATA	$39
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$38		; ADATA	$38
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$30		; ADATA	$30
		.BYTE	$FB		; ARET
_asub_5091C:
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$D7,$3C		; ADATAEX     $D7,$3C
		.BYTE	$FB		; ARET
_mus2_D:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F8		; AJMP	_aloc_508FF
		.WORD	_aloc_508FF
		.BYTE	$FF		; ASTOP
_mus2_E:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$F5,$18		; ACMDF5      $18
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FA		; AJSR	_asub_50909
		.WORD	_asub_50909
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$30		; ADATA	$30
		.BYTE	$FA		; AJSR	_asub_50954
		.WORD	_asub_50954
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$D0,$0F		; ADATAEX     $D0,$0F
		.BYTE	$D7,$3C		; ADATAEX     $D7,$3C
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FF		; ASTOP
_asub_50954:
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$09		; ADATA	$09
		.BYTE	$05		; ADATA	$05
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$09		; ADATA	$09
		.BYTE	$04		; ADATA	$04
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$09		; ADATA	$09
		.BYTE	$FB		; ARET
_mus3:
		.BYTE	$05
		.WORD	_mus3_A
		.BYTE	$0C
		.WORD	_mus3_B
		.BYTE	$00
		.WORD	_mus3_C
		.BYTE	$04
		.WORD	_mus3_D
		.BYTE	$08
		.WORD	_mus3_E
		.BYTE	$0C
_mus3_A:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$CF,$0D		; ADATAEX     $CF,$0D
		.BYTE	$DE,$0F		; ADATAEX     $DE,$0F
		.BYTE	$DE,$0B		; ADATAEX     $DE,$0B
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$FF		; ASTOP
_mus3_B:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$30		; ADATA	$30
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$17		; ADATA	$17
		.BYTE	$38		; ADATA	$38
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C3,$02		; ADATAEX     $C3,$02
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$C4,$0A		; ADATAEX     $C4,$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$D0,$0D		; ADATAEX     $D0,$0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$DD,$0F		; ADATAEX     $DD,$0F
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$DC,$03		; ADATAEX     $DC,$03
		.BYTE	$DD,$00		; ADATAEX     $DD,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0F		; ACMDF3      $0F
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$04		; ACMDE3      $04
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_mus3_C:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$31		; ADATA	$31
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$36		; ADATA	$36
		.BYTE	$15		; ADATA	$15
		.BYTE	$38		; ADATA	$38
		.BYTE	$11		; ADATA	$11
		.BYTE	$33		; ADATA	$33
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$13		; ADATA	$13
		.BYTE	$D0,$0D		; ADATAEX     $D0,$0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$DA,$0F		; ADATAEX     $DA,$0F
		.BYTE	$DA,$0B		; ADATAEX     $DA,$0B
		.BYTE	$DA,$0B		; ADATAEX     $DA,$0B
		.BYTE	$D9,$03		; ADATAEX     $D9,$03
		.BYTE	$DA,$00		; ADATAEX     $DA,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0F		; ACMDF3      $0F
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$04		; ACMDE3      $04
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_mus3_D:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$29		; ADATA	$29
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$09		; ADATA	$09
		.BYTE	$29		; ADATA	$29
		.BYTE	$08		; ADATA	$08
		.BYTE	$47		; ADATA	$47
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$47		; ADATA	$47
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$27		; ADATA	$27
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$D0,$0D		; ADATAEX     $D0,$0D
		.BYTE	$C2,$0F		; ADATAEX     $C2,$0F
		.BYTE	$C2,$0B		; ADATAEX     $C2,$0B
		.BYTE	$C2,$0B		; ADATAEX     $C2,$0B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
_mus3_E:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$CF,$0D		; ADATAEX     $CF,$0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$C4,$0F		; ADATAEX     $C4,$0F
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$C7,$0B		; ADATAEX     $C7,$0B
		.BYTE	$C8,$0B		; ADATAEX     $C8,$0B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$FF		; ASTOP
_sample_copy_unused_start:
		.BYTE	$80	; ADATA	$80
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
		.BYTE	$81		; ADATA	$81
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
		.BYTE	$82		; ADATA	$82
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
		.BYTE	$83		; ADATA	$83
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
		.BYTE	$40		; ADATA	$40
		.BYTE	$FF		; ASTOP
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$41		; ADATA	$41
		.BYTE	$04		; ADATA	$04
		.BYTE	$40		; ADATA	$40
		.BYTE	$FF		; ASTOP
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$03		; ADATA	$03
		.BYTE	$FC,$0C		; ALOOP_START $0C
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_aloc_50A91:
		.BYTE	$57		; ADATA	$57
		.BYTE	$56		; ADATA	$56
		.BYTE	$45		; ADATA	$45
		.BYTE	$03		; ADATA	$03
		.BYTE	$44		; ADATA	$44
		.BYTE	$0F		; ADATA	$0F
_aloc_50A97:
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50A97
		.WORD	_aloc_50A97
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$81		; ADATA	$81
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$43		; ADATA	$43
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$20		; ADATA	$20
		.BYTE	$FF		; ASTOP
		.BYTE	$81		; ADATA	$81
		.BYTE	$58		; ADATA	$58
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$82		; ADATA	$82
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$82		; ADATA	$82
		.BYTE	$58		; ADATA	$58
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$80		; ADATA	$80
		.BYTE	$57		; ADATA	$57
		.BYTE	$82		; ADATA	$82
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50ACE
		.WORD	_aloc_50ACE
		.BYTE	$81		; ADATA	$81
		.BYTE	$57		; ADATA	$57
		.BYTE	$80		; ADATA	$80
		.BYTE	$04		; ADATA	$04
_aloc_50ACE:
		.BYTE	$40		; ADATA	$40
_aloc_50ACF:
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$62		; ADATA	$62
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50ACF
		.WORD	_aloc_50ACF
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$83		; ADATA	$83
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$83		; ADATA	$83
		.BYTE	$58		; ADATA	$58
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$44		; ADATA	$44
_aloc_50AE5:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50AE5
		.WORD	_aloc_50AE5
		.BYTE	$FA		; AJSR	_asub_50AF6
		.WORD	_asub_50AF6
		.BYTE	$F8		; AJMP	_aloc_50B00
		.WORD	_aloc_50B00
_asub_50AF6:
		.BYTE	$80		; ADATA	$80
		.BYTE	$43		; ADATA	$43
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$72		; ADATA	$72
		.BYTE	$FD		; ALOOP_END
		.BYTE	$91		; ADATA	$91
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$83		; ADATA	$83
		.BYTE	$FB		; ARET
_aloc_50B00:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$7F		; ADATA	$7F
_aloc_50B06:
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50B06
		.WORD	_aloc_50B06
		.BYTE	$49		; ADATA	$49
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$01		; ADATA	$01
		.BYTE	$6B		; ADATA	$6B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
		.BYTE	$49		; ADATA	$49
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
		.BYTE	$82		; ADATA	$82
		.BYTE	$58		; ADATA	$58
		.BYTE	$20		; ADATA	$20
		.BYTE	$83		; ADATA	$83
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$82		; ADATA	$82
		.BYTE	$F8		; AJMP	_aloc_50A91
		.WORD	_aloc_50A91
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$43		; ADATA	$43
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$22		; ADATA	$22
		.BYTE	$FF		; ASTOP
		.BYTE	$4B		; ADATA	$4B
		.BYTE	$92		; ADATA	$92
		.BYTE	$48		; ADATA	$48
		.BYTE	$83		; ADATA	$83
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
		.BYTE	$83		; ADATA	$83
		.BYTE	$46		; ADATA	$46
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$71		; ADATA	$71
		.BYTE	$80		; ADATA	$80
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
_aloc_50B52:
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$41		; ADATA	$41
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F8		; AJMP	_aloc_50B52
		.WORD	_aloc_50B52
		.BYTE	$81		; ADATA	$81
		.BYTE	$45		; ADATA	$45
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$72		; ADATA	$72
		.BYTE	$FD		; ALOOP_END
		.BYTE	$82		; ADATA	$82
_aloc_50B60:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$23		; ADATA	$23
		.BYTE	$02		; ADATA	$02
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50B60
		.WORD	_aloc_50B60
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$83		; ADATA	$83
		.BYTE	$02		; ADATA	$02
		.BYTE	$81		; ADATA	$81
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FD		; ALOOP_END
_aloc_50B77:
		.BYTE	$83		; ADATA	$83
		.BYTE	$02		; ADATA	$02
		.BYTE	$72		; ADATA	$72
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$F8		; AJMP	_aloc_50B77
		.WORD	_aloc_50B77
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
		.BYTE	$80		; ADATA	$80
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$02		; ADATA	$02
		.BYTE	$81		; ADATA	$81
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$82		; ADATA	$82
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$80		; ADATA	$80
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$02		; ADATA	$02
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$83		; ADATA	$83
		.BYTE	$02		; ADATA	$02
_aloc_50B97:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$03		; ADATA	$03
		.BYTE	$F8		; AJMP	_aloc_50B97
		.WORD	_aloc_50B97
		.BYTE	$57		; ADATA	$57
		.BYTE	$31		; ADATA	$31
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$6F		; ADATA	$6F
_aloc_50BAA:
		.BYTE	$21		; ADATA	$21
		.BYTE	$05		; ADATA	$05
		.BYTE	$F8		; AJMP	_aloc_50BAA
		.WORD	_aloc_50BAA
		.BYTE	$83		; ADATA	$83
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$81		; ADATA	$81
		.BYTE	$59		; ADATA	$59
		.BYTE	$80		; ADATA	$80
		.BYTE	$47		; ADATA	$47
		.BYTE	$03		; ADATA	$03
_aloc_50BB6:
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$03		; ADATA	$03
		.BYTE	$F8		; AJMP	_aloc_50BB6
		.WORD	_aloc_50BB6
_aloc_50BBD:
		.BYTE	$82		; ADATA	$82
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$80		; ADATA	$80
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FD		; ALOOP_END
_aloc_50BC7:
		.BYTE	$46		; ADATA	$46
		.BYTE	$03		; ADATA	$03
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$46		; ADATA	$46
		.BYTE	$03		; ADATA	$03
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50BC7
		.WORD	_aloc_50BC7
		.BYTE	$FF		; ASTOP
		.BYTE	$83		; ADATA	$83
		.BYTE	$22		; ADATA	$22
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$81		; ADATA	$81
		.BYTE	$59		; ADATA	$59
		.BYTE	$80		; ADATA	$80
		.BYTE	$47		; ADATA	$47
		.BYTE	$03		; ADATA	$03
_aloc_50BDB:
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$03		; ADATA	$03
		.BYTE	$F8		; AJMP	_aloc_50BDB
		.WORD	_aloc_50BDB
		.BYTE	$53		; ADATA	$53
		.BYTE	$55		; ADATA	$55
		.BYTE	$53		; ADATA	$53
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$40		; ADATA	$40
		.BYTE	$FF		; ASTOP
		.BYTE	$23		; ADATA	$23
		.BYTE	$F8		; AJMP	_aloc_50BBD
		.WORD	_aloc_50BBD
		.BYTE	$FF		; ASTOP
		.BYTE	$82		; ADATA	$82
		.BYTE	$59		; ADATA	$59
		.BYTE	$81		; ADATA	$81
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$83		; ADATA	$83
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$21		; ADATA	$21
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$5A		; ADATA	$5A
_aloc_50BF8:
		.BYTE	$49		; ADATA	$49
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50BF8
		.WORD	_aloc_50BF8
		.BYTE	$80		; ADATA	$80
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$81		; ADATA	$81
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$82		; ADATA	$82
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
_aloc_50C0A:
		.BYTE	$55		; ADATA	$55
		.BYTE	$F8		; AJMP	_aloc_50C0A
		.WORD	_aloc_50C0A
_aloc_50C0E:
		.BYTE	$42		; ADATA	$42
		.BYTE	$03		; ADATA	$03
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50C0E
		.WORD	_aloc_50C0E
		.BYTE	$FF		; ASTOP
		.BYTE	$83		; ADATA	$83
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$02		; ADATA	$02
		.BYTE	$82		; ADATA	$82
		.BYTE	$4B		; ADATA	$4B
		.BYTE	$04		; ADATA	$04
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$04		; ADATA	$04
		.BYTE	$49		; ADATA	$49
		.BYTE	$06		; ADATA	$06
_aloc_50C20:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50C20
		.WORD	_aloc_50C20
		.BYTE	$82		; ADATA	$82
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$83		; ADATA	$83
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$81		; ADATA	$81
_aloc_50C33:
		.BYTE	$31		; ADATA	$31
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$31		; ADATA	$31
		.BYTE	$F8		; AJMP	_aloc_50C33
		.WORD	_aloc_50C33
		.BYTE	$80		; ADATA	$80
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$81		; ADATA	$81
		.BYTE	$47		; ADATA	$47
		.BYTE	$02		; ADATA	$02
		.BYTE	$80		; ADATA	$80
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
		.BYTE	$83		; ADATA	$83
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$80		; ADATA	$80
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$02		; ADATA	$02
		.BYTE	$82		; ADATA	$82
		.BYTE	$49		; ADATA	$49
_aloc_50C4E:
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50C4E
		.WORD	_aloc_50C4E
		.BYTE	$FF		; ASTOP
		.BYTE	$83		; ADATA	$83
		.BYTE	$47		; ADATA	$47
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$61		; ADATA	$61
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
_aloc_50C61:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_50C61
		.WORD	_aloc_50C61
		.BYTE	$FF		; ASTOP
		.BYTE	$FC,$0D		; ALOOP_START $0D
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$71		; ADATA	$71
		.BYTE	$71		; ADATA	$71
		.BYTE	$62		; ADATA	$62
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
		.BYTE	$82		; ADATA	$82
		.BYTE	$4E		; ADATA	$4E
		.BYTE	$03		; ADATA	$03
		.BYTE	$4B		; ADATA	$4B
		.BYTE	$FC,$0B		; ALOOP_START $0B
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$58		; ADATA	$58
		.BYTE	$5C		; ADATA	$5C
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
_sample_copy_unused_end:
		.BYTE	$FF	; ASTOP
_mus4:
		.BYTE	$05
		.WORD	_mus4_A
		.BYTE	$04
		.WORD	_mus4_B
		.BYTE	$00
		.WORD	_mus4_C
		.BYTE	$08
		.WORD	_mus4_D
		.BYTE	$0C
		.WORD	_mus4_E
		.BYTE	$0C
_mus4_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
_aloc_50CA2:
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_50CCB
		.WORD	_asub_50CCB
		.BYTE	$FA		; AJSR	_asub_50CD4
		.WORD	_asub_50CD4
		.BYTE	$FA		; AJSR	_asub_50CCB
		.WORD	_asub_50CCB
		.BYTE	$FA		; AJSR	_asub_50CD9
		.WORD	_asub_50CD9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$FA		; AJSR	_asub_50CCB
		.WORD	_asub_50CCB
		.BYTE	$FA		; AJSR	_asub_50CD4
		.WORD	_asub_50CD4
		.BYTE	$FA		; AJSR	_asub_50CCB
		.WORD	_asub_50CCB
		.BYTE	$FA		; AJSR	_asub_50CD9
		.WORD	_asub_50CD9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50CA2
		.WORD	_aloc_50CA2
_asub_50CCB:
		.BYTE	$34		; ADATA	$34
		.BYTE	$19		; ADATA	$19
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$30		; ADATA	$30
		.BYTE	$19		; ADATA	$19
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_50CD4:
		.BYTE	$20		; ADATA	$20
		.BYTE	$19		; ADATA	$19
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_50CD9:
		.BYTE	$22		; ADATA	$22
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$20		; ADATA	$20
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_mus4_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_50D0B
		.WORD	_asub_50D0B
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_50D40
		.WORD	_asub_50D40
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_50D4B
		.WORD	_asub_50D4B
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FA		; AJSR	_asub_50D0B
		.WORD	_asub_50D0B
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_50D40
		.WORD	_asub_50D40
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FA		; AJSR	_asub_50D4B
		.WORD	_asub_50D4B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_50D61
		.WORD	_asub_50D61
		.BYTE	$F8		; AJMP	_aloc_50CDE
		.WORD	_mus4_B
_asub_50D0B:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$29		; ADATA	$29
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$F6,$0B		; ACMDF6      $0B
		.BYTE	$00		; ADATA	$00
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$19		; ADATA	$19
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$29		; ADATA	$29
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_50D40:
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$CA,$03		; ADATAEX     $CA,$03
		.BYTE	$CB,$04		; ADATAEX     $CB,$04
		.BYTE	$CC,$08		; ADATAEX     $CC,$08
		.BYTE	$FB		; ARET
_asub_50D4B:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$29		; ADATA	$29
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$FB		; ARET
_asub_50D61:
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C0,$5A		; ADATAEX     $C0,$5A
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$DE,$3C		; ADATAEX     $DE,$3C
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$60		; ADATA	$60
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DB,$5A		; ADATAEX     $DB,$5A
		.BYTE	$C0,$3C		; ADATAEX     $C0,$3C
		.BYTE	$F1,$00		; ACMDF1      $00
		.BYTE	$63		; ADATA	$63
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$24		; ADATA	$24
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C5,$3C		; ADATAEX     $C5,$3C
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C1,$3C		; ADATAEX     $C1,$3C
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$A8		; ADATA	$A8
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$CB,$46		; ADATAEX     $CB,$46
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$29		; ADATA	$29
		.BYTE	$C8,$3C		; ADATAEX     $C8,$3C
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$C7,$5A		; ADATAEX     $C7,$5A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$C0,$3C		; ADATAEX     $C0,$3C
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$84		; ADATA	$84
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$DB,$5A		; ADATAEX     $DB,$5A
		.BYTE	$C0,$3C		; ADATAEX     $C0,$3C
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C8,$3C		; ADATAEX     $C8,$3C
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$A1		; ADATA	$A1
		.BYTE	$DC,$2D		; ADATAEX     $DC,$2D
		.BYTE	$A1		; ADATA	$A1
		.BYTE	$48		; ADATA	$48
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$CA,$04		; ADATAEX     $CA,$04
		.BYTE	$CB,$42		; ADATAEX     $CB,$42
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$29		; ADATA	$29
		.BYTE	$A8		; ADATA	$A8
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$AD		; ADATA	$AD
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_mus4_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$FA		; AJSR	_asub_50DEC
		.WORD	_asub_50DEC
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$FA		; AJSR	_asub_50DEC
		.WORD	_asub_50DEC
		.BYTE	$F8		; AJMP	_aloc_50DD9
		.WORD	_mus4_C
_asub_50DEC:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$39		; ADATA	$39
		.BYTE	$18		; ADATA	$18
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$19		; ADATA	$19
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$39		; ADATA	$39
		.BYTE	$19		; ADATA	$19
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$50		; ADATA	$50
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$38		; ADATA	$38
		.BYTE	$19		; ADATA	$19
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$19		; ADATA	$19
		.BYTE	$F4,$B4		; ACMDF4      $B4
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$12		; ADATA	$12
		.BYTE	$39		; ADATA	$39
		.BYTE	$12		; ADATA	$12
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$12		; ADATA	$12
		.BYTE	$39		; ADATA	$39
		.BYTE	$12		; ADATA	$12
		.BYTE	$FB		; ARET
_mus4_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_50E39
		.WORD	_asub_50E39
		.BYTE	$FA		; AJSR	_asub_50E52
		.WORD	_asub_50E52
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50E39
		.WORD	_asub_50E39
		.BYTE	$FA		; AJSR	_asub_50E5E
		.WORD	_asub_50E5E
		.BYTE	$F8		; AJMP	_aloc_50E21
		.WORD	_mus4_E
_asub_50E39:
		.BYTE	$F6,$2D		; ACMDF6      $2D
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$23		; ADATA	$23
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$26		; ADATA	$26
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_50E52:
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$C3,$09		; ADATAEX     $C3,$09
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$FB		; ARET
_asub_50E5E:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C4,$09		; ADATAEX     $C4,$09
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$C4,$09		; ADATAEX     $C4,$09
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$FB		; ARET
_mus4_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_50E79
		.WORD	_asub_50E79
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50E8F
		.WORD	_asub_50E8F
		.BYTE	$F8		; AJMP	_aloc_50E6B
		.WORD	_mus4_D
_asub_50E79:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$DD,$13		; ADATAEX     $DD,$13
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$0B		; ADATAEX     $DE,$0B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_50E8F:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$09		; ADATAEX     $DE,$09
		.BYTE	$DE,$06		; ADATAEX     $DE,$06
		.BYTE	$DE,$09		; ADATAEX     $DE,$09
		.BYTE	$DE,$06		; ADATAEX     $DE,$06
		.BYTE	$FB		; ARET
_mus5:
		.BYTE	$05
		.WORD	_mus5_A
		.BYTE	$0C
		.WORD	_mus5_B
		.BYTE	$08
		.WORD	_mus5_C
		.BYTE	$0C
		.WORD	_mus5_D
		.BYTE	$00
		.WORD	_mus5_E
		.BYTE	$04
_mus5_A:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$FA		; AJSR	_asub_50F76
		.WORD	_asub_50F76
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F04
		.WORD	_asub_50F04
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F5F
		.WORD	_asub_50F5F
_aloc_50ECA:
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F04
		.WORD	_asub_50F04
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F16
		.WORD	_asub_50F16
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F04
		.WORD	_asub_50F04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F16
		.WORD	_asub_50F16
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_50F2B
		.WORD	_asub_50F2B
		.BYTE	$FA		; AJSR	_asub_50F41
		.WORD	_asub_50F41
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50ECA
		.WORD	_aloc_50ECA
		.BYTE	$FF		; ASTOP
_asub_50EF2:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_50F04:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_50F16:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_50F2B:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_50F41:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$FB		; ARET
_asub_50F5F:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DF,$02		; ADATAEX     $DF,$02
		.BYTE	$DF,$05		; ADATAEX     $DF,$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_50F76:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_mus5_B:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$D0,$70		; ADATAEX     $D0,$70
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_50FB0
		.WORD	_asub_50FB0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50FBF
		.WORD	_asub_50FBF
_aloc_50F98:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_50FB0
		.WORD	_asub_50FB0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50FBF
		.WORD	_asub_50FBF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_50FCF
		.WORD	_asub_50FCF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50F98
		.WORD	_aloc_50F98
		.BYTE	$FF		; ASTOP
_asub_50FB0:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$79		; ADATA	$79
		.BYTE	$FB		; ARET
_asub_50FBF:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$39		; ADATA	$39
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_50FCF:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$60		; ADATA	$60
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$B2		; ADATA	$B2
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$71		; ADATA	$71
		.BYTE	$7C		; ADATA	$7C
		.BYTE	$63		; ADATA	$63
		.BYTE	$7C		; ADATA	$7C
		.BYTE	$65		; ADATA	$65
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_mus5_C:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_51085
		.WORD	_asub_51085
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51012
		.WORD	_asub_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51066
		.WORD	_asub_51066
_aloc_50FF0:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51012
		.WORD	_asub_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51025
		.WORD	_asub_51025
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51012
		.WORD	_asub_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51025
		.WORD	_asub_51025
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51039
		.WORD	_asub_51039
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51052
		.WORD	_asub_51052
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50FF0
		.WORD	_aloc_50FF0
		.BYTE	$FF		; ASTOP
_asub_51012:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$FB		; ARET
_asub_51025:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$26		; ADATA	$26
		.BYTE	$FB		; ARET
_asub_51039:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$FB		; ARET
_asub_51052:
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_51066:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C6,$05		; ADATAEX     $C6,$05
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FB		; ARET
_asub_51085:
		.BYTE	$F6,$2D		; ACMDF6      $2D
		.BYTE	$F4,$78		; ACMDF4      $78
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$06		; ACMDF1      $06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$06		; ADATA	$06
		.BYTE	$06		; ADATA	$06
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_mus5_D:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$CD,$54		; ADATAEX     $CD,$54
		.BYTE	$CD,$00		; ADATAEX     $CD,$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$07		; ACMDF3      $07
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_510FF
		.WORD	_asub_510FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_5110E
		.WORD	_asub_5110E
_aloc_510C5:
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_5120C
		.WORD	_asub_5120C
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_511F3
		.WORD	_asub_511F3
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FA		; AJSR	_asub_5111F
		.WORD	_asub_5111F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_5120C
		.WORD	_asub_5120C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FA		; AJSR	_asub_5111F
		.WORD	_asub_5111F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_511F3
		.WORD	_asub_511F3
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FA		; AJSR	_asub_5114E
		.WORD	_asub_5114E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_510C5
		.WORD	_aloc_510C5
		.BYTE	$FF		; ASTOP
_asub_510FF:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$79		; ADATA	$79
		.BYTE	$FB		; ARET
_asub_5110E:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$39		; ADATA	$39
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_5111F:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$06		; ADATAEX     $C3,$06
		.BYTE	$10		; ADATA	$10
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$11		; ADATAEX     $C3,$11
		.BYTE	$D0,$34		; ADATAEX     $D0,$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$CB,$01		; ADATAEX     $CB,$01
		.BYTE	$C0,$00		; ADATAEX     $C0,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0D		; ACMDF3      $0D
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$3E		; ADATAEX     $D0,$3E
		.BYTE	$FB		; ARET
_asub_5114E:
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$14		; ADATAEX     $C3,$14
		.BYTE	$F4,$6F		; ACMDF4      $6F
		.BYTE	$40		; ADATA	$40
		.BYTE	$FD		; ALOOP_END
		.BYTE	$23		; ADATA	$23
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_mus5_E:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$C1,$54		; ADATAEX     $C1,$54
		.BYTE	$C1,$00		; ADATAEX     $C1,$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$07		; ACMDF3      $07
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$FA		; AJSR	_asub_511B3
		.WORD	_asub_511B3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_511C4
		.WORD	_asub_511C4
_aloc_51186:
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$FA		; AJSR	_asub_511B3
		.WORD	_asub_511B3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_511C4
		.WORD	_asub_511C4
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_51225
		.WORD	_asub_51225
		.BYTE	$FA		; AJSR	_asub_51225
		.WORD	_asub_51225
		.BYTE	$FA		; AJSR	_asub_51233
		.WORD	_asub_51233
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51251
		.WORD	_asub_51251
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_51186
		.WORD	_aloc_51186
		.BYTE	$FF		; ASTOP
_asub_511B3:
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$65		; ADATA	$65
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_511C4:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_511D5:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$30		; ADATA	$30
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$24		; ADATA	$24
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$22		; ADATA	$22
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$90		; ADATA	$90
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FB		; ARET
_asub_511F3:
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$09		; ACMDF1      $09
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$C1,$01		; ADATAEX     $C1,$01
		.BYTE	$C2,$06		; ADATAEX     $C2,$06
		.BYTE	$F1,$F9		; ACMDF1      $F9
		.BYTE	$10		; ADATA	$10
		.BYTE	$F1,$07		; ACMDF1      $07
		.BYTE	$60		; ADATA	$60
		.BYTE	$FB		; ARET
_asub_5120C:
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$90		; ADATA	$90
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FB		; ARET
_unref_10:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$09		; ACMDF6      $09
_asub_51225:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$14		; ADATA	$14
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$03		; ADATA	$03
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$03		; ADATA	$03
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_51233:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$17		; ADATA	$17
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$07		; ADATA	$07
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$08		; ADATA	$08
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$05		; ADATA	$05
		.BYTE	$02		; ADATA	$02
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FB		; ARET
_asub_51251:
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$14		; ADATAEX     $C7,$14
		.BYTE	$F4,$6F		; ACMDF4      $6F
		.BYTE	$43		; ADATA	$43
		.BYTE	$FD		; ALOOP_END
		.BYTE	$27		; ADATA	$27
		.BYTE	$23		; ADATA	$23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$23		; ADATA	$23
		.BYTE	$FB		; ARET
_mus0:
		.BYTE	$05
		.WORD	_mus0_A
		.BYTE	$0C
		.WORD	_mus0_B
		.BYTE	$0C
		.WORD	_mus0_C
		.BYTE	$08
		.WORD	_mus0_D
		.BYTE	$00
		.WORD	_mus0_E
		.BYTE	$04
_mus0_A:
		.BYTE	$F2,$05		; ACMDF2      $05
_aloc_5127B:
		.BYTE	$FA		; AJSR	_asub_512A6
		.WORD	_asub_512A6
		.BYTE	$FA		; AJSR	_asub_512B1
		.WORD	_asub_512B1
		.BYTE	$FA		; AJSR	_asub_512A6
		.WORD	_asub_512A6
		.BYTE	$FA		; AJSR	_asub_512B1
		.WORD	_asub_512B1
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_512A6
		.WORD	_asub_512A6
		.BYTE	$FA		; AJSR	_asub_512B1
		.WORD	_asub_512B1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_512A6
		.WORD	_asub_512A6
		.BYTE	$FA		; AJSR	_asub_512BE
		.WORD	_asub_512BE
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_512CD
		.WORD	_asub_512CD
		.BYTE	$FA		; AJSR	_asub_512D9
		.WORD	_asub_512D9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_512EC
		.WORD	_asub_512EC
		.BYTE	$F8		; AJMP	_aloc_5127B
		.WORD	_aloc_5127B
		.BYTE	$FF		; ASTOP
_asub_512A6:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$8F		; ADATA	$8F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$FB		; ARET
_asub_512B1:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$FB		; ARET
_asub_512BE:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$8F		; ADATA	$8F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$FB		; ARET
_asub_512CD:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$8F		; ADATA	$8F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_512D9:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_512EC:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$CF,$10		; ADATAEX     $CF,$10
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$DE,$06		; ADATAEX     $DE,$06
		.BYTE	$FB		; ARET
_mus0_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0B		; ACMDF0      $0B
_aloc_51304:
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$FA		; AJSR	_asub_5131C
		.WORD	_asub_5131C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_5135B
		.WORD	_asub_5135B
		.BYTE	$FA		; AJSR	_asub_51382
		.WORD	_asub_51382
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_513A5
		.WORD	_asub_513A5
		.BYTE	$F8		; AJMP	_aloc_51304
		.WORD	_aloc_51304
		.BYTE	$FF		; ASTOP
_asub_5131C:
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$03		; ADATA	$03
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$94		; ACMDF6      $94
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$44		; ADATA	$44
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$08		; ADATA	$08
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$07		; ADATA	$07
		.BYTE	$FB		; ARET
_asub_5135B:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_51382:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$23		; ADATA	$23
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_513A5:
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$06		; ADATA	$06
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F1,$05		; ACMDF1      $05
		.BYTE	$C4,$10		; ADATAEX     $C4,$10
		.BYTE	$F1,$FB		; ACMDF1      $FB
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$FB		; ARET
_mus0_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_513FF
		.WORD	_asub_513FF
		.BYTE	$FA		; AJSR	_asub_5140E
		.WORD	_asub_5140E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$20		; ACMDF5      $20
		.BYTE	$FA		; AJSR	_asub_513FF
		.WORD	_asub_513FF
		.BYTE	$F5,$22		; ACMDF5      $22
		.BYTE	$FA		; AJSR	_asub_5140E
		.WORD	_asub_5140E
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_513FF
		.WORD	_asub_513FF
		.BYTE	$FA		; AJSR	_asub_5140E
		.WORD	_asub_5140E
		.BYTE	$F5,$20		; ACMDF5      $20
		.BYTE	$FA		; AJSR	_asub_513FF
		.WORD	_asub_513FF
		.BYTE	$FA		; AJSR	_asub_5140E
		.WORD	_asub_5140E
		.BYTE	$F5,$22		; ACMDF5      $22
		.BYTE	$FA		; AJSR	_asub_5140E
		.WORD	_asub_5140E
		.BYTE	$FA		; AJSR	_asub_51424
		.WORD	_asub_51424
		.BYTE	$F8		; AJMP	_aloc_513C6
		.WORD	_mus0_C
		.BYTE	$FF		; ASTOP
_asub_513FF:
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$92		; ADATA	$92
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$14		; ADATA	$14
		.BYTE	$37		; ADATA	$37
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_5140E:
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$92		; ADATA	$92
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$03		; ADATAEX     $DE,$03
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$20		; ADATA	$20
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$39		; ADATA	$39
		.BYTE	$17		; ADATA	$17
		.BYTE	$FB		; ARET
_asub_51424:
		.BYTE	$F4,$96		; ACMDF4      $96
		.BYTE	$54		; ADATA	$54
		.BYTE	$54		; ADATA	$54
		.BYTE	$54		; ADATA	$54
		.BYTE	$54		; ADATA	$54
		.BYTE	$D4,$10		; ADATAEX     $D4,$10
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$D4,$1F		; ADATAEX     $D4,$1F
		.BYTE	$FB		; ARET
_mus0_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$DF,$02		; ADATAEX     $DF,$02
		.BYTE	$C0,$0B		; ADATAEX     $C0,$0B
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$10		; ADATA	$10
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$10		; ADATA	$10
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$09		; ADATA	$09
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$D2,$02		; ADATAEX     $D2,$02
		.BYTE	$D3,$02		; ADATAEX     $D3,$02
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$D4,$10		; ADATAEX     $D4,$10
		.BYTE	$D0,$00		; ADATAEX     $D0,$00
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$30		; ADATA	$30
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$10		; ADATA	$10
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$10		; ADATA	$10
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$30		; ADATA	$30
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$0E		; ACMDF6      $0E
		.BYTE	$19		; ADATA	$19
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$19		; ADATA	$19
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$0F		; ADATAEX     $DB,$0F
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$30		; ADATA	$30
		.BYTE	$DF,$00		; ADATAEX     $DF,$00
		.BYTE	$E3,$FA		; ACMDE3      $FA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$A0		; ADATA	$A0
		.BYTE	$A3		; ADATA	$A3
		.BYTE	$8A		; ADATA	$8A
		.BYTE	$67		; ADATA	$67
		.BYTE	$25		; ADATA	$25
		.BYTE	$10		; ADATA	$10
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$27		; ADATA	$27
		.BYTE	$25		; ADATA	$25
		.BYTE	$10		; ADATA	$10
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30		; ADATA	$30
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$63		; ADATA	$63
		.BYTE	$D0,$3C		; ADATAEX     $D0,$3C
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F6,$0C		; ACMDF6      $0C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$10		; ADATA	$10
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$D0,$73		; ADATAEX     $D0,$73
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$17		; ADATAEX     $DE,$17
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$50		; ADATA	$50
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$17		; ADATAEX     $DE,$17
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$32		; ADATA	$32
		.BYTE	$14		; ADATA	$14
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$20		; ADATA	$20
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$12		; ADATA	$12
		.BYTE	$34		; ADATA	$34
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$14		; ADATA	$14
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$09		; ADATA	$09
		.BYTE	$34		; ADATA	$34
		.BYTE	$09		; ADATA	$09
		.BYTE	$28		; ADATA	$28
		.BYTE	$14		; ADATA	$14
		.BYTE	$28		; ADATA	$28
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$C5,$02		; ADATAEX     $C5,$02
		.BYTE	$C6,$08		; ADATAEX     $C6,$08
		.BYTE	$03		; ADATA	$03
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$60		; ADATA	$60
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$50		; ADATA	$50
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$AA		; ADATA	$AA
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$A5		; ADATA	$A5
		.BYTE	$AC		; ADATA	$AC
		.BYTE	$AF		; ADATA	$AF
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$AA		; ADATA	$AA
		.BYTE	$A5		; ADATA	$A5
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$17		; ADATAEX     $C3,$17
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$17		; ADATAEX     $C3,$17
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$17		; ADATAEX     $C3,$17
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$17		; ADATAEX     $C3,$17
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$20		; ADATA	$20
		.BYTE	$67		; ADATA	$67
		.BYTE	$25		; ADATA	$25
		.BYTE	$10		; ADATA	$10
		.BYTE	$23		; ADATA	$23
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$40		; ADATA	$40
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$D0,$41		; ADATAEX     $D0,$41
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$10		; ADATA	$10
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$D0,$3C		; ADATAEX     $D0,$3C
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$C9,$02		; ADATAEX     $C9,$02
		.BYTE	$CA,$17		; ADATAEX     $CA,$17
		.BYTE	$07		; ADATA	$07
		.BYTE	$30		; ADATA	$30
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$47		; ADATA	$47
		.BYTE	$25		; ADATA	$25
		.BYTE	$06		; ADATA	$06
		.BYTE	$27		; ADATA	$27
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$30		; ADATA	$30
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$49		; ADATA	$49
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$29		; ADATA	$29
		.BYTE	$06		; ADATA	$06
		.BYTE	$2C		; ADATA	$2C
		.BYTE	$05		; ADATA	$05
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$06		; ACMDF6      $06
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$08		; ADATAEX     $D9,$08
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3A		; ADATA	$3A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$19		; ADATA	$19
		.BYTE	$37		; ADATA	$37
		.BYTE	$12		; ADATA	$12
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$DF,$1C		; ADATAEX     $DF,$1C
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$A3		; ADATA	$A3
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$B9		; ADATA	$B9
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$04		; ADATAEX     $C7,$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$91		; ACMDF6      $91
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$C7,$04		; ADATAEX     $C7,$04
		.BYTE	$C7,$00		; ADATAEX     $C7,$00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$D2,$1F		; ADATAEX     $D2,$1F
		.BYTE	$F8		; AJMP	_aloc_51436
		.WORD	_mus0_D
		.BYTE	$FF		; ASTOP
_mus0_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$DF,$02		; ADATAEX     $DF,$02
		.BYTE	$C0,$0B		; ADATAEX     $C0,$0B
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$27		; ADATA	$27
		.BYTE	$07		; ADATA	$07
		.BYTE	$30		; ADATA	$30
		.BYTE	$07		; ADATA	$07
		.BYTE	$27		; ADATA	$27
		.BYTE	$10		; ADATA	$10
		.BYTE	$27		; ADATA	$27
		.BYTE	$10		; ADATA	$10
		.BYTE	$27		; ADATA	$27
		.BYTE	$07		; ADATA	$07
		.BYTE	$30		; ADATA	$30
		.BYTE	$07		; ADATA	$07
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$D2,$02		; ADATAEX     $D2,$02
		.BYTE	$D3,$02		; ADATAEX     $D3,$02
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$D4,$10		; ADATAEX     $D4,$10
		.BYTE	$D0,$00		; ADATAEX     $D0,$00
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$27		; ADATA	$27
		.BYTE	$07		; ADATA	$07
		.BYTE	$30		; ADATA	$30
		.BYTE	$07		; ADATA	$07
		.BYTE	$27		; ADATA	$27
		.BYTE	$10		; ADATA	$10
		.BYTE	$27		; ADATA	$27
		.BYTE	$10		; ADATA	$10
		.BYTE	$27		; ADATA	$27
		.BYTE	$07		; ADATA	$07
		.BYTE	$30		; ADATA	$30
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$FC,$09		; ALOOP_START $09
		.BYTE	$30		; ADATA	$30
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$14		; ADATA	$14
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$14		; ADATA	$14
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30		; ADATA	$30
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$07		; ACMDF6      $07
		.BYTE	$32		; ADATA	$32
		.BYTE	$14		; ADATA	$14
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$14		; ADATA	$14
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$D2,$00		; ADATAEX     $D2,$00
		.BYTE	$E3,$03		; ACMDE3      $03
		.BYTE	$F3,$05		; ACMDF3      $05
		.BYTE	$D4,$00		; ADATAEX     $D4,$00
		.BYTE	$E3,$03		; ACMDE3      $03
		.BYTE	$F3,$0A		; ACMDF3      $0A
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$30		; ADATA	$30
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$14		; ADATA	$14
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$09		; ADATA	$09
		.BYTE	$34		; ADATA	$34
		.BYTE	$09		; ADATA	$09
		.BYTE	$28		; ADATA	$28
		.BYTE	$14		; ADATA	$14
		.BYTE	$08		; ADATA	$08
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F6,$0E		; ACMDF6      $0E
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$C5,$02		; ADATAEX     $C5,$02
		.BYTE	$C6,$08		; ADATAEX     $C6,$08
		.BYTE	$03		; ADATA	$03
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$96		; ACMDF4      $96
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$03		; ADATA	$03
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$03		; ADATA	$03
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$17		; ADATAEX     $C9,$17
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$17		; ADATAEX     $C9,$17
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$23		; ADATA	$23
		.BYTE	$04		; ADATA	$04
		.BYTE	$25		; ADATA	$25
		.BYTE	$10		; ADATA	$10
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$17		; ADATAEX     $C9,$17
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$17		; ADATAEX     $C9,$17
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$23		; ADATA	$23
		.BYTE	$04		; ADATA	$04
		.BYTE	$25		; ADATA	$25
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$10		; ADATA	$10
		.BYTE	$37		; ADATA	$37
		.BYTE	$12		; ADATA	$12
		.BYTE	$33		; ADATA	$33
		.BYTE	$54		; ADATA	$54
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$14		; ADATA	$14
		.BYTE	$37		; ADATA	$37
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$34		; ADATA	$34
		.BYTE	$10		; ADATA	$10
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$25		; ADATA	$25
		.BYTE	$10		; ADATA	$10
		.BYTE	$25		; ADATA	$25
		.BYTE	$67		; ADATA	$67
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$30		; ADATA	$30
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$20		; ADATA	$20
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$39		; ADATA	$39
		.BYTE	$17		; ADATA	$17
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$39		; ADATA	$39
		.BYTE	$03		; ADATA	$03
		.BYTE	$23		; ADATA	$23
		.BYTE	$19		; ADATA	$19
		.BYTE	$23		; ADATA	$23
		.BYTE	$19		; ADATA	$19
		.BYTE	$22		; ADATA	$22
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$10		; ADATA	$10
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$10		; ADATA	$10
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$10		; ADATA	$10
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$05		; ADATA	$05
		.BYTE	$10		; ADATA	$10
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$39		; ADATA	$39
		.BYTE	$03		; ADATA	$03
		.BYTE	$23		; ADATA	$23
		.BYTE	$19		; ADATA	$19
		.BYTE	$22		; ADATA	$22
		.BYTE	$03		; ADATA	$03
		.BYTE	$22		; ADATA	$22
		.BYTE	$03		; ADATA	$03
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F4,$96		; ACMDF4      $96
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$05		; ADATA	$05
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$19		; ADATA	$19
		.BYTE	$02		; ADATA	$02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$04		; ADATAEX     $C7,$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$91		; ACMDF6      $91
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$C7,$04		; ADATAEX     $C7,$04
		.BYTE	$C7,$00		; ADATAEX     $C7,$00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$D9,$1F		; ADATAEX     $D9,$1F
		.BYTE	$F8		; AJMP	_aloc_515DA
		.WORD	_mus0_E
		.BYTE	$FF		; ASTOP
_mus6:
		.BYTE	$05
		.WORD	_mus6_A
		.BYTE	$0C
		.WORD	_mus6_B
		.BYTE	$0C
		.WORD	_mus6_C
		.BYTE	$04
		.WORD	_mus6_D
		.BYTE	$00
		.WORD	_mus6_E
		.BYTE	$08
_mus6_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517BC
		.WORD	_asub_517BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517CE
		.WORD	_asub_517CE
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517BC
		.WORD	_asub_517BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517CE
		.WORD	_asub_517CE
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517E1
		.WORD	_asub_517E1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517CE
		.WORD	_asub_517CE
		.BYTE	$F8		; AJMP	_aloc_51777
		.WORD	_mus6_A
		.BYTE	$FF		; ASTOP
_asub_517AA:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_517BC:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_517CE:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_517E1:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_mus6_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_5181C
		.WORD	_asub_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51831
		.WORD	_asub_51831
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$1F		; ALOOP_START $1F
		.BYTE	$FA		; AJSR	_asub_5181C
		.WORD	_asub_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51831
		.WORD	_asub_51831
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_5181C
		.WORD	_asub_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51831
		.WORD	_asub_51831
		.BYTE	$F8		; AJMP	_aloc_517F5
		.WORD	_mus6_B
		.BYTE	$FF		; ASTOP
_asub_5181C:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FB		; ARET
_asub_51831:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$23		; ADATA	$23
		.BYTE	$23		; ADATA	$23
		.BYTE	$23		; ADATA	$23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FB		; ARET
_mus6_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51884
		.WORD	_asub_51884
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_51889
		.WORD	_asub_51889
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_5188C
		.WORD	_asub_5188C
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_5188F
		.WORD	_asub_5188F
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51892
		.WORD	_asub_51892
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_51884
		.WORD	_asub_51884
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_51892
		.WORD	_asub_51892
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_518B8
		.WORD	_asub_518B8
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_518C8
		.WORD	_asub_518C8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_51842
		.WORD	_mus6_C
		.BYTE	$FF		; ASTOP
_asub_51884:
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$FB		; ARET
_asub_51889:
		.BYTE	$35		; ADATA	$35
		.BYTE	$21		; ADATA	$21
		.BYTE	$FB		; ARET
_asub_5188C:
		.BYTE	$34		; ADATA	$34
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_5188F:
		.BYTE	$33		; ADATA	$33
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FB		; ARET
_asub_51892:
		.BYTE	$32		; ADATA	$32
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_51895:
		.BYTE	$F4,$DC		; ACMDF4      $DC
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$36		; ADATA	$36
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$39		; ADATA	$39
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_518B8:
		.BYTE	$31		; ADATA	$31
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$31		; ADATA	$31
		.BYTE	$30		; ADATA	$30
		.BYTE	$31		; ADATA	$31
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$31		; ADATA	$31
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$31		; ADATA	$31
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_518C8:
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$36		; ADATA	$36
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$39		; ADATA	$39
		.BYTE	$22		; ADATA	$22
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$39		; ADATA	$39
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F4,$A0		; ACMDF4      $A0
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_mus6_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$FA		; AJSR	_asub_5190C
		.WORD	_asub_5190C
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_5195B
		.WORD	_asub_5195B
		.BYTE	$FA		; AJSR	_asub_519B1
		.WORD	_asub_519B1
		.BYTE	$FA		; AJSR	_asub_519C7
		.WORD	_asub_519C7
		.BYTE	$FA		; AJSR	_asub_519B1
		.WORD	_asub_519B1
		.BYTE	$FA		; AJSR	_asub_519E2
		.WORD	_asub_519E2
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_519FE
		.WORD	_asub_519FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_518E4
		.WORD	_mus6_D
		.BYTE	$FF		; ASTOP
_asub_5190C:
		.BYTE	$22		; ADATA	$22
		.BYTE	$D0,$82		; ADATAEX     $D0,$82
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$C9,$09		; ADATAEX     $C9,$09
		.BYTE	$27		; ADATA	$27
		.BYTE	$25		; ADATA	$25
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$07		; ADATAEX     $C5,$07
		.BYTE	$C7,$09		; ADATAEX     $C7,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$D0,$08		; ADATAEX     $D0,$08
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$22		; ADATA	$22
		.BYTE	$25		; ADATA	$25
		.BYTE	$27		; ADATA	$27
		.BYTE	$29		; ADATA	$29
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C7,$07		; ADATAEX     $C7,$07
		.BYTE	$C9,$09		; ADATAEX     $C9,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$D0,$08		; ADATAEX     $D0,$08
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$C9,$09		; ADATAEX     $C9,$09
		.BYTE	$27		; ADATA	$27
		.BYTE	$25		; ADATA	$25
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$07		; ADATAEX     $C5,$07
		.BYTE	$C7,$09		; ADATAEX     $C7,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$1C		; ADATAEX     $D0,$1C
		.BYTE	$FB		; ARET
_asub_5195B:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$12		; ADATAEX     $D9,$12
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$36		; ADATA	$36
		.BYTE	$34		; ADATA	$34
		.BYTE	$D5,$02		; ADATAEX     $D5,$02
		.BYTE	$D6,$12		; ADATAEX     $D6,$12
		.BYTE	$79		; ADATA	$79
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DA,$02		; ADATAEX     $DA,$02
		.BYTE	$DB,$12		; ADATAEX     $DB,$12
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$09		; ADATAEX     $DD,$09
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$19		; ADATA	$19
		.BYTE	$96		; ADATA	$96
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$12		; ADATAEX     $D9,$12
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$30		; ADATA	$30
		.BYTE	$34		; ADATA	$34
		.BYTE	$30		; ADATA	$30
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$09		; ADATAEX     $D9,$09
		.BYTE	$30		; ADATA	$30
		.BYTE	$36		; ADATA	$36
		.BYTE	$34		; ADATA	$34
		.BYTE	$76		; ADATA	$76
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$D9,$01		; ADATAEX     $D9,$01
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$12		; ADATAEX     $DB,$12
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$19		; ADATA	$19
		.BYTE	$96		; ADATA	$96
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FB		; ARET
_asub_519B1:
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$12		; ADATAEX     $D9,$12
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$30		; ADATA	$30
		.BYTE	$34		; ADATA	$34
		.BYTE	$30		; ADATA	$30
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$1C		; ADATAEX     $D9,$1C
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$D0,$29		; ADATAEX     $D0,$29
		.BYTE	$FB		; ARET
_asub_519C7:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$D9,$01		; ADATAEX     $D9,$01
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$12		; ADATAEX     $DB,$12
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$39		; ADATA	$39
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$A8		; ACMDF6      $A8
		.BYTE	$36		; ADATA	$36
		.BYTE	$34		; ADATA	$34
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$76		; ADATA	$76
		.BYTE	$D0,$46		; ADATAEX     $D0,$46
		.BYTE	$FB		; ARET
_asub_519E2:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$DA,$02		; ADATAEX     $DA,$02
		.BYTE	$DB,$08		; ADATAEX     $DB,$08
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$09		; ADATAEX     $DB,$09
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$30		; ADATA	$30
		.BYTE	$DB,$01		; ADATAEX     $DB,$01
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$26		; ADATAEX     $DD,$26
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$FB		; ARET
_asub_519FE:
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$42		; ADATA	$42
		.BYTE	$50		; ADATA	$50
		.BYTE	$40		; ADATA	$40
		.BYTE	$10		; ADATA	$10
		.BYTE	$22		; ADATA	$22
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$FD		; ALOOP_END
		.BYTE	$42		; ADATA	$42
		.BYTE	$50		; ADATA	$50
		.BYTE	$60		; ADATA	$60
		.BYTE	$70		; ADATA	$70
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$20		; ADATA	$20
		.BYTE	$40		; ADATA	$40
		.BYTE	$10		; ADATA	$10
		.BYTE	$42		; ADATA	$42
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$70		; ADATA	$70
		.BYTE	$FB		; ARET
_mus6_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51A56
		.WORD	_asub_51A56
		.BYTE	$FA		; AJSR	_asub_51A6A
		.WORD	_asub_51A6A
		.BYTE	$FA		; AJSR	_asub_51A7D
		.WORD	_asub_51A7D
		.BYTE	$FA		; AJSR	_asub_51A90
		.WORD	_asub_51A90
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51AA3
		.WORD	_asub_51AA3
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_519C7
		.WORD	_asub_519C7
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_51AA3
		.WORD	_asub_51AA3
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_519E2
		.WORD	_asub_519E2
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51AB6
		.WORD	_asub_51AB6
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_51A21
		.WORD	_mus6_E
		.BYTE	$FF		; ASTOP
_asub_51A56:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$76		; ADATA	$76
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$36		; ADATA	$36
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$22		; ADATA	$22
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51A6A:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$35		; ADATA	$35
		.BYTE	$35		; ADATA	$35
		.BYTE	$35		; ADATA	$35
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$21		; ADATA	$21
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51A7D:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$20		; ADATA	$20
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51A90:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$33		; ADATA	$33
		.BYTE	$33		; ADATA	$33
		.BYTE	$33		; ADATA	$33
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51AA3:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$62		; ADATA	$62
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$30		; ADATA	$30
		.BYTE	$A2		; ADATA	$A2
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FB		; ARET
_asub_51AB6:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$20		; ADATA	$20
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_mus7:
		.BYTE	$05
		.WORD	_mus7_A
		.BYTE	$0C
		.WORD	_mus7_B
		.BYTE	$0C
		.WORD	_mus7_C
		.BYTE	$08
		.WORD	_mus7_D
		.BYTE	$04
		.WORD	_mus7_E
		.BYTE	$00
_mus7_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51B0D
		.WORD	_asub_51B0D
		.BYTE	$FA		; AJSR	_asub_51B1E
		.WORD	_asub_51B1E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B0D
		.WORD	_asub_51B0D
		.BYTE	$FA		; AJSR	_asub_51B30
		.WORD	_asub_51B30
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51B47
		.WORD	_asub_51B47
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B59
		.WORD	_asub_51B59
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51B47
		.WORD	_asub_51B47
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B30
		.WORD	_asub_51B30
		.BYTE	$FA		; AJSR	_asub_51B30
		.WORD	_asub_51B30
		.BYTE	$F8		; AJMP	_aloc_51AE0
		.WORD	_mus7_A
		.BYTE	$FF		; ASTOP
_asub_51B0D:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51B1E:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51B30:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_51B47:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51B59:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_mus7_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51B9B
		.WORD	_asub_51B9B
		.BYTE	$FA		; AJSR	_asub_51BAF
		.WORD	_asub_51BAF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B9B
		.WORD	_asub_51B9B
		.BYTE	$FA		; AJSR	_asub_51BC1
		.WORD	_asub_51BC1
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51BD0
		.WORD	_asub_51BD0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51BEB
		.WORD	_asub_51BEB
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51BD0
		.WORD	_asub_51BD0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51BC1
		.WORD	_asub_51BC1
		.BYTE	$FA		; AJSR	_asub_51C0C
		.WORD	_asub_51C0C
		.BYTE	$F8		; AJMP	_aloc_51B6D
		.WORD	_mus7_B
		.BYTE	$FF		; ASTOP
_asub_51B9B:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_51BAF:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$FB		; ARET
_asub_51BC1:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$23		; ADATA	$23
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_51BD0:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_51BEB:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_51C0C:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$23		; ADATA	$23
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$06		; ADATA	$06
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
_mus7_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51C64
		.WORD	_asub_51C64
		.BYTE	$D0,$F0		; ADATAEX     $D0,$F0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51C64
		.WORD	_asub_51C64
		.BYTE	$FA		; AJSR	_asub_51C72
		.WORD	_asub_51C72
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1E		; ACMDF5      $1E
		.BYTE	$FA		; AJSR	_asub_51C99
		.WORD	_asub_51C99
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1E		; ACMDF5      $1E
		.BYTE	$FA		; AJSR	_asub_51C99
		.WORD	_asub_51C99
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_51CAA
		.WORD	_asub_51CAA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_51CAA
		.WORD	_asub_51CAA
		.BYTE	$FA		; AJSR	_asub_51CAA
		.WORD	_asub_51CAA
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_51CB5
		.WORD	_asub_51CB5
		.BYTE	$FA		; AJSR	_asub_51CBA
		.WORD	_asub_51CBA
		.BYTE	$F8		; AJMP	_aloc_51C24
		.WORD	_mus7_C
		.BYTE	$FF		; ASTOP
_asub_51C64:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$16		; ACMDF5      $16
		.BYTE	$60		; ADATA	$60
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$30		; ADATA	$30
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$FB		; ARET
_asub_51C72:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$07		; ADATA	$07
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7C		; ADATA	$7C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51C99:
		.BYTE	$F4,$BE		; ACMDF4      $BE
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$34		; ADATA	$34
		.BYTE	$20		; ADATA	$20
		.BYTE	$FD		; ALOOP_END
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$14		; ADATA	$14
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_asub_51CAA:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_51CB5:
		.BYTE	$78		; ADATA	$78
		.BYTE	$79		; ADATA	$79
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$FB		; ARET
_asub_51CBA:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$65		; ADATA	$65
		.BYTE	$59		; ADATA	$59
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_mus7_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51D20
		.WORD	_asub_51D20
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51D6A
		.WORD	_asub_51D6A
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51DA7
		.WORD	_asub_51DA7
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51DD2
		.WORD	_asub_51DD2
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_51E03
		.WORD	_asub_51E03
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_51E1A
		.WORD	_asub_51E1A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_51E1A
		.WORD	_asub_51E1A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_51E2A
		.WORD	_asub_51E2A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$FA		; AJSR	_asub_51E2A
		.WORD	_asub_51E2A
		.BYTE	$F5,$24		; ACMDF5      $24
		.BYTE	$FA		; AJSR	_asub_51E03
		.WORD	_asub_51E03
		.BYTE	$FA		; AJSR	_asub_51E40
		.WORD	_asub_51E40
		.BYTE	$F8		; AJMP	_aloc_51CC2
		.WORD	_mus7_D
		.BYTE	$FF		; ASTOP
_asub_51D0A:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$16		; ACMDF5      $16
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$74		; ADATA	$74
		.BYTE	$40		; ADATA	$40
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$30		; ADATA	$30
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$FB		; ARET
_asub_51D20:
		.BYTE	$90		; ADATA	$90
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$02		; ADATA	$02
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$02		; ADATA	$02
		.BYTE	$16		; ADATA	$16
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$C0,$09		; ADATAEX     $C0,$09
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$22		; ADATA	$22
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_51D6A:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$79		; ADATA	$79
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$13		; ADATAEX     $DF,$13
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$10		; ADATA	$10
		.BYTE	$02		; ADATA	$02
		.BYTE	$02		; ADATA	$02
		.BYTE	$42		; ADATA	$42
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$20		; ADATA	$20
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$76		; ADATA	$76
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$00		; ADATA	$00
		.BYTE	$19		; ADATA	$19
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$79		; ADATA	$79
		.BYTE	$FB		; ARET
_asub_51DA7:
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$62		; ADATA	$62
		.BYTE	$25		; ADATA	$25
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07		; ADATA	$07
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$05		; ADATA	$05
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$56		; ADATA	$56
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_51DD2:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$D0,$03		; ADATAEX     $D0,$03
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$23		; ACMDF6      $23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$13		; ADATAEX     $C7,$13
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$22		; ADATA	$22
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$D9,$07		; ADATAEX     $D9,$07
		.BYTE	$FB		; ARET
_asub_51E03:
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$07		; ADATA	$07
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$03		; ADATA	$03
		.BYTE	$06		; ADATA	$06
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_51E1A:
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$18		; ADATA	$18
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_51E2A:
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$34		; ADATA	$34
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$14		; ADATA	$14
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$14		; ADATA	$14
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_51E40:
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$08		; ADATA	$08
		.BYTE	$06		; ADATA	$06
		.BYTE	$03		; ADATA	$03
		.BYTE	$06		; ADATA	$06
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$FB		; ARET
_mus7_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51EA7
		.WORD	_asub_51EA7
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51EEB
		.WORD	_asub_51EEB
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51F30
		.WORD	_asub_51F30
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51F5F
		.WORD	_asub_51F5F
		.BYTE	$FA		; AJSR	_asub_51F92
		.WORD	_asub_51F92
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_51FA5
		.WORD	_asub_51FA5
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_51FA5
		.WORD	_asub_51FA5
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_51FD8
		.WORD	_asub_51FD8
		.BYTE	$FA		; AJSR	_asub_51FD8
		.WORD	_asub_51FD8
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_51FD8
		.WORD	_asub_51FD8
		.BYTE	$F5,$30		; ACMDF5      $30
		.BYTE	$FA		; AJSR	_asub_51F92
		.WORD	_asub_51F92
		.BYTE	$FA		; AJSR	_asub_51FE4
		.WORD	_asub_51FE4
		.BYTE	$F8		; AJMP	_aloc_51E55
		.WORD	_mus7_E
		.BYTE	$FF		; ASTOP
_asub_51E97:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0A		; ACMDF5      $0A
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$67		; ADATA	$67
		.BYTE	$47		; ADATA	$47
		.BYTE	$04		; ADATA	$04
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$25		; ADATA	$25
		.BYTE	$FB		; ARET
_asub_51EA7:
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$02		; ADATA	$02
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$01		; ADATA	$01
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$02		; ADATA	$02
		.BYTE	$16		; ADATA	$16
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$C0,$09		; ADATAEX     $C0,$09
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$22		; ADATA	$22
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_51EEB:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$67		; ADATA	$67
		.BYTE	$65		; ADATA	$65
		.BYTE	$CA,$01		; ADATAEX     $CA,$01
		.BYTE	$CB,$13		; ADATAEX     $CB,$13
		.BYTE	$67		; ADATA	$67
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$05		; ADATA	$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$02		; ADATA	$02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$62		; ADATA	$62
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$05		; ADATA	$05
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$05		; ADATA	$05
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$05		; ADATA	$05
		.BYTE	$00		; ADATA	$00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$65		; ADATA	$65
		.BYTE	$FB		; ARET
_asub_51F30:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$62		; ADATA	$62
		.BYTE	$67		; ADATA	$67
		.BYTE	$CA,$02		; ADATAEX     $CA,$02
		.BYTE	$CB,$08		; ADATAEX     $CB,$08
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$07		; ADATA	$07
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$60		; ADATA	$60
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$62		; ADATA	$62
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$79		; ADATA	$79
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$56		; ADATA	$56
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_51F5F:
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$3F		; ACMDF5      $3F
		.BYTE	$19		; ADATA	$19
		.BYTE	$16		; ADATA	$16
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$16		; ADATA	$16
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$16		; ADATA	$16
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$16		; ADATA	$16
		.BYTE	$19		; ADATA	$19
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$13		; ADATA	$13
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$13		; ADATAEX     $C7,$13
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$22		; ADATA	$22
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_51F92:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$27		; ADATA	$27
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$28		; ADATA	$28
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$29		; ADATA	$29
		.BYTE	$01		; ADATA	$01
		.BYTE	$04		; ADATA	$04
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_asub_51FA5:
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$23		; ADATAEX     $D8,$23
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$76		; ADATA	$76
		.BYTE	$51		; ADATA	$51
		.BYTE	$12		; ADATA	$12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$08		; ADATAEX     $DE,$08
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$76		; ADATA	$76
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$A4		; ADATA	$A4
		.BYTE	$C1,$03		; ADATAEX     $C1,$03
		.BYTE	$C0,$03		; ADATAEX     $C0,$03
		.BYTE	$DF,$04		; ADATAEX     $DF,$04
		.BYTE	$DE,$28		; ADATAEX     $DE,$28
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$22		; ADATA	$22
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$69		; ADATA	$69
		.BYTE	$60		; ADATA	$60
		.BYTE	$FB		; ARET
_asub_51FD8:
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$07		; ADATA	$07
		.BYTE	$FB		; ARET
_asub_51FE4:
		.BYTE	$29		; ADATA	$29
		.BYTE	$01		; ADATA	$01
		.BYTE	$04		; ADATA	$04
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$17		; ADATA	$17
		.BYTE	$14		; ADATA	$14
		.BYTE	$FB		; ARET
_mus8:
		.BYTE	$05
		.WORD	_mus8_A
		.BYTE	$0C
		.WORD	_mus8_B
		.BYTE	$0C
		.WORD	_mus8_C
		.BYTE	$00
		.WORD	_mus8_D
		.BYTE	$08
		.WORD	_mus8_E
		.BYTE	$04
_mus8_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FA		; AJSR	_asub_5202D
		.WORD	_asub_5202D
_aloc_5200E:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_52047
		.WORD	_asub_52047
		.BYTE	$FA		; AJSR	_asub_5205A
		.WORD	_asub_5205A
		.BYTE	$FA		; AJSR	_asub_52070
		.WORD	_asub_52070
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52047
		.WORD	_asub_52047
		.BYTE	$FA		; AJSR	_asub_5205A
		.WORD	_asub_5205A
		.BYTE	$FA		; AJSR	_asub_52079
		.WORD	_asub_52079
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	_asub_52082
		.WORD	_asub_52082
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_5200E
		.WORD	_aloc_5200E
		.BYTE	$FF		; ASTOP
_asub_5202D:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$DF,$03		; ADATAEX     $DF,$03
		.BYTE	$DF,$04		; ADATAEX     $DF,$04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_52047:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_asub_5205A:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_52070:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_52079:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_52082:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_mus8_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_520C7
		.WORD	_asub_520C7
_aloc_520A8:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_520D7
		.WORD	_asub_520D7
		.BYTE	$FA		; AJSR	_asub_520F4
		.WORD	_asub_520F4
		.BYTE	$FA		; AJSR	_asub_5210C
		.WORD	_asub_5210C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_520D7
		.WORD	_asub_520D7
		.BYTE	$FA		; AJSR	_asub_520F4
		.WORD	_asub_520F4
		.BYTE	$FA		; AJSR	_asub_52113
		.WORD	_asub_52113
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	_asub_5211B
		.WORD	_asub_5211B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_520A8
		.WORD	_aloc_520A8
		.BYTE	$FF		; ASTOP
_asub_520C7:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$C6,$03		; ADATAEX     $C6,$03
		.BYTE	$C6,$04		; ADATAEX     $C6,$04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$26		; ADATA	$26
		.BYTE	$46		; ADATA	$46
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$46		; ADATA	$46
		.BYTE	$26		; ADATA	$26
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_asub_520D7:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_520F4:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$FB		; ARET
_asub_5210C:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$FB		; ARET
_asub_52113:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_5211B:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_mus8_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$D0,$7F		; ADATAEX     $D0,$7F
_aloc_52143:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_52195
		.WORD	_asub_52195
		.BYTE	$FA		; AJSR	_asub_521AA
		.WORD	_asub_521AA
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_521C1
		.WORD	_asub_521C1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_521EB
		.WORD	_asub_521EB
		.BYTE	$FA		; AJSR	_asub_5221D
		.WORD	_asub_5221D
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$FA		; AJSR	_asub_521EB
		.WORD	_asub_521EB
		.BYTE	$FA		; AJSR	_asub_52233
		.WORD	_asub_52233
		.BYTE	$D0,$12		; ADATAEX     $D0,$12
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$F8		; AJMP	_aloc_522B4
		.WORD	_aloc_522B4
_aloc_52179:
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_52251
		.WORD	_asub_52251
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_5225C
		.WORD	_asub_5225C
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_52251
		.WORD	_asub_52251
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_5226C
		.WORD	_asub_5226C
		.BYTE	$F8		; AJMP	_aloc_52289
		.WORD	_aloc_52289
		.BYTE	$FF		; ASTOP
_asub_52195:
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$44		; ADATA	$44
		.BYTE	$43		; ADATA	$43
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$22		; ADATA	$22
		.BYTE	$03		; ADATA	$03
		.BYTE	$22		; ADATA	$22
		.BYTE	$01		; ADATA	$01
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$40		; ADATA	$40
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_521AA:
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$40		; ADATA	$40
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$58		; ADATA	$58
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$18		; ADATA	$18
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_521C1:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$0B		; ACMDF6      $0B
		.BYTE	$84		; ADATA	$84
		.BYTE	$04		; ADATA	$04
		.BYTE	$90		; ADATA	$90
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$DF,$06		; ADATAEX     $DF,$06
		.BYTE	$C7,$06		; ADATAEX     $C7,$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F4,$90		; ACMDF4      $90
		.BYTE	$18		; ADATA	$18
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$FB		; ARET
_asub_521EB:
		.BYTE	$50		; ADATA	$50
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$1D		; ADATAEX     $DF,$1D
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$C1,$01		; ADATAEX     $C1,$01
		.BYTE	$C2,$00		; ADATAEX     $C2,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$15		; ACMDF3      $15
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_5221D:
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$FB		; ARET
_asub_52223:
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$30		; ADATA	$30
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$30		; ADATA	$30
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$29		; ADATA	$29
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$49		; ADATA	$49
		.BYTE	$FB		; ARET
_asub_52233:
		.BYTE	$F4,$FC		; ACMDF4      $FC
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$C2,$06		; ADATAEX     $C2,$06
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_5223F:
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$F4,$E9		; ACMDF4      $E9
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$20		; ADATA	$20
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$22		; ADATA	$22
		.BYTE	$10		; ADATA	$10
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$FB		; ARET
_asub_52251:
		.BYTE	$DF,$41		; ADATAEX     $DF,$41
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$10		; ADATA	$10
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_asub_5225C:
		.BYTE	$DF,$00		; ADATAEX     $DF,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$1E		; ACMDF3      $1E
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$DD,$5A		; ADATAEX     $DD,$5A
		.BYTE	$FB		; ARET
_asub_5226C:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DF,$23		; ADATAEX     $DF,$23
		.BYTE	$C9,$01		; ADATAEX     $C9,$01
		.BYTE	$CA,$01		; ADATAEX     $CA,$01
		.BYTE	$CB,$1C		; ADATAEX     $CB,$1C
		.BYTE	$09		; ADATA	$09
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$02		; ADATA	$02
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$02		; ADATA	$02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FB		; ARET
_mus8_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$D0,$7F		; ADATAEX     $D0,$7F
_aloc_52289:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_522C5
		.WORD	_asub_522C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_522D0
		.WORD	_asub_522D0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_522C5
		.WORD	_asub_522C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_522FF
		.WORD	_asub_522FF
		.BYTE	$FA		; AJSR	_asub_52308
		.WORD	_asub_52308
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FA		; AJSR	_asub_52308
		.WORD	_asub_52308
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_52179
		.WORD	_aloc_52179
_aloc_522B4:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_52316
		.WORD	_asub_52316
		.BYTE	$F5,$1A		; ACMDF5      $1A
		.BYTE	$FA		; AJSR	_asub_52316
		.WORD	_asub_52316
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_52143
		.WORD	_aloc_52143
		.BYTE	$FF		; ASTOP
_asub_522C5:
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$18		; ADATA	$18
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_522D0:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$83		; ADATA	$83
		.BYTE	$03		; ADATA	$03
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$58		; ADATA	$58
		.BYTE	$58		; ADATA	$58
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$24		; ADATA	$24
		.BYTE	$18		; ADATA	$18
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_522FF:
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$09		; ADATA	$09
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$29		; ADATA	$29
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FB		; ARET
_asub_52308:
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$04		; ADATA	$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$04		; ADATA	$04
		.BYTE	$42		; ADATA	$42
		.BYTE	$FB		; ARET
_asub_52316:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$58		; ADATA	$58
		.BYTE	$40		; ADATA	$40
		.BYTE	$38		; ADATA	$38
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$20		; ADATA	$20
		.BYTE	$18		; ADATA	$18
		.BYTE	$38		; ADATA	$38
		.BYTE	$00		; ADATA	$00
		.BYTE	$38		; ADATA	$38
		.BYTE	$14		; ADATA	$14
		.BYTE	$FB		; ARET
_mus8_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$D0,$7F		; ADATAEX     $D0,$7F
_aloc_5232F:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$FA		; AJSR	_asub_52360
		.WORD	_asub_52360
		.BYTE	$FA		; AJSR	_asub_52373
		.WORD	_asub_52373
		.BYTE	$FA		; AJSR	_asub_52386
		.WORD	_asub_52386
		.BYTE	$FA		; AJSR	_asub_52360
		.WORD	_asub_52360
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_523AC
		.WORD	_asub_523AC
		.BYTE	$FA		; AJSR	_asub_523E3
		.WORD	_asub_523E3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_5241D
		.WORD	_asub_5241D
		.BYTE	$F5,$0E		; ACMDF5      $0E
		.BYTE	$FA		; AJSR	_asub_5241D
		.WORD	_asub_5241D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_5232F
		.WORD	_aloc_5232F
		.BYTE	$FF		; ASTOP
_asub_52360:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$58		; ADATA	$58
		.BYTE	$58		; ADATA	$58
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$58		; ADATA	$58
		.BYTE	$50		; ADATA	$50
		.BYTE	$33		; ADATA	$33
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$13		; ADATA	$13
		.BYTE	$FB		; ARET
_asub_52373:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$40		; ADATA	$40
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$40		; ADATA	$40
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$58		; ADATA	$58
		.BYTE	$FB		; ARET
_asub_52386:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$13		; ADATA	$13
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$DF,$09		; ADATAEX     $DF,$09
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$09		; ADATAEX     $DD,$09
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$FB		; ARET
_asub_523AC:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$01		; ADATAEX     $C3,$01
		.BYTE	$C4,$08		; ADATAEX     $C4,$08
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0E		; ADATAEX     $DD,$0E
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$38		; ADATA	$38
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$13		; ADATA	$13
		.BYTE	$18		; ADATA	$18
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$FB		; ARET
_asub_523E3:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0E		; ADATAEX     $DD,$0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0E		; ADATAEX     $DD,$0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$50		; ADATA	$50
		.BYTE	$33		; ADATA	$33
		.BYTE	$02		; ADATA	$02
		.BYTE	$FB		; ARET
_asub_5241D:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$54		; ADATA	$54
		.BYTE	$40		; ADATA	$40
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$20		; ADATA	$20
		.BYTE	$00		; ADATA	$00
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_mus9:
		.BYTE	$05
		.WORD	_mus9_A
		.BYTE	$0C
		.WORD	_mus9_B
		.BYTE	$0C
		.WORD	_mus9_C
		.BYTE	$00
		.WORD	_mus9_D
		.BYTE	$04
		.WORD	_mus9_E
		.BYTE	$08
_mus9_A:
		.BYTE	$F2,$02		; ACMDF2      $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$DF,$09		; ADATAEX     $DF,$09
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DA,$37		; ADATAEX     $DA,$37
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$F8		; AJMP	_aloc_5243F
		.WORD	_mus9_A
		.BYTE	$FF		; ASTOP
_mus9_B:
		.BYTE	$F2,$02		; ACMDF2      $02
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C5,$11		; ADATAEX     $C5,$11
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C6,$07		; ADATAEX     $C6,$07
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$27		; ADATA	$27
		.BYTE	$F4,$B4		; ACMDF4      $B4
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$CB,$09		; ADATAEX     $CB,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$C7,$0F		; ADATAEX     $C7,$0F
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$29		; ADATA	$29
		.BYTE	$F8		; AJMP	_aloc_52459
		.WORD	_mus9_B
		.BYTE	$FF		; ASTOP
_mus9_C:
		.BYTE	$F2,$02		; ACMDF2      $02
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$70		; ADATA	$70
		.BYTE	$75		; ADATA	$75
		.BYTE	$78		; ADATA	$78
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$D0,$A0		; ADATAEX     $D0,$A0
		.BYTE	$75		; ADATA	$75
		.BYTE	$78		; ADATA	$78
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$A1		; ADATA	$A1
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$D0,$A0		; ADATAEX     $D0,$A0
		.BYTE	$75		; ADATA	$75
		.BYTE	$78		; ADATA	$78
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$D0,$A0		; ADATAEX     $D0,$A0
		.BYTE	$75		; ADATA	$75
		.BYTE	$78		; ADATA	$78
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$61		; ADATA	$61
		.BYTE	$64		; ADATA	$64
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$90		; ADATA	$90
		.BYTE	$DB,$60		; ADATAEX     $DB,$60
		.BYTE	$79		; ADATA	$79
		.BYTE	$D8,$60		; ADATAEX     $D8,$60
		.BYTE	$79		; ADATA	$79
		.BYTE	$DB,$60		; ADATAEX     $DB,$60
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$DE,$00		; ADATAEX     $DE,$00
		.BYTE	$F1,$00		; ACMDF1      $00
		.BYTE	$F3,$80		; ACMDF3      $80
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F3,$10		; ACMDF3      $10
		.BYTE	$FD		; ALOOP_END
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F0,$06		; ACMDF0      $06
		.BYTE	$F5,$3F		; ACMDF5      $3F
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_524F1
		.WORD	_asub_524F1
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FA		; AJSR	_asub_524F1
		.WORD	_asub_524F1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX     $D0,$10
		.BYTE	$F8		; AJMP	_aloc_5248F
		.WORD	_mus9_C
		.BYTE	$FF		; ASTOP
_asub_524F1:
		.BYTE	$69		; ADATA	$69
		.BYTE	$66		; ADATA	$66
		.BYTE	$63		; ADATA	$63
		.BYTE	$60		; ADATA	$60
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$77		; ADATA	$77
		.BYTE	$76		; ADATA	$76
		.BYTE	$77		; ADATA	$77
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$60		; ADATA	$60
		.BYTE	$63		; ADATA	$63
		.BYTE	$66		; ADATA	$66
		.BYTE	$FB		; ARET
_mus9_D:
		.BYTE	$F2,$02		; ACMDF2      $02
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$75		; ADATA	$75
		.BYTE	$78		; ADATA	$78
		.BYTE	$BB		; ADATA	$BB
		.BYTE	$B5		; ADATA	$B5
		.BYTE	$99		; ADATA	$99
		.BYTE	$D0,$C0		; ADATAEX     $D0,$C0
		.BYTE	$75		; ADATA	$75
		.BYTE	$78		; ADATA	$78
		.BYTE	$BB		; ADATA	$BB
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$99		; ADATA	$99
		.BYTE	$90		; ADATA	$90
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D8,$60		; ADATAEX     $D8,$60
		.BYTE	$76		; ADATA	$76
		.BYTE	$D5,$60		; ADATAEX     $D5,$60
		.BYTE	$76		; ADATA	$76
		.BYTE	$D8,$60		; ADATAEX     $D8,$60
		.BYTE	$79		; ADATA	$79
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$DB,$00		; ADATAEX     $DB,$00
		.BYTE	$F1,$00		; ACMDF1      $00
		.BYTE	$F3,$80		; ACMDF3      $80
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F3,$10		; ACMDF3      $10
		.BYTE	$FD		; ALOOP_END
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_524F1
		.WORD	_asub_524F1
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FA		; AJSR	_asub_524F1
		.WORD	_asub_524F1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX     $D0,$10
		.BYTE	$F8		; AJMP	_aloc_52500
		.WORD	_mus9_D
		.BYTE	$FF		; ASTOP
_mus9_E:
		.BYTE	$F2,$02		; ACMDF2      $02
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$16		; ACMDF5      $16
_aloc_5255C:
		.BYTE	$A2		; ADATA	$A2
		.BYTE	$F8		; AJMP	_aloc_5255C
		.WORD	_aloc_5255C
		.BYTE	$FF		; ASTOP
_musA:
		.BYTE	$05
		.WORD	_musA_A
		.BYTE	$0C
		.WORD	_musA_B
		.BYTE	$0C
		.WORD	_musA_C
		.BYTE	$00
		.WORD	_musA_D
		.BYTE	$04
		.WORD	_musA_E
		.BYTE	$08
_musA_A:
		.BYTE	$F2,$03		; ACMDF2      $03
_aloc_52573:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$F8		; AJMP	_aloc_52573
		.WORD	_aloc_52573
		.BYTE	$FF		; ASTOP
_musA_B:
		.BYTE	$F2,$03		; ACMDF2      $03
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_525B1
		.WORD	_asub_525B1
		.BYTE	$FA		; AJSR	_asub_525C8
		.WORD	_asub_525C8
		.BYTE	$FA		; AJSR	_asub_525B1
		.WORD	_asub_525B1
		.BYTE	$FA		; AJSR	_asub_525E1
		.WORD	_asub_525E1
		.BYTE	$F8		; AJMP	_aloc_5259B
		.WORD	_musA_B
		.BYTE	$FF		; ASTOP
_asub_525B1:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_525C8:
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_525E1:
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_musA_C:
		.BYTE	$F2,$03		; ACMDF2      $03
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_525FC:
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$CB,$40		; ADATAEX     $CB,$40
		.BYTE	$CC,$40		; ADATAEX     $CC,$40
		.BYTE	$66		; ADATA	$66
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$CB,$40		; ADATAEX     $CB,$40
		.BYTE	$C7,$40		; ADATAEX     $C7,$40
		.BYTE	$C9,$40		; ADATAEX     $C9,$40
		.BYTE	$66		; ADATA	$66
		.BYTE	$69		; ADATA	$69
		.BYTE	$C7,$40		; ADATAEX     $C7,$40
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F8		; AJMP	_aloc_525FC
		.WORD	_aloc_525FC
		.BYTE	$FF		; ASTOP
_musA_D:
		.BYTE	$F2,$03		; ACMDF2      $03
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_5261C:
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$DB,$40		; ADATAEX     $DB,$40
		.BYTE	$DD,$40		; ADATAEX     $DD,$40
		.BYTE	$77		; ADATA	$77
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$DB,$40		; ADATAEX     $DB,$40
		.BYTE	$D8,$40		; ADATAEX     $D8,$40
		.BYTE	$D4,$40		; ADATAEX     $D4,$40
		.BYTE	$73		; ADATA	$73
		.BYTE	$77		; ADATA	$77
		.BYTE	$D8,$40		; ADATAEX     $D8,$40
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F8		; AJMP	_aloc_5261C
		.WORD	_aloc_5261C
		.BYTE	$FF		; ASTOP
_musA_E:
		.BYTE	$F2,$03		; ACMDF2      $03
		.BYTE	$F6,$03		; ACMDF6      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$10		; ALOOP_START $10
		.BYTE	$70		; ADATA	$70
		.BYTE	$FD		; ALOOP_END
_aloc_52644:
		.BYTE	$C4,$C8		; ADATAEX     $C4,$C8
		.BYTE	$C4,$38		; ADATAEX     $C4,$38
		.BYTE	$F8		; AJMP	_aloc_52644
		.WORD	_aloc_52644
		.BYTE	$FF		; ASTOP
_musB:
		.BYTE	$05
		.WORD	_musB_A
		.BYTE	$0C
		.WORD	_musB_B
		.BYTE	$0C
		.WORD	_musB_C
		.BYTE	$08
		.WORD	_musB_D
		.BYTE	$04
		.WORD	_musB_E
		.BYTE	$00
_musB_A:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_52671
		.WORD	_asub_52671
		.BYTE	$FA		; AJSR	_asub_5268D
		.WORD	_asub_5268D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52671
		.WORD	_asub_52671
		.BYTE	$FA		; AJSR	_asub_526AA
		.WORD	_asub_526AA
		.BYTE	$F8		; AJMP	_aloc_5265C
		.WORD	_musB_A
		.BYTE	$FF		; ASTOP
_asub_52671:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_5268D:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$FB		; ARET
_asub_526AA:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_musB_B:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_526DD
		.WORD	_asub_526DD
		.BYTE	$FA		; AJSR	_asub_526F8
		.WORD	_asub_526F8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_526DD
		.WORD	_asub_526DD
		.BYTE	$FA		; AJSR	_asub_52711
		.WORD	_asub_52711
		.BYTE	$F8		; AJMP	_aloc_526C4
		.WORD	_musB_B
		.BYTE	$FF		; ASTOP
_asub_526DD:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_526F8:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_asub_52711:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$03		; ADATA	$03
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_musB_C:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$13		; ACMDF5      $13
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_5277C
		.WORD	_asub_5277C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_52781
		.WORD	_asub_52781
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_5277C
		.WORD	_asub_5277C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_52781
		.WORD	_asub_52781
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$F5,$1A		; ACMDF5      $1A
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$F5,$1A		; ACMDF5      $1A
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52797
		.WORD	_asub_52797
		.BYTE	$F8		; AJMP	_aloc_52726
		.WORD	_musB_C
		.BYTE	$FF		; ASTOP
_asub_52772:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_5277C:
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_asub_52781:
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FB		; ARET
_asub_52786:
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$15		; ADATA	$15
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$01		; ADATA	$01
		.BYTE	$04		; ADATA	$04
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$15		; ADATA	$15
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$12		; ADATA	$12
		.BYTE	$03		; ADATA	$03
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_52797:
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$18		; ADATA	$18
		.BYTE	$04		; ADATA	$04
		.BYTE	$01		; ADATA	$01
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$01		; ADATA	$01
		.BYTE	$FB		; ARET
_musB_D:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$24		; ACMDF6      $24
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$03		; ACMDF5      $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527F7
		.WORD	_asub_527F7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527FC
		.WORD	_asub_527FC
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527F7
		.WORD	_asub_527F7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527FC
		.WORD	_asub_527FC
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$22		; ACMDF6      $22
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52801
		.WORD	_asub_52801
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$26		; ACMDF5      $26
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52801
		.WORD	_asub_52801
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_527A8
		.WORD	_musB_D
		.BYTE	$FF		; ASTOP
_asub_527ED:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_527F7:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_527FC:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_asub_52801:
		.BYTE	$30		; ADATA	$30
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_musB_E:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$22		; ACMDF6      $22
		.BYTE	$F5,$03		; ACMDF5      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_52857
		.WORD	_asub_52857
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_5285C
		.WORD	_asub_5285C
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_52857
		.WORD	_asub_52857
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_5285C
		.WORD	_asub_5285C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52861
		.WORD	_asub_52861
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$26		; ACMDF5      $26
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52861
		.WORD	_asub_52861
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_5280A
		.WORD	_musB_E
		.BYTE	$FF		; ASTOP
_asub_5284D:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_52857:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_5285C:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_asub_52861:
		.BYTE	$30		; ADATA	$30
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$24		; ADATA	$24
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
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
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$2B		; ACMDF5      $2B
		.BYTE	$E1,$01		; ACMDE1      $01
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$09		; ADATA	$09
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$03		; ADATA	$03
		.BYTE	$E1,$00		; ACMDE1      $00
		.BYTE	$FF		; ASTOP
_snd01_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$18		; ACMDF5      $18
		.BYTE	$13		; ADATA	$13
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$15		; ADATA	$15
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$04		; ADATA	$04
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$16		; ADATA	$16
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$FF		; ASTOP
_snd02_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$80		; ACMDF6      $80
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$CE,$00		; ADATAEX     $CE,$00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$FE		; ACMDE3      $FE
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd02_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$03		; ACMDF6      $03
		.BYTE	$31		; ADATA	$31
		.BYTE	$14		; ADATA	$14
		.BYTE	$01		; ADATA	$01
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$17		; ADATA	$17
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$18		; ADATA	$18
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$FF		; ASTOP
_snd03_E:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$DC		; ACMDF4      $DC
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$28		; ADATA	$28
		.BYTE	$F0,$00		; ACMDF0      $00
		.BYTE	$AF		; ADATA	$AF
		.BYTE	$FF		; ASTOP
_snd03_C:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$23		; ACMDF6      $23
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$39		; ADATA	$39
		.BYTE	$FF		; ASTOP
_snd03_D:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$39		; ADATA	$39
		.BYTE	$FF		; ASTOP
_snd03_A:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$39		; ADATA	$39
		.BYTE	$FF		; ASTOP
_snd03_B:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$FF		; ASTOP
_snd04_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F0,$00		; ACMDF0      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$21		; ACMDF5      $21
		.BYTE	$C2,$00		; ADATAEX     $C2,$00
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$EC		; ACMDE3      $EC
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$FA		; ACMDE3      $FA
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$08		; ACMDE3      $08
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$70		; ADATA	$70
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$FF		; ASTOP
_snd04_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_52A42
		.WORD	_asub_52A42
		.BYTE	$F5,$03		; ACMDF5      $03
		.BYTE	$FA		; AJSR	_asub_52A42
		.WORD	_asub_52A42
		.BYTE	$F1,$FB		; ACMDF1      $FB
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_asub_52A42:
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$05		; ADATA	$05
		.BYTE	$03		; ADATA	$03
		.BYTE	$01		; ADATA	$01
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_snd05_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$28		; ADATA	$28
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$20		; ADATA	$20
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3A		; ADATA	$3A
		.BYTE	$FF		; ASTOP
_snd05_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$26		; ADATA	$26
		.BYTE	$09		; ADATA	$09
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$FF		; ASTOP
_snd06_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C1,$00		; ADATAEX     $C1,$00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$08		; ADATA	$08
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd06_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$17		; ADATA	$17
		.BYTE	$10		; ADATA	$10
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$16		; ADATA	$16
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd07_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F6,$03		; ACMDF6      $03
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$11		; ADATA	$11
		.BYTE	$12		; ADATA	$12
		.BYTE	$15		; ADATA	$15
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$01		; ADATA	$01
		.BYTE	$02		; ADATA	$02
		.BYTE	$03		; ADATA	$03
		.BYTE	$FF		; ASTOP
_snd07_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$4E		; ADATA	$4E
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$06		; ADATA	$06
		.BYTE	$05		; ADATA	$05
		.BYTE	$FF		; ASTOP
_snd08_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$01		; ADATA	$01
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$03		; ADATA	$03
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$3C		; ACMDF5      $3C
		.BYTE	$10		; ADATA	$10
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$19		; ADATA	$19
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$30		; ADATA	$30
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$10		; ADATA	$10
		.BYTE	$16		; ADATA	$16
		.BYTE	$17		; ADATA	$17
		.BYTE	$18		; ADATA	$18
		.BYTE	$10		; ADATA	$10
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$15		; ADATA	$15
		.BYTE	$16		; ADATA	$16
		.BYTE	$17		; ADATA	$17
		.BYTE	$FF		; ASTOP
_snd09_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$20		; ACMDF5      $20
		.BYTE	$D4,$00		; ADATAEX     $D4,$00
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$EB		; ACMDE3      $EB
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
_aloc_52B27:
		.BYTE	$E3,$20		; ACMDE3      $20
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$E3,$E0		; ACMDE3      $E0
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$E3,$2C		; ACMDE3      $2C
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$E3,$D4		; ACMDE3      $D4
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F8		; AJMP	_aloc_52B27
		.WORD	_aloc_52B27
		.BYTE	$FF		; ASTOP
_snd09_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_52B43:
		.BYTE	$26		; ADATA	$26
		.BYTE	$CC,$0A		; ADATAEX     $CC,$0A
		.BYTE	$A9		; ADATA	$A9
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$47		; ADATA	$47
		.BYTE	$8F		; ADATA	$8F
		.BYTE	$68		; ADATA	$68
		.BYTE	$F8		; AJMP	_aloc_52B43
		.WORD	_aloc_52B43
_snd0A_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$2C		; ACMDF6      $2C
		.BYTE	$F5,$3F		; ACMDF5      $3F
		.BYTE	$CB,$64		; ADATAEX     $CB,$64
		.BYTE	$FF		; ASTOP
_snd0A_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$AF		; ADATA	$AF
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$2C		; ADATA	$2C
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$29		; ADATA	$29
		.BYTE	$28		; ADATA	$28
		.BYTE	$07		; ADATA	$07
		.BYTE	$FF		; ASTOP
_snd0B_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$26		; ADATA	$26
		.BYTE	$28		; ADATA	$28
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$06		; ADATA	$06
		.BYTE	$28		; ADATA	$28
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0C_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$46		; ADATA	$46
		.BYTE	$8D		; ADATA	$8D
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$46		; ADATA	$46
		.BYTE	$AD		; ADATA	$AD
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0D_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$00		; ACMDF0      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$C6,$00		; ADATAEX     $C6,$00
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$F9		; ACMDE3      $F9
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$F9		; ACMDF1      $F9
		.BYTE	$E3,$F9		; ACMDE3      $F9
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0E_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$17		; ACMDF5      $17
		.BYTE	$10		; ADATA	$10
		.BYTE	$11		; ADATA	$11
		.BYTE	$14		; ADATA	$14
		.BYTE	$18		; ADATA	$18
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$F6,$03		; ACMDF6      $03
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$01		; ADATA	$01
		.BYTE	$02		; ADATA	$02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX     $D0,$10
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_52BF8
		.WORD	_asub_52BF8
		.BYTE	$D0,$0C		; ADATAEX     $D0,$0C
		.BYTE	$F5,$0C		; ACMDF5      $0C
		.BYTE	$FA		; AJSR	_asub_52BF8
		.WORD	_asub_52BF8
		.BYTE	$D0,$0A		; ADATAEX     $D0,$0A
		.BYTE	$F5,$09		; ACMDF5      $09
		.BYTE	$FA		; AJSR	_asub_52BF8
		.WORD	_asub_52BF8
		.BYTE	$D0,$08		; ADATAEX     $D0,$08
		.BYTE	$F5,$06		; ACMDF5      $06
		.BYTE	$FA		; AJSR	_asub_52BF8
		.WORD	_asub_52BF8
		.BYTE	$D0,$06		; ADATAEX     $D0,$06
		.BYTE	$F5,$04		; ACMDF5      $04
		.BYTE	$FA		; AJSR	_asub_52BF8
		.WORD	_asub_52BF8
		.BYTE	$FF		; ASTOP
_asub_52BF8:
		.BYTE	$10		; ADATA	$10
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$03		; ADATA	$03
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$FB		; ARET
_snd0E_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$11		; ADATA	$11
		.BYTE	$14		; ADATA	$14
		.BYTE	$18		; ADATA	$18
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$00		; ADATA	$00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX     $D0,$10
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_52C3C
		.WORD	_asub_52C3C
		.BYTE	$D0,$0C		; ADATAEX     $D0,$0C
		.BYTE	$F5,$0E		; ACMDF5      $0E
		.BYTE	$FA		; AJSR	_asub_52C3C
		.WORD	_asub_52C3C
		.BYTE	$D0,$0A		; ADATAEX     $D0,$0A
		.BYTE	$F5,$0A		; ACMDF5      $0A
		.BYTE	$FA		; AJSR	_asub_52C3C
		.WORD	_asub_52C3C
		.BYTE	$D0,$08		; ADATAEX     $D0,$08
		.BYTE	$F5,$05		; ACMDF5      $05
		.BYTE	$FA		; AJSR	_asub_52C3C
		.WORD	_asub_52C3C
		.BYTE	$D0,$06		; ADATAEX     $D0,$06
		.BYTE	$F5,$04		; ACMDF5      $04
		.BYTE	$FA		; AJSR	_asub_52C3C
		.WORD	_asub_52C3C
		.BYTE	$FF		; ASTOP
_asub_52C3C:
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$06		; ADATA	$06
		.BYTE	$01		; ADATA	$01
		.BYTE	$F1,$FB		; ACMDF1      $FB
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FB		; ARET
_snd0F_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$3F		; ACMDF5      $3F
		.BYTE	$C0,$00		; ADATAEX     $C0,$00
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$E3,$FF		; ACMDE3      $FF
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0F_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$28		; ADATA	$28
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$22		; ADATA	$22
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd10_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$13		; ADATA	$13
		.BYTE	$17		; ADATA	$17
		.BYTE	$19		; ADATA	$19
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F5,$22		; ACMDF5      $22
		.BYTE	$12		; ADATA	$12
		.BYTE	$15		; ADATA	$15
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$FF		; ASTOP
_snd11_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$21		; ADATA	$21
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$02		; ADATA	$02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$08		; ADATA	$08
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$FF		; ASTOP
_snd12_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$09		; ADATA	$09
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$08		; ADATA	$08
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd12_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$11		; ADATA	$11
		.BYTE	$13		; ADATA	$13
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$11		; ADATA	$11
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$12		; ADATA	$12
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$13		; ADATA	$13
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$16		; ADATA	$16
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$19		; ADATA	$19
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$17		; ADATA	$17
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FF		; ASTOP
_snd13_A:
		.BYTE	$F5,$20		; ACMDF5      $20
_aloc_52D02:
		.BYTE	$F0,$03		; ACMDF0      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$C7,$00		; ADATAEX     $C7,$00
		.BYTE	$E3,$FC		; ACMDE3      $FC
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$E3,$FD		; ACMDE3      $FD
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$E3,$03		; ACMDE3      $03
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FC,$09		; ALOOP_START $09
		.BYTE	$E3,$FD		; ACMDE3      $FD
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$32		; ACMDF3      $32
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$E3,$05		; ACMDE3      $05
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$01		; ACMDF0      $01
		.BYTE	$CA,$00		; ADATAEX     $CA,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$04		; ACMDF3      $04
		.BYTE	$FC,$12		; ALOOP_START $12
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd13_B:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F8		; AJMP	_aloc_52D02
		.WORD	_aloc_52D02
_snd13_C:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$28		; ADATA	$28
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$A6		; ADATA	$A6
		.BYTE	$FC,$19		; ALOOP_START $19
		.BYTE	$07		; ADATA	$07
		.BYTE	$06		; ADATA	$06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$06		; ADATA	$06
		.BYTE	$87		; ADATA	$87
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$89		; ADATA	$89
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F0,$03		; ACMDF0      $03
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$A8		; ADATA	$A8
		.BYTE	$A9		; ADATA	$A9
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$AA		; ADATA	$AA
		.BYTE	$FF		; ASTOP
_snd14_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$09		; ADATA	$09
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$09		; ADATA	$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$08		; ADATA	$08
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$45		; ADATA	$45
		.BYTE	$F0,$06		; ACMDF0      $06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd15_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$06		; ADATA	$06
		.BYTE	$08		; ADATA	$08
		.BYTE	$FD		; ALOOP_END
		.BYTE	$07		; ADATA	$07
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$09		; ADATA	$09
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$09		; ADATA	$09
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd16_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$07		; ADATA	$07
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$FA		; AJSR	_asub_52DF9
		.WORD	_asub_52DF9
		.BYTE	$FA		; AJSR	_asub_52DFF
		.WORD	_asub_52DFF
		.BYTE	$F1,$FB		; ACMDF1      $FB
		.BYTE	$FA		; AJSR	_asub_52DF9
		.WORD	_asub_52DF9
		.BYTE	$FA		; AJSR	_asub_52DFF
		.WORD	_asub_52DFF
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FA		; AJSR	_asub_52DF9
		.WORD	_asub_52DF9
		.BYTE	$FA		; AJSR	_asub_52DFF
		.WORD	_asub_52DFF
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52DF9
		.WORD	_asub_52DF9
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_52E09
		.WORD	_asub_52E09
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_asub_52DF9:
		.BYTE	$06		; ADATA	$06
		.BYTE	$08		; ADATA	$08
		.BYTE	$07		; ADATA	$07
		.BYTE	$08		; ADATA	$08
		.BYTE	$09		; ADATA	$09
		.BYTE	$FB		; ARET
_asub_52DFF:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_52E09:
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$2C		; ADATA	$2C
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$FB		; ARET
_snd17_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$00		; ACMDF0      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$CE,$00		; ADATAEX     $CE,$00
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$05		; ACMDF3      $05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$04		; ACMDF3      $04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$05		; ACMDF3      $05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd17_B:
		.BYTE	$D0,$04		; ADATAEX     $D0,$04
		.BYTE	$F8		; AJMP	_aloc_52E0E
		.WORD	_snd17_A
_snd18_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$03		; ACMDF0      $03
		.BYTE	$F6,$03		; ACMDF6      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$24		; ACMDF5      $24
		.BYTE	$12		; ADATA	$12
		.BYTE	$13		; ADATA	$13
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$16		; ADATA	$16
		.BYTE	$19		; ADATA	$19
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FF		; ASTOP
_snd18_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$FF		; ASTOP
_snd19_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$2F		; ACMDF5      $2F
		.BYTE	$FA		; AJSR	_asub_52EA6
		.WORD	_asub_52EA6
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$18		; ACMDF5      $18
		.BYTE	$FA		; AJSR	_asub_52EBE
		.WORD	_asub_52EBE
		.BYTE	$F5,$2F		; ACMDF5      $2F
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$FA		; AJSR	_asub_52ED4
		.WORD	_asub_52ED4
		.BYTE	$FF		; ASTOP
_asub_52EA6:
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_52EBE:
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$31		; ADATA	$31
		.BYTE	$14		; ADATA	$14
		.BYTE	$01		; ADATA	$01
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$17		; ADATA	$17
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_52ED4:
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$18		; ADATA	$18
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_snd19_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$FA		; AJSR	_asub_52EA6
		.WORD	_asub_52EA6
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FA		; AJSR	_asub_52EBE
		.WORD	_asub_52EBE
		.BYTE	$F5,$36		; ACMDF5      $36
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$FA		; AJSR	_asub_52ED4
		.WORD	_asub_52ED4
		.BYTE	$FF		; ASTOP
_snd19_C:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$07		; ADATA	$07
		.BYTE	$06		; ADATA	$06
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$02		; ADATA	$02
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$02		; ADATA	$02
		.BYTE	$03		; ADATA	$03
		.BYTE	$01		; ADATA	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$23		; ADATA	$23
		.BYTE	$24		; ADATA	$24
		.BYTE	$25		; ADATA	$25
		.BYTE	$26		; ADATA	$26
		.BYTE	$27		; ADATA	$27
		.BYTE	$28		; ADATA	$28
		.BYTE	$08		; ADATA	$08
		.BYTE	$02		; ADATA	$02
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$CE,$00		; ADATAEX     $CE,$00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$FE		; ACMDE3      $FE
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd1A_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FA		; AJSR	_asub_52F38
		.WORD	_asub_52F38
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_52F4C
		.WORD	_asub_52F4C
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$01		; ACMDF0      $01
		.BYTE	$FA		; AJSR	_asub_52F4C
		.WORD	_asub_52F4C
		.BYTE	$FF		; ASTOP
_asub_52F38:
		.BYTE	$24		; ADATA	$24
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$26		; ADATA	$26
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$08		; ADATA	$08
		.BYTE	$09		; ADATA	$09
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$FB		; ARET
_asub_52F4C:
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$2C		; ADATA	$2C
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_snd1A_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_52F87
		.WORD	_asub_52F87
		.BYTE	$F5,$23		; ACMDF5      $23
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F0,$03		; ACMDF0      $03
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$F5,$19		; ACMDF5      $19
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F0,$01		; ACMDF0      $01
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F5,$13		; ACMDF5      $13
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F5,$12		; ACMDF5      $12
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$FF		; ASTOP
_asub_52F87:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$08		; ADATA	$08
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$06		; ADATA	$06
		.BYTE	$01		; ADATA	$01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$17		; ADATA	$17
		.BYTE	$32		; ADATA	$32
		.BYTE	$FB		; ARET
_asub_52F9B:
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$08		; ADATA	$08
		.BYTE	$06		; ADATA	$06
		.BYTE	$01		; ADATA	$01
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$17		; ADATA	$17
		.BYTE	$12		; ADATA	$12
		.BYTE	$FB		; ARET
_snd1A_C:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F6,$02		; ACMDF6      $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$22		; ACMDF5      $22
		.BYTE	$FA		; AJSR	_asub_52F87
		.WORD	_asub_52F87
		.BYTE	$F5,$23		; ACMDF5      $23
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F5,$24		; ACMDF5      $24
		.BYTE	$F0,$03		; ACMDF0      $03
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F5,$25		; ACMDF5      $25
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F5,$26		; ACMDF5      $26
		.BYTE	$F0,$01		; ACMDF0      $01
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$FA		; AJSR	_asub_52F9B
		.WORD	_asub_52F9B
		.BYTE	$FF		; ASTOP
_snd1A_D:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$18		; ACMDF5      $18
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$08		; ADATA	$08
		.BYTE	$06		; ADATA	$06
		.BYTE	$01		; ADATA	$01
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$17		; ADATA	$17
		.BYTE	$32		; ADATA	$32
		.BYTE	$FF		; ASTOP
_snd1B_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$01		; ACMDF0      $01
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$03		; ADATA	$03
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd1C_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$32		; ACMDF5      $32
		.BYTE	$FA		; AJSR	_asub_53023
		.WORD	_asub_53023
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_53023
		.WORD	_asub_53023
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_53023
		.WORD	_asub_53023
		.BYTE	$FF		; ASTOP
_asub_53023:
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$08		; ADATA	$08
		.BYTE	$D0,$00		; ADATAEX     $D0,$00
		.BYTE	$CA,$00		; ADATAEX     $CA,$00
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$08		; ADATA	$08
		.BYTE	$09		; ADATA	$09
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_snd1D_A:
		.BYTE	$F5,$2E		; ACMDF5      $2E
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$02		; ADATA	$02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$07		; ADATA	$07
		.BYTE	$08		; ADATA	$08
		.BYTE	$05		; ADATA	$05
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_53030
		.WORD	_snd1D_A
_snd1E_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F6,$00		; ACMDF6      $00
_aloc_53048:
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$20		; ADATA	$20
		.BYTE	$00		; ADATA	$00
		.BYTE	$23		; ADATA	$23
		.BYTE	$03		; ADATA	$03
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$27		; ADATA	$27
		.BYTE	$27		; ADATA	$27
		.BYTE	$29		; ADATA	$29
		.BYTE	$29		; ADATA	$29
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$FF		; ASTOP
_snd1E_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F6,$23		; ACMDF6      $23
		.BYTE	$F8		; AJMP	_aloc_53048
		.WORD	_aloc_53048
_snd1F_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_53092
		.WORD	_asub_53092
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_53092
		.WORD	_asub_53092
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_53092
		.WORD	_asub_53092
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_53092
		.WORD	_asub_53092
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FA		; AJSR	_asub_53092
		.WORD	_asub_53092
		.BYTE	$FF		; ASTOP
_asub_53092:
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$4E		; ADATA	$4E
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_snd20_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$09		; ADATA	$09
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F8		; AJMP	_aloc_53099
		.WORD	_snd20_A
_snd21_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$09		; ADATA	$09
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_530AB
		.WORD	_snd21_A
_snd22_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$2B		; ACMDF5      $2B
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FA		; AJSR	_asub_530DE
		.WORD	_asub_530DE
		.BYTE	$F5,$26		; ACMDF5      $26
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FA		; AJSR	_asub_530EC
		.WORD	_asub_530EC
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_530EE
		.WORD	_asub_530EE
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_asub_530DE:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$0A		; ADATA	$0A
_asub_530EC:
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
_asub_530EE:
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$08		; ADATA	$08
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$03		; ADATA	$03
		.BYTE	$06		; ADATA	$06
		.BYTE	$01		; ADATA	$01
		.BYTE	$FB		; ARET
_snd23_A:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$01		; ACMDF6      $01
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$E2,$0F,$00	; ACMDE2      $0F,$00
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$F0,$03		; ACMDF0      $03
		.BYTE	$27		; ADATA	$27
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$64		; ADATA	$64
		.BYTE	$F0,$01		; ACMDF0      $01
		.BYTE	$22		; ADATA	$22
		.BYTE	$FF		; ASTOP
_snd23_B:
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$22		; ACMDF5      $22
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$14		; ADATA	$14
		.BYTE	$16		; ADATA	$16
		.BYTE	$12		; ADATA	$12
		.BYTE	$17		; ADATA	$17
		.BYTE	$FF		; ASTOP
_sample00:
		.BYTE	$80		; ADATA	$80
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
_sample02:
		.BYTE	$81		; ADATA	$81
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
_sample04:
		.BYTE	$82		; ADATA	$82
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
_sample06:
		.BYTE	$83		; ADATA	$83
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FF		; ASTOP
_sample4F:
		.BYTE	$40		; ADATA	$40
		.BYTE	$FF		; ASTOP
_sample35:
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$41		; ADATA	$41
		.BYTE	$04		; ADATA	$04
		.BYTE	$40		; ADATA	$40
		.BYTE	$FF		; ASTOP
_sample29:
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
_sample08:
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$03		; ADATA	$03
		.BYTE	$FC,$0C		; ALOOP_START $0C
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_aloc_53148:
		.BYTE	$57		; ADATA	$57
		.BYTE	$56		; ADATA	$56
		.BYTE	$45		; ADATA	$45
		.BYTE	$03		; ADATA	$03
		.BYTE	$44		; ADATA	$44
		.BYTE	$0F		; ADATA	$0F
_aloc_5314E:
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_5314E
		.WORD	_aloc_5314E
_sample0C:
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$81		; ADATA	$81
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample3D:
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$43		; ADATA	$43
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$20		; ADATA	$20
		.BYTE	$FF		; ASTOP
_sample1A:
		.BYTE	$81		; ADATA	$81
		.BYTE	$58		; ADATA	$58
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample12:
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$82		; ADATA	$82
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample16:
		.BYTE	$82		; ADATA	$82
		.BYTE	$58		; ADATA	$58
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample_unref:
		.BYTE	$80		; ADATA	$80
		.BYTE	$57		; ADATA	$57
		.BYTE	$82		; ADATA	$82
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_53185
		.WORD	_aloc_53185
_sample18:
		.BYTE	$81		; ADATA	$81
		.BYTE	$57		; ADATA	$57
		.BYTE	$80		; ADATA	$80
		.BYTE	$04		; ADATA	$04
_aloc_53185:
		.BYTE	$40		; ADATA	$40
_aloc_53186:
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$62		; ADATA	$62
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_53186
		.WORD	_aloc_53186
_sample1E:
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$83		; ADATA	$83
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample22:
		.BYTE	$83		; ADATA	$83
		.BYTE	$58		; ADATA	$58
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample_unref_0:
		.BYTE	$44		; ADATA	$44
_aloc_5319C:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_5319C
		.WORD	_aloc_5319C
_sample24:
		.BYTE	$FA		; AJSR	_asub_531AD
		.WORD	_asub_531AD
		.BYTE	$F8		; AJMP	_aloc_531B7
		.WORD	_aloc_531B7
_asub_531AD:
		.BYTE	$80		; ADATA	$80
		.BYTE	$43		; ADATA	$43
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$72		; ADATA	$72
		.BYTE	$FD		; ALOOP_END
		.BYTE	$91		; ADATA	$91
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$83		; ADATA	$83
		.BYTE	$FB		; ARET
_aloc_531B7:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$7F		; ADATA	$7F
_aloc_531BD:
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_531BD
		.WORD	_aloc_531BD
_sample26:
		.BYTE	$49		; ADATA	$49
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$01		; ADATA	$01
		.BYTE	$6B		; ADATA	$6B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample28:
		.BYTE	$49		; ADATA	$49
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample2C:
		.BYTE	$82		; ADATA	$82
		.BYTE	$58		; ADATA	$58
		.BYTE	$20		; ADATA	$20
		.BYTE	$83		; ADATA	$83
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample30:
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$82		; ADATA	$82
		.BYTE	$F8		; AJMP	_aloc_53148
		.WORD	_aloc_53148
_sample2F:
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
_sample55:
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$43		; ADATA	$43
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$04		; ADATA	$04
		.BYTE	$61		; ADATA	$61
		.BYTE	$04		; ADATA	$04
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$22		; ADATA	$22
		.BYTE	$FF		; ASTOP
_sample36:
		.BYTE	$4B		; ADATA	$4B
		.BYTE	$92		; ADATA	$92
		.BYTE	$48		; ADATA	$48
		.BYTE	$83		; ADATA	$83
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample34:
		.BYTE	$83		; ADATA	$83
		.BYTE	$46		; ADATA	$46
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$71		; ADATA	$71
		.BYTE	$80		; ADATA	$80
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
_aloc_53209:
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$41		; ADATA	$41
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F8		; AJMP	_aloc_53209
		.WORD	_aloc_53209
_sample38:
		.BYTE	$81		; ADATA	$81
		.BYTE	$45		; ADATA	$45
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$72		; ADATA	$72
		.BYTE	$FD		; ALOOP_END
		.BYTE	$82		; ADATA	$82
_aloc_53217:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$23		; ADATA	$23
		.BYTE	$02		; ADATA	$02
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_53217
		.WORD	_aloc_53217
_sample3A:
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$83		; ADATA	$83
		.BYTE	$02		; ADATA	$02
		.BYTE	$81		; ADATA	$81
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FD		; ALOOP_END
_aloc_5322E:
		.BYTE	$83		; ADATA	$83
		.BYTE	$02		; ADATA	$02
		.BYTE	$72		; ADATA	$72
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$F8		; AJMP	_aloc_5322E
		.WORD	_aloc_5322E
_sample41:
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
_sample3C:
		.BYTE	$80		; ADATA	$80
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$02		; ADATA	$02
		.BYTE	$81		; ADATA	$81
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$82		; ADATA	$82
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
_sample3E:
		.BYTE	$80		; ADATA	$80
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$02		; ADATA	$02
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$83		; ADATA	$83
		.BYTE	$02		; ADATA	$02
_aloc_5324E:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$03		; ADATA	$03
		.BYTE	$F8		; AJMP	_aloc_5324E
		.WORD	_aloc_5324E
_sample40:
		.BYTE	$57		; ADATA	$57
		.BYTE	$31		; ADATA	$31
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$6F		; ADATA	$6F
_aloc_53261:
		.BYTE	$21		; ADATA	$21
		.BYTE	$05		; ADATA	$05
		.BYTE	$F8		; AJMP	_aloc_53261
		.WORD	_aloc_53261
_sample42:
		.BYTE	$83		; ADATA	$83
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$81		; ADATA	$81
		.BYTE	$59		; ADATA	$59
		.BYTE	$80		; ADATA	$80
		.BYTE	$47		; ADATA	$47
		.BYTE	$03		; ADATA	$03
_aloc_5326D:
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$03		; ADATA	$03
		.BYTE	$F8		; AJMP	_aloc_5326D
		.WORD	_aloc_5326D
_sample44:
		.BYTE	$82		; ADATA	$82
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$80		; ADATA	$80
		.BYTE	$58		; ADATA	$58
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$80		; ADATA	$80
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FD		; ALOOP_END
_aloc_5327E:
		.BYTE	$46		; ADATA	$46
		.BYTE	$03		; ADATA	$03
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$46		; ADATA	$46
		.BYTE	$03		; ADATA	$03
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_5327E
		.WORD	_aloc_5327E
		.BYTE	$FF		; ASTOP
_sample46:
		.BYTE	$83		; ADATA	$83
		.BYTE	$22		; ADATA	$22
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$81		; ADATA	$81
		.BYTE	$59		; ADATA	$59
		.BYTE	$80		; ADATA	$80
		.BYTE	$47		; ADATA	$47
		.BYTE	$03		; ADATA	$03
_aloc_53292:
		.BYTE	$21		; ADATA	$21
		.BYTE	$03		; ADATA	$03
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$03		; ADATA	$03
		.BYTE	$F8		; AJMP	_aloc_53292
		.WORD	_aloc_53292
_sample5B:
		.BYTE	$53		; ADATA	$53
		.BYTE	$55		; ADATA	$55
		.BYTE	$53		; ADATA	$53
		.BYTE	$42		; ADATA	$42
		.BYTE	$02		; ADATA	$02
		.BYTE	$40		; ADATA	$40
		.BYTE	$FF		; ASTOP
_sample48:
		.BYTE	$23		; ADATA	$23
		.BYTE	$F8		; AJMP	_sample44
		.WORD	_sample44
		.BYTE	$FF		; ASTOP
_sample4A:
		.BYTE	$82		; ADATA	$82
		.BYTE	$59		; ADATA	$59
		.BYTE	$81		; ADATA	$81
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$83		; ADATA	$83
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$21		; ADATA	$21
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$5A		; ADATA	$5A
_aloc_532AF:
		.BYTE	$49		; ADATA	$49
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_532AF
		.WORD	_aloc_532AF
_sample4C:
		.BYTE	$80		; ADATA	$80
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$81		; ADATA	$81
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$82		; ADATA	$82
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
_aloc_532C1:
		.BYTE	$55		; ADATA	$55
		.BYTE	$F8		; AJMP	_aloc_532C1
		.WORD	_aloc_532C1
_sample4B:
		.BYTE	$42		; ADATA	$42
		.BYTE	$03		; ADATA	$03
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_sample4B
		.WORD	_sample4B
		.BYTE	$FF		; ASTOP
_sample4E:
		.BYTE	$83		; ADATA	$83
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$02		; ADATA	$02
		.BYTE	$82		; ADATA	$82
		.BYTE	$4B		; ADATA	$4B
		.BYTE	$04		; ADATA	$04
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$04		; ADATA	$04
		.BYTE	$49		; ADATA	$49
		.BYTE	$06		; ADATA	$06
_aloc_532D7:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_532D7
		.WORD	_aloc_532D7
_sample50:
		.BYTE	$82		; ADATA	$82
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$83		; ADATA	$83
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$81		; ADATA	$81
_aloc_532EA:
		.BYTE	$31		; ADATA	$31
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$31		; ADATA	$31
		.BYTE	$F8		; AJMP	_aloc_532EA
		.WORD	_aloc_532EA
_sample52:
		.BYTE	$80		; ADATA	$80
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$81		; ADATA	$81
		.BYTE	$47		; ADATA	$47
		.BYTE	$02		; ADATA	$02
		.BYTE	$80		; ADATA	$80
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample54:
		.BYTE	$83		; ADATA	$83
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$80		; ADATA	$80
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$02		; ADATA	$02
		.BYTE	$82		; ADATA	$82
		.BYTE	$49		; ADATA	$49
_aloc_53305:
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_53305
		.WORD	_aloc_53305
		.BYTE	$FF		; ASTOP
_sample56:
		.BYTE	$83		; ADATA	$83
		.BYTE	$47		; ADATA	$47
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$61		; ADATA	$61
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
_aloc_53318:
		.BYTE	$22		; ADATA	$22
		.BYTE	$02		; ADATA	$02
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$02		; ADATA	$02
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$02		; ADATA	$02
		.BYTE	$F8		; AJMP	_aloc_53318
		.WORD	_aloc_53318
		.BYTE	$FF		; ASTOP
_sample59:
		.BYTE	$FC,$0D		; ALOOP_START $0D
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$02		; ADATA	$02
		.BYTE	$71		; ADATA	$71
		.BYTE	$71		; ADATA	$71
		.BYTE	$62		; ADATA	$62
		.BYTE	$02		; ADATA	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample58:
		.BYTE	$82		; ADATA	$82
		.BYTE	$4E		; ADATA	$4E
		.BYTE	$03		; ADATA	$03
		.BYTE	$4B		; ADATA	$4B
		.BYTE	$FC,$0B		; ALOOP_START $0B
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample5A:
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$58		; ADATA	$58
		.BYTE	$5C		; ADATA	$5C
		.BYTE	$5A		; ADATA	$5A
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_samples_lib:
		.WORD	_sample00
		.WORD	_sample4F
		.WORD	_sample02
		.WORD	_sample4F
		.WORD	_sample04
		.WORD	_sample4F
		.WORD	_sample06
		.WORD	_sample4F
		.WORD	_sample08
		.WORD	_sample4F
		.WORD	_sample0C
		.WORD	_sample29
		.WORD	_sample0C
		.WORD	_sample3D
		.WORD	_sample1A
		.WORD	_sample29
		.WORD	_sample12
		.WORD	_sample29
		.WORD	_sample12
		.WORD	_sample3D
		.WORD	_sample16
		.WORD	_sample29
		.WORD	_sample16
		.WORD	_sample3D
		.WORD	_sample18
		.WORD	_sample29
		.WORD	_sample1A
		.WORD	_sample3D
		.WORD	_sample1E
		.WORD	_sample29
		.WORD	_sample1E
		.WORD	_sample3D
		.WORD	_sample22
		.WORD	_sample29
		.WORD	_sample22
		.WORD	_sample3D
		.WORD	_sample24
		.WORD	_sample29
		.WORD	_sample26
		.WORD	_sample29
		.WORD	_sample28
		.WORD	_sample29
		.WORD	_sample2C
		.WORD	_sample2F
		.WORD	_sample2C
		.WORD	_sample55
		.WORD	_sample30
		.WORD	_sample2F
		.WORD	_sample30
		.WORD	_sample55
		.WORD	_sample36
		.WORD	_sample4F
		.WORD	_sample34
		.WORD	_sample35
		.WORD	_sample36
		.WORD	_sample4F
		.WORD	_sample38
		.WORD	_sample3D
		.WORD	_sample3A
		.WORD	_sample41
		.WORD	_sample3C
		.WORD	_sample3D
		.WORD	_sample3E
		.WORD	_sample55
		.WORD	_sample40
		.WORD	_sample41
		.WORD	_sample42
		.WORD	_sample4F
		.WORD	_sample44
		.WORD	_sample5B
		.WORD	_sample46
		.WORD	_sample4F
		.WORD	_sample48
		.WORD	_sample5B
		.WORD	_sample4A
		.WORD	_sample4B
		.WORD	_sample4C
		.WORD	_sample4F
		.WORD	_sample4E
		.WORD	_sample4F
		.WORD	_sample50
		.WORD	_sample5B
		.WORD	_sample52
		.WORD	_sample5B
		.WORD	_sample54
		.WORD	_sample55
		.WORD	_sample56
		.WORD	_sample59
		.WORD	_sample58
		.WORD	_sample59
		.WORD	_sample5A
		.WORD	_sample5B
byte_533FD:
		.BYTE	$01,$02,$03,$04,$05,$06,$07,$0E,$15,$1C,$23,$38,$08,$10,$18,$20
		.BYTE	$80,$40,$08,$10,$18,$20,$28,$30,$06,$0C,$12,$18,$1E,$24,$05,$0A
		.BYTE	$0F,$14,$19,$1E,$09,$12,$1B,$24,$8A,$06,$11,$0C,$05,$03,$88,$1D
; REGION, the additional lengths table for PAL version of the music data
;		.BYTE	$01,$04,$08,$09,$0C,$0D,$06,$07,$14,$1A,$1B,$35,$04,$08,$0C,$0D
;		.BYTE	$19,$09,$05,$06,$0B,$0C,$16,$17,$06,$0C,$12,$18,$1E,$30,$04,$05
;		.BYTE	$08,$09,$11,$19,$0E,$0A,$04,$02,$70,$18,$04,$05,$08,$0C,$0D,$19
;
_music_lib:
		.WORD	_mus0
		.WORD	_mus1
		.WORD	_mus2
		.WORD	_mus3
		.WORD	_mus4
		.WORD	_mus5
		.WORD	_mus6
		.WORD	_mus7
		.WORD	_mus8
		.WORD	_mus9
		.WORD	_musA
		.WORD	_musB
		.WORD	_musC
; REGION, there is an unused unreferenced headerless music track in the EU version
; similar unused space in the US/JP revisions filled with copy of samples data
; unused track never appear in any data tables and cannot be played without proper
; header.
;		.WORD	_musD
; -
_snd_lib:
		.WORD	_snd00
		.WORD	_snd01
		.WORD	_snd02
		.WORD	_snd03
		.WORD	_snd04
		.WORD	_snd05
		.WORD	_snd06
		.WORD	_snd07
		.WORD	_snd08
		.WORD	_snd09
		.WORD	_snd0A
		.WORD	_snd0B
		.WORD	_snd0C
		.WORD	_snd0D
		.WORD	_snd0E
		.WORD	_snd0F
		.WORD	_snd10
		.WORD	_snd11
		.WORD	_snd12
		.WORD	_snd13
		.WORD	_snd14
		.WORD	_snd15
		.WORD	_snd16
		.WORD	_snd17
		.WORD	_snd18
		.WORD	_snd19
		.WORD	_snd1A
		.WORD	_snd1B
		.WORD	_snd1C
		.WORD	_snd1D
		.WORD	_snd1E
		.WORD	_snd1F
		.WORD	_snd20
		.WORD	_snd21
		.WORD	_snd22
		.WORD	_snd23
byte_5348F:
		.BYTE	$02,$02,$0A,$0F,$03,$0A,$0A,$0A,$02,$0A,$0A,$02,$02,$02,$03,$0A
		.BYTE	$02,$02,$0A,$0B,$08,$08,$08,$03,$0A,$0B,$0F,$08,$02,$02,$03,$08
		.BYTE	$02,$02,$02,$0C
byte_534B3:
		.BYTE	$3C,$32,$32,$00,$0A,$28,$32,$32,$32,$32,$32,$32,$32,$28,$1E,$32
		.BYTE	$3C,$3C,$32,$28,$3C,$32,$28,$28,$3C,$1E,$0B,$3C,$32,$32,$00,$46
		.BYTE	$32,$32,$28,$32

		BANK_END 6,$C000
