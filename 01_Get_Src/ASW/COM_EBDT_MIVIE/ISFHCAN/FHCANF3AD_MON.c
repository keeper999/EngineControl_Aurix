/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF3AD_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN3AD_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_EASY_MOVE_3AD;


   VEMS_vidGET(Ctrl_EASY_MOVE_3AD, Local_bCtrl_EASY_MOVE_3AD);
   if (ACTIVATED == Local_bCtrl_EASY_MOVE_3AD)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF3AD)
      {
         if (Dlc < 5)
         {
            Ext_bDgoShoF3AD = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF3AD,
                         Ext_bDgoShoF3AD,
                         Ext_bMonRunShoF3AD,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF3AD = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF3AD,
                         Ext_bDgoShoF3AD,
                         Ext_bMonRunShoF3AD,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN3AD_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_EASY_MOVE_3AD;


   VEMS_vidGET(Ctrl_EASY_MOVE_3AD, Local_bCtrl_EASY_MOVE_3AD);
   if (ACTIVATED == Local_bCtrl_EASY_MOVE_3AD)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF3AD)
       {
         if (!ISCAN_bSecuChkOKF3AD)
         {
            Ext_bDgoChkF3AD = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF3AD = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF3AD,
                      Ext_bDgoChkF3AD,
                      Ext_bMonRunChkF3AD,
                      DIAG_DISPO);
      }
   }
}

void FHCAN3AD_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_EASY_MOVE_3AD;


   VEMS_vidGET(Ctrl_EASY_MOVE_3AD, Local_bCtrl_EASY_MOVE_3AD);
   if (ACTIVATED == Local_bCtrl_EASY_MOVE_3AD)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF3AD)
      {
         Ext_bDgoCntF3AD = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF3AD,
                      Ext_bDgoCntF3AD,
                      Ext_bMonRunCntF3AD,
                      DIAG_DISPO);
      }
   }
}

void FHCAN3AD_vidMonFrbdP337Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF3ADP337)
   {
      if ((ISCAN_u8N3F3ADP337 == 6))
      {
         Ext_bDgoFrbdF3ADP337 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF3ADP337 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF3ADP337,
                   Ext_bDgoFrbdF3ADP337,
                   Ext_bMonRunFrbdF3ADP337,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
