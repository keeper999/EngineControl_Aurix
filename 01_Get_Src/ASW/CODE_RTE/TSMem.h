#if (!defined TSMEM_H)
#define TSMEM_H

#include "MEMSRV.h"

/*==================[type definitions]=======================================*/
/** \brief This macro maps to MEMSRV_vidCopyU8() */
#define TS_MemCpy(d,s,n) MEMSRV_vidCopyU8((d),(s),(n))

#endif /* if (!defined TSMEM_H) */