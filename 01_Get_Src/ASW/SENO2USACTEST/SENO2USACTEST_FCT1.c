/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2USACTEST                                           */
/* !Description     : SENO2USACTEST Component                                 */
/*                                                                            */
/* !Module          : SENO2USACTEST                                           */
/* !Description     : TEST ACTIONNEUR  SONDE O2 AMONT                         */
/*                                                                            */
/* !File            : SENO2USACTEST_FCT1.C                                    */
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
/*   1 / SENO2USACTEST_vidInitOutput                                          */
/*   2 / SENO2USACTEST_vidSO2UsTst                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 08131 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HeatSenO2/SENO2USACTEST/SENO2USA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SENO2USACTEST.h"
#include "SENO2USACTEST_L.h"
#include "SENO2USACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2USACTEST_vidInitOutput                                */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_08131_003.01                                     */
/*                 VEMS_R_08_08131_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st53 SO2Us_stActrTst;                                              */
/*  output boolean HeatSenO2_bUsTstCmd;                                       */
/*  output boolean HeatSenO2_bUsPwrRlyCmd;                                    */
/*  output boolean HeatSenO2_bUsTstCmpl;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2USACTEST_vidInitOutput(void)
{
   SO2Us_stActrTst = SO2Us_ACTRTEST_IDLE;
   VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
   VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
   VEMS_vidSET(HeatSenO2_bUsTstCmpl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2USACTEST_vidSO2UsTst                                  */
