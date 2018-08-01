
;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		0
OPTIMIZATION	EQU		1
TWO_PLAYER_MODE	EQU		0
OOS_ACTIVE		EQU		0
NEW_SPRITES		EQU		1
SPR_SIZE_TEST	EQU		0

REGION_JP		EQU		0
REGION_EU		EQU		1
REGION			EQU		REGION_JP

PAD_A			EQU		$80
PAD_B			EQU		$40
PAD_SEL			EQU		$20
PAD_START		EQU		$10
PAD_U			EQU		$08
PAD_D			EQU		$04
PAD_L			EQU		$02
PAD_R			EQU		$01

; $0A - default
; $0E - max
DEBUG_MAX_ENEMY	EQU		$0A
; L - C
; 0 - 1 2 3 4
; 1 - 1 2 3 4 5
; 2 - 1 2 3 4 5 6 7
; 3 - 1 2 3 4 5 6
; 4 - 1 2 3 4 5
; 5 - 1
DEBUG_LEVEL		EQU		$00
DEBUG_CHKPOINT	EQU		$01
; CHR0 - 00-1F
; LIBA - 00-08
; LIBB - 00-01 (for 02, 06-08 LIBA only!)
; IDX  - 00-lib max value
DEBUG_CHR0		EQU		$01
DEBUG_LIBA		EQU		$00
DEBUG_LIBB		EQU		$00
DEBUG_IDX		EQU		$00

;--------------------A-P-U----------------------

SQUA0	EQU	$00
SQUA1	EQU	$04
TRIAN	EQU	$08
NOISE	EQU	$0C

	MAC	CHNL_PTR
		.WORD	{2}
		.BYTE	{1}
	ENDM

SMPL_FORCE	EQU	$80

	MAC	SMPL_PTR
{1}		SET	[[.-_samples_lib]>>2]
		.WORD	{2}
		.WORD	{3}
	ENDM

	MAC	ADMC
#if OPTIMIZATION==0
		.BYTE	$E0
		.BYTE	{1}_addr
		.BYTE	{1}_size
#else
	#if {1}_addr==_pcm0A_addr && {1}_size==_pcm0A_size
		.BYTE	$E4
	#endif
	#if {1}_addr==_pcm0B_addr && {1}_size==_pcm0B_size
		.BYTE	$E5
	#endif
	#if {1}_addr==_pcm1_addr && {1}_size==_pcm1_size
		.BYTE	$E6
	#endif
#endif
	ENDM

	MAC	ACMDE1
		.BYTE	$E1
		.BYTE	{1}
	ENDM

	MAC	ACMDE2
		.BYTE	$E2
		.BYTE	{1},{2}
	ENDM

	MAC	ACMDE3
		.BYTE	$E3
		.BYTE	{1}
	ENDM

	MAC	ACMDF0
		.BYTE	$F0
		.BYTE	{1}
	ENDM

	MAC	ACMDF1
		.BYTE	$F1
		.BYTE	{1}
	ENDM

	MAC	ACMDF2
		.BYTE	$F2
		.BYTE	{1}
	ENDM

	MAC	ACMDF3
		.BYTE	$F3
		.BYTE	{1}
	ENDM

	MAC	ACMDF4
		.BYTE	$F4
		.BYTE	{1}
	ENDM

	MAC	ACMDF5
		.BYTE	$F5
		.BYTE	{1}
	ENDM

	MAC	ASMPL
		.BYTE	$F6
		.BYTE	{1}
	ENDM

	MAC	AJMP
		.BYTE	$F8
		.WORD	{1}
	ENDM

	MAC	AJSR
		.BYTE	$FA
		.WORD	{1}
	ENDM

	MAC	ARET
		.BYTE	$FB
	ENDM

	MAC	ALOOP_START
		.BYTE	$FC
		.BYTE	{1}
	ENDM

	MAC	ALOOP_END
		.BYTE	$FD
	ENDM

	MAC	ASTOP
		.BYTE	$FF
	ENDM

	MAC	ADATA
		.BYTE	{1}
	ENDM

	MAC	ADATAEX
		.BYTE	{1},{2}
	ENDM

;--------------D-E-B-U-G-G-I-N-G----------------

; {1} - destination offset
; {2} - opcode size
; {3} - opcode name
;
	MAC	ASSERT_SHORT_OFS
