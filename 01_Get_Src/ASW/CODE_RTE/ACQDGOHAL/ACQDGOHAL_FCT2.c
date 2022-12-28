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
/* !File            : ACQDGOHAL_FCT2.C                                        */
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
/*   1 / ACQDGOHAL_vidCmdDiagDmtr                                             */
/*   2 / ACQDGOHAL_vidCmdDiagRly                                              */
/*   3 / ACQDGOHAL_vidCmdDiagStrtr                                            */
/*   4 / ACQDGOHAL_vidInit_OutPutCmdDiag                                      */
/*   5 / ACQDGOHAL_vidCmdDiagGMV1GMV2                                         */
/*   6 / ACQDGOHAL_vidCmdDiagECTReq                                           */
/*   7 / ACQDGOHAL_vidCmdDiagThrOverload                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6669624 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQDGOHAL/ACQDGOHAL_FCT2.c_v      $*/
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
/* !Function    :  ACQDGOHAL_vidCmdDiagDmtr                                   */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit au dispositif de maintient en tension reseau */
/*                 (MAINTIENT DMTR)                                           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_cmd_dmtr;                                          */
/*  output boolean Dft_oc_cmd_dmtr;                                           */
/*  output boolean Dena_scp_cmd_dmtr;                                         */
/*  output boolean Dft_scp_cmd_dmtr;                                          */
/*  output boolean Dena_scg_cmd_dmtr;                                         */
/*  output boolean Dft_scg_cmd_dmtr;                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagDmtr(void)
{
   /*CmdDiagDmtr*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udt_DMTR);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_cmd_dmtr, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_cmd_dmtr, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_cmd_dmtr, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_cmd_dmtr, 0);
      VEMS_vidSET(Dft_oc_cmd_dmtr, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_cmd_dmtr, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_cmd_dmtr, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_cmd_dmtr, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_cmd_dmtr, 0);
      VEMS_vidSET(Dft_scp_cmd_dmtr, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_cmd_dmtr, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_cmd_dmtr, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_cmd_dmtr, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_cmd_dmtr, 0);
      VEMS_vidSET(Dft_scg_cmd_dmtr, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagRly                                    */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert /panne Court-circuit à la masse/panne       */
/*                 Court-circuit à l'ACTUATOR RELAY                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_relais_puissance;                                  */
/*  output boolean Dft_oc_relais_puissance;                                   */
/*  output boolean Dena_scp_relais_puissance;                                 */
/*  output boolean Dft_scp_relais_puissance;                                  */
/*  output boolean Dena_scg_relais_puissance;                                 */
/*  output boolean Dft_scg_relais_puissance;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagRly(void)
{
   /*CmdDiagRly*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtACTR_RLY);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_relais_puissance , 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_relais_puissance, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_relais_puissance, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_relais_puissance, 0);
      VEMS_vidSET(Dft_oc_relais_puissance, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_relais_puissance, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_relais_puissance, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_relais_puissance, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_relais_puissance, 0);
      VEMS_vidSET(Dft_scp_relais_puissance, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_relais_puissance, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_relais_puissance, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_relais_puissance, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_relais_puissance, 0);
      VEMS_vidSET(Dft_scg_relais_puissance, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagStrtr                                  */
/* !Description :  Trois types de diagnostic de pannes à la sortie logique DML*/
/*                 sont traités: panne circuit ouvert /panne Court-circuit à  */
/*                 la masse/panne Court-circuit.                              */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_sortielogiquedml;                                  */
/*  output boolean Dft_oc_sortielogiquedml;                                   */
/*  output boolean Dena_scp_sortielogiquedml;                                 */
/*  output boolean Dft_scp_sortielogiquedml;                                  */
/*  output boolean Dena_scg_sortielogiquedml;                                 */
/*  output boolean Dft_scg_sortielogiquedml;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagStrtr(void)
{
   /*CmdDiagStrtr*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtDML_1);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_sortielogiquedml, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_sortielogiquedml, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_sortielogiquedml, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_sortielogiquedml, 0);
      VEMS_vidSET(Dft_oc_sortielogiquedml, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_sortielogiquedml, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_sortielogiquedml, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_sortielogiquedml, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_sortielogiquedml, 0);
      VEMS_vidSET(Dft_scp_sortielogiquedml, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_sortielogiquedml, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_sortielogiquedml, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_sortielogiquedml, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_sortielogiquedml, 0);
      VEMS_vidSET(Dft_scg_sortielogiquedml, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidInit_OutPutCmdDiag                            */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dft_oc_cmd_relais_principal;                               */
