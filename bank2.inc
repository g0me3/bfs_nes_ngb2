
		ORG $8000

		BANK_START $02

		SECTION_START

; NOTE: even if all these sprites are set in libraries 08 and 09, they copied here
; as well. also an ending libraries contains more copies... this is fine for
; not care about actual sprite data locations or not care about optimizations
; (at least there are a lot of free space anyway), however, this may be optimized
; as well
;

		SPR_LIB_START	_spr_libA00

		SPR_IDX	_sprA00_00	; title logo patch for ghost hole
		SPR_IDX	_sprA00_01
		SPR_IDX	_sprA00_02	; title slime animation
		SPR_IDX	_sprA00_03
		SPR_IDX	_sprA00_04	; title buster A animations
		SPR_IDX	_sprA03_0A	; regular movement sprites, now optimized
		SPR_IDX	_sprA03_09	; to fetch common system bank sprites data
		SPR_IDX	_sprA03_0B
		SPR_IDX	_sprA03_0E
		SPR_IDX	_sprA03_0D
		SPR_IDX	_sprA03_0F
		SPR_IDX	_sprA00_0B	; special sprites for sliding on the pole
		SPR_IDX	_sprA00_0C
		SPR_IDX	_sprA00_0D
		SPR_IDX	_sprA00_0E
		SPR_IDX	_sprA00_0F
		SPR_IDX	_sprA00_10	; title buster B anim
		SPR_IDX	_sprA03_2A	; same for the rest of the busters
		SPR_IDX	_sprA03_29
		SPR_IDX	_sprA03_2B
		SPR_IDX	_sprA03_2E
		SPR_IDX	_sprA03_2D
		SPR_IDX	_sprA03_2F
		SPR_IDX	_sprA00_17
		SPR_IDX	_sprA00_18
		SPR_IDX	_sprA00_19
		SPR_IDX	_sprA00_1A
		SPR_IDX	_sprA00_1B
		SPR_IDX	_sprA00_1C	; title buster C anim
		SPR_IDX	_sprA03_3A
		SPR_IDX	_sprA03_39
		SPR_IDX	_sprA03_3B
		SPR_IDX	_sprA03_3E
		SPR_IDX	_sprA03_3D
		SPR_IDX	_sprA03_3F
		SPR_IDX	_sprA00_23
		SPR_IDX	_sprA00_24
		SPR_IDX	_sprA00_25
		SPR_IDX	_sprA00_26
		SPR_IDX	_sprA00_27
		SPR_IDX	_sprA00_28	; title buster D anim
		SPR_IDX	_sprA03_1A
		SPR_IDX	_sprA03_19
		SPR_IDX	_sprA03_1B
		SPR_IDX	_sprA03_1E
		SPR_IDX	_sprA03_1D
		SPR_IDX	_sprA03_1F
		SPR_IDX	_sprA00_2F
		SPR_IDX	_sprA00_30
		SPR_IDX	_sprA00_31
		SPR_IDX	_sprA00_32
		SPR_IDX	_sprA00_33
		SPR_IDX	_sprA03_4A	; buster select louis
		SPR_IDX	_sprA03_42
		SPR_IDX	_sprA03_41
		SPR_IDX	_sprA03_43
		SPR_IDX	_sprA03_4E
		SPR_IDX	_sprA03_4D
		SPR_IDX	_sprA03_4F
		SPR_IDX	_sprA00_3B
		SPR_IDX	_sprA00_3C
		SPR_IDX	_sprA00_3D
		SPR_IDX	_sprA00_3E
		SPR_IDX	_sprA00_3F
		SPR_IDX	_sprA00_40	; select buster name overlays
		SPR_IDX	_sprA00_41
		SPR_IDX	_sprA00_42
		SPR_IDX	_sprA00_43
		SPR_IDX	_sprA00_44
		SPR_IDX	_sprA00_45	; player's ass alone
		SPR_IDX	_sprA00_46	; title ghost logo
		SPR_IDX	_sprA00_47
		SPR_IDX	_sprA00_48
		SPR_IDX	_sprA00_49
		SPR_IDX	_sprA00_4A
		SPR_IDX	_sprA00_4B
		SPR_IDX	_sprA00_4C

		SPR_LIB_SIZE	_spr_libA00

; NOTE: here is the ending sprites, many of them copy the regular players
; sprites and may of them not used in the ending at all...
;
		SPR_LIB_START	_spr_libA02

		SPR_IDX	_sprA02_00	; chibi vega?
		SPR_IDX	_sprA02_01
		SPR_IDX	_sprA02_02
		SPR_IDX	_sprA02_03
		SPR_IDX	_sprA02_04
		SPR_IDX	_sprA02_05
		SPR_IDX	_sprA02_06	; statue of liberty for some reason
		SPR_IDX	_sprA02_07
		SPR_IDX	_sprA02_08
		SPR_IDX	_sprA02_09
		SPR_IDX	_sprA02_0A
		SPR_IDX	_sprA02_0B
		SPR_IDX	_sprA02_0C
		SPR_IDX	_sprA02_0D
		SPR_IDX	_sprA02_0E	; chaisaw
		SPR_IDX	_sprA02_0F
		SPR_IDX	_sprA02_10
		SPR_IDX	_sprA02_11
		SPR_IDX	_sprA02_12
		SPR_IDX	_sprA02_13
