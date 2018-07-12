
		ORG $8000

		BANK_START $01

		SECTION_START

; =============== S C R I P T ==========================s====================
; base level handler with some set of common operations as well as set
; of specific options for every particular room. all level handlers have
; mostly the same structure and consists of two parts:
; - initialization part. usually setup once per stage at the beginning
; and set all global level parameters, setting up background scripted
; and native routines, run players scripts, also handles the continue
; checkpoints
; - room handlers state machine. every room have its own unique settings
; as well and may contain additional adjusting global settings. the main
; function of room handlers is to test if player reaches the exit points
; and then jump to a corresponding new room handler. every room handler
; usually setup its own set of doors, entry points and exits.
;
		FAR_OFS			_scr01_lvl1_handler
		NJSR			_nsub_get_checkpoint_tmp_idx	; here is the beginning of the stage
		NJSR			_nsub_read_mem					; we start from here either if begin the stage
			NARGW		_tmp_idx						; or continue after game over
		SJSR_SW	$04										;
		SCASE			_lvl1_room_initA				; entering level from checkpoints need to
		SCASE			_lvl1_room_initA				; reinit the current stage from given position
		SCASE			_lvl1_room_initA				; so we have here a number of cases as much
		SCASE			_lvl1_room_initB				; checkpoints in a particular stage
; NEW, some hacky way to have just one reoutine for setting the player starting
; position, adds additional 5 bytes for every such replacement, but won't be
; noticeable in overall size reduction.
		STORE16			_room_exits_ptr,_lvl1_room_starts
		NJSR			_nsub_players_room_start_pos_init_from_ptr
		NJSR			_nsub_read_mem					; and finally go to main room handler, according
			NARGW		_tmp_idx						; also to a starting checkpoint position.
		SJMP_SW			$04								; in this case, four checkpoints started from room0
		SCASE			_lvl1_room0_handler				; room3, room1 and room 6 accordingly.
		SCASE			_lvl1_room3_handler
		SCASE			_lvl1_room1_handler
		SCASE			_lvl1_room6_handler

; NEW, using new common function to handle exits, this is a hacky
; way to not to use two separate functions. $00 here is that there is
; no data to skip before the starting point tables.
_lvl1_room_starts:
		.BYTE	$00
		.BYTE	$4E,$71,$00					; when room is entered, set the starting position
		.BYTE	$79,$46,$03					; of players based on checkpoint index (read internally)
		.BYTE	$39,$6E,$03					; by _nsub
		.BYTE	$6E,$34,$00

; =============== S C R I P T  S U B R O U T I N E =====s====================
; NEW, merged all common room handling code in one routine with
; custom native functions to test exits and set the starting position
;
_ssub_common_room_loop:
		SJSR			_ssub_room_entry_pal_fade_in	; and finally fade in to start the game
_sloc_14048:
		SDELAY			$01								; the handler here did all its work, now he just
		NJSR			_nsub_players_room_exit_test_from_ptr	; constantly test the players positions to check
		SBCCS			_sloc_14048						; if they got to the exit, the return door's idx
; NOTE: doors and exit points are separate entities. doors only blocks the exits which usually always
; active, but doors may be open only in particular conditions.
		SJSR			_ssub_room_exit_pal_fade_out	; now we have a new door idx in _tmp_idx so we could
		NJSR			_nsub_players_room_start_pos_init_from_ptr	; select player positions for the next room
		SRET

; =============== S C R I P T ==========================s====================
; NOTE, when entering the actual room, set current room index to inform object
; manager where to start to fetch objects data. next draw the room and load the
; doors handlers.
;
_lvl1_room0_handler:
		NJSR			_nsub_room_init
			NARGB		$00								; room idx
			NARGB		ROOM_H,$02,$03					; room data location
			NARGW		_lvl1_room0_prize_seq			; prize sequences
			NARGW		_lvl1_room0_exits				; exits data
			NARGW		_lvl1_room0_doors				; doors data
		SJSRS			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx						; and go to selected room handler, so as we seee
		SJMP_SW			$03								; the warping logic between rooms handled purely
		SCASE			_lvl1_room1_handler				; with these scripts
		SCASE			_lvl1_room2_handler
		SCASE			_lvl1_room3_handler

_lvl1_room0_exits:
		.BYTE	$03							; a number of exit entries
		.BYTE	$F8,$01,$88,$03				; set of door coordinates in full format
		.BYTE	$00,$04,$B0,$03
		.BYTE	$80,$02,$08,$03
		.BYTE	$3C,$6E,$03					; first two parameters are packed X and Y pos of beamer
		.BYTE	$82,$74,$01					; after entering the room, the third one is for relative
		.BYTE	$4E,$5A,$00					; position of the catcher according to entry direction
_lvl1_room0_doors:
		.BYTE	$02,$80,$03,$D0,$00,DOOR_CLOSED
		.BYTE	$02,$10,$03,$80,$01,DOOR_TEST
		.BYTE	$02,$80,$03,$20,$00,DOOR_TEST
		.BYTE	$03,$E0,$03,$B0,$01,DOOR_TEST
		.BYTE	$FF
_lvl1_room0_prize_seq:
		.BYTE	$17,$13,$13,$00

; =============== S C R I P T ==========================s====================
; NOTE, rest of the room handlers are mostly the same, differs only in additional
; paletter/CHR bank settings and stuff
;
_lvl1_room1_handler:
		NJSR			_nsub_room_init
			NARGB		$01								; room idx
			NARGB		ROOM_H,$00,$03					; room data location
			NARGW		_lvl1_room1_prize_seq			; prize sequences
			NARGW		_lvl1_room1_exits				; exits data
			NARGW		_lvl1_room1_doors				; doors data
		SJSRS			_ssub_common_room_loop
		SJMPS			_lvl1_room0_handler

_lvl1_room1_exits:
		.BYTE	$01							; only one exit from this room here
		.BYTE	$00,$02,$88,$03				; so one exit point as well, and
		.BYTE	$42,$6E,$01					; one destination room, return back to room0
_lvl1_room1_doors:
		.BYTE	$01,$E0,$03,$80,$01,DOOR_TEST
		.BYTE	$00,$F0,$03,$80,$01,DOOR_OPEN
		.BYTE	$FF
_lvl1_room1_prize_seq:
		.BYTE	$15,$16,$14,$14,$14,$16,$16,$00

; =============== S C R I P T ==========================s====================
_lvl1_room2_handler:
		NJSR			_nsub_room_init
			NARGB		$02								; room idx
			NARGB		ROOM_V,$04,$02					; room data location
			NARGW		_lvl1_room2_prize_seq			; prize sequences
			NARGW		_lvl1_room2_exits				; exits data
			NARGW		_lvl1_room2_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0D
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_patch_pal_load			; sometimes
			NARGB		$06								; we need to fix sprites palette as
			NARGW		_lvl1_full_palA+$18				; well as change sprites CHR bank
		NJSR			_nsub_mmc1_chr0_set				; because there are other enemies may appear
			NARGB		$04
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl1_room0_handler
		SCASE			_lvl1_room3_handler

_lvl1_room2_exits:
		.BYTE	$02
		.BYTE	$F8,$03,$B0,$03
		.BYTE	$F8,$03,$40,$02
		.BYTE	$7C,$74,$03
		.BYTE	$7C,$46,$03
_lvl1_room2_doors:
		.BYTE	$04,$10,$03,$B0,$01,DOOR_TEST
		.BYTE	$04,$C0,$03,$90,$00,DOOR_OPEN
		.BYTE	$04,$C0,$02,$60,$00,DOOR_OPEN
		.BYTE	$04,$10,$02,$40,$01,DOOR_TEST
_lvl1_room2_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl1_room3_handler:
		NJSR			_nsub_room_init
			NARGB		$03								; room idx
			NARGB		ROOM_H,$02,$02					; room data location
			NARGW		_lvl1_room3_prize_seq			; prize sequences
			NARGW		_lvl1_room3_exits				; exits data
			NARGW		_lvl1_room3_doors				; doors data
		STORE16			_lvl_collisions_ptr,_lvl1_collisionsA	; when return from prev room restore collision data
		SJSR			_lvl1_room_chrA_set				; if you return back from room6 you
		SJSR			_ssub_common_room_loop			; need to restore back CHR banks and palettes
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$04
		SCASE			_lvl1_room0_handler
		SCASE			_lvl1_room2_handler
		SCASE			_lvl1_room4_handler
		SCASE			_lvl1_room6_handler

_lvl1_room3_exits:
		.BYTE	$04
		.BYTE	$80,$02,$F8,$02
		.BYTE	$00,$04,$40,$02
		.BYTE	$F8,$01,$C0,$02
		.BYTE	$80,$02,$08,$02
		.BYTE	$4E,$62,$02
		.BYTE	$82,$46,$01
		.BYTE	$3C,$56,$03
		.BYTE	$6E,$38,$00
_lvl1_room3_doors:
		.BYTE	$03,$E0,$02,$40,$01,DOOR_TEST
		.BYTE	$03,$70,$02,$B0,$00,DOOR_OPEN
		.BYTE	$02,$10,$02,$C0,$01,DOOR_TEST
		.BYTE	$02,$80,$02,$E0,$00,DOOR_TEST
		.BYTE	$02,$80,$02,$20,$00,DOOR_TEST
		.BYTE	$FF
_lvl1_room3_prize_seq:
; REGION, changed in the EU version
;		.BYTE	$17,$14,$18,$13,$00
		.BYTE	$17,$18,$18,$18,$14,$13,$00
; -

; =============== S C R I P T ==========================s====================
_lvl1_room4_handler:
		NJSR			_nsub_room_init
			NARGB		$04								; room idx
			NARGB		ROOM_0,$01,$02					; room data location
			NARGW		_lvl1_room4_prize_seq			; prize sequences
			NARGW		_lvl1_room4_exits				; exits data
			NARGW		_lvl1_room4_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl1_room3_handler

_lvl1_room4_exits:
		.BYTE	$01
		.BYTE	$00,$02,$C0,$02
		.BYTE	$42,$56,$01
_lvl1_room4_doors:
		.BYTE	$01,$E0,$02,$C0,$01,DOOR_TEST
		.BYTE	$01,$70,$02,$90,$00,DOOR_OPEN
_lvl1_room4_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
; this is the last room with boss. note, the boss area locks scrolls not here
; but rather by the boss object itself..
;
_lvl1_room5_handler:
		NJSR			_nsub_room_init
			NARGB		$05								; room idx
			NARGB		ROOM_V,$02,$00					; room data location
			NARGW		_lvl1_room5_prize_seq			; prize sequences
			NARGW		_lvl1_room5_exits				; exits data
			NARGW		_lvl1_room5_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl1_room6_handler

_lvl1_room5_exits:
		.BYTE	$01
		.BYTE	$80,$02,$B8,$01
		.BYTE	$6E,$22,$02
_lvl1_room5_doors:
		.BYTE	$02,$80,$01,$A0,$00,DOOR_TEST
_lvl1_room5_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl1_room6_handler:
		NJSR			_nsub_room_init
			NARGB		$06								; room idx
			NARGB		ROOM_0,$03,$01					; room data location
			NARGW		_lvl1_room6_prize_seq			; prize sequences
			NARGW		_lvl1_room6_exits				; exits data
			NARGW		_lvl1_room6_doors				; doors data
		STORE16			_lvl_collisions_ptr,_lvl1_collisionsB	; coll data for this room is different
		SJSRS			_lvl1_room_chrB_set				; this is a corridor before the court
		SJSR			_ssub_common_room_loop			; room, here we need to change CHR and pal
		NJSR			_nsub_read_mem					; also there is another bg collision table
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl1_room5_handler				; we can exith this corridor back or continue
		SCASE			_lvl1_room3_handler				; to the main boss

_lvl1_room6_exits:
		.BYTE	$02
		.BYTE	$80,$03,$18,$01
		.BYTE	$80,$03,$E8,$01
		.BYTE	$4E,$32,$00
		.BYTE	$4E,$42,$02
_lvl1_room6_doors:
		.BYTE	$03,$80,$01,$30,$00,DOOR_TEST
		.BYTE	$03,$80,$01,$D0,$00,DOOR_TEST
_lvl1_room6_prize_seq:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl1_room_chrA_set:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$02
		NJSR			_nsub_full_pal_load
			NARGW		_lvl1_full_palA
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl1_room_initA:
		SJSRS			_lvl1_room_chrA_set
; WARNING! make sure, collisions data also reside in the same bank as the
; rest of the level data!
		STORE16			_lvl_collisions_ptr,_lvl1_collisionsA
		SJMPS			_lvl1_common_init

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl1_room_chrB_set:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$07
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$03
		NJSR			_nsub_full_pal_load
			NARGW		_lvl1_full_palB
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl1_room_initB:
		SJSRS			_lvl1_room_chrB_set
		STORE16			_lvl_collisions_ptr,_lvl1_collisionsB

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
; common initialization for whole level, all levels does the same initializers.
; here set macro/attrs data for level draw, level layouts and room data library
_lvl1_common_init:
		NJSR			_nsub_level_init
			NARGB		_lvl1_bank
			NARGW		_lvl1_macroA_tbl
			NARGW		_lvl1_macroB_tbl
			NARGW		_lvl1_macroC_tbl
			NARGW		_lvl1_macroD_tbl
			NARGW		_lvl1_attrs_tbl
			NARGW		_lvl1_rooms_lib
			NARGW		_lvl1_objects_list
			NARGB		_mus0_idx

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
; NEW, common level initializators goes here
;
_lvl_common_initA:
		NBG_HNDL_SET	_nbgsub_room_obj_handler		; set the room object handler as a native bg sub

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
; NEW, the rest of levels uses custom bg handlers, so goes here.
;
_lvl_common_initB:
		NJSR			_nsub_beamer_handler_start		; start players control script 08, for beamer
		NJSR			_nsub_catcher_handler_start		; and 0A for catcher
		SSCRIPT1_SET	_scr_common_pause_handler		; secondary script of current level thread set to pause handler
		NJSR			_nsub_lvl_room_objects_init		; and initialize objects offset according to last checkpoint
		SRET

; =============== S C R I P T ==========================s====================
_scr_common_pause_handler:
		SDELAY			$01								; common pause handler for all levels
#if DEBUG==1
		NJSR			_nsub_ingame_select_input_test	; presumably stage complete test were here
		SBCCS			_skip_stage_select
		SJSR			_ssub_room_exit_pal_fade_out_ex
		SSTOP
_skip_stage_select:
#endif
		NJSR			_nsub_ingame_start_input_test	; just wait for START is pressed
		SBCCS			_scr_common_pause_handler		; and then play pause sound
		NJSR			_nsub_apu_snd_load				; and run pause native handler
			NARGB		_snd03_idx
		SJSR			_ssub_room_exit_pal_fade_out_ex	; when exit, loop back to wait for input
		NJSR			_nsub_ingame_pause_handler
		SJSR			_ssub_room_entry_pal_fade_in_ex
		SJMPS			_scr_common_pause_handler

_lvl1_full_palA:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$1A,$17,$0F,$37,$27,$17,$0F,$30,$05,$17
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$2B,$0F,$0F,$10,$17,$07
_lvl1_full_palB:
		.BYTE	$0F,$30,$17,$07,$0F,$30,$05,$07,$0F,$10,$17,$07,$0F,$30,$10,$00
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$31,$25,$0F,$0F,$10,$17,$07

		SECTION_END	"LVL1 SCRIPTS"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr02_lvl2_handler
		NJSR			_nsub_get_checkpoint_tmp_idx	; same as for lvl1
		NJSR			_nsub_read_mem					; now we have 4 checkpoints here
			NARGW		_tmp_idx
		SJSR_SW	$05
		SCASE			_lvl2_room_initA
		SCASE			_lvl2_room_initA
		SCASE			_lvl2_room_initA
		SCASE			_lvl2_room_initA
		SCASE			_lvl2_room_initB
		STORE16			_room_exits_ptr,_lvl2_room_starts
		NJSR			_nsub_players_room_start_pos_init_from_ptr
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$05
		SCASE			_lvl2_room0_handler
		SCASE			_lvl2_room3_handler
		SCASE			_lvl2_room5_handler
		SCASE			_lvl2_room7_handler
		SCASE			_lvl2_room9_handler

_lvl2_room_starts:
		.BYTE	$00
		.BYTE	$06,$D1,$01
		.BYTE	$2E,$D9,$00
		.BYTE	$2E,$79,$00
		.BYTE	$83,$46,$01
		.BYTE	$A3,$06,$01

; =============== S C R I P T ==========================s====================
_lvl2_room0_handler:
		NJSR			_nsub_room_init
			NARGB		$00								; room idx
			NARGB		ROOM_0,$00,$06					; room data location
			NARGW		_lvl2_room0_prize_seq			; prize sequences
			NARGW		_lvl2_room0_exits				; exits data
			NARGW		_lvl2_room0_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room1_handler

_lvl2_room0_exits:
		.BYTE	$01
		.BYTE	$80,$00,$08,$06
		.BYTE	$0E,$B9,$00
_lvl2_room0_doors:
		.BYTE	$00,$80,$06,$10,$02,DOOR_TEST
_lvl2_room0_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_room1_handler:
		NJSR			_nsub_room_init
			NARGB		$01								; room idx
			NARGB		ROOM_V,$00,$04					; room data location
			NARGW		_lvl2_room1_prize_seq			; prize sequences
			NARGW		_lvl2_room1_exits				; exits data
			NARGW		_lvl2_room1_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room2_handler

_lvl2_room1_exits:
		.BYTE	$01
		.BYTE	$78,$00,$08,$04
		.BYTE	$0E,$73,$00
_lvl2_room1_doors:
		.BYTE	$00,$80,$04,$20,$02,DOOR_TEST
_lvl2_room1_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_room2_handler:
		NJSR			_nsub_room_init
			NARGB		$02								; room idx
			NARGB		ROOM_0,$00,$03					; room data location
			NARGW		_lvl2_room2_prize_seq			; prize sequences
			NARGW		_lvl2_room2_exits				; exits data
			NARGW		_lvl2_room2_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room3_handler

_lvl2_room2_exits:
		.BYTE	$01
		.BYTE	$78,$00,$08,$03
		.BYTE	$2E,$D9,$00
_lvl2_room2_doors:
		.BYTE	$00,$80,$03,$10,$02,DOOR_TEST
		.BYTE	$00,$80,$03,$D0,$02,DOOR_CLOSED
_lvl2_room2_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_room3_handler:
		NJSR			_nsub_room_init
			NARGB		$03								; room idx
			NARGB		ROOM_0,$01,$06					; room data location
			NARGW		_lvl2_room3_prize_seq			; prize sequences
			NARGW		_lvl2_room3_exits				; exits data
			NARGW		_lvl2_room3_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room4_handler

_lvl2_room3_exits:
		.BYTE	$01
		.BYTE	$80,$01,$08,$06
		.BYTE	$2E,$B9,$00
_lvl2_room3_doors:
		.BYTE	$01,$80,$06,$20,$02,DOOR_TEST
_lvl2_room3_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_room4_handler:
		NJSR			_nsub_room_init
			NARGB		$04								; room idx
			NARGB		ROOM_V,$01,$04					; room data location
			NARGW		_lvl2_room4_prize_seq			; prize sequences
			NARGW		_lvl2_room4_exits				; exits data
			NARGW		_lvl2_room4_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl2_room5_handler
		SCASE			_lvl2_room4_handler

_lvl2_room4_exits:
		.BYTE	$02
		.BYTE	$B0,$01,$08,$04
		.BYTE	$50,$01,$08,$04
		.BYTE	$2E,$79,$00
		.BYTE	$2E,$B9,$00
_lvl2_room4_doors:
		.BYTE	$01,$B0,$04,$20,$02,DOOR_TEST
		.BYTE	$01,$50,$04,$20,$02,DOOR_TEST
		.BYTE	$FF
_lvl2_room4_prize_seq:
		.BYTE	$1D,$1D,$20,$1D,$1D,$1E,$00

; =============== S C R I P T ==========================s====================
_lvl2_room5_handler:
		NJSR			_nsub_room_init
			NARGB		$05								; room idx
			NARGB		ROOM_V,$01,$02					; room data location
			NARGW		_lvl2_room5_prize_seq			; prize sequences
			NARGW		_lvl2_room5_exits				; exits data
			NARGW		_lvl2_room5_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room6_handler

_lvl2_room5_exits:
		.BYTE	$01
		.BYTE	$F8,$01,$40,$02
		.BYTE	$45,$46,$01
_lvl2_room5_doors:
		.BYTE	$01,$E0,$02,$40,$03,DOOR_TEST
		.BYTE	$FF
_lvl2_room5_prize_seq:
		.BYTE	$20,$1D,$1E,$20,$1D,$1E,$00

; =============== S C R I P T ==========================s====================
_lvl2_room6_handler:
		NJSR			_nsub_room_init
			NARGB		$06								; room idx
			NARGB		ROOM_H,$02,$02					; room data location
			NARGW		_lvl2_room6_prize_seq			; prize sequences
			NARGW		_lvl2_room6_exits				; exits data
			NARGW		_lvl2_room6_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room7_handler

_lvl2_room6_exits:
		.BYTE	$01
		.BYTE	$F8,$03,$40,$02
		.BYTE	$83,$46,$01
_lvl2_room6_doors:
		.BYTE	$03,$E0,$02,$40,$03,DOOR_TEST
		.BYTE	$02,$20,$02,$40,$03,DOOR_CLOSED
		.BYTE	$FF
_lvl2_room6_prize_seq:
		.BYTE	$20,$20,$1F,$00

; =============== S C R I P T ==========================s====================
_lvl2_room7_handler:
		NJSR			_nsub_room_init
			NARGB		$07								; room idx
			NARGB		ROOM_0,$04,$02					; room data location
			NARGW		_lvl2_room7_prize_seq			; prize sequences
			NARGW		_lvl2_room7_exits				; exits data
			NARGW		_lvl2_room7_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room8_handler

_lvl2_room7_exits:
		.BYTE	$01
		.BYTE	$80,$04,$08,$02
		.BYTE	$8E,$39,$00
_lvl2_room7_doors:
		.BYTE	$04,$80,$02,$20,$02,DOOR_TEST
		.BYTE	$FF
_lvl2_room7_prize_seq:
		.BYTE	$1E,$1F,$1E,$20,$00

; =============== S C R I P T ==========================s====================
_lvl2_room8_handler:
		NJSR			_nsub_room_init
			NARGB		$08								; room idx
			NARGB		ROOM_V,$04,$00					; room data location
			NARGW		_lvl2_room8_prize_seq			; prize sequences
			NARGW		_lvl2_room8_exits				; exits data
			NARGW		_lvl2_room8_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_room9_handler

_lvl2_room8_exits:
		.BYTE	$01
		.BYTE	$00,$05,$48,$00
		.BYTE	$A3,$06,$01
_lvl2_room8_doors:
		.BYTE	$04,$E0,$00,$40,$03,DOOR_TEST
		.BYTE	$FF
_lvl2_room8_prize_seq:
		.BYTE	$1E,$1F,$1D,$20,$00

