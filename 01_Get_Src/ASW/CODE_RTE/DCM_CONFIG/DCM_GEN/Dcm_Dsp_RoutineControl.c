
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dsp                                                     */
/* !Description     : Diagnostic services processing                          */
/*                                                                            */
/* !Module          : Dcm_Dsp_RoutineControl                                  */
/* !Description     : Routine Control automatically generated code            */
/*                                                                            */
/* !File            : Dcm_Dsp_RoutineControl.c                                */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DCM_CONFIG/DCM_GEN/Dcm_Dsp_Routi$*/
/* $Revision::   1.22     $$Author::   pbakabad       $$Date::   May 31 2013 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3450]: No Declaration Needed for the      */
/*              functions because they are static and referred to withen the  */
/*              file.                                                         */
/* PRQA S 3450 L2 */
/* !Deviation : inhibit MISRA rule [3132]: The automated configuration tool  */ 
/*              writes the array size directly in files. no manual editing in*/
/*              files required.                                              */
/* PRQA S 3132 L4 */

/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
/* !Deviation : inhibit MISRA rule [2211]: To simplify the automatic          */
/*              code generation                                               */
/* PRQA S 2211 L7 */
/* !Deviation : inhibit MISRA rule [2215]: To simplify the automatic          */
/*              code generation                                               */
/* PRQA S 2215 L7 */
#include "Std_Types.h"
#include "Dcm.h"
#include "Dcm_Internal.h"
/* PRQA L:L1 */
#include "Dcm_Cfg.h"
#include "Rte_Dcm.h"
    

/* !Deviation : Inhibit MISRA rule [0838]: macro used for performance.        */
/* PRQA S 3453 ++                                                             */

/* !Deviation : Inhibit MISRA rule [3456]: Parameter is needed to be evaluated
 *              more than once.                                               */
/* PRQA S 3456 ++                                                             */

#define u16SWAP_BYTES(u16Word)      \
  ((((u16Word) & 0x00FFU) << 8) |   \
   (((u16Word) & 0xFF00U) >> 8))


#define u32SWAP_BYTES(u32Word)            \
  ((((u32Word) & 0x000000FFUL) << 24) |   \
   (((u32Word) & 0x0000FF00UL) << 8)  |   \
   (((u32Word) & 0x00FF0000UL) >> 8)  |   \
   (((u32Word) & 0xFF000000UL) >> 24))

/* PRQA S 3456 --                                                             */
/* PRQA S 3453 --                                                             */

/******************************************************************************/
/* LOCAL FUNCTIONS DECLARATION                                                */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */


/* !Deviation : Inhibit MISRA rule [3206]: The same prototype is defined for  */
/*              all routines , but this routine doesn't have in/out parameters*/
/*              file.                                                         */
/* PRQA S 3206 L3 */

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)

        

