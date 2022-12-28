/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGIDLEINTERFACE                                        */
/* !Description     : ENGIDLEINTERFACE Component                              */
/*                                                                            */
/* !Module          : ENGIDLEINTERFACE                                        */
/* !Description     : INTERFACE RALENTI MOTEUR ESSENCE                        */
/*                                                                            */
/* !File            : ENGIDLEINTERFACE_FCT1.C                                 */
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
/*   1 / ENGIDLEINTERFACE_vidInitOutput                                       */
/*   2 / ENGIDLEINTERFACE_vidBoucleStruct                                     */
/*   3 / ENGIDLEINTERFACE_vidSelGainRegul                                     */
/*   4 / ENGIDLEINTERFACE_vidCalcCouples                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 04614 / 02                                        */
/* !OtherRefs   : 01460_10_01449 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/LIBPSA/LOG/Ref/MOD_VEMS/TqStruct/ENGIDLEINTERFACE/$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGIDLEINTERFACE.h"
#include "ENGIDLEINTERFACE_L.h"
#include "ENGIDLEINTERFACE_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGIDLEINTERFACE_vidInitOutput                             */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean IdlSys_bAcvStrtTqSys;                                      */
/*  output uint8 IdlSys_idxIdlCtlMod;                                         */
/*  output sint16 IdlSys_tqIdcIdlMax;                                         */
/*  output sint16 IdlSys_tqIdcIdlMin;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGIDLEINTERFACE_vidInitOutput(void)
{
   VEMS_vidSET(IdlSys_bAcvStrtTqSys, 0);
   VEMS_vidSET(IdlSys_idxIdlCtlMod, 1);
   VEMS_vidSET(IdlSys_tqIdcIdlMax, 32000);
   VEMS_vidSET(IdlSys_tqIdcIdlMin, -32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGIDLEINTERFACE_vidBoucleStruct                           */
/* !Description :  Ce bloc permet de générer le flux de bouclage de la        */
/*                 structure couple à partir des informations de bouclage des */
/*                 branches avance et air.                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_04614_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IgSys_bAcvStructAdv;                                        */
/*  input boolean IgSys_bAcvStructAir;                                        */
/*  output boolean IdlSys_bAcvStrtTqSys;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGIDLEINTERFACE_vidBoucleStruct(void)
{
   boolean bLocalIgSys_bAcvStructAdv;
   boolean bLocalIgSys_bIgSys_bAcvStructAir;


   VEMS_vidGET(IgSys_bAcvStructAdv, bLocalIgSys_bAcvStructAdv);
   VEMS_vidGET(IgSys_bAcvStructAir, bLocalIgSys_bIgSys_bAcvStructAir);
   if (  (bLocalIgSys_bAcvStructAdv != 0)
      && (bLocalIgSys_bIgSys_bAcvStructAir != 0) )
   {
      VEMS_vidSET(IdlSys_bAcvStrtTqSys, 1);
   }
   else
   {
      VEMS_vidSET(IdlSys_bAcvStrtTqSys, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGIDLEINTERFACE_vidSelGainRegul                           */
/* !Description :  Ce bloc permet d’adapter les gains du régulateur de ralenti*/
/*                 en fonction du mode de combustion ou d’un défaut moteur    */
/*                 imposant une régulation de régime spécifique.              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_04614_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  output uint8 IdlSys_idxIdlCtlMod;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGIDLEINTERFACE_vidSelGainRegul(void)
{
   boolean bLocalEOM_bTWCHeatPha;
   boolean bLocalAcvIdlRegDft;


   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   bLocalAcvIdlRegDft = GDGAR_bGetFRM(FRM_FRM_ACVIDLREGDFT);
   if (bLocalAcvIdlRegDft != 0)
   {
      VEMS_vidSET(IdlSys_idxIdlCtlMod, 4);
   }
   else
   {
      if (bLocalEOM_bTWCHeatPha == 0)
      {
         VEMS_vidSET(IdlSys_idxIdlCtlMod, 1);
      }
      else
      {
         VEMS_vidSET(IdlSys_idxIdlCtlMod, 2);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGIDLEINTERFACE_vidCalcCouples                            */
