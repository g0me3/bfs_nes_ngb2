
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
		STORE8			_chr_bank0,$0D
		SJSR			_ssub_common_room_loop
		NJSR			_nsub_patch_pal_load			; sometimes
			NARGB		$06								; we need to fix sprites palette as
			NARGW		_lvl1_full_palA+$18				; well as change sprites CHR bank
		STORE8			_chr_bank0,$04					; because there are other enemies may appear
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
		STORE8			_chr_bank0,$04
		STORE8			_chr_bank1,$02
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
		STORE8			_chr_bank0,$07
		STORE8			_chr_bank1,$03
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
; NOTE: fix exit position of the players to avoid possible getting stuck
; of the catcher, which put at the start over the non-penetrable block
; and if walk left, will stuck in it.
; WARNING! in this new position, beamer put on the rails and may be killed
; almost immediately lol
#if TWO_PLAYER_MODE==1
		.BYTE	$46,$46,$01
#else
		.BYTE	$45,$46,$01
#endif
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
		STORE8			_chr_bank1,$0B					; here we enter the train section
		SJSR			_ssub_common_room_loop			; currently only part of the tiles are changed
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
; tunnel/train level also has two different collision tables but since you couldn't
; return back there is no need to manually patch in transitions between rooms
;
_lvl2_room_initA:
		STORE8			_chr_bank1,$0A
		STORE16			_lvl_collisions_ptr,_lvl2_collisionsA
		SJMPS			_lvl2_common_init

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl2_room_initB:
		STORE8			_chr_bank1,$0B
		STORE16			_lvl_collisions_ptr,_lvl2_collisionsB

; !FALLTHROUGH!

; =============== S C R I P T  S U B R O U T I N E =====s====================
_lvl2_common_init:
		STORE8			_chr_bank0,$0C
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
		STORE8			_chr_bank0,$0F					; here is the special room with
		NJSR			_nsub_patch_pal_load			; mid-boss, as well as special
			NARGB		$07								; music and palettes for it
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
		STORE8			_chr_bank0,$0E					; restore regular level CHR bank
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
		STORE8			_chr_bank0,$0E
		STORE8			_chr_bank1,$10
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
		STORE8			_chr_bank0,$12
		STORE8			_chr_bank1,$11
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
		STORE8			_chr_bank0,$0E
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
		STORE8			_chr_bank0,$0D
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
		STORE8			_chr_bank0,$0E
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
		STORE8			_chr_bank0,$0E
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
		STORE8			_chr_bank0,$12
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
		STORE8			_chr_bank0,$12
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
		STORE8			_chr_bank0,$07
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
		STORE8			_chr_bank0,$0F
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
		STORE8			_chr_bank0,$04
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
		STORE8			_chr_bank0,$0E
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
		STORE8			_chr_bank0,$0E
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
		STORE8			_chr_bank0,$04
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
		STORE8			_chr_bank0,$0E
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
		STORE8			_chr_bank0,$0C
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
		STORE8			_chr_bank0,$18
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
		STORE8			_chr_bank0,$0E
		STORE8			_chr_bank1,$15
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
		STORE8			_chr_bank0,$17
		STORE8			_chr_bank1,$16
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
		STA		_chr_bank1					; restore room background CHR bank
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

#if TWO_PLAYER_MODE==1
		JSR		_player_spr_insert
		LDX		#$50
		LDY		#$B8
		LDA		_catcher_spr_base_tmp
#endif

; !FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_player_spr_insert:
		STX		_tmp1
		STY		_tmp2
		AND		#$F0						; animate it based on frames counter
		LSR
		LSR
		STA		_tmp0
		JSR		_spr_y_pos_adjust
		LDA		_nmi_counter
		AND		#$0C
		LSR
		LSR
		ADC		_tmp0
		TAY
		LDA		_spr_pause_list,Y
		ASL									; NEW, WARNING, may oveflow if idx are
		TAY									; higher than 80!
		LDA		_spr_libA03,Y				; WARNING! library is in system bank now,
		STA		_ptr1E						; so no need to far call it here, change
		LDA		_spr_libA03+1,Y				; if you decide to move sprites to other
		STA		_ptr1E+1					; banks!
		JMP		_spr_lib_fetch_ex

; NEW, WARNING! there are a lot shared sprites here between various
; libraries. to make sure you using the correct index for particular
; library, we need to replace all duplicated offsets with unique ones
; pointing to the same place anyway.
;
_spr_pause_list:
		.BYTE	$0A	; _sprA03_0A_idx
		.BYTE	$09	; _sprA03_09_idx
		.BYTE	$0A	; _sprA03_0A_idx
		.BYTE	$0B	; _sprA03_0B_idx
		.BYTE	$1A	; _sprA03_1A_idx
		.BYTE	$19	; _sprA03_19_idx
		.BYTE	$1A	; _sprA03_1A_idx
		.BYTE	$1B	; _sprA03_1B_idx
		.BYTE	$2A	; _sprA03_2A_idx
		.BYTE	$29	; _sprA03_29_idx
		.BYTE	$2A	; _sprA03_2A_idx
		.BYTE	$2B	; _sprA03_2B_idx
		.BYTE	$3A	; _sprA03_3A_idx
		.BYTE	$39	; _sprA03_39_idx
		.BYTE	$3A	; _sprA03_3A_idx
		.BYTE	$3B	; _sprA03_3B_idx
		.BYTE	$4A	; _sprA03_4A_idx
		.BYTE	$49	; _sprA03_49_idx
		.BYTE	$4A	; _sprA03_4A_idx
		.BYTE	$4B	; _sprA03_4B_idx

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
		STORE8			_chr_bank0,$05					; also change sprites CHR bank
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
		STORE8			_chr_bank0,$04					; tiles changes and goes to second CHR page
		STORE8			_chr_bank1,$05					; because bg tiles of font are there as well
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
		JSR		_print_num99999
#if TWO_PLAYER_MODE==1
		LDA		#$0D
		LDX		#$01
		JSR		_nsub_players_lives_draw
#endif
		LDA		#$15
		LDX		#$00

; FALLTHROUGH!

; =============== S U B R O U T I N E ======n================================
_nsub_players_lives_draw:
		PHA
		LDA		_players_lives,X			; convert binary lives to decimal
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
		PLA
		TAX
		LDY		#$16
		JSR		_ppu_offset_calc			; helper routine to calc ppu position
		LDX		#$01
		STX		_tmp_buf+3
		INX
		STX		_tmp_buf+2
		JSR		_ppu_res_send_param_no_ofs	; send lives buffer data first
		.WORD	_tmp_buf+2
		RTS

; NOTE: same as for stage complete script, must be in the same bank as
; the main stage scripts.
;
; =============== S C R I P T ==========================s====================
_scr_game_over:
		SJSR			_ssub_room_exit_pal_fade_out	; usual stuff here
		NJSR			_nsub_all_threads_off_except_cur; disable threads,
		NJSR			_nsub_far_prg0_tlm_lib_unpack	; draw picture
			NARGB		_tlm3_game_over_idx
		STORE8			_chr_bank1,$05					; setup CHR banks
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

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr1A_lvl1_boss_judges
		NJSR			_nsub_obj_sarg_add_imm_test		; two instances of the object existed
			NARGB		SARG0,$FF
		SJMP_SW			$01
		SCASE			_scr_judges_tall

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SPR_IDX_SET		0,$04							; default instance set the "hat" sprite
		NJSR			_nsub_obj_sarg_add_imm_test		; this is an additional branch for using
			NARGB		SARG2,$FF						; this object on LVL5
		SJMP_SW			$01								; only for LVL1 _sloc_2C014 is executed
		SCASE			_scr_judges_intro				; for the rest this branch is skipped

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
_sloc_2C014:
		SDELAY			$01								; special branch for LVL1, wait for
		NJSR			_nsub_mcmp						; scroll of the room reach particular
			NARGW		_ppu_scroll_pos_y				; value
			NARGB		$00
		SBCCS			_sloc_2C014
		STORE8			_cur_room_x_pageB,$00			; force pageB
		NJSR			_nsub_gen_threads_off_except_cur; remove all other object (chairs maybe)
		SJSR			_ssub_boss_music_fade_and_load	; fade out music and start boss theme

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_intro:
		SPR_IDX_SET		4,$04							; finally, start to anim "hat" on the table
		SPR_IDX_INC		4								; (actually i DONT KNOW what is it and how
		SPR_IDX_DEC		4								; they called it)
		SPR_IDX_SET		4,$06
		SPR_IDX_SET		0,$04
		SDELAY			$14
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SPR_IDX_SET		4,$06
		SPR_IDX_SET		4,$04
		SPR_IDX_SET		1,$07
		SPR_IDX_INC		5
		SPR_IDX_DEC		4
		SPR_IDX_SET		0,$FF							; hat disappears, this object turns to fat
		NJSR			_nsub_new_thread_start			; judge, the other instance loaded for
			NARGB		_scr1A_lvl1_boss_judges_idx		; tall judge
			NARGB		$38,$40
			NARGB		_scr_judges_tall_idx+1
			NARGB		$00
		POS_X_MOVE		0,$C0							; position of the fat judge x-64, y+64 of the
		POS_Y_MOVE		0,$40							; main object position
		NJSR			_nsub_patch_pal_load			; NOTE: this is a default value for LVL1 palette
			NARGB		$06								; for this object, this is already there, so not
			NARGW		_pal_judges_default_patch		; sure why this palette aplied here...
		SARG_SET		SARG1,$80						; face down

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sct_judges_fat_restart:
		NBG_HNDL_SET	_nbgsub_fat_judge_ctest			; init bg native collision test
		NJSR			_nsub_patch_pal_load			; NOTE: to previous, this is actual palette for
			NARGB		$06								; this enemy
			NARGW		_pal_judges_active_patch
		NJSR			_nsub_spr_dir_select			; set sprite
			NARGB		$09,$40
		SLOOP_BEGIN		$06								; at the beginning stand still animation
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 6,$FC
		SLOOP_END
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; now targeting on beamer

; FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sct_judges_fat_active:
		NBG_HNDL_SET	_nbgsub_fat_judge_ctest			; not sure why they set the same handler here twice
_sloc_2C06F:
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; set destination
		NJSR			_nsub_spr_dir_select
			NARGB		$09,$40							; refresh sprite idx
		SLOOP_BEGIN		$02
		SDELAY			$06								; start to move animated
		SPR_IDX_ADD_IMM 6,$04
		SPR_IDX_ADD_IMM 0,$FC
		SLOOP_END
		NJSR			_nsub_obj_to_beamer_slow_turn	; adjust targeting to beamer
			NARGB		$10
		SJMPS			_sloc_2C06F						; repeat

; =============== S C R I P T ==========================s====================
_sct_judges_fat_stun:
		NBG_HNDL_SET	_nbgsub_judges_fat_catch_test
		SLOOP_BEGIN		$3C
		SJSRS			_ssub_judges_fat_shake_anim
		NJSR			_nsub_wait_for_beam_hold		; unless most of regular enemies
		SBCS_BREAK		_sct_judges_fat_restart			; when beam released, this boss start
		SLOOP_END										; to be active immediately.
		SARG_SET		SARG0,$02						; after 1 sec boss turns red,
		NJSR			_nsub_patch_pal_load			; also catch flag is raized, may
			NARGB		$06								; be catched now as usual
			NARGW		_pal_judges_red_patch
_sloc_2C0A1:
		SJSRS			_ssub_judges_fat_shake_anim		; the rest is the same as regular
		NJSR			_nsub_wait_for_beam_hold		; enemy stun handler
		SBCCS			_sloc_2C0A1
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_sct_judges_fat_restart
		SCASE			_scr_judges_fat_catch_anim_L
		SCASE			_scr_judges_fat_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_judges_fat_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$09,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_judges_fat_catch_anim_L:
		SARG_SET		SARG1,$15
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_judges_fat_catch_anim_R:
		SARG_SET		SARG1,$17
		SJMP			_ssub_common_catch_anim_R_snd19

_pal_judges_default_patch:
		.BYTE	$0F,$31,$25,$0F
_pal_judges_active_patch:
		.BYTE	$0F,$36,$22,$0F
_pal_judges_red_patch:
		.BYTE	$0F,$25,$15,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_fat_judge_ctest:
		LDY		#$00
		LDX		_cur_trd_slot				; there is no room obstacles test,
		LDA		_obj_x_pos_lo,X				; just limit the min-max X range for
		CMP		#$10						; movement
		BCS		loc_2C0E5
		LDA		#$10
		BNE		loc_2C0EB
loc_2C0E5:
		CMP		#$F0
		BCC		loc_2C0F5
		LDA		#$EF
loc_2C0EB:
		STA		_obj_x_pos_lo,X				; when edges reached, bounce in opposite
		INY									; direction on the same vector
		LDA		#$00
		SEC
		SBC		_trds_args1,X
		STA		_trds_args1,X
loc_2C0F5:
		LDA		_obj_y_pos_lo,X				; the same for Y
		CMP		#$10
		BCS		loc_2C0FF
		LDA		#$10
		BNE		loc_2C105
loc_2C0FF:
		CMP		#$E0
		BCC		loc_2C10F
		LDA		#$DF
loc_2C105:
		STA		_obj_y_pos_lo,X
		INY
		LDA		#$80
		SEC
		SBC		_trds_args1,X
		STA		_trds_args1,X
loc_2C10F:
		TYA
		BEQ		loc_2C118					; if direction is changed need to recalc sprites
		JSR		_cur_thread_reload_param	; so reload current current script from beginning
		.WORD	_sct_judges_fat_active
		RTS
loc_2C118:
		LDX		#$0C
		LDY		#$0E
		JSR		_obj_to_beam_ctest
		BCC		loc_2C127
		JSR		_cur_thread_reload_param
		.WORD	_sct_judges_fat_stun
		RTS
loc_2C127:
		LDX		#$0F
		LDY		#$12
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_judges_fat_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2C147
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_2C142
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_fat_catch_anim_L
		RTS
loc_2C142:
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_fat_catch_anim_R
locret_2C147:
		RTS

; =============== S C R I P T ==========================s====================
_scr_judges_tall:
		NBG_HNDL_SET	_nbgsub_judges_tall_ctest		; regular init, set regular
		NJSR			_nsub_patch_pal_load			; palette immediately without any
			NARGB		$07								; redundant calls this time
			NARGW		_pal_judges_active_patch
		SARG_SET		SARG0,$00
		SARG_SET		SARG1,$80
		SSCRIPT1_SET	_scr_judges_tall_spr_anim		; automatic boss, set constant anim
		SDELAY			$48
		SJMPS			_scr_judges_tall_activeA

; =============== S C R I P T ==========================s====================
_scr_judges_tall_restart_posA:
		NJSR			_nsub_judges_tall_pos_set		; one of three restart points for tall boss
			NARGB		$B8,$80							; right side of the screen, the same as for
		SARG_SET		SARG1,$80						; appearance point
		SJSR			_ssub_judges_tall_reappear

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_tall_activeA:
		SLOOP_BEGIN		$10								; do half large cirle right till the
		SARG_ALU		SARG1,_ADC,$08					; left side of the screen
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02
		SDELAY			$07
		SLOOP_END
		SJMPS			_scr_judges_tall_activeB

; =============== S C R I P T ==========================s====================
_scr_judges_tall_restart_posB:						; second reappearance point
		NJSR			_nsub_judges_tall_pos_set		; left side of the screen
			NARGB		$2A,$72
		SARG_SET		SARG1,$00
		SJSR			_ssub_judges_tall_reappear

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_tall_activeB:
		SLOOP_BEGIN		$10								; here start a small half circle to the
		SARG_ALU		SARG1,_ADC,$08					; middle, the same start for second reappearance
		NJSR			_nsub_speed_dir_select			; point
			NARGB		$00,$02
		SDELAY			$04
		SLOOP_END
		SJMPS			_scr_judges_tall_activeC

; =============== S C R I P T ==========================s====================
_scr_judges_tall_restart_posC:
		NJSR			_nsub_judges_tall_pos_set		; finally middle of the screen reappearance point
			NARGB		$7B,$7A
		SARG_SET		SARG1,$00
		SJSRS			_ssub_judges_tall_reappear

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_judges_tall_activeC:
		SLOOP_BEGIN		$20								; here is the main loop, two full circles
		SARG_ALU		SARG1,_ADC,$F8					; with start in the middle point, also
		NJSR			_nsub_speed_dir_select			; third reappearance point
			NARGB		$00,$02
		SDELAY			$05
		SLOOP_END
		SLOOP_BEGIN		$20
		SARG_ALU		SARG1,_ADC,$08
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02
		SDELAY			$05
		SLOOP_END
		SJMPS			_scr_judges_tall_activeC

; =============== S C R I P T ==========================s====================
_scr_judges_tall_spr_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$19,$40
		SDELAY			$06
		SPR_IDX_ADD_IMM 6,$04
		SJMPS			_scr_judges_tall_spr_anim

; =============== S C R I P T ==========================s====================
_scr_judges_tall_stun:
		NBG_HNDL_SET	_nbgsub_judges_tall_catch_test	; same as for other boss object
		SLOOP_BEGIN		$3C
		SJSRS			_scr_judges_tall_shake_anim		; beam for a second, then set
		NJSR			_nsub_wait_for_beam_hold		; catch active flag, turn sprite red
		SBCS_BREAK		_sloc_2C1EF						; and continue with regular stun handler
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_judges_red_patch
_sloc_2C1E6:
		SJSRS			_scr_judges_tall_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_2C1E6
_sloc_2C1EF:
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_judges_tall_disappear
		SCASE			_scr_judges_tall_catch_anim_L
		SCASE			_scr_judges_tall_catch_anim_R

