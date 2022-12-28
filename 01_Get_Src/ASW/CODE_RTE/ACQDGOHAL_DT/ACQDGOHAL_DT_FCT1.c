/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQDGOHAL_DT                                            */
/* !Description     : ACQDGOHAL_DT Component.                                 */
/*                                                                            */
/* !Module          : ACQDGOHAL_DT                                            */
/* !Description     : Acquisition of Diagnoses States and results for specific*/
/*                    components                                              */
/*                                                                            */
/* !File            : ACQDGOHAL_DT_FCT1.C                                     */
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
/*   1 / ACQDGOHAL_DT_vidDgoHalInit                                           */
/*   2 / ACQDGOHAL_DT_vidDgoHalCtlPmpReq                                      */
/*   3 / ACQDGOHAL_DT_vidDgoHalCmdWgc                                         */
/*   4 / ACQDGOHAL_DT_vidDgoHalDmpVlvCmd                                      */
/*   5 / ACQDGOHAL_DT_vidDgoHlHPPmpActCmd                                     */
/*   6 / ACQDGOHAL_DT_vidDgoHalTrbWaPmp                                       */
/*   7 / ACQDGOHAL_DT_vidDgoHalCTP                                            */
/*   8 / ACQDGOHAL_DT_vidDgoHalASICGDI                                        */
/*   9 / ACQDGOHAL_DT_vidDgoHalOilLvlAcq                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6854092 / 01                                        */
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

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACQDGOHAL_DT.h"
#include "ACQDGOHAL_DT_L.h"
#include "ACQDGOHAL_DT_IM.h"
#include "DGOHAL.h"
#include "ACQDGOHAL_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalInit                                 */
/* !Description :  All the outputs of the API DGOHAL BSW are initialized to 0.*/
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_scg_WgcCmd;                                            */
/*  output boolean Dena_oc_WgcCmd;                                            */
/*  output boolean Dft_oc_WgcCmd;                                             */
/*  output boolean Dena_ovld_HPPmpActCmd;                                     */
/*  output boolean Dft_ovld_HPPmpActCmd;                                      */
/*  output boolean Dena_scp_HPPmpActCmd;                                      */
/*  output boolean Dft_scp_HPPmpActCmd;                                       */
/*  output boolean Dena_scg_HPPmpActCmd;                                      */
/*  output boolean Dft_scg_HPPmpActCmd;                                       */
/*  output boolean Dena_oc_HPPmpActCmd;                                       */
/*  output boolean Dft_oc_HPPmpActCmd;                                        */
/*  output boolean Dena_scp_DmpVlvCmd;                                        */
/*  output boolean Dft_scp_DmpVlvCmd;                                         */
/*  output boolean Dena_scg_DmpVlvCmd;                                        */
/*  output boolean Dft_scg_DmpVlvCmd;                                         */
/*  output boolean Dena_oc_DmpVlvCmd;                                         */
/*  output boolean Dft_oc_DmpVlvCmd;                                          */
/*  output boolean Dena_scp_CtlPmpReq;                                        */
/*  output boolean Dft_scp_CtlPmpReq;                                         */
/*  output boolean Dena_scg_CtlPmpReq;                                        */
/*  output boolean Dft_scg_CtlPmpReq;                                         */
/*  output boolean Dena_oc_CtlPmpReq;                                         */
/*  output boolean Dft_oc_CtlPmpReq;                                          */
/*  output boolean Dena_oc_CTP2;                                              */
/*  output boolean Dft_oc_CTP2;                                               */
/*  output boolean Dena_scp_CTP1;                                             */
/*  output boolean Dft_scp_CTP1;                                              */
/*  output boolean Dena_scg_CTP1;                                             */
/*  output boolean Dft_scg_CTP1;                                              */
/*  output boolean Dena_oc_CTP1;                                              */
/*  output boolean Dft_oc_CTP1;                                               */
/*  output boolean Dena_scp_TrbWaPmp;                                         */
/*  output boolean Dft_scp_TrbWaPmp;                                          */
/*  output boolean Dena_scg_TrbWaPmp;                                         */
/*  output boolean Dft_scg_TrbWaPmp;                                          */
/*  output boolean Dena_oc_TrbWaPmp;                                          */
/*  output boolean Dft_oc_TrbWaPmp;                                           */
/*  output boolean Dena_scp_WgcCmd;                                           */
/*  output boolean Dft_scp_WgcCmd;                                            */
/*  output boolean Dena_scg_WgcCmd;                                           */
/*  output boolean Dena_scp_OilLvlAcq;                                        */
/*  output boolean Dft_scp_OilLvlAcq;                                         */
/*  output boolean Dena_scg_OilLvlAcq;                                        */
/*  output boolean Dft_scg_OilLvlAcq;                                         */
/*  output boolean Dena_oc_OilLvlAcq;                                         */
/*  output boolean Dft_oc_OilLvlAcq;                                          */
/*  output boolean Dena_UnderVBoost_ASICGDI;                                  */
/*  output boolean Dft_UnderVBoost_ASICGDI;                                   */
/*  output boolean Dena_OverVBoost_ASICGDI;                                   */
/*  output boolean Dft_OverVBoost_ASICGDI;                                    */
/*  output boolean Dena_ComSpi_ASICGDI;                                       */
/*  output boolean Dft_ComSpi_ASICGDI;                                        */
/*  output boolean Dena_UnderVBat_ASICGDI;                                    */
/*  output boolean Dft_UnderVBat_ASICGDI;                                     */
/*  output boolean Dena_OverVBat_ASICGDI;                                     */
/*  output boolean Dft_OverVBat_ASICGDI;                                      */
/*  output boolean Dena_scp_CTP2;                                             */
/*  output boolean Dft_scp_CTP2;                                              */
/*  output boolean Dena_scg_CTP2;                                             */
/*  output boolean Dft_scg_CTP2;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalInit(void)
{
   VEMS_vidSET(Dft_scg_WgcCmd, 0);
   VEMS_vidSET(Dena_oc_WgcCmd, 0);
   VEMS_vidSET(Dft_oc_WgcCmd, 0);
   VEMS_vidSET(Dena_ovld_HPPmpActCmd, 0);
   VEMS_vidSET(Dft_ovld_HPPmpActCmd, 0);
   VEMS_vidSET(Dena_scp_HPPmpActCmd, 0);
   VEMS_vidSET(Dft_scp_HPPmpActCmd, 0);
   VEMS_vidSET(Dena_scg_HPPmpActCmd, 0);
   VEMS_vidSET(Dft_scg_HPPmpActCmd, 0);
   VEMS_vidSET(Dena_oc_HPPmpActCmd, 0);
   VEMS_vidSET(Dft_oc_HPPmpActCmd, 0);
   VEMS_vidSET(Dena_scp_DmpVlvCmd, 0);
   VEMS_vidSET(Dft_scp_DmpVlvCmd, 0);
   VEMS_vidSET(Dena_scg_DmpVlvCmd, 0);
   VEMS_vidSET(Dft_scg_DmpVlvCmd, 0);
   VEMS_vidSET(Dena_oc_DmpVlvCmd, 0);
   VEMS_vidSET(Dft_oc_DmpVlvCmd, 0);
   VEMS_vidSET(Dena_scp_CtlPmpReq, 0);
   VEMS_vidSET(Dft_scp_CtlPmpReq, 0);
   VEMS_vidSET(Dena_scg_CtlPmpReq, 0);
   VEMS_vidSET(Dft_scg_CtlPmpReq, 0);
   VEMS_vidSET(Dena_oc_CtlPmpReq, 0);
   VEMS_vidSET(Dft_oc_CtlPmpReq, 0);
   VEMS_vidSET(Dena_oc_CTP2, 0);
   VEMS_vidSET(Dft_oc_CTP2, 0);
   VEMS_vidSET(Dena_scp_CTP1, 0);
   VEMS_vidSET(Dft_scp_CTP1, 0);
   VEMS_vidSET(Dena_scg_CTP1, 0);
   VEMS_vidSET(Dft_scg_CTP1, 0);
   VEMS_vidSET(Dena_oc_CTP1, 0);
   VEMS_vidSET(Dft_oc_CTP1, 0);
   VEMS_vidSET(Dena_scp_TrbWaPmp, 0);
   VEMS_vidSET(Dft_scp_TrbWaPmp, 0);
   VEMS_vidSET(Dena_scg_TrbWaPmp, 0);
   VEMS_vidSET(Dft_scg_TrbWaPmp, 0);
   VEMS_vidSET(Dena_oc_TrbWaPmp, 0);
   VEMS_vidSET(Dft_oc_TrbWaPmp, 0);
   VEMS_vidSET(Dena_scp_WgcCmd, 0);
   VEMS_vidSET(Dft_scp_WgcCmd, 0);
   VEMS_vidSET(Dena_scg_WgcCmd, 0);
   VEMS_vidSET(Dena_scp_OilLvlAcq, 0);
   VEMS_vidSET(Dft_scp_OilLvlAcq, 0);
   VEMS_vidSET(Dena_scg_OilLvlAcq, 0);
   VEMS_vidSET(Dft_scg_OilLvlAcq, 0);
   VEMS_vidSET(Dena_oc_OilLvlAcq, 0);
   VEMS_vidSET(Dft_oc_OilLvlAcq, 0);
   VEMS_vidSET(Dena_UnderVBoost_ASICGDI, 0);
   VEMS_vidSET(Dft_UnderVBoost_ASICGDI, 0);
   VEMS_vidSET(Dena_OverVBoost_ASICGDI, 0);
   VEMS_vidSET(Dft_OverVBoost_ASICGDI, 0);
   VEMS_vidSET(Dena_ComSpi_ASICGDI, 0);
   VEMS_vidSET(Dft_ComSpi_ASICGDI, 0);
   VEMS_vidSET(Dena_UnderVBat_ASICGDI, 0);
   VEMS_vidSET(Dft_UnderVBat_ASICGDI, 0);
   VEMS_vidSET(Dena_OverVBat_ASICGDI, 0);
   VEMS_vidSET(Dft_OverVBat_ASICGDI, 0);
   VEMS_vidSET(Dena_scp_CTP2, 0);
   VEMS_vidSET(Dft_scp_CTP2, 0);
   VEMS_vidSET(Dena_scg_CTP2, 0);
   VEMS_vidSET(Dft_scg_CTP2, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalCtlPmpReq                            */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the oil pump solenoid valve.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_CtlPmpReq;                                         */
