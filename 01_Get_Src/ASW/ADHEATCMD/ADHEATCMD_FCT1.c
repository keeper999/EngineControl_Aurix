/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADHEATCMD                                               */
/* !Description     : ADHEATCMD Component                                     */
/*                                                                            */
/* !Module          : ADHEATCMD                                               */
/* !Description     : CTP additional heaters command and diagnosis            */
/*                                                                            */
/* !File            : ADHEATCMD_FCT1.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / ADHEATCMD_vidInit                                                    */
/*   2 / ADHEATCMD_vidAdHeatCmdCalc                                           */
/*   3 / ADHEATCMD_vidCmdCTP1                                                 */
/*   4 / ADHEATCMD_vidCmdCTP2                                                 */
/*   5 / ADHEATCMD_vidDiagCTP1                                                */
/*   6 / ADHEATCMD_vidDiagCTP2                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6851368 / 01                                        */
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
#include "ADHEATCMD.h"
#include "ADHEATCMD_L.h"
#include "ADHEATCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADHEATCMD_vidInit                                          */
/* !Description :  The outputs variables are initialized on reset event.      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean AdHeatCmd_bAcvCTP1;                                        */
/*  output boolean AdHeatCmd_bAcvCTP2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADHEATCMD_vidInit(void)
{
   VEMS_vidSET(AdHeatCmd_bAcvCTP1, 0);
   VEMS_vidSET(AdHeatCmd_bAcvCTP2, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADHEATCMD_vidAdHeatCmdCalc                                 */
/* !Description :  According to the different values of the CAN parameter     */
/*                 CoReqVeh_stAdHeat the activation request flags are set to 1*/
/*                 or not.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoReqVeh_stAdHeat;                                            */
/*  output boolean AdHeatCmd_bAcvCTP1;                                        */
/*  output boolean AdHeatCmd_bAcvCTP2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADHEATCMD_vidAdHeatCmdCalc(void)
{
   uint8  u8LocalCoReqVehstAdHeat;


   VEMS_vidGET(CoReqVeh_stAdHeat, u8LocalCoReqVehstAdHeat);
   switch(u8LocalCoReqVehstAdHeat)
   {
      case 1:
         VEMS_vidSET(AdHeatCmd_bAcvCTP1, 1);
         VEMS_vidSET(AdHeatCmd_bAcvCTP2, 0);
         break;
      case 2:
         VEMS_vidSET(AdHeatCmd_bAcvCTP1, 0);
         VEMS_vidSET(AdHeatCmd_bAcvCTP2, 1);
         break;
      case 3:
         VEMS_vidSET(AdHeatCmd_bAcvCTP1, 1);
         VEMS_vidSET(AdHeatCmd_bAcvCTP2, 1);
         break;
      default:
         VEMS_vidSET(AdHeatCmd_bAcvCTP1, 0);
         VEMS_vidSET(AdHeatCmd_bAcvCTP2, 0);
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADHEATCMD_vidCmdCTP1                                       */
/* !Description :  The activation command of the CTP1 additional heater is    */
/*                 sent to the BSW using a DIOHAL API.                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CTP_bAcvCTP1ActrTstReq;                                     */
/*  input boolean CTP_bActrTstInProgs;                                        */
/*  input boolean AdHeatCmd_bAcvCTP1;                                         */
/*  input boolean AdHeatCmd_bInvReq_C;                                        */
/*  output boolean AdHeatCmd_bAcvCTP1Drv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADHEATCMD_vidCmdCTP1(void)
{
   boolean  bLocalAcvCTP1ActrTstReq;
   boolean  bLocalActrTstInProgs;
   boolean  bLocalAdHeatCmdAcvCTP1;
   boolean  bLocalSwitch1;
   boolean  bLocalAdHeatCmd_bAcvCTP1Drv;


   VEMS_vidGET(CTP_bAcvCTP1ActrTstReq, bLocalAcvCTP1ActrTstReq);
   VEMS_vidGET(CTP_bActrTstInProgs, bLocalActrTstInProgs);
   VEMS_vidGET(AdHeatCmd_bAcvCTP1, bLocalAdHeatCmdAcvCTP1);
   if (bLocalActrTstInProgs != 0)
   {
      bLocalSwitch1 = bLocalAcvCTP1ActrTstReq;
   }
   else
   {
      bLocalSwitch1 = bLocalAdHeatCmdAcvCTP1;
   }

   if (AdHeatCmd_bInvReq_C != 0)
   {
      bLocalAdHeatCmd_bAcvCTP1Drv = !bLocalSwitch1;
   }
   else
   {
      bLocalAdHeatCmd_bAcvCTP1Drv = bLocalSwitch1;
   }
   VEMS_vidSET(AdHeatCmd_bAcvCTP1Drv, bLocalAdHeatCmd_bAcvCTP1Drv);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADHEATCMD_vidCmdCTP2                                       */
