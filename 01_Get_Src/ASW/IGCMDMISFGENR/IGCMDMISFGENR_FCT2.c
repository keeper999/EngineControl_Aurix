/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCMDMISFGENR                                           */
/* !Description     : IGCMDMISFGENR component.                                */
/*                                                                            */
/* !Module          : IGCMDMISFGENR                                           */
/* !Description     : Générateur De Ratés D'allumage.                         */
/*                                                                            */
/* !File            : IGCMDMISFGENR_FCT2.C                                    */
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
/*   1 / IGCMDMISFGENR_vidRazMsmSparkCnt                                      */
/*   2 / IGCMDMISFGENR_vidMisfireRatio                                        */
/*   3 / IGCMDMISFGENR_vidCylSelection                                        */
/*   4 / IGCMDMISFGENR_vidInitcompteurs                                       */
/*   5 / IGCMDMISFGENR_vidTauxmisfirereel                                     */
/*   6 / IGCMDMISFGENR_vidMisfireGenStop                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 06148 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/MISF/IGCMDMISFGENR/IGCMDMISFGENR$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   26 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCMDMISFGENR.h"
#include "IGCMDMISFGENR_L.h"
#include "IGCMDMISFGENR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidRazMsmSparkCnt                            */
/* !Description :  Cette fonction permet, en mode successif, d'initialiser  le*/
/*                 compteur de récurrence uniquement lors du premier misfire. */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Msm_spark_counter;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidRazMsmSparkCnt(void)
{
   Msm_spark_counter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidMisfireRatio                              */
/* !Description :  Cette fonction pemet de produire les taux de misfire en    */
/*                 mode aléatoire et déterministe ainsi que le taux de misfire*/
/*                 EOBD (mode aléatoire ou déterministe).                     */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Autorisation_misfire;                                       */
/*  input uint8 Recurrence_misfire_deterministe;                              */
/*  input boolean Mode_successif;                                             */
/*  input uint16 Taux_misfire_reel;                                           */
/*  input boolean Mode_deterministe;                                          */
/*  output uint16 Taux_deterministe;                                          */
/*  output uint16 Taux_aleatoire;                                             */
/*  output uint16 Taux_misfire;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidMisfireRatio(void)
{
   /* 03_Taux_misfire */
   uint16  u16LocalTaux_aleatoire;
   uint16  u16LocalTaux;
   uint32  u32LocalTaux;


   if (Autorisation_misfire != 0)
   {
      if (Recurrence_misfire_deterministe == 0)
      {
         u32LocalTaux = 65535;
      }
      else
      {
         if (Mode_successif != 0)
         {
            u32LocalTaux = (uint32)(131072 / Recurrence_misfire_deterministe);
         }
         else
         {
            u32LocalTaux = (uint32)(65536 / Recurrence_misfire_deterministe);
         }
      }
      u16LocalTaux = (uint16)MATHSRV_udtMIN(u32LocalTaux, 65535);
      VEMS_vidSET(Taux_deterministe, u16LocalTaux);

      VEMS_vidGET(Taux_misfire_reel, u16LocalTaux_aleatoire);
      VEMS_vidSET(Taux_aleatoire, u16LocalTaux_aleatoire);

      if (Mode_deterministe != 0)
      {
         VEMS_vidSET(Taux_misfire, u16LocalTaux);
      }
      else
      {
         VEMS_vidSET(Taux_misfire, u16LocalTaux_aleatoire);
      }
   }
   else
   {
      VEMS_vidSET(Taux_deterministe, 0);
      VEMS_vidSET(Taux_aleatoire, 0);
      VEMS_vidSET(Taux_misfire, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidCylSelection                              */
/* !Description :  Cette fonction permet de redistribuer les composantes du   */
/*                 vecteur Misfire_cylindre dans les variables de sortie      */
/*                 propre à chaque cylindre.                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Misfire_cylindre;                                             */
/*  output boolean Misfire_cylindre_1;                                        */
/*  output boolean Misfire_cylindre_2;                                        */
/*  output boolean Misfire_cylindre_3;                                        */
/*  output boolean Misfire_cylindre_4;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidCylSelection(void)
{
   uint8   u8LocalMisfire_cylindre;


   VEMS_vidGET(Misfire_cylindre, u8LocalMisfire_cylindre);
   if ( (u8LocalMisfire_cylindre & 0x01) == 0x01)
   {
      VEMS_vidSET(Misfire_cylindre_1, 1);
   }
   else
   {
      VEMS_vidSET(Misfire_cylindre_1, 0);
   }
   if ( (u8LocalMisfire_cylindre & 0x02) == 0x02)
   {
      VEMS_vidSET(Misfire_cylindre_2, 1);
   }
   else
   {
      VEMS_vidSET(Misfire_cylindre_2, 0);
   }
   if ( (u8LocalMisfire_cylindre & 0x04) == 0x04)
   {
      VEMS_vidSET(Misfire_cylindre_3, 1);
   }
   else
   {
      VEMS_vidSET(Misfire_cylindre_3, 0);
   }
   if ( (u8LocalMisfire_cylindre & 0x08) == 0x08)
   {
      VEMS_vidSET(Misfire_cylindre_4, 1);
   }
   else
   {
      VEMS_vidSET(Misfire_cylindre_4, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidInitcompteurs                             */
/* !Description :  Le compteur global du nombre de combustions Cnt_global     */
/*                 ainsi que le compteur de misfire Cnt_misfire sont          */
/*                 réinitialisés à 0 lors de la détection d’un changement     */
/*                 effectué sur la valeur de la calibration                   */
/*                 Taux_misfire_aleatoire.                                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Cnt_global;                                                 */
/*  output uint16 Cnt_misfire;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidInitcompteurs(void)
{
   Cnt_global = 0;
   Cnt_misfire = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidTauxmisfirereel                           */
/* !Description :  Le taux réel de misfire générés est calculés mis à jour en */
/*                 permanence grâce à deux compteurs : Cnt_global comptant    */
/*                 toutes les combustions et Cnt_misfire comptant les         */
/*                 combustions avec misfire.                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Misfire_al;                                                 */
/*  input uint16 Cnt_misfire;                                                 */
/*  input uint16 Cnt_global;                                                  */
/*  output uint16 Cnt_misfire;                                                */
/*  output uint16 Cnt_global;                                                 */
/*  output uint16 Taux_misfire_reel;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidTauxmisfirereel(void)
{
   /* 02_Taux_misfire_reel */
   uint16  u16LocalTaux_misfire_reel;
   uint32  u32LocalDivision;


   if (Misfire_al != 0)
   {
      if (Cnt_misfire < 65535)
      {
         Cnt_misfire = (uint16)(Cnt_misfire + 1);
      }
   }

   if (Cnt_global < 65535)
   {
      Cnt_global = (uint16)(Cnt_global + 1);
   }

   u32LocalDivision = ((Cnt_misfire * (uint32)65536) / Cnt_global);

   u16LocalTaux_misfire_reel = (uint16)MATHSRV_udtMIN(u32LocalDivision, 65535);
   VEMS_vidSET(Taux_misfire_reel, u16LocalTaux_misfire_reel);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidMisfireGenStop                            */
/* !Description :  Ce bloc réinitalise le calcul de Misfire_cylindre.         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Misfire_cylindre;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidMisfireGenStop(void)
{
   VEMS_vidSET(Misfire_cylindre, 0);
}

/****************************** end of file ***********************************/