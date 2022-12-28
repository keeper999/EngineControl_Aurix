/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CHAADVMINUNLIM                                          */
/* !Description     : CHAADVMINUNLIM Component                                */
/*                                                                            */
/* !Module          : CHAADVMINUNLIM                                          */
/* !Description     :  DEBORNAGE AVANCE MIN PR ESP SECURITAIRE                */
/*                                                                            */
/* !File            : CHAADVMINUNLIM_FCT1.C                                   */
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
/*   1 / CHAADVMINUNLIM_vidInitOutput                                         */
/*   2 / CHAADVMINUNLIM_vidRstSelc                                            */
/*   3 / CHAADVMINUNLIM_vidEventMs                                            */
/*   4 / CHAADVMINUNLIM_vidInit                                               */
/*   5 / CHAADVMINUNLIM_vidRearWheelSpeed                                     */
/*   6 / CHAADVMINUNLIM_vidASRSecuReq                                         */
/*   7 / CHAADVMINUNLIM_vidESPReg                                             */
/*   8 / CHAADVMINUNLIM_vidASRReg                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 05440 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CHAADVMINUNLIM/CHAADVMINUNLIM_FCT1$*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   11 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   11 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CHAADVMINUNLIM.h"
#include "CHAADVMINUNLIM_L.h"
#include "CHAADVMINUNLIM_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidInitOutput                               */
/* !Description :  Initialisation du timer.                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CHAADVMINUNLIM_bInitCndPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidInitOutput(void)
{
   CHAADVMINUNLIM_bInitCndPrev = 0;
   Ext_tiTmrASRReg = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidRstSelc                                  */
/* !Description :  Fonction reset EventSelc                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Ext_ctSdlASRSecuReqThd_C;                                     */
/*  output uint8 Ext_ctSdlASRSecuReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidRstSelc(void)
{
   Ext_ctSdlASRSecuReq = Ext_ctSdlASRSecuReqThd_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidEventMs                                  */
/* !Description :  L’automate « EventSelc » permet de créer un événement à    */
/*                 10ms à partir d’un événement à 5ms.                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CHAADVMINUNLIM_vidRearWheelSpeed();                      */
/*  extf argret void CHAADVMINUNLIM_vidASRSecuReq();                          */
/*  input uint8 Ext_ctSdlASRSecuReq;                                          */
/*  input uint8 Ext_ctSdlASRSecuReqThd_C;                                     */
/*  output uint8 Ext_ctSdlASRSecuReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidEventMs(void)
{

   if ( Ext_ctSdlASRSecuReq >= Ext_ctSdlASRSecuReqThd_C)
   {
      Ext_ctSdlASRSecuReq = 0;
      CHAADVMINUNLIM_vidRearWheelSpeed();
      CHAADVMINUNLIM_vidASRSecuReq();
   }
   else
   {
      Ext_ctSdlASRSecuReq = (uint8)(Ext_ctSdlASRSecuReq + 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidInit                                     */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean CoCha_bASRSecuReq;                                         */
/*  output uint8 Ext_spdVehAvrReWhl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidInit(void)
{
   VEMS_vidSET(CoCha_bASRSecuReq, 0);
   VEMS_vidSET(Ext_spdVehAvrReWhl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidRearWheelSpeed                           */
/* !Description :  Cette fonction permet la production de la moyenne des      */
/*                 vitesses des roues arrières, issues du CAN.                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Wael.Chambah                                               */
/* !Trace_To    :  VEMS_R_11_05440_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vitesse_vehicule_ard_mux;                                    */
/*  input uint16 Vitesse_vehicule_arg_mux;                                    */
/*  output uint8 Ext_spdVehAvrReWhl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidRearWheelSpeed(void)
{
   uint32  u32LocalExt_spdVehAvrReWhl;
   uint16  u16LocalVitesse_vehicule_ard_mux;
   uint16  u16LocalVitesse_vehicule_arg_mux;
   uint8   u8LocalExt_spdVehAvrReWhl;


   VEMS_vidGET(Vitesse_vehicule_ard_mux, u16LocalVitesse_vehicule_ard_mux);
   VEMS_vidGET(Vitesse_vehicule_arg_mux, u16LocalVitesse_vehicule_arg_mux);
   u32LocalExt_spdVehAvrReWhl = (uint32)( ( u16LocalVitesse_vehicule_ard_mux
                                          + u16LocalVitesse_vehicule_arg_mux
                                          + 100)
                                        / 200);
   u8LocalExt_spdVehAvrReWhl = (uint8)MATHSRV_udtMIN(u32LocalExt_spdVehAvrReWhl,
                                                     255);
   VEMS_vidSET(Ext_spdVehAvrReWhl, u8LocalExt_spdVehAvrReWhl);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidASRSecuReq                               */
/* !Description :  Fonction de demande d'activation d'ASR sécuritaire .       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Wael.Chambah                                               */
/* !Trace_To    :  VEMS_R_11_05440_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CHAADVMINUNLIM_vidESPReg();                              */
/*  extf argret void CHAADVMINUNLIM_vidASRReg();                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bASRSecuReq_flag1;                                      */
/*  input boolean Ext_bASRSecuReq_flag2;                                      */
/*  output boolean CoCha_bASRSecuReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidASRSecuReq(void)
{

   CHAADVMINUNLIM_vidESPReg();
   CHAADVMINUNLIM_vidASRReg();

   if (  (Ext_bASRSecuReq_flag1 != 0)
      || (Ext_bASRSecuReq_flag2 != 0))
   {
      VEMS_vidSET(CoCha_bASRSecuReq, 1);
   }
   else
   {
      VEMS_vidSET(CoCha_bASRSecuReq, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidESPReg                                   */
