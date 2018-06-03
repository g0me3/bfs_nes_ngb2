
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
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_99D43
		.WORD	_asub_99D43
		.BYTE	$FA		; AJSR	_asub_99D56
		.WORD	_asub_99D56
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99D43
		.WORD	_asub_99D43
		.BYTE	$FA		; AJSR	_asub_99D69
		.WORD	_asub_99D69
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_99D43
		.WORD	_asub_99D43
		.BYTE	$FA		; AJSR	_asub_99D56
		.WORD	_asub_99D56
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99D43
		.WORD	_asub_99D43
		.BYTE	$FA		; AJSR	_asub_99D69
		.WORD	_asub_99D69
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_99D43
		.WORD	_asub_99D43
		.BYTE	$FA		; AJSR	_asub_99D7C
		.WORD	_asub_99D7C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99D43
		.WORD	_asub_99D43
		.BYTE	$FA		; AJSR	_asub_99D69
		.WORD	_asub_99D69
		.BYTE	$F8		; AJMP	_aloc_99D10
		.WORD	_mus6_A
		.BYTE	$FF		; ASTOP
_asub_99D43:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$10		; ADATAEX     $DE,$10
		.BYTE	$FB		; ARET
_asub_99D56:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$10		; ADATAEX     $DE,$10
		.BYTE	$FB		; ARET
_asub_99D69:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$FB		; ARET
_asub_99D7C:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$FB		; ARET
_mus6_B:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$FA		; AJSR	_asub_99DEA
		.WORD	_asub_99DEA
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$FA		; AJSR	_asub_99DEA
		.WORD	_asub_99DEA
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99DD5
		.WORD	_asub_99DD5
		.BYTE	$FA		; AJSR	_asub_99DEA
		.WORD	_asub_99DEA
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F8		; AJMP	_aloc_99D90
		.WORD	_mus6_B
		.BYTE	$FF		; ASTOP
_asub_99DD5:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$64		; ADATA	$64
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$44		; ADATA	$44
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$44		; ADATA	$44
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FB		; ARET
_asub_99DEA:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$63		; ADATA	$63
		.BYTE	$43		; ADATA	$43
		.BYTE	$43		; ADATA	$43
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FB		; ARET
_mus6_C:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_99E3D
		.WORD	_asub_99E3D
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FA		; AJSR	_asub_99E42
		.WORD	_asub_99E42
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FA		; AJSR	_asub_99E45
		.WORD	_asub_99E45
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FA		; AJSR	_asub_99E48
		.WORD	_asub_99E48
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99E4B
		.WORD	_asub_99E4B
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FA		; AJSR	_asub_99E3D
		.WORD	_asub_99E3D
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FA		; AJSR	_asub_99E4B
		.WORD	_asub_99E4B
		.BYTE	$FA		; AJSR	_asub_99E4E
		.WORD	_asub_99E4E
		.BYTE	$FA		; AJSR	_asub_99E71
		.WORD	_asub_99E71
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_99E81
		.WORD	_asub_99E81
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_99DFB
		.WORD	_mus6_C
		.BYTE	$FF		; ASTOP
_asub_99E3D:
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$76		; ADATA	$76
		.BYTE	$42		; ADATA	$42
		.BYTE	$FB		; ARET
_asub_99E42:
		.BYTE	$75		; ADATA	$75
		.BYTE	$41		; ADATA	$41
		.BYTE	$FB		; ARET
_asub_99E45:
		.BYTE	$74		; ADATA	$74
		.BYTE	$40		; ADATA	$40
		.BYTE	$FB		; ARET
_asub_99E48:
		.BYTE	$73		; ADATA	$73
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_99E4B:
		.BYTE	$72		; ADATA	$72
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$FB		; ARET
_asub_99E4E:
		.BYTE	$F4,$DC		; ACMDF4      $DC
		.BYTE	$79		; ADATA	$79
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$56		; ADATA	$56
		.BYTE	$59		; ADATA	$59
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$71		; ADATA	$71
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$71		; ADATA	$71
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$59		; ADATA	$59
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$71		; ADATA	$71
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$51		; ADATA	$51
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_99E71:
		.BYTE	$71		; ADATA	$71
		.BYTE	$51		; ADATA	$51
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$51		; ADATA	$51
		.BYTE	$50		; ADATA	$50
		.BYTE	$51		; ADATA	$51
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$71		; ADATA	$71
		.BYTE	$51		; ADATA	$51
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$51		; ADATA	$51
		.BYTE	$71		; ADATA	$71
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$51		; ADATA	$51
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$FB		; ARET
_asub_99E81:
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$76		; ADATA	$76
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$79		; ADATA	$79
		.BYTE	$42		; ADATA	$42
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$59		; ADATA	$59
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F4,$A0		; ACMDF4      $A0
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_mus6_D:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$FA		; AJSR	_asub_99EC5
		.WORD	_asub_99EC5
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_99F13
		.WORD	_asub_99F13
		.BYTE	$FA		; AJSR	_asub_99F6D
		.WORD	_asub_99F6D
		.BYTE	$FA		; AJSR	_asub_99F83
		.WORD	_asub_99F83
		.BYTE	$FA		; AJSR	_asub_99F6D
		.WORD	_asub_99F6D
		.BYTE	$FA		; AJSR	_asub_99F9E
		.WORD	_asub_99F9E
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_99FB8
		.WORD	_asub_99FB8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_99E9D
		.WORD	_mus6_D
		.BYTE	$FF		; ASTOP
