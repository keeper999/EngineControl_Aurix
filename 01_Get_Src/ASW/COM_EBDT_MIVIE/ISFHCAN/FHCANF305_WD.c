/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF305_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF305_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidCheckCAPT_VOLWindow(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalCoPtUH_bEngRStrtReq;
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(CoPtUH_bEngRStrtReq, bLocalCoPtUH_bEngRStrtReq);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if (bLocalUCE_bWkuMain == TRUE)
   {
      FHCANF305_u16Cond1Counter = (uint16)(MATHSRV_udtMIN(FHCANF305_u16Cond1Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF305_u16Cond1Counter = 0;
   }

   if (bLocalCoPtUH_bEngRStrtReq == TRUE)
   {
      FHCANF305_u16Cond2Counter = (uint16)(MATHSRV_udtMIN(FHCANF305_u16Cond2Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF305_u16Cond2Counter = 0;
   }

   if (   (s16LocalExt_uBattMes >= Ext_uBattMinCAVtoCMM_C)
      &&  (s16LocalExt_uBattMes <= Ext_uBattMaxCAVtoCMM_C))
   {
      FHCANF305_u16Cond3Counter = (uint16)(MATHSRV_udtMIN(FHCANF305_u16Cond3Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF305_u16Cond3Counter = 0;
   }

   if (  (FHCANF305_u16Cond1Counter >= Ext_tiMonRunCAVtoCMM1_C)
      && (FHCANF305_u16Cond2Counter >= Ext_tiMonRunCAVtoCMM2_C)
      && (FHCANF305_u16Cond3Counter >= Ext_tiMonRunCAVtoCMM3_C))
   {
      VEMS_vidSET(Ext_bMonRunCAVtoCMM, FHCAN_ENABLE);
   }
   else
   {
      VEMS_vidSET(Ext_bMonRunCAVtoCMM, FHCAN_DISABLE);
   }
}

void FHCAN305_vidCalcMonCAPT_VOLWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;
   boolean Local_bExt_bMonRunCAVtoCMM;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);
   VEMS_vidGET(Ext_bMonRunCAVtoCMM, Local_bExt_bMonRunCAVtoCMM);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in)
      && (FHCAN_ENABLE == Local_bExt_bMonRunCAVtoCMM))
   {
      Ext_bMonRunCAPT_VOLAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunCAPT_VOLAbsent = FHCAN_DISABLE;
   }
}

void FHCAN305_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF305_in;
   boolean FRM_bInhDiagShoF305_in;
   boolean FRM_bInhChkF305_in;
   boolean Local_bExt_bMonRunCAVtoCMM;


   FRM_bInhDiagMissF305_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF305);
   FRM_bInhDiagShoF305_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF305);
   FRM_bInhChkF305_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF305);

   VEMS_vidGET(Ext_bMonRunCAVtoCMM, Local_bExt_bMonRunCAVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunCAVtoCMM)
   {
      if (!FRM_bInhDiagMissF305_in)
      {
         Ext_bMonRunMissF305 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF305 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF305_in)
      {
         Ext_bMonRunShoF305 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF305 = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF305_in)
      {
         Ext_bMonRunChkF305 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF305 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF305 = FHCAN_DISABLE;
      Ext_bMonRunShoF305 = FHCAN_DISABLE;
      Ext_bMonRunChkF305 = FHCAN_DISABLE;
   }
}

void FHCAN305_vidCalcMonFP537Window(void)
{
   boolean FRM_bInhFrbdF305_in;
   boolean FRM_bInhInvldF305_in;
   boolean Local_bExt_bMonRunCAVtoCMM;


   FRM_bInhFrbdF305_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF305);
   FRM_bInhInvldF305_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF305);

   VEMS_vidGET(Ext_bMonRunCAVtoCMM, Local_bExt_bMonRunCAVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunCAVtoCMM)
   {
      if (!FRM_bInhFrbdF305_in)
      {
         Ext_bMonRunFrbdF305P537 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF305P537 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF305_in)
      {
         Ext_bMonRunInvldF305P537 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF305P537 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF305P537 = FHCAN_DISABLE;
      Ext_bMonRunInvldF305P537 = FHCAN_DISABLE;
   }
}

void FHCAN305_vidCalcMonFP538Window(void)
{
   boolean FRM_bInhInvldF305_in;
   boolean Local_bExt_bMonRunCAVtoCMM;


   FRM_bInhInvldF305_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF305);

   VEMS_vidGET(Ext_bMonRunCAVtoCMM, Local_bExt_bMonRunCAVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunCAVtoCMM)
   {
      if (!FRM_bInhInvldF305_in)
      {
         Ext_bMonRunInvldF305P538 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF305P538 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF305P538 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