#if DEBUG==1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS<-128
		ECHO "long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
	#if TMP_OFS>127
		ECHO "long",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

	MAC	ALERT_SHORT_OFS
#if DEBUG==1
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-{2}]
	#if TMP_OFS>=-128&&TMP_OFS<=127
		ECHO "short",{3},"at",TMP_CMD_PC,"jumps to",{1},"distance",TMP_OFS
	#endif
#endif
	ENDM

;------------S-T-R-U-C-T-U-R-E-S----------------

	MAC	_tarray
{1}		SET	.
		DS	{2}
{1}_end	SET	.
{1}_size SET [{1}_end-{1}]
	ENDM

;---------G-A-M-E--S-P-E-C-I-F-I-C--------------

	MAC		SPR_LIB_START
{1}_bank	SET	CUR_PRG_BANK
{1}		SET		.
SPR_LIB	SET		.
	ENDM

	MAC		SPR_LIB_SIZE
{1}_size	SET		[.-SPR_LIB]
	ENDM

	MAC		SPR_IDX
{1}_idx	SET		[[.-SPR_LIB]>>1]
	.WORD	{1}
	ENDM

	MAC	MUS
{1}_idx	SET	[.-_music_lib]>>1
		.WORD	{1}
	ENDM

	MAC	SND
{1}_idx	SET	[.-_snd_lib]>>1
		.WORD	{1}
	ENDM

	MAC	TXT
{3}		SET		.
		.WORD	{1}
		.BYTE	[{3}TXT_END-{3}TXT_START],$01
{3}TXT_START	SET	.
		.BYTE	{2}
{3}TXT_END		SET	.
	ENDM

_NON	EQU	-1

	MAC	OBJ_END
		.BYTE	$FF, $00
	ENDM

	MAC	ROOM
		.BYTE	$FF, $01, {1}
	ENDM

	MAC	CHECKPOINT
		.BYTE	$FF, $02
	ENDM

	MAC	OBJ_SET
		.BYTE	{1}_idx,{2},{3},{4},{5}
#if {6}!=_NON
		.BYTE	{6}
#endif
#if {7}!=_NON
		.BYTE	{7}
#endif
#if {8}!=_NON
		.BYTE	{8}
#endif
	ENDM

	MAC	TLM_PAK
{1}_idx	SET	[.-_tlm_pak_lib]
		.WORD	{1}
	ENDM

	MAC	SCR_IDX_LO
{1}_idx	SET	[.-_scr_lib_lo]
		.BYTE	<[{1}]
	ENDM

	MAC	SCR_IDX_HI
		.BYTE	>[{1}]
	ENDM

	MAC	CMD_IDX_LO
{1}_idx	SET	[.-_scmd_lib_lo]+1
		.BYTE	<[{1}]
	ENDM

	MAC	CMD_IDX_HI
		.BYTE	>[{1}]
	ENDM

	MAC	DCMD_IDX_LO
{1}_idx	SET	[.-_dcmd_lib_lo]
		.BYTE	<[{1}]
	ENDM

	MAC	DCMD_IDX_HI
		.BYTE	>[{1}]
	ENDM

	MAC	_ttrd
{1}		SET	.
{1}._ptr0:		.WORD 0
{1}._ptr1:		.WORD 0
	ENDM

	MAC	FAR_OFS
{1}_bank	SET	CUR_PRG_BANK
{1}			SET	.
	ENDM

ROOM_H	EQU	$00
ROOM_V	EQU	$01
ROOM_0	EQU	$02

DOOR_CLOSED	EQU	$00
DOOR_OPEN	EQU	$01
DOOR_TEST	EQU	$02

;---------------S-C-R-I-P-T-S-------------------

	MAC	SSTOP
		.BYTE	$00
	ENDM

	MAC	SLOOP_BEGIN
		.BYTE	_scmd01_loop_begin_idx
		.BYTE	{1}
	ENDM

	MAC	SLOOP_END
		.BYTE	_scmd02_loop_end_idx
	ENDM

	MAC	SJMPS
#if OPTIMIZATION==1
		ASSERT_SHORT_OFS	{1},2,"SJMPS"
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-1]
		.BYTE	_scmd1A_sjmps_idx
		.BYTE	TMP_OFS&$FF
#else
		.BYTE	_scmd03_sjmp_idx
		.WORD	{1}
