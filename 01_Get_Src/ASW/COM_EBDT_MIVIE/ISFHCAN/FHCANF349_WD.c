/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF349_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF349_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"



void FHCAN349_vidCalcMonWindow(void)
{
   boolean FRM_bInhDiagMissF349_in;
   boolean FRM_bInhDiagShoF349_in;
   boolean FRM_bInhChkF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhDiagMissF349_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGMISSF349);
   FRM_bInhDiagShoF349_in = GDGAR_bGetFRM(FRM_FRM_INHDIAGSHOF349);
   FRM_bInhChkF349_in = GDGAR_bGetFRM(FRM_FRM_INHCHECKF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhDiagMissF349_in)
      {
         Ext_bMonRunMissF349 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunMissF349 = FHCAN_DISABLE;
      }

      if (!FRM_bInhDiagShoF349_in)
      {
         Ext_bMonRunShoF349 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunShoF349 = FHCAN_DISABLE;
      }

      if (!FRM_bInhChkF349_in)
      {
         Ext_bMonRunChkF349 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunChkF349 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunMissF349 = FHCAN_DISABLE;
      Ext_bMonRunShoF349 = FHCAN_DISABLE;
      Ext_bMonRunChkF349 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP360Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349P360 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349P360 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349P360 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP057Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349P057 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349P057 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349P057 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP008Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349P008 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349P008 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349P008 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP007Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean FRM_bInhInvldF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);
   FRM_bInhInvldF349_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349P007 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349P007 = FHCAN_DISABLE;
      }
      if (!FRM_bInhInvldF349_in)
      {
         Ext_bMonRunInvldF349P007 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF349P007 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349P007 = FHCAN_DISABLE;
      Ext_bMonRunInvldF349P007 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP055Window(void)
{
   boolean FRM_bInhInvldF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhInvldF349_in = GDGAR_bGetFRM(FRM_FRM_INHINVLDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhInvldF349_in)
      {
         Ext_bMonRunInvldF349P055 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunInvldF349P055 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunInvldF349P055 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP287Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349P287 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349P287 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349P287 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFPM1434Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349PM1434 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349PM1434 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349PM1434 = FHCAN_DISABLE;
   }
}

void FHCAN349_vidCalcMonFP166Window(void)
{
   boolean FRM_bInhFrbdF349_in;
   boolean Local_bExt_bMonRunBVtoCMM;


   FRM_bInhFrbdF349_in = GDGAR_bGetFRM(FRM_FRM_INHFRBDF349);

   VEMS_vidGET(Ext_bMonRunBVtoCMM, Local_bExt_bMonRunBVtoCMM);

   if (FHCAN_ENABLE == Local_bExt_bMonRunBVtoCMM)
   {
      if (!FRM_bInhFrbdF349_in)
      {
         Ext_bMonRunFrbdF349P166 = FHCAN_ENABLE;
      }
      else
      {
         Ext_bMonRunFrbdF349P166 = FHCAN_DISABLE;
      }
   }
   else
   {
      Ext_bMonRunFrbdF349P166 = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