; NOTE: these sprites are exactly tha same as regular characters sprites
; but with background flag set to be below the background. this particular
; engine cannot override sprite attributes and flags so they need to
; have separate sprite copy for every roration and attributes.
		SPR_IDX	_sprA02_14	; peter U	A	unused
		SPR_IDX	_sprA02_15	; 			B	unused
		SPR_IDX	_sprA02_16	; 			C	unused
		SPR_IDX	_sprA02_17	; 		R 	A
		SPR_IDX	_sprA02_18	;			B
		SPR_IDX	_sprA02_19	;			C
		SPR_IDX	_sprA02_1A	; 		D	A
		SPR_IDX	_sprA02_1B	; 			B	unused
		SPR_IDX	_sprA02_1C	; 			C	unused
		SPR_IDX	_sprA02_1D	; 		L	A
		SPR_IDX	_sprA02_1E	; 			B
		SPR_IDX	_sprA02_1F	;			C
		SPR_IDX	_sprA02_20	; ray	U	A	unused
		SPR_IDX	_sprA02_21	; 			B	unused
		SPR_IDX	_sprA02_22	; 			C	unused
		SPR_IDX	_sprA02_23	; 		R	A
		SPR_IDX	_sprA02_24	;			B
		SPR_IDX	_sprA02_25	;			C
		SPR_IDX	_sprA02_26	; 		D	A
		SPR_IDX	_sprA02_27	; 			B	unused
		SPR_IDX	_sprA02_28	; 			C	unused
		SPR_IDX	_sprA02_29	; 		L	A
		SPR_IDX	_sprA02_2A	;			B
		SPR_IDX	_sprA02_2B	;			C
		SPR_IDX	_sprA02_2C	; egon	U	A
		SPR_IDX	_sprA02_2D	; 			B	unused
		SPR_IDX	_sprA02_2E	; 			C	unused
		SPR_IDX	_sprA02_2F	; 		R	A
		SPR_IDX	_sprA02_30	; 			B
		SPR_IDX	_sprA02_31	;			C
		SPR_IDX	_sprA02_32	; 		D	A	unused
		SPR_IDX	_sprA02_33	; 			B	unused
		SPR_IDX	_sprA02_34	; 			C	unused
		SPR_IDX	_sprA02_35	;		L	A
		SPR_IDX	_sprA02_36	;			B
		SPR_IDX	_sprA02_37	;			C
		SPR_IDX	_sprA02_38	; winst	U	A
		SPR_IDX	_sprA02_39	; 			B	unused
		SPR_IDX	_sprA02_3A	; 			C	unused
		SPR_IDX	_sprA02_3B	;		R	A
		SPR_IDX	_sprA02_3C	;			B
		SPR_IDX	_sprA02_3D	;			C
		SPR_IDX	_sprA02_3E	; 		D	A	unused
		SPR_IDX	_sprA02_3F	; 			B	unused
		SPR_IDX	_sprA02_40	; 			C	unused
		SPR_IDX	_sprA02_41	;		L	A
		SPR_IDX	_sprA02_42	;			B
		SPR_IDX	_sprA02_43	;			C
		SPR_IDX	_sprA02_44	; louis	U	A	unused
		SPR_IDX	_sprA02_45	; 			B	unused
		SPR_IDX	_sprA02_46	; 			C	unused
		SPR_IDX	_sprA02_47	;		R	A
		SPR_IDX	_sprA02_48	;			B
		SPR_IDX	_sprA02_49	;			C
		SPR_IDX	_sprA02_4A	;		D	A
		SPR_IDX	_sprA02_4B	; 			B	unused
		SPR_IDX	_sprA02_4C	; 			C	unused
		SPR_IDX	_sprA02_4D	;		L	A
		SPR_IDX	_sprA02_4E	;			B
		SPR_IDX	_sprA02_4F	;			C
		SPR_IDX	_sprA02_50	; peter	sit D	A
		SPR_IDX	_sprA02_51	;				B
		SPR_IDX	_sprA02_52	;			R
		SPR_IDX	_sprA02_53	; ray sit	D	A
		SPR_IDX	_sprA02_54	;				B
		SPR_IDX	_sprA02_55	;			L
		SPR_IDX	_sprA02_56	; runr	R	A
		SPR_IDX	_sprA02_57	;			B
		SPR_IDX	_sprA02_58	;			C
		SPR_IDX	_sprA02_59	;			D
		SPR_IDX	_sprA02_5A	;		L	A
		SPR_IDX	_sprA02_5B	;			B
		SPR_IDX	_sprA02_5C	;			C
		SPR_IDX	_sprA02_5D	;			D
		SPR_IDX	_sprA02_5E
		SPR_IDX	_sprA02_5F
		SPR_IDX	_sprA02_60
		SPR_IDX	_sprA02_61
		SPR_IDX	_sprA02_62
		SPR_IDX	_sprA02_63
		SPR_IDX	_sprA02_64
		SPR_IDX	_sprA02_65
		SPR_IDX	_sprA02_66
		SPR_IDX	_sprA02_67
		SPR_IDX	_sprA02_68
		SPR_IDX	_sprA02_69
		SPR_IDX	_sprA02_6A
		SPR_IDX	_sprA02_6B
		SPR_IDX	_sprA02_6C
		SPR_IDX	_sprA02_6D
		SPR_IDX	_sprA02_6E
		SPR_IDX	_sprA02_6F
		SPR_IDX	_sprA02_70
