
		.BYTE	$05
		.WORD	_mus0_A
		.BYTE	$0C
		.WORD	_mus0_B
		.BYTE	$0C
		.WORD	_mus0_C
		.BYTE	$08
		.WORD	_mus0_D
		.BYTE	$00
		.WORD	_mus0_E
		.BYTE	$04
_mus0_A:
		.BYTE	$F2,$08		; ACMDF2      $08
_aloc_9878B:
		.BYTE	$FA		; AJSR	_asub_987B6
		.WORD	_asub_987B6
		.BYTE	$FA		; AJSR	_asub_987C3
		.WORD	_asub_987C3
		.BYTE	$FA		; AJSR	_asub_987B6
		.WORD	_asub_987B6
		.BYTE	$FA		; AJSR	_asub_987C3
		.WORD	_asub_987C3
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_987B6
		.WORD	_asub_987B6
		.BYTE	$FA		; AJSR	_asub_987C3
		.WORD	_asub_987C3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_987B6
		.WORD	_asub_987B6
		.BYTE	$FA		; AJSR	_asub_987D1
		.WORD	_asub_987D1
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_987E2
		.WORD	_asub_987E2
		.BYTE	$FA		; AJSR	_asub_987F0
		.WORD	_asub_987F0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98803
		.WORD	_asub_98803
		.BYTE	$F8		; AJMP	_aloc_9878B
		.WORD	_aloc_9878B
		.BYTE	$FF		; ASTOP
_asub_987B6:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$CF,$15		; ADATAEX     $CF,$15
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$CF,$11		; ADATAEX     $CF,$11
		.BYTE	$FB		; ARET
_asub_987C3:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$6F		; ADATA	$6F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$CF,$11		; ADATAEX     $CF,$11
		.BYTE	$FB		; ARET
_asub_987D1:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$CF,$15		; ADATAEX     $CF,$15
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DF,$05		; ADATAEX     $DF,$05
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_987E2:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$CF,$15		; ADATAEX     $CF,$15
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$CF,$0D		; ADATAEX     $CF,$0D
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FB		; ARET
_asub_987F0:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FB		; ARET
_asub_98803:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$CF,$0E		; ADATAEX     $CF,$0E
		.BYTE	$9F		; ADATA	$9F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_mus0_B:
		.BYTE	$F2,$08		; ACMDF2      $08
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0B		; ACMDF0      $0B
_aloc_98821:
		.BYTE	$FC,$0A		; ALOOP_START $0A
		.BYTE	$FA		; AJSR	_asub_98839
		.WORD	_asub_98839
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_98878
		.WORD	_asub_98878
		.BYTE	$FA		; AJSR	_asub_9889F
		.WORD	_asub_9889F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_988C2
		.WORD	_asub_988C2
		.BYTE	$F8		; AJMP	_aloc_98821
		.WORD	_aloc_98821
		.BYTE	$FF		; ASTOP
_asub_98839:
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$23		; ADATA	$23
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$65		; ADATA	$65
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$94		; ACMDF6      $94
		.BYTE	$45		; ADATA	$45
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$64		; ADATA	$64
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$47		; ADATA	$47
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$A4		; ADATA	$A4
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$47		; ADATA	$47
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$28		; ADATA	$28
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$65		; ADATA	$65
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$27		; ADATA	$27
		.BYTE	$FB		; ARET
_asub_98878:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$44		; ADATA	$44
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$64		; ADATA	$64
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$46		; ADATA	$46
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$64		; ADATA	$64
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_9889F:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$44		; ADATA	$44
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$63		; ADATA	$63
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$46		; ADATA	$46
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$FB		; ARET
_asub_988C2:
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$26		; ADATA	$26
		.BYTE	$4F		; ADATA	$4F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$64		; ADATA	$64
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F1,$05		; ACMDF1      $05
		.BYTE	$C4,$0E		; ADATAEX     $C4,$0E
		.BYTE	$F1,$FB		; ACMDF1      $FB
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$44		; ADATA	$44
		.BYTE	$C4,$05		; ADATAEX     $C4,$05
		.BYTE	$FB		; ARET
