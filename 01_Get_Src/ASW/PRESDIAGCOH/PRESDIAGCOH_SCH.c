/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PRESDIAGCOH                                             */
/* !Description     : PRESDIAGCOH Component                                   */
/*                                                                            */
/* !Module          : PRESDIAGCOH                                             */
/* !Description     : PRESSURE SENSORS COHERENCY DIAGNOSIS                    */
/*                                                                            */
/* !File            : PRESDIAGCOH_SCH.C                                       */
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
/*   1 / Oil_EveRst_PresDiagCoh                                               */
/*   2 / Oil_EveKOn_PresDiagCoh                                               */
/*   3 / Oil_SdlFast_PresDiagCoh                                              */
/*                                                                            */
/* !Reference   : V02 NT 12 01298 / 04                                        */
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
#include "PRESDIAGCOH.h"
#include "PRESDIAGCOH_L.h"
#include "PRESDIAGCOH_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveRst_PresDiagCoh                                     */
/* !Description :  ECU Event Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PRESDIAGCOH_vidInitOutput();                             */
/*  extf argret void PRESDIAGCOH_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :   Oil_EveRst_PresDiagCoh                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveRst_PresDiagCoh(void)
{
   PRESDIAGCOH_vidInitOutput();
   PRESDIAGCOH_vidInitialization();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveKOn_PresDiagCoh                                     */
/* !Description :  Key On Event                                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PRESDIAGCOH_vidCounterKeyOn();                           */
/*  input uint8 PRESDIAGCOH_u8Inhib;                                          */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :   Oil_EveKOn_PresDiagCoh                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveKOn_PresDiagCoh(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;


   if (PRESDIAGCOH_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
      if (bLocalCtrl_bOilPropPresAcq != 0)
      {
         PRESDIAGCOH_vidCounterKeyOn();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlFast_PresDiagCoh                                    */
/* !Description :  Fast scheduler  Event                                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PRESDIAGCOH_vidInhDiagSecKeyOn();                        */
/*  extf argret void PRESDIAGCOH_vidPressureDiagnosis();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 PRESDIAGCOH_u8Inhib;                                          */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input boolean DgSen_bDgoOilPrssSupORng;                                   */
/*  input boolean DgSen_bMonRunOilPrssSupORng;                                */
/*  input boolean DgSen_bDgoOilPrssSdwnORng;                                  */
/*  input boolean DgSen_bMonRunOilPrssSdwnORng;                               */
/*  input boolean DgSen_bDgoAirPrssExtSup;                                    */
/*  input boolean DgSen_bMonRunAirPrssExtSup;                                 */
/*  input boolean DgSen_bDgoAirPrssExtSdwn;                                   */
/*  input boolean DgSen_bMonRunAirPrssExtSdwn;                                */
/*  input boolean DgSen_bDgoUsThrPrssSup;                                     */
/*  input boolean DgSen_bMonRunUsThrPrssSup;                                  */
/*  input boolean DgSen_bDgoUsThrPrssSdwn;                                    */
/*  input boolean DgSen_bMonRunUsThrPrssSdwn;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :   Oil_SdlFast_PresDiagCoh                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlFast_PresDiagCoh(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;


   if (PRESDIAGCOH_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
      if (bLocalCtrl_bOilPropPresAcq != 0)
      {
         /*F02_InhDiagSecondKeyOn*/
         PRESDIAGCOH_vidInhDiagSecKeyOn();

         /*F03_Pressure_Diagnosis*/
         PRESDIAGCOH_vidPressureDiagnosis();

         GDGAR_vidGdu(GD_DFT_OILPRSSSUPORNG,
                      DgSen_bDgoOilPrssSupORng,
                      DgSen_bMonRunOilPrssSupORng,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_OILPRSSSDWNORNG,
                      DgSen_bDgoOilPrssSdwnORng,
                      DgSen_bMonRunOilPrssSdwnORng,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_AIRPRSSEXTSUP,
                      DgSen_bDgoAirPrssExtSup,
                      DgSen_bMonRunAirPrssExtSup,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_AIRPRSSEXTSDWN,
                      DgSen_bDgoAirPrssExtSdwn,
                      DgSen_bMonRunAirPrssExtSdwn,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_USTHRPRSSSUP,
                      DgSen_bDgoUsThrPrssSup,
                      DgSen_bMonRunUsThrPrssSup,
                      DIAG_DISPO);

         GDGAR_vidGdu(GD_DFT_USTHRPRSSSDOWN,
                      DgSen_bDgoUsThrPrssSdwn,
                      DgSen_bMonRunUsThrPrssSdwn,
                      DIAG_DISPO);
      }
   }
}
/*-------------------------------- end of file -------------------------------*/