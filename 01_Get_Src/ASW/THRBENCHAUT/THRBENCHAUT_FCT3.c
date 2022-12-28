/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBENCHAUT                                             */
/* !Description     : THRBENCHAUT Component                                   */
/*                                                                            */
/* !Module          : THRBENCHAUT                                             */
/* !Description     : MODE BANC AUTOMATIQUE PAPILLON MOTORISE                 */
/*                                                                            */
/* !File            : THRBENCHAUT_FCT3.C                                      */
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
/*   1 / THRBENCHAUT_vidSinTimeFourthQuad                                     */
/*   2 / THRBENCHAUT_vidSinTimeFirstQuad                                      */
/*   3 / THRBENCHAUT_vidSinTimeSecondQuad                                     */
/*   4 / THRBENCHAUT_vidSinTimeThirdQuad                                      */
/*   5 / THRBENCHAUT_vidResetSinTime                                          */
/*   6 / THRBENCHAUT_vidIncrGenTimeCount                                      */
/*   7 / THRBENCHAUT_vidIncrSignalCount                                       */
/*   8 / THRBENCHAUT_vidNextSignal                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 04529 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#055915                                         */
/* !OtherRefs   : VEMS V02 ECU#056022                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRBENCHAUT/THRBENCHAUT_FCT3$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRBENCHAUT.h"
#include "THRBENCHAUT_L.h"
#include "THRBENCHAUT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidSinTimeFourthQuad                           */
/* !Description :  Calcul de l'angle eval quatrième quadrant                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_sin_time_constant4;                                     */
/*  input uint8 Tpac_sin_freq;                                                */
/*  input uint16 Tpac_sin_func_entry;                                         */
/*  output uint16 Tpac_sin_func_entry;                                        */
/*  output boolean Tpac_sin_inverse_output;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidSinTimeFourthQuad(void)
{
   sint32 s32LocalSinEntry;


   /* sin_time_fourth_quadrant */
   s32LocalSinEntry = (sint32)( Tpac_sin_func_entry
                              - ( ( ( (Tpac_sin_time_constant4 * 12207)
                                    / 10000000)
                                  * (Tpac_sin_freq + 1))
                                + ( ( ( (Tpac_sin_time_constant4 * 12207)
                                      % 10000000)
                                    * (Tpac_sin_freq + 1))
                                  / 10000000)));
   Tpac_sin_func_entry = (uint16)MATHSRV_udtCLAMP(s32LocalSinEntry, 0, 512);
   Tpac_sin_inverse_output = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidSinTimeFirstQuad                            */
/* !Description :  Calcul de l'angle eval premier quadrant                    */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_sin_time_constant1;                                     */
/*  input uint8 Tpac_sin_freq;                                                */
/*  input uint16 Tpac_sin_func_entry;                                         */
/*  output uint16 Tpac_sin_func_entry;                                        */
/*  output boolean Tpac_sin_inverse_output;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidSinTimeFirstQuad(void)
{
   uint32 u32LocalSinEntry;


   /* sin_time_first_quadrant */
   u32LocalSinEntry = (uint32)( Tpac_sin_func_entry
                              + ( ( ( (Tpac_sin_time_constant1 * 12207)
                                    / 10000000)
                                  * (Tpac_sin_freq + 1))
                                + ( ( ( (Tpac_sin_time_constant1 * 12207)
                                      % 10000000)
                                    * (Tpac_sin_freq + 1))
                                  / 10000000)));
   Tpac_sin_func_entry = (uint16)MATHSRV_udtMIN(u32LocalSinEntry, 512);
   Tpac_sin_inverse_output = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidSinTimeSecondQuad                           */
/* !Description :  Calcul de l'angle eval deuxième quadrant                   */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_sin_time_constant2;                                     */
/*  input uint8 Tpac_sin_freq;                                                */
/*  input uint16 Tpac_sin_func_entry;                                         */
/*  output uint16 Tpac_sin_func_entry;                                        */
/*  output boolean Tpac_sin_inverse_output;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidSinTimeSecondQuad(void)
{
   sint32 s32LocalSinEntry;


   /* sin_time_second_quadrant */
   s32LocalSinEntry = (sint32)( Tpac_sin_func_entry
                              - ( ( ( (Tpac_sin_time_constant2 * 12207)
                                    / 10000000)
                                  * (Tpac_sin_freq + 1))
                                + ( ( ( (Tpac_sin_time_constant2 * 12207)
                                      % 10000000)
                                    * (Tpac_sin_freq + 1))
                                  / 10000000)));
   Tpac_sin_func_entry = (uint16)MATHSRV_udtCLAMP(s32LocalSinEntry, 0, 512);
   Tpac_sin_inverse_output = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidSinTimeThirdQuad                            */
