/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGREQH                                                 */
/* !Description     : ENGREQH component.                                      */
/*                                                                            */
/* !Module          : ENGREQH                                                 */
/* !Description     : ERH                                                     */
/*                                                                            */
/* !File            : ENGREQH_FCT4.C                                          */
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
/*   1 / ENGREQH_vidFiltreRegimeMoteur                                        */
/*   2 / ENGREQH_vidCriticPresAtmospheriq                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 05960 / 08                                        */
/* !OtherRefs   : CSMT_CGMT08_2303 / 2.6                                      */
/* !OtherRefs   : VEMS V02 ECU#058179                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/ENGREQH/ENGREQH_FCT4.C$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "GDGAR.h"
#include "MATHSRV.h"
#include "ENGREQH.h"
#include "ENGREQH_L.h"
#include "ENGREQH_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidFiltreRegimeMoteur                              */
/* !Description :  Ce bloc permet de sélectionner le régime moteur utilisé    */
/*                 pour le calcul de la condition de redémarrage autonome.    */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_nEngToothClc;                                            */
/*  input uint8 EngReqH_facFilNEng_C;                                         */
/*  input uint32 ENGREQH_u32nEngFiltMem;                                      */
/*  input boolean EngReqH_bCfNEngRstrtAutn_C;                                 */
/*  input uint16 ENGREQH_u16nEngFilter;                                       */
/*  output uint32 ENGREQH_u32nEngFiltMem;                                     */
/*  output uint16 ENGREQH_u16nEngFilter;                                      */
/*  output uint16 EngReqH_nEngFil;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidFiltreRegimeMoteur(void)
{
   uint16 u16LocalExt_nEng;
   uint16 u16LocalExt_nEngToothClc;
   uint16 u16LocalEngReqH_facFilNEng;
   uint16 u16LocalEngReqHnEngFil;
   uint16 u16LocalnEngFilter;
   uint32 u32LocalEngReqH_nEngFil;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_nEngToothClc, u16LocalExt_nEngToothClc);
   u16LocalEngReqH_facFilNEng = (uint16)((EngReqH_facFilNEng_C * 32) / 25);

   if (u16LocalEngReqH_facFilNEng > 255)
   {
      u16LocalnEngFilter = (uint16)MATHSRV_udtMIN(u16LocalExt_nEngToothClc,
                                                  2000);
      ENGREQH_u32nEngFiltMem = (uint32)(u16LocalExt_nEngToothClc * 256);
   }
   else
   {
      u16LocalnEngFilter = MATHSRV_u16FirstOrderFilterGu8(
                                    (uint8)u16LocalEngReqH_facFilNEng,
                                    &ENGREQH_u32nEngFiltMem,
                                    u16LocalExt_nEngToothClc);
   }
   ENGREQH_u16nEngFilter = (uint16)MATHSRV_udtMIN(u16LocalnEngFilter, 2000);

   if (EngReqH_bCfNEngRstrtAutn_C != 0)
   {
      u16LocalEngReqHnEngFil = u16LocalExt_nEng;
   }
   else
   {
      u16LocalEngReqHnEngFil = ENGREQH_u16nEngFilter;
   }
   u32LocalEngReqH_nEngFil = (uint32)(u16LocalEngReqHnEngFil * 4);
   EngReqH_nEngFil = (uint16)MATHSRV_udtMIN(u32LocalEngReqH_nEngFil,
                                            32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGREQH_vidCriticPresAtmospheriq                           */
