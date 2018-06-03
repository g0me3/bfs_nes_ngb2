
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
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_997F3
		.WORD	_asub_997F3
		.BYTE	$FA		; AJSR	_asub_99804
		.WORD	_asub_99804
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_997F3
		.WORD	_asub_997F3
		.BYTE	$FA		; AJSR	_asub_99816
		.WORD	_asub_99816
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_9982D
		.WORD	_asub_9982D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99841
		.WORD	_asub_99841
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_9982D
		.WORD	_asub_9982D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99816
		.WORD	_asub_99816
		.BYTE	$FA		; AJSR	_asub_99816
		.WORD	_asub_99816
		.BYTE	$F8		; AJMP	_aloc_997C6
		.WORD	_mus7_A
		.BYTE	$FF		; ASTOP
_asub_997F3:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$FB		; ARET
_asub_99804:
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$FB		; ARET
_asub_99816:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$FB		; ARET
_asub_9982D:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$0C		; ADATAEX     $DE,$0C
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$FB		; ARET
_asub_99841:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$0C		; ADATAEX     $DE,$0C
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_mus7_B:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_99885
		.WORD	_asub_99885
		.BYTE	$FA		; AJSR	_asub_99899
		.WORD	_asub_99899
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99885
		.WORD	_asub_99885
		.BYTE	$FA		; AJSR	_asub_998AB
		.WORD	_asub_998AB
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_998C5
		.WORD	_asub_998C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_998E0
		.WORD	_asub_998E0
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_998C5
		.WORD	_asub_998C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_998AB
		.WORD	_asub_998AB
		.BYTE	$FA		; AJSR	_asub_99901
		.WORD	_asub_99901
		.BYTE	$F8		; AJMP	_aloc_99857
		.WORD	_mus7_B
		.BYTE	$FF		; ASTOP
_asub_99885:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$45		; ADATA	$45
		.BYTE	$45		; ADATA	$45
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_99899:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$85		; ADATA	$85
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$45		; ADATA	$45
		.BYTE	$FB		; ARET
_asub_998AB:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$43		; ADATA	$43
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$43		; ADATA	$43
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_998C5:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$64		; ADATA	$64
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$6D		; ADATA	$6D
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_998E0:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$64		; ADATA	$64
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$6D		; ADATA	$6D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$05		; ADATA	$05
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_99901:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$63		; ADATA	$63
		.BYTE	$F4,$F4		; ACMDF4      $F4
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$45		; ADATA	$45
		.BYTE	$65		; ADATA	$65
		.BYTE	$06		; ADATA	$06
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$FB		; ARET
_mus7_C:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_9995D
		.WORD	_asub_9995D
		.BYTE	$D0,$C9		; ADATAEX     $D0,$C9
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9995D
		.WORD	_asub_9995D
		.BYTE	$FA		; AJSR	_asub_9996C
		.WORD	_asub_9996C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1F		; ACMDF5      $1F
		.BYTE	$FA		; AJSR	_asub_99996
		.WORD	_asub_99996
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1F		; ACMDF5      $1F
		.BYTE	$FA		; AJSR	_asub_99996
		.WORD	_asub_99996
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_999A7
		.WORD	_asub_999A7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$02		; ADATAEX     $D0,$02
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_999A7
		.WORD	_asub_999A7
		.BYTE	$FA		; AJSR	_asub_999A7
		.WORD	_asub_999A7
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_999B2
		.WORD	_asub_999B2
		.BYTE	$FA		; AJSR	_asub_999B8
		.WORD	_asub_999B8
		.BYTE	$F8		; AJMP	_aloc_99919
		.WORD	_mus7_C
		.BYTE	$FF		; ASTOP
_asub_9995D:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$17		; ACMDF5      $17
		.BYTE	$80		; ADATA	$80
		.BYTE	$CC,$0D		; ADATAEX     $CC,$0D
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$50		; ADATA	$50
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$FB		; ARET
_asub_9996C:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$02		; ADATA	$02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$07		; ADATA	$07
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$9C		; ADATA	$9C
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$DE,$10		; ADATAEX     $DE,$10
		.BYTE	$FB		; ARET
_asub_99996:
		.BYTE	$F4,$BE		; ACMDF4      $BE
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$74		; ADATA	$74
		.BYTE	$40		; ADATA	$40
		.BYTE	$FD		; ALOOP_END
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$14		; ADATA	$14
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_asub_999A7:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_999B2:
		.BYTE	$98		; ADATA	$98
		.BYTE	$99		; ADATA	$99
		.BYTE	$9A		; ADATA	$9A
		.BYTE	$DB,$10		; ADATAEX     $DB,$10
		.BYTE	$FB		; ARET
