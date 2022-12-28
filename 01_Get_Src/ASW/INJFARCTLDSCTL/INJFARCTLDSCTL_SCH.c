/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLDSCTL                                          */
/* !Description     : INJFARCTLDSCTL Component                                */
/*                                                                            */
/* !Module          : INJFARCTLDSCTL                                          */
/* !Description     : REGULATION DE RICHESSE PAR LA SONDE A OXYGENE AVAL      */
/*                    (DOUBLE BOUCLE)                                         */
/*                                                                            */
/* !File            : INJFARCTLDSCTL_SCH.C                                    */
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
/*   1 / InjCtl_EveRst_InjFarCtlDsCtl                                         */
/*   2 / InjCtl_SdlMid_InjFarCtlDsCtl                                         */
/*   3 / InjCtl_SdlFast_InjFarCtlDsCtl                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 05886 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJ/INJCTL/INJFARCTLDSCTL/INJFARCT$*/
/* $Revision::   1.7      $$Author::   ACHEBINO       $$Date::   16 Jan 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   16 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INJFARCTLDSCTL.h"
#include "INJFARCTLDSCTL_L.h"
#include "INJFARCTLDSCTL_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRst_InjFarCtlDsCtl                               */
/* !Description :  Reset du calculateur                                       */
/* !Number      :  SCH.1                                                      */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_E_08_05886_006.01                                     */
/*                 VEMS_E_08_05886_007.01                                     */
/*                 VEMS_E_08_05886_008.01                                     */
/*                 VEMS_E_08_05886_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLDSCTL_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TInjCtl_EveRst_InjFarCtlDsCtl                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRst_InjFarCtlDsCtl(void)
{
   INJFARCTLDSCTL_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlMid_InjFarCtlDsCtl                               */
/* !Description :  Moniteur medium pour la fonction injection                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_E_08_05886_006.01                                     */
/*                 VEMS_E_08_05886_007.01                                     */
/*                 VEMS_E_08_05886_008.01                                     */
/*                 VEMS_E_08_05886_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLDSCTL_vidDecrEntryDly();                        */
/*  extf argret void INJFARCTLDSCTL_vidCalculationMod();                      */
/*  input uint8 INJFARCTLDSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_SdlMid_InjFarCtlDsCtl                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlMid_InjFarCtlDsCtl(void)
{
   if (INJFARCTLDSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLDSCTL_vidDecrEntryDly();
      INJFARCTLDSCTL_vidCalculationMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlFast_InjFarCtlDsCtl                              */
/* !Description :  Moniteur rapide pour la fonction injection                 */
/* !Number      :  SCH.3                                                      */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_E_08_05886_006.01                                     */
/*                 VEMS_E_08_05886_007.01                                     */
/*                 VEMS_E_08_05886_008.01                                     */
/*                 VEMS_E_08_05886_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLDSCTL_vidManager();                             */
/*  extf argret void INJFARCTLDSCTL_vidDecSettlingDly();                      */
/*  extf argret void INJFARCTLDSCTL_vidDownstreamCond();                      */
/*  input uint8 INJFARCTLDSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_SdlFast_InjFarCtlDsCtl                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlFast_InjFarCtlDsCtl(void)
{
   if (INJFARCTLDSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLDSCTL_vidManager();
      INJFARCTLDSCTL_vidDecSettlingDly();
      INJFARCTLDSCTL_vidDownstreamCond();
   }
}

/*------------------------------- end of file --------------------------------*/