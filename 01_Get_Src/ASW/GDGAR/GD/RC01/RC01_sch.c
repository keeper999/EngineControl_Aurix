/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RC01                                                    */
/* !Description     : RC01 Component                                          */
/*                                                                            */
/* !Module          : RC01                                                    */
/* !Description     : Gestion des Readiness Codes 01                          */
/*                                                                            */
/* !File            : RC01_SCH.C                                              */
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
/*   1 / GD_EveRst_Rdy                                                        */
/*   2 / RC01_vidMngEveGlbDCStrt                                              */
/*   3 / GD_EveRstDft_Rdy                                                     */
/*   4 / GD_EveRstDftObd_Rdy                                                  */
/*   5 / RC01_vidMngEveRstDft                                                 */
/*   6 / RC01_vidExitEveStObdRec                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5263162 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065983                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/RC01/RC01_sch.c_v            $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "RC01.h"
#include "RC01_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_Rdy                                              */
/* !Description :  Evènement reset de l'ECU                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RC01_vidF01_Rdy_Init();                                  */
/*  extf argret void RC01_vidF00_Def_Prio_Init();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_Rdy                                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_Rdy(void)
{
   RC01_vidF01_Rdy_Init();
   RC01_vidF00_Def_Prio_Init();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidMngEveGlbDCStrt                                    */
/* !Description :  Evènement de démarrage d'un nouveau Driving Cycle Global   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RC01_vidF02_Rdy_ValRdy();                                */
/*  extf argret void RC01_vidF04_Rdy_ValClasRdy();                            */
/*  input uint8 RC01_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RC01_vidMngEveGlbDCStrt                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidMngEveGlbDCStrt(void)
{
   if(RC01_u8Inhib != 0x5A)
   {
      RC01_vidF02_Rdy_ValRdy();
      RC01_vidF04_Rdy_ValClasRdy();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft_Rdy                                           */
/* !Description :  Requête d'effacement des défauts avec l'outil APV          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RC01_vidF03_Rdy_ReinitRdy();                             */
/*  input uint8 RC01_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDft_Rdy                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft_Rdy(void)
{
   if(RC01_u8Inhib != 0x5A)
   {
      RC01_vidF03_Rdy_ReinitRdy();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDftObd_Rdy                                        */
/* !Description :  Requête d'effacement des défauts OBD par le ScanTool       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RC01_vidF03_Rdy_ReinitRdy();                             */
/*  input uint8 RC01_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDftObd_Rdy                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDftObd_Rdy(void)
{
   if(RC01_u8Inhib != 0x5A)
   {
      RC01_vidF03_Rdy_ReinitRdy();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidMngEveRstDft                                       */
/* !Description :  Demande d'effacement Manuel des défauts                    */
/* !Number      :  SCH.5                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RC01_vidF03_Rdy_ReinitRdy();                             */
/*  input uint8 RC01_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RC01_vidMngEveRstDft                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidMngEveRstDft(void)
{
   if (RC01_u8Inhib != 0x5A)
   {
      RC01_vidF03_Rdy_ReinitRdy();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidExitEveStObdRec                                    */
/* !Description :  Evènement entrée du Gestionnaire OBD dans l'état           */
/*                 GOBD_ST_ENREGISTRE                                         */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RC01_vidF06_Rdy_ValClasRdyCfOBD(argin uint16 u16IdxDft); */
/*  input uint8 RC01_u8Inhib;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RC01_vidExitEveStObdRec                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidExitEveStObdRec(uint16 u16IdxDft)
{
   if (RC01_u8Inhib != 0x5A)
   {
      RC01_vidF06_Rdy_ValClasRdyCfOBD(u16IdxDft);
   }
}

/*--------------------------------- end of file ------------------------------*/