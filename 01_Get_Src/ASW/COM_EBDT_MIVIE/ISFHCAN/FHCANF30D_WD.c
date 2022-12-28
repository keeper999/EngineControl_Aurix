/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF30D_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF30D_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN30D_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF30D_in;
   boolean FRM_bInhDiagShoF30D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF30D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF30D);
   FRM_bInhDiagShoF30D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF30D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF30D_in)
      {
         Ext_bMonRunMissF30D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF30D = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF30D_in)
      {
         Ext_bMonRunShoF30D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF30D = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF30D = FHCAN_DISABLE;
      Ext_bMonRunShoF30D = FHCAN_DISABLE;
   }
}

void FHCAN30D_vidCalcMonFP263Window(void)
{
   boolean FRM_bInhInvldF30D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF30D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF30D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF30D_in)
      {
         Ext_bMonRunInvldF30DP263 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF30DP263 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF30DP263 = FHCAN_DISABLE;
   }
}

void FHCAN30D_vidCalcMonFP264Window(void)
{
   boolean FRM_bInhInvldF30D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF30D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF30D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF30D_in)
      {
         Ext_bMonRunInvldF30DP264 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF30DP264 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF30DP264 = FHCAN_DISABLE;
   }
}

void FHCAN30D_vidCalcMonFP265Window(void)
{
   boolean FRM_bInhInvldF30D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF30D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF30D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF30D_in)
      {
         Ext_bMonRunInvldF30DP265 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF30DP265 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF30DP265 = FHCAN_DISABLE;
   }
}

void FHCAN30D_vidCalcMonFP266Window(void)
{
   boolean FRM_bInhInvldF30D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF30D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF30D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF30D_in)
      {
         Ext_bMonRunInvldF30DP266 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF30DP266 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF30DP266 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
