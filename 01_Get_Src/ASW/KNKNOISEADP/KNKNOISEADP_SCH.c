/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKNOISEADP                                             */
/* !Description     : KNKNOISEADP component                                   */
/*                                                                            */
/* !Module          : KNKNOISEADP                                             */
/* !Description     : ADAPTATION DU BRUIT MOTEUR MOYEN POUR LA STRATEGIE DE   */
/*                    DETECTION CLIQUETIS                                     */
/*                                                                            */
/* !File            : KNKNOISEADP_SCH.C                                       */
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
/*   1 / KnkTreat_EveRst_NoiseAdp                                             */
/*   2 / KnkTreat_EveKnk_NoiseAdp                                             */
/*   3 / KnkTreat_SdlSlow_NoiseAdp                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 05725 / 06                                        */
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

#include "STD_TYPES.H"
#include "KNKNOISEADP.H"
#include "KNKNOISEADP_L.H"
#include "KNKNOISEADP_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_NoiseAdp                                   */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKNOISEADP_vidInitOutput();                             */
/*  extf argret void KNKNOISEADP_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_NoiseAdp                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_NoiseAdp(void)
{
   KNKNOISEADP_vidInitOutput();
   KNKNOISEADP_vidInitialization();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveKnk_NoiseAdp                                   */
/* !Description :  Tâche de calcul du niveau de cliquetis pour le cylindre en */
/*                 cours                                                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKNOISEADP_vidActivationCond();                         */
/*  extf argret void KNKNOISEADP_vidAdaptation();                             */
/*  input uint8 KNKNOISEADP_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveKnk_NoiseAdp                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveKnk_NoiseAdp(void)
{
   if (KNKNOISEADP_u8Inhib != 0x5A)
   {
      KNKNOISEADP_vidActivationCond();
      KNKNOISEADP_vidAdaptation();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlSlow_NoiseAdp                                  */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.3                                                      */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKNOISEADP_vidDiagnostic();                             */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 KNKNOISEADP_u8Inhib;                                          */
/*  input boolean KnkTreat_bDgoHHit_NoiseAdp;                                 */
/*  input boolean KnkTreat_bMonRun_NoiseAdp;                                  */
/*  input boolean KnkTreat_bDgoLHit_NoiseAdp;                                 */
/*  input boolean KnkTreat_bDgoHSld_NoiseAdp;                                 */
/*  input boolean KnkTreat_bDgoLSld_NoiseAdp;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlSlow_NoiseAdp                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlSlow_NoiseAdp(void)
{
   if (KNKNOISEADP_u8Inhib != 0x5A)
   {
      KNKNOISEADP_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_HHIT_NOISEADP,
                   KnkTreat_bDgoHHit_NoiseAdp,
                   KnkTreat_bMonRun_NoiseAdp,
                   0);
      GDGAR_vidGdu(GD_DFT_LHIT_NOISEADP,
                   KnkTreat_bDgoLHit_NoiseAdp,
                   KnkTreat_bMonRun_NoiseAdp,
                   0);
      GDGAR_vidGdu(GD_DFT_HSLD_NOISEADP,
                   KnkTreat_bDgoHSld_NoiseAdp,
                   KnkTreat_bMonRun_NoiseAdp,
                   0);
      GDGAR_vidGdu(GD_DFT_LSLD_NOISEADP,
                   KnkTreat_bDgoLSld_NoiseAdp,
                   KnkTreat_bMonRun_NoiseAdp,
                   0);
   }
}
/*------------------------------end of file-----------------------------------*/