#ifndef BSWM_LINSM_H
#define BSWM_LINSM_H
#include "Std_Types.h"


#define LINSM_START_SEC_CODE
#include "LINSM_MemMap.h"

LOCAL_INLINE FUNC(void,BSWM_CODE) BswM_LinSM_CurrentState(NetworkHandleType Network,
                                        LinSM_ModeType CurrentState)
{
	COMPILER_UNUSED_PARAMETER(Network);
	COMPILER_UNUSED_PARAMETER(CurrentState);
}
										
                                        

LOCAL_INLINE FUNC(void,BSWM_CODE) BswM_LinSM_CurrentSchedule(
                                        NetworkHandleType Network,
                                        LinIf_SchHandleType CurrentSchedule)
{
 	COMPILER_UNUSED_PARAMETER(Network);
	COMPILER_UNUSED_PARAMETER(CurrentSchedule);
}

#define LINSM_STOP_SEC_CODE
#include "LINSM_MemMap.h"

#endif /* BSWM_LINSM_H */
