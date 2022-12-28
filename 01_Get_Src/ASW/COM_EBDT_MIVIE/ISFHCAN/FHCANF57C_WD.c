/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF57C_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF57C_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidCheckDMTRWindow(void)
{
   boolean bLocalUCE_bWkuMain;
   boolean bLocalECU_bUcapWkuSt;
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(ECU_bUcapWkuSt, bLocalECU_bUcapWkuSt);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if ((bLocalUCE_bWkuMain == TRUE) || (bLocalECU_bUcapWkuSt == TRUE))
   {
      FHCANF57C_u16Cond1Counter = (uint16)(MATHSRV_udtMIN(FHCANF57C_u16Cond1Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF57C_u16Cond1Counter = 0;
   }

   if (   (s16LocalExt_uBattMes >= Ext_uBattMinDMTRtoCMM_C)
      &&  (s16LocalExt_uBattMes <= Ext_uBattMaxDAEtoCMM_C))
   {
      FHCANF57C_u16Cond2Counter = (uint16)(MATHSRV_udtMIN(FHCANF57C_u16Cond2Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF57C_u16Cond2Counter = 0;
   }

   if (  ((FHCANF57C_u16Cond1Counter >= Ext_tiMonRunDMTRtoCMM1_C) || (FHCANF57C_u16Cond1Counter >= Ext_tiMonRunDMTRtoCMM2_C))
      && (FHCANF57C_u16Cond2Counter >= Ext_tiMonRunDMTRtoCMM3_C))
   {
      VEMS_vidSET(Ext_bMonRunDMTRtoCMM, FHCAN_ENABLE);
   }
   else
   {
      VEMS_vidSET(Ext_bMonRunDMTRtoCMM, FHCAN_DISABLE);
   }
}

void FHCAN57C_vidCalcMonDMTRWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;
   boolean Local_bExt_bMonRunDMTRtoCMM;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);
   VEMS_vidGET(Ext_bMonRunDMTRtoCMM, Local_bExt_bMonRunDMTRtoCMM);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in)
      && (FHCAN_ENABLE == Local_bExt_bMonRunDMTRtoCMM))
   {
      Ext_bMonRunDMTRAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunDMTRAbsent = FHCAN_DISABLE;
   }
}

void FHCAN57C_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF57C_in;
   boolean FRM_bInhDiagShoF57C_in;
   boolean Local_bExt_bMonRunDMTRtoCMM;


   FRM_bInhDiagMissF57C_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF57C);
   FRM_bInhDiagShoF57C_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF57C);

   VEMS_vidGET(Ext_bMonRunDMTRtoCMM, Local_bExt_bMonRunDMTRtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunDMTRtoCMM)
   {
      if (!FRM_bInhDiagMissF57C_in)
      {
         Ext_bMonRunMissF57C = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF57C = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF57C_in)
      {
         Ext_bMonRunShoF57C = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF57C = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF57C = FHCAN_DISABLE;
      Ext_bMonRunShoF57C = FHCAN_DISABLE;
   }
}

void FHCAN57C_vidCalcMonFPM1418Window(void)
{
   boolean FRM_bInhInvldF57C_in;
   boolean Local_bExt_bMonRunDMTRtoCMM;


   FRM_bInhInvldF57C_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF57C);

   VEMS_vidGET(Ext_bMonRunDMTRtoCMM, Local_bExt_bMonRunDMTRtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunDMTRtoCMM)
   {
      if (!FRM_bInhInvldF57C_in)
      {
         Ext_bMonRunInvldF57CPM1418 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF57CPM1418 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF57CPM1418 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
