
		.BYTE	$05
		.WORD	_mus4_A
		.BYTE	$04
		.WORD	_mus4_B
		.BYTE	$00
		.WORD	_mus4_C
		.BYTE	$08
		.WORD	_mus4_D
		.BYTE	$0C
		.WORD	_mus4_E
		.BYTE	$0C
_mus4_A:
		.BYTE	$F2,$0F		; ACMDF2      $0F
		.BYTE	$F0,$0F		; ACMDF0      $0F
_aloc_9A6A8:
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_9A6D1
		.WORD	_asub_9A6D1
		.BYTE	$FA		; AJSR	_asub_9A6DC
		.WORD	_asub_9A6DC
		.BYTE	$FA		; AJSR	_asub_9A6D1
		.WORD	_asub_9A6D1
		.BYTE	$FA		; AJSR	_asub_9A6E2
		.WORD	_asub_9A6E2
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$12		; ACMDF5      $12
		.BYTE	$FA		; AJSR	_asub_9A6D1
		.WORD	_asub_9A6D1
		.BYTE	$FA		; AJSR	_asub_9A6DC
		.WORD	_asub_9A6DC
		.BYTE	$FA		; AJSR	_asub_9A6D1
		.WORD	_asub_9A6D1
		.BYTE	$FA		; AJSR	_asub_9A6E2
		.WORD	_asub_9A6E2
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_9A6A8
		.WORD	_aloc_9A6A8
_asub_9A6D1:
		.BYTE	$54		; ADATA	$54
		.BYTE	$19		; ADATA	$19
		.BYTE	$DB,$09		; ADATAEX     $DB,$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$50		; ADATA	$50
		.BYTE	$19		; ADATA	$19
		.BYTE	$DB,$09		; ADATAEX     $DB,$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_9A6DC:
		.BYTE	$40		; ADATA	$40
		.BYTE	$19		; ADATA	$19
		.BYTE	$DB,$09		; ADATAEX     $DB,$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_asub_9A6E2:
		.BYTE	$42		; ADATA	$42
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$C0,$09		; ADATAEX     $C0,$09
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_mus4_B:
		.BYTE	$F2,$0F		; ACMDF2      $0F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FA		; AJSR	_asub_9A715
		.WORD	_asub_9A715
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_9A74E
		.WORD	_asub_9A74E
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FA		; AJSR	_asub_9A759
		.WORD	_asub_9A759
		.BYTE	$F5,$1E		; ACMDF5      $1E
		.BYTE	$FA		; AJSR	_asub_9A715
		.WORD	_asub_9A715
		.BYTE	$F5,$2A		; ACMDF5      $2A
		.BYTE	$FA		; AJSR	_asub_9A74E
		.WORD	_asub_9A74E
		.BYTE	$F5,$1E		; ACMDF5      $1E
		.BYTE	$FA		; AJSR	_asub_9A759
		.WORD	_asub_9A759
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$FA		; AJSR	_asub_9A76F
		.WORD	_asub_9A76F
		.BYTE	$F8		; AJMP	_aloc_9A6E8
		.WORD	_mus4_B
_asub_9A715:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$8A		; ADATA	$8A
		.BYTE	$F6,$25		; ACMDF6      $25
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$01		; ADATAEX     $D0,$01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$49		; ADATA	$49
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$50		; ADATA	$50
		.BYTE	$F6,$0B		; ACMDF6      $0B
		.BYTE	$00		; ADATA	$00
		.BYTE	$DE,$09		; ADATAEX     $DE,$09
		.BYTE	$19		; ADATA	$19
		.BYTE	$58		; ADATA	$58
		.BYTE	$16		; ADATA	$16
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$8C		; ADATA	$8C
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$90		; ADATA	$90
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$49		; ADATA	$49
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$D0,$09		; ADATAEX     $D0,$09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_9A74E:
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$CA,$03		; ADATAEX     $CA,$03
		.BYTE	$CB,$03		; ADATAEX     $CB,$03
		.BYTE	$CC,$07		; ADATAEX     $CC,$07
		.BYTE	$FB		; ARET
