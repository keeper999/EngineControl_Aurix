/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF329_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF329_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN329_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF329_in;
   boolean FRM_bInhDiagShoF329_in;
   boolean FRM_bInhChkF329_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhDiagMissF329_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF329);
   FRM_bInhDiagShoF329_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF329);
   FRM_bInhChkF329_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF329);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhDiagMissF329_in)
      {
         Ext_bMonRunMissF329 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF329 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF329_in)
      {
         Ext_bMonRunShoF329 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF329 = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF329_in)
      {
         Ext_bMonRunChkF329 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF329 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF329 = FHCAN_DISABLE;
      Ext_bMonRunShoF329 = FHCAN_DISABLE;
      Ext_bMonRunChkF329 = FHCAN_DISABLE;
   }
}

void FHCAN329_vidCalcMonFP445Window(void)
{
   boolean FRM_bInhFrbdF329_in;
   boolean FRM_bInhInvldF329_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF329_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF329);
   FRM_bInhInvldF329_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF329);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF329_in)
      {
         Ext_bMonRunFrbdF329P445 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF329P445 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF329_in)
      {
         Ext_bMonRunInvldF329P445 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF329P445 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF329P445 = FHCAN_DISABLE;
      Ext_bMonRunInvldF329P445 = FHCAN_DISABLE;
   }
}

void FHCAN329_vidCalcMonFP397Window(void)
{
   boolean FRM_bInhFrbdF329_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF329_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF329);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF329_in)
      {
         Ext_bMonRunFrbdF329P397 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF329P397 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF329P397 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
