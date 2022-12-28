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
* Ref X:\integration_view_00PSASWC_L10DD11\blois_psa_sstg\Software\Appli\dds_lib\src\dds_lib.h
* Version int :/main/L02_01/16 Date: 16/5/2014 8 h 58 m User:posmyk 
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :Update version
* Version dev :\main\branch_girodon_module_dev\1 Date: 13/5/2014 16 h 50 m User:girodon 
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :Update version
* Version int :/main/L02_01/15 Date: 26/2/2014 14 h 41 m User:groult
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :dev euro6.2
* Version dev :\main\branch_lemort_module_dev\2 Date: 26/2/2014 13 h 36 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :dev euro6.2
* Version dev :\main\branch_lemort_module_dev\1 Date: 13/2/2014 15 h 19 m User:lemort
*    TWK_model:DDS_Lib_L02_010_IMPL1_D
*    comments :proto PFlt 20.0 euro6.2
* Version int :/main/L02_01/14 Date: 22/10/2012 9 h 44 m User:posmyk
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_TAB2D_NEAREST_SU16
* Version dev :\main\branch_halouane_fab_dev\1 Date: 19/10/2012 16 h 12 m User:halouane
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_TAB2D_NEAREST_SU16
* Version int :/main/L02_01/13 Date: 16/10/2012 11 h 34 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_SOFT_TRANS_S32_DELTA. Add DDS_M_TAB2D_NEAREST_S16. Add DDS_M_TAB2D_NEAREST_US16
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 15/10/2012 16 h 38 m User:morisseau
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_SOFT_TRANS_S32_DELTA
*    comments :Add DDS_M_TAB2D_NEAREST_S16
*    comments :Add DDS_M_TAB2D_NEAREST_US16
* Version int :/main/L02_01/12 Date: 28/10/2011 9 h 55 m User:esnault
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add new MAP types S16U8S16 / S16U8U16
* Version dev :\main\branch_veillard_pflt\5 Date: 24/10/2011 13 h 57 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add new MAP types
* Version dev :\main\branch_veillard_pflt\4 Date: 24/10/2011 13 h 54 m User:veillard
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
* Version int :/main/L02_01/10 Date: 6/10/2011 9 h 5 m User:meme
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Implement dynamique multiplication on 64bits
* Version dev :\main\branch_moisan_module_dev\1 Date: 5/10/2011 10 h 40 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Implement dynamique multiplication on 64bits
* Version dev :\main\branch_girodon_module_dev\1 Date: 27/9/2011 17 h 0 m User:girodon
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add function DDS_M_FILTER_LP1_U16_V2, DDS_M_FILTER_LP1_U16_V2_INIT,  DDS_M_FILTER_LP1_S16_V2

