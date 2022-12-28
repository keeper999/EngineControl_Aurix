/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : LIBSFTYLVL2                                             */
/* !Description     : MATH SERVICES                                           */
/*                                                                            */
/* !Module          : LIBSFTYLVL2                                             */
/* !Description     : DIAGNOSTIC LEVEL 2                                      */
/*                                                                            */
/* !File            : LIBSFTYLVL2.C                                           */
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
/*   1 / LIBSFTYLVL2_U8_Safety_Level2                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 04106 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/LIBSFTYLVL2/LIBSFTYLVL2.C_v     $*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "Std_Types.h"
#include "MATHSRV.H"
#include "LIBSFTYLVL2.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  LIBSFTYLVL2_U8_Safety_Level2                               */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ	                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void LIBSFTYLVL2_U8_Safety_Level2
(
   boolean RawSig,
   uint8   UpTranThd_C,
   uint8   DownTranThd_C,
   uint8   InitCptConf_C,
   uint8   DecCpt_C,
   uint8   *Counter_Filter,
   boolean *FilSig,
   uint8   *CountNiv2,
   boolean *bDgoNiv2
)
{
   uint8  u8LocalThd;
   uint16 u16LocalCounter;
   sint16 s16LocalDifference;


   if (RawSig != *FilSig)
   {
      if (RawSig == 0)
      {
         u8LocalThd = DownTranThd_C;
      }
      else
      {
         u8LocalThd = UpTranThd_C;
      }
      u16LocalCounter = (uint16)(*Counter_Filter + 1);
      *Counter_Filter = (uint8)MATHSRV_udtMIN(u16LocalCounter, 255);
      if (*Counter_Filter >= u8LocalThd)
      {
         *FilSig = RawSig;
         *Counter_Filter = 0;
      }
   }
   else
   {
      *Counter_Filter = 0;
   }
   if (*FilSig != 0)
   {
      s16LocalDifference = (sint16)(*CountNiv2 - DecCpt_C);
      *CountNiv2 = (uint8)MATHSRV_udtCLAMP(s16LocalDifference, 0, 255);
      if (*CountNiv2 == 0)
      {
         *bDgoNiv2 = 1;
      }
      else
      {
         *bDgoNiv2 = 0;
      }
   }
   else
   {
      *CountNiv2 = InitCptConf_C;
      *bDgoNiv2 = 0;
   }
}
/*------------------------------- end of file --------------------------------*/