; NOTE, sprites between 70 and AE are shared in system bank
; to optimize sprites data
		SPR_IDX	_sprA03_02	; 71 unused
		SPR_IDX	_sprA03_01	; 71 unused
		SPR_IDX	_sprA03_03	; 73 unused
		SPR_IDX	_sprA03_06	; 74
		SPR_IDX	_sprA03_05	; 75
		SPR_IDX	_sprA03_07	; 76
		SPR_IDX	_sprA03_0A	; 77 unused
		SPR_IDX	_sprA03_09	; 78 unused
		SPR_IDX	_sprA03_0B	; 79 unused
		SPR_IDX	_sprA03_0E	; 7A
		SPR_IDX	_sprA03_0D	; 7B unused
		SPR_IDX	_sprA03_0F	; 7C unused
		SPR_IDX	_sprA03_12	; 7D unused
		SPR_IDX	_sprA03_11	; 7E unused
		SPR_IDX	_sprA03_13	; 7F unused
		SPR_IDX	_sprA03_16	; 80
		SPR_IDX	_sprA03_15	; 81
		SPR_IDX	_sprA03_17	; 82
		SPR_IDX	_sprA03_1A	; 83
		SPR_IDX	_sprA03_19	; 84 unused
		SPR_IDX	_sprA03_1B	; 85 unused
		SPR_IDX	_sprA03_1E	; 86
		SPR_IDX	_sprA03_1D	; 87 unused
		SPR_IDX	_sprA03_1F	; 88 unused
		SPR_IDX	_sprA03_22	; 89 unused
		SPR_IDX	_sprA03_21	; 8A unused
		SPR_IDX	_sprA03_23	; 8B unused
		SPR_IDX	_sprA03_26	; 8C
		SPR_IDX	_sprA03_25	; 8D
		SPR_IDX	_sprA03_27	; 8E
		SPR_IDX	_sprA03_2A	; 8F
		SPR_IDX	_sprA03_29	; 90 unused
		SPR_IDX	_sprA03_2B	; 91 unused
		SPR_IDX	_sprA03_2E	; 92
		SPR_IDX	_sprA03_2D	; 93
		SPR_IDX	_sprA03_2F	; 94
		SPR_IDX	_sprA03_32	; 95 unused
		SPR_IDX	_sprA03_31	; 96 unused
		SPR_IDX	_sprA03_33	; 97 unused
		SPR_IDX	_sprA03_36	; 98
		SPR_IDX	_sprA03_35	; 99
		SPR_IDX	_sprA03_37	; 9A
		SPR_IDX	_sprA03_3A	; 9B
		SPR_IDX	_sprA03_39	; 9C unused
		SPR_IDX	_sprA03_3B	; 9D unused
		SPR_IDX	_sprA03_3E	; 9E
		SPR_IDX	_sprA03_3D	; 9F
		SPR_IDX	_sprA03_3F	; A0
		SPR_IDX	_sprA03_42	; A1 unused
		SPR_IDX	_sprA03_41	; A2 unused
		SPR_IDX	_sprA03_43	; A3 unused
		SPR_IDX	_sprA03_46	; A4
		SPR_IDX	_sprA03_45	; A5
		SPR_IDX	_sprA03_47	; A6
		SPR_IDX	_sprA03_4A	; A7
		SPR_IDX	_sprA03_49	; A8 unused
		SPR_IDX	_sprA03_4B	; A9 unused
		SPR_IDX	_sprA03_4E	; AA
		SPR_IDX	_sprA03_4D	; AB unused
		SPR_IDX	_sprA03_4F	; AC unused
		SPR_IDX	_sprA02_AD
		SPR_IDX	_sprA02_AE
		SPR_IDX	_sprA02_AF
		SPR_IDX	_sprA02_B0
		SPR_IDX	_sprA02_B1
		SPR_IDX	_sprA02_B2
		SPR_IDX	_sprA02_B3
		SPR_IDX	_sprA02_B4
		SPR_IDX	_sprA02_B5
		SPR_IDX	_sprA02_B6
		SPR_IDX	_sprA02_B7
		SPR_IDX	_sprA02_B8
		SPR_IDX	_sprA02_B9
		SPR_IDX	_sprA02_BA
		SPR_IDX	_sprA02_BB
		SPR_IDX	_sprA02_BC

		SPR_LIB_SIZE	_spr_libA02

		SPR_LIB_START	_spr_libB02

		SPR_IDX	_sprB02_C0
		SPR_IDX	_sprB02_C1
		SPR_IDX	_sprB02_C2
		SPR_IDX	_sprB02_C3
		SPR_IDX	_sprB02_C4
		SPR_IDX	_sprB02_C5
		SPR_IDX	_sprB02_C6
		SPR_IDX	_sprB02_C7
		SPR_IDX	_sprB02_C8
		SPR_IDX	_sprB02_C9
		SPR_IDX	_sprB02_CA
		SPR_IDX	_sprB02_CB
		SPR_IDX	_sprB02_CC
		SPR_IDX	_sprB02_CD
		SPR_IDX	_sprB02_CE
		SPR_IDX	_sprB02_CF
		SPR_IDX	_sprB02_D0
		SPR_IDX	_sprB02_D1
		SPR_IDX	_sprB02_D2

		SPR_LIB_SIZE	_spr_libB02

#if SPR_SIZE_TEST==0
#if NEW_SPRITES==1
		INCLUDE		"../spr/spr_data0_new.inc"
#else
		INCLUDE		"../spr/spr_data0.inc"
#endif
#endif

		SECTION_END	"PRG0 SPRITES"

		SECTION_START

		SPR_LIB_START	_spr_libA01

		SPR_IDX	_sprA01_00	; doors open anims
		SPR_IDX	_sprA01_01
		SPR_IDX	_sprA01_02
		SPR_IDX	_sprA01_03
		SPR_IDX	_sprA01_04
		SPR_IDX	_sprA01_05
		SPR_IDX	_sprA01_06
		SPR_IDX	_sprA01_07
		SPR_IDX	_sprA01_08
		SPR_IDX	_sprA01_09
		SPR_IDX	_sprA01_0A
		SPR_IDX	_sprA01_0B
		SPR_IDX	_sprA01_0C
		SPR_IDX	_sprA01_0D
; NOTE: for some reason, the prev to last level's doors uses sprite pal 0
; as the players itself, so when doors are animated they turns blue for.
; however, when using colors 2 or 3, they may still be yellowish without
; much modifications...
; NEW, fixed colors for those sprites for a great justice
		SPR_IDX	_sprA01_0E
		SPR_IDX	_sprA01_0F
		SPR_IDX	_sprA01_10
		SPR_IDX	_sprA01_11
		SPR_IDX	_sprA01_12
		SPR_IDX	_sprA01_13
		SPR_IDX	_sprA01_14
		SPR_IDX	_sprA01_15	; pause mode sprites
		SPR_IDX	_sprA01_16
		SPR_IDX	_sprA01_17	; stage complete sprites
		SPR_IDX	_sprA01_18
		SPR_IDX	_sprA01_19	; money bag prize
		SPR_IDX	_sprA01_1A
; NEW, readded coin
		SPR_IDX	_sprA01_1B
		SPR_IDX	_sprA01_1C
		SPR_IDX	_sprA01_1D
		SPR_IDX	_sprA01_1E

		SPR_LIB_SIZE	_spr_libA01

#if SPR_SIZE_TEST==0
#if NEW_SPRITES==1
		INCLUDE		"../spr/spr_data1_new.inc"
#else
		INCLUDE		"../spr/spr_data1.inc"
