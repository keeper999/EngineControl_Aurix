/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SUMRAT                                                  */
/* !Description     : SUMRAT Component                                        */
/*                                                                            */
/* !Module          : SUMRAT                                                  */
/* !Description     : Pre-consolidation modules for IUPR Ratios               */
/*                                                                            */
/* !File            : SUMRAT_FCT1.C                                           */
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
/*   1 / SUMRAT_vidF01                                                        */
/*   2 / SUMRAT_vidF02                                                        */
/*                                                                            */
/* !Reference   : V02 NT 10 06202 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/SUMRAT/SumRat_fct1.c_v       $*/
/* $Revision::   1.5      $$Author::   alaouni        $$Date::   21 Feb 2012 $*/
/* $Author::   alaouni                                $$Date::   21 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "SUMRAT.h"
#include "SUMRAT_L.h"
#include "SUMRAT_IM.h"
#include "GD_api.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SUMRAT_vidF01                                              */
/* !Description :  Call on ECU reset event                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  RR.RAOUAGI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*  output boolean SumRat_bDgoIUPRSynt[3];                                    */
/*  output boolean SumRat_bMonRunIUPRSynt[3];                                 */
/*  output uint8 Sumrat_au8PrevDrvCyc[10];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : SUMRAT_vidF01                                                  */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SUMRAT_vidF01(void)
{
   uint8    u8LocalModPreReg;
   uint16   u16LocalDftIdx;

   for(  u8LocalModPreReg = 0;
         u8LocalModPreReg < IUPR_NB_MOD_PRE_REG;
         u8LocalModPreReg++)
   {
      SumRat_bDgoIUPRSynt[u8LocalModPreReg] = 0;
      SumRat_bMonRunIUPRSynt[u8LocalModPreReg] = 0;
   }
   for ( u16LocalDftIdx = 0;
         u16LocalDftIdx < ((GD_DFT_NB/8)+1);
         u16LocalDftIdx++)
   {
      Sumrat_au8PrevDrvCyc[u16LocalDftIdx] = DC_au8DC_EEPROM[u16LocalDftIdx];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SUMRAT_vidF02                                              */
/* !Description :  Call on slow event                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  RR.RAOUAGI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf GD_bBitRead(????);                                                   */
/*  extf GD_vidBitWrite(????);                                                */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait );                    */
/*  input uint16 SumRat_idxDftIUPRSynt_C[3][5];                               */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*  input uint8 Sumrat_au8PrevDrvCyc[10];                                     */
/*  input boolean SumRat_bDgoIUPRSynt[3];                                     */
/*  input boolean SumRat_bMonRunIUPRSynt[3];                                  */
/*  output boolean SumRat_bMonRunIUPRSynt[3];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : SUMRAT_vidF02                                                  */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SUMRAT_vidF02(void)
{
   boolean  bLocalDc;
   boolean  bLocalPrevDc;
   uint8    u8LocalDftParMod;
   uint8    u8LocalDivision;
   uint8    u8LocalRatio;
   uint16   u16LocalIndex;
   uint16   u16LocalModPreReg;
   uint16   u16LocalDftIUPRSynt;

   for ( u16LocalModPreReg = 0;
         u16LocalModPreReg < IUPR_NB_MOD_PRE_REG;
         u16LocalModPreReg++)
   {
      SumRat_bMonRunIUPRSynt[u16LocalModPreReg] = 0;

      for ( u8LocalDftParMod = 0;
            u8LocalDftParMod < IUPR_NB_DFT_PAR_MOD;
            u8LocalDftParMod++)
      {
         u16LocalIndex =
            SumRat_idxDftIUPRSynt_C[u16LocalModPreReg][u8LocalDftParMod];

         if(u16LocalIndex < GD_DFT_NB)
         {
            u8LocalDivision = (uint8)(u16LocalIndex / 8);
            u8LocalRatio = (uint8)(u16LocalIndex % 8);

            bLocalDc =
               GD_bBitRead(DC_au8DC_EEPROM[u8LocalDivision],u8LocalRatio);
            bLocalPrevDc =
               GD_bBitRead(Sumrat_au8PrevDrvCyc[u8LocalDivision],u8LocalRatio);

            if ((bLocalDc == 1)&&(bLocalPrevDc == 0))
            {
               SumRat_bMonRunIUPRSynt[u16LocalModPreReg] = 1;
            }

            GD_vidBitWrite(Sumrat_au8PrevDrvCyc[u8LocalDivision],
                  u8LocalRatio, bLocalDc);
         }
      }

      u16LocalDftIUPRSynt = (uint16)(GD_DFT_IUPRSYNT1 + u16LocalModPreReg);
      GDGAR_vidGdu(u16LocalDftIUPRSynt, SumRat_bDgoIUPRSynt[u16LocalModPreReg],
                   SumRat_bMonRunIUPRSynt[u16LocalModPreReg], DIAG_DISPO);
   }
}
