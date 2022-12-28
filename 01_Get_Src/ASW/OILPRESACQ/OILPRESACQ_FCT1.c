/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILPRESACQ                                              */
/* !Description     : OILPRESACQ component.                                   */
/*                                                                            */
/* !Module          : OILPRESACQ                                              */
/* !Description     : ACQUISITION DE L’INFORMATION PRESSION HUILE MOTEUR.     */
/*                                                                            */
/* !File            : OILPRESACQ_FCT1.C                                       */
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
/*   1 / OILPRESACQ_vidInitOutput                                             */
/*   2 / OILPRESACQ_vidInitialization                                         */
/*   3 / OILPRESACQ_vidOilPresInfoAcq                                         */
/*   4 / OILPRESACQ_vidAcqFil                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6563540 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/OILPRESACQ/OILPRESACQ_FCT1.C_v    $*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "OILPRESACQ.h"
#include "OILPRESACQ_l.h"
#include "OILPRESACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPRESACQ_vidInitOutput                                   */
/* !Description :  fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 OILPRESACQ_u8AntiBounceCounter;                              */
/*  output boolean OILPRESACQ_bRawSig;                                        */
/*  output boolean Oil_pres_alert_fil;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPRESACQ_vidInitOutput(void)
{
    /*initialization of the block filtre_anti_rebond*/
   OILPRESACQ_u8AntiBounceCounter = 0;
   OILPRESACQ_bRawSig = 0;
   Oil_pres_alert_fil = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPRESACQ_vidInitialization                               */
/* !Description :  A l'initialisation l'information pression huile doit être à*/
/*                 OFF.                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00761_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Oil_pres_alertDetec;                                       */
/*  output boolean Ext_bOilPresDetec;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPRESACQ_vidInitialization(void)
{
   VEMS_vidSET(Oil_pres_alertDetec,0);
   VEMS_vidSET(Ext_bOilPresDetec,0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPRESACQ_vidOilPresInfoAcq                               */
/* !Description :  La lecture de l’information OIL_PRESSURE_ACQUISITION_SENSOR*/
/*                 provenant du LdB sera réalisée s’il n’y a pas  action  de  */
/*                 reconfiguration  en  cours  suite  à  la  levée  d’un      */
/*                 défaut  pression  huile  moteur (FRM_bAcvDftValOilPresAcq =*/
/*                 OFF).                                                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00761_004.01                                     */
/*                 VEMS_R_09_00761_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILPRESACQ_vidAcqFil();                                  */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Oil_pres_alert_fil;                                         */
/*  input boolean Oil_pres_alertTyp_C;                                        */
/*  output boolean Ext_bOilPresDetec;                                         */
/*  output boolean Oil_pres_alertDetec;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPRESACQ_vidOilPresInfoAcq(void)
{
   boolean bLocalACVDFTVALOILPRESACQ;


   OILPRESACQ_vidAcqFil();
   bLocalACVDFTVALOILPRESACQ = GDGAR_bGetFRM(FRM_FRM_ACVDFTVALOILPRESACQ);

   if (bLocalACVDFTVALOILPRESACQ != 0)
   {
      VEMS_vidSET(Ext_bOilPresDetec, 0);
   }
   else
   {
      if (Oil_pres_alert_fil != 0)
      {
         VEMS_vidSET(Ext_bOilPresDetec, 1);
      }
      else
      {
         VEMS_vidSET(Ext_bOilPresDetec, 0);
      }
   }

   if (Oil_pres_alertTyp_C != 0)
   {
      if (Oil_pres_alert_fil != 0)
      {
         VEMS_vidSET(Oil_pres_alertDetec, 1);
      }
      else
      {
         VEMS_vidSET(Oil_pres_alertDetec, 0);
      }
   }
   else
   {
      if (Oil_pres_alert_fil != 0)
      {
         VEMS_vidSET(Oil_pres_alertDetec, 0);
      }
      else
      {
         VEMS_vidSET(Oil_pres_alertDetec, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPRESACQ_vidAcqFil                                       */
/* !Description :  Le signal d'acquisition est filtré par un système          */
/*                 anti-rebond.                                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00761_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Acquisition_pression_huile_tor;                             */
/*  input boolean Hal_dio_inverse_signal_oil_pres;                            */
/*  input boolean OILPRESACQ_bRawSig;                                         */
/*  input boolean Oil_pres_alert_fil;                                         */
/*  input uint8 Ext_noOilPresHiThd_C;                                         */
/*  input uint8 Ext_noOilPresLoThd_C;                                         */
/*  input uint8 OILPRESACQ_u8AntiBounceCounter;                               */
/*  output boolean Ext_bRawOilPresDetec;                                      */
/*  output boolean OILPRESACQ_bRawSig;                                        */
/*  output uint8 OILPRESACQ_u8AntiBounceCounter;                              */
/*  output boolean Oil_pres_alert_fil;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPRESACQ_vidAcqFil(void)
{
   boolean bLocalAcquiPressionHuileTor;
   boolean bLocalInv;
   uint8   u8LocalThd;
   uint16  u16LocalCnt;

   VEMS_vidGET(Acquisition_pression_huile_tor, bLocalAcquiPressionHuileTor);
   if (Hal_dio_inverse_signal_oil_pres != 0)
   {
      bLocalInv = !bLocalAcquiPressionHuileTor;
      VEMS_vidSET(Ext_bRawOilPresDetec, bLocalInv);
      OILPRESACQ_bRawSig = !bLocalAcquiPressionHuileTor;
   }
   else
   {
      VEMS_vidSET(Ext_bRawOilPresDetec, bLocalAcquiPressionHuileTor);
      OILPRESACQ_bRawSig = bLocalAcquiPressionHuileTor;
   }

   if (OILPRESACQ_bRawSig != Oil_pres_alert_fil)
   {
      if (OILPRESACQ_bRawSig!= 0)
      {
         u8LocalThd = Ext_noOilPresHiThd_C;
      }
      else
      {
         u8LocalThd = Ext_noOilPresLoThd_C;
      }

      u16LocalCnt = (uint16)(OILPRESACQ_u8AntiBounceCounter + 1);
      OILPRESACQ_u8AntiBounceCounter = (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);

      if (OILPRESACQ_u8AntiBounceCounter > u8LocalThd)
      {
         OILPRESACQ_u8AntiBounceCounter = 0;
         Oil_pres_alert_fil = OILPRESACQ_bRawSig;
      }
   }
   else
   {
      OILPRESACQ_u8AntiBounceCounter = 0;
   }
}
/*------------------------------- end of file --------------------------------*/