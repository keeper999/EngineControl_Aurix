/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : RCD.c
* Description   : Interface AUTOSAR du module RCD avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 06-Oct-2010(17:3:14)
*******************************************************************************/

#ifndef _RCD_C_
#define _RCD_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_RCD.h"
#include "RCD.h"
#include "RCD_002_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define RCD_START_SEC_CONST_VERSION_MODULE_8BIT
#include "RCD_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 RCD_ModuleVersion_Major_MP = 2;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 RCD_ModuleVersion_Minor_MP = 2;
#define RCD_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "RCD_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 1
#define Module_LIB_PSA_VERSION_REQ_MIN 6

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define RCD_START_SEC_CALIB_BOOLEAN
#include "RCD_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RCD_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bLINComReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bRCDLineCmd_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bShutDownAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bPwrlAcv_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bWkuMain_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean UCE_bExtdWkuMain_B = 0;

#define RCD_STOP_SEC_CALIB_BOOLEAN
#include "RCD_MemMap.h"

#define RCD_START_SEC_CALIB_8BIT
#include "RCD_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 UCE_stCAN2ComReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 UCE_stCAN3ComReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 UCE_bfMstPtlWkuReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 UCE_stCAN1ComReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 UCE_bfSlavePtlWkuSt_B = 0;
#define RCD_STOP_SEC_CALIB_8BIT
#include "RCD_MemMap.h"

#define RCD_START_SEC_VAR_BOOLEAN
#include "RCD_MemMap.h"
static Boolean UCE_bDgoRCDLineScg_out_prec;
static Boolean UCE_bDgoMainWkuDisrd_out_prec;
static Boolean UCE_bDgoMainWkuIncst_out_prec;
static Boolean UCE_bMonRunRCDLineScg_out_prec;
static Boolean UCE_bMonRunMainWkuDisrd_out_prec;
static Boolean UCE_bMonRunMainWkuIncst_out_prec;

#define RCD_STOP_SEC_VAR_BOOLEAN
#include "RCD_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define RCD_START_SEC_CODE
#include "RCD_MemMap.h"

void RE_RCD_001_MSE(void)
{


      RCD_001_MSE_ini();

      (void)Rte_Write_P_UCE_stCAN2ComReq_UCE_stCAN2ComReq(0);
      (void)Rte_Write_P_UCE_stCAN3ComReq_UCE_stCAN3ComReq(0);
      (void)Rte_Write_P_UCE_bfMstPtlWkuReq_UCE_bfMstPtlWkuReq(0);
      (void)Rte_Write_P_UCE_bLINComReq_UCE_bLINComReq(0);
      (void)Rte_Write_P_UCE_bRCDLineCmd_UCE_bRCDLineCmd(0);
      (void)Rte_Write_P_UCE_bShutDownAuth_UCE_bShutDownAuth(0);
      (void)Rte_Write_P_UCE_stCAN1ComReq_UCE_stCAN1ComReq(0);
      (void)Rte_Write_P_UCE_bfSlavePtlWkuSt_UCE_bfSlavePtlWkuSt(0);
      (void)Rte_Write_P_UCE_bPwrlAcv_UCE_bPwrlAcv(0);
      (void)Rte_Write_P_UCE_bWkuMain_UCE_bWkuMain(0);

}