/* !Description :  Calcul de l'angle eval troisième quadrant                  */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_sin_time_constant3;                                     */
/*  input uint8 Tpac_sin_freq;                                                */
/*  input uint16 Tpac_sin_func_entry;                                         */
/*  output uint16 Tpac_sin_func_entry;                                        */
/*  output boolean Tpac_sin_inverse_output;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidSinTimeThirdQuad(void)
{
   uint32 u32LocalSinEntry;


   /* sin_time_third_quadrant */
   u32LocalSinEntry = (uint32)( Tpac_sin_func_entry
                              + ( ( ( (Tpac_sin_time_constant3 * 12207)
                                    / 10000000)
                                  * (Tpac_sin_freq + 1))
                                + ( ( ( (Tpac_sin_time_constant3 * 12207)
                                      % 10000000)
                                    * (Tpac_sin_freq + 1))
                                  / 10000000)));
   Tpac_sin_func_entry = (uint16)MATHSRV_udtMIN(u32LocalSinEntry, 512);
   Tpac_sin_inverse_output = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidResetSinTime                                */
/* !Description :  Ce bloc réinitialise Tpac_sin_time et Tpac_sin_func_entry à*/
/*                 leur valeur de départ. Afin de commencer le cycle du sinus */
/*                 avec les bonnes valeurs, on n'effectue pas l'addition de   */
/*                 0.008s sur Tpac_sin_time lorsque ce bloc est exécuté       */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Tpac_sin_time;                                              */
/*  output uint16 Tpac_sin_time_count;                                        */
/*  output uint16 Tpac_sin_func_entry;                                        */
/*  output boolean Tpac_sin_inverse_output;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidResetSinTime(void)
{
   /* reset_sin_time */
   Tpac_sin_time           = 0;
   Tpac_sin_time_count     = 0;
   Tpac_sin_func_entry     = 512;
   Tpac_sin_inverse_output = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidIncrGenTimeCount                            */
/* !Description :  Ce bloc réinitialise Tpac_sin_time et Tpac_sin_func_entry à*/
/*                 leur valeur de départ. Afin de commencer le cycle du sinus */
/*                 avec les bonnes valeurs, on n'effectue pas l'addition de   */
/*                 0.008s sur Tpac_sin_time lorsque ce bloc est exécuté       */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_sin_time_count;                                         */
/*  output uint16 Tpac_sin_time_count;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidIncrGenTimeCount(void)
{
   /* increase_generator_time_count */
   uint32 u32LocalTpac_time_count;


   u32LocalTpac_time_count = (uint32)Tpac_sin_time_count + 1;
   Tpac_sin_time_count = (uint16)MATHSRV_udtMIN(u32LocalTpac_time_count, 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidIncrSignalCount                             */
/* !Description :  Ce bloc incrémente de 1 le numéro du signal utilisé        */
/*                 (Tpac_sin_signal_count) quand la durée de ce signal est    */
/*                 écoulée.                                                   */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf Mfx_RMulDiv_u32u32u32_u32(????);                                     */
/*  extf argret void THRBENCHAUT_vidNextSignal();                             */
/*  input uint8 Tpac_sin_signal_count;                                        */
/*  input uint8 Tpac_sin_period_count_map[8];                                 */
/*  input uint8 Tpac_sin_freq;                                                */
/*  input uint16 Tpac_sin_time_count;                                         */
/*  input uint16 Tpac_sin_duration;                                           */
/*  output uint16 Tpac_sin_duration;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidIncrSignalCount(void)
{
   uint8  u8LocalCalcIndex1d;
   uint8  u8LocalTpacSinSignalCount;
   uint32 u32LocalTpacSinDuration;


   /* increase_signal_count */
   u8LocalTpacSinSignalCount = (uint8)MATHSRV_udtMIN(Tpac_sin_signal_count, 7);
   u8LocalCalcIndex1d = Tpac_sin_period_count_map[u8LocalTpacSinSignalCount];

   u32LocalTpacSinDuration = (uint32)(12207 * (Tpac_sin_freq + 1));
   u32LocalTpacSinDuration =
      Mfx_RMulDiv_u32u32u32_u32((uint32)u8LocalCalcIndex1d,
                                20000000,
                                u32LocalTpacSinDuration);
   Tpac_sin_duration = (uint16)MATHSRV_udtMIN(u32LocalTpacSinDuration, 52427);
   if (Tpac_sin_time_count >= Tpac_sin_duration)
   {
      THRBENCHAUT_vidNextSignal();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidNextSignal                                  */
/* !Description :  Calcul du numéro du signal sinus en cours d'émission       */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tpac_sin_signal_count;                                        */
/*  input uint8 Tpac_sin_signal_number;                                       */
/*  output uint8 Tpac_sin_signal_count;                                       */
/*  output uint16 Tpac_sin_time_count;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidNextSignal(void)
{
   uint16 u16LocalTpac_signal_count;


   /* next_signal */
   u16LocalTpac_signal_count = (uint16)(Tpac_sin_signal_count + 1);
   if (u16LocalTpac_signal_count > Tpac_sin_signal_number)
   {
      Tpac_sin_signal_count = 0;
   }
   else
   {
      Tpac_sin_signal_count = (uint8)u16LocalTpac_signal_count;
   }
   Tpac_sin_time_count = 0;
}
/*------------------------------- end of file --------------------------------*/