
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
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$70		; ADATA	$70
_aloc_507FA:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F8		; AJMP	_aloc_507FA
		.WORD	_aloc_507FA
_mus1_B:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$06		; ACMDF5      $06
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_50829:
		.BYTE	$00		; ADATA	$00
		.BYTE	$23		; ADATA	$23
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$27		; ADATA	$27
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$23		; ADATA	$23
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$23		; ADATA	$23
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$00		; ADATA	$00
		.BYTE	$23		; ADATA	$23
		.BYTE	$40		; ADATA	$40
		.BYTE	$26		; ADATA	$26
		.BYTE	$40		; ADATA	$40
		.BYTE	$27		; ADATA	$27
		.BYTE	$40		; ADATA	$40
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$40		; ADATA	$40
		.BYTE	$27		; ADATA	$27
		.BYTE	$40		; ADATA	$40
		.BYTE	$25		; ADATA	$25
		.BYTE	$40		; ADATA	$40
		.BYTE	$23		; ADATA	$23
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$F8		; AJMP	_aloc_50829
		.WORD	_aloc_50829
_mus1_C:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$70		; ADATA	$70
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$EB		; ACMDF4      $EB
		.BYTE	$F5,$12		; ACMDF5      $12
		.BYTE	$F8		; AJMP	_aloc_50829
		.WORD	_aloc_50829
_mus1_D:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$81		; ADATA	$81
		.BYTE	$80		; ADATA	$80
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$81		; ADATA	$81
		.BYTE	$80		; ADATA	$80
		.BYTE	$F8		; AJMP	_aloc_50858
		.WORD	_mus1_D
_mus1_E:
		.BYTE	$F2,$07		; ACMDF2      $07
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
_aloc_50872:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$44		; ADATA	$44
		.BYTE	$FD		; ALOOP_END
		.BYTE	$24		; ADATA	$24
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F8		; AJMP	_aloc_50872
		.WORD	_aloc_50872