/* !Description :  The activation command of the CTP2 additional heater is    */
/*                 sent to the BSW using a DIOHAL API.                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CTP_bAcvCTP2ActrTstReq;                                     */
/*  input boolean CTP_bActrTstInProgs;                                        */
/*  input boolean AdHeatCmd_bAcvCTP2;                                         */
/*  input boolean AdHeatCmd_bInvReq_C;                                        */
/*  output boolean AdHeatCmd_bAcvCTP2Drv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADHEATCMD_vidCmdCTP2(void)
{
   boolean  bLocalAcvCTP2ActrTstReq;
   boolean  bLocalActrTstInProgs;
   boolean  bLocalAdHeatCmdAcvCTP2;
   boolean  bLocalSwitch1;
   boolean  bLocalAdHeatCmd_bAcvCTP2Drv;


   VEMS_vidGET(CTP_bAcvCTP2ActrTstReq, bLocalAcvCTP2ActrTstReq);
   VEMS_vidGET(CTP_bActrTstInProgs, bLocalActrTstInProgs);
   VEMS_vidGET(AdHeatCmd_bAcvCTP2, bLocalAdHeatCmdAcvCTP2);
   if (bLocalActrTstInProgs != 0)
   {
      bLocalSwitch1 = bLocalAcvCTP2ActrTstReq;
   }
   else
   {
      bLocalSwitch1 = bLocalAdHeatCmdAcvCTP2;
   }

   if (AdHeatCmd_bInvReq_C != 0)
   {
      bLocalAdHeatCmd_bAcvCTP2Drv = !bLocalSwitch1;
   }
   else
   {
      bLocalAdHeatCmd_bAcvCTP2Drv = bLocalSwitch1;
   }
   VEMS_vidSET(AdHeatCmd_bAcvCTP2Drv, bLocalAdHeatCmd_bAcvCTP2Drv);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADHEATCMD_vidDiagCTP1                                      */
