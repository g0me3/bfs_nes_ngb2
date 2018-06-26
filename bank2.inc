
		ORG $8000

		BANK_START $02

		SECTION_START

		FAR_OFS	_lvl2

_lvl2_objects_list:
		CHECKPOINT
; REGION, changed in the EU version
;		OBJ_SET	_scr1E_pick_axe_miner,				$A8,$00,$90,$06,_NON,_NON,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$A8,$00,$98,$06,_NON,_NON,_NON
; -
		OBJ_SET	_scr1E_pick_axe_miner,				$A8,$00,$68,$06,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $01
		ROOM	$01
		OBJ_SET	_scr1E_pick_axe_miner,				$50,$00,$88,$05,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr1E_pick_axe_miner,				$A0,$00,$98,$05,_NON,_NON,_NON
; -
		OBJ_SET	_scr1E_pick_axe_miner,				$C0,$00,$08,$05,_NON,_NON,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$38,$00,$D0,$04,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr1E_pick_axe_miner,				$88,$00,$28,$05,_NON,_NON,_NON
; -
; REGION, changed in the EU version
;		OBJ_SET	_scr1E_pick_axe_miner,				$B8,$00,$C0,$04,_NON,_NON,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$98,$00,$C0,$04,_NON,_NON,_NON
; -
		OBJ_SET	_scr1E_pick_axe_miner,				$C0,$00,$48,$04,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $02
		ROOM	$02
		OBJ_SET	_scr1D_air_hammer_miner,			$80,$00,$C0,$03,_NON,_NON,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$80,$00,$30,$03,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $03
		ROOM	$03
		CHECKPOINT
		OBJ_SET	_scr1E_pick_axe_miner,				$38,$01,$88,$06,_NON,_NON,_NON
		OBJ_SET	_scr20_trolley_miner,				$88,$01,$78,$06,_NON, $80,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $04
		ROOM	$04
		OBJ_SET	_scr20_trolley_miner,				$18,$01,$28,$05,_NON, $40,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr20_trolley_miner,				$78,$01,$78,$04,_NON, $40,_NON
; -
		OBJ_SET	_scr20_trolley_miner,				$F8,$01,$A8,$04,_NON, $C0,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$38,$01,$78,$05,_NON,_NON,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$88,$01,$20,$05,_NON,_NON,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$80,$01,$D0,$04,_NON,_NON,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$38,$01,$68,$04,_NON,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr20_trolley_miner,				$58,$01,$A8,$04,_NON, $00,_NON
		OBJ_SET	_scr20_trolley_miner,				$E8,$01,$A8,$05,_NON, $C0,_NON
; -
		OBJ_SET	_scr1D_air_hammer_miner,			$98,$01,$98,$04,_NON,_NON,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$50,$01,$38,$04,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$80,$01,$50,$04, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $05
		ROOM	$05
		CHECKPOINT
		OBJ_SET	_scr20_trolley_miner,				$68,$01,$78,$03,_NON, $00,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$A8,$01,$60,$03,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr20_trolley_miner,				$B8,$01,$08,$03,_NON, $80,_NON
; -
		OBJ_SET	_scr1D_air_hammer_miner,			$30,$01,$20,$03,_NON,_NON,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$98,$01,$98,$02,_NON,_NON,_NON
		OBJ_SET	_scr20_trolley_miner,				$68,$01,$78,$02,_NON, $80,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$38,$01,$40,$02,_NON,_NON,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$C0,$01,$48,$02,_NON,_NON,_NON
		OBJ_SET	_scr20_trolley_miner,				$B8,$01,$58,$02,_NON, $80,_NON
		OBJ_SET	_scr0D_money_bag,					$80,$01,$50,$02, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AD, $06
		ROOM	$06
		OBJ_SET	_scr20_trolley_miner,				$98,$02,$58,$02,_NON, $C0,_NON
		OBJ_SET	_scr1F_hammer_miner,				$78,$02,$B0,$02,_NON,_NON,_NON
		OBJ_SET	_scr1F_hammer_miner,				$10,$03,$80,$02,_NON,_NON,_NON
		OBJ_SET	_scr20_trolley_miner,				$98,$03,$98,$02,_NON, $C0,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr20_trolley_miner,				$38,$03,$88,$02,_NON, $40,_NON
; -
		OBJ_SET	_scr1F_hammer_miner,				$78,$03,$50,$02,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$60,$02,$70,$02, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AD, $07
		ROOM	$07
		CHECKPOINT
; REGION, changed in the EU version
;		OBJ_SET	_scr1F_hammer_miner,				$58,$04,$68,$02,_NON,_NON,_NON
		OBJ_SET	_scr1F_hammer_miner,				$58,$04,$48,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr1E_pick_axe_miner,				$B8,$04,$68,$02,_NON,_NON,_NON
		OBJ_SET	_scr20_trolley_miner,				$A8,$04,$C8,$02,_NON, $00,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$C8,$04,$C0,$02,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$88,$04,$C0,$02, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $08
		ROOM	$08
		OBJ_SET	_scr20_trolley_miner,				$68,$04,$B8,$01,_NON, $00,_NON
		OBJ_SET	_scr1E_pick_axe_miner,				$D0,$04,$98,$01,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr20_trolley_miner,				$B8,$04,$68,$01,_NON, $80,_NON
; -
		OBJ_SET	_scr1F_hammer_miner,				$40,$04,$60,$01,_NON,_NON,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$80,$04,$00,$01,_NON,_NON,_NON
		OBJ_SET	_scr1F_hammer_miner,				$40,$04,$90,$00,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr20_trolley_miner,				$B8,$04,$88,$00,_NON, $00,_NON
; -
		OBJ_SET	_scr1E_pick_axe_miner,				$80,$04,$38,$00,_NON,_NON,_NON
		OBJ_SET	_scr1D_air_hammer_miner,			$B8,$04,$68,$00,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$80,$04,$58,$00, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AD, $09
		ROOM	$09
		CHECKPOINT
		ROOM	$0A
		OBJ_SET	_scr10_train_semaphores,			$80,$05,$80,$01,_NON,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$90,$05,$98,$01, $00,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$70,$05,$08,$02, $01,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr21_train_ghost,					$80,$05,$40,$02, $03,_NON,_NON
;		OBJ_SET	_scr21_train_ghost,					$70,$05,$98,$02, $02,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$80,$05,$40,$02, $02,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$70,$05,$98,$02, $01,_NON,_NON
; -
; REGION, removed in the EU version
		OBJ_SET	_scr21_train_ghost,					$80,$05,$60,$02, $00,_NON,_NON
; -
		ROOM	$0B
		OBJ_SET	_scr10_train_semaphores,			$80,$05,$80,$03,_NON,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$6C,$05,$98,$04, $03,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$6C,$05,$68,$03, $04,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr21_train_ghost,					$94,$05,$98,$03, $02,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$94,$05,$98,$03, $03,_NON,_NON
; -
		OBJ_SET	_scr21_train_ghost,					$6C,$05,$38,$04, $05,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr21_train_ghost,					$80,$05,$A8,$03, $03,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$80,$05,$88,$04, $05,_NON,_NON
; -
		OBJ_SET	_scr21_train_ghost,					$94,$05,$68,$04, $04,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$6C,$05,$C8,$03, $03,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr21_train_ghost,					$94,$05,$08,$04, $01,_NON,_NON
		OBJ_SET	_scr21_train_ghost,					$94,$05,$08,$04, $05,_NON,_NON
; -
		ROOM	$0C
		OBJ_SET	_scr10_train_semaphores,			$80,$05,$80,$05,_NON,_NON,_NON
		OBJ_SET	_scr22_lvl2_boss_train_slime,		$80,$05,$90,$05,_NON,_NON,_NON
		OBJ_END

_lvl2_collisionsA:
		.BYTE	$3C,$00,$00,$00,$C0,$03,$0C,$03,$03,$FB,$F3,$FB,$F0,$F0,$F0,$F1
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl2_collisionsB:
		.BYTE	$3D,$E9,$FF,$F9,$EF,$FE,$FD,$FE,$FD,$FC,$FF,$FF,$0D,$FF,$0B,$FF
		.BYTE	$00,$0F,$00,$0C,$00,$00,$00,$10,$00,$00,$00,$00,$00,$00,$00,$00
_lvl2_macroA_tbl:
		.BYTE	$FF,$00,$0C,$06,$26,$2A,$1E,$62,$42,$13,$13,$6E,$40,$13,$5D,$FF
		.BYTE	$00,$60,$0A,$08,$13,$2C,$1E,$13,$13,$42,$13,$6E,$42,$13,$13,$FF
		.BYTE	$02,$04,$44,$40,$40,$42,$44,$42,$20,$24,$59,$5A,$47,$46,$5A,$47
		.BYTE	$48,$48,$14,$1E,$3F,$5A,$2E,$48,$3E,$53,$FF,$4A,$49,$5B,$5A,$FF
		.BYTE	$48,$58,$57,$13,$48,$44,$59,$59,$5A,$51,$FF,$5A,$5A,$47,$5A,$7A
		.BYTE	$59,$FF,$5A,$25,$25,$47,$25,$9E,$9F,$9E,$FF,$9E,$FF,$AA,$FF,$FF
		.BYTE	$FF,$5C,$3F,$FF,$3F,$4A,$49,$3F,$3F,$3A,$3E,$49,$24,$60,$62,$23
		.BYTE	$FF,$BC,$FF,$25,$47,$8C,$21,$4A,$49,$22,$20,$20,$40,$42,$23,$23
		.BYTE	$21,$09,$21,$8D,$21,$3A,$4A,$4A,$49,$8D,$8C,$21,$23,$23,$10,$12
		.BYTE	$3F,$07,$3F,$3C,$49,$4A,$37,$39,$FF,$3C,$3C,$49,$23,$FF,$14,$16
		.BYTE	$3F,$6F,$6F,$FF,$5C,$6D,$5C,$68,$6A,$6C,$FF,$FF,$FF,$FF,$21,$23
		.BYTE	$3F,$1C,$6F,$FF,$3F,$5C,$3F,$FF,$54,$FF,$77,$FF,$7E,$7E,$87,$23
		.BYTE	$FF,$FF,$87,$FF,$28,$13,$44,$13,$40,$7F,$13,$7F,$1E,$13,$7F,$7F
		.BYTE	$BB,$BB,$7E,$47,$4A,$49,$DC,$DE,$7F,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl2_macroB_tbl:
		.BYTE	$FF,$00,$1C,$16,$36,$3A,$1E,$72,$13,$13,$13,$6E,$54,$43,$13,$13
		.BYTE	$00,$70,$1A,$18,$13,$3C,$0E,$13,$43,$13,$13,$6E,$13,$43,$4E,$13
		.BYTE	$43,$FF,$40,$54,$40,$43,$54,$43,$30,$34,$59,$5A,$47,$56,$5A,$6A
		.BYTE	$5A,$51,$22,$1E,$5A,$2F,$40,$FF,$FF,$FF,$43,$5A,$5A,$47,$5A,$FF
		.BYTE	$59,$59,$59,$13,$5A,$54,$4A,$49,$5A,$47,$43,$58,$57,$4B,$5A,$47
		.BYTE	$48,$13,$5A,$25,$57,$4B,$58,$9F,$9E,$FF,$9E,$9E,$AA,$FF,$FF,$FF
		.BYTE	$FF,$4E,$3F,$FF,$5E,$3F,$3F,$4A,$49,$4A,$9C,$21,$24,$23,$23,$70
		.BYTE	$FF,$FF,$AC,$25,$47,$2E,$8F,$2C,$49,$30,$32,$FF,$50,$52,$23,$72
		.BYTE	$FF,$19,$FF,$2A,$8F,$4A,$27,$29,$FF,$2A,$2A,$8F,$23,$20,$40,$42
		.BYTE	$3F,$6F,$21,$9D,$21,$2C,$5A,$4A,$49,$9D,$9C,$21,$23,$21,$22,$20
		.BYTE	$3F,$0C,$6F,$FF,$3F,$7D,$3F,$78,$7A,$6C,$67,$FF,$6E,$6E,$FF,$21
		.BYTE	$21,$54,$6F,$FF,$5E,$FF,$5E,$76,$76,$76,$FF,$FF,$FF,$FF,$87,$23
		.BYTE	$87,$87,$87,$87,$38,$13,$40,$43,$40,$13,$7F,$1E,$7F,$13,$13,$13
		.BYTE	$BB,$BB,$13,$47,$CC,$CE,$4A,$49,$7F,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl2_macroC_tbl:
		.BYTE	$FF,$00,$0D,$07,$27,$2B,$1E,$63,$67,$13,$13,$6F,$13,$41,$42,$32
		.BYTE	$01,$61,$0B,$09,$13,$2D,$1E,$67,$67,$42,$13,$6F,$45,$13,$13,$FF
		.BYTE	$03,$05,$45,$41,$41,$42,$42,$45,$21,$25,$59,$47,$47,$47,$47,$47
		.BYTE	$48,$12,$15,$33,$5B,$47,$48,$48,$53,$53,$32,$48,$5B,$5C,$68,$FF
		.BYTE	$48,$48,$59,$41,$48,$45,$59,$59,$50,$52,$FF,$59,$47,$47,$79,$7B
		.BYTE	$59,$FF,$59,$26,$47,$47,$59,$9E,$9F,$9E,$FF,$9E,$FF,$AB,$0F,$1F
		.BYTE	$5C,$5D,$3F,$1F,$3F,$49,$49,$3F,$1D,$49,$49,$49,$24,$61,$63,$23
		.BYTE	$3F,$BD,$3F,$47,$47,$21,$21,$49,$49,$20,$20,$21,$41,$43,$23,$23
		.BYTE	$08,$0A,$21,$FF,$21,$3B,$7F,$49,$49,$56,$21,$21,$23,$23,$11,$13
		.BYTE	$06,$FF,$3F,$49,$49,$7F,$38,$FF,$FF,$3D,$49,$49,$46,$3F,$15,$17
		.BYTE	$3F,$74,$74,$5C,$5C,$7C,$5C,$69,$6B,$FF,$FF,$FF,$FF,$FF,$21,$23
		.BYTE	$1B,$45,$FF,$75,$3F,$5C,$0F,$54,$FF,$FF,$77,$7D,$7E,$FF,$87,$23
		.BYTE	$FF,$97,$BA,$FF,$29,$41,$42,$13,$13,$7F,$41,$7F,$1E,$7F,$7F,$7F
		.BYTE	$BB,$BB,$7E,$6D,$49,$49,$DD,$DF,$7F,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl2_macroD_tbl:
		.BYTE	$FF,$00,$1D,$17,$37,$3B,$1E,$73,$77,$13,$13,$6F,$43,$55,$13,$13
		.BYTE	$01,$71,$1B,$19,$13,$3D,$0E,$77,$77,$13,$13,$6F,$41,$4D,$4F,$13
		.BYTE	$43,$43,$41,$55,$41,$43,$43,$55,$31,$35,$59,$47,$47,$47,$69,$6B
		.BYTE	$50,$52,$FF,$1E,$47,$4B,$13,$FF,$FF,$FF,$43,$59,$47,$47,$78,$6C
		.BYTE	$59,$59,$59,$41,$59,$55,$48,$59,$47,$47,$43,$48,$4B,$4C,$47,$47
		.BYTE	$48,$55,$59,$26,$4B,$4C,$48,$9F,$9E,$FF,$9E,$9E,$AB,$FF,$0F,$1F
		.BYTE	$0F,$4F,$3F,$5E,$5F,$3F,$0D,$49,$49,$49,$21,$21,$24,$23,$23,$71
		.BYTE	$3F,$3F,$AD,$47,$47,$8E,$4D,$49,$49,$31,$33,$FF,$51,$53,$23,$73
		.BYTE	$18,$1A,$FF,$8E,$4D,$7F,$28,$FF,$FF,$2B,$8E,$4D,$36,$21,$41,$43
		.BYTE	$3F,$64,$21,$FF,$21,$2D,$5B,$49,$49,$56,$21,$21,$23,$21,$20,$20
		.BYTE	$0B,$FF,$FF,$66,$3F,$77,$1F,$79,$7B,$FF,$67,$6D,$6E,$7C,$FF,$21
		.BYTE	$44,$55,$64,$5E,$5E,$FF,$5E,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$87,$23
		.BYTE	$87,$87,$BA,$BA,$39,$41,$13,$43,$13,$41,$7F,$1E,$7F,$7F,$13,$7F
		.BYTE	$BB,$87,$13,$47,$CD,$CF,$49,$49,$7F,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl2_attrs_tbl:
		.BYTE	$00,$01,$01,$01,$01,$01,$01,$01,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$01,$01,$01,$01,$02,$01,$01,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$01,$01,$01,$03,$03,$03,$03,$03
		.BYTE	$03,$01,$01,$01,$03,$03,$02,$01,$03,$03,$02,$01,$03,$03,$03,$01
		.BYTE	$01,$01,$01,$01,$01,$02,$01,$01,$03,$03,$02,$01,$03,$03,$03,$03
		.BYTE	$01,$02,$01,$01,$03,$03,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$02,$03,$03,$03
		.BYTE	$01,$01,$01,$03,$03,$01,$01,$01,$01,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$03,$03,$03
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$03,$03
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$02,$01
		.BYTE	$02,$02,$02,$02,$01,$02,$02,$02,$02,$02,$02,$01,$01,$02,$02,$02
		.BYTE	$02,$02,$02,$03,$01,$01,$01,$01,$02,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl2_rooms_lib:
		.WORD	      0,      0,      0,      0,_l2_r40,_l2_r50,      0,      0
		.WORD	      0,      0,      0,      0,_l2_r41,_l2_r51,      0,      0
		.WORD	      0,_l2_r40,_l2_r22,_l2_r32,_l2_r42,_l2_r52,      0,      0
		.WORD	_l2_r03,_l2_r41,      0,      0,      0,_l2_r51,      0,      0
		.WORD	_l2_r04,_l2_r14,      0,      0,      0,_l2_r52,      0,      0
		.WORD	_l2_r05,_l2_r15,      0,      0,      0,_l2_r55,      0,      0
		.WORD	_l2_r06,_l2_r42,      0,      0,      0,_l2_r56,      0,      0