/*  output boolean Dft_scp_cmd_relais_principal;                              */
/*  output boolean Dft_scg_cmd_relais_principal;                              */
/*  output boolean Dft_oc_cmd_dmtr;                                           */
/*  output boolean Dft_scg_relais_puissance;                                  */
/*  output boolean Dena_oc_cmd_dmtr;                                          */
/*  output boolean Dft_scg_cmd_dmtr;                                          */
/*  output boolean Dena_scg_cmd_dmtr;                                         */
/*  output boolean Dena_scp_cmd_dmtr;                                         */
/*  output boolean Dena_scp_driver_vvt_adm;                                   */
/*  output boolean Dft_scp_driver_vvt_adm;                                    */
/*  output boolean Dena_scg_driver_vvt_adm;                                   */
/*  output boolean Dft_scg_driver_vvt_adm;                                    */
/*  output boolean Dena_oc_driver_vvt_adm;                                    */
/*  output boolean Dena_oc_rechauffeurblowby1;                                */
/*  output boolean Dft_oc_infomoteurtournant;                                 */
/*  output boolean Dft_oc_driver_vvt_adm;                                     */
/*  output boolean Dft_oc_pompe_ess_pwm;                                      */
/*  output boolean Dft_scg_driver_vvt_ech;                                    */
/*  output boolean Dft_scp_driver_vvt_ech;                                    */
/*  output boolean Dena_oc_sortielogiquedml;                                  */
/*  output boolean Dena_scg_sortielogiquedml;                                 */
/*  output boolean Dena_scp_sortielogiquedml;                                 */
/*  output boolean Dena_oc_cmdautoredemstt;                                   */
/*  output boolean Dena_oc_infomoteurtournant;                                */
/*  output boolean Dena_scg_infomoteurtournant;                               */
/*  output boolean Dena_oc_drvrseno2ds;                                       */
/*  output boolean Dena_scp_infomoteurtournant;                               */
/*  output boolean Dena_scg_cmdautoredemstt;                                  */
/*  output boolean Dena_oc_pompe_ess_pwm;                                     */
/*  output boolean Dft_scg_drvrseno2ds;                                       */
/*  output boolean Dft_scg_pompe_ess_pwm;                                     */
/*  output boolean Dena_scw_drvrseno2ds;                                      */
/*  output boolean Dena_scg_pompe_ess_pwm;                                    */
/*  output boolean Dft_scp_relais_puissance;                                  */
/*  output boolean Dena_scp_relais_puissance;                                 */
/*  output boolean Dft_scp_pompe_ess_pwm;                                     */
/*  output boolean Dft_scg_drvrseno2us;                                       */
/*  output boolean Dft_scp_cmd_dmtr;                                          */
/*  output boolean Dena_oc_drvrseno2us;                                       */
/*  output boolean Dena_scp_pompe_ess_pwm;                                    */
/*  output boolean Dena_scw_drvrseno2us;                                      */
/*  output boolean Dena_scg_driver_vvt_ech;                                   */
/*  output boolean Dft_oc_drvrseno2us;                                        */
/*  output boolean Dena_oc_driver_vvt_ech;                                    */
/*  output boolean Dena_scg_rechauffeurblowby1;                               */
/*  output boolean Dena_scp_driver_vvt_ech;                                   */
/*  output boolean Dft_oc_driver_vvt_ech;                                     */
/*  output boolean Dft_scp_sortielogiquedml;                                  */
/*  output boolean Dft_scg_sortielogiquedml;                                  */
/*  output boolean Dft_scg_infomoteurtournant;                                */
/*  output boolean Dft_scp_infomoteurtournant;                                */
/*  output boolean Dft_oc_relais_puissance;                                   */
/*  output boolean Dft_scp_cmdautoredemstt;                                   */
/*  output boolean Dft_scg_cmdautoredemstt;                                   */
/*  output boolean Dft_scw_drvrseno2ds;                                       */
/*  output boolean Dena_oc_rechauffeurblowby2;                                */
/*  output boolean Dena_scg_drvrseno2ds;                                      */
/*  output boolean Dena_scg_rechauffeurblowby2;                               */
/*  output boolean Dena_scg_relais_puissance;                                 */
/*  output boolean Dena_scw_rechauffeurblowby2;                               */
/*  output boolean Dft_oc_rechauffeurblowby2;                                 */
/*  output boolean Dft_scg_rechauffeurblowby2;                                */
/*  output boolean Dft_scw_rechauffeurblowby2;                                */
/*  output boolean Dft_scg_rechauffeurblowby1;                                */
/*  output boolean Dft_scw_rechauffeurblowby1;                                */
/*  output boolean Dft_oc_cstrdrv;                                            */
/*  output boolean Dft_oc_sortielogiquedml;                                   */
/*  output boolean Dena_scg_drvrseno2us;                                      */
/*  output boolean Dena_oc_cstrdrv;                                           */
/*  output boolean Dena_scw_cstrdrv;                                          */
/*  output boolean Dft_scw_cstrdrv;                                           */
/*  output boolean Dft_scg_cstrdrv;                                           */
/*  output boolean Dft_oc_drvrseno2ds;                                        */
/*  output boolean Dena_scg_cstrdrv;                                          */
/*  output boolean Dena_scw_rechauffeurblowby1;                               */
/*  output boolean Dft_oc_cmdautoredemstt;                                    */
/*  output boolean Dft_oc_rechauffeurblowby1;                                 */
/*  output boolean Dft_scw_drvrseno2us;                                       */
/*  output boolean Dena_oc_relais_puissance;                                  */
/*  output boolean Dena_scp_cmdautoredemstt;                                  */
/*  output uint8 Diag_elec_ectdrv;                                            */
/*  output boolean Dena_composant_bpm;                                        */
/*  output boolean Dena_surcharge_bpm;                                        */
/*  output boolean Dft_composant_bpm;                                         */
/*  output boolean Dft_surcharge_bpm;                                         */
/*  output boolean Dft_oc_driver_GMV1;                                        */
/*  output boolean Dft_scg_driver_GMV1;                                       */
/*  output boolean Dft_scp_driver_GMV1;                                       */
/*  output boolean Dena_oc_driver_GMV1;                                       */
/*  output boolean Dena_scg_driver_GMV1;                                      */
/*  output boolean Dena_scp_driver_GMV1;                                      */
/*  output boolean Dft_oc_driver_GMV2;                                        */
/*  output boolean Dft_scg_driver_GMV2;                                       */
/*  output boolean Dft_scp_driver_GMV2;                                       */
/*  output boolean Dena_oc_driver_GMV2;                                       */
/*  output boolean Dena_scg_driver_GMV2;                                      */
/*  output boolean Dena_scp_driver_GMV2;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidInit_OutPutCmdDiag(void)
{
   /*F00_Init_OutPutCmdDiag*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtMAIN_RELAY);

   if (  ((bfLocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_OPEN)) != 0)
      && ((bfLocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_OPEN)) != 0))
   {
      VEMS_vidSET(Dft_oc_cmd_relais_principal, 1);
   }
   else
   {
      VEMS_vidSET(Dft_oc_cmd_relais_principal, 0);
   }

   if (  ((bfLocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_SUPPLY)) != 0)
      && ((bfLocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_SUPPLY)) != 0))
   {
      VEMS_vidSET(Dft_scp_cmd_relais_principal, 1);
   }
   else
   {
      VEMS_vidSET(Dft_scp_cmd_relais_principal, 0);
   }

   if (  ((bfLocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfVALID_GROUND)) != 0)
      && ((bfLocalFault & (DGOHAL_tbfStatus)(DGOHAL_bfFAULT_GROUND)) != 0))
   {
      VEMS_vidSET(Dft_scg_cmd_relais_principal, 1);
   }
   else
   {
      VEMS_vidSET(Dft_scg_cmd_relais_principal, 0);
   }

   VEMS_vidSET(Dft_oc_cmd_dmtr, 0);
   VEMS_vidSET(Dft_scg_relais_puissance, 0);
   VEMS_vidSET(Dena_oc_cmd_dmtr, 0);
   VEMS_vidSET(Dft_scg_cmd_dmtr, 0);
   VEMS_vidSET(Dena_scg_cmd_dmtr, 0);
   VEMS_vidSET(Dena_scp_cmd_dmtr, 0);
   VEMS_vidSET(Dena_scp_driver_vvt_adm, 0);
   VEMS_vidSET(Dft_scp_driver_vvt_adm, 0);
   VEMS_vidSET(Dena_scg_driver_vvt_adm, 0);
   VEMS_vidSET(Dft_scg_driver_vvt_adm, 0);
   VEMS_vidSET(Dena_oc_driver_vvt_adm, 0);
   VEMS_vidSET(Dena_oc_rechauffeurblowby1, 0);
   VEMS_vidSET(Dft_oc_infomoteurtournant, 0);
   VEMS_vidSET(Dft_oc_driver_vvt_adm, 0);
   VEMS_vidSET(Dft_oc_pompe_ess_pwm, 0);
   VEMS_vidSET(Dft_scg_driver_vvt_ech, 0);
   VEMS_vidSET(Dft_scp_driver_vvt_ech, 0);
   VEMS_vidSET(Dena_oc_sortielogiquedml, 0);
   VEMS_vidSET(Dena_scg_sortielogiquedml, 0);
   VEMS_vidSET(Dena_scp_sortielogiquedml, 0);
   VEMS_vidSET(Dena_oc_cmdautoredemstt, 0);
   VEMS_vidSET(Dena_oc_infomoteurtournant, 0);
   VEMS_vidSET(Dena_scg_infomoteurtournant, 0);
   VEMS_vidSET(Dena_oc_drvrseno2ds, 0);
   VEMS_vidSET(Dena_scp_infomoteurtournant, 0);
   VEMS_vidSET(Dena_scg_cmdautoredemstt, 0);
   VEMS_vidSET(Dena_oc_pompe_ess_pwm, 0);
   VEMS_vidSET(Dft_scg_drvrseno2ds, 0);
   VEMS_vidSET(Dft_scg_pompe_ess_pwm, 0);
   VEMS_vidSET(Dena_scw_drvrseno2ds, 0);
   VEMS_vidSET(Dena_scg_pompe_ess_pwm, 0);
   VEMS_vidSET(Dft_scp_relais_puissance, 0);
   VEMS_vidSET(Dena_scp_relais_puissance, 0);
   VEMS_vidSET(Dft_scp_pompe_ess_pwm, 0);
   VEMS_vidSET(Dft_scg_drvrseno2us, 0);
   VEMS_vidSET(Dft_scp_cmd_dmtr, 0);
   VEMS_vidSET(Dena_oc_drvrseno2us, 0);
   VEMS_vidSET(Dena_scp_pompe_ess_pwm, 0);
   VEMS_vidSET(Dena_scw_drvrseno2us, 0);
   VEMS_vidSET(Dena_scg_driver_vvt_ech, 0);
   VEMS_vidSET(Dft_oc_drvrseno2us, 0);
   VEMS_vidSET(Dena_oc_driver_vvt_ech, 0);
   VEMS_vidSET(Dena_scg_rechauffeurblowby1, 0);
   VEMS_vidSET(Dena_scp_driver_vvt_ech, 0);
   VEMS_vidSET(Dft_oc_driver_vvt_ech, 0);
   VEMS_vidSET(Dft_scp_sortielogiquedml, 0);
   VEMS_vidSET(Dft_scg_sortielogiquedml, 0);
   VEMS_vidSET(Dft_scg_infomoteurtournant, 0);
   VEMS_vidSET(Dft_scp_infomoteurtournant, 0);
   VEMS_vidSET(Dft_oc_relais_puissance, 0);
   VEMS_vidSET(Dft_scp_cmdautoredemstt, 0);
   VEMS_vidSET(Dft_scg_cmdautoredemstt, 0);
   VEMS_vidSET(Dft_scw_drvrseno2ds, 0);
   VEMS_vidSET(Dena_oc_rechauffeurblowby2, 0);
   VEMS_vidSET(Dena_scg_drvrseno2ds, 0);
   VEMS_vidSET(Dena_scg_rechauffeurblowby2, 0);
   VEMS_vidSET(Dena_scg_relais_puissance, 0);
   VEMS_vidSET(Dena_scw_rechauffeurblowby2, 0);
   VEMS_vidSET(Dft_oc_rechauffeurblowby2, 0);
   VEMS_vidSET(Dft_scg_rechauffeurblowby2, 0);
   VEMS_vidSET(Dft_scw_rechauffeurblowby2, 0);
   VEMS_vidSET(Dft_scg_rechauffeurblowby1, 0);
   VEMS_vidSET(Dft_scw_rechauffeurblowby1, 0);
   VEMS_vidSET(Dft_oc_cstrdrv, 0);
   VEMS_vidSET(Dft_oc_sortielogiquedml, 0);
   VEMS_vidSET(Dena_scg_drvrseno2us, 0);
   VEMS_vidSET(Dena_oc_cstrdrv, 0);
   VEMS_vidSET(Dena_scw_cstrdrv, 0);
   VEMS_vidSET(Dft_scw_cstrdrv, 0);
   VEMS_vidSET(Dft_scg_cstrdrv, 0);
   VEMS_vidSET(Dft_oc_drvrseno2ds, 0);
   VEMS_vidSET(Dena_scg_cstrdrv, 0);
   VEMS_vidSET(Dena_scw_rechauffeurblowby1, 0);
   VEMS_vidSET(Dft_oc_cmdautoredemstt, 0);
   VEMS_vidSET(Dft_oc_rechauffeurblowby1, 0);
   VEMS_vidSET(Dft_scw_drvrseno2us, 0);
   VEMS_vidSET(Dena_oc_relais_puissance, 0);
   VEMS_vidSET(Dena_scp_cmdautoredemstt, 0);
   VEMS_vidSET(Diag_elec_ectdrv, 0);
   VEMS_vidSET(Dena_composant_bpm, 0);
   VEMS_vidSET(Dena_surcharge_bpm, 0);
   VEMS_vidSET(Dft_composant_bpm, 0);
   VEMS_vidSET(Dft_surcharge_bpm, 0);
   VEMS_vidSET(Dft_oc_driver_GMV1, 0);
   VEMS_vidSET(Dft_scg_driver_GMV1, 0);
   VEMS_vidSET(Dft_scp_driver_GMV1, 0);
   VEMS_vidSET(Dena_oc_driver_GMV1, 0);
   VEMS_vidSET(Dena_scg_driver_GMV1, 0);
   VEMS_vidSET(Dena_scp_driver_GMV1, 0);
   VEMS_vidSET(Dft_oc_driver_GMV2, 0);
   VEMS_vidSET(Dft_scg_driver_GMV2, 0);
   VEMS_vidSET(Dft_scp_driver_GMV2, 0);
   VEMS_vidSET(Dena_oc_driver_GMV2, 0);
   VEMS_vidSET(Dena_scg_driver_GMV2, 0);
   VEMS_vidSET(Dena_scp_driver_GMV2, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagGMV1GMV2                               */
