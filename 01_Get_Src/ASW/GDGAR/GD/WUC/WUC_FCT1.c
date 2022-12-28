/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WUC                                                     */
/* !Description     : WUC Component                                           */
/*                                                                            */
/* !Module          : WUC                                                     */
/* !Description     : WARM UP CYCLE                                           */
/*                                                                            */
/* !File            : WUC_FCT1.C                                              */
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
/*   1 / WUC_vidWupInit                                                       */
/*   2 / WUC_vidF02_tCoRefFrz                                                 */
/*   3 / WUC_vidF03_WupPrmUpd                                                 */
/*   4 / WUC_vidF03_F01_WupStDet                                              */
/*   5 / WUC_vidF03_F02_CtWupDftClr                                           */
/*   6 / WUC_vidF05_WupPrmClrTool                                             */
/*                                                                            */
/* !Reference   : V02 NT 08 04191 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/GDGAR/WUC/WUC_FCT1.c_v            $*/
/* $Revision::   1.7      $$Author::   acabresp       $$Date::   09 Nov 2009 $*/
/* $Author::   acabresp                               $$Date::   09 Nov 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "MATHSRV.h"
#include "WUC.h"
#include "WUC_L.h"
#include "WUC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidWupInit                                             */
/* !Description :  Initialize the WUC parameters.                             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 WUC_tCoRefEep;                                               */
/*  output sint16 WUC_tCoRef;                                                 */
/*  output sint16 WUC_s16tCoRef_NS;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidWupInit(void)
{
   WUC_tCoRef = (sint16)MATHSRV_udtCLAMP(WUC_tCoRefEep, -40, 214);
   WUC_s16tCoRef_NS = (sint16)MATHSRV_udtCLAMP(WUC_tCoRefEep, -40, 214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidF02_tCoRefFrz                                       */
