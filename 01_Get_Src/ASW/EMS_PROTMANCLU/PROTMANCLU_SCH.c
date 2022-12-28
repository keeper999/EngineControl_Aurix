/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTMANCLU                                              */
/* !Description     : PROTMANCLU Component                                    */
/*                                                                            */
/* !Module          : PROTMANCLU                                              */
/* !Description     : Clutch protection for manual gearbox                    */
/*                                                                            */
/* !File            : PROTMANCLU_SCH.C                                        */
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
/*   1 / PROTMANCLU_vidEntryInit                                              */
/*   2 / TqSys_Sdl40ms_ProtManClu                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 04687 / 01                                        */
/* !OtherRefs   : 01460_10_03770/1.1                                          */
/* !OtherRefs   : VEMS V02 ECU#056597                                         */
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
#include "PROTMANCLU.h"
#include "PROTMANCLU_l.h"
#include "PROTMANCLU_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEntryInit                                    */
/* !Description :  Initialization function.                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PROTMANCLU_vidEntryInit                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEntryInit(void)
{
   PROTMANCLU_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl40ms_ProtManClu                                   */
/* !Description :  Event 40ms of the function .                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidClutch_Protection();                       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 PROTMANCLU_u8Inhib;                                           */
/*  input boolean CoPt_bDgoCluDmgAfts;                                        */
/*  input boolean CoPt_bMonRunCluDmgAfts;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl40ms_ProtManClu                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl40ms_ProtManClu(void)
{
   boolean bLocalbDgoCluDmgAfts;
   boolean bLocalbMonRunCluDmgAfts;


   if (PROTMANCLU_u8Inhib != 0x5A)
   {
      PROTMANCLU_vidClutch_Protection();
      VEMS_vidGET(CoPt_bDgoCluDmgAfts, bLocalbDgoCluDmgAfts);
      VEMS_vidGET(CoPt_bMonRunCluDmgAfts, bLocalbMonRunCluDmgAfts);
      GDGAR_vidGdu(GD_DFT_CLUDMGAFTS,
                   bLocalbDgoCluDmgAfts,
                   bLocalbMonRunCluDmgAfts ,
                   DIAG_DISPO);
   }
}

/*---------------------------------End Of File--------------------------------*/