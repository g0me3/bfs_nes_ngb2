_sprA08_04:
		.BYTE	$02
		.BYTE	$F8,$CA,$02,$F8
		.BYTE	$F8,$DA,$02,$00
_sprA08_05:
		.BYTE	$02
		.BYTE	$F8,$CC,$02,$F8
		.BYTE	$F8,$DC,$02,$00
_sprA08_06:
		.BYTE	$02
		.BYTE	$F8,$CC,$42,$00
		.BYTE	$F8,$DC,$42,$F8
_sprA08_07:
		.BYTE	$03
		.BYTE	$00,$58,$00,$F8
		.BYTE	$F7,$58,$00,$FB
		.BYTE	$FD,$58,$00,$00
_sprA08_08:
		.BYTE	$03
		.BYTE	$02,$48,$00,$FB
		.BYTE	$FC,$48,$00,$FE
		.BYTE	$FD,$48,$00,$FA
_sprA08_09:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_09_B
_sprA08_09_A:
		.BYTE	$02
		.BYTE	$10,$3E,$00,$00
		.BYTE	$10,$3E,$40,$F8
_sprA08_09_B:
		.BYTE	$06
		.BYTE	$E8,$A4,$02,$FC
		.BYTE	$E8,$B4,$02,$04
		.BYTE	$E8,$B4,$42,$F4
		.BYTE	$F8,$A6,$02,$FC
		.BYTE	$F8,$B6,$02,$04
		.BYTE	$F8,$B6,$42,$F4
_sprA08_0A:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_0A_B
_sprA08_0A_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$42,$04
		.BYTE	$E8,$9C,$42,$FC
		.BYTE	$E8,$AC,$42,$F4
		.BYTE	$F8,$8E,$42,$04
		.BYTE	$F8,$9E,$42,$FC
		.BYTE	$F8,$AE,$42,$F4
_sprA08_0B:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_0B_B
_sprA08_0B_B:
		.BYTE	$06
		.BYTE	$E8,$80,$02,$F4
		.BYTE	$E8,$80,$42,$04
		.BYTE	$E8,$90,$02,$FC
		.BYTE	$F8,$82,$02,$F4
		.BYTE	$F8,$82,$42,$04
		.BYTE	$F8,$92,$02,$FC
_sprA08_0C:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_0C_B
_sprA08_0C_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$02,$F4
		.BYTE	$E8,$9C,$02,$FC
		.BYTE	$E8,$AC,$02,$04
		.BYTE	$F8,$8E,$02,$F4
		.BYTE	$F8,$9E,$02,$FC
		.BYTE	$F8,$AE,$02,$04
_sprA08_0D:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_0D_B
_sprA08_0D_B:
		.BYTE	$06
		.BYTE	$E8,$84,$02,$F4
		.BYTE	$E8,$84,$42,$04
		.BYTE	$E8,$94,$02,$FC
		.BYTE	$F8,$86,$02,$F4
		.BYTE	$F8,$86,$42,$04
		.BYTE	$F8,$96,$02,$FC
_sprA08_0E:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_0E_B
_sprA08_0E_B:
		.BYTE	$06
		.BYTE	$E8,$88,$42,$04
		.BYTE	$E8,$98,$42,$FC
		.BYTE	$E8,$A8,$42,$F4
		.BYTE	$F8,$8A,$42,$04
		.BYTE	$F8,$9A,$42,$FC
		.BYTE	$F8,$AA,$42,$F4
_sprA08_0F:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_0F_B
_sprA08_0F_B:
		.BYTE	$06
		.BYTE	$E8,$A0,$02,$FC
		.BYTE	$E8,$B0,$02,$04
		.BYTE	$E8,$B0,$42,$F4
		.BYTE	$F8,$A2,$02,$FC
		.BYTE	$F8,$B2,$02,$04
		.BYTE	$F8,$B2,$42,$F4
_sprA08_10:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_10_B
_sprA08_10_B:
		.BYTE	$06
		.BYTE	$E8,$88,$02,$F4
		.BYTE	$E8,$98,$02,$FC
		.BYTE	$E8,$A8,$02,$04
		.BYTE	$F8,$8A,$02,$F4
		.BYTE	$F8,$9A,$02,$FC
		.BYTE	$F8,$AA,$02,$04
_sprA08_11:
		.BYTE	$82
		.WORD	_sprA08_11_A
		.WORD	_sprA08_11_B
_sprA08_11_A:
		.BYTE	$02
		.BYTE	$10,$3E,$00,$02
		.BYTE	$10,$3E,$40,$FA
_sprA08_11_B:
		.BYTE	$06
		.BYTE	$E8,$A4,$02,$FE
		.BYTE	$E8,$B4,$02,$06
		.BYTE	$E8,$B4,$42,$F6
		.BYTE	$F8,$A6,$02,$FE
		.BYTE	$F8,$B6,$02,$06
		.BYTE	$F8,$B6,$42,$F6
_sprA08_12:
		.BYTE	$82
		.WORD	_sprA08_11_A
		.WORD	_sprA08_12_B
_sprA08_12_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$42,$06
		.BYTE	$E8,$9C,$42,$FE
		.BYTE	$E8,$AC,$42,$F6
		.BYTE	$F8,$8E,$42,$06
		.BYTE	$F8,$9E,$42,$FE
		.BYTE	$F8,$AE,$42,$F6
_sprA08_13:
		.BYTE	$82
		.WORD	_sprA08_11_A
		.WORD	_sprA08_13_B
_sprA08_13_B:
		.BYTE	$06
		.BYTE	$E8,$80,$02,$F6
		.BYTE	$E8,$80,$42,$06
		.BYTE	$E8,$90,$02,$FE
		.BYTE	$F8,$82,$02,$F6
		.BYTE	$F8,$82,$42,$06
		.BYTE	$F8,$92,$02,$FE
_sprA08_14:
		.BYTE	$82
		.WORD	_sprA08_11_A
		.WORD	_sprA08_14_B
_sprA08_14_B:
		.BYTE	$06
		.BYTE	$E8,$8C,$02,$F6
		.BYTE	$E8,$9C,$02,$FE
		.BYTE	$E8,$AC,$02,$06
		.BYTE	$F8,$8E,$02,$F6
		.BYTE	$F8,$9E,$02,$FE
		.BYTE	$F8,$AE,$02,$06
_sprA08_15:
		.BYTE	$82
		.WORD	_sprA08_15_A
		.WORD	_sprA08_15_B
_sprA08_15_A:
		.BYTE	$02
		.BYTE	$FF,$CE,$02,$F2
		.BYTE	$FF,$DE,$02,$FA
_sprA08_15_B:
		.BYTE	$03
		.BYTE	$EF,$88,$02,$EE
		.BYTE	$EF,$98,$02,$F6
		.BYTE	$F0,$A8,$02,$FE
_sprA08_16:
		.BYTE	$82
		.WORD	_sprA08_15_A
		.WORD	_sprA08_16_B
_sprA08_16_B
		.BYTE	$03
		.BYTE	$F6,$88,$02,$EE
		.BYTE	$F7,$98,$02,$F6
		.BYTE	$F8,$A8,$02,$FE
_sprA08_17:
		.BYTE	$82
		.WORD	_sprA08_17_A
		.WORD	_sprA08_17_B
_sprA08_17_A:
		.BYTE	$02
		.BYTE	$FF,$CE,$42,$07
		.BYTE	$FF,$DE,$42,$FF
_sprA08_17_B:
		.BYTE	$03
		.BYTE	$EF,$88,$42,$0B
		.BYTE	$EF,$98,$42,$03
		.BYTE	$F0,$A8,$42,$FB
_sprA08_18:
		.BYTE	$82
		.WORD	_sprA08_17_A
		.WORD	_sprA08_18_B
_sprA08_18_B:
		.BYTE	$03
		.BYTE	$F6,$88,$42,$0B
		.BYTE	$F7,$98,$42,$03
		.BYTE	$F8,$A8,$42,$FB
_sprA08_19:
		.BYTE	$83
		.WORD	_sprA08_09_A
		.WORD	_sprA08_19_B
		.WORD	_sprA08_19_C
