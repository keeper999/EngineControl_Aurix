/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTHRARCRKSP                                           */
/* !Description     : AIRTHRARCRKSP component                                 */
/*                                                                            */
/* !Module          : AIRTHRARCRKSP                                           */
/* !Description     : CALCUL DE LA CONSIGNE D’AIRE PAPILLON HORS STRUCTURE    */
/*                    COUPLE                                                  */
/*                                                                            */
/* !File            : AIRTHRARCRKSP_SCH.c                                     */
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
/*   1 / AIRTHRARCRKSP_vidEntryInit                                           */
/*   2 / CrkMgt_SdlMid_AirThrArCrkSp                                          */
/*   3 / CrkMgt_SdlFast_AirThrArCrkSp                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5074571 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/AIRTHRARCRKSP/AIRTHRARCRKSP_SCH.C_$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   04 Nov 2013 $*/
/* $Author::   wbouach                                $$Date::   04 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

 #include "STD_TYPES.H"
 #include "AIRTHRARCRKSP.H"
 #include "AIRTHRARCRKSP_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTHRARCRKSP_vidEntryInit                                 */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_04622_001.02                                     */
/*                 PTS_R_507471_001.01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTHRARCRKSP_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  AIRTHRARCRKSP_vidEntryInit                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTHRARCRKSP_vidEntryInit(void)
{
   AIRTHRARCRKSP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_SdlMid_AirThrArCrkSp                                */
/* !Description :  moniteur moyen pour le calcul  de la condigne d'air        */
/*                 papillon.                                                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_04622_001.02                                     */
/*                 PTS_R_507471_001.01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTHRARCRKSP_vidCompAirDenGain();                       */
/*  extf argret void AIRTHRARCRKSP_vidCompDtcFiCraOff();                      */
/*  input uint8 AIRTHRARCRKSP_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_SdlMid_AirThrArCrkSp                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_SdlMid_AirThrArCrkSp(void)
{
   if(AIRTHRARCRKSP_u8Inhib != 0x5A)
   {
      AIRTHRARCRKSP_vidCompAirDenGain();
      AIRTHRARCRKSP_vidCompDtcFiCraOff();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrkMgt_SdlFast_AirThrArCrkSp                               */
/* !Description :  moniteur rapide pour le calcul  de la consigne d'air       */
/*                 papillon.                                                  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_04622_001.02                                     */
/*                 PTS_R_507471_001.01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTHRARCRKSP_vidCalcTqLoss();                           */
/*  extf argret void AIRTHRARCRKSP_vidCompDtcTrCoSurf();                      */
/*  extf argret void AIRTHRARCRKSP_vidCompDtcSection();                       */
/*  input uint8 AIRTHRARCRKSP_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CrkMgt_SdlFast_AirThrArCrkSp                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrkMgt_SdlFast_AirThrArCrkSp(void)
{
   if(AIRTHRARCRKSP_u8Inhib != 0x5A)
   {
      AIRTHRARCRKSP_vidCalcTqLoss();
      AIRTHRARCRKSP_vidCompDtcTrCoSurf();
      AIRTHRARCRKSP_vidCompDtcSection();
   }
}

/*------------------------------- end of file --------------------------------*/