_mus0_C:
		.BYTE	$F2,$08		; ACMDF2      $08
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$05		; ALOOP_START $05
		.BYTE	$FA		; AJSR	_asub_9891C
		.WORD	_asub_9891C
		.BYTE	$FA		; AJSR	_asub_9892C
		.WORD	_asub_9892C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$21		; ACMDF5      $21
		.BYTE	$FA		; AJSR	_asub_9891C
		.WORD	_asub_9891C
		.BYTE	$F5,$23		; ACMDF5      $23
		.BYTE	$FA		; AJSR	_asub_9892C
		.WORD	_asub_9892C
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_9891C
		.WORD	_asub_9891C
		.BYTE	$FA		; AJSR	_asub_9892C
		.WORD	_asub_9892C
		.BYTE	$F5,$21		; ACMDF5      $21
		.BYTE	$FA		; AJSR	_asub_9891C
		.WORD	_asub_9891C
		.BYTE	$FA		; AJSR	_asub_9892C
		.WORD	_asub_9892C
		.BYTE	$F5,$23		; ACMDF5      $23
		.BYTE	$FA		; AJSR	_asub_9892C
		.WORD	_asub_9892C
		.BYTE	$FA		; AJSR	_asub_98943
		.WORD	_asub_98943
		.BYTE	$F8		; AJMP	_aloc_988E3
		.WORD	_mus0_C
		.BYTE	$FF		; ASTOP
_asub_9891C:
		.BYTE	$54		; ADATA	$54
		.BYTE	$30		; ADATA	$30
		.BYTE	$74		; ADATA	$74
		.BYTE	$30		; ADATA	$30
		.BYTE	$D2,$15		; ADATAEX     $D2,$15
		.BYTE	$74		; ADATA	$74
		.BYTE	$30		; ADATA	$30
		.BYTE	$34		; ADATA	$34
		.BYTE	$57		; ADATA	$57
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_9892C:
		.BYTE	$54		; ADATA	$54
		.BYTE	$30		; ADATA	$30
		.BYTE	$74		; ADATA	$74
		.BYTE	$30		; ADATA	$30
		.BYTE	$D2,$15		; ADATAEX     $D2,$15
		.BYTE	$54		; ADATA	$54
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$60		; ADATA	$60
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$3A		; ADATA	$3A
		.BYTE	$79		; ADATA	$79
		.BYTE	$37		; ADATA	$37
		.BYTE	$FB		; ARET
_asub_98943:
		.BYTE	$F4,$96		; ACMDF4      $96
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$94		; ADATA	$94
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$94		; ADATA	$94
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$27		; ADATA	$27
		.BYTE	$22		; ADATA	$22
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$D4,$19		; ADATAEX     $D4,$19
		.BYTE	$FB		; ARET
