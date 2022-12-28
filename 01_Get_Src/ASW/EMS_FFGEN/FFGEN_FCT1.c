/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FFGEN                                                   */
/* !Description     : FFGEN Component                                         */
/*                                                                            */
/* !Module          : FFGEN                                                   */
/* !Description     : ESTIMER COUPLE REEL                                     */
/*                                                                            */
/* !File            : FFGEN_FCT1.C                                            */
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
/*   1 / FFGEN_vidInitOutput                                                  */
/*   2 / FFGEN_vidConstructionFrf                                             */
/*                                                                            */
/* !Reference   : V02 NT 10 01258 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2406 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/FFGEN/FFGEN_FCT1.C_v  $*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_Types.h"
#include "FFGEN.H"
#include "FFGEN_L.H"
#include "FFGEN_IM.H"
#include "VEMS.H"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FFGEN_vidInitOutput                                        */
/* !Description :  La fonction d' initialisation des entrées.                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output uint16 SftyMgt_prm_bFrf[8];                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FFGEN_vidInitOutput(void)
{
   uint8    u8Local_Count;
   uint16   u16Local_prm_bFrf[FFGEN_PrmBFrfSize];


   for(u8Local_Count=0; u8Local_Count < FFGEN_PrmBFrfSize; u8Local_Count++)
   {
      u16Local_prm_bFrf[u8Local_Count] = 0;
   }

   VEMS_vidSET1DArray(SftyMgt_prm_bFrf, FFGEN_PrmBFrfSize, u16Local_prm_bFrf);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FFGEN_vidConstructionFrf                                   */
/* !Description :  La fonction de construction du freeze frame.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 Ext_spdVeh;                                                   */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirSys_rAirLdReq;                                            */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 TqSys_tqIdcReq;                                              */
/*  output uint16 SftyMgt_prm_bFrf[8];                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FFGEN_vidConstructionFrf(void)
{
   uint8   u8Local_Ext_spdVeh;
   uint16  u16Local_Ext_nEng;
   uint16  u16Local_rAirLdReq;
   sint16  s16Local_tqIdcAirReq;
   sint16  s16Local_Ex_DsThrMes;
   sint16  s16Local_Ext_tCoMes;
   sint16  s16Local_Ex_uBattMes;
   sint16  s16Local_TqIdcReq;
   uint16  u16Local_prm_bFrf[FFGEN_PrmBFrfSize];


   VEMS_vidGET(Ext_spdVeh, u8Local_Ext_spdVeh);
   VEMS_vidGET(Ext_nEng, u16Local_Ext_nEng);
   VEMS_vidGET(AirSys_rAirLdReq, u16Local_rAirLdReq);
   VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_tqIdcAirReq);
   VEMS_vidGET(Ext_pDsThrMes, s16Local_Ex_DsThrMes);
   VEMS_vidGET(Ext_tCoMes, s16Local_Ext_tCoMes);
   VEMS_vidGET(Ext_uBattMes, s16Local_Ex_uBattMes);
   VEMS_vidGET(TqSys_tqIdcReq, s16Local_TqIdcReq);

   u16Local_prm_bFrf[0] = u16Local_Ext_nEng;
   u16Local_prm_bFrf[1] = (uint16)s16Local_Ex_uBattMes;
   u16Local_prm_bFrf[2] = u16Local_rAirLdReq;
   u16Local_prm_bFrf[3] = (uint16)s16Local_Ext_tCoMes;
   u16Local_prm_bFrf[4] = (uint16)s16Local_TqIdcReq;
   u16Local_prm_bFrf[5] = (uint16)s16Local_tqIdcAirReq;
   u16Local_prm_bFrf[6] = (uint16)s16Local_Ex_DsThrMes;
   u16Local_prm_bFrf[7] = (uint16)u8Local_Ext_spdVeh;

   VEMS_vidSET1DArray(SftyMgt_prm_bFrf, FFGEN_PrmBFrfSize, u16Local_prm_bFrf);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/******************************* <End_Of_File> ********************************/