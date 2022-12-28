/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGARB                                                   */
/* !Description     : IGARB component.                                        */
/*                                                                            */
/* !Module          : IGARB                                                   */
/* !Description     : ARBITRAGE DES AVANCES À APPLIQUER                       */
/*                                                                            */
/* !File            : IGARB_SCH.C                                             */
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
/*   1 / IgSys_EveRst_IgArb                                                   */
/*   2 / IgSys_SdlSlow_IgArb                                                  */
/*   3 / IgSys_EveBDC_IgArb                                                   */
/*                                                                            */
/* !Reference   : V02 NT 09 07775 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#064402                                         */
/* !OtherRefs   : VEMS V02 ECU#064641                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "STD_TYPES.h"
#include "IgArb.h"
#include "IgArb_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveRst_IgArb                                         */
/* !Description :  Evènement Reset de la fonction IgSys                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgArb_vidIgArbInit();                                    */
/*  extf argret void IGARB_vidInitOutput();                                   */
/*  extf argret void IgArb_vidMngBenchMod();                                  */
/*  extf argret void IgArb_vidIgnitionArbitration();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveRst_IgArb                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveRst_IgArb(void)
{
   IgArb_vidIgArbInit();
   IGARB_vidInitOutput();
   IgArb_vidMngBenchMod();
   IgArb_vidIgnitionArbitration();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_SdlSlow_IgArb                                        */
/* !Description :  Moniteur lent de la fonction IgSys                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgArb_vidMngBenchMod();                                  */
/*  input uint8 IgArb_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_SdlSlow_IgArb                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_SdlSlow_IgArb(void)
{
   if (IgArb_u8Inhib != 0x5A)
   {
      IgArb_vidMngBenchMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveBDC_IgArb                                         */
/* !Description :  Interruption PMB de la fonction IgSys                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IgArb_vidIgnitionClcBenchMod();                          */
/*  extf argret void IgArb_vidIgnitionArbitration();                          */
/*  input uint8 IgArb_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveBDC_IgArb                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveBDC_IgArb(void)
{
   if (IgArb_u8Inhib != 0x5A)
   {
      IgArb_vidIgnitionClcBenchMod();
      IgArb_vidIgnitionArbitration();
   }
}
/******************************************************************************/