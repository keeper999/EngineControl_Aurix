/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SECUBV                                                  */
/* !Description     : SECUBV Component                                        */
/*                                                                            */
/* !Module          : SECUBV                                                  */
/* !Description     : Sécuriser Boites                                        */
/*                                                                            */
/* !File            : SECUBV_FCT2.C                                           */
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
/*   1 / SECUBV_vidStrategieRAZFctBoite                                       */
/*   2 / SECUBV_vidTraiChgRapSIPSdlNiv1V2                                     */
/*   3 / SECUBV_vidTraiChgRapInCpleNiv1V2                                     */
/*   4 / SECUBV_vidTrRegulRegAM6SdlNiv1V2                                     */
/*   5 / SECUBV_vidTraiChgRapSIPRun                                           */
/*   6 / SECUBV_vidTraiChgRapSIPRst                                           */
/*   7 / SECUBV_vidTraiChgRapInCpleRun                                        */
/*   8 / SECUBV_vidTraiChgRapInCpleRst                                        */
/*   9 / SECUBV_vidTrRegulRegAM6Run                                           */
/*   10 / SECUBV_vidTrRegulRegAM6Rst                                          */
/*                                                                            */
/* !Reference   : V02 NT 10 01251 / 03                                        */
/* !OtherRefs   : 01460_09_01310 / 1.2                                        */
/* !OtherRefs   : VEMS V02 ECU#047007                                         */
/* !OtherRefs   : VEMS V02 ECU#050657                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_FCT2.C_v$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SECUBV.h"
#include "SECUBV_L.h"
#include "SECUBV_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidStrategieRAZFctBoite                             */
/* !Description :  Cette fonction décrit la stratégie de reset pour la        */
/*                 fonction boite.                                            */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_039.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stTraTypCf;                                               */
/*  input boolean SftyMgt_bInhNbTarGearDeltaTqI_C;                            */
/*  input uint8 SftyMgt_noTraTypAL4_C;                                        */
/*  input uint8 SftyMgt_noTraTypMCP_C;                                        */
/*  input uint8 SftyMgt_noTraTypMAP_C;                                        */
/*  input uint8 SftyMgt_noTraTypAM6_C;                                        */
/*  output boolean SftyMgt_bEnaNbTarGearChgTqIRun;                            */
/*  output boolean SftyMgt_bEnaNbTarGearChgTqIRst;                            */
/*  output boolean SftyMgt_bEnaNbTarGearChgSIPRun;                            */
/*  output boolean SftyMgt_bEnaNbTarGearChgSIPRst;                            */
/*  output boolean SftyMgt_bEnaNRegReqChgSIPRun;                              */
/*  output boolean SftyMgt_bEnaNRegReqChgSIPRst;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidStrategieRAZFctBoite(void)
{
   uint8 u8LocalExt_stTraTypCf;


   /* F03_01_01_StrategieRAZFctBoite */

   VEMS_vidGET(Ext_stTraTypCf, u8LocalExt_stTraTypCf);

   if (SftyMgt_bInhNbTarGearDeltaTqI_C != 0)
   {
      SftyMgt_bEnaNbTarGearChgTqIRun = 0;
      SftyMgt_bEnaNbTarGearChgTqIRst = 1;
   }
   else
   {
      if (u8LocalExt_stTraTypCf == SftyMgt_noTraTypAL4_C)
      {
         SftyMgt_bEnaNbTarGearChgTqIRun = 1;
         SftyMgt_bEnaNbTarGearChgTqIRst = 0;
      }
      else
      {
         SftyMgt_bEnaNbTarGearChgTqIRun = 0;
         SftyMgt_bEnaNbTarGearChgTqIRst = 1;
      }
   }

   if (  (u8LocalExt_stTraTypCf == SftyMgt_noTraTypMCP_C)
      || (u8LocalExt_stTraTypCf == SftyMgt_noTraTypMAP_C)
      || (u8LocalExt_stTraTypCf == SftyMgt_noTraTypAM6_C))
   {
      SftyMgt_bEnaNbTarGearChgSIPRun = 1;
      SftyMgt_bEnaNbTarGearChgSIPRst = 0;
   }
   else
   {
      SftyMgt_bEnaNbTarGearChgSIPRun = 0;
      SftyMgt_bEnaNbTarGearChgSIPRst = 1;
   }

   if (u8LocalExt_stTraTypCf == SftyMgt_noTraTypAM6_C)
   {
      SftyMgt_bEnaNRegReqChgSIPRun = 1;
      SftyMgt_bEnaNRegReqChgSIPRst = 0;
   }
   else
   {
      SftyMgt_bEnaNRegReqChgSIPRun = 0;
      SftyMgt_bEnaNRegReqChgSIPRst = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTraiChgRapSIPSdlNiv1V2                           */
/* !Description :  Cette fonction gère la dynamique d’activation du niveau 1  */
/*                 qui a lieu lors de deux appels de la fonction de           */
/*                 surveillance au niveau 2.                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_040.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidTraiChgRapSIPRun();                            */
/*  extf argret void SECUBV_vidTraiChgRapSIPRst();                            */
/*  input boolean SftyMgt_bEnaNbTarGearChgSIPRun;                             */
/*  input boolean SftyMgt_bEnaNbTarGearChgSIPRst;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTraiChgRapSIPSdlNiv1V2(void)
{
   /* F03_01_02_TraitementChgRapportSIP_SdlNiv1VersSdlNiv2 */

   if (SftyMgt_bEnaNbTarGearChgSIPRun != 0)
   {
      SECUBV_vidTraiChgRapSIPRun();
   }

   if (SftyMgt_bEnaNbTarGearChgSIPRst != 0)
   {
      SECUBV_vidTraiChgRapSIPRst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTraiChgRapInCpleNiv1V2                           */
/* !Description :  Cette fonction gère la dynamique d’activation du niveau 1  */
/*                 qui a lieu lors de deux appels de la fonction de           */
/*                 surveillance au niveau 2.                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_044.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidTraiChgRapInCpleRun();                         */
/*  extf argret void SECUBV_vidTraiChgRapInCpleRst();                         */
/*  input boolean SftyMgt_bEnaNbTarGearChgTqIRun;                             */
/*  input boolean SftyMgt_bEnaNbTarGearChgTqIRst;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTraiChgRapInCpleNiv1V2(void)
{
   /* F03_01_03_TraitementChgRapportIntegraleSurcouple_SdlNiv1VersSdlNiv2 */

   if (SftyMgt_bEnaNbTarGearChgTqIRun != 0)
   {
      SECUBV_vidTraiChgRapInCpleRun();
   }

   if (SftyMgt_bEnaNbTarGearChgTqIRst != 0)
   {
      SECUBV_vidTraiChgRapInCpleRst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTrRegulRegAM6SdlNiv1V2                           */
/* !Description :  Cette fonction gère la dynamique d’activation du niveau 1  */
/*                 qui a lieu lors de deux appels de la fonction de           */
/*                 surveillance au niveau 2.                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_050.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidTrRegulRegAM6Run();                            */
/*  extf argret void SECUBV_vidTrRegulRegAM6Rst();                            */
/*  input boolean SftyMgt_bEnaNRegReqChgSIPRun;                               */
/*  input boolean SftyMgt_bEnaNRegReqChgSIPRst;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTrRegulRegAM6SdlNiv1V2(void)
{
   /* F03_01_04_TraitementRegulRegimeAM6_SdlNiv1VersSdlNiv2 */

   if (SftyMgt_bEnaNRegReqChgSIPRun != 0)
   {
      SECUBV_vidTrRegulRegAM6Run();
   }

   if (SftyMgt_bEnaNRegReqChgSIPRst != 0)
   {
      SECUBV_vidTrRegulRegAM6Rst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTraiChgRapSIPRun                                 */
/* !Description :  Ce bloc compare les valeurs de raport 1 à 1 pour détecter  */
/*                 une différence                                             */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_043.01                                     */
/*                 VEMS_R_10_01251_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input sint8 SftyMgt_prm_noTarGearTra[5];                                  */
/*  input boolean SftyMgt_bNbTarGearChgSIPRun;                                */
/*  output boolean SftyMgt_bNbTarGearChgSIPRun;                               */
/*  output boolean SftyMgt_bNbTarGearChgSIP;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTraiChgRapSIPRun(void)
{
   sint8 s8LocalSftyMgt_prm_noTarGearTra[SECUBV_u8ARRAY_LENGTH];
   /* QAC_Warning: Msg(2:3204): the array is an input */

   /* F03_01_02_01_Run */
   VEMS_vidGET1DArray(SftyMgt_prm_noTarGearTra,
                      SECUBV_u8ARRAY_LENGTH,
                      s8LocalSftyMgt_prm_noTarGearTra);

   if (  (s8LocalSftyMgt_prm_noTarGearTra[0] !=
          s8LocalSftyMgt_prm_noTarGearTra[1])
      || (s8LocalSftyMgt_prm_noTarGearTra[1] !=
          s8LocalSftyMgt_prm_noTarGearTra[2])
      || (s8LocalSftyMgt_prm_noTarGearTra[2] !=
          s8LocalSftyMgt_prm_noTarGearTra[3])
      || (s8LocalSftyMgt_prm_noTarGearTra[3] !=
          s8LocalSftyMgt_prm_noTarGearTra[4]))
   {
      SftyMgt_bNbTarGearChgSIPRun = 1;
   }
   else
   {
      SftyMgt_bNbTarGearChgSIPRun = 0;
   }
   SftyMgt_bNbTarGearChgSIP = SftyMgt_bNbTarGearChgSIPRun;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTraiChgRapSIPRst                                 */
/* !Description :  remise à zéro de SftyMgt_bNbTarGearChgSIPRst.              */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_042.01                                     */
/*                 VEMS_R_10_01251_043.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bNbTarGearChgSIPRst;                                */
/*  output boolean SftyMgt_bNbTarGearChgSIPRst;                               */
/*  output boolean SftyMgt_bNbTarGearChgSIP;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTraiChgRapSIPRst(void)
{
   /* F03_01_02_02_Rst */

   SftyMgt_bNbTarGearChgSIPRst = 0;
   SftyMgt_bNbTarGearChgSIP = SftyMgt_bNbTarGearChgSIPRst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTraiChgRapInCpleRun                              */
/* !Description :  Ce bloc compare les valeurs de rapport 1 à 1 pour détecter */
/*                 un changement                                              */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_047.01                                     */
/*                 VEMS_R_10_01251_049.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input sint8 SftyMgt_prm_noTarGearTra[5];                                  */
/*  input boolean SftyMgt_bNbTarGearChgTqIRun;                                */
/*  output boolean SftyMgt_bNbTarGearChgTqIRun;                               */
/*  output boolean SftyMgt_bNbTarGearChgTqI;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTraiChgRapInCpleRun(void)
{
   sint8 s8LocalSftyMgt_prm_noTarGearTra[SECUBV_u8ARRAY_LENGTH];
   /* QAC_Warning: Msg(2:3204): the array is an input */

   /* F03_01_03_01_Run */
   VEMS_vidGET1DArray(SftyMgt_prm_noTarGearTra,
                      SECUBV_u8ARRAY_LENGTH,
                      s8LocalSftyMgt_prm_noTarGearTra);

   if (  (s8LocalSftyMgt_prm_noTarGearTra[0] !=
          s8LocalSftyMgt_prm_noTarGearTra[1])
      || (s8LocalSftyMgt_prm_noTarGearTra[1] !=
          s8LocalSftyMgt_prm_noTarGearTra[2])
      || (s8LocalSftyMgt_prm_noTarGearTra[2] !=
          s8LocalSftyMgt_prm_noTarGearTra[3])
      || (s8LocalSftyMgt_prm_noTarGearTra[3] !=
          s8LocalSftyMgt_prm_noTarGearTra[4]))
   {
      SftyMgt_bNbTarGearChgTqIRun = 1;
   }
   else
   {
      SftyMgt_bNbTarGearChgTqIRun = 0;
   }
   SftyMgt_bNbTarGearChgTqI = SftyMgt_bNbTarGearChgTqIRun;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTraiChgRapInCpleRst                              */
/* !Description :  remise à zéro de SftyMgt_bNbTarGearChgTqIRst.              */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_048.01                                     */
/*                 VEMS_R_10_01251_049.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bNbTarGearChgTqIRst;                                */
/*  output boolean SftyMgt_bNbTarGearChgTqIRst;                               */
/*  output boolean SftyMgt_bNbTarGearChgTqI;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTraiChgRapInCpleRst(void)
{
   /* F03_01_03_02_Rst */

   SftyMgt_bNbTarGearChgTqIRst = 0;
   SftyMgt_bNbTarGearChgTqI = SftyMgt_bNbTarGearChgTqIRst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTrRegulRegAM6Run                                 */
/* !Description :  Compare les valeurs de régul de régime AM6 1 à 1 pour      */
/*                 détecter un changement.                                    */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_051.01                                     */
/*                 VEMS_R_10_01251_053.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input boolean SftyMgt_prm_bNRegReq[5];                                    */
/*  input boolean SftyMgt_bNRegReqChgSIPRun;                                  */
/*  output boolean SftyMgt_bNRegReqChgSIPRun;                                 */
/*  output boolean SftyMgt_bNRegReqChgSIP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTrRegulRegAM6Run(void)
{
   boolean bLocalSftyMgt_prm_bNRegReq[SECUBV_u8ARRAY_LENGTH];
   /* QAC_Warning: Msg(2:3204): the array is an input */

   /* F03_01_04_01_Run */
   VEMS_vidGET1DArray(SftyMgt_prm_bNRegReq,
                      SECUBV_u8ARRAY_LENGTH,
                      bLocalSftyMgt_prm_bNRegReq);

   if (  (bLocalSftyMgt_prm_bNRegReq[0] != bLocalSftyMgt_prm_bNRegReq[1])
      || (bLocalSftyMgt_prm_bNRegReq[1] != bLocalSftyMgt_prm_bNRegReq[2])
      || (bLocalSftyMgt_prm_bNRegReq[2] != bLocalSftyMgt_prm_bNRegReq[3])
      || (bLocalSftyMgt_prm_bNRegReq[3] != bLocalSftyMgt_prm_bNRegReq[4]))
   {
      SftyMgt_bNRegReqChgSIPRun = 1;
   }
   else
   {
      SftyMgt_bNRegReqChgSIPRun = 0;
   }
   SftyMgt_bNRegReqChgSIP = SftyMgt_bNRegReqChgSIPRun;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidTrRegulRegAM6Rst                                 */
/* !Description :  remise à zéro de SftyMgt_bNRegReqChgSIPRst                 */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_052.01                                     */
/*                 VEMS_R_10_01251_053.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bNRegReqChgSIPRst;                                  */
/*  output boolean SftyMgt_bNRegReqChgSIPRst;                                 */
/*  output boolean SftyMgt_bNRegReqChgSIP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidTrRegulRegAM6Rst(void)
{
   /* F03_01_04_02_Rst */

   SftyMgt_bNRegReqChgSIPRst = 0;
   SftyMgt_bNRegReqChgSIP = SftyMgt_bNRegReqChgSIPRst;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/