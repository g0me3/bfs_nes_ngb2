
		.BYTE	$05
		.WORD	_mus5_A
		.BYTE	$0C
		.WORD	_mus5_B
		.BYTE	$08
		.WORD	_mus5_C
		.BYTE	$0C
		.WORD	_mus5_D
		.BYTE	$00
		.WORD	_mus5_E
		.BYTE	$04
_mus5_A:
		.BYTE	$F2,$0B		; ACMDF2      $0B
		.BYTE	$FA		; AJSR	_asub_9947B
		.WORD	_asub_9947B
		.BYTE	$FA		; AJSR	_asub_993F3
		.WORD	_asub_993F3
		.BYTE	$FA		; AJSR	_asub_99405
		.WORD	_asub_99405
		.BYTE	$FA		; AJSR	_asub_993F3
		.WORD	_asub_993F3
		.BYTE	$FA		; AJSR	_asub_99464
		.WORD	_asub_99464
_aloc_993CB:
		.BYTE	$FA		; AJSR	_asub_993F3
		.WORD	_asub_993F3
		.BYTE	$FA		; AJSR	_asub_99405
		.WORD	_asub_99405
		.BYTE	$FA		; AJSR	_asub_993F3
		.WORD	_asub_993F3
		.BYTE	$FA		; AJSR	_asub_99417
		.WORD	_asub_99417
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_993F3
		.WORD	_asub_993F3
		.BYTE	$FA		; AJSR	_asub_99405
		.WORD	_asub_99405
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_993F3
		.WORD	_asub_993F3
		.BYTE	$FA		; AJSR	_asub_99417
		.WORD	_asub_99417
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_9942D
		.WORD	_asub_9942D
		.BYTE	$FA		; AJSR	_asub_99445
		.WORD	_asub_99445
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_993CB
		.WORD	_aloc_993CB
		.BYTE	$FF		; ASTOP
_asub_993F3:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_asub_99405:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_asub_99417:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$DF,$11		; ADATAEX     $DF,$11
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_9942D:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$DF,$12		; ADATAEX     $DF,$12
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DD,$11		; ADATAEX     $DD,$11
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FB		; ARET
_asub_99445:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$DF,$11		; ADATAEX     $DF,$11
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_99464:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DF,$02		; ADATAEX     $DF,$02
		.BYTE	$DF,$04		; ADATAEX     $DF,$04
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_asub_9947B:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$BF		; ADATA	$BF
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_mus5_B:
		.BYTE	$F2,$0B		; ACMDF2      $0B
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$D0,$5D		; ADATAEX     $D0,$5D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_994B5
		.WORD	_asub_994B5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_994C4
		.WORD	_asub_994C4
_aloc_9949D:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_994B5
		.WORD	_asub_994B5
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_994C4
		.WORD	_asub_994C4
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FA		; AJSR	_asub_994D4
		.WORD	_asub_994D4
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_9949D
		.WORD	_aloc_9949D
		.BYTE	$FF		; ASTOP
_asub_994B5:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$74		; ADATA	$74
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$38		; ADATA	$38
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$B9		; ADATA	$B9
		.BYTE	$FB		; ARET
_asub_994C4:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$74		; ADATA	$74
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$38		; ADATA	$38
		.BYTE	$39		; ADATA	$39
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$79		; ADATA	$79
		.BYTE	$59		; ADATA	$59
		.BYTE	$FB		; ARET
_asub_994D4:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$D4,$2F		; ADATAEX     $D4,$2F
		.BYTE	$A0		; ADATA	$A0
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$D2,$2F		; ADATAEX     $D2,$2F
		.BYTE	$DE,$2E		; ADATAEX     $DE,$2E
		.BYTE	$DD,$2F		; ADATAEX     $DD,$2F
		.BYTE	$B1		; ADATA	$B1
		.BYTE	$BC		; ADATA	$BC
		.BYTE	$C3,$18		; ADATAEX     $C3,$18
		.BYTE	$BC		; ADATA	$BC
		.BYTE	$A5		; ADATA	$A5
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$FB		; ARET
_mus5_C:
		.BYTE	$F2,$0B		; ACMDF2      $0B
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_9958F
		.WORD	_asub_9958F
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_9951C
		.WORD	_asub_9951C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99570
		.WORD	_asub_99570
