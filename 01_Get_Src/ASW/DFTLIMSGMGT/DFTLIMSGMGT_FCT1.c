/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DFTLIMSGMGT                                             */
/* !Description     : DFTLIMSGMGT Component                                   */
/*                                                                            */
/* !Module          : DFTLIMSGMGT                                             */
/* !Description     : ELABORATION DES MESSAGES CAN POUR ALLUMAGE DES VOYANTS  */
/*                    NON REGLEMENTAIRES                                      */
/*                                                                            */
/* !File            : DFTLIMSGMGT_FCT1.C                                      */
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
/*   1 / DFTLIMSGMGT_vidInit                                                  */
/*   2 / DFTLIMSGMGT_vidTimeTreatment                                         */
/*   3 / DFTLIMSGMGT_vidCMM_Dft                                               */
/*   4 / DFTLIMSGMGT_vidSfty_Dft                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 02272 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/DFTLIMSGMGT/DFTLIMSGMGT_FCT1.C_v  $*/
/* $Revision::   1.1      $$Author::   cbanchie       $$Date::   29 Apr 2011 $*/
/* $Author::   cbanchie                               $$Date::   29 Apr 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DFTLIMSGMGT.h"
#include "DFTLIMSGMGT_L.h"
#include "DFTLIMSGMGT_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTLIMSGMGT_vidInit                                        */
/* !Description :  Cette fonction donne les valeurs d'initialisation des      */
/*                 sorties.                                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.BOUKADIDA                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 ECU_stAcvWarn;                                               */
/*  output boolean ECU_bAcvSftyWarn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTLIMSGMGT_vidInit(void)
{
   VEMS_vidSET(ECU_stAcvWarn, 3);
   VEMS_vidSET(ECU_bAcvSftyWarn, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTLIMSGMGT_vidTimeTreatment                               */
/* !Description :  Les flux de sortie ne sont pas élaborés de la même manière */
/*                 selon qu’on soit en configuration « Mode d’alerte G3 – G4 »*/
/*                 ou bien « Mode d’alerte Safety ».                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.BOUKADIDA                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DFTLIMSGMGT_vidCMM_Dft();                                */
/*  extf argret void DFTLIMSGMGT_vidSfty_Dft();                               */
/*  input boolean Ext_bG3G4Cf;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTLIMSGMGT_vidTimeTreatment(void)
{
   boolean bLocalExt_bG3G4Cf;


   VEMS_vidGET(Ext_bG3G4Cf, bLocalExt_bG3G4Cf);
   if(bLocalExt_bG3G4Cf != 0)
   {
      DFTLIMSGMGT_vidCMM_Dft();
   }
   else
   {
      DFTLIMSGMGT_vidSfty_Dft();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTLIMSGMGT_vidCMM_Dft                                     */
/* !Description :  Cette fonction gère l’élaboration des messages CAN pour les*/
/*                 allumages des voyants non réglementaires en configuration «*/
/*                 Mode d’alerte G3-G4 »                                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.BOUKADIDA                                                */
/* !Trace_To    :  VEMS_R_11_02272_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st09 Rcd_power_state;                                               */
/*  input boolean ECU_bWkuMain;                                               */
/*  output uint8 ECU_stAcvWarn;                                               */
/*  output boolean ECU_bAcvSftyWarn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTLIMSGMGT_vidCMM_Dft(void)
{
   boolean  bLocalECU_bWkuMain;
   boolean  bLocalAcvStopWarn;
   boolean  bLocalAcvSrvWarn;
   uint8    u8LocalRcd_power_state;


   VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   bLocalAcvStopWarn = GDGAR_bGetFRM(FRM_FRM_ACVSTOPWARN);
   bLocalAcvSrvWarn = GDGAR_bGetFRM(FRM_FRM_ACVSRVWARN);
   if(u8LocalRcd_power_state == RCD_ANTICIPATION)
   {
      VEMS_vidSET(ECU_stAcvWarn, 3);
   }
   else
   {
      if(bLocalECU_bWkuMain != 0)
      {
         if(bLocalAcvStopWarn != 0)
         {
            VEMS_vidSET(ECU_stAcvWarn, 2);
         }
         else
         {
            if(bLocalAcvSrvWarn != 0)
            {
               VEMS_vidSET(ECU_stAcvWarn, 1);
            }
            else
            {
               VEMS_vidSET(ECU_stAcvWarn, 0);
            }
         }
      }
   }
   VEMS_vidSET(ECU_bAcvSftyWarn, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DFTLIMSGMGT_vidSfty_Dft                                    */
/* !Description :  Cett fonction gère l’élaboration des messages CAN pour les */
/*                 allumages des voyants non réglementaires en configuration «*/
/*                 Mode d’alerte Safety »                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.BOUKADIDA                                                */
/* !Trace_To    :  VEMS_R_11_02272_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 ECU_stAcvWarn;                                               */
/*  output boolean ECU_bAcvSftyWarn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DFTLIMSGMGT_vidSfty_Dft(void)
{
   boolean  bLocalAcvSftyWarn;


   bLocalAcvSftyWarn = GDGAR_bGetFRM(FRM_FRM_ACVSFTYWARN);

   VEMS_vidSET(ECU_stAcvWarn, 3);
   VEMS_vidSET(ECU_bAcvSftyWarn, bLocalAcvSftyWarn);
}
/*----------------------------------end of file-------------------------------*/