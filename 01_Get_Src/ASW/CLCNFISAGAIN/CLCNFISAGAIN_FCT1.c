/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLCNFISAGAIN                                            */
/* !Description     : CLCNFISAGAIN Component.                                 */
/*                                                                            */
/* !Module          : CLCNFISAGAIN                                            */
/* !Description     : Calcul des coefficients de correction liés à la FISA.   */
/*                                                                            */
/* !File            : CLCNFISAGAIN_FCT1.C                                     */
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
/*   1 / CLCNFISAGAIN_vidInitOutput                                           */
/*   2 / CLCNFISAGAIN_vidCalculCoeff                                          */
/*   3 / CLCNFISAGAIN_vidAllowedWrite                                         */
/*                                                                            */
/* !Reference   : V02 NT 08 04650 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CLCNFISAGAIN/CLCNFISAGAIN_FCT1.C_v$*/
/* $Revision::   1.5      $$Author::   achebino       $$Date::   27 Nov 2013 $*/
/* $Author::   achebino                               $$Date::   27 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MATHSRV.h"
#include "CLCNFISAGAIN.h"
#include "CLCNFISAGAIN_L.h"
#include "CLCNFISAGAIN_im.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLCNFISAGAIN_vidInitOutput                                 */
/* !Description :  Initialisation des sorrties.                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 FISA_facOld_nvm;                                              */
/*  output uint16 FISA_facWupAdp;                                             */
/*  output uint8 FISA_facTranAdp;                                             */
/*  output uint16 FISA_facStrtAdp;                                            */
/*  output uint16 FISA_facAstAdp;                                             */
/*  output uint8 FISA_facOld;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLCNFISAGAIN_vidInitOutput(void)
{
   uint8 u8LocalFISA_facOld_nvm;


   VEMS_vidSET(FISA_facWupAdp, 0);
   VEMS_vidSET(FISA_facTranAdp, 0);
   VEMS_vidSET(FISA_facStrtAdp, 0);
   VEMS_vidSET(FISA_facAstAdp, 0);
   u8LocalFISA_facOld_nvm = (uint8)MATHSRV_udtMIN(FISA_facOld_nvm, 128);
   VEMS_vidSET(FISA_facOld, u8LocalFISA_facOld_nvm);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLCNFISAGAIN_vidCalculCoeff                                */
