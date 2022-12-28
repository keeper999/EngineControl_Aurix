/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF5B2_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN5B2_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_CONTEXTE_1_5B2;


   VEMS_vidGET(Ctrl_CONTEXTE_1_5B2, Local_bCtrl_CONTEXTE_1_5B2);
   if (ACTIVATED == Local_bCtrl_CONTEXTE_1_5B2)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF5B2)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF5B2 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF5B2,
                         Ext_bDgoShoF5B2,
                         Ext_bMonRunShoF5B2,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF5B2 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF5B2,
                         Ext_bDgoShoF5B2,
                         Ext_bMonRunShoF5B2,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN5B2_vidMonInvldP146Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF5B2P146)
   {
      if ((ISCAN_u8N8F5B2P146 == 255) || (ISCAN_u8N8F5B2P146 == 254))
      {
         Ext_bDgoInvldF5B2P146 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF5B2P146 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF5B2P146,
                   Ext_bDgoInvldF5B2P146,
                   Ext_bMonRunInvldF5B2P146,
                   DIAG_DISPO);
   }
}

void FHCAN5B2_vidMonFrbdP146Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF5B2P146)
   {
      if ((ISCAN_u8N8F5B2P146 == 251))
      {
         Ext_bDgoFrbdF5B2P146 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF5B2P146 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF5B2P146,
                   Ext_bDgoFrbdF5B2P146,
                   Ext_bMonRunFrbdF5B2P146,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
