/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCOMON                                                 */
/* !Description     : TQCOMON Component.                                      */
/*                                                                            */
/* !Module          : TQCOMON                                                 */
/* !Description     : Safety TMS : Coordonner les Couples.                    */
/*                                                                            */
/* !File            : TQCOMON_SCH.C                                           */
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
/*   1 / TQCOMON_vidEntryInit                                                 */
/*   2 / SftyMgt_SdlMid_tqCoVSCtl                                             */
/*   3 / SftyMgt_SdlMid_tqEfcFilCo                                            */
/*   4 / SftyMgt_SdlMid_tqEfcReqCoCha                                         */
/*   5 / SftyMgt_SdlMid_tqEfcCoGBx                                            */
/*   6 / SftyMgt_SdlMid_tqIdcCoGBx                                            */
/*   7 / SftyMgt_SdlMid_tqIdcCoNReg                                           */
/*   8 / SftyMgt_SdlMid_tqIdcEngLimCo                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 01231 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#062959                                         */
/* !OtherRefs   : CSCT_CGMT09_1791 / 1.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMON/TQCOMON_SCH.C_$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCOMON.h"
#include "TQCOMON_L.h"
#include "TQCOMON_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMON_vidEntryInit                                       */
/* !Description :  Accroche moniteur pour la fonction Reset de calculateur    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCOMON_vidEntryInit                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMON_vidEntryInit(void)
{
   TQCOMON_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqCoVSCtl                                   */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqCoVSCtl.     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidCoordonner_XVV();                             */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqCoVSCtl                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqCoVSCtl(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidCoordonner_XVV();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqEfcFilCo                                  */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqEfcFilCo.    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidCoordonner_Agrement();                        */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqEfcFilCo                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqEfcFilCo(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidCoordonner_Agrement();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqEfcReqCoCha                               */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqEfcReqCoCha. */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidCoordonner_Couple_ESP();                      */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqEfcReqCoCha                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqEfcReqCoCha(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidCoordonner_Couple_ESP();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqEfcCoGBx                                  */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqEfcCoGBx.    */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidCoordonner_Couple_BV();                       */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqEfcCoGBx                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqEfcCoGBx(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidCoordonner_Couple_BV();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqIdcCoGBx                                  */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqIdcCoGBx.    */
/* !Number      :  SCH.6                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidConversion_CME_CMI();                         */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqIdcCoGBx                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqIdcCoGBx(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidConversion_CME_CMI();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqIdcCoNReg                                 */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqIdcCoNReg.   */
/* !Number      :  SCH.7                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidCoordRelanceRegimeBV();                       */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCOMON_vidCoordRelanceRegimeBV                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqIdcCoNReg(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidCoordRelanceRegimeBV();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_tqIdcEngLimCo                               */
/* !Description :  Fonction d'accroche moniteur SftyMgt_SdlMid_tqIdcEngLimCo. */
/* !Number      :  SCH.8                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01231_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCOMON_vidCoordonnerLimRalenti();                       */
/*  input uint8 TQCOMON_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_tqIdcEngLimCo                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_tqIdcEngLimCo(void)
{
   if (TQCOMON_u8Inhib != 0x5A)
   {
      TQCOMON_vidCoordonnerLimRalenti();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/