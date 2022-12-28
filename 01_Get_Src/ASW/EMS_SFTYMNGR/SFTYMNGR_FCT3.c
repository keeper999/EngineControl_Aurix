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
/* !File            : SFTYMNGR_FCT3.C                                         */
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
/*   1 / SFTYMNGR_vidTraiteMem2                                               */
/*   2 / SFTYMNGR_vidCasDefaut                                                */
/*   3 / SFTYMNGR_vidCondEcriMemSurDefaut                                     */
/*   4 / SFTYMNGR_vidEcriTramMemSurDefaut                                     */
/*   5 / SFTYMNGR_vidConstruitTrameDft                                        */
/*   6 / SFTYMNGR_vidMemSansDefautEveDft                                      */
/*   7 / SFTYMNGR_vidCasKeyOff                                                */
/*   8 / SFTYMNGR_vidIFTHENELSEWrMem                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_FCT3$*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
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
#include "MATHSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraiteMem2                                     */
/* !Description :  gèrer l’écriture de la mémoire sauvegardée et les          */
/*                 évènements provoquant cette écriture.                      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_023.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidCasDefaut();                                 */
/*  extf argret void SFTYMNGR_vidCasKeyOff();                                 */
/*  extf argret void SFTYMNGR_vidCasSaturaEcritureMem();                      */
/*  extf argret void SFTYMNGR_vidEcritMem();                                  */
/*  extf argret void SFTYMNGR_vidDetDftPresentInit();                         */
/*  extf argret void SFTYMNGR_vidMergeTrameCtxtGD();                          */
/*  extf argret void SFTYMNGR_vidEnFormeContexteGD();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraiteMem2(void)
{
   SFTYMNGR_vidCasDefaut();
   SFTYMNGR_vidCasKeyOff();
   SFTYMNGR_vidCasSaturaEcritureMem();
   SFTYMNGR_vidEcritMem();
   SFTYMNGR_vidDetDftPresentInit();
   SFTYMNGR_vidMergeTrameCtxtGD();
   SFTYMNGR_vidEnFormeContexteGD();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCasDefaut                                      */
/* !Description :  gérer le cas de déclanchement de l’évènement d’écriture en */
/*                 mémoire sauvegardée sur défaut.                            */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidCondEcriMemSurDefaut();                      */
/*  extf argret void SFTYMNGR_vidEcriTramMemSurDefaut();                      */
/*  input boolean SftyMgt_bEveDftWrMemEna;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCasDefaut(void)
{
   SFTYMNGR_vidCondEcriMemSurDefaut();
   if (SftyMgt_bEveDftWrMemEna != 0)
   {
      SFTYMNGR_vidEcriTramMemSurDefaut();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCondEcriMemSurDefaut                           */
/* !Description :  calculer la condition d'écriture sur mémoire sur defaut    */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bEveDftWrMem;                                       */
/*  input boolean SftyMgt_bEnaWrMem;                                          */
/*  output boolean SftyMgt_bEveDftWrMemEna;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCondEcriMemSurDefaut(void)
{
   if (  (SftyMgt_bEveDftWrMem != 0)
      && (SftyMgt_bEnaWrMem != 0) )
   {
      SftyMgt_bEveDftWrMemEna = 1;
   }
   else
   {
      SftyMgt_bEveDftWrMemEna = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEcriTramMemSurDefaut                           */
/* !Description :  ecriture pour la mémoire sauvegardée sur Défaut            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidConstruitTrameDft();                         */
/*  extf argret void SFTYMNGR_vidMemSansDefautEveDft();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEcriTramMemSurDefaut(void)
{
   SFTYMNGR_vidConstruitTrameDft();
   SFTYMNGR_vidMemSansDefautEveDft();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidConstruitTrameDft                              */
