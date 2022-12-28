/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSVLD                                                */
/* !Description     : TQSYSVLD component.                                     */
/*                                                                            */
/* !Module          : TQSYSVLD                                                */
/* !Description     : VALIDITE DES INFORMATIONS COUPLE.                       */
/*                                                                            */
/* !File            : TQSYSVLD_FCT1.C                                         */
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
/*   1 / TQSYSVLD_vidInit                                                     */
/*   2 / TQSYSVLD_vidDiagMisfire                                              */
/*   3 / TQSYSVLD_vidNoWght                                                   */
/*   4 / TQSYSVLD_vidTqCkEngReal                                              */
/*   5 / TQSYSVLD_vidTqEM                                                     */
/*   6 / TQSYSVLD_vidStDiagESPReq                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 04105 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/TQSYSVLD/TQSYSVLD_FCT1.C_v        $*/
/* $Revision::   1.1      $$Author::   pcabariq       $$Date::   15 Dec 2009 $*/
/* $Author::   pcabariq                               $$Date::   15 Dec 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQSYSVLD.h"
#include "TQSYSVLD_L.h"
#include "TQSYSVLD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidInit                                           */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 Spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean TqDiag_bUncrt_tqCkEngReal;                                 */
/*  output boolean TqDiag_bInvld_tqCkEngReal;                                 */
/*  output boolean TqDiag_bUncrt_tqEM;                                        */
/*  output boolean TqDiag_bInvld_tqEM;                                        */
/*  output uint8 TqDiag_stDiagESPReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidInit(void)
{
   VEMS_vidSET(TqDiag_bUncrt_tqCkEngReal, 0);
   VEMS_vidSET(TqDiag_bInvld_tqCkEngReal, 0);
   VEMS_vidSET(TqDiag_bUncrt_tqEM, 0);
   VEMS_vidSET(TqDiag_bInvld_tqEM, 0);
   VEMS_vidSET(TqDiag_stDiagESPReq, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidDiagMisfire                                    */
/* !Description :  A partir de l'information " taux de ratés de combustion"   */
/*                 produite par le diagnostic Misfire(200tr), cette fonction  */
/*                 produit et consomme en interne les informations suivantes: */
/*                 Diag_misfire_bas_EM, Diag_misfire_haut_EM, Diag_misfire_bas*/
/*                 et Diag_misfire_haut.                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Mf_cat_dam_mf_rate_uavn0;                                     */
/*  input uint8 TqDiag_thdMisfLoEM_C;                                         */
/*  input uint8 TqDiag_thdMisfHiEM_C;                                         */
/*  input uint8 TqDiag_thdMisfLo_C;                                           */
/*  input uint8 TqDiag_thdMisfHi_C;                                           */
/*  output boolean Diag_misfire_bas_EM;                                       */
/*  output boolean Diag_misfire_haut_EM;                                      */
/*  output boolean Diag_misfire_bas;                                          */
/*  output boolean Diag_misfire_haut;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidDiagMisfire(void)
{
   uint8 u8LocalMf_cat_dam_mf_rate_uavn0;


   VEMS_vidGET(Mf_cat_dam_mf_rate_uavn0, u8LocalMf_cat_dam_mf_rate_uavn0);
   if (u8LocalMf_cat_dam_mf_rate_uavn0 >= TqDiag_thdMisfLoEM_C)
   {
      Diag_misfire_bas_EM = 1;
   }
   else
   {
      Diag_misfire_bas_EM = 0;
   }

   if (u8LocalMf_cat_dam_mf_rate_uavn0 >= TqDiag_thdMisfHiEM_C)
   {
      Diag_misfire_haut_EM = 1;
   }
   else
   {
      Diag_misfire_haut_EM = 0;
   }

   if (u8LocalMf_cat_dam_mf_rate_uavn0 >= TqDiag_thdMisfLo_C)
   {
      Diag_misfire_bas = 1;
   }
   else
   {
      Diag_misfire_bas = 0;
   }

   if (u8LocalMf_cat_dam_mf_rate_uavn0 >= TqDiag_thdMisfHi_C)
   {
      Diag_misfire_haut = 1;
   }
   else
   {
      Diag_misfire_haut = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidNoWght                                         */