_aloc_994FA:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_9951C
		.WORD	_asub_9951C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9952F
		.WORD	_asub_9952F
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_9951C
		.WORD	_asub_9951C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9952F
		.WORD	_asub_9952F
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_99543
		.WORD	_asub_99543
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_9955C
		.WORD	_asub_9955C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_994FA
		.WORD	_aloc_994FA
		.BYTE	$FF		; ASTOP
_asub_9951C:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$45		; ADATA	$45
		.BYTE	$65		; ADATA	$65
		.BYTE	$65		; ADATA	$65
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$FB		; ARET
_asub_9952F:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$45		; ADATA	$45
		.BYTE	$65		; ADATA	$65
		.BYTE	$65		; ADATA	$65
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$46		; ADATA	$46
		.BYTE	$FB		; ARET
_asub_99543:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$44		; ADATA	$44
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$44		; ADATA	$44
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$FB		; ARET
_asub_9955C:
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$64		; ADATA	$64
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$24		; ADATA	$24
		.BYTE	$25		; ADATA	$25
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
_asub_99570:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$64		; ADATA	$64
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$45		; ADATA	$45
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C6,$04		; ADATAEX     $C6,$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$26		; ADATA	$26
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$66		; ADATA	$66
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FB		; ARET
_asub_9958F:
		.BYTE	$F6,$2D		; ACMDF6      $2D
		.BYTE	$F4,$78		; ACMDF4      $78
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$25		; ADATA	$25
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$27		; ADATA	$27
		.BYTE	$F1,$06		; ACMDF1      $06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$26		; ADATA	$26
		.BYTE	$06		; ADATA	$06
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_mus5_D:
		.BYTE	$F2,$0B		; ACMDF2      $0B
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$CD,$45		; ADATAEX     $CD,$45
		.BYTE	$CD,$00		; ADATAEX     $CD,$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$06		; ACMDF3      $06
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_99609
		.WORD	_asub_99609
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_99618
		.WORD	_asub_99618
_aloc_995CF:
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$FA		; AJSR	_asub_996DE
		.WORD	_asub_996DE
		.BYTE	$FA		; AJSR	_asub_99716
		.WORD	_asub_99716
		.BYTE	$FA		; AJSR	_asub_996DE
		.WORD	_asub_996DE
		.BYTE	$FA		; AJSR	_asub_996FD
		.WORD	_asub_996FD
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FA		; AJSR	_asub_99629
		.WORD	_asub_99629
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FA		; AJSR	_asub_996DE
		.WORD	_asub_996DE
		.BYTE	$FA		; AJSR	_asub_99716
		.WORD	_asub_99716
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FA		; AJSR	_asub_99629
		.WORD	_asub_99629
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FA		; AJSR	_asub_996DE
		.WORD	_asub_996DE
		.BYTE	$FA		; AJSR	_asub_996FD
		.WORD	_asub_996FD
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FA		; AJSR	_asub_99656
		.WORD	_asub_99656
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_995CF
		.WORD	_aloc_995CF
		.BYTE	$FF		; ASTOP
_asub_99609:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$74		; ADATA	$74
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$38		; ADATA	$38
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$B9		; ADATA	$B9
		.BYTE	$FB		; ARET
_asub_99618:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$74		; ADATA	$74
		.BYTE	$54		; ADATA	$54
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$38		; ADATA	$38
		.BYTE	$39		; ADATA	$39
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$79		; ADATA	$79
		.BYTE	$59		; ADATA	$59
		.BYTE	$FB		; ARET
_asub_99629:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$03		; ADATA	$03
		.BYTE	$30		; ADATA	$30
		.BYTE	$20		; ADATA	$20
		.BYTE	$10		; ADATA	$10
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$63		; ADATA	$63
		.BYTE	$D0,$2D		; ADATAEX     $D0,$2D
		.BYTE	$20		; ADATA	$20
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$CB,$01		; ADATAEX     $CB,$01
		.BYTE	$C0,$00		; ADATAEX     $C0,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0A		; ACMDF3      $0A
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$32		; ADATAEX     $D0,$32
		.BYTE	$FB		; ARET
_asub_99656:
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$11		; ADATAEX     $C3,$11
		.BYTE	$F4,$6F		; ACMDF4      $6F
		.BYTE	$C0,$11		; ADATAEX     $C0,$11
		.BYTE	$FD		; ALOOP_END
		.BYTE	$63		; ADATA	$63
		.BYTE	$40		; ADATA	$40
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$40		; ADATA	$40
		.BYTE	$FB		; ARET
