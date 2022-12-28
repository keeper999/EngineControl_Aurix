/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSTGPMPRES                                             */
/* !Description     : TQSTGPMPRES component                                   */
/*                                                                            */
/* !Module          : TQSTGPMPRES                                             */
/* !Description     : RÉSERVE DE COUPLE DIRECTION ASSISTÉE                    */
/*                                                                            */
/* !File            : TQSTGPMPRES_FCT1.C                                      */
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
/*   1 / TQSTGPMPRES_vidInitOutput                                            */
/*   2 / TQSTGPMPRES_vidReserveDeCoupleDA                                     */
/*   3 / TQSTGPMPRES_vidConditionReserve                                      */
/*   4 / TQSTGPMPRES_vidConditionDA                                           */
/*   5 / TQSTGPMPRES_vidConditionVolant                                       */
/*   6 / TQSTGPMPRES_vidCalculReserve                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 04991 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0178 / 2                                        */
/* !OtherRefs   : VEMS V02 ECU#052696                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQSTGPMPRES/TQSTG$*/
/* $Revision::   1.8      $$Author::   etsasson       $$Date::   28 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQSTGPMPRES.h"
#include "TQSTGPMPRES_l.h"
#include "TQSTGPMPRES_im.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidInitOutput                                  */
/* !Description :  Fonction d'initialisations des sorties au reset.           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Stg_agStrWhl;                                                */
/*  input uint16 Stg_agvStrWhl;                                               */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input sint16 TqRes_agStrWhlFilStgPmpRes_MP;                               */
/*  input uint8 TqRes_agvStrWhlFilStgPmpRes_MP;                               */
/*  output uint16 TqRes_tqStgPmpRes;                                          */
/*  output boolean TQSTGPMPRES_bTurnOffDelayIn;                               */
/*  output boolean TQSTGPMPRES_bTurnOffDelayInPrev;                           */
/*  output uint16 TQSTGPMPRES_u16tiStgPmpThrCpt;                              */
/*  output uint16 TQSTGPMPRES_u16tiStgPmpThrCpt1;                             */
/*  output sint16 TqRes_agStrWhlFilStgPmpRes_MP;                              */
/*  output sint32 TQSTGPMPRES_s32FiltredCoefFilMem;                           */
/*  output uint8 TqRes_agvStrWhlFilStgPmpRes_MP;                              */
/*  output uint32 TQSTGPMPRES_u32FiltredCoefFilMem;                           */
/*  output boolean TQSTGPMPRES_bRateLimiterPrevEna;                           */
/*  output uint16 TqRes_tqStgPmpResSat_MP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidInitOutput(void)
{
   uint16  u16LocalStg_agvStrWhl;
   uint16  u16LocalTqRes_tqIdlRes;
   sint16  s16LocalStg_agStrWhl;


   VEMS_vidSET(TqRes_tqStgPmpRes, 0);
   VEMS_vidGET(Stg_agStrWhl, s16LocalStg_agStrWhl);
   VEMS_vidGET(Stg_agvStrWhl, u16LocalStg_agvStrWhl);
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   TQSTGPMPRES_bTurnOffDelayIn = 0;
   TQSTGPMPRES_bTurnOffDelayInPrev = 0;
   TQSTGPMPRES_u16tiStgPmpThrCpt = 0;
   TQSTGPMPRES_u16tiStgPmpThrCpt1 = 0;
   TqRes_agStrWhlFilStgPmpRes_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalStg_agStrWhl, -7800, 7800);
   TQSTGPMPRES_s32FiltredCoefFilMem = TqRes_agStrWhlFilStgPmpRes_MP * 256;
   TqRes_agvStrWhlFilStgPmpRes_MP = (uint8)MATHSRV_udtMIN(u16LocalStg_agvStrWhl,
                                                          254);
   TQSTGPMPRES_u32FiltredCoefFilMem = (uint32)(TqRes_agvStrWhlFilStgPmpRes_MP
                                              * 256);
   TQSTGPMPRES_bRateLimiterPrevEna = 0;
   TqRes_tqStgPmpResSat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes,
                                                    1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidReserveDeCoupleDA                           */
