/*
* File: VSREG_Det_Init_Secu_Fct_Sf.c
*
*                   Delphi Diesel Systems
*
*                   This document is the property of
*                   Delphi Diesel Systems
*                   It must not be copied (in whole or in part)
*                   or disclosed without prior written consent
*                   of the company. Any copies by any method
*                   must also include a copy of this legend.
*
* Real-Time Workshop code generated for Simulink model VSREG_Det_Init_Secu_Fct_Sf.
*
* Model version                        : 1.1
* Real-Time Workshop file version      : 7.0.1  (R2007b+)  21-Apr-2008
* Real-Time Workshop file generated on : Mon Jul 18 16:04:35 2011
* TLC version                          : 7.0 (Jul 26 2007)
* C source code generated on           : Mon Jul 18 16:04:36 2011
*
* Post treatment done by tool Aut_Autocode_Post.pl version 11.42
*        with rules Aut_Rules_For_Autocode_Post.pm version 10.00
*
* Code generated from spec : R6512345_10
*
* LABEL USED: LIBRARY_R6510684_14_0_1
*
* Options settings:
*        ALLOW_STANDARD_SIMULINK_BLOCK = 'DDS_FALSE'
*        DELETE_TEMPORARY_MODEL = 'DDS_TRUE'
*        GENERATE_A2L = 'DDS_FALSE'
*        MACRO_REVISION = 'DDS_TRUE'
*        NUMBER_OF_BITS_CHAR = 8
*        NUMBER_OF_BITS_SHORT =16
*        NUMBER_OF_BITS_INT =32
*        NUMBER_OF_BITS_LONG =32
*        NUMBER_OF_BITS_NATIVE_WORD_SIZE = 32
*        BYTE_ORDERING = 'BigEndian'
*        FIXED_POINT_ROUNDING_METHOD = 'Fix'
*        TIMER_1S='S_S_1S_U32_TIME'
*        TIMER_1MS='S_S_1MS_U32_TIME'
*        TIMER_100US='S_S_100US_U32_TIME'
*        TIMER_10US='S_S_10US_U32_TIME'
*        TIMER_1US='S_S_1US_U32_TIME'
*        ENABLE_POST_TASK = 'DDS_TRUE'
*        TASK_AND_DATA_CROSS_CHECK='DDS_TRUE'
*        DATA_NAMING_CONVENTION = 'DDS_TRUE'
*        ALLOW_NATIVE_SIMULINK_CONVERT_BLOCK = 'DDS_FALSE'
*        ENABLE_T55_CHECK = 'DDS_TRUE'
*        ENABLE_DDS_CAST = 'DDS_TRUE'
*        DDS_ADDITION = 'DDS_TRUE'
*        DDS_SUBSTRACTION = 'DDS_TRUE'
*        DDS_MULTIPLICATION = 'DDS_TRUE'
*        DDS_DIVIDE = 'DDS_TRUE'
*        DDS_CALC_VERBOSE_MODE='DDS_FALSE'
*        ENABLE_DDS_DIVIDE_ZPROT_PARAMETER = 'DDS_FALSE'
*        SITE_LOCATION='LIGHT_DUTY'
*        ARRAY_DECLARATION_METHOD = 'DDS_ARRAY_FORMAT'
*        ENABLE_SERVER_CAPABILITY = 'DDS_TRUE'
*        HOST_NAME ='DL6384B2J'
*        RETAIN_FILES_ON_SHARED_DIRECTORY='DDS_FALSE'
*        DRIVE_LETTER_USED_BY_SERVER = 'Z'
*        VIEW_USED_BY_SERVER='USER_VIEW'
*        VOB_NAME = 'blois_esys'
*        VIEW_SERVER_OPTION_IN_GUI='DDS_TRUE'
*        ALLOWED_INCLUDE_REGULAR='';
*        ENABLE_DD_IN_FILE = 'DDS_FALSE'
*        CALIBRATION_MNGT_MODE = 'INTO_C_FILE'
*        OUTPUT_RANGE_LIMITATION_MODE='INTO_SUB_SYSTEM'
*        UNIT_MEMORY_BLOCK_SELECTION_METHOD = 'DDS_BLOCK'
*        SWITCH_BLOCK_SELECTION_METHOD = 'SIMULINK_BLOCK'
*        SWITCH_OPTIMIZATION_ACTIVATED = 'DDS_FALSE'
*        CODE_FORMAT = 'DDS_SSTG'
*        ENABLE_EDITOR_CAPABILITY = 'DDS_TRUE'
*        EDITOR_PATH_1 ='C:\Program Files\TextPad 4\textpad.exe';
*        EDITOR_PATH_2 ='C:\Program Files\TextPad 5\textpad.exe';
*        EDITOR_PATH_3 ='C:\Program Files\Notepad++\notepad++.exe';
*        EDITOR_PATH_4 ='';
*        CALIBRATION_MNGT_MODE_WITH_CONSTANT = 'IN_EXTERNAL_FEATURE_FILE'
*        DATATYPE_MIN_SELECTION_NO_32BIT_OPT = 'NEG_DATATYPE_MAX'
*        DATATYPE_MIN_SELECTION_32BIT_OPT = 'NEG_DATATYPE_MAX'
*
* Libraries versions:
*        aut_ems_lib version 14.0
*
* Common dll version 3.0
*
* Blocks versions:
*        AUT_EC_Function_Stub_v1 SFunction version: 6.0, TLC version: 1.0
*        AUT_EC_m_min_opt SFunction version: 3.0, TLC version: 1.0
*
* Scripts versions:
*        aut_allow_standard_simulink_block.m version 1.0               aut_delete_temporary_model.m version 1.0
*        aut_generate_a2l_opt.m version 1.0                            aut_macro_revision_opt.m version 2.0
*        aut_processor_settings.m version 3.0                          aut_timers_opt.m version 1.0
*        aut_enable_post_task_opt.m version 1.0                        aut_checks_activation.m version 1.0
*        aut_enable_t55_check_opt.m version 1.0                        aut_enable_dds_cast_opt.m version 2.0
*        aut_enable_dds_calculation_opt.m version 2.0                  aut_site_location.m version 1.0
*        aut_array_declaration_method_opt.m version 1.0                aut_server_settings.m version 1.0
*        aut_include_authorisation.m version 1.0                       aut_import_dd_in_generated_file.m version 1.0
*        aut_calibration_mngt_mode.m version 1.0                       aut_manage_range_limitation_for_output.m version 1.0
*        aut_unit_memory_method_opt.m version 1.0                      aut_switch_block_method_opt.m version 1.0
*        aut_code_format_opt.m version 1.0                             aut_editor_settings.m version 1.0
*        aut_calibration_mngt_with_constant.m version 1.0              aut_datatype_min_selection_opt.m version 1.0
*        aut_ec_chronometer_v2_callback.m version 1.0                  aut_ec_cast_callback.m version 1.0
*        aut_ec_dds_cast_callback.m version 1.0                        aut_ec_val_at_first_call_v1_callback.m version 1.0
*        aut_ec_sp_aut_unit_delay_callback.m version 1.0               aut_ec_rs_flipflop_v1_callback.m version 1.0
*        aut_ec_unit_delay_n_block_v1_callback.m version 1.0           aut_ec_modulo_callback.m version 1.0
*        _aut_ec_template_callback.m version 1.0                       aut_ec_dds_add_callback.m version 1.0
*        aut_ec_dds_sub_callback.m version 1.0                         aut_ec_dds_product_callback.m version 1.0
*        aut_ec_dds_divide_callback.m version 1.0                      aut_ec_dds_divide_0_protect_callback.m version 1.0
*        aut_ec_sincos_rad_v1_callback.m version 1.0                   aut_ec_2_pow_n_v1_callback.m version 1.0
*        aut_ec_abs_callback.m version 1.0                             aut_ec_mut_dt_callback.m version 1.0
*        aut_ec_div_dt_callback.m version 1.0                          aut_ec_cnt_v1_callback.m version 1.0
*        aut_ec_timeout_rising_edge_v1_callback.m version 1.0          aut_ec_dt_block_v1_callback.m version 1.0
*        aut_ec_current_time_block_v1_callback.m version 1.0           aut_ec_chronometer_v1_callback.m version 1.0
*        aut_ec_turn_on_off_counts_v1_callback.m version 1.0           aut_ec_turn_on_off_delay_v1_callback.m version 1.0
*        aut_ec_switch_multi_v1_callback.m version 1.0                 aut_ec_soft_transition_n_frz_tcom_v2_callback.m version 1.0
*        aut_ec_soft_transition_n_rst_tcom_callback.m version 1.0      aut_ec_turn_on_delay_v1_callback.m version 1.0
*        aut_ec_turn_off_delay_v1_callback.m version 1.0               aut_ec_switch_backup_x_callback.m version 1.0
*        aut_ec_switch_enum_v1_callback.m version 1.0                  aut_ec_soft_transition_n_ttab_v2_callback.m version 1.0
*        aut_ec_enable_states_osc_v1_callback.m version 1.0            aut_ec_switch_slew_rate_v1_callback.m version 1.0
*        aut_ec_switch_slew_v1_callback.m version 1.0                  aut_ec_soft_transition_frz_v2_callback.m version 1.0
*        aut_ec_soft_transition_v2_callback.m version 1.0              aut_ec_dti_eci_v1_callback.m version 2.0
*        aut_ec_table_operator_v1_callback.m version 1.0               aut_ec_m_lib_map3d_scale_callback.m version 2.0
*        aut_ec_find_index_v1_callback.m version 1.0                   aut_ec_m_lib_apt3d_callback.m version 1.0
*        aut_ec_table1d_write_callback.m version 1.0                   aut_ec_table2d_write_callback.m version 1.0
*        aut_ec_table2d_read_callback.m version 1.0                    aut_ec_table1d_read_callback.m version 1.0
*        aut_ec_m_lib_apt3d_hyst.m version 1.0                         aut_ec_m_lib_apt2d_hyst_callback.m version 1.0
*        aut_ec_m_lib_apt2d_callback.m version 1.0                     aut_ec_m_lib_map2d_callback.m version 1.0
*        aut_ec_m_lib_map3d_callback.m version 1.0                     aut_ec_limit_to_range_callback.m version 1.0
*        aut_ec_hysteresis_v1_callback.m version 1.0                   aut_ec_limiter_and_detect_callback.m version 1.0
*        aut_ec_limiter_callback.m version 1.0                         aut_ec_compare_to_ones_complement_callback.m version 1.0
*        aut_ec_create_ones_complement_callback.m version 1.0          aut_ec_bitwise_not_callback.m version 1.0
*        aut_ec_bitwise_operator_callback.m version 1.0                aut_ec_adc_rd_v1_callback.m version 1.0
*        aut_ec_average_v1_callback.m version 1.0                      aut_ec_band_stop_filter_limit_v1_callback.m version 1.0
*        aut_ec_band_stop_filter_v1_callback.m version 1.0             aut_ec_debounce_v1_callback.m version 1.0
*        aut_ec_di_rd_v1_callback.m version 1.0                        aut_ec_do_wr_v1_callback.m version 1.0
*        aut_ec_dt_gain_v1_callback.m version 1.0                      aut_ec_dt_gain_v2_callback.m version 1.0
*        aut_ec_dt_gen_v1_callback.m version 1.0                       aut_ec_dt_gen_v2_callback.m version 1.0
*        aut_ec_dt_rate_gain_v1_callback.m version 1.0                 aut_ec_dt_rate_gain_v2_callback.m version 1.0
*        aut_ec_f_m_callback.m version 1.0                             aut_ec_f_m_obd_mode6_callback.m version 1.0
*        aut_ec_f_m_v1_callback.m version 1.0                          aut_ec_generic_sbpa_generator_callback.m version 1.0
*        aut_ec_grad_filter_t_v1_callback.m version 1.0                aut_ec_low_pass_filter_gen_v1_callback.m version 1.0
*        aut_ec_nvv_define_callback.m version 1.0                      aut_ec_nvv_write_callback.m version 1.0
*        aut_ec_osc_generator_v1_callback.m version 1.0                aut_ec_pfc_v1_callback.m version 1.0
*        aut_ec_pid_dterms_v1_callback.m version 1.0                   aut_ec_pid_v1_callback.m version 1.0
*        aut_ec_pulse_dt_block_v1_callback.m version 1.0               aut_ec_pwm_wr_v1_callback.m version 1.0
*        aut_ec_rst_v1_callback.m version 1.0                          aut_ec_slew_rate_v1_callback.m version 1.0
*        aut_ec_sp_cast_callback.m version 1.0                         aut_ec_sub_aut_cast_callback.m version 1.0
*        aut_ec_sub_const_cast_callback.m version 1.0                  aut_ec_sub_dds_cast_callback.m version 1.0
*        aut_ec_saturation_block_callback.m version 2.0                aut_ec_round_to_integer_callback.m version 1.0
*        aut_ec_cumulative_sum_v1_callback.m version 1.0               aut_ec_m_lib_map2d_high_res_callback.m version 1.0
*        aut_ec_m_lib_map3d_high_res_callback.m version 1.0            aut_ec_m_lib_map2d_scale_callback.m version 1.0
*        aut_ec_m_lib_map2d_high_res_scale_callback.m version 1.0      aut_ec_m_lib_map3d_high_res_scale_callback.m version 1.0
*        aut_ec_interp_v1_callback.m version 1.0                       aut_ec_history_table_shift_write_v1_callback.m version 1.0
*        aut_ec_history_table_rollover_write_v1_callback.m version 1.0 aut_ec_pid_boost_v1_callback.m version 1.0
*        aut_ec_table1d_rollover_read_callback.m version 1.0           aut_axis_check.m version 10.1
*        aut_fill_timer_input_fields.m version 26.0                    aut_get_abs_block_optimization.m version 4.0
*        aut_check_switch_multi_block.m version 2.5                    aut_check_limiter.m version 1.0
*        aut_set_param_with_retry.m version 1.0                        aut_check_port_signal_is_global.m version 1.0
*        aut_check_if_data_is_in_max_range.m version 3.0               aut_check_io_signal_is_defined_with_full_range.m version 2.0
*        aut_set_datatype_for_signal_spec_block.m version 1.0          aut_check_band_stop_filters.m version 5.0
*        aut_set_fault_management_block.m version 1.0                  aut_fill_map_apt_information.m version 3.0
*        aut_fill_soft_trans_fields.m version 5.0                      aut_set_cast_block.m version 4.0
*        aut_check_array_read.m version 5.0                            aut_set_calc_range_limitation.m version 12.0
*        aut_check_f_m_mode.m version 10.0                             aut_fill_lp1_fields.m version 7.0
*        aut_test_if_zdiv_test_is_requested.m version 17.0             aut_check_enum_linearity.m version 9.0
*        aut_fill_slwrate_fields.m version 21.0                        aut_fill_pid_fields.m version 10.0
*        aut_check_array_write.m version 18.1                          aut_get_map_high_res_info.m version 1.0
*        aut_check_history_table_x.m version 2.0                       aut_check_input_def_compatible_with_output_def.m version 1.0
*        aut_get_port_index_from_name.m version 1.0                    aut_tlc_check_branch_is_dead.m version 3.0
*        aut_tlc_check_if_min_range_start_to_0.m version 1.0           aut_tlc_check_io_data_string_is_numerical.m version 2.1
*        aut_tlc_check_positive_range.m version 1.0                    aut_tlc_check_snapshot_is_required.m version 1.0
*        aut_tlc_deter_if_min_range_should_be_tested.m version 3.0     aut_tlc_find_is_block_outport_dead.m version 4.1
*        aut_tlc_find_limit_selection.m version 3.0                    aut_tlc_format_array.m version 2.0
*        aut_tlc_get_array_write_index_value.m version 10.0            aut_tlc_get_block_init_string.m version 4.0
*        aut_tlc_get_feature_name.m version 4.0                        aut_tlc_get_final_size.m version 2.0
*        aut_tlc_get_max_size_x_for_2D_array.m version 1.0             aut_tlc_static_variable_name_calculation.m version 4.0
*        sim_cnt_v1_callback.m version 1.0                             sim_chronometer_v2_callback.m version 1.0
*        sim_cumulative_sum_v1_callback.m version 1.0                  sim_round_to_integer_callback.m version 1.0
*        sim_interp_v1_callback.m version 1.0                          sim_template_callback.m version 1.0
*        sim_sw_constant_v1_callback.m version 1.0                     sim_mul_percent_v1_callback.m version 1.0
*        sim_div_percent_v1_callback.m version 1.0                     sim_history_table_rollover_write_v1_callback.m version 1.0
*        sim_history_table_shift_write_v1_callback.m version 1.0       sim_rst_v1_callback.m version 1.0
*        sim_pid_dterms_v1_callback.m version 1.0                      sim_pid_v1_callback.m version 1.0
*        sim_pid_boost_v1_callback.m version 1.0                       sim_nvm_define_callback.m version 1.0
*        sim_nvm_write_callback.m version 1.0                          sim_extract_byte_callback.m version 1.0
*        sim_insert_data_in_buffer_v1_callback.m version 1.0           sim_can_frame_buffer_unpack_v1_callback.m version 1.0
*        sim_can_frame_buffer_pack_v1_callback.m version 1.0           sim_phys_to_bitfield_callback_v1.m version 1.0
*        sim_bitfield_to_phys_callback_v1.m version 1.0                sim_table1d_rollover_read_v1_callback.m version 1.0
*        sim_switch_block_mode.m version 2.0                           sim_set_sub_link_data.m version 3.0
*        sim_set_link_data.m version 1.0                               sim_manage_cast_visibility.m version 1.0
*        sim_view_fixed_point_setting.m version 2.0                    sim_prepare_limitation.m version 56.0
*        sim_set_cast_input.m version 30.0                             sim_cast_input_visibility.m version 16.0
*        sim_manage_block_tab.m version 3.0                            sim_manage_pwm_output_blk.m version 3.0
*        sim_check_find_index_block.m version 1.0                      sim_tag_update.m version 10.0
*        sim_check_no_limit_settings.m version 4.0                     sim_call_shared_files.m version 2.0
*        sim_get_tag_version.m version 17.0                            sim_manage_data_prop_for_calculation.m version 7.0
*        sim_set_cast_block.m version 6.0                              sim_set_snapshot.m version 8.0
*        sim_fill_map_apt_information.m version 8.0                    sim_set_calc_block.m version 12.0
*        sim_manage_calculation_block_mask_visibility.m version 3.0    sim_attributes_format_string.m version 2.0
*        sim_maskinitialization_common_function.m version 1.0          sim_get_doc_block_content_string.m version 2.0
*        sim_set_and_view_fixed_point_setting_for_xD_scale.m version 2.0aut_autocode_interface.m version 8.0
*        aut_mode_switch.m version 60.0                                aut_model_autocode.m version 21.0
*        aut_pre_autocode.m version 51.0                               aut_path.m version 5.0
*        aut_configuration_helper.m version 18.0                       aut_process_mngt.m version 51.0
*        aut_calc_block_before_limiter.m version 6.0                   aut_check_pointer_access.m version 2.0
*        aut_create_data.m version 21.91                               aut_create_enum.m version 8.0
*        aut_get_information_from_next_block.m version 14.0            aut_get_information_from_previous_block.m version 26.0
*        aut_manage_snapshot.m version 22.0                            aut_check_downcast.m version 2.0
*        aut_types.m version 1.0                                       aut_model_configure.m version 5.0
*        aut_signal_config.m version 10.0                              aut_get_squeduling_list.m version 14.0
*        aut_manage_autocode_model.m version 13.0                      aut_prepare_t55_task.m version 25.0
*        aut_get_static_data_list.m version 2.0                        aut_project_settings.m version 19.0
*        aut_get_updated_files_with_labels.m version 8.0               aut_manage_model_workspace.m version 1.0
*        aut_manage_simulink_to_post_task_exchange.m version 46.0      aut_cross_check_T55_mdl_init.m version 2.0
*        aut_manage_doc_block.m version 5.0                            aut_check_input_line_is_shared.m version 4.0
*        aut_check_calc_blocks.m version 39.0                          aut_get_field_info_from_previous_block.m version 2.0
*        aut_update_init_file_with_tag.m version 2.0                   aut_prepare_t55_task_for_tag.m version 7.0
*        aut_determine_is_io_signal_global.m version 1.0               aut_check_if_previous_block_equal_to_type.m version 2.0
*        aut_check_input_is_numerical.m version 5.0                    aut_step_ckecks.m version 2.0
*        aut_autocode_optimization.m version 5.0                       aut_check_if_dds_calc_is_activated.m version 1.0
*        aut_find_source_block_path.m version 4.0                      aut_pre_model_analysis.m version 2.0
*        aut_create_struture.m version 3.0                             aut_manage_limiter.m version 9.0
*        aut_check_init_between_blk_and_data.m version 13.0            aut_manage_server_demand.m version 4.0
*        aut_display_log_file_and_run_editor.m version 3.0             aut_get_enum_values.m version 1.0
*        aut_get_port_details.m version 2.0                            aut_get_unit_and_dec_point_from_def.m version 2.0
*        aut_format_cpv_initialization_line.m version 8.0              aut_check_if_data_exists_into_workps.m version 2.0
*        aut_unset_set_block_properties_of_subsytem.m version 6.0      aut_get_evaluated_value_from_constant.m version 2.0
*        aut_create_hyperlink_command_from_block.m version 1.0         aut_check_mng_range_for_create_vector_blk.m version 3.0
*        aut_cast_block_before_limiter.m version 2.0                   aut_get_data_list_from_link_output_block.m version 1.0
*        aut_get_deeper_block_from_list.m version 1.0                  aut_check_input_is_constant.m version 5.0
*        aut_check_if_input_range_is_controled.m version 1.0           aut_check_if_range_is_compatible_with_datatype.m version 3.0
*        aut_common_driver_blocks_checks.m version 2.0                 aut_check_calc_configuration_after_zdiv_block.m version 2.0
*        aut_init_value_check.m version 1.0                            aut_check_if_data_is_in_full_range.m version 1.0
*        aut_get_array_size_value_from_name.m version 4.0              aut_manage_range_limitation_with_mask.m version 3.0
*        aut_check_all_inputs_compatible_with_output.m version 7.0     aut_get_array_apv_according_calibration_mode.m version 3.0
*        aut_check_idx_type_name_with_datatype.m version 8.0           aut_check_if_parameter_present_into_model.m version 1.0
*        aut_create_sstg_architecture.m version 8.0                    aut_bug_finder.m version 3.0
*        aut_sstg_manage_signal_memory_location.m version 3.0          aut_check_blocks_fields_values.m version 1.0
*        aut_get_dd_from_spectool_model.m version 1.0                  aut_stateflow_checks.m version 5.0
*        aut_fixed_point_toolbox_interface.m version 2.0               aut_post_debug.m version 3.0
*        aut_switch_cpv_initialization.m version 9.0                   aut_create_intermediate_constants.m version 1.0
*        aut_check_accuracy_loss.m version 2.0                         aut_update_tag_if_necessary.m version 1.0
*        aut_format_apv_initialization_line.m version 1.0
*
* Post task version 11.42
*
* Config Spec:
*        element * CHECKEDOUT
*        element clearcase\... \main\LATEST
*        element livraison\... \main\LATEST
*        element tests\... \main\LATEST
*        element Appli\ /main/LATEST
*        element \DDS_E_Documents_Vob\...  /main/LATEST
*        element * LABEL_SSTG_AUTOCODING
*        element * LABEL_JONCHIERES_DEBUG_SSTG
*        element * LIBRARY_R6510684_14_0_1
*        element * ModelPrepare_V3_1_1
*        element * 00PSASWC_L105D01
*        element SC.h \main\branch_lemort_xvv_e6_integ\LATEST
*        element Appli\SC\ /main/LATEST
*        element SC\src\... /main/LATEST
*        element * LABEL_DEMEZIL_VSREG_VIEW
*        element * 00PSASWC_D301D01
*        element * 00PSAATS_B301D01
*        element \ldcr_tools \main\LATEST
*        element * INT2ULP_3_1_6
*        element * GEN_STR_32_VERSION_15_1
*        element \ldcr_tools\... DIAB_5610_2
*        element \ldcr_tools\... INTERNAL_FLASH_MAPPER_V07_40
*        element \ldcr_tools\... A2L_GNU_SH
*        element \ldcr_tools\... GNUSH_401
*        element \ldcr_tools\... GEN_RTE_VERSION_2_0_7
*        element \ldcr_tools\... SWC_CODE_CHECKER_EURO6_1_11
*        element  \ldcr_tools\... SWC_VALID_CHECK_SCENARIO_1_1
*        element  \ldcr_tools\... SWC_VALID_GEN_REPORT_1_3
*        element  \ldcr_tools\... SWC_PREPA_VALID_3_1_0_226
*        element \ldcr_tools\... SWC_SCENARIO_INIT_BYPASS_GENERATOR_1_00
*        element arxml_swc_generator\... ARXML_SWC_GENERATOR_1_02
*        element \ldcr_tools\... SWC_STIL_TO_IO_LIST_GENERATOR_EURO6_0_10
*        element \ldcr_tools\... SWC_STUB_GENERATOR_EURO6_1_00
*        element swc_stix_arxml_checker\... SWC_STIX_ARXML_CHECKER_1_32
*        element \ldcr_tools\... SWC_MAIN_CODE_GENERATOR_EURO6_1_00
*        element \ldcr_tools\... SWC_TASK_CODE_GENERATOR_EURO6_0_10
*        element asap2.pl \main\L01_01\8
*        element \ldcr_tools\... SWC_INCA_CSV_GENERATOR_0_20
*        element \ldcr_tools\... SWC_DELIVERY_CHECKER_EURO6_1_00
*        element \ldcr_tools\... SWC_LAB_GENERATOR_1_00
*        element \ldcr_tools\... SWC_AUTOCODING_GET_ENUM_LABEL_0_10
*        element \ldcr_tools\... SWC_AUTOCODING_PREPARE_0_10
*        element \ldcr_tools\... /main/LATEST
*        element -directory \blois_esoft\... \main\LATEST            # -directory pour ne voir le main\LATEST QUE sur le r�pertoires
*        element \blois_esoft\... \main\main_tcb\LATEST            # La branche de baseline de cette VOB est "main_tcb" pour �viter les label des Anglais.
*        element \blois_esoft\... \main\0 -mkbranch main_tcb      # Quand on fait un "add to source control" la branche "main_tcb" est automatiquement cr��e pour le nouveau fichier.
*        element \ldcr_doc\... /main/LATEST
*        element doc\... \main\LATEST
*        element Doc\... \main\LATEST
*
* Block list with autocode bypass option activated:
*        No bypassed blocks into this model
*
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Det_Init_Secu_Fct_Sf.c
* Version int :/main/L01_02/2 Date: 5/1/2012 11 h 24 m User:esnault 
*    TWK_model:VSREG_Det_Init_Secu_Fct_Sf_L01_020_IMPL1_D
*    comments :For VSReg_12_0_e6
* Version dev :\main\branch_halouane_vsreg_euro6\1 Date: 4/1/2012 15 h 37 m User:halouane 
*    TWK_model:VSREG_Det_Init_Secu_Fct_Sf_L01_020_IMPL1_D
*    comments :For VSReg_12_0_e6
* Version int :/main/L01_02/1 Date: 25/8/2011 10 h 46 m User:meme
*    TWK_model:VSREG_Det_Init_Secu_Fct_Sf_L01_020_IMPL1
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 9/8/2011 10 h 37 m User:demezil
*    TWK_model:VSREG_Det_Init_Secu_Fct_Sf_L01_020_IMPL1
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 18/7/2011 16 h 40 m User:demezil
*    TWK_model:VSREG_Det_Init_Secu_Fct_Sf_L01_010_IMPL1_D
*    comments :for VSReg 11.0
*/

