/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCOMP                                                  */
/* !Description     : TQCOMP component.                                       */
/*                                                                            */
/* !Module          : TQCOMP                                                  */
/* !Description     : safety tms : comparer les couples.                      */
/*                                                                            */
/* !File            : TQCOMP_FCT1.C                                           */
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
/*   1 / TQCOMP_vidInitOutput                                                 */
/*   2 / TQCOMP_vidComparer_Couples                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5050623 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_1862 / 1.3                                      */
/* !OtherRefs   : VEMS V02 ECU#048269                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMP/TQCOMP_FCT1.C_v$*/
/* $Revision::   1.5.1.1  $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQCOMP.h"
#include "TQCOMP_L.h"
#include "TQCOMP_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMP_vidInitOutput                                       */
/* !Description :  fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoSftyTqComp;                                    */
/*  output boolean TQCOMP_bCondInPrev;                                        */
/*  output uint8 TQCOMP_u8tiDlyTqComp;                                        */
/*  output boolean SftyMgt_bZeroTqOn_MP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMP_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDgoSftyTqComp, 0);
   TQCOMP_bCondInPrev = 0;
   TQCOMP_u8tiDlyTqComp = 0;
   SftyMgt_bZeroTqOn_MP = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOMP_vidComparer_Couples                                 */