_asub_999B8:
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$9A		; ADATA	$9A
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$85		; ADATA	$85
		.BYTE	$D9,$0C		; ADATAEX     $D9,$0C
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_mus7_D:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$FA		; AJSR	_asub_99A09
		.WORD	_asub_99A09
		.BYTE	$FA		; AJSR	_asub_99A20
		.WORD	_asub_99A20
		.BYTE	$FA		; AJSR	_asub_99A09
		.WORD	_asub_99A09
		.BYTE	$FA		; AJSR	_asub_99A6A
		.WORD	_asub_99A6A
		.BYTE	$FA		; AJSR	_asub_99A09
		.WORD	_asub_99A09
		.BYTE	$FA		; AJSR	_asub_99AA9
		.WORD	_asub_99AA9
		.BYTE	$FA		; AJSR	_asub_99A09
		.WORD	_asub_99A09
		.BYTE	$FA		; AJSR	_asub_99ADA
		.WORD	_asub_99ADA
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_99B0B
		.WORD	_asub_99B0B
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$2B		; ACMDF5      $2B
		.BYTE	$FA		; AJSR	_asub_99B22
		.WORD	_asub_99B22
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_99B22
		.WORD	_asub_99B22
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$FA		; AJSR	_asub_99B32
		.WORD	_asub_99B32
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$FA		; AJSR	_asub_99B32
		.WORD	_asub_99B32
		.BYTE	$F5,$25		; ACMDF5      $25
		.BYTE	$FA		; AJSR	_asub_99B0B
		.WORD	_asub_99B0B
		.BYTE	$FA		; AJSR	_asub_99B48
		.WORD	_asub_99B48
		.BYTE	$F8		; AJMP	_aloc_999C1
		.WORD	_mus7_D
		.BYTE	$FF		; ASTOP
_asub_99A09:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$17		; ACMDF5      $17
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$94		; ADATA	$94
		.BYTE	$C0,$0D		; ADATAEX     $C0,$0D
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$50		; ADATA	$50
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$FB		; ARET
_asub_99A20:
		.BYTE	$D0,$15		; ADATAEX     $D0,$15
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$39		; ACMDF5      $39
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$29		; ADATA	$29
		.BYTE	$06		; ADATA	$06
		.BYTE	$02		; ADATA	$02
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F5,$2D		; ACMDF5      $2D
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$22		; ADATA	$22
		.BYTE	$16		; ADATA	$16
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$22		; ADATA	$22
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$06		; ADATA	$06
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$15		; ACMDF5      $15
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$40		; ADATA	$40
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$39		; ACMDF5      $39
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$20		; ADATA	$20
		.BYTE	$42		; ADATA	$42
		.BYTE	$40		; ADATA	$40
		.BYTE	$FB		; ARET
_asub_99A6A:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$99		; ADATA	$99
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$10		; ADATAEX     $DF,$10
		.BYTE	$DB,$10		; ADATAEX     $DB,$10
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$02		; ADATA	$02
		.BYTE	$30		; ADATA	$30
		.BYTE	$02		; ADATA	$02
		.BYTE	$02		; ADATA	$02
		.BYTE	$C2,$0D		; ADATAEX     $C2,$0D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$60		; ADATA	$60
		.BYTE	$40		; ADATA	$40
		.BYTE	$50		; ADATA	$50
		.BYTE	$40		; ADATA	$40
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$96		; ADATA	$96
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$00		; ADATA	$00
		.BYTE	$19		; ADATA	$19
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$99		; ADATA	$99
		.BYTE	$FB		; ARET
_asub_99AA9:
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$82		; ADATA	$82
		.BYTE	$45		; ADATA	$45
		.BYTE	$07		; ADATA	$07
		.BYTE	$22		; ADATA	$22
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07		; ADATA	$07
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$25		; ADATA	$25
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DB,$0D		; ADATAEX     $DB,$0D
		.BYTE	$D9,$0C		; ADATAEX     $D9,$0C
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$DB,$0D		; ADATAEX     $DB,$0D
		.BYTE	$D6,$0C		; ADATAEX     $D6,$0C
		.BYTE	$59		; ADATA	$59
		.BYTE	$FB		; ARET