_sprA08_19_B:
		.BYTE	$02
		.BYTE	$08,$D4,$03,$F8
		.BYTE	$08,$D4,$43,$00
_sprA08_19_C:
		.BYTE	$04
		.BYTE	$E8,$BE,$03,$00
		.BYTE	$E8,$D6,$03,$F8
		.BYTE	$F8,$D8,$03,$F8
		.BYTE	$F8,$D8,$43,$00
_sprA08_1A:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_1A_B
_sprA08_1A_B:
		.BYTE	$05
		.BYTE	$08,$F4,$43,$F8
		.BYTE	$E8,$E0,$43,$00
		.BYTE	$E8,$F0,$43,$F8
		.BYTE	$F8,$E2,$43,$00
		.BYTE	$F8,$F2,$43,$F8
_sprA08_1B:
		.BYTE	$83
		.WORD	_sprA08_09_A
		.WORD	_sprA08_19_B
		.WORD	_sprA08_1B_C
_sprA08_1B_C:
		.BYTE	$04
		.BYTE	$E8,$BA,$03,$00
		.BYTE	$E8,$D0,$03,$F8
		.BYTE	$F8,$D2,$03,$F8
		.BYTE	$F8,$D2,$43,$00
_sprA08_1C:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_1C_B
_sprA08_1C_B:
		.BYTE	$05
		.BYTE	$08,$F4,$03,$00
		.BYTE	$E8,$E0,$03,$F8
		.BYTE	$E8,$F0,$03,$00
		.BYTE	$F8,$E2,$03,$F8
		.BYTE	$F8,$F2,$03,$00
_sprA08_1D:
		.BYTE	$83
		.WORD	_sprA08_09_A
		.WORD	_sprA08_1D_B
		.WORD	_sprA08_1D_C
_sprA08_1D_B:
		.BYTE	$02
		.BYTE	$08,$C4,$03,$F8
		.BYTE	$08,$C4,$43,$00
_sprA08_1D_C:
		.BYTE	$04
		.BYTE	$E8,$BC,$03,$00
		.BYTE	$E8,$C6,$03,$F8
		.BYTE	$F8,$C8,$03,$F8
		.BYTE	$F8,$C8,$43,$00
_sprA08_1E:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_1E_B
_sprA08_1E_B:
		.BYTE	$05
		.BYTE	$08,$E4,$43,$F8
		.BYTE	$E8,$E6,$43,$00
		.BYTE	$E8,$F6,$43,$F8
		.BYTE	$F8,$E8,$43,$00
		.BYTE	$F8,$F8,$43,$F8
_sprA08_1F:
		.BYTE	$83
		.WORD	_sprA08_09_A
		.WORD	_sprA08_1D_B
		.WORD	_sprA08_1F_C
_sprA08_1F_C:
		.BYTE	$04
		.BYTE	$E8,$B8,$03,$00
		.BYTE	$E8,$C0,$03,$F8
		.BYTE	$F8,$C2,$03,$F8
		.BYTE	$F8,$C2,$43,$00
_sprA08_20:
		.BYTE	$82
		.WORD	_sprA08_09_A
		.WORD	_sprA08_20_B
_sprA08_20_B:
		.BYTE	$05
		.BYTE	$08,$E4,$03,$00
		.BYTE	$E8,$E6,$03,$F8
		.BYTE	$E8,$F6,$03,$00
		.BYTE	$F8,$E8,$03,$F8
		.BYTE	$F8,$F8,$03,$00
_sprA08_21:
		.BYTE	$83
		.WORD	_sprA08_11_A
		.WORD	_sprA08_21_B
		.WORD	_sprA08_21_C
_sprA08_21_B:
		.BYTE	$02
		.BYTE	$08,$D4,$03,$FA
		.BYTE	$08,$D4,$43,$02
_sprA08_21_C
		.BYTE	$04
		.BYTE	$E8,$BE,$03,$02
		.BYTE	$E8,$D6,$03,$FA
		.BYTE	$F8,$D8,$03,$FA
		.BYTE	$F8,$D8,$43,$02
_sprA08_22:
		.BYTE	$82
		.WORD	_sprA08_11_A
		.WORD	_sprA08_22_B
_sprA08_22_B:
		.BYTE	$05
		.BYTE	$08,$F4,$43,$FA
		.BYTE	$E8,$E0,$43,$02
		.BYTE	$E8,$F0,$43,$FA
		.BYTE	$F8,$E2,$43,$02
		.BYTE	$F8,$F2,$43,$FA
_sprA08_23:
		.BYTE	$83
		.WORD	_sprA08_11_A
		.WORD	_sprA08_21_B
		.WORD	_sprA08_23_C
_sprA08_23_C:
		.BYTE	$04
		.BYTE	$E8,$BA,$03,$02
		.BYTE	$E8,$D0,$03,$FA
		.BYTE	$F8,$D2,$03,$FA
		.BYTE	$F8,$D2,$43,$02
_sprA08_24:
		.BYTE	$82
		.WORD	_sprA08_11_A
		.WORD	_sprA08_24_B
_sprA08_24_B:
		.BYTE	$05
		.BYTE	$08,$F4,$03,$02
		.BYTE	$E8,$E0,$03,$FA
		.BYTE	$E8,$F0,$03,$02
		.BYTE	$F8,$E2,$03,$FA
		.BYTE	$F8,$F2,$03,$02
_sprA08_25:
		.BYTE	$05
		.BYTE	$E6,$E6,$03,$F6
		.BYTE	$E6,$F6,$03,$FE
		.BYTE	$F6,$E8,$03,$F5
		.BYTE	$F6,$F8,$03,$FD
		.BYTE	$FF,$FA,$03,$FA
_sprA08_26:
		.BYTE	$03
		.BYTE	$F4,$F6,$03,$FF
		.BYTE	$F6,$E6,$03,$F7
		.BYTE	$FF,$FA,$03,$FA
_sprA08_27:
		.BYTE	$05
		.BYTE	$E6,$E6,$43,$03
		.BYTE	$E6,$F6,$43,$FB
		.BYTE	$F6,$E8,$43,$04
		.BYTE	$F6,$F8,$43,$FC
		.BYTE	$FF,$FA,$43,$FF
_sprA08_28:
		.BYTE	$03
		.BYTE	$F4,$F6,$43,$FA
		.BYTE	$F6,$E6,$43,$02
		.BYTE	$FF,$FA,$43,$FF
_sprA08_29:
		.BYTE	$82
		.WORD	_sprA08_29_A
		.WORD	_sprA08_29_B
_sprA08_29_A:
		.BYTE	$04
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$E7,$E3,$00,$F8
		.BYTE	$E7,$E3,$40,$00
_sprA08_29_B:
		.BYTE	$07
		.BYTE	$00,$E2,$02,$F8
		.BYTE	$00,$E2,$42,$00
		.BYTE	$F0,$E0,$02,$F8
		.BYTE	$F0,$E0,$42,$00
		.BYTE	$FD,$C7,$00,$FA
		.BYTE	$FD,$D7,$00,$02
		.BYTE	$FD,$E7,$00,$0A
_sprA08_2A:
		.BYTE	$83
		.WORD	_sprA08_29_A
		.WORD	_sprA08_2B_A
		.WORD	_sprA08_2A_C
_sprA08_2A_C:
		.BYTE	$03
		.BYTE	$FF,$C7,$00,$FA
		.BYTE	$FF,$D7,$00,$02
		.BYTE	$FF,$E7,$00,$0A
_sprA08_2B:
		.BYTE	$82
		.WORD	_sprA08_2B_A
		.WORD	_sprA08_2B_B
_sprA08_2B_A:
		.BYTE	$04
		.BYTE	$01,$E2,$02,$F8
		.BYTE	$01,$E2,$42,$00
		.BYTE	$F1,$F0,$02,$F8
		.BYTE	$F1,$F0,$42,$00
_sprA08_2B_B:
		.BYTE	$07
		.BYTE	$08,$3E,$03,$00
		.BYTE	$08,$3E,$43,$F8
		.BYTE	$E8,$E3,$00,$F8
		.BYTE	$E8,$E3,$40,$00
		.BYTE	$FE,$C7,$00,$FA
		.BYTE	$FE,$D7,$00,$02
		.BYTE	$FE,$E7,$00,$0A
