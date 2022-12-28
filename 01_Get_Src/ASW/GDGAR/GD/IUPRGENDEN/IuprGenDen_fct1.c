/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRGENDEN                                              */
/* !Description     : IUPRGENDEN Component                                    */
/*                                                                            */
/* !Module          : IUPRGENDEN                                              */
/* !Description     : IUPRGENDENORISATION DES PARAMETRES DEFAUTS              */
/*                                                                            */
/* !File            : IuprGenDen_fct1.c                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IUPRGENDEN_vidInitOutput                                             */
/*   2 / IUPRGENDEN_vidF02_bObdStrt                                           */
/*   3 / IUPRGENDEN_vidF03_GenDen                                             */
/*   4 / IUPRGENDEN_vidF01_ObdCond                                            */
/*   5 / IUPRGENDEN_vidF02_ObdStrt                                            */
/*   6 / IUPRGENDEN_vidF01_SinceEngStrt                                       */
/*   7 / IUPRGENDEN_vidF02_VehSpdOver40                                       */
/*   8 / IUPRGENDEN_vidF03_VehIdle                                            */
/*   9 / IUPRGENDEN_vidF04_ReInitPrm                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5497341 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRGENDEN/IuprGenDen_fct1.c_$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   17 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "IUPRGENDEN.h"
#include "IUPRGENDEN_L.h"
#include "IUPRGENDEN_IM.h"
#include "GD_api.h"
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "NVMSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidInitOutput                                   */
/* !Description :  Initialisation des variables internes et sorties.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean IUPR_bRstPrm_prev;                                         */
/*  output boolean Iupr_gen_denom_ok_prev;                                    */
/*  output boolean Iupr_obd_Strt_ok_prev;                                     */
/*  output uint16 IUPR_tiObdStrt;                                             */
/*  output uint16 IUPR_tiSinceEngStrt;                                        */
/*  output uint16 IUPR_tiVehIdle;                                             */
/*  output uint16 IUPR_tiVehSpdOver40;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidInitOutput(void)
{
   IUPR_bRstPrm_prev = 0;
   Iupr_gen_denom_ok_prev = 0;
   Iupr_obd_Strt_ok_prev = 0;
   IUPR_tiObdStrt = 0;
   IUPR_tiSinceEngStrt = 0;
   IUPR_tiVehIdle = 0;
   IUPR_tiVehSpdOver40 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF02_bObdStrt                                 */
/* !Description :  Cette fonction crée un booléen qui s’active quand le régime*/
/*                 moteur est supérieur à un seuil calibrable                 */
/*                 (GOBD_nObdStrtThd_C) correspondant au régime de ralenti    */
/*                 -150tr/min. Cela correspond au critère d’un démarrage OBD. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 GOBD_nObdStrtThd_C;                                          */
/*  output boolean IUPR_bObdStrt;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF02_bObdStrt(void)
{
   uint16 u16LocalRegimeMoteur;


   VEMS_vidGET(Regime_moteur,u16LocalRegimeMoteur);
   if(u16LocalRegimeMoteur < GOBD_nObdStrtThd_C)
   {
      IUPR_bObdStrt = 0;
   }
   else
   {
      IUPR_bObdStrt = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF03_GenDen                                   */
/* !Description :  Cette fonction comprend une sous-fonction F01_IUPR_OBDCOND */
/*                 dans laquelle est calculé le Dénominateur Général et le    */
/*                 Compteur de démarrages OBD. Elle peut être inhiber et les  */
/*                 paramètres de sortie figés si FRM_bFrzOBDGenDen provenant  */
/*                 du GAR est activé.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IUPRGENDEN_vidF01_ObdCond();                             */
/*  extf argret void IUPRGENDEN_vidF02_ObdStrt();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Iupr_bFrzGenDen;                                            */
/*  input boolean Iupr_bFrzCntObdStrt;                                        */
/*  input boolean IUPR_bRstPrm_C;                                             */
/*  input boolean IUPR_bRstPrm_prev;                                          */
/*  output uint16 Iupr_gen_denom_count_eep;                                   */
/*  output uint16 IUPR_ctObdStrt;                                             */
/*  output boolean IUPR_bRstPrm_prev;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF03_GenDen(void)
{
   boolean bLocalIupr_bFrzGenDen;
   boolean bLocalIupr_bFrzCntObdStrt;


   VEMS_vidGET(Iupr_bFrzGenDen, bLocalIupr_bFrzGenDen);
   VEMS_vidGET(Iupr_bFrzCntObdStrt, bLocalIupr_bFrzCntObdStrt);
   if (bLocalIupr_bFrzGenDen != 1)
   {
      IUPRGENDEN_vidF01_ObdCond();
   }

   if (bLocalIupr_bFrzCntObdStrt != 1)
   {
      IUPRGENDEN_vidF02_ObdStrt();
   }

   if (  (IUPR_bRstPrm_C == 1)
      && (IUPR_bRstPrm_prev == 0))
   {
      VEMS_vidSET(Iupr_gen_denom_count_eep, 0);
      VEMS_vidSET(IUPR_ctObdStrt, 0);
   }

   IUPR_bRstPrm_prev = IUPR_bRstPrm_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF01_ObdCond                                  */
