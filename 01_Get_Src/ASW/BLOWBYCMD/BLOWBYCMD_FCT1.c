/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BLOWBYCMD                                               */
/* !Description     : BLOWBYCMD component.                                    */
/*                                                                            */
/* !Module          : BLOWBYCMD                                               */
/* !Description     : BlowBy COMMAND AND DIAGNOSIS                            */
/*                                                                            */
/* !File            : BLOWBYCMD_FCT1.C                                        */
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
/*   1 / BLOWBYCMD_vidInit                                                    */
/*   2 / BLOWBYCMD_vidHeaterCmd                                               */
/*   3 / BLOWBYCMD_vidBlowBy1Cmd                                              */
/*   4 / BLOWBYCMD_vidBlowBy2Cmd                                              */
/*   5 / BLOWBYCMD_vidDiagBlowBy1                                             */
/*   6 / BLOWBYCMD_vidDiagBlowBy2                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6563717 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BLOWBYCMD/BLOWBYCMD_FCT1.C_v      $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BLOWBYCMD.h"
#include "BLOWBYCMD_L.h"
#include "BLOWBYCMD_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BLOWBYCMD_vidInit                                          */
/* !Description :  The outputs variables are initialized on event reset       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean BlowByHw_bReq;                                             */
/*  output boolean BlowBy1Hw_bReq;                                            */
/*  output st125 BlowByHw_stCtl;                                              */
/*  output boolean Commande_rechauff_blowby1_tor;                             */
/*  output boolean Commande_rechauff_blowby2_tor;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BLOWBYCMD_vidInit(void)
{
   VEMS_vidSET(BlowByHw_bReq, 0);
   VEMS_vidSET(BlowBy1Hw_bReq, 0);
   BlowByHw_stCtl = HEATER_INIT;
   VEMS_vidSET(Commande_rechauff_blowby1_tor, 0);
   VEMS_vidSET(Commande_rechauff_blowby2_tor, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BLOWBYCMD_vidHeaterCmd                                     */
