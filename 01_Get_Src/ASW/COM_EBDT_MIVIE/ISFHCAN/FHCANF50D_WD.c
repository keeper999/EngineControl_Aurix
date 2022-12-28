/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50D_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF50D_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN50D_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF50D_in;
   boolean FRM_bInhDiagShoF50D_in;
   boolean FRM_bInhChkF50D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF50D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF50D);
   FRM_bInhDiagShoF50D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF50D);
   FRM_bInhChkF50D_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF50D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF50D_in)
      {
         Ext_bMonRunMissF50D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF50D = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF50D_in)
      {
         Ext_bMonRunShoF50D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF50D = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF50D_in)
      {
         Ext_bMonRunChkF50D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF50D = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF50D = FHCAN_DISABLE;
      Ext_bMonRunShoF50D = FHCAN_DISABLE;
      Ext_bMonRunChkF50D = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
