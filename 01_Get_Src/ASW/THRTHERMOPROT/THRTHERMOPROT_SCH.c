/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRTHERMOPROT                                           */
/* !Description     : THRTHERMOPROT component                                 */
/*                                                                            */
/* !Module          : THRTHERMOPROT                                           */
/* !Description     : DIAGNOSTIC DE L’ECHAUFFEMENT THERMIQUE DU BOITIER       */
/*                    PAPILLON                                                */
/*                                                                            */
/* !File            : THRTHERMOPROT_SCH.C                                     */
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
/*   1 / Thr_EveRst_ThermoProt                                                */
/*   2 / Thr_EveClcnServo_ThermoProt                                          */
/*   3 / Thr_SdlMid_ThermoProt                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 00381 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRTHERMOPROT/THRTHERMOPROT_SC$*/
/* $Revision::   1.2      $$Author::   acabresp       $$Date::   27 May 2010 $*/
/* $Author::   acabresp                               $$Date::   27 May 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRTHERMOPROT.h"
#include "THRTHERMOPROT_L.h"
#include "THRTHERMOPROT_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_ThermoProt                                      */
/* !Description :  Evènement de reset de la fonction papillon.                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  N.ABID                                                     */
/* !Trace_To    :  VEMS_R_10_00381_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRTHERMOPROT_vidInitOutput();                           */
/*  extf argret void THRTHERMOPROT_vidInit();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveRst_ThermoProt                                          */
/* !Trigger  : Thr_EveRst_ThermoProt                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_ThermoProt(void)
{
   THRTHERMOPROT_vidInitOutput();
   THRTHERMOPROT_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_ThermoProt                                */
/* !Description :  Evènement de calcul de la fonction papillon.               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  N.ABID                                                     */
/* !Trace_To    :  VEMS_R_10_00381_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRTHERMOPROT_vidFilThrVolt();                           */
/*  input uint8 THRTHERMOPROT_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_EveClcnServo_ThermoProt                                    */
/* !Trigger  : Thr_EveClcnServo_ThermoProt                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_ThermoProt(void)
{
   if (THRTHERMOPROT_u8Inhib != 0x5A)
   {
      THRTHERMOPROT_vidFilThrVolt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_ThermoProt                                      */
/* !Description :  Moniteur moyen de la fonction papillon.                    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  N.ABID                                                     */
/* !Trace_To    :  VEMS_R_10_00381_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRTHERMOPROT_vidDiagCdn();                              */
/*  extf argret void THRTHERMOPROT_vidEngTEstim();                            */
/*  extf argret void THRTHERMOPROT_vidDiag();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 THRTHERMOPROT_u8Inhib;                                        */
/*  input boolean Thr_bDgoOvldThermoThr;                                      */
/*  input boolean Thr_bMonRunOvldThermoThr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Thr_SdlMid_ThermoProt                                          */
/* !Trigger  : Thr_SdlMid_ThermoProt                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_ThermoProt(void)
{
   if (THRTHERMOPROT_u8Inhib != 0x5A)
   {
      THRTHERMOPROT_vidDiagCdn();
      THRTHERMOPROT_vidEngTEstim();
      THRTHERMOPROT_vidDiag();
      GDGAR_vidGdu(GD_DFT_OVLDTHERMOTHR,
                   Thr_bDgoOvldThermoThr,
                   Thr_bMonRunOvldThermoThr,
                   DIAG_DISPO);
   }
}

/*------------------------------- end of file --------------------------------*/