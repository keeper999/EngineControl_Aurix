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
/* !File            : OILPRESACQ_SCH.C                                        */
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
/*   1 / Oil_EveRst_OilPresAcq                                                */
/*   2 / Oil_SdlMid_OilPresAcq                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6563540 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/OILPRESACQ/OILPRESACQ_SCH.C_v     $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "OILPRESACQ.h"
#include "OILPRESACQ_l.h"
#include "OILPRESACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveRst_OilPresAcq                                      */
/* !Description :  Fonction d'accroche à l'événement reset du calculateur     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00761_001.01                                     */
/*                 VEMS_R_09_00761_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILPRESACQ_vidInitOutput();                              */
/*  extf argret void OILPRESACQ_vidInitialization();                          */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_EveRst_OilPresAcq                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveRst_OilPresAcq(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;


   VEMS_vidGET(Ctrl_bOilPropPresAcq , bLocalCtrl_bOilPropPresAcq );

   if (bLocalCtrl_bOilPropPresAcq == 0)
   {
      OILPRESACQ_vidInitOutput();
      OILPRESACQ_vidInitialization();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlMid_OilPresAcq                                      */
/* !Description :  Fonction d'accroche à l'événement Oil_SdlMid_OilPresAcq    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00761_001.01                                     */
/*                 VEMS_R_09_00761_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILPRESACQ_vidOilPresInfoAcq();                          */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input uint8 OILPRESACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlMid_OilPresAcq                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlMid_OilPresAcq(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;


   VEMS_vidGET(Ctrl_bOilPropPresAcq , bLocalCtrl_bOilPropPresAcq );

   if (OILPRESACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bOilPropPresAcq == 0)
      {
         OILPRESACQ_vidOilPresInfoAcq();
      }
   }
}
/*------------------------------- end of file --------------------------------*/