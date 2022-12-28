/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF34D_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF34D_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN34D_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF34D_in;
   boolean FRM_bInhDiagShoF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF34D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF34D);
   FRM_bInhDiagShoF34D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF34D_in)
      {
         Ext_bMonRunMissF34D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF34D = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF34D_in)
      {
         Ext_bMonRunShoF34D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF34D = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF34D = FHCAN_DISABLE;
      Ext_bMonRunShoF34D = FHCAN_DISABLE;
   }
}

void FHCAN34D_vidCalcMonFP047Window(void)
{
   boolean FRM_bInhFrbdF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF34D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF34D_in)
      {
         Ext_bMonRunFrbdF34DP047 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF34DP047 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF34DP047 = FHCAN_DISABLE;
   }
}

void FHCAN34D_vidCalcMonFP043Window(void)
{
   boolean FRM_bInhFrbdF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF34D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF34D_in)
      {
         Ext_bMonRunFrbdF34DP043 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF34DP043 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF34DP043 = FHCAN_DISABLE;
   }
}

void FHCAN34D_vidCalcMonFP044Window(void)
{
   boolean FRM_bInhFrbdF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF34D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF34D_in)
      {
         Ext_bMonRunFrbdF34DP044 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF34DP044 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF34DP044 = FHCAN_DISABLE;
   }
}

void FHCAN34D_vidCalcMonFP045Window(void)
{
   boolean FRM_bInhFrbdF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF34D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF34D_in)
      {
         Ext_bMonRunFrbdF34DP045 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF34DP045 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF34DP045 = FHCAN_DISABLE;
   }
}

void FHCAN34D_vidCalcMonFFP0593Window(void)
{
   boolean FRM_bInhFrbdF34D_in;
   boolean FRM_bInhInvldF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF34D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF34D);
   FRM_bInhInvldF34D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF34D_in)
      {
         Ext_bMonRunFrbdF34DFP0593 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF34DFP0593 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF34D_in)
      {
         Ext_bMonRunInvldF34DFP0593 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF34DFP0593 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF34DFP0593 = FHCAN_DISABLE;
      Ext_bMonRunInvldF34DFP0593 = FHCAN_DISABLE;
   }
}

void FHCAN34D_vidCalcMonFPM1413Window(void)
{
   boolean FRM_bInhFrbdF34D_in;
   boolean FRM_bInhInvldF34D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF34D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF34D);
   FRM_bInhInvldF34D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF34D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF34D_in)
      {
         Ext_bMonRunFrbdF34DPM1413 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF34DPM1413 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF34D_in)
      {
         Ext_bMonRunInvldF34DPM1413 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF34DPM1413 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF34DPM1413 = FHCAN_DISABLE;
      Ext_bMonRunInvldF34DPM1413 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
