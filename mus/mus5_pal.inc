
		.BYTE	$05
		CHNL_PTR	NOISE,_mus5_A
		CHNL_PTR	TRIAN,_mus5_B
		CHNL_PTR	NOISE,_mus5_C
		CHNL_PTR	SQUA0,_mus5_D
		CHNL_PTR	SQUA1,_mus5_E
_mus5_A:
		ACMDF2		$0B
		AJSR		_asub_9947B
		AJSR		_asub_993F3
		AJSR		_asub_99405
		AJSR		_asub_993F3
		AJSR		_asub_99464
_aloc_993CB:
		AJSR		_asub_993F3
		AJSR		_asub_99405
		AJSR		_asub_993F3
		AJSR		_asub_99417
		ALOOP_START	$03
		AJSR		_asub_993F3
		AJSR		_asub_99405
		ALOOP_END
		AJSR		_asub_993F3
		AJSR		_asub_99417
		ALOOP_START	$04
		AJSR		_asub_9942D
		AJSR		_asub_99445
		ALOOP_END
		AJMP		_aloc_993CB
_asub_993F3:
		ADMC		_pcm0A
		ADATA		$BF
		ADMC		_pcm1
		ADATA		$BE
		ADMC		_pcm0A
		ADATA		$7F
		ADATA		$7F
		ADMC		_pcm1
		ADATA		$BE
		ARET
_asub_99405:
		ADMC		_pcm0A
		ADATA		$7F
		ADATA		$7F
		ADMC		_pcm1
		ADATA		$BE
		ADMC		_pcm0A
		ADATA		$BF
		ADMC		_pcm1
		ADATA		$BE
		ARET
_asub_99417:
		ADMC		_pcm0A
		ADATA		$7F
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$BE
		ADMC		_pcm0A
		ADATAEX		$DF,$11
		ADATA		$3F
		ADMC		_pcm1
		ADATA		$3F
		ADATA		$3F
		ADATA		$7D
		ARET
_asub_9942D:
		ADMC		_pcm0A
		ADATAEX		$DF,$12
		ADATA		$3F
		ADMC		_pcm1
		ADATA		$BD
		ADMC		_pcm0A
		ADATA		$BF
		ADMC		_pcm1
		ADATAEX		$DD,$11
		ADMC		_pcm0A
		ADATA		$3F
		ARET
_asub_99445:
		ADMC		_pcm0A
		ADATAEX		$DF,$11
		ADATA		$3F
		ADMC		_pcm1
		ADATA		$7D
		ADMC		_pcm0A
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$5E
		ADATA		$3E
		ADMC		_pcm0A
		ADATA		$3F
		ADMC		_pcm1
		ADATA		$3F
		ADATA		$3E
		ADATA		$3E
		ADATA		$3D
		ARET
_asub_99464:
		ADMC		_pcm0A
		ADATA		$BF
		ADMC		_pcm1
		ADATA		$BD
		ADMC		_pcm0A
		ADATA		$7F
		ADATA		$5F
		ADMC		_pcm1
		ADATAEX		$DF,$02
		ADATAEX		$DF,$04
		ADATA		$3F
		ADATA		$7E
		ARET
_asub_9947B:
		ADMC		_pcm0A
		ADATA		$BF
		ADATA		$BF
		ADATA		$7F
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$3F
		ADATA		$3F
		ADATA		$3E
		ADATA		$3E
		ARET
_mus5_B:
		ACMDF2		$0B
		ACMDF5		$1D
		ASMPL		_sample00
		ACMDF0		$0F
		ADATAEX		$D0,$5D
		ALOOP_START	$03
		AJSR		_asub_994B5
		ALOOP_END
		AJSR		_asub_994C4
_aloc_9949D:
		ALOOP_START	$03
		ALOOP_START	$03
		AJSR		_asub_994B5
		ALOOP_END
		AJSR		_asub_994C4
		ALOOP_END
		ALOOP_START	$02
		ACMDF5		$1D
		AJSR		_asub_994D4
		ALOOP_END
		AJMP		_aloc_9949D
