/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGAIREXTPRES                                          */
/* !Description     : DIAGAIREXTPRES component.                               */
/*                                                                            */
/* !Module          : DIAGAIREXTPRES                                          */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA PRESSION DE ATMOSPHERIQUE  */
/*                                                                            */
/* !File            : DIAGAIREXTPRES_FCT2.C                                   */
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
/*   1 / DIAGAIREXTPRES_vidCohAirPresOld                                      */
/*   2 / DIAGAIREXTPRES_vidMemBeforeWr                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 03594 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRPRES/DIAGAIREXTPRES/DIAGAIREX$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   19 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "DIAGAIREXTPRES.h"
#include "DIAGAIREXTPRES_L.h"
#include "DIAGAIREXTPRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidCohAirPresOld                            */
/* !Description :  Détection d'une pression atmosphérique incohérente par     */
/*                 rapport au roulage  précédent                              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 AirPres_pAirExtStrtPresSens;                                 */
/*  input uint16 AirPres_pAirExtRefOld;                                       */
/*  input uint16 AirPres_pAirExtThdGrdOldMax_C;                               */
/*  output uint16 AirPres_pAirExtGrdOld;                                      */
/*  output boolean AirPres_bDgoGrd_pAirExtOld;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidCohAirPresOld(void)
{
   uint16 u16LocalAirPres_pAirExtGrdOld;
   sint32 s32LocalpAirStrtPresSensRefOld;


   s32LocalpAirStrtPresSensRefOld = (sint32)( AirPres_pAirExtStrtPresSens
                                            - AirPres_pAirExtRefOld);
   u16LocalAirPres_pAirExtGrdOld =
      (uint16)MATHSRV_udtABS(s32LocalpAirStrtPresSensRefOld);
   AirPres_pAirExtGrdOld =
      (uint16)MATHSRV_udtMIN(u16LocalAirPres_pAirExtGrdOld, 1000);
   if (u16LocalAirPres_pAirExtGrdOld > AirPres_pAirExtThdGrdOldMax_C)
   {
      AirPres_bDgoGrd_pAirExtOld = 1;
   }
   else
   {
      AirPres_bDgoGrd_pAirExtOld = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGAIREXTPRES_vidMemBeforeWr                              */
/* !Description :  Le système doit mémoriser la pression atmosphérique mesurée*/
/*                 au key-off                                                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_011.01                                     */
/*                 VEMS_E_11_03594_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  output uint16 UsThrM_pAirExtEstimRefOld;                                  */
/*  output uint16 AirPres_pAirExtRefOld;                                      */
/*  output boolean AirPres_bPresAirExtKOnMem;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGAIREXTPRES_vidMemBeforeWr(void)
{
   uint16 u16LocalExt_pAirExtMes;
   uint32 u32LocalpAirExtEstimRefOld;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   u32LocalpAirExtEstimRefOld = (uint32)((u16LocalExt_pAirExtMes * 25) / 2);
   UsThrM_pAirExtEstimRefOld =
      (uint16)MATHSRV_udtMIN(u32LocalpAirExtEstimRefOld, 65535);

   AirPres_pAirExtRefOld = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pAirExtMes,
                                                    500,
                                                    1500);
   AirPres_bPresAirExtKOnMem = 0;
}
/*---------------------------- end of file -----------------------------------*/