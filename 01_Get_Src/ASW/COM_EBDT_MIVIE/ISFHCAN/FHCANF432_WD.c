/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF432_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF432_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN432_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF432_in;
   boolean FRM_bInhDiagShoF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF432_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF432);
   FRM_bInhDiagShoF432_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF432_in)
      {
         Ext_bMonRunMissF432 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF432 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF432_in)
      {
         Ext_bMonRunShoF432 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF432 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF432 = FHCAN_DISABLE;
      Ext_bMonRunShoF432 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFP214Window(void)
{
   boolean FRM_bInhInvldF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF432_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF432_in)
      {
         Ext_bMonRunInvldF432P214 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF432P214 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF432P214 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFP249Window(void)
{
   boolean FRM_bInhFrbdF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF432_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF432_in)
      {
         Ext_bMonRunFrbdF432P249 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF432P249 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF432P249 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFP251Window(void)
{
   boolean FRM_bInhFrbdF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF432_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF432_in)
      {
         Ext_bMonRunFrbdF432P251 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF432P251 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF432P251 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFP402Window(void)
{
   boolean FRM_bInhFrbdF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF432_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF432_in)
      {
         Ext_bMonRunFrbdF432P402 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF432P402 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF432P402 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFP368Window(void)
{
   boolean FRM_bInhFrbdF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF432_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF432_in)
      {
         Ext_bMonRunFrbdF432P368 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF432P368 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF432P368 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFP369Window(void)
{
   boolean FRM_bInhFrbdF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF432_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF432_in)
      {
         Ext_bMonRunFrbdF432P369 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF432P369 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF432P369 = FHCAN_DISABLE;
   }
}

void FHCAN432_vidCalcMonFPM1424Window(void)
{
   boolean FRM_bInhFrbdF432_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF432_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF432);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF432_in)
      {
         Ext_bMonRunFrbdF432PM1424 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF432PM1424 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF432PM1424 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
