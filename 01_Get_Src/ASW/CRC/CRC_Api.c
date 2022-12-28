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
/* !File            : CRC_API.c                                               */
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
/*   1 / CRC_vidComputation                                                   */
/*   2 / CRC_bCheck                                                           */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CRC/CRC_Api.C_v                   $*/
/* $Revision::   1.3          $$Author::   vvoyer $$Date::   23 Jul 2009 09:4$*/
/******************************************************************************/

#include "STD_Types.h"
#include "CRC.h"
#include "CRC_L.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Calculates the CRC of the frame                             */
/* !Number      : API1.1                                                      */
/* !Reference   : V02 NT 09 03344 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*   extf argret void CRC_vidCalcCrc(argin const uint8 * DataPtr, argin uint32*/
/*   DataLength, argio uint16 * ComputedCrc );                                */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  VIAS (DFAH)                                                */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CRC_vidComputation
(
   uint8  * DataPtr,

   uint32 DataLength,

   uint16* ComputedCrc

)

{
   CRC_vidCalcCrc(DataPtr, DataLength, ComputedCrc);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Check the CRC of the frame                                  */
/* !Number      : API1.2                                                      */
/* !Reference   : V02 NT 09 03344 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*   extf argret void CRC_vidCalcCrc(argin const uint8 * DataPtr, argin uint32*/
/*   DataLength, argio uint16 * ComputedCrc );                                */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  VIAS (DFAH)                                                */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/

boolean CRC_bCheck
(
   uint8* DataPtr,

   uint32 DataLength,

   uint16 ExpectedCrc

)

{
   uint16  u16LocalCrc;
   boolean bLocalCheck;

   CRC_vidCalcCrc(DataPtr, DataLength, &u16LocalCrc);

   if( u16LocalCrc != ExpectedCrc)
   {
      bLocalCheck = CRC_u8CRC_NOK;
   }
   else
   {
      bLocalCheck = CRC_u8CRC_OK;
   }
   return bLocalCheck;
}

/*QAC Warning Msg(2:0838): Due to the multiple inclusion of MemMap.h file  */
/*-------------------------------- end of file -------------------------------*/
/*QAC Warning Msg(2:0862): Due to Inclusion of MemMap.h                    */
