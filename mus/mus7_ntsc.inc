
		.BYTE	$05
		.WORD	_mus7_A
		.BYTE	$0C
		.WORD	_mus7_B
		.BYTE	$0C
		.WORD	_mus7_C
		.BYTE	$08
		.WORD	_mus7_D
		.BYTE	$04
		.WORD	_mus7_E
		.BYTE	$00
_mus7_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51B0D
		.WORD	_asub_51B0D
		.BYTE	$FA		; AJSR	_asub_51B1E
		.WORD	_asub_51B1E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B0D
		.WORD	_asub_51B0D
		.BYTE	$FA		; AJSR	_asub_51B30
		.WORD	_asub_51B30
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51B47
		.WORD	_asub_51B47
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B59
		.WORD	_asub_51B59
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51B47
		.WORD	_asub_51B47
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B30
		.WORD	_asub_51B30
		.BYTE	$FA		; AJSR	_asub_51B30
		.WORD	_asub_51B30
		.BYTE	$F8		; AJMP	_aloc_51AE0
		.WORD	_mus7_A
		.BYTE	$FF		; ASTOP
_asub_51B0D:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51B1E:
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51B30:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_51B47:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51B59:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_mus7_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51B9B
		.WORD	_asub_51B9B
		.BYTE	$FA		; AJSR	_asub_51BAF
		.WORD	_asub_51BAF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51B9B
		.WORD	_asub_51B9B
		.BYTE	$FA		; AJSR	_asub_51BC1
		.WORD	_asub_51BC1
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51BD0
		.WORD	_asub_51BD0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51BEB
		.WORD	_asub_51BEB
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51BD0
		.WORD	_asub_51BD0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51BC1
		.WORD	_asub_51BC1
		.BYTE	$FA		; AJSR	_asub_51C0C
		.WORD	_asub_51C0C
		.BYTE	$F8		; AJMP	_aloc_51B6D
		.WORD	_mus7_B
		.BYTE	$FF		; ASTOP
_asub_51B9B:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_51BAF:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$FB		; ARET
_asub_51BC1:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$23		; ADATA	$23
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_51BD0:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_51BEB:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_51C0C:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$23		; ADATA	$23
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$06		; ADATA	$06
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
_mus7_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51C64
		.WORD	_asub_51C64
		.BYTE	$D0,$F0		; ADATAEX     $D0,$F0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51C64
		.WORD	_asub_51C64
		.BYTE	$FA		; AJSR	_asub_51C72
		.WORD	_asub_51C72
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1E		; ACMDF5      $1E
		.BYTE	$FA		; AJSR	_asub_51C99
		.WORD	_asub_51C99
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1E		; ACMDF5      $1E
		.BYTE	$FA		; AJSR	_asub_51C99
		.WORD	_asub_51C99
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_51CAA
		.WORD	_asub_51CAA
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_51CAA
		.WORD	_asub_51CAA
		.BYTE	$FA		; AJSR	_asub_51CAA
		.WORD	_asub_51CAA
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_51CB5
		.WORD	_asub_51CB5
		.BYTE	$FA		; AJSR	_asub_51CBA
		.WORD	_asub_51CBA
		.BYTE	$F8		; AJMP	_aloc_51C24
		.WORD	_mus7_C
		.BYTE	$FF		; ASTOP
