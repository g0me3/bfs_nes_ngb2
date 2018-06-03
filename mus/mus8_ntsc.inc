
		.BYTE	$05
		.WORD	_mus8_A
		.BYTE	$0C
		.WORD	_mus8_B
		.BYTE	$0C
		.WORD	_mus8_C
		.BYTE	$00
		.WORD	_mus8_D
		.BYTE	$08
		.WORD	_mus8_E
		.BYTE	$04
_mus8_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FA		; AJSR	_asub_5202D
		.WORD	_asub_5202D
_aloc_5200E:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_52047
		.WORD	_asub_52047
		.BYTE	$FA		; AJSR	_asub_5205A
		.WORD	_asub_5205A
		.BYTE	$FA		; AJSR	_asub_52070
		.WORD	_asub_52070
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52047
		.WORD	_asub_52047
		.BYTE	$FA		; AJSR	_asub_5205A
		.WORD	_asub_5205A
		.BYTE	$FA		; AJSR	_asub_52079
		.WORD	_asub_52079
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	_asub_52082
		.WORD	_asub_52082
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_5200E
		.WORD	_aloc_5200E
		.BYTE	$FF		; ASTOP
_asub_5202D:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$DF,$03		; ADATAEX     $DF,$03
		.BYTE	$DF,$04		; ADATAEX     $DF,$04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_52047:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_asub_5205A:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_52070:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_52079:
		.BYTE	$E0,$F8,$1C		; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_52082:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_mus8_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_520C7
		.WORD	_asub_520C7
_aloc_520A8:
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_520D7
		.WORD	_asub_520D7
		.BYTE	$FA		; AJSR	_asub_520F4
		.WORD	_asub_520F4
		.BYTE	$FA		; AJSR	_asub_5210C
		.WORD	_asub_5210C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_520D7
		.WORD	_asub_520D7
		.BYTE	$FA		; AJSR	_asub_520F4
		.WORD	_asub_520F4
		.BYTE	$FA		; AJSR	_asub_52113
		.WORD	_asub_52113
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$FA		; AJSR	_asub_5211B
		.WORD	_asub_5211B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_520A8
		.WORD	_aloc_520A8
		.BYTE	$FF		; ASTOP
_asub_520C7:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$C6,$03		; ADATAEX     $C6,$03
		.BYTE	$C6,$04		; ADATAEX     $C6,$04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$26		; ADATA	$26
		.BYTE	$46		; ADATA	$46
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$46		; ADATA	$46
		.BYTE	$26		; ADATA	$26
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_asub_520D7:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_520F4:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$FB		; ARET
_asub_5210C:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$FB		; ARET
_asub_52113:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$08		; ADATA	$08
		.BYTE	$FB		; ARET
_asub_5211B:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$4D		; ADATA	$4D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$2D		; ADATA	$2D
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_mus8_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$D0,$7F		; ADATAEX     $D0,$7F
_aloc_52143:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_52195
		.WORD	_asub_52195
		.BYTE	$FA		; AJSR	_asub_521AA
		.WORD	_asub_521AA
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_521C1
		.WORD	_asub_521C1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_521EB
		.WORD	_asub_521EB
		.BYTE	$FA		; AJSR	_asub_5221D
		.WORD	_asub_5221D
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$FA		; AJSR	_asub_521EB
		.WORD	_asub_521EB
		.BYTE	$FA		; AJSR	_asub_52233
		.WORD	_asub_52233
		.BYTE	$D0,$12		; ADATAEX     $D0,$12
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FA		; AJSR	_asub_52223
		.WORD	_asub_52223
		.BYTE	$F8		; AJMP	_aloc_522B4
		.WORD	_aloc_522B4
_aloc_52179:
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_52251
		.WORD	_asub_52251
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_5225C
		.WORD	_asub_5225C
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_52251
		.WORD	_asub_52251
		.BYTE	$FA		; AJSR	_asub_5223F
		.WORD	_asub_5223F
		.BYTE	$FA		; AJSR	_asub_5226C
		.WORD	_asub_5226C
		.BYTE	$F8		; AJMP	_aloc_52289
		.WORD	_aloc_52289
		.BYTE	$FF		; ASTOP
