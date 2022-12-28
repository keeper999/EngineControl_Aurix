/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF532_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN532_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_DAT_BSI_532;


   VEMS_vidGET(Ctrl_DAT_BSI_532, Local_bCtrl_DAT_BSI_532);
   if (ACTIVATED == Local_bCtrl_DAT_BSI_532)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF532)
      {
         if (Dlc < 3)
         {
            Ext_bDgoShoF532 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF532,
                         Ext_bDgoShoF532,
                         Ext_bMonRunShoF532,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF532 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF532,
                         Ext_bDgoShoF532,
                         Ext_bMonRunShoF532,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN532_vidMonInvldPM1414Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF532PM1414)
   {
      if (ISCAN_u16N10F532PM1414 == 1023)
      {
         Ext_bDgoInvldF532PM1414 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF532PM1414 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF532PM1414,
                   Ext_bDgoInvldF532PM1414,
                   Ext_bMonRunInvldF532PM1414,
                   DIAG_DISPO);
   }
}

void FHCAN532_vidMonFrbdPM1414Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF532PM1414)
   {
      if (((1001 <= ISCAN_u16N10F532PM1414) && (ISCAN_u16N10F532PM1414 <= 1021)))
      {
         Ext_bDgoFrbdF532PM1414 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF532PM1414 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF532PM1414,
                   Ext_bDgoFrbdF532PM1414,
                   Ext_bMonRunFrbdF532PM1414,
                   DIAG_DISPO);
   }
}

void FHCAN532_vidMonInvldPM1415Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF532PM1415)
   {
      if (ISCAN_u8N6F532PM1415 == 63)
      {
         Ext_bDgoInvldF532PM1415 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF532PM1415 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF532PM1415,
                   Ext_bDgoInvldF532PM1415,
                   Ext_bMonRunInvldF532PM1415,
                   DIAG_DISPO);
   }
}

void FHCAN532_vidMonFrbdPM1415Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF532PM1415)
   {
      if ((ISCAN_u8N6F532PM1415 == 61))
      {
         Ext_bDgoFrbdF532PM1415 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF532PM1415 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF532PM1415,
                   Ext_bDgoFrbdF532PM1415,
                   Ext_bMonRunFrbdF532PM1415,
                   DIAG_DISPO);
   }
}

void FHCAN532_vidMonInvldPM1416Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF532PM1416)
   {
      if (ISCAN_u8N7F532PM1416 == 127)
      {
         Ext_bDgoInvldF532PM1416 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF532PM1416 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF532PM1416,
                   Ext_bDgoInvldF532PM1416,
                   Ext_bMonRunInvldF532PM1416,
                   DIAG_DISPO);
   }
}

void FHCAN532_vidMonFrbdPM1416Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF532PM1416)
   {
      if (((101 <= ISCAN_u8N7F532PM1416) && (ISCAN_u8N7F532PM1416 <= 125)))
      {
         Ext_bDgoFrbdF532PM1416 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF532PM1416 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF532PM1416,
                   Ext_bDgoFrbdF532PM1416,
                   Ext_bMonRunFrbdF532PM1416,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
