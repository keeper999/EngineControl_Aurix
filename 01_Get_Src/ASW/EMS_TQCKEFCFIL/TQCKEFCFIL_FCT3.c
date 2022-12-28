/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCKEFCFIL                                              */
/* !Description     : TQCKEFCFIL Component                                    */
/*                                                                            */
/* !Module          : TQCKEFCFIL                                              */
/* !Description     : SAFETY TMS : VALIDER AGRÉMENT PRÉVENTIF                 */
/*                                                                            */
/* !File            : TQCKEFCFIL_FCT3.C                                       */
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
/*   1 / TQCKEFCFIL_vidValidation                                             */
/*   2 / TQCKEFCFIL_vidValidtqCkEfcFil                                        */
/*   3 / TQCKEFCFIL_vidCalcDrivFilOutRnge                                     */
/*   4 / TQCKEFCFIL_vidDbnceDeftTqDrivFil                                     */
/*   5 / TQCKEFCFIL_vidCalcCntDecIPOutRng                                     */
/*   6 / TQCKEFCFIL_vidDbncDfDrvFilDcIPCn                                     */
/*   7 / TQCKEFCFIL_vidCalcDecAcvOutOfRng                                     */
/*   8 / TQCKEFCFIL_vidDebounceDeftDecAcv                                     */
/*   9 / TQCKEFCFIL_vidSyntheseDefTqCkEfc                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01236 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#056922                                         */
/* !OtherRefs   : CSCT_CGMT09_2398 / 2.6                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKEFCFIL/TQCKEFCFIL_$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQCKEFCFIL.h"
#include "TQCKEFCFIL_L.h"
#include "TQCKEFCFIL_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidValidation                                   */
/* !Description :  Valide le couple et le temps d’activation du filtrage en   */
/*                 décélération du niveau 1 par rapports aux seuils de couple */
/*                 et de temps permissible maximum calculés. Sors le défaut et*/
/*                 le flux de couple en sortie agrément préventif du niveau 1 */
/*                 sécurisé.                                                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_018.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidValidtqCkEfcFil();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidValidation(void)
{
   TQCKEFCFIL_vidValidtqCkEfcFil();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidValidtqCkEfcFil                              */
/* !Description :  Fonction de gestion de generation des défauts relatifs à la*/
/*                 phase de décélération                                      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_019.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidCalcDrivFilOutRnge();                      */
/*  extf argret void TQCKEFCFIL_vidDbnceDeftTqDrivFil();                      */
/*  extf argret void TQCKEFCFIL_vidCalcCntDecIPOutRng();                      */
/*  extf argret void TQCKEFCFIL_vidDbncDfDrvFilDcIPCn();                      */
/*  extf argret void TQCKEFCFIL_vidCalcDecAcvOutOfRng();                      */
/*  extf argret void TQCKEFCFIL_vidDebounceDeftDecAcv();                      */
/*  extf argret void TQCKEFCFIL_vidSyntheseDefTqCkEfc();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidValidtqCkEfcFil(void)
{
   TQCKEFCFIL_vidCalcDrivFilOutRnge();
   TQCKEFCFIL_vidDbnceDeftTqDrivFil();
   TQCKEFCFIL_vidCalcCntDecIPOutRng();
   TQCKEFCFIL_vidDbncDfDrvFilDcIPCn();
   TQCKEFCFIL_vidCalcDecAcvOutOfRng();
   TQCKEFCFIL_vidDebounceDeftDecAcv();
   TQCKEFCFIL_vidSyntheseDefTqCkEfc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcDrivFilOutRnge                           */
