
		.BYTE	$05
		CHNL_PTR	NOISE,_mus8_A
		CHNL_PTR	NOISE,_mus8_B
		CHNL_PTR	SQUA0,_mus8_C
		CHNL_PTR	TRIAN,_mus8_D
		CHNL_PTR	SQUA1,_mus8_E
_mus8_A:
		ACMDF2		$05
		AJSR		_asub_5202D
_aloc_5200E:
		ALOOP_START	$07
		AJSR		_asub_52047
		AJSR		_asub_5205A
		AJSR		_asub_52070
		ALOOP_END
		AJSR		_asub_52047
		AJSR		_asub_5205A
		AJSR		_asub_52079
		ALOOP_START	$08
		AJSR		_asub_52082
		ALOOP_END
		AJMP		_aloc_5200E
_asub_5202D:
		ADMC		_pcm1
		ADATAEX		$DF,$03
		ADATAEX		$DF,$04
		ALOOP_START	$03
		ADMC		_pcm1
		ADATA		$3F
		ADATA		$5F
		ADMC		_pcm0A
		ADATA		$1F
		ALOOP_END
		ADMC		_pcm1
		ADATA		$5F
		ADATA		$3F
		ADATA		$1F
		ARET
_asub_52047:
		ADMC		_pcm0A
		ADATA		$BF
		ADMC		_pcm1
		ADATA		$BE
		ADMC		_pcm0A
		ADATA		$2F
		ADATA		$1F
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$BE
		ARET
_asub_5205A:
		ADMC		_pcm0A
		ADATA		$BF
		ADMC		_pcm1
		ADATA		$5E
		ADMC		_pcm0A
		ADATA		$3F
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$1F
		ADMC		_pcm0A
		ADATA		$5F
		ARET
_asub_52070:
		ADMC		_pcm1
		ADATA		$5F
		ADMC		_pcm0A
		ADATA		$5F
		ARET
_asub_52079:
		ADMC		_pcm1
		ADATA		$3F
		ADATA		$1F
		ADATA		$1F
		ADATA		$1F
		ADATA		$1E
		ARET
_asub_52082:
		ADMC		_pcm0A
		ADATA		$3F
		ADATA		$1F
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$9F
		ADMC		_pcm0A
		ADATA		$5F
		ADATA		$1F
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$5F
		ADMC		_pcm0A
		ADATA		$3F
		ADMC		_pcm1
		ADATA		$1F
		ARET
_mus8_B:
		ACMDF2		$05
		ACMDF0		$0D
		ACMDF4		$00
		AJSR		_asub_520C7
_aloc_520A8:
		ALOOP_START	$07
		AJSR		_asub_520D7
		AJSR		_asub_520F4
		AJSR		_asub_5210C
		ALOOP_END
		AJSR		_asub_520D7
		AJSR		_asub_520F4
		AJSR		_asub_52113
		ALOOP_START	$08
		AJSR		_asub_5211B
		ALOOP_END
		AJMP		_aloc_520A8
_asub_520C7:
		ASMPL		_sample19
		ADATAEX		$C6,$03
		ADATAEX		$C6,$04
		ALOOP_START	$03
		ADATA		$26
		ADATA		$46
		ADATA		$0E
		ALOOP_END
		ADATA		$46
		ADATA		$26
		ADATA		$06
		ARET
_asub_520D7:
		ASMPL		_sample19
		ADATA		$4D
		ASMPL		_sample13
		ADATA		$24
		ADATA		$04
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ADATA		$24
		ADATA		$44
		ASMPL		_sample19
		ADATA		$0D
		ADATA		$2D
		ASMPL		_sample13
		ADATA		$04
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ADATA		$24
		ADATA		$04
		ARET
_asub_520F4:
		ASMPL		_sample19
		ADATA		$4D
		ASMPL		_sample13
		ADATA		$24
		ADATA		$04
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample19
		ADATA		$2D
		ADATA		$0D
		ASMPL		_sample13
		ADATA		$24
		ASMPL		_sample20
		ADATA		$04
		ASMPL		_sample19
		ADATA		$4D
		ARET
_asub_5210C:
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample19
		ADATA		$4D
		ARET
_asub_52113:
		ASMPL		_sample20
		ADATA		$24
		ADATA		$04
		ADATA		$04
		ADATA		$06
		ADATA		$08
		ARET
_asub_5211B:
		ASMPL		_sample19
		ADATA		$4D
		ASMPL		_sample13
		ADATA		$24
		ADATA		$04
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ADATA		$24
		ADATA		$04
		ASMPL		_sample19
		ADATA		$2D
		ASMPL		_sample13
		ADATA		$04
		ASMPL		_sample15
		ADATA		$24
		ASMPL		_sample13
		ADATA		$04
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ADATA		$24
		ASMPL		_sample19
		ADATA		$06
		ARET
