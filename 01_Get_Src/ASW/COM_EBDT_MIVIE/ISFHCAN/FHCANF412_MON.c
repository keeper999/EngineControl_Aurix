/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF412_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN412_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_412;


   VEMS_vidGET(Ctrl_BSI_412, Local_bCtrl_BSI_412);
   if (ACTIVATED == Local_bCtrl_BSI_412)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF412)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF412 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF412,
                         Ext_bDgoShoF412,
                         Ext_bMonRunShoF412,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF412 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF412,
                         Ext_bDgoShoF412,
                         Ext_bMonRunShoF412,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN412_vidMonInvldP040Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF412P040)
   {
      if (ISCAN_bF412P040 == 1)
      {
         Ext_bDgoInvldF412P040 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF412P040 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF412P040,
                   Ext_bDgoInvldF412P040,
                   Ext_bMonRunInvldF412P040,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