/* !Description :  Dans ce module on définie un système de poids qui quantifie*/
/*                 l’effet plus ou moins important de chaque paramètre sur la */
/*                 précision des couples reconstruits.                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQSYSVLD_vidNoWght1();                                   */
/*  extf argret void TQSYSVLD_vidNoWght2();                                   */
/*  extf argret void TQSYSVLD_vidNoWght3();                                   */
/*  extf argret void TQSYSVLD_vidNoWght4();                                   */
/*  extf argret void TQSYSVLD_vidNoWght5();                                   */
/*  input uint16 TqDiag_noWght1;                                              */
/*  input uint16 TqDiag_noWght2;                                              */
/*  input uint16 TqDiag_noWght3;                                              */
/*  input uint16 TqDiag_noWght4;                                              */
/*  input uint16 TqDiag_noWght5;                                              */
/*  output uint16 TqDiag_noWght;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidNoWght(void)
{
   uint32 u32LocalTqDiagNoWght;


   TQSYSVLD_vidNoWght1();
   TQSYSVLD_vidNoWght2();
   TQSYSVLD_vidNoWght3();
   TQSYSVLD_vidNoWght4();
   TQSYSVLD_vidNoWght5();

   u32LocalTqDiagNoWght = (uint32)( TqDiag_noWght1
                                  + TqDiag_noWght2
                                  + TqDiag_noWght3
                                  + TqDiag_noWght4
                                  + TqDiag_noWght5);
   TqDiag_noWght = (uint16)MATHSRV_udtMIN(u32LocalTqDiagNoWght, 1000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidTqCkEngReal                                    */
/* !Description :  Fonction de calcul de l'Information couple incertain et    */
/*                 Information couple invalide.                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqDiag_noWght;                                               */
/*  input uint16 TqDiag_thdInvldTqCkEngReal_C;                                */
/*  input boolean manu_inh_bInvld_tqCkEngReal;                                */
/*  input uint16 TqDiag_thdUncrtTqCkEngReal_C;                                */
/*  input boolean manu_inh_bUncrt_tqCkEngReal;                                */
/*  output boolean TqDiag_bUncrt_tqCkEngReal;                                 */
/*  output boolean TqDiag_bInvld_tqCkEngReal;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidTqCkEngReal(void)
{
   boolean bLocalInvld_tqCkEngReal;
   boolean bLocalUncrt_tqCkEngReal;
   boolean bLocalTqDiag_bInvld_tqCkEngReal;


   bLocalInvld_tqCkEngReal = GDGAR_bGetFRM(FRM_FRM_INVLD_TQCKENGREAL);
   bLocalUncrt_tqCkEngReal = GDGAR_bGetFRM(FRM_FRM_UNCRT_TQCKENGREAL);
   if (  (bLocalInvld_tqCkEngReal != 0)
      || (  (TqDiag_noWght >= TqDiag_thdInvldTqCkEngReal_C)
         && (manu_inh_bInvld_tqCkEngReal == 0)))
   {
      bLocalTqDiag_bInvld_tqCkEngReal = 1;
   }
   else
   {
      bLocalTqDiag_bInvld_tqCkEngReal = 0;
   }
   if (  (bLocalUncrt_tqCkEngReal != 0)
      || (  (  (TqDiag_noWght >= TqDiag_thdUncrtTqCkEngReal_C)
            || (bLocalTqDiag_bInvld_tqCkEngReal != 0))
         && (manu_inh_bUncrt_tqCkEngReal == 0)))
   {
      VEMS_vidSET(TqDiag_bUncrt_tqCkEngReal, 1);
   }
   else
   {
      VEMS_vidSET(TqDiag_bUncrt_tqCkEngReal, 0);
   }
   VEMS_vidSET(TqDiag_bInvld_tqCkEngReal, bLocalTqDiag_bInvld_tqCkEngReal);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidTqEM                                           */
