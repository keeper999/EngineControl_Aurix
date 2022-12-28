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
/* !File            : TELECODAGE_FCT2.C                                       */
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
/*   1 / TELECODAGE_NVMSRV_vidInit                                            */
/*   2 / TELECODAGE_vidVarCodMng                                              */
/*   3 / TELECODAGE_vidInfoWrite                                              */
/*   4 / TELECODAGE_vidWrite                                                  */
/*   5 / TELECODAGE_vidReInit                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5074365 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066577                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TELECODAGE/TELECODAGE_FCT2.C_v  $*/
/* $Revision::   1.10     $$Author::   pbakabad       $$Date::   Jul 29 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 29 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TELECODAGE.h"
#include "TELECODAGE_L.h"
#include "TELECODAGE_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_NVMSRV_vidInit                                  */
/* !Description :  A l’initialisation, on vient lire toutes les données       */
/*                 enregistrées en EEPROM. Dans le cas d’une première mise    */
/*                 sous tension (et pour toutes les autres mises sous tension */
/*                 avant le premier télécodage), on utilise les valeurs par   */
/*                 défaut.                                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Tele_program_uc_init_C;                                      */
/*  input uint16 Tele_program_alternator_init_C;                              */
/*  input uint8 Tele_program_fric_init_C;                                     */
/*  input uint8 Tele_program_gear_box_init_C;                                 */
/*  input uint8 Tele_program_press_clim_init_C;                               */
/*  input uint8 Tele_program_car_init_C;                                      */
/*  input uint8 Tele_program_add_heat_init_C;                                 */
/*  output uint16 Tele_program_alternator;                                    */
/*  output uint16 Tele_program_alternator_init_C;                             */
/*  output uint8 Tele_program_fric;                                           */
/*  output uint8 Tele_program_fric_init_C;                                    */
/*  output uint8 Tele_program_gear_box;                                       */
/*  output uint8 Tele_program_gear_box_init_C;                                */
/*  output uint32 Tele_program_uc;                                            */
/*  output uint8 Tele_program_press_clim;                                     */
/*  output uint8 Tele_program_press_clim_init_C;                              */
/*  output uint8 Tele_program_car;                                            */
/*  output uint8 Tele_program_car_init_C;                                     */
/*  output uint8 Tele_program_add_heat;                                       */
/*  output uint8 Tele_program_add_heat_init_C;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_NVMSRV_vidInit(void)
{
   uint32 u32LocalTele_program_uc;

   u32LocalTele_program_uc = MATHSRV_udtMIN(Tele_program_uc_init_C,
                                                    16777215);
   VEMS_vidSET(Tele_program_alternator, Tele_program_alternator_init_C);
   VEMS_vidSET(Tele_program_fric, Tele_program_fric_init_C);
   VEMS_vidSET(Tele_program_gear_box, Tele_program_gear_box_init_C);
   VEMS_vidSET(Tele_program_uc, u32LocalTele_program_uc);
   VEMS_vidSET(Tele_program_press_clim, Tele_program_press_clim_init_C);
   VEMS_vidSET(Tele_program_car, Tele_program_car_init_C);
   VEMS_vidSET(Tele_program_add_heat, Tele_program_add_heat_init_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidVarCodMng                                    */