/* !Description :  Ce bloc permet d’adapter les couples de saturation maximum */
/*                 et minimum à prendre en compte par le régulateur de        */
/*                 ralenti.                                                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_04614_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqIdcLdMaxTrbMax;                                     */
/*  input uint16 IdlSys_tqOfsIdlMax_C;                                        */
/*  input uint16 IdlSys_tqSatIdlMax_C;                                        */
/*  input sint16 EngLim_tqIdcLdMinAdvMin;                                     */
/*  input sint16 EngLim_tqIdcLdMinAdvMinSelc;                                 */
/*  input boolean IdlSys_bTqMinSel_C;                                         */
/*  input uint16 IdlSys_tqOfsIdlMin_C;                                        */
/*  input sint16 IdlSys_tqSatIdlMin_C;                                        */
/*  output sint16 IdlSys_tqIdcIdlMax;                                         */
/*  output sint16 IdlSys_tqIdcIdlMin;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGIDLEINTERFACE_vidCalcCouples(void)
{
   sint16 s16LocalEngLim_tqIdcLdMaxTrbMax;
   sint16 s16LocalEngLim_tqIdcLdMinAdvMin;
   sint16 s16LocalIdlSys_tqIdcIdlMax;
   sint16 s16LocalIdlSys_tqIdcIdlMin;
   sint16 s16LocalEngLim_tqIdcLdAdvMinSelc;
   sint32 s32LocalIdlSysTqSatIdlMaxC;
   sint32 s32LocalIdlSysTqSatIdlMinC;
   sint32 s32LocalIdlSysTqOfsIdlMax;
   sint32 s32LocalIdlSysTqOfsIdlMin;


   VEMS_vidGET(EngLim_tqIdcLdMaxTrbMax, s16LocalEngLim_tqIdcLdMaxTrbMax);
   s32LocalIdlSysTqOfsIdlMax = s16LocalEngLim_tqIdcLdMaxTrbMax
                             + (sint32)(IdlSys_tqOfsIdlMax_C * 4);
   s32LocalIdlSysTqSatIdlMaxC = IdlSys_tqSatIdlMax_C * 4;
   s32LocalIdlSysTqOfsIdlMax = MATHSRV_udtMIN(s32LocalIdlSysTqOfsIdlMax,
                                              s32LocalIdlSysTqSatIdlMaxC);
   s16LocalIdlSys_tqIdcIdlMax =
      (sint16)MATHSRV_udtMIN(s32LocalIdlSysTqOfsIdlMax, 32000);
   VEMS_vidSET(IdlSys_tqIdcIdlMax, s16LocalIdlSys_tqIdcIdlMax);

   VEMS_vidGET(EngLim_tqIdcLdMinAdvMin, s16LocalEngLim_tqIdcLdMinAdvMin);
   VEMS_vidGET(EngLim_tqIdcLdMinAdvMinSelc, s16LocalEngLim_tqIdcLdAdvMinSelc);
   if (IdlSys_bTqMinSel_C != 0)
   {
      s32LocalIdlSysTqOfsIdlMin = s16LocalEngLim_tqIdcLdMinAdvMin;
   }
   else
   {
      s32LocalIdlSysTqOfsIdlMin = s16LocalEngLim_tqIdcLdAdvMinSelc;
   }

   s32LocalIdlSysTqOfsIdlMin = s32LocalIdlSysTqOfsIdlMin -
                               (sint32)(IdlSys_tqOfsIdlMin_C * 4);

   s32LocalIdlSysTqSatIdlMinC = IdlSys_tqSatIdlMin_C * 4;
   s32LocalIdlSysTqOfsIdlMin =
      MATHSRV_udtMAX(s32LocalIdlSysTqOfsIdlMin, s32LocalIdlSysTqSatIdlMinC);
   s16LocalIdlSys_tqIdcIdlMin =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSysTqOfsIdlMin, -32000, 32000);
   VEMS_vidSET(IdlSys_tqIdcIdlMin, s16LocalIdlSys_tqIdcIdlMin);
}
/*------------------------------- end of file --------------------------------*/