/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILACTEST                                            */
/* !Description     : IGCOILACTEST Component                                  */
/*                                                                            */
/* !Module          : IGCOILACTEST                                            */
/* !Description     :  TESTS ACTIONNEURS DES BOBINES                          */
/*                                                                            */
/* !File            : IGCOILACTEST_SCH.C                                      */
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
/*   1 / IgCmd_EveRst_ActrTstCoil                                             */
/*   2 / IgCmd_SdlFast_ActrTstCoil                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 00741 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGCOILACTEST/IGCOILACTEST_SCH.C_v $*/
/* $Revision::   1.3      $$Author::   vgarnier       $$Date::   01 Jun 2010 $*/
/* $Author::   vgarnier                               $$Date::   01 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IGCOILACTEST.h"
#include "IGCOILACTEST_L.h"
#include "IGCOILACTEST_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveRst_ActrTstCoil                                   */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILACTEST_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveRst_ActrTstCoil(void)
{
   IGCOILACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_SdlFast_ActrTstCoil                                  */
/* !Description :  Moniteur rapide de la fonction IgCmd                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILACTEST_vidIgnTime();                               */
/*  extf argret void IGCOILACTEST_vidEntryMode();                             */
/*  extf argret void IGCOILACTEST_vidTestMode();                              */
/*  extf argret void IGCOILACTEST_vidTestEnd();                               */
/*  input uint8 IGCOILACTEST_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_SdlFast_ActrTstCoil(void)
{
   if (IGCOILACTEST_u8Inhib != 0x5A)
   {
      IGCOILACTEST_vidIgnTime();
      IGCOILACTEST_vidEntryMode();
      IGCOILACTEST_vidTestMode();
      IGCOILACTEST_vidTestEnd();
   }
}

/*------------------------------- end of file --------------------------------*/