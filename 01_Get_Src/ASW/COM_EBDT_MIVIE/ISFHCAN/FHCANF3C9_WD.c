/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3C9_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF3C9_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN3C9_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF3C9_in;
   boolean FRM_bInhDiagShoF3C9_in;
   boolean FRM_bInhChkF3C9_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhDiagMissF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF3C9);
   FRM_bInhDiagShoF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF3C9);
   FRM_bInhChkF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF3C9);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhDiagMissF3C9_in)
      {
         Ext_bMonRunMissF3C9 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF3C9 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF3C9_in)
      {
         Ext_bMonRunShoF3C9 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF3C9 = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF3C9_in)
      {
         Ext_bMonRunChkF3C9 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF3C9 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF3C9 = FHCAN_DISABLE;
      Ext_bMonRunShoF3C9 = FHCAN_DISABLE;
      Ext_bMonRunChkF3C9 = FHCAN_DISABLE;
   }
}

void FHCAN3C9_vidCalcMonFP363Window(void)
{
   boolean FRM_bInhInvldF3C9_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhInvldF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3C9);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhInvldF3C9_in)
      {
         Ext_bMonRunInvldF3C9P363 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3C9P363 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF3C9P363 = FHCAN_DISABLE;
   }
}

void FHCAN3C9_vidCalcMonFP481Window(void)
{
   boolean FRM_bInhFrbdF3C9_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3C9);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF3C9_in)
      {
         Ext_bMonRunFrbdF3C9P481 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3C9P481 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3C9P481 = FHCAN_DISABLE;
   }
}

void FHCAN3C9_vidCalcMonFP364Window(void)
{
   boolean FRM_bInhFrbdF3C9_in;
   boolean FRM_bInhInvldF3C9_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3C9);
   FRM_bInhInvldF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3C9);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF3C9_in)
      {
         Ext_bMonRunFrbdF3C9P364 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3C9P364 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF3C9_in)
      {
         Ext_bMonRunInvldF3C9P364 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3C9P364 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3C9P364 = FHCAN_DISABLE;
      Ext_bMonRunInvldF3C9P364 = FHCAN_DISABLE;
   }
}

void FHCAN3C9_vidCalcMonFP482Window(void)
{
   boolean FRM_bInhFrbdF3C9_in;
   boolean FRM_bInhInvldF3C9_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3C9);
   FRM_bInhInvldF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3C9);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF3C9_in)
      {
         Ext_bMonRunFrbdF3C9P482 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3C9P482 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF3C9_in)
      {
         Ext_bMonRunInvldF3C9P482 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3C9P482 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3C9P482 = FHCAN_DISABLE;
      Ext_bMonRunInvldF3C9P482 = FHCAN_DISABLE;
   }
}

void FHCAN3C9_vidCalcMonFP483Window(void)
{
   boolean FRM_bInhFrbdF3C9_in;
   boolean FRM_bInhInvldF3C9_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3C9);
   FRM_bInhInvldF3C9_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3C9);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF3C9_in)
      {
         Ext_bMonRunFrbdF3C9P483 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3C9P483 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF3C9_in)
      {
         Ext_bMonRunInvldF3C9P483 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3C9P483 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3C9P483 = FHCAN_DISABLE;
      Ext_bMonRunInvldF3C9P483 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
