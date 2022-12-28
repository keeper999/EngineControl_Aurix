/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BATTVOLTACQ                                             */
/* !Description     : BATTVOLTACQ Component                                   */
/*                                                                            */
/* !Module          : BATTVOLTACQ                                             */
/* !Description     : ACQUISITION DE LA TENSION BATTERIE                      */
/*                                                                            */
/* !File            : BATTVOLTACQ_FCT2.C                                      */
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
/*   1 / BATTVOLTACQ_vidbattFiltMng                                           */
/*   2 / BATTVOLTACQ_vidWeightedAvr                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6547150 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068642                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BATTVOLTACQ/BATTVOLTACQ_FCT2.C_v  $*/
/* $Revision::   1.0      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BATTVOLTACQ_IM.h"
#include "BATTVOLTACQ.h"
#include "BATTVOLTACQ_L.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidbattFiltMng                                 */
/* !Description :  Avant chaque injection, une requête de boost est envoyée à */
/*                 la batterie. Ces emandes entraînent des chutes de tension. */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BATTVOLTACQ_vidWeightedAvr();                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Pwr_nEngThd_uBattFil_C;                                      */
/*  input uint16 Pwr_nEngHysThd_uBattFil_C;                                   */
/*  input boolean Pwr_bHysVoltAcqFil;                                         */
/*  input uint16 Acquisition_tension_batterie;                                */
/*  input boolean Pwr_bEnaEveInj_C;                                           */
/*  input boolean Pwr_bEnaEve2ms_C;                                           */
/*  input boolean Pwr_bAcvEveInjStra;                                         */
/*  input uint16 Pwr_uBattEveInjAcq;                                          */
/*  input uint16 Pwr_uBattFilAcq;                                             */
/*  input uint16 Pwr_uBattDiagAcq;                                            */
/*  output boolean Pwr_bHysVoltAcqFil;                                        */
/*  output uint16 Pwr_uBattDiagAcq;                                           */
/*  output boolean Pwr_bAcvEveInjStra;                                        */
/*  output uint16 Tension_batterie_brute;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidbattFiltMng(void)
{
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalTension_batterie_brute;
   uint16 u16LocalAcquis_tension_batterie;
   uint32 u32LocalAdcVoltage;
   uint32 u32LocalThreshold2;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   u32LocalThreshold2 =
      (uint32)(Pwr_nEngThd_uBattFil_C + Pwr_nEngHysThd_uBattFil_C);

   if (Pwr_bHysVoltAcqFil == 0)
   {
      if (u16LocalRegime_moteur >= u32LocalThreshold2)
      {
         Pwr_bHysVoltAcqFil = 1;
      }
      else
      {
         Pwr_bHysVoltAcqFil = 0;
      }
   }
   else
   {
      if (u16LocalRegime_moteur <= Pwr_nEngThd_uBattFil_C)
      {
         Pwr_bHysVoltAcqFil = 0;
      }
      else
      {
         Pwr_bHysVoltAcqFil = 1;
      }
   }

   VEMS_vidGET(Acquisition_tension_batterie, u16LocalAcquis_tension_batterie);
   u32LocalAdcVoltage = ((u16LocalAcquis_tension_batterie * 25) + 241) / 483;
   Pwr_uBattDiagAcq = (uint16)MATHSRV_udtMIN(u32LocalAdcVoltage, 1024);
   BATTVOLTACQ_vidWeightedAvr();

   if (  (Pwr_bEnaEveInj_C != 0)
      && (  (Pwr_bHysVoltAcqFil != 0)
         || (Pwr_bEnaEve2ms_C == 0)))
   {
      Pwr_bAcvEveInjStra = 1;
   }
   else
   {
      Pwr_bAcvEveInjStra = 0;
   }

   if (  (Pwr_bEnaEve2ms_C != 0)
      || (Pwr_bEnaEveInj_C != 0))
   {
      if (Pwr_bAcvEveInjStra != 0)
      {
         u16LocalTension_batterie_brute =
            (uint16)MATHSRV_udtMIN(Pwr_uBattEveInjAcq, 1024);
         VEMS_vidSET(Tension_batterie_brute, u16LocalTension_batterie_brute);
      }
      else
      {
         u16LocalTension_batterie_brute =
            (uint16)MATHSRV_udtMIN(Pwr_uBattFilAcq, 1024);
         VEMS_vidSET(Tension_batterie_brute, u16LocalTension_batterie_brute);
      }
   }
   else
   {
      VEMS_vidSET(Tension_batterie_brute, Pwr_uBattDiagAcq);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTACQ_vidWeightedAvr                                 */
/* !Description :  Moyenne pondérée  glissante sur 5 échantillons, avec une   */
/*                 pondération calibrable. Les pondérations doivent être      */
/*                 comprises entre 0 et 1et la somme des pondération doit être*/
/*                 obligatoirement égale à 1.                                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Pwr_uBattRaw1;                                               */
/*  input uint8 Pwr_rSample1_C;                                               */
/*  input uint16 Pwr_uBattRaw2;                                               */
/*  input uint8 Pwr_rSample2_C;                                               */
/*  input uint16 Pwr_uBattRaw3;                                               */
/*  input uint8 Pwr_rSample3_C;                                               */
/*  input uint16 Pwr_uBattRaw4;                                               */
/*  input uint8 Pwr_rSample4_C;                                               */
/*  input uint16 Pwr_uBattRaw5;                                               */
/*  input uint8 Pwr_rSample5_C;                                               */
/*  output uint16 Pwr_uBattFilAcq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTACQ_vidWeightedAvr(void)
{
   uint32 u32LocalSomme;


   u32LocalSomme = (uint32)( ( (Pwr_uBattRaw1 * Pwr_rSample1_C)
                             + (Pwr_uBattRaw2 * Pwr_rSample2_C)
                             + (Pwr_uBattRaw3 * Pwr_rSample3_C)
                             + (Pwr_uBattRaw4 * Pwr_rSample4_C)
                             + (Pwr_uBattRaw5 * Pwr_rSample5_C))
                           / 100);

   Pwr_uBattFilAcq = (uint16)(MATHSRV_udtMIN(u32LocalSomme, 1024));
}
/*------------------------------- end of file --------------------------------*/