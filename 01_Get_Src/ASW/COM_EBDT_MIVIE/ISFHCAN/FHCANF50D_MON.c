/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF50D_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN50D_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_ABR_50D;


   VEMS_vidGET(Ctrl_ABR_50D, Local_bCtrl_ABR_50D);
   if (ACTIVATED == Local_bCtrl_ABR_50D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF50D)
      {
         if (Dlc < 1)
         {
            Ext_bDgoShoF50D = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF50D,
                         Ext_bDgoShoF50D,
                         Ext_bMonRunShoF50D,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF50D = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF50D,
                         Ext_bDgoShoF50D,
                         Ext_bMonRunShoF50D,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN50D_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_ABR_50D;


   VEMS_vidGET(Ctrl_ABR_50D, Local_bCtrl_ABR_50D);
   if (ACTIVATED == Local_bCtrl_ABR_50D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF50D)
       {
         if (!ISCAN_bSecuChkOKF50D)
         {
            Ext_bDgoChkF50D = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF50D = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF50D,
                      Ext_bDgoChkF50D,
                      Ext_bMonRunChkF50D,
                      DIAG_DISPO);
      }
   }
}

void FHCAN50D_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_ABR_50D;


   VEMS_vidGET(Ctrl_ABR_50D, Local_bCtrl_ABR_50D);
   if (ACTIVATED == Local_bCtrl_ABR_50D)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF50D)
      {
         Ext_bDgoCntF50D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF50D,
                      Ext_bDgoCntF50D,
                      Ext_bMonRunCntF50D,
                      DIAG_DISPO);
      }
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
