/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONAGCOR                                              */
/* !Description     : ADDONAGCOR Component                                    */
/*                                                                            */
/* !Module          : ADDONAGCOR                                              */
/* !Description     : DEFORMATION DE LA COURBE UNIQUE                         */
/*                                                                            */
/* !File            : ADDONAGCOR_FCT2.C                                       */
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
/*   1 / ADDONAGCOR_vidInterpolation                                          */
/*   2 / ADDONAGCOR_vidCoordination                                           */
/*                                                                            */
/* !Reference   : V02 NT 11 01473 / 01                                        */
/* !OtherRefs   : 01460_10_01467_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#054464                                         */
/* !OtherRefs   : VEMS V02 ECU#053827                                         */
/* !OtherRefs   : VEMS V02 ECU#058132                                         */
/* !OtherRefs   : VEMS V02 ECU#058205                                         */
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
#include "ADDONAGCOR.h"
#include "ADDONAGCOR_L.h"
#include "ADDONAGCOR_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidInterpolation                                */
/* !Description :  Fonction qui permet de calculer la valeur du coefficient de*/
/*                 déformation de la courbe de rendement d’avance à partir des*/
/*                 valeurs des modes courants et de consigne.                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_facFacAgCorBasModTar;                                   */
/*  input uint16 IgSys_facAgCorBas1ModTar;                                    */
/*  input uint16 IgSys_facAgCorBas2ModTar;                                    */
/*  input uint8 IgSys_facFacAgCorBasModCur;                                   */
/*  input uint16 IgSys_facAgCorBas1ModCur;                                    */
/*  input uint16 IgSys_facAgCorBas2ModCur;                                    */
/*  input uint8 IgSys_facFacAgCorTranMod;                                     */
/*  input uint16 IgSys_facAgCorTranTar_MP;                                    */
/*  input uint16 IgSys_facAgCorTranCur_MP;                                    */
/*  output uint16 IgSys_facAgCorTranTar_MP;                                   */
/*  output uint16 IgSys_facAgCorTranCur_MP;                                   */
/*  output uint16 IgSys_facAgCorTran;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidInterpolation(void)
{
   uint8  u8Localdiff;
   uint32 u32Localmult1;
   uint32 u32Localmult2;
   uint32 u32LocalranTar_MP;
   uint32 u32LocalTranCur_MP;


   /*Barycentre1*/
   if (  (IgSys_facFacAgCorBasModTar > 0)
      && (IgSys_facFacAgCorBasModTar < 100))
   {
      u8Localdiff = (uint8)(100 - IgSys_facFacAgCorBasModTar);
      u32Localmult1 = (uint32)(IgSys_facAgCorBas1ModTar
                            * (uint16)IgSys_facFacAgCorBasModTar);
      u32Localmult2 = (uint32)(IgSys_facAgCorBas2ModTar * (uint16)u8Localdiff);
      u32LocalranTar_MP = ((u32Localmult1 + u32Localmult2 + 50) / 100);
      IgSys_facAgCorTranTar_MP = (uint16)MATHSRV_udtMIN(u32LocalranTar_MP, 512);
   }
   else
   {
      if (IgSys_facFacAgCorBasModTar == 0)
      {
         IgSys_facAgCorTranTar_MP =
            (uint16)MATHSRV_udtMIN(IgSys_facAgCorBas2ModTar, 512);
      }
      else
      {
         IgSys_facAgCorTranTar_MP =
            (uint16)MATHSRV_udtMIN(IgSys_facAgCorBas1ModTar, 512);
      }
   }

   /*Barycentre2*/
   if (  (IgSys_facFacAgCorBasModCur > 0)
      && (IgSys_facFacAgCorBasModCur < 100))
   {
      u8Localdiff = (uint8)(100 - IgSys_facFacAgCorBasModCur);
      u32Localmult1 = (uint32)(IgSys_facAgCorBas1ModCur
                            * (uint16)IgSys_facFacAgCorBasModCur);
      u32Localmult2 = (uint32)(IgSys_facAgCorBas2ModCur * (uint16)u8Localdiff);
      u32LocalTranCur_MP = ((u32Localmult1 + u32Localmult2 + 50) / 100);
      IgSys_facAgCorTranCur_MP = (uint16)MATHSRV_udtMIN(u32LocalTranCur_MP,
                                                        512);
   }
   else
   {
      if (IgSys_facFacAgCorBasModCur == 0)
      {
         IgSys_facAgCorTranCur_MP =
            (uint16)MATHSRV_udtMIN(IgSys_facAgCorBas2ModCur, 512);
      }
      else
      {
         IgSys_facAgCorTranCur_MP =
            (uint16)MATHSRV_udtMIN(IgSys_facAgCorBas1ModCur, 512);
      }
   }

   /*Barycentre3*/
   if (  (IgSys_facFacAgCorTranMod > 0)
      && (IgSys_facFacAgCorTranMod < 100))
   {
      u8Localdiff = (uint8)(100 - IgSys_facFacAgCorTranMod);
      u32Localmult1 = (uint32)(IgSys_facAgCorTranTar_MP
                            * (uint16)IgSys_facFacAgCorTranMod);
      u32Localmult2 = (uint32)(IgSys_facAgCorTranCur_MP * (uint16)u8Localdiff);
      IgSys_facAgCorTran = (uint16)((u32Localmult1 + u32Localmult2 + 50) / 100);
   }
   else
   {
      if (IgSys_facFacAgCorTranMod == 0)
      {
         IgSys_facAgCorTran = IgSys_facAgCorTranCur_MP;
      }
      else
      {
         IgSys_facAgCorTran = IgSys_facAgCorTranTar_MP;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidCoordination                                 */
/* !Description :  Fonction qui coordonne les valeurs de coefficients de      */
/*                 déformation de la courbe de rendement d’avance pour les    */
/*                 différents combustibles et pour les différents modes de    */
/*                 fonctionnement.                                            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16ldxDft) boolean;                 */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_prm_facFlex[10];                                        */
/*  input uint8 IgSys_prm_facGas[10];                                         */
/*  input uint16 IgSys_facTarAgCorFlex;                                       */
/*  input uint16 IgSys_facTarAgCorGas;                                        */
/*  input boolean IgSys_bFlexFacAgCor_C;                                      */
/*  input uint16 IgSys_facAgCorTran;                                          */
/*  input boolean IgSys_bInhTarAgCor_C;                                       */
/*  input boolean IgSys_bGasFacAgCor_C;                                       */
/*  input uint16 IgSys_facAgCorSelTranFlex_MP;                                */
/*  output uint16 IgSys_facAgCorSelTranFlex_MP;                               */
/*  output uint16 IgSys_facTarAgCor;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidCoordination(void)
{
   boolean bLocalFRM_bInhTarAgCor;
   uint8   u8Localrate1;
   uint8   u8Localrate2;
   uint16  u16LocalIgSys_facTarAgCor;
   uint16  u16LocalIgSys_facTarAgCorFlex;
   uint16  u16LocalIgSys_facTarAgCorGas;
   uint32  u32LocalB2int1;
   uint32  u32LocalTranFlex_MP;
   uint32  u32LocaloutB2;
   uint32  u32Localmult1;
   uint32  u32Localmult2;
   uint32  u32LocalB1int1;


   bLocalFRM_bInhTarAgCor = GDGAR_bGetFRM(FRM_FRM_INHTARAGCOR);
   VEMS_vidGET1DArrayElement(IgSys_prm_facFlex, 4, u8Localrate1);
   VEMS_vidGET1DArrayElement(IgSys_prm_facGas, 4, u8Localrate2);
   VEMS_vidGET(IgSys_facTarAgCorFlex, u16LocalIgSys_facTarAgCorFlex);
   VEMS_vidGET(IgSys_facTarAgCorGas, u16LocalIgSys_facTarAgCorGas);

   if (IgSys_bFlexFacAgCor_C != 0)
   {
      u32LocalB1int1 = u16LocalIgSys_facTarAgCorFlex;
   }
   else
   {
      u32LocalB1int1 = u16LocalIgSys_facTarAgCorFlex + IgSys_facAgCorTran;
   }

   /*Barycentre1*/
   if (  (u8Localrate1 > 0)
      && (u8Localrate1 < 128))
   {
      u32Localmult1 = u32LocalB1int1 * u8Localrate1 ;
      u32Localmult2 = IgSys_facAgCorTran * (128 - u8Localrate1);
      u32LocalTranFlex_MP = (u32Localmult1 + u32Localmult2 + 64) / 128;
      IgSys_facAgCorSelTranFlex_MP = (uint16)MATHSRV_udtMIN(u32LocalTranFlex_MP,
                                                            512);
   }
   else
   {
      if (u8Localrate1 == 0)
      {
         IgSys_facAgCorSelTranFlex_MP =
            (uint16)MATHSRV_udtMIN(IgSys_facAgCorTran, 512);
      }
      else
      {
         IgSys_facAgCorSelTranFlex_MP =
            (uint16)MATHSRV_udtMIN(u32LocalB1int1, 512);
      }
   }

   if (  (IgSys_bInhTarAgCor_C != 0)
      || (bLocalFRM_bInhTarAgCor != 0))
   {
      VEMS_vidSET(IgSys_facTarAgCor, 256);
   }
   else
   {
      /*entree in1 barycentre2*/
      if (IgSys_bGasFacAgCor_C != 0)
      {
         u32LocalB2int1 = (uint32)u16LocalIgSys_facTarAgCorGas;
      }
      else
      {
         u32LocalB2int1 = (uint32)( u16LocalIgSys_facTarAgCorGas
                                  + IgSys_facAgCorSelTranFlex_MP);
      }
      /*barycentre2*/
      if (  (u8Localrate2 >0 )
         && (u8Localrate2 < 128))
      {
         u32Localmult1 = u32LocalB2int1 * u8Localrate2;
         u32Localmult2 = IgSys_facAgCorSelTranFlex_MP * (128 - u8Localrate2);
         u32LocaloutB2 = (u32Localmult1 + u32Localmult2 + 64) / 128;
      }
      else
      {
         if (u8Localrate2 == 0)
         {
            u32LocaloutB2 = (uint32)IgSys_facAgCorSelTranFlex_MP;
         }
         else
         {
            u32LocaloutB2 = u32LocalB2int1;
         }
      }
      u16LocalIgSys_facTarAgCor = (uint16)MATHSRV_udtMIN(u32LocaloutB2, 512);
      VEMS_vidSET(IgSys_facTarAgCor, u16LocalIgSys_facTarAgCor);
   }
}

/*------------------------------- end of file --------------------------------*/