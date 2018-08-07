
_sprA03_01:
		.BYTE	$24
_sprA03_01_A:
		.BYTE	$00,$24,$00,$F8
		.BYTE	$00,$34,$00,$00
_sprA03_01_B:
		.BYTE	$F1,$18,$00,$F8
		.BYTE	$F1,$18,$40,$00
_sprA03_02:
		.BYTE	$24
_sprA03_02_A:
		.BYTE	$00,$26,$00,$F8
		.BYTE	$00,$36,$00,$00
_sprA03_02_B:
		.BYTE	$F0,$18,$00,$F8
		.BYTE	$F0,$18,$40,$00
_sprA03_03:
		.BYTE	$02
_sprA03_03_A:
		.BYTE	$00,$24,$40,$00
		.BYTE	$00,$34,$40,$F8
		.BYTE	$A2
		.WORD	_sprA03_01_B
_sprA03_05:
		.BYTE	$24
_sprA03_05_A:
		.BYTE	$00,$2A,$40,$00
		.BYTE	$00,$3A,$40,$F8
_sprA03_05_B:
		.BYTE	$F1,$00,$40,$00
		.BYTE	$F1,$10,$40,$F8
_sprA03_06:
		.BYTE	$24
_sprA03_06_A:
		.BYTE	$00,$28,$40,$00
		.BYTE	$00,$38,$40,$F8
		.BYTE	$F0,$00,$40,$00
		.BYTE	$F0,$10,$40,$F8
_sprA03_07:
		.BYTE	$02
_sprA03_07_A:
		.BYTE	$00,$2A,$00,$F8
		.BYTE	$00,$3A,$00,$00
		.BYTE	$A2
		.WORD	_sprA03_05_B
_sprA03_09:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_09_B:
		.BYTE	$F1,$08,$00,$F8
		.BYTE	$F1,$08,$40,$00
_sprA03_0A:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_0A_B:
		.BYTE	$F0,$08,$00,$F8
		.BYTE	$F0,$08,$40,$00
_sprA03_0B:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_09_B
_sprA03_0D:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$22
_sprA03_0D_B:
		.BYTE	$F1,$00,$00,$F8
		.BYTE	$F1,$10,$00,$00
_sprA03_0E:
		.BYTE	$24
_sprA03_0E_A:
		.BYTE	$00,$28,$00,$F8
		.BYTE	$00,$38,$00,$00
		.BYTE	$F0,$00,$00,$F8
		.BYTE	$F0,$10,$00,$00
_sprA03_0F:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$A2
		.WORD	_sprA03_0D_B
_sprA03_11:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_11_B:
		.BYTE	$F1,$1A,$00,$F8
		.BYTE	$F1,$1A,$40,$00
_sprA03_12:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_12_B:
		.BYTE	$F0,$1A,$00,$F8
		.BYTE	$F0,$1A,$40,$00
_sprA03_13:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_11_B
_sprA03_15:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$22
_sprA03_15_B:
		.BYTE	$F1,$02,$40,$00
		.BYTE	$F1,$12,$40,$F8
_sprA03_16:
		.BYTE	$82
		.WORD	_sprA03_06_A
		.BYTE	$22
_sprA03_16_B:
		.BYTE	$F0,$02,$40,$00
		.BYTE	$F0,$12,$40,$F8
_sprA03_17:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$A2
		.WORD	_sprA03_15_B
_sprA03_19:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_19_B:
		.BYTE	$F1,$0A,$00,$F8
		.BYTE	$F1,$0A,$40,$00
_sprA03_1A:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_1A_B:
		.BYTE	$F0,$0A,$00,$F8
		.BYTE	$F0,$0A,$40,$00
_sprA03_1B:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_19_B
_sprA03_1D:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$22
_sprA03_1D_B:
		.BYTE	$F1,$02,$00,$F8
		.BYTE	$F1,$12,$00,$00
_sprA03_1E:
		.BYTE	$82
		.WORD	_sprA03_0E_A
		.BYTE	$22
