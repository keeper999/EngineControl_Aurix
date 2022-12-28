/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TELECODAGE                                              */
/* !Description     : TELECODAGE component.                                   */
/*                                                                            */
/* !Module          : TELECODAGE                                              */
/* !Description     : PROCÉDURE DE TÉLÉCODAGE SÉCURISÉ                        */
/*                                                                            */
/* !File            : TELECODAGE_FCT1.C                                       */
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
/*   1 / TELECODAGE_vidInitOutput                                             */
/*   2 / TELECODAGE_vidInitDftBeforeTel                                       */
/*   3 / TELECODAGE_vidVarCodDftMng                                           */
/*   4 / TELECODAGE_vidDataVerification                                       */
/*   5 / TELECODAGE_vidFricConfVerif                                          */
/*   6 / TELECODAGE_vidPressClimConfVerif                                     */
/*   7 / TELECODAGE_vidGearBoxConfVerif                                       */
/*   8 / TELECODAGE_vidAlternConfVerif                                        */
/*   9 / TELECODAGE_vidCarConfVerif                                           */
/*   10 / TELECODAGE_vidAddHeatConfVerif                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5074365 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066577                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TELECODAGE/TELECODAGE_FCT1.C_v  $*/
/* $Revision::   1.9      $$Author::   pbakabad       $$Date::   Jul 29 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 29 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TELECODAGE.h"
#include "TELECODAGE_L.h"
#include "TELECODAGE_IM.h"
#include "CRC.h"
#include "SUPSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidInitOutput                                   */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool SRV_TELEECU_IDLE;                                              */
/*  output st57 Srv_stTeleEcuStatus;                                          */
/*  output bool SRV_TELEECU_IDLE;                                             */
/*  output uint8 TELECODAGE_u8SrvStTeleEcuStaPrev;                            */
/*  output uint32 TELECODAGE_u32Info_UC;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidInitOutput(void)
{
   VEMS_vidSET(Srv_stTeleEcuStatus, SRV_TELEECU_IDLE);
   TELECODAGE_u8SrvStTeleEcuStaPrev = 0;
   TELECODAGE_u32Info_UC = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidInitDftBeforeTel                             */
/* !Description :  A l’initialisation, on vient lire toutes les données       */
/*                 enregistrées en EEPROM. Dans le cas d’une première mise    */
/*                 sous tension (et pour toutes les autres mises sous tension */
/*                 avant le premier télécodage), on utilise les valeurs par   */
/*                 défaut.                                                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint16  SUPSRV_u16ReadAppliKey(argio uint8 *pau8Buffer, argin */
/*  uint16 u16MaxSize);                                                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 AppliKey;                                                   */
/*  output boolean Srv_bDgoInv_VarCod;                                        */
/*  output boolean Srv_bMonRunInv_VarCod;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidInitDftBeforeTel(void)
{
   uint8  u8LocalAppliKey[TELECODAGE_u8BufferSize];
   uint16 u16LocalResultSize;
   /*qac warning Msg(3:3203) due to the use of SUPSRV_u16ReadAppliKey macro*/
   uint16 u16LocalAppliKeyMsb;
   uint16 u16LocalAppliKeyLsb;
   uint16 u16LocalAppliKey;


   /* Initialisation of the buffer */
   u8LocalAppliKey[0] = 0;
   u8LocalAppliKey[1] = 0;

   u16LocalResultSize = SUPSRV_u16ReadAppliKey(&u8LocalAppliKey[0], 2);
   /*qac warning Msg(3:3199) due to the use of SUPSRV_u16ReadAppliKey macro*/
   u16LocalAppliKeyMsb = (uint16)u8LocalAppliKey[0];
   u16LocalAppliKeyLsb = (uint16)u8LocalAppliKey[1];
   u16LocalAppliKey = (uint16)((u16LocalAppliKeyMsb << 8)
                    + u16LocalAppliKeyLsb);

   VEMS_vidSET(AppliKey, u16LocalAppliKey);
   Srv_bDgoInv_VarCod = 0;
   Srv_bMonRunInv_VarCod = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidVarCodDftMng                                 */
