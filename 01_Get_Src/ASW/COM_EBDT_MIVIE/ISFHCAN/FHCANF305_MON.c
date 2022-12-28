/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF305_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN305_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_VOL_305;


   VEMS_vidGET(Ctrl_VOL_305, Local_bCtrl_VOL_305);
   if (ACTIVATED == Local_bCtrl_VOL_305)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF305)
      {
         if (Dlc < 5)
         {
            Ext_bDgoShoF305 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF305,
                         Ext_bDgoShoF305,
                         Ext_bMonRunShoF305,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF305 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF305,
                         Ext_bDgoShoF305,
                         Ext_bMonRunShoF305,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN305_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_VOL_305;


   VEMS_vidGET(Ctrl_VOL_305, Local_bCtrl_VOL_305);
   if (ACTIVATED == Local_bCtrl_VOL_305)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF305)
       {
         if (!ISCAN_bSecuChkOKF305)
         {
            Ext_bDgoChkF305 = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF305 = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF305,
                      Ext_bDgoChkF305,
                      Ext_bMonRunChkF305,
                      DIAG_DISPO);
      }
   }
}

void FHCAN305_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_VOL_305;


   VEMS_vidGET(Ctrl_VOL_305, Local_bCtrl_VOL_305);
   if (ACTIVATED == Local_bCtrl_VOL_305)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF305)
      {
         Ext_bDgoCntF305 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF305,
                      Ext_bDgoCntF305,
                      Ext_bMonRunCntF305,
                      DIAG_DISPO);
      }
   }
}

void FHCAN305_vidMonInvldP537Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF305P537)
   {
      if (ISCAN_s16N16F305P537 == 32767)
      {
         Ext_bDgoInvldF305P537 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF305P537 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF305P537,
                   Ext_bDgoInvldF305P537,
                   Ext_bMonRunInvldF305P537,
                   DIAG_DISPO);
   }
}

void FHCAN305_vidMonFrbdP537Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF305P537)
   {
      if (((7801 <= ISCAN_s16N16F305P537) && (ISCAN_s16N16F305P537 <= 32766)) || ((32768 <= ISCAN_s16N16F305P537) && (ISCAN_s16N16F305P537 <= 57735)))
      {
         Ext_bDgoFrbdF305P537 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF305P537 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF305P537,
                   Ext_bDgoFrbdF305P537,
                   Ext_bMonRunFrbdF305P537,
                   DIAG_DISPO);
   }
}

void FHCAN305_vidMonInvldP538Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF305P538)
   {
      if (ISCAN_u8N8F305P538 == 255)
      {
         Ext_bDgoInvldF305P538 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF305P538 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF305P538,
                   Ext_bDgoInvldF305P538,
                   Ext_bMonRunInvldF305P538,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
