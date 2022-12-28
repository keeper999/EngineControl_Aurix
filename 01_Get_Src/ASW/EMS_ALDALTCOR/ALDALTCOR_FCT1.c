/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ALDALTCOR                                               */
/* !Description     : ALDALTCOR Component                                     */
/*                                                                            */
/* !Module          : ALDALTCOR                                               */
/* !Description     : Correction altimétrique de la charge en air             */
/*                                                                            */
/* !File            : ALDALTCOR_FCT1.C                                        */
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
/*   1 / ALDALTCOR_vidInitOutput                                              */
/*   2 / ALDALTCOR_vidAlticor                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 02165 / 01                                        */
/* !OtherRefs   : CSMT_CGMT09_2173_2 / 01                                     */
/* !OtherRefs   : VEMS V02 ECU#053821                                         */
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
#include "ALDALTCOR.h"
#include "ALDALTCOR_L.h"
#include "ALDALTCOR_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ALDALTCOR_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvSys_rAirLdAltiCor;                                       */
/*  output uint16 VlvSys_rAirLdPrfMod;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ALDALTCOR_vidInitOutput(void)
{
   VEMS_vidSET(VlvSys_rAirLdAltiCor, 0);
   VEMS_vidSET(VlvSys_rAirLdPrfMod, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ALDALTCOR_vidAlticor                                       */
/* !Description :  Fonction de correction altimétrique de la charge en air.   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_02165_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirSys_rAirLdReq;                                            */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 UsThrM_facPresAltiCor;                                       */
/*  input boolean VlvSys_bAirLdSel_C;                                         */
/*  input boolean VlvSys_bAirLdSelPrfMod_C;                                   */
/*  input boolean VlvSys_bAcvAltiCor_C;                                       */
/*  output uint16 VlvSys_rAirLdAltiCor;                                       */
/*  output uint16 VlvSys_rAirLdPrfMod;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ALDALTCOR_vidAlticor(void)
{
   uint16 u16LocalAirSys_rAirLdReq;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalUsThrM_facPresAltiCor;
   uint16 u16LocalVlvSys_rAirLdAltiCor;
   uint16 u16LocalVlvSys_rAirLdPrfMod;
   uint32 u32LocalMult_1;
   uint32 u32LocalMult_2;


   VEMS_vidGET(AirSys_rAirLdReq, u16LocalAirSys_rAirLdReq);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(UsThrM_facPresAltiCor, u16LocalUsThrM_facPresAltiCor);

   if (VlvSys_bAirLdSel_C != 0)
   {
      u32LocalMult_1 = (uint32)u16LocalAirSys_rAirLdReq;
   }
   else
   {
      u32LocalMult_1 = (uint32)u16LocalEngM_rAirLdCor;
   }

   if (VlvSys_bAirLdSelPrfMod_C != 0)
   {
      u32LocalMult_2 = (uint32)u16LocalAirSys_rAirLdReq;
   }
   else
   {
      u32LocalMult_2 = (uint32)u16LocalEngM_rAirLdCor;
   }

   if (VlvSys_bAcvAltiCor_C != 0)
   {
      u32LocalMult_1 = (u32LocalMult_1 * (uint32)u16LocalUsThrM_facPresAltiCor)
                       / 32768;
      u32LocalMult_2 = (u32LocalMult_2 * (uint32)u16LocalUsThrM_facPresAltiCor)
                       / 32768;
   }

   u16LocalVlvSys_rAirLdAltiCor = (uint16)MATHSRV_udtMIN(u32LocalMult_1, 49152);
   u16LocalVlvSys_rAirLdPrfMod = (uint16)MATHSRV_udtMIN(u32LocalMult_2, 49152);
   VEMS_vidSET(VlvSys_rAirLdAltiCor, u16LocalVlvSys_rAirLdAltiCor);
   VEMS_vidSET(VlvSys_rAirLdPrfMod, u16LocalVlvSys_rAirLdPrfMod);
}

/*------------------------------- end of file --------------------------------*/