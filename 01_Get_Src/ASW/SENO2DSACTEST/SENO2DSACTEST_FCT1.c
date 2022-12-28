/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2DSACTEST                                           */
/* !Description     : SENO2DSACTEST Component                                 */
/*                                                                            */
/* !Module          : SENO2DSACTEST                                           */
/* !Description     : TEST ACTIONNEUR  SONDE O2 AVAL                          */
/*                                                                            */
/* !File            : SENO2DSACTEST_FCT1.C                                    */
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
/*   1 / SENO2DSACTEST_vidInitOutput                                          */
/*   2 / SENO2DSACTEST_vidSO2DsTst                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 01049 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HeatSenO2/SENO2DSACTEST/SENO2DSA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SENO2DSACTEST.h"
#include "SENO2DSACTEST_L.h"
#include "SENO2DSACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DSACTEST_vidInitOutput                                */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01049_003.01                                     */
/*                 VEMS_R_09_01049_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st55 SO2Ds_stActrTst;                                              */
/*  output boolean HeatSenO2_bDsTstCmd;                                       */
/*  output boolean HeatSenO2_bDsPwrRlyCmd;                                    */
/*  output boolean HeatSenO2_bDsTstCmpl;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DSACTEST_vidInitOutput(void)
{
   SO2Ds_stActrTst = SO2Ds_ACTRTEST_IDLE;
   VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
   VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
   VEMS_vidSET(HeatSenO2_bDsTstCmpl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DSACTEST_vidSO2DsTst                                  */