_asub_51C64:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$16		; ACMDF5      $16
		.BYTE	$60		; ADATA	$60
		.BYTE	$4C		; ADATA	$4C
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$30		; ADATA	$30
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$FB		; ARET
_asub_51C72:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$07		; ADATA	$07
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7C		; ADATA	$7C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_51C99:
		.BYTE	$F4,$BE		; ACMDF4      $BE
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$34		; ADATA	$34
		.BYTE	$20		; ADATA	$20
		.BYTE	$FD		; ALOOP_END
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$14		; ADATA	$14
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_asub_51CAA:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_51CB5:
		.BYTE	$78		; ADATA	$78
		.BYTE	$79		; ADATA	$79
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$FB		; ARET
_asub_51CBA:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$65		; ADATA	$65
		.BYTE	$59		; ADATA	$59
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_mus7_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51D20
		.WORD	_asub_51D20
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51D6A
		.WORD	_asub_51D6A
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51DA7
		.WORD	_asub_51DA7
		.BYTE	$FA		; AJSR	_asub_51D0A
		.WORD	_asub_51D0A
		.BYTE	$FA		; AJSR	_asub_51DD2
		.WORD	_asub_51DD2
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_51E03
		.WORD	_asub_51E03
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_51E1A
		.WORD	_asub_51E1A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_51E1A
		.WORD	_asub_51E1A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_51E2A
		.WORD	_asub_51E2A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$FA		; AJSR	_asub_51E2A
		.WORD	_asub_51E2A
		.BYTE	$F5,$24		; ACMDF5      $24
		.BYTE	$FA		; AJSR	_asub_51E03
		.WORD	_asub_51E03
		.BYTE	$FA		; AJSR	_asub_51E40
		.WORD	_asub_51E40
		.BYTE	$F8		; AJMP	_aloc_51CC2
		.WORD	_mus7_D
		.BYTE	$FF		; ASTOP
_asub_51D0A:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$16		; ACMDF5      $16
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$74		; ADATA	$74
		.BYTE	$40		; ADATA	$40
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$30		; ADATA	$30
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$FB		; ARET
_asub_51D20:
		.BYTE	$90		; ADATA	$90
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$02		; ADATA	$02
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$02		; ADATA	$02
		.BYTE	$16		; ADATA	$16
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$C0,$09		; ADATAEX     $C0,$09
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$22		; ADATA	$22
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_51D6A:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$79		; ADATA	$79
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$13		; ADATAEX     $DF,$13
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$10		; ADATA	$10
		.BYTE	$02		; ADATA	$02
		.BYTE	$02		; ADATA	$02
		.BYTE	$42		; ADATA	$42
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$20		; ADATA	$20
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$76		; ADATA	$76
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$00		; ADATA	$00
		.BYTE	$19		; ADATA	$19
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$79		; ADATA	$79
		.BYTE	$FB		; ARET
_asub_51DA7:
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$62		; ADATA	$62
		.BYTE	$25		; ADATA	$25
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07		; ADATA	$07
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$05		; ADATA	$05
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$56		; ADATA	$56
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_51DD2:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$D0,$03		; ADATAEX     $D0,$03
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$23		; ACMDF6      $23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$13		; ADATAEX     $C7,$13
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$22		; ADATA	$22
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$D9,$07		; ADATAEX     $D9,$07
		.BYTE	$FB		; ARET
_asub_51E03:
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$07		; ADATA	$07
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$03		; ADATA	$03
		.BYTE	$06		; ADATA	$06
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_51E1A:
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$18		; ADATA	$18
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_51E2A:
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$34		; ADATA	$34
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$14		; ADATA	$14
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$14		; ADATA	$14
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_51E40:
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$08		; ADATA	$08
		.BYTE	$06		; ADATA	$06
		.BYTE	$03		; ADATA	$03
		.BYTE	$06		; ADATA	$06
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$FB		; ARET
_mus7_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51EA7
		.WORD	_asub_51EA7
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51EEB
		.WORD	_asub_51EEB
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51F30
		.WORD	_asub_51F30
		.BYTE	$FA		; AJSR	_asub_51E97
		.WORD	_asub_51E97
		.BYTE	$FA		; AJSR	_asub_51F5F
		.WORD	_asub_51F5F
		.BYTE	$FA		; AJSR	_asub_51F92
		.WORD	_asub_51F92
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_51FA5
		.WORD	_asub_51FA5
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_51FA5
		.WORD	_asub_51FA5
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_51FD8
		.WORD	_asub_51FD8
		.BYTE	$FA		; AJSR	_asub_51FD8
		.WORD	_asub_51FD8
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_51FD8
		.WORD	_asub_51FD8
		.BYTE	$F5,$30		; ACMDF5      $30
		.BYTE	$FA		; AJSR	_asub_51F92
		.WORD	_asub_51F92
		.BYTE	$FA		; AJSR	_asub_51FE4
		.WORD	_asub_51FE4
		.BYTE	$F8		; AJMP	_aloc_51E55
		.WORD	_mus7_E
		.BYTE	$FF		; ASTOP
