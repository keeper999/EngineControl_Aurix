/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF34D_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN34D_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_CDS_34D;


   VEMS_vidGET(Ctrl_CDS_34D, Local_bCtrl_CDS_34D);
   if (ACTIVATED == Local_bCtrl_CDS_34D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF34D)
      {
         if (Dlc < 5)
         {
            Ext_bDgoShoF34D = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF34D,
                         Ext_bDgoShoF34D,
                         Ext_bMonRunShoF34D,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF34D = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF34D,
                         Ext_bDgoShoF34D,
                         Ext_bMonRunShoF34D,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN34D_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_CDS_34D;


   VEMS_vidGET(Ctrl_CDS_34D, Local_bCtrl_CDS_34D);
   if (ACTIVATED == Local_bCtrl_CDS_34D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF34D)
      {
         Ext_bDgoCntF34D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF34D,
                      Ext_bDgoCntF34D,
                      Ext_bMonRunCntF34D,
                      DIAG_DISPO);
      }
   }
}

void FHCAN34D_vidMonFrbdP047Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF34DP047)
   {
      if (((1 <= ISCAN_u8N3F34DP047) && (ISCAN_u8N3F34DP047 <= 4)) || (ISCAN_u8N3F34DP047 == 7))
      {
         Ext_bDgoFrbdF34DP047 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF34DP047 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF34DP047,
                   Ext_bDgoFrbdF34DP047,
                   Ext_bMonRunFrbdF34DP047,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonFrbdP043Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF34DP043)
   {
      if (((251 <= ISCAN_u8N8F34DP043) && (ISCAN_u8N8F34DP043 <= 255)))
      {
         Ext_bDgoFrbdF34DP043 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF34DP043 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF34DP043,
                   Ext_bDgoFrbdF34DP043,
                   Ext_bMonRunFrbdF34DP043,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonFrbdP044Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF34DP044)
   {
      if (((251 <= ISCAN_u8N8F34DP044) && (ISCAN_u8N8F34DP044 <= 255)))
      {
         Ext_bDgoFrbdF34DP044 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF34DP044 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF34DP044,
                   Ext_bDgoFrbdF34DP044,
                   Ext_bMonRunFrbdF34DP044,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonFrbdP045Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF34DP045)
   {
      if (((251 <= ISCAN_u8N8F34DP045) && (ISCAN_u8N8F34DP045 <= 255)))
      {
         Ext_bDgoFrbdF34DP045 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF34DP045 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF34DP045,
                   Ext_bDgoFrbdF34DP045,
                   Ext_bMonRunFrbdF34DP045,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonInvldFP0593Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF34DFP0593)
   {
      if (ISCAN_u8N2F34DFP0593 == 3)
      {
         Ext_bDgoInvldF34DFP0593 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF34DFP0593 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF34DFP0593,
                   Ext_bDgoInvldF34DFP0593,
                   Ext_bMonRunInvldF34DFP0593,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonFrbdFP0593Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF34DFP0593)
   {
      if ((ISCAN_u8N2F34DFP0593 == 2))
      {
         Ext_bDgoFrbdF34DFP0593 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF34DFP0593 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF34DFP0593,
                   Ext_bDgoFrbdF34DFP0593,
                   Ext_bMonRunFrbdF34DFP0593,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonInvldPM1413Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF34DPM1413)
   {
      if (ISCAN_u8N6F34DPM1413 == 63)
      {
         Ext_bDgoInvldF34DPM1413 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF34DPM1413 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF34DPM1413,
                   Ext_bDgoInvldF34DPM1413,
                   Ext_bMonRunInvldF34DPM1413,
                   DIAG_DISPO);
   }
}

void FHCAN34D_vidMonFrbdPM1413Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF34DPM1413)
   {
      if ((ISCAN_u8N6F34DPM1413 == 61))
      {
         Ext_bDgoFrbdF34DPM1413 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF34DPM1413 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF34DPM1413,
                   Ext_bDgoFrbdF34DPM1413,
                   Ext_bMonRunFrbdF34DPM1413,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