/******************************************************************************/
/* Routine0                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine0Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC0Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[0];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine0Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine0Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC0Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[0];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine0Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine0ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC0RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[0];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine0ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine1                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine1Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC1Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[1];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine1Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine1Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC1Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[1];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine1Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine1ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC1RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[1];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine1ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine2                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine2Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC2Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[2];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine2Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine2Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC2Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[2];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine2Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine2ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC2RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[2];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine2ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine3                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine3Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC3Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[3];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine3Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine3Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC3Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[3];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine3Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine3ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC3RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[3];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine3ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine4                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine4Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC4Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[4];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine4Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine4Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC4Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[4];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine4Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine4ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC4RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[4];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine4ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine5                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine5Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC5Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[5];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine5Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine5Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC5Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[5];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine5Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine5ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC5RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[5];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine5ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine6                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine6Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC6Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[6];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine6Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine6Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC6Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[6];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine6Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine6ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC6RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[6];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine6ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine7                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine7Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC7Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[7];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine7Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine7Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC7Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[7];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine7Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine7ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC7RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[7];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine7ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine8                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine8Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC8Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[8];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine8Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine8Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC8Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[8];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine8Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine8ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC8RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[8];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine8ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine9                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine9Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC9Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[9];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine9Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine9Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC9Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[9];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine9Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine9ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC9RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[9];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine9ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine10                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine10Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC10Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[10];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine10Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine10Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC10Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[10];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine10Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine10ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC10RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[10];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine10ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine11                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine11Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC11Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[11];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine11Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine11Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC11Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[11];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine11Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine11ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC11RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[11];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine11ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine12                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine12Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC12Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[12];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine12Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine12Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC12Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[12];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine12Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine12ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC12RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[12];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine12ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine13                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine13Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC13Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[13];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine13Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine13Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC13Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[13];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine13Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine13ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC13RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[13];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine13ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine14                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine14Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC14Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  VAR(uint8,AUTOMATIC) au8DataOut2[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[14];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine14Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, au8DataOut2, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  

  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

      
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine14Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC14Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  VAR(uint8,AUTOMATIC) au8DataOut2[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[14];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine14Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus,&u8DataOut1, au8DataOut2, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  

  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U, 8U, 8U, bEndianConv);

  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine14ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC14RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[14];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine14ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine15                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine15Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC15Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[15];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine15Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine15Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC15Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[15];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine15Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine15ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC15RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[15];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine15ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine16                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine16Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(uint16,AUTOMATIC)u16DataIn2,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC16Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint16,AUTOMATIC) u16DataIn2;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 3)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[16];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u16DataIn2,1U, 0U, 16U , 16U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine16Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1,u16DataIn2, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine16Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC16Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[16];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine16Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine16ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC16RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[16];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine16ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine17                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine17Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC17Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  VAR(uint8,AUTOMATIC) au8DataOut2[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[17];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine17Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, au8DataOut2, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  

  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

      
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine17Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC17Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[17];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine17Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine17ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC17RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[17];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine17ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine18                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine18Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(uint8,AUTOMATIC)u8DataIn2,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC18Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint8,AUTOMATIC) u8DataIn2;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 2)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[18];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn2,1U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine18Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1,u8DataIn2, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine18Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC18Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[18];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine18Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine18ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC18RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[18];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine18ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine19                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine19Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC19Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[19];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine19Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine19Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC19Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[19];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine19Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine19ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC19RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[19];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine19ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine20                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine20Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC20Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[20];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine20Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine20Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC20Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[20];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine20Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine20ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC20RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[20];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine20ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine21                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine21Start)(
  VAR(uint32,AUTOMATIC) u32DataIn1,P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn2,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC21Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint32,AUTOMATIC) u32DataIn1;
VAR(uint8,AUTOMATIC) au8DataIn2[256];
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  VAR(uint8,AUTOMATIC) au8DataOut2[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength < 4)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[21];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u32DataIn1, 0U, 0U, 32U , 32U, bEndianConv,FALSE);
          
  u16Length = (*pu16DataLength * 8) - 32;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn2,4U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine21Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u32DataIn1,au8DataIn2, u8OpStatus, &u8DataOut1, au8DataOut2, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  

  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

      
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine21Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC21Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[21];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine21Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine21ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC21RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[21];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine21ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine22                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine22Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC22Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[22];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine22Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine22Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC22Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[22];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine22Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine22ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC22RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[22];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine22ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine23                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine23Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC23Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[23];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine23Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine23Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC23Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[23];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine23Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine23ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC23RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[23];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine23ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine24                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine24Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC24Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[24];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine24Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine24Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC24Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[24];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine24Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine24ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC24RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[24];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine24ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine25                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine25Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC25Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[25];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine25Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine25Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC25Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[25];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine25Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine25ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC25RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[25];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine25ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine26                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine26Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC26Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[26];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine26Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine26Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC26Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[26];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine26Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine26ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC26RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[26];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine26ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine27                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine27Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(uint16,AUTOMATIC)u16DataIn2,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC27Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint16,AUTOMATIC) u16DataIn2;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 3)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[27];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u16DataIn2,1U, 0U, 16U , 16U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine27Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1,u16DataIn2, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine27Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC27Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[27];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine27Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine27ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC27RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[27];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine27ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine28                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine28Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC28Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  VAR(uint8,AUTOMATIC) au8DataOut2[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[28];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine28Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, au8DataOut2, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  

  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

      
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine28Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC28Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[28];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine28Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine28ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC28RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[28];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine28ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine29                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine29Start)(P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC29Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataIn1[256];
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  VAR(uint8,AUTOMATIC) au8DataOut2[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[29];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  u16Length = (*pu16DataLength * 8) - 0;
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)au8DataIn1,0U, 0U, u16Length ,0, bEndianConv, FALSE); 
          
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine29Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(au8DataIn1, u8OpStatus, &u8DataOut1, au8DataOut2, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  

  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

      
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine29Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC29Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[29];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine29Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine29ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC29RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[29];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine29ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine30                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine30Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC30Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[30];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine30Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine30Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC30Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[30];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine30Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine30ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC30RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[30];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine30ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine31                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine31Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC31Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[31];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine31Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine31Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC31Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[31];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine31Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine31ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC31RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[31];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine31ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine32                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine32Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC32Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[32];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine32Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine32Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC32Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[32];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine32Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine32ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC32RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[32];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine32ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine33                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine33Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC33Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[33];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine33Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine33Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC33Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[33];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine33Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine33ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC33RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[33];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine33ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine34                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine34Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC34Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[34];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine34Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine34Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC34Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[34];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine34Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine34ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC34RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[34];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine34ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine35                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine35Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC35Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[35];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine35Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine35Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC35Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[35];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine35Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine35ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC35RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[35];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine35ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine36                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine36Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC36Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[36];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine36Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine36Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC36Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[36];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine36Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine36ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC36RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[36];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine36ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine37                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine37Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC37Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[37];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine37Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine37Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC37Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[37];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine37Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine37ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC37RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[37];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine37ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine38                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine38Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC38Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 1)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[38];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine38Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine38Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC38Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[38];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine38Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine38ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC38RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[38];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine38ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine39                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine39Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC39Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 1)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[39];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine39Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine39Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC39Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[39];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine39Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine39ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC39RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[39];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine39ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine40                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine40Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC40Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 1)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[40];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine40Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine40Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC40Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[40];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine40Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine40ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC40RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[40];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine40ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine41                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine41Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC41Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[41];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine41Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine41Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC41Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[41];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine41Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine41ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC41RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[41];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine41ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine42                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine42Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC42Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[42];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine42Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine42Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC42Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[42];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine42Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine42ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC42RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[42];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine42ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine43                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine43Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC43Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[43];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine43Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine43Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC43Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[43];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine43Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine43ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC43RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[43];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine43ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine44                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine44Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC44Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  
  VAR(uint16,AUTOMATIC)   u16Length;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[44];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine44Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine44Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC44Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) au8DataOut1[256];
  VAR(uint16,AUTOMATIC)   u16Length;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[44];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine44Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, au8DataOut1, &u16Length, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut1, pu8DataOut, 0U, 0U,  u16Length , 0, bEndianConv);
  *pu16DataLength = ((0 + u16Length) / 8);                                   
  if (((0 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine44ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut2,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC44RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

VAR(uint8,AUTOMATIC) u8DataOut1;
VAR(uint8,AUTOMATIC) au8DataOut2[256];

VAR(uint16,AUTOMATIC)   u16Length=0;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[44];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine44ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
      &u8DataOut1,
    
      au8DataOut2,
    
&u16Length,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

                
  DspInternal_vidInjectSignalIntoBuff((uint8*)au8DataOut2, pu8DataOut, 1U, 0U,  u16Length , 0, bEndianConv);                  
  *pu16DataLength = ((8 + u16Length) / 8);                                   
  if (((8 + u16Length) % 8) > 0)
  {
    (*pu16DataLength)++;
  }
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine45                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine45Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC45Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[45];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine45Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine45Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC45Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[45];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine45Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine45ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC45RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[45];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine45ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine46                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine46Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC46Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[46];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine46Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine46Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC46Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[46];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine46Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine46ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC46RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[46];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine46ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine47                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine47Start)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC47Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[47];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine47Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))( u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine47Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC47Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[47];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine47Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine47ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC47RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;

  VAR(uint8,AUTOMATIC) u8DataOut1;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[47];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine47ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
  &u8DataOut1,

pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);
          
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       


/******************************************************************************/
/* Routine48                                                                   */
/******************************************************************************/


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine48Start)(
  VAR(uint8,AUTOMATIC)u8DataIn1,
  VAR(uint16,AUTOMATIC)u16DataIn2,
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut1,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);
          
