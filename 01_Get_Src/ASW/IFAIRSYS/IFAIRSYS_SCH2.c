/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYS                                                */
/* !Description     : IFAIRSYS Component                                      */
/*                                                                            */
/* !Module          : IFAIRSYS                                                */
/* !Description     : INTERFACE DE LA CHAINE D AIR                            */
/*                                                                            */
/* !File            : IFAIRSYS_SCH2.C                                         */
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
/*   1 / AirSys_SdlFast_nEngGrdIf                                             */
/*   2 / EngSt_SdlFast_EngrunStIfAir                                          */
/*   3 / EngSt_EveRst_EngrunStIfAir                                           */
/*   4 / CrkMgt_EveRst_AirTqStructMngtIf                                      */
/*   5 / Crkmgt_sdlFast_tqStructMngtIf                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5199971 / 07                                        */
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
#include "IFAIRSYS.h"
#include "IFAIRSYS_L.h"
#include "IFAIRSYS_IM.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirSys_SdlFast_nEngGrdIf                                   */
/* !Description :  Scheduleur rapide de l'interfaçage du module AirSys.       */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidNEngGrd();                                   */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_CkMngIfIfAir                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirSys_SdlFast_nEngGrdIf(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidNEngGrd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_EngrunStIfAir                                */
/* !Description :  Moniteur Rapide de la fonction EngSt                       */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidEngSt();                                     */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_EngrunStIfAir                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_EngrunStIfAir(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidEngSt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngrunStIfAir                                 */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidEngSt();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngrunStIfAir                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngrunStIfAir(void)
{
   IFAIRSYS_vidEngSt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_EveRst_AirTqStructMngtIf                            */
/* !Description :  evènement Reset.                                           */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidInitCrkMgt();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_EveRst_AirTqStructMngtIf                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_EveRst_AirTqStructMngtIf(void)
{
   IFAIRSYS_vidInitCrkMgt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Crkmgt_sdlFast_tqStructMngtIf                              */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidCrkMgt2();                                   */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Crkmgt_sdlFast_tqStructMngtIf                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Crkmgt_sdlFast_tqStructMngtIf(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidCrkMgt2();
   }
}
/*-------------------------------- end of file -------------------------------*/