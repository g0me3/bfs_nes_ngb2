
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
		.BYTE	$F2,$0A		; ACMDF2      $0A
		.BYTE	$FA		; AJSR	_asub_98FA8
		.WORD	_asub_98FA8
_aloc_98F89:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_98FC3
		.WORD	_asub_98FC3
		.BYTE	$FA		; AJSR	_asub_98FD6
		.WORD	_asub_98FD6
		.BYTE	$FA		; AJSR	_asub_98FEC
		.WORD	_asub_98FEC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98FC3
		.WORD	_asub_98FC3
		.BYTE	$FA		; AJSR	_asub_98FD6
		.WORD	_asub_98FD6
		.BYTE	$FA		; AJSR	_asub_98FF5
		.WORD	_asub_98FF5
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	_asub_98FFF
		.WORD	_asub_98FFF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_98F89
		.WORD	_aloc_98F89
		.BYTE	$FF		; ASTOP
_asub_98FA8:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$DF,$02		; ADATAEX     $DF,$02
		.BYTE	$DF,$03		; ADATAEX     $DF,$03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_98FC3:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$FB		; ARET
_asub_98FD6:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FB		; ARET
_asub_98FEC:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_98FF5:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$DF,$05		; ADATAEX     $DF,$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_98FFF:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DF,$15		; ADATAEX     $DF,$15
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_mus8_B:
		.BYTE	$F2,$0A		; ACMDF2      $0A
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_99045
		.WORD	_asub_99045
_aloc_99026:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_99055
		.WORD	_asub_99055
		.BYTE	$FA		; AJSR	_asub_99073
		.WORD	_asub_99073
		.BYTE	$FA		; AJSR	_asub_9908B
		.WORD	_asub_9908B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99055
		.WORD	_asub_99055
		.BYTE	$FA		; AJSR	_asub_99073
		.WORD	_asub_99073
		.BYTE	$FA		; AJSR	_asub_99092
		.WORD	_asub_99092
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	_asub_9909B
		.WORD	_asub_9909B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_99026
		.WORD	_aloc_99026
		.BYTE	$FF		; ASTOP
_asub_99045:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$C6,$03		; ADATAEX     $C6,$03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$26		; ADATA	$26
		.BYTE	$66		; ADATA	$66
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$66		; ADATA	$66
		.BYTE	$26		; ADATA	$26
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_asub_99055:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$6D		; ADATA	$6D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C4,$09		; ADATAEX     $C4,$09
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_99073:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$64		; ADATA	$64
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$6D		; ADATA	$6D
		.BYTE	$FB		; ARET
_asub_9908B:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$6D		; ADATA	$6D
		.BYTE	$FB		; ARET
_asub_99092:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$C4,$05		; ADATAEX     $C4,$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_9909B:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$6D		; ADATA	$6D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$CD,$09		; ADATAEX     $CD,$09
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_mus8_C:
		.BYTE	$F2,$0A		; ACMDF2      $0A
		.BYTE	$D0,$69		; ADATAEX     $D0,$69
_aloc_990C4:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_99118
		.WORD	_asub_99118
		.BYTE	$FA		; AJSR	_asub_9912E
		.WORD	_asub_9912E
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$FA		; AJSR	_asub_99146
		.WORD	_asub_99146
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$FA		; AJSR	_asub_99173
		.WORD	_asub_99173
		.BYTE	$FA		; AJSR	_asub_991A5
		.WORD	_asub_991A5
		.BYTE	$90		; ADATA	$90
		.BYTE	$FA		; AJSR	_asub_991AB
		.WORD	_asub_991AB
		.BYTE	$D0,$26		; ADATAEX     $D0,$26
		.BYTE	$FA		; AJSR	_asub_991AB
		.WORD	_asub_991AB
		.BYTE	$FA		; AJSR	_asub_99173
		.WORD	_asub_99173
		.BYTE	$FA		; AJSR	_asub_991BB
		.WORD	_asub_991BB
		.BYTE	$D0,$0E		; ADATAEX     $D0,$0E
		.BYTE	$FA		; AJSR	_asub_991AB
		.WORD	_asub_991AB
		.BYTE	$D0,$25		; ADATAEX     $D0,$25
		.BYTE	$FA		; AJSR	_asub_991AB
		.WORD	_asub_991AB
		.BYTE	$D0,$02		; ADATAEX     $D0,$02
		.BYTE	$F8		; AJMP	_aloc_99241
		.WORD	_aloc_99241
