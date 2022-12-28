/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SAIMMO                                                  */
/* !Description     : SAIMMO Component                                        */
/*                                                                            */
/* !Module          : SAIMMO                                                  */
/* !Description     : Structure d'accueil pour le module IMMO                 */
/*                                                                            */
/* !File            : SAIMMO_FCT4.C                                           */
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
/*   1 / Ext_setStCANOptImmoEve                                               */
/*   2 / Ext_setStMatchProgImmoEve                                            */
/*   3 / Ext_setBDgoNoAnswCtlUnit                                             */
/*   4 / Ext_setBDgoWrgAnswCtlUnit                                            */
/*   5 / Ext_setBDgoImmoCodNotRead                                            */
/*   6 / Ext_getBInhCdtSpdVehImmo                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5060905 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_FCT4.c_v          $*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   06 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "saimmo_im.h"
#include "saimmo.h"
#include "saimmo_l.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setStCANOptImmoEve                                     */
/* !Description :  Indicate to the SA the new ADC CAN option.                 */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setStCANOptImmoEve
(
   uint8 Immo_stCANOptEve
)
{  /* WARNING QAC and Compilation:
      function not used in SA. it is functionally replaced by
      Ext_setImmoCod.
   */
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setStMatchProgImmoEve                                  */
/* !Description :  Indicate to SA if the UCM is paired or not.                */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidMngEveRstDftApv();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setStMatchProgImmoEve(void)
{
   GDGAR_vidMngEveRstDftApv();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setBDgoNoAnswCtlUnit                                   */
/* !Description :  Demande d’envoi du défaut « Absence de réponse UCx » au    */
/*                 gestionnaire de diagnostic simplifié.                      */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_034.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/*  bMonRun, boolean Ns_bMonWait);                                            */
/*  input boolean Immo_bDgoNoAnswCtlUnit;                                     */
/*  output boolean Immo_bDgoNoAnswCtlUnit;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setBDgoNoAnswCtlUnit
(
   boolean bLocalImmo_bDgoNoAnswCtlUnit,
   boolean Immo_bMonRunNoAnswCtlUnit
)
{
   Immo_bDgoNoAnswCtlUnit = bLocalImmo_bDgoNoAnswCtlUnit;
   GDGAR_vidGdu(GD_DFT_NOANSWCTLUNIT,
                Immo_bDgoNoAnswCtlUnit,
                Immo_bMonRunNoAnswCtlUnit,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setBDgoWrgAnswCtlUnit                                  */
/* !Description :  Demande d’envoi du défaut « Réponse UCx incorrecte » au    */
/*                 gestionnaire de diagnostic simplifié                       */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_035.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/*  bMonRun, boolean Ns_bMonWait);                                            */
/*  input boolean Immo_bDgoWrgAnswCtlUnit;                                    */
/*  output boolean Immo_bDgoWrgAnswCtlUnit;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setBDgoWrgAnswCtlUnit
(
   boolean bLocalImmo_bDgoWrgAnswCtlUnit,
   boolean Immo_bMonRunWrgAnswCtlUnit
)
{
   Immo_bDgoWrgAnswCtlUnit = bLocalImmo_bDgoWrgAnswCtlUnit;
   GDGAR_vidGdu(GD_DFT_WRGANSWCTLUNIT,
                Immo_bDgoWrgAnswCtlUnit,
                Immo_bMonRunWrgAnswCtlUnit,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setBDgoImmoCodNotRead                                  */
/* !Description :  Demande d’envoi du défaut « Lecture du Code ADC impossible */
/*                 » au gestionnaire de diagnostic simplifié.                 */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_036.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/*  bMonRun, boolean Ns_bMonWait);                                            */
/*  input boolean Immo_bDgoImmoCodNotRead;                                    */
/*  output boolean Immo_bDgoImmoCodNotRead;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setBDgoImmoCodNotRead
(
   boolean bLocalImmo_bDgoImmoCodNotRead,
   boolean Immo_bMonRunImmoCodNotRead
)
{
   Immo_bDgoImmoCodNotRead = bLocalImmo_bDgoImmoCodNotRead;
   GDGAR_vidGdu(GD_DFT_IMMOCODNOTREAD,
                Immo_bDgoImmoCodNotRead,
                Immo_bMonRunImmoCodNotRead,
                DIAG_DISPO);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getBInhCdtSpdVehImmo                                   */
/* !Description :  Invalid vehicle speed information acquisition function sent*/
/*                 by the GAR.                                                */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_037.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getBInhCdtSpdVehImmo
(
   boolean* Immo_bInhCdtSpdVehImmo
)
{
   *Immo_bInhCdtSpdVehImmo = GDGAR_bGetFRM(FRM_FRM_INHCDTSPDVEHIMMO);
}

/*-------------------------------- end of file -------------------------------*/