/* !Description :  Trois types de diagnostic de pannes sont traités pour le   */
/*                 driver du GMV1 et GMV2 :panne circuit ouvert /panne        */
/*                 Court-circuit à la masse/panne Court-circuit               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_oc_driver_GMV1;                                       */
/*  output boolean Dft_oc_driver_GMV1;                                        */
/*  output boolean Dena_scp_driver_GMV1;                                      */
/*  output boolean Dft_scp_driver_GMV1;                                       */
/*  output boolean Dena_scg_driver_GMV1;                                      */
/*  output boolean Dft_scg_driver_GMV1;                                       */
/*  output boolean Dena_oc_driver_GMV2;                                       */
/*  output boolean Dft_oc_driver_GMV2;                                        */
/*  output boolean Dena_scp_driver_GMV2;                                      */
/*  output boolean Dft_scp_driver_GMV2;                                       */
/*  output boolean Dena_scg_driver_GMV2;                                      */
/*  output boolean Dft_scg_driver_GMV2;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagGMV1GMV2(void)
{
   /*CmdDiagGMV1GMV2*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtGMV_1);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_driver_GMV1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_driver_GMV1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_driver_GMV1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_driver_GMV1, 0);
      VEMS_vidSET(Dft_oc_driver_GMV1, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_driver_GMV1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_driver_GMV1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_driver_GMV1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_driver_GMV1, 0);
      VEMS_vidSET(Dft_scp_driver_GMV1, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_driver_GMV1, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_driver_GMV1, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_driver_GMV1, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_driver_GMV1, 0);
      VEMS_vidSET(Dft_scg_driver_GMV1, 0);
   }

   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtGMV_2);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      VEMS_vidSET(Dena_oc_driver_GMV2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         VEMS_vidSET(Dft_oc_driver_GMV2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_oc_driver_GMV2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_oc_driver_GMV2, 0);
      VEMS_vidSET(Dft_oc_driver_GMV2, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      VEMS_vidSET(Dena_scp_driver_GMV2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         VEMS_vidSET(Dft_scp_driver_GMV2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scp_driver_GMV2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scp_driver_GMV2, 0);
      VEMS_vidSET(Dft_scp_driver_GMV2, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      VEMS_vidSET(Dena_scg_driver_GMV2, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         VEMS_vidSET(Dft_scg_driver_GMV2, 1);
      }
      else
      {
         VEMS_vidSET(Dft_scg_driver_GMV2, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_scg_driver_GMV2, 0);
      VEMS_vidSET(Dft_scg_driver_GMV2, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagECTReq                                 */
