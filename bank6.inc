
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
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18,$0F,$1F,$0F,$00,$0F ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17,$0E,$1D,$0E,$1E,$0E ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_musC_A
		.WORD	_musC_A
_musC_B:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18,$05,$1F,$05,$00,$05 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17,$04,$1D,$04,$1E,$04 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_musC_B
		.WORD	_musC_B
_musC_C:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18,$0A,$1F,$0A,$00,$0A ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$16,$09,$1D,$09,$1E,$09 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_musC_C
		.WORD	_musC_C
_musC_D:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$9F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E,$1C,$5D	; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1C,$5C,$5E,$1D,$3C ; ADATA
		.BYTE	$F8		; AJMP	_musC_D
		.WORD	_musC_D
_musC_E:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$20		; ACMDF6	$20
byte_507CB:
		.BYTE	$0D		; ADATA
byte_507CC:
		.BYTE	$8D,$24		; ADATA
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$08,$45		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$0D		; ADATA
		.BYTE	$CD,$1B		; ADATAEX
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$C9,$08		; ADATAEX
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44,$07,$48	; ADATA
		.BYTE	$F8		; AJMP	0x000507CC
		.WORD	byte_507CC
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
		.BYTE	$F2,$07		; ACMDF2	$07
		.BYTE	$70		; ADATA
byte_507FA:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$BE		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$5F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1E		; ADATA
		.BYTE	$F8		; AJMP	byte_507FA
		.WORD	byte_507FA
_mus1_B:
		.BYTE	$F2,$07		; ACMDF2	$07
		.BYTE	$70		; ADATA
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$F5,$06		; ACMDF5	$06
		.BYTE	$F4,$00		; ACMDF4	$00
byte_50829:
		.BYTE	$00,$23,$40,$25,$40,$27,$40,$25,$40,$23,$40,$25,$40,$23,$5E,$00 ;	ADATA
		.BYTE	$23,$40,$26,$40,$27,$40,$2A,$40,$27,$40,$25,$40,$23,$5E
		.BYTE	$F8		; AJMP	byte_50829
		.WORD	byte_50829
_mus1_C:
		.BYTE	$F2,$07		; ACMDF2	$07
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$70		; ADATA
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$EB		; ACMDF4	$EB
		.BYTE	$F5,$12		; ACMDF5	$12
		.BYTE	$F8		; AJMP	byte_50829
		.WORD	byte_50829
_mus1_D:
		.BYTE	$F2,$07		; ACMDF2	$07
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F6,$2B		; ACMDF6	$2B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$81,$80		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$81,$80		; ADATA
		.BYTE	$F8		; AJMP	_mus1_D
		.WORD	_mus1_D
_mus1_E:
		.BYTE	$F2,$07		; ACMDF2	$07
		.BYTE	$70		; ADATA
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
byte_50872:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$45		; ADATA
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$27		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$44		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$24,$45		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$27		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$03		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$44		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04		; ADATA
		.BYTE	$F8		; AJMP	byte_50872
		.WORD	byte_50872
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
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$9F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$9F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7F,$3F,$3F,$1E,$5D,$7E ;	ADATA
		.BYTE	$FF		; ASTOP
_mus2_B:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$2D		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$05,$25		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$0D		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$05		; ADATA
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$23		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$4D		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$05		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24,$24		; ADATA
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$06,$47		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$63		; ADATA
		.BYTE	$FF		; ASTOP
_mus2_C:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$11		; ACMDF5	$11
byte_508FF:
		.BYTE	$FA		; AJSR	byte_50909
		.WORD	byte_50909
		.BYTE	$FA		; AJSR	byte_50912
		.WORD	byte_50912
		.BYTE	$FA		; AJSR	byte_5091C
		.WORD	byte_5091C
		.BYTE	$FF		; ASTOP
byte_50909:
		.BYTE	$31,$1D,$30,$18,$3B,$1D,$20,$1B ;	ADATA
		.BYTE	$FB		; ARET
byte_50912:
		.BYTE	$30,$1D,$3C,$1D,$39,$1D,$38,$1D,$30 ; ADATA
		.BYTE	$FB		; ARET
byte_5091C:
		.BYTE	$F5,$11		; ACMDF5	$11
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$D7,$3C		; ADATAEX
		.BYTE	$FB		; ARET
_mus2_D:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$29		; ACMDF5	$29
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F8		; AJMP	byte_508FF
		.WORD	byte_508FF
		.BYTE	$FF		; ASTOP
_mus2_E:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$F5,$18		; ACMDF5	$18
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$FA		; AJSR	byte_50909
		.WORD	byte_50909
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F5,$35		; ACMDF5	$35
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$30		; ADATA
		.BYTE	$FA		; AJSR	byte_50954
		.WORD	byte_50954
		.BYTE	$F6,$2B		; ACMDF6	$2B
		.BYTE	$F5,$11		; ACMDF5	$11
		.BYTE	$D0,$0F		; ADATAEX
		.BYTE	$D7,$3C		; ADATAEX
		.BYTE	$B0		; ADATA
		.BYTE	$FF		; ASTOP
byte_50954:
		.BYTE	$09,$08,$1D,$09,$05,$1D,$09,$04,$1D,$09 ;	ADATA
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
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$9E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1E,$1E,$1D	; ADATA
		.BYTE	$CF,$0D		; ADATAEX
		.BYTE	$DE,$0F		; ADATAEX
		.BYTE	$DE,$0B		; ADATAEX
		.BYTE	$DD,$0B		; ADATAEX
		.BYTE	$BD		; ADATA
		.BYTE	$FF		; ASTOP
_mus3_B:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$30,$02,$21,$1D,$3B,$1C,$3D,$17,$38,$02,$21,$1D ;	ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C3,$02		; ADATAEX
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$C4,$0A		; ADATAEX
		.BYTE	$07,$3F,$1B	; ADATA
		.BYTE	$D0,$0D		; ADATAEX
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$DD,$0F		; ADATAEX
		.BYTE	$DD,$0B		; ADATAEX
		.BYTE	$DD,$0B		; ADATAEX
		.BYTE	$DC,$03		; ADATAEX
		.BYTE	$DD,$00		; ADATAEX
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$0F		; ACMDF3	$0F
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$04		; ACMDE3	$04
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_mus3_C:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$31		; ADATA
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$1D,$3B,$18,$36,$15,$38,$11,$33,$1D,$3B,$18,$3D,$1F,$3B,$13 ; ADATA
		.BYTE	$D0,$0D		; ADATAEX
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$DA,$0F		; ADATAEX
		.BYTE	$DA,$0B		; ADATAEX
		.BYTE	$DA,$0B		; ADATAEX
		.BYTE	$D9,$03		; ADATAEX
		.BYTE	$DA,$00		; ADATAEX
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$0F		; ACMDF3	$0F
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$04		; ACMDE3	$04
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_mus3_D:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$5D,$29,$5D,$09,$29,$08,$47,$3B,$47,$1B,$27,$1B ;	ADATA
		.BYTE	$D0,$0D		; ADATAEX
		.BYTE	$C2,$0F		; ADATAEX
		.BYTE	$C2,$0B		; ADATAEX
		.BYTE	$C2,$0B		; ADATAEX
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$42		; ADATA
		.BYTE	$FF		; ASTOP
_mus3_E:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$05,$05	; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$04,$05,$05	; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$06,$07		; ADATA
		.BYTE	$CF,$0D		; ADATAEX
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$C4,$0F		; ADATAEX
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$C7,$0B		; ADATAEX
		.BYTE	$C8,$0B		; ADATAEX
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$64		; ADATA
		.BYTE	$FF		; ASTOP
_samples_data_copy_relocated_unused:
		.BYTE	$80,$4F,$FF,$81,$4F,$FF,$82,$4F,$FF,$83,$4F,$FF,$40,$FF,$42,$02 ; ADATA
		.BYTE	$41,$04,$40,$FF,$42,$FF,$4C,$03,$FC,$0C,$6F,$03,$FD,$FF,$57,$56
		.BYTE	$45,$03,$44,$0F,$6F,$04,$61,$04,$F8,$97,$8A,$80,$58,$81,$F8,$91
		.BYTE	$8A,$44,$04,$43,$FC,$05,$6F,$04,$61,$04,$6F,$FD,$20,$FF,$81,$58
		.BYTE	$80,$F8,$91,$8A,$80,$58,$82,$F8,$91,$8A,$82,$58,$80,$F8,$91,$8A
		.BYTE	$80,$57,$82,$04,$F8,$CE,$8A,$81,$57,$80,$04,$40,$2E,$62,$04,$22
		.BYTE	$6E,$04,$F8,$CF,$8A,$80,$58,$83,$F8,$91,$8A,$83,$58,$80,$F8,$91
		.BYTE	$8A,$44,$2F,$02,$21,$02,$21,$02,$2F,$02,$F8,$E5,$8A,$FA,$F6,$8A
		.BYTE	$F8,$00,$8B,$80,$43,$FC,$03,$72,$FD,$91,$6E,$83,$FB,$FC,$02,$6E
		.BYTE	$02,$FD,$7F,$61,$04,$6F,$04,$F8,$06,$8B,$49,$FC,$03,$01,$6B,$FD
		.BYTE	$FF,$49,$FC,$02,$7E,$FD,$FC,$05,$6F,$02,$FD,$FF,$82,$58,$20,$83
		.BYTE	$F8,$91,$8A,$80,$58,$82,$F8,$91,$8A,$2E,$42,$FF,$44,$04,$43,$FC
		.BYTE	$0A,$6F,$04,$61,$04,$6F,$FD,$22,$FF,$4B,$92,$48,$83,$FC,$08,$6F
		.BYTE	$02,$FD,$FF,$83,$46,$FC,$02,$71,$80,$FD,$FC,$02,$6E,$03,$FD,$42
		.BYTE	$02,$41,$0C,$F8,$52,$8B,$81,$45,$FC,$02,$72,$FD,$82,$22,$02,$23
		.BYTE	$02,$22,$02,$2E,$02,$2D,$02,$2E,$02,$F8,$60,$8B,$4A,$83,$02,$81
		.BYTE	$FC,$03,$7E,$FD,$83,$02,$72,$7E,$F8,$77,$8B,$FC,$05,$6F,$03,$FD
		.BYTE	$80,$4D,$02,$81,$4A,$FC,$02,$7D,$FD,$82,$FC,$02,$7F,$FD,$80,$4A
		.BYTE	$02,$6E,$83,$02,$22,$02,$21,$03,$2E,$02,$2F,$03,$F8,$97,$8B,$57
		.BYTE	$31,$6F,$21,$02,$21,$03,$6F,$21,$05,$F8,$AA,$8B,$83,$5A,$81,$59
		.BYTE	$80,$47,$03,$21,$03,$2F,$03,$F8,$B6,$8B,$82,$5A,$80,$58,$FC,$02
		.BYTE	$7E,$80,$7E,$FD,$46,$03,$42,$02,$46,$03,$42,$02,$F8,$C7,$8B,$FF
		.BYTE	$83,$22,$5A,$81,$59,$80,$47,$03,$21,$03,$2F,$03,$F8,$DB,$8B,$53
		.BYTE	$55,$53,$42,$02,$40,$FF,$23,$F8,$BD,$8B,$FF,$82,$59,$81,$5A,$83
		.BYTE	$5B,$21,$5D,$2F,$5A,$49,$21,$02,$2F,$02,$F8,$F8,$8B,$80,$5D,$81
		.BYTE	$5D,$82,$5A,$FC,$05,$7F,$FD,$55,$F8,$0A,$8C,$42,$03,$44,$04,$F8
		.BYTE	$0E,$8C,$FF,$83,$4D,$02,$82,$4B,$04,$4A,$04,$49,$06,$22,$02,$2E
		.BYTE	$02,$2E,$02,$22,$02,$F8,$20,$8C,$82,$5D,$83,$5B,$7E,$6F,$02,$81
		.BYTE	$31,$3F,$3F,$31,$F8,$33,$8C,$80,$5E,$81,$47,$02,$80,$5B,$5A,$FC
		.BYTE	$0A,$7F,$FD,$FF,$83,$5F,$80,$4C,$02,$82,$49,$21,$02,$2F,$02,$2F
		.BYTE	$02,$21,$02,$F8,$4E,$8C,$FF,$83,$47,$FC,$06,$61,$02,$FD,$22,$02
		.BYTE	$2F,$02,$2E,$02,$21,$02,$F8,$61,$8C,$FF,$FC,$0D,$7E,$7F,$7F,$6F
		.BYTE	$02,$71,$71,$62,$02,$FD,$FF,$82,$4E,$03,$4B,$FC,$0B,$6F,$03,$FD
		.BYTE	$FF,$5F,$5E,$58,$5C,$5A,$FC,$0A,$7F,$FD,$FF
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
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0F		; ACMDF0	$0F
byte_50CA2:
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$F5,$10		; ACMDF5	$10
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00050CCB
		.WORD	byte_50CCB
		.BYTE	$FA		; AJSR	0x00050CD4
		.WORD	byte_50CD4
		.BYTE	$FA		; AJSR	0x00050CCB
		.WORD	byte_50CCB
		.BYTE	$FA		; AJSR	0x00050CD9
		.WORD	byte_50CD9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$11		; ACMDF5	$11
		.BYTE	$FA		; AJSR	0x00050CCB
		.WORD	byte_50CCB
		.BYTE	$FA		; AJSR	0x00050CD4
		.WORD	byte_50CD4
		.BYTE	$FA		; AJSR	0x00050CCB
		.WORD	byte_50CCB
		.BYTE	$FA		; AJSR	0x00050CD9
		.WORD	byte_50CD9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x00050CA2
		.WORD	byte_50CA2
byte_50CCB:
		.BYTE	$34,$19,$3B,$1E,$30,$19,$3B,$1E ;	ADATA
		.BYTE	$FB		; ARET
byte_50CD4:
		.BYTE	$20,$19,$3B,$1E	; ADATA
		.BYTE	$FB		; ARET
byte_50CD9:
		.BYTE	$22,$1B,$20,$1E	; ADATA
		.BYTE	$FB		; ARET
_mus4_B:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1C		; ACMDF5	$1C
		.BYTE	$FA		; AJSR	0x00050D0B
		.WORD	byte_50D0B
		.BYTE	$F5,$28		; ACMDF5	$28
		.BYTE	$FA		; AJSR	0x00050D40
		.WORD	byte_50D40
		.BYTE	$F5,$1C		; ACMDF5	$1C
		.BYTE	$FA		; AJSR	0x00050D4B
		.WORD	byte_50D4B
		.BYTE	$F5,$1D		; ACMDF5	$1D
		.BYTE	$FA		; AJSR	0x00050D0B
		.WORD	byte_50D0B
		.BYTE	$F5,$29		; ACMDF5	$29
		.BYTE	$FA		; AJSR	0x00050D40
		.WORD	byte_50D40
		.BYTE	$F5,$1D		; ACMDF5	$1D
		.BYTE	$FA		; AJSR	0x00050D4B
		.WORD	byte_50D4B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$28		; ACMDF5	$28
		.BYTE	$FA		; AJSR	0x00050D61
		.WORD	byte_50D61
		.BYTE	$F8		; AJMP	_mus4_B
		.WORD	_mus4_B
byte_50D0B:
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$4C,$4A		; ADATA
		.BYTE	$F6,$25		; ACMDF6	$25
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$0A,$07		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$29,$0A,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$0A,$30		; ADATA
		.BYTE	$F6,$0B		; ACMDF6	$0B
		.BYTE	$00,$3E,$19,$38,$16 ; ADATA
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$4C,$4A,$50	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$29,$0A,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$0A		; ADATA
		.BYTE	$FB		; ARET
byte_50D40:
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$CA,$03		; ADATAEX
		.BYTE	$CB,$04		; ADATAEX
		.BYTE	$CC,$08		; ADATAEX
		.BYTE	$FB		; ARET
byte_50D4B:
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$4C,$4A,$50	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$29,$0A,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$09		; ADATA
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$4C,$4A,$4C,$4A	; ADATA
		.BYTE	$FB		; ARET
byte_50D61:
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C0,$5A		; ADATAEX
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$DE,$3C		; ADATAEX
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$60		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$1E,$1D		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$DB,$5A		; ADATAEX
		.BYTE	$C0,$3C		; ADATAEX
		.BYTE	$F1,$00		; ACMDF1	$00
		.BYTE	$63		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$24		; ADATA
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C5,$3C		; ADATAEX
		.BYTE	$BF		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$C1,$3C		; ADATAEX
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$A8		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$CB,$46		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$2A		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$29		; ADATA
		.BYTE	$C8,$3C		; ADATAEX
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$BF		; ADATA
		.BYTE	$F6,$2B		; ACMDF6	$2B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$C7,$5A		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$C0,$3C		; ADATAEX
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$84		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$05		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$DB,$5A		; ADATAEX
		.BYTE	$C0,$3C		; ADATAEX
		.BYTE	$A7		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$C8,$3C		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$A1		; ADATA
		.BYTE	$DC,$2D		; ADATAEX
		.BYTE	$A1,$48		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$CA,$04		; ADATAEX
		.BYTE	$CB,$42		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$2A		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$29,$A8		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$AD		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$BE		; ADATA
		.BYTE	$FB		; ARET
