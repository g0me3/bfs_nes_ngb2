
		.BYTE	$05
		.WORD	_musD_A
		.BYTE	$00
		.WORD	_musD_B
		.BYTE	$08
		.WORD	_musD_C
		.BYTE	$04
		.WORD	_musD_D
		.BYTE	$0C
		.WORD	_musD_E
		.BYTE	$0C
_musD_A:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$FA		; AJSR	_asub_9A20C
		.WORD	_asub_9A20C
		.BYTE	$FA		; AJSR	_asub_9A223
		.WORD	_asub_9A223
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$FA		; AJSR	_asub_9A223
		.WORD	_asub_9A223
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$FA		; AJSR	_asub_9A239
		.WORD	_asub_9A239
		.BYTE	$FF		; ASTOP
_asub_9A20C:
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$38		; ADATA	$38
		.BYTE	$37		; ADATA	$37
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$18		; ADATA	$18
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$17		; ADATA	$17
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_9A223:
		.BYTE	$FC,$02		; ALOOP_START $02
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
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_9A239:
		.BYTE	$19		; ADATA	$19
		.BYTE	$23		; ADATA	$23
		.BYTE	$19		; ADATA	$19
		.BYTE	$23		; ADATA	$23
		.BYTE	$19		; ADATA	$19
		.BYTE	$03		; ADATA	$03
		.BYTE	$29		; ADATA	$29
		.BYTE	$08		; ADATA	$08
		.BYTE	$10		; ADATA	$10
		.BYTE	$19		; ADATA	$19
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
		.BYTE	$19		; ADATA	$19
		.BYTE	$03		; ADATA	$03
		.BYTE	$09		; ADATA	$09
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$FB		; ARET
_musD_B:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FA		; AJSR	_asub_9A20C
		.WORD	_asub_9A20C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_9A266
		.WORD	_asub_9A266
		.BYTE	$FA		; AJSR	_asub_9A266
		.WORD	_asub_9A266
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_9A27C
		.WORD	_asub_9A27C
		.BYTE	$FF		; ASTOP
_asub_9A266:
		.BYTE	$FC,$02		; ALOOP_START $02
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
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_9A27C:
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$25		; ADATA	$25
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$25		; ADATA	$25
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$05		; ADATA	$05
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$09		; ADATA	$09
		.BYTE	$10		; ADATA	$10
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
_musD_C:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$C3,$70		; ADATAEX     $C3,$70
		.BYTE	$C2,$70		; ADATAEX     $C2,$70
		.BYTE	$C1,$70		; ADATAEX     $C1,$70
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$C0,$70		; ADATAEX     $C0,$70
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_9A2C0
		.WORD	_asub_9A2C0
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$23		; ACMDF6      $23
		.BYTE	$FA		; AJSR	_asub_9A2C0
		.WORD	_asub_9A2C0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$29		; ACMDF6      $29
		.BYTE	$FA		; AJSR	_asub_9A2D6
		.WORD	_asub_9A2D6
		.BYTE	$FF		; ASTOP
_asub_9A2C0:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$18		; ADATA	$18
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$17		; ADATA	$17
		.BYTE	$09		; ADATA	$09
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$09		; ADATA	$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$09		; ADATA	$09
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_9A2D6:
		.BYTE	$14		; ADATA	$14
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$14		; ADATA	$14
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$14		; ADATA	$14
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$23		; ADATA	$23
		.BYTE	$02		; ADATA	$02
		.BYTE	$10		; ADATA	$10
		.BYTE	$14		; ADATA	$14
		.BYTE	$04		; ADATA	$04
		.BYTE	$03		; ADATA	$03
		.BYTE	$14		; ADATA	$14
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$04		; ADATA	$04
		.BYTE	$08		; ADATA	$08
		.BYTE	$28		; ADATA	$28
		.BYTE	$FB		; ARET
_musD_D:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$E0,$F6,$06	; ACMDE0      $F6,$06
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$DF,$70		; ADATAEX     $DF,$70
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$FF		; ASTOP
_musD_E:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$FC,$20		; ALOOP_START $20
		.BYTE	$26		; ADATA	$26
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$8D		; ADATA	$8D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$08		; ADATA	$08
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$8D		; ADATA	$8D
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$07		; ADATA	$07
		.BYTE	$28		; ADATA	$28
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$07		; ADATA	$07
		.BYTE	$06		; ADATA	$06
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$09		; ADATA	$09
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$05		; ADATA	$05
		.BYTE	$09		; ADATA	$09
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C7,$02		; ADATAEX     $C7,$02
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$C6,$05		; ADATAEX     $C6,$05
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$06		; ADATA	$06
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$09		; ADATA	$09
		.BYTE	$08		; ADATA	$08
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$23		; ADATA	$23
		.BYTE	$FF	; ASTOP
