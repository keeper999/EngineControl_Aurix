/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BLOWBYCMD                                               */
/* !Description     : BLOWBYCMD component.                                    */
/*                                                                            */
/* !Module          : BLOWBYCMD                                               */
/* !Description     : BlowBy COMMAND AND DIAGNOSIS                            */
/*                                                                            */
/* !File            : BLOWBYCMD_SCH.C                                         */
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
/*   1 / Oil_EveRst_BlowByCmd                                                 */
/*   2 / Oil_SdlSlow_BlowByCmd                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6563717 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BLOWBYCMD/BLOWBYCMD_SCH.C_v       $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BLOWBYCMD.h"
#include "BLOWBYCMD_L.h"
#include "BLOWBYCMD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveRst_BlowByCmd                                       */
/* !Description :  Reset event for BlowBy command                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BLOWBYCMD_vidInit();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  Oil_EveRst_BlowByCmd                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveRst_BlowByCmd(void)
{
   BLOWBYCMD_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlSlow_BlowByCmd                                      */
/* !Description :  Slow scheduler for BlowByCmd                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_04583_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BLOWBYCMD_vidHeaterCmd();                                */
/*  extf argret void BLOWBYCMD_vidBlowBy1Cmd();                               */
/*  extf argret void BLOWBYCMD_vidDiagBlowBy1();                              */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void BLOWBYCMD_vidBlowBy2Cmd();                               */
/*  extf argret void BLOWBYCMD_vidDiagBlowBy2();                              */
/*  input uint8 BLOWBYCMD_u8Inhib;                                            */
/*  input boolean Ctrl_bAvc_BlowBy1;                                          */
/*  input boolean Ctrl_bAvc_BlowBy2;                                          */
/*  input boolean OilSys_bDgoScg_BlowBy1;                                     */
/*  input boolean OilSys_bMonRunScg_BlowBy1;                                  */
/*  input boolean OilSys_bDgoScp_BlowBy1;                                     */
/*  input boolean OilSys_bMonRunScp_BlowBy1;                                  */
/*  input boolean OilSys_bDgoOc_BlowBy1;                                      */
/*  input boolean OilSys_bMonRunOc_BlowBy1;                                   */
/*  input boolean OilSys_bDgoScg_BlowBy2;                                     */
/*  input boolean OilSys_bMonRunScg_BlowBy2;                                  */
/*  input boolean OilSys_bDgoScp_BlowBy2;                                     */
/*  input boolean OilSys_bMonRunScp_BlowBy2;                                  */
/*  input boolean OilSys_bDgoOc_BlowBy2;                                      */
/*  input boolean OilSys_bMonRunOc_BlowBy2;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlSlow_BlowByCmd                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlSlow_BlowByCmd(void)
{
   boolean bLocalCtrl_bAvc_BlowBy1;
   boolean bLocalCtrl_bAvc_BlowBy2;


   if (BLOWBYCMD_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAvc_BlowBy1, bLocalCtrl_bAvc_BlowBy1);
      VEMS_vidGET(Ctrl_bAvc_BlowBy2, bLocalCtrl_bAvc_BlowBy2);
      if ((bLocalCtrl_bAvc_BlowBy1 != 0) || (bLocalCtrl_bAvc_BlowBy2 != 0))
      {
         BLOWBYCMD_vidHeaterCmd();
      }
      if (bLocalCtrl_bAvc_BlowBy1 != 0)
      {
         BLOWBYCMD_vidBlowBy1Cmd();
         BLOWBYCMD_vidDiagBlowBy1();
         GDGAR_vidGdu(GD_DFT_SCG_BLOWBY1,
                      OilSys_bDgoScg_BlowBy1,
                      OilSys_bMonRunScg_BlowBy1,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCP_BLOWBY1,
                      OilSys_bDgoScp_BlowBy1,
                      OilSys_bMonRunScp_BlowBy1,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OC_BLOWBY1,
                      OilSys_bDgoOc_BlowBy1,
                      OilSys_bMonRunOc_BlowBy1,
                      DIAG_DISPO);
      }
      if (bLocalCtrl_bAvc_BlowBy2 != 0)
      {
         BLOWBYCMD_vidBlowBy2Cmd();
         BLOWBYCMD_vidDiagBlowBy2();
         GDGAR_vidGdu(GD_DFT_SCG_BLOWBY2,
                      OilSys_bDgoScg_BlowBy2,
                      OilSys_bMonRunScg_BlowBy2,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCP_BLOWBY2,
                      OilSys_bDgoScp_BlowBy2,
                      OilSys_bMonRunScp_BlowBy2,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OC_BLOWBY2,
                      OilSys_bDgoOc_BlowBy2,
                      OilSys_bMonRunOc_BlowBy2,
                      DIAG_DISPO);
      }
   }
}
/*-------------------------------- End of file -------------------------------*/