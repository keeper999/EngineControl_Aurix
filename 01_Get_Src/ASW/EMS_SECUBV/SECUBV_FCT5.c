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
/* !File            : SECUBV_FCT5.C                                           */
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
/*   1 / SECUBV_vidCoordinationDefautsAL4                                     */
/*   2 / SECUBV_vidIFTHENIntegraleSurcple                                     */
/*   3 / SECUBV_vidRAZIntegraleSurcouple                                      */
/*   4 / SECUBV_vidIntegraleSurcple                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 01251 / 03                                        */
/* !OtherRefs   : 01460_09_01310 / 1.2                                        */
/* !OtherRefs   : VEMS V02 ECU#047007                                         */
/* !OtherRefs   : VEMS V02 ECU#050657                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_FCT5.C_v$*/
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
/* !Function    :  SECUBV_vidCoordinationDefautsAL4                           */
/* !Description :  Coordination des erreurs spécifiques AL4.                  */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_034.01                                     */
/*                 VEMS_R_10_01251_036.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDgoDeltaTq;                                        */
/*  input boolean SftyMgt_bDgoDeltaTqI;                                       */
/*  input boolean SftyMgt_bDgoDeltaTqCordAL4;                                 */
/*  output boolean SftyMgt_bDgoDeltaTqCordAL4;                                */
/*  output boolean SftyMgt_bDgoDeltaTqCord;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidCoordinationDefautsAL4(void)
{
   /* F03_03_02_04_03_CoordinationDefautsAL4 */

   if (  (SftyMgt_bDgoDeltaTq != 0)
      || (SftyMgt_bDgoDeltaTqI != 0))
   {
      SftyMgt_bDgoDeltaTqCordAL4 = 1;
   }
   else
   {
      SftyMgt_bDgoDeltaTqCordAL4 = 0;
   }
   SftyMgt_bDgoDeltaTqCord = SftyMgt_bDgoDeltaTqCordAL4;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidIFTHENIntegraleSurcple                           */
/* !Description :  Le compteur est mis en marche lorsque SftyMgt_bSIPCoPt est */
/*                 égal à 1.  Le compteur  est remis à 0 lorsque              */
/*                 SftyMgt_bSIPCoPt est égal à 0.  On change de rapport cible */
/*                 (prise en compte calibrable).                              */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bSIPCoPt;                                           */
/*  input boolean SftyMgt_bNbTarGearChgTqI;                                   */
/*  output boolean SftyMgt_bEnaDftDeltaTqIRst;                                */
/*  output boolean SftyMgt_bEnaDftDeltaTqIRun;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidIFTHENIntegraleSurcple(void)
{
   boolean bLocalSftyMgt_bSIPCoPt;


   /* F03_03_02_03_01_01_IFTHENIntegraleSurcouple */

   VEMS_vidGET(SftyMgt_bSIPCoPt, bLocalSftyMgt_bSIPCoPt);
   if (  (bLocalSftyMgt_bSIPCoPt == 0)
      || (SftyMgt_bNbTarGearChgTqI != 0))
   {
      SftyMgt_bEnaDftDeltaTqIRst = 1;
      SftyMgt_bEnaDftDeltaTqIRun = 0;
   }
   else
   {
      SftyMgt_bEnaDftDeltaTqIRst = 0;
      SftyMgt_bEnaDftDeltaTqIRun = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidRAZIntegraleSurcouple                            */
/* !Description :  Compteur à 0                                               */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_027.01                                     */
/*                 VEMS_R_10_01251_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 SftyMgt_tqTiDeltaTqIRst;                                     */
/*  output sint16 SftyMgt_tqTiDeltaTqIRst;                                    */
/*  output sint16 SftyMgt_tqTiDeltaTqI;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidRAZIntegraleSurcouple(void)
{
   /* F03_03_02_03_01_02_RAZIntegraleSurcouple */
   SftyMgt_tqTiDeltaTqIRst = 0;
   SftyMgt_tqTiDeltaTqI = SftyMgt_tqTiDeltaTqIRst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidIntegraleSurcple                                 */
/* !Description :  Intégrale de surcouple.                                    */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_028.01                                     */
/*                 VEMS_R_10_01251_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_tqReqGBxCoPt;                                        */
/*  input sint16 SftyMgt_tqDrvRawCoPt;                                        */
/*  input boolean SftyMgt_bActDftDeltaTqIPos_C;                               */
/*  input sint16 SftyMgt_tqTiDeltaTqIRun;                                     */
/*  input sint16 SftyMgt_tqtiDftDeltaTqIMin_C;                                */
/*  input sint16 SftyMgt_tqtiDftDeltaTqIMax_C;                                */
/*  output sint16 SftyMgt_tqTiDeltaTqIRun;                                    */
/*  output sint16 SftyMgt_tqTiDeltaTqI;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidIntegraleSurcple(void)
{
   sint16 s16LocalSftyMgt_tqReqGBxCoPt;
   sint16 s16LocalSftyMgt_tqDrvRawCoPt;
   sint32 s32LocalDiff;
   sint32 s32LocalSftyMgt_tqTiDeltaTqIRun;


   /* F03_03_02_03_01_03_IntegraleSurcouple */

   VEMS_vidGET(SftyMgt_tqReqGBxCoPt, s16LocalSftyMgt_tqReqGBxCoPt);
   VEMS_vidGET(SftyMgt_tqDrvRawCoPt, s16LocalSftyMgt_tqDrvRawCoPt);

   s32LocalDiff = (sint32)( ( s16LocalSftyMgt_tqReqGBxCoPt
                            - s16LocalSftyMgt_tqDrvRawCoPt)
                          / 400);
   if (SftyMgt_bActDftDeltaTqIPos_C != 0)
   {
      s32LocalDiff = MATHSRV_udtMAX(s32LocalDiff, 0);
   }

   s32LocalSftyMgt_tqTiDeltaTqIRun = ( s32LocalDiff
                                     + SftyMgt_tqTiDeltaTqIRun);
   s32LocalSftyMgt_tqTiDeltaTqIRun =
      MATHSRV_udtCLAMP(s32LocalSftyMgt_tqTiDeltaTqIRun,
                       SftyMgt_tqtiDftDeltaTqIMin_C,
                       SftyMgt_tqtiDftDeltaTqIMax_C);
   SftyMgt_tqTiDeltaTqIRun =
      (sint16)MATHSRV_udtCLAMP(s32LocalSftyMgt_tqTiDeltaTqIRun, -1000, 1000);
   SftyMgt_tqTiDeltaTqI = SftyMgt_tqTiDeltaTqIRun;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/