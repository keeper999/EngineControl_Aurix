/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COFANACTEST                                             */
/* !Description     : COFANACTEST Component                                   */
/*                                                                            */
/* !Module          : COFANACTEST                                             */
/* !Description     :  TESTS ACTIONNEURS DES GMV                              */
/*                                                                            */
/* !File            : COFANACTEST_SCH.C                                       */
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
/*   1 / CoFan_EveRst_ActrTstGMV                                              */
/*   2 / CoFan_SdlMid_ActrTstGMV                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 00774 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/COFAN/COFANACTEST/COFANACTEST_SC$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   20 Dec 2012 $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "COFANACTEST.h"
#include "COFANACTEST_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_EveRst_ActrTstGMV                                    */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANACTEST_vidInitOutput();                             */
/*  extf argret void COFANACTEST_vidGMVTstRun();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : CoFan_EveRst_ActrTstGMV                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_EveRst_ActrTstGMV(void)
{
   COFANACTEST_vidInitOutput();
   COFANACTEST_vidGMVTstRun();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_ActrTstGMV                                    */
/* !Description :  Moniteur moyen de la fonction commande des GMV             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COFANACTEST_vidGMVTstRun();                              */
/*  input uint8 COFANACTEST_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : CoFan_SdlMid_ActrTstGMV                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_ActrTstGMV(void)
{
   if (COFANACTEST_u8Inhib != 0x5A)
   {
      COFANACTEST_vidGMVTstRun();
   }
}
/*------------------------------- end of file --------------------------------*/