void RE_RCD_002_TEV(void)
{

  if (FALSE == RCD_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bDiagToolReq_Afts_bDiagToolReq(&RCD_Afts_bDiagToolReq_in);
      (void)Rte_Read_R_Ext_bAPCLine_Ext_bAPCLine(&RCD_Ext_bAPCLine_in);
      (void)Rte_Read_R_Ext_bElecItgrReq_Ext_bElecItgrReq(&RCD_Ext_bElecItgrReq_in);
      (void)Rte_Read_R_Ext_bFctHldReq_Ext_bFctHldReq(&RCD_Ext_bFctHldReq_in);
      (void)Rte_Read_R_Ext_bfMstPtlWkuHldReq_Ext_bfMstPtlWkuHldReq(&RCD_Ext_bfMstPtlWkuHldReq_in);
      (void)Rte_Read_R_Ext_bfMstPtlWkuNd_Ext_bfMstPtlWkuNd(&RCD_Ext_bfMstPtlWkuNd_in);
      (void)Rte_Read_R_Ext_bfSlavePtlWkuReq_Ext_bfSlavePtlWkuReq(&RCD_Ext_bfSlavePtlWkuReq_in);
      (void)Rte_Read_R_Ext_bPostRunReq_Ext_bPostRunReq(&RCD_Ext_bPostRunReq_in);
      (void)Rte_Read_R_Ext_bRCDLine_Ext_bRCDLine(&RCD_Ext_bRCDLine_in);
      (void)Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&RCD_Ext_spdVeh_in);
      (void)Rte_Read_R_Ext_stMainWkuReq_Ext_stMainWkuReq(&RCD_Ext_stMainWkuReq_in);
      (void)Rte_Read_R_UCE_bCAN1ComNd_UCE_bCAN1ComNd(&RCD_UCE_bCAN1ComNd_in);
      (void)Rte_Read_R_UCE_bCAN2ComNd_UCE_bCAN2ComNd(&RCD_UCE_bCAN2ComNd_in);
      (void)Rte_Read_R_UCE_bCAN3ComNd_UCE_bCAN3ComNd(&RCD_UCE_bCAN3ComNd_in);
      (void)Rte_Read_R_UCE_bLINComNd_UCE_bLINComNd(&RCD_UCE_bLINComNd_in);

      RCD_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      UCE_stCAN2ComReq_out = UCE_stCAN2ComReq_B;
      UCE_stCAN3ComReq_out = UCE_stCAN3ComReq_B;
      UCE_bfMstPtlWkuReq_out = UCE_bfMstPtlWkuReq_B;
      UCE_bLINComReq_out = UCE_bLINComReq_B;
      UCE_bRCDLineCmd_out = UCE_bRCDLineCmd_B;
      UCE_bShutDownAuth_out = UCE_bShutDownAuth_B;
      UCE_stCAN1ComReq_out = UCE_stCAN1ComReq_B;
      UCE_bfSlavePtlWkuSt_out = UCE_bfSlavePtlWkuSt_B;
      UCE_bPwrlAcv_out = UCE_bPwrlAcv_B;
      UCE_bWkuMain_out = UCE_bWkuMain_B;
  }
  (void)Rte_Write_P_UCE_stCAN2ComReq_UCE_stCAN2ComReq(UCE_stCAN2ComReq_out);
  (void)Rte_Write_P_UCE_stCAN3ComReq_UCE_stCAN3ComReq(UCE_stCAN3ComReq_out);
  (void)Rte_Write_P_UCE_bfMstPtlWkuReq_UCE_bfMstPtlWkuReq(UCE_bfMstPtlWkuReq_out);
  (void)Rte_Write_P_UCE_bLINComReq_UCE_bLINComReq(UCE_bLINComReq_out);
  (void)Rte_Write_P_UCE_bRCDLineCmd_UCE_bRCDLineCmd(UCE_bRCDLineCmd_out);
  (void)Rte_Write_P_UCE_bShutDownAuth_UCE_bShutDownAuth(UCE_bShutDownAuth_out);
  (void)Rte_Write_P_UCE_stCAN1ComReq_UCE_stCAN1ComReq(UCE_stCAN1ComReq_out);
  (void)Rte_Write_P_UCE_bfSlavePtlWkuSt_UCE_bfSlavePtlWkuSt(UCE_bfSlavePtlWkuSt_out);
  (void)Rte_Write_P_UCE_bPwrlAcv_UCE_bPwrlAcv(UCE_bPwrlAcv_out);
  (void)Rte_Write_P_UCE_bWkuMain_UCE_bWkuMain(UCE_bWkuMain_out);