; =============== S C R I P T ==========================s====================
_lvl2_room9_handler:
		NJSR			_nsub_room_init
			NARGB		$09								; room idx
			NARGB		ROOM_0,$05,$00					; room data location
			NARGW		_lvl2_room9_prize_seq			; prize sequences
			NARGW		_lvl2_room9_exits				; exits data
			NARGW		_lvl2_room9_doors				; doors data
		STORE16			_lvl_collisions_ptr,_lvl2_collisionsB
		NJSR			_nsub_mmc1_chr1_set				; here we enter the train section
			NARGB		$0B								; currently only part of the tiles are changed
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_roomA_handler

_lvl2_room9_exits:
		.BYTE	$01
		.BYTE	$80,$05,$D8,$00
		.BYTE	$AE,$26,$02
_lvl2_room9_doors:
		.BYTE	$05,$80,$00,$D0,$04,DOOR_TEST
_lvl2_room9_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_roomA_handler:
		NJSR			_nsub_room_init
			NARGB		$0A								; room idx
			NARGB		ROOM_V,$05,$01					; room data location
			NARGW		_lvl2_roomA_prize_seq			; prize sequences
			NARGW		_lvl2_roomA_exits				; exits data
			NARGW		_lvl2_roomA_doors				; doors data
		NJSR			_nsub_bg_pal_load				; further on the train the bg pal
			NARGW		_lvl2_bg_palA					; need to be updated
		NBG_HNDL_SET	_nbgsub_lvl2_roomA				; also here we have custom bg native sub
		SSCRIPT1_SET	_scr_lvl2_roomA_secondary		; and new secondary script handler
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_roomB_handler

_lvl2_roomA_exits:
		.BYTE	$01
		.BYTE	$80,$05,$E8,$02
		.BYTE	$AE,$66,$02
_lvl2_roomA_doors:
		.BYTE	$05,$80,$01,$20,$04,DOOR_CLOSED
		.BYTE	$05,$80,$02,$D0,$04,DOOR_TEST
_lvl2_roomA_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_roomB_handler:
		NJSR			_nsub_room_init
			NARGB		$0B								; room idx
			NARGB		ROOM_V,$05,$03					; room data location
			NARGW		_lvl2_roomB_prize_seq			; prize sequences
			NARGW		_lvl2_roomB_exits				; exits data
			NARGW		_lvl2_roomB_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl2_roomC_handler

_lvl2_roomB_exits:
		.BYTE	$01
		.BYTE	$78,$05,$E8,$04
		.BYTE	$AE,$A6,$02
_lvl2_roomB_doors:
		.BYTE	$05,$80,$03,$20,$04,DOOR_CLOSED
		.BYTE	$05,$80,$04,$D0,$04,DOOR_TEST
_lvl2_roomB_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl2_roomC_handler:
		NJSR			_nsub_room_init
			NARGB		$0C								; room idx
			NARGB		ROOM_V,$05,$05					; room data location
			NARGW		_lvl2_roomC_prize_seq			; prize sequences
			NARGW		$0000							; there is no exits here, add dummy for convinience
			NARGW		_lvl2_roomC_doors				; doors data
; NOTE, although, the boss room is double sized they used two parts separately for boss..
; ..room and for empty tracks when you beat it.
		STORE8			_cur_room_x_pageB,$05
		SJSR			_ssub_room_entry_pal_fade_in
		SUSPEND											; there is no doors to go further, script stop here

_lvl2_roomC_doors:
		.BYTE	$05,$80,$05,$20,$04,DOOR_CLOSED
_lvl2_roomC_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_scr_lvl2_roomA_secondary:
		SLOOP_BEGIN		$80								; when entering the train, regular pause
		SMEM_ALU		_apu_mus_volume,_ADC,$FF		; secondary script replaced with this,
		SDELAY			$01								; which first disables  the music
		SLOOP_END
		NJSR			_nsub_apu_mus_load				; plays train sound
			NARGB		$FF
		NJSR			_nsub_apu_snd_load				; and then start another music
			NARGB		_snd13_idx
		SDELAY			$A0
		STORE8			_apu_mus_volume,$FF
		NJSR			_nsub_apu_mus_load
			NARGB		_mus4_idx
		SJMP			_scr_common_pause_handler		; and finally goes to the regular pause seq

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl2_room_initA:
		NJSR			_nsub_mmc1_chr1_set				; tunnel/train level also has two different
			NARGB		$0A								; collision tables but since you couldn't
		STORE16			_lvl_collisions_ptr,_lvl2_collisionsA	; return  back there is no need to
		SJMPS			_lvl2_common_init				; manually patch in transitions between rooms

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl2_room_initB:
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$0B
		STORE16			_lvl_collisions_ptr,_lvl2_collisionsB

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl2_common_init:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0C
		NJSR			_nsub_full_pal_load
			NARGW		_lvl2_full_pal
		NJSR			_nsub_level_init
			NARGB		_lvl2_bank
			NARGW		_lvl2_macroA_tbl
			NARGW		_lvl2_macroB_tbl
			NARGW		_lvl2_macroC_tbl
			NARGW		_lvl2_macroD_tbl
			NARGW		_lvl2_attrs_tbl
			NARGW		_lvl2_rooms_lib
			NARGW		_lvl2_objects_list
			NARGB		_mus6_idx
		SJMP			_lvl_common_initA				; common initialization for all levels

_lvl2_full_pal:
		.BYTE	$0F,$30,$10,$00,$0F,$10,$00,$07,$0F,$10,$00,$08,$0F,$10,$00,$17
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$10,$00,$0F,$0F,$36,$27,$0F
_lvl2_bg_palA:
		.BYTE	$0F,$30,$10,$00,$0F,$10,$00,$07,$0F,$27,$17,$07,$0F,$01,$00,$07
; NOTE, this is a leftover from full palette for train part of the level 2
; however, the final version uses only first part of it for background
; as you may see, the only difference in sprites palettes is two last palettes
; are swapped. this causes the ghost heads on the train looks less contrast
;_unused_2:
;		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$2B,$0F,$0F,$10,$17,$07

; =============== S U B R O U T I N E ======n================================
_nbgsub_lvl2_roomA:
		LDA		_trds_args0
		CLC
		ADC		#$01
		CMP		#$03
		BCC		loc_147FC
		LDA		#$00
loc_147FC:
		STA		_trds_args0
		ASL
		ASL
		ADC		#<[_lvl2_roomA_patch_pal_list]
		PHA
		LDA		#$00
		ADC		#>[_lvl2_roomA_patch_pal_list]
		TAX
		PLA
		LDY		#$02
		JSR		_patch_pal_load
		JMP		_nbgsub_room_obj_handler

_lvl2_roomA_patch_pal_list:
		.BYTE	$0F,$0F,$07,$0F
		.BYTE	$0F,$07,$0F,$0F
		.BYTE	$0F,$0F,$0F,$07

		SECTION_END	"LVL2 SCRIPTS"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr03_lvl3_handler
		NJSR			_nsub_get_checkpoint_tmp_idx
		SJSR			_lvl3_common_init
		STORE16			_room_exits_ptr,_lvl3_room_starts
		NJSR			_nsub_players_room_start_pos_init_from_ptr
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$07
		SCASE			_lvl3_room0_handler
		SCASE			_lvl3_room2_handler
		SCASE			_lvl3_room5_handler
		SCASE			_lvl3_room8_handler
		SCASE			_lvl3_roomB_handler
		SCASE			_lvl3_roomE_handler
		SCASE			_lvl3_room14_handler

_lvl3_room_starts:
		.BYTE	$00
		.BYTE	$0E,$34,$00
		.BYTE	$4E,$06,$02
		.BYTE	$AE,$06,$02
		.BYTE	$CE,$06,$02
		.BYTE	$2E,$66,$02
		.BYTE	$4E,$66,$02
		.BYTE	$AE,$66,$02

; =============== S C R I P T ==========================s====================
_lvl3_room0_handler:
		NJSR			_nsub_room_init
			NARGB		$00								; room idx
			NARGB		ROOM_H,$00,$01					; room data location
			NARGW		_lvl3_room0_prize_seq			; prize sequences
			NARGW		_lvl3_room0_exits				; exits data
			NARGW		_lvl3_room0_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl3_room1_handler

_lvl3_room0_exits:
		.BYTE	$01
		.BYTE	$80,$01,$08,$01
		.BYTE	$2E,$18,$00
_lvl3_room0_doors:
		.BYTE	$01,$80,$01,$20,$05,DOOR_TEST
		.BYTE	$00,$90,$01,$D0,$06,DOOR_CLOSED
_lvl3_room0_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room1_handler:
		NJSR			_nsub_room_init
			NARGB		$01								; room idx
			NARGB		ROOM_H,$00,$00					; room data location
			NARGW		_lvl3_room1_prize_seq			; prize sequences
			NARGW		_lvl3_room1_exits				; exits data
			NARGW		_lvl3_room1_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room2_handler
		SCASE			_lvl3_room0_handler

_lvl3_room1_exits:
		.BYTE	$02
		.BYTE	$80,$00,$08,$00
		.BYTE	$80,$01,$F8,$00
		.BYTE	$4E,$02,$02
		.BYTE	$2E,$22,$02
_lvl3_room1_doors:
		.BYTE	$00,$80,$00,$20,$06,DOOR_TEST
		.BYTE	$01,$80,$00,$D0,$05,DOOR_TEST
_lvl3_room1_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room2_handler:
		NJSR			_nsub_room_init
			NARGB		$02								; room idx
			NARGB		ROOM_V,$02,$00					; room data location
			NARGW		_lvl3_room2_prize_seq			; prize sequences
			NARGW		_lvl3_room2_exits				; exits data
			NARGW		_lvl3_room2_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room3_handler
		SCASE			_lvl3_room1_handler

_lvl3_room2_exits:
		.BYTE	$02
		.BYTE	$30,$02,$F8,$01
		.BYTE	$80,$02,$08,$00
		.BYTE	$44,$42,$02
		.BYTE	$0E,$02,$02
_lvl3_room2_doors:
		.BYTE	$02,$80,$00,$20,$06,DOOR_TEST
		.BYTE	$02,$40,$00,$B0,$07,DOOR_OPEN
		.BYTE	$02,$80,$00,$E0,$05,DOOR_OPEN
		.BYTE	$02,$B0,$01,$50,$05,DOOR_OPEN
		.BYTE	$02,$70,$01,$80,$07,DOOR_OPEN
		.BYTE	$02,$30,$01,$D0,$05,DOOR_TEST
		.BYTE	$FF
_lvl3_room2_prize_seq:
		.BYTE	$25,$25,$25,$28,$28,$00

; =============== S C R I P T ==========================s====================
_lvl3_room3_handler:
		NJSR			_nsub_room_init
			NARGB		$03								; room idx
			NARGB		ROOM_H,$02,$02					; room data location
			NARGW		_lvl3_room3_prize_seq			; prize sequences
			NARGW		_lvl3_room3_exits				; exits data
			NARGW		_lvl3_room3_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room4_handler
		SCASE			_lvl3_room2_handler

_lvl3_room3_exits:
		.BYTE	$02
		.BYTE	$D0,$03,$08,$02
		.BYTE	$30,$02,$08,$02
		.BYTE	$78,$38,$00
		.BYTE	$44,$38,$00
_lvl3_room3_doors:
		.BYTE	$02,$30,$02,$20,$05,DOOR_TEST
		.BYTE	$02,$40,$02,$80,$07,DOOR_OPEN
		.BYTE	$02,$C0,$02,$50,$05,DOOR_OPEN
		.BYTE	$03,$50,$02,$50,$05,DOOR_OPEN
		.BYTE	$03,$C0,$02,$80,$07,DOOR_OPEN
		.BYTE	$03,$D0,$02,$20,$05,DOOR_TEST
_lvl3_room3_prize_seq:
		.BYTE	$FF


; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl3_room_modeA_init:
		NJSR			_nsub_apu_mus_load
			NARGB		_mus4_idx

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl3_room_modeA_init_ex:
		NJSR			_nsub_mmc1_chr0_set				; here is the special room with
			NARGB		$0F								; mid-boss, as well as special
		NJSR			_nsub_patch_pal_load			; music and palettes for it
			NARGB		$07
			NARGW		_lvl3_roomsAE_patch_pal
		SRET

; =============== S C R I P T ==========================s====================
_lvl3_room4_handler:
		NJSR			_nsub_room_init
			NARGB		$04								; room idx
			NARGB		ROOM_V,$03,$00					; room data location
			NARGW		_lvl3_room4_prize_seq			; prize sequences
			NARGW		_lvl3_room4_exits				; exits data
			NARGW		_lvl3_room4_doors				; doors data
		SJSRS			_lvl3_room_modeA_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_apu_mus_load				; restore regular music here
			NARGB		_mus7_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room5_handler
		SCASE			_lvl3_room3_handler

_lvl3_room4_exits:
		.BYTE	$02
		.BYTE	$80,$03,$08,$00
		.BYTE	$D0,$03,$F8,$01
		.BYTE	$AE,$02,$02
		.BYTE	$78,$42,$02
_lvl3_room4_doors:
		.BYTE	$03,$80,$01,$50,$05,DOOR_OPEN
		.BYTE	$03,$40,$01,$80,$07,DOOR_OPEN
		.BYTE	$03,$D0,$01,$D0,$05,DOOR_TEST
		.BYTE	$03,$80,$00,$20,$06,DOOR_TEST
_lvl3_room4_prize_seq:
		.BYTE	$FF


; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl3_room_modeB_init:
		NJSR			_nsub_mmc1_chr0_set				; restore regular level CHR bank
			NARGB		$0E
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_lvl3_full_pal+$1C				; restore also old palette portion
		SRET

; =============== S C R I P T ==========================s====================
_lvl3_room5_handler:
		NJSR			_nsub_room_init
			NARGB		$05								; room idx
			NARGB		ROOM_V,$05,$00					; room data location
			NARGW		_lvl3_room5_prize_seq			; prize sequences
			NARGW		_lvl3_room5_exits				; exits data
			NARGW		_lvl3_room5_doors				; doors data
		SJSRS			_lvl3_room_modeB_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room6_handler
		SCASE			_lvl3_room4_handler

_lvl3_room5_exits:
		.BYTE	$02
		.BYTE	$D0,$05,$F8,$01
		.BYTE	$80,$05,$08,$00
		.BYTE	$B8,$42,$02
		.BYTE	$6E,$02,$02
_lvl3_room5_doors:
		.BYTE	$05,$80,$00,$20,$06,DOOR_TEST
		.BYTE	$05,$70,$00,$B0,$07,DOOR_OPEN
		.BYTE	$05,$B0,$00,$E0,$05,DOOR_OPEN
		.BYTE	$05,$80,$01,$50,$05,DOOR_OPEN
		.BYTE	$05,$40,$01,$80,$07,DOOR_OPEN
		.BYTE	$05,$D0,$01,$D0,$05,DOOR_TEST
		.BYTE	$FF
_lvl3_room5_prize_seq:
; REGION, changed in the EU version
;		.BYTE	$28,$28,$26,$00
		.BYTE	$28,$26,$26,$00
; -

; =============== S C R I P T ==========================s====================
_lvl3_room6_handler:
		NJSR			_nsub_room_init
			NARGB		$06								; room idx
			NARGB		ROOM_H,$04,$02					; room data location
			NARGW		_lvl3_room6_prize_seq			; prize sequences
			NARGW		_lvl3_room6_exits				; exits data
			NARGW		_lvl3_room6_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room7_handler
		SCASE			_lvl3_room5_handler

_lvl3_room6_exits:
		.BYTE	$02
		.BYTE	$30,$04,$08,$02
		.BYTE	$D0,$05,$08,$02
		.BYTE	$84,$38,$00
		.BYTE	$B8,$38,$00
_lvl3_room6_doors:
		.BYTE	$04,$30,$02,$20,$05,DOOR_TEST
		.BYTE	$04,$40,$02,$80,$07,DOOR_OPEN
		.BYTE	$04,$D0,$02,$50,$05,DOOR_OPEN
		.BYTE	$05,$30,$02,$50,$05,DOOR_OPEN
		.BYTE	$05,$C0,$02,$80,$07,DOOR_OPEN
		.BYTE	$05,$D0,$02,$20,$05,DOOR_TEST
_lvl3_room6_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room7_handler:
		NJSR			_nsub_room_init
			NARGB		$07								; room idx
			NARGB		ROOM_V,$04,$00					; room data location
			NARGW		_lvl3_room7_prize_seq			; prize sequences
			NARGW		_lvl3_room7_exits				; exits data
			NARGW		_lvl3_room7_doors				; doors data
		SJSR			_lvl3_room_modeA_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_apu_mus_load
			NARGB		_mus7_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room8_handler
		SCASE			_lvl3_room6_handler

_lvl3_room7_exits:
		.BYTE	$02
		.BYTE	$80,$04,$08,$00
		.BYTE	$30,$04,$F8,$01
		.BYTE	$CE,$02,$02
		.BYTE	$84,$42,$02
_lvl3_room7_doors:
		.BYTE	$04,$80,$00,$20,$06,DOOR_TEST
		.BYTE	$04,$B0,$01,$50,$05,DOOR_OPEN
		.BYTE	$04,$70,$01,$80,$07,DOOR_OPEN
		.BYTE	$04,$30,$01,$D0,$05,DOOR_TEST
_lvl3_room7_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room8_handler:
		NJSR			_nsub_room_init
			NARGB		$08								; room idx
			NARGB		ROOM_V,$06,$00					; room data location
			NARGW		_lvl3_room8_prize_seq			; prize sequences
			NARGW		_lvl3_room8_exits				; exits data
			NARGW		_lvl3_room8_doors				; doors data
		SJSR			_lvl3_room_modeB_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room9_handler
		SCASE			_lvl3_room7_handler

_lvl3_room8_exits:
		.BYTE	$02
		.BYTE	$30,$06,$F8,$01
		.BYTE	$80,$06,$08,$00
		.BYTE	$C4,$42,$02
		.BYTE	$8E,$02,$02
_lvl3_room8_doors:
		.BYTE	$06,$80,$00,$20,$06,DOOR_TEST
		.BYTE	$06,$40,$00,$B0,$07,DOOR_OPEN
		.BYTE	$06,$80,$00,$E0,$05,DOOR_OPEN
		.BYTE	$06,$B0,$01,$50,$05,DOOR_OPEN
		.BYTE	$06,$70,$01,$80,$07,DOOR_OPEN
		.BYTE	$06,$30,$01,$D0,$05,DOOR_TEST
		.BYTE	$FF
_lvl3_room8_prize_seq:
		.BYTE	$27,$27,$28,$00

; =============== S C R I P T ==========================s====================
_lvl3_room9_handler:
		NJSR			_nsub_room_init
			NARGB		$09								; room idx
			NARGB		ROOM_H,$06,$02					; room data location
			NARGW		_lvl3_room9_prize_seq			; prize sequences
			NARGW		_lvl3_room9_exits				; exits data
			NARGW		_lvl3_room9_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_roomA_handler
		SCASE			_lvl3_room8_handler

_lvl3_room9_exits:
		.BYTE	$02
		.BYTE	$D0,$07,$08,$02
		.BYTE	$30,$06,$08,$02
		.BYTE	$F8,$38,$00
		.BYTE	$C4,$38,$00
_lvl3_room9_doors:
		.BYTE	$06,$30,$02,$20,$05,DOOR_TEST
		.BYTE	$06,$40,$02,$80,$07,DOOR_OPEN
		.BYTE	$06,$C0,$02,$50,$05,DOOR_OPEN
		.BYTE	$07,$50,$02,$50,$05,DOOR_OPEN
		.BYTE	$07,$C0,$02,$80,$07,DOOR_OPEN
		.BYTE	$07,$D0,$02,$20,$05,DOOR_TEST
_lvl3_room9_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
; NOTE: when it exit from mini-boss room it restores only music, the
; rest of the settings like CHR bank and palette for sprites leave intact
; this is because the game logic assumes that room you already visited and
; cleared have no enemies, so doesn't matter if there is no proper sprites
; settings anymore there...
;
_lvl3_roomA_handler:
		NJSR			_nsub_room_init
			NARGB		$0A								; room idx
			NARGB		ROOM_V,$07,$00					; room data location
			NARGW		_lvl3_roomA_prize_seq			; prize sequences
			NARGW		_lvl3_roomA_exits				; exits data
			NARGW		_lvl3_roomA_doors				; doors data
		SJSR			_lvl3_room_modeA_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_apu_mus_load
			NARGB		_mus7_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_roomB_handler
		SCASE			_lvl3_room9_handler

_lvl3_roomA_exits:
		.BYTE	$02
		.BYTE	$80,$07,$08,$00
		.BYTE	$C0,$07,$F8,$01
		.BYTE	$2E,$62,$02
		.BYTE	$F8,$42,$02
_lvl3_roomA_doors:
		.BYTE	$07,$80,$00,$20,$06,DOOR_TEST
		.BYTE	$07,$80,$01,$50,$05,DOOR_OPEN
		.BYTE	$07,$40,$01,$80,$07,DOOR_OPEN
		.BYTE	$07,$D0,$01,$D0,$05,DOOR_TEST
_lvl3_roomA_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
; NOTE, to the previous note, it only need to restore proper CHR/pal settings
; for rooms where enemies still existing..
;
_lvl3_roomB_handler:
		NJSR			_nsub_room_init
			NARGB		$0B								; room idx
			NARGB		ROOM_V,$01,$03					; room data location
			NARGW		_lvl3_roomB_prize_seq			; prize sequences
			NARGW		_lvl3_roomB_exits				; exits data
			NARGW		_lvl3_roomB_doors				; doors data
		SJSR			_lvl3_room_modeB_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_roomC_handler
		SCASE			_lvl3_roomA_handler

_lvl3_roomB_exits:
		.BYTE	$02
		.BYTE	$D0,$01,$F8,$04
		.BYTE	$80,$01,$08,$03
		.BYTE	$38,$A2,$02
		.BYTE	$EE,$02,$02
_lvl3_roomB_doors:
		.BYTE	$01,$80,$03,$20,$06,DOOR_TEST
		.BYTE	$01,$70,$03,$B0,$07,DOOR_OPEN
		.BYTE	$01,$B0,$03,$E0,$05,DOOR_OPEN
		.BYTE	$01,$80,$04,$50,$05,DOOR_OPEN
		.BYTE	$01,$40,$04,$80,$07,DOOR_OPEN
		.BYTE	$01,$D0,$04,$D0,$05,DOOR_TEST
_lvl3_roomB_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_roomC_handler:
		NJSR			_nsub_room_init
			NARGB		$0C								; room idx
			NARGB		ROOM_H,$00,$05					; room data location
			NARGW		_lvl3_roomC_prize_seq			; prize sequences
			NARGW		_lvl3_roomC_exits				; exits data
			NARGW		_lvl3_roomC_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_roomD_handler
		SCASE			_lvl3_roomB_handler

_lvl3_roomC_exits:
		.BYTE	$02
		.BYTE	$30,$00,$08,$05
		.BYTE	$D0,$01,$08,$05
		.BYTE	$04,$98,$00
		.BYTE	$38,$98,$00