#endif
	ENDM

	MAC	SJMP
		ALERT_SHORT_OFS		{1},3,"SJMP"
		.BYTE	_scmd03_sjmp_idx
		.WORD	{1}
	ENDM

	MAC	SJSRS
#if OPTIMIZATION==1
		ASSERT_SHORT_OFS	{1},2,"SJSRS"
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-2]
		.BYTE	_scmd1B_sjsrs_idx
		.BYTE	TMP_OFS&$FF
#else
		.BYTE	_scmd03_sjmp_idx
		.WORD	{1}
#endif
	ENDM

	MAC	SJSR
		ALERT_SHORT_OFS		{1},3,"SJSR"
		.BYTE	_scmd04_sjsr_idx
		.WORD	{1}
	ENDM

	MAC	SRET
		.BYTE	_scmd05_ret_idx
	ENDM

	MAC	SDELAY
		.BYTE	_scmd06_delay_idx
		.BYTE	{1}
	ENDM

	MAC	NJSR
		.BYTE	_scmd07_njsr_idx
		.WORD	{1}
	ENDM

	; maybe this will be little bit confusing, but at least
	; take less text lines...
	;
;	MAC	NJSRB
;		.BYTE	_scmd07_njsr_idx
;		.WORD	{1}
;		.BYTE	{2}
;	ENDM

;	MAC	NARGI
;		.BYTE	{1}_idx
;	ENDM

	MAC	NARGB
		.BYTE	{0}
	ENDM

	MAC NARGW
		.WORD	{0}
	ENDM

	MAC	SSCRIPT1_SET
		.BYTE	_scmd08_script1_set_idx
#if OPTIMIZATION==0
		.BYTE	$01
#endif
		.WORD	{1}
	ENDM

	MAC	NBG_HNDL_SET
		.BYTE	_scmd09_nbg_hndl_set_idx
		.WORD	{1}
	ENDM

	MAC	SUSPEND
		.BYTE	_scmd0A_suspend_idx
	ENDM

	MAC	SBCSS
#if OPTIMIZATION==1
		ASSERT_SHORT_OFS	{1},2,"SBCSS"
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-1]
		.BYTE	_scmd1C_bcss_idx
		.BYTE	TMP_OFS&$FF
#else
		.BYTE	_scmd0B_bcs_idx
		.WORD	{1}
#endif
	ENDM

#if OPTIMIZATION==0
	MAC	SBCS
		ALERT_SHORT_OFS		{1},3,"SBCS"
		.BYTE	_scmd0B_bcs_idx
		.WORD	{1}
	ENDM
#endif

	MAC	SBCCS
#if OPTIMIZATION==1
		ASSERT_SHORT_OFS	{1},2,"SBCCS"
TMP_CMD_PC	SET	.
TMP_OFS		SET	[{1}-TMP_CMD_PC-1]
		.BYTE	_scmd1D_bccs_idx
		.BYTE	TMP_OFS&$FF
#else
		.BYTE	_scmd0C_bcc_idx
		.WORD	{1}
#endif
	ENDM

#if OPTIMIZATION==0
	MAC	SBCC
		ALERT_SHORT_OFS		{1},3,"SBCC"
		.BYTE	_scmd0C_bcc_idx
		.WORD	{1}
	ENDM
#endif

	MAC	SSCRIPT0_OFF
		.BYTE	_scmd0A_script0_off_idx
	ENDM

	MAC	SMEM_ALU
#if OPTIMIZATION==1
		.BYTE	_scmd0E_smem_alu_idx
		.WORD	{1}
		.BYTE	{3}
#else
		.BYTE	_scmd0E_smem_alu_idx
		.WORD	{1}
		.BYTE	{2},{3}
#endif
	ENDM

SARG0	EQU	0
SARG1	EQU	1
SARG2	EQU	2

	MAC	SARG_SET
		.BYTE	_scmd0F_sarg_set_idx
		.BYTE	{1},{2}
	ENDM

	MAC	NBG_HNDL_RESET
		.BYTE	_scmd10_nbg_hndl_reset_idx
	ENDM

	MAC	SJMP_SW
		.BYTE	_scmd11_sloc_sw_idx
		.BYTE	{1}
_SW_START	SET	.
	ENDM

	MAC	SJSR_SW
		.BYTE	_scmd12_ssub_sw_idx
		.BYTE	{1}
_SW_START	SET	.
	ENDM

	MAC	SCASE
{1}_idx	SET	[[.-_SW_START]>>1]
		.WORD	{1}
	ENDM

	MAC	STORE8