_aloc_990FC:
		.BYTE	$FA		; AJSR	_asub_991C7
		.WORD	_asub_991C7
		.BYTE	$FA		; AJSR	_asub_991D9
		.WORD	_asub_991D9
		.BYTE	$FA		; AJSR	_asub_991C7
		.WORD	_asub_991C7
		.BYTE	$FA		; AJSR	_asub_991E5
		.WORD	_asub_991E5
		.BYTE	$FA		; AJSR	_asub_991C7
		.WORD	_asub_991C7
		.BYTE	$FA		; AJSR	_asub_991D9
		.WORD	_asub_991D9
		.BYTE	$FA		; AJSR	_asub_991C7
		.WORD	_asub_991C7
		.BYTE	$FA		; AJSR	_asub_991F5
		.WORD	_asub_991F5
		.BYTE	$F8		; AJMP	_aloc_99214
		.WORD	_aloc_99214
		.BYTE	$FF		; ASTOP
_asub_99118:
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$64		; ADATA	$64
		.BYTE	$43		; ADATA	$43
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$C2,$09		; ADATAEX     $C2,$09
		.BYTE	$03		; ADATA	$03
		.BYTE	$22		; ADATA	$22
		.BYTE	$01		; ADATA	$01
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$60		; ADATA	$60
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_9912E:
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$60		; ADATA	$60
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$09		; ADATAEX     $DD,$09
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$58		; ADATA	$58
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$18		; ADATA	$18
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_99146:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$0B		; ACMDF6      $0B
		.BYTE	$C4,$15		; ADATAEX     $C4,$15
		.BYTE	$04		; ADATA	$04
		.BYTE	$D0,$15		; ADATAEX     $D0,$15
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$DF,$05		; ADATAEX     $DF,$05
		.BYTE	$C7,$05		; ADATAEX     $C7,$05
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F4,$90		; ACMDF4      $90
		.BYTE	$18		; ADATA	$18
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DD,$15		; ADATAEX     $DD,$15
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$D0,$29		; ADATAEX     $D0,$29
		.BYTE	$FB		; ARET
_asub_99173:
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$90		; ADATA	$90
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$18		; ADATAEX     $DF,$18
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$C1,$01		; ADATAEX     $C1,$01
		.BYTE	$C2,$00		; ADATAEX     $C2,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$12		; ACMDF3      $12
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_991A5:
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_991AB:
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$30		; ADATA	$30
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$29		; ADATA	$29
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$69		; ADATA	$69
		.BYTE	$FB		; ARET
_asub_991BB:
		.BYTE	$F4,$FC		; ACMDF4      $FC
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$C4,$05		; ADATAEX     $C4,$05
		.BYTE	$C2,$05		; ADATAEX     $C2,$05
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$FB		; ARET
_asub_991C7:
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$F4,$E9		; ACMDF4      $E9
		.BYTE	$D0,$25		; ADATAEX     $D0,$25
		.BYTE	$A0		; ADATA	$A0
		.BYTE	$10		; ADATA	$10
		.BYTE	$A0		; ADATA	$A0
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$22		; ADATA	$22
		.BYTE	$10		; ADATA	$10
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$FB		; ARET
_asub_991D9:
		.BYTE	$DF,$36		; ADATAEX     $DF,$36
		.BYTE	$DF,$15		; ADATAEX     $DF,$15
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$10		; ADATA	$10
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_asub_991E5:
		.BYTE	$DF,$00		; ADATAEX     $DF,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$19		; ACMDF3      $19
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$DD,$4B		; ADATAEX     $DD,$4B
		.BYTE	$FB		; ARET
_asub_991F5:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DF,$1D		; ADATAEX     $DF,$1D
		.BYTE	$C9,$01		; ADATAEX     $C9,$01
		.BYTE	$CA,$01		; ADATAEX     $CA,$01
		.BYTE	$CB,$18		; ADATAEX     $CB,$18
		.BYTE	$C9,$05		; ADATAEX     $C9,$05
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$02		; ADATA	$02
		.BYTE	$C4,$05		; ADATAEX     $C4,$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$02		; ADATA	$02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FB		; ARET
