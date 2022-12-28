/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : DCM_MANU_ACTUATOR_TST_FCT.c                             */
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
/*   1 / DCM_MANU_ActuatorTestCheckCond_Farsp                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5074350 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

#include "VEMS.H"




/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ActuatorTestCheckCond_Farsp                       */
/* !Description :  Fonction traitant les conditions d'exécution de la routine */
/*                 FASP                                                       */
/* !Number      :  ACTUATOR_TST_FCT.1                                         */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 ActrTstMng_nEngRunMaxTestFarSp_C;                            */
/*  input uint16 ActrTstMng_nEngRunMinTestFarSp_C;                            */
/*  input uint8 ActrTstMng_tCoMesMinTestFarSp_C;                              */
/*  output uint8 Srv_stRcActrTst;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean DCM_MANU_ActuatorTestCheckCond_Farsp(void)
{
   boolean            bLocalTestEnable;
   uint16             u16LocalExt_nEng;
   sint16             s16LocaltCoMes;
   sint16             s16LocaltCoMes_C;

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_tCoMes, s16LocaltCoMes);
   bLocalTestEnable = TRUE;

   /* entry: Srv_RcEngRunTooHighFarSp */
   if(u16LocalExt_nEng > ActrTstMng_nEngRunMaxTestFarSp_C)
   {
      Srv_stRcActrTst = RC_ENGINE_RUNNING_TOO_HIGH;
      bLocalTestEnable = FALSE;
   }
   else
   {
      /* entry: Srv_RcEngRunTooLowFarSp */
      if(u16LocalExt_nEng < ActrTstMng_nEngRunMinTestFarSp_C)
      {
         Srv_stRcActrTst = RC_ENGINE_RUNNING_TOO_LOW;
         bLocalTestEnable = FALSE;
      }
      else
      {
         /* entry: Srv_RcWaterTempTooLowFarSp */
         s16LocaltCoMes_C = (sint16)(ActrTstMng_tCoMesMinTestFarSp_C - 40);
         if (s16LocaltCoMes < s16LocaltCoMes_C)
         {
            Srv_stRcActrTst = RC_WATER_TEMP_TOO_LOW;
            bLocalTestEnable = FALSE;
         }
      }
   }

   return bLocalTestEnable;
}

