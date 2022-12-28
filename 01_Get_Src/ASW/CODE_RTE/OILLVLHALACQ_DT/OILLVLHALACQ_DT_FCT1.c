/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILLVLHALACQ_DT                                         */
/* !Description     : OILLVLHALACQ_DT Component                               */
/*                                                                            */
/* !Module          : OILLVLHALACQ_DT                                         */
/* !Description     : OILLVHAL acquisition                                    */
/*                                                                            */
/* !File            : OILLVLHALACQ_DT_FCT1.C                                  */
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
/*   1 / OILLVLHALACQ_DT_vidInitOutput                                        */
/*   2 / OILLVLHALACQ_DT_vidCdnLvlAcq                                         */
/*   3 / OILLVLHALACQ_DT_vidEnableLvlAcq                                      */
/*   4 / OILLVLHALACQ_DT_vidDisableLvlAcq                                     */
/*   5 / OILLVLHALACQ_DT_vidLvlAcq                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6873713 / 01                                        */
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

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "OILLVLHALACQ_DT.h"
#include "OILLVLHALACQ_DT_L.h"
#include "OILLVLHALACQ_DT_IM.h"
#include "OILLVHAL.h"
#include "OILLVLHALACQ_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLHALACQ_DT_vidInitOutput                              */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 AcquiState_stEngOilLvl;                                      */
/*  output uint16 FisrtAcqui_uEngOilLvl;                                      */
/*  output uint16 SecondAcqui_uEngOilLvl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLHALACQ_DT_vidInitOutput(void)
{
   VEMS_vidSET(AcquiState_stEngOilLvl, 0);
   VEMS_vidSET(FisrtAcqui_uEngOilLvl, 0);
   VEMS_vidSET(SecondAcqui_uEngOilLvl, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLHALACQ_DT_vidCdnLvlAcq                               */
/* !Description :  The BSW must be informed when the measure is authorized.   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILLVLHALACQ_DT_vidEnableLvlAcq();                       */
/*  extf argret void OILLVLHALACQ_DT_vidDisableLvlAcq();                      */
/*  input boolean Ext_stMeasAuth;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLHALACQ_DT_vidCdnLvlAcq(void)
{
   boolean bLocalExt_stMeasAuth;


   VEMS_vidGET(Ext_stMeasAuth, bLocalExt_stMeasAuth);
   if (bLocalExt_stMeasAuth != 0)
   {
      OILLVLHALACQ_DT_vidEnableLvlAcq();
   }
   else
   {
      OILLVLHALACQ_DT_vidDisableLvlAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLHALACQ_DT_vidEnableLvlAcq                            */
/* !Description :  Oil level acquisition is enabled when the measure is       */
/*                 authorized.                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVHAL_vidEnable();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLHALACQ_DT_vidEnableLvlAcq(void)
{
   OILLVHAL_vidEnable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLHALACQ_DT_vidDisableLvlAcq                           */
/* !Description :  Oil level acquisition is disabled when the measure is not  */
/*                 authorized.                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVHAL_vidDisable();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLHALACQ_DT_vidDisableLvlAcq(void)
{
   OILLVHAL_vidDisable();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLHALACQ_DT_vidLvlAcq                                  */
/* !Description :  Fonction that makes the acquisition of two average measures*/
/*                 on the oil level and returns the status of the oil level   */
/*                 acquisition.                                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  OILLVHAL_udtGetConversionResult(argout uint16 */
/*  *pu16FirstAcqui, argout uint16 *pu16SecondAcqui);                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 FisrtAcqui_uEngOilLvl;                                      */
/*  output uint16 SecondAcqui_uEngOilLvl;                                     */
/*  output uint8 AcquiState_stEngOilLvl;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLHALACQ_DT_vidLvlAcq(void)
{
   Std_ReturnType u8LocalRetValue;
   uint16         u16LocalFisrtAcqui;
   uint16         u16LocalSecondAcqui;


   u8LocalRetValue = OILLVHAL_udtGetConversionResult(&u16LocalFisrtAcqui,
                                                     &u16LocalSecondAcqui);
   u16LocalFisrtAcqui = (uint16)MATHSRV_udtMIN(u16LocalFisrtAcqui, 4096);
   VEMS_vidSET(FisrtAcqui_uEngOilLvl, u16LocalFisrtAcqui);
   u16LocalSecondAcqui = (uint16)MATHSRV_udtMIN(u16LocalSecondAcqui, 4096);
   VEMS_vidSET(SecondAcqui_uEngOilLvl, u16LocalSecondAcqui);
   VEMS_vidSET(AcquiState_stEngOilLvl, u8LocalRetValue);
}
/*-------------------------------- end of file -------------------------------*/