; =============== S C R I P T  S U B R O U T I N E =====s====================
_scr_judges_tall_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$19,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_judges_tall_disappear:
		SLOOP_BEGIN		$1E								; start to blinking
		NJSR			_nsub_spr_dir_select			; in current sprite state
			NARGB		$19,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SDELAY			$3C								; delay, reload active pal patch
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_judges_active_patch
		SSCRIPT1_SET	_scr_judges_tall_spr_anim		; restart regular animation
		NJSR			_nsub_get_rand_probability		; get random unmber in range 0-2
			NARGB		$03
		SJMP_SW			$03
		SCASE			_scr_judges_tall_restart_posA	; restarting boss from a particular
		SCASE			_scr_judges_tall_restart_posB	; location on its movement trajectory
		SCASE			_scr_judges_tall_restart_posC	; to keep it move on the same area

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_judges_tall_reappear:
		SLOOP_BEGIN		$1E								; blink while reappearing
		SPR_IDX_SET		1,$1B
		SPR_IDX_SET		1,$FF
		SLOOP_END
		NBG_HNDL_SET	_nbgsub_judges_tall_ctest
		SRET

; =============== S C R I P T ==========================s====================
_scr_judges_tall_catch_anim_L:
		SARG_SET		SARG1,$25
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_judges_tall_catch_anim_R:
		SARG_SET		SARG1,$27
		SJMP			_ssub_common_catch_anim_R_snd19

; =============== S U B R O U T I N E ======n================================
_nbgsub_judges_tall_ctest:
		LDX		#$08
		LDY		#$0E
		JSR		_obj_to_beam_ctest
		BCC		loc_2C24E
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_tall_stun
		RTS
loc_2C24E:
		LDX		#$0B
		LDY		#$12
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_judges_tall_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2C26E
		LSR
		LDA		#$0A
		STA		_scores_obj_value
		BCS		loc_2C269
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_tall_catch_anim_L
		RTS
loc_2C269:
		JSR		_cur_thread_reload_param
		.WORD	_scr_judges_tall_catch_anim_R
locret_2C26E:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_judges_tall_pos_set:
		LDX		_cur_trd_slot				; read hardcoded positions from script
		JSR		_scr_getc
		STA		_obj_x_pos_lo,X
		JSR		_scr_getc
		STA		_obj_y_pos_lo,X
		RTS

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr22_lvl2_boss_train_slime
		NJSR			_nsub_obj_sarg_add_imm_test		; boss slime looking simple, but
			NARGB		SARG0,$FF						; uses 4 different entities
		SJMP_SW			$04
		SCASE			_scr_train_slime_projectileA
		SCASE			_scr_train_slime_projectileB
		SCASE			_scr_train_slime_projectileC
		SCASE			_scr_train_slime_dead

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
_scr_train_slime_active:
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_train_slime_patch
		NBG_HNDL_SET	_nbgsub_train_slime_ctest
		SJSRS			_ssub_train_slime_idle_anim		; idle anim
		SLOOP_BEGIN		$02
		SJSRS			_ssub_train_slime_shot_anim		; two shots in row
		SLOOP_END
		SJSRS			_ssub_train_slime_idle_anim		; idle
		SJSRS			_ssub_train_slime_shot_anim		; one shot
		SJSRS			_ssub_train_slime_idle_anim		; idle
		SLOOP_BEGIN		$03
		SJSRS			_ssub_train_slime_shot_anim		; three shots in row
		SLOOP_END
		SJMPS			_scr_train_slime_active

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_slime_idle_anim:
		SLOOP_BEGIN		$03
		SPR_IDX_SET		0,$29
		SDELAY			$0C
		SPR_IDX_INC		6
		SPR_IDX_INC		6
		SLOOP_END
		SRET

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_slime_shot_anim:
		SPR_IDX_SET		7,$2C							; turn to the player
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		SPR_IDX_INC		3
		NJSR			_nsub_new_thread_start			; deploy projectile
			NARGB		_scr22_lvl2_boss_train_slime_idx
			NARGB		$00,$F8
			NARGB		_scr_train_slime_projectileA_idx+1
			NARGB		$00
		SPR_IDX_INC		7								; turn back
		SPR_IDX_DEC		3
		SPR_IDX_DEC		3
		SPR_IDX_DEC		3
		SRET

; =============== S C R I P T ==========================s====================
_scr_train_slime_stun:
		NBG_HNDL_SET	_nbgsub_train_slime_catch_test
		SARG_SET		SARG0,$02
		SSCRIPT1_SET	_scr_train_slime_dodge_anim		; slime dodges the beam
_sloc_2C6A2:
		SDELAY			$01								; it is possible to catch only
		NJSR			_nsub_wait_for_beam_hold		; while dodge script starts
		SBCCS			_sloc_2C6A2						; when secondary script finishes
		SSCRIPT1_OFF									; all reloaded to active state
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_train_slime_active
		SCASE			_scr_train_slime_catch_anim_L
		SCASE			_scr_train_slime_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_train_slime_dodge_anim:
		SLOOP_BEGIN		$01								; dodge anim play
		SPR_IDX_SET		1,$29
		SPR_IDX_SET		1,$31
		SLOOP_END
		SPR_IDX_SET		1,$2C
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		SPR_IDX_DEC		1
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SPR_IDX_INC		1
		NJSR			_nsub_thread_off				; custom native thread off
			NARGB		$03								; disables beam completely
		NJSR			_nsub_obj_to_beam_release_test	; then reset corresponding flags.
		SSCRIPT0_OFF									; shut down

; =============== S C R I P T ==========================s====================
_scr_train_slime_catch_anim_L:
		SJSRS			_ssub_train_slime_catch_extra
		SARG_SET		SARG1,$32
		SJMP			_ssub_common_catch_anim_L_snd02

; =============== S C R I P T ==========================s====================
_scr_train_slime_catch_anim_R:
		SJSRS			_ssub_train_slime_catch_extra
		SARG_SET		SARG1,$34
		SJMP			_ssub_common_catch_anim_R_snd02

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_train_slime_catch_extra:
		NJSR			_nsub_new_thread_start			; additional custom init
			NARGB		_scr22_lvl2_boss_train_slime_idx; for dead lvl2 boss
			NARGB		$00,$00							; start a new actor script here
			NARGB		_scr_train_slime_dead_idx+1
			NARGB		$00
		NJSR			_nsub_apu_mus_load				; and do scream sound
			NARGB		$FF
		NJSR			_nsub_apu_snd_load
			NARGB		_snd19_idx
		SRET

_pal_train_slime_patch:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_slime_ctest:
		LDX		#$08
		LDY		#$08
		JSR		_obj_to_beam_ctest
		BCC		loc_2C706
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_slime_stun
		RTS
loc_2C706:
		LDX		#$0D
		LDY		#$0E
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_slime_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2C72B
		PHA
		JSR		_nsub_gen_threads_off_except_cur
		LDA		#$19
		STA		_scores_obj_value
		PLA
		LSR
		BCS		loc_2C726
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_slime_catch_anim_L
		RTS
loc_2C726:
		JSR		_cur_thread_reload_param
		.WORD	_scr_train_slime_catch_anim_R
locret_2C72B:
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_slime_dead:
		NJSR			_nsub_players_scr_suspend		; when boss dead, there is another
		SDELAY			$5A								; scenery, first players are auto controlled
		NJSR			_nsub_lvl_native_handler_disable; custom routine to disable all bg work of level
		NJSR			_nsub_patch_pal_load
			NARGB		$02
			NARGW		_pal_train_slime_dead_patch
		SDELAY			$50
		NJSR			_nsub_apu_snd_load				; train whistle
			NARGB		_snd13_idx
		SDELAY			$3C
		SLOOP_BEGIN		$3C
		STORE8			_obj_y_pos_hi+2,$05				; now do the scroll trick, set
		STORE8			_obj_y_pos_hi+4,$05				; level scroll to room 0 then 1,
		SCRL_Y_SET		0,$00,$05						; do not forget to adjust player's scrolls
		POS_Y_SET		1,$00,$05						; as well... looks like train
		STORE8			_obj_y_pos_hi+2,$06				; disappears.
		STORE8			_obj_y_pos_hi+4,$06
		SCRL_Y_SET		0,$00,$06
		POS_Y_SET		1,$00,$06
		SLOOP_END
		NJSR			_nsub_stage_complete_force		; now stage is complete.
		SSTOP

_pal_train_slime_dead_patch:
		.BYTE	$0F,$0F,$0F,$07

