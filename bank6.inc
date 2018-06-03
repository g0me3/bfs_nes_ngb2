
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

; REGION, unused data for missing music track from the EU version
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
;_musD:
;		INCLUDE	"..\mus\musD_ntsc.inc"
;-

_musC:
		INCLUDE	"..\mus\musC_ntsc.inc"
_mus1:
		INCLUDE	"..\mus\mus1_ntsc.inc"
_mus2:
		INCLUDE	"..\mus\mus2_ntsc.inc"
_mus3:
		INCLUDE	"..\mus\mus3_ntsc.inc"

; NOTE: this data is an exact copy of full library of _sampleXX codes.
; it has no pointer table associated, but all offsets are fixed to
; this particular location, so somehow they have his copy linked to
; the sources as well. definitely this is not just rtash from uninitialized
; RAM...
;
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
		.BYTE	$FF	; ASTOP

_mus4:
		INCLUDE	"..\mus\mus4_ntsc.inc"
_mus5:
		INCLUDE	"..\mus\mus5_ntsc.inc"
_mus0:
		INCLUDE	"..\mus\mus0_ntsc.inc"
_mus6:
		INCLUDE	"..\mus\mus6_ntsc.inc"
_mus7:
		INCLUDE	"..\mus\mus7_ntsc.inc"
_mus8:
		INCLUDE	"..\mus\mus8_ntsc.inc"
_mus9:
		INCLUDE	"..\mus\mus9_ntsc.inc"
_musA:
		INCLUDE	"..\mus\musA_ntsc.inc"
_musB:
		INCLUDE	"..\mus\musB_ntsc.inc"

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
; REGION, re-added an unused missing music track here in future
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
