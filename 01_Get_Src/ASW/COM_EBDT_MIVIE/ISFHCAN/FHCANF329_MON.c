/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF329_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN329_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_STT_BV_329;


   VEMS_vidGET(Ctrl_STT_BV_329, Local_bCtrl_STT_BV_329);
   if (ACTIVATED == Local_bCtrl_STT_BV_329)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF329)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF329 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF329,
                         Ext_bDgoShoF329,
                         Ext_bMonRunShoF329,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF329 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF329,
                         Ext_bDgoShoF329,
                         Ext_bMonRunShoF329,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN329_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_STT_BV_329;


   VEMS_vidGET(Ctrl_STT_BV_329, Local_bCtrl_STT_BV_329);
   if (ACTIVATED == Local_bCtrl_STT_BV_329)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF329)
       {
         if (!ISCAN_bSecuChkOKF329)
         {
            Ext_bDgoChkF329 = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF329 = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF329,
                      Ext_bDgoChkF329,
                      Ext_bMonRunChkF329,
                      DIAG_DISPO);
      }
   }
}

void FHCAN329_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_STT_BV_329;


   VEMS_vidGET(Ctrl_STT_BV_329, Local_bCtrl_STT_BV_329);
   if (ACTIVATED == Local_bCtrl_STT_BV_329)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF329)
      {
         Ext_bDgoCntF329 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF329,
                      Ext_bDgoCntF329,
                      Ext_bMonRunCntF329,
                      DIAG_DISPO);
      }
   }
}

void FHCAN329_vidMonInvldP445Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF329P445)
   {
      if (ISCAN_u8N8F329P445 == 255)
      {
         Ext_bDgoInvldF329P445 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF329P445 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF329P445,
                   Ext_bDgoInvldF329P445,
                   Ext_bMonRunInvldF329P445,
                   DIAG_DISPO);
   }
}

void FHCAN329_vidMonFrbdP445Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF329P445)
   {
      if (((201 <= ISCAN_u8N8F329P445) && (ISCAN_u8N8F329P445 <= 254)))
      {
         Ext_bDgoFrbdF329P445 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF329P445 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF329P445,
                   Ext_bDgoFrbdF329P445,
                   Ext_bMonRunFrbdF329P445,
                   DIAG_DISPO);
   }
}

void FHCAN329_vidMonFrbdP397Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF329P397)
   {
      if ((ISCAN_u8N2F329P397 == 0))
      {
         Ext_bDgoFrbdF329P397 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF329P397 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF329P397,
                   Ext_bDgoFrbdF329P397,
                   Ext_bMonRunFrbdF329P397,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
