/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQWKUSIG                                               */
/* !Description     : ACQWKUSIG component                                     */
/*                                                                            */
/* !Module          : ACQWKUSIG                                               */
/* !Description     : Acquisition de la commande de reveil (rcd)              */
/*                                                                            */
/* !File            : ACQWKUSIG_FCT1.C                                        */
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
/*   1 / ACQWKUSIG_vidKeyOnOffInit                                            */
/*   2 / ACQWKUSIG_vidInitOutPut                                              */
/*   3 / ACQWKUSIG_vidKeyTreatement                                           */
/*   4 / ACQWKUSIG_vidRcdModeActive                                           */
/*   5 / ACQWKUSIG_vidRcdModeNoAct                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6884549 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECUST/ACQWKUSIG/ACQWKUSIG_FCT1.c_v$*/
/* $Revision::   1.8      $$Author::   wbouach        $$Date::   23 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   23 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "ACQWKUSIG.h"
#include "ACQWKUSIG_L.h"
#include "ACQWKUSIG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQWKUSIG_vidKeyOnOffInit                                  */
/* !Description :  Au reset du calculateur, le signal RCD est supposé actif   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Rcd_mode_active;                                            */
/*  output boolean Rcd_signal;                                                */
/*  output boolean Rcd_mode_active;                                           */
/*  output boolean Ext_bRCDLine;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQWKUSIG_vidKeyOnOffInit(void)
{
   VEMS_vidSET(Rcd_signal, Rcd_mode_active);
   VEMS_vidSET(Ext_bRCDLine, Rcd_mode_active);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQWKUSIG_vidInitOutPut                                    */
/* !Description :  fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Clef_signal_filt;                                          */
/*  output boolean Ext_bAPCLine;                                              */
/*  output uint8 ACQWKUSIG_u8AntiBounceCounter;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQWKUSIG_vidInitOutPut(void)
{
   VEMS_vidSET(Clef_signal_filt, 0);
   VEMS_vidSET(Ext_bAPCLine, 0);
   ACQWKUSIG_u8AntiBounceCounter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQWKUSIG_vidKeyTreatement                                 */
/* !Description :  Fonction qui permet le traitement clef.                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_11_05622_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACQWKUSIG_vidRcdModeActive();                            */
/*  extf argret void ACQWKUSIG_vidRcdModeNoAct();                             */
/*  input boolean Acquisition_cmde_reveil_rcd_tor;                            */
/*  input boolean Clef_signal_filt;                                           */
/*  input boolean Clef_signal_raw;                                            */
/*  input uint8 AcqWkuSig_RcdLoThd_C;                                         */
/*  input uint8 AcqWkuSig_RcdHiThd_C;                                         */
/*  input uint8 ACQWKUSIG_u8AntiBounceCounter;                                */
/*  input boolean Rcd_mode_active;                                            */
/*  output boolean Clef_signal_raw;                                           */
/*  output uint8 ACQWKUSIG_u8AntiBounceCounter;                               */
/*  output boolean Clef_signal_filt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQWKUSIG_vidKeyTreatement(void)
{
   boolean bLocalClef_signal_filt;
   boolean bLocalAcquisition_cmde_tor;
   uint8   u8LocalTranThd;
   uint16  u16LocalCnt;


   VEMS_vidGET(Acquisition_cmde_reveil_rcd_tor, bLocalAcquisition_cmde_tor);
   Clef_signal_raw = bLocalAcquisition_cmde_tor;
   VEMS_vidGET(Clef_signal_filt, bLocalClef_signal_filt);
   if (Clef_signal_raw != bLocalClef_signal_filt)
   {
      if (Clef_signal_raw == 0)
      {
         u8LocalTranThd = AcqWkuSig_RcdLoThd_C;
      }
      else
      {
         u8LocalTranThd = AcqWkuSig_RcdHiThd_C;
      }
      u16LocalCnt = (uint16)(ACQWKUSIG_u8AntiBounceCounter + 1);
      ACQWKUSIG_u8AntiBounceCounter =
         (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);
      if (ACQWKUSIG_u8AntiBounceCounter > u8LocalTranThd)
      {
         bLocalClef_signal_filt = Clef_signal_raw;
         ACQWKUSIG_u8AntiBounceCounter = 0;
      }
   }
   else
   {
      ACQWKUSIG_u8AntiBounceCounter = 0;
   }
   VEMS_vidSET(Clef_signal_filt, bLocalClef_signal_filt);

   if (Rcd_mode_active != 0)
   {
      ACQWKUSIG_vidRcdModeActive();
   }
   else
   {
      ACQWKUSIG_vidRcdModeNoAct();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQWKUSIG_vidRcdModeActive                                 */
/* !Description :  Le filtrage du signal APC_CD est déjà effectué dans le LDB,*/
/*                 donc pour éviter la redondance, le signal_RCD prend        */
/*                 directement les valeurs de Clef_signal_filt                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_signal_filt;                                           */
/*  output boolean Rcd_signal;                                                */
/*  output boolean Ext_bRCDLine;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQWKUSIG_vidRcdModeActive(void)
{
   boolean bLocalClef_signal_filt;


   VEMS_vidGET(Clef_signal_filt, bLocalClef_signal_filt);
   VEMS_vidSET(Rcd_signal, bLocalClef_signal_filt);
   VEMS_vidSET(Ext_bRCDLine, bLocalClef_signal_filt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQWKUSIG_vidRcdModeNoAct                                  */
/* !Description :  Si la variable Rcd_mode_active est à ON, Ext_bAPCLine doit */
/*                 rester à OFF. Sinon elle prend la valeur de                */
/*                 Clef_signal_filt                                           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_signal_filt;                                           */
/*  output boolean Ext_bAPCLine;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQWKUSIG_vidRcdModeNoAct(void)
{
   boolean bLocalClef_signal_filt;


   VEMS_vidGET(Clef_signal_filt, bLocalClef_signal_filt);
   VEMS_vidSET(Ext_bAPCLine, bLocalClef_signal_filt);
}

/******************************** end of file *********************************/