/* !Description :  This bloc manages with the electrical diagnoses of the     */
/*                 CTP1. The diagnoses are activated only if there is no      */
/*                 inhibition requested.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AdHeatCmd_bAcvCTP1;                                         */
/*  input boolean Dft_oc_CTP1;                                                */
/*  input boolean Dft_scg_CTP1;                                               */
/*  input boolean Dft_scp_CTP1;                                               */
/*  input boolean Dena_oc_CTP1;                                               */
/*  input boolean Dena_scg_CTP1;                                              */
/*  input boolean Dena_scp_CTP1;                                              */
/*  output boolean AC_bMonRunOc_CTP1;                                         */
/*  output boolean AC_bDgoOc_CTP1;                                            */
/*  output boolean AC_bMonRunScg_CTP1;                                        */
/*  output boolean AC_bDgoScg_CTP1;                                           */
/*  output boolean AC_bMonRunScp_CTP1;                                        */
/*  output boolean AC_bDgoScp_CTP1;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADHEATCMD_vidDiagCTP1(void)
{
   boolean          bLocalInhDiag_AdHeatCmd;
   boolean          bLocalDft_oc_CTP1;
   boolean          bLocalDft_scg_CTP1;
   boolean          bLocalDft_scp_CTP1;
   boolean          bLocalDena_oc_CTP1;
   boolean          bLocalDena_scg_CTP1;
   boolean          bLocalDena_scp_CTP1;
   boolean          bLocalAdHeatCmd_bAcvCTP1;


   bLocalInhDiag_AdHeatCmd = GDGAR_bGetFRM(FRM_FRM_INHDIAG_ADHEATCMD);
   VEMS_vidGET(AdHeatCmd_bAcvCTP1, bLocalAdHeatCmd_bAcvCTP1);
   VEMS_vidGET(Dft_oc_CTP1, bLocalDft_oc_CTP1);
   VEMS_vidGET(Dft_scg_CTP1, bLocalDft_scg_CTP1);
   VEMS_vidGET(Dft_scp_CTP1, bLocalDft_scp_CTP1);
   VEMS_vidGET(Dena_oc_CTP1, bLocalDena_oc_CTP1);
   VEMS_vidGET(Dena_scg_CTP1, bLocalDena_scg_CTP1);
   VEMS_vidGET(Dena_scp_CTP1, bLocalDena_scp_CTP1);

   if (bLocalInhDiag_AdHeatCmd != 0)
   {
      AC_bMonRunOc_CTP1 = 0;
      AC_bDgoOc_CTP1 = 0;

      AC_bMonRunScg_CTP1 = 0;
      AC_bDgoScg_CTP1 = 0;

      AC_bMonRunScp_CTP1 = 0;
      AC_bDgoScp_CTP1 = 0;
   }
   else
   {
      if (bLocalAdHeatCmd_bAcvCTP1 != 0)
      {
         AC_bMonRunOc_CTP1 = 0;
         AC_bDgoOc_CTP1 = 0;

         AC_bMonRunScg_CTP1 = 0;
         AC_bDgoScg_CTP1 = 0;

         if (bLocalDena_scp_CTP1 != 0)
         {
            AC_bMonRunScp_CTP1 = 1;
            if (bLocalDft_scp_CTP1 != 0)
            {
               AC_bDgoScp_CTP1 = 1;
            }
            else
            {
               AC_bDgoScp_CTP1 = 0;
            }
         }
         else
         {
            AC_bMonRunScp_CTP1 = 0;
            AC_bDgoScp_CTP1 = 0;
         }
      }
      else
      {
         AC_bMonRunScp_CTP1 = 0;
         AC_bDgoScp_CTP1 = 0;
         if (bLocalDena_scg_CTP1 != 0)
         {
            AC_bMonRunScg_CTP1 = 1;
            if (bLocalDft_scg_CTP1 != 0)
            {
               AC_bDgoScg_CTP1 = 1;
            }
            else
            {
               AC_bDgoScg_CTP1 = 0;
            }
         }
         else
         {
            AC_bMonRunScg_CTP1 = 0;
            AC_bDgoScg_CTP1 = 0;
         }
         if (bLocalDena_oc_CTP1 != 0)
         {
            AC_bMonRunOc_CTP1 = 1;
            if (bLocalDft_oc_CTP1 != 0)
            {
               AC_bDgoOc_CTP1 = 1;
            }
            else
            {
               AC_bDgoOc_CTP1 = 0;
            }
         }
         else
         {
            AC_bMonRunOc_CTP1 = 0;
            AC_bDgoOc_CTP1 = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADHEATCMD_vidDiagCTP2                                      */