/* !Description :  This state machine generate the variable control of the    */
/*                 heater BlowBy BlowByHw_bReq                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 Ext_tAirExtMes;                                              */
/*  input st125 BlowByHw_stCtl;                                               */
/*  input sint8 BlowByHw_uBattMesMin_C;                                       */
/*  input sint8 BlowByHw_tAirExtLo_C;                                         */
/*  input sint8 BlowByHw_tAirExtHi_C;                                         */
/*  input uint16 BlowByHw_tiHeat;                                             */
/*  input uint16 BlowByHw_tiHeat_C;                                           */
/*  output st125 BlowByHw_stCtl;                                              */
/*  output uint16 BlowByHw_tiHeat;                                            */
/*  output boolean BlowByHw_bReq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BLOWBYCMD_vidHeaterCmd(void)
{
   uint8  u8LocalCoPTSt_stEng;
   sint16 s16LocalExt_uBattMes;
   sint16 s16LocalExt_tAirExtMes;
   sint16 s16LocalUBattMesMin;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET( Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(Ext_tAirExtMes, s16LocalExt_tAirExtMes);

   switch (BlowByHw_stCtl)
   {
      case HEATER_INIT:
         BlowByHw_stCtl = HEATER_INACTIF;
         break;

      case HEATER_INACTIF:
         s16LocalUBattMesMin = (sint16)(BlowByHw_uBattMesMin_C * 100);
         if (  (s16LocalExt_uBattMes > s16LocalUBattMesMin)
            && (s16LocalExt_tAirExtMes < BlowByHw_tAirExtLo_C))
         {
            if (  (u8LocalCoPTSt_stEng == Coupe_cale)
               || (u8LocalCoPTSt_stEng == Preparation)
               || (u8LocalCoPTSt_stEng == Stop))
            {
               BlowByHw_stCtl = HEATER_ACTIF_MOTEUR_ARRETE;
               BlowByHw_tiHeat = 0;
            }
            else
            {
               if(  (u8LocalCoPTSt_stEng == Driven_Start)
                 || (u8LocalCoPTSt_stEng == Autonomous_Start)
                 || (u8LocalCoPTSt_stEng == Engine_Running)
                 || (u8LocalCoPTSt_stEng == Driven_Restart)
                 || (u8LocalCoPTSt_stEng == Autonomous_Restart ))
               {
                  BlowByHw_stCtl = HEATER_ACTIF_MOTEUR_TOURNANT;
               }
               else
               {
                  VEMS_vidSET(BlowByHw_bReq, 0);
               }
            }
         }
         else
         {
            VEMS_vidSET(BlowByHw_bReq, 0);
         }
         break;

      case HEATER_ACTIF_MOTEUR_ARRETE:
         s16LocalUBattMesMin = (sint16)(BlowByHw_uBattMesMin_C * 100);
         if (  (s16LocalExt_uBattMes > s16LocalUBattMesMin)
            && (s16LocalExt_tAirExtMes < BlowByHw_tAirExtLo_C)
            && (  (u8LocalCoPTSt_stEng == Driven_Start)
               || (u8LocalCoPTSt_stEng == Autonomous_Start)
               || (u8LocalCoPTSt_stEng == Engine_Running)
               || (u8LocalCoPTSt_stEng == Driven_Restart)
               || (u8LocalCoPTSt_stEng == Autonomous_Restart)))
         {
            BlowByHw_stCtl = HEATER_ACTIF_MOTEUR_TOURNANT;
         }
         else
         {
            if (  (s16LocalExt_tAirExtMes > BlowByHw_tAirExtHi_C)
               || (BlowByHw_tiHeat >= BlowByHw_tiHeat_C))
            {
               BlowByHw_stCtl = HEATER_INACTIF;
            }
            else
            {
               VEMS_vidSET(BlowByHw_bReq, 1);
               if (BlowByHw_tiHeat < 500 )
               {
                  BlowByHw_tiHeat = (uint16)(BlowByHw_tiHeat + 1);
               }
               else
               {
                  BlowByHw_tiHeat = 500;
               }
            }
         }
         break;

      case HEATER_ACTIF_MOTEUR_TOURNANT:
         s16LocalUBattMesMin = (sint16)(BlowByHw_uBattMesMin_C * 100);
         if (  (s16LocalExt_uBattMes > s16LocalUBattMesMin)
            && (s16LocalExt_tAirExtMes < BlowByHw_tAirExtLo_C)
            && (  (u8LocalCoPTSt_stEng == Coupe_cale)
               || (u8LocalCoPTSt_stEng == Preparation)
               || (u8LocalCoPTSt_stEng == Stop)))
         {
            BlowByHw_stCtl = HEATER_ACTIF_MOTEUR_ARRETE;
            BlowByHw_tiHeat = 0;
         }
         else
         {
            if (s16LocalExt_tAirExtMes > BlowByHw_tAirExtHi_C)
            {
               BlowByHw_stCtl = HEATER_INACTIF;
            }
            else
            {
               VEMS_vidSET(BlowByHw_bReq, 1);
            }
         }
         break;

      default:
         BlowByHw_stCtl = HEATER_INIT;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BLOWBYCMD_vidBlowBy1Cmd                                    */