#endif
#endif

		SECTION_END	"PRG1 SPRITES"

		SECTION_START

		SPR_LIB_START	_spr_libA08

		SPR_IDX	_sprA08_00	; catch, uses copies in CHR1 for every level
		SPR_IDX	_sprA08_01
		SPR_IDX	_sprA08_02
		SPR_IDX	_sprA08_03
		SPR_IDX	_sprA08_04	; lvl1 boss judges (CHR0 07, CHR1 none)
		SPR_IDX	_sprA08_05
		SPR_IDX	_sprA08_06
		SPR_IDX	_sprA08_07
		SPR_IDX	_sprA08_08
		SPR_IDX	_sprA08_09
		SPR_IDX	_sprA08_0A
		SPR_IDX	_sprA08_0B
		SPR_IDX	_sprA08_0C
		SPR_IDX	_sprA08_0D
		SPR_IDX	_sprA08_0E
		SPR_IDX	_sprA08_0F
		SPR_IDX	_sprA08_10
		SPR_IDX	_sprA08_11
		SPR_IDX	_sprA08_12
		SPR_IDX	_sprA08_13
		SPR_IDX	_sprA08_14
		SPR_IDX	_sprA08_15
		SPR_IDX	_sprA08_16
		SPR_IDX	_sprA08_17
		SPR_IDX	_sprA08_18
		SPR_IDX	_sprA08_19
		SPR_IDX	_sprA08_1A
		SPR_IDX	_sprA08_1B
		SPR_IDX	_sprA08_1C
		SPR_IDX	_sprA08_1D
		SPR_IDX	_sprA08_1E
		SPR_IDX	_sprA08_1F
		SPR_IDX	_sprA08_20
		SPR_IDX	_sprA08_21
		SPR_IDX	_sprA08_22
		SPR_IDX	_sprA08_23
		SPR_IDX	_sprA08_24
		SPR_IDX	_sprA08_25
		SPR_IDX	_sprA08_26
		SPR_IDX	_sprA08_27
		SPR_IDX	_sprA08_28
		SPR_IDX	_sprA08_29	; lvl2 boss train slime (CHR0 0C, CHR1 0A)
		SPR_IDX	_sprA08_2A
		SPR_IDX	_sprA08_2B
		SPR_IDX	_sprA08_2C
		SPR_IDX	_sprA08_2D
		SPR_IDX	_sprA08_2E
		SPR_IDX	_sprA08_2F
		SPR_IDX	_sprA08_30
		SPR_IDX	_sprA08_31
		SPR_IDX	_sprA08_32
		SPR_IDX	_sprA08_33
		SPR_IDX	_sprA08_34
		SPR_IDX	_sprA08_35
		SPR_IDX	_sprA08_36
		SPR_IDX	_sprA08_37
		SPR_IDX	_sprA08_38
		SPR_IDX	_sprA08_39
		SPR_IDX	_sprA08_3A
		SPR_IDX	_sprA08_3B	; lvl3 boss sewer dragons (CHR0 13, CHR1 none)
		SPR_IDX	_sprA08_3C
		SPR_IDX	_sprA08_3D
		SPR_IDX	_sprA08_3E
		SPR_IDX	_sprA08_3F
		SPR_IDX	_sprA08_40
		SPR_IDX	_sprA08_41
		SPR_IDX	_sprA08_42
		SPR_IDX	_sprA08_43
		SPR_IDX	_sprA08_44
		SPR_IDX	_sprA08_45
		SPR_IDX	_sprA08_46
		SPR_IDX	_sprA08_47
		SPR_IDX	_sprA08_48
		SPR_IDX	_sprA08_49
		SPR_IDX	_sprA08_4A
		SPR_IDX	_sprA08_4B
		SPR_IDX	_sprA08_4C
		SPR_IDX	_sprA08_4D
		SPR_IDX	_sprA08_4E
		SPR_IDX	_sprA08_4F
		SPR_IDX	_sprA08_50
		SPR_IDX	_sprA08_51
		SPR_IDX	_sprA08_52
		SPR_IDX	_sprA08_53
		SPR_IDX	_sprA08_54
		SPR_IDX	_sprA08_55
		SPR_IDX	_sprA08_56
		SPR_IDX	_sprA08_57
		SPR_IDX	_sprA08_58
		SPR_IDX	_sprA08_59
		SPR_IDX	_sprA08_5A	; lvl5 boss keykeeper (CHR0 18, CHR1 none)
		SPR_IDX	_sprA08_5B
		SPR_IDX	_sprA08_5C
		SPR_IDX	_sprA08_5D
		SPR_IDX	_sprA08_5E
		SPR_IDX	_sprA08_5F
		SPR_IDX	_sprA08_60
		SPR_IDX	_sprA08_61
		SPR_IDX	_sprA08_62
		SPR_IDX	_sprA08_63
		SPR_IDX	_sprA08_64
		SPR_IDX	_sprA08_65
		SPR_IDX	_sprA08_66
		SPR_IDX	_sprA08_67
		SPR_IDX	_sprA08_68
		SPR_IDX	_sprA08_69
		SPR_IDX	_sprA08_6A
		SPR_IDX	_sprA08_6B
		SPR_IDX	_sprA08_6C
		SPR_IDX	_sprA08_6D
		SPR_IDX	_sprA08_6E
		SPR_IDX	_sprA08_6F
		SPR_IDX	_sprA08_70
		SPR_IDX	_sprA08_71
		SPR_IDX	_sprA08_72
		SPR_IDX	_sprA08_73
		SPR_IDX	_sprA08_74
		SPR_IDX	_sprA08_75
		SPR_IDX	_sprA08_76
; NOTE: this is a floor phase for baby keykeeper after it fall down to the floor
; but script use only two next frames rendered this one unused.
		SPR_IDX	_sprA08_77	; unused
		SPR_IDX	_sprA08_78
		SPR_IDX	_sprA08_79
		SPR_IDX	_sprA08_7A
		SPR_IDX	_sprA08_7B
		SPR_IDX	_sprA08_80
		SPR_IDX	_sprA08_81
		SPR_IDX	_sprA08_82
		SPR_IDX	_sprA08_83
		SPR_IDX	_sprA08_80
		SPR_IDX	_sprA08_81
		SPR_IDX	_sprA08_82
		SPR_IDX	_sprA08_83
		SPR_IDX	_sprA08_84	; lvl6 boss vega dead phase (CHR0 17, CHR1 none)
		SPR_IDX	_sprA08_85
		SPR_IDX	_sprA08_86
		SPR_IDX	_sprA08_87
		SPR_IDX	_sprA08_88
		SPR_IDX	_sprA08_89
		SPR_IDX	_sprA08_8A
		SPR_IDX	_sprA08_8B
		SPR_IDX	_sprA08_8C
		SPR_IDX	_sprA08_8D
		SPR_IDX	_sprA08_8E
		SPR_IDX	_sprA08_8F
		SPR_IDX	_sprA08_90
		SPR_IDX	_sprA08_91	; ending cutscene sprites (CHR1 none, CHR1 16)
		SPR_IDX	_sprA08_92
		SPR_IDX	_sprA08_93
		SPR_IDX	_sprA08_94

		SPR_LIB_SIZE	_spr_libA08

		SPR_LIB_START	_spr_libB08

