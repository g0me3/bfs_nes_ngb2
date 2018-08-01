
		ORG $8000

		BANK_START $03

		INCLUDE "../lvl/lvl1.inc"
		INCLUDE "../lvl/lvl3.inc"
		INCLUDE	"../lvl/lvl4.inc"

		BANK_END 3,$C000