/* !Description :  Cette fonction a pour but de comparer le couple autorisé   */
/*                 issu de la coordination en couple avec le couple réalisé,  */
/*                 issu de l’estimateur.                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input sint16 SftyMgt_tqCkEngLimCord;                                      */
/*  input uint16 SftyMgt_tqIdcEngCurEstim;                                    */
/*  input boolean SftyMgt_bEnaTqOfsSfty;                                      */
/*  input boolean SftyMgt_bDgoTqCord;                                         */
/*  input boolean SftyMgt_bTqSysAcvTqSys;                                     */
/*  input uint16 SftyMgt_nErrThdSftyCompX_A[16];                              */
/*  input uint16 SftyMgt_tqErrThdSftyCompY_A[16];                             */
/*  input uint16 SftyMgt_tqErrThdSftyComp_M[16][16];                          */
/*  input uint16 SftyMgt_nOfsSftyComp_A[16];                                  */
/*  input uint16 SftyMgt_tqOfsSftyComp_T[16];                                 */
/*  input uint16 SftyMgt_tqOfsSftyComp_MP;                                    */
/*  input sint16 SftyMgt_tqErrTolZeroTq_C;                                    */
/*  input uint8 SftyMgt_tiRefDlyZeroTq_C;                                     */
/*  input sint16 SftyMgt_tqOfst0Tq_C;                                         */
/*  input uint8 SftyMgt_tiRefDly_C;                                           */
/*  input sint16 SftyMgt_tqIdcEngLimMax_MP;                                   */
/*  input uint16 SftyMgt_tqIdcEngRealMax_C;                                   */
/*  input boolean TQCOMP_bCondInPrev;                                         */
/*  input uint8 TQCOMP_u8tiDlyTqComp;                                         */
/*  output uint16 SftyMgt_tqOfsSftyComp_MP;                                   */
/*  output sint16 SftyMgt_tqIdcEngLimMax_MP;                                  */
/*  output boolean SftyMgt_bZeroTqOn_MP;                                      */
/*  output uint8 TQCOMP_u8tiDlyTqComp;                                        */
/*  output boolean SftyMgt_bDgoSftyTqComp;                                    */
/*  output boolean TQCOMP_bCondInPrev;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOMP_vidComparer_Couples(void)
{
   boolean bLocalCondIn;
   boolean bLocalEnaTqOfsSfty;
   boolean bLocalSftyMgt_bDgoSftyTqComp;
   boolean bLocalSftyMgtbDgoTqCord;
   boolean bLocalSftyMgtbTqSysAcvTqSysd;
   uint8   u8LocaltiDlyTqComp;
   uint8   u8LocalSftyMgt_tiRefDly;
   uint16  u16LocalIdcEngCurEstim;
   uint16  u16LocalCkEngLimCord;
   uint16  u16LocalInterpResult;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalParam;
   uint16  u16LocalCkFilBuf;
   uint16  u16LocalTqOfsSftyComp_MP;
   uint16  u16LocalSftyMgt_tqOfsSftyComp;
   sint16  s16LocalCkEngLimCord;
   sint16  s16LocalOutEngLimMax_MP;
   sint32  s32LocalCkEngLimCord;
   sint32  s32LocalEngLimCoMax_MP;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalCkFilBuf);
   VEMS_vidGET(SftyMgt_tqCkEngLimCord, s16LocalCkEngLimCord);
   VEMS_vidGET(SftyMgt_tqIdcEngCurEstim, u16LocalIdcEngCurEstim);
   VEMS_vidGET(SftyMgt_bEnaTqOfsSfty, bLocalEnaTqOfsSfty);
   VEMS_vidGET(SftyMgt_bDgoTqCord, bLocalSftyMgtbDgoTqCord);
   VEMS_vidGET(SftyMgt_bTqSysAcvTqSys, bLocalSftyMgtbTqSysAcvTqSysd);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nErrThdSftyCompX_A,
                                                u16LocalCkFilBuf,
                                                16);

   s32LocalCkEngLimCord = (sint32)(s16LocalCkEngLimCord + 32000);
   u16LocalCkEngLimCord = (uint16)MATHSRV_udtMAX(s32LocalCkEngLimCord, 0);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_tqErrThdSftyCompY_A,
                                                u16LocalCkEngLimCord,
                                                16);

   u16LocalInterpResult = MATHSRV_u16Interp2d(&SftyMgt_tqErrThdSftyComp_M[0][0],
                                              u16LocalParaX,
                                              u16LocalParaY,
                                              16);

   u16LocalParam = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nOfsSftyComp_A,
                                                u16LocalCkFilBuf,
                                                16);
   u16LocalSftyMgt_tqOfsSftyComp = MATHSRV_u16Interp1d(SftyMgt_tqOfsSftyComp_T,
                                                       u16LocalParam);
   SftyMgt_tqOfsSftyComp_MP =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqOfsSftyComp, 32000);

   if (bLocalEnaTqOfsSfty != 0)
   {
      u16LocalTqOfsSftyComp_MP = SftyMgt_tqOfsSftyComp_MP;
   }
   else
   {
      u16LocalTqOfsSftyComp_MP = 0;
   }

   s32LocalEngLimCoMax_MP = (sint32)( ( u16LocalInterpResult
                                      + u16LocalTqOfsSftyComp_MP)
                                    + (s16LocalCkEngLimCord - 32000));
   SftyMgt_tqIdcEngLimMax_MP = (sint16)MATHSRV_udtCLAMP(s32LocalEngLimCoMax_MP,
                                                        -32000,
                                                        32000);

   if (  (s16LocalCkEngLimCord <= SftyMgt_tqErrTolZeroTq_C)
      && (bLocalSftyMgtbTqSysAcvTqSysd != 0))
   {
      SftyMgt_bZeroTqOn_MP = 1;
      u8LocalSftyMgt_tiRefDly = SftyMgt_tiRefDlyZeroTq_C;
      s16LocalOutEngLimMax_MP = SftyMgt_tqOfst0Tq_C;
   }
   else
   {
      SftyMgt_bZeroTqOn_MP = 0;
      u8LocalSftyMgt_tiRefDly = SftyMgt_tiRefDly_C;
      s16LocalOutEngLimMax_MP =
         (sint16)MATHSRV_udtCLAMP(SftyMgt_tqIdcEngLimMax_MP,
                                  0,
                                  SftyMgt_tqIdcEngRealMax_C);
   }

   if (u16LocalIdcEngCurEstim > s16LocalOutEngLimMax_MP)
   {
      bLocalCondIn = 1;
   }
   else
   {
      bLocalCondIn = 0;
   }

   if (bLocalCondIn != 0)
   {
      if (TQCOMP_bCondInPrev == 0)
      {
         TQCOMP_u8tiDlyTqComp = (uint8)MATHSRV_udtMIN(u8LocalSftyMgt_tiRefDly,
                                                      100);
      }
      else
      {
         if (TQCOMP_u8tiDlyTqComp > 0)
         {
            u8LocaltiDlyTqComp = (uint8)(TQCOMP_u8tiDlyTqComp - 1);
            TQCOMP_u8tiDlyTqComp =
               (uint8)MATHSRV_udtMIN(u8LocaltiDlyTqComp, 100);
         }
      }
      if (TQCOMP_u8tiDlyTqComp == 0)
      {
         bLocalSftyMgt_bDgoSftyTqComp = 1;
      }
      else
      {
         bLocalSftyMgt_bDgoSftyTqComp = 0;
      }
   }
   else
   {
      bLocalSftyMgt_bDgoSftyTqComp = 0;
   }

   if (  (bLocalSftyMgtbDgoTqCord != 0)
      || (bLocalSftyMgt_bDgoSftyTqComp !=0))
   {
      VEMS_vidSET(SftyMgt_bDgoSftyTqComp, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoSftyTqComp, 0);
   }

   TQCOMP_bCondInPrev = bLocalCondIn;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/