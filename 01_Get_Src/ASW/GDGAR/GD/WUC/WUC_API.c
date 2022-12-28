/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WUC                                                     */
/* !Description     : WUC Component                                           */
/*                                                                            */
/* !Module          : WUC                                                     */
/* !Description     : WARM UP CYCLE                                           */
/*                                                                            */
/* !File            : WUC_API.C                                               */
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
/*   1 / WUC_vidMngEveGlobDCStrt                                              */
/*   2 / WUC_vidMngEvePrmClrAftsScanTool                                      */
/*   3 / WUC_vidMngEvePrmClrAfts                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 04191 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/GDGAR/WUC/WUC_API.c_v             $*/
/* $Revision::   1.3      $$Author::   sbiet          $$Date::   06 Jul 2009 $*/
/* $Author::   sbiet                                  $$Date::   06 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "WUC.h"
#include "WUC_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidMngEveGlobDCStrt                                    */
/* !Description :  API calls on the event Global DC start (New global DC).    */
/*                 Launch all actions which must be done by the module on the */
/*                 event.                                                     */
/* !Number      :  API.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WUC_vidF02_tCoRefFrz();                                  */
/*  input uint8 WUC_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidMngEveGlobDCStrt(void)
{
   if(WUC_u8Inhib != 0x5A)
   {
      WUC_vidF02_tCoRefFrz ();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidMngEvePrmClrAftsScanTool                            */
/* !Description :  API calls on the event clear prm (erasure default request) */
/*                 from a afts scan tools. Launch all actions which must be   */
/*                 done by the module on the event.                           */
/* !Number      :  API.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WUC_vidF05_WupPrmClrTool();                              */
/*  input uint8 WUC_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidMngEvePrmClrAftsScanTool(void)
{
   if(WUC_u8Inhib != 0x5A)
   {
      WUC_vidF05_WupPrmClrTool ();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidMngEvePrmClrAfts                                    */
/* !Description :  API calls on the event clear prm (erasure default request) */
/*                 from a afts. Launch all actions which must be done by the  */
/*                 module on the event.                                       */
/* !Number      :  API.3                                                      */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WUC_vidF05_WupPrmClrTool();                              */
/*  input uint8 WUC_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidMngEvePrmClrAfts(void)
{
   if(WUC_u8Inhib != 0x5A)
   {
      WUC_vidF05_WupPrmClrTool ();
   }
}