_asub_994B5:
		ACMDF4		$B1
		ADATA		$74
		ADATA		$54
		ACMDF4		$00
		ADATA		$38
		ADATA		$39
		ADATA		$3B
		ADATA		$30
		ACMDF4		$C8
		ADATA		$BE
		ADATA		$B9
		ARET
_asub_994C4:
		ACMDF4		$B1
		ADATA		$74
		ADATA		$54
		ACMDF4		$00
		ADATA		$38
		ADATA		$39
		ACMDF4		$A6
		ADATA		$7B
		ADATA		$7E
		ADATA		$5E
		ADATA		$79
		ADATA		$59
		ARET
_asub_994D4:
		ACMDF4		$FF
		ADATAEX		$D4,$2F
		ADATA		$A0
		ADATA		$BE
		ADATAEX		$D2,$2F
		ADATAEX		$DE,$2E
		ADATAEX		$DD,$2F
		ADATA		$B1
		ADATA		$BC
		ADATAEX		$C3,$18
		ADATA		$BC
		ADATA		$A5
		ADATA		$BE
		ARET
_mus5_C:
		ACMDF2		$0B
		ACMDF0		$0D
		ACMDF4		$00
		AJSR		_asub_9958F
		ALOOP_START	$03
		AJSR		_asub_9951C
		ALOOP_END
		AJSR		_asub_99570
_aloc_994FA:
		ALOOP_START	$03
		AJSR		_asub_9951C
		ALOOP_END
		AJSR		_asub_9952F
		ALOOP_START	$07
		AJSR		_asub_9951C
		ALOOP_END
		AJSR		_asub_9952F
		ALOOP_START	$04
		ALOOP_START	$03
		AJSR		_asub_99543
		ALOOP_END
		AJSR		_asub_9955C
		ALOOP_END
		AJMP		_aloc_994FA
_asub_9951C:
		ASMPL		_sample13
		ADATA		$65
		ADATA		$45
		ASMPL		_sample20
		ADATA		$64
		ASMPL		_sample13
		ADATA		$45
		ADATA		$65
		ADATA		$65
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ADATA		$65
		ARET
_asub_9952F:
		ASMPL		_sample13
		ADATA		$65
		ADATA		$45
		ASMPL		_sample20
		ADATA		$64
		ASMPL		_sample13
		ADATA		$45
		ADATA		$65
		ADATA		$65
		ASMPL		_sample19
		ADATA		$25
		ADATA		$25
		ASMPL		_sample20
		ADATA		$46
		ARET
_asub_99543:
		ASMPL		_sample19
		ACMDF1		$02
		ADATA		$44
		ACMDF1		$FA
		ASMPL		_sample13
		ADATA		$25
		ADATA		$25
		ACMDF1		$04
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ACMDF1		$FC
		ADATA		$25
		ADATA		$25
		ACMDF1		$04
		ARET
_asub_9955C:
		ASMPL		_sample1B
		ACMDF1		$FF
		ADATA		$64
		ADATA		$24
		ASMPL		_sample13
		ACMDF1		$FD
		ADATA		$25
		ACMDF1		$04
		ASMPL		_sample20
		ADATA		$24
		ADATA		$24
		ADATA		$25
		ADATA		$24
		ARET
_asub_99570:
		ASMPL		_sample13
		ADATA		$65
		ADATA		$45
		ASMPL		_sample20
		ADATA		$64
		ASMPL		_sample13
		ADATA		$45
		ADATA		$65
		ADATA		$45
		ASMPL		_sample19
		ACMDF1		$FD
		ADATAEX		$C6,$02
		ACMDF1		$01
		ADATAEX		$C6,$04
		ACMDF1		$01
		ADATA		$26
		ASMPL		_sample20
		ADATA		$66
		ACMDF1		$01
		ARET
_asub_9958F:
		ASMPL		_sample2D
		ACMDF4		$78
		ACMDF1		$FD
		ALOOP_START	$06
		ADATA		$25
		ACMDF1		$FA
		ADATA		$27
		ACMDF1		$06
		ALOOP_END
		ACMDF1		$03
		ACMDF4		$00
		ASMPL		_sample20
		ADATA		$26
		ADATA		$06
		ADATA		$05
		ADATA		$04
		ARET
