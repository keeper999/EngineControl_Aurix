/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SECUBV                                                  */
/* !Description     : SECUBV Component                                        */
/*                                                                            */
/* !Module          : SECUBV                                                  */
/* !Description     : Sécuriser Boites                                        */
/*                                                                            */
/* !File            : SECUBV_FCT1.C                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SECUBV_vidInitOutput                                                 */
/*   2 / SECUBV_vidBVConfiguration                                            */
/*   3 / SECUBV_vidBVMConfiguration                                           */
/*   4 / SECUBV_vidBVABVMPConfiguration                                       */
/*   5 / SECUBV_vidRAZCompteursSurChange                                      */
/*   6 / SECUBV_vidSecurisationTempsSIP                                       */
/*   7 / SECUBV_vidSecurisationSpecifAL4                                      */
/*   8 / SECUBV_vidSyntheseDefaut                                             */
/*   9 / SECUBV_vidSecurisationGBxActive                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 01251 / 03                                        */
/* !OtherRefs   : 01460_09_01310 / 1.2                                        */
/* !OtherRefs   : VEMS V02 ECU#047007                                         */
/* !OtherRefs   : VEMS V02 ECU#050657                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_FCT1.C_v$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SECUBV.h"
#include "SECUBV_L.h"
#include "SECUBV_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidInitOutput                                       */
/* !Description :  initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoTqGBx;                                         */
/*  output boolean SftyMgt_bDeac0TqGBx;                                       */
/*  output uint16 SftyMgt_tiSIPCntRst;                                        */
/*  output uint16 SftyMgt_tiSIPCnt;                                           */
/*  output uint16 SftyMgt_tiSIPCntRun;                                        */
/*  output uint8 SECUBV_u8tiDlyOnDgoDeltaTq_Cnt;                              */
/*  output uint8 SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt;                             */
/*  output uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt;                              */
/*  output uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1;                            */
/*  output uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2;                            */
/*  output boolean SftyMgt_bDgoDeltaTqCordAL4;                                */
/*  output boolean SftyMgt_bDgoDeltaTqCordNotAL4;                             */
/*  output boolean SftyMgt_bNbTarGearChgSIPRun;                               */
/*  output boolean SftyMgt_bNbTarGearChgSIPRst;                               */
/*  output boolean SftyMgt_bNbTarGearChgTqIRun;                               */
/*  output boolean SftyMgt_bNbTarGearChgTqIRst;                               */
/*  output boolean SftyMgt_bNRegReqChgSIPRun;                                 */
/*  output boolean SftyMgt_bNRegReqChgSIPRst;                                 */
/*  output sint16 SftyMgt_tqTiDeltaTqIRun;                                    */
/*  output sint16 SftyMgt_tqTiDeltaTqIRst;                                    */
/*  output sint16 SftyMgt_tqTiDeltaTqI;                                       */
/*  output uint8 SECUBV_u8SftyMgt_bDgoSIPNotIpCnt;                            */
/*  output boolean SECUBV_bEnaDftDeltaTqIRunPrev;                             */
/*  output boolean SECUBV_bEnaSIPCntRun_Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDgoTqGBx, 0);
   VEMS_vidSET(SftyMgt_bDeac0TqGBx, 0);
   SftyMgt_tiSIPCntRst = 0;
   SftyMgt_tiSIPCnt = 0;
   SftyMgt_tiSIPCntRun = 0;
   SECUBV_u8tiDlyOnDgoDeltaTq_Cnt = 0;
   SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt = 0;
   SECUBV_u16tiDlyOnDgoTqGBx_Cnt = 0;
   SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1 = 0;
   SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2 = 0;
   SftyMgt_bDgoDeltaTqCordAL4 = 0;
   SftyMgt_bDgoDeltaTqCordNotAL4 = 0;
   SftyMgt_bNbTarGearChgSIPRun = 0;
   SftyMgt_bNbTarGearChgSIPRst = 0;
   SftyMgt_bNbTarGearChgTqIRun = 0;
   SftyMgt_bNbTarGearChgTqIRst = 0;
   SftyMgt_bNRegReqChgSIPRun = 0;
   SftyMgt_bNRegReqChgSIPRst = 0;
   SftyMgt_tqTiDeltaTqIRun = 0;
   SftyMgt_tqTiDeltaTqIRst = 0;
   SftyMgt_tqTiDeltaTqI = 0;
   SECUBV_u8SftyMgt_bDgoSIPNotIpCnt = 0;
   SECUBV_bEnaDftDeltaTqIRunPrev = 0;
   SECUBV_bEnaSIPCntRun_Prev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidBVConfiguration                                  */
