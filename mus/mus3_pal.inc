
		.BYTE	$05
		.WORD	_mus3_A
		.BYTE	$0C
		.WORD	_mus3_B
		.BYTE	$00
		.WORD	_mus3_C
		.BYTE	$04
		.WORD	_mus3_D
		.BYTE	$08
		.WORD	_mus3_E
		.BYTE	$0C
_mus3_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$DE,$06		; ADATAEX     $DE,$06
		.BYTE	$DD,$06		; ADATAEX     $DD,$06
		.BYTE	$CF,$0A		; ADATAEX     $CF,$0A
		.BYTE	$DE,$0C		; ADATAEX     $DE,$0C
		.BYTE	$DE,$09		; ADATAEX     $DE,$09
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$FF		; ASTOP
_mus3_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$30		; ADATA	$30
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$17		; ADATA	$17
		.BYTE	$38		; ADATA	$38
		.BYTE	$02		; ADATA	$02
		.BYTE	$21		; ADATA	$21
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C3,$02		; ADATAEX     $C3,$02
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$C4,$08		; ADATAEX     $C4,$08
		.BYTE	$07		; ADATA	$07
		.BYTE	$DF,$0B		; ADATAEX     $DF,$0B
		.BYTE	$DB,$06		; ADATAEX     $DB,$06
		.BYTE	$D0,$0A		; ADATAEX     $D0,$0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$DD,$0C		; ADATAEX     $DD,$0C
		.BYTE	$DD,$09		; ADATAEX     $DD,$09
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$DC,$03		; ADATAEX     $DC,$03
		.BYTE	$DD,$00		; ADATAEX     $DD,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0F		; ACMDF3      $0F
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$04		; ACMDE3      $04
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_mus3_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$31		; ADATA	$31
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$36		; ADATA	$36
		.BYTE	$15		; ADATA	$15
		.BYTE	$38		; ADATA	$38
		.BYTE	$11		; ADATA	$11
		.BYTE	$33		; ADATA	$33
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$18		; ADATA	$18
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$DB,$0B		; ADATAEX     $DB,$0B
		.BYTE	$D3,$06		; ADATAEX     $D3,$06
		.BYTE	$D0,$0A		; ADATAEX     $D0,$0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$DA,$0C		; ADATAEX     $DA,$0C
		.BYTE	$DA,$09		; ADATAEX     $DA,$09
		.BYTE	$DA,$0B		; ADATAEX     $DA,$0B
		.BYTE	$D9,$03		; ADATAEX     $D9,$03
		.BYTE	$DA,$00		; ADATAEX     $DA,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0F		; ACMDF3      $0F
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$E3,$04		; ACMDE3      $04
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FF		; ASTOP
_mus3_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$29		; ADATA	$29
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$09		; ADATA	$09
		.BYTE	$29		; ADATA	$29
		.BYTE	$08		; ADATA	$08
		.BYTE	$47		; ADATA	$47
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$47		; ADATA	$47
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$C7,$0B		; ADATAEX     $C7,$0B
		.BYTE	$DB,$06		; ADATAEX     $DB,$06
		.BYTE	$D0,$0A		; ADATAEX     $D0,$0A
		.BYTE	$C2,$0C		; ADATAEX     $C2,$0C
		.BYTE	$C2,$09		; ADATAEX     $C2,$09
		.BYTE	$C2,$0B		; ADATAEX     $C2,$0B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
_mus3_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$C6,$06		; ADATAEX     $C6,$06
		.BYTE	$C7,$06		; ADATAEX     $C7,$06
		.BYTE	$CF,$0A		; ADATAEX     $CF,$0A
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$C4,$0C		; ADATAEX     $C4,$0C
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$C7,$09		; ADATAEX     $C7,$09
		.BYTE	$C8,$0B		; ADATAEX     $C8,$0B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$FF		; ASTOP
