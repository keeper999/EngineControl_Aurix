/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHMNG                                                  */
/* !Description     : VEHMNG component                                        */
/*                                                                            */
/* !Module          : VEHMNG                                                  */
/* !Description     : Gestion de la vitesse véhicule                          */
/*                                                                            */
/* !File            : VEHMNG_FCT2.C                                           */
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
/*   1 / VEHMNG_vidVehDstClcMng                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 05610 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VEHMNG/VEHMNG_FCT2.C_v            $*/
/* $Revision::   1.12     $$Author::   achebino       $$Date::   05 Oct 2012 $*/
/* $Author::   achebino                               $$Date::   05 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Std_Limits.h"
#include "VEHMNG.h"
#include "VEHMNG_L.h"
#include "VEHMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHMNG_vidVehDstClcMng                                     */
/* !Description :  La distance parcourue depuis le dernier clé ON  est        */
/*                 visualisable sous ADES par la variable                     */
/*                 Distance_parcourue_hectometre. Si l’on ne dispose pas de   */
/*                 cette information en interne CMM, on prend l’information   */
/*                 disponible sur le CAN.                                     */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Distance_parcourue_totale;                                   */
/*  input uint16 Distance_parcourue_hectometre;                               */
/*  input uint16 Distance_parcourue;                                          */
/*  input uint16 Distance_parcourue_prev;                                     */
/*  input uint32 Distance_parcourue_totale_prev;                              */
/*  output uint32 Distance_parcourue_totale_prev;                             */
/*  output uint16 Distance_parcourue_hecto_prev;                              */
/*  output uint32 Distance_parcourue_totale;                                  */
/*  output uint16 Distance_parcourue_hectometre;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHMNG_vidVehDstClcMng(void)
{
   /* 08_VehDstClc_Mng */
   uint16 u16LocalDistanceParcourueHecto;
   uint16 u16LocalDistance_parcourue;
   uint16 u16LocalDistTraveled;
   uint32 u32LocalDifference;


   Distance_parcourue_totale_prev = Distance_parcourue_totale;

   VEMS_vidGET(Distance_parcourue_hectometre, u16LocalDistanceParcourueHecto);
   VEMS_vidSET(Distance_parcourue_hecto_prev, u16LocalDistanceParcourueHecto);
   VEMS_vidGET(Distance_parcourue, u16LocalDistance_parcourue);
   if (u16LocalDistance_parcourue < Distance_parcourue_prev)
   {
      u16LocalDistTraveled = (uint16)( ( u16LocalDistance_parcourue
                                       - Distance_parcourue_prev)
                                     + 65535);
   }
   else
   {
      u16LocalDistTraveled = (uint16)( u16LocalDistance_parcourue
                                     - Distance_parcourue_prev);
   }

   u32LocalDifference = UINT32_MAX - Distance_parcourue_totale_prev;
   if (u16LocalDistTraveled <= u32LocalDifference)
   {
      Distance_parcourue_totale = ( Distance_parcourue_totale_prev
                                  + u16LocalDistTraveled);
   }
   else
   {
      Distance_parcourue_totale = UINT32_MAX;
   }
   if (Distance_parcourue_totale < 65535000)
   {
      u16LocalDistanceParcourueHecto = (uint16)( Distance_parcourue_totale
                                               / 1000);
   }
   else
   {
      u16LocalDistanceParcourueHecto = 65535;
   }

   VEMS_vidSET(Distance_parcourue_hectometre, u16LocalDistanceParcourueHecto);
}
/*---------------------------------end of file--------------------------------*/