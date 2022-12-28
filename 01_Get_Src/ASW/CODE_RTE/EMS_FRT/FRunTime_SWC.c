/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FRT                                                     */
/* !Description     : FRT component                                           */
/*                                                                            */
/* !Module          : FRT                                                     */
/* !Description     : Free Run Timer                                          */
/*                                                                            */
/* !File            : FRunTime_SWC.c                                          */
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
/*   1 / FRunTime_GetTimer1msU32                                              */
/*   2 / FRunTime_GetTimer_1ms_U32                                            */
/*   3 / FRunTime_GetTimer_100ms_U32                                          */
/*   4 / FRunTime_GetTimer100msU32                                            */
/*   5 / FRunTime_GetTimer1sU32                                               */
/*   6 / FRunTime_GetTimer_1s_U32                                             */
/*   7 / FRunTime_GetTimer_1min_U32                                           */
/*   8 / FRunTime_GetTimer1minU32                                             */
/*   9 / FRunTime_Init                                                        */
/*   10 / FRunTime_SdlFast                                                    */
/*   11 / FRunTime_SdlMid                                                     */
/*   12 / FRunTime_SdlSlow                                                    */
/*   13 / FRunTime_GetTimer100usU32                                           */
/*   14 / FRunTime_GetTimer_100us_U32                                         */
/*   15 / FRunTime_vidUpdate_Nb_Roll_Ov                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6307798 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/FRT/FRunTime_SWC.c_v       $*/
/* $Revision::   1.10     $$Author::   hmelloul       $$Date::   04 Apr 2014 $*/
/* $Author::   hmelloul                               $$Date::   04 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

/*#include "Rte_FRunTime_SWC.h"*/
#include "Rte_FRunTime1.h"

#include "FRT.h"
#include "FRT_L.h"

#include "Std_Types.h"
#include "Std_Limits.h"

#include "GPT.h"

#define FRT_START_SEC_CODE
#include "FRT_MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer1msU32                                    */
/* !Description :  API permettant d'obtenir un Timer 1ms                      */
/* !Number      :  API.01                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRunTime_vidUpdate_Nb_Roll_Ov();                         */
/*  input uint32 FRunTime_u32NbRollOver;                                      */
/*  input uint32 FRunTime_u32GptValue;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer1msU32
(
   uint32* CurrentTime1msPtr
)
{
   unsigned long long  Local_u64TimeElapsed;
   /*QAC :"Msg(4:1027) [E] long long is a language extension",Ignorer ce message
   car ce type de variable n'est pas déclaré dans la base temp.mde*/
   uint32              u32LocalCurrentTime;


   FRunTime_vidUpdate_Nb_Roll_Ov();
   Local_u64TimeElapsed = ((unsigned long long)FRunTime_u32NbRollOver << 24);
   Local_u64TimeElapsed =
      Local_u64TimeElapsed + ((unsigned long long)FRunTime_u32GptValue);
   Local_u64TimeElapsed = Local_u64TimeElapsed / ((unsigned long long)2000);
   u32LocalCurrentTime = (uint32)Local_u64TimeElapsed;
   /*QAC :"Msg(2:3212) This explicit cast is redundant and could be removed
   A Ignorer car il cause un warning lors de la compilation*/
   *CurrentTime1msPtr = u32LocalCurrentTime;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer_1ms_U32                                  */
/* !Description :  API permettant d'obtenir un Timer 1ms                      */
/* !Number      :  API.05                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRunTime_vidUpdate_Nb_Roll_Ov();                         */
/*  input uint32 FRunTime_u32NbRollOver;                                      */
/*  input uint32 FRunTime_u32GptValue;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer_1ms_U32
(
   uint32* CurrentTime1msPtr
)
{
   unsigned long long  Local_u64TimeElapsed;
   /*QAC :"Msg(4:1027) [E] long long is a language extension",Ignorer ce message
   car ce type de variable n'est pas déclaré dans la base temp.mde*/
   uint32              u32LocalCurrentTime;


   FRunTime_vidUpdate_Nb_Roll_Ov();
   Local_u64TimeElapsed = ((unsigned long long)FRunTime_u32NbRollOver << 24);
   Local_u64TimeElapsed =
      Local_u64TimeElapsed + ((unsigned long long)FRunTime_u32GptValue);
   Local_u64TimeElapsed = Local_u64TimeElapsed / ((unsigned long long)2000);
   u32LocalCurrentTime = (uint32)Local_u64TimeElapsed;
   /*QAC :"Msg(2:3212) This explicit cast is redundant and could be removed
   A Ignorer car il cause un warning lors de la compilation*/
   *CurrentTime1msPtr = u32LocalCurrentTime;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer_100ms_U32                                */
