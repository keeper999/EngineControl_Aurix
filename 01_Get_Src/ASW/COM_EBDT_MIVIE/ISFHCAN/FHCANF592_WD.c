/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF592_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF592_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN592_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF592_in;
   boolean FRM_bInhDiagShoF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF592_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF592);
   FRM_bInhDiagShoF592_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF592_in)
      {
         Ext_bMonRunMissF592 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF592 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF592_in)
      {
         Ext_bMonRunShoF592 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF592 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF592 = FHCAN_DISABLE;
      Ext_bMonRunShoF592 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP272Window(void)
{
   boolean FRM_bInhFrbdF592_in;
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF592_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF592);
   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF592_in)
      {
         Ext_bMonRunFrbdF592P272 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF592P272 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P272 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P272 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF592P272 = FHCAN_DISABLE;
      Ext_bMonRunInvldF592P272 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP273Window(void)
{
   boolean FRM_bInhFrbdF592_in;
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF592_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF592);
   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF592_in)
      {
         Ext_bMonRunFrbdF592P273 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF592P273 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P273 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P273 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF592P273 = FHCAN_DISABLE;
      Ext_bMonRunInvldF592P273 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP349Window(void)
{
   boolean FRM_bInhFrbdF592_in;
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF592_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF592);
   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF592_in)
      {
         Ext_bMonRunFrbdF592P349 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF592P349 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P349 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P349 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF592P349 = FHCAN_DISABLE;
      Ext_bMonRunInvldF592P349 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP418Window(void)
{
   boolean FRM_bInhFrbdF592_in;
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF592_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF592);
   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF592_in)
      {
         Ext_bMonRunFrbdF592P418 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF592P418 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P418 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P418 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF592P418 = FHCAN_DISABLE;
      Ext_bMonRunInvldF592P418 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP419Window(void)
{
   boolean FRM_bInhFrbdF592_in;
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF592_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF592);
   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF592_in)
      {
         Ext_bMonRunFrbdF592P419 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF592P419 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P419 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P419 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF592P419 = FHCAN_DISABLE;
      Ext_bMonRunInvldF592P419 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP420Window(void)
{
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P420 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P420 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF592P420 = FHCAN_DISABLE;
   }
}

void FHCAN592_vidCalcMonFP421Window(void)
{
   boolean FRM_bInhFrbdF592_in;
   boolean FRM_bInhInvldF592_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF592_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF592);
   FRM_bInhInvldF592_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF592);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF592_in)
      {
         Ext_bMonRunFrbdF592P421 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF592P421 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF592_in)
      {
         Ext_bMonRunInvldF592P421 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF592P421 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF592P421 = FHCAN_DISABLE;
      Ext_bMonRunInvldF592P421 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