_asub_9A759:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$8C		; ADATA	$8C
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$90		; ADATA	$90
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$49		; ADATA	$49
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$09		; ADATA	$09
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$8C		; ADATA	$8C
		.BYTE	$8A		; ADATA	$8A
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$FB		; ARET
_asub_9A76F:
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C0,$4B		; ADATAEX     $C0,$4B
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$DE,$32		; ADATAEX     $DE,$32
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C0,$11		; ADATAEX     $C0,$11
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$DB,$4B		; ADATAEX     $DB,$4B
		.BYTE	$C0,$32		; ADATAEX     $C0,$32
		.BYTE	$F1,$00		; ACMDF1      $00
		.BYTE	$C3,$11		; ADATAEX     $C3,$11
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$44		; ADATA	$44
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C5,$32		; ADATAEX     $C5,$32
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C1,$32		; ADATAEX     $C1,$32
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$A8		; ADATA	$A8
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$CB,$3B		; ADATAEX     $CB,$3B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$49		; ADATA	$49
		.BYTE	$C8,$32		; ADATAEX     $C8,$32
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$F6,$2B		; ACMDF6      $2B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$C7,$4B		; ADATAEX     $C7,$4B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$C0,$32		; ADATAEX     $C0,$32
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C4,$14		; ADATAEX     $C4,$14
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$DB,$4B		; ADATAEX     $DB,$4B
		.BYTE	$C0,$32		; ADATAEX     $C0,$32
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C8,$32		; ADATAEX     $C8,$32
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$A1		; ADATA	$A1
		.BYTE	$DC,$25		; ADATAEX     $DC,$25
		.BYTE	$A1		; ADATA	$A1
		.BYTE	$88		; ADATA	$88
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$CA,$03		; ADATAEX     $CA,$03
		.BYTE	$CB,$38		; ADATAEX     $CB,$38
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$49		; ADATA	$49
		.BYTE	$A8		; ADATA	$A8
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$AD		; ADATA	$AD
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_mus4_C:
		.BYTE	$F2,$0F		; ACMDF2      $0F
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$FA		; AJSR	_asub_9A7FD
		.WORD	_asub_9A7FD
		.BYTE	$F5,$36		; ACMDF5      $36
		.BYTE	$FA		; AJSR	_asub_9A7FD
		.WORD	_asub_9A7FD
		.BYTE	$F8		; AJMP	_aloc_9A7EA
		.WORD	_mus4_C
_asub_9A7FD:
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$79		; ADATA	$79
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$39		; ADATA	$39
		.BYTE	$D8,$06		; ADATAEX     $D8,$06
		.BYTE	$D0,$09		; ADATAEX     $D0,$09
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$19		; ADATA	$19
		.BYTE	$D0,$27		; ADATAEX     $D0,$27
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$9B		; ADATA	$9B
		.BYTE	$99		; ADATA	$99
		.BYTE	$70		; ADATA	$70
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$D9,$09		; ADATAEX     $D9,$09
		.BYTE	$19		; ADATA	$19
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$F4,$9B		; ACMDF4      $9B
		.BYTE	$90		; ADATA	$90
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$99		; ADATA	$99
		.BYTE	$70		; ADATA	$70
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$D8,$09		; ADATAEX     $D8,$09
		.BYTE	$19		; ADATA	$19
		.BYTE	$50		; ADATA	$50
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$19		; ADATA	$19
		.BYTE	$F4,$B4		; ACMDF4      $B4
		.BYTE	$DB,$09		; ADATAEX     $DB,$09
		.BYTE	$12		; ADATA	$12
		.BYTE	$59		; ADATA	$59
		.BYTE	$12		; ADATA	$12
		.BYTE	$DB,$0A		; ADATAEX     $DB,$0A
		.BYTE	$12		; ADATA	$12
		.BYTE	$39		; ADATA	$39
		.BYTE	$32		; ADATA	$32
		.BYTE	$FB		; ARET
_mus4_D:
		.BYTE	$F2,$0F		; ACMDF2      $0F
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_9A88E
		.WORD	_asub_9A88E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9A8A5
		.WORD	_asub_9A8A5
		.BYTE	$F8		; AJMP	_aloc_9A880
		.WORD	_mus4_D
_asub_9A88E:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$DF,$15		; ADATAEX     $DF,$15
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$DD,$14		; ADATAEX     $DD,$14
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DE,$06		; ADATAEX     $DE,$06
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_9A8A5:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$DF,$15		; ADATAEX     $DF,$15
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9E		; ADATA	$9E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$DE,$07		; ADATAEX     $DE,$07
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_mus4_E:
		.BYTE	$F2,$0F		; ACMDF2      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$0F		; ALOOP_START $0F
		.BYTE	$FA		; AJSR	_asub_9A850
		.WORD	_asub_9A850
		.BYTE	$FA		; AJSR	_asub_9A869
		.WORD	_asub_9A869
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9A850
		.WORD	_asub_9A850
		.BYTE	$FA		; AJSR	_asub_9A876
		.WORD	_asub_9A876
		.BYTE	$F8		; AJMP	_aloc_9A838
		.WORD	_mus4_E
_asub_9A850:
		.BYTE	$F6,$2D		; ACMDF6      $2D
		.BYTE	$4E		; ADATA	$4E
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$43		; ADATA	$43
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$46		; ADATA	$46
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_9A869:
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$C3,$07		; ADATAEX     $C3,$07
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$C4,$05		; ADATAEX     $C4,$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$C4,$0F		; ADATAEX     $C4,$0F
		.BYTE	$FB		; ARET
_asub_9A876:
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$44		; ADATA	$44
		.BYTE	$24		; ADATA	$24
		.BYTE	$44		; ADATA	$44
		.BYTE	$C4,$06		; ADATAEX     $C4,$06
		.BYTE	$FB		; ARET