static FUNC(Std_ReturnType,DCM_CODE) u8RC48Start(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  VAR(uint8,AUTOMATIC) u8DataIn1;
  VAR(uint16,AUTOMATIC) u16DataIn2;
  VAR(uint8,AUTOMATIC) u8DataOut1;
  if (*pu16DataLength != 3)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */    
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[48];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
  
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u8DataIn1,0U, 0U, 8U , 8U, bEndianConv,FALSE); 
      
  DspInternal_vidExtractSignalFromBuff(pku8DataIn, (uint8*)&u16DataIn2,1U, 0U, 16U , 16U, bEndianConv,FALSE); 
      
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */ 
  u8FuncReturn = ((tpfu8Routine48Start)(LOC_pkstrRoutine->pfDcmDspStartRoutine))(u8DataIn1,u16DataIn2, u8OpStatus, &u8DataOut1, pu8ErrorCode);
  /* PRQA L:L1 */
  
  DspInternal_vidInjectSignalIntoBuff((uint8*)&u8DataOut1, pu8DataOut, 0U, 0U,  8U , 8U, bEndianConv);

  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 1; /* total number of bytes for all data outputs */
      

  }
  
  /* return from function */
  return u8FuncReturn;
}



typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine48Stop)(
  VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC48Stop(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;
  
  if (*pu16DataLength != 0)
  {
    u8FuncReturn = E_NOT_OK;
    *pu8ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {    
  

    
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[48];
  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L6 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L6 */
    
  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine48Stop)(LOC_pkstrRoutine->pfDcmDspStopRoutine))( u8OpStatus, pu8ErrorCode);
    
  /* PRQA L:L1 */
  
  /* PRQA L:L6 */
  /* PRQA L:L6 */
  
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
      

  }

  /* return from function */ 
  return u8FuncReturn;
}


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, tpfu8Routine48ReqRes)(
    VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus,

  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode
);