/* !Description :  La fonction réserve de couple direction assistée concerne  */
/*                 uniquement la réserve de couple en condition de manoeuvre. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04991_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSTGPMPRES_vidConditionReserve();                       */
/*  extf argret void TQSTGPMPRES_vidCalculReserve();                          */
/*  input boolean TqRes_bAcvStgPmpRes_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidReserveDeCoupleDA(void)
{
   if (TqRes_bAcvStgPmpRes_C != 0)
   {
      TQSTGPMPRES_vidConditionReserve();
      TQSTGPMPRES_vidCalculReserve();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidConditionReserve                            */
/* !Description :  L’activation de la condition manoeuvre sollicite la        */
/*                 validation de quatre conditions suivantes : La vitesse     */
/*                 véhicule doit être inférieure à un seuil de vitesse        */
/*                 calibrable ou défaut vitesse,temps après démarrage est     */
/*                 supérieur à une valeur calibrable.                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04991_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQSTGPMPRES_vidConditionDA();                            */
/*  extf argret void TQSTGPMPRES_vidConditionVolant();                        */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 EOM_tiEngRunStrt;                                            */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 TqRes_spdThrStgPmpRes_C;                                      */
/*  input uint16 TqRes_tiThrEngRunStgPmpRes_C;                                */
/*  input sint16 TqRes_tCoThrStgPmpRes_C;                                     */
/*  input boolean TqRes_bCdnSpdStgPmpRes_MP;                                  */
/*  input boolean TqRes_bCdnEngRunStgPmpRes_MP;                               */
/*  input boolean TqRes_bCdnTCoStgPmpRes_MP;                                  */
/*  input boolean TqRes_bCdnStgPmpStgPmpRes;                                  */
/*  input boolean TqRes_bCdnAgWhlStgPmpRes;                                   */
/*  output boolean TqRes_bCdnSpdStgPmpRes_MP;                                 */
/*  output boolean TqRes_bCdnEngRunStgPmpRes_MP;                              */
/*  output boolean TqRes_bCdnTCoStgPmpRes_MP;                                 */
/*  output boolean TqRes_bCdnStgPmpRes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidConditionReserve(void)
{
   boolean bLocalLimResStg_spdVeh;
   boolean bLocalVehSpdVeh;
   sint16  s16LocalExt_tCoMes;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalEOM_tiEngRunStrt;
   uint16  u16LocalTqResSpdThrStgPmpResC;
   uint32  u32LocalTqResTiThrEngRunStgPmp;


   bLocalLimResStg_spdVeh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(EOM_tiEngRunStrt, u16LocalEOM_tiEngRunStrt);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   u16LocalTqResSpdThrStgPmpResC = (uint16)(32 * TqRes_spdThrStgPmpRes_C);
   if (u16LocalVeh_spdVeh < u16LocalTqResSpdThrStgPmpResC)
   {
      bLocalVehSpdVeh = 1;
   }
   else
   {
      bLocalVehSpdVeh = 0;
   }
   if (  (bLocalVehSpdVeh != 0)
      || (bLocalLimResStg_spdVeh != 0))
   {
      TqRes_bCdnSpdStgPmpRes_MP = 1;
   }
   else
   {
      TqRes_bCdnSpdStgPmpRes_MP = 0;
   }
   u32LocalTqResTiThrEngRunStgPmp = (uint32)(25 * TqRes_tiThrEngRunStgPmpRes_C);

   if (u16LocalEOM_tiEngRunStrt > u32LocalTqResTiThrEngRunStgPmp)
   {
      TqRes_bCdnEngRunStgPmpRes_MP = 1;
   }
   else
   {
      TqRes_bCdnEngRunStgPmpRes_MP = 0;
   }
   if (s16LocalExt_tCoMes > TqRes_tCoThrStgPmpRes_C)
   {
      TqRes_bCdnTCoStgPmpRes_MP = 1;
   }
   else
   {
      TqRes_bCdnTCoStgPmpRes_MP = 0;
   }
   TQSTGPMPRES_vidConditionDA();
   TQSTGPMPRES_vidConditionVolant();
   if (  (TqRes_bCdnSpdStgPmpRes_MP != 0)
      && (TqRes_bCdnEngRunStgPmpRes_MP != 0)
      && (TqRes_bCdnTCoStgPmpRes_MP != 0)
      && (  (TqRes_bCdnStgPmpStgPmpRes != 0)
         || (TqRes_bCdnAgWhlStgPmpRes !=0)))
   {
      TqRes_bCdnStgPmpRes = 1;
   }
   else
   {
      TqRes_bCdnStgPmpRes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidConditionDA                                 */
