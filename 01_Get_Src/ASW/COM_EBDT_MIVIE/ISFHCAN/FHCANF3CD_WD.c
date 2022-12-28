/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3CD_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF3CD_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN3CD_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF3CD_in;
   boolean FRM_bInhDiagShoF3CD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhDiagMissF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF3CD);
   FRM_bInhDiagShoF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF3CD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhDiagMissF3CD_in)
      {
         Ext_bMonRunMissF3CD = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF3CD = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF3CD_in)
      {
         Ext_bMonRunShoF3CD = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF3CD = FHCAN_DISABLE;
      }

   }
   else
   {
      Ext_bMonRunMissF3CD = FHCAN_DISABLE;
      Ext_bMonRunShoF3CD = FHCAN_DISABLE;
   }
}

void FHCAN3CD_vidCalcMonFP225Window(void)
{
   boolean FRM_bInhInvldF3CD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3CD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF3CD_in)
      {
         Ext_bMonRunInvldF3CDP225 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3CDP225 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF3CDP225 = FHCAN_DISABLE;
   }
}

void FHCAN3CD_vidCalcMonFPM1387Window(void)
{
   boolean FRM_bInhFrbdF3CD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3CD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF3CD_in)
      {
         Ext_bMonRunFrbdF3CDPM1387 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3CDPM1387 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3CDPM1387 = FHCAN_DISABLE;
   }
}

void FHCAN3CD_vidCalcMonFP515Window(void)
{
   boolean FRM_bInhInvldF3CD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhInvldF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3CD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhInvldF3CD_in)
      {
         Ext_bMonRunInvldF3CDP515 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3CDP515 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF3CDP515 = FHCAN_DISABLE;
   }
}

void FHCAN3CD_vidCalcMonFP319Window(void)
{
   boolean FRM_bInhFrbdF3CD_in;
   boolean FRM_bInhInvldF3CD_in;
   boolean Local_bExt_bMonRunUCFreintoCMM;


   FRM_bInhFrbdF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF3CD);
   FRM_bInhInvldF3CD_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF3CD);

   VEMS_vidGET(Ext_bMonRunUCFreintoCMM, Local_bExt_bMonRunUCFreintoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunUCFreintoCMM)
   {
      if (!FRM_bInhFrbdF3CD_in)
      {
         Ext_bMonRunFrbdF3CDP319 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF3CDP319 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF3CD_in)
      {
         Ext_bMonRunInvldF3CDP319 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF3CDP319 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF3CDP319 = FHCAN_DISABLE;
      Ext_bMonRunInvldF3CDP319 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
