/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PFUACQ                                                  */
/* !Description     : PFUACQ Component                                        */
/*                                                                            */
/* !Module          : PFUACQ                                                  */
/* !Description     : PFuAcq: FUEL RAIL PRESSURE ACQUISITION (GDI)            */
/*                                                                            */
/* !File            : PFUACQ_FCT2.C                                           */
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
/*   1 / PFUACQ_vidCoherencyDiagnosis                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6851391 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PFUACQ.h"
#include "PFUACQ_L.h"
#include "PFUACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFUACQ_vidCoherencyDiagnosis                               */
/* !Description :  The raw voltage sent by the rail pressure sensor is        */
/*                 compared to a high and a low thresholds. If this voltage is*/
/*                 not included between these two thresholds, a failure flag  */
/*                 is sent.                                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upFuMes;                                                 */
/*  input uint16 Ext_uDgoScg_pFuMes_C;                                        */
/*  input uint16 Ext_uDgoCoh_pFuMes_C;                                        */
/*  output boolean Ext_bDgoCoh_PFuAcq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFUACQ_vidCoherencyDiagnosis(void)
{
   uint16   u16LocalExt_upFuMes;


   VEMS_vidGET(Ext_upFuMes, u16LocalExt_upFuMes);
   if (  (u16LocalExt_upFuMes > Ext_uDgoScg_pFuMes_C)
      && (u16LocalExt_upFuMes < Ext_uDgoCoh_pFuMes_C))
   {
      Ext_bDgoCoh_PFuAcq = 1;
   }
   else
   {
      Ext_bDgoCoh_PFuAcq = 0;
   }
}
/*---------------------------- end of file -----------------------------------*/