/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILMNG                                               */
/* !Description     : IGCOILMNG component.                                    */
/*                                                                            */
/* !Module          : IGCOILMNG                                               */
/* !Description     : COMMANDE ET DIAGNOSTIC DES BOBINES D’ALLUMAGE           */
/*                                                                            */
/* !File            : IGCOILMNG_FCT2.C                                        */
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
/*   1 / IGCOILMNG_vidTestInhibIgn                                            */
/*   2 / IGCOILMNG_vidInhibIgn                                                */
/*   3 / IGCOILMNG_vidInhibIgnNext                                            */
/*   4 / IGCOILMNG_vidProgAvance                                              */
/*   5 / IGCOILMNG_vidProgAvanceNext                                          */
/*   6 / IGCOILMNG_vidDiagnostic                                              */
/*   7 / IGCOILMNG_vidDiagBob1                                                */
/*   8 / IGCOILMNG_vidDiagBob2                                                */
/*   9 / IGCOILMNG_vidDiagBob3                                                */
/*   10 / IGCOILMNG_vidDiagBob4                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6668934 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/IGCOILMNG/IGCOILMNG_FCT2.C_v      $*/
/* $Revision::   1.14     $$Author::   achebino       $$Date::   02 Jul 2014 $*/
/* $Author::   achebino                               $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCOILMNG.h"
#include "IGCOILMNG_L.h"
#include "IGCOILMNG_IM.h"
#include "IGNHAL.h"
#include "SWFAIL.h"
#include "IGCOILMNG_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidTestInhibIgn                                  */
/* !Description :  Ce bloc gère la demande d’inhibition de la bobine du       */
/*                 cylindre en cours de compression et celle de la bobine du  */
/*                 cylindre suivant.                                          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 IMMO_stEcuLockStTyp;                                         */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input boolean Misfire_cylindre_1;                                         */
/*  input boolean Manu_coupure_bob_1;                                         */
/*  input boolean Misfire_cylindre_2;                                         */
/*  input boolean Manu_coupure_bob_2;                                         */
/*  input boolean Misfire_cylindre_3;                                         */
/*  input boolean Manu_coupure_bob_3;                                         */
/*  input boolean Misfire_cylindre_4;                                         */
/*  input boolean Manu_coupure_bob_4;                                         */
/*  output boolean IgCmd_bInhIgCoilCmd;                                       */
/*  output boolean IgCmd_bInhIgCoilNxtCmd;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidTestInhibIgn(void)
{
   boolean bLocalClef_de_contact;
   boolean bLocalMisfire_cylindre_1;
   boolean bLocalMisfire_cylindre_2;
   boolean bLocalMisfire_cylindre_3;
   boolean bLocalMisfire_cylindre_4;
   boolean bLocalIgnInhFlag;
   uint8   u8LocalEng_noCmprCyl;
   uint8   u8LocalEng_noCmprNxtCyl;
   uint16  u16LocalIMMO_stEcuLockStTyp;

   VEMS_vidGET(IMMO_stEcuLockStTyp, u16LocalIMMO_stEcuLockStTyp);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);

   if (   (u16LocalIMMO_stEcuLockStTyp != IMMO_ECU_UNLOCKED)
        ||(bLocalClef_de_contact == 0))
   {
      bLocalIgnInhFlag = 1;
   }
   else
   {
      bLocalIgnInhFlag = 0;
   }
   switch (u8LocalEng_noCmprCyl)
   {
      case 1:
      VEMS_vidGET(Misfire_cylindre_1, bLocalMisfire_cylindre_1);

      if (  (Manu_coupure_bob_1 != 0)
          ||(bLocalMisfire_cylindre_1 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilCmd = 0;
      }
      break;

      case 2:
      VEMS_vidGET(Misfire_cylindre_2, bLocalMisfire_cylindre_2);

      if (  (Manu_coupure_bob_2 != 0)
          ||(bLocalMisfire_cylindre_2 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilCmd = 0;
      }
      break;

      case 3:
      VEMS_vidGET(Misfire_cylindre_3, bLocalMisfire_cylindre_3);

      if (  (Manu_coupure_bob_3 != 0)
          ||(bLocalMisfire_cylindre_3 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilCmd = 0;
      }
      break;

      case 4:
      VEMS_vidGET(Misfire_cylindre_4, bLocalMisfire_cylindre_4);

      if (  (Manu_coupure_bob_4 != 0)
          ||(bLocalMisfire_cylindre_4 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilCmd = 0;
      }
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
   switch (u8LocalEng_noCmprNxtCyl)
   {
      case 1:
      VEMS_vidGET(Misfire_cylindre_1, bLocalMisfire_cylindre_1);

      if (  (Manu_coupure_bob_1 != 0)
          ||(bLocalMisfire_cylindre_1 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilNxtCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilNxtCmd = 0;
      }
      break;

      case 2:
      VEMS_vidGET(Misfire_cylindre_2, bLocalMisfire_cylindre_2);

      if (  (Manu_coupure_bob_2 != 0)
          ||(bLocalMisfire_cylindre_2 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilNxtCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilNxtCmd = 0;
      }
      break;

      case 3:
      VEMS_vidGET(Misfire_cylindre_3, bLocalMisfire_cylindre_3);

      if (  (Manu_coupure_bob_3 != 0)
          ||(bLocalMisfire_cylindre_3 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilNxtCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilNxtCmd = 0;
      }
      break;

      case 4:
      VEMS_vidGET(Misfire_cylindre_4, bLocalMisfire_cylindre_4);

      if (  (Manu_coupure_bob_4 != 0)
          ||(bLocalMisfire_cylindre_4 != 0)
          ||(bLocalIgnInhFlag != 0))
      {
         IgCmd_bInhIgCoilNxtCmd = 1;
      }
      else
      {
         IgCmd_bInhIgCoilNxtCmd = 0;
      }
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}
/*QAC Warning(2:4700): complexity accepted                                    */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidInhibIgn                                      */
/* !Description :  Calling IGNHAL_vidInhibCoil for the current cylinder.      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGNHAL_vidInhibCoil(argin uint8 u8Channel);              */
/*  input uint8 IgCmd_stCurIgCoil;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidInhibIgn(void)
{
   IGNHAL_vidInhibCoil(IgCmd_stCurIgCoil);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidInhibIgnNext                                  */
