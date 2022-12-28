/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF3CD_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN3CD_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_FRE_3CD;


   VEMS_vidGET(Ctrl_FRE_3CD, Local_bCtrl_FRE_3CD);
   if (ACTIVATED == Local_bCtrl_FRE_3CD)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF3CD)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF3CD = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF3CD,
                         Ext_bDgoShoF3CD,
                         Ext_bMonRunShoF3CD,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF3CD = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF3CD,
                         Ext_bDgoShoF3CD,
                         Ext_bMonRunShoF3CD,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN3CD_vidMonInvldP225Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3CDP225)
   {
      if (ISCAN_bF3CDP225 == 1)
      {
         Ext_bDgoInvldF3CDP225 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3CDP225 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3CDP225,
                   Ext_bDgoInvldF3CDP225,
                   Ext_bMonRunInvldF3CDP225,
                   DIAG_DISPO);
   }
}

void FHCAN3CD_vidMonFrbdPM1387Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3CDPM1387)
   {
      if (((0 <= ISCAN_u8N3F3CDPM1387) && (ISCAN_u8N3F3CDPM1387 <= 2)) || (ISCAN_u8N3F3CDPM1387 == 4) || (ISCAN_u8N3F3CDPM1387 == 7))
      {
         Ext_bDgoFrbdF3CDPM1387 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3CDPM1387 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3CDPM1387,
                   Ext_bDgoFrbdF3CDPM1387,
                   Ext_bMonRunFrbdF3CDPM1387,
                   DIAG_DISPO);
   }
}

void FHCAN3CD_vidMonInvldP515Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3CDP515)
   {
      if (ISCAN_u16N12F3CDP515 == 4095)
      {
         Ext_bDgoInvldF3CDP515 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3CDP515 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3CDP515,
                   Ext_bDgoInvldF3CDP515,
                   Ext_bMonRunInvldF3CDP515,
                   DIAG_DISPO);
   }
}

void FHCAN3CD_vidMonInvldP319Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF3CDP319)
   {
      if (ISCAN_u8N8F3CDP319 == 255)
      {
         Ext_bDgoInvldF3CDP319 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF3CDP319 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF3CDP319,
                   Ext_bDgoInvldF3CDP319,
                   Ext_bMonRunInvldF3CDP319,
                   DIAG_DISPO);
   }
}

void FHCAN3CD_vidMonFrbdP319Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3CDP319)
   {
      if (((201 <= ISCAN_u8N8F3CDP319) && (ISCAN_u8N8F3CDP319 <= 253)))
      {
         Ext_bDgoFrbdF3CDP319 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3CDP319 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3CDP319,
                   Ext_bDgoFrbdF3CDP319,
                   Ext_bMonRunFrbdF3CDP319,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