/* !Description :  Cette fonction gère le calcul du Dénominateur Général de   */
/*                 l’IUPR ainsi que le Compteur de démarrages OBD.            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IUPRGENDEN_vidF01_SinceEngStrt();                        */
/*  extf argret void IUPRGENDEN_vidF02_VehSpdOver40();                        */
/*  extf argret void IUPRGENDEN_vidF03_VehIdle();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Atmospheric_pressure;                                        */
/*  input sint16 Ext_tAirMesFineResl;                                         */
/*  input uint8 Iupr_ambient_temp_thresh;                                     */
/*  input uint16 Iupr_pressure_thresh;                                        */
/*  input boolean IUPR_bSinceEngStrt;                                         */
/*  input boolean IUPR_bVehSpdOver40;                                         */
/*  input boolean IUPR_bVehIdle;                                              */
/*  input uint8 u8Iupr_xxx_denom_ok;                                          */
/*  input uint16 Iupr_gen_denom_count_eep;                                    */
/*  input boolean Iupr_gen_denom_ok_prev;                                     */
/*  output boolean IUPR_bExtCond;                                             */
/*  output uint16 Iupr_gen_denom_count_eep;                                   */
/*  output boolean Iupr_gen_denom_ok_prev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF01_ObdCond(void)
{
   boolean bLocalIupr_gen_denom_ok;
   sint16  s16LocalExt_tAirMesFineResl;
   uint16  u16LocalAtmosphericPressure;
   uint16  u16LocalIupr_gen_denom_count_eep;
   uint16  u16LocalScalingCompIupr;
   sint32  s32LocalExt_tAirMesFineResl;


   VEMS_vidGET(Atmospheric_pressure, u16LocalAtmosphericPressure);
   VEMS_vidGET(Ext_tAirMesFineResl, s16LocalExt_tAirMesFineResl);

   s32LocalExt_tAirMesFineResl =
         (sint32)((s16LocalExt_tAirMesFineResl + 40) * 8);
   u16LocalScalingCompIupr = (uint16)(Iupr_ambient_temp_thresh * 5);

   u16LocalAtmosphericPressure = (uint16)(u16LocalAtmosphericPressure * 4);


   if (  (s32LocalExt_tAirMesFineResl >= u16LocalScalingCompIupr )
      && (u16LocalAtmosphericPressure >= Iupr_pressure_thresh))
   {
      IUPR_bExtCond = 1;
   }
   else
   {
      IUPR_bExtCond = 0;
   }

   IUPRGENDEN_vidF01_SinceEngStrt();
   IUPRGENDEN_vidF02_VehSpdOver40();
   IUPRGENDEN_vidF03_VehIdle();

   bLocalIupr_gen_denom_ok = (boolean)(IUPR_bSinceEngStrt &
                                       IUPR_bVehSpdOver40 &
                                       IUPR_bVehIdle);

   GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                  DEF_IUPR_GEN_DENOM_OK,
                  bLocalIupr_gen_denom_ok);

   VEMS_vidGET(Iupr_gen_denom_count_eep, u16LocalIupr_gen_denom_count_eep);
   if (u16LocalIupr_gen_denom_count_eep >= 65535)
   {
      VEMS_vidSET(Iupr_gen_denom_count_eep, 0);
   }
   else
   {
      if (  (bLocalIupr_gen_denom_ok == 1)
         && (Iupr_gen_denom_ok_prev == 0))
      {
         u16LocalIupr_gen_denom_count_eep =
               (uint16)(u16LocalIupr_gen_denom_count_eep + 1);
         if (u16LocalIupr_gen_denom_count_eep >= 65535)
         {
            u16LocalIupr_gen_denom_count_eep = 0;
         }
         VEMS_vidSET(Iupr_gen_denom_count_eep,
                     u16LocalIupr_gen_denom_count_eep);
      }
   }

   Iupr_gen_denom_ok_prev = bLocalIupr_gen_denom_ok;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF02_ObdStrt                                  */
