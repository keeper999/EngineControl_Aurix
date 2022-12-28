#include "Vems_NVRAM.h"

/**********************************************************************************
   Creation des macros necessaires pour la variable FRM_abRawTypAcvOptRvCcDd -  VEMS V02 ECU#058813
 **********************************************************************************/
#include "FRM.h"
#include "FRM_L.h"
#define vidGET_ARRAY_ELEMENT_FRM_abRawTypAcvOptRvCcDd(variable,pos) \
{ \
  uint16 u16localPos = pos; \
  if (u16localPos < 4) \
  { \
    variable=FRM_abRawTypAcvOptRvCcDd[pos]; \
  } \
  else \
  { \
    variable=FRM_abRawTypAcvOptRvCcDd[0]; \
    SWFAIL_vidSoftwareErrorHook(); \
  }\
}

/**********************************************************************************
   Creation des macros necessaires pour la variable AirSys_pInMnfReq (altis 158392)
 **********************************************************************************/

#undef vidSET_VALUE_AirSys_pInMnfReq
#define vidSET_VALUE_AirSys_pInMnfReq(value)
#undef vidGET_VALUE_AirSys_pInMnfReq
#define vidGET_VALUE_AirSys_pInMnfReq(variable)\
do\
{\
   uint16 datatemp[2];\
   Rte_Read_R_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq(&datatemp);\
   variable = datatemp[1];\
}\
while(0)

/**********************************************************************************
   Creation des macros necessaires pour la variable UCE_stSt (en attend une MAJ de l'outil T3torte pour la gestion des mode Switch)
 **********************************************************************************/
#undef vidSET_VALUE_UCE_stSt
#define vidSET_VALUE_UCE_stSt(value)                    Rte_SwcBDS_Application_Core1.Rte_ModeVariable_0 = value                     // il faudrais utile la macro Rte_Switch_P_UCE_stSt_RCD_Mode dans Rte_RCD.h

#undef vidGET_VALUE_UCE_stSt
#define vidGET_VALUE_UCE_stSt(variable)                 variable = Rte_SwcBDS_Application_Core1.Rte_ModeVariable_0

/**********************************************************************************
   Creation des macros necessaires pour la variable UCE_stWkuMainRelSt (en attend une MAJ de l'outil T3torte pour la gestion des mode Switch)
 **********************************************************************************/
#undef vidSET_VALUE_UCE_stWkuMainRelSt
#define vidSET_VALUE_UCE_stWkuMainRelSt(value)          Rte_Mode_R_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt() = value // il faudrais utile la macro Rte_Switch_P_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt dans Rte_RCD.h

#undef vidGET_VALUE_UCE_stWkuMainRelSt
#define vidGET_VALUE_UCE_stWkuMainRelSt(variable)       variable = Rte_Mode_R_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt()

/**********************************************************************************
   Creation des macros necessaires pour la variable currentMode (en attend une MAJ de l'outil T3torte pour la gestion des mode Switch)
 **********************************************************************************/
#undef vidSET_VALUE_currentMode
#define vidSET_VALUE_currentMode(value)                 Rte_Switch_VEMS_Interface_P_EcuM_CurrentMode_currentMode(value)

#undef vidGET_VALUE_currentMode
#define vidGET_VALUE_currentMode(variable)              variable = Rte_Mode_R_EcuM_CurrentMode_currentMode()

/**********************************************************************************
   Creation des macros necessaires pour la variable EcuM_Mode (en attend une MAJ de l'outil T3torte pour la gestion des mode Switch)
 **********************************************************************************/
#undef vidSET_VALUE_EcuM_Mode
#define vidSET_VALUE_EcuM_Mode(value)                   Rte_Switch_VEMS_Interface_P_EcuM_CurrentMode_EcuM_Mode(value)

#undef vidGET_VALUE_EcuM_Mode
#define vidGET_VALUE_EcuM_Mode(variable)                variable = Rte_Mode_R_EcuM_CurrentMode_EcuM_Mode()

/**********************************************************************************
   Creation des macros necessaires pour l'integration MacroModule
 **********************************************************************************/
 #include "Rte_EBSTUB.h"
 #include "Rte_TQADPCMP.h"
 #include "Rte_COTQ.h"
 #include "Rte_AIRSYSAIR.h"
 #include "Rte_ADVMAXT.h"
 #include "Rte_PRODELEM.h"
 #include "Rte_ENGMGSLLIM.h"
 #include "Rte_EXMGSLT2.h"
 #include "Rte_AFAT.h"

/**********************************************************************************
   Creation des macros necessaires pour le tableau IgSys_prm_facFlex
 **********************************************************************************/
