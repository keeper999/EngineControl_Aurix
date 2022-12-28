/*******************************************************************************
*                    Delphi Diesel Systems
*
*                    This document is the property of
*                    Delphi Diesel Systems
*                    It must not be copied (in whole or in part)
*                    or disclosed without prior written consent
*                    of the company. Any copies by any method
*                    must also include a copy of this legend.
********************************************************************************
* Task File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*------------------------------------------------------------------------------*
*
* Ref X:\integration_view_00PSASWC_L10DD11\blois_psa_sstg\Software\Appli\dds_lib\src\dds_lib.c
* Version int :/main/L02_01/16 Date: 16/5/2014 8 h 58 m User:posmyk 
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :Update memory section.
* Version dev :\main\branch_girodon_module_dev\4 Date: 15/5/2014 16 h 12 m User:girodon 
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :Update memory section.
* Version int :/main/L02_01/15 Date: 26/2/2014 14 h 41 m User:groult
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :proto PFlt 20.0 euro6.2
* Version dev :\main\branch_lemort_module_dev\1 Date: 13/2/2014 15 h 18 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :proto PFlt 20.0 euro6.2
* Version int :/main/L02_01/14 Date: 22/10/2012 9 h 45 m User:posmyk
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_TAB2D_NEAREST_SU16
* Version dev :\main\branch_halouane_fab_dev\7 Date: 22/10/2012 9 h 13 m User:halouane
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_TAB2D_NEAREST_SU16
* Version int :/main/L02_01/13 Date: 16/10/2012 11 h 34 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_SOFT_TRANS_S32_DELTA. Add DDS_M_TAB2D_NEAREST_S16. Add DDS_M_TAB2D_NEAREST_US16
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 15/10/2012 16 h 39 m User:morisseau
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_SOFT_TRANS_S32_DELTA
*    comments :Add DDS_M_TAB2D_NEAREST_S16
*    comments :Add DDS_M_TAB2D_NEAREST_US16
* Version int :/main/L02_01/12 Date: 28/10/2011 9 h 55 m User:esnault
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add new MAP types S16U8S16 / S16U8U16
* Version dev :\main\branch_veillard_pflt\10 Date: 24/10/2011 13 h 56 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add new MAP types
* Version dev :\main\branch_veillard_pflt\9 Date: 24/10/2011 13 h 54 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add new MAP type S16U8S16 / S16U8U16
* Version int :/main/L02_01/11 Date: 19/10/2011 15 h 8 m User:esnault
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :By default, dynamic multiplication is based on 32bits (use of 64bits does not optimized
*    comments :CPU load on every integrators)
* Version dev :\main\branch_moisan_module_reception\2 Date: 19/10/2011 14 h 53 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :By default, dynamic multiplication is based on 32bits (use of 64bits does not optimized
*    comments :CPU load on every integrators)
* Version int :/main/L02_01/10 Date: 6/10/2011 9 h 6 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Implement dynamique multiplication on 64bits
* Version dev :\main\branch_moisan_module_dev\1 Date: 5/10/2011 10 h 40 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Implement dynamique multiplication on 64bits
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 4/10/2011 15 h 30 m User:morisseau
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :correct LIB_TAB_SEARCH_IND_Y_NEAREST
* Version dev :\main\branch_girodon_module_dev\1 Date: 27/9/2011 17 h 0 m User:girodon
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add function DDS_M_FILTER_LP1_U16_V2, DDS_M_FILTER_LP1_U16_V2_INIT,  DDS_M_FILTER_LP1_S16_V2

*    comments : and DDS_M_FILTER_LP1_S16_V2_INIT.
*    comments :Update interpolation functions to remove QAC warning and reduce CPU load.
* Version dev :\main\branch_veillard_pflt\8 Date: 23/9/2011 11 h 27 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\7 Date: 23/9/2011 11 h 23 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\4 Date: 23/9/2011 10 h 29 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\3 Date: 22/9/2011 13 h 42 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\2 Date: 21/9/2011 10 h 1 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\1 Date: 14/9/2011 10 h 49 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
* Version int :/main/L02_01/9 Date: 26/8/2011 14 h 56 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :V370: correct implementation of macro DDS_M_ADAP_TRAN_TEMP_BLOC_S32
* Version dev :\main\branch_moisan_module_dev\1 Date: 26/8/2011 11 h 10 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :V370: correct implementation of macro DDS_M_ADAP_TRAN_TEMP_BLOC_S32
* Version int :/main/L02_01/8 Date: 10/8/2011 11 h 18 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :correct version
* Version dev :\main\branch_lemort_boucle_air_dev\4 Date: 10/8/2011 9 h 51 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :correct version
* Version dev :\main\branch_lemort_boucle_air_dev\3 Date: 10/8/2011 9 h 49 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :correct version
* Version dev :\main\branch_lemort_boucle_air_dev\2 Date: 10/8/2011 9 h 45 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :qac warning corrections
* Version dev :\main\branch_lemort_boucle_air_dev\1 Date: 10/8/2011 9 h 18 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :add DDS_M_LIMITED_DECREMENT_S32. DDS_M_LIMITED_DECREMENT_U32. DDS_M_LIMITED_INCREMENT_S32.
*    comments :DDS_M_LIMITED_INCREMENT_U32
* Version int :/main/L02_01/7 Date: 18/7/2011 14 h 25 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U16U8U8  and  DDS_M_MAP3D_U16U8S8
* Version dev :\main\branch_moisan_tmp\2 Date: 18/7/2011 10 h 29 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U16U8U8  and  DDS_M_MAP3D_U16U8S8
* Version int :/main/L02_01/6 Date: 23/6/2011 14 h 50 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Correct mistakes found on DDS_M_VARIABLE_TRANSPORT_DELAY_FAP: input and output resolution
*    comments :have been changed from BIN17 to BIN7
* Version dev :\main\branch_moisan_tmp\2 Date: 17/6/2011 9 h 38 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Correct mistakes found on DDS_M_VARIABLE_TRANSPORT_DELAY_FAP: input and output resolution
*    comments :have been changed from BIN17 to BIN7
* Version int :/main/L02_01/5 Date: 11/5/2011 11 h 18 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :add DDS_M_BARY_FILTER_S16_V2 and DDS_M_BARY_FILTER_S32_V2
* Version dev :\main\branch_lemort_pflt_dev\1 Date: 10/5/2011 17 h 7 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :add DDS_M_BARY_FILTER_S16_V2 and DDS_M_BARY_FILTER_S32_V2
* Version int :/main/L02_01/4 Date: 11/4/2011 9 h 50 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :update version but no modifications in code
* Version dev :\main\branch_demezil_dvsreg\3 Date: 11/4/2011 9 h 0 m User:demezil
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :update version but no modifications in code
* Version int :/main/L02_01/3 Date: 7/4/2011 14 h 43 m User:esnault
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :for V310
* Version dev :\main\branch_demezil_dvsreg\2 Date: 7/4/2011 14 h 19 m User:demezil
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :for V310
* Version dev :\main\branch_demezil_dvsreg\1 Date: 7/4/2011 12 h 5 m User:demezil
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :DDS_M_NEGATIVE_EDGE_DETECT and DDS_M_POSITIVE_EDGE_DETECT
* Version int :/main/L02_01/2 Date: 30/3/2011 17 h 6 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Guarantee retrocompatibility with previous DDS_M_TAB2D_U16 (V1)
* Version dev :\main\branch_moisan_afad_dev\1 Date: 30/3/2011 12 h 0 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Guarantee retrocompatibility with previous DDS_M_TAB2D_U16 (V1)
* Version int :/main/L02_01/1 Date: 28/3/2011 14 h 55 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :V_300:. Add DDS_M_TAB2D_NEAREST_U16, DDS_M_TAB3D_NEAREST_U16 ,DDS_M_TAB3D_NEAREST_USU16,
*    comments :DDS_M_MAP2D_S16S8, DDS_M_TAB2D_NEAREST_U8 (Use Input Nearest), . DDS_M_TAB3D_SSU16,
*    comments :DDS_M_TAB2D_U8, DDS_M_TAB2D_U16, DDS_M_POSITIVE_EDGE_DETECT, DDS_M_NEGATIVE_EDGE_DETECT
*    comments :and DDS_M_MAP3D_U16S16S8
* Version dev :\main\branch_moisan_afad_dev\8 Date: 28/3/2011 14 h 20 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :V_300:
*    comments :Add DDS_M_TAB2D_NEAREST_U16, DDS_M_TAB3D_NEAREST_U16 ,DDS_M_TAB3D_NEAREST_USU16,
*    comments :DDS_M_MAP2D_S16S8, DDS_M_TAB2D_NEAREST_U8 (Use Input Nearest),
*    comments :DDS_M_TAB3D_SSU16, DDS_M_TAB2D_U8, DDS_M_TAB2D_U16, DDS_M_POSITIVE_EDGE_DETECT, DDS_M_NEGATIVE_EDGE_DETECT
*    comments :and DDS_M_MAP3D_U16S16S8
* Version dev :\main\branch_demezil_fap_e6_dev\1 Date: 21/3/2011 15 h 32 m User:demezil
*    TWK_model:NO_MODEL
*    comments :v290 00PSASWC_L100D01
* Version dev :\main\branch_morisseau_fap_euro6_dev\2 Date: 7/3/2011 17 h 22 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add map DDS_M_MAP2D_US8 DDS_M_MAP3D_UUS8
*    comments :correct 32bits map interpolation
* Version int :/main/L01_01/11 Date: 16/11/2010 16 h 17 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :increase version's requirement
* Version dev :\main\branch_morisseau_fap_euro6_dev\2 Date: 15/11/2010 10 h 10 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :increase version's requirement
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 2/11/2010 15 h 2 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :correct DDS_M_U16_CALC_MEAN_SHIFTED_INIT
* Version int :/main/L01_01/10 Date: 4/10/2010 14 h 21 m User:meme
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Correction of:. DDS_M_TURN_OFF_DELAY_DELTA. DDS_M_TURN_ON_DELAY_DELTA
* Version dev :\main\branch_morisseau_fap_euro6_dev\2 Date: 4/10/2010 13 h 56 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Correction of:
*    comments :DDS_M_TURN_OFF_DELAY_DELTA
*    comments :DDS_M_TURN_ON_DELAY_DELTA
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 4/10/2010 11 h 34 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Correction of:
*    comments :DDS_M_TURN_OFF_DELAY_DELTA
*    comments :DDS_M_TURN_ON_DELAY_DELTA
* Version int :/main/L01_01/9 Date: 27/9/2010 14 h 29 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add TURN_ON_OFF_DELAY_DELTA. Add map DDS_M_MAP2D_U16U32, DDS_M_MAP2D_U16S32, DDS_M_MAP2D_S16U32,
*    comments :DDS_M_MAP2D_S16S32.. For FAP: add DDS_M_VARIABLE_TRANSPORT_DELAY_FAP
* Version dev :\main\branch_morisseau_fap_euro6_dev\3 Date: 24/9/2010 16 h 6 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add TURN_ON_OFF_DELAY_DELTA
*    comments :Add map DDS_M_MAP2D_U16U32, DDS_M_MAP2D_U16S32, DDS_M_MAP2D_S16U32, DDS_M_MAP2D_S16S32.

*    comments :For FAP: add DDS_M_VARIABLE_TRANSPORT_DELAY_FAP
* Version dev :\main\branch_morisseau_fap_euro6_dev\2 Date: 9/9/2010 9 h 46 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :last version
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 8/9/2010 16 h 28 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add debounce block: TURN_ON_OFF_DELAY_DELTA
* Version dev :\main\branch_demezil_fap_e6_dev\8 Date: 7/9/2010 12 h 18 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add DDS_M_MAP2D_S16U8
* Version dev :\main\branch_demezil_fap_e6_dev\7 Date: 24/8/2010 16 h 9 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add DDS_M_MAP3D_U8U8U16
* Version dev :\main\branch_demezil_fap_e6_dev\6 Date: 24/8/2010 16 h 2 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add DDS_M_MAP3D_U8U8U16
* Version dev :\main\branch_demezil_fap_e6_dev\5 Date: 19/8/2010 10 h 45 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :correct last update
* Version dev :\main\branch_demezil_fap_e6_dev\4 Date: 19/8/2010 10 h 29 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :correct issue number
* Version dev :\main\branch_demezil_fap_e6_dev\3 Date: 19/8/2010 10 h 25 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :correct issue number
* Version dev :\main\branch_demezil_fap_e6_dev\1 Date: 18/8/2010 17 h 44 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :ADD DDS_M_MAP2D_U8, DDS_M_MAP2D_S8, DDS_M_MAP2D_SU8, DDS_M_MAP2D_S8U16, DDS_M_MAP2D_U8U16,
*    comments :DDS_M_MAP2D_U16U8, DDS_M_MAP3D_U8, DDS_M_SUM_S32EXT32, DDS_M_SUM_S32EXT32_INIT, DDS_M_SUM_S32EXT32_SAT_INIT
* Version dev :\main\branch_lemort_boucle_air_dev\2 Date: 15/7/2010 10 h 15 m User:lemort
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add turn_on_delay_delta
* Version dev :\main\branch_morisseau_afad_view\3 Date: 30/6/2010 16 h 44 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add ouput default value for:
*    comments :DDS_M_SIGNAL_XX_DELAY_V2
*    comments :DDS_M_SIGNAL_XX_DELAY_V2_INIT
* Version dev :\main\branch_demezil_afad_dev\7 Date: 10/6/2010 9 h 58 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :for v240
* Version dev :\main\branch_demezil_afad_dev\6 Date: 7/6/2010 11 h 58 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add SIGNAL_S8_DELAY_V2 and SIGNAL_S8_DELAY_V2_INIT
* Version dev :\main\branch_demezil_afad_dev\5 Date: 7/6/2010 11 h 15 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add SIGNAL_U8_DELAY_V2 and SIGNAL_U8_DELAY_V2_INIT
* Version dev :\main\branch_demezil_afad_dev\4 Date: 3/6/2010 14 h 47 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add DDS_M_SIGNAL_S16_DELAY_V2,
*    comments :DDS_M_SIGNAL_S16_DELAY_V2_INIT,
*    comments :DDS_M_SIGNAL_U16_DELAY_V2,
*    comments :DDS_M_SIGNAL_U16_DELAY_V2_INIT,
*    comments :DDS_M_SIGNAL_BOOLEAN_DELAY,
*    comments :DDS_M_SIGNAL_BOOLEAN_DELAY_INIT.
*    comments :rename macro DDS_M_SIGNAL_S16_DELAY in DDS_M_SIGNAL_S16_DELAY_V1,
*    comments :DDS_M_SIGNAL_S16_DELAY_INIT in DDS_M_SIGNAL_S16_DELAY_V1_INIT
* Version int :/main/L01_01/6 Date: 23/4/2010 18 h 30 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :For Backlash
* Version dev :\main\branch_salmane_trbAct_euro6_dev\3 Date: 21/4/2010 14 h 20 m User:salmane
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :For Backlash
* Version dev :\main\branch_salmane_trbAct_euro6_dev\2 Date: 21/4/2010 14 h 13 m User:salmane
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :to debug backlash function
* Version dev :\main\branch_salmane_trbAct_euro6_dev\1 Date: 6/4/2010 17 h 51 m User:salmane
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :To add Backlash_library
* Version dev :\main\branch_moisan_trbact_dev\16 Date: 1/4/2010 10 h 43 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :correct DDS_M_2ND_ORDER_FILTER_S16_INIT
* Version int :/main/L01_01/4 Date: 26/3/2010 15 h 32 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :For TrbAct 1.0. v210
*    comments :For TrbAct 1.0. v210
* Version dev :\main\branch_moisan_trbact_dev\15 Date: 26/3/2010 15 h 17 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :For TrbAct 1.0. v210
* Version dev :\main\branch_moisan_trbact_dev\3 Date: 10/2/2010 12 h 43 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add DDS_M_2ND_ORDER_FILTER_S16 and DDS_M_2ND_ORDER_FILTER_S16_INIT
* Version dev :\main\branch_moisan_trbact_dev\1 Date: 5/2/2010 12 h 23 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add DDS_M_MEM_EXTINI_U16_INIT and DDS_M_MEM_EXTINI_U16
* Version int :/main/L01_01/1 Date: 3/12/2009 11 h 45 m User:langendorf
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add "DDS_M_FILTER_HYST_U16", "DDS_M_FILTER_HYST_U16_INIT", "DDS_M_FILTER_HYST_S32"
*    comments :and "DDS_M_FILTER_HYST_S32".
* Version dev :\main\branch_girodon_vsinfoh\2 Date: 13/11/2009 14 h 6 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add "DDS_M_FILTER_HYST_U16", "DDS_M_FILTER_HYST_U16_INIT", "DDS_M_FILTER_HYST_S32"
*    comments :and "DDS_M_FILTER_HYST_S32".
* Version int :/main/P2868/BR_06E4/3 Date: 16/9/2009 10 h 44 m User:langendorf
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32_INIT and DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 16/9/2009 10 h 4 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32_INIT and DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32
* Version dev :\main\branch_lemort_corepth\2 Date: 1/7/2009 15 h 59 m User:lemort
*    TWK_model:NO_MODEL
*    comments :DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32 devient
*    comments :DDS_M_ADAP_TRAN_TEMP_BLOC_S32
* Version dev :\main\branch_lemort_corepth\1 Date: 23/6/2009 16 h 1 m User:lemort
*    TWK_model:NO_MODEL
*    comments :for debug bloc transition temporelle adaptative
* Version dev :\main\branch_moisan_corepth_dev\6 Date: 15/6/2009 15 h 28 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Correct commentary
* Version dev :\main\branch_moisan_corepth_dev\1 Date: 12/6/2009 15 h 7 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32 and DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32_INIT
* Version int :/main/P2868/BR_06D7/1 Date: 28/5/2009 18 h 3 m User:langendorf
*    TWK_model:NO_MODEL
*    comments :Add : DDS_M_FILTER_LP1_ASSYM_S16, . DDS_M_FILTER_LP1_ASSYM_S16_INIT, . DDS_M_FILTER_HYST_S16.
*                    DDS_M_FILTER_HYST_S16_INIT. . Remove QAC warnings except for cartography function (to critical).
* Version dev :\main\branch_girodon_generic\1 Date: 28/5/2009 10 h 33 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add : DDS_M_FILTER_LP1_ASSYM_S16,
*    comments :DDS_M_FILTER_LP1_ASSYM_S16_INIT,
*    comments :DDS_M_FILTER_HYST_S16,
*    comments :DDS_M_FILTER_HYST_S16_INIT.
*    comments :Remove QAC warnings except for cartography function (to critical)
* Version dev :\main\branch_moisan_vsmaxh_dev\2 Date: 29/4/2009 13 h 37 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Correct errors in DDS_M_DYNAMIC_MULT_U32
* Version dev :\main\branch_moisan_vsctlinfo_dev\1 Date: 2/4/2009 14 h 28 m User:moisan
*    TWK_model:NO_MODEL
*    comments :- Improve DDS_M_DYNAMIC_MULT_U32 macro to avoid loss of resolution with parity test .
*              - Correct DDS_M_RESTORE_BINPOINT_UINT32 and DDS_M_RESTORE_BINPOINT_SINT32 in case of negative nb_shift_wished
* Version int :/main/17 Date: 22/12/2008 15 h 59 m User:neve
*    TWK_model:NO_MODEL
*    comments :Version 150: . Correct DDS_M_HYST_LH_U32 function. . Add DDS_M_HYST_LH_S32 function.
*                           . Add DDS_M_LINEAR_FILTER_S32 and DDS_M_LINEAR_FILTER_S32_INIT.
* Version dev :\main\branch_girodon_tqdemh_1_dev\1 Date: 9/12/2008 16 h 43 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Version 150:
*    comments :Correct DDS_M_HYST_LH_U32 function.
*    comments :Add DDS_M_HYST_LH_S32 function.
*    comments :Add DDS_M_LINEAR_FILTER_S32 and DDS_M_LINEAR_FILTER_S32_INIT.
* Version int :/main/16 Date: 14/11/2008 16 h 49 m User:langendorf
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_HYST_PH_S32 and DDS_M_HYST_PH_INIT_S32 macro.
* Version dev :\main\branch_girodon_pfilfast_1_dev\1 Date: 14/11/2008 12 h 11 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_HYST_PH_S32 and DDS_M_HYST_PH_INIT_S32 macro.
* Version dev :\main\branch_veillard_curdrivfil\5 Date: 4/11/2008 9 h 54 m User:veillard
*    TWK_model:NO_MODEL
*    comments :R6513605 v3.0
* Version dev :\main\branch_veillard_curdrivfil\4 Date: 31/10/2008 14 h 55 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Correction after build all
* Version dev :\main\branch_veillard_curdrivfil\3 Date: 31/10/2008 14 h 16 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Correction after build all
* Version dev :\main\branch_veillard_curdrivfil\2 Date: 31/10/2008 9 h 32 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Add new SOFT TRANSITION DELTA
* Version dev :\main\branch_veillard_curdrivfil\1 Date: 30/10/2008 16 h 52 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Add new macro DDS_M_TURN_OFF_DELAY & DDS_M_TURN_OFF_DELAY_INIT
* Version dev :\main\branch_girodon_tqdem_1_dev\1 Date: 8/10/2008 16 h 10 m User:girodon
*    TWK_model:LDCR_Application_06E400_IMPL2
*    comments :Rename last function added to respect the naming convention : all function must start with "DDS_M_".
* Version int :/main/P2868/BR_06E4/1 Date: 9/9/2008 8 h 5 m User:boucher
*    TWK_model:NO_MODEL
*    comments :Update library in order to be coherente with PSA TqDem specification
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 4/9/2008 15 h 14 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update library in order to be coherente with PSA TqDem specification
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\1 Date: 29/8/2008 8 h 58 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Update version of library to be in coherence with header file version.
* Version int :/main/15 Date: 29/4/2008 15 h 0 m User:neve
*    TWK_model:NO_MODEL
*    comments :Correct "M_FILTER_LP1_U16" function.
* Version dev :\main\branch_girodon_xvv_2_dev\3 Date: 28/4/2008 12 h 34 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Correct "M_FILTER_LP1_U16" function.
* Version dev :\main\branch_girodon_xvv_2_dev\1 Date: 28/4/2008 9 h 20 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add "DDS_M_DECREMENT_SINT32" to be use to create the minimum sint32 suypported by the machine.
* Version int :/main/14 Date: 15/4/2008 15 h 44 m User:neve
*    TWK_model:NO_MODEL
*    comments :Update version following big mistake in define declaration (FDS22651).
* Version dev :\main\branch_girodon_fap_1_dev\1 Date: 14/4/2008 11 h 23 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Update version following big mistake in define declaration (FDS22651).
* Version int :/main/13 Date: 8/4/2008 9 h 39 m User:neve
*    TWK_model:NO_MODEL
*    comments :Use -(2^31) instead of "DDS_SINT32_MIN" for the min value to reduce time function's execution
*             :of addition protected function and bary filter.
* Version dev :\main\branch_girodon_module_integ_xvv_1\2 Date: 2/4/2008 14 h 27 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Use -(2^31) instead of "DDS_SINT32_MIN" for the min value to reduce time function's execution
*             :of addition protected function and bary filter.
* Version dev :\main\branch_girodon_module_integ_xvv_1\1 Date: 2/4/2008 13 h 13 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Use -(2^31) instead of "DDS_SINT32_MIN" for the min value to reduce time function's execution (warning use introduce).
* Version dev :\main\branch_terracol_sstg_autosar\12 Date: 28/3/2008 10 h 41 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Protected addition optimisation
* Version dev :\main\branch_terracol_sstg_autosar\11 Date: 28/3/2008 9 h 33 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Protected addition optimisation
* Version dev :\main\branch_terracol_sstg_autosar\9 Date: 11/3/2008 12 h 39 m User:terracol
*    TWK_model:NO_MODEL
*    comments :QUAL Correction M_GET_BITFIELD --> DDS_M_GET_BITFIELD
* Version dev :\main\branch_terracol_sstg_autosar\8 Date: 11/3/2008 12 h 11 m User:terracol
*    TWK_model:NO_MODEL
*    comments :QUAL correction + optimisation for DDS_M_SHORTEN_SINT32_TO_SINT16
* Version int :/main/12 Date: 29/2/2008 11 h 40 m User:renier
*    TWK_model:NO_MODEL
*    comments :dynamique library corrections
* Version dev :\main\branch_terracol_sstg_autosar\7 Date: 27/2/2008 17 h 19 m User:terracol
*    TWK_model:NO_MODEL
*    comments :dynamique library corrections
* Version dev :\main\branch_terracol_sstg_autosar\6 Date: 25/2/2008 16 h 34 m User:terracol
*    TWK_model:NO_MODEL
*    comments :correction of DDS_M_DYNAMIC_MULT_USS32, use of saturation replace by BIN reduction. Add macro DDS_M_SHORTEN_UINT32_TO_UINT32
* Version dev :\main\branch_terracol_sstg_autosar\4 Date: 22/2/2008 15 h 22 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add VSC_DDS_M_ADDITION_S32 and VSC_DDS_M_ADDITION_U32
* Version int :/main/11 Date: 22/10/2007 9 h 36 m User:renier
*    TWK_model:NO_MODEL
*    comments :In Dynamic library, fix operation was replace by round operation.
* Version dev :\main\branch_terracol_sstg_autosar\3 Date: 16/10/2007 13 h 45 m User:terracol
*    TWK_model:NO_MODEL
*    comments :In Dynamic library, fix operation was replace by round operation.
* Version dev :\main\branch_terracol_sstg_autosar\2 Date: 16/10/2007 8 h 28 m User:terracol
*    TWK_model:NO_MODEL
*    comments :BIN dynamic library evolution
* Version int :/main/10 Date: 15/10/2007 10 h 35 m User:renier
*    TWK_model:NO_MODEL
*    comments :Add .c/.h compatibility check. . Correct DDS_M_SIGNAL_S16_DELAY behaviour when time delay is 0.
* Version dev :\main\branch_girodon_dgd_sstg\3 Date: 3/10/2007 11 h 38 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add .c/.h compatibility check.
*    comments :Correct DDS_M_SIGNAL_S16_DELAY behaviour when time delay is 0.
* Version int :/main/9 Date: 23/7/2007 16 h 53 m User:renier
*    TWK_model:NO_MODEL
*    comments :DDS_M_TURN_ON_DELAY, DDS_M_TURN_OFF_DELAY, DDS_M_TURN_ON_OFF_DELAY correction case
*             :Delay == 0 (according to lib_macro.c in blois soft vob)
* Version dev :\main\branch_terracol_sstg_autosar\5 Date: 19/7/2007 8 h 54 m User:terracol
*    TWK_model:NO_MODEL
*    comments :DDS_M_TURN_ON_DELAY, DDS_M_TURN_OFF_DELAY, DDS_M_TURN_ON_OFF_DELAY correction case
*             :Delay == 0 (according to lib_macro.c in blois soft vob)
* Version dev :\main\branch_terracol_sstg_autosar\4 Date: 18/7/2007 18 h 14 m User:terracol
*    TWK_model:NO_MODEL
*    comments :behaviour modification of DDS_M_DYNAMIC_MULT_U32, DDS_M_DYNAMIC_MULT_S32, DDS_M_DYNAMIC_MULT_USS32
* Version dev :\main\branch_terracol_sstg_autosar\3 Date: 17/7/2007 15 h 30 m User:terracol
*    TWK_model:NO_MODEL
*    comments :DDS_M_DYNAMIC_DIV_U32 and DDS_M_DYNAMIC_DIV_S32 corrections
* Version dev :\main\branch_terracol_sstg_autosar\2 Date: 4/7/2007 16 h 19 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add dynamic librairy:
*    comments :DDS_M_DYNAMIC_MULT_U32
*    comments :DDS_M_DYNAMIC_MULT_S32
*    comments :DDS_M_DYNAMIC_MULT_USS32
*    comments :DDS_M_DYNAMIC_DIV_U32
*    comments :DDS_M_DYNAMIC_DIV_S32
* Version dev :\main\branch_terracol_sstg_autosar\1 Date: 15/5/2007 8 h 26 m User:terracol
*    TWK_model:NO_MODEL
*    comments :DDS_M_BARY_FILTER_S32 correction
* Version int :/main/7 Date: 17/4/2007 13 h 31 m User:neve
*    TWK_model:NO_MODEL
*    comments :Add macro DDS_M_INTEGRATE_S16U32
* Version dev :\main\branch_terracol_sstg_autosar\19 Date: 11/4/2007 13 h 44 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add macro DDS_M_INTEGRATE_S16U32
* Version int :/main/6 Date: 27/2/2007 10 h 37 m User:renier
*    TWK_model:NO_MODEL
*    comments :Change "REDUCE" function names due to downward compatibility requirement (should have been done in previous version).
* Version dev :\main\branch_girodon_dgd_sstg\1 Date: 21/2/2007 9 h 37 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Change "REDUCE" function names due to downward compatibility requirement (should have been done in previous version).
* Version int :/main/5 Date: 12/2/2007 15 h 53 m User:cheucle
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :add #define START_SEC_CODE_LIB . #include "dds_lib_MemMap.h" . #define STOP_SEC_CODE_LIB . #include "dds_lib_MemMap.h"
* Version dev :\main\branch_terracol_sstg_autosar\18 Date: 8/2/2007 16 h 54 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :add #define START_SEC_CODE_LIB
*    comments :#include "dds_lib_MemMap.h"
*    comments :#define STOP_SEC_CODE_LIB
*    comments :#include "dds_lib_MemMap.h"
* Version dev :\main\branch_terracol_sstg_autosar\17 Date: 6/2/2007 9 h 22 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Headers corrections
* Version dev :\main\branch_terracol_sstg_autosar\16 Date: 5/2/2007 16 h 25 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :add DDS_M_TAB2D_U16
* Version dev :\main\branch_terracol_sstg_autosar\15 Date: 5/2/2007 11 h 29 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Correction of DDS_M_BARY_FILTER_S32
* Version dev :\main\branch_terracol_sstg_autosar\14 Date: 1/2/2007 14 h 20 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :DDS_M_SLEW_INIT_U32 -> DDS_M_SLEW_U32_INIT
* Version dev :\main\branch_terracol_sstg_autosar\13 Date: 30/1/2007 14 h 24 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :correcection of DDS_M_INCREASE_SINT32_TO_SINT32
* Version dev :\main\branch_terracol_sstg_autosar\12 Date: 30/1/2007 14 h 8 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :DDS_M_REDUCE_SINT32_TO_SINT16 and DDS_M_REDUCE_UINT32_TO_UINT16 headers modification.
*    comments :DDS_M_INCREASE_UINT32_TO_UINT32 and DDS_M_INCREASE_SINT32_TO_SINT32 modification.
* Version dev :\main\branch_terracol_sstg_autosar\11 Date: 29/1/2007 17 h 12 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Correction of DDS_M_PROD_MATRIX_UINT16 & DDS_M_PROD_MATRIX_SINT16
* Version dev :\main\branch_terracol_sstg_autosar\10 Date: 26/1/2007 16 h 36 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :add DDS_M_BARY_FILTER_S32 (not operationnal currently)
* Version dev :\main\branch_girodon_dgd_sstg\10 Date: 25/1/2007 9 h 0 m User:girodon
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Add macro DDS_M_INCREASE_UINT32_TO_UINT32 and update DDS_M_REDUCE_xINT32_TO_xINT16 to not set to 0 nb_shift.
* Version dev :\main\branch_terracol_sstg_autosar\9 Date: 19/1/2007 11 h 1 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :In macro DDS_M_PROD_MATRIX_ CONSP2CONST -> P2VAR
* Version dev :\main\branch_terracol_sstg_autosar\8 Date: 18/1/2007 15 h 43 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Output of matrix multiplication becomes 32 bits
* Version int :/main/P2868/BR_06C/3 Date: 12/1/2007 10 h 3 m User:renier
*    TWK_model:LDCR_Application_06C000_IMPL3
*    comments :Rename "t_dds_m_hyst_u32_type" to "t_dds_m_hyst_type". . Change "DDS_M_REDUCE_UINT32_TO_UINT16" and
*             :"DDS_M_REDUCE_SINT32_TO_SINT16" in order to init nb_shift to 0 (temporary).
* Version dev :\main\branch_girodon_dgd_sstg\9 Date: 11/1/2007 18 h 41 m User:girodon
*    TWK_model:LDCR_Application_06C000_IMPL3
*    comments :Rename "t_dds_m_hyst_u32_type" to "t_dds_m_hyst_type". . Change "DDS_M_REDUCE_UINT32_TO_UINT16" and
*             :"DDS_M_REDUCE_SINT32_TO_SINT16" in order to init nb_shift to 0 (temporary).
* Version dev :\main\branch_guillon_sstg_autosar\6 Date: 11/1/2007 10 h 8 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Add macros DDS_M_HYST_U32 and DDS_M_HYST_U32_INIT
* Version dev :\main\branch_terracol_sstg_autosar\7 Date: 11/1/2007 9 h 3 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add macros DDS_M_PROD_MATRIX_UINT16 & DDS_M_PROD_MATRIX_SINT16
* Version int :/main/P2868/BR_06C/2 Date: 21/12/2006 10 h 2 m User:cheucle
*    TWK_model:NO_MODEL
*    comments :modifications applied on macro DDS_M_SIGNAL_S16_DELAY & DDS_M_SIGNAL_S16_DELAY_INIT to correct buffer delay values assignement.
* Version int :/main/P2868/BR_06C/1 Date: 6/12/2006 13 h 32 m User:neve
*    TWK_model:LDCR_Application_06C000_SPEC1
*    comments :Remove QAC warnings.
* Version dev :\main\branch_delpierre_sstg_autosar\2 Date: 12/12/2006 9 h 51 m User:delpierre
*    TWK_model:NO_MODEL
*    comments :modifications applied on macro DDS_M_SIGNAL_S16_DELAY & DDS_M_SIGNAL_S16_DELAY_INIT to correct buffer delay values assignement.
* Version dev :\main\branch_terracol_sstg_autosar\6 Date: 6/12/2006 14 h 26 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Correction of "user guide" for macro DDS_M_RESTORE_BINPOINT
* Version dev :\main\branch_guillon_sstg_autosar\5 Date: 6/12/2006 13 h 58 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Modification of macros :
*    comments :DDS_M_CALC_MEAN_BUFFER
*    comments :DDS_M_CALC_MEAN_BUFFER_INIT
*    comments :DDS_M_REDUCE_SINT32_TO_SINT16
*    comments :DDS_M_RESTORE_BINPOINT_UINT32
*    comments :DDS_M_RESTORE_BINPOINT_SINT32
* Version dev :\main\branch_terracol_sstg_autosar\5 Date: 4/12/2006 10 h 20 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add function for dynamic binpoint:
*    comments :DDS_M_REDUCE_UINT32_TO_UINT16
*    comments :DDS_M_REDUCE_SINT32_TO_SINT16
*    comments :DDS_M_RESTORE_BINPOINT_UINT32
*    comments :DDS_M_RESTORE_BINPOINT_SINT32
* Version dev :\main\branch_girodon_dgd_sstg\8 Date: 28/11/2006 9 h 44 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Remove QAC warnings.
* Version dev :\main\branch_girodon_dgd_sstg\7 Date: 28/11/2006 9 h 8 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_SIGNAL_S16_DELAY and DDS_M_SIGNAL_S16_DELAY_INIT.
* Version dev :\main\branch_hz9crn_dpf\1 Date: 22/11/2006 11 h 33 m User:oudin
*    TWK_model:NO_MODEL
*    comments :add macros DDS_TRUE and DDS_FALSE .
* Version dev :\main\branch_delpierre_sstg_autosar\1 Date: 21/11/2006 13 h 22 m User:delpierre
*    TWK_model:NO_MODEL
*    comments :map macro renamed
* Version dev :\main\branch_terracol_sstg_autosar\4 Date: 20/11/2006 15 h 27 m User:terracol
*    TWK_model:NO_MODEL
*    comments :correction of bad replace
* Version dev :\main\branch_terracol_sstg_autosar\3 Date: 20/11/2006 14 h 45 m User:terracol
*    TWK_model:NO_MODEL
*    comments :debbug latest macros added
* Version dev :\main\branch_terracol_sstg_autosar\2 Date: 20/11/2006 14 h 37 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add macros:
*    comments :- DDS_M_TIMER_DISP_U16, DDS_M_TIMER_DISP_U16_INIT
*    comments :- DDS_M_TIMER_DISP_U32, DDS_M_TIMER_DISP_U32_INIT
* Version dev :\main\branch_terracol_sstg_autosar\1 Date: 20/11/2006 13 h 16 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add macros:
*    comments :- DDS_M_TIMER, DDS_M_TIMER_INIT
*    comments :- DDS_M_TURN_ON_DELAY, DDS_M_TURN_ON_DELAY_INIT
*    comments :- DDS_M_TURN_OFF_DELAY, DDS_M_TURN_OFF_DELAY_INIT
*    comments :- DDS_M_TURN_ON_OFF_DELAY, DDS_M_TURN_ON_OFF_DELAY_INIT
* Version dev :\main\branch_guillon_sstg_autosar\4 Date: 17/11/2006 14 h 45 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Modification of macros :
*    comments :DDS_M_INTEGRATE_32 (input_value <-> current_time)
*    comments :DDS_M_CHRONOMETER_U32_INIT(init_value <-> current_time)
* Version dev :\main\branch_guillon_sstg_autosar\3 Date: 14/11/2006 9 h 47 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Macros renamed :
*    comments :- DDS_M_UMAP2D => DDS_M_MAP2D_U16
*    comments :- DDS_M_SMAP2D => DDS_M_MAP2D_S16
*    comments :- DDS_M_SUMAP2D => DDS_M_MAP2D_SU16
*    comments :- DDS_M_USMAP2D => DDS_M_MAP2D_US16
*    comments :- DDS_M_UMAP3D => DDS_M_MAP3D_U16
*    comments :- DDS_M_SMAP3D => DDS_M_MAP3D_S16
*    comments :- DDS_M_SUSMAP3D => DDS_M_MAP3D_SUS16
*    comments :- DDS_M_USSMAP3D => DDS_M_MAP3D_USS16
*    comments :- DDS_M_SUUMAP3D => DDS_M_MAP3D_SUU16
*    comments :- DDS_M_USUMAP3D => DDS_M_MAP3D_USU16
*    comments :- DDS_M_SSUMAP3D => DDS_M_MAP3D_SSU16
*    comments :- DDS_M_UUSMAP3D => DDS_M_MAP3D_UUS16
* Version dev :\main\branch_girodon_dgd_sstg\3 Date: 6/11/2006 11 h 11 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Correct function's parameters (change P2VAR to P2CONST or CONSTP2CONST)
* Version dev :\main\branch_girodon_dgd_sstg\2 Date: 3/11/2006 16 h 45 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Correct problems detected by QAC.
*    comments :Add:
*    comments :- DDS_M_EDGE_DETECT
*    comments :- DDS_M_EDGE_DETECT_INIT
*    comments :Update :
*    comments :- DDS_M_BARY_FILTER_S16 interface
* Version dev :\main\branch_guillon_sstg_autosar\2 Date: 2/11/2006 14 h 54 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Add macros :
*    comments :- DDS_M_FILTER_LP1_U16,
*    comments :- DDS_M_FILTER_LP1_U16_INIT,
*    comments :- DDS_M_FILTER_LP1_S16,
*    comments :- DDS_M_FILTER_LP1_S16_INIT
* Version dev :\main\branch_guillon_sstg_autosar\1 Date: 23/10/2006 13 h 34 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Add following macros :
*    comments :- DDS_M_INV_BOOL_TYPE
*    comments :- DDS_M_ABS
*    comments :- DDS_M_CHRONOMETER_U32
*    comments :- DDS_M_CHRONOMETER_U32_INIT
*    comments :Modification of DDS_M_BARY_FILTER_S16
* Version dev :\main\branch_girodon_dgd_sstg\1 Date: 9/10/2006 10 h 43 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add following macros:
*    comments :- DDS_M_MIN
*    comments :- DDS_M_MAX
*    comments :- DDS_M_LIMIT
*    comments :- DDS_M_UMAP2D
*    comments :- DDS_M_SMAP2D
*    comments :- DDS_M_SUMAP2D
*    comments :- DDS_M_USMAP2D
*    comments :- DDS_M_UMAP3D
*    comments :- DDS_M_SMAP3D
*    comments :- DDS_M_SUSMAP3D
*    comments :- DDS_M_USSMAP3D
*    comments :- DDS_M_SUUMAP3D
*    comments :- DDS_M_USUMAP3D
*    comments :- DDS_M_SSUMAP3D
*    comments :- DDS_M_UUSMAP3D
*    comments :- DDS_M_INTEGRATE_32
*    comments :- DDS_M_INTEGRATE_32_INIT
*    comments :- DDS_M_INTEGRATE_16EXT32
*    comments :- DDS_M_INTEGRATE_16EXT32_INIT
*    comments :- DDS_M_CHECK_DELTA16
*    comments :- DDS_M_CHECK_DELTA16_INIT
*    comments :- DDS_M_CALC_MEAN_BUFFER
*    comments :- DDS_M_CALC_MEAN_BUFFER_INIT
*    comments :- DDS_M_SLEW_S32
*    comments :- DDS_M_SLEW_S32_INIT
*    comments :- DDS_M_BARY_FILTER_S16
*
*******************************************************************************/

/*******************************************************************************
*   Library Include Files
*******************************************************************************/

#include "dds_lib.h"
#include "Rte_Type.h"   /* Generic AUTOSAR types definitions */

/*******************************************************************************
*  Library Version
*******************************************************************************/

#define DDS_LIB_VERSION_REQ 430

/* Comptibility test */
#if DDS_LIB_VERSION_REQ - DDS_LIB_VERSION
dds_lib.h version is not compatible with dds_lib.c
#endif


/*******************************************************************************
*  Local Task Function Declaration
*******************************************************************************/
#define DDS_LIB_START_SEC_CODE
#include "dds_lib_MemMap.h"

static FUNC(uint16, AUTOMATIC) DDS_M_SOFT_TRANS_INC_RATIO(uint32 delta_time,
                       uint32 transition_duration,
                       uint16 ratio,
                       CONSTP2VAR (uint32, AUTOMATIC, AUTOMATIC) error_ptr,
                       CONSTP2VAR (uint16, AUTOMATIC, AUTOMATIC) error_shift_ptr);

/*******************************************************************************
*
*                                 MACROS DEFINITIONS
*
********************************************************************************/


/*******************************************************************************
*  Macro name:  DDS_M_ADDITION_S32
*
* out = in1 + in2
*
* if out > DDS_SINT32_MAX --> out = DDS_SINT32_MAX
* if out < -(2^31)        --> out = -(2^31)
*
*
* WARNING: in the case of "DDS_SINT32_MIN" is different from "-(2^31)" a limit
*          should be use after the use of this function.
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_ADDITION_S32(sint32 in1, sint32 in2)
{
    sint32 sum = in1 + in2;
    t_dds_m_sint sign_in1 = DDS_M_SIGN(in1);

    if( (sign_in1 == DDS_M_SIGN(in2)) &&
        (sign_in1 != DDS_M_SIGN(sum)) )
    {
        if(0 != sign_in1)
        {
            sum = DDS_SINT32_MIN_FULL;
        }
        else
        {
            sum = DDS_SINT32_MAX;
        }
    }
    else
    {
        /* Do nothing */
    }
    return(sum);
}

/*******************************************************************************
*  Macro name:  DDS_M_ADDITION_U32
*
* out = in1 + in2
*
* if out > DDS_UINT32_MAX --> out = DDS_UINT32_MAX
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_ADDITION_U32(uint32 in1, uint32 in2)
{
    uint32 sum;


    if (in1 > (DDS_UINT32_MAX - in2))
    {
        sum = DDS_UINT32_MAX;
    }
    else
    {
        sum = in1 + in2;
    }

    return(sum);
}

/*******************************************************************************
*  Function name:  DDS_M_INTEGRATE_32
*
*  Description :
*   The following function is used to perform an integration function.
*
*     S(n+1) = S(n) + (input_value * elapsed_time)
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   input_value is the input value
*   current_time is the current time
*
*  REMARKS:
*   The sum is limited to the 32bit unsigned integer max value (no roll over).
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_32(
        CONSTP2VAR(t_dds_m_integrate_32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
        uint32 current_time,
        uint32 input_value)
{
    uint32 elapsed_time_tmp;
    uint32 calc_temp;

    /* Time passed calculation */
    elapsed_time_tmp = current_time - integrate_struct_ptr->dds_int_previous_time;

    if (0 != input_value)
    {
        if ( (DDS_UINT32_MAX / input_value) < elapsed_time_tmp )
        {
            integrate_struct_ptr->dds_int_prev_output = DDS_UINT32_MAX;
        }
        else
        {
            calc_temp = input_value * elapsed_time_tmp;

            if ( (DDS_UINT32_MAX - calc_temp) < integrate_struct_ptr->dds_int_prev_output )
            {
                integrate_struct_ptr->dds_int_prev_output = DDS_UINT32_MAX;
            }
            else
            {
                integrate_struct_ptr->dds_int_prev_output += calc_temp;
            }
        }
    }
    else
    {
        /* Do nothing */
    }

    integrate_struct_ptr->dds_int_previous_time = current_time;

    return(integrate_struct_ptr->dds_int_prev_output);
}

/*******************************************************************************
*  Macro name:  DDS_M_INTEGRATE_32_INIT
*
*  Description :
*  The following macro manage reset of macro DDS_M_INTEGRATE_32
*
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   current_time is the current time
*   init_value is the output init value
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_32_INIT(
        CONSTP2VAR(t_dds_m_integrate_32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
        uint32 current_time,
        uint32 init_value )
{
    integrate_struct_ptr->dds_int_prev_output   = init_value;
    integrate_struct_ptr->dds_int_previous_time = current_time;

    return(init_value);
}

/*******************************************************************************
*  Function name:  DDS_M_INTEGRATE_S16U32
*
*  Description :
*   The following function is used to perform an integration function.
*
*     S(n+1) = S(n) + (input_value * elapsed_time)
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   input_value is the input value
*   current_time is the current time
*
*  REMARKS:
*   The sum is limited to the 32bit unsigned integer max value (no roll over).
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_S16U32(CONSTP2VAR(t_dds_m_integrate_s16u32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                uint32 current_time,
                                                sint16 input_value)
{
     uint32 local_elapsed_time;
     uint16 elapsed_time_limited;
     uint32 temp_calc;


     /* Elapsed time calculation */
    local_elapsed_time = current_time - integrate_struct_ptr->dds_int_previous_time;

    integrate_struct_ptr->dds_int_previous_time = current_time;
    /* Limit elapsed */
    elapsed_time_limited = (uint16)DDS_M_MIN(local_elapsed_time, DDS_UINT16_MAX);

    if((t_dds_m_sint)input_value < 0)
    {
        /* Calculate input_value * elapsed_time_tmp (no overflow possible) */
        temp_calc = (uint32)(-(sint32)input_value) * (uint32)elapsed_time_limited;


        if(integrate_struct_ptr->dds_int_prev_output > temp_calc)
        {
            integrate_struct_ptr->dds_int_prev_output -= temp_calc;
        }
        else
        {
            integrate_struct_ptr->dds_int_prev_output = 0;
        }
    }
    else if((t_dds_m_sint)input_value > 0)
    {
        /* Calculate input_value * elapsed_time_tmp (no overflow possible) */
        temp_calc = (uint32)input_value * (uint32)elapsed_time_limited;


        if(integrate_struct_ptr->dds_int_prev_output < (DDS_UINT32_MAX - temp_calc))
        {
            integrate_struct_ptr->dds_int_prev_output += temp_calc;
        }
        else
        {
            integrate_struct_ptr->dds_int_prev_output = DDS_UINT32_MAX;
        }
    }
    else
    {
        /* do nothing */
    }

    return(integrate_struct_ptr->dds_int_prev_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_INTEGRATE_S16U32_INIT
*
*  Description :
*  The following macro manage reset of macro DDS_M_INTEGRATE_S16U32
*
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   current_time is the current time
*   init_value is the output init value
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_S16U32_INIT(CONSTP2VAR(t_dds_m_integrate_s16u32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                uint32 current_time,
                                                uint32 input_init_value)
{
    integrate_struct_ptr->dds_int_prev_output   = input_init_value;
    integrate_struct_ptr->dds_int_previous_time = current_time;

    return(integrate_struct_ptr->dds_int_prev_output);
}

/*******************************************************************************
*  Function name:  DDS_M_INTEGRATE_16EXT32
*
*  Description :
*   The following function is used to perform an integration function
*
*   S(n+1) = S(n) + (input_value * elapsed_time)
*
*   The result is divided in 2 parts (for a better accuracy)
*
*   S(n) = ( H(n) * step ) + L(n)
*
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   input_value is the input value
*   current_time is the current time
*
*  REMARKS:
*   H is an 16bit unsigned integer
*   L is an 32bit unsigned integer
*
*  WARNING:
*   time_passed is limited to 16bit unsigned integer max value (65535).
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_INTEGRATE_16EXT32(
        CONSTP2VAR(t_dds_m_integrate_16ext32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
        uint32 current_time,
        uint16 input_value )
{
    uint32 elapsed_time_tmp;
    uint32 temp_calc;
    uint32 temp_high;
    uint32 temp_low;
    uint32 output_step;
    uint32 nb_step_in_u32max;
    uint32 nb_step_in_low;
    uint32 add_max;

    /* Elapsed time calculation */
    elapsed_time_tmp = current_time - integrate_struct_ptr->dds_int_previous_time;

    /* Avoid useless calculation */
    if (((t_dds_m_uint)input_value > (t_dds_m_uint)0) &&
        ((t_dds_m_uint)*(integrate_struct_ptr->dds_int_prev_output_high_ptr) < DDS_UINT16_MAX))
    {
        /* Limit elapsed */
        if (elapsed_time_tmp > DDS_UINT16_MAX)
        {
            elapsed_time_tmp = DDS_UINT16_MAX;
        }
        else
        {
            /* Do nothing */
        }
        /* Calculate input_value * elapsed_time_tmp (no overflow possible) */
        temp_calc = (uint32)input_value * elapsed_time_tmp;

        output_step = integrate_struct_ptr->dds_int_output_step;
/* <PRQA_COMMENT><2834> output_step will never be equal to 0 </2834></PRQA_COMMENT> */
        temp_high = temp_calc / output_step;
/* <PRQA_COMMENT><2834> output_step will never be equal to 0 </2834></PRQA_COMMENT> */
        temp_low = temp_calc % output_step;
        add_max = DDS_UINT32_MAX - *(integrate_struct_ptr->dds_int_prev_output_low_ptr);

        /* Check if an overflow on 32bit is possible */
        if (temp_low > add_max)
        {
            /* then calculate the number of step present in u32 max */
/* <PRQA_COMMENT><2834> output_step will never be equal to 0 </2834></PRQA_COMMENT> */
            nb_step_in_u32max = (DDS_UINT32_MAX / output_step);
            /* Check if an overflow on 16bit is possible before adding nb_step */
            if ( (DDS_UINT16_MAX - nb_step_in_u32max) > temp_high )
            {
                *(integrate_struct_ptr->dds_int_prev_output_high_ptr) = DDS_UINT16_MAX;
                *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = DDS_UINT32_MAX;
            }
            else
            {
                /* Update temp_high and temp_low */
                temp_high += nb_step_in_u32max;
/* <PRQA_COMMENT><2834> output_step will never be equal to 0 </2834></PRQA_COMMENT> */
                temp_low = (temp_low - add_max) + (DDS_UINT32_MAX - (DDS_UINT32_MAX % output_step));

                /* Calculate the next possible step to add from low */
/* <PRQA_COMMENT><2834> output_step will never be equal to 0 </2834></PRQA_COMMENT> */
                nb_step_in_low = temp_low / output_step;
                /* Check if an overflow on 16bit is possible */
                if ( (DDS_UINT16_MAX - nb_step_in_low) < temp_high )
                {
                    *(integrate_struct_ptr->dds_int_prev_output_high_ptr) = DDS_UINT16_MAX;
                    *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = DDS_UINT32_MAX;
                }
                else
                {
                    /* Update temp_high */
                    temp_high += nb_step_in_low;
                    temp_low %= output_step;
                    /* Check if an overflow on 16bit is possible */
                    if ( ((sint32)DDS_UINT16_MAX - (sint32)temp_high) < (sint32)*(integrate_struct_ptr->dds_int_prev_output_high_ptr) )
                    {
                        *(integrate_struct_ptr->dds_int_prev_output_high_ptr) = DDS_UINT16_MAX;
                        *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = DDS_UINT32_MAX;
                    }
                    else
                    {
                        *(integrate_struct_ptr->dds_int_prev_output_high_ptr) =
                            (uint16)((uint32)*(integrate_struct_ptr->dds_int_prev_output_high_ptr) +
                                    temp_high);
                        *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = temp_low % output_step;
                    }
                }
            }
        }
        else
        {
            /* Update temp_low */
            temp_low += *(integrate_struct_ptr->dds_int_prev_output_low_ptr);

            /* Calculate the possible step to add from low */
/* <PRQA_COMMENT><2834> output_step will never be equal to 0 </2834></PRQA_COMMENT> */
            nb_step_in_low = temp_low / output_step;
            /* Check if an overflow on 16bit is possible */
            if ( (DDS_UINT16_MAX - nb_step_in_low) < temp_high )
            {
                *(integrate_struct_ptr->dds_int_prev_output_high_ptr) = DDS_UINT16_MAX;
                *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = DDS_UINT32_MAX;
            }
            else
            {
                /* Update temp_high */
                temp_high += nb_step_in_low;
                /* Check if an overflow on 16bit is possible */
                if ( ((sint32)DDS_UINT16_MAX - (sint32)temp_high) < (sint32)*(integrate_struct_ptr->dds_int_prev_output_high_ptr) )
                {
                    *(integrate_struct_ptr->dds_int_prev_output_high_ptr) = DDS_UINT16_MAX;
                    *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = DDS_UINT32_MAX;
                }
                else
                {
                    *(integrate_struct_ptr->dds_int_prev_output_high_ptr) =
                        (uint16)((uint32)*(integrate_struct_ptr->dds_int_prev_output_high_ptr) +
                                temp_high);
                    *(integrate_struct_ptr->dds_int_prev_output_low_ptr) = temp_low % output_step;
                }
            }
        }
    }
    else
    {
        /* Do nothing */
    }
    integrate_struct_ptr->dds_int_previous_time = current_time;

    return *(integrate_struct_ptr->dds_int_prev_output_high_ptr);
}

/*******************************************************************************
*  Macro name:  DDS_M_INTEGRATE_16EXT32_INIT
*
*  Description :
*  The following macro manage reset of macro DDS_M_INTEGRATE_32EXT16
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   current_time is the current time
*   integrate_high_output_ptr is the high data pointer
*   integrate_low_output_ptr is the low data pointer
*   high_output_init_value is the init value of high data
*   low_output_init_value is the init value of low data
*   output_step_value is the step use to increment the high part
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_INTEGRATE_16EXT32_INIT(
        CONSTP2VAR(t_dds_m_integrate_16ext32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
        uint32 current_time,
        P2VAR (uint16, AUTOMATIC, AUTOMATIC) integrate_high_output_ptr,
        P2VAR (uint32, AUTOMATIC, AUTOMATIC) integrate_low_output_ptr,
        uint16 high_output_init_value,
        uint32 low_output_init_value,
        uint32 output_step_value )
{
    integrate_struct_ptr->dds_int_prev_output_high_ptr    = integrate_high_output_ptr;
    integrate_struct_ptr->dds_int_prev_output_low_ptr     = integrate_low_output_ptr;
    *(integrate_struct_ptr->dds_int_prev_output_high_ptr) = high_output_init_value;
    *(integrate_struct_ptr->dds_int_prev_output_low_ptr)  = low_output_init_value;
    integrate_struct_ptr->dds_int_previous_time           = current_time;
    integrate_struct_ptr->dds_int_output_step             = output_step_value;

    return(high_output_init_value);
}

/*******************************************************************************
*  Macro name:  DDS_M_INTEGRATE_16EXT32_PTR_INIT
*
*  Description :
*  The following macro manage reset of pointer for DDS_M_INTEGRATE_32EXT16 in aftersale context
*
*  Where:
*   integrate_struct_ptr is the structure associated to macro
*   integrate_high_output_ptr is the high data pointer
*   integrate_low_output_ptr is the low data pointer
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_INTEGRATE_16EXT32_PTR_INIT(
        CONSTP2VAR(t_dds_m_integrate_16ext32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
        P2VAR (uint16, AUTOMATIC, AUTOMATIC) integrate_high_output_ptr,
        P2VAR (uint32, AUTOMATIC, AUTOMATIC) integrate_low_output_ptr)
{
    integrate_struct_ptr->dds_int_prev_output_high_ptr    = integrate_high_output_ptr;
    integrate_struct_ptr->dds_int_prev_output_low_ptr     = integrate_low_output_ptr;
}

/*******************************************************************************
*  Function name:  DDS_M_SUM_S32EXT32
*
*  Description :
*  The following function is used to integrate data without resolution lost.
*
*
*  Where:
*   't_dds_m_sum_s32ext32' is the structure associated to macro
*   'input_value' is the input value to ingrate
*
*  Output: is the integration result
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_SUM_S32EXT32(
        CONSTP2VAR(t_dds_m_sum_s32ext32, AUTOMATIC, AUTOMATIC) sum_struct_ptr,
        sint32 input_value)
{
    sint32 low;
    sint32 low_increment;
    sint32 high;
    sint32 high_increment;
    sint32 step;
    sint32 saturation_min;
    sint32 saturation_max;

    low = (*sum_struct_ptr).dds_sum_prev_low;
    high = (*sum_struct_ptr).dds_sum_prev_high;
    step = (sint32)sum_struct_ptr->dds_sum_step;
    saturation_min = sum_struct_ptr->dds_sum_saturation_min;
    saturation_max = sum_struct_ptr->dds_sum_saturation_max;

    high_increment = 0;
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "dds_sum_step".</2834></PRQA_COMMENT> */
    low_increment = input_value % step;
    if(low_increment == 0)
    {
        /* Nothing to do */
    }
    else if(low_increment > 0)
    {
        if(low <= (DDS_SINT32_MAX - low_increment))
        {
            low = low + low_increment;
        }
        else
        {
            high_increment = 1;
            low = low - step;
            low = low + low_increment;
        }
    }
    else
    {
        if(low >= (DDS_SINT32_MIN_FULL - low_increment ))
        {
            low = low + low_increment;
        }
        else
        {
            high_increment = -1;
            low = low + step;
            low = low + low_increment;
        }
    }
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "dds_sum_step".</2834></PRQA_COMMENT> */
    high_increment = high_increment + (low / step);
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "dds_sum_step".</2834></PRQA_COMMENT> */
    low = low % step;

/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "dds_sum_step".</2834></PRQA_COMMENT> */
    high_increment = high_increment + (input_value / step);
    if(high_increment == 0)
    {
        /* Nothing to do */
    }
    else if(high_increment > 0)
    {
        if(high < (saturation_max - high_increment))
        {
            high = high + high_increment;
        }
        else
        {
            high = saturation_max;
            low = 0;
        }
    }
    else
    {
        if(high > (saturation_min - high_increment))
        {
            high = high + high_increment;
        }
        else
        {
            high = saturation_min;
            low = 0;
        }
    }

    (*sum_struct_ptr).dds_sum_prev_low = low;
    (*sum_struct_ptr).dds_sum_prev_high = high;
    return high;
}


/*******************************************************************************
*  Function name:  DDS_M_SUM_S32EXT32_INIT
*
*  Description :
*  The following function is used to initialise the integration data.
*
*
*  Where:
*   't_dds_m_sum_s32ext32' is the structure associated to macro
*   'high_output_init_value' is high output init data
*   'low_output_init_value' is low output init data
*   'step' is the input resolution divide by output resolution
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SUM_S32EXT32_INIT(
        CONSTP2VAR(t_dds_m_sum_s32ext32, AUTOMATIC, AUTOMATIC) sum_struct_ptr,
        sint32 high_output_init_value,
        sint32 low_output_init_value,
        uint32 step)
{
    (*sum_struct_ptr).dds_sum_prev_high = high_output_init_value;
    (*sum_struct_ptr).dds_sum_prev_low = low_output_init_value;
    if (0 == step)
    {
        sum_struct_ptr->dds_sum_step = 1;
    }
    else if(step > DDS_SINT32_MAX)
    {
        sum_struct_ptr->dds_sum_step = DDS_SINT32_MAX;
    }
    else
    {
        sum_struct_ptr->dds_sum_step = step;
    }
    sum_struct_ptr->dds_sum_saturation_min = DDS_SINT32_MIN_FULL;
    sum_struct_ptr->dds_sum_saturation_max = DDS_SINT32_MAX;
}

/*******************************************************************************
*  Function name:  DDS_M_SUM_S32EXT32_SAT_INIT
*
*  Description :
*  The following function is used to initialise the integration data.
*
*
*  Where:
*   't_dds_m_sum_s32ext32' is the structure associated to macro
*   'high_output_init_value' is high output init data
*   'low_output_init_value' is low output init data
*   'step' is the input resolution divide by output resolution
*   'saturation_min' is the min value of output
*   'saturation_max' is the max value of output
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SUM_S32EXT32_SAT_INIT(
            CONSTP2VAR(t_dds_m_sum_s32ext32, AUTOMATIC, AUTOMATIC) sum_struct_ptr,
            sint32 high_output_init_value,
            sint32 low_output_init_value,
            uint32 step,
            sint32 saturation_min,
            sint32 saturation_max)
{
    (*sum_struct_ptr).dds_sum_prev_high = high_output_init_value;
    (*sum_struct_ptr).dds_sum_prev_low = low_output_init_value;
    if (0 == step)
    {
        sum_struct_ptr->dds_sum_step = 1;
    }
    else if(step > DDS_SINT32_MAX)
    {
        sum_struct_ptr->dds_sum_step = DDS_SINT32_MAX;
    }
    else
    {
        sum_struct_ptr->dds_sum_step = step;
    }
    sum_struct_ptr->dds_sum_saturation_min = saturation_min;
    sum_struct_ptr->dds_sum_saturation_max = saturation_max;
}

/*******************************************************************************
*  Macro name:  DDS_M_CHECK_DELTA16
*
*  Description :
*  The following macro is used to check the delta between the last and the new
*  input value
*
*  If |input_value - last_value| is greater than delta_max then
*   Return DDS_TRUE
*  Else
*   Return DDS_FALSE
*
*  Where:
*   check_delta16_struct_ptr is the structure associated to macro
*   input_value is the input value
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_CHECK_DELTA16(
/* <PRQA_COMMENT><3673> In order to have flexibility, it has been decided to use pointer on variable
and not constant. In addition for compatibility reason this implementation is kept. </3673></PRQA_COMMENT> */
        CONSTP2VAR(t_dds_m_check_delta16, AUTOMATIC, AUTOMATIC) check_delta16_struct_ptr,
        uint16 input_value )
{
    uint16 delta_tmp;
    uint8 delta_max_reached;

    if ((t_dds_m_uint)check_delta16_struct_ptr->dds_delta_prev_output > (t_dds_m_uint)input_value)
    {
        delta_tmp = (uint16)((t_dds_m_uint)check_delta16_struct_ptr->dds_delta_prev_output - (t_dds_m_uint)input_value);
    }
    else
    {
        delta_tmp = (uint16)((t_dds_m_uint)input_value - (t_dds_m_uint)check_delta16_struct_ptr->dds_delta_prev_output);
    }

    if ((t_dds_m_uint)delta_tmp > (t_dds_m_uint)check_delta16_struct_ptr->dds_delta_max)
    {
        delta_max_reached = DDS_TRUE;
    }
    else
    {
        delta_max_reached = DDS_FALSE;
    }
    return delta_max_reached;
}

/*******************************************************************************
*  Macro name:  DDS_M_CHECK_DELTA16_INIT
*
*  Description :
*  The following macro manage reset of macro DDS_M_CHECK_DELTA16
*
*  Where:
*   check_delta16_struct_ptr is the structure associated to macro
*   init_value is the init value of output
*   delta_max_value is the value of maximum delta
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_CHECK_DELTA16_INIT(
        CONSTP2VAR(t_dds_m_check_delta16, AUTOMATIC, AUTOMATIC) check_delta16_struct_ptr,
        uint16 init_value,
        uint16 delta_max_value )
{
    check_delta16_struct_ptr->dds_delta_prev_output = init_value;
    check_delta16_struct_ptr->dds_delta_max = delta_max_value;

    return(init_value);
}


/*******************************************************************************
*  Macro name:  DDS_M_CALC_MEAN_BUFFER
*
*  Description :
*   The following macro is used to calculate the mean value on "nb_data_for_mean"
*   data present in buffer. "input_value" data is added to the roll-over buffer
*   before the mean calculation is done.
*
*  Where:
*   - calc_mean_buffer_ptr is the structure associated to macro
*   - input_value is the signal used to compute the mean value
*   - nb_data_for_mean is the number of data use for the mean calculation
*
*  REMARKS
*   No check is done on parameters.
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_CALC_MEAN_BUFFER(
        CONSTP2VAR(t_dds_m_calc_mean_buffer, AUTOMATIC, AUTOMATIC) calc_mean_buffer_ptr,
        uint16 input_value,
        uint8  nb_data_for_mean )
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) dest_ptr;
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) src_ptr;
    t_dds_m_uint i;
    t_dds_m_uint max_size;
    uint32 sum;
    uint16 mean;

    if ((t_dds_m_uint)calc_mean_buffer_ptr->dds_cmb_size <= (t_dds_m_uint)1)
    {
        mean = calc_mean_buffer_ptr->dds_cmb_buffer_ptr[0];
    }
    else
    {
        max_size = (t_dds_m_uint)calc_mean_buffer_ptr->dds_cmb_size - (t_dds_m_uint)1;
        dest_ptr = &(calc_mean_buffer_ptr->dds_cmb_buffer_ptr[max_size]);
        src_ptr  = &(calc_mean_buffer_ptr->dds_cmb_buffer_ptr[max_size-1]);

        for (i=0; i<max_size ; i++)
        {
            *dest_ptr = *src_ptr;
            dest_ptr--;
            src_ptr--;
        }
        *dest_ptr = input_value;

        if ((t_dds_m_uint)0 == (t_dds_m_uint)nb_data_for_mean)
        {
            mean = input_value;
        }
        else
        {
            sum = 0;
            for (i=0; i<(t_dds_m_uint)nb_data_for_mean; i++)
            {
                sum += (uint32)*dest_ptr;
                dest_ptr++;
            }
            mean = (uint16)DDS_M_MIN((sum / (uint32)nb_data_for_mean), DDS_UINT16_MAX);
        }
    }
    return(mean);
}

/*******************************************************************************
*  Macro name:  DDS_M_CALC_MEAN_BUFFER_INIT
*
*  Description :
*   The following macro manage reset of macro DDS_M_CALC_MEAN_BUFFER
*   It returns the mean calculated on the
*
*  Where:
*   - calc_mean_buffer_ptr is the structure associated to macro
*   - tab_ptr is the pointer on the buffer use for mean calculation
*   - tab_init is the initialization vector
*   - tab_size is the size of the mean calculation buffer
*   - nb_data_for_mean is the number of data use for the mean calculation
*
*  REMARKS
*   No check is done on parameters.
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_CALC_MEAN_BUFFER_INIT(
        CONSTP2VAR(t_dds_m_calc_mean_buffer, AUTOMATIC, AUTOMATIC) calc_mean_buffer_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_ptr,
/* <PRQA_COMMENT><3673> In order to have flexibility, it has been decided to use pointer on variable
and not constant. In addition for compatibility reason this implementation is kept. </3673></PRQA_COMMENT> */
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_init_ptr,
        uint8 tab_size,
        uint8 nb_data_for_mean)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) temp_ptr;
    t_dds_m_uint i;
    uint32 sum;
    uint16 mean;

    calc_mean_buffer_ptr->dds_cmb_buffer_ptr  = tab_ptr;
    calc_mean_buffer_ptr->dds_cmb_size        = tab_size;

    /* Initialise table */
    for (i=0; i < (t_dds_m_uint)tab_size; i++)
    {
        *tab_ptr = *tab_init_ptr;
        tab_ptr++;
        tab_init_ptr++;
    }

    temp_ptr = calc_mean_buffer_ptr->dds_cmb_buffer_ptr;

    if ((t_dds_m_uint)0 == (t_dds_m_uint)nb_data_for_mean)
    {
        mean = *temp_ptr;
    }
    else
    {
        sum = 0;
        for (i=0; i<(t_dds_m_uint)nb_data_for_mean; i++)
        {
            sum += (uint32)*temp_ptr;
            temp_ptr++;
        }
        mean = (uint16)DDS_M_MIN((sum / (uint32)nb_data_for_mean), DDS_UINT16_MAX);
    }
    return(mean);
}


/*******************************************************************************
*  Macro name:  DDS_M_U16_CALC_MEAN_SHIFTED_V1
*
*  Description :
*   The following macro is used to calculate the mean value on "nb_data_for_mean"
*   data present in buffer. "input_value" data is added to the roll-over buffer
*   before the mean calculation is done.
*
*  Where:
*   - calc_mean_buffer_ptr is the structure associated to macro
*   - input_value is the signal used to compute the mean value
*   - nb_data_for_mean is the number of data use for the mean calculation
*
*  REMARKS
*   No check is done on parameters.
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_U16_CALC_MEAN_SHIFTED_V1(
        CONSTP2VAR(t_dds_m_u16_calc_mean_shifted, AUTOMATIC, AUTOMATIC) calc_mean_shifted_ptr,
        uint16 input_value,
        uint8  nb_data_for_mean )
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) dest_ptr;
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) src_ptr;
    t_dds_m_uint i;
    uint32 max_size;
    uint32 sum;
    uint16 mean;

    if ((uint32)calc_mean_shifted_ptr->dds_cmb_size <= (uint32)1)
    {
        mean = calc_mean_shifted_ptr->dds_cmb_buffer_ptr[0];
    }
    else
    {
        max_size = (uint32)calc_mean_shifted_ptr->dds_cmb_size - (uint32)1;
        dest_ptr = &(calc_mean_shifted_ptr->dds_cmb_buffer_ptr[max_size]);
        src_ptr  = &(calc_mean_shifted_ptr->dds_cmb_buffer_ptr[max_size-1]);
        /* 1st: shift buffer and add new value */
        for (i=0; i<max_size ; i++)
        {
            *dest_ptr = *src_ptr;
            dest_ptr--;
            src_ptr--;
        }
        *dest_ptr = input_value;

        /* 2nd: mean's calculations */
        if ((t_dds_m_uint)0 == (t_dds_m_uint)nb_data_for_mean)
        {
            mean = input_value;
        }
        else
        {
            sum = 0;
            if  ((t_dds_m_uint)nb_data_for_mean > (t_dds_m_uint)calc_mean_shifted_ptr->dds_cmb_size)
            {
                nb_data_for_mean = calc_mean_shifted_ptr->dds_cmb_size;
            }
            else
            {
                /* Do nothing */
            }
            for (i=0; i<(t_dds_m_uint)nb_data_for_mean; i++)
            {
                sum += (uint32)*dest_ptr;
                dest_ptr++;
            }
/* <PRQA_COMMENT><2833> nb_data_for_mean will never be equal to 0 </2833></PRQA_COMMENT> */
            mean = (uint16)DDS_M_MIN((sum / (uint32)nb_data_for_mean), DDS_UINT16_MAX);
        }
    }
    return(mean);
}

/*******************************************************************************
*  Macro name:  DDS_M_U16_CALC_MEAN_SHIFTED_V1_INIT
*
*  Description :
*   The following macro manage reset of macro DDS_M_CALC_MEAN_BUFFER
*   It returns the mean calculated on the
*
*  Where:
*   - calc_mean_buffer_ptr is the structure associated to macro
*   - tab_ptr is the pointer on the buffer use for mean calculation
*   - tab_init is the initialization vector
*   - tab_size is the size of the mean calculation buffer
*   - nb_data_for_mean is the number of data use for the mean calculation
*
*  REMARKS
*   No check is done on parameters.
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_U16_CALC_MEAN_SHIFTED_V1_INIT(
        CONSTP2VAR(t_dds_m_u16_calc_mean_shifted, AUTOMATIC, AUTOMATIC) calc_mean_shifted_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_ptr,
        uint16 first_value,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_init_ptr,
        uint8 tab_size,
        uint8 nb_data_for_mean)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) temp_ptr;
    t_dds_m_uint i;
    uint32 sum;
    uint16 mean;

    calc_mean_shifted_ptr->dds_cmb_buffer_ptr  = tab_ptr;
    calc_mean_shifted_ptr->dds_cmb_size        = tab_size;

    /* Calulate mean on input buffer */
    if ((t_dds_m_uint)0 == (t_dds_m_uint)nb_data_for_mean)
    {
        mean = first_value;
    }
    else
    {
        sum = 0;
        temp_ptr = tab_init_ptr;
        if ((t_dds_m_uint)nb_data_for_mean > (t_dds_m_uint)calc_mean_shifted_ptr->dds_cmb_size)
        {
            nb_data_for_mean = calc_mean_shifted_ptr->dds_cmb_size;
        }
        else
        {
            /* Do nothing */
        }
        for (i=0; i<(t_dds_m_uint)nb_data_for_mean; i++)
        {
            sum += (uint32)*temp_ptr;
            temp_ptr++;
        }
/* <PRQA_COMMENT><2833> nb_data_for_mean will never be equal to 0 </2833></PRQA_COMMENT> */
        sum /= (uint32)nb_data_for_mean;
        mean = (uint16)DDS_M_MIN(sum, DDS_UINT16_MAX);
    }

    /* Initialise buffer */
    /* First element with entry */
    *tab_ptr = first_value;
    tab_ptr++;
    /* Following element with table */
    tab_size = (uint8)((t_dds_m_uint)tab_size - (t_dds_m_uint)1);
    for (i=0; i < (t_dds_m_uint)tab_size; i++)
    {
        *tab_ptr = *tab_init_ptr;
        tab_ptr++;
        tab_init_ptr++;
    }

    return(mean);
}

/*******************************************************************************
*  Macro name:  DDS_M_U16_CALC_MEAN_SHIFTED_V2_INIT
*
*  Description :
*   The following macro manage reset of macro DDS_M_CALC_MEAN_BUFFER
*   It returns the mean calculated on the
*
*  Where:
*   - calc_mean_buffer_ptr is the structure associated to macro
*   - tab_ptr is the pointer on the buffer use for mean calculation
*   - tab_init is the initialization vector
*   - tab_size is the size of the mean calculation buffer
*   - nb_data_for_mean is the number of data use for the mean calculation
*
*  REMARKS
*   No check is done on parameters.
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_U16_CALC_MEAN_SHIFTED_V2_INIT(
        CONSTP2VAR(t_dds_m_u16_calc_mean_shifted, AUTOMATIC, AUTOMATIC) calc_mean_shifted_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_init_ptr,
        uint8 tab_size,
        uint8 nb_data_for_mean)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) temp_ptr;
    t_dds_m_uint i;
    uint32 sum;
    uint16 mean;

    calc_mean_shifted_ptr->dds_cmb_buffer_ptr  = tab_ptr;
    calc_mean_shifted_ptr->dds_cmb_size        = tab_size;

    /* Calulate mean on input buffer */
    if ((t_dds_m_uint)0 == (t_dds_m_uint)nb_data_for_mean)
    {
        mean = *tab_init_ptr;
    }
    else
    {
        sum = 0;
        temp_ptr = tab_init_ptr;
        if ((t_dds_m_uint)nb_data_for_mean > (t_dds_m_uint)calc_mean_shifted_ptr->dds_cmb_size)
        {
            nb_data_for_mean = calc_mean_shifted_ptr->dds_cmb_size;
        }
        else
        {
            /* Do nothing */
        }
        for (i=0; i<(t_dds_m_uint)nb_data_for_mean; i++)
        {
            sum += (uint32)*temp_ptr;
            temp_ptr++;
        }
/* <PRQA_COMMENT><2833> nb_data_for_mean will never be equal to 0 </2833></PRQA_COMMENT> */
        sum /= (uint32)nb_data_for_mean;
        mean = (uint16)DDS_M_MIN(sum, DDS_UINT16_MAX);
    }

    /* Initialise buffer */
    for (i=0; i < (t_dds_m_uint)tab_size; i++)
    {
        *tab_ptr = *tab_init_ptr;
        tab_ptr++;
        tab_init_ptr++;
    }

    return(mean);
}


/*******************************************************************************
*  Function name:  DDS_M_SLEW_S32
*
*  Description :
*  The following macro will slew a variable using an up_rate and down_rate
*
*  If input is greater than previous_output + up_rate then
*   Return previous_output + up_rate
*  Else If input is less than previous_output - down_rate then
*   Return previous_output - down_rate
*  Else
*   Return input.
*
*
*  Where:
*   slew_struct_ptr is the structure associated to macro
*   input is the target value
*   up_rate is the increment of slew
*   down_rate is the decrement of slew
*
*  REMARKS:
*   input, up_rate and down_rate must all be of the same BIN Point
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_SLEW_S32( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC) slew_struct_ptr,
                                        sint32 input,
                                        uint32 up_rate,
                                        uint32 down_rate )
{
    uint32 delta;

    /* Check delta overflow */
    if(input >= slew_struct_ptr->prev_output.prev_S32)
    {
        delta = (uint32)input - (uint32)(slew_struct_ptr->prev_output.prev_S32);
        if( delta > up_rate)
        {
            slew_struct_ptr->prev_output.prev_S32 += (sint32)up_rate;
        }
        else
        {
            slew_struct_ptr->prev_output.prev_S32 = input;
        }
    }
    else
    {
        delta = (uint32)(slew_struct_ptr->prev_output.prev_S32) - (uint32)input;
        if(delta > down_rate)
        {
            slew_struct_ptr->prev_output.prev_S32 -= (sint32)down_rate;
        }
        else
        {
            slew_struct_ptr->prev_output.prev_S32 = input;
        }
    }


    return (slew_struct_ptr->prev_output.prev_S32);
}



/*******************************************************************************
*  Macro name:  DDS_M_SLEW_S32_INIT
*
*  Description :
*  The following macro manage init of DDS_M_SLEW_S32 macro
*
*  previous_output = init_value
*
*  Where:
*   slew_struct_ptr is the structure associated to macro
*   init_value is the init value of hysteresis
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_SLEW_S32_INIT( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC) slew_struct_ptr,
                                             sint32 init_value )
{
    slew_struct_ptr->prev_output.prev_S32   = init_value;

    return(init_value);
}


/*******************************************************************************
*  Function name:  DDS_M_SLEW_U32
*
*  Description :
*  The following macro will slew a variable using an up_rate and down_rate
*
*  If input is greater than previous_output + up_rate then
*   Return previous_output + up_rate
*  Else If input is less than previous_output - down_rate then
*   Return previous_output - down_rate
*  Else
*   Return input.
*
*
*  Where:
*   slew_struct_ptr is the structure associated to macro
*   input is the target value
*   up_rate is the increment of slew
*   down_rate is the decrement of slew
*
*  REMARKS:
*   input, up_rate and down_rate must all be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SLEW_U32( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC)slew_struct_ptr,
                                        uint32 input,
                                        uint32 up_rate,
                                        uint32 down_rate )
{
    uint32 delta;

    /* Check delta overflow */
    if(input >= slew_struct_ptr->prev_output.prev_U32)
    {
        delta = input - slew_struct_ptr->prev_output.prev_U32;
        if( delta > up_rate)
        {
            slew_struct_ptr->prev_output.prev_U32 += up_rate;
        }
        else
        {
            slew_struct_ptr->prev_output.prev_U32 = input;
        }
    }
    else
    {
        delta = slew_struct_ptr->prev_output.prev_U32 - input;
        if(delta > down_rate)
        {
            slew_struct_ptr->prev_output.prev_U32 -= down_rate;
        }
        else
        {
            slew_struct_ptr->prev_output.prev_U32 = input;
        }
    }
    return (slew_struct_ptr->prev_output.prev_U32);
}

/*******************************************************************************
*  Macro name:  DDS_M_SLEW_U32_INIT
*
*  Description :
*  The following macro manage init of DDS_M_SLEW_U32 macro
*
*  previous_output = init_value
*
*  Where:
*   slew_struct_ptr is the structure associated to macro
*   init_value is the init value of hysteresis
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SLEW_U32_INIT( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC)slew_struct_ptr,
                                             uint32 init_value )
{
    slew_struct_ptr->prev_output.prev_U32   = init_value;

    return(init_value);
}


/*******************************************************************************
*  Macro name:  DDS_M_BARY_FILTER_S16
*
* out = in_coef_bary/bp_filter_factor)  * inp_bary_1 + (1 - (in_coef_bary/bp_filter_factor)) * inp_bary_2
*
*  Description :
*  The following macro
*
*  Where:
*   inp_bary_1 : input1
*   inp_bary_2 : input2
*   in_coef_bary : weigth coefficient
*   bp_filter_factor : filter factor binary point (ex: if in_coef_bary = [0; 100] BIN7
*                                                      bp_filter_factor = 100 * BIN7)
*
* Important : inp_bary_1 and inp_bary_2  must have the same Binpoint!!!
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_BARY_FILTER_S16(sint16 inp_bary_1,
                                              sint16 inp_bary_2,
                                              sint16 in_coef_bary,
                                              uint16 bp_filter_factor)
{
    sint32 out_bary;
    sint32 out_tmp1;
    sint32 out_tmp2;

    if (0 == (t_dds_m_sint)in_coef_bary)
    {
        out_bary = (sint32)inp_bary_2;
    }
    else if ((sint32)bp_filter_factor == (sint32)in_coef_bary)
    {
        out_bary = (sint32)inp_bary_1;
    }
    else
    {
        out_tmp1 = (sint32)in_coef_bary  *  (sint32)inp_bary_1;
        out_tmp2 = ((sint32)bp_filter_factor - (sint32)in_coef_bary) * (sint32)inp_bary_2;
        out_bary = DDS_M_ADDITION_S32(out_tmp1, out_tmp2);

        /* OUt_bary/bp_filter_factor -> +inf ? */
        if (out_bary >= ((sint32)bp_filter_factor * (sint32)DDS_SINT16_MAX))
        {
            out_bary = (sint32)DDS_SINT16_MAX;
        }
        /* OUt_bary/bp_filter_factor -> -inf ? */
        else if (out_bary <= ((sint32)bp_filter_factor * (sint32)DDS_SINT16_MIN))
        {
            out_bary = (sint32)DDS_SINT16_MIN;
        }
        else
        {
            /* Due to previous variables tests */
            /* division by zero is not possible here */
            out_bary = out_bary / (sint32)bp_filter_factor;
        }
    }
    return((sint16)DDS_M_LIMIT(out_bary, (sint32)DDS_SINT16_MIN, (sint32)DDS_SINT16_MAX));
}


/*******************************************************************************
*  Macro name:  DDS_M_BARY_FILTER_S32
*
* out = in_coef_bary/bp_filter_factor)  * inp_bary_1 + (1 - (in_coef_bary/bp_filter_factor)) * inp_bary_2
*
*  Description :
*  The following macro
*
*  Where:
*   inp_bary_1 : input1
*   inp_bary_2 : input2
*   in_coef_bary : weigth coefficient
*   bp_filter_factor : filter factor binary point (ex: if in_coef_bary = [0; 100] BIN7
*                                                      bp_filter_factor = 100 * BIN7)
*
* WARNING :
*   1/ inp_bary_1 and inp_bary_2  must have the same Binpoint!!!
*   2/ -(2^31) is used instead of"DDS_SINT32_MIN", in consequence if these 2
*       values are different a limit should be use after the use of this function.
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_BARY_FILTER_S32(sint32 inp_bary_1,
                                              sint32 inp_bary_2,
                                              uint16 in_coef_bary,
                                              uint16 bp_filter_factor)
{
    sint32 delta;
    sint32 delta_test;
    sint32 out_bary;
    sint32 out_tmp1;
    sint32 out_tmp2;
    sint32 error_result;
    sint32 out_bary_tmp;

    if ((t_dds_m_uint)0 == (t_dds_m_uint)in_coef_bary)
    {
        out_bary = inp_bary_2;
    }
    else if ((sint32)bp_filter_factor == (sint32)in_coef_bary)
    {
        out_bary = inp_bary_1;
    }
    else if(inp_bary_1 == inp_bary_2)
    {
        out_bary = inp_bary_2;
    }
    else /* bp_filter_factor != in_coef_bary != 0, inp_bary_1 != inp_bary_2 */
    {
        delta_test = (inp_bary_1/2) - (inp_bary_2/2);
        if (    (((DDS_SINT32_MIN_FULL/2) + 1) <= delta_test)
            &&  (delta_test <= ((DDS_SINT32_MAX/2) -1)) )       /* SINT32_MIN <= delta <= SINT32_MAX  ? */
        {
            delta = inp_bary_1 - inp_bary_2;

            /* (a*b) / c = (a/ c) * b + ((a%c) * b / c) */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
            out_tmp1 = delta / (sint32)bp_filter_factor;
            if(out_tmp1 >= (DDS_SINT32_MAX/(sint32)in_coef_bary))
            {
                out_tmp2 = DDS_SINT32_MAX;
            }
            else if(out_tmp1 <= (DDS_SINT32_MIN_FULL/(sint32)in_coef_bary))
            {
                out_tmp2 = DDS_SINT32_MIN_FULL;
            }
            else
            {
                out_tmp2 = out_tmp1 * (sint32)in_coef_bary;
            }
            error_result = ((delta%(sint32)bp_filter_factor) * (sint32)in_coef_bary)/(sint32)bp_filter_factor;
            out_bary_tmp = DDS_M_ADDITION_S32(out_tmp2, error_result);
        }
        else    /* delta > sint32 --> reduction of resolution*/
        {
            delta = delta_test;

            /* (a*b) / c = (a/ c) * b + (a%c) * (b / c) */
            out_tmp1 = delta / (sint32)bp_filter_factor;
            if(out_tmp1 >= (DDS_SINT32_MAX/(sint32)in_coef_bary))
            {
                out_tmp2 = DDS_SINT32_MAX;
            }
            else if(out_tmp1 <= (DDS_SINT32_MIN_FULL/(sint32)in_coef_bary))
            {
                out_tmp2 = DDS_SINT32_MIN_FULL;
            }
            else
            {
                out_tmp2 = out_tmp1 * (sint32)in_coef_bary;
            }
            error_result = ((delta%(sint32)bp_filter_factor) * (sint32)in_coef_bary)/(sint32)bp_filter_factor;
            out_bary_tmp = DDS_M_ADDITION_S32(out_tmp2, error_result);
            if( (out_bary_tmp < (DDS_SINT32_MAX/2)) && (out_bary_tmp > (DDS_SINT32_MIN/2)))
            {
                out_bary_tmp *= 2; /* restor precision */
            }
            else
            {
                /* do nothing */
            }
        }
        out_bary = DDS_M_ADDITION_S32(out_bary_tmp, inp_bary_2);
    }
    return(out_bary);
}


/*******************************************************************************
*  Macro name:  DDS_M_BARY_FILTER_S16_V2
*
* out = in_coef_bary/bp_filter_factor)  * inp_bary_1 + (1 - (in_coef_bary/bp_filter_factor)) * inp_bary_2
*
*  Description :
*  The following macro
*
*  Where:
*   inp_bary_1 : input1
*   inp_bary_2 : input2
*   in_coef_bary : weigth coefficient
*   bp_filter_factor : filter factor binary point (ex: if in_coef_bary = [0; 100] BIN7
*                                                      bp_filter_factor = 100 * BIN7)
*
* Important : inp_bary_1 and inp_bary_2  must have the same Binpoint!!!
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_BARY_FILTER_S16_V2(sint16 inp_bary_1,
                                              sint16 inp_bary_2,
                                              sint16 in_coef_bary,
                                              uint16 bp_filter_factor)
{
    sint32 out_bary;
    sint32 out_tmp1;
    sint32 out_tmp2;

    if (0 >= (t_dds_m_sint)in_coef_bary)
    {
        out_bary = (sint32)inp_bary_2;
    }
    else if ((sint32)bp_filter_factor <= (sint32)in_coef_bary)
    {
        out_bary = (sint32)inp_bary_1;
    }
    else
    {
        out_tmp1 = (sint32)in_coef_bary  *  (sint32)inp_bary_1;
        out_tmp2 = ((sint32)bp_filter_factor - (sint32)in_coef_bary) * (sint32)inp_bary_2;
        out_bary = DDS_M_ADDITION_S32(out_tmp1, out_tmp2);

        out_bary = out_bary / (sint32)bp_filter_factor;

    }
    return((sint16)out_bary);
}

/*******************************************************************************
*  Macro name:  DDS_M_BARY_FILTER_S32_V2
*
* out = in_coef_bary/bp_filter_factor)  * inp_bary_1 + (1 - (in_coef_bary/bp_filter_factor)) * inp_bary_2
*
*  Description :
*  The following macro
*
*  Where:
*   inp_bary_1 : input1
*   inp_bary_2 : input2
*   in_coef_bary : weigth coefficient
*   bp_filter_factor : filter factor binary point (ex: if in_coef_bary = [0; 100] BIN7
*                                                      bp_filter_factor = 100 * BIN7)
*
* WARNING :
*   1/ inp_bary_1 and inp_bary_2  must have the same Binpoint!!!
*   2/ -(2^31) is used instead of"DDS_SINT32_MIN", in consequence if these 2
*       values are different a limit should be use after the use of this function.
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_BARY_FILTER_S32_V2(sint32 inp_bary_1,
                                              sint32 inp_bary_2,
                                              uint16 in_coef_bary,
                                              uint16 bp_filter_factor)
{
    sint32 delta;
    sint32 delta_test;
    sint32 out_bary;
    sint32 out_tmp1;
    sint32 out_tmp2;
    sint32 error_result;
    sint32 out_bary_tmp;

    if ((t_dds_m_uint)0 >= (t_dds_m_uint)in_coef_bary)
    {
        out_bary = inp_bary_2;
    }
    else if ((sint32)bp_filter_factor <= (sint32)in_coef_bary)
    {
        out_bary = inp_bary_1;
    }
    else if(inp_bary_1 == inp_bary_2)
    {
        out_bary = inp_bary_2;
    }
    else /* bp_filter_factor != in_coef_bary != 0, inp_bary_1 != inp_bary_2 */
    {
        delta_test = (inp_bary_1/2) - (inp_bary_2/2);
        if (    (((DDS_SINT32_MIN_FULL/2) + 1) <= delta_test)
            &&  (delta_test <= ((DDS_SINT32_MAX/2) -1)) )       /* SINT32_MIN <= delta <= SINT32_MAX  ? */
        {
            delta = inp_bary_1 - inp_bary_2;

            /* (a*b) / c = (a/ c) * b + ((a%c) * b / c) */
            out_tmp1 = delta / (sint32)bp_filter_factor;
            out_tmp2 = out_tmp1 * (sint32)in_coef_bary;

            error_result = ((delta%(sint32)bp_filter_factor) * (sint32)in_coef_bary)/(sint32)bp_filter_factor;
            out_bary_tmp = DDS_M_ADDITION_S32(out_tmp2, error_result);
            out_bary = DDS_M_ADDITION_S32(out_bary_tmp, inp_bary_2);
        }
        else    /* delta > sint32 --> reduction of resolution*/
        {
            delta = delta_test;

            /* (a*b) / c = (a/ c) * b + (a%c) * (b / c) */
            out_tmp1 = delta / (sint32)bp_filter_factor;
            out_tmp2 = out_tmp1 * (sint32)in_coef_bary;

            error_result = ((delta%(sint32)bp_filter_factor) * (sint32)in_coef_bary)/(sint32)bp_filter_factor;
            out_bary_tmp = DDS_M_ADDITION_S32(out_tmp2, error_result);
            if( (out_bary_tmp < (DDS_SINT32_MAX/2)) && (out_bary_tmp > (DDS_SINT32_MIN/2)))
            {
                out_bary_tmp *= 2; /* restor precision */
                out_bary = DDS_M_ADDITION_S32(out_bary_tmp, inp_bary_2);
            }
            else
            {
                /* do nothing */
                out_bary = DDS_M_ADDITION_S32(out_bary_tmp, inp_bary_2/2);
                out_bary *= 2; /* restor precision */
            }
        }
    }
    return(out_bary);
}


/*******************************************************************************
*  Function name:  DDS_M_CHRONOMETER_U32
*
*  Description :
*  The following function is used to perform a stop watch function.
*
*  The output indicates the time for which clock is enabled
*  since the last reset.
*
*  Where:
*   chrono_struct_ptr is the pointer to the structure associated with the macro
*   current_time is the current time
*   enable_cond is the stop watch enable signal
*
*  REMARKS:
*   current_time and output must be of same unit and precision.
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_CHRONOMETER_U32( CONSTP2VAR(t_dds_m_chrono_u32, AUTOMATIC, AUTOMATIC) chrono_struct_ptr,
                                               uint32 current_time,
                                               uint8 enable_cond )
{
    uint32 delta_time;

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)chrono_struct_ptr->dds_chrono_previous_enable)
    {
        delta_time = (current_time - chrono_struct_ptr->dds_chrono_previous_time);

        if(chrono_struct_ptr->dds_chrono_previous_output <= (DDS_UINT32_MAX - delta_time))
        {
            chrono_struct_ptr->dds_chrono_previous_output += delta_time;
        }
        else
        {
            chrono_struct_ptr->dds_chrono_previous_output = DDS_UINT32_MAX;
        }
    }
    else
    {
        /* Do nothing */
    }
    chrono_struct_ptr->dds_chrono_previous_enable = enable_cond;
    chrono_struct_ptr->dds_chrono_previous_time = current_time;

    return(chrono_struct_ptr->dds_chrono_previous_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_CHRONOMETER_U32_INIT
*
*  Description :
*  The following macro manages the init and reset of M_CHRONOMETER_U32 macro
*
*  Where:
*   chrono_struct_ptr is the pointer to the structure associated with the macro
*   init_value is the init value of chronometer
*   current_time is the current time
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_CHRONOMETER_U32_INIT( CONSTP2VAR(t_dds_m_chrono_u32, AUTOMATIC, AUTOMATIC) chrono_struct_ptr,
                                                    uint32 current_time,
                                                    uint32 init_value )
{
    chrono_struct_ptr->dds_chrono_previous_output = init_value;
    chrono_struct_ptr->dds_chrono_previous_time   = current_time;
    chrono_struct_ptr->dds_chrono_previous_enable = DDS_FALSE;

    return(chrono_struct_ptr->dds_chrono_previous_output);
}


/*******************************************************************************
*  Function name:  DDS_M_FILTER_LP1_U16
*
*  Description :
*  The following function apply a low pass 1st order filter to the input
*
*  result = previous_output + (target - previous_output)*filter_factor
*                                    / bp_filter_factor
*  previous_error = (target - previous_output) * filter_factor % bp_filter_factor
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   target is the input signal
*   filter_factor is the attenuation factor
*   bp_filter_factor is filter_factor binary point
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_FILTER_LP1_U16_INIT
*   it is assume that bp_filter_factor is different from zero
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             uint16 target,
                                             uint16 filter_factor,
                                             uint16 bp_filter_factor)
{
    sint32 temp ;
    sint32 temp_calc;
    sint32 delta;

    delta = (sint32)target - (sint32)filter_struct_ptr->previous_output.prev_U16;
    /* Test to check overflow on calculation. The >= allow to anticipe
       the prev_error */
    if ( (delta >= (sint32)DDS_SINT16_MAX ) && ((sint32)filter_factor >= (sint32)DDS_SINT16_MAX) )
    {
        /* overflow case */
        delta = delta / 2;

        /* temp = x/2 + prev_err/2 */
        temp = (delta * (sint32)filter_factor) + (filter_struct_ptr->previous_error / 2);

        /* error calculation = (temp % fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        filter_struct_ptr->previous_error = (temp % (sint32)bp_filter_factor) * 2;

        /* output calculation  = prev_out + (temp/fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = (sint32)filter_struct_ptr->previous_output.prev_U16 + ((temp/(sint32)bp_filter_factor) * 2);
    }
    else
    {

        temp = (delta * (sint32)filter_factor) + filter_struct_ptr->previous_error;

        /* error calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        filter_struct_ptr->previous_error = temp % (sint32)bp_filter_factor;

        /* output calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = (sint32)filter_struct_ptr->previous_output.prev_U16 + (temp / (sint32)bp_filter_factor);

    }

    filter_struct_ptr->previous_output.prev_U16 = (uint16)DDS_M_LIMIT(temp_calc,
                                                                    (sint32)DDS_UINT16_MIN,
                                                                    (sint32)DDS_UINT16_MAX);

    return filter_struct_ptr->previous_output.prev_U16 ; /* Return output */
}



/*******************************************************************************
*  Macro name:  DDS_M_FILTER_LP1_U16_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_FILTER_LP1_U16
*
*  previous_output = init_value
*  previous_error = 0
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   init_value is the init value
*
*  REMARKS:
*   This macro should be used each time a new filter order is launched with
*   DDS_M_FILTER_LP1_U16
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16_INIT(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                  uint16 init_value)
{
    filter_struct_ptr->previous_output.prev_U16 = init_value ;
    filter_struct_ptr->previous_error = 0 ;

    return(init_value);
}


/*******************************************************************************
*  Function name:  DDS_M_FILTER_LP1_V2_U16
*
*  Description :
*  The following function apply a low pass 1st order filter to the input
*
*  result = previous_output + (target - previous_output)*filter_factor
*                                    / bp_filter_factor
*  previous_error = (target - previous_output) * filter_factor % bp_filter_factor
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   target is the input signal
*   filter_factor is the attenuation factor
*   bp_filter_factor is filter_factor binary point
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_FILTER_LP1_U16_INIT
*   it is assume that bp_filter_factor is different from zero
*   the macro uses pointer to access on previous value and and error
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16_V2(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             uint16 target,
                                             uint16 filter_factor,
                                             uint16 bp_filter_factor)
{
    sint32 temp ;
    sint32 temp_calc;
    sint32 delta;
    sint32 prev;

    prev = (sint32)*(filter_struct_ptr->previous_output.prev_U16_ptr);
    delta = (sint32)target - prev;
    /* Test to check overflow on calculation. The >= allow to anticipe
       the prev_error */
    if ( (delta >= (sint32)DDS_SINT16_MAX ) && ((sint32)filter_factor >= (sint32)DDS_SINT16_MAX) )
    {
        /* overflow case */
        delta = delta / 2;

        /* temp = x/2 + prev_err/2 */
        temp = (delta * (sint32)filter_factor) + (*(filter_struct_ptr->previous_error_ptr) / 2);

        /* error calculation = (temp % fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        *(filter_struct_ptr->previous_error_ptr) = (temp % (sint32)bp_filter_factor) * 2;

        /* output calculation  = prev_out + (temp/fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = prev + ((temp/(sint32)bp_filter_factor) * 2);
    }
    else
    {

        temp = (delta * (sint32)filter_factor) + *(filter_struct_ptr->previous_error_ptr);

        /* error calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        *(filter_struct_ptr->previous_error_ptr) = temp % (sint32)bp_filter_factor;

        /* output calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = prev + (temp / (sint32)bp_filter_factor);

    }

    *(filter_struct_ptr->previous_output.prev_U16_ptr) = (uint16)DDS_M_LIMIT(temp_calc,
                                                                    (sint32)DDS_UINT16_MIN,
                                                                    (sint32)DDS_UINT16_MAX);

    return *(filter_struct_ptr->previous_output.prev_U16_ptr) ; /* Return output */
}

/*******************************************************************************
*  Macro name:  DDS_M_FILTER_LP1_U16_V2_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_FILTER_LP1_U16
*
*  previous_output = init_value
*  previous_error = 0
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   init_value is the init value
*
*  REMARKS:
*   This macro should be used each time a new filter order is launched with
*   DDS_M_FILTER_LP1_U16
*   it is assume that the pointer given to the fucntion are valid
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16_V2_INIT(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                     CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) prev_ptr,
                                                     CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) error_ptr,
                                                     uint16 init_value,
                                                     sint32 error)
{
    filter_struct_ptr->previous_output.prev_U16_ptr = prev_ptr;
    filter_struct_ptr->previous_error_ptr = error_ptr;
    *(filter_struct_ptr->previous_output.prev_U16_ptr) = init_value ;
    *(filter_struct_ptr->previous_error_ptr) = error;

    return(init_value);
}

/*******************************************************************************
*  Function name:  DDS_M_FILTER_LP1_S16
*
*  Description :
*  The following fucntion apply a low pass 1st order filter to the input
*
*  result = previous_output + (target - previous_output)*filter_factor
*                                    / bp_filter_factor
*  previous_error = (target - previous_output) * filter_factor % bp_filter_factor
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   target is the input signal
*   filter_factor is the attenuation factor
*   bp_filter_factor is filter_factor binary point
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_FILTER_LP1_S16_INIT
*   it is assume that bp_filter_factor is different from zero
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             sint16 target,
                                             uint16 filter_factor,
                                             uint16 bp_filter_factor)
{
    sint32 temp ;
    sint32 temp_calc;
    sint32 delta;

    delta = (sint32)target - (sint32)filter_struct_ptr->previous_output.prev_S16;
    /* Test to check overflow on calculation. The >= allow to anticipe
       the prev_error */
    if ( (delta >= (sint32)DDS_SINT16_MAX ) && ((sint32)filter_factor >= (sint32)DDS_SINT16_MAX) )
    {
        /* overflow case */
        delta = delta / 2;

        /* temp = x/2 + prev_err/2 */
        temp = (delta * (sint32)filter_factor) + (filter_struct_ptr->previous_error / 2);

        /* error calculation = (temp % fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        filter_struct_ptr->previous_error = (temp % (sint32)bp_filter_factor) * 2;

        /* output calculation  = prev_out + (temp/fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = (sint32)filter_struct_ptr->previous_output.prev_S16 + ((temp/(sint32)bp_filter_factor) * 2);
    }
    else
    {
        temp = (delta * (sint32)filter_factor) + filter_struct_ptr->previous_error;

        /* error calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        filter_struct_ptr->previous_error = temp % (sint32)bp_filter_factor;

        /* output calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = (sint32)filter_struct_ptr->previous_output.prev_S16 + (temp/(sint32)bp_filter_factor);


    }
    filter_struct_ptr->previous_output.prev_S16 = (sint16)DDS_M_LIMIT ( temp_calc,
                                                                        DDS_SINT16_MIN,
                                                                        DDS_SINT16_MAX );

    return filter_struct_ptr->previous_output.prev_S16 ; /* Return output */
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_LP1_S16_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_FILTER_LP1_S16
*
*  previous_output = init_value
*  previous_error = 0
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   init_value is the init value
*
*  REMARKS:
*   This macro should be used each time a new filter order is launched with
*   DDS_M_FILTER_LP1_S16
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16_INIT(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                  sint16 init_value)
{
    filter_struct_ptr->previous_output.prev_S16 = init_value ;
    filter_struct_ptr->previous_error= 0 ;

    return(init_value);
}

/*******************************************************************************
*  Function name:  DDS_M_FILTER_LP1_S16_V2
*
*  Description :
*  The following fucntion apply a low pass 1st order filter to the input
*
*  result = previous_output + (target - previous_output)*filter_factor
*                                    / bp_filter_factor
*  previous_error = (target - previous_output) * filter_factor % bp_filter_factor
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   target is the input signal
*   filter_factor is the attenuation factor
*   bp_filter_factor is filter_factor binary point
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_FILTER_LP1_S16_INIT
*   it is assume that bp_filter_factor is different from zero
*   the macro uses pointer to access on previous value and and error
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16_V2(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             sint16 target,
                                             uint16 filter_factor,
                                             uint16 bp_filter_factor)
{
    sint32 temp ;
    sint32 temp_calc;
    sint32 delta;
    sint32 prev;

    prev = (sint32)*(filter_struct_ptr->previous_output.prev_S16_ptr);
    delta = (sint32)target - prev;
    /* Test to check overflow on calculation. The >= allow to anticipe
       the prev_error */
    if ( (delta >= (sint32)DDS_SINT16_MAX ) && ((sint32)filter_factor >= (sint32)DDS_SINT16_MAX) )
    {
        /* overflow case */
        delta = delta / 2;

        /* temp = x/2 + prev_err/2 */
        temp = (delta * (sint32)filter_factor) + (*(filter_struct_ptr->previous_error_ptr) / 2);

        /* error calculation = (temp % fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        *(filter_struct_ptr->previous_error_ptr) = (temp % (sint32)bp_filter_factor) * 2;

        /* output calculation  = prev_out + (temp/fact) * 2 */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = prev + ((temp/(sint32)bp_filter_factor) * 2);
    }
    else
    {
        temp = (delta * (sint32)filter_factor) + *(filter_struct_ptr->previous_error_ptr);

        /* error calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        *(filter_struct_ptr->previous_error_ptr) = temp % (sint32)bp_filter_factor;

        /* output calculation */
/* <PRQA_COMMENT><2834>It is the responsability of the caller to not set a null value for "bp_filter_factor". </2834></PRQA_COMMENT> */
        temp_calc = prev + (temp/(sint32)bp_filter_factor);


    }
    *(filter_struct_ptr->previous_output.prev_S16_ptr) = (sint16)DDS_M_LIMIT ( temp_calc,
                                                                        DDS_SINT16_MIN,
                                                                        DDS_SINT16_MAX );

    return *(filter_struct_ptr->previous_output.prev_S16_ptr) ; /* Return output */
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_LP1_S16_V2_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_FILTER_LP1_S16
*
*  previous_output = init_value
*  previous_error = 0
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   init_value is the init value
*
*  REMARKS:
*   This macro should be used each time a new filter order is launched with
*   DDS_M_FILTER_LP1_S16
*   it is assume that the pointer given to the fucntion are valid
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16_V2_INIT(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                     CONSTP2VAR(sint16, AUTOMATIC, AUTOMATIC) prev_ptr,
                                                     CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) error_ptr,
                                                     sint16 init_value,
                                                     sint32 error)
{
    filter_struct_ptr->previous_output.prev_S16_ptr = prev_ptr;
    filter_struct_ptr->previous_error_ptr = error_ptr;
    *(filter_struct_ptr->previous_output.prev_S16_ptr) = init_value ;
    *(filter_struct_ptr->previous_error_ptr) = error;

    return(init_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_U16_V1
*  Description     :    U16 2-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_TAB2D_U16_V1(CONSTP2CONST(t_dds_m_tab2d_u16, AUTOMATIC, AUTOMATIC) table,
                                        uint16 x)
{
    P2CONST(uint16, AUTOMATIC, AUTOMATIC) xv; /* A pointer into the x vector. */
    P2CONST(uint16, AUTOMATIC, AUTOMATIC) yv; /* A pointer into the y vector. */
    uint16 nlast;
    uint16 rtn_value;

    xv     = table->xval;         /* point to first x element of vector */
    yv     = table->yval;         /* point to first y element of vector */


    /* find bracketting x values, x values increase in value by defn. */

    if ((uint32)x < (uint32)(*xv))            /* Test first extreme. */
    {
      rtn_value = *yv;
    }
    else
    {     /* Not first extreme */

      {  /* Block containing nlast */


           nlast = (uint16)((uint32)table->size - (uint32)1); /* last index of array */
/* <PRQA_COMMENT><0488>Do not touch the current implementation to avoid regression</0488></PRQA_COMMENT> */
           xv += nlast;                   /* point to last x element of vector */
/* <PRQA_COMMENT><0488>Do not touch the current implementation to avoid regression</0488></PRQA_COMMENT> */
           yv += nlast;                   /* point to last y element of vector */
        }

        if ((uint32)x >= (uint32)(*xv))          /* Test second extreme. */
        {
            rtn_value = *yv;
        }
        else
        {    /* Not second extreme */

            do                   /* Searching from the end of the vector,   */
            {
                --yv;             /* ... find a component of the x vector just */
                --xv;             /* ... less than x                           */
            }
            while ((uint32)x < (uint32)(*xv));

            rtn_value =  *yv;


        } /* End not second extreme */

    } /* End not first extreme */

    return rtn_value;
}



/*******************************************************************************
*
*                       2-D MAP FUNCTIONS       x -> y
*
********************************************************************************
*
*       INTRODUCTION
*       ------------
*
*       2-d maps, mapping x onto y, consist of a set of (x,y) pairs.
*       Piecewise linear interpolation is undertaken between these pairs.
*
*       The x-values are assumed to be monotonically increasing, and
*       errors will arise if they do not (although two x values may be equal
*       to allow discontinuities in y).
*
*       Where discontinuities exist, the y value returned at the point of the
*       discontinuity is the y value as x tends to this value from above.
*
*       If the x value presented to the function lies outside the range xmin ..
*       xmax, then the value is treated as though it has the value of the
*       nearest value in the range.
*
*       If the x value lies within the range xmin .. xmax then linear
*       interpolation is undertaken between the two x values that bound the x
*       value closest.
*
*       |
*       |          /\                _______
*       |         /  \              /:
*       |        /    \            / :
*       |       /      \          /  :
*       |-------        \        /   :
*       |       :        \      /    :
*       |       :         \____/     :
*       |       :                    :
*       |___________________________________
*
*               xvec[0]              xmax
*               =xmin
*
*
*
*       IMPLEMENTATION
*       --------------
*
*       There follow 3 flavours of 2-D map function:
*
*               x & y signed words,
*               x & y unsigned words.
*               x signed word and y unsigned word
*
*       x & y are stored as arrays.
*       nx indexing into the x array and ny into the y array.
*
*       EFFICIENCY
*       ----------
*
*       The indexes nx & ny were byte sized, but declaring them word sized
*       is more efficient as it avoids integer promotions.
*
*       Functions lib_umap2d lib_smap2d & lib_sumap2d embody the functionality
*       of functions interpolate1d_U16 & interpolate1d_S16 respectively;
*       this avoids the overhead associated with a function call.
*       This is permissible because the combined functions remain small.
*
*       ASSUMPTIONS THE RELEASE & CALIBRATION TOOLS SHOULD CHECK FOR EACH
*       2-D MAP FUNCTION.
*       --------------------------------------------------------
*
*    i)  x values increase monotonically.
*    ii) There are 'size' components in the x vector.
*        ('size' is a component of the MAP2D_x16 structure).
*    iii)There are 'size' components in the y vector.
*    iv) Each vector has at least two elements.
*
*******************************************************************************/

/******/
/* V1 */
/******/
#define DDS_SEARCH_IND_2D                                                   \
    ind_max = (uint16)(map->size - 2); /* Max index size of array */        \
    indx_ptr = &(map->sav_ptr->ind_x);   /* Last used index of array */     \
                                                                            \
    nx = *indx_ptr;                                                         \
                                                                            \
    if ( nx > ind_max )                                                     \
    {                                                                       \
        nx = ind_max;                                                       \
    }                                                                       \
                                                                            \
    xv_p = map->xval + nx ;                                                 \
                                                                            \
    while ( x >= xv_p[1] )                                                  \
    {                                                                       \
        nx++;        /* ... find a component of the x vector just */        \
        xv_p++;          /* ... greater than x                        */    \
                                                                            \
        if ( nx > ind_max )     /* Test the maximum index */                \
        {                                                                   \
            *indx_ptr = (uint8)ind_max;                                     \
            return ( map->yval[ind_max+1]);                                 \
        }                                                                   \
                                                                            \
    }                                                                       \
                                                                            \
    while ( x < xv_p[0] )                                                   \
    {                                                                       \
        if ( nx <= 0 )          /* Test the minimum index  */               \
        {                                                                   \
            *indx_ptr = 0;                                                  \
            return ( map->yval[0]);                                         \
        }                                                                   \
                                                                            \
        nx--;       /* ... find a component of the x vector just */         \
        xv_p--;         /* ... less than x                           */     \
    }                                                                       \
                                                                            \
    yv_p = map->yval + nx;                                                  \
/* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    *indx_ptr = (uint8) nx;         /* Save the x value index */

#define DDS_INTERPOLE_2D_U                                                  \
    /* From above tests loop is guaranteed to terminate within the array */ \
    /* such that xv & xv+1 fall within the array.                        */ \
    /* If changing the above logic, consider the impact on discontinuous */ \
    /* maps ( ie when x[n] = x[n+1] for some n ). */                        \
                                                                            \
    /* We now have *xv as the largest component of xval that remains     */ \
    /* smaller than x and *(xv+1) as the smallest value of xval that     */ \
    /* remains larger than or equal to x.   */                              \
                                                                            \
    /* Entry into this block implies xv[1] != xv[0] */                      \
                                                                            \
     dx0  = (uint16)(x - xv_p[0]);                                          \
     dx1  = (uint16)(xv_p[1] - x); /* These differences cannot overflow  */ \
                          /* if the x,y pairs are ordered correctly      */ \
                                                                            \
                                                                            \
     numerator = ((uint32)dx1 * yv_p[0]) + ((uint32)dx0 * yv_p[1]);         \
                                                                            \
     /*  Above cannot overflow, because:                                 */ \
     /*        numerator is less than (dx1+dx0)*max(yv[1],yv[0])         */ \
     /*        dx1 + dx0 = dx01 which fits in 16 bits.                   */ \
     /*        yv[1] & yv[0] both fit in 16 bits.                        */ \
     /*  therefore numerator fits in 32 bits.                            */ \
                                                                            \
     /* denominator is guaranteed not to be zero as xv[1] != xv[0]  */      \
                                                                            \
     rtn_value = ( (uint16) (numerator / (uint32)( dx0 + dx1 ) ) );         \
                                                                            \
     /* return value is guaranteed to fit inside 16 bits because         */ \
/* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
     /* yv[0] & yv[1] do.*/

#define DDS_INTERPOLE_2D_S                                                  \
    /* From above tests loop is guaranteed to terminate within the       */ \
    /* array such that xv & xv+1 fall within the array.                  */ \
                                                                            \
    /* We now have *xv as the largest component of xval that remains     */ \
    /* smaller than x and *(xv+1) as the smallest value of xval that     */ \
    /* remains larger than or equal to x.                                */ \
                                                                            \
    /* We assume that these S16 subtractions gives a valid uint16 value     */ \
    /* even when the S16 value has overflowed. This is valid for         */ \
    /* 2's complement type maths as we know a positive number will       */ \
    /* be returned in the range supported by uint16.                        */ \
                                                                            \
    dx0  =  x - xv_p[0] ;                                                   \
    dx1  =  xv_p[1] - x ;                                                   \
                                                                            \
    /* The above differences cannot overflow  if the x,y pairs are       */ \
    /* ordered correctly.                                                */ \
                                                                            \
    /* dx0, dx1 are uint16's; we wish to use the sum of these two           */ \
    /* values (dx01) as an S16, so divide both by 2 if necessary         */ \
    /* to ensure top (sign) bit is clear.                                */ \
    /* Since we will be dividing both numerator and denominator,         */ \
    /* all we lose is precision.                                         */ \
                                                                            \
    /* We cannot cast these vars directly to S32's otherwise             */ \
    /* the compiler would use a long multiplication library call.        */ \
                                                                            \
    numerator =    (dx1 * yv_p[0]) + (dx0 * yv_p[1]) ;                      \
                                                                            \
    /*  Above cannot overflow, because:                                  */ \
    /*        numerator is less than (dx1+dx0)*max(yv[1],yv[0])          */ \
    /*        dx1 + dx0 = dx01 which fits in 16 bits.                    */ \
    /*        yv[1] & yv[0] both fit in 16 bits.                         */ \
    /*  therefore numerator fits in 32 bits.                             */ \
                                                                            \
    rtn_value =  (sint16) ( numerator / ( dx1 + dx0 ) );                    \
                                                                            \
    /* Division by zero not possible as  dx01 != 0.                      */ \
    /* Return value is guaranteed to fit inside 16 bits because          */ \
/* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    /* yv[0] & yv[1] do.                                                 */


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_U16 ( CONSTP2CONST(t_dds_m_map2d_u16, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                          uint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2101>
Do not touch the current implementation to avoid regression
</2101></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U8
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_U8 ( CONSTP2CONST(t_dds_m_map2d_u8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                          uint8 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return (uint8)rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U8U16
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_U8U16 ( CONSTP2CONST(t_dds_m_map2d_u8u16, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                          uint8 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16U8
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_U16U8 ( CONSTP2CONST(t_dds_m_map2d_u16u8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                          uint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return (uint8)rtn_value;
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16U8
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_S16U8 ( CONSTP2CONST(t_dds_m_map2d_s16u8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                          sint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return (uint8)rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16S8
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(sint8, AUTOMATIC) DDS_M_MAP2D_S16S8 ( CONSTP2CONST(t_dds_m_map2d_s16s8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                          sint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    sint32 numerator;
    sint32 dx0;
    sint32 dx1;

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2104><2105>
Do not touch the current implementation to avoid regression
</2105></2104></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S

    return (sint8)rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(sint16, AUTOMATIC) DDS_M_MAP2D_S16 ( CONSTP2CONST(t_dds_m_map2d_s16, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                          sint16 x /* x value */ )

{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    sint32 numerator;
    sint32 dx0;
    sint32 dx1;

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2105>
Do not touch the current implementation to avoid regression
</2105></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S

    return (rtn_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint8, AUTOMATIC) DDS_M_MAP2D_S8 ( CONSTP2CONST(t_dds_m_map2d_s8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                          sint8 x /* x value */ )

{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    sint32 numerator;
    sint32 dx0;
    sint32 dx1;

    P2VAR(sint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2104>
Do not touch the current implementation to avoid regression
</2104></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2104>
Do not touch the current implementation to avoid regression
</2104></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S

    return (sint8)(rtn_value);
}



/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_SU16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_SU16( CONSTP2CONST(t_dds_m_map2d_su16, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                          sint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D


    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return (rtn_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_SU8
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_SU8( CONSTP2CONST(t_dds_m_map2d_su8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                          sint8 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(sint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2104>
Do not touch the current implementation to avoid regression
</2104></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2100><2101><2104>
Do not touch the current implementation to avoid regression
</2104></2101></2100></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return (uint8)(rtn_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_US8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint8, AUTOMATIC) DDS_M_MAP2D_US8( CONSTP2CONST(t_dds_m_map2d_us8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                          uint8 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    sint32 numerator;

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    sint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2100><2101><2104><4491>
Do not touch the current implementation to avoid regression
</4491></2104></2101></2100></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S

    return (sint8)(rtn_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S8U16
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_S8U16( CONSTP2CONST(t_dds_m_map2d_s8u16, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                          sint8 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    uint32 numerator;

    P2VAR(sint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    uint16 rtn_value;
    uint16 dx0;
    uint16 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2104>
Do not touch the current implementation to avoid regression
</2104></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2101><2104>
Do not touch the current implementation to avoid regression
</2104></2101></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U

    return (rtn_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_US16
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(sint16, AUTOMATIC) DDS_M_MAP2D_US16 ( CONSTP2CONST(t_dds_m_map2d_us16, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           uint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 nx;
    uint16 ind_max;

    sint32 numerator;

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the y vector. */

    sint16 rtn_value;
    sint32 dx0;
    sint32 dx1;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834><2101><2105><4443>
Do not touch the current implementation to avoid regression
</4443></2105></2101></2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S

    return (rtn_value);
}



/******/
/* V2 */
/******/

/* DDS_SEARCH_IND_2D_V2
Change from V1:
- Use table access type instead of operation on pointer
- Create a local copy instead access of table element
*/
#define DDS_SEARCH_IND_2D_V2                                                \
    ind_max = (uint16)((sint32)(map->size) - 2); /* Max index size of array */\
    indx_ptr = &(map->sav_ptr->ind_x);   /* Last used index of array */     \
                                                                            \
    index = *indx_ptr;                                                      \
                                                                            \
    if ( index > ind_max )                                                  \
    {                                                                       \
        index = 0;                                                          \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        /* Do Nothing */                                                    \
    }                                                                       \
    bpx_ptr = &map->xval[(sint32)index];                                    \
    bpx_1 = bpx_ptr[1];                                                     \
                                                                            \
    while ( x >= bpx_1 )                                                    \
    {                                                                       \
                                                                            \
        if ( index >= ind_max )     /* Test the maximum index */            \
        {                                                                   \
            *indx_ptr = (uint8)ind_max;                                     \
            return ( map->yval[(sint32)ind_max+1]);                         \
        }                                                                   \
        index++;                                                            \
        bpx_ptr++;                                                          \
        bpx_1 = bpx_ptr[1];                                                 \
                                                                            \
    }                                                                       \
                                                                            \
    bpx_0 = bpx_ptr[0];                                                     \
    while ( x < bpx_0 )                                                     \
    {                                                                       \
        if ( index <= 0 )       /* Test the minimum index  */               \
        {                                                                   \
            *indx_ptr = 0;                                                  \
            return ( map->yval[0]);                                         \
        }                                                                   \
                                                                            \
        index--;                                                            \
        bpx_ptr--;          /* ... less than x                   */         \
        bpx_0 = bpx_ptr[0];                                                 \
        bpx_1 = bpx_ptr[1];                                                 \
    }                                                                       \
                                                                            \
    data_ptr = &map->yval[(sint32)index];                                   \
                                                                            \
/* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    *indx_ptr = (uint8) index;         /* Save the x value index */


/* DDS_INTERPOLE_2D_U32_V2
Changes from V1:
- Add test to avoid calculation in case of flat cartography
- Change formula due to overflow on calculation
*/
#define DDS_INTERPOLE_2D_U32_V2                                             \
    data_0 = data_ptr[0];                                                   \
    data_1 = data_ptr[1];                                                   \
    if(data_0 != data_1)                                                    \
    {                                                                       \
        dx0   =  (uint32)x - (uint32)bpx_0;                                 \
        dx1   =  (uint32)bpx_1 - (uint32)x;                                 \
        dx    =  (uint32)bpx_1 - (uint32)bpx_0;                             \
                                                                            \
        if(data_1>=data_0)                                                  \
        {                                                                   \
            data_dx =data_1-data_0;                                         \
            rtn_value = (data_0 +                                           \
                        ((data_dx / dx) * dx0)+                             \
                        (((data_dx % dx) * dx0) / dx));                     \
        }                                                                   \
        else                                                                \
        {                                                                   \
            data_dx =data_0-data_1;                                         \
            rtn_value = (data_1 +                                           \
                        ((data_dx / dx) * dx1)+                             \
                        (((data_dx % dx) * dx1) / dx));                     \
        }                                                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        rtn_value = data_0;                                                 \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    }

#define DDS_INTERPOLE_2D_S32_V2                                             \
    data_0 = data_ptr[0];                                                   \
    data_1 = data_ptr[1];                                                   \
    if(data_0 != data_1)                                                    \
    {                                                                       \
        dx0   =  (sint32)x - (sint32)bpx_0;                                 \
        dx1   =  (sint32)bpx_1 - (sint32)x;                                 \
        dx    =  (sint32)bpx_1 - (sint32)bpx_0;                             \
                                                                            \
        if(data_1>=data_0)                                                  \
        {                                                                   \
            data_dx =data_1-data_0;                                         \
            rtn_value = (data_0 +                                           \
                        ((data_dx / dx) * dx0)+                             \
                        (((data_dx % dx) * dx0) / dx));                     \
        }                                                                   \
        else                                                                \
        {                                                                   \
            data_dx =data_0-data_1;                                         \
            rtn_value = (data_1 +                                           \
                        ((data_dx / dx) * dx1)+                             \
                        (((data_dx % dx) * dx1) / dx));                     \
        }                                                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        rtn_value = data_0;                                                 \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    }


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16U32
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_MAP2D_U16U32 ( CONSTP2CONST(t_dds_m_map2d_u16u32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           uint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 ind_max;
    uint16 index;

    /* BPX */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) bpx_ptr; /* A pointer into the x vector. */
    uint16  bpx_0;
    uint16  bpx_1;

    /* DAT */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) data_ptr; /* A pointer into the x vector. */
    uint32 data_0;
    uint32 data_1;
    uint32 data_dx;
    uint32 dx0;
    uint32 dx1;
    uint32 dx;
    uint32 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><2000><2101>
Do not touch the current implementation to avoid regression
</2101></2000></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D_V2

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834>
Do not touch the current implementation to avoid regression
</2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U32_V2

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16S32
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(sint32, AUTOMATIC) DDS_M_MAP2D_U16S32 ( CONSTP2CONST(t_dds_m_map2d_u16s32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           uint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 ind_max;
    uint16 index;

    /* BPX */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) bpx_ptr; /* A pointer into the x vector. */
    uint16  bpx_0;
    uint16  bpx_1;

    /* DAT */
    P2VAR(sint32, AUTOMATIC, AUTOMATIC) data_ptr; /* A pointer into the x vector. */
    sint32 data_0;
    sint32 data_1;
    uint32 data_dx;
    sint32 dx0;
    sint32 dx1;
    sint32 dx;
    sint32 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><2000><2101>
Do not touch the current implementation to avoid regression
</2101></2000></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D_V2

    /* Interpole to get output value */
/* <PRQA_COMMENT><1820><2834><3784><3795><4434><4446>
Do not touch the current implementation to avoid regression
</4446></4434></3795></3784></2834></1820></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S32_V2

    return (rtn_value);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16U32
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_MAP2D_S16U32 ( CONSTP2CONST(t_dds_m_map2d_s16u32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           sint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 ind_max;
    uint16 index;

    /* BPX */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) bpx_ptr; /* A pointer into the x vector. */
    sint16  bpx_0;
    sint16  bpx_1;

    /* DAT */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) data_ptr; /* A pointer into the x vector. */
    uint32 data_0;
    uint32 data_1;
    uint32 data_dx;
    uint32 dx0;
    uint32 dx1;
    uint32 dx;
    uint32 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><2000><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2000></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D_V2

    /* Interpole to get output value */
/* <PRQA_COMMENT><2834>
Do not touch the current implementation to avoid regression
</2834></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_U32_V2

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16S32
*  Description     :    see above comment
*
*******************************************************************************/
/* <PRQA_COMMENT><2889> return used in macro for code optimisation </2889></PRQA_COMMENT> */
FUNC(sint32, AUTOMATIC) DDS_M_MAP2D_S16S32 ( CONSTP2CONST(t_dds_m_map2d_s16s32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           sint16 x /* x value */ )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;
    uint16 ind_max;
    uint16 index;

    /* BPX */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) bpx_ptr; /* A pointer into the x vector. */
    sint16  bpx_0;
    sint16  bpx_1;

    /* DAT */
    P2VAR(sint32, AUTOMATIC, AUTOMATIC) data_ptr; /* A pointer into the x vector. */
    sint32 data_0;
    sint32 data_1;
    uint32 data_dx;
    sint32 dx0;
    sint32 dx1;
    sint32 dx;
    sint32 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><2000><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2000></PRQA_COMMENT> */
    DDS_SEARCH_IND_2D_V2

    /* Interpole to get output value */
/* <PRQA_COMMENT><1820><2834><3784><3795><4434><4446>
Do not touch the current implementation to avoid regression
</4446></4434></3795></3784></2834></1820></PRQA_COMMENT> */
    DDS_INTERPOLE_2D_S32_V2

    return (rtn_value);
}


/*******************************************************************************
*
*                       3-D MAP FUNCTIONS    (x,y) -> z
*
********************************************************************************
*
*  Theory:
*
*
*   The 3-d  map consists of an irregular rectangular grid mapping x & y
*   coordinates onto z.
*
*   Main algorithm:
*
*   i)   Clip both x & y such that they fall within the defined range of values.
*   ii)  Identify the rectangular cell in which (x,y) falls.
*   iii) Conduct bilinear interpolation across this cell to identify z for the
*        given x & y.
*
*
*         |             z0                          |
*    y0 --+-----------------------------------------+----
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            : z                          |
*     y ..|............*............................|
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            :                            |
*         |            : z1                         |
*    y1 --+-----------------------------------------+----
*         |            .                            |
*         |            .                            |
*         |            .                            |
*         x1           x                            x0
*
*
*
*       Bilinear interpolation algorithm:
*
*       calculate z(x,y0) by interpolating between (x0,y0) & (x1,y0).
*       calculate z(x,y1) by interpolating between (x0,y1) & (x1,y1).
*       calculate z(x,y)  by interpolating between (x, y0) & (x, y1).
*
*
*       IMPLEMENTATION
*       --------------
*
*       There are 2 flavours of 3-D map functions:
*
*               x, y & z signed words,
*               x, y & z unsigned words.
*
*
*       ASSUMPTIONS THE RELEASE & CALIBRATION TOOLS SHOULD CHECK FOR EACH
*       LOOKUP FUNCTION.
*       ------------------------------------------------------------------
*
*       i)   X values increase monotonically.
*       ii)  Y values increase monotonically.
*       iii) There are x_size components in the x vector.
*            ('x_size' is a component of the MAP3D_x16 structure).
*       iv)  There are y_size components in the y vector.
*            ('y_size' is a component of the MAP3D_x16 structure).
*       v)   There are x_size * y_size components in the z matrix.
*       vi)  x_size & y_size are both greater than or equal to two.
*
*******************************************************************************/

#define DDS_SEARCH_IND_3D                                                   \
    x_size_cpy = map->x_size;                                                   \
                                                                            \
    ind_max = (uint16)(map->x_size - 2);                                    \
    indx_ptr = &(map->sav_ptr->ind_x);                                      \
    nx = *indx_ptr;                                                         \
                                                                            \
    /* find bracketting x values, x values increase in value by defn. */    \
    if ( nx > ind_max )     /* If x lies outside the defined range ... */   \
    {                                                                       \
        nx = ind_max;      /* ...  then the search is done, else ... */     \
    }                                                                       \
                                                                            \
    xv_p = (map->xval + nx) + 1;   /* ... search from the last element  */  \
                                                                            \
    while ( ( x >= *xv_p ) && ( nx < ind_max ) )                            \
    {                                                                       \
        nx ++;                                                              \
        xv_p++;                                                             \
    }                                                                       \
                                                                            \
    xv_p--;                                                                 \
                                                                            \
    while ( ( x < *xv_p ) && ( nx > 0 ) )                                   \
    {                                                                       \
        nx --;                                                              \
        xv_p--;                                                             \
    }                                                                       \
                                                                            \
    /* From above tests loop is guaranteed to terminate within the array  */\
    /* and both xv_p & (xv_p+1) point into the x vector.                  */\
                                                                            \
    /* find bracketting y values, y values increase in value by defn. */    \
                                                                            \
    ind_max = (uint16)(map->y_size - 2);                                    \
    indy_ptr = &(map->sav_ptr->ind_y);                                      \
    ny = *indy_ptr;                                                         \
                                                                            \
    if ( ny > ind_max )   /* If y lies outside the defined range ... */     \
    {                                                                       \
        ny = ind_max;    /* ...  then the search is done , else...     */   \
    }                                                                       \
                                                                            \
    yv_p = map->yval + ny + 1; /* ... seach from the last element */        \
                                                                            \
    while ( ( y >= *yv_p ) && ( ny < ind_max ) )                            \
    {                                                                       \
        ny ++;                                                              \
        yv_p++;                                                             \
    }                                                                       \
                                                                            \
    yv_p--;                                                                 \
                                                                            \
    while ( ( y < *yv_p ) && ( ny > 0 ) )                                   \
    {                                                                       \
        ny --;                                                              \
        yv_p--;                                                             \
    }                                                                       \
                                                                            \
    *indx_ptr = ( uint8 ) nx;    /* save x index */                         \
    *indy_ptr = ( uint8 ) ny;    /* save y index */                         \
                                                                            \
    /* Set pointer to cell within z-matrix. */                              \
                                                                            \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    zm_p = (map->zmat + (ny*x_size_cpy)) + nx;  /* point to col nx, row ny */


#define DDS_INTERPOLE_3D_U                                                  \
    /* STAGE I: Collapse x dimension of 2-d cell onto line with */          \
    /*          desired x value.                                */          \
                                                                            \
    /* Interpolation along yv[0] to give z2d[0] */                          \
    if ((sint32)x <= (sint32)xv_p[0])                                       \
    {                                                                       \
        z2d[0] = zm_p[0];                                                   \
        zm_p += x_size_cpy;    /* point to col nx, row ny+1 */              \
        z2d[1] = zm_p[0];                                                   \
    }                                                                       \
    else if ((sint32)x >= (sint32)xv_p[1])                                  \
    {                                                                       \
        z2d[0] = zm_p[1];                                                   \
        zm_p += x_size_cpy;    /* point to col nx, row ny+1 */              \
        z2d[1] = zm_p[1];                                                   \
    }                                                                       \
    else       /* Entry into this block implies xv[1] != xv[0] */           \
    {                                                                       \
        /* We assume that these uint16  subtractions gives a valid uint16 value */\
        /* even when the uint16 value has overflowed.   */                      \
                                                                            \
        dx1  =  (uint32)xv_p[1] - (uint32)x ;/*These differences cannot overflow*/\
        dx0  =  (uint32)x - (uint32)xv_p[0] ;/*if the x,y pairs are ordered correctly*/\
        denominator = dx1 + dx0;                                            \
                                                                            \
        numerator =   (dx1 * (uint32)zm_p[0]) + (dx0 * (uint32)zm_p[1]);    \
                                                                            \
        /*  Above cannot overflow, because:                         */      \
        /*        numerator is less than (dx1+dx0)*max(yv[1],yv[0]) */      \
        /*        dx1 + dx0 = dx01 which fits in 16 bits.           */      \
        /*        yv[1] & yv[0] both fit in 16 bits.                */      \
        /*  therefore numerator fits in 32 bits.                    */      \
                                                                            \
        z2d[0] = (uint16) (numerator/(denominator));                        \
                                                                            \
        zm_p += x_size_cpy;    /* point to col nx, row ny+1 */              \
        numerator =   (dx1 * (uint32)zm_p[0]) + (dx0 * (uint32)zm_p[1]);    \
        z2d[1] = (uint16) (numerator/(denominator));                        \
                                                                            \
        /* Division by zero not possible as  dx01 != 0.   */                \
        /* y is guaranteed to fit inside 16 bits because yv[0] & yv[1] do.*/\
    }                                                                       \
                                                                            \
    if ((sint32)y <= (sint32)yv_p[0])                                       \
    {                                                                       \
        rtn_value = z2d[0];                                                 \
    }                                                                       \
    else if ((sint32)y >= (sint32)yv_p[1])                                  \
    {                                                                       \
        rtn_value = z2d[1];                                                 \
    }                                                                       \
    else       /* Entry into this block implies xv[1] != xv[0] */           \
    {                                                                       \
        /* We assume that these uint16  subtractions gives a valid uint16 value */\
        /* even when the uint16 value has overflowed. */                    \
                                                                            \
        dx1  =  (uint32)yv_p[1] - (uint32)y ;/*These differences cannot overflow*/\
        dx0  =  (uint32)y - (uint32)yv_p[0] ;/*if the x,y pairs are ordered correctly*/\
        denominator = dx1 + dx0;                                            \
                                                                            \
        numerator =   (dx1 * (uint32)z2d[0]) + (dx0 * (uint32)z2d[1]);      \
                                                                            \
        /*  Above cannot overflow, because:                              */ \
        /*        numerator is less than (dx1+dx0)*max(yv[1],yv[0])      */ \
        /*        dx1 + dx0 = dx01 which fits in 16 bits.                */ \
        /*        yv[1] & yv[0] both fit in 16 bits.                     */ \
        /*  therefore numerator fits in 32 bits.                         */ \
                                                                            \
        rtn_value = (uint16) (numerator/(denominator));                     \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    }


#define DDS_INTERPOLE_3D_S                                                  \
    /* STAGE I: Collapse x dimension of 2-d cell onto line with */          \
    /*          desired x value. */                                         \
                                                                            \
    /* Interpolation along yv[0] to give z2d[0] */                          \
    if ((sint32)x <= (sint32)xv_p[0])                                       \
    {                                                                       \
        z2d[0] = zm_p[0];                                                   \
        zm_p += x_size_cpy;    /* point to col nx, row ny+1 */              \
        z2d[1] = zm_p[0];                                                   \
    }                                                                       \
    else if ((sint32)x >= (sint32)xv_p[1])                                  \
    {                                                                       \
        z2d[0] = zm_p[1];                                                   \
        zm_p += x_size_cpy;    /* point to col nx, row ny+1 */              \
        z2d[1] = zm_p[1];                                                   \
    }                                                                       \
    else       /* Entry into this block implies xv[1] != xv[0] */           \
    {                                                                       \
        /* We assume that these S16  subtractions gives a valid S32 value */\
        /* even when the S16 value has overflowed.  */                      \
                                                                            \
        dx1  =  (sint32)xv_p[1] - (sint32)x ; /* These differences cannot overflow      */\
        dx0  =  (sint32)x - (sint32)xv_p[0] ; /* if the x,y pairs are ordered correctly */\
        denominator = dx1 + dx0;                                            \
                                                                            \
        numerator =   (dx1 * (sint32)zm_p[0]) + (dx0 * (sint32)zm_p[1]);    \
                                                                            \
        /*  Above cannot overflow, because:                              */ \
        /*        numerator is less than (dx1+dx0)*max(yv[1],yv[0])      */ \
        /*        dx1 + dx0 = dx01 which fits in 16 bits.                */ \
        /*        yv[1] & yv[0] both fit in 16 bits.                     */ \
        /*  therefore numerator fits in 32 bits.                         */ \
                                                                            \
        z2d[0] = (sint16) (numerator/(denominator));                        \
                                                                            \
        zm_p += x_size_cpy;    /* point to col nx, row ny+1 */              \
        numerator =   (dx1 * (sint32)zm_p[0]) + (dx0 * (sint32)zm_p[1]);    \
        z2d[1] = (sint16) (numerator/(denominator));                        \
                                                                            \
        /* Division by zero not possible as  dx01 != 0.   */                \
        /* y is guaranteed to fit inside 16 bits because yv[0] & yv[1] do.*/\
    }                                                                       \
                                                                            \
    if ((sint32)y <= (sint32)yv_p[0])                                                       \
    {                                                                       \
        rtn_value = z2d[0];                                                 \
    }                                                                       \
    else if ((sint32)y >= (sint32)yv_p[1])                                                  \
    {                                                                       \
        rtn_value = z2d[1];                                                 \
    }                                                                       \
    else       /* Entry into this block implies xv[1] != xv[0] */           \
    {                                                                       \
                                                                            \
        /* We assume that these S16  subtractions gives a valid S32 value */\
        /* even when the S16 value has overflowed.                        */\
                                                                            \
        dx1  =  (sint32)yv_p[1] - (sint32)y ;   /* These differences cannot overflow      */\
        dx0  =  (sint32)y - (sint32)yv_p[0] ;   /* if the x,y pairs are ordered correctly */\
        denominator = dx1 + dx0;                                            \
                                                                            \
        numerator =   (dx1 * (sint32)z2d[0]) + (dx0 * (sint32)z2d[1]);      \
                                                                            \
        /*  Above cannot overflow, because:                              */ \
        /*        numerator is less than (dx1+dx0)*max(yv[1],yv[0])      */ \
        /*        dx1 + dx0 = dx01 which fits in 16 bits.                */ \
        /*        yv[1] & yv[0] both fit in 16 bits.                     */ \
        /*  therefore numerator fits in 32 bits.                         */ \
                                                                            \
        rtn_value = (sint16)(numerator/(denominator));                      \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    }

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U16( CONSTP2CONST(t_dds_m_map3d_u16, AUTOMATIC, AUTOMATIC) map,
                                         uint16 x,
                                         uint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8U8U16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U8U8U16( CONSTP2CONST(t_dds_m_map3d_u8u8u16, AUTOMATIC, AUTOMATIC) map,
                                         uint8 x,
                                         uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16S16S8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint8, AUTOMATIC) DDS_M_MAP3D_U16S16S8 ( CONSTP2CONST(t_dds_m_map3d_u16s16s8, AUTOMATIC, AUTOMATIC) map,
                                            uint16 x,
                                            sint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return (sint8)rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8U8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_MAP3D_U16U8U8 ( CONSTP2CONST(t_dds_m_map3d_u16u8u8, AUTOMATIC, AUTOMATIC) map,
                                             uint16 x,
                                             uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return (uint8)rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8S8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint8, AUTOMATIC) DDS_M_MAP3D_U16U8S8 ( CONSTP2CONST(t_dds_m_map3d_u16u8s8, AUTOMATIC, AUTOMATIC) map,
                                             uint16 x,
                                             uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return (sint8)rtn_value;
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_MAP3D_U8( CONSTP2CONST(t_dds_m_map3d_u8, AUTOMATIC, AUTOMATIC) map,
                                         uint8 x,
                                         uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return (uint8)rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_S16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_S16 ( CONSTP2CONST(t_dds_m_map3d_s16, AUTOMATIC, AUTOMATIC) map,
                                          sint16 x,
                                          sint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_SUS16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_SUS16 ( CONSTP2CONST(t_dds_m_map3d_sus16, AUTOMATIC, AUTOMATIC) map,
                                            sint16 x,
                                            uint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_USS16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_USS16 ( CONSTP2CONST(t_dds_m_map3d_uss16, AUTOMATIC, AUTOMATIC) map,
                                            uint16 x,
                                            sint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_SUU16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_SUU16 ( CONSTP2CONST(t_dds_m_map3d_suu16, AUTOMATIC, AUTOMATIC) map,
                                            sint16 x,
                                            uint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_USU16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_USU16 ( CONSTP2CONST(t_dds_m_map3d_usu16, AUTOMATIC, AUTOMATIC) map,
                                            uint16 x,
                                            sint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_SSU16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_SSU16 ( CONSTP2CONST(t_dds_m_map3d_ssu16, AUTOMATIC, AUTOMATIC) map,
                                            sint16 x,
                                            sint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;         /* index into x vector */
    uint16 ny;         /* index into y vector */

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_UUS16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_UUS16 ( CONSTP2CONST(t_dds_m_map3d_uus16, AUTOMATIC, AUTOMATIC) map,
                                            uint16 x,
                                            uint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;          /* index into x vector */
    uint16 ny;          /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_UUS8
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint8, AUTOMATIC) DDS_M_MAP3D_UUS8 ( CONSTP2CONST(t_dds_m_map3d_uus8, AUTOMATIC, AUTOMATIC) map,
                                           uint8 x,
                                           uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;      /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;          /* index into x vector */
    uint16 ny;          /* index into y vector */

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return (sint8)rtn_value;
}



/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8U16U16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U8U16U16 ( CONSTP2CONST(t_dds_m_map3d_u8u16u16, AUTOMATIC, AUTOMATIC) map,
                                              uint8 x,
                                              uint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8U16S16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_U8U16S16 ( CONSTP2CONST(t_dds_m_map3d_u8u16s16, AUTOMATIC, AUTOMATIC) map,
                                              uint8 x,
                                              uint16 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8U16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U16U8U16 ( CONSTP2CONST(t_dds_m_map3d_u16u8u16, AUTOMATIC, AUTOMATIC) map,
                                              uint16 x,
                                              uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8S16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_U16U8S16 ( CONSTP2CONST(t_dds_m_map3d_u16u8s16, AUTOMATIC, AUTOMATIC) map,
                                              uint16 x,
                                              uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101>
Do not touch the current implementation to avoid regression
</2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_S16U8S16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_S16U8S16 ( CONSTP2CONST(t_dds_m_map3d_s16u8s16, AUTOMATIC, AUTOMATIC) map,
                                              sint16 x,
                                              uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    sint32 numerator;
    sint32 denominator;
    sint32 dx0;
    sint32 dx1;

    sint16 z2d[DDS_LIB_SIZE_2];

    sint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_S

    return rtn_value;
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_S16U8U16
*  Description     :    see above comment
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_S16U8U16 ( CONSTP2CONST(t_dds_m_map3d_s16u8u16, AUTOMATIC, AUTOMATIC) map,
                                              sint16 x,
                                              uint8 y )
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indx_ptr;   /* A pointer to index into x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) indy_ptr;   /* A pointer to index into y vector */

    uint16 x_size_cpy;  /* A local copy of map->x_size (for efficiency). */
    uint16 ind_max;
    uint16 nx;               /*index into x vector */
    uint16 ny;              /* index into y vector */

    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p;       /* A pointer to 2 elements of the x vector. */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  yv_p;       /* A pointer to 2 elements of the y vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC)  zm_p;       /* A pointer to 2 elements of the desired row of zmat */

    uint32 numerator;
    uint32 denominator;
    uint32 dx0;
    uint32 dx1;

    uint16 z2d[DDS_LIB_SIZE_2];

    uint16 rtn_value;

    /* Search current position in map */
/* <PRQA_COMMENT><0488><2000><2100><2101><2105>
Do not touch the current implementation to avoid regression
</2105></2101></2100></2000></0488></PRQA_COMMENT> */
    DDS_SEARCH_IND_3D

    /* Interpole to get output value */
/* <PRQA_COMMENT><0488><2834>
Do not touch the current implementation to avoid regression
</2834></0488></PRQA_COMMENT> */
    DDS_INTERPOLE_3D_U

    return rtn_value;
}



/*******************************************************************************
*  Macro name:  DDS_M_EDGE_DETECT_INIT
*
*  Description :
*  The following macro manage init of DDS_M_EDGE_DETECT macro
*
*  Where:
*   init_value is the init value of previous input
*   edge_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(t_dds_m_edge_detected_event, AUTOMATIC) DDS_M_EDGE_DETECT_INIT(
                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                uint8 init_value)
{
    edge_struct_ptr->previous_input  = init_value;

    return (DDS_M_NO_EDGE_DETECTED);
}

/*******************************************************************************
*  Macro name:  DDS_M_EDGE_DETECT
*
*  Description :
*  This macro performs different output, when the input change.
*  A comparison between the previous input and the actual input allow
*  to select the edge type.
*  We have 3 type of edge : no edge, a positive edge and a negative edge.
*
*  Where:
*   input is the value of input
*   edge_struct_ptr is the structure associated to macro
*   This macro return a t_dds_m_edge_detected_event output
*
*******************************************************************************/
FUNC(t_dds_m_edge_detected_event, AUTOMATIC) DDS_M_EDGE_DETECT(
                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                uint8 input)
{
    t_dds_m_edge_detected_event output;

    if ((t_dds_m_uint)input == (t_dds_m_uint)edge_struct_ptr->previous_input)
    {
        output = DDS_M_NO_EDGE_DETECTED;
    }
    else
    {
        if ((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)input)
        {
            output = DDS_M_POSITIVE_EDGE_DETECTED;
        }
        else
        {
            output = DDS_M_NEGATIVE_EDGE_DETECTED;
        }
        edge_struct_ptr->previous_input = input;
    }

    return output;
}

/*******************************************************************************
*  Macro name:  DDS_M_POS_NEG_EDGE_DETECT_INIT
*
*  Description :
*  This macro is used to initialize structure for positive or negative edge detection
*  This macro affects struct_prev.previous_input with init_value
*
*  Where:
*   edge_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_POS_NEG_EDGE_DETECT_INIT(CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                                                                uint8 init_value)
{
    edge_struct_ptr->previous_input  = init_value;

    return init_value;
}

/*******************************************************************************
*  Macro name:  DDS_M_POSITIVE_EDGE_DETECT
*
*  Description :
*  This macro affects return_value with :
*     - DDS_TRUE when :
*               - input == DDS_TRUE
*           and - previous_input == DDS_FALSE
*     - DDS_FALSE else
*  It also affects struct_prev.previous_input with input
*
*  Where:
*   input is the value of input
*   edge_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_POSITIVE_EDGE_DETECT(
                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                uint8 input)
{
    uint8 output;

    if( ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)edge_struct_ptr->previous_input) ||
        ((t_dds_m_uint)DDS_TRUE != (t_dds_m_uint)input)  )
    {
        output = DDS_FALSE;
    }
    else
    {
        output = DDS_TRUE;
    }

    edge_struct_ptr->previous_input = input;

    return output;
}

/*******************************************************************************
*  Macro name:  DDS_M_NEGATIVE_EDGE_DETECT
*
*  Description :
*  This macro affects return_value with :
*     - DDS_TRUE when :
*               - input == DDS_FALSE
*           and - previous_input == DDS_TRUE
*     - DDS_FALSE else
*  It also affects struct_prev.previous_input with input
*
*  Where:
*   input is the value of input
*   edge_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_NEGATIVE_EDGE_DETECT(
                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                uint8 input)
{
    uint8 output;

    if( ((t_dds_m_uint)DDS_TRUE != (t_dds_m_uint)edge_struct_ptr->previous_input) ||
        ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)input)  )
    {
        output = DDS_FALSE;
    }
    else
    {
        output = DDS_TRUE;
    }

    edge_struct_ptr->previous_input = input;

    return output;
}

/*******************************************************************************
*  Function name: DDS_M_TURN_ON_DELAY
*
*  Description :
*  The following macro is used to apply a TURN ON DELAY on input
*
*  Output = DDS_TRUE if Input = DDS_TRUE since DELAY
*
*
*  Where:
*   input is the input value to test
*   current_time is the curren,t timer
*   delay is the turn on duration
*   turn_on_delay_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   current_time and delay must be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY(uint8 input, /* Boolean */
                   uint32 current_time,
                   uint32 delay,
                   CONSTP2VAR(t_dds_m_turn_on_delay_type, AUTOMATIC, AUTOMATIC) turn_on_delay_struct_ptr)
{

    if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)input)
    {
        turn_on_delay_struct_ptr->previous_input  = DDS_FALSE;
        turn_on_delay_struct_ptr->previous_output = DDS_FALSE;
    }
    else /* input = DDS_TRUE */
    {
        if (0 != delay)
        {
            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_delay_struct_ptr->previous_input)
            {
                (void)DDS_M_TIMER_INIT(current_time,
                                        &(turn_on_delay_struct_ptr->m_timer_str));

                turn_on_delay_struct_ptr->previous_input = DDS_TRUE;
            }
            else
            {
                /* Do nothing */
            }

            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_delay_struct_ptr->previous_output)
            {
                turn_on_delay_struct_ptr->previous_output
                         = DDS_M_TIMER(current_time ,
                                   delay ,
                                   &(turn_on_delay_struct_ptr->m_timer_str));
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            turn_on_delay_struct_ptr->previous_input = DDS_TRUE;
            turn_on_delay_struct_ptr->previous_output = DDS_TRUE;
        }

    }
    return(turn_on_delay_struct_ptr->previous_output);
}

/*******************************************************************************
*  Macro name: DDS_M_TURN_ON_DELAY_INIT
*
*  Description :
*  The following macro manage init of M_TURN_ON_DELAY function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of TURN_ON_DELAY
*   turn_on_delay_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_on_delay_type, AUTOMATIC, AUTOMATIC) turn_on_delay_struct_ptr)
{
    turn_on_delay_struct_ptr->previous_input  = init_value;
    turn_on_delay_struct_ptr->previous_output = init_value;

    return(init_value);
}




/*******************************************************************************
*  Function name: DDS_M_TURN_ON_DELAY_DELTA
*
*  Description :
*  The following macro is used to apply a TURN ON DELAY on input
*
*  Output = DDS_TRUE if Input = DDS_TRUE since DELAY
*
*
*  Where:
*   input is the input value to test
*   increment_time_delta is the elapsed time between calls
*   delay is the turn on duration
*   turn_on_delay_delta_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   increment_time_delta and delay must be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY_DELTA(uint8 input, /* Boolean */
                   uint32 increment_time_delta,
                   uint32 delay,
                   CONSTP2VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_delay_delta_struct_ptr)
{

    if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)input)
    {
        turn_on_delay_delta_struct_ptr->previous_input  = DDS_FALSE;
        turn_on_delay_delta_struct_ptr->previous_output = DDS_FALSE;
    }
    else /* input = DDS_TRUE */
    {
        if (delay != 0)
        {
            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_delay_delta_struct_ptr->previous_input)
            {
                turn_on_delay_delta_struct_ptr->elapsed_time = 0;
                turn_on_delay_delta_struct_ptr->previous_input = DDS_TRUE;
            }
            else
            {
                if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_delay_delta_struct_ptr->previous_output)
                {
                    if(turn_on_delay_delta_struct_ptr->elapsed_time  < (DDS_UINT32_MAX - increment_time_delta) )
                    {
                        turn_on_delay_delta_struct_ptr->elapsed_time = turn_on_delay_delta_struct_ptr->elapsed_time + increment_time_delta;
                    }
                    else
                    {
                        turn_on_delay_delta_struct_ptr->elapsed_time = DDS_UINT32_MAX;
                    }

                    if(turn_on_delay_delta_struct_ptr->elapsed_time > delay)
                    {
                        turn_on_delay_delta_struct_ptr->previous_output = DDS_TRUE;
                    }
                    else
                    {
                        turn_on_delay_delta_struct_ptr->previous_output = DDS_FALSE;
                    }

                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            turn_on_delay_delta_struct_ptr->previous_input  = DDS_TRUE;
            turn_on_delay_delta_struct_ptr->previous_output = DDS_TRUE;
        }
    }
    return(turn_on_delay_delta_struct_ptr->previous_output);
}



/*******************************************************************************
*  Macro name: DDS_M_TURN_ON_DELAY_DELTA_INIT
*
*  Description :
*  The following macro manage init of M_TURN_ON_DELAY function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of TURN_ON_DELAY
*   turn_on_delay_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY_DELTA_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_delay_delta_struct_ptr)
{
    turn_on_delay_delta_struct_ptr->previous_input  = init_value;
    turn_on_delay_delta_struct_ptr->previous_output = init_value;

    return(init_value);
}



/*******************************************************************************
*  Function name: DDS_M_TURN_OFF_DELAY
*
*  Description :
*  The following macro is used to apply a TURN OFF DELAY on input
*
*  Output = DDS_FALSE if Input = DDS_FALSE since DELAY
*
*
*  Where:
*   input is the input value to test
*   current_time is the curren,t timer
*   delay is the turn off duration
*   turn_on_delay_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   current_time and delay must be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY(uint8 input, /* Boolean */
                   uint32 current_time,
                   uint32 delay,
                   CONSTP2VAR(t_dds_m_turn_off_delay_type, AUTOMATIC, AUTOMATIC) turn_off_delay_struct_ptr)
{
    uint8 local_output; /* Boolean */

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)input)
    {
        turn_off_delay_struct_ptr->previous_input  = DDS_TRUE;
        turn_off_delay_struct_ptr->previous_output = DDS_TRUE;
    }
    else /* input = DDS_FALSE */
    {
        if (0 != delay)
        {
            if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_off_delay_struct_ptr->previous_input)
            {
                (void)DDS_M_TIMER_INIT(current_time,
                                        &(turn_off_delay_struct_ptr->m_timer_str));

                turn_off_delay_struct_ptr->previous_input = DDS_FALSE;
            }
            else
            {
                /* Do nothing */
            }

            if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_off_delay_struct_ptr->previous_output)
            {
                local_output
                         = DDS_M_TIMER(current_time ,
                                   delay ,
                                   &(turn_off_delay_struct_ptr->m_timer_str));
                if ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)local_output)
                {
                    turn_off_delay_struct_ptr->previous_output = DDS_TRUE;
                }
                else
                {
                    turn_off_delay_struct_ptr->previous_output = DDS_FALSE;
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            turn_off_delay_struct_ptr->previous_input  = DDS_FALSE;
            turn_off_delay_struct_ptr->previous_output = DDS_FALSE;
        }
    }
    return(turn_off_delay_struct_ptr->previous_output);
}


/*******************************************************************************
*  Macro name: DDS_M_TURN_OFF_DELAY_INIT
*
*  Description :
*  The following macro manage init of M_TURN_OFF_DELAY function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of TURN_OFF_DELAY
*   turn_off_delay_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_off_delay_type, AUTOMATIC, AUTOMATIC) turn_off_delay_struct_ptr)
{
    turn_off_delay_struct_ptr->previous_input  = init_value;
    turn_off_delay_struct_ptr->previous_output = init_value;

    return(init_value);
}




/*******************************************************************************
*  Function name: DDS_M_TURN_OFF_DELAY_DELTA
*
*  Description :
*  The following macro is used to apply a TURN OFF DELAY on input
*
*  Output = DDS_FALSE if Input = DDS_FALSE since DELAY
*
*
*  Where:
*   input is the input value to test
*   increment_time_delta is the elapsed time between calls
*   delay is the turn off duration
*   turn_off_delay_delta_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   increment_time_delta and delay must be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY_DELTA(uint8 input, /* Boolean */
                   uint32 increment_time_delta,
                   uint32 delay,
                   CONSTP2VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_off_delay_delta_struct_ptr)
{

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)input)
    {
        turn_off_delay_delta_struct_ptr->previous_input  = DDS_TRUE;
        turn_off_delay_delta_struct_ptr->previous_output = DDS_TRUE;
    }
    else /* input = DDS_FALSE */
    {
        if (delay != 0)
        {
            if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_off_delay_delta_struct_ptr->previous_input)
            {
                turn_off_delay_delta_struct_ptr->elapsed_time = 0;
                turn_off_delay_delta_struct_ptr->previous_input = DDS_FALSE;
            }
            else
            {
                if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_off_delay_delta_struct_ptr->previous_output)
                {
                    if(turn_off_delay_delta_struct_ptr->elapsed_time  < (DDS_UINT32_MAX - increment_time_delta) )
                    {
                        turn_off_delay_delta_struct_ptr->elapsed_time = turn_off_delay_delta_struct_ptr->elapsed_time + increment_time_delta;
                    }
                    else
                    {
                        turn_off_delay_delta_struct_ptr->elapsed_time = DDS_UINT32_MAX;
                    }

                    if(turn_off_delay_delta_struct_ptr->elapsed_time > delay)
                    {
                        turn_off_delay_delta_struct_ptr->previous_output = DDS_FALSE;
                    }
                    else
                    {
                        turn_off_delay_delta_struct_ptr->previous_output = DDS_TRUE;
                    }


                }
                else
                {
                    /* Do nothing */
                }
            }
        }
        else
        {
            turn_off_delay_delta_struct_ptr->previous_input  = DDS_FALSE;
            turn_off_delay_delta_struct_ptr->previous_output = DDS_FALSE;
        }
    }
    return(turn_off_delay_delta_struct_ptr->previous_output);
}


/*******************************************************************************
*  Macro name: DDS_M_TURN_OFF_DELAY_INIT_DELTA
*
*  Description :
*  The following macro manage init of M_TURN_OFF_DELAY function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of TURN_OFF_DELAY
*   turn_off_delay_delta_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY_DELTA_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_off_delay_delta_struct_ptr)
{
    turn_off_delay_delta_struct_ptr->previous_input  = init_value;
    turn_off_delay_delta_struct_ptr->previous_output = init_value;

    return(init_value);
}


/*******************************************************************************
*  Function name: DDS_M_TURN_ON_OFF_DELAY
*
*  Description :
*  The following macro is used to apply a TURN ON OFF DELAY on input
*
*  Output = DDS_TRUE if Input = DDS_TRUE since DELAY_ON
*  Output = DDS_FALSE if Input = DDS_FALSE since DELAY_OFF
*
*
*  Where:
*   input is the input value to test
*   current_time is the current timer
*   delay_on is the turn on duration
*   delay_off is the turn off duration
*   turn_on_off_delay_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   current_time, delay_on and delay_off must be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY(uint8 input, /* Boolean */
                   uint32 current_time,
                   uint32 delay_on,
                   uint32 delay_off,
                   CONSTP2VAR(t_dds_m_turn_on_off_delay_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_struct_ptr)
{
    uint8 local_output; /* Boolean */

    if ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)input)
    {   /* toff delay */
        if (0 != delay_off)
        {
            if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_on_off_delay_struct_ptr->previous_input)
            {
                (void)DDS_M_TIMER_INIT(current_time,
                                        &(turn_on_off_delay_struct_ptr->m_timer_str));

                turn_on_off_delay_struct_ptr->previous_input = DDS_FALSE;
            }
            else
            {
                /* Do nothing */
            }

            if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_on_off_delay_struct_ptr->previous_output)
            {
                local_output
                         = DDS_M_TIMER(current_time ,
                                   delay_off ,
                                   &(turn_on_off_delay_struct_ptr->m_timer_str));
                if ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)local_output)
                {
                    turn_on_off_delay_struct_ptr->previous_output = DDS_TRUE;
                }
                else
                {
                    turn_on_off_delay_struct_ptr->previous_output = DDS_FALSE;
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            turn_on_off_delay_struct_ptr->previous_input = DDS_FALSE;
            turn_on_off_delay_struct_ptr->previous_output = DDS_FALSE;
        }
    }
    else
    {   /* ton delay */
        if (0 != delay_off)
        {
            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_off_delay_struct_ptr->previous_input)
            {
                (void)DDS_M_TIMER_INIT(current_time,
                                        &(turn_on_off_delay_struct_ptr->m_timer_str));

                turn_on_off_delay_struct_ptr->previous_input = DDS_TRUE;
            }
            else
            {
                /* Do nothing */
            }

            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_off_delay_struct_ptr->previous_output)
            {
                turn_on_off_delay_struct_ptr->previous_output
                         = DDS_M_TIMER(current_time ,
                                   delay_on ,
                                   &(turn_on_off_delay_struct_ptr->m_timer_str));
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            turn_on_off_delay_struct_ptr->previous_input = DDS_TRUE;
            turn_on_off_delay_struct_ptr->previous_output = DDS_TRUE;
        }
    }
    return(turn_on_off_delay_struct_ptr->previous_output);
}

/*******************************************************************************
*  Macro name: DDS_M_TURN_ON_OFF_DELAY_INIT
*
*  Description :
*  The following macro manage init of M_TURN_ON_OFF_DELAY function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the init value of TURN_ON_OFF_DELAY
*   turn_on_off_delay_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_on_off_delay_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_struct_ptr)
{
    turn_on_off_delay_struct_ptr->previous_input  = init_value;
    turn_on_off_delay_struct_ptr->previous_output = init_value;

    return(init_value);
}

/*******************************************************************************
*  Function name: DDS_M_TURN_ON_OFF_DELAY_DELTA
*
*  Description :
*  The following macro is used to apply a TURN ON OFF DELAY on input
*
*  Output = DDS_TRUE if Input = DDS_TRUE since DELAY_ON
*  Output = DDS_FALSE if Input = DDS_FALSE since DELAY_OFF
*
*
*  Where:
*   input is the input value to test
*   increment_time_delta is the ellapsed time between call
*   delay_on is the turn on duration
*   delay_off is the turn off duration
*   turn_on_off_delay_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   increment_time_delta, delay_on and delay_off must be of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY_DELTA(uint8 input, /* Boolean */
                   uint32 increment_time_delta,
                   uint32 delay_on,
                   uint32 delay_off,
                   CONSTP2VAR(t_dds_m_turn_on_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_delta_struct_ptr)
{
    if ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_off_delay_delta_struct_ptr->previous_output)
    {   /* ton delay */
        if((t_dds_m_uint)input != 0)
        {
            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)turn_on_off_delay_delta_struct_ptr->previous_input)
            {
                /* Init time counter */
                turn_on_off_delay_delta_struct_ptr->elapsed_time = 0;
            }
            else
            {
                /* count time */
                if(turn_on_off_delay_delta_struct_ptr->elapsed_time  < (DDS_UINT32_MAX - increment_time_delta) )
                {
                    turn_on_off_delay_delta_struct_ptr->elapsed_time = turn_on_off_delay_delta_struct_ptr->elapsed_time + increment_time_delta;
                }
                else
                {
                    turn_on_off_delay_delta_struct_ptr->elapsed_time = DDS_UINT32_MAX;
                }

                if(turn_on_off_delay_delta_struct_ptr->elapsed_time >= delay_on)
                {
                    /* time elasted */
                    turn_on_off_delay_delta_struct_ptr->previous_output = DDS_TRUE;
                }
                else
                {
                    /* time not elasted */
                }
            }
        }
        else
        {
            turn_on_off_delay_delta_struct_ptr->elapsed_time = 0;
        }
    }
    else
    {   /* toff delay */
        if((t_dds_m_uint)input != 1)
        {
            if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)turn_on_off_delay_delta_struct_ptr->previous_input)
            {
                turn_on_off_delay_delta_struct_ptr->elapsed_time = 0;
            }
            else
            {
                if(turn_on_off_delay_delta_struct_ptr->elapsed_time  < (DDS_UINT32_MAX - increment_time_delta) )
                {
                    turn_on_off_delay_delta_struct_ptr->elapsed_time = turn_on_off_delay_delta_struct_ptr->elapsed_time + increment_time_delta;
                }
                else
                {
                    turn_on_off_delay_delta_struct_ptr->elapsed_time = DDS_UINT32_MAX;
                }

                if(turn_on_off_delay_delta_struct_ptr->elapsed_time >= delay_off)
                {
                    turn_on_off_delay_delta_struct_ptr->previous_output = DDS_FALSE;
                }
                else
                {
                }
            }
        }
        else
        {
            turn_on_off_delay_delta_struct_ptr->elapsed_time = 0;
        }
    }

    turn_on_off_delay_delta_struct_ptr->previous_input = input;

    return(turn_on_off_delay_delta_struct_ptr->previous_output);
}

/*******************************************************************************
*  Macro name: DDS_M_TURN_ON_OFF_DELAY_DELTA_INIT
*
*  Description :
*  The following macro manage init of M_TURN_ON_OFF_DELAY_DELTA function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the init value of TURN_ON_OFF_DELAY
*   turn_on_off_delay_delta_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY_DELTA_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_on_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_delta_struct_ptr)
{
    turn_on_off_delay_delta_struct_ptr->previous_input  = init_value;
    turn_on_off_delay_delta_struct_ptr->previous_output = init_value;

    return(init_value);
}

/*******************************************************************************
*  Function name:  DDS_M_TIMER
*
*  Description :
*  The following function is used to perform a timer function.
*
*  If the current_time is greater than start_time + timer_duration
*   The output will be DDS_TRUE .
*  Else
*   The output will be DDS_FALSE.
*
*  Where:
*   current_time is the current time
*   timer_duration is the timer duration
*   timer_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   current_time and timer_duration must be of same BIN Point.
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TIMER(uint32 current_time,
                                  uint32 timer_duration,
                                  CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr)
{
    uint32 time_passed_tmp;

    /* Time passed calculation */
    time_passed_tmp = current_time - timer_struct_ptr->start_time;

    if(time_passed_tmp < timer_struct_ptr->time_passed)
    {
        timer_struct_ptr->time_passed = DDS_UINT32_MAX;
    }
    else
    {
        timer_struct_ptr->time_passed = time_passed_tmp;
    }


    if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)timer_struct_ptr->previous_output)
    {
        if(timer_struct_ptr->time_passed < timer_duration)
        {
            /* Do nothing */
        }
        else
        {
            timer_struct_ptr->previous_output = DDS_TRUE;
        }
    }
    else
    {
        /* Do nothing */
    }

    return(timer_struct_ptr->previous_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_TIMER_INIT
*
*  Description :
*  The following macro manage reset of timer managed by function DDS_M_TIMER.
*
*  previous_output = DDS_FALSE
*  start_time = current_time
*
*  Where:
*   current_time is the current time
*   timer_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TIMER_INIT(uint32 current_time,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr)
{
    timer_struct_ptr->previous_output   = DDS_FALSE;
    timer_struct_ptr->start_time        = current_time;
    timer_struct_ptr->time_passed       = 0;

    return(DDS_FALSE);
}


/*******************************************************************************
*  Function name:  DDS_M_TIMER_DISP_U16
*
*  Description :
*  The following function is used to perform a timer function.
*
*  If the current_time is greater than start_time + timer_duration
*   The output will be DDS_TRUE .
*  Else
*   The output will be DDS_FALSE.
*
*  Where:
*   current_time is the current time
*   timer_duration is the timer duration
*   time_passed represents the time passed since TIMER_INIT
*   timer_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   current_time and timer_duration must be of same BIN Point.
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_U16(uint32 current_time,
                                          uint32 timer_duration,
                                          CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) time_passed,
                                          CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr)
{
    uint8 result; /* Boolean */

    result = DDS_M_TIMER(current_time,
                     timer_duration,
                     timer_struct_ptr);

    *time_passed = (uint16)DDS_M_MIN(timer_struct_ptr->time_passed,DDS_UINT16_MAX);

    return(result);
}


/*******************************************************************************
*  Macro name:  DDS_M_TIMER_DISP_INIT_U16
*
*  Description :
*  The following macro manage reset of timer managed by function M_TIMER.
*
*  previous_output = DDS_FALSE
*  start_time = current_time
*
*  Where:
*   current_time is the current time
*   time_passed represents the time passed since TIMER_INIT
*   timer_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_INIT_U16(uint32 current_time,
                                          CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) time_passed,
                                          CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr)
{
    (void)DDS_M_TIMER_INIT(current_time,
                           timer_struct_ptr);

    *time_passed = (uint16)timer_struct_ptr->time_passed;

    return(DDS_FALSE);
}





/*******************************************************************************
*  Function name:  DDS_M_TIMER_DISP_U32
*
*  Description :
*  The following function is used to perform a timer function.
*
*  If the current_time is greater than start_time + timer_duration
*   The output will be DDS_TRUE .
*  Else
*   The output will be DDS_FALSE.
*
*  Where:
*   current_time is the current time
*   timer_duration is the timer duration
*   time_passed represents the time passed since TIMER_INIT
*   timer_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   current_time and timer_duration must be of same BIN Point.
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_U32(uint32 current_time,
                                          uint32 timer_duration,
                                          CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) time_passed,
                                          CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr)
{
    uint8 result; /* Boolean */

    result = DDS_M_TIMER(current_time,
                     timer_duration,
                     timer_struct_ptr);

    *time_passed = timer_struct_ptr->time_passed;

    return(result);
}


/*******************************************************************************
*  Macro name:  DDS_M_TIMER_DISP_INIT_U32
*
*  Description :
*  The following macro manage reset of timer managed by function M_TIMER.
*
*  previous_output = DDS_FALSE
*  start_time = current_time
*
*  Where:
*   current_time is the current time
*   time_passed represents the time passed since TIMER_INIT
*   timer_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_INIT_U32(uint32 current_time,
                  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) time_passed,
                  CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr)
{
    (void)DDS_M_TIMER_INIT(current_time,
                           timer_struct_ptr);

    *time_passed = timer_struct_ptr->time_passed;

    return(DDS_FALSE);
}




/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY_V1
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
*     Else
*       the value is interpolated
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :            *<-----------+------ "output_signal"
*             *                    :       .    :            |       (interpolated)
*             |                    :  .         :            |
*             |                    *            :            |
*             |                    |            :            |
*             |                    |            :            |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]           :          [n+1]
*                                               :
*             +--------- "time_delay" --------->:
*
*  Where:
*   sig_delay_struct_ptr is the structure associated to macro
*   input_sig_value is the input signal value
*   time_delay is the time delay of the signal
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V1(CONSTP2VAR(t_dds_m_sig_s16_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                sint16 input_sig_value,
                                                uint16 time_delay)
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) buffer_ptr_cpy;
    uint16 current_prescale_cpy;
    uint16 prescaler_cpy;
    uint16 buffer_size_cpy;
    uint16 ratio_delay_sched_cpy;
    uint16 buffer_last_pos_cpy;
    uint16 buffer_nb_data_cpy;

    uint32 nb_sched_from_current_sched;
    uint16 nb_sched_from_last_value;
    uint16 nb_sched_memorised;
    uint16 prescaler_offset;
    uint16 delta_pos;
    uint16 offset_sched;

    sint16 output_signal;
    sint32 delta_val;
    uint16 pos_younger_value;
    uint16 pos_older_value;


    current_prescale_cpy = sig_delay_struct_ptr->current_prescale;
    buffer_ptr_cpy = sig_delay_struct_ptr->buffer_ptr;
    buffer_size_cpy = sig_delay_struct_ptr->buffer_size;
    ratio_delay_sched_cpy = sig_delay_struct_ptr->ratio_delay_sched;
    buffer_last_pos_cpy = sig_delay_struct_ptr->buffer_last_pos;
    buffer_nb_data_cpy = sig_delay_struct_ptr->buffer_nb_data;
    prescaler_cpy = sig_delay_struct_ptr->prescaler;

    /* Check if the save is required */
    if ((t_dds_m_uint)current_prescale_cpy >= (t_dds_m_uint)prescaler_cpy)
    {
        /* Clear prescaler counter */
        current_prescale_cpy = 1;
        /* Calculate next position to save data */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy + (t_dds_m_uint)1);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy % (t_dds_m_uint)buffer_size_cpy);
        sig_delay_struct_ptr->buffer_last_pos = buffer_last_pos_cpy;
        /* Save signal value */
        buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] = input_sig_value;

        /* Update counter */
         if ((t_dds_m_uint)buffer_nb_data_cpy < (t_dds_m_uint)buffer_size_cpy)
         {
            buffer_nb_data_cpy = (uint16)((t_dds_m_uint)buffer_nb_data_cpy + (t_dds_m_uint)1);
            sig_delay_struct_ptr->buffer_nb_data = buffer_nb_data_cpy;
         }
         else
        {
            /* Do nothing */
        }
    }
    else
    {
        current_prescale_cpy = (uint16)((t_dds_m_uint)current_prescale_cpy + (t_dds_m_uint)1);
    }
    sig_delay_struct_ptr->current_prescale = current_prescale_cpy;

    if ((t_dds_m_uint)buffer_nb_data_cpy <= (t_dds_m_uint)1)
    {
        /* buffer_nb_data_cpy == 0 can't happen */
        output_signal = input_sig_value;
    }
    else
    {
        /* Calculate offset from last value */
        prescaler_offset = (uint16)((t_dds_m_uint)current_prescale_cpy - (t_dds_m_uint)1);
        nb_sched_from_current_sched = (uint32)((t_dds_m_uint)time_delay * (t_dds_m_uint)ratio_delay_sched_cpy);
        if (nb_sched_from_current_sched <= (uint32)prescaler_offset)
        {
            /* Return newest value */
            output_signal = input_sig_value;
        }
        else
        {
            nb_sched_memorised = (uint16)( (((t_dds_m_uint)buffer_nb_data_cpy-(t_dds_m_uint)1) * (t_dds_m_uint)prescaler_cpy) + \
                                           (t_dds_m_uint)prescaler_offset);
            if (nb_sched_from_current_sched >= (uint32)nb_sched_memorised)
            {
                /* Delay is too high */
                if ((t_dds_m_uint)buffer_nb_data_cpy < (t_dds_m_uint)buffer_size_cpy)
                {
                    pos_older_value = 0;
                }
                else
                {
                    pos_older_value = (uint16)((t_dds_m_uint)buffer_last_pos_cpy + (t_dds_m_uint)1);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
                    pos_older_value = (uint16)((t_dds_m_uint)pos_older_value % (t_dds_m_uint)buffer_size_cpy);
                }
                /* Return oldest value */
                output_signal = buffer_ptr_cpy[(t_dds_m_sint)pos_older_value];
            }
            else
            {
                nb_sched_from_last_value = (uint16)(nb_sched_from_current_sched - (uint32)prescaler_offset);
                delta_pos = (uint16)((t_dds_m_uint)nb_sched_from_last_value / (t_dds_m_uint)prescaler_cpy);
                offset_sched = (uint16)((t_dds_m_uint)nb_sched_from_last_value % (t_dds_m_uint)prescaler_cpy);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
                pos_younger_value = (uint16)( (((t_dds_m_uint)buffer_size_cpy + (t_dds_m_uint)buffer_last_pos_cpy) - (t_dds_m_uint)delta_pos) % \
                                              (t_dds_m_uint)buffer_size_cpy);
                if ((t_dds_m_uint)0 == (t_dds_m_uint)offset_sched)
                {
                    /* It corresponds to a memorised value */
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                }
                else
                {
                    /* Need to interpolate value */
                    pos_older_value = pos_younger_value;
                    if ((t_dds_m_uint)0 == (t_dds_m_uint)pos_older_value)
                    {
                        pos_younger_value = (uint16)((t_dds_m_uint)buffer_size_cpy - (t_dds_m_uint)1);
                    }
                    else
                    {
                        pos_younger_value = (uint16)((t_dds_m_uint)pos_older_value - (t_dds_m_uint)1);
                    }
                    delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                    delta_val = (delta_val * ((sint32)prescaler_cpy - (sint32)offset_sched)) / (sint32)prescaler_cpy;
                    output_signal = (sint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
                }
            }
        }
    }

    return output_signal;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY_V1_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   sig_delay_struct_ptr is the structure associated to macro
*   time_delay is the time delay of the signal
*   data_buffer_ptr is the pointer on the buffer where to save signal
*   data_buffer_size is the size of the saving buffer
*   prescaler_value is the number of DDS_M_SIG_U16_DELAY call before saving
*                   input_sig_value in buffer
*   scheduling_in_time_delay_res is the DDS_M_SIG_U16_DELAY scheduling in
*                               time_delay resolution
*
*  REMARKS:
*   There is no value in the buffer once init done.
*   Time delay resolution must be inferior or equal to the scheduling:
*   ratio_delay_sched > 0.
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V1_INIT(CONSTP2VAR(t_dds_m_sig_s16_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (sint16, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 prescaler_value,
                                                    uint16 ratio_delay_sched)
{
    sig_delay_struct_ptr->buffer_ptr = data_buffer_ptr;
    sig_delay_struct_ptr->buffer_size = data_buffer_size;
    sig_delay_struct_ptr->buffer_last_pos = (uint16)((t_dds_m_uint)data_buffer_size - (t_dds_m_uint)1);
    sig_delay_struct_ptr->buffer_nb_data = 0;

    if ((t_dds_m_uint)prescaler_value == (t_dds_m_uint)0)
    {
        sig_delay_struct_ptr->prescaler = 1;
        sig_delay_struct_ptr->current_prescale = 1;
    }
    else
    {
        sig_delay_struct_ptr->prescaler = prescaler_value;
        sig_delay_struct_ptr->current_prescale = prescaler_value;
    }

    sig_delay_struct_ptr->ratio_delay_sched = ratio_delay_sched;
}
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
*     Else
*       the value is interpolated
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :            *<-----------+------ "output_signal"
*             *                    :       .    :            |       (interpolated)
*             |                    :  .         :            |
*             |                    *            :            |
*             |                    |            :            |
*             |                    |            :            |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]           :          [n+1]
*                                               :
*             +--------- "time_delay" --------->:
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'input_sig_value' is the input signal value
*   'time_delay' is the time delay of the signal
*   'delta_time' is the time since last execution of function (must have same resolution of time_delay)
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V2(CONSTP2VAR(t_dds_m_sig_s16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                sint16 input_sig_value,
                                                uint16 time_delay)
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) buffer_ptr_cpy;
    uint16 current_prescale_cpy;
    uint16 prescaler_cpy;
    uint16 buffer_size_cpy;
    uint16 buffer_last_pos_cpy;
    uint16 buffer_nb_data_cpy;
    uint16 delay_sched_cpy;


    uint16 prescaler_offset;
    uint16 nb_sched_time_delay;
    uint16 offset_sched_time_delay;
    uint16 nb_sched_memorised;
    uint16 nb_sched_from_last_memorised;
    uint16 nb_sched_from_last_data_cpy;
    uint16 nb_snapshot_from_last_copy;
    uint16 offset_from_younger;

    sint16 output_signal;
    sint32 delta_val;
    sint32 timing_prescaler;
    sint32 timing_from_younger;
    sint32 pos_younger_value;
    sint32 pos_older_value;

    current_prescale_cpy = sig_delay_struct_ptr->current_prescale;
    buffer_ptr_cpy = sig_delay_struct_ptr->buffer_ptr;
    buffer_size_cpy = sig_delay_struct_ptr->buffer_size;
    buffer_last_pos_cpy = sig_delay_struct_ptr->buffer_last_pos;
    buffer_nb_data_cpy = sig_delay_struct_ptr->buffer_nb_data;
    prescaler_cpy = sig_delay_struct_ptr->prescaler;
    delay_sched_cpy = sig_delay_struct_ptr->delay_sched;

    /* Check if the save is required */
    if ((t_dds_m_uint)current_prescale_cpy >= (t_dds_m_uint)prescaler_cpy)
    {
        /* Clear prescaler counter */
        current_prescale_cpy = 1;
        /* Calculate next position to save data */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy + (t_dds_m_uint)1);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy % (t_dds_m_uint)buffer_size_cpy);
        sig_delay_struct_ptr->buffer_last_pos = buffer_last_pos_cpy;
        /* Save signal value */
        buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] = input_sig_value;

        /* Update counter */
         if ((t_dds_m_uint)buffer_nb_data_cpy < (t_dds_m_uint)buffer_size_cpy)
         {
            buffer_nb_data_cpy = (uint16)((t_dds_m_uint)buffer_nb_data_cpy + (t_dds_m_uint)1);
            sig_delay_struct_ptr->buffer_nb_data = buffer_nb_data_cpy;
         }
         else
        {
            /* Do nothing */
        }
    }
    else
    {
        current_prescale_cpy = (uint16)((t_dds_m_uint)current_prescale_cpy + (t_dds_m_uint)1);
    }
    sig_delay_struct_ptr->current_prescale = current_prescale_cpy;

    /* Check if a data has been memorised */
    if (0 == (t_dds_m_uint)buffer_nb_data_cpy)
    {
        output_signal = sig_delay_struct_ptr->default_val;
    }
    else
    {
        /* Calculate delay in number of scheduling */
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        nb_sched_time_delay = (uint16)((uint32)time_delay / (uint32)delay_sched_cpy);
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        offset_sched_time_delay = (uint16)((uint32)time_delay % (uint32)delay_sched_cpy);
        /* Calculate number of scheduling memorised (virtualy) */
        prescaler_offset = (uint16)((t_dds_m_uint)current_prescale_cpy - (t_dds_m_uint)1);
        nb_sched_memorised = (uint16)( (((t_dds_m_uint)buffer_nb_data_cpy-(t_dds_m_uint)1) * (t_dds_m_uint)prescaler_cpy) + \
                                   (t_dds_m_uint)prescaler_offset);

        if (((t_dds_m_uint)nb_sched_memorised < (t_dds_m_uint)nb_sched_time_delay) &&
            ((t_dds_m_uint)0 == (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if (((t_dds_m_uint)nb_sched_memorised <= (t_dds_m_uint)nb_sched_time_delay) &&
                ((t_dds_m_uint)0 != (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if ((t_dds_m_uint)nb_sched_time_delay < (t_dds_m_uint)prescaler_offset)
        {
            /* Return newest value */
            nb_sched_from_last_memorised = (uint16)((t_dds_m_uint)prescaler_offset - (t_dds_m_uint)nb_sched_time_delay);
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
/* <PRQA_COMMENT><2992><2996> test for security </2996></2992></PRQA_COMMENT> */
                if ((uint32)0 == (uint32)nb_sched_from_last_memorised)
                {
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                }
                else
                {
                    delta_val = (sint32)input_sig_value - (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                    delta_val = ((delta_val / (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) + \
                                (((delta_val % (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) / (sint32)prescaler_offset);
                    output_signal = (sint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] + delta_val);
                }
            }
            else
            {
                timing_prescaler = (sint32)prescaler_offset * (sint32)delay_sched_cpy;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] - (sint32)input_sig_value;
                delta_val = ((delta_val / timing_prescaler) * (sint32)time_delay) + \
                            (((delta_val % timing_prescaler) * (sint32)time_delay) / timing_prescaler);
                output_signal = (sint16)((sint32)input_sig_value + delta_val);
            }
        }
        else if (((uint32)nb_sched_time_delay == (uint32)prescaler_offset) && \
                 ((uint32)0 == (uint32)offset_sched_time_delay))
        {
                /* It is the last memorised value */
                output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
        }
        else
        {
            /* Calculate offset in scheduling from last memorised value */
            nb_sched_from_last_data_cpy = (uint16)((sint32)nb_sched_time_delay - (sint32)prescaler_offset);
            /* Calculate offset in table scale */
            nb_snapshot_from_last_copy = (uint16)((sint32)nb_sched_from_last_data_cpy / (sint32)prescaler_cpy);

            /* Check if in the table */
            if ((uint32)buffer_last_pos_cpy >= (uint32)nb_snapshot_from_last_copy)
            {
                pos_younger_value = (t_dds_m_sint)buffer_last_pos_cpy - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            else
            {
                pos_younger_value = ((t_dds_m_sint)buffer_size_cpy + (t_dds_m_sint)buffer_last_pos_cpy)  - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            /* Check if interpolation is required */
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
                offset_from_younger = (uint16)((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy);
                if ((uint32)0 == (uint32)offset_from_younger)
                {
                    /* No interpolation */
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                }
                else
                {
                    /* Calculate older value position */
                    if ((sint32)0 == pos_younger_value)
                    {
                        pos_older_value = (t_dds_m_sint)buffer_size_cpy - 1;
                    }
                    else
                    {
                        pos_older_value = pos_younger_value - 1;
                    }
                    /* Interpolate */
                    delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                    delta_val = ((delta_val / (sint32)prescaler_cpy) * (sint32)offset_from_younger) + \
                                (((delta_val % (sint32)prescaler_cpy) * (sint32)offset_from_younger) / (sint32)prescaler_cpy);
                    output_signal = (sint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
                }
            }
            else
            {
                offset_from_younger = (uint16)(((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy) + 1);
                /* Calculate older value position */
                if ((uint32)0 == (uint32)pos_younger_value)
                {
                    pos_older_value = (sint32)buffer_size_cpy - 1;
                }
                else
                {
                    pos_older_value = pos_younger_value - 1;
                }
                /* Interpolate */
                timing_prescaler = (sint32)prescaler_cpy * (sint32)delay_sched_cpy;
                timing_from_younger = ((sint32)(offset_from_younger) * (sint32)delay_sched_cpy) - (sint32)offset_sched_time_delay;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                delta_val = ((delta_val / timing_prescaler) * timing_from_younger) + \
                            (((delta_val % timing_prescaler) * timing_from_younger) / timing_prescaler);
                output_signal = (sint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
            }
        }
    }
    return output_signal;
}
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY_V2_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'data_buffer_ptr' is the pointer on the buffer where to save signal
*   'data_buffer_size' is the size of the saving buffer
*   'prescaler_value' is frequency of saving input signal in scheduling resolution
*   'delay_sched' is the scheduling of the call of DDS_M_SIGNAL_S16_DELAY_V2 (avoid to memorise exact timing)
*
*  REMARKS:
*   There is no value in the buffer once init done.
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_s16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (sint16, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 prescaler_value,
                                                    uint16 delay_sched,
                                                    sint16 default_value)
{
    sig_delay_struct_ptr->buffer_ptr = data_buffer_ptr;
    sig_delay_struct_ptr->buffer_size = data_buffer_size;
    sig_delay_struct_ptr->buffer_last_pos = (uint16)((t_dds_m_uint)data_buffer_size - (t_dds_m_uint)1);
    sig_delay_struct_ptr->buffer_nb_data = 0;

    if ((t_dds_m_uint)prescaler_value == (t_dds_m_uint)0)
    {
        sig_delay_struct_ptr->prescaler = 1;
        sig_delay_struct_ptr->current_prescale = 1;
    }
    else
    {
        sig_delay_struct_ptr->prescaler = prescaler_value;
        sig_delay_struct_ptr->current_prescale = prescaler_value;
    }
    sig_delay_struct_ptr->delay_sched = delay_sched;
    sig_delay_struct_ptr->default_val = default_value;
}
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_U16_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
*     Else
*       the value is interpolated
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :            *<-----------+------ "output_signal"
*             *                    :       .    :            |       (interpolated)
*             |                    :  .         :            |
*             |                    *            :            |
*             |                    |            :            |
*             |                    |            :            |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]           :          [n+1]
*                                               :
*             +--------- "time_delay" --------->:
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'input_sig_value' is the input signal value
*   'time_delay' is the time delay of the signal
*   'delta_time' is the time since last execution of function (must have same resolution of time_delay)
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_SIGNAL_U16_DELAY_V2(CONSTP2VAR(t_dds_m_sig_u16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                uint16 input_sig_value,
                                                uint16 time_delay)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) buffer_ptr_cpy;
    uint16 current_prescale_cpy;
    uint16 prescaler_cpy;
    uint16 buffer_size_cpy;
    uint16 buffer_last_pos_cpy;
    uint16 buffer_nb_data_cpy;
    uint16 delay_sched_cpy;


    uint16 prescaler_offset;
    uint16 nb_sched_time_delay;
    uint16 offset_sched_time_delay;
    uint16 nb_sched_memorised;
    uint16 nb_sched_from_last_memorised;
    uint16 nb_sched_from_last_data_cpy;
    uint16 nb_snapshot_from_last_copy;
    uint16 offset_from_younger;

    uint16 output_signal;
    sint32 delta_val;
    sint32 timing_prescaler;
    sint32 timing_from_younger;
    sint32 pos_younger_value;
    sint32 pos_older_value;

    current_prescale_cpy = sig_delay_struct_ptr->current_prescale;
    buffer_ptr_cpy = sig_delay_struct_ptr->buffer_ptr;
    buffer_size_cpy = sig_delay_struct_ptr->buffer_size;
    buffer_last_pos_cpy = sig_delay_struct_ptr->buffer_last_pos;
    buffer_nb_data_cpy = sig_delay_struct_ptr->buffer_nb_data;
    prescaler_cpy = sig_delay_struct_ptr->prescaler;
    delay_sched_cpy = sig_delay_struct_ptr->delay_sched;

    /* Check if the save is required */
    if ((t_dds_m_uint)current_prescale_cpy >= (t_dds_m_uint)prescaler_cpy)
    {
        /* Clear prescaler counter */
        current_prescale_cpy = 1;
        /* Calculate next position to save data */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy + (t_dds_m_uint)1);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy % (t_dds_m_uint)buffer_size_cpy);
        sig_delay_struct_ptr->buffer_last_pos = buffer_last_pos_cpy;
        /* Save signal value */
        buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] = input_sig_value;

        /* Update counter */
         if ((t_dds_m_uint)buffer_nb_data_cpy < (t_dds_m_uint)buffer_size_cpy)
         {
            buffer_nb_data_cpy = (uint16)((t_dds_m_uint)buffer_nb_data_cpy + (t_dds_m_uint)1);
            sig_delay_struct_ptr->buffer_nb_data = buffer_nb_data_cpy;
         }
         else
        {
            /* Do nothing */
        }
    }
    else
    {
        current_prescale_cpy = (uint16)((t_dds_m_uint)current_prescale_cpy + (t_dds_m_uint)1);
    }
    sig_delay_struct_ptr->current_prescale = current_prescale_cpy;

    /* Check if a data has been memorised */
    if (0 == (t_dds_m_uint)buffer_nb_data_cpy)
    {
        output_signal = sig_delay_struct_ptr->default_val;
    }
    else
    {
        /* Calculate delay in number of scheduling */
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        nb_sched_time_delay = (uint16)((uint32)time_delay / (uint32)delay_sched_cpy);
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        offset_sched_time_delay = (uint16)((uint32)time_delay % (uint32)delay_sched_cpy);
        /* Calculate number of scheduling memorised (virtualy) */
        prescaler_offset = (uint16)((t_dds_m_uint)current_prescale_cpy - (t_dds_m_uint)1);
        nb_sched_memorised = (uint16)( (((t_dds_m_uint)buffer_nb_data_cpy-(t_dds_m_uint)1) * (t_dds_m_uint)prescaler_cpy) + \
                                   (t_dds_m_uint)prescaler_offset);

        if (((t_dds_m_uint)nb_sched_memorised < (t_dds_m_uint)nb_sched_time_delay) &&
            ((t_dds_m_uint)0 == (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if (((t_dds_m_uint)nb_sched_memorised <= (t_dds_m_uint)nb_sched_time_delay) &&
                ((t_dds_m_uint)0 != (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if ((t_dds_m_uint)nb_sched_time_delay < (t_dds_m_uint)prescaler_offset)
        {
            /* Return newest value */
            nb_sched_from_last_memorised = (uint16)((t_dds_m_uint)prescaler_offset - (t_dds_m_uint)nb_sched_time_delay);
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
/* <PRQA_COMMENT><2996><2992> test for security </2992></2996></PRQA_COMMENT> */
                if ((uint32)0 == (uint32)nb_sched_from_last_memorised)
                {
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                }
                else
                {
                    delta_val = (sint32)input_sig_value - (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                    delta_val = ((delta_val / (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) + \
                                (((delta_val % (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) / (sint32)prescaler_offset);
                    output_signal = (uint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] + delta_val);
                }
            }
            else
            {
                timing_prescaler = (sint32)prescaler_offset * (sint32)delay_sched_cpy;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] - (sint32)input_sig_value;
                delta_val = ((delta_val / timing_prescaler) * (sint32)time_delay) + \
                            (((delta_val % timing_prescaler) * (sint32)time_delay) / timing_prescaler);
                output_signal = (uint16)((sint32)input_sig_value + delta_val);
            }
        }
        else if (((uint32)nb_sched_time_delay == (uint32)prescaler_offset) && \
                 ((uint32)0 == (uint32)offset_sched_time_delay))
        {
                /* It is the last memorised value */
                output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
        }
        else
        {
            /* Calculate offset in scheduling from last memorised value */
            nb_sched_from_last_data_cpy = (uint16)((sint32)nb_sched_time_delay - (sint32)prescaler_offset);
            /* Calculate offset in table scale */
            nb_snapshot_from_last_copy = (uint16)((sint32)nb_sched_from_last_data_cpy / (sint32)prescaler_cpy);

            /* Check if in the table */
            if ((uint32)buffer_last_pos_cpy >= (uint32)nb_snapshot_from_last_copy)
            {
                pos_younger_value = (t_dds_m_sint)buffer_last_pos_cpy - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            else
            {
                pos_younger_value = ((t_dds_m_sint)buffer_size_cpy + (t_dds_m_sint)buffer_last_pos_cpy)  - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            /* Check if interpolation is required */
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
                offset_from_younger = (uint16)((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy);
                if ((uint32)0 == (uint32)offset_from_younger)
                {
                    /* No interpolation */
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                }
                else
                {
                    /* Calculate older value position */
                    if ((sint32)0 == pos_younger_value)
                    {
                        pos_older_value = (t_dds_m_sint)buffer_size_cpy - 1;
                    }
                    else
                    {
                        pos_older_value = pos_younger_value - 1;
                    }
                    /* Interpolate */
                    delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                    delta_val = ((delta_val / (sint32)prescaler_cpy) * (sint32)offset_from_younger) + \
                                (((delta_val % (sint32)prescaler_cpy) * (sint32)offset_from_younger) / (sint32)prescaler_cpy);
                    output_signal = (uint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
                }
            }
            else
            {
                offset_from_younger = (uint16)(((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy) + 1);
                /* Calculate older value position */
                if ((uint32)0 == (uint32)pos_younger_value)
                {
                    pos_older_value = (sint32)buffer_size_cpy - 1;
                }
                else
                {
                    pos_older_value = pos_younger_value - 1;
                }
                /* Interpolate */
                timing_prescaler = (sint32)prescaler_cpy * (sint32)delay_sched_cpy;
                timing_from_younger = ((sint32)(offset_from_younger) * (sint32)delay_sched_cpy) - (sint32)offset_sched_time_delay;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                delta_val = ((delta_val / timing_prescaler) * timing_from_younger) + \
                            (((delta_val % timing_prescaler) * timing_from_younger) / timing_prescaler);
                output_signal = (uint16)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
            }
        }
    }
    return output_signal;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_U16_DELAY_V2_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'data_buffer_ptr' is the pointer on the buffer where to save signal
*   'data_buffer_size' is the size of the saving buffer
*   'prescaler_value' is frequency of saving input signal in scheduling resolution
*   'delay_sched' is the scheduling of the call of DDS_M_SIGNAL_U16_DELAY_V2 (avoid to memorise exact timing)
*
*  REMARKS:
*   There is no value in the buffer once init done.
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SIGNAL_U16_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_u16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (uint16, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 prescaler_value,
                                                    uint16 delay_sched,
                                                    uint16 default_value)
{
    sig_delay_struct_ptr->buffer_ptr = data_buffer_ptr;
    sig_delay_struct_ptr->buffer_size = data_buffer_size;
    sig_delay_struct_ptr->buffer_last_pos = (uint16)((t_dds_m_uint)data_buffer_size - (t_dds_m_uint)1);
    sig_delay_struct_ptr->buffer_nb_data = 0;

    if ((t_dds_m_uint)prescaler_value == (t_dds_m_uint)0)
    {
        sig_delay_struct_ptr->prescaler = 1;
        sig_delay_struct_ptr->current_prescale = 1;
    }
    else
    {
        sig_delay_struct_ptr->prescaler = prescaler_value;
        sig_delay_struct_ptr->current_prescale = prescaler_value;
    }
    sig_delay_struct_ptr->delay_sched = delay_sched;
    sig_delay_struct_ptr->default_val = default_value;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_U8_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
*     Else
*       the value is interpolated
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :            *<-----------+------ "output_signal"
*             *                    :       .    :            |       (interpolated)
*             |                    :  .         :            |
*             |                    *            :            |
*             |                    |            :            |
*             |                    |            :            |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]           :          [n+1]
*                                               :
*             +--------- "time_delay" --------->:
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'input_sig_value' is the input signal value
*   'time_delay' is the time delay of the signal
*   'delta_time' is the time since last execution of function (must have same resolution of time_delay)
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_SIGNAL_U8_DELAY_V2(CONSTP2VAR(t_dds_m_sig_u8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                uint8 input_sig_value,
                                                uint16 time_delay)
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) buffer_ptr_cpy;
    uint16 current_prescale_cpy;
    uint16 prescaler_cpy;
    uint16 buffer_size_cpy;
    uint16 buffer_last_pos_cpy;
    uint16 buffer_nb_data_cpy;
    uint16 delay_sched_cpy;


    uint16 prescaler_offset;
    uint16 nb_sched_time_delay;
    uint16 offset_sched_time_delay;
    uint16 nb_sched_memorised;
    uint16 nb_sched_from_last_memorised;
    uint16 nb_sched_from_last_data_cpy;
    uint16 nb_snapshot_from_last_copy;
    uint16 offset_from_younger;

    uint8 output_signal;
    sint32 delta_val;
    sint32 timing_prescaler;
    sint32 timing_from_younger;
    sint32 pos_younger_value;
    sint32 pos_older_value;

    current_prescale_cpy = sig_delay_struct_ptr->current_prescale;
    buffer_ptr_cpy = sig_delay_struct_ptr->buffer_ptr;
    buffer_size_cpy = sig_delay_struct_ptr->buffer_size;
    buffer_last_pos_cpy = sig_delay_struct_ptr->buffer_last_pos;
    buffer_nb_data_cpy = sig_delay_struct_ptr->buffer_nb_data;
    prescaler_cpy = sig_delay_struct_ptr->prescaler;
    delay_sched_cpy = sig_delay_struct_ptr->delay_sched;

    /* Check if the save is required */
    if ((t_dds_m_uint)current_prescale_cpy >= (t_dds_m_uint)prescaler_cpy)
    {
        /* Clear prescaler counter */
        current_prescale_cpy = 1;
        /* Calculate next position to save data */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy + (t_dds_m_uint)1);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy % (t_dds_m_uint)buffer_size_cpy);
        sig_delay_struct_ptr->buffer_last_pos = buffer_last_pos_cpy;
        /* Save signal value */
        buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] = input_sig_value;

        /* Update counter */
         if ((t_dds_m_uint)buffer_nb_data_cpy < (t_dds_m_uint)buffer_size_cpy)
         {
            buffer_nb_data_cpy = (uint16)((t_dds_m_uint)buffer_nb_data_cpy + (t_dds_m_uint)1);
            sig_delay_struct_ptr->buffer_nb_data = buffer_nb_data_cpy;
         }
         else
        {
            /* Do nothing */
        }
    }
    else
    {
        current_prescale_cpy = (uint16)((t_dds_m_uint)current_prescale_cpy + (t_dds_m_uint)1);
    }
    sig_delay_struct_ptr->current_prescale = current_prescale_cpy;

    /* Check if a data has been memorised */
    if (0 == (t_dds_m_uint)buffer_nb_data_cpy)
    {
        output_signal = sig_delay_struct_ptr->default_val;
    }
    else
    {
        /* Calculate delay in number of scheduling */
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        nb_sched_time_delay = (uint16)((uint32)time_delay / (uint32)delay_sched_cpy);
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        offset_sched_time_delay = (uint16)((uint32)time_delay % (uint32)delay_sched_cpy);
        /* Calculate number of scheduling memorised (virtualy) */
        prescaler_offset = (uint16)((t_dds_m_uint)current_prescale_cpy - (t_dds_m_uint)1);
        nb_sched_memorised = (uint16)( (((t_dds_m_uint)buffer_nb_data_cpy-(t_dds_m_uint)1) * (t_dds_m_uint)prescaler_cpy) + \
                                   (t_dds_m_uint)prescaler_offset);

        if (((t_dds_m_uint)nb_sched_memorised < (t_dds_m_uint)nb_sched_time_delay) &&
            ((t_dds_m_uint)0 == (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if (((t_dds_m_uint)nb_sched_memorised <= (t_dds_m_uint)nb_sched_time_delay) &&
                ((t_dds_m_uint)0 != (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if ((t_dds_m_uint)nb_sched_time_delay < (t_dds_m_uint)prescaler_offset)
        {
            /* Return newest value */
            nb_sched_from_last_memorised = (uint16)((t_dds_m_uint)prescaler_offset - (t_dds_m_uint)nb_sched_time_delay);
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
/* <PRQA_COMMENT><2996><2992> test for security </2992></2996></PRQA_COMMENT> */
                if ((uint32)0 == (uint32)nb_sched_from_last_memorised)
                {
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                }
                else
                {
                    delta_val = (sint32)input_sig_value - (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                    delta_val = ((delta_val / (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) + \
                                (((delta_val % (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) / (sint32)prescaler_offset);
                    output_signal = (uint8)((sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] + delta_val);
                }
            }
            else
            {
                timing_prescaler = (sint32)prescaler_offset * (sint32)delay_sched_cpy;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] - (sint32)input_sig_value;
                delta_val = ((delta_val / timing_prescaler) * (sint32)time_delay) + \
                            (((delta_val % timing_prescaler) * (sint32)time_delay) / timing_prescaler);
                output_signal = (uint8)((sint32)input_sig_value + delta_val);
            }
        }
        else if (((uint32)nb_sched_time_delay == (uint32)prescaler_offset) && \
                 ((uint32)0 == (uint32)offset_sched_time_delay))
        {
                /* It is the last memorised value */
                output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
        }
        else
        {
            /* Calculate offset in scheduling from last memorised value */
            nb_sched_from_last_data_cpy = (uint16)((sint32)nb_sched_time_delay - (sint32)prescaler_offset);
            /* Calculate offset in table scale */
            nb_snapshot_from_last_copy = (uint16)((sint32)nb_sched_from_last_data_cpy / (sint32)prescaler_cpy);

            /* Check if in the table */
            if ((uint32)buffer_last_pos_cpy >= (uint32)nb_snapshot_from_last_copy)
            {
                pos_younger_value = (t_dds_m_sint)buffer_last_pos_cpy - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            else
            {
                pos_younger_value = ((t_dds_m_sint)buffer_size_cpy + (t_dds_m_sint)buffer_last_pos_cpy)  - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            /* Check if interpolation is required */
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
                offset_from_younger = (uint16)((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy);
                if ((uint32)0 == (uint32)offset_from_younger)
                {
                    /* No interpolation */
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                }
                else
                {
                    /* Calculate older value position */
                    if ((sint32)0 == pos_younger_value)
                    {
                        pos_older_value = (t_dds_m_sint)buffer_size_cpy - 1;
                    }
                    else
                    {
                        pos_older_value = pos_younger_value - 1;
                    }
                    /* Interpolate */
                    delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                    delta_val = ((delta_val / (sint32)prescaler_cpy) * (sint32)offset_from_younger) + \
                                (((delta_val % (sint32)prescaler_cpy) * (sint32)offset_from_younger) / (sint32)prescaler_cpy);
                    output_signal = (uint8)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
                }
            }
            else
            {
                offset_from_younger = (uint16)(((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy) + 1);
                /* Calculate older value position */
                if ((uint32)0 == (uint32)pos_younger_value)
                {
                    pos_older_value = (sint32)buffer_size_cpy - 1;
                }
                else
                {
                    pos_older_value = pos_younger_value - 1;
                }
                /* Interpolate */
                timing_prescaler = (sint32)prescaler_cpy * (sint32)delay_sched_cpy;
                timing_from_younger = ((sint32)(offset_from_younger) * (sint32)delay_sched_cpy) - (sint32)offset_sched_time_delay;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                delta_val = ((delta_val / timing_prescaler) * timing_from_younger) + \
                            (((delta_val % timing_prescaler) * timing_from_younger) / timing_prescaler);
                output_signal = (uint8)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
            }
        }
    }
    return output_signal;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_U8_DELAY_V2_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'data_buffer_ptr' is the pointer on the buffer where to save signal
*   'data_buffer_size' is the size of the saving buffer
*   'prescaler_value' is frequency of saving input signal in scheduling resolution
*   'delay_sched' is the scheduling of the call of DDS_M_SIGNAL_U8_DELAY_V2 (avoid to memorise exact timing)
*
*  REMARKS:
*   There is no value in the buffer once init done.
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SIGNAL_U8_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_u8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 prescaler_value,
                                                    uint16 delay_sched,
                                                    uint8 default_value)
{
    sig_delay_struct_ptr->buffer_ptr = data_buffer_ptr;
    sig_delay_struct_ptr->buffer_size = data_buffer_size;
    sig_delay_struct_ptr->buffer_last_pos = (uint16)((t_dds_m_uint)data_buffer_size - (t_dds_m_uint)1);
    sig_delay_struct_ptr->buffer_nb_data = 0;

    if ((t_dds_m_uint)prescaler_value == (t_dds_m_uint)0)
    {
        sig_delay_struct_ptr->prescaler = 1;
        sig_delay_struct_ptr->current_prescale = 1;
    }
    else
    {
        sig_delay_struct_ptr->prescaler = prescaler_value;
        sig_delay_struct_ptr->current_prescale = prescaler_value;
    }
    sig_delay_struct_ptr->delay_sched = delay_sched;
    sig_delay_struct_ptr->default_val = default_value;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S8_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
*     Else
*       the value is interpolated
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :            *<-----------+------ "output_signal"
*             *                    :       .    :            |       (interpolated)
*             |                    :  .         :            |
*             |                    *            :            |
*             |                    |            :            |
*             |                    |            :            |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]           :          [n+1]
*                                               :
*             +--------- "time_delay" --------->:
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'input_sig_value' is the input signal value
*   'time_delay' is the time delay of the signal
*   'delta_time' is the time since last execution of function (must have same resolution of time_delay)
*
*******************************************************************************/
FUNC(sint8, AUTOMATIC) DDS_M_SIGNAL_S8_DELAY_V2(CONSTP2VAR(t_dds_m_sig_s8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                sint8 input_sig_value,
                                                uint16 time_delay)
{
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) buffer_ptr_cpy;
    uint16 current_prescale_cpy;
    uint16 prescaler_cpy;
    uint16 buffer_size_cpy;
    uint16 buffer_last_pos_cpy;
    uint16 buffer_nb_data_cpy;
    uint16 delay_sched_cpy;


    uint16 prescaler_offset;
    uint16 nb_sched_time_delay;
    uint16 offset_sched_time_delay;
    uint16 nb_sched_memorised;
    uint16 nb_sched_from_last_memorised;
    uint16 nb_sched_from_last_data_cpy;
    uint16 nb_snapshot_from_last_copy;
    uint16 offset_from_younger;

    sint8 output_signal;
    sint32 delta_val;
    sint32 timing_prescaler;
    sint32 timing_from_younger;
    sint32 pos_younger_value;
    sint32 pos_older_value;

    current_prescale_cpy = sig_delay_struct_ptr->current_prescale;
    buffer_ptr_cpy = sig_delay_struct_ptr->buffer_ptr;
    buffer_size_cpy = sig_delay_struct_ptr->buffer_size;
    buffer_last_pos_cpy = sig_delay_struct_ptr->buffer_last_pos;
    buffer_nb_data_cpy = sig_delay_struct_ptr->buffer_nb_data;
    prescaler_cpy = sig_delay_struct_ptr->prescaler;
    delay_sched_cpy = sig_delay_struct_ptr->delay_sched;

    /* Check if the save is required */
    if ((t_dds_m_uint)current_prescale_cpy >= (t_dds_m_uint)prescaler_cpy)
    {
        /* Clear prescaler counter */
        current_prescale_cpy = 1;
        /* Calculate next position to save data */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy + (t_dds_m_uint)1);
/* <PRQA_COMMENT><2834> "buffer_size_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        buffer_last_pos_cpy = (uint16)((t_dds_m_uint)buffer_last_pos_cpy % (t_dds_m_uint)buffer_size_cpy);
        sig_delay_struct_ptr->buffer_last_pos = buffer_last_pos_cpy;
        /* Save signal value */
        buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] = input_sig_value;

        /* Update counter */
         if ((t_dds_m_uint)buffer_nb_data_cpy < (t_dds_m_uint)buffer_size_cpy)
         {
            buffer_nb_data_cpy = (uint16)((t_dds_m_uint)buffer_nb_data_cpy + (t_dds_m_uint)1);
            sig_delay_struct_ptr->buffer_nb_data = buffer_nb_data_cpy;
         }
         else
        {
            /* Do nothing */
        }
    }
    else
    {
        current_prescale_cpy = (uint16)((t_dds_m_uint)current_prescale_cpy + (t_dds_m_uint)1);
    }
    sig_delay_struct_ptr->current_prescale = current_prescale_cpy;

    /* Check if a data has been memorised */
    if (0 == (t_dds_m_uint)buffer_nb_data_cpy)
    {
        output_signal = sig_delay_struct_ptr->default_val;
    }
    else
    {
        /* Calculate delay in number of scheduling */
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        nb_sched_time_delay = (uint16)((uint32)time_delay / (uint32)delay_sched_cpy);
/* <PRQA_COMMENT><2834> "delay_sched_cpy" can never be equal to 0.</2834></PRQA_COMMENT> */
        offset_sched_time_delay = (uint16)((uint32)time_delay % (uint32)delay_sched_cpy);
        /* Calculate number of scheduling memorised (virtualy) */
        prescaler_offset = (uint16)((t_dds_m_uint)current_prescale_cpy - (t_dds_m_uint)1);
        nb_sched_memorised = (uint16)( (((t_dds_m_uint)buffer_nb_data_cpy-(t_dds_m_uint)1) * (t_dds_m_uint)prescaler_cpy) + \
                                   (t_dds_m_uint)prescaler_offset);

        if (((t_dds_m_uint)nb_sched_memorised < (t_dds_m_uint)nb_sched_time_delay) &&
            ((t_dds_m_uint)0 == (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if (((t_dds_m_uint)nb_sched_memorised <= (t_dds_m_uint)nb_sched_time_delay) &&
                ((t_dds_m_uint)0 != (t_dds_m_uint)offset_sched_time_delay))
        {
            /* Not enougth data return 0 */
            output_signal = sig_delay_struct_ptr->default_val;
        }
        else if ((t_dds_m_uint)nb_sched_time_delay < (t_dds_m_uint)prescaler_offset)
        {
            /* Return newest value */
            nb_sched_from_last_memorised = (uint16)((t_dds_m_uint)prescaler_offset - (t_dds_m_uint)nb_sched_time_delay);
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
/* <PRQA_COMMENT><2996><2992> test for security </2992></2996></PRQA_COMMENT> */
                if ((uint32)0 == (uint32)nb_sched_from_last_memorised)
                {
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                }
                else
                {
                    delta_val = (sint32)input_sig_value - (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
                    delta_val = ((delta_val / (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) + \
                                (((delta_val % (sint32)prescaler_offset) * (sint32)nb_sched_from_last_memorised) / (sint32)prescaler_offset);
                    output_signal = (sint8)((sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] + delta_val);
                }
            }
            else
            {
                timing_prescaler = (sint32)prescaler_offset * (sint32)delay_sched_cpy;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy] - (sint32)input_sig_value;
                delta_val = ((delta_val / timing_prescaler) * (sint32)time_delay) + \
                            (((delta_val % timing_prescaler) * (sint32)time_delay) / timing_prescaler);
                output_signal = (sint8)((sint32)input_sig_value + delta_val);
            }
        }
        else if (((uint32)nb_sched_time_delay == (uint32)prescaler_offset) && \
                 ((uint32)0 == (uint32)offset_sched_time_delay))
        {
                /* It is the last memorised value */
                output_signal = buffer_ptr_cpy[(t_dds_m_sint)buffer_last_pos_cpy];
        }
        else
        {
            /* Calculate offset in scheduling from last memorised value */
            nb_sched_from_last_data_cpy = (uint16)((sint32)nb_sched_time_delay - (sint32)prescaler_offset);
            /* Calculate offset in table scale */
            nb_snapshot_from_last_copy = (uint16)((sint32)nb_sched_from_last_data_cpy / (sint32)prescaler_cpy);

            /* Check if in the table */
            if ((uint32)buffer_last_pos_cpy >= (uint32)nb_snapshot_from_last_copy)
            {
                pos_younger_value = (t_dds_m_sint)buffer_last_pos_cpy - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            else
            {
                pos_younger_value = ((t_dds_m_sint)buffer_size_cpy + (t_dds_m_sint)buffer_last_pos_cpy)  - (t_dds_m_sint)nb_snapshot_from_last_copy;
            }
            /* Check if interpolation is required */
            if((uint32)0 == (uint32)offset_sched_time_delay)
            {
                offset_from_younger = (uint16)((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy);
                if ((uint32)0 == (uint32)offset_from_younger)
                {
                    /* No interpolation */
                    output_signal = buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                }
                else
                {
                    /* Calculate older value position */
                    if ((sint32)0 == pos_younger_value)
                    {
                        pos_older_value = (t_dds_m_sint)buffer_size_cpy - 1;
                    }
                    else
                    {
                        pos_older_value = pos_younger_value - 1;
                    }
                    /* Interpolate */
                    delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                    delta_val = ((delta_val / (sint32)prescaler_cpy) * (sint32)offset_from_younger) + \
                                (((delta_val % (sint32)prescaler_cpy) * (sint32)offset_from_younger) / (sint32)prescaler_cpy);
                    output_signal = (sint8)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
                }
            }
            else
            {
                offset_from_younger = (uint16)(((sint32)nb_sched_from_last_data_cpy % (sint32)prescaler_cpy) + 1);
                /* Calculate older value position */
                if ((uint32)0 == (uint32)pos_younger_value)
                {
                    pos_older_value = (sint32)buffer_size_cpy - 1;
                }
                else
                {
                    pos_older_value = pos_younger_value - 1;
                }
                /* Interpolate */
                timing_prescaler = (sint32)prescaler_cpy * (sint32)delay_sched_cpy;
                timing_from_younger = ((sint32)(offset_from_younger) * (sint32)delay_sched_cpy) - (sint32)offset_sched_time_delay;

                delta_val = (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_older_value] - (sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value];
                delta_val = ((delta_val / timing_prescaler) * timing_from_younger) + \
                            (((delta_val % timing_prescaler) * timing_from_younger) / timing_prescaler);
                output_signal = (sint8)((sint32)buffer_ptr_cpy[(t_dds_m_sint)pos_younger_value] + delta_val);
            }
        }
    }
    return output_signal;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S8_DELAY_V2_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   'sig_delay_struct_ptr' is the structure associated to macro
*   'data_buffer_ptr' is the pointer on the buffer where to save signal
*   'data_buffer_size' is the size of the saving buffer
*   'prescaler_value' is frequency of saving input signal in scheduling resolution
*   'delay_sched' is the scheduling of the call of DDS_M_SIGNAL_S8_DELAY_V2 (avoid to memorise exact timing)
*
*  REMARKS:
*   There is no value in the buffer once init done.
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SIGNAL_S8_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_s8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 prescaler_value,
                                                    uint16 delay_sched,
                                                    sint8 default_value)
{
    sig_delay_struct_ptr->buffer_ptr = data_buffer_ptr;
    sig_delay_struct_ptr->buffer_size = data_buffer_size;
    sig_delay_struct_ptr->buffer_last_pos = (uint16)((t_dds_m_uint)data_buffer_size - (t_dds_m_uint)1);
    sig_delay_struct_ptr->buffer_nb_data = 0;

    if ((t_dds_m_uint)prescaler_value == (t_dds_m_uint)0)
    {
        sig_delay_struct_ptr->prescaler = 1;
        sig_delay_struct_ptr->current_prescale = 1;
    }
    else
    {
        sig_delay_struct_ptr->prescaler = prescaler_value;
        sig_delay_struct_ptr->current_prescale = prescaler_value;
    }
    sig_delay_struct_ptr->delay_sched = delay_sched;
    sig_delay_struct_ptr->default_val = default_value;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_BOOLEAN_DELAY
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
*     Else
*       the value is interpolated
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :            *<-----------+------ "output_signal"
*             *                    :       .    :            |       (interpolated)
*             |                    :  .         :            |
*             |                    *            :            |
*             |                    |            :            |
*             |                    |            :            |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]           :          [n+1]
*                                               :
*             +--------- "time_delay" --------->:
*
*  Where:
*   sig_delay_struct_ptr is the structure associated to macro
*   input_sig_value is the input signal value
*   time_delay is the time delay of the signal
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_SIGNAL_BOOLEAN_DELAY(CONSTP2VAR(t_dds_m_sig_boolean_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                uint8 input_sig_value,
                                                uint16 time_delay)
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) buffer_ptr_cpy;
    uint16 buffer_size_cpy;
    uint16 delay_sched_cpy;
    uint32 buffer_last_pos_cpy;
    uint32 buffer_nb_data_cpy;

    uint32 temp_calc;
    uint32 delta_pos;
    uint8 output_signal;
    uint16 index_to_rw_buffer;
    uint8 index_to_rw_bit;
    uint16 time_delay_loc;

    buffer_ptr_cpy = sig_delay_struct_ptr->buffer_ptr;
    buffer_size_cpy = sig_delay_struct_ptr->buffer_size;
    delay_sched_cpy = sig_delay_struct_ptr->delay_sched;
    buffer_last_pos_cpy = sig_delay_struct_ptr->buffer_last_pos;
    buffer_nb_data_cpy = sig_delay_struct_ptr->buffer_nb_data;

    /*================ check time delay =================================*/
    if((t_dds_m_uint)time_delay>(t_dds_m_uint)sig_delay_struct_ptr->time_delay_max)
    {
        time_delay_loc = sig_delay_struct_ptr->time_delay_max;
    }
    else
    {
        time_delay_loc = time_delay;
    }


    /*================ read data to return ==============================*/
    if((t_dds_m_uint)time_delay_loc > 0)
    {
        /* calculate delta position */
        /* use of time_delay_loc-1, because the first most recent value is the one store step earlier.
        That's because we store the most recent value at the end of the function. */
/* <PRQA_COMMENT><2834><4491> "delay_sched_cpy" can never be equal to 0.</4491></2834></PRQA_COMMENT> */
        delta_pos = ((t_dds_m_uint)time_delay_loc - 1) / ((t_dds_m_uint)delay_sched_cpy);

        /* check delta position with nb of data store */
        if((t_dds_m_uint)delta_pos<=(t_dds_m_uint)buffer_nb_data_cpy)
        {
            /* nothing to do, detla position is available */
        }
        else
        {
            /* delta position is not available */
            delta_pos = buffer_nb_data_cpy;
        }
        /* calculate index of table and bit position to read the value */
        if((t_dds_m_uint)delta_pos<=(t_dds_m_uint)buffer_last_pos_cpy)
        {
            index_to_rw_buffer = (uint16)((buffer_last_pos_cpy - delta_pos) / 8);
            index_to_rw_bit = (uint8)((buffer_last_pos_cpy - delta_pos) - (8* (t_dds_m_uint)index_to_rw_buffer));
        }
        else
        {
            temp_calc = ((8*(t_dds_m_uint)buffer_size_cpy)+(t_dds_m_uint)buffer_last_pos_cpy) - delta_pos;
            index_to_rw_buffer = (uint16)((temp_calc) / 8);
            index_to_rw_bit = (uint8)(temp_calc - (8 * (t_dds_m_uint)index_to_rw_buffer));
        }
        /* read the value */
      /* <PRQA_COMMENT><2100> bug QAC. </2100></PRQA_COMMENT> */
      output_signal = (uint8)DDS_M_BIT_GET8((t_dds_m_uint)buffer_ptr_cpy[(t_dds_m_uint)index_to_rw_buffer],(t_dds_m_uint)index_to_rw_bit);
    }
    else
    {
        output_signal = input_sig_value;
    }


    /*================ memorising data to delay =========================*/
    /* increase current position */
/* <PRQA_COMMENT><4491> Do not touch the current implementation to avoid regression. </4491></PRQA_COMMENT> */
    temp_calc = (8*(t_dds_m_uint)buffer_size_cpy)-1;
    if((t_dds_m_uint)buffer_last_pos_cpy<(t_dds_m_uint)temp_calc)
    {
        buffer_last_pos_cpy = buffer_last_pos_cpy + 1;
    }
    else
    {
        buffer_last_pos_cpy = 0;
    }
    /* calculate index to write buffer and bit position */
    index_to_rw_buffer = (uint16)(buffer_last_pos_cpy / 8);
    index_to_rw_bit = (uint8)((t_dds_m_uint)buffer_last_pos_cpy - (8* (t_dds_m_uint)index_to_rw_buffer));

/* <PRQA_COMMENT><4491> Do not touch the current implementation to avoid regression. </4491></PRQA_COMMENT> */
    temp_calc = (8*(t_dds_m_uint)buffer_size_cpy)-1 ;
    /* updating nb of data store */
    if((t_dds_m_uint)buffer_nb_data_cpy<((t_dds_m_uint)temp_calc))
    {
        /* the table is not yet full */
        buffer_nb_data_cpy = buffer_nb_data_cpy + 1;
    }
    else
    {
        /* the table is already full */
    }

    /* write value */
    if((t_dds_m_uint)input_sig_value != (t_dds_m_uint)DDS_FALSE)
    {
        DDS_M_BIT_SET8(buffer_ptr_cpy[(t_dds_m_uint)index_to_rw_buffer],(t_dds_m_uint)index_to_rw_bit);
    }
    else
    {
        DDS_M_BIT_CLR8(buffer_ptr_cpy[(t_dds_m_uint)index_to_rw_buffer],(t_dds_m_uint)index_to_rw_bit);
    }

    /*================ update structure values =======================*/
    sig_delay_struct_ptr->buffer_last_pos = buffer_last_pos_cpy;
    sig_delay_struct_ptr->buffer_nb_data = buffer_nb_data_cpy;
    /*================ set output ====================================*/
    return output_signal;
}

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_BOOLEAN_DELAY_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   sig_delay_struct_ptr is the structure associated to macro
*   time_delay is the time delay of the signal
*   data_buffer_ptr is the pointer on the buffer where to save signal
*   data_buffer_size is the size of the saving buffer
*
*  REMARKS:
*   There is no value in the buffer once init done.
*   delay_sched is the scheduling.
*   Time delay and scheduling must have the same resolution.
*
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_SIGNAL_BOOLEAN_DELAY_INIT(CONSTP2VAR(t_dds_m_sig_boolean_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 delay_sched,
                                                    uint16 time_delay_max)
{
    sig_delay_struct_ptr->buffer_ptr = data_buffer_ptr;
    sig_delay_struct_ptr->buffer_size = data_buffer_size;
    sig_delay_struct_ptr->buffer_last_pos = 0;
    sig_delay_struct_ptr->buffer_nb_data = 0;
    sig_delay_struct_ptr->delay_sched = delay_sched;
    if((uint32)time_delay_max < ((uint32)data_buffer_size*8))
    {
        sig_delay_struct_ptr->time_delay_max = time_delay_max;
    }
    else
    {
        sig_delay_struct_ptr->time_delay_max = (uint16)((uint32)data_buffer_size * 8);
    }
}
/*******************************************************************************
*  Function name:  DDS_M_VARIABLE_TRANSPORT_DELAY_FAP
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every time a buffer
*  2 It returns the signal value that has occured "time_delay" before.
*
*
*             :                    :<-- (prescaler_value  -->:
*             :                    :     * scheduling)       :
*             :                    :                         *
*             :                    :                     .   |
*             :                    :                .        |
*             :                    :                         |
*             *                    :       .                 |
*             |                    :  .                      |
*             |                    *                         |
*             |                    |                         |
*             |                    |                         |
*             +-----...     ...----+-------------------------+----
*      [buffer_last_pos]          [n]                      [n+1]
*
*             +--------- "time_delay" ---------------------->:
*
*  Where:
*   t_dds_m_var_trans_delay_fap is the structure associated to macro
*   input is the input signal value
*   delta_time is the delta time between call
*   v_propagation is the signal speed
*   pflt_var_trig is the trigger of search fonction
*   pflt_var_dtsub is the delta time to search for
*   pflt_var_state is the state in search block
*   pflt_var_idx is the index in the buffer
*
*  Be Careful: limitation have been introduced in macro code in order to make possible calculation on range
*              Range and limitation are precised in specification 01460_10_01523_LIB_FAP_v1.0 (and in associated tracking
*              sheet 01460_10_01523_LIB_FAP_Remark_Tracking_Sheet.xls, CSMT_CGMT06_1453_Remark_Tracking_Sheet.xls)
*
*              Variable shall respect the range and definition:
*                input: [-10000; 10000] BIN7
*                delta_time: [0.01; 100] DEC3
*                v_propagation: [0; 100] BIN7
*                vdt: [0; 5000] DEC3BIN7
*                u_table_old: [-10000; 10000] BIN7
*                Ivdt_table_old: [0; 100] DEC3BIN7
*                out_val: [-10000; 10000] BIN7
*                dT_min: [0.02; 100] DEC3
*                dT_max: [0.02; 100] DEC3
*
*  Historic: In a first version, input and out_val was defined in BIN17. Taking account calculation complexity,
*            resolution of those parameters have been reduced to BIN7. Embedded in FAP Euro6, currently in development
*            (no retro-compatibility problem)
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_VARIABLE_TRANSPORT_DELAY_FAP(
                        CONSTP2VAR(t_dds_m_var_trans_delay_fap, AUTOMATIC, AUTOMATIC) str,
                        sint32 input, /* BIN7 */
                        uint32 delta_time, /* DEC3 */
                        uint32 v_propagation, /* BIN7 */
                        CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) pflt_var_trig, /* BIN0 */
                        CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) pflt_var_dtsub, /* DEC3 */
                        CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) pflt_var_state, /* BIN0 */
                        CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) pflt_var_idx /* BIN0 */)
{
    uint32 uvalue;
    sint32 svalue;
    sint32 output_val;
    uint32 vdt;
    uint32 epsdiv;
    sint32 idx_loc;
    uint32 delta_sub;
    uint8 test_result;
    uint8 prev_trig_search;
    sint32 num_tmp1, num_tmp2, num_tmp, denum_tmp, div_tmp;
    sint8 bp_shift;

    epsdiv = (uint32)((0.0001) * BIN7 * DEC3);


/* FcnCallGenerator */
    /* Calcul de la période d'échantillonnage pour la sous fonction */

    /* [0.01; 100] DEC3 */
    delta_sub = delta_time + str->dly_sum_dt; /* DEC3 */
    delta_sub = (uint32)DDS_M_MIN((sint32)delta_sub, (sint32)(100 * DEC3)); /* DEC3 */

    /* Détermination des conditions d'appel de la sous fonction */
    uvalue = delta_time * v_propagation; /* DEC3 * BIN7 */

    uvalue = uvalue + str->te_v_dly; /* DEC3 * BIN7 */

    if((uint32)(0.01 * BIN7 * DEC3) < uvalue)
    {
        str->te_v_dly = 0;
        test_result = DDS_TRUE;
    }
    else
    {
        str->te_v_dly = uvalue;
        test_result = DDS_FALSE;
    }

    /* TrigSearch calculation */
    prev_trig_search = str->TrigSearch;

    if(  (  (delta_sub > str->dT_min)
          &&((uint32)test_result == (uint32)DDS_TRUE))
       ||(delta_sub >= str->dT_max))
    {
        /* bfcncall_mp = DDS_TRUE; */
        str->dly_sum_dt = 0;
        if((uint32)str->TrigSearch == (uint32)DDS_TRUE)
        {
            str->TrigSearch = DDS_FALSE;
        }
        else
        {
            str->TrigSearch = DDS_TRUE;
        }
    }
    else
    {
        /* bfcncall_mp = DDS_FALSE; */
        str->dly_sum_dt = delta_sub;
    }


    if(((((uint32)DDS_FALSE == (uint32)prev_trig_search) &&
       ((uint32)DDS_TRUE == (uint32)str->TrigSearch)))   ||
       ((((uint32)DDS_TRUE == (uint32)prev_trig_search) &&
       ((uint32)DDS_FALSE == (uint32)str->TrigSearch))))
    {
        test_result = DDS_TRUE;
    }
    else
    {
        test_result = DDS_FALSE;
    }

/* Search */
    idx_loc = (sint32)str->idx;

    if(  ((uint32)test_result == (uint32)DDS_TRUE)
       &&((uint32)str->init == (uint32)DDS_TRUE))
    {
        /* State machine */
        if((uint32)str->State == 0)
        {
            /* Initialisation */
            for(uvalue=0;uvalue<DDS_M_VAR_TRANS_DELAY_FAP;uvalue++)
            {
                str->u_table_old[uvalue] = input;
                str->Ivdt_table_old[uvalue] = 0;
            }

            /* Fin de l'initialisation */
            idx_loc = 0; /* 1 -1 */
            str->State = 1;
            output_val = 0;
        }
        else
        {
            output_val = str->u_table_old[(uint32)idx_loc];
            if(v_propagation == 0)
            {
                /* Si la vitesse v du flux est nulle, on sort du stateflow */
                str->State = 2;
            }
            else
            {
                /* Si la vitesse v du flux et le temps d'echantilonnage de la fonction sont non nulles,
                vdt reçoit la longueur de propagation du flux à l'instant t*/
                /* [0.01; 100] DEC3 * [0; 100] BIN7 */
                /* limited to [0; 5000] */
                vdt = delta_sub * v_propagation;  /* DEC3 * BIN7 */
                vdt = DDS_M_MIN( vdt, (5000 * BIN7 * DEC3));

                /* Si la longueur de propagation contenu dans la table Ivdt_table_old pour l'indice i actuel est > 1,
                on peut déterminer la valeur de tempéraure à la sortie du tube (branche gauche)*/
                if(str->Ivdt_table_old[idx_loc] <= (1 * BIN7 * DEC3))
                {
                    /* Sinon on doit tester si les tables sont pleines avant de les mettre à jour .
                    Comparaison de l'indice i actuel avec le nombre d'element des tables n_mask.
                    Un flag indiquant la saturation des tables est mis à jour */
                    if(idx_loc == (DDS_M_VAR_TRANS_DELAY_FAP-1))
                    {
                        str->State = 3;
                    }
                    else
                    {
                        str->State = 4;
                    }

                    /* MAJ de la sortie */
                    output_val = str->u_table_old[(uint32)idx_loc];
                }
                else
                {
                    /* si le premier élément de la table de longueur de propagation contient une valeur >= à la longueur du tube
                    on peut calculer la T° à la sortie ( brandhe gauche) sinon on doit faire une recherche dans la table*/
                    if(str->Ivdt_table_old[0] < (1 * BIN7 * DEC3))
                    {
                        /* Cette boucle permet de trouver l'élément de la table Ivdt_table_old qui contient la valeur de longueur de
                        propagation du fluxb juste inférieure à la longueur du tube. */
                        while(  (idx_loc > 0) &&
                                (str->Ivdt_table_old[(uint32)idx_loc] > (1 * BIN7 * DEC3)))
                        {
                             idx_loc = idx_loc - 1;
                        }

                        /* MAJ de l'indice i et test pour securiser la division par Ivdt_table_old[1] */
                        idx_loc = DDS_M_LIMITED_INCREMENT(idx_loc, 1, DDS_M_VAR_TRANS_DELAY_FAP - 1);

                        /* [0; 100] - [0; 100] BIN7DEC3 */
                        uvalue = (uint32)DDS_M_ABS((sint32)(str->Ivdt_table_old[(uint32)idx_loc] - str->Ivdt_table_old[(uint32)(idx_loc - 1)]));

                        if(uvalue < epsdiv)
                        {
                            /* cond = 1; */
                            output_val = str->u_table_old[(uint32)idx_loc];
                            str->State = 6;
                        }
                        else
                        {
                            /* cond = 0; */
                            /* Determination de la T° sortie tube par interpolation */
                            /* [-20000; 20000] BIN7 = [-10000; 10000] BIN7 - [-10000; 10000] BIN7 */
                            num_tmp1 = (str->u_table_old[(uint32)idx_loc] - str->u_table_old[(uint32)(idx_loc -1)]);

                            /* [-100; 100] DEC3BIN7 = [1] DEC3BIN7 - [0; 100]BIN7DEC3 */
                            num_tmp2 = (BIN7 * DEC3) - (sint32)str->Ivdt_table_old[(uint32)(idx_loc - 1)];

                            /* [0; 100]BIN7DEC3 - [0; 100]BIN7DEC3 */
                            denum_tmp = (sint32)str->Ivdt_table_old[(uint32)idx_loc] - (sint32)str->Ivdt_table_old[(uint32)(idx_loc - 1)] ;

                            bp_shift = 7 + 7;
                            num_tmp = DDS_M_DYNAMIC_MULT_S32(num_tmp1, num_tmp2,&bp_shift);

                            div_tmp = DDS_M_DYNAMIC_DIV_S32(num_tmp, denum_tmp,bp_shift,7,7);

                            svalue = str->u_table_old[idx_loc -1] + div_tmp;
                            svalue = DDS_M_LIMIT(svalue, (-10000 * BIN7), (10000 * BIN7));
                            output_val = svalue;
                            str->State = 5;
                        }
                    }
                    else
                    {
                        /* MAJ de l'indice i et test pour securiser la division par Ivdt_table_old [1] */
                        idx_loc = 0;

                        uvalue = str->Ivdt_table_old[0];

                        if(uvalue < epsdiv)
                        {
                            /* cond = 1; */
                            /* MAJ de la sortie. La T° en sortie dutube est égale à la T° à son entrée */
                            output_val = input;
                            str->State = 8;
                        }
                        else
                        {
                            /* cond = 0; */
                            /* [-10000;10000] BIN7 */
                            /* Determination de la T° sortie tube par interpolation */
                            /* [-20000; 20000] BIN7DEC3 */
                            num_tmp = (str->u_table_old[0] - input) * DEC3;

                            div_tmp = DDS_M_DYNAMIC_DIV_S32(num_tmp, (sint32)str->Ivdt_table_old[0] ,7,7,7);

                            svalue = input + div_tmp;
                            svalue = DDS_M_LIMIT(svalue, (-10000 * BIN7), (10000 * BIN7));

                            output_val = svalue;
                            str->State = 7;
                        }
                    }
                }

                /* Mise à jour de l'élément i de la table d'historique des températues avec la valeur de température de sortie calculée */
                str->u_table_old[(uint32)idx_loc] = output_val;

                /* Cette boucle permet de décaler toutes les valeurs des tables d'un élément et d'ajouter à la table d 'historique des
                longueurs de propagation du flux la valeur de propagation à l'instant de l'appel au stateflow. Le premier element de la
                table u_table_old prend la valeur de la T° entrée tube à l'instant t */

                for(uvalue=(DDS_M_VAR_TRANS_DELAY_FAP-1);uvalue>0;uvalue--)
                {
                    str->u_table_old[uvalue] = str->u_table_old[uvalue - 1];
                    /* [0; 100] BIN7DEC3 */
                    str->Ivdt_table_old[uvalue] = str->Ivdt_table_old[uvalue - 1] + vdt;
                    str->Ivdt_table_old[uvalue] = DDS_M_MIN( str->Ivdt_table_old[uvalue], (100 * BIN7 * DEC3));
                }

                str->u_table_old[0] = input;
                str->Ivdt_table_old[0] = DDS_M_MIN( vdt, (100 * BIN7 * DEC3));

                /* Incrementation de la valeur de l'indice i qui prend au pire la valeur de la taille des tables */
                idx_loc = DDS_M_MIN(idx_loc + 1,DDS_M_VAR_TRANS_DELAY_FAP-1);
            }
        }
    }
    else
    {
        output_val = str->output_prev;
/* <PRQA_COMMENT><2000> Do not touch the current implementation to avoid regression. </2000></PRQA_COMMENT> */
        if((uint32)str->init != (uint32)DDS_TRUE)
        {
            str->init = DDS_TRUE;
            idx_loc = -1;
        }
    }

    *pflt_var_idx = (uint8)(idx_loc + 1);
    str->idx = (uint8)DDS_M_MAX(idx_loc,0);
    *pflt_var_state = str->State;
    *pflt_var_dtsub = delta_sub;
    *pflt_var_trig = str->TrigSearch;
    str->output_prev  = output_val;

    return output_val;
}

/*******************************************************************************
*  Function name:  DDS_M_VARIABLE_TRANSPORT_DELAY_FAP_INIT
*
*  Description :
*  The following function is used to reset and configure the signal delay
*  function.
*
*
*  Where:
*   t_dds_m_var_trans_delay_fap is the structure associated to macro
*   dT_min is the minimal scheduling
*   dT_max is the maximal cheduling
*
*  REMARKS:
*   Time delay and scheduling must have the same resolution.
*
*
*******************************************************************************/
FUNC(void, AUTOMATIC) DDS_M_VARIABLE_TRANSPORT_DELAY_FAP_INIT(
                        CONSTP2VAR(t_dds_m_var_trans_delay_fap, AUTOMATIC, AUTOMATIC) str,
                        uint32 dT_min, /* DEC3 */
                        uint32 dT_max /* DEC3 */)
{
    str->dT_min = dT_min;
    str->dT_max = dT_max;
    str->idx = 0;
    str->State = 0;
    str->output_prev = 0;
    str->TrigSearch = 0;
    str->te_v_dly = 0;
    str->dly_sum_dt = 0;
    str->init = 0;
}

/*******************************************************************************
*  Function name:  DDS_M_PROD_MATRIX_UINT16
*
*  Description :
*  The following function is used to calculate the matrix multiplication C = A * B.
*  The function return a boolean flag to inform if the calculation running without overflow.
*
*
*  Where:
*   inputs:
*   matrix_in1 : matrix A
*   nb_row_matrix_in1 : row number of matrix A
*   nb_col_matrix_in1 : column number of matrix A
*   matrix_in2 : matrix B
*   nb_col_matrix_in2: column number of matrix B (row number is the same as column number of matrix A)
*   matrix_out : matrix C
*   bin_scalaire = (BIN_matrix_A * BIN_matrix_B) / BIN_matrix_C
*
*   outputs:
*   flag == TRUE if there is one or more overflow result in matrix C (calcul not ok), FALSE in other case (calcul ok).
*
*  REMARKS:
*   0 < bin_scalaire must be < BIN32. Dimensions of matrix C must be :
*   nb_row = nb_row_matrix_in1
*   nb_col = nb_col_matrix_in2
*
*******************************************************************************/
/* <PRQA_COMMENT><3673> In order to have flexibility, it has been decided to use pointer on variable
and not constant. In addition for compatibility reason this implementation is kept. </3673></PRQA_COMMENT> */
FUNC(uint8, AUTOMATIC) DDS_M_PROD_MATRIX_UINT16(P2VAR(uint16, AUTOMATIC, AUTOMATIC) matrix_in1,
                                              uint8 nb_row_matrix_in1,
                                              uint8 nb_col_matrix_in1,
/* <PRQA_COMMENT><3673> In order to have flexibility, it has been decided to use pointer on variable
and not constant. In addition for compatibility reason this implementation is kept. </3673></PRQA_COMMENT> */
                                              P2VAR(uint16, AUTOMATIC, AUTOMATIC) matrix_in2,
                                              uint8 nb_col_matrix_in2,
                                              P2VAR(uint32, AUTOMATIC, AUTOMATIC) matrix_out,
                                              uint32 bin_scalaire)
{
    uint32 sum_result;
    uint32 prod_tmp;

    t_dds_m_uint index_i;
    t_dds_m_uint index_j;
    t_dds_m_uint index_k;
    uint16 BIN_Sum;

    uint8 overflow_flag; /* Boolean */

    overflow_flag = DDS_FALSE;

    for(index_i = 0; index_i < (t_dds_m_uint)nb_row_matrix_in1; index_i++)
    {
        for(index_j = 0; index_j < (t_dds_m_uint)nb_col_matrix_in2; index_j++)
        {

            sum_result = 0;
            BIN_Sum = 1;
            for(index_k = 0; index_k < (t_dds_m_uint)nb_col_matrix_in1; index_k++)
            {
                if( ((t_dds_m_uint)BIN_Sum != (t_dds_m_uint)1) &&
                    (sum_result <= (DDS_UINT32_MAX/2)) )
                {
                    /* BIN(X) = BIN(X-1) * BIN1 */
                    sum_result *= BIN1;
                    BIN_Sum = (uint16)((t_dds_m_uint)BIN_Sum / (t_dds_m_uint)2);
                }
                else
                {
                    /* sum_result still too big to restore it */
                }
                prod_tmp = (uint32)matrix_in1[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in1) + index_k)]
                        * (uint32)matrix_in2[(t_dds_m_sint)((index_k * (t_dds_m_uint)nb_col_matrix_in2) + index_j)];


                if( sum_result < (DDS_UINT32_MAX - prod_tmp) )
                {
                    /* BINX = BINY / BIN(Y-X) */
/* <PRQA_COMMENT><2834> "BIN_Sum" can never be equal to 0.</2834></PRQA_COMMENT> */
                    sum_result += prod_tmp/(uint32)BIN_Sum;
                }
                else
                {
                    /* BIN(X-1) = BINX / BIN1 */
/* <PRQA_COMMENT><2834> "BIN_Sum" can never be equal to 0.</2834></PRQA_COMMENT> */
                    sum_result = (sum_result/(uint32)BIN1) + (prod_tmp/((uint32)BIN1 * (uint32)BIN_Sum));
                    BIN_Sum  = (uint16)((t_dds_m_uint)BIN_Sum * (t_dds_m_uint)2);
                }
            }
            if((uint32)BIN_Sum <= bin_scalaire)
            {
                matrix_out[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in2) + index_j)] =
/* <PRQA_COMMENT><2834> "BIN_Sum" can never be equal to 0.</2834></PRQA_COMMENT> */
                    sum_result/(bin_scalaire / (uint32)BIN_Sum);

            }
            else
            {
                /* There is an overflow_flag during calculation flag -> TRUE */
                overflow_flag = DDS_TRUE;
                matrix_out[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in2) + index_j)] = DDS_UINT32_MAX;
            }
        }
    }
    return(overflow_flag);
}


/*******************************************************************************
*  Function name:  DDS_M_PROD_MATRIX_SINT16
*
*  Description :
*  The following function is used to calculate the matrix multiplication C = A * B.
*  The function return a boolean flag to inform if the calculation running without overflow.
*
*
*  Where:
*   inputs:
*   matrix_in1 : matrix A
*   nb_row_matrix_in1 : row number of matrix A
*   nb_col_matrix_in1 : column number of matrix A
*   matrix_in2 : matrix B
*   nb_col_matrix_in2: column number of matrix B (row number is the same as column number of matrix A)
*   matrix_out : matrix C
*   bin_scalaire = (BIN_matrix_A * BIN_matrix_B) / BIN_matrix_C
*
*   outputs:
*   flag == TRUE if there is one or more overflow result in matrix C (calcul not ok), FALSE in other case (calcul ok).
*
*  REMARKS:
*   0 < bin_scalaire < BIN31. Dimensions of matrix C must be :
*   nb_row = nb_row_matrix_in1
*   nb_col = nb_col_matrix_in2
*
*******************************************************************************/
/* <PRQA_COMMENT><3673> In order to have flexibility, it has been decided to use pointer on variable
and not constant. In addition for compatibility reason this implementation is kept. </3673></PRQA_COMMENT> */
FUNC(uint8, AUTOMATIC) DDS_M_PROD_MATRIX_SINT16(P2VAR(sint16, AUTOMATIC, AUTOMATIC) matrix_in1,
                                              uint8 nb_row_matrix_in1,
                                              uint8 nb_col_matrix_in1,
/* <PRQA_COMMENT><3673> In order to have flexibility, it has been decided to use pointer on variable
and not constant. In addition for compatibility reason this implementation is kept. </3673></PRQA_COMMENT> */
                                              P2VAR(sint16, AUTOMATIC, AUTOMATIC) matrix_in2,
                                              uint8 nb_col_matrix_in2,
                                              P2VAR(sint32, AUTOMATIC, AUTOMATIC) matrix_out,
                                              uint32 bin_scalaire)
{
    sint32 sum_result;
    sint32 prod_tmp;
    sint32 sum_reduced;

    t_dds_m_uint index_i;
    t_dds_m_uint index_j;
    t_dds_m_uint index_k;
    uint8 overflow_flag; /* Boolean */
    uint16 BIN_Sum;

    overflow_flag = DDS_FALSE;

    for(index_i = 0; index_i < (t_dds_m_uint)nb_row_matrix_in1; index_i++)
    {
        for(index_j = 0; index_j < (t_dds_m_uint)nb_col_matrix_in2; index_j++)
        {
            sum_result = 0;
            BIN_Sum = 1;
            for(index_k = 0; index_k < (t_dds_m_uint)nb_col_matrix_in1; index_k++)
            {
                if( ((t_dds_m_uint)BIN_Sum != (t_dds_m_uint)1) &&
                    (sum_result <= (DDS_SINT32_MAX/2))
                    && (sum_result >= (DDS_SINT32_MIN/2)))
                {
                    /* BIN(X) = BIN(X-1) * BIN1 */
                    sum_result *= BIN1;
                    BIN_Sum = (uint16)((t_dds_m_uint)BIN_Sum / (t_dds_m_uint)2);
                }
                else
                {
                    /* sum_result still too big to restore it */
                }
                prod_tmp = (sint32)matrix_in1[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in1) + index_k)]
                        * (sint32)matrix_in2[(t_dds_m_sint)((index_k * (t_dds_m_uint)nb_col_matrix_in2) + index_j)];
/* <PRQA_COMMENT><2834> "BIN_Sum" can never be equal to 0.</2834></PRQA_COMMENT> */
                sum_reduced = (sum_result/BIN1) + (prod_tmp/(BIN1 * (sint32)BIN_Sum));


                if( ( sum_reduced <= ((DDS_SINT32_MAX/2) - 1) )
                    && (sum_reduced >= ((DDS_SINT32_MIN/2) + 1)) )
                {
                    /* BINX = BINY / BIN(Y-X) */
                    sum_result += prod_tmp/(sint32)BIN_Sum;
                }
                else
                {
                    /* BIN(X-1) = BINX / BIN1 */
                    sum_result = sum_reduced;
                    BIN_Sum  = (uint16)((t_dds_m_uint)BIN_Sum * (t_dds_m_uint)2);
                }
            }
            if((uint32)BIN_Sum <= bin_scalaire)
            {
                matrix_out[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in2) + index_j)] =
                    sum_result/(sint32)(bin_scalaire / (uint32)BIN_Sum);

            }
            else if(sum_result < 0)
            {
                /* There is an overflow_flag during calculation flag -> TRUE */
                overflow_flag = DDS_TRUE;
                matrix_out[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in2) + index_j)] = DDS_SINT32_MIN;
            }
            else
            {
                /* There is an overflow_flag during calculation flag -> TRUE */
                overflow_flag = DDS_TRUE;
                matrix_out[(t_dds_m_sint)((index_i * (t_dds_m_uint)nb_col_matrix_in2) + index_j)] = DDS_SINT32_MAX;
            }

        }
    }
    return(overflow_flag);
}


/*******************************************************************************
*  Function name:  DDS_M_HYST_U32
*
*  Description :
*  The following macro is used to test the position of a variable
*  within a hysteresis loop for a unsigned variable
*
*  If the variable is above the upper limit then
*   The result  = DDS_TRUE
*  Else if the variable is below the upper limit - the hyst band then
*   The result  = DDS_FALSE
*  Else
*   The result is left unchanged
*
*  Where:
*   input is the value to test
*   hyst_high_thr is the upper limit of hyst
*   hyst_band is the band of hyst
*   hyst_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   input, hyst_high_thr and hyst_band must all be  of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_U32 ( CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                        uint32 input,
                                        uint32 hyst_high_thr,
                                        uint32 hyst_band )
{
    if (input >= hyst_high_thr)
    {
        hyst_struct_ptr->previous_output = DDS_TRUE;
    }
    else if (input <= (hyst_high_thr - hyst_band))
    {
        hyst_struct_ptr->previous_output = DDS_FALSE;
    }
    else
    {
        /* No change */
    }
    return (hyst_struct_ptr->previous_output);
}

/*******************************************************************************
*  Function name:  DDS_M_HYST_PH_S32
*
*  Description :
*  The following macro is used to test the position of a variable
*  within a hysteresis loop for a unsigned variable. The priority is done on
*  the upper limit
*
*  If the variable is above the upper limit then
*   The result  = DDS_TRUE
*  Else if the variable is below the lower limit then
*   The result  = DDS_FALSE
*  Else
*   The result is left unchanged
*
*  Where:
*   input is the value to test
*   hyst_high_thr is the upper limit of hyst
*   hyst_low_thr is the lower limit of hyst
*   hyst_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   input, hyst_high_thr and hyst_low_thr must all be  of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_PH_S32 ( CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            sint32 input,
                                            sint32 hyst_high_thr,
                                            sint32 hyst_low_thr )
{
    if (input >= hyst_high_thr)
    {
        hyst_struct_ptr->previous_output = DDS_TRUE;
    }
    else if (input <= hyst_low_thr)
    {
        hyst_struct_ptr->previous_output = DDS_FALSE;
    }
    else
    {
        /* No change */
    }
    return (hyst_struct_ptr->previous_output);
}

/*******************************************************************************
*  Function name:  DDS_M_HYST_PH_U32
*
*  Description :
*  The following macro is used to test the position of a variable
*  within a hysteresis loop for a unsigned variable. The priority is done on
*  the upper limit
*
*  If the variable is above the upper limit then
*   The result  = DDS_TRUE
*  Else if the variable is below the lower limit then
*   The result  = DDS_FALSE
*  Else
*   The result is left unchanged
*
*  Where:
*   input is the value to test
*   hyst_high_thr is the upper limit of hyst
*   hyst_low_thr is the lower limit of hyst
*   hyst_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   input, hyst_high_thr and hyst_low_thr must all be  of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_PH_U32 ( CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint32 input,
                                            uint32 hyst_high_thr,
                                            uint32 hyst_low_thr )
{
    if (input >= hyst_high_thr)
    {
        hyst_struct_ptr->previous_output = DDS_TRUE;
    }
    else if (input <= hyst_low_thr)
    {
        hyst_struct_ptr->previous_output = DDS_FALSE;
    }
    else
    {
        /* No change */
    }
    return (hyst_struct_ptr->previous_output);
}

/*******************************************************************************
*  Function name:  DDS_M_HYST_LH_S32
*
*  Description :
*  The following macro is used to test the position of a variable
*  within a hysteresis loop for a unsigned variable. The priority is done on
*  the lower limit
*
*  If the variable is above the upper limit then
*   The result  = DDS_FALSE
*  Else if the variable is below the lower limit then
*   The result  = DDS_TRUE
*  Else
*   The result is left unchanged
*
*  Where:
*   input is the value to test
*   hyst_high_thr is the upper limit of hyst
*   hyst_low_thr is the lower limit of hyst
*   hyst_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   input, hyst_high_thr and hyst_low_thr must all be  of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_LH_S32 (  CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            sint32 input,
                                            sint32 hyst_high_thr,
                                            sint32 hyst_low_thr )
{
    if (input >= hyst_high_thr)
    {
        hyst_struct_ptr->previous_output = DDS_FALSE;
    }
    else if (input <= hyst_low_thr)
    {
        hyst_struct_ptr->previous_output = DDS_TRUE;
    }
    else
    {
        /* No change */
    }
    return (hyst_struct_ptr->previous_output);
}

/*******************************************************************************
*  Function name:  DDS_M_HYST_LH_U32
*
*  Description :
*  The following macro is used to test the position of a variable
*  within a hysteresis loop for a unsigned variable. The priority is done on
*  the lower limit
*
*  If the variable is above the upper limit then
*   The result  = DDS_FALSE
*  Else if the variable is below the lower limit then
*   The result  = DDS_TRUE
*  Else
*   The result is left unchanged
*
*  Where:
*   input is the value to test
*   hyst_high_thr is the upper limit of hyst
*   hyst_low_thr is the lower limit of hyst
*   hyst_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   input, hyst_high_thr and hyst_low_thr must all be  of the same type and BIN Point
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_LH_U32 (  CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint32 input,
                                            uint32 hyst_high_thr,
                                            uint32 hyst_low_thr )
{
    if (input >= hyst_high_thr)
    {
        hyst_struct_ptr->previous_output = DDS_FALSE;
    }
    else if (input <= hyst_low_thr)
    {
        hyst_struct_ptr->previous_output = DDS_TRUE;
    }
    else
    {
        /* No change */
    }
    return (hyst_struct_ptr->previous_output);
}

/*******************************************************************************
*  Macro name:  DDS_M_HYST_S32_INIT
*
*  Description :
*  The following macro manage init of DDS_M_HYST_S32 macro
*
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of hysteresis
*   hyst_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_S32_INIT (CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint8 init_value)
{
    hyst_struct_ptr->previous_output   = init_value;

    return(init_value);
}

/*******************************************************************************
*  Macro name:  DDS_M_HYST_U32_INIT
*
*  Description :
*  The following macro manage init of DDS_M_HYST_U32 macro
*
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of hysteresis
*   hyst_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_HYST_U32_INIT (CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint8 init_value)
{
    hyst_struct_ptr->previous_output   = init_value;

    return(init_value);
}



/******************************************************************************/
/*!!!!!!!!!!!!!--------Use those functions with precaution-------!!!!!!!!!!!!!*/
/******************************************************************************/
/*
*   We want to make
*       num_out = num_in1 * num_in2
*   or
*       num_out = num_in1 / num_in2
*   but num_out > 32 bits
*   solution use the "dynamique resolution":
*       - Step1 : reduce num1 and num2 in 16 bits number;
*       - Step2 : do the operation;
*       - Step3 : finally restore the result a the final resolution.
*
*   With this method, the relative error is constant.
*
*   Example:
*       # initials variables:
*   uint32 num_in1;             # BINX
*   uint32 num_in2;             # BINY
*   uint32 num_out;             # BINZ
*
*       # temporary variables:
*   uint16 num_in1_reduced; # BIN(X-U)
*   uint16 num_in2_reduced; # BIN(Y-V)
*   uint32 num_out_tmp;     # BIN(X-U + Y-V)
*
*   sint8 num_in1_nb_shift; # U
*   sint8 num_in2_nb_shift; # V
*   sint8 nb_shift_wished;      # X-U + Y-V -Z
*
*       # Step1
*   num_in1_reduced = DDS_M_REDUCE_UINT32_TO_UINT16(num_in1, &num_in1_nb_shift);
*   num_in2_reduced = DDS_M_REDUCE_UINT32_TO_UINT16(num_in2, &num_in2_nb_shift);
*
*       # Step2
*   # BIN(X-U + Y-V) =  BIN(X-U) * BIN(Y-V)
*   num_out_tmp = (uint32)num_in1_reduced * (uint32)num_in2_reduced;
*
*       # Step3
*   # BINZ = BIN(X-U + Y-V) / BIN(X-U + Y-V -Z)
*   nb_shift_wished = X + Y - (sint8)(num_in1_nb_shift + num_in2_nb_shift) - Z;
*   num_out = DDS_M_RESTORE_BINPOINT_UINT32(num_out_tmp, nb_shift_wished);
*
*
*   "SHORTEN" functions have the same behaviour as "REDUCE" except that the "nb_shift"
*   parameter has to be initialised. This is usefull for a series of "REDUCE" using
*   only one variable for "nb_shift".
*   "SHORTEN" functions have been created to have a downward comptibility between
*   "dds_lib" versions.
*
*******************************************************************************************/

/*******************************************************************************
*  Function Name   : DDS_M_SHORTEN_UINT32_TO_UINT16
*
*  Description     :  reduce the resolution of a 32bits variable num_to_reduce
*                     (BINX) in 16 bits number out in BIN(X-nb_shift)
*           - num_to_reduce: 32 bits variable
*           - nb_shift : number shift used to reduce resolution saving
*           - out: 16 bits variable with the same value of input but with a degraded resolution
*
*           out = num_to_reduce / 2^nb_shift
*           BINY = BINX / BIN(nb_shift)
*           0 < Y <= DDS_UINT16_MAX
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_SHORTEN_UINT32_TO_UINT16(uint32 num_to_reduce, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    return( (uint16)DDS_M_SHORTEN_UINT32_TO_UINT32(num_to_reduce, (uint32)DDS_UINT16_MAX, nb_shift));
}

/*******************************************************************************
*  Function Name   : DDS_M_SHORTEN_UINT32_TO_UINT32
*
*  Description     :  reduce the resolution of a 32bits variable num_to_reduce
*                     (BINX) in 32 bits number out in BIN(X-nb_shift)
*           - num_to_reduce: 32 bits variable
*           - nb_shift : number shift used to reduce resolution saving
*           - out: 32 bits variable with the same value of input but with a degraded resolution
*
*           out = num_to_reduce / 2^nb_shift
*           BINY = BINX / BIN(nb_shift)
*           0 < Y <= max_value
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SHORTEN_UINT32_TO_UINT32(uint32 num_to_reduce, uint32 max_value, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    uint32 last_bit = 0;
    uint32 reduced_num;
    reduced_num = num_to_reduce;

    while ((reduced_num+last_bit) > max_value)
    {
        last_bit = reduced_num & 1;
        reduced_num /= BIN1;
        *nb_shift= (sint8)((t_dds_m_sint)(*nb_shift)+1);
    }
    reduced_num += last_bit;

    return(reduced_num);
}

/*******************************************************************************
*  Function Name   : DDS_M_SHORTEN_SINT32_TO_SINT16
*
*  Description     : reduce the resolution of a 32bits variable num_to_reduce
*                    (BINX) in 16 bits number out in BIN(X-nb_shift). The number
*                    of shift used to reduced the resolution is store in nb_shift.
*           - num_to_reduce: 32 bits variable
*           - nb_shift : number shift used to reduce resolution saving
*           - out: 16 bits variable with the same value of input but with a degraded resolution
*
*           out = num_to_reduce / 2^nb_shift
*           BINY = BINX / BIN(nb_shift)
*           abs(Y) <= DDS_SINT16_MAX
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_SHORTEN_SINT32_TO_SINT16(sint32 num_to_shorten, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    uint32 num_to_shorten_tmp;

    num_to_shorten_tmp = DDS_M_SHORTEN_UINT32_TO_UINT32((uint32)DDS_M_ABS(num_to_shorten), (uint32)DDS_SINT16_MAX, nb_shift);

    if(0 <= num_to_shorten)
    {
        num_to_shorten = (sint32)num_to_shorten_tmp;
    }
    else
    {
        num_to_shorten = -(sint32)num_to_shorten_tmp;
    }

    return( (sint16)num_to_shorten);
}

/*******************************************************************************
*  Function Name   : DDS_M_REDUCE_UINT32_TO_UINT16
*
*  Description     :  reduce the resolution of a 32bits variable num_to_reduce
*                     (BINX) in 16 bits number out in BIN(X-nb_shift)
*           - num_to_reduce: 32 bits variable
*           - nb_shift : number shift used to reduce resolution saving
*           - out: 16 bits variable with the same value of input but with a degraded resolution
*
*           out = num_to_reduce / 2^nb_shift
*           BINY = BINX / BIN(nb_shift)
*           0 < Y <= DDS_UINT16_MAX
*
*  Warning:
*      nb_shift is initialised to 0 before shifting data
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_REDUCE_UINT32_TO_UINT16(uint32 num_to_reduce, CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    uint32 reduced_num;
    reduced_num = num_to_reduce;

    (*nb_shift) = 0;
    while (reduced_num > DDS_UINT16_MAX)
    {
        reduced_num /= BIN1;
        *nb_shift= (uint8)((t_dds_m_uint)(*nb_shift)+(t_dds_m_uint)1);
    }

    return( (uint16)reduced_num);
}

/*******************************************************************************
*  Function Name   : DDS_M_REDUCE_SINT32_TO_SINT16
*
*  Description     : reduce the resolution of a 32bits variable num_to_reduce
*                    (BINX) in 16 bits number out in BIN(X-nb_shift). The number
*                    of shift used to reduced the resolution is store in nb_shift.
*           - num_to_reduce: 32 bits variable
*           - nb_shift : number shift used to reduce resolution saving
*           - out: 16 bits variable with the same value of input but with a degraded resolution
*
*           out = num_to_reduce / 2^nb_shift
*           BINY = BINX / BIN(nb_shift)
*           DDS_SINT16_MIN <= Y <= DDS_SINT16_MAX
*
*  Warning:
*      nb_shift is initialised to 0 before shifting data
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_REDUCE_SINT32_TO_SINT16(sint32 num_to_reduce, CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    sint32 reduced_num;
    reduced_num = num_to_reduce;

    (*nb_shift) = 0;
    while ((reduced_num > DDS_SINT16_MAX) || (reduced_num < DDS_SINT16_MIN))
    {
        reduced_num /= BIN1;
        *nb_shift= (uint8)((t_dds_m_uint)(*nb_shift)+(t_dds_m_uint)1);
    }

    return( (sint16)reduced_num);
}

/*******************************************************************************
*  Function Name   : DDS_M_INCREASE_UINT32_TO_UINT32
*
*  Description     :
*           Increase the resolution of a 32bits variable num_to_increase (BINX)
*           in 32bits number out in BIN(X+nb_shift).
*           The number of shift used to increase the resolution is store in
*           nb_shift.
*
*           out = num_to_reduce * 2^nb_shift
*           BINY = BINX * BIN(nb_shift)
*           DDS_UINT32_MIN <= Y <= DDS_UINT32_MAX
*
*  Where:
*   - num_to_increase is the 32bits variable to increase
*   - nb_shift is the shift number used to increase resolution saving
*   - out is the 32bits variable with the same value of input but with a increased
*     resolution
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_INCREASE_UINT32_TO_UINT32 (uint32 num_to_increase,
                                                         CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    if (0 != num_to_increase)
    {
        while (num_to_increase <= (DDS_UINT32_MAX / BIN1))
        {
            num_to_increase = num_to_increase * BIN1;
            *nb_shift= (sint8)((t_dds_m_sint)(*nb_shift)+1);
        }
    }
    else
    {
        /* Do nothing */
    }
    return (num_to_increase);
}

/*******************************************************************************
*  Function Name   : DDS_M_INCREASE_SINT32_TO_SINT32
*
*  Description     :
*           Increase the resolution of a 32bits variable num_to_increase (BINX)
*           in 32bits number out in BIN(X+nb_shift).
*           The number of shift used to increase the resolution is store in
*           nb_shift.
*
*           out = num_to_reduce * 2^nb_shift
*           BINY = BINX * BIN(nb_shift)
*           DDS_SINT32_MIN <= Y <= DDS_SINT32_MAX
*
*  Where:
*   - num_to_increase is the 32bits variable to increase
*   - nb_shift is the shift number used to increase resolution saving
*   - out is the 32bits variable with the same value of input but with a increased
*     resolution
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_INCREASE_SINT32_TO_SINT32 (sint32 num_to_increase,
                                                         CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift)
{
    if (0 != num_to_increase)
    {
        while( (num_to_increase <= (DDS_SINT32_MAX / BIN1))
            &&  (num_to_increase >= (DDS_SINT32_MIN / BIN1)) )
        {
            num_to_increase = num_to_increase * BIN1;
            *nb_shift= (sint8)((t_dds_m_sint)(*nb_shift)+1);
        }
    }
    else
    {
        /* Do nothing */
    }
    return (num_to_increase);
}

/*******************************************************************************
*  Function Name   : DDS_M_RESTORE_BINPOINT_UINT32
*
*  Description     : restore the wished resolution from a  variable with a "dynamically" reduced resolution
*           - num_to_restore : 32 bits variable with "dynamically" reduced resolution : BIN(X- nb_shift)
*           - nb_shift_wished: sihft number necessary to reach the wished resolution from the degraded resolution.
*           - out : 32 bits variable with the wished resolution : BINY
*
*           0 < out <= DDS_UINT32_MAX
*           BINY = BIN(X-nb_shift) / BIN(nb_shift_wished)
*           nb_shift_wished = (X-Y) - nb_shift
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_RESTORE_BINPOINT_UINT32(uint32 num_to_restore, sint8 nb_shift_wished)
{
    uint32 last_bit = 0;
    t_dds_m_sint nb_shift_wished_tmp = (t_dds_m_sint)nb_shift_wished;

    if (nb_shift_wished_tmp >= 0)
    {
        while(nb_shift_wished_tmp > 0)
        {
            last_bit = num_to_restore & 1;
            num_to_restore /= BIN1;
            nb_shift_wished_tmp--;
        }
        num_to_restore += last_bit;
    }
    else /* nb_shift_wished < 0 */
    {
        while((num_to_restore <= (DDS_UINT32_MAX / BIN1))
                && (nb_shift_wished_tmp < 0))
        {
            num_to_restore *= BIN1;
            nb_shift_wished_tmp++;
        }
        /* restore completed ? */
        if(0 != nb_shift_wished_tmp)
        {
            /* Incompleted restore --> saturation */
            num_to_restore = DDS_UINT32_MAX;
        }
        else
        {
            /* Completed restore --> do nothing */
        }

    }
    return(num_to_restore);
}


/*******************************************************************************
*
*  Function Name   : DDS_M_RESTORE_BINPOINT_SINT32
*
*  Description     : restore the wished resolution from a  variable with a "dynamically" reduced resolution
*           - num_to_restore : 32 bits variable with "dynamically" reduced resolution : BIN(X- nb_shift)
*           - nb_shift_wished: sihft number necessary to reach the wished resolution from the degraded resolution.
*           - out : 32 bits variable with the wished resolution : BINY
*
*            DDS_SINT32_MAX < out <= DDS_SINT32_MAX
*           BINY = BIN(X-nb_shift) / BIN(nb_shift_wished)
*           nb_shift_wished = (X-Y) - nb_shift
*
*******************************************************************************/

FUNC(sint32, AUTOMATIC) DDS_M_RESTORE_BINPOINT_SINT32(sint32 num_to_restore, sint8 nb_shift_wished)
{
    uint32 last_bit = 0;
    uint32 num_to_restore_tmp;
    t_dds_m_sint nb_shift_wished_tmp = (t_dds_m_sint)nb_shift_wished;

    if (nb_shift_wished_tmp >= 0)
    {
        num_to_restore_tmp = (uint32)DDS_M_ABS(num_to_restore);
        while(nb_shift_wished_tmp > 0)
        {
            last_bit = num_to_restore_tmp & 1;
            num_to_restore_tmp /= BIN1;
            nb_shift_wished_tmp--;
        }
        num_to_restore_tmp += last_bit;

        if(0 > num_to_restore)
        {
            num_to_restore = -(sint32)num_to_restore_tmp;
        }
        else
        {
            num_to_restore = (sint32)num_to_restore_tmp;
        }
    }
    else /* nb_shift_wished < 0 */
    {
        while((num_to_restore <= (DDS_SINT32_MAX / BIN1))
            && (num_to_restore >= (DDS_SINT32_MIN / BIN1))
            && (nb_shift_wished_tmp != 0))
        {
            num_to_restore *= BIN1;
            nb_shift_wished_tmp++;
        }
        /* restore completed ? */
        if(0 != nb_shift_wished_tmp)
        {
            /* Incompleted restore --> saturation */
            if(0 <= num_to_restore)
            {
                num_to_restore = DDS_SINT32_MAX;
            }
            else
            {
                num_to_restore = DDS_SINT32_MIN;
            }
        }
        else
        {
            /* Completed restore --> do nothing */
        }
    }
    return(num_to_restore);
}


/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_MULT_U32_V1
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - current_bin_number: shift number corresponding to the initial binpoint reduced to the loss resolution:
*           current_bin_number must be initialized with the binpoint sum of a and b
*
*           BINZ  = (BINX * BINY) / BINnb_shift
*           current_bin_number = X+Y-nb_shift
*            result = a * b
*
*       Code example:
*       ---------------
*       current_bin_number = X+Y;
*       DDS_M_RESTORE_BINPOINT_UINT32(DDS_M_DYNAMIC_MULT_U32_V1(a, b, &current_bin_number),
*                               current_bin_number - Z);
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_U32_V1(uint32  a, uint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number)
{
    uint32 result;
    uint32 a_last_bit = 0;
    uint32 b_last_bit = 0;
    if((0 == a) || (0 == b))
    {
        result = 0;
    }
    else
    {
        while((a+a_last_bit) > (DDS_UINT32_MAX / (b+b_last_bit)))
        {
            (*current_bin_number) = (sint8)((t_dds_m_sint)(*current_bin_number)-1);

            if(0 == (a &1))
            {
                a_last_bit = 0;
                a /= BIN1;
            }
            else if(0 == (b & 1))
            {
                b_last_bit = 0;
                b /= BIN1;
            }
            else if(b > a)
            {
                b_last_bit = 1;
                b /= BIN1;
            }
            else
            {
                a_last_bit = 1;
                a /= BIN1;
            }
        }
        a += a_last_bit;
        b += b_last_bit;
        result = a * b;
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_MULT_U32_V2
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - current_bin_number: shift number corresponding to the initial binpoint reduced to the loss resolution:
*           current_bin_number must be initialized with the binpoint sum of a and b
*
*           BINZ  = (BINX * BINY) / BINnb_shift
*           current_bin_number = X+Y-nb_shift
*            result = a * b
*
*       Code example:
*       ---------------
*       current_bin_number = X+Y;
*       DDS_M_RESTORE_BINPOINT_UINT32(DDS_M_DYNAMIC_MULT_U32_V2(a, b, &current_bin_number),
*                               current_bin_number - Z);
*
*******************************************************************************/

FUNC(uint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_U32_V2(uint32  a, uint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number)
{
    uint32 result;
    t_dds_m_uint64 temp;

    temp = (t_dds_m_uint64)a * (t_dds_m_uint64)b;
    while(temp >= (t_dds_m_uint64)DDS_UINT32_MAX)
    {
        temp = temp / (t_dds_m_uint64)BIN1;
        (*current_bin_number) = (sint8)((t_dds_m_sint)(*current_bin_number)-1);
    }
    result = (uint32)temp;

    return result;
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_MULT_S32_V1
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - current_bin_number: shift number corresponding to the initial binpoint reduced to the loss resolution:
*           current_bin_number must be initialized with the binpoint sum of a and b
*
*           BINZ  = (BINX * BINY) / BINnb_shift
*           current_bin_number = X+Y-nb_shift
*            result = a * b
*
*       Code example:
*       ---------------
*       current_bin_number = X+Y;
*       DDS_M_RESTORE_BINPOINT_SINT32(DDS_M_DYNAMIC_MULT_S32_V1(a, b, &current_bin_number),
*                               current_bin_number - Z);
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_S32_V1(sint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number)
{
    sint32 result;
    uint32 result_tmp;
    sint8 bin_reduction = 0;

    result_tmp = DDS_M_DYNAMIC_MULT_U32((uint32)DDS_M_ABS(a), (uint32)DDS_M_ABS(b), current_bin_number);
    if(0 == result_tmp)
    {
        result = 0;
    }
    else if(((0 < a) && (0 < b)) || ((0 > a) && (0 > b)))
    {
        /* Reduce resolution if result_tmp > DDS_SINT32_MAX */
        result = (sint32)DDS_M_SHORTEN_UINT32_TO_UINT32(result_tmp,
                                                        (uint32)DDS_SINT32_MAX,
                                                        &bin_reduction);

    }
    else
    {
        /* Reduce resolution if result_tmp < DDS_SINT32_MIN */
        result = -(sint32)DDS_M_SHORTEN_UINT32_TO_UINT32(result_tmp,
                                                        (uint32)(-DDS_SINT32_MIN),
                                                        &bin_reduction);
    }
    *current_bin_number = (sint8)((t_dds_m_sint)(*current_bin_number) - (t_dds_m_sint)bin_reduction);

    return(result);
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_MULT_S32_V2
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - current_bin_number: shift number corresponding to the initial binpoint reduced to the loss resolution:
*           current_bin_number must be initialized with the binpoint sum of a and b
*
*           BINZ  = (BINX * BINY) / BINnb_shift
*           current_bin_number = X+Y-nb_shift
*            result = a * b
*
*       Code example:
*       ---------------
*       current_bin_number = X+Y;
*       DDS_M_RESTORE_BINPOINT_SINT32(DDS_M_DYNAMIC_MULT_S32_V2(a, b, &current_bin_number),
*                               current_bin_number - Z);
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_S32_V2(sint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number)
{
    sint32 result;
    t_dds_m_uint64 temp;

    temp = (t_dds_m_uint64)DDS_M_ABS(a) * (t_dds_m_uint64)DDS_M_ABS(b);

    if(0 == temp)
    {
        result = 0;
    }
    else if(((0 < a) && (0 < b)) || ((0 > a) && (0 > b)))
    {
        while(temp >= (t_dds_m_uint64)DDS_SINT32_MAX)
        {
            temp = temp / (t_dds_m_uint64)BIN1;
            (*current_bin_number) = (sint8)((t_dds_m_sint)(*current_bin_number)-1);
        }
        result = (sint32)temp;
    }
    else
    {
        while(temp >= (t_dds_m_uint64)(-DDS_SINT32_MIN))
        {
            temp = temp / (t_dds_m_uint64)BIN1;
            (*current_bin_number) = (sint8)((t_dds_m_sint)(*current_bin_number)-1);
        }
        result = -(sint32)temp;
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_MULT_USS32_V1
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - current_bin_number: shift number corresponding to the initial binpoint reduced to the loss resolution:
*           current_bin_number must be initialized with the binpoint sum of a and b
*
*           BINZ  = (BINX * BINY) / BINnb_shift
*           current_bin_number = X+Y-nb_shift
*            result = a * b
*
*       Code example:
*       ---------------
*       current_bin_number = X+Y;
*       DDS_M_RESTORE_BINPOINT_SINT32(DDS_M_DYNAMIC_MULT_USS32_V1(a, b, &current_bin_number),
*                               current_bin_number - Z);
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_USS32_V1(uint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number)
{
    uint32 result_tmp;
    sint32 result;
    sint8 bin_reduction = 0;

    if(b >= 0)
    {
        result_tmp = DDS_M_DYNAMIC_MULT_U32(a, (uint32)b, current_bin_number);
        /* Reduce resolution if result_tmp > DDS_SINT32_MAX */
        result = (sint32)DDS_M_SHORTEN_UINT32_TO_UINT32(result_tmp, (uint32)DDS_SINT32_MAX, &bin_reduction);
    }
    else
    {
        result_tmp = DDS_M_DYNAMIC_MULT_U32(a, (uint32)(-b), current_bin_number);
        /* Reduce resolution if result_tmp < DDS_SINT32_MIN */
        result = -(sint32)DDS_M_SHORTEN_UINT32_TO_UINT32(result_tmp, (uint32)(-DDS_SINT32_MIN), &bin_reduction);
    }
    *current_bin_number = (sint8)((t_dds_m_sint)(*current_bin_number) - (t_dds_m_sint)bin_reduction);
    return(result);
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_MULT_USS32_V2
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - current_bin_number: shift number corresponding to the initial binpoint reduced to the loss resolution:
*           current_bin_number must be initialized with the binpoint sum of a and b
*
*           BINZ  = (BINX * BINY) / BINnb_shift
*           current_bin_number = X+Y-nb_shift
*            result = a * b
*
*       Code example:
*       ---------------
*       current_bin_number = X+Y;
*       DDS_M_RESTORE_BINPOINT_SINT32(DDS_M_DYNAMIC_MULT_USS32_V2(a, b, &current_bin_number),
*                               current_bin_number - Z);
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_USS32_V2(uint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number)
{
    sint32 result;
    t_dds_m_uint64 temp;

    temp = (t_dds_m_uint64)a * (t_dds_m_uint64)DDS_M_ABS(b);

    if(0 == temp)
    {
        result = 0;
    }
    else if(b > 0)
    {
        while(temp >= (t_dds_m_uint64)DDS_SINT32_MAX)
        {
            temp = temp / (t_dds_m_uint64)BIN1;
            (*current_bin_number) = (sint8)((t_dds_m_sint)(*current_bin_number)-1);
        }
        result = (sint32)temp;
    }
    else
    {
        while(temp >= (t_dds_m_uint64)(-DDS_SINT32_MIN))
        {
            temp = temp / (t_dds_m_uint64)BIN1;
            (*current_bin_number) = (sint8)((t_dds_m_sint)(*current_bin_number)-1);
        }
        result = -(sint32)temp;
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_DIV_U32
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - bin_number_num: sihft number corresponding to the "a BIN"
*           - bin_number_denum: sihft number corresponding to the "b BIN"
*           - bin_number_expected: sihft number corresponding to the "expected BIN"
*
*           BINZ  = BINX / BINY
*            result = a / b
*
*   bin_number_num = X
*   bin_number_denum = Y
*   bin_number_expected = Z
*
*******************************************************************************/

FUNC(uint32, AUTOMATIC)  DDS_M_DYNAMIC_DIV_U32(uint32  a, uint32 b, sint8 bin_number_num, sint8 bin_number_denum, sint8 bin_number_expected)
{
    uint32 result;
    uint32 num_increased;
    uint32 denum_reduced;
    sint8 bin_number_num_increased;
    t_dds_m_sint nb_shift_result;

    nb_shift_result = (t_dds_m_sint)bin_number_num - (t_dds_m_sint)bin_number_denum;
    if(0 == a)
    {
        result = 0;
    }
    else if(0 == b)
    {
        result = DDS_UINT32_MAX;
    }
    else if(nb_shift_result >= (t_dds_m_sint)bin_number_expected)
    {
        result = DDS_M_RESTORE_BINPOINT_UINT32(a / b, (sint8)(nb_shift_result - (t_dds_m_sint)bin_number_expected));
    }
    else /* nb_shift_result < bin_number_expected */
    {
        bin_number_num_increased = bin_number_num;
        num_increased = DDS_M_INCREASE_UINT32_TO_UINT32(a, &bin_number_num_increased);
        nb_shift_result = (t_dds_m_sint)bin_number_num_increased - (t_dds_m_sint)bin_number_denum;
        if(nb_shift_result >= (t_dds_m_sint)bin_number_expected)
        {
            result = DDS_M_RESTORE_BINPOINT_UINT32(num_increased / b, (sint8)(nb_shift_result - (t_dds_m_sint)bin_number_expected));
        }
        else
        {
            denum_reduced = DDS_M_RESTORE_BINPOINT_UINT32(b, (sint8)((t_dds_m_sint)bin_number_expected - nb_shift_result));
            if(0 == denum_reduced)
            {
                result = DDS_UINT32_MAX;
            }
            else
            {
                result = num_increased / denum_reduced;
            }
        }
    }
    return(result);
}



/*******************************************************************************
*
*  Function Name   : DDS_M_DYNAMIC_DIV_S32
*
*  Description     :  "dynamic" multiplication calculation
*           - a : 32 bits variable
*           - b : 32 bits variable
*           - bin_number_num: sihft number corresponding to the "a BIN"
*           - bin_number_denum: sihft number corresponding to the "b BIN"
*           - bin_number_expected: sihft number corresponding to the "expected BIN"
*
*           BINZ  = BINX / BINY
*            result = a / b
*
*   bin_number_num = X
*   bin_number_denum = Y
*   bin_number_expected = Z
*
*******************************************************************************/

FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_DIV_S32(sint32  a, sint32 b, sint8 bin_number_num, sint8 bin_number_denum, sint8 bin_number_expected)
{
    sint32 result;
    sint32 num_increased;
    sint32 denum_reduced;
    sint8 bin_number_num_increased;
    t_dds_m_sint nb_shift_result;

    nb_shift_result = (t_dds_m_sint)bin_number_num - (t_dds_m_sint)bin_number_denum;
    if(0 == a)
    {
        result = 0;
    }
    else if(0 == b)
    {
        if(a > 0)
        {
            result = DDS_SINT32_MAX;
        }
        else
        {
            result = DDS_SINT32_MIN;
        }
    }
    else if(nb_shift_result >= (t_dds_m_sint)bin_number_expected)
    {
        result = DDS_M_RESTORE_BINPOINT_SINT32(a / b, (sint8)(nb_shift_result - (t_dds_m_sint)bin_number_expected));
    }
    else /* nb_shift_result < bin_number_expected */
    {
        bin_number_num_increased = bin_number_num;
        num_increased = DDS_M_INCREASE_SINT32_TO_SINT32(a, &bin_number_num_increased);
        nb_shift_result = (t_dds_m_sint)bin_number_num_increased - (t_dds_m_sint)bin_number_denum;
        if(nb_shift_result >= (t_dds_m_sint)bin_number_expected)
        {
            result = DDS_M_RESTORE_BINPOINT_SINT32(num_increased / b, (sint8)(nb_shift_result - (t_dds_m_sint)bin_number_expected));
        }
        else
        {
            denum_reduced = DDS_M_RESTORE_BINPOINT_SINT32(b, (sint8)((t_dds_m_sint)bin_number_expected - nb_shift_result));
            if(0 == denum_reduced)
            {
                if(a > 0)
                {
                    result = DDS_SINT32_MAX;
                }
                else
                {
                    result = DDS_SINT32_MIN;
                }
            }
            else
            {
                result = num_increased / denum_reduced;
            }
        }
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   : DDS_M_DECREMENT_SINT32
*
*  Description     : decrement the input by one and check under flow.
*
*  Warning: the minimum will depend on the machine implementation
*           -2147483647 or -2147483648
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_DECREMENT_SINT32(sint32 nb_to_decrease)
{
    nb_to_decrease--;
    if (0 < nb_to_decrease)
    {
        nb_to_decrease = DDS_SINT32_MIN;
    }
    else
    {
        /* Do nothing */
    }
    return nb_to_decrease;
}

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_U32 (Comes from M_SOFT_TRANS_V2_U32)
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following function performs a gradual transition between target_enable
*  and target_disable.
*  When Enable is TRUE, output value change gradually from current value
*   to target_enable at each call.
*  When Enable is FALSE, output value change gradually from current value
*   to target_disable at each call.
*
*
*  Where:
*   enable is the enable flag
*   target_disable is the target value when enable = FALSE
*   target_enable is the target value when enable = TRUE
*   current_time is the current timer
*   disable_to_enable_duration is the time to go from target_disable
*           to target_enable
*   enable_to_disable_duration is the time to go from target_enable
*           to target_disable
*   soft_trans_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   user is in charge reset the macro before first use by using macro
*   M_SOFT_TRANS_INIT_U32
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_U32(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        uint32 current_time,
                        uint32 disable_to_enable_duration,
                        uint32 enable_to_disable_duration,
                        CONSTP2VAR (t_dds_m_soft_trans_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr)
{
    uint32 delta_time;
    uint32 local_output;
    uint32 term_dis;
    uint32 term_en;
    uint32 error_out;
    uint32 tmp;
    uint16 ratio_inv;

    uint8 trans_active_out;
    uint8 calculate_output;

    calculate_output = DDS_FALSE;

    if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)soft_trans_struct_ptr->previous_enable)
    {
        if(  ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)enable)
           &&((t_dds_m_uint)0 == (t_dds_m_uint)enable_to_disable_duration))
        {
            soft_trans_struct_ptr->ratio        = 0;
            soft_trans_struct_ptr->error        = 0;
            soft_trans_struct_ptr->error_shift  = 0;
            local_output                        = target_disable;
            trans_active_out                    = DDS_FALSE;
        }
        else if((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN > (t_dds_m_uint)soft_trans_struct_ptr->ratio)
        {   /* Ramp is in progress */
            delta_time = current_time - soft_trans_struct_ptr->previous_time;

            soft_trans_struct_ptr->ratio = DDS_M_SOFT_TRANS_INC_RATIO(delta_time,
                                               disable_to_enable_duration,
                                               soft_trans_struct_ptr->ratio,
                                               &(soft_trans_struct_ptr->error),
                                               &(soft_trans_struct_ptr->error_shift));

            if((t_dds_m_uint)soft_trans_struct_ptr->ratio < (t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN)
            {
                trans_active_out = DDS_TRUE;
                calculate_output = DDS_TRUE;
            }
            else
            {
                trans_active_out                    = DDS_FALSE;
                local_output                        = target_enable;
                soft_trans_struct_ptr->error        = 0;
                soft_trans_struct_ptr->error_shift  = 0;

            }


            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)enable)
            {   /* Change ramp direction : reset error because it will be used in wrong direction */
                soft_trans_struct_ptr->error    = 0;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)enable)
        {   /* Start transition to disable state */
            local_output                        = target_enable;
            trans_active_out                    = DDS_TRUE;

        }
        else
        {   /* enable state */
            local_output                        = target_enable;
            trans_active_out                    = DDS_FALSE;
        }
    }
    else
    {
        if(  ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)enable)
           &&(0 == disable_to_enable_duration))
        {
            soft_trans_struct_ptr->ratio        = DDS_M_SOFT_TRANS_RATIO_BIN;
            soft_trans_struct_ptr->error        = 0;
            soft_trans_struct_ptr->error_shift  = 0;
            local_output                        = target_enable;
            trans_active_out                    = DDS_FALSE;
        }
        else if((t_dds_m_uint)0 < (t_dds_m_uint)soft_trans_struct_ptr->ratio)
        {   /* Ramp is in progress */
            delta_time = (current_time - soft_trans_struct_ptr->previous_time);


            soft_trans_struct_ptr->ratio = (uint16)((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN
                                           - (t_dds_m_uint)DDS_M_SOFT_TRANS_INC_RATIO(
                                               delta_time,
                                               enable_to_disable_duration,
                                               (uint16)((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN - (t_dds_m_uint)soft_trans_struct_ptr->ratio),
                                               &(soft_trans_struct_ptr->error),
                                               &(soft_trans_struct_ptr->error_shift)));


            if((t_dds_m_uint)soft_trans_struct_ptr->ratio > (t_dds_m_uint)0)
            {
                trans_active_out = DDS_TRUE;
                calculate_output = DDS_TRUE;
            }
            else
            {
                trans_active_out                    = DDS_FALSE;
                local_output                        = target_disable;
                soft_trans_struct_ptr->error        = 0;
                soft_trans_struct_ptr->error_shift  = 0;
            }


            if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)enable)
            {   /* Change ramp direction : reset error because it will be used in wrong direction */
                soft_trans_struct_ptr->error        = 0;
            }
            else
            {
                /* Do Nothing */
            }

        }
        else if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)enable)
        {   /* Start transition to enable state */
            local_output                            = target_disable;
            trans_active_out                        = DDS_TRUE;
        }
        else
        {   /* diadble state */
            local_output                            = target_disable;
            trans_active_out                        = DDS_FALSE;
        }

    }

    if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)calculate_output)
    {
        ratio_inv =  (uint16)((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN - (t_dds_m_uint)soft_trans_struct_ptr->ratio);
        if(target_disable < BIN17)
        {
            tmp         = target_disable * (uint32)ratio_inv;
            term_dis    = tmp /  DDS_M_SOFT_TRANS_RATIO_BIN;
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   = tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }
        else
        {
            tmp         = (target_disable%DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)ratio_inv;
            term_dis    = ((target_disable/DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)ratio_inv)
                           + (tmp/DDS_M_SOFT_TRANS_RATIO_BIN);
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   = tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }

        if(target_enable < BIN17)
        {
            tmp         = target_enable * (uint32)soft_trans_struct_ptr->ratio;
            term_en     = (target_enable * (uint32)soft_trans_struct_ptr->ratio) / DDS_M_SOFT_TRANS_RATIO_BIN;
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   += tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }
        else
        {
            tmp         = (target_enable%DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)soft_trans_struct_ptr->ratio;
            term_en =   ((target_enable/DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)soft_trans_struct_ptr->ratio)
                      + ( tmp / DDS_M_SOFT_TRANS_RATIO_BIN);
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   += tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }

        local_output = term_dis + term_en + (error_out / DDS_M_SOFT_TRANS_RATIO_BIN);
    }
    else
    {
        /* local_output ever calculated */
    }

    soft_trans_struct_ptr->previous_enable = enable;
    soft_trans_struct_ptr->previous_time   = current_time;

    if(DDS_NULL_PTR != soft_trans_struct_ptr->trans_active_ptr)
    {
        *soft_trans_struct_ptr->trans_active_ptr    = trans_active_out;
    }
    else
    {
        /* Do Nothing */
    }
    return (local_output);

}

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_INIT_U32
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following macro manage initialization before starting M_SOFT_TRANS_V2_U32.
*
*
*  Where:
*   enable is the enable flag
*   target_disable is the target value when enable = FALSE
*   target_enable is the target value when enable = TRUE
*   current_time is the current timer
*   trans_active_ptr : Optionnal pointer to a transition active flag
*   soft_trans_struct_ptr is the structure associated to macro
*
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_INIT_U32(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        uint32 current_time,
                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) trans_active_ptr,      /* May be DDS_NULL_PTR */
                        CONSTP2VAR (t_dds_m_soft_trans_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr)

{
    uint32 output;

    soft_trans_struct_ptr->previous_enable  = enable;
    soft_trans_struct_ptr->previous_time    = current_time;
    soft_trans_struct_ptr->error            = 0;
    soft_trans_struct_ptr->error_shift      = 0;

    soft_trans_struct_ptr->trans_active_ptr = trans_active_ptr;
    if(DDS_NULL_PTR != trans_active_ptr)
    {
        *trans_active_ptr  = DDS_FALSE;
    }
    else
    {
        /* Do Nothing */
    }

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)enable)
    {
        soft_trans_struct_ptr->ratio    = DDS_M_SOFT_TRANS_RATIO_BIN;
        output                          = target_enable;
    }
    else
    {
        soft_trans_struct_ptr->ratio    = 0;
        output                          = target_disable;
    }
    return(output);
}



/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_DELTA_U32 (Comes from DDS_M_SOFT_TRANS_U32)
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following function performs a gradual transition between target_enable
*  and target_disable.
*  When Enable is TRUE, output value change gradually from current value
*   to target_enable at each call.
*  When Enable is FALSE, output value change gradually from current value
*   to target_disable at each call.
*
*
*  Where:
*   enable is the enable flag
*   target_disable is the target value when enable = FALSE
*   target_enable is the target value when enable = TRUE
*   delta_time is time elapsed between calls (replace current time)
*   disable_to_enable_duration is the time to go from target_disable
*           to target_enable
*   enable_to_disable_duration is the time to go from target_enable
*           to target_disable
*   soft_trans_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   user is in charge reset the macro before first use by using macro
*   M_SOFT_TRANS_INIT_U32
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_U32(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        uint32 delta_time,
                        uint32 disable_to_enable_duration,
                        uint32 enable_to_disable_duration,
                        CONSTP2VAR (t_dds_m_soft_trans_delta_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr)
{
    /*uint32 delta_time;*/
    uint32 local_output;
    uint32 term_dis;
    uint32 term_en;
    uint32 error_out;
    uint32 tmp;
    uint16 ratio_inv;

    uint8 trans_active_out;
    uint8 calculate_output;

    calculate_output = DDS_FALSE;

    if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)soft_trans_struct_ptr->previous_enable)
    {
        if(  ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)enable)
           &&(0 == enable_to_disable_duration))
        {
            soft_trans_struct_ptr->ratio        = 0;
            soft_trans_struct_ptr->error        = 0;
            soft_trans_struct_ptr->error_shift  = 0;
            local_output                        = target_disable;
            trans_active_out                    = DDS_FALSE;
        }
        else if((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN > (t_dds_m_uint)soft_trans_struct_ptr->ratio)
        {   /* Ramp is in progress */
            /*delta_time = current_time - soft_trans_struct_ptr->previous_time;*/

            soft_trans_struct_ptr->ratio = DDS_M_SOFT_TRANS_INC_RATIO(delta_time,
                                               disable_to_enable_duration,
                                               soft_trans_struct_ptr->ratio,
                                               &(soft_trans_struct_ptr->error),
                                               &(soft_trans_struct_ptr->error_shift));

            if((t_dds_m_uint)soft_trans_struct_ptr->ratio < (t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN)
            {
                trans_active_out = DDS_TRUE;
                calculate_output = DDS_TRUE;
            }
            else
            {
                trans_active_out                    = DDS_FALSE;
                local_output                        = target_enable;
                soft_trans_struct_ptr->error        = 0;
                soft_trans_struct_ptr->error_shift  = 0;

            }


            if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)enable)
            {   /* Change ramp direction : reset error because it will be used in wrong direction */
                soft_trans_struct_ptr->error    = 0;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else if((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)enable)
        {   /* Start transition to disable state */
            local_output                        = target_enable;
            trans_active_out                    = DDS_TRUE;

        }
        else
        {   /* enable state */
            local_output                        = target_enable;
            trans_active_out                    = DDS_FALSE;
        }
    }
    else
    {
        if(  ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)enable)
           &&(0 == disable_to_enable_duration))
        {
            soft_trans_struct_ptr->ratio        = DDS_M_SOFT_TRANS_RATIO_BIN;
            soft_trans_struct_ptr->error        = 0;
            soft_trans_struct_ptr->error_shift  = 0;
            local_output                        = target_enable;
            trans_active_out                    = DDS_FALSE;
        }
        else if((t_dds_m_uint)0 < (t_dds_m_uint)soft_trans_struct_ptr->ratio)
        {   /* Ramp is in progress */
            /*delta_time = (current_time - soft_trans_struct_ptr->previous_time);*/


            soft_trans_struct_ptr->ratio = (uint16)((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN
                                           - (t_dds_m_uint)DDS_M_SOFT_TRANS_INC_RATIO(
                                               delta_time,
                                               enable_to_disable_duration,
                                               (uint16)((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN - (t_dds_m_uint)soft_trans_struct_ptr->ratio),
                                               &(soft_trans_struct_ptr->error),
                                               &(soft_trans_struct_ptr->error_shift)));


            if((t_dds_m_uint)soft_trans_struct_ptr->ratio > (t_dds_m_uint)0)
            {
                trans_active_out = DDS_TRUE;
                calculate_output = DDS_TRUE;
            }
            else
            {
                trans_active_out                    = DDS_FALSE;
                local_output                        = target_disable;
                soft_trans_struct_ptr->error        = 0;
                soft_trans_struct_ptr->error_shift  = 0;
            }


            if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)enable)
            {   /* Change ramp direction : reset error because it will be used in wrong direction */
                soft_trans_struct_ptr->error        = 0;
            }
            else
            {
                /* Do Nothing */
            }

        }
        else if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)enable)
        {   /* Start transition to enable state */
            local_output                            = target_disable;
            trans_active_out                        = DDS_TRUE;
        }
        else
        {   /* diadble state */
            local_output                            = target_disable;
            trans_active_out                        = DDS_FALSE;
        }

    }

    if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)calculate_output)
    {
        ratio_inv =  (uint16)((t_dds_m_uint)DDS_M_SOFT_TRANS_RATIO_BIN - (t_dds_m_uint)soft_trans_struct_ptr->ratio);
        if(target_disable < BIN17)
        {
            tmp         = target_disable * (uint32)ratio_inv;
            term_dis    = tmp /  DDS_M_SOFT_TRANS_RATIO_BIN;
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   = tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }
        else
        {
            tmp         = (target_disable%DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)ratio_inv;
            term_dis    = ((target_disable/DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)ratio_inv)
                           + (tmp/DDS_M_SOFT_TRANS_RATIO_BIN);
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   = tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }

        if(target_enable < BIN17)
        {
            tmp         = target_enable * (uint32)soft_trans_struct_ptr->ratio;
            term_en     = (target_enable * (uint32)soft_trans_struct_ptr->ratio) / DDS_M_SOFT_TRANS_RATIO_BIN;
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   += tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }
        else
        {
            tmp         = (target_enable%DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)soft_trans_struct_ptr->ratio;
            term_en =   ((target_enable/DDS_M_SOFT_TRANS_RATIO_BIN)* (uint32)soft_trans_struct_ptr->ratio)
                      + ( tmp / DDS_M_SOFT_TRANS_RATIO_BIN);
            /* %DDS_M_SOFT_TRANS_RATIO_BIN = &(DDS_M_SOFT_TRANS_RATIO_BIN-1) for pos val */
            error_out   += tmp &(DDS_M_SOFT_TRANS_RATIO_BIN-1);
        }

        local_output = term_dis + term_en + (error_out / DDS_M_SOFT_TRANS_RATIO_BIN);
    }
    else
    {
        /* local_output ever calculated */
    }

    soft_trans_struct_ptr->previous_enable = enable;
    /*soft_trans_struct_ptr->previous_time   = current_time;*/

    if(DDS_NULL_PTR != soft_trans_struct_ptr->trans_active_ptr)
    {
        *soft_trans_struct_ptr->trans_active_ptr    = trans_active_out;
    }
    else
    {
        /* Do Nothing */
    }
    return (local_output);

}

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_DELTA_U32_INIT
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following macro manage initialization before starting DDS_M_SOFT_TRANS_U32_DELTA.
*
*
*  Where:
*   enable is the enable flag
*   target_disable is the target value when enable = FALSE
*   target_enable is the target value when enable = TRUE
*   delta_time is time elapsed between calls (replace current time)
*   trans_active_ptr : Optionnal pointer to a transition active flag
*   soft_trans_struct_ptr is the structure associated to macro
*
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_U32_INIT(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        /*uint32 delta_time,*/
                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) trans_active_ptr,      /* May be DDS_NULL_PTR */
                        CONSTP2VAR (t_dds_m_soft_trans_delta_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr)

{
    uint32 output;

    soft_trans_struct_ptr->previous_enable  = enable;
    /*soft_trans_struct_ptr->previous_time    = current_time;*/
    soft_trans_struct_ptr->error            = 0;
    soft_trans_struct_ptr->error_shift      = 0;

    soft_trans_struct_ptr->trans_active_ptr = trans_active_ptr;
    if(DDS_NULL_PTR != trans_active_ptr)
    {
        *trans_active_ptr  = DDS_FALSE;
    }
    else
    {
        /* Do Nothing */
    }

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)enable)
    {
        soft_trans_struct_ptr->ratio    = DDS_M_SOFT_TRANS_RATIO_BIN;
        output                          = target_enable;
    }
    else
    {
        soft_trans_struct_ptr->ratio    = 0;
        output                          = target_disable;
    }
    return(output);
}



/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_DELTA_S32 (Comes from DDS_M_SOFT_TRANS_U32)
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following function performs a gradual transition between target_enable
*  and target_disable.
*  When Enable is TRUE, output value change gradually from current value
*   to target_enable at each call.
*  When Enable is FALSE, output value change gradually from current value
*   to target_disable at each call.
*
*
*  Where:
*   enable is the enable flag
*   target_disable is the target value when enable = FALSE
*   target_enable is the target value when enable = TRUE
*   delta_time is time elapsed between calls (replace current time)
*   disable_to_enable_duration is the time to go from target_disable
*           to target_enable
*   enable_to_disable_duration is the time to go from target_enable
*           to target_disable
*   soft_trans_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   user is in charge reset the macro before first use by using macro
*   M_SOFT_TRANS_INIT_U32
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_S32(uint8 enable,
                        sint32 target_disable,
                        sint32 target_enable,
                        uint32 delta_time,
                        uint32 disable_to_enable_duration,
                        uint32 enable_to_disable_duration,
                        CONSTP2VAR (t_dds_m_soft_trans_delta_s32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr)
{
    sint32 s_output;
    uint32 u_output;
    uint32 u_target_disable;
    uint32 u_target_enable;

    if(target_disable <= 0)
    {
        u_target_disable = (uint32)(target_disable + DDS_SINT32_MAX);
    }
    else
    {
        u_target_disable = (uint32)target_disable + (uint32)DDS_SINT32_MAX;
    }

    if(target_enable <= 0)
    {
        u_target_enable = (uint32)(target_enable + DDS_SINT32_MAX);
    }
    else
    {
        u_target_enable = (uint32)target_enable + (uint32)DDS_SINT32_MAX;
    }


    u_output = DDS_M_SOFT_TRANS_DELTA_U32(
                        enable,
                        u_target_disable,
                        u_target_enable,
                        delta_time,
                        disable_to_enable_duration,
                        enable_to_disable_duration,
                        soft_trans_struct_ptr);

    if(u_output <= (uint32)DDS_SINT32_MAX)
    {
        s_output = (sint32)u_output - DDS_SINT32_MAX;
    }
    else
    {
        s_output = (sint32)(u_output - (uint32)DDS_SINT32_MAX);
    }

    return(s_output);
}


/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_DELTA_U32_INIT
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following macro manage initialization before starting DDS_M_SOFT_TRANS_U32_DELTA.
*
*
*  Where:
*   enable is the enable flag
*   target_disable is the target value when enable = FALSE
*   target_enable is the target value when enable = TRUE
*   delta_time is time elapsed between calls (replace current time)
*   trans_active_ptr : Optionnal pointer to a transition active flag
*   soft_trans_struct_ptr is the structure associated to macro
*
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_S32_INIT(uint8 enable,
                        sint32 target_disable,
                        sint32 target_enable,
                        /*uint32 delta_time,*/
                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) trans_active_ptr,      /* May be DDS_NULL_PTR */
                        CONSTP2VAR (t_dds_m_soft_trans_delta_s32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr)

{
    sint32 s_output;
    uint32 u_output;
    uint32 u_target_disable;
    uint32 u_target_enable;

    if(target_disable <= 0)
    {
        u_target_disable = (uint32)(target_disable + DDS_SINT32_MAX);
    }
    else
    {
        u_target_disable = (uint32)target_disable + (uint32)DDS_SINT32_MAX;
    }

    if(target_enable <= 0)
    {
        u_target_enable = (uint32)(target_enable + DDS_SINT32_MAX);
    }
    else
    {
        u_target_enable = (uint32)target_enable + (uint32)DDS_SINT32_MAX;
    }


    u_output = DDS_M_SOFT_TRANS_DELTA_U32_INIT(enable,
                                               u_target_disable,
                                               u_target_enable,
                                               trans_active_ptr,
                                               soft_trans_struct_ptr);

    if(u_output <= (uint32)DDS_SINT32_MAX)
    {
        s_output = (sint32)u_output - DDS_SINT32_MAX;
    }
    else
    {
        s_output = (sint32)(u_output - (uint32)DDS_SINT32_MAX);
    }

    return(s_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_LINEAR_FILTER_S32
*
*  Description :
*  The following function manage the transtion between last value and the
*  selected input. After Tr time output takes value of selected input.
*
*  With characteristics:
*   linear_filter_ptr is the structure associated to macro
*   acv_ptr pointer to a activation flag
*   sel is the input selector
*   in1 is the 1st input
*   in2 is the 2nd input
*   tr is the transition time
*   inh is the inhibit function command
*   current_time is the current time
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_LINEAR_FILTER_S32(
        CONSTP2VAR(t_dds_m_linear_filter_s32, AUTOMATIC, AUTOMATIC) linear_filter_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8 sel,
        sint32 in1,
        sint32 in2,
        uint32 tr,
        uint8 inh,
        uint32 current_time)
{
    uint8 retrigger;
    uint8 activation;
    sint32 input;
    uint8 input_set;
    uint8 compar_time;
    sint32 switch_result;
    sint32 output_result;
    sint32 temp_s32;
    uint32 temp_u32;
    uint32 integ_output;


    /* Calculate flip-flop SET */
    if(((t_dds_m_uint)linear_filter_ptr->previous_input_choice != (t_dds_m_uint)sel) &&
        ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)inh))
    {
        input_set = DDS_TRUE;
    }
    else
    {
        input_set = DDS_FALSE;
    }

    /* Calculate condition for flip-flop RESET */
    if(linear_filter_ptr->previous_integ_output >= tr)
    {
        compar_time = DDS_TRUE;
    }
    else
    {
        compar_time = DDS_FALSE;
    }

    /* RS Flip-flop evaluation */
    if (( ( ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)linear_filter_ptr->previous_compar_time) &&
            ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)compar_time)) && ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)input_set) ) ||
        ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)inh))
    {
        activation = DDS_FALSE;
    }
    else if ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)input_set)
    {
        activation = DDS_TRUE;
    }
    else
    {
        activation = linear_filter_ptr->previous_activation;
    }

    /* Calculate "retrigger" */
    if(((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)input_set) &&
        ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)linear_filter_ptr->previous_activation))
    {
        retrigger = DDS_TRUE;
    }
    else
    {
        retrigger = DDS_FALSE;
    }

    /* Timing integrator */
    if ( (((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)retrigger) &&
          ((t_dds_m_uint)DDS_FALSE ==  (t_dds_m_uint)linear_filter_ptr->previous_retrigger)) ||
         ((t_dds_m_uint)activation != (t_dds_m_uint)linear_filter_ptr->previous_activation) )
    {
        integ_output = 0;
        linear_filter_ptr->chrono_start_time = current_time;
    }
    else
    {
        integ_output = current_time - linear_filter_ptr->chrono_start_time;
    }

    /* Input slection */
    if((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)sel)
    {
        input = in2;
    }
    else
    {
        input = in1;
    }

    if(((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)retrigger) &&
        ((t_dds_m_uint)DDS_FALSE != (t_dds_m_uint)linear_filter_ptr->previous_activation))
    {
        switch_result = linear_filter_ptr->previous_switch_result;
    }
    else
    {
        switch_result = DDS_M_ADDITION_S32(linear_filter_ptr->previous_filtered_out, -input);
    }

    /* */
    if (((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)activation) || (0 == tr))
    {
        output_result = input;
    }
    else
    {
        if (0 == integ_output)
        {
            output_result = DDS_M_ADDITION_S32(switch_result, input);
        }
        else if (integ_output >= tr)
        {
            output_result = input;
        }
        else
        {
            /*  output_result = input + ((switch_result - switch_result * (integ_output / tr)); */
            if (switch_result > 0)
            {
                temp_u32 = (((uint32)switch_result/tr)*integ_output) + ((((uint32)switch_result%tr)*integ_output)/tr);
                temp_s32 = (sint32)temp_u32;
            }
            else
            {
                temp_u32 = (((uint32)-switch_result/tr)*integ_output) + ((((uint32)-switch_result%tr)*integ_output)/tr);
                temp_s32 = -(sint32)temp_u32;
            }

            temp_s32 = DDS_M_ADDITION_S32(switch_result, -temp_s32);
            output_result = DDS_M_ADDITION_S32(temp_s32, input);
        }
    }

    *acv_ptr = activation;
    linear_filter_ptr->previous_activation = activation;
    linear_filter_ptr->previous_retrigger = retrigger;
    linear_filter_ptr->previous_input_choice = sel;
    linear_filter_ptr->previous_compar_time = compar_time;
    linear_filter_ptr->previous_switch_result = switch_result;
    linear_filter_ptr->previous_integ_output = integ_output;
    linear_filter_ptr->previous_filtered_out = output_result;

    return (output_result);
}


/*******************************************************************************
*  Macro name:  DDS_M_LINEAR_FILTER_S32_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  DDS_M_LINEAR_FILTER_S32.
*
*  With characteristics:
*   linear_filter_ptr is the structure associated to macro
*   acv_ptr pointer to a activation flag
*   sel is the input selector
*   in1 is the 1st input
*   in2 is the 2nd input
*   current_time is the current time
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_LINEAR_FILTER_S32_INIT(
        CONSTP2VAR(t_dds_m_linear_filter_s32, AUTOMATIC, AUTOMATIC) linear_filter_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8 sel,
        sint32 in1,
        sint32 in2,
        uint32 current_time)
{
    sint32 output;

    *acv_ptr = DDS_FALSE;
    linear_filter_ptr->previous_activation = DDS_FALSE;   /* Boolean */
    linear_filter_ptr->previous_retrigger = DDS_FALSE;    /* Boolean */
    linear_filter_ptr->previous_input_choice = sel;  /* Boolean */
    linear_filter_ptr->previous_compar_time = DDS_FALSE;
    if ((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)sel)
    {
        output = in1;
        linear_filter_ptr->previous_filtered_out = in1;
    }
    else
    {
        output = in2;
        linear_filter_ptr->previous_filtered_out = in2;
    }
    linear_filter_ptr->previous_switch_result = 0;
    linear_filter_ptr->previous_integ_output = 0;
    linear_filter_ptr->chrono_start_time = current_time;

    return (output);
}




/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_INC_RATIO
*
*  Description :
*  This function is an internal tool to manage the ratio / error of a soft
*  transition ramp.
*
*  With characteristics:
*  delta_time and transition_duration are U32
*  ratio is uint16 : 0 to DDS_M_SOFT_TRANS_RATIO_BIN
*  error is store i, U32
*
*******************************************************************************/
static FUNC(uint16, AUTOMATIC) DDS_M_SOFT_TRANS_INC_RATIO(uint32 delta_time,
                       uint32 transition_duration,
                       uint16 ratio,
                       CONSTP2VAR (uint32, AUTOMATIC, AUTOMATIC) error_ptr,
                       CONSTP2VAR (uint16, AUTOMATIC, AUTOMATIC) error_shift_ptr)
{
    uint32 ratio_offst_numerator;
    uint32 ratio_offset;
    uint32 ratio_tmp;

    t_dds_m_uint nb_shift;
    uint32 delta_shift;
    uint32 trans_dur_shift;
    uint32 error_offset;

    if(delta_time  >= transition_duration)
    {
        *error_ptr          = 0;
        *error_shift_ptr    = 0;
        ratio               = 1 * DDS_M_SOFT_TRANS_RATIO_BIN;
    }
    else
    {
        delta_shift     = delta_time;
        trans_dur_shift = transition_duration;
        nb_shift        = 0;

        while(delta_shift > DDS_M_SOFT_TRANS_DELTA_MAX)
        {
            delta_shift     = delta_shift >> 1;
            trans_dur_shift = trans_dur_shift >> 1;
            nb_shift++;
        }

        ratio_offst_numerator = delta_shift * DDS_M_SOFT_TRANS_RATIO_BIN;

        /* Add prev error */
        if(nb_shift == (t_dds_m_uint)*error_shift_ptr)
        {
            error_offset = *error_ptr;
        }
        else if(nb_shift > (t_dds_m_uint)*error_shift_ptr)
        {
            error_offset = *error_ptr >> (nb_shift - (t_dds_m_uint)*error_shift_ptr);
        }
        else /* nb_shift < *error_shift_ptr */
        {
            /* No overflow possible beacuse  :
               *error_ptr < BIN16
               0 <= *error_shift_ptr <= 16
               0 <= nb_shift <= 16 */
            error_offset = *error_ptr << ((t_dds_m_uint)*error_shift_ptr - nb_shift);
        }

        if(ratio_offst_numerator < (DDS_UINT32_MAX - error_offset))
        {
            ratio_offst_numerator += error_offset;
        }
        else
        {
            ratio_offst_numerator = DDS_UINT32_MAX;
        }
/* <PRQA_COMMENT><2834> It is the responsability of the caller to not set a null value for "transition_duration"
                        and "delta_time" (which is absolutely incoherent). </2834></PRQA_COMMENT> */
        ratio_offset = ratio_offst_numerator / trans_dur_shift;
        /* 0 <= ratio_offset <= (2 * DDS_M_SOFT_TRANS_RATIO_BIN) */

        /* can use % because terms a >= 0 */
/* <PRQA_COMMENT><2834> It is the responsability of the caller to not set a null value for "transition_duration"
                        and "delta_time" (which is absolutely incoherent). </2834></PRQA_COMMENT> */
        *error_ptr = ratio_offst_numerator % trans_dur_shift;
        *error_shift_ptr = (uint16)nb_shift;


        ratio_tmp = (uint32)ratio + ratio_offset;

        ratio = (uint16)DDS_M_MIN(ratio_tmp,DDS_M_SOFT_TRANS_RATIO_BIN);
    }

    return(ratio);
}



/*******************************************************************************
*  Macro name:  DDS_M_FILTER_HYST_S16
*
*  Description :
*  The following macro allows to apply an hysteresis or a set to the input "inp_hyst".
*  The output "out_hyst" is forced between the two values (inp_hyst - tol_pos) and (inp_hyst + tol_neg),
*  When the input "activ" is set to TRUE (TRUE = 1, FALSE = 0) the application of the hysteresis is active,
*  if not the output "out_hyst" is equal to the input "inp_hyst".
*
*  With characteristics:
*   filter_hyst_ptr is the structure associated to macro
*   inp_hyst is the input
*   tol_pos is the positive hysteresis
*   tol_neg is the negative hysteresis
*   activ is the activation
*
*  Remark:
*   tol_pos and tol_neg must be positive
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_HYST_S16(
                CONSTP2VAR(t_dds_m_filter_hyst_s16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                sint16 inp_hyst,
                uint16 tol_pos,
                uint16 tol_neg,
                uint8 activ)
{
    sint32 temp_1;
    sint32 temp_2;
    sint32 temp_3;

    if((uint32)DDS_FALSE == (uint32)activ)
    {
        filter_hyst_ptr->previous_output = inp_hyst;
    }
    else
    {
        /* [-65538; 65534] = [-32768; 32767] + [-32768; 32767] */
        temp_1 = (sint32)inp_hyst + (sint32)tol_neg;
        /* [-65538; 32767] = MIN([-32768; 32767],  [-65538; 65534]) */
        temp_2 = DDS_M_MIN((sint32)(filter_hyst_ptr->previous_output) , temp_1);
        /* [-65535; 65535] = [-32768; 32767] - [-32768; 32767] */
        temp_1 = (sint32)inp_hyst - (sint32)tol_pos;
        /* [-65535; 65535] = MAX([-65538; 32767],  [-65535; 65535]) */
        temp_3 = DDS_M_MAX(temp_2, temp_1);
/* <PRQA_COMMENT><2996> limitation for security </2996></PRQA_COMMENT> */
        filter_hyst_ptr->previous_output = (sint16)DDS_M_LIMIT(temp_3,
                                                                DDS_SINT16_MIN,
                                                                DDS_SINT16_MAX);
    }
    return(filter_hyst_ptr->previous_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_HYST_S16_INIT
*
*  Description :
*  The following macro manage init of DDS_M_FILTER_HYST_S16 macro
*
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of hysteresis
*   hyst_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_HYST_S16_INIT (
                                CONSTP2VAR(t_dds_m_filter_hyst_s16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                                sint16 init_value)
{
    filter_hyst_ptr->previous_output = init_value;
    return(init_value);
}



/*******************************************************************************
*  Macro name:  DDS_M_FILTER_HYST_U16
*
*  Description :
*  The following macro allows to apply an hysteresis or a set to the input "inp_hyst".
*  The output "out_hyst" is forced between the two values (inp_hyst - tol_pos) and (inp_hyst + tol_neg),
*  When the input "activ" is set to TRUE (TRUE = 1, FALSE = 0) the application of the hysteresis is active,
*  if not the output "out_hyst" is equal to the input "inp_hyst".
*
*  With characteristics:
*   filter_hyst_ptr is the structure associated to macro
*   inp_hyst is the input
*   tol_pos is the positive hysteresis
*   tol_neg is the negative hysteresis
*   activ is the activation
*
*  Remark:
*   tol_pos and tol_neg must be positive
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_FILTER_HYST_U16(
                CONSTP2VAR(t_dds_m_filter_hyst_u16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                uint16 inp_hyst,
                uint16 tol_pos,
                uint16 tol_neg,
                uint8 activ)
{
    sint32 temp_1;
    sint32 temp_2;

    if((uint32)DDS_FALSE == (uint32)activ)
    {
        filter_hyst_ptr->previous_output = inp_hyst;
    }
    else
    {
        /* [0; 131070] = [0; 65535] + [0; 65535] */
        temp_1 = (sint32)inp_hyst + (sint32)tol_neg;
        /* [0; 65535] = MIN([0; 65535], [0; 131070]) */
        temp_2 = DDS_M_MIN((sint32)(filter_hyst_ptr->previous_output) , temp_1);
        /* [-65535; 65535] = [0; 65535] -  [0; 65535] */
        temp_1 = (sint32)inp_hyst - (sint32)tol_pos;
        /* [0; 65535] = MAX([0; 65535] , [-65535; 65535]) */
        filter_hyst_ptr->previous_output = (uint16)DDS_M_MAX(temp_2, temp_1);
    }
    return(filter_hyst_ptr->previous_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_HYST_U16_INIT
*
*  Description :
*  The following macro manage init of DDS_M_FILTER_HYST_S16 macro
*
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of hysteresis
*   hyst_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_FILTER_HYST_U16_INIT (
                                CONSTP2VAR(t_dds_m_filter_hyst_u16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                                uint16 init_value)
{
    filter_hyst_ptr->previous_output = init_value;
    return(init_value);
}



/*******************************************************************************
*  Macro name:  DDS_M_FILTER_HYST_S32
*
*  Description :
*  The following macro allows to apply an hysteresis or a set to the input "inp_hyst".
*  The output "out_hyst" is forced between the two values (inp_hyst - tol_pos) and (inp_hyst + tol_neg),
*  When the input "activ" is set to TRUE (TRUE = 1, FALSE = 0) the application of the hysteresis is active,
*  if not the output "out_hyst" is equal to the input "inp_hyst".
*
*  With characteristics:
*   filter_hyst_ptr is the structure associated to macro
*   inp_hyst is the input
*   tol_pos is the positive hysteresis
*   tol_neg is the negative hysteresis
*   activ is the activation
*
*  Remark:
*   tol_pos and tol_neg must be positive
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_FILTER_HYST_S32(
                CONSTP2VAR(t_dds_m_filter_hyst_s32, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                sint32 inp_hyst,
                uint32 tol_pos,
                uint32 tol_neg,
                uint8 activ)
{
    sint32 out_min;
    sint32 out_add;
    sint32 out_sub;

    if((uint32)DDS_FALSE == (uint32)activ)
    {
        filter_hyst_ptr->previous_output = inp_hyst;
    }
    else
    {
        /* To compare U32 and S32 */
        if (inp_hyst >= 0)
        {
            /* Evalutate MIN output */
            if (tol_neg > ((uint32)DDS_SINT32_MAX - (uint32)inp_hyst))
            {
                out_min = filter_hyst_ptr->previous_output;
            }
            else
            {
                out_add = (sint32)tol_neg + inp_hyst;
                out_min = DDS_M_MIN(out_add, filter_hyst_ptr->previous_output);
            }

            /* Evalutate substraction output */
            if (tol_pos >= (((uint32)DDS_SINT32_MAX + (uint32)1) + (uint32)inp_hyst))
            {
                out_sub = DDS_SINT32_MIN_FULL;
            }
            else
            {
                out_sub = inp_hyst - (sint32)tol_pos;
            }
        }
        else
        {
            /* Evalutate MIN output */
            if (tol_neg > ((uint32)DDS_SINT32_MAX + (uint32)(-inp_hyst)))
            {
                out_min = filter_hyst_ptr->previous_output;
            }
            else
            {
                out_add = (sint32)tol_neg + inp_hyst;
                out_min = DDS_M_MIN(out_add, filter_hyst_ptr->previous_output);
            }

            /* Evalutate substraction output */
            if (tol_pos >= (((uint32)DDS_SINT32_MAX + (uint32)1) - (uint32)(-inp_hyst)))
            {
                out_sub = DDS_SINT32_MIN_FULL;
            }
            else
            {
                out_sub = inp_hyst - (sint32)tol_pos;
            }
        }

        filter_hyst_ptr->previous_output = DDS_M_MAX(out_sub, out_min);
    }
    return(filter_hyst_ptr->previous_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_HYST_S32_INIT
*
*  Description :
*  The following macro manage init of DDS_M_FILTER_HYST_S16 macro
*
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of hysteresis
*   hyst_struct_ptr is the structure associated to macro
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_FILTER_HYST_S32_INIT (
                                CONSTP2VAR(t_dds_m_filter_hyst_s32, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                                sint32 init_value)
{
    filter_hyst_ptr->previous_output = init_value;
    return(init_value);
}



/*******************************************************************************
*  Function name:  DDS_M_FILTER_LP1_ASSYM_S16
*
*  Description :
*  The following fucntion apply a low pass 1st order filter to the input
*
*  result = previous_output + (target - previous_output)*filter_factor
*                                    / bp_filter_factor
*  previous_error = (target - previous_output) * filter_factor % bp_filter_factor
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   target is the input signal
*   filter_factor is : - positive_factor if target > previous_output
*                      - negative_factor if target <= previous_output
*   bp_filter_factor is binary point of positive_factor and negative_factor
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_FILTER_LP1_ASSYM_S16_INIT
*   it is assume that bp_filter_factor is different from zero
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_ASSYM_S16(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                     sint16 target,
                                                     uint16 positive_factor,
                                                     uint16 negative_factor,
                                                     uint16 bp_filter_factor)
{
    sint16 filtered_value;

    if( ( (sint32)target - (sint32)(filter_struct_ptr->previous_output.prev_S16) ) > (sint32)0 )
    {
        filtered_value = DDS_M_FILTER_LP1_S16(filter_struct_ptr,
                                              target,
                                              positive_factor,
                                              bp_filter_factor);
    }
    else
    {
        filtered_value = DDS_M_FILTER_LP1_S16(filter_struct_ptr,
                                              target,
                                              negative_factor,
                                              bp_filter_factor);
    }
    return filtered_value;
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_LP1_ASSYM_S16_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_FILTER_LP1_ASSYM_S16
*
*  previous_output = init_value
*  previous_error = 0
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   init_value is the init value
*
*  REMARKS:
*   This macro should be used each time a new filter order is launched with
*   DDS_M_FILTER_LP1_ASSYM_S16
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_ASSYM_S16_INIT(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                        sint16 init_value)
{
    filter_struct_ptr->previous_output.prev_S16 = init_value ;
    filter_struct_ptr->previous_error= 0 ;

    return(init_value);
}


/*******************************************************************************
*  Macro name:  DDS_M_ADAP_TRAN_TEMP_BLOC_S32
*
*  Description :
*
*
*
*  With characteristics:
*   block_ptr is the structure associated to macro
*   acv_ptr pointer to a activation flag
*   sel is the input selector
*   in1 is the 1st input
*   in2 is the 2nd input
*   tr is the transition time
*   inh is the inhibit function command
*   te is the sampling period
* in_out_bin_number is the shift number of input and output of the macro
*
* To be noted: tr and te should have the same bin-point
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_ADAP_TRAN_TEMP_BLOC_S32(
        CONSTP2VAR(t_dds_m_adapt_trans_tempo_s32, AUTOMATIC, AUTOMATIC) block_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8  sel,
        sint32 in1,
        sint32 in2,
        uint32 tr,
        uint8  inh,
        uint32 te,
        sint8  in_out_bin_number)
{
  t_dds_m_uint  front_sel;
  sint8  nb_shift;
  uint32 rate_limit_input;
  uint8  output_flip;
  sint32 sub_input;
  sint32 mult_tmp;
  uint32 rate_limiter_output;
  sint32 output_result;
  uint32 sum_te_tr;
  uint32 inc;
  uint32 pente_2;
  uint32 ref_pente;

  /* protect the future division */
  te = DDS_M_MAX(te, 1);

  front_sel = (t_dds_m_uint)DDS_M_EDGE_DETECT(&(block_ptr->m_sel_edge_str), sel);

    /* flip flop */
    if((t_dds_m_uint)DDS_TRUE != (t_dds_m_uint)block_ptr->acv_prev)
    {
        output_flip = DDS_FALSE;
    }
    else if((t_dds_m_uint)DDS_M_NO_EDGE_DETECTED != front_sel)
    {
        output_flip = DDS_TRUE;
    }
    else
    {
        output_flip = block_ptr->output_flip_prev;
    }
    block_ptr->output_flip_prev = output_flip;

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)sel)
    {
        block_ptr->in1_raw = in1;
        rate_limit_input = (uint32)(1 * BIN30);
    }
    else
    {
        block_ptr->in2_raw = in2;
        rate_limit_input = (uint32)(0 * BIN30);
    }

    if((t_dds_m_uint)DDS_M_NO_EDGE_DETECTED != front_sel)
    {
        pente_2 = block_ptr->pente_1_prev;
    }
    else
    {
        pente_2 = block_ptr->pente_2_prev;
    }

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)output_flip)
    {
        ref_pente = pente_2;
    }
    else
    {
        ref_pente = (uint32)1 * BIN30;
    }

    /* BIN30 = (BIN30 * BINxx) / BINxx */
    /* inc = ((ref_pente * te ) / (tr + te)) */
    sum_te_tr = DDS_M_ADDITION_U32(tr, te);
/* <PRQA_COMMENT><2834> sum_te_tr != 0 because te > 0 and tr >= 0</2834></PRQA_COMMENT> */
    inc = ((ref_pente / sum_te_tr) * te) + (((ref_pente % sum_te_tr) * te) / sum_te_tr);

    /* enable */
    if(((t_dds_m_uint)DDS_FALSE == (t_dds_m_uint)inh) && (0 != tr))
    {
        /* RATE_LIMITER */
        rate_limiter_output = DDS_M_SLEW_U32( &(block_ptr->m_slew_str),
                                              rate_limit_input,
                                              (inc),
                                              (inc));
    }
    else
    {
        /* RATE_LIMITER_INIT */
        rate_limiter_output = DDS_M_SLEW_U32_INIT( &(block_ptr->m_slew_str),
                                                   rate_limit_input);
    }


    if(((1 * BIN30) > rate_limiter_output) && (0 < rate_limiter_output))
    {
        *acv_ptr = DDS_TRUE;
    }
    else
    {
        *acv_ptr = DDS_FALSE;
    }

    /* Dynamic Bary filter calculation */
    /* Out = Rate * IN1 + (1 - Rate) * In2 */
    /* Out = Rate * (IN1 - In2) + In2 */
    nb_shift = (sint8)(30 + (uint32)in_out_bin_number);
    sub_input = DDS_M_ADDITION_S32(block_ptr->in1_raw, (-1 * block_ptr->in2_raw));

    /* rate_limiter_output is limited between 0 and 1; BIN30*/
    mult_tmp = DDS_M_DYNAMIC_MULT_S32((sint32)rate_limiter_output, sub_input, &nb_shift);
    output_result = DDS_M_RESTORE_BINPOINT_SINT32(mult_tmp, (sint8)((sint32)nb_shift - (sint32)in_out_bin_number));
    output_result = output_result + block_ptr->in2_raw;

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)sel)
    {
        block_ptr->pente_1_prev = rate_limiter_output;
    }
    else
    {

        block_ptr->pente_1_prev = (uint32)(1 * BIN30) - rate_limiter_output;
    }

    block_ptr->acv_prev = *acv_ptr;
    block_ptr->pente_2_prev = pente_2;

    return (output_result);
}


/*******************************************************************************
*  Macro name:  DDS_M_ADAP_TRAN_TEMP_BLOC_S32_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  DDS_M_ADAP_TRAN_TEMP_BLOC_S32.
*
*  With characteristics:
*   linear_filter_ptr is the structure associated to macro
*   acv_ptr pointer to a activation flag
*   sel
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_ADAP_TRAN_TEMP_BLOC_S32_INIT(
        CONSTP2VAR(t_dds_m_adapt_trans_tempo_s32, AUTOMATIC, AUTOMATIC) block_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8 sel)
{
    sint32 rate_limit_input;

    *acv_ptr = DDS_FALSE;

    block_ptr->pente_1_prev = (uint32)(1 * BIN30);
    block_ptr->pente_2_prev = (uint32)(1 * BIN30);
    block_ptr->acv_prev = DDS_FALSE;
    block_ptr->output_flip_prev = DDS_FALSE;
    block_ptr->in1_raw = 0;
    block_ptr->in2_raw = 0;

    if((t_dds_m_uint)DDS_TRUE == (t_dds_m_uint)sel)
    {
        rate_limit_input = 1 * BIN30;
    }
    else
    {
        rate_limit_input = 0;
    }

    (void)DDS_M_SLEW_S32_INIT(&(block_ptr->m_slew_str),
                              rate_limit_input);

    (void)DDS_M_EDGE_DETECT_INIT(&(block_ptr->m_sel_edge_str),
                                 sel);
    return ((sint32)0);
}

/*******************************************************************************
*  Function name:  DDS_M_FILTER_LP1_S32
*
*  Description :
*  The following function apply a low pass 1st order filter to the input
*
*  result = previous_output + (target - previous_output)*filter_factor
*                                    / bp_filter_factor
*  previous_error = (target - previous_output) * filter_factor % bp_filter_factor
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   target is the input signal
*   filter_factor is the attenuation factor. BIN15 precision is required for it.
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_FILTER_LP1_S32_INIT
*   it is assume that filter_factor has a BIN15 precision.
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_FILTER_LP1_S32(CONSTP2VAR(t_dds_m_filter_lp1_s32, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             sint32 target,
                                             uint16 filter_factor)
{

    sint32 temp;
    sint32 delta;

  temp = (target/BIN1) - (filter_struct_ptr->previous_output.prev_S32/BIN1);

  if( ( temp >= ((-DDS_SINT32_MAX/2)+2) ) &&
    ( temp <= ((DDS_SINT32_MAX/2)-2) ) )
  {
    delta = target - filter_struct_ptr->previous_output.prev_S32;
    /* (delta * filter_factor + err)/BIN15 =
    (delta/bin15)*filter_factor + ((delta%BIN15)*filter_factor + err)/BIN15 */

    if(delta >= 0)
    {   /* %BIN15 = &(BIN15-1) for pos val */
/* <PRQA_COMMENT><4130><4532> No functionnal problem the bitwise operation is done on positive value </4532></4130></PRQA_COMMENT> */
      temp = ( (delta & (BIN15-1)) * ((sint32)(filter_factor)) ) +
                  (filter_struct_ptr->previous_error);
    }
    else
    {
/* <PRQA_COMMENT><4130><4532> No functionnal problem the bitwise operation is done on positive value </4532></4130></PRQA_COMMENT> */
      temp = ( -((-delta) & (BIN15-1)) * ((sint32)(filter_factor)) ) +
                  (filter_struct_ptr->previous_error);
    }
    if(temp >= 0)
    {   /* %BIN15 = &(BIN15-1) for pos val */
/* <PRQA_COMMENT><4130><4532> No functionnal problem the bitwise operation is done on positive value </4532></4130></PRQA_COMMENT> */
      filter_struct_ptr->previous_error = temp & (BIN15 - 1); /* error calculation */
    }
    else
    {
/* <PRQA_COMMENT><4130><4532> No functionnal problem the bitwise operation is done on positive value </4532></4130></PRQA_COMMENT> */
      filter_struct_ptr->previous_error = -((-temp) & (BIN15 - 1));
    }
    filter_struct_ptr->previous_output.prev_S32 += (temp / BIN15) +
        ((delta/BIN15) * (sint32)(filter_factor));
  }
  else
  {
    /* in this case, we decrease resolution but the error will be
    very small because value is large */
    /* NBIN15 = NBIN1/BIN14 */
    delta = temp/BIN14; /* With (DDS_UINT32_MAX/2) >ABS(delta) > (SInt32_MAX/2 - 2) */

    if(BIN14 >= (sint32)filter_factor)
    {
      /* BIN0 = NBIN15 * BIN15 */
      temp = delta * (sint32)(filter_factor);
      filter_struct_ptr->previous_error = 0; /* error calculation */

      filter_struct_ptr->previous_output.prev_S32 += temp;
    }
    else
    {
      /* NBIN1 = NBIN15 * (BIN15/BIN1) */
      temp = delta * ((sint32)filter_factor / BIN1);
      filter_struct_ptr->previous_error = 0; /* error calculation */

      /* NBIN1 += BIN0/BIN1 */
      temp += (filter_struct_ptr->previous_output.prev_S32/BIN1);

      /* BIN0 = NBIN1 * BIN1 */
      filter_struct_ptr->previous_output.prev_S32 = temp*BIN1;
    }
  }

    return filter_struct_ptr->previous_output.prev_S32; /* Return output */
}


/*******************************************************************************
*  Macro name:  DDS_M_FILTER_LP1_S32_INIT
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_FILTER_LP1_S32
*
*  previous_output = init_value
*  previous_error = 0
*
*  Where:
*   filter_struct_ptr is the structure associated to macro
*   init_value is the init value
*
*  REMARKS:
*   This macro should be used each time a new filter order is launched with
*   DDS_M_FILTER_LP1_S32
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_FILTER_LP1_S32_INIT(CONSTP2VAR(t_dds_m_filter_lp1_s32, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                  sint32 init_value)
{
    filter_struct_ptr->previous_output.prev_S32 = init_value ;
    filter_struct_ptr->previous_error           = 0 ;

    return(init_value);
}

/*******************************************************************************
*  Macro name:  DDS_M_MEM_EXTINI_U16
*
*  Description :
*  The following macro manage external memorisation of prev value
*
*
*  output = init_value
*  previous_ouput = output or in (depend on hld value)
*
*  Where:
*   t_dds_m_mem_extini_u16 is the structure associated to macro
*   init_value is the init value
*
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC)  DDS_M_MEM_EXTINI_U16(
                            CONSTP2VAR(t_dds_m_mem_extini_16, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint16 in_value,
                            uint8 hld_sel)
{
    uint16 tmp_output = mem_struct_ptr->previous_output.prev_U16;

    if(0 == (uint32)hld_sel)
    {
        mem_struct_ptr->previous_output.prev_U16    = in_value;
    }
    else
    {
        mem_struct_ptr->previous_output.prev_U16    = tmp_output;
    }

    return (tmp_output);
}

/*******************************************************************************
*  Macro name:  DDS_M_MEM_EXTINI_U16_INIT
*
*  Description :
*  The following macro manage initialization before starting  DDS_M_MEM_EXTINI_U16
*
*
*  output = init_value
*  previous_ouput = output or in (depend on hld value)
*
*  Where:
*   t_dds_m_mem_extini_u16 is the structure associated to macro
*   init_value is the init value
*
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC)  DDS_M_MEM_EXTINI_U16_INIT(
                            CONSTP2VAR(t_dds_m_mem_extini_16, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint16 init_value,
                            uint16 in_value,
                            uint8 hld_sel)
{
    uint16 tmp_output = init_value;

    if(0 == (uint32)hld_sel)
    {
        mem_struct_ptr->previous_output.prev_U16    = in_value;
    }
    else
    {
        mem_struct_ptr->previous_output.prev_U16    = tmp_output;
    }

    return (tmp_output);
}


/*******************************************************************************
*  Macro name:  DDS_M_MEM_EXTINI_U32
*
*  Description :
*  The following macro manage external memorisation of prev value
*
*
*  output = init_value
*  previous_ouput = output or in (depend on hld value)
*
*  Where:
*   t_dds_m_mem_extini_u32 is the structure associated to macro
*   init_value is the init value
*
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC)  DDS_M_MEM_EXTINI_U32(
                            CONSTP2VAR(t_dds_m_mem_extini_32, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint32 in_value,
                            uint8 hld_sel)
{
    uint32 tmp_output = mem_struct_ptr->previous_output.prev_U32;

    if(0 == (uint32)hld_sel)
    {
        mem_struct_ptr->previous_output.prev_U32    = in_value;
    }
    else
    {
        mem_struct_ptr->previous_output.prev_U32    = tmp_output;
    }

    return (tmp_output);
}

/*******************************************************************************
*  Macro name:  DDS_M_MEM_EXTINI_U32_INIT
*
*  Description :
*  The following macro manage initialization before starting  DDS_M_MEM_EXTINI_U32
*
*
*  output = init_value
*  previous_ouput = output or in (depend on hld value)
*
*  Where:
*   t_dds_m_mem_extini_u32 is the structure associated to macro
*   init_value is the init value
*
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC)  DDS_M_MEM_EXTINI_U32_INIT(
                            CONSTP2VAR(t_dds_m_mem_extini_32, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint32 init_value,
                            uint32 in_value,
                            uint8 hld_sel)
{
    uint32 tmp_output = init_value;

    if(0 == (uint32)hld_sel)
    {
        mem_struct_ptr->previous_output.prev_U32    = in_value;
    }
    else
    {
        mem_struct_ptr->previous_output.prev_U32    = tmp_output;
    }

    return (tmp_output);
}

/*******************************************************************************
*  Function name:  DDS_M_2ND_ORDER_FILTER_S16
*
*  Diagram symbol glossary ref : 2nd_Order_Filter
*
*  Description :
*  The following fucntion apply a stop band filter to the input.
*   Output = ((b2_factor * input) + (b1_factor * input_prev) + (b0_factor * input_prev_prev)
*           - (a1_factor * output_prev) - (a0_factor * output_prev_prev)) / a2_factor
*
*   The transfert function is
*   H(z) = (b2 + b1.Z^(-1) + b0.Z^(-2)) / (a2 + a1.Z^(-1) + a0.Z^(-2))
*
*  Where:
*   input is the input signal
*
*   a1_factor, a2_factor, b0_factor, b1_factor, b2_factor are a1, a2, b0, b1, b2
*   factor of the transfert function
*   a1_scaler = BIN_a1_factor
*   a2_scaler = BIN_a2_factor
*   b0_scaler = BIN_b0_factor + BIN_input - BIN_output
*   b1_scaler = BIN_b1_factor + BIN_input - BIN_output
*   b2_scaler = BIN_b2_factor + BIN_input - BIN_output
*
*   filter_struct_ptr is the structure associated to the macro
*
*  REMARKS:
*   user is in charge reset the filter before first use by using macro
*   DDS_M_2ND_ORDER_FILTER_S16_INIT
*
*******************************************************************************/
sint32 DDS_M_2ND_ORDER_FILTER_S16 (
                            sint16 input,
                            sint16 a0_factor,
                            sint16 a1_factor,
                            sint16 a2_factor,
                            sint16 b0_factor,
                            sint16 b1_factor,
                            sint16 b2_factor,
                            uint16 a0_scaler, /* = BIN(a0_factor) */
                            uint16 a1_scaler, /* = BIN(a1_factor) */
                            uint16 a2_scaler, /* = BIN(a2_factor) */
                            uint16 b0_scaler, /* = BIN(b0_factor) + BIN(input) - BIN(output) */
                            uint16 b1_scaler, /* = BIN(b1_factor) + BIN(input) - BIN(output) */
                            uint16 b2_scaler, /* = BIN(b2_factor) + BIN(input) - BIN(output) */
                            t_dds_m_2nd_order_filter_s16 *filter_struct_ptr)
{
    sint32 sum;
    sint32 tab_term[DDS_2ND_ORDER_FILTER_S16_TAB_TERM_SIZE_5];
    sint32 b0_filter_term_temp;
    sint32 b1_filter_term_temp;
    sint32 b2_filter_term_temp;
    sint32 a0_filter_term_temp;
    sint32 a1_filter_term_temp;
    sint32 a2_filter_term_temp;
    sint32 tmp_s32;
    sint32 prev_out_abs;
    sint32 tab_term_tmp;
    sint32 out_div_scaler;
    sint32 abs_factor_thr;
    sint32 ax_factor_abs;
    sint32 nb_term;
    sint32 i;

    sint32 temp_div;
    sint32 signe;
    uint32 add_diff_sign_done;

    /*************************************************************************/
    /* Input coefficient calcualtion ........................................*/
    /* filter_term = b_factor * input / scaler...............................*/
    /* sint32 = sint16 * sint16 / sint16 ....................................*/
    /*************************************************************************/
    /* b0_filter_term_calculation */
    b0_filter_term_temp = (sint32)b0_factor * (sint32)filter_struct_ptr->previous_input_2;
/* <PRQA_COMMENT><3226><3109><3138>
It is the responsability of the caller to not set a null value for "b2_scaler".
</3138></3109></3226></PRQA_COMMENT> */
    tab_term[0] = DDS_M_OUT_SCALED_CALC(b0_filter_term_temp,(sint32)b0_scaler,filter_struct_ptr->b0_error,tmp_s32);


    /* b1_filter_term_calculation */
    b1_filter_term_temp = (sint32)b1_factor * (sint32)filter_struct_ptr->previous_input_1;
/* <PRQA_COMMENT><3226><3109><3138>
It is the responsability of the caller to not set a null value for "b2_scaler".
</3138></3109></3226></PRQA_COMMENT> */
    tab_term[1] = DDS_M_OUT_SCALED_CALC(b1_filter_term_temp,(sint32)b1_scaler,filter_struct_ptr->b1_error,tmp_s32);


    /* b2_filter_term_calculation */
    b2_filter_term_temp = (sint32)b2_factor * (sint32)input;
/* <PRQA_COMMENT><3226><3109><3138>
It is the responsability of the caller to not set a null value for "b2_scaler".
</3138></3109></3226></PRQA_COMMENT> */
    tab_term[2] = DDS_M_OUT_SCALED_CALC(b2_filter_term_temp,(sint32)b2_scaler,filter_struct_ptr->b2_error,tmp_s32);


    /*************************************************************************/
    /* Output coefficient calcualtion ........................................*/
    /* filter_term = a_factor * output / scaler...............................*/
    /* sint32 = sint16 * sint16 / sint16 .....................................*/
    /*************************************************************************/


    /* a0_filter_term_calculation */
    if(filter_struct_ptr->previous_output_2 < 0)
    {
        prev_out_abs     = -filter_struct_ptr->previous_output_2;
        signe = -1;
    }
    else
    {
        prev_out_abs     = filter_struct_ptr->previous_output_2;
        signe = 1;
    }

    if((sint32)a0_factor < 0)
    {
        ax_factor_abs   = -(sint32)a0_factor;
        signe = -signe;
    }
    else
    {
        ax_factor_abs   = (sint32)a0_factor;
    }

    /* In normal case, -2 <= a0_factor <= 2 */
    if(0 != (uint32)ax_factor_abs)
    {
        abs_factor_thr = DDS_SINT32_MAX/ax_factor_abs;

        if(prev_out_abs < abs_factor_thr)
        {
            a0_filter_term_temp = (sint32)a0_factor * filter_struct_ptr->previous_output_2;
/* <PRQA_COMMENT><3220><3226><3109><3138><3430>
Do not touch the current implementation to avoid regression (very sensitive library function strongly validated).
</3430></3138></3109></3226></3220></PRQA_COMMENT> */
            DDS_M_OUT_SCALED_CALC_PROT_S32(tab_term[4],a0_filter_term_temp,(sint32)a0_scaler,filter_struct_ptr->a0_error);
        }
        else
        {
            out_div_scaler = prev_out_abs/(sint32)a0_scaler;

            if(out_div_scaler <= abs_factor_thr)
            {
                if(filter_struct_ptr->previous_output_2 >= 0)
                {
                    tmp_s32 = ((filter_struct_ptr->previous_output_2 % (sint32)a0_scaler)*(sint32)a0_factor) + filter_struct_ptr->a0_error;
                }
                else
                {
                    tmp_s32 = (((-filter_struct_ptr->previous_output_2) % (sint32)a0_scaler)*(sint32)a0_factor) - filter_struct_ptr->a0_error;
                    tmp_s32 = -tmp_s32;
                }

                tab_term_tmp = (out_div_scaler * ax_factor_abs) * signe;

                if(tmp_s32 >= 0)
                {
                    filter_struct_ptr->a0_error = tmp_s32 % (sint32)a0_scaler;
                    tmp_s32 /= (sint32)a0_scaler;

                    if(tab_term_tmp <= (DDS_SINT32_MAX - tmp_s32))
                    {
                        tab_term[4] = tab_term_tmp + tmp_s32;
                    }
                    else
                    {
                        tab_term[4] = DDS_SINT32_MAX;
                        filter_struct_ptr->a0_error = 0;
                    }
                }
                else
                {
                    filter_struct_ptr->a0_error = -((-tmp_s32) % (sint32)a0_scaler);
                    tmp_s32 /= (sint32)a0_scaler;

                    if(tab_term_tmp >= (-DDS_SINT32_MAX - tmp_s32))
                    {
                        tab_term[4] = tab_term_tmp + tmp_s32;
                    }
                    else
                    {
                        tab_term[4] = -DDS_SINT32_MAX;
                        filter_struct_ptr->a0_error = 0;
                    }
                }
            }
            else
            {
                tab_term[4] = signe * DDS_SINT32_MAX;
                filter_struct_ptr->a0_error = 0;
            }
        }
    }
    else
    {
        tab_term[4]                 = 0;
        filter_struct_ptr->a0_error = 0;
    }

    /* a1_filter_term_calculation */
    if(filter_struct_ptr->previous_output_1 < 0)
    {
        prev_out_abs     = -filter_struct_ptr->previous_output_1;
        signe = -1;
    }
    else
    {
        prev_out_abs     = filter_struct_ptr->previous_output_1;
        signe = 1;
    }

    if((sint32)a1_factor < 0)
    {
        ax_factor_abs   = -(sint32)a1_factor;
        signe = -signe;
    }
    else
    {
        ax_factor_abs   = a1_factor;
    }

    /* In normal case, -2 <= a1_factor <= 2 */
    if(0 != ax_factor_abs)
    {
        abs_factor_thr = DDS_SINT32_MAX/ax_factor_abs;

        if(prev_out_abs < abs_factor_thr)
        {
            a1_filter_term_temp = (sint32)a1_factor * filter_struct_ptr->previous_output_1;
/* <PRQA_COMMENT><3220><3226><3109><3138><3430>
Do not touch the current implementation to avoid regression (very sensitive library function strongly validated).
</3430></3138></3109></3226></3220></PRQA_COMMENT> */
            DDS_M_OUT_SCALED_CALC_PROT_S32(tab_term[3],a1_filter_term_temp,(sint32)a1_scaler,filter_struct_ptr->a1_error);
        }
        else
        {
            out_div_scaler = prev_out_abs/(sint32)a1_scaler;

            if(out_div_scaler <= abs_factor_thr)
            {
                if(filter_struct_ptr->previous_output_1 >= 0)
                {
                    tmp_s32 = ((filter_struct_ptr->previous_output_1 % (sint32)a1_scaler)*(sint32)a1_factor)+ filter_struct_ptr->a1_error;
                }
                else
                {
                    tmp_s32 = (((-filter_struct_ptr->previous_output_1) % (sint32)a1_scaler)*(sint32)a1_factor)- filter_struct_ptr->a1_error;
                    tmp_s32 = -tmp_s32;
                }

                tab_term_tmp = (out_div_scaler * ax_factor_abs) * signe;

                if(tmp_s32 >= 0)
                {
                    filter_struct_ptr->a1_error = tmp_s32 % (sint32)a1_scaler;
                    tmp_s32 /= (sint32)a1_scaler;

                    if(tab_term_tmp <= (DDS_SINT32_MAX - tmp_s32))
                    {
                        tab_term[3] = tab_term_tmp + tmp_s32;
                    }
                    else
                    {
                        tab_term[3] = DDS_SINT32_MAX;
                        filter_struct_ptr->a1_error = 0;
                    }
                }
                else
                {
                    filter_struct_ptr->a1_error = -((-tmp_s32) % (sint32)a1_scaler);
                    tmp_s32 /= (sint32)a1_scaler;

                    if(tab_term_tmp >= (-DDS_SINT32_MAX - tmp_s32))
                    {
                        tab_term[3] = tab_term_tmp + tmp_s32;
                    }
                    else
                    {
                        tab_term[3] = -DDS_SINT32_MAX;
                        filter_struct_ptr->a1_error = 0;
                    }
                }

            }
            else
            {
                tab_term[3] = signe * DDS_SINT32_MAX;
                filter_struct_ptr->a1_error = 0;
            }
        }
    }
    else
    {
        tab_term[3]                 = 0;
        filter_struct_ptr->a1_error = 0;
    }

    /********************************************************************/
    /* Integral term calculation                                        */
    /* Use of a saved error to minimize the calculated error            */
    /********************************************************************/

    /* Add all term of different sign : B0 + B1 + B2 - A1 - A0 */

    nb_term = 5;
    tab_term[3] = -tab_term[3];
    tab_term[4] = -tab_term[4];

    do
    {
        add_diff_sign_done = (uint32)DDS_TRUE;

        i = nb_term - 2;
        while ((i >= 0) && (add_diff_sign_done == (uint32)DDS_TRUE))
        {
            if(  ((tab_term[i] >= 0) && (tab_term[nb_term-1] <= 0))
               ||((tab_term[i] <= 0) && (tab_term[nb_term-1] >= 0)))
            {
                tab_term[i] = tab_term[i] + tab_term[nb_term-1];
                nb_term--;
                add_diff_sign_done = (uint32)DDS_FALSE;
            }
            else
            {
                /* Do Nothing */
            }
            i--;
        }
    }
    while((uint32)DDS_FALSE == add_diff_sign_done);

    /* Add the term remaining (same sign) */
    sum = tab_term[nb_term-1];
    nb_term--;

    if(sum >= 0)
    {   /* Sum of positiv term */
        while(nb_term > 0)
        {
            if(tab_term[nb_term-1] <= (DDS_SINT32_MAX - sum))
            {
                sum += tab_term[nb_term-1];
                nb_term--;
            }
            else
            {
                sum = DDS_SINT32_MAX;
                nb_term = 0;    /* Exit loop */
            }
        }
    }
    else
    {   /* Sum of negativ term */
        while(nb_term > 0)
        {
            if(tab_term[nb_term-1] >= ((-DDS_SINT32_MAX) - sum))
            {
                sum += tab_term[nb_term-1];
                nb_term--;
            }
            else
            {
                sum = -DDS_SINT32_MAX;
                nb_term = 0;    /* Exit loop */
            }
        }
    }

    /********************************************************************/
    /* Division term calculation                                        */
    /********************************************************************/

    if (0 == sum)
    {
        temp_div = 0;
    }
    else if ((sint32)a2_factor == 0)
    {
        if(sum > 0)
        {
            temp_div = DDS_SINT32_MAX;
        }
        else
        {
            temp_div = DDS_SINT32_MIN;
        }
    }
    else
    {
        /* a2_filter_term_calculation */
        if(sum < 0)
        {
            prev_out_abs     = -sum;
            signe = -1;
        }
        else
        {
            prev_out_abs     = sum;
            signe = 1;
        }


        ax_factor_abs   = (sint32)a2_scaler;

        if(0 != (uint32)ax_factor_abs)
        {
            abs_factor_thr = DDS_SINT32_MAX/ax_factor_abs;

            if(prev_out_abs < abs_factor_thr)
            {
                a2_filter_term_temp = (sint32)a2_scaler * sum;
/* <PRQA_COMMENT><3220><3226><3109><3138><3430>
Do not touch the current implementation to avoid regression (very sensitive library function strongly validated).
</3430></3138></3109></3226></3220></PRQA_COMMENT> */
                DDS_M_OUT_SCALED_CALC_PROT_S32(temp_div,a2_filter_term_temp,(sint32)a2_factor,filter_struct_ptr->a2_error);
            }
            else
            {
                out_div_scaler = prev_out_abs/(sint32)a2_factor;

                if(out_div_scaler <= abs_factor_thr)
                {
                    if(sum >= 0)
                    {
                        tmp_s32 = ((sum % (sint32)a2_factor)*(sint32)a2_scaler) + filter_struct_ptr->a2_error;
                    }
                    else
                    {
                        tmp_s32 = (((-sum) % (sint32)a2_factor)*(sint32)a2_scaler) - filter_struct_ptr->a2_error;
                        tmp_s32 = -tmp_s32;
                    }

                    tab_term_tmp = (out_div_scaler * ax_factor_abs) * signe;

                    if(tmp_s32 >= 0)
                    {
                        filter_struct_ptr->a2_error = tmp_s32 % (sint32)a2_scaler;

                        tmp_s32 /= (sint32)a2_factor;

                        if(tab_term_tmp <= (DDS_SINT32_MAX - tmp_s32))
                        {
                            temp_div = tab_term_tmp + tmp_s32;
                        }
                        else
                        {
                            temp_div = DDS_SINT32_MAX;
                            filter_struct_ptr->a2_error = 0;
                        }

                    }
                    else
                    {
                        filter_struct_ptr->a2_error = -((-tmp_s32) % (sint32)a2_factor);

                        tmp_s32 /= (sint32)a2_scaler;

                        if(tab_term_tmp >= (-DDS_SINT32_MAX - tmp_s32))
                        {
                            temp_div = tab_term_tmp + tmp_s32;
                        }
                        else
                        {
                            temp_div = -DDS_SINT32_MAX;
                            filter_struct_ptr->a2_error = 0;
                        }
                    }
                }
                else
                {
                    temp_div = signe * DDS_SINT32_MAX;
                    filter_struct_ptr->a2_error = 0;
                }
            }
        }
        else
        {
            temp_div                    = 0;
            filter_struct_ptr->a2_error = 0;
        }

    }

    /********************************************************************/
    /* Allocate structure value ........................................*/
    /********************************************************************/
    /* Previous output allocation */
    filter_struct_ptr->previous_output_2 = filter_struct_ptr->previous_output_1;
    filter_struct_ptr->previous_output_1 = temp_div;

    /* Previous input allocation */
    filter_struct_ptr->previous_input_2 = filter_struct_ptr->previous_input_1;
    filter_struct_ptr->previous_input_1 = input;

    return (temp_div);
}

/*******************************************************************************
*  Macro name:  DDS_M_2ND_ORDER_FILTER_DIS_S16
*
*  Diagram symbol glossary ref : 2nd_Order_Filter
*
*  Description :
*  The following macro manage disable mode. The parameters are memorized and
*           the output is fixed by output_value
*
*  Where:
*  input value is the current input value and is memorize in previous_input_1
*           and then in previous_input_2
*  output value is the current output value and is memorize in previous_output_1
*           and then in previous_output_2
*   filter_struct_ptr is the structure associated with macro
*
*******************************************************************************/
sint32 DDS_M_2ND_ORDER_FILTER_DIS_S16(
                                sint16 input_value,
                                sint32 output_value,
                                t_dds_m_2nd_order_filter_s16 *filter_struct_ptr)
{
    /* Previous output initialisation */
    filter_struct_ptr->previous_output_2 = filter_struct_ptr->previous_output_1;
    filter_struct_ptr->previous_output_1 = output_value;

    /* Previous input initialisation */
    filter_struct_ptr->previous_input_2 = filter_struct_ptr->previous_input_1;
    filter_struct_ptr->previous_input_1 = input_value;

    /* Error initialisation */
    filter_struct_ptr->b0_error = 0;
    filter_struct_ptr->b1_error = 0;
    filter_struct_ptr->b2_error = 0;
    filter_struct_ptr->a0_error = 0;
    filter_struct_ptr->a1_error = 0;
    filter_struct_ptr->a2_error = 0;

    return(output_value);
}

/*******************************************************************************
*  Macro name:  DDS_M_2ND_ORDER_FILTER_S16_INIT
*
*  Diagram symbol glossary ref : 2nd_Order_Filter
*
*  Description :
*  The following macro manage initialization before starting
*  new filter with function DDS_M_2ND_ORDER_FILTER_S16 .
*
*  Where:
*  input_value initialises previous_input_2 and previous_output
*  init_value initialises previous_input_1
*  filter_struct_ptr is the structure associated to macro
*
*******************************************************************************/
sint32 DDS_M_2ND_ORDER_FILTER_S16_INIT(
                                     sint16 input_value,
                                     sint16 init_value,
                                     t_dds_m_2nd_order_filter_s16 *filter_struct_ptr)
{
    /* Previous output initialisation */
    filter_struct_ptr->previous_output_1 = init_value;
    filter_struct_ptr->previous_output_2 = init_value;

    /* Previous input initialisation */
    filter_struct_ptr->previous_input_1 = input_value;
    filter_struct_ptr->previous_input_2 = init_value;


    /* Error initialisation */
    filter_struct_ptr->b0_error = 0;
    filter_struct_ptr->b1_error = 0;
    filter_struct_ptr->b2_error = 0;
    filter_struct_ptr->a0_error = 0;
    filter_struct_ptr->a1_error = 0;
    filter_struct_ptr->a2_error = 0;

    return (sint32)init_value;
}

/*******************************************************************************
*  Function name:  DDS_M_BACKLASH_FUNCTION_S32
*
*  Description :
*  The following function applies to the input a hysteresis value "HysBand, and returns the result".

Where:
*   t_dds_m_backlash_s32 is the structure associated to macro
*   target is the input parameter
*   hyst_band allows to apply a hysteresis action on the target.
*
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_BACKLASH_S32 (CONSTP2VAR(t_dds_m_backlash_s32, AUTOMATIC, AUTOMATIC) backlash_struct_ptr,
                                            sint16 input,
                                            uint16 hyst_band)
{
    sint32 high_limit;
    sint32 low_limit;


    /*[0;65532,5] = [0;32765] +[0;(65535/2)]*/
     high_limit = (sint32)input + ((sint32)hyst_band/2);

     /*[-65535/2;32765] = [0;32765] - [0;(65535/2)]*/
     low_limit = (sint32)input - ((sint32)hyst_band/2);

    /* Call of DDS_M_SATURATION_V2 */
    backlash_struct_ptr->previous_output = DDS_M_SATURATION_V2((backlash_struct_ptr->previous_output),low_limit, high_limit);

    return (backlash_struct_ptr->previous_output);
}

/*******************************************************************************
*  Function name:  DDS_M_BACKLASH_FUNCTION_S32_INIT
*
*  Description :
*  The following function applies initialization before starting the macro DDS_M_BACKLASH_FUNCTION_S32".

Where:
*   t_dds_m_backlash_s32 is the structure associated to macro
*   target is the input parameter
*   hyst_band allows to apply a hysteresis action on the target.
*
*
*******************************************************************************/

FUNC(sint32, AUTOMATIC) DDS_M_BACKLASH_S32_INIT (CONSTP2VAR(t_dds_m_backlash_s32, AUTOMATIC, AUTOMATIC) backlash_struct_ptr,
                                            sint16 input)
{

    backlash_struct_ptr->previous_output = (sint32)input;
    return (backlash_struct_ptr->previous_output);

}

/*******************************************************************************
*
*                       2-D TAB FUNCTIONS       x -> y
*
********************************************************************************


************************************************************************************************************
    LIB_TAB_SEARCH_IND_X

    This macro is in charge to identify the X breakpoint position in the table for the X input
    with  "Use Input below" method

*************************************************************************************************************/
#define LIB_TAB_SEARCH_IND_X                                            \
    size_x_cpy    = table->size_x;                                      \
    nx = table->sav_ptr->ind_x;                                         \
    if (nx > (size_x_cpy - 1) )                                         \
    {                                                                   \
        table->sav_ptr->ind_x = 0;                                      \
        nx = table->sav_ptr->ind_x;                                     \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* Do Nothing */                                                \
    }                                                                   \
    xv_p = &table->xval[nx];                                            \
                                                                        \
    while((nx > 0) && (x < *xv_p))                                      \
    {                                                                   \
        xv_p--;                                                         \
        nx--;                                                           \
    }                                                                   \
    while((nx < (size_x_cpy - 1)) && (x >= *(xv_p + 1)))                \
    {                                                                   \
        xv_p++;                                                         \
        nx++;                                                           \
    }                                                                   \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    table->sav_ptr->ind_x = nx;



/************************************************************************************************************
    LIB_TAB_SEARCH_IND_Y

    This macro is in charge to identify the Y breakpoint position in the table for the Y input
    with  "Use Input below" method

*************************************************************************************************************/
#define LIB_TAB_SEARCH_IND_Y                                            \
    size_y_cpy    = table->size_y;                                      \
    ny = table->sav_ptr->ind_y;                                         \
    if (ny > (size_y_cpy - 1) )                                         \
    {                                                                   \
        table->sav_ptr->ind_y = 0;                                      \
        ny = table->sav_ptr->ind_y;                                     \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* Do Nothing */                                                \
    }                                                                   \
                                                                        \
    yv_p = &table->yval[ny];                                            \
    while((ny > 0) && (y < *yv_p))                                      \
    {                                                                   \
        yv_p--;                                                         \
        ny--;                                                           \
    }                                                                   \
                                                                        \
    while((ny < (size_y_cpy-1)) && (y >= *(yv_p + 1)))                  \
    {                                                                   \
        yv_p++;                                                         \
        ny++;                                                           \
    }                                                                   \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    table->sav_ptr->ind_y = ny;


/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_U8 (Use Input Below)
*  Description     :    uint8 2-D table function
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TAB2D_U8_V2( CONSTP2CONST(t_dds_m_tab2d_u8_v2, AUTOMATIC, AUTOMATIC)  table,
                                       uint8 x)
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */

    uint8 nx;           /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100> Do not touch the current implementation to avoid regression </2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X
    return (table->yval[nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_U16 (Use Input Below)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC)  DDS_M_TAB2D_U16_V2(CONSTP2CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC, AUTOMATIC) table,
                                                      uint16 x)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */

    uint8 nx;             /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2101> Do not touch the current implementation to avoid regression </2101></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X
    return (table->yval[nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_SSU16 (Use Input Below)
*  Description     :    sint16, sint16, uint16 3-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_TAB3D_SSU16_V2(CONSTP2CONST(t_dds_m_tab3d_ssu16_v2, AUTOMATIC, AUTOMATIC) table,
                                          sint16 x,
                                          sint16 y)
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the x vector. */
    uint8 nx;              /* index into x vector             */
    uint8 ny;              /* index into y vector             */
    uint8 size_x_cpy;
    uint8 size_y_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2105> Do not touch the current implementation to avoid regression </2105></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X

    /*y determination*/
    /* <PRQA_COMMENT><2100><2105> Do not touch the current implementation to avoid regression </2105></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_Y

    /* return value pointing col nx, row ny  */
    /* <PRQA_COMMENT><2100> Do not touch the current implementation to avoid regression </2100></PRQA_COMMENT> */
    return(table->zmat[(ny * size_x_cpy) + nx]);
}

/************************************************************************************************************
    LIB_TAB_SEARCH_IND_X_NEAREST

    This macro is in charge to identify the X breakpoint position in the table for the X input
    with  "Use Input Nearest" method

*************************************************************************************************************/
#define LIB_TAB_SEARCH_IND_X_NEAREST                                    \
    size_x_cpy    = table->size_x;                                      \
    nx = table->sav_ptr->ind_x;                                         \
    if (nx > (size_x_cpy - 1) )                                         \
    {                                                                   \
        table->sav_ptr->ind_x = 0;                                      \
        nx = table->sav_ptr->ind_x;                                     \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* Do Nothing */                                                \
    }                                                                   \
    xv_p = &table->xval[nx];                                            \
                                                                        \
    while((nx > 0) && (x < (*xv_p)) && (((*xv_p) - x) > ((x - (*(xv_p - 1))))))   \
    {                                                                   \
        xv_p--;                                                         \
        nx--;                                                           \
    }                                                                   \
                                                                        \
    while((nx < (size_x_cpy - 1)) && ((x > (*xv_p)) &&                  \
          ((x - (*xv_p)) >= ((*(xv_p + 1)) - x))))                          \
    {                                                                   \
        xv_p++;                                                         \
        nx++;                                                           \
    }                                                                   \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    table->sav_ptr->ind_x = nx;

/************************************************************************************************************
    LIB_TAB_SEARCH_IND_Y_NEAREST

    This macro is in charge to identify the Y breakpoint position in the table for the Y input
    with  "Use Input nearest" method

*************************************************************************************************************/
#define LIB_TAB_SEARCH_IND_Y_NEAREST                                    \
    size_y_cpy    = table->size_y;                                      \
    ny = table->sav_ptr->ind_y;                                         \
    if (ny > (size_y_cpy - 1) )                                         \
    {                                                                   \
        table->sav_ptr->ind_y = 0;                                      \
        ny = table->sav_ptr->ind_y;                                     \
    }                                                                   \
    else                                                                \
    {                                                                   \
        /* Do Nothing */                                                \
    }                                                                   \
                                                                        \
    yv_p = &table->yval[ny];                                            \
                                                                        \
    while((ny > 0) && (y < (*yv_p)) && (((*yv_p) - y) > (y - (*(yv_p - 1)))))   \
    {                                                                   \
        yv_p--;                                                         \
        ny--;                                                           \
    }                                                                   \
                                                                        \
    while((ny < (size_y_cpy - 1)) && (y > *yv_p) &&                     \
          (((y - (*yv_p)) >= ((*(yv_p + 1)) - y))))                     \
    {                                                                   \
        yv_p++;                                                         \
        ny++;                                                           \
    }                                                                   \
    /* <PRQA_COMMENT><3412> macro used for code optimisation </3412></PRQA_COMMENT> */\
    table->sav_ptr->ind_y = ny;


/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_U8_NEAREST (Use Input Nearest)
*  Description     :    uint8 2-D table function
*
*******************************************************************************/
FUNC(uint8, AUTOMATIC) DDS_M_TAB2D_NEAREST_U8_V2( CONSTP2CONST(t_dds_m_tab2d_u8_v2, AUTOMATIC, AUTOMATIC)  table,
                                               uint8 x)
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */

    uint8 nx;           /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100> Do not touch the current implementation to avoid regression </2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    return (table->yval[nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_U16 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_U16_V2(CONSTP2CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC, AUTOMATIC) table,
                                                 uint16 x)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    uint8 nx;             /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2101> Do not touch the current implementation to avoid regression </2101></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    return (table->yval[nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_S16 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_S16(CONSTP2CONST(t_dds_m_tab2d_s16, AUTOMATIC, AUTOMATIC) table,
                                                 sint16 x)
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    uint8 nx;             /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2105> Do not touch the current implementation to avoid regression </2105></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    return (table->yval[nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_US16 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
FUNC(sint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_US16(CONSTP2CONST(t_dds_m_tab2d_us16, AUTOMATIC, AUTOMATIC) table,
                                                 uint16 x)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    uint8 nx;             /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2101> Do not touch the current implementation to avoid regression </2101></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    return (table->yval[nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_SU16 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_SU16(CONSTP2CONST(t_dds_m_tab2d_su16, AUTOMATIC, AUTOMATIC) table,
                                                 sint16 x)
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    uint8 nx;             /* pointer to index on x axes  */
    uint8 size_x_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2105> Do not touch the current implementation to avoid regression </2105></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    return (table->yval[nx]);
}


/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB3D_NEAREST_U16 (Use Input Nearest)
*  Description     :    uint16, uint16, uint16 3-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_TAB3D_NEAREST_U16_V2(CONSTP2CONST(t_dds_m_tab3d_u16_v2, AUTOMATIC, AUTOMATIC) table,
                                                uint16 x,
                                                uint16 y)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the x vector. */
    uint8 nx;              /* index into x vector             */
    uint8 ny;              /* index into y vector             */
    uint8 size_x_cpy;
    uint8 size_y_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2101> Do not touch the current implementation to avoid regression </2101></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    /*y determination*/
    /* <PRQA_COMMENT><2100><2101> Do not touch the current implementation to avoid regression </2101></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_Y_NEAREST

    /* return value pointing col nx, row ny  */
    /* <PRQA_COMMENT><2100> Do not touch the current implementation to avoid regression </2100></PRQA_COMMENT> */
    return(table->zmat[(ny * size_x_cpy) + nx]);
}



/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB3D_NEAREST_USU16 (Use Input Nearest)
*  Description     :    uint16, sint16, uint16 3-D table function
*
*******************************************************************************/
FUNC(uint16, AUTOMATIC) DDS_M_TAB3D_NEAREST_USU16_V2(CONSTP2CONST(t_dds_m_tab3d_usu16_v2, AUTOMATIC, AUTOMATIC) table,
                                                  uint16 x,
                                                  sint16 y)
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xv_p; /* A pointer into the x vector. */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yv_p; /* A pointer into the x vector. */
    uint8 nx;              /* index into x vector             */
    uint8 ny;              /* index into y vector             */
    uint8 size_x_cpy;
    uint8 size_y_cpy;

    /*x determination*/
    /* <PRQA_COMMENT><2100><2101> Do not touch the current implementation to avoid regression </2101></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_X_NEAREST

    /*y determination*/
    /* <PRQA_COMMENT><2100><2105> Do not touch the current implementation to avoid regression </2105></2100></PRQA_COMMENT> */
    LIB_TAB_SEARCH_IND_Y_NEAREST

    /* return value pointing col nx, row ny  */
    /* <PRQA_COMMENT><2100> Do not touch the current implementation to avoid regression </2100></PRQA_COMMENT> */
    return(table->zmat[(ny * size_x_cpy) + nx]);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_DECREMENT_U32
*
*  The following macro will return max(input - dec, limit).
*
*  input : variable that need to be decremented.
*  dec   : decrement variable must be positive
*  limit : min value of decrementation result
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_LIMITED_DECREMENT_U32(uint32 input,
                                                  uint16 dec,
                                                  uint32 limit)
{
    uint32 temp;
    uint32 result;

    /* <PRQA_COMMENT><4471> Do not touch the current implementation to avoid regression </4471></PRQA_COMMENT> */
    temp = DDS_M_ADDITION_U32(limit,dec);

    if(temp < input)
    {
        result = ((input) - ((uint32)dec));
    }
    else
    {
        result = limit;
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_DECREMENT_S32
*
*  The following macro will return max(input - dec, limit).
*
*  input : variable that need to be decremented.
*  dec   : decrement variable must be positive
*  limit : min value of decrementation result
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_LIMITED_DECREMENT_S32(sint32 input,
                                                  uint16 dec,
                                                  sint32 limit)
{
    sint32 temp;
    sint32 result;

    temp = DDS_M_ADDITION_S32(limit,(sint32)dec);

    if(temp < input)
    {
        result = (input - (sint32)dec);
    }
    else
    {
        result = (limit);
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_INCREMENT_U32
*
*  The following macro will return min(input + inc, limit).
*
*  input : variable that need to be incremented.
*  inc   : increment variable must be positive
*  limit : min value of incrementation result
*
*******************************************************************************/
FUNC(uint32, AUTOMATIC) DDS_M_LIMITED_INCREMENT_U32(uint32 input,
                                                  uint16 inc,
                                                  uint32 limit)
{
    uint32 temp;
    uint32 result;

    /* <PRQA_COMMENT><4471> Do not touch the current implementation to avoid regression </4471></PRQA_COMMENT> */
    temp = DDS_M_ADDITION_U32(input,inc);

    if(temp < limit)
    {
        result = temp;
    }
    else
    {
        result = limit;
    }
    return(result);
}

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_INCREMENT_S32
*
*  The following macro will return min(input + inc, limit).
*
*  input : variable that need to be incremented.
*  inc   : increment variable must be positive
*  limit : min value of incrementation result
*
*******************************************************************************/
FUNC(sint32, AUTOMATIC) DDS_M_LIMITED_INCREMENT_S32(sint32 input,
                                                  uint16 inc,
                                                  sint32 limit)
{
    sint32 temp;
    sint32 result;

    temp = DDS_M_ADDITION_S32(input,(sint32)inc);

    if(temp < limit)
    {
        result = temp;
    }
    else
    {
        result = limit;
    }
     return(result);
}

#define DDS_LIB_STOP_SEC_CODE
#include "dds_lib_MemMap.h"

