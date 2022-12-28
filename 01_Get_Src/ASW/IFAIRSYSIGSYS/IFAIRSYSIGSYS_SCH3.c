/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_SCH3.C                                    */
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
/*   1 / Can_SdlSlow_FHCanF349If_2                                            */
/*   2 / DIAGCAN_EveRst_If                                                    */
/*   3 / Can_EveRst_FHCanF432If                                               */
/*   4 / Can_EveRst_FHCanF495If                                               */
/*   5 / Can_EveRst_FHCanF592If                                               */
/*   6 / Can_EveRst_FHCanF612If                                               */
/*   7 / EngSt_EveRst_EngStrtStopIf                                           */
/*   8 / Can_EveRxn4F2_FHCanF4F2AVIf                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
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
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlSlow_FHCanF349If_2                                  */
/* !Description :  Moniteur lent pour la fonction FH CAN F349h.               */
/* !Number      :  SCH3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidIntfacIsCanIf2();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*  input boolean Ctrl_bTraNoTarGear;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlSlow_FHCanF349If_2                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlSlow_FHCanF349If_2(void)
{
   boolean  bLocalCtrl_bTraNoTarGear;


   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTraNoTarGear, bLocalCtrl_bTraNoTarGear);
      if (bLocalCtrl_bTraNoTarGear != 0)
      {
         IFAIRSYSIGSYS_vidIntfacIsCanIf2();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGCAN_EveRst_If                                          */
/* !Description :  Evènement reset.                                           */
/* !Number      :  SCH3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutbElecltgr();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DIAGCAN_EveRst_If                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGCAN_EveRst_If(void)
{
   IFAIRSYSIGSYS_vidOutbElecltgr();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF432If                                     */
/* !Description :  Evenement reset lie au CAN                                 */
/* !Number      :  SCH3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutSlaveWkuReq();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF432If                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF432If(void)
{
   IFAIRSYSIGSYS_vidOutSlaveWkuReq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF495If                                     */
/* !Description :  Evenement reset lie au CAN.                                */
/* !Number      :  SCH3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutEngStopAuth();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF495If                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF495If(void)
{
   IFAIRSYSIGSYS_vidOutEngStopAuth();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF592If                                     */
/* !Description :  Evenement reset lié au CAN                                 */
/* !Number      :  SCH3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutNotAvlBatMes();                      */
/*  extf argret void IFAIRSYSIGSYS_vidOutput_iBattMes();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF592If                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF592If(void)
{
   IFAIRSYSIGSYS_vidOutNotAvlBatMes();
   IFAIRSYSIGSYS_vidOutput_iBattMes();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF612If                                     */
/* !Description :  Event reset lie au CAN                                     */
/* !Number      :  SCH3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidFuTnk();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF612If                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF612If(void)
{
   IFAIRSYSIGSYS_vidFuTnk();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngStrtStopIf                                 */
/* !Description :  Evenement reset du calculateur.                            */
/* !Number      :  SCH3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidFrstCrk();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngStrtStopIf                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngStrtStopIf(void)
{
   IFAIRSYSIGSYS_vidFrstCrk();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn4F2_FHCanF4F2AVIf                                */
/* !Description :  Evnement de rception de la trame 4F2                       */
/* !Number      :  SCH3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutFHCanF4F2AV();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn4F2_FHCanF4F2AVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutFHCanF4F2AV();
   }
}
/*-------------------------------- end of file -------------------------------*/