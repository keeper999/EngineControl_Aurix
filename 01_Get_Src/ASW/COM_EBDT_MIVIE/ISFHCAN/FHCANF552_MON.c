/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF552_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCANBSI_552_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_552;


   VEMS_vidGET(Ctrl_BSI_552, Local_bCtrl_BSI_552);
   if (ACTIVATED == Local_bCtrl_BSI_552)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF552)
      {
         if (Dlc < 5)
         {
            Ext_bDgoShoF552 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF552,
                         Ext_bDgoShoF552,
                         Ext_bMonRunShoF552,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF552,
                         Ext_bDgoShoF552,
                         Ext_bMonRunShoF552,
                         DIAG_DISPO);
         }
      }
   }
}

void FHCANV2_BSI_552_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_V2_BSI_552;


   VEMS_vidGET(Ctrl_V2_BSI_552, Local_bCtrl_V2_BSI_552);
   if (ACTIVATED == Local_bCtrl_V2_BSI_552)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF552)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF552 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF552,
                         Ext_bDgoShoF552,
                         Ext_bMonRunShoF552,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF552 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF552,
                         Ext_bDgoShoF552,
                         Ext_bMonRunShoF552,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN552_vidMonInvldP255Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF552P255)
   {
      if (ISCAN_u32N20F552P255 == 1048575)
      {
         Ext_bDgoInvldF552P255 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF552P255 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF552P255,
                   Ext_bDgoInvldF552P255,
                   Ext_bMonRunInvldF552P255,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonFrbdP255Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF552P255)
   {
      if (((86400 <= ISCAN_u32N20F552P255) && (ISCAN_u32N20F552P255 <= 1048574)))
      {
         Ext_bDgoFrbdF552P255 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF552P255 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF552P255,
                   Ext_bDgoFrbdF552P255,
                   Ext_bMonRunFrbdF552P255,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonInvldP256Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF552P256)
   {
      if (ISCAN_u16N12F552P256 == 4095)
      {
         Ext_bDgoInvldF552P256 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF552P256 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF552P256,
                   Ext_bDgoInvldF552P256,
                   Ext_bMonRunInvldF552P256,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonFrbdP256Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF552P256)
   {
      if (((365 <= ISCAN_u16N12F552P256) && (ISCAN_u16N12F552P256 <= 4094)))
      {
         Ext_bDgoFrbdF552P256 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF552P256 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF552P256,
                   Ext_bDgoFrbdF552P256,
                   Ext_bMonRunFrbdF552P256,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonInvldP257Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF552P257)
   {
      if (ISCAN_u8N8F552P257 == 255)
      {
         Ext_bDgoInvldF552P257 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF552P257 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF552P257,
                   Ext_bDgoInvldF552P257,
                   Ext_bMonRunInvldF552P257,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonFrbdP257Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF552P257)
   {
      if (((101 <= ISCAN_u8N8F552P257) && (ISCAN_u8N8F552P257 <= 254)))
      {
         Ext_bDgoFrbdF552P257 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF552P257 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF552P257,
                   Ext_bDgoFrbdF552P257,
                   Ext_bMonRunFrbdF552P257,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonInvldP325Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF552P325)
   {
      if (ISCAN_u32N32F552P325 == 4294967295)
      {
         Ext_bDgoInvldF552P325 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF552P325 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF552P325,
                   Ext_bDgoInvldF552P325,
                   Ext_bMonRunInvldF552P325,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonInvldP015Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF552P015)
   {
      if (ISCAN_u32N24F552P015 == 16777215)
      {
         Ext_bDgoInvldF552P015 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF552P015 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF552P015,
                   Ext_bDgoInvldF552P015,
                   Ext_bMonRunInvldF552P015,
                   DIAG_DISPO);
   }
}

void FHCAN552_vidMonInvldP326Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF552P326)
   {
      if (ISCAN_u8N8F552P326 == 255)
      {
         Ext_bDgoInvldF552P326 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF552P326 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF552P326,
                   Ext_bDgoInvldF552P326,
                   Ext_bMonRunInvldF552P326,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