_asub_51E97:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0A		; ACMDF5      $0A
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$67		; ADATA	$67
		.BYTE	$47		; ADATA	$47
		.BYTE	$04		; ADATA	$04
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$25		; ADATA	$25
		.BYTE	$FB		; ARET
_asub_51EA7:
		.BYTE	$70		; ADATA	$70
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$38		; ACMDF5      $38
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$02		; ADATA	$02
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$01		; ADATA	$01
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$02		; ADATA	$02
		.BYTE	$16		; ADATA	$16
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$2C		; ACMDF5      $2C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$C0,$09		; ADATAEX     $C0,$09
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$22		; ADATA	$22
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_51EEB:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$67		; ADATA	$67
		.BYTE	$65		; ADATA	$65
		.BYTE	$CA,$01		; ADATAEX     $CA,$01
		.BYTE	$CB,$13		; ADATAEX     $CB,$13
		.BYTE	$67		; ADATA	$67
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$05		; ADATA	$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$02		; ADATA	$02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$62		; ADATA	$62
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$05		; ADATA	$05
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$05		; ADATA	$05
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$05		; ADATA	$05
		.BYTE	$00		; ADATA	$00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$65		; ADATA	$65
		.BYTE	$FB		; ARET
_asub_51F30:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$62		; ADATA	$62
		.BYTE	$67		; ADATA	$67
		.BYTE	$CA,$02		; ADATAEX     $CA,$02
		.BYTE	$CB,$08		; ADATAEX     $CB,$08
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$07		; ADATA	$07
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$60		; ADATA	$60
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$62		; ADATA	$62
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$79		; ADATA	$79
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$59		; ADATA	$59
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$56		; ADATA	$56
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_51F5F:
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$3F		; ACMDF5      $3F
		.BYTE	$19		; ADATA	$19
		.BYTE	$16		; ADATA	$16
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$16		; ADATA	$16
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$16		; ADATA	$16
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$16		; ADATA	$16
		.BYTE	$19		; ADATA	$19
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$13		; ADATA	$13
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$13		; ADATAEX     $C7,$13
		.BYTE	$6E		; ADATA	$6E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$22		; ADATA	$22
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_51F92:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$27		; ADATA	$27
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$28		; ADATA	$28
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$29		; ADATA	$29
		.BYTE	$01		; ADATA	$01
		.BYTE	$04		; ADATA	$04
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_asub_51FA5:
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$23		; ADATAEX     $D8,$23
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$76		; ADATA	$76
		.BYTE	$51		; ADATA	$51
		.BYTE	$12		; ADATA	$12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$08		; ADATAEX     $DE,$08
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$76		; ADATA	$76
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$A4		; ADATA	$A4
		.BYTE	$C1,$03		; ADATAEX     $C1,$03
		.BYTE	$C0,$03		; ADATAEX     $C0,$03
		.BYTE	$DF,$04		; ADATAEX     $DF,$04
		.BYTE	$DE,$28		; ADATAEX     $DE,$28
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$22		; ADATA	$22
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$69		; ADATA	$69
		.BYTE	$60		; ADATA	$60
		.BYTE	$FB		; ARET
_asub_51FD8:
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$07		; ADATA	$07
		.BYTE	$FB		; ARET
_asub_51FE4:
		.BYTE	$29		; ADATA	$29
		.BYTE	$01		; ADATA	$01
		.BYTE	$04		; ADATA	$04
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$17		; ADATA	$17
		.BYTE	$14		; ADATA	$14
		.BYTE	$FB		; ARET
