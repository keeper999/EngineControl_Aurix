/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ECUMNG                                                  */
/* !Description     : ECUMNG component                                        */
/*                                                                            */
/* !Module          : ECUMNG                                                  */
/* !Description     : ETAT ELECTRIQUE DU CALCULATEUR                          */
/*                                                                            */
/* !File            : ecumng_fct3.c                                           */
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
/*   1 / ECUMNG_vidbisAcvDiagHotRst                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6642215 / 05                                        */
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

#include "ECUMNG.h"
#include "ECUMNG_L.h"
#include "ECUMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ECUMNG_vidbisAcvDiagHotRst                                 */
/* !Description :  When a hot reset is detected (hot reset = software reset or*/
/*                 hardware reset) the EcuSt_bDgoHotRst flag is  validated.   */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  anaji                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean First_crank;                                                */
/*  input boolean EcuSt_bDetHotRst;                                           */
/*  input boolean EcuSt_bInhFirstCrank_C;                                     */
/*  input boolean ECUMNG_bAcv_Diag_Hot_Rst;                                   */
/*  output boolean EcuSt_bMonRunHotRst;                                       */
/*  output boolean EcuSt_bDgoHotRst;                                          */
/*  output boolean ECUMNG_bAcv_Diag_Hot_Rst;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ECUMNG_vidbisAcvDiagHotRst(void)
{
   boolean bLocalFirst_crank;
   boolean bLocalEcuSt_bDetHotRst;

   VEMS_vidGET(First_crank, bLocalFirst_crank);
   VEMS_vidGET(EcuSt_bDetHotRst, bLocalEcuSt_bDetHotRst);

   if (  (  (EcuSt_bInhFirstCrank_C != 0)
         || (bLocalFirst_crank == 0))
      && (ECUMNG_bAcv_Diag_Hot_Rst == 0))
   {
      EcuSt_bMonRunHotRst = 1;
   }
   else
   {
      EcuSt_bMonRunHotRst = 0;
   }

   EcuSt_bDgoHotRst = bLocalEcuSt_bDetHotRst;

   ECUMNG_bAcv_Diag_Hot_Rst = 1;
}

/*------------------------------- end of file --------------------------------*/