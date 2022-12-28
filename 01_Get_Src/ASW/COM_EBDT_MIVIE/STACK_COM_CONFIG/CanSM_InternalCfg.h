/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined CANSM_INTERNALCFG_H_)
#define CANSM_INTERNALCFG_H_
/*==================[includes]==============================================*/

#include <BswM_CanSM.h>        /* Basic Software Mode Manager */

/*==================[macros]================================================*/

/*------------------[Function-Like macros]-----------*/

/** \brief Indicate state changes to BswM */
#define BSWM_CANSM_CURRENTSTATE(nw, cs) \
  BswM_CanSM_CurrentState(nw, cs)

#endif /* (!defined CANSM_INTERNALCFG_H_) */
/*==================[end of file]===========================================*/
