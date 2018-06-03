
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
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$FA		; AJSR	_asub_50F76
		.WORD	_asub_50F76
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F04
		.WORD	_asub_50F04
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F5F
		.WORD	_asub_50F5F
_aloc_50ECA:
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F04
		.WORD	_asub_50F04
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F16
		.WORD	_asub_50F16
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F04
		.WORD	_asub_50F04
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50EF2
		.WORD	_asub_50EF2
		.BYTE	$FA		; AJSR	_asub_50F16
		.WORD	_asub_50F16
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FA		; AJSR	_asub_50F2B
		.WORD	_asub_50F2B
		.BYTE	$FA		; AJSR	_asub_50F41
		.WORD	_asub_50F41
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50ECA
		.WORD	_aloc_50ECA
		.BYTE	$FF		; ASTOP
_asub_50EF2:
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
_asub_50F04:
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
_asub_50F16:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_50F2B:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$5D		; ADATA	$5D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_50F41:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$5F		; ADATA	$5F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$FB		; ARET
_asub_50F5F:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$DF,$02		; ADATAEX     $DF,$02
		.BYTE	$DF,$05		; ADATAEX     $DF,$05
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_asub_50F76:
		.BYTE	$E0,$F6,$08		; ACMDE0      $F6,$08
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$7F		; ADATA	$7F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$FB		; ARET
_mus5_B:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$D0,$70		; ADATAEX     $D0,$70
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_50FB0
		.WORD	_asub_50FB0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50FBF
		.WORD	_asub_50FBF
_aloc_50F98:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_50FB0
		.WORD	_asub_50FB0
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_50FBF
		.WORD	_asub_50FBF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_50FCF
		.WORD	_asub_50FCF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50F98
		.WORD	_aloc_50F98
		.BYTE	$FF		; ASTOP
_asub_50FB0:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$C8		; ACMDF4      $C8
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$79		; ADATA	$79
		.BYTE	$FB		; ARET
_asub_50FBF:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$39		; ADATA	$39
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_50FCF:
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$B4		; ADATA	$B4
		.BYTE	$60		; ADATA	$60
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$B2		; ADATA	$B2
		.BYTE	$BE		; ADATA	$BE
		.BYTE	$BD		; ADATA	$BD
		.BYTE	$71		; ADATA	$71
		.BYTE	$7C		; ADATA	$7C
		.BYTE	$63		; ADATA	$63
		.BYTE	$7C		; ADATA	$7C
		.BYTE	$65		; ADATA	$65
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$FB		; ARET
_mus5_C:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_51085
		.WORD	_asub_51085
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51012
		.WORD	_asub_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51066
		.WORD	_asub_51066
_aloc_50FF0:
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51012
		.WORD	_asub_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51025
		.WORD	_asub_51025
		.BYTE	$FC,$07		; ALOOP_START $07
		.BYTE	$FA		; AJSR	_asub_51012
		.WORD	_asub_51012
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51025
		.WORD	_asub_51025
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_51039
		.WORD	_asub_51039
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_51052
		.WORD	_asub_51052
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_50FF0
		.WORD	_aloc_50FF0
		.BYTE	$FF		; ASTOP
_asub_51012:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$FB		; ARET
_asub_51025:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$26		; ADATA	$26
		.BYTE	$FB		; ARET
_asub_51039:
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$02		; ACMDF1      $02
		.BYTE	$24		; ADATA	$24
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$FB		; ARET
_asub_51052:
		.BYTE	$F6,$1B		; ACMDF6      $1B
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$24		; ADATA	$24
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$04		; ACMDF1      $04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_51066:
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$F6,$19		; ACMDF6      $19
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$C6,$02		; ADATAEX     $C6,$02
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$C6,$05		; ADATAEX     $C6,$05
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$26		; ADATA	$26
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FB		; ARET
_asub_51085:
		.BYTE	$F6,$2D		; ACMDF6      $2D
		.BYTE	$F4,$78		; ACMDF4      $78
		.BYTE	$F1,$FD		; ACMDF1      $FD
		.BYTE	$FC,$06		; ALOOP_START $06
		.BYTE	$05		; ADATA	$05
		.BYTE	$F1,$FA		; ACMDF1      $FA
		.BYTE	$07		; ADATA	$07
		.BYTE	$F1,$06		; ACMDF1      $06
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F1,$03		; ACMDF1      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$06		; ADATA	$06
		.BYTE	$06		; ADATA	$06
		.BYTE	$05		; ADATA	$05
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_mus5_D:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$02		; ACMDF0      $02
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$CD,$54		; ADATAEX     $CD,$54
		.BYTE	$CD,$00		; ADATAEX     $CD,$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$07		; ACMDF3      $07
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$10		; ACMDF6      $10
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_510FF
		.WORD	_asub_510FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_5110E
		.WORD	_asub_5110E
