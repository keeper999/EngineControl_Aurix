/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF50E_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN50E_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_CLIM_50E;


   VEMS_vidGET(Ctrl_CLIM_50E, Local_bCtrl_CLIM_50E);
   if (ACTIVATED == Local_bCtrl_CLIM_50E)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF50E)
      {
         if (Dlc < 3)
         {
            Ext_bDgoShoF50E = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF50E,
                         Ext_bDgoShoF50E,
                         Ext_bMonRunShoF50E,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF50E = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF50E,
                         Ext_bDgoShoF50E,
                         Ext_bMonRunShoF50E,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN50E_vidMonInvldPM1386Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF50EPM1386)
   {
      if (ISCAN_bF50EPM1386 == 1)
      {
         Ext_bDgoInvldF50EPM1386 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF50EPM1386 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF50EPM1386,
                   Ext_bDgoInvldF50EPM1386,
                   Ext_bMonRunInvldF50EPM1386,
                   DIAG_DISPO);
   }
}

void FHCAN50E_vidMonInvldP046Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF50EP046)
   {
      if (ISCAN_u8N6F50EP046 == 63)
      {
         Ext_bDgoInvldF50EP046 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF50EP046 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF50EP046,
                   Ext_bDgoInvldF50EP046,
                   Ext_bMonRunInvldF50EP046,
                   DIAG_DISPO);
   }
}

void FHCAN50E_vidMonFrbdP046Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF50EP046)
   {
      if (((56 <= ISCAN_u8N6F50EP046) && (ISCAN_u8N6F50EP046 <= 62)))
      {
         Ext_bDgoFrbdF50EP046 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF50EP046 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF50EP046,
                   Ext_bDgoFrbdF50EP046,
                   Ext_bMonRunFrbdF50EP046,
                   DIAG_DISPO);
   }
}

void FHCAN50E_vidMonFrbdP417Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF50EP417)
   {
      if ((ISCAN_u8N2F50EP417 == 0) || (ISCAN_u8N2F50EP417 == 3))
      {
         Ext_bDgoFrbdF50EP417 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF50EP417 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF50EP417,
                   Ext_bDgoFrbdF50EP417,
                   Ext_bMonRunFrbdF50EP417,
                   DIAG_DISPO);
   }
}

void FHCAN50E_vidMonInvldP210Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF50EP210)
   {
      if (ISCAN_u8N8F50EP210 == 255)
      {
         Ext_bDgoInvldF50EP210 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF50EP210 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF50EP210,
                   Ext_bDgoInvldF50EP210,
                   Ext_bMonRunInvldF50EP210,
                   DIAG_DISPO);
   }
}

void FHCAN50E_vidMonFrbdP208Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF50EP208)
   {
      if ((ISCAN_u8N8F50EP208 == 255))
      {
         Ext_bDgoFrbdF50EP208 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF50EP208 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF50EP208,
                   Ext_bDgoFrbdF50EP208,
                   Ext_bMonRunFrbdF50EP208,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
