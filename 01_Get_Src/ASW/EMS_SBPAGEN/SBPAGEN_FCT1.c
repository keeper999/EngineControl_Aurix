/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SBPAGEN                                                 */
/* !Description     : SBPAGEN Component                                       */
/*                                                                            */
/* !Module          : SBPAGEN                                                 */
/* !Description     : Générateur De Sbpa                                      */
/*                                                                            */
/* !File            : SBPAGEN_FCT1.C                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : Renesas                                                 */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / SBPAGEN_vidInitOutput                                                */
/*   2 / SBPAGEN_vidCalculer_SBPA                                             */
/*   3 / SBPAGEN_vidCalculer_niveau                                           */
/*   4 / SBPAGEN_vidEffectuer_traitements                                     */
/*   5 / SBPAGEN_vidDecaler_registre                                          */
/*   6 / SBPAGEN_vidModifier_niveau                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 07560 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_1271 / 1.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/SBPAGEN/SBPAGEN_F$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SBPAGEN.h"
#include "SBPAGEN_L.h"
#include "SBPAGEN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidInitOutput                                      */
/* !Description :  Initialisation des variables de sortie                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 TqSys_ctPerSBPA;                                             */
/*  output sint16 TqSys_tqIdcSBPA;                                            */
/*  output uint16 TqSys_ctCycSBPA;                                            */
/*  output sint16 TqSys_tqIdcLvlSBPA;                                         */
/*  output uint16 SBPAGEN_u16SbpaShiftRegister;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidInitOutput(void)
{
   VEMS_vidSET(TqSys_ctPerSBPA, 0);
   VEMS_vidSET(TqSys_tqIdcSBPA, 0);
   VEMS_vidSET(TqSys_ctCycSBPA, 0);
   VEMS_vidSET(TqSys_tqIdcLvlSBPA, 0);
   SBPAGEN_u16SbpaShiftRegister = 0x0001;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidCalculer_SBPA                                   */
/* !Description :  Cette fonction génère une SBPA utilisée pour               */
/*                 l’identification de système.                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SBPAGEN_vidCalculer_niveau();                            */
/*  extf argret void SBPAGEN_vidEffectuer_traitements();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidCalculer_SBPA(void)
{
   SBPAGEN_vidCalculer_niveau();
   SBPAGEN_vidEffectuer_traitements();

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidCalculer_niveau                                 */
/* !Description :  effectue  les opérations dans  le  registre de décalage,   */
/*                 produit  la valeur du compteur de période et commande la   */
/*                 valeur du niveau de sortie du signal                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SBPAGEN_vidDecaler_registre();                           */
/*  extf argret void SBPAGEN_vidModifier_niveau();                            */
/*  input boolean TqSys_bAcvChgLvl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidCalculer_niveau(void)
{
   SBPAGEN_vidDecaler_registre();

   if (TqSys_bAcvChgLvl != 0)
   {
      SBPAGEN_vidModifier_niveau();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidEffectuer_traitements                           */
/* !Description :  applique  les  valeurs  de  couple  à  la  SBPA  selon  le */
/*                 niveau demandé par le registre de décalage et renvoie la   */
/*                 valeur du compteur de cycles ainsi que la somme entre les  */
/*                 niveaux de couple haut et bas.                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqSys_tqLoLvlSBPA_C;                                         */
/*  input sint16 TqSys_tqHiLvlSBPA_C;                                         */
/*  input boolean TqSys_bAcvSBPAClc_C;                                        */
/*  input boolean TqSys_bLvlSBPA;                                             */
/*  input uint16 TqSys_ctCycSBPA;                                             */
/*  output sint16 TqSys_tqIdcLvlSBPA;                                         */
/*  output sint16 TqSys_tqIdcSBPA;                                            */
/*  output uint16 TqSys_ctCycSBPA;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidEffectuer_traitements(void)
{
   sint16 s16LocalTqSys_tqIdcSBPA;
   sint16 s16LocalTqSys_tqIdcLvlSBPA;
   uint16 u16LocalTqSys_ctCycSBPA;
   sint32 s32LocalTqSys_tqIdcLvlSBPA;

   s32LocalTqSys_tqIdcLvlSBPA =
      (sint32)(TqSys_tqLoLvlSBPA_C + TqSys_tqHiLvlSBPA_C);
   s16LocalTqSys_tqIdcLvlSBPA =
      (sint16)MATHSRV_udtCLAMP(s32LocalTqSys_tqIdcLvlSBPA, -32000, 32000);
   VEMS_vidSET(TqSys_tqIdcLvlSBPA, s16LocalTqSys_tqIdcLvlSBPA);

   if (TqSys_bAcvSBPAClc_C != 0)
   {
      if (TqSys_bLvlSBPA != 0)
      {
         s16LocalTqSys_tqIdcSBPA = TqSys_tqHiLvlSBPA_C;
      }
      else
      {
         s16LocalTqSys_tqIdcSBPA = TqSys_tqLoLvlSBPA_C;
      }
      s16LocalTqSys_tqIdcSBPA =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcSBPA, -32000, 32000);
      VEMS_vidSET(TqSys_tqIdcSBPA, s16LocalTqSys_tqIdcSBPA);

      VEMS_vidGET(TqSys_ctCycSBPA, u16LocalTqSys_ctCycSBPA);
      if (u16LocalTqSys_ctCycSBPA == 65535)
      {
         u16LocalTqSys_ctCycSBPA = 0;
      }
      else
      {
         u16LocalTqSys_ctCycSBPA = (uint16)(u16LocalTqSys_ctCycSBPA + 1);
      }
      VEMS_vidSET(TqSys_ctCycSBPA,u16LocalTqSys_ctCycSBPA);
   }
   else
   {
      VEMS_vidSET(TqSys_tqIdcSBPA, 0);
      VEMS_vidSET(TqSys_ctCycSBPA, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidDecaler_registre                                */