_mus5_E:
		.BYTE	$F2,$0B		; ACMDF2      $0B
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$C1,$45		; ADATAEX     $C1,$45
		.BYTE	$C1,$00		; ADATAEX     $C1,$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$06		; ACMDF3      $06
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$FA		; AJSR	_asub_996BC
		.WORD	_asub_996BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_996CD
		.WORD	_asub_996CD
_aloc_9968F:
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$FA		; AJSR	_asub_996BC
		.WORD	_asub_996BC
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_996CD
		.WORD	_asub_996CD
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F5,$1D		; ACMDF5      $1D
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_99731
		.WORD	_asub_99731
		.BYTE	$FA		; AJSR	_asub_99731
		.WORD	_asub_99731
		.BYTE	$FA		; AJSR	_asub_9973F
		.WORD	_asub_9973F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_9975D
		.WORD	_asub_9975D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_9968F
		.WORD	_aloc_9968F
		.BYTE	$FF		; ASTOP
_asub_996BC:
		.BYTE	$F5,$11		; ACMDF5      $11
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$A5		; ADATA	$A5
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$FB		; ARET
_asub_996CD:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$7B		; ADATA	$7B
		.BYTE	$5B		; ADATA	$5B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$65		; ADATA	$65
		.BYTE	$45		; ADATA	$45
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$FB		; ARET
_asub_996DE:
		.BYTE	$F5,$29		; ACMDF5      $29
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$44		; ADATA	$44
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$20		; ADATA	$20
		.BYTE	$30		; ADATA	$30
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$62		; ADATA	$62
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$D0,$1C		; ADATAEX     $D0,$1C
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FB		; ARET
_asub_996FD:
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$B0		; ADATA	$B0
		.BYTE	$F1,$09		; ACMDF1      $09
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$C1,$01		; ADATAEX     $C1,$01
		.BYTE	$02		; ADATA	$02
		.BYTE	$F1,$F9		; ACMDF1      $F9
		.BYTE	$30		; ADATA	$30
		.BYTE	$F1,$07		; ACMDF1      $07
		.BYTE	$C0,$16		; ADATAEX     $C0,$16
		.BYTE	$FB		; ARET
_asub_99716:
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$D0,$16		; ADATAEX     $D0,$16
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$20		; ADATA	$20
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$D0,$1D		; ADATAEX     $D0,$1D
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FB		; ARET
_unref_0:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$09		; ACMDF6      $09
_asub_99731:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$34		; ADATA	$34
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$20		; ADATA	$20
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$23		; ADATA	$23
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$23		; ADATA	$23
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$00		; ADATA	$00
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$FB		; ARET
_asub_9973F:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$37		; ADATA	$37
		.BYTE	$20		; ADATA	$20
		.BYTE	$23		; ADATA	$23
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$27		; ADATA	$27
		.BYTE	$00		; ADATA	$00
		.BYTE	$FD		; ALOOP_END
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$20		; ADATA	$20
		.BYTE	$03		; ADATA	$03
		.BYTE	$20		; ADATA	$20
		.BYTE	$27		; ADATA	$27
		.BYTE	$23		; ADATA	$23
		.BYTE	$20		; ADATA	$20
		.BYTE	$3C		; ADATA	$3C
		.BYTE	$20		; ADATA	$20
		.BYTE	$23		; ADATA	$23
		.BYTE	$28		; ADATA	$28
		.BYTE	$00		; ADATA	$00
		.BYTE	$2A		; ADATA	$2A
		.BYTE	$25		; ADATA	$25
		.BYTE	$22		; ADATA	$22
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$25		; ADATA	$25
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FB		; ARET
_asub_9975D:
		.BYTE	$F5,$35		; ACMDF5      $35
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$11		; ADATAEX     $C7,$11
		.BYTE	$F4,$6F		; ACMDF4      $6F
		.BYTE	$C3,$11		; ADATAEX     $C3,$11
		.BYTE	$FD		; ALOOP_END
		.BYTE	$67		; ADATA	$67
		.BYTE	$43		; ADATA	$43
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$20		; ADATA	$20
		.BYTE	$22		; ADATA	$22
		.BYTE	$43		; ADATA	$43
		.BYTE	$FB		; ARET