/* !Description :  Fix the WUC reference temperature at the engine cooling    */
/*                 liquid when the engine start.                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_08_04191_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  output boolean WUC_bWupSt;                                                */
/*  output sint16 WUC_tCoRef;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidF02_tCoRefFrz(void)
{
   sint16 s16LocalExtTCoMes;
   sint16 s16LocalExt_tCoMes;
   VEMS_vidGET(Ext_tCoMes,s16LocalExt_tCoMes);
   s16LocalExtTCoMes = s16LocalExt_tCoMes;


   WUC_bWupSt = FALSE;

   /* check if Ext_tCoMes is between [-40..214] */
   if(  (WUC_s16TCO_MIN <= s16LocalExtTCoMes)
     && (s16LocalExtTCoMes <= WUC_s16TCO_MAX) )
   {
      WUC_tCoRef = s16LocalExtTCoMes; /* must be same type */
   }
   else
   {
      if(WUC_s16TCO_MIN > s16LocalExtTCoMes)
      {
         WUC_tCoRef = WUC_s16TCO_MIN;
      }
      else /* s16LocalExtTCoMes > WUC_s16TCO_MAX  */
      {
         WUC_tCoRef = WUC_s16TCO_MAX;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidF03_WupPrmUpd                                       */
/* !Description :  Update the warm up status and the Warm Up meter.           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WUC_vidF03_F01_WupStDet();                               */
/*  extf argret void WUC_vidF03_F02_CtWupDftClr();                            */
/*  input boolean WUC_bWupSt;                                                 */
/*  input sint16 WUC_s16tCoRef_NS;                                            */
/*  input sint16 WUC_tCoRef;                                                  */
/*  output sint16 WUC_tCoRefEep;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidF03_WupPrmUpd(void)
{
   if(WUC_bWupSt == FALSE)
   {
      WUC_vidF03_F01_WupStDet();

      if(WUC_bWupSt == TRUE)
      {
         WUC_vidF03_F02_CtWupDftClr();
      }
   }

   /* management of the data which is save in EEPROM. We update the data only */
   /* if the WUC_bWupSt is FALSE. In other case, we must restore the value    */
   /* that we had on reset ECU */
   if(WUC_bWupSt == TRUE)
   {
      WUC_tCoRefEep = WUC_s16tCoRef_NS;
   }
   else
   {
      WUC_tCoRefEep = WUC_tCoRef;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidF03_F01_WupStDet                                    */
/* !Description :  Update the warm up status (WUC_bWupSt).                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_08_04191_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 WUC_tCoRef;                                                  */
/*  input sint16 WUC_tCoThd_C;                                                */
/*  input uint8 WUC_tCoInc_C;                                                 */
/*  output boolean WUC_bWupSt;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidF03_F01_WupStDet(void)
{
   sint16  s16LocalDifCo;     /* difference between Ext_tCoMes and WUC_tCoRef */
   boolean bLocalFRMFrzWucSt; /* */
   sint16  s16LocalExtTCoMes; /* working image of Ext_tCoMes                  */
   sint16  s16LocalExt_tCoMes;


   bLocalFRMFrzWucSt = GDGAR_bGetFRM(FRM_FRM_FRZWUCST);
   VEMS_vidGET(Ext_tCoMes,s16LocalExt_tCoMes);
   s16LocalExtTCoMes = s16LocalExt_tCoMes;
   /* check these parameters because this parameter is defined on a sint16
      and its limit are not the size of the type definition conversely
      WUC_u8tCoInc_C.
   */
   if(  (WUC_s16TCO_MIN <= s16LocalExtTCoMes)
     && (s16LocalExtTCoMes <= WUC_s16TCO_MAX) )
   {  /* YES */
      s16LocalDifCo = (sint16)(s16LocalExtTCoMes - WUC_tCoRef);

      if(s16LocalDifCo < 0)
      {
         s16LocalDifCo = 0;
      }

      if(  (s16LocalExtTCoMes >= WUC_tCoThd_C)
        && (s16LocalDifCo >= (sint16)WUC_tCoInc_C)
        && (FALSE == bLocalFRMFrzWucSt) )
      {
         WUC_bWupSt = TRUE;
      }
    /* We don't need to treat the other case, because the call of this
            function is  based this test (WUC_bWupSt == FALSE) so the param is
            already set at FALSE.
         */
   }
   else
   {  /* NO */
      WUC_bWupSt = FALSE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidF03_F02_CtWupDftClr                                 */
/* !Description :  Update the WUC meter (WUC_ctWupDftClr).                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_08_04191_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 WUC_ctWupDftClr;                                              */
/*  output uint8 WUC_ctWupDftClr;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidF03_F02_CtWupDftClr(void)
{
   /* check if wup meter is under the upper threshold */
   if(WUC_ctWupDftClr < WUC_u8CTWUP_MAX)
   {
      WUC_ctWupDftClr = (uint8)(WUC_ctWupDftClr + 1);
   }
   else
   {
      WUC_ctWupDftClr = WUC_u8CTWUP_MAX;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WUC_vidF05_WupPrmClrTool                                   */
/* !Description :  Set data when there is an erausre.                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_08_04191_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 WUC_tCoRef;                                                  */
/*  output boolean WUC_bWupSt;                                                */
/*  output uint8 WUC_ctWupDftClr;                                             */
/*  output sint16 WUC_tCoRefEep;                                              */
/*  output sint16 WUC_tCoRef;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WUC_vidF05_WupPrmClrTool(void)
{
   sint16 s16LocalExtTCoMes;
   sint16 s16LocalExt_tCoMes;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   WUC_bWupSt = FALSE;
   WUC_ctWupDftClr = 0;
   WUC_tCoRefEep = WUC_tCoRef;

   s16LocalExtTCoMes = s16LocalExt_tCoMes;

   /* check if Ext_tCoMes is between [-40..214] */
   if(  (WUC_s16TCO_MIN <= s16LocalExtTCoMes)
     && (s16LocalExtTCoMes <= WUC_s16TCO_MAX) )
   {
      WUC_tCoRef = s16LocalExtTCoMes; /* must be same type */
   }
   else
   {
      if(WUC_s16TCO_MIN > s16LocalExtTCoMes)
      {
         WUC_tCoRef = WUC_s16TCO_MIN;
      }
      else /* s16LocalExtTCoMes > WUC_s16TCO_MAX  */
      {
         WUC_tCoRef = WUC_s16TCO_MAX;
      }
   }
}

/*------------------------------- end of file --------------------------------*/