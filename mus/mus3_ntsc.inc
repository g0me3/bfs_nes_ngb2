
		.BYTE	$05
		CHNL_PTR	NOISE,_mus3_A
		CHNL_PTR	SQUA0,_mus3_B
		CHNL_PTR	SQUA1,_mus3_C
		CHNL_PTR	TRIAN,_mus3_D
		CHNL_PTR	NOISE,_mus3_E
_mus3_A:
		ACMDF2		$04
		ADMC		_pcm0A
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$9E
		ADMC		_pcm0A
		ADATA		$1F
		ADMC		_pcm1
		ADATA		$5E
		ADMC		_pcm0A
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$3E
		ADMC		_pcm0A
		ADATA		$5F
		ADATA		$1F
		ADMC		_pcm1
		ADATA		$1E
		ADATA		$1E
		ADATA		$1D
		ADATAEX		$CF,$0D
		ADATAEX		$DE,$0F
		ADATAEX		$DE,$0B
		ADATAEX		$DD,$0B
		ADATA		$BD
		ASTOP
_mus3_B:
		ACMDF2		$04
		ACMDF0		$0E
		ASMPL		_sample21
		ACMDF5		$33
		ACMDF4		$FF
		ADATA		$30
		ADATA		$02
		ADATA		$21
		ADATA		$1D
		ADATA		$3B
		ADATA		$1C
		ADATA		$3D
		ADATA		$17
		ADATA		$38
		ADATA		$02
		ADATA		$21
		ADATA		$1D
		ACMDF4		$00
		ADATAEX		$C3,$02
		ACMDF4		$FF
		ADATAEX		$C4,$0A
		ADATA		$07
		ADATA		$3F
		ADATA		$1B
		ADATAEX		$D0,$0D
		ACMDF4		$00
		ACMDF0		$0F
		ASMPL		_sample21
		ADATAEX		$DD,$0F
		ADATAEX		$DD,$0B
		ADATAEX		$DD,$0B
		ADATAEX		$DC,$03
		ADATAEX		$DD,$00
		ACMDE3		$00
		ACMDF3		$0F
		ACMDF0		$0B
		ALOOP_START	$05
		ACMDE3		$04
		ACMDF3		$02
		ALOOP_END
		ASTOP
_mus3_C:
		ACMDF2		$04
		ACMDF0		$0D
		ASMPL		_sample19
		ACMDF4		$00
		ACMDF5		$0F
		ACMDF4		$00
		ADATA		$31
		ASMPL		_sample21
		ACMDF4		$FF
		ACMDF5		$33
		ADATA		$1D
		ADATA		$3B
		ADATA		$18
		ADATA		$36
		ADATA		$15
		ADATA		$38
		ADATA		$11
		ADATA		$33
		ADATA		$1D
		ADATA		$3B
		ADATA		$18
		ADATA		$3D
		ADATA		$1F
		ADATA		$3B
		ADATA		$13
		ADATAEX		$D0,$0D
		ACMDF4		$00
		ASMPL		_sample21
		ACMDF0		$0F
		ADATAEX		$DA,$0F
		ADATAEX		$DA,$0B
		ADATAEX		$DA,$0B
		ADATAEX		$D9,$03
		ADATAEX		$DA,$00
		ACMDE3		$00
		ACMDF3		$0F
		ACMDF0		$0B
		ALOOP_START	$05
		ACMDE3		$04
		ACMDF3		$02
		ALOOP_END
		ASTOP
_mus3_D:
		ACMDF2		$04
		ACMDF0		$0F
		ASMPL		_sample00
		ACMDF5		$1B
		ACMDF4		$C8
		ADATA		$5D
		ADATA		$29
		ADATA		$5D
		ADATA		$09
		ADATA		$29
		ADATA		$08
		ADATA		$47
		ADATA		$3B
		ADATA		$47
		ADATA		$1B
		ADATA		$27
		ADATA		$1B
		ADATAEX		$D0,$0D
		ADATAEX		$C2,$0F
		ADATAEX		$C2,$0B
		ADATAEX		$C2,$0B
		ACMDF4		$00
		ADATA		$42
		ASTOP
_mus3_E:
		ACMDF2		$04
		ACMDF0		$0D
		ACMDF4		$00
		ALOOP_START	$03
		ASMPL		_sample13
		ADATA		$04
		ADATA		$05
		ADATA		$05
		ASMPL		_sample20
		ADATA		$24
		ASMPL		_sample13
		ADATA		$04
		ALOOP_END
		ADATA		$04
		ADATA		$05
		ADATA		$05
		ASMPL		_sample20
		ADATA		$04
		ASMPL		_sample19
		ADATA		$06
		ADATA		$07
		ADATAEX		$CF,$0D
		ACMDF0		$0F
		ASMPL		_sample20
		ADATAEX		$C4,$0F
		ASMPL		_sample1A
		ADATAEX		$C7,$0B
		ADATAEX		$C8,$0B
		ASMPL		_sample20
		ADATA		$64
		ASTOP