_l2_r42:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$46,$48,$2B,$2B,$2B,$4C,$0A,$1A,$3C,$2B,$2B,$2B,$2B,$41,$2A
		.BYTE	$2B,$4C,$49,$2D,$2C,$2D,$4D,$0B,$1B,$3D,$2C,$2D,$2C,$2D,$40,$2A
		.BYTE	$2C,$4D,$0F,$09,$09,$09,$09,$09,$C5,$C5,$C5,$1A,$C5,$09,$40,$2A
		.BYTE	$CE,$09,$09,$09,$09,$09,$09,$C7,$04,$06,$C4,$25,$11,$19,$40,$2A
		.BYTE	$52,$4B,$09,$09,$09,$09,$09,$C7,$01,$26,$10,$27,$01,$19,$40,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$09,$09,$C7,$01,$25,$03,$06,$12,$19,$40,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$3B,$4B,$C7,$01,$25,$01,$26,$01,$19,$40,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$40,$50,$4A,$10,$25,$10,$25,$10,$19,$40,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$40,$50,$20,$01,$25,$02,$06,$13,$19,$40,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$40,$50,$21,$05,$06,$13,$25,$01,$19,$40,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$40,$50,$1F,$C8,$0C,$01,$25,$01,$19,$40,$2A
		.BYTE	$2A,$47,$52,$52,$52,$42,$50,$1F,$09,$C7,$10,$25,$10,$19,$40,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$1F,$09,$3B,$52,$52,$52,$52,$42,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$CF,$CD,$40,$2A,$2A,$2A,$2A,$2A,$2A
_l2_r40:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$46,$48,$2B,$2B,$2B,$2B,$2B,$2B,$2B,$2B,$2B,$2B,$41,$2A,$2A
		.BYTE	$2A,$50,$49,$2D,$2C,$2D,$2C,$2D,$2C,$2D,$2C,$2D,$2C,$3C,$2B,$2B
		.BYTE	$2A,$50,$1F,$C5,$C5,$C5,$C5,$C5,$C5,$C5,$C5,$C5,$09,$3D,$D3,$2C
		.BYTE	$2A,$50,$4A,$04,$06,$06,$06,$06,$06,$16,$06,$C4,$19,$09,$D2,$0A
		.BYTE	$2A,$50,$4A,$10,$36,$C8,$24,$24,$24,$24,$23,$01,$19,$3B,$52,$52
		.BYTE	$2A,$50,$4A,$01,$37,$C7,$04,$16,$06,$06,$16,$12,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$4A,$01,$38,$C7,$01,$C6,$34,$35,$0C,$01,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$4A,$01,$39,$C7,$01,$0E,$3D,$4D,$1D,$01,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$4A,$10,$19,$C7,$10,$19,$09,$09,$C7,$10,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$4A,$01,$0E,$C7,$01,$19,$34,$35,$C7,$01,$19,$3C,$41,$2A
		.BYTE	$2A,$50,$4A,$10,$1C,$0D,$10,$0E,$3D,$4D,$C7,$10,$19,$3D,$40,$2A
		.BYTE	$2A,$50,$4A,$02,$06,$16,$13,$1C,$C5,$09,$20,$01,$1C,$C5,$40,$2A
		.BYTE	$2A,$50,$4A,$10,$36,$0C,$02,$06,$C4,$19,$21,$02,$06,$29,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$37,$C7,$10,$26,$10,$1C,$0D,$10,$C6,$C8,$40,$2A
_l2_r06:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$0B,$1B,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$3C,$2B,$2B,$2B,$41,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$47,$4B,$09,$3D,$2D,$2C,$2D,$40,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$50,$1F,$C5,$C5,$C5,$09,$40,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$50,$4A,$04,$06,$C4,$19,$40,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$50,$4A,$01,$27,$01,$19,$40,$2A,$2A
		.BYTE	$2A,$46,$48,$2B,$2B,$2B,$2B,$4C,$4A,$02,$06,$13,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$49,$2D,$2C,$2D,$2C,$4D,$3A,$01,$26,$01,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$09,$09,$09,$C7,$10,$25,$10,$19,$40,$2A,$2A
		.BYTE	$2A,$50,$1F,$09,$09,$09,$09,$09,$C7,$01,$25,$01,$19,$40,$2A,$2A
		.BYTE	$2A,$47,$52,$52,$52,$52,$52,$4B,$C7,$11,$25,$11,$19,$40,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$50,$1F,$C8,$C8,$C8,$09,$40,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$47,$52,$52,$52,$52,$52,$42,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A
_l2_r41:
		.BYTE	$2A,$50,$4A,$01,$38,$C7,$01,$25,$03,$06,$16,$12,$19,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$39,$C7,$01,$25,$01,$C6,$0C,$10,$19,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$1C,$0D,$01,$25,$01,$19,$C7,$01,$19,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$03,$06,$16,$12,$25,$01,$19,$20,$01,$1C,$C5,$40,$2A
		.BYTE	$2A,$50,$4A,$10,$C6,$0C,$10,$25,$10,$19,$21,$03,$06,$29,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$0E,$C7,$01,$25,$01,$0E,$1D,$10,$C6,$C8,$40,$2A
		.BYTE	$2A,$50,$4A,$10,$19,$C7,$10,$25,$10,$19,$C7,$10,$19,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$19,$20,$01,$25,$10,$19,$C7,$10,$19,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$0E,$21,$01,$25,$10,$19,$C7,$01,$19,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$1C,$0D,$01,$25,$10,$19,$1D,$01,$1C,$C5,$40,$2A
		.BYTE	$2A,$50,$4A,$02,$06,$16,$13,$25,$11,$19,$C7,$02,$06,$29,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$C6,$0C,$01,$22,$24,$24,$23,$01,$C6,$C8,$40,$2A
		.BYTE	$2A,$50,$4A,$10,$0E,$C7,$05,$06,$06,$06,$06,$15,$0E,$09,$40,$2A
		.BYTE	$2A,$47,$52,$52,$52,$52,$4B,$C8,$C8,$3B,$52,$52,$52,$52,$42,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$CF,$CD,$40,$2A,$2A,$2A,$2A,$2A,$2A
_l2_r50:
		.BYTE	$2A,$2A,$50,$D0,$D0,$D0,$D0,$D0,$D0,$D0,$D0,$D0,$D0,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$C0,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$73,$73,$54,$C0,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$74,$74,$55,$C1,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$53,$53,$56,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$C0,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$C0,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$BE,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$C3,$C2,$C2,$C2,$C2,$C2,$C2,$C2,$C2,$C2,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$60,$5E,$5C,$5D,$5F,$63,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$61,$62,$62,$62,$62,$64,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$75,$69,$D4,$D6,$77,$6A,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$76,$78,$D5,$D7,$78,$6B,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$AE,$BF,$BF,$BF,$BF,$AF,$5B,$00,$40,$2A,$2A
_l2_r14:
		.BYTE	$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A
		.BYTE	$2A,$46,$48,$4C,$0A,$1A,$3C,$2B,$2B,$4C,$0A,$1A,$3C,$2B,$41,$2A
		.BYTE	$2A,$50,$49,$4D,$0B,$1B,$3D,$2D,$2C,$4D,$0B,$1B,$3D,$2D,$40,$2A
		.BYTE	$2A,$50,$1F,$C5,$C5,$C5,$09,$09,$09,$09,$C5,$C5,$C5,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$04,$06,$C4,$19,$09,$09,$C7,$04,$06,$C4,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$26,$01,$19,$09,$09,$C7,$01,$26,$01,$0E,$40,$2A
		.BYTE	$2A,$50,$4A,$10,$25,$10,$1C,$C5,$C5,$0D,$10,$25,$10,$19,$40,$2A
		.BYTE	$2B,$4C,$4A,$01,$27,$02,$06,$16,$06,$06,$12,$25,$01,$19,$3C,$2B
		.BYTE	$2C,$4D,$3A,$02,$16,$12,$C6,$C8,$C8,$0C,$01,$25,$01,$0E,$3D,$2C
		.BYTE	$C9,$C5,$0D,$01,$20,$01,$19,$09,$09,$C7,$01,$20,$01,$1C,$C5,$CA
		.BYTE	$CB,$16,$06,$12,$21,$01,$19,$09,$09,$C7,$01,$21,$02,$06,$16,$CC
		.BYTE	$52,$4B,$0C,$10,$25,$10,$19,$09,$09,$C7,$03,$06,$13,$C6,$3B,$52
		.BYTE	$2A,$50,$4A,$01,$25,$01,$19,$09,$09,$C7,$01,$26,$01,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$25,$01,$19,$09,$09,$C7,$10,$25,$01,$0E,$40,$2A
		.BYTE	$2B,$4C,$4A,$01,$25,$01,$19,$34,$35,$C7,$10,$25,$10,$19,$3C,$2B
