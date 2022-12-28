/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3AD_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF3AD_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN3AD_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF3AD_in;
   boolean FRM_bInhDiagShoF3AD_in;
   boolean FRM_bInhChkF3AD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF3AD_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF3AD);
   FRM_bInhDiagShoF3AD_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF3AD);
   FRM_bInhChkF3AD_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF3AD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF3AD_in)
      {
         Ext_bMonRunMissF3AD = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF3AD = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF3AD_in)
      {
         Ext_bMonRunShoF3AD = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF3AD = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF3AD_in)
      {
         Ext_bMonRunChkF3AD = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF3AD = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF3AD = FHCAN_DISABLE;
      Ext_bMonRunShoF3AD = FHCAN_DISABLE;
      Ext_bMonRunChkF3AD = FHCAN_DISABLE;
   }
}

void FHCAN3AD_vidCalcMonFP337Window(void)
{
   boolean FRM_bInhFrbdF3AD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF3AD_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3AD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF3AD_in)
      {
         Ext_bMonRunFrbdF3ADP337 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3ADP337 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3ADP337 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