_mus5_D:
		ACMDF2		$0B
		ACMDF0		$02
		ASMPL		_sample00
		ASMPL		_sample2B|SMPL_FORCE
		ACMDF5		$34
		ADATAEX		$CD,$45
		ADATAEX		$CD,$00
		ALOOP_START	$04
		ACMDE3		$00
		ACMDF3		$06
		ACMDF1		$01
		ALOOP_END
		ACMDF0		$0D
		ASMPL		_sample10
		ACMDF5		$1D
		ALOOP_START	$03
		AJSR		_asub_99609
		ALOOP_END
		AJSR		_asub_99618
_aloc_995CF:
		ACMDF0		$09
		ASMPL		_sample27
		AJSR		_asub_996DE
		AJSR		_asub_99716
		AJSR		_asub_996DE
		AJSR		_asub_996FD
		ACMDF0		$0D
		AJSR		_asub_99629
		ACMDF0		$0D
		ASMPL		_sample18
		AJSR		_asub_996DE
		AJSR		_asub_99716
		ACMDF0		$0D
		AJSR		_asub_99629
		ACMDF0		$0D
		ASMPL		_sample18
		AJSR		_asub_996DE
		AJSR		_asub_996FD
		ALOOP_START	$04
		ACMDF0		$0F
		AJSR		_asub_99656
		ALOOP_END
		AJMP		_aloc_995CF
_asub_99609:
		ACMDF4		$B1
		ADATA		$74
		ADATA		$54
		ACMDF4		$FF
		ADATA		$38
		ADATA		$39
		ADATA		$3B
		ADATA		$30
		ACMDF4		$FA
		ADATA		$BE
		ADATA		$B9
		ARET
_asub_99618:
		ACMDF4		$B1
		ADATA		$74
		ADATA		$54
		ACMDF4		$FF
		ADATA		$38
		ADATA		$39
		ADATA		$3B
		ADATA		$30
		ACMDF4		$A6
		ADATA		$7E
		ADATA		$5E
		ADATA		$79
		ADATA		$59
		ARET
_asub_99629:
		ASMPL		_sample28
		ACMDF5		$29
		ACMDF4		$00
		ADATAEX		$C2,$01
		ADATA		$03
		ADATA		$30
		ADATA		$20
		ADATA		$10
		ADATAEX		$C2,$01
		ADATA		$63
		ADATAEX		$D0,$2D
		ADATA		$20
		ADATA		$3E
		ADATA		$20
		ADATA		$30
		ADATA		$20
		ADATA		$30
		ACMDF1		$FC
		ADATAEX		$CB,$01
		ADATAEX		$C0,$00
		ACMDE3		$00
		ACMDF3		$0A
		ALOOP_START	$04
		ACMDE3		$01
		ACMDF3		$02
		ACMDF1		$FF
		ALOOP_END
		ADATAEX		$D0,$32
		ARET
_asub_99656:
		ASMPL		_sample21
		ALOOP_START	$04
		ACMDF4		$00
		ADATAEX		$C2,$01
		ADATAEX		$C3,$11
		ACMDF4		$6F
		ADATAEX		$C0,$11
		ALOOP_END
		ADATA		$63
		ADATA		$40
		ACMDF4		$00
		ADATA		$3E
		ADATA		$3F
		ADATA		$40
		ARET
_mus5_E:
		ACMDF2		$0B
		ACMDF0		$04
		ASMPL		_sample2B|SMPL_FORCE
		ACMDF5		$34
		ADATAEX		$C1,$45
		ADATAEX		$C1,$00
		ALOOP_START	$04
		ACMDE3		$00
		ACMDF3		$06
		ACMDF1		$01
		ALOOP_END
		ACMDF0		$0C
		ALOOP_START	$03
		ASMPL		_sample26
		AJSR		_asub_996BC
		ALOOP_END
		AJSR		_asub_996CD
