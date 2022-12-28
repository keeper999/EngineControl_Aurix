/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUPEDPOSNDIAG                                          */
/* !Description     : CLUPEDPOSNDIAG Component.                               */
/*                                                                            */
/* !Module          : CLUPEDPOSNDIAG                                          */
/* !Description     : SURVEILLANCE DE LA POSITION EMBRAYAGE CONTINUE.         */
/*                                                                            */
/* !File            : CLUPEDPOSNDIAG_SCH.C                                    */
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
/*   1 / CLUPEDPOSNDIAG_vidEntryInit                                          */
/*   2 / CLUPEDPOSNDIAG_vidEntry_100ms                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5050499 / 01                                        */
/* !OtherRefs   : CSMT_CGMT07_2265 / 2.1                                      */
/* !OtherRefs   : VEMS V02 ECU#044847                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/CLUPEDPOSNDIAG/CL$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "CLUPEDPOSNDIAG.h"
#include "CLUPEDPOSNDIAG_L.h"
#include "CLUPEDPOSNDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidEntryInit                                */
/* !Description :  Scheduler Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUPEDPOSNDIAG_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CLUPEDPOSNDIAG_vidEntryInit                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidEntryInit(void)
{
   CLUPEDPOSNDIAG_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidEntry_100ms                              */
/* !Description :  Scheduler 100 ms                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_08522_001.01                                     */
/*                 VEMS_R_10_08522_002.01                                     */
/*                 VEMS_R_10_08522_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUPEDPOSNDIAG_vidActiv_diag();                          */
/*  extf argret void CLUPEDPOSNDIAG_vidCycle_de_tests();                      */
/*  extf argret void CLUPEDPOSNDIAG_vidDetect_dysfcts();                      */
/*  extf argret void CLUPEDPOSNDIAG_vidCompteur();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CLUPEDPOSNDIAG_u8Inhib;                                       */
/*  input boolean StaCtl_bDgoFctCluP;                                         */
/*  input boolean StaCtl_bMonRunFctCluP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CLUPEDPOSNDIAG_vidEntry_100ms                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidEntry_100ms(void)
{
   boolean  bLocalStaCtl_bDgoFctCluP;
   boolean  bLocalStaCtl_bMonRunFctCluP;


   if (CLUPEDPOSNDIAG_u8Inhib != 0x5A)
   {

      VEMS_vidGET(StaCtl_bDgoFctCluP, bLocalStaCtl_bDgoFctCluP);
      VEMS_vidGET(StaCtl_bMonRunFctCluP, bLocalStaCtl_bMonRunFctCluP);

      CLUPEDPOSNDIAG_vidActiv_diag();
      CLUPEDPOSNDIAG_vidCycle_de_tests();
      CLUPEDPOSNDIAG_vidDetect_dysfcts();
      CLUPEDPOSNDIAG_vidCompteur();
      GDGAR_vidGdu(GD_DFT_FCTCLUP,
                   bLocalStaCtl_bDgoFctCluP,
                   bLocalStaCtl_bMonRunFctCluP,
                   DIAG_DISPO);
   }

}
/*---------------------------------End Of File--------------------------------*/