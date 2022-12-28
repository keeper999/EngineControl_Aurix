/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LAMCLMPD                                                */
/* !Description     : LAMCLMPD component                                      */
/*                                                                            */
/* !Module          : LAMCLMPD                                                */
/* !Description     : Régulation De Richesse En Butée                         */
/*                                                                            */
/* !File            : LAMCLMPD_FCT1.c                                         */
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
/*   1 / LAMCLMPD_vidInitIndicRichActobd                                      */
/*   2 / LAMCLMPD_vidRichCalcIndicators                                       */
/*                                                                            */
/* !Reference   : V02 NT 09 02030 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/LAMCLMPD/LAMCLMPD_FCT1$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   25 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   25 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "std_types.h"
#include "MATHSRV.h"
#include "LAMCLMPD.h"
#include "LAMCLMPD_L.h"
#include "LAMCLMPD_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAMCLMPD_vidInitIndicRichActobd                            */
/* !Description :  Fonction qui permet l'initialisation Indicateur de         */
/*                 Lambda_feeback en butée basse (mélange riche) et Haute     */
/*                 (mélange pauvre).                                          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Lfbk_on_enrich_clamp;                                      */
/*  output boolean Lfbk_on_enlean_clamp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAMCLMPD_vidInitIndicRichActobd(void)
{
   VEMS_vidSET(Lfbk_on_enrich_clamp,0);
   VEMS_vidSET(Lfbk_on_enlean_clamp,0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LAMCLMPD_vidRichCalcIndicators                             */
/* !Description :  Fonction qui détermine les indicateurs de richesse.        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback;                                             */
/*  input uint8 Lfbk_on_enrich_thresh;                                        */
/*  input sint16 Lfbk_on_enlean_thresh;                                       */
/*  output boolean Lfbk_on_enlean_clamp;                                      */
/*  output boolean Lfbk_on_enrich_clamp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LAMCLMPD_vidRichCalcIndicators(void)
{
   uint16 u16LocalMulti;
   sint16 s16LocalMulti;
   sint16 s16LocalLambda_feedback;


   VEMS_vidGET(Lambda_feedback,s16LocalLambda_feedback);
   u16LocalMulti = (uint16)(Lfbk_on_enrich_thresh * 128);
   if (s16LocalLambda_feedback >= u16LocalMulti)
   {
      VEMS_vidSET(Lfbk_on_enlean_clamp,0);
      VEMS_vidSET(Lfbk_on_enrich_clamp,1);
   }
   else
   {
      s16LocalMulti = (sint16)(Lfbk_on_enlean_thresh * 128);
      if (s16LocalLambda_feedback <= s16LocalMulti)
      {
         VEMS_vidSET(Lfbk_on_enlean_clamp,1);
         VEMS_vidSET(Lfbk_on_enrich_clamp,0);
      }
      else
      {
         VEMS_vidSET(Lfbk_on_enlean_clamp,0);
         VEMS_vidSET(Lfbk_on_enrich_clamp,0);
      }
   }
}
/*------------------------------- end of file --------------------------------*/