_mus4_C:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$34		; ACMDF5	$34
		.BYTE	$FA		; AJSR	0x00050DEC
		.WORD	byte_50DEC
		.BYTE	$F5,$35		; ACMDF5	$35
		.BYTE	$FA		; AJSR	0x00050DEC
		.WORD	byte_50DEC
		.BYTE	$F8		; AJMP	_mus4_C
		.WORD	_mus4_C
byte_50DEC:
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$5B,$59,$B0	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$39,$18,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$19		; ADATA
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$5B,$59,$50	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$39,$19,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$1B		; ADATA
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$50,$5B,$59,$50	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$38,$19,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$19		; ADATA
		.BYTE	$F4,$B4		; ACMDF4	$B4
		.BYTE	$3B,$12,$39,$12,$3B,$12,$39,$12 ;	ADATA
		.BYTE	$FB		; ARET
_mus4_E:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	0x00050E39
		.WORD	byte_50E39
		.BYTE	$FA		; AJSR	0x00050E52
		.WORD	byte_50E52
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00050E39
		.WORD	byte_50E39
		.BYTE	$FA		; AJSR	0x00050E5E
		.WORD	byte_50E5E
		.BYTE	$F8		; AJMP	_mus4_E
		.WORD	_mus4_E
byte_50E39:
		.BYTE	$F6,$2D		; ACMDF6	$2D
		.BYTE	$2E		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$23		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$26		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$FB		; ARET
byte_50E52:
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$C3,$09		; ADATAEX
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$C4,$06		; ADATAEX
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$FB		; ARET
byte_50E5E:
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$C4,$09		; ADATAEX
		.BYTE	$C4,$06		; ADATAEX
		.BYTE	$C4,$09		; ADATAEX
		.BYTE	$C4,$06		; ADATAEX
		.BYTE	$FB		; ARET
_mus4_D:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	0x00050E79
		.WORD	byte_50E79
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00050E8F
		.WORD	byte_50E8F
		.BYTE	$F8		; AJMP	_mus4_D
		.WORD	_mus4_D
byte_50E79:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$9F,$1E		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$DD,$13		; ADATAEX
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$DE,$0B		; ADATAEX
		.BYTE	$1F		; ADATA
		.BYTE	$FB		; ARET
byte_50E8F:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$9F,$1E		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$DE,$09		; ADATAEX
		.BYTE	$DE,$06		; ADATAEX
		.BYTE	$DE,$09		; ADATAEX
		.BYTE	$DE,$06		; ADATAEX
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
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$FA		; AJSR	0x00050F76
		.WORD	byte_50F76
		.BYTE	$FA		; AJSR	0x00050EF2
		.WORD	byte_50EF2
		.BYTE	$FA		; AJSR	0x00050F04
		.WORD	byte_50F04
		.BYTE	$FA		; AJSR	0x00050EF2
		.WORD	byte_50EF2
		.BYTE	$FA		; AJSR	0x00050F5F
		.WORD	byte_50F5F
byte_50ECA:
		.BYTE	$FA		; AJSR	0x00050EF2
		.WORD	byte_50EF2
		.BYTE	$FA		; AJSR	0x00050F04
		.WORD	byte_50F04
		.BYTE	$FA		; AJSR	0x00050EF2
		.WORD	byte_50EF2
		.BYTE	$FA		; AJSR	0x00050F16
		.WORD	byte_50F16
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00050EF2
		.WORD	byte_50EF2
		.BYTE	$FA		; AJSR	0x00050F04
		.WORD	byte_50F04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00050EF2
		.WORD	byte_50EF2
		.BYTE	$FA		; AJSR	0x00050F16
		.WORD	byte_50F16
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	0x00050F2B
		.WORD	byte_50F2B
		.BYTE	$FA		; AJSR	0x00050F41
		.WORD	byte_50F41
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x00050ECA
		.WORD	byte_50ECA
		.BYTE	$FF		; ASTOP
byte_50EF2:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_50F04:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_50F16:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F,$1F,$3D	; ADATA
		.BYTE	$FB		; ARET
byte_50F2B:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7D		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5D		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$FB		; ARET
byte_50F41:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3D		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E,$1E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F,$1E,$1E,$1D	; ADATA
		.BYTE	$FB		; ARET
byte_50F5F:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7D		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$DF,$02		; ADATAEX
		.BYTE	$DF,$05		; ADATAEX
		.BYTE	$1F,$3E		; ADATA
		.BYTE	$FB		; ARET
byte_50F76:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F,$7F,$3F,$3F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F,$1F,$1E,$1E	; ADATA
		.BYTE	$FB		; ARET
_mus5_B:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F5,$1C		; ACMDF5	$1C
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$D0,$70		; ADATAEX
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00050FB0
		.WORD	byte_50FB0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00050FBF
		.WORD	byte_50FBF
byte_50F98:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00050FB0
		.WORD	byte_50FB0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00050FBF
		.WORD	byte_50FBF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1C		; ACMDF5	$1C
		.BYTE	$FA		; AJSR	0x00050FCF
		.WORD	byte_50FCF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x00050F98
		.WORD	byte_50F98
		.BYTE	$FF		; ASTOP
byte_50FB0:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$34,$34		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$18,$19,$1B,$10	; ADATA
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$7E,$79		; ADATA
		.BYTE	$FB		; ARET
byte_50FBF:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$34,$34		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$18,$19		; ADATA
		.BYTE	$F4,$A6		; ACMDF4	$A6
		.BYTE	$3B,$3E,$3E,$39,$39 ; ADATA
		.BYTE	$FB		; ARET
byte_50FCF:
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$B4,$60,$7E,$B2,$BE,$BD,$71,$7C,$63,$7C,$65,$7E ;	ADATA
		.BYTE	$FB		; ARET
_mus5_C:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FA		; AJSR	0x00051085
		.WORD	byte_51085
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00051012
		.WORD	byte_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051066
		.WORD	byte_51066
byte_50FF0:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00051012
		.WORD	byte_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051025
		.WORD	byte_51025
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x00051012
		.WORD	byte_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051025
		.WORD	byte_51025
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00051039
		.WORD	byte_51039
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051052
		.WORD	byte_51052
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x00050FF0
		.WORD	byte_50FF0
		.BYTE	$FF		; ASTOP
byte_51012:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25,$25	; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25		; ADATA
		.BYTE	$FB		; ARET
byte_51025:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25,$25	; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$05,$05		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$26		; ADATA
		.BYTE	$FB		; ARET
byte_51039:
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FA		; ACMDF1	$FA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$05,$05		; ADATA
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$F1,$FC		; ACMDF1	$FC
		.BYTE	$05,$05		; ADATA
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$FB		; ARET
byte_51052:
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$24,$04		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$05		; ADATA
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04,$04,$05,$04	; ADATA
		.BYTE	$FB		; ARET
byte_51066:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25,$25	; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$C6,$02		; ADATAEX
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$C6,$05		; ADATAEX
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$06		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$26		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FB		; ARET
byte_51085:
		.BYTE	$F6,$2D		; ACMDF6	$2D
		.BYTE	$F4,$78		; ACMDF4	$78
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$05		; ADATA
		.BYTE	$F1,$FA		; ACMDF1	$FA
		.BYTE	$07		; ADATA
		.BYTE	$F1,$06		; ACMDF1	$06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$06,$06,$05,$04	; ADATA
		.BYTE	$FB		; ARET
_mus5_D:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$02		; ACMDF0	$02
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F6,$AB		; ACMDF6	$AB
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$CD,$54		; ADATAEX
		.BYTE	$CD,$00		; ADATAEX
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$07		; ACMDF3	$07
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$10		; ACMDF6	$10
		.BYTE	$F5,$1C		; ACMDF5	$1C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x000510FF
		.WORD	byte_510FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x0005110E
		.WORD	byte_5110E
byte_510C5:
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F6,$27		; ACMDF6	$27
		.BYTE	$FA		; AJSR	0x000511D5
		.WORD	byte_511D5
		.BYTE	$FA		; AJSR	0x0005120C
		.WORD	byte_5120C
		.BYTE	$FA		; AJSR	0x000511D5
		.WORD	byte_511D5
		.BYTE	$FA		; AJSR	0x000511F3
		.WORD	byte_511F3
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FA		; AJSR	0x0005111F
		.WORD	byte_5111F
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$FA		; AJSR	0x000511D5
		.WORD	byte_511D5
		.BYTE	$FA		; AJSR	0x0005120C
		.WORD	byte_5120C
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FA		; AJSR	0x0005111F
		.WORD	byte_5111F
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$FA		; AJSR	0x000511D5
		.WORD	byte_511D5
		.BYTE	$FA		; AJSR	0x000511F3
		.WORD	byte_511F3
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$FA		; AJSR	0x0005114E
		.WORD	byte_5114E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x000510C5
		.WORD	byte_510C5
		.BYTE	$FF		; ASTOP
byte_510FF:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$34,$34		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$18,$19,$1B,$10	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$7E,$79		; ADATA
		.BYTE	$FB		; ARET
byte_5110E:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$34,$34		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$18,$19,$1B,$10	; ADATA
		.BYTE	$F4,$A6		; ACMDF4	$A6
		.BYTE	$3E,$3E,$39,$39	; ADATA
		.BYTE	$FB		; ARET
byte_5111F:
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$F5,$28		; ACMDF5	$28
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C2,$01		; ADATAEX
		.BYTE	$C3,$06		; ADATAEX
		.BYTE	$10,$00,$10	; ADATA
		.BYTE	$C2,$01		; ADATAEX
		.BYTE	$C3,$11		; ADATAEX
		.BYTE	$D0,$34		; ADATAEX
		.BYTE	$00,$1E,$00,$10,$00,$10 ;	ADATA
		.BYTE	$F1,$FC		; ACMDF1	$FC
		.BYTE	$CB,$01		; ADATAEX
		.BYTE	$C0,$00		; ADATAEX
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$0D		; ACMDF3	$0D
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$3E		; ADATAEX
		.BYTE	$FB		; ARET
byte_5114E:
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C2,$01		; ADATAEX
		.BYTE	$C3,$14		; ADATAEX
		.BYTE	$F4,$6F		; ACMDF4	$6F
		.BYTE	$40		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$23,$20		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$1E,$1F,$20	; ADATA
		.BYTE	$FB		; ARET
_mus5_E:
		.BYTE	$F2,$01		; ACMDF2	$01
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$F6,$AB		; ACMDF6	$AB
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$C1,$54		; ADATAEX
		.BYTE	$C1,$00		; ADATAEX
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$07		; ACMDF3	$07
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$FA		; AJSR	0x000511B3
		.WORD	byte_511B3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000511C4
		.WORD	byte_511C4
byte_51186:
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$FA		; AJSR	0x000511B3
		.WORD	byte_511B3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000511C4
		.WORD	byte_511C4
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F5,$1C		; ACMDF5	$1C
		.BYTE	$F6,$1D		; ACMDF6	$1D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FA		; AJSR	0x00051225
		.WORD	byte_51225
		.BYTE	$FA		; AJSR	0x00051225
		.WORD	byte_51225
		.BYTE	$FA		; AJSR	0x00051233
		.WORD	byte_51233
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00051251
		.WORD	byte_51251
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x00051186
		.WORD	byte_51186
		.BYTE	$FF		; ASTOP
byte_511B3:
		.BYTE	$F5,$10		; ACMDF5	$10
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$3B,$3B		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$1B,$1E,$00,$10	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$65,$7D		; ADATA
		.BYTE	$FB		; ARET
byte_511C4:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$3B,$3B		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$1B,$1E,$00,$10	; ADATA
		.BYTE	$F4,$A6		; ACMDF4	$A6
		.BYTE	$25,$25,$3D,$3D	; ADATA
		.BYTE	$FB		; ARET
byte_511D5:
		.BYTE	$F5,$28		; ACMDF5	$28
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$30		; ADATA
		.BYTE	$F1,$08		; ACMDF1	$08
		.BYTE	$00,$00		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$24		; ADATA
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$00,$10		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$22		; ADATA
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$1E		; ADATA
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$90		; ADATA
		.BYTE	$F1,$08		; ACMDF1	$08
		.BYTE	$FB		; ARET
byte_511F3:
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$70		; ADATA
		.BYTE	$F1,$09		; ACMDF1	$09
		.BYTE	$00,$00,$00,$00	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$3E		; ADATA
		.BYTE	$C1,$01		; ADATAEX
		.BYTE	$C2,$06		; ADATAEX
		.BYTE	$F1,$F9		; ACMDF1	$F9
		.BYTE	$10		; ADATA
		.BYTE	$F1,$07		; ACMDF1	$07
		.BYTE	$60		; ADATA
		.BYTE	$FB		; ARET
byte_5120C:
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$70		; ADATA
		.BYTE	$F1,$08		; ACMDF1	$08
		.BYTE	$00,$00,$00,$00	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$3E		; ADATA
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$00		; ADATA
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$90		; ADATA
		.BYTE	$F1,$08		; ACMDF1	$08
		.BYTE	$FB		; ARET
_unref_10:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$09		; ACMDF6	$09
byte_51225:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$14,$1B,$00,$1B,$03,$1B ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$03,$1B,$00,$1B	; ADATA
		.BYTE	$FB		; ARET
byte_51233:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$17,$00,$03,$1D,$07,$00 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1C,$00,$03,$00,$07,$03,$00,$1C,$00,$03,$08,$00,$0A,$05,$02,$1E ;	ADATA
		.BYTE	$05,$1B,$1E,$0E
		.BYTE	$FB		; ARET
byte_51251:
		.BYTE	$F5,$34		; ACMDF5	$34
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C6,$01		; ADATAEX
		.BYTE	$C7,$14		; ADATAEX
		.BYTE	$F4,$6F		; ACMDF4	$6F
		.BYTE	$43		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$27,$23		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$00,$02,$23	; ADATA
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
		.BYTE	$F2,$05		; ACMDF2	$05
byte_5127B:
		.BYTE	$FA		; AJSR	0x000512A6
		.WORD	byte_512A6
		.BYTE	$FA		; AJSR	0x000512B1
		.WORD	byte_512B1
		.BYTE	$FA		; AJSR	0x000512A6
		.WORD	byte_512A6
		.BYTE	$FA		; AJSR	0x000512B1
		.WORD	byte_512B1
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x000512A6
		.WORD	byte_512A6
		.BYTE	$FA		; AJSR	0x000512B1
		.WORD	byte_512B1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000512A6
		.WORD	byte_512A6
		.BYTE	$FA		; AJSR	0x000512BE
		.WORD	byte_512BE
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x000512CD
		.WORD	byte_512CD
		.BYTE	$FA		; AJSR	0x000512D9
		.WORD	byte_512D9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000512EC
		.WORD	byte_512EC
		.BYTE	$F8		; AJMP	0x0005127B
		.WORD	byte_5127B
		.BYTE	$FF		; ASTOP
byte_512A6:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$8F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F,$6F		; ADATA
		.BYTE	$FB		; ARET
byte_512B1:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$2F,$1F,$2F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F,$6F		; ADATA
		.BYTE	$FB		; ARET
byte_512BE:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$8F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F,$0F,$1F,$1F,$1E,$1D ;	ADATA
		.BYTE	$FB		; ARET
byte_512CD:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$8F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F,$4F,$1F	; ADATA
		.BYTE	$FB		; ARET
byte_512D9:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$0F,$5F,$5F	; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$FB		; ARET
byte_512EC:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5F		; ADATA
		.BYTE	$CF,$10		; ADATAEX
		.BYTE	$5F,$3F		; ADATA
		.BYTE	$DE,$06		; ADATAEX
		.BYTE	$FB		; ARET
_mus0_B:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0B		; ACMDF0	$0B
byte_51304:
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$FA		; AJSR	0x0005131C
		.WORD	byte_5131C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x0005135B
		.WORD	byte_5135B
		.BYTE	$FA		; AJSR	0x00051382
		.WORD	byte_51382
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000513A5
		.WORD	byte_513A5
		.BYTE	$F8		; AJMP	0x00051304
		.WORD	byte_51304
		.BYTE	$FF		; ASTOP
byte_5131C:
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$03,$0F		; ADATA
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$06		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$25		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$06		; ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$F6,$94		; ACMDF6	$94
		.BYTE	$25		; ADATA
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$06		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$06		; ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$27		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$06		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$44		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$27		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$08		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$25		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$07		; ADATA
		.BYTE	$FB		; ARET