_asub_99EC5:
		.BYTE	$42		; ADATA	$42
		.BYTE	$D0,$29		; ADATAEX     $D0,$29
		.BYTE	$D0,$43		; ADATAEX     $D0,$43
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$C9,$08		; ADATAEX     $C9,$08
		.BYTE	$67		; ADATA	$67
		.BYTE	$65		; ADATA	$65
		.BYTE	$C7,$08		; ADATAEX     $C7,$08
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$06		; ADATAEX     $C5,$06
		.BYTE	$C7,$07		; ADATAEX     $C7,$07
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$62		; ADATA	$62
		.BYTE	$45		; ADATA	$45
		.BYTE	$67		; ADATA	$67
		.BYTE	$49		; ADATA	$49
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C7,$06		; ADATAEX     $C7,$06
		.BYTE	$C9,$07		; ADATAEX     $C9,$07
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$50		; ADATA	$50
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$69		; ADATA	$69
		.BYTE	$47		; ADATA	$47
		.BYTE	$65		; ADATA	$65
		.BYTE	$67		; ADATA	$67
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$06		; ADATAEX     $C5,$06
		.BYTE	$C7,$07		; ADATAEX     $C7,$07
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FB		; ARET
_asub_99F13:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$10		; ADATAEX     $D9,$10
		.BYTE	$56		; ADATA	$56
		.BYTE	$56		; ADATA	$56
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$56		; ADATA	$56
		.BYTE	$54		; ADATA	$54
		.BYTE	$D5,$02		; ADATAEX     $D5,$02
		.BYTE	$D6,$0F		; ADATAEX     $D6,$0F
		.BYTE	$99		; ADATA	$99
		.BYTE	$D0,$2C		; ADATAEX     $D0,$2C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$10		; ADATAEX     $DB,$10
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DB,$0C		; ADATAEX     $DB,$0C
		.BYTE	$D9,$04		; ADATAEX     $D9,$04
		.BYTE	$D6,$16		; ADATAEX     $D6,$16
		.BYTE	$D0,$25		; ADATAEX     $D0,$25
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$10		; ADATAEX     $D9,$10
		.BYTE	$56		; ADATA	$56
		.BYTE	$56		; ADATA	$56
		.BYTE	$70		; ADATA	$70
		.BYTE	$54		; ADATA	$54
		.BYTE	$70		; ADATA	$70
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$59		; ADATA	$59
		.BYTE	$50		; ADATA	$50
		.BYTE	$56		; ADATA	$56
		.BYTE	$54		; ADATA	$54
		.BYTE	$96		; ADATA	$96
		.BYTE	$D0,$1A		; ADATAEX     $D0,$1A
		.BYTE	$D9,$01		; ADATAEX     $D9,$01
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$0F		; ADATAEX     $DB,$0F
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$70		; ADATA	$70
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DB,$0D		; ADATAEX     $DB,$0D
		.BYTE	$19		; ADATA	$19
		.BYTE	$D6,$15		; ADATAEX     $D6,$15
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D0,$25		; ADATAEX     $D0,$25
		.BYTE	$FB		; ARET
_asub_99F6D:
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$0F		; ADATAEX     $D9,$0F
		.BYTE	$76		; ADATA	$76
		.BYTE	$56		; ADATA	$56
		.BYTE	$50		; ADATA	$50
		.BYTE	$54		; ADATA	$54
		.BYTE	$70		; ADATA	$70
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$18		; ADATAEX     $D9,$18
		.BYTE	$56		; ADATA	$56
		.BYTE	$56		; ADATA	$56
		.BYTE	$D0,$22		; ADATAEX     $D0,$22
		.BYTE	$FB		; ARET
_asub_99F83:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$D9,$01		; ADATAEX     $D9,$01
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$0F		; ADATAEX     $DB,$0F
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$79		; ADATA	$79
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$A8		; ACMDF6      $A8
		.BYTE	$56		; ADATA	$56
		.BYTE	$54		; ADATA	$54
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$96		; ADATA	$96
		.BYTE	$D0,$3B		; ADATAEX     $D0,$3B
		.BYTE	$FB		; ARET