/* !Description :  Driver of BlowBy heater 1                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean BlowByHw_bReq;                                              */
/*  input boolean Oil_bActrTstInProgsBB1;                                     */
/*  input boolean Oil_bBlowBy1ReqActrTst;                                     */
/*  output boolean Commande_rechauff_blowby1_tor;                             */
/*  output boolean BlowBy1Hw_bReq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BLOWBYCMD_vidBlowBy1Cmd(void)
{
   boolean bLocalBlowByHw_bReq;
   boolean bLocalOil_bActrTstInProgsBB1;
   boolean bLocalOil_bBlowBy1ReqActrTst;


   VEMS_vidGET(BlowByHw_bReq, bLocalBlowByHw_bReq);
   VEMS_vidGET(Oil_bActrTstInProgsBB1, bLocalOil_bActrTstInProgsBB1);
   VEMS_vidGET(Oil_bBlowBy1ReqActrTst, bLocalOil_bBlowBy1ReqActrTst);

   if (bLocalOil_bActrTstInProgsBB1 != 0)
   {
      VEMS_vidSET(Commande_rechauff_blowby1_tor, bLocalOil_bBlowBy1ReqActrTst);
   }
   else
   {
      VEMS_vidSET(Commande_rechauff_blowby1_tor, bLocalBlowByHw_bReq);
   }
   VEMS_vidSET(BlowBy1Hw_bReq, bLocalBlowByHw_bReq);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BLOWBYCMD_vidBlowBy2Cmd                                    */
/* !Description :  Driver of BlowBy heater 2                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean BlowByHw_bReq;                                              */
/*  input boolean Oil_bActrTstInProgsBB2;                                     */
/*  input boolean Oil_bBlowBy2ReqActrTst;                                     */
/*  output boolean Commande_rechauff_blowby2_tor;                             */
/*  output boolean BlowBy2Hw_bReq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BLOWBYCMD_vidBlowBy2Cmd(void)
{
   boolean bLocalBlowByHw_bReq;
   boolean bLocalOil_bActrTstInProgsBB2;
   boolean bLocalOil_bBlowBy2ReqActrTst;


   VEMS_vidGET(BlowByHw_bReq, bLocalBlowByHw_bReq);
   VEMS_vidGET(Oil_bActrTstInProgsBB2, bLocalOil_bActrTstInProgsBB2);
   VEMS_vidGET(Oil_bBlowBy2ReqActrTst, bLocalOil_bBlowBy2ReqActrTst);

   if (bLocalOil_bActrTstInProgsBB2 != 0)
   {
      VEMS_vidSET(Commande_rechauff_blowby2_tor, bLocalOil_bBlowBy2ReqActrTst);
   }
   else
   {
      VEMS_vidSET(Commande_rechauff_blowby2_tor, bLocalBlowByHw_bReq);
   }
   BlowBy2Hw_bReq = bLocalBlowByHw_bReq;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BLOWBYCMD_vidDiagBlowBy1                                   */