_asub_99ADA:
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$D0,$02		; ADATAEX     $D0,$02
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F6,$23		; ACMDF6      $23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$10		; ADATAEX     $C7,$10
		.BYTE	$8E		; ADATA	$8E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$45		; ADATA	$45
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$24		; ADATA	$24
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$62		; ADATA	$62
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$D9,$06		; ADATAEX     $D9,$06
		.BYTE	$FB		; ARET
_asub_99B0B:
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$07		; ADATA	$07
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$23		; ADATA	$23
		.BYTE	$06		; ADATA	$06
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$04		; ADATA	$04
		.BYTE	$27		; ADATA	$27
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_99B22:
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$18		; ADATA	$18
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$04		; ADATA	$04
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_99B32:
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$54		; ADATA	$54
		.BYTE	$60		; ADATA	$60
		.BYTE	$14		; ADATA	$14
		.BYTE	$34		; ADATA	$34
		.BYTE	$40		; ADATA	$40
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$14		; ADATA	$14
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$40		; ADATA	$40
		.BYTE	$14		; ADATA	$14
		.BYTE	$40		; ADATA	$40
		.BYTE	$FB		; ARET
_asub_99B48:
		.BYTE	$09		; ADATA	$09
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$25		; ADATA	$25
		.BYTE	$08		; ADATA	$08
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$0C		; ADATA	$0C
		.BYTE	$08		; ADATA	$08
		.BYTE	$06		; ADATA	$06
		.BYTE	$03		; ADATA	$03
		.BYTE	$06		; ADATA	$06
		.BYTE	$03		; ADATA	$03
		.BYTE	$20		; ADATA	$20
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$FB		; ARET
_mus7_E:
		.BYTE	$F2,$0D		; ACMDF2      $0D
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FA		; AJSR	_asub_99B9F
		.WORD	_asub_99B9F
		.BYTE	$FA		; AJSR	_asub_99BB0
		.WORD	_asub_99BB0
		.BYTE	$FA		; AJSR	_asub_99B9F
		.WORD	_asub_99B9F
		.BYTE	$FA		; AJSR	_asub_99BF5
		.WORD	_asub_99BF5
		.BYTE	$FA		; AJSR	_asub_99B9F
		.WORD	_asub_99B9F
		.BYTE	$FA		; AJSR	_asub_99C3B
		.WORD	_asub_99C3B
		.BYTE	$FA		; AJSR	_asub_99B9F
		.WORD	_asub_99B9F
		.BYTE	$FA		; AJSR	_asub_99C6F
		.WORD	_asub_99C6F
		.BYTE	$FA		; AJSR	_asub_99CA2
		.WORD	_asub_99CA2
		.BYTE	$F5,$2B		; ACMDF5      $2B
		.BYTE	$FA		; AJSR	_asub_99CB5
		.WORD	_asub_99CB5
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_99CB5
		.WORD	_asub_99CB5
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FA		; AJSR	_asub_99CE9
		.WORD	_asub_99CE9
		.BYTE	$FA		; AJSR	_asub_99CE9
		.WORD	_asub_99CE9
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_99CE9
		.WORD	_asub_99CE9
		.BYTE	$F5,$31		; ACMDF5      $31
		.BYTE	$FA		; AJSR	_asub_99CA2
		.WORD	_asub_99CA2
		.BYTE	$FA		; AJSR	_asub_99CFB
		.WORD	_asub_99CFB
		.BYTE	$F8		; AJMP	_aloc_99B5D
		.WORD	_mus7_E
		.BYTE	$FF		; ASTOP
_asub_99B9F:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0B		; ACMDF5      $0B
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$87		; ADATA	$87
		.BYTE	$C7,$0D		; ADATAEX     $C7,$0D
		.BYTE	$04		; ADATA	$04
		.BYTE	$F4,$A8		; ACMDF4      $A8
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$50		; ADATA	$50
		.BYTE	$45		; ADATA	$45
		.BYTE	$FB		; ARET
_asub_99BB0:
		.BYTE	$90		; ADATA	$90
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F6,$12		; ACMDF6      $12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$39		; ACMDF5      $39
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$22		; ADATA	$22
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
		.BYTE	$36		; ADATA	$36
		.BYTE	$02		; ADATA	$02
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$00		; ADATA	$00
		.BYTE	$16		; ADATA	$16
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$2D		; ACMDF5      $2D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$60		; ADATA	$60
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$3A		; ADATA	$3A
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$42		; ADATA	$42
		.BYTE	$40		; ADATA	$40
		.BYTE	$FB		; ARET
