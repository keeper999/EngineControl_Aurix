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
/* !File            : SECUBV_FCT4.C                                           */
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
/*   1 / SECUBV_vidConfiguationAL4                                            */
/*   2 / SECUBV_vidAL4AT8Presente                                             */
/*   3 / SECUBV_vidAutre                                                      */
/*   4 / SECUBV_vidDetectErrCplLentCplRap                                     */
/*   5 / SECUBV_vidDetectErrIntegrSurcple                                     */
/*   6 / SECUBV_vidCoordinationAL4Erreur                                      */
/*   7 / SECUBV_vidIntegraleSurcouple                                         */
/*   8 / SECUBV_vidCompSeuilIntegrSurcple                                     */
/*   9 / SECUBV_vidDebounDefDeltaAirAvAl4                                     */
/*   10 / SECUBV_vidDebounDefIntSurcpleAL4                                    */
/*                                                                            */
/* !Reference   : V02 NT 10 01251 / 03                                        */
/* !OtherRefs   : 01460_09_01310 / 1.2                                        */
/* !OtherRefs   : VEMS V02 ECU#047007                                         */
/* !OtherRefs   : VEMS V02 ECU#050657                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_FCT4.C_v$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
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
/* !Function    :  SECUBV_vidConfiguationAL4                                  */
/* !Description :  en attendant le SIQ                                        */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stTraTypCf;                                               */
/*  output boolean SftyMgt_bEnaAL4;                                           */
/*  output boolean SftyMgt_bEnaNotAL4;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidConfiguationAL4(void)
{
   uint8 u8LocalExt_stTraTypCf;


   VEMS_vidGET(Ext_stTraTypCf, u8LocalExt_stTraTypCf);
   /* F03_03_01_ConfiguationAL4 */
   if (u8LocalExt_stTraTypCf == 0)
   {
      SftyMgt_bEnaAL4 = 1;
      SftyMgt_bEnaNotAL4 = 0;
   }
   else
   {
      SftyMgt_bEnaAL4 = 0;
      SftyMgt_bEnaNotAL4 = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidAL4AT8Presente                                   */
/* !Description :  Ce bloc traite AL4/AT8  présente .                         */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidDetectErrCplLentCplRap();                      */
/*  extf argret void SECUBV_vidDetectErrIntegrSurcple();                      */
/*  extf argret void SECUBV_vidCoordinationAL4Erreur();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidAL4AT8Presente(void)
{
   /* F03_03_02_AL4AT8Presente */

   SECUBV_vidDetectErrCplLentCplRap();
   SECUBV_vidDetectErrIntegrSurcple();
   SECUBV_vidCoordinationAL4Erreur();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidAutre                                            */
/* !Description :  Ce bloc traite le cas où AL4/AT8 non présente.             */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_035.01                                     */
/*                 VEMS_R_10_01251_036.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDgoDeltaTqCordNotAL4;                              */
/*  output boolean SftyMgt_bDgoDeltaTqCordNotAL4;                             */
/*  output boolean SftyMgt_bDgoDeltaTqCord;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidAutre(void)
{
   /* F03_03_03_Autre */

   SftyMgt_bDgoDeltaTqCordNotAL4 = 0;
   SftyMgt_bDgoDeltaTqCord = SftyMgt_bDgoDeltaTqCordNotAL4;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidDetectErrCplLentCplRap                           */
/* !Description :  Surveillance du couple lent par rapport au couple rapide.  */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input boolean SftyMgt_bSIPCoPt;                                           */
/*  input sint16 SftyMgt_tqReqGBxCoPt;                                        */
/*  input sint16 SftyMgt_tqAirReqGBxCoPt;                                     */
/*  input uint8 SftyMgt_spdDftDeltaTq_A[6];                                   */
/*  input uint16 SftyMgt_tqDeltaTq_T[6];                                      */
/*  output boolean SftyMgt_bDftDeltaTq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidDetectErrCplLentCplRap(void)
{
   boolean bLocalSftyMgt_bSIPCoPt;
   uint8   u8LocalSftyMgt_spdVeh;
   uint16  u16LocalSftyMgt_spdVeh;
   uint16  u16LocalSftyMgt_tqDeltaTq;
   uint16  u16LocalPara;
   sint16  s16LocalSftyMgt_tqReqGBxCoPt;
   sint16  s16LocalSftyMgt_tqAirReqGBxCoPt;
   sint32  s32LocalSum;


   /* F03_03_02_01_detectionErreurCoupleLentCoupleRapide */

   VEMS_vidGET(SftyMgt_spdVeh, u16LocalSftyMgt_spdVeh);
   VEMS_vidGET(SftyMgt_bSIPCoPt, bLocalSftyMgt_bSIPCoPt);
   VEMS_vidGET(SftyMgt_tqReqGBxCoPt, s16LocalSftyMgt_tqReqGBxCoPt);
   VEMS_vidGET(SftyMgt_tqAirReqGBxCoPt, s16LocalSftyMgt_tqAirReqGBxCoPt);

   u16LocalSftyMgt_spdVeh = (uint16)(u16LocalSftyMgt_spdVeh / 128);
   u8LocalSftyMgt_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_spdVeh, 255);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(SftyMgt_spdDftDeltaTq_A,
                                              u8LocalSftyMgt_spdVeh,
                                              6);

   u16LocalSftyMgt_tqDeltaTq = MATHSRV_u16Interp1d(SftyMgt_tqDeltaTq_T,
                                                   u16LocalPara);

   s32LocalSum = (sint32)( s16LocalSftyMgt_tqReqGBxCoPt
                         + u16LocalSftyMgt_tqDeltaTq);
   if (  (s16LocalSftyMgt_tqAirReqGBxCoPt > s32LocalSum)
      && (bLocalSftyMgt_bSIPCoPt != 0))
   {
      SftyMgt_bDftDeltaTq = 1;
   }
   else
   {
      SftyMgt_bDftDeltaTq = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidDetectErrIntegrSurcple                           */
/* !Description :  Surveillance de l’integrale de surcouple rapide/volonte    */
/*                 conducteur du Niveau 1.                                    */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidIntegraleSurcouple();                          */
/*  extf argret void SECUBV_vidCompSeuilIntegrSurcple();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidDetectErrIntegrSurcple(void)
{
   /* F03_03_02_03_detectionErreurIntegraleSurcouple */
   SECUBV_vidIntegraleSurcouple();
   SECUBV_vidCompSeuilIntegrSurcple();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidCoordinationAL4Erreur                            */
/* !Description :  Coordination des erreurs spécifiques AL4.                  */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidDebounDefDeltaAirAvAl4();                      */
/*  extf argret void SECUBV_vidDebounDefIntSurcpleAL4();                      */
/*  extf argret void SECUBV_vidCoordinationDefautsAL4();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidCoordinationAL4Erreur(void)
{
   /* F03_03_02_04_CoordinationAL4Erreur */
   SECUBV_vidDebounDefDeltaAirAvAl4();
   SECUBV_vidDebounDefIntSurcpleAL4();
   SECUBV_vidCoordinationDefautsAL4();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidIntegraleSurcouple                               */
/* !Description :  cette fonction calcule l'integrale sur couple              */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidIFTHENIntegraleSurcple();                      */
/*  extf argret void SECUBV_vidRAZIntegraleSurcouple();                       */
/*  extf argret void SECUBV_vidIntegraleSurcple();                            */
/*  input boolean SftyMgt_bEnaDftDeltaTqIRst;                                 */
/*  input boolean SftyMgt_bEnaDftDeltaTqIRun;                                 */
/*  input boolean SECUBV_bEnaDftDeltaTqIRunPrev;                              */
/*  output sint16 SftyMgt_tqTiDeltaTqIRun;                                    */
/*  output sint16 SftyMgt_tqTiDeltaTqI;                                       */
/*  output boolean SECUBV_bEnaDftDeltaTqIRunPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidIntegraleSurcouple(void)
{
   /* F03_03_02_03_01_IntegraleSurcouple */

   SECUBV_vidIFTHENIntegraleSurcple();
   if (SftyMgt_bEnaDftDeltaTqIRst != 0)
   {
      SECUBV_vidRAZIntegraleSurcouple();
   }

   if (SftyMgt_bEnaDftDeltaTqIRun != 0)
   {
      if (SECUBV_bEnaDftDeltaTqIRunPrev == 0)
      {
         SftyMgt_tqTiDeltaTqIRun = 0;
         SftyMgt_tqTiDeltaTqI = 0;
      }
      else
      {
         SECUBV_vidIntegraleSurcple();
      }
   }
   SECUBV_bEnaDftDeltaTqIRunPrev = SftyMgt_bEnaDftDeltaTqIRun;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidCompSeuilIntegrSurcple                           */
/* !Description :  Le résultat de l’intégrale de surcouple est comparé à un   */
/*                 seuil dépendant de la vitesse véhicule.                    */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input uint8 SftyMgt_spdDftTqI_A[6];                                       */
/*  input uint16 SftyMgt_tqTiDftTqI_T[6];                                     */
/*  input sint16 SftyMgt_tqTiDeltaTqI;                                        */
/*  output boolean SftyMgt_bDftDeltaTqI;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidCompSeuilIntegrSurcple(void)
{
   uint8  u8LocalSftyMgt_spdVeh;
   uint16 u16LocalSftyMgt_spdVeh;
   uint16 u16LocalSftyMgt_tqTiDftTqI;
   uint16 u16LocalPara;
   sint32 s32LocalSftyMgt_tqTiDeltaTqI;


   /* F03_03_02_03_02_comparaisonSeuilIntegraleSurcouple */

   VEMS_vidGET(SftyMgt_spdVeh, u16LocalSftyMgt_spdVeh);
   u16LocalSftyMgt_spdVeh = (uint16)(u16LocalSftyMgt_spdVeh / 128);
   u8LocalSftyMgt_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_spdVeh, 255);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(SftyMgt_spdDftTqI_A,
                                              u8LocalSftyMgt_spdVeh,
                                              6);

   u16LocalSftyMgt_tqTiDftTqI = MATHSRV_u16Interp1d(SftyMgt_tqTiDftTqI_T,
                                                   u16LocalPara);
   s32LocalSftyMgt_tqTiDeltaTqI = (sint32)(SftyMgt_tqTiDeltaTqI * 16);
   if (s32LocalSftyMgt_tqTiDeltaTqI > u16LocalSftyMgt_tqTiDftTqI)
   {
      SftyMgt_bDftDeltaTqI = 1;
   }
   else
   {
      SftyMgt_bDftDeltaTqI = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidDebounDefDeltaAirAvAl4                           */
/* !Description :  Debounce défaut couple lent / couple rapide                */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_032.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDgoDeltaTq_C;                                   */
/*  input boolean SftyMgt_bDftDeltaTq;                                        */
/*  input uint8 SftyMgt_tiDlyOnDgoDeltaTq_C;                                  */
/*  input uint8 SECUBV_u8tiDlyOnDgoDeltaTq_Cnt;                               */
/*  output uint8 SECUBV_u8tiDlyOnDgoDeltaTq_Cnt;                              */
/*  output boolean SftyMgt_bDgoDeltaTq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidDebounDefDeltaAirAvAl4(void)
{
   boolean bLocalSftyMgt_bDftDeltaTq;
   uint8   u8LocalSumTurnOnDelaySimple;
   uint8   u8LocalMinTurnOnDelaySimple;

   /* F03_03_02_04_01_DebounceDefautDeltaAirAvanceAl4 */

   if (SftyMgt_bInhDgoDeltaTq_C != 0)
   {
      bLocalSftyMgt_bDftDeltaTq = 0;
   }
   else
   {
      bLocalSftyMgt_bDftDeltaTq = SftyMgt_bDftDeltaTq;
   }
   u8LocalSumTurnOnDelaySimple = (uint8)((SftyMgt_tiDlyOnDgoDeltaTq_C + 6) / 4);
   if (bLocalSftyMgt_bDftDeltaTq == 0)
   {
      SECUBV_u8tiDlyOnDgoDeltaTq_Cnt = 0;
   }
   else
   {
      u8LocalMinTurnOnDelaySimple =
         (uint8)MATHSRV_udtMIN(SECUBV_u8tiDlyOnDgoDeltaTq_Cnt,
                               u8LocalSumTurnOnDelaySimple);
      SECUBV_u8tiDlyOnDgoDeltaTq_Cnt = (uint8)(u8LocalMinTurnOnDelaySimple + 1);
   }

   if (SECUBV_u8tiDlyOnDgoDeltaTq_Cnt >= u8LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDgoDeltaTq = 1;
   }
   else
   {
      SftyMgt_bDgoDeltaTq = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidDebounDefIntSurcpleAL4                           */
/* !Description :  Débounce défaut Intégrale de surcouple                     */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_033.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDgoDeltaTqI_C;                                  */
/*  input boolean SftyMgt_bDftDeltaTqI;                                       */
/*  input uint8 SftyMgt_tiDlyOnDgoDeltaTqI_C;                                 */
/*  input uint8 SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt;                              */
/*  output uint8 SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt;                             */
/*  output boolean SftyMgt_bDgoDeltaTqI;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidDebounDefIntSurcpleAL4(void)
{
   boolean bLocalSftyMgt_bDftDeltaTqI;
   uint8   u8LocalSumTurnOnDelaySimple;
   uint8   u8LocalMinTurnOnDelaySimple;

   /* F03_03_02_04_02_DebounceDefautIntegraleSurcoupleAL4 */

   if (SftyMgt_bInhDgoDeltaTqI_C != 0)
   {
      bLocalSftyMgt_bDftDeltaTqI = 0;
   }
   else
   {
      bLocalSftyMgt_bDftDeltaTqI = SftyMgt_bDftDeltaTqI;
   }
   u8LocalSumTurnOnDelaySimple =
      (uint8)((SftyMgt_tiDlyOnDgoDeltaTqI_C + 6) / 4);
   if (bLocalSftyMgt_bDftDeltaTqI == 0)
   {
      SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt = 0;
   }
   else
   {
      u8LocalMinTurnOnDelaySimple =
         (uint8)MATHSRV_udtMIN(SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt,
                               u8LocalSumTurnOnDelaySimple);
      SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt =
         (uint8)(u8LocalMinTurnOnDelaySimple + 1);
   }

   if (SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt >= u8LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDgoDeltaTqI = 1;
   }
   else
   {
      SftyMgt_bDgoDeltaTqI = 0;
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/