/*  output boolean Dft_oc_CtlPmpReq;                                          */
/*  output boolean Dena_scg_CtlPmpReq;                                        */
/*  output boolean Dft_scg_CtlPmpReq;                                         */
/*  output boolean Dena_scp_CtlPmpReq;                                        */
/*  output boolean Dft_scp_CtlPmpReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalCtlPmpReq(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtCTLPMPVLV);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_CtlPmpReq, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_CtlPmpReq, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_CtlPmpReq, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_CtlPmpReq, 0);
      VEMS_vidSET(Dft_oc_CtlPmpReq, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_CtlPmpReq, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_CtlPmpReq, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_CtlPmpReq, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_CtlPmpReq, 0);
      VEMS_vidSET(Dft_scg_CtlPmpReq, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_CtlPmpReq, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_CtlPmpReq, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_CtlPmpReq, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_CtlPmpReq, 0);
      VEMS_vidSET(Dft_scp_CtlPmpReq, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalCmdWgc                               */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the wastegate command.                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_WgcCmd;                                            */
/*  output boolean Dft_oc_WgcCmd;                                             */
/*  output boolean Dena_scg_WgcCmd;                                           */
/*  output boolean Dft_scg_WgcCmd;                                            */
/*  output boolean Dena_scp_WgcCmd;                                           */
/*  output boolean Dft_scp_WgcCmd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalCmdWgc(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtWASTE_GATE);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_WgcCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_WgcCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_WgcCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_WgcCmd, 0);
      VEMS_vidSET(Dft_oc_WgcCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_WgcCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_WgcCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_WgcCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_WgcCmd, 0);
      VEMS_vidSET(Dft_scg_WgcCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_WgcCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_WgcCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_WgcCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_WgcCmd, 0);
      VEMS_vidSET(Dft_scp_WgcCmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalDmpVlvCmd                            */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the dump-valve command.                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_DmpVlvCmd;                                         */
