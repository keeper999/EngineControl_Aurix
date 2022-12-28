/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STTIF                                                   */
/* !Description     : STTIF component.                                        */
/*                                                                            */
/* !Module          : STTIF                                                   */
/* !Description     : Spécification d’interface pour la fonction STT          */
/*                                                                            */
/* !File            : STTIF_FCT1.C                                            */
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
/*   1 / STTIF_vidInjCutOff                                                   */
/*   2 / STTIF_vidOutput_nEng                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5199315 / 01                                        */
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

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "STTIF.h"
#include "STTIF_L.h"
#include "STTIF_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTIF_vidInjCutOff                                         */
/* !Description :  Fonction pour produite la sortie Ext_bAcvInjCutOff.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean InjSys_bTotCutOff;                                          */
/*  output boolean Ext_bAcvInjCutOff;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTIF_vidInjCutOff(void)
{
   boolean bLocalInjSys_bTotCutOff;


   VEMS_vidGET(InjSys_bTotCutOff, bLocalInjSys_bTotCutOff);
   VEMS_vidSET(Ext_bAcvInjCutOff, bLocalInjSys_bTotCutOff);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTIF_vidOutput_nEng                                       */
/* !Description :  Fonction pour produite la sortie Ext_nEngToothClc.         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  output uint16 Ext_nEngToothClc;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTIF_vidOutput_nEng(void)
{
   uint16 u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 2000);
   VEMS_vidSET(Ext_nEngToothClc, u16LocalExt_nEng);
}
/****************************** end of file ***********************************/