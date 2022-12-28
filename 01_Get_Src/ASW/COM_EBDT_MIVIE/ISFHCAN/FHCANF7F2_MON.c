/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF7F2_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN7F2_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_CONTEXTE_1_7F2;


   VEMS_vidGET(Ctrl_CONTEXTE_1_7F2, Local_bCtrl_CONTEXTE_1_7F2);
   if (ACTIVATED == Local_bCtrl_CONTEXTE_1_7F2)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF7F2)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF7F2 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF7F2,
                         Ext_bDgoShoF7F2,
                         Ext_bMonRunShoF7F2,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF7F2 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF7F2,
                         Ext_bDgoShoF7F2,
                         Ext_bMonRunShoF7F2,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN7F2_vidMonFrbdP849Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF7F2P849)
   {
      if (((0 <= ISCAN_u8N8F7F2P849) && (ISCAN_u8N8F7F2P849 <= 140)) || ((144 <= ISCAN_u8N8F7F2P849) && (ISCAN_u8N8F7F2P849 <= 255)))
      {
         Ext_bDgoFrbdF7F2P849 = FHCAN_DETECTED;
         Ext_bDgoLIDF7F2 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF7F2P849 = FHCAN_NOT_DETECTED;
         Ext_bDgoLIDF7F2 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF7F2P849,
                   Ext_bDgoFrbdF7F2P849,
                   Ext_bMonRunFrbdF7F2P849,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LIDF7F2,
                   Ext_bDgoLIDF7F2,
                   Ext_bMonRunFrbdF7F2P849,
                   DIAG_DISPO);
   }
}

void FHCAN7F2_vidMonInvldP146Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF7F2P146)
   {
      if ((ISCAN_u8N8F7F2P146 == 255) || (ISCAN_u8N8F7F2P146 == 254))
      {
         Ext_bDgoInvldF7F2P146 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF7F2P146 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF7F2P146,
                   Ext_bDgoInvldF7F2P146,
                   Ext_bMonRunInvldF7F2P146,
                   DIAG_DISPO);
   }
}

void FHCAN7F2_vidMonFrbdP146Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF7F2P146)
   {
      if ((ISCAN_u8N8F7F2P146 == 251))
      {
         Ext_bDgoFrbdF7F2P146 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF7F2P146 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF7F2P146,
                   Ext_bDgoFrbdF7F2P146,
                   Ext_bMonRunFrbdF7F2P146,
                   DIAG_DISPO);
   }
}

void FHCAN7F2_vidMonInvldP015Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF7F2P015)
   {
      if (ISCAN_u32N24F7F2P015 == 16777215)
      {
         Ext_bDgoInvldF7F2P015 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF7F2P015 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF7F2P015,
                   Ext_bDgoInvldF7F2P015,
                   Ext_bMonRunInvldF7F2P015,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
