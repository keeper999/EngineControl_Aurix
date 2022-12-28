/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : VECTORINTF                                              */
/* !Description     : Interface to the Vector Flash Boot Loader               */
/*                                                                            */
/* !File            : VectorIntf.h                                            */
/* !Description     : Defines for the interface to the Vector FBL             */
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
 * %PID: P2017_BSW:0A157047.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

 /* This file is an extract of the Vector BSW\Fbl\fbl_def.h file */
 
#ifndef VECTORINF_H
#define VECTORINF_H

/* Basic configurations */
#include "v_cfg.h"

/* Configuration file for flash boot loader */
#include "fbl_cfg.h"

/* Basic type definitions */
#include "v_def.h"


/* Define to access the FBL header structure */
# define FblHeaderTable ((V_MEMROM1_FAR tFblHeader V_MEMROM2_FAR V_MEMROM3 *)(FBL_HEADER_ADDRESS))

/* Access macros for FblHeader elements for application */
# define GetFblMainVersion()     (FblHeaderTable->kFblMainVersion)
# define GetFblSubVersion()      (FblHeaderTable->kFblSubVersion)
# define GetFblReleaseVersion()  (FblHeaderTable->kFblBugFixVersion)

#  define FBL_START_PARAM       ((void *)0)
#   define CallFblStart(pParam)  (FblHeaderTable->FblStartFct)((pParam))

/* FblStart-parameter tCanInitTable is not used, define it to be void* to satisfy the compiler  */
typedef void* tCanInitTable;

typedef MEMORY_HUGE MEMORY_FAR void (*tFblStrtFct)( tCanInitTable* );

/* Header of the FBL */
typedef struct tagFblHeader
{
   vuint8       kFblMainVersion;
   vuint8       kFblSubVersion;
   vuint8       kFblBugFixVersion;
   vuint8       FblHeaderAlign1;     /**< Alignment to even addresses */
   tFblStrtFct  FblStartFct;
} tFblHeader;

#endif /* VECTORINF_H */

/*------------------------------- end of file --------------------------------*/