_mus0_D:
		.BYTE	$F2,$08		; ACMDF2      $08
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$C0,$0A		; ADATAEX     $C0,$0A
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$D0,$00		; ADATAEX     $D0,$00
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$70		; ADATA	$70
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$30		; ADATA	$30
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$30		; ADATA	$30
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$70		; ADATA	$70
		.BYTE	$29		; ADATA	$29
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$D2,$02		; ADATAEX     $D2,$02
		.BYTE	$D3,$02		; ADATAEX     $D3,$02
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$D0,$00		; ADATAEX     $D0,$00
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$70		; ADATA	$70
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$30		; ADATA	$30
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$30		; ADATA	$30
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$50		; ADATA	$50
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$0E		; ACMDF6      $0E
		.BYTE	$39		; ADATA	$39
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$39		; ADATA	$39
		.BYTE	$1A		; ADATA	$1A
		.BYTE	$BB		; ADATA	$BB
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F0,$05		; ACMDF0      $05
		.BYTE	$70		; ADATA	$70
		.BYTE	$DF,$00		; ADATAEX     $DF,$00
		.BYTE	$E3,$FA		; ACMDE3      $FA
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$01		; ACMDF3      $01
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$FD		; ALOOP_END
		.BYTE	$C0,$1A		; ADATAEX     $C0,$1A
		.BYTE	$C3,$19		; ADATAEX     $C3,$19
		.BYTE	$CA,$16		; ADATAEX     $CA,$16
		.BYTE	$C7,$11		; ADATAEX     $C7,$11
		.BYTE	$45		; ADATA	$45
		.BYTE	$D0,$05		; ADATAEX     $D0,$05
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$47		; ADATA	$47
		.BYTE	$45		; ADATA	$45
		.BYTE	$30		; ADATA	$30
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$50		; ADATA	$50
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$DE,$07		; ADATAEX     $DE,$07
		.BYTE	$C0,$07		; ADATAEX     $C0,$07
		.BYTE	$D0,$07		; ADATAEX     $D0,$07
		.BYTE	$C3,$07		; ADATAEX     $C3,$07
		.BYTE	$D0,$35		; ADATAEX     $D0,$35
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F6,$0C		; ACMDF6      $0C
		.BYTE	$D0,$07		; ADATAEX     $D0,$07
		.BYTE	$DD,$05		; ADATAEX     $DD,$05
		.BYTE	$D0,$06		; ADATAEX     $D0,$06
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$D0,$61		; ADATAEX     $D0,$61
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$F0		; ACMDF4      $F0
		.BYTE	$F6,$11		; ACMDF6      $11
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$15		; ADATAEX     $DE,$15
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$D0,$0C		; ADATAEX     $D0,$0C
		.BYTE	$DD,$02		; ADATAEX     $DD,$02
		.BYTE	$DE,$14		; ADATAEX     $DE,$14
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$52		; ADATA	$52
		.BYTE	$34		; ADATA	$34
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$60		; ADATA	$60
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$32		; ADATA	$32
		.BYTE	$54		; ADATA	$54
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$34		; ADATA	$34
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$29		; ADATA	$29
		.BYTE	$54		; ADATA	$54
		.BYTE	$29		; ADATA	$29
		.BYTE	$68		; ADATA	$68
		.BYTE	$34		; ADATA	$34
		.BYTE	$48		; ADATA	$48
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$C5,$02		; ADATAEX     $C5,$02
		.BYTE	$C6,$07		; ADATAEX     $C6,$07
		.BYTE	$23		; ADATA	$23
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$C0,$10		; ADATAEX     $C0,$10
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$08		; ACMDF0      $08
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$C7,$19		; ADATAEX     $C7,$19
		.BYTE	$CA,$19		; ADATAEX     $CA,$19
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C5,$19		; ADATAEX     $C5,$19
		.BYTE	$CC,$19		; ADATAEX     $CC,$19
		.BYTE	$CF,$19		; ADATAEX     $CF,$19
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$CA,$19		; ADATAEX     $CA,$19
		.BYTE	$C5,$19		; ADATAEX     $C5,$19
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$14		; ADATAEX     $C3,$14
		.BYTE	$40		; ADATA	$40
		.BYTE	$50		; ADATA	$50
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$14		; ADATAEX     $C3,$14
		.BYTE	$40		; ADATA	$40
		.BYTE	$50		; ADATA	$50
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$40		; ADATA	$40
		.BYTE	$30		; ADATA	$30
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$14		; ADATAEX     $C3,$14
		.BYTE	$40		; ADATA	$40
		.BYTE	$50		; ADATA	$50
		.BYTE	$C2,$02		; ADATAEX     $C2,$02
		.BYTE	$C3,$14		; ADATAEX     $C3,$14
		.BYTE	$40		; ADATA	$40
		.BYTE	$50		; ADATA	$50
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$40		; ADATA	$40
		.BYTE	$C7,$11		; ADATAEX     $C7,$11
		.BYTE	$45		; ADATA	$45
		.BYTE	$30		; ADATA	$30
		.BYTE	$63		; ADATA	$63
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$A0		; ADATA	$A0
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$D0,$36		; ADATAEX     $D0,$36
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$30		; ADATA	$30
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$CC,$11		; ADATAEX     $CC,$11
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$F6,$0D		; ACMDF6      $0D
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$C9,$02		; ADATAEX     $C9,$02
		.BYTE	$CA,$14		; ADATAEX     $CA,$14
		.BYTE	$27		; ADATA	$27
		.BYTE	$50		; ADATA	$50
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$A7		; ADATA	$A7
		.BYTE	$65		; ADATA	$65
		.BYTE	$26		; ADATA	$26
		.BYTE	$47		; ADATA	$47
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$70		; ADATA	$70
		.BYTE	$2F		; ADATA	$2F
		.BYTE	$A9		; ADATA	$A9
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$49		; ADATA	$49
		.BYTE	$26		; ADATA	$26
		.BYTE	$6C		; ADATA	$6C
		.BYTE	$25		; ADATA	$25
		.BYTE	$6B		; ADATA	$6B
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$06		; ACMDF6      $06
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$D8,$02		; ADATAEX     $D8,$02
		.BYTE	$D9,$06		; ADATAEX     $D9,$06
		.BYTE	$F4,$E6		; ACMDF4      $E6
		.BYTE	$3A		; ADATA	$3A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$7A		; ADATA	$7A
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$39		; ADATA	$39
		.BYTE	$57		; ADATA	$57
		.BYTE	$32		; ADATA	$32
		.BYTE	$F6,$1C		; ACMDF6      $1C
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$DF,$17		; ADATAEX     $DF,$17
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C3,$19		; ADATAEX     $C3,$19
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$DE,$19		; ADATAEX     $DE,$19
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$D9,$19		; ADATAEX     $D9,$19
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$06		; ADATA	$06
		.BYTE	$C7,$03		; ADATAEX     $C7,$03
		.BYTE	$50		; ADATA	$50
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$91		; ACMDF6      $91
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$C7,$03		; ADATAEX     $C7,$03
		.BYTE	$C7,$00		; ADATAEX     $C7,$00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$10		; ADATA	$10
		.BYTE	$D2,$19		; ADATAEX     $D2,$19
		.BYTE	$F8		; AJMP	_aloc_98954
		.WORD	_mus0_D
		.BYTE	$FF		; ASTOP
