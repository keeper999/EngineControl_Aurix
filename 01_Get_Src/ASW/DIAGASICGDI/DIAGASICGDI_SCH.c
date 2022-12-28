/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGASICGDI                                             */
/* !Description     : DIAGASICGDI component                                   */
/*                                                                            */
/* !Module          : DIAGASICGDI                                             */
/* !Description     : DIAGNOSTIC DE L’ASIC GDI                                */
/*                                                                            */
/* !File            : DIAGASICGDI_SCH.C                                       */
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
/*   1 / ASIC_EveRst_diagasicgdi                                              */
/*   2 / ASIC_SdlFast_diagasicgdi                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6930924 / 01                                        */
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
#include "DIAGASICGDI.h"
#include "DIAGASICGDI_L.h"
#include "DIAGASICGDI_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ASIC_EveRst_diagasicgdi                                    */
/* !Description :  Evenement Reset pour le diagnostic de l'Asic Gdi           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGASICGDI_vidDiag_ASICGDI();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Ext_bDgoAsicGdiFailure;                                     */
/*  input boolean Ext_bMonRunAsicGdiFailure;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ASIC_EveRst_diagasicgdi(void)
{
   DIAGASICGDI_vidDiag_ASICGDI();
   GDGAR_vidGdu(GD_DFT_ASICGDIFAILURE,
                Ext_bDgoAsicGdiFailure,
                Ext_bMonRunAsicGdiFailure,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ASIC_SdlFast_diagasicgdi                                   */
/* !Description :  Moniteur rapide pour le diagnostic ASIC GDI                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  M.Boubakri                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGASICGDI_vidDiag_ASICGDI();                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 DIAGASICGDI_u8Inhib;                                          */
/*  input boolean Ext_bDgoAsicGdiFailure;                                     */
/*  input boolean Ext_bMonRunAsicGdiFailure;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ASIC_SdlFast_diagasicgdi(void)
{
   if (DIAGASICGDI_u8Inhib != 0x5A)
   {
      DIAGASICGDI_vidDiag_ASICGDI();
      GDGAR_vidGdu(GD_DFT_ASICGDIFAILURE,
                   Ext_bDgoAsicGdiFailure,
                   Ext_bMonRunAsicGdiFailure,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/