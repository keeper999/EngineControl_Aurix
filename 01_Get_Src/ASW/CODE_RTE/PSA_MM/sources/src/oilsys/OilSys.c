/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: OilSys.c %
*
* %version: 5.1.build1 %
*
* %date_modified: Wed Apr  3 16:59:46 2013 %
*
*
* %derived_by: u299919 %
* %release: DW10F/V200 %
* %full_filespec: OilSys.c-5.1.build1:csrc:3 %
*
*******************************************************************************/

#ifndef _OILSYS_C_
#define _OILSYS_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_OilSys.h"
#include "OilSys.h"
#include "OilSys_002_TEV_fct.h"
#include "OilSys_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define OILSYS_START_SEC_CONST_VERSION_MODULE_8BIT
#include "OilSys_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 OilSys_ModuleVersion_Major_MP = 5;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 OilSys_ModuleVersion_Minor_MP = 1;
#define OILSYS_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "OilSys_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 5
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define OILSYS_START_SEC_CALIB_BOOLEAN
#include "OilSys_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean OILSYS_ACTIVE_BYP_C = 0;
#define OILSYS_STOP_SEC_CALIB_BOOLEAN
#include "OilSys_MemMap.h"

#define OILSYS_START_SEC_CALIB_8BIT
#include "OilSys_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 OilSys_stCtlTyp_B = 0;
#define OILSYS_STOP_SEC_CALIB_8BIT
#include "OilSys_MemMap.h"

#define OILSYS_START_SEC_CALIB_16BIT
#include "OilSys_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 OilSys_pOilReq_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 OilSys_rCtlPmpReq_B = 0;
#define OILSYS_STOP_SEC_CALIB_16BIT
#include "OilSys_MemMap.h"

#define OILSYS_START_SEC_VAR_BOOLEAN
#include "OilSys_MemMap.h"
static Boolean OilSys_bMonRunDftOnOffHi_out_prec;
static Boolean OilSys_bMonRunDftOnOffLo_out_prec;
static Boolean OilSys_bMonRunDftOscCfm_out_prec;
static Boolean OilSys_bMonRunDftRegHi_out_prec;
static Boolean OilSys_bMonRunDftRegHiCfm_out_prec;
static Boolean OilSys_bMonRunDftRegLo_out_prec;
static Boolean OilSys_bMonRunDftRegLoCfm_out_prec;
static Boolean OilSys_bMonRunPresMesFrz_out_prec;
static Boolean OilSys_bMonRunPresToHi_out_prec;
static Boolean OilSys_bMonRunPresToLo_out_prec;
#define OILSYS_STOP_SEC_VAR_BOOLEAN
#include "OilSys_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define OILSYS_START_SEC_CODE
#include "OilSys_MemMap.h"
void RE_OilSys_001_MSE(void)
{
   OilSys_001_MSE_ini();

   (void)Rte_Write_P_OilSys_pOilReq_OilSys_pOilReq(0);
   (void)Rte_Write_P_OilSys_rCtlPmpReq_OilSys_rCtlPmpReq(0);
   (void)Rte_Write_P_OilSys_stCtlTyp_OilSys_stCtlTyp(0);
}