//  (void)Rte_Write_P_UCE_stWkuMainRelSt_UCE_stWkuMainRelSt(UCE_stWkuMainRelSt_out);
//  (void)Rte_Write_P_UCE_stSt_P_UCE_stSt(UCE_stSt_out);

  switch(UCE_stSt_out){
		case 1:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_PARTIAL_WAKEUP);
			break;
		}

		case 2:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_INTERNAL_PARTIAL_WAKEUP);
			break;
		}

		case 3:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_TRANSITORY);
			break;
		}

		case 4:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_MAIN_WAKEUP);
			break;
		}

		case 5:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_DEGRADED_MAIN_WAKEUP);
			break;
		}

		case 7:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_SHUTDOWN_PREPARATION);
			break;
		}

		case 10:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_INTERNAL_PARTIAL_WAKEUP_APC);
			break;
		}

		case 11:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_COM_LATCH);
			break;
		}

		case 12:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_MAIN_WAKEUP_APC);
			break;
		}

		case 15:
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_SHUTDOWN_PREPARATION_APC);
			break;
		}

		default :
		{
			(void)Rte_Switch_RCD_P_UCE_stSt_RCD_Mode(RTE_MODE_RCD_Mode_TRANSITORY);
			break;
		}
  }

  switch(UCE_stWkuMainRelSt_out){
		case 0:
		{
			(void)Rte_Switch_RCD_P_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt(RTE_MODE_RCD_stWkuMainRelSt_PreMainWakeUp);
			break;
		}

		case 1:
		{
			(void)Rte_Switch_RCD_P_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt(RTE_MODE_RCD_stWkuMainRelSt_MainWakeUp);
			break;
		}

		case 2:
		{
			(void)Rte_Switch_RCD_P_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt(RTE_MODE_RCD_stWkuMainRelSt_PostMainWakeUp);
			break;
		}

		case 3:
		{
			(void)Rte_Switch_RCD_P_UCE_stWkuMainRelSt_RCD_stWkuMainRelSt(RTE_MODE_RCD_stWkuMainRelSt_Invalid);
			break;
		}
  }

  if (FALSE == RCD_ACTIVE_BYP_C)
  {

  /* Diag treatment : UCE_RCDLineScg */
     if(UCE_bMonRunRCDLineScg_out==1)
     {
         /* Diag activation */
         if(UCE_bDgoRCDLineScg_out==1)
         {
             Rte_Call_R_UCE_RCDLineScg_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_UCE_RCDLineScg_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (UCE_bDgoRCDLineScg_out_prec==1)
         {
             Rte_Call_R_UCE_RCDLineScg_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     UCE_bMonRunRCDLineScg_out_prec = UCE_bMonRunRCDLineScg_out;


    /* Diag treatment : UCE_MainWkuDisrd */
     if(UCE_bMonRunMainWkuDisrd_out==1)
     {
         /* Diag activation */
         if(UCE_bDgoMainWkuDisrd_out==1)
         {
              Rte_Call_R_UCE_MainWkuDisrd_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_UCE_MainWkuDisrd_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (UCE_bDgoMainWkuDisrd_out_prec==1)
         {
             Rte_Call_R_UCE_MainWkuDisrd_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     UCE_bMonRunMainWkuDisrd_out_prec = UCE_bMonRunMainWkuDisrd_out;

	 /* Diag treatment : UCE_MainWkuIncst */
	 if(UCE_bMonRunMainWkuIncst_out==1)
     {
         /* Diag activation */
         if(UCE_bDgoMainWkuIncst_out==1)
         {
              Rte_Call_R_UCE_MainWkuIncst_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_UCE_MainWkuIncst_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (UCE_bDgoMainWkuIncst_out_prec==1)
         {
             Rte_Call_R_UCE_MainWkuIncst_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     UCE_bMonRunMainWkuIncst_out_prec = UCE_bMonRunMainWkuIncst_out;

    }
}

#define RCD_STOP_SEC_CODE
#include "RCD_MemMap.h"

#endif/*_RCD_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

