/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJTICOR                                                */
/* !Description     : INJTICOR component                                      */
/*                                                                            */
/* !Module          : INJTICOR                                                */
/* !Description     : CORRECTION DE LA RÉGULATION DE RICHESSE EN BUTÉE        */
/*                                                                            */
/* !File            : INJTICOR_FCT6.C                                         */
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
/*   1 / INJTICOR_vidbDgoSen02AmLeanBlo                                       */
/*   2 / INJTICOR_vidbDgoSen02AmRichBlo                                       */
/*   3 / INJTICOR_vidbDgoAlimRichFuel                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_FCT6.C_v        $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   20 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INJTICOR.h"
#include "INJTICOR_L.h"
#include "INJTICOR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidbDgoSen02AmLeanBlo                             */
/* !Description :  Cette fonction traite le cas d'un Défaut sonde amont       */
/*                 bloquée pauvre : Lfbk_on_enrich_clamp et Sonde_riche_aval  */
/*                 sont à l'état ON.                                          */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  input boolean Sonde_riche_aval;                                           */
/*  input uint8 Lfbk_switch_rich_delay_count;                                 */
/*  input uint8 Lfbk_switch_rich_delay;                                       */
/*  output uint8 Lfbk_switch_rich_delay_count;                                */
/*  output boolean Lfbk_switch_rich;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidbDgoSen02AmLeanBlo(void)
{
   /* 2_bDgo_Sen02_Amont_bloque_pauvre  */
   boolean bLocalLfbkOnEnrichClamp;
   boolean bLocalSondeRicheAval;


   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbkOnEnrichClamp);
   VEMS_vidGET(Sonde_riche_aval, bLocalSondeRicheAval);

   if (  (bLocalLfbkOnEnrichClamp != 0)
      && (bLocalSondeRicheAval != 0))
   {
      if (Lfbk_switch_rich_delay_count > 0)
      {
         Lfbk_switch_rich_delay_count =
            (uint8)(Lfbk_switch_rich_delay_count - 1);
      }
      else
      {
         Lfbk_switch_rich_delay_count = 0;
      }
   }
   else
   {
      Lfbk_switch_rich_delay_count = Lfbk_switch_rich_delay;
   }
   if (Lfbk_switch_rich_delay_count == 0)
   {
      Lfbk_switch_rich = 1;
   }
   else
   {
      Lfbk_switch_rich = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidbDgoSen02AmRichBlo                             */
/* !Description :  Cette fonction traite le cas d'un Défaut sonde amont       */
/*                 bloquée riche : Lfbk_on_enrich_clamp et Sonde_riche_aval   */
/*                 sont à l'état OFF.                                         */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lfbk_on_enlean_clamp;                                       */
/*  input boolean Sonde_riche_aval;                                           */
/*  input uint8 Lfbk_switch_lean_delay_count;                                 */
/*  input uint8 Lfbk_switch_lean_delay;                                       */
/*  output uint8 Lfbk_switch_lean_delay_count;                                */
/*  output boolean Lfbk_switch_lean;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidbDgoSen02AmRichBlo(void)
{
   /* 3_bDgo_Sen02_Amont_bloque_riche */
   boolean bLocalLfbkOnEnleanClamp;
   boolean bLocalSondeRicheAval;


   VEMS_vidGET(Lfbk_on_enlean_clamp, bLocalLfbkOnEnleanClamp);
   VEMS_vidGET(Sonde_riche_aval, bLocalSondeRicheAval);

   if (  (bLocalLfbkOnEnleanClamp != 0)
      && (bLocalSondeRicheAval == 0))
   {
      if (Lfbk_switch_lean_delay_count > 0)
      {
         Lfbk_switch_lean_delay_count =
            (uint8)(Lfbk_switch_lean_delay_count - 1);
      }
      else
      {
         Lfbk_switch_lean_delay_count = 0;
      }
   }
   else
   {
      Lfbk_switch_lean_delay_count = Lfbk_switch_lean_delay;
   }
   if (Lfbk_switch_lean_delay_count == 0)
   {
      Lfbk_switch_lean = 1;
   }
   else
   {
      Lfbk_switch_lean = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidbDgoAlimRichFuel                               */
/* !Description :  Cette fonction traite le cas d'un Défaut injecteur riche : */
/*                 Lfbk_on_enrich_clamp est à l'état OFF et Sonde_riche_aval  */
/*                 est à l'état ON.                                           */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lfbk_on_enlean_clamp;                                       */
/*  input boolean Sonde_riche_aval;                                           */
/*  input uint8 Lfbk_stuck_rich_delay_count;                                  */
/*  input uint8 Lfbk_stuck_rich_delay;                                        */
/*  output uint8 Lfbk_stuck_rich_delay_count;                                 */
/*  output boolean Lfbk_stuck_rich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidbDgoAlimRichFuel(void)
{
   /* 4_bDgo_Alim_Carb_riche */
   boolean bLocalLfbkOnEnleanClamp;
   boolean bLocalSondeRicheAval;


   VEMS_vidGET(Lfbk_on_enlean_clamp, bLocalLfbkOnEnleanClamp);
   VEMS_vidGET(Sonde_riche_aval, bLocalSondeRicheAval);

   if (  (bLocalLfbkOnEnleanClamp != 0)
      && (bLocalSondeRicheAval != 0))
   {
      if (Lfbk_stuck_rich_delay_count > 0)
      {
         Lfbk_stuck_rich_delay_count = (uint8)(Lfbk_stuck_rich_delay_count - 1);
      }
      else
      {
         Lfbk_stuck_rich_delay_count = 0;
      }
   }
   else
   {
      Lfbk_stuck_rich_delay_count = Lfbk_stuck_rich_delay;
   }
   if (Lfbk_stuck_rich_delay_count == 0)
   {
      Lfbk_stuck_rich = 1;
   }
   else
   {
      Lfbk_stuck_rich = 0;
   }
}
/*------------------------------- end of file --------------------------------*/