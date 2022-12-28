/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDEXTINT                                                */
/* !Description     : GDEXTINT Component                                      */
/*                                                                            */
/* !Module          : GDEXTINT                                                */
/* !Description     : GD EXTERNAL INTERFACE                                   */
/*                                                                            */
/* !File            : GDEXTINT_FCT3.C                                         */
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
/*   1 / GDEXTINT_vidSetEventSt                                               */
/*   2 / GDEXTINT_vidSetEventSt_reinit                                        */
/*   3 / GDEXTINT_vidRstEventSt                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5075312 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDEXTINT/GDEXTINT_FCT3.C_v   $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   30 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   30 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "MATHSRV.h"
#include "GDExtInt.h"
#include "GDExtInt_L.h"
#include "GDExtInt_IM.h"
#include "Rte_Type.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_vidSetEventSt                                     */
/* !Description :  Update the GAR upon changes of the event status            */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void Fim_DemTriggerOnEventStatus(argin uint16 u16DftIdx, argin*/
/* uint8 u8StatusOld, argin uint8 u8Status);                                  */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  input uint8 u8StatusOld[8];                                               */
/*  output uint8 u8StatusOld[8];                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDEXTINT_vidSetEventSt
(
   uint16 u16IdxDft
)
{
   uint8 u8LocalGD_prmDtcStatus;


   if (u16IdxDft < GD_DFT_NB)
   {
      VEMS_vidGET1DArrayElement(GD_prmDtcStatus,u16IdxDft,
                                u8LocalGD_prmDtcStatus);
      Fim_DemTriggerOnEventStatus(u16IdxDft,
                                  u8StatusOld[u16IdxDft],
                                  u8LocalGD_prmDtcStatus);

      u8StatusOld[u16IdxDft] = u8LocalGD_prmDtcStatus;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_vidSetEventSt_reinit                              */
/* !Description :  Update the GAR upon changes of the event status            */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void Fim_DemTriggerOnEventStatus_opt(argin uint16 u16DftIdx,  */
/* argin uint8 u8StatusOld, argin uint8 u8Status);                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 GD_prmDtcStatus[8];                                           */
/*  input uint8 u8StatusOld[8];                                               */
/*  output uint8 u8StatusOld[8];                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDEXTINT_vidSetEventSt_reinit /*il faut mettre a jour cette fonction si la
fonction GDEXTINT_vidSetEventSt evolue*/
(
   uint16 u16IdxDft
)
{
   uint8 u8LocalGD_prmDtcStatus;


   if (u16IdxDft < GD_DFT_NB)
   {
      VEMS_vidGET1DArrayElement(GD_prmDtcStatus,u16IdxDft,
                                u8LocalGD_prmDtcStatus);
      Fim_DemTriggerOnEventStatus_opt(u16IdxDft,
                                      u8StatusOld[u16IdxDft],
                                      u8LocalGD_prmDtcStatus);

      u8StatusOld[u16IdxDft] = u8LocalGD_prmDtcStatus;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDEXTINT_vidRstEventSt                                     */
/* !Description :  Event indicating an update of StatusOfDTC information on   */
/*                 failure clear                                              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FIM_DemInit();                                           */
/*  output uint8 u8StatusOld[8];                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDEXTINT_vidRstEventSt(void)
{
   sint32 s32LocalIndex;


   Fim_DemInit();
   for (s32LocalIndex = 0; s32LocalIndex < GD_DFT_NB; s32LocalIndex++)
   {
      u8StatusOld[s32LocalIndex] = 0x50;
   }
}
/*------------------------------- end of file --------------------------------*/