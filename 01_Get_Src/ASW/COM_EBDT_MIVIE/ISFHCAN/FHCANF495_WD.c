/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF495_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF495_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidCheckUC_DIRAWindow(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalCoPtUH_bEngRStrtReq;
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(CoPtUH_bEngRStrtReq, bLocalCoPtUH_bEngRStrtReq);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if (bLocalUCE_bWkuMain == TRUE)
   {
      FHCANF495_u16Cond1Counter = (uint16)(MATHSRV_udtMIN(FHCANF495_u16Cond1Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF495_u16Cond1Counter = 0;
   }

   if (bLocalCoPtUH_bEngRStrtReq == TRUE)
   {
      FHCANF495_u16Cond2Counter = (uint16)(MATHSRV_udtMIN(FHCANF495_u16Cond2Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF495_u16Cond2Counter = 0;
   }

   if (   (s16LocalExt_uBattMes >= Ext_uBattMinDIRAtoCMM_C)
      &&  (s16LocalExt_uBattMes <= Ext_uBattMaxDIRAtoCMM_C))
   {
      FHCANF495_u16Cond3Counter = (uint16)(MATHSRV_udtMIN(FHCANF495_u16Cond3Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF495_u16Cond3Counter = 0;
   }

   if (  (FHCANF495_u16Cond1Counter >= Ext_tiMonRunDIRAtoCMM1_C)
      && (FHCANF495_u16Cond2Counter >= Ext_tiMonRunDIRAtoCMM2_C)
      && (FHCANF495_u16Cond3Counter >= Ext_tiMonRunDIRAtoCMM3_C))
   {
      VEMS_vidSET(Ext_bMonRunDIRAtoCMM, FHCAN_ENABLE);
   }
   else
   {
      VEMS_vidSET(Ext_bMonRunDIRAtoCMM, FHCAN_DISABLE);
   }
}

void FHCAN495_vidCalcMonUC_DIRAWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;
   boolean Local_bExt_bMonRunDIRAtoCMM;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);
   VEMS_vidGET(Ext_bMonRunDIRAtoCMM, Local_bExt_bMonRunDIRAtoCMM);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in)
      && (FHCAN_ENABLE == Local_bExt_bMonRunDIRAtoCMM))
   {
      Ext_bMonRunUC_DIRAAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunUC_DIRAAbsent = FHCAN_DISABLE;
   }
}

void FHCAN495_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF495_in;
   boolean FRM_bInhDiagShoF495_in;
   boolean Local_bExt_bMonRunDIRAtoCMM;


   FRM_bInhDiagMissF495_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF495);
   FRM_bInhDiagShoF495_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF495);

   VEMS_vidGET(Ext_bMonRunDIRAtoCMM, Local_bExt_bMonRunDIRAtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunDIRAtoCMM)
   {
      if (!FRM_bInhDiagMissF495_in)
      {
         Ext_bMonRunMissF495 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF495 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF495_in)
      {
         Ext_bMonRunShoF495 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF495 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF495 = FHCAN_DISABLE;
      Ext_bMonRunShoF495 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