_sprA03_1E_B:
		.BYTE	$F0,$02,$00,$F8
		.BYTE	$F0,$12,$00,$00
_sprA03_1F:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$A2
		.WORD	_sprA03_1D_B
_sprA03_21:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_21_B:
		.BYTE	$F1,$1C,$00,$F8
		.BYTE	$F1,$1C,$40,$00
_sprA03_22:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_22_B:
		.BYTE	$F0,$1C,$00,$F8
		.BYTE	$F0,$1C,$40,$00
_sprA03_23:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_21_B
_sprA03_25:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$22
_sprA03_25_A:
		.BYTE	$F1,$04,$40,$00
		.BYTE	$F1,$14,$40,$F8
_sprA03_26:
		.BYTE	$82
		.WORD	_sprA03_06_A
		.BYTE	$22
_sprA03_26_B:
		.BYTE	$F0,$04,$40,$00
		.BYTE	$F0,$14,$40,$F8
_sprA03_27:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$A2
		.WORD	_sprA03_25_A
_sprA03_29:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_29_A:
		.BYTE	$F1,$0C,$00,$F8
		.BYTE	$F1,$0C,$40,$00
_sprA03_2A:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_2A_B:
		.BYTE	$F0,$0C,$00,$F8
		.BYTE	$F0,$0C,$40,$00
_sprA03_2B:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_29_A
_sprA03_2D:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$22
_sprA03_2D_B:
		.BYTE	$F1,$04,$00,$F8
		.BYTE	$F1,$14,$00,$00
_sprA03_2E:
		.BYTE	$82
		.WORD	_sprA03_0E_A
		.BYTE	$22
_sprA03_2E_B:
		.BYTE	$F0,$04,$00,$F8
		.BYTE	$F0,$14,$00,$00
_sprA03_2F:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$A2
		.WORD	_sprA03_2D_B
_sprA03_31:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_31_B:
		.BYTE	$F1,$1E,$00,$F8
		.BYTE	$F1,$1E,$40,$00
_sprA03_32:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_32_B:
		.BYTE	$F0,$1E,$00,$F8
		.BYTE	$F0,$1E,$40,$00
_sprA03_33:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_31_B
_sprA03_35:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$22
_sprA03_35_B:
		.BYTE	$F1,$06,$40,$00
		.BYTE	$F1,$16,$40,$F8
_sprA03_36:
		.BYTE	$82
		.WORD	_sprA03_06_A
		.BYTE	$22
_sprA03_36_B:
		.BYTE	$F0,$06,$40,$00
		.BYTE	$F0,$16,$40,$F8
_sprA03_37:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$A2
		.WORD	_sprA03_35_B
_sprA03_39:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_39_A:
		.BYTE	$F1,$0E,$00,$F8
		.BYTE	$F1,$0E,$40,$00
_sprA03_3A:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_3A_B:
		.BYTE	$F0,$0E,$00,$F8
		.BYTE	$F0,$0E,$40,$00
_sprA03_3B:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_39_A
_sprA03_3D:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$22
_sprA03_3D_B:
		.BYTE	$F1,$06,$00,$F8
		.BYTE	$F1,$16,$00,$00
_sprA03_3E:
		.BYTE	$82
		.WORD	_sprA03_0E_A
		.BYTE	$22
_sprA03_3E_B:
		.BYTE	$F0,$06,$00,$F8
		.BYTE	$F0,$16,$00,$00
_sprA03_3F:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$A2
		.WORD	_sprA03_3D_B
_sprA03_41:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_41_B:
		.BYTE	$F1,$32,$00,$F8
		.BYTE	$F1,$32,$40,$00
_sprA03_42:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_42_B:
		.BYTE	$F0,$32,$00,$F8
		.BYTE	$F0,$32,$40,$00
_sprA03_43:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_41_B
_sprA03_45:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$22
_sprA03_45_B:
		.BYTE	$F1,$20,$40,$00
		.BYTE	$F1,$30,$40,$F8