/* !Description :  Cette fonction permet le calcul des corrections strictement*/
/*                 nécessaires aux réglages de bases d’enrichissements au     */
/*                 démarrage, post démarrage et réchauffage moteur à partir de*/
/*                 la valeur du coefficient de qualité carburant calculé au   */
/*                 sein de FISA.                                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04650_003.01                                     */
/*                 VEMS_R_08_04650_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 FISA_facAdp;                                                  */
/*  input uint8 FISA_Enrich_tCoMesX_A[12];                                    */
/*  input uint8 FISA_Enrich_facAdpY_A[5];                                     */
/*  input uint16 FISA_facAstAdp_M[12][5];                                     */
/*  input uint16 FISA_facStrtAdp_M[12][5];                                    */
/*  input uint8 FISA_facTranAdp_M[12][5];                                     */
/*  input uint16 FISA_facWupAdp_M[12][5];                                     */
/*  output uint16 FISA_facAstAdp;                                             */
/*  output uint16 FISA_facStrtAdp;                                            */
/*  output uint8 FISA_facTranAdp;                                             */
/*  output uint16 FISA_facWupAdp;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLCNFISAGAIN_vidCalculCoeff(void)
{
   uint16 u16LocalSitInterpX1;
   uint16 u16LocalFISA_facAstAdp;
   uint16 u16LocalFISA_facStrtAdp;
   uint16 u16LocalFISA_facWupAdp;
   uint16 u16LocalSitInterpY1;
   sint16 s16LocalExt_tCoMes;
   uint8  u8LocalFISA_facAdp;
   uint8  u8LocalExt_tCoMesClamp;
   uint8  u8LocalFISA_facTranAdp;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(FISA_facAdp, u8LocalFISA_facAdp);
   u8LocalExt_tCoMesClamp = (uint8)MATHSRV_udtCLAMP(s16LocalExt_tCoMes
                                                    + 40, 0, 254);
   u16LocalSitInterpX1 = MATHSRV_u16CalcParaIncAryU8(FISA_Enrich_tCoMesX_A,
                                                     u8LocalExt_tCoMesClamp,
                                                     12);
   u16LocalSitInterpY1 = MATHSRV_u16CalcParaIncAryU8( FISA_Enrich_facAdpY_A,
                                                      u8LocalFISA_facAdp,
                                                      5);
   u16LocalFISA_facAstAdp = MATHSRV_u16Interp2d( &FISA_facAstAdp_M[0][0],
                                                 u16LocalSitInterpX1,
                                                 u16LocalSitInterpY1,
                                                 5);
   u16LocalFISA_facAstAdp = (uint16)MATHSRV_udtMIN(u16LocalFISA_facAstAdp,
                                                   1280);
   VEMS_vidSET(FISA_facAstAdp, u16LocalFISA_facAstAdp);
   u16LocalFISA_facStrtAdp = MATHSRV_u16Interp2d( &FISA_facStrtAdp_M[0][0],
                                                  u16LocalSitInterpX1,
                                                  u16LocalSitInterpY1,
                                                  5);
   u16LocalFISA_facStrtAdp = (uint16)MATHSRV_udtMIN(u16LocalFISA_facStrtAdp,
                                                    1280);
   VEMS_vidSET(FISA_facStrtAdp, u16LocalFISA_facStrtAdp);
   u8LocalFISA_facTranAdp = MATHSRV_u8Interp2d( &FISA_facTranAdp_M[0][0],
                                                u16LocalSitInterpX1,
                                                u16LocalSitInterpY1,
                                                5);
   u8LocalFISA_facTranAdp = (uint8)MATHSRV_udtMIN(u8LocalFISA_facTranAdp, 128);
   VEMS_vidSET(FISA_facTranAdp, u8LocalFISA_facTranAdp);
   u16LocalFISA_facWupAdp = MATHSRV_u16Interp2d( &FISA_facWupAdp_M[0][0],
                                                 u16LocalSitInterpX1,
                                                 u16LocalSitInterpY1,
                                                 5);
   u16LocalFISA_facWupAdp = (uint16)MATHSRV_udtMIN(u16LocalFISA_facWupAdp,
                                                   1280);
   VEMS_vidSET(FISA_facWupAdp, u16LocalFISA_facWupAdp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLCNFISAGAIN_vidAllowedWrite                               */
/* !Description :  La valeur de FISA_facAdp est stockée en mémoire non        */
/*                 volatile au powerlatch si l'autorisation de sauvegarde est */
/*                 donnée par le superviseur (FISA_bAuthSave à 1              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_00000_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean FISA_bAuthSave;                                             */
/*  input uint8 FISA_facAdp;                                                  */
/*  input uint8 FISA_facOld_nvm;                                              */
/*  input uint8 FISA_facOld;                                                  */
/*  output uint8 FISA_facOld_nvm;                                             */
/*  output uint8 FISA_facOld;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLCNFISAGAIN_vidAllowedWrite(void)
{
   boolean bLocalFISA_bAuthSave;
   uint8   u8LocalFISA_facAdp;
   uint8   u8LocalFISA_facOld;


   VEMS_vidGET(FISA_bAuthSave, bLocalFISA_bAuthSave);
   VEMS_vidGET(FISA_facAdp, u8LocalFISA_facAdp);
   if (bLocalFISA_bAuthSave != 0)
   {
      FISA_facOld_nvm = (uint8)MATHSRV_udtMIN(u8LocalFISA_facAdp, 128);
      VEMS_vidSET(FISA_facOld, FISA_facOld_nvm);
   }
   else
   {
      VEMS_vidGET(FISA_facOld, u8LocalFISA_facOld);
      u8LocalFISA_facOld = (uint8)MATHSRV_udtMIN(u8LocalFISA_facOld, 128);
      VEMS_vidSET(FISA_facOld, u8LocalFISA_facOld);
      FISA_facOld_nvm = (uint8)MATHSRV_udtMIN(FISA_facOld_nvm, 128);
   }
}

/*------------------------------- end of file --------------------------------*/