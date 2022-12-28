/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TOILEST                                                 */
/* !Description     : TOILEST Component                                       */
/*                                                                            */
/* !Module          : TOILEST                                                 */
/* !Description     : ESTIMATION DE LA TEMPERATURE D'HUILE                    */
/*                                                                            */
/* !File            : TOILEST_sch.c                                           */
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
/*   1 / Eng_EveIni_tOilEstim                                                 */
/*   2 / Eng_Sdl100ms_tOilEstim                                               */
/*   3 / Eng_EvePwL_tOilEstim                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5050596 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_2341 / 2.7                                      */
/* !OtherRefs   : VEMS V02 ECU#050185                                         */
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
#include "GDGAR.h"
#include "TOILEST.h"
#include "TOILEST_L.h"
#include "TOILEST_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Eng_EveIni_tOilEstim                                       */
/* !Description :  Fonction d'accroche au moniteur de Reset.                  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07613_001.01                                     */
/*                 VEMS_R_10_06089_004.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TOILEST_vidInitialiser();                                */
/*  extf argret void TOILEST_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Eng_EveIni_tOilEstim                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Eng_EveIni_tOilEstim(void)
{
   TOILEST_vidInitialiser();
   TOILEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Eng_Sdl100ms_tOilEstim                                     */
/* !Description :  Fonction d'accroche au moniteur moyen.                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07613_001.01                                     */
/*                 VEMS_R_10_06089_004.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TOILEST_vidCalculerThuile();                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 TOILEST_u8Inhib;                                              */
/*  input boolean Eng_bDgoORngHiTOilEstim;                                    */
/*  input boolean Eng_bMonRunORngTOilEstim;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Eng_Sdl100ms_tOilEstim                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Eng_Sdl100ms_tOilEstim(void)
{
   /* Msg(2:4152) Names of events are imposed by specification document. */
   boolean bLocalEng_bDgoORngHiTOilEstim;
   boolean bLocalEng_bMonRunORngTOilEstim;


   if (TOILEST_u8Inhib != 0x5A)
   {
      TOILEST_vidCalculerThuile();

      VEMS_vidGET(Eng_bDgoORngHiTOilEstim, bLocalEng_bDgoORngHiTOilEstim);
      VEMS_vidGET(Eng_bMonRunORngTOilEstim, bLocalEng_bMonRunORngTOilEstim);
      GDGAR_vidGdu(GD_DFT_ORNGHITOILESTIM,
                   bLocalEng_bDgoORngHiTOilEstim,
                   bLocalEng_bMonRunORngTOilEstim,
                   FALSE);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Eng_EvePwL_tOilEstim                                       */
/* !Description :  Evènement Power Latch.                                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07613_001.01                                     */
/*                 VEMS_R_10_06089_004.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TOILEST_vidPowerLatch();                                 */
/*  input uint8 TOILEST_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Eng_EvePwL_tOilEstim                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Eng_EvePwL_tOilEstim(void)
{
   if (TOILEST_u8Inhib != 0x5A)
   {
      TOILEST_vidPowerLatch();
   }
}
/*--------------------------------- end of file ------------------------------*/