_l2_r51:
		.BYTE	$2A,$2A,$50,$00,$6C,$89,$85,$86,$96,$95,$99,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$8A,$69,$D4,$D6,$77,$9A,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$8B,$78,$D5,$D7,$78,$9B,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$AE,$7E,$7E,$7E,$7E,$AF,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$7E,$7E,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$8C,$9C,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$7E,$7E,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
_l2_r15:
		.BYTE	$2C,$4D,$3A,$10,$25,$10,$19,$3D,$4D,$1E,$10,$25,$10,$19,$3D,$2C
		.BYTE	$C9,$C5,$0D,$01,$25,$01,$1C,$C5,$C5,$0D,$10,$25,$01,$1C,$C5,$CA
		.BYTE	$CB,$16,$06,$13,$25,$03,$06,$06,$06,$06,$12,$25,$03,$06,$16,$CC
		.BYTE	$52,$4B,$0C,$01,$25,$01,$C6,$C8,$24,$23,$01,$25,$01,$C6,$3B,$52
		.BYTE	$2A,$50,$4A,$01,$27,$10,$19,$0D,$04,$06,$12,$25,$01,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$02,$16,$12,$25,$04,$15,$26,$01,$25,$01,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$10,$26,$10,$25,$10,$C6,$C7,$01,$25,$01,$0E,$40,$2A
		.BYTE	$2B,$4C,$4A,$10,$25,$10,$25,$10,$19,$C7,$10,$25,$01,$19,$3C,$2B
		.BYTE	$2C,$4D,$3A,$01,$25,$10,$25,$10,$1C,$C7,$01,$25,$01,$19,$3D,$2C
		.BYTE	$C9,$C5,$0D,$01,$20,$01,$25,$05,$C4,$20,$01,$20,$01,$1C,$C5,$CA
		.BYTE	$CB,$16,$06,$13,$21,$10,$1C,$23,$01,$21,$10,$21,$03,$06,$16,$CC
		.BYTE	$52,$4B,$0C,$01,$27,$02,$06,$06,$15,$25,$11,$27,$10,$C6,$3B,$52
		.BYTE	$2A,$50,$4A,$05,$16,$15,$C6,$C8,$C8,$C7,$05,$16,$15,$19,$40,$2A
		.BYTE	$2A,$47,$52,$52,$52,$52,$4B,$09,$09,$3B,$52,$52,$52,$52,$42,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$CF,$CD,$40,$2A,$2A,$2A,$2A,$2A,$2A
_l2_r52:
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$7E,$7E,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$7E,$7E,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$7E,$7E,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7B,$7E,$8C,$9C,$7E,$8D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$79,$7C,$6D,$6F,$8E,$9E,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$83,$69,$D4,$D6,$77,$93,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$8B,$78,$D5,$D7,$78,$9B,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$AE,$7E,$7E,$7E,$7E,$AF,$6C,$00,$40,$2A,$2A
_l2_r04:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$46,$48,$2B,$2B,$2B,$4C,$0A,$0A,$3C,$2B,$2B,$2B,$2B,$41,$2A
		.BYTE	$2A,$50,$49,$2D,$2C,$2D,$4D,$0B,$0B,$3D,$2D,$2C,$2D,$2C,$40,$2A
		.BYTE	$2A,$50,$1F,$C5,$C5,$C5,$C5,$C5,$C5,$09,$09,$09,$09,$09,$40,$2A
		.BYTE	$2A,$50,$4A,$04,$16,$06,$06,$16,$C4,$1C,$C5,$C5,$C5,$C5,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$26,$11,$C6,$0C,$02,$06,$06,$16,$06,$29,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$27,$01,$19,$C7,$01,$C6,$3B,$52,$52,$52,$42,$2A
		.BYTE	$2A,$50,$4A,$03,$16,$15,$19,$C7,$01,$19,$3C,$2B,$2B,$2B,$2B,$2B
		.BYTE	$2A,$50,$4A,$10,$C6,$0C,$1C,$0D,$01,$0E,$3D,$2D,$2C,$2D,$2C,$2D
		.BYTE	$2A,$50,$4A,$01,$19,$C7,$04,$06,$13,$19,$09,$09,$C5,$C5,$C5,$CA
		.BYTE	$2A,$50,$4A,$10,$0E,$C7,$01,$26,$01,$19,$C5,$0D,$04,$06,$16,$CC
		.BYTE	$2A,$50,$4A,$01,$19,$C7,$11,$25,$10,$25,$04,$16,$12,$C6,$3B,$52
		.BYTE	$2A,$50,$4A,$01,$1C,$0D,$01,$25,$01,$25,$10,$26,$10,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$02,$16,$06,$15,$25,$10,$25,$01,$25,$01,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$01,$C6,$C8,$C8,$C7,$01,$25,$01,$25,$01,$19,$40,$2A
_l2_r55:
		.BYTE	$2A,$2A,$50,$00,$6C,$7A,$7D,$6E,$7F,$8F,$9F,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$83,$69,$D4,$D6,$77,$93,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$84,$78,$D5,$D7,$78,$94,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$82,$70,$72,$71,$70,$9D,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$82,$62,$62,$62,$62,$92,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$82,$62,$62,$62,$62,$92,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$82,$62,$62,$62,$62,$92,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$82,$62,$62,$62,$62,$92,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$82,$62,$62,$62,$62,$92,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$80,$90,$62,$62,$A0,$B0,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$81,$91,$A2,$B2,$A1,$B1,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$A3,$A7,$A9,$00,$B7,$B3,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$A4,$A8,$AA,$BA,$B8,$B4,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$A5,$A8,$00,$00,$B9,$B4,$6C,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$6C,$A5,$A8,$AB,$BB,$B9,$B5,$6C,$00,$40,$2A,$2A
_l2_r05:
		.BYTE	$2A,$50,$4A,$10,$1C,$C5,$C5,$0D,$03,$06,$13,$27,$01,$19,$40,$2A
		.BYTE	$2A,$50,$4A,$05,$06,$06,$06,$06,$12,$26,$05,$06,$15,$19,$40,$2A
		.BYTE	$2A,$47,$52,$52,$52,$52,$4B,$26,$01,$19,$3B,$52,$52,$52,$42,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$20,$10,$19,$40,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$46,$48,$2B,$2B,$2B,$4C,$21,$01,$19,$3C,$2B,$2B,$2B,$41,$2A
		.BYTE	$2B,$4C,$49,$2D,$2C,$2D,$4D,$3A,$01,$0E,$3D,$2D,$2C,$2D,$40,$2A
		.BYTE	$2C,$4D,$0F,$C5,$C5,$C5,$C5,$0D,$10,$19,$C5,$09,$C5,$09,$40,$2A
		.BYTE	$C9,$C5,$0D,$04,$06,$16,$06,$06,$13,$25,$11,$25,$11,$19,$40,$2A
		.BYTE	$CB,$16,$06,$12,$C6,$C8,$C8,$0C,$01,$25,$01,$25,$01,$0E,$3C,$2B
		.BYTE	$2B,$35,$0C,$01,$19,$C5,$C5,$0D,$01,$25,$10,$25,$01,$19,$3D,$2C
		.BYTE	$2C,$4D,$3A,$01,$25,$04,$06,$06,$12,$25,$01,$25,$01,$1C,$C5,$CA
		.BYTE	$C9,$C5,$0D,$10,$25,$01,$C6,$0C,$01,$25,$01,$27,$02,$06,$16,$CC
		.BYTE	$CB,$16,$06,$13,$27,$01,$19,$1D,$01,$27,$02,$16,$15,$C6,$3B,$52
		.BYTE	$52,$4B,$0C,$05,$06,$15,$19,$C7,$05,$06,$15,$C6,$C8,$09,$40,$2A
		.BYTE	$2A,$47,$52,$52,$52,$52,$4B,$CD,$CD,$3B,$52,$52,$52,$52,$42,$2A
_l2_r56:
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
		.BYTE	$2A,$2A,$50,$00,$5B,$58,$58,$59,$5A,$57,$57,$5B,$00,$40,$2A,$2A
_l2_r22:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$46,$48,$2B,$2B,$2B,$2B,$2B,$41,$2A,$2A,$2A,$46,$2B,$2B
		.BYTE	$2B,$2B,$4C,$49,$2C,$2D,$2C,$2D,$2C,$3C,$2B,$2B,$2B,$4C,$2C,$2D
		.BYTE	$2C,$D3,$4D,$0F,$C5,$C5,$C5,$C5,$09,$3D,$2D,$2C,$2D,$4D,$09,$C5
		.BYTE	$09,$D2,$09,$C7,$04,$16,$06,$C4,$1C,$C5,$C5,$C5,$C5,$C5,$0D,$04
		.BYTE	$52,$52,$4B,$C7,$10,$C6,$0C,$03,$06,$06,$16,$06,$06,$06,$16,$13
		.BYTE	$2A,$2A,$50,$4A,$01,$19,$C7,$01,$C6,$34,$2B,$2B,$2B,$35,$0C,$10
		.BYTE	$2A,$2A,$50,$4A,$01,$1C,$0D,$01,$0E,$3D,$2D,$2C,$2D,$4D,$3A,$01
		.BYTE	$2A,$2A,$50,$4A,$03,$06,$06,$13,$1C,$C5,$C5,$C5,$C5,$C5,$0D,$03
		.BYTE	$2A,$2A,$50,$4A,$01,$C6,$23,$02,$06,$06,$16,$06,$06,$06,$16,$12
		.BYTE	$2A,$2A,$50,$4A,$01,$25,$04,$15,$C6,$34,$2B,$2B,$2B,$35,$0C,$01
		.BYTE	$2A,$2A,$50,$4A,$01,$27,$01,$C6,$09,$3D,$2D,$2C,$2D,$4D,$3A,$10
		.BYTE	$2A,$2A,$50,$4A,$05,$06,$15,$19,$09,$09,$09,$09,$09,$09,$C7,$05
		.BYTE	$2A,$2A,$47,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A
_l2_r32:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2B,$2B,$2B,$2B,$2B,$2B,$2B,$2B,$41,$2A,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2C,$2D,$2C,$2D,$2C,$2D,$2C,$2D,$3C,$2B,$2B,$2B,$2B,$2B,$2B,$2B
		.BYTE	$C5,$C5,$C5,$C5,$C5,$C5,$C5,$1A,$3D,$2D,$2C,$2D,$2C,$2D,$D3,$2C
		.BYTE	$06,$16,$06,$06,$06,$16,$C4,$1C,$C5,$C5,$C5,$C5,$09,$09,$D2,$09
		.BYTE	$C6,$34,$2B,$2B,$35,$0C,$02,$06,$06,$16,$06,$C4,$19,$3B,$52,$52
		.BYTE	$0E,$3D,$2C,$2D,$4D,$3A,$10,$C6,$34,$35,$0C,$10,$19,$40,$2A,$2A
		.BYTE	$1C,$C5,$C5,$C5,$C5,$0D,$10,$0E,$3D,$4D,$3A,$01,$19,$40,$2A,$2A
		.BYTE	$06,$16,$06,$06,$06,$16,$12,$1C,$C5,$C5,$0D,$10,$19,$40,$2A,$2A
		.BYTE	$C6,$34,$2B,$2B,$35,$0C,$03,$06,$06,$16,$06,$15,$19,$40,$2A,$2A
		.BYTE	$0E,$3D,$2C,$2D,$4D,$3A,$01,$C6,$34,$2B,$2B,$35,$09,$40,$2A,$2A
		.BYTE	$1C,$C5,$C5,$C5,$C5,$0D,$10,$19,$3D,$2D,$2C,$4D,$0F,$40,$2A,$2A
		.BYTE	$06,$16,$06,$06,$06,$16,$15,$19,$09,$09,$09,$09,$09,$40,$2A,$2A
		.BYTE	$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$52,$42,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A,$2A
_l2_r03:
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$D8,$D8,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$0B,$1B,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$09,$09,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$0B,$1B,$40,$2A,$2A,$2A,$2A,$2A,$2A
		.BYTE	$2A,$2A,$2A,$2A,$2A,$2A,$50,$CD,$CD,$40,$2A,$2A,$2A,$2A,$2A,$2A

		SECTION_END	"LVL2 DATA"

		SECTION_START

		FAR_OFS	_lvl3

_lvl3_objects_list:
		CHECKPOINT
; REGION, changed in the EU version
;		OBJ_SET	_scr28_pink_goo,					$F0,$00,$48,$01,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$D8,$00,$48,$01,_NON,_NON,_NON
; -
; REGION, removed in the EU version
		OBJ_SET	_scr28_pink_goo,					$D8,$00,$78,$01,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$D8,$00,$A8,$01,_NON,_NON,_NON