/* START OF SSTG FUNCTION INTERFACE AREA */

/* TAG_START_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction ;ECU_bAuthVSCtlIni;Ext_stDVSRegCf;VSCtl_stVSCtlInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction ;VSCtl_bCfVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Condition_Configuration_Fonction */

/* TAG_START_OF_STATEFLOW_FUNCTION: Etat_Service_RVV */
/* TAG_INPUT_OF_STATEFLOW_FUNCTION: Etat_Service_RVV ;ECU_bAuthVSCtlIni;Ext_bKeyOff;Ext_stAcvRegVSCtlReq;Ext_stDVSRegCf;Ext_stModRegVSCtlReq;FRM_bDeacIrvVSReg;FRM_bDeacRvVSReg;SftyMgt_bDeacIrvVSReg;VSCtl_stVSCtlInfo; */
/* TAG_OUTPUT_OF_STATEFLOW_FUNCTION: Etat_Service_RVV ;VSCtl_bDgoVSReg;VSCtl_bMonRunVSReg;VSCtl_bctDefRevVSReg;VSCtl_ctDftRevVSReg;VSCtl_stMonVSReg;VSCtl_tiFilDftRvVSReg;VSCtl_tiFilIniVSReg; */
/* TAG_END_OF_STATEFLOW_FUNCTION: Etat_Service_RVV */

