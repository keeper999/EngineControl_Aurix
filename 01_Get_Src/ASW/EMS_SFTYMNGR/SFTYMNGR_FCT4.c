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
/* !File            : SFTYMNGR_FCT4.C                                         */
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
/*   1 / SFTYMNGR_vidEcrTramMemSurKeyoff                                      */
/*   2 / SFTYMNGR_vidConstrTramMemKeyoff                                      */
/*   3 / SFTYMNGR_vidMemSansDefaut                                            */
/*   4 / SFTYMNGR_vidCasSaturaEcritureMem                                     */
/*   5 / SFTYMNGR_vidConditionSatMem                                          */
/*   6 / SFTYMNGR_vidEcritMemSat                                              */
/*   7 / SFTYMNGR_vidEcritMem                                                 */
/*   8 / SFTYMNGR_vidEvenementEcritMem                                        */
/*   9 / SFTYMNGR_vidEcritMemEEP                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_FCT4$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
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
#include "NVMSRV.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEcrTramMemSurKeyoff                            */
/* !Description :  écriture de la trame pour la mémoire sauvegardée sur       */
/*                 KeyOff.                                                    */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_031.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidConstrTramMemKeyoff();                       */
/*  extf argret void SFTYMNGR_vidMemSansDefaut();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEcrTramMemSurKeyoff(void)
{
   SFTYMNGR_vidConstrTramMemKeyoff();
   SFTYMNGR_vidMemSansDefaut();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidConstrTramMemKeyoff                            */
