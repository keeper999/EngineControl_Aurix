/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : POSTEQUSRV                                              */
/* !Description     : POSTEQUSRV Component                                    */
/*                                                                            */
/* !Module          : POSTEQUSRV                                              */
/* !Description     : COHERENCE CAN INFOS_EOBD_BSI                            */
/*                                                                            */
/* !File            : POSTEQUSRV_FCT1.C                                       */
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
/*   1 / POSTEQUSRV_vidInitOutput                                             */
/*   2 / POSTEQUSRV_vidInitEEP                                                */
/*   3 / POSTEQUSRV_vidDataVerification                                       */
/*   4 / POSTEQUSRV_vidVarCodMng                                              */
/*   5 / POSTEQUSRV_vidInfoWrite                                              */
/*   6 / POSTEQUSRV_vidWrite                                                  */
/*   7 / POSTEQUSRV_vidReInit                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5074440 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066576                                         */
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
#include "POSTEQUSRV.h"
#include "POSTEQUSRV_L.h"
#include "POSTEQUSRV_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidInitOutput                                   */
/* !Description :  Output initialization function.                            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input bool SRV_POSTEQUECU_IDLE;                                           */
/*  output uint8 POSTEQUSRV_u8stPostEcuStatPrev;                              */
/*  output boolean Srv_bPostEquVld;                                           */
/*  output st132 Srv_stPostEquEcuStatus;                                      */
/*  output bool SRV_POSTEQUECU_IDLE;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidInitOutput(void)
{
   POSTEQUSRV_u8stPostEcuStatPrev = SRV_POSTEQUECU_IDLE;
   Srv_bPostEquVld = 0;
   VEMS_vidSET(Srv_stPostEquEcuStatus, SRV_POSTEQUECU_IDLE);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidInitEEP                                      */
/* !Description :  At init, datas are read from EEPROM                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_spdVehVSMaxPrmaReq1;                                      */
/*  output uint8 Ext_spdVehVSMaxPrmaReq2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidInitEEP(void)
{
   uint8 u8LocalspdVehVSMaxPrmaReq1;


   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq1, u8LocalspdVehVSMaxPrmaReq1);
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq2, u8LocalspdVehVSMaxPrmaReq1);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidDataVerification                             */
/* !Description :  ECU checks during the writing request of data in memory    */
/*                 that index received matches with the index in memory.      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 Srv_prmPostEquRawData[2];                                     */
/*  input uint8 Srv_PostEquIndice_C;                                          */
/*  input uint8 Srv_prmPostEquMin_C;                                          */
/*  input uint8 Srv_prmPostEquMax_C;                                          */
/*  output boolean Srv_bPostEquVld;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidDataVerification(void)
{
   uint8 u8LocalprmPostEquRawData1;
   uint8 u8LocalprmPostEquRawData2;


   VEMS_vidGET1DArrayElement(Srv_prmPostEquRawData,
                             0, u8LocalprmPostEquRawData1);
   VEMS_vidGET1DArrayElement(Srv_prmPostEquRawData,
                             1, u8LocalprmPostEquRawData2);

   if (  (u8LocalprmPostEquRawData1 == Srv_PostEquIndice_C)
      && (  (  (u8LocalprmPostEquRawData2 >= Srv_prmPostEquMin_C)
            && (u8LocalprmPostEquRawData2 <= Srv_prmPostEquMax_C))
         || (u8LocalprmPostEquRawData2 == 255)))
   {
      Srv_bPostEquVld = 1;
   }
   else
   {
      Srv_bPostEquVld = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidVarCodMng                                    */
