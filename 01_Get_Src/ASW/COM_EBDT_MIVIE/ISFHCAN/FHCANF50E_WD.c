/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50E_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF50E_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidCheckBSIWindow(void)
{
   boolean bLocalUCE_bWkuMain;
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   if (   (s16LocalExt_uBattMes >= Ext_uBattMinBSItoCMM_C)
      &&  (s16LocalExt_uBattMes <= Ext_uBattMaxBSItoCMM_C))
   {
      FHCANF50E_u16Cond2Counter = (uint16)(MATHSRV_udtMIN(FHCANF50E_u16Cond2Counter + 1, UINT16_MAX));
   }
   else
   {
      FHCANF50E_u16Cond2Counter = 0;
   }

   if (  (bLocalUCE_bWkuMain == TRUE)
      && (FHCANF50E_u16Cond2Counter >= Ext_tiMonRunBSItoCMM_C))
   {
      VEMS_vidSET(Ext_bMonRunBSItoCMM, FHCAN_ENABLE);
   }
   else
   {
      VEMS_vidSET(Ext_bMonRunBSItoCMM, FHCAN_DISABLE);
   }
}

void FHCAN50E_vidCalcMonBSIWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);
   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in)
      && (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM))
   {
      Ext_bMonRunBSIAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunBSIAbsent = FHCAN_DISABLE;
   }
}

void FHCAN50E_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF50E_in;
   boolean FRM_bInhDiagShoF50E_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF50E_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF50E);
   FRM_bInhDiagShoF50E_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF50E);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF50E_in)
      {
         Ext_bMonRunMissF50E = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF50E = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF50E_in)
      {
         Ext_bMonRunShoF50E = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF50E = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF50E = FHCAN_DISABLE;
      Ext_bMonRunShoF50E = FHCAN_DISABLE;
   }
}

void FHCAN50E_vidCalcMonFPM1386Window(void)
{
   boolean FRM_bInhInvldF50E_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF50E_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF50E);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF50E_in)
      {
         Ext_bMonRunInvldF50EPM1386 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF50EPM1386 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF50EPM1386 = FHCAN_DISABLE;
   }
}

void FHCAN50E_vidCalcMonFP046Window(void)
{
   boolean FRM_bInhFrbdF50E_in;
   boolean FRM_bInhInvldF50E_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF50E_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF50E);
   FRM_bInhInvldF50E_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF50E);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF50E_in)
      {
         Ext_bMonRunFrbdF50EP046 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF50EP046 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF50E_in)
      {
         Ext_bMonRunInvldF50EP046 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF50EP046 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF50EP046 = FHCAN_DISABLE;
      Ext_bMonRunInvldF50EP046 = FHCAN_DISABLE;
   }
}

void FHCAN50E_vidCalcMonFP417Window(void)
{
   boolean FRM_bInhFrbdF50E_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF50E_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF50E);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF50E_in)
      {
         Ext_bMonRunFrbdF50EP417 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF50EP417 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF50EP417 = FHCAN_DISABLE;
   }
}

void FHCAN50E_vidCalcMonFP210Window(void)
{
   boolean FRM_bInhInvldF50E_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF50E_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF50E);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF50E_in)
      {
         Ext_bMonRunInvldF50EP210 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF50EP210 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF50EP210 = FHCAN_DISABLE;
   }
}

void FHCAN50E_vidCalcMonFP208Window(void)
{
   boolean FRM_bInhFrbdF50E_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF50E_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF50E);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF50E_in)
      {
         Ext_bMonRunFrbdF50EP208 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF50EP208 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF50EP208 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
