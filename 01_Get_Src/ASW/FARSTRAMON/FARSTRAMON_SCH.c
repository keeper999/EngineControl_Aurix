/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FARSTRAMON                                              */
/* !Description     : FARSTRAMON component                                    */
/*                                                                            */
/* !Module          : FARSTRAMON                                              */
/* !Description     : Superviseur de stratégies liées à la Richesse           */
/*                                                                            */
/* !File            : FARSTRAMON_SCH.C                                        */
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
/*   1 / StraMon_EveRst_FarStraMon                                            */
/*   2 / StraMon_SdlMid_FarStraMon                                            */
/*   3 / StraMon_EveCrTR_FarStraMon                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5147156 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/FARSTRAMON/FARSTRAMON_$*/
/* $Revision::   1.5      $$Author::   HHAMLAOU       $$Date::   20 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "FARSTRAMON.h"
#include "FARSTRAMON_L.h"
#include "FARSTRAMON_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  StraMon_EveRst_FarStraMon                                  */
/* !Description :  Fonction Reset calculateur                                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_00524_005.01                                     */
/*                 VEMS_E_10_00524_006.01                                     */
/*                 VEMS_E_10_00524_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FARSTRAMON_vidInitOutput();                              */
/*  extf argret void FARSTRAMON_vidIninTmrEnaPurgEng();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : StraMon_EveRst_FarStraMon                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void StraMon_EveRst_FarStraMon(void)
{
   FARSTRAMON_vidInitOutput();
   FARSTRAMON_vidIninTmrEnaPurgEng();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  StraMon_SdlMid_FarStraMon                                  */
/* !Description :  Fonction du Moniteur moyen de la fonction Cstr             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_00524_005.01                                     */
/*                 VEMS_E_10_00524_006.01                                     */
/*                 VEMS_E_10_00524_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FARSTRAMON_vidFiltration();                              */
/*  extf argret void FARSTRAMON_vidReqClsPurg();                              */
/*  extf argret void FARSTRAMON_vidEGREffect();                               */
/*  extf argret void FARSTRAMON_vidEnableManagement();                        */
/*  extf argret void FARSTRAMON_vidTmrEnaPurgEng();                           */
/*  input uint8 FARSTRAMON_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : StraMon_SdlMid_FarStraMon                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void StraMon_SdlMid_FarStraMon(void)
{
   if (FARSTRAMON_u8Inhib != 0x5A)
   {
      FARSTRAMON_vidFiltration();
      FARSTRAMON_vidReqClsPurg ();
      FARSTRAMON_vidEGREffect();
      FARSTRAMON_vidEnableManagement();
      FARSTRAMON_vidTmrEnaPurgEng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  StraMon_EveCrTR_FarStraMon                                 */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_00524_005.01                                     */
/*                 VEMS_E_10_00524_006.01                                     */
/*                 VEMS_E_10_00524_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FARSTRAMON_vidIninTmrEnaPurgEng();                       */
/*  input uint8 FARSTRAMON_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : StraMon_EveCrTR_FarStraMon                                     */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void StraMon_EveCrTR_FarStraMon(void)
{
   if (FARSTRAMON_u8Inhib != 0x5A)
   {
      FARSTRAMON_vidIninTmrEnaPurgEng();
   }
}

/*------------------------------- end of file --------------------------------*/