/*  output boolean Dft_oc_DmpVlvCmd;                                          */
/*  output boolean Dena_scg_DmpVlvCmd;                                        */
/*  output boolean Dft_scg_DmpVlvCmd;                                         */
/*  output boolean Dena_scp_DmpVlvCmd;                                        */
/*  output boolean Dft_scp_DmpVlvCmd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalDmpVlvCmd(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtDUMP_VALVE);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_DmpVlvCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_DmpVlvCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_DmpVlvCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_DmpVlvCmd, 0);
      VEMS_vidSET(Dft_oc_DmpVlvCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_DmpVlvCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_DmpVlvCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_DmpVlvCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_DmpVlvCmd, 0);
      VEMS_vidSET(Dft_scg_DmpVlvCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_DmpVlvCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_DmpVlvCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_DmpVlvCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_DmpVlvCmd, 0);
      VEMS_vidSET(Dft_scp_DmpVlvCmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHlHPPmpActCmd                           */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the HP fuel pump command.                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_HPPmpActCmd;                                       */
/*  output boolean Dft_oc_HPPmpActCmd;                                        */
/*  output boolean Dena_scg_HPPmpActCmd;                                      */
/*  output boolean Dft_scg_HPPmpActCmd;                                       */
/*  output boolean Dena_scp_HPPmpActCmd;                                      */
/*  output boolean Dft_scp_HPPmpActCmd;                                       */
/*  output boolean Dena_ovld_HPPmpActCmd;                                     */
/*  output boolean Dft_ovld_HPPmpActCmd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHlHPPmpActCmd(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtPUMP_HP);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_HPPmpActCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_HPPmpActCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_HPPmpActCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_HPPmpActCmd, 0);
      VEMS_vidSET(Dft_oc_HPPmpActCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_HPPmpActCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_HPPmpActCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_HPPmpActCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_HPPmpActCmd, 0);
      VEMS_vidSET(Dft_scg_HPPmpActCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_HPPmpActCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_HPPmpActCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_HPPmpActCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_HPPmpActCmd, 0);
      VEMS_vidSET(Dft_scp_HPPmpActCmd, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OVERLOAD) != 0)
   {
      VEMS_vidSET(Dena_ovld_HPPmpActCmd, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OVERLOAD) != 0)
      {
         VEMS_vidSET(Dft_ovld_HPPmpActCmd, 1);
      }
      else
      {
         VEMS_vidSET(Dft_ovld_HPPmpActCmd, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_ovld_HPPmpActCmd, 0);
      VEMS_vidSET(Dft_ovld_HPPmpActCmd, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalTrbWaPmp                             */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the turbo cooling pump command.                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_TrbWaPmp;                                          */