/* !Description :  Cette fonction détecte une condition critique sur la       */
/*                 pression atmosphérique pour le démarrage du moteur.        */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_09_05960_044.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input boolean ENGREQH_bpAirExtMemPrev;                                    */
/*  input boolean ENGREQH_bpAirExtMemPrev_2;                                  */
/*  input uint16 EngReqH_tiPAirExtMem_MP;                                     */
/*  input uint16 EngReqH_tiPAirExtMem_C;                                      */
/*  input uint16 EngReqH_pAirExtMem_MP;                                       */
/*  input uint8 EngReqH_pAirExtHysUnfav_C;                                    */
/*  input uint16 EngReqH_pAirExtUnfav_C;                                      */
/*  input sint16 EngReqH_pAirDeltaUnfav_C;                                    */
/*  input uint8 EngReqH_pAirDeltaHysUnfav_C;                                  */
/*  input boolean ENGREQH_bpAirExtUnfav;                                      */
/*  input boolean ENGREQH_bpAirDeltaUnfav;                                    */
/*  output uint16 EngReqH_tiPAirExtMem_MP;                                    */
/*  output uint16 EngReqH_pAirExtMem_MP;                                      */
/*  output boolean ENGREQH_bpAirExtUnfav;                                     */
/*  output boolean ENGREQH_bpAirDeltaUnfav;                                   */
/*  output boolean EngReqH_bDetPresAirUnfav;                                  */
/*  output boolean ENGREQH_bpAirExtMemPrev_2;                                 */
/*  output boolean ENGREQH_bpAirExtMemPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGREQH_vidCriticPresAtmospheriq(void)
{
   boolean bLocalPAirExtMem;
   uint16  u16LocalExt_pAirExtMes;
   uint32  u32LocalCounter;
   uint32  u32LocalEngReqH_tiPAirExtMem;
   uint32  u32LocalHigh;
   sint32  s32LocalLow;
   sint32  s32LocalIn;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   /* Production of EngReqH_tiPAirExtMem_MP */
   if (  (ENGREQH_bpAirExtMemPrev != 0)
      && (ENGREQH_bpAirExtMemPrev_2 == 0))
   {
      EngReqH_tiPAirExtMem_MP = 0;
   }
   else
   {
      u32LocalCounter = (uint32)(EngReqH_tiPAirExtMem_MP + 1);
      EngReqH_tiPAirExtMem_MP = (uint16)MATHSRV_udtMIN(u32LocalCounter, 63000);
   }

   u32LocalEngReqH_tiPAirExtMem = (uint32)(EngReqH_tiPAirExtMem_C * 10);
   if (EngReqH_tiPAirExtMem_MP >= u32LocalEngReqH_tiPAirExtMem)
   {
      bLocalPAirExtMem = 1;
   }
   else
   {
      bLocalPAirExtMem = 0;
   }

   /* Production of EngReqH_pAirExtMem_MP */
   if (bLocalPAirExtMem != 0)
   {
      EngReqH_pAirExtMem_MP = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pAirExtMes,
                                                       500,
                                                       1500);
   }
   else
   {
      EngReqH_pAirExtMem_MP = (uint16)MATHSRV_udtCLAMP(EngReqH_pAirExtMem_MP,
                                                       500,
                                                       1500);
   }

   /* Production of Hys Output EngReqH_bpAirExtUnfav */
   u32LocalHigh = (uint32)(EngReqH_pAirExtHysUnfav_C + EngReqH_pAirExtUnfav_C);
   if (u16LocalExt_pAirExtMes >= u32LocalHigh)
   {
      ENGREQH_bpAirExtUnfav = 0;
   }
   else
   {
      if (u16LocalExt_pAirExtMes <= EngReqH_pAirExtUnfav_C)
      {
         ENGREQH_bpAirExtUnfav = 1;
      }
   }

   /* Production of Hys Output EngReqH_bpAirDeltaUnfav*/
   s32LocalLow = (sint32)( EngReqH_pAirDeltaUnfav_C
                         - EngReqH_pAirDeltaHysUnfav_C);
   s32LocalIn = (sint32)(EngReqH_pAirExtMem_MP - u16LocalExt_pAirExtMes);
   if (s32LocalIn <= s32LocalLow)
   {
      ENGREQH_bpAirDeltaUnfav = 0;
   }
   else
   {
      if (s32LocalIn >= EngReqH_pAirDeltaUnfav_C)
      {
         ENGREQH_bpAirDeltaUnfav = 1;
      }
   }

   /* Production of EngReqH_bDetPresAirUnfav*/
   if (  (ENGREQH_bpAirExtUnfav != 0)
      || (ENGREQH_bpAirDeltaUnfav != 0))
   {
      VEMS_vidSET(EngReqH_bDetPresAirUnfav, 1);
   }
   else
   {
      VEMS_vidSET(EngReqH_bDetPresAirUnfav, 0);
   }
   ENGREQH_bpAirExtMemPrev_2 = ENGREQH_bpAirExtMemPrev;
   ENGREQH_bpAirExtMemPrev = bLocalPAirExtMem;
}
/*-------------------------------- end of file -------------------------------*/
