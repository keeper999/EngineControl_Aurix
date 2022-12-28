/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF3C9_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN3C9_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_V2_BV_3C9;


   VEMS_vidGET(Ctrl_V2_BV_3C9, Local_bCtrl_V2_BV_3C9);
   if (ACTIVATED == Local_bCtrl_V2_BV_3C9)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF3C9)
      {
         if (Dlc < 6)
         {
            Ext_bDgoShoF3C9 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF3C9,
                         Ext_bDgoShoF3C9,
                         Ext_bMonRunShoF3C9,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF3C9 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF3C9,
                         Ext_bDgoShoF3C9,
                         Ext_bMonRunShoF3C9,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN3C9_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_V2_BV_3C9;


   VEMS_vidGET(Ctrl_V2_BV_3C9, Local_bCtrl_V2_BV_3C9);
   if (ACTIVATED == Local_bCtrl_V2_BV_3C9)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF3C9)
       {
         if (!ISCAN_bSecuChkOKF3C9)
         {
            Ext_bDgoChkF3C9 = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF3C9 = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF3C9,
                      Ext_bDgoChkF3C9,
                      Ext_bMonRunChkF3C9,
                      DIAG_DISPO);
      }
   }
}

void FHCAN3C9_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_V2_BV_3C9;


   VEMS_vidGET(Ctrl_V2_BV_3C9, Local_bCtrl_V2_BV_3C9);
   if (ACTIVATED == Local_bCtrl_V2_BV_3C9)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF3C9)
      {
         Ext_bDgoCntF3C9 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF3C9,
                      Ext_bDgoCntF3C9,
                      Ext_bMonRunCntF3C9,
                      DIAG_DISPO);
      }
   }
}

void FHCAN3C9_vidMonInvldP363Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3C9P363)
   {
      if (ISCAN_u8N8F3C9P363 == 255)
      {
         Ext_bDgoInvldF3C9P363 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3C9P363 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3C9P363,
                   Ext_bDgoInvldF3C9P363,
                   Ext_bMonRunInvldF3C9P363,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonFrbdP481Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3C9P481)
   {
      if (((4 <= ISCAN_u8N3F3C9P481) && (ISCAN_u8N3F3C9P481 <= 7)))
      {
         Ext_bDgoFrbdF3C9P481 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3C9P481 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3C9P481,
                   Ext_bDgoFrbdF3C9P481,
                   Ext_bMonRunFrbdF3C9P481,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonInvldP364Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3C9P364)
   {
      if (ISCAN_u16N12F3C9P364 == 4095)
      {
         Ext_bDgoInvldF3C9P364 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3C9P364 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3C9P364,
                   Ext_bDgoInvldF3C9P364,
                   Ext_bMonRunInvldF3C9P364,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonFrbdP364Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3C9P364)
   {
      if (((4001 <= ISCAN_u16N12F3C9P364) && (ISCAN_u16N12F3C9P364 <= 4094)))
      {
         Ext_bDgoFrbdF3C9P364 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3C9P364 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3C9P364,
                   Ext_bDgoFrbdF3C9P364,
                   Ext_bMonRunFrbdF3C9P364,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonInvldP482Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3C9P482)
   {
      if (ISCAN_u8N6F3C9P482 == 63)
      {
         Ext_bDgoInvldF3C9P482 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3C9P482 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3C9P482,
                   Ext_bDgoInvldF3C9P482,
                   Ext_bMonRunInvldF3C9P482,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonFrbdP482Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3C9P482)
   {
      if (((51 <= ISCAN_u8N6F3C9P482) && (ISCAN_u8N6F3C9P482 <= 62)))
      {
         Ext_bDgoFrbdF3C9P482 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3C9P482 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3C9P482,
                   Ext_bDgoFrbdF3C9P482,
                   Ext_bMonRunFrbdF3C9P482,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonInvldP483Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3C9P483)
   {
      if (ISCAN_u16N10F3C9P483 == 1023)
      {
         Ext_bDgoInvldF3C9P483 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3C9P483 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3C9P483,
                   Ext_bDgoInvldF3C9P483,
                   Ext_bMonRunInvldF3C9P483,
                   DIAG_DISPO);
   }
}

void FHCAN3C9_vidMonFrbdP483Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3C9P483)
   {
      if (((1001 <= ISCAN_u16N10F3C9P483) && (ISCAN_u16N10F3C9P483 <= 1022)))
      {
         Ext_bDgoFrbdF3C9P483 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3C9P483 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3C9P483,
                   Ext_bDgoFrbdF3C9P483,
                   Ext_bMonRunFrbdF3C9P483,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
