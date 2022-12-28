/**
 * \file
 *
 * \brief Autosar Base
 *
 * This file contains the implementation of the Autosar
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined TS_ATOMIC_ASSIGN_H)
#define TS_ATOMIC_ASSIGN_H

/*==================[inclusions]=============================================*/

#include <TSAutosar_Cfg.h>

/*==================[macros]=================================================*/

#if (defined TS_AtomicAssignGeneric)
#error TS_AtomicAssignGeneric already defined
#endif

/** \brief Assigns an arbitrary entity \p from to \p to in an atomic fashion
 **
 ** This macro assigns the entity \p from (which can be of arbitrary size) to \p to
 ** in an atomic fashion
 **
 ** The parameters \p from and \p to have to be of a type that can be assigned via
 ** the C assignment operator.
 **
 ** \param[out] to    entity which is the destionation of the assignment
 ** \param[in]  from  entity which is the source of the assignment
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
#define TS_AtomicAssignGeneric(to, from) \
    do { \
        TS_IntStatusType savedIntStatus = TS_IntDisable();   \
        (to) = (from);                                       \
        TS_IntRestore(savedIntStatus);                       \
    } while(0)

/** \brief Assigns the 8 bit entity \p from to \p to in an atomic fashion
 **
 ** This macro assigns the 8 bit entity \p from to \p to in an atomic fashion
 **
 ** The parameters \p from and \p to thus have to be of type \p uint8 or \p sint8.
 **
 ** \param[out] to    8 bit entity which is the destionation of the assignment
 ** \param[in]  from  8 bit entity which is the source of the assignment
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
#if (!defined TS_AtomicAssign8)
#define TS_AtomicAssign8(to, from) \
    ((to) = (from))
#endif


/** \brief Assigns the 16 bit entity \p from to \p to in an atomic fashion
 **
 ** This macro assigns the 16 bit entity \p from to \p to in an atomic fashion
 **
 ** The parameters \p from and \p to thus have to be of type \p uint16 or \p sint16.
 **
 ** \param[out] to    16 bit entity which is the destionation of the assignment
 ** \param[in]  from  16 bit entity which is the source of the assignment
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
#if (!defined TS_AtomicAssign16)
#define TS_AtomicAssign16(to, from) \
    TS_AtomicAssignGeneric((to), (from))
#endif


/** \brief Assigns the 32 bit entity \p from to \p to in an atomic fashion
 **
 ** This macro assigns the 32 bit entity \p from to \p to in an atomic fashion
 **
 ** The parameters \p from and \p to thus have to be of type \p uint32 or \p sint32.
 **
 ** \param[out] to    32 bit entity which is the destionation of the assignment
 ** \param[in]  from  32 bit entity which is the source of the assignment
 **
 ** \remarks The parameters of this macro may be used in any way, especially
 **   they can be used more than once. They shall not contain side effects. */
#if (!defined TS_AtomicAssign32)
#define TS_AtomicAssign32(to, from) \
     TS_AtomicAssignGeneric((to), (from))
#endif

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

#endif /* if !defined( TS_ATOMIC_ASSIGN_H ) */