; -
		OBJ_SET	_scr28_pink_goo,					$90,$01,$88,$01,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr28_pink_goo,					$08,$01,$98,$01,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $01
		ROOM	$01
		OBJ_SET	_scr28_pink_goo,					$58,$01,$78,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$D8,$01,$58,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$88,$00,$88,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$58,$00,$58,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$58,$00,$A8,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$A8,$00,$68,$00,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $02
		ROOM	$02
		CHECKPOINT
		OBJ_SET	_scr25_stinging_elephant,			$A8,$02,$80,$00,_NON, $40,_NON
		OBJ_SET	_scr28_pink_goo,					$48,$02,$48,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$98,$02,$C8,$00,_NON,_NON,_NON
		OBJ_SET	_scr25_stinging_elephant,			$48,$02,$A0,$01,_NON, $C0,_NON
		OBJ_SET	_scr25_stinging_elephant,			$70,$02,$60,$01,_NON, $00,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr28_pink_goo,					$A8,$02,$A8,$01,_NON,_NON,_NON
; -
		OBJ_SET	_scr0D_money_bag,					$B0,$02,$B0,$01, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $03
		ROOM	$03
		OBJ_SET	_scr28_pink_goo,					$A8,$02,$68,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr28_pink_goo,					$B8,$02,$98,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr28_pink_goo,					$58,$02,$A8,$02,_NON,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr28_pink_goo,					$38,$03,$A8,$02,_NON,_NON,_NON
		OBJ_SET	_scr26_sword_ninja,					$38,$03,$A8,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr28_pink_goo,					$98,$03,$A8,$02,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$C8,$03,$68,$02,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $04
		ROOM	$04
; REGION, changed in the EU version
;		OBJ_SET	_scr2A_morning_star_troll,			$A0,$03,$48,$00,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$88,$03,$48,$00,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $05
		ROOM	$05
		CHECKPOINT
		OBJ_SET	_scr26_sword_ninja,					$88,$05,$80,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$78,$05,$A8,$01,_NON,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr28_pink_goo,					$88,$05,$88,$00,_NON,_NON,_NON
		OBJ_SET	_scr26_sword_ninja,					$88,$05,$88,$00,_NON,_NON,_NON
; -
		OBJ_SET	_scr0D_money_bag,					$40,$05,$68,$01, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $06
		ROOM	$06
		OBJ_SET	_scr26_sword_ninja,					$90,$05,$A0,$02,_NON,_NON,_NON
		OBJ_SET	_scr25_stinging_elephant,			$60,$05,$60,$02,_NON, $00,_NON
		OBJ_SET	_scr25_stinging_elephant,			$F8,$04,$60,$02,_NON, $00,_NON
		OBJ_SET	_scr25_stinging_elephant,			$98,$04,$60,$02,_NON, $00,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr25_stinging_elephant,			$78,$04,$60,$02,_NON, $00,_NON
		OBJ_SET	_scr26_sword_ninja,					$78,$04,$60,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr25_stinging_elephant,			$42,$04,$60,$02,_NON, $00,_NON
		OBJ_SET	_scr28_pink_goo,					$80,$04,$90,$02,_NON,_NON,_NON
; REGION, added in the EU version
;		OBJ_SET	_scr26_sword_ninja,					$90,$04,$A0,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $07
		ROOM	$07
		OBJ_SET	_scr2A_morning_star_troll,			$60,$04,$48,$00,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$B0,$04,$48,$00,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $08
		ROOM	$08
		CHECKPOINT
		OBJ_SET	_scr27_shuriken_ninja,				$88,$06,$68,$00,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$B0,$06,$10,$01,_NON,_NON,_NON
		OBJ_SET	_scr27_shuriken_ninja,				$40,$06,$C0,$01,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$58,$06,$A0,$01, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $09
		ROOM	$09
; REGION, changed in the EU version
;		OBJ_SET	_scr28_pink_goo,					$88,$06,$A8,$02,_NON,_NON,_NON
		OBJ_SET	_scr27_shuriken_ninja,				$88,$06,$A8,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr28_pink_goo,					$28,$07,$A8,$02,_NON,_NON,_NON
		OBJ_SET	_scr28_pink_goo,					$D8,$06,$B8,$02,_NON,_NON,_NON
; REGION, changed in the EU version
;		OBJ_SET	_scr28_pink_goo,					$A8,$06,$98,$02,_NON,_NON,_NON
;		OBJ_SET	_scr28_pink_goo,					$88,$07,$98,$02,_NON,_NON,_NON
		OBJ_SET	_scr27_shuriken_ninja,				$A8,$06,$98,$02,_NON,_NON,_NON
		OBJ_SET	_scr27_shuriken_ninja,				$88,$07,$98,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr28_pink_goo,					$C8,$07,$B8,$02,_NON,_NON,_NON
		OBJ_SET	_scr27_shuriken_ninja,				$88,$06,$98,$02,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $0A
		ROOM	$0A
		OBJ_SET	_scr23_halloween,					$80,$07,$80,$01,_NON,_NON,_NON
; REGION, added in the EU version
;		OBJ_SET	_scr23_halloween,					$58,$07,$B0,$01,_NON,_NON,_NON
; -
		OBJ_SET	_scr2A_morning_star_troll,			$60,$07,$48,$00,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$78,$07,$98,$00,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$B0,$07,$48,$00,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $0B
		ROOM	$0B
		CHECKPOINT
		OBJ_SET	_scr24_flying_elephant,				$30,$01,$90,$03,_NON, $80,_NON
		OBJ_SET	_scr24_flying_elephant,				$A0,$01,$00,$04,_NON, $00,_NON
		OBJ_SET	_scr24_flying_elephant,				$30,$01,$A0,$04,_NON, $40,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $0C
		ROOM	$0C
		OBJ_SET	_scr24_flying_elephant,				$A0,$00,$68,$05,_NON, $00,_NON
		OBJ_SET	_scr28_pink_goo,					$58,$00,$98,$05,_NON,_NON,_NON
		OBJ_SET	_scr24_flying_elephant,				$30,$01,$A0,$05,_NON, $C0,_NON
		OBJ_SET	_scr24_flying_elephant,				$70,$01,$80,$05,_NON, $40,_NON
		OBJ_SET	_scr24_flying_elephant,				$D0,$00,$30,$05,_NON, $40,_NON
		OBJ_SET	_scr28_pink_goo,					$98,$01,$A8,$05,_NON,_NON,_NON
		OBJ_SET	_scr24_flying_elephant,				$C0,$01,$68,$05,_NON, $C0,_NON
		OBJ_SET	_scr24_flying_elephant,				$50,$00,$B0,$05,_NON, $00,_NON
		OBJ_SET	_scr0D_money_bag,					$B0,$00,$B0,$05, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $0D
		ROOM	$0D
		OBJ_SET	_scr2A_morning_star_troll,			$60,$00,$78,$03,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$B8,$00,$48,$03,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr2A_morning_star_troll,			$88,$00,$48,$03,_NON,_NON,_NON
; -
		OBJ_SET	_scr23_halloween,					$48,$00,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $0E
		ROOM	$0E
		CHECKPOINT
		OBJ_SET	_scr24_flying_elephant,				$40,$02,$30,$03,_NON, $80,_NON
		OBJ_SET	_scr24_flying_elephant,				$60,$02,$C0,$03,_NON, $C0,_NON
		OBJ_SET	_scr24_flying_elephant,				$80,$02,$90,$03,_NON, $00,_NON
		OBJ_SET	_scr28_pink_goo,					$88,$02,$18,$04,_NON,_NON,_NON
		OBJ_SET	_scr24_flying_elephant,				$30,$02,$30,$04,_NON, $40,_NON
		OBJ_SET	_scr24_flying_elephant,				$A0,$02,$A0,$04,_NON, $00,_NON
		OBJ_SET	_scr25_stinging_elephant,			$48,$02,$A0,$04,_NON, $C0,_NON
		OBJ_SET	_scr24_flying_elephant,				$C0,$02,$80,$04,_NON, $40,_NON
		OBJ_SET	_scr0D_money_bag,					$C8,$02,$98,$04, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $0F
		ROOM	$0F
		OBJ_SET	_scr25_stinging_elephant,			$F8,$02,$60,$05,_NON, $00,_NON
		OBJ_SET	_scr25_stinging_elephant,			$98,$02,$60,$05,_NON, $00,_NON
		OBJ_SET	_scr24_flying_elephant,				$80,$03,$90,$05,_NON, $40,_NON
		OBJ_SET	_scr24_flying_elephant,				$00,$03,$50,$05,_NON, $80,_NON
		OBJ_SET	_scr25_stinging_elephant,			$C0,$03,$60,$05,_NON, $00,_NON
		OBJ_SET	_scr25_stinging_elephant,			$60,$03,$60,$05,_NON, $00,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $10
		ROOM	$10
		OBJ_SET	_scr2A_morning_star_troll,			$68,$03,$A8,$03,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$98,$03,$78,$03,_NON,_NON,_NON
		OBJ_SET	_scr2A_morning_star_troll,			$B8,$03,$48,$03,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$58,$03,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$48,$03,$00,$04,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$C0,$03,$C0,$03,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $14
		ROOM	$14
		CHECKPOINT
		OBJ_SET	_scr23_halloween,					$80,$05,$88,$03,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$30,$05,$E0,$03,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$C8,$05,$78,$04,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$30,$05,$A0,$04,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$B0,$05,$90,$03,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $15
		ROOM	$15
		OBJ_SET	_scr23_halloween,					$70,$04,$90,$05,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$A0,$04,$B0,$05,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$E0,$04,$88,$05,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$40,$04,$A8,$05,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$A8,$05,$A8,$05,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$10,$05,$98,$05,_NON,_NON,_NON
		OBJ_SET	_scr23_halloween,					$30,$05,$A8,$05,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $16
		ROOM	$16
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $17
		ROOM	$17
		OBJ_SET	_scr11_lvl2_ghost_nanny,			$80,$00,$80,$02,_NON,_NON,_NON
		OBJ_END

_lvl3_collisions:
		.BYTE	$03,$BE,$EF,$8E,$0F,$8F,$0F,$BF,$0F,$B7,$0B,$B4,$FF,$B5,$FD,$34
		.BYTE	$01,$C0,$03,$00,$00,$C0,$00,$80,$00,$3C,$00,$7C,$03,$FC,$01,$F5
