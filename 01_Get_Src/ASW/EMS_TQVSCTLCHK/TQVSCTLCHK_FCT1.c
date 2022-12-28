/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQVSCTLCHK                                              */
/* !Description     : TQVSCTLCHK Component                                    */
/*                                                                            */
/* !Module          : TQVSCTLCHK                                              */
/* !Description     : SAFETY TMS : SECURISER RVV                              */
/*                                                                            */
/* !File            : TQVSCTLCHK_FCT1.C                                       */
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
/*   1 / TQVSCTLCHK_vidInitOutput                                             */
/*   2 / TQVSCTLCHK_vidDesacRVVAppuiFrein                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 01190 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2401 / 1.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQVSCTLCHK/TQVSCTLCHK_$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQVSCTLCHK.h"
#include "TQVSCTLCHK_L.h"
#include "TQVSCTLCHK_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQVSCTLCHK_vidInitOutput                                   */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDeac0TqVSCtl;                                     */
/*  output boolean SftyMgt_bDgoVSCtl;                                         */
/*  output uint16 TQCKEFCFIL_u16BrkPedPressCounter;                           */
/*  output uint16 TQCKEFCFIL_u16TqVSCtl_Counter;                              */
/*  output boolean SftyMgt_bDftBrkPedPress_MP;                                */
/*  output boolean SftyMgt_bDftTqVSCtl_MP;                                    */
/*  output sint16 SftyMgt_tqCkEfc_MP;                                         */
/*  output sint16 SftyMgt_tqEfcVSCtlSum_MP;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQVSCTLCHK_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDeac0TqVSCtl, 0);
   VEMS_vidSET(SftyMgt_bDgoVSCtl, 0);
   TQCKEFCFIL_u16BrkPedPressCounter = 0;
   TQCKEFCFIL_u16TqVSCtl_Counter = 0;
   SftyMgt_bDftBrkPedPress_MP =0;
   SftyMgt_bDftTqVSCtl_MP = 0;
   SftyMgt_tqCkEfc_MP = 0;
   SftyMgt_tqEfcVSCtlSum_MP = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQVSCTLCHK_vidDesacRVVAppuiFrein                           */