#define vidSET_ARRAY_IgSys_prm_facFlex(value,size)     Rte_Write_P_IgSys_prm_facFlex_IgSys_prm_facFlex(value)
#define vidGET_ARRAY_IgSys_prm_facFlex(variable,size)  Rte_Read_ADVMAXT_R_IgSys_prm_facFlex_IgSys_prm_facFlex(variable)

#define vidSET_ARRAY_ELEMENT_IgSys_prm_facFlex(variable,pos) \
{ \
   uint8 datatemp[10];\
   Rte_Read_ADVMAXT_R_IgSys_prm_facFlex_IgSys_prm_facFlex(datatemp);\
   datatemp[pos] = variable;\
   Rte_Write_P_IgSys_prm_facFlex_IgSys_prm_facFlex(datatemp);\
}

#define vidGET_ARRAY_ELEMENT_IgSys_prm_facFlex(variable,pos) \
{ \
   uint8 datatemp[10];\
   Rte_Read_ADVMAXT_R_IgSys_prm_facFlex_IgSys_prm_facFlex(datatemp);\
   variable = datatemp[pos];\
}
/**********************************************************************************
   Creation des macros necessaires pour le tableau IgSys_prm_facGas
 **********************************************************************************/
#define vidSET_ARRAY_IgSys_prm_facGas(value,size)    Rte_Write_P_IgSys_prm_facGas_IgSys_prm_facGas(value)
#define vidGET_ARRAY_IgSys_prm_facGas(variable,size) Rte_Read_ADVMAXT_R_IgSys_prm_facGas_IgSys_prm_facGas(variable)

#define vidSET_ARRAY_ELEMENT_IgSys_prm_facGas(variable,pos) \
{ \
   uint8 datatemp[10];\
   Rte_Read_ADVMAXT_R_IgSys_prm_facGas_IgSys_prm_facGas(datatemp);\
   datatemp[pos] = variable;\
   Rte_Write_P_IgSys_prm_facGas_IgSys_prm_facGas(datatemp);\
}

#define vidGET_ARRAY_ELEMENT_IgSys_prm_facGas(variable,pos) \
{ \
   uint8 datatemp[10];\
   Rte_Read_ADVMAXT_R_IgSys_prm_facGas_IgSys_prm_facGas(datatemp);\
   variable = datatemp[pos];\
}

#define vidSET_VALUE_EGRSys_rEGRReq(value)        Rte_Write_P_EGRSys_rEGRReq_EGRSys_rEGRReq(value)
#define vidGET_VALUE_EGRSys_rEGRReq(variable)     Rte_Read_AIRSYSAIR_R_EGRSys_rEGRReq_EGRSys_rEGRReq(&variable)

#define vidSET_VALUE_EngLim_tqIdcFLdLim(value)    Rte_Write_P_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(value)
#define vidGET_VALUE_EngLim_tqIdcFLdLim(variable) Rte_Read_COTQ_R_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(&variable)

#define vidSET_VALUE_Stg_bStgPmpThdMes(value)     Rte_Write_P_Stg_bStgPmpThdMes_Stg_bStgPmpThdMes(value)
#define vidGET_VALUE_Stg_bStgPmpThdMes(variable)  Rte_Read_TQADPCMP_R_Stg_bStgPmpThdMes_Stg_bStgPmpThdMes(&variable)

#define vidSET_VALUE_Stg_pStgPmpLnrMes(value)     Rte_Write_P_Stg_pStgPmpLnrMes_Stg_pStgPmpLnrMes(value)
#define vidGET_VALUE_Stg_pStgPmpLnrMes(variable)  Rte_Read_TQADPCMP_R_Stg_pStgPmpLnrMes_Stg_pStgPmpLnrMes(&variable)

#define vidSET_VALUE_TqSys_bFuCutOffReq(value)    Rte_Write_P_TqSys_bFuCutOffReq_TqSys_bFuCutOffReq(value)
#define vidGET_VALUE_TqSys_bFuCutOffReq(variable) Rte_Read_COTQ_R_TqSys_bFuCutOffReq_TqSys_bFuCutOffReq(&variable)

#define vidSET_VALUE_TqSys_tqCkPumpHiPLoss(value)    Rte_Write_P_TqSys_tqCkPumpHiPLoss_TqSys_tqCkPumpHiPLoss(value)
#define vidGET_VALUE_TqSys_tqCkPumpHiPLoss(variable) Rte_Read_TQADPCMP_R_TqSys_tqCkPumpHiPLoss_TqSys_tqCkPumpHiPLoss(&variable)

#define vidSET_VALUE_Ext_bfAcvConstReTra1(value)     Rte_Write_P_Ext_bfAcvConstReTra1_Ext_bfAcvConstReTra1(value)
#define vidGET_VALUE_Ext_bfAcvConstReTra1(variable)  Rte_Read_PRODELEM_R_Ext_bfAcvConstReTra1_Ext_bfAcvConstReTra1(&variable)