/* TAG_START_OF_SUB_FUNCTION: F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite */
/* TAG_INPUT_OF_SUB_FUNCTION: F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite ;Ext_bKeyOff;FRM_bDeacIrvVSReg;FRM_bDeacRvVSReg;SftyMgt_bDeacIrvVSReg;VSCtl_bCfVSReg;VSCtl_bctDefRevVSReg; */
/* TAG_OUTPUT_OF_SUB_FUNCTION: F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite ;VSCtl_stDeacVSRegReq_Ini; */
/* TAG_END_OF_SUB_FUNCTION: F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite */

/* END OF SSTG FUNCTION INTERFACE AREA */

/* <AUT_POST> : Task Include managment */
/********************************************************************/
/*  Include Files                                                   */
/********************************************************************/
#include "dds_lib.h"
#include "VSReg.h"
/* \<AUT_POST> : Task Include managment */

/********************************************************************/
/*  Task Macro Definitions                                          */
/********************************************************************/
#define EXT_STDVSREGCF_RVV_PRESENT              (1)
#define EXT_STACVREGVSCTLREQ_REGUL_RVV_DEMANDEE (1)
#define EXT_STMODREGVSCTLREQ_RVV_SELECT         (1)

/* VSCtl_stVSCtlInfo */
#define VSCTL_STVSCTLINFO_ARRET                 (0)
#define VSCTL_STVSCTLINFO_VERIF                 (1)
#define VSCTL_STVSCTLINFO_INIT                  (2)
#define VSCTL_STVSCTLINFO_NOMINAL               (3)
#define VSCTL_STVSCTLINFO_DEFAUT                (4)