_lvl3_roomC_doors:
		.BYTE	$00,$30,$05,$20,$05,DOOR_TEST
		.BYTE	$00,$40,$05,$80,$07,DOOR_OPEN
		.BYTE	$00,$C0,$05,$50,$05,DOOR_OPEN
		.BYTE	$01,$50,$05,$50,$05,DOOR_OPEN
		.BYTE	$01,$C0,$05,$80,$07,DOOR_OPEN
		.BYTE	$01,$D0,$05,$20,$05,DOOR_TEST
		.BYTE	$FF
_lvl3_roomC_prize_seq:
		.BYTE	$28,$24,$24,$24,$28,$00

; =============== S C R I P T ==========================s====================
_lvl3_roomD_handler:
		NJSR			_nsub_room_init
			NARGB		$0D								; room idx
			NARGB		ROOM_V,$00,$03					; room data location
			NARGW		_lvl3_roomD_prize_seq			; prize sequences
			NARGW		_lvl3_roomD_exits				; exits data
			NARGW		_lvl3_roomD_doors				; doors data
		SJSR			_lvl3_room_modeA_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_apu_mus_load
			NARGB		_mus7_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_roomE_handler
		SCASE			_lvl3_roomC_handler

_lvl3_roomD_exits:
		.BYTE	$02
		.BYTE	$80,$00,$08,$03
		.BYTE	$30,$00,$F8,$04
		.BYTE	$4E,$62,$02
		.BYTE	$04,$A2,$02
_lvl3_roomD_doors:
		.BYTE	$00,$80,$03,$20,$06,DOOR_TEST
		.BYTE	$00,$B0,$04,$50,$05,DOOR_OPEN
		.BYTE	$00,$70,$04,$80,$07,DOOR_OPEN
		.BYTE	$00,$30,$04,$D0,$05,DOOR_TEST
_lvl3_roomD_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_roomE_handler:
		NJSR			_nsub_room_init
			NARGB		$0E								; room idx
			NARGB		ROOM_V,$02,$03					; room data location
			NARGW		_lvl3_roomE_prize_seq			; prize sequences
			NARGW		_lvl3_roomE_exits				; exits data
			NARGW		_lvl3_roomE_doors				; doors data
		SJSR			_lvl3_room_modeB_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_roomF_handler
		SCASE			_lvl3_roomD_handler

_lvl3_roomE_exits:
		.BYTE	$02
		.BYTE	$30,$02,$F8,$04
		.BYTE	$80,$02,$08,$03
		.BYTE	$44,$A2,$02
		.BYTE	$0E,$62,$02
_lvl3_roomE_doors:
		.BYTE	$02,$80,$03,$20,$06,DOOR_TEST
		.BYTE	$02,$80,$03,$E0,$05,DOOR_OPEN
		.BYTE	$02,$40,$03,$B0,$07,DOOR_OPEN
		.BYTE	$02,$B0,$04,$50,$05,DOOR_OPEN
		.BYTE	$02,$70,$04,$80,$07,DOOR_OPEN
		.BYTE	$02,$30,$04,$D0,$05,DOOR_TEST
		.BYTE	$FF
_lvl3_roomE_prize_seq:
		.BYTE	$28,$24,$24,$24,$24,$24,$24,$25,$00

; =============== S C R I P T ==========================s====================
_lvl3_roomF_handler:
		NJSR			_nsub_room_init
			NARGB		$0F								; room idx
			NARGB		ROOM_H,$02,$05					; room data location
			NARGW		_lvl3_roomF_prize_seq			; prize sequences
			NARGW		_lvl3_roomF_exits				; exits data
			NARGW		_lvl3_roomF_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room10_handler
		SCASE			_lvl3_roomE_handler

_lvl3_roomF_exits:
		.BYTE	$02
		.BYTE	$D0,$03,$08,$05
		.BYTE	$30,$02,$08,$05
		.BYTE	$78,$98,$00
		.BYTE	$44,$98,$00
_lvl3_roomF_doors:
		.BYTE	$02,$30,$05,$20,$05,DOOR_TEST
		.BYTE	$02,$40,$05,$80,$07,DOOR_OPEN
		.BYTE	$02,$D0,$05,$50,$05,DOOR_OPEN
		.BYTE	$03,$30,$05,$50,$05,DOOR_OPEN
		.BYTE	$03,$C0,$05,$80,$07,DOOR_OPEN
		.BYTE	$03,$D0,$05,$20,$05,DOOR_TEST
_lvl3_roomF_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room10_handler:
		NJSR			_nsub_room_init
			NARGB		$10								; room idx
			NARGB		ROOM_V,$03,$03					; room data location
			NARGW		_lvl3_room10_prize_seq			; prize sequences
			NARGW		_lvl3_room10_exits				; exits data
			NARGW		_lvl3_room10_doors				; doors data
		SJSR			_lvl3_room_modeA_init
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_apu_mus_load
			NARGB		_mus7_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room14_handler
		SCASE			_lvl3_roomF_handler

_lvl3_room10_exits:
		.BYTE	$02
		.BYTE	$80,$03,$08,$03
		.BYTE	$C0,$03,$F8,$04
		.BYTE	$AE,$62,$02
		.BYTE	$78,$A2,$02
_lvl3_room10_doors:
		.BYTE	$03,$80,$03,$20,$06,DOOR_TEST
		.BYTE	$03,$80,$04,$50,$05,DOOR_OPEN
		.BYTE	$03,$40,$04,$80,$07,DOOR_OPEN
		.BYTE	$03,$D0,$04,$D0,$05,DOOR_TEST
_lvl3_room10_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
; NOTE: for some reason, there is a gap between 10 and 14 room indexes.
; why there are no 11, 12 and 13 is unknown
;
_lvl3_room14_handler:
		NJSR			_nsub_room_init
			NARGB		$14								; room idx
			NARGB		ROOM_V,$05,$03					; room data location
			NARGW		_lvl3_room14_prize_seq			; prize sequences
			NARGW		_lvl3_room14_exits				; exits data
			NARGW		_lvl3_room14_doors				; doors data
		SJSR			_lvl3_room_modeA_init_ex
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room15_handler
		SCASE			_lvl3_room10_handler

_lvl3_room14_exits:
		.BYTE	$02
		.BYTE	$D0,$05,$F8,$04
		.BYTE	$80,$05,$08,$03
		.BYTE	$B8,$A2,$02
		.BYTE	$6E,$62,$02
_lvl3_room14_doors:
		.BYTE	$05,$80,$03,$20,$06,DOOR_TEST
		.BYTE	$05,$70,$03,$B0,$07,DOOR_OPEN
		.BYTE	$05,$B0,$03,$E0,$05,DOOR_OPEN
		.BYTE	$05,$80,$04,$50,$05,DOOR_OPEN
		.BYTE	$05,$40,$04,$80,$07,DOOR_OPEN
		.BYTE	$05,$D0,$04,$D0,$05,DOOR_TEST
_lvl3_room14_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room15_handler:
		NJSR			_nsub_room_init
			NARGB		$15								; room idx
			NARGB		ROOM_H,$04,$05					; room data location
			NARGW		_lvl3_room15_prize_seq			; prize sequences
			NARGW		_lvl3_room15_exits				; exits data
			NARGW		_lvl3_room15_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room16_handler
		SCASE			_lvl3_room14_handler

_lvl3_room15_exits:
		.BYTE	$02
		.BYTE	$30,$04,$08,$05
		.BYTE	$D0,$05,$08,$05
		.BYTE	$84,$98,$00
		.BYTE	$B8,$98,$00
_lvl3_room15_doors:
		.BYTE	$04,$30,$05,$20,$05,DOOR_TEST
		.BYTE	$04,$40,$05,$80,$07,DOOR_OPEN
		.BYTE	$04,$C0,$05,$50,$05,DOOR_OPEN
		.BYTE	$05,$50,$05,$50,$05,DOOR_OPEN
		.BYTE	$05,$C0,$05,$80,$07,DOOR_OPEN
		.BYTE	$05,$D0,$05,$20,$05,DOOR_TEST
_lvl3_room15_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room16_handler:
		NJSR			_nsub_room_init
			NARGB		$16								; room idx
			NARGB		ROOM_V,$04,$03					; room data location
			NARGW		_lvl3_room16_prize_seq			; prize sequences
			NARGW		_lvl3_room16_exits				; exits data
			NARGW		_lvl3_room16_doors				; doors data
		NJSR			_nsub_apu_mus_load				; start intermedia music
			NARGB		_mus1_idx
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl3_room17_handler
		SCASE			_lvl3_room15_handler

_lvl3_room16_exits:
		.BYTE	$02
		.BYTE	$30,$04,$08,$03
		.BYTE	$30,$04,$F8,$04
		.BYTE	$06,$56,$01
		.BYTE	$84,$A2,$02
_lvl3_room16_doors:
		.BYTE	$04,$B0,$04,$70,$07,DOOR_OPEN
		.BYTE	$04,$80,$04,$A0,$05,DOOR_OPEN
		.BYTE	$04,$30,$04,$D0,$05,DOOR_TEST
		.BYTE	$04,$30,$03,$20,$05,DOOR_TEST
_lvl3_room16_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl3_room17_handler:
		NJSR			_nsub_room_init
			NARGB		$17								; room idx
			NARGB		ROOM_0,$00,$02					; room data location
			NARGW		_lvl3_room17_prize_seq			; prize sequences
			NARGW		$0000							; also dummy here
			NARGW		_lvl3_room17_doors				; doors data
		SJSR			_lvl3_room_modeB_init
; REDUNDANT, this is a final boss/cutscene room for LVL3, there is a door in it
; but it is always closed. you couldn't exit this door as well because
; there is an automated scripted cutscene with forced jump to the next
; level. so this branch never executed at all. may be removed.
;		STORE16			_room_exits_ptr,_lvl3_room17_exits
;		SJSR			_ssub_common_room_loop
;		NJSR			_nsub_read_mem
;			NARGW		_tmp_idx
;		SJMP_SW			$01
;		SCASE			_lvl3_room16_handler
		SJSR			_ssub_room_entry_pal_fade_in
		SUSPEND

;_lvl3_room17_exits:
;		.BYTE	$01
;		.BYTE	$30,$00,$F8,$02
;		.BYTE	$84,$63,$02

_lvl3_room17_doors:
;		.BYTE	$00,$30,$02,$E0,$05,DOOR_CLOSED
_lvl3_room17_prize_seq:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl3_common_init:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$10
		NJSR			_nsub_full_pal_load
			NARGW		_lvl3_full_pal
		STORE16			_lvl_collisions_ptr,_lvl3_collisions
		NJSR			_nsub_level_init
			NARGB		_lvl3_bank
			NARGW		_lvl3_macroA_tbl
			NARGW		_lvl3_macroB_tbl
			NARGW		_lvl3_macroC_tbl
			NARGW		_lvl3_macroD_tbl
			NARGW		_lvl3_attrs_tbl
			NARGW		_lvl3_rooms_lib
			NARGW		_lvl3_objects_list
			NARGB		_mus7_idx
		SJMP			_lvl_common_initA

_lvl3_full_pal:
		.BYTE	$0F,$30,$10,$00,$0F,$19,$10,$17,$0F,$37,$27,$17,$0F,$30,$10,$1A
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$37,$27,$17,$0F,$36,$25,$0F
_lvl3_roomsAE_patch_pal:
		.BYTE	$0F,$36,$2B,$0F

		SECTION_END	"LVL3 SCRIPTS"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr04_lvl4_handler
		NJSR			_nsub_get_checkpoint_tmp_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJSR			_lvl4_common_init
		STORE16			_room_exits_ptr,_lvl4_room_starts
		NJSR			_nsub_players_room_start_pos_init_from_ptr
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$06
		SCASE			_lvl4_room0_handler
		SCASE			_lvl4_room1_handler
		SCASE			_lvl4_room4_handler
		SCASE			_lvl4_room5_handler
		SCASE			_lvl4_room6_handler
		SCASE			_lvl4_room8_handler

_lvl4_room_starts:
		.BYTE	$00
		.BYTE	$26,$AE,$01
		.BYTE	$3A,$90,$03
		.BYTE	$03,$66,$02
		.BYTE	$08,$34,$01
		.BYTE	$51,$27,$02
		.BYTE	$79,$54,$00

; =============== S C R I P T ==========================s====================
_lvl4_room0_handler:
		NJSR			_nsub_room_init
			NARGB		$00								; room idx
			NARGB		ROOM_0,$01,$05					; room data location
			NARGW		_lvl4_room0_prize_seq			; prize sequences
			NARGW		_lvl4_room0_exits				; exits data
			NARGW		_lvl4_room0_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl4_room1_handler

_lvl4_room0_exits:
		.BYTE	$01
		.BYTE	$98,$01,$08,$05
		.BYTE	$32,$97,$00
_lvl4_room0_doors:
		.BYTE	$01,$A0,$05,$20,$08,DOOR_TEST
_lvl4_room0_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl4_room1_handler:
		NJSR			_nsub_room_init
			NARGB		$01								; room idx
			NARGB		ROOM_V,$01,$03					; room data location
			NARGW		_lvl4_room1_prize_seq			; prize sequences
			NARGW		_lvl4_room1_exits				; exits data
			NARGW		_lvl4_room1_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl4_room2_handler
		SCASE			_lvl4_room3_handler

_lvl4_room1_exits:
		.BYTE	$02
		.BYTE	$F8,$01,$A8,$04
		.BYTE	$B0,$01,$08,$03
		.BYTE	$43,$92,$01
		.BYTE	$34,$57,$00
_lvl4_room1_doors:
		.BYTE	$01,$90,$04,$D0,$08,DOOR_CLOSED
		.BYTE	$01,$E0,$04,$A0,$09,DOOR_TEST
		.BYTE	$01,$B0,$03,$20,$08,DOOR_TEST
_lvl4_room1_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl4_room2_handler:
		NJSR			_nsub_room_init
			NARGB		$02								; room idx
			NARGB		ROOM_H,$02,$04					; room data location
			NARGW		_lvl4_room2_prize_seq			; prize sequences
			NARGW		_lvl4_room2_exits				; exits data
			NARGW		_lvl4_room2_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl4_room1_handler

_lvl4_room2_exits:
		.BYTE	$01
		.BYTE	$00,$02,$98,$04
		.BYTE	$3C,$92,$03
_lvl4_room2_doors:
		.BYTE	$02,$10,$04,$A0,$0A,DOOR_TEST
_lvl4_room2_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl4_room3_handler:
		NJSR			_nsub_room_init
			NARGB		$03								; room idx
			NARGB		ROOM_H,$00,$02					; room data location
			NARGW		_lvl4_room3_prize_seq			; prize sequences
			NARGW		_lvl4_room3_exits				; exits data
			NARGW		_lvl4_room3_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$03
		SCASE			_lvl4_room1_handler
		SCASE			_lvl4_room4_handler
		SCASE			_lvl4_room5_handler

_lvl4_room3_exits:
		.BYTE	$03
		.BYTE	$B0,$01,$F0,$02
		.BYTE	$48,$00,$F0,$02
		.BYTE	$50,$00,$08,$02
		.BYTE	$34,$63,$02
		.BYTE	$08,$63,$02
		.BYTE	$08,$37,$00
_lvl4_room3_doors:
		.BYTE	$01,$B0,$02,$D0,$08,DOOR_TEST
		.BYTE	$00,$50,$02,$D0,$08,DOOR_TEST
		.BYTE	$00,$50,$02,$20,$08,DOOR_TEST
_lvl4_room3_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl4_room4_handler:
		NJSR			_nsub_room_init
			NARGB		$04								; room idx
			NARGB		ROOM_V,$00,$03					; room data location
			NARGW		_lvl4_room4_prize_seq			; prize sequences
			NARGW		_lvl4_room4_exits				; exits data
			NARGW		_lvl4_room4_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl4_room3_handler

_lvl4_room4_exits:
		.BYTE	$01
		.BYTE	$50,$00,$08,$03
		.BYTE	$08,$57,$00
_lvl4_room4_doors:
		.BYTE	$00,$50,$03,$20,$08,DOOR_TEST
		.BYTE	$FF
_lvl4_room4_prize_seq:
		.BYTE	$2C,$2C,$2C,$29,$29,$2C,$00

; =============== S C R I P T ==========================s====================
_lvl4_room5_handler:
		NJSR			_nsub_room_init
			NARGB		$05								; room idx
			NARGB		ROOM_H,$00,$01					; room data location
			NARGW		_lvl4_room5_prize_seq			; prize sequences
			NARGW		_lvl4_room5_exits				; exits data
			NARGW		_lvl4_room5_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl4_room3_handler
		SCASE			_lvl4_room6_handler

_lvl4_room5_exits:
		.BYTE	$02
		.BYTE	$50,$00,$F0,$01
		.BYTE	$F8,$01,$28,$01
		.BYTE	$08,$43,$02
		.BYTE	$44,$24,$01
_lvl4_room5_doors:
		.BYTE	$00,$50,$01,$D0,$08,DOOR_TEST
		.BYTE	$01,$E0,$01,$30,$10,DOOR_TEST
		.BYTE	$01,$00,$01,$80,$0B,DOOR_TEST
_lvl4_room5_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl4_room6_handler:
		NJSR			_nsub_room_init
			NARGB		$06								; room idx
			NARGB		ROOM_V,$02,$01					; room data location
			NARGW		_lvl4_room6_prize_seq			; prize sequences
			NARGW		_lvl4_room6_exits				; exits data
			NARGW		_lvl4_room6_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl4_room5_handler
		SCASE			_lvl4_room7_handler

_lvl4_room6_exits:
		.BYTE	$02
		.BYTE	$00,$02,$30,$01
		.BYTE	$60,$02,$F0,$02
		.BYTE	$3C,$24,$03
		.BYTE	$4A,$63,$02
_lvl4_room6_doors:
		.BYTE	$02,$10,$01,$30,$0C,DOOR_TEST
		.BYTE	$02,$60,$02,$D0,$08,DOOR_TEST
		.BYTE	$FF
_lvl4_room6_prize_seq:
; REGION, changed in the EU version
;		.BYTE	$2B,$2B,$2B,$2B,$2D,$2D,$2D,$2D,$00
		.BYTE	$2B,$2B,$2B,$2B,$2D,$2D,$2D,$2D,$2C,$00
; -

; =============== S C R I P T ==========================s====================
_lvl4_room7_handler:
		NJSR			_nsub_room_init
			NARGB		$07								; room idx
			NARGB		ROOM_H,$02,$03					; room data location
			NARGW		_lvl4_room7_prize_seq			; prize sequences
			NARGW		_lvl4_room7_exits				; exits data
			NARGW		_lvl4_room7_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl4_room6_handler
		SCASE			_lvl4_room8_handler

_lvl4_room7_exits:
		.BYTE	$02
		.BYTE	$60,$02,$08,$03
		.BYTE	$C0,$03,$08,$03
		.BYTE	$4A,$57,$00
		.BYTE	$76,$57,$00
_lvl4_room7_doors:
		.BYTE	$02,$60,$03,$20,$08,DOOR_TEST
		.BYTE	$03,$C0,$03,$20,$08,DOOR_TEST
		.BYTE	$FF
_lvl4_room7_prize_seq:
; REGION, changed in the EU version
;		.BYTE	$29,$2D,$29,$2D,$29,$29,$2D,$2D,$00
		.BYTE	$29,$2D,$29,$2D,$29,$29,$2D,$2D,$2B,$00
; -

; =============== S C R I P T ==========================s====================
_lvl4_room8_handler:
		NJSR			_nsub_room_init
			NARGB		$08								; room idx
			NARGB		ROOM_V,$03,$01					; room data location
			NARGW		_lvl4_room8_prize_seq			; prize sequences
			NARGW		_lvl4_room8_exits				; exits data
			NARGW		_lvl4_room8_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl4_room7_handler
		SCASE			_lvl4_room9_handler

_lvl4_room8_exits:
		.BYTE	$02
		.BYTE	$C0,$03,$F0,$02
		.BYTE	$28,$03,$08,$01
		.BYTE	$76,$64,$02
		.BYTE	$63,$17,$00
_lvl4_room8_doors:
		.BYTE	$03,$C0,$02,$D0,$08,DOOR_TEST
		.BYTE	$03,$20,$01,$20,$0D,DOOR_TEST
		.BYTE	$FF
_lvl4_room8_prize_seq:
		.BYTE	$29,$2D,$2D,$2C,$29,$2D,$2C,$2D,$00

; =============== S C R I P T ==========================s====================
_lvl4_room9_handler:
		NJSR			_nsub_room_init
			NARGB		$09								; room idx
			NARGB		ROOM_0,$03,$00					; room data location
			NARGW		_lvl4_room9_prize_seq			; prize sequences
			NARGW		_lvl4_room9_exits				; exits data
			NARGW		_lvl4_room9_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl4_room8_handler

_lvl4_room9_exits:
		.BYTE	$01
		.BYTE	$18,$03,$F0,$00
		.BYTE	$63,$23,$02
_lvl4_room9_doors:
		.BYTE	$03,$20,$00,$D0,$0D,DOOR_TEST
_lvl4_room9_prize_seq:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl4_common_init:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$12
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$11
		NJSR			_nsub_full_pal_load
			NARGW		_lvl4_full_pal
		STORE16			_lvl_collisions_ptr,_lvl4_collisions
		NJSR			_nsub_level_init
			NARGB		_lvl4_bank
			NARGW		_lvl4_macroA_tbl
			NARGW		_lvl4_macroB_tbl
			NARGW		_lvl4_macroC_tbl
			NARGW		_lvl4_macroD_tbl
			NARGW		_lvl4_attrs_tbl
			NARGW		_lvl4_rooms_lib
			NARGW		_lvl4_objects_list
			NARGB		_mus8_idx
		NBG_HNDL_SET	_nbgsub_lvl4_room_obj_handler	; custom handler for this level
		SJMP			_lvl_common_initB

_lvl4_full_pal:
		.BYTE	$0F,$30,$10,$00,$0F,$26,$17,$05,$0F,$37,$17,$08,$0F,$07,$15,$05
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$39,$2C,$0F,$0F,$15,$0F,$0F

; =============== S U B R O U T I N E ======n================================
; palette rotate for sewers water
;
_nbgsub_lvl4_room_obj_handler:
		LDA		_nmi_counter
		AND		#$07
		BNE		loc_15558
		LDA		_trds_args0
		ASL
		ASL
		ADC		#<[_lvl4_patch_pal_lib]
		PHA
		LDA		#$00
		ADC		#>[_lvl4_patch_pal_lib]
		TAX
		PLA
		LDY		#$03
		JSR		_patch_pal_load
		INC		_trds_args0
		LDA		_trds_args0
		CMP		#$06
		BCC		loc_15558
		LDA		#$00
		STA		_trds_args0
loc_15558:
		JMP		_nbgsub_room_obj_handler

_lvl4_patch_pal_lib:
		.BYTE	$0F,$07,$15,$05
		.BYTE	$0F,$05,$07,$15
		.BYTE	$0F,$15,$05,$07
		.BYTE	$0F,$07,$16,$05
		.BYTE	$0F,$05,$07,$16
		.BYTE	$0F,$16,$05,$07

		SECTION_END	"LVL4 SCRIPTS"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr05_lvl5_handler
		NJSR			_nsub_get_checkpoint_tmp_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJSR			_lvl5_common_init
		STORE16			_room_exits_ptr,_lvl5_room_starts
		NJSR			_nsub_players_room_start_pos_init_from_ptr
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$05
		SCASE			_lvl5_room0_handler
		SCASE			_lvl5_room3_handler
		SCASE			_lvl5_roomA_handler
		SCASE			_lvl5_roomF_handler
		SCASE			_lvl5_room13_handler