_mus0_E:
		.BYTE	$F2,$08		; ACMDF2      $08
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$DE,$02		; ADATAEX     $DE,$02
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$C0,$0A		; ADATAEX     $C0,$0A
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$47		; ADATA	$47
		.BYTE	$27		; ADATA	$27
		.BYTE	$70		; ADATA	$70
		.BYTE	$27		; ADATA	$27
		.BYTE	$47		; ADATA	$47
		.BYTE	$30		; ADATA	$30
		.BYTE	$67		; ADATA	$67
		.BYTE	$30		; ADATA	$30
		.BYTE	$47		; ADATA	$47
		.BYTE	$27		; ADATA	$27
		.BYTE	$70		; ADATA	$70
		.BYTE	$27		; ADATA	$27
		.BYTE	$47		; ADATA	$47
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$D2,$02		; ADATAEX     $D2,$02
		.BYTE	$D3,$02		; ADATAEX     $D3,$02
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$D0,$00		; ADATAEX     $D0,$00
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$F6,$1E		; ACMDF6      $1E
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$47		; ADATA	$47
		.BYTE	$27		; ADATA	$27
		.BYTE	$70		; ADATA	$70
		.BYTE	$27		; ADATA	$27
		.BYTE	$47		; ADATA	$47
		.BYTE	$30		; ADATA	$30
		.BYTE	$67		; ADATA	$67
		.BYTE	$30		; ADATA	$30
		.BYTE	$47		; ADATA	$47
		.BYTE	$27		; ADATA	$27
		.BYTE	$70		; ADATA	$70
		.BYTE	$30		; ADATA	$30
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$FC,$09		; ALOOP_START $09
		.BYTE	$50		; ADATA	$50
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$34		; ADATA	$34
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$34		; ADATA	$34
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$50		; ADATA	$50
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$FE		; ACMDF1      $FE
		.BYTE	$F6,$07		; ACMDF6      $07
		.BYTE	$72		; ADATA	$72
		.BYTE	$34		; ADATA	$34
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$34		; ADATA	$34
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$D2,$00		; ADATAEX     $D2,$00
		.BYTE	$E3,$03		; ACMDE3      $03
		.BYTE	$F3,$04		; ACMDF3      $04
		.BYTE	$D4,$00		; ADATAEX     $D4,$00
		.BYTE	$E3,$03		; ACMDE3      $03
		.BYTE	$F3,$08		; ACMDF3      $08
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$50		; ADATA	$50
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$34		; ADATA	$34
		.BYTE	$6A		; ADATA	$6A
		.BYTE	$29		; ADATA	$29
		.BYTE	$54		; ADATA	$54
		.BYTE	$29		; ADATA	$29
		.BYTE	$68		; ADATA	$68
		.BYTE	$34		; ADATA	$34
		.BYTE	$28		; ADATA	$28
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$F6,$0E		; ACMDF6      $0E
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$C5,$02		; ADATAEX     $C5,$02
		.BYTE	$C6,$07		; ADATAEX     $C6,$07
		.BYTE	$23		; ADATA	$23
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$96		; ACMDF4      $96
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$CA,$05		; ADATAEX     $CA,$05
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$23		; ADATA	$23
		.BYTE	$CA,$05		; ADATAEX     $CA,$05
		.BYTE	$20		; ADATA	$20
		.BYTE	$C3,$05		; ADATAEX     $C3,$05
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$C3,$05		; ADATAEX     $C3,$05
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$20		; ADATA	$20
		.BYTE	$C3,$05		; ADATAEX     $C3,$05
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$C8,$01		; ADATAEX     $C8,$01
		.BYTE	$C9,$15		; ADATAEX     $C9,$15
		.BYTE	$45		; ADATA	$45
		.BYTE	$50		; ADATA	$50
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$14		; ADATAEX     $C9,$14
		.BYTE	$45		; ADATA	$45
		.BYTE	$50		; ADATA	$50
		.BYTE	$43		; ADATA	$43
		.BYTE	$24		; ADATA	$24
		.BYTE	$65		; ADATA	$65
		.BYTE	$D0,$03		; ADATAEX     $D0,$03
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$14		; ADATAEX     $C9,$14
		.BYTE	$45		; ADATA	$45
		.BYTE	$50		; ADATA	$50
		.BYTE	$C8,$02		; ADATAEX     $C8,$02
		.BYTE	$C9,$14		; ADATAEX     $C9,$14
		.BYTE	$45		; ADATA	$45
		.BYTE	$50		; ADATA	$50
		.BYTE	$63		; ADATA	$63
		.BYTE	$24		; ADATA	$24
		.BYTE	$45		; ADATA	$45
		.BYTE	$CC,$11		; ADATAEX     $CC,$11
		.BYTE	$4A		; ADATA	$4A
		.BYTE	$30		; ADATA	$30
		.BYTE	$57		; ADATA	$57
		.BYTE	$32		; ADATA	$32
		.BYTE	$73		; ADATA	$73
		.BYTE	$D4,$0C		; ADATAEX     $D4,$0C
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$34		; ADATA	$34
		.BYTE	$57		; ADATA	$57
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$74		; ADATA	$74
		.BYTE	$30		; ADATA	$30
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F0,$0B		; ACMDF0      $0B
		.BYTE	$F6,$1F		; ACMDF6      $1F
		.BYTE	$45		; ADATA	$45
		.BYTE	$30		; ADATA	$30
		.BYTE	$65		; ADATA	$65
		.BYTE	$C7,$12		; ADATAEX     $C7,$12
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$50		; ADATA	$50
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$60		; ADATA	$60
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$3A		; ADATA	$3A
		.BYTE	$79		; ADATA	$79
		.BYTE	$37		; ADATA	$37
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$59		; ADATA	$59
		.BYTE	$23		; ADATA	$23
		.BYTE	$63		; ADATA	$63
		.BYTE	$39		; ADATA	$39
		.BYTE	$43		; ADATA	$43
		.BYTE	$39		; ADATA	$39
		.BYTE	$62		; ADATA	$62
		.BYTE	$23		; ADATA	$23
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$0F		; ACMDF6      $0F
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$D0,$05		; ADATAEX     $D0,$05
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$30		; ADATA	$30
		.BYTE	$29		; ADATA	$29
		.BYTE	$26		; ADATA	$26
		.BYTE	$D0,$05		; ADATAEX     $D0,$05
		.BYTE	$2C		; ADATA	$2C
		.BYTE	$25		; ADATA	$25
		.BYTE	$30		; ADATA	$30
		.BYTE	$2B		; ADATA	$2B
		.BYTE	$24		; ADATA	$24
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F6,$08		; ACMDF6      $08
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$59		; ADATA	$59
		.BYTE	$23		; ADATA	$23
		.BYTE	$63		; ADATA	$63
		.BYTE	$39		; ADATA	$39
		.BYTE	$62		; ADATA	$62
		.BYTE	$23		; ADATA	$23
		.BYTE	$42		; ADATA	$42
		.BYTE	$23		; ADATA	$23
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$F4,$96		; ACMDF4      $96
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$25		; ADATA	$25
		.BYTE	$DB,$05		; ADATAEX     $DB,$05
		.BYTE	$22		; ADATA	$22
		.BYTE	$27		; ADATA	$27
		.BYTE	$39		; ADATA	$39
		.BYTE	$22		; ADATA	$22
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$1A		; ACMDF6      $1A
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$27		; ADATA	$27
		.BYTE	$D0,$07		; ADATAEX     $D0,$07
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$91		; ACMDF6      $91
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$C7,$03		; ADATAEX     $C7,$03
		.BYTE	$C7,$00		; ADATAEX     $C7,$00
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$E3,$02		; ACMDE3      $02
		.BYTE	$F3,$03		; ACMDF3      $03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$16		; ACMDF6      $16
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$D9,$19		; ADATAEX     $D9,$19
		.BYTE	$F8		; AJMP	_aloc_98B0D
		.WORD	_mus0_E
		.BYTE	$FF		; ASTOP
