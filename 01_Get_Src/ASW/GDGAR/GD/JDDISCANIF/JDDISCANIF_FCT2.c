/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : JDDISCANIF                                              */
/* !Description     : JDDISCANIF Component                                    */
/*                                                                            */
/* !Module          : JDDISCANIF                                              */
/* !Description     : SPECIFICATION D'INTERFACE ENTRE LE JDD ET L'ISCAN       */
/*                                                                            */
/* !File            : JDDISCANIF_FCT2.C                                       */
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
/*   1 / JDDISCANIF_vid1Trame                                                 */
/*   2 / JDDISCANIF_vid3Trames                                                */
/*   3 / JDDISCANIF_vidRemplissageTrame1                                      */
/*   4 / JDDISCANIF_vidRemplissageTrame2                                      */
/*   5 / JDDISCANIF_vidRemplissageTrame3                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 02911 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#054516                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/JDDISCANIF/JDDISCANIF_FCT2.C_v  $*/
/* $Revision::   1.0      $$Author::   fguillon       $$Date::   14 Jun 2011 $*/
/* $Author::   fguillon                               $$Date::   14 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "JDDISCANIF.h"
#include "JDDISCANIF_L.h"
#include "JDDISCANIF_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vid1Trame                                       */
/* !Description :  Cette fonction permet d'envoyer une trame lorsque le defaut*/
/*                 est fugitifs                                               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Jbsi_code_defaut;                                            */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vid1Trame(void)
{
   uint8  u8LocalPos3;
   uint8  u8LocalPos2;
   uint32 u32LocalJbsi_code_defaut;


   VEMS_vidGET(Jbsi_code_defaut, u32LocalJbsi_code_defaut);
   u8LocalPos3 = (uint8)((u32LocalJbsi_code_defaut & 0xFF00) >> 8);
   u8LocalPos2 = (uint8)((u32LocalJbsi_code_defaut & 0xFF0000) >> 16);

   VEMS_vidSET(Jbsi_IscanBufferPos3, u8LocalPos3);
   VEMS_vidSET(Jbsi_IscanBufferPos2, u8LocalPos2);
   VEMS_vidSET(Jbsi_IscanBufferPos4, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos5, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos6, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos7, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos8, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vid3Trames                                      */
/* !Description :  cette fonction envoie trois trames lorsque le défaut est   */
/*                 present.                                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDDISCANIF_vidRemplissageTrame1();                       */
/*  extf argret void JDDISCANIF_vidRemplissageTrame2();                       */
/*  extf argret void JDDISCANIF_vidRemplissageTrame3();                       */
/*  input uint8 Jbsi_numero_trame;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vid3Trames(void)
{
   uint8 u8LocalJbsi_numero_trame;


   VEMS_vidGET(Jbsi_numero_trame, u8LocalJbsi_numero_trame);
   if (u8LocalJbsi_numero_trame == 1)
   {
      JDDISCANIF_vidRemplissageTrame1();
   }
   else
   {
      if (u8LocalJbsi_numero_trame == 2)
      {
         JDDISCANIF_vidRemplissageTrame2();
      }
      else
      {
         if ( u8LocalJbsi_numero_trame == 3)
         {
            JDDISCANIF_vidRemplissageTrame3();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidRemplissageTrame1                            */
/* !Description :  Cette fonction permet de remplir la 1 trame en cas d'un    */
/*                 défaut.                                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Jbsi_Lbd_closed_loop;                                         */
/*  input uint32 Jbsi_code_defaut;                                            */
/*  input uint8 Jbsi_Ld_feedback;                                             */
/*  input uint8 Jbsi_engine_air_load;                                         */
/*  input uint8 Jbsi_tCoMes;                                                  */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidRemplissageTrame1(void)
{
   uint8  u8LocalPos3;
   uint8  u8LocalPos2;
   uint8  u8LocalJbsi_Lbd_closed_loop;
   uint8  u8LocalJbsi_Ld_feedback;
   uint8  u8LocalJbsi_engine_air_load;
   uint8  u8LocalJbsi_tCoMes;
   uint32 u32LocalJbsi_code_defaut;


   VEMS_vidGET(Jbsi_Lbd_closed_loop, u8LocalJbsi_Lbd_closed_loop);
   VEMS_vidSET(Jbsi_IscanBufferPos4, u8LocalJbsi_Lbd_closed_loop);

   VEMS_vidGET(Jbsi_code_defaut, u32LocalJbsi_code_defaut);
   u8LocalPos3 = (uint8)((u32LocalJbsi_code_defaut & 0xFF00) >> 8);
   u8LocalPos2 = (uint8)((u32LocalJbsi_code_defaut & 0xFF0000) >> 16);
   VEMS_vidSET(Jbsi_IscanBufferPos2, u8LocalPos2);
   VEMS_vidSET(Jbsi_IscanBufferPos3, u8LocalPos3);

   VEMS_vidGET(Jbsi_Ld_feedback, u8LocalJbsi_Ld_feedback);
   VEMS_vidGET(Jbsi_engine_air_load, u8LocalJbsi_engine_air_load);
   VEMS_vidGET(Jbsi_tCoMes, u8LocalJbsi_tCoMes);

   VEMS_vidSET(Jbsi_IscanBufferPos5, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos6, u8LocalJbsi_engine_air_load);
   VEMS_vidSET(Jbsi_IscanBufferPos7, u8LocalJbsi_tCoMes);
   VEMS_vidSET(Jbsi_IscanBufferPos8, u8LocalJbsi_Ld_feedback);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidRemplissageTrame2                            */
/* !Description :  Cette fonction permet de remplir la 2 trame en cas d'un    */
/*                 défaut.                                                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Jbsi_Correct_lente;                                           */
/*  input uint8 Jbsi_pDsThrMes;                                               */
/*  input uint16 Jbsi_nEng;                                                   */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidRemplissageTrame2(void)
{
   uint8  u8LocalPos7;
   uint8  u8LocalPos8;
   uint8  u8LocalJbsi_Correct_lente;
   uint8  u8LocalJbsi_pDsThrMes;
   uint16 u16LocalJbsi_nEng;

   VEMS_vidGET(Jbsi_Correct_lente, u8LocalJbsi_Correct_lente);
   VEMS_vidGET(Jbsi_pDsThrMes, u8LocalJbsi_pDsThrMes);
   VEMS_vidGET(Jbsi_nEng, u16LocalJbsi_nEng);

   u8LocalPos8 = (uint8)(u16LocalJbsi_nEng & 0xFF);
   u8LocalPos7 = (uint8)((u16LocalJbsi_nEng & 0xFF00) >> 8);

   VEMS_vidSET(Jbsi_IscanBufferPos2, u8LocalJbsi_Correct_lente);
   VEMS_vidSET(Jbsi_IscanBufferPos3, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos4, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos5, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos6, u8LocalJbsi_pDsThrMes);
   VEMS_vidSET(Jbsi_IscanBufferPos7, u8LocalPos7);
   VEMS_vidSET(Jbsi_IscanBufferPos8, u8LocalPos8);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidRemplissageTrame3                            */
/* !Description :  Cette fonction permet de remplir la 3 trame en cas d'un    */
/*                 défaut.                                                    */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Jbsi_spdVeh;                                                  */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidRemplissageTrame3(void)
{
   uint8 u8LocalJbsi_spdVeh;


   VEMS_vidGET(Jbsi_spdVeh, u8LocalJbsi_spdVeh);

   VEMS_vidSET(Jbsi_IscanBufferPos2, u8LocalJbsi_spdVeh);
   VEMS_vidSET(Jbsi_IscanBufferPos3, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos4, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos5, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos6, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos7, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos8, 0);
}
/*------------------------------- end of file --------------------------------*/