_sprA08_2C:
		.BYTE	$82
		.WORD	_sprA08_2C_A
		.WORD	_sprA08_2C_B
_sprA08_2C_A:
		.BYTE	$07
		.BYTE	$00,$C4,$42,$00
		.BYTE	$00,$D4,$42,$F8
		.BYTE	$06,$3E,$03,$00
		.BYTE	$06,$3E,$43,$F8
		.BYTE	$E8,$C5,$00,$F9
		.BYTE	$E8,$D5,$00,$01
		.BYTE	$F0,$C2,$42,$00
_sprA08_2C_B:
		.BYTE	$03
		.BYTE	$F0,$D2,$42,$F8
		.BYTE	$FD,$E5,$00,$FA
		.BYTE	$FD,$F5,$00,$02
_sprA08_2D:
		.BYTE	$82
		.WORD	_sprA08_2C_A
		.WORD	_sprA08_2D_B
_sprA08_2D_B:
		.BYTE	$04
		.BYTE	$F0,$D2,$42,$F8
		.BYTE	$F8,$C7,$00,$FA
		.BYTE	$F8,$D7,$00,$02
		.BYTE	$F8,$E7,$00,$0A
_sprA08_2E:
		.BYTE	$83
		.WORD	_sprA08_2E_A
		.WORD	_sprA08_2E_B
		.WORD	_sprA08_2E_C
_sprA08_2E_A:
		.BYTE	$02
		.BYTE	$06,$3E,$03,$00
		.BYTE	$06,$3E,$43,$F8
_sprA08_2E_B:
		.BYTE	$02
		.BYTE	$EA,$F3,$00,$F8
		.BYTE	$EA,$F3,$40,$00
_sprA08_2E_C:
		.BYTE	$05
		.BYTE	$EF,$F2,$02,$F8
		.BYTE	$EF,$F2,$42,$00
		.BYTE	$F1,$F5,$80,$05
		.BYTE	$FF,$F4,$02,$F8
		.BYTE	$FF,$F4,$42,$00
_sprA08_2F:
		.BYTE	$83
		.WORD	_sprA08_2E_A
		.WORD	_sprA08_2E_B
		.WORD	_sprA08_2F_C
_sprA08_2F_C:
		.BYTE	$05
		.BYTE	$E6,$F7,$00,$FA
		.BYTE	$EE,$F2,$02,$F8
		.BYTE	$EE,$F2,$42,$00
		.BYTE	$FE,$F4,$02,$F8
		.BYTE	$FE,$F4,$42,$00
_sprA08_30:
		.BYTE	$82
		.WORD	_sprA08_2E_A
		.WORD	_sprA08_30_B
_sprA08_30_B:
		.BYTE	$07
		.BYTE	$E9,$F3,$00,$F8
		.BYTE	$E9,$F3,$40,$00
		.BYTE	$ED,$F2,$02,$F8
		.BYTE	$ED,$F2,$42,$00
		.BYTE	$ED,$F5,$C0,$F0
		.BYTE	$FD,$F4,$02,$F8
		.BYTE	$FD,$F4,$42,$00
_sprA08_31:
		.BYTE	$0B
		.BYTE	$00,$E2,$02,$FA
		.BYTE	$00,$E2,$42,$02
		.BYTE	$08,$3E,$03,$02
		.BYTE	$08,$3E,$43,$FA
		.BYTE	$E7,$E3,$00,$FA
		.BYTE	$E7,$E3,$40,$02
		.BYTE	$F0,$E0,$02,$FA
		.BYTE	$F0,$E0,$42,$02
		.BYTE	$FD,$C7,$00,$FC
		.BYTE	$FD,$D7,$00,$04
		.BYTE	$FD,$E7,$00,$0C
_sprA08_32:
		.BYTE	$03
		.BYTE	$00,$C6,$02,$F8
		.BYTE	$F0,$D6,$02,$F2
		.BYTE	$F0,$E6,$02,$FA
_sprA08_33:
		.BYTE	$02
		.BYTE	$F8,$E4,$02,$F0
		.BYTE	$F8,$F6,$02,$F8
_sprA08_34:
		.BYTE	$03
		.BYTE	$00,$C6,$42,$00
		.BYTE	$F0,$D6,$42,$08
		.BYTE	$F0,$E6,$42,$00
_sprA08_35:
		.BYTE	$02
		.BYTE	$F8,$E4,$42,$08
		.BYTE	$F8,$F6,$42,$00
_sprA08_36:
		.BYTE	$01
		.BYTE	$F8,$C0,$01,$FC
_sprA08_37:
		.BYTE	$01
		.BYTE	$F8,$D0,$01,$FC
_sprA08_38:
		.BYTE	$01
		.BYTE	$F8,$C0,$41,$FC
_sprA08_39:
		.BYTE	$01
		.BYTE	$F8,$C8,$01,$FC
_sprA08_3A:
		.BYTE	$01
		.BYTE	$F8,$C8,$41,$FC
_sprA08_3B:
		.BYTE	$82
		.WORD	_sprA08_3B_A
		.WORD	_sprA08_3B_B
_sprA08_3B_A:
		.BYTE	$02
		.BYTE	$08,$82,$00,$F4
		.BYTE	$08,$90,$00,$04
_sprA08_3B_B:
		.BYTE	$01
		.BYTE	$08,$80,$00,$FC
_sprA08_3C:
		.BYTE	$82
		.WORD	_sprA08_3B_A
		.WORD	_sprA08_3C_B
_sprA08_3C_B:
		.BYTE	$01
		.BYTE	$08,$98,$03,$FC
_sprA08_3D:
		.BYTE	$03
		.BYTE	$08,$8A,$43,$04
		.BYTE	$08,$90,$43,$F4
		.BYTE	$08,$9A,$43,$FC
_sprA08_3E:
		.BYTE	$82
		.WORD	_sprA08_3B_A
		.WORD	_sprA08_3E_B
_sprA08_3E_B:
		.BYTE	$01
		.BYTE	$08,$88,$03,$FC
_sprA08_3F:
		.BYTE	$03
		.BYTE	$08,$8A,$03,$F4
		.BYTE	$08,$90,$00,$04
		.BYTE	$08,$9A,$03,$FC
_sprA08_40:
		.BYTE	$82
		.WORD	_sprA08_3B_A
		.WORD	_sprA08_40_B
_sprA08_40_B:
		.BYTE	$07
		.BYTE	$08,$80,$00,$FC
		.BYTE	$EE,$A6,$03,$FC
		.BYTE	$FE,$A4,$03,$EC
		.BYTE	$FE,$A4,$43,$0C
		.BYTE	$FE,$B4,$03,$F4
		.BYTE	$FE,$B4,$43,$04
		.BYTE	$FE,$C4,$03,$FC
_sprA08_41:
		.BYTE	$08
		.BYTE	$08,$80,$43,$00
		.BYTE	$08,$80,$43,$F8
		.BYTE	$EE,$A8,$43,$04
		.BYTE	$EE,$B8,$43,$FC
		.BYTE	$FE,$C8,$43,$0C
		.BYTE	$FE,$D8,$43,$04
		.BYTE	$FE,$E8,$43,$FC
		.BYTE	$FE,$F8,$43,$F4
_sprA08_42:
		.BYTE	$09
		.BYTE	$08,$80,$03,$FC
		.BYTE	$08,$82,$03,$F4
		.BYTE	$08,$90,$03,$04
		.BYTE	$EE,$A2,$03,$FC
		.BYTE	$FE,$A0,$03,$EC
		.BYTE	$FE,$A0,$43,$0C
		.BYTE	$FE,$B0,$03,$F4
		.BYTE	$FE,$B0,$43,$04
		.BYTE	$FE,$C0,$03,$FC
_sprA08_43:
		.BYTE	$08
		.BYTE	$08,$80,$03,$00
		.BYTE	$08,$80,$03,$F8
		.BYTE	$EE,$A8,$03,$F4
		.BYTE	$EE,$B8,$03,$FC
		.BYTE	$FE,$C8,$03,$EC
		.BYTE	$FE,$D8,$03,$F4
		.BYTE	$FE,$E8,$03,$FC
		.BYTE	$FE,$F8,$03,$04