*    comments : and DDS_M_FILTER_LP1_S16_V2_INIT.
* Version dev :\main\branch_veillard_pflt\3 Date: 23/9/2011 10 h 29 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\2 Date: 21/9/2011 10 h 2 m User:veillard
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :Add DDS_M_MAP3D_U8U16U16, Add DDS_M_MAP3D_U8U16S16, Add DDS_M_MAP3D_U16U8U16, Add
*    comments :DDS_M_MAP3D_U16U8S16
*    comments :Add DDS_M_INTEGRATE_16EXT32_PTR_INIT
*    comments :Modif on BIN31 and bin32 Binary points definitions
* Version dev :\main\branch_veillard_pflt\1 Date: 14/9/2011 10 h 51 m User:veillard
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
*    comments :add DDS_M_LIMITED_DECREMENT_S32. DDS_M_LIMITED_DECREMENT_U32. DDS_M_LIMITED_INCREMENT_S32.
*    comments :DDS_M_LIMITED_INCREMENT_U32
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
* Version dev :\main\branch_moisan_afad_dev\7 Date: 28/3/2011 14 h 20 m User:moisan
*    TWK_model:DDS_Lib_L02_010_IMPL1
*    comments :V_300:
*    comments :Add DDS_M_TAB2D_NEAREST_U16, DDS_M_TAB3D_NEAREST_U16 ,DDS_M_TAB3D_NEAREST_USU16,
*    comments :DDS_M_MAP2D_S16S8, DDS_M_TAB2D_NEAREST_U8 (Use Input Nearest),
*    comments :DDS_M_TAB3D_SSU16, DDS_M_TAB2D_U8, DDS_M_TAB2D_U16, DDS_M_POSITIVE_EDGE_DETECT, DDS_M_NEGATIVE_EDGE_DETECT
*    comments :and DDS_M_MAP3D_U16S16S8
* Version dev :\main\branch_moisan_afad_dev\5 Date: 25/3/2011 16 h 33 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_TAB2D_NEAREST_U16, DDS_M_TAB3D_NEAREST_U16 and DDS_M_TAB3D_NEAREST_USU16
* Version dev :\main\branch_moisan_afad_dev\4 Date: 25/3/2011 14 h 49 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_MAP2D_S16S8
* Version dev :\main\branch_moisan_afad_dev\3 Date: 25/3/2011 12 h 34 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_TAB2D_NEAREST_U8 (Use Input Nearest)
* Version dev :\main\branch_moisan_afad_dev\2 Date: 25/3/2011 10 h 41 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_TAB3D_SSU16, DDS_M_TAB2D_U8 and DDS_M_TAB2D_U16 (corresponding to "Use
*    comments :Input Below" lookup table)
* Version dev :\main\branch_moisan_afad_dev\1 Date: 24/3/2011 15 h 47 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_POSITIVE_EDGE_DETECT and DDS_M_NEGATIVE_EDGE_DETECT
*    comments :Add DDS_M_MAP3D_U16S16S8
* Version dev :\main\branch_demezil_fap_e6_dev\1 Date: 21/3/2011 15 h 32 m User:demezil
*    TWK_model:NO_MODEL
*    comments :v290 00PSASWC_L100D01
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 23/2/2011 11 h 46 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add map DDS_M_MAP2D_US8 DDS_M_MAP3D_UUS8
* Version int :/main/L01_01/11 Date: 16/11/2010 16 h 18 m User:esnault
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
*    comments :Correction of:. DDS_M_TURN_OFF_DELAY_DELTA. DDS_M_TURN_ON_DELAY_DELTA.
* Version dev :\main\branch_morisseau_fap_euro6_dev\4 Date: 4/10/2010 13 h 56 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Correction of:. DDS_M_TURN_OFF_DELAY_DELTA. DDS_M_TURN_ON_DELAY_DELTA.
* Version int :/main/L01_01/9 Date: 27/9/2010 14 h 29 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add TURN_ON_OFF_DELAY_DELTA. Add map DDS_M_MAP2D_U16U32, DDS_M_MAP2D_U16S32, DDS_M_MAP2D_S16U32,
*    comments :DDS_M_MAP2D_S16S32.. For FAP: add DDS_M_VARIABLE_TRANSPORT_DELAY_FAP
* Version dev :\main\branch_morisseau_fap_euro6_dev\3 Date: 24/9/2010 16 h 6 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add TURN_ON_OFF_DELAY_DELTA
*    comments :Add map DDS_M_MAP2D_U16U32, DDS_M_MAP2D_U16S32, DDS_M_MAP2D_S16U32, DDS_M_MAP2D_S16S32.

*    comments :For FAP: add DDS_M_VARIABLE_TRANSPORT_DELAY_FAP
* Version dev :\main\branch_morisseau_fap_euro6_dev\2 Date: 9/9/2010 9 h 47 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :last version
* Version dev :\main\branch_morisseau_fap_euro6_dev\1 Date: 8/9/2010 16 h 28 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add debounce block: TURN_ON_OFF_DELAY_DELTA
* Version dev :\main\branch_demezil_fap_e6_dev\5 Date: 7/9/2010 12 h 22 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add DDS_M_MAP2D_S16U8
* Version dev :\main\branch_demezil_fap_e6_dev\3 Date: 24/8/2010 16 h 3 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add DDS_M_MAP3D_U8U8U16
* Version dev :\main\branch_demezil_fap_e6_dev\2 Date: 19/8/2010 10 h 45 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :correct last update
* Version dev :\main\branch_demezil_fap_e6_dev\1 Date: 18/8/2010 17 h 45 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :ADD DDS_M_MAP2D_U8, DDS_M_MAP2D_S8, DDS_M_MAP2D_SU8, DDS_M_MAP2D_S8U16, DDS_M_MAP2D_U8U16,
*    comments :DDS_M_MAP2D_U16U8, DDS_M_MAP3D_U8, DDS_M_SUM_S32EXT32, DDS_M_SUM_S32EXT32_INIT, DDS_M_SUM_S32EXT32_SAT_INIT
* Version dev :\main\branch_lemort_boucle_air_dev\2 Date: 15/7/2010 10 h 15 m User:lemort
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add turn on delay delta
* Version dev :\main\branch_morisseau_afad_view\1 Date: 30/6/2010 16 h 39 m User:morisseau
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :Add ouput default value for:
*    comments :DDS_M_SIGNAL_XX_DELAY_V2
*    comments :DDS_M_SIGNAL_XX_DELAY_V2_INIT
* Version dev :\main\branch_demezil_afad_dev\7 Date: 7/6/2010 11 h 59 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add SIGNAL_S8_DELAY_V2 and SIGNAL_S8_DELAY_V2_INIT
* Version dev :\main\branch_demezil_afad_dev\6 Date: 7/6/2010 11 h 14 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add SIGNAL_U8_DELAY_V2 and SIGNAL_U8_DELAY_V2_INIT
* Version dev :\main\branch_demezil_afad_dev\5 Date: 3/6/2010 14 h 47 m User:demezil
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :add DDS_M_SIGNAL_S16_DELAY_V2,
*    comments :DDS_M_SIGNAL_S16_DELAY_V2_INIT,
*    comments :DDS_M_SIGNAL_U16_DELAY_V2,
*    comments :DDS_M_SIGNAL_U16_DELAY_V2_INIT,
*    comments :DDS_M_SIGNAL_BOOLEAN_DELAY,
*    comments :DDS_M_SIGNAL_BOOLEAN_DELAY_INIT.
*    comments :rename macro DDS_M_SIGNAL_S16_DELAY in DDS_M_SIGNAL_S16_DELAY_V1,
*    comments :DDS_M_SIGNAL_S16_DELAY_INIT in DDS_M_SIGNAL_S16_DELAY_V1_INIT
* Version int :/main/L01_01/6 Date: 23/4/2010 18 h 31 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :to add Backlash_library
* Version dev :\main\branch_salmane_trbAct_euro6_dev\1 Date: 6/4/2010 17 h 51 m User:salmane
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :to add Backlash_library
* Version dev :\main\branch_moisan_trbact_dev\7 Date: 1/4/2010 10 h 43 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :dds_lib evolution to 220
* Version int :/main/L01_01/4 Date: 26/3/2010 15 h 32 m User:esnault
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :For TrbAct 1.0. v210
* Version dev :\main\branch_moisan_trbact_dev\6 Date: 26/3/2010 15 h 15 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1_D
*    comments :For TrbAct 1.0. v210
* Version dev :\main\branch_moisan_trbact_dev\5 Date: 1/3/2010 10 h 33 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_moisan_trbact_dev\4 Date: 17/2/2010 15 h 20 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add DDS_M_MEM_EXTINI_U32_INIT and DDS_M_MEM_EXTINI_U32
* Version dev :\main\branch_moisan_trbact_dev\3 Date: 10/2/2010 12 h 44 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add DDS_M_2ND_ORDER_FILTER_S16 and DDS_M_2ND_ORDER_FILTER_S16_INIT
* Version dev :\main\branch_moisan_trbact_dev\1 Date: 5/2/2010 12 h 27 m User:moisan
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add DDS_M_MEM_EXTINI_U16_INIT and DDS_M_MEM_EXTINI_U16
* Version int :/main/L01_01/1 Date: 3/12/2009 11 h 46 m User:langendorf
*    TWK_model:DDS_Lib_L01_010_IMPL1
*    comments :Add "DDS_M_FILTER_HYST_U16", "DDS_M_FILTER_HYST_U16_INIT", "DDS_M_FILTER_HYST_S32"
*    comments :and "DDS_M_FILTER_HYST_S32".
* Version dev :\main\branch_girodon_vsinfoh\1 Date: 13/11/2009 13 h 15 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add "DDS_M_FILTER_HYST_U16", "DDS_M_FILTER_HYST_U16_INIT", "DDS_M_FILTER_HYST_S32"
*    comments :and "DDS_M_FILTER_HYST_S32".
* Version int :/main/P2868/BR_06E4/3 Date: 16/9/2009 10 h 44 m User:langendorf
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32_INIT and DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 28/8/2009 17 h 20 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32_INIT and DDS_M_ADAPT_TRANS_TEMPO_BLOCK_S32
* Version int :/main/P2868/BR_06D7/1 Date: 28/5/2009 18 h 3 m User:langendorf
*    TWK_model:NO_MODEL
*    comments :Add machine types to remove QAC warning.
* Version dev :\main\branch_girodon_generic\1 Date: 28/5/2009 10 h 31 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add machine types to remove QAC warning.
* Version dev :\main\branch_lemort_vscoh_dev\3 Date: 19/5/2009 15 h 51 m User:lemort
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_LIMIT_V2 and DDS_M_SATURATION_V2
*    comments :Change DDS_M_LIMIT to DDS_M_LIMIT_V1 and DDS_M_SATURATION to DDS_M_SATURATION_V1
* Version dev :\main\branch_lemort_vscoh_dev\2 Date: 7/5/2009 14 h 44 m User:lemort
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_FILTER_LP1_ASSYM_S16,
*    comments :DDS_M_FILTER_LP1_ASSYM_S16_INIT and correct errors on DDS_M_FILTER_HYST_S16
* Version dev :\main\branch_lemort_vscoh_dev\1 Date: 7/5/2009 10 h 50 m User:lemort
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_FILTER_HYST_S16 function
*    comments :and DDS_M_FILTER_HYST_S16_INIT
*    comments :and associated structure : t_dds_m_filter_hyst_s16
* Version dev :\main\branch_moisan_vsmaxh_dev\1 Date: 30/4/2009 14 h 40 m User:moisan
*    TWK_model:NO_MODEL
*    comments :No modification, but should be integrated in main branch
* Version dev :\main\branch_moisan_vsctlinfo_dev\1 Date: 3/4/2009 17 h 12 m User:moisan
*    TWK_model:NO_MODEL
*    comments :New version. Update Version 160 only
* Version int :/main/15 Date: 22/12/2008 16 h 0 m User:neve
*    TWK_model:NO_MODEL
*    comments :Version 150: . Correct DDS_M_HYST_LH_U32 function. . Add DDS_M_HYST_LH_S32 function. . Add DDS_M_LINEAR_FILTER_S32 and DDS_M_LINEAR_FILTER_S32_INIT.
* Version dev :\main\branch_girodon_tqdemh_1_dev\1 Date: 9/12/2008 16 h 44 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Version 150:
*    comments :Correct DDS_M_HYST_LH_U32 function.
*    comments :Add DDS_M_HYST_LH_S32 function.
*    comments :Add DDS_M_LINEAR_FILTER_S32 and DDS_M_LINEAR_FILTER_S32_INIT.
* Version int :/main/14 Date: 14/11/2008 16 h 49 m User:langendorf
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_HYST_PH_S32 and DDS_M_HYST_PH_INIT_S32 macro.
* Version dev :\main\branch_girodon_pfilfast_1_dev\1 Date: 14/11/2008 12 h 9 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_HYST_PH_S32 and DDS_M_HYST_PH_INIT_S32 macro.
* Version dev :\main\branch_veillard_curdrivfil\3 Date: 31/10/2008 14 h 55 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Modif name of macro DDS_M_SOFT_TRANS_U32_DELTA par
*    comments :DDS_M_SOFT_TRANS_DELTA_U32 & DDS_M_SOFT_TRANS_U32_DELTA_INIT par
*    comments :DDS_M_SOFT_TRANS_DELTA_U32_INIT
* Version dev :\main\branch_veillard_curdrivfil\2 Date: 31/10/2008 9 h 32 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Add new SOFT TRANSITION DELTA
* Version dev :\main\branch_veillard_curdrivfil\1 Date: 30/10/2008 16 h 52 m User:veillard
*    TWK_model:NO_MODEL
*    comments :Add a new macro, DDS_M_TURN_OFF_DELAY_DELTA & DDS_M_TURN_OFF_DELAY_DELTA_INIT
* Version dev :\main\branch_girodon_tqdem_1_dev\1 Date: 8/10/2008 16 h 12 m User:girodon
*    TWK_model:LDCR_Application_06E400_IMPL2
*    comments :Rename "slew rate" function and its sub-function to respect the nmaing convention (start with "DDS_M_").
* Version int :/main/P2868/BR_06E4/1 Date: 9/9/2008 8 h 6 m User:boucher
*    TWK_model:NO_MODEL
*    comments :Update library in order to integrate a soft transition for psa SSTG
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 4/9/2008 15 h 15 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update library in order to integrate a soft transition for psa SSTG
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\1 Date: 29/8/2008 8 h 47 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add macro DDS_M_SATURATION
* Version int :/main/13 Date: 29/4/2008 15 h 0 m User:neve
*    TWK_model:NO_MODEL
*    comments :Add "DDS_M_DECREMENT_SINT32" function to be use to update the minimum sint32 supported by the machine ("DDS_SINT32_MIN_FULL").
* Version dev :\main\branch_girodon_xvv_2_dev\1 Date: 28/4/2008 9 h 22 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add "DDS_M_DECREMENT_SINT32" function to be use to update the minimum sint32 supported by the machine ("DDS_SINT32_MIN_FULL").
* Version int :/main/12 Date: 15/4/2008 15 h 45 m User:neve
*    TWK_model:NO_MODEL
*    comments :Correct define use to generate negative value (FDS22651).
* Version dev :\main\branch_girodon_fap_1_dev\1 Date: 14/4/2008 11 h 24 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Correct define use to generate negative value (FDS22651).
* Version int :/main/11 Date: 8/4/2008 9 h 40 m User:neve
*    TWK_model:NO_MODEL
*    comments :Use -(2^31) instead of "DDS_SINT32_MIN" for the min value to reduce time function's execution of addition protected function and bary filter.
* Version dev :\main\branch_girodon_module_integ_xvv_1\1 Date: 2/4/2008 14 h 26 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Use -(2^31) instead of "DDS_SINT32_MIN" for the min value to reduce time function's execution of addition protected function and bary filter.
* Version dev :\main\branch_terracol_sstg_autosar\10 Date: 28/3/2008 10 h 42 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Protected addition optimisation
* Version dev :\main\branch_terracol_sstg_autosar\9 Date: 28/3/2008 9 h 33 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add macro DDS_M_SIGN
* Version dev :\main\branch_terracol_sstg_autosar\8 Date: 27/3/2008 15 h 6 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add  inline function for operation shorten and dynamique multiplication
* Version dev :\main\branch_terracol_sstg_autosar\7 Date: 11/3/2008 12 h 14 m User:terracol
*    TWK_model:NO_MODEL
*    comments :QUAL Correction M_GET_BITFIELD --> DDS_M_GET_BITFIELD
* Version int :/main/10 Date: 29/2/2008 11 h 40 m User:renier
*    TWK_model:NO_MODEL
*    comments :Increase DDS LIB version only
* Version dev :\main\branch_terracol_sstg_autosar\6 Date: 28/2/2008 10 h 48 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Increase DDS LIB version only
* Version dev :\main\branch_terracol_sstg_autosar\5 Date: 25/2/2008 16 h 21 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add DDS_M_SHORTEN_UINT32_TO_UINT32 header
* Version dev :\main\branch_terracol_sstg_autosar\4 Date: 22/2/2008 15 h 23 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add VSC_DDS_M_ADDITION_S32 and VSC_DDS_M_ADDITION_U32
* Version int :/main/9 Date: 22/10/2007 9 h 36 m User:renier
*    TWK_model:NO_MODEL
*    comments :Dynamic library improvement (fix --> round)
* Version dev :\main\branch_terracol_sstg_autosar\3 Date: 16/10/2007 13 h 53 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Dynamic library improvement (fix --> round)
* Version int :/main/8 Date: 15/10/2007 10 h 35 m User:renier
*    TWK_model:NO_MODEL
*    comments :Add library compatibility tag.
* Version dev :\main\branch_girodon_dgd_sstg\1 Date: 14/9/2007 14 h 42 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add library compatibility tag.
* Version int :/main/7 Date: 23/7/2007 16 h 53 m User:renier
*    TWK_model:NO_MODEL
*    comments :Minor correction (QAC quallity)
* Version dev :\main\branch_terracol_sstg_autosar\2 Date: 19/7/2007 8 h 56 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Minor correction (QAC quallity)
* Version dev :\main\branch_terracol_sstg_autosar\1 Date: 18/7/2007 18 h 14 m User:terracol
*    TWK_model:NO_MODEL
*    comments :behaviour modification of DDS_M_DYNAMIC_MULT_U32, DDS_M_DYNAMIC_MULT_S32, DDS_M_DYNAMIC_MULT_USS32
* Version dev :\main\branch_girodon_dgd_sstg\1 Date: 11/7/2007 12 h 57 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add dynamic librairy: . DDS_M_DYNAMIC_MULT_U32 . DDS_M_DYNAMIC_MULT_S32 . DDS_M_DYNAMIC_MULT_USS32 . DDS_M_DYNAMIC_DIV_U32 . DDS_M_DYNAMIC_DIV_S32
* Version int :/main/6 Date: 17/4/2007 13 h 32 m User:neve
*    TWK_model:NO_MODEL
*    comments :add DDS_M_INTEGRATE_S16U32
* Version dev :\main\branch_terracol_sstg_autosar\18 Date: 11/4/2007 13 h 45 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add DDS_M_INTEGRATE_S16U32
* Version int :/main/5 Date: 27/2/2007 10 h 37 m User:renier
*    TWK_model:NO_MODEL
*    comments :Change "REDUCE" function names due to downward compatibility requirement (should have been done in previous version). Add bit field management macro. Add define for library version.
* Version dev :\main\branch_girodon_dgd_sstg\14 Date: 21/2/2007 9 h 37 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Change "REDUCE" function names due to downward compatibility requirement (should have been done in previous version). Add bit field management macro. Add define for library version.
* Version int :/main/4 Date: 12/2/2007 15 h 55 m User:cheucle
*    TWK_model:NO_MODEL
*    comments :modification of type "t_dds_m_tab2d_u16" const struct --> struct
* Version dev :\main\branch_terracol_sstg_autosar\17 Date: 6/2/2007 9 h 35 m User:terracol
*    TWK_model:NO_MODEL
*    comments :modification of type "t_dds_m_tab2d_u16" const struct --> struct
* Version dev :\main\branch_terracol_sstg_autosar\16 Date: 6/2/2007 9 h 23 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Headers corrections
* Version dev :\main\branch_terracol_sstg_autosar\15 Date: 5/2/2007 16 h 25 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add DDS_M_TAB2D_U16
* Version dev :\main\branch_terracol_sstg_autosar\14 Date: 30/1/2007 14 h 8 m User:terracol
*    TWK_model:NO_MODEL
*    comments :DDS_M_REDUCE_SINT32_TO_SINT16 and DDS_M_REDUCE_UINT32_TO_UINT16 headers modification.
*    comments :DDS_M_INCREASE_UINT32_TO_UINT32 and DDS_M_INCREASE_SINT32_TO_SINT32 modification.
* Version dev :\main\branch_terracol_sstg_autosar\13 Date: 26/1/2007 16 h 35 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add DDS_M_BARY_FILTER_S32 (not operationnal currently)
* Version dev :\main\branch_girodon_dgd_sstg\11 Date: 25/1/2007 9 h 51 m User:girodon
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Add macro DDS_M_INCREASE_UINT32_TO_UINT32 and update DDS_M_REDUCE_xINT32_TO_xINT16 to not set to 0 nb_shift.
* Version dev :\main\branch_terracol_sstg_autosar\12 Date: 19/1/2007 11 h 2 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :In macro DDS_M_PROD_MATRIX_ CONSP2CONST -> P2VAR
* Version dev :\main\branch_terracol_sstg_autosar\11 Date: 18/1/2007 15 h 42 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :Output of matrix multplication becomes 32 bits
* Version dev :\main\branch_terracol_sstg_autosar\10 Date: 16/1/2007 15 h 49 m User:terracol
*    TWK_model:LDCR_Application_06C000_IMPL3_D
*    comments :correction of DDS_M_LIMITED_DECREMENT
* Version int :/main/P2868/BR_06C/3 Date: 12/1/2007 10 h 1 m User:renier
*    TWK_model:LDCR_Application_06C000_IMPL3
*    comments :Update comment of "DDS_M_REDUCE_UINT32_TO_UINT16" and "DDS_M_REDUCE_SINT32_TO_SINT16" in order to init nb_shift to 0 (temporary).
* Version dev :\main\branch_girodon_dgd_sstg\10 Date: 11/1/2007 18 h 41 m User:girodon
*    TWK_model:LDCR_Application_06C000_IMPL3
*    comments :Update comment of "DDS_M_REDUCE_UINT32_TO_UINT16" and "DDS_M_REDUCE_SINT32_TO_SINT16" in order to init nb_shift to 0 (temporary).
* Version dev :\main\branch_guillon_sstg_autosar\7 Date: 11/1/2007 10 h 7 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Add macros DDS_M_HYST_U32 and DDS_M_HYST_U32_INIT
* Version dev :\main\branch_terracol_sstg_autosar\9 Date: 11/1/2007 9 h 2 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add missing ";"
* Version dev :\main\branch_terracol_sstg_autosar\8 Date: 11/1/2007 8 h 46 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add macros DDS_M_PROD_MATRIX_UINT16 & DDS_M_PROD_MATRIX_SINT16
*    comments :Add macros DDS_M_SLEW_U32_INIT (header was missing)
*    comments :Add comment of all macros (comments come from dds_lib.c)
* Version dev :\main\branch_terracol_sstg_autosar\7 Date: 8/1/2007 12 h 50 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add DDS_M_LIMITED_DECREMENT and DDS_M_LIMITED_INCREMENT
* Version dev :\main\branch_terracol_sstg_autosar\6 Date: 8/1/2007 11 h 28 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add DDS_M_POSITIVE_DECREMENT(input, dec)
* Version dev :\main\branch_terracol_sstg_autosar\5 Date: 22/12/2006 11 h 25 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Add user guide for "dynamique resolution" functions
* Version int :/main/P2868/BR_06C/2 Date: 21/12/2006 10 h 2 m User:cheucle
*    TWK_model:NO_MODEL
*    comments :Correction of "user guide" for macro DDS_M_RESTORE_BINPOINT
* Version int :/main/P2868/BR_06C/1 Date: 6/12/2006 13 h 32 m User:neve
*    TWK_model:LDCR_Application_06C000_SPEC1
*    comments :Add DDS_M_CONVERT_BOOL_TO_UINT8 and DDS_M_CONVERT_UINT8_TO_BOOL.
* Version dev :\main\branch_terracol_sstg_autosar\4 Date: 6/12/2006 14 h 28 m User:terracol
*    TWK_model:NO_MODEL
*    comments :Correction of "user guide" for macro DDS_M_RESTORE_BINPOINT
* Version dev :\main\branch_guillon_sstg_autosar\6 Date: 6/12/2006 14 h 1 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Modification of macros DDS_M_CALC_MEAN_BUFFER and DDS_M_CALC_MEAN_BUFFER_INIT
* Version dev :\main\branch_terracol_sstg_autosar\3 Date: 4/12/2006 10 h 20 m User:terracol
*    TWK_model:NO_MODEL
*    comments :add function for dynamic binpoint:
*    comments :DDS_M_REDUCE_UINT32_TO_UINT16
*    comments :DDS_M_REDUCE_SINT32_TO_SINT16
*    comments :DDS_M_RESTORE_BINPOINT_UINT32
*    comments :DDS_M_RESTORE_BINPOINT_SINT32
* Version dev :\main\branch_girodon_dgd_sstg\9 Date: 1/12/2006 20 h 9 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_CONVERT_BOOL_TO_UINT8 and DDS_M_CONVERT_UINT8_TO_BOOL.
* Version dev :\main\branch_girodon_dgd_sstg\8 Date: 28/11/2006 9 h 8 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add DDS_M_SIGNAL_S16_DELAY and DDS_M_SIGNAL_S16_DELAY_INIT.
* Version dev :\main\branch_guillon_sstg_autosar\5 Date: 23/11/2006 13 h 38 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Modification of macro DDS_M_INV_BOOL_TYPE : TRUE/FALSE -> DDS_TRUE/DDS_FALSE
* Version dev :\main\branch_girodon_dgd_sstg\5 Date: 23/11/2006 10 h 39 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Add parenthesis in DDS_FALSE and DDS_TRUE definitions to remove QAC warnings.
* Version dev :\main\branch_hz9crn_dpf\1 Date: 22/11/2006 11 h 34 m User:oudin
*    TWK_model:NO_MODEL
*    comments :add macros DDS_TRUE and DDS_FALSE .
* Version dev :\main\branch_terracol_sstg_autosar\2 Date: 20/11/2006 14 h 38 m User:terracol
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
* Version dev :\main\branch_guillon_sstg_autosar\3 Date: 14/11/2006 9 h 48 m User:guillon
*    TWK_model:NO_MODEL
*    comments :Macros renamed :
*    comments :- DDS_M_UMAP2D   => DDS_M_MAP2D_U16
*    comments :- DDS_M_SMAP2D   => DDS_M_MAP2D_S16
*    comments :- DDS_M_SUMAP2D => DDS_M_MAP2D_SU16
*    comments :- DDS_M_USMAP2D => DDS_M_MAP2D_US16
*    comments :- DDS_M_UMAP3D   => DDS_M_MAP3D_U16
*    comments :- DDS_M_SMAP3D   => DDS_M_MAP3D_S16
*    comments :- DDS_M_SUSMAP3D => DDS_M_MAP3D_SUS16
*    comments :- DDS_M_USSMAP3D => DDS_M_MAP3D_USS16
*    comments :- DDS_M_SUUMAP3D => DDS_M_MAP3D_SUU16
*    comments :- DDS_M_USUMAP3D => DDS_M_MAP3D_USU16
*    comments :- DDS_M_SSUMAP3D => DDS_M_MAP3D_SSU16
*    comments :- DDS_M_UUSMAP3D => DDS_M_MAP3D_UUS16
* Version dev :\main\branch_girodon_dgd_sstg\3 Date: 6/11/2006 11 h 10 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Correct function declarations (change P2VAR to P2CONST or CONSTP2CONST)
* Version dev :\main\branch_girodon_dgd_sstg\2 Date: 3/11/2006 16 h 42 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Remove "const" from type declaration.
*    comments :Add:
*    comments :- DDS_M_EDGE_DETECT
*    comments :- DDS_M_EDGE_DETECT_INIT
*    comments :Update :
*    comments :- DDS_M_BARY_FILTER_S16 interface
* Version dev :\main\branch_guillon_sstg_autosar\2 Date: 2/11/2006 14 h 53 m User:guillon
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

#ifndef DDS_LIB_H
#define DDS_LIB_H


/*******************************************************************************
*  Library Include Files
*******************************************************************************/
#include "Rte_Type.h"          /* Generic AUTOSAR types definitions */


/*******************************************************************************
*  Library Version
*******************************************************************************/

#define DDS_LIB_VERSION 430

/*******************************************************************************
*  Library Macro Definitions
*******************************************************************************/

#define DDS_UINT8_MIN   (0U)
#define DDS_UINT8_MAX   (255U)

#define DDS_SINT8_MIN   (-127)
#define DDS_SINT8_MAX   (127)

#define DDS_UINT16_MIN  (0U)
#define DDS_UINT16_MAX  (65535U)

#define DDS_SINT16_MIN  (-32767)
#define DDS_SINT16_MAX  (32767)

#define DDS_UINT32_MIN  (0UL)
#define DDS_UINT32_MAX  (4294967295UL)

#define DDS_SINT32_MIN  (-2147483647L)
#define DDS_SINT32_MAX  (2147483647L)

#define DDS_SINT32_MIN_FULL (DDS_M_DECREMENT_SINT32(DDS_SINT32_MIN))

#define DDS_TRUE        ((uint8)1)
#define DDS_FALSE       ((uint8)0)

/* Null pointer definition */
#define DDS_NULL_PTR ((void*)0)

#define DDS_M_SOFT_TRANS_RATIO_BIN           (BIN15)
#define DDS_M_SOFT_TRANS_DELTA_MAX           (BIN16)

#define DDS_LIB_SIZE_2    ((uint32)2)
#define DDS_2ND_ORDER_FILTER_S16_TAB_TERM_SIZE_5    ((uint32)5)

/*******************************************************************************
* Binary points definitions
*******************************************************************************/

#define BIN0            1
#define BIN1            2
#define BIN2            4
#define BIN3            8
#define BIN4            16
#define BIN5            32
#define BIN6            64
#define BIN7            128
#define BIN8            256
#define BIN9            512
#define BIN10           1024
#define BIN11           2048
#define BIN12           4096
#define BIN13           8192
#define BIN14           16384
#define BIN15           32768
#define BIN16           65536L
#define BIN17           131072L
#define BIN18           262144L
#define BIN19           524288L
#define BIN20           1048576L
#define BIN21           2097152L
#define BIN22           4194304L
#define BIN23           8388608L
#define BIN24           16777216L
#define BIN25           33554432L
#define BIN26           67108864L
#define BIN27           134217728L
#define BIN28           268435456L
#define BIN29           536870912L
#define BIN30           1073741824L
#define BIN31           2147483648UL
#define BIN32           4294967296ULL

/*******************************************************************************
* Decimal points definitions
*******************************************************************************/

#define DEC0            1
#define DEC1            10
#define DEC2            100
#define DEC3            1000
#define DEC4            10000
#define DEC5            100000L
#define DEC6            1000000L
#define DEC7            10000000L
#define DEC8            100000000L
#define DEC9            1000000000L

/*******************************************************************************
*  Plateform Type Definitions
*******************************************************************************/

typedef unsigned int    t_dds_m_uint;
typedef signed int      t_dds_m_sint;

typedef unsigned long long t_dds_m_uint64;
typedef signed long long   t_dds_m_sint64;

/* By default, Dynamique multiplication are done on 32bits */
#ifdef DDS_LIB_64BITS_SUPPORTED
#define DDS_M_DYNAMIC_MULT_U32 DDS_M_DYNAMIC_MULT_U32_V2
#define DDS_M_DYNAMIC_MULT_S32 DDS_M_DYNAMIC_MULT_S32_V2
#define DDS_M_DYNAMIC_MULT_USS32 DDS_M_DYNAMIC_MULT_USS32_V2
#else
#define DDS_M_DYNAMIC_MULT_U32 DDS_M_DYNAMIC_MULT_U32_V1
#define DDS_M_DYNAMIC_MULT_S32 DDS_M_DYNAMIC_MULT_S32_V1
#define DDS_M_DYNAMIC_MULT_USS32 DDS_M_DYNAMIC_MULT_USS32_V1
#endif


/*******************************************************************************
*  Map Type Definitions
*******************************************************************************/

/* MAP TYPES */
typedef struct
{
    uint8 ind_x;         /* Save last Index x position */
}t_dds_m_map2d_sav;

typedef struct
{
    uint8 ind_x;         /* Save last Index x position */
    uint8 ind_y;         /* Save last Index x position */
}t_dds_m_map3d_sav;

/* 2-D MAPS : ie x -> y */
typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s16;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_u16;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_u8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_u8u16;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_u16u8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s16u8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of x,y pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s16s8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_su16;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_su8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_us8;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s8u16;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_us16;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_u16u32;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint32, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_u16s32;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s16u32;

typedef struct
{
    P2VAR(t_dds_m_map2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size;                                             /* No of pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(sint32, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_map2d_s16s32;

/* 3-D MAPS : ie (x,y) -> z */
typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_s16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_u16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;                /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;                /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_u8u8u16;


typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) zmat;                /* Pointer to start of z matrix */
} t_dds_m_map3d_u16s16s8;


typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;                /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;                /* Pointer to start of y vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) zmat;                /* Pointer to start of z matrix */
} t_dds_m_map3d_u8;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;                /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;                /* Pointer to start of y vector */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) zmat;                /* Pointer to start of z matrix */
} t_dds_m_map3d_uus8;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;                /* Pointer to start of y vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) zmat;                /* Pointer to start of z matrix */
} t_dds_m_map3d_u16u8u8;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;                /* Pointer to start of y vector */
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) zmat;                /* Pointer to start of z matrix */
} t_dds_m_map3d_u16u8s8;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_sus16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_uss16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_suu16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_usu16;


typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_ssu16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_uus16;


typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_u8u16u16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_u8u16s16;


typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_u16u8u16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_u16u8s16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_s16u8s16;

typedef struct
{
    P2VAR(t_dds_m_map3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 x_size;                                           /* X dimension of array & x-vector */
    uint8 y_size;                                           /* Y dimension of array & y-vector */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x vector */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y vector */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;               /* Pointer to start of z matrix */
} t_dds_m_map3d_s16u8u16;

/*******************************************************************************
*  Enum Type Definitions
*******************************************************************************/

/* Enum for macro DDS_M_EDGE_DETECT */
typedef enum
{
    DDS_M_NO_EDGE_DETECTED,
    DDS_M_POSITIVE_EDGE_DETECTED,
    DDS_M_NEGATIVE_EDGE_DETECTED
} t_dds_m_edge_detected_event;


/*******************************************************************************
*  Structure Type Definitions
*******************************************************************************/

/* Store data structure for macro DDS_M_INTEGRATE_32 */
typedef struct
{
    uint32  dds_int_prev_output;
    uint32  dds_int_previous_time;
}t_dds_m_integrate_32;

/* Store data structure for macro DDS_M_INTEGRATE_S16U32 */
typedef struct
{
    uint32 dds_int_prev_output;
    uint32  dds_int_previous_time;
}t_dds_m_integrate_s16u32;

/* Store data structure for macro DDS_M_INTEGRATE_32EXT16 */
typedef struct
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) dds_int_prev_output_high_ptr;
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) dds_int_prev_output_low_ptr;
    uint32  dds_int_previous_time;
    uint32  dds_int_output_step;
}t_dds_m_integrate_16ext32;

typedef struct {
    sint32 dds_sum_prev_high;
    sint32 dds_sum_prev_low;
    uint32 dds_sum_step;
    sint32 dds_sum_saturation_min;
    sint32 dds_sum_saturation_max;
}t_dds_m_sum_s32ext32;

/* Store data structure for macro DDS_M_CHECK_DELTA16 */
typedef struct
{
    uint16  dds_delta_prev_output;
    uint16  dds_delta_max;
}t_dds_m_check_delta16;

/* Store data structure for macro DDS_M_CALC_MEAN_BUFFER */
typedef struct
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) dds_cmb_buffer_ptr;
    uint8   dds_cmb_size;
}t_dds_m_calc_mean_buffer;

/* Store data structure for macro DDS_M_U16_CALC_MEAN_SHIFTED */
typedef struct
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) dds_cmb_buffer_ptr;
    uint8   dds_cmb_size;
}t_dds_m_u16_calc_mean_shifted;

/* Store data structure for macro DDS_M_SLEW */
typedef struct
{
    union
    {
        sint32 prev_S32;
        uint32 prev_U32;
    }prev_output;
}t_dds_m_slew;

/* Store data structure for macro DDS_M_CHRONOMETER_U32 */
typedef struct
{
    uint32 dds_chrono_previous_time;
    uint32 dds_chrono_previous_output;
    uint8  dds_chrono_previous_enable;      /* Boolean */
}t_dds_m_chrono_u32;

/* Store data structure for macro DDS_M_FILTER_LP1_U16 and DDS_M_FILTER_LP1_S16 */
typedef struct
{
    sint32 previous_error ;
    union
    {
        sint16 prev_S16;
        uint16 prev_U16;
    }previous_output;
}t_dds_m_filter_lp1;

/* Store data structure for macro DDS_M_FILTER_LP1_U16_V2 and DDS_M_FILTER_LP1_S16_V2 */
typedef struct
{
    P2VAR(sint32, AUTOMATIC, AUTOMATIC) previous_error_ptr;
    union
    {
        P2VAR(sint16, AUTOMATIC, AUTOMATIC) prev_S16_ptr;
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) prev_U16_ptr;
    }previous_output;
}t_dds_m_filter_lp1_v2;


/* Store data structure for macro DDS_M_EDGE_DETECT */
typedef struct
{
    uint8 previous_input;
} t_dds_m_edge_detect;

/* Store data structure for macro DDS_M_TIMER         */
typedef struct
{
    uint32 start_time ;
    uint32 time_passed;
    uint8 previous_output ; /* Boolean */
} t_dds_m_timer_type;

/* Store data structure for macro DDS_M_TURN_ON_DELAY */
typedef struct
{
    t_dds_m_timer_type m_timer_str;
    uint8 previous_input ;   /* Boolean */
    uint8 previous_output;   /* Boolean */

} t_dds_m_turn_on_delay_type;

/* Store data structure for macro DDS_M_TURN_ON_DELAY_DELTA */
typedef struct
{
    t_dds_m_timer_type m_timer_str;
    uint8 previous_input ;   /* Boolean */
    uint8 previous_output;   /* Boolean */
    uint32 elapsed_time;     /* elapsed time */

} t_dds_m_turn_on_delay_delta_type;

/* Store data structure for macro DDS_M_TURN_OFF_DELAY */
typedef struct
{
    t_dds_m_timer_type m_timer_str;
    uint8 previous_input ;   /* Boolean */
    uint8 previous_output;   /* Boolean */

} t_dds_m_turn_off_delay_type;


/* Store data structure for macro DDS_M_TURN_OFF_DELAY_DELTA */
typedef struct
{
    t_dds_m_timer_type m_timer_str;
    uint8 previous_input ;   /* Boolean */
    uint8 previous_output;   /* Boolean */
    uint32 elapsed_time;     /* elapsed time */

} t_dds_m_turn_off_delay_delta_type;


/* Store data structure for macro DDS_M_TURN_ON_OFF_DELAY */
typedef struct
{
    t_dds_m_timer_type m_timer_str;
    uint8 previous_input ;   /* Boolean */
    uint8 previous_output;   /* Boolean */

} t_dds_m_turn_on_off_delay_type;

/* Store data structure for macro DDS_M_TURN_ON_OFF_DELAY_DELTA */
typedef struct
{
    uint8 previous_input ;   /* Boolean */
    uint8 previous_output;   /* Boolean */
    uint32 elapsed_time;     /* elapsed time */

} t_dds_m_turn_on_off_delay_delta_type;

/* Store data structure for macro DDS_M_SIGNAL_S16_DELAY */
typedef struct
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) buffer_ptr;
    uint16 buffer_size;
    uint16 buffer_last_pos;
    uint16 buffer_nb_data;
    uint16 prescaler;
    uint16 current_prescale;
    uint16 ratio_delay_sched;
} t_dds_m_sig_s16_delay_type;

/* Store data structure for macro DDS_M_SIGNAL_S16_DELAY_V2 */
typedef struct
{
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) buffer_ptr;
    uint16 buffer_size;
    uint16 buffer_last_pos;
    uint16 buffer_nb_data;
    uint16 prescaler;
    uint16 current_prescale;
    uint16 delay_sched;
    sint16 default_val;
} t_dds_m_sig_s16_delay_v2_type;

/* Store data structure for macro DDS_M_SIGNAL_U16_DELAY_V2 */
typedef struct
{
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) buffer_ptr;
    uint16 buffer_size;
    uint16 buffer_last_pos;
    uint16 buffer_nb_data;
    uint16 prescaler;
    uint16 current_prescale;
    uint16 delay_sched;
    uint16 default_val;
} t_dds_m_sig_u16_delay_v2_type;