; =============== S U B R O U T I N E ======n================================
_nsub_lvl_native_handler_disable:
;		LDA		#$00						; REDUNDANT, never used by other code
;		ASL									; with other arguments,
;		TAX									; and $00 here is HARDCODED!
;		LDA		#<[_nbgsub_dummy]
;		STA		_trds_nbgsub_ptr,X
;		LDA		#>[_nbgsub_dummy]
;		STA		_trds_nbgsub_ptr+1,X
		LDA		#<[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr
		LDA		#>[_nbgsub_dummy]
		STA		_trds_nbgsub_ptr+1
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectileA:
		NJSR			_nsub_train_slime_projectile_dir_select
		NJSR			_nsub_new_thread_start			; set random direction up
			NARGB		_scr22_lvl2_boss_train_slime_idx; then deploy two more projectiles
			NARGB		$F8,$00							; to the left and to the right
			NARGB		_scr_train_slime_projectileB_idx+1
			NARGB		$E0
		NJSR			_nsub_new_thread_start
			NARGB		_scr22_lvl2_boss_train_slime_idx
			NARGB		$08,$00
			NARGB		_scr_train_slime_projectileC_idx+1
			NARGB		$20
		SPR_IDX_SET		0,$37

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectile_common:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_train_slime_projectile_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$02							; small projectile in the beginning
		SDELAY			$18								; then getting bigger and finally disappear
		SLOOP_BEGIN		$03
		SPR_IDX_SET		1,$39
		SPR_IDX_SET		1,$FF
		SPR_IDX_SET		1,$3A
		SPR_IDX_SET		1,$FF
		SLOOP_END
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_train_slime_projectile_ctest:
		LDX		#$06
		LDY		#$07
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_train_slime_projectile_dir_select:
		LDA		#$21
		JSR		_rand
		CLC
		ADC		#$F0
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectileB:
		SPR_IDX_SET		0,$36
		SJMPS			_scr_train_slime_projectile_common

; =============== S C R I P T ==========================s====================
_scr_train_slime_projectileC:
		SPR_IDX_SET		0,$38
		SJMPS			_scr_train_slime_projectile_common

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr2E_lvl4_boss_dragons
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$02
		SCASE			_scr_dragons_active
		SCASE			_scr_dragons_flame

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SJSR			_ssub_boss_music_fade_and_load	; boss init here, music, palette
		NJSR			_nsub_patch_pal_load			; and CHR bank
			NARGB		$07
			NARGW		_pal_dragons_patchA
		STORE8			_chr_bank0,$13
		SLOOP_BEGIN		$08								; now will deploy 8 objects
_sloc_2C99C:
		SDELAY			$01
		NJSR			_nsub_dragons_obj_num_test		; if objects count more than 3, then wait
			NARGB		$04								; when you catch some
		SBCSS			_sloc_2C99C
		NJSR			_nsub_new_thread_start			; or else deploy new clone
			NARGB		_scr2E_lvl4_boss_dragons_idx
			NARGB		$00,$00
			NARGB		_scr_dragons_active_idx+1
			NARGB		$00
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_dragons_active:
		NJSR			_nsub_dragons_start_pos_select	; set the appearance position and
		SLOOP_BEGIN		$10								; direction,
		SPR_IDX_SET		1,$3B							; then blink under water phase sprite
		SPR_IDX_SET		1,$FF
		SLOOP_END

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_dragons_restart:
		SARG_SET		SARG0,$00
_sloc_2C9BB:
		SPR_IDX_SET		0,$3B							; retarget at the beginning of the ai loop
		NJSR			_nsub_dragons_direction_update	; by random
		NJSR			_nsub_dragons_obstacle_test		; test if any obstacles in given direction
		SBCCS			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$40
		NJSR			_nsub_dragons_obstacle_test		; test all directions before start moving
		SBCCS			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$80
		NJSR			_nsub_dragons_obstacle_test
		SBCCS			_sloc_2C9E4
		SARG_ALU		SARG1,_ADC,$C0
		NJSR			_nsub_dragons_obstacle_test
		SBCSS			_sloc_2C9BB
_sloc_2C9E4:
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$01							; now set speed
		SDELAY			$10								; and move
		POS_MOVE_STOP	0
		NJSR			_nsub_obj_to_obj_in_range_test	; check for the beamer around
			NARGB		$02,$40
		SBCCS			_sloc_2C9BB						; if no one, continue swimming
		NJSR			_nsub_obj_to_beamer_fast_right_turn
		NJSR			_nsub_apu_snd_load				; or else, target on it,
			NARGB		_snd14_idx						; play popping up sound
		NJSR			_nsub_spr_dir_select			; show up the dragon itself
			NARGB		$3C,$40
		SDELAY			$07
		SPR_IDX_ADD_IMM 7,$04							; now start active phase, also
		NBG_HNDL_SET	_nbgsub_dragons_ctest			; catchable
		SPR_IDX_ADD_IMM 4,$04							; animate popping up
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$18
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 0,$FC
		NJSR			_nsub_apu_snd_load				; play fire sound
			NARGB		_snd15_idx
		SLOOP_BEGIN		$20
		NJSR			_nsub_new_thread_start			; deploy fire projectile
			NARGB		_scr2E_lvl4_boss_dragons_idx
			NARGB		$00,$00
			NARGB		_scr_dragons_flame_idx+1
			NARGB		$00
		SDELAY			$03								; hide back
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$07
		SPR_IDX_ADD_IMM 5,$FC
		SPR_IDX_ADD_IMM 0,$04
		SDELAY			$0C
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		SPR_IDX_ADD_IMM 7,$FC
		NBG_HNDL_RESET									; disable collision test handler, loop
		SJMPS			_sloc_2C9BB

; =============== S C R I P T ==========================s====================
_scr_dragons_stun:
		NBG_HNDL_SET	_nbgsub_dragons_catch_test		; dragons are gone if beamed for 90 cycles
		SLOOP_BEGIN		$5A								; two frame each = 3 seconds
		SJSRS			_ssub_dragons_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCS_BREAK		_sloc_2CA7E						; wait if beam released and break
		SLOOP_END
		NJSR			_nsub_is_any_enemy_active		; test if this is a last object on the level
		SBCSS			_sloc_2CA66
		NJSR			_nsub_apu_snd_load				; if no, play disappear sound
			NARGB		_snd22_idx
		SLOOP_BEGIN		$10
		NJSR			_nsub_spr_dir_select			; and do disappear animation
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_SET		1,$FF							; remove object and stop thread then
		SLOOP_END
		SSTOP
_sloc_2CA66:
		SARG_SET		SARG0,$02						; when last one, turn it read
		NJSR			_nsub_patch_pal_load			; and wait for catch as usual
			NARGB		$07
			NARGW		_pal_dragons_patchB
_sloc_2CA6F:
		SJSRS			_ssub_dragons_shake_anim
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_2CA6F
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_dragons_patchA
_sloc_2CA7E:
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_dragons_retire
		SCASE			_scr_dragons_catch_anim_L
		SCASE			_scr_dragons_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_dragons_retire:
		NBG_HNDL_RESET
		SPR_IDX_ADD_IMM 6,$F4
		SPR_IDX_ADD_IMM 6,$FC
		SJMP			_scr_dragons_restart

; =============== S C R I P T  S U B R O U T I N E =====s====================
_ssub_dragons_shake_anim:
		NJSR			_nsub_spr_dir_select
			NARGB		$44,$40
		SDELAY			$01
		SPR_IDX_ADD_IMM 1,$08
		SRET

; =============== S C R I P T ==========================s====================
_scr_dragons_catch_anim_L:
		SARG_SET		SARG1,$50
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_dragons_catch_anim_R:
		SARG_SET		SARG1,$52
		SJMP			_ssub_common_catch_anim_R_snd19

_pal_dragons_patchA:
		.BYTE	$0F,$25,$16,$0F
_pal_dragons_patchB:
		.BYTE	$0F,$36,$2B,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragons_ctest:
		LDX		#$10
		LDY		#$10
		JSR		_obj_to_beam_ctest
		BCC		loc_2CABE
		JSR		_cur_thread_reload_param
		.WORD	_scr_dragons_stun
		RTS
loc_2CABE:
		LDX		#$15
		LDY		#$16
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragons_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2CADE
		LSR
		LDA		#$1E
		STA		_scores_obj_value
		BCS		loc_2CAD9
		JSR		_cur_thread_reload_param
		.WORD	_scr_dragons_catch_anim_L
		RTS
loc_2CAD9:
		JSR		_cur_thread_reload_param
		.WORD	_scr_dragons_catch_anim_R
locret_2CADE:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_obj_num_test:
		JSR		_scr_getc
		STA		_tmp0
		LDY		#$00
		LDX		#$06
loc_2CAE8:
		LDA		_trds_obj_idx,X
		BMI		loc_2CAEE
		INY
loc_2CAEE:
		INX
		CPX		#$0D
		BCC		loc_2CAE8
		CPY		_tmp0
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_obstacle_test:
		LDY		_cur_trd_slot				; since there are no actual obstacles
		LDA		_trds_args1,Y				; this test only preventing the
		ASL									; objects to get close to the screen
		ROL									; edges
		ROL
		TAX
		LDA		_obj_x_pos_lo,Y
		CMP		byte_2CB13,X
		BEQ		loc_2CB11
		LDA		_obj_y_pos_lo,Y
		CMP		byte_2CB17,X
		BEQ		loc_2CB11
		CLC
		RTS
loc_2CB11:
		SEC
		RTS

byte_2CB13:
		.BYTE	$FF,$D0,$FF,$30