_aloc_9968F:
		ACMDF0		$0D
		ALOOP_START	$03
		ALOOP_START	$03
		ASMPL		_sample15
		AJSR		_asub_996BC
		ALOOP_END
		AJSR		_asub_996CD
		ALOOP_END
		ACMDF0		$0A
		ACMDF5		$1D
		ASMPL		_sample1D
		ACMDF4		$00
		AJSR		_asub_99731
		AJSR		_asub_99731
		AJSR		_asub_9973F
		ACMDF0		$0D
		ALOOP_START	$02
		AJSR		_asub_9975D
		ALOOP_END
		AJMP		_aloc_9968F
_asub_996BC:
		ACMDF5		$11
		ACMDF4		$B1
		ADATA		$7B
		ADATA		$5B
		ACMDF4		$FF
		ADATA		$3B
		ADATA		$3E
		ADATA		$20
		ADATA		$30
		ACMDF4		$FA
		ADATA		$A5
		ADATA		$BD
		ARET
_asub_996CD:
		ACMDF4		$B1
		ADATA		$7B
		ADATA		$5B
		ACMDF4		$FF
		ADATA		$3B
		ADATA		$3E
		ADATA		$20
		ADATA		$30
		ACMDF4		$A6
		ADATA		$65
		ADATA		$45
		ADATA		$7D
		ADATA		$5D
		ARET
_asub_996DE:
		ACMDF5		$29
		ACMDF4		$BC
		ACMDF1		$F8
		ADATA		$70
		ACMDF1		$08
		ADATA		$20
		ADATA		$20
		ACMDF4		$00
		ADATA		$44
		ACMDF4		$BC
		ADATA		$20
		ADATA		$30
		ACMDF4		$00
		ADATA		$62
		ACMDF4		$BC
		ADATA		$3E
		ACMDF1		$F8
		ADATAEX		$D0,$1C
		ACMDF1		$08
		ARET
_asub_996FD:
		ACMDF1		$F8
		ADATA		$B0
		ACMDF1		$09
		ADATA		$20
		ADATA		$20
		ADATA		$20
		ADATA		$20
		ACMDF4		$00
		ACMDF1		$01
		ADATA		$7E
		ADATAEX		$C1,$01
		ADATA		$02
		ACMDF1		$F9
		ADATA		$30
		ACMDF1		$07
		ADATAEX		$C0,$16
		ARET
_asub_99716:
		ACMDF1		$F8
		ADATAEX		$D0,$16
		ACMDF1		$08
		ADATA		$20
		ADATA		$20
		ADATA		$20
		ADATA		$20
		ACMDF4		$00
		ADATA		$7E
		ACMDF4		$BC
		ADATA		$20
		ACMDF1		$F8
		ADATAEX		$D0,$1D
		ACMDF1		$08
		ARET
;_unref_0:
;		ACMDF4		$00
;		ASMPL		_sample09
_asub_99731:
		ALOOP_START	$02
		ADATA		$34
		ADATA		$3B
		ADATA		$20
		ADATA		$3B
		ADATA		$23
		ADATA		$1B
		ALOOP_END
		ADATA		$23
		ADATA		$3B
		ADATA		$00
		ADATA		$3B
		ARET
_asub_9973F:
		ALOOP_START	$02
		ADATA		$37
		ADATA		$20
		ADATA		$23
		ADATA		$3D
		ADATA		$27
		ADATA		$00
		ALOOP_END
		ADATA		$3C
		ADATA		$20
		ADATA		$03
		ADATA		$20
		ADATA		$27
		ADATA		$23
		ADATA		$20
		ADATA		$3C
		ADATA		$20
		ADATA		$23
		ADATA		$28
		ADATA		$00
		ADATA		$2A
		ADATA		$25
		ADATA		$22
		ADATA		$1E
		ADATA		$25
		ADATA		$3B
		ADATA		$3E
		ADATA		$0E
		ARET
_asub_9975D:
		ACMDF5		$35
		ASMPL		_sample21
		ALOOP_START	$04
		ACMDF4		$00
		ADATAEX		$C6,$01
		ADATAEX		$C7,$11
		ACMDF4		$6F
		ADATAEX		$C3,$11
		ALOOP_END
		ADATA		$67
		ADATA		$43
		ACMDF4		$00
		ADATA		$20
		ADATA		$22
		ADATA		$43
		ARET
