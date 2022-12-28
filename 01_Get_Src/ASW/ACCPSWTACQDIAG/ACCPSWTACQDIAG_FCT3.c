/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPSWTACQDIAG                                          */
/* !Description     : ACCPSWTACQDIAG Component                                */
/*                                                                            */
/* !Module          : ACCPSWTACQDIAG                                          */
/* !Description     : IMPLEMENTATION DU TRAITEMENT DU CONTACTEUR ELECTRIQUE   */
/*                    LVV                                                     */
/*                                                                            */
/* !File            : ACCPSWTACQDIAG_FCT3.C                                   */
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
/*   1 / ACCPSWTACQDIAG_vidAccPedSwtAff                                       */
/*   2 / ACCPSWTACQDIAG_vidEndPtInstTempo                                     */
/*   3 / ACCPSWTACQDIAG_vidEndPtCounter                                       */
/*   4 / ACCPSWTACQDIAG_vidPtDurSensDetec                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6606841 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#050819                                         */
/* !OtherRefs   : VEMS V02 ECU#068754                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCP/ACCPSWTACQDIAG/ACCPSWTACQDIAG$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "ACCPSWTACQDIAG.H"
#include "ACCPSWTACQDIAG_L.H"
#include "ACCPSWTACQDIAG_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidAccPedSwtAff                             */
/* !Description :  Affectation de Passage_point_dur, recopie de Etat_point_dur*/
/*                 en absence de panne sur capteur point dur                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Etat_point_dur_raw;                                         */
/*  output boolean Cc_accel_pedal_wot_request;                                */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output boolean Etat_point_dur;                                            */
/*  output boolean Ext_bAccPHdPt;                                             */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidAccPedSwtAff(void)
{
   VEMS_vidSET(Cc_accel_pedal_wot_request, Etat_point_dur_raw);
   VEMS_vidSET(Etat_point_dur, Etat_point_dur_raw);
   VEMS_vidSET(Ext_bAccPHdPt, Etat_point_dur_raw);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidEndPtInstTempo                           */
/* !Description :  incrémntation instantanée du Tempo_maintien_etat_pt_dur.   */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Delai_maintien_etat_pt_dur;                                  */
/*  output uint16 Tempo_maintien_etat_pt_dur;                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidEndPtInstTempo(void)
{
   uint32 u32LocalTempo_maintien_etat_pt;


   u32LocalTempo_maintien_etat_pt = (uint32)(Delai_maintien_etat_pt_dur + 1);
   Tempo_maintien_etat_pt_dur =
      (uint16)MATHSRV_udtMIN(u32LocalTempo_maintien_etat_pt, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidEndPtCounter                             */
/* !Description :  Incréméntation de Tempo_maintien_etat_pt_dur.              */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Delai_maintien_etat_pt_dur;                                  */
/*  input uint16 Tempo_maintien_etat_pt_dur;                                  */
/*  output uint16 Tempo_maintien_etat_pt_dur;                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidEndPtCounter(void)
{
   uint32 u32LocalDelai_maintien_etat_pt;
   uint32 u32LocalTempo_maintien_etat_pt;
   uint32 u32LocalTempo;


   u32LocalDelai_maintien_etat_pt = (uint32)(Delai_maintien_etat_pt_dur + 1);
   u32LocalTempo_maintien_etat_pt = (uint32)(Tempo_maintien_etat_pt_dur + 1);
   u32LocalTempo = MATHSRV_udtMIN(u32LocalDelai_maintien_etat_pt,
                                  u32LocalTempo_maintien_etat_pt);
   Tempo_maintien_etat_pt_dur = (uint16)MATHSRV_udtMIN(u32LocalTempo,
                                                       65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidPtDurSensDetec                           */
/* !Description :  En présence d’un capteur point dur, le point dur sera      */
/*                 calculé à partir de AccP_rAccp : Si AccP_rAccp> seuil,     */
/*                 alors point dur atteint.                                   */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00973_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint16 AccP_point_dur_thd_C;                                        */
/*  output boolean Etat_point_dur;                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidPtDurSensDetec(void)
{
   uint16  u16LocalAccP_rAccP;


   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   if (u16LocalAccP_rAccP >= AccP_point_dur_thd_C)
   {
      VEMS_vidSET(Etat_point_dur, 1);
   }
   else
   {
      VEMS_vidSET(Etat_point_dur, 0);
   }
}
/*------------------------------- end of file --------------------------------*/