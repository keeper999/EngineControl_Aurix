/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKCRITZONE                                             */
/* !Description     : KNKCRITZONE Component                                   */
/*                                                                            */
/* !Module          : KNKCRITZONE                                             */
/* !Description     : DETECTION DE ZONE CRITIQUE                              */
/*                                                                            */
/* !File            : KNKCRITZONE_FCT1.C                                      */
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
/*   1 / KNKCRITZONE_vidInitialization                                        */
/*   2 / KNKCRITZONE_vidComputeCritZone                                       */
/*                                                                            */
/* !Reference   : V02 NT 08 05110 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKCRITZONE/KNKCRITZONE_FCT1$*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   14 Jan 2011 $*/
/* $Author::   wbouach                                $$Date::   14 Jan 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "KNKCRITZONE.H"
#include "KNKCRITZONE_L.H"
#include "KNKCRITZONE_IM.H"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKCRITZONE_vidInitialization                              */
/* !Description :  Le paramètre zone critique est initialisé à 0              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Oussama Hidri                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Zone_critique;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKCRITZONE_vidInitialization(void)
{
   VEMS_vidSET(Zone_critique, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKCRITZONE_vidComputeCritZone                             */
/* !Description :  La Table_zone_critique représente la zone où il est        */
/*                 physiquement possible d’avoir du cliquetis. Ainsi, on      */
/*                 définit un seuil mini en charge en dessous duquel on       */
/*                 considère qu’il ne peut pas y avoir de cliquetis           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Oussama Hidri                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 InThM_tAirUsInVlvEstim;                                      */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Mdyn_cor_cyl_int_temp_bkpt_map[9];                           */
/*  input uint8 Table_zone_critique[16][9];                                   */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input uint8 Seuil_temp_eau_zone_critique;                                 */
/*  output boolean Zone_critique;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKCRITZONE_vidComputeCritZone(void)
{
   uint8  u8LocalZoneCritique;
   uint8  u8LocalVehicle_active_state;
   uint8  u8LocalTemperature_eau;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalInThM_tAirUsInVlvEstim;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalCritZoneInterp;
   uint32 u32LocalEngineSpeedAdaptation;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(InThM_tAirUsInVlvEstim, u16LocalInThM_tAirUsInVlvEstim);
   u32LocalEngineSpeedAdaptation = (uint32)(u16LocalRegime_moteur * 8);
   u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u32LocalEngineSpeedAdaptation,
                                                  65535);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                                u16LocalRegime_moteur,
                                                16);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Mdyn_cor_cyl_int_temp_bkpt_map,
                                                u16LocalInThM_tAirUsInVlvEstim,
                                                9);
   u8LocalZoneCritique = MATHSRV_u8Interp2d(&Table_zone_critique[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            9);
   u16LocalCritZoneInterp = (uint16)(u8LocalZoneCritique * 256);

   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);

   if (  (u8LocalVehicle_active_state == VS_RUNNING)
      && (u8LocalTemperature_eau >= Seuil_temp_eau_zone_critique)
      && (u16LocalExt_rAirLd >= u16LocalCritZoneInterp))
   {
      VEMS_vidSET(Zone_critique, 1);
   }
   else
   {
      VEMS_vidSET(Zone_critique, 0);
   }
}

/*------------------------------- end of file --------------------------------*/