/* !Description :  Trois types de diagnostic de pannes sont traités pour le   */
/*                 ECT command : panne circuit ouvert /panne Court-circuit à  */
/*                 la masse/panne Court-circuit                               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Diag_elec_ectdrv;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagECTReq(void)
{
   /*CmdDiagECTReq*/
   DGOHAL_tbfStatus bfLocalFault;
   uint8            u8LocalSum1;
   uint8            u8LocalSum2;
   uint8            u8LocalSum3;
   uint8            u8LocalSum4;
   uint8            u8LocalSum5;
   uint8            u8LocalSum6;
   uint8            u8LocalSumT;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtTHERMOSTAT_PILOTE);

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_OPEN) != 0)
   {
      u8LocalSum2 = 8;
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_OPEN) != 0)
      {
         u8LocalSum1 = 4;
      }
      else
      {
         u8LocalSum1 = 0;
      }
   }
   else
   {
      u8LocalSum2 = 0;
      u8LocalSum1 = 0;
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_SUPPLY) != 0)
   {
      u8LocalSum4 = 32;
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_SUPPLY) != 0)
      {
         u8LocalSum3 = 1;
      }
      else
      {
         u8LocalSum3 = 0;
      }
   }
   else
   {
      u8LocalSum4 = 0;
      u8LocalSum3 = 0;
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_GROUND) != 0)
   {
      u8LocalSum6 = 16;
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_GROUND) != 0)
      {
         u8LocalSum5 = 2;
      }
      else
      {
         u8LocalSum5 = 0;
      }
   }
   else
   {
      u8LocalSum6 = 0;
      u8LocalSum5 = 0;
   }
   u8LocalSumT = (uint8)( u8LocalSum1
                        + u8LocalSum2
                        + u8LocalSum3
                        + u8LocalSum4
                        + u8LocalSum5
                        + u8LocalSum6);
   VEMS_vidSET(Diag_elec_ectdrv, u8LocalSumT);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQDGOHAL_vidCmdDiagThrOverload                            */
