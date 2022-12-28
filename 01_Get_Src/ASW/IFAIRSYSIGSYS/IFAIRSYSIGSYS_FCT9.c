/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_FCT9.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidOutput_nEng                                         */
/*   2 / IFAIRSYSIGSYS_vidOutput_OxC                                          */
/*   3 / IFAIRSYSIGSYS_vidCmdCoFan                                            */
/*   4 / IFAIRSYSIGSYS_vidOutN3F34DPM1413                                     */
/*   5 / IFAIRSYSIGSYS_vidtEcuAct                                             */
/*   6 / IFAIRSYSIGSYS_vidOutFHCanF7F2AV                                      */
/*   7 / IFAIRSYSIGSYS_vidOutputbDft                                          */
/*   8 / IFAIRSYSIGSYS_vidOutput_bStaReq                                      */
/*   9 / IFAIRSYSIGSYS_vidOutFHCanF4F2AV                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/IFAIRSYSIGSYS/IFAIRSYSIGSYS_FCT9$*/
/* $Revision::   1.25     $$Author::   HHAMLAOU       $$Date::   07 Nov 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_nEng                               */
/* !Description :  Fonction qui permet la production des variables Eng_nEng,  */
/*                 Ext_noNEngCplm et TqSys_tiEveSync2.                        */
/* !Number      :  FCT9.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 Ext_tiTDC;                                                    */
/*  output uint32 Eng_nEng;                                                   */
/*  output uint8 TqSys_tiEveSync2;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_nEng(void)
{
   /*F10_Output_nEng */
   uint8  u8LocalExt_tiTDC;
   uint16 u16LocalExt_nEng;
   uint32 u32LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u32LocalExt_nEng = (uint32)((u16LocalExt_nEng * 1024) + 62) / 125;
   u32LocalExt_nEng = MATHSRV_udtMIN(u32LocalExt_nEng, 65536);
   VEMS_vidSET(Eng_nEng, u32LocalExt_nEng);

   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   u8LocalExt_tiTDC = (uint8)MATHSRV_udtMIN(u8LocalExt_tiTDC, 100);
   VEMS_vidSET(TqSys_tiEveSync2, u8LocalExt_tiTDC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_OxC                                */
/* !Description :  Fonction d'interface du module CatMon.                     */
/* !Number      :  FCT9.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean OxC_bMonEndORngIntr;                                        */
/*  output boolean OxC_bEndMonORngItrsv;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_OxC(void)
{
   /*F08_Output_OxC */
   boolean bLocalOxC_bMonEndORngIntr;

   VEMS_vidGET(OxC_bMonEndORngIntr, bLocalOxC_bMonEndORngIntr);
   VEMS_vidSET(OxC_bEndMonORngItrsv, bLocalOxC_bMonEndORngIntr);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidCmdCoFan                                  */
/* !Description :  Fonction de production d'état consigne appliquée au GMV    */
/* !Number      :  FCT9.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Cf_speed_for_air;                                             */
/*  output uint8 Ext_rSpdFanAct;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidCmdCoFan(void)
{
   uint8  u8LocalCf_speed_for_air;
   uint8  u8LocalExt_rSpdFanAct;


   VEMS_vidGET(Cf_speed_for_air, u8LocalCf_speed_for_air);
   u8LocalExt_rSpdFanAct = (uint8)MATHSRV_udtMIN(u8LocalCf_speed_for_air, 55);
   VEMS_vidSET(Ext_rSpdFanAct, u8LocalExt_rSpdFanAct);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutN3F34DPM1413                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 ISCAN_u8N3F34DPM1413.                                      */
/* !Number      :  FCT9.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ISCAN_u8N6F34DPM1413;                                         */
/*  output uint8 ISCAN_u8N3F34DPM1413;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutN3F34DPM1413(void)
{
   /*F14_Output_u8N3F34DPM1413 */
   uint8 u8LocalISCAN_u8N6F34DPM1413;


   VEMS_vidGET(ISCAN_u8N6F34DPM1413, u8LocalISCAN_u8N6F34DPM1413);
   u8LocalISCAN_u8N6F34DPM1413 =
      (uint8)MATHSRV_udtMIN(u8LocalISCAN_u8N6F34DPM1413, 60);
   VEMS_vidSET(ISCAN_u8N3F34DPM1413, u8LocalISCAN_u8N6F34DPM1413);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidtEcuAct                                   */
/* !Description :  Fonction de production de la temprature interne du CMM     */
/* !Number      :  FCT9.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SenAct_tECUAcq;                                               */
/*  input boolean Ext_bAcvByptECUMes_C;                                       */
/*  input sint16 Ext_tECUMes_BypC;                                            */
/*  output sint16 Ext_tECUMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidtEcuAct(void)
{
   uint8  u8LocalSenAct_tECUAcq;
   sint16 s16LocalExt_tECUMes;


   VEMS_vidGET(SenAct_tECUAcq, u8LocalSenAct_tECUAcq);
   if (Ext_bAcvByptECUMes_C != 0)
   {
      s16LocalExt_tECUMes = Ext_tECUMes_BypC;
   }
   else
   {
      s16LocalExt_tECUMes = (sint16)( ( ( u8LocalSenAct_tECUAcq
                                        * 5)
                                      / 8)
                                    - 40);
   }
   s16LocalExt_tECUMes =
         (sint16)MATHSRV_udtCLAMP(s16LocalExt_tECUMes, -40, 250);
   VEMS_vidSET(Ext_tECUMes, s16LocalExt_tECUMes);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutFHCanF7F2AV                            */
/* !Description :  Fonction appelé à la réception d'une trame 7F2.            */
/* !Number      :  FCT9.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ISCAN_u8N8F7F2P301bis;                                        */
/*  output uint8 ISCAN_u8N8F7F2P301;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutFHCanF7F2AV(void)
{
   /*F16_Output_FHCanF7F2AVIf */
   uint8   u8LocalISCAN_u8N8F7F2P301bis;


   VEMS_vidGET(ISCAN_u8N8F7F2P301bis, u8LocalISCAN_u8N8F7F2P301bis);
   VEMS_vidSET(ISCAN_u8N8F7F2P301, u8LocalISCAN_u8N8F7F2P301bis);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputbDft                                */
/* !Description :  Fonction qui permet la production de la variable Ext_bDft. */
/* !Number      :  FCT9.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Jbsi_etat_dtc;                                              */
/*  output boolean Ext_bDft;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputbDft(void)
{
   /* F15_Output_bDft */
   boolean  bLocalJbsi_etat_dtc;


   VEMS_vidGET(Jbsi_etat_dtc, bLocalJbsi_etat_dtc);
   VEMS_vidSET(Ext_bDft, bLocalJbsi_etat_dtc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutput_bStaReq                            */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 StaCtl_bStaReq.                                            */
/* !Number      :  FCT9.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean StaStrtMgt_bStaReq;                                         */
/*  output boolean StaCtl_bStaReq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutput_bStaReq(void)
{
   /*F01_Output_bStaReq */
   boolean bLocalStaStrtMgt_bStaReq;


   VEMS_vidGET(StaStrtMgt_bStaReq, bLocalStaStrtMgt_bStaReq);
   VEMS_vidSET(StaCtl_bStaReq, bLocalStaStrtMgt_bStaReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutFHCanF4F2AV                            */
/* !Description :  Fonction appelé à la réception d'une trame 4F2.            */
/* !Number      :  FCT9.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ISCAN_bN9F4F2P437NotAvl;                                    */
/*  output boolean ISCAN_bN10F4F2P437NotAvl;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutFHCanF4F2AV(void)
{
   /*F17_Output_FHCanF4F2AVIf */
   boolean bLocalISCAN_bN9F4F2P437NotAvl;


   VEMS_vidGET(ISCAN_bN9F4F2P437NotAvl, bLocalISCAN_bN9F4F2P437NotAvl);
   VEMS_vidSET(ISCAN_bN10F4F2P437NotAvl, bLocalISCAN_bN9F4F2P437NotAvl);
}
/*-------------------------------- end of file -------------------------------*/