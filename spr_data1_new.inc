
_sprA01_00:
		.BYTE	$04
		.BYTE	$F0,$31,$43,$08
		.BYTE	$00,$33,$43,$08
		.BYTE	$00,$33,$03,$F0
		.BYTE	$F0,$31,$03,$F0
		.BYTE	$00
_sprA01_01:
		.BYTE	$02
		.BYTE	$F0,$EF,$83,$00
		.BYTE	$00,$EF,$03,$00
		.BYTE	$00
_sprA01_02:
		.BYTE	$06
		.BYTE	$0B,$F9,$43,$00
		.BYTE	$0B,$F9,$43,$F8
		.BYTE	$0B,$F9,$03,$F0 ; *
		.BYTE	$F8,$FB,$03,$00
		.BYTE	$F8,$EB,$03,$F8
		.BYTE	$F8,$DB,$03,$F0
		.BYTE	$00
_sprA01_03:
		.BYTE	$44,$03
		.BYTE	$0B,$F9,$F8
		.BYTE	$0B,$F9,$F0
		.BYTE	$F8,$DD,$F8
		.BYTE	$F8,$CD,$F0
		.BYTE	$00
_sprA01_04:
		.BYTE	$02
		.BYTE	$0B,$F9,$03,$F0 ; *
		.BYTE	$F4,$CB,$03,$F1
		.BYTE	$00
_sprA01_05:
		.BYTE	$01
		.BYTE	$00,$D9,$03,$FF
		.BYTE	$00
_sprA01_06:
		.BYTE	$01
		.BYTE	$00,$E9,$03,$FF
		.BYTE	$00
_sprA01_07:
		.BYTE	$02
		.BYTE	$F0,$AF,$40,$F8
		.BYTE	$00,$8B,$40,$F8
		.BYTE	$00
_sprA01_08:
		.BYTE	$04
		.BYTE	$00,$43,$02,$08
		.BYTE	$F0,$41,$02,$08
		.BYTE	$F0,$41,$42,$F0
		.BYTE	$00,$43,$42,$F0
		.BYTE	$00
_sprA01_09:
		.BYTE	$44,$02
		.BYTE	$00,$23,$08
		.BYTE	$F0,$21,$08
		.BYTE	$00,$33,$F0
		.BYTE	$F0,$31,$F0
		.BYTE	$00
_sprA01_0A:
		.BYTE	$04
_sprA01_0A_A:
		.BYTE	$00,$CF,$00,$08
		.BYTE	$00,$CF,$00,$00
		.BYTE	$00,$CF,$00,$F0
		.BYTE	$00,$CF,$00,$F8
		.BYTE	$00
_sprA01_0B:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$00
		.BYTE	$00,$DF,$00,$00
		.BYTE	$00
_sprA01_0C:
		.BYTE	$82
		.WORD	_sprA01_0A_A
		.BYTE	$00
_sprA01_0D:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$08
		.BYTE	$00,$DF,$00,$08
		.BYTE	$00
_sprA01_0E:
		.BYTE	$48,$03
		.BYTE	$F0,$7D,$08
		.BYTE	$F0,$7D,$00
		.BYTE	$F0,$7D,$F8
		.BYTE	$F0,$7D,$F0
		.BYTE	$00,$7F,$F0
		.BYTE	$00,$7F,$08
		.BYTE	$00,$7F,$00
		.BYTE	$00,$7F,$F8
		.BYTE	$00
_sprA01_0F:
		.BYTE	$44,$03
		.BYTE	$00,$6F,$08
		.BYTE	$00,$6F,$00
		.BYTE	$00,$6F,$F8
		.BYTE	$00,$6F,$F0
		.BYTE	$00
_sprA01_10:
		.BYTE	$44,$03
		.BYTE	$00,$7D,$08
		.BYTE	$00,$7D,$00
		.BYTE	$00,$7D,$F8
		.BYTE	$00,$7D,$F0
		.BYTE	$00
