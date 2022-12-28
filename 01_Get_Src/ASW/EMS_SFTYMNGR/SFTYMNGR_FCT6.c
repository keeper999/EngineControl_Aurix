/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMNGR                                                */
/* !Description     : SFTYMNGR Component                                      */
/*                                                                            */
/* !Module          : SFTYMNGR                                                */
/* !Description     : SAFETY TMS :SAFETY MANAGER                              */
/*                                                                            */
/* !File            : SFTYMNGR_FCT6.C                                         */
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
/*   1 / SFTYMNGR_vidDetDftPresentInit                                        */
/*   2 / SFTYMNGR_vidMergeTrameCtxtGD                                         */
/*   3 / SFTYMNGR_vidTrmCtxtVrGDInit                                          */
/*   4 / SFTYMNGR_vidTrmCtxtVrGDDefaut                                        */
/*   5 / SFTYMNGR_vidEnFormeContexteGD                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_FCT6$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SFTYMNGR.h"
#include "SFTYMNGR_l.h"
#include "SFTYMNGR_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidDetDftPresentInit                              */
/* !Description :  Detection d’un défaut présent à l’initialisation de la     */
/*                 fonction                                                   */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_053.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bPresentInitVar;                                    */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input boolean SftyMgt_bEveDftWrMem;                                       */
/*  output boolean SftyMgt_bDgoIni;                                           */
/*  output boolean SftyMgt_bEveIniEna;                                        */
/*  output boolean SftyMgt_bEveIniDftWrMemEna;                                */
/*  output boolean SftyMgt_bPresentInitVar;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidDetDftPresentInit(void)
{
   uint8 u8LocalSftyMgt_ctDftLadd;


   if (SftyMgt_bPresentInitVar == 0)
   {
      SftyMgt_bDgoIni = 0;
      SftyMgt_bEveIniEna = 0;
   }
   else
   {
      VEMS_vidGET(SftyMgt_ctDftLadd, u8LocalSftyMgt_ctDftLadd);
      if (u8LocalSftyMgt_ctDftLadd != 0)
      {
         SftyMgt_bDgoIni = 1;
      }
      else
      {
         SftyMgt_bDgoIni = 0;
      }
      if (SftyMgt_bEveDftWrMem == 0)
      {
         SftyMgt_bEveIniEna = 1;
      }
      else
      {
         SftyMgt_bEveIniEna = 0;
      }
   }
   SftyMgt_bEveIniDftWrMemEna = SftyMgt_bEveDftWrMem;
   SftyMgt_bPresentInitVar = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidMergeTrameCtxtGD                               */
/* !Description :  Gère les trames de contexte vers le GD                     */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_054.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidTrmCtxtVrGDInit();                           */
/*  extf argret void SFTYMNGR_vidTrmCtxtVrGDDefaut();                         */
/*  input boolean SftyMgt_bEveIniEna;                                         */
/*  input boolean SftyMgt_bEveIniDftWrMemEna;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidMergeTrameCtxtGD(void)
{
   if(SftyMgt_bEveIniEna != 0)
   {
      SFTYMNGR_vidTrmCtxtVrGDInit();
   }
   if(SftyMgt_bEveIniDftWrMemEna != 0)
   {
      SFTYMNGR_vidTrmCtxtVrGDDefaut();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTrmCtxtVrGDInit                                */
/* !Description :  Trame vers GD à l’Init                                     */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_055.01                                     */
/*                 VEMS_R_10_01256_057.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 SftyMgt_prm_bDftHisOld[4];                                   */
/*  input uint32 SftyMgt_prm_bDftHisEveIniAfts[4];                            */
/*  output uint32 SftyMgt_prm_bDftHisEveIniAfts[4];                           */
/*  output uint16 SftyMgt_prm_bDftHisAfts[8];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTrmCtxtVrGDInit(void)
{
   uint8 u8LocalInd;


   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisEveIniAfts[u8LocalInd] =
         SftyMgt_prm_bDftHisOld[u8LocalInd];
   }
   /*Merge Trames */
   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisAfts[u8LocalInd * 2] =
         (uint16)(SftyMgt_prm_bDftHisEveIniAfts[u8LocalInd] >> 16);

      SftyMgt_prm_bDftHisAfts[(u8LocalInd * 2) + 1] =
         (uint16)(SftyMgt_prm_bDftHisEveIniAfts[u8LocalInd]);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTrmCtxtVrGDDefaut                              */
/* !Description :  Trame vers GD sur nouveau Défaut                           */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_056.01                                     */
/*                 VEMS_R_10_01256_057.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 SftyMgt_prm_bDft;                                            */
/*  input uint32 SftyMgt_prm_bDftHisOld[4];                                   */
/*  input uint32 SftyMgt_prm_bDftHisEveDftAfts[4];                            */
/*  output uint32 SftyMgt_prm_bDftHisEveDftAfts[4];                           */
/*  output uint16 SftyMgt_prm_bDftHisAfts[8];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTrmCtxtVrGDDefaut(void)
{
   uint8  u8LocalInd;
   uint32 u32LocalPrmDft;
   uint32 u32LocalMask1;
   uint32 u32LocalMask2;


   VEMS_vidGET(SftyMgt_prm_bDft, u32LocalPrmDft);

   u32LocalPrmDft = (u32LocalPrmDft & 0x01FFFFFFUL) << 7;
   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[0] & 0xFE000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDftAfts[0] = u32LocalMask1|u32LocalPrmDft;

   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[0] & 0x01FFFFFFUL) << 7;
   u32LocalMask2 = (SftyMgt_prm_bDftHisOld[1] & 0xFE000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDftAfts[1] = u32LocalMask2 | u32LocalMask1;

   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[1] & 0x01FFFFFFUL) << 7;
   u32LocalMask2 = (SftyMgt_prm_bDftHisOld[2] & 0xFE000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDftAfts[2] = u32LocalMask2 | u32LocalMask1;

   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[2] & 0x01FFFFFFUL) << 7;
   u32LocalMask2 = (SftyMgt_prm_bDftHisOld[3] & 0xF0000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDftAfts[3] = u32LocalMask2 | u32LocalMask1;

   /* Merge Trames*/
   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisAfts[u8LocalInd * 2] =
         (uint16)(SftyMgt_prm_bDftHisEveDftAfts[u8LocalInd] >> 16);

      SftyMgt_prm_bDftHisAfts[(u8LocalInd * 2) + 1] =
         (uint16)(SftyMgt_prm_bDftHisEveDftAfts[u8LocalInd]);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEnFormeContexteGD                              */
/* !Description :  Mets en forme le champs de bit en variables de 2 octets    */
/*                 pour être compatible avec GD / APV.                        */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_058.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input uint16 SftyMgt_prm_bDftHisAfts[8];                                  */
/*  output uint16 SftyMgt_prm_bDftHisAfts1;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts[8];                                 */
/*  output uint16 SftyMgt_prm_bDftHisAfts2;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts3;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts4;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts5;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts6;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts7;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts8;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEnFormeContexteGD(void)
{
   uint8  u8LocalSftyMgtCtDftLadd;
   uint16 u16LocalCalcDftHisAfts;
   uint16 u16LocalSftyMgtCtDftLadd1;
   uint16 u16LocalSftyMgtCtDftLadd;


   VEMS_vidGET(SftyMgt_ctDftLadd, u8LocalSftyMgtCtDftLadd);
   u16LocalSftyMgtCtDftLadd = (uint16)(u8LocalSftyMgtCtDftLadd & 0x07);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts1, SftyMgt_prm_bDftHisAfts[0]);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts2, SftyMgt_prm_bDftHisAfts[1]);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts3, SftyMgt_prm_bDftHisAfts[2]);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts4, SftyMgt_prm_bDftHisAfts[3]);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts5, SftyMgt_prm_bDftHisAfts[4]);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts6, SftyMgt_prm_bDftHisAfts[5]);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts7, SftyMgt_prm_bDftHisAfts[6]);

   u16LocalCalcDftHisAfts = (uint16)(SftyMgt_prm_bDftHisAfts[7] & 0xFFF8);
   u16LocalSftyMgtCtDftLadd1 =
      (uint16)(u16LocalSftyMgtCtDftLadd | u16LocalCalcDftHisAfts);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts8, u16LocalSftyMgtCtDftLadd1);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/