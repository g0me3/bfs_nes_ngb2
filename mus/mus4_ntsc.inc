
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