_lvl3_macroA_tbl:
		.BYTE	$00,$04,$14,$15,$15,$12,$34,$14,$10,$24,$40,$05,$15,$15,$49,$4B
		.BYTE	$0C,$0E,$24,$10,$A0,$00,$13,$14,$10,$10,$40,$42,$16,$18,$69,$6B
		.BYTE	$10,$11,$24,$10,$14,$15,$02,$14,$96,$44,$60,$04,$36,$38,$34,$25
		.BYTE	$D8,$04,$24,$10,$15,$14,$15,$6E,$0E,$0E,$2C,$78,$11,$2E,$6A,$4A
		.BYTE	$20,$22,$15,$15,$16,$C8,$08,$5F,$6E,$5C,$04,$04,$11,$3E,$09,$0B
		.BYTE	$20,$22,$10,$71,$36,$E6,$08,$25,$6C,$5F,$04,$3A,$11,$3E,$29,$2B
		.BYTE	$15,$15,$97,$11,$04,$04,$10,$61,$10,$14,$15,$FF,$DD,$24,$10,$CE
		.BYTE	$10,$17,$04,$04,$04,$14,$15,$15,$24,$24,$10,$EE,$DE,$24,$00,$DE
		.BYTE	$10,$37,$04,$C9,$04,$14,$B8,$70,$58,$73,$46,$FF,$EE,$24,$67,$FF
		.BYTE	$63,$57,$04,$04,$14,$96,$14,$10,$88,$89,$15,$A9,$04,$14,$15,$A9
		.BYTE	$FF,$FF,$00,$ED,$ED,$DC,$FF,$ED,$DC,$FF,$F8,$FF,$EC,$00,$F9,$DC
		.BYTE	$00,$00,$EC,$00,$FB,$00,$DC,$00,$00,$EB,$EC,$EC,$FF,$00,$DC,$DC
		.BYTE	$EC,$DC,$DB,$DB,$FD,$CC,$00,$EC,$00,$00,$ED,$FF,$00,$F8,$00,$EC
		.BYTE	$CB,$00,$00,$00,$DC,$CA,$EB,$DC,$00,$A8,$88,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl3_macroB_tbl:
		.BYTE	$00,$04,$24,$65,$00,$10,$35,$00,$00,$14,$50,$03,$06,$08,$59,$5B
		.BYTE	$1C,$1E,$24,$10,$A0,$04,$04,$24,$10,$87,$50,$52,$26,$28,$79,$7B
		.BYTE	$10,$11,$14,$15,$24,$10,$02,$24,$10,$00,$70,$04,$00,$00,$25,$35
		.BYTE	$04,$04,$14,$10,$06,$14,$08,$7E,$1E,$1E,$3C,$76,$11,$3E,$7A,$5A
		.BYTE	$30,$32,$65,$61,$26,$54,$08,$5E,$7E,$6C,$04,$0A,$11,$3E,$19,$1B
		.BYTE	$30,$32,$10,$00,$00,$F6,$15,$25,$7C,$5E,$04,$13,$11,$4E,$39,$3B
		.BYTE	$65,$07,$11,$B8,$D8,$04,$10,$71,$87,$10,$08,$CE,$CE,$24,$47,$DE
		.BYTE	$10,$27,$04,$F6,$5E,$14,$11,$60,$24,$63,$56,$FF,$DE,$24,$00,$EE
		.BYTE	$10,$00,$5E,$04,$04,$14,$00,$00,$58,$24,$10,$FF,$CD,$24,$10,$FF
		.BYTE	$04,$04,$73,$66,$00,$00,$00,$56,$00,$00,$00,$00,$04,$00,$65,$06
		.BYTE	$EC,$ED,$ED,$FF,$FF,$CC,$FF,$FD,$DC,$F9,$00,$FF,$F8,$FB,$DC,$00
		.BYTE	$EA,$00,$ED,$00,$00,$EC,$00,$00,$ED,$FD,$CC,$FF,$FD,$FF,$DC,$EC
		.BYTE	$DA,$DB,$DC,$00,$DB,$ED,$00,$EC,$00,$00,$FB,$FB,$ED,$EC,$00,$00
		.BYTE	$00,$FD,$DC,$00,$DA,$DC,$ED,$CB,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl3_macroC_tbl:
		.BYTE	$00,$04,$15,$15,$15,$11,$04,$10,$11,$10,$41,$43,$15,$15,$4A,$04
		.BYTE	$0D,$0F,$10,$11,$A0,$00,$13,$10,$11,$11,$41,$43,$17,$00,$6A,$04
		.BYTE	$10,$11,$10,$11,$15,$15,$02,$96,$97,$45,$62,$13,$37,$00,$04,$04
		.BYTE	$04,$04,$10,$11,$15,$15,$04,$6F,$0F,$2C,$0F,$4C,$2D,$2F,$6A,$4A
		.BYTE	$21,$23,$15,$15,$17,$C9,$04,$6F,$6F,$5D,$04,$04,$3D,$3F,$0A,$04
		.BYTE	$21,$23,$70,$72,$37,$E7,$04,$04,$5E,$6F,$39,$3B,$3D,$3F,$2A,$04
		.BYTE	$15,$15,$97,$11,$04,$04,$60,$62,$70,$15,$15,$FF,$FF,$10,$11,$CF
		.BYTE	$16,$18,$04,$04,$04,$96,$15,$15,$0F,$10,$11,$EF,$DF,$00,$58,$DF
		.BYTE	$36,$38,$04,$04,$78,$10,$B8,$72,$08,$46,$66,$FF,$EF,$67,$68,$FF
		.BYTE	$57,$57,$04,$04,$96,$97,$15,$36,$88,$04,$A8,$15,$A9,$A8,$A8,$15
		.BYTE	$ED,$EC,$E9,$ED,$FB,$FF,$FD,$FB,$FF,$00,$F9,$EC,$FF,$F8,$DC,$ED
		.BYTE	$FB,$00,$DC,$F9,$EC,$00,$00,$00,$EB,$00,$FF,$EB,$EC,$00,$00,$FA
		.BYTE	$EC,$FD,$ED,$FD,$00,$E9,$DC,$00,$FD,$00,$EB,$00,$FB,$00,$D9,$00
		.BYTE	$ED,$DC,$00,$ED,$FD,$CB,$DC,$DC,$00,$88,$89,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl3_macroD_tbl:
		.BYTE	$00,$04,$64,$75,$00,$11,$04,$00,$00,$87,$51,$53,$07,$00,$5A,$04
		.BYTE	$1D,$1F,$10,$11,$A0,$04,$04,$10,$11,$B8,$51,$53,$27,$00,$7A,$04
		.BYTE	$10,$11,$15,$15,$10,$11,$02,$10,$11,$00,$72,$04,$00,$00,$04,$04
		.BYTE	$04,$D8,$10,$11,$07,$64,$04,$7F,$1F,$3C,$1F,$77,$3D,$3F,$7A,$5A
		.BYTE	$31,$33,$60,$62,$27,$55,$04,$7F,$7F,$6D,$09,$0B,$3D,$3F,$1A,$04
		.BYTE	$31,$33,$74,$00,$00,$F7,$04,$04,$7D,$7F,$04,$13,$4D,$4F,$3A,$04
		.BYTE	$06,$08,$11,$B8,$04,$E7,$70,$72,$B8,$58,$00,$CF,$CF,$47,$48,$DF
		.BYTE	$26,$28,$55,$04,$04,$10,$11,$62,$1F,$56,$57,$FF,$DF,$00,$58,$EF
		.BYTE	$75,$00,$04,$04,$04,$87,$00,$00,$08,$10,$11,$FF,$FF,$10,$11,$FF
		.BYTE	$04,$13,$66,$66,$00,$00,$00,$75,$00,$04,$00,$00,$00,$00,$75,$07
		.BYTE	$EC,$FF,$EB,$FF,$FB,$FF,$FD,$FB,$EC,$FB,$EC,$FF,$F9,$EC,$EC,$DA
		.BYTE	$EB,$EC,$00,$00,$00,$00,$00,$EA,$FB,$00,$FF,$FD,$FF,$DC,$DC,$EC
		.BYTE	$DB,$EC,$EC,$DA,$00,$EB,$00,$EB,$00,$F9,$FD,$00,$EB,$FF,$EA,$00
		.BYTE	$EB,$CB,$CB,$ED,$EC,$EC,$CA,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl3_attrs_tbl:
		.BYTE	$00,$02,$00,$00,$00,$00,$01,$00,$00,$00,$02,$02,$00,$00,$02,$02
		.BYTE	$03,$01,$00,$00,$00,$02,$02,$00,$00,$00,$02,$02,$00,$00,$02,$02
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$02,$00,$00,$01,$01
		.BYTE	$02,$02,$00,$00,$00,$00,$02,$01,$01,$02,$02,$02,$00,$00,$02,$02
		.BYTE	$02,$02,$00,$00,$00,$02,$02,$01,$01,$01,$02,$02,$00,$00,$02,$02
		.BYTE	$02,$02,$00,$00,$00,$02,$02,$01,$01,$01,$02,$02,$00,$00,$02,$02
		.BYTE	$00,$00,$00,$00,$02,$02,$00,$00,$00,$00,$00,$02,$02,$00,$00,$02
		.BYTE	$00,$00,$02,$02,$01,$00,$00,$00,$02,$00,$00,$02,$02,$00,$00,$02
		.BYTE	$03,$00,$01,$02,$02,$00,$00,$00,$00,$00,$00,$02,$02,$00,$00,$02
		.BYTE	$01,$01,$01,$01,$00,$00,$00,$00,$00,$01,$00,$00,$01,$00,$00,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl3_rooms_lib:
		.WORD	_l3_r00,_l3_r10,_l3_r20,_l3_r03,_l3_r03,_l3_r13,_l3_r20,_l3_r03
		.WORD	_l3_r01,_l3_r11,_l3_r21,_l3_r31,_l3_r04,_l3_r14,_l3_r21,_l3_r31
		.WORD	_l3_r02,      0,_l3_r05,_l3_r15,_l3_r25,_l3_r35,_l3_r05,_l3_r15
		.WORD	_l3_r03,_l3_r13,_l3_r20,_l3_r03,_l3_r43,_l3_r53,      0,      0
		.WORD	_l3_r04,_l3_r14,_l3_r21,_l3_r31,_l3_r44,_l3_r54,      0,      0
		.WORD	_l3_r05,_l3_r15,_l3_r25,_l3_r35,_l3_r05,_l3_r15,      0,      0
_l3_r43:
		.BYTE	$00,$96,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$8F
		.BYTE	$00,$35,$0A,$1A,$27,$02,$12,$12,$6D,$7D,$8D,$12,$12,$12,$02,$12
		.BYTE	$00,$03,$0B,$1B,$28,$60,$70,$80,$6E,$7E,$8E,$13,$13,$13,$03,$10
		.BYTE	$00,$04,$01,$01,$01,$61,$71,$81,$01,$01,$01,$01,$01,$01,$04,$11
		.BYTE	$00,$04,$01,$01,$1E,$04,$01,$01,$01,$01,$01,$01,$4A,$20,$04,$01
		.BYTE	$00,$04,$01,$01,$3E,$04,$01,$45,$01,$01,$01,$01,$4B,$20,$04,$01
		.BYTE	$00,$04,$01,$01,$3E,$04,$01,$0E,$01,$1E,$01,$01,$01,$2E,$04,$01
		.BYTE	$00,$04,$01,$01,$1F,$04,$01,$3F,$01,$3E,$01,$01,$01,$01,$04,$01
		.BYTE	$00,$04,$01,$01,$01,$04,$01,$0F,$01,$1F,$01,$01,$4A,$20,$04,$01
		.BYTE	$00,$04,$01,$01,$1E,$04,$01,$45,$01,$01,$01,$01,$4B,$20,$04,$01
		.BYTE	$00,$04,$01,$01,$3E,$04,$01,$01,$01,$01,$01,$01,$01,$2E,$04,$01
		.BYTE	$00,$04,$01,$01,$3E,$02,$12,$12,$12,$09,$01,$01,$27,$12,$96,$01
		.BYTE	$00,$04,$01,$01,$1F,$03,$13,$13,$13,$19,$01,$01,$28,$13,$04,$82
		.BYTE	$00,$04,$01,$01,$01,$04,$37,$0E,$01,$01,$01,$01,$01,$01,$04,$01
		.BYTE	$00,$04,$01,$01,$1E,$04,$38,$3F,$01,$01,$01,$01,$01,$37,$04,$01
_l3_r53:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$12,$02,$12,$12,$12,$12,$09,$40,$50,$27,$12,$12,$12,$12,$96,$00
		.BYTE	$13,$03,$10,$13,$13,$13,$19,$41,$51,$28,$13,$13,$13,$13,$04,$00
		.BYTE	$01,$04,$11,$01,$01,$01,$01,$01,$01,$01,$48,$58,$74,$1E,$04,$00
		.BYTE	$20,$04,$01,$01,$01,$39,$3B,$01,$01,$01,$01,$39,$01,$3E,$04,$00
		.BYTE	$20,$04,$01,$45,$01,$3A,$01,$01,$01,$01,$01,$3A,$01,$3E,$04,$00
		.BYTE	$2E,$04,$01,$01,$02,$12,$12,$12,$12,$12,$12,$12,$12,$12,$96,$00
		.BYTE	$01,$04,$01,$01,$60,$70,$80,$13,$13,$13,$13,$13,$13,$13,$04,$00
		.BYTE	$20,$04,$01,$01,$61,$71,$81,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$20,$04,$01,$01,$04,$01,$01,$01,$01,$01,$01,$01,$01,$37,$04,$00
		.BYTE	$2E,$04,$01,$01,$02,$09,$40,$50,$96,$01,$01,$01,$17,$12,$96,$00
		.BYTE	$12,$96,$01,$01,$42,$68,$41,$51,$04,$01,$01,$01,$05,$62,$04,$00
		.BYTE	$13,$04,$82,$01,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$00
		.BYTE	$01,$04,$01,$01,$17,$12,$12,$12,$17,$09,$0A,$1A,$27,$12,$96,$00
		.BYTE	$37,$04,$01,$01,$18,$13,$13,$13,$18,$19,$0B,$1B,$28,$13,$04,$00
_l3_r44:
		.BYTE	$00,$04,$01,$01,$3E,$04,$01,$0F,$01,$01,$01,$01,$01,$38,$04,$01
		.BYTE	$00,$04,$01,$01,$3E,$04,$01,$01,$01,$4A,$20,$20,$5A,$01,$04,$01
		.BYTE	$00,$04,$01,$01,$1F,$04,$01,$45,$01,$4B,$20,$20,$5B,$01,$04,$01
		.BYTE	$00,$04,$30,$01,$01,$04,$37,$01,$01,$01,$2E,$2F,$01,$37,$04,$01
		.BYTE	$00,$04,$01,$01,$1E,$04,$38,$01,$01,$01,$01,$01,$01,$38,$02,$12
		.BYTE	$00,$04,$01,$01,$3E,$04,$01,$01,$01,$3B,$01,$01,$01,$01,$03,$13
		.BYTE	$00,$04,$01,$01,$3E,$02,$09,$01,$01,$02,$40,$50,$27,$12,$96,$01
		.BYTE	$00,$04,$01,$01,$1F,$76,$86,$16,$01,$03,$41,$51,$28,$66,$02,$09
		.BYTE	$00,$04,$01,$01,$37,$77,$87,$01,$01,$04,$26,$26,$26,$67,$03,$19
		.BYTE	$00,$04,$01,$01,$38,$17,$09,$0A,$1A,$27,$17,$12,$12,$12,$96,$01
		.BYTE	$00,$04,$01,$01,$01,$18,$19,$0B,$1B,$28,$13,$13,$13,$13,$04,$01
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$73,$01,$01,$01,$01,$01,$34,$44
		.BYTE	$00,$35,$0A,$1A,$27,$12,$12,$12,$12,$12,$12,$12,$12,$12,$17,$12
		.BYTE	$00,$03,$0B,$1B,$28,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
_l3_r54:
		.BYTE	$38,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$01,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$72,$01,$01,$04,$00
		.BYTE	$01,$04,$01,$01,$83,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$37,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$38,$02,$12,$12,$12,$02,$09,$0A,$1A,$27,$12,$96,$01,$01,$04,$00
		.BYTE	$01,$42,$52,$13,$13,$03,$19,$0B,$1B,$28,$62,$04,$01,$01,$04,$00
		.BYTE	$12,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$01,$01,$04,$00
		.BYTE	$66,$02,$09,$40,$50,$94,$01,$01,$17,$12,$12,$96,$01,$01,$04,$00
		.BYTE	$67,$03,$19,$41,$51,$95,$83,$01,$05,$13,$13,$04,$01,$01,$04,$00
		.BYTE	$12,$04,$01,$01,$55,$01,$01,$01,$01,$01,$01,$04,$01,$01,$04,$00
		.BYTE	$13,$04,$01,$01,$01,$01,$01,$31,$01,$01,$01,$04,$01,$01,$04,$00
		.BYTE	$01,$34,$44,$54,$01,$01,$01,$3B,$01,$4A,$20,$04,$01,$01,$04,$00
		.BYTE	$12,$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$85,$0A,$1A,$96,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$19,$0B,$1B,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
