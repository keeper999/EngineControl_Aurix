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
/* !File            : CHAADVMINUNLIM_SCH.C                                    */
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
/*   1 / TqSys_EveRst_ChaAdvMinUnlim                                          */
/*   2 / TqSys_SdlFast_ChaAdvMinUnlim                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 05440 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CHAADVMINUNLIM/CHAADVMINUNLIM_SCH.$*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   11 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   11 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
/******************************************************************************/

#include "CHAADVMINUNLIM.h"
#include "CHAADVMINUNLIM_L.h"
#include "CHAADVMINUNLIM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveRst_ChaAdvMinUnlim                                */
/* !Description :  Evénement reset du calculateur .                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Wael.Chambah                                               */
/* !Trace_To    :  VEMS_R_11_05440_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CHAADVMINUNLIM_vidInit();                                */
/*  extf argret void CHAADVMINUNLIM_vidInitOutput();                          */
/*  extf argret void CHAADVMINUNLIM_vidRstSelc();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_EveRst_ChaAdvMinUnlim                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveRst_ChaAdvMinUnlim(void)
{
   CHAADVMINUNLIM_vidInit();
   CHAADVMINUNLIM_vidInitOutput();
   CHAADVMINUNLIM_vidRstSelc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_SdlFast_ChaAdvMinUnlim                               */
/* !Description :  Moniteur rapide de la fonction                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Wael.Chambah                                               */
/* !Trace_To    :  VEMS_R_11_05440_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CHAADVMINUNLIM_vidEventMs();                             */
/*  input uint8 CHAADVMINUNLIM_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_SdlFast_ChaAdvMinUnlim                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_SdlFast_ChaAdvMinUnlim(void)
{
   if (CHAADVMINUNLIM_u8Inhib != 0x5A)
   {
      CHAADVMINUNLIM_vidEventMs();
   }
}

/*------------------------------- End of file --------------------------------*/