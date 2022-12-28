/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQIDLCHK                                                */
/* !Description     : TQIDLCHK Component                                      */
/*                                                                            */
/* !Module          : TQIDLCHK                                                */
/* !Description     : VALIDER REGULATION RALENTI                              */
/*                                                                            */
/* !File            : TQIDLCHK_FCT1.C                                         */
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
/*   1 / TQIDLCHK_vidInitOutput                                               */
/*   2 / TQIDLCHK_vidValRalentiDecollage                                      */
/*   3 / TQIDLCHK_vidValidRegulRalenti                                        */
/*   4 / TQIDLCHK_vidValidGlobaleRalenti                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 01242 / 02                                        */
/* !OtherRefs   : CSCT_CGMT09_2400 / 1.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDLCHK/TQIDLCHK_FCT1$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "TQIDLCHK.h"
#include "TQIDLCHK_l.h"
#include "TQIDLCHK_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDLCHK_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation des sorties au reset             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoTqIdl;                                         */
/*  output uint16 TQIDLCHK_u16nOfsIdlTakeOffPrev;                             */
/*  output boolean TQIDLCHK_bOfsIdlTakeOffPrev;                               */
/*  output uint8 TQIDLCHK_u8DgoIdlRegTempo;                                   */
/*  output uint8 TQIDLCHK_u8ElValidateSlowTempo;                              */
/*  output sint16 SftyMgt_tqIdcIdlFil_MP;                                     */
/*  output sint32 TQIDLCHK_s32tqIdcIdlFilMem;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDLCHK_vidInitOutput(void)
{
   VEMS_vidSET(SftyMgt_bDgoTqIdl,0);
   TQIDLCHK_u16nOfsIdlTakeOffPrev = 0;
   TQIDLCHK_bOfsIdlTakeOffPrev = 0;
   TQIDLCHK_u8DgoIdlRegTempo = 0;
   TQIDLCHK_u8ElValidateSlowTempo = 0;
   SftyMgt_tqIdcIdlFil_MP = 0;
   TQIDLCHK_s32tqIdcIdlFilMem = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDLCHK_vidValRalentiDecollage                            */
/* !Description :  valide l’offset de consigne de ralenti produit par la      */
/*                 fonction d’aide au décollage                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01242_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nOfsIdlTakeOff;                                      */
/*  input uint16 TQIDLCHK_u16nOfsIdlTakeOffPrev;                              */
/*  input uint16 SftyMgt_nOfsIdlTakeOff_C;                                    */
/*  input uint8 TQIDLCHK_u8ElValidateSlowTempo;                               */
/*  input boolean TQIDLCHK_bOfsIdlTakeOffPrev;                                */
/*  input uint8 SftyMgt_tiDlyOfsIdlTakeOff_C;                                 */
/*  output uint16 TQIDLCHK_u16nOfsIdlTakeOffPrev;                             */
/*  output boolean SftyMgt_bDgoIdlTakeOff;                                    */
/*  output uint8 TQIDLCHK_u8ElValidateSlowTempo;                              */
/*  output boolean TQIDLCHK_bOfsIdlTakeOffPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDLCHK_vidValRalentiDecollage(void)
{
   boolean bLocalOfsIdlTakeOff;
   uint8   u8LocalElValidateSlowTempo;
   uint16  u16LocalOfsIdlTakeOff;
   uint32  u32LocalnOfsIdlTakeOff;


   VEMS_vidGET(SftyMgt_nOfsIdlTakeOff,u16LocalOfsIdlTakeOff);
   u32LocalnOfsIdlTakeOff =
      TQIDLCHK_u16nOfsIdlTakeOffPrev + SftyMgt_nOfsIdlTakeOff_C;
   if (u16LocalOfsIdlTakeOff > u32LocalnOfsIdlTakeOff)
   {
      bLocalOfsIdlTakeOff = 1;
   }
   else
   {
      bLocalOfsIdlTakeOff = 0;
   }
   TQIDLCHK_u16nOfsIdlTakeOffPrev = u16LocalOfsIdlTakeOff;

   u8LocalElValidateSlowTempo = TQIDLCHK_u8ElValidateSlowTempo;
   if (bLocalOfsIdlTakeOff != 0)
   {
      if (TQIDLCHK_bOfsIdlTakeOffPrev == 0)
      {
         u8LocalElValidateSlowTempo = SftyMgt_tiDlyOfsIdlTakeOff_C;
      }
      else
      {
         if (u8LocalElValidateSlowTempo > 0)
         {
            u8LocalElValidateSlowTempo =
               (uint8)(u8LocalElValidateSlowTempo - 1);
         }
      }

      if (u8LocalElValidateSlowTempo == 0)
      {
         SftyMgt_bDgoIdlTakeOff = 1;
      }
      else
      {
         SftyMgt_bDgoIdlTakeOff = 0;
      }
   }
   else
   {
      SftyMgt_bDgoIdlTakeOff = 0;
   }
   TQIDLCHK_u8ElValidateSlowTempo =
      (uint8)MATHSRV_udtMIN(u8LocalElValidateSlowTempo, 25);
   TQIDLCHK_bOfsIdlTakeOffPrev = bLocalOfsIdlTakeOff ;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDLCHK_vidValidRegulRalenti                              */