byte_5135B:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$04		; ADATA
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$26		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FB		; ARET
byte_51382:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$23		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$26		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FB		; ARET
byte_513A5:
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$06,$2F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$F1,$05		; ACMDF1	$05
		.BYTE	$C4,$10		; ADATAEX
		.BYTE	$F1,$FB		; ACMDF1	$FB
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24		; ADATA
		.BYTE	$C4,$06		; ADATAEX
		.BYTE	$FB		; ARET
_mus0_C:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	0x000513FF
		.WORD	byte_513FF
		.BYTE	$FA		; AJSR	0x0005140E
		.WORD	byte_5140E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$20		; ACMDF5	$20
		.BYTE	$FA		; AJSR	0x000513FF
		.WORD	byte_513FF
		.BYTE	$F5,$22		; ACMDF5	$22
		.BYTE	$FA		; AJSR	0x0005140E
		.WORD	byte_5140E
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FA		; AJSR	0x000513FF
		.WORD	byte_513FF
		.BYTE	$FA		; AJSR	0x0005140E
		.WORD	byte_5140E
		.BYTE	$F5,$20		; ACMDF5	$20
		.BYTE	$FA		; AJSR	0x000513FF
		.WORD	byte_513FF
		.BYTE	$FA		; AJSR	0x0005140E
		.WORD	byte_5140E
		.BYTE	$F5,$22		; ACMDF5	$22
		.BYTE	$FA		; AJSR	0x0005140E
		.WORD	byte_5140E
		.BYTE	$FA		; AJSR	0x00051424
		.WORD	byte_51424
		.BYTE	$F8		; AJMP	_mus0_C
		.WORD	_mus0_C
		.BYTE	$FF		; ASTOP
byte_513FF:
		.BYTE	$34,$10,$34,$10,$92,$34,$10,$14,$37,$1B,$3D,$1E,$3D,$1E ;	ADATA
		.BYTE	$FB		; ARET
byte_5140E:
		.BYTE	$34,$10,$34,$10,$92,$34,$10 ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DD,$02		; ADATAEX
		.BYTE	$DE,$03		; ADATAEX
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$20,$1E,$3B,$1A,$39,$17 ;	ADATA
		.BYTE	$FB		; ARET
byte_51424:
		.BYTE	$F4,$96		; ACMDF4	$96
		.BYTE	$54,$54,$54,$54	; ADATA
		.BYTE	$D4,$10		; ADATAEX
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$07,$02,$1B	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$D4,$1F		; ADATAEX
		.BYTE	$FB		; ARET
_mus0_D:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F6,$1D		; ACMDF6	$1D
		.BYTE	$DE,$02		; ADATAEX
		.BYTE	$DF,$02		; ADATAEX
		.BYTE	$C0,$0B		; ADATAEX
		.BYTE	$F1,$FA		; ACMDF1	$FA
		.BYTE	$D0,$01		; ADATAEX
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$2A,$0A,$30,$0A,$2A,$10,$2A,$10,$2A,$0A,$30,$09,$2A ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$D2,$02		; ADATAEX
		.BYTE	$D3,$02		; ADATAEX
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$D4,$10		; ADATAEX
		.BYTE	$D0,$00		; ADATAEX
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$3E,$1E,$30,$1E,$3E,$10,$3E,$10,$3E,$1E,$30,$1E ;	ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$F6,$0E		; ACMDF6	$0E
		.BYTE	$19,$1E,$19	; ADATA
		.BYTE	$DA,$01		; ADATAEX
		.BYTE	$DB,$0F		; ADATAEX
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$30		; ADATA
		.BYTE	$DF,$00		; ADATAEX
		.BYTE	$E3,$FA		; ACMDE3	$FA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$02		; ACMDE3	$02
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$A0,$A3,$8A,$67,$25,$10 ;	ADATA
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$27,$25,$10	; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30		; ADATA
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$F6,$0D		; ACMDF6	$0D
		.BYTE	$3E,$20,$10,$63	; ADATA
		.BYTE	$D0,$3C		; ADATAEX
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F6,$0C		; ACMDF6	$0C
		.BYTE	$3D,$10,$3D,$1E,$3D,$3B ;	ADATA
		.BYTE	$D0,$73		; ADATAEX
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$F6,$11		; ACMDF6	$11
		.BYTE	$DD,$02		; ADATAEX
		.BYTE	$DE,$17		; ADATAEX
		.BYTE	$1B,$50		; ADATA
		.BYTE	$DD,$02		; ADATAEX
		.BYTE	$DE,$17		; ADATAEX
		.BYTE	$1B		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$32,$14		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$3E,$1F		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$20		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$12,$34		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$0B,$2A,$14,$2A,$09,$34,$09,$28,$14,$28,$07 ; ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$F6,$0D		; ACMDF6	$0D
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$C5,$02		; ADATAEX
		.BYTE	$C6,$08		; ADATAEX
		.BYTE	$03,$1D,$1E,$60	; ADATA
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$50,$A7,$AA	; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$A5,$AC,$AF	; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$AA,$A5		; ADATA
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F6,$10		; ACMDF6	$10
		.BYTE	$C2,$02		; ADATAEX
		.BYTE	$C3,$17		; ADATAEX
		.BYTE	$20,$30		; ADATA
		.BYTE	$C2,$02		; ADATAEX
		.BYTE	$C3,$17		; ADATAEX
		.BYTE	$20,$30,$3E,$1F,$20,$10 ;	ADATA
		.BYTE	$C2,$02		; ADATAEX
		.BYTE	$C3,$17		; ADATAEX
		.BYTE	$20,$30		; ADATA
		.BYTE	$C2,$02		; ADATAEX
		.BYTE	$C3,$17		; ADATAEX
		.BYTE	$20,$30,$3E,$1F,$20,$67,$25,$10,$23,$1E,$3F,$40 ;	ADATA
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$D0,$41		; ADATAEX
		.BYTE	$2A,$10,$2A,$6C	; ADATA
		.BYTE	$D0,$3C		; ADATAEX
		.BYTE	$F6,$0D		; ACMDF6	$0D
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$C9,$02		; ADATAEX
		.BYTE	$CA,$17		; ADATAEX
		.BYTE	$07,$30,$0A,$47,$25,$06,$27,$0A,$30,$0F,$49 ; ADATA
		.BYTE	$F6,$0F		; ACMDF6	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$3E,$0A,$29,$06,$2C,$05,$2B,$04 ;	ADATA
		.BYTE	$F6,$06		; ACMDF6	$06
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$D8,$02		; ADATAEX
		.BYTE	$D9,$08		; ADATAEX
		.BYTE	$F4,$E6		; ACMDF4	$E6
		.BYTE	$1A		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$3B,$1E,$3A	; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$19,$37,$12	; ADATA
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$DE,$02		; ADATAEX
		.BYTE	$DF,$1C		; ADATAEX
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$A3		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$BE		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$B9		; ADATA
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$C6,$01		; ADATAEX
		.BYTE	$C7,$04		; ADATAEX
		.BYTE	$30		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$91		; ACMDF6	$91
		.BYTE	$C6,$02		; ADATAEX
		.BYTE	$C7,$04		; ADATAEX
		.BYTE	$C7,$00		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$02		; ACMDE3	$02
		.BYTE	$F3,$03		; ACMDF3	$03
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$16		; ACMDF6	$16
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$D0,$01		; ADATAEX
		.BYTE	$D2,$1F		; ADATAEX
		.BYTE	$F8		; AJMP	_mus0_D
		.WORD	_mus0_D
		.BYTE	$FF		; ASTOP
_mus0_E:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$1D		; ACMDF6	$1D
		.BYTE	$DE,$02		; ADATAEX
		.BYTE	$DF,$02		; ADATAEX
		.BYTE	$C0,$0B		; ADATAEX
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$F1,$FA		; ACMDF1	$FA
		.BYTE	$27,$07,$30,$07,$27,$10,$27,$10,$27,$07,$30,$07,$27 ; ADATA
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$D2,$02		; ADATAEX
		.BYTE	$D3,$02		; ADATAEX
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$D4,$10		; ADATAEX
		.BYTE	$D0,$00		; ADATAEX
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$27,$07,$30,$07,$27,$10,$27,$10,$27,$07,$30,$70 ;	ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$FC,$09		; ALOOP_START $09
		.BYTE	$30,$1E		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$3E		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$14		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$3E		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$14,$3D		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$1E		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30,$1E		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$07		; ACMDF6	$07
		.BYTE	$32,$14		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$3E		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$14,$3D		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$D2,$00		; ADATAEX
		.BYTE	$E3,$03		; ACMDE3	$03
		.BYTE	$F3,$05		; ACMDF3	$05
		.BYTE	$D4,$00		; ADATAEX
		.BYTE	$E3,$03		; ACMDE3	$03
		.BYTE	$F3,$0A		; ACMDF3	$0A
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$30,$0B,$2A,$14,$2A,$09,$34,$09,$28,$14,$08 ; ADATA
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F6,$0E		; ACMDF6	$0E
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$C5,$02		; ADATAEX
		.BYTE	$C6,$08		; ADATAEX
		.BYTE	$03,$1D,$1E,$00	; ADATA
		.BYTE	$F4,$96		; ACMDF4	$96
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$0A,$1E,$03,$0A,$00,$03,$0A,$1E,$03,$0A,$00,$03 ;	ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F6,$10		; ACMDF6	$10
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$C8,$02		; ADATAEX
		.BYTE	$C9,$17		; ADATAEX
		.BYTE	$25,$30		; ADATA
		.BYTE	$C8,$02		; ADATAEX
		.BYTE	$C9,$17		; ADATAEX
		.BYTE	$25,$30,$23,$04,$25,$10 ;	ADATA
		.BYTE	$C8,$02		; ADATAEX
		.BYTE	$C9,$17		; ADATAEX
		.BYTE	$25,$30		; ADATA
		.BYTE	$C8,$02		; ADATAEX
		.BYTE	$C9,$17		; ADATAEX
		.BYTE	$25,$30,$23,$04,$25,$6C,$2A,$10,$37,$12,$33,$54 ;	ADATA
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F6,$10		; ACMDF6	$10
		.BYTE	$14,$37,$1B,$3D,$1E,$3D,$1E,$34,$10 ; ADATA
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$25,$10,$25,$67	; ADATA
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$10		; ACMDF6	$10
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$30,$1E,$20,$1E,$3B,$1A,$39,$17 ;	ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$39,$03,$23,$19,$23,$19,$22,$03 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$0F		; ACMDF6	$0F
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$10,$1E,$0A,$10,$09,$06,$10,$0C,$05,$10,$0B,$04 ;	ADATA
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$39,$03,$23,$19,$22,$03,$22,$03 ;	ADATA
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$F4,$96		; ACMDF4	$96
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$05,$1B,$02,$07,$19,$02 ;	ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$C6,$01		; ADATAEX
		.BYTE	$C7,$04		; ADATAEX
		.BYTE	$30		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$91		; ACMDF6	$91
		.BYTE	$C6,$02		; ADATAEX
		.BYTE	$C7,$04		; ADATAEX
		.BYTE	$C7,$00		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$02		; ACMDE3	$02
		.BYTE	$F3,$03		; ACMDF3	$03
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$16		; ACMDF6	$16
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$D0,$01		; ADATAEX
		.BYTE	$D9,$1F		; ADATAEX
		.BYTE	$F8		; AJMP	_mus0_E
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
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x000517AA
		.WORD	byte_517AA
		.BYTE	$FA		; AJSR	0x000517BC
		.WORD	byte_517BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000517AA
		.WORD	byte_517AA
		.BYTE	$FA		; AJSR	0x000517CE
		.WORD	byte_517CE
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x000517AA
		.WORD	byte_517AA
		.BYTE	$FA		; AJSR	0x000517BC
		.WORD	byte_517BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000517AA
		.WORD	byte_517AA
		.BYTE	$FA		; AJSR	0x000517CE
		.WORD	byte_517CE
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x000517AA
		.WORD	byte_517AA
		.BYTE	$FA		; AJSR	0x000517E1
		.WORD	byte_517E1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000517AA
		.WORD	byte_517AA
		.BYTE	$FA		; AJSR	0x000517CE
		.WORD	byte_517CE
		.BYTE	$F8		; AJMP	_mus6_A
		.WORD	_mus6_A
		.BYTE	$FF		; ASTOP
byte_517AA:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_517BC:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_517CE:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E,$3E,$3E	; ADATA
		.BYTE	$FB		; ARET
byte_517E1:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3D,$3E		; ADATA
		.BYTE	$FB		; ARET
_mus6_B:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	0x0005181C
		.WORD	byte_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051831
		.WORD	byte_51831
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FC,$1F		; ALOOP_START $1F
		.BYTE	$FA		; AJSR	0x0005181C
		.WORD	byte_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051831
		.WORD	byte_51831
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	0x0005181C
		.WORD	byte_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051831
		.WORD	byte_51831
		.BYTE	$F8		; AJMP	_mus6_B
		.WORD	_mus6_B
		.BYTE	$FF		; ASTOP
byte_5181C:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$24		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$24		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FB		; ARET
byte_51831:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$23,$23,$23	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FB		; ARET
_mus6_C:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00051884
		.WORD	byte_51884
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FA		; AJSR	0x00051889
		.WORD	byte_51889
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FA		; AJSR	0x0005188C
		.WORD	byte_5188C
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FA		; AJSR	0x0005188F
		.WORD	byte_5188F
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051892
		.WORD	byte_51892
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FA		; AJSR	0x00051884
		.WORD	byte_51884
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FA		; AJSR	0x00051892
		.WORD	byte_51892
		.BYTE	$FA		; AJSR	0x00051895
		.WORD	byte_51895
		.BYTE	$FA		; AJSR	0x000518B8
		.WORD	byte_518B8
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x000518C8
		.WORD	byte_518C8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_mus6_C
		.WORD	_mus6_C
		.BYTE	$FF		; ASTOP
byte_51884:
		.BYTE	$F4,$E6		; ACMDF4	$E6
		.BYTE	$36,$22		; ADATA
		.BYTE	$FB		; ARET
byte_51889:
		.BYTE	$35,$21		; ADATA
		.BYTE	$FB		; ARET
byte_5188C:
		.BYTE	$34,$20		; ADATA
		.BYTE	$FB		; ARET
byte_5188F:
		.BYTE	$33,$3F		; ADATA
		.BYTE	$FB		; ARET
byte_51892:
		.BYTE	$32,$3E		; ADATA
		.BYTE	$FB		; ARET
byte_51895:
		.BYTE	$F4,$DC		; ACMDF4	$DC
		.BYTE	$39,$3B,$3D,$36,$39,$3B ;	ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$31		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$3B		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$31		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$39		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$3B		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$31		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$3D		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$31		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FB		; ARET
byte_518B8:
		.BYTE	$31,$31,$3D,$31,$30,$31,$7D,$31,$31,$3D,$31,$31,$3D,$31,$3D ; ADATA
		.BYTE	$FB		; ARET
byte_518C8:
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$36,$3D,$39,$22,$1D,$02,$1D,$02,$39 ; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F4,$A0		; ACMDF4	$A0
		.BYTE	$2E		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_mus6_D:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F6,$2A		; ACMDF6	$2A
		.BYTE	$FA		; AJSR	0x0005190C
		.WORD	byte_5190C
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	0x0005195B
		.WORD	byte_5195B
		.BYTE	$FA		; AJSR	0x000519B1
		.WORD	byte_519B1
		.BYTE	$FA		; AJSR	0x000519C7
		.WORD	byte_519C7
		.BYTE	$FA		; AJSR	0x000519B1
		.WORD	byte_519B1
		.BYTE	$FA		; AJSR	0x000519E2
		.WORD	byte_519E2
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x000519FE
		.WORD	byte_519FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_mus6_D
		.WORD	_mus6_D
		.BYTE	$FF		; ASTOP
byte_5190C:
		.BYTE	$22		; ADATA
		.BYTE	$D0,$82		; ADATAEX
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$C8,$01		; ADATAEX
		.BYTE	$C9,$09		; ADATAEX
		.BYTE	$27,$25,$27	; ADATA
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$07		; ADATAEX
		.BYTE	$C7,$09		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6	$2A
		.BYTE	$D0,$08		; ADATAEX
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$22,$25,$27,$29	; ADATA
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C7,$07		; ADATAEX
		.BYTE	$C9,$09		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6	$2A
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$D0,$08		; ADATAEX
		.BYTE	$C8,$01		; ADATAEX
		.BYTE	$C9,$09		; ADATAEX
		.BYTE	$27,$25,$27	; ADATA
		.BYTE	$F6,$1E		; ACMDF6	$1E
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$07		; ADATAEX
		.BYTE	$C7,$09		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$1C		; ADATAEX
		.BYTE	$FB		; ARET
