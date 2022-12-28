/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CANSECUCHKDATA                                          */
/* !Description     : CANSECUCHKDATA component.                               */
/*                                                                            */
/* !Module          : CANSECUCHKDATA                                          */
/* !Description     : LIBRAIRIE : CONTRÔLE TRAME CRITIQUE                     */
/*                                                                            */
/* !File            : cansecuchkdata_api.c                                    */
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
/*   1 / CanSecuChkData                                                       */
/*   2 / CanSecuCalcChecksum                                                  */
/*                                                                            */
/* !Reference   : V02 NT 09 05149 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#059529                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CANSECUCHKDATA/CANSECUCHKDATA_AP$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   27 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   27 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "CANSECUCHKDATA.h"
#include "STD_TYPES.h"
#include "MATHSRV.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CanSecuChkData                                             */
/* !Description :  Cette fonction calcul la somme des quartets d’une trame    */
/*                 plus une constante d’initialisation modulo 16. Une trame   */
/*                 vérifiant cette cohérence rendra toujours un résultat de   */
/*                 Fh.                                                        */
/* !Number      :  1.1                                                        */
/* !Author      :  hgharian                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : B.Safi                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CanSecuChkData(uint8 CHKini,
                    const uint8 DataFrame[DATAFRAME_COLS],
                    uint8 Size,
                    uint8 *Result,
                    boolean *Chk_ok)
{
   uint8 u8LocalIndex;
   uint8 u8LocalSize;


   * Result = (uint8)(CHKini & 0x0F);

   u8LocalSize = (uint8)MATHSRV_udtMIN(Size, 8);
   for(u8LocalIndex = 1; u8LocalIndex <= u8LocalSize; u8LocalIndex++)
   {
      *Result =
         (uint8)((uint8)(*Result + (uint8)(DataFrame[u8LocalIndex - 1] / 16))
                + (uint8)(DataFrame[u8LocalIndex - 1] & 0x0F));
   }

   *Result =(uint8)(*Result & 0x0F);

   if (*Result == 15)
   {
      *Chk_ok = 1;
   }
   else
   {
      *Chk_ok = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CanSecuCalcChecksum                                        */
/* !Description :  Cette fonction calcule la valeur que doit prendre le       */
/*                 quartet du checksum dans la trame.                         */
/* !Number      :  1.2                                                        */
/* !Author      :  hgharian                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CanSecuCalcChecksum(uint8 CHKini,
                    const uint8 DataFrame[DATAFRAME_COLS],
                    uint8 Size,
                    uint8 *Result)
{
   uint8 u8LocalIndex;
   uint8 u8LocalSize;

   * Result = (uint8)(CHKini & 0x0F);

   u8LocalSize = (uint8)MATHSRV_udtMIN(Size, 8);
   for(u8LocalIndex = 1; u8LocalIndex <= u8LocalSize; u8LocalIndex++)
   {
      *Result =
         (uint8)((uint8)(*Result + (uint8)(DataFrame[u8LocalIndex - 1] / 16))
                + (uint8)(DataFrame[u8LocalIndex - 1] & 0x0F));
   }

   *Result =(uint8)(0x0F - (*Result & 0x0F));
}
/*------------------------------- end of file --------------------------------*/