/* !Description :  Fonction qui traite la condition d'activation de la        */
/*                 direction assistée                                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_07507_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stStgPmpCf;                                               */
/*  input boolean Stg_bStgPmpThdMes;                                          */
/*  input uint16 Stg_pStgPmpLnrMes;                                           */
/*  input uint16 TqRes_pStgPmpThrStgPmpRes_C;                                 */
/*  input boolean TQSTGPMPRES_bTurnOffDelayIn;                                */
/*  input uint8 TqRes_tiCdnStgPmpStgPmpRes_C;                                 */
/*  input uint16 TQSTGPMPRES_u16tiStgPmpThrCpt;                               */
/*  output boolean TqRes_bCdnStgPmpStgPmpRes;                                 */
/*  output boolean TQSTGPMPRES_bTurnOffDelayIn;                               */
/*  output uint16 TQSTGPMPRES_u16tiStgPmpThrCpt;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidConditionDA(void)
{
   boolean bLocalTurnOffDelayIn;
   boolean bLocalStg_bStgPmpThdMes;
   uint8   u8LocalExt_stStgPmpCf;
   uint16  u16LocalStg_pStgPmpLnrMes;


   VEMS_vidGET(Ext_stStgPmpCf, u8LocalExt_stStgPmpCf);
   u8LocalExt_stStgPmpCf = (uint8)MATHSRV_udtMIN(u8LocalExt_stStgPmpCf, 3);
   switch (u8LocalExt_stStgPmpCf)
   {
      case 0:
         bLocalTurnOffDelayIn = 0;
         break;

      case 1:
         VEMS_vidGET(Stg_bStgPmpThdMes, bLocalStg_bStgPmpThdMes);
         bLocalTurnOffDelayIn = bLocalStg_bStgPmpThdMes;
         break;

      case 2:
         VEMS_vidGET(Stg_pStgPmpLnrMes, u16LocalStg_pStgPmpLnrMes);
         if (u16LocalStg_pStgPmpLnrMes > TqRes_pStgPmpThrStgPmpRes_C)
         {
            bLocalTurnOffDelayIn = 1;
         }
         else
         {
            bLocalTurnOffDelayIn = 0;
         }
         break;

      default:
         bLocalTurnOffDelayIn = 0;
         break;
   }

   if (bLocalTurnOffDelayIn != 0)
   {
      TqRes_bCdnStgPmpStgPmpRes = 1;
      TQSTGPMPRES_bTurnOffDelayIn = 1;
   }
   else
   {
      if (TQSTGPMPRES_bTurnOffDelayIn != 0)
      {
         TQSTGPMPRES_u16tiStgPmpThrCpt =
            (uint16)((TqRes_tiCdnStgPmpStgPmpRes_C * 25) / 4);
      }
      else
      {
         if (TQSTGPMPRES_u16tiStgPmpThrCpt > 0)
         {
            TQSTGPMPRES_u16tiStgPmpThrCpt =
               (uint16)(TQSTGPMPRES_u16tiStgPmpThrCpt - 1);
         }
      }
      if (TQSTGPMPRES_u16tiStgPmpThrCpt == 0)
      {
         TqRes_bCdnStgPmpStgPmpRes = 0;
      }
      else
      {
         TqRes_bCdnStgPmpStgPmpRes = 1;
      }
      TQSTGPMPRES_bTurnOffDelayIn = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidConditionVolant                             */
