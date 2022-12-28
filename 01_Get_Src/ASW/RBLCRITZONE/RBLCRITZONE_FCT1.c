/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RBLCRITZONE                                             */
/* !Description     : RBLCRITZONE Component                                   */
/*                                                                            */
/* !Module          : RBLCRITZONE                                             */
/* !Description     : Rumble Critical Zone Detection                          */
/*                                                                            */
/* !File            : RBLCRITZONE_FCT1.C                                      */
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
/*   1 / RBLCRITZONE_vidInitialization                                        */
/*   2 / RBLCRITZONE_vidComputeCritZone                                       */
/*                                                                            */
/* !Reference   : V02 NT 12 00518 / 01                                        */
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
#include "MATHSRV.h"
#include "RBLCRITZONE.h"
#include "RBLCRITZONE_L.h"
#include "RBLCRITZONE_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLCRITZONE_vidInitialization                              */
/* !Description :  Le paramètre Zone_critique_Rbl est initialisé à 0          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Zone_critique_Rbl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLCRITZONE_vidInitialization(void)
{
   VEMS_vidSET(Zone_critique_Rbl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLCRITZONE_vidComputeCritZone                             */
/* !Description :  La KnkTreat_rAirLdAcvRblDet_M représente la zone où il est */
/*                 physiquement possible d’avoir du rumble                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u8Interp2d(????);                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 InThM_tAirUsInVlvEstim;                                      */
/*  input uint16 Regime_moteur_bkpt_map[16];                                  */
/*  input uint16 Mdyn_cor_cyl_int_temp_bkpt_map[9];                           */
/*  input uint8 KnkTreat_rAirLdAcvRblDet_M[16][9];                            */
/*  input st23 Vehicle_active_state;                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 Ext_rAirLd;                                                  */
/*  input sint16 KnkTreat_tCoAcvRblDet_C;                                     */
/*  output boolean Zone_critique_Rbl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLCRITZONE_vidComputeCritZone(void)
{
   uint8  u8LocalZoneCritique;
   uint8  u8LocalVehicle_active_state;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalInThM_tAirUsInVlvEstim;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalExt_rAirLd;
   uint16 u16LocalCritZoneInterp;
   sint16 s16LocalExt_tCoMes;
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
   u8LocalZoneCritique = MATHSRV_u8Interp2d(&KnkTreat_rAirLdAcvRblDet_M[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            9);
   u16LocalCritZoneInterp = (uint16)(u8LocalZoneCritique * 256);

   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_rAirLd, u16LocalExt_rAirLd);

   if ((u8LocalVehicle_active_state == VS_RUNNING)
      && (s16LocalExt_tCoMes >= KnkTreat_tCoAcvRblDet_C)
      && (u16LocalExt_rAirLd >= u16LocalCritZoneInterp))
   {
      VEMS_vidSET(Zone_critique_Rbl, 1);
   }
   else
   {
      VEMS_vidSET(Zone_critique_Rbl, 0);
   }
}

/*------------------------------- end of file --------------------------------*/