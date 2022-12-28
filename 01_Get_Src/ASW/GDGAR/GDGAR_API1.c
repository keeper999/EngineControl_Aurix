/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : GDGAR Component                                         */
/*                                                                            */
/* !Module          : GDGAR                                                   */
/* !Description     : GESTIONNAIRE DE DEFAUT                                  */
/*                                                                            */
/* !File            : GDGAR_API1.C                                            */
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
/*   1 / GDGAR_vidGdu                                                         */
/*   2 / GDGAR_bGetFRM                                                        */
/*   3 / GDGAR_vidMngEveRstDftApv                                             */
/*   4 / GDGAR_vidMngEveRstDftObd                                             */
/*   5 / GDGAR_tenuGetStDgo                                                   */
/*   6 / GDGAR_bGetEndDiagStrt                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5012623 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#048854                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GDGAR/GDGAR_API1.c_v            $*/
/* $Revision::   1.13     $$Author::   mbenfrad       $$Date::   16 Jan 2013 $*/
/* $Author::   mbenfrad                               $$Date::   16 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "GDGAR.h"
#include "GDGAR_L.h"
#include "GDGAR_IM.h"
#include "Rte_Type.h"
#include "Vems.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_vidGdu                                               */
/* !Description :  API permettant d'appeler la fonction de gestion du GDU.    */
/*                 Elle verifie les paramètres passés en arguments et si il y */
/*                 un problème, elle sort sans executer la fonction.          */
/* !Number      :  API1.1                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  Dem_SetEventStatus(argin uint16 u16DftIdx,    */
/* argin uint8 u8EventStatus);                                                */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  input boolean GD_bInhDiagPwrl[400];                                       */
/*  input uint8 DiagState;                                                    */
/*  output uint8 DiagState;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_vidGdu
(
   uint16 u16IdxDft,
   boolean bDgo,
   boolean bMonRun,
   boolean Ns_bMonWait
)
{
   Std_ReturnType  udtLocalStatus;
   sint32          s32LocalIdx;
   boolean         bLocalEcuSt_bInhDiagOcCmdActr;


   VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalEcuSt_bInhDiagOcCmdActr);
   udtLocalStatus = E_NOT_OK;
   if (bMonRun == 1)
   {
      /* F02_PREPASSED_PREFAILED */
      if (Ns_bMonWait == 1) /* &&(bMonRun ==1) */
      {
         DiagState = DEM_EVENT_STATUS_INIT;
      }
      else
      {
         if (  (GD_bInhDiagPwrl[u16IdxDft] == 0)
            || (bLocalEcuSt_bInhDiagOcCmdActr == 0))
         {
            if (bDgo == 1)
            {
               DiagState = DEM_EVENT_STATUS_PREFAILED;
            }
            else
            {
               DiagState = DEM_EVENT_STATUS_PREPASSED;
            }
         }
         else
         {
            DiagState = DEM_EVENT_STATUS_INIT;
         }
      }
   }
   else
   {
      DiagState = DEM_EVENT_STATUS_INIT;
   }
   /* F03_Calcul_frequence_appel_au_GD */
   for (s32LocalIdx = 0;
       (s32LocalIdx < DEM_CPT_TRY_EVENT_STATUS) && (udtLocalStatus == E_NOT_OK);
        s32LocalIdx++
       )
   {
      udtLocalStatus = Dem_SetEventStatus(u16IdxDft, DiagState);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_bGetFRM                                              */
/* !Description :  Get FRM Value                                              */
/* !Number      :  API1.2                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Fim_GetFunctionPermission(argin uint16        */
/*  u16FRMIndex, argin boolean *bPermission);                                 */
/*  output boolean FRM_abTypAcvOptRvCcDd[8];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean GDGAR_bGetFRM
(
   uint16 u16IndexFRM
)
{
   boolean        bLocalPermission;
   Std_ReturnType udtLocalStatus;
   sint32         s32LocalIdx;

   bLocalPermission = TRUE;
   udtLocalStatus = E_NOT_OK;
   for (
        s32LocalIdx = 0;
       (s32LocalIdx < FIM_CPT_TRY_FCT_PERM) && (udtLocalStatus == E_NOT_OK);
        s32LocalIdx++
       )
   {
      udtLocalStatus = Fim_GetFunctionPermission(u16IndexFRM,&bLocalPermission);
      FRM_abTypAcvOptRvCcDd[u16IndexFRM] = !(bLocalPermission);
   }
   return !bLocalPermission;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_vidMngEveRstDftApv                                   */
/* !Description :  Requete d'effacement des defauts avec l'outil APV          */
/* !Number      :  API1.3                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRstDft();                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_vidMngEveRstDftApv(void)
{
   GD_EveRstDft();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_vidMngEveRstDftObd                                   */
/* !Description :  Requete d'effacement des défauts avec l'outil ScanTool     */
/* !Number      :  API1.4                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GD_EveRstDftObd();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_vidMngEveRstDftObd(void)
{
   GD_EveRstDftObd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_tenuGetStDgo                                         */
/* !Description :  Value of the GDU states                                    */
/* !Number      :  API1.5                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDU_tenuGetStDgo(argin uint16 u16IdxDft); */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
GDFRM_tenuGDUState GDGAR_tenuGetStDgo
(
   uint16 u16IdxDft
)
{
   GDFRM_tenuGDUState enuLocalGDUState;

   enuLocalGDUState = GDU_tenuGetStDgo(u16IdxDft);

   return enuLocalGDUState;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_bGetEndDiagStrt                                      */
/* !Description :  Value of EndDiagStrt                                       */
/* !Number      :  API1.6                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDU_bGetEndDiagStrt(argin uint16 u16IdxDft);         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean GDGAR_bGetEndDiagStrt
(
   uint16 u16IdxDft
)
{
   boolean bLocalEndDiagStrt;

   bLocalEndDiagStrt = GDU_bGetEndDiagStrt(u16IdxDft);

   return bLocalEndDiagStrt;
}
/*--------------------------------- end of file ------------------------------*/