/* !Description :  valide la régulation de régime                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01242_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFil;                                              */
/*  input uint16 SftyMgt_nTarIdl;                                             */
/*  input sint16 SftyMgt_tqIdcCoNReg;                                         */
/*  input sint16 SftyMgt_tqIdcIdl;                                            */
/*  input boolean SftyMgt_bDeacAOS;                                           */
/*  input sint16 SftyMgt_tqIdcIdlFil_MP;                                      */
/*  input sint16 SftyMgt_tqIdcIdlComp_MP;                                     */
/*  input uint16 TQIDLCHK_u16tqIdcIdlCompMP;                                  */
/*  input uint16 SftyMgt_tqldcIdl_A[4];                                       */
/*  input uint8 SftyMgt_facTqldcIdlFil_T[4];                                  */
/*  input uint8 SftyMgt_facTqIdcIdlFil_MP;                                    */
/*  input sint32 TQIDLCHK_s32tqIdcIdlFilMem;                                  */
/*  input uint16 SftyMgt_nTarIdlOfs_C;                                        */
/*  input sint16 SftyMgt_tqIdlThd_C;                                          */
/*  input boolean SftyMgt_bTqGrd_MP;                                          */
/*  input boolean SftyMgt_bEngNOnIdl_MP;                                      */
/*  input boolean SftyMgt_bTqIdcIdl_MP;                                       */
/*  input boolean SftyMgt_bDgoTqIdlRaw_MP;                                    */
/*  input boolean SftyMgt_bErrNIdl_MP;                                        */
/*  input boolean SftyMgt_bTqIdlErr_MP;                                       */
/*  input uint8 SftyMgt_tiTqIdlDly_C;                                         */
/*  input uint8 TQIDLCHK_u8DgoIdlRegTempo;                                    */
/*  output sint16 SftyMgt_tqIdcIdlComp_MP;                                    */
/*  output uint16 TQIDLCHK_u16tqIdcIdlCompMP;                                 */
/*  output uint8 SftyMgt_facTqIdcIdlFil_MP;                                   */
/*  output sint32 TQIDLCHK_s32tqIdcIdlFilMem;                                 */
/*  output sint16 SftyMgt_tqIdcIdlFil_MP;                                     */
/*  output boolean SftyMgt_bErrNIdl_MP;                                       */
/*  output boolean SftyMgt_bTqIdcIdl_MP;                                      */
/*  output boolean SftyMgt_bEngNOnIdl_MP;                                     */
/*  output boolean SftyMgt_bTqGrd_MP;                                         */
/*  output boolean SftyMgt_bTqIdlErr_MP;                                      */
/*  output boolean SftyMgt_bDgoTqIdlRaw_MP;                                   */
/*  output uint8 TQIDLCHK_u8DgoIdlRegTempo;                                   */
/*  output boolean SftyMgt_bDgoIdlReg;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDLCHK_vidValidRegulRalenti(void)
{
   boolean bLocalDeacAOS;
   boolean bLocalTqGrdMP;
   uint8   u8LocalInterpolation;
   uint16  u16LocalGain;
   uint16  u16LocalSftyMgtnTarIdl;
   uint16  u16LocalCalcPara;
   uint16  u16LocalSftyMgtnCkFil;
   uint16  u16LocalTqIdcIdlComp;
   sint16  s16LocalTqIdcIdlFil;
   sint16  s16LocalTqIdcIdl;
   sint16  s16LocalTqIdcIdlComp;
   sint16  s16LocalSftyMgtTqIdcCoNReg;
   sint16  s16LocalFilterOutput;
   uint32  u32LocalSftyMgtnTarId;
   sint32  s32LocalTqIdcIdlComp;


   VEMS_vidGET(SftyMgt_nCkFil, u16LocalSftyMgtnCkFil);
   VEMS_vidGET(SftyMgt_nTarIdl, u16LocalSftyMgtnTarIdl);
   VEMS_vidGET(SftyMgt_tqIdcCoNReg, s16LocalSftyMgtTqIdcCoNReg);
   VEMS_vidGET(SftyMgt_tqIdcIdl, s16LocalTqIdcIdl);
   VEMS_vidGET(SftyMgt_bDeacAOS, bLocalDeacAOS);

   s16LocalTqIdcIdlFil = SftyMgt_tqIdcIdlFil_MP;
   s16LocalTqIdcIdlComp = SftyMgt_tqIdcIdlComp_MP;
   s32LocalTqIdcIdlComp = s16LocalTqIdcIdl - SftyMgt_tqIdcIdlFil_MP;
   SftyMgt_tqIdcIdlComp_MP = (sint16)MATHSRV_udtCLAMP(s32LocalTqIdcIdlComp,
                                                      -32000,
                                                      32000);
   TQIDLCHK_u16tqIdcIdlCompMP = (uint16)MATHSRV_udtABS(s16LocalTqIdcIdlComp);
   u16LocalTqIdcIdlComp = (uint16)(TQIDLCHK_u16tqIdcIdlCompMP + 32000);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_tqldcIdl_A,
                                                   u16LocalTqIdcIdlComp,
                                                   4);
   u8LocalInterpolation = MATHSRV_u8Interp1d(SftyMgt_facTqldcIdlFil_T,
                                             u16LocalCalcPara);
   SftyMgt_facTqIdcIdlFil_MP =
      (uint8)MATHSRV_udtMIN(u8LocalInterpolation, 25);

   if (SftyMgt_facTqIdcIdlFil_MP == 0)
   {
      s16LocalFilterOutput = s16LocalTqIdcIdl;
      TQIDLCHK_s32tqIdcIdlFilMem = (sint32)(s16LocalTqIdcIdl * 65536);
   }
   else
   {
      u16LocalGain = (uint16)(65536 / (1 + SftyMgt_facTqIdcIdlFil_MP));
      s16LocalFilterOutput =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalGain,
                                         &TQIDLCHK_s32tqIdcIdlFilMem,
                                         s16LocalTqIdcIdl);
   }
   SftyMgt_tqIdcIdlFil_MP = (sint16)MATHSRV_udtCLAMP(s16LocalFilterOutput,
                                                     -32000,
                                                     32000);

   u32LocalSftyMgtnTarId = u16LocalSftyMgtnTarIdl + SftyMgt_nTarIdlOfs_C;
   if (u32LocalSftyMgtnTarId < u16LocalSftyMgtnCkFil)
   {
      SftyMgt_bErrNIdl_MP = 1;
   }
   else
   {
      SftyMgt_bErrNIdl_MP = 0;
   }

   if (SftyMgt_tqIdcIdlFil_MP > SftyMgt_tqIdlThd_C)
   {
      SftyMgt_bTqIdcIdl_MP = 1;
   }
   else
   {
      SftyMgt_bTqIdcIdl_MP = 0;
   }

   if (SftyMgt_tqIdcIdlFil_MP > s16LocalSftyMgtTqIdcCoNReg)
   {
      SftyMgt_bEngNOnIdl_MP = 1;
   }
   else
   {
      SftyMgt_bEngNOnIdl_MP = 0;
   }

   if (SftyMgt_tqIdcIdlFil_MP >= s16LocalTqIdcIdlFil)
   {
      SftyMgt_bTqGrd_MP = 1;
   }
   else
   {
      SftyMgt_bTqGrd_MP = 0;
   }

   if (  (SftyMgt_bTqGrd_MP != 0)
      && (SftyMgt_bEngNOnIdl_MP != 0)
      && (SftyMgt_bTqIdcIdl_MP != 0)
      && (bLocalDeacAOS != 0) )
   {
      SftyMgt_bTqIdlErr_MP = 1;
   }
   else
   {
      SftyMgt_bTqIdlErr_MP = 0;
   }

   bLocalTqGrdMP = SftyMgt_bDgoTqIdlRaw_MP;
   if (  (SftyMgt_bErrNIdl_MP != 0)
      && (SftyMgt_bTqIdlErr_MP != 0))
   {
      SftyMgt_bDgoTqIdlRaw_MP = 1;
   }
   else
   {
      SftyMgt_bDgoTqIdlRaw_MP = 0;
   }

   if (SftyMgt_bDgoTqIdlRaw_MP != 0)
   {
      if (bLocalTqGrdMP == 0)
      {
         TQIDLCHK_u8DgoIdlRegTempo =
            (uint8)MATHSRV_udtMIN(SftyMgt_tiTqIdlDly_C, 25);
      }
      else
      {
         if (TQIDLCHK_u8DgoIdlRegTempo > 0)
         {
            TQIDLCHK_u8DgoIdlRegTempo =
               (uint8)( TQIDLCHK_u8DgoIdlRegTempo - 1);
         }
      }

      if (TQIDLCHK_u8DgoIdlRegTempo == 0)
      {
         SftyMgt_bDgoIdlReg = 1 ;
      }
      else
      {
         SftyMgt_bDgoIdlReg = 0 ;
      }
   }
   else
   {
      SftyMgt_bDgoIdlReg = 0 ;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQIDLCHK_vidValidGlobaleRalenti                            */
/* !Description :  fait la synthèse des défauts de la fonction ralenti        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_01242_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoNIdl;                                           */
/*  input boolean SftyMgt_bDgoIdlTakeOff;                                     */
/*  input boolean SftyMgt_bDgoIdlReg;                                         */
/*  output boolean SftyMgt_bDgoTqIdl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQIDLCHK_vidValidGlobaleRalenti(void)
{
   boolean bLocalDgoNIdl;


   VEMS_vidGET(SftyMgt_bDgoNIdl,bLocalDgoNIdl);
   if (  (SftyMgt_bDgoIdlTakeOff != 0)
      || (bLocalDgoNIdl != 0)
      || (SftyMgt_bDgoIdlReg != 0) )
   {
      VEMS_vidSET(SftyMgt_bDgoTqIdl, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoTqIdl, 0);
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/