_lvl5_room_starts:
		.BYTE	$00
		.BYTE	$4D,$D4,$00
		.BYTE	$98,$92,$02
		.BYTE	$08,$93,$01
		.BYTE	$23,$29,$02
		.BYTE	$94,$34,$00

; =============== S C R I P T ==========================s====================
_lvl5_room0_handler:
		NJSR			_nsub_room_init
			NARGB		$00								; room idx
			NARGB		ROOM_0,$02,$06					; room data location
			NARGW		_lvl5_room0_prize_seq			; prize sequences
			NARGW		_lvl5_room0_exits				; exits data
			NARGW		_lvl5_room0_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl5_room1_handler

_lvl5_room0_exits:
		.BYTE	$01
		.BYTE	$40,$02,$08,$06
		.BYTE	$46,$B9,$00
_lvl5_room0_doors:
		.BYTE	$02,$40,$06,$20,$0E,DOOR_TEST
		.BYTE	$02,$40,$06,$D0,$0E,DOOR_CLOSED
_lvl5_room0_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room1_handler:
		NJSR			_nsub_room_init
			NARGB		$01								; room idx
			NARGB		ROOM_H,$02,$05					; room data location
			NARGW		_lvl5_room1_prize_seq			; prize sequences
			NARGW		_lvl5_room1_exits				; exits data
			NARGW		_lvl5_room1_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room2_handler
		SCASE			_lvl5_room0_handler

_lvl5_room1_exits:
		.BYTE	$02
		.BYTE	$F8,$03,$50,$05
		.BYTE	$40,$02,$F8,$05
		.BYTE	$83,$A7,$01
		.BYTE	$46,$C3,$02
_lvl5_room1_doors:
		.BYTE	$02,$40,$05,$D0,$0E,DOOR_TEST
		.BYTE	$03,$E0,$05,$50,$0F,DOOR_TEST
_lvl5_room1_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room2_handler:
		NJSR			_nsub_room_init
			NARGB		$02								; room idx
			NARGB		ROOM_0,$04,$05					; room data location
			NARGW		_lvl5_room2_prize_seq			; prize sequences
			NARGW		_lvl5_room2_exits				; exits data
			NARGW		_lvl5_room2_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0D
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room3_handler
		SCASE			_lvl5_room1_handler

_lvl5_room2_exits:
		.BYTE	$02
		.BYTE	$A8,$04,$08,$05
		.BYTE	$00,$04,$48,$05
		.BYTE	$94,$99,$00
		.BYTE	$7C,$A7,$03
_lvl5_room2_doors:
		.BYTE	$04,$10,$05,$50,$0F,DOOR_TEST
		.BYTE	$04,$B0,$05,$20,$0E,DOOR_TEST
_lvl5_room2_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room3_handler:
		NJSR			_nsub_room_init
			NARGB		$03								; room idx
			NARGB		ROOM_V,$04,$03					; room data location
			NARGW		_lvl5_room3_prize_seq			; prize sequences
			NARGW		_lvl5_room3_exits				; exits data
			NARGW		_lvl5_room3_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_lvl5_full_pal+$18
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$03
		SCASE			_lvl5_room5_handler
		SCASE			_lvl5_room4_handler
		SCASE			_lvl5_room2_handler

_lvl5_room3_exits:
		.BYTE	$03
		.BYTE	$00,$04,$50,$03
		.BYTE	$F8,$04,$50,$03
		.BYTE	$B0,$04,$F8,$04
		.BYTE	$7C,$67,$03
		.BYTE	$A3,$67,$01
		.BYTE	$94,$A3,$02
_lvl5_room3_doors:
		.BYTE	$04,$B0,$04,$D0,$0E,DOOR_TEST
		.BYTE	$04,$E0,$03,$50,$0F,DOOR_TEST
		.BYTE	$04,$10,$03,$50,$0F,DOOR_TEST
_lvl5_room3_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room4_handler:
		NJSR			_nsub_room_init
			NARGB		$04								; room idx
			NARGB		ROOM_0,$05,$03					; room data location
			NARGW		_lvl5_room4_prize_seq			; prize sequences
			NARGW		_lvl5_room4_exits				; exits data
			NARGW		_lvl5_room4_doors				; doors data
; REGION, missed in the EU version due to missing enemy
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
; -
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl5_room3_handler

_lvl5_room4_exits:
		.BYTE	$01
		.BYTE	$00,$05,$50,$03
		.BYTE	$9C,$67,$03
_lvl5_room4_doors:
		.BYTE	$05,$10,$03,$50,$0F,DOOR_TEST
_lvl5_room4_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room5_handler:
		NJSR			_nsub_room_init
			NARGB		$05								; room idx
			NARGB		ROOM_0,$03,$03					; room data location
			NARGW		_lvl5_room5_prize_seq			; prize sequences
			NARGW		_lvl5_room5_exits				; exits data
			NARGW		_lvl5_room5_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$12
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room3_handler
		SCASE			_lvl5_room6_handler

_lvl5_room5_exits:
		.BYTE	$02
		.BYTE	$F8,$03,$50,$03
		.BYTE	$B0,$03,$F8,$03
		.BYTE	$83,$67,$01
		.BYTE	$74,$83,$02
_lvl5_room5_doors:
		.BYTE	$03,$E0,$03,$50,$0F,DOOR_TEST
		.BYTE	$03,$B0,$03,$D0,$0E,DOOR_TEST
_lvl5_room5_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room6_handler:
		NJSR			_nsub_room_init
			NARGB		$06								; room idx
			NARGB		ROOM_H,$02,$04					; room data location
			NARGW		_lvl5_room6_prize_seq			; prize sequences
			NARGW		_lvl5_room6_exits				; exits data
			NARGW		_lvl5_room6_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room5_handler
		SCASE			_lvl5_room7_handler

_lvl5_room6_exits:
		.BYTE	$02
		.BYTE	$B0,$03,$08,$04
		.BYTE	$00,$02,$50,$04
		.BYTE	$74,$79,$00
		.BYTE	$3C,$87,$03
_lvl5_room6_doors:
		.BYTE	$03,$B0,$04,$20,$0E,DOOR_TEST
		.BYTE	$02,$10,$04,$50,$0F,DOOR_TEST
_lvl5_room6_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room7_handler:
		NJSR			_nsub_room_init
			NARGB		$07								; room idx
			NARGB		ROOM_V,$01,$04					; room data location
			NARGW		_lvl5_room7_prize_seq			; prize sequences
			NARGW		_lvl5_room7_exits				; exits data
			NARGW		_lvl5_room7_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$03
		SCASE			_lvl5_room6_handler
		SCASE			_lvl5_room8_handler
		SCASE			_lvl5_room9_handler

_lvl5_room7_exits:
		.BYTE	$03
		.BYTE	$F8,$01,$50,$04
		.BYTE	$B0,$01,$F8,$05
		.BYTE	$00,$01,$A0,$05
		.BYTE	$43,$87,$01
		.BYTE	$34,$C3,$02
		.BYTE	$1C,$B1,$03
_lvl5_room7_doors:
		.BYTE	$01,$E0,$04,$50,$0F,DOOR_TEST
		.BYTE	$01,$B0,$05,$D0,$0E,DOOR_TEST
		.BYTE	$01,$10,$05,$A0,$0F,DOOR_TEST
_lvl5_room7_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room8_handler:
		NJSR			_nsub_room_init
			NARGB		$08								; room idx
			NARGB		ROOM_0,$01,$06					; room data location
			NARGW		_lvl5_room8_prize_seq			; prize sequences
			NARGW		_lvl5_room8_exits				; exits data
			NARGW		_lvl5_room8_doors				; doors data
; REGION, removed in the EU version
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$12
; -
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl5_room7_handler

_lvl5_room8_exits:
		.BYTE	$01
		.BYTE	$B0,$01,$08,$06
		.BYTE	$34,$B9,$00
_lvl5_room8_doors:
		.BYTE	$01,$B0,$06,$20,$0E,DOOR_TEST
_lvl5_room8_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room9_handler:
		NJSR			_nsub_room_init
			NARGB		$09								; room idx
			NARGB		ROOM_0,$00,$05					; room data location
			NARGW		_lvl5_room9_prize_seq			; prize sequences
			NARGW		_lvl5_room9_exits				; exits data
			NARGW		_lvl5_room9_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$07
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room7_handler
		SCASE			_lvl5_roomA_handler

_lvl5_room9_exits:
		.BYTE	$02
		.BYTE	$F8,$00,$A0,$05
		.BYTE	$40,$00,$08,$05
		.BYTE	$23,$B1,$01
		.BYTE	$06,$99,$00
_lvl5_room9_doors:
		.BYTE	$00,$40,$05,$20,$0E,DOOR_TEST
		.BYTE	$00,$E0,$05,$A0,$0F,DOOR_TEST
_lvl5_room9_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_roomA_handler:
		NJSR			_nsub_room_init
			NARGB		$0A								; room idx
			NARGB		ROOM_V,$00,$03					; room data location
			NARGW		_lvl5_roomA_prize_seq			; prize sequences
			NARGW		_lvl5_roomA_exits				; exits data
			NARGW		_lvl5_roomA_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0F
		NJSR			_nsub_full_pal_load
			NARGW		_lvl5_full_pal
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room9_handler
		SCASE			_lvl5_roomB_handler

_lvl5_roomA_exits:
		.BYTE	$02
		.BYTE	$40,$00,$F8,$04
		.BYTE	$F8,$00,$50,$03
		.BYTE	$06,$A3,$02
		.BYTE	$23,$67,$01
_lvl5_roomA_doors:
		.BYTE	$00,$40,$04,$D0,$0E,DOOR_TEST
		.BYTE	$00,$E0,$03,$50,$0F,DOOR_TEST
_lvl5_roomA_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_roomB_handler:
		NJSR			_nsub_room_init
			NARGB		$0B								; room idx
			NARGB		ROOM_0,$01,$03					; room data location
			NARGW		_lvl5_roomB_prize_seq			; prize sequences
			NARGW		_lvl5_roomB_exits				; exits data
			NARGW		_lvl5_roomB_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_roomC_handler
		SCASE			_lvl5_roomA_handler

_lvl5_roomB_exits:
		.BYTE	$02
		.BYTE	$F8,$01,$A0,$03
		.BYTE	$00,$01,$50,$03
		.BYTE	$43,$71,$01
		.BYTE	$1C,$67,$03
_lvl5_roomB_doors:
		.BYTE	$01,$10,$03,$50,$0F,DOOR_TEST
		.BYTE	$01,$E0,$03,$A0,$0F,DOOR_TEST
_lvl5_roomB_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_roomC_handler:
		NJSR			_nsub_room_init
			NARGB		$0C								; room idx
			NARGB		ROOM_V,$02,$02					; room data location
			NARGW		_lvl5_roomC_prize_seq			; prize sequences
			NARGW		_lvl5_roomC_exits				; exits data
			NARGW		_lvl5_roomC_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_roomD_handler
		SCASE			_lvl5_roomB_handler

_lvl5_roomC_exits:
		.BYTE	$02
		.BYTE	$00,$02,$50,$02
		.BYTE	$00,$02,$A0,$03
		.BYTE	$3C,$47,$03
		.BYTE	$3C,$71,$03
_lvl5_roomC_doors:
		.BYTE	$02,$10,$03,$A0,$0F,DOOR_TEST
		.BYTE	$02,$10,$02,$50,$0F,DOOR_TEST
		.BYTE	$FF
_lvl5_roomC_prize_seq:
		.BYTE	$19,$18,$19,$19,$19,$18,$18,$00

; =============== S C R I P T ==========================s====================
_lvl5_roomD_handler:
		NJSR			_nsub_room_init
			NARGB		$0D								; room idx
			NARGB		ROOM_H,$00,$02					; room data location
			NARGW		_lvl5_roomD_prize_seq			; prize sequences
			NARGW		_lvl5_roomD_exits				; exits data
			NARGW		_lvl5_roomD_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_roomE_handler
		SCASE			_lvl5_roomC_handler

_lvl5_roomD_exits:
		.BYTE	$02
		.BYTE	$40,$00,$08,$02
		.BYTE	$F8,$01,$50,$02
		.BYTE	$06,$39,$00
		.BYTE	$42,$47,$01
_lvl5_roomD_doors:
		.BYTE	$01,$E0,$02,$50,$0F,DOOR_TEST
		.BYTE	$00,$40,$02,$20,$0E,DOOR_TEST
		.BYTE	$FF
_lvl5_roomD_prize_seq:
		.BYTE	$13,$13,$19,$19,$19,$19,$17,$17,$00

; =============== S C R I P T ==========================s====================
_lvl5_roomE_handler:
		NJSR			_nsub_room_init
			NARGB		$0E								; room idx
			NARGB		ROOM_0,$00,$01					; room data location
			NARGW		_lvl5_roomE_prize_seq			; prize sequences
			NARGW		_lvl5_roomE_exits				; exits data
			NARGW		_lvl5_roomE_doors				; doors data
		SJSR			_lvl3_room_modeA_init_ex
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_roomF_handler
		SCASE			_lvl5_roomD_handler

_lvl5_roomE_exits:
		.BYTE	$02
		.BYTE	$F8,$00,$50,$01
		.BYTE	$40,$00,$F8,$01
		.BYTE	$23,$27,$01
		.BYTE	$06,$43,$02
_lvl5_roomE_doors:
		.BYTE	$00,$E0,$01,$50,$0F,DOOR_TEST
		.BYTE	$00,$40,$01,$D0,$0E,DOOR_TEST
_lvl5_roomE_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_roomF_handler:
		NJSR			_nsub_room_init
			NARGB		$0F								; room idx
			NARGB		ROOM_H,$01,$01					; room data location
			NARGW		_lvl5_roomF_prize_seq			; prize sequences
			NARGW		_lvl5_roomF_exits				; exits data
			NARGW		_lvl5_roomF_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_lvl5_full_pal+$1C
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$03
		SCASE			_lvl5_room11_handler
		SCASE			_lvl5_roomE_handler
		SCASE			_lvl5_room10_handler

_lvl5_roomF_exits:
		.BYTE	$03
		.BYTE	$F8,$02,$50,$01
		.BYTE	$00,$01,$50,$01
		.BYTE	$70,$01,$08,$01
		.BYTE	$63,$27,$01
		.BYTE	$1C,$27,$03
		.BYTE	$2C,$19,$00
_lvl5_roomF_doors:
		.BYTE	$01,$70,$01,$20,$0E,DOOR_TEST
		.BYTE	$01,$10,$01,$50,$0F,DOOR_TEST
		.BYTE	$02,$E0,$01,$50,$0F,DOOR_TEST
_lvl5_roomF_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room10_handler:
		NJSR			_nsub_room_init
			NARGB		$10								; room idx
			NARGB		ROOM_0,$01,$00					; room data location
			NARGW		_lvl5_room10_prize_seq			; prize sequences
			NARGW		_lvl5_room10_exits				; exits data
			NARGW		_lvl5_room10_doors				; doors data
; REGION, removed in the EU version
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
; -
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl5_roomF_handler

_lvl5_room10_exits:
		.BYTE	$01
		.BYTE	$70,$01,$F8,$00
		.BYTE	$2C,$23,$02
_lvl5_room10_doors:
		.BYTE	$01,$70,$00,$D0,$0E,DOOR_TEST
_lvl5_room10_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room11_handler:
		NJSR			_nsub_room_init
			NARGB		$11								; room idx
			NARGB		ROOM_V,$03,$01					; room data location
			NARGW		_lvl5_room11_prize_seq			; prize sequences
			NARGW		_lvl5_room11_exits				; exits data
			NARGW		_lvl5_room11_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$04
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room12_handler
		SCASE			_lvl5_roomF_handler

_lvl5_room11_exits:
		.BYTE	$02
		.BYTE	$F8,$03,$A0,$02
		.BYTE	$00,$03,$50,$01
		.BYTE	$83,$51,$01
		.BYTE	$5C,$27,$03
_lvl5_room11_doors:
		.BYTE	$03,$10,$01,$50,$0F,DOOR_TEST
		.BYTE	$03,$E0,$02,$A0,$0F,DOOR_TEST
_lvl5_room11_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room12_handler:
		NJSR			_nsub_room_init
			NARGB		$12								; room idx
			NARGB		ROOM_0,$04,$02					; room data location
			NARGW		_lvl5_room12_prize_seq			; prize sequences
			NARGW		_lvl5_room12_exits				; exits data
			NARGW		_lvl5_room12_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room13_handler
		SCASE			_lvl5_room11_handler

_lvl5_room12_exits:
		.BYTE	$02
		.BYTE	$B0,$04,$08,$02
		.BYTE	$00,$04,$A0,$02
		.BYTE	$94,$39,$00
		.BYTE	$7C,$51,$03
_lvl5_room12_doors:
		.BYTE	$04,$10,$02,$A0,$0F,DOOR_TEST
		.BYTE	$04,$B0,$02,$20,$0E,DOOR_TEST
_lvl5_room12_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room13_handler:
		NJSR			_nsub_room_init
			NARGB		$13								; room idx
			NARGB		ROOM_0,$04,$01					; room data location
			NARGW		_lvl5_room13_prize_seq			; prize sequences
			NARGW		_lvl5_room13_exits				; exits data
			NARGW		_lvl5_room13_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0C
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_lvl5_room13_patch_pal
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room14_handler
		SCASE			_lvl5_room12_handler

_lvl5_room13_exits:
		.BYTE	$02
		.BYTE	$B0,$04,$08,$01
		.BYTE	$B4,$04,$F8,$01
		.BYTE	$94,$19,$00
		.BYTE	$94,$43,$02
_lvl5_room13_doors:
		.BYTE	$04,$B0,$01,$20,$0E,DOOR_TEST
		.BYTE	$04,$B0,$01,$D0,$0E,DOOR_TEST
_lvl5_room13_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room14_handler:
		NJSR			_nsub_room_init
			NARGB		$14								; room idx
			NARGB		ROOM_H,$03,$00					; room data location
			NARGW		_lvl5_room14_prize_seq			; prize sequences
			NARGW		_lvl5_room14_exits				; exits data
			NARGW		_lvl5_room14_doors				; doors data
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$18
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_lvl5_full_pal+$1C
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl5_room15_handler
		SCASE			_lvl5_room13_handler

_lvl5_room14_exits:
		.BYTE	$02
		.BYTE	$00,$03,$70,$00
		.BYTE	$B0,$04,$F8,$00
		.BYTE	$5C,$0C,$03
		.BYTE	$94,$23,$02
_lvl5_room14_doors:
		.BYTE	$04,$B0,$00,$D0,$0E,DOOR_TEST
		.BYTE	$03,$10,$00,$70,$0F,DOOR_TEST
_lvl5_room14_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
_lvl5_room15_handler:
		NJSR			_nsub_room_init
			NARGB		$15								; room idx
			NARGB		ROOM_0,$02,$00					; room data location
			NARGW		_lvl5_room15_prize_seq			; prize sequences
			NARGW		_lvl5_room15_exits				; exits data
			NARGW		_lvl5_room15_doors				; doors data
		SJSR			_ssub_common_room_loop
		SJMPS			_lvl5_room14_handler

_lvl5_room15_exits:
		.BYTE	$01
		.BYTE	$F8,$02,$70,$00
		.BYTE	$63,$0C,$01
_lvl5_room15_doors:
		.BYTE	$02,$E0,$00,$70,$0F,DOOR_TEST
_lvl5_room15_prize_seq:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl5_common_init:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$0E
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$15
		NJSR			_nsub_full_pal_load
			NARGW		_lvl5_full_pal
		STORE16			_lvl_collisions_ptr,_lvl5_collisions
		NJSR			_nsub_level_init
			NARGB		_lvl5_bank
			NARGW		_lvl5_macroA_tbl
			NARGW		_lvl5_macroB_tbl
			NARGW		_lvl5_macroC_tbl
			NARGW		_lvl5_macroD_tbl
			NARGW		_lvl5_attrs_tbl
			NARGW		_lvl5_rooms_lib
			NARGW		_lvl5_objects_list
			NARGB		_mus9_idx
		SJMP			_lvl_common_initA

_lvl5_full_pal:
		.BYTE	$0F,$30,$10,$00,$0F,$30,$10,$01,$0F,$30,$27,$01,$0F,$30,$15,$07
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$26,$0F,$0F,$36,$26,$0F
_lvl5_room13_patch_pal:
		.BYTE	$0F,$36,$27,$0F

		SECTION_END	"LVL5 SCRIPTS"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr06_lvl6_handler
		NJSR			_nsub_get_checkpoint_tmp_idx
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJSRS			_lvl6_common_init
		STORE16			_room_exits_ptr,_lvl6_room_starts
		NJSR			_nsub_players_room_start_pos_init_from_ptr
		SJMPS			_lvl6_room0_handler

_lvl6_room_starts:
		.BYTE	$00
		.BYTE	$0E,$73,$00

; =============== S C R I P T ==========================s====================
; this is second to last game room, there are no doors in it
; only doubled exit point since the exit area is too wide for one exit
;
_lvl6_room0_handler:
		NJSR			_nsub_room_init
			NARGB		$00								; room idx
			NARGB		ROOM_V,$00,$02					; room data location
			NARGW		_lvl6_room0_prize_seq			; prize sequences
			NARGW		_lvl6_room0_exits				; exits data
			NARGW		_lvl6_room0_doors				; doors data
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_read_mem
			NARGW		_tmp_idx
		SJMP_SW			$02
		SCASE			_lvl6_room1_handler
		SCASE			_lvl6_room1_handler

_lvl6_room0_exits:
		.BYTE	$02
		.BYTE	$70,$00,$10,$02
		.BYTE	$90,$00,$10,$02
		.BYTE	$0E,$36,$00
		.BYTE	$0E,$36,$00
_lvl6_room0_doors:
_lvl6_room0_prize_seq:
		.BYTE	$FF

; =============== S C R I P T ==========================s====================
; final boss room. unless any other room handlers, this one uses
; partial palette fade out routine since the boss sprite hidden in it
; so it keep boss sprite invisible at the beginning of the battle.
;
_lvl6_room1_handler:
		NJSR			_nsub_room_init
			NARGB		$01								; room idx
			NARGB		ROOM_V,$00,$00					; room data location
			NARGW		_lvl6_room1_prize_seq			; prize sequences
			NARGW		$0000							; also dummy
			NARGW		_lvl6_room1_doors				; doors data
		SDELAY			$01
		SLOOP_BEGIN		$04								; pal fade with mask
		NJSR			_nsub_pal_fade_req_inc_by_mask
			NARGB		$DD
		SDELAY			$03
		SLOOP_END
		STORE8			_pause_mode_flag,$00		; not sure why they disable pause here
		NJSR			_nsub_lvl6_players_auto_scriptsA_set	; reload players scripts with auto walk
		SCRL_Y_MOVE_SET 0,$80,$FF						; set scroll animation parameter
		SDELAY			$F0								; do animation while scrolling and walking up
		SDELAY			$F0
		SCRL_MOVE_STOP  0								; stop
		STORE8			_cur_room_x_pageB,$00			; fix the main room page idx here.
		SUSPEND											; all done