/* !Description :  La condition angle volant est active si la valeur de       */
/*                 l’angle au volant est supérieure à une valeur d’angle      */
/*                 fonction de la vitesse de l’angle au volant. La condition  */
/*                 angle volant se désactive après une temporisation          */
/*                 calibrable.                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04991_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Stg_agStrWhl;                                                */
/*  input uint8 TqRes_facFilAgStgPmpRes_C;                                    */
/*  input sint32 TQSTGPMPRES_s32FiltredCoefFilMem;                            */
/*  input sint16 TqRes_agStrWhlFilStgPmpRes_MP;                               */
/*  input uint16 Stg_agvStrWhl;                                               */
/*  input uint8 TqRes_facFilAvgStgPmpRes_C;                                   */
/*  input uint32 TQSTGPMPRES_u32FiltredCoefFilMem;                            */
/*  input uint8 TqRes_agvStrWhl_A[8];                                         */
/*  input uint8 TqRes_agvStrWhlFilStgPmpRes_MP;                               */
/*  input uint16 TqRes_agStrWhlThr_T[8];                                      */
/*  input boolean TQSTGPMPRES_bTurnOffDelayInPrev;                            */
/*  input uint8 TqRes_tiCdnStrWhlStgPmpRes_C;                                 */
/*  input uint16 TQSTGPMPRES_u16tiStgPmpThrCpt1;                              */
/*  input boolean TqRes_bAcvCdnAgStgPmpRes_C;                                 */
/*  output sint32 TQSTGPMPRES_s32FiltredCoefFilMem;                           */
/*  output sint16 TqRes_agStrWhlFilStgPmpRes_MP;                              */
/*  output uint32 TQSTGPMPRES_u32FiltredCoefFilMem;                           */
/*  output uint8 TqRes_agvStrWhlFilStgPmpRes_MP;                              */
/*  output boolean TQSTGPMPRES_bTurnOffDelayInPrev;                           */
/*  output uint16 TQSTGPMPRES_u16tiStgPmpThrCpt1;                             */
/*  output boolean TqRes_bCdnAgWhlStgPmpRes;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidConditionVolant(void)
{
   boolean bLocalTurnOffDelay1;
   uint8   u8LocalFilterGain;
   uint8   u8LocalFilterGain1;
   uint16  u16LocalStg_agvStrWhl;
   uint16  u16LocalTqResAvStrWhlFilStgPmpMP;
   uint16  u16LocalInterpolationPara;
   uint16  u16LocalTqResAgStrWhlThrT;
   uint16  u16LocalTqResAgStrWhlFilStgPmpMP;
   sint16  s16LocalStg_agStrWhl;
   sint16  s16LocalTqResAgStrWhlFilStgPmpM;
   uint32  u32LocalTqResAgStrWhlThrT;


   /*****Filter1********/
   VEMS_vidGET(Stg_agStrWhl, s16LocalStg_agStrWhl);
   if (TqRes_facFilAgStgPmpRes_C < 128)
   {
      u8LocalFilterGain = (uint8)(TqRes_facFilAgStgPmpRes_C * 2);
      s16LocalTqResAgStrWhlFilStgPmpM =
          MATHSRV_s16FirstOrderFilterGu8(u8LocalFilterGain,
                                         &TQSTGPMPRES_s32FiltredCoefFilMem,
                                         s16LocalStg_agStrWhl);
   }
   else
   {
      /* Traitement du cas où le gain = 100% */
      s16LocalTqResAgStrWhlFilStgPmpM = s16LocalStg_agStrWhl;
      TQSTGPMPRES_s32FiltredCoefFilMem =
         (sint32)(s16LocalTqResAgStrWhlFilStgPmpM * 256);
   }
      TqRes_agStrWhlFilStgPmpRes_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqResAgStrWhlFilStgPmpM, -7800, 7800);
      u16LocalTqResAgStrWhlFilStgPmpMP =
         (uint16)MATHSRV_udtABS(TqRes_agStrWhlFilStgPmpRes_MP);

   /****Filter2********/
   VEMS_vidGET(Stg_agvStrWhl, u16LocalStg_agvStrWhl);
   if (TqRes_facFilAvgStgPmpRes_C < 128)
   {
      u8LocalFilterGain1 = (uint8)(TqRes_facFilAvgStgPmpRes_C * 2);
      u16LocalTqResAvStrWhlFilStgPmpMP =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain1,
                                        &TQSTGPMPRES_u32FiltredCoefFilMem,
                                        u16LocalStg_agvStrWhl);
   }
   else
   {
      /* Traitement du cas où le gain = 100% */
      u16LocalTqResAvStrWhlFilStgPmpMP = u16LocalStg_agvStrWhl;
      TQSTGPMPRES_u32FiltredCoefFilMem =
         (uint32)(u16LocalTqResAvStrWhlFilStgPmpMP * 256);
   }
   TqRes_agvStrWhlFilStgPmpRes_MP =
      (uint8)MATHSRV_udtMIN(u16LocalTqResAvStrWhlFilStgPmpMP, 254);
   /*   INTERPOLATION  */
   u16LocalInterpolationPara =
      MATHSRV_u16CalcParaIncAryU8(TqRes_agvStrWhl_A,
                                  TqRes_agvStrWhlFilStgPmpRes_MP,
                                  8);
   u16LocalTqResAgStrWhlThrT = MATHSRV_u16Interp1d(TqRes_agStrWhlThr_T,
                                                   u16LocalInterpolationPara);
   u32LocalTqResAgStrWhlThrT = (uint32)(u16LocalTqResAgStrWhlThrT * 10);
   /* TurnOffDelay */
   if (u16LocalTqResAgStrWhlFilStgPmpMP > u32LocalTqResAgStrWhlThrT)
   {
      TQSTGPMPRES_bTurnOffDelayInPrev = 1;
      bLocalTurnOffDelay1 = 1;
   }
   else
   {
      if (TQSTGPMPRES_bTurnOffDelayInPrev != 0)
      {
         TQSTGPMPRES_u16tiStgPmpThrCpt1 =
            (uint16)((TqRes_tiCdnStrWhlStgPmpRes_C * 25) / 4);
      }
      else
      {
         if (TQSTGPMPRES_u16tiStgPmpThrCpt1 > 0)
         {
            TQSTGPMPRES_u16tiStgPmpThrCpt1 =
               (uint16)(TQSTGPMPRES_u16tiStgPmpThrCpt1 - 1);
         }
      }
      if (TQSTGPMPRES_u16tiStgPmpThrCpt1 == 0)
      {
         bLocalTurnOffDelay1 = 0;
      }
      else
      {
         bLocalTurnOffDelay1 = 1;
      }
      TQSTGPMPRES_bTurnOffDelayInPrev = 0;
   }
   if (  (TqRes_bAcvCdnAgStgPmpRes_C != 0)
      && (bLocalTurnOffDelay1 != 0))
   {
      TqRes_bCdnAgWhlStgPmpRes = 1;
   }
   else
   {
      TqRes_bCdnAgWhlStgPmpRes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSTGPMPRES_vidCalculReserve                               */
/* !Description :  Fonction qui calcule la réserve de couple DA finale qui est*/
/*                 le maximum entre la valeur 0 et la différence entre la     */
/*                 réserve de couple et le couple compensé.                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_04991_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 TqRes_nEngStgPmpRes_A[8];                                    */
/*  input uint8 TqRes_spdVehStgPmpRes_A[8];                                   */
/*  input uint16 TqRes_tqStgPmpRes_M[8][8];                                   */
/*  input boolean TqRes_bCdnStgPmpRes;                                        */
/*  input boolean TQSTGPMPRES_bRateLimiterPrevEna;                            */
/*  input uint16 TqRes_tqStgPmpResMax_MP;                                     */
/*  input uint16 TqRes_tqIncMaxStgPmpRes_C;                                   */
/*  input sint16 TqRes_tqDecMaxStgPmpRes_C;                                   */
/*  input uint16 TqRes_tqStgPmpResSat_MP;                                     */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqCmp_tqStgPmpLoss;                                          */
/*  output uint16 TqRes_tqStgPmpResMax_MP;                                    */
/*  output boolean TQSTGPMPRES_bRateLimiterPrevEna;                           */
/*  output uint16 TqRes_tqStgPmpResSat_MP;                                    */
/*  output uint16 TqRes_tqStgPmpRes;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSTGPMPRES_vidCalculReserve(void)
{
   boolean bLocalRateLimterEna;
   uint8   u8LocalVehSpdVeh;
   uint16  u16LocalRateLimterIn;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalInterpolationParaX;
   uint16  u16LocalInterpolationParaY;
   uint16  u16LocalTqResTqStgPmpResM;
   uint16  u16LocalTqRes_tqIdlRes;
   uint16  u16LocalTqResTqStgPmpResSatMP;
   uint16  u16LocalTqCmp_tqStgPmpLoss;
   uint16  u16LocalTqRes_tqStgPmpRes;
   uint16  u16LocalSlewFilterInc;
   uint16  u16LocalSlewFilterDec;
   sint16  s16LocalSlewFilterDec;
   sint32  s32LocalTqResTqStgPmpRes;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalInterpolationParaX =
      MATHSRV_u16CalcParaIncAryU16(TqRes_nEngStgPmpRes_A,
                                   u16LocalEng_nCkFil,
                                   8);
   u16LocalVeh_spdVeh = (uint16)((u16LocalVeh_spdVeh + 16) / 32);
   u8LocalVehSpdVeh = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 255);
   u16LocalInterpolationParaY =
      MATHSRV_u16CalcParaIncAryU8(TqRes_spdVehStgPmpRes_A,
                                  u8LocalVehSpdVeh,
                                  8);
   u16LocalTqResTqStgPmpResM =
      MATHSRV_u16Interp2d(&TqRes_tqStgPmpRes_M[0][0],
                          u16LocalInterpolationParaX,
                          u16LocalInterpolationParaY,
                          8);
   TqRes_tqStgPmpResMax_MP = (uint16)MATHSRV_udtMIN(u16LocalTqResTqStgPmpResM,
                                                    1600);
   if (TqRes_bCdnStgPmpRes == 0)
   {
      u16LocalRateLimterIn = 0;
      bLocalRateLimterEna = 1;
      TQSTGPMPRES_bRateLimiterPrevEna = 0;
   }
   else
   {
      if (TQSTGPMPRES_bRateLimiterPrevEna == 0)
      {
         bLocalRateLimterEna = 0;
      }
      else
      {
         bLocalRateLimterEna = 1;
      }
      TQSTGPMPRES_bRateLimiterPrevEna = 1;
      u16LocalRateLimterIn = TqRes_tqStgPmpResMax_MP;
   }
   if (bLocalRateLimterEna != 0)
   {
      u16LocalSlewFilterInc = (uint16)(TqRes_tqIncMaxStgPmpRes_C / 25);
      s16LocalSlewFilterDec = (sint16)(TqRes_tqDecMaxStgPmpRes_C / 25);
      s16LocalSlewFilterDec = (sint16)( (-1) * s16LocalSlewFilterDec);
      u16LocalSlewFilterDec = (uint16)MATHSRV_udtMAX(s16LocalSlewFilterDec, 0);
      u16LocalTqResTqStgPmpResSatMP =
               MATHSRV_u16SlewFilter(TqRes_tqStgPmpResSat_MP,
                                     u16LocalRateLimterIn,
                                     u16LocalSlewFilterInc,
                                     u16LocalSlewFilterDec);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
      u16LocalTqResTqStgPmpResSatMP = u16LocalTqRes_tqIdlRes;
   }
   TqRes_tqStgPmpResSat_MP =
      (uint16)MATHSRV_udtMIN(u16LocalTqResTqStgPmpResSatMP, 1600);
   VEMS_vidGET(TqCmp_tqStgPmpLoss, u16LocalTqCmp_tqStgPmpLoss);
   s32LocalTqResTqStgPmpRes = TqRes_tqStgPmpResSat_MP
                            - u16LocalTqCmp_tqStgPmpLoss;
   u16LocalTqRes_tqStgPmpRes =
      (uint16)MATHSRV_udtMAX(s32LocalTqResTqStgPmpRes, 0);
   VEMS_vidSET(TqRes_tqStgPmpRes, u16LocalTqRes_tqStgPmpRes);
}
/*---------------------------------End Of File--------------------------------*/