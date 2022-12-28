/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WGACTRTEST                                              */
/* !Description     : WGACTRTEST component.                                   */
/*                                                                            */
/* !Module          : WGACTRTEST                                              */
/* !Description     : WASTE GATE ACTUATOR TEST                                */
/*                                                                            */
/* !File            : WGACTRTEST_FCT2.C                                       */
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
/*   1 / WGACTRTEST_vidTrbDynTest                                             */
/*   2 / WGACTRTEST_vidTrbStabTest                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5621841 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/WG/WGACTRTEST/WGACTRTEST_FCT2.C_$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   14 Oct 2013 $*/
/* $Author::   etsasson                               $$Date::   14 Oct 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "WGACTRTEST.h"
#include "WGACTRTEST_L.h"
#include "WGACTRTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidTrbDynTest                                   */
/* !Description :  Détermine le comportement dynamique du Wastegate une durée */
/*                 après un changement de consigne.                           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Wg_noTrbTestChgtSp;                                           */
/*  input uint8 Wg_tiDlyTestTrbActRise_C;                                     */
/*  input uint8 Wg_tiDlyTestTrbActFall_C;                                     */
/*  input uint8 Wg_tiTrbActPhaDrn;                                            */
/*  input boolean WGACTRTEST_bTrbDrnDynCompPrev;                              */
/*  input uint16 Wg_rOpTrbActrTst;                                            */
/*  input uint16 TrbAct_rOpTrbActTmp;                                         */
/*  input uint16 Wg_rErrTestTrbAct_C;                                         */
/*  output boolean Wg_bDynActrTst;                                            */
/*  output boolean WGACTRTEST_bTrbDrnDynCompPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidTrbDynTest(void)
{
   boolean  bLocalComp;
   uint16   u16LocalActPhaDrnComp;
   uint16   u16LocalWg_rOpTrbActrTst;
   uint32   u32LocalrOpTrbAct;


   switch (Wg_noTrbTestChgtSp)
   {
      case 0:
         u16LocalActPhaDrnComp = 6375;
         break;

      case 1:
         u16LocalActPhaDrnComp = Wg_tiDlyTestTrbActRise_C;
         break;

      case 2:
         u16LocalActPhaDrnComp = Wg_tiDlyTestTrbActFall_C;
         break;

      default:
         u16LocalActPhaDrnComp = Wg_tiDlyTestTrbActFall_C;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if (Wg_tiTrbActPhaDrn >= u16LocalActPhaDrnComp)
   {
      bLocalComp = 1;
   }
   else
   {
      bLocalComp = 0;
   }

   if (  (WGACTRTEST_bTrbDrnDynCompPrev == 0)
      && (bLocalComp != 0))
   {
      VEMS_vidGET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
      u32LocalrOpTrbAct =
             (uint32)MATHSRV_udtABS(u16LocalWg_rOpTrbActrTst
                                   - TrbAct_rOpTrbActTmp);
      if (u32LocalrOpTrbAct >= Wg_rErrTestTrbAct_C)
      {
         VEMS_vidSET(Wg_bDynActrTst, 1);
      }
   }

   WGACTRTEST_bTrbDrnDynCompPrev = bLocalComp;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGACTRTEST_vidTrbStabTest                                  */
/* !Description :  Observe l'erreur statique entre la consigne et la mesure   */
/*                 pour déterminer si l'actionneur est obstrué.               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Wg_tiTrbActPhaDrn;                                            */
/*  input uint8 Wg_tiDlyTestTrbActMes1_C;                                     */
/*  input boolean WGACTRTEST_bTrbDrnStabCompPrev;                             */
/*  input uint8 Wg_tiDlyTestTrbActMes2_C;                                     */
/*  input uint8 WGACTRTEST_u8Timer;                                           */
/*  input uint16 Wg_rOpTrbActrTst;                                            */
/*  input uint16 TrbAct_rOpTrbActTmp;                                         */
/*  input uint16 Wg_rMaxTestTrbAct_C;                                         */
/*  input boolean WGACTRTEST_bTimeout;                                        */
/*  output uint8 WGACTRTEST_u8Timer;                                          */
/*  output boolean WGACTRTEST_bTimeout;                                       */
/*  output boolean Wg_bGapActrTst;                                            */
/*  output boolean WGACTRTEST_bTrbDrnStabCompPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGACTRTEST_vidTrbStabTest(void)
{
   boolean  bLocalComp;
   uint16   u16LocalWg_rOpTrbActrTst;
   uint32   u32LocalrOpTrbAct;


   if (Wg_tiTrbActPhaDrn >= Wg_tiDlyTestTrbActMes1_C)
   {
      bLocalComp = 1;
   }
   else
   {
      bLocalComp = 0;
   }

   if (  (WGACTRTEST_bTrbDrnStabCompPrev == 0)
      && (bLocalComp != 0))
   {
      WGACTRTEST_u8Timer = Wg_tiDlyTestTrbActMes2_C;
      if (WGACTRTEST_u8Timer == 0)
      {
         WGACTRTEST_bTimeout = 1;
      }
      else
      {
         WGACTRTEST_bTimeout = 0;
      }
   }
   else
   {
      if (WGACTRTEST_u8Timer > 0)
      {
         WGACTRTEST_u8Timer = (uint8)(WGACTRTEST_u8Timer - 1);
         if (WGACTRTEST_u8Timer == 0)
         {
            WGACTRTEST_bTimeout = 1;
         }
         else
         {
            WGACTRTEST_bTimeout = 0;
         }
      }
   }

   if (bLocalComp != 0)
   {
      VEMS_vidGET(Wg_rOpTrbActrTst, u16LocalWg_rOpTrbActrTst);
      u32LocalrOpTrbAct = (uint32)MATHSRV_udtABS(u16LocalWg_rOpTrbActrTst
                                                - TrbAct_rOpTrbActTmp);

      if (  (u32LocalrOpTrbAct >= Wg_rMaxTestTrbAct_C)
         && (WGACTRTEST_bTimeout != 0))
      {
         VEMS_vidSET(Wg_bGapActrTst, 1);
      }
   }
   WGACTRTEST_bTrbDrnStabCompPrev = bLocalComp;
}

/*---------------------------- end of file -----------------------------------*/