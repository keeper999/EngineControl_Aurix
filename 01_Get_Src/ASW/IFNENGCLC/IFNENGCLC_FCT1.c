/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFNENGCLC                                               */
/* !Description     : IFNENGCLC component                                     */
/*                                                                            */
/* !Module          : IFNENGCLC                                               */
/* !Description     : Interface modulaire du calcul du régime pour le régime  */
/*                    recentré                                                */
/*                                                                            */
/* !File            : IFNENGCLC_FCT1.C                                        */
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
/*   1 / IFNENGCLC_vidInitOutput                                              */
/*   2 / IFNENGCLC_vidTDCGeneration                                           */
/*   3 / IFNENGCLC_vidBDCGeneration                                           */
/*   4 / IFNENGCLC_vidTDCEngineSpeed                                          */
/*   5 / IFNENGCLC_vidBDCEngineSpeed                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 03031 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IFNENGCLC/IFNENGCLC_FCT1.C_v      $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   31 Jan 2011 $*/
/* $Author::   wbouach                                $$Date::   31 Jan 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IFNENGCLC.h"
#include "IFNENGCLC_L.h"
#include "IFNENGCLC_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFNENGCLC_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Sync_nEngClc;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFNENGCLC_vidInitOutput(void)
{
   VEMS_vidSET(Sync_nEngClc, 0);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFNENGCLC_vidTDCGeneration                                 */
/* !Description :  Génération de l'évènement PMH.                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFNENGCLC_vidTDCEngineSpeed();                           */
/*  input boolean Sync_bAcvBDCEngSpdClcn_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFNENGCLC_vidTDCGeneration(void)
{
   if (Sync_bAcvBDCEngSpdClcn_C == 0)
   {
      IFNENGCLC_vidTDCEngineSpeed();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFNENGCLC_vidBDCGeneration                                 */
/* !Description :  Génération de l'évènement PMB.                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFNENGCLC_vidBDCEngineSpeed();                           */
/*  input boolean Sync_bAcvBDCEngSpdClcn_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFNENGCLC_vidBDCGeneration(void)
{
   if (Sync_bAcvBDCEngSpdClcn_C != 0)
   {
      IFNENGCLC_vidBDCEngineSpeed();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFNENGCLC_vidTDCEngineSpeed                                */
/* !Description :  Production du régime moteur recentré à partir du régime    */
/*                 moteur.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEngTDC;                                                 */
/*  output uint16 Sync_nEngClc;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFNENGCLC_vidTDCEngineSpeed(void)
{
   uint16 u16LocalExt_nEngTDC;
   uint16 u16LocalSync_nEngClc;


   VEMS_vidGET(Ext_nEngTDC, u16LocalExt_nEngTDC);

   u16LocalSync_nEngClc = (uint16)MATHSRV_udtMIN(u16LocalExt_nEngTDC, 8000);

   VEMS_vidSET(Sync_nEngClc, u16LocalSync_nEngClc);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFNENGCLC_vidBDCEngineSpeed                                */
/* !Description :  Production du régime moteur recentré à partir du régime    */
/*                 moteur au PMB.                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mimouni                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEngBDC;                                                 */
/*  output uint16 Sync_nEngClc;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFNENGCLC_vidBDCEngineSpeed(void)
{
   uint16 u16LocalExt_nEngBDC;


   VEMS_vidGET(Ext_nEngBDC, u16LocalExt_nEngBDC);

   u16LocalExt_nEngBDC = (uint16)MATHSRV_udtMIN(u16LocalExt_nEngBDC, 8000);

   VEMS_vidSET(Sync_nEngClc, u16LocalExt_nEngBDC);
}
/*------------------------------- end of file --------------------------------*/