/* !Description :  Fonction de calcul de l'Information couple Easy Move       */
/*                 invalide et l'Information couple Easy Move incertain.      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04105_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqDiag_noWght;                                               */
/*  input uint16 TqDiag_thdInvldTqEM_C;                                       */
/*  input boolean manu_inh_bInvld_tqEM;                                       */
/*  input uint16 TqDiag_thdUncrtTqEM_C;                                       */
/*  input boolean manu_inh_bUncrt_tqEM;                                       */
/*  output boolean TqDiag_bUncrt_tqEM;                                        */
/*  output boolean TqDiag_bInvld_tqEM;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidTqEM(void)
{
   boolean bLocalInvld_tqEM;
   boolean bLocalUncrt_tqEM;
   boolean bLocalTqDiag_bInvld_tqEM;


   bLocalInvld_tqEM = GDGAR_bGetFRM(FRM_FRM_INVLD_TQEM);
   bLocalUncrt_tqEM = GDGAR_bGetFRM(FRM_FRM_UNCRT_TQEM);
   if (  (bLocalInvld_tqEM != 0)
      || (  (TqDiag_noWght >= TqDiag_thdInvldTqEM_C)
         && (manu_inh_bInvld_tqEM == 0)))
   {
      bLocalTqDiag_bInvld_tqEM = 1;
   }
   else
   {
      bLocalTqDiag_bInvld_tqEM = 0;
   }
   if (  (bLocalUncrt_tqEM != 0)
      || (  (  (TqDiag_noWght >= TqDiag_thdUncrtTqEM_C)
            || (bLocalTqDiag_bInvld_tqEM != 0))
         && (manu_inh_bUncrt_tqEM == 0)))
   {
      VEMS_vidSET(TqDiag_bUncrt_tqEM, 1);
   }
   else
   {
      VEMS_vidSET(TqDiag_bUncrt_tqEM, 0);
   }
   VEMS_vidSET(TqDiag_bInvld_tqEM, bLocalTqDiag_bInvld_tqEM);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSVLD_vidStDiagESPReq                                   */
/* !Description :  Fonction de calcul de l'Etat réalisation de la consigne    */
/*                 ASR/MSR :0 = fonctionnement normal, 1 = Moteur géré en     */
/*                 boucle ouverte, 2 = fonctionnement dégradé et 3 = aucune   */
/*                 action possible.                                           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqDiag_bUncrt_tqCkEngReal;                                  */
/*  output uint8 TqDiag_stDiagESPReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : W.LASSOUED                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSVLD_vidStDiagESPReq(void)
{
   boolean bLocalInvld_tqESPReq;
   boolean bLocalUncrt_tqESPReq;
   boolean bLocalTqDiag_bUncrt_tqCkEngReal;


   bLocalInvld_tqESPReq = GDGAR_bGetFRM(FRM_FRM_INVLD_TQESPREQ);
   if (bLocalInvld_tqESPReq != 0)
   {
      VEMS_vidSET(TqDiag_stDiagESPReq, 3);
   }
   else
   {
      VEMS_vidGET(TqDiag_bUncrt_tqCkEngReal, bLocalTqDiag_bUncrt_tqCkEngReal);
      if (bLocalTqDiag_bUncrt_tqCkEngReal != 0)
      {
         VEMS_vidSET(TqDiag_stDiagESPReq, 1);
      }
      else
      {
         bLocalUncrt_tqESPReq = GDGAR_bGetFRM(FRM_FRM_UNCRT_TQESPREQ);
         if (bLocalUncrt_tqESPReq != 0)
         {
            VEMS_vidSET(TqDiag_stDiagESPReq, 2);
         }
         else
         {
            VEMS_vidSET(TqDiag_stDiagESPReq, 0);
         }
      }
   }
}

/*------------------------------- end of file --------------------------------*/