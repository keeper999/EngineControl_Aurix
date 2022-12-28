/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SAIMMO                                                  */
/* !Description     : SAIMMO Component                                        */
/*                                                                            */
/* !Module          : SAIMMO                                                  */
/* !Description     : Structure d'accueil pour le module IMMO                 */
/*                                                                            */
/* !File            : SAIMMO_FCT1.C                                           */
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
/*   1 / SAIMMO_vidChkWrEep                                                   */
/*   2 / SAIMMO_vidUpdateSaimmoExit                                           */
/*   3 / SAIMMO_vidSendCAN                                                    */
/*   4 / Ext_getStLockECU                                                     */
/*   5 / Ext_setStLockECU                                                     */
/*   6 / Ext_setImmoCod                                                       */
/*   7 / Ext_setImmoProg                                                      */
/*   8 / Ext_getImmoCodProg                                                   */
/*   9 / Ext_getRandomUInt32                                                  */
/*   10 / Ext_setBECUAwakeImmoNeed                                            */
/*   11 / Ext_getSpdVehImmo                                                   */
/*   12 / Ext_getBUnlockReq                                                   */
/*   13 / Ext_getBUnlockAutho                                                 */
/*   14 / Ext_getNInputImmo                                                   */
/*   15 / Ext_getBInhConf                                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5060905 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_FCT1.c_v          $*/
/* $Revision::   1.8      $$Author::   etsasson       $$Date::   06 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "RND.h"
#include "MATHSRV.H"
#include "saimmo_im.h"
#include "saimmo_i.h"
#include "saimmo.h"
#include "saimmo_l.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_vidChkWrEep                                         */
/* !Description :  check the EEPROM object writing and send the status to     */
/*                 IMMO.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint8  NVMSRV_u8WriteStatus(argin NVMSRV_tudtObjectList       */
/*  udtObject);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Immo_EndWr(argin uint8 Ext_stEndWrImmo);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Srv_stADCCodWr;                                               */
/*  input uint8 SAIMMO_u8CptObjCode;                                          */
/*  input uint8 SAIMMO_u8CptObjEtat;                                          */
/*  output uint8 SAIMMO_u8CptObjCode;                                         */
/*  output uint8 SAIMMO_u8CptObjEtat;                                         */
/*  output uint8 Srv_stADCCodWr;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_vidChkWrEep(void)
{
   uint8 u8LocalEtatEepromObjCode; /* Res of the EEPROM object writing status
                                      SAIMMO_CODE */
   uint8 u8LocalEtatEepromObjEtat; /* Res of the EEPROM object writing status
                                      SAIMMO_ETAT */
   uint8 u8LocalGetStatusObjCode;  /* status return by the nvmSrv layer */
   uint8 u8LocalGetStatusObjEtat;  /* status return by the nvmSrv layer */

   uint8 u8LocalSrv_stADCCodWr;    /* status of the write adc code for DCM */

   /* Get the write status of the object */
   u8LocalGetStatusObjCode = NVMSRV_u8WriteStatus(NVMSRV_udtOBJ_SAIMMO_CODE);
   u8LocalGetStatusObjEtat = NVMSRV_u8WriteStatus(NVMSRV_udtOBJ_SAIMMO_ETAT);

   VEMS_vidGET(Srv_stADCCodWr , u8LocalSrv_stADCCodWr);
   /***************************************************************************/
   /* Check for object "code" */
   if (SAIMMO_u8CptObjCode > 1)
   {
      if (u8LocalGetStatusObjCode == NVMSRV_u8OK)
      {
         u8LocalEtatEepromObjCode = SAIMMO_u8NVMSRV_OK;
         SAIMMO_u8CptObjCode = 0;
      }
      else
      {
         u8LocalEtatEepromObjCode = SAIMMO_u8NVMSRV_NOT_TESTED;
         SAIMMO_u8CptObjCode = (uint8)(SAIMMO_u8CptObjCode - 1);
      }
   }
   else
   {  /* The count is done and the value is not equal to the default one */
      if (SAIMMO_u8CptObjCode == 1)
      {
         if (u8LocalGetStatusObjCode == NVMSRV_u8DEFAULT)
         {
            u8LocalEtatEepromObjCode = SAIMMO_u8NVMSRV_DEFAULT;
         }
         else
         {
            u8LocalEtatEepromObjCode = SAIMMO_u8NVMSRV_OK;
         }
         SAIMMO_u8CptObjCode = 0; /* set to zero to stop the check */
      }
      else
      {  /* set the state to do nothing until the next EEPROM writing */
         u8LocalEtatEepromObjCode = SAIMMO_u8NVMSRV_NOT_TESTED;
      }
   }

   /* Check for object "Etat" */
   if (SAIMMO_u8CptObjEtat > 1)
   {
      if (u8LocalGetStatusObjEtat == NVMSRV_u8OK)
      {
         u8LocalEtatEepromObjEtat = SAIMMO_u8NVMSRV_OK;
         SAIMMO_u8CptObjEtat = 0;
      }
      else
      {
         u8LocalEtatEepromObjEtat = SAIMMO_u8NVMSRV_NOT_TESTED;
         SAIMMO_u8CptObjEtat = (uint8)(SAIMMO_u8CptObjEtat - 1);
      }
   }
   else
   {  /* The count is done and the value is not equal to the default one */
      if (SAIMMO_u8CptObjEtat == 1)
      {
         if (u8LocalGetStatusObjEtat == NVMSRV_u8DEFAULT)
         {
            u8LocalEtatEepromObjEtat = SAIMMO_u8NVMSRV_DEFAULT;
         }
         else
         {
            u8LocalEtatEepromObjEtat = SAIMMO_u8NVMSRV_OK;
         }
         SAIMMO_u8CptObjEtat = 0; /* set to zero to stop the check */
      }
      else
      {  /* set the state to do nothing until the next EEPROM writing */
         u8LocalEtatEepromObjEtat = SAIMMO_u8NVMSRV_NOT_TESTED;
      }
   }

   /* Inform IMMO module of the state of the current EEPROM writing */
   /* info : It could be to have only one object to write */
   if ((u8LocalEtatEepromObjCode == SAIMMO_u8NVMSRV_DEFAULT)
     ||(u8LocalEtatEepromObjEtat == SAIMMO_u8NVMSRV_DEFAULT))
   {
      Immo_EndWr (SAIMMO_u8NVMSRV_DEFAULT);
   }
   else
   {
      if ((u8LocalEtatEepromObjCode == SAIMMO_u8NVMSRV_OK)
        ||(u8LocalEtatEepromObjEtat == SAIMMO_u8NVMSRV_OK))
      {
         Immo_EndWr (SAIMMO_u8NVMSRV_OK);
      }
      else
      {  /* Manage a timeout if the command RD is out */
         if((u8LocalSrv_stADCCodWr == WRITE_ADC_IN_PROGRESS)
             &&(SAIMMO_u8CptObjEtat == 0)
             &&(SAIMMO_u8CptObjCode == 0))
         {
            VEMS_vidSET(Srv_stADCCodWr , WRITE_ADC_TIMEOUT);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_vidUpdateSaimmoExit                                 */
/* !Description :  Update the SAIMMO exit data with the value get from IMMO.  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Immo_GetConf(argout uint8 *Immo_stProgImmoConf, argout   */
/*  boolean *Immo_bLockECUConf, argout uint8 *Immo_stCANOptConf);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  output uint8 IMMO_stEcuPairOffStTyp;                                      */
/*  output uint8 IMMO_stECUConf;                                              */
/*  output uint16 IMMO_stEcuLockStTyp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_vidUpdateSaimmoExit(void)
{
   boolean  bLocalImmo_bLockECUConf;      /* Lock state                       */
   uint8    u8LocalImmo_stProgImmoConf;   /* ECU program state                */
   uint8    u8LocalImmo_stCANOptConf;     /* Pairing and CAN option           */

   /* Get state from the module IMMO */
   Immo_GetConf(&u8LocalImmo_stProgImmoConf,
               &bLocalImmo_bLockECUConf,
               &u8LocalImmo_stCANOptConf);
   /* Update the IMMO_stEcuPairOffStTyp */
   /* QAC Deviation : problem of indentation. This warning is to ignore
      because we respect the VEES presenting rule (PON EEM INS 06 0004).
      */
   switch (u8LocalImmo_stProgImmoConf)
   {
      case SAIMMO_GETCONF_PROG_ETUDE:
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_DEVELOPMENT);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_DEVELOPMENT);
         break;

      case SAIMMO_GETCONF_UC_APPAIRE_4:
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_PAIRED);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_PAIRED);
         break;

      case SAIMMO_GETCONF_PROG_LIVRAISON:
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_VIRGIN);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_LIVRAISON);
         break;

      case SAIMMO_GETCONF_PROG_1:
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_VIRGIN);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_PROG_1);
         break;

      case SAIMMO_GETCONF_PROG_2:
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_VIRGIN);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_PROG_2);
         break;

      case SAIMMO_GETCONF_PROG_3:
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_VIRGIN);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_PROG_3);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VEMS_vidSET(IMMO_stEcuPairOffStTyp, IMMO_ECU_VIRGIN);
         VEMS_vidSET(IMMO_stECUConf, IMMO_ECU_VIRGIN);
         break;
   }

   /* update the state IMMO_stEcuLockStTyp to inform the other module */
   if (bLocalImmo_bLockECUConf == 0x00)
   {
      VEMS_vidSET(IMMO_stEcuLockStTyp, IMMO_ECU_UNLOCKED);
   }
   else
   {
      VEMS_vidSET(IMMO_stEcuLockStTyp, IMMO_ECU_LOCKED);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SAIMMO_vidSendCAN                                          */
/* !Description :  Management of the periodic emission of CAN frames.         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Can_EveSaimmo_TxFrame072();                              */
/*  extf argret void Can_EveSaimmo_TxFrame0E8();                              */
/*  input uint8 SAIMMO_u8TypeContinuFrame;                                    */
/*  input Struct_ObjCode_NVM SAIMMO_ObjCode;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SAIMMO_vidSendCAN(void)
{
   /* check if need to send a frame */
   if (SAIMMO_u8TypeContinuFrame == SAIMMO_CAN_FRAME_SEND)
   {  /* check the type of frame to send and call the right function. The buffer
         is already complete.
         */
      if ((SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_PSA_AUTO)
        ||(SAIMMO_ObjCode.AdcTyp == SAIMMO_ADC_CAN_PSA_MANUEL))
      {
         Can_EveSaimmo_TxFrame072();
      }
      else
      {
         Can_EveSaimmo_TxFrame0E8();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getStLockECU                                           */
/* !Description :  Function which allow module to get the value of the ECUlock*/
/*                 state store in the SAIMMO. If the state is not "LOCK" or   */
/*                 "UNLOCK", we return the "INVALID" state.                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SAIMMO_EcuLock1;                                             */
/*  input uint16 SAIMMO_EcuLock2;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getStLockECU
(
   uint8* Ext_stLockECU
)
{
   if ( (SAIMMO_EcuLock1 == SAIMMO_STECU_UNLOCKED)
     && (SAIMMO_EcuLock2 == SAIMMO_STECU_UNLOCKED))
   {
      *Ext_stLockECU = SAIMMO_STLOCKECU_UNLOCK;           /* ECU UNLOCK STATE */
   }
   else
   {
      if ( (SAIMMO_EcuLock1 == SAIMMO_STECU_LOCKED)
        && (SAIMMO_EcuLock2 == SAIMMO_STECU_LOCKED))
      {
         *Ext_stLockECU = SAIMMO_STLOCKECU_LOCK;          /* ECU LOCK  STATE  */
      }
      else
      {
         *Ext_stLockECU = SAIMMO_STLOCKECU_NOK;          /* ECU INVALID STATE */
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setStLockECU                                           */
/* !Description :  function used by the IMMO module to set the ECU lock state */
/*                 memorized in SAIMMO. The state is duplicate on 2 data.     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 SAIMMO_EcuLock1;                                            */
/*  output uint16 SAIMMO_EcuLock2;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setStLockECU
(
   uint8 Immo_stLockECU
)
{
   switch (Immo_stLockECU)
   {
      case SAIMMO_STLOCKECU_UNLOCK:
         SAIMMO_EcuLock1 = SAIMMO_STECU_UNLOCKED;
         SAIMMO_EcuLock2 = SAIMMO_STECU_UNLOCKED;
         break;

      case SAIMMO_STLOCKECU_LOCK:
         SAIMMO_EcuLock1 = SAIMMO_STECU_LOCKED;
         SAIMMO_EcuLock2 = SAIMMO_STECU_LOCKED;
         break;

      default:
         SAIMMO_EcuLock1 = SAIMMO_STECU_INVALED;
         SAIMMO_EcuLock2 = SAIMMO_STECU_INVALED;
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setImmoCod                                             */
/* !Description :  Function called by module IMMO to write in SA the ADC type */
/*                 and code. The data are stored in EEPROM and the SA should  */
/*                 return the writing status in EEPROM to IMMO with a         */
/*                 perioical function.                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/*  argin boolean bMode);                                                     */
/*  input uint8 SAIMMO_CptObjEEPROM_Code;                                     */
/*  output Struct_ObjCode_NVM SAIMMO_ObjCode;                                 */
/*  output uint8 SAIMMO_u8CptObjCode;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setImmoCod
(
   uint32 Immo_noImmoCodWr,
   uint8 Immo_stCANMatchOptWr
)
{
   SAIMMO_ObjCode.AdcCode = Immo_noImmoCodWr;
   SAIMMO_ObjCode.AdcTyp = Immo_stCANMatchOptWr;

   /* EEPROM update (à la volé) */
   NVMSRV_vidWrite(NVMSRV_udtOBJ_SAIMMO_CODE, NVMSRV_bSAVE_NOW);
   SAIMMO_u8CptObjCode = SAIMMO_CptObjEEPROM_Code;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setImmoProg                                            */
/* !Description :  Function called by IMMO to update the Programmation state  */
/*                 stored in SA (in no volatil memory).                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/*  argin boolean bMode);                                                     */
/*  input uint8 SAIMMO_CptObjEEPROM_Etat;                                     */
/*  output Struct_ObjEtat_NVM SAIMMO_ObjEtat;                                 */
/*  output uint8 SAIMMO_u8CptObjEtat;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setImmoProg
(
   uint16 Immo_stProgImmoWr
)
{
   SAIMMO_ObjEtat.EcuPairOffSt = Immo_stProgImmoWr;

   /* EEPROM update (à la volé) */
   NVMSRV_vidWrite(NVMSRV_udtOBJ_SAIMMO_ETAT, NVMSRV_bSAVE_NOW);
   SAIMMO_u8CptObjEtat = SAIMMO_CptObjEEPROM_Etat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getImmoCodProg                                         */
/* !Description :  Function called by IMMO to get state of data stored in SA  */
/*                 module.                                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_024.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/*  udtObject);                                                               */
/*  input Struct_ObjCode_NVM SAIMMO_ObjCode;                                  */
/*  input Struct_ObjEtat_NVM SAIMMO_ObjEtat;                                  */
/*  input boolean NvmDiag_bFirstInitDone;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getImmoCodProg
(
   uint32* Ext_noImmoCod,
   uint8* Ext_stCANMatchOpt,
   uint16* Ext_stProgImmo,
   uint8* Ext_stReadImmo
)
{
   uint8    u8LocalGetStatusObjCode;  /* status return by the nvmSrv layer */
   uint8    u8LocalGetStatusObjEtat;  /* status return by the nvmSrv layer */

   *Ext_noImmoCod = SAIMMO_ObjCode.AdcCode;
   *Ext_stCANMatchOpt = SAIMMO_ObjCode.AdcTyp;
   *Ext_stProgImmo = SAIMMO_ObjEtat.EcuPairOffSt;

   if (NvmDiag_bFirstInitDone == FALSE)
   {
      *Ext_stReadImmo = 0x00;    /* no problem */
   }
   else
   {
      /* Get the status to know if the data could be read */
      u8LocalGetStatusObjCode = NVMSRV_u8GetStatus(NVMSRV_udtOBJ_SAIMMO_CODE);
      u8LocalGetStatusObjEtat = NVMSRV_u8GetStatus(NVMSRV_udtOBJ_SAIMMO_ETAT);

      /* return the state depending on the status read */
      if((u8LocalGetStatusObjEtat != NVMSRV_u8OK)
       &&(u8LocalGetStatusObjCode != NVMSRV_u8OK))
      {
         *Ext_stReadImmo = 0x03;  /* the third parameter's read is NOK        */
      }
      else
      {
         if(u8LocalGetStatusObjEtat != NVMSRV_u8OK)
         {
            *Ext_stReadImmo = 0x02;  /* Programmation parameter's read is NOK */
         }
         else
         {
            if(u8LocalGetStatusObjCode != NVMSRV_u8OK)
            {
               *Ext_stReadImmo = 0x01;    /* CODE & option ADC read is NOK    */
            }
            else
            {
               *Ext_stReadImmo = 0x00;    /* no problem */
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getRandomUInt32                                        */
/* !Description :  Get a random data on 4 bytes.                              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RND_vidReadRandomNumber(argin uint32                     */
/*  *Ext_noUInt32Random);                                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getRandomUInt32
(
   uint32* Ext_noUInt32Random
)
{
    RND_vidReadRandomNumber(Ext_noUInt32Random);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_setBECUAwakeImmoNeed                                   */
/* !Description :  Function called by IMMO to alert the S.A. of the new power */
/*                 latch need for the ADC function.                           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Immo_bEcuAwakeImmoNeed;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_setBECUAwakeImmoNeed
(
   boolean bEcuAwakeImmoNeed
)
{
   VEMS_vidSET(Immo_bEcuAwakeImmoNeed, bEcuAwakeImmoNeed);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getSpdVehImmo                                          */
/* !Description :  Vehicle speed acquisition function                         */
/* !Number      :  FCT1.11                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getSpdVehImmo
(
   uint8* Immo_spdVeh
)
{
   uint16 u16LocalVeh_spdVeh;
   uint16 u16LocalTemp;

   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   u16LocalTemp = (uint16)((u16LocalVeh_spdVeh + 64) / 128);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 100);

   *Immo_spdVeh = (uint8)u16LocalTemp;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getBUnlockReq                                          */
/* !Description :  Immobiliser life situation acquisition function            */
/* !Number      :  FCT1.12                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bUnlockReq;                                             */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getBUnlockReq
(
   boolean* Immo_bUnlockReq,
   boolean* Immo_bMainECUWakeUp
)
{
   boolean bLocalExt_bUnlockReq;
   boolean bLocalECU_bWkuMain;

   VEMS_vidGET(Ext_bUnlockReq, bLocalExt_bUnlockReq);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   *Immo_bUnlockReq = bLocalExt_bUnlockReq;
   *Immo_bMainECUWakeUp = bLocalECU_bWkuMain;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getBUnlockAutho                                        */
/* !Description :  Function of inhibition of the unlock procedure and the     */
/*                 automatic pairring                                         */
/* !Number      :  FCT1.13                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 TqSys_stTypPwtCf;                                             */
/*  input boolean SAIMMO_bUnlockAutho;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getBUnlockAutho
(
   boolean* Immo_bUnlockAutho
)
{
   uint8 u8LocalTqSys_stTypPwtCf;

   VEMS_vidGET(TqSys_stTypPwtCf, u8LocalTqSys_stTypPwtCf);

   /* moteur thermique */
   if (u8LocalTqSys_stTypPwtCf == 0)
   {
      *Immo_bUnlockAutho = 1;
   }
   else
   {
      *Immo_bUnlockAutho = SAIMMO_bUnlockAutho;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getNInputImmo                                          */
/* !Description :  Engine speed acquisition function.                         */
/* !Number      :  FCT1.14                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getNInputImmo
(
   uint16* Immo_nInput
)
{
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTemp;

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 5000);

   *Immo_nInput = u16LocalTemp;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_getBInhConf                                            */
/* !Description :  Function of inhibition of the procedure of confirmation.   */
/* !Number      :  FCT1.15                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTStNew_stEng;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_getBInhConf
(
   boolean* Immo_bInhConf
)
{
   uint8    u8LocalCoPTStNew_stEng;

   VEMS_vidGET(CoPTStNew_stEng, u8LocalCoPTStNew_stEng);

   /* Fonction « Stop & Start » absente */
   /* OU Pas de demande d’arrêt du moteur thermique via le « Stop & Start » */
   if (u8LocalCoPTStNew_stEng != 6)
   {
      *Immo_bInhConf = 0x00;
   }
   /* Demande d’arrêt du moteur thermique via le « Stop & Start » */
   else
   {
      *Immo_bInhConf = 0x01;
   }
}

/*-------------------------------- end of file -------------------------------*/