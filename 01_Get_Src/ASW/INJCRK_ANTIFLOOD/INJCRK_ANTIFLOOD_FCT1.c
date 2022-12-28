/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCRK_ANTIFLOOD                                        */
/* !Description     : INJCRK_ANTIFLOOD component                              */
/*                                                                            */
/* !Module          : INJCRK_ANTIFLOOD                                        */
/* !Description     : DETECTION DE DEMANDE DE DENOYAGE                        */
/*                                                                            */
/* !File            : INJCRK_ANTIFLOOD_FCT1.C                                 */
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
/*   1 / INJCRK_ANTIFLOOD_vidInitOutput                                       */
/*   2 / INJCRK_ANTIFLOOD_vidCrkFuelling                                      */
/*   3 / INJCRK_ANTIFLOOD_vidInitCrkFlood                                     */
/*   4 / INJCRK_ANTIFLOOD_vidMngAntiFlood                                     */
/*   5 / INJCRK_ANTIFLOOD_vidCranking                                         */
/*   6 / INJCRK_ANTIFLOOD_vidEngSpdOk                                         */
/*   7 / INJCRK_ANTIFLOOD_vidEngSpdNok                                        */
/*   8 / INJCRK_ANTIFLOOD_vidIniRunToCrnk                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 04908 / 2                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJ/INJRCRK/INJCRK_ANTIFLOOD/INJCR$*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   18 Mar 2011 $*/
/* $Author::   hmelloul                               $$Date::   18 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "INJCRK_ANTIFLOOD.h"
#include "INJCRK_ANTIFLOOD_L.h"
#include "INJCRK_ANTIFLOOD_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidInitOutput                             */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Disable_inj_for_anti_flood;                                */
/*  output boolean Function_anti_flood;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidInitOutput(void)
{
   VEMS_vidSET(Disable_inj_for_anti_flood, 0);
   Function_anti_flood = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidCrkFuelling                            */
/* !Description :  Fonction qui active la fonction                            */
/*                 INJCRK_ANTIFLOOD_vidInitAntFlood si Vehicle_active_state et*/
/*                 VS_CRANKING sont égaux                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCRK_ANTIFLOOD_vidInitCrkFlood();                      */
/*  input st23 Vehicle_active_state;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidCrkFuelling(void)
{
   uint8 u8LocalVehicle_active_state;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_CRANKING)
   {
      INJCRK_ANTIFLOOD_vidInitCrkFlood();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidInitCrkFlood                           */
/* !Description :  Fonction d'initialisation à 0 de Disable_inj_for_anti_flood*/
/*                 et de Function_anti_flood                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Disable_inj_for_anti_flood;                                */
/*  output boolean Function_anti_flood;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidInitCrkFlood(void)
{
   VEMS_vidSET(Disable_inj_for_anti_flood, 0);
   Function_anti_flood = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidMngAntiFlood                           */
/* !Description :  Appel de la focntions INJCRK_ANTIFLOOD_vidCranking si      */
/*                 Vehicle_active_state repasse dans l'état VS_CRANKING, sinon*/
/*                 INJCRK_ANTIFLOOD_vidNotCranking sera appelé                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCRK_ANTIFLOOD_vidCranking();                          */
/*  extf argret void INJCRK_ANTIFLOOD_vidNotCranking();                       */
/*  input st23 Vehicle_active_state;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidMngAntiFlood(void)
{
   uint8 u8LocalVehicle_active_state;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   if (u8LocalVehicle_active_state == VS_CRANKING)
   {
      INJCRK_ANTIFLOOD_vidCranking();
   }
   else
   {
      INJCRK_ANTIFLOOD_vidNotCranking();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidCranking                               */
/* !Description :  Appel de la fonction INJCRK_ANTIFLOOD_vidEngSpdOk si       */
/*                 Regime_moteur_32 est inférieur à Anti_flood_regime_reinj,  */
/*                 sinon INJCRK_ANTIFLOOD_vidEngSpdNok sera appelé            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCRK_ANTIFLOOD_vidEngSpdOk();                          */
/*  extf argret void INJCRK_ANTIFLOOD_vidEngSpdNok();                         */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Anti_flood_regime_reinj;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidCranking(void)
{
   uint8 u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   if (u8LocalRegime_moteur_32 < Anti_flood_regime_reinj)
   {
/*  !Comment : Bloc Eng_spd_ ok                                              */
      INJCRK_ANTIFLOOD_vidEngSpdOk();
   }
   else
   {
/*  !Comment : Bloc Eng_spd_nok                                              */
      INJCRK_ANTIFLOOD_vidEngSpdNok();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidEngSpdOk                               */
/* !Description :  Appel de la focntions INJCRK_ANTIFLOOD_vidDetAntiFlood si  */
/*                 Function_anti_flood égale à 1, sinon                       */
/*                 INJCRK_ANTIFLOOD_vidConfAntFlood sera appelé               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCRK_ANTIFLOOD_vidDetAntiFlood();                      */
/*  extf argret void INJCRK_ANTIFLOOD_vidConfAntFlood();                      */
/*  input boolean Function_anti_flood;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidEngSpdOk(void)
{
   if (Function_anti_flood == 0)
   {
      INJCRK_ANTIFLOOD_vidDetAntiFlood();
   }
   else
   {
      INJCRK_ANTIFLOOD_vidConfAntFlood();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidEngSpdNok                              */
/* !Description :  Fonction d'initialisation à 0 de Disable_inj_for_anti_flood*/
/*                 et de Function_anti_flood                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Disable_inj_for_anti_flood;                                */
/*  output boolean Function_anti_flood;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidEngSpdNok(void)
{
   VEMS_vidSET(Disable_inj_for_anti_flood, 0);
   Function_anti_flood = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidIniRunToCrnk                           */
/* !Description :  Fonction d'initialisation à 0 de Disable_inj_for_anti_flood*/
/*                 et de Function_anti_flood                                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Disable_inj_for_anti_flood;                                */
/*  output boolean Function_anti_flood;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidIniRunToCrnk(void)
{
   VEMS_vidSET(Disable_inj_for_anti_flood, 0);
   Function_anti_flood = 0;
}
/*---------------------------- end of file -----------------------------------*/