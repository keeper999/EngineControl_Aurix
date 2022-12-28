/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF7F2_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF7F2_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN7F2_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF7F2_in;
   boolean FRM_bInhDiagShoF7F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF7F2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF7F2);
   FRM_bInhDiagShoF7F2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF7F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF7F2_in)
      {
         Ext_bMonRunMissF7F2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF7F2 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF7F2_in)
      {
         Ext_bMonRunShoF7F2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF7F2 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF7F2 = FHCAN_DISABLE;
      Ext_bMonRunShoF7F2 = FHCAN_DISABLE;
   }
}

void FHCAN7F2_vidCalcMonFP849Window(void)
{
   boolean FRM_bInhFrbdF7F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF7F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF7F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF7F2_in)
      {
         Ext_bMonRunFrbdF7F2P849 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF7F2P849 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF7F2P849 = FHCAN_DISABLE;
   }
}

void FHCAN7F2_vidCalcMonFP146Window(void)
{
   boolean FRM_bInhFrbdF7F2_in;
   boolean FRM_bInhInvldF7F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF7F2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF7F2);
   FRM_bInhInvldF7F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF7F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF7F2_in)
      {
         Ext_bMonRunFrbdF7F2P146 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF7F2P146 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF7F2_in)
      {
         Ext_bMonRunInvldF7F2P146 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF7F2P146 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF7F2P146 = FHCAN_DISABLE;
      Ext_bMonRunInvldF7F2P146 = FHCAN_DISABLE;
   }
}

void FHCAN7F2_vidCalcMonFP015Window(void)
{
   boolean FRM_bInhInvldF7F2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF7F2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF7F2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF7F2_in)
      {
         Ext_bMonRunInvldF7F2P015 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF7F2P015 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF7F2P015 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
