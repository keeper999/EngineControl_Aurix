/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 14/10/2014 17:25:59 */
/* File: FHCANF349_MON.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "GDGAR.H"
#include "CTRLCFG.H"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"


void FHCAN349_vidMonShoUpdate(uint8 Dlc)
{
   boolean Local_bCtrl_V2_BVA_349;


   VEMS_vidGET(Ctrl_V2_BVA_349, Local_bCtrl_V2_BVA_349);
   if (ACTIVATED == Local_bCtrl_V2_BVA_349)
   {
      if (FHCAN_ENABLE == Ext_bMonRunShoF349)
      {
         if (Dlc < 8)
         {
            Ext_bDgoShoF349 = FHCAN_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF349,
                         Ext_bDgoShoF349,
                         Ext_bMonRunShoF349,
                         DIAG_DISPO);
         }
         else
         {
            Ext_bDgoShoF349 = FHCAN_NOT_DETECTED;
            GDGAR_vidGdu(GD_DFT_SHOF349,
                         Ext_bDgoShoF349,
                         Ext_bMonRunShoF349,
                         DIAG_DISPO);
         }
      }
   }
}


void FHCAN349_vidMonChkUpdate(void)
{
   boolean Local_bCtrl_V2_BVA_349;


   VEMS_vidGET(Ctrl_V2_BVA_349, Local_bCtrl_V2_BVA_349);
   if (ACTIVATED == Local_bCtrl_V2_BVA_349)
   {
      if (FHCAN_ENABLE == Ext_bMonRunChkF349)
       {
         if (!ISCAN_bSecuChkOKF349)
         {
            Ext_bDgoChkF349 = FHCAN_DETECTED;
         }
         else
         {
            Ext_bDgoChkF349 = FHCAN_NOT_DETECTED;
         }
         GDGAR_vidGdu(GD_DFT_CHKF349,
                      Ext_bDgoChkF349,
                      Ext_bMonRunChkF349,
                      DIAG_DISPO);
      }
   }
}

void FHCAN349_vidMonCntUpdate(void)
{
   boolean Local_bCtrl_V2_BVA_349;


   VEMS_vidGET(Ctrl_V2_BVA_349, Local_bCtrl_V2_BVA_349);
   if (ACTIVATED == Local_bCtrl_V2_BVA_349)
   {
      if (FHCAN_ENABLE == Ext_bMonRunCntF349)
      {
         Ext_bDgoCntF349 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_CNTF349,
                      Ext_bDgoCntF349,
                      Ext_bMonRunCntF349,
                      DIAG_DISPO);
      }
   }
}

void FHCAN349_vidMonFrbdP360Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349P360)
   {
      if (((6 <= ISCAN_u8N3F349P360) && (ISCAN_u8N3F349P360 <= 7)))
      {
         Ext_bDgoFrbdF349P360 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349P360 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349P360,
                   Ext_bDgoFrbdF349P360,
                   Ext_bMonRunFrbdF349P360,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonFrbdP057Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349P057)
   {
      if ((ISCAN_u8N8F349P057 == 255))
      {
         Ext_bDgoFrbdF349P057 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349P057 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349P057,
                   Ext_bDgoFrbdF349P057,
                   Ext_bMonRunFrbdF349P057,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonFrbdP008Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349P008)
   {
      if (((11 <= ISCAN_u8N4F349P008) && (ISCAN_u8N4F349P008 <= 14)))
      {
         Ext_bDgoFrbdF349P008 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349P008 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349P008,
                   Ext_bDgoFrbdF349P008,
                   Ext_bMonRunFrbdF349P008,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonInvldP007Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF349P007)
   {
      if (ISCAN_u8N4F349P007 == 15)
      {
         Ext_bDgoInvldF349P007 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF349P007 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF349P007,
                   Ext_bDgoInvldF349P007,
                   Ext_bMonRunInvldF349P007,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonFrbdP007Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349P007)
   {
      if (((4 <= ISCAN_u8N4F349P007) && (ISCAN_u8N4F349P007 <= 10)) || ((12 <= ISCAN_u8N4F349P007) && (ISCAN_u8N4F349P007 <= 14)))
      {
         Ext_bDgoFrbdF349P007 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349P007 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349P007,
                   Ext_bDgoFrbdF349P007,
                   Ext_bMonRunFrbdF349P007,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonInvldP055Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunInvldF349P055)
   {
      if (ISCAN_u8N8F349P055 == 255)
      {
         Ext_bDgoInvldF349P055 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoInvldF349P055 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_INVLDF349P055,
                   Ext_bDgoInvldF349P055,
                   Ext_bMonRunInvldF349P055,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonFrbdP287Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349P287)
   {
      if ((ISCAN_u8N4F349P287 == 0) || ((11 <= ISCAN_u8N4F349P287) && (ISCAN_u8N4F349P287 <= 14)))
      {
         Ext_bDgoFrbdF349P287 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349P287 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349P287,
                   Ext_bDgoFrbdF349P287,
                   Ext_bMonRunFrbdF349P287,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonFrbdPM1434Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349PM1434)
   {
      if ((ISCAN_u8N2F349PM1434 == 3))
      {
         Ext_bDgoFrbdF349PM1434 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349PM1434 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349PM1434,
                   Ext_bDgoFrbdF349PM1434,
                   Ext_bMonRunFrbdF349PM1434,
                   DIAG_DISPO);
   }
}

void FHCAN349_vidMonFrbdP166Update(void)
{
   if (FHCAN_ENABLE == Ext_bMonRunFrbdF349P166)
   {
      if ((ISCAN_u8N8F349P166 == 255))
      {
         Ext_bDgoFrbdF349P166 = FHCAN_DETECTED;
      }
      else
      {
         Ext_bDgoFrbdF349P166 = FHCAN_NOT_DETECTED;
      }
      GDGAR_vidGdu(GD_DFT_FRBDF349P166,
                   Ext_bDgoFrbdF349P166,
                   Ext_bMonRunFrbdF349P166,
                   DIAG_DISPO);
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