/* !Description :  Calling IGNHAL_vidInhibCoil for the next cylinder.         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGNHAL_vidInhibCoil(argin uint8 u8Channel);              */
/*  input uint8 IgCmd_stCurNxtIgCoil;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidInhibIgnNext(void)
{
   IGNHAL_vidInhibCoil(IgCmd_stCurNxtIgCoil);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidProgAvance                                    */
/* !Description :  Calling IgnHALWriteAngle for the current cylinder.         */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IgnHALWriteAngle(argin uint8 u8Channel, argin uint16     */
/* u16Advance);                                                               */
/*  input uint8 IgCmd_agIgSp;                                                 */
/*  input uint8 IgCmd_stCurIgCoil;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidProgAvance(void)
{
   uint8  u8LocalIgCmd_agIgSp;
   uint16 u16LocalIgCmd_agIgSp;
   sint16 s16LocalIgCmd_agIgSpScaling;

   VEMS_vidGET(IgCmd_agIgSp,u8LocalIgCmd_agIgSp);

   /*Converting the IgCmd_agIgSp to match the resolution used in
         IgnHALWriteAngle (with resolution 1/64 and offset -36)*/
   /* Correction de  VEMS V02 ECU#059792 par VVOY*/
   s16LocalIgCmd_agIgSpScaling = (sint16)(24 * u8LocalIgCmd_agIgSp);
   u16LocalIgCmd_agIgSp =
      (uint16)MATHSRV_udtMAX(s16LocalIgCmd_agIgSpScaling, 0);
   IgnHALWriteAngle(IgCmd_stCurIgCoil, u16LocalIgCmd_agIgSp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidProgAvanceNext                                */
/* !Description :  Calling IgnHALWriteAngle for the next cylinder.            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IgnHALWriteAngle(argin uint8 u8Channel, argin uint16     */
/* u16Advance);                                                               */
/*  input uint8 IgCmd_agIgSpNxt;                                              */
/*  input uint8 IgCmd_stCurNxtIgCoil;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidProgAvanceNext(void)
{
   uint8  u8LocalIgCmd_agIgSpNxt;
   uint16 u16LocalIgCmd_agIgSpNxt;
   sint16 s16LocalIgCmd_agIgSpNxtScaling;

   VEMS_vidGET(IgCmd_agIgSpNxt,u8LocalIgCmd_agIgSpNxt);

   /*Converting the IgCmd_agIgSpNxt to match the resolution used in
          IgnHALWriteAngle (with resolution 1/64 and offset -36)*/
   /* Correction de  VEMS V02 ECU#059792 par VVOY*/
   s16LocalIgCmd_agIgSpNxtScaling = (sint16)(24 * u8LocalIgCmd_agIgSpNxt);
   u16LocalIgCmd_agIgSpNxt =
      (uint16)MATHSRV_udtMAX(s16LocalIgCmd_agIgSpNxtScaling, 0);
   IgnHALWriteAngle(IgCmd_stCurNxtIgCoil, u16LocalIgCmd_agIgSpNxt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDiagnostic                                    */
/* !Description :  Pour garder la transversalité 3 cylindres/4 cylindres,     */
/*                 l'appel au diagnostic se fera pour tous les cylindres à    */
/*                 chaque PMB. Les diagnostics non réalisés seront couverts   */
/*                 par les _bMonRun à 0                                       */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILMNG_vidDiagBob1();                                 */
/*  extf argret void IGCOILMNG_vidDiagBob2();                                 */
/*  extf argret void IGCOILMNG_vidDiagBob3();                                 */
/*  extf argret void IGCOILMNG_vidDiagBob4();                                 */
/*  input uint8 Ext_noCylEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDiagnostic(void)
{
   uint8 u8LocalExt_noCylEng;

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   IGCOILMNG_vidDiagBob1();
   IGCOILMNG_vidDiagBob2();
   IGCOILMNG_vidDiagBob3();

   if (u8LocalExt_noCylEng == 4)
   {
      IGCOILMNG_vidDiagBob4();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDiagBob1                                      */
/* !Description :  Fonction du diagnostic du bobine 1                         */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidDiagCoil(argin uint32 udtChannel,argout     */
/*  boolean *bDgoOc,argout boolean *bMonRunOc,argout boolean *bDgoScg,argout  */
/*  boolean *bMonRunScg,argout boolean *bDgoScp,argout boolean *bMonRunScp);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_oc_bobine1;                                            */
/*  output boolean Dft_scg_bobine1;                                           */
/*  output boolean Dft_scp_bobine1;                                           */
/*  output boolean Dena_oc_bobine1;                                           */
/*  output boolean Dena_scg_bobine1;                                          */
/*  output boolean Dena_scp_bobine1;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDiagBob1(void)
{
   boolean bLocalDgoOc;
   boolean bLocalMonRunOc;
   boolean bLocalDgoScg;
   boolean bLocalMonRunScg;
   boolean bLocalDgoScp;
   boolean bLocalMonRunScp;


   IGCOILMNG_vidDiagCoil(DGO_COIL_CYLINDER_1,
                         &bLocalDgoOc,
                         &bLocalMonRunOc,
                         &bLocalDgoScg,
                         &bLocalMonRunScg,
                         &bLocalDgoScp,
                         &bLocalMonRunScp);
   VEMS_vidSET(Dft_oc_bobine1, bLocalDgoOc);
   VEMS_vidSET(Dft_scg_bobine1, bLocalDgoScg);
   VEMS_vidSET(Dft_scp_bobine1, bLocalDgoScp);
   VEMS_vidSET(Dena_oc_bobine1, bLocalMonRunOc);
   VEMS_vidSET(Dena_scg_bobine1, bLocalMonRunScg);
   VEMS_vidSET(Dena_scp_bobine1, bLocalMonRunScp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDiagBob2                                      */
/* !Description :  Fonction du diagnostic du bobine 2                         */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidDiagCoil(argin uint32 udtChannel,argout     */
/*  boolean *bDgoOc,argout boolean *bMonRunOc,argout boolean *bDgoScg,argout  */
/*  boolean *bMonRunScg,argout boolean *bDgoScp,argout boolean *bMonRunScp);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_oc_bobine2;                                            */
/*  output boolean Dft_scg_bobine2;                                           */
/*  output boolean Dft_scp_bobine2;                                           */
/*  output boolean Dena_oc_bobine2;                                           */
/*  output boolean Dena_scg_bobine2;                                          */
/*  output boolean Dena_scp_bobine2;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDiagBob2(void)
{
   boolean bLocalDgoOc;
   boolean bLocalMonRunOc;
   boolean bLocalDgoScg;
   boolean bLocalMonRunScg;
   boolean bLocalDgoScp;
   boolean bLocalMonRunScp;


   IGCOILMNG_vidDiagCoil(DGO_COIL_CYLINDER_2,
                         &bLocalDgoOc,
                         &bLocalMonRunOc,
                         &bLocalDgoScg,
                         &bLocalMonRunScg,
                         &bLocalDgoScp,
                         &bLocalMonRunScp);
   VEMS_vidSET(Dft_oc_bobine2, bLocalDgoOc);
   VEMS_vidSET(Dft_scg_bobine2, bLocalDgoScg);
   VEMS_vidSET(Dft_scp_bobine2, bLocalDgoScp);
   VEMS_vidSET(Dena_oc_bobine2, bLocalMonRunOc);
   VEMS_vidSET(Dena_scg_bobine2, bLocalMonRunScg);
   VEMS_vidSET(Dena_scp_bobine2, bLocalMonRunScp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDiagBob3                                      */
/* !Description :  Fonction du diagnostic du bobine 3                         */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidDiagCoil(argin uint32 udtChannel,argout     */
/*  boolean *bDgoOc,argout boolean *bMonRunOc,argout boolean *bDgoScg,argout  */
/*  boolean *bMonRunScg,argout boolean *bDgoScp,argout boolean *bMonRunScp);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_oc_bobine3;                                            */
/*  output boolean Dft_scg_bobine3;                                           */
/*  output boolean Dft_scp_bobine3;                                           */
/*  output boolean Dena_oc_bobine3;                                           */
/*  output boolean Dena_scg_bobine3;                                          */
/*  output boolean Dena_scp_bobine3;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDiagBob3(void)
{
   boolean bLocalDgoOc;
   boolean bLocalMonRunOc;
   boolean bLocalDgoScg;
   boolean bLocalMonRunScg;
   boolean bLocalDgoScp;
   boolean bLocalMonRunScp;


   IGCOILMNG_vidDiagCoil(DGO_COIL_CYLINDER_3,
                         &bLocalDgoOc,
                         &bLocalMonRunOc,
                         &bLocalDgoScg,
                         &bLocalMonRunScg,
                         &bLocalDgoScp,
                         &bLocalMonRunScp);
   VEMS_vidSET(Dft_oc_bobine3, bLocalDgoOc);
   VEMS_vidSET(Dft_scg_bobine3, bLocalDgoScg);
   VEMS_vidSET(Dft_scp_bobine3, bLocalDgoScp);
   VEMS_vidSET(Dena_oc_bobine3, bLocalMonRunOc);
   VEMS_vidSET(Dena_scg_bobine3, bLocalMonRunScg);
   VEMS_vidSET(Dena_scp_bobine3, bLocalMonRunScp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILMNG_vidDiagBob4                                      */
/* !Description :  Fonction du diagnostic du bobine 4. La génération des      */
/*                 événements CALL_GduOc_IgCoil4Cmd et CALL_GduScp_IgCoil4Cmd */
/*                 doit se faire après l’appel de l’API DgoHALRead.           */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILMNG_vidDiagCoil(argin uint32 udtChannel,argout     */
/*  boolean *bDgoOc,argout boolean *bMonRunOc,argout boolean *bDgoScg,argout  */
/*  boolean *bMonRunScg,argout boolean *bDgoScp,argout boolean *bMonRunScp);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_oc_bobine4;                                            */
/*  output boolean Dft_scg_bobine4;                                           */
/*  output boolean Dft_scp_bobine4;                                           */
/*  output boolean Dena_oc_bobine4;                                           */
/*  output boolean Dena_scg_bobine4;                                          */
/*  output boolean Dena_scp_bobine4;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILMNG_vidDiagBob4(void)
{
   boolean bLocalDgoOc;
   boolean bLocalMonRunOc;
   boolean bLocalDgoScg;
   boolean bLocalMonRunScg;
   boolean bLocalDgoScp;
   boolean bLocalMonRunScp;

   IGCOILMNG_vidDiagCoil(DGO_COIL_CYLINDER_4,
                         &bLocalDgoOc,
                         &bLocalMonRunOc,
                         &bLocalDgoScg,
                         &bLocalMonRunScg,
                         &bLocalDgoScp,
                         &bLocalMonRunScp);
   VEMS_vidSET(Dft_oc_bobine4, bLocalDgoOc);
   VEMS_vidSET(Dft_scg_bobine4, bLocalDgoScg);
   VEMS_vidSET(Dft_scp_bobine4, bLocalDgoScp);
   VEMS_vidSET(Dena_oc_bobine4, bLocalMonRunOc);
   VEMS_vidSET(Dena_scg_bobine4, bLocalMonRunScg);
   VEMS_vidSET(Dena_scp_bobine4, bLocalMonRunScp);
}

/*---------------------------------end of file--------------------------------*/