_l3_r03:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$02,$12,$12,$12,$12,$09,$40,$50,$27,$12,$12,$12,$12,$96,$00
		.BYTE	$00,$03,$10,$10,$13,$13,$19,$41,$51,$28,$13,$13,$10,$10,$04,$00
		.BYTE	$00,$04,$11,$11,$01,$01,$82,$01,$01,$01,$48,$58,$11,$11,$04,$00
		.BYTE	$00,$04,$0E,$49,$59,$01,$01,$01,$01,$01,$01,$01,$01,$1E,$04,$00
		.BYTE	$00,$04,$3F,$01,$82,$01,$01,$82,$01,$01,$01,$01,$01,$3E,$04,$00
		.BYTE	$00,$04,$0F,$45,$01,$01,$64,$30,$01,$01,$65,$01,$01,$1F,$04,$00
		.BYTE	$00,$04,$0E,$48,$58,$01,$01,$01,$01,$01,$49,$59,$55,$1E,$04,$00
		.BYTE	$00,$04,$3F,$01,$65,$3B,$73,$01,$01,$01,$65,$45,$01,$3E,$04,$00
		.BYTE	$00,$04,$3F,$01,$84,$01,$01,$01,$01,$01,$01,$01,$83,$3E,$04,$00
		.BYTE	$00,$04,$0F,$01,$01,$01,$01,$01,$84,$01,$01,$01,$01,$1F,$04,$00
		.BYTE	$00,$04,$0E,$01,$01,$01,$01,$01,$01,$01,$72,$01,$01,$1E,$04,$00
		.BYTE	$00,$04,$3F,$01,$01,$01,$83,$01,$01,$01,$01,$01,$01,$3E,$04,$00
		.BYTE	$00,$04,$3F,$01,$01,$01,$01,$31,$01,$01,$01,$01,$01,$3E,$04,$00
		.BYTE	$00,$04,$0F,$01,$01,$01,$01,$01,$01,$01,$65,$01,$01,$1F,$04,$00
_l3_r13:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$02,$12,$12,$12,$12,$09,$40,$50,$27,$12,$12,$12,$12,$96,$00
		.BYTE	$00,$03,$10,$13,$13,$13,$19,$41,$51,$28,$13,$13,$13,$13,$04,$00
		.BYTE	$00,$04,$11,$01,$01,$01,$01,$01,$01,$01,$48,$58,$74,$1E,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$39,$3B,$01,$01,$01,$01,$39,$01,$3E,$04,$00
		.BYTE	$00,$04,$01,$45,$01,$3A,$01,$01,$01,$01,$01,$3A,$01,$3E,$04,$00
		.BYTE	$00,$04,$01,$01,$02,$12,$12,$12,$12,$12,$12,$12,$12,$12,$96,$00
		.BYTE	$00,$04,$01,$01,$60,$70,$80,$13,$13,$13,$13,$13,$13,$13,$04,$00
		.BYTE	$00,$04,$01,$01,$61,$71,$81,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$04,$01,$01,$01,$01,$01,$01,$01,$01,$37,$04,$00
		.BYTE	$00,$04,$01,$01,$02,$09,$40,$50,$96,$01,$01,$01,$17,$12,$96,$00
		.BYTE	$00,$04,$01,$01,$42,$68,$41,$51,$04,$01,$01,$01,$05,$62,$04,$00
		.BYTE	$00,$04,$82,$01,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$00
		.BYTE	$00,$04,$01,$01,$17,$12,$12,$12,$17,$09,$0A,$1A,$27,$12,$96,$00
		.BYTE	$00,$04,$01,$01,$18,$13,$13,$13,$18,$19,$0B,$1B,$28,$13,$04,$00
_l3_r04:
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$31,$01,$01,$01,$01,$01,$01,$83,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$02,$12,$12,$12,$02,$09,$0A,$1A,$27,$12,$96,$00
		.BYTE	$00,$04,$01,$01,$42,$52,$13,$13,$03,$19,$0B,$1B,$28,$62,$04,$00
		.BYTE	$00,$04,$01,$01,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$00
		.BYTE	$00,$04,$31,$01,$02,$09,$40,$50,$94,$01,$45,$01,$17,$12,$96,$00
		.BYTE	$00,$04,$01,$01,$03,$19,$41,$51,$95,$01,$65,$01,$05,$10,$04,$00
		.BYTE	$00,$04,$01,$01,$04,$01,$01,$64,$01,$01,$01,$01,$01,$11,$04,$00
		.BYTE	$00,$04,$01,$01,$04,$01,$01,$01,$01,$55,$01,$45,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$34,$44,$54,$01,$01,$64,$01,$0E,$20,$1E,$04,$00
		.BYTE	$00,$35,$0A,$1A,$27,$12,$12,$12,$12,$12,$12,$12,$12,$12,$17,$12
		.BYTE	$00,$03,$0B,$1B,$28,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
_l3_r14:
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$72,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$83,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$02,$12,$12,$12,$02,$09,$0A,$1A,$27,$12,$96,$01,$01,$04,$00
		.BYTE	$00,$42,$52,$13,$13,$03,$19,$0B,$1B,$28,$62,$04,$01,$01,$04,$00
		.BYTE	$00,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$01,$01,$04,$00
		.BYTE	$00,$02,$09,$40,$50,$94,$01,$01,$17,$12,$12,$04,$01,$01,$04,$00
		.BYTE	$00,$03,$19,$41,$51,$95,$83,$01,$05,$13,$13,$04,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$55,$01,$01,$01,$01,$01,$01,$04,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$31,$01,$01,$01,$04,$01,$01,$04,$00
		.BYTE	$00,$34,$44,$54,$01,$01,$01,$3B,$01,$4A,$20,$04,$01,$01,$04,$00
		.BYTE	$12,$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$85,$0A,$1A,$96,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$19,$0B,$1B,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
_l3_r05:
		.BYTE	$00,$04,$01,$01,$34,$44,$54,$01,$01,$64,$01,$01,$0E,$20,$1E,$34
		.BYTE	$00,$35,$0A,$1A,$27,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$17
		.BYTE	$00,$03,$0B,$1B,$28,$05,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$02,$12,$12,$12,$02,$12,$12,$12,$02,$09,$0A,$1A,$27,$12,$12
		.BYTE	$00,$42,$52,$13,$13,$76,$86,$13,$13,$03,$19,$0B,$1B,$28,$05,$13
		.BYTE	$00,$43,$53,$26,$26,$77,$87,$45,$01,$04,$30,$01,$01,$01,$01,$3B
		.BYTE	$00,$02,$09,$40,$50,$27,$09,$01,$01,$94,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$03,$19,$41,$51,$28,$19,$2B,$01,$95,$01,$01,$01,$64,$01,$01
		.BYTE	$00,$04,$01,$01,$64,$01,$01,$01,$01,$01,$01,$73,$01,$01,$01,$01
		.BYTE	$00,$04,$3B,$01,$01,$01,$01,$73,$01,$37,$01,$01,$01,$0E,$20,$1E
		.BYTE	$00,$34,$44,$54,$01,$01,$01,$01,$01,$11,$01,$01,$01,$3F,$20,$3E
		.BYTE	$00,$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
		.BYTE	$00,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l3_r15:
		.BYTE	$44,$54,$48,$01,$01,$01,$01,$01,$01,$06,$3E,$04,$01,$01,$04,$00
		.BYTE	$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$85,$0A,$1A,$96,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$05,$19,$0B,$1B,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$02,$12,$12,$09,$0A,$1A,$27,$02,$12,$12,$02,$12,$12,$12,$96,$00
		.BYTE	$03,$13,$05,$19,$0B,$1B,$28,$03,$13,$62,$03,$13,$13,$66,$04,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$31,$04,$01,$2A,$04,$26,$26,$67,$04,$00
		.BYTE	$04,$72,$01,$01,$01,$01,$01,$07,$01,$27,$85,$40,$50,$27,$96,$00
		.BYTE	$04,$01,$01,$64,$01,$01,$01,$08,$01,$28,$19,$41,$51,$28,$04,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$73,$01,$01,$01,$01,$01,$83,$01,$04,$00
		.BYTE	$34,$44,$54,$01,$74,$01,$01,$01,$01,$01,$01,$01,$01,$55,$04,$00
		.BYTE	$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$07,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$08,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l3_r20:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$02,$12,$12,$12,$12,$09,$40,$50,$27,$12,$12,$12,$12,$96,$00
		.BYTE	$00,$03,$10,$13,$13,$13,$19,$41,$51,$28,$13,$13,$13,$13,$04,$00
		.BYTE	$00,$04,$11,$01,$82,$59,$01,$01,$01,$01,$01,$01,$01,$1E,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$39,$3B,$01,$01,$01,$39,$01,$01,$3E,$04,$00
		.BYTE	$00,$04,$01,$45,$01,$3A,$01,$01,$01,$01,$3A,$01,$01,$1F,$04,$00
		.BYTE	$00,$02,$12,$79,$01,$01,$89,$12,$12,$12,$12,$9D,$83,$01,$04,$00
		.BYTE	$00,$60,$70,$97,$01,$01,$8A,$13,$13,$13,$13,$98,$01,$65,$04,$00
		.BYTE	$00,$61,$71,$81,$01,$01,$01,$01,$01,$01,$01,$99,$01,$55,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$37,$9B,$01,$01,$04,$00
		.BYTE	$00,$02,$09,$40,$50,$96,$01,$01,$01,$17,$12,$96,$01,$01,$04,$00
		.BYTE	$00,$42,$68,$41,$51,$04,$01,$01,$01,$05,$62,$04,$01,$73,$04,$00
		.BYTE	$00,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$01,$01,$04,$00
		.BYTE	$00,$02,$79,$26,$89,$17,$09,$0A,$1A,$27,$12,$96,$01,$01,$04,$00
		.BYTE	$00,$03,$7A,$26,$8A,$18,$19,$0B,$1B,$28,$13,$04,$01,$01,$04,$00
_l3_r21:
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$83,$01,$01,$01,$01,$01,$01,$31,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$02,$12,$79,$92,$02,$09,$0A,$1A,$27,$12,$96,$00
		.BYTE	$00,$04,$01,$01,$42,$52,$7A,$93,$03,$19,$0B,$1B,$28,$62,$04,$00
		.BYTE	$00,$04,$01,$01,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$00
		.BYTE	$00,$04,$01,$01,$02,$09,$40,$50,$94,$01,$01,$01,$17,$12,$96,$00
		.BYTE	$00,$04,$64,$01,$9E,$19,$41,$51,$95,$01,$01,$01,$05,$13,$04,$00
		.BYTE	$00,$04,$01,$01,$98,$01,$45,$01,$01,$01,$01,$01,$01,$1E,$04,$00
		.BYTE	$00,$04,$45,$01,$99,$01,$01,$01,$3B,$65,$01,$01,$20,$3E,$04,$00
		.BYTE	$00,$04,$01,$01,$9F,$44,$54,$48,$01,$01,$01,$01,$06,$3E,$04,$00
		.BYTE	$00,$35,$0A,$1A,$27,$12,$12,$12,$12,$12,$12,$12,$12,$12,$17,$12
		.BYTE	$00,$03,$0B,$1B,$28,$13,$13,$13,$13,$13,$13,$13,$13,$13,$18,$13
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
_l3_r31:
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$83,$01,$01,$01,$01,$01,$01,$31,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$00,$02,$12,$12,$12,$02,$09,$0A,$1A,$27,$12,$96,$01,$01,$04,$00
		.BYTE	$00,$42,$52,$13,$13,$03,$19,$0B,$1B,$28,$62,$04,$01,$01,$04,$00
		.BYTE	$00,$43,$53,$26,$26,$04,$01,$01,$01,$01,$2A,$04,$01,$01,$04,$00
		.BYTE	$00,$02,$09,$40,$50,$94,$01,$01,$01,$01,$17,$96,$01,$01,$04,$00
		.BYTE	$00,$03,$19,$41,$51,$95,$01,$01,$01,$01,$10,$9A,$01,$01,$04,$00
		.BYTE	$00,$04,$45,$01,$64,$01,$01,$01,$01,$01,$11,$98,$01,$01,$04,$00
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$45,$01,$01,$99,$01,$01,$04,$00
		.BYTE	$00,$34,$44,$54,$55,$01,$01,$01,$0E,$20,$1E,$9B,$01,$01,$04,$00
		.BYTE	$12,$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$85,$0A,$1A,$96,$00
		.BYTE	$13,$18,$13,$13,$13,$13,$13,$13,$13,$13,$13,$19,$0B,$1B,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
