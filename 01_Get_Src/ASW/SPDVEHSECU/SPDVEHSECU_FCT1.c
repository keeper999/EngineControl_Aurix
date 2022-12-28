/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPDVEHSECU                                              */
/* !Description     : SPDVEHSECU component.                                   */
/*                                                                            */
/* !Module          : SPDVEHSECU                                              */
/* !Description     : Calculation of a secured speed for the STT function     */
/*                                                                            */
/* !File            : SPDVEHSECU_FCT1.C                                       */
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
/*   1 / SPDVEHSECU_vidInitOutput                                             */
/*   2 / SPDVEHSECU_vidIni                                                    */
/*   3 / SPDVEHSECU_vidSecuredSpeedInfo                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5664717 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SPDVEHSECU/SPDVEHSECU_FCT1.c_v    $*/
/* $Revision::   1.1      $$Author::   ACHEBINO       $$Date::   09 May 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   09 May 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SPDVEHSECU.h"
#include "SPDVEHSECU_L.h"
#include "SPDVEHSECU_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPDVEHSECU_vidInitOutput                                   */
/* !Description :  Fonction permettant l'initialisation de certaines variables*/
/*                 au début du calcul                                         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_spdVehIni_C;                                         */
/*  output uint16 SPDVEHSECU_U16OutputFilter1;                                */
/*  output uint16 SPDVEHSECU_U16OutputFilter2;                                */
/*  output uint16 SPDVEHSECU_U16OutputFilter3;                                */
/*  output uint16 SPDVEHSECU_U16OutputFilter4;                                */
/*  output uint32 SPDVEHSECU_U32OutputFilter1Mem;                             */
/*  output uint32 SPDVEHSECU_U32OutputFilter2Mem;                             */
/*  output uint32 SPDVEHSECU_U32OutputFilter3Mem;                             */
/*  output uint32 SPDVEHSECU_U32OutputFilter4Mem;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPDVEHSECU_vidInitOutput(void)
{
   uint16  u16LocalSftyMgtspdVehIni;


   u16LocalSftyMgtspdVehIni = (uint16)(((25 * SftyMgt_spdVehIni_C) + 16) / 32);
   SPDVEHSECU_U16OutputFilter1 = u16LocalSftyMgtspdVehIni;
   SPDVEHSECU_U16OutputFilter2 = u16LocalSftyMgtspdVehIni;
   SPDVEHSECU_U16OutputFilter3 = u16LocalSftyMgtspdVehIni;
   SPDVEHSECU_U16OutputFilter4 = u16LocalSftyMgtspdVehIni;
   SPDVEHSECU_U32OutputFilter1Mem = (uint32)(65536 * u16LocalSftyMgtspdVehIni);
   SPDVEHSECU_U32OutputFilter2Mem = (uint32)(65536 * u16LocalSftyMgtspdVehIni);
   SPDVEHSECU_U32OutputFilter3Mem = (uint32)(65536 * u16LocalSftyMgtspdVehIni);
   SPDVEHSECU_U32OutputFilter4Mem = (uint32)(65536 * u16LocalSftyMgtspdVehIni);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPDVEHSECU_vidIni                                          */
/* !Description :  Fonction d'initialisation des variables au Reset           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_spdVehIni_C;                                         */
/*  output uint16 Ext_spdVehSecu;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPDVEHSECU_vidIni(void)
{
   uint16  u16LocalExtspdVehSecu;


   u16LocalExtspdVehSecu = (uint16)MATHSRV_udtMIN(SftyMgt_spdVehIni_C, 64000);
   VEMS_vidSET(Ext_spdVehSecu, u16LocalExtspdVehSecu);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPDVEHSECU_vidSecuredSpeedInfo                             */
