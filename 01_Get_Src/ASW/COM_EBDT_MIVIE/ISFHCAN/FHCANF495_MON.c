/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF495_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN495_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_DIRA_495;


   VEMS_vidGET(Ctrl_DIRA_495, Local_bCtrl_DIRA_495);
   if (ACTIVATED == Local_bCtrl_DIRA_495)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF495)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF495 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF495,
                         Ext_bDgoShoF495,
                         Ext_bMonRunShoF495,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF495 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF495,
                         Ext_bDgoShoF495,
                         Ext_bMonRunShoF495,
                         DIAG_DISPO);
         }
      }
   }
}


#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
