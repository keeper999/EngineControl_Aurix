/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LIHCHK                                                  */
/* !Description     : LIHCHK Component                                        */
/*                                                                            */
/* !Module          : LIHCHK                                                  */
/* !Description     : Safety TMS :SECURISER LE LIMP HOME                      */
/*                                                                            */
/* !File            : LIHCHK_FCT1.C                                           */
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
/*   1 / LIHCHK_vidInitOutput                                                 */
/*   2 / LIHCHK_vidValider_Limp_Home                                          */
/*   3 / LIHCHK_vidDeterminer_Limitation                                      */
/*   4 / LIHCHK_vidValider_Limitation                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 01261 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2403 / 1.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/LIHCHK/LIHCHK_FCT1.C_v$*/
/* $Revision::   1.2.1.0  $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "LIHCHK.h"
#include "LIHCHK_L.h"
#include "LIHCHK_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LIHCHK_vidInitOutput                                       */
/* !Description :  initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoLih;                                           */
/*  output boolean SftyMgt_bRcvMonRunLih;                                     */
/*  output boolean LIHCHK_bTurnOnDelayInPrev;                                 */
/*  output uint8 LIHCHK_u8TurnOnDelayCnt;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LIHCHK_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDgoLih, 0);
   VEMS_vidSET(SftyMgt_bRcvMonRunLih, 0);
   LIHCHK_bTurnOnDelayInPrev = 0;
   LIHCHK_u8TurnOnDelayCnt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LIHCHK_vidValider_Limp_Home                                */
/* !Description :  Cette fonction sécurise l’application des limitations de   */
/*                 régime qui sont demandées dans certains modes dégradés     */
/*                 moteur.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01261_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void LIHCHK_vidDeterminer_Limitation();                       */
/*  extf argret void LIHCHK_vidValider_Limitation();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LIHCHK_vidValider_Limp_Home(void)
{
   LIHCHK_vidDeterminer_Limitation();
   LIHCHK_vidValider_Limitation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LIHCHK_vidDeterminer_Limitation                            */
/* !Description :  Cette fonction génère deux informations : une première     */
/*                 information, indique si une limitation de régime est en    */
/*                 cours , la deuxième détermine le niveau de limitation      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01261_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bEngSpdLimHiIntvFRM;                                */
/*  input boolean SftyMgt_bEngSpdLimLoIntvFRM;                                */
/*  input uint8 SftyMgt_noGearCord;                                           */
/*  input uint8 SftyMgt_noGearCord_A[8];                                      */
/*  input uint16 SftyMgt_nEngSpdLimLoThd_T[8];                                */
/*  input uint16 SftyMgt_nEngSpdLimHiThd_T[8];                                */
/*  output boolean SftyMgt_bRcvMonRunLih;                                     */
/*  output uint16 SftyMgt_nEngLim;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LIHCHK_vidDeterminer_Limitation(void)
{
   boolean bLocalSftyMgt_bEngSpdLimHiIntFRM;
   boolean bLocalSftyMgt_bEngSpdLimLoIntFRM;
   boolean blocalSftyMgt_bRcvMonRunLih;
   uint8   u8LocalSftyMgt_noGearCord;
   uint8   u8LocalIdx;
   uint8   u8LocalIdxMap;
   uint16  u16LocalInterp1d;


   VEMS_vidGET(SftyMgt_bEngSpdLimHiIntvFRM, bLocalSftyMgt_bEngSpdLimHiIntFRM);
   VEMS_vidGET(SftyMgt_bEngSpdLimLoIntvFRM, bLocalSftyMgt_bEngSpdLimLoIntFRM);
   VEMS_vidGET(SftyMgt_noGearCord, u8LocalSftyMgt_noGearCord);
   if (  (bLocalSftyMgt_bEngSpdLimHiIntFRM !=0)
      || (bLocalSftyMgt_bEngSpdLimLoIntFRM !=0) )
   {
      blocalSftyMgt_bRcvMonRunLih= 1;
   }
   else
   {
      blocalSftyMgt_bRcvMonRunLih= 0;
   }
   VEMS_vidSET(SftyMgt_bRcvMonRunLih, blocalSftyMgt_bRcvMonRunLih);
   u8LocalIdx = (uint8)MATHSRV_udtMIN(u8LocalSftyMgt_noGearCord, 7);
   u8LocalIdxMap = (uint8)MATHSRV_udtMIN(SftyMgt_noGearCord_A[u8LocalIdx], 7);
   if (bLocalSftyMgt_bEngSpdLimLoIntFRM !=0)
   {
      u16LocalInterp1d = SftyMgt_nEngSpdLimLoThd_T[u8LocalIdxMap];
   }
   else
   {
      if (bLocalSftyMgt_bEngSpdLimHiIntFRM !=0)
      {
         u16LocalInterp1d = SftyMgt_nEngSpdLimHiThd_T[u8LocalIdxMap];
      }
      else
      {
         u16LocalInterp1d = 32000;
      }
   }
   SftyMgt_nEngLim = (uint16)MATHSRV_udtMIN(u16LocalInterp1d, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LIHCHK_vidValider_Limitation                               */
