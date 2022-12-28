/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRC                                                     */
/* !Description     : CRC component                                           */
/*                                                                            */
/* !Module          : CRC                                                     */
/* !Description     : Cyclic Redundancy Check                                 */
/*                                                                            */
/* !File            : CRC_fct1.c                                              */
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
/*   1 / CRC_vidCalcCrc                                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CRC/CRC_FCT1.C_v                  $*/
/* $Revision::   1.1           $$Author::   srobart  $$Date::   22 Jul 2009 2$*/
/******************************************************************************/

#include "STD_Types.h"
#include "CRC.h"
#include "CRC_L.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Calculates the CRC of the frame                             */
/* !Number      : FCT2.1                                                      */
/* !Reference   : V02 NT 09 03344 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  :  VIAS (DFAH)                                                */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRC_vidCalcCrc
(
   const uint8  * DataPtr,

   uint32 DataLength,

   uint16* ComputedCrc

)
{
   uint16  u16LocalCrc;
   uint8   u8LocalCptBit;
   uint32  u32LocalCptDat;
   uint8   u8LocalCopyData;


   u16LocalCrc = CRC_u16CRC_BEGIN_VALUE;

   for (u32LocalCptDat = 0; u32LocalCptDat < DataLength; u32LocalCptDat++)
   {
      u8LocalCopyData = DataPtr[u32LocalCptDat];
      for  (u8LocalCptBit=0; u8LocalCptBit < 8; u8LocalCptBit++)
      {
         if (((u16LocalCrc & 0x01) ^ (u8LocalCopyData & 0x01)) == 1)
         {
            u16LocalCrc = u16LocalCrc >> 1;
            u16LocalCrc = (u16LocalCrc) ^ (CRC_u16POLYNOME);
         }
         else
         {
            u16LocalCrc = u16LocalCrc >> 1;
         }
         u8LocalCopyData = u8LocalCopyData >> 1;
      }
   }
   *ComputedCrc = u16LocalCrc;
}


/*QAC Warning Msg(2:0838): Due to the multiple inclusion of MemMap.h file  */

/*-------------------------------- end of file -------------------------------*/
/*QAC Warning Msg(2:0862): Due to Inclusion of MemMap.h                    */