_asub_52195:
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$44		; ADATA	$44
		.BYTE	$43		; ADATA	$43
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$22		; ADATA	$22
		.BYTE	$03		; ADATA	$03
		.BYTE	$22		; ADATA	$22
		.BYTE	$01		; ADATA	$01
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$40		; ADATA	$40
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_521AA:
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$40		; ADATA	$40
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F4,$80		; ACMDF4      $80
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$58		; ADATA	$58
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$18		; ADATA	$18
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_521C1:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$0B		; ACMDF6      $0B
		.BYTE	$84		; ADATA	$84
		.BYTE	$04		; ADATA	$04
		.BYTE	$90		; ADATA	$90
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$DF,$06		; ADATAEX     $DF,$06
		.BYTE	$C7,$06		; ADATAEX     $C7,$06
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F4,$90		; ACMDF4      $90
		.BYTE	$18		; ADATA	$18
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$FB		; ARET
_asub_521EB:
		.BYTE	$50		; ADATA	$50
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$38		; ADATA	$38
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$1D		; ADATAEX     $DF,$1D
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$C1,$01		; ADATAEX     $C1,$01
		.BYTE	$C2,$00		; ADATAEX     $C2,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$15		; ACMDF3      $15
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_5221D:
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$FB		; ARET
_asub_52223:
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$30		; ADATA	$30
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$30		; ADATA	$30
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$29		; ADATA	$29
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$49		; ADATA	$49
		.BYTE	$FB		; ARET
_asub_52233:
		.BYTE	$F4,$FC		; ACMDF4      $FC
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$C2,$06		; ADATAEX     $C2,$06
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$FB		; ARET
_asub_5223F:
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$F4,$E9		; ACMDF4      $E9
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$20		; ADATA	$20
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$22		; ADATA	$22
		.BYTE	$10		; ADATA	$10
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$FB		; ARET
_asub_52251:
		.BYTE	$DF,$41		; ADATAEX     $DF,$41
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$10		; ADATA	$10
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
_asub_5225C:
		.BYTE	$DF,$00		; ADATAEX     $DF,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$1E		; ACMDF3      $1E
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$DD,$5A		; ADATAEX     $DD,$5A
		.BYTE	$FB		; ARET
_asub_5226C:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DF,$23		; ADATAEX     $DF,$23
		.BYTE	$C9,$01		; ADATAEX     $C9,$01
		.BYTE	$CA,$01		; ADATAEX     $CA,$01
		.BYTE	$CB,$1C		; ADATAEX     $CB,$1C
		.BYTE	$09		; ADATA	$09
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$09		; ADATA	$09
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$02		; ADATA	$02
		.BYTE	$04		; ADATA	$04
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$02		; ADATA	$02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$03		; ADATA	$03
		.BYTE	$FB		; ARET
_mus8_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$D0,$7F		; ADATAEX     $D0,$7F
_aloc_52289:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_522C5
		.WORD	_asub_522C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_522D0
		.WORD	_asub_522D0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_522C5
		.WORD	_asub_522C5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_522FF
		.WORD	_asub_522FF
		.BYTE	$FA		; AJSR	_asub_52308
		.WORD	_asub_52308
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FA		; AJSR	_asub_52308
		.WORD	_asub_52308
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_52179
		.WORD	_aloc_52179
_aloc_522B4:
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_52316
		.WORD	_asub_52316
		.BYTE	$F5,$1A		; ACMDF5      $1A
		.BYTE	$FA		; AJSR	_asub_52316
		.WORD	_asub_52316
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_52143
		.WORD	_aloc_52143
		.BYTE	$FF		; ASTOP