; NOTE: this is the only multiple chunked sprite in original game
; and because of sprite manager bug, it need to have adjusted
; Y position. when i fix the Y pos bug in sprite routine, i fixed
; Y here as well

		SPR_IDX	_sprB08_C0	; lvl6 boss vega main sprites (CHR0 17, CHR1 none)
		SPR_IDX	_sprB08_C1
		SPR_IDX	_sprB08_C2
		SPR_IDX	_sprB08_C3
		SPR_IDX	_sprB08_C4
		SPR_IDX	_sprB08_C5
		SPR_IDX	_sprB08_C6
		SPR_IDX	_sprB08_C7

		SPR_LIB_SIZE	_spr_libB08

#if SPR_SIZE_TEST==0
#if NEW_SPRITES==1
		INCLUDE		"../spr/spr_data2_new.inc"
#else
		INCLUDE		"../spr/spr_data2.inc"
#endif
#endif

		SECTION_END	"PRG3 SPRITES"

		SECTION_START

		SPR_LIB_START	_spr_libA05

; NOTE: this is a common sprites for animation of catch glow, shared
; in all enemy sprite libraries and resided in system bank to be
; accessible from any other bank.

		SPR_IDX	_sprA08_00
		SPR_IDX	_sprA08_01
		SPR_IDX	_sprA08_02
		SPR_IDX	_sprA08_03
		SPR_IDX	_sprA05_04
		SPR_IDX	_sprA05_05
		SPR_IDX	_sprA05_06
		SPR_IDX	_sprA05_07
		SPR_IDX	_sprA05_08
		SPR_IDX	_sprA05_09
		SPR_IDX	_sprA05_0A
		SPR_IDX	_sprA05_0B
		SPR_IDX	_sprA05_0C
		SPR_IDX	_sprA05_0D
		SPR_IDX	_sprA05_0E
		SPR_IDX	_sprA05_0F
		SPR_IDX	_sprA05_10
		SPR_IDX	_sprA05_11
		SPR_IDX	_sprA05_12
		SPR_IDX	_sprA05_13
		SPR_IDX	_sprA05_14
; NOTE: there are 4 diifferent objects to throw only one of them has full rorate
; animations the rest are same for all 4 frames.
; why they did not animated all of them, don't know, seems most probably
; because lack of free space in this particular bank.
;
; NEW: restored animations for three throwable objects
;
		SPR_IDX	_sprA05_15	; meat
		SPR_IDX	_sprA05_16
		SPR_IDX	_sprA05_17
		SPR_IDX	_sprA05_18
		SPR_IDX	_sprA05_19	; pan
		SPR_IDX	_sprA05_1A
		SPR_IDX	_sprA05_1B
		SPR_IDX	_sprA05_1C
		SPR_IDX	_sprA05_1D	; pineaple
		SPR_IDX	_sprA05_1E
		SPR_IDX	_sprA05_1F
		SPR_IDX	_sprA05_20
		SPR_IDX	_sprA05_21	; coat rack
		SPR_IDX	_sprA05_22
		SPR_IDX	_sprA05_23
		SPR_IDX	_sprA05_24
		SPR_IDX	_sprA05_25
		SPR_IDX	_sprA05_26
		SPR_IDX	_sprA05_27
		SPR_IDX	_sprA05_28
		SPR_IDX	_sprA05_29
		SPR_IDX	_sprA05_2A
		SPR_IDX	_sprA05_2B
		SPR_IDX	_sprA05_2C
		SPR_IDX	_sprA05_2D
		SPR_IDX	_sprA05_2E
		SPR_IDX	_sprA05_2F
		SPR_IDX	_sprA05_30
		SPR_IDX	_sprA05_31
		SPR_IDX	_sprA05_32
		SPR_IDX	_sprA05_33
		SPR_IDX	_sprA05_34
		SPR_IDX	_sprA05_35
		SPR_IDX	_sprA05_36
		SPR_IDX	_sprA05_37
		SPR_IDX	_sprA05_38
		SPR_IDX	_sprA05_39
		SPR_IDX	_sprA05_3A
		SPR_IDX	_sprA05_3B
		SPR_IDX	_sprA05_3C
		SPR_IDX	_sprA05_3D
		SPR_IDX	_sprA05_3E
		SPR_IDX	_sprA05_3F
		SPR_IDX	_sprA05_40
		SPR_IDX	_sprA05_41
		SPR_IDX	_sprA05_42
		SPR_IDX	_sprA05_43
		SPR_IDX	_sprA05_44
		SPR_IDX	_sprA05_45
		SPR_IDX	_sprA05_46
		SPR_IDX	_sprA05_47
		SPR_IDX	_sprA05_48
		SPR_IDX	_sprA05_49
		SPR_IDX	_sprA05_4A
		SPR_IDX	_sprA05_4B
		SPR_IDX	_sprA05_4C
		SPR_IDX	_sprA05_4D
		SPR_IDX	_sprA05_4E
		SPR_IDX	_sprA05_4F
		SPR_IDX	_sprA05_50
		SPR_IDX	_sprA05_51
		SPR_IDX	_sprA05_52
		SPR_IDX	_sprA05_53
		SPR_IDX	_sprA05_56
		SPR_IDX	_sprA05_57
		SPR_IDX	_sprA05_56
		SPR_IDX	_sprA05_57
		SPR_IDX	_sprA05_58
		SPR_IDX	_sprA05_59
		SPR_IDX	_sprA05_5A
		SPR_IDX	_sprA05_5B
		SPR_IDX	_sprA05_5C
		SPR_IDX	_sprA05_5D
		SPR_IDX	_sprA05_5E
		SPR_IDX	_sprA05_5F
		SPR_IDX	_sprA05_60
		SPR_IDX	_sprA05_61
		SPR_IDX	_sprA05_62
		SPR_IDX	_sprA05_63
		SPR_IDX	_sprA05_64
		SPR_IDX	_sprA05_65
		SPR_IDX	_sprA05_66
		SPR_IDX	_sprA05_67
		SPR_IDX	_sprA05_68
		SPR_IDX	_sprA05_69
		SPR_IDX	_sprA05_6A
		SPR_IDX	_sprA05_6B
		SPR_IDX	_sprA05_6C
		SPR_IDX	_sprA05_6D
		SPR_IDX	_sprA05_6E
		SPR_IDX	_sprA05_6F
		SPR_IDX	_sprA05_70
		SPR_IDX	_sprA05_71
		SPR_IDX	_sprA05_72
		SPR_IDX	_sprA05_73
		SPR_IDX	_sprA05_74
		SPR_IDX	_sprA05_75
		SPR_IDX	_sprA05_77
		SPR_IDX	_sprA05_77
		SPR_IDX	_sprA05_79
		SPR_IDX	_sprA05_79
		SPR_IDX	_sprA05_7A
		SPR_IDX	_sprA05_7B
