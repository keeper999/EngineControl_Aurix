/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF412_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF412_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN412_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF412_in;
   boolean FRM_bInhDiagShoF412_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF412_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF412);
   FRM_bInhDiagShoF412_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF412);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF412_in)
      {
         Ext_bMonRunMissF412 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF412 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF412_in)
      {
         Ext_bMonRunShoF412 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF412 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF412 = FHCAN_DISABLE;
      Ext_bMonRunShoF412 = FHCAN_DISABLE;
   }
}

void FHCAN412_vidCalcMonFP040Window(void)
{
   boolean FRM_bInhInvldF412_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhInvldF412_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF412);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhInvldF412_in)
      {
         Ext_bMonRunInvldF412P040 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF412P040 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF412P040 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
