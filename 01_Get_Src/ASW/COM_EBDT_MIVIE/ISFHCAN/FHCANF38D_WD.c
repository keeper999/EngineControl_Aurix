/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF38D_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF38D_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidCheckUC_FREINWindow(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalCoPtUH_bEngRStrtReq;
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(CoPtUH_bEngRStrtReq, bLocalCoPtUH_bEngRStrtReq);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if (bLocalUCE_bWkuMain == TRUE)
   {
      FHCANF38D_u16Cond1Counter = (uint16)(MATHSRV_udtMIN(FHCANF38D_u16Cond1Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF38D_u16Cond1Counter = 0;
   }

   if (bLocalCoPtUH_bEngRStrtReq == TRUE)
   {
      FHCANF38D_u16Cond2Counter = (uint16)(MATHSRV_udtMIN(FHCANF38D_u16Cond2Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF38D_u16Cond2Counter = 0;
   }

   if (   (s16LocalExt_uBattMes >= Ext_uBattMinUCFtoCMM_C)
      &&  (s16LocalExt_uBattMes <= Ext_uBattMaxUCFtoCMM_C))
   {
      FHCANF38D_u16Cond3Counter = (uint16)(MATHSRV_udtMIN(FHCANF38D_u16Cond3Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF38D_u16Cond3Counter = 0;
   }

   if (  (FHCANF38D_u16Cond1Counter >= Ext_tiMonRunUCFtoCMM1_C)
      && (FHCANF38D_u16Cond2Counter >= Ext_tiMonRunUCFtoCMM2_C)
      && (FHCANF38D_u16Cond3Counter >= Ext_tiMonRunUCFtoCMM3_C))
   {
      VEMS_vidSET(Ext_bMonRunUCFreintoCMM, FHCAN_ENABLE);
   }
   else
   {
      VEMS_vidSET(Ext_bMonRunUCFreintoCMM, FHCAN_DISABLE);
   }
}

void FHCAN38D_vidCalcMonUC_FREINWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);
   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in)
      && (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM))
   {
      Ext_bMonRunUC_FREINAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunUC_FREINAbsent = FHCAN_DISABLE;
   }
}

void FHCAN38D_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF38D_in;
   boolean FRM_bInhDiagShoF38D_in;
   boolean FRM_bInhChkF38D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF38D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF38D);
   FRM_bInhDiagShoF38D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF38D);
   FRM_bInhChkF38D_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF38D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF38D_in)
      {
         Ext_bMonRunMissF38D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF38D = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF38D_in)
      {
         Ext_bMonRunShoF38D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF38D = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF38D_in)
      {
         Ext_bMonRunChkF38D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF38D = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF38D = FHCAN_DISABLE;
      Ext_bMonRunShoF38D = FHCAN_DISABLE;
      Ext_bMonRunChkF38D = FHCAN_DISABLE;
   }
}

void FHCAN38D_vidCalcMonFP010Window(void)
{
   boolean FRM_bInhInvldF38D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF38D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF38D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF38D_in)
      {
         Ext_bMonRunInvldF38DP010 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF38DP010 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF38DP010 = FHCAN_DISABLE;
   }
}

void FHCAN38D_vidCalcMonFP052Window(void)
{
   boolean FRM_bInhInvldF38D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF38D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF38D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF38D_in)
      {
         Ext_bMonRunInvldF38DP052 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF38DP052 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF38DP052 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