/* !Description :  Un défaut de télécodage est enregistré tant qu’aucun       */
/*                 télécodage n’a été réalisé.                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Tele_program_nb;                                              */
/*  output boolean Srv_bDgoInv_VarCod;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidVarCodDftMng(void)
{
   uint8 u8LocalTele_program_nb;


   VEMS_vidGET(Tele_program_nb, u8LocalTele_program_nb);
   if (u8LocalTele_program_nb == 0)
   {
      Srv_bDgoInv_VarCod = 1;
   }
   else
   {
      Srv_bDgoInv_VarCod = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidDataVerification                             */
/* !Description :  Calcul de la sortie Srv_bDaVld                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_005.01                                     */
/*                 VEMS_R_11_02626_006.01                                     */
/*                 VEMS_R_11_02626_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void TELECODAGE_vidFricConfVerif();                           */
/*  extf argret void TELECODAGE_vidPressClimConfVerif();                      */
/*  extf argret void TELECODAGE_vidGearBoxConfVerif();                        */
/*  extf argret void TELECODAGE_vidAlternConfVerif();                         */
/*  extf argret void TELECODAGE_vidCarConfVerif();                            */
/*  extf argret void TELECODAGE_vidAddHeatConfVerif();                        */
/*  input uint8 Tele_program_raw_data[11];                                    */
/*  input uint32 TELECODAGE_u32Info_UC;                                       */
/*  input uint32 Tele_available_uc;                                           */
/*  input uint8 Srv_TeleIndice_C;                                             */
/*  input boolean Tele_program_fric_vld;                                      */
/*  input boolean Tele_program_press_clim_vld;                                */
/*  input boolean Tele_program_gear_box_vld;                                  */
/*  input boolean Tele_program_alternator_vld;                                */
/*  input boolean Tele_program_car_vld;                                       */
/*  input boolean Tele_program_add_heat_vld;                                  */
/*  output uint8 Tele_program_fric_int;                                       */
/*  output uint8 Tele_program_press_clim_int;                                 */
/*  output uint8 Tele_program_gear_box_int;                                   */
/*  output uint16 Tele_program_alternator_int;                                */
/*  output uint8 Tele_program_car_int;                                        */
/*  output uint8 Tele_program_add_heat_int;                                   */
/*  output uint32 TELECODAGE_u32Info_UC;                                      */
/*  output boolean Srv_bDaVld;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidDataVerification(void)
{
   uint8  u8LocalTele_program_raw_data[TELE_PROGRAM_RAW_DATA_COLS];
   uint32 u32LocalTele_available_uc;


   u8LocalTele_program_raw_data[0] = 0;/*To avoid QAC warning*/
   VEMS_vidGET1DArray(Tele_program_raw_data,
                      TELE_PROGRAM_RAW_DATA_COLS,
                      u8LocalTele_program_raw_data);

   Tele_program_fric_int = u8LocalTele_program_raw_data[1];
   TELECODAGE_vidFricConfVerif();
   Tele_program_press_clim_int = u8LocalTele_program_raw_data[2];
   TELECODAGE_vidPressClimConfVerif();
   Tele_program_gear_box_int = u8LocalTele_program_raw_data[3];
   TELECODAGE_vidGearBoxConfVerif();
   Tele_program_alternator_int =
      (uint16)( u8LocalTele_program_raw_data[4]
              + (u8LocalTele_program_raw_data[5] * 256));
   TELECODAGE_vidAlternConfVerif();
   Tele_program_car_int = u8LocalTele_program_raw_data[6];
   TELECODAGE_vidCarConfVerif();
   Tele_program_add_heat_int = u8LocalTele_program_raw_data[7];
   TELECODAGE_vidAddHeatConfVerif();

   TELECODAGE_u32Info_UC =(uint32)( u8LocalTele_program_raw_data[8]
                                  + (u8LocalTele_program_raw_data[9] * 256)
                                  + (u8LocalTele_program_raw_data[10] * 65536));

   u32LocalTele_available_uc = ( TELECODAGE_u32Info_UC | Tele_available_uc);

   if (  (Srv_TeleIndice_C == u8LocalTele_program_raw_data[0])
      && (Tele_program_fric_vld != 0)
      && (Tele_program_press_clim_vld != 0)
      && (Tele_program_gear_box_vld != 0)
      && (Tele_program_alternator_vld != 0)
      && (Tele_program_car_vld != 0)
      && (Tele_program_add_heat_vld != 0)
      && (u32LocalTele_available_uc == TELECODAGE_u32Info_UC))
   {
      Srv_bDaVld = 1;
   }
   else
   {
      Srv_bDaVld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidFricConfVerif                                */
/* !Description :  Le calculateur effectue la vérification de l'équations     */
/*                 logique suivante : configuration possible OU configuration */
/*                 programmée = configuration programmée, pour la variante    */
/*                 Fric                                                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tele_program_fric_int;                                        */
/*  input uint8 Tele_available_fric;                                          */
/*  output boolean Tele_program_fric_vld;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidFricConfVerif(void)
{
   uint8   u8LocalAvailableFric;


   u8LocalAvailableFric = (uint8)(Tele_program_fric_int | Tele_available_fric);
   if (  (  (Tele_program_fric_int == 255)
         || (Tele_program_fric_int == 254)
         || (Tele_program_fric_int == 253)
         || (Tele_program_fric_int == 251)
         || (Tele_program_fric_int == 247)
         || (Tele_program_fric_int == 239)
         || (Tele_program_fric_int == 223)
         || (Tele_program_fric_int == 191)
         || (Tele_program_fric_int == 127))
      && (Tele_program_fric_int == u8LocalAvailableFric))
   {
      Tele_program_fric_vld = 1;
   }
   else
   {
      Tele_program_fric_vld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidPressClimConfVerif                           */
/* !Description :  Le calculateur effectue la vérification de l'équations     */
/*                 logique suivante : configuration possible OU configuration */
/*                 programmée = configuration programmée, pour la variante    */
/*                 Pression Clim                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tele_program_press_clim_int;                                  */
/*  input uint8 Tele_available_press_clim;                                    */
/*  output boolean Tele_program_press_clim_vld;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidPressClimConfVerif(void)
{
   uint8   u8LocalAvailableClim;


   u8LocalAvailableClim = (uint8)( Tele_program_press_clim_int
                                 | Tele_available_press_clim);
   if (  (  (Tele_program_press_clim_int == 255)
         || (Tele_program_press_clim_int == 254)
         || (Tele_program_press_clim_int == 253)
         || (Tele_program_press_clim_int == 251)
         || (Tele_program_press_clim_int == 247)
         || (Tele_program_press_clim_int == 239)
         || (Tele_program_press_clim_int == 223)
         || (Tele_program_press_clim_int == 191)
         || (Tele_program_press_clim_int == 127))
      && (Tele_program_press_clim_int == u8LocalAvailableClim))
   {
      Tele_program_press_clim_vld = 1;
   }
   else
   {
      Tele_program_press_clim_vld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidGearBoxConfVerif                             */
/* !Description :  Le calculateur effectue la vérification de l'équations     */
/*                 logique suivante : configuration possible OU configuration */
/*                 programmée = configuration programmée, pour la variante    */
/*                 Boite de vitesse                                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tele_program_gear_box_int;                                    */
/*  input uint8 Tele_available_gear_box;                                      */
/*  output boolean Tele_program_gear_box_vld;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidGearBoxConfVerif(void)
{
   uint8   u8LocalAvailableGear;


   u8LocalAvailableGear = (uint8)( Tele_program_gear_box_int
                                 | Tele_available_gear_box);
   if (  (  (Tele_program_gear_box_int == 255)
         || (Tele_program_gear_box_int == 254)
         || (Tele_program_gear_box_int == 253)
         || (Tele_program_gear_box_int == 251)
         || (Tele_program_gear_box_int == 247)
         || (Tele_program_gear_box_int == 239)
         || (Tele_program_gear_box_int == 223)
         || (Tele_program_gear_box_int == 191)
         || (Tele_program_gear_box_int == 127))
      && (Tele_program_gear_box_int == u8LocalAvailableGear))
   {
      Tele_program_gear_box_vld = 1;
   }
   else
   {
      Tele_program_gear_box_vld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidAlternConfVerif                              */
/* !Description :  Le calculateur effectue la vérification de l'équations     */
/*                 logique suivante : configuration possible OU configuration */
/*                 programmée = configuration programmée, pour la variante    */
/*                 Classe Alternateur                                         */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tele_program_alternator_int;                                 */
/*  input uint16 Tele_available_alternator;                                   */
/*  output boolean Tele_program_alternator_vld;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidAlternConfVerif(void)
{
   uint16   u16LocalAvailableAlternator;


   u16LocalAvailableAlternator = (uint16)( Tele_program_alternator_int
                                       | Tele_available_alternator);
   if (  (  (Tele_program_alternator_int == 65535)
         || (Tele_program_alternator_int == 65534)
         || (Tele_program_alternator_int == 65533)
         || (Tele_program_alternator_int == 65531)
         || (Tele_program_alternator_int == 65527)
         || (Tele_program_alternator_int == 65519)
         || (Tele_program_alternator_int == 65503)
         || (Tele_program_alternator_int == 65471)
         || (Tele_program_alternator_int == 65407)
         || (Tele_program_alternator_int == 65279)
         || (Tele_program_alternator_int == 65023)
         || (Tele_program_alternator_int == 64511)
         || (Tele_program_alternator_int == 63487)
         || (Tele_program_alternator_int == 61439)
         || (Tele_program_alternator_int == 57343)
         || (Tele_program_alternator_int == 49151)
         || (Tele_program_alternator_int == 32767))
      && (Tele_program_alternator_int == u16LocalAvailableAlternator))
   {
      Tele_program_alternator_vld = 1;
   }
   else
   {
      Tele_program_alternator_vld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidCarConfVerif                                 */
/* !Description :  Le calculateur effectue la vérification de l'équations     */
/*                 logique suivante : configuration possible OU configuration */
/*                 programmée = configuration programmée, pour la variante    */
/*                 Carosserie                                                 */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tele_program_car_int;                                         */
/*  input uint8 Tele_available_car;                                           */
/*  output boolean Tele_program_car_vld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidCarConfVerif(void)
{
   uint8   u8LocalAvailableCar;


   u8LocalAvailableCar = (uint8)(Tele_program_car_int | Tele_available_car);
   if (  (  (Tele_program_car_int == 255)
         || (Tele_program_car_int == 254)
         || (Tele_program_car_int == 253)
         || (Tele_program_car_int == 251)
         || (Tele_program_car_int == 247)
         || (Tele_program_car_int == 239)
         || (Tele_program_car_int == 223)
         || (Tele_program_car_int == 191)
         || (Tele_program_car_int == 127))
      && (Tele_program_car_int == u8LocalAvailableCar))
   {
      Tele_program_car_vld = 1;
   }
   else
   {
      Tele_program_car_vld = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidAddHeatConfVerif                             */
/* !Description :  Le calculateur effectue la vérification de l'équations     */
/*                 logique suivante : configuration possible OU configuration */
/*                 programmée = configuration programmée, pour la variante    */
/*                 Chauffage Additionnel                                      */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tele_program_add_heat_int;                                    */
/*  input uint8 Tele_available_add_heat;                                      */
/*  output boolean Tele_program_add_heat_vld;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidAddHeatConfVerif(void)
{
   uint8   u8LocalAvailableAddHeat;


   u8LocalAvailableAddHeat = (uint8)( Tele_program_add_heat_int
                                    | Tele_available_add_heat);
   if (  (  (Tele_program_add_heat_int == 255)
         || (Tele_program_add_heat_int == 254)
         || (Tele_program_add_heat_int == 253)
         || (Tele_program_add_heat_int == 251)
         || (Tele_program_add_heat_int == 247)
         || (Tele_program_add_heat_int == 239)
         || (Tele_program_add_heat_int == 223)
         || (Tele_program_add_heat_int == 191)
         || (Tele_program_add_heat_int == 127))
      && (Tele_program_add_heat_int == u8LocalAvailableAddHeat))
   {
      Tele_program_add_heat_vld = 1;
   }
   else
   {
      Tele_program_add_heat_vld = 0;
   }
}

/*------------------------------- end of file --------------------------------*/