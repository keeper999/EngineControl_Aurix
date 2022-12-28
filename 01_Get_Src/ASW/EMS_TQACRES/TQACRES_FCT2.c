/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQACRES                                                 */
/* !Description     : TQACRES Component                                       */
/*                                                                            */
/* !Module          : TQACRES                                                 */
/* !Description     : Réserve de couple climatisation                         */
/*                                                                            */
/* !File            : TQACRES_FCT2.C                                          */
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
/*   1 / TQACRES_vidCondition_reserve_AC4                                     */
/*   2 / TQACRES_vidTransHorsRes                                              */
/*   3 / TQACRES_vidTransAttEmbrayage                                         */
/*   4 / TQACRES_vidTransDefSeqEmbrayage                                      */
/*   5 / TQACRES_vidTransAttDebrayage                                         */
/*   6 / TQACRES_vidTransMaintReserve                                         */
/*   7 / TQACRES_vidActivation_Calcul                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 04980 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0181 / 2.3                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQACRES/TQACRES_F$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQACRES.h"
#include "TQACRES_L.h"
#include "TQACRES_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidCondition_reserve_AC4                           */
/* !Description :  Fonction qui traite la condition réserve Climatisation 4   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQACRES_vidTransHorsRes();                               */
/*  extf argret void TQACRES_vidTransAttEmbrayage();                          */
/*  extf argret void TQACRES_vidTransDefSeqEmbrayage();                       */
/*  extf argret void TQACRES_vidTransAttDebrayage();                          */
/*  extf argret void TQACRES_vidTransMaintReserve();                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st18 TQACRES_StActual_Status;                                       */
/*  output st18 TQACRES_StActual_Status;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidCondition_reserve_AC4(void)
{
   switch (TQACRES_StActual_Status)
   {
      case HORS_RESERVE:
         TQACRES_vidTransHorsRes();
      break;

      case ATTENTE_EMBRAYAGE:
         TQACRES_vidTransAttEmbrayage();
      break;

      case DEFAUT_SEQUENCE_EMBRAYAGE:
         TQACRES_vidTransDefSeqEmbrayage();
      break;

      case ATTENTE_DEBRAYAGE:
         TQACRES_vidTransAttDebrayage();
      break;

      case MAINTIEN_RESERVE:
         TQACRES_vidTransMaintReserve();
      break;

      default:
         TQACRES_StActual_Status = HORS_RESERVE;
         SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidTransHorsRes                                    */
/* !Description :  Fonction de transition de l'etat HORS_RESERVE              */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AC_bACClu;                                                  */
/*  input uint8 AC_pwrAC;                                                     */
/*  output st18 TQACRES_StActual_Status;                                      */
/*  output boolean TqRes_bCdnAC4Res;                                          */
/*  output boolean TqRes_bDftAC4SwtOn;                                        */
/*  output uint16 TqRes_tiCplAC4Res_MP;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidTransHorsRes(void)
{
   boolean bLocal_AC_bACClu;
   uint8   u8Local_AC_pwrAC;


   VEMS_vidGET(AC_bACClu, bLocal_AC_bACClu);
   if (bLocal_AC_bACClu != 0)
   {
      TQACRES_StActual_Status = DEFAUT_SEQUENCE_EMBRAYAGE;
      TqRes_bCdnAC4Res = 0;
      TqRes_bDftAC4SwtOn = 1;
   }
   else
   {
      VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);
      if (u8Local_AC_pwrAC > 0)
      {
         TQACRES_StActual_Status = ATTENTE_EMBRAYAGE;
         TqRes_bCdnAC4Res = 1;
         TqRes_bDftAC4SwtOn = 0;
         TqRes_tiCplAC4Res_MP = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidTransAttEmbrayage                               */
/* !Description :  Fonction de transition de l'etat ATTENTE_EMBRAYAGE         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 AC_pwrAC;                                                     */
/*  input uint16 TqRes_tiCplAC4Res_MP;                                        */
/*  input uint16 TqRes_tiAC4ResTmpMax;                                        */
/*  input boolean AC_bACClu;                                                  */
/*  output st18 TQACRES_StActual_Status;                                      */
/*  output boolean TqRes_bCdnAC4Res;                                          */
/*  output boolean TqRes_bDftAC4SwtOn;                                        */
/*  output uint16 TqRes_tiAcvAC4Res_MP;                                       */
/*  output uint16 TqRes_tiCplAC4Res_MP;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidTransAttEmbrayage(void)
{
   boolean bLocal_AC_bACClu;
   uint8   u8Local_AC_pwrAC;
   uint16  u16LocaltiCplAC4Res_MP;


   VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);

   if (u8Local_AC_pwrAC == 0)
   {
      TQACRES_StActual_Status = HORS_RESERVE;
      TqRes_bCdnAC4Res = 0;
      TqRes_bDftAC4SwtOn = 0;
   }
   else
   {
      if (TqRes_tiCplAC4Res_MP >= TqRes_tiAC4ResTmpMax)
      {
         TQACRES_StActual_Status = DEFAUT_SEQUENCE_EMBRAYAGE;
         TqRes_bCdnAC4Res = 0;
         TqRes_bDftAC4SwtOn = 1;
      }
      else
      {
         VEMS_vidGET(AC_bACClu, bLocal_AC_bACClu);
         if (bLocal_AC_bACClu != 0)
         {
            TQACRES_StActual_Status = MAINTIEN_RESERVE;
            TqRes_tiAcvAC4Res_MP = 0;
         }
         else
         {
            u16LocaltiCplAC4Res_MP = (uint16)(TqRes_tiCplAC4Res_MP + 1);
            TqRes_tiCplAC4Res_MP =
               (uint16)MATHSRV_udtMIN(u16LocaltiCplAC4Res_MP, 1500);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidTransDefSeqEmbrayage                            */
/* !Description :  Fonction de transition de l'etat DEFAUT_SEQUENCE_EMBRAYAGE */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 AC_pwrAC;                                                     */
/*  input boolean AC_bACClu;                                                  */
/*  output st18 TQACRES_StActual_Status;                                      */
/*  output boolean TqRes_bCdnAC4Res;                                          */
/*  output boolean TqRes_bDftAC4SwtOn;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidTransDefSeqEmbrayage(void)
{
   boolean bLocal_AC_bACClu;
   uint8   u8Local_AC_pwrAC;


   VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);
   VEMS_vidGET(AC_bACClu, bLocal_AC_bACClu);
   if ( (u8Local_AC_pwrAC == 0)
      &&(bLocal_AC_bACClu == 0))
   {
      TQACRES_StActual_Status = HORS_RESERVE;
      TqRes_bCdnAC4Res = 0;
      TqRes_bDftAC4SwtOn = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidTransAttDebrayage                               */
/* !Description :  Fonction de transition de l'etat  ATTENTE_DEBRAYAGE        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AC_bACClu;                                                  */
/*  input uint8 AC_pwrAC;                                                     */
/*  input boolean TqRes_bInhResACCluOp_C;                                     */
/*  output st18 TQACRES_StActual_Status;                                      */
/*  output boolean TqRes_bCdnAC4Res;                                          */
/*  output boolean TqRes_bDftAC4SwtOn;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidTransAttDebrayage(void)
{
   boolean bLocal_AC_bACClu;
   uint8   u8Local_AC_pwrAC;


   VEMS_vidGET(AC_bACClu, bLocal_AC_bACClu);
   VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);
   if (  (bLocal_AC_bACClu == 0)
      && (  (u8Local_AC_pwrAC == 0)
         || (TqRes_bInhResACCluOp_C != 0)))
   {
      TQACRES_StActual_Status = HORS_RESERVE;
      TqRes_bCdnAC4Res = 0;
      TqRes_bDftAC4SwtOn = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidTransMaintReserve                               */
/* !Description :  Fonction de transition de l'etat MAINTIEN_RESERVE          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AC_bACClu;                                                  */
/*  input uint8 AC_pwrAC;                                                     */
/*  input boolean TqRes_bInhResACCluOp_C;                                     */
/*  input uint16 TqRes_tiAcvAC4Res_MP;                                        */
/*  input uint16 TqRes_tiAC4Res;                                              */
/*  output st18 TQACRES_StActual_Status;                                      */
/*  output boolean TqRes_bCdnAC4Res;                                          */
/*  output boolean TqRes_bDftAC4SwtOn;                                        */
/*  output uint16 TqRes_tiAcvAC4Res_MP;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidTransMaintReserve(void)
{
   boolean bLocal_AC_bACClu;
   uint8   u8Local_AC_pwrAC;
   uint16  u16LocaltiAcvAC4Res_MP;


   VEMS_vidGET(AC_bACClu, bLocal_AC_bACClu);
   VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);
   if (  (bLocal_AC_bACClu == 0)
      && (  (u8Local_AC_pwrAC == 0)
         || (TqRes_bInhResACCluOp_C != 0)))
   {
      TQACRES_StActual_Status = HORS_RESERVE;
      TqRes_bCdnAC4Res = 0;
      TqRes_bDftAC4SwtOn = 0;
   }
   else
   {
      if (  (TqRes_tiAcvAC4Res_MP >= TqRes_tiAC4Res)
         || (  (bLocal_AC_bACClu == 0)
            && (TqRes_bInhResACCluOp_C == 0)))
      {
         TQACRES_StActual_Status = ATTENTE_DEBRAYAGE;
         TqRes_bCdnAC4Res = 0;
      }
      else
      {
         u16LocaltiAcvAC4Res_MP = (uint16)(TqRes_tiAcvAC4Res_MP + 1);
         TqRes_tiAcvAC4Res_MP =
            (uint16)MATHSRV_udtMIN(u16LocaltiAcvAC4Res_MP, 1500);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidActivation_Calcul                               */
/* !Description :  Le choix du trigger pour l’appel de la fonction se fait en */
/*                 fonction du régime moteur                                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqRes_nEngThdOptmRes_C;                                      */
/*  output boolean TqRes_bAcvOptmTqACRes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidActivation_Calcul(void)
{
   uint16  u16LocalEng_nCkFil;
   uint32  u32LocalnEngThdOptmResHi;
   sint32  s32LocalnEngThdOptmResLo;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u32LocalnEngThdOptmResHi = (uint32)(TqRes_nEngThdOptmRes_C * 4);
   s32LocalnEngThdOptmResLo = (sint32)((TqRes_nEngThdOptmRes_C * 4) - 200);

   if (u16LocalEng_nCkFil <= s32LocalnEngThdOptmResLo)
   {
      TqRes_bAcvOptmTqACRes = 0;
   }
   else
   {
      if (u16LocalEng_nCkFil >= u32LocalnEngThdOptmResHi)
      {
         TqRes_bAcvOptmTqACRes = 1;
      }
   }
}
/*------------------------------- end of file --------------------------------*/