_sprA08_44:
		.BYTE	$09
		.BYTE	$00,$86,$03,$04
		.BYTE	$00,$B6,$03,$F4
		.BYTE	$00,$C6,$03,$FC
		.BYTE	$E0,$A6,$03,$FC
		.BYTE	$F0,$A4,$03,$EC
		.BYTE	$F0,$A4,$43,$0C
		.BYTE	$F0,$B4,$03,$F4
		.BYTE	$F0,$B4,$43,$04
		.BYTE	$F0,$C4,$03,$FC
_sprA08_45:
		.BYTE	$0A
		.BYTE	$00,$CA,$43,$0C
		.BYTE	$00,$DA,$43,$04
		.BYTE	$00,$EA,$43,$FC
		.BYTE	$00,$FA,$43,$F4
		.BYTE	$E0,$A8,$43,$04
		.BYTE	$E0,$B8,$43,$FC
		.BYTE	$F0,$C8,$43,$0C
		.BYTE	$F0,$D8,$43,$04
		.BYTE	$F0,$E8,$43,$FC
		.BYTE	$F0,$F8,$43,$F4
_sprA08_46:
		.BYTE	$09
		.BYTE	$00,$84,$03,$04
		.BYTE	$00,$B2,$03,$F4
		.BYTE	$00,$C2,$03,$FC
		.BYTE	$E0,$A2,$03,$FC
		.BYTE	$F0,$A0,$03,$EC
		.BYTE	$F0,$A0,$43,$0C
		.BYTE	$F0,$B0,$03,$F4
		.BYTE	$F0,$B0,$43,$04
		.BYTE	$F0,$C0,$03,$FC
_sprA08_47:
		.BYTE	$0A
		.BYTE	$00,$CA,$03,$F0
		.BYTE	$00,$DA,$03,$F8
		.BYTE	$00,$EA,$03,$00
		.BYTE	$00,$FA,$03,$08
		.BYTE	$E0,$A8,$03,$F8
		.BYTE	$E0,$B8,$03,$00
		.BYTE	$F0,$C8,$03,$F0
		.BYTE	$F0,$D8,$03,$F8
		.BYTE	$F0,$E8,$03,$00
		.BYTE	$F0,$F8,$03,$08
_sprA08_48:
		.BYTE	$09
		.BYTE	$00,$96,$03,$F4
		.BYTE	$00,$D6,$03,$FC
		.BYTE	$00,$E6,$03,$04
		.BYTE	$E0,$F6,$03,$FC
		.BYTE	$F0,$D4,$03,$FC
		.BYTE	$F0,$E4,$03,$04
		.BYTE	$F0,$E4,$43,$F4
		.BYTE	$F0,$F4,$03,$0C
		.BYTE	$F0,$F4,$43,$EC
_sprA08_49:
		.BYTE	$09
		.BYTE	$00,$CE,$43,$04
		.BYTE	$00,$DE,$43,$FC
		.BYTE	$00,$EE,$43,$F4
		.BYTE	$E0,$AA,$43,$04
		.BYTE	$E0,$BA,$43,$FC
		.BYTE	$F0,$BC,$43,$0C
		.BYTE	$F0,$CC,$43,$04
		.BYTE	$F0,$DC,$43,$FC
		.BYTE	$F0,$EC,$43,$F4
_sprA08_4A:
		.BYTE	$09
		.BYTE	$00,$94,$03,$F4
		.BYTE	$00,$D2,$03,$FC
		.BYTE	$00,$E2,$03,$04
		.BYTE	$E0,$F2,$03,$FC
		.BYTE	$F0,$D0,$03,$FC
		.BYTE	$F0,$E0,$03,$04
		.BYTE	$F0,$E0,$43,$F4
		.BYTE	$F0,$F0,$03,$0C
		.BYTE	$F0,$F0,$43,$EC
_sprA08_4B:
		.BYTE	$09
		.BYTE	$00,$CE,$03,$F8
		.BYTE	$00,$DE,$03,$00
		.BYTE	$00,$EE,$03,$08
		.BYTE	$E0,$AA,$03,$F8
		.BYTE	$E0,$BA,$03,$00
		.BYTE	$F0,$BC,$03,$F0
		.BYTE	$F0,$CC,$03,$F8
		.BYTE	$F0,$DC,$03,$00
		.BYTE	$F0,$EC,$03,$08
_sprA08_4C:
		.BYTE	$09
		.BYTE	$00,$86,$03,$06
		.BYTE	$00,$B6,$03,$F6
		.BYTE	$00,$C6,$03,$FE
		.BYTE	$E0,$A6,$03,$FE
		.BYTE	$F0,$A4,$03,$EE
		.BYTE	$F0,$A4,$43,$0E
		.BYTE	$F0,$B4,$03,$F6
		.BYTE	$F0,$B4,$43,$06
		.BYTE	$F0,$C4,$03,$FE
_sprA08_4D:
		.BYTE	$0A
		.BYTE	$00,$CA,$43,$0E
		.BYTE	$00,$DA,$43,$06
		.BYTE	$00,$EA,$43,$FE
		.BYTE	$00,$FA,$43,$F6
		.BYTE	$E0,$A8,$43,$06
		.BYTE	$E0,$B8,$43,$FE
		.BYTE	$F0,$C8,$43,$0E
		.BYTE	$F0,$D8,$43,$06
		.BYTE	$F0,$E8,$43,$FE
		.BYTE	$F0,$F8,$43,$F6
_sprA08_4E:
		.BYTE	$09
		.BYTE	$00,$84,$03,$07
		.BYTE	$00,$B2,$03,$F7
		.BYTE	$00,$C2,$03,$FF
		.BYTE	$E0,$A2,$03,$FF
		.BYTE	$F0,$A0,$03,$EF
		.BYTE	$F0,$A0,$43,$0F
		.BYTE	$F0,$B0,$03,$F7
		.BYTE	$F0,$B0,$43,$07
		.BYTE	$F0,$C0,$03,$FF
_sprA08_4F:
		.BYTE	$0A
		.BYTE	$00,$CA,$03,$F2
		.BYTE	$00,$DA,$03,$FA
		.BYTE	$00,$EA,$03,$02
		.BYTE	$00,$FA,$03,$0A
		.BYTE	$E0,$A8,$03,$FA
		.BYTE	$E0,$B8,$03,$02
		.BYTE	$F0,$C8,$03,$F2
		.BYTE	$F0,$D8,$03,$FA
		.BYTE	$F0,$E8,$03,$02
		.BYTE	$F0,$F8,$03,$0A
_sprA08_50:
		.BYTE	$0A
		.BYTE	$DF,$AA,$03,$F2
		.BYTE	$DF,$BA,$03,$FA
		.BYTE	$EF,$C8,$03,$EA
		.BYTE	$EF,$D8,$03,$F2
		.BYTE	$EF,$E8,$03,$FA
		.BYTE	$EF,$F8,$03,$02
		.BYTE	$FF,$9E,$03,$F2
		.BYTE	$FF,$AE,$03,$FA
		.BYTE	$FF,$BE,$03,$02
		.BYTE	$FF,$CA,$03,$EA
_sprA08_51:
		.BYTE	$04
		.BYTE	$07,$8E,$03,$F9
		.BYTE	$07,$BE,$03,$01
		.BYTE	$F7,$C8,$03,$F9
		.BYTE	$F7,$F8,$03,$01
_sprA08_52:
		.BYTE	$0A
		.BYTE	$DF,$AA,$43,$07
		.BYTE	$DF,$BA,$43,$FF
		.BYTE	$EF,$C8,$43,$0F
		.BYTE	$EF,$D8,$43,$07
		.BYTE	$EF,$E8,$43,$FF
		.BYTE	$EF,$F8,$43,$F7
		.BYTE	$FF,$9E,$43,$07
		.BYTE	$FF,$AE,$43,$FF
		.BYTE	$FF,$BE,$43,$F7
		.BYTE	$FF,$CA,$43,$0F
_sprA08_53:
		.BYTE	$04
		.BYTE	$06,$8E,$43,$02
		.BYTE	$06,$BE,$43,$FA
		.BYTE	$F6,$C8,$43,$02
		.BYTE	$F6,$F8,$43,$FA
