/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF4F2_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN4F2_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_4F2;


   VEMS_vidGET(Ctrl_BSI_4F2, Local_bCtrl_BSI_4F2);
   if (ACTIVATED == Local_bCtrl_BSI_4F2)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF4F2)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF4F2 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF4F2,
                         Ext_bDgoShoF4F2,
                         Ext_bMonRunShoF4F2,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF4F2 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF4F2,
                         Ext_bDgoShoF4F2,
                         Ext_bMonRunShoF4F2,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN4F2_vidMonInvldP434Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P434)
   {
      if (ISCAN_u16N10F4F2P434 == 1023)
      {
         Ext_bDgoInvldF4F2P434 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P434 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P434,
                   Ext_bDgoInvldF4F2P434,
                   Ext_bMonRunInvldF4F2P434,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP434Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P434)
   {
      if (((1001 <= ISCAN_u16N10F4F2P434) && (ISCAN_u16N10F4F2P434 <= 1021)))
      {
         Ext_bDgoFrbdF4F2P434 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P434 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P434,
                   Ext_bDgoFrbdF4F2P434,
                   Ext_bMonRunFrbdF4F2P434,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonInvldP438Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P438)
   {
      if (ISCAN_u16N10F4F2P438 == 1023)
      {
         Ext_bDgoInvldF4F2P438 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P438 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P438,
                   Ext_bDgoInvldF4F2P438,
                   Ext_bMonRunInvldF4F2P438,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP438Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P438)
   {
      if (((1001 <= ISCAN_u16N10F4F2P438) && (ISCAN_u16N10F4F2P438 <= 1021)))
      {
         Ext_bDgoFrbdF4F2P438 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P438 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P438,
                   Ext_bDgoFrbdF4F2P438,
                   Ext_bMonRunFrbdF4F2P438,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonInvldP429Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P429)
   {
      if (ISCAN_u8N2F4F2P429 == 2)
      {
         Ext_bDgoInvldF4F2P429 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P429 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P429,
                   Ext_bDgoInvldF4F2P429,
                   Ext_bMonRunInvldF4F2P429,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonInvldP437Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P437)
   {
      if (ISCAN_u16N9F4F2P437 == 511)
      {
         Ext_bDgoInvldF4F2P437 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P437 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P437,
                   Ext_bDgoInvldF4F2P437,
                   Ext_bMonRunInvldF4F2P437,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP437Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P437)
   {
      if (((301 <= ISCAN_u16N9F4F2P437) && (ISCAN_u16N9F4F2P437 <= 509)))
      {
         Ext_bDgoFrbdF4F2P437 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P437 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P437,
                   Ext_bDgoFrbdF4F2P437,
                   Ext_bMonRunFrbdF4F2P437,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonInvldP490Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P490)
   {
      if (ISCAN_u8N6F4F2P490 == 63)
      {
         Ext_bDgoInvldF4F2P490 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P490 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P490,
                   Ext_bDgoInvldF4F2P490,
                   Ext_bMonRunInvldF4F2P490,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP490Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P490)
   {
      if (((55 <= ISCAN_u8N6F4F2P490) && (ISCAN_u8N6F4F2P490 <= 62)))
      {
         Ext_bDgoFrbdF4F2P490 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P490 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P490,
                   Ext_bDgoFrbdF4F2P490,
                   Ext_bMonRunFrbdF4F2P490,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP493Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P493)
   {
      if ((ISCAN_u8N2F4F2P493 == 3))
      {
         Ext_bDgoFrbdF4F2P493 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P493 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P493,
                   Ext_bDgoFrbdF4F2P493,
                   Ext_bMonRunFrbdF4F2P493,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonInvldP491Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P491)
   {
      if (ISCAN_u8N6F4F2P491 == 63)
      {
         Ext_bDgoInvldF4F2P491 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P491 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P491,
                   Ext_bDgoInvldF4F2P491,
                   Ext_bMonRunInvldF4F2P491,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP491Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P491)
   {
      if (((55 <= ISCAN_u8N6F4F2P491) && (ISCAN_u8N6F4F2P491 <= 62)))
      {
         Ext_bDgoFrbdF4F2P491 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P491 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P491,
                   Ext_bDgoFrbdF4F2P491,
                   Ext_bMonRunFrbdF4F2P491,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP494Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P494)
   {
      if ((ISCAN_u8N2F4F2P494 == 3))
      {
         Ext_bDgoFrbdF4F2P494 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P494 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P494,
                   Ext_bDgoFrbdF4F2P494,
                   Ext_bMonRunFrbdF4F2P494,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonInvldP492Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF4F2P492)
   {
      if (ISCAN_u8N7F4F2P492 == 127)
      {
         Ext_bDgoInvldF4F2P492 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF4F2P492 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF4F2P492,
                   Ext_bDgoInvldF4F2P492,
                   Ext_bMonRunInvldF4F2P492,
                   DIAG_DISPO);
   }
}

void FHCAN4F2_vidMonFrbdP492Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF4F2P492)
   {
      if ((ISCAN_u8N7F4F2P492 == 0) || ((101 <= ISCAN_u8N7F4F2P492) && (ISCAN_u8N7F4F2P492 <= 126)))
      {
         Ext_bDgoFrbdF4F2P492 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF4F2P492 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF4F2P492,
                   Ext_bDgoFrbdF4F2P492,
                   Ext_bMonRunFrbdF4F2P492,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
