
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