byte_2CB17:
		.BYTE	$30,$FF,$A0,$FF

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_start_pos_select:
		LDA		#$0B						; select two random numbers
		JSR		_rand						; $03-$0E and
		PHA									; $03-$0A
		LDA		#$08
		JSR		_rand
		CLC
		ADC		#$03						; this selecting one of the floor
		ASL									; cells
		ASL
		ASL
		ASL
		LDX		_cur_trd_slot
		STA		_obj_y_pos_lo,X
		LDA		#$00
		STA		_obj_y_pos_hi,X
		PLA
		CLC
		ADC		#$03
		ASL
		ASL
		ASL
		ASL
		STA		_obj_x_pos_lo,X				; set current location of the object
		LDA		#$03
		STA		_obj_x_pos_hi,X
		LDA		#$00
		JSR		_rand
		AND		#$C0
		STA		_trds_args1,X				; then select movement direction
		RTS									; also randomly

; =============== S U B R O U T I N E ======n================================
_nsub_dragons_direction_update:
		LDA		#$00						; moving randomly under water
		JSR		_rand
		LSR
		BCC		locret_2CB5E
		ASL
		AND		#$C0
		LDX		_cur_trd_slot
		STA		_trds_args1,X
locret_2CB5E:
		RTS

; =============== S C R I P T ==========================s====================
_scr_dragons_flame:
		SARG_SET		SARG0,$00
		NJSR			_nsub_sarg1_direction_extract	; four kinds of flame sprites
		SJMP_SW			$04								; for every direction
		SCASE			_scr_dragons_flame_U
		SCASE			_scr_dragons_flame_R
		SCASE			_scr_dragons_flame_D
		SCASE			_scr_dragons_flame_L

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_U:
		POS_Y_MOVE		0,$CD
		SJMPS			_scr_dragons_flame_vert

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_D:
		POS_Y_MOVE		0,$22

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_vert:
		NBG_HNDL_SET	_nbgsub_dragon_flame_vert_ctest
		SPR_IDX_SET		1,$54
		SPR_IDX_INC		2
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_R:
		POS_X_MOVE		0,$2F
		POS_Y_MOVE		0,$04
		NBG_HNDL_SET	_nbgsub_dragon_flame_hor_ctest
		SPR_IDX_SET		1,$58
		SPR_IDX_INC		2
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_dragons_flame_L:
		POS_X_MOVE		0,$D1
		POS_Y_MOVE		0,$04
		NBG_HNDL_SET	_nbgsub_dragon_flame_hor_ctest
		SPR_IDX_SET		1,$56
		SPR_IDX_INC		2
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragon_flame_vert_ctest:
		LDX		#$09
		LDY		#$24
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_dragon_flame_hor_ctest:
		LDX		#$23
		LDY		#$0A
		JMP		_obj_to_player_ctest

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr2F_lvl5_boss_keykeeper
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_scr_boss_keykeeperA
		SCASE			_scr_boss_keykeeperB
		SCASE			_scr_keykeeper_death
		SCASE			_scr_keykeeper_projectile

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SJSR			_ssub_boss_music_fade_and_load
		NJSR			_nsub_keykeeper_init			; init internal extra vars here
		NJSR			_nsub_spr_pal_load				; the rest is usual
			NARGW		_pal_spr_boss_keykeeper
		STORE8			_chr_bank0,$18
		SARG_SET		SARG1,$40
		NJSR			_nsub_new_thread_start			; deploy another boss instance
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_boss_keykeeperA_idx+1
			NARGB		$00								; store its thread idx to the custom array
		NJSR			_nsub_keykeeper_thread_idx_register
		SSCRIPT1_SET	_scr_keykeeper_appear_blink		; wait until second instance stopped
		SDELAY			$28								; this thread will wait until second instance walk
		SDELAY			$B4								; then two more instances finish to work


; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_main:
		NJSR			_nsub_is_boss_three_obj_left_test	; if 3 or more objects to deploy left,
		SBCCS			_sloc_2CF51						; keep deploying boss instances
		NJSR			_nsub_keykeeper_active_obj_threads_reload	; as the main object deploying entities
			NARGW		_scr_keykeeper_moveA_blink		; set all objects the same short move script
		SSCRIPT1_SET	_scr_keykeeper_appear_blink		; with no collision test handler
		SDELAY			$28								; wait for they move
		NJSR			_keykeeper_clone_to_near_thread_slot
		NJSR			_nsub_new_thread_start			; start another instance
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_boss_keykeeperB_idx+1
			NARGB		$00
		NJSR			_nsub_keykeeper_thread_idx_register
		SDELAY			$B4								; still keep walking
_sloc_2CF51:
		NJSR			_nsub_keykeeper_active_obj_threads_reload
			NARGW		_scr_keykeeper_move_solid		; when all three instances deployed, set to all
		SDELAY			$28								; objects collision testable script and walk around
		SSCRIPT1_OFF									; for one cycle, then stop and reload regular palette
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_spr_boss_keykeeper+$0C

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sub_keykeeper_active:
		SDELAY			$01
		NJSR			_nsub_keykeeper_get_beamed_status
		SJMP_SW			$02
		SCASE			_sub_keykeeper_active
		SCASE			_sub_keykeeper_reinit

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_keykeeper_pos_lock		; lock all current positions for all objects
		NJSR			_nsub_keykeeper_active_obj_threads_reload
			NARGW		_scr_keykeeper_fire				; set firing state for all except beamed one

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_stop:
		SDELAY			$01								; test if beamer is lost its target
		NJSR			_nsub_mcmp
			NARGW		_keykeeper_beam_flag
			NARGB		$00
		SBCCS			_scr_keykeeper_shake			; of no, keep shaking
		NJSR			_nsub_keykeeper_pos_unlock		; or turn targeting bosses to normal

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_sub_keykeeper_reinit:
		NJSR			_nsub_keykeeper_active_obj_threads_reload
			NARGW		_scr_keykeeper_move_solid
		SJMPS			_sub_keykeeper_active

; =============== S C R I P T ==========================s====================
_scr_keykeeper_shake:
		NJSR			_nsub_mcmp						; here we test if object catched
			NARGW		_keykeeper_beam_flag			; _keykeeper_beam_flag == $02
			NARGB		$02
		SBCCS			_scr_keykeeper_stop
		NJSR			_nsub_keykeeper_pos_unlock		; when catched, decrement boss counter
		SMEM_ALU		_keykeeper_counter,_ADC,$FF
		NJSR			_nsub_is_boss_last_obj_left_test; test if there are few
		SBCCS			_scr_keykeeper_main				; restart base script then or stop cur entity
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_keykeeper_appear_blink:
		NJSR			_nsub_patch_pal_load			; black blinking while
			NARGB		$07								; appear and move
			NARGW		_pal_keykeeper_patch
		SDELAY			$02
		NJSR			_nsub_patch_pal_load
			NARGB		$07
			NARGW		_pal_spr_boss_keykeeper+$0C
		SDELAY			$02
		SJMPS			_scr_keykeeper_appear_blink

; =============== S C R I P T ==========================s====================
_scr_boss_keykeeperA:
		SARG_SET		SARG0,$00
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$28
		NJSR			_nsub_new_thread_start
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_boss_keykeeperB_idx+1
			NARGB		$00
		NJSR			_nsub_keykeeper_thread_idx_register
		SJMPS			_scr_keykeeper_move_common

; =============== S C R I P T ==========================s====================
_scr_boss_keykeeperB:
		SARG_SET		SARG0,$00
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$B4

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_moveA_blink:
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$28
		SJMPS			_scr_keykeeper_move_common

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_solid:
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		SDELAY			$28
		NBG_HNDL_SET	_nbgsub_keykeeper_ctest

; !FALLTHROUGH!

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_common:
		NJSR			_nsub_sarg1_direction_extract	; constantly moving around the
		SJSR_SW	$04										; corner, when reach corresponding limit
		SCASE			_scr_keykeeper_move_U			; turn to the next corner
		SCASE			_scr_keykeeper_move_R			; never stop
		SCASE			_scr_keykeeper_move_D
		SCASE			_scr_keykeeper_move_L
		POS_MOVE_STOP	0
		SARG_ALU		SARG1,_ADC,$40
		SJMPS			_scr_keykeeper_move_common

; =============== S C R I P T ==========================s====================
_scr_keykeeper_fire:
		NJSR			_nsub_cur_obj_to_beamer_dir_set	; keep firing state unless
		SDELAY			$01								; beamed object lost or catched
		NJSR			_nsub_spr_dir_select
			NARGB		$5A,$40
		NJSR			_nsub_keykeeper_spr_reverse
		SDELAY			$01
		NJSR			_nsub_new_thread_start			; deploy projectile
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$00
			NARGB		_scr_keykeeper_projectile_idx+1
			NARGB		$00
		SDELAY			$3C
		SJMPS			_scr_keykeeper_fire				; loop unless beamed object change state

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_R:
		SSCRIPT1_SET	_scr_keykeeper_move_R_anim
_sloc_2D022:
		NJSR			_nsub_keykeeper_R_limit_test	; test for reaching the limit
			NARGB		$C8
		SBCSS			_sloc_2D02E						; then exit to retarget
		SDELAY			$01								; else keep going
		SJMPS			_sloc_2D022
_sloc_2D02E:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_R_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5B
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$5F
		SDELAY			$08
		POS_X_DELTA_SET 0,$80,$00
		SPR_IDX_SET		0,$63
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$5F
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_R_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_L:
		SSCRIPT1_SET	_scr_keykeeper_move_L_anim
