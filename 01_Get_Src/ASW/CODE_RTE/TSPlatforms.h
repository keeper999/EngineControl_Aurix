#if (!defined TSPLATFORMS_H)
#define TSPLATFORMS_H

/**
 * \file
 *
 * \brief Autosar Platforms
 *
 * This file contains the implementation of the Autosar
 * module Platforms.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[macros]=================================================*/
 
#if (defined TS_IntDisable)
#error "TS_IntDisable already defined"
#endif

/** \brief Disables interrupts and returns previous state.
 **
 ** This macro disables all interrupts.
 ** The previous interrupt locking status is returned. */
#define TS_IntDisable() TS_IntDisableInternal()

#if (defined TS_IntRestore)
#error "TS_IntRestore already defined"
#endif

/** \brief Restores interrupt lock state
 **
 ** This macro restores the interrupt locking status to a state
 ** returned by a previous call to TS_IntDisable(). */
#define TS_IntRestore(s) TS_IntRestoreInternal(s)


#endif /* if (!defined TSPLATFORMS_H) */
