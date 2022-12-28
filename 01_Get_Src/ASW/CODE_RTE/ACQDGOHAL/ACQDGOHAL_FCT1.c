/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQDGOHAL                                               */
/* !Description     : ACQDGOHAL component.                                    */
/*                                                                            */
/* !Module          : ACQDGOHAL                                               */
/* !Description     : Spécification des acquisitions des états et résultats   */
/*                    des diagnostics                                         */
/*                                                                            */
/* !File            : ACQDGOHAL_FCT1.C                                        */
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
/*   1 / ACQDGOHAL_vidCmdDiagBlowBy1                                          */
/*   2 / ACQDGOHAL_vidCmdDiagBlowBy2                                          */
/*   3 / ACQDGOHAL_vidCmdDiagVlvActEx                                         */
/*   4 / ACQDGOHAL_vidCmdDiagVlvActIn                                         */
/*   5 / ACQDGOHAL_vidCmdDiagDrvO2Ds                                          */
/*   6 / ACQDGOHAL_vidCmdDiagDrvO2Us                                          */
/*   7 / ACQDGOHAL_vidCmdDiagAuthStrtSTT                                      */
/*   8 / ACQDGOHAL_vidCmdDiagCstr                                             */
/*   9 / ACQDGOHAL_vidCmdDiagEngStOutIdc                                      */
/*   10 / ACQDGOHAL_vidCmdDiagPropFuPmp                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6669624 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQDGOHAL/ACQDGOHAL_FCT1.c_v      $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   17 Sep 2014 $*/
/* $Author::   wbouach                                $$Date::   17 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H

#include "STD_TYPES.h"
#include "ACQDGOHAL.h"
#include "ACQDGOHAL_L.h"
#include "ACQDGOHAL_IM.h"
#include "DGOHAL.h"
#include "ACQDGOHAL_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagBlowBy1                                */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit au réchauffeur BlowBy                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_rechauffeurblowby1;                                */
/*  output boolean Dft_oc_rechauffeurblowby1;                                 */
/*  output boolean Dena_scw_rechauffeurblowby1;                               */
/*  output boolean Dft_scw_rechauffeurblowby1;                                */
/*  output boolean Dena_scg_rechauffeurblowby1;                               */
/*  output boolean Dft_scg_rechauffeurblowby1;                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagBlowBy1(void)
{
   /*CmdDiagBlowBy1*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtCHAUFFAGE_BLOW_BY_1);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_rechauffeurblowby1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_rechauffeurblowby1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_rechauffeurblowby1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_rechauffeurblowby1, 0);
      VEMS_vidSET(Dft_oc_rechauffeurblowby1, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_rechauffeurblowby1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_rechauffeurblowby1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_rechauffeurblowby1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_rechauffeurblowby1, 0);
      VEMS_vidSET(Dft_scw_rechauffeurblowby1, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_rechauffeurblowby1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_rechauffeurblowby1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_rechauffeurblowby1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_rechauffeurblowby1, 0);
      VEMS_vidSET(Dft_scg_rechauffeurblowby1, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagBlowBy2                                */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit au réchauffeur BlowBy                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_rechauffeurblowby2;                                */
