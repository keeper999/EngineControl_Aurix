/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSDERIDIAG                                     */
/* !Description     : HEATSENO2DSDERIDIAG component.                          */
/*                                                                            */
/* !Module          : HEATSENO2DSDERIDIAG                                     */
/* !Description     : DIAGNOSTIC DERIVEE TENSION SONDE A OXYGENE AVAL.        */
/*                                                                            */
/* !File            : HEATSENO2DSDERIDIAG_FCT3.C                              */
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
/*   1 / HEATSENO2DSDERIDIAG_vidInitGsl                                       */
/*   2 / HEATSENO2DSDERIDIAG_vidInitGaz                                       */
/*   3 / HEATSENO2DSDERIDIAG_vidFacMes                                        */
/*   4 / HEATSENO2DSDERIDIAG_vidSigEuro6                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5012852 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSDERIDIA$*/
/* $Revision::   1.3      $$Author::   etsass$$Date::   18 Jan 2013 16:31:44 $*/
/* $Author::   etsasson                      $$Date::   18 Jan 2013 16:31:44 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2DSDERIDIAG.h"
#include "HEATSENO2DSDERIDIAG_L.h"
#include "HEATSENO2DSDERIDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidInitGsl                             */
/* !Description :  Cette fonction permet d’initialiser correctement les       */
/*                 variables de la fonction diagnostic  dérivée sonde aval    */
/*                 ainsi qu'elle indique si on effectue le premier roulage.   */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ldsd_trk_ewma_essence_eep;                                   */
/*  output boolean Ldsd_trk_init_fait;                                        */
/*  output boolean Ldsd_trk_first_diag;                                       */
/*  output uint16 Ldsd_trk_ewma_eep;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidInitGsl(void)
{
   uint16 u16LocalLdsd_trk_ewma_eep;


   Ldsd_trk_init_fait = 1;

   if (Ldsd_trk_ewma_essence_eep == 65535)
   {
      Ldsd_trk_first_diag = 1;
   }
   else
   {
      Ldsd_trk_first_diag = 0;
   }
   u16LocalLdsd_trk_ewma_eep = Ldsd_trk_ewma_essence_eep;

   VEMS_vidSET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidInitGaz                             */
/* !Description :  Cette fonction permet d’initialiser la valeur de la moyenne*/
/*                 de tension de type EWMA.                                   */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_trk_ewma_essence_eep;                                   */
/*  input uint16 Ldsd_trk_ewma_gaz_eep;                                       */
/*  output boolean Ldsd_trk_init_fait;                                        */
/*  output boolean Ldsd_trk_first_diag;                                       */
/*  output uint16 Ldsd_trk_ewma_eep;                                          */
/*  output uint16 Ldsd_trk_ewma_essence_eep;                                  */
/*  output uint16 Ldsd_trk_ewma_gaz_eep;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidInitGaz(void)
{
   uint8  u8LocalExt_stSysGas;


   Ldsd_trk_init_fait = 1;
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGslMod_SC)
   {
      if (Ldsd_trk_ewma_essence_eep == 65535)
      {
         Ldsd_trk_first_diag = 1;
      }
      else
      {
         Ldsd_trk_first_diag = 0;
      }
      VEMS_vidSET(Ldsd_trk_ewma_eep, Ldsd_trk_ewma_essence_eep);
   }
   else
   {
      if (Ldsd_trk_ewma_gaz_eep == 65535)
      {
         Ldsd_trk_first_diag = 1;
      }
      else
      {
         Ldsd_trk_first_diag = 0;
      }
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Ldsd_trk_ewma_eep, Ldsd_trk_ewma_gaz_eep);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidFacMes                              */
/* !Description :  La valeur envoyée au ScanTool mode06 est mise à jour       */
/*                 lorsque le résultat du diag est disponible (autrement dit  */
/*                 bMonRun à 1)                                               */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ldsd_trk_ewma_eep;                                           */
/*  output uint16 SenO2Ds_SigGrdFacMesRaw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidFacMes(void)
{
   uint16 u16LocalLdsd_trk_ewma_eep;


   VEMS_vidGET(Ldsd_trk_ewma_eep, u16LocalLdsd_trk_ewma_eep);
   SenO2Ds_SigGrdFacMesRaw = u16LocalLdsd_trk_ewma_eep;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSDERIDIAG_vidSigEuro6                            */
/* !Description :  Les variables finales envoyées au Mode06 (FacMes, FacMin)  */
/*                 sont gelées lorsque la panne est présente mais non encore  */
/*                 confirmée par le GD/GAR                                    */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SenO2Ds_bAcvEuro6SigGrdDiag_C;                              */
/*  input boolean SenO2Ds_bDgoORng_SigGrdDiag;                                */
/*  input uint16 SenO2Ds_SigGrdFacMesRaw;                                     */
/*  input uint16 SenO2Ds_SigGrdFacMinRaw;                                     */
/*  input boolean SenO2Ds_bInhMonWait_sigGrd_C;                               */
/*  input boolean SenO2Ds_bMonRunRaw_SigGrdDiag;                              */
/*  input boolean SenO2Ds_bMonWaitRaw_SigGrdDiag;                             */
/*  output uint16 SenO2Ds_SigGrdFacMes_Obd6Mod;                               */
/*  output uint16 SenO2Ds_SigGrdFacMesRaw;                                    */
/*  output uint16 SenO2Ds_SigGrdFacMin_Obd6Mod;                               */
/*  output uint16 SenO2Ds_SigGrdFacMinRaw;                                    */
/*  output boolean SenO2Ds_bMonWaitORng_SigGrdDiag;                           */
/*  output boolean SenO2Ds_bMonRunORng_SigGrdDiag;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSDERIDIAG_vidSigEuro6(void)
{
   boolean  bLocalFRM_bCfmSenO2DsSigGrd;


   bLocalFRM_bCfmSenO2DsSigGrd = GDGAR_bGetFRM (FRM_FRM_CFMSENO2DSSIGGRD);
   if (  (bLocalFRM_bCfmSenO2DsSigGrd != 0)
      || (  (SenO2Ds_bAcvEuro6SigGrdDiag_C == 0)
         || (SenO2Ds_bDgoORng_SigGrdDiag == 0)))
   {
      VEMS_vidSET(SenO2Ds_SigGrdFacMes_Obd6Mod, SenO2Ds_SigGrdFacMesRaw);
      VEMS_vidSET(SenO2Ds_SigGrdFacMin_Obd6Mod, SenO2Ds_SigGrdFacMinRaw);
   }
   if (SenO2Ds_bInhMonWait_sigGrd_C != 0)
   {
      SenO2Ds_bMonWaitORng_SigGrdDiag = DIAG_DISPO;
      if (  ( SenO2Ds_bMonRunRaw_SigGrdDiag != 0)
         && ( SenO2Ds_bMonWaitRaw_SigGrdDiag == 0))
      {
         SenO2Ds_bMonRunORng_SigGrdDiag = 1;
      }
      else
      {
         SenO2Ds_bMonRunORng_SigGrdDiag = 0;
      }
   }
   else
   {
      SenO2Ds_bMonWaitORng_SigGrdDiag = SenO2Ds_bMonWaitRaw_SigGrdDiag;
      SenO2Ds_bMonRunORng_SigGrdDiag = SenO2Ds_bMonRunRaw_SigGrdDiag;
   }
}

/*------------------------------- end of file --------------------------------*/