/* !Description :  DGOHAL service generates signals defaults detected during  */
/*                 the command of the BlowBy heater nbr 1                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean BlowByHw_bReq;                                              */
/*  input boolean Dena_oc_rechauffeurblowby1;                                 */
/*  input boolean Dft_oc_rechauffeurblowby1;                                  */
/*  input boolean Dena_scg_rechauffeurblowby1;                                */
/*  input boolean Dft_scg_rechauffeurblowby1;                                 */
/*  input boolean Dena_scw_rechauffeurblowby1;                                */
/*  input boolean Dft_scw_rechauffeurblowby1;                                 */
/*  output boolean OilSys_bMonRunOc_BlowBy1;                                  */
/*  output boolean OilSys_bDgoOc_BlowBy1;                                     */
/*  output boolean OilSys_bMonRunScg_BlowBy1;                                 */
/*  output boolean OilSys_bDgoScg_BlowBy1;                                    */
/*  output boolean OilSys_bMonRunScp_BlowBy1;                                 */
/*  output boolean OilSys_bDgoScp_BlowBy1;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BLOWBYCMD_vidDiagBlowBy1(void)
{
   boolean bLocalBlowByHw_bReq;
   boolean bLocalInhDiag_BlowBy1;
   boolean bLocalDenaOcRechauffeurblowby1;
   boolean bLocalDftOcRechauffeurblowby1;
   boolean bLocalDenaScgRechauffeurblowby1;
   boolean bLocalDftScgRechauffeurblowby1;
   boolean bLocalDenaScwRechauffeurblowby1;
   boolean bLocalDftScwRechauffeurblowby1;


   bLocalInhDiag_BlowBy1 = GDGAR_bGetFRM(FRM_FRM_INHDIAG_BLOWBY1);
   VEMS_vidGET(BlowByHw_bReq, bLocalBlowByHw_bReq);
   VEMS_vidGET(Dena_oc_rechauffeurblowby1, bLocalDenaOcRechauffeurblowby1);
   VEMS_vidGET(Dft_oc_rechauffeurblowby1, bLocalDftOcRechauffeurblowby1);
   VEMS_vidGET(Dena_scg_rechauffeurblowby1, bLocalDenaScgRechauffeurblowby1);
   VEMS_vidGET(Dft_scg_rechauffeurblowby1, bLocalDftScgRechauffeurblowby1);
   VEMS_vidGET(Dena_scw_rechauffeurblowby1, bLocalDenaScwRechauffeurblowby1);
   VEMS_vidGET(Dft_scw_rechauffeurblowby1, bLocalDftScwRechauffeurblowby1);

   if (  (bLocalBlowByHw_bReq == 0)
      && (bLocalInhDiag_BlowBy1 == 0))
   {
      if (bLocalDenaOcRechauffeurblowby1 != 0)
      {
         OilSys_bMonRunOc_BlowBy1 = 1;
         if (bLocalDftOcRechauffeurblowby1 != 0)
         {
            OilSys_bDgoOc_BlowBy1 = 1;
         }
         else
         {
            OilSys_bDgoOc_BlowBy1 = 0;
         }
      }
      else
      {
         OilSys_bMonRunOc_BlowBy1 = 0;
         OilSys_bDgoOc_BlowBy1 = 0;
      }

      if (bLocalDenaScgRechauffeurblowby1 != 0)
      {
         OilSys_bMonRunScg_BlowBy1 = 1;
         if (bLocalDftScgRechauffeurblowby1 != 0)
         {
            OilSys_bDgoScg_BlowBy1 = 1;
         }
         else
         {
            OilSys_bDgoScg_BlowBy1 = 0;
         }
      }
      else
      {
         OilSys_bMonRunScg_BlowBy1 = 0;
         OilSys_bDgoScg_BlowBy1 = 0;
      }
   }
   else
   {
      OilSys_bMonRunOc_BlowBy1 = 0;
      OilSys_bMonRunScg_BlowBy1 = 0;
      OilSys_bDgoOc_BlowBy1 = 0;
      OilSys_bDgoScg_BlowBy1 = 0;
   }
   if (  (bLocalDenaScwRechauffeurblowby1 != 0)
      && (bLocalInhDiag_BlowBy1 == 0)
      && (bLocalBlowByHw_bReq != 0))
   {
      OilSys_bMonRunScp_BlowBy1 = 1;
      if (bLocalDftScwRechauffeurblowby1 != 0)
      {
         OilSys_bDgoScp_BlowBy1 = 1;
      }
      else
      {
         OilSys_bDgoScp_BlowBy1 = 0;
      }
   }
   else
   {
      OilSys_bMonRunScp_BlowBy1 = 0;
      OilSys_bDgoScp_BlowBy1 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BLOWBYCMD_vidDiagBlowBy2                                   */