/* !Description :  Construire la trame pour la mémoire sauvegardée sur Défaut */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_027.01                                     */
/*                 VEMS_R_10_01256_038.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input uint16 SftyMgt_prm_bFrf[8];                                         */
/*  input uint32 SftyMgt_prm_bDft;                                            */
/*  input uint16 SftyMgt_ctWrMemOld;                                          */
/*  input uint32 SftyMgt_prm_bDftHisOld[4];                                   */
/*  input uint16 SftyMgt_ctWrMemEveDft;                                       */
/*  input uint32 SftyMgt_prm_bDftHisEveDft[4];                                */
/*  input uint16 SftyMgt_prm_bFrfEveDft[8];                                   */
/*  input uint8 SftyMgt_ctDftLaddEveDft;                                      */
/*  output uint16 SftyMgt_ctWrMemEveDft;                                      */
/*  output uint32 SftyMgt_prm_bDftHisEveDft[4];                               */
/*  output uint16 SftyMgt_prm_bFrfEveDft[8];                                  */
/*  output uint8 SftyMgt_ctDftLaddEveDft;                                     */
/*  output uint16 SftyMgt_ctWrMem;                                            */
/*  output uint32 SftyMgt_prm_bDftHis[4];                                     */
/*  output uint16 SftyMgt_prm_bFrfNew[8];                                     */
/*  output uint8 SftyMgt_ctDftLaddNew;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidConstruitTrameDft(void)
{
   uint8  u8LocalInd;
   uint8  u8LocalSftyMgtCtDftLadd;
   uint16 u16LocalSftyMgtPrmbFrf[8];
   /*QAC Msg(2:3132): declaration imposed by issue VEMS V02 ECU#059998 */
   uint32 u32LocalPrmDft;
   uint32 u32LocalWrMemEveDft;
   uint32 u32LocalMask1;
   uint32 u32LocalMask2;


   VEMS_vidGET(SftyMgt_ctDftLadd, u8LocalSftyMgtCtDftLadd);
   VEMS_vidGET1DArray(SftyMgt_prm_bFrf,
                      8,
                      u16LocalSftyMgtPrmbFrf);
   VEMS_vidGET(SftyMgt_prm_bDft, u32LocalPrmDft);

   u32LocalWrMemEveDft = SftyMgt_ctWrMemOld + 1;
   SftyMgt_ctWrMemEveDft = (uint16)MATHSRV_udtMIN(u32LocalWrMemEveDft, 65000);

   u32LocalPrmDft = (u32LocalPrmDft & 0x01FFFFFFUL) << 7;
   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[0] & 0xFE000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDft[0] = u32LocalMask1|u32LocalPrmDft;

   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[0] & 0x01FFFFFFUL) << 7;
   u32LocalMask2 = (SftyMgt_prm_bDftHisOld[1] & 0xFE000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDft[1] = u32LocalMask2 | u32LocalMask1;

   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[1] & 0x01FFFFFFUL) << 7;
   u32LocalMask2 = (SftyMgt_prm_bDftHisOld[2] & 0xFE000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDft[2] = u32LocalMask2 | u32LocalMask1;

   u32LocalMask1 = (SftyMgt_prm_bDftHisOld[2] & 0x01FFFFFFUL) << 7;
   u32LocalMask2 = (SftyMgt_prm_bDftHisOld[3] & 0xF0000000UL) >> 25;
   SftyMgt_prm_bDftHisEveDft[3] = u32LocalMask2 | u32LocalMask1;

   for(u8LocalInd = 0; u8LocalInd < 7; u8LocalInd++)
   {
      SftyMgt_prm_bFrfEveDft[u8LocalInd] = u16LocalSftyMgtPrmbFrf[u8LocalInd];
   }
   SftyMgt_prm_bFrfEveDft[7] = (uint16)(u16LocalSftyMgtPrmbFrf[7] & 0xFF00);

   SftyMgt_ctDftLaddEveDft =
      (uint8)MATHSRV_udtMIN(u8LocalSftyMgtCtDftLadd, 9);

   /* Merge Trames*/
   SftyMgt_ctWrMem = SftyMgt_ctWrMemEveDft;

   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHis[u8LocalInd] = SftyMgt_prm_bDftHisEveDft[u8LocalInd];
   }

   for(u8LocalInd = 0; u8LocalInd < 8; u8LocalInd++)
   {
      SftyMgt_prm_bFrfNew[u8LocalInd] = SftyMgt_prm_bFrfEveDft[u8LocalInd];
   }
   SftyMgt_ctDftLaddNew = SftyMgt_ctDftLaddEveDft;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidMemSansDefautEveDft                            */
/* !Description :  calculer le nombre d'écriture mémoire sauvegardée          */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_028.01                                     */
/*                 VEMS_R_10_01256_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDgoSatMemEveDft;                                   */
/*  output boolean SftyMgt_bDgoSatMemEveDft;                                  */
/*  output boolean SftyMgt_bDgoSatMem;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidMemSansDefautEveDft(void)
{
   SftyMgt_bDgoSatMemEveDft = 0;
   /* Merge Mem Sat*/
   SftyMgt_bDgoSatMem = SftyMgt_bDgoSatMemEveDft;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCasKeyOff                                      */
/* !Description :  gérer le cas de déclanchement de l’évènement d’écriture en */
/*                 mémoire sauvegardée sur keyOff.                            */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidIFTHENELSEWrMem();                           */
/*  extf argret void SFTYMNGR_vidEcrTramMemSurKeyoff();                       */
/*  input boolean SftyMgt_bEveKeyOffWrMemEna;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCasKeyOff(void)
{
   SFTYMNGR_vidIFTHENELSEWrMem();
   if (SftyMgt_bEveKeyOffWrMemEna != 0)
   {
      SFTYMNGR_vidEcrTramMemSurKeyoff();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidIFTHENELSEWrMem                                */
/* !Description :  calculer la conditions de déclanchement de l’évènement     */
/*                 d’écriture en mémoire sauvegardée sur keyOff.              */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input boolean SftyMgt_bEnaWrMem;                                          */
/*  input boolean SftyMgt_bEveKeyOffWrMem;                                    */
/*  output boolean SftyMgt_bEveKeyOffWrMemEna;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidIFTHENELSEWrMem(void)
{
   uint8  u8LocalSftyMgtCtDftLadd;


   VEMS_vidGET(SftyMgt_ctDftLadd,u8LocalSftyMgtCtDftLadd);
   if (  (u8LocalSftyMgtCtDftLadd != 0)
      && (SftyMgt_bEnaWrMem != 0)
      && (SftyMgt_bEveKeyOffWrMem != 0) )
   {
      SftyMgt_bEveKeyOffWrMemEna = 1;
   }
   else
   {
      SftyMgt_bEveKeyOffWrMemEna = 0;
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/