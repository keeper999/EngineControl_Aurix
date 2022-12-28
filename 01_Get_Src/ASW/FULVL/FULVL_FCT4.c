/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FULVL                                                   */
/* !Description     : FULVL component.                                        */
/*                                                                            */
/* !Module          : FULVL                                                   */
/* !Description     : GESTION DU NIVEAU CARBURANT                             */
/*                                                                            */
/* !File            : FULVL_FCT4.C                                            */
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
/*   1 / FULVL_vid1BisDiagLowFuelLevel                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5462804 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#049911                                         */
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
#include "FULVL.h"
#include "FULVL_L.h"
#include "FULVL_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FULVL_vid1BisDiagLowFuelLevel                              */
/* !Description :  Le flag niveau carburant mini peut être fourni par une     */
/*                 information CAN ou par une information filaire.            */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean FuLvl_bAcvDiagLoFuLvl_C;                                    */
/*  input boolean Ext_bLowFuelLevelSel;                                       */
/*  input boolean Flev_low_fuel_level_fil;                                    */
/*  input boolean Flev_low_fuel_level_can;                                    */
/*  output boolean FuLvl_bMonRunLoFuLvl;                                      */
/*  output boolean Flev_low_fuel_level;                                       */
/*  output boolean FuLvl_bDgoLoFuLvl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FULVL_vid1BisDiagLowFuelLevel(void)
{
   boolean bLocalInhFuLowLvlHw;
   boolean bLocalExt_bLowFuelLevelSel;
   boolean bLocalFlev_low_fuel_level;


   bLocalInhFuLowLvlHw = GDGAR_bGetFRM(FRM_FRM_INHFULOWLVLHW);
   FuLvl_bMonRunLoFuLvl = FuLvl_bAcvDiagLoFuLvl_C;
   if (bLocalInhFuLowLvlHw != 0)
   {
      bLocalFlev_low_fuel_level = 0;
   }
   else
   {
      VEMS_vidGET(Ext_bLowFuelLevelSel, bLocalExt_bLowFuelLevelSel);
      if (bLocalExt_bLowFuelLevelSel != 0)
      {
         VEMS_vidGET(Flev_low_fuel_level_fil, bLocalFlev_low_fuel_level);
      }
      else
      {
         bLocalFlev_low_fuel_level = Flev_low_fuel_level_can;
      }
   }
   VEMS_vidSET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   FuLvl_bDgoLoFuLvl = bLocalFlev_low_fuel_level;
}
/*------------------------------- end of file --------------------------------*/