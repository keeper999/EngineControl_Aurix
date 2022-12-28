/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF30D_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN30D_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_FRE_30D;


   VEMS_vidGET(Ctrl_FRE_30D, Local_bCtrl_FRE_30D);
   if (ACTIVATED == Local_bCtrl_FRE_30D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF30D)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF30D = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF30D,
                         Ext_bDgoShoF30D,
                         Ext_bMonRunShoF30D,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF30D = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF30D,
                         Ext_bDgoShoF30D,
                         Ext_bMonRunShoF30D,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN30D_vidMonInvldP263Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF30DP263)
   {
      if (ISCAN_u16N16F30DP263 == 65535)
      {
         Ext_bDgoInvldF30DP263 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF30DP263 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF30DP263,
                   Ext_bDgoInvldF30DP263,
                   Ext_bMonRunInvldF30DP263,
                   DIAG_DISPO);
   }
}

void FHCAN30D_vidMonInvldP264Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF30DP264)
   {
      if (ISCAN_u16N16F30DP264 == 65535)
      {
         Ext_bDgoInvldF30DP264 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF30DP264 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF30DP264,
                   Ext_bDgoInvldF30DP264,
                   Ext_bMonRunInvldF30DP264,
                   DIAG_DISPO);
   }
}

void FHCAN30D_vidMonInvldP265Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF30DP265)
   {
      if (ISCAN_u16N16F30DP265 == 65535)
      {
         Ext_bDgoInvldF30DP265 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF30DP265 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF30DP265,
                   Ext_bDgoInvldF30DP265,
                   Ext_bMonRunInvldF30DP265,
                   DIAG_DISPO);
   }
}

void FHCAN30D_vidMonInvldP266Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF30DP266)
   {
      if (ISCAN_u16N16F30DP266 == 65535)
      {
         Ext_bDgoInvldF30DP266 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF30DP266 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF30DP266,
                   Ext_bDgoInvldF30DP266,
                   Ext_bMonRunInvldF30DP266,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
