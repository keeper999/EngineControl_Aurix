/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GOBD                                                    */
/* !Description     : GOBD Component                                          */
/*                                                                            */
/* !Module          : GOBD                                                    */
/* !Description     : Gestionnaire OBD                                        */
/*                                                                            */
/* !File            : GOBD_FCT1.C                                             */
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
/*   1 / GOBD_vidInit                                                         */
/*   2 / GOBD_vidSetKeyOBD                                                    */
/*   3 / GOBD_vidRstKeyOBD                                                    */
/*   4 / GOBD_vidWriteCntAcv                                                  */
/*   5 / GOBD_vidTiSinceEngStrt                                               */
/*   6 / GOBD_vidInitTiSinceEngStrt                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5075502 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GOBD/GOBD_FCT1.c_v           $*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   11 Feb 2014 $*/
/* $Author::   mbenfrad                               $$Date::   11 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GOBD.h"
#include "GOBD_L.h"
#include "GOBD_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidInit                                               */
/* !Description :  Initialize the GOBD module parameters.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean GOBD_bMemRg;                                               */
/*  output boolean GOBD_bKeyOBD;                                              */
/*  output boolean Ns_bCntAcv;                                                */
/*  output uint16 GOBD_tiSinceEngStrt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidInit(void)
{
   GOBD_bMemRg = FALSE;
   GOBD_bKeyOBD = FALSE;
   Ns_bCntAcv = FALSE;
   GOBD_tiSinceEngStrt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidSetKeyOBD                                          */
/* !Description :  This function generate the information "CONTACT OBD" and   */
/*                 modified some data.                                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean GOBD_bKeyOBD;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidSetKeyOBD(void)
{
   GOBD_bKeyOBD = TRUE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidRstKeyOBD                                          */
/* !Description :  Set the parameter GOBD_bKeyOBD to FALSE.                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean GOBD_bKeyOBD;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidRstKeyOBD(void)
{
   GOBD_bKeyOBD = FALSE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidWriteCntAcv                                        */
/* !Description :  Write the value give in argument to Ns_bCntAcv.            */
/*                 (F04_F02_RstCntAcv and F04_F01_SetCntAcv)                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Ns_bCntAcv;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidWriteCntAcv
(
   boolean bValue
)
{
   Ns_bCntAcv = bValue;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidTiSinceEngStrt                                     */
/* !Description :  Manage the time's meter since the engine starts.           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Ns_bCntAcv;                                                 */
/*  input uint16 GOBD_tiSinceEngStrt;                                         */
/*  output uint16 GOBD_tiSinceEngStrt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidTiSinceEngStrt(void)
{
   if(Ns_bCntAcv == TRUE)
   {
      if(GOBD_tiSinceEngStrt < (uint16)(UINT16_VAL_MAX - 1))
      {
         GOBD_tiSinceEngStrt =
                        (uint16)(GOBD_tiSinceEngStrt + 1);
      }
      else
      {
         GOBD_tiSinceEngStrt = UINT16_VAL_MAX;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidInitTiSinceEngStrt                                 */
/* !Description :  reset the data GOBD_vidInitTiSinceEngStrt.                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 GOBD_tiSinceEngStrt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidInitTiSinceEngStrt(void)
{
   GOBD_tiSinceEngStrt = 0;
}
/*------------------------------- end of file --------------------------------*/