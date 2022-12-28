/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4B2_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF4B2_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN4B2_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF4B2_in;
   boolean FRM_bInhDiagShoF4B2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF4B2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF4B2);
   FRM_bInhDiagShoF4B2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF4B2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF4B2_in)
      {
         Ext_bMonRunMissF4B2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF4B2 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF4B2_in)
      {
         Ext_bMonRunShoF4B2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF4B2 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF4B2 = FHCAN_DISABLE;
      Ext_bMonRunShoF4B2 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