byte_5195B:
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$D8,$02		; ADATAEX
		.BYTE	$D9,$12		; ADATAEX
		.BYTE	$36,$36,$30	; ADATA
		.BYTE	$F4,$E6		; ACMDF4	$E6
		.BYTE	$36,$34		; ADATA
		.BYTE	$D5,$02		; ADATAEX
		.BYTE	$D6,$12		; ADATAEX
		.BYTE	$79		; ADATA
		.BYTE	$D0,$32		; ADATAEX
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$DA,$02		; ADATAEX
		.BYTE	$DB,$12		; ADATAEX
		.BYTE	$3B,$3B,$30	; ADATA
		.BYTE	$DC,$01		; ADATAEX
		.BYTE	$DD,$09		; ADATAEX
		.BYTE	$30		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$5B,$19,$96	; ADATA
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$D8,$02		; ADATAEX
		.BYTE	$D9,$12		; ADATAEX
		.BYTE	$36,$36,$30,$34,$30 ; ADATA
		.BYTE	$D8,$01		; ADATAEX
		.BYTE	$D9,$09		; ADATAEX
		.BYTE	$30,$36,$34,$76,$B0 ; ADATA
		.BYTE	$D9,$01		; ADATAEX
		.BYTE	$DA,$01		; ADATAEX
		.BYTE	$DB,$12		; ADATAEX
		.BYTE	$3B,$3B,$30,$3D,$30 ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$5B,$19,$96	; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$FB		; ARET
byte_519B1:
		.BYTE	$F6,$25		; ACMDF6	$25
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$D8,$01		; ADATAEX
		.BYTE	$D9,$12		; ADATAEX
		.BYTE	$36,$36,$30,$34,$30 ; ADATA
		.BYTE	$D8,$02		; ADATAEX
		.BYTE	$D9,$1C		; ADATAEX
		.BYTE	$36,$36		; ADATA
		.BYTE	$D0,$29		; ADATAEX
		.BYTE	$FB		; ARET
byte_519C7:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$D9,$01		; ADATAEX
		.BYTE	$DA,$01		; ADATAEX
		.BYTE	$DB,$12		; ADATAEX
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$3B,$39,$30	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F6,$A8		; ACMDF6	$A8
		.BYTE	$36,$34		; ADATA
		.BYTE	$F6,$28		; ACMDF6	$28
		.BYTE	$76		; ADATA
		.BYTE	$D0,$46		; ADATAEX
		.BYTE	$FB		; ARET
byte_519E2:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$DA,$02		; ADATAEX
		.BYTE	$DB,$08		; ADATAEX
		.BYTE	$30,$39		; ADATA
		.BYTE	$DA,$01		; ADATAEX
		.BYTE	$DB,$09		; ADATAEX
		.BYTE	$30,$39,$30	; ADATA
		.BYTE	$DB,$01		; ADATAEX
		.BYTE	$DC,$01		; ADATAEX
		.BYTE	$DD,$26		; ADATAEX
		.BYTE	$D0,$32		; ADATAEX
		.BYTE	$FB		; ARET
byte_519FE:
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F6,$25		; ACMDF6	$25
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$42,$50,$40,$10,$22,$20,$30 ; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$42,$50,$60,$70	; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$20,$40,$10,$42,$10 ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$25,$22,$70	; ADATA
		.BYTE	$FB		; ARET
_mus6_E:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00051A56
		.WORD	byte_51A56
		.BYTE	$FA		; AJSR	0x00051A6A
		.WORD	byte_51A6A
		.BYTE	$FA		; AJSR	0x00051A7D
		.WORD	byte_51A7D
		.BYTE	$FA		; AJSR	0x00051A90
		.WORD	byte_51A90
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051AA3
		.WORD	byte_51AA3
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	byte_519C7
		.WORD	byte_519C7
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$FA		; AJSR	0x00051AA3
		.WORD	byte_51AA3
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	byte_519E2
		.WORD	byte_519E2
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00051AB6
		.WORD	byte_51AB6
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_mus6_E
		.WORD	_mus6_E
		.BYTE	$FF		; ASTOP
byte_51A56:
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$76		; ADATA
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$36,$39,$3D,$22	; ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$39,$3B,$30,$3B,$30,$39,$7B,$7D ;	ADATA
		.BYTE	$FB		; ARET
byte_51A6A:
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$35,$35,$35,$39,$3D,$21 ;	ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$39,$3B,$30,$3B,$30,$39,$7B,$7D ;	ADATA
		.BYTE	$FB		; ARET
byte_51A7D:
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$34,$34,$34,$39,$3D,$20 ;	ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$39,$3B,$30,$3B,$30,$39,$7B,$7D ;	ADATA
		.BYTE	$FB		; ARET
byte_51A90:
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$33,$33,$33,$39,$3D,$3F ;	ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$39,$3B,$30,$3B,$30,$39,$7B,$7D ;	ADATA
		.BYTE	$FB		; ARET
byte_51AA3:
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$62,$3E,$3E,$30,$39,$30,$A2,$3E,$7E,$B0 ;	ADATA
		.BYTE	$FB		; ARET
byte_51AB6:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$36,$36,$22,$36,$36,$36,$22,$36 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$20,$36,$22,$36	; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$25,$22,$36,$3D	; ADATA
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
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x00051B0D
		.WORD	byte_51B0D
		.BYTE	$FA		; AJSR	0x00051B1E
		.WORD	byte_51B1E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051B0D
		.WORD	byte_51B0D
		.BYTE	$FA		; AJSR	0x00051B30
		.WORD	byte_51B30
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00051B47
		.WORD	byte_51B47
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051B59
		.WORD	byte_51B59
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00051B47
		.WORD	byte_51B47
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051B30
		.WORD	byte_51B30
		.BYTE	$FA		; AJSR	0x00051B30
		.WORD	byte_51B30
		.BYTE	$F8		; AJMP	_mus7_A
		.WORD	_mus7_A
		.BYTE	$FF		; ASTOP
byte_51B0D:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$BE		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_51B1E:
		.BYTE	$2F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$BF		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_51B30:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F,$3F,$3F,$1F,$1E,$3D ;	ADATA
		.BYTE	$FB		; ARET
byte_51B47:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E,$5F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$FB		; ARET
byte_51B59:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E,$5F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1E,$3F,$1F	; ADATA
		.BYTE	$FB		; ARET
_mus7_B:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x00051B9B
		.WORD	byte_51B9B
		.BYTE	$FA		; AJSR	0x00051BAF
		.WORD	byte_51BAF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051B9B
		.WORD	byte_51B9B
		.BYTE	$FA		; AJSR	0x00051BC1
		.WORD	byte_51BC1
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x00051BD0
		.WORD	byte_51BD0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051BEB
		.WORD	byte_51BEB
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00051BD0
		.WORD	byte_51BD0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00051BC1
		.WORD	byte_51BC1
		.BYTE	$FA		; AJSR	0x00051C0C
		.WORD	byte_51C0C
		.BYTE	$F8		; AJMP	_mus7_B
		.WORD	_mus7_B
		.BYTE	$FF		; ASTOP
byte_51B9B:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25,$25	; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$FB		; ARET
byte_51BAF:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25,$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$65,$25		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$25		; ADATA
		.BYTE	$FB		; ARET
byte_51BC1:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$23		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$F4,$F4		; ACMDF4	$F4
		.BYTE	$04,$04		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
byte_51BD0:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04,$04	; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$04		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$2D,$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$FB		; ARET
byte_51BEB:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04,$04	; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$04		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$2D		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$05,$24		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FB		; ARET
byte_51C0C:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$23		; ADATA
		.BYTE	$F4,$F4		; ACMDF4	$F4
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$25,$25,$06,$06	; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$FB		; ARET
_mus7_C:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	byte_51C64
		.WORD	byte_51C64
		.BYTE	$D0,$F0		; ADATAEX
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	byte_51C64
		.WORD	byte_51C64
		.BYTE	$FA		; AJSR	byte_51C72
		.WORD	byte_51C72
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1E		; ACMDF5	$1E
		.BYTE	$FA		; AJSR	byte_51C99
		.WORD	byte_51C99
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1E		; ACMDF5	$1E
		.BYTE	$FA		; AJSR	byte_51C99
		.WORD	byte_51C99
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	byte_51CAA
		.WORD	byte_51CAA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$28		; ACMDF5	$28
		.BYTE	$FA		; AJSR	byte_51CAA
		.WORD	byte_51CAA
		.BYTE	$FA		; AJSR	byte_51CAA
		.WORD	byte_51CAA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FA		; AJSR	byte_51CB5
		.WORD	byte_51CB5
		.BYTE	$FA		; AJSR	byte_51CBA
		.WORD	byte_51CBA
		.BYTE	$F8		; AJMP	_mus7_C
		.WORD	_mus7_C
		.BYTE	$FF		; ASTOP
byte_51C64:
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F5,$16		; ACMDF5	$16
		.BYTE	$60,$4C,$0C	; ADATA
		.BYTE	$F4,$A8		; ACMDF4	$A8
		.BYTE	$2A,$2A,$30,$2A	; ADATA
		.BYTE	$FB		; ARET
byte_51C72:
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1F,$02,$05,$07,$00,$02,$05,$07 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1B,$02,$07,$1F,$02,$07 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1B,$02,$0B,$07	; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$7B,$7C,$7D,$7E	; ADATA
		.BYTE	$FB		; ARET
byte_51C99:
		.BYTE	$F4,$BE		; ACMDF4	$BE
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$34,$20		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$34		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$00,$00,$14,$00,$1B,$00 ;	ADATA
		.BYTE	$FB		; ARET
byte_51CAA:
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$04,$0A,$0A,$04,$0A,$0A,$04,$0A ;	ADATA
		.BYTE	$FB		; ARET
byte_51CB5:
		.BYTE	$78,$79,$7A,$7B	; ADATA
		.BYTE	$FB		; ARET
byte_51CBA:
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$7A,$7B,$65,$59,$05 ; ADATA
		.BYTE	$FB		; ARET
_mus7_D:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$FA		; AJSR	0x00051D0A
		.WORD	byte_51D0A
		.BYTE	$FA		; AJSR	0x00051D20
		.WORD	byte_51D20
		.BYTE	$FA		; AJSR	0x00051D0A
		.WORD	byte_51D0A
		.BYTE	$FA		; AJSR	0x00051D6A
		.WORD	byte_51D6A
		.BYTE	$FA		; AJSR	0x00051D0A
		.WORD	byte_51D0A
		.BYTE	$FA		; AJSR	0x00051DA7
		.WORD	byte_51DA7
		.BYTE	$FA		; AJSR	0x00051D0A
		.WORD	byte_51D0A
		.BYTE	$FA		; AJSR	0x00051DD2
		.WORD	byte_51DD2
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	0x00051E03
		.WORD	byte_51E03
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$2A		; ACMDF5	$2A
		.BYTE	$FA		; AJSR	0x00051E1A
		.WORD	byte_51E1A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$29		; ACMDF5	$29
		.BYTE	$FA		; AJSR	0x00051E1A
		.WORD	byte_51E1A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FA		; AJSR	0x00051E2A
		.WORD	byte_51E2A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$10		; ACMDF5	$10
		.BYTE	$FA		; AJSR	0x00051E2A
		.WORD	byte_51E2A
		.BYTE	$F5,$24		; ACMDF5	$24
		.BYTE	$FA		; AJSR	0x00051E03
		.WORD	byte_51E03
		.BYTE	$FA		; AJSR	0x00051E40
		.WORD	byte_51E40
		.BYTE	$F8		; AJMP	_mus7_D
		.WORD	_mus7_D
		.BYTE	$FF		; ASTOP
byte_51D0A:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$16		; ACMDF5	$16
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$74,$40,$00	; ADATA
		.BYTE	$F4,$A8		; ACMDF4	$A8
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$3E,$3E,$30,$3E	; ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$FB		; ARET
byte_51D20:
		.BYTE	$90		; ADATA
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$F6,$12		; ACMDF6	$12
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$38		; ACMDF5	$38
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09,$06,$02,$00	; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05,$06,$1D	; ADATA
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$F5,$2C		; ACMDF5	$2C
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$02,$16,$00,$16,$02,$1A,$00,$16,$1D,$1A,$1D,$06,$1D,$1A,$1D,$06 ;	ADATA
		.BYTE	$F6,$11		; ACMDF6	$11
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F5,$14		; ACMDF5	$14
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$C0,$09		; ADATAEX
		.BYTE	$1F,$1E,$3D,$3B	; ADATA
		.BYTE	$F6,$0F		; ACMDF6	$0F
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F5,$38		; ACMDF5	$38
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$09,$1A,$1D,$00,$22,$20 ;	ADATA
		.BYTE	$FB		; ARET
byte_51D6A:
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$7B,$79		; ADATA
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$DF,$13		; ADATAEX
		.BYTE	$7B		; ADATA
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$02,$10,$02,$02,$42,$1F ;	ADATA
		.BYTE	$F4,$A8		; ACMDF4	$A8
		.BYTE	$20,$20,$30,$20	; ADATA
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$76		; ADATA
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$00,$19,$1D,$00	; ADATA
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$7E,$79		; ADATA
		.BYTE	$FB		; ARET
byte_51DA7:
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$7F,$62,$25,$07,$02,$3F,$3D ; ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$12		; ACMDF6	$12
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07,$1F,$02,$07,$05,$1D,$02,$05 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$5B,$59,$3F,$5B,$56,$39 ;	ADATA
		.BYTE	$FB		; ARET
byte_51DD2:
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$D0,$03		; ADATAEX
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1F,$02,$05,$07,$00,$02,$05,$07 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F6,$23		; ACMDF6	$23
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C6,$01		; ADATAEX
		.BYTE	$C7,$13		; ADATAEX
		.BYTE	$6E		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$25		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$04,$03		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$22		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$D9,$07		; ADATAEX
		.BYTE	$FB		; ARET
byte_51E03:
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$07,$1B,$02,$05,$08,$1C,$03,$06,$09,$1D,$04,$07,$0A,$1E,$05,$08 ;	ADATA
		.BYTE	$FB		; ARET
byte_51E1A:
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$18		; ACMDF6	$18
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$18,$1B,$1E,$04	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1E,$1B,$04,$1B	; ADATA
		.BYTE	$FB		; ARET
byte_51E2A:
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$34,$20,$14,$14,$20 ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$14,$1B,$1E	; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$20,$14,$20	; ADATA
		.BYTE	$FB		; ARET
byte_51E40:
		.BYTE	$09,$1D,$04,$07,$0A,$1E,$05,$08 ;	ADATA
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$0C,$08,$06,$03,$06,$03,$00,$1C ;	ADATA
		.BYTE	$FB		; ARET
_mus7_E:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$FA		; AJSR	0x00051E97
		.WORD	byte_51E97
		.BYTE	$FA		; AJSR	0x00051EA7
		.WORD	byte_51EA7
		.BYTE	$FA		; AJSR	0x00051E97
		.WORD	byte_51E97
		.BYTE	$FA		; AJSR	0x00051EEB
		.WORD	byte_51EEB
		.BYTE	$FA		; AJSR	0x00051E97
		.WORD	byte_51E97
		.BYTE	$FA		; AJSR	0x00051F30
		.WORD	byte_51F30
		.BYTE	$FA		; AJSR	0x00051E97
		.WORD	byte_51E97
		.BYTE	$FA		; AJSR	0x00051F5F
		.WORD	byte_51F5F
		.BYTE	$FA		; AJSR	0x00051F92
		.WORD	byte_51F92
		.BYTE	$F5,$2A		; ACMDF5	$2A
		.BYTE	$FA		; AJSR	0x00051FA5
		.WORD	byte_51FA5
		.BYTE	$F5,$29		; ACMDF5	$29
		.BYTE	$FA		; AJSR	0x00051FA5
		.WORD	byte_51FA5
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	0x00051FD8
		.WORD	byte_51FD8
		.BYTE	$FA		; AJSR	0x00051FD8
		.WORD	byte_51FD8
		.BYTE	$F5,$28		; ACMDF5	$28
		.BYTE	$FA		; AJSR	0x00051FD8
		.WORD	byte_51FD8
		.BYTE	$F5,$30		; ACMDF5	$30
		.BYTE	$FA		; AJSR	0x00051F92
		.WORD	byte_51F92
		.BYTE	$FA		; AJSR	0x00051FE4
		.WORD	byte_51FE4
		.BYTE	$F8		; AJMP	_mus7_E
		.WORD	_mus7_E
		.BYTE	$FF		; ASTOP
byte_51E97:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$0A		; ACMDF5	$0A
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$67,$47,$04	; ADATA
		.BYTE	$F4,$A8		; ACMDF4	$A8
		.BYTE	$25,$25,$30,$25	; ADATA
		.BYTE	$FB		; ARET