/* Named constants for block: /Etat_Service_RVV' */
#define VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD (0)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_ETAT_SERVICE_RVV (1)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_ARRET (1)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_IRREVESIBLE (2)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_MARCHE (3)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_VERIF (2)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_NON_VERIF (1)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_PAS_DEFAUT (2)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_INIT (1)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_REVESIBLE (1)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_NOMINAL (2)
#define VSREG_Det_Init_Secu_Fct_Sf_VRAI_e (1U)
#define VSREG_Det_Init_Secu_Fct_Sf_FAUX_h (0U)

/* Named constants for block: /Condition_Configuration_Fonction' */
#define VSREG_Det_Init_Secu_Fct_Sf_IN_FAUX (1)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_VRAI (2)
#define VSREG_Det_Init_Secu_Fct_Sf_IN_CONDITION_CONFIGURATION_FONCTION (1)
#define VSREG_Det_Init_Secu_Fct_Sf_VRAI (1U)
#define VSREG_Det_Init_Secu_Fct_Sf_FAUX (0U)


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Application Level variables: Inputs from the Application        */
/********************************************************************/

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Feature Level variables: Outputs to the Application             */
/********************************************************************/

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bctDefRevVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bCfVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



/********************************************************************/
/*  Task Level Type Definitions                                     */
/********************************************************************/

