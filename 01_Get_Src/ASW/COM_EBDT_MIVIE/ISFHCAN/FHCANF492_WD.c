/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF492_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF492_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN492_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF492_in;
   boolean FRM_bInhDiagShoF492_in;
   boolean Local_bExt_bMonRunBSItoCMM;


   FRM_bInhDiagMissF492_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF492);
   FRM_bInhDiagShoF492_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF492);

   VEMS_vidGET(Ext_bMonRunBSItoCMM, Local_bExt_bMonRunBSItoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBSItoCMM)
   {
      if (!FRM_bInhDiagMissF492_in)
      {
         Ext_bMonRunMissF492 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF492 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF492_in)
      {
         Ext_bMonRunShoF492 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF492 = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF492 = FHCAN_DISABLE;
      Ext_bMonRunShoF492 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
