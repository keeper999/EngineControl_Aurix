/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF612_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF612_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN612_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF612_in;
   boolean FRM_bInhDiagShoF612_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF612_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF612);
   FRM_bInhDiagShoF612_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF612);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF612_in)
      {
         Ext_bMonRunMissF612 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF612 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF612_in)
      {
         Ext_bMonRunShoF612 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF612 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF612 = FHCAN_DISABLE;
      Ext_bMonRunShoF612 = FHCAN_DISABLE;
   }
}

void FHCAN612_vidCalcMonFP927Window(void)
{
   boolean FRM_bInhFrbdF612_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF612_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF612);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF612_in)
      {
         Ext_bMonRunFrbdF612P927 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF612P927 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF612P927 = FHCAN_DISABLE;
   }
}

void FHCAN612_vidCalcMonFP260Window(void)
{
   boolean FRM_bInhInvldF612_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF612_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF612);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF612_in)
      {
         Ext_bMonRunInvldF612P260 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF612P260 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF612P260 = FHCAN_DISABLE;
   }
}

void FHCAN612_vidCalcMonFP436Window(void)
{
   boolean FRM_bInhFrbdF612_in;
   boolean FRM_bInhInvldF612_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF612_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF612);
   FRM_bInhInvldF612_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF612);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF612_in)
      {
         Ext_bMonRunFrbdF612P436 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF612P436 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF612_in)
      {
         Ext_bMonRunInvldF612P436 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF612P436 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF612P436 = FHCAN_DISABLE;
      Ext_bMonRunInvldF612P436 = FHCAN_DISABLE;
   }
}

void FHCAN612_vidCalcMonFP705Window(void)
{
   boolean FRM_bInhInvldF612_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF612_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF612);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF612_in)
      {
         Ext_bMonRunInvldF612P705 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF612P705 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF612P705 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
