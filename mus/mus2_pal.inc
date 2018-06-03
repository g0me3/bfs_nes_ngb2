
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
		.BYTE	$F2,$05		; ACMDF2      $05
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
		.BYTE	$F2,$05		; ACMDF2      $05
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
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$12		; ACMDF5      $12
_aloc_9A3CB:
		.BYTE	$FA		; AJSR	_asub_9A3D5
		.WORD	_asub_9A3D5
		.BYTE	$FA		; AJSR	_asub_9A3DE
		.WORD	_asub_9A3DE
		.BYTE	$FA		; AJSR	_asub_9A3E8
		.WORD	_asub_9A3E8
		.BYTE	$FF		; ASTOP
_asub_9A3D5:
		.BYTE	$31		; ADATA	$31
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$20		; ADATA	$20
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_9A3DE:
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
_asub_9A3E8:
		.BYTE	$F5,$12		; ACMDF5      $12
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$D7,$3C		; ADATAEX     $D7,$3C
		.BYTE	$FB		; ARET
_mus2_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F8		; AJMP	_aloc_9A3CB
		.WORD	_aloc_9A3CB
		.BYTE	$FF		; ASTOP
_mus2_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$F5,$19		; ACMDF5      $19
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FA		; AJSR	_asub_9A3D5
		.WORD	_asub_9A3D5
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F5,$36		; ACMDF5      $36
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$30		; ADATA	$30
		.BYTE	$FA		; AJSR	_asub_9A420
		.WORD	_asub_9A420
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F5,$12		; ACMDF5      $12
		.BYTE	$D0,$0F		; ADATAEX     $D0,$0F
		.BYTE	$D7,$3C		; ADATAEX     $D7,$3C
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FF		; ASTOP
_asub_9A420:
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