_sprA08_54:
		.BYTE	$03
		.BYTE	$0E,$92,$01,$FC
		.BYTE	$E3,$92,$01,$FC
		.BYTE	$F9,$92,$41,$FC
_sprA08_55:
		.BYTE	$03
		.BYTE	$04,$92,$01,$FC
		.BYTE	$D8,$92,$41,$FC
		.BYTE	$EE,$92,$41,$FC
_sprA08_56:
		.BYTE	$03
		.BYTE	$F2,$92,$01,$0D
		.BYTE	$F5,$92,$41,$F7
		.BYTE	$F8,$92,$41,$E1
_sprA08_57:
		.BYTE	$03
		.BYTE	$F0,$92,$41,$18
		.BYTE	$F3,$92,$01,$02
		.BYTE	$F7,$92,$41,$EC
_sprA08_58:
		.BYTE	$03
		.BYTE	$F0,$92,$01,$E0
		.BYTE	$F3,$92,$41,$F6
		.BYTE	$F7,$92,$01,$0C
_sprA08_59:
		.BYTE	$03
		.BYTE	$F2,$92,$41,$EB
		.BYTE	$F5,$92,$01,$01
		.BYTE	$F8,$92,$01,$18
_sprA08_5A:
		.BYTE	$82
		.WORD	_sprA08_5A_A
		.WORD	_sprA08_5A_B
_sprA08_5A_A:
		.BYTE	$02
		.BYTE	$08,$9E,$03,$08
		.BYTE	$08,$9E,$43,$F0
_sprA08_5A_B:
		.BYTE	$08
		.BYTE	$08,$8C,$43,$00
		.BYTE	$08,$9C,$43,$F8
		.BYTE	$E8,$88,$43,$04
		.BYTE	$E8,$98,$43,$FC
		.BYTE	$E8,$A8,$43,$F4
		.BYTE	$F8,$8A,$43,$04
		.BYTE	$F8,$9A,$43,$FC
		.BYTE	$F8,$AA,$43,$F4
_sprA08_5B:
		.BYTE	$82
		.WORD	_sprA08_5B_A
		.WORD	_sprA08_5B_B
_sprA08_5B_A:
		.BYTE	$04
		.BYTE	$08,$84,$03,$F0
		.BYTE	$08,$84,$43,$08
		.BYTE	$08,$94,$03,$F8
		.BYTE	$08,$94,$43,$00
_sprA08_5B_B:
		.BYTE	$08
		.BYTE	$E8,$80,$03,$F0
		.BYTE	$E8,$80,$43,$08
		.BYTE	$E8,$90,$03,$F8
		.BYTE	$E8,$90,$43,$00
		.BYTE	$F8,$82,$03,$F0
		.BYTE	$F8,$82,$43,$08
		.BYTE	$F8,$92,$03,$F8
		.BYTE	$F8,$92,$43,$00
_sprA08_5C:
		.BYTE	$82
		.WORD	_sprA08_5A_A
		.WORD	_sprA08_5C_B
_sprA08_5C_B:
		.BYTE	$08
		.BYTE	$08,$8C,$03,$F8
		.BYTE	$08,$9C,$03,$00
		.BYTE	$E8,$88,$03,$F4
		.BYTE	$E8,$98,$03,$FC
		.BYTE	$E8,$A8,$03,$04
		.BYTE	$F8,$8A,$03,$F4
		.BYTE	$F8,$9A,$03,$FC
		.BYTE	$F8,$AA,$03,$04
_sprA08_5D:
		.BYTE	$82
		.WORD	_sprA08_5D_A
		.WORD	_sprA08_5D_B
_sprA08_5D_A:
		.BYTE	$08
		.BYTE	$E8,$A0,$03,$00
		.BYTE	$E8,$A0,$43,$F8
		.BYTE	$E8,$B0,$03,$08
		.BYTE	$E8,$B0,$43,$F0
		.BYTE	$F8,$A2,$03,$00
		.BYTE	$F8,$A2,$43,$F8
		.BYTE	$F8,$B2,$03,$08
		.BYTE	$F8,$B2,$43,$F0
_sprA08_5D_B:
		.BYTE	$04
		.BYTE	$08,$A4,$03,$00
		.BYTE	$08,$A4,$43,$F8
		.BYTE	$08,$B4,$03,$08
		.BYTE	$08,$B4,$43,$F0
_sprA08_5E:
		.BYTE	$0A
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8C,$43,$00
		.BYTE	$07,$BC,$43,$F8
		.BYTE	$E7,$88,$43,$04
		.BYTE	$E7,$98,$43,$FC
		.BYTE	$E7,$A8,$43,$F4
		.BYTE	$F7,$8A,$43,$04
		.BYTE	$F7,$9A,$43,$FC
		.BYTE	$F7,$AA,$43,$F4
_sprA08_5F:
		.BYTE	$82
		.WORD	_sprA08_5F_A
		.WORD	_sprA08_5F_B
_sprA08_5F_A:
		.BYTE	$04
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8E,$03,$00
		.BYTE	$07,$8E,$43,$F8
_sprA08_5F_B
		.BYTE	$08
		.BYTE	$E7,$80,$03,$F0
		.BYTE	$E7,$80,$43,$08
		.BYTE	$E7,$90,$03,$F8
		.BYTE	$E7,$90,$43,$00
		.BYTE	$F7,$82,$03,$F0
		.BYTE	$F7,$82,$43,$08
		.BYTE	$F7,$92,$03,$F8
		.BYTE	$F7,$92,$43,$00
_sprA08_60:
		.BYTE	$0A
		.BYTE	$07,$9E,$03,$08
		.BYTE	$07,$9E,$43,$F0
		.BYTE	$07,$8C,$03,$F8
		.BYTE	$07,$BC,$03,$00
		.BYTE	$E7,$88,$03,$F4
		.BYTE	$E7,$98,$03,$FC
		.BYTE	$E7,$A8,$03,$04
		.BYTE	$F7,$8A,$03,$F4
		.BYTE	$F7,$9A,$03,$FC
		.BYTE	$F7,$AA,$03,$04
_sprA08_61:
		.BYTE	$82
		.WORD	_sprA08_5F_A
		.WORD	_sprA08_61_B
_sprA08_61_B
		.BYTE	$08
		.BYTE	$E7,$A0,$03,$00
		.BYTE	$E7,$A0,$43,$F8
		.BYTE	$E7,$B0,$03,$08
		.BYTE	$E7,$B0,$43,$F0
		.BYTE	$F7,$A2,$03,$00
		.BYTE	$F7,$A2,$43,$F8
		.BYTE	$F7,$B2,$03,$08
		.BYTE	$F7,$B2,$43,$F0
_sprA08_62:
		.BYTE	$82
		.WORD	_sprA08_5A_A
		.WORD	_sprA08_62_B
_sprA08_62_B:
		.BYTE	$08
		.BYTE	$08,$AC,$43,$00
		.BYTE	$08,$BC,$43,$F8
		.BYTE	$E8,$88,$43,$03
		.BYTE	$E8,$98,$43,$FB
		.BYTE	$E8,$A8,$43,$F3
		.BYTE	$F8,$8A,$43,$03
		.BYTE	$F8,$9A,$43,$FB
		.BYTE	$F8,$AA,$43,$F3
_sprA08_63:
		.BYTE	$83
		.WORD	_sprA08_5A_A
		.WORD	_sprA08_63_B
		.WORD	_sprA08_5B_B
_sprA08_63_B:
		.BYTE	$02
		.BYTE	$08,$AE,$03,$F8
		.BYTE	$08,$BE,$03,$00
_sprA08_64:
		.BYTE	$82
		.WORD	_sprA08_5A_A
		.WORD	_sprA08_64_B
_sprA08_64_B:
		.BYTE	$08
		.BYTE	$08,$AC,$03,$F8
		.BYTE	$08,$BC,$03,$00
		.BYTE	$E8,$88,$03,$F5
		.BYTE	$E8,$98,$03,$FD
		.BYTE	$E8,$A8,$03,$05
		.BYTE	$F8,$8A,$03,$F5
		.BYTE	$F8,$9A,$03,$FD
		.BYTE	$F8,$AA,$03,$05