static FUNC(Std_ReturnType,DCM_CODE) u8RC48RequestResult(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) pu8ErrorCode)
{
  /* !Deviation : Inhibit MISRA rule [3203]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3203 L1 */  
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutine;
  /* PRQA L:L1 */
  VAR(Std_ReturnType,AUTOMATIC)                        u8FuncReturn;


          
  /*! get a pointer to Routine configuration */
  /* !Deviation : Inhibit MISRA rule [3199]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3199 L1 */  
  LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[48];
  /* PRQA L:L1 */


  /* !Deviation : Inhibit MISRA rule [313]: Casting is needed because the     */
  /*              prototype is unknown                                        */
  /* PRQA S 313 L1 */  
  u8FuncReturn = ((tpfu8Routine48ReqRes)(LOC_pkstrRoutine->pfDcmDspRequestResultsRoutine))(
  u8OpStatus,
  
pu8ErrorCode);

  /* PRQA L:L1 */

  /* !Deviation : Inhibit MISRA rule [310]: Casting to different object pointer*/
  /*              type is needed to convert the input buffer type              */
  /* PRQA S 310 L1 */ 
  /* !Deviation : Inhibit MISRA rule [3212]: Automatically generated for all   */
  /*              routines , it is left for simplicity of Config. Tool         */
  /*              implementation                                               */
  /* PRQA S 3212 L1 */
          
  *pu16DataLength = 0; /* total number of bytes for all data outputs */
                
          
  /* PRQA L:L1 */

  /* return from function */ 
  return u8FuncReturn;
}       



/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */
/*              for memory allocation and should be included several times.  */
/* PRQA S 5087,0838 L1 */
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* !Deviation : Inhibit MISRA rule [1334]: Pointer to function can't         */
/*              not have parameter definitions                               */
/* PRQA S 1334 L1 */ 
/* Start lookup table */ 
CONST(Dcm_tpfu8RoutineSubfunction,DCM_CFG_CONST)
   DspInternal_akpfeRoutineStart[DCM_u8NUM_OF_ROUTINES] = 
{
  
  &u8RC0Start,
  &u8RC1Start,
  &u8RC2Start,
  &u8RC3Start,
  &u8RC4Start,
  &u8RC5Start,
  &u8RC6Start,
  &u8RC7Start,
  &u8RC8Start,
  &u8RC9Start,
  &u8RC10Start,
  &u8RC11Start,
  &u8RC12Start,
  &u8RC13Start,
  &u8RC14Start,
  &u8RC15Start,
  &u8RC16Start,
  &u8RC17Start,
  &u8RC18Start,
  &u8RC19Start,
  &u8RC20Start,
  &u8RC21Start,
  &u8RC22Start,
  &u8RC23Start,
  &u8RC24Start,
  &u8RC25Start,
  &u8RC26Start,
  &u8RC27Start,
  &u8RC28Start,
  &u8RC29Start,
  &u8RC30Start,
  &u8RC31Start,
  &u8RC32Start,
  &u8RC33Start,
  &u8RC34Start,
  &u8RC35Start,
  &u8RC36Start,
  &u8RC37Start,
  &u8RC38Start,
  &u8RC39Start,
  &u8RC40Start,
  &u8RC41Start,
  &u8RC42Start,
  &u8RC43Start,
  &u8RC44Start,
  &u8RC45Start,
  &u8RC46Start,
  &u8RC47Start,
  &u8RC48Start
};