_sloc_2D050:
		NJSR			_nsub_keykeeper_L_limit_test
			NARGB		$30
		SBCSS			_sloc_2D05C
		SDELAY			$01
		SJMPS			_sloc_2D050
_sloc_2D05C:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_L_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5D
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$61
		SDELAY			$08
		POS_X_DELTA_SET 0,$80,$FF
		SPR_IDX_SET		0,$65
		SDELAY			$0A
		POS_X_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$61
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_L_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_U:
		SSCRIPT1_SET	_scr_keykeeper_move_U_anim
_sloc_2D07E:
		NJSR			_nsub_keykeeper_U_limit_test
			NARGB		$40
		SBCSS			_sloc_2D08A
		SDELAY			$01
		SJMPS			_sloc_2D07E
_sloc_2D08A:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_U_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5A
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$5E
		SDELAY			$08
		POS_Y_DELTA_SET 0,$80,$FF
		SPR_IDX_SET		0,$62
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_SET		0,$5E
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_U_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_D:
		SSCRIPT1_SET	_scr_keykeeper_move_D_anim
_sloc_2D0AC:
		NJSR			_nsub_keykeeper_D_limit_test
			NARGB		$A8
		SBCSS			_sloc_2D0B8
		SDELAY			$01
		SJMPS			_sloc_2D0AC
_sloc_2D0B8:
		SRET

; =============== S C R I P T ==========================s====================
_scr_keykeeper_move_D_anim:
		POS_MOVE_STOP	0
		SPR_IDX_SET		0,$5C
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$60
		SDELAY			$08
		POS_Y_DELTA_SET 0,$80,$00
		SPR_IDX_SET		0,$64
		SDELAY			$0A
		POS_Y_DELTA_SET 0,$00,$02
		SPR_IDX_SET		0,$60
		SDELAY			$06
		SJMPS			_scr_keykeeper_move_D_anim

; =============== S C R I P T ==========================s====================
_scr_keykeeper_stun:
		NBG_HNDL_SET	_nbgsub_keykeeper_catch_test	; also two-part handler
		NJSR			_nsub_spr_dir_select			; first part waiting for beaming time
			NARGB		$5A,$40
		SLOOP_BEGIN		$5A
		SPR_IDX_ADD_IMM 1,$0C
		SPR_IDX_ADD_IMM 1,$F4
		NJSR			_nsub_wait_for_beam_hold
		SBCS_BREAK		_sloc_2D112
		SLOOP_END
		SARG_SET		SARG0,$02
		NJSR			_nsub_is_boss_one_obj_left_test	; also additional test if there is a last
		SBCSS			_sloc_2D103						; object
		SPR_IDX_ADD_IMM 0,$10							; set new sprite with red palette set
_sloc_2D0F6:
		SPR_IDX_ADD_IMM 1,$04							; because all objects uses the same pal
		SPR_IDX_ADD_IMM 1,$FC							; we just can't use the same pal trick as
		NJSR			_nsub_wait_for_beam_hold		; for lvl1 boss for exmple...
		SBCCS			_sloc_2D0F6
		SJMPS			_sloc_2D112
_sloc_2D103:
		NJSR			_nsub_spr_dir_select			; start to disappear and baby appear
			NARGB		$5A,$40
		SDELAY			$01
		SPR_IDX_SET		1,$76
		NJSR			_nsub_wait_for_beam_hold
		SBCCS			_sloc_2D103
_sloc_2D112:
		NJSR			_nsub_get_obj_stun_state
		SJMP_SW			$03
		SCASE			_scr_keykeeper_lost
		SCASE			_scr_keykeeper_catch_anim_L
		SCASE			_scr_keykeeper_catch_anim_R

; =============== S C R I P T ==========================s====================
_scr_keykeeper_lost:
		STORE8			_keykeeper_beam_flag,$00		; reset flag, the rest is up to other part of script
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_keykeeper_catch_anim_L:
		NJSR			_nsub_keykeeper_thread_idx_remove	; remove it from local tmp list
		NJSR			_nsub_is_boss_one_obj_left_test	; test if there is not the last boss
		SBCCS			_sloc_2D133						; if yes, deploy death anim
		NJSR			_nsub_new_thread_start
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$18
			NARGB		_scr_keykeeper_death_idx+1
			NARGB		$00
_sloc_2D133:
		SARG_SET		SARG1,$72						; or just play catch anim with sound
		SJMP			_ssub_common_catch_anim_L_snd19

; =============== S C R I P T ==========================s====================
_scr_keykeeper_catch_anim_R:
		NJSR			_nsub_keykeeper_thread_idx_remove
		NJSR			_nsub_is_boss_one_obj_left_test
		SBCCS			_sloc_2D14A
		NJSR			_nsub_new_thread_start
			NARGB		_scr2F_lvl5_boss_keykeeper_idx
			NARGB		$00,$18
			NARGB		_scr_keykeeper_death_idx+1
			NARGB		$00
_sloc_2D14A:
		SARG_SET		SARG1,$74
		SJMP			_ssub_common_catch_anim_R_snd19

_pal_spr_boss_keykeeper:
		.BYTE	$0F,$36,$1C,$0F,$0F,$21,$25,$15,$0F,$25,$15,$0F,$0F,$36,$1B,$0F
_pal_keykeeper_patch:
		.BYTE	$0F,$0F,$0F,$0F

; =============== S U B R O U T I N E ======n================================
_nbgsub_keykeeper_ctest:
		LDX		#$10
		LDY		#$16
		JSR		_obj_to_beam_ctest
		BCC		loc_2D178
		LDA		#$01
		STA		_keykeeper_beam_flag
		JSR		_cur_thread_reload_param
		.WORD	_scr_keykeeper_stun
		RTS
loc_2D178:
		LDX		#$0F
		LDY		#$18
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nbgsub_keykeeper_catch_test:
		LDX		_cur_trd_slot
		LDA		_trds_args0,X
		BPL		locret_2D198
		LSR
		LDA		#$0F
		STA		_scores_obj_value
		BCS		loc_2D193
		JSR		_cur_thread_reload_param
		.WORD	_scr_keykeeper_catch_anim_L
		RTS
loc_2D193:
		JSR		_cur_thread_reload_param
		.WORD	_scr_keykeeper_catch_anim_R
locret_2D198:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_boss_three_obj_left_test:
		LDA		_keykeeper_counter
		CMP		#$03
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_boss_last_obj_left_test:
		LDA		_keykeeper_counter
		BNE		loc_2D1A6
		SEC
		RTS
loc_2D1A6:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_is_boss_one_obj_left_test:
		LDA		_keykeeper_counter
		CMP		#$01
		BEQ		locret_2D1B0
		CLC
locret_2D1B0:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_spr_reverse:
		LDX		_cur_trd_slot
		LDY		_obj_spr_idx,X
		LDA		byte_2D1BB-$5A,Y
		STA		_obj_spr_idx,X
		RTS
byte_2D1BB:
		.BYTE	$5D,$5A,$5B,$5C

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_active_obj_threads_reload:
		JSR		_scr_getc
		STA		_tmp0
		JSR		_scr_getc
		STA		_tmp2
		LDY		#$02
loc_2D1CB:
		TYA
		PHA
		LDX		_boss_tmp_list,Y
		BMI		loc_2D1EC
		LDA		_trds_obj_idx,X
		BMI		loc_2D1EC
		LDA		_trds_args0,X
		BNE		loc_2D1EC
		LDA		_tmp2
		PHA
		LDA		_tmp0
		PHA
		LDY		_tmp2
		JSR		_thread_load
		PLA
		STA		_tmp0
		PLA
		STA		_tmp2
loc_2D1EC:
		PLA
		TAY
		DEY
		BPL		loc_2D1CB
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_get_beamed_status:
		LDA		_keykeeper_beam_flag		; return $00 if no beamed at all
		BEQ		locret_2D214
		LDY		#$02
loc_2D1F9:
		LDX		_boss_tmp_list,Y			; look for currently beamed
		BMI		loc_2D207					; return $02 if any
		LDA		_trds_obj_idx,X
		BMI		loc_2D207
		LDA		_trds_args0,X
		BNE		loc_2D212
loc_2D207:
		DEY
		BPL		loc_2D1F9
		LDA		#$00						; if beamed flag set but no beamed
		STA		_keykeeper_beam_flag		; objects left, reset beamed flag,
		LDA		#$01						; return $01
		RTS
loc_2D212:
		LDA		#$02
locret_2D214:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_pos_lock:
		LDY		#$02
loc_2D217:
		LDX		_boss_tmp_list,Y
		BMI		loc_2D225
		LDA		_trds_obj_idx,X
		BMI		loc_2D225
		LDA		_trds_args1,X
		STA		_trds_args2,X
loc_2D225:
		DEY
		BPL		loc_2D217
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_pos_unlock:
		LDY		#$02
loc_2D22B:
		LDX		_boss_tmp_list,Y
		BMI		loc_2D239
		LDA		_trds_obj_idx,X
		BMI		loc_2D239
		LDA		_trds_args2,X
		STA		_trds_args1,X
