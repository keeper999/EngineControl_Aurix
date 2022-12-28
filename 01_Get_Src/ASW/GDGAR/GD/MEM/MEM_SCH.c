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
/* !File            : MEM_SCH.C                                               */
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
/*   1 / MEM_vidMngEveKeyOn                                                   */
/*   2 / MEM_vidMngEveRstDftObd                                               */
/*   3 / MEM_vidMngEveRstDft                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5447179 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/MEM/MEM_SCH.c_v              $*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   17 Sep 2013 $*/
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
/* !Function    :  MEM_vidMngEveKeyOn                                         */
/* !Description :  Evénement clé ON / OFF ou réveil principal de l'ECU        */
/* !Number      :  SCH.01                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5447179_001.01                                       */
/*                 PTS_R_5447179_002.01                                       */
/*                 PTS_R_5447179_003.01                                       */
/*                 VEMS_R_11_00118_001.01                                     */
/*                 VEMS_R_11_00118_002.01                                     */
/*                 VEMS_R_11_00118_003.01                                     */
/*                 VEMS_R_11_00118_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF01_DTCRec();                                     */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MEM_vidMngEveKeyOn                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveKeyOn(void)
{
   if(MEM_u8Inhib != 0x5A)
   {
      MEM_vidF01_DTCRec();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveRstDftObd                                     */
/* !Description :  Demande d'effacement des défauts OBD par le ScanTool       */
/* !Number      :  SCH.02                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5447179_001.01                                       */
/*                 PTS_R_5447179_002.01                                       */
/*                 PTS_R_5447179_003.01                                       */
/*                 VEMS_R_11_00118_001.01                                     */
/*                 VEMS_R_11_00118_002.01                                     */
/*                 VEMS_R_11_00118_003.01                                     */
/*                 VEMS_R_11_00118_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF07_RstDftObdMng();                               */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MEM_vidMngEveRstDftObd                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveRstDftObd(void)
{
   if(MEM_u8Inhib != 0x5A)
   {
      MEM_vidF07_RstDftObdMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidMngEveRstDft                                        */
/* !Description :  Requête d'effacement des défauts avec l'outil APV          */
/* !Number      :  SCH.03                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  PTS_R_5447179_001.01                                       */
/*                 PTS_R_5447179_002.01                                       */
/*                 PTS_R_5447179_003.01                                       */
/*                 VEMS_R_11_00118_001.01                                     */
/*                 VEMS_R_11_00118_002.01                                     */
/*                 VEMS_R_11_00118_003.01                                     */
/*                 VEMS_R_11_00118_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF06_RstDftMng();                                  */
/*  input uint8 MEM_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MEM_vidMngEveRstDft                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidMngEveRstDft(void)
{
   if(MEM_u8Inhib != 0x5A)
   {
      MEM_vidF06_RstDftMng();
   }
}

/*--------------------------- End of file ------------------------------------*/