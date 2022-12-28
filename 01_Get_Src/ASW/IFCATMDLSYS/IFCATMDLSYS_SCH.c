/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFCATMDLSYS                                             */
/* !Description     : IFCATMDLSYS Component                                   */
/*                                                                            */
/* !Module          : IFCATMDLSYS                                             */
/* !Description     : INTERFACE OF CATMDL FUNCTION                            */
/*                                                                            */
/* !File            : IFCATMDLSYS_SCH.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / RE_ExMGslT2_001_MSEIfTWC                                             */
/*   2 / TWCMgt_SdlFast_TWCMgtIf                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 06970 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#064711                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CATMDLSYS/IFCATMDLSYS/IFCATMDLSY$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   23 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   23 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "IFCATMDLSYS.h"
#include "IFCATMDLSYS_L.h"
#include "IFCATMDLSYS_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_ExMGslT2_001_MSEIfTWC                                   */
/* !Description :  Reset event occurring after ExMGslT2 initialisation.       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFCATMDLSYS_vidTWCMgtIf();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_ExMGslT2_001_MSEIfTWC                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_ExMGslT2_001_MSEIfTWC(void)
{
   IFCATMDLSYS_vidTWCMgtIf();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMgt_SdlFast_TWCMgtIf                                    */
/* !Description :  Fast monitor of TWCMgt interface.                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFCATMDLSYS_vidTWCMgtIf();                               */
/*  input uint8 IFCATMDLSYS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TWCMgt_SdlFast_TWCMgtIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMgt_SdlFast_TWCMgtIf(void)
{
   if (IFCATMDLSYS_u8Inhib != 0x5A)
   {
      IFCATMDLSYS_vidTWCMgtIf();
   }
}
/*------------------------------- end of file --------------------------------*/