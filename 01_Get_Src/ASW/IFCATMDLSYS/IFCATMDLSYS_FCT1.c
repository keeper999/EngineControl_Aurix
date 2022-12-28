/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFCATMDLSYS                                             */
/* !Description     : IFCATMDLSYS Component                                   */
/*                                                                            */
/* !Module          : IFCATMDLSYS                                             */
/* !Description     : INTERFACE OF CATMDL FUNCTION                            */
/*                                                                            */
/* !File            : IFCATMDLSYS_FCT1.C                                      */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IFCATMDLSYS_vidTWCMgtIf                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 06970 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#064711                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CATMDLSYS/IFCATMDLSYS/IFCATMDLSY$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   23 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   23 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "IFCATMDLSYS.h"
#include "IFCATMDLSYS_L.h"
#include "IFCATMDLSYS_IM.h"
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFCATMDLSYS_vidTWCMgtIf                                    */
/* !Description :  Fonction de determination des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input uint16 ExM_tExMnfEstim;                                             */
/*  input uint8 Cat_light_off_temperature_c;                                  */
/*  output boolean Cat_light_off_achieved;                                    */
/*  output boolean OxC_bOptmEfcldc_tOxCEstim;                                 */
/*  output uint16 Cat_temperature;                                            */
/*  output sint16 Ext_tOxCEstim;                                              */
/*  output uint16 Exhaust_gas_temp_real;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFCATMDLSYS_vidTWCMgtIf(void)
{
   uint16  u16LocalExM_tExMnfEstim;
   uint16  u16LocalExhaust_gas_temp_real;
   uint16  u16LocalCat_temperature;
   uint16  u16LocalExM_tOxCEstim;
   sint16  s16LocalExt_tOxCEstim;
   sint16  s16LocalExM_tOxCEstim;
   sint32  s32LocalCat_temperature;
   sint32  s32LocalExhaust_gas_temp_real;


   VEMS_vidGET(ExM_tOxCEstim, s16LocalExM_tOxCEstim);
   VEMS_vidGET(ExM_tExMnfEstim, u16LocalExM_tExMnfEstim);

   /* Production of Cat_light_off_achieved and OxC_bOptmEfcldc_tOxCEstim */
   u16LocalExM_tOxCEstim = (uint16)(Cat_light_off_temperature_c * 4);
   if (s16LocalExM_tOxCEstim > u16LocalExM_tOxCEstim)
   {
      VEMS_vidSET(Cat_light_off_achieved, 1);
      VEMS_vidSET(OxC_bOptmEfcldc_tOxCEstim, 1);
   }
   else
   {
      VEMS_vidSET(Cat_light_off_achieved, 0);
      VEMS_vidSET(OxC_bOptmEfcldc_tOxCEstim, 0);
   }

   /* Production of Cat_temperature */
   s32LocalCat_temperature = (sint32)((s16LocalExM_tOxCEstim + 50) * 32);
   u16LocalCat_temperature =
      (uint16)MATHSRV_udtCLAMP(s32LocalCat_temperature, 0, 65535);
   VEMS_vidSET(Cat_temperature, u16LocalCat_temperature);

   /* Production of Ext_tOxCEstim */
   s16LocalExt_tOxCEstim =
      (sint16)MATHSRV_udtCLAMP(s16LocalExM_tOxCEstim, -50, 1000);
   VEMS_vidSET(Ext_tOxCEstim, s16LocalExt_tOxCEstim);

   /* Production of Exhaust_gas_temp_real */
   s32LocalExhaust_gas_temp_real = ( (sint32)( (u16LocalExM_tExMnfEstim * 10)
                                             - 16048)
                                   / 10);
   u16LocalExhaust_gas_temp_real =
      (uint16)MATHSRV_udtMAX(s32LocalExhaust_gas_temp_real, 0);
   VEMS_vidSET(Exhaust_gas_temp_real, u16LocalExhaust_gas_temp_real);
}
/*------------------------------- end of file --------------------------------*/