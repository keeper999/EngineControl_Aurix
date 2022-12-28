/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGTAB                                                 */
/* !Description     : DIAGTAB component.                                      */
/*                                                                            */
/* !Module          : DIAGTAB                                                 */
/* !Description     : Failures Buffer for development tool                    */
/*                                                                            */
/* !File            : DIAGTAB_FCT1.C                                          */
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
/*   1 / DIAGTAB_vidInitFailuresBuffer                                        */
/*   2 / DIAGTAB_vidFillingFailuresBuffer                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 00293 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/DIAGTAB/DIAGTAB_FCT1.C_v     $*/
/* $Revision::   1.5      $$Author::   alaouni        $$Date::   04 Apr 2012 $*/
/* $Author::   alaouni                                $$Date::   04 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DIAGTAB.h"
#include "DIAGTAB_L.h"
#include "DIAGTAB_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGTAB_vidInitFailuresBuffer                              */
/* !Description :  Fonction d'initialisation du module DIAGTAB.               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  AMIRA HAMDOUN                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 GD_table_panne_event[30];                                   */
/*  output uint8 GD_table_panne_state[30];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGTAB_vidInitFailuresBuffer(void)
{
   sint32 s32LocalIndex;


   /* The failures buffer is set to “no failure stored”*/
   for (s32LocalIndex = 0;
        s32LocalIndex <= (GD_NB_DFTMEMMAX - 1);
        s32LocalIndex ++)
   {
      GD_table_panne_event[s32LocalIndex] = 0xFFFF;
      GD_table_panne_state[s32LocalIndex] = 0xFF;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGTAB_vidFillingFailuresBuffer                           */
/* !Description :  Cette fonction assure le remplissage des tables des pannes.*/
/* !Number      :  FCT1.2                                                     */
/* !Author      :  AMIRA HAMDOUN                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input boolean Manu_inh_table_panne;                                       */
/*  input uint8 GD_au8RnkFrf[400];                                            */
/*  input GD_tstrDftEep GD_astrDftEep[400];                                   */
/*  output uint16 GD_table_panne_event[30];                                   */
/*  output uint8 GD_table_panne_state[30];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGTAB_vidFillingFailuresBuffer(void)
{
   uint8   u8LocalRnkFrf;
   sint32  s32LocalIndex;
   sint32  s32DftIdx;


   /*u16DftIdx represents the failure index or Event Identifier (TypCc_NameVar)
   in the GD table failures*/
   if (Manu_inh_table_panne == 0)
   {
   /*At first the failures buffer is cleared*/
      for (s32LocalIndex = 0;
           s32LocalIndex <= (GD_NB_DFTMEMMAX - 1);
           s32LocalIndex ++) /*Failures’ buffer scanning*/
      {
         GD_table_panne_event[s32LocalIndex] = 0xFFFF;
         GD_table_panne_state[s32LocalIndex] = 0xFF;
      }
      /*Then the failures buffer is filled in according to GD table failure
      scanning order*/
      s32LocalIndex = 0;
      for (s32DftIdx = 0;
           (  (s32DftIdx < GD_DFT_NB)
           && (s32LocalIndex < GD_NB_DFTMEMMAX));
           s32DftIdx ++) /*GD table failure scanning*/
      {
         VEMS_vidGET1DArrayElement(GD_au8RnkFrf, s32DftIdx, u8LocalRnkFrf);
         if (u8LocalRnkFrf != 0xFF) /*A DTC is stored*/
         {
            /*Getting the Event Identifier*/
            GD_table_panne_event[s32LocalIndex] = (uint16)s32DftIdx;
            /*Getting the failure state according to Event Identifier*/
            GD_table_panne_state[s32LocalIndex] =
               GD_astrDftEep[s32DftIdx].enuStDgo;
            s32LocalIndex = s32LocalIndex + 1;
         }
      }
   }
}

/*------------------------------- end of file --------------------------------*/