/* !Description :  A  l’initialisation,  l’état SRV_TELEECU_IDLE est activé en*/
/*                 attendant de déterminer s’il est nécessaire d’utiliser les */
/*                 processus  de  protection  en  écriture  (si  au  moins  un*/
/*                 télécodage  a  déjà  été  réalisé)  ou  non.               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_008.01                                     */
/*                 VEMS_R_11_02626_009.01                                     */
/*                 VEMS_R_11_02626_010.01                                     */
/*                 VEMS_R_11_02626_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st58 Srv_stTeleAccessStatus;                                        */
/*  input st57 Srv_stTeleEcuStatus;                                           */
/*  input uint8 Tele_program_nb;                                              */
/*  input boolean Srv_bTeleWrChck;                                            */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Afts_bAcvModAfts;                                           */
/*  input boolean Srv_bAntiScanning;                                          */
/*  input bool SRV_TELEECU_ANTISCANNING;                                      */
/*  input uint16 Srv_tiDelayTele_C;                                           */
/*  input bool SRV_TELEECU_WAIT;                                              */
/*  input bool SRV_TELEECU_NEEDACCESS;                                        */
/*  input bool SRV_TELEECU_IDLE;                                              */
/*  input bool SRV_TELEACCESS_REQ_OK;                                         */
/*  input bool SRV_TELEECU_SEED;                                              */
/*  input bool SRV_TELEACCESS_TELE_ENABLE;                                    */
/*  input bool SRV_TELEACCESS_REQ_NOK;                                        */
/*  input uint16 Srv_tiWaitDelayTele;                                         */
/*  input bool SRV_TELEACCESS_PRGM;                                           */
/*  input boolean Srv_bDaVld;                                                 */
/*  input bool SRV_TELEECU_DATANOK;                                           */
/*  input bool SRV_TELEECU_WRITE;                                             */
/*  output uint8 TELECODAGE_u8SrvStTeleEcuStaPrev;                            */
/*  output uint16 Srv_tiWaitDelayTele;                                        */
/*  output boolean Srv_bAntiScanning;                                         */
/*  output st57 Srv_stTeleEcuStatus;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidVarCodMng(void)
{
   boolean bLocalSrv_bTeleWrChck;
   boolean bLocalECU_bWkuMain;
   boolean bLocalAfts_bAcvModAfts;
   uint8   u8LocalSrv_stTeleEcuStatus;
   uint8   u8LocalSrv_stTeleAccessStatus;
   uint8   u8LocalTele_program_nb;
   uint16  u16LocalSrv_tiWaitDelayTele;


   VEMS_vidGET(Srv_stTeleAccessStatus, u8LocalSrv_stTeleAccessStatus);
   VEMS_vidGET(Srv_stTeleEcuStatus, u8LocalSrv_stTeleEcuStatus);
   VEMS_vidGET(Tele_program_nb, u8LocalTele_program_nb);
   VEMS_vidGET(Srv_bTeleWrChck, bLocalSrv_bTeleWrChck);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Afts_bAcvModAfts, bLocalAfts_bAcvModAfts);
   TELECODAGE_u8SrvStTeleEcuStaPrev = u8LocalSrv_stTeleEcuStatus;
   switch(u8LocalSrv_stTeleEcuStatus)
   {
      case SRV_TELEECU_IDLE:
         if (Srv_bAntiScanning != 0)
         {
         /*qac warning Msg(2:2215) due to the use of case*/
            u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_ANTISCANNING;
            NVMSRV_vidWrite(NVMSRV_u16OBJ_TELE_BANTISCANNING, NVMSRV_bSAVE_NOW);
            Srv_tiWaitDelayTele = (uint16)MATHSRV_udtMIN(Srv_tiDelayTele_C,
                                                         30000);
         }
         else
         {
            if (u8LocalTele_program_nb == 0)
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_WAIT ;
            }
            else
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_NEEDACCESS;
            }
         }
         break;
      case SRV_TELEECU_NEEDACCESS:
         if (u8LocalSrv_stTeleAccessStatus == SRV_TELEACCESS_REQ_OK)
         {
            u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_SEED;
         }
         else
         {
            if (u8LocalSrv_stTeleAccessStatus == SRV_TELEACCESS_TELE_ENABLE)
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_WAIT;
            }
         }
         break;
      case SRV_TELEECU_SEED:

         if (  (  (Srv_bAntiScanning != 0)
               && (u8LocalSrv_stTeleAccessStatus != SRV_TELEACCESS_TELE_ENABLE))
            || (u8LocalSrv_stTeleAccessStatus == SRV_TELEACCESS_REQ_NOK))
         {
            Srv_bAntiScanning = 1;
            /*Write to EEPROM Srv_bAntiScanning*/
            NVMSRV_vidWrite(NVMSRV_u16OBJ_TELE_BANTISCANNING, NVMSRV_bSAVE_NOW);
            u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_ANTISCANNING;
            Srv_tiWaitDelayTele = (uint16)MATHSRV_udtMIN(Srv_tiDelayTele_C,
                                                         30000);
         }
         else
         {
            if (u8LocalSrv_stTeleAccessStatus == SRV_TELEACCESS_TELE_ENABLE)
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_WAIT;
            }
         }
         break;
      case SRV_TELEECU_ANTISCANNING:

         if(Srv_tiWaitDelayTele == 0)
         {
            Srv_bAntiScanning = 0;
            u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_IDLE;
         }
         else
         {
            u16LocalSrv_tiWaitDelayTele = (uint16)(Srv_tiWaitDelayTele - 1);
            Srv_tiWaitDelayTele =
               (uint16)MATHSRV_udtMIN(u16LocalSrv_tiWaitDelayTele, 30000);
         }
         break;
      case SRV_TELEECU_WAIT:
         if (u8LocalSrv_stTeleAccessStatus == SRV_TELEACCESS_PRGM)
         {
            if(Srv_bDaVld == 0)
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_DATANOK;
            }
            else
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_WRITE;
            }
         }
         else
         {
            if ( (  (bLocalECU_bWkuMain == 0)
                 || (bLocalAfts_bAcvModAfts == 0))
                 || (  (  u8LocalSrv_stTeleAccessStatus
                       != SRV_TELEACCESS_TELE_ENABLE)
                    && (u8LocalTele_program_nb !=0)))
            {
               u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_IDLE;
            }
         }

         break;
      case SRV_TELEECU_DATANOK:
      case SRV_TELEECU_WRITE:
         if (bLocalSrv_bTeleWrChck != 0)
         {
            u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_IDLE;
         }
         break;
      default:
         u8LocalSrv_stTeleEcuStatus = SRV_TELEECU_IDLE;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidSET(Srv_stTeleEcuStatus, u8LocalSrv_stTeleEcuStatus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidInfoWrite                                    */
/* !Description :  A l’entrée de l’état SRV_TELEECU_WRITE, les informations   */
/*                 ayant été confirmées, elles peuvent être prises en compte. */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TELECODAGE_vidWrite();                                   */
/*  input st57 Srv_stTeleEcuStatus;                                           */
/*  input bool SRV_TELEECU_WRITE;                                             */
/*  input uint8 TELECODAGE_u8SrvStTeleEcuStaPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidInfoWrite(void)
{
   uint8 u8LocalSrv_stTeleEcuStatus;


   VEMS_vidGET(Srv_stTeleEcuStatus, u8LocalSrv_stTeleEcuStatus);
   if(  (u8LocalSrv_stTeleEcuStatus == SRV_TELEECU_WRITE)
     && (TELECODAGE_u8SrvStTeleEcuStaPrev != SRV_TELEECU_WRITE))
   {
      TELECODAGE_vidWrite();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidWrite                                        */
/* !Description :  Les informations reçues sont prises en compte dans le      */
/*                 calculateur. Le compteur du nombre de télécodage est       */
/*                 incrémenté de 1.                                           */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_013.01                                     */
/*                 VEMS_R_11_02626_014.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  input uint8 Tele_program_raw_data[11];                                    */
/*  input uint8 Tele_program_nb;                                              */
/*  output uint8 Id_telecodage_eeprom;                                        */
/*  output uint8 Tele_program_fric;                                           */
/*  output uint8 Tele_program_press_clim;                                     */
/*  output uint8 Tele_program_gear_box;                                       */
/*  output uint16 Tele_program_alternator;                                    */
/*  output uint8 Tele_program_car;                                            */
/*  output uint8 Tele_program_add_heat;                                       */
/*  output uint32 Tele_program_uc;                                            */
/*  output uint8 Tele_program_nb;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidWrite(void)
{
   uint8   u8LocalTele_program_nb;
   uint8   u8LocalTele_program;
   uint8   u8LocalTele_program_raw_data[TELE_PROGRAM_RAW_DATA_COLS];
   uint16  u16LocalTele_program_nb;
   uint16  u16LocalSum;
   uint32  u32LocalSom;

   u8LocalTele_program_raw_data[0] = 0;/*To avoid QAC warning*/
   VEMS_vidGET1DArray(Tele_program_raw_data,
                      TELE_PROGRAM_RAW_DATA_COLS,
                      u8LocalTele_program_raw_data);

   VEMS_vidGET(Tele_program_nb, u8LocalTele_program_nb);
   u16LocalSum = (uint16)( u8LocalTele_program_raw_data[4]
                         + (u8LocalTele_program_raw_data[5] * 256));

   u32LocalSom = (uint32)( u8LocalTele_program_raw_data[8]
                         + (u8LocalTele_program_raw_data[9] * 256)
                         + (u8LocalTele_program_raw_data[10] * 65536));

   VEMS_vidSET(Id_telecodage_eeprom, u8LocalTele_program_raw_data[0]);
   VEMS_vidSET(Tele_program_fric, u8LocalTele_program_raw_data[1]);
   VEMS_vidSET(Tele_program_press_clim, u8LocalTele_program_raw_data[2]);
   VEMS_vidSET(Tele_program_gear_box, u8LocalTele_program_raw_data[3]);
   VEMS_vidSET(Tele_program_alternator, u16LocalSum);
   VEMS_vidSET(Tele_program_car, u8LocalTele_program_raw_data[6]);
   VEMS_vidSET(Tele_program_add_heat, u8LocalTele_program_raw_data[7]);
   VEMS_vidSET(Tele_program_uc, u32LocalSom);

   u16LocalTele_program_nb = (uint16)(u8LocalTele_program_nb + 1);
   u8LocalTele_program = (uint8)MATHSRV_udtMIN(u16LocalTele_program_nb, 255);
   VEMS_vidSET(Tele_program_nb, u8LocalTele_program);
   /*API d’accès en écriture de la référence à la volée par le driver EEPROM*/
   NVMSRV_vidWrite(NVMSRV_u16OBJ_TELECODAGE, NVMSRV_bSAVE_NOW);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TELECODAGE_vidReInit                                       */
/* !Description :  En cas de mauvaise écriture en eeprom l’ensemble des       */
/*                 données de télécodage reprennent les valeurs par défauts,  */
/*                 le nombre de télécodage est aussi réinitalisé à zéro ce qui*/
/*                 permet de monter la panne telecodage.                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Tele_program_uc_init_C;                                      */
/*  input uint16 Tele_program_alternator_init_C;                              */
/*  input uint8 Tele_program_fric_init_C;                                     */
/*  input uint8 Tele_program_gear_box_init_C;                                 */
/*  input uint8 Tele_program_press_clim_init_C;                               */
/*  input uint8 Tele_program_car_init_C;                                      */
/*  input uint8 Tele_program_add_heat_init_C;                                 */
/*  output uint8 Tele_program_nb;                                             */
/*  output uint16 Tele_program_alternator;                                    */
/*  output uint16 Tele_program_alternator_init_C;                             */
/*  output uint8 Tele_program_fric;                                           */
/*  output uint8 Tele_program_fric_init_C;                                    */
/*  output uint8 Tele_program_gear_box;                                       */
/*  output uint8 Tele_program_gear_box_init_C;                                */
/*  output uint32 Tele_program_uc;                                            */
/*  output uint8 Id_telecodage_eeprom;                                        */
/*  output uint8 Tele_program_press_clim;                                     */
/*  output uint8 Tele_program_press_clim_init_C;                              */
/*  output uint8 Tele_program_car;                                            */
/*  output uint8 Tele_program_car_init_C;                                     */
/*  output uint8 Tele_program_add_heat;                                       */
/*  output uint8 Tele_program_add_heat_init_C;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TELECODAGE_vidReInit(void)
{
   uint32 u32LocalTele_program_uc;

   u32LocalTele_program_uc = MATHSRV_udtMIN(Tele_program_uc_init_C,
                                                    16777215);
   VEMS_vidSET(Tele_program_nb, 0);
   VEMS_vidSET(Tele_program_alternator, Tele_program_alternator_init_C);
   VEMS_vidSET(Tele_program_fric, Tele_program_fric_init_C);
   VEMS_vidSET(Tele_program_gear_box, Tele_program_gear_box_init_C);
   VEMS_vidSET(Tele_program_uc, u32LocalTele_program_uc);
   VEMS_vidSET(Id_telecodage_eeprom, 2);
   VEMS_vidSET(Tele_program_press_clim, Tele_program_press_clim_init_C);
   VEMS_vidSET(Tele_program_car, Tele_program_car_init_C);
   VEMS_vidSET(Tele_program_add_heat, Tele_program_add_heat_init_C);
}
/*------------------------------- end of file --------------------------------*/