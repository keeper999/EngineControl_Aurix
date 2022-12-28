/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : Camshaft management                                     */
/*                                                                            */
/* !File            : CAMHAL_E.h                                              */
/* !Description     : CAMHAL External Configuration                           */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A81077.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CAMHAL_E_H
#define CAMHAL_E_H

#include "Std_Types.h"
#include "CAMHAL_L.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : CAMHAL_vidMngrCrkDwnModeEntry                               */
/* !Description : Manager for CRKHAL Downgraded Mode Entry are authorized     */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define CAMHAL_vidMngrCrkDwnModeEntry(udtChannelName) \
do \
{ \
   Std_ReturnType  udtLocalStatus; \
   uint8           u8LocalTmp; \
   uint32          u32LocalTmp; \
   CAMHAL_tenuMode enuLocalMode; \
 \
   u32LocalTmp = (uint32)UINT32_MIN; \
 \
   for (u8LocalTmp = (uint8)UINT8_MIN; \
        u8LocalTmp < (uint8)CAMHAL_udtCHANNELS_NUMBER; \
        u8LocalTmp++) \
   { \
      udtLocalStatus = CAMHAL_udtReadMode(u8LocalTmp, &enuLocalMode); \
      if ((enuLocalMode == CAMHAL_udtNORMAL_MODE) && (udtLocalStatus == E_OK)) \
      { \
         CAMHAL_vidSetMode(u8LocalTmp, CAMHAL_udtNOT_SET); \
         u32LocalTmp |= (1U << u8LocalTmp); \
      } \
   } \
 \
   udtLocalStatus = CAMHAL_udtEnableEvtActivation(udtChannelName); \
 \
   for (u8LocalTmp = (uint8)UINT8_MIN; \
        u8LocalTmp < (uint8)CAMHAL_udtCHANNELS_NUMBER; \
        u8LocalTmp++) \
   { \
      if (((u32LocalTmp >> u8LocalTmp) & 1U) != 0U) \
      { \
         CAMHAL_vidSetMode(u8LocalTmp, CAMHAL_udtNORMAL_MODE); \
      } \
   } \
 \
} \
while (0)

/******************************************************************************/
/* !FuncName    : CAMHAL_vidMngrCrkNormalModeEntry                            */
/* !Description : Manager for CRKHAL Normal Mode Entry are authorized         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define CAMHAL_vidMngrCrkNormalModeEntry() \
do \
{ \
   Std_ReturnType  udtLocalStatus; \
   uint8           u8LocalTmp; \
   uint32          u32LocalTmp; \
   CAMHAL_tenuMode enuLocalMode; \
 \
   u32LocalTmp = UINT32_MIN; \
 \
   for (u8LocalTmp = UINT8_MIN; \
        u8LocalTmp < (uint8)CAMHAL_udtCHANNELS_NUMBER; \
        u8LocalTmp++) \
   { \
      udtLocalStatus = CAMHAL_udtReadMode(u8LocalTmp, &enuLocalMode); \
      if ((enuLocalMode == CAMHAL_udtNORMAL_MODE) && (udtLocalStatus == E_OK)) \
      { \
         CAMHAL_vidSetMode(u8LocalTmp, CAMHAL_udtNOT_SET); \
         u32LocalTmp |= (1 << u8LocalTmp); \
      } \
   } \
 \
   udtLocalStatus = CAMHAL_udtDisableEvtActivation(); \
 \
   for (u8LocalTmp = UINT8_MIN; \
        u8LocalTmp < (uint8)CAMHAL_udtCHANNELS_NUMBER; \
        u8LocalTmp++) \
   { \
      if (((u32LocalTmp >> u8LocalTmp) & 1) != 0) \
      { \
         CAMHAL_vidSetMode(u8LocalTmp, CAMHAL_udtNORMAL_MODE); \
      } \
   } \
 \
} \
while (0)

/******************************************************************************/
/* !FuncName    : CAMHAL_vidMngrBackwardRotatEntry                            */
/* !Description : Manager for CRKHAL Backward Rotation Entry                  */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define CAMHAL_vidMngrBackwardRotatEntry() \
do \
{ \
   uint8 u8LocalTmp; \
 \
   CAMHAL_bBackwardRotationDetected = (boolean)TRUE; \
 \
   for (u8LocalTmp = UINT8_MIN; \
        (sint32)u8LocalTmp < (sint32)CAMHAL_udtCHANNELS_NUMBER; \
        u8LocalTmp++) \
   { \
      CAMHAL_vidForceSignalLoss(u8LocalTmp); \
   } \
} \
while (0)

/******************************************************************************/
/* !FuncName    : CAMHAL_vidMngrForwardRotatEntry                             */
/* !Description : Manager for CRKHAL Forward Rotation Entry                   */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
#define CAMHAL_vidMngrForwardRotatEntry() \
do \
{ \
   CAMHAL_bBackwardRotationDetected = FALSE; \
} \
while (0)

#endif /* CAMHAL_E_H */


/*-------------------------------- end of file -------------------------------*/
