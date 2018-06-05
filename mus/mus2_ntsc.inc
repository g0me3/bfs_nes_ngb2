
		.BYTE	$05
		CHNL_PTR	NOISE,_mus2_A
		CHNL_PTR	NOISE,_mus2_B
		CHNL_PTR	SQUA0,_mus2_C
		CHNL_PTR	TRIAN,_mus2_D
		CHNL_PTR	SQUA1,_mus2_E
_mus2_A:
		ACMDF2		$04
		ADMC		_pcm0A
		ADATA		$9F
		ADATA		$1F
		ADMC		_pcm1
		ADATA		$9F
		ADMC		_pcm0A
		ADATA		$5F
		ADMC		_pcm1
		ADATA		$7F
		ADATA		$3F
		ADATA		$3F
		ADATA		$1E
		ADATA		$5D
		ADATA		$7E
		ASTOP
_mus2_B:
		ACMDF2		$04
		ACMDF0		$0D
		ACMDF4		$00
		ASMPL		_sample19
		ADATA		$2D
		ACMDF1		$FE
		ASMPL		_sample13
		ADATA		$05
		ADATA		$25
		ACMDF1		$02
		ASMPL		_sample19
		ADATA		$0D
		ASMPL		_sample20
		ADATA		$24
		ACMDF1		$FE
		ASMPL		_sample13
		ADATA		$05
		ASMPL		_sample18
		ADATA		$23
		ASMPL		_sample19
		ACMDF1		$02
		ADATA		$4D
		ASMPL		_sample20
		ADATA		$44
		ASMPL		_sample13
		ADATA		$05
		ASMPL		_sample20
		ADATA		$24
		ADATA		$24
		ASMPL		_sample14
		ADATA		$06
		ADATA		$47
		ASMPL		_sample20
		ACMDF1		$02
		ADATA		$63
		ASTOP
_mus2_C:
		ACMDF2		$04
		ACMDF0		$0E
		ASMPL		_sample26
		ACMDF4		$00
		ACMDF5		$11
_aloc_508FF:
		AJSR		_asub_50909
		AJSR		_asub_50912
		AJSR		_asub_5091C
		ASTOP
_asub_50909:
		ADATA		$31
		ADATA		$1D
		ADATA		$30
		ADATA		$18
		ADATA		$3B
		ADATA		$1D
		ADATA		$20
		ADATA		$1B
		ARET
_asub_50912:
		ADATA		$30
		ADATA		$1D
		ADATA		$3C
		ADATA		$1D
		ADATA		$39
		ADATA		$1D
		ADATA		$38
		ADATA		$1D
		ADATA		$30
		ARET
_asub_5091C:
		ACMDF5		$11
		ASMPL		_sample20
		ADATAEX		$D7,$3C
		ARET
_mus2_D:
		ACMDF2		$04
		ACMDF0		$0F
		ACMDF4		$00
		ACMDF5		$29
		ASMPL		_sample00
		AJMP		_aloc_508FF
		ASTOP
_mus2_E:
		ACMDF2		$04
		ACMDF0		$0C
		ASMPL		_sample18
		ACMDF5		$18
		ACMDF4		$FF
		AJSR		_asub_50909
		ASMPL		_sample1C
		ACMDF5		$35
		ACMDF4		$00
		ACMDF0		$09
		ADATA		$30
		AJSR		_asub_50954
		ASMPL		_sample2B
		ACMDF5		$11
		ADATAEX		$D0,$0F
		ADATAEX		$D7,$3C
		ADATA		$B0
		ASTOP
_asub_50954:
		ADATA		$09
		ADATA		$08
		ADATA		$1D
		ADATA		$09
		ADATA		$05
		ADATA		$1D
		ADATA		$09
		ADATA		$04
		ADATA		$1D
		ADATA		$09
		ARET