_asub_522C5:
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$18		; ADATA	$18
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_522D0:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$83		; ADATA	$83
		.BYTE	$03		; ADATA	$03
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$58		; ADATA	$58
		.BYTE	$58		; ADATA	$58
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$24		; ADATA	$24
		.BYTE	$18		; ADATA	$18
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_522FF:
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$09		; ADATA	$09
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$29		; ADATA	$29
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FB		; ARET
_asub_52308:
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$04		; ADATA	$04
		.BYTE	$30		; ADATA	$30
		.BYTE	$04		; ADATA	$04
		.BYTE	$22		; ADATA	$22
		.BYTE	$04		; ADATA	$04
		.BYTE	$42		; ADATA	$42
		.BYTE	$FB		; ARET
_asub_52316:
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$58		; ADATA	$58
		.BYTE	$40		; ADATA	$40
		.BYTE	$38		; ADATA	$38
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$20		; ADATA	$20
		.BYTE	$18		; ADATA	$18
		.BYTE	$38		; ADATA	$38
		.BYTE	$00		; ADATA	$00
		.BYTE	$38		; ADATA	$38
		.BYTE	$14		; ADATA	$14
		.BYTE	$FB		; ARET
_mus8_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$D0,$7F		; ADATAEX     $D0,$7F
_aloc_5232F:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$FA		; AJSR	_asub_52360
		.WORD	_asub_52360
		.BYTE	$FA		; AJSR	_asub_52373
		.WORD	_asub_52373
		.BYTE	$FA		; AJSR	_asub_52386
		.WORD	_asub_52386
		.BYTE	$FA		; AJSR	_asub_52360
		.WORD	_asub_52360
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_523AC
		.WORD	_asub_523AC
		.BYTE	$FA		; AJSR	_asub_523E3
		.WORD	_asub_523E3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FA		; AJSR	_asub_5241D
		.WORD	_asub_5241D
		.BYTE	$F5,$0E		; ACMDF5      $0E
		.BYTE	$FA		; AJSR	_asub_5241D
		.WORD	_asub_5241D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_5232F
		.WORD	_aloc_5232F
		.BYTE	$FF		; ASTOP
_asub_52360:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$58		; ADATA	$58
		.BYTE	$58		; ADATA	$58
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$9D		; ADATA	$9D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$58		; ADATA	$58
		.BYTE	$50		; ADATA	$50
		.BYTE	$33		; ADATA	$33
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$13		; ADATA	$13
		.BYTE	$FB		; ARET
_asub_52373:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$40		; ADATA	$40
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$40		; ADATA	$40
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$58		; ADATA	$58
		.BYTE	$FB		; ARET
_asub_52386:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$13		; ADATA	$13
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$DF,$09		; ADATAEX     $DF,$09
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$DE		; ACMDF4      $DE
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$09		; ADATAEX     $DD,$09
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$38		; ADATA	$38
		.BYTE	$16		; ADATA	$16
		.BYTE	$FB		; ARET
_asub_523AC:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$01		; ADATAEX     $C3,$01
		.BYTE	$C4,$08		; ADATAEX     $C4,$08
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0E		; ADATAEX     $DD,$0E
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$38		; ADATA	$38
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$13		; ADATA	$13
		.BYTE	$18		; ADATA	$18
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$FB		; ARET
_asub_523E3:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0E		; ADATAEX     $DD,$0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$01		; ADATAEX     $DD,$01
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$58		; ADATA	$58
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DE,$01		; ADATAEX     $DE,$01
		.BYTE	$DF,$0E		; ADATAEX     $DF,$0E
		.BYTE	$30		; ADATA	$30
		.BYTE	$18		; ADATA	$18
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$0E		; ADATAEX     $DD,$0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$50		; ADATA	$50
		.BYTE	$33		; ADATA	$33
		.BYTE	$02		; ADATA	$02
		.BYTE	$FB		; ARET
_asub_5241D:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$54		; ADATA	$54
		.BYTE	$40		; ADATA	$40
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$20		; ADATA	$20
		.BYTE	$00		; ADATA	$00
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$20		; ADATA	$20
		.BYTE	$14		; ADATA	$14
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$34		; ADATA	$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$FB		; ARET