/* !Description :  Compare le couple niveau 1 en sortie agrément préventif au */
/*                 couple permissible maximum. Sort un défaut.                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_tqErrDrivFilThd_C;                                   */
/*  input sint16 SftyMgt_tqCkEfcFilTol;                                       */
/*  input sint16 SftyMgt_tqCkEfcFilTqSys;                                     */
/*  output boolean SftyMgt_bDrivFilTqInvld;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcDrivFilOutRnge(void)
{
   /*F02_01_01_calculTqDrivFilOutOfRange*/
   sint16 s16LocalSftyMgttqCkEfcFilTqSys;
   sint32 s32LocalSum;


   s32LocalSum = (sint32)(SftyMgt_tqErrDrivFilThd_C + SftyMgt_tqCkEfcFilTol);
   VEMS_vidGET(SftyMgt_tqCkEfcFilTqSys, s16LocalSftyMgttqCkEfcFilTqSys);
   if (s32LocalSum < s16LocalSftyMgttqCkEfcFilTqSys)
   {
      SftyMgt_bDrivFilTqInvld = 1;
   }
   else
   {
      SftyMgt_bDrivFilTqInvld = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidDbnceDeftTqDrivFil                           */
/* !Description :  Débounce le défaut sur le couple.                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDgoTqDrivFil_C;                                 */
/*  input uint8 SftyMgt_tiDlyOnDgoTqDrivFil_C;                                */
/*  input boolean SftyMgt_bDrivFilTqInvld;                                    */
/*  input uint8 TQCKEFCFIL_u8tiDlyOnDgoCounter;                               */
/*  output boolean SftyMgt_bDgoDrivFilTq;                                     */
/*  output uint8 TQCKEFCFIL_u8tiDlyOnDgoCounter;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidDbnceDeftTqDrivFil(void)
{
   uint8 u8LocalMinTurnOnDelaySimple;
   uint8 u8LocaltiDlyOnDgoCounter;


   if (SftyMgt_bInhDgoTqDrivFil_C != 0)
   {
      SftyMgt_bDgoDrivFilTq = 0;
   }
   else
   {
      u8LocaltiDlyOnDgoCounter = (uint8)( ( SftyMgt_tiDlyOnDgoTqDrivFil_C
                                          + 6)
                                        / 4);

      if (SftyMgt_bDrivFilTqInvld == 0)
      {
         u8LocalMinTurnOnDelaySimple = 0;
      }
      else
      {
         u8LocalMinTurnOnDelaySimple =
            (uint8)MATHSRV_udtMIN(TQCKEFCFIL_u8tiDlyOnDgoCounter,
                                  u8LocaltiDlyOnDgoCounter);
         u8LocalMinTurnOnDelaySimple = (uint8)(u8LocalMinTurnOnDelaySimple + 1);
      }
      TQCKEFCFIL_u8tiDlyOnDgoCounter =  u8LocalMinTurnOnDelaySimple;

      if (u8LocalMinTurnOnDelaySimple >= u8LocaltiDlyOnDgoCounter)
      {
         SftyMgt_bDgoDrivFilTq = 1;
      }
      else
      {
         SftyMgt_bDgoDrivFilTq = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcCntDecIPOutRng                           */
/* !Description :  Comparaison du compteur avec le délai maximum permissible  */
/*                 d’activation du filtrage en décélération. Remonte un       */
/*                 défaut.                                                    */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_tiOfsDrivFilDeceIpThd_C;                             */
/*  input uint16 SftyMgt_tiDlyDrivFilDeceTotTol;                              */
/*  input uint16 SftyMgt_tiDrivFilDeceIpCnt;                                  */
/*  output boolean SftyMgt_bDrivFilDeceIpCntInvld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcCntDecIPOutRng(void)
{
   uint16 u16LocaltiOfsDrivFilDeceIpThd;
   uint32 u32LocalSum;


   u16LocaltiOfsDrivFilDeceIpThd =
      (uint16)((SftyMgt_tiOfsDrivFilDeceIpThd_C + 2) / 4);
   u32LocalSum = ( SftyMgt_tiDlyDrivFilDeceTotTol
                 + u16LocaltiOfsDrivFilDeceIpThd);
   if (SftyMgt_tiDrivFilDeceIpCnt > u32LocalSum)
   {
      SftyMgt_bDrivFilDeceIpCntInvld = 1;
   }
   else
   {
      SftyMgt_bDrivFilDeceIpCntInvld = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidDbncDfDrvFilDcIPCn                           */
/* !Description :  Débounce le défaut sur le temps maximal permissible en     */
/*                 phase d’activation de filtrage de dédélération.            */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDgoFilIpCnt_C;                                  */
/*  input uint8 SftyMgt_tiDlyOnDgoFilIpCnt_C;                                 */
/*  input boolean SftyMgt_bDrivFilDeceIpCntInvld;                             */
/*  input uint8 TQCKEFCFIL_u8tiDlyOnDgoIpCounter;                             */
/*  output boolean SftyMgt_bDgoDrivFilDeceIpCnt;                              */
/*  output uint8 TQCKEFCFIL_u8tiDlyOnDgoIpCounter;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidDbncDfDrvFilDcIPCn(void)
{
   /*F02_01_04_debounceDefautDrivFilDeceIPCnt*/
   uint8 u8LocaltiDlyOnDgoCounter;
   uint8 u8LocalMinTurnOnDelaySimple;


   if (SftyMgt_bInhDgoFilIpCnt_C != 0)
   {
      SftyMgt_bDgoDrivFilDeceIpCnt = 0;
   }
   else
   {
      u8LocaltiDlyOnDgoCounter = (uint8)( ( SftyMgt_tiDlyOnDgoFilIpCnt_C
                                          + 6)
                                        / 4);
      if (SftyMgt_bDrivFilDeceIpCntInvld == 0)
      {
         u8LocalMinTurnOnDelaySimple = 0;
      }
      else
      {
         u8LocalMinTurnOnDelaySimple =
            (uint8)MATHSRV_udtMIN(TQCKEFCFIL_u8tiDlyOnDgoIpCounter,
                                  u8LocaltiDlyOnDgoCounter);
         u8LocalMinTurnOnDelaySimple = (uint8)( u8LocalMinTurnOnDelaySimple
                                              + 1);
      }
      TQCKEFCFIL_u8tiDlyOnDgoIpCounter = u8LocalMinTurnOnDelaySimple;

      if (u8LocalMinTurnOnDelaySimple >= u8LocaltiDlyOnDgoCounter)
      {
         SftyMgt_bDgoDrivFilDeceIpCnt = 1;
      }
      else
      {
         SftyMgt_bDgoDrivFilDeceIpCnt = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcDecAcvOutOfRng                           */
/* !Description :  Reconstruction de l’activation de la décélération au niv 2 */
/*                 et comparaison au niv1. Si l’activation est confirmée au   */
/*                 niv2 mais non active au niv 1 au niv1 on remonte au défaut.*/
/* !Number      :  FCT3.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_024.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_rAccP;                                               */
/*  input uint16 SftyMgt_rAccPThdTqCll_C;                                     */
/*  input sint16 SftyMgt_tqCkEfcFilTqSys;                                     */
/*  input boolean SftyMgt_bDeac0TqVSCtl;                                      */
/*  input sint16 SftyMgt_tqOfsTqCkEfcFilThd_C;                                */
/*  input boolean SftyMgt_bAcvCllTqCll;                                       */
/*  input sint16 SftyMgt_tqLimEM;                                             */
/*  input boolean SftyMgt_bAccPThdTqCll_MP;                                   */
/*  input boolean SftyMgt_bDeceAcv_MP;                                        */
/*  input boolean SftyMgt_bDrivFilDeceIp;                                     */
/*  output boolean SftyMgt_bAccPThdTqCll_MP;                                  */
/*  output boolean SftyMgt_bDeceAcv_MP;                                       */
/*  output boolean SftyMgt_bDrivFilDeceAcvInvld;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcDecAcvOutOfRng(void)
{
   /*F02_01_05_calculDeceAcvOutOfRange*/
   boolean  bLocalSftyMgtbDeac0TqVSCtl;
   boolean  bLocalSftyMgt_bAcvCllTqCll;
   sint16   s16LocalSftyMgt_tqCkEfcFilTqSys;
   sint16   s16LocalSftyMgt_tqLimEM;
   uint16   u16LocalSftyMgt_rAccP;
   sint32   s32LocalDiv;


   VEMS_vidGET(SftyMgt_rAccP, u16LocalSftyMgt_rAccP);
   if (u16LocalSftyMgt_rAccP <= SftyMgt_rAccPThdTqCll_C)
   {
      SftyMgt_bAccPThdTqCll_MP = 1;
   }
   else
   {
      SftyMgt_bAccPThdTqCll_MP = 0;
   }
   VEMS_vidGET(SftyMgt_tqCkEfcFilTqSys, s16LocalSftyMgt_tqCkEfcFilTqSys);
   VEMS_vidGET(SftyMgt_bDeac0TqVSCtl, bLocalSftyMgtbDeac0TqVSCtl);
   s32LocalDiv = (sint32)( s16LocalSftyMgt_tqCkEfcFilTqSys
                         - SftyMgt_tqOfsTqCkEfcFilThd_C);

   VEMS_vidGET(SftyMgt_bAcvCllTqCll, bLocalSftyMgt_bAcvCllTqCll);
   VEMS_vidGET(SftyMgt_tqLimEM, s16LocalSftyMgt_tqLimEM);

   if (  (s32LocalDiv >= s16LocalSftyMgt_tqLimEM)
      && (  (bLocalSftyMgt_bAcvCllTqCll != 0)
         || (  (SftyMgt_bAccPThdTqCll_MP != 0)
            && (bLocalSftyMgtbDeac0TqVSCtl == 0))))
   {
      SftyMgt_bDeceAcv_MP = 1;
   }
   else
   {
      SftyMgt_bDeceAcv_MP = 0;
   }

   if (  (SftyMgt_bDeceAcv_MP != 0)
      && (SftyMgt_bDrivFilDeceIp == 0))
   {
      SftyMgt_bDrivFilDeceAcvInvld = 1;
   }
   else
   {
      SftyMgt_bDrivFilDeceAcvInvld = 0;
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidDebounceDeftDecAcv                           */
/* !Description :  Débounce le défaut sur la détection de la phase            */
/*                 d’activation de filtrage de décélération.                  */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_025.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDgoDeceAcv_C;                                   */
/*  input uint8 SftyMgt_tiDlyOnDgoFilInvld_C;                                 */
/*  input boolean SftyMgt_bDrivFilDeceAcvInvld;                               */
/*  input uint8 TQCKEFCFIL_u8DlyOnDgoInvdCounter;                             */
/*  output boolean SftyMgt_bDgoDrivFilDeceAcv;                                */
/*  output uint8 TQCKEFCFIL_u8DlyOnDgoInvdCounter;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidDebounceDeftDecAcv(void)
{
   uint8 u8LocaltiDlyOnDgoCounter;
   uint8 u8LocalMinTurnOnDelaySimple;


   if (SftyMgt_bInhDgoDeceAcv_C != 0)
   {
      SftyMgt_bDgoDrivFilDeceAcv = 0;
   }
   else
   {
      u8LocaltiDlyOnDgoCounter = (uint8)( ( SftyMgt_tiDlyOnDgoFilInvld_C
                                          + 6)
                                        / 4);
      if (SftyMgt_bDrivFilDeceAcvInvld == 0)
      {
         u8LocalMinTurnOnDelaySimple = 0;
      }
      else
      {
         u8LocalMinTurnOnDelaySimple =
            (uint8)MATHSRV_udtMIN(TQCKEFCFIL_u8DlyOnDgoInvdCounter,
                                  u8LocaltiDlyOnDgoCounter);
         u8LocalMinTurnOnDelaySimple = (uint8)( u8LocalMinTurnOnDelaySimple
                                              + 1);
      }
      TQCKEFCFIL_u8DlyOnDgoInvdCounter = u8LocalMinTurnOnDelaySimple;

      if (u8LocalMinTurnOnDelaySimple >= u8LocaltiDlyOnDgoCounter)
      {
         SftyMgt_bDgoDrivFilDeceAcv = 1;
      }
      else
      {
         SftyMgt_bDgoDrivFilDeceAcv = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidSyntheseDefTqCkEfc                           */
/* !Description :  Fonction qui coordonne les défauts                         */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_026.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoDrivFilTq;                                      */
/*  input boolean SftyMgt_bDgoDrivFilDeceIpCnt;                               */
/*  input boolean SftyMgt_bDgoDrivFilDeceAcv;                                 */
/*  output boolean SftyMgt_bDgoTqCkEfcFil;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidSyntheseDefTqCkEfc(void)
{
   if (  (SftyMgt_bDgoDrivFilTq != 0)
      || (SftyMgt_bDgoDrivFilDeceIpCnt != 0)
      || (SftyMgt_bDgoDrivFilDeceAcv != 0))
   {
      VEMS_vidSET(SftyMgt_bDgoTqCkEfcFil, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoTqCkEfcFil, 0);
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/