/* <AUT_POST> : Struct and enum import */

typedef struct {
  UInt32 is_ETAT_SERVICE_RVV : 2;      /* /Etat_Service_RVV' */
  UInt32 is_MARCHE : 2;                /* /Etat_Service_RVV' */
  UInt32 is_NON_VERIF : 2;             /* /Etat_Service_RVV' */
  UInt32 is_PAS_DEFAUT : 2;            /* /Etat_Service_RVV' */
  UInt32 is_CONDITION_CONFIGURATION_FONCTION : 2;/* /Condition_Configuration_Fonction' */
  UInt32 is_active_c33_VSREG_Det_Init_Secu_Fct_Sf : 1;/* /Etat_Service_RVV' */
  UInt32 is_c33_VSREG_Det_Init_Secu_Fct_Sf : 1;/* /Etat_Service_RVV' */
  UInt32 is_active_c32_VSREG_Det_Init_Secu_Fct_Sf : 1;/* /Condition_Configuration_Fonction' */
  UInt32 is_c32_VSREG_Det_Init_Secu_Fct_Sf : 1;/* /Condition_Configuration_Fonction' */
} D_Work_VSREG_Det_Init_Secu_Fct_Sf;

/* \<AUT_POST> : Struct and enum import */

/********************************************************************/
/*  File Scope Displayable Variable Definitions                     */
/********************************************************************/