_sprA03_46:
		.BYTE	$82
		.WORD	_sprA03_06_A
		.BYTE	$22
_sprA03_46_B:
		.BYTE	$F0,$20,$40,$00
		.BYTE	$F0,$30,$40,$F8
_sprA03_47:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$A2
		.WORD	_sprA03_45_B
_sprA03_49:
		.BYTE	$82
		.WORD	_sprA03_01_A
		.BYTE	$22
_sprA03_49_B:
		.BYTE	$F1,$22,$00,$F8
		.BYTE	$F1,$22,$40,$00
_sprA03_4A:
		.BYTE	$82
		.WORD	_sprA03_02_A
		.BYTE	$22
_sprA03_4A_B:
		.BYTE	$F0,$22,$00,$F8
		.BYTE	$F0,$22,$40,$00
_sprA03_4B:
		.BYTE	$82
		.WORD	_sprA03_03_A
		.BYTE	$A2
		.WORD	_sprA03_49_B
_sprA03_4D:
		.BYTE	$82
		.WORD	_sprA03_07_A
		.BYTE	$22
_sprA03_4D_B:
		.BYTE	$F1,$20,$00,$F8
		.BYTE	$F1,$30,$00,$00
_sprA03_4E:
		.BYTE	$82
		.WORD	_sprA03_0E_A
		.BYTE	$22
_sprA03_4E_B:
		.BYTE	$F0,$20,$00,$F8
		.BYTE	$F0,$30,$00,$00
_sprA03_4F:
		.BYTE	$82
		.WORD	_sprA03_05_A
		.BYTE	$A2
		.WORD	_sprA03_4D_B
_sprA03_52:
		.BYTE	$22
		.BYTE	$F4,$18,$00,$F8
		.BYTE	$F4,$18,$40,$00
_sprA03_53:
		.BYTE	$22
		.BYTE	$F5,$18,$00,$F8
		.BYTE	$F5,$18,$40,$00
_sprA03_56:
		.BYTE	$22
_sprA03_56_A:
		.BYTE	$F4,$00,$40,$00
		.BYTE	$F4,$10,$40,$F8
_sprA03_57:
		.BYTE	$22
		.BYTE	$F5,$00,$40,$00
		.BYTE	$F5,$10,$40,$F8
_sprA03_5A:
		.BYTE	$22
_sprA03_5A_A:
		.BYTE	$F4,$08,$00,$F8
		.BYTE	$F4,$08,$40,$00
_sprA03_5B:
		.BYTE	$22
_sprA03_5B_A:
		.BYTE	$F5,$08,$00,$F8
		.BYTE	$F5,$08,$40,$00
_sprA03_5E:
		.BYTE	$22
		.BYTE	$F4,$00,$00,$F8
		.BYTE	$F4,$10,$00,$00
_sprA03_5F:
		.BYTE	$22
		.BYTE	$F5,$00,$00,$F8
		.BYTE	$F5,$10,$00,$00
_sprA03_62:
		.BYTE	$22
		.BYTE	$F4,$1A,$00,$F8
		.BYTE	$F4,$1A,$40,$00
_sprA03_63:
		.BYTE	$22
		.BYTE	$F5,$1A,$00,$F8
		.BYTE	$F5,$1A,$40,$00
_sprA03_66:
		.BYTE	$22
		.BYTE	$F4,$02,$40,$00
		.BYTE	$F4,$12,$40,$F8
_sprA03_67:
		.BYTE	$22
		.BYTE	$F5,$02,$40,$00
		.BYTE	$F5,$12,$40,$F8
_sprA03_6A:
		.BYTE	$22
_sprA03_6A_A:
		.BYTE	$F4,$0A,$00,$F8
		.BYTE	$F4,$0A,$40,$00
_sprA03_6B:
		.BYTE	$22
_sprA03_6B_A:
		.BYTE	$F5,$0A,$00,$F8
		.BYTE	$F5,$0A,$40,$00
_sprA03_6E:
		.BYTE	$22
