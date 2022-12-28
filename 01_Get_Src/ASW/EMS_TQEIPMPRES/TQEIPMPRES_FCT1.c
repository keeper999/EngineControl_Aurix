/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQEIPMPRES                                              */
/* !Description     : TQEIPMPRES component.                                   */
/*                                                                            */
/* !Module          : TQEIPMPRES                                              */
/* !Description     : Reserve de couple GEP                                   */
/*                                                                            */
/* !File            : TQEIPMPRES_FCT1.C                                       */
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
/*   1 / TQEIPMPRES_vidInitOutput                                             */
/*   2 / TQEIPMPRES_vidReserve_couple_GEP                                     */
/*   3 / TQEIPMPRES_vidPmpGrpDelay                                            */
/*                                                                            */
/* !Reference   : V02 NT 10 05003 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0182 / 2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQEIPMPRES/TQEIPM$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQEIPMPRES.h"
#include "TQEIPMPRES_IM.h"
#include "TQEIPMPRES_L.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQEIPMPRES_vidInitOutput                                   */
/* !Description :  Initialisation des variables de sortie                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 TqRes_tqElPmpGrpRes;                                        */
/*  output boolean Ext_bStHaltElPmpGrp_Prev;                                  */
/*  output uint16 TQEIPMPRES_u16ElPmpGrpTempo;                                */
/*  output boolean TQEIPMPRES_bCdnElPmpResMPPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQEIPMPRES_vidInitOutput(void)
{
   VEMS_vidSET(TqRes_tqElPmpGrpRes, 0);
   Ext_bStHaltElPmpGrp_Prev = 0;
   TQEIPMPRES_u16ElPmpGrpTempo = 0;
   TQEIPMPRES_bCdnElPmpResMPPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQEIPMPRES_vidReserve_couple_GEP                           */
/* !Description :  La réserve du couple GEP varie entre la valeur 0 et une    */
/*                 valeur maximum calibrable. Elle se dégrade progressivement */
/*                 si la condition réserve du couple GEP est non active.      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05003_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQEIPMPRES_vidPmpGrpDelay();                             */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqRes_bAcvElPmpGrpRes_C;                                    */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean Ext_bStHaltElPmpGrp;                                        */
/*  input uint16 TqRes_tqElPmpGrpRes;                                         */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint8 TqRes_spdThrElPmpGrpRes_C;                                    */
/*  input boolean TqRes_bCdnStElPmpGrpRes_MP;                                 */
/*  input boolean TqRes_bCdnSpdElPmpGrpRes_MP;                                */
/*  input uint16 TqRes_tqElPmpGrpRes_C;                                       */
/*  input sint16 TqRes_tqDecMaxElPmpGrpRes_C;                                 */
/*  input uint16 TqRes_tqIncMaxElPmpGrpRes_C;                                 */
/*  input boolean TQEIPMPRES_bCdnElPmpResMPPrev;                              */
/*  input boolean TqRes_bCdnElPmpRes_MP;                                      */
/*  output boolean TqRes_bCdnSpdElPmpGrpRes_MP;                               */
/*  output boolean TqRes_bCdnElPmpRes_MP;                                     */
/*  output uint16 TqRes_tqElPmpGrpRes;                                        */
/*  output boolean TQEIPMPRES_bCdnElPmpResMPPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQEIPMPRES_vidReserve_couple_GEP(void)
{
   boolean bLocal_dft_spdveh;
   boolean bLocalExt_bStHaltElPmpGrp;
   uint16  u16LocalTqResspdThrElPmpGrpResC;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalTqRes_tqElPmpGrpRes;
   uint16  u16LocalTqRes_tqIdlRes;
   uint16  u16LocalTqResTqIncMaxElPmpGrpRes;
   uint16  u16LocalTqResTqDecMaxElPmpGrpRes;
   uint16  u16LocalSlewRateInput;
   sint16  s16LocalTqRes_tqDecMax;


   if (TqRes_bAcvElPmpGrpRes_C != 0)
   {
      VEMS_vidGET(Veh_spdVeh,u16LocalVeh_spdVeh);
      VEMS_vidGET(Ext_bStHaltElPmpGrp, bLocalExt_bStHaltElPmpGrp);
      VEMS_vidGET(TqRes_tqElPmpGrpRes, u16LocalTqRes_tqElPmpGrpRes);
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);

      TQEIPMPRES_vidPmpGrpDelay();

      bLocal_dft_spdveh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);
      u16LocalTqResspdThrElPmpGrpResC =
         (uint16)(TqRes_spdThrElPmpGrpRes_C * 32);
      if (  (u16LocalVeh_spdVeh < u16LocalTqResspdThrElPmpGrpResC)
         || (bLocal_dft_spdveh != 0))
      {
         TqRes_bCdnSpdElPmpGrpRes_MP = 1;
      }
      else
      {
         TqRes_bCdnSpdElPmpGrpRes_MP = 0;
      }

      if (  (bLocalExt_bStHaltElPmpGrp != 0)
         && (TqRes_bCdnStElPmpGrpRes_MP != 0)
         && (TqRes_bCdnSpdElPmpGrpRes_MP != 0))
      {
         TqRes_bCdnElPmpRes_MP = 1;
         u16LocalSlewRateInput = TqRes_tqElPmpGrpRes_C;
      }
      else
      {
         TqRes_bCdnElPmpRes_MP = 0;
         u16LocalSlewRateInput = 0;
      }

      s16LocalTqRes_tqDecMax =
         (sint16)MATHSRV_udtMIN(TqRes_tqDecMaxElPmpGrpRes_C, 0);
      u16LocalTqResTqIncMaxElPmpGrpRes =
         (uint16)(TqRes_tqIncMaxElPmpGrpRes_C / 25);
      u16LocalTqResTqDecMaxElPmpGrpRes =
         (uint16)(((-1) * s16LocalTqRes_tqDecMax) / 25);

      if (  (TQEIPMPRES_bCdnElPmpResMPPrev != 0)
         || (TqRes_bCdnElPmpRes_MP == 0))
      {
         u16LocalTqRes_tqElPmpGrpRes =
            MATHSRV_u16SlewFilter(u16LocalTqRes_tqElPmpGrpRes,
                                  u16LocalSlewRateInput,
                                  u16LocalTqResTqIncMaxElPmpGrpRes,
                                  u16LocalTqResTqDecMaxElPmpGrpRes);
      }
      else
      {
         u16LocalTqRes_tqElPmpGrpRes = u16LocalTqRes_tqIdlRes;
      }
      u16LocalTqRes_tqElPmpGrpRes =
         (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqElPmpGrpRes, 1600);
      VEMS_vidSET(TqRes_tqElPmpGrpRes, u16LocalTqRes_tqElPmpGrpRes);
      TQEIPMPRES_bCdnElPmpResMPPrev = TqRes_bCdnElPmpRes_MP;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQEIPMPRES_vidPmpGrpDelay                                  */
