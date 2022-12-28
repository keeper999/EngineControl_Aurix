/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF4D2_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN4D2_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_WMI_BSI_4D2;


   VEMS_vidGET(Ctrl_WMI_BSI_4D2, Local_bCtrl_WMI_BSI_4D2);
   if (ACTIVATED == Local_bCtrl_WMI_BSI_4D2)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF4D2)
      {
         if (Dlc < 3)
         {
            Ext_bDgoShoF4D2 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF4D2,
                         Ext_bDgoShoF4D2,
                         Ext_bMonRunShoF4D2,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF4D2 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF4D2,
                         Ext_bDgoShoF4D2,
                         Ext_bMonRunShoF4D2,
                         DIAG_DISPO);
         }
      }
   }
}


#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
