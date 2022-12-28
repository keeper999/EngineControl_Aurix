/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MUXDIAGON                                               */
/* !Description     : MUXDIAGON component.                                    */
/*                                                                            */
/* !Module          : MUXDIAGON                                               */
/* !Description     : GENERATION DU DIAG ON .                                 */
/*                                                                            */
/* !File            : MUXDIAGON_FCT1.C                                        */
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
/*   1 / MUXDIAGON_Vid_Init                                                   */
/*   2 / MUXDIAGON_Vid_RunDiagOn                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 05997 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/MUXDIAGON/MUXDIAGON_FCT1.C_v      $*/
/* $Revision::   1.4      $$Author::   fgravez        $$Date::   21 Jan 2010 $*/
/* $Author::   fgravez                                $$Date::   21 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MUXDIAGON.h"
#include "MUXDIAGON_l.h"
#include "MUXDIAGON_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXDIAGON_Vid_Init                                         */
/* !Description :  Initialization function.                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ	                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Valeur_tempo_srv_liaison_dem;                                 */
/*  output uint8 Tempo_surveillance_liaison;                                  */
/*  output boolean Diag_on;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : B.Safi                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXDIAGON_Vid_Init(void)
{
   Tempo_surveillance_liaison =
      (uint8)MATHSRV_udtMIN(Valeur_tempo_srv_liaison_dem, 250);

   VEMS_vidSET(Diag_on, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXDIAGON_Vid_RunDiagOn                                    */
/* !Description :  Main module function                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ	                                                 */
/* !Trace_To    :  VEMS_R_08_07446_023.01                                     */
/*                 VEMS_R_08_07446_025.01                                     */
/*                 VEMS_R_08_05997_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  input st12 Dtc_etat_structure;                                            */
/*  input uint16 Rcd_tempo_boot_count;                                        */
/*  input boolean Rcd_mode_active;                                            */
/*  input uint8 Tempo_surveillance_liaison;                                   */
/*  input uint8 Valeur_tempo_srv_liaison_redem;                               */
/*  input uint8 Valeur_tempo_srv_liaison_dem;                                 */
/*  output uint8 Tempo_surveillance_liaison;                                  */
/*  output boolean Diag_on;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : B.Safi                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXDIAGON_Vid_RunDiagOn(void)
{
   boolean bLocal_Tmp;
   boolean bLocalClef_de_contact;
   uint8   u8Local_TmpMax;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalDtc_etat_structure;
   uint16  u16LocalRcd_tempo_boot_count;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Dtc_etat_structure, u8LocalDtc_etat_structure);
   VEMS_vidGET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
   if (  (bLocalClef_de_contact != 0)
      && (  (u8LocalDtc_etat_structure == DTC_VERS_ET_STRUCTURE_COUPLE)
         || (u8LocalDtc_etat_structure == DTC_VERS_ET_DEBOUCLEE))
      && (  (Rcd_mode_active == 0)
         || (u16LocalRcd_tempo_boot_count == 0))
      && (u8LocalCoPTSt_stEng == Engine_Running))
   {
      bLocal_Tmp = 1;
   }
   else
   {
      bLocal_Tmp = 0;
   }

   if (bLocal_Tmp != 0)
   {
      u8Local_TmpMax =
         (uint8)(MATHSRV_udtMAX((Tempo_surveillance_liaison - 1), 0));
   }
   else
   {
      if (u8LocalCoPTSt_stEng == Stop)
      {
         u8Local_TmpMax = Valeur_tempo_srv_liaison_redem;
      }
      else
      {
         u8Local_TmpMax = Valeur_tempo_srv_liaison_dem;
      }
   }

   Tempo_surveillance_liaison = (uint8)MATHSRV_udtMIN(u8Local_TmpMax, 250);

   if (  (bLocal_Tmp != 0)
      && (Tempo_surveillance_liaison == 0))
   {
      VEMS_vidSET(Diag_on, 1);
   }
   else
   {
      VEMS_vidSET(Diag_on, 0);
   }
}
/*------------------------------ end of file ---------------------------------*/