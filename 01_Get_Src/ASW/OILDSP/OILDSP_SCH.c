/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILDSP                                                  */
/* !Description     : OILDSP Component                                        */
/*                                                                            */
/* !Module          : OILDSP                                                  */
/* !Description     :  FUEL DESORPTION FROM OIL                               */
/*                                                                            */
/* !File            : OILDSP_SCH.C                                            */
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
/*   1 / OilSys_EveRst_OilDsp                                                 */
/*   2 / OilSys_EveTDC_OilDsp                                                 */
/*   3 / OilSys_SdlMid_OilDsp                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5377698 / 03                                        */
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
#include "OILDSP.h"
#include "OILDSP_L.h"
#include "OILDSP_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSys_EveRst_OilDsp                                       */
/* !Description :  Reset event.                                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  PTS_R_5377698_001.01                                       */
/*                 PTS_R_5377698_002.01                                       */
/*                 PTS_R_5377698_003.01                                       */
/*                 PTS_R_5377698_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILDSP_vidInit();                                        */
/*  extf argret void OILDSP_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSys_EveRst_OilDsp                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSys_EveRst_OilDsp(void)
{
   OILDSP_vidInit();
   OILDSP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSys_EveTDC_OilDsp                                       */
/* !Description :  TDC event (Top Dead Center)                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  PTS_R_5377698_004.01                                       */
/*                 PTS_R_5377698_003.01                                       */
/*                 PTS_R_5377698_002.01                                       */
/*                 PTS_R_5377698_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILDSP_vidAbsorption();                                  */
/*  input uint8 OILDSP_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSys_EveTDC_OilDsp                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSys_EveTDC_OilDsp(void)
{
   if (OILDSP_u8Inhib != 0x5A)
   {
      OILDSP_vidAbsorption();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSys_SdlMid_OilDsp                                       */
/* !Description :  Middle scheduler.                                          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  PTS_R_5377698_004.01                                       */
/*                 PTS_R_5377698_003.01                                       */
/*                 PTS_R_5377698_002.01                                       */
/*                 PTS_R_5377698_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILDSP_vidDesorption();                                  */
/*  extf argret void OILDSP_vidDisableAFACanister();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 OILDSP_u8Inhib;                                               */
/*  input boolean OilDsp_bMonRunIdcBlbyCnd;                                   */
/*  input boolean OilDsp_bDgoIdcBlbyCnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSys_SdlMid_OilDsp                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSys_SdlMid_OilDsp(void)
{
   if (OILDSP_u8Inhib != 0x5A)
   {
      OILDSP_vidDesorption();
      if (OilDsp_bMonRunIdcBlbyCnd != 0)
      {
         OILDSP_vidDisableAFACanister();
      }
      GDGAR_vidGdu(GD_DFT_IDCBLBYCND,
                   OilDsp_bDgoIdcBlbyCnd,
                   OilDsp_bMonRunIdcBlbyCnd,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/