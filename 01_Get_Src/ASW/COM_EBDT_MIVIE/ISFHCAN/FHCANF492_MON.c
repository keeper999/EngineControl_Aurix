/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF492_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN492_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_VDS_BSI_492;


   VEMS_vidGET(Ctrl_VDS_BSI_492, Local_bCtrl_VDS_BSI_492);
   if (ACTIVATED == Local_bCtrl_VDS_BSI_492)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF492)
      {
         if (Dlc < 6)
         {
            Ext_bDgoShoF492 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF492,
                         Ext_bDgoShoF492,
                         Ext_bMonRunShoF492,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF492 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF492,
                         Ext_bDgoShoF492,
                         Ext_bMonRunShoF492,
                         DIAG_DISPO);
         }
      }
   }
}


#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