_sprA03_6E_A:
		.BYTE	$F4,$02,$00,$F8
		.BYTE	$F4,$12,$00,$00
_sprA03_6F:
		.BYTE	$22
		.BYTE	$F5,$02,$00,$F8
		.BYTE	$F5,$12,$00,$00
_sprA03_72:
		.BYTE	$22
		.BYTE	$F4,$1C,$00,$F8
		.BYTE	$F4,$1C,$40,$00
_sprA03_73:
		.BYTE	$22
		.BYTE	$F5,$1C,$00,$F8
		.BYTE	$F5,$1C,$40,$00
_sprA03_76:
		.BYTE	$22
		.BYTE	$F4,$04,$40,$00
		.BYTE	$F4,$14,$40,$F8
_sprA03_77:
		.BYTE	$22
		.BYTE	$F5,$04,$40,$00
		.BYTE	$F5,$14,$40,$F8
_sprA03_7A:
		.BYTE	$22
		.BYTE	$F4,$0C,$00,$F8
		.BYTE	$F4,$0C,$40,$00
_sprA03_7B:
		.BYTE	$22
		.BYTE	$F5,$0C,$00,$F8
		.BYTE	$F5,$0C,$40,$00
_sprA03_7E:
		.BYTE	$22
		.BYTE	$F4,$04,$00,$F8
		.BYTE	$F4,$14,$00,$00
_sprA03_7F:
		.BYTE	$22
		.BYTE	$F5,$04,$00,$F8
		.BYTE	$F5,$14,$00,$00
_sprA03_82:
		.BYTE	$22
		.BYTE	$F4,$1E,$00,$F8
		.BYTE	$F4,$1E,$40,$00
_sprA03_83:
		.BYTE	$22
		.BYTE	$F5,$1E,$00,$F8
		.BYTE	$F5,$1E,$40,$00
_sprA03_86:
		.BYTE	$22
		.BYTE	$F4,$06,$40,$00
		.BYTE	$F4,$16,$40,$F8
_sprA03_87:
		.BYTE	$22
		.BYTE	$F5,$06,$40,$00
		.BYTE	$F5,$16,$40,$F8
_sprA03_8A:
		.BYTE	$22
		.BYTE	$F4,$0E,$00,$F8
		.BYTE	$F4,$0E,$40,$00
_sprA03_8B:
		.BYTE	$22
		.BYTE	$F5,$0E,$00,$F8
		.BYTE	$F5,$0E,$40,$00
_sprA03_8E:
		.BYTE	$22
		.BYTE	$F4,$06,$00,$F8
		.BYTE	$F4,$16,$00,$00
_sprA03_8F:
		.BYTE	$22
		.BYTE	$F5,$06,$00,$F8
		.BYTE	$F5,$16,$00,$00
_sprA03_92:
		.BYTE	$22
		.BYTE	$F4,$32,$00,$F8
		.BYTE	$F4,$32,$40,$00
_sprA03_93:
		.BYTE	$22
		.BYTE	$F5,$32,$00,$F8
		.BYTE	$F5,$32,$40,$00
_sprA03_96:
		.BYTE	$22
		.BYTE	$F4,$20,$40,$00
		.BYTE	$F4,$30,$40,$F8
_sprA03_97:
		.BYTE	$22
		.BYTE	$F5,$20,$40,$00
		.BYTE	$F5,$30,$40,$F8
_sprA03_9A:
		.BYTE	$22
		.BYTE	$F4,$22,$00,$F8
		.BYTE	$F4,$22,$40,$00
_sprA03_9B:
		.BYTE	$22
		.BYTE	$F5,$22,$00,$F8
		.BYTE	$F5,$22,$40,$00
_sprA03_9E:
		.BYTE	$22
		.BYTE	$F4,$20,$00,$F8
		.BYTE	$F4,$30,$00,$00
_sprA03_9F:
		.BYTE	$22
		.BYTE	$F5,$20,$00,$F8
		.BYTE	$F5,$30,$00,$00
