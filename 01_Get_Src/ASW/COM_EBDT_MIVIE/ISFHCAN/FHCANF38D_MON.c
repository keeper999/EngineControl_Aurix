/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF38D_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN38D_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_ABR_38D;


   VEMS_vidGET(Ctrl_ABR_38D, Local_bCtrl_ABR_38D);
   if (ACTIVATED == Local_bCtrl_ABR_38D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF38D)
      {
         if (Dlc < 5)
         {
            Ext_bDgoShoF38D = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF38D,
                         Ext_bDgoShoF38D,
                         Ext_bMonRunShoF38D,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF38D = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF38D,
                         Ext_bDgoShoF38D,
                         Ext_bMonRunShoF38D,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN38D_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_ABR_38D;


   VEMS_vidGET(Ctrl_ABR_38D, Local_bCtrl_ABR_38D);
   if (ACTIVATED == Local_bCtrl_ABR_38D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF38D)
       {
         if (!ISCAN_bSecuChkOKF38D)
         {
            Ext_bDgoChkF38D = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF38D = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF38D,
                      Ext_bDgoChkF38D,
                      Ext_bMonRunChkF38D,
                      DIAG_DISPO);
      }
   }
}

void FHCAN38D_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_ABR_38D;


   VEMS_vidGET(Ctrl_ABR_38D, Local_bCtrl_ABR_38D);
   if (ACTIVATED == Local_bCtrl_ABR_38D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF38D)
      {
         Ext_bDgoCntF38D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF38D,
                      Ext_bDgoCntF38D,
                      Ext_bMonRunCntF38D,
                      DIAG_DISPO);
      }
   }
}

void FHCAN38D_vidMonInvldP010Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF38DP010)
   {
      if (ISCAN_u16N16F38DP010 == 65535)
      {
         Ext_bDgoInvldF38DP010 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF38DP010 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF38DP010,
                   Ext_bDgoInvldF38DP010,
                   Ext_bMonRunInvldF38DP010,
                   DIAG_DISPO);
   }
}

void FHCAN38D_vidMonInvldP052Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF38DP052)
   {
      if (ISCAN_u8N8F38DP052 == 255)
      {
         Ext_bDgoInvldF38DP052 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF38DP052 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF38DP052,
                   Ext_bDgoInvldF38DP052,
                   Ext_bMonRunInvldF38DP052,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
