/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF44D_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN44D_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_ABR_44D;


   VEMS_vidGET(Ctrl_ABR_44D, Local_bCtrl_ABR_44D);
   if (ACTIVATED == Local_bCtrl_ABR_44D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF44D)
      {
         if (Dlc < 6)
         {
            Ext_bDgoShoF44D = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF44D,
                         Ext_bDgoShoF44D,
                         Ext_bMonRunShoF44D,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF44D = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF44D,
                         Ext_bDgoShoF44D,
                         Ext_bMonRunShoF44D,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN44D_vidMonInvldFP0535Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF44DFP0535)
   {
      if (ISCAN_u16N16F44DFP0535 == 65535)
      {
         Ext_bDgoInvldF44DFP0535 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF44DFP0535 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF44DFP0535,
                   Ext_bDgoInvldF44DFP0535,
                   Ext_bMonRunInvldF44DFP0535,
                   DIAG_DISPO);
   }
}

void FHCAN44D_vidMonInvldP330Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF44DP330)
   {
      if (ISCAN_u16N16F44DP330 == 65535)
      {
         Ext_bDgoInvldF44DP330 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF44DP330 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF44DP330,
                   Ext_bDgoInvldF44DP330,
                   Ext_bMonRunInvldF44DP330,
                   DIAG_DISPO);
   }
}

void FHCAN44D_vidMonInvldP331Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF44DP331)
   {
      if (ISCAN_u16N16F44DP331 == 65535)
      {
         Ext_bDgoInvldF44DP331 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF44DP331 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF44DP331,
                   Ext_bDgoInvldF44DP331,
                   Ext_bMonRunInvldF44DP331,
                   DIAG_DISPO);
   }
}

void FHCAN44D_vidMonInvldP354Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF44DP354)
   {
      if (ISCAN_u16N16F44DP354 == 65535)
      {
         Ext_bDgoInvldF44DP354 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF44DP354 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF44DP354,
                   Ext_bDgoInvldF44DP354,
                   Ext_bMonRunInvldF44DP354,
                   DIAG_DISPO);
   }
}

void FHCAN44D_vidMonFrbdP354Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF44DP354)
   {
      if (((65526 <= ISCAN_u16N16F44DP354) && (ISCAN_u16N16F44DP354 <= 65534)))
      {
         Ext_bDgoFrbdF44DP354 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF44DP354 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF44DP354,
                   Ext_bDgoFrbdF44DP354,
                   Ext_bMonRunFrbdF44DP354,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