_aloc_510C5:
		.BYTE	$F0,$09		; ACMDF0      $09
		.BYTE	$F6,$27		; ACMDF6      $27
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_5120C
		.WORD	_asub_5120C
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_511F3
		.WORD	_asub_511F3
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FA		; AJSR	_asub_5111F
		.WORD	_asub_5111F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_5120C
		.WORD	_asub_5120C
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FA		; AJSR	_asub_5111F
		.WORD	_asub_5111F
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F6,$18		; ACMDF6      $18
		.BYTE	$FA		; AJSR	_asub_511D5
		.WORD	_asub_511D5
		.BYTE	$FA		; AJSR	_asub_511F3
		.WORD	_asub_511F3
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FA		; AJSR	_asub_5114E
		.WORD	_asub_5114E
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_510C5
		.WORD	_aloc_510C5
		.BYTE	$FF		; ASTOP
_asub_510FF:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$7E		; ADATA	$7E
		.BYTE	$79		; ADATA	$79
		.BYTE	$FB		; ARET
_asub_5110E:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$34		; ADATA	$34
		.BYTE	$34		; ADATA	$34
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$18		; ADATA	$18
		.BYTE	$19		; ADATA	$19
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$39		; ADATA	$39
		.BYTE	$39		; ADATA	$39
		.BYTE	$FB		; ARET
_asub_5111F:
		.BYTE	$F6,$28		; ACMDF6      $28
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$06		; ADATAEX     $C3,$06
		.BYTE	$10		; ADATA	$10
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$11		; ADATAEX     $C3,$11
		.BYTE	$D0,$34		; ADATAEX     $D0,$34
		.BYTE	$00		; ADATA	$00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F1,$FC		; ACMDF1      $FC
		.BYTE	$CB,$01		; ADATAEX     $CB,$01
		.BYTE	$C0,$00		; ADATAEX     $C0,$00
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$0D		; ACMDF3      $0D
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$01		; ACMDE3      $01
		.BYTE	$F3,$02		; ACMDF3      $02
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$FD		; ALOOP_END
		.BYTE	$D0,$3E		; ADATAEX     $D0,$3E
		.BYTE	$FB		; ARET
_asub_5114E:
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C2,$01		; ADATAEX     $C2,$01
		.BYTE	$C3,$14		; ADATAEX     $C3,$14
		.BYTE	$F4,$6F		; ACMDF4      $6F
		.BYTE	$40		; ADATA	$40
		.BYTE	$FD		; ALOOP_END
		.BYTE	$23		; ADATA	$23
		.BYTE	$20		; ADATA	$20
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$20		; ADATA	$20
		.BYTE	$FB		; ARET
_mus5_E:
		.BYTE	$F2,$01		; ACMDF2      $01
		.BYTE	$F0,$04		; ACMDF0      $04
		.BYTE	$F6,$AB		; ACMDF6      $AB
		.BYTE	$F5,$33		; ACMDF5      $33
		.BYTE	$C1,$54		; ADATAEX     $C1,$54
		.BYTE	$C1,$00		; ADATAEX     $C1,$00
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$E3,$00		; ACMDE3      $00
		.BYTE	$F3,$07		; ACMDF3      $07
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0C		; ACMDF0      $0C
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$26		; ACMDF6      $26
		.BYTE	$FA		; AJSR	_asub_511B3
		.WORD	_asub_511B3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_511C4
		.WORD	_asub_511C4