loc_2D239:
		DEY
		BPL		loc_2D22B
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_thread_idx_remove:
		LDY		#$02
loc_2D23F:
		LDA		_boss_tmp_list,Y
		CMP		_cur_trd_slot
		BEQ		loc_2D24C
		DEY
		BPL		loc_2D23F
loc_2D249:
		JMP		loc_2D249					; original DEBUG assert here
loc_2D24C:
		LDA		#$FF
		STA		_boss_tmp_list,Y
		LDA		#$02
		STA		_keykeeper_beam_flag
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_thread_idx_register:
		LDX		#$00
loc_2D259:
		LDA		_boss_tmp_list,X
		BMI		loc_2D266
		INX
		CPX		#$03
		BCC		loc_2D259
loc_2D263:
		JMP		loc_2D263					; original DEBUG assert here also
loc_2D266:
		LDA		_nsub_return_value
		STA		_boss_tmp_list,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_init:
		LDA		#$FF
		STA		_boss_tmp_list
		STA		_boss_tmp_list+1
		STA		_boss_tmp_list+2
		LDA		#$00
		STA		_keykeeper_beam_flag
		LDA		#$0A
		STA		_keykeeper_counter
		RTS

; =============== S U B R O U T I N E ======n================================
_keykeeper_clone_to_near_thread_slot:
		JSR		_keykeeper_get_near_thread_idx_slot
		TAY
		LDX		_boss_tmp_list,Y
		LDY		_cur_trd_slot
		LDA		_obj_x_pos_lo,X
		STA		_obj_x_pos_lo,Y
		LDA		_obj_x_pos_hi,X
		STA		_obj_x_pos_hi,Y
		LDA		_obj_y_pos_lo,X
		STA		_obj_y_pos_lo,Y
		LDA		_obj_y_pos_hi,X
		STA		_obj_y_pos_hi,Y
		LDA		_trds_args1,X
		STA		_trds_args1,Y
		RTS

; =============== S U B R O U T I N E ======n================================
_keykeeper_get_near_thread_idx_slot:
		LDY		#$02
loc_2D2A9:
		LDA		_boss_tmp_list,Y
		BMI		loc_2D2B4
		DEY
		BPL		loc_2D2A9
loc_2D2B1:
		JMP		loc_2D2B1					; original DEBUG assert here also
loc_2D2B4:
		LDA		byte_2D2B8,Y
		RTS
byte_2D2B8:
		.BYTE	$02,$00,$01

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_R_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_x_pos_lo,X
		BEQ		loc_2D2C8
		BCS		loc_2D2CA
		STA		_obj_x_pos_lo,X
loc_2D2C8:
		SEC
		RTS
loc_2D2CA:
		CLC
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_L_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_x_pos_lo,X
		BCC		locret_2D2D7
		STA		_obj_x_pos_lo,X
locret_2D2D7:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_U_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_y_pos_lo,X
		BCC		locret_2D2E3
		STA		_obj_y_pos_lo,X
locret_2D2E3:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_D_limit_test:
		JSR		_scr_getc
		LDX		_cur_trd_slot
		CMP		_obj_y_pos_lo,X
		BEQ		loc_2D2F1
		BCS		loc_2D2F3
		STA		_obj_y_pos_lo,X
loc_2D2F1:
		SEC
		RTS
loc_2D2F3:
		CLC
		RTS

; =============== S C R I P T ==========================s====================
_scr_keykeeper_death:
		SARG_SET		SARG0,$00						; remove main boss object
		SPR_IDX_SET		0,$76							; set baby keykeeper sprite
		SDELAY			$20
		POS_Y_DELTA_SET 4,$00,$02						; animate it
		POS_MOVE_STOP	0
		SPR_IDX_SET		4,$78
		SPR_IDX_INC		4
		SPR_IDX_SET		0,$76							; set stage complete script
		SDELAY			$3C
		NJSR			_nsub_stage_complete_force
		SUSPEND

; =============== S C R I P T ==========================s====================
_scr_keykeeper_projectile:
		SARG_SET		SARG0,$00
		NJSR			_nsub_keykeeper_projectile_init	; init starting pos and direction
		SLOOP_BEGIN		$03
		SPR_IDX_SET		2,$FF							; start to animate it first around
		NJSR			_nsub_obj_spr_idx_set_from_sarg	; head
			NARGB		SARG2
		SDELAY			$02
		SLOOP_END										; then start to move in targets direction
		NJSR			_nsub_apu_snd_load
			NARGB		_snd0F_idx
		NBG_HNDL_SET	_nbgsub_keykeeper_projectile_ctest	; deadly projectile collision test
		NJSR			_nsub_spr_dir_select			; reinit sprite
			NARGB		$7C,$20
		NJSR			_nsub_speed_dir_select			; keep going, script is done here
			NARGB		$00,$03
		SUSPEND

; =============== S U B R O U T I N E ======n================================
_nbgsub_keykeeper_projectile_ctest:
		LDX		#$09
		LDY		#$0A
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S U B R O U T I N E ======n================================
_nsub_keykeeper_projectile_init:
		LDY		_cur_trd_slot
		LDA		_trds_args1,Y
		CLC
		ADC		#$20
		AND		#$C0
		ASL
		ROL
		ROL
		TAX
		LDA		_obj_x_pos_lo,Y
		CLC
		ADC		byte_2D886,X
		STA		_obj_x_pos_lo,Y
		LDA		_obj_x_pos_hi,Y
		ADC		byte_2D88A,X
		STA		_obj_x_pos_hi,Y
		LDA		_obj_y_pos_lo,Y
		CLC
		ADC		byte_2D88E,X
		STA		_obj_y_pos_lo,Y
		LDA		_obj_y_pos_hi,Y
		ADC		byte_2D892,X
		STA		_obj_y_pos_hi,Y
		TXA
		AND		#$01
		CLC
		ADC		#$7A
		STA		_trds_args2,Y
		RTS
byte_2D886:
		.BYTE	$00,$05,$00,$FB
byte_2D88A:
		.BYTE	$00,$00,$00,$FF
byte_2D88E:
		.BYTE	$E8,$FE,$FD,$FE
byte_2D892:
		.BYTE	$FF,$FF,$FF,$FF

; =============== S C R I P T ==========================s====================
		FAR_OFS			_scr30_lvl6_boss_vega
		NJSR			_nsub_obj_sarg_add_imm_test
			NARGB		SARG0,$FF
		SJMP_SW			$04
		SCASE			_scr_vega_projectileA
		SCASE			_scr_vega_fireball
		SCASE			_scr_vega_projectileB
		SCASE			_scr_vega_mother

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		SLOOP_BEGIN		$C8								; default initialization
		SMEM_ALU		_apu_mus_volume,_ADC,$FF		; slowly lower the music volume
		SDELAY			$02								; in about 6 seconds
		SLOOP_END
		NJSR			_nsub_apu_snd_load				; start laughing sound effect
			NARGB		_snd0E_idx
		SDELAY			$64
		STORE8			_apu_mus_volume,$FF				; restore music volume and play
		NJSR			_nsub_apu_mus_load				; custom boss music
			NARGB		_musB_idx
		SPR_IDX_SET		0,$C0							; display sprite (hidden)
		SLOOP_BEGIN		$04								; slowly reveal through the
		NJSR			_nsub_pal_fade_req_inc_by_mask	; palette fade in effect
			NARGB		$22
		SDELAY			$06
		SLOOP_END
		STORE16			_boss_tmp_list,$800				; set HP for this boss
		NBG_HNDL_SET	_nbgsub_vega_ctest				; set bg damage detection routine
		SSCRIPT1_SET	_scr_vega_blinker				; start damage blinker secondary script
		SDELAY			$B4								; now wait for a while
		POS_Y_DELTA_SET 0,$80,$00						; and move forth from the painting
		SDELAY			$60
		POS_MOVE_STOP	0								; stop, get to the main loop
_sloc_2D90E:
		SPR_IDX_SET		0,$C0							; delay before attack
		SDELAY			$62
		SARG_SET		SARG1,$00						; reset attack tmp var
		NJSR			_nsub_new_thread_start			; start to attack
			NARGB		_scr30_lvl6_boss_vega_idx		; deploy four projectiles
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$20
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$60
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$A0
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$00
			NARGB		_scr_vega_projectileA_idx+1
			NARGB		$E0
		SDELAY			$2E								; animate vega controlling projectiles
		SLOOP_BEGIN		$04
		SPR_IDX_SET		0,$C1
		SDELAY			$0C
		SLOOP_BEGIN		$03
		SPR_IDX_INC		0
		SDELAY			$0C
		SLOOP_END
		SLOOP_END
		SPR_IDX_DEC		0
		SDELAY			$0C
		NJSR			_nsub_new_thread_start			; all fireballs shrinked to one single
			NARGB		_scr30_lvl6_boss_vega_idx		; pulsating ball
			NARGB		$00,$00
			NARGB		_scr_vega_fireball_idx+1
			NARGB		$00
		SDELAY			$20								; some more hands shaking
		SPR_IDX_SET		0,$C0
		SDELAY			$10
		SPR_IDX_SET		0,$C5
		SDELAY			$08
		NJSR			_nsub_vega_shot_targeting		; random targering to fire
		NJSR			_nsub_new_thread_start			; deploy three fire balls
			NARGB		_scr30_lvl6_boss_vega_idx		; from one hand
			NARGB		$10,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$4C
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$6C
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$10,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$8C
		SDELAY			$10								; then the same from another hand
		SPR_IDX_INC		0
		SDELAY			$08
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$74
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$94
		NJSR			_nsub_new_thread_start
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$F0,$F8
			NARGB		_scr_vega_projectileB_idx+1
			NARGB		$B4
		SDELAY			$10
		SJMP			_sloc_2D90E						; repeat boss pattern

