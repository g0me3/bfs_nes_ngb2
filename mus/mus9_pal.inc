
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
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$DF,$08		; ADATAEX     $DF,$08
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DA,$2E		; ADATAEX     $DA,$2E
		.BYTE	$DD,$14		; ADATAEX     $DD,$14
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$DF,$06		; ADATAEX     $DF,$06
		.BYTE	$DF,$0D		; ADATAEX     $DF,$0D
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DC,$0D		; ADATAEX     $DC,$0D
		.BYTE	$F8		; AJMP	_aloc_9A095
		.WORD	_mus9_A
		.BYTE	$FF		; ASTOP
_mus9_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$CD,$14		; ADATAEX     $CD,$14
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C5,$06		; ADATAEX     $C5,$06
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C5,$0E		; ADATAEX     $C5,$0E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$C5,$07		; ADATAEX     $C5,$07
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C6,$06		; ADATAEX     $C6,$06
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$C7,$0D		; ADATAEX     $C7,$0D
		.BYTE	$F4,$B4		; ACMDF4      $B4
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$CB,$08		; ADATAEX     $CB,$08
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$C7,$0C		; ADATAEX     $C7,$0C
		.BYTE	$CA,$07		; ADATAEX     $CA,$07
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C9,$0D		; ADATAEX     $C9,$0D
		.BYTE	$F8		; AJMP	_aloc_9A0B3
		.WORD	_mus9_B
		.BYTE	$FF		; ASTOP
_mus9_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$D0,$1B		; ADATAEX     $D0,$1B
		.BYTE	$D5,$1A		; ADATAEX     $D5,$1A
		.BYTE	$D8,$1B		; ADATAEX     $D8,$1B
		.BYTE	$DB,$1A		; ADATAEX     $DB,$1A
		.BYTE	$DE,$35		; ADATAEX     $DE,$35
		.BYTE	$D8,$35		; ADATAEX     $D8,$35
		.BYTE	$DD,$6A		; ADATAEX     $DD,$6A
		.BYTE	$D0,$85		; ADATAEX     $D0,$85
		.BYTE	$D5,$1A		; ADATAEX     $D5,$1A
		.BYTE	$D8,$1B		; ADATAEX     $D8,$1B
		.BYTE	$DB,$1A		; ADATAEX     $DB,$1A
		.BYTE	$DE,$35		; ADATAEX     $DE,$35
		.BYTE	$C1,$35		; ADATAEX     $C1,$35
		.BYTE	$DD,$6A		; ADATAEX     $DD,$6A
		.BYTE	$D0,$85		; ADATAEX     $D0,$85
		.BYTE	$D5,$1A		; ADATAEX     $D5,$1A
		.BYTE	$D8,$1B		; ADATAEX     $D8,$1B
		.BYTE	$DB,$1A		; ADATAEX     $DB,$1A
		.BYTE	$DE,$35		; ADATAEX     $DE,$35
		.BYTE	$D8,$35		; ADATAEX     $D8,$35
		.BYTE	$DD,$6A		; ADATAEX     $DD,$6A
		.BYTE	$D0,$85		; ADATAEX     $D0,$85
		.BYTE	$D5,$1A		; ADATAEX     $D5,$1A
		.BYTE	$D8,$1B		; ADATAEX     $D8,$1B
		.BYTE	$DB,$1A		; ADATAEX     $DB,$1A
		.BYTE	$DE,$35		; ADATAEX     $DE,$35
		.BYTE	$C1,$1B		; ADATAEX     $C1,$1B
		.BYTE	$C4,$1A		; ADATAEX     $C4,$1A
		.BYTE	$DD,$6A		; ADATAEX     $DD,$6A
		.BYTE	$D0,$6A		; ADATAEX     $D0,$6A
		.BYTE	$DB,$50		; ADATAEX     $DB,$50
		.BYTE	$D9,$1A		; ADATAEX     $D9,$1A
		.BYTE	$D8,$50		; ADATAEX     $D8,$50
		.BYTE	$D9,$1A		; ADATAEX     $D9,$1A
		.BYTE	$DB,$50		; ADATAEX     $DB,$50
		.BYTE	$DD,$1A		; ADATAEX     $DD,$1A
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$DE,$00		; ADATAEX     $DE,$00
		.BYTE	$F1,$00		; ACMDF1      $00
		.BYTE	$F3,$6A		; ACMDF3      $6A
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F3,$0D		; ACMDF3      $0D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$34		; ADATAEX     $D0,$34
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F0,$06		; ACMDF0      $06
		.BYTE	$F5,$40		; ACMDF5      $40
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_9A16E
		.WORD	_asub_9A16E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FA		; AJSR	_asub_9A16E
		.WORD	_asub_9A16E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_9A0EF
		.WORD	_mus9_C
		.BYTE	$FF		; ASTOP
_asub_9A16E:
		.BYTE	$69		; ADATA	$69
		.BYTE	$66		; ADATA	$66
		.BYTE	$63		; ADATA	$63
		.BYTE	$60		; ADATA	$60
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$76		; ADATA	$76
		.BYTE	$77		; ADATA	$77
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$60		; ADATA	$60
		.BYTE	$63		; ADATA	$63
		.BYTE	$66		; ADATA	$66
		.BYTE	$FB		; ARET
_mus9_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$D0,$35		; ADATAEX     $D0,$35
		.BYTE	$D5,$1B		; ADATAEX     $D5,$1B
		.BYTE	$D8,$1A		; ADATAEX     $D8,$1A
		.BYTE	$DB,$35		; ADATAEX     $DB,$35
		.BYTE	$D5,$35		; ADATAEX     $D5,$35
		.BYTE	$D9,$6A		; ADATAEX     $D9,$6A
		.BYTE	$D0,$A0		; ADATAEX     $D0,$A0
		.BYTE	$D5,$1B		; ADATAEX     $D5,$1B
		.BYTE	$D8,$1A		; ADATAEX     $D8,$1A
		.BYTE	$DB,$35		; ADATAEX     $DB,$35
		.BYTE	$DE,$35		; ADATAEX     $DE,$35
		.BYTE	$D9,$6A		; ADATAEX     $D9,$6A
		.BYTE	$D0,$6A		; ADATAEX     $D0,$6A
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D8,$50		; ADATAEX     $D8,$50
		.BYTE	$D6,$1A		; ADATAEX     $D6,$1A
		.BYTE	$D5,$50		; ADATAEX     $D5,$50
		.BYTE	$D6,$1A		; ADATAEX     $D6,$1A
		.BYTE	$D8,$50		; ADATAEX     $D8,$50
		.BYTE	$D9,$1A		; ADATAEX     $D9,$1A
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$DB,$00		; ADATAEX     $DB,$00
		.BYTE	$F1,$00		; ACMDF1      $00
		.BYTE	$F3,$6A		; ACMDF3      $6A
		.BYTE	$FC,$08		; ALOOP_START $08
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F3,$0D		; ACMDF3      $0D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$F2,$00		; ACMDF2      $00
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_9A16E
		.WORD	_asub_9A16E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FA		; AJSR	_asub_9A16E
		.WORD	_asub_9A16E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_9A17B
		.WORD	_mus9_D
		.BYTE	$FF		; ASTOP
_mus9_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$17		; ACMDF5      $17
_aloc_9A1E5:
		.BYTE	$C2,$35		; ADATAEX     $C2,$35
		.BYTE	$F8		; AJMP	_aloc_9A1E5
		.WORD	_aloc_9A1E5
		.BYTE	$FF		; ASTOP
