/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL_HOOK.h                                           */
/* !Description     : Hooks for Diagnostics Management of the INJHAL Component*/
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
 * %PID: P2017_BSW:0A192550.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef _INJHAL_HOOK_H_
#define _INJHAL_HOOK_H_

#include "Std_Types.h"
#include "L9781.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : INJHAL_vidINJECTON_START_HOOK                               */
/* !Description : Hook function called by INJHAL component at the beginning   */
/*                of each injection of 'snChannel', i.e. just after timer     */
/*                controlling injection on 'snChannel' channel is started     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidINJECTON_START_HOOK( \
\
   snChannel \
\
)

/******************************************************************************/
/* !FuncName    : INJHAL_vidINJECTON_STOP_HOOK                                */
/* !Description : Hook function called by INJHAL component at the end         */
/*                of each injection of 'snChannel', i.e. just after timer     */
/*                controlling injection on 'snChannel' channel is stopped     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidINJECTON_STOP_HOOK( \
\
   snChannel \
\
)

/******************************************************************************/
/* !FuncName    : INJHAL_vidENABLE_HOOK                                       */
/* !Description : Hook function called by INJHAL component when injection     */
/*                on 'snInstance' instance is enabled                         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidENABLE_HOOK(snChannel) \
   M1_INJHAL_vidENABLE_HOOK(snChannel)

   #define M1_INJHAL_vidENABLE_HOOK(snChannel) (void)L9781_udtEnable()

/******************************************************************************/
/* !FuncName    : INJHAL_vidDISABLE_HOOK                                      */
/* !Description : Hook function called by INJHAL component when injection     */
/*                on 'snInstance' instance is disabled                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidDISABLE_HOOK(snChannel) \
   M1_INJHAL_vidDISABLE_HOOK(snChannel)

   #define M1_INJHAL_vidDISABLE_HOOK(snChannel) L9781_vidDisable()

/******************************************************************************/
/* !FuncName    : INJHAL_vidINJECTON_PRESTART_HOOK                            */
/* !Description : Hook function called by INJHAL component at the beginning   */
/*                of each injection of 'snChannel', i.e. just before timer    */
/*                controlling injection on 'snChannel' channel is started     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidINJECTON_PRESTART_HOOK( \
\
   snChannel, \
   u8Pulse, \
   u32InjTime \
\
) \
   M1_INJHAL_vidINJ_PRESTART_HOOK(INJHAL_u8GET_CHANNEL_ID(snChannel), \
                                  u8Pulse, \
                                  u32InjTime) \

   #define M1_INJHAL_vidINJ_PRESTART_HOOK(u8Channel, u8Pulse, u32InjTime) \
              COMPILER_UNUSED_PARAMETER(u8Pulse);

/******************************************************************************/
/* !FuncName    : INJHAL_vidTEST_MODE_ENTRY_HOOK                              */
/* !Description : Hook function called by INJHAL component when entering the  */
/*                test mode                                                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidTEST_MODE_ENTRY_HOOK(snChannel) \
   M1_INJHAL_vidTST_MODE_ENTRY_HOOK(snChannel)

   #define M1_INJHAL_vidTST_MODE_ENTRY_HOOK(snChannel) /*(void)L9781_udtEnable()*/

/******************************************************************************/
/* !FuncName    : INJHAL_vidTEST_MODE_EXIT_HOOK                               */
/* !Description : Hook function called by INJHAL component when exiting the   */
/*                test mode                                                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define INJHAL_vidTEST_MODE_EXIT_HOOK(snChannel) \
   M1_INJHAL_vidTEST_MODE_EXIT_HOOK(snChannel)

   #define M1_INJHAL_vidTEST_MODE_EXIT_HOOK(snChannel)


#endif /* _INJHAL_HOOK_H_ */

/*-------------------------------- end of file -------------------------------*/