/* !Description :  function describing the post equipment process             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st132 Srv_stPostEquEcuStatus;                                       */
/*  input boolean Srv_bAntiScanPostEqu;                                       */
/*  input bool SRV_POSTEQUECU_ANTISCANNING;                                   */
/*  input uint16 Srv_tiDelayPostEqu_C;                                        */
/*  input boolean Srv_bPostEquDone;                                           */
/*  input boolean Srv_bInhSAFstWrPosEq_C;                                     */
/*  input bool SRV_POSTEQUECU_WAIT;                                           */
/*  input bool SRV_POSTEQUECU_NEEDACCESS;                                     */
/*  input bool SRV_POSTEQUECU_IDLE;                                           */
/*  input st21 Srv_stTeleAccessStatus;                                        */
/*  input bool SRV_TELEACCESS_REQ_OK;                                         */
/*  input bool SRV_POSTEQUECU_SEED;                                           */
/*  input bool SRV_TELEACCESS_TELE_ENABLE;                                    */
/*  input uint16 Srv_tiWaitDelayPostEqu;                                      */
/*  input bool SRV_TELEACCESS_REQ_NOK;                                        */
/*  input bool SRV_TELEACCESS_PRGM_POSTEQU;                                   */
/*  input boolean Srv_bPostEquVld;                                            */
/*  input bool SRV_POSTEQUECU_DATANOK;                                        */
/*  input bool SRV_POSTEQUECU_WRITE;                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Afts_bAcvModAfts;                                           */
/*  input boolean Srv_bPostEquWrChck;                                         */
/*  output uint8 POSTEQUSRV_u8stPostEcuStatPrev;                              */
/*  output boolean Srv_bAntiScanPostEqu;                                      */
/*  output uint16 Srv_tiWaitDelayPostEqu;                                     */
/*  output st132 Srv_stPostEquEcuStatus;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidVarCodMng(void)
{
   boolean bLocalECU_bWkuMain;
   boolean bLocalAfts_bAcvModAfts;
   boolean bLocalbPostEquWrChck;
   boolean bLocalSrv_bPostEquDone;
   uint8   u8LocalstPostEquEcuStatus;
   uint8   u8LocalstTeleAccessStatus;
   uint16  u16LocalSrv_tiWaitDelayPostEqu;


   VEMS_vidGET(Srv_stPostEquEcuStatus, u8LocalstPostEquEcuStatus);
   POSTEQUSRV_u8stPostEcuStatPrev = u8LocalstPostEquEcuStatus;

   switch(u8LocalstPostEquEcuStatus)
   {
      case SRV_POSTEQUECU_IDLE:
         if (Srv_bAntiScanPostEqu != 0)
         {
            Srv_bAntiScanPostEqu = 1;
            /*API d’accès en écriture de la référence à la volée par l'EEPROM*/
            NVMSRV_vidWrite( NVMSRV_u16OBJ_POSTEQUSRV_BANTISCANNING
                           , NVMSRV_bSAVE_NOW);
            u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_ANTISCANNING;
            Srv_tiWaitDelayPostEqu =
               (uint16)MATHSRV_udtMIN(Srv_tiDelayPostEqu_C, 30000);
         }
         else
         {
            VEMS_vidGET(Srv_bPostEquDone, bLocalSrv_bPostEquDone);

            if (  (bLocalSrv_bPostEquDone == 0)
               && (Srv_bInhSAFstWrPosEq_C == 0))
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_WAIT;
            }
            else
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_NEEDACCESS;
            }
         }
         break;

      case SRV_POSTEQUECU_NEEDACCESS:
         VEMS_vidGET(Srv_stTeleAccessStatus, u8LocalstTeleAccessStatus);

         if (u8LocalstTeleAccessStatus == SRV_TELEACCESS_REQ_OK)
         {
            u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_SEED;
         }
         else
         {
            if (u8LocalstTeleAccessStatus == SRV_TELEACCESS_TELE_ENABLE)
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_WAIT;
            }
         }
         break;

      case SRV_POSTEQUECU_ANTISCANNING:
         if (Srv_tiWaitDelayPostEqu == 0)
         {
            Srv_bAntiScanPostEqu = 0;
            u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_IDLE;
         }
         else
         {
            u16LocalSrv_tiWaitDelayPostEqu =
               (uint16)(Srv_tiWaitDelayPostEqu - 1);
            Srv_tiWaitDelayPostEqu =
               (uint16)MATHSRV_udtMIN(u16LocalSrv_tiWaitDelayPostEqu, 30000);
         }
         break;

      case SRV_POSTEQUECU_SEED:
         VEMS_vidGET(Srv_stTeleAccessStatus, u8LocalstTeleAccessStatus);

         if (  (  (Srv_bAntiScanPostEqu != 0)
                  && (u8LocalstTeleAccessStatus != SRV_TELEACCESS_TELE_ENABLE))
            || (u8LocalstTeleAccessStatus == SRV_TELEACCESS_REQ_NOK))
         {
            Srv_bAntiScanPostEqu = 1;
            /*API d’accès en écriture de la référence à la volée par l'EEPROM*/
            NVMSRV_vidWrite( NVMSRV_u16OBJ_POSTEQUSRV_BANTISCANNING
                           , NVMSRV_bSAVE_NOW);
            u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_ANTISCANNING;
            Srv_tiWaitDelayPostEqu =
               (uint16)MATHSRV_udtMIN(Srv_tiDelayPostEqu_C, 30000);
         }
         else
         {
            if (u8LocalstTeleAccessStatus == SRV_TELEACCESS_TELE_ENABLE)
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_WAIT;
            }
         }
         break;

      case SRV_POSTEQUECU_WAIT:
         VEMS_vidGET(Srv_stTeleAccessStatus, u8LocalstTeleAccessStatus);

         if (u8LocalstTeleAccessStatus == SRV_TELEACCESS_PRGM_POSTEQU)
         {
            if (Srv_bPostEquVld == 0)
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_DATANOK;
            }
            else
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_WRITE;
            }
         }
         else
         {
            VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
            VEMS_vidGET(Afts_bAcvModAfts, bLocalAfts_bAcvModAfts);
            VEMS_vidGET(Srv_bPostEquDone, bLocalSrv_bPostEquDone);
            if (  (bLocalECU_bWkuMain == 0)
               || (bLocalAfts_bAcvModAfts == 0)
               || (  (u8LocalstTeleAccessStatus != SRV_TELEACCESS_TELE_ENABLE)
                  && (  (bLocalSrv_bPostEquDone != 0)
                     || (Srv_bInhSAFstWrPosEq_C != 0))))
            {
               u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_IDLE;
            }
         }
         break;

      case SRV_POSTEQUECU_DATANOK:
         VEMS_vidGET(Srv_bPostEquWrChck, bLocalbPostEquWrChck);

         if (bLocalbPostEquWrChck != 0)
         {
            u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_IDLE;
         }
         break;

      case SRV_POSTEQUECU_WRITE:
         VEMS_vidGET(Srv_bPostEquWrChck, bLocalbPostEquWrChck);

         if (bLocalbPostEquWrChck != 0)
         {
            u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_IDLE;
         }
         break;

      default:
      u8LocalstPostEquEcuStatus = SRV_POSTEQUECU_IDLE;
      SWFAIL_vidSoftwareErrorHook();
   }
   VEMS_vidSET(Srv_stPostEquEcuStatus, u8LocalstPostEquEcuStatus);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidInfoWrite                                    */
