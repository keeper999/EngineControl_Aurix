/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHMUX                                                  */
/* !Description     : VEHMUX Component                                        */
/*                                                                            */
/* !Module          : VEHMUX                                                  */
/* !Description     : ACQUISITION VITESSE VEHICULE VIA CAN                    */
/*                                                                            */
/* !File            : VEHMUX_SCH.C                                            */
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
/*   1 / VehSpd_EveRst_VehMux                                                 */
/*   2 / VehSpd_SdlMid_VehMux                                                 */
/*   3 / VehSpd_EveRxn7F2_VehMux                                              */
/*   4 / VehSpd_EveRxn552_VehMux                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 05607 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VEHMUX/VEHMUX_SCH.C_v             $*/
/* $Revision::   1.6      $$Author::   ACHEBINO       $$Date::   18 Jun 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   18 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VEHMUX.h"
#include "VEHMUX_L.h"
#include "VEHMUX_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveRst_VehMux                                       */
/* !Description :  Reset of VehSpd function.                                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMUX_vidVehSpdMuxInit();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VehSpd_EveRst_VehMux                                           */
/* !Trigger  : VehSpd_EveRst_VehMux                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveRst_VehMux(void)
{
   VEHMUX_vidVehSpdMuxInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlMid_VehMux                                       */
/* !Description :  Periodic event                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMUX_vidAcquisition38D();                              */
/*  input uint8 VEHMUX_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VehSpd_SdlMid_VehMux                                           */
/* !Trigger  : VehSpd_SdlMid_VehMux                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlMid_VehMux(void)
{
   if (VEHMUX_u8Inhib != 0x5A)
   {
      VEHMUX_vidAcquisition38D();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveRxn7F2_VehMux                                    */
/* !Description :  Receiving 7F2 frame                                        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMUX_vidCalcDist7F2();                                 */
/*  input uint8 VEHMUX_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : VehSpd_EveRxn7F2_VehMux                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveRxn7F2_VehMux(void)
{
   if (VEHMUX_u8Inhib != 0x5A)
   {
      VEHMUX_vidCalcDist7F2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_EveRxn552_VehMux                                    */
/* !Description :  Receiving 552 Frame                                        */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHMUX_vidCalcDist552();                                 */
/*  input uint8 VEHMUX_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VehSpd_EveRxn552_VehMux                                        */
/* !Trigger  : VehSpd_EveRxn552_VehMux                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_EveRxn552_VehMux(void)
{
   if (VEHMUX_u8Inhib != 0x5A)
   {
      VEHMUX_vidCalcDist552();
   }
}

/*-------------------------------end of file----------------------------------*/
