
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
		.BYTE	$F2,$04		; ACMDF2      $04
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
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$CF,$0D		; ADATAEX     $CF,$0D
		.BYTE	$DE,$0F		; ADATAEX     $DE,$0F
		.BYTE	$DE,$0B		; ADATAEX     $DE,$0B
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$FF		; ASTOP
_mus3_B:
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F5,$33		; ACMDF5      $33
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
		.BYTE	$C4,$0A		; ADATAEX     $C4,$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$D0,$0D		; ADATAEX     $D0,$0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$DD,$0F		; ADATAEX     $DD,$0F
		.BYTE	$DD,$0B		; ADATAEX     $DD,$0B
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$31		; ADATA	$31
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F5,$33		; ACMDF5      $33
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
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$13		; ADATA	$13
		.BYTE	$D0,$0D		; ADATAEX     $D0,$0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$DA,$0F		; ADATAEX     $DA,$0F
		.BYTE	$DA,$0B		; ADATAEX     $DA,$0B
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$1B		; ACMDF5      $1B
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
		.BYTE	$27		; ADATA	$27
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$D0,$0D		; ADATAEX     $D0,$0D
		.BYTE	$C2,$0F		; ADATAEX     $C2,$0F
		.BYTE	$C2,$0B		; ADATAEX     $C2,$0B
		.BYTE	$C2,$0B		; ADATAEX     $C2,$0B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$42		; ADATA	$42
		.BYTE	$FF		; ASTOP
_mus3_E:
		.BYTE	$F2,$04		; ACMDF2      $04
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
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$CF,$0D		; ADATAEX     $CF,$0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$C4,$0F		; ADATAEX     $C4,$0F
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$C7,$0B		; ADATAEX     $C7,$0B
		.BYTE	$C8,$0B		; ADATAEX     $C8,$0B
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$FF		; ASTOP