_lvl6_room1_doors:
_lvl6_room1_prize_seq:
		.BYTE	$FF

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl6_common_init:
		NJSR			_nsub_mmc1_chr0_set
			NARGB		$17
		NJSR			_nsub_mmc1_chr1_set
			NARGB		$16
		NJSR			_nsub_full_pal_load
			NARGW		_lvl6_full_pal
		STORE16			_lvl_collisions_ptr,_lvl6_collisions
		NJSR			_nsub_level_init
			NARGB		_lvl6_bank
			NARGW		_lvl6_macroA_tbl
			NARGW		_lvl6_macroB_tbl
			NARGW		_lvl6_macroC_tbl
			NARGW		_lvl6_macroD_tbl
			NARGW		_lvl6_macroE_tbl
			NARGW		_lvl6_rooms_lib
			NARGW		_lvl6_objects_list
			NARGB		_musA_idx
		SJMP			_lvl_common_initA

_lvl6_full_pal:
		.BYTE	$0F,$30,$10,$1B,$0F,$10,$1B,$06,$0F,$26,$17,$07,$0F,$09,$10,$0B
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$36,$17,$0F,$0F,$36,$25,$0F

; =============== S U B R O U T I N E ======n================================
; do walk to the boss painting
;
_nsub_lvl6_players_auto_scriptsA_set:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl6_beamer_auto_scriptA
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl6_catcher_auto_scriptA
		RTS

		SECTION_END	"LVL6 SCRIPTS"

		SECTION_START

; =============== S U B R O U T I N E ======n================================
_nsub_ingame_start_input_test:
		LDA		_pause_mode_flag			; sub constantly called from
		BNE		loc_15E56					; level secondary script to

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nsub_wait_for_start_press:
		LDA		_pad0_pressed				; check if START was pressed ot nor
		AND		#$10
		BEQ		loc_15E56
		SEC
		RTS
loc_15E56:
		CLC
		RTS

#if DEBUG==1
; =============== S U B R O U T I N E ======n================================
; NOTE: this _game_flags ($80) used by the game to determine if previous
; level were comlete or not when the main level script is stopped during
; the game. usually, there are three options: 00/01 if continue or end were
; selected at the "GAME OVER" screen, 80 is set after the "STAGE CLEAR"
; screen and thus the main engine will increment the level number...
;
; NEW, reused this routine for debugging purposes
;
_nsub_ingame_select_input_test:
		LDA		_pad0_pressed
		AND		#$20
		BEQ		loc_15E65
		LDA		#$80
		STA		_game_flags
		SEC
		RTS
loc_15E65:
		CLC
		RTS
#endif

; =============== S U B R O U T I N E ======n================================
_nsub_ingame_pause_handler:
		LDA		#$FF						; stop music at the pause entry
		JSR		_far_prg6_apu_mus_load_ex	; onlu snd is player this time
		LDA		_ppu_scroll_pos_x			; backup critical variables
		PHA
		LDA		_ppu_scroll_pos_x+1
		PHA
		LDA		_ppu_scroll_pos_y
		PHA
		LDA		_ppu_scroll_pos_y+1
		PHA
		LDA		_cur_room_x_pageA
		PHA
		LDA		_cur_room_y_pageA
		PHA
		LDA		_cur_room_x_pageB
		PHA
		LDA		_cur_room_y_pageB
		PHA
		LDA		#$00
		STA		_ppu_scroll_pos_x
		STA		_ppu_scroll_pos_x+1
		STA		_ppu_scroll_pos_y
		STA		_ppu_scroll_pos_y+1
		LDA		_chr_bank1
		PHA
		LDA		#_tlm1_score_idx			; draw pause static info tile-map
		JSR		_far_prg0_tlm_lib_unpack
		JSR		_nsub_scores_and_players_lives_draw	; draw pause dynamic info (scores, lives)
		JSR		_ppu_res_send_param			; send palette
		.WORD	_res_pause_pal
loc_15EA2:
		JSR		_wait_for_nmi				; enter the pause loop here
		LDA		#$00
		STA		_spr_buf_pos
		STA		_spr_buf_shuffle
		JSR		_pause_screen_anim			; animate player's icon
		JSR		_nsub_wait_for_start_press
		BCC		loc_15EA2					; and wait for press START
		JSR		_full_pal_fade
		JSR		_room_draw					; redraw current room, all vars already
		PLA									; initialized
		JSR		_mmc1_chr1_set				; restore room background CHR bank
		LDY		_active_door_data_pos		; there is a special case to
		BMI		loc_15ED8					; also update currently opened door
		INY									; if you pause nearby
		INY
		INY
		INY
		LDA		(_room_doors_data_ptr),Y	; fetch only the door type
		ASL
		TAY
		LDA		off_15F18,Y					; then call corresponding door draw routine
		STA		_ptr06
		LDA		off_15F18+1,Y
		STA		_ptr06+1
		JSR		_jmp_ptr06
loc_15ED8:
		PLA
		STA		_cur_room_y_pageB			; restore all vars and music, return to the game script
		PLA
		STA		_cur_room_x_pageB
		PLA
		STA		_cur_room_y_pageA
		PLA
		STA		_cur_room_x_pageA
		PLA
		STA		_ppu_scroll_pos_y+1
		PLA
		STA		_ppu_scroll_pos_y
		PLA
		STA		_ppu_scroll_pos_x+1
		PLA
		STA		_ppu_scroll_pos_x
		LDA		_apu_cur_mus_idx
		JMP		_far_prg6_apu_mus_load

; =============== S U B R O U T I N E ======n================================
_pause_screen_anim:
		LDX		#$90						; and put it to fixed location
		LDY		#$B8
		LDA		_beamer_spr_base_tmp		; using the beamer spr idx
		JSR		_player_spr_insert
		LDX		#$80						; TEST
		LDY		#$B8
		LDA		_catcher_spr_base_tmp

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_player_spr_insert:
		STX		_tmp1
		STY		_tmp2
		AND		#$F0						; animate it based on frames counter
		LSR
		LSR
		STA		_tmp0
		LDA		_nmi_counter
		AND		#$0C
		LSR
		LSR
		ADC		_tmp0
		TAY
		LDA		_spr_pause_list,Y
		ASL									; NEW, WARNING, may oveflow if idx are
		TAY									; higher than 80!
		LDA		_spr_libA08,Y
		STA		_ptr1E
		LDA		_spr_libA08+1,Y
		STA		_ptr1E+1
		JMP		_spr_mode_select_ex

; NEW, WARNING! there are a lot shared sprites here between various
; libraries. to make sure you using the correct index for particular
; library, we need to replace all duplicated offsets with unique ones
; pointing to the same place anyway.
;
_spr_pause_list:
		.BYTE	$0A	; _sprA08_0A_idx
		.BYTE	$09	; _sprA08_09_idx
		.BYTE	$0A	; _sprA08_0A_idx
		.BYTE	$0B	; _sprA08_0B_idx
		.BYTE	$1A	; _sprA08_1A_idx
		.BYTE	$19	; _sprA08_19_idx
		.BYTE	$1A	; _sprA08_1A_idx
		.BYTE	$1B	; _sprA08_1B_idx
		.BYTE	$2A	; _sprA08_2A_idx
		.BYTE	$29	; _sprA08_29_idx
		.BYTE	$2A	; _sprA08_2A_idx
		.BYTE	$2B	; _sprA08_2B_idx
		.BYTE	$3A	; _sprA08_3A_idx
		.BYTE	$39	; _sprA08_39_idx
		.BYTE	$3A	; _sprA08_3A_idx
		.BYTE	$3B	; _sprA08_3B_idx
		.BYTE	$4A	; _sprA08_4A_idx
		.BYTE	$49	; _sprA08_49_idx
		.BYTE	$4A	; _sprA08_4A_idx
		.BYTE	$4B	; _sprA08_4B_idx

off_15F18:
		.WORD	_nsub_door00_open_draw
		.WORD	_nsub_door01_open_draw
		.WORD	_nsub_door02_open_draw
		.WORD	_nsub_door03_open_draw
		.WORD	_nsub_door04_open_draw
		.WORD	_nsub_door05_open_draw
		.WORD	_nsub_door06_open_draw
		.WORD	_nsub_door07_open_draw
		.WORD	_nsub_door08_open_draw
		.WORD	_nsub_door09_open_draw
		.WORD	_nsub_door0A_open_draw
		.WORD	_nsub_door0B_open_draw
		.WORD	_nsub_door0C_open_draw
		.WORD	_nsub_door0D_open_draw
		.WORD	_nsub_door0E_open_draw
		.WORD	_nsub_door0F_open_draw
		.WORD	_nsub_door10_open_draw

_res_pause_pal:
		.WORD	$3F00
		.BYTE	$18,$01
		.BYTE	$0F,$31,$11,$01,$0F,$00,$10,$20,$0F,$00,$10,$20,$0F,$00,$10,$20
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15

; NOTE: must be in the same bank as stage scrips, or called as a separate
; entry in the scripts list
;
; =============== S C R I P T ==========================s====================
_scr_stage_complete:
		NJSR			_nsub_players_scr_suspend		; suspend players
		NJSR			_nsub_apu_mus_load				; they still visible
			NARGB		$FF								; music off, wait for 10 frames
		STORE8			_apu_mus_volume,$FF
		SDELAY			$10
		STORE8			_pause_mode_flag,$01			; set pause mode to disable all scripts
		SDELAY			$4B								; stand still for about 1.25 seconds
		NJSR			_nsub_all_threads_off_except_cur; then off all threads except this one
		SDELAY			$2D
		NJSR			_nsub_apu_mus_load				; start stage complete jingle
			NARGB		_mus3_idx
		NJSR			_nsub_mmc1_chr0_set				; also change sprites CHR bank
			NARGB		$05
		NJSR			_nsub_obj_screen_pos_set		; set object sprite screen position
			NARGB		$80,$7C							; relative to current scroll
		SPR_IDX_SET		0,$17							; set sprite for "STAGE COMPLETE"
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_ngsub_stage_complete_pal_anim	; start to rotate palette for this sprite
		SDELAY			$78								; for 2 seconds
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask	; fade all except this sprite pal
			NARGB		$FE
		SDELAY			$06
		SLOOP_END
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; now unpack tlm for scores info
			NARGB		_tlm1_score_idx
		NJSR			_nsub_scores_and_players_lives_draw	; draw the same info as for pause screen
		NJSR			_nsub_bg_pal_load
			NARGW		_stage_complete_bg_pal
		NJSR			_nsub_scroll_page_set			; reset scrolls
			NARGB		$00
		POS_X_SET		0,$80,$00						; re-set the current sprite position
		POS_Y_SET		0,$7C,$00						; without scroll adjusting this time
		NBG_HNDL_SET	_ngsub_stage_complete_pal_anim_with_player	; set anim routine also with player icon
		SPR_IDX_INC		0								; change sprite idx to 18 because now sprite
		NJSR			_nsub_mmc1_chr0_set				; tiles changes and goes to second CHR page
			NARGB		$04
		NJSR			_nsub_mmc1_chr1_set				; because bg tiles of font are there as well
			NARGB		$05
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_inc_by_mask	; fade out complete screen prepared
			NARGB		$FE
		SDELAY			$06
		SLOOP_END
		SDELAY			$F0								; and wait for the jingle is over
		SJSR			_ssub_pal_fade_out
		STORE8			_game_flags,$80					; set game flag to inform engine to increment level idx
		SSTOP											; and kill current script to exit from engine loop.

_stage_complete_bg_pal:
		.BYTE	$0F,$30,$0F,$0F,$0F,$30,$10,$00,$0F,$35,$25,$15,$0F,$30,$3B,$2B

; =============== S U B R O U T I N E ======n================================
_ngsub_stage_complete_pal_anim_with_player:
		JSR		_pause_screen_anim

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_ngsub_stage_complete_pal_anim:
		LDA		_nmi_counter
		AND		#$03
		BNE		locret_15FFD
		LDA		_trds_args0
		ASL
		ASL
		TAY
		LDX		#$00
loc_15FE3:
		LDA		_stage_complete_patch_pal_list,Y
		STA		_pal_buf+$1C,X
		INY
		INX
		CPX		#$04
		BCC		loc_15FE3
		JSR		_full_pal_fade
		INC		_trds_args0
		LDA		_trds_args0
		CMP		#$0E
		BCC		locret_15FFD
		LDA		#$00
		STA		_trds_args0
locret_15FFD:
		RTS

_stage_complete_patch_pal_list:
		.BYTE	$0F,$06,$0F,$0F
		.BYTE	$0F,$17,$06,$0F
		.BYTE	$0F,$27,$17,$06
		.BYTE	$0F,$37,$27,$17
		.BYTE	$0F,$30,$37,$27
		.BYTE	$0F,$30,$30,$37
		.BYTE	$0F,$37,$30,$30
		.BYTE	$0F,$27,$37,$30
		.BYTE	$0F,$17,$27,$37
		.BYTE	$0F,$06,$17,$27
		.BYTE	$0F,$0F,$06,$17
		.BYTE	$0F,$0F,$0F,$06
		.BYTE	$0F,$0F,$0F,$0F
		.BYTE	$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nsub_scores_and_players_lives_draw:
		LDA		#$05
		STA		_chr_bank1
		JSR		_ppu_spr_fill_F1
		LDA		_players_lives				; convert binary lives to decimal
		LDX		#$00
		JSR		_bin2dec
		LDA		_var3						; check if high digit is zero
		BNE		loc_1604E					; so fill it with "SPACE"
		LDA		#$20
		BNE		loc_16050
loc_1604E:
		ORA		#$30						; or adjust the number idx
loc_16050:
		STA		_tmp_buf+4					; lower digit cannot be zero here
		LDA		_var4						; so just convert to number idx
		ORA		#$30
		STA		_tmp_buf+5
		LDX		#$15
		LDY		#$16
		JSR		_ppu_offset_calc			; helper routine to calc ppu position
#if TWO_PLAYER_MODE==1
; TODO: second players lives display on pause and stage complete screens
#endif
		LDX		#$01
		STX		_tmp_buf+3
		INX
		STX		_tmp_buf+2
		JSR		_ppu_res_send_param_no_ofs	; send lives buffer data first
		.WORD	_tmp_buf+2
		LDA		_hi_scores
		LDX		_hi_scores+1
		JSR		_bin2dec					; convert scores now
		LDX		#$10
		LDY		#$08
		JSR		_print_num99999				; print using special subroutine now
		LDA		_scores						; same as using "%5d" in format(...)
		LDX		_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$0A
		JMP		_print_num99999

; NOTE: same as for stage complete script, must be in the same bank as
; the main stage scripts.
;
; =============== S C R I P T ==========================s====================
_scr_game_over:
		SJSR			_ssub_room_exit_pal_fade_out	; usual stuff here
		NJSR			_nsub_all_threads_off_except_cur; disable threads,
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; draw picture
			NARGB		_tlm3_game_over_idx
		NJSR			_nsub_mmc1_chr1_set				; setup CHR banks
			NARGB		$05
		NJSR			_nsub_full_pal_load				; and palettes
			NARGW		_pal_game_over
		NJSR			_nsub_scroll_page_set
			NARGB		$00
		NJSR			_nsub_game_over_draw			; draw numeric values
		SJSR			_ssub_pal_fade_in
		STORE8			_apu_mus_volume,$FF				; start game over music
		NJSR			_nsub_apu_mus_load
			NARGB		_mus2_idx
		NJSR			_nsub_mcmp						; now check if we have any continues
			NARGW		_continues
			NARGB		$00
		SBCSS			_sloc_16162						; if no, just skip to the dummy delay
		POS_X_SET		0,$58,$00						; or else setup a sprite anims
		SSCRIPT1_SET	_scr_game_over_exit_test
_sloc_16146:
		POS_X_DELTA_SET 0,$00,$01						; animate ghost nanny at the gb to the right
		SPR_IDX_SET		0,$15							; while polling the menu input native sub
		SLOOP_BEGIN		$50
		NJSR			_nsub_game_over_menu_item_input
		SDELAY			$01
		SLOOP_END
		POS_X_DELTA_SET 0,$00,$FF						; invert delta, do the same to the left
		SPR_IDX_INC		0
		SLOOP_BEGIN		$50
		NJSR			_nsub_game_over_menu_item_input
		SDELAY			$01
		SLOOP_END
		SJMPS			_sloc_16146						; repeat until input done
_sloc_16162:
		SDELAY			$F0
		SDELAY			$3C
		SJSR			_ssub_pal_fade_out
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_game_over_exit_test:
		SDELAY			$01								; accept test in secondary script for this thread
		NJSR			_nsub_wait_for_start_press
		SBCCS			_scr_game_over_exit_test
		SJSR			_ssub_pal_fade_out
		SSTOP

_pal_game_over:
		.BYTE	$0F,$30,$15,$03,$0F,$30,$10,$0F,$0F,$37,$27,$17,$0F,$0F,$0F,$0F
		.BYTE	$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$31,$12,$0F,$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nsub_game_over_draw:
		LDA		_lvl_cur_checkpoint_idx		; in case of continue, reload last accessed checkpoint
		STA		_lvl_last_checkpoint_idx
		LDA		_hi_scores					; convert scores to decimal string
		LDX		_hi_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$04
		JSR		_print_num99999				; and draw
		LDA		_scores
		LDX		_scores+1
		JSR		_bin2dec
		LDX		#$10
		LDY		#$06
		JSR		_print_num99999
		DEC		_continues					; also continues
		BEQ		loc_161E3					; but convert to string manually
		LDA		_continues					; since the common routine
		ORA		#$30						; handles 5-digit numbers only
		STA		_tmp_buf+4
		LDA		#$01
		STA		_tmp_buf+2
		STA		_tmp_buf+3
		LDX		#$14
		LDY		#$12
		JSR		_ppu_offset_calc
		JSR		_ppu_res_send_param_no_ofs
		.WORD	_tmp_buf+2
		LDA		#$01
		STA		_game_flags
		RTS
loc_161E3:
		JSR		_ppu_res_send_param_repeat	; draw empty area if no continues left
		.WORD	word_161EE
		LDA		#$00
		STA		_game_flags
		RTS
word_161EE:
		.WORD	$224B
		.BYTE	$0A,$05
		.BYTE	$20

; =============== S U B R O U T I N E ======n================================
_nsub_game_over_menu_item_input:
		LDA		_pad0_pressed
		AND		#$2C
		BEQ		loc_16201
		LDA		_game_flags
		EOR		#$01
		STA		_game_flags
loc_16201:
		LDX		_cur_trd_slot
		LDY		_game_flags
		LDA		byte_16211,Y
		STA		_obj_y_pos_lo,X
		LDA		#$00
		STA		_obj_y_pos_hi,X
		RTS
byte_16211:
		.BYTE	$AD,$8D

		SECTION_END	"PAUSE/STAGE COMPLETE/GAME OVER HANDLERS"

		SECTION_START

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr0C_room_doors_handler
		NBG_HNDL_SET	_nbgsub_cur_door_data_load		; initialize the doors data on start
		NJSR			_nsub_player_to_doors_ctest		; now test if player appears at the door
		SBCCS			_sloc_16284						; in this case draw it open manually
		SJSR_SW	$11										; without animation and sounds
		SCASE			_ssub_door00_opened				; lvl1 face 2x2 regular
		SCASE			_ssub_door01_opened				; lvl1 edge 1x2
		SCASE			_ssub_door02_opened 			; lvl2 face 2x1 regular
		SCASE			_ssub_door03_opened 			; lvl2 edge 1x2
		SCASE			_ssub_door04_opened				; lvl2 face 1x2 train
		SCASE			_ssub_door05_opened				; lvl3 face 2x2 regular A
		SCASE			_ssub_door06_opened				; lvl3 face 2x2 regular B
		SCASE			_ssub_door07_opened				; lvl3 face 2x2 regular B (diff open)
		SCASE			_ssub_door08_opened				; lvl4 face 2x2 regular
		SCASE			_ssub_door09_opened				; lvl4
		SCASE			_ssub_door0A_opened 			; lvl4
		SCASE			_ssub_door0B_opened 			; lvl4
		SCASE			_ssub_door0C_opened 			; lvl4
		SCASE			_ssub_door0D_opened 			; lvl4
		SCASE			_ssub_door0E_opened				; lvl5
		SCASE			_ssub_door0F_opened				; lvl5
		SCASE			_ssub_door10_opened 			; lvl4
_sloc_16284:
		SDELAY			$01								; or else skip to the main door handler loop
		NJSR			_nsub_player_to_doors_ctest		; test if players get near any door
		SBCCS			_sloc_16284						; then execute the door animation script
		SJSR_SW	$11
		SCASE			_ssub_door00_anim				; all dors has a separate scripts
		SCASE			_ssub_door01_anim
		SCASE			_ssub_door02_anim
		SCASE			_ssub_door03_anim
		SCASE			_ssub_door04_anim
		SCASE			_ssub_door05_anim
		SCASE			_ssub_door06_anim
		SCASE			_ssub_door07_anim
		SCASE			_ssub_door08_anim
		SCASE			_ssub_door09_anim
		SCASE			_ssub_door0A_anim
		SCASE			_ssub_door0B_anim
		SCASE			_ssub_door0C_anim
		SCASE			_ssub_door0D_anim
		SCASE			_ssub_door0E_anim
		SCASE			_ssub_door0F_anim
		SCASE			_ssub_door10_anim
		SJMPS			_sloc_16284

; =============== S U B R O U T I N E ======n================================
; pre-load the doors data into additional doors objects parameters array
; which are used to handle objects-to-room collision tests in conjunction
; with macro-tile based collision test. the main purpose is to detect any
; solid obstacles on the way of any dynamic objects
;
; there are maximum 8 doors data can be loaded
;
_nbgsub_cur_door_data_load:
; NOTE, for some reason, here we load the doors counter while it should be 0 here,
; why they init it outside of thread manager in the main game loop, and load here?
; this is also impossible to have it non zero here...
;
;		LDX		_cur_room_doors_cnt
		LDA		#$00
		TAY
		TAX
loc_162B8:
		LDA		(_room_doors_data_ptr),Y
		BMI		loc_162F7
		CPY		_active_door_data_pos		; skip currently active door, it should be opened
		BEQ		loc_162F0
		STA		_doors_x_pos_lo+1,X			; position of the door taken from arrays
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_doors_x_pos_hi+1,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_doors_y_pos_lo+1,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_doors_y_pos_hi+1,X
		INY
		TYA									; backup Y as door data position
		PHA									; we will use Y here to other calcs
		LDA		(_room_doors_data_ptr),Y	; diminsions are fixed for particular door
		TAY									; and fetched from arrays additionally
		LDA		_doors_width_list,Y
		STA		_doors_width+1,X
		LDA		_doors_height_list,Y
		STA		_doors_height+1,X
		PLA									; restore door data pos, adjust to the next
		TAY
		INY
		INY
		INX
		BNE		loc_162B8
loc_162F0:
		TYA
		CLC
		ADC		#$06
		TAY
		BNE		loc_162B8
loc_162F7:
		STX		_cur_room_doors_cnt
		RTS