/*  output boolean Dft_oc_rechauffeurblowby2;                                 */
/*  output boolean Dena_scw_rechauffeurblowby2;                               */
/*  output boolean Dft_scw_rechauffeurblowby2;                                */
/*  output boolean Dena_scg_rechauffeurblowby2;                               */
/*  output boolean Dft_scg_rechauffeurblowby2;                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagBlowBy2(void)
{
   /*CmdDiagBlowBy2 */
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtCHAUFFAGE_BLOW_BY_2);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_rechauffeurblowby2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_rechauffeurblowby2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_rechauffeurblowby2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_rechauffeurblowby2, 0);
      VEMS_vidSET(Dft_oc_rechauffeurblowby2, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_rechauffeurblowby2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_rechauffeurblowby2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_rechauffeurblowby2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_rechauffeurblowby2, 0);
      VEMS_vidSET(Dft_scw_rechauffeurblowby2, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_rechauffeurblowby2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_rechauffeurblowby2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_rechauffeurblowby2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_rechauffeurblowby2, 0);
      VEMS_vidSET(Dft_scg_rechauffeurblowby2, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagVlvActEx                               */
/* !Description :  Fonction de diagnostique défaut du driver de la VVT        */
/*                 échappement.                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_driver_vvt_ech;                                    */
/*  output boolean Dft_oc_driver_vvt_ech;                                     */
/*  output boolean Dena_scp_driver_vvt_ech;                                   */
/*  output boolean Dft_scp_driver_vvt_ech;                                    */
/*  output boolean Dena_scg_driver_vvt_ech;                                   */
/*  output boolean Dft_scg_driver_vvt_ech;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagVlvActEx(void)
{
   /*CmdDiagVlvActEx*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtEXHAUST_VVT);
   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_driver_vvt_ech, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_driver_vvt_ech, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_driver_vvt_ech, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_driver_vvt_ech, 0);
      VEMS_vidSET(Dft_oc_driver_vvt_ech, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_driver_vvt_ech, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_driver_vvt_ech, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_driver_vvt_ech, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_driver_vvt_ech, 0);
      VEMS_vidSET(Dft_scp_driver_vvt_ech, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_driver_vvt_ech, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_driver_vvt_ech, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_driver_vvt_ech, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_driver_vvt_ech, 0);
      VEMS_vidSET(Dft_scg_driver_vvt_ech, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagVlvActIn                               */
/* !Description :  Fonction de diagnostique défaut du driver de la VVT        */
/*                 admission.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_driver_vvt_adm;                                    */
/*  output boolean Dft_oc_driver_vvt_adm;                                     */
/*  output boolean Dena_scp_driver_vvt_adm;                                   */
/*  output boolean Dft_scp_driver_vvt_adm;                                    */
/*  output boolean Dena_scg_driver_vvt_adm;                                   */
/*  output boolean Dft_scg_driver_vvt_adm;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagVlvActIn(void)
{
   /*CmdDiagVlvActIn*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtINTAKE_VVT);
   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_driver_vvt_adm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_driver_vvt_adm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_driver_vvt_adm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_driver_vvt_adm, 0);
      VEMS_vidSET(Dft_oc_driver_vvt_adm, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_driver_vvt_adm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_driver_vvt_adm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_driver_vvt_adm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_driver_vvt_adm, 0);
      VEMS_vidSET(Dft_scp_driver_vvt_adm, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_driver_vvt_adm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_driver_vvt_adm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_driver_vvt_adm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_driver_vvt_adm, 0);
      VEMS_vidSET(Dft_scg_driver_vvt_adm, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagDrvO2Ds                                */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à la fonction HeatSenO2 aval.                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_drvrseno2ds;                                       */
/*  output boolean Dft_oc_drvrseno2ds;                                        */
/*  output boolean Dena_scw_drvrseno2ds;                                      */
/*  output boolean Dft_scw_drvrseno2ds;                                       */
/*  output boolean Dena_scg_drvrseno2ds;                                      */
/*  output boolean Dft_scg_drvrseno2ds;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagDrvO2Ds(void)
{
   /*CmdDiagDrvO2Ds*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtSO2_HEAT_DOWN);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_drvrseno2ds, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_drvrseno2ds, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_drvrseno2ds, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_drvrseno2ds, 0);
      VEMS_vidSET(Dft_oc_drvrseno2ds, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_drvrseno2ds, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_drvrseno2ds, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_drvrseno2ds, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_drvrseno2ds, 0);
      VEMS_vidSET(Dft_scw_drvrseno2ds, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_drvrseno2ds, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_drvrseno2ds, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_drvrseno2ds, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_drvrseno2ds, 0);
      VEMS_vidSET(Dft_scg_drvrseno2ds, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagDrvO2Us                                */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à la fonction HeatSenO2 amont.               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_drvrseno2us;                                       */
/*  output boolean Dft_oc_drvrseno2us;                                        */
/*  output boolean Dena_scw_drvrseno2us;                                      */
/*  output boolean Dft_scw_drvrseno2us;                                       */
/*  output boolean Dena_scg_drvrseno2us;                                      */
/*  output boolean Dft_scg_drvrseno2us;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagDrvO2Us(void)
{
   /*CmdDiagDrvO2Us*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtSO2_HEAT_UP);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_drvrseno2us, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_drvrseno2us, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_drvrseno2us, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_drvrseno2us, 0);
      VEMS_vidSET(Dft_oc_drvrseno2us, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_drvrseno2us, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_drvrseno2us, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_drvrseno2us, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_drvrseno2us, 0);
      VEMS_vidSET(Dft_scw_drvrseno2us, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_drvrseno2us, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_drvrseno2us, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_drvrseno2us, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_drvrseno2us, 0);
      VEMS_vidSET(Dft_scg_drvrseno2us, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagAuthStrtSTT                            */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à la fonction STT                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_cmdautoredemstt;                                   */
/*  output boolean Dft_oc_cmdautoredemstt;                                    */
/*  output boolean Dena_scp_cmdautoredemstt;                                  */
/*  output boolean Dft_scp_cmdautoredemstt;                                   */
/*  output boolean Dena_scg_cmdautoredemstt;                                  */
/*  output boolean Dft_scg_cmdautoredemstt;                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagAuthStrtSTT(void)
{
   /*CmdDiagAuthStrtSTT*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udt_AUTORISATION_REDEM_STT);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_cmdautoredemstt, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_cmdautoredemstt, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_cmdautoredemstt, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_cmdautoredemstt, 0);
      VEMS_vidSET(Dft_oc_cmdautoredemstt, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_cmdautoredemstt, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_cmdautoredemstt, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_cmdautoredemstt, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_cmdautoredemstt, 0);
      VEMS_vidSET(Dft_scp_cmdautoredemstt, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_cmdautoredemstt, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_cmdautoredemstt, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_cmdautoredemstt, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_cmdautoredemstt, 0);
      VEMS_vidSET(Dft_scg_cmdautoredemstt, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagCstr                                   */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à L’ELECTROVANNE PURGE CANISTER.             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_cstrdrv;                                           */
/*  output boolean Dft_oc_cstrdrv;                                            */
/*  output boolean Dena_scw_cstrdrv;                                          */
/*  output boolean Dft_scw_cstrdrv;                                           */
/*  output boolean Dena_scg_cstrdrv;                                          */
/*  output boolean Dft_scg_cstrdrv;                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagCstr(void)
{
   /*CmdDiagCstr*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtCP);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_cstrdrv, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_cstrdrv, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_cstrdrv, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_cstrdrv, 0);
      VEMS_vidSET(Dft_oc_cstrdrv, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scw_cstrdrv, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scw_cstrdrv, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scw_cstrdrv, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scw_cstrdrv, 0);
      VEMS_vidSET(Dft_scw_cstrdrv, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_cstrdrv, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_cstrdrv, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_cstrdrv, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_cstrdrv, 0);
      VEMS_vidSET(Dft_scg_cstrdrv, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagEngStOutIdc                            */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à la sortie filaire information moteur       */
/*                 tournant                                                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_infomoteurtournant;                                */
/*  output boolean Dft_oc_infomoteurtournant;                                 */
/*  output boolean Dena_scp_infomoteurtournant;                               */
/*  output boolean Dft_scp_infomoteurtournant;                                */
/*  output boolean Dena_scg_infomoteurtournant;                               */
/*  output boolean Dft_scg_infomoteurtournant;                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagEngStOutIdc(void)
{
   /*CmdDiagEngStOutIdc*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtENGST);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_infomoteurtournant, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_infomoteurtournant, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_infomoteurtournant, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_infomoteurtournant, 0);
      VEMS_vidSET(Dft_oc_infomoteurtournant, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_infomoteurtournant, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_infomoteurtournant, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_infomoteurtournant, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_infomoteurtournant, 0);
      VEMS_vidSET(Dft_scp_infomoteurtournant, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_infomoteurtournant, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_infomoteurtournant, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_infomoteurtournant, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_infomoteurtournant, 0);
      VEMS_vidSET(Dft_scg_infomoteurtournant, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagPropFuPmp                              */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à la sortie FUEL PUMP                        */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_pompe_ess_pwm;                                     */
/*  output boolean Dft_oc_pompe_ess_pwm;                                      */
/*  output boolean Dena_scp_pompe_ess_pwm;                                    */
/*  output boolean Dft_scp_pompe_ess_pwm;                                     */
/*  output boolean Dena_scg_pompe_ess_pwm;                                    */
/*  output boolean Dft_scg_pompe_ess_pwm;                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagPropFuPmp(void)
{
   /*CmdDiagPropFuPmp*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtFUEL_PUMP_BP);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_pompe_ess_pwm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_pompe_ess_pwm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_pompe_ess_pwm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_pompe_ess_pwm, 0);
      VEMS_vidSET(Dft_oc_pompe_ess_pwm, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_pompe_ess_pwm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_pompe_ess_pwm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_pompe_ess_pwm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_pompe_ess_pwm, 0);
      VEMS_vidSET(Dft_scp_pompe_ess_pwm, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_pompe_ess_pwm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_pompe_ess_pwm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_pompe_ess_pwm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_pompe_ess_pwm, 0);
      VEMS_vidSET(Dft_scg_pompe_ess_pwm, 0);
   }
}
/*------------------------------- end of file --------------------------------*/