
#ifndef _EOMGSL_004_TEV_FCT_H_
#define _EOMGSL_004_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
struct zd1a376d219976d28f7c639cc9ea12fcf{unsigned int 
z200e638cb93af591a6bdc9f35cd13398:1;unsigned int 
zabf0e01207f605b49148135708c35977:1;unsigned int 
z4a052598993b4333361aaeb65ec9fd0a:1;unsigned int 
zf32e303d35e04f9af4d6471a0a457517:1;unsigned int 
z7af7395280d171b6942072aee71dfd88:1;unsigned int 
zc5be4c5f2cc074fbafbef66b701b7a99:1;unsigned int 
zaf12c6b48bebb2dc6ab0af07b27a41a9:1;unsigned int 
zb4954c6223aeba6ffd725fe80a500782:1;};
#define EOMGSL_START_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean EOM_bSpcInjMod_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean EOM_bTWCHeatPha_out;extern AR_IF_GLOBAL_BOOLEAN 
Boolean EOM_bTranMod_out;
#define EOMGSL_STOP_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
extern Void EOMGsl_004_TEV_fct(Void);extern Void EOMGsl_004_TEV_ini(Void);extern
 Void EOMGsl_004_FctVarInit(Void);
#endif

