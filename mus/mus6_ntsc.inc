
		.BYTE	$05
		.WORD	_mus6_A
		.BYTE	$0C
		.WORD	_mus6_B
		.BYTE	$0C
		.WORD	_mus6_C
		.BYTE	$04
		.WORD	_mus6_D
		.BYTE	$00
		.WORD	_mus6_E
		.BYTE	$08
_mus6_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517BC
		.WORD	_asub_517BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517CE
		.WORD	_asub_517CE
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517BC
		.WORD	_asub_517BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517CE
		.WORD	_asub_517CE
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517E1
		.WORD	_asub_517E1
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_517AA
		.WORD	_asub_517AA
		.BYTE	$FA		; AJSR	_asub_517CE
		.WORD	_asub_517CE
		.BYTE	$F8		; AJMP	_aloc_51777
		.WORD	_mus6_A
		.BYTE	$FF		; ASTOP
_asub_517AA:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_517BC:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_517CE:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_517E1:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_mus6_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_5181C
		.WORD	_asub_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51831
		.WORD	_asub_51831
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$1F		; ALOOP_START $1F
		.BYTE	$FA		; AJSR	_asub_5181C
		.WORD	_asub_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51831
		.WORD	_asub_51831
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_5181C
		.WORD	_asub_5181C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51831
		.WORD	_asub_51831
		.BYTE	$F8		; AJMP	_aloc_517F5
		.WORD	_mus6_B
		.BYTE	$FF		; ASTOP
_asub_5181C:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FB		; ARET
_asub_51831:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$23		; ADATA	$23
		.BYTE	$23		; ADATA	$23
		.BYTE	$23		; ADATA	$23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FB		; ARET
_mus6_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51884
		.WORD	_asub_51884
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_51889
		.WORD	_asub_51889
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_5188C
		.WORD	_asub_5188C
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_5188F
		.WORD	_asub_5188F
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51892
		.WORD	_asub_51892
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_51884
		.WORD	_asub_51884
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_51892
		.WORD	_asub_51892
		.BYTE	$FA		; AJSR	_asub_51895
		.WORD	_asub_51895
		.BYTE	$FA		; AJSR	_asub_518B8
		.WORD	_asub_518B8
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_518C8
		.WORD	_asub_518C8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_51842
		.WORD	_mus6_C
		.BYTE	$FF		; ASTOP
_asub_51884:
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$FB		; ARET
_asub_51889:
		.BYTE	$35		; ADATA	$35
		.BYTE	$21		; ADATA	$21
		.BYTE	$FB		; ARET
_asub_5188C:
		.BYTE	$34		; ADATA	$34
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_asub_5188F:
		.BYTE	$33		; ADATA	$33
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FB		; ARET
_asub_51892:
		.BYTE	$32		; ADATA	$32
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_51895:
		.BYTE	$F4,$DC		; ACMDF4      $DC
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$36		; ADATA	$36
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$39		; ADATA	$39
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$31		; ADATA	$31
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FB		; ARET
_asub_518B8:
		.BYTE	$31		; ADATA	$31
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$31		; ADATA	$31
		.BYTE	$30		; ADATA	$30
		.BYTE	$31		; ADATA	$31
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$31		; ADATA	$31
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$31		; ADATA	$31
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$31		; ADATA	$31
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_518C8:
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$36		; ADATA	$36
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$39		; ADATA	$39
		.BYTE	$22		; ADATA	$22
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$02		; ADATA	$02
		.BYTE	$39		; ADATA	$39
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F4,$A0		; ACMDF4      $A0
		.BYTE	$2E		; ADATA	$2E
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_mus6_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$FA		; AJSR	_asub_5190C
		.WORD	_asub_5190C
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_5195B
		.WORD	_asub_5195B
		.BYTE	$FA		; AJSR	_asub_519B1
		.WORD	_asub_519B1
		.BYTE	$FA		; AJSR	_asub_519C7
		.WORD	_asub_519C7
		.BYTE	$FA		; AJSR	_asub_519B1
		.WORD	_asub_519B1
		.BYTE	$FA		; AJSR	_asub_519E2
		.WORD	_asub_519E2
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_519FE
		.WORD	_asub_519FE
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_518E4
		.WORD	_mus6_D
		.BYTE	$FF		; ASTOP
_asub_5190C:
		.BYTE	$22		; ADATA	$22
		.BYTE	$D0,$82		; ADATAEX     $D0,$82
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$C9,$09		; ADATAEX     $C9,$09
		.BYTE	$27		; ADATA	$27
		.BYTE	$25		; ADATA	$25
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$07		; ADATAEX     $C5,$07
		.BYTE	$C7,$09		; ADATAEX     $C7,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$D0,$08		; ADATAEX     $D0,$08
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$22		; ADATA	$22
		.BYTE	$25		; ADATA	$25
		.BYTE	$27		; ADATA	$27
		.BYTE	$29		; ADATA	$29
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C7,$07		; ADATAEX     $C7,$07
		.BYTE	$C9,$09		; ADATAEX     $C9,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$2A		; ACMDF6      $2A
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$D0,$08		; ADATAEX     $D0,$08
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$C9,$09		; ADATAEX     $C9,$09
		.BYTE	$27		; ADATA	$27
		.BYTE	$25		; ADATA	$25
		.BYTE	$27		; ADATA	$27
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F0,$07		; ACMDF0      $07
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$C5,$07		; ADATAEX     $C5,$07
		.BYTE	$C7,$09		; ADATAEX     $C7,$09
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$1C		; ADATAEX     $D0,$1C
		.BYTE	$FB		; ARET
