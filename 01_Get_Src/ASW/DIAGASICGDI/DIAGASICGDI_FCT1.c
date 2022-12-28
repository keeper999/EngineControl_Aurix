/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGASICGDI                                             */
/* !Description     : DIAGASICGDI component                                   */
/*                                                                            */
/* !Module          : DIAGASICGDI                                             */
/* !Description     : DIAGNOSTIC DE L’ASIC GDI                                */
/*                                                                            */
/* !File            : DIAGASICGDI_FCT1.C                                      */
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
/*   1 / DIAGASICGDI_vidDiag_ASICGDI                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6930924 / 01                                        */
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
#include "DIAGASICGDI.h"
#include "DIAGASICGDI_L.h"
#include "DIAGASICGDI_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGASICGDI_vidDiag_ASICGDI                                */
/* !Description :  Fonction bouchon                                           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.Boubakri                                                 */
/* !Trace_To    :  PTS_R_5073344_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input boolean Dena_ComSpi_ASICGDI;                                        */
/*  input boolean Dena_OverVBat_ASICGDI;                                      */
/*  input boolean Dena_OverVBoost_ASICGDI;                                    */
/*  input boolean Dena_UnderVBat_ASICGDI;                                     */
/*  input boolean Dena_UnderVBoost_ASICGDI;                                   */
/*  input boolean Dft_ComSpi_ASICGDI;                                         */
/*  input boolean Dft_OverVBat_ASICGDI;                                       */
/*  input boolean Dft_OverVBoost_ASICGDI;                                     */
/*  input boolean Dft_UnderVBat_ASICGDI;                                      */
/*  input boolean Dft_UnderVBoost_ASICGDI;                                    */
/*  input boolean Ext_bDftOverVbat_Diagasicgdi;                               */
/*  input boolean Ext_bDftUnderVbat_Diagasicgdi;                              */
/*  input boolean Ext_bDftOverVboost_Diagasicgdi;                             */
/*  input boolean Ext_bDftUnderVboost_Diagasicgdi;                            */
/*  input boolean Ext_bMonRunOverVbat_Diagasicgdi;                            */
/*  input boolean Ext_bMonRunUnderVbat_Diagasicgdi;                           */
/*  input boolean Ext_bMonRunOverVboost_Diagasic;                             */
/*  input boolean Ext_bMonRunUnderVboost_Diagasic;                            */
/*  input boolean Ext_bMonRunVbat_Diagasicgdi;                                */
/*  input boolean Ext_bMonRunComSpi_Diagasicgdi;                              */
/*  input boolean Ext_bMonRunVboost_Diagasicgdi;                              */
/*  input boolean Ext_bDftVbat_Diagasicgdi;                                   */
/*  input boolean Ext_bdftComSpi_Diagasicgdi;                                 */
/*  input boolean Ext_bDftVboost_Diagasicgdi;                                 */
/*  output boolean Ext_bMonRunOverVbat_Diagasicgdi;                           */
/*  output boolean Ext_bDftOverVbat_Diagasicgdi;                              */
/*  output boolean Ext_bMonRunUnderVbat_Diagasicgdi;                          */
/*  output boolean Ext_bDftUnderVbat_Diagasicgdi;                             */
/*  output boolean Ext_bDftVbat_Diagasicgdi;                                  */
/*  output boolean Ext_bMonRunComSpi_Diagasicgdi;                             */
/*  output boolean Ext_bdftComSpi_Diagasicgdi;                                */
/*  output boolean Ext_bMonRunOverVboost_Diagasic;                            */
/*  output boolean Ext_bDftOverVboost_Diagasicgdi;                            */
/*  output boolean Ext_bMonRunUnderVboost_Diagasic;                           */
/*  output boolean Ext_bDftUnderVboost_Diagasicgdi;                           */
/*  output boolean Ext_bDftVboost_Diagasicgdi;                                */
/*  output boolean Ext_bMonRunVbat_Diagasicgdi;                               */
/*  output boolean Ext_bMonRunVboost_Diagasicgdi;                             */
/*  output boolean Ext_bMonRunAsicGdiFailure;                                 */
/*  output boolean Ext_bDgoAsicGdiFailure;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGASICGDI_vidDiag_ASICGDI(void)
{
   boolean bLocalDena_ComSpi_ASICGDI;
   boolean bLocalDena_OverVBat_ASICGDI;
   boolean bLocalDena_OverVBoost_ASICGDI;
   boolean bLocalDena_UnderVBat_ASICGDI;
   boolean bLocalDena_UnderVBoost_ASICGDI;
   boolean bLocalDft_ComSpi_ASICGDI;
   boolean bLocalDft_OverVBat_ASICGDI;
   boolean bLocalDft_OverVBoost_ASICGDI;
   boolean bLocalDft_UnderVBat_ASICGDI;
   boolean bLocalDft_UnderVBoost_ASICGDI;
   boolean bLocalInhDiag_ASICGDI;


   VEMS_vidGET(Dena_ComSpi_ASICGDI, bLocalDena_ComSpi_ASICGDI);
   VEMS_vidGET(Dena_OverVBat_ASICGDI, bLocalDena_OverVBat_ASICGDI);
   VEMS_vidGET(Dena_OverVBoost_ASICGDI, bLocalDena_OverVBoost_ASICGDI);
   VEMS_vidGET(Dena_UnderVBat_ASICGDI, bLocalDena_UnderVBat_ASICGDI);
   VEMS_vidGET(Dena_UnderVBoost_ASICGDI, bLocalDena_UnderVBoost_ASICGDI);
   VEMS_vidGET(Dft_ComSpi_ASICGDI, bLocalDft_ComSpi_ASICGDI);
   VEMS_vidGET(Dft_OverVBat_ASICGDI, bLocalDft_OverVBat_ASICGDI);
   VEMS_vidGET(Dft_OverVBoost_ASICGDI, bLocalDft_OverVBoost_ASICGDI);
   VEMS_vidGET(Dft_UnderVBat_ASICGDI, bLocalDft_UnderVBat_ASICGDI);
   VEMS_vidGET(Dft_UnderVBoost_ASICGDI, bLocalDft_UnderVBoost_ASICGDI);

   if (bLocalDena_OverVBat_ASICGDI != 0)
   {
      Ext_bMonRunOverVbat_Diagasicgdi = 1;
      if (bLocalDft_OverVBat_ASICGDI != 0)
      {
         Ext_bDftOverVbat_Diagasicgdi = 1;
      }
      else
      {
         Ext_bDftOverVbat_Diagasicgdi = 0;
      }
   }
   else
   {
      Ext_bMonRunOverVbat_Diagasicgdi = 0;
      Ext_bDftOverVbat_Diagasicgdi = 0;
   }

   if (bLocalDena_UnderVBat_ASICGDI != 0)
   {
      Ext_bMonRunUnderVbat_Diagasicgdi = 1;
      if (bLocalDft_UnderVBat_ASICGDI != 0)
      {
         Ext_bDftUnderVbat_Diagasicgdi = 1;
      }
      else
      {
         Ext_bDftUnderVbat_Diagasicgdi = 0;
      }
   }
   else
   {
      Ext_bMonRunUnderVbat_Diagasicgdi = 0;
      Ext_bDftUnderVbat_Diagasicgdi = 0;
   }

   if (  (Ext_bDftOverVbat_Diagasicgdi != 0)
      || (Ext_bDftUnderVbat_Diagasicgdi != 0))
   {
      Ext_bDftVbat_Diagasicgdi = 1;
   }
   else
   {
      Ext_bDftVbat_Diagasicgdi = 0;
   }

   if (bLocalDena_ComSpi_ASICGDI != 0)
   {
      Ext_bMonRunComSpi_Diagasicgdi = 1;
      if (bLocalDft_ComSpi_ASICGDI != 0)
      {
         Ext_bdftComSpi_Diagasicgdi = 1;
      }
      else
      {
         Ext_bdftComSpi_Diagasicgdi = 0;
      }
   }
   else
   {
      Ext_bMonRunComSpi_Diagasicgdi = 0;
      Ext_bdftComSpi_Diagasicgdi = 0;
   }

   if (bLocalDena_OverVBoost_ASICGDI != 0)
   {
      Ext_bMonRunOverVboost_Diagasic = 1;
      if (bLocalDft_OverVBoost_ASICGDI != 0)
      {
         Ext_bDftOverVboost_Diagasicgdi = 1;
      }
      else
      {
         Ext_bDftOverVboost_Diagasicgdi = 0;
      }
   }
   else
   {
      Ext_bMonRunOverVboost_Diagasic = 0;
      Ext_bDftOverVboost_Diagasicgdi = 0;
   }

   if (bLocalDena_UnderVBoost_ASICGDI != 0)
   {
      Ext_bMonRunUnderVboost_Diagasic = 1;
      if (bLocalDft_UnderVBoost_ASICGDI != 0)
      {
         Ext_bDftUnderVboost_Diagasicgdi = 1;
      }
      else
      {
         Ext_bDftUnderVboost_Diagasicgdi = 0;
      }
   }
   else
   {
      Ext_bMonRunUnderVboost_Diagasic = 0;
      Ext_bDftUnderVboost_Diagasicgdi = 0;
   }

   if (  (Ext_bDftOverVboost_Diagasicgdi != 0)
      || (Ext_bDftUnderVboost_Diagasicgdi != 0))
   {
      Ext_bDftVboost_Diagasicgdi = 1;
   }
   else
   {
      Ext_bDftVboost_Diagasicgdi = 0;
   }

   if (  (Ext_bMonRunOverVbat_Diagasicgdi != 0)
      || (Ext_bMonRunUnderVbat_Diagasicgdi != 0))
   {
      Ext_bMonRunVbat_Diagasicgdi = 1;
   }
   else
   {
      Ext_bMonRunVbat_Diagasicgdi = 0;
   }

   if (  (Ext_bMonRunOverVboost_Diagasic != 0)
      || (Ext_bMonRunUnderVboost_Diagasic != 0))
   {
      Ext_bMonRunVboost_Diagasicgdi = 1;
   }
   else
   {
      Ext_bMonRunVboost_Diagasicgdi = 0;
   }

   bLocalInhDiag_ASICGDI = GDGAR_bGetFRM(FRM_FRM_INHDIAG_ASICGDI);

   if (  (bLocalInhDiag_ASICGDI == 0)
      && (  (Ext_bMonRunVbat_Diagasicgdi != 0)
         || (Ext_bMonRunComSpi_Diagasicgdi != 0)
         || (Ext_bMonRunVboost_Diagasicgdi != 0)))
   {
      Ext_bMonRunAsicGdiFailure = 1;
   }
   else
   {
      Ext_bMonRunAsicGdiFailure = 0;
   }

   if (  (Ext_bDftVbat_Diagasicgdi != 0)
      || (Ext_bdftComSpi_Diagasicgdi != 0)
      || (Ext_bDftVboost_Diagasicgdi != 0))
   {
      Ext_bDgoAsicGdiFailure = 1;
   }
   else
   {
      Ext_bDgoAsicGdiFailure = 0;
   }
}
/*------------------------------- end of file --------------------------------*/