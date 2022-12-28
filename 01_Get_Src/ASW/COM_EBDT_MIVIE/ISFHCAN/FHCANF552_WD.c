/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF552_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF552_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN552_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF552_in;
   boolean FRM_bInhDiagShoF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF552_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF552);
   FRM_bInhDiagShoF552_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF552_in)
      {
         Ext_bMonRunMissF552 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF552 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF552_in)
      {
         Ext_bMonRunShoF552 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF552 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF552 = FHCAN_DISABLE;
      Ext_bMonRunShoF552 = FHCAN_DISABLE;
   }
}

void FHCAN552_vidCalcMonFP255Window(void)
{
   boolean FRM_bInhFrbdF552_in;
   boolean FRM_bInhInvldF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF552_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF552);
   FRM_bInhInvldF552_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF552_in)
      {
         Ext_bMonRunFrbdF552P255 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF552P255 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF552_in)
      {
         Ext_bMonRunInvldF552P255 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF552P255 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF552P255 = FHCAN_DISABLE;
      Ext_bMonRunInvldF552P255 = FHCAN_DISABLE;
   }
}

void FHCAN552_vidCalcMonFP256Window(void)
{
   boolean FRM_bInhFrbdF552_in;
   boolean FRM_bInhInvldF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF552_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF552);
   FRM_bInhInvldF552_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF552_in)
      {
         Ext_bMonRunFrbdF552P256 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF552P256 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF552_in)
      {
         Ext_bMonRunInvldF552P256 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF552P256 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF552P256 = FHCAN_DISABLE;
      Ext_bMonRunInvldF552P256 = FHCAN_DISABLE;
   }
}

void FHCAN552_vidCalcMonFP257Window(void)
{
   boolean FRM_bInhFrbdF552_in;
   boolean FRM_bInhInvldF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF552_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF552);
   FRM_bInhInvldF552_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF552_in)
      {
         Ext_bMonRunFrbdF552P257 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF552P257 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF552_in)
      {
         Ext_bMonRunInvldF552P257 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF552P257 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF552P257 = FHCAN_DISABLE;
      Ext_bMonRunInvldF552P257 = FHCAN_DISABLE;
   }
}

void FHCAN552_vidCalcMonFP325Window(void)
{
   boolean FRM_bInhInvldF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF552_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF552_in)
      {
         Ext_bMonRunInvldF552P325 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF552P325 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF552P325 = FHCAN_DISABLE;
   }
}

void FHCAN552_vidCalcMonFP015Window(void)
{
   boolean FRM_bInhInvldF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF552_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF552_in)
      {
         Ext_bMonRunInvldF552P015 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF552P015 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF552P015 = FHCAN_DISABLE;
   }
}

void FHCAN552_vidCalcMonFP326Window(void)
{
   boolean FRM_bInhInvldF552_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF552_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF552);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF552_in)
      {
         Ext_bMonRunInvldF552P326 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF552P326 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF552P326 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