_sprA03_A0:
		.BYTE	$24
_sprA03_A0_A:
		.BYTE	$00,$4E,$00,$F8
		.BYTE	$00,$4E,$40,$00
		.BYTE	$F0,$4C,$00,$F8
		.BYTE	$F0,$4C,$40,$00
_sprA03_A1:
		.BYTE	$23
_sprA03_A1_A:
		.BYTE	$F8,$2C,$40,$04
		.BYTE	$F8,$2E,$40,$F4
		.BYTE	$F8,$3C,$40,$FC
_sprA03_A2:
		.BYTE	$24
_sprA03_A2_A:
		.BYTE	$00,$4C,$80,$F8
		.BYTE	$00,$4C,$C0,$00
		.BYTE	$F0,$4E,$80,$F8
		.BYTE	$F0,$4E,$C0,$00
_sprA03_A3:
		.BYTE	$23
_sprA03_A3_A:
		.BYTE	$F8,$2C,$00,$F6
		.BYTE	$F8,$2E,$00,$06
		.BYTE	$F8,$3C,$00,$FE
_sprA03_A4:
		.BYTE	$84
		.WORD	_sprA03_A0_A
		.BYTE	$22
		.BYTE	$F3,$48,$00,$07
		.BYTE	$FC,$48,$00,$F2
_sprA03_A5:
		.BYTE	$01
		.BYTE	$01,$48,$40,$0A
		.BYTE	$A3
		.WORD	_sprA03_A1_A
_sprA03_A6:
		.BYTE	$84
		.WORD	_sprA03_A2_A
		.BYTE	$22
		.BYTE	$F3,$48,$80,$06
		.BYTE	$FB,$48,$80,$F1
_sprA03_A7:
		.BYTE	$01
		.BYTE	$01,$48,$00,$F0
		.BYTE	$A3
		.WORD	_sprA03_A3_A
_sprA03_A8:
		.BYTE	$84
		.WORD	_sprA03_A0_A
		.BYTE	$22
		.BYTE	$F0,$58,$00,$0B
		.BYTE	$FE,$58,$00,$EF
_sprA03_A9:
		.BYTE	$83
		.WORD	_sprA03_A1_A
		.BYTE	$21
		.BYTE	$FC,$58,$40,$0D
_sprA03_AA:
		.BYTE	$84
		.WORD	_sprA03_A2_A
		.BYTE	$22
		.BYTE	$F0,$58,$80,$09
		.BYTE	$FE,$58,$80,$ED
_sprA03_AB:
		.BYTE	$83
		.WORD	_sprA03_A3_A
		.BYTE	$21
		.BYTE	$FC,$58,$00,$ED
_sprA03_AC:
		.BYTE	$26
		.BYTE	$02,$8F,$00,$FC
		.BYTE	$0A,$8F,$00,$FC
		.BYTE	$EA,$8D,$00,$FC
		.BYTE	$F2,$9F,$00,$04
		.BYTE	$F2,$9F,$40,$F4
		.BYTE	$FA,$8F,$00,$FC
_sprA03_AD:
		.BYTE	$27
		.BYTE	$F4,$8F,$80,$FE
		.BYTE	$F4,$9F,$00,$06
		.BYTE	$FC,$8F,$00,$06
		.BYTE	$FC,$8F,$00,$EE
		.BYTE	$FC,$8F,$00,$F6
		.BYTE	$FC,$9D,$00,$0E
		.BYTE	$FC,$9F,$80,$06
_sprA03_AE:
		.BYTE	$26
		.BYTE	$06,$8D,$80,$FC
		.BYTE	$E6,$8F,$80,$FC
		.BYTE	$EE,$8F,$80,$FC
		.BYTE	$F6,$8F,$80,$FC
		.BYTE	$FE,$9F,$80,$04
		.BYTE	$FE,$9F,$C0,$F4
