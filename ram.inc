
		INCLUDE		"../macroses.inc"

;--------------------R-A-M----------------------

		ORG $0000

_ppu_ctrl_shadow:
		.BYTE	0
_ppu_mask_req:
		.BYTE	0
_ppu_mask_shadow:
		.BYTE	0
_nmi_flag:
		.BYTE	0
_pad0_held:
		.BYTE	0
#if TWO_PLAYER_MODE==1
_pad1_held:
		.BYTE	0
#endif
_pad0_pressed:
		.BYTE	0
#if TWO_PLAYER_MODE==1
_pad1_pressed:
		.BYTE	0
#endif
_ptr06:
		.BYTE	0,0
_ptr08:
		.BYTE	0,0
_ptr0A:
		.BYTE	0,0
_var0:
		.BYTE	0
_var1:
		.BYTE	0
_var2:
		.BYTE	0
_var3:
		.BYTE	0
_var4:
		.BYTE	0
_var5:
		.BYTE	0
_var6:
		.BYTE	0
_var7:
		.BYTE	0
_tmp0:
		.BYTE	0
_tmp1:
		.BYTE	0
_tmp2:
		.BYTE	0
_ptr17:
		.BYTE	0,0
_tmp19:
		.BYTE	0
_tmp1A:
		.BYTE	0
_tmp1B:
		.BYTE	0
#if TWO_PLAYER_MODE==1
_tmp1C:
		.BYTE	0
_tmp1D:
		.BYTE	0
#endif
_ptr1E:
		.BYTE	0,0
#if DEBUG==1
_debug_vars_list:
_debug_chr0:
		.BYTE	0
_debug_chr1:
		.BYTE	0
_debug_lib_idx:
		.BYTE	0
_debug_lib_type:
		.BYTE	0
_debug_spr:
		.BYTE	0
_debug_pos_idx:
		.BYTE	0
_debug_cnt:
		.BYTE	0,0
#endif
_random_seed:
		.BYTE	0,0
_mmc1_ctrl_shadow:
		.BYTE	0
_prg_cur_bank:
		.BYTE	0
_chr_bank0:
		.BYTE	0
_chr_bank1:
		.BYTE	0
_lvl_data_prg_bank:
		.BYTE	0
_spr_buf_pos:
		.BYTE	0
_mmc1_busy:
		.BYTE	0
_apu_play_delayed_req:
		.BYTE	0
_prg_bank:
		.BYTE	0
; REGION, new var added in the EU version
_ppu_forbid_flag:
		.BYTE	0
_ppu_queue_head:
		.BYTE	0
_ppu_queue_tail:
		.BYTE	0
_ppu_queue_pos:
		.BYTE	0
_ppu_queue_tail_tmp:
		.BYTE	0
_nmi_counter:
		.BYTE	0
;_unused_13:
;		.BYTE	0
_apu_cur_pc:
		.BYTE	0,0
_apu_cur_sp:
		.BYTE	0
_apu_ptr35:
		.BYTE	0,0
_ppu_scroll_pos_x:
		.BYTE	0,0
_ppu_scroll_pos_y:
		.BYTE	0,0
_trds_manager_restart_flag:
		.BYTE	0
_trds_exec_req:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_pos_lo:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_pos_lo:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_spr_idx:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_args0:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_args1:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_args2:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_cur_scr_pc:
		.BYTE	0,0
_cur_scr_sp:
		.BYTE	0,0
_ppu_scroll_x_shift:
		.BYTE	0,0
_ppu_scroll_y_shift:
		.BYTE	0,0
_ppu_scroll_x_clk:
		.BYTE	0
_ppu_scroll_y_clk:
		.BYTE	0
_cur_trd_slot:
		.BYTE	0
_tmp_loop_cnt:
		.BYTE	0
_cur_trd_scr_slot:
		.BYTE	0
_nsub_return_flags:
		.BYTE	0
_nsub_return_value:
		.BYTE	0
_pal_fade_req_list:
		.BYTE	0,0,0,0,0,0,0,0
_ppu_scroll_x_page:
		.BYTE	0 	; обе переменные инициализируются нулем	и используются
					; в вычислениях	как ноль. скриптовые команды, которые
					; должны их менять, не используются в игре. фактически
					; данные переменные и предназначенные для них эффекты
					; в игре не нужны.
_ppu_scroll_y_page:
		.BYTE	0
_spr_buf_shuffle:
		.BYTE	0
_spr_x_clip_flag:
		.BYTE	0
_spr_y_clip_flag:
		.BYTE	0
_lvl_macroA_ptr:
		.BYTE	0,0
_lvl_macroB_ptr:
		.BYTE	0,0
_lvl_macroC_ptr:
		.BYTE	0,0