_aloc_51186:
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F6,$15		; ACMDF6      $15
		.BYTE	$FA		; AJSR	_asub_511B3
		.WORD	_asub_511B3
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_511C4
		.WORD	_asub_511C4
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F0,$0A		; ACMDF0      $0A
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$F6,$1D		; ACMDF6      $1D
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FA		; AJSR	_asub_51225
		.WORD	_asub_51225
		.BYTE	$FA		; AJSR	_asub_51225
		.WORD	_asub_51225
		.BYTE	$FA		; AJSR	_asub_51233
		.WORD	_asub_51233
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_51251
		.WORD	_asub_51251
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_51186
		.WORD	_aloc_51186
		.BYTE	$FF		; ASTOP
_asub_511B3:
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$FA		; ACMDF4      $FA
		.BYTE	$65		; ADATA	$65
		.BYTE	$7D		; ADATA	$7D
		.BYTE	$FB		; ARET
_asub_511C4:
		.BYTE	$F4,$B1		; ACMDF4      $B1
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$3B		; ADATA	$3B
		.BYTE	$F4,$FF		; ACMDF4      $FF
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$A6		; ACMDF4      $A6
		.BYTE	$25		; ADATA	$25
		.BYTE	$25		; ADATA	$25
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$3D		; ADATA	$3D
		.BYTE	$FB		; ARET
_asub_511D5:
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$30		; ADATA	$30
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$24		; ADATA	$24
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$00		; ADATA	$00
		.BYTE	$10		; ADATA	$10
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$22		; ADATA	$22
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$90		; ADATA	$90
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FB		; ARET
_asub_511F3:
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$09		; ACMDF1      $09
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$C1,$01		; ADATAEX     $C1,$01
		.BYTE	$C2,$06		; ADATAEX     $C2,$06
		.BYTE	$F1,$F9		; ACMDF1      $F9
		.BYTE	$10		; ADATA	$10
		.BYTE	$F1,$07		; ACMDF1      $07
		.BYTE	$60		; ADATA	$60
		.BYTE	$FB		; ARET
_asub_5120C:
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$70		; ADATA	$70
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$00		; ADATA	$00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$F4,$BC		; ACMDF4      $BC
		.BYTE	$00		; ADATA	$00
		.BYTE	$F1,$F8		; ACMDF1      $F8
		.BYTE	$90		; ADATA	$90
		.BYTE	$F1,$08		; ACMDF1      $08
		.BYTE	$FB		; ARET
_unref_10:
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F6,$09		; ACMDF6      $09
_asub_51225:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$14		; ADATA	$14
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$03		; ADATA	$03
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$03		; ADATA	$03
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$00		; ADATA	$00
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$FB		; ARET
_asub_51233:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$17		; ADATA	$17
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$07		; ADATA	$07
		.BYTE	$00		; ADATA	$00
		.BYTE	$FD		; ALOOP_END
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$07		; ADATA	$07
		.BYTE	$03		; ADATA	$03
		.BYTE	$00		; ADATA	$00
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$00		; ADATA	$00
		.BYTE	$03		; ADATA	$03
		.BYTE	$08		; ADATA	$08
		.BYTE	$00		; ADATA	$00
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$05		; ADATA	$05
		.BYTE	$02		; ADATA	$02
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$05		; ADATA	$05
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$FB		; ARET
_asub_51251:
		.BYTE	$F5,$34		; ACMDF5      $34
		.BYTE	$F6,$21		; ACMDF6      $21
		.BYTE	$FC,$04		; ALOOP_START $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$C6,$01		; ADATAEX     $C6,$01
		.BYTE	$C7,$14		; ADATAEX     $C7,$14
		.BYTE	$F4,$6F		; ACMDF4      $6F
		.BYTE	$43		; ADATA	$43
		.BYTE	$FD		; ALOOP_END
		.BYTE	$27		; ADATA	$27
		.BYTE	$23		; ADATA	$23
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$00		; ADATA	$00
		.BYTE	$02		; ADATA	$02
		.BYTE	$23		; ADATA	$23
		.BYTE	$FB		; ARET