_l3_r25:
		.BYTE	$00,$04,$01,$01,$34,$44,$54,$48,$01,$01,$01,$01,$06,$01,$01,$34
		.BYTE	$00,$35,$0A,$1A,$27,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$17
		.BYTE	$00,$03,$0B,$1B,$28,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$02,$12,$79,$92,$02,$12,$90,$02,$90,$89,$09,$0A,$1A,$27,$90
		.BYTE	$00,$42,$52,$7A,$93,$76,$86,$91,$03,$91,$8A,$19,$0B,$1B,$28,$91
		.BYTE	$00,$43,$53,$26,$26,$77,$87,$45,$04,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$02,$09,$40,$50,$27,$09,$01,$94,$01,$73,$01,$01,$01,$01,$01
		.BYTE	$00,$03,$19,$41,$51,$28,$19,$2B,$95,$01,$01,$01,$01,$64,$01,$01
		.BYTE	$00,$04,$01,$01,$64,$01,$01,$01,$01,$30,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$0C,$1C,$2C,$01,$01,$01,$01,$72,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$34,$44,$54,$01,$3B,$01,$0E,$01,$1E,$01,$01,$01,$01,$01,$31
		.BYTE	$00,$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12
		.BYTE	$00,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l3_r35:
		.BYTE	$44,$54,$01,$01,$01,$01,$64,$01,$0E,$20,$1E,$04,$01,$01,$04,$00
		.BYTE	$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$85,$0A,$1A,$96,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$19,$0B,$1B,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$02,$09,$0A,$1A,$27,$79,$92,$02,$12,$12,$02,$79,$92,$12,$96,$00
		.BYTE	$03,$19,$0B,$1B,$28,$7A,$93,$03,$13,$62,$03,$7A,$93,$66,$04,$00
		.BYTE	$04,$4E,$01,$01,$20,$01,$01,$04,$01,$2A,$04,$26,$26,$67,$04,$00
		.BYTE	$04,$4F,$01,$01,$06,$01,$73,$07,$01,$89,$85,$40,$50,$27,$96,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$01,$08,$01,$8A,$19,$41,$51,$28,$04,$00
		.BYTE	$04,$01,$72,$01,$01,$01,$01,$83,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$83,$55,$04,$00
		.BYTE	$34,$44,$54,$01,$73,$01,$01,$01,$01,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$07,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$08,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l3_r00:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$02,$12,$12,$12,$12,$09,$40,$50,$27,$12,$12,$12,$12,$12,$12
		.BYTE	$00,$03,$10,$10,$13,$13,$19,$41,$51,$28,$13,$13,$10,$10,$13,$10
		.BYTE	$00,$04,$11,$11,$01,$01,$82,$01,$01,$01,$48,$58,$11,$11,$01,$11
		.BYTE	$00,$04,$0E,$49,$59,$01,$01,$01,$01,$01,$01,$01,$01,$01,$55,$1E
		.BYTE	$00,$04,$3F,$01,$82,$01,$01,$82,$01,$01,$01,$01,$01,$01,$01,$3E
		.BYTE	$00,$04,$0F,$01,$01,$01,$64,$30,$01,$01,$65,$01,$01,$01,$01,$1F
		.BYTE	$00,$04,$0E,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$1E
		.BYTE	$00,$04,$3F,$01,$01,$01,$73,$01,$01,$01,$01,$01,$01,$01,$01,$3E
		.BYTE	$00,$04,$0F,$01,$84,$01,$01,$01,$01,$01,$01,$01,$83,$01,$01,$1F
		.BYTE	$00,$04,$0E,$01,$01,$01,$01,$01,$55,$01,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$04,$3F,$45,$01,$01,$01,$45,$01,$48,$58,$01,$01,$01,$01,$01
		.BYTE	$00,$02,$12,$12,$12,$12,$09,$0A,$1A,$27,$12,$12,$12,$12,$12,$12
		.BYTE	$00,$03,$13,$13,$13,$13,$19,$0B,$1B,$28,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$04,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01
_l3_r10:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$02,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$96,$00
		.BYTE	$03,$13,$3C,$4C,$4C,$4C,$5C,$13,$10,$13,$3C,$4C,$5C,$13,$04,$00
		.BYTE	$04,$01,$3D,$4D,$4D,$4D,$5D,$01,$11,$01,$3D,$4D,$5D,$01,$04,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$2A,$21,$20,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$04,$01,$20,$20,$20,$20,$20,$20,$20,$01,$01,$45,$01,$48,$04,$00
		.BYTE	$04,$73,$36,$46,$46,$46,$46,$46,$56,$65,$01,$01,$01,$3B,$04,$00
		.BYTE	$04,$01,$01,$01,$01,$01,$01,$01,$64,$01,$01,$01,$01,$01,$04,$00
		.BYTE	$07,$01,$4E,$20,$3B,$49,$59,$01,$01,$01,$01,$4E,$20,$5E,$04,$00
		.BYTE	$08,$01,$4F,$06,$01,$01,$64,$01,$01,$48,$58,$4F,$06,$5F,$04,$00
		.BYTE	$01,$01,$4E,$20,$5E,$37,$01,$01,$73,$01,$37,$55,$20,$5E,$04,$00
		.BYTE	$01,$01,$4F,$06,$5F,$38,$01,$01,$01,$01,$38,$01,$06,$5F,$04,$00
		.BYTE	$17,$12,$02,$12,$12,$12,$09,$0A,$1A,$27,$12,$12,$12,$12,$96,$00
		.BYTE	$13,$10,$07,$3C,$4C,$5C,$19,$0B,$1B,$28,$3C,$5C,$10,$13,$04,$00
		.BYTE	$01,$11,$08,$3D,$4D,$5D,$01,$01,$01,$01,$3D,$5D,$11,$01,$04,$00
_l3_r01:
		.BYTE	$00,$04,$3F,$45,$01,$01,$01,$45,$01,$48,$58,$01,$01,$01,$01,$01
		.BYTE	$00,$02,$12,$12,$12,$12,$09,$0A,$1A,$27,$12,$12,$12,$12,$12,$12
		.BYTE	$00,$03,$13,$13,$13,$10,$19,$0B,$1B,$28,$13,$13,$13,$13,$13,$13
		.BYTE	$00,$04,$01,$01,$01,$11,$01,$49,$59,$01,$48,$58,$01,$01,$01,$01
		.BYTE	$00,$04,$0E,$20,$1E,$01,$39,$01,$01,$39,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$04,$0F,$78,$1F,$01,$3A,$45,$01,$3A,$01,$01,$01,$01,$01,$01
		.BYTE	$00,$04,$01,$01,$01,$37,$01,$01,$01,$01,$01,$01,$01,$01,$01,$20
		.BYTE	$00,$04,$0E,$20,$1E,$38,$39,$01,$01,$39,$01,$01,$01,$01,$01,$20
		.BYTE	$00,$04,$0F,$78,$1F,$01,$3A,$01,$01,$3A,$01,$01,$01,$01,$01,$20
		.BYTE	$00,$04,$01,$01,$01,$37,$47,$01,$01,$47,$01,$01,$01,$01,$01,$20
		.BYTE	$00,$04,$0E,$20,$1E,$38,$47,$01,$01,$47,$01,$01,$01,$01,$01,$69
		.BYTE	$00,$04,$0F,$78,$1F,$01,$38,$01,$01,$38,$01,$01,$01,$01,$01,$6A
		.BYTE	$00,$17,$12,$12,$12,$12,$09,$40,$50,$27,$12,$12,$12,$12,$12,$17
		.BYTE	$00,$18,$13,$13,$13,$13,$19,$41,$51,$28,$13,$13,$13,$13,$13,$33
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l3_r11:
		.BYTE	$01,$01,$4F,$06,$5F,$38,$01,$01,$01,$01,$38,$01,$06,$5F,$04,$00
		.BYTE	$12,$12,$02,$12,$12,$12,$09,$0A,$1A,$27,$12,$12,$12,$12,$96,$00
		.BYTE	$13,$10,$07,$3C,$4C,$5C,$19,$0B,$1B,$28,$3C,$5C,$10,$62,$04,$00
		.BYTE	$01,$11,$08,$3D,$4D,$5D,$01,$01,$01,$01,$3D,$5D,$11,$62,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$73,$01,$01,$72,$01,$01,$01,$62,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$20,$20,$01,$88,$04,$00
		.BYTE	$20,$20,$02,$12,$09,$01,$20,$20,$01,$45,$20,$20,$01,$01,$04,$00
		.BYTE	$88,$88,$07,$3C,$5C,$01,$88,$20,$84,$01,$88,$88,$01,$01,$04,$00
		.BYTE	$01,$01,$08,$3D,$5D,$01,$4E,$20,$01,$01,$01,$01,$01,$55,$04,$00
		.BYTE	$01,$01,$01,$01,$01,$01,$4F,$20,$01,$01,$20,$20,$01,$01,$04,$00
		.BYTE	$5E,$01,$01,$4A,$20,$5A,$4E,$20,$01,$64,$88,$88,$01,$62,$04,$00
		.BYTE	$5F,$01,$96,$4B,$20,$5B,$4F,$88,$3B,$01,$01,$01,$01,$62,$04,$00
		.BYTE	$12,$12,$17,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$12,$07,$00
		.BYTE	$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$13,$08,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l3_r02:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$B1,$A3,$00,$00,$00,$A1,$00,$00,$00
		.BYTE	$A0,$00,$C6,$B1,$C9,$B1,$BB,$B1,$00,$CC,$B1,$C7,$D3,$A0,$A1,$A8
		.BYTE	$00,$A5,$00,$00,$00,$B6,$00,$D4,$A3,$00,$00,$D2,$A1,$00,$B5,$00
		.BYTE	$A0,$B8,$AB,$AC,$B7,$B1,$BB,$B1,$B7,$CC,$B1,$C7,$D3,$A0,$B6,$A0
		.BYTE	$00,$00,$00,$B2,$00,$00,$A1,$BF,$A0,$B1,$00,$00,$CF,$B1,$A0,$00
		.BYTE	$A1,$A6,$AC,$B3,$A0,$B2,$BC,$C0,$A3,$C8,$00,$00,$D0,$C8,$B1,$00
		.BYTE	$A2,$A7,$AD,$B4,$A4,$00,$BD,$C1,$C5,$B7,$CC,$BB,$D1,$D4,$BB,$CC
		.BYTE	$A3,$A8,$AE,$00,$AB,$A3,$00,$C2,$C6,$BC,$CD,$B1,$D2,$D5,$AF,$BE
		.BYTE	$00,$A9,$AF,$B5,$A1,$B5,$00,$C3,$00,$C9,$00,$00,$D3,$D6,$CF,$00
		.BYTE	$A4,$AA,$B0,$00,$B8,$A4,$00,$C4,$C7,$CA,$CE,$CC,$00,$D7,$CE,$CC
		.BYTE	$A5,$8F,$8F,$B6,$B9,$BA,$BE,$6F,$7F,$CB,$CF,$B9,$B6,$A1,$CB,$CF
		.BYTE	$8F,$7F,$6F,$7F,$8F,$6B,$7C,$8C,$6C,$7C,$7B,$8F,$8F,$8F,$6F,$8F
		.BYTE	$12,$96,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$6F,$7F,$8F
		.BYTE	$10,$35,$0A,$1A,$27,$02,$12,$12,$6D,$7D,$8D,$12,$12,$12,$96,$8F
		.BYTE	$11,$03,$0B,$1B,$28,$60,$70,$80,$6E,$7E,$8E,$13,$13,$13,$04,$8F

		SECTION_END	"LVL3 DATA"

		SECTION_START

		FAR_OFS	_lvl6

_lvl6_objects_list:
		CHECKPOINT
		OBJ_SET	_scr0F_candle,						$80,$00,$5C,$03,_NON,_NON,_NON
		OBJ_SET	_scr0F_candle,						$80,$00,$5C,$02,_NON,_NON,_NON
		ROOM	$01
		OBJ_SET	_scr30_lvl6_boss_vega,				$80,$00,$48,$00,_NON,_NON,_NON
		OBJ_END