/* Static Visible area start */

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_ctDftRevVSReg;                     /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilDftRvVSReg;                   /*BIN0*/
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilIniVSReg;                     /*BIN0*/
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/* Static Visible area end */

/********************************************************************/
/*  File Scope Non-displayable Variable Definitions                    */
/********************************************************************/

/* Static Not Visible area start */

/* 8BIT-bits variable definition */
#define VSREG_START_SEC_VAR_8BIT
#include "VSReg_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bdgovsreg_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsreg_vsctl_bmonrunvsreg_cpy;
#define VSREG_STOP_SEC_VAR_8BIT
#include "VSReg_MemMap.h"


/* UNSPECIFIED-bits variable definition */
#define VSREG_START_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"
STATIC VAR(D_Work_VSREG_Det_Init_Secu_Fct_Sf, AUTOMATIC) vsreg_det_init_secu_fct_sf_dwork;
/* Static Not Visible area end */
#define VSREG_STOP_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"

/* \<AUT_POST> : Task Memory Ordering */


/* <AUT_POST> : Task Memory Ordering */
/********************************************************************/
/*  Task Scope Constant Definitions                                 */
/********************************************************************/

/* 8BIT-bits variable definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_ctTolRvDftVSReg_C = (CONST(UInt8, AUTOMATIC))( 255U);      /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDftRvVSReg_C = (CONST(UInt8, AUTOMATIC))( 49U);          /*BIN0*/
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiIni_VSReg_C = (CONST(UInt8, AUTOMATIC))( 2U);            /*BIN0*/
/* \<AUT_POST> : Task Memory Ordering */
#define VSREG_STOP_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"

/* <AUT_PRE> DECLARATIONS */
/* \<AUT_PRE> DECLARATIONS */
/* <AUT_PRE> FUNCTIONS */

/* Model step function */

/* <AUT_POST> : Task static function */
/********************************************************************/
/*  Task Local Function Prototypes                                  */
/********************************************************************/
/* NONE */
/* \<AUT_POST> : Task static function */

/********************************************************************/
/*  Local Task Function Definition                                  */
/********************************************************************/
/* NONE */

/********************************************************************/
/*  Main Task Function Definition                                   */
/********************************************************************/

#define VSREG_START_SEC_CODE
#include "VSReg_MemMap.h"

FUNC(void, AUTOMATIC) VSREG_Det_Init_Secu_Fct_Sf(UInt8 Ext_stModRegVSCtlReq_swc_in,
                               UInt8 FRM_bDeacRvVSReg_swc_in,
                               UInt8 VSCtl_stVSCtlInfo_swc_in,
                               UInt8 FRM_bDeacIrvVSReg_swc_in,
                               UInt8 Ext_stDVSRegCf_swc_in,
                               UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                               UInt8 SftyMgt_bDeacIrvVSReg_swc_in,
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt8 Ext_bKeyOff_swc_in,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSReg_swc_out)