void RE_OilSys_002_TEV(void)
{
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_aVehLatEstim_Ext_aVehLatEstim(&OilSys_Ext_aVehLatEstim_in);
      (void)Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0(&OilSys_Ext_agCkClsExVlvEstimRef0_in);
      (void)Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0(&OilSys_Ext_agCkOpInVlvEstimRef0_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&OilSys_Ext_nEng_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&OilSys_Ext_pAirExtMes_in);
      (void)Rte_Read_R_Ext_pOilMes_Ext_pOilMes(&OilSys_Ext_pOilMes_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&OilSys_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&OilSys_Ext_tOilMes_in);
      (void)Rte_Read_R_Ext_uBattMes_Ext_uBattMes(&OilSys_Ext_uBattMes_in);
      (void)Rte_Read_R_VlvSys_agCkClsExVlvReqRef0_VlvSys_agCkClsExVlvReqRef0(&OilSys_VlvSys_agCkClsExVlvReqRef0_in);
      (void)Rte_Read_R_VlvSys_agCkOpInVlvReqRef0_VlvSys_agCkOpInVlvReqRef0(&OilSys_VlvSys_agCkOpInVlvReqRef0_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&OilSys_CoPTSt_stEng_in);
      (void)Rte_Read_R_OilTqCf_bPresOilReqCf_OilTqCf_bPresOilReqCf(&OilSys_OilTqCf_bPresOilReqCf_in);
      (void)Rte_Read_R_OilTqCf_facDen_OilTqCf_facDen(&OilSys_OilTqCf_facDen_in);
      (void)Rte_Read_R_OilTqCf_facNum_OilTqCf_facNum(&OilSys_OilTqCf_facNum_in);

      Rte_Call_R_FRM_bAcvModTog_GetFunctionPermission(&OilSys_FRM_bAcvModTog_in);
      OilSys_FRM_bAcvModTog_in = !OilSys_FRM_bAcvModTog_in;
      Rte_Call_R_FRM_bDftCmVlv_GetFunctionPermission(&OilSys_FRM_bDftCmVlv_in);
      OilSys_FRM_bDftCmVlv_in = !OilSys_FRM_bDftCmVlv_in;
      Rte_Call_R_FRM_bDftPOilMes_GetFunctionPermission(&OilSys_FRM_bDftPOilMes_in);
      OilSys_FRM_bDftPOilMes_in = !OilSys_FRM_bDftPOilMes_in;
      Rte_Call_R_FRM_bDftTCoMes_GetFunctionPermission(&OilSys_FRM_bDftTCoMes_in);
      OilSys_FRM_bDftTCoMes_in = !OilSys_FRM_bDftTCoMes_in;
      Rte_Call_R_FRM_bDftTOilMes_GetFunctionPermission(&OilSys_FRM_bDftTOilMes_in);
      OilSys_FRM_bDftTOilMes_in = !OilSys_FRM_bDftTOilMes_in;
      Rte_Call_R_FRM_bInhOilPmpPropCtl_GetFunctionPermission(&OilSys_FRM_bInhOilPmpPropCtl_in);
      OilSys_FRM_bInhOilPmpPropCtl_in = !OilSys_FRM_bInhOilPmpPropCtl_in;
      Rte_Call_R_FRM_bInhPAirExtMes_GetFunctionPermission(&OilSys_FRM_bInhPAirExtMes_in);
      OilSys_FRM_bInhPAirExtMes_in = !OilSys_FRM_bInhPAirExtMes_in;
      Rte_Call_R_FRM_bOilPmpVolMaxForc_GetFunctionPermission(&OilSys_FRM_bOilPmpVolMaxForc_in);
      OilSys_FRM_bOilPmpVolMaxForc_in = !OilSys_FRM_bOilPmpVolMaxForc_in;
      Rte_Call_R_FRM_bUncrtTq_GetFunctionPermission(&OilSys_FRM_bUncrtTq_in);
      OilSys_FRM_bUncrtTq_in = !OilSys_FRM_bUncrtTq_in;
      OilSys_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      OilSys_pOilReq_out = OilSys_pOilReq_B;
      OilSys_rCtlPmpReq_out = OilSys_rCtlPmpReq_B;
      OilSys_stCtlTyp_out = OilSys_stCtlTyp_B;
   }
   (void)Rte_Write_P_OilSys_pOilReq_OilSys_pOilReq(OilSys_pOilReq_out);
   (void)Rte_Write_P_OilSys_rCtlPmpReq_OilSys_rCtlPmpReq(OilSys_rCtlPmpReq_out);
   (void)Rte_Write_P_OilSys_stCtlTyp_OilSys_stCtlTyp(OilSys_stCtlTyp_out);

   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftOnOffHi */
      if(OilSys_bMonRunDftOnOffHi_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftOnOffHi_out==1)
         {
            Rte_Call_R_OilSys_DftOnOffHi_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftOnOffHi_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftOnOffHi_out_prec==1)
         {
            Rte_Call_R_OilSys_DftOnOffHi_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftOnOffHi_out_prec = OilSys_bMonRunDftOnOffHi_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftOnOffLo */
      if(OilSys_bMonRunDftOnOffLo_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftOnOffLo_out==1)
         {
            Rte_Call_R_OilSys_DftOnOffLo_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftOnOffLo_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftOnOffLo_out_prec==1)
         {
            Rte_Call_R_OilSys_DftOnOffLo_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftOnOffLo_out_prec = OilSys_bMonRunDftOnOffLo_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftOscCfm */
      if(OilSys_bMonRunDftOscCfm_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftOscCfm_out==1)
         {
            Rte_Call_R_OilSys_DftOscCfm_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftOscCfm_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftOscCfm_out_prec==1)
         {
            Rte_Call_R_OilSys_DftOscCfm_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftOscCfm_out_prec = OilSys_bMonRunDftOscCfm_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftRegHi */
      if(OilSys_bMonRunDftRegHi_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftRegHi_out==1)
         {
            Rte_Call_R_OilSys_DftRegHi_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftRegHi_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftRegHi_out_prec==1)
         {
            Rte_Call_R_OilSys_DftRegHi_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftRegHi_out_prec = OilSys_bMonRunDftRegHi_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftRegHiCfm */
      if(OilSys_bMonRunDftRegHiCfm_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftRegHiCfm_out==1)
         {
            Rte_Call_R_OilSys_DftRegHiCfm_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftRegHiCfm_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftRegHiCfm_out_prec==1)
         {
            Rte_Call_R_OilSys_DftRegHiCfm_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftRegHiCfm_out_prec = OilSys_bMonRunDftRegHiCfm_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftRegLo */
      if(OilSys_bMonRunDftRegLo_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftRegLo_out==1)
         {
            Rte_Call_R_OilSys_DftRegLo_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftRegLo_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftRegLo_out_prec==1)
         {
            Rte_Call_R_OilSys_DftRegLo_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftRegLo_out_prec = OilSys_bMonRunDftRegLo_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_DftRegLoCfm */
      if(OilSys_bMonRunDftRegLoCfm_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoDftRegLoCfm_out==1)
         {
            Rte_Call_R_OilSys_DftRegLoCfm_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_DftRegLoCfm_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunDftRegLoCfm_out_prec==1)
         {
            Rte_Call_R_OilSys_DftRegLoCfm_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunDftRegLoCfm_out_prec = OilSys_bMonRunDftRegLoCfm_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_PresMesFrz */
      if(OilSys_bMonRunPresMesFrz_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoPresMesFrz_out==1)
         {
            Rte_Call_R_OilSys_PresMesFrz_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_PresMesFrz_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunPresMesFrz_out_prec==1)
         {
            Rte_Call_R_OilSys_PresMesFrz_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunPresMesFrz_out_prec = OilSys_bMonRunPresMesFrz_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_PresToHi */
      if(OilSys_bMonRunPresToHi_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoPresToHi_out==1)
         {
            Rte_Call_R_OilSys_PresToHi_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_PresToHi_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunPresToHi_out_prec==1)
         {
            Rte_Call_R_OilSys_PresToHi_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunPresToHi_out_prec = OilSys_bMonRunPresToHi_out;
   }
   if (FALSE == OILSYS_ACTIVE_BYP_C)
   {

      /* Diag treatment : OilSys_PresToLo */
      if(OilSys_bMonRunPresToLo_out==1)
      {
         /* Diag activation */
         if(OilSys_bDgoPresToLo_out==1)
         {
            Rte_Call_R_OilSys_PresToLo_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_OilSys_PresToLo_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(OilSys_bMonRunPresToLo_out_prec==1)
         {
            Rte_Call_R_OilSys_PresToLo_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      OilSys_bMonRunPresToLo_out_prec = OilSys_bMonRunPresToLo_out;
   }
}

#define OILSYS_STOP_SEC_CODE
#include "OilSys_MemMap.h"

#endif
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
