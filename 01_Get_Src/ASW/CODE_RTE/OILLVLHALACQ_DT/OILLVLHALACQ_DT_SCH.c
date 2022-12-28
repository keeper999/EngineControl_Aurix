/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILLVLHALACQ_DT                                         */
/* !Description     : OILLVLHALACQ_DT Component                               */
/*                                                                            */
/* !Module          : OILLVLHALACQ_DT                                         */
/* !Description     : OILLVHAL acquisition                                    */
/*                                                                            */
/* !File            : OILLVLHALACQ_DT_SCH.C                                   */
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
/*   1 / OILLVLHALACQ_DT_vidEntryInit                                         */
/*   2 / Oil_EveOilLvl_OilLvlHalAcq                                           */
/*   3 / Oil_SdlFast_OilLvlHalAcq                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6873713 / 01                                        */
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
#include "OILLVLHALACQ_DT.h"
#include "OILLVLHALACQ_DT_L.h"
#include "OILLVLHALACQ_DT_IM.h"
#include "OILLVLHALACQ_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLHALACQ_DT_vidEntryInit                               */
/* !Description :  Reset Event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVLHALACQ_DT_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : OILLVLHALACQ_DT_vidEntryInit                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLHALACQ_DT_vidEntryInit(void)
{
   OILLVLHALACQ_DT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveOilLvl_OilLvlHalAcq                                 */
/* !Description :  Event created by LDB to call the API                       */
/*                 OILLVHAL_udtGetConversionResult                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVLHALACQ_DT_vidLvlAcq();                             */
/*  input uint8 OILLVLHALACQ_DT_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Oil_EveOilLvl_OilLvlHalAcq                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveOilLvl_OilLvlHalAcq(void)
{
   if (OILLVLHALACQ_DT_u8Inhib != 0x5A)
   {
      OILLVLHALACQ_DT_vidLvlAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlFast_OilLvlHalAcq                                   */
/* !Description :  Fast scheduler                                             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILLVLHALACQ_DT_vidCdnLvlAcq();                          */
/*  input uint8 OILLVLHALACQ_DT_u8Inhib;                                      */
/*  input boolean UCE_bPwrlAcv;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Oil_SdlFast_OilLvlHalAcq                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlFast_OilLvlHalAcq(void)
{
   boolean bLocalUCE_bPwrlAcv;


   if (OILLVLHALACQ_DT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
      if (bLocalUCE_bPwrlAcv == 0)
      {
         OILLVLHALACQ_DT_vidCdnLvlAcq();
      }
   }
}
/*-------------------------------- end of file -------------------------------*/