_mus8_C:
		ACMDF2		$05
		ADATAEX		$D0,$7F
_aloc_52143:
		ALOOP_START	$02
		ACMDF0		$0C
		ACMDF5		$27
		AJSR		_asub_52195
		AJSR		_asub_521AA
		ACMDF5		$33
		AJSR		_asub_521C1
		ALOOP_END
		ACMDF5		$33
		AJSR		_asub_521EB
		AJSR		_asub_5221D
		ADATA		$B0
		AJSR		_asub_52223
		ADATAEX		$D0,$2D
		AJSR		_asub_52223
		AJSR		_asub_521EB
		AJSR		_asub_52233
		ADATAEX		$D0,$12
		AJSR		_asub_52223
		ADATAEX		$D0,$2D
		AJSR		_asub_52223
		AJMP		_aloc_522B4
_aloc_52179:
		AJSR		_asub_5223F
		AJSR		_asub_52251
		AJSR		_asub_5223F
		AJSR		_asub_5225C
		AJSR		_asub_5223F
		AJSR		_asub_52251
		AJSR		_asub_5223F
		AJSR		_asub_5226C
		AJMP		_aloc_52289
_asub_52195:
		ASMPL		_sample25
		ACMDF4		$80
		ADATA		$44
		ADATA		$43
		ACMDF4		$FF
		ADATA		$22
		ADATA		$03
		ADATA		$22
		ADATA		$01
		ACMDF4		$80
		ADATA		$40
		ADATA		$5F
		ACMDF4		$F0
		ADATA		$5E
		ADATA		$5F
		ARET
_asub_521AA:
		ACMDF4		$80
		ADATA		$40
		ADATA		$5F
		ADATA		$5D
		ADATA		$5B
		ACMDF4		$00
		ADATA		$3D
		ACMDF4		$80
		ADATA		$5F
		ACMDF4		$FF
		ADATA		$58
		ACMDF1		$FE
		ADATA		$18
		ADATA		$3B
		ADATA		$18
		ACMDF1		$02
		ARET
_asub_521C1:
		ACMDF4		$FF
		ACMDF0		$0F
		ASMPL		_sample0B
		ADATA		$84
		ADATA		$04
		ADATA		$90
		ASMPL		_sample1C
		ACMDF0		$0D
		ACMDF4		$FF
		ALOOP_START	$05
		ADATAEX		$DF,$06
		ADATAEX		$C7,$06
		ACMDF1		$FE
		ALOOP_END
		ACMDF0		$0E
		ACMDF5		$1B
		ASMPL		_sample21
		ACMDF4		$90
		ADATA		$18
		ADATA		$5D
		ADATA		$5F
		ACMDF4		$FA
		ADATA		$9D
		ADATA		$5B
		ADATAEX		$D0,$32
		ARET
_asub_521EB:
		ADATA		$50
		ACMDF0		$0C
		ACMDF4		$C8
		ASMPL		_sample1F
		ADATA		$38
		ADATA		$10
		ADATA		$5F
		ADATA		$38
		ADATA		$10
		ADATA		$5D
		ADATA		$B0
		ADATA		$38
		ADATA		$10
		ADATA		$5B
		ADATA		$38
		ADATA		$10
		ADATA		$5D
		ADATA		$38
		ADATA		$10
		ACMDF4		$00
		ADATAEX		$DE,$01
		ADATAEX		$DF,$1D
		ASMPL		_sample1F
		ADATAEX		$C1,$01
		ADATAEX		$C2,$00
		ACMDE3		$00
		ACMDF3		$15
		ACMDF1		$FE
		ALOOP_START	$08
		ACMDE3		$01
		ACMDF3		$01
		ALOOP_END
		ACMDF1		$02
		ARET
_asub_5221D:
		ASMPL		_sample1F
		ACMDF4		$C8
		ADATA		$5D
		ARET
_asub_52223:
		ACMDF4		$DE
		ACMDF0		$0C
		ASMPL		_sample08
		ADATA		$2B
		ADATA		$0B
		ADATA		$30
		ADATA		$0B
		ADATA		$30
		ADATA		$0B
		ADATA		$29
		ADATA		$0B
		ADATA		$49
		ARET
_asub_52233:
		ACMDF4		$FC
		ACMDF0		$0F
		ASMPL		_sample1F
		ADATAEX		$C4,$06
		ADATAEX		$C2,$06
		ADATA		$5F
		ARET