_lvl_macroD_ptr:
		.BYTE	0,0
_lvl_attrs_ptr:
		.BYTE	0,0
_lvl_rooms_lib_ptr:
		.BYTE	0,0
_lvl_collisions_ptr:
		.BYTE	0,0
_room_doors_data_ptr:
		.BYTE	0,0
_lvl_objects_ptr:
		.BYTE	0,0
_room_prize_sequence_ptr:
		.BYTE	0,0
_room_exits_ptr:
		.BYTE	0,0
_tmp_var0:
		.BYTE	0
_tmp_var1:
		.BYTE	0
_pause_mode_flag:
		.BYTE	0
_out_of_screen_test_flag:
		.BYTE	0
_obj_x_screen_pos:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_screen_pos:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_cur_room_x_pageA:
		.BYTE	0
_cur_room_y_pageA:
		.BYTE	0
_cur_room_x_pageB:
		.BYTE	0
_cur_room_y_pageB:
		.BYTE	0

		ECHO "-------------"
		ECHO "zero ram free:",[$100-.]
		ECHO "-------------"

		ORG		$100

_tmp_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0
_pal_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_speed:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_speed:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_nbgsub_ptr:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_clk:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_clk:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_x_pos_hi:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_pos_hi:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0

		ECHO "-------------"
		ECHO "stack ram free:",[$200-.]
		ECHO "-------------"

		ORG		$200

_ppu_spr_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_ppu_queue_buf:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_apu_var400:
		.BYTE	0
_apu_snd_volume:
		.BYTE	0
_apu_mus_volume:
		.BYTE	0
_apu_var403:
		.BYTE	0
_apu_var404:
		.BYTE	0
;_unused_8:
;		.BYTE	0
_apu_reg_pulse0_A:
		.BYTE	0,0,0,0
_apu_reg_pulse1_A:
		.BYTE	0,0,0,0
_apu_reg_trian_A:
		.BYTE	0,0,0,0
_apu_reg_noise_A:
		.BYTE	0,0,0,0
_apu_reg_pulse0_B:
		.BYTE	0,0,0,0
_apu_reg_pulse1_B:
		.BYTE	0,0,0,0
_apu_reg_trian_B:
		.BYTE	0,0,0,0
_apu_reg_noise_B:
		.BYTE	0,0,0,0
_apu_reg_pulse0_C:
		.BYTE	0,0,0,0
_apu_reg_pulse1_C:
		.BYTE	0,0,0,0
_apu_reg_trian_C:
		.BYTE	0,0,0,0
_apu_reg_noise_C:
		.BYTE	0,0,0,0
_apu_chnl_type:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_mus_delay:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_mus_pc_lo:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_mus_pc_hi:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_snd_delay:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_snd_pc_lo:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_snd_pc_hi:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_var05:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_var06:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_var08:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_var09:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_smpl:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_var0B:
		.BYTE	0,0,0,0,0,0,0,0,0,0
;_apu_chnl_freq_tbl:
;		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_mus_sp:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_snd_sp:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_chnl_var0F:
		.BYTE	0,0,0,0,0,0,0,0,0,0
_apu_stack:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_apu_var580:
		.BYTE	0
_obj_x_delta:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_obj_y_delta:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_scr_sp:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_scr_delay:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0

		_ttrd _trd_ptr
		_ttrd _trd_ptr1
		_ttrd _trd_ptr2
		_ttrd _trd_ptr3
		_ttrd _trd_ptr4
		_ttrd _trd_ptr5
		_ttrd _trd_ptr6
		_ttrd _trd_ptr7
		_ttrd _trd_ptr8
		_ttrd _trd_ptr9
		_ttrd _trd_ptrA
		_ttrd _trd_ptrB
		_ttrd _trd_ptrC
		_ttrd _trd_ptrD

_trds_scr_stack:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

_cur_room_doors_cnt:
		.BYTE	0
_menu_controls_idx:
		.BYTE	0
_menu_difficulty_idx:
		.BYTE	0
_sound_test_mus_idx:
		.BYTE	0
_sound_test_snd_idx:
		.BYTE	0
_doors_x_pos_hi:
		.BYTE	0,0,0,0,0,0,0,0
_doors_y_pos_hi:
		.BYTE	0,0,0,0,0,0,0,0
_doors_x_pos_lo:
		.BYTE	0,0,0,0,0,0,0,0
_doors_y_pos_lo:
		.BYTE	0,0,0,0,0,0,0,0
_doors_width:
		.BYTE	0,0,0,0,0,0,0,0
_doors_height:
		.BYTE	0,0,0,0,0,0,0,0
_attr_buf_pageA:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_attr_buf_pageB:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_active_door_data_pos:
		.BYTE	0
_beam_target_x_pos:
		.BYTE	0
