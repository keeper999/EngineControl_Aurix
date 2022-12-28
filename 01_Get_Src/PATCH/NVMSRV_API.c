/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : NVMSRV                                                  */
/* !Description     : NVM Service Layer                                       */
/*                                                                            */
/* !File            : NVMSRV_API.c                                            */
/* !Description     : API of the NVMSRV Component                             */
/*                                                                            */
/* !Reference       : V03 NT 12 00986 / 03                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A238.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "std_types.h"
#include "std_limits.h"
#include "SWFAIL.h"
#include "NOPROD.h"
#include "NVMSRV.h"
#include "Users_NvM.h"

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"
#define NVMSRV_u8OK 0
#define NVMSRV_u8BUSY 1
#define NVMSRV_u8DEFAULT 1
#define NVMSRV_u8FAILED 2
/******************************************************************************/
/* Check that Conditional Compilation defines are defined                     */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : NVMSRV_vidInit                                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidInit(void)
{
}

/******************************************************************************/
/* !FuncName    : NVMSRV_vidWrite                                             */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidWrite
(
   uint16 udtObject,
   boolean               bMode
)
{
Std_ReturnType NvMFctRslt;
NvM_RequestResultType NvMJobResult;

   switch(udtObject)
   {
      case NVMSRV_u16OBJ_ACCPEM:
         NvMFctRslt = NvM_SetBlockProtection(NvM_ACCPEM, FALSE);
         NvM_SetRamBlockStatus(NvM_ACCPEM, TRUE);
         if (NvMFctRslt == E_OK)
         {
            NvMFctRslt = NvM_WriteBlock(NvM_ACCPEM, &ACCPEM_NvMRamBlockDataStruct);
         }
      break;
      // case NVMSRV_udtOBJ_MEM1:
      // case NVMSRV_udtOBJ_MEM10:
      // case NVMSRV_udtOBJ_MEM11:
      // case NVMSRV_udtOBJ_MEM12:
      // case NVMSRV_udtOBJ_MEM13:
      // case NVMSRV_udtOBJ_MEM14:
      // case NVMSRV_udtOBJ_MEM15:
      // case NVMSRV_udtOBJ_MEM16:
      // case NVMSRV_udtOBJ_MEM17:
      // case NVMSRV_udtOBJ_MEM18:
      // case NVMSRV_udtOBJ_MEM19:
      // case NVMSRV_udtOBJ_MEM2 :
      // case NVMSRV_udtOBJ_MEM20:
      // case NVMSRV_udtOBJ_MEM21:
      // case NVMSRV_udtOBJ_MEM22:
      // case NVMSRV_udtOBJ_MEM23:
      // case NVMSRV_udtOBJ_MEM24:
      // case NVMSRV_udtOBJ_MEM25:
      // case NVMSRV_udtOBJ_MEM26:
      // case NVMSRV_udtOBJ_MEM27:
      // case NVMSRV_udtOBJ_MEM28:
      // case NVMSRV_udtOBJ_MEM29:
      // case NVMSRV_udtOBJ_MEM3 :
      // case NVMSRV_udtOBJ_MEM30:
      // case NVMSRV_udtOBJ_MEM31:
      // case NVMSRV_udtOBJ_MEM32:
      // case NVMSRV_udtOBJ_MEM33:
      // case NVMSRV_udtOBJ_MEM34:
      // case NVMSRV_udtOBJ_MEM35:
      // case NVMSRV_udtOBJ_MEM36:
      // case NVMSRV_udtOBJ_MEM37:
      // case NVMSRV_udtOBJ_MEM38:
      // case NVMSRV_udtOBJ_MEM39:
      // case NVMSRV_udtOBJ_MEM4 :
      // case NVMSRV_udtOBJ_MEM40:
      // case NVMSRV_udtOBJ_MEM5 :
      // case NVMSRV_udtOBJ_MEM6 :
      // case NVMSRV_udtOBJ_MEM7 :
      // case NVMSRV_udtOBJ_MEM8 :
      // case NVMSRV_udtOBJ_MEM9 :      
      // break;
      // case NVMSRV_u16OBJ_POSTEQUSRV_BANTISCANNING:
      // break;
      // case NVMSRV_u16OBJ_POSTEQUSRV:
      // break;
      // case NVMSRV_udtOBJ_ECUSTSRVPWRLST:
      // break;
      // case NVMSRV_u16OBJ_REFIDETA:
      // break;
      // case NVMSRV_u16OBJ_RANDOM:
      // break;
      // case NVMSRV_udtOBJ_SAIMMO_CODE:
      // break;
      // case NVMSRV_udtOBJ_SAIMMO_CODE:
      // break;
      // case NVMSRV_udtOBJ_SAIMMO_ETAT:
      // break;
      // case NVMSRV_u16OBJ_SFTYMNGR:
      // break;
      // case NVMSRV_u16OBJ_TELE_BANTISCANNING:
      // break;
      // case NVMSRV_u16OBJ_TELECODAGE:
      // break;
      // case NVMSRV_udtOBJ_EXCEPTION_REGS:
      // break;
      // case NVMSRV_udtOBJ_RESET:
      // break;
      default:
      break;
   }
}