{

  /* TAG_START_OF_MAIN_FUNCTION */


  /* TAG_START_OF_STATEFLOW_FUNCTION: F2112_Determiner_Etat_Service*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.76.1  */

  if (vsreg_det_init_secu_fct_sf_dwork.is_active_c33_VSREG_Det_Init_Secu_Fct_Sf ==
      0)
  {
    vsreg_det_init_secu_fct_sf_dwork.is_active_c33_VSREG_Det_Init_Secu_Fct_Sf =
      1U;
    vsreg_det_init_secu_fct_sf_dwork.is_c33_VSREG_Det_Init_Secu_Fct_Sf =
      (UInt8)VSREG_Det_Init_Secu_Fct_Sf_IN_ETAT_SERVICE_RVV;
    vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
      VSREG_Det_Init_Secu_Fct_Sf_IN_ARRET;
    VSCtl_stMonVSReg = VSCTL_STMONVSREG_ARRET;
    VSCtl_ctDftRevVSReg = VSCtl_ctTolRvDftVSReg_C;
    VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C;
    VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;
    vsreg_vsctl_bdgovsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
    vsreg_vsctl_bmonrunvsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
    VSCtl_bctDefRevVSReg = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;

  }
  else
  {
    switch (vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV) {
     case VSREG_Det_Init_Secu_Fct_Sf_IN_ARRET:
      if (((((Ext_stDVSRegCf_swc_in == EXT_STDVSREGCF_RVV_PRESENT)
      && (Ext_bKeyOff_swc_in ==
              VSREG_Det_Init_Secu_Fct_Sf_FAUX_h))
              && (VSCtl_stVSCtlInfo_swc_in !=
             VSCTL_STVSCTLINFO_VERIF)) && (VSCtl_stVSCtlInfo_swc_in !=
            VSCTL_STVSCTLINFO_INIT)) && (VSCtl_stVSCtlInfo_swc_in !=
           VSCTL_STVSCTLINFO_ARRET))
      {
        vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_MARCHE;
        vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_VERIF;
        VSCtl_stMonVSReg = VSCTL_STMONVSREG_VERIF;
        vsreg_vsctl_bmonrunvsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_VRAI_e;
      }
      break;

     case VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_IRREVESIBLE:
      if ((Ext_stDVSRegCf_swc_in != EXT_STDVSREGCF_RVV_PRESENT)
      || (Ext_bKeyOff_swc_in ==
           VSREG_Det_Init_Secu_Fct_Sf_VRAI_e))
      {
        vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_ARRET;
        VSCtl_stMonVSReg = VSCTL_STMONVSREG_ARRET;
        VSCtl_ctDftRevVSReg = VSCtl_ctTolRvDftVSReg_C;
        VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C;
        VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;
        vsreg_vsctl_bdgovsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
        vsreg_vsctl_bmonrunvsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
        VSCtl_bctDefRevVSReg = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
      }
      break;

     case VSREG_Det_Init_Secu_Fct_Sf_IN_MARCHE:
      if (((((Ext_stDVSRegCf_swc_in != EXT_STDVSREGCF_RVV_PRESENT)
      || (Ext_bKeyOff_swc_in ==
              VSREG_Det_Init_Secu_Fct_Sf_VRAI_e))
              || (VSCtl_stVSCtlInfo_swc_in ==
             VSCTL_STVSCTLINFO_VERIF)) || (VSCtl_stVSCtlInfo_swc_in ==
            VSCTL_STVSCTLINFO_INIT)) || (VSCtl_stVSCtlInfo_swc_in ==
           VSCTL_STVSCTLINFO_ARRET))
      {
        vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
        vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
          VSREG_Det_Init_Secu_Fct_Sf_IN_ARRET;
        VSCtl_stMonVSReg = VSCTL_STMONVSREG_ARRET;
        VSCtl_ctDftRevVSReg = VSCtl_ctTolRvDftVSReg_C;
        VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C;
        VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;
        vsreg_vsctl_bdgovsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
        vsreg_vsctl_bmonrunvsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
        VSCtl_bctDefRevVSReg = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;

      }
      else
      {
        switch (vsreg_det_init_secu_fct_sf_dwork.is_MARCHE)
      {
         case VSREG_Det_Init_Secu_Fct_Sf_IN_NON_VERIF:
          if ((FRM_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
          ||
              (SftyMgt_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e))
          {
            vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_IRREVESIBLE;
            VSCtl_stMonVSReg = VSCTL_STMONVSREG_DEFAUT_IRREV;

          }
          else
          {
            switch (vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF)
      {
             case VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_REVESIBLE:
              if (VSCtl_ctDftRevVSReg == 0)
              {
                vsreg_vsctl_bdgovsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_VRAI_e;
                VSCtl_bctDefRevVSReg = VSREG_Det_Init_Secu_Fct_Sf_VRAI_e;
                vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
                vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
                vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_IRREVESIBLE;
                VSCtl_stMonVSReg = VSCTL_STMONVSREG_DEFAUT_IRREV;

              }
              else if ((((((Ext_stAcvRegVSCtlReq_swc_in !=
                              EXT_STACVREGVSCTLREQ_REGUL_RVV_DEMANDEE)
                              &&
                             (Ext_stModRegVSCtlReq_swc_in !=
                              EXT_STMODREGVSCTLREQ_RVV_SELECT)) &&
                            (FRM_bDeacRvVSReg_swc_in ==
                             VSREG_Det_Init_Secu_Fct_Sf_FAUX_h)) &&
                           (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL))
                           &&
                          (VSCtl_ctDftRevVSReg != 0))
                          && (VSCtl_tiFilDftRvVSReg ==
                          0))
              {
                vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_PAS_DEFAUT;
                vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_INIT;
                VSCtl_stMonVSReg = VSCTL_STMONVSREG_INIT;
                VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;

              }
              else
              {
                VSCtl_tiFilDftRvVSReg = (UInt8)DDS_M_MAX(VSCtl_tiFilDftRvVSReg -
                  1, 0);
              }
              break;

             case VSREG_Det_Init_Secu_Fct_Sf_IN_PAS_DEFAUT:
              if ((FRM_bDeacRvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
              ||
                  (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_DEFAUT))
              {
                vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
                vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
                  VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_REVESIBLE;
                VSCtl_stMonVSReg = VSCTL_STMONVSREG_DEFAUT_REV;
                VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C;
                VSCtl_ctDftRevVSReg = (UInt8)(VSCtl_ctDftRevVSReg - 1);

              }
              else
              {
                switch (vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT)
      {
                 case VSREG_Det_Init_Secu_Fct_Sf_IN_INIT:
                  if (VSCtl_tiFilIniVSReg == 0)
                  {
                    vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = (UInt8)
                      VSREG_Det_Init_Secu_Fct_Sf_IN_NOMINAL;
                    VSCtl_stMonVSReg = VSCTL_STMONVSREG_NOMINAL;

                  }
                  else
                  {
                    VSCtl_tiFilIniVSReg = (UInt8)DDS_M_MAX(VSCtl_tiFilIniVSReg -
                      1, 0);
                  }
                  break;
                }
              }
              break;
            }
          }
          break;

         case VSREG_Det_Init_Secu_Fct_Sf_IN_VERIF:
          if ((ECU_bAuthVSCtlIni_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
          &&
              ((FRM_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
              ||
               (SftyMgt_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)))
          {
            vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_NO_ACTIVE_CHILD;
            vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_IRREVESIBLE;
            VSCtl_stMonVSReg = VSCTL_STMONVSREG_DEFAUT_IRREV;

          }
          else if ((((ECU_bAuthVSCtlIni_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
          &&
                       ((FRM_bDeacRvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
                       ||
                        (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_DEFAUT)))
                        &&
                      (FRM_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_FAUX_h))
                      &&
                     (SftyMgt_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_FAUX_h))
          {
            vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_NON_VERIF;
            vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_DEFAUT_REVESIBLE;
            VSCtl_stMonVSReg = VSCTL_STMONVSREG_DEFAUT_REV;
            VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C;
            VSCtl_ctDftRevVSReg = (UInt8)(VSCtl_ctDftRevVSReg - 1);

          }
          else if ((((ECU_bAuthVSCtlIni_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI_e)
          &&
                       (FRM_bDeacRvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_FAUX_h))
                       &&
                      (FRM_bDeacIrvVSReg_swc_in == VSREG_Det_Init_Secu_Fct_Sf_FAUX_h))
                      &&
                     (VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL))
          {
            vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_NON_VERIF;
            vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_PAS_DEFAUT;
            vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = (UInt8)
              VSREG_Det_Init_Secu_Fct_Sf_IN_INIT;
            VSCtl_stMonVSReg = VSCTL_STMONVSREG_INIT;
            VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;
          }
          break;
        }
      }
      break;

     default:
      vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = (UInt8)
        VSREG_Det_Init_Secu_Fct_Sf_IN_ARRET;
      VSCtl_stMonVSReg = VSCTL_STMONVSREG_ARRET;
      VSCtl_ctDftRevVSReg = VSCtl_ctTolRvDftVSReg_C;
      VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C;
      VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;
      vsreg_vsctl_bdgovsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
      vsreg_vsctl_bmonrunvsreg_cpy = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
      VSCtl_bctDefRevVSReg = VSREG_Det_Init_Secu_Fct_Sf_FAUX_h;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2112_Determiner_Etat_Service*/



  /* TAG_START_OF_STATEFLOW_FUNCTION: F2111_Determiner_Condition_Configuration_Fonction*/
	/* SSTG_REQ_TAG: CSMT_CGMT08_2269.FR.75.0  */

  if (vsreg_det_init_secu_fct_sf_dwork.is_active_c32_VSREG_Det_Init_Secu_Fct_Sf ==
      0)
  {
    vsreg_det_init_secu_fct_sf_dwork.is_active_c32_VSREG_Det_Init_Secu_Fct_Sf =
      1U;
    vsreg_det_init_secu_fct_sf_dwork.is_c32_VSREG_Det_Init_Secu_Fct_Sf =
      (UInt8)VSREG_Det_Init_Secu_Fct_Sf_IN_CONDITION_CONFIGURATION_FONCTION;
    vsreg_det_init_secu_fct_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION =
      (UInt8)VSREG_Det_Init_Secu_Fct_Sf_IN_VRAI;
    VSCtl_bCfVSReg = VSREG_Det_Init_Secu_Fct_Sf_VRAI;

  }
  else
  {
    switch (vsreg_det_init_secu_fct_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION)
    {
     case VSREG_Det_Init_Secu_Fct_Sf_IN_FAUX:
      if ((VSCtl_stVSCtlInfo_swc_in != VSCTL_STVSCTLINFO_NOMINAL)
      || (Ext_stDVSRegCf_swc_in !=
           EXT_STDVSREGCF_RVV_PRESENT))
      {
        vsreg_det_init_secu_fct_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION =
          (UInt8)VSREG_Det_Init_Secu_Fct_Sf_IN_VRAI;
        VSCtl_bCfVSReg = VSREG_Det_Init_Secu_Fct_Sf_VRAI;
      }
      break;

     case VSREG_Det_Init_Secu_Fct_Sf_IN_VRAI:
      if (((VSCtl_stVSCtlInfo_swc_in == VSCTL_STVSCTLINFO_NOMINAL) &&
           (ECU_bAuthVSCtlIni_swc_in == VSREG_Det_Init_Secu_Fct_Sf_VRAI)) &&
          (Ext_stDVSRegCf_swc_in == EXT_STDVSREGCF_RVV_PRESENT))
      {
        vsreg_det_init_secu_fct_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION =
          (UInt8)VSREG_Det_Init_Secu_Fct_Sf_IN_FAUX;
        VSCtl_bCfVSReg = VSREG_Det_Init_Secu_Fct_Sf_FAUX;
      }
      break;

     default:
      vsreg_det_init_secu_fct_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION =
        (UInt8)VSREG_Det_Init_Secu_Fct_Sf_IN_VRAI;
      VSCtl_bCfVSReg = VSREG_Det_Init_Secu_Fct_Sf_VRAI;
      break;
    }
  }

  /* TAG_END_OF_STATEFLOW_FUNCTION: F2111_Determiner_Condition_Configuration_Fonction*/

  VSREG_F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite(
                                             Ext_bKeyOff_swc_in,
                                             FRM_bDeacIrvVSReg_swc_in,
                                             FRM_bDeacRvVSReg_swc_in,
                                             SftyMgt_bDeacIrvVSReg_swc_in);

  /* TAG_END_OF_MAIN_FUNCTION */
  *VSCtl_bDgoVSReg_swc_out = vsreg_vsctl_bdgovsreg_cpy;

  *VSCtl_bMonRunVSReg_swc_out = vsreg_vsctl_bmonrunvsreg_cpy;

}

/* Model initialize function */
/********************************************************************/
/*  Task Initialisation Function Definition                         */
/********************************************************************/
FUNC(void, AUTOMATIC) VSREG_Det_Init_Secu_Fct_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSReg_swc_out)

{
    VSREG_Gmp_Cond_Calc_Sl_Init();

  /* <AUT_POST>  : Task Initialization of DDS_FALSE Value */
  /* \<AUT_POST> : Task Initialization of DDS_FALSE Value */
  /* Registration code */

  /* block I/O */

  /* custom signals */
  VSCtl_stMonVSReg = VSCTL_STMONVSREG_ARRET;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiFilDftRvVSReg = VSCtl_tiDftRvVSReg_C; /* Replaced by Post task */     /* Init from Model */
  VSCtl_ctDftRevVSReg = VSCtl_ctTolRvDftVSReg_C;    /* Replaced by Post task */     /* Init from Model */
  VSCtl_tiFilIniVSReg = VSCtl_tiIni_VSReg_C;    /* Replaced by Post task */     /* Init from Model */

  /* InitializeConditions for atomic SubSystem: /F2112_Determiner_Etat_Service' */

  /* Initialize code for chart: /Etat_Service_RVV' */
  vsreg_det_init_secu_fct_sf_dwork.is_ETAT_SERVICE_RVV = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_MARCHE = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_NON_VERIF = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_PAS_DEFAUT = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_active_c33_VSREG_Det_Init_Secu_Fct_Sf = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_c33_VSREG_Det_Init_Secu_Fct_Sf = 0U;
  *VSCtl_bDgoVSReg_swc_out =DDS_FALSE;
  vsreg_vsctl_bdgovsreg_cpy = *VSCtl_bDgoVSReg_swc_out;

  VSCtl_bctDefRevVSReg =DDS_FALSE;
  *VSCtl_bMonRunVSReg_swc_out =DDS_FALSE;
  vsreg_vsctl_bmonrunvsreg_cpy = *VSCtl_bMonRunVSReg_swc_out;


  /* end of InitializeConditions for SubSystem: /F2112_Determiner_Etat_Service' */

  /* InitializeConditions for atomic SubSystem: /F2111_Determiner_Condition_Configuration_Fonction' */

  /* Initialize code for chart: /Condition_Configuration_Fonction' */
  vsreg_det_init_secu_fct_sf_dwork.is_CONDITION_CONFIGURATION_FONCTION = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_active_c32_VSREG_Det_Init_Secu_Fct_Sf = 0U;
  vsreg_det_init_secu_fct_sf_dwork.is_c32_VSREG_Det_Init_Secu_Fct_Sf = 0U;
  VSCtl_bCfVSReg =DDS_FALSE;

  /* end of InitializeConditions for SubSystem: /F2111_Determiner_Condition_Configuration_Fonction' */
}

/* \<AUT_PRE> FUNCTIONS */

#define VSREG_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSReg_MemMap.h"