/* !Description :  Cette fonction calcule le nombre de démarrage OBD          */
/*                 (IUPR_ctObdStrt).                                          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 IUPR_ctObdStrt;                                              */
/*  input uint16 IUPR_tiObdStrt;                                              */
/*  input uint16 IUPR_tiObdStrtThd_C;                                         */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input boolean IUPR_bObdStrt;                                              */
/*  input boolean Iupr_obd_Strt_ok_prev;                                      */
/*  output uint16 IUPR_tiObdStrt;                                             */
/*  output uint16 IUPR_ctObdStrt;                                             */
/*  output boolean Iupr_obd_Strt_ok_prev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF02_ObdStrt(void)
{
   boolean bLocalIuprObdStrtOk;
   boolean bLocalDC_bSyncGlbDC;
   uint16  u16LocalIUPR_ctObdStrt;


   VEMS_vidGET(IUPR_ctObdStrt, u16LocalIUPR_ctObdStrt);
   if (IUPR_tiObdStrt < IUPR_tiObdStrtThd_C)
   {
      bLocalIuprObdStrtOk = 0;
      VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
      if (  (bLocalDC_bSyncGlbDC == 1)
         && (IUPR_bObdStrt == 1))
      {
         IUPR_tiObdStrt = (uint16)(IUPR_tiObdStrt + 1);
      }
      if (u16LocalIUPR_ctObdStrt >= 65535)
      {
         VEMS_vidSET(IUPR_ctObdStrt, 0);
      }
   }
   else
   {
      bLocalIuprObdStrtOk = 1;
      if (u16LocalIUPR_ctObdStrt >= 65535)
      {
         VEMS_vidSET(IUPR_ctObdStrt, 0);
      }
      else
      {
         if (Iupr_obd_Strt_ok_prev == 0)
         {
            u16LocalIUPR_ctObdStrt = (uint16)(u16LocalIUPR_ctObdStrt + 1);
            if (u16LocalIUPR_ctObdStrt >= 65535)
            {
               u16LocalIUPR_ctObdStrt = 0;
            }
            VEMS_vidSET(IUPR_ctObdStrt, u16LocalIUPR_ctObdStrt);
         }
      }
   }

   Iupr_obd_Strt_ok_prev = bLocalIuprObdStrtOk;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF01_SinceEngStrt                             */
/* !Description :  Cette fonction gère le compteur de temps depuis le         */
/*                 démarrage moteur IUPR_tiSinceEngStrt                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 IUPR_tiSinceEngStrt;                                         */
/*  input uint16 Iupr_gen_denom_cumul_delay;                                  */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input boolean GOBD_bKeyOBD;                                               */
/*  input boolean IUPR_bExtCond;                                              */
/*  output boolean IUPR_bSinceEngStrt;                                        */
/*  output uint16 IUPR_tiSinceEngStrt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF01_SinceEngStrt(void)
{
   boolean bLocalDC_bSyncGlbDC;
   boolean bLocalGOBD_bKeyOBD;


   if (IUPR_tiSinceEngStrt < Iupr_gen_denom_cumul_delay)
   {
      IUPR_bSinceEngStrt = 0;
      VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
      VEMS_vidGET(GOBD_bKeyOBD, bLocalGOBD_bKeyOBD);

      if (  (bLocalDC_bSyncGlbDC == 1)
         && (bLocalGOBD_bKeyOBD == 1)
         && (IUPR_bExtCond == 1))
      {
         if (IUPR_tiSinceEngStrt < 65534)
         {
            IUPR_tiSinceEngStrt = (uint16)(IUPR_tiSinceEngStrt + 1);
         }
         else
         {
            IUPR_tiSinceEngStrt = (uint16)UINT16_MAX;
         }

         if (IUPR_tiSinceEngStrt >= Iupr_gen_denom_cumul_delay)
         {
            IUPR_bSinceEngStrt = 1;
         }
      }
   }
   else
   {
      IUPR_bSinceEngStrt = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF02_VehSpdOver40                             */
