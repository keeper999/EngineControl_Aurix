/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_SCH19.C                                   */
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
/*   1 / RE_OEMGsl_003_TEVIf                                                  */
/*   2 / AirPres_SdlSlow_AirExtPresAcqIf                                      */
/*   3 / AirPres_SdlFast_AirExtPresAcqIf                                      */
/*   4 / Oil_SdlMid_ActrTstCtlPmpIf                                           */
/*   5 / RE_InMdlT_020_TEVIf                                                  */
/*   6 / RE_InMdlT_043_MSEIf                                                  */
/*   7 / RE_StopStrtEng_013_MSEIf                                             */
/*   8 / RE_StopStrtEng_014_TEVIf                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
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
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_OEMGsl_003_TEVIf                                        */
/* !Description :  Scheduler du module OEMGsl .                               */
/* !Number      :  SCH19.1                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutOCHeatPhaReq();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_OEMGsl_003_TEVIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_OEMGsl_003_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutOCHeatPhaReq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlSlow_AirExtPresAcqIf                            */
/* !Description :  Moniteur lent.                                             */
/* !Number      :  SCH19.2                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidOutAtmphPress();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input boolean Ext_bRun;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlSlow_AirExtPresAcqIf                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlSlow_AirExtPresAcqIf(void)
{
   boolean bLocalCtrl_bAcv_pAirExtMes;
   boolean bLocalExt_bRun;


   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);

      if (  (bLocalExt_bRun != 0)
         && (bLocalCtrl_bAcv_pAirExtMes != 0))
      {
         IFAIRSYSIGSYS_vidOutAtmphPress();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_AirExtPresAcqIf                            */
/* !Description :  Monitoring rapide de la fonction AirPres.                  */
/* !Number      :  SCH19.3                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidOutAtmphPress();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*  input boolean Ctrl_bAcv_pAirExtMes;                                       */
/*  input boolean Ext_bRun;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlFast_AirExtPresAcqIf                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_AirExtPresAcqIf(void)
{
   boolean bLocalCtrl_bAcv_pAirExtMes;
   boolean bLocalExt_bRun;


   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pAirExtMes, bLocalCtrl_bAcv_pAirExtMes);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);

      if (  (bLocalExt_bRun == 0)
         && (bLocalCtrl_bAcv_pAirExtMes != 0))
      {
         IFAIRSYSIGSYS_vidOutAtmphPress();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlMid_ActrTstCtlPmpIf                                 */
/* !Description :  Scheduler moyen.                                           */
/* !Number      :  SCH19.4                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutbCtlPmpReq();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlMid_ActrTstCtlPmpIf                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlMid_ActrTstCtlPmpIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutbCtlPmpReq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_InMdlT_020_TEVIf                                        */
/* !Description :  Moniteur 5ms de la fonction InMdlT.                        */
/* !Number      :  SCH19.5                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutfacVlvOvlp();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_InMdlT_020_TEVIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_InMdlT_020_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidOutfacVlvOvlp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_InMdlT_043_MSEIf                                        */
/* !Description :  Evènement.                                                 */
/* !Number      :  SCH19.6                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutfacVlvOvlp();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_InMdlT_043_MSEIf                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_InMdlT_043_MSEIf(void)
{
   IFAIRSYSIGSYS_vidOutfacVlvOvlp();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_StopStrtEng_013_MSEIf                                   */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH19.7                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInterfacCstrIf1();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_StopStrtEng_013_MSEIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_StopStrtEng_013_MSEIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInterfacCstrIf1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RE_StopStrtEng_014_TEVIf                                   */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH19.8                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidInterfacCstrIf1();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RE_StopStrtEng_014_TEVIf                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RE_StopStrtEng_014_TEVIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidInterfacCstrIf1();
   }
}

/*-------------------------------- end of file -------------------------------*/