_beam_target_y_pos:
		.BYTE	0
_catcher_turns_flags:
		.BYTE	0,0
_catcher_turns_count:
		.BYTE	0
_beamer_direction_idx:
		.BYTE	0
#if TWO_PLAYER_MODE==1
_catcher_direction_idx:
		.BYTE	0
#endif
_beamer_speed:
		.BYTE	0,0
_catcher_speed:
		.BYTE	0,0
_tmp_idx:
		.BYTE	0
#if TWO_PLAYER_MODE==0
_catcher_direction_idx:
		.BYTE	0
#endif
_beamer_spr_base_tmp:
		.BYTE	0
_catcher_spr_base_tmp:
		.BYTE	0
_beamer_spr_base:
		.BYTE	0
_catcher_spr_base:
		.BYTE	0
_catcher_target_slot_idx:
		.BYTE	0
_catcher_target_distance:
		.BYTE	0
_players_hit_flag:
		.BYTE	0
#if TWO_PLAYER_MODE==1
		.BYTE	0
#endif
_cur_room_orientation_idx:
		.BYTE	0
_cur_room_data_col:
		.BYTE	0
_cur_room_data_row:
		.BYTE	0
_cur_lvl_room_idx:
		.BYTE	0
_lvl_cur_checkpoint_idx:
		.BYTE	0
_lvl_last_checkpoint_idx:
		.BYTE	0
_apu_cur_snd_idx:
		.BYTE	0
_apu_cur_mus_idx:
		.BYTE	0
_scores_obj_value:
		.BYTE	0
_scores:
		.BYTE	0,0
_hi_scores:
		.BYTE	0,0
_players_lives:
		.BYTE	0
#if TWO_PLAYER_MODE==1
		.BYTE	0
#endif
_players_inv_timer:
		.BYTE	0
#if TWO_PLAYER_MODE==1
		.BYTE	0
#endif
_game_flags:
		.BYTE	0
_continues:
		.BYTE	0
_scores_1st_extend:
		.BYTE	0,0
_scores_2nd_extend:
		.BYTE	0,0
_scores_to_next_life:
		.BYTE	0,0
_level:
		.BYTE	0
_boss_tmp_list:
		.BYTE	0,0,0
_keykeeper_beam_flag:
		.BYTE	0
_keykeeper_counter:
		.BYTE	0
_ram_signature:
		.BYTE	0,0
_license_screen_display_flag:
		.BYTE	0
_difficulty:
		.BYTE	0
_control_beam_button_code:
		.BYTE	0
_control_catch_button_code:
		.BYTE	0
_obj_out_of_screen:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0
_trds_obj_idx:
		.BYTE	0,0,0,0,0,0,0,0,0,0,0,0,0,0

		ECHO "-------------"
		ECHO "general ram free:",[$800-.]
		ECHO "-------------"

;--------------------P-P-U----------------------

		ORG $2000

_PPU_CTRL:
		.BYTE 0
_PPU_MASK:
		.BYTE 0
_PPU_STATUS:
		.BYTE 0
_PPU_OAM_ADDR:
		.BYTE 0
_PPU_OAM_DATA:
		.BYTE 0
_PPU_SCROLL:
		.BYTE 0
_PPU_ADDR:
		.BYTE 0
_PPU_DATA:
		.BYTE 0

;--------------------A-P-U----------------------

		ORG $4000

_APU_PULSE1_ENV:
		.BYTE 0
_APU_PULSE1_SWEEP:
		.BYTE	0
_APU_PULSE1_TIME:
		.BYTE 0
_APU_PULSE1_LEN:
		.BYTE 0
_APU_PULSE2_ENV:
		.BYTE 0
_APU_PULSE2_SWEEP:
		.BYTE	0
_APU_PULSE2_TIME:
		.BYTE 0
_APU_PULSE2_LEN:
		.BYTE 0
_APU_TRI_COUNT:
		.BYTE 0
_APU_TRI_UNUSED:
		.BYTE 0
_APU_TRI_TIME:
		.BYTE 0
_APU_TRI_LEN:
		.BYTE 0
_APU_NOISE_ENV:
		.BYTE 0
_APU_NOISE_UNUSED:
		.BYTE 0
_APU_NOISE_LOOP:
		.BYTE 0
_APU_NOISE_LEN:
		.BYTE 0
_APU_DMC_FREQ:
		.BYTE 0
_APU_DMC_LOAD:
		.BYTE 0
_APU_DMC_ADDR:
		.BYTE 0
_APU_DMC_LEN:
		.BYTE 0
_PPU_OAM_DMA:
		.BYTE 0
_APU_STATUS:
		.BYTE 0
_PAD0_REG:
		.BYTE 0
_PAD1_REG:
		.BYTE 0