byte_51EA7:
		.BYTE	$70		; ADATA
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F6,$12		; ACMDF6	$12
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$38		; ACMDF5	$38
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09,$06,$02,$00	; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05,$06,$1D,$01	; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$02,$16,$00,$16,$02,$1A,$00,$16 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$11		; ACMDF6	$11
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F5,$2C		; ACMDF5	$2C
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$C0,$09		; ADATAEX
		.BYTE	$1F,$1E,$3D,$3B	; ADATA
		.BYTE	$F6,$0F		; ACMDF6	$0F
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$09,$1A,$1D,$00,$22,$20 ;	ADATA
		.BYTE	$FB		; ARET
byte_51EEB:
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$67,$65		; ADATA
		.BYTE	$CA,$01		; ADATAEX
		.BYTE	$CB,$13		; ADATAEX
		.BYTE	$67		; ADATA
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$07,$02,$05,$07,$05,$1F,$02,$05,$02,$1B,$1F,$02,$07,$02,$05,$07 ;	ADATA
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$62		; ADATA
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$05,$1D,$00,$05	; ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$39,$05,$00	; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$65		; ADATA
		.BYTE	$FB		; ARET
byte_51F30:
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$62,$67		; ADATA
		.BYTE	$CA,$02		; ADATAEX
		.BYTE	$CB,$08		; ADATAEX
		.BYTE	$0E,$07,$25,$22	; ADATA
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$60		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$62		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$7F		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$79		; ADATA
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$5B,$59,$3F,$5B,$56,$39 ;	ADATA
		.BYTE	$FB		; ARET
byte_51F5F:
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F5,$3F		; ACMDF5	$3F
		.BYTE	$19,$16,$1B,$16,$1D,$16,$1E,$16,$1F,$16,$02,$16,$19,$1A,$1B,$13 ;	ADATA
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C6,$01		; ADATAEX
		.BYTE	$C7,$13		; ADATAEX
		.BYTE	$6E		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$25		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$04,$03		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$22		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$39		; ADATA
		.BYTE	$FB		; ARET
byte_51F92:
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F6,$0D		; ACMDF6	$0D
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$27,$1F,$02,$28,$00,$03,$29,$01,$04,$2A,$02,$05 ;	ADATA
		.BYTE	$FB		; ARET
byte_51FA5:
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F6,$27		; ACMDF6	$27
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$D8,$23		; ADATAEX
		.BYTE	$1B,$76,$51,$12	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$7B		; ADATA
		.BYTE	$DD,$02		; ADATAEX
		.BYTE	$DE,$08		; ADATAEX
		.BYTE	$1D,$1C		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$7B,$76		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$A4		; ADATA
		.BYTE	$C1,$03		; ADATAEX
		.BYTE	$C0,$03		; ADATAEX
		.BYTE	$DF,$04		; ADATAEX
		.BYTE	$DE,$28		; ADATAEX
		.BYTE	$F6,$16		; ACMDF6	$16
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$7B,$22		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$00,$0A,$69,$60	; ADATA
		.BYTE	$FB		; ARET
byte_51FD8:
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$02,$07,$0E	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$07		; ADATA
		.BYTE	$FB		; ARET
byte_51FE4:
		.BYTE	$29,$01,$04,$2A,$02,$05 ;	ADATA
		.BYTE	$F6,$29		; ACMDF6	$29
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$03,$00,$1C,$1A,$1C,$1A,$17,$14 ;	ADATA
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
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$FA		; AJSR	0x0005202D
		.WORD	byte_5202D
byte_5200E:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x00052047
		.WORD	byte_52047
		.BYTE	$FA		; AJSR	0x0005205A
		.WORD	byte_5205A
		.BYTE	$FA		; AJSR	0x00052070
		.WORD	byte_52070
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00052047
		.WORD	byte_52047
		.BYTE	$FA		; AJSR	0x0005205A
		.WORD	byte_5205A
		.BYTE	$FA		; AJSR	0x00052079
		.WORD	byte_52079
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	0x00052082
		.WORD	byte_52082
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x0005200E
		.WORD	byte_5200E
		.BYTE	$FF		; ASTOP
byte_5202D:
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$DF,$03		; ADATAEX
		.BYTE	$DF,$04		; ADATAEX
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F,$5F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5F,$3F,$1F	; ADATA
		.BYTE	$FB		; ARET
byte_52047:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$BF		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$BE		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$2F,$1F,$5F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$BE		; ADATA
		.BYTE	$FB		; ARET
byte_5205A:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$BF		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$5F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F		; ADATA
		.BYTE	$FB		; ARET
byte_52070:
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F		; ADATA
		.BYTE	$FB		; ARET
byte_52079:
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F,$1F,$1F,$1F,$1E ; ADATA
		.BYTE	$FB		; ARET
byte_52082:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F,$1F,$5F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$9F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F,$1F,$5F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F		; ADATA
		.BYTE	$FB		; ARET
_mus8_B:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FA		; AJSR	0x000520C7
		.WORD	byte_520C7
byte_520A8:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x000520D7
		.WORD	byte_520D7
		.BYTE	$FA		; AJSR	0x000520F4
		.WORD	byte_520F4
		.BYTE	$FA		; AJSR	0x0005210C
		.WORD	byte_5210C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000520D7
		.WORD	byte_520D7
		.BYTE	$FA		; AJSR	0x000520F4
		.WORD	byte_520F4
		.BYTE	$FA		; AJSR	0x00052113
		.WORD	byte_52113
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	0x0005211B
		.WORD	byte_5211B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x000520A8
		.WORD	byte_520A8
		.BYTE	$FF		; ASTOP
byte_520C7:
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$C6,$03		; ADATAEX
		.BYTE	$C6,$04		; ADATAEX
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$26,$46,$0E	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$46,$26,$06	; ADATA
		.BYTE	$FB		; ARET
byte_520D7:
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$4D		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$44		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$0D,$2D		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04		; ADATA
		.BYTE	$FB		; ARET
byte_520F4:
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$4D		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$2D,$0D		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$4D		; ADATA
		.BYTE	$FB		; ARET
byte_5210C:
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$4D		; ADATA
		.BYTE	$FB		; ARET
byte_52113:
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24,$04,$04,$06,$08 ; ADATA
		.BYTE	$FB		; ARET
byte_5211B:
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$4D		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24,$04		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$2D		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$24		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$44		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$24		; ADATA
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$06		; ADATA
		.BYTE	$FB		; ARET
_mus8_C:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$D0,$7F		; ADATAEX
byte_52143:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	0x00052195
		.WORD	byte_52195
		.BYTE	$FA		; AJSR	0x000521AA
		.WORD	byte_521AA
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$FA		; AJSR	0x000521C1
		.WORD	byte_521C1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$FA		; AJSR	0x000521EB
		.WORD	byte_521EB
		.BYTE	$FA		; AJSR	0x0005221D
		.WORD	byte_5221D
		.BYTE	$B0		; ADATA
		.BYTE	$FA		; AJSR	0x00052223
		.WORD	byte_52223
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$FA		; AJSR	0x00052223
		.WORD	byte_52223
		.BYTE	$FA		; AJSR	0x000521EB
		.WORD	byte_521EB
		.BYTE	$FA		; AJSR	0x00052233
		.WORD	byte_52233
		.BYTE	$D0,$12		; ADATAEX
		.BYTE	$FA		; AJSR	0x00052223
		.WORD	byte_52223
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$FA		; AJSR	0x00052223
		.WORD	byte_52223
		.BYTE	$F8		; AJMP	0x000522B4
		.WORD	byte_522B4
byte_52179:
		.BYTE	$FA		; AJSR	0x0005223F
		.WORD	byte_5223F
		.BYTE	$FA		; AJSR	0x00052251
		.WORD	byte_52251
		.BYTE	$FA		; AJSR	0x0005223F
		.WORD	byte_5223F
		.BYTE	$FA		; AJSR	0x0005225C
		.WORD	byte_5225C
		.BYTE	$FA		; AJSR	0x0005223F
		.WORD	byte_5223F
		.BYTE	$FA		; AJSR	0x00052251
		.WORD	byte_52251
		.BYTE	$FA		; AJSR	0x0005223F
		.WORD	byte_5223F
		.BYTE	$FA		; AJSR	0x0005226C
		.WORD	byte_5226C
		.BYTE	$F8		; AJMP	0x00052289
		.WORD	byte_52289
		.BYTE	$FF		; ASTOP
byte_52195:
		.BYTE	$F6,$25		; ACMDF6	$25
		.BYTE	$F4,$80		; ACMDF4	$80
		.BYTE	$44,$43		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$22,$03,$22,$01	; ADATA
		.BYTE	$F4,$80		; ACMDF4	$80
		.BYTE	$40,$5F		; ADATA
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$5E,$5F		; ADATA
		.BYTE	$FB		; ARET
byte_521AA:
		.BYTE	$F4,$80		; ACMDF4	$80
		.BYTE	$40,$5F,$5D,$5B	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$3D		; ADATA
		.BYTE	$F4,$80		; ACMDF4	$80
		.BYTE	$5F		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$58		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$18,$3B,$18	; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FB		; ARET
byte_521C1:
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$0B		; ACMDF6	$0B
		.BYTE	$84,$04,$90	; ADATA
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$DF,$06		; ADATAEX
		.BYTE	$C7,$06		; ADATAEX
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$21		; ACMDF6	$21
		.BYTE	$F4,$90		; ACMDF4	$90
		.BYTE	$18,$5D,$5F	; ADATA
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$9D,$5B		; ADATA
		.BYTE	$D0,$32		; ADATAEX
		.BYTE	$FB		; ARET
byte_521EB:
		.BYTE	$50		; ADATA
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$38,$10,$5F,$38,$10,$5D,$B0,$38,$10,$5B,$38,$10,$5D,$38,$10 ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$DF,$1D		; ADATAEX
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$C1,$01		; ADATAEX
		.BYTE	$C2,$00		; ADATAEX
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$15		; ACMDF3	$15
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FB		; ARET
byte_5221D:
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$5D		; ADATA
		.BYTE	$FB		; ARET
byte_52223:
		.BYTE	$F4,$DE		; ACMDF4	$DE
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F6,$08		; ACMDF6	$08
		.BYTE	$2B,$0B,$30,$0B,$30,$0B,$29,$0B,$49 ; ADATA
		.BYTE	$FB		; ARET
byte_52233:
		.BYTE	$F4,$FC		; ACMDF4	$FC
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$C4,$06		; ADATAEX
		.BYTE	$C2,$06		; ADATAEX
		.BYTE	$5F		; ADATA
		.BYTE	$FB		; ARET
byte_5223F:
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F6,$27		; ACMDF6	$27
		.BYTE	$F4,$E9		; ACMDF4	$E9
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$20,$10,$20,$00,$20,$22,$10,$20,$10 ; ADATA
		.BYTE	$FB		; ARET
byte_52251:
		.BYTE	$DF,$41		; ADATAEX
		.BYTE	$9F,$3D,$10,$3F,$10 ; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$00		; ADATA
		.BYTE	$FB		; ARET
byte_5225C:
		.BYTE	$DF,$00		; ADATAEX
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$1E		; ACMDF3	$1E
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$DD,$5A		; ADATAEX
		.BYTE	$FB		; ARET
byte_5226C:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DF,$23		; ADATAEX
		.BYTE	$C9,$01		; ADATAEX
		.BYTE	$CA,$01		; ADATAEX
		.BYTE	$CB,$1C		; ADATAEX
		.BYTE	$09,$0B,$09,$07,$04,$02,$04,$07,$04,$02,$1F,$03 ;	ADATA
		.BYTE	$FB		; ARET
_mus8_D:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$D0,$7F		; ADATAEX
byte_52289:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	byte_522C5
		.WORD	byte_522C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$FA		; AJSR	byte_522D0
		.WORD	byte_522D0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	byte_522C5
		.WORD	byte_522C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	byte_522FF
		.WORD	byte_522FF
		.BYTE	$FA		; AJSR	byte_52308
		.WORD	byte_52308
		.BYTE	$D0,$2D		; ADATAEX
		.BYTE	$FA		; AJSR	byte_52308
		.WORD	byte_52308
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	byte_52179
		.WORD	byte_52179
byte_522B4:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FA		; AJSR	0x00052316
		.WORD	byte_52316
		.BYTE	$F5,$1A		; ACMDF5	$1A
		.BYTE	$FA		; AJSR	0x00052316
		.WORD	byte_52316
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x00052143
		.WORD	byte_52143
		.BYTE	$FF		; ASTOP
byte_522C5:
		.BYTE	$F4,$A6		; ACMDF4	$A6
		.BYTE	$38,$1F,$3F,$18,$3F,$1F,$38,$1F ;	ADATA
		.BYTE	$FB		; ARET
byte_522D0:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$83,$03,$B0	; ADATA
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DD,$01		; ADATAEX
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F4,$DE		; ACMDF4	$DE
		.BYTE	$DF,$0D		; ADATAEX
		.BYTE	$3D,$1B,$3D,$1B,$38,$16 ;	ADATA
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$58,$58		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$9D,$1B		; ADATA
		.BYTE	$F4,$F0		; ACMDF4	$F0
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$38,$1F,$24,$18,$04,$04,$04,$22,$04 ; ADATA
		.BYTE	$FB		; ARET
byte_522FF:
		.BYTE	$F4,$BC		; ACMDF4	$BC
		.BYTE	$3F,$09,$2B,$1F,$29,$0B ;	ADATA
		.BYTE	$FB		; ARET
byte_52308:
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F4,$DE		; ACMDF4	$DE
		.BYTE	$24,$04,$30,$04,$30,$04,$22,$04,$42 ; ADATA
		.BYTE	$FB		; ARET
byte_52316:
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$58,$40,$38,$00,$20,$1B,$38,$1B,$20,$18,$38,$00,$38,$14 ;	ADATA
		.BYTE	$FB		; ARET
_mus8_E:
		.BYTE	$F2,$05		; ACMDF2	$05
		.BYTE	$D0,$7F		; ADATAEX
byte_5232F:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F6,$26		; ACMDF6	$26
		.BYTE	$FA		; AJSR	0x00052360
		.WORD	byte_52360
		.BYTE	$FA		; AJSR	0x00052373
		.WORD	byte_52373
		.BYTE	$FA		; AJSR	0x00052386
		.WORD	byte_52386
		.BYTE	$FA		; AJSR	0x00052360
		.WORD	byte_52360
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x000523AC
		.WORD	byte_523AC
		.BYTE	$FA		; AJSR	0x000523E3
		.WORD	byte_523E3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FA		; AJSR	0x0005241D
		.WORD	byte_5241D
		.BYTE	$F5,$0E		; ACMDF5	$0E
		.BYTE	$FA		; AJSR	0x0005241D
		.WORD	byte_5241D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	0x0005232F
		.WORD	byte_5232F
		.BYTE	$FF		; ASTOP
byte_52360:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$58,$58		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$9D,$1B		; ADATA
		.BYTE	$F4,$C8		; ACMDF4	$C8
		.BYTE	$58,$50,$33,$1B,$30 ; ADATA
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$13		; ADATA
		.BYTE	$FB		; ARET
byte_52373:
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$5F,$40,$5F,$40	; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$3F,$1D		; ADATA
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$5B		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$3D,$1B,$58	; ADATA
		.BYTE	$FB		; ARET
byte_52386:
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$3B,$1D		; ADATA
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$5F,$30,$13	; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$DF,$09		; ADATAEX
		.BYTE	$10		; ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DD,$01		; ADATAEX
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$F4,$DE		; ACMDF4	$DE
		.BYTE	$DF,$0D		; ADATAEX
		.BYTE	$3D,$1B		; ADATA
		.BYTE	$DC,$01		; ADATAEX
		.BYTE	$DD,$09		; ADATAEX
		.BYTE	$1B,$38,$16	; ADATA
		.BYTE	$FB		; ARET
byte_523AC:
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C2,$01		; ADATAEX
		.BYTE	$C3,$01		; ADATAEX
		.BYTE	$C4,$08		; ADATAEX
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$1F,$58,$30,$18,$5F,$30,$18,$5D ;	ADATA
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DD,$01		; ADATAEX
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$DF,$0D		; ADATAEX
		.BYTE	$3D,$1B,$3D,$1B,$58,$30,$18 ; ADATA
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$DF,$0E		; ADATAEX
		.BYTE	$30,$18		; ADATA
		.BYTE	$DC,$01		; ADATAEX
		.BYTE	$DD,$0E		; ADATAEX
		.BYTE	$F4,$B1		; ACMDF4	$B1
		.BYTE	$38		; ADATA
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$13,$18,$1B,$1D	; ADATA
		.BYTE	$FB		; ARET
