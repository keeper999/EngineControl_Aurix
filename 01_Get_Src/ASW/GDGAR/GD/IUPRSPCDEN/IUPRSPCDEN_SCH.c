/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRSPCDEN                                              */
/* !Description     : IUPRSPCDEN Component                                    */
/*                                                                            */
/* !Module          : IUPRSPCDEN                                              */
/* !Description     : IUPRSPCDENORISATION DES PARAMETRES DEFAUTS              */
/*                                                                            */
/* !File            : IUPRSPCDEN_SCH.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IuprSpcDen_EveRst                                                    */
/*   2 / IuprSpcDen_GlbDCStrt                                                 */
/*   3 / IuprSpcDen_SdlSlow                                                   */
/*                                                                            */
/* !Reference   : V02 NT 11 03254 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRSPCDEN/IUPRSPCDEN_SCH.C_v$*/
/* $Revision::   1.3      $$Author::   alaouni        $$Date::   28 Mar 2012 $*/
/* $Author::   alaouni                                $$Date::   28 Mar 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "IUPRSPCDEN.h"
#include "IUPRSPCDEN_L.h"
#include "IUPRSPCDEN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IuprSpcDen_EveRst                                          */
/* !Description :  Fonction appelée à l'initialisation du calculateur.        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRSPCDEN_vidF01_Ini();                                 */
/*  extf argret void IUPRSPCDEN_vidInternalValueInit();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IuprSpcDen_EveRst                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IuprSpcDen_EveRst(void)
{
   IUPRSPCDEN_vidF01_Ini();
   IUPRSPCDEN_vidInternalValueInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IuprSpcDen_GlbDCStrt                                       */
/* !Description :  Fonction appelée lors de la réinitialisation lors d'un     */
/*                 nouveau DC global.                                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRSPCDEN_vidF01_Ini();                                 */
/*  extf argret void IUPRSPCDEN_vidF02_ColdStrtCdn();                         */
/*  input uint8 IUPRSPCDEN_u8Inhib;                                           */
/*  output boolean IUPRSPCDEN_UpdateDenomOkPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IuprSpcDen_GlbDCStrt                                           */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IuprSpcDen_GlbDCStrt(void)
{
   if( 0x5A != IUPRSPCDEN_u8Inhib )
   {
      IUPRSPCDEN_vidF01_Ini();
      IUPRSPCDEN_vidF02_ColdStrtCdn();
      IUPRSPCDEN_UpdateDenomOkPrev = 1;
   }
   else
   {
      /* Do Nothing */
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IuprSpcDen_SdlSlow                                         */
/* !Description :  Calcul des conditions d'incrémentation des dénominateurs   */
/*                 spécifiques à la récurrence du moniteur lent de la fonction*/
/*                 GD                                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IUPRSPCDEN_vidF03_ClcnIncCdn();                          */
/*  input uint8 IUPRSPCDEN_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IuprSpcDen_SdlSlow                                             */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IuprSpcDen_SdlSlow(void)
{
   if( 0x5A != IUPRSPCDEN_u8Inhib )
   {
      IUPRSPCDEN_vidF03_ClcnIncCdn();
   }
   else
   {
      /* Do Nothing */
   }
}
/*------------------------------- end of file --------------------------------*/