/* !Description :  Déroulement des tests actionneurs  de la sonde amont       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_08131_003.01                                     */
/*                 VEMS_R_08_08131_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bActrTstEna;                                            */
/*  input st53 SO2Us_stActrTst;                                               */
/*  input uint32 ActrTstSO2Us_TotTime;                                        */
/*  input uint16 ActrTstSO2Us_OffTime;                                        */
/*  input uint32 ActrTstSO2Us_CumulTime;                                      */
/*  input uint16 ActrTstSO2Us_IntTime;                                        */
/*  input uint32 ActrTstSO2_UsTempo_C;                                        */
/*  input uint16 ActrTstSO2Us_OnTime;                                         */
/*  input uint32 ActrTstSO2_UsTempo;                                          */
/*  output uint32 ActrTstSO2Us_CumulTime;                                     */
/*  output st53 SO2Us_stActrTst;                                              */
/*  output boolean HeatSenO2_bUsTstCmd;                                       */
/*  output boolean HeatSenO2_bUsPwrRlyCmd;                                    */
/*  output uint16 ActrTstSO2Us_IntTime;                                       */
/*  output boolean HeatSenO2_bUsTstCmpl;                                      */
/*  output uint32 ActrTstSO2_UsTempo;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2USACTEST_vidSO2UsTst(void)
{
   boolean  bLocalSrv_bActrTstEna;
   boolean  bLocalTestEna;
   uint8    u8LocalCode_test_action;
   uint16   u16LocalActrTstSO2Us_IntTime;
   uint32   u32LocalActrTstSO2Us_CumulTime;
   uint32   u32LocalActrTstSO2_UsTempo;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   VEMS_vidGET(Srv_bActrTstEna, bLocalSrv_bActrTstEna);

   if (  (bLocalSrv_bActrTstEna != 0)
      && (u8LocalCode_test_action == CODE_TEST_SO2_AM))
   {
      bLocalTestEna = 1;
   }
   else
   {
      bLocalTestEna = 0;
   }

   switch (SO2Us_stActrTst)
   {
      case SO2Us_ACTRTEST_IDLE:
         if (bLocalTestEna != 0)
         {
            ActrTstSO2Us_CumulTime =
               MATHSRV_udtMIN(ActrTstSO2Us_TotTime, 120000);
            SO2Us_stActrTst = SO2Us_ACTRTEST_OFF;
            VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
            ActrTstSO2Us_IntTime = (uint16)MATHSRV_udtMIN(ActrTstSO2Us_OffTime,
                                                          400);
         }
         else
         {
            ActrTstSO2Us_CumulTime =
               MATHSRV_udtMIN(ActrTstSO2Us_CumulTime, 120000);
            ActrTstSO2Us_IntTime = (uint16)MATHSRV_udtMIN(ActrTstSO2Us_IntTime,
                                                          400);
         }
         break;

      case SO2Us_ACTRTEST_OFF:
         if (bLocalTestEna == 0)
         {
            SO2Us_stActrTst = SO2Us_ACTRTEST_IDLE;
            VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsTstCmpl, 0);
         }
         else
         {
            if (ActrTstSO2Us_CumulTime <= 1)
            {
               SO2Us_stActrTst = SO2Us_ACTRTEST_END;
               VEMS_vidSET(HeatSenO2_bUsTstCmpl, 1);
               VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
               VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
               ActrTstSO2_UsTempo =
                  MATHSRV_udtMIN(ActrTstSO2_UsTempo_C, 120000);
            }
            else
            {
               if (ActrTstSO2Us_IntTime <= 1)
               {
                  SO2Us_stActrTst = SO2Us_ACTRTEST_ON;
                  VEMS_vidSET(HeatSenO2_bUsTstCmd, 1);
                  VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 1);
                  ActrTstSO2Us_IntTime =
                     (uint16)MATHSRV_udtMIN(ActrTstSO2Us_OnTime, 400);
               }
               else
               {
                  u16LocalActrTstSO2Us_IntTime = (uint16)( ActrTstSO2Us_IntTime
                                                         - 1);
                  ActrTstSO2Us_IntTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstSO2Us_IntTime, 400);
               }
               u32LocalActrTstSO2Us_CumulTime = (ActrTstSO2Us_CumulTime - 1);
               ActrTstSO2Us_CumulTime =
                  MATHSRV_udtMIN(u32LocalActrTstSO2Us_CumulTime, 120000);
            }
         }
         break;

      case SO2Us_ACTRTEST_ON:
         if (bLocalTestEna == 0)
         {
            SO2Us_stActrTst = SO2Us_ACTRTEST_IDLE;
            VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsTstCmpl, 0);
         }
         else
         {
            if (ActrTstSO2Us_CumulTime <= 1)
            {
               SO2Us_stActrTst = SO2Us_ACTRTEST_END;
               VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
               VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
               VEMS_vidSET(HeatSenO2_bUsTstCmpl, 1);
               ActrTstSO2_UsTempo =
                  MATHSRV_udtMIN(ActrTstSO2_UsTempo_C, 120000);
            }
            else
            {
               if (ActrTstSO2Us_IntTime <= 1)
               {
                  SO2Us_stActrTst = SO2Us_ACTRTEST_OFF;
                  VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
                  VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
                  ActrTstSO2Us_IntTime =
                     (uint16)MATHSRV_udtMIN(ActrTstSO2Us_OffTime, 400);
               }
               else
               {
                  u16LocalActrTstSO2Us_IntTime = (uint16)( ActrTstSO2Us_IntTime
                                                         - 1);
                  ActrTstSO2Us_IntTime =
                     (uint16)MATHSRV_udtMIN(u16LocalActrTstSO2Us_IntTime, 400);
               }
               u32LocalActrTstSO2Us_CumulTime = (ActrTstSO2Us_CumulTime - 1);
               ActrTstSO2Us_CumulTime =
                  MATHSRV_udtMIN(u32LocalActrTstSO2Us_CumulTime, 120000);
            }
         }
         break;

      case SO2Us_ACTRTEST_END:
         if ((bLocalTestEna != 0) && (ActrTstSO2_UsTempo == 0))
         {
            SO2Us_stActrTst = SO2Us_ACTRTEST_IDLE;
            VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
            VEMS_vidSET(HeatSenO2_bUsTstCmpl, 0);
         }
         else
         {
            if(ActrTstSO2_UsTempo > 0)
            {
               u32LocalActrTstSO2_UsTempo = (ActrTstSO2_UsTempo - 1);
               ActrTstSO2_UsTempo =
                  MATHSRV_udtMIN(u32LocalActrTstSO2_UsTempo, 120000);
            }
         }
         break;

      default:
         SO2Us_stActrTst = SO2Us_ACTRTEST_IDLE;
         VEMS_vidSET(HeatSenO2_bUsTstCmd, 0);
         VEMS_vidSET(HeatSenO2_bUsPwrRlyCmd, 0);
         VEMS_vidSET(HeatSenO2_bUsTstCmpl, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*--------------------------------- end of file ------------------------------*/