_asub_99F9E:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$DA,$02		; ADATAEX     $DA,$02
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$59		; ADATA	$59
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$59		; ADATA	$59
		.BYTE	$50		; ADATA	$50
		.BYTE	$DB,$01		; ADATAEX     $DB,$01
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$20		; ADATAEX     $DD,$20
		.BYTE	$D0,$28		; ADATAEX     $D0,$28
		.BYTE	$FB		; ARET
_asub_99FB8:
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$C2,$0D		; ADATAEX     $C2,$0D
		.BYTE	$D0,$0C		; ADATAEX     $D0,$0C
		.BYTE	$C0,$0D		; ADATAEX     $C0,$0D
		.BYTE	$10		; ADATA	$10
		.BYTE	$62		; ADATA	$62
		.BYTE	$40		; ADATA	$40
		.BYTE	$50		; ADATA	$50
		.BYTE	$FD		; ALOOP_END
		.BYTE	$C2,$0D		; ADATAEX     $C2,$0D
		.BYTE	$D0,$0C		; ADATAEX     $D0,$0C
		.BYTE	$80		; ADATA	$80
		.BYTE	$90		; ADATA	$90
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$60		; ADATA	$60
		.BYTE	$C0,$0C		; ADATAEX     $C0,$0C
		.BYTE	$10		; ADATA	$10
		.BYTE	$C2,$0D		; ADATAEX     $C2,$0D
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$45		; ADATA	$45
		.BYTE	$42		; ADATA	$42
		.BYTE	$90		; ADATA	$90
		.BYTE	$FB		; ARET
_mus6_E:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_9A019
		.WORD	_asub_9A019
		.BYTE	$FA		; AJSR	_asub_9A02F
		.WORD	_asub_9A02F
		.BYTE	$FA		; AJSR	_asub_9A042
		.WORD	_asub_9A042
		.BYTE	$FA		; AJSR	_asub_9A055
		.WORD	_asub_9A055
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9A068
		.WORD	_asub_9A068
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_99F83
		.WORD	_asub_99F83
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$FA		; AJSR	_asub_9A068
		.WORD	_asub_9A068
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_99F9E
		.WORD	_asub_99F9E
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_9A07B
		.WORD	_asub_9A07B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F8		; AJMP	_aloc_99FE2
		.WORD	_mus6_E
		.BYTE	$FF		; ASTOP
_asub_9A019:
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$D6,$11		; ADATAEX     $D6,$11
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$76		; ADATA	$76
		.BYTE	$59		; ADATA	$59
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$42		; ADATA	$42
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$79		; ADATA	$79
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$50		; ADATA	$50
		.BYTE	$79		; ADATA	$79
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$DD,$10		; ADATAEX     $DD,$10
		.BYTE	$FB		; ARET
_asub_9A02F:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$55		; ADATA	$55
		.BYTE	$75		; ADATA	$75
		.BYTE	$75		; ADATA	$75
		.BYTE	$59		; ADATA	$59
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$41		; ADATA	$41
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$79		; ADATA	$79
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$50		; ADATA	$50
		.BYTE	$59		; ADATA	$59
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$FB		; ARET
_asub_9A042:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$54		; ADATA	$54
		.BYTE	$74		; ADATA	$74
		.BYTE	$74		; ADATA	$74
		.BYTE	$59		; ADATA	$59
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$40		; ADATA	$40
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$79		; ADATA	$79
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$50		; ADATA	$50
		.BYTE	$59		; ADATA	$59
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$FB		; ARET
_asub_9A055:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$53		; ADATA	$53
		.BYTE	$73		; ADATA	$73
		.BYTE	$73		; ADATA	$73
		.BYTE	$59		; ADATA	$59
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$79		; ADATA	$79
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$50		; ADATA	$50
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$50		; ADATA	$50
		.BYTE	$59		; ADATA	$59
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$FB		; ARET
_asub_9A068:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$82		; ADATA	$82
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$50		; ADATA	$50
		.BYTE	$59		; ADATA	$59
		.BYTE	$50		; ADATA	$50
		.BYTE	$A2		; ADATA	$A2
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FB		; ARET
_asub_9A07B:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$76		; ADATA	$76
		.BYTE	$56		; ADATA	$56
		.BYTE	$42		; ADATA	$42
		.BYTE	$76		; ADATA	$76
		.BYTE	$56		; ADATA	$56
		.BYTE	$56		; ADATA	$56
		.BYTE	$62		; ADATA	$62
		.BYTE	$56		; ADATA	$56
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$60		; ADATA	$60
		.BYTE	$56		; ADATA	$56
		.BYTE	$42		; ADATA	$42
		.BYTE	$76		; ADATA	$76
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$45		; ADATA	$45
		.BYTE	$42		; ADATA	$42
		.BYTE	$76		; ADATA	$76
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$FB		; ARET
