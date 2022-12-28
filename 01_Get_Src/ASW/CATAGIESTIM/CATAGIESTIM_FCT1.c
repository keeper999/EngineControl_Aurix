/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CATAGIESTIM                                             */
/* !Description     : CATAGIESTIM Component                                   */
/*                                                                            */
/* !Module          : CATAGIESTIM                                             */
/* !Description     : Estimation du vieillissement catalyseur                 */
/*                                                                            */
/* !File            : CATAGIESTIM_FCT1.C                                      */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CATAGIESTIM_vidInitOutput                                            */
/*   2 / CATAGIESTIM_vidAgiCata                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 07305 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CATAGIESTIM/CATAGIESTIM_FCT1.C_v  $*/
/* $Revision::   1.2      $$Author::   ACHEBINO       $$Date::   28 Sep 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   28 Sep 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "CATAGIESTIM.H"
#include "CATAGIESTIM_L.H"
#include "CATAGIESTIM_IM.H"
#include "MATHSRV.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CATAGIESTIM_vidInitOutput                                  */
/* !Description :  Initialisation des outputs                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Cat_old_gain;                                                */
/*  output uint16 OxC_facDmgOxC;                                              */
/*  output uint8 Cat_old_gain_obd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CATAGIESTIM_vidInitOutput(void)
{
   VEMS_vidSET(Cat_old_gain, 0);
   VEMS_vidSET(OxC_facDmgOxC, 0);
   VEMS_vidSET(Cat_old_gain_obd, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CATAGIESTIM_vidAgiCata                                     */
/* !Description :  Optimisation des fonctions régulation de richesse et double*/
/*                 boucle en fonction du vieillissement catalyseur            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Km_vehicle_mux;                                              */
/*  input uint16 Km_vehicle_bkpt_map[8];                                      */
/*  input uint16 Km_vehicle_mux_uw;                                           */
/*  input uint8 Cat_old_gain_map[8];                                          */
/*  input uint8 Cat_old_gain_obd_map[8];                                      */
/*  output uint16 Km_vehicle_mux_uw;                                          */
/*  output uint8 Cat_old_gain;                                                */
/*  output uint16 OxC_facDmgOxC;                                              */
/*  output uint8 Cat_old_gain_obd;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CATAGIESTIM_vidAgiCata(void)
{
   uint8  u8LocalCatOldGain;
   uint8  u8LocalCatOldGainObd;
   uint16 u16LocalKmVehMux;
   uint16 u16LocalOxCFacDmgOxC;
   uint32 u32LocalKm_vehicle_mux_uw;

   VEMS_vidGET(Km_vehicle_mux, u32LocalKm_vehicle_mux_uw);

   u32LocalKm_vehicle_mux_uw = u32LocalKm_vehicle_mux_uw / 3;
   Km_vehicle_mux_uw = (uint16)MATHSRV_udtMIN(u32LocalKm_vehicle_mux_uw, 65535);
   u16LocalKmVehMux = MATHSRV_u16CalcParaIncAryU16(Km_vehicle_bkpt_map,
                                                   Km_vehicle_mux_uw,
                                                   8);
   u8LocalCatOldGain = MATHSRV_u8Interp1d(Cat_old_gain_map, u16LocalKmVehMux);
   u16LocalOxCFacDmgOxC = (uint16)(u8LocalCatOldGain * 128);

   u8LocalCatOldGainObd = MATHSRV_u8Interp1d(Cat_old_gain_obd_map,
                                             u16LocalKmVehMux);

   VEMS_vidSET(Cat_old_gain, u8LocalCatOldGain);
   VEMS_vidSET(OxC_facDmgOxC, u16LocalOxCFacDmgOxC);
   VEMS_vidSET(Cat_old_gain_obd, u8LocalCatOldGainObd);
}

/*------------------------------ end of file ---------------------------------*/