_sprA03_AF:
		.BYTE	$27
		.BYTE	$F4,$8F,$80,$02
		.BYTE	$F4,$8F,$80,$0A
		.BYTE	$F4,$8F,$80,$FA
		.BYTE	$F4,$9F,$40,$F2
		.BYTE	$FC,$8F,$00,$F2
		.BYTE	$FC,$9D,$40,$EA
		.BYTE	$FC,$9F,$C0,$F2
_sprA04_00:
		.BYTE	$23
		.BYTE	$0C,$60,$01,$FC
		.BYTE	$EC,$60,$01,$FC
		.BYTE	$FC,$60,$01,$FC
_sprA04_01:
		.BYTE	$22
		.BYTE	$F4,$60,$01,$FC
		.BYTE	$04,$60,$01,$FC
_sprA04_02:
		.BYTE	$23
		.BYTE	$EC,$60,$41,$FC
		.BYTE	$0C,$60,$41,$FC
		.BYTE	$FC,$60,$41,$FC
_sprA04_03:
		.BYTE	$22
		.BYTE	$F4,$60,$41,$FC
		.BYTE	$04,$60,$41,$FC
_sprA04_04:
		.BYTE	$23
		.BYTE	$EC,$70,$01,$FC
		.BYTE	$0C,$70,$01,$FC
		.BYTE	$FC,$70,$01,$FC
_sprA04_05:
		.BYTE	$22
		.BYTE	$F4,$70,$01,$FC
		.BYTE	$04,$70,$01,$FC
_sprA04_06:
		.BYTE	$22
		.BYTE	$F4,$70,$41,$FC
		.BYTE	$04,$70,$41,$FC
_sprA04_07:
		.BYTE	$23
		.BYTE	$0C,$70,$41,$FC
		.BYTE	$EC,$70,$41,$FC
		.BYTE	$FC,$70,$41,$FC
_sprA04_08:
		.BYTE	$23
		.BYTE	$FC,$6C,$01,$0C
		.BYTE	$FC,$6C,$01,$EC
		.BYTE	$FC,$6C,$01,$FC
_sprA04_09:
		.BYTE	$22
		.BYTE	$FC,$6C,$01,$F4
		.BYTE	$FC,$6C,$01,$04
_sprA04_0A:
		.BYTE	$23
		.BYTE	$F4,$6C,$81,$EC
		.BYTE	$F4,$6C,$81,$0C
		.BYTE	$F4,$6C,$81,$FC
_sprA04_0B:
		.BYTE	$22
		.BYTE	$F4,$6C,$81,$F4
		.BYTE	$F4,$6C,$81,$04
_sprA04_0C:
		.BYTE	$23
		.BYTE	$FC,$7C,$01,$EC
		.BYTE	$FC,$7C,$01,$0C
		.BYTE	$FC,$7C,$01,$FC
_sprA04_0D:
		.BYTE	$22
		.BYTE	$FC,$7C,$01,$F4
		.BYTE	$FC,$7C,$01,$04
_sprA04_0E:
		.BYTE	$23
		.BYTE	$F4,$7C,$81,$0C
		.BYTE	$F4,$7C,$81,$FC
		.BYTE	$F4,$7C,$81,$EC
_sprA04_0F:
		.BYTE	$22
		.BYTE	$F4,$7C,$81,$04
		.BYTE	$F4,$7C,$81,$F4
_sprA04_11:
		.BYTE	$A3
		.WORD	_sprA04_1D_C
_sprA04_13:
		.BYTE	$A3
		.WORD	_sprA04_1F_C
_sprA04_14:
		.BYTE	$A2
		.WORD	_sprA04_1C_B
_sprA04_15:
		.BYTE	$A4
		.WORD	_sprA04_1D_B
_sprA04_16:
		.BYTE	$A2
		.WORD	_sprA04_1E_B
_sprA04_17:
		.BYTE	$A4
		.WORD	_sprA04_1F_B
_sprA04_19:
		.BYTE	$A5
		.WORD	_sprA04_1D_A
_sprA04_1B:
		.BYTE	$A5
		.WORD	_sprA04_1F_A
