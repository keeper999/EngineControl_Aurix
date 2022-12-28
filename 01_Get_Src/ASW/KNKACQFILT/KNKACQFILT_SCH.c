/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKACQFILT                                              */
/* !Description     : KNKACQFILT Component                                    */
/*                                                                            */
/* !Module          : KNKACQFILT                                              */
/* !Description     :  KNOCK SIGNAL PROCESSING WITH A BAND-PASS FILTER AND    */
/*                    INTERFACE WITH BSW                                      */
/*                                                                            */
/* !File            : KNKACQFILT_SCH.C                                        */
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
/*   1 / KnkTreat_EveRst_KnkAcqFilt                                           */
/*   2 / KnkTreat_EveKnk_KnkAcqFiltFst                                        */
/*   3 / KnkTreat_EveKnk_KnkAcqFiltLst                                        */
/*   4 / KnkTreat_SdlFast_KnkAcqFilt                                          */
/*   5 / KnkTreat_EveCkSnOn_KnkAcqFilt                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5066552 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KNKACQFILT.h"
#include "KNKACQFILT_L.h"
#include "KNKACQFILT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_KnkAcqFilt                                 */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQFILT_vidInitOutput();                              */
/*  extf argret void KNKACQFILT_vidConfigParamInit();                         */
/*  input boolean Autorise_rbl_num;                                           */
/*  input boolean Autorise_clq_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_KnkAcqFilt                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_KnkAcqFilt(void)
{
   KNKACQFILT_vidInitOutput();
   if (  (Autorise_rbl_num != 0)
      || (Autorise_clq_num != 0))
   {
      /*01_Knk_Cfg_Configuration_parameters_Init*/
      KNKACQFILT_vidConfigParamInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_KnkAcqFiltFst                              */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours.                                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKACQFILT_vidFilterEnergyCalc();                        */
/*  input uint8 KNKACQFILT_u8Inhib;                                           */
/*  input boolean Autorise_detection_clq;                                     */
/*  input boolean Autorise_detection_rbl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_KnkAcqFiltFst                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_KnkAcqFiltFst(void)
{
   boolean  bLocalAutorise_detection_clq;
   boolean  bLocalAutorise_detection_rbl;


   if (KNKACQFILT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
      VEMS_vidGET(Autorise_detection_rbl, bLocalAutorise_detection_rbl);
      if (  (bLocalAutorise_detection_clq != 0)
         || (bLocalAutorise_detection_rbl != 0))
      {
         /*02_Knk_filter_energy_calc*/
         KNKACQFILT_vidFilterEnergyCalc();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_KnkAcqFiltLst                              */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours.                                                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQFILT_vidCheckCondition();                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKACQFILT_vidDefKnkWindows();                           */
/*  input uint8 KNKACQFILT_u8Inhib;                                           */
/*  input boolean Autorise_detection_clq;                                     */
/*  input boolean Autorise_detection_rbl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_KnkAcqFiltLst                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_KnkAcqFiltLst(void)
{
   boolean  bLocalAutorise_detection_clq;
   boolean  bLocalAutorise_detection_rbl;


   if (KNKACQFILT_u8Inhib != 0x5A)
   {
      KNKACQFILT_vidCheckCondition();
      VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
      VEMS_vidGET(Autorise_detection_rbl, bLocalAutorise_detection_rbl);
      if (  (bLocalAutorise_detection_clq != 0)
         || (bLocalAutorise_detection_rbl != 0))
      {
         /*03_Definition_knk_windows*/
         KNKACQFILT_vidDefKnkWindows();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlFast_KnkAcqFilt                                */
/* !Description :  Traitement temporel pour lancer le premier évènement Knk.  */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQFILT_vidCheckCondition();                          */
/*  extf argret void KNKACQFILT_vidDefKnkWindows();                           */
/*  input uint8 KNKACQFILT_u8Inhib;                                           */
/*  input boolean KnkRbl_bAcvCalSdlFast;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlFast_KnkAcqFilt                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlFast_KnkAcqFilt(void)
{
   if (KNKACQFILT_u8Inhib != 0x5A)
   {
      KNKACQFILT_vidCheckCondition();
      if (KnkRbl_bAcvCalSdlFast != 0)
      {
         /*03_Definition_knk_windows*/
         KNKACQFILT_vidDefKnkWindows();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_KnkAcqFilt                              */
/* !Description :  Traitement temporel pour lancer le premier évènement Knk   */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKACQFILT_vidConfigParamInit();                         */
/*  input uint8 KNKACQFILT_u8Inhib;                                           */
/*  input boolean Autorise_rbl_num;                                           */
/*  input boolean Autorise_clq_num;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOn_KnkAcqFilt                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_KnkAcqFilt(void)
{
   if (KNKACQFILT_u8Inhib != 0x5A)
   {
      if (  (Autorise_rbl_num != 0)
         || (Autorise_clq_num != 0))
      {
         /*01_Knk_Cfg_Configuration_parameters_Init*/
         KNKACQFILT_vidConfigParamInit();
      }
   }
}
/*------------------------------- end of file --------------------------------*/