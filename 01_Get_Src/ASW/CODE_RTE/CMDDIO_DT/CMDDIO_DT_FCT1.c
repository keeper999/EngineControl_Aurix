/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CMDDIO_DT                                               */
/* !Description     : CMDDIO_DT Component.                                    */
/*                                                                            */
/* !Module          : CMDDIO_DT                                               */
/* !Description     :  SPECIFICATION OF LOGICAL COMMANDS (DIOHAL) SENT TO BSW */
/*                                                                            */
/* !File            : CMDDIO_DT_FCT1.C                                        */
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
/*   1 / CMDDIO_DT_vidCmdDio_CTP1                                             */
/*   2 / CMDDIO_DT_vidCmdDio_CTP2                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6913275 / 01                                        */
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

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "CMDDIO_DT_IM.h"
#include "CMDDIO_DT.h"
#include "CMDDIO_DT_L.h"
#include "DIOHAL.h"
#include "CMDDIO_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDDIO_DT_vidCmdDio_CTP1                                   */
/* !Description :  The activation command of the CTP1 additional heater is    */
/*                 sent to the the basic layer using a DIOHAL API.            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean AdHeatCmd_bAcvCTP1Drv;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDDIO_DT_vidCmdDio_CTP1(void)
{
   boolean bLocalAdHeatCmd_bAcvCTP1Drv;


   VEMS_vidGET(AdHeatCmd_bAcvCTP1Drv, bLocalAdHeatCmd_bAcvCTP1Drv);

   DIOHAL_vidWrite(CH_DIO_OUT_CTP_1, bLocalAdHeatCmd_bAcvCTP1Drv);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CMDDIO_DT_vidCmdDio_CTP2                                   */
/* !Description :  The activation command of the CTP2 additional heater is    */
/*                 sent to the the basic layer using a DIOHAL API.            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean AdHeatCmd_bAcvCTP2Drv;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CMDDIO_DT_vidCmdDio_CTP2(void)
{
   boolean bLocalAdHeatCmd_bAcvCTP2Drv;

   VEMS_vidGET(AdHeatCmd_bAcvCTP2Drv, bLocalAdHeatCmd_bAcvCTP2Drv);

   DIOHAL_vidWrite(CH_DIO_OUT_CTP_2, bLocalAdHeatCmd_bAcvCTP2Drv);
}
/*-------------------------------- end of file -------------------------------*/