/* !Description :  DGOHAL service generates signals defaults detected during  */
/*                 the command of the BlowBy heater nbr 2.                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean BlowByHw_bReq;                                              */
/*  input boolean Dena_oc_rechauffeurblowby2;                                 */
/*  input boolean Dft_oc_rechauffeurblowby2;                                  */
/*  input boolean Dena_scg_rechauffeurblowby2;                                */
/*  input boolean Dft_scg_rechauffeurblowby2;                                 */
/*  input boolean Dena_scw_rechauffeurblowby2;                                */
/*  input boolean Dft_scw_rechauffeurblowby2;                                 */
/*  output boolean OilSys_bMonRunOc_BlowBy2;                                  */
/*  output boolean OilSys_bDgoOc_BlowBy2;                                     */
/*  output boolean OilSys_bMonRunScg_BlowBy2;                                 */
/*  output boolean OilSys_bDgoScg_BlowBy2;                                    */
/*  output boolean OilSys_bMonRunScp_BlowBy2;                                 */
/*  output boolean OilSys_bDgoScp_BlowBy2;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BLOWBYCMD_vidDiagBlowBy2(void)
{
   boolean bLocalBlowByHw_bReq;
   boolean bLocalInhDiag_BlowBy2;
   boolean bLocalDenaOcRechauffeurblowby2;
   boolean bLocalDftOcRechauffeurblowby2;
   boolean bLocalDenaScgRechauffeurblowby2;
   boolean bLocalDftScgRechauffeurblowby2;
   boolean bLocalDenaScwRechauffeurblowby2;
   boolean bLocalDftScwRechauffeurblowby2;


   bLocalInhDiag_BlowBy2 = GDGAR_bGetFRM(FRM_FRM_INHDIAG_BLOWBY2);
   VEMS_vidGET(BlowByHw_bReq, bLocalBlowByHw_bReq);
   VEMS_vidGET(Dena_oc_rechauffeurblowby2, bLocalDenaOcRechauffeurblowby2);
   VEMS_vidGET(Dft_oc_rechauffeurblowby2, bLocalDftOcRechauffeurblowby2);
   VEMS_vidGET(Dena_scg_rechauffeurblowby2, bLocalDenaScgRechauffeurblowby2);
   VEMS_vidGET(Dft_scg_rechauffeurblowby2, bLocalDftScgRechauffeurblowby2);
   VEMS_vidGET(Dena_scw_rechauffeurblowby2, bLocalDenaScwRechauffeurblowby2);
   VEMS_vidGET(Dft_scw_rechauffeurblowby2, bLocalDftScwRechauffeurblowby2);

   if ((bLocalBlowByHw_bReq == 0) && (bLocalInhDiag_BlowBy2 == 0))
   {
      if (bLocalDenaOcRechauffeurblowby2 != 0)
      {
         OilSys_bMonRunOc_BlowBy2 = 1;
         if (bLocalDftOcRechauffeurblowby2 != 0)
         {
            OilSys_bDgoOc_BlowBy2 = 1;
         }
         else
         {
            OilSys_bDgoOc_BlowBy2 = 0;
         }
      }
      else
      {
         OilSys_bMonRunOc_BlowBy2 = 0;
         OilSys_bDgoOc_BlowBy2 = 0;
      }

      if (bLocalDenaScgRechauffeurblowby2 != 0)
      {
         OilSys_bMonRunScg_BlowBy2 = 1;
         if (bLocalDftScgRechauffeurblowby2 != 0)
         {
            OilSys_bDgoScg_BlowBy2 = 1;
         }
         else
         {
            OilSys_bDgoScg_BlowBy2 = 0;
         }
      }
      else
      {
         OilSys_bMonRunScg_BlowBy2 = 0;
         OilSys_bDgoScg_BlowBy2 = 0;
      }
   }
   else
   {
      OilSys_bMonRunOc_BlowBy2 = 0;
      OilSys_bMonRunScg_BlowBy2 = 0;
      OilSys_bDgoOc_BlowBy2 = 0;
      OilSys_bDgoScg_BlowBy2 = 0;
   }
   if (  (bLocalDenaScwRechauffeurblowby2 != 0)
      && (bLocalInhDiag_BlowBy2 == 0)
      && (bLocalBlowByHw_bReq != 0))
   {
      OilSys_bMonRunScp_BlowBy2 = 1;
      if (bLocalDftScwRechauffeurblowby2 != 0)
      {
         OilSys_bDgoScp_BlowBy2 = 1;
      }
      else
      {
         OilSys_bDgoScp_BlowBy2 = 0;
      }
   }
   else
   {
      OilSys_bMonRunScp_BlowBy2 = 0;
      OilSys_bDgoScp_BlowBy2 = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/