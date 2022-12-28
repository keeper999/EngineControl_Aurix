/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFELECMOTESS                                            */
/* !Description     : IFELECMOTESS component.                                 */
/*                                                                            */
/* !Module          : IFELECMOTESS                                            */
/* !Description     : INTERFACE BESOIN ELECTRIQUE MOTEUR ESSENCE              */
/*                                                                            */
/* !File            : IFELECMOTESS_FCT1.C                                     */
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
/*   1 / IFELECMOTESS_vidInitOutput                                           */
/*   2 / IFELECMOTESS_vidByte_carrier                                         */
/*                                                                            */
/* !Reference   : V02 NT 12 00929 / 01                                        */
/* !OtherRefs   : 01460_11_00542_1 / 2.1                                      */
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
#include "MATHSRV.h"
#include "IFELECMOTESS.h"
#include "IFELECMOTESS_L.h"
#include "IFELECMOTESS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFELECMOTESS_vidInitOutput                                 */
/* !Description :  fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Ext_bfAcvConstEng1;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFELECMOTESS_vidInitOutput(void)
{
   VEMS_vidSET(Ext_bfAcvConstEng1, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFELECMOTESS_vidByte_carrier                               */
/* !Description :  « Ext_bfAcvConstEng1 » est un porteur d’information,       */
/*                 consommé par la fonction « CoOptmEl ». Chaque booléen en   */
/*                 entrée est positionné dans un octet.                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_12_00929_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsSys_bAdj_uBattNom;                                        */
/*  input boolean IgVoltAdj_bVoltAdj;                                         */
/*  input boolean InjSys_bVoltAdj;                                            */
/*  input boolean ThMgt_bIncVoltReq;                                          */
/*  input boolean BoostReq_bBattVoltReq;                                      */
/*  input boolean FTPCtl_bVoltCtlReq;                                         */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  input uint8 TWCMgt_stHeatPhaReq;                                          */
/*  input uint8 IfEngReq_stHeatPha_A[5];                                      */
/*  input boolean IfEngReq_bIncVoltReqTWC_T[5];                               */
/*  output uint8 Ext_bfAcvConstEng1;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFELECMOTESS_vidByte_carrier(void)
{
   boolean bLocalLsSys_bAdj_uBattNom;
   boolean bLocalIgVoltAdj_bVoltAdj;
   boolean bLocalInjSys_bVoltAdj;
   boolean bLocalThMgt_bIncVoltReq;
   boolean bLocalBoostReq_bBattVoltReq;
   boolean bLocalFTPCtl_bVoltCtlReq;
   boolean bLocalEOM_bTWCHeatPha;
   boolean bLocalOutMap;
   uint8   u8LocalTWCMgt_stHeatPhaReq;
   uint8   u8Localindex;
   uint8   u8LocalExt_bfAcvConstEng1;
   uint16  u16LocalPara;


   VEMS_vidGET(LsSys_bAdj_uBattNom, bLocalLsSys_bAdj_uBattNom);
   VEMS_vidGET(IgVoltAdj_bVoltAdj, bLocalIgVoltAdj_bVoltAdj);
   VEMS_vidGET(InjSys_bVoltAdj, bLocalInjSys_bVoltAdj);
   VEMS_vidGET(ThMgt_bIncVoltReq, bLocalThMgt_bIncVoltReq);
   VEMS_vidGET(BoostReq_bBattVoltReq, bLocalBoostReq_bBattVoltReq);
   VEMS_vidGET(FTPCtl_bVoltCtlReq, bLocalFTPCtl_bVoltCtlReq);
   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   VEMS_vidGET(TWCMgt_stHeatPhaReq, u8LocalTWCMgt_stHeatPhaReq);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(IfEngReq_stHeatPha_A,
                                              u8LocalTWCMgt_stHeatPhaReq,
                                              5);
   u8Localindex = (uint8)(u16LocalPara >> 8);
   bLocalOutMap = IfEngReq_bIncVoltReqTWC_T[u8Localindex];

   u8LocalExt_bfAcvConstEng1 = 0;
   if (bLocalLsSys_bAdj_uBattNom != 0)
   {
      u8LocalExt_bfAcvConstEng1 = 1;
   }
   if (bLocalIgVoltAdj_bVoltAdj != 0)
   {
      u8LocalExt_bfAcvConstEng1 = (uint8)(u8LocalExt_bfAcvConstEng1 + 2);
   }
   if (bLocalInjSys_bVoltAdj != 0)
   {
      u8LocalExt_bfAcvConstEng1 = (uint8)(u8LocalExt_bfAcvConstEng1 + 4);
   }
   if (bLocalThMgt_bIncVoltReq != 0)
   {
      u8LocalExt_bfAcvConstEng1 = (uint8)(u8LocalExt_bfAcvConstEng1 + 8);
   }
   if (bLocalBoostReq_bBattVoltReq != 0)
   {
      u8LocalExt_bfAcvConstEng1 = (uint8)(u8LocalExt_bfAcvConstEng1 + 16);
   }
   if (bLocalFTPCtl_bVoltCtlReq != 0)
   {
      u8LocalExt_bfAcvConstEng1 = (uint8)(u8LocalExt_bfAcvConstEng1 + 32);
   }
   if ( (bLocalOutMap != 0) && (bLocalEOM_bTWCHeatPha != 0))
   {
      u8LocalExt_bfAcvConstEng1 = (uint8)(u8LocalExt_bfAcvConstEng1 + 64);
   }
   VEMS_vidSET(Ext_bfAcvConstEng1, u8LocalExt_bfAcvConstEng1);
}
/*-------------------------------- End of file -------------------------------*/