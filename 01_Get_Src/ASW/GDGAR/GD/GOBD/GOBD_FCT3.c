/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GOBD                                                    */
/* !Description     : GOBD Component                                          */
/*                                                                            */
/* !Module          : GOBD                                                    */
/* !Description     : Gestionnaire OBD                                        */
/*                                                                            */
/* !File            : GOBD_FCT3.C                                             */
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
/*   1 / GOBD_vidCDThdUp                                                      */
/*   2 / GOBD_vidGlbDC                                                        */
/*   3 / GOBD_vidRstCntDC                                                     */
/*   4 / GOBD_vidCntWUC                                                       */
/*   5 / GOBD_vidIniCntWUC                                                    */
/*   6 / GOBD_vidClrCntWUC                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5075502 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GOBD/GOBD_FCT3.c_v           $*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   11 Feb 2014 $*/
/* $Author::   mbenfrad                               $$Date::   11 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "GOBD.h"
#include "GOBD_L.h"
#include "GOBD_im.h"
#include "GD_api.h"
#include "GD_A.h"
#include "MATHSRV.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidCDThdUp                                            */
/* !Description :  Do all the actions which must be done on the event         */
/*                 GD_EveCDThdUp.                                             */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  output uint8 GOBD_u8ctDC[9];                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidCDThdUp
(
   uint16 u16IdxDft
)
{
   boolean bLocalNcfDc;
   boolean bLocalPresDc;
   uint8   u8LocalNoNCfDC;     /* array of number of DC consecutive*/
                               /* need to confirm a default        */
   uint8   u8LocalNoHealDC;    /* */

   u8LocalNoNCfDC = GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].u8NoNCfDC;
   u8LocalNoHealDC = GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].u8NoHealDC;

   bLocalPresDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BPRESDC);

   if(bLocalPresDc == FALSE)
   {
      /* CALL CDThdUp */
      /*QAC WARNING Macro use if else*/
      GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                     BPRESDC,TRUE);
      /* bloc F05_F01_F01_GOBD_PresDC */
      bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BNCFDC);
      if(bLocalNcfDc == TRUE)
      {
         GOBD_u8ctDC[u16IdxDft] = u8LocalNoHealDC;
      }
      else
      {  /* bloc F01_GOBD_IncCntDC */
         if(GOBD_u8ctDC[u16IdxDft] < u8LocalNoNCfDC)
         {
            GOBD_u8ctDC[u16IdxDft] = (uint8)(GOBD_u8ctDC[u16IdxDft] + 1);
         }
         /* Check if the meter has reached the threshold */
         if(GOBD_u8ctDC[u16IdxDft] >=  u8LocalNoNCfDC)
         {
            GOBD_u8ctDC[u16IdxDft] = u8LocalNoHealDC;

         /*QAC WARNING Macro use if else*/
         GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                           BNCFDC,TRUE);
         }
      }
   }
}/* mettre a jour GOBD_Macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidGlbDC                                              */
/* !Description :  Manage all the actins which must be done on the vent       */
/*                 Cal_GlbDCStrt.                                             */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  input uint8 GOBD_u8ctWUC[9];                                              */
/*  output uint8 GOBD_u8ctDC[9];                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidGlbDC
(
   uint16 u16IdxDft
)
{
   boolean  bLocalNcfDc;
   boolean  bLocalPresDc;
   boolean  bLocalDcabDc;
   uint8    u8LocalDivision;
   uint8    u8LocalRatio;
   uint8    u8LocalGOBD_u8ctDC;

   u8LocalDivision = (uint8)(u16IdxDft / 8);
   u8LocalRatio = (uint8)(u16IdxDft % 8);

   bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BNCFDC);

   bLocalPresDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                             BPRESDC);

   bLocalDcabDc = GD_bBitRead(DC_au8DC_EEPROM[u8LocalDivision],u8LocalRatio);

   if ( (bLocalPresDc == FALSE)
      && (bLocalDcabDc == TRUE))
   {  /* Start -> function F01_GOBD_DecCntDC */
      if(bLocalNcfDc == TRUE)
      {
         if (GOBD_u8ctDC[u16IdxDft] > 0)
         {
            u8LocalGOBD_u8ctDC = (uint8)(GOBD_u8ctDC[u16IdxDft] - 1);
            GOBD_u8ctDC[u16IdxDft] =
               (uint8)MATHSRV_udtMIN(u8LocalGOBD_u8ctDC, 10);
         }
      }
      else
      {
         GOBD_u8ctDC[u16IdxDft] = 0;
      }
      /* End -> function F01_GOBD_DecCntDC */
   }
   /*QAC WARNING Macro use if else*/
   /* Start -> function F01_GOBD_RstbNCf */
   if (  (GOBD_u8ctWUC[u16IdxDft] == 0)
      && (bLocalPresDc == FALSE))
   {
      GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                     BNCFDC,FALSE);
   }
   /*QAC WARNING Macro use if else*/
   /* End -> function F01_GOBD_RstbNCf */
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                  BPRESDC,FALSE);
}/* mettre a jour GOBD_Macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidRstCntDC                                           */
/* !Description :  Reset the DC meter of the default give in argument.        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrDftEep GD_astrDftEep[9];                                     */
/*  output uint8 GOBD_u8ctDC[9];                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidRstCntDC
(
   uint16 u16IdxDft
)
{
   GOBD_u8ctDC[u16IdxDft] = 0;

   /*QAC WARNING Macro use if else*/
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                           BPRESDC,FALSE);

   /*QAC WARNING Macro use if else*/
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,
                           BNCFDC,FALSE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidCntWUC                                             */
/* !Description :  Manage the WUC meter for the automatic erasure of the      */
/*                 default.                                                   */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GOBD_u8ctDC[9];                                               */
/*  input boolean WUC_bWupSt;                                                 */
/*  input uint8 GOBD_u8ctWUC[9];                                              */
/*  output uint8 GOBD_u8ctWUC[9];                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidCntWUC
(
   uint16 u16IdxDft
)
{
   uint8 u8LocalGOBD_u8ctWUC;


   if((GOBD_u8ctDC[u16IdxDft] == 0) && (WUC_bWupSt == TRUE) )
   {
      if(GOBD_u8ctWUC[u16IdxDft] > 0)
      {
         u8LocalGOBD_u8ctWUC = (uint8)(GOBD_u8ctWUC[u16IdxDft] - 1);
         GOBD_u8ctWUC[u16IdxDft] =
            (uint8)MATHSRV_udtMIN(u8LocalGOBD_u8ctWUC, 100);
      }
   }
}/* mettre a jour GOBD_Macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidIniCntWUC                                          */
/* !Description :  Manage the re-initialization of the WUC's meter.           */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 GOBD_noWUCClr_C;                                              */
/*  output uint8 GOBD_u8ctWUC[9];                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidIniCntWUC
(
   uint16 u16IdxDft
)
{
   GOBD_u8ctWUC[u16IdxDft] = (uint8)MATHSRV_udtMIN(GOBD_noWUCClr_C, 100);
}/* mettre a jour GOBD_Macro.h si cette fonction evolue*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GOBD_vidClrCntWUC                                          */
/* !Description :  Manage the re-initalization of the WUC's meter on the clear*/
/*                 tools event.                                               */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 GOBD_u8ctWUC[9];                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GOBD_vidClrCntWUC
(
   uint16 u16IdxDft
)
{
   GOBD_u8ctWUC[u16IdxDft] = 0;
}
/*------------------------------- end of file --------------------------------*/