/*  output boolean Dft_oc_TrbWaPmp;                                           */
/*  output boolean Dena_scg_TrbWaPmp;                                         */
/*  output boolean Dft_scg_TrbWaPmp;                                          */
/*  output boolean Dena_scp_TrbWaPmp;                                         */
/*  output boolean Dft_scp_TrbWaPmp;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalTrbWaPmp(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtWATER_PUMP_COMMAND);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_TrbWaPmp, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_TrbWaPmp, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_TrbWaPmp, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_TrbWaPmp, 0);
      VEMS_vidSET(Dft_oc_TrbWaPmp, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_TrbWaPmp, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_TrbWaPmp, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_TrbWaPmp, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_TrbWaPmp, 0);
      VEMS_vidSET(Dft_scg_TrbWaPmp, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_TrbWaPmp, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_TrbWaPmp, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_TrbWaPmp, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_TrbWaPmp, 0);
      VEMS_vidSET(Dft_scp_TrbWaPmp, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalCTP                                  */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the CTP components.                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_CTP1;                                              */
/*  output boolean Dft_oc_CTP1;                                               */
/*  output boolean Dena_scg_CTP1;                                             */
/*  output boolean Dft_scg_CTP1;                                              */
/*  output boolean Dena_scp_CTP1;                                             */
/*  output boolean Dft_scp_CTP1;                                              */
/*  output boolean Dena_oc_CTP2;                                              */
/*  output boolean Dft_oc_CTP2;                                               */
/*  output boolean Dena_scg_CTP2;                                             */
/*  output boolean Dft_scg_CTP2;                                              */
/*  output boolean Dena_scp_CTP2;                                             */
/*  output boolean Dft_scp_CTP2;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalCTP(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtHEATER_CTP_1);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_CTP1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_CTP1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_CTP1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_CTP1, 0);
      VEMS_vidSET(Dft_oc_CTP1, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_CTP1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_CTP1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_CTP1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_CTP1, 0);
      VEMS_vidSET(Dft_scg_CTP1, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_CTP1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_CTP1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_CTP1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_CTP1, 0);
      VEMS_vidSET(Dft_scp_CTP1, 0);
   }

   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtHEATER_CTP_2);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_CTP2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_CTP2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_CTP2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_CTP2, 0);
      VEMS_vidSET(Dft_oc_CTP2, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_CTP2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_CTP2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_CTP2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_CTP2, 0);
      VEMS_vidSET(Dft_scg_CTP2, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_CTP2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_CTP2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_CTP2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_CTP2, 0);
      VEMS_vidSET(Dft_scp_CTP2, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalASICGDI                              */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the ASIC GDI and VBOOST components.            */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_OverVBat_ASICGDI;                                     */