/* Store data structure for macro DDS_M_SIGNAL_U8_DELAY_V2 */
typedef struct
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) buffer_ptr;
    uint16 buffer_size;
    uint16 buffer_last_pos;
    uint16 buffer_nb_data;
    uint16 prescaler;
    uint16 current_prescale;
    uint16 delay_sched;
    uint8 default_val;
} t_dds_m_sig_u8_delay_v2_type;

/* Store data structure for macro DDS_M_SIGNAL_S8_DELAY_V2 */
typedef struct
{
    P2VAR(sint8, AUTOMATIC, AUTOMATIC) buffer_ptr;
    uint16 buffer_size;
    uint16 buffer_last_pos;
    uint16 buffer_nb_data;
    uint16 prescaler;
    uint16 current_prescale;
    uint16 delay_sched;
    sint8 default_val;
} t_dds_m_sig_s8_delay_v2_type;

/* Store data structure for macro DDS_M_SIGNAL_BOOLEAN_DELAY */
typedef struct
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) buffer_ptr;
    uint16 buffer_size;
    uint32 buffer_last_pos;
    uint32 buffer_nb_data;
    uint16 delay_sched;
    uint16 time_delay_max;
} t_dds_m_sig_boolean_delay_type;

/* Store data structure for macro */
/* DDS_M_HYST_U32 */
/* DDS_M_HYST_PH_S32 */
/* DDS_M_HYST_PH_U32 */
/* DDS_M_HYST_LH_U32 */
typedef struct
{
    uint8 previous_output;
}t_dds_m_hyst_type;

/* Store data structure for TAB2D U16 */
typedef struct {
        uint8 size;            /* No of pairs */
        P2CONST(uint16, AUTOMATIC, AUTOMATIC) xval;             /* Pointer to start of x array */
        P2CONST(uint16, AUTOMATIC, AUTOMATIC) yval;             /* Pointer to start of y array */
} t_dds_m_tab2d_u16;

/* Store data structure for macro DDS_M_SOFT_TRANS_U32 */
typedef struct
{
    uint8 *trans_active_ptr;
    uint32 previous_time;
    uint32 error;
    uint16 error_shift;  /* right shift of error */
    uint16 ratio;     /* Resolution = DDS_M_SOFT_TRANS_RATIO_BIN */

    uint8 previous_enable;
} t_dds_m_soft_trans_u32_type;


/* Store data structure for macro DDS_M_SOFT_TRANS_DELTA_U32 */
typedef struct
{
    uint8 *trans_active_ptr;
    uint32 error;
    uint16 error_shift;  /* right shift of error */
    uint16 ratio;     /* Resolution = DDS_M_SOFT_TRANS_RATIO_BIN */

    uint8 previous_enable;
} t_dds_m_soft_trans_delta_u32_type;


/* Store data structure for macro DDS_M_SOFT_TRANS_DELTA_S32 */
typedef t_dds_m_soft_trans_delta_u32_type t_dds_m_soft_trans_delta_s32_type;


/* Store data structure for macro DDS_M_LINEAR_FILTER_S32 */
typedef struct
{
    uint8 previous_activation;    /* Boolean */
    uint8 previous_retrigger;     /* Boolean */
    uint8 previous_input_choice;  /* Boolean */
    uint8 previous_compar_time;   /* Boolean */
    sint32 previous_filtered_out;
    sint32 previous_switch_result;
    uint32 previous_integ_output;
    uint32 chrono_start_time;
} t_dds_m_linear_filter_s32;


/* Store data structure for macro DDS_M_FILTER_HYST_S16 */
typedef struct
{
    sint16 previous_output;
} t_dds_m_filter_hyst_s16;

/* Store data structure for macro DDS_M_FILTER_HYST_U16 */
typedef struct
{
    uint16 previous_output;
} t_dds_m_filter_hyst_u16;

/* Store data structure for macro DDS_M_FILTER_HYST_S32 */
typedef struct
{
    sint32 previous_output;
} t_dds_m_filter_hyst_s32;


/* Store data structure for macro DDS_M_ADAP_TRAN_TEMP_BLOC_S32 */
typedef struct
{
    uint32 pente_1_prev;
    uint32 pente_2_prev;
    uint8  acv_prev;
    uint8  output_flip_prev;
    sint32 in1_raw;
    sint32 in2_raw;
    t_dds_m_slew m_slew_str;
    t_dds_m_edge_detect m_sel_edge_str;
} t_dds_m_adapt_trans_tempo_s32;


/* Store data structure for macro DDS_M_FILTER_LP1_S32 */
typedef struct
{
    sint32 previous_error ;
    union
    {
        sint32 prev_S32;
        uint32 prev_U32;
    }previous_output;
}t_dds_m_filter_lp1_s32;


/* Store data structure for macro DDS_M_MEM_EXTINI_U16 */
typedef struct
{
    union
    {
        sint16 prev_S16;
        uint16 prev_U16;
    }previous_output;
}t_dds_m_mem_extini_16;

/* Store data structure for macro DDS_M_MEM_EXTINI_U32 */
typedef struct
{
    union
    {
        sint32 prev_S32;
        uint32 prev_U32;
    }previous_output;
}t_dds_m_mem_extini_32;

/* Store data structure for macro DDS_M_2ND_ORDER_FILTER_S16   */
typedef struct
{
    sint32 previous_output_1;
    sint32 previous_output_2;
    sint32 b0_error;
    sint32 b1_error;
    sint32 b2_error;
    sint32 a0_error;
    sint32 a1_error;
    sint32 a2_error;
    sint16 previous_input_1;
    sint16 previous_input_2;
} t_dds_m_2nd_order_filter_s16;


/* Store data structure for macro DDS_M_BACKLASH_S32 */
typedef struct
{
  sint32 previous_output;
} t_dds_m_backlash_s32;


/* Size of buffer for macro DDS_M_VARIABLE_TRANSPORT_DELAY_FAP */
#define DDS_M_VAR_TRANS_DELAY_FAP           (100)
/* Store data structure for macro DDS_M_VARIABLE_TRANSPORT_DELAY_FAP */
typedef struct{
    sint32 u_table_old[DDS_M_VAR_TRANS_DELAY_FAP]; /* Input Bin */
    uint32 Ivdt_table_old[DDS_M_VAR_TRANS_DELAY_FAP];/* BIN7 * DEC3 */
    sint32 output_prev;
    uint32 dT_min; /* DEC3 */
    uint32 dT_max; /* DEC3 */
    uint32 te_v_dly; /* BIN7 * DEC3 */
    uint32 dly_sum_dt; /* DEC3 */
    uint8 TrigSearch; /* flag : BIN0 */
    uint8 State; /* Status : BIN0 */
    uint8 idx; /* indice : BIN0 */
    uint8 init; /* indice : BIN0 */
} t_dds_m_var_trans_delay_fap;


/*----2-D Structures---*/

/* 2-D Tables SAV */
typedef struct
{
    uint8 ind_x;         /* Save last Index x position */
}t_dds_m_tab2d_sav;

/* 3-D Tables SAV */
typedef struct {
    uint8 ind_x;           /* Save last Index x position */
    uint8 ind_y;           /* Save last Index y position */
} t_dds_m_tab3d_sav;

typedef struct
{
    P2VAR(t_dds_m_tab2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* Pointer to SAV structure */
    uint8 size_x;                                             /* No of pairs */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) xval;               /* Pointer to start of x array */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) yval;               /* Pointer to start of y array */
} t_dds_m_tab2d_u8_v2;