/* !Description :  Cette fonction gère le compteur de temps passé avec la     */
/*                 vitesse véhicule supérieure à 40 km/h IUPR_tiVehSpdOver40  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input uint16 IUPR_tiVehSpdOver40;                                         */
/*  input uint16 Iupr_gen_denom_over_40kph_delay;                             */
/*  input uint16 Iupr_vitesse_vehicule_thresh;                                */
/*  input boolean IUPR_bExtCond;                                              */
/*  output boolean IUPR_bVehSpdOver40;                                        */
/*  output uint16 IUPR_tiVehSpdOver40;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF02_VehSpdOver40(void)
{
   boolean bLocalDC_bSyncGlbDC;
   uint16  u16LocalVitesseVehicule;


   VEMS_vidGET(Vitesse_vehicule, u16LocalVitesseVehicule);
   VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
   u16LocalVitesseVehicule = (uint16)(u16LocalVitesseVehicule * 128);

   if (IUPR_tiVehSpdOver40 < Iupr_gen_denom_over_40kph_delay)
   {
      IUPR_bVehSpdOver40 = 0;
      if (  (u16LocalVitesseVehicule > Iupr_vitesse_vehicule_thresh)
         && (IUPR_bExtCond != 0)
         && (bLocalDC_bSyncGlbDC != 0))
      {
         if (IUPR_tiVehSpdOver40 < 65534)
         {
            IUPR_tiVehSpdOver40 = (uint16)(IUPR_tiVehSpdOver40 + 1);
         }
         else
         {
            IUPR_tiVehSpdOver40 = (uint16)UINT16_MAX;
         }

         if (IUPR_tiVehSpdOver40 >= Iupr_gen_denom_over_40kph_delay)
         {
            IUPR_bVehSpdOver40 = 1;
         }
      }
   }
   else
   {
      IUPR_bVehSpdOver40 = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF03_VehIdle                                  */
/* !Description :  Cette fonction gère le compteur de temps passé au ralenti  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input boolean Dv_detection_pied_leve;                                     */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input uint16 IUPR_tiVehIdle;                                              */
/*  input uint16 Iupr_gen_denom_idle_delay;                                   */
/*  input uint16 Iupr_vitesse_veh_idle_thresh;                                */
/*  input boolean IUPR_bVehIdle;                                              */
/*  input boolean IUPR_bExtCond;                                              */
/*  output boolean IUPR_bVehIdle;                                             */
/*  output boolean IUPR_bIdle;                                                */
/*  output uint16 IUPR_tiVehIdle;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF03_VehIdle(void)
{
   uint16  u16LocalVitesseVehicule;
   boolean bLocalDvDetectionPiedLeve;
   boolean bLocalDC_bSyncGlbDC;


   VEMS_vidGET(Vitesse_vehicule, u16LocalVitesseVehicule);
   VEMS_vidGET(Dv_detection_pied_leve, bLocalDvDetectionPiedLeve);
   VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
   u16LocalVitesseVehicule = (uint16)(u16LocalVitesseVehicule * 128);
   if (IUPR_tiVehIdle < Iupr_gen_denom_idle_delay)
   {
      IUPR_bVehIdle = 0;
   }
   else
   {
      IUPR_bVehIdle = 1;
   }

   if (  (u16LocalVitesseVehicule <= Iupr_vitesse_veh_idle_thresh)
      && (bLocalDvDetectionPiedLeve != 0))
   {
      IUPR_bIdle = 1;

      if (IUPR_bVehIdle == 0)
      {
         if (  (IUPR_bExtCond != 0)
            && (bLocalDC_bSyncGlbDC != 0))
         {
            if (IUPR_tiVehIdle < 65534)
            {
               IUPR_tiVehIdle = (uint16)(IUPR_tiVehIdle + 1);
            }
            else
            {
               IUPR_tiVehIdle = (uint16)UINT16_MAX;
            }

            if (IUPR_tiVehIdle >= Iupr_gen_denom_idle_delay)
            {
               IUPR_bVehIdle = 1;
            }
         }
         else
         {
            IUPR_tiVehIdle = 0;
         }
      }
   }
   else
   {
      IUPR_bIdle = 0;

      if (IUPR_bVehIdle == 0)
      {
         IUPR_tiVehIdle = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRGENDEN_vidF04_ReInitPrm                                */
/* !Description :  Cette fonction est appelée à chaque début de DC Global qui */
/*                 correspond aussi au démarrage moteur (hors calage et arrêts*/
/*                 « Stop&Start ») et permet de ré-initialiser à 0 chaque     */
/*                 compteurs de temps                                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean IUPR_bVehIdle;                                             */
/*  output uint16 IUPR_tiSinceEngStrt;                                        */
/*  output uint16 IUPR_tiVehSpdOver40;                                        */
/*  output uint16 IUPR_tiVehIdle;                                             */
/*  output uint16 IUPR_tiObdStrt;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRGENDEN_vidF04_ReInitPrm(void)
{
   IUPR_bVehIdle = 0;
   IUPR_tiSinceEngStrt = 0;
   IUPR_tiVehSpdOver40 = 0;
   IUPR_tiVehIdle = 0;
   IUPR_tiObdStrt = 0;
}
/*------------------------------- end of file --------------------------------*/