_asub_5223F:
		ACMDF5		$33
		ASMPL		_sample27
		ACMDF4		$E9
		ADATAEX		$D0,$2D
		ADATA		$20
		ADATA		$10
		ADATA		$20
		ADATA		$00
		ADATA		$20
		ADATA		$22
		ADATA		$10
		ADATA		$20
		ADATA		$10
		ARET
_asub_52251:
		ADATAEX		$DF,$41
		ADATA		$9F
		ADATA		$3D
		ADATA		$10
		ADATA		$3F
		ADATA		$10
		ACMDF4		$00
		ADATA		$00
		ARET
_asub_5225C:
		ADATAEX		$DF,$00
		ACMDE3		$00
		ACMDF3		$1E
		ALOOP_START	$05
		ACMDE3		$01
		ACMDF3		$01
		ALOOP_END
		ADATAEX		$DD,$5A
		ARET
_asub_5226C:
		ACMDF4		$00
		ADATAEX		$DF,$23
		ADATAEX		$C9,$01
		ADATAEX		$CA,$01
		ADATAEX		$CB,$1C
		ADATA		$09
		ADATA		$0B
		ADATA		$09
		ADATA		$07
		ADATA		$04
		ADATA		$02
		ADATA		$04
		ADATA		$07
		ADATA		$04
		ADATA		$02
		ADATA		$1F
		ADATA		$03
		ARET
_mus8_D:
		ACMDF2		$05
		ACMDF0		$0F
		ADATAEX		$D0,$7F
_aloc_52289:
		ALOOP_START	$02
		ASMPL		_sample00
		ACMDF5		$27
		ALOOP_START	$04
		AJSR		_asub_522C5
		ALOOP_END
		ACMDF5		$33
		AJSR		_asub_522D0
		ALOOP_END
		ALOOP_START	$02
		ALOOP_START	$04
		ACMDF5		$27
		AJSR		_asub_522C5
		ALOOP_END
		AJSR		_asub_522FF
		AJSR		_asub_52308
		ADATAEX		$D0,$2D
		AJSR		_asub_52308
		ALOOP_END
		AJMP		_aloc_52179
_aloc_522B4:
		ALOOP_START	$04
		ACMDF5		$1B
		AJSR		_asub_52316
		ACMDF5		$1A
		AJSR		_asub_52316
		ALOOP_END
		AJMP		_aloc_52143
_asub_522C5:
		ACMDF4		$A6
		ADATA		$38
		ADATA		$1F
		ADATA		$3F
		ADATA		$18
		ADATA		$3F
		ADATA		$1F
		ADATA		$38
		ADATA		$1F
		ARET
_asub_522D0:
		ACMDF4		$00
		ADATA		$83
		ADATA		$03
		ADATA		$B0
		ACMDF5		$1B
		ACMDF4		$00
		ADATAEX		$DD,$01
		ADATAEX		$DE,$01
		ACMDF5		$27
		ACMDF4		$DE
		ADATAEX		$DF,$0D
		ADATA		$3D
		ADATA		$1B
		ADATA		$3D
		ADATA		$1B
		ADATA		$38
		ADATA		$16
		ACMDF4		$B1
		ADATA		$58
		ADATA		$58
		ACMDF4		$FF
		ADATA		$9D
		ADATA		$1B
		ACMDF4		$F0
		ACMDF5		$1B
		ADATA		$38
		ADATA		$1F
		ADATA		$24
		ADATA		$18
		ADATA		$04
		ADATA		$04
		ADATA		$04
		ADATA		$22
		ADATA		$04
		ARET
_asub_522FF:
		ACMDF4		$BC
		ADATA		$3F
		ADATA		$09
		ADATA		$2B
		ADATA		$1F
		ADATA		$29
		ADATA		$0B
		ARET
_asub_52308:
		ACMDF5		$33
		ACMDF4		$DE
		ADATA		$24
		ADATA		$04
		ADATA		$30
		ADATA		$04
		ADATA		$30
		ADATA		$04
		ADATA		$22
		ADATA		$04
		ADATA		$42
		ARET
_asub_52316:
		ACMDF4		$FA
		ACMDF0		$09
		ASMPL		_sample1C
		ADATA		$58
		ADATA		$40
		ADATA		$38
		ADATA		$00
		ADATA		$20
		ADATA		$1B
		ADATA		$38
		ADATA		$1B
		ADATA		$20
		ADATA		$18
		ADATA		$38
		ADATA		$00
		ADATA		$38
		ADATA		$14
		ARET
_mus8_E:
		ACMDF2		$05
		ADATAEX		$D0,$7F