/* !Description :  Elle intègre la consigne de couple RVV dans la chaîne en   */
/*                 couple en appliquant un max entre la couple conducteur     */
/*                 issue du bloc amont et la consigne de couple RVV.          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SftyMgt_stTqPTMinCtlVSCtl;                                    */
/*  input sint16 SftyMgt_tqCkEfcMinVSCtl;                                     */
/*  input sint16 SftyMgt_tqCkEfcTqDem;                                        */
/*  input sint16 SftyMgt_tqCkEfcMaxVSCtl;                                     */
/*  input boolean SftyMgt_bBrkPedPrss;                                        */
/*  input sint16 SftyMgt_tqLimEM;                                             */
/*  input uint8 SftyMgt_stAcvEfcTqPTMinVSCtl_C;                               */
/*  input uint8 SftyMgt_stAcvNotEfcTqPTMin_C;                                 */
/*  input boolean SftyMgt_bInhAcvNotEfcTqPTMin_C;                             */
/*  input sint16 SftyMgt_tqCkEfcThdVSCtl_C;                                   */
/*  input boolean SftyMgt_bTypTqVSCtl_C;                                      */
/*  input sint16 SftyMgt_tqCkEfc_MP;                                          */
/*  input sint16 SftyMgt_tqOfsDftVSCtl_C;                                     */
/*  input sint16 SftyMgt_tqEfcReqCoVSCtl;                                     */
/*  input sint16 SftyMgt_tqEfcVSCtlSum_MP;                                    */
/*  input uint8 SftyMgt_tiDlyOnDftVSCtl_C;                                    */
/*  input uint16 TQCKEFCFIL_u16BrkPedPressCounter;                            */
/*  input uint8 SftyMgt_tiDlyOnDftTqVSCtl_C;                                  */
/*  input uint16 TQCKEFCFIL_u16TqVSCtl_Counter;                               */
/*  input boolean SftyMgt_bInhDftBrkPedPress_C;                               */
/*  input boolean SftyMgt_bDftBrkPedPress_MP;                                 */
/*  input boolean SftyMgt_bInhDftTqVSCtl_C;                                   */
/*  input boolean SftyMgt_bDftTqVSCtl_MP;                                     */
/*  output boolean SftyMgt_bDeac0TqVSCtl;                                     */
/*  output sint16 SftyMgt_tqCkEfc_MP;                                         */
/*  output sint16 SftyMgt_tqEfcVSCtlSum_MP;                                   */
/*  output uint16 TQCKEFCFIL_u16BrkPedPressCounter;                           */
/*  output boolean SftyMgt_bDftBrkPedPress_MP;                                */
/*  output uint16 TQCKEFCFIL_u16TqVSCtl_Counter;                              */
/*  output boolean SftyMgt_bDftTqVSCtl_MP;                                    */
/*  output boolean SftyMgt_bDgoVSCtl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQVSCTLCHK_vidDesacRVVAppuiFrein(void)
{
   boolean bLocalSftyMgt_bDgoVSCtl;
   boolean bLocalSwitch1;
   boolean bLocalSwitch2;
   boolean bLocalCondition;
   boolean bLocalCondition_TD1;
   boolean bLocalCondition_TD2;
   boolean bLocalSftyMgt_bDeac0TqVSCtl;
   boolean bLocalSftyMgt_bBrkPedPrss;
   uint8   u8LocalSftyMgt_stTqPTMinCtlVSCtl;
   uint16  u16LocalSumTurnOnDelaySimple;
   uint16  u16LocalMinTurnOnDelaySimple;
   sint16  s16LocalSftyMgt_tqCkEfcMinVSCtl;
   sint16  s16LocalSftyMgt_tqEfcReqCoVSCtl;
   sint16  s16LocalSftyMgt_tqCkEfcTqDem;
   sint16  s16LocalSftyMgt_tqCkEfcMaxVSCtl;
   sint16  s16LocalSftyMgt_tqCkEfc_MP;
   sint16  s16LocalSftyMgt_tqLimEM;
   sint32  s32LocalSum;


   VEMS_vidGET(SftyMgt_stTqPTMinCtlVSCtl, u8LocalSftyMgt_stTqPTMinCtlVSCtl);
   VEMS_vidGET(SftyMgt_tqCkEfcMinVSCtl, s16LocalSftyMgt_tqCkEfcMinVSCtl);
   VEMS_vidGET(SftyMgt_tqCkEfcTqDem, s16LocalSftyMgt_tqCkEfcTqDem);
   VEMS_vidGET(SftyMgt_tqCkEfcMaxVSCtl, s16LocalSftyMgt_tqCkEfcMaxVSCtl);
   VEMS_vidGET(SftyMgt_bBrkPedPrss, bLocalSftyMgt_bBrkPedPrss);
   VEMS_vidGET(SftyMgt_tqLimEM, s16LocalSftyMgt_tqLimEM);

   if (  (u8LocalSftyMgt_stTqPTMinCtlVSCtl == SftyMgt_stAcvEfcTqPTMinVSCtl_C)
      || (u8LocalSftyMgt_stTqPTMinCtlVSCtl == SftyMgt_stAcvNotEfcTqPTMin_C))
   {
      bLocalCondition =1;
   }
   else
   {
      bLocalCondition =0;
   }
   if (SftyMgt_bInhAcvNotEfcTqPTMin_C != 0)
   {
      if (u8LocalSftyMgt_stTqPTMinCtlVSCtl == SftyMgt_stAcvEfcTqPTMinVSCtl_C)
      {
         bLocalSftyMgt_bDeac0TqVSCtl =1;
      }
      else
      {
         bLocalSftyMgt_bDeac0TqVSCtl =0;
      }
   }
   else
   {
      bLocalSftyMgt_bDeac0TqVSCtl = bLocalCondition;
   }
   VEMS_vidSET(SftyMgt_bDeac0TqVSCtl, bLocalSftyMgt_bDeac0TqVSCtl);

   if (  (bLocalSftyMgt_bBrkPedPrss != 0)
      && (  (bLocalCondition != 0)
         || (SftyMgt_tqCkEfcThdVSCtl_C < s16LocalSftyMgt_tqCkEfcMinVSCtl)))
   {
      bLocalCondition_TD1 = 1;
   }
   else
   {
      bLocalCondition_TD1 = 0;
   }
   s16LocalSftyMgt_tqCkEfc_MP =
      (sint16)MATHSRV_udtMAX(s16LocalSftyMgt_tqCkEfcMinVSCtl,
                             s16LocalSftyMgt_tqCkEfcTqDem);
   s16LocalSftyMgt_tqCkEfc_MP =
      (sint16)MATHSRV_udtMIN(s16LocalSftyMgt_tqCkEfc_MP,
                             s16LocalSftyMgt_tqCkEfcMaxVSCtl);
   SftyMgt_tqCkEfc_MP = (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqCkEfc_MP,
                                                 -32000,
                                                 32000);
   if (SftyMgt_bTypTqVSCtl_C != 0)
   {
      s32LocalSum = (sint32)(SftyMgt_tqCkEfc_MP + SftyMgt_tqOfsDftVSCtl_C);
   }
   else
   {
      VEMS_vidGET(SftyMgt_tqEfcReqCoVSCtl, s16LocalSftyMgt_tqEfcReqCoVSCtl);
      s32LocalSum = (sint32)( s16LocalSftyMgt_tqEfcReqCoVSCtl
                            + SftyMgt_tqOfsDftVSCtl_C);
   }
   SftyMgt_tqEfcVSCtlSum_MP = (sint16)MATHSRV_udtCLAMP(s32LocalSum,
                                                       -32000,
                                                       32000);

   if (s16LocalSftyMgt_tqLimEM > SftyMgt_tqEfcVSCtlSum_MP)
   {
      bLocalCondition_TD2 =1;
   }
   else
   {
      bLocalCondition_TD2 =0;
   }

   /* Turn On Delay TMS */
   u16LocalSumTurnOnDelaySimple = (uint16)(SftyMgt_tiDlyOnDftVSCtl_C + 1);
   u16LocalMinTurnOnDelaySimple =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16BrkPedPressCounter,
                             u16LocalSumTurnOnDelaySimple);
   if (bLocalCondition_TD1 == 0)
   {
      TQCKEFCFIL_u16BrkPedPressCounter = 0;
   }
   else
   {
      TQCKEFCFIL_u16BrkPedPressCounter =
         (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   if (TQCKEFCFIL_u16BrkPedPressCounter >= u16LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDftBrkPedPress_MP = 1;
   }
   else
   {
      SftyMgt_bDftBrkPedPress_MP = 0;
   }

   /* Turn On Delay TMS */
   u16LocalSumTurnOnDelaySimple = (uint16)(SftyMgt_tiDlyOnDftTqVSCtl_C + 1);
   u16LocalMinTurnOnDelaySimple =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16TqVSCtl_Counter,
                             u16LocalSumTurnOnDelaySimple);
   if (bLocalCondition_TD2 == 0)
   {
      TQCKEFCFIL_u16TqVSCtl_Counter = 0;
   }
   else
   {
      TQCKEFCFIL_u16TqVSCtl_Counter =
            (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   if (TQCKEFCFIL_u16TqVSCtl_Counter >= u16LocalSumTurnOnDelaySimple)
   {
      SftyMgt_bDftTqVSCtl_MP = 1;
   }
   else
   {
      SftyMgt_bDftTqVSCtl_MP = 0;
   }

   if (SftyMgt_bInhDftBrkPedPress_C != 0)
   {
      bLocalSwitch1 = 0;
   }
   else
   {
      bLocalSwitch1 = SftyMgt_bDftBrkPedPress_MP;
   }
   if (SftyMgt_bInhDftTqVSCtl_C != 0)
   {
      bLocalSwitch2 = 0;
   }
   else
   {
      bLocalSwitch2 = SftyMgt_bDftTqVSCtl_MP;
   }
   if (  (bLocalSwitch1 != 0)
      || (bLocalSwitch2 != 0))
   {
      bLocalSftyMgt_bDgoVSCtl = 1;
   }
   else
   {
      bLocalSftyMgt_bDgoVSCtl = 0;
   }
   VEMS_vidSET(SftyMgt_bDgoVSCtl, bLocalSftyMgt_bDgoVSCtl);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/