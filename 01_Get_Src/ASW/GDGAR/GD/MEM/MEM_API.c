/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MEM                                                     */
/* !Description     : MEM Component                                           */
/*                                                                            */
/* !Module          : MEM                                                     */
/* !Description     : MEMORISATION DES PARAMETRES DEFAUTS                     */
/*                                                                            */
/* !File            : MEM_API.C                                               */
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
/*   1 / MEM_vidMngEveInit                                                    */
/*   2 / MEM_vidMngEveDftClr                                                  */
/*   3 / MEM_vidMngEveRstDftCal                                               */
/*   4 / MEM_vidMngEveFrfRec                                                  */
/*   5 / MEM_vidMngEveCDThUp                                                  */
/*   6 / MEM_vidMngEveStObdRec                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5447179 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/MEM/MEM_API.c_v              $*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   17 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "SWFAIL.h"
#include "MEM_L.h"
#include "MEM.h"
#include "MEM_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveInit                                          */
/* !Description :  Effacement de tous les DTC                                 */
/* !Number      :  API.01                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF01_Init();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveInit(void)
{
   MEM_vidF01_Init();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveDftClr                                        */
/* !Description :  Evenement effacement des paramètres défauts enregistrés    */
/* !Number      :  API.02                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF04_RstnoRnkFrf(argin uint16 u16IdxDft);          */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveDftClr
(
   uint16 u16IdxDft
)
{
   if (MEM_u8Inhib != 0x5A)
   {
      MEM_vidF04_RstnoRnkFrf(u16IdxDft);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveRstDftCal                                     */
/* !Description :  Demande d'effacement Manuel des défauts                    */
/* !Number      :  API.03                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF06_RstDftMng();                                  */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveRstDftCal(void)
{
   if(MEM_u8Inhib != 0x5A)
   {
      MEM_vidF06_RstDftMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveFrfRec                                        */
/* !Description :  Evènement moment de mémorisation de la Freeze Frame        */
/* !Number      :  API.04                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF01_FrzData(argin uint16 u16IdxDft);              */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveFrfRec
(
   uint16 u16IdxDft
)
{
   if(MEM_u8Inhib != 0x5A)
   {
      MEM_vidF01_FrzData(u16IdxDft);
   }
}/* mettre a jour MEM_macro.h si cette fonction evolue*/


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveCDThUp                                        */
/* !Description :  Evenement GDU notifiant le franchissement du seuil         */
/* !Number      :  API.05                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF02_StoreDataFrf(argin uint16 u16IdxDft);         */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveCDThUp
(
   uint16 u16IdxDft
)
{
   if (MEM_u8Inhib != 0x5A)
   {
      MEM_vidF02_StoreDataFrf(u16IdxDft);
   }
}/* mettre a jour MEM_macro.h si cette fonction evolue*/


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveStObdRec                                      */
/* !Description :  Evènement entrée du Gestionnaire OBD dans l'état           */
/*                 GOBD_ST_ENREGISTRE                                         */
/* !Number      :  API.06                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF04_StoreFrfObd(argin uint16 u16IdxDft);          */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveStObdRec
(
   uint16 u16IdxDft
)
{
   if (MEM_u8Inhib != 0x5A)
   {
      MEM_vidF04_StoreFrfObd(u16IdxDft);
   }
}
/*--------------------------- End of file ------------------------------------*/