/* !Description :  Déroulement des tests actionneurs  de la sonde aval        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01049_003.01                                     */
/*                 VEMS_R_09_01049_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input st55 SO2Ds_stActrTst;                                               */
/*  input uint32 ActrTstSO2Ds_TotTime;                                        */
/*  input uint16 ActrTstSO2Ds_OffTime;                                        */
/*  input uint32 ActrTstSO2Ds_CumulTime;                                      */
/*  input uint16 ActrTstSO2Ds_IntTime;                                        */
/*  input uint32 ActrTstSO2_DsTempo_C;                                        */
/*  input uint16 ActrTstSO2Ds_OnTime;                                         */
/*  input uint32 ActrTstSO2_DsTempo;                                          */
/*  output uint32 ActrTstSO2Ds_CumulTime;                                     */
/*  output st55 SO2Ds_stActrTst;                                              */
/*  output boolean HeatSenO2_bDsTstCmd;                                       */
/*  output boolean HeatSenO2_bDsPwrRlyCmd;                                    */
/*  output uint16 ActrTstSO2Ds_IntTime;                                       */
/*  output boolean HeatSenO2_bDsTstCmpl;                                      */
/*  output uint32 ActrTstSO2_DsTempo;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DSACTEST_vidSO2DsTst(void)
{
   boolean  bLocalSrv_bActrTstEna;
   boolean  bLocalTestEna;
   uint8    u8LocalCode_test_action;
   uint16   u16LocalActrTstSO2Ds_IntTime;
   uint32   u32LocalActrTstSO2Ds_CumulTime;
   uint32   u32LocalActrTstSO2_DsTempo;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_SO2_AV))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }

   switch (SO2Ds_stActrTst)
   {
      case SO2Ds_ACTRTEST_IDLE:
         if (bLocalTestEna != 0)
         {
            ActrTstSO2Ds_CumulTime =
               MATHSRV_udtMIN(ActrTstSO2Ds_TotTime, 120000);
            SO2Ds_stActrTst = SO2Ds_ACTRTEST_OFF;
            VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
            ActrTstSO2Ds_IntTime = (uint16)MATHSRV_udtMIN(ActrTstSO2Ds_OffTime,
                                                         400);
         }
         else
         {
            ActrTstSO2Ds_CumulTime =
               MATHSRV_udtMIN(ActrTstSO2Ds_CumulTime, 120000);
            ActrTstSO2Ds_IntTime = (uint16)MATHSRV_udtMIN(ActrTstSO2Ds_IntTime,
                                                         400);
         }
         break;

      case SO2Ds_ACTRTEST_OFF:
         if (bLocalTestEna == 0)
         {
            SO2Ds_stActrTst = SO2Ds_ACTRTEST_IDLE;
            VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsTstCmpl, 0);
         }
         else
         {
            if (ActrTstSO2Ds_CumulTime <= 1)
            {
               SO2Ds_stActrTst = SO2Ds_ACTRTEST_END;
               VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
               VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
               VEMS_vidSET(HeatSenO2_bDsTstCmpl, 1);
               ActrTstSO2_DsTempo =
                  MATHSRV_udtMIN(ActrTstSO2_DsTempo_C, 120000);
            }
            else
            {
               if (ActrTstSO2Ds_IntTime <= 1)
               {
                  SO2Ds_stActrTst = SO2Ds_ACTRTEST_ON;
                  VEMS_vidSET(HeatSenO2_bDsTstCmd, 1);
                  VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 1);
                  ActrTstSO2Ds_IntTime =
                     (uint16)MATHSRV_udtMIN(ActrTstSO2Ds_OnTime, 400);
               }
               else
               {
                  u16LocalActrTstSO2Ds_IntTime = (uint16)( ActrTstSO2Ds_IntTime
                                                         - 1);
                  ActrTstSO2Ds_IntTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstSO2Ds_IntTime, 400);
               }
               u32LocalActrTstSO2Ds_CumulTime = (ActrTstSO2Ds_CumulTime - 1);
               ActrTstSO2Ds_CumulTime =
                  MATHSRV_udtMIN(u32LocalActrTstSO2Ds_CumulTime, 120000);
            }
         }
         break;

      case SO2Ds_ACTRTEST_ON:
         if (bLocalTestEna == 0)
         {
            SO2Ds_stActrTst = SO2Ds_ACTRTEST_IDLE;
            VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsTstCmpl, 0);
         }
         else
         {
            if (ActrTstSO2Ds_CumulTime <= 1)
            {
               SO2Ds_stActrTst = SO2Ds_ACTRTEST_END;
               VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
               VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
               VEMS_vidSET(HeatSenO2_bDsTstCmpl, 1);
               ActrTstSO2_DsTempo =
                  MATHSRV_udtMIN(ActrTstSO2_DsTempo_C, 120000);
            }
            else
            {
               if (ActrTstSO2Ds_IntTime <= 1)
               {
                  SO2Ds_stActrTst = SO2Ds_ACTRTEST_OFF;
                  VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
                  VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
                  ActrTstSO2Ds_IntTime =
                     (uint16)MATHSRV_udtMIN(ActrTstSO2Ds_OffTime, 400);
               }
               else
               {
                  u16LocalActrTstSO2Ds_IntTime = (uint16)( ActrTstSO2Ds_IntTime
                                                         - 1);
                  ActrTstSO2Ds_IntTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstSO2Ds_IntTime, 400);
               }
               u32LocalActrTstSO2Ds_CumulTime = (ActrTstSO2Ds_CumulTime - 1);
               ActrTstSO2Ds_CumulTime =
                  MATHSRV_udtMIN(u32LocalActrTstSO2Ds_CumulTime, 120000);
            }
         }
         break;

      case SO2Ds_ACTRTEST_END:
         if ((bLocalTestEna != 0) && (ActrTstSO2_DsTempo == 0))
         {
            SO2Ds_stActrTst = SO2Ds_ACTRTEST_IDLE;
            VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
            VEMS_vidSET(HeatSenO2_bDsTstCmpl, 0);
         }
         else
         {
            if(ActrTstSO2_DsTempo > 0)
            {
               u32LocalActrTstSO2_DsTempo = (ActrTstSO2_DsTempo - 1);
               ActrTstSO2_DsTempo =
                  MATHSRV_udtMIN(u32LocalActrTstSO2_DsTempo, 120000);
            }
         }
         break;

      default:
         SO2Ds_stActrTst = SO2Ds_ACTRTEST_IDLE;
         VEMS_vidSET(HeatSenO2_bDsTstCmd, 0);
         VEMS_vidSET(HeatSenO2_bDsPwrRlyCmd, 0);
         VEMS_vidSET(HeatSenO2_bDsTstCmpl, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*--------------------------------- end of file ------------------------------*/