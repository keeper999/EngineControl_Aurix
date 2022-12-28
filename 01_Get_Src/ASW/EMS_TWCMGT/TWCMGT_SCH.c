/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TWCMGT                                                  */
/* !Description     : TWCMGT component.                                       */
/*                                                                            */
/* !Module          : TWCMGT                                                  */
/* !Description     : Three Way Catalyst Heating Manager.                     */
/*                                                                            */
/* !File            : TWCMGT_SCH.C                                            */
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
/*   1 / TWCMgt_EveIni_TWCMgt                                                 */
/*   2 / TWCMgt_SdlFast_TWCMgt                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 02024 / 01                                        */
/* !OtherRefs   : 01460_10_02228 / 1                                          */
/* !OtherRefs   : VEMS V02 ECU#054415                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "TWCMGT.h"
#include "TWCMGT_L.h"
#include "TWCMGT_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMgt_EveIni_TWCMgt                                       */
/* !Description :  Initialization event of the function Three Way Catalyst    */
/*                 Heating Manager                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_001.01                                     */
/*                 VEMS_R_11_02024_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidInitThreeWayCatHeatMng();                      */
/*  extf argret void TWCMGT_VidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TWCMgt_EveIni_TWCMgt                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMgt_EveIni_TWCMgt(void)
{
   TWCMGT_VidInitThreeWayCatHeatMng();
   TWCMGT_VidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMgt_SdlFast_TWCMgt                                      */
/* !Description :  Calculation event of the function Three Way Catalyst       */
/*                 Heating Manager                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_001.01                                     */
/*                 VEMS_R_11_02024_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TWCMGT_VidThreeWayCatHeatMngVal();                       */
/*  input uint8 TWCMGT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TWCMgt_SdlFast_TWCMgt                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMgt_SdlFast_TWCMgt(void)
{
   if (TWCMGT_u8Inhib != 0x5A)
   {
      TWCMGT_VidThreeWayCatHeatMngVal();
   }
}
/*------------------------------- end of file --------------------------------*/