/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF592_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN592_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_592;


   VEMS_vidGET(Ctrl_BSI_592, Local_bCtrl_BSI_592);
   if (ACTIVATED == Local_bCtrl_BSI_592)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF592)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF592 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF592,
                         Ext_bDgoShoF592,
                         Ext_bMonRunShoF592,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF592 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF592,
                         Ext_bDgoShoF592,
                         Ext_bMonRunShoF592,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN592_vidMonInvldP272Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P272)
   {
      if (ISCAN_u8N8F592P272 == 255)
      {
         Ext_bDgoInvldF592P272 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P272 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P272,
                   Ext_bDgoInvldF592P272,
                   Ext_bMonRunInvldF592P272,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonFrbdP272Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF592P272)
   {
      if (((101 <= ISCAN_u8N8F592P272) && (ISCAN_u8N8F592P272 <= 253)))
      {
         Ext_bDgoFrbdF592P272 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF592P272 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF592P272,
                   Ext_bDgoFrbdF592P272,
                   Ext_bMonRunFrbdF592P272,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonInvldP273Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P273)
   {
      if (ISCAN_u8N8F592P273 == 255)
      {
         Ext_bDgoInvldF592P273 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P273 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P273,
                   Ext_bDgoInvldF592P273,
                   Ext_bMonRunInvldF592P273,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonFrbdP273Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF592P273)
   {
      if (((231 <= ISCAN_u8N8F592P273) && (ISCAN_u8N8F592P273 <= 253)))
      {
         Ext_bDgoFrbdF592P273 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF592P273 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF592P273,
                   Ext_bDgoFrbdF592P273,
                   Ext_bMonRunFrbdF592P273,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonInvldP349Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P349)
   {
      if (ISCAN_u8N3F592P349 == 7)
      {
         Ext_bDgoInvldF592P349 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P349 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P349,
                   Ext_bDgoInvldF592P349,
                   Ext_bMonRunInvldF592P349,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonFrbdP349Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF592P349)
   {
      if (((4 <= ISCAN_u8N3F592P349) && (ISCAN_u8N3F592P349 <= 5)))
      {
         Ext_bDgoFrbdF592P349 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF592P349 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF592P349,
                   Ext_bDgoFrbdF592P349,
                   Ext_bMonRunFrbdF592P349,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonInvldP418Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P418)
   {
      if (ISCAN_u16N11F592P418 == 2047)
      {
         Ext_bDgoInvldF592P418 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P418 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P418,
                   Ext_bDgoInvldF592P418,
                   Ext_bMonRunInvldF592P418,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonFrbdP418Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF592P418)
   {
      if (((1301 <= ISCAN_u16N11F592P418) && (ISCAN_u16N11F592P418 <= 2045)))
      {
         Ext_bDgoFrbdF592P418 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF592P418 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF592P418,
                   Ext_bDgoFrbdF592P418,
                   Ext_bMonRunFrbdF592P418,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonInvldP419Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P419)
   {
      if (ISCAN_u8N2F592P419 == 3)
      {
         Ext_bDgoInvldF592P419 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P419 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P419,
                   Ext_bDgoInvldF592P419,
                   Ext_bMonRunInvldF592P419,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonFrbdP419Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF592P419)
   {
      if ((ISCAN_u8N2F592P419 == 0))
      {
         Ext_bDgoFrbdF592P419 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF592P419 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF592P419,
                   Ext_bDgoFrbdF592P419,
                   Ext_bMonRunFrbdF592P419,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonInvldP420Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P420)
   {
      if (ISCAN_u8N2F592P420 == 3)
      {
         Ext_bDgoInvldF592P420 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P420 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P420,
                   Ext_bDgoInvldF592P420,
                   Ext_bMonRunInvldF592P420,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonInvldP421Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF592P421)
   {
      if (ISCAN_u16N16F592P421 == 65535)
      {
         Ext_bDgoInvldF592P421 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF592P421 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF592P421,
                   Ext_bDgoInvldF592P421,
                   Ext_bMonRunInvldF592P421,
                   DIAG_DISPO);
   }
}

void FHCAN592_vidMonFrbdP421Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF592P421)
   {
      if (((40001 <= ISCAN_u16N16F592P421) && (ISCAN_u16N16F592P421 <= 65533)))
      {
         Ext_bDgoFrbdF592P421 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF592P421 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF592P421,
                   Ext_bDgoFrbdF592P421,
                   Ext_bMonRunFrbdF592P421,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
