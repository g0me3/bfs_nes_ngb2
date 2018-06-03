
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_52671
		.WORD	_asub_52671
		.BYTE	$FA		; AJSR	_asub_5268D
		.WORD	_asub_5268D
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52671
		.WORD	_asub_52671
		.BYTE	$FA		; AJSR	_asub_526AA
		.WORD	_asub_526AA
		.BYTE	$F8		; AJMP	_aloc_5265C
		.WORD	_musB_A
		.BYTE	$FF		; ASTOP
_asub_52671:
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
_asub_5268D:
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
_asub_526AA:
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F0,$0E		; ACMDF0      $0E
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_526DD
		.WORD	_asub_526DD
		.BYTE	$FA		; AJSR	_asub_526F8
		.WORD	_asub_526F8
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_526DD
		.WORD	_asub_526DD
		.BYTE	$FA		; AJSR	_asub_52711
		.WORD	_asub_52711
		.BYTE	$F8		; AJMP	_aloc_526C4
		.WORD	_musB_B
		.BYTE	$FF		; ASTOP
_asub_526DD:
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
_asub_526F8:
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
_asub_52711:
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$00		; ACMDF6      $00
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$13		; ACMDF5      $13
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_5277C
		.WORD	_asub_5277C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_52781
		.WORD	_asub_52781
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_5277C
		.WORD	_asub_5277C
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_52772
		.WORD	_asub_52772
		.BYTE	$FA		; AJSR	_asub_52781
		.WORD	_asub_52781
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$F5,$1A		; ACMDF5      $1A
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$F5,$1B		; ACMDF5      $1B
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$F5,$1A		; ACMDF5      $1A
		.BYTE	$FA		; AJSR	_asub_52786
		.WORD	_asub_52786
		.BYTE	$FA		; AJSR	_asub_52797
		.WORD	_asub_52797
		.BYTE	$F8		; AJMP	_aloc_52726
		.WORD	_musB_C
		.BYTE	$FF		; ASTOP
_asub_52772:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_5277C:
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$01		; ADATA	$01
		.BYTE	$06		; ADATA	$06
		.BYTE	$FB		; ARET
_asub_52781:
		.BYTE	$07		; ADATA	$07
		.BYTE	$01		; ADATA	$01
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$FB		; ARET
_asub_52786:
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
_asub_52797:
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$24		; ACMDF6      $24
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$F5,$03		; ACMDF5      $03
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527F7
		.WORD	_asub_527F7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527FC
		.WORD	_asub_527FC
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527F7
		.WORD	_asub_527F7
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_527ED
		.WORD	_asub_527ED
		.BYTE	$FA		; AJSR	_asub_527FC
		.WORD	_asub_527FC
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F6,$22		; ACMDF6      $22
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52801
		.WORD	_asub_52801
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$26		; ACMDF5      $26
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52801
		.WORD	_asub_52801
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_527A8
		.WORD	_musB_D
		.BYTE	$FF		; ASTOP
_asub_527ED:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_527F7:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_527FC:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_asub_52801:
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
		.BYTE	$F2,$04		; ACMDF2      $04
		.BYTE	$F0,$0F		; ACMDF0      $0F
		.BYTE	$F6,$22		; ACMDF6      $22
		.BYTE	$F5,$03		; ACMDF5      $03
		.BYTE	$F4,$00		; ACMDF4      $00
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_52857
		.WORD	_asub_52857
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_5285C
		.WORD	_asub_5285C
		.BYTE	$F5,$0F		; ACMDF5      $0F
		.BYTE	$FC,$03		; ALOOP_START $03
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_52857
		.WORD	_asub_52857
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FA		; AJSR	_asub_5284D
		.WORD	_asub_5284D
		.BYTE	$FA		; AJSR	_asub_5285C
		.WORD	_asub_5285C
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$F5,$27		; ACMDF5      $27
		.BYTE	$F0,$0D		; ACMDF0      $0D
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52861
		.WORD	_asub_52861
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F5,$26		; ACMDF5      $26
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$FA		; AJSR	_asub_52861
		.WORD	_asub_52861
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FD		; ALOOP_END
		.BYTE	$F8		; AJMP	_aloc_5280A
		.WORD	_musB_E
		.BYTE	$FF		; ASTOP
_asub_5284D:
		.BYTE	$FC,$02		; ALOOP_START $02
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$FD		; ALOOP_END
		.BYTE	$FB		; ARET
_asub_52857:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$05		; ADATA	$05
		.BYTE	$0A		; ADATA	$0A
		.BYTE	$FB		; ARET
_asub_5285C:
		.BYTE	$0B		; ADATA	$0B
		.BYTE	$05		; ADATA	$05
		.BYTE	$0E		; ADATA	$0E
		.BYTE	$0F		; ADATA	$0F
		.BYTE	$FB		; ARET
_asub_52861:
		.BYTE	$30		; ADATA	$30
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$24		; ADATA	$24
		.BYTE	$44		; ADATA	$44
		.BYTE	$04		; ADATA	$04
		.BYTE	$24		; ADATA	$24
		.BYTE	$FB		; ARET
