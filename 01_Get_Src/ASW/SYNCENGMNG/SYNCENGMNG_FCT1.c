/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCENGMNG                                              */
/* !Description     : SYNCENGMNG component.                                   */
/*                                                                            */
/* !Module          : SYNCENGMNG                                              */
/* !Description     : GESTION DE LA SYNCHRONISATION MOTEUR.                   */
/*                                                                            */
/* !File            : SYNCENGMNG_FCT1.C                                       */
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
/*   1 / SYNCENGMNG_vidInitOutput                                             */
/*   2 / SYNCENGMNG_vidIniAPI                                                 */
/*   3 / SYNCENGMNG_vidEngSyncVld                                             */
/*   4 / SYNCENGMNG_vidEngSyncLost                                            */
/*   5 / SYNCENGMNG_vidIniInCmSen                                             */
/*   6 / SYNCENGMNG_vidIniExCmSen                                             */
/*   7 / SYNCENGMNG_vidInitSync                                               */
/*   8 / SYNCENGMNG_vidInitDesync                                             */
/*                                                                            */
/* !Reference: V02 NT 09 03299 / 03                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCENGMNG/SYNCENGMNG_FCT1.C_$*/
/* $Revision::   1.5      $$Author::   hmelloul       $$Date::   02 Apr 2010 $*/
/* $Author::   hmelloul                               $$Date::   02 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "SYNCENGMNG.h"
#include "SYNCENGMNG_L.h"
#include "SYNCENGMNG_IM.h"
#include "CRKHAL.h"
#include "CAMHAL.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidInitOutput                                    */
/* !Description : Fonction d'initialisation des sorties                       */
/* !Number      : FCT1.1                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   output boolean Moteur_synchronise;                                       */
/*   output boolean Ext_bSync;                                                */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidInitOutput(void)
{
   VEMS_vidSET(Moteur_synchronise, 0);
   VEMS_vidSET(Ext_bSync, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidIniAPI                                        */
/* !Description : Fonction de demande synchronisation moteur                  */
/* !Number      : FCT1.2                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void SYNCENGMNG_vidIniInCmSen();                             */
/*   extf argret void SYNCENGMNG_vidIniExCmSen();                             */
/*   input boolean Ext_bPresInCmSen;                                          */
/*   input boolean Ext_bPresExCmSen;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidIniAPI(void)
{
   boolean bLocalExt_bPresInCmSen;
   boolean bLocalExt_bPresExCmSen;


   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
   VEMS_vidGET(Ext_bPresExCmSen, bLocalExt_bPresExCmSen);
   if (bLocalExt_bPresInCmSen != 0)
   {
      SYNCENGMNG_vidIniInCmSen();
   }
   if (bLocalExt_bPresExCmSen != 0)
   {
      SYNCENGMNG_vidIniExCmSen();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidEngSyncVld                                    */
/* !Description : Fonction d'autorisation de détection de fronts              */
/* !Number      : FCT1.3                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   output boolean Moteur_synchronise;                                       */
/*   output boolean Ext_bSync;                                                */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidEngSyncVld(void)
{
   VEMS_vidSET(Moteur_synchronise, 1);
   VEMS_vidSET(Ext_bSync, 1);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidEngSyncLost                                   */
/* !Description : Fonction qui permet la recherche de synchronisation         */
/* !Number      : FCT1.4                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   output boolean Moteur_synchronise;                                       */
/*   output boolean Ext_bSync;                                                */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidEngSyncLost(void)
{
   VEMS_vidSET(Moteur_synchronise, 0);
   VEMS_vidSET(Ext_bSync, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidIniInCmSen                                    */
/* !Description : initialisation de CAMHAL_udtEnableSynchronisation (pour     */
/*                l'admission)                                                */
/* !Number      : FCT1.5                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret Std_ReturnType  CAMHAL_udtEnableSynchronisation(argin        */
/*   CAMHAL_tudtChannel udtChannel);                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidIniInCmSen(void)
{
   (void)CAMHAL_udtEnableSynchronisation(CAMHAL_udtCH_INTAKE_CAMSHAFT);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidIniExCmSen                                    */
/* !Description : initialisation de CAMHAL_udtEnableSynchronisation (pour     */
/*                l’échappement)                                              */
/* !Number      : FCT1.6                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret Std_ReturnType  CAMHAL_udtEnableSynchronisation(argin        */
/*   CAMHAL_tudtChannel udtChannel);                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidIniExCmSen(void)
{
   (void)CAMHAL_udtEnableSynchronisation(CAMHAL_udtCH_EXHAUST_CAMSHAFT);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidInitSync                                      */
/* !Description : La recherche de synchronisation moteur est désactivée sur   */
/*                l’évènement KOf pour prévenir des risques de détection de   */
/*                rotation moteur voire de synchronisation moteur lors de     */
/*                l’arrêt (et des rebonds) moteur.                            */
/* !Number      : FCT1.7                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret Std_ReturnType  CRKHAL_udtEnableSynchronisation();           */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidInitSync(void)
{
   (void)CRKHAL_udtEnableSynchronisation();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : SYNCENGMNG_vidInitDesync                                    */
/* !Description : La recherche de synchronisation moteur est désactivée sur   */
/*                l’évènement KOf pour prévenir des risques de détection de   */
/*                rotation moteur voire de synchronisation moteur lors de     */
/*                l’arrêt (et des rebonds) moteur.                            */
/* !Number      : FCT1.8                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret Std_ReturnType  CRKHAL_udtDisableSynchronisation();          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGMNG_vidInitDesync(void)
{
   (void)CRKHAL_udtDisableSynchronisation();
}
/*------------------------------- end of file --------------------------------*/