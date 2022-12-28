/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF532_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF532_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN532_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF532_in;
   boolean FRM_bInhDiagShoF532_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF532_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF532);
   FRM_bInhDiagShoF532_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF532);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF532_in)
      {
         Ext_bMonRunMissF532 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF532 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF532_in)
      {
         Ext_bMonRunShoF532 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF532 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF532 = FHCAN_DISABLE;
      Ext_bMonRunShoF532 = FHCAN_DISABLE;
   }
}

void FHCAN532_vidCalcMonFPM1414Window(void)
{
   boolean FRM_bInhFrbdF532_in;
   boolean FRM_bInhInvldF532_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF532_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF532);
   FRM_bInhInvldF532_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF532);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF532_in)
      {
         Ext_bMonRunFrbdF532PM1414 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF532PM1414 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF532_in)
      {
         Ext_bMonRunInvldF532PM1414 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF532PM1414 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF532PM1414 = FHCAN_DISABLE;
      Ext_bMonRunInvldF532PM1414 = FHCAN_DISABLE;
   }
}

void FHCAN532_vidCalcMonFPM1415Window(void)
{
   boolean FRM_bInhFrbdF532_in;
   boolean FRM_bInhInvldF532_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF532_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF532);
   FRM_bInhInvldF532_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF532);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF532_in)
      {
         Ext_bMonRunFrbdF532PM1415 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF532PM1415 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF532_in)
      {
         Ext_bMonRunInvldF532PM1415 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF532PM1415 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF532PM1415 = FHCAN_DISABLE;
      Ext_bMonRunInvldF532PM1415 = FHCAN_DISABLE;
   }
}

void FHCAN532_vidCalcMonFPM1416Window(void)
{
   boolean FRM_bInhFrbdF532_in;
   boolean FRM_bInhInvldF532_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF532_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF532);
   FRM_bInhInvldF532_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF532);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF532_in)
      {
         Ext_bMonRunFrbdF532PM1416 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF532PM1416 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF532_in)
      {
         Ext_bMonRunInvldF532PM1416 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF532PM1416 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF532PM1416 = FHCAN_DISABLE;
      Ext_bMonRunInvldF532PM1416 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
