/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4F2_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF4F2_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN4F2_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF4F2_in;
   boolean FRM_bInhDiagShoF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF4F2);
   FRM_bInhDiagShoF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF4F2_in)
      {
         Ext_bMonRunMissF4F2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF4F2 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF4F2_in)
      {
         Ext_bMonRunShoF4F2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF4F2 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF4F2 = FHCAN_DISABLE;
      Ext_bMonRunShoF4F2 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP434Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);
   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P434 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P434 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P434 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P434 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P434 = FHCAN_DISABLE;
      Ext_bMonRunInvldF4F2P434 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP438Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);
   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P438 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P438 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P438 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P438 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P438 = FHCAN_DISABLE;
      Ext_bMonRunInvldF4F2P438 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP429Window(void)
{
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P429 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P429 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF4F2P429 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP437Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);
   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P437 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P437 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P437 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P437 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P437 = FHCAN_DISABLE;
      Ext_bMonRunInvldF4F2P437 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP490Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);
   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P490 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P490 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P490 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P490 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P490 = FHCAN_DISABLE;
      Ext_bMonRunInvldF4F2P490 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP493Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P493 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P493 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P493 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP491Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);
   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P491 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P491 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P491 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P491 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P491 = FHCAN_DISABLE;
      Ext_bMonRunInvldF4F2P491 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP494Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P494 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P494 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P494 = FHCAN_DISABLE;
   }
}

void FHCAN4F2_vidCalcMonFP492Window(void)
{
   boolean FRM_bInhFrbdF4F2_in;
   boolean FRM_bInhInvldF4F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF4F2);
   FRM_bInhInvldF4F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF4F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF4F2_in)
      {
         Ext_bMonRunFrbdF4F2P492 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF4F2P492 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF4F2_in)
      {
         Ext_bMonRunInvldF4F2P492 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF4F2P492 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF4F2P492 = FHCAN_DISABLE;
      Ext_bMonRunInvldF4F2P492 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
