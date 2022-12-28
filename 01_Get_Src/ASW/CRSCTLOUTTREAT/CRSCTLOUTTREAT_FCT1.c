/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLOUTTREAT                                          */
/* !Description     : CRSCTLOUTTREAT Component                                */
/*                                                                            */
/* !Module          : CRSCTLOUTTREAT                                          */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LA FONCTION XVV ET      */
/*                    L’ISCAN                                                 */
/*                                                                            */
/* !File            : CRSCTLOUTTREAT_FCT1.C                                   */
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
/*   1 / CRSCTLOUTTREAT_vidxVV_init                                           */
/*   2 / CRSCTLOUTTREAT_vidInitOutput                                         */
/*   3 / CRSCTLOUTTREAT_vidxVVStIndiCond                                      */
/*   4 / CRSCTLOUTTREAT_vidxVVStateIndic                                      */
/*   5 / CRSCTLOUTTREAT_vidxVVFailCond                                        */
/*   6 / CRSCTLOUTTREAT_vidxVVFail                                            */
/*   7 / CRSCTLOUTTREAT_vidSubSystem                                          */
/*   8 / CRSCTLOUTTREAT_vidxVVInFctTreat                                      */
/*   9 / CRSCTLOUTTREAT_vidFctTreatProc                                       */
/*                                                                            */
/* !Reference   : V02 NT 12 01019 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#060743                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLOUTTREAT/CRSCTLOUTT$*/
/* $Revision::   1.0      $$Author::   alaouni        $$Date::   06 Apr 2012 $*/
/* $Author::   alaouni                                $$Date::   06 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "CRSCTLOUTTREAT.h"
#include "CRSCTLOUTTREAT_l.h"
#include "CRSCTLOUTTREAT_IM.h"
#include "VEMS.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidxVV_init                                 */
/* !Description :  Ce bloc gère l’initialisation des variables sur évènement  */
/*                 reset du calculateur.                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 VSCtl_stVSCtl;                                               */
/*  output uint8 Position_pedale_regulateur;                                  */
/*  output uint8 Position_pedale_limiteur;                                    */
/*  output boolean Cc_accel_pedal_regulation_master;                          */
/*  output boolean Cc_couple_lvv_effectif;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidxVV_init(void)
{
   VEMS_vidSET(VSCtl_stVSCtl, 3);
   VEMS_vidSET(Position_pedale_regulateur, 0);
   VEMS_vidSET(Position_pedale_limiteur, 255);
   VEMS_vidSET(Cc_accel_pedal_regulation_master, 0);
   VEMS_vidSET(Cc_couple_lvv_effectif, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidInitOutput                               */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean VSCtl_bVSCtlDft;                                           */
/*  output boolean CrsCtl_bDgoCrsCtlDft;                                      */
/*  output boolean CrsCtl_bMonRunCrsCtlDft;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidInitOutput(void)
{
   VEMS_vidSET(VSCtl_bVSCtlDft, 0);
   CrsCtl_bDgoCrsCtlDft = 0;
   CrsCtl_bMonRunCrsCtlDft = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidxVVStIndiCond                            */
/* !Description :  Appel de la fonction CRSCTLOUTTREAT_vidxVVStateIndic si    */
/*                 Ext_bVSRegCf = 1 ou Ext_bVSLimCf = 1                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLOUTTREAT_vidxVVStateIndic();                       */
/*  input uint8 Ext_stDVSRegCf;                                               */
/*  input boolean Ext_bVSLimCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidxVVStIndiCond(void)
{
   boolean bLocalExt_bVSLimCf;
   uint8   u8LocalExt_stDVSRegCf;


   VEMS_vidGET(Ext_stDVSRegCf, u8LocalExt_stDVSRegCf);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);

   if (  (u8LocalExt_stDVSRegCf == 1)
      || (bLocalExt_bVSLimCf != 0))
   {
      CRSCTLOUTTREAT_vidxVVStateIndic();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidxVVStateIndic                            */
