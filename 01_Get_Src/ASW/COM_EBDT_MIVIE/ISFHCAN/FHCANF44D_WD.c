/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF44D_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF44D_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN44D_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF44D_in;
   boolean FRM_bInhDiagShoF44D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF44D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF44D);
   FRM_bInhDiagShoF44D_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF44D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF44D_in)
      {
         Ext_bMonRunMissF44D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF44D = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF44D_in)
      {
         Ext_bMonRunShoF44D = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF44D = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF44D = FHCAN_DISABLE;
      Ext_bMonRunShoF44D = FHCAN_DISABLE;
   }
}

void FHCAN44D_vidCalcMonFFP0535Window(void)
{
   boolean FRM_bInhInvldF44D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF44D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF44D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF44D_in)
      {
         Ext_bMonRunInvldF44DFP0535 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF44DFP0535 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF44DFP0535 = FHCAN_DISABLE;
   }
}

void FHCAN44D_vidCalcMonFP330Window(void)
{
   boolean FRM_bInhInvldF44D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF44D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF44D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF44D_in)
      {
         Ext_bMonRunInvldF44DP330 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF44DP330 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF44DP330 = FHCAN_DISABLE;
   }
}

void FHCAN44D_vidCalcMonFP331Window(void)
{
   boolean FRM_bInhInvldF44D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF44D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF44D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF44D_in)
      {
         Ext_bMonRunInvldF44DP331 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF44DP331 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF44DP331 = FHCAN_DISABLE;
   }
}

void FHCAN44D_vidCalcMonFP354Window(void)
{
   boolean FRM_bInhFrbdF44D_in;
   boolean FRM_bInhInvldF44D_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF44D_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF44D);
   FRM_bInhInvldF44D_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF44D);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF44D_in)
      {
         Ext_bMonRunFrbdF44DP354 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF44DP354 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF44D_in)
      {
         Ext_bMonRunInvldF44DP354 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF44DP354 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF44DP354 = FHCAN_DISABLE;
      Ext_bMonRunInvldF44DP354 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
