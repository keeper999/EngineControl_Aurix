/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : GDGAR Component                                         */
/*                                                                            */
/* !Module          : GDGAR                                                   */
/* !Description     : GESTIONNAIRE DE DEFAUT                                  */
/*                                                                            */
/* !File            : GDGAR_API2.c                                            */
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
/*   1 / GDGAR_EepromRamCpyUnpack                                             */
/*   2 / GDGAR_EepromRamCpyPack                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5012623 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#048854                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "GDGAR.h"
#include "GDGAR_L.h"
#include "GDGAR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EepromRamCpyUnpack                                   */
/* !Description :  Extraction et récupération des fautes stockées en EEPROM   */
/* !Number      :  API2.1                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrSaveDftEep GD_strSaveDftEep[400];                            */
/*  input uint8 Rdy_au8Rdy_EEPROM;                                            */
/*  input uint8 DC_au8DC_EEPROM[51];                                          */
/*  output GD_tstrDftEep GD_astrDftEep[400];                                  */
/*  output GDFRM_tenuGOBDState GOBD_enustDgo[400];                            */
/*  output uint8 GOBD_u8ctWUC[400];                                           */
/*  output uint8 GD_au8RnkFrf[400];                                           */
/*  output uint8 GOBD_u8ctDC[400];                                            */
/*  output uint8 Rdy_au8ctDC[400];                                            */
/*  output uint8 Rdy_au8Rdy_EEPROM;                                           */
/*  output uint8 DC_au8DC_EEPROM[51];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : GDGAR_EepromRamCpyUnpack                                       */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EepromRamCpyUnpack(void)
{
   sint32  GDGAR_s32nbfault;
   uint8   GDGAR_u8bitfieldtemp;
   uint8   GDGAR_u8tabpos;
   uint8   GDGAR_u8bitnum;

   for(GDGAR_s32nbfault = 0 ; GDGAR_s32nbfault < GD_DFT_NB ; GDGAR_s32nbfault++)
   {
      GD_astrDftEep[GDGAR_s32nbfault].enuStDgo =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8GduEnuStDgo;

      GD_astrDftEep[GDGAR_s32nbfault].u8ctErrorClr =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8CptErrorClr;

      GOBD_enustDgo[GDGAR_s32nbfault] =
           GD_strSaveDftEep[GDGAR_s32nbfault].u8GobdEnuStDgo;

      GOBD_u8ctWUC[GDGAR_s32nbfault] =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8CtWuc;

      GD_au8RnkFrf[GDGAR_s32nbfault] =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8RnkFrf;

      GOBD_u8ctDC[GDGAR_s32nbfault] =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8GobdCtDC;

      Rdy_au8ctDC[GDGAR_s32nbfault] =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8RdyCtDC;

      GDGAR_u8bitfieldtemp =
         GD_strSaveDftEep[GDGAR_s32nbfault].u8BitField;

      GD_astrDftEep[GDGAR_s32nbfault].u8GduGobdManagement =
         (uint8)(GDGAR_u8bitfieldtemp & 0x1F);

      GDGAR_u8tabpos = (uint8)(GDGAR_s32nbfault / 8);
      GDGAR_u8bitnum = (uint8)(GDGAR_s32nbfault % 8);

      Rdy_au8Rdy_EEPROM[GDGAR_u8tabpos] =
         (uint8)(Rdy_au8Rdy_EEPROM[GDGAR_u8tabpos] |
         (((GDGAR_u8bitfieldtemp&0x20)>>5)<<GDGAR_u8bitnum));

      DC_au8DC_EEPROM[GDGAR_u8tabpos] =
         (uint8)(DC_au8DC_EEPROM[GDGAR_u8tabpos] |
         (((GDGAR_u8bitfieldtemp&0x80)>>7)<<GDGAR_u8bitnum));
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDGAR_EepromRamCpyPack                                     */
/* !Description :  Archivage des fautes loguées avant stockage en EEPROM      */
/* !Number      :  API2.2                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input GD_tstrDftEep GD_astrDftEep[400];                                   */
/*  input GDFRM_tenuGOBDState GOBD_enustDgo[400];                             */
/*  input uint8 GOBD_u8ctWUC[400];                                            */
/*  input uint8 GD_au8RnkFrf[400];                                            */
/*  input uint8 GOBD_u8ctDC[400];                                             */
/*  input uint8 Rdy_au8ctDC[400];                                             */
/*  input uint8 Rdy_au8Rdy_EEPROM;                                            */
/*  input uint8 DC_au8DC_EEPROM[51];                                          */
/*  output GD_tstrSaveDftEep GD_strSaveDftEep[400];                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : GDGAR_EepromRamCpyPack                                         */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDGAR_EepromRamCpyPack(void)
{
   sint32 GDGAR_s32nbfault;
   uint8  GDGAR_u8bitfieldtemp;
   uint8  GDGAR_u8tabpos;
   uint8  GDGAR_u8bitnum;

   for(GDGAR_s32nbfault = 0 ; GDGAR_s32nbfault < GD_DFT_NB ; GDGAR_s32nbfault++)
   {
      GD_strSaveDftEep[GDGAR_s32nbfault].u8GduEnuStDgo =
         GD_astrDftEep[GDGAR_s32nbfault].enuStDgo;

      GD_strSaveDftEep[GDGAR_s32nbfault].u8CptErrorClr =
         GD_astrDftEep[GDGAR_s32nbfault].u8ctErrorClr;

      GD_strSaveDftEep[GDGAR_s32nbfault].u8GobdEnuStDgo =
         GOBD_enustDgo[GDGAR_s32nbfault];

      GD_strSaveDftEep[GDGAR_s32nbfault].u8CtWuc =
         GOBD_u8ctWUC[GDGAR_s32nbfault];

      GD_strSaveDftEep[GDGAR_s32nbfault].u8RnkFrf =
         GD_au8RnkFrf[GDGAR_s32nbfault];

      GD_strSaveDftEep[GDGAR_s32nbfault].u8GobdCtDC =
         GOBD_u8ctDC[GDGAR_s32nbfault];

      GD_strSaveDftEep[GDGAR_s32nbfault].u8RdyCtDC =
         Rdy_au8ctDC[GDGAR_s32nbfault];

      GDGAR_u8bitfieldtemp =
         GD_astrDftEep[GDGAR_s32nbfault].u8GduGobdManagement;

      GDGAR_u8tabpos = (uint8)(GDGAR_s32nbfault / 8);
      GDGAR_u8bitnum = (uint8)(GDGAR_s32nbfault % 8);

      GDGAR_u8bitfieldtemp = (uint8)(GDGAR_u8bitfieldtemp |
      (((Rdy_au8Rdy_EEPROM[GDGAR_u8tabpos]>>GDGAR_u8bitnum)&0x01)<<5) |
       (((DC_au8DC_EEPROM[GDGAR_u8tabpos] >> GDGAR_u8bitnum)
      & 0x01) << 7));

      GD_strSaveDftEep[GDGAR_s32nbfault].u8BitField =
          GDGAR_u8bitfieldtemp;
   }
}