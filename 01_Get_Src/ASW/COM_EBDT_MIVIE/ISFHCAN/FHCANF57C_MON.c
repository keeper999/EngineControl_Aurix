/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF57C_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN57C_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_DMTR_57C;


   VEMS_vidGET(Ctrl_DMTR_57C, Local_bCtrl_DMTR_57C);
   if (ACTIVATED == Local_bCtrl_DMTR_57C)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF57C)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF57C = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF57C,
                         Ext_bDgoShoF57C,
                         Ext_bMonRunShoF57C,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF57C = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF57C,
                         Ext_bDgoShoF57C,
                         Ext_bMonRunShoF57C,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN57C_vidMonInvldPM1418Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF57CPM1418)
   {
      if (ISCAN_u8N3F57CPM1418 == 7)
      {
         Ext_bDgoInvldF57CPM1418 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF57CPM1418 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF57CPM1418,
                   Ext_bDgoInvldF57CPM1418,
                   Ext_bMonRunInvldF57CPM1418,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