_sprA08_65:
		.BYTE	$83
		.WORD	_sprA08_5A_A
		.WORD	_sprA08_5D_A
		.WORD	_sprA08_65_C
_sprA08_65_C:
		.BYTE	$02
		.BYTE	$08,$B8,$03,$F8
		.BYTE	$08,$BA,$03,$00
_sprA08_66:
		.BYTE	$0A
		.BYTE	$08,$8C,$43,$02
		.BYTE	$08,$9C,$43,$FA
		.BYTE	$08,$9E,$03,$0A
		.BYTE	$08,$9E,$43,$F2
		.BYTE	$E8,$88,$43,$06
		.BYTE	$E8,$98,$43,$FE
		.BYTE	$E8,$A8,$43,$F6
		.BYTE	$F8,$8A,$43,$06
		.BYTE	$F8,$9A,$43,$FE
		.BYTE	$F8,$AA,$43,$F6
_sprA08_67:
		.BYTE	$0C
		.BYTE	$08,$84,$03,$F2
		.BYTE	$08,$84,$43,$0A
		.BYTE	$08,$94,$03,$FA
		.BYTE	$08,$94,$43,$02
		.BYTE	$E8,$80,$03,$F2
		.BYTE	$E8,$80,$43,$0A
		.BYTE	$E8,$90,$03,$FA
		.BYTE	$E8,$90,$43,$02
		.BYTE	$F8,$82,$03,$F2
		.BYTE	$F8,$82,$43,$0A
		.BYTE	$F8,$92,$03,$FA
		.BYTE	$F8,$92,$43,$02
_sprA08_68:
		.BYTE	$0A
		.BYTE	$08,$8C,$03,$FA
		.BYTE	$08,$9C,$03,$02
		.BYTE	$08,$9E,$03,$0A
		.BYTE	$08,$9E,$43,$F2
		.BYTE	$E8,$88,$03,$F6
		.BYTE	$E8,$98,$03,$FE
		.BYTE	$E8,$A8,$03,$06
		.BYTE	$F8,$8A,$03,$F6
		.BYTE	$F8,$9A,$03,$FE
		.BYTE	$F8,$AA,$03,$06
_sprA08_69:
		.BYTE	$0C
		.BYTE	$08,$A4,$03,$02
		.BYTE	$08,$A4,$43,$FA
		.BYTE	$08,$B4,$03,$0A
		.BYTE	$08,$B4,$43,$F2
		.BYTE	$E8,$A0,$03,$02
		.BYTE	$E8,$A0,$43,$FA
		.BYTE	$E8,$B0,$03,$0A
		.BYTE	$E8,$B0,$43,$F2
		.BYTE	$F8,$A2,$03,$02
		.BYTE	$F8,$A2,$43,$FA
		.BYTE	$F8,$B2,$03,$0A
		.BYTE	$F8,$B2,$43,$F2
_sprA08_6A:
		.BYTE	$82
		.WORD	_sprA08_6A_A
		.WORD	_sprA08_0E_B
_sprA08_6A_A:
		.BYTE	$04
		.BYTE	$08,$8C,$42,$00
		.BYTE	$08,$9C,$42,$F8
		.BYTE	$08,$9E,$02,$08
		.BYTE	$08,$9E,$42,$F0
_sprA08_6B:
		.BYTE	$0C
		.BYTE	$08,$84,$02,$F0
		.BYTE	$08,$84,$42,$08
		.BYTE	$08,$94,$02,$F8
		.BYTE	$08,$94,$42,$00
		.BYTE	$E8,$80,$02,$F0
		.BYTE	$E8,$80,$42,$08
		.BYTE	$E8,$90,$02,$F8
		.BYTE	$E8,$90,$42,$00
		.BYTE	$F8,$82,$02,$F0
		.BYTE	$F8,$82,$42,$08
		.BYTE	$F8,$92,$02,$F8
		.BYTE	$F8,$92,$42,$00
_sprA08_6C:
		.BYTE	$82
		.WORD	_sprA08_6C_A
		.WORD	_sprA08_10_B
_sprA08_6C_A:
		.BYTE	$04
		.BYTE	$08,$8C,$02,$F8
		.BYTE	$08,$9C,$02,$00
		.BYTE	$08,$9E,$02,$08
		.BYTE	$08,$9E,$42,$F0
_sprA08_6D:
		.BYTE	$0C
		.BYTE	$08,$A4,$02,$00
		.BYTE	$08,$A4,$42,$F8
		.BYTE	$08,$B4,$02,$08
		.BYTE	$08,$B4,$42,$F0
		.BYTE	$E8,$A0,$02,$00
		.BYTE	$E8,$A0,$42,$F8
		.BYTE	$E8,$B0,$02,$08
		.BYTE	$E8,$B0,$42,$F0
		.BYTE	$F8,$A2,$02,$00
		.BYTE	$F8,$A2,$42,$F8
		.BYTE	$F8,$B2,$02,$08
		.BYTE	$F8,$B2,$42,$F0
_sprA08_6E:
		.BYTE	$0A
		.BYTE	$08,$8C,$42,$02
		.BYTE	$08,$9C,$42,$FA
		.BYTE	$08,$9E,$02,$0A
		.BYTE	$08,$9E,$42,$F2
		.BYTE	$E8,$88,$42,$06
		.BYTE	$E8,$98,$42,$FE
		.BYTE	$E8,$A8,$42,$F6
		.BYTE	$F8,$8A,$42,$06
		.BYTE	$F8,$9A,$42,$FE
		.BYTE	$F8,$AA,$42,$F6
_sprA08_6F:
		.BYTE	$0C
		.BYTE	$08,$84,$02,$F2
		.BYTE	$08,$84,$42,$0A
		.BYTE	$08,$94,$02,$FA
		.BYTE	$08,$94,$42,$02
		.BYTE	$E8,$80,$02,$F2
		.BYTE	$E8,$80,$42,$0A
		.BYTE	$E8,$90,$02,$FA
		.BYTE	$E8,$90,$42,$02
		.BYTE	$F8,$82,$02,$F2
		.BYTE	$F8,$82,$42,$0A
		.BYTE	$F8,$92,$02,$FA
		.BYTE	$F8,$92,$42,$02
_sprA08_70:
		.BYTE	$0A
		.BYTE	$08,$8C,$02,$FA
		.BYTE	$08,$9C,$02,$02
		.BYTE	$08,$9E,$02,$0A
		.BYTE	$08,$9E,$42,$F2
		.BYTE	$E8,$88,$02,$F6
		.BYTE	$E8,$98,$02,$FE
		.BYTE	$E8,$A8,$02,$06
		.BYTE	$F8,$8A,$02,$F6
		.BYTE	$F8,$9A,$02,$FE
		.BYTE	$F8,$AA,$02,$06
_sprA08_71:
		.BYTE	$0C
		.BYTE	$08,$A4,$02,$02
		.BYTE	$08,$A4,$42,$FA
		.BYTE	$08,$B4,$02,$0A
		.BYTE	$08,$B4,$42,$F2
		.BYTE	$E8,$A0,$02,$02
		.BYTE	$E8,$A0,$42,$FA
		.BYTE	$E8,$B0,$02,$0A
		.BYTE	$E8,$B0,$42,$F2
		.BYTE	$F8,$A2,$02,$02
		.BYTE	$F8,$A2,$42,$FA
		.BYTE	$F8,$B2,$02,$0A
		.BYTE	$F8,$B2,$42,$F2
_sprA08_72:
		.BYTE	$0A
		.BYTE	$08,$D0,$03,$F0
		.BYTE	$08,$E0,$03,$F8
		.BYTE	$E8,$80,$03,$E8
		.BYTE	$E8,$80,$43,$00
		.BYTE	$E8,$90,$03,$F0
		.BYTE	$E8,$90,$43,$F8
		.BYTE	$F8,$92,$03,$F0
		.BYTE	$F8,$92,$43,$F8
		.BYTE	$F8,$C0,$03,$00
		.BYTE	$F8,$C0,$43,$E8
_sprA08_73:
		.BYTE	$06
		.BYTE	$00,$C2,$03,$F0
		.BYTE	$00,$D2,$03,$F8
		.BYTE	$F0,$80,$03,$E8
		.BYTE	$F0,$80,$43,$00
		.BYTE	$F0,$90,$03,$F0
		.BYTE	$F0,$90,$43,$F8