/* !Description :  API permettant d'obtenir un Timer 100ms                    */
/* !Number      :  API.11                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_100msU32;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer_100ms_U32
(
   uint32* CurrentTime100msPtr
)
{
   *CurrentTime100msPtr = FRunTime_100msU32;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer100msU32                                  */
/* !Description :  API permettant d'obtenir un Timer 100ms                    */
/* !Number      :  API.10                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_100msU32;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer100msU32
(
   uint32* CurrentTime100msPtr
)
{
   *CurrentTime100msPtr = FRunTime_100msU32;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer1sU32                                     */
/* !Description :  API permettant d'obtenir un Timer 1S                       */
/* !Number      :  API.02                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_sU32;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer1sU32
(
   uint32* CurrentTime1sPtr
)
{
   *CurrentTime1sPtr = FRunTime_sU32;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer_1s_U32                                   */
/* !Description :  API permettant d'obtenir un Timer 1S                       */
/* !Number      :  API.06                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_sU32;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer_1s_U32
(
   uint32* CurrentTime1sPtr
)
{
   *CurrentTime1sPtr = FRunTime_sU32;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer_1min_U32                                 */
/* !Description :  API permettant d'obtenir un Timer 1min                     */
/* !Number      :  API.07                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_minU32;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer_1min_U32
(
   uint32* CurrentTime1minPtr
)
{
   *CurrentTime1minPtr = FRunTime_minU32;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer1minU32                                   */
/* !Description :  API permettant d'obtenir un Timer 1min                     */
/* !Number      :  API.03                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_minU32;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer1minU32
(
   uint32* CurrentTime1minPtr
)
{
   *CurrentTime1minPtr = FRunTime_minU32;

   return E_OK;
}

/*------------------------[port handle API]-----------------------------------*/

/*------------------------[per instance memory API]---------------------------*/

/*------------------------[Mode API]------------------------------------------*/

/*------------------------[Internal function]---------------------------------*/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_Init                                              */
/* !Description :  Fonction d'INIT                                            */
/* !Number      :  SCH.01                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_6307798_001.01                                      */
/*                 VEMS_R_6307798_002.01                                      */
/*                 VEMS_R_6307798_003.01                                      */
/*                 VEMS_R_6307798_004.01                                      */
/*                 VEMS_R_6307798_005.01                                      */
/*                 VEMS_R_6307798_006.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Gpt_GetTimeElapsed(argin uint16 channel)uint32;          */
/*  output uint32 FRunTime_sU32;                                              */
/*  output uint32 FRunTime_100msU32;                                          */
/*  output uint32 FRunTime_minU32;                                            */
/*  output uint32 FRunTime_u32NbRollOver;                                     */
/*  output uint32 FRunTime_u32GptValue;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRunTime_Init(void)
{
   FRunTime_sU32     = 0;
   FRunTime_100msU32 = 0;
   FRunTime_minU32   = 0;
   FRunTime_u32NbRollOver = 0;
   FRunTime_u32GptValue =
      Gpt_GetTimeElapsed(GptConf_GptChannel_APPLICATIVE_500NS);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_SdlFast                                           */
/* !Description :  Function Fast                                              */
/* !Number      :  SCH.04                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_6307798_001.01                                      */
/*                 VEMS_R_6307798_002.01                                      */
/*                 VEMS_R_6307798_003.01                                      */
/*                 VEMS_R_6307798_004.01                                      */
/*                 VEMS_R_6307798_005.01                                      */
/*                 VEMS_R_6307798_006.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_100msU32;                                           */
/*  output uint32 FRunTime_100msU32;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FRunTime_SdlFast                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRunTime_SdlFast(void)
{
   FRunTime_100msU32 = (FRunTime_100msU32 + 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_SdlMid                                            */
/* !Description :  Function middle                                            */
/* !Number      :  SCH.02                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_6307798_001.01                                      */
/*                 VEMS_R_6307798_002.01                                      */
/*                 VEMS_R_6307798_003.01                                      */
/*                 VEMS_R_6307798_004.01                                      */
/*                 VEMS_R_6307798_005.01                                      */
/*                 VEMS_R_6307798_006.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRunTime_vidUpdate_Nb_Roll_Ov();                         */
/*  input uint32 FRunTime_sU32;                                               */
/*  output uint32 FRunTime_sU32;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FRunTime_SdlMid                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRunTime_SdlMid(void)
{
   FRunTime_vidUpdate_Nb_Roll_Ov();
   FRunTime_sU32 = (FRunTime_sU32 + 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_SdlSlow                                           */
