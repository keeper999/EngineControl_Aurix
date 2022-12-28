/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA_F07_Residual_scavenged_reaspired_mass               */
/*                                                                            */
/* !File            : AFA_F07_Residual_scavenged_reaspired_mass_private.h     */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AFA_F07_Residual_scavenged_reaspired_mass.mdl         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFA_F07_Residual_scavenged_reaspired_mass_private_h_
#define RTW_HEADER_AFA_F07_Residual_scavenged_reaspired_mass_private_h_
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: LookupTablenD_maxInde
   * Referenced by: '<S18>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxInde[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S28>/Lookup Table (n-D)'
   *   '<S29>/Lookup Table (n-D)'
   */
  UInt32 pooled11[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S42>/Lookup Table (n-D)'
   *   '<S43>/Lookup Table (n-D)'
   */
  UInt32 pooled12[2];

  /* Computed Parameter: LookupTablenD_maxIn_a
   * Referenced by: '<S56>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_a[2];

  /* Computed Parameter: LookupTablenD_maxIn_l
   * Referenced by: '<S79>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_l[2];

  /* Computed Parameter: LookupTablenD_maxIn_f
   * Referenced by: '<S102>/Lookup Table (n-D)'
   */
  UInt32 LookupTablenD_maxIn_f[2];
} ConstParam_AFA_F07_Residual_sca;

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare data in section "SEC_VAR_UNSPECIFIED" */

#define AFAT_START_SEC_CONST_UNSPECIFIED
#include "AFAT_MemMap.h"


/* Constant parameters (auto storage) */
extern const ConstParam_AFA_F07_Residual_sca AFA_F07_Residual_scaveng_ConstP;

#define AFAT_STOP_SEC_CONST_UNSPECIFIED
#include "AFAT_MemMap.h"




/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#endif                                 /* RTW_HEADER_AFA_F07_Residual_scavenged_reaspired_mass_private_h_ */

/*-------------------------------- end of file -------------------------------*/