/* !Description :  If the input state is SRV_POSTEQUECU_WRITE, incoming data  */
/*                 have been confirmed and can be taken into account.         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void POSTEQUSRV_vidWrite();                                   */
/*  input st132 Srv_stPostEquEcuStatus;                                       */
/*  input bool SRV_POSTEQUECU_WRITE;                                          */
/*  input uint8 POSTEQUSRV_u8stPostEcuStatPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidInfoWrite(void)
{
   uint8   u8LocalstPostEquEcuStatus;


   VEMS_vidGET(Srv_stPostEquEcuStatus, u8LocalstPostEquEcuStatus);

   if (  (u8LocalstPostEquEcuStatus == SRV_POSTEQUECU_WRITE)
      && (POSTEQUSRV_u8stPostEcuStatPrev != SRV_POSTEQUECU_WRITE))
   {
      POSTEQUSRV_vidWrite();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidWrite                                        */
/* !Description :  this function save data in EEPROM                          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  input uint8 Srv_prmPostEquRawData[2];                                     */
/*  output uint8 Srv_PostEquIndice;                                           */
/*  output uint8 Ext_spdVehVSMaxPrmaReq1;                                     */
/*  output uint8 Ext_spdVehVSMaxPrmaReq2;                                     */
/*  output boolean Srv_bPostEquDone;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidWrite(void)
{
   uint8 u8LocalprmPostEquRawData1;
   uint8 u8LocalprmPostEquRawData2;


   VEMS_vidGET1DArrayElement(Srv_prmPostEquRawData,
                             0, u8LocalprmPostEquRawData1);
   VEMS_vidGET1DArrayElement(Srv_prmPostEquRawData,
                             1, u8LocalprmPostEquRawData2);

   VEMS_vidSET(Srv_PostEquIndice, u8LocalprmPostEquRawData1);
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq1, u8LocalprmPostEquRawData2);
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq2, u8LocalprmPostEquRawData2);
   VEMS_vidSET(Srv_bPostEquDone, 1);

   /*API d’accès en écriture de la référence à la volée par le driver EEPROM*/
   NVMSRV_vidWrite(NVMSRV_u16OBJ_POSTEQUSRV, NVMSRV_bSAVE_NOW);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  POSTEQUSRV_vidReInit                                       */
/* !Description :  In case of a writing default, the values are set at the    */
/*                 default values and saved in EEPROM.                        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Srv_PostEquIndice;                                           */
/*  output uint8 Ext_spdVehVSMaxPrmaReq1;                                     */
/*  output uint8 Ext_spdVehVSMaxPrmaReq2;                                     */
/*  output boolean Srv_bPostEquDone;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void POSTEQUSRV_vidReInit(void)
{
   VEMS_vidSET(Srv_PostEquIndice, 0);
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq1, 255);
   VEMS_vidSET(Ext_spdVehVSMaxPrmaReq2, 255);
   VEMS_vidSET(Srv_bPostEquDone, 0);
}
/*-------------------------------- end of file -------------------------------*/