typedef struct
{
    P2VAR(t_dds_m_tab2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* sav of values */
    uint8 size_x;          /* No of pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;           /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;           /* Pointer to start of y array */
} t_dds_m_tab2d_u16_v2;


typedef struct
{
    P2VAR(t_dds_m_tab2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* sav of values */
    uint8 size_x;          /* No of pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;           /* Pointer to start of x array */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;           /* Pointer to start of y array */
} t_dds_m_tab2d_s16;


typedef struct
{
    P2VAR(t_dds_m_tab2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* sav of values */
    uint8 size_x;          /* No of pairs */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;           /* Pointer to start of x array */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;           /* Pointer to start of y array */
} t_dds_m_tab2d_us16;

typedef struct
{
    P2VAR(t_dds_m_tab2d_sav, AUTOMATIC, AUTOMATIC) sav_ptr; /* sav of values */
    uint8 size_x;          /* No of pairs */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;           /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;           /* Pointer to start of y array */
} t_dds_m_tab2d_su16;

typedef struct
{
    P2VAR(t_dds_m_tab3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr;
    uint8 size_x;          /* No of pairs */
    uint8 size_y;
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;          /* Pointer to start of x array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) yval;          /* Pointer to start of y array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;          /* Pointer to start of z matrix */
}t_dds_m_tab3d_u16_v2;


typedef struct
{
    P2VAR(t_dds_m_tab3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr;
    uint8 size_x;          /* No of pairs */
    uint8 size_y;
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) xval;          /* Pointer to start of x array */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;          /* Pointer to start of y array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;          /* Pointer to start of z matrix */
}t_dds_m_tab3d_ssu16_v2;

typedef struct
{
    P2VAR(t_dds_m_tab3d_sav, AUTOMATIC, AUTOMATIC) sav_ptr;
    uint8 size_x;          /* No of pairs */
    uint8 size_y;
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) xval;          /* Pointer to start of x array */
    P2VAR(sint16, AUTOMATIC, AUTOMATIC) yval;          /* Pointer to start of y array */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) zmat;          /* Pointer to start of z matrix */
}t_dds_m_tab3d_usu16_v2;

/*******************************************************************************
* MACRO Definitions
*******************************************************************************/
/*******************************************************************************
*  Macro name:  DDS_M_POSITIVE_DECREMENT
*
*  The following macro will return "input - dec" if the result is positive or "0" if not.
*
*  input : variable that need to be decremented. This variable must be positive
*  dec   : decrement variable
*
*******************************************************************************/
#define DDS_M_POSITIVE_DECREMENT(input, dec) (((dec) < (input))?((input) - (dec)):0)

/*******************************************************************************
*  Macro name:  DDS_M_LIMITED_DECREMENT
*
*  The following macro will return max(input - dec, limit).
*
*  input : variable that need to be decremented.
*  dec   : decrement variable
*  limit : max value of incrementation result. must be inferior of dec
*
*******************************************************************************/
#define DDS_M_LIMITED_DECREMENT(input, dec, limit) ((((limit) + (dec)) < (input))?((input) - (dec)):(limit))

/*******************************************************************************
*  Macro name:  DDS_M_LIMITED_INCREMENT
*
*  The following macro will return min(input + inc, limit).
*
*  input : variable that need to be decremented.
*  inc   : increment variable
*  limit : max value of incrementation result. must be superior of inc
*
*******************************************************************************/
#define DDS_M_LIMITED_INCREMENT(input, inc, limit) ((((limit) - (inc)) > (input))?((input) + (inc)):(limit))

/*******************************************************************************
*  Macro name:  DDS_M_INV_BOOL_TYPE
*
*  The following macro will return the inverse value of input_bt passed to it.
*
*  input_bt must be of type BOOL_TYPE
*
*******************************************************************************/
#define DDS_M_INV_BOOL_TYPE(input_bt) (((input_bt)==(DDS_FALSE))?(DDS_TRUE):(DDS_FALSE))


/*******************************************************************************
*  Macro name:  DDS_M_ABS
*
*  The following macro will return the absolut value of input value.
*
*******************************************************************************/
#define DDS_M_ABS(input)   (((input)<0)?(-(input)):(input))

/*******************************************************************************
*  Macro name:  DDS_M_SIGN
*
*  The following macro will return the input signe, 0 if input is positiv, 1 if it is negativ.
*
*******************************************************************************/
#define DDS_M_SIGN(input)   (((input) < 0)?(1):(0))

/*******************************************************************************
*  Macro name:  DDS_M_MIN
*
*  The following macro will return the minimum of two variables passed to it.
*
*  input_a and input_b must be
*  of the same type and BIN Point.
*******************************************************************************/
#define DDS_M_MIN(input_a, input_b)   (((input_a)<(input_b))?(input_a):(input_b))


/*******************************************************************************
*  Macro name:   DDS_M_MAX
*
*  The following macro will return the maximum of two variables
*  passed to it.
*
*  input_a and input_b must be
*  of the same type and BIN Point.
*******************************************************************************/
#define DDS_M_MAX(input_a, input_b)   (((input_a)>(input_b))?(input_a):(input_b))


/*******************************************************************************
*  Macro name:   DDS_M_LIMIT_V1
*
*  The following macro will limit a variable between an upper
*  and lower limit.
*
*  If input is greater than upper_limit then
*   Return upper_limit.
*  Else If input is less than lower_limit then
*   Return lower_limit
*  Else
*   Return input
*
*   that gives :
*    if lower_limit <= input <= upper_limit , else return input
*    if input <= lower_limit <= upper_limit , else return lower_limit
*    if lower_limit <= upper_limit <= input , else return upper_limit
*    if input <= upper_limit <= lower_limit , else return lower_limit
*    if upper_limit <= input <= lower_limit , else return upper_limit
*    if upper_limit <= lower_limit <= input , else return upper_limit
*
*  input, lower_limit and upper_limit must be
*  of the same type and BIN Point.
*******************************************************************************/
#define DDS_M_LIMIT_V1(input, lower_limit, upper_limit) \
    (((input)>(upper_limit))?(upper_limit)\
    :(((input)<(lower_limit))?(lower_limit)\
    :(input)))

/* to keep old definition */
#define DDS_M_LIMIT DDS_M_LIMIT_V1


/*******************************************************************************
*  Macro name:   DDS_M_SATURATION_V1
*
*  The following macro will limit a variable between an upper
*  and lower limit.
*
*  If input is lower than lower_limit then
*   Return lower_limit.
*  Else If input is higher than upper_limit then
*   Return upper_limit
*  Else
*   Return input
*
*   that gives :
*    if lower_limit <= input <= upper_limit , else return input
*    if input <= lower_limit <= upper_limit , else return lower_limit
*    if lower_limit <= upper_limit <= input , else return upper_limit
*    if input <= upper_limit <= lower_limit , else return lower_limit
*    if upper_limit <= input <= lower_limit , else return lower_limit
*    if upper_limit <= lower_limit <= input , else return upper_limit
*
*  input, lower_limit and upper_limit must be
*  of the same type and BIN Point.
*******************************************************************************/
#define DDS_M_SATURATION_V1(input, lower_limit, upper_limit) \
    (((input)<(lower_limit))?(lower_limit)\
    :(((input)>(upper_limit))?(upper_limit)\
    :(input)))

/* to keep old definition */
#define DDS_M_SATURATION DDS_M_SATURATION_V1

/*******************************************************************************
*  Macro name:   DDS_M_LIMIT_V2
*
*  The following macro will limit a variable between an upper
*  and lower limit.
*
*  Return MAX(lower_limit , MIN(input , upper_limit))
*   that gives :
*    if lower_limit <= input <= upper_limit , else return input
*    if input <= lower_limit <= upper_limit , else return lower_limit
*    if lower_limit <= upper_limit <= input , else return upper_limit
*    if input <= upper_limit <= lower_limit , else return lower_limit
*    if upper_limit <= input <= lower_limit , else return lower_limit
*    if upper_limit <= lower_limit <= input , else return lower_limit
*
*  input, lower_limit and upper_limit must be
*  of the same type and BIN Point.
*******************************************************************************/
#define DDS_M_LIMIT_V2(input, lower_limit, upper_limit) \
    (DDS_M_MAX(lower_limit , DDS_M_MIN(input , upper_limit)))


/*******************************************************************************
*  Macro name:   DDS_M_SATURATION_V2
*
*  The following macro will limit a variable between an upper
*  and lower limit.
*
*  Return MIN(upper_limit , MAX(input , lower_limit))
*   that gives :
*    if lower_limit <= input <= upper_limit , else return input
*    if input <= lower_limit <= upper_limit , else return lower_limit
*    if lower_limit <= upper_limit <= input , else return upper_limit
*    if input <= upper_limit <= lower_limit , else return upper_limit
*    if upper_limit <= input <= lower_limit , else return upper_limit
*    if upper_limit <= lower_limit <= input , else return upper_limit
*
*  input, lower_limit and upper_limit must be
*  of the same type and BIN Point.
*******************************************************************************/
#define DDS_M_SATURATION_V2(input, lower_limit, upper_limit) \
    (DDS_M_MIN(upper_limit , DDS_M_MAX(input , lower_limit)))


/*******************************************************************************
*  Macro name:  DDS_M_GET_BITFIELD
*
*  Extract the value of a bit field.
*  carrier is the variable holding the bitfield
*  msb is the position of the highest bit of the bitfield
*  lsb is the position of the lowest bit of the bitfield
*  carrier, msb and lsb shall be unsigned
*
*******************************************************************************/
#define DDS_M_GET_BITFIELD(carrier, msb, lsb)\
    ( \
    ((uint32)(carrier) >> (uint32)(lsb)) & (((uint32)1<<((uint32)((msb)-(lsb)+1)))-(uint32)1) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_GET32
*
*  Extract the value of a bit field with a carrier of type U32.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of get
*
*******************************************************************************/
#define DDS_M_BIT_GET32(carrier, pos)\
    ( \
    (((carrier >>  (uint32)(pos)) & (uint32)1)  == 0)? (DDS_FALSE):(DDS_TRUE) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_GET16
*
*  Extract the value of a bit field with a carrier of type U16.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of get
*
*******************************************************************************/
#define DDS_M_BIT_GET16(carrier, pos)\
    ( \
    ((((uint32)(carrier) >>  (uint32)(pos)) & (uint32)1)  == 0)? (DDS_FALSE):(DDS_TRUE) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_GET8
*
*  Extract the value of a bit field with a carrier of type U8.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of get
*
*******************************************************************************/
#define DDS_M_BIT_GET8(carrier, pos)\
    ( \
    ((((uint32)(carrier) >>  (uint32)(pos)) & (uint32)1)  == (uint32)0)? (DDS_FALSE):(DDS_TRUE) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_SET32
*
*  Set the value of a bit field with a carrier of type U32.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of set
*
*******************************************************************************/
#define DDS_M_BIT_SET32(carrier, pos)\
    ( \
    (carrier) = (carrier) | ((uint32)1<<((uint32)(pos))) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_CLR32
*
*  Clear the value of a bit field with a carrier of type U32.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of clear
*
*******************************************************************************/
#define DDS_M_BIT_CLR32(carrier, pos)\
    ( \
    (carrier) = (carrier) & (~((uint32)1<<((uint32)(pos)))) \
    )


/*******************************************************************************
*  Macro name:  M_BIT_SET16
*
*  Set the value of a bit field with a carrier of type U16.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of set
*
*******************************************************************************/
#define DDS_M_BIT_SET16(carrier, pos)\
    ( \
    (carrier) = (uint16)((uint32)(carrier) | ((uint32)1<<((uint32)(pos)))) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_CLR16
*
*  Clear the value of a bit field with a carrier of type U16.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of clear
*
*******************************************************************************/
#define DDS_M_BIT_CLR16(carrier, pos)\
    ( \
    (carrier) = (uint16)((uint32)(carrier) & (~((uint32)1<<((uint32)(pos))))) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_SET8
*
*  Set the value of a bit field with a carrier of type U8.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of set
*
*******************************************************************************/
#define DDS_M_BIT_SET8(carrier, pos)\
    ( \
    (carrier) = (uint8)((uint32)(carrier) | ((uint32)1<<((uint32)(pos)))) \
    )


/*******************************************************************************
*  Macro name:  DDS_M_BIT_CLR8
*
*  Clear the value of a bit field with a carrier of type U8.
*  carrier is the variable holding the bitfield
*  pos is the position of the bit of clear
*
*******************************************************************************/
#define DDS_M_BIT_CLR8(carrier, pos)\
    ( \
    (carrier) = (uint8)((uint32)(carrier) & (~((uint32)1<<((uint32)(pos))))) \
    )


/*******************************************************************************
*  Macro name:   DDS_M_CONVERT_BOOL_TO_UINT8
*
*  The following macro convert "Boolean" value FALSE/TRUE
*  to "uint8" value DDS_FALSE/DDS_TRUE.
*
*******************************************************************************/
#define DDS_M_CONVERT_BOOL_TO_UINT8(input_bt) (((input_bt)==(FALSE))?(DDS_FALSE):(DDS_TRUE))


/*******************************************************************************
*  Macro name:   DDS_M_CONVERT_UINT8_TO_BOOL
*
*  The following macro convert "uint8" value DDS_FALSE/DDS_TRUE
*  to "Boolean" value FALSE/TRUE.
*
*******************************************************************************/
#define DDS_M_CONVERT_UINT8_TO_BOOL(input_u8) (((input_u8)==(DDS_FALSE))?(FALSE):(TRUE))


/*******************************************************************************
*  Macro name:  DDS_M_OUT_SCALED_CALC
*
*  The following macro is used to minimize the loss of precision in a
*  scaler division.
*  error = (coeff a * coeff b) % scaler
*  result = ((coeff a * coeff b) + error) / scaler
*
*******************************************************************************/


#define DDS_M_OUT_SCALED_CALC(coeff_ab,scaler,error_calc,tmp_out_scaled) \
                       (((tmp_out_scaled) =((coeff_ab) + (error_calc))) / (scaler));\
                       if((tmp_out_scaled) >= 0) \
                       {\
                            ((error_calc) = (tmp_out_scaled) % (scaler));\
                       }\
                       else\
                       {\
                            ((error_calc) = -((-(tmp_out_scaled)) % (scaler)));\
                       }


/*******************************************************************************
*  Macro name:  OUT_SCALED_CALC_PROT_S32
*
*  The following macro is used to minimize the loss of precision in a
*  scaler division.
*  error = (coeff a * coeff b) % scaler
*  result = ((coeff a * coeff b) + error) / scaler
*
*  This version manage possible overflow for the sum :
*   coeff_ab + error_calc
*******************************************************************************/
#define DDS_M_OUT_SCALED_CALC_PROT_S32(result,coeff_ab,scaler,error_calc)                               \
{                                                                                                       \
    sint32 tmp_out_scaled_prot;                                                                         \
                                                                                                        \
    if((error_calc) >= 0)                                                                               \
    {                                                                                                   \
        if((coeff_ab) <= (DDS_SINT32_MAX - (error_calc)))                                               \
        {                                                                                               \
            (result) = DDS_M_OUT_SCALED_CALC((coeff_ab),(scaler),(error_calc),(tmp_out_scaled_prot));   \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            sint32 new_err;                                                                             \
                                                                                                        \
            /* Remove from error the part of error that is possible to add to tmp_out_scaled */         \
            (error_calc) -= (DDS_SINT32_MAX - (coeff_ab));                                              \
                                                                                                        \
            /* Saturate tmp_out_scaled */                                                               \
            (tmp_out_scaled_prot) = DDS_SINT32_MAX;                                                     \
                                                                                                        \
            (result) = (tmp_out_scaled_prot) / (scaler);                                                \
                                                                                                        \
            /* Calculate new error */                                                                   \
            (new_err) = (tmp_out_scaled_prot) % (scaler);                                               \
                                                                                                        \
            if((error_calc) < ((scaler) - (new_err)))                                                   \
            {                                                                                           \
                (error_calc) += (new_err);                                                              \
            }                                                                                           \
            else                                                                                        \
            {                                                                                           \
                (error_calc) -= (scaler);                                                               \
                (error_calc) += (new_err);                                                              \
                (result)++;                                                                             \
            }                                                                                           \
        }                                                                                               \
    }                                                                                                   \
                                                                                                        \
    else                                                                                                \
    {                                                                                                   \
        if((coeff_ab) >= (-DDS_SINT32_MAX - (error_calc)))                                              \
        {                                                                                               \
            (result) = DDS_M_OUT_SCALED_CALC((coeff_ab),(scaler),(error_calc),(tmp_out_scaled_prot));   \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            sint32 (new_err);                                                                           \
                                                                                                        \
            /* Remove from error the part of error that is possible to add to tmp_out_scaled */         \
            (error_calc) -= (-DDS_SINT32_MAX - (coeff_ab));                                             \
                                                                                                        \
            /* Saturate tmp_out_scaled */                                                               \
            (tmp_out_scaled_prot) = -DDS_SINT32_MAX;                                                    \
                                                                                                        \
            (result) = (tmp_out_scaled_prot) / (scaler);                                                \
                                                                                                        \
            /* Calculate new error */                                                                   \
            (new_err) = -((-(tmp_out_scaled_prot)) % (scaler));                                         \
                                                                                                        \
            if((error_calc) > (-(scaler) - (new_err)))                                                  \
            {                                                                                           \
                (error_calc) += (new_err);                                                              \
            }                                                                                           \
            else                                                                                        \
            {                                                                                           \
                (error_calc) += (scaler);                                                               \
                (error_calc) += (new_err);                                                              \
                result--;                                                                               \
            }                                                                                           \
        }                                                                                               \
    }                                                                                                   \
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
extern FUNC(uint8, AUTOMATIC) DDS_M_POS_NEG_EDGE_DETECT_INIT(CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                                                                uint8 init_value);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_POSITIVE_EDGE_DETECT(
                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                uint8 input);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_NEGATIVE_EDGE_DETECT(
                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                uint8 input);

/*******************************************************************************
*  Library Function Prototypes
*******************************************************************************/

/*******************************************************************************
*  Macro name:  DDS_M_ADDITION_S32
*
* out = in1 + in2
*
* if out > DDS_SINT32_MAX --> out = DDS_SINT32_MAX
* if out < -(2^31)        --> out = -(2^31)
*
* WARNING: in the case of "DDS_SINT32_MIN" is different from "-(2^31)" a limit
*          should be use after the use of this function.
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_ADDITION_S32(sint32 in1, sint32 in2);

/*******************************************************************************
*  Macro name:  DDS_M_ADDITION_U32
*
* out = in1 + in2
*
* if out > DDS_UINT32_MAX --> out = DDS_UINT32_MAX
*
*******************************************************************************/
extern FUNC(uint32, AUTOMATIC) DDS_M_ADDITION_U32(uint32 in1, uint32 in2);


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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY(uint8 input, /* Boolean */
                                        uint32 current_time,
                                        uint32 delay,
                                        CONSTP2VAR(t_dds_m_turn_on_delay_type, AUTOMATIC, AUTOMATIC) turn_on_delay_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY_INIT(uint8 init_value,
                                        CONSTP2VAR(t_dds_m_turn_on_delay_type, AUTOMATIC, AUTOMATIC) turn_on_delay_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY(uint8 input, /* Boolean */
                                        uint32 current_time,
                                        uint32 delay,
                                        CONSTP2VAR(t_dds_m_turn_off_delay_type, AUTOMATIC, AUTOMATIC) turn_off_delay_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY_INIT(uint8 init_value, /* Boolean */
                                        CONSTP2VAR(t_dds_m_turn_off_delay_type, AUTOMATIC, AUTOMATIC) turn_off_delay_struct_ptr);


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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY_DELTA(uint8 input, /* Boolean */
                   uint32 increment_time_delta,
                   uint32 delay,
                   CONSTP2VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_delay_delta_struct_ptr);



/*******************************************************************************
*  Macro name: DDS_M_TURN_ON_DELAY_DELTA_INIT
*
*  Description :
*  The following macro manage init of M_TURN_ON_DELAY_DELTA function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of TURN_ON_DELAY_DELTA
*   turn_on_delay_delta_struct_ptr is the structure associated to macro
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_DELAY_DELTA_INIT(uint8 init_value, /* Boolean */
                   CONSTP2VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_delay_delta_struct_ptr);


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
*   current_time and delay must be of the same type and BIN Point
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY_DELTA(uint8 input, /* Boolean */
                                        uint32 increment_time_delta,
                                        uint32 delay,
                                        CONSTP2VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_off_delay_delta_struct_ptr);

/*******************************************************************************
*  Macro name: DDS_M_TURN_OFF_DELAY_DELTA_INIT
*
*  Description :
*  The following macro manage init of M_TURN_OFF_DELAY_DELTA function
*
*  previous_input  = init_value
*  previous_output = init_value
*
*  Where:
*   init_value is the int value of TURN_OFF_DELAY_DELTA
*   turn_off_delay_delta_struct_ptr is the structure associated to macro
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_OFF_DELAY_DELTA_INIT(uint8 init_value, /* Boolean */
                                        CONSTP2VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_off_delay_delta_struct_ptr);



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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY(uint8 input, /* Boolean */
                                        uint32 current_time,
                                        uint32 delay_on,
                                        uint32 delay_off,
                                        CONSTP2VAR(t_dds_m_turn_on_off_delay_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_struct_ptr);


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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY_INIT(uint8 init_value, /* Boolean */
                                        CONSTP2VAR(t_dds_m_turn_on_off_delay_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_struct_ptr);


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
extern FUNC(uint8, AUTOMATIC) DDS_M_TURN_ON_OFF_DELAY_DELTA(uint8 input, /* Boolean */
                   uint32 increment_time_delta,
                   uint32 delay_on,
                   uint32 delay_off,
                   CONSTP2VAR(t_dds_m_turn_on_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_delta_struct_ptr);

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
                   CONSTP2VAR(t_dds_m_turn_on_off_delay_delta_type, AUTOMATIC, AUTOMATIC) turn_on_off_delay_delta_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TIMER(uint32 current_time,
                                        uint32 timer_duration,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TIMER_INIT(uint32 current_time,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_U16(uint32 current_time,
                                        uint32 timer_duration,
                                        CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) time_passed,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_INIT_U16(uint32 current_time,
                                        CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) time_passed,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_U32(uint32 current_time,
                                        uint32 timer_duration,
                                        CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) time_passed,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_TIMER_DISP_INIT_U32(uint32 current_time,
                                        CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) time_passed,
                                        CONSTP2VAR(t_dds_m_timer_type, AUTOMATIC, AUTOMATIC) timer_struct_ptr);


/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_V1_U16
*  Description     :    U16 2-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_TAB2D_U16_V1(CONSTP2CONST(t_dds_m_tab2d_u16, AUTOMATIC, AUTOMATIC) table,
                                        uint16 x);

#define DDS_M_TAB2D_U16 DDS_M_TAB2D_U16_V1

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

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_U16 ( CONSTP2CONST(t_dds_m_map2d_u16, AUTOMATIC, AUTOMATIC) map,
                                                 uint16 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_U8 ( CONSTP2CONST(t_dds_m_map2d_u8, AUTOMATIC, AUTOMATIC) map,
                                                 uint8 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U8U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_U8U16 ( CONSTP2CONST(t_dds_m_map2d_u8u16, AUTOMATIC, AUTOMATIC) map,
                                                            uint8 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16U8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_U16U8 ( CONSTP2CONST(t_dds_m_map2d_u16u8, AUTOMATIC, AUTOMATIC) map,
                                                            uint16 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP2D_S16 ( CONSTP2CONST(t_dds_m_map2d_s16, AUTOMATIC, AUTOMATIC) map,
                                                 sint16 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_MAP2D_S8 ( CONSTP2CONST(t_dds_m_map2d_s8, AUTOMATIC, AUTOMATIC) map,
                                                 sint8 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_SU16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_SU16 ( CONSTP2CONST(t_dds_m_map2d_su16, AUTOMATIC, AUTOMATIC) map,
                                                  sint16 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16U8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_S16U8 ( CONSTP2CONST(t_dds_m_map2d_s16u8, AUTOMATIC, AUTOMATIC) map,
                                                  sint16 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16S8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_MAP2D_S16S8 ( CONSTP2CONST(t_dds_m_map2d_s16s8, AUTOMATIC, AUTOMATIC) map /* 2 dimensional map */,
                                                  sint16 x /* x value */ );


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_SU8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_MAP2D_SU8 ( CONSTP2CONST(t_dds_m_map2d_su8, AUTOMATIC, AUTOMATIC) map,
                                                  sint8 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_US8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_MAP2D_US8 ( CONSTP2CONST(t_dds_m_map2d_us8, AUTOMATIC, AUTOMATIC) map,
                                                  uint8 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S8U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP2D_S8U16 ( CONSTP2CONST(t_dds_m_map2d_s8u16, AUTOMATIC, AUTOMATIC) map,
                                                  sint8 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_US16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP2D_US16 ( CONSTP2CONST(t_dds_m_map2d_us16, AUTOMATIC, AUTOMATIC) map,
                                                  uint16 x );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16U32
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint32, AUTOMATIC) DDS_M_MAP2D_U16U32 ( CONSTP2CONST(t_dds_m_map2d_u16u32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           uint16 x /* x value */ );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16S32
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_MAP2D_U16S32 ( CONSTP2CONST(t_dds_m_map2d_u16s32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           uint16 x /* x value */ );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_S16U32
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint32, AUTOMATIC) DDS_M_MAP2D_S16U32 ( CONSTP2CONST(t_dds_m_map2d_s16u32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           sint16 x /* x value */ );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP2D_U16S32
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_MAP2D_S16S32 ( CONSTP2CONST(t_dds_m_map2d_s16s32, AUTOMATIC, AUTOMATIC) map /* 2 dimensional table */,
                                           sint16 x /* x value */ );

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

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U16 ( CONSTP2CONST(t_dds_m_map3d_u16, AUTOMATIC, AUTOMATIC) map,
                                                 uint16 x,
                                                 uint16 y );
/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8U8U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U8U8U16( CONSTP2CONST(t_dds_m_map3d_u8u8u16, AUTOMATIC, AUTOMATIC) map,
                                                     uint8 x,
                                                     uint8 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16S16S8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_MAP3D_U16S16S8( CONSTP2CONST(t_dds_m_map3d_u16s16s8, AUTOMATIC, AUTOMATIC) map,
                                                     uint16 x,
                                                     sint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8U8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_MAP3D_U16U8U8 ( CONSTP2CONST(t_dds_m_map3d_u16u8u8, AUTOMATIC, AUTOMATIC) map,
                                                    uint16 x,
                                                    uint8 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8S8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_MAP3D_U16U8S8 ( CONSTP2CONST(t_dds_m_map3d_u16u8s8, AUTOMATIC, AUTOMATIC) map,
                                                    uint16 x,
                                                    uint8 y );


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_UUS8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_MAP3D_UUS8 ( CONSTP2CONST(t_dds_m_map3d_uus8, AUTOMATIC, AUTOMATIC) map,
                                                   uint8 x,
                                                   uint8 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_MAP3D_U8 ( CONSTP2CONST(t_dds_m_map3d_u8, AUTOMATIC, AUTOMATIC) map,
                                                 uint8 x,
                                                 uint8 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_S16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_S16 ( CONSTP2CONST(t_dds_m_map3d_s16, AUTOMATIC, AUTOMATIC) map,
                                                 sint16 x,
                                                 sint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_SUS16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_SUS16 ( CONSTP2CONST(t_dds_m_map3d_sus16, AUTOMATIC, AUTOMATIC) map,
                                                   sint16 x,
                                                   uint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_USS16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_USS16 ( CONSTP2CONST(t_dds_m_map3d_uss16, AUTOMATIC, AUTOMATIC) map,
                                                   uint16 x,
                                                   sint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_SUU16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_SUU16 ( CONSTP2CONST(t_dds_m_map3d_suu16, AUTOMATIC, AUTOMATIC) map,
                                                   sint16 x,
                                                   uint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_USU16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_USU16 ( CONSTP2CONST(t_dds_m_map3d_usu16, AUTOMATIC, AUTOMATIC) map,
                                                   uint16 x,
                                                   sint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_SSU16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_SSU16 ( CONSTP2CONST(t_dds_m_map3d_ssu16, AUTOMATIC, AUTOMATIC) map,
                                                   sint16 x,
                                                   sint16 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_UUS16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_UUS16 ( CONSTP2CONST(t_dds_m_map3d_uus16, AUTOMATIC, AUTOMATIC) map,
                                                   uint16 x,
                                                   uint16 y );



/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8U16U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U8U16U16 ( CONSTP2CONST(t_dds_m_map3d_u8u16u16, AUTOMATIC, AUTOMATIC) map,
                                                      uint8 x,
                                                      uint16 y );


 /*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U8U16S16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_U8U16S16 ( CONSTP2CONST(t_dds_m_map3d_u8u16s16, AUTOMATIC, AUTOMATIC) map,
                                                      uint8 x,
                                                      uint16 y );


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_U16U8U16 ( CONSTP2CONST(t_dds_m_map3d_u16u8u16, AUTOMATIC, AUTOMATIC) map,
                                                      uint16 x,
                                                      uint8 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_U16U8S16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_U16U8S16 ( CONSTP2CONST(t_dds_m_map3d_u16u8s16, AUTOMATIC, AUTOMATIC) map,
                                                      uint16 x,
                                                      uint8 y );


/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_S16U8S16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_MAP3D_S16U8S16 ( CONSTP2CONST(t_dds_m_map3d_s16u8s16, AUTOMATIC, AUTOMATIC) map,
                                                      sint16 x,
                                                      uint8 y );

/*******************************************************************************
*
*  Function Name   :    DDS_M_MAP3D_S16U8U16
*  Description     :    see above comment
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_MAP3D_S16U8U16 ( CONSTP2CONST(t_dds_m_map3d_s16u8u16, AUTOMATIC, AUTOMATIC) map,
                                                      sint16 x,
                                                      uint8 y );

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
extern FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_32(  CONSTP2VAR(t_dds_m_integrate_32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                    uint32 current_time,
                                                    uint32 input_value );

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
extern FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_32_INIT( CONSTP2VAR(t_dds_m_integrate_32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                        uint32 current_time,
                                                        uint32 init_value );

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
extern FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_S16U32(CONSTP2VAR(t_dds_m_integrate_s16u32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                uint32 current_time,
                                                sint16 input_value);


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
extern FUNC(uint32, AUTOMATIC) DDS_M_INTEGRATE_S16U32_INIT(CONSTP2VAR(t_dds_m_integrate_s16u32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                uint32 current_time,
                                                uint32 input_init_value);

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
extern FUNC(uint16, AUTOMATIC) DDS_M_INTEGRATE_16EXT32( CONSTP2VAR(t_dds_m_integrate_16ext32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                        uint32 current_time,
                                                        uint16 input_value );

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
extern FUNC(uint16, AUTOMATIC) DDS_M_INTEGRATE_16EXT32_INIT(CONSTP2VAR(t_dds_m_integrate_16ext32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                            uint32 current_time,
                                                            P2VAR (uint16, AUTOMATIC, AUTOMATIC) integrate_high_output_ptr,
                                                            P2VAR (uint32, AUTOMATIC, AUTOMATIC) integrate_low_output_ptr,
                                                            uint16 high_output_init_value,
                                                            uint32 low_output_init_value,
                                                            uint32 output_step_value );

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
extern FUNC(void, AUTOMATIC) DDS_M_INTEGRATE_16EXT32_PTR_INIT(CONSTP2VAR(t_dds_m_integrate_16ext32, AUTOMATIC, AUTOMATIC) integrate_struct_ptr,
                                                            P2VAR (uint16, AUTOMATIC, AUTOMATIC) integrate_high_output_ptr,
                                                            P2VAR (uint32, AUTOMATIC, AUTOMATIC) integrate_low_output_ptr);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_SUM_S32EXT32(
        CONSTP2VAR(t_dds_m_sum_s32ext32, AUTOMATIC, AUTOMATIC) sum_struct_ptr,
        sint32 input_value);

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
extern FUNC(void, AUTOMATIC) DDS_M_SUM_S32EXT32_INIT(
        CONSTP2VAR(t_dds_m_sum_s32ext32, AUTOMATIC, AUTOMATIC) sum_struct_ptr,
        sint32 high_output_init_value,
        sint32 low_output_init_value,
        uint32 step);

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
extern FUNC(void, AUTOMATIC) DDS_M_SUM_S32EXT32_SAT_INIT(
            CONSTP2VAR(t_dds_m_sum_s32ext32, AUTOMATIC, AUTOMATIC) sum_struct_ptr,
            sint32 high_output_init_value,
            sint32 low_output_init_value,
            uint32 step,
            sint32 saturation_min,
            sint32 saturation_max);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_CHECK_DELTA16( CONSTP2VAR(t_dds_m_check_delta16, AUTOMATIC, AUTOMATIC) check_delta16_struct_ptr,
                                                    uint16 input_value );

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
extern FUNC(uint16, AUTOMATIC) DDS_M_CHECK_DELTA16_INIT( CONSTP2VAR(t_dds_m_check_delta16, AUTOMATIC, AUTOMATIC) check_delta16_struct_ptr,
                                                        uint16 init_value,
                                                        uint16 delta_max_value );

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
extern FUNC(uint16, AUTOMATIC) DDS_M_CALC_MEAN_BUFFER( CONSTP2VAR(t_dds_m_calc_mean_buffer, AUTOMATIC, AUTOMATIC) calc_mean_buffer_ptr,
                                                        uint16 input_value,
                                                        uint8  nb_data_for_mean );

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
extern FUNC(uint16, AUTOMATIC) DDS_M_CALC_MEAN_BUFFER_INIT( CONSTP2VAR(t_dds_m_calc_mean_buffer, AUTOMATIC, AUTOMATIC) calc_mean_buffer_ptr,
                                                            P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_ptr,
                                                            P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_init_ptr,
                                                            uint8 tab_size,
                                                            uint8 nb_data_for_mean );

/*******************************************************************************
*  Macro name:  DDS_M_U16_CALC_MEAN_SHIFTED
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
extern FUNC(uint16, AUTOMATIC) DDS_M_U16_CALC_MEAN_SHIFTED_V1(
        CONSTP2VAR(t_dds_m_u16_calc_mean_shifted, AUTOMATIC, AUTOMATIC) calc_mean_shifted_ptr,
        uint16 input_value,
        uint8  nb_data_for_mean );

/* to keep old declaration */
#define DDS_M_U16_CALC_MEAN_SHIFTED  DDS_M_U16_CALC_MEAN_SHIFTED_V1

/*******************************************************************************
*  Macro name:  DDS_M_U16_CALC_MEAN_SHIFTED_INIT
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
extern FUNC(uint16, AUTOMATIC) DDS_M_U16_CALC_MEAN_SHIFTED_V1_INIT(
        CONSTP2VAR(t_dds_m_u16_calc_mean_shifted, AUTOMATIC, AUTOMATIC) calc_mean_shifted_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_ptr,
        uint16 first_value,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_init_ptr,
        uint8 tab_size,
        uint8 nb_data_for_mean);

/* to keep old declaration */
#define DDS_M_U16_CALC_MEAN_SHIFTED_INIT  DDS_M_U16_CALC_MEAN_SHIFTED_V1_INIT

/*******************************************************************************
*  Macro name:  DDS_M_U16_CALC_MEAN_SHIFTED_V2
*
* It's the same as DDS_M_U16_CALC_MEAN_SHIFTED
*
*******************************************************************************/
#define DDS_M_U16_CALC_MEAN_SHIFTED_V2  DDS_M_U16_CALC_MEAN_SHIFTED

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
extern FUNC(uint16, AUTOMATIC) DDS_M_U16_CALC_MEAN_SHIFTED_V2_INIT(
        CONSTP2VAR(t_dds_m_u16_calc_mean_shifted, AUTOMATIC, AUTOMATIC) calc_mean_shifted_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_ptr,
        P2VAR(uint16, AUTOMATIC, AUTOMATIC) tab_init_ptr,
        uint8 tab_size,
        uint8 nb_data_for_mean);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_SLEW_S32(  CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC) slew_struct_ptr,
                                                sint32 input,
                                                uint32 up_rate,
                                                uint32 down_rate );


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
extern FUNC(sint32, AUTOMATIC) DDS_M_SLEW_S32_INIT( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC) slew_struct_ptr,
                                                    sint32 init_value );

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
extern FUNC(uint32, AUTOMATIC) DDS_M_SLEW_U32( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC)slew_struct_ptr,
                                                uint32 input,
                                                uint32 up_rate,
                                                uint32 down_rate );

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
extern FUNC(uint32, AUTOMATIC) DDS_M_SLEW_U32_INIT( CONSTP2VAR(t_dds_m_slew, AUTOMATIC, AUTOMATIC)slew_struct_ptr,
                                                uint32 init_value );

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
extern FUNC(sint16, AUTOMATIC) DDS_M_BARY_FILTER_S16(sint16 inp_bary_1,
                                                     sint16 inp_bary_2,
                                                     sint16 in_coef_bary,
                                                     uint16 bp_filter_factor);

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
*   1°/ inp_bary_1 and inp_bary_2  must have the same Binpoint!!!
*   2°/ -(2^31) is used instead of"DDS_SINT32_MIN", in consequence if these 2
*       values are different a limit should be use after the use of this function.
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_BARY_FILTER_S32(sint32 inp_bary_1,
                                              sint32 inp_bary_2,
                                              uint16 in_coef_bary,
                                              uint16 bp_filter_factor);


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
extern FUNC(sint16, AUTOMATIC) DDS_M_BARY_FILTER_S16_V2(sint16 inp_bary_1,
                                                     sint16 inp_bary_2,
                                                     sint16 in_coef_bary,
                                                     uint16 bp_filter_factor);

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
*   1°/ inp_bary_1 and inp_bary_2  must have the same Binpoint!!!
*   2°/ -(2^31) is used instead of"DDS_SINT32_MIN", in consequence if these 2
*       values are different a limit should be use after the use of this function.
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_BARY_FILTER_S32_V2(sint32 inp_bary_1,
                                              sint32 inp_bary_2,
                                              uint16 in_coef_bary,
                                              uint16 bp_filter_factor);

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
extern FUNC(uint32, AUTOMATIC) DDS_M_CHRONOMETER_U32( CONSTP2VAR(t_dds_m_chrono_u32, AUTOMATIC, AUTOMATIC) chrono_struct_ptr,
                                                    uint32 current_time,
                                                    uint8 enable_cond );

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
extern FUNC(uint32, AUTOMATIC) DDS_M_CHRONOMETER_U32_INIT(  CONSTP2VAR(t_dds_m_chrono_u32, AUTOMATIC, AUTOMATIC) chrono_struct_ptr,
                                                            uint32 current_time,
                                                            uint32 init_value );

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
extern FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                    uint16 target,
                                                    uint16 filter_factor,
                                                    uint16 bp_filter_factor);

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
extern FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16_INIT(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                    uint16 init_value);


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
extern FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16_V2(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             uint16 target,
                                             uint16 filter_factor,
                                             uint16 bp_filter_factor);

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
extern FUNC(uint16, AUTOMATIC) DDS_M_FILTER_LP1_U16_V2_INIT(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                     CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) prev_ptr,
                                                     CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) error_ptr,
                                                     uint16 init_value,
                                                     sint32 error);

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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                    sint16 target,
                                                    uint16 filter_factor,
                                                    uint16 bp_filter_factor);

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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16_INIT(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                        sint16 init_value);

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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16_V2(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             sint16 target,
                                             uint16 filter_factor,
                                             uint16 bp_filter_factor);

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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_S16_V2_INIT(CONSTP2VAR(t_dds_m_filter_lp1_v2, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                     CONSTP2VAR(sint16, AUTOMATIC, AUTOMATIC) prev_ptr,
                                                     CONSTP2VAR(sint32, AUTOMATIC, AUTOMATIC) error_ptr,
                                                     sint16 init_value,
                                                     sint32 error);

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
extern FUNC(t_dds_m_edge_detected_event, AUTOMATIC) DDS_M_EDGE_DETECT_INIT(
                                                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                                                uint8 init_value);

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
extern FUNC(t_dds_m_edge_detected_event, AUTOMATIC) DDS_M_EDGE_DETECT(
                                                CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_struct_ptr,
                                                uint8 input);


/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1° It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2° It returns the signal value that has occured "time_delay" before.
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
*  REMARKS:
*   It is assume that this function is called every "scheduling_in_time_delay_res".
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V1(CONSTP2VAR(t_dds_m_sig_s16_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                sint16 input_sig_value,
                                                uint16 time_delay);

#define DDS_M_SIGNAL_S16_DELAY DDS_M_SIGNAL_S16_DELAY_V1

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY_INIT
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
*
*******************************************************************************/
extern FUNC(void, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V1_INIT(CONSTP2VAR(t_dds_m_sig_s16_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                CONSTP2VAR (sint16, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                uint16 data_buffer_size,
                                                uint16 prescaler_value,
                                                uint16 ratio_delay_sched);

#define DDS_M_SIGNAL_S16_DELAY_INIT DDS_M_SIGNAL_S16_DELAY_V1_INIT
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S16_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1° It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2° It returns the signal value that has occured "time_delay" before.
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
*  REMARK:
 *  if the time delay is
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V2(CONSTP2VAR(t_dds_m_sig_s16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                sint16 input_sig_value,
                                                uint16 time_delay);

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
*   'delay_sched' is the scheduling of the call of DDS_M_SIGNAL_U16_DELAY_V2 (avoid to memorise exact timing)
*
*  REMARKS:
*   There is no value in the buffer once init done.
*
*******************************************************************************/
extern FUNC(void, AUTOMATIC) DDS_M_SIGNAL_S16_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_s16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                CONSTP2VAR (sint16, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                uint16 data_buffer_size,
                                                uint16 prescaler_value,
                                                uint16 delay_sched,
                                                sint16 default_value);
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_U16_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1° It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2° It returns the signal value that has occured "time_delay" before.
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
*  REMARK:
 *  if the time delay is
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_SIGNAL_U16_DELAY_V2(CONSTP2VAR(t_dds_m_sig_u16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                uint16 input_sig_value,
                                                uint16 time_delay);

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
extern FUNC(void, AUTOMATIC) DDS_M_SIGNAL_U16_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_u16_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                CONSTP2VAR (uint16, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                uint16 data_buffer_size,
                                                uint16 prescaler_value,
                                                uint16 delay_sched,
                                                uint16 default_value);

/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_U8_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1° It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2° It returns the signal value that has occured "time_delay" before.
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
*  REMARK:
 *  if the time delay is
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_SIGNAL_U8_DELAY_V2(CONSTP2VAR(t_dds_m_sig_u8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                uint8 input_sig_value,
                                                uint16 time_delay);

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
extern FUNC(void, AUTOMATIC) DDS_M_SIGNAL_U8_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_u8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                            CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                            uint16 data_buffer_size,
                                                            uint16 prescaler_value,
                                                            uint16 delay_sched,
                                                            uint8 default_value);
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_S8_DELAY_V2
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1° It saves the "input_sig_value" every "prescaler" time in the "buffer_ptr".
*  2° It returns the signal value that has occured "time_delay" before.
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
*  REMARK:
 *  if the time delay is
*******************************************************************************/
extern FUNC(sint8, AUTOMATIC) DDS_M_SIGNAL_S8_DELAY_V2(CONSTP2VAR(t_dds_m_sig_s8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                sint8 input_sig_value,
                                                uint16 time_delay);

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
extern FUNC(void, AUTOMATIC) DDS_M_SIGNAL_S8_DELAY_V2_INIT(CONSTP2VAR(t_dds_m_sig_s8_delay_v2_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                            CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                            uint16 data_buffer_size,
                                                            uint16 prescaler_value,
                                                            uint16 delay_sched,
                                                            sint8 default_value);
/*******************************************************************************
*  Function name:  DDS_M_SIGNAL_BOOLEAN_DELAY
*
*  Description :
*  The following function is used to perform a signal delay function.
*
*  1 It saves the "input_sig_value" every time in the "buffer_ptr".
*  2 It returns the signal value that has occured "time_delay" before.
*     If the delay is higher than the amount of signal memorised
*       the oldest value is returned
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
*   sig_delay_struct_ptr is the structure associated to macro
*   input_sig_value is the input signal value
*   time_delay is the time delay of the signal
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_SIGNAL_BOOLEAN_DELAY(CONSTP2VAR(t_dds_m_sig_boolean_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                uint8 input_sig_value,
                                                uint16 time_delay);

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
*   data_buffer_ptr is the pointer on the buffer where to save signal
*   data_buffer_size is the size of the saving buffer
*   scheduling_in_time_delay_res is the DDS_M_SIG_U16_DELAY scheduling in
*                               time_delay resolution
*   time_delay_max is the maximum number of delay.
*
*  REMARKS:
*   time_delay_max must be lower than 8*data_buffer_size
*   There is no value in the buffer once init done.
*   delay_sched is the scheduling.
*   Time delay and scheduling must have the same resolution.
*
*
*******************************************************************************/
extern FUNC(void, AUTOMATIC) DDS_M_SIGNAL_BOOLEAN_DELAY_INIT(CONSTP2VAR(t_dds_m_sig_boolean_delay_type, AUTOMATIC, AUTOMATIC) sig_delay_struct_ptr,
                                                    CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) data_buffer_ptr,
                                                    uint16 data_buffer_size,
                                                    uint16 delay_sched,
                                                    uint16 time_delay_max);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_VARIABLE_TRANSPORT_DELAY_FAP(
                        CONSTP2VAR(t_dds_m_var_trans_delay_fap, AUTOMATIC, AUTOMATIC) str,
                        sint32 input, /* BIN17 */
                        uint32 delta_time, /* DEC3 */
                        uint32 v_propagation, /* BIN7 */
                        CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) pflt_var_trig, /* BIN0 */
                        CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) pflt_var_dtsub, /* DEC3 */
                        CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) pflt_var_state, /* BIN0 */
                        CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) pflt_var_idx /* BIN0 */);

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
extern FUNC(void, AUTOMATIC) DDS_M_VARIABLE_TRANSPORT_DELAY_FAP_INIT(
                        CONSTP2VAR(t_dds_m_var_trans_delay_fap, AUTOMATIC, AUTOMATIC) str,
                        uint32 dT_min, /* DEC3 */
                        uint32 dT_max /* DEC3 */);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_PROD_MATRIX_UINT16(P2VAR(uint16, AUTOMATIC, AUTOMATIC) matrix_in1,
                                                      uint8 nb_row_matrix_in1,
                                                      uint8 nb_col_matrix_in1,
                                                      P2VAR(uint16, AUTOMATIC, AUTOMATIC) matrix_in2,
                                                      uint8 nb_col_matrix_in2,
                                                      P2VAR(uint32, AUTOMATIC, AUTOMATIC) matrix_out,
                                                      uint32 bin_scalaire);

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

extern FUNC(uint8, AUTOMATIC) DDS_M_PROD_MATRIX_SINT16(P2VAR(sint16, AUTOMATIC, AUTOMATIC) matrix_in1,
                                                      uint8 nb_row_matrix_in1,
                                                      uint8 nb_col_matrix_in1,
                                                      P2VAR(sint16, AUTOMATIC, AUTOMATIC) matrix_in2,
                                                      uint8 nb_col_matrix_in2,
                                                      P2VAR(sint32, AUTOMATIC, AUTOMATIC) matrix_out,
                                                      uint32 bin_scalaire);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_PH_S32 ( CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            sint32 input,
                                            sint32 hyst_high_thr,
                                            sint32 hyst_low_thr );

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
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_PH_U32 ( CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint32 input,
                                            uint32 hyst_high_thr,
                                            uint32 hyst_low_thr );

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
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_LH_S32 (  CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            sint32 input,
                                            sint32 hyst_high_thr,
                                            sint32 hyst_low_thr );

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
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_LH_U32 (  CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint32 input,
                                            uint32 hyst_high_thr,
                                            uint32 hyst_low_thr );

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
*   hyst_high_thr is th upper limit of hyst
*   hyst_band is the band of hyst
*   hyst_struct_ptr is the structure associated to macro
*
*  REMARKS:
*   input, hyst_high_thr and hyst_band must all be  of the same type and BIN Point
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_U32 ( CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                        uint32 input,
                                        uint32 hyst_high_thr,
                                        uint32 hyst_band );

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
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_S32_INIT (CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint8 init_value);

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
extern FUNC(uint8, AUTOMATIC) DDS_M_HYST_U32_INIT (CONSTP2VAR(t_dds_m_hyst_type, AUTOMATIC, AUTOMATIC) hyst_struct_ptr,
                                            uint8 init_value);


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
*       // inatials variables:
*   uint32 num_in1;             // BINX
*   uint32 num_in2;             // BINY
*   uint32 num_out;             // BINZ
*
*       // temporary variables:
*   uint16 num_in1_reduced; // BIN(X-U)
*   uint16 num_in2_reduced; // BIN(Y-V)
*   uint32 num_out_tmp;     // BIN(X-U + Y-V)
*
*   sint8 num_in1_nb_shift; // U
*   sint8 num_in2_nb_shift; // V
*   sint8 nb_shift_wished;      // X-U + Y-V -Z
*
*       // Step1
*   num_in1_reduced = DDS_M_REDUCE_UINT32_TO_UINT16(num_in1, &num_in1_nb_shift);
*   num_in2_reduced = DDS_M_REDUCE_UINT32_TO_UINT16(num_in2, &num_in2_nb_shift);
*
*       // Step2
*   // BIN(X-U + Y-V) =  BIN(X-U) * BIN(Y-V)
*   num_out_tmp = (uint32)num_in1_reduced * (uint32)num_in2_reduced;
*
*       // Step3
*   // BINZ = BIN(X-U + Y-V) / BIN(X-U + Y-V -Z)
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
extern FUNC(uint16, AUTOMATIC) DDS_M_SHORTEN_UINT32_TO_UINT16(uint32 num_to_reduce,
                                                        CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift);

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
extern FUNC(uint32, AUTOMATIC) DDS_M_SHORTEN_UINT32_TO_UINT32(uint32 num_to_reduce, uint32 max_value, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift);



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
extern FUNC(sint16, AUTOMATIC) DDS_M_SHORTEN_SINT32_TO_SINT16(sint32 num_to_shorten,
                                                        CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift);

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
extern FUNC(uint16, AUTOMATIC) DDS_M_REDUCE_UINT32_TO_UINT16(uint32 num_to_reduce,
                                                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) nb_shift);

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
extern FUNC(sint16, AUTOMATIC) DDS_M_REDUCE_SINT32_TO_SINT16(sint32 num_to_reduce,
                                                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) nb_shift);

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
extern FUNC(uint32, AUTOMATIC) DDS_M_INCREASE_UINT32_TO_UINT32 (uint32 num_to_increase,
                                                         CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_INCREASE_SINT32_TO_SINT32 (sint32 num_to_increase,
                                                         CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) nb_shift);

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
extern FUNC(uint32, AUTOMATIC) DDS_M_RESTORE_BINPOINT_UINT32(uint32 num_to_restore, sint8 nb_shift_wished);


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
extern FUNC(sint32, AUTOMATIC) DDS_M_RESTORE_BINPOINT_SINT32(sint32 num_to_restore, sint8 nb_shift_wished);

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
extern FUNC(uint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_U32_V1(uint32  a, uint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number);

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
extern FUNC(uint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_U32_V2(uint32  a, uint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number);


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
extern FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_S32_V1(sint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number);

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
extern FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_S32_V2(sint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number);

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
extern FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_USS32_V1(uint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number);

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
extern FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_MULT_USS32_V2(uint32  a, sint32 b, CONSTP2VAR (sint8, AUTOMATIC, AUTOMATIC) current_bin_number);


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

extern FUNC(uint32, AUTOMATIC)  DDS_M_DYNAMIC_DIV_U32(uint32  a, uint32 b, sint8 bin_number_num, sint8 bin_number_denum, sint8 bin_number_expected);

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

extern FUNC(sint32, AUTOMATIC)  DDS_M_DYNAMIC_DIV_S32(sint32  a, sint32 b, sint8 bin_number_num, sint8 bin_number_denum, sint8 bin_number_expected);



/*******************************************************************************
*
*  Function Name   : DDS_M_DECREMENT_SINT32
*
*  Description     : decrement the input by one and check under flow.
*
*  Warning: the minimum will depend on the machine implementation
*           -2147483647 or -2147483648
*******************************************************************************/

extern FUNC(sint32, AUTOMATIC) DDS_M_DECREMENT_SINT32(sint32 nb_to_decrease);


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
extern FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_U32(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        uint32 current_time,
                        uint32 disable_to_enable_duration,
                        uint32 enable_to_disable_duration,
                        CONSTP2VAR (t_dds_m_soft_trans_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr);

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_INIT_U32
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following macro manage initialization before starting DDS_M_SOFT_TRANS_U32.
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
extern FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_INIT_U32(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        uint32 current_time,
                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) trans_active_ptr,      /* May be DDS_NULL_PTR */
                        CONSTP2VAR (t_dds_m_soft_trans_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr);

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
extern FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_U32(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        uint32 delta_time,
                        uint32 disable_to_enable_duration,
                        uint32 enable_to_disable_duration,
                        CONSTP2VAR (t_dds_m_soft_trans_delta_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr);

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_DELTA_U32_INIT
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following macro manage initialization before starting DDS_M_SOFT_TRANS_DELTA_U32.
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
extern FUNC(uint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_U32_INIT(uint8 enable,
                        uint32 target_disable,
                        uint32 target_enable,
                        /*uint32 delta_time,*/
                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) trans_active_ptr,      /* May be DDS_NULL_PTR */
                        CONSTP2VAR (t_dds_m_soft_trans_delta_u32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_S32(uint8 enable,
                        sint32 target_disable,
                        sint32 target_enable,
                        uint32 delta_time,
                        uint32 disable_to_enable_duration,
                        uint32 enable_to_disable_duration,
                        CONSTP2VAR (t_dds_m_soft_trans_delta_s32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr);

/*******************************************************************************
*  Function name:  DDS_M_SOFT_TRANS_DELTA_S32_INIT
*
*  Diagram symbol glossary ref : Soft_transition_v2
*
*  Description :
*  The following macro manage initialization before starting DDS_M_SOFT_TRANS_DELTA_U32.
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
extern FUNC(sint32, AUTOMATIC) DDS_M_SOFT_TRANS_DELTA_S32_INIT(uint8 enable,
                        sint32 target_disable,
                        sint32 target_enable,
                        /*uint32 delta_time,*/
                        CONSTP2VAR (uint8, AUTOMATIC, AUTOMATIC) trans_active_ptr,      /* May be DDS_NULL_PTR */
                        CONSTP2VAR (t_dds_m_soft_trans_delta_s32_type, AUTOMATIC, AUTOMATIC) soft_trans_struct_ptr);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_LINEAR_FILTER_S32(
        CONSTP2VAR(t_dds_m_linear_filter_s32, AUTOMATIC, AUTOMATIC) linear_filter_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8 sel,
        sint32 in1,
        sint32 in2,
        uint32 tr,
        uint8 inh,
        uint32 current_time);

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
*   tr is the transition time
*   inh is the inhibit function command
*   current_time is the current time
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_LINEAR_FILTER_S32_INIT(
        CONSTP2VAR(t_dds_m_linear_filter_s32, AUTOMATIC, AUTOMATIC) linear_filter_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8 sel,
        sint32 in1,
        sint32 in2,
        uint32 current_time);


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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_HYST_S16(
                            CONSTP2VAR(t_dds_m_filter_hyst_s16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                            sint16 inp_hyst,
                            uint16 tol_pos,
                            uint16 tol_neg,
                            uint8 activ);


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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_HYST_S16_INIT (
                                CONSTP2VAR(t_dds_m_filter_hyst_s16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                                sint16 init_value);



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
extern FUNC(uint16, AUTOMATIC) DDS_M_FILTER_HYST_U16(
                            CONSTP2VAR(t_dds_m_filter_hyst_u16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                            uint16 inp_hyst,
                            uint16 tol_pos,
                            uint16 tol_neg,
                            uint8 activ);


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
extern FUNC(uint16, AUTOMATIC) DDS_M_FILTER_HYST_U16_INIT (
                                CONSTP2VAR(t_dds_m_filter_hyst_u16, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                                uint16 init_value);



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
extern FUNC(sint32, AUTOMATIC) DDS_M_FILTER_HYST_S32(
                            CONSTP2VAR(t_dds_m_filter_hyst_s32, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                            sint32 inp_hyst,
                            uint32 tol_pos,
                            uint32 tol_neg,
                            uint8 activ);


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
extern FUNC(sint32, AUTOMATIC) DDS_M_FILTER_HYST_S32_INIT (
                                CONSTP2VAR(t_dds_m_filter_hyst_s32, AUTOMATIC, AUTOMATIC) filter_hyst_ptr,
                                sint32 init_value);



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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_ASSYM_S16(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                     sint16 target,
                                                     uint16 positive_factor,
                                                     uint16 negative_factor,
                                                     uint16 bp_filter_factor);



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
extern FUNC(sint16, AUTOMATIC) DDS_M_FILTER_LP1_ASSYM_S16_INIT(CONSTP2VAR(t_dds_m_filter_lp1, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                        sint16 init_value);



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
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_ADAP_TRAN_TEMP_BLOC_S32(
        CONSTP2VAR(t_dds_m_adapt_trans_tempo_s32, AUTOMATIC, AUTOMATIC) block_ptr,
        P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
        uint8  sel,
        sint32 in1,
        sint32 in2,
        uint32 tr,
        uint8  inh,
        uint32 te,
        sint8  in_out_bin_number);

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
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_ADAP_TRAN_TEMP_BLOC_S32_INIT(
                CONSTP2VAR(t_dds_m_adapt_trans_tempo_s32, AUTOMATIC, AUTOMATIC) block_ptr,
                P2VAR(uint8, AUTOMATIC, AUTOMATIC) acv_ptr,
                uint8 sel);

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
*   DDS_M_FILTER_LP1_SInt32_INIT
*   it is assume that filter_factor has a BIN15 precision.
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_FILTER_LP1_S32(CONSTP2VAR(t_dds_m_filter_lp1_s32, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                             sint32 target,
                                             uint16 filter_factor);

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
extern FUNC(sint32, AUTOMATIC) DDS_M_FILTER_LP1_S32_INIT(CONSTP2VAR(t_dds_m_filter_lp1_s32, AUTOMATIC, AUTOMATIC) filter_struct_ptr,
                                                  sint32 init_value);

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
extern FUNC(uint16, AUTOMATIC)  DDS_M_MEM_EXTINI_U16_INIT(
                            CONSTP2VAR(t_dds_m_mem_extini_16, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint16 init_value,
                            uint16 in_value,
                            uint8 hld_sel);

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
extern FUNC(uint16, AUTOMATIC)  DDS_M_MEM_EXTINI_U16(
                            CONSTP2VAR(t_dds_m_mem_extini_16, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint16 in_value,
                            uint8 hld_sel);

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
*   t_dds_m_mem_extini_u16 is the structure associated to macro
*   init_value is the init value
*
*
*******************************************************************************/
extern FUNC(uint32, AUTOMATIC)  DDS_M_MEM_EXTINI_U32_INIT(
                            CONSTP2VAR(t_dds_m_mem_extini_32, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint32 init_value,
                            uint32 in_value,
                            uint8 hld_sel);

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
extern FUNC(uint32, AUTOMATIC)  DDS_M_MEM_EXTINI_U32(
                            CONSTP2VAR(t_dds_m_mem_extini_32, AUTOMATIC, AUTOMATIC) mem_struct_ptr,
                            uint32 in_value,
                            uint8 hld_sel);

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
*  init_input value initialise previous_input_1 and 2
*  init_output value initialise previou_output_1 and 2
*  filter_struct_ptr is the structure associated to macro
*
*******************************************************************************/
extern sint32 DDS_M_2ND_ORDER_FILTER_S16_INIT(
                                     sint16 input_value,
                                     sint16 init_value,
                                     t_dds_m_2nd_order_filter_s16 *filter_struct_ptr);


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
extern sint32 DDS_M_2ND_ORDER_FILTER_DIS_S16(
                                sint16 input_value,
                                sint32 output_value,
                                t_dds_m_2nd_order_filter_s16 *filter_struct_ptr);

/*******************************************************************************
*  Function name:  DDS_M_2ND_ORDER_FILTER_S16
*
*  Diagram symbol glossary ref : 2nd_Order_Filter
*
*  Description :
*  The following fucntion apply a stop band filter to the input.
*   Output = (b0_factor * input) + (b1_factor * input_prev) + (b2_factor * input_prev_prev)
*           - (a1_factor * output_prev) - (a2_factor * output_prev_prev)
*
*   The transfert function is
*   H(z) = (b0 + b1.Z^(-1) + b2.Z^(-2)) / (1 + a1.Z^(-1) + a2.Z^(-2))
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

extern sint32 DDS_M_2ND_ORDER_FILTER_S16 (
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
                            t_dds_m_2nd_order_filter_s16 *filter_struct_ptr);


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
extern FUNC(sint32, AUTOMATIC) DDS_M_BACKLASH_S32 (CONSTP2VAR(t_dds_m_backlash_s32, AUTOMATIC, AUTOMATIC) backlash_struct_ptr,
                                            sint16 input,
                                            uint16 hyst_band);


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
extern FUNC(sint32, AUTOMATIC) DDS_M_BACKLASH_S32_INIT (CONSTP2VAR(t_dds_m_backlash_s32, AUTOMATIC, AUTOMATIC) backlash_struct_ptr,
                                            sint16 input);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_U8_V2 (Use Input Below)
*  Description     :    U8 2-D table function
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_TAB2D_U8_V2( CONSTP2CONST(t_dds_m_tab2d_u8_v2, AUTOMATIC, AUTOMATIC)  table,
                                                 uint8 x);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_U16_V2 (Use Input Below)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC)  DDS_M_TAB2D_U16_V2(CONSTP2CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC, AUTOMATIC) table,
                                                uint16 x);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB3D_SSU16_V2 (Use Input Below)
*  Description     :    sint16, sint16, uint16 3-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_TAB3D_SSU16_V2(CONSTP2CONST(t_dds_m_tab3d_ssu16_v2, AUTOMATIC, AUTOMATIC) table,
                                                 sint16 x,
                                                 sint16 y);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_U8_V2 (Use Input Nearest)
*  Description     :    uint8 2-D table function
*
*******************************************************************************/
extern FUNC(uint8, AUTOMATIC) DDS_M_TAB2D_NEAREST_U8_V2( CONSTP2CONST(t_dds_m_tab2d_u8_v2, AUTOMATIC, AUTOMATIC)  table,
                                                         uint8 x);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_U16_V2 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_U16_V2(CONSTP2CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC, AUTOMATIC) table,
                                                           uint16 x);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_S16 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_S16(CONSTP2CONST(t_dds_m_tab2d_s16, AUTOMATIC, AUTOMATIC) table,
                                                        sint16 x);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_US16 (Use Input Nearest)
*  Description     :    uint16 2-D table function
*
*******************************************************************************/
extern FUNC(sint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_US16(CONSTP2CONST(t_dds_m_tab2d_us16, AUTOMATIC, AUTOMATIC) table,
                                                        uint16 x);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB2D_NEAREST_SU16 (Use Input Nearest)
*  Description     :    sint16 2-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC)  DDS_M_TAB2D_NEAREST_SU16(CONSTP2CONST(t_dds_m_tab2d_su16, AUTOMATIC, AUTOMATIC) table,
                                                        sint16 x);


/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB3D_NEAREST_U16_V2 (Use Input Nearest)
*  Description     :    uint16, uint16, uint16 3-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_TAB3D_NEAREST_U16_V2(CONSTP2CONST(t_dds_m_tab3d_u16_v2, AUTOMATIC, AUTOMATIC) table,
                                                uint16 x,
                                                uint16 y);

/*******************************************************************************
*
*  Function Name   :    DDS_M_TAB3D_NEAREST_USU16_V2 (Use Input Nearest)
*  Description     :    uint16, sint16, uint16 3-D table function
*
*******************************************************************************/
extern FUNC(uint16, AUTOMATIC) DDS_M_TAB3D_NEAREST_USU16_V2(CONSTP2CONST(t_dds_m_tab3d_usu16_v2, AUTOMATIC, AUTOMATIC) table,
                                                  uint16 x,
                                                  sint16 y);

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_DECREMENT_U32
*  Description     :    max(input - dec, limit).
*
*******************************************************************************/
extern FUNC(uint32, AUTOMATIC) DDS_M_LIMITED_DECREMENT_U32(uint32 input,
                                                  uint16 dec,
                                                  uint32 limit);

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_DECREMENT_S32
*  Description     :    max(input - dec, limit).
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_LIMITED_DECREMENT_S32(sint32 input,
                                                  uint16 dec,
                                                  sint32 limit);

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_INCREMENT_U32
*  Description     :    min(input + inc, limit).
*
*******************************************************************************/
extern FUNC(uint32, AUTOMATIC) DDS_M_LIMITED_INCREMENT_U32(uint32 input,
                                                  uint16 inc,
                                                  uint32 limit);

/*******************************************************************************
*
*  Function Name   :    DDS_M_LIMITED_INCREMENT_S32
*  Description     :    min(input + inc, limit).
*
*******************************************************************************/
extern FUNC(sint32, AUTOMATIC) DDS_M_LIMITED_INCREMENT_S32(sint32 input,
                                                  uint16 inc,
                                                  sint32 limit);

#endif /* DDS_LIB_H */

