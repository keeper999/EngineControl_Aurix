/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCKEFCFIL                                              */
/* !Description     : TQCKEFCFIL Component                                    */
/*                                                                            */
/* !Module          : TQCKEFCFIL                                              */
/* !Description     : SAFETY TMS : VALIDER AGRÉMENT PRÉVENTIF                 */
/*                                                                            */
/* !File            : TQCKEFCFIL_SCH.C                                        */
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
/*   1 / TQCKEFCFIL_vidEntryInit                                              */
/*   2 / SftyMgt_SdlMid_tqCkEfcFil                                            */
/*                                                                            */
/* !Reference   : V02 NT 10 01236 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#056922                                         */
/* !OtherRefs   : CSCT_CGMT09_2398 / 2.6                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKEFCFIL/TQCKEFCFIL_$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCKEFCFIL.h"
#include "TQCKEFCFIL_L.h"
#include "TQCKEFCFIL_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidEntryInit                                    */
/* !Description :  Evenement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_001.02                                     */
/*                 VEMS_R_10_01236_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCKEFCFIL_vidEntryInit                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidEntryInit(void)
{
   TQCKEFCFIL_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqCkEfcFil                                  */
/* !Description :  Evennement de déclenchement de la fonction qui décrit l'   */
/*                 enveloppe max simplifiée de la partie applicative et la    */
/*                 fonction de validation des signaux de la partie applicative*/
/*                  préventif                                                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_001.02                                     */
/*                 VEMS_R_10_01236_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidCalculEstimation();                        */
/*  extf argret void TQCKEFCFIL_vidValidation();                              */
/*  input uint8 TQCKEFCFIL_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqCkEfcFil                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqCkEfcFil(void)
{
   if (TQCKEFCFIL_u8Inhib != 0x5A)
   {
      TQCKEFCFIL_vidCalculEstimation();
      TQCKEFCFIL_vidValidation();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/