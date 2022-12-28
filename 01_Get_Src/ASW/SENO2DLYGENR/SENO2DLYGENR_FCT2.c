/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SENO2DLYGENR                                            */
/* !Description     : SENO2DLYGENR Component                                  */
/*                                                                            */
/* !Module          : SENO2DLYGENR                                            */
/* !Description     : TEST BED MODE FOR THE UPSTREAM OXYGEN SENSOR VOLTAGE    */
/*                                                                            */
/* !File            : SENO2DLYGENR_FCT2.C                                     */
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
/*   1 / SENO2DLYGENR_vidLeanRichInit                                         */
/*   2 / SENO2DLYGENR_vidRichLeanInit                                         */
/*   3 / SENO2DLYGENR_vidRichStatus                                           */
/*   4 / SENO2DLYGENR_vidLeanStatus                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 06150 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SENO2DLYGENR/SENO2DLYGENR_FCT2.C_v$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   15 Dec 2010 $*/
/* $Author::   wbouach                                $$Date::   15 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SENO2DLYGENR.h"
#include "SENO2DLYGENR_L.h"
#include "SENO2DLYGENR_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidLeanRichInit                               */
/* !Description :  trasition from lean to rich                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 Up_oxy_tb_lean_vs_rich_delay_c0;                             */
/*  output uint32 Up_oxy_tb_lean_vs_rich_count_v;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidLeanRichInit(void)
{
   Up_oxy_tb_lean_vs_rich_count_v =
      MATHSRV_udtMIN(Up_oxy_tb_lean_vs_rich_delay_c0, 204000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidRichLeanInit                               */
/* !Description :  transition from rich to lean                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 Up_oxy_tb_rich_vs_lean_delay_c0;                             */
/*  output uint32 Up_oxy_tb_rich_vs_lean_count_v;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidRichLeanInit(void)
{
   Up_oxy_tb_rich_vs_lean_count_v =
      MATHSRV_udtMIN(Up_oxy_tb_rich_vs_lean_delay_c0, 204000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidRichStatus                                 */
/* !Description :  function of rich status                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Up_oxy_tb_rich_voltage_value_c0;                             */
/*  output uint16 Up_oxy_test_bed_voltage_v;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidRichStatus(void)
{
   uint16 u16LocalUpOxyTestBedVoltageV;


   u16LocalUpOxyTestBedVoltageV =
      (uint16)MATHSRV_udtMIN(Up_oxy_tb_rich_voltage_value_c0, 1023);
   VEMS_vidSET(Up_oxy_test_bed_voltage_v, u16LocalUpOxyTestBedVoltageV);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SENO2DLYGENR_vidLeanStatus                                 */
/* !Description :  function of Lean status                                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  BKBO                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Up_oxy_tb_lean_voltage_value_c0;                             */
/*  output uint16 Up_oxy_test_bed_voltage_v;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SENO2DLYGENR_vidLeanStatus(void)
{
   uint16   u16LocalUpOxyTestBedVoltageV;


   u16LocalUpOxyTestBedVoltageV =
      (uint16)MATHSRV_udtMIN(Up_oxy_tb_lean_voltage_value_c0, 1023);
   VEMS_vidSET(Up_oxy_test_bed_voltage_v, u16LocalUpOxyTestBedVoltageV);
}

/*------------------------------- end of file --------------------------------*/