#if OPTIMIZATION==1
	#if {1}<$100
;		ECHO	"store8 short at",.
		.BYTE	_scmd1C_store8s_idx
		.BYTE	{1}
		.BYTE	{2}
	#else
;		ECHO	"store8 long at",.
		.BYTE	_scmd13_store8_idx
		.WORD	{1}
		.BYTE	{2}
	#endif
#else
		.BYTE	_scmd13_store8_idx
		.WORD	{1}
		.BYTE	{2}
#endif
	ENDM

	MAC	SSCRIPT1_OFF
		.BYTE	_scmd14_script1_off_idx
#if OPTIMIZATION==0
		.BYTE	$01
#endif
	ENDM

_AND	EQU	$00
_ORA	EQU	$01
_ADC	EQU	$02

	MAC	SARG_ALU
#if OPTIMIZATION==1
		.BYTE	_scmd15_sarg_alu_idx
		.BYTE	{1},{3}
#else
		.BYTE	_scmd15_sarg_alu_idx
		.BYTE	{1},{2},{3}
#endif
	ENDM

	MAC	STORE16
#if OPTIMIZATION==1
	#if {1}<$100
		.BYTE	_scmd1D_store16s_idx
		.BYTE	{1}
		.WORD	{2}
	#else
		.BYTE	_scmd16_store16_idx
		.WORD	{1}
		.WORD	{2}
	#endif
#else
		.BYTE	_scmd16_store16_idx
		.WORD	{1}
		.WORD	{2}
#endif
	ENDM

	MAC	SBCS_BREAK
;		ALERT_SHORT_OFS		{1},3,"SBCS_BREAK"
		.BYTE	_scmd17_sbcs_break_idx
		.WORD	{1}
	ENDM

;	MAC	SBCC_BREAK
;		.BYTE	_scmd18_sbcc_break_idx
;		.WORD	{1}
;	ENDM

