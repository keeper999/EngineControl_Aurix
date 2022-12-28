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
/* !File            : INJCRK_ANTIFLOOD_FCT2.C                                 */
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
/*   1 / INJCRK_ANTIFLOOD_vidDetAntiFlood                                     */
/*   2 / INJCRK_ANTIFLOOD_vidInitAntiFlood                                    */
/*   3 / INJCRK_ANTIFLOOD_vidConfAntFlood                                     */
/*   4 / INJCRK_ANTIFLOOD_vidPosPedOk                                         */
/*   5 / INJCRK_ANTIFLOOD_vidNotCranking                                      */
/*   6 / INJCRK_ANTIFLOOD_vidRestAntFlood                                     */
/*   7 / INJCRK_ANTIFLOOD_vidPosPedNok                                        */
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
#include "MATHSRV.h"
#include "INJCRK_ANTIFLOOD.h"
#include "INJCRK_ANTIFLOOD_L.h"
#include "INJCRK_ANTIFLOOD_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidDetAntiFlood                           */
/* !Description :  Appel de la focntions INJCRK_ANTIFLOOD_vidIniAntiFlood si  */
/*                 Dv_position_pedale_relative est supérieur à                */
/*                 Anti_flood_pedale_limit                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCRK_ANTIFLOOD_vidInitAntiFlood();                     */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input uint8 Anti_flood_pedale_limit;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidDetAntiFlood(void)
{
   uint8 u8LocalDv_position_pedale_relati;


   VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_position_pedale_relati);

   if (u8LocalDv_position_pedale_relati > Anti_flood_pedale_limit)
   {
      INJCRK_ANTIFLOOD_vidInitAntiFlood();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidInitAntiFlood                          */
/* !Description :  Initialisation à 1 de Function_anti_flood et affectation de*/
/*                 la valeur de Anti_flood_delay à Anti_flood_delay_counter   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Anti_flood_delay;                                            */
/*  output uint16 Anti_flood_delay_counter;                                   */
/*  output boolean Function_anti_flood;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidInitAntiFlood(void)
{
   Anti_flood_delay_counter = (uint16)MATHSRV_udtMIN(Anti_flood_delay, 29999);
   Function_anti_flood = 1;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidConfAntFlood                           */
/* !Description :  Appel de la fonction INJCRK_ANTIFLOOD_vidPosPedNok si      */
/*                 Dv_position_pedale_relative est inférieur ou égale à la    */
/*                 différence entre Anti_flood_pedale_limit et                */
/*                 Anti_flood_pedale_hysteresis, sinon                        */
/*                 INJCRK_ANTIFLOOD_vidPosPedOk sera appelé                   */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCRK_ANTIFLOOD_vidPosPedNok();                         */
/*  extf argret void INJCRK_ANTIFLOOD_vidPosPedOk();                          */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input uint8 Anti_flood_pedale_limit;                                      */
/*  input uint8 Anti_flood_pedale_hysteresis;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidConfAntFlood(void)
{
   uint8  u8LocalDv_position_pedale_relati;
   sint16 s16LocalComp;


   VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_position_pedale_relati);

   s16LocalComp = (sint16)(Anti_flood_pedale_limit -
                           Anti_flood_pedale_hysteresis);
   if (u8LocalDv_position_pedale_relati <= s16LocalComp)
   {
      INJCRK_ANTIFLOOD_vidPosPedNok();
   }
   else
   {
      INJCRK_ANTIFLOOD_vidPosPedOk();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidPosPedOk                               */
/* !Description :  calcule de Anti_flood_delay_counter et de                  */
/*                 Disable_inj_for_anti_flood                                 */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Anti_flood_delay_counter;                                    */
/*  output uint16 Anti_flood_delay_counter;                                   */
/*  output boolean Disable_inj_for_anti_flood;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidPosPedOk(void)
{
   sint32 s32LocalComp;


   s32LocalComp = (Anti_flood_delay_counter - 1);
   Anti_flood_delay_counter = (uint16)MATHSRV_udtCLAMP(s32LocalComp, 0, 29999);
   if (Anti_flood_delay_counter == 0)
   {
      VEMS_vidSET(Disable_inj_for_anti_flood, 1);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidNotCranking                            */
/* !Description :  Appel de la focntions INJCRK_ANTIFLOOD_vidRestAntFlood si  */
/*                 Regime_moteur_32 est supérieur à Anti_flood_regime_reinj   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJCRK_ANTIFLOOD_vidRestAntFlood();                      */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Anti_flood_regime_reinj;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidNotCranking(void)
{
   uint8 u8LocalRegime_moteur_32;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   if (u8LocalRegime_moteur_32 > Anti_flood_regime_reinj)
   {
      INJCRK_ANTIFLOOD_vidRestAntFlood();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidRestAntFlood                           */
/* !Description :  Fonction d'initialisation à 0 de Disable_inj_for_anti_flood*/
/*                 et de Function_anti_flood                                  */
/* !Number      :  FCT2.6                                                     */
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
void INJCRK_ANTIFLOOD_vidRestAntFlood(void)
{
   VEMS_vidSET(Disable_inj_for_anti_flood, 0);
   Function_anti_flood = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidPosPedNok                              */
/* !Description :  Fonction d'initialisation à 0 de Disable_inj_for_anti_flood*/
/*                 et de Function_anti_flood                                  */
/* !Number      :  FCT2.7                                                     */
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
void INJCRK_ANTIFLOOD_vidPosPedNok(void)
{
   VEMS_vidSET(Disable_inj_for_anti_flood, 0);
   Function_anti_flood = 0;
}
/*---------------------------- end of file -----------------------------------*/