/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DC                                                      */
/* !Description     : DC Component                                            */
/*                                                                            */
/* !Module          : DC                                                      */
/* !Description     : DRIVING CYCLE                                           */
/*                                                                            */
/* !File            : DC_fct1.c                                               */
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
/*   1 / DC_vidInit                                                           */
/*   2 / DC_vidF01_NonAutorise                                                */
/*   3 / DC_vidF01_Autorise                                                   */
/*   4 / DC_vidF02_GlbDCStrtEve                                               */
/*   5 / DC_vidF03_F01_NotRelzd                                               */
/*   6 / DC_vidF02_F01_ValDC                                                  */
/*   7 / DC_vidF03_DC_Reinit                                                  */
/*                                                                            */
/* !Reference   : V02 NT 10 04662 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/DC/DC_fct1.c_v               $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   01 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "DC.h"
#include "DC_L.h"
#include "DC_IM.h"
#include "GD_API.h"
#include "NVMSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidInit                                                 */
/* !Description :  Intialized the DC parameter.                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean DC_bSyncGlbDC;                                             */
/*  output boolean DC_bAuthNewDrvCyc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidInit(void)
{
   DC_bSyncGlbDC = FALSE;
   DC_bAuthNewDrvCyc = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidF01_NonAutorise                                      */
/* !Description :  Global DC Start not autorize during the next starting      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean GOBD_bKeyOBD;                                               */
/*  output boolean DC_bAuthNewDrvCyc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidF01_NonAutorise(void)
{
   DC_bAuthNewDrvCyc = !GOBD_bKeyOBD;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidF01_Autorise                                         */
/* !Description :  Global DC Start autorize during the next starting          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean DC_bAuthNewDrvCyc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidF01_Autorise(void)
{
   DC_bAuthNewDrvCyc = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidF02_GlbDCStrtEve                                     */
/* !Description :  Function which indicate to the rest of the module that an  */
/*                 Global DC has started.                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  EF40_020_02_(1)                                            */
/*                 EF40_020_03_(0)                                            */
/*                 EF40_020_07_(0)                                            */
/*                 EF40_020_08_(0)                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DC_vidExitEveGlbStrt();                                  */
/*  extf argret void DC_RstDC();                                              */
/*  input boolean CoPtUH_bLatchDrvCyc;                                        */
/*  input boolean DC_bAuthNewDrvCyc;                                          */
/*  output boolean DC_bSyncGlbDC;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidF02_GlbDCStrtEve(void)
{
   boolean bLocalFRMInhDrvCycGlbStrt;
   boolean bLocalCoPtUH_bLatchDrvCyc;


   bLocalFRMInhDrvCycGlbStrt = GDGAR_bGetFRM(FRM_FRM_INHDRVCYCGLBSTRT);
   VEMS_vidGET(CoPtUH_bLatchDrvCyc, bLocalCoPtUH_bLatchDrvCyc);

   if(  (bLocalCoPtUH_bLatchDrvCyc == FALSE)
      &&(bLocalFRMInhDrvCycGlbStrt == FALSE)
      &&(DC_bAuthNewDrvCyc == TRUE))
   {
      /* function DC_GlbDCStrt*/
      DC_vidExitEveGlbStrt();
      DC_RstDC();
      /* function F03_F02_Relzd */
      DC_bSyncGlbDC = TRUE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidF03_F01_NotRelzd                                     */
/* !Description :  set to false the data DC_bSynGlbDC to indicate that the DC */
/*                 is in the state not realized.                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  EF40_020_07_(0)                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean DC_bSyncGlbDC;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidF03_F01_NotRelzd(void)
{
   DC_bSyncGlbDC = FALSE;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidF02_F01_ValDC                                        */
/* !Description :  This data set to TRUE the parameter DC_B<typeCc_NameVar> of*/
/*                 the default indicated by its index.                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  EF40_020_04_(3)                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidF02_F01_ValDC
(
   uint16 u16IdxDft
)
{
   boolean  blocal;
   uint8    u8LocalDivision;
   uint8    u8LocalRatio;


   blocal = TRUE;
   u8LocalDivision = (uint8)(u16IdxDft / 8);
   u8LocalRatio = (uint8)(u16IdxDft % 8);

   /*QAC Warning: macro use if else*/
   GD_vidBitWrite(DC_au8DC_EEPROM[u8LocalDivision],u8LocalRatio,blocal);
   /* QAC Warning : Les opérations sur le tableaux font qu'on dépasse le nombre
   d'opération autorisé : Ne pas prendre un compte */
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DC_vidF03_DC_Reinit                                        */
/* !Description :  A chaque début d’un nouveau DC global, les DC Appliqués    */
/*                 sont réinitialisés à l’état « Non Réalisé ».               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 DC_au8DC_EEPROM;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DC_vidF03_DC_Reinit(void)
{
   sint32 s32LocalIdx;


   for(s32LocalIdx = 0; s32LocalIdx < DC_AU8DC_EEPROM_LNS; s32LocalIdx++)
   {
      DC_au8DC_EEPROM[s32LocalIdx] = 0;
   }
}
/*------------------------------- end of file --------------------------------*/