/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKINHADP                                               */
/* !Description     : KNKINHADP Component                                     */
/*                                                                            */
/* !Module          : KNKINHADP                                               */
/* !Description     : GESTION DE LA PHASE DE DECOLLAGE DANS LE BUT D’INHIBER  */
/*                    L’ADAPTATION D’AVANCE                                   */
/*                                                                            */
/* !File            : KNKINHADP_SCH.C                                         */
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
/*   1 / IgLim_EveRst_KnkInhAdp                                               */
/*   2 / IgLim_SdlMid_KnkInhAdp                                               */
/*                                                                            */
/* !Reference   : V02 NT 09 02295 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKINHADP/KNKINHADP_SCH.C_v $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   06 Jul 2009 $*/
/* $Author::   wbouach                                $$Date::   06 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "KNKINHADP.H"
#include "KNKINHADP_L.H"
#include "KNKINHADP_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_EveRst_KnkInhAdp                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINHADP_vidInitCounter();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : IgLim_EveRst_KnkInhAdp                                         */
/* !Trigger  : IgLim_EveRst_KnkInhAdp                                         */
/*                                                                            */
/* !LastAuthor  : A.BEN AMAR                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_EveRst_KnkInhAdp(void)
{
   KNKINHADP_vidInitCounter();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgLim_SdlMid_KnkInhAdp                                     */
/* !Description :  Moniteur moyen pour la fonction KnkInhAdp                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINHADP_vidUpdateCounter();                            */
/*  input uint8 KNKINHADP_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : IgLim_SdlMid_KnkInhAdp                                         */
/* !Trigger  : IgLim_SdlMid_KnkInhAdp                                         */
/*                                                                            */
/* !LastAuthor  : A.BEN AMAR                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgLim_SdlMid_KnkInhAdp(void)
{
   if (KNKINHADP_u8Inhib != 0x5A)
   {
      KNKINHADP_vidUpdateCounter();
   }
}

/*------------------------------- end of file --------------------------------*/