_aloc_5232F:
		ALOOP_START	$02
		ACMDF0		$0E
		ACMDF5		$0F
		ASMPL		_sample26
		AJSR		_asub_52360
		AJSR		_asub_52373
		AJSR		_asub_52386
		AJSR		_asub_52360
		ALOOP_END
		ALOOP_START	$02
		AJSR		_asub_523AC
		AJSR		_asub_523E3
		ALOOP_END
		ALOOP_START	$04
		ACMDF0		$0F
		ACMDF5		$0F
		AJSR		_asub_5241D
		ACMDF5		$0E
		AJSR		_asub_5241D
		ALOOP_END
		AJMP		_aloc_5232F
_asub_52360:
		ACMDF4		$B1
		ADATA		$58
		ADATA		$58
		ACMDF4		$FF
		ADATA		$9D
		ADATA		$1B
		ACMDF4		$C8
		ADATA		$58
		ADATA		$50
		ADATA		$33
		ADATA		$1B
		ADATA		$30
		ACMDF4		$B1
		ADATA		$13
		ARET
_asub_52373:
		ACMDF4		$B1
		ADATA		$5F
		ADATA		$40
		ADATA		$5F
		ADATA		$40
		ACMDF4		$FF
		ADATA		$3F
		ADATA		$1D
		ACMDF4		$B1
		ADATA		$5B
		ACMDF4		$FF
		ADATA		$3D
		ADATA		$1B
		ADATA		$58
		ARET
_asub_52386:
		ACMDF4		$FF
		ADATA		$3B
		ADATA		$1D
		ACMDF4		$B1
		ADATA		$5F
		ADATA		$30
		ADATA		$13
		ACMDF4		$00
		ADATAEX		$DE,$01
		ACMDF4		$B1
		ADATAEX		$DF,$09
		ADATA		$10
		ACMDF4		$00
		ADATAEX		$DD,$01
		ADATAEX		$DE,$01
		ACMDF4		$DE
		ADATAEX		$DF,$0D
		ADATA		$3D
		ADATA		$1B
		ADATAEX		$DC,$01
		ADATAEX		$DD,$09
		ADATA		$1B
		ADATA		$38
		ADATA		$16
		ARET
_asub_523AC:
		ACMDF4		$00
		ADATAEX		$C2,$01
		ADATAEX		$C3,$01
		ADATAEX		$C4,$08
		ACMDF4		$FA
		ADATA		$1F
		ADATA		$58
		ADATA		$30
		ADATA		$18
		ADATA		$5F
		ADATA		$30
		ADATA		$18
		ADATA		$5D
		ACMDF4		$00
		ADATAEX		$DD,$01
		ADATAEX		$DE,$01
		ACMDF4		$FA
		ADATAEX		$DF,$0D
		ADATA		$3D
		ADATA		$1B
		ADATA		$3D
		ADATA		$1B
		ADATA		$58
		ADATA		$30
		ADATA		$18
		ADATAEX		$DE,$01
		ADATAEX		$DF,$0E
		ADATA		$30
		ADATA		$18
		ADATAEX		$DC,$01
		ADATAEX		$DD,$0E
		ACMDF4		$B1
		ADATA		$38
		ACMDF4		$FF
		ADATA		$13
		ADATA		$18
		ADATA		$1B
		ADATA		$1D
		ARET
_asub_523E3:
		ALOOP_START	$02
		ACMDF4		$00
		ADATAEX		$DD,$01
		ADATAEX		$DE,$01
		ACMDF4		$FA
		ADATAEX		$DF,$0D
		ALOOP_END
		ADATA		$30
		ADATA		$18
		ADATAEX		$DE,$01
		ADATAEX		$DF,$0E
		ADATA		$30
		ADATA		$18
		ADATAEX		$DC,$01
		ADATAEX		$DD,$0E
		ACMDF4		$00
		ADATAEX		$DD,$01
		ADATAEX		$DE,$01
		ACMDF4		$FA
		ADATAEX		$DF,$0D
		ADATA		$3D
		ADATA		$1B
		ADATA		$3D
		ADATA		$1B
		ADATA		$58
		ADATA		$30
		ADATA		$18
		ADATAEX		$DE,$01
		ADATAEX		$DF,$0E
		ADATA		$30
		ADATA		$18
		ADATAEX		$DC,$01
		ADATAEX		$DD,$0E
		ACMDF4		$00
		ADATA		$50
		ADATA		$33
		ADATA		$02
		ARET
_asub_5241D:
		ACMDF4		$9B
		ADATA		$54
		ADATA		$40
		ADATA		$54
		ACMDF4		$E6
		ADATA		$20
		ADATA		$00
		ADATA		$34
		ADATA		$00
		ADATA		$20
		ADATA		$14
		ADATA		$34
		ADATA		$00
		ADATA		$34
		ADATA		$00
		ARET
