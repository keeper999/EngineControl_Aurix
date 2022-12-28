/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF612_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN612_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_612;


   VEMS_vidGET(Ctrl_BSI_612, Local_bCtrl_BSI_612);
   if (ACTIVATED == Local_bCtrl_BSI_612)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF612)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF612 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF612,
                         Ext_bDgoShoF612,
                         Ext_bMonRunShoF612,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF612 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF612,
                         Ext_bDgoShoF612,
                         Ext_bMonRunShoF612,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN612_vidMonFrbdP927Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF612P927)
   {
      if ((ISCAN_u8N2F612P927 == 3))
      {
         Ext_bDgoFrbdF612P927 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF612P927 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF612P927,
                   Ext_bDgoFrbdF612P927,
                   Ext_bMonRunFrbdF612P927,
                   DIAG_DISPO);
   }
}

void FHCAN612_vidMonInvldP260Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF612P260)
   {
      if (ISCAN_u8N8F612P260 == 255)
      {
         Ext_bDgoInvldF612P260 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF612P260 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF612P260,
                   Ext_bDgoInvldF612P260,
                   Ext_bMonRunInvldF612P260,
                   DIAG_DISPO);
   }
}

void FHCAN612_vidMonInvldP436Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF612P436)
   {
      if (ISCAN_u16N11F612P436 == 2047)
      {
         Ext_bDgoInvldF612P436 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF612P436 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF612P436,
                   Ext_bDgoInvldF612P436,
                   Ext_bMonRunInvldF612P436,
                   DIAG_DISPO);
   }
}

void FHCAN612_vidMonFrbdP436Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF612P436)
   {
      if (((1301 <= ISCAN_u16N11F612P436) && (ISCAN_u16N11F612P436 <= 2045)))
      {
         Ext_bDgoFrbdF612P436 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF612P436 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF612P436,
                   Ext_bDgoFrbdF612P436,
                   Ext_bMonRunFrbdF612P436,
                   DIAG_DISPO);
   }
}

void FHCAN612_vidMonInvldP705Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF612P705)
   {
      if (ISCAN_u8N3F612P705 == 7)
      {
         Ext_bDgoInvldF612P705 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF612P705 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF612P705,
                   Ext_bDgoInvldF612P705,
                   Ext_bMonRunInvldF612P705,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