/* !Description :  Fonction lente du FRT                                      */
/* !Number      :  SCH.03                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_6307798_001.01                                      */
/*                 VEMS_R_6307798_002.01                                      */
/*                 VEMS_R_6307798_003.01                                      */
/*                 VEMS_R_6307798_004.01                                      */
/*                 VEMS_R_6307798_005.01                                      */
/*                 VEMS_R_6307798_006.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint32 FRunTime_minU32;                                             */
/*  output uint32 FRunTime_minU32;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FRunTime_SdlSlow                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRunTime_SdlSlow(void)
{
   FRunTime_minU32 = (FRunTime_minU32 + 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer100usU32                                  */
/* !Description :  API permettant d'obtenir un timer de 100µs                 */
/* !Number      :  API.04                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRunTime_vidUpdate_Nb_Roll_Ov();                         */
/*  input uint32 FRunTime_u32NbRollOver;                                      */
/*  input uint32 FRunTime_u32GptValue;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer100usU32
(
   uint32* CurrentTime100usPtr
)
{
   unsigned long long  Local_u64TimeElapsed;
   /*QAC :"Msg(4:1027) [E] long long is a language extension",Ignorer ce message
   car ce type de variable n'est pas déclaré dans la base temp.mde*/
   uint32              u32LocalCurrentTime;

   FRunTime_vidUpdate_Nb_Roll_Ov();
   Local_u64TimeElapsed = ((unsigned long long)FRunTime_u32NbRollOver << 24);
   Local_u64TimeElapsed =
      Local_u64TimeElapsed + ((unsigned long long)FRunTime_u32GptValue);
   Local_u64TimeElapsed = Local_u64TimeElapsed / ((unsigned long long)200);
   u32LocalCurrentTime  = (uint32)Local_u64TimeElapsed;
   /*QAC :"Msg(2:3212) This explicit cast is redundant and could be removed
   A Ignorer car il cause un warning lors de la compilation*/
   *CurrentTime100usPtr = u32LocalCurrentTime;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_GetTimer_100us_U32                                */
/* !Description :  API permettant d'obtenir un timer de 100µs                 */
/* !Number      :  API.08                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FRunTime_vidUpdate_Nb_Roll_Ov();                         */
/*  input uint32 FRunTime_u32NbRollOver;                                      */
/*  input uint32 FRunTime_u32GptValue;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType FRunTime_GetTimer_100us_U32
(
   uint32* CurrentTime100usPtr
)
{
   unsigned long long  Local_u64TimeElapsed;
   /*QAC :"Msg(4:1027) [E] long long is a language extension",Ignorer ce message
   car ce type de variable n'est pas déclaré dans la base temp.mde*/
   uint32              u32LocalCurrentTime;


   FRunTime_vidUpdate_Nb_Roll_Ov();
   Local_u64TimeElapsed = ((unsigned long long)FRunTime_u32NbRollOver << 24);
   Local_u64TimeElapsed = Local_u64TimeElapsed + ((unsigned long long)FRunTime_u32GptValue);
   Local_u64TimeElapsed = Local_u64TimeElapsed / ((unsigned long long)200);
   u32LocalCurrentTime = (uint32)Local_u64TimeElapsed;
   /*QAC :"Msg(2:3212) This explicit cast is redundant and could be removed
   A Ignorer car il cause un warning lors de la compilation*/
   *CurrentTime100usPtr = u32LocalCurrentTime;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FRunTime_vidUpdate_Nb_Roll_Ov                              */
/* !Description :  vérifie si un roll-over a eu lieu et incrémente le compteur*/
/*                 si un roll-over est detecté"                               */
/* !Number      :  API.09                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Gpt_GetTimeElapsed(argin uint16 channel)uint32;          */
/*  input uint32 FRunTime_u32GptValue;                                        */
/*  input uint32 FRunTime_u32NbRollOver;                                      */
/*  output uint32 FRunTime_u32NbRollOver;                                     */
/*  output uint32 FRunTime_u32GptValue;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FRunTime_vidUpdate_Nb_Roll_Ov(void)
{
   Gpt_ValueType  udtGetTimeElapsed;


   udtGetTimeElapsed = Gpt_GetTimeElapsed(GptConf_GptChannel_APPLICATIVE_500NS);
   if (udtGetTimeElapsed < FRunTime_u32GptValue)
   {
      FRunTime_u32NbRollOver = (FRunTime_u32NbRollOver + 1);
   }
   FRunTime_u32GptValue = udtGetTimeElapsed;
}

#define FRT_STOP_SEC_CODE
#include "FRT_MemMap.h"
/*------------------------------- end of file --------------------------------*/