_sprA04_1C:
		.BYTE	$23
		.BYTE	$18,$56,$00,$FC
_sprA04_1C_B:
		.BYTE	$08,$56,$00,$FC
		.BYTE	$F8,$54,$00,$FC
_sprA04_1D:
		.BYTE	$26
		.BYTE	$F4,$46,$40,$D8
_sprA04_1D_A:
		.BYTE	$F4,$46,$40,$E0
_sprA04_1D_B:
		.BYTE	$F4,$46,$40,$E8
_sprA04_1D_C:
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$50,$40,$F8
		.BYTE	$F4,$40,$40,$00
_sprA04_1E:
		.BYTE	$23
		.BYTE	$D8,$56,$00,$FC
_sprA04_1E_B:
		.BYTE	$E8,$56,$00,$FC
		.BYTE	$F8,$54,$00,$FC
_sprA04_1F:
		.BYTE	$26
		.BYTE	$F4,$46,$00,$20
_sprA04_1F_A:
		.BYTE	$F4,$46,$00,$18
_sprA04_1F_B:
		.BYTE	$F4,$46,$00,$10
_sprA04_1F_C:
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$50,$00,$00
		.BYTE	$F4,$40,$00,$F8
_sprA04_21:
		.BYTE	$A3
		.WORD	_sprA04_2D_C
_sprA04_23:
		.BYTE	$A3
		.WORD	_sprA04_2F_C
_sprA04_24:
		.BYTE	$A2
		.WORD	_sprA04_2C_B
_sprA04_25:
		.BYTE	$A4
		.WORD	_sprA04_2D_B
_sprA04_26:
		.BYTE	$A2
		.WORD	_sprA04_2E_B
_sprA04_27:
		.BYTE	$A4
		.WORD	_sprA04_2F_B
_sprA04_29:
		.BYTE	$A5
		.WORD	_sprA04_2D_A
_sprA04_2B:
		.BYTE	$A5
		.WORD	_sprA04_2F_A
_sprA04_2C:
		.BYTE	$23
		.BYTE	$18,$56,$00,$FC
_sprA04_2C_B:
		.BYTE	$08,$56,$00,$FC
		.BYTE	$F8,$44,$00,$FC
_sprA04_2D:
		.BYTE	$26
		.BYTE	$F4,$46,$40,$D8
_sprA04_2D_A:
		.BYTE	$F4,$46,$40,$E0
_sprA04_2D_B:
		.BYTE	$F4,$46,$40,$E8
_sprA04_2D_C:
		.BYTE	$F4,$46,$40,$F0
		.BYTE	$F4,$42,$40,$00
		.BYTE	$F4,$52,$40,$F8
_sprA04_2E:
		.BYTE	$23
		.BYTE	$D8,$56,$00,$FC
_sprA04_2E_B:
		.BYTE	$E8,$56,$00,$FC
		.BYTE	$F8,$44,$00,$FC
_sprA04_2F:
		.BYTE	$26
		.BYTE	$F4,$46,$00,$20
_sprA04_2F_A:
		.BYTE	$F4,$46,$00,$18
_sprA04_2F_B:
		.BYTE	$F4,$46,$00,$10
_sprA04_2F_C:
		.BYTE	$F4,$46,$00,$08
		.BYTE	$F4,$52,$00,$00
		.BYTE	$F4,$42,$00,$F8
_sprA08_00:
		.BYTE	$23
		.BYTE	$F0,$C1,$00,$F8
		.BYTE	$F8,$C1,$00,$F0
_sprA08_00_A:
		.BYTE	$00,$D1,$00,$F8
_sprA08_01:
		.BYTE	$A1
		.WORD	_sprA08_00_A
_sprA08_02:
		.BYTE	$23
		.BYTE	$F0,$C1,$40,$00
		.BYTE	$F8,$C1,$40,$08
_sprA08_02_A:
		.BYTE	$00,$D1,$40,$00
_sprA08_03:
		.BYTE	$A1
		.WORD	_sprA08_02_A