_sprA08_74:
		.BYTE	$0A
		.BYTE	$08,$D0,$43,$08
		.BYTE	$08,$E0,$43,$00
		.BYTE	$E8,$80,$03,$F8
		.BYTE	$E8,$80,$43,$10
		.BYTE	$E8,$90,$03,$00
		.BYTE	$E8,$90,$43,$08
		.BYTE	$F8,$92,$03,$00
		.BYTE	$F8,$92,$43,$08
		.BYTE	$F8,$C0,$03,$10
		.BYTE	$F8,$C0,$43,$F8
_sprA08_75:
		.BYTE	$06
		.BYTE	$00,$C2,$43,$08
		.BYTE	$00,$D2,$43,$00
		.BYTE	$F0,$80,$03,$F8
		.BYTE	$F0,$80,$43,$10
		.BYTE	$F0,$90,$03,$00
		.BYTE	$F0,$90,$43,$08
_sprA08_76:
		.BYTE	$04
		.BYTE	$00,$36,$03,$00
		.BYTE	$00,$36,$43,$F8
		.BYTE	$F0,$A6,$03,$F8
		.BYTE	$F0,$A6,$43,$00
_sprA08_77:
		.BYTE	$04
		.BYTE	$F0,$A6,$03,$F8
		.BYTE	$F0,$A6,$43,$00
		.BYTE	$00,$4E,$03,$F8
		.BYTE	$00,$4E,$43,$00
_sprA08_78:
		.BYTE	$82
		.WORD	_sprA08_77
		.WORD	_sprA08_78_B
_sprA08_78_B
		.BYTE	$02
		.BYTE	$F0,$58,$03,$F0
		.BYTE	$F8,$58,$03,$08
_sprA08_79:
		.BYTE	$82
		.WORD	_sprA08_77
		.WORD	_sprA08_79_B
_sprA08_79_B:
		.BYTE	$02
		.BYTE	$F0,$48,$03,$F0
		.BYTE	$F8,$48,$03,$08
_sprA08_7A:
		.BYTE	$02
		.BYTE	$FC,$96,$01,$00
		.BYTE	$FC,$96,$01,$F8
_sprA08_7B:
		.BYTE	$01
		.BYTE	$FC,$96,$01,$FC
_sprA08_80:
		.BYTE	$02
		.BYTE	$F8,$86,$41,$00
		.BYTE	$F8,$86,$01,$F8
_sprA08_81:
		.BYTE	$02
		.BYTE	$F8,$F0,$C1,$00
		.BYTE	$F8,$F0,$01,$F8
_sprA08_82:
		.BYTE	$02
		.BYTE	$F8,$B6,$01,$F8
		.BYTE	$F8,$B6,$41,$00
_sprA08_83:
		.BYTE	$02
		.BYTE	$F8,$F0,$41,$00
		.BYTE	$F8,$F0,$81,$F8
_sprA08_84:
		.BYTE	$82
		.WORD	_sprA08_84_A
		.WORD	_sprA08_84_B
_sprA08_84_A:
		.BYTE	$1B
		.BYTE	$05,$A8,$42,$07
		.BYTE	$06,$A8,$02,$F0
		.BYTE	$06,$B8,$02,$F8
		.BYTE	$06,$B8,$42,$00
		.BYTE	$14,$AA,$02,$F1
		.BYTE	$14,$AA,$42,$08
		.BYTE	$14,$BA,$02,$F8
		.BYTE	$14,$BA,$42,$00
		.BYTE	$18,$9A,$02,$E8
		.BYTE	$22,$9C,$02,$EA
		.BYTE	$22,$9C,$42,$10
		.BYTE	$22,$AC,$02,$F1
		.BYTE	$24,$AC,$42,$08
		.BYTE	$CC,$80,$02,$F8
		.BYTE	$CC,$80,$42,$00
		.BYTE	$CC,$A0,$02,$F0
		.BYTE	$CC,$A0,$42,$08
		.BYTE	$DA,$92,$02,$EC
		.BYTE	$DA,$92,$42,$0C
		.BYTE	$DC,$82,$02,$F8
		.BYTE	$DC,$82,$42,$00
		.BYTE	$DC,$A2,$02,$F1
		.BYTE	$DC,$A2,$42,$08
		.BYTE	$EA,$B4,$02,$F8
		.BYTE	$EA,$B4,$42,$00
		.BYTE	$EA,$DA,$02,$0B
		.BYTE	$EA,$DA,$42,$EE
_sprA08_84_B:
		.BYTE	$04
		.BYTE	$F8,$B6,$02,$F8
		.BYTE	$F8,$B6,$42,$00
		.BYTE	$F8,$BE,$02,$07
		.BYTE	$F8,$BE,$42,$F1
_sprA08_85:
		.BYTE	$82
		.WORD	_sprA08_85_A
		.WORD	_sprA08_84_B
_sprA08_85_A:
		.BYTE	$16
		.BYTE	$03,$A8,$42,$07
		.BYTE	$04,$A8,$02,$F1
		.BYTE	$04,$B8,$02,$F8
		.BYTE	$04,$B8,$42,$00
		.BYTE	$11,$AA,$02,$F1
		.BYTE	$11,$AA,$42,$08
		.BYTE	$12,$BA,$02,$F8
		.BYTE	$12,$BA,$42,$00
		.BYTE	$1D,$9C,$02,$EA
		.BYTE	$1F,$9C,$42,$10
		.BYTE	$1F,$AC,$02,$F1
		.BYTE	$20,$AC,$42,$08
		.BYTE	$CE,$80,$02,$F8
		.BYTE	$CE,$80,$42,$00
		.BYTE	$DA,$92,$42,$08
		.BYTE	$DC,$92,$02,$F0
		.BYTE	$DE,$82,$02,$F8
		.BYTE	$DE,$82,$42,$00
		.BYTE	$EA,$DA,$02,$08
		.BYTE	$EA,$DA,$42,$F0
		.BYTE	$EC,$B4,$02,$F8
		.BYTE	$EC,$B4,$42,$00
_sprA08_86:
		.BYTE	$0E
		.BYTE	$00,$C4,$02,$F0
		.BYTE	$00,$C4,$42,$08
		.BYTE	$00,$D4,$02,$F8
		.BYTE	$00,$D4,$42,$00
		.BYTE	$10,$C6,$02,$F0
		.BYTE	$10,$C6,$42,$08
		.BYTE	$10,$D6,$02,$F8
		.BYTE	$10,$D6,$42,$00
		.BYTE	$E0,$D0,$02,$F8
		.BYTE	$E0,$D0,$42,$00
		.BYTE	$F0,$C2,$02,$F0
		.BYTE	$F0,$C2,$42,$08
		.BYTE	$F0,$D2,$02,$F8
		.BYTE	$F0,$D2,$42,$00
_sprA08_87:
		.BYTE	$0E
		.BYTE	$00,$E4,$02,$F0
		.BYTE	$00,$E4,$42,$08
		.BYTE	$00,$F4,$02,$F8
		.BYTE	$00,$F4,$42,$00
		.BYTE	$10,$E6,$02,$F0
		.BYTE	$10,$E6,$42,$08
		.BYTE	$10,$F6,$02,$F8
		.BYTE	$10,$F6,$42,$00
		.BYTE	$E0,$F0,$02,$F8
		.BYTE	$E0,$F0,$42,$00
		.BYTE	$F0,$E2,$02,$F0
		.BYTE	$F0,$E2,$42,$08
		.BYTE	$F0,$F2,$02,$F8
		.BYTE	$F0,$F2,$42,$00
_sprA08_88:
		.BYTE	$0C
		.BYTE	$00,$FA,$82,$F8
		.BYTE	$00,$FA,$C2,$00
		.BYTE	$10,$FA,$82,$00
		.BYTE	$10,$FA,$82,$F0
		.BYTE	$10,$FA,$C2,$08
		.BYTE	$10,$FA,$C2,$F8
		.BYTE	$E0,$FA,$02,$F8
		.BYTE	$E0,$FA,$42,$00
		.BYTE	$F0,$EA,$02,$F0
		.BYTE	$F0,$EA,$42,$08
		.BYTE	$F0,$FA,$02,$F8
		.BYTE	$F0,$FA,$42,$00