_mus8_D:
		.BYTE	$F2,$0A		; ACMDF2      $0A
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$D0,$69		; ADATAEX     $D0,$69
_aloc_99214:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_99252
		.WORD	_asub_99252
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$FA		; AJSR	_asub_9925D
		.WORD	_asub_9925D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_99252
		.WORD	_asub_99252
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9928F
		.WORD	_asub_9928F
		.BYTE	$FA		; AJSR	_asub_99298
		.WORD	_asub_99298
		.BYTE	$D0,$25		; ADATAEX     $D0,$25
		.BYTE	$FA		; AJSR	_asub_99298
		.WORD	_asub_99298
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$03		; ADATAEX     $D0,$03
		.BYTE	$F8		; AJMP	_aloc_990FC
		.WORD	_aloc_990FC
_aloc_99241:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_992A6
		.WORD	_asub_992A6
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_992A6
		.WORD	_asub_992A6
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_990C4
		.WORD	_aloc_990C4
		.BYTE	$FF		; ASTOP
_asub_99252:
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$18		; ADATA	$18
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_9925D:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C3,$15		; ADATAEX     $C3,$15
		.BYTE	$03		; ADATA	$03
		.BYTE	$90		; ADATA	$90
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$DF,$0B		; ADATAEX     $DF,$0B
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$78		; ADATA	$78
		.BYTE	$58		; ADATA	$58
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DD,$15		; ADATAEX     $DD,$15
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$24		; ADATA	$24
		.BYTE	$18		; ADATA	$18
		.BYTE	$C4,$05		; ADATAEX     $C4,$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_9928F:
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$09		; ADATA	$09
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$29		; ADATA	$29
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FB		; ARET
_asub_99298:
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$A4		; ADATA	$A4
		.BYTE	$04		; ADATA	$04
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$04		; ADATA	$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$04		; ADATA	$04
		.BYTE	$62		; ADATA	$62
		.BYTE	$FB		; ARET
_asub_992A6:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$78		; ADATA	$78
		.BYTE	$40		; ADATA	$40
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$20		; ADATA	$20
		.BYTE	$18		; ADATA	$18
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$00		; ADATA	$00
		.BYTE	$38		; ADATA	$38
		.BYTE	$14		; ADATA	$14
		.BYTE	$FB		; ARET
_mus8_E:
		.BYTE	$F2,$0A		; ACMDF2      $0A
		.BYTE	$D0,$69		; ADATAEX     $D0,$69
_aloc_992BF:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$FA		; AJSR	_asub_992F0
		.WORD	_asub_992F0
		.BYTE	$FA		; AJSR	_asub_99304
		.WORD	_asub_99304
		.BYTE	$FA		; AJSR	_asub_99317
		.WORD	_asub_99317
		.BYTE	$FA		; AJSR	_asub_992F0
		.WORD	_asub_992F0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_9933B
		.WORD	_asub_9933B
		.BYTE	$FA		; AJSR	_asub_99371
		.WORD	_asub_99371
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$FA		; AJSR	_asub_993A8
		.WORD	_asub_993A8
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_993A8
		.WORD	_asub_993A8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_992BF
		.WORD	_aloc_992BF
		.BYTE	$FF		; ASTOP
_asub_992F0:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$78		; ADATA	$78
		.BYTE	$58		; ADATA	$58
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DD,$15		; ADATAEX     $DD,$15
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$78		; ADATA	$78
		.BYTE	$50		; ADATA	$50
		.BYTE	$B3		; ADATA	$B3
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$13		; ADATA	$13
		.BYTE	$FB		; ARET
_asub_99304:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$40		; ADATA	$40
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$40		; ADATA	$40
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$78		; ADATA	$78
		.BYTE	$FB		; ARET
_asub_99317:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$30		; ADATA	$30
		.BYTE	$13		; ADATA	$13
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$DF,$0B		; ADATAEX     $DF,$0B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$FB		; ARET
_asub_9933B:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$01		; ADATAEX     $C3,$01
		.BYTE	$C4,$07		; ADATAEX     $C4,$07
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0B		; ADATAEX     $DF,$0B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$78		; ADATA	$78
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$38		; ADATA	$38
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D3,$05		; ADATAEX     $D3,$05
		.BYTE	$18		; ADATA	$18
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$FB		; ARET
_asub_99371:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0B		; ADATAEX     $DF,$0B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0A		; ADATAEX     $DF,$0A
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$78		; ADATA	$78
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$70		; ADATA	$70
		.BYTE	$33		; ADATA	$33
		.BYTE	$02		; ADATA	$02
		.BYTE	$FB		; ARET
_asub_993A8:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$74		; ADATA	$74
		.BYTE	$40		; ADATA	$40
		.BYTE	$74		; ADATA	$74
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$20		; ADATA	$20
		.BYTE	$00		; ADATA	$00
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$00		; ADATA	$00
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
