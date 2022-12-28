/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RND                                                     */
/* !Description     : RND Component                                           */
/*                                                                            */
/* !Module          : RND                                                     */
/* !Description     : Structure d'accueil pour le module RND                  */
/*                                                                            */
/* !File            : rnd_api.c                                               */
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
/*   1 / RND_vidReadRandomNumber                                              */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RND/RND_API.c_v                   $*/
/* $Revision::   1.0.1.0  $$Author::   srobart        $$Date::   22 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "RND.h"
#include "RND_im.h"
#include "RND_cfg_i.h"
#include "RND_L.h"

#define RND_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Génération de valeur aleatoire                              */
/* !Number      : 1.1                                                         */
/* !Reference   : V02 NT 09 03939 / 1                                         */
/* !Requirement : VEMS_R_09_003939_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*   extf argret argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList */
/*   udtObject);                                                              */
/*   extf argret void ADCHAL_udtRead(argin uint8 u8Channel);                  */
/*   extf argret argret Gpt_ValueType  Gpt_GetTimeElapsed(argin               */
/* Gpt_ChannelType Channel);                                                  */
/*   extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,  */
/* argin boolean bMode);                                                      */
/*   input uint16 RND_u16SeedTimer;                                           */
/*   input uint16 RND_u16SeedOldAlea;                                         */
/*   input boolean RND_bFirstSeedGeneration;                                  */
/*   input uint8 RND_u8inhibit;                                               */
/*   input uint8 RND_kuADCHAL[14];                                            */
/*   output boolean RND_bFirstSeedGeneration;                                 */
/*   output uint16 RND_u16SeedTimer;                                          */
/*   output uint16 RND_u16SeedOldAlea;                                        */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  : F.TOURNAIRE                                                 */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RND_vidReadRandomNumber
(
   uint32* pu32RandomNumber
      
)
{

   uint8   u8RandomNvmObjStatus;
   boolean bFirstSeedGeneration;
   uint8   u8LoopIndex;
   uint8  *pu8LocalRandomNumber;
   uint16  Temp_uw_1;
   uint16  Temp_uw_2;
   uint16  Temp_uw_3;
   uint16  Temp_uw_4;
   uint32  Temp_u4;


   if(RND_u8inhibit != 0x5A)
   {
      *pu32RandomNumber = 0;
      pu8LocalRandomNumber = (uint8 *) pu32RandomNumber;

      Temp_uw_1 = (uint16) (RND_u16SeedTimer | RND_u16SeedOldAlea);



      u8RandomNvmObjStatus = NVMSRV_u8GetStatus(NVMSRV_u16OBJ_RANDOM);

      if ((u8RandomNvmObjStatus != NVMSRV_u8OK) || (RND_bFirstSeedGeneration
            == FALSE))
      {
         bFirstSeedGeneration = TRUE;
      }
      else
      {
         if (Temp_uw_1 == UINT16_MIN)
         {
            bFirstSeedGeneration = TRUE;
         }
         else
         {
            bFirstSeedGeneration = FALSE;
         }
      }
      RND_bFirstSeedGeneration = TRUE;

      if (bFirstSeedGeneration != FALSE)
      {
         Temp_uw_1 = UINT16_MIN;
         Temp_uw_2 = UINT16_MIN;
         for ( u8LoopIndex = UINT8_MIN;
               ((sint32) u8LoopIndex) < (sint32)(NB_MAX_ADC_CHANNEL/2);
               u8LoopIndex++)
         {
         /*The cast to uint16 is need because the api ADCHAL can return several */
         /*types, it  depend to the maximum range used by channels of this API  */
            Temp_uw_3 = (uint16) (ADCHAL_udtRead(RND_kuADCHAL[ u8LoopIndex]));
            Temp_uw_4 = (uint16) (ADCHAL_udtRead(RND_kuADCHAL[ u8LoopIndex
                                               + (uint8)(NB_MAX_ADC_CHANNEL/2)]));
            Temp_u4 = ((uint32) Temp_uw_3) * ((uint32) Temp_uw_4);
            Temp_uw_1 += (uint16) (Temp_u4 & UINT16_MAX);
            Temp_u4 = (Temp_u4 & 4294901760U) >> 16;
            Temp_u4 += (uint32) Temp_uw_2;
            if (Temp_u4 > (uint32)65535)
            {
               Temp_u4 += (uint32)1;
            }
            Temp_uw_2 = (uint16) (Temp_u4 & UINT16_MAX);
         }
         Temp_uw_2 = (uint16) (((uint32) Temp_uw_2) >> 1);
         Temp_u4 = ((uint32) Temp_uw_1) * ((uint32) Temp_uw_2);
         RND_u16SeedTimer = (uint16) (Temp_u4 & UINT16_MAX);
         RND_u16SeedOldAlea = (uint16) ((Temp_u4 & 4294901760U) >> 16);

      }

      Temp_uw_1 = RND_u16SeedOldAlea;
      Temp_uw_2 = RND_u16SeedTimer;
      for (u8LoopIndex = UINT8_MIN; ((sint32) u8LoopIndex) < 4; u8LoopIndex++)
      {
         Temp_u4 = ((uint32) Temp_uw_1) * (uint32)RAND_A_L;
         Temp_uw_1 = (uint16) Temp_u4;
         Temp_u4 = ((uint32) Temp_uw_2) * (uint32)RAND_A_H;
         Temp_uw_1 += (uint16) Temp_u4;
         Temp_u4 = ((uint32) Temp_uw_2) * (uint32)RAND_A_L;
         Temp_u4 = RAND_B + Temp_u4;
         Temp_uw_2 = (uint16) Temp_u4;
         Temp_uw_1 += (uint16) (Temp_u4 >> 16);
         Temp_uw_1 = (uint16) (((uint32) Temp_uw_1) >> 7);
         pu8LocalRandomNumber[u8LoopIndex] = (uint8) Temp_uw_1;
      }
      RND_u16SeedOldAlea = Temp_uw_1;
      RND_u16SeedTimer = (uint16)Gpt_GetTimeElapsed(GPT_udtGPT_APPLICATIVE_TIME);
      NVMSRV_vidWrite(NVMSRV_u16OBJ_RANDOM, NVMSRV_bSAVE_NOW);
   }
   else
   {
      *pu32RandomNumber = 0x11111111;
   }
}

#define RND_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/