/* !Description :  Demande d’activation d’ASR sécuritaire en contrôle de lacet*/
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Wael.Chambah                                               */
/* !Trace_To    :  VEMS_R_11_05440_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input boolean Cha_bESPReg;                                                */
/*  input uint8 Ext_spdVehAvrReWhl;                                           */
/*  input uint8 Ext_spdVehAvrReWhlThd_C;                                      */
/*  output boolean Ext_bASRSecuReq_flag1;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidESPReg(void)
{
   uint8    u8LocalCha_stTqReq;
   uint8    u8LocalExt_spdVehAvrReWhl;
   boolean  bLocalCha_bESPReg;


   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);
   VEMS_vidGET(Cha_bESPReg, bLocalCha_bESPReg);
   VEMS_vidGET(Ext_spdVehAvrReWhl, u8LocalExt_spdVehAvrReWhl);
   if ( ( u8LocalExt_spdVehAvrReWhl > Ext_spdVehAvrReWhlThd_C)
      && (u8LocalCha_stTqReq == 5)
      && (bLocalCha_bESPReg != 0))
   {
      Ext_bASRSecuReq_flag1 = 1;
   }
   else
   {
      Ext_bASRSecuReq_flag1 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHAADVMINUNLIM_vidASRReg                                   */
/* !Description :  Cette fonction élabore la demande d’activation ASR         */
/*                 sécuritaire lors de l’activation de l’ASR moteur.          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Wael.Chambah                                               */
/* !Trace_To    :  VEMS_R_11_05440_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Cha_stTqReq;                                                  */
/*  input boolean Cha_bASRReg;                                                */
/*  input uint8 Ext_spdVehAvrReWhl;                                           */
/*  input boolean CHAADVMINUNLIM_bInitCndPrev;                                */
/*  input uint16 Ext_tiTmrASRReg_C;                                           */
/*  input uint16 Ext_tiTmrASRReg;                                             */
/*  input uint8 Ext_ctSdlASRSecuReqThd_C;                                     */
/*  input uint8 Ext_spdVehAvrReWhlThd_C;                                      */
/*  input boolean CHAADVMINUNLIM_bTimeOut;                                    */
/*  output uint16 Ext_tiTmrASRReg;                                            */
/*  output boolean CHAADVMINUNLIM_bTimeOut;                                   */
/*  output boolean CHAADVMINUNLIM_bInitCndPrev;                               */
/*  output boolean Ext_bASRSecuReq_flag2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHAADVMINUNLIM_vidASRReg(void)
{
   boolean  bLocalCha_bASRReg;
   boolean  bLocalInitCnd;
   uint8    u8LocalCha_stTqReq;
   uint8    u8LocalExt_spdVehAvrReWhl;
   sint32   s32LocalTimer;


   VEMS_vidGET(Cha_stTqReq, u8LocalCha_stTqReq);
   VEMS_vidGET(Cha_bASRReg, bLocalCha_bASRReg);
   VEMS_vidGET(Ext_spdVehAvrReWhl, u8LocalExt_spdVehAvrReWhl);

   if (  (u8LocalCha_stTqReq != 5)
      && (bLocalCha_bASRReg == 0))
   {
      bLocalInitCnd = 0;
   }
   else
   {
      bLocalInitCnd = 1;
   }

   if (  (CHAADVMINUNLIM_bInitCndPrev == 0)
      && (bLocalInitCnd != 0))
   {
      s32LocalTimer = (sint32)Ext_tiTmrASRReg_C;
      Ext_tiTmrASRReg = (uint16)MATHSRV_udtMIN(s32LocalTimer, 60000);
      if (Ext_tiTmrASRReg == 0)
      {
         CHAADVMINUNLIM_bTimeOut = 1;
      }
      else
      {
         CHAADVMINUNLIM_bTimeOut = 0;
      }
   }
   else
   {
      if (Ext_tiTmrASRReg > 0)
      {
         s32LocalTimer = (sint32)( Ext_tiTmrASRReg
                                 - ( Ext_ctSdlASRSecuReqThd_C
                                   + 1));
         Ext_tiTmrASRReg = (uint16)MATHSRV_udtCLAMP(s32LocalTimer,
                                                    0,
                                                    60000);

         if (Ext_tiTmrASRReg == 0)
         {
            CHAADVMINUNLIM_bTimeOut = 1;
         }
         else
         {
            CHAADVMINUNLIM_bTimeOut = 0;
         }
      }
   }

   CHAADVMINUNLIM_bInitCndPrev = bLocalInitCnd;

   if (  (u8LocalExt_spdVehAvrReWhl > Ext_spdVehAvrReWhlThd_C)
      && (u8LocalCha_stTqReq == 5)
      && (CHAADVMINUNLIM_bTimeOut == 0))
   {
      Ext_bASRSecuReq_flag2 = 1;
   }
   else
   {
      Ext_bASRSecuReq_flag2 = 0;
   }
}
/*------------------------------- End of file --------------------------------*/