_sprA01_11:
		.BYTE	$02
		.BYTE	$F4,$5F,$03,$00
		.BYTE	$00,$5F,$03,$00
		.BYTE	$00
_sprA01_12:
		.BYTE	$02
		.BYTE	$F8,$5D,$03,$00
		.BYTE	$00,$5D,$03,$00 ; *
		.BYTE	$00
_sprA01_13:
		.BYTE	$02
		.BYTE	$FC,$5D,$03,$00
		.BYTE	$00,$5D,$03,$00 ; *
		.BYTE	$00
_sprA01_14:
		.BYTE	$01
		.BYTE	$00,$6D,$03,$00
		.BYTE	$00
_sprA01_15:
		.BYTE	$47,$22
		.BYTE	$00,$0F,$F0
		.BYTE	$00,$1F,$F8
		.BYTE	$00,$3D,$08
		.BYTE	$00,$3F,$00
		.BYTE	$F0,$0D,$F0
		.BYTE	$F0,$1D,$F8
		.BYTE	$F0,$3B,$00
		.BYTE	$00
_sprA01_16:
		.BYTE	$47,$62
		.BYTE	$00,$0F,$08
		.BYTE	$00,$1F,$00
		.BYTE	$00,$3D,$F0
		.BYTE	$00,$3F,$F8
		.BYTE	$F0,$0D,$08
		.BYTE	$F0,$1D,$00
		.BYTE	$F0,$3B,$F8
		.BYTE	$00
_sprA01_17:
		.BYTE	$50,$03
		.BYTE	$00,$8E,$18
		.BYTE	$00,$8C,$10
		.BYTE	$00,$8A,$08
		.BYTE	$00,$88,$00
		.BYTE	$00,$7E,$F8
		.BYTE	$00,$7C,$F0
		.BYTE	$00,$7A,$E8
		.BYTE	$00,$78,$E0
		.BYTE	$F0,$76,$18
		.BYTE	$F0,$74,$10
		.BYTE	$F0,$72,$08
		.BYTE	$F0,$68,$E0
		.BYTE	$F0,$6A,$E8
		.BYTE	$F0,$6C,$F0
		.BYTE	$F0,$6E,$F8
		.BYTE	$F0,$70,$00
		.BYTE	$00
_sprA01_18:
		.BYTE	$50,$03
		.BYTE	$00,$8F,$18
		.BYTE	$00,$8D,$10
		.BYTE	$00,$8B,$08
		.BYTE	$00,$89,$00
		.BYTE	$00,$7F,$F8
		.BYTE	$00,$7D,$F0
		.BYTE	$00,$7B,$E8
		.BYTE	$00,$79,$E0
		.BYTE	$F0,$77,$18
		.BYTE	$F0,$75,$10
		.BYTE	$F0,$73,$08
		.BYTE	$F0,$69,$E0
		.BYTE	$F0,$6B,$E8
		.BYTE	$F0,$6D,$F0
		.BYTE	$F0,$6F,$F8
		.BYTE	$F0,$71,$00
		.BYTE	$00
_sprA01_19:
		.BYTE	$02
		.BYTE	$F8,$BD,$00,$00
		.BYTE	$F8,$AD,$00,$F8
		.BYTE	$00
_sprA01_1A:
		.BYTE	$02
		.BYTE	$F8,$BD,$01,$00
		.BYTE	$F8,$AD,$01,$F8
		.BYTE	$00
_sprA01_1B:
		.BYTE	$02
		.BYTE	$F8,$BB,$00,$00
		.BYTE	$F8,$AB,$00,$F8
		.BYTE	$00
_sprA01_1C:
		.BYTE	$01
		.BYTE	$F8,$BF,$00,$FC
		.BYTE	$00
_sprA01_1D:
		.BYTE	$01
		.BYTE	$F8,$AF,$00,$FC
		.BYTE	$00
_sprA01_1E:
		.BYTE	$01
		.BYTE	$F8,$BF,$40,$FC
		.BYTE	$00