; =============== S C R I P T ==========================s====================
_scr_vega_blinker:
		SDELAY			$01
		NJSR			_nsub_obj_sarg_add_imm_test		; wait when need to blink
			NARGB		SARG0,$00
		SJMP_SW			$01
		SCASE			_scr_vega_blinker				; and blink!

; !FALLTHROUGH!

; =============== D E F A U L T  S C R I P T  C A S E ==s====================
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_vega_blink_patch
		SDELAY			$01
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_vega_normal_patch
		SDELAY			$01
		SJMPS			_scr_vega_blinker

_pal_vega_normal_patch:
		.BYTE	$0F,$36,$17,$0F
_pal_vega_blink_patch:
		.BYTE	$0F,$20,$20,$20

; =============== S C R I P T ==========================s====================
_scr_vega_death:
		NJSR			_nsub_gen_threads_off_except_cur; start final boss death cutscene
		NJSR			_nsub_patch_pal_load
			NARGB		$06
			NARGW		_pal_vega_normal_patch
		SPR_IDX_SET		0,$C1							; stop animating
		SDELAY			$40
		SPR_IDX_SET		0,$C7
		SDELAY			$10								; start scream sound
		NJSR			_nsub_apu_mus_load
			NARGB		$FF
		NJSR			_nsub_apu_snd_load
			NARGB		_snd1A_idx
		POS_Y_DELTA_SET 0,$00,$FC						; now dodging back to painting
		SPR_IDX_SET		4,$84
		SPR_IDX_INC		4
		POS_Y_DELTA_SET 0,$00,$FE
		SPR_IDX_INC		4
		POS_Y_DELTA_SET 0,$00,$FF
		SPR_IDX_INC		4
		POS_MOVE_STOP	0
		SPR_IDX_INC		4
		SPR_IDX_SET		0,$FF
		SDELAY			$5A								; final scene starts, auto play script
		NJSR			_nsub_lvl6_players_auto_scriptsB_set	; for players
		POS_X_SET		0,$80,$00
		POS_Y_SET		0,$98,$00						; show blinking baby
		SPR_IDX_SET		1,$91
		SPR_IDX_SET		2,$FF
		SPR_IDX_SET		3,$91
		SPR_IDX_SET		4,$FF
		SPR_IDX_SET		5,$91
		SPR_IDX_SET		6,$FF
		SPR_IDX_SET		7,$91
		SPR_IDX_SET		0,$FF
		SDELAY			$08
		SPR_IDX_SET		0,$91
		SDELAY			$09
		SPR_IDX_SET		0,$FF
		SDELAY			$0A
		SPR_IDX_SET		0,$91
		SDELAY			$0B
		SPR_IDX_SET		0,$FF
		SDELAY			$0C
		SPR_IDX_SET		0,$91
		SDELAY			$0D
		SPR_IDX_SET		0,$FF
		SDELAY			$0E
		SPR_IDX_SET		0,$91
		SDELAY			$96
		NJSR			_nsub_new_thread_start			; deploy mother script, walk to baby
			NARGB		_scr30_lvl6_boss_vega_idx
			NARGB		$00,$58
			NARGB		_scr_vega_mother_idx+1
			NARGB		$00
		SDELAY			$40
		SLOOP_BEGIN		$04
		NJSR			_nsub_pal_fade_req_dec_by_mask	; fade out
			NARGB		$FF
		SDELAY			$08
		SLOOP_END
		STORE8			_game_flags,$80					; no sclear screen here, just silently exit
		NJSR			_nsub_all_threads_off_except_cur; script with complere stage flag
		SSTOP

; =============== S U B R O U T I N E ======n================================
_nbgsub_vega_ctest:
		LDX		#$15
		LDY		#$26
		JSR		_obj_to_player_ctest
		LDX		#$10
		LDY		#$18
		JSR		_obj_to_beam_ctest			; this is not regular ctest for beam
		LDX		_cur_trd_slot				; we don't have stun or beamed scripts for vega
		LDA		_trds_args0,X				; it is only an amount of beam damage
		BEQ		locret_2DA6F				; that counts
		LDA		_boss_tmp_list
		SEC
		SBC		#$01
		STA		_boss_tmp_list
		LDA		_boss_tmp_list+1
		SBC		#$00
		STA		_boss_tmp_list+1
		ORA		_boss_tmp_list				; beam it until death, thats all
		BNE		locret_2DA6F
		JSR		_cur_thread_reload_param
		.WORD	_scr_vega_death
		LDA		#$C8
		JSR		_scores_add
locret_2DA6F:
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_vega_shot_targeting:
		LDA		#$21
		JSR		_rand
		SEC
		SBC		#$10
		LDX		_cur_trd_slot
		STA		_trds_args1,X
		RTS

; =============== S U B R O U T I N E ======n================================
_nsub_lvl6_players_auto_scriptsB_set:
		LDX		#$02
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl6_beamer_auto_scriptB
		LDX		#$04
		JSR		_thread_reload_param_ex
		.WORD	_scr_lvl6_catcher_auto_scriptB
		RTS

; =============== S C R I P T ==========================s====================
_scr_vega_projectileA:
		SARG_SET		SARG0,$00						; this projectile moves in circles
		SSCRIPT1_SET	_scr_vega_projectileA_anim		; around vega
		NBG_HNDL_SET	_nbgsub_vega_projectileA_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$04
		SDELAY			$10
		POS_MOVE_STOP	0
		SDELAY			$4E
		SARG_ALU		SARG1,_ADC,$40
		SLOOP_BEGIN		$80
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$06
		SDELAY			$01
		SARG_ALU		SARG1,_ADC,$04
		SLOOP_END
		SARG_SET		SARG2,$04
		SLOOP_BEGIN		$07
		SLOOP_BEGIN		$04
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$06
		SDELAY			$01
		NJSR			_nsub_vega_projectileA_shrink
		SLOOP_END
		SARG_ALU		SARG2,_ADC,$01					; final shrinking
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_vega_projectileA_anim:
		SPR_IDX_SET		1,$8B
		SPR_IDX_INC		1
		SJMPS			_scr_vega_projectileA_anim

; =============== S U B R O U T I N E ======n================================
_nbgsub_vega_projectileA_ctest:
		LDX		#$08
		LDY		#$09
		JMP		_obj_to_player_ctest

; =============== S U B R O U T I N E ======n================================
_nsub_vega_projectileA_shrink:
		LDX		_cur_trd_slot
		LDA		_trds_args1,X
		CLC
		ADC		_trds_args2,X
		STA		_trds_args1,X
		RTS

; =============== S C R I P T ==========================s====================
_scr_vega_fireball:
		SARG_SET		SARG0,$00
		SPR_IDX_SET		0,$8A
		SLOOP_BEGIN		$03
		SLOOP_BEGIN		$03
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$02
		SLOOP_END
		SLOOP_BEGIN		$07
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SLOOP_END
		SSTOP

; =============== S C R I P T ==========================s====================
_scr_vega_projectileB:
		SARG_SET		SARG0,$00
		NBG_HNDL_SET	_nbgsub_vega_projectileB_ctest
		NJSR			_nsub_speed_dir_select
			NARGB		$00,$03
		SPR_IDX_SET		0,$8A
		SLOOP_BEGIN		$03
		SLOOP_BEGIN		$02
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SLOOP_END
		SPR_IDX_ADD_IMM 0,$02
		SLOOP_END
_sloc_2DF73:
		SPR_IDX_DEC		1
		SPR_IDX_INC		1
		SJMPS			_sloc_2DF73

; =============== S U B R O U T I N E ======n================================
_nbgsub_vega_projectileB_ctest:
		LDX		#$08
		LDY		#$09
		JSR		_obj_to_player_ctest
		JMP		_cur_obj_out_of_screen_test

; =============== S C R I P T ==========================s====================
_scr_vega_mother:
		POS_Y_DELTA_SET 0,$00,$FF
		SLOOP_BEGIN		$04
		SPR_IDX_SET		4,$92
		SPR_IDX_INC		4
		SPR_IDX_INC		4
		SPR_IDX_DEC		4
		SLOOP_END
		POS_MOVE_STOP	0
		SUSPEND

		SECTION_END	"OBJECT SCRIPTS B (BOSSES)"

		BANK_END 1,$C000
