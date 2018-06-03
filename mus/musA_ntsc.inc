
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