_doors_width_list:
		.BYTE	$10,$04,$10,$04,$08,$10,$10,$10,$10,$04,$04,$04,$04,$04,$10,$04,$04
_doors_height_list:
		.BYTE	$0F,$10,$04,$10,$0F,$0F,$0F,$0F,$0F,$10,$10,$10,$10,$08,$0F,$10,$10

; =============== S U B R O U T I N E ======n================================
_nsub_room_init:
		JSR		_scr_getc
		STA		_cur_lvl_room_idx
		JSR		_scr_getc					; most of room draw called from scripts
		STA		_cur_room_orientation_idx
		JSR		_scr_getc
		STA		_cur_room_data_col
		JSR		_scr_getc
		STA		_cur_room_data_row
		JSR		_room_draw
		LDY		#$00
		JSR		_scr_getc
		STA		_room_prize_sequence_ptr
		JSR		_scr_getc
		STA		_room_prize_sequence_ptr+1
		JSR		_scr_getc
		STA		_room_exits_ptr
		JSR		_scr_getc
		STA		_room_exits_ptr+1
		JSR		_scr_getc					; initialize doors data pointer
		STA		_room_doors_data_ptr
		JSR		_scr_getc
		STA		_room_doors_data_ptr+1
		LDA		#$FF
		STA		_active_door_data_pos		; init to make sure this thread will
		STA		_trds_obj_idx+1				; load in slot 01
		LDA		#$01						; also run the doors handler thread
		STA		_var4
		LDA		#$02
		STA		_var5
		LDA		#$0C
		JMP		_thread_lib_load

; =============== S U B R O U T I N E ======n================================
_nsub_player_to_doors_ctest:
		LDA		#$00						; now doors thread constantly polling
		STA		_active_door_data_pos		; this routine
loc_16341:
		LDY		_active_door_data_pos		; fetch all doors data from array
		LDA		(_room_doors_data_ptr),Y
		BMI		loc_16366
		JSR		_room_door_screen_pos_calc	; calculates its screen position
		BCS		loc_1635B
		LDA		#$02
		JSR		_obj_to_room_door_distance_test	; test distance to both players.
		BCC		loc_1636B					; yes, catcher can't open the door
		LDA		#$04						; but he definitely don't let it to close
		JSR		_obj_to_room_door_distance_test
		BCC		loc_1636B
loc_1635B:
		LDA		_active_door_data_pos		; skip if no doors nearby
		CLC
		ADC		#$06
		STA		_active_door_data_pos
		BNE		loc_16341
loc_16366:
		STA		_active_door_data_pos		; and exit
		CLC
		RTS
loc_1636B:
		TYA									; backup current y pos of player 2 (in Y)
		PHA
		LDY		_active_door_data_pos		; load its offset in data array
		INY									; calculated during tests
		INY
		INY
		INY
		INY
		LDA		(_room_doors_data_ptr),Y
		ASL
		TAY
		LDA		_doors_open_handlers,Y
		STA		_ptr06
		LDA		_doors_open_handlers+1,Y
		STA		_ptr06+1
		PLA
		TAY
		JSR		_jmp_ptr06					; and run it, if door allowed to open
		BCC		loc_1635B					; CARRY=1 returned
		LDX		_cur_trd_slot				; if so, load current door coordinates
		LDY		_active_door_data_pos		; as current thread object sprite coordinates
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_x_pos_hi,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_x_pos_lo,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_y_pos_hi,X
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_obj_y_pos_lo,X
		INY
		LDA		(_room_doors_data_ptr),Y
		SEC
		RTS

_doors_open_handlers:
		.WORD	_room_door_closed
		.WORD	_room_door_open
		.WORD	_room_door_test

; =============== S U B R O U T I N E ======n================================
_nsub_is_players_near_active_door:
		JSR		_active_door_screen_pos_calc; performs the door collision tests
		LDA		#$02						; for currently opened nearby door
		JSR		_obj_to_room_door_distance_test	; for both players
		BCC		locret_163B3
		LDA		#$04
		JSR		_obj_to_room_door_distance_test
locret_163B3:
		RTS

; =============== S U B R O U T I N E ======n================================
; special collision test for doors uses fixed activation area for it in
; 32x32 pixels
; input X/Y screen position of nearby door
;       A - index of object to test against the door
; procedure does not destroy X/Y values, so they can be used after
;
_obj_to_room_door_distance_test:
		STA		_tmp0						; keep idx safe
		STX		_tmp1						; backup X, Y safe here
		LDX		_tmp0						; restore index, do screen pos calcs
		LDA		_obj_out_of_screen,X
		BEQ		.room_on_screen
		SEC									; WARNING, this routine need the out of screen
		RTS
.room_on_screen
		LDA		_tmp1
		SEC
		SBC		_obj_x_screen_pos,X
		BCS		loc_163D1					; A=X here already, so du calc immediately
		EOR		#$FF
		ADC		#$01
loc_163D1:
		CMP		#$20
		BCS		locret_163E0
		TYA									; retrieve y pos from Y, Y still safe!
		SEC
		SBC		_obj_y_screen_pos,X
		BCS		loc_163DE
		EOR		#$FF
		ADC		#$01
loc_163DE:
		CMP		#$20						; exit also with CARRY as result!
locret_163E0:
		LDX		_tmp1						; restore X
		RTS

; =============== S U B R O U T I N E ======n================================
_active_door_screen_pos_calc:
		LDY		_active_door_data_pos		; calculated door screen pos for
		LDA		(_room_doors_data_ptr),Y	; active nearby door only

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_room_door_screen_pos_calc:
		STA		_tmp_var0					; calculate door screen pos for
		INY									; selected position of data
		LDA		(_room_doors_data_ptr),Y
		TAX
		INY
		LDA		(_room_doors_data_ptr),Y
		STA		_tmp_var1
		INY
		LDA		(_room_doors_data_ptr),Y
		TAY
		TXA
		SEC
		SBC		_ppu_scroll_pos_x
		TAX
		LDA		_tmp_var0
		SBC		_ppu_scroll_pos_x+1
		BNE		loc_61A3F
		TYA
		SBC		_ppu_scroll_pos_y
		BCS		loc_61A36
		SBC		#$0F
		CLC
loc_61A36:
		TAY
		LDA		_tmp_var1
		SBC		_ppu_scroll_pos_y+1
		BNE		loc_61A3F
		CLC
		RTS
loc_61A3F:
		SEC
		RTS

; =============== S U B R O U T I N E ======n================================
_room_door_test:
		STX		_tmp1						; this is the main routine to test
		LDX		#$06						; if all enemy objects in the room are
loc_16400:									; gone
		LDA		_trds_obj_idx,X				; fetch object index
		BMI		loc_16409
		CMP		#$13						; all objects above 13 are enemies
		BCS		_room_door_closed			; others aren't preventing doors to be shut
loc_16409:
		INX
		CPX		#$0E
		BCC		loc_16400
		LDX		_tmp1
#if TWO_PLAYER_MODE==1
		LDA		#$02
		JSR		_obj_to_room_door_distance_test
		BCC		_room_door_open
		LDA		#$04
		JSR		_obj_to_room_door_distance_test
#else
		LDA		#$02						; here is the additional test to be sure
		JSR		_obj_to_room_door_distance_test	; this is the main player want to open it
#endif
		BCS		_room_door_closed

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_room_door_open:
		SEC									; default handler for always open door
		RTS

; =============== S U B R O U T I N E ======n================================
_room_door_closed:
		CLC									; the same for doors always closed
		RTS

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door00_opened:
		NJSR			_nsub_door00_open_draw			; skip sound and open animation
		SJMPS			_ssub_door00_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door00_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door00_open_draw
		SPR_IDX_SET		6,$00							; there are only one additional
		SPR_IDX_SET		0,$FF							; phase for door opening, then disable sprite

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door00_wait:
		SJSRS			_ssub_wait_for_door_is_inactive	; now wait for players leave the door area
		NJSR			_nsub_apu_snd_load				; in this case play shut down sound
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$00							; and animate door close the same way it was
		SPR_IDX_SET		0,$FF							; animated open
		NJSR			_nsub_door00_close_draw			; now draw meta tile for closed door
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_wait_for_door_is_inactive:
		SDELAY			$01								; common routine for waiting the players to
		NJSR			_nsub_is_players_near_active_door	; leave active door area
		SBCCS			_ssub_wait_for_door_is_inactive
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door00_open_draw:
		LDA		#<[_mac_door00_open]
		LDX		#>[_mac_door00_open]
		JMP		_door_macro_drawA
_mac_door00_open:
		.BYTE	$14,$14,$14,$14

; =============== S U B R O U T I N E ======n================================
_nsub_door00_close_draw:
		LDA		#<[_mac_door00_close]
		LDX		#>[_mac_door00_close]
		JMP		_door_macro_drawA
_mac_door00_close:
		.BYTE	$1A,$1B,$0A,$0B

; =============== S U B R O U T I N E ======n================================
_door_macro_drawB:
		LDY		#$01						; for edge-oriented vert doors (1x2)
		BNE		_door_macro_draw_common

; =============== S U B R O U T I N E ======n================================
_door_macro_drawA:
		LDY		#$03						; draw the face oriented doors (2x2)

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_door_macro_draw_common:
		STA		_ptr06
		STX		_ptr06+1					; based on the object sprite coordinates
loc_16460:
		TYA
		PHA
		LDA		_ptr06
		PHA
		LDA		_ptr06+1
		PHA
		LDA		(_ptr06),Y
		PHA
		LDA		_obj_x_pos_lo+1
		CLC
		ADC		_door_x_lo_deltasA,Y
		TAX
		LDA		_obj_x_pos_hi+1
		ADC		_door_x_hi_deltasA,Y
		STA		_tmp_var0
		LDA		_obj_y_pos_lo+1
		CLC
		ADC		_door_y_lo_deltasA,Y
		PHA
		LDA		_obj_y_pos_hi+1
		ADC		_door_y_hi_deltasA,Y
		STA		_tmp_var1
		PLA
		TAY
		PLA
		JSR		_far_ppu_macro_block_draw
		PLA
		STA		_ptr06+1
		PLA
		STA		_ptr06
		PLA
		TAY
		DEY
		BPL		loc_16460
		RTS
_door_x_lo_deltasA:
		.BYTE	$00,$00,$F0,$F0
_door_x_hi_deltasA:
		.BYTE	$00,$00,$FF,$FF
_door_y_lo_deltasA:
		.BYTE	$F0,$00,$F0,$00
_door_y_hi_deltasA:
		.BYTE	$FF,$00,$FF,$00

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door01_opened:
		NJSR			_nsub_door01_open_draw
		SJMPS			_ssub_door01_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door01_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door01_open_draw
		SPR_IDX_SET		6,$01
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door01_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$01
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door01_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door01_open_draw:
		LDA		#<[_mac_door01_open]
		LDX		#>[_mac_door01_open]
		JMP		_door_macro_drawB
_mac_door01_open:
		.BYTE	$00,$00

; =============== S U B R O U T I N E ======n================================
_nsub_door01_close_draw:
		LDA		#<[_mac_door01_close]
		LDX		#>[_mac_door01_close]
		JMP		_door_macro_drawB
_mac_door01_close:
		.BYTE	$29,$29

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door02_opened:
		NJSR			_nsub_door02_open_draw
		SJMPS			_ssub_door02_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door02_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door02_open_draw
		SPR_IDX_SET		2,$02							; this is a mine door, it has
		SPR_IDX_INC		2								; a lot more detailed animation
		SPR_IDX_INC		2
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door02_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		2,$04
		SPR_IDX_DEC		2
		SPR_IDX_DEC		2
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door02_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door02_open_draw:
		LDA		#<[_mac_door2_open]
		LDX		#>[_mac_door2_open]
		JMP		_door_macro_drawC

_mac_door2_open:
		.BYTE	$14,$14

; =============== S U B R O U T I N E ======n================================
_nsub_door02_close_draw:
		LDA		#<[_mac_door2_closed]
		LDX		#>[_mac_door2_closed]
		JMP		_door_macro_drawC

_mac_door2_closed:
		.BYTE	$0B,$1B

; =============== S U B R O U T I N E ======n================================
_door_macro_drawC:
		STA		_ptr06
		STX		_ptr06+1
		LDY		#$01						; horizontal oriented 2x1
loc_1655C:
		TYA
		PHA
		LDA		_ptr06
		PHA
		LDA		_ptr06+1
		PHA
		LDA		(_ptr06),Y
		PHA
		LDA		_obj_x_pos_lo+1
		CLC
		ADC		_door_y_lo_deltasA,Y		; NOTE: delta array for X here
		TAX									; is the same as delta array for Y in
		LDA		_obj_x_pos_hi+1				; drawA/B routines, merge
		ADC		_door_y_hi_deltasA,Y
		STA		_tmp_var0
		LDY		_obj_y_pos_lo+1
		LDA		_obj_y_pos_hi+1
		STA		_tmp_var1
		PLA									; both open macros are the same here
		JSR		_far_ppu_macro_block_draw	; hardcoded as a constant
		PLA
		STA		_ptr06+1
		PLA
		STA		_ptr06
		PLA
		TAY
		DEY
		BPL		loc_1655C
		RTS

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door03_opened:
		NJSR			_nsub_door03_open_draw
		SJMPS			_ssub_door03_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door03_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door03_open_draw
		SPR_IDX_SET		3,$05							; this is a door for train
		SPR_IDX_INC		3								; aprt of lvl2
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door03_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		3,$06
		SPR_IDX_DEC		3
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door03_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door03_open_draw:
		LDA		#<[_mac_door03_open]		; this is 1x2 door so utilizes
		LDX		#>[_mac_door03_open]		; one of common routines to draw
		JMP		_door_macro_drawB			; vertical 1x2 macroses
_mac_door03_open:
		.BYTE	$2C,$14

; =============== S U B R O U T I N E ======n================================
_nsub_door03_close_draw:
		LDA		#<[_mac_door03_close]
		LDX		#>[_mac_door03_close]
		JMP		_door_macro_drawB
_mac_door03_close:
		.BYTE	$D3,$D2

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door04_opened:
		NJSR			_nsub_door04_open_draw
		SJMPS			_ssub_door04_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door04_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door04_open_draw
		SPR_IDX_SET		6,$07
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door04_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$07
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door04_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door04_open_draw:
		LDA		#<[_mac_door04_open]
		LDX		#>[_mac_door04_open]
		JMP		_door_macro_drawA
_mac_door04_open:
		.BYTE	$97,$98,$87,$88

; =============== S U B R O U T I N E ======n================================
_nsub_door04_close_draw:
		LDA		#<[_mac_door04_close]
		LDX		#>[_mac_door04_close]
		JMP		_door_macro_drawA
_mac_door04_close:
		.BYTE	$D6,$D7,$D4,$D5

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door05_opened:
		NJSR			_nsub_door05_open_draw
		SJMPS			_ssub_door05_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door05_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door05_open_draw
		SPR_IDX_SET		6,$08
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door05_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$08
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door05_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door05_open_draw:
		LDA		#<[_mac_door05_open]
		LDX		#>[_mac_door05_open]
		JMP		_door_macro_drawA
_mac_door05_open:
		.BYTE	$01,$01,$01,$01

; =============== S U B R O U T I N E ======n================================
_nsub_door05_close_draw:
		LDA		#<[_mac_door05_close]
		LDX		#>[_mac_door05_close]
		JMP		_door_macro_drawA
_mac_door05_close:
		.BYTE	$1A,$1B,$0A,$0B

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door06_opened:
		NJSR			_nsub_door06_open_draw
		SJMPS			_ssub_door06_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door06_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door06_open_draw
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door06_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd0A_idx
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door06_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door06_open_draw:
		LDA		#<[_mac_door06_open]
		LDX		#>[_mac_door06_open]
		JMP		_door_macro_drawA
_mac_door06_open:
		.BYTE	$00,$00,$00,$00

; =============== S U B R O U T I N E ======n================================
_nsub_door06_close_draw:
		LDA		#<[_mac_door06_close]
		LDX		#>[_mac_door06_close]
		JMP		_door_macro_drawA
_mac_door06_close:
		.BYTE	$50,$51,$40,$41

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door07_opened:
		NJSR			_nsub_door07_open_draw
		SJMPS			_ssub_door07_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door07_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door07_open_draw
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door07_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$09
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door06_close_draw			; closed state for both doors are
		SRET											; the same here, open are different

; =============== S U B R O U T I N E ======n================================
_nsub_door07_open_draw:
		LDA		#<[_mac_door07_open]
		LDX		#>[_mac_door07_open]
		JMP		_door_macro_drawA
_mac_door07_open:
		.BYTE	$26,$26,$26,$26

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door08_opened:
		NJSR			_nsub_door08_open_draw
		SJMPS			_ssub_door08_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door08_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door08_open_draw
		SPR_IDX_SET		6,$0A
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door08_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$0A
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door08_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door08_open_draw:
		LDA		#<[_mac_door08_open]
		LDX		#>[_mac_door08_open]
		JMP		_door_macro_drawA
_mac_door08_open:
		.BYTE	$20,$97,$20,$96

; =============== S U B R O U T I N E ======n================================
_nsub_door08_close_draw:
		LDA		#<[_mac_door08_close]
		LDX		#>[_mac_door08_close]
		JMP		_door_macro_drawA
_mac_door08_close:
		.BYTE	$8D,$8E,$8B,$8C

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door09_opened:
		SARG_SET		SARG0,$00

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_lvl4_doos_openedB:
		NJSR			_nsub_lvl4_doors_open_drawB
		SJMPS			_ssub_lvl4_doos_waitB

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door09_anim:
		SARG_SET		SARG0,$00

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_lvl4_doos_animB:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_lvl4_doors_open_drawB
		SPR_IDX_SET		6,$0B
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_lvl4_doos_waitB:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$0B
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_lvl4_doors_close_drawB
		SRET

_mac_door09_open:
		.BYTE	$17,$98
_mac_door09_close:
		.BYTE	$95,$91

; =============== S U B R O U T I N E ======n================================
_nsub_lvl4_doors_open_drawB:
		LDX		_cur_trd_slot
		LDY		_trds_args0,X

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nsub_lvl4_doors_open_drawB_ex:
		LDA		_lvl4_mac_open_lib_lo,Y
		LDX		_lvl4_mac_open_lib_hi,Y
		JMP		_door_macro_drawB

_lvl4_mac_open_lib_lo:
		.BYTE	<[_mac_door09_open]
		.BYTE	<[_mac_door0A_open]
		.BYTE	<[_mac_door0B_open]
		.BYTE	<[_mac_door0C_open]
_lvl4_mac_open_lib_hi:
		.BYTE	>[_mac_door09_open]
		.BYTE	>[_mac_door0A_open]
		.BYTE	>[_mac_door0B_open]
		.BYTE	>[_mac_door0C_open]

; =============== S U B R O U T I N E ======n================================
; NOTE: manual selection of the door open routines to be used in pause
; screen to restore currently opened door after return from pause mode
; since they optimized it with indexed arrays instead of using
; direct offset loading as usual...
;
_nsub_door09_open_draw:
		LDY		#$00
		BEQ		_nsub_lvl4_doors_open_drawB_ex

; =============== S U B R O U T I N E ======n================================
_nsub_door0A_open_draw:
		LDY		#$01
		BNE		_nsub_lvl4_doors_open_drawB_ex

; =============== S U B R O U T I N E ======n================================
_nsub_door0B_open_draw:
		LDY		#$02
		BNE		_nsub_lvl4_doors_open_drawB_ex

; =============== S U B R O U T I N E ======n================================
_nsub_door0C_open_draw:
		LDY		#$03
		BNE		_nsub_lvl4_doors_open_drawB_ex

; =============== S U B R O U T I N E ======n================================
; no need to call it from any wrappers this time
;
_nsub_lvl4_doors_close_drawB:
		LDX		_cur_trd_slot
		LDY		_trds_args0,X
		LDA		_lvl4_mac_close_lib_lo,Y
		LDX		_lvl4_mac_close_lib_hi,Y
		JMP		_door_macro_drawB

_lvl4_mac_close_lib_lo:
		.BYTE	<[_mac_door09_close]
		.BYTE	<[_mac_door0A_close]
		.BYTE	<[_mac_door0B_close]
		.BYTE	<[_mac_door0C_close]
_lvl4_mac_close_lib_hi:
		.BYTE	>[_mac_door09_close]
		.BYTE	>[_mac_door0A_close]
		.BYTE	>[_mac_door0B_close]
		.BYTE	>[_mac_door0C_close]

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0A_opened:
		SARG_SET		SARG0,$01
		SJMPS			_ssub_lvl4_doos_openedB

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0A_anim:
		SARG_SET		SARG0,$01
		SJMPS			_ssub_lvl4_doos_animB

_mac_door0A_open:
		.BYTE	$4E,$98
_mac_door0A_close:
		.BYTE	$99,$91

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0B_opened:
		SARG_SET		SARG0,$02
		SJMPS			_ssub_lvl4_doos_openedB

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0B_anim:
		SARG_SET		SARG0,$02
		SJMPS			_ssub_lvl4_doos_animB

_mac_door0B_open:
		.BYTE	$51,$9B
_mac_door0B_close:
		.BYTE	$8F,$9A

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0C_opened:
		SARG_SET		SARG0,$03
		SJMP			_ssub_lvl4_doos_openedB

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0C_anim:
		SARG_SET		SARG0,$03
		SJMPS			_ssub_lvl4_doos_animB

_mac_door0C_open:
		.BYTE	$22,$98
_mac_door0C_close:
		.BYTE	$90,$91

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0D_opened:
		NJSR			_nsub_door0D_open_draw
		SJMPS			_ssub_door0D_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
; the difference between previous doors and this one in
; open animation scprite. it's different now, so they put it
; in a separate script case...
;
_ssub_door0D_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door0D_open_draw
		SPR_IDX_SET		6,$0C
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0D_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$0C
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door0D_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door0D_open_draw:
		LDA		#<[_mac_door0D_open]
		LDX		#>[_mac_door0D_open]
		JMP		_door_macro_drawB
_mac_door0D_open:
		.BYTE	$20,$96

; =============== S U B R O U T I N E ======n================================
_nsub_door0D_close_draw:
		LDA		#<[_mac_door0D_close]
		LDX		#>[_mac_door0D_close]
		JMP		_door_macro_drawB
_mac_door0D_close:
		.BYTE	$8B,$8C

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door10_opened:
		NJSR			_nsub_door10_open_draw
		SJMPS			_ssub_door10_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door10_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door10_open_draw
		SPR_IDX_SET		6,$0D
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door10_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		6,$0D
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door10_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door10_open_draw:
		LDA		#<[_mac_door10_open]
		LDX		#>[_mac_door10_open]
		JMP		_door_macro_drawB
_mac_door10_open:
		.BYTE	$22,$9E

; =============== S U B R O U T I N E ======n================================
_nsub_door10_close_draw:
		LDA		#<[_mac_door10_close]
		LDX		#>[_mac_door10_close]
		JMP		_door_macro_drawB
_mac_door10_close:
		.BYTE	$9C,$9D

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0E_opened:
		NJSR			_nsub_door0E_open_draw
		SJMPS			_ssub_door0E_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0E_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door0E_open_draw
		SPR_IDX_SET		1,$0E
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0E_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		1,$10
		SPR_IDX_DEC		1
		SPR_IDX_DEC		1
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door0E_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door0E_open_draw:
		LDA		#<[_mac_door0E_open]
		LDX		#>[_mac_door0E_open]
		JMP		_door_macro_drawA