/******************************************************************************/
/* !FuncName    : NVMSRV_vidRead                                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidRead
(
   uint16 udtObject
)
{
Std_ReturnType NvMFctRslt;
NvM_RequestResultType NvMJobResult;

   if (udtObject == NVMSRV_u16OBJ_REFIDETA)
   {
      NvMFctRslt = NvM_ReadBlock(NvM_REFIDETA, &REFIDETA_NvMRamBlockDataStruct);
   }
   else if (udtObject == NVMSRV_u16OBJ_ACCPEM)
   {
      NvMFctRslt = NvM_ReadBlock(NvM_ACCPEM, &ACCPEM_NvMRamBlockDataStruct);
   }
}

/******************************************************************************/
/* !FuncName    : NVMSRV_u8GetStatus                                          */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint8 NVMSRV_u8GetStatus
(
   uint16 udtObject
)
{
   uint8 u8LocalStatus;
   Std_ReturnType NvMFctRslt;
   NvM_RequestResultType NvMJobResult;

   NvMFctRslt = NvM_GetErrorStatus(udtObject, &NvMJobResult);
   if (NvMFctRslt == E_OK)
   {
      switch(NvMJobResult)
      {
         case NVM_REQ_OK:
            u8LocalStatus = NVMSRV_u8OK;
         break;
         case NVM_REQ_PENDING:
            u8LocalStatus = NVMSRV_u8BUSY;
         break;
         case NVM_REQ_NOT_OK:
            u8LocalStatus = NVMSRV_u8DEFAULT;
         break;
         case NVM_REQ_INTEGRITY_FAILED:
            u8LocalStatus = NVMSRV_u8FAILED;
         break;
         default:
            u8LocalStatus = NVMSRV_u8DEFAULT;
         break;
      }
   }
   else
   {
      u8LocalStatus = NVMSRV_u8DEFAULT;
   }
   
   return(u8LocalStatus);
}