byte_523E3:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DD,$01		; ADATAEX
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$DF,$0D		; ADATAEX
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30,$18		; ADATA
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$DF,$0E		; ADATAEX
		.BYTE	$30,$18		; ADATA
		.BYTE	$DC,$01		; ADATAEX
		.BYTE	$DD,$0E		; ADATAEX
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$DD,$01		; ADATAEX
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$F4,$FA		; ACMDF4	$FA
		.BYTE	$DF,$0D		; ADATAEX
		.BYTE	$3D,$1B,$3D,$1B,$58,$30,$18 ; ADATA
		.BYTE	$DE,$01		; ADATAEX
		.BYTE	$DF,$0E		; ADATAEX
		.BYTE	$30,$18		; ADATA
		.BYTE	$DC,$01		; ADATAEX
		.BYTE	$DD,$0E		; ADATAEX
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$50,$33,$02	; ADATA
		.BYTE	$FB		; ARET
byte_5241D:
		.BYTE	$F4,$9B		; ACMDF4	$9B
		.BYTE	$54,$40,$54	; ADATA
		.BYTE	$F4,$E6		; ACMDF4	$E6
		.BYTE	$20,$00,$34,$00,$20,$14,$34,$00,$34,$00 ;	ADATA
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
		.BYTE	$F2,$02		; ACMDF2	$02
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$DF,$09		; ADATAEX
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$DA,$37		; ADATAEX
		.BYTE	$5D		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3C		; ADATA
		.BYTE	$F8		; AJMP	_mus9_A
		.WORD	_mus9_A
		.BYTE	$FF		; ASTOP
_mus9_B:
		.BYTE	$F2,$02		; ACMDF2	$02
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$19		; ACMDF6	$19
		.BYTE	$4D		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$05		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$C5,$11		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$05		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$C6,$07		; ADATAEX
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$27		; ADATA
		.BYTE	$F4,$B4		; ACMDF4	$B4
		.BYTE	$F6,$1B		; ACMDF6	$1B
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$CB,$09		; ADATAEX
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$C7,$0F		; ADATAEX
		.BYTE	$0A		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$29		; ADATA
		.BYTE	$F8		; AJMP	_mus9_B
		.WORD	_mus9_B
		.BYTE	$FF		; ASTOP
_mus9_C:
		.BYTE	$F2,$02		; ACMDF2	$02
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$2B		; ACMDF6	$2B
		.BYTE	$70,$75,$78,$7B,$BE,$B8,$9D ; ADATA
		.BYTE	$D0,$A0		; ADATAEX
		.BYTE	$75,$78,$7B,$BE,$A1,$9D ;	ADATA
		.BYTE	$D0,$A0		; ADATAEX
		.BYTE	$75,$78,$7B,$BE,$B8,$9D ;	ADATA
		.BYTE	$D0,$A0		; ADATAEX
		.BYTE	$75,$78,$7B,$BE,$61,$64,$9D,$90 ;	ADATA
		.BYTE	$DB,$60		; ADATAEX
		.BYTE	$79		; ADATA
		.BYTE	$D8,$60		; ADATAEX
		.BYTE	$79		; ADATA
		.BYTE	$DB,$60		; ADATAEX
		.BYTE	$7D		; ADATA
		.BYTE	$F6,$AB		; ACMDF6	$AB
		.BYTE	$DE,$00		; ADATAEX
		.BYTE	$F1,$00		; ACMDF1	$00
		.BYTE	$F3,$80		; ACMDF3	$80
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F3,$10		; ACMDF3	$10
		.BYTE	$FD		; ALOOP_END
		.BYTE	$B0		; ADATA
		.BYTE	$F6,$1A		; ACMDF6	$1A
		.BYTE	$F0,$06		; ACMDF0	$06
		.BYTE	$F5,$3F		; ACMDF5	$3F
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	byte_524F1
		.WORD	byte_524F1
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FA		; AJSR	byte_524F1
		.WORD	byte_524F1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX
		.BYTE	$F8		; AJMP	_mus9_C
		.WORD	_mus9_C
		.BYTE	$FF		; ASTOP
byte_524F1:
		.BYTE	$69,$66,$63,$60,$7D,$7A,$77,$76,$77,$7A,$7D,$60,$63,$66 ;	ADATA
		.BYTE	$FB		; ARET
_mus9_D:
		.BYTE	$F2,$02		; ACMDF2	$02
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$F6,$2B		; ACMDF6	$2B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$B0,$75,$78,$BB,$B5,$99 ;	ADATA
		.BYTE	$D0,$C0		; ADATAEX
		.BYTE	$75,$78,$BB,$BE,$99,$90 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D8,$60		; ADATAEX
		.BYTE	$76		; ADATA
		.BYTE	$D5,$60		; ADATAEX
		.BYTE	$76		; ADATA
		.BYTE	$D8,$60		; ADATAEX
		.BYTE	$79		; ADATA
		.BYTE	$F6,$AB		; ACMDF6	$AB
		.BYTE	$DB,$00		; ADATAEX
		.BYTE	$F1,$00		; ACMDF1	$00
		.BYTE	$F3,$80		; ACMDF3	$80
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F3,$10		; ACMDF3	$10
		.BYTE	$FD		; ALOOP_END
		.BYTE	$B0		; ADATA
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	byte_524F1
		.WORD	byte_524F1
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FA		; AJSR	byte_524F1
		.WORD	byte_524F1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX
		.BYTE	$F8		; AJMP	_mus9_D
		.WORD	_mus9_D
		.BYTE	$FF		; ASTOP
_mus9_E:
		.BYTE	$F2,$02		; ACMDF2	$02
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$16		; ACMDF5	$16
byte_5255C:
		.BYTE	$A2		; ADATA
		.BYTE	$F8		; AJMP	0x0005255C
		.WORD	byte_5255C
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
		.BYTE	$F2,$03		; ACMDF2	$03
byte_52573:
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E,$5E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1E		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$5F,$7F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$5E,$3E,$1E	; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$3F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$7E		; ADATA
		.BYTE	$F8		; AJMP	0x00052573
		.WORD	byte_52573
		.BYTE	$FF		; ASTOP
_musA_B:
		.BYTE	$F2,$03		; ACMDF2	$03
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FA		; AJSR	0x000525B1
		.WORD	byte_525B1
		.BYTE	$FA		; AJSR	0x000525C8
		.WORD	byte_525C8
		.BYTE	$FA		; AJSR	0x000525B1
		.WORD	byte_525B1
		.BYTE	$FA		; AJSR	0x000525E1
		.WORD	byte_525E1
		.BYTE	$F8		; AJMP	_musA_B
		.WORD	_musA_B
		.BYTE	$FF		; ASTOP
byte_525B1:
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$04		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04,$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FB		; ARET
byte_525C8:
		.BYTE	$0F,$04		; ADATA
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$03		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04,$0F		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FB		; ARET
byte_525E1:
		.BYTE	$0F		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$15		; ACMDF6	$15
		.BYTE	$03		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0F		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$06		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$04,$04,$06	; ADATA
		.BYTE	$FB		; ARET
_musA_C:
		.BYTE	$F2,$03		; ACMDF2	$03
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F4,$00		; ACMDF4	$00
byte_525FC:
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$CB,$40		; ADATAEX
		.BYTE	$CC,$40		; ADATAEX
		.BYTE	$66,$6C		; ADATA
		.BYTE	$CB,$40		; ADATAEX
		.BYTE	$C7,$40		; ADATAEX
		.BYTE	$C9,$40		; ADATAEX
		.BYTE	$66,$69		; ADATA
		.BYTE	$C7,$40		; ADATAEX
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F8		; AJMP	0x000525FC
		.WORD	byte_525FC
		.BYTE	$FF		; ASTOP
_musA_D:
		.BYTE	$F2,$03		; ACMDF2	$03
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F4,$00		; ACMDF4	$00
byte_5261C:
		.BYTE	$F6,$1C		; ACMDF6	$1C
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$DB,$40		; ADATAEX
		.BYTE	$DD,$40		; ADATAEX
		.BYTE	$77,$7D		; ADATA
		.BYTE	$DB,$40		; ADATAEX
		.BYTE	$D8,$40		; ADATAEX
		.BYTE	$D4,$40		; ADATAEX
		.BYTE	$73,$77		; ADATA
		.BYTE	$D8,$40		; ADATAEX
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F8		; AJMP	0x0005261C
		.WORD	byte_5261C
		.BYTE	$FF		; ASTOP
_musA_E:
		.BYTE	$F2,$03		; ACMDF2	$03
		.BYTE	$F6,$03		; ACMDF6	$03
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FC,$10		; ALOOP_START $10
		.BYTE	$70		; ADATA
		.BYTE	$FD		; ALOOP_END
byte_52644:
		.BYTE	$C4,$C8		; ADATAEX
		.BYTE	$C4,$38		; ADATAEX
		.BYTE	$F8		; AJMP	0x00052644
		.WORD	byte_52644
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
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00052671
		.WORD	byte_52671
		.BYTE	$FA		; AJSR	0x0005268D
		.WORD	byte_5268D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00052671
		.WORD	byte_52671
		.BYTE	$FA		; AJSR	0x000526AA
		.WORD	byte_526AA
		.BYTE	$F8		; AJMP	_musB_A
		.WORD	_musB_A
		.BYTE	$FF		; ASTOP
byte_52671:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$1F,$1F,$1F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$3F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1D,$1F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$FB		; ARET
byte_5268D:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$1F,$1F,$1F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1D,$1F,$1C	; ADATA
		.BYTE	$FB		; ARET
byte_526AA:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F,$1F,$1F	; ADATA
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1D,$1F		; ADATA
		.BYTE	$E0,$F6,$08	; ACMDE0	$F6,$08
		.BYTE	$1F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F,$1F,$1F,$1F	; ADATA
		.BYTE	$FB		; ARET
_musB_B:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x000526DD
		.WORD	byte_526DD
		.BYTE	$FA		; AJSR	0x000526F8
		.WORD	byte_526F8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000526DD
		.WORD	byte_526DD
		.BYTE	$FA		; AJSR	0x00052711
		.WORD	byte_52711
		.BYTE	$F8		; AJMP	_musB_B
		.WORD	_musB_B
		.BYTE	$FF		; ASTOP
byte_526DD:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$03		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$06		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04		; ADATA
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04		; ADATA
		.BYTE	$FB		; ARET
byte_526F8:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$03		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$04		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$06		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$04,$05		; ADATA
		.BYTE	$FB		; ARET
byte_52711:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6	$13
		.BYTE	$04,$04,$04	; ADATA
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$06		; ADATA
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$24		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$20		; ACMDF6	$20
		.BYTE	$03,$04,$05,$06	; ADATA
		.BYTE	$FB		; ARET
_musB_C:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$13		; ACMDF5	$13
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00052772
		.WORD	byte_52772
		.BYTE	$FA		; AJSR	0x0005277C
		.WORD	byte_5277C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00052772
		.WORD	byte_52772
		.BYTE	$FA		; AJSR	0x00052781
		.WORD	byte_52781
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00052772
		.WORD	byte_52772
		.BYTE	$FA		; AJSR	0x0005277C
		.WORD	byte_5277C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00052772
		.WORD	byte_52772
		.BYTE	$FA		; AJSR	0x00052781
		.WORD	byte_52781
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$F5,$1A		; ACMDF5	$1A
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$F5,$1A		; ACMDF5	$1A
		.BYTE	$FA		; AJSR	0x00052786
		.WORD	byte_52786
		.BYTE	$FA		; AJSR	0x00052797
		.WORD	byte_52797
		.BYTE	$F8		; AJMP	_musB_C
		.WORD	_musB_C
		.BYTE	$FF		; ASTOP
byte_52772:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07,$01,$01,$01,$01,$01 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
byte_5277C:
		.BYTE	$07,$01,$01,$06	; ADATA
		.BYTE	$FB		; ARET
byte_52781:
		.BYTE	$07,$01,$0A,$0B	; ADATA
		.BYTE	$FB		; ARET
byte_52786:
		.BYTE	$1B,$15,$1B,$1D,$1E,$01,$04,$1D,$1B,$15,$1B,$1D,$1E,$12,$03,$04 ;	ADATA
		.BYTE	$FB		; ARET
byte_52797:
		.BYTE	$1E,$18,$04,$01,$07,$04,$06,$07,$1E,$0D,$0A,$04,$0A,$07,$04,$01 ;	ADATA
		.BYTE	$FB		; ARET
_musB_D:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$24		; ACMDF6	$24
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$03		; ACMDF5	$03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x000527ED
		.WORD	byte_527ED
		.BYTE	$FA		; AJSR	0x000527F7
		.WORD	byte_527F7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000527ED
		.WORD	byte_527ED
		.BYTE	$FA		; AJSR	0x000527FC
		.WORD	byte_527FC
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$FA		; AJSR	0x000527ED
		.WORD	byte_527ED
		.BYTE	$FA		; AJSR	0x000527F7
		.WORD	byte_527F7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x000527ED
		.WORD	byte_527ED
		.BYTE	$FA		; AJSR	0x000527FC
		.WORD	byte_527FC
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$22		; ACMDF6	$22
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00052801
		.WORD	byte_52801
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$26		; ACMDF5	$26
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00052801
		.WORD	byte_52801
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_musB_D
		.WORD	_musB_D
		.BYTE	$FF		; ASTOP
byte_527ED:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B,$05,$05,$05,$05,$05 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
byte_527F7:
		.BYTE	$0B,$05,$05,$0A	; ADATA
		.BYTE	$FB		; ARET
byte_527FC:
		.BYTE	$0B,$05,$0E,$0F	; ADATA
		.BYTE	$FB		; ARET
byte_52801:
		.BYTE	$30,$5E,$1E,$3E,$3E,$5E,$1E,$3E ;	ADATA
		.BYTE	$FB		; ARET
_musB_E:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$22		; ACMDF6	$22
		.BYTE	$F5,$03		; ACMDF5	$03
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x0005284D
		.WORD	byte_5284D
		.BYTE	$FA		; AJSR	0x00052857
		.WORD	byte_52857
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x0005284D
		.WORD	byte_5284D
		.BYTE	$FA		; AJSR	0x0005285C
		.WORD	byte_5285C
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x0005284D
		.WORD	byte_5284D
		.BYTE	$FA		; AJSR	0x00052857
		.WORD	byte_52857
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x0005284D
		.WORD	byte_5284D
		.BYTE	$FA		; AJSR	0x0005285C
		.WORD	byte_5285C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00052861
		.WORD	byte_52861
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$26		; ACMDF5	$26
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	0x00052861
		.WORD	byte_52861
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_musB_E
		.WORD	_musB_E
		.BYTE	$FF		; ASTOP
byte_5284D:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B,$05,$05,$05,$05,$05 ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
byte_52857:
		.BYTE	$0B,$05,$05,$0A	; ADATA
		.BYTE	$FB		; ARET
byte_5285C:
		.BYTE	$0B,$05,$0E,$0F	; ADATA
		.BYTE	$FB		; ARET
byte_52861:
		.BYTE	$30,$44,$04,$24,$24,$44,$04,$24 ;	ADATA
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
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$2B		; ACMDF5	$2B
		.BYTE	$E1,$01		; ACMDE1	$01
		.BYTE	$09,$07,$04,$0B,$09,$0E,$03 ; ADATA
		.BYTE	$E1,$00		; ACMDE1	$00
		.BYTE	$FF		; ASTOP
_snd01_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$18		; ACMDF5	$18
		.BYTE	$13,$1A,$15,$1C,$16,$1D,$16,$1D,$1C,$04 ;	ADATA
		.BYTE	$F5,$35		; ACMDF5	$35
		.BYTE	$F1,$F8		; ACMDF1	$F8
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$16,$1F,$0D	; ADATA
		.BYTE	$FF		; ASTOP
_snd02_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$80		; ACMDF6	$80
		.BYTE	$0A,$0D,$0B	; ADATA
		.BYTE	$CE,$00		; ADATAEX
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$FE		; ACMDE3	$FE
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd02_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$03		; ACMDF6	$03
		.BYTE	$31,$14,$01	; ADATA
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$17,$04		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$1A		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$07		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$1D		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0A		; ADATA
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$F5,$35		; ACMDF5	$35
		.BYTE	$18,$05,$06	; ADATA
		.BYTE	$FF		; ASTOP
_snd03_E:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$DC		; ACMDF4	$DC
		.BYTE	$F6,$14		; ACMDF6	$14
		.BYTE	$05,$06,$07,$28	; ADATA
		.BYTE	$F0,$00		; ACMDF0	$00
		.BYTE	$AF		; ADATA
		.BYTE	$FF		; ASTOP
_snd03_C:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$23		; ACMDF6	$23
		.BYTE	$1E,$1B,$00,$39	; ADATA
		.BYTE	$FF		; ASTOP