/* !Description :  Fonction permettant la determination d'une information     */
/*                 sécurisée de la vitesse véhicule, à partir des vitesses de */
/*                 chacune des quatre roues                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  LDHI                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ISCAN_u16N16F30DP263;                                        */
/*  input uint16 ISCAN_u16N16F30DP264;                                        */
/*  input uint16 ISCAN_u16N16F30DP265;                                        */
/*  input uint16 ISCAN_u16N16F30DP266;                                        */
/*  input uint16 SftyMgt_facFilSpdVeh_C;                                      */
/*  input uint32 SPDVEHSECU_U32OutputFilter1Mem;                              */
/*  input uint32 SPDVEHSECU_U32OutputFilter2Mem;                              */
/*  input uint32 SPDVEHSECU_U32OutputFilter3Mem;                              */
/*  input uint32 SPDVEHSECU_U32OutputFilter4Mem;                              */
/*  input uint16 SftyMgt_spdVeh_inh_C;                                        */
/*  input uint16 SPDVEHSECU_U16OutputFilter1;                                 */
/*  input uint16 SPDVEHSECU_U16OutputFilter2;                                 */
/*  input uint16 SPDVEHSECU_U16OutputFilter3;                                 */
/*  input uint16 SPDVEHSECU_U16OutputFilter4;                                 */
/*  input uint16 SftyMgt_spdVehMinVal;                                        */
/*  input uint16 SftyMgt_spdVehMax_inh_C;                                     */
/*  output uint16 SPDVEHSECU_U16OutputFilter1;                                */
/*  output uint16 SPDVEHSECU_U16OutputFilter2;                                */
/*  output uint16 SPDVEHSECU_U16OutputFilter3;                                */
/*  output uint16 SPDVEHSECU_U16OutputFilter4;                                */
/*  output uint16 SftyMgt_spdVehMinVal;                                       */
/*  output uint16 Ext_spdVehSecu;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPDVEHSECU_vidSecuredSpeedInfo(void)
{
   boolean bLocallnhDiag_noSpdSecu;
   boolean bLocalResult263;
   boolean bLocalResult264;
   boolean bLocalResult265;
   boolean bLocalResult266;
   uint8   u8LocalResult;
   uint16  u16LocalISCAN_u16N16F30DP263;
   uint16  u16LocalISCAN_u16N16F30DP264;
   uint16  u16LocalISCAN_u16N16F30DP265;
   uint16  u16LocalISCAN_u16N16F30DP266;
   uint16  u16LocalSftyMgtfacFilSpdVeh;
   uint16  u16LocalSftyMgtspdVehMinVa1;
   uint16  u16LocalSftyMgtspdVehMinVa2;
   uint16  u16LocalMinOut1;
   uint16  u16LocalMinOut2;
   uint16  u16LocalExtspdVehSecu;
   uint16  u16LocalOut1;
   uint16  u16LocalOut2;
   uint16  u16LocalOut3;
   uint16  u16LocalOut4;
   uint16  u16LocaloutputFilter;
   uint32  u32LocalExtspdVehSecu;
   uint32  u32LocalSftyMgtfacFilSpdVeh;


   VEMS_vidGET(ISCAN_u16N16F30DP263, u16LocalISCAN_u16N16F30DP263);
   VEMS_vidGET(ISCAN_u16N16F30DP264, u16LocalISCAN_u16N16F30DP264);
   VEMS_vidGET(ISCAN_u16N16F30DP265, u16LocalISCAN_u16N16F30DP265);
   VEMS_vidGET(ISCAN_u16N16F30DP266, u16LocalISCAN_u16N16F30DP266);
   /*FRM*/
   bLocallnhDiag_noSpdSecu = GDGAR_bGetFRM(FRM_FRM_INHDIAG_NOSPDSECU);
   /*Calcul GAIN */
   u32LocalSftyMgtfacFilSpdVeh = (uint32)( ( ( SftyMgt_facFilSpdVeh_C
                                             * 65536)
                                           + 16384)
                                         / 32768);
   u16LocalSftyMgtfacFilSpdVeh =
      (uint16)MATHSRV_udtMIN(u32LocalSftyMgtfacFilSpdVeh, 65535);
   /* Msg(3:3356) prouved by Unit test */
   /*Calcul FILTER */
   u16LocaloutputFilter =
      MATHSRV_u16FirstOrderFilterGu16(u16LocalSftyMgtfacFilSpdVeh,
                                      &SPDVEHSECU_U32OutputFilter1Mem,
                                      u16LocalISCAN_u16N16F30DP263);
   SPDVEHSECU_U16OutputFilter1 =
      (uint16)MATHSRV_udtMIN(u16LocaloutputFilter, 65533);
   u16LocaloutputFilter =
      MATHSRV_u16FirstOrderFilterGu16(u16LocalSftyMgtfacFilSpdVeh,
                                      &SPDVEHSECU_U32OutputFilter2Mem,
                                      u16LocalISCAN_u16N16F30DP264);
   SPDVEHSECU_U16OutputFilter2 =
      (uint16)MATHSRV_udtMIN(u16LocaloutputFilter, 65533);
   u16LocaloutputFilter =
      MATHSRV_u16FirstOrderFilterGu16(u16LocalSftyMgtfacFilSpdVeh,
                                      &SPDVEHSECU_U32OutputFilter3Mem,
                                      u16LocalISCAN_u16N16F30DP265);
   SPDVEHSECU_U16OutputFilter3 =
      (uint16)MATHSRV_udtMIN(u16LocaloutputFilter, 65533);
   u16LocaloutputFilter =
      MATHSRV_u16FirstOrderFilterGu16(u16LocalSftyMgtfacFilSpdVeh,
                                      &SPDVEHSECU_U32OutputFilter4Mem,
                                      u16LocalISCAN_u16N16F30DP266);
   SPDVEHSECU_U16OutputFilter4 =
      (uint16)MATHSRV_udtMIN(u16LocaloutputFilter, 65533);
   if (bLocallnhDiag_noSpdSecu != 0)
   {
      u16LocalExtspdVehSecu = (uint16)MATHSRV_udtMIN(SftyMgt_spdVeh_inh_C,
                                                     64000);
   }
   else
   {
      /*Calcul MIN FILTER */
      u16LocalSftyMgtspdVehMinVa1 =
         (uint16)MATHSRV_udtMIN(SPDVEHSECU_U16OutputFilter1,
                                SPDVEHSECU_U16OutputFilter2);
      u16LocalSftyMgtspdVehMinVa2 =
         (uint16)MATHSRV_udtMIN(SPDVEHSECU_U16OutputFilter3,
                                SPDVEHSECU_U16OutputFilter4);
      SftyMgt_spdVehMinVal =
         (uint16)MATHSRV_udtMIN(u16LocalSftyMgtspdVehMinVa1,
                                u16LocalSftyMgtspdVehMinVa2);

      if (SPDVEHSECU_U16OutputFilter1 == SftyMgt_spdVehMinVal)
      {
         bLocalResult263 = 1;
         u16LocalOut1 = SftyMgt_spdVehMax_inh_C;
      }
      else
      {
         bLocalResult263 = 0;
         u16LocalOut1 = SPDVEHSECU_U16OutputFilter1;
      }
      if (SPDVEHSECU_U16OutputFilter2 == SftyMgt_spdVehMinVal)
      {
         bLocalResult264 = 1;
         u16LocalOut2 = SftyMgt_spdVehMax_inh_C;
      }
      else
      {
         bLocalResult264 = 0;
         u16LocalOut2 = SPDVEHSECU_U16OutputFilter2;
      }
      if (SPDVEHSECU_U16OutputFilter3 == SftyMgt_spdVehMinVal)
      {
         bLocalResult265 = 1;
         u16LocalOut3 = SftyMgt_spdVehMax_inh_C;
      }
      else
      {
         bLocalResult265 = 0;
         u16LocalOut3 = SPDVEHSECU_U16OutputFilter3;
      }
      if (SPDVEHSECU_U16OutputFilter4 == SftyMgt_spdVehMinVal)
      {
         bLocalResult266 = 1;
         u16LocalOut4 = SftyMgt_spdVehMax_inh_C;
      }
      else
      {
         bLocalResult266 = 0;
         u16LocalOut4 = SPDVEHSECU_U16OutputFilter4;
      }
      u16LocalMinOut1 = (uint16)MATHSRV_udtMIN(u16LocalOut1, u16LocalOut2);
      u16LocalMinOut2 = (uint16)MATHSRV_udtMIN(u16LocalOut3, u16LocalOut4);
      u8LocalResult = (uint8) ( bLocalResult263
                              + bLocalResult264
                              + bLocalResult265
                              + bLocalResult266);
      if (u8LocalResult > 1)
      {
         u16LocalExtspdVehSecu = SftyMgt_spdVehMinVal;
      }
      else
      {
         u16LocalExtspdVehSecu =
            (uint16)MATHSRV_udtMIN(u16LocalMinOut1, u16LocalMinOut2);
      }
      u32LocalExtspdVehSecu = (uint32)(( 32 * u16LocalExtspdVehSecu) / 25);
      u16LocalExtspdVehSecu =
         (uint16)MATHSRV_udtMIN(u32LocalExtspdVehSecu, 64000);
   }
   VEMS_vidSET(Ext_spdVehSecu, u16LocalExtspdVehSecu);
}
/*------------------------------- end of file --------------------------------*/