;	MAC	NJSR_SW
;		.BYTE	_scmd19_njsr_sw_idx
;	ENDM

	MAC	SPR_IDX_SET
		.BYTE	[[_dcmd00_spr_idx_set_idx<<3]+$20]|[{1}&7]
		.BYTE	{2}
	ENDM

	MAC	POS_X_SET
		.BYTE	[[_dcmd01_pos_x_set_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

	MAC	POS_Y_SET
		.BYTE	[[_dcmd02_pos_y_set_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

	MAC	POS_X_MOVE
		.BYTE	[[_dcmd03_pos_x_move_idx<<3]+$20]|[{1}&7]
		.BYTE	{2}
	ENDM

	MAC	POS_Y_MOVE
		.BYTE	[[_dcmd04_pos_y_move_idx<<3]+$20]|[{1}&7]
		.BYTE	{2}
	ENDM

	MAC	POS_X_DELTA_SET
		.BYTE	[[_dcmd05_pos_x_delta_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

	MAC	POS_Y_DELTA_SET
		.BYTE	[[_dcmd06_pos_y_delta_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

	MAC	POS_X_DELTA_ADD
		.BYTE	[[_dcmd07_pos_x_delta_add_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

	MAC	POS_Y_DELTA_ADD
		.BYTE	[[_dcmd08_pos_y_delta_add_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

;	MAC	SCRL_X_SET
;		.BYTE	[[_dcmd09_scrl_x_set_idx<<3]+$20]|[{1}&7]
;		.BYTE	{2},{3}
;	ENDM

	MAC	SCRL_Y_SET
		.BYTE	[[_dcmd0A_scrl_y_sey_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

;	MAC	SCRL_X_MOVE_SET
;		.BYTE	[[_dcmd0B_scrl_x_move_set_idx<<3]+$20]|[{1}&7]
;		.BYTE	{2},{3}
;	ENDM

	MAC	SCRL_Y_MOVE_SET
		.BYTE	[[_dcmd0C_scrl_y_move_set_idx<<3]+$20]|[{1}&7]
		.BYTE	{2},{3}
	ENDM

;	MAC	SCRL_X_MOVE_ADD
;		.BYTE	[[_dcmd0D_scrl_x_move_add_idx<<3]+$20]|[{1}&7]
;		.BYTE	{2},{3}
;	ENDM

;	MAC	SCRL_Y_MOVE_ADD
;		.BYTE	[[_dcmd0E_scrl_y_move_add_idx<<3]+$20]|[{1}&7]
;		.BYTE	{2},{3}
;	ENDM

	MAC	SPR_IDX_INC
		.BYTE	[[_dcmd0F_spr_idx_inc_idx<<3]+$20]|[{1}&7]
	ENDM

	MAC	SPR_IDX_DEC
		.BYTE	[[_dcmd10_spr_idx_dec_idx<<3]+$20]|[{1}&7]
	ENDM

	MAC	SPR_IDX_ADD_IMM
		.BYTE	[[_dcmd11_spr_idx_add_imm_idx<<3]+$20]|[{1}&7]
		.BYTE	{2}
	ENDM

;	MAC	BYTE_D5_ADD
;		.BYTE	[[_dcmd12_scrl_x_page_add_idx<<3]+$20]|[{1}&7]
;		.BYTE	{2}
;	ENDM

;	MAC	BYTE_D6_ADD
;		.BYTE	[[_dcmd13_scrl_y_page_add_idx<<3]+$20]|[{1}&7]
;		.BYTE	{2}
;	ENDM

	MAC	POS_MOVE_STOP
		.BYTE	[[_dcmd14_pos_move_stop_idx<<3]+$20]|[{1}&7]
	ENDM

	MAC	SCRL_MOVE_STOP
		.BYTE	[[_dcmd15_scrl_move_stop_idx<<3]+$20]|[{1}&7]
	ENDM


;----------------C-O-M-M-O-N--------------------

	MAC BANK_START
CUR_PRG_BANK	SET {1}
CUR_BANK_START	SET .
CUR_SEC_START	SET $FFFFFFFF
		ECHO "BANK",CUR_PRG_BANK," ORG ",[CUR_BANK_START>>12],"{"
	ENDM

STUB_SIZE		EQU	11
LAST_STUB_SIZE	EQU	6

	MAC	BANK_END
	#if {1}=$00
_total_free	SET 0
	#endif
_bank{1}_free	SET	[{2}-.-STUB_SIZE]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>{2}-STUB_SIZE
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
	#if .<{2}-STUB_SIZE
		ORG		{2}-STUB_SIZE-1
		.BYTE	$FF
	#endif
		ORG		{2}-STUB_SIZE
		SEI
		INC		$FFFC
		JMP		RESET
		.WORD	$FFF5
		.WORD	$FFFF
	ENDM

	MAC	LAST_BANK_END
_bank{1}_free	SET	[{2}-.-LAST_STUB_SIZE]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>[{2}-LAST_STUB_SIZE]
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
		ECHO "-------------";
		ECHO "total ROM free =",_total_free
		ECHO "zero RAM free =",ZERO_RAM_FREE
		ECHO "stack RAM free =",STACK_RAM_FREE
		ECHO "general RAM free =",GENERAL_RAM_FREE
#if SPR_SIZE_TEST==1
SPR_LIB_SIZES SET _spr_libA00_size+_spr_libA01_size+_spr_libA02_size+_spr_libA03_size+_spr_libA04_size+_spr_libA05_size+_spr_libA06_size+_spr_libA07_size+_spr_libA08_size+_spr_libB02_size+_spr_libB06_size+_spr_libB07_size+_spr_libB08_size
		ECHO "sprite data size =",SPR_DATA_SIZE,"sprite libs size =",SPR_LIB_SIZES,"total =",SPR_DATA_SIZE+SPR_LIB_SIZES
#endif
		ECHO ""
	#if .<{2}-LAST_STUB_SIZE
		ORG		{2}-LAST_STUB_SIZE-1
		.BYTE	$FF
	#endif
		ORG		{2}-LAST_STUB_SIZE
		.WORD NMI
		.WORD RESET
		.WORD IRQ
	ENDM

	MAC SECTION_START
#if CUR_SEC_START == $FFFFFFFF
CUR_SEC_START	SET	.
#else
		ECHO "WARNING! previous block isn't closed!"
#endif
	ENDM

	MAC SECTION_END
#if CUR_SEC_START != $FFFFFFFF
_CUR_SEC_END	SET .
		ECHO " * block size =",_CUR_SEC_END-CUR_SEC_START,"[",{1},"]"
CUR_SEC_START	SET $FFFFFFFF
#else
		ECHO "WARNING! there is no block start!"
#endif
	ENDM