/* !Description :  fonction qui assure le Test de la configuration définissant*/
/*                 le code à compiler                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  output boolean SftyMgt_bEnaMTCf;                                          */
/*  output boolean SftyMgt_bEnaATAMTCf;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidBVConfiguration(void)
{
   uint8 u8LocalExt_stGBxCf;

   /* F01_BVConfiguration */

   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 0)
   {
      SftyMgt_bEnaMTCf = 1;
      SftyMgt_bEnaATAMTCf = 0;
   }
   else
   {
      SftyMgt_bEnaMTCf = 0;
      SftyMgt_bEnaATAMTCf = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidBVMConfiguration                                 */
/* !Description :  Cette fonction permet de bypasser la sécurisation dans le  */
/*                 cas d’une BVM                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_003.02                                     */
/*                 VEMS_R_10_01251_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bEnaMTCf;                                           */
/*  input boolean SftyMgt_bDgoTqGBxMTCf;                                      */
/*  input boolean SftyMgt_bDeac0TqGBxMTCf;                                    */
/*  output boolean SftyMgt_bDgoTqGBxMTCf;                                     */
/*  output boolean SftyMgt_bDgoTqGBx;                                         */
/*  output boolean SftyMgt_bDeac0TqGBxMTCf;                                   */
/*  output boolean SftyMgt_bDeac0TqGBx;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidBVMConfiguration(void)
{
   /*F02_BVMConfiguration */

   if (SftyMgt_bEnaMTCf != 0)
   {
      SftyMgt_bDgoTqGBxMTCf = 0;
      VEMS_vidSET(SftyMgt_bDgoTqGBx, SftyMgt_bDgoTqGBxMTCf);
      SftyMgt_bDeac0TqGBxMTCf = 0;
      VEMS_vidSET(SftyMgt_bDeac0TqGBx, SftyMgt_bDeac0TqGBxMTCf);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidBVABVMPConfiguration                             */
/* !Description :  Cette fonction effectue la synthèse des défauts CMM boite. */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidRAZCompteursSurChange();                       */
/*  extf argret void SECUBV_vidSecurisationTempsSIP();                        */
/*  extf argret void SECUBV_vidSecurisationSpecifAL4();                       */
/*  extf argret void SECUBV_vidSecurisationGBxActive();                       */
/*  extf argret void SECUBV_vidSyntheseDefaut();                              */
/*  input boolean SftyMgt_bEnaATAMTCf;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidBVABVMPConfiguration(void)
{
   /* F03_BVABVMPConfiguration */

   if (SftyMgt_bEnaATAMTCf != 0)
   {
      SECUBV_vidRAZCompteursSurChange();
      SECUBV_vidSecurisationTempsSIP();
      SECUBV_vidSecurisationSpecifAL4();
      SECUBV_vidSecurisationGBxActive();
      SECUBV_vidSyntheseDefaut();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidRAZCompteursSurChange                            */
/* !Description :  Cette fonction détecte un chgt de rapport ou une entrée en */
/*                 régulation de régime alors qu’un SIP est engagé et en      */
/*                 fonction de la configuration boite choisit de reseter ou   */
/*                 non le compteur de temps.                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_037.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidStrategieRAZFctBoite();                        */
/*  extf argret void SECUBV_vidTraiChgRapSIPSdlNiv1V2();                      */
/*  extf argret void SECUBV_vidTraiChgRapInCpleNiv1V2();                      */
/*  extf argret void SECUBV_vidTrRegulRegAM6SdlNiv1V2();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidRAZCompteursSurChange(void)
{
   /* F03_01_RAZCompteursSurChangement */

   SECUBV_vidStrategieRAZFctBoite();
   SECUBV_vidTraiChgRapSIPSdlNiv1V2();
   SECUBV_vidTraiChgRapInCpleNiv1V2();
   SECUBV_vidTrRegulRegAM6SdlNiv1V2();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidSecurisationTempsSIP                             */
/* !Description :  Cette fonction effectue l’analyse de la prise en main du   */
/*                 couple moteur par les BVMP/BVA                             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidSecurisaMiseEnPlaceFRM();                      */
/*  extf argret void SECUBV_vidDetectionSIPInvalide();                        */
/*  extf argret void SECUBV_vidCalculSIPOutOfRange();                         */
/*  extf argret void SECUBV_vidCoordDebounceSIPErreur();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidSecurisationTempsSIP(void)
{
   /*F03_02_securisationTempsSIP*/

   SECUBV_vidSecurisaMiseEnPlaceFRM();
   SECUBV_vidDetectionSIPInvalide();
   SECUBV_vidCalculSIPOutOfRange();
   SECUBV_vidCoordDebounceSIPErreur();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidSecurisationSpecifAL4                            */
/* !Description :  Ce bloc effectue l’analyse de la prise en main du couple   */
/*                 moteur par l’AL4                                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidConfiguationAL4();                             */
/*  extf argret void SECUBV_vidAL4AT8Presente();                              */
/*  extf argret void SECUBV_vidAutre();                                       */
/*  input boolean SftyMgt_bEnaAL4;                                            */
/*  input boolean SftyMgt_bEnaNotAL4;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidSecurisationSpecifAL4(void)
{
   /* F03_03_securisationSpecifiqueAL4 */

   SECUBV_vidConfiguationAL4();
   if (SftyMgt_bEnaAL4 != 0)
   {
      SECUBV_vidAL4AT8Presente();
   }

   if (SftyMgt_bEnaNotAL4 != 0)
   {
      SECUBV_vidAutre();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidSyntheseDefaut                                   */
/* !Description :  Cette fonction effectue la synthèse entre les défauts CMM  */
/*                 boite et l’état de la chaine de traction.                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_016.03                                     */
/*                 VEMS_R_10_01251_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bOpTra;                                             */
/*  input boolean SftyMgt_bDgoSIPCord;                                        */
/*  input boolean SftyMgt_bDgoSIPNotIp;                                       */
/*  input boolean SftyMgt_bDgoDeltaTqCord;                                    */
/*  input boolean SftyMgt_bInhCluNotOp_C;                                     */
/*  input boolean SftyMgt_bDgoTqGBxATAMTCf;                                   */
/*  output boolean SftyMgt_bDgoTqGBxATAMTCf;                                  */
/*  output boolean SftyMgt_bDgoTqGBx;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidSyntheseDefaut(void)
{
   boolean bLocalSftyMgtbDgoCord;
   boolean bLocalSftyMgt_bOpTra;


   /* F03_04_syntheseDefaut */

   VEMS_vidGET(SftyMgt_bOpTra,bLocalSftyMgt_bOpTra);

   if (  (SftyMgt_bDgoSIPCord != 0)
      || (SftyMgt_bDgoSIPNotIp != 0)
      || (SftyMgt_bDgoDeltaTqCord != 0))
   {
      bLocalSftyMgtbDgoCord = 1;
   }
   else
   {
      bLocalSftyMgtbDgoCord = 0;
   }

   if (SftyMgt_bInhCluNotOp_C != 0)
   {
      SftyMgt_bDgoTqGBxATAMTCf = bLocalSftyMgtbDgoCord;
   }
   else
   {
      if (  (bLocalSftyMgtbDgoCord != 0)
         && (bLocalSftyMgt_bOpTra == 0))
      {
         SftyMgt_bDgoTqGBxATAMTCf = 1;
      }
      else
      {
         SftyMgt_bDgoTqGBxATAMTCf = 0;
      }
   }
   VEMS_vidSET(SftyMgt_bDgoTqGBx, SftyMgt_bDgoTqGBxATAMTCf);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidSecurisationGBxActive                            */
/* !Description :  Ce bloc désactive le 0 torque lorsqu’il sécurise de manière*/
/*                 active le couple                                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_017.01                                     */
/*                 VEMS_R_10_01251_038.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bSIPCoPt;                                           */
/*  input boolean SftyMgt_bFuCutOffReqTqSys;                                  */
/*  input sint16 SftyMgt_tqSumLossCmp;                                        */
/*  input sint16 SftyMgt_tqEfcReqCoChaChk;                                    */
/*  input sint16 SftyMgt_tqIdcReqCordNRegReq;                                 */
/*  input boolean SftyMgt_bDeac0TqGBxATAMTCf;                                 */
/*  input boolean SftyMgt_bInhDgoSIPNotIp_C;                                  */
/*  input sint16 SftyMgt_tqOfsGbxSIPNotIp_C;                                  */
/*  input uint8 SftyMgt_tiDlyOnDgoSIPNotIp_C;                                 */
/*  input uint8 SECUBV_u8SftyMgt_bDgoSIPNotIpCnt;                             */
/*  output boolean SftyMgt_bDeac0TqGBxATAMTCf;                                */
/*  output boolean SftyMgt_bDeac0TqGBx;                                       */
/*  output uint8 SECUBV_u8SftyMgt_bDgoSIPNotIpCnt;                            */
/*  output boolean SftyMgt_bDgoSIPNotIp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidSecurisationGBxActive(void)
{
   /* F03_04_SecurisationGBxActive */
   boolean bLocalSftyMgt_bSIPCoPt;
   boolean bLocalSftyMgt_bInhDgoSIPNotIp;
   boolean bLocalSftyMgt_bFuCutOffReqTqSys;
   uint8   u8LocalSumTurnOnDelaySimple;
   uint8   u8LocalMinTurnOnDelaySimple;
   sint16  s16LocalSftyMgt_tqSumLossCmp;
   sint16  s16LocalSftyMgt_tqEfcReqCoChaChk;
   sint16  s16LocalSftyMgtIdcReqCordNRegReq;
   sint32  s32LocalSum;

   VEMS_vidGET(SftyMgt_bSIPCoPt, bLocalSftyMgt_bSIPCoPt);
   VEMS_vidGET(SftyMgt_bFuCutOffReqTqSys, bLocalSftyMgt_bFuCutOffReqTqSys);
   VEMS_vidGET(SftyMgt_tqSumLossCmp, s16LocalSftyMgt_tqSumLossCmp);
   VEMS_vidGET(SftyMgt_tqEfcReqCoChaChk, s16LocalSftyMgt_tqEfcReqCoChaChk);
   VEMS_vidGET(SftyMgt_tqIdcReqCordNRegReq, s16LocalSftyMgtIdcReqCordNRegReq);

   SftyMgt_bDeac0TqGBxATAMTCf = bLocalSftyMgt_bSIPCoPt;
   VEMS_vidSET(SftyMgt_bDeac0TqGBx, SftyMgt_bDeac0TqGBxATAMTCf);
   if (SftyMgt_bInhDgoSIPNotIp_C != 0)
   {
      bLocalSftyMgt_bInhDgoSIPNotIp = 0;
   }
   else
   {
      if (bLocalSftyMgt_bFuCutOffReqTqSys != 0)
      {
         s32LocalSum = 0;
      }
      else
      {
         s32LocalSum = ( s16LocalSftyMgt_tqEfcReqCoChaChk
                       + s16LocalSftyMgt_tqSumLossCmp);
      }
      s32LocalSum = s32LocalSum + SftyMgt_tqOfsGbxSIPNotIp_C;

      if (s16LocalSftyMgtIdcReqCordNRegReq > s32LocalSum)
      {
         bLocalSftyMgt_bInhDgoSIPNotIp = 1;
      }
      else
      {
         bLocalSftyMgt_bInhDgoSIPNotIp = 0;
      }

      if (  (bLocalSftyMgt_bInhDgoSIPNotIp != 0)
         && (bLocalSftyMgt_bSIPCoPt == 0))
      {
         bLocalSftyMgt_bInhDgoSIPNotIp = 1;
      }
      else
      {
         bLocalSftyMgt_bInhDgoSIPNotIp = 0;
      }
   }
   u8LocalSumTurnOnDelaySimple =
      (uint8)((SftyMgt_tiDlyOnDgoSIPNotIp_C + 6) / 4);
   if (bLocalSftyMgt_bInhDgoSIPNotIp == 0)
   {
      SECUBV_u8SftyMgt_bDgoSIPNotIpCnt = 0;
   }
   else
   {
      u8LocalMinTurnOnDelaySimple =
         (uint8)MATHSRV_udtMIN(SECUBV_u8SftyMgt_bDgoSIPNotIpCnt,
                               u8LocalSumTurnOnDelaySimple);
      SECUBV_u8SftyMgt_bDgoSIPNotIpCnt = (uint8)( u8LocalMinTurnOnDelaySimple
                                                + 1);
   }

   if (SECUBV_u8SftyMgt_bDgoSIPNotIpCnt >= u8LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDgoSIPNotIp = 1;
   }
   else
   {
      SftyMgt_bDgoSIPNotIp = 0;
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/