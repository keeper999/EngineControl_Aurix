/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF572_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF572_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN572_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF572_in;
   boolean FRM_bInhDiagShoF572_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF572_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF572);
   FRM_bInhDiagShoF572_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF572);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF572_in)
      {
         Ext_bMonRunMissF572 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF572 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF572_in)
      {
         Ext_bMonRunShoF572 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF572 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF572 = FHCAN_DISABLE;
      Ext_bMonRunShoF572 = FHCAN_DISABLE;
   }
}

void FHCAN572_vidCalcMonFPM1360Window(void)
{
   boolean FRM_bInhFrbdF572_in;
   boolean FRM_bInhInvldF572_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF572_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF572);
   FRM_bInhInvldF572_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF572);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF572_in)
      {
         Ext_bMonRunFrbdF572PM1360 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF572PM1360 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF572_in)
      {
         Ext_bMonRunInvldF572PM1360 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF572PM1360 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF572PM1360 = FHCAN_DISABLE;
      Ext_bMonRunInvldF572PM1360 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