_asub_99BF5:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$87		; ADATA	$87
		.BYTE	$C5,$10		; ADATAEX     $C5,$10
		.BYTE	$CA,$01		; ADATAEX     $CA,$01
		.BYTE	$CB,$10		; ADATAEX     $CB,$10
		.BYTE	$87		; ADATA	$87
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$07		; ADATA	$07
		.BYTE	$22		; ADATA	$22
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$05		; ADATA	$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$22		; ADATA	$22
		.BYTE	$05		; ADATA	$05
		.BYTE	$02		; ADATA	$02
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$22		; ADATA	$22
		.BYTE	$07		; ADATA	$07
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$82		; ADATA	$82
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$05		; ADATA	$05
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$00		; ADATA	$00
		.BYTE	$25		; ADATA	$25
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$59		; ADATA	$59
		.BYTE	$05		; ADATA	$05
		.BYTE	$00		; ADATA	$00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$85		; ADATA	$85
		.BYTE	$FB		; ARET
_asub_99C3B:
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$82		; ADATA	$82
		.BYTE	$87		; ADATA	$87
		.BYTE	$CA,$02		; ADATAEX     $CA,$02
		.BYTE	$CB,$07		; ADATAEX     $CB,$07
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$07		; ADATA	$07
		.BYTE	$45		; ADATA	$45
		.BYTE	$42		; ADATA	$42
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$80		; ADATA	$80
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$82		; ADATA	$82
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$D9,$10		; ADATAEX     $D9,$10
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DB,$0D		; ADATAEX     $DB,$0D
		.BYTE	$D9,$0D		; ADATAEX     $D9,$0D
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$DB,$0D		; ADATAEX     $DB,$0D
		.BYTE	$D6,$0C		; ADATAEX     $D6,$0C
		.BYTE	$59		; ADATA	$59
		.BYTE	$FB		; ARET
_asub_99C6F:
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$40		; ACMDF5      $40
		.BYTE	$19		; ADATA	$19
		.BYTE	$36		; ADATA	$36
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$16		; ADATA	$16
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$16		; ADATA	$16
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$16		; ADATA	$16
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$16		; ADATA	$16
		.BYTE	$02		; ADATA	$02
		.BYTE	$36		; ADATA	$36
		.BYTE	$19		; ADATA	$19
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$13		; ADATA	$13
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$10		; ADATAEX     $C7,$10
		.BYTE	$8E		; ADATA	$8E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$45		; ADATA	$45
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$62		; ADATA	$62
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$59		; ADATA	$59
		.BYTE	$FB		; ARET
_asub_99CA2:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$67		; ADATA	$67
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$02		; ADATA	$02
		.BYTE	$48		; ADATA	$48
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$69		; ADATA	$69
		.BYTE	$01		; ADATA	$01
		.BYTE	$24		; ADATA	$24
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_asub_99CB5:
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$1D		; ADATAEX     $D8,$1D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$96		; ADATA	$96
		.BYTE	$D1,$0D		; ADATAEX     $D1,$0D
		.BYTE	$12		; ADATA	$12
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$07		; ADATAEX     $DE,$07
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DB,$10		; ADATAEX     $DB,$10
		.BYTE	$96		; ADATA	$96
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$A4		; ADATA	$A4
		.BYTE	$C1,$03		; ADATAEX     $C1,$03
		.BYTE	$C0,$02		; ADATAEX     $C0,$02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$DE,$21		; ADATAEX     $DE,$21
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$42		; ADATA	$42
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$89		; ADATA	$89
		.BYTE	$80		; ADATA	$80
		.BYTE	$FB		; ARET
_asub_99CE9:
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$02		; ADATA	$02
		.BYTE	$07		; ADATA	$07
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$22		; ADATA	$22
		.BYTE	$07		; ADATA	$07
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$07		; ADATA	$07
		.BYTE	$FB		; ARET
_asub_99CFB:
		.BYTE	$49		; ADATA	$49
		.BYTE	$01		; ADATA	$01
		.BYTE	$24		; ADATA	$24
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$02		; ADATA	$02
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$23		; ADATA	$23
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$37		; ADATA	$37
		.BYTE	$14		; ADATA	$14
		.BYTE	$FB		; ARET
