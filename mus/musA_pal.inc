
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
		.BYTE	$F2,$09		; ACMDF2      $09
_aloc_98CA4:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$06		; ADATAEX     $DE,$06
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$DE,$0D		; ADATAEX     $DE,$0D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$F8		; AJMP	_aloc_98CA4
		.WORD	_aloc_98CA4
		.BYTE	$FF		; ASTOP
_musA_B:
		.BYTE	$F2,$09		; ACMDF2      $09
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_98CE6
		.WORD	_asub_98CE6
		.BYTE	$FA		; AJSR	_asub_98CFD
		.WORD	_asub_98CFD
		.BYTE	$FA		; AJSR	_asub_98CE6
		.WORD	_asub_98CE6
		.BYTE	$FA		; AJSR	_asub_98D16
		.WORD	_asub_98D16
		.BYTE	$F8		; AJMP	_aloc_98CD0
		.WORD	_musA_B
		.BYTE	$FF		; ASTOP
_asub_98CE6:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_98CFD:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$23		; ADATA	$23
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$06		; ADATA	$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_98D16:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$23		; ADATA	$23
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_musA_C:
		.BYTE	$F2,$09		; ACMDF2      $09
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_98D31:
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$AB		; ADATA	$AB
		.BYTE	$AC		; ADATA	$AC
		.BYTE	$86		; ADATA	$86
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$AB		; ADATA	$AB
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$A9		; ADATA	$A9
		.BYTE	$86		; ADATA	$86
		.BYTE	$69		; ADATA	$69
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F8		; AJMP	_aloc_98D31
		.WORD	_aloc_98D31
		.BYTE	$FF		; ASTOP
_musA_D:
		.BYTE	$F2,$09		; ACMDF2      $09
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_98D4B:
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$BB		; ADATA	$BB
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$97		; ADATA	$97
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$BB		; ADATA	$BB
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$93		; ADATA	$93
		.BYTE	$77		; ADATA	$77
		.BYTE	$B8		; ADATA	$B8
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F8		; AJMP	_aloc_98D4B
		.WORD	_aloc_98D4B
		.BYTE	$FF		; ASTOP
_musA_E:
		.BYTE	$F2,$09		; ACMDF2      $09
		.BYTE	$F6,$03		; ACMDF6      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$70		; ADATA	$70
		.BYTE	$90		; ADATA	$90
		.BYTE	$FD		; ALOOP_END
_aloc_98D6E:
		.BYTE	$C4,$6A		; ADATAEX     $C4,$6A
		.BYTE	$C4,$6A		; ADATAEX     $C4,$6A
		.BYTE	$F8		; AJMP	_aloc_98D6E
		.WORD	_aloc_98D6E
		.BYTE	$FF		; ASTOP