_lvl6_collisions:
		.BYTE	$A1,$78,$A1,$7F,$E1,$7F,$41,$43,$01,$43,$01,$00,$FB,$FF,$EF,$F0
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$E0,$37,$00,$FF,$03,$FE,$03,$F0
_lvl6_macroA_tbl:
		.BYTE	$FF,$7E,$7F,$7E,$7F,$7E,$7F,$7F,$7E,$7F,$7F,$7C,$7C,$7F,$7C,$7C
		.BYTE	$7F,$7C,$13,$15,$17,$33,$35,$37,$7D,$7D,$C2,$53,$55,$57,$68,$69
		.BYTE	$7E,$0F,$5F,$7E,$4B,$4D,$CA,$EA,$CC,$EC,$30,$7E,$52,$FF,$20,$22
		.BYTE	$20,$12,$20,$02,$20,$FF,$20,$FF,$67,$20,$63,$FF,$FF,$FF,$75,$6B
		.BYTE	$77,$FF,$6E,$FF,$6B,$22,$FF,$12,$FF,$02,$FF,$FF,$FF,$22,$12,$12
		.BYTE	$02,$02,$FF,$FF,$FF,$FF,$49,$29,$39,$49,$39,$19,$19,$39,$29,$2A
		.BYTE	$2C,$2E,$39,$19,$09,$09,$39,$39,$4E,$29,$39,$09,$19,$19,$29,$09
		.BYTE	$29,$49,$29,$09,$29,$29,$09,$29,$39,$49,$29,$39,$39,$19,$0B,$39
		.BYTE	$7D,$7A,$D8,$7D,$7D,$7D,$E8,$7D,$7D,$CD,$CF,$7D,$D7,$ED,$7F,$ED
		.BYTE	$7E,$ED,$7E,$ED,$7F,$ED,$C0,$ED,$C0,$C1,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroB_tbl:
		.BYTE	$FF,$7E,$7F,$7E,$7F,$7F,$7F,$7E,$7F,$7E,$7C,$7F,$7F,$7C,$7C,$7C
		.BYTE	$7F,$7C,$23,$25,$27,$43,$45,$47,$03,$05,$07,$7D,$7D,$C2,$78,$79
		.BYTE	$7E,$3B,$3D,$7E,$5B,$5D,$DA,$FA,$DC,$FC,$30,$42,$7E,$21,$FF,$21
		.BYTE	$22,$21,$12,$21,$02,$21,$FF,$21,$61,$FF,$6E,$FF,$FF,$75,$FF,$77
		.BYTE	$67,$FF,$6E,$FF,$6E,$FF,$22,$FF,$12,$FF,$02,$FF,$FF,$12,$22,$02
		.BYTE	$12,$FF,$02,$FF,$FF,$FF,$49,$29,$39,$1C,$1E,$29,$19,$29,$29,$49
		.BYTE	$39,$3E,$39,$29,$09,$19,$29,$39,$29,$09,$49,$09,$09,$19,$09,$09
		.BYTE	$19,$39,$39,$19,$39,$39,$19,$39,$29,$49,$39,$49,$49,$29,$39,$39
		.BYTE	$7A,$7D,$7D,$D8,$7D,$7D,$F8,$7D,$D9,$DD,$DF,$7D,$7D,$ED,$ED,$7F
		.BYTE	$ED,$7E,$ED,$7E,$ED,$7F,$ED,$C0,$C1,$C0,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroC_tbl:
		.BYTE	$FF,$7E,$7E,$7F,$7E,$7F,$7F,$7F,$7E,$7F,$7F,$7C,$7C,$7C,$7F,$7C
		.BYTE	$7C,$7F,$14,$16,$18,$34,$36,$38,$7D,$7D,$7D,$54,$56,$58,$68,$7E
		.BYTE	$0E,$5E,$7E,$4A,$4C,$7E,$CB,$EB,$7D,$7D,$7E,$7E,$7E,$FF,$20,$FF
		.BYTE	$20,$22,$20,$12,$20,$02,$20,$66,$6F,$20,$64,$FF,$74,$6A,$76,$6C
		.BYTE	$6F,$6D,$6F,$6A,$6C,$FF,$FF,$22,$FF,$12,$FF,$02,$FF,$FF,$FF,$12
		.BYTE	$12,$02,$02,$10,$FF,$31,$39,$29,$39,$49,$29,$19,$39,$29,$39,$2B
		.BYTE	$2D,$2F,$29,$29,$19,$29,$49,$39,$4F,$29,$49,$19,$09,$19,$29,$19
		.BYTE	$39,$49,$09,$19,$39,$19,$09,$19,$49,$39,$39,$49,$29,$0A,$0C,$39
		.BYTE	$7D,$7B,$D9,$7D,$D7,$E7,$E9,$7D,$D7,$CE,$7D,$EE,$7D,$ED,$7F,$ED
		.BYTE	$7E,$ED,$ED,$ED,$7F,$ED,$C0,$ED,$C0,$C1,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroD_tbl:
		.BYTE	$FF,$7E,$7E,$7F,$7F,$7F,$7E,$7F,$7F,$7E,$7C,$7F,$7C,$7C,$7C,$7F
		.BYTE	$7C,$7F,$24,$26,$28,$44,$46,$48,$04,$06,$08,$7D,$7D,$7D,$78,$7E
		.BYTE	$3A,$3C,$7E,$5A,$5C,$7E,$DB,$FB,$7D,$7D,$7E,$7E,$7E,$21,$FF,$21
		.BYTE	$FF,$21,$22,$21,$12,$21,$02,$60,$62,$6D,$6F,$74,$FF,$76,$66,$6F
		.BYTE	$6F,$6D,$6F,$6D,$6F,$FF,$FF,$FF,$22,$FF,$12,$FF,$02,$FF,$FF,$12
		.BYTE	$12,$02,$02,$FF,$00,$31,$39,$29,$1B,$1D,$1F,$19,$29,$09,$39,$39
		.BYTE	$49,$3F,$29,$39,$19,$09,$39,$39,$19,$39,$49,$09,$19,$19,$19,$19
		.BYTE	$29,$49,$29,$29,$49,$29,$29,$29,$39,$39,$39,$49,$39,$39,$49,$39
		.BYTE	$7B,$7D,$D7,$D9,$7D,$F7,$F9,$D8,$7D,$DE,$7D,$7D,$7D,$ED,$ED,$7F
		.BYTE	$ED,$7E,$ED,$ED,$ED,$7F,$ED,$C0,$C1,$C0,$ED,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl6_macroE_tbl:
		.BYTE	$00,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03
		.BYTE	$03,$03,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$00,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$01,$01,$01,$01,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$03,$03,$03,$03,$03
		.BYTE	$03,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$03,$03,$00,$00,$00
		.BYTE	$00,$03,$03,$00,$00,$00,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$03,$03,$03
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$03,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl6_rooms_lib:
		.WORD	_l6_r01,      0,      0,      0,      0,      0,      0,      0
		.WORD	_l6_r02,      0,      0,      0,      0,      0,      0,      0
		.WORD	_l6_r03,      0,      0,      0,      0,      0,      0,      0
		.WORD	_l6_r04,      0,      0,      0,      0,      0,      0,      0
_l6_r01:
		.BYTE	$00,$00,$1E,$00,$54,$55,$55,$55,$55,$55,$55,$53,$00,$1E,$00,$00
		.BYTE	$00,$4B,$1E,$4C,$35,$56,$5D,$64,$6B,$72,$79,$36,$4B,$1E,$4C,$00
		.BYTE	$52,$49,$1E,$4A,$33,$57,$5E,$65,$6C,$73,$7A,$34,$49,$1E,$4A,$51
		.BYTE	$50,$47,$1E,$48,$31,$58,$5F,$66,$6D,$74,$7B,$32,$47,$1E,$48,$4F
		.BYTE	$4E,$45,$1E,$46,$2F,$59,$60,$67,$6E,$75,$7C,$30,$45,$1E,$46,$4D
		.BYTE	$00,$00,$1E,$3B,$2D,$5A,$61,$68,$6F,$76,$7D,$2E,$3C,$1E,$00,$00
		.BYTE	$41,$41,$1E,$3D,$37,$5B,$62,$69,$70,$77,$7E,$39,$3E,$1E,$43,$41
		.BYTE	$42,$42,$1E,$3F,$38,$5C,$63,$6A,$71,$78,$7F,$3A,$40,$1E,$44,$42
		.BYTE	$91,$01,$1F,$01,$2B,$2A,$2A,$2A,$2A,$2A,$2A,$2C,$01,$1F,$01,$90
		.BYTE	$91,$01,$01,$01,$01,$01,$01,$26,$27,$01,$01,$01,$01,$01,$01,$90
		.BYTE	$91,$01,$01,$01,$01,$01,$01,$28,$29,$01,$01,$01,$01,$01,$01,$90
		.BYTE	$8F,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$10,$8E
		.BYTE	$8F,$0B,$02,$04,$0B,$02,$02,$02,$02,$02,$02,$0A,$06,$02,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$01,$18,$12,$15,$1B,$01,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0B,$01,$19,$13,$16,$1C,$01,$0A,$11,$11,$0E,$8E
_l6_r02:
		.BYTE	$97,$99,$9A,$97,$99,$9A,$1A,$14,$17,$1D,$9A,$98,$96,$9A,$98,$96
		.BYTE	$8F,$0B,$03,$05,$0B,$03,$03,$03,$03,$03,$03,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0F,$0E,$11,$11,$11,$11,$0F,$0E,$11,$11,$0E,$8E
		.BYTE	$8F,$0B,$01,$08,$0B,$0A,$09,$20,$23,$08,$0B,$0A,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$0A,$09,$21,$24,$08,$0B,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0B,$0A,$09,$22,$25,$08,$0B,$0A,$11,$11,$0E,$8E
		.BYTE	$8F,$0B,$01,$08,$0C,$0D,$10,$10,$10,$10,$0C,$0D,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$02,$02,$0A,$0B,$02,$02,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$0F,$11,$11,$0B,$01,$01,$0A,$0B,$01,$01,$0A,$11,$11,$0E,$8E
		.BYTE	$8F,$0B,$01,$08,$0B,$01,$01,$0A,$0B,$01,$01,$0A,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$01,$08,$0B,$01,$01,$0A,$0B,$01,$01,$0A,$09,$01,$0A,$8E
		.BYTE	$8F,$0B,$03,$05,$0B,$03,$03,$0A,$0B,$03,$03,$0A,$07,$03,$0A,$8E
		.BYTE	$8F,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$11,$8E
		.BYTE	$91,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$01,$90
		.BYTE	$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D,$8D
_l6_r03:
		.BYTE	$8D,$8D,$8D,$8D,$8D,$8D,$09,$01,$01,$08,$8D,$8D,$8D,$8D,$8D,$8D
		.BYTE	$91,$01,$89,$8B,$85,$01,$09,$01,$01,$08,$01,$01,$01,$87,$01,$90
		.BYTE	$91,$01,$8A,$01,$86,$84,$09,$01,$01,$08,$85,$01,$83,$88,$8C,$90
		.BYTE	$91,$01,$01,$01,$87,$82,$09,$01,$01,$08,$86,$84,$01,$89,$8B,$90
		.BYTE	$91,$01,$85,$83,$88,$8C,$09,$01,$01,$08,$01,$82,$01,$8A,$01,$90
		.BYTE	$91,$01,$86,$84,$89,$8B,$09,$01,$01,$08,$01,$89,$8B,$85,$01,$90
		.BYTE	$91,$85,$87,$01,$8A,$80,$09,$01,$01,$08,$81,$8A,$82,$86,$84,$90
		.BYTE	$91,$86,$88,$82,$85,$01,$09,$01,$01,$08,$01,$85,$87,$82,$01,$90
		.BYTE	$91,$01,$82,$01,$86,$84,$09,$01,$01,$08,$01,$86,$88,$8C,$01,$90
		.BYTE	$91,$01,$01,$01,$83,$84,$09,$01,$01,$08,$89,$8B,$01,$01,$01,$90
		.BYTE	$91,$01,$01,$85,$82,$01,$09,$01,$01,$08,$8A,$82,$01,$89,$8B,$90
		.BYTE	$91,$89,$8B,$86,$84,$80,$09,$01,$01,$08,$81,$01,$85,$8A,$01,$90
		.BYTE	$91,$8A,$82,$01,$01,$01,$09,$01,$01,$08,$83,$84,$86,$84,$01,$90
		.BYTE	$91,$01,$01,$89,$8B,$82,$09,$01,$01,$08,$01,$85,$87,$01,$01,$90
		.BYTE	$91,$82,$01,$8A,$85,$01,$09,$01,$01,$08,$01,$86,$88,$8C,$01,$90
_l6_r04:
		.BYTE	$91,$01,$01,$01,$86,$84,$09,$01,$01,$08,$01,$83,$84,$85,$01,$90
		.BYTE	$91,$01,$89,$8B,$82,$80,$09,$01,$01,$08,$81,$01,$87,$86,$84,$90
		.BYTE	$91,$01,$8A,$01,$85,$01,$09,$01,$01,$08,$85,$83,$88,$8C,$01,$90
		.BYTE	$91,$01,$83,$84,$86,$84,$09,$01,$01,$08,$86,$84,$01,$89,$8B,$90
		.BYTE	$91,$85,$01,$01,$87,$01,$09,$01,$01,$08,$01,$89,$8B,$8A,$01,$90
		.BYTE	$91,$86,$84,$83,$88,$8C,$09,$01,$01,$08,$01,$8A,$83,$84,$01,$90
		.BYTE	$91,$01,$01,$89,$8B,$80,$09,$01,$01,$08,$81,$01,$01,$85,$01,$90
		.BYTE	$91,$83,$84,$8A,$01,$01,$09,$01,$01,$08,$83,$84,$87,$86,$84,$90
		.BYTE	$91,$01,$01,$01,$82,$01,$09,$01,$01,$08,$01,$83,$88,$8C,$01,$90
		.BYTE	$91,$01,$01,$85,$83,$84,$09,$01,$01,$08,$01,$01,$89,$8B,$01,$90
		.BYTE	$91,$89,$8B,$86,$84,$01,$09,$01,$01,$08,$01,$85,$8A,$01,$01,$90
		.BYTE	$91,$8A,$83,$84,$82,$80,$09,$01,$01,$08,$81,$86,$84,$82,$01,$90
		.BYTE	$91,$01,$82,$01,$89,$8B,$09,$01,$01,$08,$01,$89,$8B,$83,$84,$90
		.BYTE	$91,$01,$01,$82,$8A,$01,$09,$01,$01,$08,$82,$8A,$01,$01,$01,$90
		.BYTE	$8D,$8D,$8D,$8D,$8D,$8D,$94,$8D,$8D,$95,$8D,$8D,$8D,$8D,$8D,$8D

		SECTION_END	"LVL6 DATA"

		BANK_END 2,$C000