; NOTE: the same case for these projectile... most objects are animated in
; 4 frame as rotaded sprite. but 3 out of 7 objects doesn't
;
		SPR_IDX	_sprA05_7C	; bottle
		SPR_IDX	_sprA05_7D
		SPR_IDX	_sprA05_7E
		SPR_IDX	_sprA05_7F
		SPR_IDX	_sprA05_80	; key
		SPR_IDX	_sprA05_81
		SPR_IDX	_sprA05_82
		SPR_IDX	_sprA05_83
		SPR_IDX	_sprA05_84	; coat rack
		SPR_IDX	_sprA05_85
		SPR_IDX	_sprA05_86
		SPR_IDX	_sprA05_87
		SPR_IDX	_sprA05_88	; hammer
		SPR_IDX	_sprA05_89
		SPR_IDX	_sprA05_8A
		SPR_IDX	_sprA05_8B
; TODO: animate
;
		SPR_IDX	_sprA05_8F	; 8C pan
		SPR_IDX	_sprA05_8F	; 8D
		SPR_IDX	_sprA05_8F	; 8E
		SPR_IDX	_sprA05_8F	; 8F
		SPR_IDX	_sprA05_93	; 90 rock
		SPR_IDX	_sprA05_93	; 91
		SPR_IDX	_sprA05_93	; 92
		SPR_IDX	_sprA05_93	; 93
		SPR_IDX	_sprA05_97	; 94 brick
		SPR_IDX	_sprA05_97	; 95
		SPR_IDX	_sprA05_97	; 96
		SPR_IDX	_sprA05_97	; 97

		SPR_LIB_SIZE	_spr_libA05

		SPR_LIB_START	_spr_libA06

		SPR_IDX	_sprA08_00
		SPR_IDX	_sprA08_01
		SPR_IDX	_sprA08_02
		SPR_IDX	_sprA08_03
		SPR_IDX	_sprA06_04
		SPR_IDX	_sprA06_05
		SPR_IDX	_sprA06_06
		SPR_IDX	_sprA06_07
		SPR_IDX	_sprA06_08
		SPR_IDX	_sprA06_09
		SPR_IDX	_sprA06_0A
		SPR_IDX	_sprA06_0B
		SPR_IDX	_sprA06_0C
		SPR_IDX	_sprA06_0D
		SPR_IDX	_sprA06_0E
		SPR_IDX	_sprA06_0F
		SPR_IDX	_sprA06_10
		SPR_IDX	_sprA06_11
		SPR_IDX	_sprA06_12
		SPR_IDX	_sprA06_13
		SPR_IDX	_sprA06_14
		SPR_IDX	_sprA06_15	; NOTE, animation of spear for elephant
		SPR_IDX	_sprA06_16	; with dir DOWN, never used. there are
		SPR_IDX	_sprA06_17	; no such enemies in this game
		SPR_IDX	_sprA06_18	;
		SPR_IDX	_sprA06_19	; all unused
		SPR_IDX	_sprA06_1A
		SPR_IDX	_sprA06_1B
		SPR_IDX	_sprA06_1C
		SPR_IDX	_sprA06_1D
		SPR_IDX	_sprA06_1E
		SPR_IDX	_sprA06_1F
		SPR_IDX	_sprA06_20
		SPR_IDX	_sprA06_21
		SPR_IDX	_sprA06_22
		SPR_IDX	_sprA06_23
