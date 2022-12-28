/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GMIL                                                    */
/* !Description     : GMIL Component                                          */
/*                                                                            */
/* !Module          : GMIL                                                    */
/* !Description     : GESTIONNAIRE DE LA LAMPE DEFAUT                         */
/*                                                                            */
/* !File            : GMIL_SCH.C                                              */
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
/*   1 / GMIL_vidMngEveSldSlow                                                */
/*   2 / GMIL_vidMngEveKeyOBD                                                 */
/*   3 / GMIL_vidMngEveRst                                                    */
/*                                                                            */
/* !Reference   : V02 NT 10 04661 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GMIL/GMIL_sch.c_v            $*/
/* $Revision::   1.2      $$Author::   alaouni        $$Date::   23 Nov 2011 $*/
/* $Author::   alaouni                                $$Date::   23 Nov 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "GMIL.h"
#include "GMIL_L.h"
#include "GMIL_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_vidMngEveSldSlow                                      */
/* !Description :  Moniteur lent associé au module GMIL                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_10_04661_001.01                                     */
/*                 VEMS_E_10_04661_002.01                                     */
/*                 VEMS_E_10_04661_003.01                                     */
/*                 VEMS_E_10_04661_004.01                                     */
/*                 VEMS_E_10_04661_005.01                                     */
/*                 VEMS_E_10_04661_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GMIL_StrtMng();                                          */
/*  extf argret void GMIL_DftAndWarnSt();                                     */
/*  extf argret void GMIL_Req(argin uint8 u8Event);                           */
/*  extf argret void GMIL_MilReqCanConf();                                    */
/*  extf argret void GMIL_DftSt();                                            */
/*  input uint8 GMIL_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : GMIL_vidMngEveSldSlow                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_vidMngEveSldSlow(void)
{
   if(GMIL_u8Inhib != 0x5A)
   {
      /* Management of the MIL before startup */
      GMIL_StrtMng();

      /* function lighting the MIL in case of defects type OBD */
      GMIL_DftAndWarnSt();

      /* automatic summarizing all requests from the previous blocks
         and variable product demand of start of the MIL */
      GMIL_Req(GMIL_EVE_SLOW);

      /* this block used to create 2 Boolean GMIL_bMilOn and MIL_bMilBlink
         to be sent to the Can via frame 348 */
      GMIL_MilReqCanConf();

      /* this machine produced from blocks requests from the previous variable
         whether the lighting of the MIL is linked or not a failure */
      GMIL_DftSt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_vidMngEveKeyOBD                                       */
/* !Description :  Evènement représentant le front montant de l'information   */
/*                 CONTACT_OBD                                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_10_04661_001.01                                     */
/*                 VEMS_E_10_04661_002.01                                     */
/*                 VEMS_E_10_04661_003.01                                     */
/*                 VEMS_E_10_04661_004.01                                     */
/*                 VEMS_E_10_04661_005.01                                     */
/*                 VEMS_E_10_04661_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GMIL_StrtCntIni();                                       */
/*  extf argret void GMIL_Req(argin uint8 u8Event);                           */
/*  extf argret void GMIL_MilReqCanConf();                                    */
/*  input uint8 GMIL_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : GMIL_vidMngEveKeyOBD                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_vidMngEveKeyOBD(void)
{
   if(GMIL_u8Inhib != 0x5A)
   {
      /* This feature allows to initialize variables on the event GD_EveKeyOBD*/
      GMIL_StrtCntIni();

      /* automatic summarizing all requests from the previous blocks
         and variable product demand of start of the MIL */
      GMIL_Req(GMIL_EVE_SLOW);

      /* this block used to create 2 Boolean GMIL_bMilOn and MIL_bMilBlink
         to be sent to the Can via frame 348 */
      GMIL_MilReqCanConf();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GMIL_vidMngEveRst                                          */
/* !Description :  Evènement Reset CMM                                        */
/* !Number      :  SCH.3                                                      */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_10_04661_001.01                                     */
/*                 VEMS_E_10_04661_002.01                                     */
/*                 VEMS_E_10_04661_003.01                                     */
/*                 VEMS_E_10_04661_004.01                                     */
/*                 VEMS_E_10_04661_005.01                                     */
/*                 VEMS_E_10_04661_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GMIL_vidInitOutput();                                    */
/*  extf argret void GMIL_Init();                                             */
/*  extf argret void GMIL_Req(argin uint8 u8Event);                           */
/*  extf argret void GMIL_MilReqCanConf();                                    */
/*  extf argret void GMIL_DftSt();                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : GMIL_vidMngEveRst                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GMIL_vidMngEveRst(void)
{
   /* Initialization of remaining Outputs */
   GMIL_vidInitOutput();

   /* Reading in EEPROM and initialization of variables and temporal odometer */
   GMIL_Init();

   /* automatic summarizing all requests from the previous blocks
      and variable product demand of start of the MIL */
   GMIL_Req(GMIL_EVE_RST);

    /* this block used to create 2 Boolean GMIL_bMilOn and MIL_bMilBlink
      to be sent to the Can via frame 348 */
   GMIL_MilReqCanConf();

   /* this machine produced from blocks requests from the previous variable
      whether the lighting of the MIL is linked or not a failure */
   GMIL_DftSt();
}
/*------------------------------- end of file --------------------------------*/