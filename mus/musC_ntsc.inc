
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
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$00		; ADATA	$00
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17		; ADATA	$17
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50749
		.WORD	_musC_A
_musC_B:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$05		; ADATA	$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$05		; ADATA	$05
		.BYTE	$00		; ADATA	$00
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17		; ADATA	$17
		.BYTE	$04		; ADATA	$04
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50768
		.WORD	_musC_B
_musC_C:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$16		; ADATA	$16
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$09		; ADATA	$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$09		; ADATA	$09
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50787
		.WORD	_musC_C
_musC_D:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$5C		; ADATA	$5C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$F8		; AJMP	_aloc_507A6
		.WORD	_musC_D
_musC_E:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$0D		; ADATA	$0D
_aloc_507CC:
		.BYTE	$8D		; ADATA	$8D
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$08		; ADATA	$08
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$CD,$1B		; ADATAEX     $CD,$1B
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C9,$08		; ADATAEX     $C9,$08
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$07		; ADATA	$07
		.BYTE	$48		; ADATA	$48
		.BYTE	$F8		; AJMP	_aloc_507CC
		.WORD	_aloc_507CC