/* !Description :  Cette fonction vérifie que le régime reste inférieur à la  */
/*                 limitation plus un seuil.                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_01261_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_nCkFil;                                              */
/*  input uint8 SftyMgt_noAcvCyl;                                             */
/*  input uint16 SftyMgt_nEngLim;                                             */
/*  input uint16 SftyMgt_nEngLimThd_C;                                        */
/*  input uint8 LIHCHK_u8TurnOnDelayCnt;                                      */
/*  input boolean LIHCHK_bTurnOnDelayInPrev;                                  */
/*  input uint8 SftyMgt_tiDlyDgoEngLim_C;                                     */
/*  output uint8 LIHCHK_u8TurnOnDelayCnt;                                     */
/*  output boolean SftyMgt_bDgoLih;                                           */
/*  output boolean LIHCHK_bTurnOnDelayInPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LIHCHK_vidValider_Limitation(void)
{
   boolean bLocalTurnOnDelayIn;
   boolean bLocalSftyMgt_bDgoLih;
   uint8   u8LocalSftyMgt_noAcvCyl;
   uint16  u16LocalSftyMgt_nCkFil;
   uint32  u32LocalSftyMgt_nEngLim;
   uint8   u8LocalTurnOnDelayCnt;


   VEMS_vidGET(SftyMgt_nCkFil, u16LocalSftyMgt_nCkFil);
   VEMS_vidGET(SftyMgt_noAcvCyl, u8LocalSftyMgt_noAcvCyl);

   u32LocalSftyMgt_nEngLim = SftyMgt_nEngLim + SftyMgt_nEngLimThd_C;

   if (  ((uint32)u16LocalSftyMgt_nCkFil > u32LocalSftyMgt_nEngLim)
      && (u8LocalSftyMgt_noAcvCyl !=0))
   {
      bLocalTurnOnDelayIn = 1;
   }
   else
   {
      bLocalTurnOnDelayIn = 0;
   }
   u8LocalTurnOnDelayCnt = LIHCHK_u8TurnOnDelayCnt;
   if (bLocalTurnOnDelayIn != 0)
   {
      if (LIHCHK_bTurnOnDelayInPrev == 0)
      {
         u8LocalTurnOnDelayCnt = SftyMgt_tiDlyDgoEngLim_C;
      }
      else
      {
         if (u8LocalTurnOnDelayCnt > 0)
         {
            u8LocalTurnOnDelayCnt =
                (uint8)(u8LocalTurnOnDelayCnt - 1);
         }
      }
      if (u8LocalTurnOnDelayCnt == 0)
      {
         bLocalSftyMgt_bDgoLih = 1;
      }
      else
      {
         bLocalSftyMgt_bDgoLih = 0;
      }
   }
   else
   {
      bLocalSftyMgt_bDgoLih = 0;
   }
   LIHCHK_u8TurnOnDelayCnt =
      (uint8)MATHSRV_udtMIN(u8LocalTurnOnDelayCnt, 25);
   VEMS_vidSET(SftyMgt_bDgoLih, bLocalSftyMgt_bDgoLih);
   LIHCHK_bTurnOnDelayInPrev = bLocalTurnOnDelayIn;
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/