/* !Description :  This bloc manages with the electrical diagnoses of the     */
/*                 CTP2. The diagnoses are activated only if there is no      */
/*                 inhibition requested.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean AdHeatCmd_bAcvCTP2;                                         */
/*  input boolean Dena_scp_CTP2;                                              */
/*  input boolean Dft_scp_CTP2;                                               */
/*  input boolean Dena_scg_CTP2;                                              */
/*  input boolean Dft_scg_CTP2;                                               */
/*  input boolean Dena_oc_CTP2;                                               */
/*  input boolean Dft_oc_CTP2;                                                */
/*  output boolean AC_bMonRunOc_CTP2;                                         */
/*  output boolean AC_bDgoOc_CTP2;                                            */
/*  output boolean AC_bMonRunScg_CTP2;                                        */
/*  output boolean AC_bDgoScg_CTP2;                                           */
/*  output boolean AC_bMonRunScp_CTP2;                                        */
/*  output boolean AC_bDgoScp_CTP2;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADHEATCMD_vidDiagCTP2(void)
{
   boolean          bLocalInhDiag_AdHeatCmd;
   boolean          bLocalAdHeatCmdAcvCTP2;
   boolean          bLocalDena_scp_CTP2;
   boolean          bLocalDft_scp_CTP2;
   boolean          bLocalDena_scg_CTP2;
   boolean          bLocalDft_scg_CTP2;
   boolean          bLocal_Dena_oc_CTP2;
   boolean          bLocalDft_oc_CTP2;


   bLocalInhDiag_AdHeatCmd = GDGAR_bGetFRM(FRM_FRM_INHDIAG_ADHEATCMD);
   VEMS_vidGET(AdHeatCmd_bAcvCTP2, bLocalAdHeatCmdAcvCTP2);
   VEMS_vidGET(Dena_scp_CTP2, bLocalDena_scp_CTP2);
   VEMS_vidGET(Dft_scp_CTP2, bLocalDft_scp_CTP2);
   VEMS_vidGET(Dena_scg_CTP2, bLocalDena_scg_CTP2);
   VEMS_vidGET(Dft_scg_CTP2, bLocalDft_scg_CTP2);
   VEMS_vidGET(Dena_oc_CTP2, bLocal_Dena_oc_CTP2);
   VEMS_vidGET(Dft_oc_CTP2, bLocalDft_oc_CTP2);

   if (bLocalInhDiag_AdHeatCmd != 0)
   {
      AC_bMonRunOc_CTP2 = 0;
      AC_bDgoOc_CTP2 = 0;

      AC_bMonRunScg_CTP2 = 0;
      AC_bDgoScg_CTP2 = 0;

      AC_bMonRunScp_CTP2 = 0;
      AC_bDgoScp_CTP2 = 0;
   }
   else
   {
      if (bLocalAdHeatCmdAcvCTP2 != 0)
      {
         AC_bMonRunOc_CTP2 = 0;
         AC_bDgoOc_CTP2 = 0;

         AC_bMonRunScg_CTP2 = 0;
         AC_bDgoScg_CTP2 = 0;

         if (bLocalDena_scp_CTP2 != 0)
         {
            AC_bMonRunScp_CTP2 = 1;
            if (bLocalDft_scp_CTP2 != 0)
            {
               AC_bDgoScp_CTP2 = 1;
            }
            else
            {
               AC_bDgoScp_CTP2 = 0;
            }
         }
         else
         {
            AC_bMonRunScp_CTP2 = 0;
            AC_bDgoScp_CTP2 = 0;
         }
      }
      else
      {
         AC_bMonRunScp_CTP2 = 0;
         AC_bDgoScp_CTP2 = 0;
         if (bLocalDena_scg_CTP2 != 0)
         {
            AC_bMonRunScg_CTP2 = 1;
            if (bLocalDft_scg_CTP2 != 0)
            {
               AC_bDgoScg_CTP2 = 1;
            }
            else
            {
               AC_bDgoScg_CTP2 = 0;
            }
         }
         else
         {
            AC_bMonRunScg_CTP2 = 0;
            AC_bDgoScg_CTP2 = 0;
         }
         if (bLocal_Dena_oc_CTP2 != 0)
         {
            AC_bMonRunOc_CTP2 = 1;
            if (bLocalDft_oc_CTP2 != 0)
            {
               AC_bDgoOc_CTP2 = 1;
            }
            else
            {
               AC_bDgoOc_CTP2 = 0;
            }
         }
         else
         {
            AC_bMonRunOc_CTP2 = 0;
            AC_bDgoOc_CTP2 = 0;
         }
      }
   }
}
/*------------------------------end of file-----------------------------------*/