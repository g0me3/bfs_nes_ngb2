
		.BYTE	$05
		.WORD	_musB_A
		.BYTE	$0C
		.WORD	_musB_B
		.BYTE	$0C
		.WORD	_musB_C
		.BYTE	$08
		.WORD	_musB_D
		.BYTE	$04
		.WORD	_musB_E
		.BYTE	$00
_musB_A:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98D8B
		.WORD	_asub_98D8B
		.BYTE	$FA		; AJSR	_asub_98DA7
		.WORD	_asub_98DA7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98D8B
		.WORD	_asub_98D8B
		.BYTE	$FA		; AJSR	_asub_98DC4
		.WORD	_asub_98DC4
		.BYTE	$F8		; AJMP	_aloc_98D76
		.WORD	_musB_A
		.BYTE	$FF		; ASTOP
_asub_98D8B:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$3F		; ADATA	$3F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_asub_98DA7:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1C		; ADATA	$1C
		.BYTE	$FB		; ARET
_asub_98DC4:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$E0,$F6,$08	; ACMDE0      $F6,$08
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FD		; ALOOP_END
		.BYTE	$E0,$F8,$1C	; ACMDE0      $F8,$1C
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$1F		; ADATA	$1F
		.BYTE	$FB		; ARET
_musB_B:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98DF7
		.WORD	_asub_98DF7
		.BYTE	$FA		; AJSR	_asub_98E12
		.WORD	_asub_98E12
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98DF7
		.WORD	_asub_98DF7
		.BYTE	$FA		; AJSR	_asub_98E2B
		.WORD	_asub_98E2B
		.BYTE	$F8		; AJMP	_aloc_98DDE
		.WORD	_musB_B
		.BYTE	$FF		; ASTOP
_asub_98DF7:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_98E12:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F1,$01		; ACMDF1      $01
		.BYTE	$03		; ADATA	$03
		.BYTE	$F1,$FF		; ACMDF1      $FF
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$FB		; ARET
_asub_98E2B:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$13		; ACMDF6      $13
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$04		; ADATA	$04
		.BYTE	$F6,$14		; ACMDF6      $14
		.BYTE	$06		; ADATA	$06
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$24		; ADATA	$24
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F6,$20		; ACMDF6      $20
		.BYTE	$03		; ADATA	$03
		.BYTE	$04		; ADATA	$04
		.BYTE	$05		; ADATA	$05
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_musB_C:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$14		; ACMDF5      $14
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98E8C
		.WORD	_asub_98E8C
		.BYTE	$FA		; AJSR	_asub_98E96
		.WORD	_asub_98E96
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98E8C
		.WORD	_asub_98E8C
		.BYTE	$FA		; AJSR	_asub_98E9B
		.WORD	_asub_98E9B
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98E8C
		.WORD	_asub_98E8C
		.BYTE	$FA		; AJSR	_asub_98E96
		.WORD	_asub_98E96
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98E8C
		.WORD	_asub_98E8C
		.BYTE	$FA		; AJSR	_asub_98E9B
		.WORD	_asub_98E9B
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$F5,$1C		; ACMDF5      $1C
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_98EA0
		.WORD	_asub_98EA0
		.BYTE	$FA		; AJSR	_asub_98EB1
		.WORD	_asub_98EB1
		.BYTE	$F8		; AJMP	_aloc_98E40
		.WORD	_musB_C
		.BYTE	$FF		; ASTOP
_asub_98E8C:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_98E96:
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_asub_98E9B:
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FB		; ARET
_asub_98EA0:
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$15		; ADATA	$15
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$01		; ADATA	$01
		.BYTE	$04		; ADATA	$04
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$15		; ADATA	$15
		.BYTE	$1B		; ADATA	$1B
		.BYTE	$1D		; ADATA	$1D
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$12		; ADATA	$12
		.BYTE	$03		; ADATA	$03
		.BYTE	$04		; ADATA	$04
		.BYTE	$FB		; ARET
_asub_98EB1:
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$18		; ADATA	$18
		.BYTE	$04		; ADATA	$04
		.BYTE	$01		; ADATA	$01
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$06		; ADATA	$06
		.BYTE	$07		; ADATA	$07
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$0D		; ADATA	$0D
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$04		; ADATA	$04
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$07		; ADATA	$07
		.BYTE	$04		; ADATA	$04
		.BYTE	$01		; ADATA	$01
		.BYTE	$FB		; ARET
_musB_D:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$24		; ACMDF6      $24
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$04		; ACMDF5      $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98F07
		.WORD	_asub_98F07
		.BYTE	$FA		; AJSR	_asub_98F11
		.WORD	_asub_98F11
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98F07
		.WORD	_asub_98F07
		.BYTE	$FA		; AJSR	_asub_98F16
		.WORD	_asub_98F16
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FA		; AJSR	_asub_98F07
		.WORD	_asub_98F07
		.BYTE	$FA		; AJSR	_asub_98F11
		.WORD	_asub_98F11
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98F07
		.WORD	_asub_98F07
		.BYTE	$FA		; AJSR	_asub_98F16
		.WORD	_asub_98F16
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$22		; ACMDF6      $22
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_98F1B
		.WORD	_asub_98F1B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_98F1B
		.WORD	_asub_98F1B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_98EC2
		.WORD	_musB_D
		.BYTE	$FF		; ASTOP
_asub_98F07:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_98F11:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_98F16:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_asub_98F1B:
		.BYTE	$30		; ADATA	$30
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$5E		; ADATA	$5E
		.BYTE	$1E		; ADATA	$1E
		.BYTE	$3E		; ADATA	$3E
		.BYTE	$FB		; ARET
_musB_E:
		.BYTE	$F2,$05		; ACMDF2      $05
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$F6,$22		; ACMDF6      $22
		.BYTE	$F5,$04		; ACMDF5      $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98F67
		.WORD	_asub_98F67
		.BYTE	$FA		; AJSR	_asub_98F71
		.WORD	_asub_98F71
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98F67
		.WORD	_asub_98F67
		.BYTE	$FA		; AJSR	_asub_98F76
		.WORD	_asub_98F76
		.BYTE	$F5,$10		; ACMDF5      $10
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_98F67
		.WORD	_asub_98F67
		.BYTE	$FA		; AJSR	_asub_98F71
		.WORD	_asub_98F71
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_98F67
		.WORD	_asub_98F67
		.BYTE	$FA		; AJSR	_asub_98F76
		.WORD	_asub_98F76
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$28		; ACMDF5      $28
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_98F7B
		.WORD	_asub_98F7B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_98F7B
		.WORD	_asub_98F7B
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_98F24
		.WORD	_musB_E
		.BYTE	$FF		; ASTOP
_asub_98F67:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_98F71:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_98F76:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_asub_98F7B:
		.BYTE	$30		; ADATA	$30
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$24		; ADATA	$24
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
