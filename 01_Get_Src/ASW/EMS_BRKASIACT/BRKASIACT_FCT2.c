/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIACT                                               */
/* !Description     : BRKASIACT Component.                                    */
/*                                                                            */
/* !Module          : BRKASIACT                                               */
/* !Description     : FONCTION ASSISTANCE DE FREINAGE                         */
/*                                                                            */
/* !File            : BRKASIACT_FCT2.C                                        */
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
/*   1 / BRKASIACT_vidAssistOFF                                               */
/*   2 / BRKASIACT_vidAssistALT_ON                                            */
/*   3 / BRKASIACT_vidAssistAC_ON                                             */
/*   4 / BRKASIACT_vidAssistALT_AC_ON                                         */
/*   5 / BRKASIACT_vidAssistALT_OFF_AC_ON                                     */
/*   6 / BRKASIACT_vidAssistALT_ON_AC_OFF                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 03258 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047998                                         */
/* !OtherRefs   : VEMS V02 ECU#060255                                         */
/* !OtherRefs   : 01460_10_00034 / 02                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/BRK/BRKASIACT/BRKASIACT_FC$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BRKASIACT.h"
#include "BRKASIACT_L.h"
#include "BRKASIACT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidAssistOFF                                     */
/* !Description :  Sous etat Assistance_OFF du superviseur                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bBrkAsiAcv;                                           */
/*  input boolean TqSys_bTqAltCnd;                                            */
/*  input boolean TqSys_bAcvBrkAsiImdtStra;                                   */
/*  input boolean TqSys_bTqACCnd;                                             */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidAssistOFF(void)
{
   if (TqSys_bBrkAsiAcv != 0)
   {
      if (  (TqSys_bTqAltCnd == 0)
         && (TqSys_bAcvBrkAsiImdtStra == 0))
      {
         VEMS_vidSET(TqSys_stBrkAsi, 1);
         VEMS_vidSET(TqSys_bRlsAltBrkAsi, 1);
         VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
      }
      else
      {
         if (TqSys_bAcvBrkAsiImdtStra != 0)
         {
            VEMS_vidSET(TqSys_stBrkAsi, 3);
            VEMS_vidSET(TqSys_bRlsAltBrkAsi, 1);
            VEMS_vidSET(TqSys_bInhACBrkAsi, 1);
         }
         else
         {
            if (TqSys_bTqACCnd != 0)
            {
               VEMS_vidSET(TqSys_stBrkAsi, 3);
               VEMS_vidSET(TqSys_bRlsAltBrkAsi, 1);
               VEMS_vidSET(TqSys_bInhACBrkAsi, 1);
            }
            else
            {
               VEMS_vidSET(TqSys_stBrkAsi, 2);
               VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
               VEMS_vidSET(TqSys_bInhACBrkAsi, 1);
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidAssistALT_ON                                  */
/* !Description :  sous etat Assistance_ALT_ON du superviseur                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bBrkAsiAcv;                                           */
/*  input uint16 TqSys_tiRlsAltBrkAsi;                                        */
/*  input uint16 TqSys_tiBrkAsiAltMax;                                        */
/*  input uint16 TqSys_tiRlsAltWait;                                          */
/*  input uint16 TqSys_tiRlsAltWaitMax;                                       */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidAssistALT_ON(void)
{
   if (  (TqSys_bBrkAsiAcv == 0)
      || (TqSys_tiRlsAltBrkAsi >= TqSys_tiBrkAsiAltMax))
   {
      VEMS_vidSET(TqSys_stBrkAsi, 0);
      VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
      VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
      TqSys_tiRlsAltWait = 0;
      TqSys_tiRlsAltBrkAsi = 0;
      TqSys_tiInhACWait = 0;
      TqSys_tiInhACBrkAsi = 0;
   }
   else
   {
      if (TqSys_tiRlsAltWait >= TqSys_tiRlsAltWaitMax)
      {
         VEMS_vidSET(TqSys_stBrkAsi, 3);
         VEMS_vidSET(TqSys_bRlsAltBrkAsi, 1);
         VEMS_vidSET(TqSys_bInhACBrkAsi, 1);
      }
      else
      {
         if (TqSys_tiRlsAltBrkAsi < 999)
         {
            TqSys_tiRlsAltBrkAsi = (uint16)(TqSys_tiRlsAltBrkAsi + 1);
         }
         else
         {
            TqSys_tiRlsAltBrkAsi = 1000;
         }

         if (TqSys_tiRlsAltWait < 999)
         {
            TqSys_tiRlsAltWait = (uint16)(TqSys_tiRlsAltWait + 1);
         }
         else
         {
            TqSys_tiRlsAltWait = 1000;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidAssistAC_ON                                   */
/* !Description :  sous etat Assistance_AC_ON du superviseur                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bBrkAsiAcv;                                           */
/*  input uint16 TqSys_tiInhACBrkAsi;                                         */
/*  input uint16 TqSys_tiBrkAsiACMax;                                         */
/*  input uint16 TqSys_tiInhACWait;                                           */
/*  input uint16 TqSys_tiInhACWaitMax;                                        */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidAssistAC_ON(void)
{
   if (  (TqSys_bBrkAsiAcv == 0)
      || (TqSys_tiInhACBrkAsi >= TqSys_tiBrkAsiACMax))
   {
      VEMS_vidSET(TqSys_stBrkAsi, 0);
      VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
      VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
      TqSys_tiRlsAltWait = 0;
      TqSys_tiRlsAltBrkAsi = 0;
      TqSys_tiInhACWait = 0;
      TqSys_tiInhACBrkAsi = 0;
   }
   else
   {
      if (TqSys_tiInhACWait >= TqSys_tiInhACWaitMax)
      {
         VEMS_vidSET(TqSys_stBrkAsi, 3);
         VEMS_vidSET(TqSys_bRlsAltBrkAsi, 1);
         VEMS_vidSET(TqSys_bInhACBrkAsi, 1);
      }
      else
      {
         if (TqSys_tiInhACBrkAsi < 999)
         {
            TqSys_tiInhACBrkAsi = (uint16)(TqSys_tiInhACBrkAsi + 1);
         }
         else
         {
            TqSys_tiInhACBrkAsi = 1000;
         }

         if (TqSys_tiInhACWait < 999)
         {
            TqSys_tiInhACWait = (uint16)(TqSys_tiInhACWait + 1);
         }
         else
         {
            TqSys_tiInhACWait = 1000;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidAssistALT_AC_ON                               */
/* !Description :  sous etat Assistance_ALT_AC_ON du superviseur              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bBrkAsiAcv;                                           */
/*  input uint16 TqSys_tiRlsAltBrkAsi;                                        */
/*  input uint16 TqSys_tiBrkAsiAltMax;                                        */
/*  input uint16 TqSys_tiInhACBrkAsi;                                         */
/*  input uint16 TqSys_tiBrkAsiACMax;                                         */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidAssistALT_AC_ON(void)
{
   if (TqSys_bBrkAsiAcv == 0)
   {
      VEMS_vidSET(TqSys_stBrkAsi, 0);
      VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
      VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
      TqSys_tiRlsAltWait = 0 ;
      TqSys_tiRlsAltBrkAsi = 0 ;
      TqSys_tiInhACWait = 0 ;
      TqSys_tiInhACBrkAsi = 0 ;
   }
   else
   {
      if (TqSys_tiRlsAltBrkAsi >= TqSys_tiBrkAsiAltMax)
      {
         if (TqSys_tiInhACBrkAsi >= TqSys_tiBrkAsiACMax)
         {
            VEMS_vidSET(TqSys_stBrkAsi, 0);
            VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
            VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
            TqSys_tiRlsAltWait = 0 ;
            TqSys_tiRlsAltBrkAsi = 0 ;
            TqSys_tiInhACWait = 0 ;
            TqSys_tiInhACBrkAsi = 0 ;
         }
         else
         {
            VEMS_vidSET(TqSys_stBrkAsi, 4);
            VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
            VEMS_vidSET(TqSys_bInhACBrkAsi, 1);
         }
      }
      else
      {
         if (TqSys_tiInhACBrkAsi >= TqSys_tiBrkAsiACMax)
         {
            VEMS_vidSET(TqSys_stBrkAsi, 5);
            VEMS_vidSET(TqSys_bRlsAltBrkAsi, 1);
            VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
         }
         else
         {
            if (TqSys_tiRlsAltBrkAsi < 999)
            {
               TqSys_tiRlsAltBrkAsi = (uint16)(TqSys_tiRlsAltBrkAsi + 1);
            }
            else
            {
               TqSys_tiRlsAltBrkAsi = 1000;
            }

            if (TqSys_tiInhACBrkAsi < 999)
            {
               TqSys_tiInhACBrkAsi = (uint16)(TqSys_tiInhACBrkAsi + 1);
            }
            else
            {
               TqSys_tiInhACBrkAsi = 1000;
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidAssistALT_OFF_AC_ON                           */
/* !Description :  sous etat Assistance_ALT_OFF_AC_ON du superviseur          */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_tiInhACBrkAsi;                                         */
/*  input uint16 TqSys_tiBrkAsiACMax;                                         */
/*  input boolean TqSys_bBrkAsiAcv;                                           */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidAssistALT_OFF_AC_ON(void)
{
   if (  (TqSys_tiInhACBrkAsi >= TqSys_tiBrkAsiACMax)
      || (TqSys_bBrkAsiAcv == 0))
   {
      VEMS_vidSET(TqSys_stBrkAsi, 0);
      VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
      VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
      TqSys_tiRlsAltWait = 0 ;
      TqSys_tiRlsAltBrkAsi = 0 ;
      TqSys_tiInhACWait = 0 ;
      TqSys_tiInhACBrkAsi = 0 ;
   }
   else
   {
      if (TqSys_tiInhACBrkAsi < 999)
      {
         TqSys_tiInhACBrkAsi = (uint16)(TqSys_tiInhACBrkAsi + 1);
      }
      else
      {
         TqSys_tiInhACBrkAsi = 1000;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACT_vidAssistALT_ON_AC_OFF                           */
/* !Description :  sous etat Assistance_ALT_ON_AC_OFF du superviseur          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_01937_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bBrkAsiAcv;                                           */
/*  input uint16 TqSys_tiRlsAltBrkAsi;                                        */
/*  input uint16 TqSys_tiBrkAsiAltMax;                                        */
/*  output uint8 TqSys_stBrkAsi;                                              */
/*  output boolean TqSys_bRlsAltBrkAsi;                                       */
/*  output boolean TqSys_bInhACBrkAsi;                                        */
/*  output uint16 TqSys_tiRlsAltWait;                                         */
/*  output uint16 TqSys_tiRlsAltBrkAsi;                                       */
/*  output uint16 TqSys_tiInhACWait;                                          */
/*  output uint16 TqSys_tiInhACBrkAsi;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACT_vidAssistALT_ON_AC_OFF(void)
{
   if (  (TqSys_bBrkAsiAcv == 0)
      || (TqSys_tiRlsAltBrkAsi >= TqSys_tiBrkAsiAltMax))
   {
      VEMS_vidSET(TqSys_stBrkAsi, 0);
      VEMS_vidSET(TqSys_bRlsAltBrkAsi, 0);
      VEMS_vidSET(TqSys_bInhACBrkAsi, 0);
      TqSys_tiRlsAltWait = 0 ;
      TqSys_tiRlsAltBrkAsi = 0 ;
      TqSys_tiInhACWait = 0 ;
      TqSys_tiInhACBrkAsi = 0 ;
   }
   else
   {
      if (TqSys_tiRlsAltBrkAsi < 999)
      {
         TqSys_tiRlsAltBrkAsi = (uint16)(TqSys_tiRlsAltBrkAsi + 1);
      }
      else
      {
         TqSys_tiRlsAltBrkAsi = 1000;
      }
   }
}

/*--------------------------------- end of file ------------------------------*/