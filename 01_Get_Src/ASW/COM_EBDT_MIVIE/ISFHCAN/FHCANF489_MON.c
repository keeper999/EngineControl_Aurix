/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF489_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN489_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_V2_BV_489;


   VEMS_vidGET(Ctrl_V2_BV_489, Local_bCtrl_V2_BV_489);
   if (ACTIVATED == Local_bCtrl_V2_BV_489)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF489)
      {
         if (Dlc < 4)
         {
            Ext_bDgoShoF489 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF489,
                         Ext_bDgoShoF489,
                         Ext_bMonRunShoF489,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF489 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF489,
                         Ext_bDgoShoF489,
                         Ext_bMonRunShoF489,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN489_vidMonInvldP102Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF489P102)
   {
      if (ISCAN_u8N8F489P102 == 255)
      {
         Ext_bDgoInvldF489P102 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF489P102 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF489P102,
                   Ext_bDgoInvldF489P102,
                   Ext_bMonRunInvldF489P102,
                   DIAG_DISPO);
   }
}

void FHCAN489_vidMonInvldP254Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF489P254)
   {
      if (ISCAN_u16N12F489P254 == 4095)
      {
         Ext_bDgoInvldF489P254 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF489P254 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF489P254,
                   Ext_bDgoInvldF489P254,
                   Ext_bMonRunInvldF489P254,
                   DIAG_DISPO);
   }
}

void FHCAN489_vidMonFrbdP254Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF489P254)
   {
      if (((3901 <= ISCAN_u16N12F489P254) && (ISCAN_u16N12F489P254 <= 4094)))
      {
         Ext_bDgoFrbdF489P254 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF489P254 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF489P254,
                   Ext_bDgoFrbdF489P254,
                   Ext_bMonRunFrbdF489P254,
                   DIAG_DISPO);
   }
}

void FHCAN489_vidMonInvldP218Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF489P218)
   {
      if (ISCAN_u8N8F489P218 == 255)
      {
         Ext_bDgoInvldF489P218 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF489P218 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF489P218,
                   Ext_bDgoInvldF489P218,
                   Ext_bMonRunInvldF489P218,
                   DIAG_DISPO);
   }
}

void FHCAN489_vidMonFrbdP218Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF489P218)
   {
      if (((101 <= ISCAN_u8N8F489P218) && (ISCAN_u8N8F489P218 <= 254)))
      {
         Ext_bDgoFrbdF489P218 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF489P218 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF489P218,
                   Ext_bDgoFrbdF489P218,
                   Ext_bMonRunFrbdF489P218,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