_asub_5195B:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$12		; ADATAEX     $D9,$12
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$36		; ADATA	$36
		.BYTE	$34		; ADATA	$34
		.BYTE	$D5,$02		; ADATAEX     $D5,$02
		.BYTE	$D6,$12		; ADATAEX     $D6,$12
		.BYTE	$79		; ADATA	$79
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DA,$02		; ADATAEX     $DA,$02
		.BYTE	$DB,$12		; ADATAEX     $DB,$12
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$09		; ADATAEX     $DD,$09
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$19		; ADATA	$19
		.BYTE	$96		; ADATA	$96
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$12		; ADATAEX     $D9,$12
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$30		; ADATA	$30
		.BYTE	$34		; ADATA	$34
		.BYTE	$30		; ADATA	$30
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$09		; ADATAEX     $D9,$09
		.BYTE	$30		; ADATA	$30
		.BYTE	$36		; ADATA	$36
		.BYTE	$34		; ADATA	$34
		.BYTE	$76		; ADATA	$76
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$D9,$01		; ADATAEX     $D9,$01
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$12		; ADATAEX     $DB,$12
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$19		; ADATA	$19
		.BYTE	$96		; ADATA	$96
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$FB		; ARET
_asub_519B1:
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$D8,$01		; ADATAEX     $D8,$01
		.BYTE	$D9,$12		; ADATAEX     $D9,$12
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$30		; ADATA	$30
		.BYTE	$34		; ADATA	$34
		.BYTE	$30		; ADATA	$30
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$1C		; ADATAEX     $D9,$1C
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$D0,$29		; ADATAEX     $D0,$29
		.BYTE	$FB		; ARET
_asub_519C7:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$D9,$01		; ADATAEX     $D9,$01
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$12		; ADATAEX     $DB,$12
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$39		; ADATA	$39
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$A8		; ACMDF6      $A8
		.BYTE	$36		; ADATA	$36
		.BYTE	$34		; ADATA	$34
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$76		; ADATA	$76
		.BYTE	$D0,$46		; ADATAEX     $D0,$46
		.BYTE	$FB		; ARET
_asub_519E2:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$DA,$02		; ADATAEX     $DA,$02
		.BYTE	$DB,$08		; ADATAEX     $DB,$08
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$DA,$01		; ADATAEX     $DA,$01
		.BYTE	$DB,$09		; ADATAEX     $DB,$09
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$30		; ADATA	$30
		.BYTE	$DB,$01		; ADATAEX     $DB,$01
		.BYTE	$DC,$01		; ADATAEX     $DC,$01
		.BYTE	$DD,$26		; ADATAEX     $DD,$26
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$FB		; ARET
_asub_519FE:
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$42		; ADATA	$42
		.BYTE	$50		; ADATA	$50
		.BYTE	$40		; ADATA	$40
		.BYTE	$10		; ADATA	$10
		.BYTE	$22		; ADATA	$22
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$FD		; ALOOP_END
		.BYTE	$42		; ADATA	$42
		.BYTE	$50		; ADATA	$50
		.BYTE	$60		; ADATA	$60
		.BYTE	$70		; ADATA	$70
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$20		; ADATA	$20
		.BYTE	$40		; ADATA	$40
		.BYTE	$10		; ADATA	$10
		.BYTE	$42		; ADATA	$42
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$70		; ADATA	$70
		.BYTE	$FB		; ARET
_mus6_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51A56
		.WORD	_asub_51A56
		.BYTE	$FA		; AJSR	_asub_51A6A
		.WORD	_asub_51A6A
		.BYTE	$FA		; AJSR	_asub_51A7D
		.WORD	_asub_51A7D
		.BYTE	$FA		; AJSR	_asub_51A90
		.WORD	_asub_51A90
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51AA3
		.WORD	_asub_51AA3
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_519C7
		.WORD	_asub_519C7
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$FA		; AJSR	_asub_51AA3
		.WORD	_asub_51AA3
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FA		; AJSR	_asub_519E2
		.WORD	_asub_519E2
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51AB6
		.WORD	_asub_51AB6
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_51A21
		.WORD	_mus6_E
		.BYTE	$FF		; ASTOP
_asub_51A56:
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$76		; ADATA	$76
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$36		; ADATA	$36
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$22		; ADATA	$22
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51A6A:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$35		; ADATA	$35
		.BYTE	$35		; ADATA	$35
		.BYTE	$35		; ADATA	$35
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$21		; ADATA	$21
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51A7D:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$20		; ADATA	$20
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51A90:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$33		; ADATA	$33
		.BYTE	$33		; ADATA	$33
		.BYTE	$33		; ADATA	$33
		.BYTE	$39		; ADATA	$39
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_51AA3:
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$62		; ADATA	$62
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$30		; ADATA	$30
		.BYTE	$39		; ADATA	$39
		.BYTE	$30		; ADATA	$30
		.BYTE	$A2		; ADATA	$A2
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$FB		; ARET
_asub_51AB6:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$20		; ADATA	$20
		.BYTE	$36		; ADATA	$36
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$36		; ADATA	$36
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
