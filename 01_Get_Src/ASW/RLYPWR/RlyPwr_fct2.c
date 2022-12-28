/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RLYPWR                                                  */
/* !Description     : RLYPWR Component                                        */
/*                                                                            */
/* !Module          : RLYPWR                                                  */
/* !Description     : Gestionnaire du relais actionneurs                      */
/*                                                                            */
/* !File            : RLYPWR_FCT2.C                                           */
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
/*   1 / RLYPWR_vidInitWaitAcvModEcoBatt                                      */
/*   2 / RLYPWR_vidWaitAcvModEcoBatt                                          */
/*   3 / RLYPWR_vidInitWaitPwrlEnd                                            */
/*   4 / RLYPWR_vidWaitPwrlEnd                                                */
/*   5 / RLYPWR_vidInitTempo                                                  */
/*   6 / RLYPWR_vidWaitAcvModEcoBattCalib                                     */
/*   7 / RLYPWR_vidRlyMngHldReq                                               */
/*   8 / RLYPWR_vidFinMaintRelPrinp                                           */
/*   9 / RLYPWR_vidPrevEcuStPwrlLong                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5137464 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/RLYPWR/RLYPWR_FCT2.C_v      $*/
/* $Revision::   1.11                                                        $*/
/* $Author::   etsasson                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEMS.h"
#include "RLYPWR.h"
#include "RLYPWR_L.h"
#include "RLYPWR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidInitWaitAcvModEcoBatt                            */
/* !Description :  Attente du mode d'activation                               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 RlyPwr_tiWaitAcvModEcoBatt_C;                                */
/*  input boolean RlyPwr_bAcvModEcoBatt;                                      */
/*  output uint16 RlyPwr_tiWaitAcvModEcoBatt;                                 */
/*  output boolean RlyPwr_bAcvModEcoBatt;                                     */
/*  output boolean Ext_bUnBlsReq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidInitWaitAcvModEcoBatt(void)
{
   RlyPwr_tiWaitAcvModEcoBatt =
      (uint16)MATHSRV_udtMIN(RlyPwr_tiWaitAcvModEcoBatt_C, 38250);
   RlyPwr_bAcvModEcoBatt = 0;
   VEMS_vidSET(Ext_bUnBlsReq, RlyPwr_bAcvModEcoBatt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidWaitAcvModEcoBatt                                */
/* !Description :  Attente du mode d'activation                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 RlyPwr_tiWaitAcvModEcoBatt;                                  */
/*  input boolean RlyPwr_bAcvModEcoBatt;                                      */
/*  output uint16 RlyPwr_tiWaitAcvModEcoBatt;                                 */
/*  output boolean RlyPwr_bAcvModEcoBatt;                                     */
/*  output boolean Ext_bUnBlsReq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidWaitAcvModEcoBatt(void)
{
   uint16 u16LocaltiWaitAcvModEcoBatt;


   if (RlyPwr_tiWaitAcvModEcoBatt != 0)
   {
      u16LocaltiWaitAcvModEcoBatt = (uint16)(RlyPwr_tiWaitAcvModEcoBatt - 1);
      RlyPwr_tiWaitAcvModEcoBatt =
         (uint16)MATHSRV_udtMIN(u16LocaltiWaitAcvModEcoBatt, 38250);
   }
   if (RlyPwr_tiWaitAcvModEcoBatt == 0)
   {
      RlyPwr_bAcvModEcoBatt = 1;
      VEMS_vidSET(Ext_bUnBlsReq, RlyPwr_bAcvModEcoBatt);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidInitWaitPwrlEnd                                  */
/* !Description :  Condition sur la durée du Power-Latch                      */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 RlyPwr_tiEcuStPwrlLong_C;                                    */
/*  output uint16 RlyPwr_tiEcuStPwrlLong;                                     */
/*  output boolean EcuSt_bPwrlLong;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidInitWaitPwrlEnd(void)
{
   RlyPwr_tiEcuStPwrlLong = (uint16)MATHSRV_udtMIN(RlyPwr_tiEcuStPwrlLong_C,
                                                   65000);
   EcuSt_bPwrlLong = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidWaitPwrlEnd                                      */
/* !Description :  Attente de la fin de l'action du relais                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 RlyPwr_tiEcuStPwrlLong;                                      */
/*  output uint16 RlyPwr_tiEcuStPwrlLong;                                     */
/*  output boolean EcuSt_bPwrlLong;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidWaitPwrlEnd(void)
{
   uint16 u16LocaltiEcuStPwrlLong;


   if (RlyPwr_tiEcuStPwrlLong != 0)
   {
      u16LocaltiEcuStPwrlLong = (uint16)(RlyPwr_tiEcuStPwrlLong - 1);
      RlyPwr_tiEcuStPwrlLong = (uint16)MATHSRV_udtMIN(u16LocaltiEcuStPwrlLong,
                                                      65000);
   }
   if (RlyPwr_tiEcuStPwrlLong == 0)
   {
      EcuSt_bPwrlLong = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidInitTempo                                        */
