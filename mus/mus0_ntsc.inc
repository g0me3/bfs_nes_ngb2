
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