/*  output boolean Dft_OverVBat_ASICGDI;                                      */
/*  output boolean Dena_UnderVBat_ASICGDI;                                    */
/*  output boolean Dft_UnderVBat_ASICGDI;                                     */
/*  output boolean Dena_ComSpi_ASICGDI;                                       */
/*  output boolean Dft_ComSpi_ASICGDI;                                        */
/*  output boolean Dena_OverVBoost_ASICGDI;                                   */
/*  output boolean Dft_OverVBoost_ASICGDI;                                    */
/*  output boolean Dena_UnderVBoost_ASICGDI;                                  */
/*  output boolean Dft_UnderVBoost_ASICGDI;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalASICGDI(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtASIC_GDI);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_VBAT_OVER_VOLTAGE) != 0)
   {
      VEMS_vidSET(Dena_OverVBat_ASICGDI, 1);
      if (( bfLocalFault
          & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_VBAT_OVER_VOLTAGE) != 0)
      {
         VEMS_vidSET(Dft_OverVBat_ASICGDI, 1);
      }
      else
      {
         VEMS_vidSET(Dft_OverVBat_ASICGDI, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_OverVBat_ASICGDI, 0);
      VEMS_vidSET(Dft_OverVBat_ASICGDI, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_VBAT_UNDER_VOLT) != 0)
   {
      VEMS_vidSET(Dena_UnderVBat_ASICGDI, 1);
      if (( bfLocalFault
          & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_VBAT_UNDER_VOLT) != 0)
      {
         VEMS_vidSET(Dft_UnderVBat_ASICGDI, 1);
      }
      else
      {
         VEMS_vidSET(Dft_UnderVBat_ASICGDI, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_UnderVBat_ASICGDI, 0);
      VEMS_vidSET(Dft_UnderVBat_ASICGDI, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SPI_FAILURE) != 0)
   {
      VEMS_vidSET(Dena_ComSpi_ASICGDI, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SPI_FAILURE) != 0)
      {
         VEMS_vidSET(Dft_ComSpi_ASICGDI, 1);
      }
      else
      {
         VEMS_vidSET(Dft_ComSpi_ASICGDI, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_ComSpi_ASICGDI, 0);
      VEMS_vidSET(Dft_ComSpi_ASICGDI, 0);
   }

   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtVBOOST);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_VBOOST_OVER_VOLT) != 0)
   {
      VEMS_vidSET(Dena_OverVBoost_ASICGDI, 1);
      if (( bfLocalFault
          & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_VBOOST_OVER_VOLT) != 0)
      {
         VEMS_vidSET(Dft_OverVBoost_ASICGDI, 1);
      }
      else
      {
         VEMS_vidSET(Dft_OverVBoost_ASICGDI, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_OverVBoost_ASICGDI, 0);
      VEMS_vidSET(Dft_OverVBoost_ASICGDI, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_VBOOST_UNDER_VOLT) != 0)
   {
      VEMS_vidSET(Dena_UnderVBoost_ASICGDI, 1);
      if (( bfLocalFault
          & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_VBOOST_UNDER_VOLT) != 0)
      {
         VEMS_vidSET(Dft_UnderVBoost_ASICGDI, 1);
      }
      else
      {
         VEMS_vidSET(Dft_UnderVBoost_ASICGDI, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_UnderVBoost_ASICGDI, 0);
      VEMS_vidSET(Dft_UnderVBoost_ASICGDI, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_DT_vidDgoHalOilLvlAcq                            */
/* !Description :  This block realizes the acquisition of diagnoses states and*/
/*                 results for the oil level acquisition.                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_OilLvlAcq;                                         */
/*  output boolean Dft_oc_OilLvlAcq;                                          */
/*  output boolean Dena_scg_OilLvlAcq;                                        */
/*  output boolean Dft_scg_OilLvlAcq;                                         */
/*  output boolean Dena_scp_OilLvlAcq;                                        */
/*  output boolean Dft_scp_OilLvlAcq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_DT_vidDgoHalOilLvlAcq(void)
{
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtOILLVHAL);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_OilLvlAcq, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_OilLvlAcq, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_OilLvlAcq, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_OilLvlAcq, 0);
      VEMS_vidSET(Dft_oc_OilLvlAcq, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_OilLvlAcq, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_OilLvlAcq, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_OilLvlAcq, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_OilLvlAcq, 0);
      VEMS_vidSET(Dft_scg_OilLvlAcq, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_OilLvlAcq, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_OilLvlAcq, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_OilLvlAcq, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_OilLvlAcq, 0);
      VEMS_vidSET(Dft_scp_OilLvlAcq, 0);
   }
}
/*------------------------------- end of file --------------------------------*/