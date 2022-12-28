/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AVRMISFCNT                                              */
/* !Description     : AVRMISFCNT component.                                   */
/*                                                                            */
/* !Module          : AVRMISFCNT                                              */
/* !Description     : MISFIRE COUNTER FOR OBD MODE$6                          */
/*                                                                            */
/* !File            : AVRMISFCNT_FCT2.C                                       */
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
/*   1 / AVRMISFCNT_vidNumMisfirePerCycle                                     */
/*   2 / AVRMISFCNT_vidEWMA_MisfireCalc                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 05583 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/MISF/AVRMISFCNT/AVRMISFCNT_FCT2.$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   22 Feb 2012 $*/
/* $Author::   etsasson                               $$Date::   22 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AVRMISFCNT.h"
#include "AVRMISFCNT_L.h"
#include "AVRMISFCNT_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidNumMisfirePerCycle                           */
/* !Description :  The total number of detected misfires during the current   */
/*                 cycle is refreshed every misfire.                          */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 MonMisf_ctOccurMfDCCyl1_Raw;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl2_Raw;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl3_Raw;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl4_Raw;                                 */
/*  output uint16 MonMisf_ctOccurMfDCCyl1;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl1_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl2;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl2_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl3;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl3_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl4;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl4_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidNumMisfirePerCycle(void)
{
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl1, MonMisf_ctOccurMfDCCyl1_Raw);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl2, MonMisf_ctOccurMfDCCyl2_Raw);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl3, MonMisf_ctOccurMfDCCyl3_Raw);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl4, MonMisf_ctOccurMfDCCyl4_Raw);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidEWMA_MisfireCalc                             */
/* !Description :   In this part, an exponential weighting moving average of  */
/*                 misfires occurring is calculated for each cylinder for the */
/*                 last driving cycles.                                       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 MonMisf_ctOccurMfDCCyl1;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl2;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl3;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl4;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl1_eep;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl2_eep;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl3_eep;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl4_eep;                                 */
/*  input uint8 MonMisf_facEWMACyl_C;                                         */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl1;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl2;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl3;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl4;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidEWMA_MisfireCalc(void)
{
   uint16 u16LocalMonMisfOccurMfDCCyl_1;
   uint16 u16LocalMonMisfOccurMfDCCyl_2;
   uint16 u16LocalMonMisfOccurMfDCCyl_3;
   uint16 u16LocalMonMisfOccurMfDCCyl_4;
   uint16 u16LocalMMisfOccMfAvg10DCCyl_1;
   uint16 u16LocalMMisfOccMfAvg10DCCyl_2;
   uint16 u16LocalMMisfOccMfAvg10DCCyl_3;
   uint16 u16LocalMMisfOccMfAvg10DCCyl_4;
   uint16 u16LocalMonMisfOccurMfDCCy1_eep;
   uint16 u16LocalMonMisfOccurMfDCCy2_eep;
   uint16 u16LocalMonMisfOccurMfDCCy3_eep;
   uint16 u16LocalMonMisfOccurMfDCCy4_eep;
   sint32 s32LocalVar1;
   sint32 s32LocalVar2;
   sint32 s32LocalVar3;
   sint32 s32LocalVar4;


   VEMS_vidGET(MonMisf_ctOccurMfDCCyl1, u16LocalMonMisfOccurMfDCCyl_1);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl2, u16LocalMonMisfOccurMfDCCyl_2);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl3, u16LocalMonMisfOccurMfDCCyl_3);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl4, u16LocalMonMisfOccurMfDCCyl_4);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl1_eep, u16LocalMonMisfOccurMfDCCy1_eep);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl2_eep, u16LocalMonMisfOccurMfDCCy2_eep);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl3_eep, u16LocalMonMisfOccurMfDCCy3_eep);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl4_eep, u16LocalMonMisfOccurMfDCCy4_eep);

   s32LocalVar1 =
      (sint32)(  (  (u16LocalMonMisfOccurMfDCCyl_1 * MonMisf_facEWMACyl_C)
                 +  ( u16LocalMonMisfOccurMfDCCy1_eep
                    * (128 - MonMisf_facEWMACyl_C)) + 64)
              / 128);
   u16LocalMMisfOccMfAvg10DCCyl_1 =
      (uint16)MATHSRV_udtCLAMP(s32LocalVar1, 0, 65535);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl1, u16LocalMMisfOccMfAvg10DCCyl_1);

   s32LocalVar2 =
      (sint32)(  (  (u16LocalMonMisfOccurMfDCCyl_2 * MonMisf_facEWMACyl_C)
                 +  ( u16LocalMonMisfOccurMfDCCy2_eep
                    * (128 - MonMisf_facEWMACyl_C))
                 + 64)
              / 128);
   u16LocalMMisfOccMfAvg10DCCyl_2 =
      (uint16)MATHSRV_udtCLAMP(s32LocalVar2, 0, 65535);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl2, u16LocalMMisfOccMfAvg10DCCyl_2);

   s32LocalVar3 =
      (sint32)(  (  (u16LocalMonMisfOccurMfDCCyl_3 * MonMisf_facEWMACyl_C)
                 +  ( u16LocalMonMisfOccurMfDCCy3_eep
                    * (128 - MonMisf_facEWMACyl_C))
                 + 64)
              / 128);
   u16LocalMMisfOccMfAvg10DCCyl_3 =
      (uint16)MATHSRV_udtCLAMP(s32LocalVar3, 0, 65535);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl3, u16LocalMMisfOccMfAvg10DCCyl_3);

   s32LocalVar4 =
      (sint32)(  (  (u16LocalMonMisfOccurMfDCCyl_4 * MonMisf_facEWMACyl_C)
                 +  ( u16LocalMonMisfOccurMfDCCy4_eep
                    * (128 - MonMisf_facEWMACyl_C))
                 + 64)
              / 128);
   u16LocalMMisfOccMfAvg10DCCyl_4 =
      (uint16)MATHSRV_udtCLAMP(s32LocalVar4, 0, 65535);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl4, u16LocalMMisfOccMfAvg10DCCyl_4);
}
/*------------------------------- end of file --------------------------------*/