/* !Description :  Calcul de Cc_rvv_lvv_manager_state_mux                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  sakrani.nouha                                              */
/* !Trace_To    :  VEMS_R_09_03334_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VSCtl_stVSRegExtd;                                            */
/*  input uint8 Ext_stModRegVSCtlReq;                                         */
/*  input uint8 VSCtl_stVSLimExtd;                                            */
/*  output uint8 VSCtl_stVSCtl;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidxVVStateIndic(void)
{
   uint8 u8LocalVSCtl_stVSRegExtd;
   uint8 u8LocalExt_stModRegVSCtlReq;
   uint8 u8LocalVSCtl_stVSLimExtd;


   VEMS_vidGET(VSCtl_stVSRegExtd, u8LocalVSCtl_stVSRegExtd);
   VEMS_vidGET(Ext_stModRegVSCtlReq, u8LocalExt_stModRegVSCtlReq);
   VEMS_vidGET(VSCtl_stVSLimExtd, u8LocalVSCtl_stVSLimExtd);

   if (  (  (u8LocalExt_stModRegVSCtlReq == 1)
         && (  (u8LocalVSCtl_stVSRegExtd == 4)
            || (u8LocalVSCtl_stVSRegExtd == 5)))
      || (  (u8LocalVSCtl_stVSLimExtd == 5)
         && (  (u8LocalExt_stModRegVSCtlReq == 2))))
   {
      VEMS_vidSET(VSCtl_stVSCtl, 2);
   }
   else
   {
      if (  (  (u8LocalVSCtl_stVSRegExtd == 6)
            && (u8LocalExt_stModRegVSCtlReq == 1))
         || (  (u8LocalVSCtl_stVSLimExtd == 6)
            && (u8LocalExt_stModRegVSCtlReq == 2)))
      {
         VEMS_vidSET(VSCtl_stVSCtl, 1);
      }
      else
      {
         if (  (  (u8LocalVSCtl_stVSRegExtd == 3)
               && (u8LocalExt_stModRegVSCtlReq == 1))
            || (  (  (u8LocalVSCtl_stVSLimExtd == 4)
                  && (u8LocalExt_stModRegVSCtlReq == 2))
               || (  (u8LocalVSCtl_stVSLimExtd == 3)
                  && (u8LocalExt_stModRegVSCtlReq == 2))))
         {
            VEMS_vidSET(VSCtl_stVSCtl, 0);
         }
         else
         {
            VEMS_vidSET(VSCtl_stVSCtl, 3);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidxVVFailCond                              */
/* !Description :  Appel de la fonction CRSCTLOUTTREAT_vidxVVFail si          */
/*                 Ext_bVSRegCf = 1 ou Ext_bVSLimCf = 1                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLOUTTREAT_vidxVVFail();                             */
/*  input uint8 Ext_stDVSRegCf;                                               */
/*  input boolean Ext_bVSLimCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidxVVFailCond(void)
{
   boolean bLocalExt_bVSLimCf;
   uint8   u8LocalExt_stDVSRegCf;


   VEMS_vidGET(Ext_stDVSRegCf, u8LocalExt_stDVSRegCf);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);

   if (  (u8LocalExt_stDVSRegCf == 1)
      || (bLocalExt_bVSLimCf != 0))
   {
      CRSCTLOUTTREAT_vidxVVFail();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidxVVFail                                  */
/* !Description :  Appel de la fonction CRSCTLOUTTREAT_vidSubSystem si        */
/*                 Ext_bKeyOff = 0 et Diag_on = 1                             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  sakrani.nouha                                              */
/* !Trace_To    :  VEMS_R_09_03334_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLOUTTREAT_vidSubSystem();                           */
/*  input boolean Ext_bKeyOff;                                                */
/*  input boolean Diag_on;                                                    */
/*  output boolean CrsCtl_bMonRunCrsCtlDft;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidxVVFail(void)
{
   boolean bLocalExt_bKeyOff;
   boolean bLocalDiag_on;


   VEMS_vidGET(Ext_bKeyOff, bLocalExt_bKeyOff);
   VEMS_vidGET(Diag_on, bLocalDiag_on);

   if (  (bLocalExt_bKeyOff == 0)
      && (bLocalDiag_on != 0))
   {
      CrsCtl_bMonRunCrsCtlDft = 1;
      CRSCTLOUTTREAT_vidSubSystem();
   }
   else
   {
      CrsCtl_bMonRunCrsCtlDft = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidSubSystem                                */
/* !Description :  calcul de Cc_defaut_rvv_lvv_mux et de CrsCtl_bDgoCrsCtlDft */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bKeyOff;                                                */
/*  input uint8 VSCtl_stVSLimExtd;                                            */
/*  input uint8 VSCtl_stVSRegExtd;                                            */
/*  input uint8 Ext_stModRegVSCtlReq;                                         */
/*  output boolean VSCtl_bVSCtlDft;                                           */
/*  output boolean CrsCtl_bDgoCrsCtlDft;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidSubSystem(void)
{
   boolean bLocalExt_bKeyOff;
   uint8   u8LocalVSCtl_stVSRegExtd;
   uint8   u8LocalVSCtl_stVSLimExtd;
   uint8   u8LocalExt_stModRegVSCtlReq;


   VEMS_vidGET(Ext_bKeyOff, bLocalExt_bKeyOff);
   VEMS_vidGET(VSCtl_stVSLimExtd, u8LocalVSCtl_stVSLimExtd);
   VEMS_vidGET(VSCtl_stVSRegExtd, u8LocalVSCtl_stVSRegExtd);
   VEMS_vidGET(Ext_stModRegVSCtlReq, u8LocalExt_stModRegVSCtlReq);

   if (bLocalExt_bKeyOff == 0)
   {
      if (  (  (u8LocalVSCtl_stVSLimExtd == 7)
            && (u8LocalExt_stModRegVSCtlReq == 2))
         || (  (u8LocalVSCtl_stVSRegExtd == 7)
            && (u8LocalExt_stModRegVSCtlReq == 1)))
      {
         VEMS_vidSET(VSCtl_bVSCtlDft, 1);
         CrsCtl_bDgoCrsCtlDft = 1;
      }
      else
      {
         VEMS_vidSET(VSCtl_bVSCtlDft, 0);
         CrsCtl_bDgoCrsCtlDft = 0;
      }
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSCtlDft, 0);
      CrsCtl_bDgoCrsCtlDft = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidxVVInFctTreat                            */