/* !Deviation : Inhibit MISRA rule [1334]: Pointer to function can't         */
/*              not have parameter definitions                               */
/* PRQA S 1334 L1 */ 
/* Stop lookup table */ 
CONST(Dcm_tpfu8RoutineSubfunction,DCM_CFG_CONST)
   DspInternal_akpfeRoutineStop[DCM_u8NUM_OF_ROUTINES] = 
{
  
  &u8RC0Stop,
  &u8RC1Stop,
  &u8RC2Stop,
  &u8RC3Stop,
  &u8RC4Stop,
  &u8RC5Stop,
  &u8RC6Stop,
  &u8RC7Stop,
  &u8RC8Stop,
  &u8RC9Stop,
  &u8RC10Stop,
  &u8RC11Stop,
  &u8RC12Stop,
  &u8RC13Stop,
  &u8RC14Stop,
  &u8RC15Stop,
  &u8RC16Stop,
  &u8RC17Stop,
  &u8RC18Stop,
  &u8RC19Stop,
  &u8RC20Stop,
  &u8RC21Stop,
  &u8RC22Stop,
  &u8RC23Stop,
  &u8RC24Stop,
  &u8RC25Stop,
  &u8RC26Stop,
  &u8RC27Stop,
  &u8RC28Stop,
  &u8RC29Stop,
  &u8RC30Stop,
  &u8RC31Stop,
  &u8RC32Stop,
  &u8RC33Stop,
  &u8RC34Stop,
  &u8RC35Stop,
  &u8RC36Stop,
  &u8RC37Stop,
  &u8RC38Stop,
  &u8RC39Stop,
  &u8RC40Stop,
  &u8RC41Stop,
  &u8RC42Stop,
  &u8RC43Stop,
  &u8RC44Stop,
  &u8RC45Stop,
  &u8RC46Stop,
  &u8RC47Stop,
  &u8RC48Stop
};

/* RequestResult lookup table */ 
CONST(Dcm_tpfu8ResultSubfunction,DCM_CFG_CONST)
   DspInternal_akpfeRoutineRequestResult[DCM_u8NUM_OF_ROUTINES] = 
{
  
  &u8RC0RequestResult,
  &u8RC1RequestResult,
  &u8RC2RequestResult,
  &u8RC3RequestResult,
  &u8RC4RequestResult,
  &u8RC5RequestResult,
  &u8RC6RequestResult,
  &u8RC7RequestResult,
  &u8RC8RequestResult,
  &u8RC9RequestResult,
  &u8RC10RequestResult,
  &u8RC11RequestResult,
  &u8RC12RequestResult,
  &u8RC13RequestResult,
  &u8RC14RequestResult,
  &u8RC15RequestResult,
  &u8RC16RequestResult,
  &u8RC17RequestResult,
  &u8RC18RequestResult,
  &u8RC19RequestResult,
  &u8RC20RequestResult,
  &u8RC21RequestResult,
  &u8RC22RequestResult,
  &u8RC23RequestResult,
  &u8RC24RequestResult,
  &u8RC25RequestResult,
  &u8RC26RequestResult,
  &u8RC27RequestResult,
  &u8RC28RequestResult,
  &u8RC29RequestResult,
  &u8RC30RequestResult,
  &u8RC31RequestResult,
  &u8RC32RequestResult,
  &u8RC33RequestResult,
  &u8RC34RequestResult,
  &u8RC35RequestResult,
  &u8RC36RequestResult,
  &u8RC37RequestResult,
  &u8RC38RequestResult,
  &u8RC39RequestResult,
  &u8RC40RequestResult,
  &u8RC41RequestResult,
  &u8RC42RequestResult,
  &u8RC43RequestResult,
  &u8RC44RequestResult,
  &u8RC45RequestResult,
  &u8RC46RequestResult,
  &u8RC47RequestResult,
  &u8RC48RequestResult
};

/* PRQA L:L1 */ 
#endif

/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */
/* PRQA L:L2 */
/* PRQA L:L4 */
/* PRQA L:L3 */
/* PRQA L:L7 */
/*-------------------------------- end of file -------------------------------*/