; NOTE: odd sprite, dir DOWN with sword strike down, the sword tile
; put a lot way lower than even the shadow of the ninja (lol)
; maybe this was done by purpose (to not to overlap a lot of sprites)
; or maybe just bug..
		SPR_IDX	_sprA06_24
		SPR_IDX	_sprA06_25
		SPR_IDX	_sprA06_26
		SPR_IDX	_sprA06_27
		SPR_IDX	_sprA06_28
		SPR_IDX	_sprA06_29
		SPR_IDX	_sprA06_2A
		SPR_IDX	_sprA06_2B
		SPR_IDX	_sprA06_2C
		SPR_IDX	_sprA06_2D
		SPR_IDX	_sprA06_2E
		SPR_IDX	_sprA06_2F
		SPR_IDX	_sprA06_30
		SPR_IDX	_sprA06_31
		SPR_IDX	_sprA06_32
		SPR_IDX	_sprA06_33
		SPR_IDX	_sprA06_34
		SPR_IDX	_sprA06_35
		SPR_IDX	_sprA06_36
		SPR_IDX	_sprA06_37
		SPR_IDX	_sprA06_38
		SPR_IDX	_sprA06_39
		SPR_IDX	_sprA06_3A
		SPR_IDX	_sprA06_3B
		SPR_IDX	_sprA06_3C
		SPR_IDX	_sprA06_3D
		SPR_IDX	_sprA06_3E
		SPR_IDX	_sprA06_3F
		SPR_IDX	_sprA06_40
		SPR_IDX	_sprA06_41
		SPR_IDX	_sprA06_42
		SPR_IDX	_sprA06_43
		SPR_IDX	_sprA06_44
		SPR_IDX	_sprA06_45
		SPR_IDX	_sprA06_46
		SPR_IDX	_sprA06_47
		SPR_IDX	_sprA06_48
		SPR_IDX	_sprA06_49
		SPR_IDX	_sprA06_4A
		SPR_IDX	_sprA06_4B
		SPR_IDX	_sprA06_4C
		SPR_IDX	_sprA06_4D
		SPR_IDX	_sprA06_4E
		SPR_IDX	_sprA06_51
		SPR_IDX	_sprA06_50
		SPR_IDX	_sprA06_51
		SPR_IDX	_sprA06_52
		SPR_IDX	_sprA06_53
		SPR_IDX	_sprA06_54
		SPR_IDX	_sprA06_55
		SPR_IDX	_sprA06_56
		SPR_IDX	_sprA06_57
		SPR_IDX	_sprA06_58
		SPR_IDX	_sprA06_59
		SPR_IDX	_sprA06_5A
		SPR_IDX	_sprA06_5B
		SPR_IDX	_sprA06_5C
		SPR_IDX	_sprA06_5D
		SPR_IDX	_sprA06_5E
		SPR_IDX	_sprA06_5F
		SPR_IDX	_sprA06_60
		SPR_IDX	_sprA06_61	; FIX, sprite $D2 shifted 4 pixels left
		SPR_IDX	_sprA06_62
		SPR_IDX	_sprA06_63
		SPR_IDX	_sprA06_64
		SPR_IDX	_sprA06_65
		SPR_IDX	_sprA06_66
		SPR_IDX	_sprA06_67
		SPR_IDX	_sprA06_68
		SPR_IDX	_sprA06_69
		SPR_IDX	_sprA06_6A
		SPR_IDX	_sprA06_6B
		SPR_IDX	_sprA06_6C
		SPR_IDX	_sprA06_6D
; NOTE: the second type of sprites here used as an optimization for
; very large objects with large parts being the same, so they decide
; to split such sprites and keep only one copy of common data and
; then just using pointer links to them.
; however, most of the time such method (if used) draws the same single
; sprites! in this game they used such optimization only once! rest of
; objects even if using this sprites type, doesn't have it split, only
; single data chunks...
;
; NOTE: as noted before, one of the reasons is it seems they made a little
; bug in sprite engine, so they has to fix sprites to avoid this. probably
; this set of sprites added later in the dev process and not finished at
; all... also one of the reasons may be speed issues with split chunks
; single chunks works faster after all, and there is an issue with sprite
; glitches because of that in the released version.
;
		SPR_LIB_SIZE	_spr_libA06

		SPR_LIB_START	_spr_libB06

		SPR_IDX	_sprB06_C0
		SPR_IDX	_sprB06_C1
		SPR_IDX	_sprB06_C2
		SPR_IDX	_sprB06_C3
		SPR_IDX	_sprB06_C4
		SPR_IDX	_sprB06_C5
		SPR_IDX	_sprB06_C6
		SPR_IDX	_sprB06_C7
		SPR_IDX	_sprB06_C8
		SPR_IDX	_sprB06_C9
		SPR_IDX	_sprB06_CA
		SPR_IDX	_sprB06_CB
		SPR_IDX	_sprB06_CC
		SPR_IDX	_sprB06_CD
		SPR_IDX	_sprB06_CE
		SPR_IDX	_sprB06_CF
		SPR_IDX	_sprB06_D0
		SPR_IDX	_sprB06_D1
		SPR_IDX	_sprB06_D2
		SPR_IDX	_sprB06_D3
		SPR_IDX	_sprB06_D4
		SPR_IDX	_sprB06_D5
		SPR_IDX	_sprB06_D6
		SPR_IDX	_sprB06_D7
; NOTE: there are no object of such type set the DOWN direction
; so there is no usage for corresponding sprites...
;
		SPR_IDX	_sprB06_D8
		SPR_IDX	_sprB06_D9
		SPR_IDX	_sprB06_DA	; unused
		SPR_IDX	_sprB06_DB
		SPR_IDX	_sprB06_DC
		SPR_IDX	_sprB06_DD
		SPR_IDX	_sprB06_DE	; unused
		SPR_IDX	_sprB06_DF
		SPR_IDX	_sprB06_E0
		SPR_IDX	_sprB06_E1
		SPR_IDX	_sprB06_E2	; unused
		SPR_IDX	_sprB06_E3
		SPR_IDX	_sprB06_E4
		SPR_IDX	_sprB06_E5
		SPR_IDX	_sprB06_E6
		SPR_IDX	_sprB06_E7
		SPR_IDX	_sprB06_E8
		SPR_IDX	_sprB06_E9
		SPR_IDX	_sprB06_EA
		SPR_IDX	_sprB06_EB

		SPR_LIB_SIZE	_spr_libB06

		SPR_LIB_START	_spr_libA07

		SPR_IDX	_sprA08_00
		SPR_IDX	_sprA08_01
		SPR_IDX	_sprA08_02
		SPR_IDX	_sprA08_03
		SPR_IDX	_sprA07_04
		SPR_IDX	_sprA07_07
		SPR_IDX	_sprA07_06
		SPR_IDX	_sprA07_07
		SPR_IDX	_sprA07_08
		SPR_IDX	_sprA07_09
		SPR_IDX	_sprA07_0A
		SPR_IDX	_sprA07_0B
		SPR_IDX	_sprA07_0C
		SPR_IDX	_sprA07_0F
		SPR_IDX	_sprA07_0E
		SPR_IDX	_sprA07_0F
		SPR_IDX	_sprA07_10
		SPR_IDX	_sprA07_11
		SPR_IDX	_sprA07_12
		SPR_IDX	_sprA07_13
		SPR_IDX	_sprA07_14
		SPR_IDX	_sprA07_15
		SPR_IDX	_sprA07_16
		SPR_IDX	_sprA07_17
		SPR_IDX	_sprA07_18
		SPR_IDX	_sprA07_19
		SPR_IDX	_sprA07_1A
		SPR_IDX	_sprA07_1B
		SPR_IDX	_sprA07_1C
		SPR_IDX	_sprA07_1D
		SPR_IDX	_sprA07_1E
		SPR_IDX	_sprA07_1F
		SPR_IDX	_sprA07_20
		SPR_IDX	_sprA07_21
		SPR_IDX	_sprA07_22
		SPR_IDX	_sprA07_23
		SPR_IDX	_sprA07_24
		SPR_IDX	_sprA07_25
		SPR_IDX	_sprA07_26
		SPR_IDX	_sprA07_27
		SPR_IDX	_sprA07_28
		SPR_IDX	_sprA07_29
		SPR_IDX	_sprA07_2A
		SPR_IDX	_sprA07_2B
		SPR_IDX	_sprA07_2C
		SPR_IDX	_sprA07_2D
		SPR_IDX	_sprA07_2E
		SPR_IDX	_sprA07_2F
		SPR_IDX	_sprA07_30
		SPR_IDX	_sprA07_31
		SPR_IDX	_sprA07_32
		SPR_IDX	_sprA07_33
		SPR_IDX	_sprA07_34
		SPR_IDX	_sprA07_35
		SPR_IDX	_sprA07_36
		SPR_IDX	_sprA07_37
		SPR_IDX	_sprA07_38
		SPR_IDX	_sprA07_39
		SPR_IDX	_sprA07_3A
		SPR_IDX	_sprA07_3B
		SPR_IDX	_sprA07_3C
		SPR_IDX	_sprA07_3D
		SPR_IDX	_sprA07_3E
		SPR_IDX	_sprA07_3F
		SPR_IDX	_sprA07_40
		SPR_IDX	_sprA07_41
		SPR_IDX	_sprA07_42
		SPR_IDX	_sprA07_43
		SPR_IDX	_sprA07_44
		SPR_IDX	_sprA07_45
		SPR_IDX	_sprA07_46
		SPR_IDX	_sprA07_47
		SPR_IDX	_sprA07_48
		SPR_IDX	_sprA07_49
