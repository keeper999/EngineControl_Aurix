/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF572_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN572_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_BSI_572;


   VEMS_vidGET(Ctrl_BSI_572, Local_bCtrl_BSI_572);
   if (ACTIVATED == Local_bCtrl_BSI_572)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF572)
      {
         if (Dlc < 2)
         {
            Ext_bDgoShoF572 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF572,
                         Ext_bDgoShoF572,
                         Ext_bMonRunShoF572,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF572 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF572,
                         Ext_bDgoShoF572,
                         Ext_bMonRunShoF572,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN572_vidMonInvldPM1360Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF572PM1360)
   {
      if (ISCAN_u16N11F572PM1360 == 2047)
      {
         Ext_bDgoInvldF572PM1360 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF572PM1360 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF572PM1360,
                   Ext_bDgoInvldF572PM1360,
                   Ext_bMonRunInvldF572PM1360,
                   DIAG_DISPO);
   }
}

void FHCAN572_vidMonFrbdPM1360Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF572PM1360)
   {
      if (((1301 <= ISCAN_u16N11F572PM1360) && (ISCAN_u16N11F572PM1360 <= 2045)))
      {
         Ext_bDgoFrbdF572PM1360 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF572PM1360 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF572PM1360,
                   Ext_bDgoFrbdF572PM1360,
                   Ext_bMonRunFrbdF572PM1360,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