#define vidSET_VALUE_TrbAct_bBoostPresClCtlAcv(value)     Rte_Write_P_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv(value)
#define vidGET_VALUE_TrbAct_bBoostPresClCtlAcv(variable)  Rte_Read_ENGMGSLLIM_R_TrbAct_bBoostPresClCtlAcv_TrbAct_bBoostPresClCtlAcv(&variable)

#define vidSET_VALUE_TrbAct_rOpTrbAct(value)      Rte_Write_P_TrbAct_rOpTrbAct_TrbAct_rOpTrbAct(value)
#define vidGET_VALUE_TrbAct_rOpTrbAct(variable)   Rte_Read_EXMGSLT2_R_TrbAct_rOpTrbAct_TrbAct_rOpTrbAct(&variable)

#define vidSET_VALUE_InM_pDsThrPred(value)      Rte_Write_P_InM_pDsThrPred_InM_pDsThrPred(value)
#define vidGET_VALUE_InM_pDsThrPred(variable)   Rte_Read_AFAT_R_InM_pDsThrPred_InM_pDsThrPred(&variable)



/* See with FTOU , to be remove  */
#define vidGET_ARRAY_ELEMENT_IgSys_prm_agIgSpCyl(variable,pos) \
{ \
   variable =  Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3753.value[pos];\
}

#define vidGET_ARRAY_InM_prm_pDsThrPredCyl(variable) \
{ \
   uint16 datatemp[6];\
   Rte_Read_ENGMGSLT_R_InM_prm_pDsThrPredCyl_InM_prm_pDsThrPredCyl(datatemp);\
   variable = datatemp[pos];\
}
#define vidGET_ARRAY_InM_prm_pDsThrPredCyl(tabvalue,size) \
{ \
    tabvalue[0] = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3219.value[0]; \
    tabvalue[1] = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3219.value[1]; \
    tabvalue[2] = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3219.value[2]; \
    tabvalue[3] = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3219.value[3]; \
    tabvalue[4] = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3219.value[4]; \
    tabvalue[5] = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3219.value[5]; \
}



#define vidGET_VALUE_AFA_noAdpEfc(variable)            variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2162.value
#define vidGET_VALUE_AirSys_pUsThrReq(variable)        variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1851.value
#define vidGET_VALUE_AirSys_pUsThrReqFil(variable)     variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1882.value
#define vidGET_VALUE_CoPtUH_bEngRStrtReq(variable)     variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3603.value
#define vidGET_VALUE_CoPt_noTarGear(variable)          variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2483.value
#define vidGET_VALUE_CoPt_nTar(variable)               variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_4042.value
#define vidGET_VALUE_EngLim_tqIdcLim(variable)         variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3457.value
#define vidGET_VALUE_EngM_agCkClsInVlvEstimRef1(variable) variable =  Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3166.value
#define vidGET_VALUE_EngM_mAirCor(variable)            variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2780.value
#define vidGET_VALUE_EngM_mfAirScvCor(variable)        variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3757.value
#define vidGET_VALUE_ExM_pExMnfEstim_facVlvOvlp(variable) variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2925.value
#define vidGET_VALUE_IgSys_agIgBas(variable)           variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2084.value
#define vidGET_VALUE_IgSys_agIgMin(variable)           variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2792.value
#define vidGET_VALUE_IgSys_agIgTarWiCllTar(variable)   variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2094.value
#define vidGET_VALUE_InM_pDsThrPred_facVlvOvlp(variable) variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2203.value
#define vidGET_VALUE_TqSys_bAcvCll(variable)           variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2360.value
#define vidGET_VALUE_TqSys_bIdlAcvCmn(variable)        variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3939.value
#define vidGET_VALUE_TqSys_stTypPwtCf(variable)        variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_4025.value
#define vidGET_VALUE_TqSys_tqCkEfcReq(variable)        variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_4255.value
#define vidGET_VALUE_Tra_noGearMan(variable)           variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2515.value
#define vidGET_VALUE_TrbAct_bInhICor(variable)         variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1885.value
#define vidGET_VALUE_TrbAct_pUsThrCorReq(variable)     variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1880.value
#define vidGET_VALUE_UsThrM_tSqrtInAir(variable)       variable = Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_3151.value

#define vidSET_VALUE_OilTqCf_bPresOilReqCf(variable)   Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1915.value = variable 
#define vidSET_VALUE_OilTqCf_facDen(variable)          Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1914.value = variable 
#define vidSET_VALUE_OilTqCf_facNum(variable)          Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1913.value = variable 