/* !Description :  Construire la trame pour la mémoire sauvegardée sur KeyOff.*/
/* !Number      :  FCT4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_032.01                                     */
/*                 VEMS_R_10_01256_038.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_ctWrMemOld;                                          */
/*  input uint32 SftyMgt_prm_bDftHisOld[4];                                   */
/*  input uint16 SftyMgt_prm_bFrfOld[8];                                      */
/*  input uint16 SftyMgt_ctWrMemEveKeyOff;                                    */
/*  input uint32 SftyMgt_prm_bDftHisEveKeyOff[4];                             */
/*  input uint16 SftyMgt_prm_bFrfEveKeyOff[8];                                */
/*  output uint16 SftyMgt_ctWrMemEveKeyOff;                                   */
/*  output uint8 SftyMgt_ctDftLaddEveKeyOff;                                  */
/*  output uint32 SftyMgt_prm_bDftHisEveKeyOff[4];                            */
/*  output uint16 SftyMgt_prm_bFrfEveKeyOff[8];                               */
/*  output uint16 SftyMgt_ctWrMem;                                            */
/*  output uint8 SftyMgt_ctDftLaddNew;                                        */
/*  output uint32 SftyMgt_prm_bDftHis[4];                                     */
/*  output uint16 SftyMgt_prm_bFrfNew[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidConstrTramMemKeyoff(void)
{
   uint8  u8LocalInd;
   uint32 u32LocalSftyMgtWrMemOld;


   u32LocalSftyMgtWrMemOld = SftyMgt_ctWrMemOld + 1;
   SftyMgt_ctWrMemEveKeyOff = (uint16)MATHSRV_udtMIN(u32LocalSftyMgtWrMemOld,
                                                     65000);

   SftyMgt_ctDftLaddEveKeyOff = 0;

   for (u8LocalInd = 0; u8LocalInd < 3; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisEveKeyOff[u8LocalInd] =
         SftyMgt_prm_bDftHisOld[u8LocalInd];
   }
   for (u8LocalInd = 0; u8LocalInd < 7; u8LocalInd++)
   {
      SftyMgt_prm_bFrfEveKeyOff[u8LocalInd] = SftyMgt_prm_bFrfOld[u8LocalInd];
   }
   SftyMgt_prm_bDftHisEveKeyOff[3] = (SftyMgt_prm_bDftHisOld[3] & 0xFFFFFFF8UL);
   SftyMgt_prm_bFrfEveKeyOff[7] = (uint16)(SftyMgt_prm_bFrfOld[7] & 0xFF00);

   /* Merge Trames*/
   SftyMgt_ctWrMem = SftyMgt_ctWrMemEveKeyOff;
   SftyMgt_ctDftLaddNew = 0;

   for (u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHis[u8LocalInd] =
         SftyMgt_prm_bDftHisEveKeyOff[u8LocalInd];
   }

   for (u8LocalInd = 0; u8LocalInd < 8; u8LocalInd++)
   {
      SftyMgt_prm_bFrfNew[u8LocalInd] = SftyMgt_prm_bFrfEveKeyOff[u8LocalInd];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidMemSansDefaut                                  */
/* !Description :  calcul de nb d'écriture mémoire sauvegardée                */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_033.01                                     */
/*                 VEMS_R_10_01256_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDgoSatMemEveKeyOff;                                */
/*  output boolean SftyMgt_bDgoSatMemEveKeyOff;                               */
/*  output boolean SftyMgt_bDgoSatMem;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidMemSansDefaut(void)
{
   SftyMgt_bDgoSatMemEveKeyOff = 0;
   /* Merge Mem Sat*/
   SftyMgt_bDgoSatMem = SftyMgt_bDgoSatMemEveKeyOff;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCasSaturaEcritureMem                           */
/* !Description :  gérer le cas de déclanchement de l’évènement de défaut     */
/*                 d’écriture sur Mem Saturée.                                */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_034.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidConditionSatMem();                           */
/*  extf argret void SFTYMNGR_vidEcritMemSat();                               */
/*  input boolean SftyMgt_bEveMemSat;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCasSaturaEcritureMem(void)
{
   SFTYMNGR_vidConditionSatMem();
   if (SftyMgt_bEveMemSat != 0)
   {
      SFTYMNGR_vidEcritMemSat();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidConditionSatMem                                */
/* !Description :  calculer la condition de déclanchement de l’évènement de   */
/*                 défaut d’écriture sur Mem Saturée.                         */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_035.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bEnaWrMem;                                          */
/*  input boolean SftyMgt_bEveDftWrMem;                                       */
/*  input boolean SftyMgt_bEveKeyOffWrMem;                                    */
/*  output boolean SftyMgt_bEveMemSat;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidConditionSatMem(void)
{
   if (  (SftyMgt_bEnaWrMem == 0)
      && (  (SftyMgt_bEveDftWrMem != 0)
         || (SftyMgt_bEveKeyOffWrMem != 0) ) )
   {
      SftyMgt_bEveMemSat = 1;
   }
   else
   {
      SftyMgt_bEveMemSat = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEcritMemSat                                    */
/* !Description :  Remonte un défaut de nombre d'écriture Mémoire sauvegardée */
/*                 dépassé                                                    */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_036.01                                     */
/*                 VEMS_R_10_01256_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDgoSatMemEveSat;                                   */
/*  output boolean SftyMgt_bDgoSatMemEveSat;                                  */
/*  output boolean SftyMgt_bDgoSatMem;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEcritMemSat(void)
{
   SftyMgt_bDgoSatMemEveSat = 1;
   /* Merge Mem Sat*/
   SftyMgt_bDgoSatMem = SftyMgt_bDgoSatMemEveSat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEcritMem                                       */
/* !Description :  Merge les données provenant des 3 cas possibles            */
/*                 d’évènements :Défaut,KeyOff et Nb d’écriture de mémoire    */
/*                 sauvegardée saturée. Et Provoque l’écriture en mémoire     */
/*                 sauvegardée ( sur évènements et non powerlatch)            */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_037.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidEvenementEcritMem();                         */
/*  extf argret void SFTYMNGR_vidEcritMemEEP();                               */
/*  input boolean SftyMgt_bEveWrMem;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEcritMem(void)
{
   SFTYMNGR_vidEvenementEcritMem();
   if (SftyMgt_bEveWrMem != 0)
   {
      SFTYMNGR_vidEcritMemEEP();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEvenementEcritMem                              */
/* !Description :  calculer la conditon d’écriture en mémoire sauvegardée (   */
/*                 sur évènements et non powerlatch)                          */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_039.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bEveDftWrMemEna;                                    */
/*  input boolean SftyMgt_bEveKeyOffWrMemEna;                                 */
/*  output boolean SftyMgt_bEveWrMem;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEvenementEcritMem(void)
{
   if (  (SftyMgt_bEveDftWrMemEna != 0)
      || (SftyMgt_bEveKeyOffWrMemEna != 0) )
   {
      SftyMgt_bEveWrMem = 1;
   }
   else
   {
      SftyMgt_bEveWrMem = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEcritMemEEP                                    */
/* !Description :  Ecrit en mémoire sauvegardée sur évènements.               */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_040.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/*  argin boolean bMode);                                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEcritMemEEP(void)
{
   NVMSRV_vidWrite(NVMSRV_u16OBJ_SFTYMNGR, NVMSRV_bSAVE_NOW);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/
