/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF432_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN432_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_432;


   VEMS_vidGET(Ctrl_BSI_432, Local_bCtrl_BSI_432);
   if (ACTIVATED == Local_bCtrl_BSI_432)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF432)
      {
         if (Dlc < 4)
         {
            Ext_bDgoShoF432 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF432,
                         Ext_bDgoShoF432,
                         Ext_bMonRunShoF432,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF432 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF432,
                         Ext_bDgoShoF432,
                         Ext_bMonRunShoF432,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN432_vidMonInvldP214Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF432P214)
   {
      if (ISCAN_u8N2F432P214 == 3)
      {
         Ext_bDgoInvldF432P214 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF432P214 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF432P214,
                   Ext_bDgoInvldF432P214,
                   Ext_bMonRunInvldF432P214,
                   DIAG_DISPO);
   }
}

void FHCAN432_vidMonFrbdP249Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF432P249)
   {
      if ((ISCAN_u8N2F432P249 == 0) || (ISCAN_u8N2F432P249 == 3))
      {
         Ext_bDgoFrbdF432P249 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF432P249 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF432P249,
                   Ext_bDgoFrbdF432P249,
                   Ext_bMonRunFrbdF432P249,
                   DIAG_DISPO);
   }
}

void FHCAN432_vidMonFrbdP251Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF432P251)
   {
      if ((ISCAN_u8N2F432P251 == 0) || (ISCAN_u8N2F432P251 == 3))
      {
         Ext_bDgoFrbdF432P251 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF432P251 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF432P251,
                   Ext_bDgoFrbdF432P251,
                   Ext_bMonRunFrbdF432P251,
                   DIAG_DISPO);
   }
}

void FHCAN432_vidMonFrbdP402Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF432P402)
   {
      if ((ISCAN_u8N2F432P402 == 0) || (ISCAN_u8N2F432P402 == 3))
      {
         Ext_bDgoFrbdF432P402 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF432P402 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF432P402,
                   Ext_bDgoFrbdF432P402,
                   Ext_bMonRunFrbdF432P402,
                   DIAG_DISPO);
   }
}

void FHCAN432_vidMonFrbdP368Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF432P368)
   {
      if ((ISCAN_u8N2F432P368 == 3))
      {
         Ext_bDgoFrbdF432P368 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF432P368 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF432P368,
                   Ext_bDgoFrbdF432P368,
                   Ext_bMonRunFrbdF432P368,
                   DIAG_DISPO);
   }
}

void FHCAN432_vidMonFrbdP369Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF432P369)
   {
      if (((8 <= ISCAN_u8N4F432P369) && (ISCAN_u8N4F432P369 <= 15)))
      {
         Ext_bDgoFrbdF432P369 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF432P369 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF432P369,
                   Ext_bDgoFrbdF432P369,
                   Ext_bMonRunFrbdF432P369,
                   DIAG_DISPO);
   }
}

void FHCAN432_vidMonFrbdPM1424Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF432PM1424)
   {
      if ((ISCAN_u8N2F432PM1424 == 0) || (ISCAN_u8N2F432PM1424 == 3))
      {
         Ext_bDgoFrbdF432PM1424 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF432PM1424 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF432PM1424,
                   Ext_bDgoFrbdF432PM1424,
                   Ext_bMonRunFrbdF432PM1424,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