/* !Description :  Fonction qui gère le diagnostic du papillon motorise actif */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret DGOHAL_tbfStatus  DGOHAL_bfRead(argin DGOHAL_tudtChannel      */
/*  udtChannel);                                                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Dena_composant_bpm;                                        */
/*  output boolean Dft_composant_bpm;                                         */
/*  output boolean Dena_surcharge_bpm;                                        */
/*  output boolean Dft_surcharge_bpm;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQDGOHAL_vidCmdDiagThrOverload(void)
{
   /*CmdDiagThrOverloadComponent*/
   DGOHAL_tbfStatus bfLocalFault;


   bfLocalFault = DGOHAL_bfRead(DGOHAL_udtCMD_THR);
   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_CMD_THR_HB) != 0)
   {
      VEMS_vidSET(Dena_composant_bpm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CMD_THR_HB) != 0)
      {
         VEMS_vidSET(Dft_composant_bpm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_composant_bpm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_composant_bpm, 0);
   }

   if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfVALID_CMD_THR_SCW) != 0)
   {
      VEMS_vidSET(Dena_surcharge_bpm, 1);
      if ((bfLocalFault & (DGOHAL_tbfStatus)DGOHAL_bfFAULT_CMD_THR_SCW) != 0)
      {
         VEMS_vidSET(Dft_surcharge_bpm, 1);
      }
      else
      {
         VEMS_vidSET(Dft_surcharge_bpm, 0);
      }
   }
   else
   {
      VEMS_vidSET(Dena_surcharge_bpm, 0);
   }
}
/*------------------------------- end of file --------------------------------*/