_sprA08_89:
		.BYTE	$01
		.BYTE	$F8,$8C,$01,$FC
_sprA08_8A:
		.BYTE	$01
		.BYTE	$F8,$8C,$00,$FC
_sprA08_8B:
		.BYTE	$01
		.BYTE	$F8,$8A,$01,$FC
_sprA08_8C:
		.BYTE	$01
		.BYTE	$F8,$8A,$00,$FC
_sprA08_8D:
		.BYTE	$02
		.BYTE	$F8,$88,$41,$00
		.BYTE	$F8,$88,$01,$F8
_sprA08_8E:
		.BYTE	$02
		.BYTE	$F8,$88,$40,$00
		.BYTE	$F8,$88,$00,$F8
_sprA08_8F:
		.BYTE	$02
		.BYTE	$F8,$98,$41,$00
		.BYTE	$F8,$98,$01,$F8
_sprA08_90:
		.BYTE	$02
		.BYTE	$F8,$98,$40,$00
		.BYTE	$F8,$98,$00,$F8
_sprA08_91:
		.BYTE	$02
		.BYTE	$F8,$9B,$00,$00
		.BYTE	$F8,$8B,$00,$F8
_sprA08_92:
		.BYTE	$04
		.BYTE	$00,$D5,$00,$F8
		.BYTE	$00,$E5,$00,$00
		.BYTE	$F1,$C5,$00,$00
		.BYTE	$F1,$C5,$40,$F8
_sprA08_93:
		.BYTE	$04
		.BYTE	$00,$E5,$00,$00
		.BYTE	$00,$E5,$40,$F8
		.BYTE	$F0,$C5,$00,$00
		.BYTE	$F0,$C5,$40,$F8
_sprA08_94:
		.BYTE	$04
		.BYTE	$00,$D5,$40,$00
		.BYTE	$00,$E5,$40,$F8
		.BYTE	$F1,$C5,$00,$00
		.BYTE	$F1,$C5,$40,$F8

_sprB08_C0:
		.BYTE	$85
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C0_B
		.WORD	_sprB08_C0_C
		.WORD	_sprB08_C0_D
		.WORD	_sprB08_C0_E
_sprB08_C1:
		.BYTE	$84
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C0_B
		.WORD	_sprB08_C1_C
		.WORD	_sprB08_C1_D
_sprB08_C2:
		.BYTE	$82
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C2_B
_sprB08_C3:
		.BYTE	$83
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C0_B
		.WORD	_sprB08_C3_B
_sprB08_C4:
		.BYTE	$82
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C4_B
_sprB08_C5:
		.BYTE	$84
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C0_B
		.WORD	_sprB08_C0_C
		.WORD	_sprB08_C5_B
_sprB08_C6:
		.BYTE	$84
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C0_B
		.WORD	_sprB08_C0_D
		.WORD	_sprB08_C6_B
_sprB08_C7:
		.BYTE	$83
		.WORD	_sprB08_C0_A
		.WORD	_sprB08_C1_C
		.WORD	_sprB08_C7_B
_sprB08_C0_A:
		.BYTE	$12
		.BYTE	$08,$A8,$02,$F0
		.BYTE	$08,$A8,$42,$08
		.BYTE	$08,$B8,$02,$F8
		.BYTE	$08,$B8,$42,$00
		.BYTE	$18,$9A,$02,$E8
		.BYTE	$18,$9A,$42,$10
		.BYTE	$18,$AA,$02,$F0
		.BYTE	$18,$AA,$42,$08
		.BYTE	$18,$BA,$02,$F8
		.BYTE	$18,$BA,$42,$00
		.BYTE	$28,$9C,$02,$E8
		.BYTE	$28,$9C,$42,$10
		.BYTE	$28,$AC,$02,$F0
		.BYTE	$28,$AC,$42,$08
		.BYTE	$C8,$A0,$02,$F0
		.BYTE	$C8,$A0,$42,$08
		.BYTE	$F8,$B6,$02,$F8
		.BYTE	$F8,$B6,$42,$00
_sprB08_C0_B:
		.BYTE	$08
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$D8,$92,$42,$10
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$D8,$B2,$42,$00
_sprB08_C0_C:
		.BYTE	$04
		.BYTE	$E8,$A4,$02,$F0
		.BYTE	$E8,$B4,$02,$F8
		.BYTE	$F8,$96,$02,$E8
		.BYTE	$F8,$A6,$02,$F0
_sprB08_C0_D:
		.BYTE	$04
		.BYTE	$E8,$A4,$42,$08
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$F8,$96,$42,$10
		.BYTE	$F8,$A6,$42,$08
_sprB08_C0_E:
		.BYTE	$04
		.BYTE	$E8,$84,$02,$E0
		.BYTE	$E8,$84,$42,$18
		.BYTE	$E8,$94,$02,$E8
		.BYTE	$E8,$94,$42,$10
_sprB08_C1_C:
		.BYTE	$07
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
_sprB08_C1_D:
		.BYTE	$01
		.BYTE	$E8,$B4,$02,$F8
_sprB08_C2_B:
		.BYTE	$11
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$D8,$B2,$02,$F8
		.BYTE	$D8,$CC,$02,$00
		.BYTE	$D8,$DC,$02,$08
		.BYTE	$D8,$EC,$02,$10
		.BYTE	$E8,$B4,$02,$F8
		.BYTE	$E8,$C8,$42,$F0
		.BYTE	$E8,$CE,$02,$00
		.BYTE	$E8,$D8,$42,$E8
		.BYTE	$E8,$DE,$02,$08
		.BYTE	$E8,$EE,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$F8,$E8,$42,$F0
		.BYTE	$F8,$F8,$42,$E8
_sprB08_C3_B:
		.BYTE	$08
		.BYTE	$E8,$8E,$02,$00
		.BYTE	$E8,$8E,$42,$F8
		.BYTE	$E8,$9E,$02,$08
		.BYTE	$E8,$9E,$42,$F0
		.BYTE	$E8,$AE,$02,$10
		.BYTE	$E8,$AE,$42,$E8
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$F8,$BE,$42,$F0
_sprB08_C4_B:
		.BYTE	$11
		.BYTE	$C8,$B0,$02,$F8
		.BYTE	$C8,$B0,$42,$00
		.BYTE	$D8,$92,$42,$10
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$D8,$B2,$42,$00
		.BYTE	$D8,$CC,$42,$F8
		.BYTE	$D8,$DC,$42,$F0
		.BYTE	$D8,$EC,$42,$E8
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$C8,$02,$08
		.BYTE	$E8,$CE,$42,$F8
		.BYTE	$E8,$D8,$02,$10
		.BYTE	$E8,$DE,$42,$F0
		.BYTE	$E8,$EE,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$F8,$E8,$02,$08
		.BYTE	$F8,$F8,$02,$10
_sprB08_C5_B:
		.BYTE	$06
		.BYTE	$E8,$B4,$42,$00
		.BYTE	$E8,$CA,$02,$08
		.BYTE	$E8,$DA,$02,$10
		.BYTE	$F8,$BE,$02,$08
		.BYTE	$E8,$84,$02,$E0
		.BYTE	$E8,$94,$02,$E8
_sprB08_C6_B:
		.BYTE	$06
		.BYTE	$E8,$CA,$42,$F0
		.BYTE	$E8,$DA,$42,$E8
		.BYTE	$F8,$BE,$42,$F0
		.BYTE	$E8,$84,$42,$18
		.BYTE	$E8,$94,$42,$10
		.BYTE	$E8,$B4,$02,$F8
_sprB08_C7_B:
		.BYTE	$09
		.BYTE	$C8,$80,$02,$F8
		.BYTE	$C8,$80,$42,$00
		.BYTE	$D8,$82,$02,$F8
		.BYTE	$D8,$82,$42,$00
		.BYTE	$D8,$92,$02,$E8
		.BYTE	$D8,$92,$42,$10
		.BYTE	$D8,$A2,$02,$F0
		.BYTE	$D8,$A2,$42,$08
		.BYTE	$E8,$B4,$02,$F8