_snd03_D:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$1F		; ACMDF6	$1F
		.BYTE	$1E,$1B,$00,$39	; ADATA
		.BYTE	$FF		; ASTOP
_snd03_A:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$FF		; ACMDF4	$FF
		.BYTE	$1E,$1B,$00,$39	; ADATA
		.BYTE	$FF		; ASTOP
_snd03_B:
		.BYTE	$F2,$04		; ACMDF2	$04
		.BYTE	$E0,$F8,$1C	; ACMDE0	$F8,$1C
		.BYTE	$1F,$1E,$1D,$3C	; ADATA
		.BYTE	$FF		; ASTOP
_snd04_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F0,$00		; ACMDF0	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$21		; ACMDF5	$21
		.BYTE	$C2,$00		; ADATAEX
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$EC		; ACMDE3	$EC
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$FA		; ACMDE3	$FA
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$08		; ACMDE3	$08
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F5,$38		; ACMDF5	$38
		.BYTE	$3E,$70,$2A	; ADATA
		.BYTE	$FF		; ASTOP
_snd04_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FA		; AJSR	0x00052A42
		.WORD	byte_52A42
		.BYTE	$F5,$03		; ACMDF5	$03
		.BYTE	$FA		; AJSR	0x00052A42
		.WORD	byte_52A42
		.BYTE	$F1,$FB		; ACMDF1	$FB
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
byte_52A42:
		.BYTE	$09,$07,$05,$03,$01,$1F ;	ADATA
		.BYTE	$FB		; ARET
_snd05_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$14		; ACMDF5	$14
		.BYTE	$2B,$28		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$24,$20		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$3D,$3A		; ADATA
		.BYTE	$FF		; ASTOP
_snd05_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$26,$09,$0B,$4D	; ADATA
		.BYTE	$FF		; ASTOP
_snd06_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$C1,$00		; ADATAEX
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$05,$07,$08	; ADATA
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$0E,$0D,$0B	; ADATA
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd06_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$0E,$0F,$0C,$0D,$0A,$0B ;	ADATA
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$0F,$0B,$0A	; ADATA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$1B,$00,$17,$10,$1C,$16,$1B ; ADATA
		.BYTE	$F1,$FC		; ACMDF1	$FC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd07_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F6,$03		; ACMDF6	$03
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$11,$12,$15,$18,$19,$1C,$1F,$1D,$00 ; ADATA
		.BYTE	$F5,$11		; ACMDF5	$11
		.BYTE	$1E,$01,$02,$03	; ADATA
		.BYTE	$FF		; ASTOP
_snd07_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$4E,$4D,$4C	; ADATA
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$0C,$0B,$0A	; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$09,$08,$07	; ADATA
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$06,$05		; ADATA
		.BYTE	$FF		; ASTOP
_snd08_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$35		; ACMDF5	$35
		.BYTE	$1B,$1C,$1D,$1F,$01 ; ADATA
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$03,$04		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$3C		; ACMDF5	$3C
		.BYTE	$10		; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$19,$1A,$1B,$30	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$18,$19,$1A,$10,$16,$17,$18,$10 ;	ADATA
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$15,$16,$17	; ADATA
		.BYTE	$FF		; ASTOP
_snd09_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$02		; ACMDF0	$02
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$20		; ACMDF5	$20
		.BYTE	$D4,$00		; ADATAEX
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$EB		; ACMDE3	$EB
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
byte_52B27:
		.BYTE	$E3,$20		; ACMDE3	$20
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$E3,$E0		; ACMDE3	$E0
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$E3,$2C		; ACMDE3	$2C
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$E3,$D4		; ACMDE3	$D4
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F8		; AJMP	0x00052B27
		.WORD	byte_52B27
		.BYTE	$FF		; ASTOP
_snd09_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
byte_52B43:
		.BYTE	$26		; ADATA
		.BYTE	$CC,$0A		; ADATAEX
		.BYTE	$A9,$4F,$47,$8F,$68 ; ADATA
		.BYTE	$F8		; AJMP	0x00052B43
		.WORD	byte_52B43
_snd0A_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$2C		; ACMDF6	$2C
		.BYTE	$F5,$3F		; ACMDF5	$3F
		.BYTE	$CB,$64		; ADATAEX
		.BYTE	$FF		; ASTOP
_snd0A_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$AF		; ADATA
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$0E		; ADATA
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$2D		; ADATA
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$2C,$0B		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$2B,$2A,$29,$28,$07 ; ADATA
		.BYTE	$FF		; ASTOP
_snd0B_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$26,$28		; ADATA
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$06,$28		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0C_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$46,$8D		; ADATA
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$46,$AD		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0D_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$00		; ACMDF0	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$C6,$00		; ADATAEX
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$F9		; ACMDE3	$F9
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$F9		; ACMDF1	$F9
		.BYTE	$E3,$F9		; ACMDE3	$F9
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$08		; ACMDF1	$08
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0E_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F5,$17		; ACMDF5	$17
		.BYTE	$10,$11,$14,$18,$1C ; ADATA
		.BYTE	$F6,$03		; ACMDF6	$03
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$01,$02,$1B	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FA		; AJSR	0x00052BF8
		.WORD	byte_52BF8
		.BYTE	$D0,$0C		; ADATAEX
		.BYTE	$F5,$0C		; ACMDF5	$0C
		.BYTE	$FA		; AJSR	0x00052BF8
		.WORD	byte_52BF8
		.BYTE	$D0,$0A		; ADATAEX
		.BYTE	$F5,$09		; ACMDF5	$09
		.BYTE	$FA		; AJSR	0x00052BF8
		.WORD	byte_52BF8
		.BYTE	$D0,$08		; ADATAEX
		.BYTE	$F5,$06		; ACMDF5	$06
		.BYTE	$FA		; AJSR	0x00052BF8
		.WORD	byte_52BF8
		.BYTE	$D0,$06		; ADATAEX
		.BYTE	$F5,$04		; ACMDF5	$04
		.BYTE	$FA		; AJSR	0x00052BF8
		.WORD	byte_52BF8
		.BYTE	$FF		; ASTOP
byte_52BF8:
		.BYTE	$10		; ADATA
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$0A,$07,$03,$1E	; ADATA
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$1E,$1A		; ADATA
		.BYTE	$FB		; ARET
_snd0E_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$14		; ACMDF5	$14
		.BYTE	$11,$14,$18,$1C	; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0A,$00,$1E	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$10		; ADATAEX
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$FA		; AJSR	0x00052C3C
		.WORD	byte_52C3C
		.BYTE	$D0,$0C		; ADATAEX
		.BYTE	$F5,$0E		; ACMDF5	$0E
		.BYTE	$FA		; AJSR	0x00052C3C
		.WORD	byte_52C3C
		.BYTE	$D0,$0A		; ADATAEX
		.BYTE	$F5,$0A		; ACMDF5	$0A
		.BYTE	$FA		; AJSR	0x00052C3C
		.WORD	byte_52C3C
		.BYTE	$D0,$08		; ADATAEX
		.BYTE	$F5,$05		; ACMDF5	$05
		.BYTE	$FA		; AJSR	0x00052C3C
		.WORD	byte_52C3C
		.BYTE	$D0,$06		; ADATAEX
		.BYTE	$F5,$04		; ACMDF5	$04
		.BYTE	$FA		; AJSR	0x00052C3C
		.WORD	byte_52C3C
		.BYTE	$FF		; ASTOP
byte_52C3C:
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$0D,$0A		; ADATA
		.BYTE	$F1,$FC		; ACMDF1	$FC
		.BYTE	$06,$01		; ADATA
		.BYTE	$F1,$FB		; ACMDF1	$FB
		.BYTE	$1C,$1D,$1B	; ADATA
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$FB		; ARET
_snd0F_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$3F		; ACMDF5	$3F
		.BYTE	$C0,$00		; ADATAEX
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$FA		; ACMDF1	$FA
		.BYTE	$E3,$FF		; ACMDE3	$FF
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$04		; ACMDF1	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd0F_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$28		; ADATA
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$22		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd10_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F5,$14		; ACMDF5	$14
		.BYTE	$13,$17,$19,$70	; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F5,$22		; ACMDF5	$22
		.BYTE	$12,$15,$18,$19	; ADATA
		.BYTE	$FF		; ASTOP
_snd11_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$21		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$02		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$04		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$06		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$08		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0D		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$04		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$05,$04		; ADATA
		.BYTE	$FF		; ASTOP
_snd12_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$0C,$0E		; ADATA
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$0D		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0C		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0B		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$09		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$08		; ADATA
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$05		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$03		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd12_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F5,$0F		; ACMDF5	$0F
		.BYTE	$11,$13		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$11		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$12		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$13		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$16		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$19		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$17		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$1A		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$1D,$1E,$1D,$1E	; ADATA
		.BYTE	$FF		; ASTOP
_snd13_A:
		.BYTE	$F5,$20		; ACMDF5	$20
byte_52D02:
		.BYTE	$F0,$03		; ACMDF0	$03
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$C7,$00		; ADATAEX
		.BYTE	$E3,$FC		; ACMDE3	$FC
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$E3,$FD		; ACMDE3	$FD
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$E3,$03		; ACMDE3	$03
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FC,$09		; ALOOP_START $09
		.BYTE	$E3,$FD		; ACMDE3	$FD
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$32		; ACMDF3	$32
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$E3,$05		; ACMDE3	$05
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$01		; ACMDF0	$01
		.BYTE	$CA,$00		; ADATAEX
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$04		; ACMDF3	$04
		.BYTE	$FC,$12		; ALOOP_START $12
		.BYTE	$E3,$02		; ACMDE3	$02
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd13_B:
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F8		; AJMP	0x00052D02
		.WORD	byte_52D02
_snd13_C:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F0,$07		; ACMDF0	$07
		.BYTE	$28,$A7,$A6	; ADATA
		.BYTE	$FC,$19		; ALOOP_START $19
		.BYTE	$07,$06		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$06,$87		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$89		; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$F0,$03		; ACMDF0	$03
		.BYTE	$A7,$A8,$A9	; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$AA		; ADATA
		.BYTE	$FF		; ASTOP
_snd14_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$0E		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0D		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0E		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0C		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0D,$0C,$0D,$0B,$0C,$0A,$0B,$09,$0A ; ADATA
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$09		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$08		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$27		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$26		; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$45		; ADATA
		.BYTE	$F0,$06		; ACMDF0	$06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd15_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$05,$07,$06,$08	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$07,$09,$08,$0A,$09,$0B,$0A,$09,$0C ; ADATA
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$0B,$0E,$0C,$0E	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$0B,$0E,$0C,$0E	; ADATA
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd16_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$07,$06,$07	; ADATA
		.BYTE	$FA		; AJSR	0x00052DF9
		.WORD	byte_52DF9
		.BYTE	$FA		; AJSR	0x00052DFF
		.WORD	byte_52DFF
		.BYTE	$F1,$FB		; ACMDF1	$FB
		.BYTE	$FA		; AJSR	0x00052DF9
		.WORD	byte_52DF9
		.BYTE	$FA		; AJSR	0x00052DFF
		.WORD	byte_52DFF
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FA		; AJSR	0x00052DF9
		.WORD	byte_52DF9
		.BYTE	$FA		; AJSR	0x00052DFF
		.WORD	byte_52DFF
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$05,$06,$07	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00052DF9
		.WORD	byte_52DF9
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	0x00052E09
		.WORD	byte_52E09
		.BYTE	$F1,$FD		; ACMDF1	$FD
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
byte_52DF9:
		.BYTE	$06,$08,$07,$08,$09 ; ADATA
		.BYTE	$FB		; ARET
byte_52DFF:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0C,$0E,$0D,$0E,$0D,$0E ;	ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
byte_52E09:
		.BYTE	$2D,$2C,$2D,$2E	; ADATA
		.BYTE	$FB		; ARET
_snd17_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$00		; ACMDF0	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F5,$2C		; ACMDF5	$2C
		.BYTE	$CE,$00		; ADATAEX
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$00		; ACMDE3	$00
		.BYTE	$F3,$03		; ACMDF3	$03
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$03		; ACMDF3	$03
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$05		; ACMDF3	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$03		; ACMDF3	$03
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$03		; ACMDF3	$03
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$04		; ACMDF3	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$01		; ACMDE3	$01
		.BYTE	$F3,$05		; ACMDF3	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd17_B:
		.BYTE	$D0,$04		; ADATAEX
		.BYTE	$F8		; AJMP	_snd17_A
		.WORD	_snd17_A
_snd18_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$03		; ACMDF0	$03
		.BYTE	$F6,$03		; ACMDF6	$03
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$24		; ACMDF5	$24
		.BYTE	$12,$13		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$16,$19		; ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$1C,$1F		; ADATA
		.BYTE	$F1,$03		; ACMDF1	$03
		.BYTE	$02,$05		; ADATA
		.BYTE	$FF		; ASTOP
_snd18_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$0D,$0E		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0D,$0C		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0B,$0C		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0B,$0A		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$09,$07		; ADATA
		.BYTE	$FF		; ASTOP
_snd19_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$2F		; ACMDF5	$2F
		.BYTE	$FA		; AJSR	0x00052EA6
		.WORD	byte_52EA6
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F5,$18		; ACMDF5	$18
		.BYTE	$FA		; AJSR	0x00052EBE
		.WORD	byte_52EBE
		.BYTE	$F5,$2F		; ACMDF5	$2F
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$FA		; AJSR	0x00052ED4
		.WORD	byte_52ED4
		.BYTE	$FF		; ASTOP
byte_52EA6:
		.BYTE	$1E,$00,$02,$05,$08,$0B ;	ADATA
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$0E,$0F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$0D,$0E,$0C,$0D,$0B,$0C,$0A,$09,$08,$09,$07,$08 ;	ADATA
		.BYTE	$FB		; ARET
byte_52EBE:
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$31,$14,$01	; ADATA
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$17,$04		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$1A		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$07		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$1D		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0A		; ADATA
		.BYTE	$FB		; ARET
byte_52ED4:
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$18,$05,$06	; ADATA
		.BYTE	$FB		; ARET
_snd19_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0D		; ACMDF0	$0D
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$2C		; ACMDF5	$2C
		.BYTE	$FA		; AJSR	byte_52EA6
		.WORD	byte_52EA6
		.BYTE	$F5,$1B		; ACMDF5	$1B
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$FA		; AJSR	byte_52EBE
		.WORD	byte_52EBE
		.BYTE	$F5,$36		; ACMDF5	$36
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$FA		; AJSR	byte_52ED4
		.WORD	byte_52ED4
		.BYTE	$FF		; ASTOP
_snd19_C:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$07,$06,$05,$04,$03,$02 ;	ADATA
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$02,$03,$01	; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$23,$24,$25,$26,$27,$28,$08,$02,$0C ; ADATA
		.BYTE	$CE,$00		; ADATAEX
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$FE		; ACMDE3	$FE
		.BYTE	$F3,$02		; ACMDF3	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd1A_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$FA		; AJSR	0x00052F38
		.WORD	byte_52F38
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	0x00052F4C
		.WORD	byte_52F4C
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$01		; ACMDF0	$01
		.BYTE	$FA		; AJSR	0x00052F4C
		.WORD	byte_52F4C
		.BYTE	$FF		; ASTOP
byte_52F38:
		.BYTE	$24,$05		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$26,$07		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$08,$09		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0A,$0B		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$0C,$0D,$2E	; ADATA
		.BYTE	$FB		; ARET
byte_52F4C:
		.BYTE	$2B,$2E,$2D,$2E,$2C,$0F ;	ADATA
		.BYTE	$FB		; ARET
_snd1A_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	0x00052F87
		.WORD	byte_52F87
		.BYTE	$F5,$23		; ACMDF5	$23
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$FA		; AJSR	0x00052F9B
		.WORD	byte_52F9B
		.BYTE	$F0,$03		; ACMDF0	$03
		.BYTE	$F5,$1D		; ACMDF5	$1D
		.BYTE	$FA		; AJSR	0x00052F9B
		.WORD	byte_52F9B
		.BYTE	$F0,$02		; ACMDF0	$02
		.BYTE	$F5,$19		; ACMDF5	$19
		.BYTE	$FA		; AJSR	0x00052F9B
		.WORD	byte_52F9B
		.BYTE	$F0,$01		; ACMDF0	$01
		.BYTE	$F5,$14		; ACMDF5	$14
		.BYTE	$FA		; AJSR	0x00052F9B
		.WORD	byte_52F9B
		.BYTE	$F5,$13		; ACMDF5	$13
		.BYTE	$FA		; AJSR	0x00052F9B
		.WORD	byte_52F9B
		.BYTE	$F5,$12		; ACMDF5	$12
		.BYTE	$FA		; AJSR	0x00052F9B
		.WORD	byte_52F9B
		.BYTE	$FF		; ASTOP