_mac_door0E_open:
		.BYTE	$14,$55,$14,$55

; =============== S U B R O U T I N E ======n================================
_nsub_door0E_close_draw:
		LDA		#<[_mac_door0E_close]
		LDX		#>[_mac_door0E_close]
		JMP		_door_macro_drawA
_mac_door0E_close:
		.BYTE	$1A,$1B,$0A,$0B

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0F_opened:
		NJSR			_nsub_door0F_open_draw
		SJMPS			_ssub_door0F_wait

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0F_anim:
		NJSR			_nsub_apu_snd_load
			NARGB		_snd07_idx
		NJSR			_nsub_door0F_open_draw
		SPR_IDX_SET		2,$11
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_INC		2
		SPR_IDX_SET		0,$FF

; FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_door0F_wait:
		SJSR			_ssub_wait_for_door_is_inactive
		NJSR			_nsub_apu_snd_load
			NARGB		_snd06_idx
		SPR_IDX_SET		2,$14
		SPR_IDX_DEC		2
		SPR_IDX_DEC		2
		SPR_IDX_DEC		2
		SPR_IDX_SET		0,$FF
		NJSR			_nsub_door0F_close_draw
		SRET

; =============== S U B R O U T I N E ======n================================
_nsub_door0F_open_draw:
		LDA		#<[_mac_door0F_open]
		LDX		#>[_mac_door0F_open]
		JMP		_door_macro_drawB
_mac_door0F_open:
		.BYTE	$00,$00

; =============== S U B R O U T I N E ======n================================
_nsub_door0F_close_draw:
		LDA		#<[_mac_door0F_close]
		LDX		#>[_mac_door0F_close]
		JMP		_door_macro_drawB
_mac_door0F_close:
		.BYTE	$29,$29

		SECTION_END	"SCR0C DOORS HANDLERS"

		SECTION_START

; =============== S C R I P T ==========================s====================
; NOTE: judging from the script structure and some unused sprites data,
; they seems planned to have more prizes than one little bag.
;
		FAR_OFS			_scr0D_money_bag
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_money_bag_prize

; NOTE: here were unreferenced sprites to draw rotating coin object.
; judging from the starting section of this script there may be a
; different modes for this object with either spitting coins or
; something... or else this initializer just redundant here

; =============== S C R I P T ==========================s====================
_money_bag_prize:
		SARG_SET		SARG0,$00
_sloc_16969:
		SDELAY			$01
		NJSR			_nsub_prize_sequence_completed_test	; wait for prize sequence completed
#if DEBUG==0
		SBCCS			_sloc_16969
#endif
		SARG_SET		SARG2,$1E						; set the money amount for this bonus.
		NBG_HNDL_SET	_nbgsub_money_bag_ctest			; now load collision test routine
_sloc_16977:
		SPR_IDX_SET		2,$19							; and just wait it it happens in infinite loop
		SPR_IDX_INC		2
		SJMPS			_sloc_16977

; =============== S U B R O U T I N E ======n================================
_nbgsub_money_bag_ctest:
		LDX		#$0D						; fixed dimensions for collision test.
		LDY		#$0E
		JMP		_prize_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_prize_sequence_completed_test:
		LDA		_room_prize_sequence_ptr	; prize sequence handled in catch routine
		ORA		_room_prize_sequence_ptr+1	; when done, zeroes the pointer, so the
		BNE		loc_1698C					; prize script check if it zero or not
		SEC
		RTS
loc_1698C:
		CLC
		RTS

		SECTION_END	"SCR0D MONEY BAG"

		SECTION_START

_spr_libA01:
		.WORD	_sprA01_00	; doors open anims
		.WORD	_sprA01_01
		.WORD	_sprA01_02
		.WORD	_sprA01_03
		.WORD	_sprA01_04
		.WORD	_sprA01_05
		.WORD	_sprA01_06
		.WORD	_sprA01_07
		.WORD	_sprA01_08
		.WORD	_sprA01_09
		.WORD	_sprA01_0A
		.WORD	_sprA01_0B
		.WORD	_sprA01_0C
		.WORD	_sprA01_0D
; NOTE: for some reason, the prev to last level's doors uses sprite pal 0
; as the players itself, so when doors are animated they turns blue for.
; however, when using colors 2 or 3, they may still be yellowish without
; much modifications...
; NEW, fixed colors for those sprites for a great justice
		.WORD	_sprA01_0E
		.WORD	_sprA01_0F
		.WORD	_sprA01_10
		.WORD	_sprA01_11
		.WORD	_sprA01_12
		.WORD	_sprA01_13
		.WORD	_sprA01_14
		.WORD	_sprA01_15	; pause mode sprites
		.WORD	_sprA01_16
		.WORD	_sprA01_17	; stage complete sprites
		.WORD	_sprA01_18
		.WORD	_sprA01_19	; money bag prize
		.WORD	_sprA01_1A
; NEW, readded coin
		.WORD	_sprA01_1B
		.WORD	_sprA01_1C
		.WORD	_sprA01_1D
		.WORD	_sprA01_1E

_sprA01_00:
		.BYTE	$04
		.BYTE	$F0,$31,$43,$08
		.BYTE	$00,$33,$43,$08
		.BYTE	$00,$33,$03,$F0
		.BYTE	$F0,$31,$03,$F0
_sprA01_01:
		.BYTE	$02
		.BYTE	$F0,$EF,$83,$00
		.BYTE	$00,$EF,$03,$00
_sprA01_02:
		.BYTE	$06
		.BYTE	$0B,$F9,$43,$00
		.BYTE	$0B,$F9,$43,$F8
		.BYTE	$0B,$F9,$03,$F0
		.BYTE	$F8,$FB,$03,$00
		.BYTE	$F8,$EB,$03,$F8
		.BYTE	$F8,$DB,$03,$F0
_sprA01_03:
		.BYTE	$04
		.BYTE	$0B,$F9,$03,$F8
		.BYTE	$0B,$F9,$03,$F0
		.BYTE	$F8,$DD,$03,$F8
		.BYTE	$F8,$CD,$03,$F0
_sprA01_04:
		.BYTE	$02
		.BYTE	$0B,$F9,$03,$F0
		.BYTE	$F4,$CB,$03,$F1
_sprA01_05:
		.BYTE	$01
		.BYTE	$00,$D9,$03,$FF
_sprA01_06:
		.BYTE	$01
		.BYTE	$00,$E9,$03,$FF
_sprA01_07:
		.BYTE	$02
		.BYTE	$F0,$AF,$40,$F8
		.BYTE	$00,$8B,$40,$F8
_sprA01_08:
		.BYTE	$04
		.BYTE	$00,$43,$02,$08
		.BYTE	$F0,$41,$02,$08
		.BYTE	$F0,$41,$42,$F0
		.BYTE	$00,$43,$42,$F0
_sprA01_09:
		.BYTE	$04
		.BYTE	$00,$23,$02,$08
		.BYTE	$F0,$21,$02,$08
		.BYTE	$00,$33,$02,$F0
		.BYTE	$F0,$31,$02,$F0
_sprA01_0A:
		.BYTE	$04
		.BYTE	$00,$CF,$00,$08
		.BYTE	$00,$CF,$00,$00
		.BYTE	$00,$CF,$00,$F0
		.BYTE	$00,$CF,$00,$F8
_sprA01_0B:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$00
		.BYTE	$00,$DF,$00,$00
_sprA01_0C:
		.BYTE	$02
		.BYTE	$00,$CF,$00,$08
		.BYTE	$00,$CF,$00,$00
_sprA01_0D:
		.BYTE	$02
		.BYTE	$F0,$DD,$00,$08
		.BYTE	$00,$DF,$00,$08
_sprA01_0E:
		.BYTE	$08
		.BYTE	$F0,$7D,$03,$08
		.BYTE	$F0,$7D,$03,$00
		.BYTE	$F0,$7D,$03,$F8
		.BYTE	$F0,$7D,$03,$F0
		.BYTE	$00,$7F,$03,$F0
		.BYTE	$00,$7F,$03,$08
		.BYTE	$00,$7F,$03,$00
		.BYTE	$00,$7F,$03,$F8
_sprA01_0F:
		.BYTE	$04
		.BYTE	$00,$6F,$03,$08
		.BYTE	$00,$6F,$03,$00
		.BYTE	$00,$6F,$03,$F8
		.BYTE	$00,$6F,$03,$F0
_sprA01_10:
		.BYTE	$04
		.BYTE	$00,$7D,$03,$08
		.BYTE	$00,$7D,$03,$00
		.BYTE	$00,$7D,$03,$F8
		.BYTE	$00,$7D,$03,$F0
_sprA01_11:
		.BYTE	$02
		.BYTE	$F4,$5F,$03,$00
		.BYTE	$00,$5F,$03,$00
_sprA01_12:
		.BYTE	$02
		.BYTE	$F8,$5D,$03,$00
		.BYTE	$00,$5D,$03,$00
_sprA01_13:
		.BYTE	$02
		.BYTE	$FC,$5D,$03,$00
		.BYTE	$00,$5D,$03,$00
_sprA01_14:
		.BYTE	$01
		.BYTE	$00,$6D,$03,$00
_sprA01_15:
		.BYTE	$07
		.BYTE	$00,$0F,$22,$F0
		.BYTE	$00,$1F,$22,$F8
		.BYTE	$00,$3D,$22,$08
		.BYTE	$00,$3F,$22,$00
		.BYTE	$F0,$0D,$22,$F0
		.BYTE	$F0,$1D,$22,$F8
		.BYTE	$F0,$3B,$22,$00
_sprA01_16:
		.BYTE	$07
		.BYTE	$00,$0F,$62,$08
		.BYTE	$00,$1F,$62,$00
		.BYTE	$00,$3D,$62,$F0
		.BYTE	$00,$3F,$62,$F8
		.BYTE	$F0,$0D,$62,$08
		.BYTE	$F0,$1D,$62,$00
		.BYTE	$F0,$3B,$62,$F8
_sprA01_17:
		.BYTE	$10
		.BYTE	$00,$8E,$03,$18
		.BYTE	$00,$8C,$03,$10
		.BYTE	$00,$8A,$03,$08
		.BYTE	$00,$88,$03,$00
		.BYTE	$00,$7E,$03,$F8
		.BYTE	$00,$7C,$03,$F0
		.BYTE	$00,$7A,$03,$E8
		.BYTE	$00,$78,$03,$E0
		.BYTE	$F0,$76,$03,$18
		.BYTE	$F0,$74,$03,$10
		.BYTE	$F0,$72,$03,$08
		.BYTE	$F0,$68,$03,$E0
		.BYTE	$F0,$6A,$03,$E8
		.BYTE	$F0,$6C,$03,$F0
		.BYTE	$F0,$6E,$03,$F8
		.BYTE	$F0,$70,$03,$00
_sprA01_18:
		.BYTE	$10
		.BYTE	$00,$8F,$03,$18
		.BYTE	$00,$8D,$03,$10
		.BYTE	$00,$8B,$03,$08
		.BYTE	$00,$89,$03,$00
		.BYTE	$00,$7F,$03,$F8
		.BYTE	$00,$7D,$03,$F0
		.BYTE	$00,$7B,$03,$E8
		.BYTE	$00,$79,$03,$E0
		.BYTE	$F0,$77,$03,$18
		.BYTE	$F0,$75,$03,$10
		.BYTE	$F0,$73,$03,$08
		.BYTE	$F0,$69,$03,$E0
		.BYTE	$F0,$6B,$03,$E8
		.BYTE	$F0,$6D,$03,$F0
		.BYTE	$F0,$6F,$03,$F8
		.BYTE	$F0,$71,$03,$00
_sprA01_19:
		.BYTE	$02
		.BYTE	$F8,$BD,$00,$00
		.BYTE	$F8,$AD,$00,$F8
_sprA01_1A:
		.BYTE	$02
		.BYTE	$F8,$BD,$01,$00
		.BYTE	$F8,$AD,$01,$F8
_sprA01_1B:
		.BYTE	$02
		.BYTE	$F8,$BB,$00,$00
		.BYTE	$F8,$AB,$00,$F8
_sprA01_1C:
		.BYTE	$01
		.BYTE	$F8,$BF,$00,$FC
_sprA01_1D:
		.BYTE	$01
		.BYTE	$F8,$AF,$00,$FC
_sprA01_1E:
		.BYTE	$01
		.BYTE	$F8,$BF,$40,$FC

		SECTION_END	"PRG1 SPRITES DATA"

		SECTION_START

		FAR_OFS	_lvl1

_lvl1_objects_list:
		CHECKPOINT
		OBJ_SET	_scr13_slow_moving_slime,			$30,$02,$88,$03,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$70,$03,$98,$03,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$A0,$03,$78,$03,_NON,_NON,_NON
		OBJ_SET	_scr17_runner,						$D0,$03,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$70,$03,$A0,$03, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AD, $02
		ROOM	$02
		OBJ_SET	_scr1C_girl_and_floaters,			$90,$04,$E0,$02,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AF, $03
		ROOM	$03
		CHECKPOINT
		OBJ_SET	_scr17_runner,						$A8,$03,$C0,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr18_chain_saw,					$C8,$03,$70,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr18_chain_saw,					$50,$03,$40,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr18_chain_saw,					$10,$03,$60,$02,_NON,_NON,_NON
; -
; REGION, changed in the EU version
;		OBJ_SET	_scr13_slow_moving_slime,			$90,$02,$A0,$02,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$70,$02,$A0,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr14_fast_moving_slime,			$D0,$02,$48,$02,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$80,$02,$50,$02, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AF, $04
		ROOM	$04
		OBJ_SET	_scr19_toilet_snake,				$78,$01,$50,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr13_slow_moving_slime,			$C8,$01,$68,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AD, $03
		ROOM	$03
		OBJ_SET	_scr13_slow_moving_slime,			$60,$02,$70,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr14_fast_moving_slime,			$A0,$02,$70,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AE, $00
		ROOM	$00
		OBJ_SET	_scr13_slow_moving_slime,			$98,$02,$A8,$03,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr14_fast_moving_slime,			$78,$02,$98,$03,_NON,_NON,_NON
; -
		OBJ_SET	_scr17_runner,						$80,$02,$48,$03,_NON,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AF, $01
		ROOM	$01
		CHECKPOINT
		OBJ_SET	_scr15_trolley_kick_slime,			$08,$01,$80,$03,_NON,_NON,_NON
		OBJ_SET	_scr16_still_throw_forward_slime,	$B8,$00,$A0,$03,_NON,_NON,_NON
		OBJ_SET	_scr16_still_throw_forward_slime,	$80,$00,$50,$03,_NON,_NON,_NON
		OBJ_SET	_scr16_still_throw_forward_slime,	$60,$00,$B0,$03,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$48,$01,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$40,$01,$B8,$03,_NON,_NON,_NON
		OBJ_SET	_scr13_slow_moving_slime,			$B8,$01,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$A0,$01,$B8,$03,_NON,_NON,_NON
		OBJ_SET	_scr0D_money_bag,					$B0,$00,$60,$03, $01,_NON,_NON
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AD, $00
		ROOM	$00
		OBJ_SET	_scr18_chain_saw,					$78,$02,$40,$03,_NON,_NON,_NON
		OBJ_SET	_scr18_chain_saw,					$B8,$02,$88,$03,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr18_chain_saw,					$88,$02,$98,$03,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $03
		ROOM	$03
		OBJ_SET	_scr17_runner,						$48,$02,$C8,$02,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$A8,$02,$88,$02,_NON,_NON,_NON
; REGION, removed in the EU version
		OBJ_SET	_scr17_runner,						$C8,$02,$C8,$02,_NON,_NON,_NON
		OBJ_SET	_scr14_fast_moving_slime,			$58,$02,$68,$02,_NON,_NON,_NON
; -
		OBJ_SET	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $05
		ROOM	$06
		CHECKPOINT
; REGION, added in the EU version
;		.BYTE	_scr12_exit_arrow,					$00,$00,$00,$00,_NON, $AC, $05
; -
		ROOM	$05
		OBJ_SET	_scr1B_court_chair,					$78,$02,$78,$01,_NON, $00,_NON
		OBJ_SET	_scr1B_court_chair,					$B8,$02,$58,$01,_NON, $01,_NON
		OBJ_SET	_scr1B_court_chair,					$48,$02,$58,$01,_NON, $02,_NON
		OBJ_SET	_scr1B_court_chair,					$68,$02,$38,$01,_NON, $03,_NON
; ADDED, here may be 5th chair object with different pattern, but currently game
; engine allows to add 4 enemies on the screen at once maximum. so this chair
; does may not appear at all if'd used. try to uncomment this and just wait until
; chair in the middle goes up and disappears out of the screen, then fifth chair
; will appear.
#if DEBUG==1
		OBJ_SET	_scr1B_court_chair,					$38,$02,$18,$01,_NON, $04,_NON
#endif
; -
		OBJ_SET	_scr1A_lvl1_boss_judges,			$80,$02,$40,$00,_NON,_NON, $00
		OBJ_END

_lvl1_collisionsA:
		.BYTE	$FF,$FC,$FB,$F3,$03,$DB,$03,$F7,$03,$F8,$0F,$FF,$7E,$FF,$7E,$7F
		.BYTE	$01,$00,$01,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
; never used, but configured to be usable..
_lvl1_collisionsB:
		.BYTE	$FC,$F7,$F8,$FB,$0C,$CE,$0F,$FF,$0B,$00,$07,$00,$F7,$00,$FB,$02
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
; no refrences at all.
;_unused_11:
;		.BYTE	$7F,$CE,$F7,$CF,$BC,$2E,$B3,$2C,$00,$00,$00,$04,$FE,$8F,$FC,$EC
;		.BYTE	$2F,$E0,$3E,$7F,$F8,$FD,$F4,$FF,$FF,$FF,$00,$03,$00,$00,$00,$00
_lvl1_macroA_tbl:
		.BYTE	$FF,$11,$12,$13,$05,$06,$08,$09,$1A,$00,$20,$22,$26,$28,$10,$24
		.BYTE	$00,$01,$02,$03,$15,$10,$00,$1A,$0A,$00,$20,$42,$46,$48,$09,$09
		.BYTE	$1F,$1C,$00,$55,$55,$6D,$FF,$1C,$15,$0E,$10,$2D,$2F,$2F,$6B,$26
		.BYTE	$4A,$15,$2B,$6F,$FF,$FF,$05,$28,$15,$5A,$09,$15,$2D,$2D,$1C,$05
		.BYTE	$15,$15,$15,$15,$64,$65,$65,$26,$3D,$67,$69,$1C,$1C,$15,$05,$6C
		.BYTE	$71,$72,$72,$15,$6A,$68,$67,$46,$5F,$26,$15,$67,$15,$05,$05,$15
		.BYTE	$0D,$26,$29,$5B,$46,$49,$FF,$1D,$0C,$FF,$FF,$4E,$11,$60,$01,$00
		.BYTE	$05,$36,$39,$5C,$39,$5C,$3D,$15,$FF,$FF,$7D,$7D,$0B,$70,$0A,$0C
		.BYTE	$2D,$45,$28,$6A,$04,$7D,$04,$24,$04,$14,$02,$1A,$2A,$40,$0A,$2C
		.BYTE	$63,$7D,$36,$38,$08,$46,$46,$7D,$6A,$15,$46,$7D,$76,$66,$18,$0C
		.BYTE	$00,$00,$0A,$10,$01,$7D,$7D,$7D,$18,$56,$66,$18,$56,$46,$0C,$0C
		.BYTE	$00,$00,$00,$00,$15,$01,$20,$FF,$1F,$09,$09,$00,$00,$05,$09,$97
		.BYTE	$60,$70,$05,$19,$05,$05,$00,$10,$10,$15,$0E,$3E,$00,$0D,$09,$97
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$60,$70
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl1_macroB_tbl:
		.BYTE	$FF,$00,$00,$05,$05,$16,$18,$00,$1A,$00,$30,$32,$36,$38,$4B,$34
		.BYTE	$00,$FF,$FF,$FF,$15,$FF,$00,$0A,$1A,$00,$30,$52,$56,$58,$FF,$00
		.BYTE	$1F,$15,$00,$55,$55,$7D,$15,$15,$15,$FF,$1F,$2D,$2D,$2D,$7B,$46
		.BYTE	$05,$15,$3A,$5A,$FF,$15,$05,$48,$15,$15,$00,$15,$3F,$3F,$15,$1A
		.BYTE	$15,$61,$62,$15,$74,$75,$74,$36,$5E,$15,$15,$68,$67,$15,$05,$7C
		.BYTE	$15,$1C,$1C,$15,$7A,$15,$15,$FF,$2A,$5C,$15,$69,$15,$05,$05,$44
		.BYTE	$05,$5C,$39,$5B,$26,$29,$4B,$15,$05,$4D,$4F,$15,$00,$7D,$FF,$00
		.BYTE	$05,$5C,$39,$46,$49,$5C,$5F,$15,$00,$4B,$7D,$7D,$FF,$FF,$1A,$1C
		.BYTE	$3D,$7D,$36,$7D,$6A,$04,$04,$04,$14,$24,$12,$2A,$3A,$40,$1A,$3C
		.BYTE	$73,$75,$36,$7D,$76,$15,$76,$7D,$7D,$76,$08,$46,$7D,$18,$56,$0C
		.BYTE	$00,$00,$FF,$00,$34,$7D,$7D,$7D,$76,$66,$18,$56,$66,$18,$0C,$0C
		.BYTE	$00,$00,$00,$00,$15,$00,$30,$FF,$FF,$FF,$4B,$09,$09,$87,$00,$05
		.BYTE	$7D,$FF,$05,$05,$05,$05,$00,$4B,$0E,$15,$1E,$15,$09,$87,$00,$05
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$7D,$00
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl1_macroC_tbl:
		.BYTE	$FF,$10,$13,$14,$05,$07,$15,$10,$1B,$1F,$21,$23,$27,$29,$10,$25
		.BYTE	$0C,$10,$03,$04,$15,$10,$05,$1B,$0B,$05,$41,$43,$47,$49,$10,$FF
		.BYTE	$1F,$1D,$55,$55,$6C,$6E,$15,$1C,$44,$0F,$10,$2D,$2E,$2D,$05,$29
		.BYTE	$4B,$15,$2C,$7F,$FF,$1D,$26,$29,$15,$5B,$05,$FF,$2D,$2D,$6B,$6A
		.BYTE	$15,$15,$15,$15,$65,$66,$65,$27,$15,$68,$15,$1C,$1C,$6B,$6A,$6D
		.BYTE	$72,$72,$73,$6B,$3D,$69,$77,$47,$15,$27,$15,$77,$78,$0C,$15,$45
		.BYTE	$0D,$28,$2D,$15,$48,$2D,$FF,$15,$0D,$FF,$4D,$4F,$60,$61,$01,$7D
		.BYTE	$05,$38,$2D,$5D,$2D,$5D,$15,$1C,$FF,$FF,$7D,$7D,$70,$71,$0B,$0D
		.BYTE	$44,$7D,$29,$6B,$05,$7D,$05,$25,$05,$7E,$03,$1B,$2A,$40,$2B,$2D
		.BYTE	$64,$7D,$37,$39,$57,$47,$46,$6A,$6A,$67,$47,$7D,$77,$57,$57,$7D
		.BYTE	$2C,$1C,$01,$01,$01,$65,$7D,$55,$57,$57,$57,$57,$57,$47,$7D,$65
		.BYTE	$62,$7D,$7D,$0D,$15,$01,$FF,$39,$1F,$1F,$1F,$05,$05,$05,$97,$97
		.BYTE	$60,$70,$1E,$05,$05,$19,$05,$10,$10,$15,$0F,$3F,$0C,$0D,$97,$97
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$7D,$7D
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl1_macroD_tbl:
		.BYTE	$FF,$4A,$05,$05,$05,$17,$15,$4A,$1B,$1F,$31,$33,$37,$39,$4C,$35
		.BYTE	$05,$FF,$FF,$FF,$15,$FF,$05,$0B,$1B,$54,$51,$53,$57,$59,$FF,$4A
		.BYTE	$1F,$15,$55,$55,$7C,$7E,$FF,$15,$15,$FF,$1F,$2D,$2D,$2D,$05,$49
		.BYTE	$05,$3C,$3B,$55,$FF,$FF,$46,$49,$45,$1D,$05,$15,$3E,$2D,$5A,$5A
		.BYTE	$60,$61,$63,$70,$74,$76,$74,$37,$15,$78,$15,$69,$77,$7B,$7A,$7D
		.BYTE	$1C,$1C,$1D,$7B,$5F,$15,$78,$FF,$15,$79,$68,$78,$15,$05,$15,$15
		.BYTE	$05,$5D,$2D,$15,$28,$2D,$4C,$15,$05,$4E,$15,$15,$7D,$7D,$FF,$7D
		.BYTE	$05,$5D,$2D,$48,$2D,$5D,$15,$15,$4A,$4C,$7D,$7D,$FF,$FF,$1B,$1D
		.BYTE	$54,$7D,$37,$7D,$6B,$05,$05,$05,$7E,$25,$13,$2A,$3B,$40,$3B,$3D
		.BYTE	$74,$7D,$37,$7D,$77,$67,$76,$7D,$7D,$77,$57,$47,$6A,$67,$57,$55
		.BYTE	$3C,$7D,$FF,$1D,$35,$7D,$55,$65,$77,$67,$57,$09,$57,$57,$7D,$7D
		.BYTE	$72,$1C,$0D,$7D,$15,$1D,$FF,$39,$FF,$FF,$4C,$05,$87,$87,$05,$05
		.BYTE	$7D,$FF,$05,$05,$19,$05,$19,$0E,$0F,$2E,$1F,$2F,$87,$87,$54,$05
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$7D,$7D
		.BYTE	$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