/* !Description :  La  fonction  « mod »  effectue  la  remise  à  zéro  du   */
/*                 compteur  lorsque  celui-ci atteint  la valeur définie par */
/*                 le paramètre TqSys_noPerSBPA_C, ce qui a pour effet de     */
/*                 générer un front montant de la sortie TqSys_bAcvChgLvl.    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 TqSys_ctPerSBPA;                                              */
/*  input uint8 TqSys_noPerSBPA_C;                                            */
/*  output boolean TqSys_bAcvChgLvl;                                          */
/*  output uint8 TqSys_ctPerSBPA;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidDecaler_registre(void)
{
   uint8 u8LocalTqSys_ctPerSBPA;

   VEMS_vidGET(TqSys_ctPerSBPA, u8LocalTqSys_ctPerSBPA);
   if (TqSys_noPerSBPA_C == 0)
   {
      u8LocalTqSys_ctPerSBPA = 0;
   }
   else
   {
      u8LocalTqSys_ctPerSBPA = (uint8)((u8LocalTqSys_ctPerSBPA + 1)
                                       % TqSys_noPerSBPA_C);
   }
   if (u8LocalTqSys_ctPerSBPA == 0)
   {
      TqSys_bAcvChgLvl = 1;
   }
   else
   {
      TqSys_bAcvChgLvl = 0;
   }
   VEMS_vidSET(TqSys_ctPerSBPA,u8LocalTqSys_ctPerSBPA);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SBPAGEN_vidModifier_niveau                                 */
/* !Description :  L’ordre TqSys_bAcvChgLvl active  le  rafraîchissement des  */
/*                 calculs du  registre de décalage à 9 états, qui            */
/*                 déterminent la consigne de commutation du niveau de la SBPA*/
/*                 (TqSys_bLvlSBPA).                                          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07560_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SBPAGEN_u16SbpaShiftRegister;                                */
/*  input boolean TqSys_bLvlSBPA;                                             */
/*  output boolean TqSys_bLvlSBPA;                                            */
/*  output uint16 SBPAGEN_u16SbpaShiftRegister;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SBPAGEN_vidModifier_niveau(void)
{
   boolean bLocalBit5;
   uint16  u16LocalShiftRegister;


   u16LocalShiftRegister = (uint16)(SBPAGEN_u16SbpaShiftRegister & 0x01FF);

   if ((u16LocalShiftRegister & 0x0001) != 0)
   {
      TqSys_bLvlSBPA = 1;
   }
   else
   {
      TqSys_bLvlSBPA = 0;
   }

   if ((u16LocalShiftRegister & 0x0010) != 0)
   {
      bLocalBit5 = 1;
   }
   else
   {
      bLocalBit5 = 0;
   }

   u16LocalShiftRegister = (uint16)(u16LocalShiftRegister >> 1);

   if ((bLocalBit5 ^ TqSys_bLvlSBPA) == 0)
   {
      SBPAGEN_u16SbpaShiftRegister = (uint16)(u16LocalShiftRegister & 0x00FF);
   }
   else
   {
      SBPAGEN_u16SbpaShiftRegister = (uint16)(u16LocalShiftRegister | 0x0100);
   }
}
/*---------------------------------end of file -------------------------------*/