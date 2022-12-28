/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF792_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF792_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN792_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF792_in;
   boolean FRM_bInhDiagShoF792_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF792_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF792);
   FRM_bInhDiagShoF792_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF792);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF792_in)
      {
         Ext_bMonRunMissF792 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF792 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF792_in)
      {
         Ext_bMonRunShoF792 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF792 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF792 = FHCAN_DISABLE;
      Ext_bMonRunShoF792 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
