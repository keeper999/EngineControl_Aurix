/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF5B2_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF5B2_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN5B2_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF5B2_in;
   boolean FRM_bInhDiagShoF5B2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF5B2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF5B2);
   FRM_bInhDiagShoF5B2_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF5B2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF5B2_in)
      {
         Ext_bMonRunMissF5B2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF5B2 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF5B2_in)
      {
         Ext_bMonRunShoF5B2 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF5B2 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF5B2 = FHCAN_DISABLE;
      Ext_bMonRunShoF5B2 = FHCAN_DISABLE;
   }
}

void FHCAN5B2_vidCalcMonFP146Window(void)
{
   boolean FRM_bInhFrbdF5B2_in;
   boolean FRM_bInhInvldF5B2_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhFrbdF5B2_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF5B2);
   FRM_bInhInvldF5B2_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF5B2);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhFrbdF5B2_in)
      {
         Ext_bMonRunFrbdF5B2P146 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF5B2P146 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF5B2_in)
      {
         Ext_bMonRunInvldF5B2P146 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF5B2P146 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF5B2P146 = FHCAN_DISABLE;
      Ext_bMonRunInvldF5B2P146 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