/******************************************************************************/
/* !FuncName    : NVMSRV_vidSave                                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidSave(void)
{
}

/******************************************************************************/
/* !FuncName    : NVMSRV_bAllSaved                                            */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
boolean NVMSRV_bAllSaved(void)
{
   boolean               bLocalStatus;
/*   uint8                 u8LocalNbWriteSaved; // dbg
   NVMSRV_tudtObjectList udtLocalCurrentObjectNb;

*/ //dbg
   bLocalStatus = TRUE;
/* // dbg
   udtLocalCurrentObjectNb = 0;
   while (udtLocalCurrentObjectNb < NVMSRV_udtVALID_OBJECTS_NUMBER)
   {
      if (  (NVMSRV_abWrite[udtLocalCurrentObjectNb] != FALSE)
         || (NVMSRV_abWritePending[udtLocalCurrentObjectNb] != FALSE)
         || (NVMSRV_abRefresh[udtLocalCurrentObjectNb] != FALSE) )
      {
         bLocalStatus            = FALSE;
         udtLocalCurrentObjectNb = NVMSRV_udtVALID_OBJECTS_NUMBER;
      }
      else
      {
         udtLocalCurrentObjectNb++;
      }
   }
   if (bLocalStatus == TRUE)
   {
      u8LocalNbWriteSaved = NVMSRV_u8SaveNbWrite();
      if (u8LocalNbWriteSaved != NVMSRV_u8OK)
      {
         bLocalStatus = FALSE;
      }
   }  // dbg */
   return(bLocalStatus);
}

/******************************************************************************/
/* !FuncName    : NVMSRV_bIsVirgin                                            */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
boolean NVMSRV_bIsVirgin(void)
{
   boolean bLocalStatus;
/* // dbg

   // bLocalStatus = DEVHAL_bCheckEmulCard(); // dbg
   if (  (NVMSRV_abDefault[NVMSRV_udtOBJ_TEST_EEPROM_1] != FALSE)
      && (NVMSRV_abDefault[NVMSRV_udtOBJ_TEST_EEPROM_2] != FALSE)
      && (NVMSRV_abDefault[NVMSRV_udtOBJ_TEST_EEPROM_3] != FALSE)
      && (  (NVMSRV_abDefault[NVMSRV_udtOBJ_PROD_8_TRIMS] == FALSE)
         || (bLocalStatus == TRUE) ) )
   {  // dbg */
      bLocalStatus = TRUE;
/*   } // dbg
   else
   {
      bLocalStatus = FALSE;
   }  // dbg */
   return(bLocalStatus);
}

/******************************************************************************/
/* !FuncName    : NVMSRV_bIsOk                                                */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
boolean NVMSRV_bIsOk(void)
{
   boolean bLocalStatus;
/* // dbg

   bLocalStatus = DEVHAL_bCheckEmulCard();
   if (bLocalStatus == TRUE)
   {
      bLocalStatus = TRUE;
   }
   else
   {
      if (  (NVMSRV_abDefault[NVMSRV_udtOBJ_TEST_EEPROM_1] != FALSE)
         && (NVMSRV_abDefault[NVMSRV_udtOBJ_TEST_EEPROM_2] != FALSE)
         && (NVMSRV_abDefault[NVMSRV_udtOBJ_TEST_EEPROM_3] != FALSE)
         && (NVMSRV_abDefault[NVMSRV_udtOBJ_PROD_8_TRIMS] != FALSE) )
      {
         bLocalStatus = FALSE;
      }
      else
      {  // dbg */
         bLocalStatus = TRUE;
      /*} // dbg
   }  // dbg */
   return(bLocalStatus);
}

/******************************************************************************/
/* !FuncName    : NVMSRV_vidCancelNbWrite                                     */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidCancelNbWrite(void)
{
}

/******************************************************************************/
/* !FuncName    : NVMSRV_u8WriteStatus                                        */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
uint8 NVMSRV_u8WriteStatus
(
   uint16 udtObject
)
{
   uint8 u8LocalStatus;

   u8LocalStatus = NVMSRV_u8GetStatus(udtObject);
   
   return(u8LocalStatus);
}

/******************************************************************************/
/* !FuncName    : NVMSRV_vidRazObjectList                                     */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidRazObjectList
(
)
{
}

/******************************************************************************/
/* !FuncName    : NVMSRV_vidRazObject                                         */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                          */
/******************************************************************************/
void NVMSRV_vidRazObject
(
)
{

}

#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"

/*------------------------------- end of file --------------------------------*/
