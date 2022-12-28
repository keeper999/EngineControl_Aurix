/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF489_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF489_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidCheckBVWindow(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalCoPtUH_bEngRStrtReq;
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(CoPtUH_bEngRStrtReq, bLocalCoPtUH_bEngRStrtReq);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if (bLocalUCE_bWkuMain == TRUE)
   {
      FHCANF489_u16Cond1Counter = (uint16)(MATHSRV_udtMIN(FHCANF489_u16Cond1Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF489_u16Cond1Counter = 0;
   }

   if (bLocalCoPtUH_bEngRStrtReq == TRUE)
   {
      FHCANF489_u16Cond2Counter = (uint16)(MATHSRV_udtMIN(FHCANF489_u16Cond2Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF489_u16Cond2Counter = 0;
   }

   if (   (s16LocalExt_uBattMes >= Ext_uBattMinBVtoCMM_C)
      &&  (s16LocalExt_uBattMes <= Ext_uBattMaxBVtoCMM_C))
   {
      FHCANF489_u16Cond3Counter = (uint16)(MATHSRV_udtMIN(FHCANF489_u16Cond3Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF489_u16Cond3Counter = 0;
   }

   if (  (FHCANF489_u16Cond1Counter >= Ext_tiMonRunBVtoCMM1_C)
      && (FHCANF489_u16Cond2Counter >= Ext_tiMonRunBVtoCMM2_C)
      && (FHCANF489_u16Cond3Counter >= Ext_tiMonRunBVtoCMM3_C))
   {
      VEMS_vidSET(Ext_bMonRunBVtoCMM, FHCAN_ENABLE);
   }
   else
   {
      VEMS_vidSET(Ext_bMonRunBVtoCMM, FHCAN_DISABLE);
   }
}

void FHCAN489_vidCalcMonBVWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);
   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in)
      && (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM))
   {
      Ext_bMonRunBVAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunBVAbsent = FHCAN_DISABLE;
   }
}

void FHCAN489_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF489_in;
   boolean FRM_bInhDiagShoF489_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhDiagMissF489_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF489);
   FRM_bInhDiagShoF489_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF489);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhDiagMissF489_in)
      {
         Ext_bMonRunMissF489 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF489 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF489_in)
      {
         Ext_bMonRunShoF489 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF489 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF489 = FHCAN_DISABLE;
      Ext_bMonRunShoF489 = FHCAN_DISABLE;
   }
}

void FHCAN489_vidCalcMonFP102Window(void)
{
   boolean FRM_bInhInvldF489_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhInvldF489_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF489);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhInvldF489_in)
      {
         Ext_bMonRunInvldF489P102 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF489P102 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF489P102 = FHCAN_DISABLE;
   }
}

void FHCAN489_vidCalcMonFP254Window(void)
{
   boolean FRM_bInhFrbdF489_in;
   boolean FRM_bInhInvldF489_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF489_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF489);
   FRM_bInhInvldF489_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF489);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF489_in)
      {
         Ext_bMonRunFrbdF489P254 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF489P254 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF489_in)
      {
         Ext_bMonRunInvldF489P254 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF489P254 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF489P254 = FHCAN_DISABLE;
      Ext_bMonRunInvldF489P254 = FHCAN_DISABLE;
   }
}

void FHCAN489_vidCalcMonFP218Window(void)
{
   boolean FRM_bInhFrbdF489_in;
   boolean FRM_bInhInvldF489_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF489_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF489);
   FRM_bInhInvldF489_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF489);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF489_in)
      {
         Ext_bMonRunFrbdF489P218 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF489P218 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF489_in)
      {
         Ext_bMonRunInvldF489P218 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF489P218 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF489P218 = FHCAN_DISABLE;
      Ext_bMonRunInvldF489P218 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
