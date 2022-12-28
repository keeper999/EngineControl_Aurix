/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF792_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN792_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_792;


   VEMS_vidGET(Ctrl_BSI_792, Local_bCtrl_BSI_792);
   if (ACTIVATED == Local_bCtrl_BSI_792)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF792)
      {
         if (Dlc < 3)
         {
            Ext_bDgoShoF792 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF792,
                         Ext_bDgoShoF792,
                         Ext_bMonRunShoF792,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF792 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF792,
                         Ext_bDgoShoF792,
                         Ext_bMonRunShoF792,
                         DIAG_DISPO);
         }
      }
   }
}


#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