/* !Description :  La temporisation RlyPwr_tiWaitAcvModEcoBatt est            */
/*                 réinitialisée sur transition clé on/clé off                */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Rly_tiMaintMainRly_C;                                        */
/*  input uint16 RlyPwr_tiWaitAcvModEcoBatt_C;                                */
/*  input uint16 RlyPwr_tiEcuStPwrlLong_C;                                    */
/*  output uint16 Rly_tiEndHldRlyActr;                                        */
/*  output uint16 RlyPwr_tiWaitAcvModEcoBatt;                                 */
/*  output uint16 RlyPwr_tiEcuStPwrlLong;                                     */
/*  output boolean EcuSt_bPwrlLong;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidInitTempo(void)
{
   Rly_tiEndHldRlyActr =
      (uint16)MATHSRV_udtMIN(Rly_tiMaintMainRly_C, 775);
   RlyPwr_tiWaitAcvModEcoBatt =
      (uint16)MATHSRV_udtMIN(RlyPwr_tiWaitAcvModEcoBatt_C, 38250);
   RlyPwr_tiEcuStPwrlLong = (uint16)MATHSRV_udtMIN(RlyPwr_tiEcuStPwrlLong_C,
                                                   65000);
   EcuSt_bPwrlLong = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidWaitAcvModEcoBattCalib                           */
/* !Description :  Si la calibration RlyPwr_bModEcoBatt_Inh_C qui permet      */
/*                 d’inhiber la stratégie d’économie batterie est égale à 1 il*/
/*                 faut mettre la variable RlyPwr_bAcvModEcoBatt à 1          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean RlyPwr_bAcvModEcoBatt;                                      */
/*  output boolean RlyPwr_bAcvModEcoBatt;                                     */
/*  output boolean Ext_bUnBlsReq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidWaitAcvModEcoBattCalib(void)
{
   RlyPwr_bAcvModEcoBatt = 0;
   VEMS_vidSET(Ext_bUnBlsReq, RlyPwr_bAcvModEcoBatt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyMngHldReq                                     */
/* !Description :  Cette fonction sert à demander un maintien du réveil UCE.  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void RLYPWR_vidFinMaintRelPrinp();                            */
/*  input boolean Actionneurs;                                                */
/*  input boolean Ext_bFctHldReq;                                             */
/*  input uint8 Ext_rSpdFanAct;                                               */
/*  input boolean Immo_bEcuAwakeImmoNeed;                                     */
/*  input boolean Rly_bTiEndHldRlyActr;                                       */
/*  output boolean Ext_bFctHldReq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyMngHldReq(void)
{
   /*7_RlyMngHldReq*/
   boolean  bLocalActionneurs;
   boolean  bLocalImmo_bEcuAwakeImmoNeed;
   boolean  bLocalExt_bFctHldReq;
   uint8    u8LocalExt_rSpdFanAct;


   VEMS_vidGET(Actionneurs, bLocalActionneurs);
   VEMS_vidGET(Ext_bFctHldReq, bLocalExt_bFctHldReq);
   if (bLocalActionneurs != 0)
   {
      VEMS_vidSET(Ext_bFctHldReq, 1);
   }
   else
   {
      RLYPWR_vidFinMaintRelPrinp();
      VEMS_vidGET(Ext_rSpdFanAct, u8LocalExt_rSpdFanAct);
      VEMS_vidGET(Immo_bEcuAwakeImmoNeed, bLocalImmo_bEcuAwakeImmoNeed);
      if (bLocalExt_bFctHldReq != 0)
      {
         if ( (Rly_bTiEndHldRlyActr != 0)
            &&(bLocalImmo_bEcuAwakeImmoNeed == 0)
            &&(u8LocalExt_rSpdFanAct == 0))
         {
            VEMS_vidSET(Ext_bFctHldReq, 0);
         }
         else
         {
            VEMS_vidSET(Ext_bFctHldReq, 1);
         }
      }
      else
      {
         if ( (u8LocalExt_rSpdFanAct > 0)
            ||(bLocalImmo_bEcuAwakeImmoNeed != 0))
         {
            VEMS_vidSET(Ext_bFctHldReq, 1);
         }
         else
         {
            VEMS_vidSET(Ext_bFctHldReq, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidFinMaintRelPrinp                                 */
/* !Description :  Cette fonction indique que le delai de maintien de la      */
/*                 fermeture du relay pricipal est terminé.                   */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Rly_tiEndHldRlyActr;                                         */
/*  output uint16 Rly_tiEndHldRlyActr;                                        */
/*  output boolean Rly_bTiEndHldRlyActr;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidFinMaintRelPrinp(void)
{
   /*F01_FinMaintRelPrinp*/
   if (Rly_tiEndHldRlyActr != 0)
   {
      Rly_tiEndHldRlyActr =
         (uint16)(Rly_tiEndHldRlyActr - 1);
   }
   if (Rly_tiEndHldRlyActr == 0)
   {
      Rly_bTiEndHldRlyActr = 1;
   }
   else
   {
      Rly_bTiEndHldRlyActr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidPrevEcuStPwrlLong                                */
/* !Description :  Le booléen EcuSt_bPwrlLong est réinitialisé sur transition */
/*                 clef off clef on                                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean EcuSt_bPwrlLong;                                            */
/*  output boolean RLYPWR_bEcuStPwrlLongPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidPrevEcuStPwrlLong(void)
{
   if (EcuSt_bPwrlLong == 0)
   {
      RLYPWR_bEcuStPwrlLongPrev = 0;
   }
   else
   {
      RLYPWR_bEcuStPwrlLongPrev = 1;
   }
}
/*------------------------------- end of file --------------------------------*/