_lvl1_attrs_tbl:
		.BYTE	$00,$00,$00,$03,$00,$01,$03,$00,$00,$00,$02,$02,$02,$02,$00,$03
		.BYTE	$00,$00,$00,$00,$03,$00,$00,$00,$00,$00,$02,$02,$02,$02,$00,$00
		.BYTE	$00,$03,$00,$00,$00,$00,$02,$03,$03,$02,$00,$03,$03,$03,$03,$02
		.BYTE	$00,$03,$02,$00,$00,$02,$00,$00,$03,$03,$00,$03,$03,$03,$03,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$00,$03,$03,$03,$03,$03,$03,$03,$00
		.BYTE	$03,$03,$03,$03,$03,$03,$03,$00,$03,$00,$03,$03,$03,$00,$00,$00
		.BYTE	$00,$02,$02,$03,$02,$02,$00,$03,$00,$03,$03,$03,$00,$03,$00,$00
		.BYTE	$01,$02,$02,$02,$02,$02,$03,$03,$00,$00,$03,$02,$00,$03,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$01,$01,$01,$02,$02
		.BYTE	$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$00,$00,$02,$00,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02,$02
		.BYTE	$00,$00,$00,$00,$01,$00,$02,$02,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$03,$03,$00,$00,$00,$00,$00,$00,$00,$01,$02,$01,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$03,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_lvl1_rooms_lib:
		.WORD	      0,      0,_l1_r20,      0,      0,      0,      0,      0
		.WORD	      0,      0,_l1_r21,_l1_r31,      0,      0,      0,      0
		.WORD	      0,_l1_r12,_l1_r22,_l1_r32,_l1_r42,      0,      0,      0
		.WORD	_l1_r03,_l1_r13,_l1_r23,_l1_r33,_l1_r34,      0,      0,      0
_l1_r20:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$A3,$6F,$A0,$B0,$A1,$B2,$A0,$B0,$B3,$B1,$A0,$B0,$6F,$A2,$00
		.BYTE	$00,$A4,$89,$86,$89,$86,$89,$86,$89,$86,$89,$86,$89,$86,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$A7,$A6,$A5,$A7,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$AD,$AC,$AB,$AA,$A9,$A8,$97,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$88,$87,$88,$87,$88,$87,$83,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$AE,$AE,$9F,$AF,$AE,$AE,$AE,$AE,$9F,$AF,$AE,$AE,$6E,$00
		.BYTE	$00,$6E,$7B,$9B,$9E,$9D,$9C,$7B,$7B,$9B,$9E,$9D,$9C,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$85,$88,$87,$84,$7B,$7B,$85,$88,$87,$84,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$96,$97,$7B,$80,$90,$7B,$7B,$96,$97,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$9A,$99,$98,$7B,$81,$91,$7B,$7B,$95,$94,$97,$6E,$00
		.BYTE	$00,$6E,$7B,$88,$87,$83,$7B,$7B,$7B,$7B,$7B,$88,$87,$83,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$8A,$8A,$8A,$8A,$7B,$7B,$7B,$8A,$6E,$00
		.BYTE	$00,$6E,$7B,$82,$92,$92,$92,$92,$92,$92,$92,$92,$93,$7B,$6E,$00
_l1_r21:
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$8A,$7B,$8A,$8A,$8A,$8A,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$8A,$8A,$7B,$7B,$8A,$8A,$7B,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$8A,$7B,$7B,$8A,$8A,$8A,$8A,$7B,$7B,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$8A,$8A,$7B,$8A,$7B,$8A,$8A,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$B5,$6F,$6F,$6F,$6F,$6F,$0A,$1A,$6F,$6F,$6F,$6F,$6F,$6E,$00
		.BYTE	$00,$A4,$89,$86,$89,$86,$89,$0B,$1B,$89,$86,$89,$86,$89,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$C9,$B4,$B4,$CB,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$CA,$8B,$8C,$B4,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6C,$6F,$6F,$6F,$6F,$6F,$8B,$8C,$6F,$6F,$6F,$6F,$6F,$7C,$00
		.BYTE	$00,$6D,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$7D,$00
_l1_r12:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$01,$16
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$0E,$C5
		.BYTE	$00,$00,$00,$00,$01,$22,$22,$22,$22,$22,$22,$22,$22,$C6,$1E,$14
		.BYTE	$00,$00,$00,$00,$0E,$23,$23,$24,$23,$33,$23,$23,$20,$68,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$26,$26,$25,$26,$26,$26,$26,$08,$35,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$26,$26,$26,$26,$26,$26,$26,$26,$26,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$26,$26,$26,$26,$26,$47,$57,$26,$26,$15,$14
		.BYTE	$00,$00,$00,$00,$07,$BC,$0A,$1A,$BE,$16,$16,$16,$16,$C6,$1E,$14
		.BYTE	$00,$00,$00,$00,$0E,$BD,$0B,$1B,$BF,$C3,$70,$C2,$C4,$70,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$14
		.BYTE	$00,$00,$00,$00,$15,$14,$2F,$77,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$00,$00,$00,$00,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$16,$16,$16,$C6,$3A,$16,$16,$C6,$07,$16,$16,$C6,$16,$16,$07,$C6
		.BYTE	$C3,$C2,$04,$C5,$C3,$05,$C4,$04,$0E,$C5,$05,$04,$C3,$70,$0E,$04
_l1_r22:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$01,$16,$09,$10,$C6,$BC,$0A,$1A,$BE,$C6,$16,$16,$16,$16,$07
		.BYTE	$00,$0E,$C5,$17,$60,$05,$BD,$0B,$1B,$BF,$04,$C2,$C5,$C3,$05,$0E
		.BYTE	$C6,$1E,$14,$18,$21,$06,$14,$14,$14,$14,$14,$14,$14,$14,$06,$15
		.BYTE	$68,$15,$14,$0F,$38,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15
		.BYTE	$35,$15,$14,$40,$14,$38,$39,$14,$14,$14,$39,$14,$43,$14,$14,$15
		.BYTE	$26,$15,$14,$41,$50,$14,$14,$14,$14,$14,$14,$14,$44,$77,$14,$15
		.BYTE	$26,$15,$14,$41,$51,$14,$14,$14,$14,$14,$14,$14,$46,$27,$14,$15
		.BYTE	$C6,$1E,$14,$41,$51,$14,$53,$14,$14,$14,$14,$14,$46,$27,$14,$15
		.BYTE	$70,$15,$14,$41,$51,$14,$54,$21,$14,$39,$14,$14,$46,$27,$14,$15
		.BYTE	$14,$15,$14,$42,$52,$14,$14,$14,$14,$14,$14,$14,$45,$21,$14,$02
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$03
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14
		.BYTE	$16,$07,$C6,$09,$09,$09,$CC,$0A,$1A,$CE,$09,$09,$09,$09,$10,$07
		.BYTE	$70,$0E,$04,$17,$08,$18,$CD,$0B,$1B,$CF,$08,$18,$17,$18,$60,$0E
_l1_r32:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$16,$16,$C6,$16,$16,$C6,$16,$16,$16,$07,$C6,$16,$16,$16,$07,$16
		.BYTE	$04,$C3,$04,$C5,$04,$C3,$04,$C2,$C5,$0E,$C4,$04,$C3,$C5,$0E,$C3
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$14,$14,$14,$14,$29,$14
		.BYTE	$14,$14,$0C,$1C,$77,$14,$0C,$1C,$77,$15,$14,$14,$14,$14,$29,$14
		.BYTE	$14,$14,$0D,$1D,$21,$28,$0D,$1D,$21,$15,$14,$01,$BC,$21,$07,$C6
		.BYTE	$14,$14,$14,$38,$14,$14,$38,$14,$14,$15,$14,$0E,$BD,$14,$0E,$05
		.BYTE	$14,$14,$31,$14,$28,$0F,$28,$14,$14,$15,$14,$15,$14,$14,$15,$06
		.BYTE	$14,$28,$32,$14,$38,$14,$28,$2F,$77,$15,$14,$15,$28,$14,$15,$49
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$28,$14,$15,$14,$15,$14,$38,$15,$4A
		.BYTE	$16,$C6,$16,$16,$C6,$BC,$0A,$1A,$BE,$12,$14,$15,$14,$14,$15,$14
		.BYTE	$C4,$C2,$C3,$04,$C5,$BD,$0B,$1B,$BF,$13,$14,$15,$14,$14,$15,$28
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$59,$57,$15,$14
		.BYTE	$16,$16,$16,$16,$C6,$16,$16,$07,$C6,$16,$16,$3A,$16,$C6,$1E,$14
		.BYTE	$04,$C4,$C3,$C2,$C5,$04,$C4,$0E,$04,$04,$C3,$C4,$04,$04,$15,$14
_l1_r42:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$16,$07,$16,$C6,$16,$16,$16,$16,$C6,$16,$16,$C6,$16,$16,$11,$00
		.BYTE	$C5,$0E,$C3,$04,$C3,$04,$C2,$C4,$04,$C5,$04,$C3,$04,$C4,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$28,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$21,$07,$C6,$16,$09,$09,$09,$09,$10,$C6,$BC,$0A,$1A,$BE,$1E,$00
		.BYTE	$14,$0E,$05,$C5,$08,$17,$08,$08,$60,$05,$BD,$0B,$1B,$BF,$15,$00
		.BYTE	$14,$15,$06,$14,$08,$18,$17,$18,$21,$06,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$49,$38,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$4A,$14,$28,$0F,$28,$14,$14,$14,$14,$14,$14,$31,$15,$00
		.BYTE	$38,$15,$14,$14,$38,$14,$28,$14,$14,$14,$14,$28,$14,$32,$15,$00
		.BYTE	$14,$15,$28,$14,$14,$38,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$28,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$57,$15,$14,$14,$14,$14,$14,$14,$28,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$C6,$1E,$14,$38,$14,$14,$38,$14,$14,$14,$14,$14,$14,$14,$15,$00
_l1_r03:
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE	$00,$01,$16,$C6,$16,$16,$16,$C6,$16,$16,$C6,$16,$16,$16,$16,$07
		.BYTE	$00,$C7,$5E,$5D,$C2,$C4,$05,$04,$C4,$04,$04,$C3,$04,$C4,$05,$0E
		.BYTE	$00,$C8,$4F,$27,$14,$14,$06,$39,$14,$53,$14,$14,$47,$57,$06,$15
		.BYTE	$00,$C8,$4E,$27,$2E,$77,$38,$14,$56,$54,$21,$14,$48,$58,$38,$15
		.BYTE	$00,$C8,$2F,$21,$04,$27,$14,$14,$14,$38,$14,$14,$14,$56,$14,$07
		.BYTE	$00,$C8,$27,$14,$04,$27,$0F,$14,$28,$14,$14,$14,$14,$14,$14,$0E
		.BYTE	$00,$C8,$3E,$14,$04,$27,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29
		.BYTE	$00,$C8,$3F,$27,$04,$27,$14,$14,$5A,$14,$28,$14,$56,$14,$14,$29
		.BYTE	$00,$C8,$2E,$27,$04,$27,$14,$14,$47,$57,$14,$14,$14,$28,$14,$07
		.BYTE	$00,$C8,$4E,$27,$54,$21,$38,$4D,$48,$58,$14,$14,$55,$14,$14,$0E
		.BYTE	$00,$2A,$20,$3B,$38,$14,$14,$54,$55,$14,$14,$14,$59,$57,$14,$15
		.BYTE	$00,$02,$C6,$16,$16,$16,$16,$16,$C6,$16,$16,$C6,$16,$16,$16,$3A
		.BYTE	$00,$03,$04,$C4,$C2,$04,$C3,$C5,$04,$04,$04,$C4,$C3,$04,$04,$C2
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l1_r13:
		.BYTE	$00,$00,$00,$00,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$16,$16,$16,$C6,$3A,$16,$16,$C6,$07,$16,$16,$C6,$16,$16,$07,$C6
		.BYTE	$C3,$C2,$04,$C5,$C3,$05,$C4,$04,$0E,$C5,$05,$04,$C3,$70,$0E,$04
		.BYTE	$14,$31,$0F,$38,$14,$06,$0C,$1C,$15,$14,$06,$38,$2F,$77,$15,$14
		.BYTE	$14,$32,$28,$14,$14,$14,$0D,$1D,$15,$28,$14,$14,$14,$14,$15,$14
		.BYTE	$BC,$14,$14,$BE,$16,$C6,$16,$16,$3A,$BC,$14,$14,$BE,$C6,$1E,$14
		.BYTE	$BD,$21,$14,$BF,$05,$C5,$C2,$05,$C3,$BD,$21,$14,$BF,$C2,$15,$14
		.BYTE	$14,$14,$14,$14,$06,$14,$14,$06,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$29,$14
		.BYTE	$16,$C6,$16,$BC,$14,$14,$BE,$07,$BC,$14,$14,$BE,$16,$16,$1E,$14
		.BYTE	$C4,$05,$C4,$BD,$21,$14,$BF,$0E,$BD,$21,$14,$BF,$C5,$C3,$15,$14
		.BYTE	$21,$06,$2F,$77,$14,$14,$14,$15,$14,$14,$28,$14,$14,$14,$15,$14
		.BYTE	$16,$16,$16,$16,$16,$16,$C6,$3A,$16,$16,$16,$16,$16,$16,$3A,$16
		.BYTE	$C4,$04,$C3,$04,$04,$C4,$04,$04,$04,$C5,$04,$04,$04,$C5,$04,$04
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l1_r23:
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14
		.BYTE	$16,$07,$C6,$09,$09,$09,$CC,$0A,$1A,$CE,$09,$09,$09,$09,$10,$07
		.BYTE	$70,$0E,$04,$17,$08,$18,$CD,$0B,$1B,$CF,$08,$18,$17,$18,$60,$0E
		.BYTE	$14,$15,$14,$18,$17,$18,$21,$14,$14,$14,$17,$08,$18,$17,$21,$15
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$28,$14,$14,$14,$14,$14,$14,$14,$15
		.BYTE	$C6,$1E,$14,$61,$75,$64,$75,$73,$61,$71,$64,$75,$73,$14,$14,$B9
		.BYTE	$C2,$15,$14,$62,$72,$65,$72,$74,$62,$72,$65,$72,$74,$27,$14,$B8
		.BYTE	$14,$29,$14,$63,$63,$63,$63,$63,$63,$63,$63,$63,$63,$67,$14,$14
		.BYTE	$14,$29,$14,$14,$38,$0F,$38,$14,$14,$14,$28,$14,$14,$14,$14,$14
		.BYTE	$16,$1E,$14,$40,$14,$28,$14,$14,$14,$14,$14,$38,$43,$14,$14,$1E
		.BYTE	$C3,$15,$14,$41,$50,$14,$14,$14,$14,$38,$14,$14,$44,$77,$14,$15
		.BYTE	$14,$15,$14,$42,$52,$14,$39,$14,$14,$14,$14,$14,$45,$21,$14,$15
		.BYTE	$16,$3A,$16,$C6,$16,$16,$BC,$0A,$1A,$BE,$16,$16,$C6,$16,$16,$3A
		.BYTE	$C5,$04,$04,$C5,$04,$C2,$BD,$0B,$1B,$BF,$04,$C5,$04,$C3,$04,$C5
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l1_r33:
		.BYTE	$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$59,$57,$15,$14
		.BYTE	$16,$16,$16,$16,$C6,$16,$16,$07,$C6,$16,$16,$3A,$16,$C6,$1E,$14
		.BYTE	$04,$C4,$C3,$C2,$C5,$04,$C4,$0E,$04,$04,$C3,$C4,$04,$04,$15,$14
		.BYTE	$14,$14,$14,$14,$38,$14,$14,$15,$14,$14,$14,$14,$14,$14,$15,$14
		.BYTE	$14,$14,$01,$BC,$14,$14,$14,$B9,$14,$BE,$C6,$11,$14,$14,$15,$28
		.BYTE	$14,$14,$0E,$BD,$21,$14,$31,$B8,$14,$BF,$C2,$15,$14,$14,$15,$14
		.BYTE	$14,$14,$15,$14,$14,$14,$32,$14,$14,$14,$14,$15,$14,$14,$15,$14
		.BYTE	$14,$14,$15,$14,$14,$38,$14,$14,$14,$39,$14,$15,$14,$14,$15,$14
		.BYTE	$14,$14,$15,$14,$14,$14,$14,$28,$14,$14,$14,$15,$14,$28,$07,$C6
		.BYTE	$14,$14,$15,$14,$0C,$1C,$77,$14,$0C,$1C,$77,$15,$14,$14,$0E,$04
		.BYTE	$14,$14,$15,$14,$0D,$1D,$21,$14,$0D,$1D,$21,$15,$14,$14,$29,$14
		.BYTE	$14,$14,$15,$14,$38,$14,$14,$14,$14,$14,$14,$15,$14,$14,$29,$14
		.BYTE	$16,$C6,$3A,$C6,$16,$16,$16,$C6,$16,$16,$16,$3A,$16,$C6,$3A,$16
		.BYTE	$04,$C4,$04,$04,$C2,$04,$04,$C5,$C3,$04,$04,$C4,$04,$04,$C2,$C3
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l1_r34:
		.BYTE	$04,$15,$14,$14,$14,$14,$14,$14,$14,$28,$14,$14,$14,$28,$15,$00
		.BYTE	$14,$15,$14,$14,$28,$14,$14,$28,$0F,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$38,$14,$14,$28,$14,$56,$14,$15,$00
		.BYTE	$14,$15,$14,$38,$14,$38,$14,$14,$14,$14,$14,$31,$14,$14,$15,$00
		.BYTE	$14,$15,$28,$14,$14,$14,$14,$14,$14,$14,$14,$32,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$15,$14,$14,$38,$14,$14,$14,$14,$14,$14,$28,$14,$5A,$15,$00
		.BYTE	$14,$15,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$5B,$15,$00
		.BYTE	$28,$07,$C6,$16,$C6,$16,$16,$16,$16,$C6,$BC,$0A,$1A,$BE,$1E,$00
		.BYTE	$14,$0E,$04,$04,$C5,$C3,$04,$C2,$C3,$04,$BD,$0B,$1B,$BF,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$14,$29,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$14,$15,$00
		.BYTE	$C6,$3A,$16,$16,$C6,$16,$16,$16,$16,$16,$16,$16,$C6,$16,$12,$00
		.BYTE	$04,$C2,$C3,$04,$C3,$C4,$04,$04,$C5,$C3,$04,$04,$04,$C5,$13,$00
		.BYTE	$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_l1_r31:
		.BYTE	$00,$6E,$7B,$8A,$8A,$7B,$8A,$7B,$8A,$8A,$7B,$8A,$8A,$7B,$6E,$00
		.BYTE	$00,$6E,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$7B,$6E,$00
		.BYTE	$00,$B5,$6F,$6F,$6F,$6F,$6F,$0A,$1A,$6F,$6F,$6F,$6F,$6F,$6E,$00
		.BYTE	$00,$A4,$89,$86,$89,$86,$89,$0B,$1B,$89,$86,$89,$86,$89,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$C9,$B4,$B4,$CB,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6E,$B4,$B4,$B4,$B4,$CA,$8B,$8C,$B4,$B4,$B4,$B4,$B4,$6E,$00
		.BYTE	$00,$6C,$6F,$6F,$6F,$6F,$6F,$8B,$8C,$6F,$6F,$6F,$6F,$6F,$7C,$00
		.BYTE	$00,$C0,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$C1,$00
		.BYTE	$6F,$DE,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$DF,$6F
		.BYTE	$7A,$7A,$7A,$7A,$7A,$7A,$7A,$8B,$8C,$7A,$7A,$7A,$7A,$7A,$7A,$7A
		.BYTE	$B4,$B4,$B4,$B4,$B4,$B4,$B4,$8B,$8C,$CB,$C9,$B4,$B4,$B4,$B4,$B4
		.BYTE	$B4,$B4,$B4,$B4,$B4,$B4,$CB,$B4,$B4,$B4,$CA,$B4,$B4,$B4,$B4,$B4
		.BYTE	$6F,$6F,$6F,$6F,$6F,$6F,$6F,$0A,$1A,$6F,$6F,$6F,$6F,$6F,$6F,$6F
		.BYTE	$7A,$7A,$7A,$7A,$7A,$7A,$7A,$0B,$1B,$7A,$7A,$7A,$7A,$7A,$7A,$7A
		.BYTE	$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4,$B4

		SECTION_END	"LVL1 DATA"

		BANK_END 1,$C000