/* !Description :  Cette fonction active l'interface entre la fonction xVV et */
/*                 le reste des fonctions internes calculateur.               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CRSCTLOUTTREAT_vidFctTreatProc();                        */
/*  input uint8 Ext_stDVSRegCf;                                               */
/*  input boolean Ext_bVSLimCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidxVVInFctTreat(void)
{
   boolean bLocalExt_bVSLimCf;
   uint8   u8LocalExt_stDVSRegCf;


   VEMS_vidGET(Ext_stDVSRegCf, u8LocalExt_stDVSRegCf);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);

   if (  (u8LocalExt_stDVSRegCf == 1)
      || (bLocalExt_bVSLimCf != 0))
   {
      CRSCTLOUTTREAT_vidFctTreatProc();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CRSCTLOUTTREAT_vidFctTreatProc                             */
/* !Description :  Cette fonction sert d’interface entre la fonction xVV et le*/
/*                 reste des fonctions internes calculateur.                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VSCtl_rAccPEngMin;                                           */
/*  input uint16 VSCtl_rAccPEngMax;                                           */
/*  input sint16 TqDem_tqCkEfc;                                               */
/*  input sint16 VSCtl_tqCkEfcMin;                                            */
/*  input sint16 VSCtl_tqCkEfcMax;                                            */
/*  output uint8 Position_pedale_regulateur;                                  */
/*  output uint8 Position_pedale_limiteur;                                    */
/*  output boolean Cc_accel_pedal_regulation_master;                          */
/*  output boolean Cc_couple_lvv_effectif;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRSCTLOUTTREAT_vidFctTreatProc(void)
{
   uint8  u8LocalPosPedRegulateur;
   uint8  u8LocalPosPedlimiteur;
   uint16 u16LocalVSCtl_rAccPEngMin;
   uint16 u16LocalVSCtl_rAccPEngMax;
   sint16 s16LocalTqDem_tqCkEfc;
   sint16 s16LocalVSCtl_tqCkEfcMin;
   sint16 s16LocalVSCtl_tqCkEfcMax;


   VEMS_vidGET(VSCtl_rAccPEngMin, u16LocalVSCtl_rAccPEngMin);
   VEMS_vidGET(VSCtl_rAccPEngMax, u16LocalVSCtl_rAccPEngMax);
   VEMS_vidGET(TqDem_tqCkEfc, s16LocalTqDem_tqCkEfc);
   VEMS_vidGET(VSCtl_tqCkEfcMin, s16LocalVSCtl_tqCkEfcMin);
   VEMS_vidGET(VSCtl_tqCkEfcMax, s16LocalVSCtl_tqCkEfcMax);


   u16LocalVSCtl_rAccPEngMin = (uint16)(u16LocalVSCtl_rAccPEngMin / 50);
   u8LocalPosPedRegulateur =
      (uint8)MATHSRV_udtMIN(u16LocalVSCtl_rAccPEngMin, 255);
   VEMS_vidSET(Position_pedale_regulateur, u8LocalPosPedRegulateur);

   u16LocalVSCtl_rAccPEngMax = (uint16)(u16LocalVSCtl_rAccPEngMax / 50);
   u8LocalPosPedlimiteur =
      (uint8)MATHSRV_udtMIN(u16LocalVSCtl_rAccPEngMax, 255);
   VEMS_vidSET(Position_pedale_limiteur, u8LocalPosPedlimiteur);

   if (s16LocalTqDem_tqCkEfc <= s16LocalVSCtl_tqCkEfcMin)
   {
      VEMS_vidSET(Cc_accel_pedal_regulation_master, 1);
   }
   else
   {
      VEMS_vidSET(Cc_accel_pedal_regulation_master, 0);
   }

   if (s16LocalTqDem_tqCkEfc >= s16LocalVSCtl_tqCkEfcMax)
   {
      VEMS_vidSET(Cc_couple_lvv_effectif, 1);
   }
   else
   {
      VEMS_vidSET(Cc_couple_lvv_effectif, 0);
   }
}
/*--------------------------------- end of file ------------------------------*/