byte_52F87:
		.BYTE	$2F,$0E		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$2D,$0C		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$0A,$08		; ADATA
		.BYTE	$F1,$01		; ACMDF1	$01
		.BYTE	$06,$01		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$1C,$17,$32	; ADATA
		.BYTE	$FB		; ARET
byte_52F9B:
		.BYTE	$0F,$0E,$0D,$0C,$0A,$08,$06,$01,$1C,$17,$12 ; ADATA
		.BYTE	$FB		; ARET
_snd1A_C:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$F6,$02		; ACMDF6	$02
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$22		; ACMDF5	$22
		.BYTE	$FA		; AJSR	byte_52F87
		.WORD	byte_52F87
		.BYTE	$F5,$23		; ACMDF5	$23
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$FA		; AJSR	byte_52F9B
		.WORD	byte_52F9B
		.BYTE	$F5,$24		; ACMDF5	$24
		.BYTE	$F0,$03		; ACMDF0	$03
		.BYTE	$FA		; AJSR	byte_52F9B
		.WORD	byte_52F9B
		.BYTE	$F5,$25		; ACMDF5	$25
		.BYTE	$F0,$02		; ACMDF0	$02
		.BYTE	$FA		; AJSR	byte_52F9B
		.WORD	byte_52F9B
		.BYTE	$F5,$26		; ACMDF5	$26
		.BYTE	$F0,$01		; ACMDF0	$01
		.BYTE	$FA		; AJSR	byte_52F9B
		.WORD	byte_52F9B
		.BYTE	$F5,$27		; ACMDF5	$27
		.BYTE	$FA		; AJSR	byte_52F9B
		.WORD	byte_52F9B
		.BYTE	$FA		; AJSR	byte_52F9B
		.WORD	byte_52F9B
		.BYTE	$FF		; ASTOP
_snd1A_D:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$18		; ACMDF5	$18
		.BYTE	$2F,$0E,$2D,$0C,$0A,$08,$06,$01,$1C,$17,$32 ; ADATA
		.BYTE	$FF		; ASTOP
_snd1B_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$01		; ACMDF0	$01
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$03,$04,$05	; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$04,$05,$06	; ADATA
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_snd1C_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$32		; ACMDF5	$32
		.BYTE	$FA		; AJSR	0x00053023
		.WORD	byte_53023
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	0x00053023
		.WORD	byte_53023
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00053023
		.WORD	byte_53023
		.BYTE	$FF		; ASTOP
byte_53023:
		.BYTE	$09,$07,$0A,$08	; ADATA
		.BYTE	$D0,$00		; ADATAEX
		.BYTE	$CA,$00		; ADATAEX
		.BYTE	$0E,$08,$09,$0F	; ADATA
		.BYTE	$FB		; ARET
_snd1D_A:
		.BYTE	$F5,$2E		; ACMDF5	$2E
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$02,$0B,$07,$08,$05,$0D,$04 ; ADATA
		.BYTE	$F8		; AJMP	_snd1D_A
		.WORD	_snd1D_A
_snd1E_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F6,$00		; ACMDF6	$00
byte_53048:
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$33		; ACMDF5	$33
		.BYTE	$3E,$1E,$20,$00,$23,$03,$24,$04,$2A,$0A,$24,$04,$27,$27,$29,$29 ;	ADATA
		.BYTE	$4A,$4A
		.BYTE	$FF		; ASTOP
_snd1E_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$10		; ADATA
		.BYTE	$F6,$23		; ACMDF6	$23
		.BYTE	$F8		; AJMP	0x00053048
		.WORD	byte_53048
_snd1F_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	0x00053092
		.WORD	byte_53092
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	0x00053092
		.WORD	byte_53092
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	0x00053092
		.WORD	byte_53092
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	0x00053092
		.WORD	byte_53092
		.BYTE	$F1,$FF		; ACMDF1	$FF
		.BYTE	$FA		; AJSR	0x00053092
		.WORD	byte_53092
		.BYTE	$FF		; ASTOP
byte_53092:
		.BYTE	$2E,$2D,$0F,$4E,$0C,$0F ;	ADATA
		.BYTE	$FB		; ARET
_snd20_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$2C		; ACMDF5	$2C
		.BYTE	$05,$07,$0C,$09,$0E ; ADATA
		.BYTE	$F8		; AJMP	_snd20_A
		.WORD	_snd20_A
_snd21_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F5,$2C		; ACMDF5	$2C
		.BYTE	$09,$07,$04,$0B,$09,$0E,$02 ; ADATA
		.BYTE	$F8		; AJMP	_snd21_A
		.WORD	_snd21_A
_snd22_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$0A		; ACMDF0	$0A
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$2B		; ACMDF5	$2B
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$FA		; AJSR	0x000530DE
		.WORD	byte_530DE
		.BYTE	$F5,$26		; ACMDF5	$26
		.BYTE	$F0,$0B		; ACMDF0	$0B
		.BYTE	$FA		; AJSR	0x000530EC
		.WORD	byte_530EC
		.BYTE	$F0,$09		; ACMDF0	$09
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	0x000530EE
		.WORD	byte_530EE
		.BYTE	$F1,$FE		; ACMDF1	$FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
byte_530DE:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0D,$0F		; ADATA
		.BYTE	$F1,$02		; ACMDF1	$02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$0D,$0E,$0C,$0D,$0B,$0C,$0A ; ADATA
byte_530EC:
		.BYTE	$09,$08		; ADATA
byte_530EE:
		.BYTE	$09,$07,$08,$04,$07,$03,$06,$01 ;	ADATA
		.BYTE	$FB		; ARET
_snd23_A:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F0,$05		; ACMDF0	$05
		.BYTE	$F6,$01		; ACMDF6	$01
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$0A		; ADATA
		.BYTE	$F0,$08		; ACMDF0	$08
		.BYTE	$E2,$0F,$00	; ACMDE2	$0F,$00
		.BYTE	$F3,$01		; ACMDF3	$01
		.BYTE	$0E		; ADATA
		.BYTE	$F0,$0C		; ACMDF0	$0C
		.BYTE	$0D		; ADATA
		.BYTE	$F0,$0E		; ACMDF0	$0E
		.BYTE	$0C		; ADATA
		.BYTE	$F0,$04		; ACMDF0	$04
		.BYTE	$2A		; ADATA
		.BYTE	$F0,$03		; ACMDF0	$03
		.BYTE	$27		; ADATA
		.BYTE	$F0,$02		; ACMDF0	$02
		.BYTE	$64		; ADATA
		.BYTE	$F0,$01		; ACMDF0	$01
		.BYTE	$22		; ADATA
		.BYTE	$FF		; ASTOP
_snd23_B:
		.BYTE	$F2,$00		; ACMDF2	$00
		.BYTE	$F6,$00		; ACMDF6	$00
		.BYTE	$F4,$00		; ACMDF4	$00
		.BYTE	$F5,$22		; ACMDF5	$22
		.BYTE	$F0,$0F		; ACMDF0	$0F
		.BYTE	$14,$16,$12,$17	; ADATA
		.BYTE	$FF		; ASTOP
_sample00:
		.BYTE	$80,$4F		; ADATA
		.BYTE	$FF		; ASTOP
_sample02:
		.BYTE	$81,$4F		; ADATA
		.BYTE	$FF		; ASTOP
_sample04:
		.BYTE	$82,$4F		; ADATA
		.BYTE	$FF		; ASTOP
_sample06:
		.BYTE	$83,$4F		; ADATA
		.BYTE	$FF		; ASTOP
_sample4F:
		.BYTE	$40		; ADATA
		.BYTE	$FF		; ASTOP
_sample35:
		.BYTE	$42,$02,$41,$04,$40 ; ADATA
		.BYTE	$FF		; ASTOP
_sample29:
		.BYTE	$42		; ADATA
		.BYTE	$FF		; ASTOP
_sample08:
		.BYTE	$4C,$03		; ADATA
		.BYTE	$FC,$0C		; ALOOP_START $0C
		.BYTE	$6F,$03		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
byte_53148:
		.BYTE	$57,$56,$45,$03,$44,$0F ;	ADATA
byte_5314E:
		.BYTE	$6F,$04,$61,$04	; ADATA
		.BYTE	$F8		; AJMP	0x0005314E
		.WORD	byte_5314E
_sample0C:
		.BYTE	$80,$58,$81	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample3D:
		.BYTE	$44,$04,$43	; ADATA
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F,$04,$61,$04,$6F ; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$20		; ADATA
		.BYTE	$FF		; ASTOP
_sample1A:
		.BYTE	$81,$58,$80	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample12:
		.BYTE	$80,$58,$82	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample16:
		.BYTE	$82,$58,$80	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample_unref:
		.BYTE	$80,$57,$82,$04	; ADATA
		.BYTE	$F8		; AJMP	byte_53185
		.WORD	byte_53185
_sample18:
		.BYTE	$81,$57,$80,$04	; ADATA
byte_53185:
		.BYTE	$40		; ADATA
byte_53186:
		.BYTE	$2E,$62,$04,$22,$6E,$04 ;	ADATA
		.BYTE	$F8		; AJMP	byte_53186
		.WORD	byte_53186
_sample1E:
		.BYTE	$80,$58,$83	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample22:
		.BYTE	$83,$58,$80	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample_unref_0:
		.BYTE	$44		; ADATA
byte_5319C:
		.BYTE	$2F,$02,$21,$02,$21,$02,$2F,$02 ;	ADATA
		.BYTE	$F8		; AJMP	0x0005319C
		.WORD	byte_5319C
_sample24:
		.BYTE	$FA		; AJSR	0x000531AD
		.WORD	byte_531AD
		.BYTE	$F8		; AJMP	0x000531B7
		.WORD	byte_531B7
byte_531AD:
		.BYTE	$80,$43		; ADATA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$72		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$91,$6E,$83	; ADATA
		.BYTE	$FB		; ARET
byte_531B7:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$6E,$02		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$7F		; ADATA
byte_531BD:
		.BYTE	$61,$04,$6F,$04	; ADATA
		.BYTE	$F8		; AJMP	0x000531BD
		.WORD	byte_531BD
_sample26:
		.BYTE	$49		; ADATA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$01,$6B		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample28:
		.BYTE	$49		; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7E		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F,$02		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample2C:
		.BYTE	$82,$58,$20,$83	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample30:
		.BYTE	$80,$58,$82	; ADATA
		.BYTE	$F8		; AJMP	byte_53148
		.WORD	byte_53148
_sample2F:
		.BYTE	$2E,$42		; ADATA
		.BYTE	$FF		; ASTOP
_sample55:
		.BYTE	$44,$04,$43	; ADATA
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$6F,$04,$61,$04,$6F ; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$22		; ADATA
		.BYTE	$FF		; ASTOP
_sample36:
		.BYTE	$4B,$92,$48,$83	; ADATA
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$6F,$02		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample34:
		.BYTE	$83,$46		; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$71,$80		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$6E,$03		; ADATA
		.BYTE	$FD		; ALOOP_END
byte_53209:
		.BYTE	$42,$02,$41,$0C	; ADATA
		.BYTE	$F8		; AJMP	0x00053209
		.WORD	byte_53209
_sample38:
		.BYTE	$81,$45		; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$72		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$82		; ADATA
byte_53217:
		.BYTE	$22,$02,$23,$02,$22,$02,$2E,$02,$2D,$02,$2E,$02
		.BYTE	$F8		; AJMP	0x00053217
		.WORD	byte_53217
_sample3A:
		.BYTE	$4A,$83,$02,$81	; ADATA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$7E		; ADATA
		.BYTE	$FD		; ALOOP_END
byte_5322E:
		.BYTE	$83,$02,$72,$7E	; ADATA
		.BYTE	$F8		; AJMP	0x0005322E
		.WORD	byte_5322E
_sample41:
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$6F,$03		; ADATA
		.BYTE	$FD		; ALOOP_END
_sample3C:
		.BYTE	$80,$4D,$02,$81,$4A ; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7D		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$82		; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7F		; ADATA
		.BYTE	$FD		; ALOOP_END
_sample3E:
		.BYTE	$80,$4A,$02,$6E,$83,$02 ;	ADATA
byte_5324E:
		.BYTE	$22,$02,$21,$03,$2E,$02,$2F,$03
		.BYTE	$F8		; AJMP	0x0005324E
		.WORD	byte_5324E
_sample40:
		.BYTE	$57,$31,$6F,$21,$02,$21,$03,$6F ;	ADATA
byte_53261:
		.BYTE	$21,$05
		.BYTE	$F8		; AJMP	0x00053261
		.WORD	byte_53261
_sample42:
		.BYTE	$83,$5A,$81,$59,$80,$47,$03 ; ADATA
byte_5326D:
		.BYTE	$21,$03,$2F,$03
		.BYTE	$F8		; AJMP	0x0005326D
		.WORD	byte_5326D
_sample44:
		.BYTE	$82,$5A,$80,$58	; ADATA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$7E,$80,$7E	; ADATA
		.BYTE	$FD		; ALOOP_END
byte_5327E:
		.BYTE	$46,$03,$42,$02,$46,$03,$42,$02 ;	ADATA
		.BYTE	$F8		; AJMP	0x0005327E
		.WORD	byte_5327E
		.BYTE	$FF		; ASTOP
_sample46:
		.BYTE	$83,$22,$5A,$81,$59,$80,$47,$03 ;	ADATA
byte_53292:
		.BYTE	$21,$03,$2F,$03
		.BYTE	$F8		; AJMP	0x00053292
		.WORD	byte_53292
_sample5B:
		.BYTE	$53,$55,$53,$42,$02,$40 ;	ADATA
		.BYTE	$FF		; ASTOP
_sample48:
		.BYTE	$23		; ADATA
		.BYTE	$F8		; AJMP	_sample44
		.WORD	_sample44
		.BYTE	$FF		; ASTOP
_sample4A:
		.BYTE	$82,$59,$81,$5A,$83,$5B,$21,$5D,$2F,$5A ;	ADATA
byte_532AF:
		.BYTE	$49,$21,$02,$2F,$02
		.BYTE	$F8		; AJMP	0x000532AF
		.WORD	byte_532AF
_sample4C:
		.BYTE	$80,$5D,$81,$5D,$82,$5A ;	ADATA
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$7F		; ADATA
		.BYTE	$FD		; ALOOP_END
byte_532C1:
		.BYTE	$55		; ADATA
		.BYTE	$F8		; AJMP	0x000532C1
		.WORD	byte_532C1
_sample4B:
		.BYTE	$42,$03,$44,$04	; ADATA
		.BYTE	$F8		; AJMP	_sample4B
		.WORD	_sample4B
		.BYTE	$FF		; ASTOP
_sample4E:
		.BYTE	-$7D,-$B3,-$FE,-$7E,-$B5,-$FC,-$B6,-$FC,-$B7,-$FA	; ADATA
byte_532D7:
		.BYTE	$22,$02,$2E,$02,$2E,$02,$22,$02
		.BYTE	$F8		; AJMP	0x000532D7
		.WORD	byte_532D7
_sample50:
		.BYTE	$82,$5D,$83,$5B,$7E,$6F,$02,$81 ;	ADATA
byte_532EA:
		.BYTE	$31,$3F,$3F,$31
		.BYTE	$F8		; AJMP	0x000532EA
		.WORD	byte_532EA
_sample52:
		.BYTE	$80,$5E,$81,$47,$02,$80,$5B,$5A ;	ADATA
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$7F		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample54:
		.BYTE	$83,$5F,$80,$4C,$02,$82,$49 ; ADATA
byte_53305:
		.BYTE	$21,$02,$2F,$02,$2F,$02,$21,$02
		.BYTE	$F8		; AJMP	0x00053305
		.WORD	byte_53305
		.BYTE	$FF		; ASTOP
_sample56:
		.BYTE	$83,$47		; ADATA
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$61,$02		; ADATA
		.BYTE	$FD		; ALOOP_END
byte_53318:
		.BYTE	$22,$02,$2F,$02,$2E,$02,$21,$02 ;	ADATA
		.BYTE	$F8		; AJMP	0x00053318
		.WORD	byte_53318
		.BYTE	$FF		; ASTOP
_sample59:
		.BYTE	$FC,$0D		; ALOOP_START $0D
		.BYTE	$7E,$7F,$7F,$6F,$02,$71,$71,$62,$02 ; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample58:
		.BYTE	$82,$4E,$03,$4B	; ADATA
		.BYTE	$FC,$0B		; ALOOP_START $0B
		.BYTE	$6F,$03		; ADATA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_sample5A:
		.BYTE	$5F,$5E,$58,$5C,$5A ; ADATA
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$7F		; ADATA
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