; NOTE: the morning star projectile only 9 sprites long max (5 frames)
; here are two more frames with 10 and 11 lengths, they are unused
;
		SPR_IDX	_sprA07_4A	; unused
		SPR_IDX	_sprA07_4B	; unused
		SPR_IDX	_sprA07_4C
		SPR_IDX	_sprA07_4D
		SPR_IDX	_sprA07_4E
		SPR_IDX	_sprA07_4F
		SPR_IDX	_sprA07_50
		SPR_IDX	_sprA07_51
		SPR_IDX	_sprA07_52
		SPR_IDX	_sprA07_53
		SPR_IDX	_sprA07_54
		SPR_IDX	_sprA07_55
		SPR_IDX	_sprA07_56
		SPR_IDX	_sprA07_57
		SPR_IDX	_sprA07_58
		SPR_IDX	_sprA07_59
		SPR_IDX	_sprA07_5A
		SPR_IDX	_sprA07_5B
		SPR_IDX	_sprA07_5C
		SPR_IDX	_sprA07_5D
		SPR_IDX	_sprA07_5E
		SPR_IDX	_sprA07_5F
		SPR_IDX	_sprA07_60
		SPR_IDX	_sprA07_61
		SPR_IDX	_sprA07_62
		SPR_IDX	_sprA07_63
		SPR_IDX	_sprA07_64
		SPR_IDX	_sprA07_65
		SPR_IDX	_sprA07_66
		SPR_IDX	_sprA07_67
		SPR_IDX	_sprA07_68
		SPR_IDX	_sprA07_69
		SPR_IDX	_sprA07_6A
		SPR_IDX	_sprA07_6B
		SPR_IDX	_sprA07_6C
		SPR_IDX	_sprA07_6D
		SPR_IDX	_sprA07_6E
		SPR_IDX	_sprA07_6F
		SPR_IDX	_sprA07_70
		SPR_IDX	_sprA07_71
		SPR_IDX	_sprA07_72
		SPR_IDX	_sprA07_73
		SPR_IDX	_sprA07_74
		SPR_IDX	_sprA07_75
		SPR_IDX	_sprA07_76
		SPR_IDX	_sprA07_77
		SPR_IDX	_sprA07_78
		SPR_IDX	_sprA07_79
		SPR_IDX	_sprA07_7A
		SPR_IDX	_sprA07_7B
		SPR_IDX	_sprA07_7C
		SPR_IDX	_sprA07_7D
		SPR_IDX	_sprA07_7E
		SPR_IDX	_sprA07_7F
		SPR_IDX	_sprA07_80
		SPR_IDX	_sprA07_81
		SPR_IDX	_sprA07_82
		SPR_IDX	_sprA07_83
		SPR_IDX	_sprA07_84
		SPR_IDX	_sprA07_85
		SPR_IDX	_sprA07_86
		SPR_IDX	_sprA07_87
		SPR_IDX	_sprA07_88
		SPR_IDX	_sprA07_89
		SPR_IDX	_sprA07_8A
		SPR_IDX	_sprA07_8B
		SPR_IDX	_sprA07_8C
		SPR_IDX	_sprA07_8D

		SPR_LIB_SIZE	_spr_libA07

		SPR_LIB_START	_spr_libB07

		SPR_IDX	_sprB07_C0
		SPR_IDX	_sprB07_C1
		SPR_IDX	_sprB07_C2
		SPR_IDX	_sprB07_C3
		SPR_IDX	_sprB07_C4
		SPR_IDX	_sprB07_C5
		SPR_IDX	_sprB07_C6
		SPR_IDX	_sprB07_C7
		SPR_IDX	_sprB07_C8
		SPR_IDX	_sprB07_C9
		SPR_IDX	_sprB07_CA

		SPR_LIB_SIZE	_spr_libB07

#if SPR_SIZE_TEST==0
#if NEW_SPRITES==1
		INCLUDE		"../spr/spr_data3_new.inc"
#else
		INCLUDE		"../spr/spr_data3.inc"
#endif
#endif

		SECTION_END	"PRG4 SPRITES"

		BANK_END 2,$C000