/* !Description :  Activation de la condition après un certain délai          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05003_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bStHaltElPmpGrp;                                        */
/*  input boolean Ext_bStHaltElPmpGrp_Prev;                                   */
/*  input uint8 TqRes_tiCdnElPmpGrpRes_C;                                     */
/*  input uint16 TQEIPMPRES_u16ElPmpGrpTempo;                                 */
/*  output uint16 TQEIPMPRES_u16ElPmpGrpTempo;                                */
/*  output boolean TqRes_bCdnStElPmpGrpRes_MP;                                */
/*  output boolean Ext_bStHaltElPmpGrp_Prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQEIPMPRES_vidPmpGrpDelay(void)
{
   boolean bLocalExt_bStHaltElPmpGrp;
   uint16  u16LocalTurnOnDelayCounter;


   VEMS_vidGET(Ext_bStHaltElPmpGrp, bLocalExt_bStHaltElPmpGrp);
   if (bLocalExt_bStHaltElPmpGrp != 0)
   {
      if (Ext_bStHaltElPmpGrp_Prev == 0)
      {
         u16LocalTurnOnDelayCounter =
            (uint16)((TqRes_tiCdnElPmpGrpRes_C * 25) / 4);
         TQEIPMPRES_u16ElPmpGrpTempo =
            (uint16)(MATHSRV_udtMIN(u16LocalTurnOnDelayCounter, 1500));
      }
      else
      {
         if (TQEIPMPRES_u16ElPmpGrpTempo > 0)
         {
            u16LocalTurnOnDelayCounter =
               (uint16)(MATHSRV_udtMIN(TQEIPMPRES_u16ElPmpGrpTempo, 1500));
            TQEIPMPRES_u16ElPmpGrpTempo = (uint16)(u16LocalTurnOnDelayCounter
                                                  - 1);
         }
      }

      if (TQEIPMPRES_u16ElPmpGrpTempo == 0)
      {
         TqRes_bCdnStElPmpGrpRes_MP = 0;
      }
      else
      {
         TqRes_bCdnStElPmpGrpRes_MP = 1;
      }

      Ext_bStHaltElPmpGrp_Prev = 1;
   }
   else
   {
      TqRes_bCdnStElPmpGrpRes_MP = 1;
      Ext_bStHaltElPmpGrp_Prev = 0;
   }
}
/*------------------------------- end of file --------------------------------*/