/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DC                                                      */
/* !Description     : DC Component                                            */
/*                                                                            */
/* !Module          : DC                                                      */
/* !Description     : DRIVING CYCLE                                           */
/*                                                                            */
/* !File            : DC_SCH.c                                                */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DC_vidMngEveRst                                                      */
/*   2 / DC_vidMngEveCrTR                                                     */
/*   3 / DC_vidMngEveCrTst                                                    */
/*   4 / DC_RstDftCal                                                         */
/*   5 / GD_EveRstDft_DC                                                      */
/*   6 / DC_RstDC                                                             */
/*   7 / GD_EveRstDftObd_DC                                                   */
/*   8 / GD_EveKOf_DC                                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 04662 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/DC/DC_SCH.c_v                $*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   01 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "DC.h"
#include "DC_L.h"
#include "DC_im.h"
#include "GD_api.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidMngEveRst                                            */
/* !Description :  Evenement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidInit();                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DC_vidMngEveRst                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidMngEveRst(void)
{
   DC_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidMngEveCrTR                                           */
/* !Description :  Evenement Crank to run                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidF02_GlbDCStrtEve();                                */
/*  input uint8 DC_u8Inhib;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DC_vidMngEveCrTR                                               */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidMngEveCrTR(void)
{
   if(DC_u8Inhib != 0x5A)
   {
      DC_vidF02_GlbDCStrtEve();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidMngEveCrTst                                          */
/* !Description :  Event CRANKING to STALL                                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidF01_NonAutorise();                                 */
/*  input uint8 DC_u8Inhib;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DC_vidMngEveCrTst                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidMngEveCrTst(void)
{
   if(DC_u8Inhib != 0x5A)
   {
      DC_vidF01_NonAutorise();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_RstDftCal                                               */
/* !Description :  Demande d'effacement Manuel des défauts                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidF03_DC_Reinit();                                   */
/*  input uint8 DC_u8Inhib;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DC_RstDftCal                                                   */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_RstDftCal(void)
{
   if(DC_u8Inhib != 0x5A)
   {
      DC_vidF03_DC_Reinit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft_DC                                            */
/* !Description :  Requête d'effacement des défauts avec l'outil APV          */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidF03_DC_Reinit();                                   */
/*  input uint8 DC_u8Inhib;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDft_DC                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft_DC(void)
{
   if(DC_u8Inhib != 0x5A)
   {
      DC_vidF03_DC_Reinit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_RstDC                                                   */
/* !Description :  Restart module DC by calling ReInit function               */
/* !Number      :  SCH.6                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidF03_DC_Reinit();                                   */
/*  input uint8 DC_u8Inhib;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DC_RstDC                                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_RstDC(void)
{
   if(DC_u8Inhib != 0x5A)
   {
      DC_vidF03_DC_Reinit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDftObd_DC                                         */
/* !Description :  Demande d'effacement des défauts OBD par le ScanTool       */
/* !Number      :  SCH.7                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DC_u8Inhib;                                                   */
/*  input uint8 GD_au8IdxClasObd[9];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDftObd_DC                                             */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDftObd_DC(void)
{
   uint8  u8LocalDivision;
   uint8  u8LocalRatio;
   uint8  u8LocalIdxClassObd;
   sint32 s32LocalIdx;


   if(DC_u8Inhib != 0x5A)
   {
      for(s32LocalIdx=0; s32LocalIdx<GD_DFT_NB; s32LocalIdx++)
      {
         u8LocalIdxClassObd = GD_au8IdxClasObd[s32LocalIdx];
         if(TRUE == GD_astrClasObd[u8LocalIdxClassObd].bEnaSctl)
         {
            u8LocalDivision = (uint8)(s32LocalIdx / 8);
            u8LocalRatio = (uint8)(s32LocalIdx % 8);
            /*QAC Warning: macro use if else*/
            GD_vidBitWrite(DC_au8DC_EEPROM[u8LocalDivision],u8LocalRatio,FALSE);
            /* QAC Warning : Les opérations sur le tableaux font qu'on dépasse
            le nombre d'opération autorisé : Ne pas prendre un compte */
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveKOf_DC                                               */
/* !Description :  Evènement passage de la clef de contact de ON à OFF        */
/* !Number      :  SCH.8                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DC_vidF03_F01_NotRelzd();                                */
/*  input uint8 DC_u8Inhib;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveKOf_DC                                                   */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveKOf_DC(void)
{
   if(DC_u8Inhib != 0x5A)
   {
      DC_vidF03_F01_NotRelzd();
   }
}

/*------------------------------- end of file --------------------------------*/