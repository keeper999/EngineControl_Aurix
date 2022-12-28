/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BATTVOLTACQ                                             */
/* !Description     : BATTVOLTACQ Component                                   */
/*                                                                            */
/* !Module          : BATTVOLTACQ                                             */
/* !Description     : ACQUISITION DE LA TENSION BATTERIE                      */
/*                                                                            */
/* !File            : BATTVOLTACQ_SCH.C                                       */
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
/*   1 / Pwr_EveRst_BattVoltAcq                                               */
/*   2 / Pwr_SdlFast_BattVoltAcq                                              */
/*   3 / Pwr_EveInj_BattVotlAcq                                               */
/*   4 / Pwr_Sdl2ms_BattVotlAcq                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6547150 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068642                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BATTVOLTACQ/BATTVOLTACQ_SCH.C_v   $*/
/* $Revision::   1.5      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "BATTVOLTACQ.h"
#include "BATTVOLTACQ_L.h"
#include "BATTVOLTACQ_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveRst_BattVoltAcq                                     */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTACQ_vidInitOutput();                             */
/*  extf argret void BATTVOLTACQ_vidBattAcqReset();                           */
/*  extf argret void BATTVOLTACQ_vidBattDiag();                               */
/*  extf argret void BATTVOLTACQ_vidBattIni();                                */
/*  extf argret void BATTVOLTACQ_vidBattFilt();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Pwr_EveRst_BattVoltAcq                                         */
/* !Trigger  : Pwr_EveRst_BattVoltAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveRst_BattVoltAcq(void)
{
   BATTVOLTACQ_vidInitOutput();
   BATTVOLTACQ_vidBattAcqReset();
   BATTVOLTACQ_vidBattDiag();
   BATTVOLTACQ_vidBattIni();
   BATTVOLTACQ_vidBattFilt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlFast_BattVoltAcq                                    */
/* !Description :  Moniteur rapide de la fonction power                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTACQ_vidbattFiltMng();                            */
/*  extf argret void BATTVOLTACQ_vidBattDiag();                               */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait) ;                                            */
/*  extf argret void BATTVOLTACQ_vidBattFil();                                */
/*  extf argret void BATTVOLTACQ_vidBattFilt();                               */
/*  input uint8 BATTVOLTACQ_u8Inhib;                                          */
/*  input boolean Ext_bDgoHi_uBattMes;                                        */
/*  input boolean Ext_bMonRunHi_uBattMes;                                     */
/*  input boolean Ext_bDgoLo_uBattMes;                                        */
/*  input boolean Ext_bMonRunLo_uBattMes;                                     */
/*  input boolean Ext_bDgoLo_uBattSpc;                                        */
/*  input boolean Ext_bMonRunLo_uBattSpc;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Pwr_SdlFast_BattVoltAcq                                        */
/* !Trigger  : Pwr_SdlFast_BattVoltAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlFast_BattVoltAcq(void)
{
   if (BATTVOLTACQ_u8Inhib != 0x5A)
   {
      BATTVOLTACQ_vidbattFiltMng();
      BATTVOLTACQ_vidBattDiag();
      GDGAR_vidGdu(GD_DFT_HI_UBATTMES,
                   Ext_bDgoHi_uBattMes,
                   Ext_bMonRunHi_uBattMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_UBATTMES,
                   Ext_bDgoLo_uBattMes,
                   Ext_bMonRunLo_uBattMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_UBATTSPC,
                   Ext_bDgoLo_uBattSpc,
                   Ext_bMonRunLo_uBattSpc,
                   DIAG_DISPO);
      BATTVOLTACQ_vidBattFil();
      BATTVOLTACQ_vidBattFilt();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveInj_BattVotlAcq                                     */
/* !Description :  Evenenement d'injection.                                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTACQ_vidBattAcqOnEveInj();                        */
/*  input uint8 BATTVOLTACQ_u8Inhib;                                          */
/*  input boolean Pwr_bEnaEveInj_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : Pwr_EveInj_BattVotlAcq                                         */
/* !Trigger  : Pwr_EveInj_BattVotlAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveInj_BattVotlAcq(void)
{
   if (BATTVOLTACQ_u8Inhib != 0x5A)
   {
      if(Pwr_bEnaEveInj_C != 0)
      {
         BATTVOLTACQ_vidBattAcqOnEveInj();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_Sdl2ms_BattVotlAcq                                     */
/* !Description :  Scheduler à 2ms.                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTACQ_vidBattAcqOn2ms();                           */
/*  input uint8 BATTVOLTACQ_u8Inhib;                                          */
/*  input boolean Pwr_bEnaEve2ms_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : Pwr_Sdl2ms_BattVotlAcq                                         */
/* !Trigger  : Pwr_Sdl2ms_BattVotlAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_Sdl2ms_BattVotlAcq(void)
{
   if (BATTVOLTACQ_u8Inhib != 0x5A)
   {
      if(Pwr_bEnaEve2ms_C != 0)
      {
         BATTVOLTACQ_vidBattAcqOn2ms();
      }
   }
}
/*------------------------------- end of file --------------------------------*/