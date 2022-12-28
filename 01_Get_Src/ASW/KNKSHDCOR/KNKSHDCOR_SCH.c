/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKSHDCOR                                               */
/* !Description     : KNKSHDCOR Component                                     */
/*                                                                            */
/* !Module          : KNKSHDCOR                                               */
/* !Description     : Correction palliative de cliquetis                      */
/*                                                                            */
/* !File            : KNKSHDCOR_SCH.C                                         */
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
/*   1 / IgLim_EveRst_ShdCor                                                  */
/*   2 / IgLim_EveCkSnOn_ShdCor                                               */
/*   3 / IgLim_EveBDC_ShdCor                                                  */
/*                                                                            */
/* !Reference: V02 NT 08 07294 / 03                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKSHDCOR/KNKSHDCOR_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   vgarnier       $$Date::   25 Mar 2010 $*/
/* $Author::   vgarnier                               $$Date::   25 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "KNKSHDCOR.H"
#include "KNKSHDCOR_L.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : IgLim_EveRst_ShdCor                                         */
/* !Description : Evénement reset du calculateur                              */
/* !Number      : SCH.1                                                       */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void KNKSHDCOR_vidInit();                                    */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : IgLim_EveRst_ShdCor                                            */
/* !Trigger  : IgLim_EveRst_ShdCor                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRst_ShdCor(void)
{
   KNKSHDCOR_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : IgLim_EveCkSnOn_ShdCor                                      */
/* !Description : Evénement correspondant au passage à 1 de la variable       */
/*                Moteur_synchronise                                          */
/* !Number      : SCH.2                                                       */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void KNKSHDCOR_vidInit();                                    */
/*   input uint8 KNKSHDCOR_u8Inhib;                                           */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : IgLim_EveCkSnOn_ShdCor                                         */
/* !Trigger  : IgLim_EveCkSnOn_ShdCor                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveCkSnOn_ShdCor(void)
{
   if (KNKSHDCOR_u8Inhib != 0x5A)
   {
      KNKSHDCOR_vidInit();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : IgLim_EveBDC_ShdCor                                         */
/* !Description : Interruption PMB                                            */
/* !Number      : SCH.3                                                       */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void KNKSHDCOR_vidCorr_manager();                            */
/*   input uint8 KNKSHDCOR_u8Inhib;                                           */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : IgLim_EveBDC_ShdCor                                            */
/* !Trigger  : IgLim_EveBDC_ShdCor                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveBDC_ShdCor(void)
{
   if (KNKSHDCOR_u8Inhib != 0x5A)
   {
      KNKSHDCOR_vidCorr_manager();
   }
}
/*------------------------------- end of file --------------------------------*/