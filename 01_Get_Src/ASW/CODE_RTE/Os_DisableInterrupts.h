/*
 * This is Os_DisableInterrupts.h, auto-generated for:
 *   Project: P2017_ASW
 *   Target:  TriCoreHighTec
 *   Variant: TC29x
 *   Version: 5.0.2
 */

/*
 * Include this header in order to allow any configured interrupt to be
 * disabled or enabled
 */
#ifndef OS_DISABLEINTERRUPTS_H
#define OS_DISABLEINTERRUPTS_H

/**************************************************************************
**
** This file contains SFR descriptions for TC29x
** Generated at 2014-01-10 11:22:51 +0000
** from tc29x_um_v1.1p4_SFR_OPEN_MARKET.xml, UM_V1.1 supplied by Infineon
** Filter: ^SRC_, ^SCU_, ^STM\d?_, ^ASCLIN, ^P\d\d_, ^CPU\d?_, XBAR_
**
**************************************************************************/
#ifndef Os_TC29x_DEFS_H
#define Os_TC29x_DEFS_H
/* [MISRA 2004 Rule 18.4] Unions */ /*lint -save -e960 (range safe) */
typedef signed int signed_sfr_access_type;
typedef unsigned int unsigned_sfr_access_type;
#ifdef __TASKING__
typedef unsigned __sfrbit32 sfr_bitfield;
#else
typedef unsigned int sfr_bitfield;
#endif
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield MOD_REV : 8; /* Module Revision Number */
    /* const */ sfr_bitfield MOD_TYPE : 8; /* Module Type */
    /* const */ sfr_bitfield MOD_NUMBER : 16; /* Module Number Value */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_ID_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SCI0 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI1 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI2 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SCI4 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI5 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI6 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI7 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI8 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI9 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield SCI10 : 1; /* SCI Debug Trigger Event Status */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield SCID : 1; /* Default Slave Debug Trigger Event Status */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBSAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SCSCI0 : 1; /* Starvation Error from SCI0 Status */
     sfr_bitfield SCSCI1 : 1; /* Starvation Error from SCI1 Status */
     sfr_bitfield SCSCI2 : 1; /* Starvation Error from SCI2 Status */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SCSCI4 : 1; /* Starvation Error from SCI4 Status */
     sfr_bitfield SCSCI5 : 1; /* Starvation Error from SCI5 Status */
     sfr_bitfield SCSCI6 : 1; /* Starvation Error from SCI6 Status */
     sfr_bitfield SCSCI7 : 1; /* Starvation Error from SCI7 Status */
     sfr_bitfield SCSCI8 : 1; /* Starvation Error from SCI8 Status */
     sfr_bitfield SCSCI9 : 1; /* Starvation Error from SCI9 Status */
     sfr_bitfield SCSCI10 : 1; /* Starvation Error from SCI10 Status */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield SCSCID : 1; /* Starvation Error from Default Slave Status */
     sfr_bitfield PRSCI0 : 1; /* Protocol Error from SCI0 Status */
     sfr_bitfield PRSCI1 : 1; /* Protocol Error from SCI1 Status */
     sfr_bitfield PRSCI2 : 1; /* Protocol Error from SCI2 Status */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield PRSCI4 : 1; /* Protocol Error from SCI4 Status */
     sfr_bitfield PRSCI5 : 1; /* Protocol Error from SCI5 Status */
     sfr_bitfield PRSCI6 : 1; /* Protocol Error from SCI6 Status */
     sfr_bitfield PRSCI7 : 1; /* Protocol Error from SCI7 Status */
     sfr_bitfield PRSCI8 : 1; /* Protocol Error from SCI8 Status */
     sfr_bitfield PRSCI9 : 1; /* Protocol Error from SCI9 Status */
     sfr_bitfield PRSCI10 : 1; /* Protocol Error from SCI10 Status */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield PRSCID : 1; /* Protocol Error from Default Slave Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_INTSAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield IDCSCI0 : 1; /* Transaction ID Error from SCI0 Status */
     sfr_bitfield IDCSCI1 : 1; /* Transaction ID Error from SCI1 Status */
     sfr_bitfield IDCSCI2 : 1; /* Transaction ID Error from SCI2 Status */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield IDSCI4 : 1; /* Transaction ID Error from SCI4 Status */
     sfr_bitfield IDSCI5 : 1; /* Transaction ID Error from SCI5 Status */
     sfr_bitfield IDSCI6 : 1; /* Transaction ID Error from SCI6 Status */
     sfr_bitfield IDSCI7 : 1; /* Transaction ID Error from SCI7 Status */
     sfr_bitfield IDSCI8 : 1; /* Transaction ID Error from SCI8 Status */
     sfr_bitfield IDSCI9 : 1; /* Transaction ID Error from SCI9 Status */
     sfr_bitfield IDSCI10 : 1; /* Transaction ID Error from SCI10 Status */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield IDSCID : 1; /* Transaction ID Error from Default Slave Status */
     sfr_bitfield IDMCI0 : 1; /* Transaction ID Error from MCI0 Status */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield IDMCI4 : 1; /* Transaction ID Error from MCI4 Status */
     sfr_bitfield IDMCI5 : 1; /* Transaction ID Error from MCI5 Status */
     sfr_bitfield IDMCI6 : 1; /* Transaction ID Error from MCI6 Status */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield IDMCI8 : 1; /* Transaction ID Error from MCI8 Status */
     sfr_bitfield IDMCI9 : 1; /* Transaction ID Error from MCI9 Status */
     sfr_bitfield IDMCI10 : 1; /* Transaction ID Error from MCI10 Status */
     sfr_bitfield IDMCI11 : 1; /* Transaction ID Error from MCI11 Status */
     sfr_bitfield IDMCI12 : 1; /* Transaction ID Error from MCI12 Status */
     sfr_bitfield IDMCI13 : 1; /* Transaction ID Error from MCI13 Status */
     sfr_bitfield  : 2; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_IDINTSAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ENSCI0 : 1; /* Enable ID Error from SCI0 */
     sfr_bitfield ENSCI1 : 1; /* Enable ID Error from SCI1 */
     sfr_bitfield ENSCI2 : 1; /* Enable ID Error from SCI2 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield ENSCI4 : 1; /* Enable ID Error from SCI4 */
     sfr_bitfield ENSCI5 : 1; /* Enable ID Error from SCI5 */
     sfr_bitfield ENSCI6 : 1; /* Enable ID Error from SCI6 */
     sfr_bitfield ENSCI7 : 1; /* Enable ID Error from SCI7 */
     sfr_bitfield ENSCI8 : 1; /* Enable ID Error from SCI8 */
     sfr_bitfield ENSCI9 : 1; /* Enable ID Error from SCI9 */
     sfr_bitfield ENSCI10 : 1; /* Enable ID Error from SCI10 */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield ENSCID : 1; /* Enable ID Error from Default Slave */
     sfr_bitfield ENMCI0 : 1; /* Enable ID Error from MCI0 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield ENMCI4 : 1; /* Enable ID Error from MCI4 */
     sfr_bitfield ENMCI5 : 1; /* Enable ID Error from MCI5 */
     sfr_bitfield ENMCI6 : 1; /* Enable ID Error from MCI6 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield ENMCI8 : 1; /* Enable ID Error from MCI8 */
     sfr_bitfield ENMCI9 : 1; /* Enable ID Error from MCI9 */
     sfr_bitfield ENMCI10 : 1; /* Enable ID Error from MCI10 */
     sfr_bitfield ENMCI11 : 1; /* Enable ID Error from MCI11 */
     sfr_bitfield ENMCI12 : 1; /* Enable ID Error from MCI12 */
     sfr_bitfield ENMCI13 : 1; /* Enable ID Error from MCI13 */
     sfr_bitfield  : 2; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_IDINTEN_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield WFWD : 1; /* Wait for FPI Write Data */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield FREQDISF : 1; /* Disable Fast Request Feature for FPI to SRI Transactions */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield NODELTR : 1; /* Control Signal for deferred transactions */
     sfr_bitfield NORMW : 1; /* Control Signal for deferred transactions */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield MAX_WS : 7; /* FPI-Bus Wait State Retry Ratio */
     sfr_bitfield  : 12; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_EXTCOND_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PRERREN : 1; /* SRI Protocol Error Enable */
     sfr_bitfield SCERREN : 1; /* SRI Starvation Error Enable */
     sfr_bitfield SETPRINT : 1; /* Set SRI Protocol Interrupt */
     sfr_bitfield SETSCINT : 1; /* Set SRI Starvation Interrupt */
     sfr_bitfield INTACK : 1; /* Interrupt Acknowledge */
     sfr_bitfield  : 15; /* reserved */
     sfr_bitfield SPC : 12; /* Starvation Protection Counter Reload Value */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_ARBCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield MASTER8 : 3; /* Master 8 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER9 : 3; /* Master 9 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER10 : 3; /* Master 10 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER11 : 3; /* Master 11 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER12 : 3; /* Master 12 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER13 : 3; /* Master 13 Priority */
     sfr_bitfield  : 9; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_PRIOH0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield MASTER0 : 3; /* Master 0 Priority */
     sfr_bitfield  : 13; /* reserved */
     sfr_bitfield MASTER4 : 3; /* Master 4 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER5 : 3; /* Master 5 Priority */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MASTER6 : 3; /* Master 6 Priority */
     sfr_bitfield  : 5; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_PRIOLD_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield ADDR : 32; /* Transaction Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_ERRADDRD_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RD : 1; /* Read Indication Status */
    /* const */ sfr_bitfield WR : 1; /* Write Indication Status */
    /* const */ sfr_bitfield SVM : 1; /* Supervisor Mode Indication Status */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield OPC : 4; /* Operation Code */
    /* const */ sfr_bitfield TR_ID : 8; /* Transaction ID */
    /* const */ sfr_bitfield ADDR_ECC : 8; /* SRI Address Phase Error Detection Information */
    /* const */ sfr_bitfield MCI_SBS : 8; /* MCI Sideband Signals [7:0] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_ERR0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield DBEN : 1; /* Status of OCDS Enable Signal */
    /* const */ sfr_bitfield DBSAT : 1; /* Debug (OCDS) Trigger Status */
     sfr_bitfield REARM : 1; /* Rearm Debug (OCDS) Trigger */
     sfr_bitfield SETDBEVT : 1; /* Set Debug Event */
     sfr_bitfield  : 12; /* reserved */
     sfr_bitfield RDEN : 1; /* Read Trigger Enable */
     sfr_bitfield WREN : 1; /* Write Trigger Enable */
     sfr_bitfield SVMEN : 1; /* SVM Trigger Enable */
     sfr_bitfield ADDEN : 1; /* Address Trigger Enable */
     sfr_bitfield ERREN : 1; /* Error Trigger Enable */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield MASEN : 1; /* Master Trigger Enable */
     sfr_bitfield MASTER : 6; /* Master TAG ID Trigger Selector */
     sfr_bitfield  : 2; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 30; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADDD_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS_23 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield ADDRESS_27 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 3; /* Reserved */
     sfr_bitfield ADDRESS_31 : 1; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS_23 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield ADDRESS_27 : 2; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 2; /* Reserved */
     sfr_bitfield ADDRESS_31 : 1; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS_23 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield ADDRESS_27 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 1; /* Reserved */
     sfr_bitfield ADDRESS_29 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_30 : 1; /* Reserved */
     sfr_bitfield ADDRESS_31 : 1; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 29; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS0 : 25; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE0 : 1; /* Reserved */
     sfr_bitfield ADDRESS1 : 3; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE1 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD6_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS0 : 19; /* Debug Address Boundary */
     sfr_bitfield  : 8; /* reserved */
     sfr_bitfield ADDRESS1 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield ONE : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD7_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS0 : 19; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE0 : 1; /* Reserved */
     sfr_bitfield  : 7; /* reserved */
     sfr_bitfield ADDRESS1 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield ONE1 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield ONE : 1; /* Reserved */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield ADDRESS_29 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield ONE_31 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD9_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 2; /* Reserved */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield ADDRESS_29 : 1; /* Debug Address Boundary */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield ONE_31 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBADD10_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ADDRESS : 32; /* Debug Address Mask Register */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBMADDD_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 2; /* Reserved */
     sfr_bitfield ADDRESS_23 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_24 : 3; /* Reserved */
     sfr_bitfield ADDRESS_27 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_28 : 3; /* Reserved */
     sfr_bitfield ADDRESS_31 : 1; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBMADD0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 2; /* Reserved */
     sfr_bitfield ADDRESS_23 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_24 : 3; /* Reserved */
     sfr_bitfield ADDRESS_27 : 2; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_29 : 2; /* Reserved */
     sfr_bitfield ADDRESS_31 : 1; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBMADD1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 2; /* Reserved */
     sfr_bitfield ADDRESS_23 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_24 : 3; /* Reserved */
     sfr_bitfield ADDRESS_27 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_28 : 1; /* Reserved */
     sfr_bitfield ADDRESS_29 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_30 : 1; /* Reserved */
     sfr_bitfield ADDRESS_31 : 1; /* Debug Address Boundary */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBMADD2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 25; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 1; /* Reserved */
     sfr_bitfield ADDRESS_28 : 3; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_31 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBMADD6_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ADDRESS : 19; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE : 8; /* Reserved */
     sfr_bitfield ADDRESS_29 : 1; /* Debug Address Boundary */
    /* const */ sfr_bitfield ONE_30 : 2; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_DBMADD7_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EN0 : 1; /* Access Enable for Master TAG ID 0 */
     sfr_bitfield EN1 : 1; /* Access Enable for Master TAG ID 1 */
     sfr_bitfield EN2 : 1; /* Access Enable for Master TAG ID 2 */
     sfr_bitfield EN3 : 1; /* Access Enable for Master TAG ID 3 */
     sfr_bitfield EN4 : 1; /* Access Enable for Master TAG ID 4 */
     sfr_bitfield EN5 : 1; /* Access Enable for Master TAG ID 5 */
     sfr_bitfield EN6 : 1; /* Access Enable for Master TAG ID 6 */
     sfr_bitfield EN7 : 1; /* Access Enable for Master TAG ID 7 */
     sfr_bitfield EN8 : 1; /* Access Enable for Master TAG ID 8 */
     sfr_bitfield EN9 : 1; /* Access Enable for Master TAG ID 9 */
     sfr_bitfield EN10 : 1; /* Access Enable for Master TAG ID 10 */
     sfr_bitfield EN11 : 1; /* Access Enable for Master TAG ID 11 */
     sfr_bitfield EN12 : 1; /* Access Enable for Master TAG ID 12 */
     sfr_bitfield EN13 : 1; /* Access Enable for Master TAG ID 13 */
     sfr_bitfield EN14 : 1; /* Access Enable for Master TAG ID 14 */
     sfr_bitfield EN15 : 1; /* Access Enable for Master TAG ID 15 */
     sfr_bitfield EN16 : 1; /* Access Enable for Master TAG ID 16 */
     sfr_bitfield EN17 : 1; /* Access Enable for Master TAG ID 17 */
     sfr_bitfield EN18 : 1; /* Access Enable for Master TAG ID 18 */
     sfr_bitfield EN19 : 1; /* Access Enable for Master TAG ID 19 */
     sfr_bitfield EN20 : 1; /* Access Enable for Master TAG ID 20 */
     sfr_bitfield EN21 : 1; /* Access Enable for Master TAG ID 21 */
     sfr_bitfield EN22 : 1; /* Access Enable for Master TAG ID 22 */
     sfr_bitfield EN23 : 1; /* Access Enable for Master TAG ID 23 */
     sfr_bitfield EN24 : 1; /* Access Enable for Master TAG ID 24 */
     sfr_bitfield EN25 : 1; /* Access Enable for Master TAG ID 25 */
     sfr_bitfield EN26 : 1; /* Access Enable for Master TAG ID 26 */
     sfr_bitfield EN27 : 1; /* Access Enable for Master TAG ID 27 */
     sfr_bitfield EN28 : 1; /* Access Enable for Master TAG ID 28 */
     sfr_bitfield EN29 : 1; /* Access Enable for Master TAG ID 29 */
     sfr_bitfield EN30 : 1; /* Access Enable for Master TAG ID 30 */
     sfr_bitfield EN31 : 1; /* Access Enable for Master TAG ID 31 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_ACCEN0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 32; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} XBAR_ACCEN1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ASI : 5; /* Address Space Identifier */
    /* const */ sfr_bitfield RES : 27; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_TASK_ASI_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DAC : 10; /* Data Access Cacheability Segments 9H-0H */
    /* const */ sfr_bitfield DAC_10 : 1; /* Data Access Cacheability Segments AH */
     sfr_bitfield DAC_11 : 2; /* Data Access Cacheability Segments CH,BH */
    /* const */ sfr_bitfield DAC_13 : 3; /* Data Access Cacheability Segments FH,EH,DH */
    /* const */ sfr_bitfield RES : 16; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PMA0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CAC : 10; /* Code Access Cacheability Segments 9H-0H */
    /* const */ sfr_bitfield CAC_10 : 1; /* Code Access Cacheability Segments AH */
     sfr_bitfield CAC_11 : 1; /* Code Access Cacheability Segments BH */
    /* const */ sfr_bitfield CAC_12 : 1; /* Code Access Cacheability Segments CH */
     sfr_bitfield CAC_13 : 1; /* Code Access Cacheability Segments DH */
    /* const */ sfr_bitfield CAC_14 : 2; /* Code Access Cacheability Segments FH,EH */
    /* const */ sfr_bitfield RES : 16; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PMA1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield PSI : 16; /* Peripheral Space Identifier Segments FH-0H */
    /* const */ sfr_bitfield RES : 16; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PMA2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PC : 1; /* Instruction Cache Memory SIST Mode Access Control */
    /* const */ sfr_bitfield RES : 1; /* Reserved */
     sfr_bitfield PT : 1; /* Program Tag Memory SIST Mode Access Control */
    /* const */ sfr_bitfield RES_3 : 5; /* Reserved */
     sfr_bitfield DC : 1; /* Data Cache Memory SIST Mode Access Control */
    /* const */ sfr_bitfield RES_9 : 1; /* Reserved */
     sfr_bitfield DT : 1; /* Data Tag Memory SIST Mode Access Control */
    /* const */ sfr_bitfield RES_11 : 5; /* Reserved */
    /* const */ sfr_bitfield RES_16 : 8; /* Reserved */
     sfr_bitfield IODT : 1; /* In-Order Data Transactions */
    /* const */ sfr_bitfield RES_25 : 7; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SMACON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield TA : 32; /* Transaction Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DIEAR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield IED : 1; /* Integrity Error Detected */
    /* const */ sfr_bitfield IE_T : 1; /* Integrity Error - Tag Memory */
    /* const */ sfr_bitfield IE_C : 1; /* Integrity Error - Cache Memory */
    /* const */ sfr_bitfield IE_S : 1; /* Integrity Error - Scratchpad Memory */
    /* const */ sfr_bitfield IE_BI : 1; /* Integrity Error - Bus Integrity */
    /* const */ sfr_bitfield E_INFO : 6; /* Error Information */
    /* const */ sfr_bitfield IE_DUAL : 1; /* Dual Bit Error Detected */
    /* const */ sfr_bitfield IE_SP : 1; /* Safety Protection Error Detected */
    /* const */ sfr_bitfield IE_BS : 1; /* Bus Slave Access Indicator */
    /* const */ sfr_bitfield RES : 18; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DIETR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PCINV : 1; /* Program Cache Invalidate */
     sfr_bitfield PBINV : 1; /* Program Buffer Invalidate */
    /* const */ sfr_bitfield RES : 30; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PCON1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield PCACHE_SZE : 16; /* Program Cache Size (ICACHE) in KBytes */
    /* const */ sfr_bitfield PSCRATCH_SZE : 16; /* Program Scratch Size in KBytes */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PCON2_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 1; /* Reserved */
     sfr_bitfield PCBYP : 1; /* Program Cache Bypass */
    /* const */ sfr_bitfield RES_2 : 30; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield FRE : 1; /* Fetch Range Error */
    /* const */ sfr_bitfield RES : 1; /* Reserved */
     sfr_bitfield FBE : 1; /* Fetch Bus Error */
    /* const */ sfr_bitfield RES_3 : 9; /* Reserved */
     sfr_bitfield FPE : 1; /* Fetch Peripheral Error */
    /* const */ sfr_bitfield RES_13 : 1; /* Reserved */
     sfr_bitfield FME : 1; /* Fetch MSIST Error */
    /* const */ sfr_bitfield RES_15 : 17; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PSTR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 1; /* Reserved */
     sfr_bitfield DCBYP : 1; /* Data Cache Bypass */
    /* const */ sfr_bitfield RES_2 : 30; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DCON0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield DCACHE_SZE : 16; /* Data Cache Size */
    /* const */ sfr_bitfield DSCRATCH_SZE : 16; /* Data Scratch Size */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DCON2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SRE : 1; /* Scratch Range Error */
     sfr_bitfield GAE : 1; /* Global Address Error */
     sfr_bitfield LBE : 1; /* Load Bus Error */
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield CRE : 1; /* Cache Refill Error */
    /* const */ sfr_bitfield RES_7 : 7; /* Reserved */
     sfr_bitfield DTME : 1; /* DTAG MSIST Error */
     sfr_bitfield LOE : 1; /* Load Overlay Error */
     sfr_bitfield SDE : 1; /* Segment Difference Error */
     sfr_bitfield SCE : 1; /* Segment Crossing Error */
     sfr_bitfield CAC : 1; /* CSFR Access Error */
     sfr_bitfield MPE : 1; /* Memory Protection Error */
     sfr_bitfield CLE : 1; /* Context Location Error */
    /* const */ sfr_bitfield RES_21 : 3; /* Reserved */
     sfr_bitfield ALN : 1; /* Alignment Error */
    /* const */ sfr_bitfield RES_25 : 7; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DSTR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield SBE : 1; /* Store Bus Error */
    /* const */ sfr_bitfield RES_4 : 5; /* Reserved */
     sfr_bitfield CWE : 1; /* Cache Writeback Error */
     sfr_bitfield CFE : 1; /* Cache Flush Error */
    /* const */ sfr_bitfield RES_11 : 3; /* Reserved */
     sfr_bitfield SOE : 1; /* Store Overlay Error */
     sfr_bitfield SME : 1; /* Store MIST Error */
    /* const */ sfr_bitfield RES_16 : 16; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DATR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield ERROR_ADDRESS : 32; /* Error Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DEADD_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield IED : 1; /* Integrity Error Detected */
    /* const */ sfr_bitfield IE_T : 1; /* Integrity Error - Tag Memory */
    /* const */ sfr_bitfield IE_C : 1; /* Integrity Error - Cache Memory */
    /* const */ sfr_bitfield IE_S : 1; /* Integrity Error - Scratchpad Memory */
    /* const */ sfr_bitfield IE_BI : 1; /* Integrity Error - Bus Interface */
    /* const */ sfr_bitfield E_INFO : 6; /* Error Information */
    /* const */ sfr_bitfield IE_DUAL : 1; /* Integrity Error - Dual Error Detected */
    /* const */ sfr_bitfield IE_SP : 1; /* Safety Protection Error Detected */
    /* const */ sfr_bitfield IE_BS : 1; /* Bus Slave Access Indicator */
    /* const */ sfr_bitfield RES : 18; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PIETR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield RM : 1; /* Rounding Mode Compatibility */
     sfr_bitfield SP : 1; /* SYSCON Safety Protection Mode Compatibility */
    /* const */ sfr_bitfield RES_5 : 27; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_COMPAT_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield TST : 1; /* Trap Status */
     sfr_bitfield TCL : 1; /* Trap Clear */
    /* const */ sfr_bitfield RES : 6; /* Reserved */
    /* const */ sfr_bitfield RM : 2; /* Captured Rounding Mode */
    /* const */ sfr_bitfield RES_10 : 8; /* Reserved */
     sfr_bitfield FXE : 1; /* FX Trap Enable */
     sfr_bitfield FUE : 1; /* FU Trap Enable */
     sfr_bitfield FZE : 1; /* FZ Trap Enable */
     sfr_bitfield FVE : 1; /* FV Trap Enable */
     sfr_bitfield FIE : 1; /* FI Trap Enable */
    /* const */ sfr_bitfield RES_23 : 3; /* Reserved */
    /* const */ sfr_bitfield FX : 1; /* Captured FX */
    /* const */ sfr_bitfield FU : 1; /* Captured FU */
    /* const */ sfr_bitfield FZ : 1; /* Captured FZ */
    /* const */ sfr_bitfield FV : 1; /* Captured FV */
    /* const */ sfr_bitfield FI : 1; /* Captured FI */
    /* const */ sfr_bitfield RES_31 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FPU_TRAP_CON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield PC : 32; /* Captured Program Counter */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FPU_TRAP_PC_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield OPC : 8; /* Captured Opcode */
    /* const */ sfr_bitfield FMT : 1; /* Captured Instruction Format */
    /* const */ sfr_bitfield RES : 7; /* Reserved */
    /* const */ sfr_bitfield DREG : 4; /* Captured Destination Register */
    /* const */ sfr_bitfield RES_20 : 12; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FPU_TRAP_OPC_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield SRC1 : 32; /* Captured SRC1 Operand */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FPU_TRAP_SRC1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield SRC2 : 32; /* Captured SRC2 Operand */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FPU_TRAP_SRC2_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield SRC3 : 32; /* Captured SRC3 Operand */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FPU_TRAP_SRC3_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield LOWBND : 29; /* DPRy Lower Boundary Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DPR0_L_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield UPPBND : 29; /* DPRy Upper Boundary Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DPR0_U_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield LOWBND : 29; /* CPRy Lower Boundary Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CPR0_L_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 3; /* Reserved */
     sfr_bitfield UPPBND : 29; /* CPR0_m Upper Boundary Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CPR0_U_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield RE : 16; /* Read Enable Range Select */
    /* const */ sfr_bitfield RES : 16; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DPRE_0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield WE : 16; /* Write Enable Range Select */
    /* const */ sfr_bitfield RES : 16; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DPWE_0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield XE : 8; /* Execute Enable Range select */
    /* const */ sfr_bitfield RES : 24; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CPXE_0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield Timer : 32; /* Temporal Protection Timer */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_TPS_TIMER0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield TEXP0 : 1; /* Timer0 Expired Flag */
    /* const */ sfr_bitfield TEXP1 : 1; /* Timer1 Expired Flag */
    /* const */ sfr_bitfield TEXP2 : 1; /* Timer1 Expired Flag */
    /* const */ sfr_bitfield RES : 13; /* Reserved */
    /* const */ sfr_bitfield TTRAP : 1; /* Temporal Protection Trap */
    /* const */ sfr_bitfield RES_17 : 15; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_TPS_CON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield DE : 1; /* Debug Enable */
     sfr_bitfield HALT : 2; /* CPU Halt Request / Status Field */
    /* const */ sfr_bitfield SIH : 1; /* Suspend-in Halt */
     sfr_bitfield SUSP : 1; /* Current State of the Core Suspend-Out Signal */
    /* const */ sfr_bitfield RES : 1; /* Reserved */
    /* const */ sfr_bitfield PREVSUSP : 1; /* Previous State of Core Suspend-Out Signal */
     sfr_bitfield PEVT : 1; /* Posted Event */
    /* const */ sfr_bitfield EVTSRC : 5; /* Event Source */
    /* const */ sfr_bitfield RES_13 : 19; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DBGSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EVTA : 3; /* Event Associated */
     sfr_bitfield BBM : 1; /* Break Before Make (BBM) or Break After Make (BAM) Selection */
     sfr_bitfield BOD : 1; /* Breakout Disable */
     sfr_bitfield SUSP : 1; /* CDC Suspend-Out Signal State */
     sfr_bitfield CNT : 2; /* Counter */
    /* const */ sfr_bitfield RES : 24; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_EXEVT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EVTA : 3; /* Event Associated */
     sfr_bitfield BBM : 1; /* Break Before Make (BBM) or Break After Make (BAM) Selection */
     sfr_bitfield BOD : 1; /* Breakout Disable */
     sfr_bitfield SUSP : 1; /* CDC Suspend-Out Signal State */
     sfr_bitfield CNT : 2; /* Counter */
    /* const */ sfr_bitfield RES : 4; /* Reserved */
     sfr_bitfield TYP : 1; /* Input Selection */
     sfr_bitfield RNG : 1; /* Compare Type */
    /* const */ sfr_bitfield RES_14 : 1; /* Reserved */
     sfr_bitfield ASI_EN : 1; /* Enable ASI Comparison */
     sfr_bitfield ASI : 5; /* Address Space Identifier */
    /* const */ sfr_bitfield RES_21 : 6; /* Reserved */
     sfr_bitfield AST : 1; /* Address Store */
     sfr_bitfield ALD : 1; /* Address Load */
    /* const */ sfr_bitfield RES_29 : 3; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_TR0EVT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ADDR : 32; /* Comparison Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_TR0ADR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield T0 : 1; /* Trigger-0 */
    /* const */ sfr_bitfield T1 : 1; /* Trigger-1 */
    /* const */ sfr_bitfield T2 : 1; /* Trigger-2 */
    /* const */ sfr_bitfield T3 : 1; /* Trigger-3 */
    /* const */ sfr_bitfield T4 : 1; /* Trigger-4 */
    /* const */ sfr_bitfield T5 : 1; /* Trigger-5 */
    /* const */ sfr_bitfield T6 : 1; /* Trigger-6 */
    /* const */ sfr_bitfield T7 : 1; /* Trigger-7 */
    /* const */ sfr_bitfield RES : 24; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_TRIG_ACC_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 1; /* Reserved */
     sfr_bitfield DMSValue : 31; /* Debug Monitor Start Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DMS_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 6; /* Reserved */
     sfr_bitfield DCXValue : 26; /* Debug Context Save Area Pointer */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DCX_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DTA : 1; /* Debug Trap Active Bit */
    /* const */ sfr_bitfield RES : 31; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_DBGTCR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CM : 1; /* Counter Mode */
     sfr_bitfield CE : 1; /* Count Enable */
     sfr_bitfield M1 : 3; /* M1CNT Configuration */
     sfr_bitfield M2 : 3; /* M2CNT Configuration */
     sfr_bitfield M3 : 3; /* M3CNT Configuration */
    /* const */ sfr_bitfield RES : 21; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CCTRL_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CountValue : 31; /* Count Value */
     sfr_bitfield SOvf : 1; /* Sticky Overflow Bit */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CCNT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PCXO : 16; /* Previous Context Pointer Offset Field */
     sfr_bitfield PCXS : 4; /* Previous Context Pointer Segment Address */
     sfr_bitfield UL : 1; /* Upper or Lower Context Tag */
     sfr_bitfield PIE : 1; /* Previous Interrupt Enable */
     sfr_bitfield PCPN : 10; /* Previous CPU Priority Number */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PCXI_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CDC : 7; /* Call Depth Counter */
     sfr_bitfield CDE : 1; /* Call Depth Count Enable */
     sfr_bitfield GW : 1; /* Global Address Register Write Permission */
     sfr_bitfield IS : 1; /* Interrupt Stack Control */
     sfr_bitfield IO : 2; /* Access Privilege Level Control (I/O Privilege) */
     sfr_bitfield PRS : 2; /* Protection Register Set */
     sfr_bitfield S : 1; /* Safe Task Identifier */
    /* const */ sfr_bitfield RES : 12; /* Reserved */
     sfr_bitfield SAV : 1; /* Sticky Advance Overflow Flag */
     sfr_bitfield AV : 1; /* Advance Overflow Flag */
     sfr_bitfield SV : 1; /* Sticky Overflow Flag */
     sfr_bitfield V : 1; /* Overflow Flag */
     sfr_bitfield C : 1; /* Carry Flag */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PSW_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 1; /* Reserved */
    /* const */ sfr_bitfield PC : 31; /* Program Counter */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_PC_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield FCDSF : 1; /* Free Context List Depleted Sticky Flag */
     sfr_bitfield PROTEN : 1; /* Memory Protection Enable */
     sfr_bitfield TPROTEN : 1; /* Temporal Protection Enable */
     sfr_bitfield IS : 1; /* Initial State */
     sfr_bitfield IT : 1; /* Initial State */
    /* const */ sfr_bitfield RES : 27; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SYSCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CORE_ID : 3; /* Core Identification Number */
    /* const */ sfr_bitfield RES : 29; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CORE_ID_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield MOD_REV : 8; /* Revision Number */
    /* const */ sfr_bitfield MOD_32B : 8; /* 32-Bit Module Enable */
    /* const */ sfr_bitfield MOD : 16; /* Module Identification Number */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CPU_ID_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield CID : 3; /* Customer ID */
    /* const */ sfr_bitfield RES : 29; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_CUS_ID_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield VSS : 1; /* Vector Spacing Select */
     sfr_bitfield BIV : 31; /* Base Address of Interrupt Vector Table */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_BIV_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 1; /* Reserved */
     sfr_bitfield BTV : 31; /* Base Address of Trap Vector Table */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_BTV_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ISP : 32; /* Interrupt Stack Pointer */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_ISP_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CCPN : 10; /* Current CPU Priority Number */
    /* const */ sfr_bitfield RES : 5; /* Reserved */
     sfr_bitfield IE : 1; /* Global Interrupt Enable Bit */
    /* const */ sfr_bitfield PIPN : 10; /* Pending Interrupt Priority Number */
    /* const */ sfr_bitfield RES_26 : 6; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_ICR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield FCXO : 16; /* FCX Offset Address Field */
     sfr_bitfield FCXS : 4; /* FCX Segment Address Field */
    /* const */ sfr_bitfield RES : 12; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_FCX_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield LCXO : 16; /* LCX Offset Field */
     sfr_bitfield LCXS : 4; /* LCX Segment Address */
    /* const */ sfr_bitfield RES : 12; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_LCX_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DATA : 32; /* Data Register */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_D0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ADDR : 32; /* Address Register */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_A0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ADFLIP : 8; /* Address ECC Bit Flip */
     sfr_bitfield ADTYPE : 2; /* Type of error */
    /* const */ sfr_bitfield RES : 21; /* Reserved */
     sfr_bitfield AE : 1; /* Activate Error Enable */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SEGEN_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 5; /* Reserved */
     sfr_bitfield ADDR : 27; /* Region Lower Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SPROT_RGNLA0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 5; /* Reserved */
     sfr_bitfield ADDR : 27; /* Region Upper Address */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SPROT_RGNUA0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EN : 32; /* Access Enable for Master TAG ID n (n = 0-31) */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SPROT_RGNACCENA0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 32; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SPROT_RGNACCENB0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EN : 32; /* Access Enable for Master TAG ID n (n= 0-31) */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} CPU0_SPROT_ACCENA_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield PLLLV : 1; /* Oscillator for PLL Valid Low Status Bit */
     sfr_bitfield OSCRES : 1; /* Oscillator Watchdog Reset */
     sfr_bitfield GAINSEL : 2; /* Oscillator Gain Selection */
     sfr_bitfield MODE : 2; /* Oscillator Mode */
     sfr_bitfield SHBY : 1; /* Shaper Bypass */
    /* const */ sfr_bitfield PLLHV : 1; /* Oscillator for PLL Valid High Status Bit */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield X1D : 1; /* XTAL1 Data Value */
     sfr_bitfield X1DEN : 1; /* XTAL1 Data Enable */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield OSCVAL : 5; /* OSC Frequency Value */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield APREN : 1; /* Amplitude Regulation Enable */
     sfr_bitfield CAP0EN : 1; /* Capacitance 0 Enable */
     sfr_bitfield CAP1EN : 1; /* Capacitance 1 Enable */
     sfr_bitfield CAP2EN : 1; /* Capacitance 2 Enable */
     sfr_bitfield CAP3EN : 1; /* Capacitance 3 Enable */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_OSCCON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield VCOBYST : 1; /* VCO Bypass Status */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield VCOLOCK : 1; /* PLL VCO Lock Status */
    /* const */ sfr_bitfield FINDIS : 1; /* Input Clock Disconnect Select Status */
    /* const */ sfr_bitfield K1RDY : 1; /* K1 Divider Ready Status */
    /* const */ sfr_bitfield K2RDY : 1; /* K2 Divider Ready Status */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield MODRUN : 1; /* Modulation Run */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLSTAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield VCOBYP : 1; /* VCO Bypass */
     sfr_bitfield VCOPWD : 1; /* VCO Power Saving Mode */
     sfr_bitfield MODEN : 1; /* Modulation Enable */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SETFINDIS : 1; /* Set Status Bit PLLSTAT.FINDIS */
     sfr_bitfield CLRFINDIS : 1; /* Clear Status Bit PLLSTAT.FINDIS */
     sfr_bitfield OSCDISCDIS : 1; /* Oscillator Disconnect Disable */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield NDIV : 7; /* N-Divider Value */
     sfr_bitfield PLLPWD : 1; /* PLL Power Saving Mode */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield RESLD : 1; /* Restart VCO Lock Detection */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield PDIV : 4; /* P-Divider Value */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield K2DIV : 7; /* K2-Divider Value */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield K3DIV : 7; /* K3-Divider Value */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield K1DIV : 7; /* K1-Divider Value */
     sfr_bitfield  : 9; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLCON1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield MODCFG : 16; /* Modulation Configuration */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLCON2_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield VCOBYST : 1; /* VCO Bypass Status */
    /* const */ sfr_bitfield PWDSTAT : 1; /* PLL_ERAY Power-saving Mode Status */
    /* const */ sfr_bitfield VCOLOCK : 1; /* PLL VCO Lock Status */
    /* const */ sfr_bitfield FINDIS : 1; /* Input Clock Disconnect Select Status */
    /* const */ sfr_bitfield K1RDY : 1; /* K1 Divider Ready Status */
    /* const */ sfr_bitfield K2RDY : 1; /* K2 Divider Ready Status */
     sfr_bitfield  : 26; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLERAYSTAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield VCOBYP : 1; /* VCO Bypass */
     sfr_bitfield VCOPWD : 1; /* VCO Power Saving Mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SETFINDIS : 1; /* Set Status Bit PLLERAYSTAT.FINDIS */
     sfr_bitfield CLRFINDIS : 1; /* Clear Status Bit PLLERAYSTAT.FINDIS */
     sfr_bitfield OSCDISCDIS : 1; /* Oscillator Disconnect Disable */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield NDIV : 5; /* N-Divider Value */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield PLLPWD : 1; /* PLL Power Saving Mode */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield RESLD : 1; /* Restart VCO Lock Detection */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield PDIV : 4; /* P-Divider Value */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLERAYCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield K2DIV : 7; /* K2-Divider Value */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield K3DIV : 4; /* K3-Divider Value */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield K1DIV : 7; /* K1-Divider Value */
     sfr_bitfield  : 9; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PLLERAYCON1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield BAUD1DIV : 4; /* Baud1 Divider Reload Value */
     sfr_bitfield BAUD2DIV : 4; /* Baud2 Divider Reload Value */
     sfr_bitfield SRIDIV : 4; /* SRI Divider Reload Value */
     sfr_bitfield LPDIV : 4; /* Low Power Divider Reload Value */
     sfr_bitfield SPBDIV : 4; /* SPB Divider Reload Value */
     sfr_bitfield FSI2DIV : 2; /* FSI2 Divider Reload Value */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield FSIDIV : 2; /* FSI Divider Reload Value */
     sfr_bitfield ADCCLKSEL : 2; /* ADC Clock Selection */
     sfr_bitfield CLKSEL : 2; /* Clock Selection */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CANDIV : 4; /* MultiCAN Divider Reload Value */
     sfr_bitfield ERAYDIV : 4; /* ERAY Divider Reload Value */
     sfr_bitfield STMDIV : 4; /* STM Divider Reload Value */
     sfr_bitfield GTMDIV : 4; /* GTM Divider Reload Value */
     sfr_bitfield ETHDIV : 4; /* Ethernet Divider Reload Value */
     sfr_bitfield ASCLINFDIV : 4; /* ASCLIN Fast Divider Reload Value */
     sfr_bitfield ASCLINSDIV : 4; /* ASCLIN Slow Divider Reload Value */
     sfr_bitfield INSEL : 2; /* Input Selection */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield MAXDIV : 4; /* Max Divider Reload Value */
     sfr_bitfield EBUDIV : 4; /* EBU Divider Reload Value */
     sfr_bitfield  : 22; /* reserved */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON5_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield BBBDIV : 4; /* BBB Divider Reload Value */
     sfr_bitfield  : 26; /* reserved */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CPU0DIV : 6; /* CPU0 Divider Reload Value */
     sfr_bitfield  : 26; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON6_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CPU1DIV : 6; /* CPU1 Divider Reload Value */
     sfr_bitfield  : 26; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON7_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CPU2DIV : 6; /* CPU2 Divider Reload Value */
     sfr_bitfield  : 26; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PLLDIV : 6; /* PLL Divider Value */
     sfr_bitfield PLLSEL : 2; /* PLL Target Monitoring Frequency Selection */
     sfr_bitfield PLLERAYDIV : 6; /* PLL_ERAY Divider Value */
     sfr_bitfield PLLERAYSEL : 2; /* PLL_ERAY Target Monitoring Frequency Selection */
     sfr_bitfield SRIDIV : 6; /* SRI Divider Value */
     sfr_bitfield SRISEL : 2; /* SRI Target Monitoring Frequency Selection */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield SLCK : 1; /* Security Lock */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON3_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SPBDIV : 6; /* SPB Divider Value */
     sfr_bitfield SPBSEL : 2; /* SPB Target Monitoring Frequency Selection */
     sfr_bitfield GTMDIV : 6; /* GTM Divider Value */
     sfr_bitfield GTMSEL : 2; /* GTM Target Monitoring Frequency Selection */
     sfr_bitfield STMDIV : 6; /* STM Divider Value */
     sfr_bitfield STMSEL : 2; /* STM Target Monitoring Frequency Selection */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield SLCK : 1; /* Security Lock */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ADCDIV : 6; /* ADC Divider Value */
     sfr_bitfield ADCSEL : 2; /* ADC Target Monitoring Frequency Selection */
     sfr_bitfield  : 21; /* reserved */
     sfr_bitfield SLCK : 1; /* Security Lock */
     sfr_bitfield UP : 1; /* Update Request */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CCUCON9_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EN0 : 1; /* External Clock Enable for EXTCLK0 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SEL0 : 4; /* External Clock Select for EXTCLK0 */
     sfr_bitfield  : 10; /* reserved */
     sfr_bitfield EN1 : 1; /* External Clock Enable for EXTCLK1 */
     sfr_bitfield NSEL : 1; /* Negation Selection */
     sfr_bitfield SEL1 : 4; /* External Clock Select for EXTCLK1 */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield DIV1 : 8; /* External Clock Divider for EXTCLK1 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EXTCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield STEP : 10; /* Step Value */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield DM : 2; /* Divider Mode */
    /* const */ sfr_bitfield RESULT : 10; /* Result Value */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield DISCLK : 1; /* Disable Clock */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_FDR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield ESR0 : 1; /* Reset Request Trigger Reset Status for ESR0 */
    /* const */ sfr_bitfield ESR1 : 1; /* Reset Request Trigger Reset Status for ESR1 */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield SMU : 1; /* Reset Request Trigger Reset Status for SMU */
    /* const */ sfr_bitfield SW : 1; /* Reset Request Trigger Reset Status for SW */
    /* const */ sfr_bitfield STM0 : 1; /* Reset Request Trigger Reset Status for STM0 Compare Match */
    /* const */ sfr_bitfield STM1 : 1; /* Reset Request Trigger Reset Status for STM1 Compare Match (If Product has STM1) */
    /* const */ sfr_bitfield STM2 : 1; /* Reset Request Trigger Reset Status for STM2 Compare Match (If Product has STM2) */
     sfr_bitfield  : 8; /* reserved */
    /* const */ sfr_bitfield PORST : 1; /* Reset Request Trigger Reset Status for PORST */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield CB0 : 1; /* Reset Request Trigger Reset Status for Cerberus System Reset */
    /* const */ sfr_bitfield CB1 : 1; /* Reset Request Trigger Reset Status for Cerberus Debug Reset */
    /* const */ sfr_bitfield CB3 : 1; /* Reset Request Trigger Reset Status for Cerberus Application Reset */
     sfr_bitfield  : 2; /* reserved */
    /* const */ sfr_bitfield EVR13 : 1; /* Reset Request Trigger Reset Status for EVR13 */
    /* const */ sfr_bitfield EVR33 : 1; /* Reset Request Trigger Reset Status for EVR33 */
    /* const */ sfr_bitfield SWD : 1; /* Reset Request Trigger Reset Status for Supply Watchdog (SWD) */
     sfr_bitfield  : 2; /* reserved */
    /* const */ sfr_bitfield STBYR : 1; /* Reset Request Trigger Reset Status for Standby Regulator Watchdog (STBYR) */
     sfr_bitfield  : 3; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_RSTSTAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ESR0 : 2; /* ESR0 Reset Request Trigger Reset Configuration */
     sfr_bitfield ESR1 : 2; /* ESR1 Reset Request Trigger Reset Configuration */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SMU : 2; /* SMU Reset Request Trigger Reset Configuration */
     sfr_bitfield SW : 2; /* SW Reset Request Trigger Reset Configuration */
     sfr_bitfield STM0 : 2; /* STM0 Reset Request Trigger Reset Configuration */
     sfr_bitfield STM1 : 2; /* STM1 Reset Request Trigger Reset Configuration (If Product has STM1) */
     sfr_bitfield STM2 : 2; /* STM2 Reset Request Trigger Reset Configuration (If Product has STM2) */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_RSTCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield STM0DIS : 1; /* STM0 Disable Reset */
     sfr_bitfield STM1DIS : 1; /* STM1 Disable Reset (If Product has STM1) */
     sfr_bitfield STM2DIS : 1; /* STM2 Disable Reset (If Product has STM2) */
     sfr_bitfield  : 29; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_ARSTDIS_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SWRSTREQ : 1; /* Software Reset Request */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield RES : 8; /* Reserved */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_SWRSTCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield CLRC : 1; /* Clear Cold Reset Status */
    /* const */ sfr_bitfield Reserved : 10; /* Reserved */
    /* const */ sfr_bitfield CSS0 : 1; /* CPU0 Safe State Reached */
    /* const */ sfr_bitfield CSS1 : 1; /* CPU1 Safe State Reached */
    /* const */ sfr_bitfield CSS2 : 1; /* CPU2 Safe State Reached */
    /* const */ sfr_bitfield Reserved_15 : 1; /* Reserved */
     sfr_bitfield USRINFO : 16; /* User Information */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_RSTCON2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 7; /* reserved */
     sfr_bitfield EDCON : 2; /* Edge Detection Control */
     sfr_bitfield  : 23; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_ESRCFG0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield ARI : 1; /* Application Reset Indicator */
     sfr_bitfield ARC : 1; /* Application Reset Indicator Clear */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_ESROCFG_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield PC0 : 4; /* Control for ESR Pin x */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield PC1 : 4; /* Control for ESR Pin x */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_IOCR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield P0 : 1; /* Output Bit 0 */
     sfr_bitfield P1 : 1; /* Output Bit 1 */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_OUT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PS0 : 1; /* ESR0 Pin Set Bit 0 */
     sfr_bitfield PS1 : 1; /* ESR1 Pin Set Bit 1 */
     sfr_bitfield  : 14; /* reserved */
     sfr_bitfield PCL0 : 1; /* ESR0 Pin Clear Bit 0 */
     sfr_bitfield PCL1 : 1; /* ESR1 Pin Clear Bit 1 */
     sfr_bitfield  : 14; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_OMR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield P0 : 1; /* Input Bit 0 */
    /* const */ sfr_bitfield P1 : 1; /* Input Bit 1 */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_IN_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PDIS0 : 1; /* Pad Disable for ESR Pin 0 */
     sfr_bitfield PDIS1 : 1; /* Pad Disable for ESR Pin 1 */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PDISC_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Pad Driver Mode for ESR Pins 0 and 1 */
     sfr_bitfield PL0 : 1; /* Pad Level Selection for ESR Pins 0 and 1 */
     sfr_bitfield PD1 : 3; /* Pad Driver Mode for ESR Pins 0 and 1 */
     sfr_bitfield PL1 : 1; /* Pad Level Selection for ESR Pins 0 and 1 */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PDR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield HWCFG : 8; /* Hardware Configuration Setting */
    /* const */ sfr_bitfield FTM : 7; /* Firmware Test Setting */
    /* const */ sfr_bitfield MODE : 1; /* MODE */
    /* const */ sfr_bitfield FCBAE : 1; /* Flash Config. Sector Access Enable */
    /* const */ sfr_bitfield LUDIS : 1; /* Latch Update Disable */
    /* const */ sfr_bitfield Res : 1; /* Reserved */
    /* const */ sfr_bitfield TRSTL : 1; /* TRSTL Status */
    /* const */ sfr_bitfield SPDEN : 1; /* Single Pin DAP Mode Enable */
    /* const */ sfr_bitfield Res_21 : 3; /* Reserved */
    /* const */ sfr_bitfield RAMINT : 1; /* RAM Content Security Integrity */
    /* const */ sfr_bitfield Res_25 : 7; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_STSTAT_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield ESR0T : 1; /* ESR0 Trap Request Flag */
    /* const */ sfr_bitfield ESR1T : 1; /* ESR1 Trap Request Flag */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield SMUT : 1; /* SMU Alarm Trap Request Flag */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_TRAPSTAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ESR0T : 1; /* Set Trap Request Flag ESR0T */
     sfr_bitfield ESR1T : 1; /* Set Trap Request Flag ESR1T */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SMUT : 1; /* Set Trap Request Flag SMUT */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_TRAPSET_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ESR0T : 1; /* Clear Trap Request Flag ESR0T */
     sfr_bitfield ESR1T : 1; /* Clear Trap Request Flag ESR1T */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SMUT : 1; /* Clear Trap Request Flag SMUT */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_TRAPCLR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ESR0T : 1; /* Disable Trap Request ESR0T */
     sfr_bitfield ESR1T : 1; /* Disable Trap Request ESR1T */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SMUT : 1; /* Disable Trap Request SMUT */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_TRAPDIS_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield EVR13 : 1; /* EVR13 status */
    /* const */ sfr_bitfield OV13 : 1; /* EVR13 Regulator Over-voltage event flag */
    /* const */ sfr_bitfield EVR33 : 1; /* EVR33 status */
    /* const */ sfr_bitfield OV33 : 1; /* EVR33 Regulator Over-voltage event flag */
    /* const */ sfr_bitfield OVSWD : 1; /* Supply Monitor (SWD) Over-voltage event flag */
    /* const */ sfr_bitfield UV13 : 1; /* EVR13 Regulator Under-voltage event flag */
    /* const */ sfr_bitfield UV33 : 1; /* EVR33 Regulator Under-voltage event flag */
    /* const */ sfr_bitfield UVSWD : 1; /* Supply Monitor (SWD) Under-voltage event flag */
    /* const */ sfr_bitfield EXTPASS13 : 1; /* External Pass Device for EVR13 */
    /* const */ sfr_bitfield EXTPASS33 : 1; /* External Pass Device for EVR33 */
    /* const */ sfr_bitfield BGPROK : 1; /* Primary Bandgap status */
     sfr_bitfield  : 21; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSTAT_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield ADC13V : 8; /* ADC 1.3 V Conversion Result */
    /* const */ sfr_bitfield ADC33V : 8; /* ADC 3.3 V Conversion Result */
    /* const */ sfr_bitfield ADCSWDV : 8; /* ADC External Supply Conversion Result */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield VAL : 1; /* Valid Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRADCSTAT_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 26; /* Reserved */
     sfr_bitfield RST33OFF : 1; /* Hard Reset EVR33 Enable */
     sfr_bitfield BPRST33OFF : 1; /* Bit Protection RST33OFF */
     sfr_bitfield RSTSWDOFF : 1; /* Hard Reset EVR Supply Monitor Enable */
     sfr_bitfield BPRSTSWDOFF : 1; /* Bit Protection RSTSWDOFF */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRRSTCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EVR13OVVAL : 8; /* 1.3 V Regulator Over-voltage threshold */
     sfr_bitfield EVR33OVVAL : 8; /* 3.3 V Regulator Over-voltage threshold */
     sfr_bitfield SWDOVVAL : 8; /* Supply monitor (SWD) Over-voltage threshold value */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVROVMON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EVR13UVVAL : 8; /* 1.3 V Regulator Under-voltage threshold */
     sfr_bitfield EVR33UVVAL : 8; /* 3.3 V Regulator Under-voltage threshold */
     sfr_bitfield SWDUVVAL : 8; /* Supply monitor (SWD) Under-voltage threshold value */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRUVMON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EVR13OVMOD : 2; /* 1.3 V Regulator Over-voltage monitoring mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield EVR13UVMOD : 2; /* 1.3 V Regulator Under-voltage monitoring mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield EVR33OVMOD : 2; /* 3.3 V Regulator Over-voltage monitoring mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield EVR33UVMOD : 2; /* 3.3 V Regulator Under-voltage monitoring mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SWDOVMOD : 2; /* Supply monitor (SWD) Over-voltage monitoring mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SWDUVMOD : 2; /* Supply monitor (SWD) Under-voltage monitoring mode */
     sfr_bitfield  : 10; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRMONCTRL_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 28; /* Reserved */
     sfr_bitfield EVR13OFF : 1; /* EVR13 Regulator Enable */
     sfr_bitfield BPEVR13OFF : 1; /* Bit Protection EVR13OFF */
    /* const */ sfr_bitfield RES_30 : 1; /* Reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVR13CON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RES : 28; /* Reserved */
     sfr_bitfield EVR33OFF : 1; /* EVR33 Regulator Enable */
     sfr_bitfield BPEVR33OFF : 1; /* Bit Protection EVR33OFF */
    /* const */ sfr_bitfield RES_30 : 1; /* Reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVR33CON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SDFREQSPRD : 16; /* Frequency Spread Threshold */
     sfr_bitfield SDFREQ : 8; /* Regulator Switching Frequency */
     sfr_bitfield SDSTEP : 4; /* Droop Voltage Step */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SDSAMPLE : 1; /* ADC Sampling Scheme */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCTRL1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DRVP : 8; /* P-Driver Setting */
     sfr_bitfield SDMINMAXDC : 8; /* Minimum Duty Cycle */
     sfr_bitfield DRVN : 8; /* N-Driver Setting */
     sfr_bitfield SDLUT : 6; /* Non-linear Starting Point */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCTRL2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SDPWMPRE : 8; /* PWM Preset Value */
     sfr_bitfield SDPID : 8; /* PID Control */
     sfr_bitfield SDVOKLVL : 8; /* Configuration of Voltage OK Signal */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCTRL3_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 8; /* reserved */
     sfr_bitfield SYNCDIV : 3; /* Clock Divider Ratio for external DCDC SYNC signal */
     sfr_bitfield  : 20; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCTRL4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SD5P : 8; /* P Coefficient */
     sfr_bitfield SD5I : 8; /* I Coefficient */
     sfr_bitfield SD5D : 8; /* D Coefficient */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCOEFF1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SD33P : 8; /* P Coefficient */
     sfr_bitfield SD33I : 8; /* I Coefficient */
     sfr_bitfield SD33D : 8; /* D Coefficient */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCOEFF2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CT5REG0 : 8; /* Commutation trimming */
     sfr_bitfield CT5REG1 : 8; /* Commutation trimming */
     sfr_bitfield CT5REG2 : 8; /* Commutation trimming */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCOEFF3_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CT5REG3 : 8; /* Commutation trimming */
     sfr_bitfield CT5REG4 : 8; /* Commutation trimming */
     sfr_bitfield  : 15; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCOEFF4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CT33REG0 : 8; /* Commutation trimming */
     sfr_bitfield CT33REG1 : 8; /* Commutation trimming */
     sfr_bitfield CT33REG2 : 8; /* Commutation trimming */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCOEFF5_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CT33REG3 : 8; /* Commutation trimming */
     sfr_bitfield CT33REG4 : 8; /* Commutation trimming */
     sfr_bitfield  : 15; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EVRSDCOEFF6_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield REQSLP : 2; /* Idle Mode and Sleep Mode Request */
     sfr_bitfield SMUSLP : 1; /* SMU CPU Idle Request */
     sfr_bitfield  : 5; /* reserved */
    /* const */ sfr_bitfield PMST : 3; /* Power management Status */
     sfr_bitfield  : 21; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PMCSR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield ESR1WKEN : 1; /* ESR1 Wake-up enable from Standby */
     sfr_bitfield PINAWKEN : 1; /* Pin A Wake-up enable from Standby */
     sfr_bitfield PINBWKEN : 1; /* Pin B Wake-up enable from Standby */
     sfr_bitfield ESR0DFEN : 1; /* Digital Filter Enable */
     sfr_bitfield ESR0EDCON : 2; /* Edge Detection Control */
     sfr_bitfield ESR1DFEN : 1; /* Digital Filter Enable */
     sfr_bitfield ESR1EDCON : 2; /* Edge Detection Control */
     sfr_bitfield PINADFEN : 1; /* Digital Filter Enable */
     sfr_bitfield PINAEDCON : 2; /* Edge Detection Control */
     sfr_bitfield PINBDFEN : 1; /* Digital Filter Enable */
     sfr_bitfield PINBEDCON : 2; /* Edge Detection Control */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield STBYRAMSEL : 2; /* Standby RAM supply in Standby Mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield TRISTEN : 1; /* Bit protection for Tristate request bit (TRISTREQ) */
     sfr_bitfield TRISTREQ : 1; /* Tristate enable */
     sfr_bitfield PORSTDF : 1; /* PORST Digital Filter enable */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield DCDCSYNC : 1; /* DC-DC Synchronisation Enable */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield ESR0TRIST : 1; /* ESR0 Tristate enable */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PMSWCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 8; /* reserved */
     sfr_bitfield CPUIDLSEL : 3; /* CPU selection for Idle mode */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield IRADIS : 1; /* Idle-Request-Acknowledge Sequence Disable */
     sfr_bitfield  : 11; /* reserved */
     sfr_bitfield CPUSEL : 3; /* CPU selection for Sleep and Standby mode */
     sfr_bitfield STBYEVEN : 1; /* Standby Entry Event configuration enable */
     sfr_bitfield STBYEV : 3; /* Standby Entry Event Configuration */
     sfr_bitfield  : 1; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PMSWCR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
    /* const */ sfr_bitfield ESR1WKP : 1; /* ESR1 Wake-up flag */
    /* const */ sfr_bitfield ESR1OVRUN : 1; /* ESR1 Overrun status flag */
    /* const */ sfr_bitfield PINAWKP : 1; /* Pin A (P14.1) Wake-up flag */
    /* const */ sfr_bitfield PINAOVRUN : 1; /* Pin A Overrun status flag */
    /* const */ sfr_bitfield PINBWKP : 1; /* Pin B (P15.1) Wake-up flag */
    /* const */ sfr_bitfield PINBOVRUN : 1; /* Pin B Overrun status flag */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield PORSTDF : 1; /* PORST Digital Filter status */
    /* const */ sfr_bitfield HWCFGEVR : 3; /* EVR Hardware Configuration */
    /* const */ sfr_bitfield STBYRAM : 2; /* Standby RAM Supply status */
    /* const */ sfr_bitfield TRIST : 1; /* Pad Tristate / Pull-up status */
     sfr_bitfield  : 4; /* reserved */
    /* const */ sfr_bitfield ESR1WKEN : 1; /* ESR1 Wake-up enable status */
    /* const */ sfr_bitfield PINAWKEN : 1; /* Pin A Wake-up enable status */
    /* const */ sfr_bitfield PINBWKEN : 1; /* Pin B Wake-up enable status */
     sfr_bitfield  : 4; /* reserved */
    /* const */ sfr_bitfield ESR0TRIST : 1; /* ESR0 pin status during Standby */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PMSWSTAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield ESR1WKPCLR : 1; /* ESR1 Wake-up indication flag clear */
     sfr_bitfield ESR1OVRUNCLR : 1; /* ESR1 Overrun status indication flag clear */
     sfr_bitfield PINAWKPCLR : 1; /* PINA Wake-up indication flag clear */
     sfr_bitfield PINAOVRUNCLR : 1; /* PINA Overrun status indication flag clear */
     sfr_bitfield PINBWKPCLR : 1; /* PINB Wake-up indication flag clear */
     sfr_bitfield PINBOVRUNCLR : 1; /* PINB Overrun status indication flag clear */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PMSWSTATCLR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield EXIS0 : 3; /* External Input Selection 0 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield FEN0 : 1; /* Falling Edge Enable 0 */
     sfr_bitfield REN0 : 1; /* Rising Edge Enable 0 */
     sfr_bitfield LDEN0 : 1; /* Level Detection Enable 0 */
     sfr_bitfield EIEN0 : 1; /* External Input Enable 0 */
     sfr_bitfield INP0 : 3; /* Input Node Pointer */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield EXIS1 : 3; /* External Input Selection 1 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield FEN1 : 1; /* Falling Edge Enable 1 */
     sfr_bitfield REN1 : 1; /* Rising Edge Enable 1 */
     sfr_bitfield LDEN1 : 1; /* Level Detection Enable 1 */
     sfr_bitfield EIEN1 : 1; /* External Input Enable 1 */
     sfr_bitfield INP1 : 3; /* Input Node Pointer */
     sfr_bitfield  : 1; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EICR0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield INTF0 : 1; /* External Event Flag of Channel 0 */
    /* const */ sfr_bitfield INTF1 : 1; /* External Event Flag of Channel 1 */
    /* const */ sfr_bitfield INTF2 : 1; /* External Event Flag of Channel 2 */
    /* const */ sfr_bitfield INTF3 : 1; /* External Event Flag of Channel 3 */
    /* const */ sfr_bitfield INTF4 : 1; /* External Event Flag of Channel 4 */
    /* const */ sfr_bitfield INTF5 : 1; /* External Event Flag of Channel 5 */
    /* const */ sfr_bitfield INTF6 : 1; /* External Event Flag of Channel 6 */
    /* const */ sfr_bitfield INTF7 : 1; /* External Event Flag of Channel 7 */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EIFR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield FS0 : 1; /* Set Flag INTF0 for Channel 0 */
     sfr_bitfield FS1 : 1; /* Set Flag INTF1 for Channel 1 */
     sfr_bitfield FS2 : 1; /* Set Flag INTF2 for Channel 2 */
     sfr_bitfield FS3 : 1; /* Set Flag INTF3 for Channel 3 */
     sfr_bitfield FS4 : 1; /* Set Flag INTF4 for Channel 4 */
     sfr_bitfield FS5 : 1; /* Set Flag INTF5 for Channel 5 */
     sfr_bitfield FS6 : 1; /* Set Flag INTF6 for Channel 6 */
     sfr_bitfield FS7 : 1; /* Set Flag INTF7 for Channel 7 */
     sfr_bitfield  : 8; /* reserved */
     sfr_bitfield FC0 : 1; /* Clear Flag INTF0 for Channel 0 */
     sfr_bitfield FC1 : 1; /* Clear Flag INTF1 for Channel 1 */
     sfr_bitfield FC2 : 1; /* Clear Flag INTF2 for Channel 2 */
     sfr_bitfield FC3 : 1; /* Clear Flag INTF3 for Channel 3 */
     sfr_bitfield FC4 : 1; /* Clear Flag INTF4 for Channel 4 */
     sfr_bitfield FC5 : 1; /* Clear Flag INTF5 for Channel 5 */
     sfr_bitfield FC6 : 1; /* Clear Flag INTF6 for Channel 6 */
     sfr_bitfield FC7 : 1; /* Clear Flag INTF7 for Channel 7 */
     sfr_bitfield  : 8; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_FMR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield PDR0 : 1; /* Pattern Detection Result of Channel 0 */
    /* const */ sfr_bitfield PDR1 : 1; /* Pattern Detection Result of Channel 1 */
    /* const */ sfr_bitfield PDR2 : 1; /* Pattern Detection Result of Channel 2 */
    /* const */ sfr_bitfield PDR3 : 1; /* Pattern Detection Result of Channel 3 */
    /* const */ sfr_bitfield PDR4 : 1; /* Pattern Detection Result of Channel 4 */
    /* const */ sfr_bitfield PDR5 : 1; /* Pattern Detection Result of Channel 5 */
    /* const */ sfr_bitfield PDR6 : 1; /* Pattern Detection Result of Channel 6 */
    /* const */ sfr_bitfield PDR7 : 1; /* Pattern Detection Result of Channel 7 */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_PDRR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield IPEN00 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN01 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN02 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN03 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN04 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN05 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN06 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield IPEN07 : 1; /* Flag Pattern Enable for Channel 0 */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield GEEN0 : 1; /* Generate Event Enable 0 */
     sfr_bitfield IGP0 : 2; /* Interrupt Gating Pattern 0 */
     sfr_bitfield IPEN10 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN11 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN12 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN13 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN14 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN15 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN16 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield IPEN17 : 1; /* Interrupt Pattern Enable for Channel 1 */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield GEEN1 : 1; /* Generate Event Enable 1 */
     sfr_bitfield IGP1 : 2; /* Interrupt Gating Pattern 1 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_IGCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 16; /* reserved */
    /* const */ sfr_bitfield LS : 1; /* Reserved in this product */
     sfr_bitfield  : 14; /* reserved */
     sfr_bitfield LSEN : 1; /* Reserved in this product */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_LCLCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 16; /* reserved */
    /* const */ sfr_bitfield LS : 1; /* Lockstep Mode Status */
     sfr_bitfield  : 14; /* reserved */
     sfr_bitfield LSEN : 1; /* Lockstep Enable */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_LCLCON1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield LCLT0 : 1; /* Reserved in this product */
     sfr_bitfield LCLT1 : 1; /* LCL1 Lockstep Test */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_LCLTEST_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PWD : 1; /* Sensor Power Down */
     sfr_bitfield START : 1; /* Sensor Measurement Start */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield CAL : 20; /* Calibration Value */
     sfr_bitfield  : 7; /* reserved */
     sfr_bitfield SLCK : 1; /* Security Lock */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_DTSCON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield RESULT : 10; /* Result of the DTS Measurement */
     sfr_bitfield  : 4; /* reserved */
    /* const */ sfr_bitfield RDY : 1; /* Sensor Ready Status */
    /* const */ sfr_bitfield BUSY : 1; /* Sensor Busy Status */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_DTSSTAT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield LOWER : 10; /* Lower Limit */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield LLU : 1; /* Lower Limit Underflow */
     sfr_bitfield UPPER : 10; /* Upper Limit */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield SLCK : 1; /* Security Lock */
    /* const */ sfr_bitfield UOF : 1; /* Upper Limit Overflow */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_DTSLIM_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ENDINIT : 1; /* End-of-Initialization Control Bit */
     sfr_bitfield LCK : 1; /* Lock Bit to Control Access to WDTxCON0 */
     sfr_bitfield PW : 14; /* User-Definable Password Field for Access to WDTxCON0 */
     sfr_bitfield REL : 16; /* Reload Value for the WDT (also Time Check Value) */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_WDTSCON0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CLRIRF : 1; /* Clear Internal Reset Flag */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield IR0 : 1; /* Input Frequency Request Control */
     sfr_bitfield DR : 1; /* Disable Request Control Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield IR1 : 1; /* Input Frequency Request Control */
     sfr_bitfield UR : 1; /* Unlock Restriction Request Control Bit */
     sfr_bitfield PAR : 1; /* Password Auto-sequence Request Bit */
     sfr_bitfield TCR : 1; /* Counter Check Request Bit */
     sfr_bitfield TCTR : 7; /* Timer Check Tolerance Request */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_WDTSCON1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield IR0 : 1; /* Input Frequency Request Control */
     sfr_bitfield DR : 1; /* Disable Request Control Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield IR1 : 1; /* Input Frequency Request Control */
     sfr_bitfield UR : 1; /* Unlock Restriction Request Control Bit */
     sfr_bitfield PAR : 1; /* Password Auto-sequence Request Bit */
     sfr_bitfield TCR : 1; /* Counter Check Request Bit */
     sfr_bitfield TCTR : 7; /* Timer Check Tolerance Request */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_WDTCPU0CON1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield AE : 1; /* Watchdog Access Error Status Flag */
    /* const */ sfr_bitfield OE : 1; /* Watchdog Overflow Error Status Flag */
    /* const */ sfr_bitfield IS0 : 1; /* Watchdog Input Clock Status */
    /* const */ sfr_bitfield DS : 1; /* Watchdog Enable/Disable Status Flag */
    /* const */ sfr_bitfield TO : 1; /* Watchdog Time-Out Mode Flag */
    /* const */ sfr_bitfield IS1 : 1; /* Watchdog Input Clock Status */
    /* const */ sfr_bitfield US : 1; /* SMU Unlock Restriction Status Flag */
    /* const */ sfr_bitfield PAS : 1; /* Password Auto-sequence Status Flag */
    /* const */ sfr_bitfield TCS : 1; /* Timer Check Status Flag */
    /* const */ sfr_bitfield TCT : 7; /* Timer Check Tolerance */
    /* const */ sfr_bitfield TIM : 16; /* Timer Value */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_WDTSSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield HBT : 1; /* Heartbeat */
     sfr_bitfield Res : 31; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_SAFECON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield POL : 1; /* Input Polarity */
     sfr_bitfield MODE : 1; /* Mode Selection */
     sfr_bitfield ENON : 1; /* Enable ON */
     sfr_bitfield PSEL : 1; /* PORT Select */
     sfr_bitfield  : 12; /* reserved */
    /* const */ sfr_bitfield EMSF : 1; /* Emergency Stop Flag */
    /* const */ sfr_bitfield SEMSF : 1; /* SMU Emergency Stop Flag */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield EMSFM : 2; /* Emergency Stop Flag Modification */
     sfr_bitfield SEMSFM : 2; /* SMU Emergency Stop Flag Modification */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_EMSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield LBISTREQ : 1; /* LBIST Request */
     sfr_bitfield LBISTREQP : 1; /* LBIST Request Protection Bit */
     sfr_bitfield PATTERNS : 14; /* LBIST Pattern Number */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_LBISTCTRL0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SEED : 23; /* LBIST Seed */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SPLITSH : 3; /* LBIST Split-Shift Selection */
     sfr_bitfield BODY : 1; /* Body Application Indicator */
     sfr_bitfield LBISTFREQU : 4; /* LBIST Frequency Selection */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_LBISTCTRL1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield SIGNATURE : 24; /* LBIST Signature */
     sfr_bitfield  : 7; /* reserved */
    /* const */ sfr_bitfield LBISTDONE : 1; /* LBIST Execution Indicator */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_LBISTCTRL2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield OVEN0 : 1; /* Overlay Enable 0 */
     sfr_bitfield OVEN1 : 1; /* Overlay Enable 1 */
     sfr_bitfield OVEN2 : 1; /* Overlay Enable 1 */
     sfr_bitfield  : 29; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_OVCENABLE_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CSEL0 : 1; /* CPU Select 0 */
     sfr_bitfield CSEL1 : 1; /* CPU Select 1 */
     sfr_bitfield CSEL2 : 1; /* CPU Select 2 */
     sfr_bitfield  : 13; /* reserved */
     sfr_bitfield OVSTRT : 1; /* Overlay Start */
     sfr_bitfield OVSTP : 1; /* Overlay Stop */
     sfr_bitfield DCINVAL : 1; /* Data Cache Invalidate */
     sfr_bitfield  : 5; /* reserved */
     sfr_bitfield OVCONF : 1; /* Overlay Configured */
     sfr_bitfield POVCONF : 1; /* Write Protection for OVCONF */
     sfr_bitfield  : 6; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_OVCCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CCTRIG0 : 1; /* Capture Compare Trigger 0 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield RAMINTM : 2; /* RAM Integrity Modify */
     sfr_bitfield SETLUDIS : 1; /* Set Latch Update Disable */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield DATM : 1; /* Disable Application Test Mode (ATM) */
     sfr_bitfield  : 23; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_SYSCON_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield CHREV : 6; /* Chip Revision Number */
    /* const */ sfr_bitfield CHTEC : 2; /* Chip Family */
     sfr_bitfield CHID : 8; /* Chip Identification Number */
    /* const */ sfr_bitfield EEA : 1; /* Emulation Extension Available */
     sfr_bitfield UCODE : 7; /* µCode Version */
     sfr_bitfield FSIZE : 4; /* Program Flash Size */
     sfr_bitfield SP : 2; /* Speed */
     sfr_bitfield SEC : 1; /* Security Device */
     sfr_bitfield  : 1; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_CHIPID_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield MODREV : 8; /* Module Revision Number */
    /* const */ sfr_bitfield MODTYPE : 8; /* Module Type */
    /* const */ sfr_bitfield MODNUMBER : 16; /* Module Number */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_ID_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield DEPT : 5; /* Department Identification Number */
    /* const */ sfr_bitfield MANUF : 11; /* Manufacturer Identification Number */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SCU_MANID_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC0 : 5; /* Port Control for Port n Pin 0 to 3 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC1 : 5; /* Port Control for Port n Pin 0 to 3 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC2 : 5; /* Port Control for Port n Pin 0 to 3 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC3 : 5; /* Port Control for Port n Pin 0 to 3 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_IOCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC4 : 5; /* Port Control for Port n Pin 4 to 7 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC5 : 5; /* Port Control for Port n Pin 4 to 7 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC6 : 5; /* Port Control for Port n Pin 4 to 7 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC7 : 5; /* Port Control for Port n Pin 4 to 7 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_IOCR4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC8 : 5; /* Port Control for Port n Pin 8 to 11 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC9 : 5; /* Port Control for Port n Pin 8 to 11 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC10 : 5; /* Port Control for Port n Pin 8 to 11 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC11 : 5; /* Port Control for Port n Pin 8 to 11 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_IOCR8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC12 : 5; /* Port Control for Port n Pin 12 to 15 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC13 : 5; /* Port Control for Port n Pin 12 to 15 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC14 : 5; /* Port Control for Port n Pin 12 to 15 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC15 : 5; /* Port Control for Port n Pin 12 to 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_IOCR12_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL0 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD1 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL1 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD2 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL2 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD3 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL3 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD4 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL4 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD5 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL5 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD6 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL6 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
     sfr_bitfield PD7 : 3; /* Pad Driver Mode for Port n Pin 0 to 7 */
     sfr_bitfield PL7 : 1; /* Pad Level Selection for Port n Pin 0 to 7 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_PDR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD8 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL8 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD9 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL9 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD10 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL10 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD11 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL11 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD12 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL12 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD13 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL13 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD14 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL14 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
     sfr_bitfield PD15 : 3; /* Pad Driver Mode for Port n Pin 8 to 15 */
     sfr_bitfield PL15 : 1; /* Pad Level Selection for Port n Pin 8 to 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_PDR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PDIS0 : 1; /* Pin Function Decision Control for Pin 0 */
     sfr_bitfield PDIS1 : 1; /* Pin Function Decision Control for Pin 1 */
     sfr_bitfield PDIS2 : 1; /* Pin Function Decision Control for Pin 2 */
     sfr_bitfield PDIS3 : 1; /* Pin Function Decision Control for Pin 3 */
     sfr_bitfield PDIS4 : 1; /* Pin Function Decision Control for Pin 4 */
     sfr_bitfield PDIS5 : 1; /* Pin Function Decision Control for Pin 5 */
     sfr_bitfield PDIS6 : 1; /* Pin Function Decision Control for Pin 6 */
     sfr_bitfield PDIS7 : 1; /* Pin Function Decision Control for Pin 7 */
     sfr_bitfield PDIS8 : 1; /* Pin Function Decision Control for Pin 8 */
     sfr_bitfield PDIS9 : 1; /* Pin Function Decision Control for Pin 9 */
     sfr_bitfield PDIS10 : 1; /* Pin Function Decision Control for Pin 10 */
     sfr_bitfield PDIS11 : 1; /* Pin Function Decision Control for Pin 11 */
     sfr_bitfield PDIS12 : 1; /* Pin Function Decision Control for Pin 12 */
     sfr_bitfield PDIS13 : 1; /* Pin Function Decision Control for Pin 13 */
     sfr_bitfield PDIS14 : 1; /* Pin Function Decision Control for Pin 14 */
     sfr_bitfield PDIS15 : 1; /* Pin Function Decision Control for Pin 15 */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P40_PDISC_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield P0 : 1; /* Port n Output Bit 0 */
     sfr_bitfield P1 : 1; /* Port n Output Bit 1 */
     sfr_bitfield P2 : 1; /* Port n Output Bit 2 */
     sfr_bitfield P3 : 1; /* Port n Output Bit 3 */
     sfr_bitfield P4 : 1; /* Port n Output Bit 4 */
     sfr_bitfield P5 : 1; /* Port n Output Bit 5 */
     sfr_bitfield P6 : 1; /* Port n Output Bit 6 */
     sfr_bitfield P7 : 1; /* Port n Output Bit 7 */
     sfr_bitfield P8 : 1; /* Port n Output Bit 8 */
     sfr_bitfield P9 : 1; /* Port n Output Bit 9 */
     sfr_bitfield P10 : 1; /* Port n Output Bit 10 */
     sfr_bitfield P11 : 1; /* Port n Output Bit 11 */
     sfr_bitfield P12 : 1; /* Port n Output Bit 12 */
     sfr_bitfield P13 : 1; /* Port n Output Bit 13 */
     sfr_bitfield P14 : 1; /* Port n Output Bit 14 */
     sfr_bitfield P15 : 1; /* Port n Output Bit 15 */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OUT_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PS0 : 1; /* Port n Set Bit 0 */
     sfr_bitfield PS1 : 1; /* Port n Set Bit 1 */
     sfr_bitfield PS2 : 1; /* Port n Set Bit 2 */
     sfr_bitfield PS3 : 1; /* Port n Set Bit 3 */
     sfr_bitfield PS4 : 1; /* Port n Set Bit 4 */
     sfr_bitfield PS5 : 1; /* Port n Set Bit 5 */
     sfr_bitfield PS6 : 1; /* Port n Set Bit 6 */
     sfr_bitfield PS7 : 1; /* Port n Set Bit 7 */
     sfr_bitfield PS8 : 1; /* Port n Set Bit 8 */
     sfr_bitfield PS9 : 1; /* Port n Set Bit 9 */
     sfr_bitfield PS10 : 1; /* Port n Set Bit 10 */
     sfr_bitfield PS11 : 1; /* Port n Set Bit 11 */
     sfr_bitfield PS12 : 1; /* Port n Set Bit 12 */
     sfr_bitfield PS13 : 1; /* Port n Set Bit 13 */
     sfr_bitfield PS14 : 1; /* Port n Set Bit 14 */
     sfr_bitfield PS15 : 1; /* Port n Set Bit 15 */
     sfr_bitfield PCL0 : 1; /* Port n Clear Bit 0 */
     sfr_bitfield PCL1 : 1; /* Port n Clear Bit 1 */
     sfr_bitfield PCL2 : 1; /* Port n Clear Bit 2 */
     sfr_bitfield PCL3 : 1; /* Port n Clear Bit 3 */
     sfr_bitfield PCL4 : 1; /* Port n Clear Bit 4 */
     sfr_bitfield PCL5 : 1; /* Port n Clear Bit 5 */
     sfr_bitfield PCL6 : 1; /* Port n Clear Bit 6 */
     sfr_bitfield PCL7 : 1; /* Port n Clear Bit 7 */
     sfr_bitfield PCL8 : 1; /* Port n Clear Bit 8 */
     sfr_bitfield PCL9 : 1; /* Port n Clear Bit 9 */
     sfr_bitfield PCL10 : 1; /* Port n Clear Bit 10 */
     sfr_bitfield PCL11 : 1; /* Port n Clear Bit 11 */
     sfr_bitfield PCL12 : 1; /* Port n Clear Bit 12 */
     sfr_bitfield PCL13 : 1; /* Port n Clear Bit 13 */
     sfr_bitfield PCL14 : 1; /* Port n Clear Bit 14 */
     sfr_bitfield PCL15 : 1; /* Port n Clear Bit 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PS0 : 1; /* Port n Set Bit 0 */
     sfr_bitfield PS1 : 1; /* Port n Set Bit 1 */
     sfr_bitfield PS2 : 1; /* Port n Set Bit 2 */
     sfr_bitfield PS3 : 1; /* Port n Set Bit 3 */
     sfr_bitfield PS4 : 1; /* Port n Set Bit 4 */
     sfr_bitfield PS5 : 1; /* Port n Set Bit 5 */
     sfr_bitfield PS6 : 1; /* Port n Set Bit 6 */
     sfr_bitfield PS7 : 1; /* Port n Set Bit 7 */
     sfr_bitfield PS8 : 1; /* Port n Set Bit 8 */
     sfr_bitfield PS9 : 1; /* Port n Set Bit 9 */
     sfr_bitfield PS10 : 1; /* Port n Set Bit 10 */
     sfr_bitfield PS11 : 1; /* Port n Set Bit 11 */
     sfr_bitfield PS12 : 1; /* Port n Set Bit 12 */
     sfr_bitfield PS13 : 1; /* Port n Set Bit 13 */
     sfr_bitfield PS14 : 1; /* Port n Set Bit 14 */
     sfr_bitfield PS15 : 1; /* Port n Set Bit 15 */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PS0 : 1; /* Port n Set Bit 0 */
     sfr_bitfield PS1 : 1; /* Port n Set Bit 1 */
     sfr_bitfield PS2 : 1; /* Port n Set Bit 2 */
     sfr_bitfield PS3 : 1; /* Port n Set Bit 3 */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMSR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield PS4 : 1; /* Port n Set Bit 4 */
     sfr_bitfield PS5 : 1; /* Port n Set Bit 5 */
     sfr_bitfield PS6 : 1; /* Port n Set Bit 6 */
     sfr_bitfield PS7 : 1; /* Port n Set Bit 7 */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMSR4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 8; /* reserved */
     sfr_bitfield PS8 : 1; /* Port n Set Bit 8 */
     sfr_bitfield PS9 : 1; /* Port n Set Bit 9 */
     sfr_bitfield PS10 : 1; /* Port n Set Bit 10 */
     sfr_bitfield PS11 : 1; /* Port n Set Bit 11 */
     sfr_bitfield  : 20; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMSR8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 12; /* reserved */
     sfr_bitfield PS12 : 1; /* Port n Set Bit 12 */
     sfr_bitfield PS13 : 1; /* Port n Set Bit 13 */
     sfr_bitfield PS14 : 1; /* Port n Set Bit 14 */
     sfr_bitfield PS15 : 1; /* Port n Set Bit 15 */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMSR12_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 16; /* reserved */
     sfr_bitfield PCL0 : 1; /* Port n Clear Bit 0 */
     sfr_bitfield PCL1 : 1; /* Port n Clear Bit 1 */
     sfr_bitfield PCL2 : 1; /* Port n Clear Bit 2 */
     sfr_bitfield PCL3 : 1; /* Port n Clear Bit 3 */
     sfr_bitfield PCL4 : 1; /* Port n Clear Bit 4 */
     sfr_bitfield PCL5 : 1; /* Port n Clear Bit 5 */
     sfr_bitfield PCL6 : 1; /* Port n Clear Bit 6 */
     sfr_bitfield PCL7 : 1; /* Port n Clear Bit 7 */
     sfr_bitfield PCL8 : 1; /* Port n Clear Bit 8 */
     sfr_bitfield PCL9 : 1; /* Port n Clear Bit 9 */
     sfr_bitfield PCL10 : 1; /* Port n Clear Bit 10 */
     sfr_bitfield PCL11 : 1; /* Port n Clear Bit 11 */
     sfr_bitfield PCL12 : 1; /* Port n Clear Bit 12 */
     sfr_bitfield PCL13 : 1; /* Port n Clear Bit 13 */
     sfr_bitfield PCL14 : 1; /* Port n Clear Bit 14 */
     sfr_bitfield PCL15 : 1; /* Port n Clear Bit 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMCR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 16; /* reserved */
     sfr_bitfield PCL0 : 1; /* Port n Clear Bit 0 */
     sfr_bitfield PCL1 : 1; /* Port n Clear Bit 1 */
     sfr_bitfield PCL2 : 1; /* Port n Clear Bit 2 */
     sfr_bitfield PCL3 : 1; /* Port n Clear Bit 3 */
     sfr_bitfield  : 12; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 20; /* reserved */
     sfr_bitfield PCL4 : 1; /* Port n Clear Bit 4 */
     sfr_bitfield PCL5 : 1; /* Port n Clear Bit 5 */
     sfr_bitfield PCL6 : 1; /* Port n Clear Bit 6 */
     sfr_bitfield PCL7 : 1; /* Port n Clear Bit 7 */
     sfr_bitfield  : 8; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMCR4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 24; /* reserved */
     sfr_bitfield PCL8 : 1; /* Port n Clear Bit 8 */
     sfr_bitfield PCL9 : 1; /* Port n Clear Bit 9 */
     sfr_bitfield PCL10 : 1; /* Port n Clear Bit 10 */
     sfr_bitfield PCL11 : 1; /* Port n Clear Bit 11 */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMCR8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 28; /* reserved */
     sfr_bitfield PCL12 : 1; /* Port n Clear Bit 12 */
     sfr_bitfield PCL13 : 1; /* Port n Clear Bit 13 */
     sfr_bitfield PCL14 : 1; /* Port n Clear Bit 14 */
     sfr_bitfield PCL15 : 1; /* Port n Clear Bit 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_OMCR12_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EN0 : 1; /* Emergency Stop Enable for Port n Pin 0 */
     sfr_bitfield EN1 : 1; /* Emergency Stop Enable for Port n Pin 1 */
     sfr_bitfield EN2 : 1; /* Emergency Stop Enable for Port n Pin 2 */
     sfr_bitfield EN3 : 1; /* Emergency Stop Enable for Port n Pin 3 */
     sfr_bitfield EN4 : 1; /* Emergency Stop Enable for Port n Pin 4 */
     sfr_bitfield EN5 : 1; /* Emergency Stop Enable for Port n Pin 5 */
     sfr_bitfield EN6 : 1; /* Emergency Stop Enable for Port n Pin 6 */
     sfr_bitfield EN7 : 1; /* Emergency Stop Enable for Port n Pin 7 */
     sfr_bitfield EN8 : 1; /* Emergency Stop Enable for Port n Pin 8 */
     sfr_bitfield EN9 : 1; /* Emergency Stop Enable for Port n Pin 9 */
     sfr_bitfield EN10 : 1; /* Emergency Stop Enable for Port n Pin 10 */
     sfr_bitfield EN11 : 1; /* Emergency Stop Enable for Port n Pin 11 */
     sfr_bitfield EN12 : 1; /* Emergency Stop Enable for Port n Pin 12 */
     sfr_bitfield EN13 : 1; /* Emergency Stop Enable for Port n Pin 13 */
     sfr_bitfield EN14 : 1; /* Emergency Stop Enable for Port n Pin 14 */
     sfr_bitfield EN15 : 1; /* Emergency Stop Enable for Port n Pin 15 */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_ESR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield P0 : 1; /* Port n Input Bit 0 */
    /* const */ sfr_bitfield P1 : 1; /* Port n Input Bit 1 */
    /* const */ sfr_bitfield P2 : 1; /* Port n Input Bit 2 */
    /* const */ sfr_bitfield P3 : 1; /* Port n Input Bit 3 */
    /* const */ sfr_bitfield P4 : 1; /* Port n Input Bit 4 */
    /* const */ sfr_bitfield P5 : 1; /* Port n Input Bit 5 */
    /* const */ sfr_bitfield P6 : 1; /* Port n Input Bit 6 */
    /* const */ sfr_bitfield P7 : 1; /* Port n Input Bit 7 */
    /* const */ sfr_bitfield P8 : 1; /* Port n Input Bit 8 */
    /* const */ sfr_bitfield P9 : 1; /* Port n Input Bit 9 */
    /* const */ sfr_bitfield P10 : 1; /* Port n Input Bit 10 */
    /* const */ sfr_bitfield P11 : 1; /* Port n Input Bit 11 */
    /* const */ sfr_bitfield P12 : 1; /* Port n Input Bit 12 */
    /* const */ sfr_bitfield P13 : 1; /* Port n Input Bit 13 */
    /* const */ sfr_bitfield P14 : 1; /* Port n Input Bit 14 */
    /* const */ sfr_bitfield P15 : 1; /* Port n Input Bit 15 */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_IN_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield EN0 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN1 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN2 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN3 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN4 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN5 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN6 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN7 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN8 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN9 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN10 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN11 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN12 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN13 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN14 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN15 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN16 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN17 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN18 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN19 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN20 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN21 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN22 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN23 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN24 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN25 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN26 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN27 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN28 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN29 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN30 : 1; /* Access Enable for Master TAG ID n */
     sfr_bitfield EN31 : 1; /* Access Enable for Master TAG ID n */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_ACCEN0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield SEL4 : 1; /* Output Select for Pin 4 */
     sfr_bitfield SEL5 : 1; /* Output Select for Pin 5 */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield SEL10 : 1; /* Output Select for Pin 10 */
     sfr_bitfield SEL11 : 1; /* Output Select for Pin 11 */
     sfr_bitfield  : 19; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P00_PCSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC12 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC13 : 5; /* Port Control for Port 00.[15:13] */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC14 : 5; /* Port Control for Port 00.[15:13] */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC15 : 5; /* Port Control for Port 00.[15:13] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P10_IOCR12_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD8 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL8 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PD9 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL9 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PD10 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL10 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL12 : 1; /* Reserved */
     sfr_bitfield PD11 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL11 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PD12 : 3; /* Reserved */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield PD13 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL13 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PD14 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL14 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PD15 : 3; /* Pad Driver Mode for Port 10 Pin [11:8], [15:13] */
     sfr_bitfield PL15 : 1; /* Pad Level Selection for Port 10 Pin [11:8], [15:13] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P10_PDR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SEL0 : 1; /* Pin Controller Select for Pin 0 */
     sfr_bitfield SEL1 : 1; /* Pin Controller Select for Pin 1 */
     sfr_bitfield SEL2 : 1; /* Pin Controller Select for Pin 2 */
     sfr_bitfield SEL3 : 1; /* Pin Controller Select for Pin 3 */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SEL6 : 1; /* Pin Controller Select for Pin 6 */
     sfr_bitfield  : 25; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P11_PCSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC0 : 5; /* Port Control for Port 12 Pin 0 to 1 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC1 : 5; /* Port Control for Port 12 Pin 0 to 1 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC2 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC3 : 5; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P12_IOCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Pad Driver Mode for Port 12 Pin 0 to 1 */
     sfr_bitfield PL0 : 1; /* Pad Level Selection for Port 12 Pin 0 to 1 */
     sfr_bitfield PD1 : 3; /* Pad Driver Mode for Port 12 Pin 0 to 1 */
     sfr_bitfield PL1 : 1; /* Pad Level Selection for Port 12 Pin 0 to 1 */
     sfr_bitfield PD2 : 3; /* Reserved */
     sfr_bitfield PL2 : 1; /* Reserved */
     sfr_bitfield PD3 : 3; /* Reserved */
     sfr_bitfield PL3 : 1; /* Reserved */
    /* const */ sfr_bitfield PD4 : 3; /* Reserved */
    /* const */ sfr_bitfield PL4 : 1; /* Reserved */
    /* const */ sfr_bitfield PD5 : 3; /* Reserved */
    /* const */ sfr_bitfield PL5 : 1; /* Reserved */
    /* const */ sfr_bitfield PD6 : 3; /* Reserved */
    /* const */ sfr_bitfield PL6 : 1; /* Reserved */
    /* const */ sfr_bitfield PD7 : 3; /* Reserved */
    /* const */ sfr_bitfield PL7 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P12_PDR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC8 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC9 : 5; /* Port Control for Port 13 Pin 9 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC10 : 5; /* Port Control for Port 13 Pin10 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC11 : 5; /* Port Control for Port 13 Pin 11 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_IOCR8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Pad Driver Mode for Port 13 Pin [1:0] */
     sfr_bitfield PL0 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD1 : 3; /* Pad Driver Mode for Port 13 Pin 1, 3, 5 and 7 */
     sfr_bitfield PL1 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD2 : 3; /* Pad Driver Mode for Port 13 Pin [3:2] */
     sfr_bitfield PL2 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD3 : 3; /* Pad Driver Mode for Port 13 Pin 1, 3, 5 and 7 */
     sfr_bitfield PL3 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD4 : 3; /* Pad Driver Mode for Port 13 Pin [5:4] */
     sfr_bitfield PL4 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD5 : 3; /* Pad Driver Mode for Port 13 Pin 1, 3, 5 and 7 */
     sfr_bitfield PL5 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD6 : 3; /* Pad Driver Mode for Port 13 Pin [7:6] */
     sfr_bitfield PL6 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
     sfr_bitfield PD7 : 3; /* Pad Driver Mode for Port 13 Pin 1, 3, 5 and 7 */
     sfr_bitfield PL7 : 1; /* Pad Level Selection for Port 13 Pin 0 to 7 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_PDR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD8 : 3; /* Reserved */
     sfr_bitfield PL8 : 1; /* Reserved */
     sfr_bitfield PD9 : 3; /* Pad Driver Mode for Port 13 Pin 9 */
     sfr_bitfield PL9 : 1; /* Pad Level Selection for Port 13 Pin 9 */
     sfr_bitfield PD10 : 3; /* Pad Driver Mode for Port 13 Pin 10 */
     sfr_bitfield PL10 : 1; /* Pad Level Selection for Port 13 Pin 10 */
     sfr_bitfield PD11 : 3; /* Pad Driver Mode for Port 13 Pin 11 */
     sfr_bitfield PL11 : 1; /* Pad Level Selection for Port 13 Pin 11 */
     sfr_bitfield PD12 : 3; /* Pad Driver Mode for Port 13 Pin 12 */
     sfr_bitfield PL12 : 1; /* Pad Level Selection for Port 13 Pin 12 */
     sfr_bitfield PD13 : 3; /* Pad Driver Mode for Port 13 Pin 13 */
     sfr_bitfield PL13 : 1; /* Pad Level Selection for Port 13 Pin 13 */
     sfr_bitfield PD14 : 3; /* Pad Driver Mode for Port 13 Pin 14 */
     sfr_bitfield PL14 : 1; /* Pad Level Selection for Port 13 Pin 14 */
     sfr_bitfield PD15 : 3; /* Pad Driver Mode for Port 13 Pin 15 */
     sfr_bitfield PL15 : 1; /* Pad Level Selection for Port 13 Pin 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_PDR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield PS1 : 1; /* Pad Supply for pins [1:0] */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_LPCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield PS1 : 1; /* Pad Supply for pins [3:2] */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_LPCR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield PS1 : 1; /* Pad Supply for pins [5:4] */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_LPCR2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield PS1 : 1; /* Pad Supply for pins [7:6] */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P13_LPCR3_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC8 : 5; /* Port Control for Port 15 Pin 8 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC9 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC10 : 5; /* Port Control for Port 15 Pin10 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC11 : 5; /* Port Control for Port 15 Pin 11 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P15_IOCR8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD8 : 3; /* Pad Driver Mode for Port 15 Pin 8 */
     sfr_bitfield PL8 : 1; /* Pad Level Selection for Port 15 Pin 8 */
     sfr_bitfield PD9 : 3; /* Reserved */
     sfr_bitfield PL9 : 1; /* Reserved */
     sfr_bitfield PD10 : 3; /* Pad Driver Mode for Port 15 Pin 10 */
     sfr_bitfield PL10 : 1; /* Pad Level Selection for Port 13 Pin 10 */
     sfr_bitfield PD11 : 3; /* Pad Driver Mode for Port 15 Pin 11 */
     sfr_bitfield PL11 : 1; /* Pad Level Selection for Port 15 Pin 11 */
     sfr_bitfield PD12 : 3; /* Pad Driver Mode for Port 15 Pin 12 */
     sfr_bitfield PL12 : 1; /* Pad Level Selection for Port 15 Pin 12 */
     sfr_bitfield PD13 : 3; /* Pad Driver Mode for Port 15 Pin 13 */
     sfr_bitfield PL13 : 1; /* Pad Level Selection for Port 15 Pin 13 */
     sfr_bitfield PD14 : 3; /* Pad Driver Mode for Port 15 Pin 14 */
     sfr_bitfield PL14 : 1; /* Pad Level Selection for Port 15 Pin 14 */
     sfr_bitfield PD15 : 3; /* Pad Driver Mode for Port 15 Pin 15 */
     sfr_bitfield PL15 : 1; /* Pad Level Selection for Port 15 Pin 15 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P15_PDR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC0 : 5; /* Port Control for Port n Pin 0 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC1 : 5; /* Port Control for Port n Pin 1 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC2 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC3 : 5; /* Port Control for Port n Pin 3 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P20_IOCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC4 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC5 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC6 : 5; /* Port Control for Port 20 Pin 6 to 7 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC7 : 5; /* Port Control for Port 20 Pin 6 to 7 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P20_IOCR4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC12 : 5; /* Port Control for Port 20 Pin 12 to 14 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC13 : 5; /* Port Control for Port 20 Pin 12 to 14 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC14 : 5; /* Port Control for Port 20 Pin 12 to 14 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC15 : 5; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P20_IOCR12_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Pad Driver Mode for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PL0 : 1; /* Pad Level Selection for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PD1 : 3; /* Pad Driver Mode for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PL1 : 1; /* Pad Level Selection for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PD2 : 3; /* Reserved */
     sfr_bitfield PL2 : 1; /* Reserved */
     sfr_bitfield PD3 : 3; /* Pad Driver Mode for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PL3 : 1; /* Pad Level Selection for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PD4 : 3; /* Reserved */
     sfr_bitfield PL4 : 1; /* Reserved */
     sfr_bitfield PD5 : 3; /* Reserved */
     sfr_bitfield PL5 : 1; /* Reserved */
     sfr_bitfield PD6 : 3; /* Pad Driver Mode for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PL6 : 1; /* Pad Level Selection for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PD7 : 3; /* Pad Driver Mode for Port 20 Pin 0 to 1, 3, 6 to 7 */
     sfr_bitfield PL7 : 1; /* Pad Level Selection for Port 20 Pin 0 to 1, 3, 6 to 7 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P20_PDR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD8 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL8 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD9 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL9 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD10 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL10 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD11 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL11 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD12 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL12 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD13 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL13 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD14 : 3; /* Pad Driver Mode for Port 20 Pin 8 to 14 */
     sfr_bitfield PL14 : 1; /* Pad Level Selection for Port 20 Pin 8 to 14 */
     sfr_bitfield PD15 : 3; /* Reserved */
     sfr_bitfield PL15 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P20_PDR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield RDIS_CTRL : 1; /* LVDS RX_DIS controller */
     sfr_bitfield RX_DIS : 1; /* Disable Receive LVDS */
     sfr_bitfield TERM : 1; /* Select Receiver Termination Mode */
     sfr_bitfield LRXTERM : 5; /* LVDS RX Poly-resistor configuration value */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P21_LPCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 8; /* reserved */
     sfr_bitfield LVDSR : 1; /* Special reduced LVDS electrical signaling mode */
     sfr_bitfield LVDSRL : 1; /* LVDS IEEE electrical signaling mode */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield TDIS_CTRL : 1; /* LVDS TX_DIS controller */
     sfr_bitfield TX_DIS : 1; /* Disable Transmit LVDS */
     sfr_bitfield TX_PD : 1; /* LVDS Power Down */
     sfr_bitfield TX_PWDPD : 1; /* Disable TX Power down pull down. */
     sfr_bitfield  : 16; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P21_LPCR2_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD8 : 3; /* Pad Driver Mode for Port 22 Pin 8 to 11 */
     sfr_bitfield PL8 : 1; /* Pad Level Selection for Port 22 Pin 8 to 11 */
     sfr_bitfield PD9 : 3; /* Pad Driver Mode for Port 22 Pin 8 to 11 */
     sfr_bitfield PL9 : 1; /* Pad Level Selection for Port 22 Pin 8 to 11 */
     sfr_bitfield PD10 : 3; /* Pad Driver Mode for Port 22 Pin 8 to 11 */
     sfr_bitfield PL10 : 1; /* Pad Level Selection for Port 22 Pin 8 to 11 */
     sfr_bitfield PD11 : 3; /* Pad Driver Mode for Port 22 Pin 8 to 11 */
     sfr_bitfield PL11 : 1; /* Pad Level Selection for Port 22 Pin 8 to 11 */
    /* const */ sfr_bitfield PD12 : 3; /* Reserved */
    /* const */ sfr_bitfield PL12 : 1; /* Reserved */
    /* const */ sfr_bitfield PD13 : 3; /* Reserved */
    /* const */ sfr_bitfield PL13 : 1; /* Reserved */
    /* const */ sfr_bitfield PD14 : 3; /* Reserved */
    /* const */ sfr_bitfield PL14 : 1; /* Reserved */
    /* const */ sfr_bitfield PD15 : 3; /* Reserved */
    /* const */ sfr_bitfield PL15 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P22_PDR1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC0 : 5; /* Port Control for Port 26 Pin 0 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC1 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC2 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC3 : 5; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P26_IOCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Pad Driver Mode for Port 12 Pin 0 */
     sfr_bitfield PL0 : 1; /* Pad Level Selection for Port 12 Pin 0 */
     sfr_bitfield PD1 : 3; /* Reserved */
     sfr_bitfield PL1 : 1; /* Reserved */
     sfr_bitfield PD2 : 3; /* Reserved */
     sfr_bitfield PL2 : 1; /* Reserved */
     sfr_bitfield PD3 : 3; /* Reserved */
     sfr_bitfield PL3 : 1; /* Reserved */
    /* const */ sfr_bitfield PD4 : 3; /* Reserved */
    /* const */ sfr_bitfield PL4 : 1; /* Reserved */
    /* const */ sfr_bitfield PD5 : 3; /* Reserved */
    /* const */ sfr_bitfield PL5 : 1; /* Reserved */
    /* const */ sfr_bitfield PD6 : 3; /* Reserved */
    /* const */ sfr_bitfield PL6 : 1; /* Reserved */
    /* const */ sfr_bitfield PD7 : 3; /* Reserved */
    /* const */ sfr_bitfield PL7 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P26_PDR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC0 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC1 : 5; /* Port Control for Port n Pin 1 to 3 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC2 : 5; /* Port Control for Port n Pin 1 to 3 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC3 : 5; /* Port Control for Port n Pin 1 to 3 */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P34_IOCR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC4 : 5; /* Port Control for Port n Pin 4 to 5 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC5 : 5; /* Port Control for Port n Pin 4 to 5 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC6 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC7 : 5; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P34_IOCR4_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PD0 : 3; /* Reserved */
     sfr_bitfield PL0 : 1; /* Reserved */
     sfr_bitfield PD1 : 3; /* Pad Driver Mode for Port 34 Pin 1 to 5 */
     sfr_bitfield PL1 : 1; /* Pad Level Selection for Port 34 Pin 1 to 5 */
     sfr_bitfield PD2 : 3; /* Pad Driver Mode for Port 34 Pin 1 to 5 */
     sfr_bitfield PL2 : 1; /* Pad Level Selection for Port 34 Pin 1 to 5 */
     sfr_bitfield PD3 : 3; /* Pad Driver Mode for Port 34 Pin 1 to 5 */
     sfr_bitfield PL3 : 1; /* Pad Level Selection for Port 34 Pin 1 to 5 */
     sfr_bitfield PD4 : 3; /* Pad Driver Mode for Port 34 Pin 1 to 5 */
     sfr_bitfield PL4 : 1; /* Pad Level Selection for Port 34 Pin 1 to 5 */
     sfr_bitfield PD5 : 3; /* Pad Driver Mode for Port 34 Pin 1 to 5 */
     sfr_bitfield PL5 : 1; /* Pad Level Selection for Port 34 Pin 1 to 5 */
     sfr_bitfield PD6 : 3; /* Reserved */
     sfr_bitfield PL6 : 1; /* Reserved */
     sfr_bitfield PD7 : 3; /* Reserved */
     sfr_bitfield PL7 : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P34_PDR0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC8 : 5; /* Port Control for Port 40 Pin 8 to 9 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC9 : 5; /* Port Control for Port 40 Pin 8 to 9 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC10 : 5; /* Reserved */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC11 : 5; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P40_IOCR8_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC12 : 5; /* Port Control for Port 40 Pin 12 to 14 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC13 : 5; /* Port Control for Port 40 Pin 12 to 14 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC14 : 5; /* Port Control for Port 40 Pin 12 to 14 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield PC15 : 5; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P40_IOCR12_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SEL1 : 1; /* Output Select for Pin 1 */
     sfr_bitfield SEL2 : 1; /* Output Select for Pin 2 */
     sfr_bitfield SEL3 : 1; /* Output Select for Pin 3 */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield SEL5 : 1; /* Output Select for Pin 5 */
     sfr_bitfield  : 25; /* reserved */
    /* const */ sfr_bitfield LCK : 1; /* Lock Status */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} P40_PCSR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield SRPN : 8; /* Service Request Priority Number */
     sfr_bitfield  : 2; /* reserved */
     sfr_bitfield SRE : 1; /* Service Request Enable */
     sfr_bitfield TOS : 2; /* Type of Service Control */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield ECC : 6; /* ECC */
     sfr_bitfield  : 2; /* reserved */
    /* const */ sfr_bitfield SRR : 1; /* Service Request Flag */
     sfr_bitfield CLRR : 1; /* Request Clear Bit */
     sfr_bitfield SETR : 1; /* Request Set Bit */
    /* const */ sfr_bitfield IOV : 1; /* Interrupt Trigger Overflow Bit */
     sfr_bitfield IOVCLR : 1; /* Interrupt Trigger Overflow Clear Bit */
    /* const */ sfr_bitfield SWS : 1; /* SW Sticky Bit */
     sfr_bitfield SWSCLR : 1; /* SW Sticky Clear Bit */
    /* const */ sfr_bitfield Reserved : 1; /* Reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} SRC_CPU0SBSRC_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DISR : 1; /* Module Disable Request Bit */
    /* const */ sfr_bitfield DISS : 1; /* Module Disable Status Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield EDIS : 1; /* Sleep Mode Enable Control */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_CLC_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield MODREV : 8; /* Module Revision Number */
    /* const */ sfr_bitfield MODTYPE : 8; /* Module Type */
    /* const */ sfr_bitfield MODNUM : 16; /* Module Number Value */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_ID_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [31:0] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM0_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [35:4] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM1_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [39:8] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM2_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [43:12] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM3_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [47:16] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM4_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [51:20] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM5_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STM : 32; /* System Timer Bits [63:32] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_TIM6_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield STMCAP : 32; /* Captured System Timer Bits [63:32] */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_CAP_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CMPVAL : 32; /* Compare Value of Compare Register x */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_CMP0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield MSIZE0 : 5; /* Compare Register Size for CMP0 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield MSTART0 : 5; /* Start Bit Location for CMP0 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield MSIZE1 : 5; /* Compare Register Size for CMP1 */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield MSTART1 : 5; /* Start Bit Location for CMP1 */
     sfr_bitfield  : 3; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_CMCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CMP0EN : 1; /* Compare Register CMP0 Interrupt Enable Control */
    /* const */ sfr_bitfield CMP0IR : 1; /* Compare Register CMP0 Interrupt Request Flag */
     sfr_bitfield CMP0OS : 1; /* Compare Register CMP0 Interrupt Output Selection */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield CMP1EN : 1; /* Compare Register CMP1 Interrupt Enable Control */
    /* const */ sfr_bitfield CMP1IR : 1; /* Compare Register CMP1 Interrupt Request Flag */
     sfr_bitfield CMP1OS : 1; /* Compare Register CMP1 Interrupt Output Selection */
     sfr_bitfield  : 25; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_ICR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CMP0IRR : 1; /* Reset Compare Register CMP0 Interrupt Flag */
     sfr_bitfield CMP0IRS : 1; /* Set Compare Register CMP0 Interrupt Flag */
     sfr_bitfield CMP1IRR : 1; /* Reset Compare Register CMP1 Interrupt Flag */
     sfr_bitfield CMP1IRS : 1; /* Set Compare Register CMP1 Interrupt Flag */
     sfr_bitfield  : 28; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_ISCR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 24; /* reserved */
     sfr_bitfield SUS : 4; /* OCDS Suspend Control */
     sfr_bitfield SUS_P : 1; /* SUS Write Protection */
    /* const */ sfr_bitfield SUSSTA : 1; /* Suspend State */
     sfr_bitfield  : 2; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_OCS_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield RST : 1; /* Kernel Reset */
     sfr_bitfield RSTSTAT : 1; /* Kernel Reset Status */
     sfr_bitfield  : 30; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_KRST0_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield RST : 1; /* Kernel Reset */
     sfr_bitfield  : 31; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_KRST1_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CLR : 1; /* Kernel Reset Status Clear */
     sfr_bitfield  : 31; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} STM0_KRSTCLR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield ALTI : 3; /* Alternate Input Select */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield DEPTH : 6; /* Digital Glitch Filter Depth */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield CTS : 2; /* CTS Select */
     sfr_bitfield  : 7; /* reserved */
     sfr_bitfield RCPOL : 1; /* RTS CTS Polarity */
     sfr_bitfield CPOL : 1; /* Clock Polarity in Synchronous Mode */
     sfr_bitfield SPOL : 1; /* Slave Polarity in Synchronous Mode */
     sfr_bitfield LB : 1; /* Loop Back Mode */
     sfr_bitfield CTSEN : 1; /* Input Signal CTS Enable */
    /* const */ sfr_bitfield RXM : 1; /* Receive Monitor */
    /* const */ sfr_bitfield TXM : 1; /* Transmit Monitor */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_IOCR_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield MODREV : 8; /* Module Revision Number */
    /* const */ sfr_bitfield MODTYPE : 8; /* Module Type */
    /* const */ sfr_bitfield MODNUMBER : 16; /* Module Number Value */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_ID_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield FLUSH : 1; /* Flush the transmit FIFO */
     sfr_bitfield ENO : 1; /* Transmit FIFO Outlet Enable */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield INW : 2; /* Transmit FIFO Inlet Width */
     sfr_bitfield INTLEVEL : 4; /* FIFO Interrupt Level */
     sfr_bitfield  : 4; /* reserved */
    /* const */ sfr_bitfield FILL : 5; /* FIFO Filling Level */
     sfr_bitfield  : 11; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_TXFIFOCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield FLUSH : 1; /* Flush the receive FIFO */
     sfr_bitfield ENI : 1; /* Receive FIFO Inlet Enable */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield OUTW : 2; /* Receive FIFO Outlet Width */
     sfr_bitfield INTLEVEL : 4; /* FIFO Interrupt Level */
     sfr_bitfield  : 4; /* reserved */
    /* const */ sfr_bitfield FILL : 5; /* FIFO Filling Level */
     sfr_bitfield  : 10; /* reserved */
     sfr_bitfield BUF : 1; /* Receive Buffer Mode */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_RXFIFOCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield PRESCALER : 12; /* Prescaling of the Fractional Divider */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield OVERSAMPLING : 4; /* Oversampling Factor */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield SAMPLEPOINT : 4; /* Sample Point Position */
     sfr_bitfield  : 3; /* reserved */
     sfr_bitfield SM : 1; /* Sample Mode */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_BITCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield IDLE : 3; /* Duration of the IDLE delay */
     sfr_bitfield STOP : 3; /* Number of Stop Bits */
     sfr_bitfield LEAD : 3; /* Duration of the Leading Delay */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield MODE : 2; /* Mode Selection */
     sfr_bitfield  : 10; /* reserved */
     sfr_bitfield MSB : 1; /* Shift Direction */
     sfr_bitfield CEN : 1; /* Collision Detection Enable */
     sfr_bitfield PEN : 1; /* Parity Enable */
     sfr_bitfield ODD : 1; /* Parity Type */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_FRAMECON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DATLEN : 4; /* Data Length */
     sfr_bitfield  : 9; /* reserved */
     sfr_bitfield HO : 1; /* Header Only */
     sfr_bitfield RM : 1; /* Response Mode */
     sfr_bitfield CSM : 1; /* Checksum Mode */
     sfr_bitfield RESPONSE : 8; /* Response Timeout Threshold Value */
     sfr_bitfield  : 8; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_DATCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DENOMINATOR : 12; /* Denominator */
     sfr_bitfield  : 4; /* reserved */
     sfr_bitfield NUMERATOR : 12; /* Numerator */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_BRG_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield LOWERLIMIT : 8; /* Lower Limit */
     sfr_bitfield UPPERLIMIT : 8; /* Upper Limit */
    /* const */ sfr_bitfield MEASURED : 12; /* Measured Value of the Denominator */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_BRD_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield  : 23; /* reserved */
     sfr_bitfield CSI : 1; /* Checksum Injection */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield CSEN : 1; /* Hardware Checksum Enable */
     sfr_bitfield MS : 1; /* Master Slave Mode */
     sfr_bitfield ABD : 1; /* Autobaud Detection */
     sfr_bitfield  : 4; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_LINCON_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield BREAK : 6; /* Break Pulse Generation and Detection */
     sfr_bitfield  : 26; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_LINBTIMER_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield HEADER : 8; /* Header Timeout Threshold Value */
     sfr_bitfield  : 24; /* reserved */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_LINHTIMER_type;
typedef volatile union
{
	struct
	{
    /* const */ sfr_bitfield TH : 1; /* Transmit Header End Flag */
    /* const */ sfr_bitfield TR : 1; /* Transmit Response End Flag */
    /* const */ sfr_bitfield RH : 1; /* Receive Header End Flag */
    /* const */ sfr_bitfield RR : 1; /* Receive Response End Flag */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield FED : 1; /* Falling Edge from Level 1 to Level 0 Detected */
    /* const */ sfr_bitfield RED : 1; /* Rising Edge from Level 0 to Level 1 Detected */
     sfr_bitfield  : 6; /* reserved */
    /* const */ sfr_bitfield TWRQ : 1; /* Transmit Wake Request Flag */
    /* const */ sfr_bitfield THRQ : 1; /* Transmit Header Request Flag */
    /* const */ sfr_bitfield TRRQ : 1; /* Transmit Response Request Flag */
    /* const */ sfr_bitfield PE : 1; /* Parity Error Flag */
    /* const */ sfr_bitfield TC : 1; /* Transmission Completed Flag */
    /* const */ sfr_bitfield FE : 1; /* Framing Error Flag */
    /* const */ sfr_bitfield HT : 1; /* Header Timeout Flag */
    /* const */ sfr_bitfield RT : 1; /* Response Timeout Flag */
    /* const */ sfr_bitfield BD : 1; /* Break Detected Flag */
    /* const */ sfr_bitfield LP : 1; /* LIN Parity Error Flag */
    /* const */ sfr_bitfield LA : 1; /* LIN Autobaud Detection Error Flag */
    /* const */ sfr_bitfield LC : 1; /* LIN Checksum Error Flag */
    /* const */ sfr_bitfield CE : 1; /* Collision Detection Error Flag */
    /* const */ sfr_bitfield RFO : 1; /* Receive FIFO Overflow Flag */
    /* const */ sfr_bitfield RFU : 1; /* Receive FIFO Underflow Flag */
    /* const */ sfr_bitfield RFL : 1; /* Receive FIFO Level Flag */
     sfr_bitfield  : 1; /* reserved */
    /* const */ sfr_bitfield TFO : 1; /* Transmit FIFO Overflow Flag */
    /* const */ sfr_bitfield TFL : 1; /* Transmit FIFO Level Flag */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_FLAGS_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield THS : 1; /* Flag Set Bit */
     sfr_bitfield TRS : 1; /* Flag Set Bit */
     sfr_bitfield RHS : 1; /* Flag Set Bit */
     sfr_bitfield RRS : 1; /* Flag Set Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield FEDS : 1; /* Flag Set Bit */
     sfr_bitfield REDS : 1; /* Flag Set Bit */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield TWRQS : 1; /* Flag Set Bit */
     sfr_bitfield THRQS : 1; /* Flag Set Bit */
     sfr_bitfield TRRQS : 1; /* Flag Set Bit */
     sfr_bitfield PES : 1; /* Flag Set Bit */
     sfr_bitfield TCS : 1; /* Flag Set Bit */
     sfr_bitfield FES : 1; /* Flag Set Bit */
     sfr_bitfield HTS : 1; /* Flag Set Bit */
     sfr_bitfield RTS : 1; /* Flag Set Bit */
     sfr_bitfield BDS : 1; /* Flag Set Bit */
     sfr_bitfield LPS : 1; /* Flag Set Bit */
     sfr_bitfield LAS : 1; /* Flag Set Bit */
     sfr_bitfield LCS : 1; /* Flag Set Bit */
     sfr_bitfield CES : 1; /* Flag Set Bit */
     sfr_bitfield RFOS : 1; /* Flag Set Bit */
     sfr_bitfield RFUS : 1; /* Flag Set Bit */
     sfr_bitfield RFLS : 1; /* Flag Set Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield TFOS : 1; /* Flag Set Bit */
     sfr_bitfield TFLS : 1; /* Flag Set Bit */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_FLAGSSET_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield THC : 1; /* Flag Clear Bit */
     sfr_bitfield TRC : 1; /* Flag Clear Bit */
     sfr_bitfield RHC : 1; /* Flag Clear Bit */
     sfr_bitfield RRC : 1; /* Flag Clear Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield FEDC : 1; /* Flag Clear Bit */
     sfr_bitfield REDC : 1; /* Flag Clear Bit */
     sfr_bitfield  : 6; /* reserved */
     sfr_bitfield TWRQC : 1; /* Flag Clear Bit */
     sfr_bitfield THRQC : 1; /* Flag Clear Bit */
     sfr_bitfield TRRQC : 1; /* Flag Clear Bit */
     sfr_bitfield PEC : 1; /* Flag Clear Bit */
     sfr_bitfield TCC : 1; /* Flag Clear Bit */
     sfr_bitfield FEC : 1; /* Flag Clear Bit */
     sfr_bitfield HTC : 1; /* Flag Clear Bit */
     sfr_bitfield RTC : 1; /* Flag Clear Bit */
     sfr_bitfield BDC : 1; /* Flag Clear Bit */
     sfr_bitfield LPC : 1; /* Flag Clear Bit */
     sfr_bitfield LAC : 1; /* Flag Clear Bit */
     sfr_bitfield LCC : 1; /* Flag Clear Bit */
     sfr_bitfield CEC : 1; /* Flag Clear Bit */
     sfr_bitfield RFOC : 1; /* Flag Clear Bit */
     sfr_bitfield RFUC : 1; /* Flag Clear Bit */
     sfr_bitfield RFLC : 1; /* Flag Clear Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield TFOC : 1; /* Flag Clear Bit */
     sfr_bitfield TFLC : 1; /* Flag Clear Bit */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_FLAGSCLEAR_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield THE : 1; /* Flag Enable Bit */
     sfr_bitfield TRE : 1; /* Flag Enable Bit */
     sfr_bitfield RHE : 1; /* Flag Enable Bit */
     sfr_bitfield RRE : 1; /* Flag Enable Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield FEDE : 1; /* Flag Enable Bit */
     sfr_bitfield REDE : 1; /* Flag Enable Bit */
     sfr_bitfield  : 9; /* reserved */
     sfr_bitfield PEE : 1; /* Flag Enable Bit */
     sfr_bitfield TCE : 1; /* Flag Enable Bit */
     sfr_bitfield FEE : 1; /* Flag Enable Bit */
     sfr_bitfield HTE : 1; /* Flag Enable Bit */
     sfr_bitfield RTE : 1; /* Flag Enable Bit */
     sfr_bitfield BDE : 1; /* Flag Enable Bit */
     sfr_bitfield LPE : 1; /* Flag Enable Bit */
     sfr_bitfield ABE : 1; /* Flag Enable Bit */
     sfr_bitfield LCE : 1; /* Flag Enable Bit */
     sfr_bitfield CEE : 1; /* Flag Enable Bit */
     sfr_bitfield RFOE : 1; /* Flag Enable Bit */
     sfr_bitfield RFUE : 1; /* Flag Enable Bit */
     sfr_bitfield RFLE : 1; /* Flag Enable Bit */
     sfr_bitfield  : 1; /* reserved */
     sfr_bitfield TFOE : 1; /* Flag Enable Bit */
     sfr_bitfield TFLE : 1; /* Flag Enable Bit */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_FLAGSENABLE_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield DATA : 32; /* Data */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_TXDATA_type;
typedef volatile union
{
	struct
	{
     sfr_bitfield CLKSEL : 5; /* Baud Rate Logic Clock Select */
     sfr_bitfield  : 26; /* reserved */
    /* const */ sfr_bitfield CON : 1; /* Clock On Flag */
  } B;
  signed_sfr_access_type I;
  unsigned_sfr_access_type U;
} ASCLIN0_CSR_type;
#define XBAR_ID	(*( XBAR_ID_type *) 0xF8700408U)	/* Module Identification Register */
#define XBAR_DBSAT	(*( XBAR_DBSAT_type *) 0xF870040CU)	/* Debug Trigger Event Status Register */
#define XBAR_INTSAT	(*( XBAR_INTSAT_type *) 0xF8700410U)	/* Arbiter Interrupt Status Register */
#define XBAR_IDINTSAT	(*( XBAR_IDINTSAT_type *) 0xF8700414U)	/* Transaction ID Interrupt Status Register */
#define XBAR_IDINTEN	(*( XBAR_IDINTEN_type *) 0xF8700418U)	/* Transaction ID Interrupt Enable Register */
#define XBAR_EXTCOND	(*( XBAR_EXTCOND_type *) 0xF8700000U)	/* External Control Register D */
#define XBAR_ARBCON0	(*( XBAR_ARBCON0_type *) 0xF8700044U)	/* Arbiter Control Register 0 */
#define XBAR_ARBCON1	(*( XBAR_ARBCON0_type *) 0xF8700084U)	/* Arbiter Control Register 1 */
#define XBAR_ARBCON2	(*( XBAR_ARBCON0_type *) 0xF87000C4U)	/* Arbiter Control Register 2 */
#define XBAR_ARBCON4	(*( XBAR_ARBCON0_type *) 0xF8700144U)	/* Arbiter Control Register 4 */
#define XBAR_ARBCON5	(*( XBAR_ARBCON0_type *) 0xF8700184U)	/* Arbiter Control Register 5 */
#define XBAR_ARBCON6	(*( XBAR_ARBCON0_type *) 0xF87001C4U)	/* Arbiter Control Register 6 */
#define XBAR_ARBCON7	(*( XBAR_ARBCON0_type *) 0xF8700204U)	/* Arbiter Control Register 7 */
#define XBAR_ARBCON8	(*( XBAR_ARBCON0_type *) 0xF8700244U)	/* Arbiter Control Register 8 */
#define XBAR_ARBCON9	(*( XBAR_ARBCON0_type *) 0xF8700284U)	/* Arbiter Control Register 9 */
#define XBAR_ARBCON10	(*( XBAR_ARBCON0_type *) 0xF87002C4U)	/* Arbiter Control Register 10 */
#define XBAR_ARBCOND	(*( XBAR_ARBCON0_type *) 0xF8700004U)	/* Arbiter Control Register D */
#define XBAR_PRIOH0	(*( XBAR_PRIOH0_type *) 0xF8700048U)	/* Arbiter Priority Register 0 */
#define XBAR_PRIOH1	(*( XBAR_PRIOH0_type *) 0xF8700088U)	/* Arbiter Priority Register 1 */
#define XBAR_PRIOH2	(*( XBAR_PRIOH0_type *) 0xF87000C8U)	/* Arbiter Priority Register 2 */
#define XBAR_PRIOH4	(*( XBAR_PRIOH0_type *) 0xF8700148U)	/* Arbiter Priority Register 4 */
#define XBAR_PRIOH5	(*( XBAR_PRIOH0_type *) 0xF8700188U)	/* Arbiter Priority Register 5 */
#define XBAR_PRIOH6	(*( XBAR_PRIOH0_type *) 0xF87001C8U)	/* Arbiter Priority Register 6 */
#define XBAR_PRIOH7	(*( XBAR_PRIOH0_type *) 0xF8700208U)	/* Arbiter Priority Register 7 */
#define XBAR_PRIOH8	(*( XBAR_PRIOH0_type *) 0xF8700248U)	/* Arbiter Priority Register 8 */
#define XBAR_PRIOH9	(*( XBAR_PRIOH0_type *) 0xF8700288U)	/* Arbiter Priority Register 9 */
#define XBAR_PRIOH10	(*( XBAR_PRIOH0_type *) 0xF87002C8U)	/* Arbiter Priority Register 10 */
#define XBAR_PRIOHD	(*( XBAR_PRIOH0_type *) 0xF8700008U)	/* Arbiter Priority Register D */
#define XBAR_PRIOLD	(*( XBAR_PRIOLD_type *) 0xF870000CU)	/* Arbiter Priority Register D */
#define XBAR_PRIOL0	(*( XBAR_PRIOLD_type *) 0xF870004CU)	/* Arbiter Priority Register 0 */
#define XBAR_PRIOL1	(*( XBAR_PRIOLD_type *) 0xF870008CU)	/* Arbiter Priority Register 1 */
#define XBAR_PRIOL2	(*( XBAR_PRIOLD_type *) 0xF87000CCU)	/* Arbiter Priority Register 2 */
#define XBAR_PRIOL4	(*( XBAR_PRIOLD_type *) 0xF870014CU)	/* Arbiter Priority Register 4 */
#define XBAR_PRIOL5	(*( XBAR_PRIOLD_type *) 0xF870018CU)	/* Arbiter Priority Register 5 */
#define XBAR_PRIOL6	(*( XBAR_PRIOLD_type *) 0xF87001CCU)	/* Arbiter Priority Register 6 */
#define XBAR_PRIOL7	(*( XBAR_PRIOLD_type *) 0xF870020CU)	/* Arbiter Priority Register 7 */
#define XBAR_PRIOL8	(*( XBAR_PRIOLD_type *) 0xF870024CU)	/* Arbiter Priority Register 8 */
#define XBAR_PRIOL9	(*( XBAR_PRIOLD_type *) 0xF870028CU)	/* Arbiter Priority Register 9 */
#define XBAR_PRIOL10	(*( XBAR_PRIOLD_type *) 0xF87002CCU)	/* Arbiter Priority Register 10 */
#define XBAR_ERRADDRD	(*( XBAR_ERRADDRD_type *) 0xF8700010U)	/* Error/Debug Address Capture Register D */
#define XBAR_ERRADDR0	(*( XBAR_ERRADDRD_type *) 0xF8700050U)	/* Error/Debug Address Capture Register 0 */
#define XBAR_ERRADDR1	(*( XBAR_ERRADDRD_type *) 0xF8700090U)	/* Error/Debug Address Capture Register 1 */
#define XBAR_ERRADDR2	(*( XBAR_ERRADDRD_type *) 0xF87000D0U)	/* Error/Debug Address Capture Register 2 */
#define XBAR_ERRADDR4	(*( XBAR_ERRADDRD_type *) 0xF8700150U)	/* Error/Debug Address Capture Register 4 */
#define XBAR_ERRADDR5	(*( XBAR_ERRADDRD_type *) 0xF8700190U)	/* Error/Debug Address Capture Register 5 */
#define XBAR_ERRADDR6	(*( XBAR_ERRADDRD_type *) 0xF87001D0U)	/* Error/Debug Address Capture Register 6 */
#define XBAR_ERRADDR7	(*( XBAR_ERRADDRD_type *) 0xF8700210U)	/* Error/Debug Address Capture Register 7 */
#define XBAR_ERRADDR8	(*( XBAR_ERRADDRD_type *) 0xF8700250U)	/* Error/Debug Address Capture Register 8 */
#define XBAR_ERRADDR9	(*( XBAR_ERRADDRD_type *) 0xF8700290U)	/* Error/Debug Address Capture Register 9 */
#define XBAR_ERRADDR10	(*( XBAR_ERRADDRD_type *) 0xF87002D0U)	/* Error/Debug Address Capture Register 10 */
#define XBAR_ERR0	(*( XBAR_ERR0_type *) 0xF8700054U)	/* Error/Debug Capture Register 0 */
#define XBAR_ERR1	(*( XBAR_ERR0_type *) 0xF8700094U)	/* Error/Debug Capture Register 1 */
#define XBAR_ERR2	(*( XBAR_ERR0_type *) 0xF87000D4U)	/* Error/Debug Capture Register 2 */
#define XBAR_ERR4	(*( XBAR_ERR0_type *) 0xF8700154U)	/* Error/Debug Capture Register 4 */
#define XBAR_ERR5	(*( XBAR_ERR0_type *) 0xF8700194U)	/* Error/Debug Capture Register 5 */
#define XBAR_ERR6	(*( XBAR_ERR0_type *) 0xF87001D4U)	/* Error/Debug Capture Register 6 */
#define XBAR_ERR7	(*( XBAR_ERR0_type *) 0xF8700214U)	/* Error/Debug Capture Register 7 */
#define XBAR_ERR8	(*( XBAR_ERR0_type *) 0xF8700254U)	/* Error/Debug Capture Register 8 */
#define XBAR_ERR9	(*( XBAR_ERR0_type *) 0xF8700294U)	/* Error/Debug Capture Register 9 */
#define XBAR_ERR10	(*( XBAR_ERR0_type *) 0xF87002D4U)	/* Error/Debug Capture Register 10 */
#define XBAR_ERRD	(*( XBAR_ERR0_type *) 0xF8700014U)	/* Error/Debug Capture Register D */
#define XBAR_DBCON0	(*( XBAR_DBCON0_type *) 0xF8700058U)	/* Debug Control Register 0 */
#define XBAR_DBCON1	(*( XBAR_DBCON0_type *) 0xF8700098U)	/* Debug Control Register 1 */
#define XBAR_DBCON2	(*( XBAR_DBCON0_type *) 0xF87000D8U)	/* Debug Control Register 2 */
#define XBAR_DBCON4	(*( XBAR_DBCON0_type *) 0xF8700158U)	/* Debug Control Register 4 */
#define XBAR_DBCON5	(*( XBAR_DBCON0_type *) 0xF8700198U)	/* Debug Control Register 5 */
#define XBAR_DBCON6	(*( XBAR_DBCON0_type *) 0xF87001D8U)	/* Debug Control Register 6 */
#define XBAR_DBCON7	(*( XBAR_DBCON0_type *) 0xF8700218U)	/* Debug Control Register 7 */
#define XBAR_DBCON8	(*( XBAR_DBCON0_type *) 0xF8700258U)	/* Debug Control Register 8 */
#define XBAR_DBCON9	(*( XBAR_DBCON0_type *) 0xF8700298U)	/* Debug Control Register 9 */
#define XBAR_DBCON10	(*( XBAR_DBCON0_type *) 0xF87002D8U)	/* Debug Control Register 10 */
#define XBAR_DBCOND	(*( XBAR_DBCON0_type *) 0xF8700018U)	/* Debug Control Register D */
#define XBAR_DBADDD	(*( XBAR_DBADDD_type *) 0xF870001CU)	/* Debug Address Register D */
#define XBAR_DBADD0	(*( XBAR_DBADD0_type *) 0xF870005CU)	/* Debug Address Register 0 */
#define XBAR_DBADD1	(*( XBAR_DBADD1_type *) 0xF870009CU)	/* Debug Address Register 1 */
#define XBAR_DBADD2	(*( XBAR_DBADD2_type *) 0xF87000DCU)	/* Debug Address Register 2 */
#define XBAR_DBADD4	(*( XBAR_DBADD4_type *) 0xF870015CU)	/* Debug Address Register 4 */
#define XBAR_DBADD5	(*( XBAR_DBADD4_type *) 0xF870019CU)	/* Debug Address Register 5 */
#define XBAR_DBADD6	(*( XBAR_DBADD6_type *) 0xF87001DCU)	/* Debug Address Register 6 */
#define XBAR_DBADD7	(*( XBAR_DBADD7_type *) 0xF870021CU)	/* Debug Address Register 7 */
#define XBAR_DBADD8	(*( XBAR_DBADD8_type *) 0xF870025CU)	/* Debug Address Register 8 */
#define XBAR_DBADD9	(*( XBAR_DBADD9_type *) 0xF870029CU)	/* Debug Address Register 9 */
#define XBAR_DBADD10	(*( XBAR_DBADD10_type *) 0xF87002DCU)	/* Debug Address Register 10 */
#define XBAR_DBMADDD	(*( XBAR_DBMADDD_type *) 0xF8700020U)	/* Debug Mask Address Register D */
#define XBAR_DBMADD0	(*( XBAR_DBMADD0_type *) 0xF8700060U)	/* Debug Mask Address Register 0 */
#define XBAR_DBMADD1	(*( XBAR_DBMADD1_type *) 0xF87000A0U)	/* Debug Mask Address Register 1 */
#define XBAR_DBMADD2	(*( XBAR_DBMADD2_type *) 0xF87000E0U)	/* Debug Mask Address Register 2 */
#define XBAR_DBMADD4	(*( XBAR_DBADD4_type *) 0xF8700160U)	/* Debug Mask Address Register 4 */
#define XBAR_DBMADD5	(*( XBAR_DBADD4_type *) 0xF87001A0U)	/* Debug Mask Address Register 5 */
#define XBAR_DBMADD6	(*( XBAR_DBMADD6_type *) 0xF87001E0U)	/* Debug Mask Address Register 6 */
#define XBAR_DBMADD7	(*( XBAR_DBMADD7_type *) 0xF8700220U)	/* Debug Mask Address Register 7 */
#define XBAR_DBMADD8	(*( XBAR_DBMADD7_type *) 0xF8700260U)	/* Debug Mask Address Register 8 */
#define XBAR_DBMADD9	(*( XBAR_DBMADD7_type *) 0xF87002A0U)	/* Debug Mask Address Register 9 */
#define XBAR_DBMADD10	(*( XBAR_DBMADD7_type *) 0xF87002E0U)	/* Debug Mask Address Register 10 */
#define XBAR_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF87004FCU)	/* Access Enable Register 0 */
#define XBAR_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF87004F8U)	/* Access Enable Register 1 */
#define CPU0_TASK_ASI	(*( CPU0_TASK_ASI_type *) 0xF8818004U)	/* CPU0 Task Address Space Identifier Register */
#define CPU1_TASK_ASI	(*( CPU0_TASK_ASI_type *) 0xF8838004U)	/* CPU1 Task Address Space Identifier Register */
#define CPU2_TASK_ASI	(*( CPU0_TASK_ASI_type *) 0xF8858004U)	/* CPU2 Task Address Space Identifier Register */
#define CPU0_PMA0	(*( CPU0_PMA0_type *) 0xF8818100U)	/* Data Access CacheabilityRegister */
#define CPU1_PMA0	(*( CPU0_PMA0_type *) 0xF8838100U)	/* Data Access CacheabilityRegister */
#define CPU2_PMA0	(*( CPU0_PMA0_type *) 0xF8858100U)	/* Data Access CacheabilityRegister */
#define CPU0_PMA1	(*( CPU0_PMA1_type *) 0xF8818104U)	/* Code Access CacheabilityRegister */
#define CPU1_PMA1	(*( CPU0_PMA1_type *) 0xF8838104U)	/* Code Access CacheabilityRegister */
#define CPU2_PMA1	(*( CPU0_PMA1_type *) 0xF8858104U)	/* Code Access CacheabilityRegister */
#define CPU0_PMA2	(*( CPU0_PMA2_type *) 0xF8818108U)	/* Peripheral Space Identifier register */
#define CPU1_PMA2	(*( CPU0_PMA2_type *) 0xF8838108U)	/* Peripheral Space Identifier register */
#define CPU2_PMA2	(*( CPU0_PMA2_type *) 0xF8858108U)	/* Peripheral Space Identifier register */
#define CPU0_SMACON	(*( CPU0_SMACON_type *) 0xF881900CU)	/* SIST Mode Access Control Register */
#define CPU1_SMACON	(*( CPU0_SMACON_type *) 0xF883900CU)	/* SIST Mode Access Control Register */
#define CPU2_SMACON	(*( CPU0_SMACON_type *) 0xF885900CU)	/* SIST Mode Access Control Register */
#define CPU0_DIEAR	(*( CPU0_DIEAR_type *) 0xF8819020U)	/* Data Integrity Error Address Register */
#define CPU1_DIEAR	(*( CPU0_DIEAR_type *) 0xF8839020U)	/* Data Integrity Error Address Register */
#define CPU2_DIEAR	(*( CPU0_DIEAR_type *) 0xF8859020U)	/* Data Integrity Error Address Register */
#define CPU0_DIETR	(*( CPU0_DIETR_type *) 0xF8819024U)	/* Data Integrity Error Trap Register */
#define CPU1_DIETR	(*( CPU0_DIETR_type *) 0xF8839024U)	/* Data Integrity Error Trap Register */
#define CPU2_DIETR	(*( CPU0_DIETR_type *) 0xF8859024U)	/* Data Integrity Error Trap Register */
#define CPU0_PCON1	(*( CPU0_PCON1_type *) 0xF8819204U)	/* Program Control 1 */
#define CPU1_PCON1	(*( CPU0_PCON1_type *) 0xF8839204U)	/* Program Control 1 */
#define CPU2_PCON1	(*( CPU0_PCON1_type *) 0xF8859204U)	/* Program Control 1 */
#define CPU0_PCON2	(*( CPU0_PCON2_type *) 0xF8819208U)	/* Program Control 2 */
#define CPU1_PCON2	(*( CPU0_PCON2_type *) 0xF8839208U)	/* Program Control 2 */
#define CPU2_PCON2	(*( CPU0_PCON2_type *) 0xF8859208U)	/* Program Control 2 */
#define CPU0_PCON0	(*( CPU0_PCON0_type *) 0xF881920CU)	/* Program Control 0 */
#define CPU1_PCON0	(*( CPU0_PCON0_type *) 0xF883920CU)	/* Program Control 0 */
#define CPU2_PCON0	(*( CPU0_PCON0_type *) 0xF885920CU)	/* Program Control 0 */
#define CPU0_PSTR	(*( CPU0_PSTR_type *) 0xF8819200U)	/* Program Synchronous Trap Register */
#define CPU1_PSTR	(*( CPU0_PSTR_type *) 0xF8839200U)	/* Program Synchronous Trap Register */
#define CPU2_PSTR	(*( CPU0_PSTR_type *) 0xF8859200U)	/* Program Synchronous Trap Register */
#define CPU0_DCON0	(*( CPU0_DCON0_type *) 0xF8819040U)	/* Data Memory Control Register */
#define CPU1_DCON0	(*( CPU0_DCON0_type *) 0xF8839040U)	/* Data Memory Control Register */
#define CPU2_DCON0	(*( CPU0_DCON0_type *) 0xF8859040U)	/* Data Memory Control Register */
#define CPU0_DCON2	(*( CPU0_DCON2_type *) 0xF8819000U)	/* Data Control Register 2 */
#define CPU1_DCON2	(*( CPU0_DCON2_type *) 0xF8839000U)	/* Data Control Register 2 */
#define CPU2_DCON2	(*( CPU0_DCON2_type *) 0xF8859000U)	/* Data Control Register 2 */
#define CPU0_DSTR	(*( CPU0_DSTR_type *) 0xF8819010U)	/* Data Synchronous Trap Register */
#define CPU1_DSTR	(*( CPU0_DSTR_type *) 0xF8839010U)	/* Data Synchronous Trap Register */
#define CPU2_DSTR	(*( CPU0_DSTR_type *) 0xF8859010U)	/* Data Synchronous Trap Register */
#define CPU0_DATR	(*( CPU0_DATR_type *) 0xF8819018U)	/* Data Asynchronous Trap Register */
#define CPU1_DATR	(*( CPU0_DATR_type *) 0xF8839018U)	/* Data Asynchronous Trap Register */
#define CPU2_DATR	(*( CPU0_DATR_type *) 0xF8859018U)	/* Data Asynchronous Trap Register */
#define CPU0_DEADD	(*( CPU0_DEADD_type *) 0xF881901CU)	/* Data Error Address Register */
#define CPU1_DEADD	(*( CPU0_DEADD_type *) 0xF883901CU)	/* Data Error Address Register */
#define CPU2_DEADD	(*( CPU0_DEADD_type *) 0xF885901CU)	/* Data Error Address Register */
#define CPU0_PIEAR	(*( CPU0_DIEAR_type *) 0xF8819210U)	/* Program Integrity Error Address Register */
#define CPU1_PIEAR	(*( CPU0_DIEAR_type *) 0xF8839210U)	/* Program Integrity Error Address Register */
#define CPU2_PIEAR	(*( CPU0_DIEAR_type *) 0xF8859210U)	/* Program Integrity Error Address Register */
#define CPU0_PIETR	(*( CPU0_PIETR_type *) 0xF8819214U)	/* Program Integrity Error Trap Register */
#define CPU1_PIETR	(*( CPU0_PIETR_type *) 0xF8839214U)	/* Program Integrity Error Trap Register */
#define CPU2_PIETR	(*( CPU0_PIETR_type *) 0xF8859214U)	/* Program Integrity Error Trap Register */
#define CPU0_COMPAT	(*( CPU0_COMPAT_type *) 0xF8819400U)	/* Compatibility Control Register */
#define CPU1_COMPAT	(*( CPU0_COMPAT_type *) 0xF8839400U)	/* Compatibility Control Register */
#define CPU2_COMPAT	(*( CPU0_COMPAT_type *) 0xF8859400U)	/* Compatibility Control Register */
#define CPU0_FPU_TRAP_CON	(*( CPU0_FPU_TRAP_CON_type *) 0xF881A000U)	/* CPU0 Trap Control Register */
#define CPU1_FPU_TRAP_CON	(*( CPU0_FPU_TRAP_CON_type *) 0xF883A000U)	/* CPU1 Trap Control Register */
#define CPU2_FPU_TRAP_CON	(*( CPU0_FPU_TRAP_CON_type *) 0xF885A000U)	/* CPU2 Trap Control Register */
#define CPU0_FPU_TRAP_PC	(*( CPU0_FPU_TRAP_PC_type *) 0xF881A004U)	/* CPU0 Trapping Instruction Program Counter Register */
#define CPU1_FPU_TRAP_PC	(*( CPU0_FPU_TRAP_PC_type *) 0xF883A004U)	/* CPU1 Trapping Instruction Program Counter Register */
#define CPU2_FPU_TRAP_PC	(*( CPU0_FPU_TRAP_PC_type *) 0xF885A004U)	/* CPU2 Trapping Instruction Program Counter Register */
#define CPU0_FPU_TRAP_OPC	(*( CPU0_FPU_TRAP_OPC_type *) 0xF881A008U)	/* CPU0 Trapping Instruction Opcode Register */
#define CPU1_FPU_TRAP_OPC	(*( CPU0_FPU_TRAP_OPC_type *) 0xF883A008U)	/* CPU1 Trapping Instruction Opcode Register */
#define CPU2_FPU_TRAP_OPC	(*( CPU0_FPU_TRAP_OPC_type *) 0xF885A008U)	/* CPU2 Trapping Instruction Opcode Register */
#define CPU0_FPU_TRAP_SRC1	(*( CPU0_FPU_TRAP_SRC1_type *) 0xF881A010U)	/* CPU0 Trapping Instruction Operand Register */
#define CPU1_FPU_TRAP_SRC1	(*( CPU0_FPU_TRAP_SRC1_type *) 0xF883A010U)	/* CPU1 Trapping Instruction Operand Register */
#define CPU2_FPU_TRAP_SRC1	(*( CPU0_FPU_TRAP_SRC1_type *) 0xF885A010U)	/* CPU2 Trapping Instruction Operand Register */
#define CPU0_FPU_TRAP_SRC2	(*( CPU0_FPU_TRAP_SRC2_type *) 0xF881A014U)	/* CPU0 Trapping Instruction Operand Register */
#define CPU1_FPU_TRAP_SRC2	(*( CPU0_FPU_TRAP_SRC2_type *) 0xF883A014U)	/* CPU1 Trapping Instruction Operand Register */
#define CPU2_FPU_TRAP_SRC2	(*( CPU0_FPU_TRAP_SRC2_type *) 0xF885A014U)	/* CPU2 Trapping Instruction Operand Register */
#define CPU0_FPU_TRAP_SRC3	(*( CPU0_FPU_TRAP_SRC3_type *) 0xF881A018U)	/* Trapping Instruction Operand Register */
#define CPU1_FPU_TRAP_SRC3	(*( CPU0_FPU_TRAP_SRC3_type *) 0xF883A018U)	/* Trapping Instruction Operand Register */
#define CPU2_FPU_TRAP_SRC3	(*( CPU0_FPU_TRAP_SRC3_type *) 0xF885A018U)	/* Trapping Instruction Operand Register */
#define CPU0_DPR0_L	(*( CPU0_DPR0_L_type *) 0xF881C000U)	/* CPU0 Data Protection Range 0, Lower Bound Register */
#define CPU0_DPR1_L	(*( CPU0_DPR0_L_type *) 0xF881C008U)	/* CPU0 Data Protection Range 1, Lower Bound Register */
#define CPU0_DPR2_L	(*( CPU0_DPR0_L_type *) 0xF881C010U)	/* CPU0 Data Protection Range 2, Lower Bound Register */
#define CPU0_DPR3_L	(*( CPU0_DPR0_L_type *) 0xF881C018U)	/* CPU0 Data Protection Range 3, Lower Bound Register */
#define CPU0_DPR4_L	(*( CPU0_DPR0_L_type *) 0xF881C020U)	/* CPU0 Data Protection Range 4, Lower Bound Register */
#define CPU0_DPR5_L	(*( CPU0_DPR0_L_type *) 0xF881C028U)	/* CPU0 Data Protection Range 5, Lower Bound Register */
#define CPU0_DPR6_L	(*( CPU0_DPR0_L_type *) 0xF881C030U)	/* CPU0 Data Protection Range 6, Lower Bound Register */
#define CPU0_DPR7_L	(*( CPU0_DPR0_L_type *) 0xF881C038U)	/* CPU0 Data Protection Range 7, Lower Bound Register */
#define CPU0_DPR8_L	(*( CPU0_DPR0_L_type *) 0xF881C040U)	/* CPU0 Data Protection Range 8, Lower Bound Register */
#define CPU0_DPR9_L	(*( CPU0_DPR0_L_type *) 0xF881C048U)	/* CPU0 Data Protection Range 9, Lower Bound Register */
#define CPU0_DPR10_L	(*( CPU0_DPR0_L_type *) 0xF881C050U)	/* CPU0 Data Protection Range 10, Lower Bound Register */
#define CPU0_DPR11_L	(*( CPU0_DPR0_L_type *) 0xF881C058U)	/* CPU0 Data Protection Range 11, Lower Bound Register */
#define CPU0_DPR12_L	(*( CPU0_DPR0_L_type *) 0xF881C060U)	/* CPU0 Data Protection Range 12, Lower Bound Register */
#define CPU0_DPR13_L	(*( CPU0_DPR0_L_type *) 0xF881C068U)	/* CPU0 Data Protection Range 13, Lower Bound Register */
#define CPU0_DPR14_L	(*( CPU0_DPR0_L_type *) 0xF881C070U)	/* CPU0 Data Protection Range 14, Lower Bound Register */
#define CPU0_DPR15_L	(*( CPU0_DPR0_L_type *) 0xF881C078U)	/* CPU0 Data Protection Range 15, Lower Bound Register */
#define CPU1_DPR0_L	(*( CPU0_DPR0_L_type *) 0xF883C000U)	/* CPU1 Data Protection Range 0, Lower Bound Register */
#define CPU1_DPR1_L	(*( CPU0_DPR0_L_type *) 0xF883C008U)	/* CPU1 Data Protection Range 1, Lower Bound Register */
#define CPU1_DPR2_L	(*( CPU0_DPR0_L_type *) 0xF883C010U)	/* CPU1 Data Protection Range 2, Lower Bound Register */
#define CPU1_DPR3_L	(*( CPU0_DPR0_L_type *) 0xF883C018U)	/* CPU1 Data Protection Range 3, Lower Bound Register */
#define CPU1_DPR4_L	(*( CPU0_DPR0_L_type *) 0xF883C020U)	/* CPU1 Data Protection Range 4, Lower Bound Register */
#define CPU1_DPR5_L	(*( CPU0_DPR0_L_type *) 0xF883C028U)	/* CPU1 Data Protection Range 5, Lower Bound Register */
#define CPU1_DPR6_L	(*( CPU0_DPR0_L_type *) 0xF883C030U)	/* CPU1 Data Protection Range 6, Lower Bound Register */
#define CPU1_DPR7_L	(*( CPU0_DPR0_L_type *) 0xF883C038U)	/* CPU1 Data Protection Range 7, Lower Bound Register */
#define CPU1_DPR8_L	(*( CPU0_DPR0_L_type *) 0xF883C040U)	/* CPU1 Data Protection Range 8, Lower Bound Register */
#define CPU1_DPR9_L	(*( CPU0_DPR0_L_type *) 0xF883C048U)	/* CPU1 Data Protection Range 9, Lower Bound Register */
#define CPU1_DPR10_L	(*( CPU0_DPR0_L_type *) 0xF883C050U)	/* CPU1 Data Protection Range 10, Lower Bound Register */
#define CPU1_DPR11_L	(*( CPU0_DPR0_L_type *) 0xF883C058U)	/* CPU1 Data Protection Range 11, Lower Bound Register */
#define CPU1_DPR12_L	(*( CPU0_DPR0_L_type *) 0xF883C060U)	/* CPU1 Data Protection Range 12, Lower Bound Register */
#define CPU1_DPR13_L	(*( CPU0_DPR0_L_type *) 0xF883C068U)	/* CPU1 Data Protection Range 13, Lower Bound Register */
#define CPU1_DPR14_L	(*( CPU0_DPR0_L_type *) 0xF883C070U)	/* CPU1 Data Protection Range 14, Lower Bound Register */
#define CPU1_DPR15_L	(*( CPU0_DPR0_L_type *) 0xF883C078U)	/* CPU1 Data Protection Range 15, Lower Bound Register */
#define CPU2_DPR0_L	(*( CPU0_DPR0_L_type *) 0xF885C000U)	/* CPU2 Data Protection Range 0, Lower Bound Register */
#define CPU2_DPR1_L	(*( CPU0_DPR0_L_type *) 0xF885C008U)	/* CPU2 Data Protection Range 1, Lower Bound Register */
#define CPU2_DPR2_L	(*( CPU0_DPR0_L_type *) 0xF885C010U)	/* CPU2 Data Protection Range 2, Lower Bound Register */
#define CPU2_DPR3_L	(*( CPU0_DPR0_L_type *) 0xF885C018U)	/* CPU2 Data Protection Range 3, Lower Bound Register */
#define CPU2_DPR4_L	(*( CPU0_DPR0_L_type *) 0xF885C020U)	/* CPU2 Data Protection Range 4, Lower Bound Register */
#define CPU2_DPR5_L	(*( CPU0_DPR0_L_type *) 0xF885C028U)	/* CPU2 Data Protection Range 5, Lower Bound Register */
#define CPU2_DPR6_L	(*( CPU0_DPR0_L_type *) 0xF885C030U)	/* CPU2 Data Protection Range 6, Lower Bound Register */
#define CPU2_DPR7_L	(*( CPU0_DPR0_L_type *) 0xF885C038U)	/* CPU2 Data Protection Range 7, Lower Bound Register */
#define CPU2_DPR8_L	(*( CPU0_DPR0_L_type *) 0xF885C040U)	/* CPU2 Data Protection Range 8, Lower Bound Register */
#define CPU2_DPR9_L	(*( CPU0_DPR0_L_type *) 0xF885C048U)	/* CPU2 Data Protection Range 9, Lower Bound Register */
#define CPU2_DPR10_L	(*( CPU0_DPR0_L_type *) 0xF885C050U)	/* CPU2 Data Protection Range 10, Lower Bound Register */
#define CPU2_DPR11_L	(*( CPU0_DPR0_L_type *) 0xF885C058U)	/* CPU2 Data Protection Range 11, Lower Bound Register */
#define CPU2_DPR12_L	(*( CPU0_DPR0_L_type *) 0xF885C060U)	/* CPU2 Data Protection Range 12, Lower Bound Register */
#define CPU2_DPR13_L	(*( CPU0_DPR0_L_type *) 0xF885C068U)	/* CPU2 Data Protection Range 13, Lower Bound Register */
#define CPU2_DPR14_L	(*( CPU0_DPR0_L_type *) 0xF885C070U)	/* CPU2 Data Protection Range 14, Lower Bound Register */
#define CPU2_DPR15_L	(*( CPU0_DPR0_L_type *) 0xF885C078U)	/* CPU2 Data Protection Range 15, Lower Bound Register */
#define CPU0_DPR0_U	(*( CPU0_DPR0_U_type *) 0xF881C004U)	/* CPU0 Data Protection Range 0, Upper Bound Register */
#define CPU0_DPR1_U	(*( CPU0_DPR0_U_type *) 0xF881C00CU)	/* CPU0 Data Protection Range 1, Upper Bound Register */
#define CPU0_DPR2_U	(*( CPU0_DPR0_U_type *) 0xF881C014U)	/* CPU0 Data Protection Range 2, Upper Bound Register */
#define CPU0_DPR3_U	(*( CPU0_DPR0_U_type *) 0xF881C01CU)	/* CPU0 Data Protection Range 3, Upper Bound Register */
#define CPU0_DPR4_U	(*( CPU0_DPR0_U_type *) 0xF881C024U)	/* CPU0 Data Protection Range 4, Upper Bound Register */
#define CPU0_DPR5_U	(*( CPU0_DPR0_U_type *) 0xF881C02CU)	/* CPU0 Data Protection Range 5, Upper Bound Register */
#define CPU0_DPR6_U	(*( CPU0_DPR0_U_type *) 0xF881C034U)	/* CPU0 Data Protection Range 6, Upper Bound Register */
#define CPU0_DPR7_U	(*( CPU0_DPR0_U_type *) 0xF881C03CU)	/* CPU0 Data Protection Range 7, Upper Bound Register */
#define CPU0_DPR8_U	(*( CPU0_DPR0_U_type *) 0xF881C044U)	/* CPU0 Data Protection Range 8, Upper Bound Register */
#define CPU0_DPR9_U	(*( CPU0_DPR0_U_type *) 0xF881C04CU)	/* CPU0 Data Protection Range 9, Upper Bound Register */
#define CPU0_DPR10_U	(*( CPU0_DPR0_U_type *) 0xF881C054U)	/* CPU0 Data Protection Range 10, Upper Bound Register */
#define CPU0_DPR11_U	(*( CPU0_DPR0_U_type *) 0xF881C05CU)	/* CPU0 Data Protection Range 11, Upper Bound Register */
#define CPU0_DPR12_U	(*( CPU0_DPR0_U_type *) 0xF881C064U)	/* CPU0 Data Protection Range 12, Upper Bound Register */
#define CPU0_DPR13_U	(*( CPU0_DPR0_U_type *) 0xF881C06CU)	/* CPU0 Data Protection Range 13, Upper Bound Register */
#define CPU0_DPR14_U	(*( CPU0_DPR0_U_type *) 0xF881C074U)	/* CPU0 Data Protection Range 14, Upper Bound Register */
#define CPU0_DPR15_U	(*( CPU0_DPR0_U_type *) 0xF881C07CU)	/* CPU0 Data Protection Range 15, Upper Bound Register */
#define CPU1_DPR0_U	(*( CPU0_DPR0_U_type *) 0xF883C004U)	/* CPU1 Data Protection Range 0, Upper Bound Register */
#define CPU1_DPR1_U	(*( CPU0_DPR0_U_type *) 0xF883C00CU)	/* CPU1 Data Protection Range 1, Upper Bound Register */
#define CPU1_DPR2_U	(*( CPU0_DPR0_U_type *) 0xF883C014U)	/* CPU1 Data Protection Range 2, Upper Bound Register */
#define CPU1_DPR3_U	(*( CPU0_DPR0_U_type *) 0xF883C01CU)	/* CPU1 Data Protection Range 3, Upper Bound Register */
#define CPU1_DPR4_U	(*( CPU0_DPR0_U_type *) 0xF883C024U)	/* CPU1 Data Protection Range 4, Upper Bound Register */
#define CPU1_DPR5_U	(*( CPU0_DPR0_U_type *) 0xF883C02CU)	/* CPU1 Data Protection Range 5, Upper Bound Register */
#define CPU1_DPR6_U	(*( CPU0_DPR0_U_type *) 0xF883C034U)	/* CPU1 Data Protection Range 6, Upper Bound Register */
#define CPU1_DPR7_U	(*( CPU0_DPR0_U_type *) 0xF883C03CU)	/* CPU1 Data Protection Range 7, Upper Bound Register */
#define CPU1_DPR8_U	(*( CPU0_DPR0_U_type *) 0xF883C044U)	/* CPU1 Data Protection Range 8, Upper Bound Register */
#define CPU1_DPR9_U	(*( CPU0_DPR0_U_type *) 0xF883C04CU)	/* CPU1 Data Protection Range 9, Upper Bound Register */
#define CPU1_DPR10_U	(*( CPU0_DPR0_U_type *) 0xF883C054U)	/* CPU1 Data Protection Range 10, Upper Bound Register */
#define CPU1_DPR11_U	(*( CPU0_DPR0_U_type *) 0xF883C05CU)	/* CPU1 Data Protection Range 11, Upper Bound Register */
#define CPU1_DPR12_U	(*( CPU0_DPR0_U_type *) 0xF883C064U)	/* CPU1 Data Protection Range 12, Upper Bound Register */
#define CPU1_DPR13_U	(*( CPU0_DPR0_U_type *) 0xF883C06CU)	/* CPU1 Data Protection Range 13, Upper Bound Register */
#define CPU1_DPR14_U	(*( CPU0_DPR0_U_type *) 0xF883C074U)	/* CPU1 Data Protection Range 14, Upper Bound Register */
#define CPU1_DPR15_U	(*( CPU0_DPR0_U_type *) 0xF883C07CU)	/* CPU1 Data Protection Range 15, Upper Bound Register */
#define CPU2_DPR0_U	(*( CPU0_DPR0_U_type *) 0xF885C004U)	/* CPU2 Data Protection Range 0, Upper Bound Register */
#define CPU2_DPR1_U	(*( CPU0_DPR0_U_type *) 0xF885C00CU)	/* CPU2 Data Protection Range 1, Upper Bound Register */
#define CPU2_DPR2_U	(*( CPU0_DPR0_U_type *) 0xF885C014U)	/* CPU2 Data Protection Range 2, Upper Bound Register */
#define CPU2_DPR3_U	(*( CPU0_DPR0_U_type *) 0xF885C01CU)	/* CPU2 Data Protection Range 3, Upper Bound Register */
#define CPU2_DPR4_U	(*( CPU0_DPR0_U_type *) 0xF885C024U)	/* CPU2 Data Protection Range 4, Upper Bound Register */
#define CPU2_DPR5_U	(*( CPU0_DPR0_U_type *) 0xF885C02CU)	/* CPU2 Data Protection Range 5, Upper Bound Register */
#define CPU2_DPR6_U	(*( CPU0_DPR0_U_type *) 0xF885C034U)	/* CPU2 Data Protection Range 6, Upper Bound Register */
#define CPU2_DPR7_U	(*( CPU0_DPR0_U_type *) 0xF885C03CU)	/* CPU2 Data Protection Range 7, Upper Bound Register */
#define CPU2_DPR8_U	(*( CPU0_DPR0_U_type *) 0xF885C044U)	/* CPU2 Data Protection Range 8, Upper Bound Register */
#define CPU2_DPR9_U	(*( CPU0_DPR0_U_type *) 0xF885C04CU)	/* CPU2 Data Protection Range 9, Upper Bound Register */
#define CPU2_DPR10_U	(*( CPU0_DPR0_U_type *) 0xF885C054U)	/* CPU2 Data Protection Range 10, Upper Bound Register */
#define CPU2_DPR11_U	(*( CPU0_DPR0_U_type *) 0xF885C05CU)	/* CPU2 Data Protection Range 11, Upper Bound Register */
#define CPU2_DPR12_U	(*( CPU0_DPR0_U_type *) 0xF885C064U)	/* CPU2 Data Protection Range 12, Upper Bound Register */
#define CPU2_DPR13_U	(*( CPU0_DPR0_U_type *) 0xF885C06CU)	/* CPU2 Data Protection Range 13, Upper Bound Register */
#define CPU2_DPR14_U	(*( CPU0_DPR0_U_type *) 0xF885C074U)	/* CPU2 Data Protection Range 14, Upper Bound Register */
#define CPU2_DPR15_U	(*( CPU0_DPR0_U_type *) 0xF885C07CU)	/* CPU2 Data Protection Range 15, Upper Bound Register */
#define CPU0_CPR0_L	(*( CPU0_CPR0_L_type *) 0xF881D000U)	/* CPU0Code Protection Range 0 Lower Bound Register */
#define CPU0_CPR1_L	(*( CPU0_CPR0_L_type *) 0xF881D008U)	/* CPU0Code Protection Range 1 Lower Bound Register */
#define CPU0_CPR2_L	(*( CPU0_CPR0_L_type *) 0xF881D010U)	/* CPU0Code Protection Range 2 Lower Bound Register */
#define CPU0_CPR3_L	(*( CPU0_CPR0_L_type *) 0xF881D018U)	/* CPU0Code Protection Range 3 Lower Bound Register */
#define CPU0_CPR4_L	(*( CPU0_CPR0_L_type *) 0xF881D020U)	/* CPU0Code Protection Range 4 Lower Bound Register */
#define CPU0_CPR5_L	(*( CPU0_CPR0_L_type *) 0xF881D028U)	/* CPU0Code Protection Range 5 Lower Bound Register */
#define CPU0_CPR6_L	(*( CPU0_CPR0_L_type *) 0xF881D030U)	/* CPU0Code Protection Range 6 Lower Bound Register */
#define CPU0_CPR7_L	(*( CPU0_CPR0_L_type *) 0xF881D038U)	/* CPU0Code Protection Range 7 Lower Bound Register */
#define CPU1_CPR0_L	(*( CPU0_CPR0_L_type *) 0xF883D000U)	/* CPU1 Code Protection Range 0 Lower Bound Register */
#define CPU1_CPR1_L	(*( CPU0_CPR0_L_type *) 0xF883D008U)	/* CPU1 Code Protection Range 1 Lower Bound Register */
#define CPU1_CPR2_L	(*( CPU0_CPR0_L_type *) 0xF883D010U)	/* CPU1 Code Protection Range 2 Lower Bound Register */
#define CPU1_CPR3_L	(*( CPU0_CPR0_L_type *) 0xF883D018U)	/* CPU1 Code Protection Range 3 Lower Bound Register */
#define CPU1_CPR4_L	(*( CPU0_CPR0_L_type *) 0xF883D020U)	/* CPU1 Code Protection Range 4 Lower Bound Register */
#define CPU1_CPR5_L	(*( CPU0_CPR0_L_type *) 0xF883D028U)	/* CPU1 Code Protection Range 5 Lower Bound Register */
#define CPU1_CPR6_L	(*( CPU0_CPR0_L_type *) 0xF883D030U)	/* CPU1 Code Protection Range 6 Lower Bound Register */
#define CPU1_CPR7_L	(*( CPU0_CPR0_L_type *) 0xF883D038U)	/* CPU1 Code Protection Range 7 Lower Bound Register */
#define CPU2_CPR0_L	(*( CPU0_CPR0_L_type *) 0xF885D000U)	/* CPU2 Code Protection Range 0 Lower Bound Register */
#define CPU2_CPR1_L	(*( CPU0_CPR0_L_type *) 0xF885D008U)	/* CPU2 Code Protection Range 1 Lower Bound Register */
#define CPU2_CPR2_L	(*( CPU0_CPR0_L_type *) 0xF885D010U)	/* CPU2 Code Protection Range 2 Lower Bound Register */
#define CPU2_CPR3_L	(*( CPU0_CPR0_L_type *) 0xF885D018U)	/* CPU2 Code Protection Range 3 Lower Bound Register */
#define CPU2_CPR4_L	(*( CPU0_CPR0_L_type *) 0xF885D020U)	/* CPU2 Code Protection Range 4 Lower Bound Register */
#define CPU2_CPR5_L	(*( CPU0_CPR0_L_type *) 0xF885D028U)	/* CPU2 Code Protection Range 5 Lower Bound Register */
#define CPU2_CPR6_L	(*( CPU0_CPR0_L_type *) 0xF885D030U)	/* CPU2 Code Protection Range 6 Lower Bound Register */
#define CPU2_CPR7_L	(*( CPU0_CPR0_L_type *) 0xF885D038U)	/* CPU2 Code Protection Range 7 Lower Bound Register */
#define CPU0_CPR0_U	(*( CPU0_CPR0_U_type *) 0xF881D004U)	/* CPU0 Code Protection Range 0 Upper Bound Register */
#define CPU0_CPR1_U	(*( CPU0_CPR0_U_type *) 0xF881D00CU)	/* CPU0 Code Protection Range 1 Upper Bound Register */
#define CPU0_CPR2_U	(*( CPU0_CPR0_U_type *) 0xF881D014U)	/* CPU0 Code Protection Range 2 Upper Bound Register */
#define CPU0_CPR3_U	(*( CPU0_CPR0_U_type *) 0xF881D01CU)	/* CPU0 Code Protection Range 3 Upper Bound Register */
#define CPU0_CPR4_U	(*( CPU0_CPR0_U_type *) 0xF881D024U)	/* CPU0 Code Protection Range 4 Upper Bound Register */
#define CPU0_CPR5_U	(*( CPU0_CPR0_U_type *) 0xF881D02CU)	/* CPU0 Code Protection Range 5 Upper Bound Register */
#define CPU0_CPR6_U	(*( CPU0_CPR0_U_type *) 0xF881D034U)	/* CPU0 Code Protection Range 6 Upper Bound Register */
#define CPU0_CPR7_U	(*( CPU0_CPR0_U_type *) 0xF881D03CU)	/* CPU0 Code Protection Range 7 Upper Bound Register */
#define CPU1_CPR0_U	(*( CPU0_CPR0_U_type *) 0xF883D004U)	/* CPU1 Code Protection Range 0 Upper Bound Register */
#define CPU1_CPR1_U	(*( CPU0_CPR0_U_type *) 0xF883D00CU)	/* CPU1 Code Protection Range 1 Upper Bound Register */
#define CPU1_CPR2_U	(*( CPU0_CPR0_U_type *) 0xF883D014U)	/* CPU1 Code Protection Range 2 Upper Bound Register */
#define CPU1_CPR3_U	(*( CPU0_CPR0_U_type *) 0xF883D01CU)	/* CPU1 Code Protection Range 3 Upper Bound Register */
#define CPU1_CPR4_U	(*( CPU0_CPR0_U_type *) 0xF883D024U)	/* CPU1 Code Protection Range 4 Upper Bound Register */
#define CPU1_CPR5_U	(*( CPU0_CPR0_U_type *) 0xF883D02CU)	/* CPU1 Code Protection Range 5 Upper Bound Register */
#define CPU1_CPR6_U	(*( CPU0_CPR0_U_type *) 0xF883D034U)	/* CPU1 Code Protection Range 6 Upper Bound Register */
#define CPU1_CPR7_U	(*( CPU0_CPR0_U_type *) 0xF883D03CU)	/* CPU1 Code Protection Range 7 Upper Bound Register */
#define CPU2_CPR0_U	(*( CPU0_CPR0_U_type *) 0xF885D004U)	/* CPU2 Code Protection Range 0 Upper Bound Register */
#define CPU2_CPR1_U	(*( CPU0_CPR0_U_type *) 0xF885D00CU)	/* CPU2 Code Protection Range 1 Upper Bound Register */
#define CPU2_CPR2_U	(*( CPU0_CPR0_U_type *) 0xF885D014U)	/* CPU2 Code Protection Range 2 Upper Bound Register */
#define CPU2_CPR3_U	(*( CPU0_CPR0_U_type *) 0xF885D01CU)	/* CPU2 Code Protection Range 3 Upper Bound Register */
#define CPU2_CPR4_U	(*( CPU0_CPR0_U_type *) 0xF885D024U)	/* CPU2 Code Protection Range 4 Upper Bound Register */
#define CPU2_CPR5_U	(*( CPU0_CPR0_U_type *) 0xF885D02CU)	/* CPU2 Code Protection Range 5 Upper Bound Register */
#define CPU2_CPR6_U	(*( CPU0_CPR0_U_type *) 0xF885D034U)	/* CPU2 Code Protection Range 6 Upper Bound Register */
#define CPU2_CPR7_U	(*( CPU0_CPR0_U_type *) 0xF885D03CU)	/* CPU2 Code Protection Range 7 Upper Bound Register */
#define CPU0_DPRE_0	(*( CPU0_DPRE_0_type *) 0xF881E010U)	/* CPU0 Data Protection Read Enable Register Set 0 */
#define CPU0_DPRE_1	(*( CPU0_DPRE_0_type *) 0xF881E014U)	/* CPU0 Data Protection Read Enable Register Set 1 */
#define CPU0_DPRE_2	(*( CPU0_DPRE_0_type *) 0xF881E018U)	/* CPU0 Data Protection Read Enable Register Set 2 */
#define CPU0_DPRE_3	(*( CPU0_DPRE_0_type *) 0xF881E01CU)	/* CPU0 Data Protection Read Enable Register Set 3 */
#define CPU1_DPRE_0	(*( CPU0_DPRE_0_type *) 0xF883E010U)	/* CPU1 Data Protection Read Enable Register Set 0 */
#define CPU1_DPRE_1	(*( CPU0_DPRE_0_type *) 0xF883E014U)	/* CPU1 Data Protection Read Enable Register Set 1 */
#define CPU1_DPRE_2	(*( CPU0_DPRE_0_type *) 0xF883E018U)	/* CPU1 Data Protection Read Enable Register Set 2 */
#define CPU1_DPRE_3	(*( CPU0_DPRE_0_type *) 0xF883E01CU)	/* CPU1 Data Protection Read Enable Register Set 3 */
#define CPU2_DPRE_0	(*( CPU0_DPRE_0_type *) 0xF885E010U)	/* CPU2 Data Protection Read Enable Register Set 0 */
#define CPU2_DPRE_1	(*( CPU0_DPRE_0_type *) 0xF885E014U)	/* CPU2 Data Protection Read Enable Register Set 1 */
#define CPU2_DPRE_2	(*( CPU0_DPRE_0_type *) 0xF885E018U)	/* CPU2 Data Protection Read Enable Register Set 2 */
#define CPU2_DPRE_3	(*( CPU0_DPRE_0_type *) 0xF885E01CU)	/* CPU2 Data Protection Read Enable Register Set 3 */
#define CPU0_DPWE_0	(*( CPU0_DPWE_0_type *) 0xF881E020U)	/* CPU0 Data Protection Write Enable Register Set 0 */
#define CPU0_DPWE_1	(*( CPU0_DPWE_0_type *) 0xF881E024U)	/* CPU0 Data Protection Write Enable Register Set 1 */
#define CPU0_DPWE_2	(*( CPU0_DPWE_0_type *) 0xF881E028U)	/* CPU0 Data Protection Write Enable Register Set 2 */
#define CPU0_DPWE_3	(*( CPU0_DPWE_0_type *) 0xF881E02CU)	/* CPU0 Data Protection Write Enable Register Set 3 */
#define CPU1_DPWE_0	(*( CPU0_DPWE_0_type *) 0xF883E020U)	/* CPU1 Data Protection Write Enable Register Set 0 */
#define CPU1_DPWE_1	(*( CPU0_DPWE_0_type *) 0xF883E024U)	/* CPU1 Data Protection Write Enable Register Set 1 */
#define CPU1_DPWE_2	(*( CPU0_DPWE_0_type *) 0xF883E028U)	/* CPU1 Data Protection Write Enable Register Set 2 */
#define CPU1_DPWE_3	(*( CPU0_DPWE_0_type *) 0xF883E02CU)	/* CPU1 Data Protection Write Enable Register Set 3 */
#define CPU2_DPWE_0	(*( CPU0_DPWE_0_type *) 0xF885E020U)	/* CPU2 Data Protection Write Enable Register Set 0 */
#define CPU2_DPWE_1	(*( CPU0_DPWE_0_type *) 0xF885E024U)	/* CPU2 Data Protection Write Enable Register Set 1 */
#define CPU2_DPWE_2	(*( CPU0_DPWE_0_type *) 0xF885E028U)	/* CPU2 Data Protection Write Enable Register Set 2 */
#define CPU2_DPWE_3	(*( CPU0_DPWE_0_type *) 0xF885E02CU)	/* CPU2 Data Protection Write Enable Register Set 3 */
#define CPU0_CPXE_0	(*( CPU0_CPXE_0_type *) 0xF881E000U)	/* CPU0 Code Protection Execute Enable Register Set 0 */
#define CPU0_CPXE_1	(*( CPU0_CPXE_0_type *) 0xF881E004U)	/* CPU0 Code Protection Execute Enable Register Set 1 */
#define CPU0_CPXE_2	(*( CPU0_CPXE_0_type *) 0xF881E008U)	/* CPU0 Code Protection Execute Enable Register Set 2 */
#define CPU0_CPXE_3	(*( CPU0_CPXE_0_type *) 0xF881E00CU)	/* CPU0 Code Protection Execute Enable Register Set 3 */
#define CPU1_CPXE_0	(*( CPU0_CPXE_0_type *) 0xF883E000U)	/* CPU1 Code Protection Execute Enable Register Set 0 */
#define CPU1_CPXE_1	(*( CPU0_CPXE_0_type *) 0xF883E004U)	/* CPU1 Code Protection Execute Enable Register Set 1 */
#define CPU1_CPXE_2	(*( CPU0_CPXE_0_type *) 0xF883E008U)	/* CPU1 Code Protection Execute Enable Register Set 2 */
#define CPU1_CPXE_3	(*( CPU0_CPXE_0_type *) 0xF883E00CU)	/* CPU1 Code Protection Execute Enable Register Set 3 */
#define CPU2_CPXE_0	(*( CPU0_CPXE_0_type *) 0xF885E000U)	/* CPU2 Code Protection Execute Enable Register Set 0 */
#define CPU2_CPXE_1	(*( CPU0_CPXE_0_type *) 0xF885E004U)	/* CPU2 Code Protection Execute Enable Register Set 1 */
#define CPU2_CPXE_2	(*( CPU0_CPXE_0_type *) 0xF885E008U)	/* CPU2 Code Protection Execute Enable Register Set 2 */
#define CPU2_CPXE_3	(*( CPU0_CPXE_0_type *) 0xF885E00CU)	/* CPU2 Code Protection Execute Enable Register Set 3 */
#define CPU0_TPS_TIMER0	(*( CPU0_TPS_TIMER0_type *) 0xF881E404U)	/* CPU0 Temporal Protection System Timer Register 0 */
#define CPU1_TPS_TIMER0	(*( CPU0_TPS_TIMER0_type *) 0xF883E404U)	/* CPU1 Temporal Protection System Timer Register 1 */
#define CPU2_TPS_TIMER0	(*( CPU0_TPS_TIMER0_type *) 0xF885E404U)	/* CPU2 Temporal Protection System Timer Register 2 */
#define CPU0_TPS_TIMER1	(*( CPU0_TPS_TIMER0_type *) 0xF881E408U)	/* CPU0 Temporal Protection System Timer Register 0 */
#define CPU1_TPS_TIMER1	(*( CPU0_TPS_TIMER0_type *) 0xF883E408U)	/* CPU1 Temporal Protection System Timer Register 1 */
#define CPU2_TPS_TIMER1	(*( CPU0_TPS_TIMER0_type *) 0xF885E408U)	/* CPU2 Temporal Protection System Timer Register 2 */
#define CPU0_TPS_TIMER2	(*( CPU0_TPS_TIMER0_type *) 0xF881E40CU)	/* CPU0 Temporal Protection System Timer Register 0 */
#define CPU1_TPS_TIMER2	(*( CPU0_TPS_TIMER0_type *) 0xF883E40CU)	/* CPU1 Temporal Protection System Timer Register 1 */
#define CPU2_TPS_TIMER2	(*( CPU0_TPS_TIMER0_type *) 0xF885E40CU)	/* CPU2 Temporal Protection System Timer Register 2 */
#define CPU0_TPS_CON	(*( CPU0_TPS_CON_type *) 0xF881E400U)	/* CPU0 Temporal Protection System Control Register */
#define CPU1_TPS_CON	(*( CPU0_TPS_CON_type *) 0xF883E400U)	/* CPU1 Temporal Protection System Control Register */
#define CPU2_TPS_CON	(*( CPU0_TPS_CON_type *) 0xF885E400U)	/* CPU2 Temporal Protection System Control Register */
#define CPU0_DBGSR	(*( CPU0_DBGSR_type *) 0xF881FD00U)	/* Debug Status Register */
#define CPU1_DBGSR	(*( CPU0_DBGSR_type *) 0xF883FD00U)	/* Debug Status Register */
#define CPU2_DBGSR	(*( CPU0_DBGSR_type *) 0xF885FD00U)	/* Debug Status Register */
#define CPU0_EXEVT	(*( CPU0_EXEVT_type *) 0xF881FD08U)	/* External Event Register */
#define CPU1_EXEVT	(*( CPU0_EXEVT_type *) 0xF883FD08U)	/* External Event Register */
#define CPU2_EXEVT	(*( CPU0_EXEVT_type *) 0xF885FD08U)	/* External Event Register */
#define CPU0_CREVT	(*( CPU0_EXEVT_type *) 0xF881FD0CU)	/* Core Register Access Event */
#define CPU1_CREVT	(*( CPU0_EXEVT_type *) 0xF883FD0CU)	/* Core Register Access Event */
#define CPU2_CREVT	(*( CPU0_EXEVT_type *) 0xF885FD0CU)	/* Core Register Access Event */
#define CPU0_SWEVT	(*( CPU0_EXEVT_type *) 0xF881FD10U)	/* Software Debug Event */
#define CPU1_SWEVT	(*( CPU0_EXEVT_type *) 0xF883FD10U)	/* Software Debug Event */
#define CPU2_SWEVT	(*( CPU0_EXEVT_type *) 0xF885FD10U)	/* Software Debug Event */
#define CPU0_TR0EVT	(*( CPU0_TR0EVT_type *) 0xF881F000U)	/* Trigger Event 0 */
#define CPU0_TR1EVT	(*( CPU0_TR0EVT_type *) 0xF881F008U)	/* Trigger Event 1 */
#define CPU0_TR2EVT	(*( CPU0_TR0EVT_type *) 0xF881F010U)	/* Trigger Event 2 */
#define CPU0_TR3EVT	(*( CPU0_TR0EVT_type *) 0xF881F018U)	/* Trigger Event 3 */
#define CPU0_TR4EVT	(*( CPU0_TR0EVT_type *) 0xF881F020U)	/* Trigger Event 4 */
#define CPU0_TR5EVT	(*( CPU0_TR0EVT_type *) 0xF881F028U)	/* Trigger Event 5 */
#define CPU0_TR6EVT	(*( CPU0_TR0EVT_type *) 0xF881F030U)	/* Trigger Event 6 */
#define CPU0_TR7EVT	(*( CPU0_TR0EVT_type *) 0xF881F038U)	/* Trigger Event 7 */
#define CPU1_TR0EVT	(*( CPU0_TR0EVT_type *) 0xF883F000U)	/* Trigger Event 0 */
#define CPU1_TR1EVT	(*( CPU0_TR0EVT_type *) 0xF883F008U)	/* Trigger Event 1 */
#define CPU1_TR2EVT	(*( CPU0_TR0EVT_type *) 0xF883F010U)	/* Trigger Event 2 */
#define CPU1_TR3EVT	(*( CPU0_TR0EVT_type *) 0xF883F018U)	/* Trigger Event 3 */
#define CPU1_TR4EVT	(*( CPU0_TR0EVT_type *) 0xF883F020U)	/* Trigger Event 4 */
#define CPU1_TR5EVT	(*( CPU0_TR0EVT_type *) 0xF883F028U)	/* Trigger Event 5 */
#define CPU1_TR6EVT	(*( CPU0_TR0EVT_type *) 0xF883F030U)	/* Trigger Event 6 */
#define CPU1_TR7EVT	(*( CPU0_TR0EVT_type *) 0xF883F038U)	/* Trigger Event 7 */
#define CPU2_TR0EVT	(*( CPU0_TR0EVT_type *) 0xF885F000U)	/* Trigger Event 0 */
#define CPU2_TR1EVT	(*( CPU0_TR0EVT_type *) 0xF885F008U)	/* Trigger Event 1 */
#define CPU2_TR2EVT	(*( CPU0_TR0EVT_type *) 0xF885F010U)	/* Trigger Event 2 */
#define CPU2_TR3EVT	(*( CPU0_TR0EVT_type *) 0xF885F018U)	/* Trigger Event 3 */
#define CPU2_TR4EVT	(*( CPU0_TR0EVT_type *) 0xF885F020U)	/* Trigger Event 4 */
#define CPU2_TR5EVT	(*( CPU0_TR0EVT_type *) 0xF885F028U)	/* Trigger Event 5 */
#define CPU2_TR6EVT	(*( CPU0_TR0EVT_type *) 0xF885F030U)	/* Trigger Event 6 */
#define CPU2_TR7EVT	(*( CPU0_TR0EVT_type *) 0xF885F038U)	/* Trigger Event 7 */
#define CPU0_TR0ADR	(*( CPU0_TR0ADR_type *) 0xF881F004U)	/* Trigger Address 0 */
#define CPU0_TR1ADR	(*( CPU0_TR0ADR_type *) 0xF881F00CU)	/* Trigger Address 1 */
#define CPU0_TR2ADR	(*( CPU0_TR0ADR_type *) 0xF881F014U)	/* Trigger Address 2 */
#define CPU0_TR3ADR	(*( CPU0_TR0ADR_type *) 0xF881F01CU)	/* Trigger Address 3 */
#define CPU0_TR4ADR	(*( CPU0_TR0ADR_type *) 0xF881F024U)	/* Trigger Address 4 */
#define CPU0_TR5ADR	(*( CPU0_TR0ADR_type *) 0xF881F02CU)	/* Trigger Address 5 */
#define CPU0_TR6ADR	(*( CPU0_TR0ADR_type *) 0xF881F034U)	/* Trigger Address 6 */
#define CPU0_TR7ADR	(*( CPU0_TR0ADR_type *) 0xF881F03CU)	/* Trigger Address 7 */
#define CPU1_TR0ADR	(*( CPU0_TR0ADR_type *) 0xF883F004U)	/* Trigger Address 0 */
#define CPU1_TR1ADR	(*( CPU0_TR0ADR_type *) 0xF883F00CU)	/* Trigger Address 1 */
#define CPU1_TR2ADR	(*( CPU0_TR0ADR_type *) 0xF883F014U)	/* Trigger Address 2 */
#define CPU1_TR3ADR	(*( CPU0_TR0ADR_type *) 0xF883F01CU)	/* Trigger Address 3 */
#define CPU1_TR4ADR	(*( CPU0_TR0ADR_type *) 0xF883F024U)	/* Trigger Address 4 */
#define CPU1_TR5ADR	(*( CPU0_TR0ADR_type *) 0xF883F02CU)	/* Trigger Address 5 */
#define CPU1_TR6ADR	(*( CPU0_TR0ADR_type *) 0xF883F034U)	/* Trigger Address 6 */
#define CPU1_TR7ADR	(*( CPU0_TR0ADR_type *) 0xF883F03CU)	/* Trigger Address 7 */
#define CPU2_TR0ADR	(*( CPU0_TR0ADR_type *) 0xF885F004U)	/* Trigger Address 0 */
#define CPU2_TR1ADR	(*( CPU0_TR0ADR_type *) 0xF885F00CU)	/* Trigger Address 1 */
#define CPU2_TR2ADR	(*( CPU0_TR0ADR_type *) 0xF885F014U)	/* Trigger Address 2 */
#define CPU2_TR3ADR	(*( CPU0_TR0ADR_type *) 0xF885F01CU)	/* Trigger Address 3 */
#define CPU2_TR4ADR	(*( CPU0_TR0ADR_type *) 0xF885F024U)	/* Trigger Address 4 */
#define CPU2_TR5ADR	(*( CPU0_TR0ADR_type *) 0xF885F02CU)	/* Trigger Address 5 */
#define CPU2_TR6ADR	(*( CPU0_TR0ADR_type *) 0xF885F034U)	/* Trigger Address 6 */
#define CPU2_TR7ADR	(*( CPU0_TR0ADR_type *) 0xF885F03CU)	/* Trigger Address 7 */
#define CPU0_TRIG_ACC	(*( CPU0_TRIG_ACC_type *) 0xF881FD30U)	/* CPU0 Trigger Address x */
#define CPU1_TRIG_ACC	(*( CPU0_TRIG_ACC_type *) 0xF883FD30U)	/* CPU1 Trigger Address x */
#define CPU2_TRIG_ACC	(*( CPU0_TRIG_ACC_type *) 0xF885FD30U)	/* CPU2 Trigger Address x */
#define CPU0_DMS	(*( CPU0_DMS_type *) 0xF881FD40U)	/* CPU0 Debug Monitor Start Address */
#define CPU1_DMS	(*( CPU0_DMS_type *) 0xF883FD40U)	/* CPU1 Debug Monitor Start Address */
#define CPU2_DMS	(*( CPU0_DMS_type *) 0xF885FD40U)	/* CPU2 Debug Monitor Start Address */
#define CPU0_DCX	(*( CPU0_DCX_type *) 0xF881FD44U)	/* CPU0 Debug Context Save Area Pointer */
#define CPU1_DCX	(*( CPU0_DCX_type *) 0xF883FD44U)	/* CPU1 Debug Context Save Area Pointer */
#define CPU2_DCX	(*( CPU0_DCX_type *) 0xF885FD44U)	/* CPU2 Debug Context Save Area Pointer */
#define CPU0_DBGTCR	(*( CPU0_DBGTCR_type *) 0xF881FD48U)	/* Debug Trap Control Register */
#define CPU1_DBGTCR	(*( CPU0_DBGTCR_type *) 0xF883FD48U)	/* Debug Trap Control Register */
#define CPU2_DBGTCR	(*( CPU0_DBGTCR_type *) 0xF885FD48U)	/* Debug Trap Control Register */
#define CPU0_CCTRL	(*( CPU0_CCTRL_type *) 0xF881FC00U)	/* Counter Control */
#define CPU1_CCTRL	(*( CPU0_CCTRL_type *) 0xF883FC00U)	/* Counter Control */
#define CPU2_CCTRL	(*( CPU0_CCTRL_type *) 0xF885FC00U)	/* Counter Control */
#define CPU0_CCNT	(*( CPU0_CCNT_type *) 0xF881FC04U)	/* CPU Clock Cycle Count */
#define CPU1_CCNT	(*( CPU0_CCNT_type *) 0xF883FC04U)	/* CPU Clock Cycle Count */
#define CPU2_CCNT	(*( CPU0_CCNT_type *) 0xF885FC04U)	/* CPU Clock Cycle Count */
#define CPU0_ICNT	(*( CPU0_CCNT_type *) 0xF881FC08U)	/* Instruction Count */
#define CPU1_ICNT	(*( CPU0_CCNT_type *) 0xF883FC08U)	/* Instruction Count */
#define CPU2_ICNT	(*( CPU0_CCNT_type *) 0xF885FC08U)	/* Instruction Count */
#define CPU0_M1CNT	(*( CPU0_CCNT_type *) 0xF881FC0CU)	/* Multi-Count Register 1 */
#define CPU1_M1CNT	(*( CPU0_CCNT_type *) 0xF883FC0CU)	/* Multi-Count Register 1 */
#define CPU2_M1CNT	(*( CPU0_CCNT_type *) 0xF885FC0CU)	/* Multi-Count Register 1 */
#define CPU0_M2CNT	(*( CPU0_CCNT_type *) 0xF881FC10U)	/* Multi-Count Register 2 */
#define CPU1_M2CNT	(*( CPU0_CCNT_type *) 0xF883FC10U)	/* Multi-Count Register 2 */
#define CPU2_M2CNT	(*( CPU0_CCNT_type *) 0xF885FC10U)	/* Multi-Count Register 2 */
#define CPU0_M3CNT	(*( CPU0_CCNT_type *) 0xF881FC14U)	/* Multi-Count Register 3 */
#define CPU1_M3CNT	(*( CPU0_CCNT_type *) 0xF883FC14U)	/* Multi-Count Register 3 */
#define CPU2_M3CNT	(*( CPU0_CCNT_type *) 0xF885FC14U)	/* Multi-Count Register 3 */
#define CPU0_PCXI	(*( CPU0_PCXI_type *) 0xF881FE00U)	/* Previous Context Information Register */
#define CPU1_PCXI	(*( CPU0_PCXI_type *) 0xF883FE00U)	/* Previous Context Information Register */
#define CPU2_PCXI	(*( CPU0_PCXI_type *) 0xF885FE00U)	/* Previous Context Information Register */
#define CPU0_PSW	(*( CPU0_PSW_type *) 0xF881FE04U)	/* Program Status Word */
#define CPU1_PSW	(*( CPU0_PSW_type *) 0xF883FE04U)	/* Program Status Word */
#define CPU2_PSW	(*( CPU0_PSW_type *) 0xF885FE04U)	/* Program Status Word */
#define CPU0_PC	(*( CPU0_PC_type *) 0xF881FE08U)	/* Program Counter */
#define CPU1_PC	(*( CPU0_PC_type *) 0xF883FE08U)	/* Program Counter */
#define CPU2_PC	(*( CPU0_PC_type *) 0xF885FE08U)	/* Program Counter */
#define CPU0_SYSCON	(*( CPU0_SYSCON_type *) 0xF881FE14U)	/* System Configuration Register */
#define CPU1_SYSCON	(*( CPU0_SYSCON_type *) 0xF883FE14U)	/* System Configuration Register */
#define CPU2_SYSCON	(*( CPU0_SYSCON_type *) 0xF885FE14U)	/* System Configuration Register */
#define CPU0_CORE_ID	(*( CPU0_CORE_ID_type *) 0xF881FE1CU)	/* CPU0 Core Identification Register */
#define CPU1_CORE_ID	(*( CPU0_CORE_ID_type *) 0xF883FE1CU)	/* CPU1 Core Identification Register */
#define CPU2_CORE_ID	(*( CPU0_CORE_ID_type *) 0xF885FE1CU)	/* CPU2 Core Identification Register */
#define CPU0_CPU_ID	(*( CPU0_CPU_ID_type *) 0xF881FE18U)	/* CPU0 Identification Register TC1.6P */
#define CPU1_CPU_ID	(*( CPU0_CPU_ID_type *) 0xF883FE18U)	/* CPU1 Identification Register TC1.6P */
#define CPU2_CPU_ID	(*( CPU0_CPU_ID_type *) 0xF885FE18U)	/* CPU2 Identification Register TC1.6P */
#define CPU0_CUS_ID	(*( CPU0_CUS_ID_type *) 0xF881FE50U)	/* CPU0 Customer ID register */
#define CPU1_CUS_ID	(*( CPU0_CUS_ID_type *) 0xF883FE50U)	/* CPU1 Customer ID register */
#define CPU2_CUS_ID	(*( CPU0_CUS_ID_type *) 0xF885FE50U)	/* CPU2 Customer ID register */
#define CPU0_BIV	(*( CPU0_BIV_type *) 0xF881FE20U)	/* Base Interrupt Vector Table Pointer */
#define CPU1_BIV	(*( CPU0_BIV_type *) 0xF883FE20U)	/* Base Interrupt Vector Table Pointer */
#define CPU2_BIV	(*( CPU0_BIV_type *) 0xF885FE20U)	/* Base Interrupt Vector Table Pointer */
#define CPU0_BTV	(*( CPU0_BTV_type *) 0xF881FE24U)	/* Base Trap Vector Table Pointer */
#define CPU1_BTV	(*( CPU0_BTV_type *) 0xF883FE24U)	/* Base Trap Vector Table Pointer */
#define CPU2_BTV	(*( CPU0_BTV_type *) 0xF885FE24U)	/* Base Trap Vector Table Pointer */
#define CPU0_ISP	(*( CPU0_ISP_type *) 0xF881FE28U)	/* Interrupt Stack Pointer */
#define CPU1_ISP	(*( CPU0_ISP_type *) 0xF883FE28U)	/* Interrupt Stack Pointer */
#define CPU2_ISP	(*( CPU0_ISP_type *) 0xF885FE28U)	/* Interrupt Stack Pointer */
#define CPU0_ICR	(*( CPU0_ICR_type *) 0xF881FE2CU)	/* Interrupt Control Register */
#define CPU1_ICR	(*( CPU0_ICR_type *) 0xF883FE2CU)	/* Interrupt Control Register */
#define CPU2_ICR	(*( CPU0_ICR_type *) 0xF885FE2CU)	/* Interrupt Control Register */
#define CPU0_FCX	(*( CPU0_FCX_type *) 0xF881FE38U)	/* Free CSA List Head Pointer */
#define CPU1_FCX	(*( CPU0_FCX_type *) 0xF883FE38U)	/* Free CSA List Head Pointer */
#define CPU2_FCX	(*( CPU0_FCX_type *) 0xF885FE38U)	/* Free CSA List Head Pointer */
#define CPU0_LCX	(*( CPU0_LCX_type *) 0xF881FE3CU)	/* Free CSA List Limit Pointer */
#define CPU1_LCX	(*( CPU0_LCX_type *) 0xF883FE3CU)	/* Free CSA List Limit Pointer */
#define CPU2_LCX	(*( CPU0_LCX_type *) 0xF885FE3CU)	/* Free CSA List Limit Pointer */
#define CPU0_D0	(*( CPU0_D0_type *) 0xF881FF00U)	/* Data General Purpose Register 0 */
#define CPU0_D1	(*( CPU0_D0_type *) 0xF881FF04U)	/* Data General Purpose Register 1 */
#define CPU0_D2	(*( CPU0_D0_type *) 0xF881FF08U)	/* Data General Purpose Register 2 */
#define CPU0_D3	(*( CPU0_D0_type *) 0xF881FF0CU)	/* Data General Purpose Register 3 */
#define CPU0_D4	(*( CPU0_D0_type *) 0xF881FF10U)	/* Data General Purpose Register 4 */
#define CPU0_D5	(*( CPU0_D0_type *) 0xF881FF14U)	/* Data General Purpose Register 5 */
#define CPU0_D6	(*( CPU0_D0_type *) 0xF881FF18U)	/* Data General Purpose Register 6 */
#define CPU0_D7	(*( CPU0_D0_type *) 0xF881FF1CU)	/* Data General Purpose Register 7 */
#define CPU0_D8	(*( CPU0_D0_type *) 0xF881FF20U)	/* Data General Purpose Register 8 */
#define CPU0_D9	(*( CPU0_D0_type *) 0xF881FF24U)	/* Data General Purpose Register 9 */
#define CPU0_D10	(*( CPU0_D0_type *) 0xF881FF28U)	/* Data General Purpose Register 10 */
#define CPU0_D11	(*( CPU0_D0_type *) 0xF881FF2CU)	/* Data General Purpose Register 11 */
#define CPU0_D12	(*( CPU0_D0_type *) 0xF881FF30U)	/* Data General Purpose Register 12 */
#define CPU0_D13	(*( CPU0_D0_type *) 0xF881FF34U)	/* Data General Purpose Register 13 */
#define CPU0_D14	(*( CPU0_D0_type *) 0xF881FF38U)	/* Data General Purpose Register 14 */
#define CPU0_D15	(*( CPU0_D0_type *) 0xF881FF3CU)	/* Data General Purpose Register 15 */
#define CPU1_D0	(*( CPU0_D0_type *) 0xF883FF00U)	/* Data General Purpose Register 0 */
#define CPU1_D1	(*( CPU0_D0_type *) 0xF883FF04U)	/* Data General Purpose Register 1 */
#define CPU1_D2	(*( CPU0_D0_type *) 0xF883FF08U)	/* Data General Purpose Register 2 */
#define CPU1_D3	(*( CPU0_D0_type *) 0xF883FF0CU)	/* Data General Purpose Register 3 */
#define CPU1_D4	(*( CPU0_D0_type *) 0xF883FF10U)	/* Data General Purpose Register 4 */
#define CPU1_D5	(*( CPU0_D0_type *) 0xF883FF14U)	/* Data General Purpose Register 5 */
#define CPU1_D6	(*( CPU0_D0_type *) 0xF883FF18U)	/* Data General Purpose Register 6 */
#define CPU1_D7	(*( CPU0_D0_type *) 0xF883FF1CU)	/* Data General Purpose Register 7 */
#define CPU1_D8	(*( CPU0_D0_type *) 0xF883FF20U)	/* Data General Purpose Register 8 */
#define CPU1_D9	(*( CPU0_D0_type *) 0xF883FF24U)	/* Data General Purpose Register 9 */
#define CPU1_D10	(*( CPU0_D0_type *) 0xF883FF28U)	/* Data General Purpose Register 10 */
#define CPU1_D11	(*( CPU0_D0_type *) 0xF883FF2CU)	/* Data General Purpose Register 11 */
#define CPU1_D12	(*( CPU0_D0_type *) 0xF883FF30U)	/* Data General Purpose Register 12 */
#define CPU1_D13	(*( CPU0_D0_type *) 0xF883FF34U)	/* Data General Purpose Register 13 */
#define CPU1_D14	(*( CPU0_D0_type *) 0xF883FF38U)	/* Data General Purpose Register 14 */
#define CPU1_D15	(*( CPU0_D0_type *) 0xF883FF3CU)	/* Data General Purpose Register 15 */
#define CPU2_D0	(*( CPU0_D0_type *) 0xF885FF00U)	/* Data General Purpose Register 0 */
#define CPU2_D1	(*( CPU0_D0_type *) 0xF885FF04U)	/* Data General Purpose Register 1 */
#define CPU2_D2	(*( CPU0_D0_type *) 0xF885FF08U)	/* Data General Purpose Register 2 */
#define CPU2_D3	(*( CPU0_D0_type *) 0xF885FF0CU)	/* Data General Purpose Register 3 */
#define CPU2_D4	(*( CPU0_D0_type *) 0xF885FF10U)	/* Data General Purpose Register 4 */
#define CPU2_D5	(*( CPU0_D0_type *) 0xF885FF14U)	/* Data General Purpose Register 5 */
#define CPU2_D6	(*( CPU0_D0_type *) 0xF885FF18U)	/* Data General Purpose Register 6 */
#define CPU2_D7	(*( CPU0_D0_type *) 0xF885FF1CU)	/* Data General Purpose Register 7 */
#define CPU2_D8	(*( CPU0_D0_type *) 0xF885FF20U)	/* Data General Purpose Register 8 */
#define CPU2_D9	(*( CPU0_D0_type *) 0xF885FF24U)	/* Data General Purpose Register 9 */
#define CPU2_D10	(*( CPU0_D0_type *) 0xF885FF28U)	/* Data General Purpose Register 10 */
#define CPU2_D11	(*( CPU0_D0_type *) 0xF885FF2CU)	/* Data General Purpose Register 11 */
#define CPU2_D12	(*( CPU0_D0_type *) 0xF885FF30U)	/* Data General Purpose Register 12 */
#define CPU2_D13	(*( CPU0_D0_type *) 0xF885FF34U)	/* Data General Purpose Register 13 */
#define CPU2_D14	(*( CPU0_D0_type *) 0xF885FF38U)	/* Data General Purpose Register 14 */
#define CPU2_D15	(*( CPU0_D0_type *) 0xF885FF3CU)	/* Data General Purpose Register 15 */
#define CPU0_A0	(*( CPU0_A0_type *) 0xF881FF80U)	/* Address General Purpose Register 0 */
#define CPU0_A1	(*( CPU0_A0_type *) 0xF881FF84U)	/* Address General Purpose Register 1 */
#define CPU0_A2	(*( CPU0_A0_type *) 0xF881FF88U)	/* Address General Purpose Register 2 */
#define CPU0_A3	(*( CPU0_A0_type *) 0xF881FF8CU)	/* Address General Purpose Register 3 */
#define CPU0_A4	(*( CPU0_A0_type *) 0xF881FF90U)	/* Address General Purpose Register 4 */
#define CPU0_A5	(*( CPU0_A0_type *) 0xF881FF94U)	/* Address General Purpose Register 5 */
#define CPU0_A6	(*( CPU0_A0_type *) 0xF881FF98U)	/* Address General Purpose Register 6 */
#define CPU0_A7	(*( CPU0_A0_type *) 0xF881FF9CU)	/* Address General Purpose Register 7 */
#define CPU0_A8	(*( CPU0_A0_type *) 0xF881FFA0U)	/* Address General Purpose Register 8 */
#define CPU0_A9	(*( CPU0_A0_type *) 0xF881FFA4U)	/* Address General Purpose Register 9 */
#define CPU0_A10	(*( CPU0_A0_type *) 0xF881FFA8U)	/* Address General Purpose Register 10 */
#define CPU0_A11	(*( CPU0_A0_type *) 0xF881FFACU)	/* Address General Purpose Register 11 */
#define CPU0_A12	(*( CPU0_A0_type *) 0xF881FFB0U)	/* Address General Purpose Register 12 */
#define CPU0_A13	(*( CPU0_A0_type *) 0xF881FFB4U)	/* Address General Purpose Register 13 */
#define CPU0_A14	(*( CPU0_A0_type *) 0xF881FFB8U)	/* Address General Purpose Register 14 */
#define CPU0_A15	(*( CPU0_A0_type *) 0xF881FFBCU)	/* Address General Purpose Register 15 */
#define CPU1_A0	(*( CPU0_A0_type *) 0xF883FF80U)	/* Address General Purpose Register 0 */
#define CPU1_A1	(*( CPU0_A0_type *) 0xF883FF84U)	/* Address General Purpose Register 1 */
#define CPU1_A2	(*( CPU0_A0_type *) 0xF883FF88U)	/* Address General Purpose Register 2 */
#define CPU1_A3	(*( CPU0_A0_type *) 0xF883FF8CU)	/* Address General Purpose Register 3 */
#define CPU1_A4	(*( CPU0_A0_type *) 0xF883FF90U)	/* Address General Purpose Register 4 */
#define CPU1_A5	(*( CPU0_A0_type *) 0xF883FF94U)	/* Address General Purpose Register 5 */
#define CPU1_A6	(*( CPU0_A0_type *) 0xF883FF98U)	/* Address General Purpose Register 6 */
#define CPU1_A7	(*( CPU0_A0_type *) 0xF883FF9CU)	/* Address General Purpose Register 7 */
#define CPU1_A8	(*( CPU0_A0_type *) 0xF883FFA0U)	/* Address General Purpose Register 8 */
#define CPU1_A9	(*( CPU0_A0_type *) 0xF883FFA4U)	/* Address General Purpose Register 9 */
#define CPU1_A10	(*( CPU0_A0_type *) 0xF883FFA8U)	/* Address General Purpose Register 10 */
#define CPU1_A11	(*( CPU0_A0_type *) 0xF883FFACU)	/* Address General Purpose Register 11 */
#define CPU1_A12	(*( CPU0_A0_type *) 0xF883FFB0U)	/* Address General Purpose Register 12 */
#define CPU1_A13	(*( CPU0_A0_type *) 0xF883FFB4U)	/* Address General Purpose Register 13 */
#define CPU1_A14	(*( CPU0_A0_type *) 0xF883FFB8U)	/* Address General Purpose Register 14 */
#define CPU1_A15	(*( CPU0_A0_type *) 0xF883FFBCU)	/* Address General Purpose Register 15 */
#define CPU2_A0	(*( CPU0_A0_type *) 0xF885FF80U)	/* Address General Purpose Register 0 */
#define CPU2_A1	(*( CPU0_A0_type *) 0xF885FF84U)	/* Address General Purpose Register 1 */
#define CPU2_A2	(*( CPU0_A0_type *) 0xF885FF88U)	/* Address General Purpose Register 2 */
#define CPU2_A3	(*( CPU0_A0_type *) 0xF885FF8CU)	/* Address General Purpose Register 3 */
#define CPU2_A4	(*( CPU0_A0_type *) 0xF885FF90U)	/* Address General Purpose Register 4 */
#define CPU2_A5	(*( CPU0_A0_type *) 0xF885FF94U)	/* Address General Purpose Register 5 */
#define CPU2_A6	(*( CPU0_A0_type *) 0xF885FF98U)	/* Address General Purpose Register 6 */
#define CPU2_A7	(*( CPU0_A0_type *) 0xF885FF9CU)	/* Address General Purpose Register 7 */
#define CPU2_A8	(*( CPU0_A0_type *) 0xF885FFA0U)	/* Address General Purpose Register 8 */
#define CPU2_A9	(*( CPU0_A0_type *) 0xF885FFA4U)	/* Address General Purpose Register 9 */
#define CPU2_A10	(*( CPU0_A0_type *) 0xF885FFA8U)	/* Address General Purpose Register 10 */
#define CPU2_A11	(*( CPU0_A0_type *) 0xF885FFACU)	/* Address General Purpose Register 11 */
#define CPU2_A12	(*( CPU0_A0_type *) 0xF885FFB0U)	/* Address General Purpose Register 12 */
#define CPU2_A13	(*( CPU0_A0_type *) 0xF885FFB4U)	/* Address General Purpose Register 13 */
#define CPU2_A14	(*( CPU0_A0_type *) 0xF885FFB8U)	/* Address General Purpose Register 14 */
#define CPU2_A15	(*( CPU0_A0_type *) 0xF885FFBCU)	/* Address General Purpose Register 15 */
#define CPU0_SEGEN	(*( CPU0_SEGEN_type *) 0xF8811030U)	/* SRI Error Generation Register */
#define CPU1_SEGEN	(*( CPU0_SEGEN_type *) 0xF8831030U)	/* SRI Error Generation Register */
#define CPU2_SEGEN	(*( CPU0_SEGEN_type *) 0xF8851030U)	/* SRI Error Generation Register */
#define CPU0_SPROT_RGNLA0	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E000U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA1	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E010U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA2	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E020U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA3	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E030U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA4	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E040U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA5	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E050U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA6	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E060U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNLA7	(*( CPU0_SPROT_RGNLA0_type *) 0xF880E070U)	/* CPU0_Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA0	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E000U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA1	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E010U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA2	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E020U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA3	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E030U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA4	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E040U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA5	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E050U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA6	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E060U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU1_SPROT_RGNLA7	(*( CPU0_SPROT_RGNLA0_type *) 0xF882E070U)	/* CPU1 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA0	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E000U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA1	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E010U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA2	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E020U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA3	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E030U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA4	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E040U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA5	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E050U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA6	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E060U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU2_SPROT_RGNLA7	(*( CPU0_SPROT_RGNLA0_type *) 0xF884E070U)	/* CPU2 Safety Protection Region Lower Address Register */
#define CPU0_SPROT_RGNUA0	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E004U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA1	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E014U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA2	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E024U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA3	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E034U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA4	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E044U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA5	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E054U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA6	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E064U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNUA7	(*( CPU0_SPROT_RGNUA0_type *) 0xF880E074U)	/* CPU0 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA0	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E004U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA1	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E014U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA2	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E024U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA3	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E034U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA4	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E044U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA5	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E054U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA6	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E064U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU1_SPROT_RGNUA7	(*( CPU0_SPROT_RGNUA0_type *) 0xF882E074U)	/* CPU1 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA0	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E004U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA1	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E014U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA2	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E024U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA3	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E034U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA4	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E044U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA5	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E054U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA6	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E064U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU2_SPROT_RGNUA7	(*( CPU0_SPROT_RGNUA0_type *) 0xF884E074U)	/* CPU2 Safety protection Region Upper Address Register */
#define CPU0_SPROT_RGNACCENA0	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E008U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA1	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E018U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA2	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E028U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA3	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E038U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA4	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E048U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA5	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E058U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA6	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E068U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENA7	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF880E078U)	/* CPU0 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA0	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E008U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA1	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E018U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA2	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E028U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA3	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E038U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA4	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E048U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA5	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E058U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA6	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E068U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU1_SPROT_RGNACCENA7	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF882E078U)	/* CPU1 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA0	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E008U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA1	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E018U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA2	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E028U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA3	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E038U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA4	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E048U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA5	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E058U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA6	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E068U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU2_SPROT_RGNACCENA7	(*( CPU0_SPROT_RGNACCENA0_type *) 0xF884E078U)	/* CPU2 Safety Protection Region Access Enable Register A */
#define CPU0_SPROT_RGNACCENB0	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E00CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB1	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E01CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB2	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E02CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB3	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E03CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB4	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E04CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB5	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E05CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB6	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E06CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_RGNACCENB7	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E07CU)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB0	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E00CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB1	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E01CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB2	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E02CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB3	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E03CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB4	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E04CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB5	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E05CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB6	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E06CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_RGNACCENB7	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E07CU)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB0	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E00CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB1	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E01CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB2	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E02CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB3	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E03CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB4	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E04CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB5	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E05CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB6	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E06CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_RGNACCENB7	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E07CU)	/* CPU2 Safety Protection Region Access Enable Register B */
#define CPU0_SPROT_ACCENA	(*( CPU0_SPROT_ACCENA_type *) 0xF880E100U)	/* CPU0 Safety Protection Register Access Enable Register A */
#define CPU1_SPROT_ACCENA	(*( CPU0_SPROT_ACCENA_type *) 0xF882E100U)	/* CPU1 Safety Protection Register Access Enable Register A */
#define CPU2_SPROT_ACCENA	(*( CPU0_SPROT_ACCENA_type *) 0xF884E100U)	/* CPU2 Safety Protection Register Access Enable Register A */
#define CPU0_SPROT_ACCENB	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF880E104U)	/* CPU0 Safety Protection Region Access Enable Register B */
#define CPU1_SPROT_ACCENB	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF882E104U)	/* CPU1 Safety Protection Region Access Enable Register B */
#define CPU2_SPROT_ACCENB	(*( CPU0_SPROT_RGNACCENB0_type *) 0xF884E104U)	/* CPU2 Safety Protection Region Access Enable Register B */
#define SCU_OSCCON	(*( SCU_OSCCON_type *) 0xF0036010U)	/* OSC Control Register */
#define SCU_PLLSTAT	(*( SCU_PLLSTAT_type *) 0xF0036014U)	/* PLL Status Register */
#define SCU_PLLCON0	(*( SCU_PLLCON0_type *) 0xF0036018U)	/* PLL Configuration 0 Register */
#define SCU_PLLCON1	(*( SCU_PLLCON1_type *) 0xF003601CU)	/* PLL Configuration 1 Register */
#define SCU_PLLCON2	(*( SCU_PLLCON2_type *) 0xF0036020U)	/* PLL Configuration 2 Register */
#define SCU_PLLERAYSTAT	(*( SCU_PLLERAYSTAT_type *) 0xF0036024U)	/* PLL_ERAY Status Register */
#define SCU_PLLERAYCON0	(*( SCU_PLLERAYCON0_type *) 0xF0036028U)	/* PLL_ERAY Configuration 0 Register */
#define SCU_PLLERAYCON1	(*( SCU_PLLERAYCON1_type *) 0xF003602CU)	/* PLL_ERAY Configuration 1 Register */
#define SCU_CCUCON0	(*( SCU_CCUCON0_type *) 0xF0036030U)	/* CCU Clock Control Register 0 */
#define SCU_CCUCON1	(*( SCU_CCUCON1_type *) 0xF0036034U)	/* CCU Clock Control Register 1 */
#define SCU_CCUCON5	(*( SCU_CCUCON5_type *) 0xF003604CU)	/* CCU Clock Control Register 5 */
#define SCU_CCUCON2	(*( SCU_CCUCON2_type *) 0xF0036040U)	/* CCU Clock Control Register 2 */
#define SCU_CCUCON6	(*( SCU_CCUCON6_type *) 0xF0036080U)	/* CCU Clock Control Register 6 */
#define SCU_CCUCON7	(*( SCU_CCUCON7_type *) 0xF0036084U)	/* CCU Clock Control Register 7 */
#define SCU_CCUCON8	(*( SCU_CCUCON8_type *) 0xF0036088U)	/* CCU Clock Control Register 8 */
#define SCU_CCUCON3	(*( SCU_CCUCON3_type *) 0xF0036044U)	/* CCU Clock Control Register 3 */
#define SCU_CCUCON4	(*( SCU_CCUCON4_type *) 0xF0036048U)	/* CCU Clock Control Register 4 */
#define SCU_CCUCON9	(*( SCU_CCUCON9_type *) 0xF003608CU)	/* CCU Clock Control Register 9 */
#define SCU_EXTCON	(*( SCU_EXTCON_type *) 0xF003603CU)	/* External Clock Control Register */
#define SCU_FDR	(*( SCU_FDR_type *) 0xF0036038U)	/* Fractional Divider Register */
#define SCU_RSTSTAT	(*( SCU_RSTSTAT_type *) 0xF0036050U)	/* Reset Status Register */
#define SCU_RSTCON	(*( SCU_RSTCON_type *) 0xF0036058U)	/* Reset Configuration Register */
#define SCU_ARSTDIS	(*( SCU_ARSTDIS_type *) 0xF003605CU)	/* Application Reset Disable Register */
#define SCU_SWRSTCON	(*( SCU_SWRSTCON_type *) 0xF0036060U)	/* Software Reset Configuration Register */
#define SCU_RSTCON2	(*( SCU_RSTCON2_type *) 0xF0036064U)	/* Additional Reset Control Register */
#define SCU_ESRCFG0	(*( SCU_ESRCFG0_type *) 0xF0036070U)	/* ESR0 Input Configuration Register */
#define SCU_ESRCFG1	(*( SCU_ESRCFG0_type *) 0xF0036074U)	/* ESR1 Input Configuration Register */
#define SCU_ESROCFG	(*( SCU_ESROCFG_type *) 0xF0036078U)	/* ESR Output Configuration Register */
#define SCU_IOCR	(*( SCU_IOCR_type *) 0xF00360A0U)	/* Input/Output Control Register */
#define SCU_OUT	(*( SCU_OUT_type *) 0xF00360A4U)	/* ESR Output Register */
#define SCU_OMR	(*( SCU_OMR_type *) 0xF00360A8U)	/* ESR Output Modification Register */
#define SCU_IN	(*( SCU_IN_type *) 0xF00360ACU)	/* ESR Input Register */
#define SCU_PDISC	(*( SCU_PDISC_type *) 0xF003618CU)	/* Pad Disable Control Register */
#define SCU_PDR	(*( SCU_PDR_type *) 0xF003609CU)	/* ESR Pad Driver Mode Register */
#define SCU_STSTAT	(*( SCU_STSTAT_type *) 0xF00360C0U)	/* Start-up Status Register */
#define SCU_TRAPSTAT	(*( SCU_TRAPSTAT_type *) 0xF0036124U)	/* Trap Status Register */
#define SCU_TRAPSET	(*( SCU_TRAPSET_type *) 0xF0036128U)	/* Trap Set Register */
#define SCU_TRAPCLR	(*( SCU_TRAPCLR_type *) 0xF003612CU)	/* Trap Clear Register */
#define SCU_TRAPDIS	(*( SCU_TRAPDIS_type *) 0xF0036130U)	/* Trap Disable Register */
#define SCU_EVRSTAT	(*( SCU_EVRSTAT_type *) 0xF00360B0U)	/* EVR Status Flag Register */
#define SCU_EVRADCSTAT	(*( SCU_EVRADCSTAT_type *) 0xF003619CU)	/* EVR ADC Status Register */
#define SCU_EVRRSTCON	(*( SCU_EVRRSTCON_type *) 0xF003606CU)	/* EVR Hard Reset Control Register */
#define SCU_EVROVMON	(*( SCU_EVROVMON_type *) 0xF00361A4U)	/* EVR Over-voltage Configuration Register */
#define SCU_EVRUVMON	(*( SCU_EVRUVMON_type *) 0xF00361A0U)	/* EVR Under-voltage Configuration Register */
#define SCU_EVRMONCTRL	(*( SCU_EVRMONCTRL_type *) 0xF00361A8U)	/* EVR Monitor Control Register */
#define SCU_EVR13CON	(*( SCU_EVR13CON_type *) 0xF00360B8U)	/* EVR13 Control Register */
#define SCU_EVR33CON	(*( SCU_EVR33CON_type *) 0xF00360BCU)	/* EVR33 Control Register */
#define SCU_EVRSDCTRL1	(*( SCU_EVRSDCTRL1_type *) 0xF00361B0U)	/* EVR13 SD Control Register 1 */
#define SCU_EVRSDCTRL2	(*( SCU_EVRSDCTRL2_type *) 0xF00361B4U)	/* EVR13 SD Control Register 2 */
#define SCU_EVRSDCTRL3	(*( SCU_EVRSDCTRL3_type *) 0xF00361B8U)	/* EVR13 SD Control Register 3 */
#define SCU_EVRSDCTRL4	(*( SCU_EVRSDCTRL4_type *) 0xF00361BCU)	/* EVR13 SD Control Register 4 */
#define SCU_EVRSDCOEFF1	(*( SCU_EVRSDCOEFF1_type *) 0xF00361C0U)	/* EVR13 SD Coefficient Register 1 */
#define SCU_EVRSDCOEFF2	(*( SCU_EVRSDCOEFF2_type *) 0xF00361C4U)	/* EVR13 SD Coefficient Register 2 */
#define SCU_EVRSDCOEFF3	(*( SCU_EVRSDCOEFF3_type *) 0xF00361C8U)	/* EVR13 SD Coefficient Register 3 */
#define SCU_EVRSDCOEFF4	(*( SCU_EVRSDCOEFF4_type *) 0xF00361CCU)	/* EVR13 SD Coefficient Register 4 */
#define SCU_EVRSDCOEFF5	(*( SCU_EVRSDCOEFF5_type *) 0xF00361D0U)	/* EVR13 SD Coefficient Register 5 */
#define SCU_EVRSDCOEFF6	(*( SCU_EVRSDCOEFF6_type *) 0xF00361D4U)	/* EVR13 SD Coefficient Register 6 */
#define SCU_PMCSR0	(*( SCU_PMCSR0_type *) 0xF00360D4U)	/* Power Management Control and Status Register */
#define SCU_PMCSR1	(*( SCU_PMCSR0_type *) 0xF00360D8U)	/* Power Management Control and Status Register */
#define SCU_PMCSR2	(*( SCU_PMCSR0_type *) 0xF00360DCU)	/* Power Management Control and Status Register */
#define SCU_PMSWCR0	(*( SCU_PMSWCR0_type *) 0xF00360C8U)	/* Standby and Wake-up Control Register 0 */
#define SCU_PMSWCR1	(*( SCU_PMSWCR1_type *) 0xF00360E8U)	/* Standby and Wake-up Control Register 1 */
#define SCU_PMSWSTAT	(*( SCU_PMSWSTAT_type *) 0xF00360CCU)	/* Standby and Wake-up Status Flag Register */
#define SCU_PMSWSTATCLR	(*( SCU_PMSWSTATCLR_type *) 0xF00360D0U)	/* Standby and Wake-up Status Clear Register */
#define SCU_EICR0	(*( SCU_EICR0_type *) 0xF0036210U)	/* External Input Channel Register 0 */
#define SCU_EICR1	(*( SCU_EICR0_type *) 0xF0036214U)	/* External Input Channel Register 1 */
#define SCU_EICR2	(*( SCU_EICR0_type *) 0xF0036218U)	/* External Input Channel Register 2 */
#define SCU_EICR3	(*( SCU_EICR0_type *) 0xF003621CU)	/* External Input Channel Register 3 */
#define SCU_EIFR	(*( SCU_EIFR_type *) 0xF0036220U)	/* External Input Flag Register */
#define SCU_FMR	(*( SCU_FMR_type *) 0xF0036224U)	/* Flag Modification Register */
#define SCU_PDRR	(*( SCU_PDRR_type *) 0xF0036228U)	/* Pattern Detection Result Register */
#define SCU_IGCR0	(*( SCU_IGCR0_type *) 0xF003622CU)	/* Flag Gating Register 0 */
#define SCU_IGCR1	(*( SCU_IGCR0_type *) 0xF0036230U)	/* Flag Gating Register 1 */
#define SCU_IGCR2	(*( SCU_IGCR0_type *) 0xF0036234U)	/* Flag Gating Register 2 */
#define SCU_IGCR3	(*( SCU_IGCR0_type *) 0xF0036238U)	/* Flag Gating Register 3 */
#define SCU_LCLCON0	(*( SCU_LCLCON0_type *) 0xF0036134U)	/* LCL CPU0 Control Register */
#define SCU_LCLCON1	(*( SCU_LCLCON1_type *) 0xF0036138U)	/* LCL CPU1 Control Register */
#define SCU_LCLTEST	(*( SCU_LCLTEST_type *) 0xF003613CU)	/* LCL Test Register */
#define SCU_DTSCON	(*( SCU_DTSCON_type *) 0xF00360E4U)	/* Die Temperature Sensor Control Register */
#define SCU_DTSSTAT	(*( SCU_DTSSTAT_type *) 0xF00360E0U)	/* Die Temperature Sensor Status Register */
#define SCU_DTSLIM	(*( SCU_DTSLIM_type *) 0xF0036240U)	/* Die Temperature Sensor Limit Register */
#define SCU_WDTSCON0	(*( SCU_WDTSCON0_type *) 0xF00360F0U)	/* Safety WDT Control Register 0 */
#define SCU_WDTCPU0CON0	(*( SCU_WDTSCON0_type *) 0xF0036100U)	/* CPU0 WDT Control Register 0 */
#define SCU_WDTCPU1CON0	(*( SCU_WDTSCON0_type *) 0xF003610CU)	/* CPU1 WDT Control Register 0 */
#define SCU_WDTCPU2CON0	(*( SCU_WDTSCON0_type *) 0xF0036118U)	/* CPU2 WDT Control Register 0 */
#define SCU_WDTSCON1	(*( SCU_WDTSCON1_type *) 0xF00360F4U)	/* Safety WDT Control Register 1 */
#define SCU_WDTCPU0CON1	(*( SCU_WDTCPU0CON1_type *) 0xF0036104U)	/* CPU0 WDT Control Register 1 */
#define SCU_WDTCPU1CON1	(*( SCU_WDTCPU0CON1_type *) 0xF0036110U)	/* CPU1 WDT Control Register 1 */
#define SCU_WDTCPU2CON1	(*( SCU_WDTCPU0CON1_type *) 0xF003611CU)	/* CPU2 WDT Control Register 1 */
#define SCU_WDTSSR	(*( SCU_WDTSSR_type *) 0xF00360F8U)	/* Safety WDT Status Register */
#define SCU_WDTCPU0SR	(*( SCU_WDTSSR_type *) 0xF0036108U)	/* CPU0 WDT Status Register */
#define SCU_WDTCPU1SR	(*( SCU_WDTSSR_type *) 0xF0036114U)	/* CPU1 WDT Status Register */
#define SCU_WDTCPU2SR	(*( SCU_WDTSSR_type *) 0xF0036120U)	/* CPU2 WDT Status Register */
#define SCU_SAFECON	(*( SCU_SAFECON_type *) 0xF0036150U)	/* Safety Heartbeat Register */
#define SCU_EMSR	(*( SCU_EMSR_type *) 0xF00360FCU)	/* Emergency Stop Register */
#define SCU_LBISTCTRL0	(*( SCU_LBISTCTRL0_type *) 0xF0036164U)	/* Logic BIST Control 0 Register */
#define SCU_LBISTCTRL1	(*( SCU_LBISTCTRL1_type *) 0xF0036168U)	/* Logic BIST Control 1 Register */
#define SCU_LBISTCTRL2	(*( SCU_LBISTCTRL2_type *) 0xF003616CU)	/* Logic BIST Control 2 Register */
#define SCU_OVCENABLE	(*( SCU_OVCENABLE_type *) 0xF00361E0U)	/* Overlay Enable Register */
#define SCU_OVCCON	(*( SCU_OVCCON_type *) 0xF00361E4U)	/* Overlay Control Register */
#define SCU_SYSCON	(*( SCU_SYSCON_type *) 0xF003607CU)	/* System Control Register */
#define SCU_CHIPID	(*( SCU_CHIPID_type *) 0xF0036140U)	/* Chip Identification Register */
#define SCU_ID	(*( SCU_ID_type *) 0xF0036008U)	/* Identification Register */
#define SCU_MANID	(*( SCU_MANID_type *) 0xF0036144U)	/* Manufacturer Identification Register */
#define SCU_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00363FCU)	/* Access Enable Register 0 */
#define SCU_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00363F8U)	/* Access Enable Register 1 */
#define P00_ID	(*( SCU_ID_type *) 0xF003A008U)	/* Identification Register */
#define P01_ID	(*( SCU_ID_type *) 0xF003A108U)	/* Identification Register */
#define P02_ID	(*( SCU_ID_type *) 0xF003A208U)	/* Identification Register */
#define P10_ID	(*( SCU_ID_type *) 0xF003B008U)	/* Identification Register */
#define P11_ID	(*( SCU_ID_type *) 0xF003B108U)	/* Identification Register */
#define P12_ID	(*( SCU_ID_type *) 0xF003B208U)	/* Identification Register */
#define P13_ID	(*( SCU_ID_type *) 0xF003B308U)	/* Identification Register */
#define P14_ID	(*( SCU_ID_type *) 0xF003B408U)	/* Identification Register */
#define P15_ID	(*( SCU_ID_type *) 0xF003B508U)	/* Identification Register */
#define P20_ID	(*( SCU_ID_type *) 0xF003C008U)	/* Identification Register */
#define P21_ID	(*( SCU_ID_type *) 0xF003C108U)	/* Identification Register */
#define P22_ID	(*( SCU_ID_type *) 0xF003C208U)	/* Identification Register */
#define P23_ID	(*( SCU_ID_type *) 0xF003C308U)	/* Identification Register */
#define P24_ID	(*( SCU_ID_type *) 0xF003C408U)	/* Identification Register */
#define P25_ID	(*( SCU_ID_type *) 0xF003C508U)	/* Identification Register */
#define P26_ID	(*( SCU_ID_type *) 0xF003C608U)	/* Identification Register */
#define P30_ID	(*( SCU_ID_type *) 0xF003D008U)	/* Identification Register */
#define P31_ID	(*( SCU_ID_type *) 0xF003D108U)	/* Identification Register */
#define P32_ID	(*( SCU_ID_type *) 0xF003D208U)	/* Identification Register */
#define P33_ID	(*( SCU_ID_type *) 0xF003D308U)	/* Identification Register */
#define P34_ID	(*( SCU_ID_type *) 0xF003D408U)	/* Identification Register */
#define P40_ID	(*( SCU_ID_type *) 0xF003E008U)	/* Identification Register */
#define P00_IOCR0	(*( P00_IOCR0_type *) 0xF003A010U)	/* Port 00 Input/Output Control Register 0 */
#define P01_IOCR0	(*( P00_IOCR0_type *) 0xF003A110U)	/* Port 01 Input/Output Control Register 0 */
#define P02_IOCR0	(*( P00_IOCR0_type *) 0xF003A210U)	/* Port 02 Input/Output Control Register 0 */
#define P10_IOCR0	(*( P00_IOCR0_type *) 0xF003B010U)	/* Port 10 Input/Output Control Register 0 */
#define P11_IOCR0	(*( P00_IOCR0_type *) 0xF003B110U)	/* Port 11 Input/Output Control Register 0 */
#define P13_IOCR0	(*( P00_IOCR0_type *) 0xF003B310U)	/* Port 13 Input/Output Control Register 0 */
#define P14_IOCR0	(*( P00_IOCR0_type *) 0xF003B410U)	/* Port 14 Input/Output Control Register 0 */
#define P15_IOCR0	(*( P00_IOCR0_type *) 0xF003B510U)	/* Port 15 Input/Output Control Register 0 */
#define P21_IOCR0	(*( P00_IOCR0_type *) 0xF003C110U)	/* Port 21 Input/Output Control Register 0 */
#define P22_IOCR0	(*( P00_IOCR0_type *) 0xF003C210U)	/* Port 22 Input/Output Control Register 0 */
#define P23_IOCR0	(*( P00_IOCR0_type *) 0xF003C310U)	/* Port 23 Input/Output Control Register 0 */
#define P24_IOCR0	(*( P00_IOCR0_type *) 0xF003C410U)	/* Port 24 Input/Output Control Register 0 */
#define P25_IOCR0	(*( P00_IOCR0_type *) 0xF003C510U)	/* Port 25 Input/Output Control Register 0 */
#define P30_IOCR0	(*( P00_IOCR0_type *) 0xF003D010U)	/* Port 30 Input/Output Control Register 0 */
#define P31_IOCR0	(*( P00_IOCR0_type *) 0xF003D110U)	/* Port 31 Input/Output Control Register 0 */
#define P32_IOCR0	(*( P00_IOCR0_type *) 0xF003D210U)	/* Port 32 Input/Output Control Register 0 */
#define P33_IOCR0	(*( P00_IOCR0_type *) 0xF003D310U)	/* Port 33 Input/Output Control Register 0 */
#define P00_IOCR0_1	(*( P00_IOCR0_type *) 0xF003A010U)	/* Port 00 Input/Output Control Register 0 */
#define P01_IOCR0_1	(*( P00_IOCR0_type *) 0xF003A110U)	/* Port 01 Input/Output Control Register 0 */
#define P02_IOCR0_1	(*( P00_IOCR0_type *) 0xF003A210U)	/* Port 02 Input/Output Control Register 0 */
#define P10_IOCR0_1	(*( P00_IOCR0_type *) 0xF003B010U)	/* Port 10 Input/Output Control Register 0 */
#define P11_IOCR0_1	(*( P00_IOCR0_type *) 0xF003B110U)	/* Port 11 Input/Output Control Register 0 */
#define P13_IOCR0_1	(*( P00_IOCR0_type *) 0xF003B310U)	/* Port 13 Input/Output Control Register 0 */
#define P14_IOCR0_1	(*( P00_IOCR0_type *) 0xF003B410U)	/* Port 14 Input/Output Control Register 0 */
#define P15_IOCR0_1	(*( P00_IOCR0_type *) 0xF003B510U)	/* Port 15 Input/Output Control Register 0 */
#define P21_IOCR0_1	(*( P00_IOCR0_type *) 0xF003C110U)	/* Port 21 Input/Output Control Register 0 */
#define P22_IOCR0_1	(*( P00_IOCR0_type *) 0xF003C210U)	/* Port 22 Input/Output Control Register 0 */
#define P23_IOCR0_1	(*( P00_IOCR0_type *) 0xF003C310U)	/* Port 23 Input/Output Control Register 0 */
#define P24_IOCR0_1	(*( P00_IOCR0_type *) 0xF003C410U)	/* Port 24 Input/Output Control Register 0 */
#define P25_IOCR0_1	(*( P00_IOCR0_type *) 0xF003C510U)	/* Port 25 Input/Output Control Register 0 */
#define P30_IOCR0_1	(*( P00_IOCR0_type *) 0xF003D010U)	/* Port 30 Input/Output Control Register 0 */
#define P31_IOCR0_1	(*( P00_IOCR0_type *) 0xF003D110U)	/* Port 31 Input/Output Control Register 0 */
#define P32_IOCR0_1	(*( P00_IOCR0_type *) 0xF003D210U)	/* Port 32 Input/Output Control Register 0 */
#define P33_IOCR0_1	(*( P00_IOCR0_type *) 0xF003D310U)	/* Port 33 Input/Output Control Register 0 */
#define P00_IOCR4	(*( P00_IOCR4_type *) 0xF003A014U)	/* Port 00 Input/Output Control Register 4 */
#define P01_IOCR4	(*( P00_IOCR4_type *) 0xF003A114U)	/* Port 01 Input/Output Control Register 4 */
#define P02_IOCR4	(*( P00_IOCR4_type *) 0xF003A214U)	/* Port 02 Input/Output Control Register 4 */
#define P10_IOCR4	(*( P00_IOCR4_type *) 0xF003B014U)	/* Port 10 Input/Output Control Register 4 */
#define P11_IOCR4	(*( P00_IOCR4_type *) 0xF003B114U)	/* Port 11 Input/Output Control Register 4 */
#define P13_IOCR4	(*( P00_IOCR4_type *) 0xF003B314U)	/* Port 13 Input/Output Control Register 4 */
#define P14_IOCR4	(*( P00_IOCR4_type *) 0xF003B414U)	/* Port 14 Input/Output Control Register 4 */
#define P15_IOCR4	(*( P00_IOCR4_type *) 0xF003B514U)	/* Port 15 Input/Output Control Register 4 */
#define P21_IOCR4	(*( P00_IOCR4_type *) 0xF003C114U)	/* Port 21 Input/Output Control Register 4 */
#define P22_IOCR4	(*( P00_IOCR4_type *) 0xF003C214U)	/* Port 22 Input/Output Control Register 4 */
#define P23_IOCR4	(*( P00_IOCR4_type *) 0xF003C314U)	/* Port 23 Input/Output Control Register 4 */
#define P24_IOCR4	(*( P00_IOCR4_type *) 0xF003C414U)	/* Port 24 Input/Output Control Register 4 */
#define P25_IOCR4	(*( P00_IOCR4_type *) 0xF003C514U)	/* Port 25 Input/Output Control Register 4 */
#define P30_IOCR4	(*( P00_IOCR4_type *) 0xF003D014U)	/* Port 30 Input/Output Control Register 4 */
#define P31_IOCR4	(*( P00_IOCR4_type *) 0xF003D114U)	/* Port 31 Input/Output Control Register 4 */
#define P32_IOCR4	(*( P00_IOCR4_type *) 0xF003D214U)	/* Port 32 Input/Output Control Register 4 */
#define P33_IOCR4	(*( P00_IOCR4_type *) 0xF003D314U)	/* Port 33 Input/Output Control Register 4 */
#define P00_IOCR4_1	(*( P00_IOCR4_type *) 0xF003A014U)	/* Port 00 Input/Output Control Register 4 */
#define P01_IOCR4_1	(*( P00_IOCR4_type *) 0xF003A114U)	/* Port 01 Input/Output Control Register 4 */
#define P02_IOCR4_1	(*( P00_IOCR4_type *) 0xF003A214U)	/* Port 02 Input/Output Control Register 4 */
#define P10_IOCR4_1	(*( P00_IOCR4_type *) 0xF003B014U)	/* Port 10 Input/Output Control Register 4 */
#define P11_IOCR4_1	(*( P00_IOCR4_type *) 0xF003B114U)	/* Port 11 Input/Output Control Register 4 */
#define P13_IOCR4_1	(*( P00_IOCR4_type *) 0xF003B314U)	/* Port 13 Input/Output Control Register 4 */
#define P14_IOCR4_1	(*( P00_IOCR4_type *) 0xF003B414U)	/* Port 14 Input/Output Control Register 4 */
#define P15_IOCR4_1	(*( P00_IOCR4_type *) 0xF003B514U)	/* Port 15 Input/Output Control Register 4 */
#define P21_IOCR4_1	(*( P00_IOCR4_type *) 0xF003C114U)	/* Port 21 Input/Output Control Register 4 */
#define P22_IOCR4_1	(*( P00_IOCR4_type *) 0xF003C214U)	/* Port 22 Input/Output Control Register 4 */
#define P23_IOCR4_1	(*( P00_IOCR4_type *) 0xF003C314U)	/* Port 23 Input/Output Control Register 4 */
#define P24_IOCR4_1	(*( P00_IOCR4_type *) 0xF003C414U)	/* Port 24 Input/Output Control Register 4 */
#define P25_IOCR4_1	(*( P00_IOCR4_type *) 0xF003C514U)	/* Port 25 Input/Output Control Register 4 */
#define P30_IOCR4_1	(*( P00_IOCR4_type *) 0xF003D014U)	/* Port 30 Input/Output Control Register 4 */
#define P31_IOCR4_1	(*( P00_IOCR4_type *) 0xF003D114U)	/* Port 31 Input/Output Control Register 4 */
#define P32_IOCR4_1	(*( P00_IOCR4_type *) 0xF003D214U)	/* Port 32 Input/Output Control Register 4 */
#define P33_IOCR4_1	(*( P00_IOCR4_type *) 0xF003D314U)	/* Port n Input/Output Control Register 4 */
#define P00_IOCR8	(*( P00_IOCR8_type *) 0xF003A018U)	/* Port 00 Input/Output Control Register 8 */
#define P01_IOCR8	(*( P00_IOCR8_type *) 0xF003A118U)	/* Port 01 Input/Output Control Register 8 */
#define P02_IOCR8	(*( P00_IOCR8_type *) 0xF003A218U)	/* Port 02 Input/Output Control Register 8 */
#define P10_IOCR8	(*( P00_IOCR8_type *) 0xF003B018U)	/* Port 10 Input/Output Control Register 8 */
#define P11_IOCR8	(*( P00_IOCR8_type *) 0xF003B118U)	/* Port 11 Input/Output Control Register 8 */
#define P14_IOCR8	(*( P00_IOCR8_type *) 0xF003B418U)	/* Port 14 Input/Output Control Register 8 */
#define P20_IOCR8	(*( P00_IOCR8_type *) 0xF003C018U)	/* Port 20 Input/Output Control Register 8 */
#define P22_IOCR8	(*( P00_IOCR8_type *) 0xF003C218U)	/* Port 22 Input/Output Control Register 8 */
#define P24_IOCR8	(*( P00_IOCR8_type *) 0xF003C418U)	/* Port 24 Input/Output Control Register 8 */
#define P25_IOCR8	(*( P00_IOCR8_type *) 0xF003C518U)	/* Port 25 Input/Output Control Register 8 */
#define P30_IOCR8	(*( P00_IOCR8_type *) 0xF003D018U)	/* Port 30 Input/Output Control Register 8 */
#define P31_IOCR8	(*( P00_IOCR8_type *) 0xF003D118U)	/* Port 31 Input/Output Control Register 8 */
#define P33_IOCR8	(*( P00_IOCR8_type *) 0xF003D318U)	/* Port 33 Input/Output Control Register 8 */
#define P00_IOCR8_1	(*( P00_IOCR8_type *) 0xF003A018U)	/* Port 00 Input/Output Control Register 8 */
#define P01_IOCR8_1	(*( P00_IOCR8_type *) 0xF003A118U)	/* Port 01 Input/Output Control Register 8 */
#define P02_IOCR8_1	(*( P00_IOCR8_type *) 0xF003A218U)	/* Port 02 Input/Output Control Register 8 */
#define P10_IOCR8_1	(*( P00_IOCR8_type *) 0xF003B018U)	/* Port 10 Input/Output Control Register 8 */
#define P11_IOCR8_1	(*( P00_IOCR8_type *) 0xF003B118U)	/* Port 11 Input/Output Control Register 8 */
#define P14_IOCR8_1	(*( P00_IOCR8_type *) 0xF003B418U)	/* Port 14 Input/Output Control Register 8 */
#define P20_IOCR8_1	(*( P00_IOCR8_type *) 0xF003C018U)	/* Port 20 Input/Output Control Register 8 */
#define P22_IOCR8_1	(*( P00_IOCR8_type *) 0xF003C218U)	/* Port 22 Input/Output Control Register 8 */
#define P24_IOCR8_1	(*( P00_IOCR8_type *) 0xF003C418U)	/* Port 24 Input/Output Control Register 8 */
#define P25_IOCR8_1	(*( P00_IOCR8_type *) 0xF003C518U)	/* Port 25 Input/Output Control Register 8 */
#define P30_IOCR8_1	(*( P00_IOCR8_type *) 0xF003D018U)	/* Port 30 Input/Output Control Register 8 */
#define P31_IOCR8_1	(*( P00_IOCR8_type *) 0xF003D118U)	/* Port 31 Input/Output Control Register 8 */
#define P33_IOCR8_1	(*( P00_IOCR8_type *) 0xF003D318U)	/* Port 33 Input/Output Control Register 8 */
#define P00_IOCR12	(*( P00_IOCR12_type *) 0xF003A01CU)	/* Port 00 Input/Output Control Register 12 */
#define P01_IOCR12	(*( P00_IOCR12_type *) 0xF003A11CU)	/* Port 01 Input/Output Control Register 12 */
#define P02_IOCR12	(*( P00_IOCR12_type *) 0xF003A21CU)	/* Port 02 Input/Output Control Register 12 */
#define P11_IOCR12	(*( P00_IOCR12_type *) 0xF003B11CU)	/* Port 11 Input/Output Control Register 12 */
#define P13_IOCR12	(*( P00_IOCR12_type *) 0xF003B31CU)	/* Port 13 Input/Output Control Register 12 */
#define P14_IOCR12	(*( P00_IOCR12_type *) 0xF003B41CU)	/* Port 14 Input/Output Control Register 12 */
#define P15_IOCR12	(*( P00_IOCR12_type *) 0xF003B51CU)	/* Port 15 Input/Output Control Register 12 */
#define P24_IOCR12	(*( P00_IOCR12_type *) 0xF003C41CU)	/* Port 24 Input/Output Control Register 12 */
#define P25_IOCR12	(*( P00_IOCR12_type *) 0xF003C51CU)	/* Port 25 Input/Output Control Register 12 */
#define P30_IOCR12	(*( P00_IOCR12_type *) 0xF003D01CU)	/* Port 30 Input/Output Control Register 12 */
#define P31_IOCR12	(*( P00_IOCR12_type *) 0xF003D11CU)	/* Port 31 Input/Output Control Register 12 */
#define P33_IOCR12	(*( P00_IOCR12_type *) 0xF003D31CU)	/* Port 33 Input/Output Control Register 12 */
#define P00_IOCR12_1	(*( P00_IOCR12_type *) 0xF003A01CU)	/* Port 00 Input/Output Control Register 12 */
#define P01_IOCR12_1	(*( P00_IOCR12_type *) 0xF003A11CU)	/* Port 01 Input/Output Control Register 12 */
#define P02_IOCR12_1	(*( P00_IOCR12_type *) 0xF003A21CU)	/* Port 02 Input/Output Control Register 12 */
#define P11_IOCR12_1	(*( P00_IOCR12_type *) 0xF003B11CU)	/* Port 11 Input/Output Control Register 12 */
#define P13_IOCR12_1	(*( P00_IOCR12_type *) 0xF003B31CU)	/* Port 13 Input/Output Control Register 12 */
#define P14_IOCR12_1	(*( P00_IOCR12_type *) 0xF003B41CU)	/* Port 14 Input/Output Control Register 12 */
#define P15_IOCR12_1	(*( P00_IOCR12_type *) 0xF003B51CU)	/* Port 15 Input/Output Control Register 12 */
#define P24_IOCR12_1	(*( P00_IOCR12_type *) 0xF003C41CU)	/* Port 24 Input/Output Control Register 12 */
#define P25_IOCR12_1	(*( P00_IOCR12_type *) 0xF003C51CU)	/* Port 25 Input/Output Control Register 12 */
#define P30_IOCR12_1	(*( P00_IOCR12_type *) 0xF003D01CU)	/* Port 30 Input/Output Control Register 12 */
#define P31_IOCR12_1	(*( P00_IOCR12_type *) 0xF003D11CU)	/* Port 31 Input/Output Control Register 12 */
#define P33_IOCR12_1	(*( P00_IOCR12_type *) 0xF003D31CU)	/* Port 33 Input/Output Control Register 12 */
#define P00_PDR0	(*( P00_PDR0_type *) 0xF003A040U)	/* Port 00 Pad Driver Mode 0 Register */
#define P01_PDR0	(*( P00_PDR0_type *) 0xF003A140U)	/* Port 01 Pad Driver Mode 0 Register */
#define P02_PDR0	(*( P00_PDR0_type *) 0xF003A240U)	/* Port 02 Pad Driver Mode 0 Register */
#define P10_PDR0	(*( P00_PDR0_type *) 0xF003B040U)	/* Port 10 Pad Driver Mode 0 Register */
#define P11_PDR0	(*( P00_PDR0_type *) 0xF003B140U)	/* Port 11 Pad Driver Mode 0 Register */
#define P14_PDR0	(*( P00_PDR0_type *) 0xF003B440U)	/* Port 14 Pad Driver Mode 0 Register */
#define P15_PDR0	(*( P00_PDR0_type *) 0xF003B540U)	/* Port 15 Pad Driver Mode 0 Register */
#define P21_PDR0	(*( P00_PDR0_type *) 0xF003C140U)	/* Port 21 Pad Driver Mode 0 Register */
#define P22_PDR0	(*( P00_PDR0_type *) 0xF003C240U)	/* Port 22 Pad Driver Mode 0 Register */
#define P23_PDR0	(*( P00_PDR0_type *) 0xF003C340U)	/* Port 23 Pad Driver Mode 0 Register */
#define P24_PDR0	(*( P00_PDR0_type *) 0xF003C440U)	/* Port 24 Pad Driver Mode 0 Register */
#define P25_PDR0	(*( P00_PDR0_type *) 0xF003C540U)	/* Port 25 Pad Driver Mode 0 Register */
#define P30_PDR0	(*( P00_PDR0_type *) 0xF003D040U)	/* Port 30 Pad Driver Mode 0 Register */
#define P31_PDR0	(*( P00_PDR0_type *) 0xF003D140U)	/* Port 31 Pad Driver Mode 0 Register */
#define P32_PDR0	(*( P00_PDR0_type *) 0xF003D240U)	/* Port 32 Pad Driver Mode 0 Register */
#define P33_PDR0	(*( P00_PDR0_type *) 0xF003D340U)	/* Port 33 Pad Driver Mode 0 Register */
#define P00_PDR1	(*( P00_PDR1_type *) 0xF003A044U)	/* Port 00 Pad Driver Mode 1 Register */
#define P01_PDR1	(*( P00_PDR1_type *) 0xF003A144U)	/* Port 01 Pad Driver Mode 1 Register */
#define P02_PDR1	(*( P00_PDR1_type *) 0xF003A244U)	/* Port 02 Pad Driver Mode 1 Register */
#define P11_PDR1	(*( P00_PDR1_type *) 0xF003B144U)	/* Port 11 Pad Driver Mode 1 Register */
#define P14_PDR1	(*( P00_PDR1_type *) 0xF003B444U)	/* Port 14 Pad Driver Mode 1 Register */
#define P24_PDR1	(*( P00_PDR1_type *) 0xF003C444U)	/* Port 24 Pad Driver Mode 1 Register */
#define P25_PDR1	(*( P00_PDR1_type *) 0xF003C544U)	/* Port 25 Pad Driver Mode 1 Register */
#define P30_PDR1	(*( P00_PDR1_type *) 0xF003D044U)	/* Port 30 Pad Driver Mode 1 Register */
#define P31_PDR1	(*( P00_PDR1_type *) 0xF003D144U)	/* Port 31 Pad Driver Mode 1 Register */
#define P33_PDR1	(*( P00_PDR1_type *) 0xF003D344U)	/* Port 33 Pad Driver Mode 1 Register */
#define P40_PDISC	(*( P40_PDISC_type *) 0xF003E060U)	/* Port 40 Pin Function Decision Control Register */
#define P00_OUT	(*( P00_OUT_type *) 0xF003A000U)	/* Port 00 Output Register */
#define P01_OUT	(*( P00_OUT_type *) 0xF003A100U)	/* Port 01 Output Register */
#define P02_OUT	(*( P00_OUT_type *) 0xF003A200U)	/* Port 02 Output Register */
#define P10_OUT	(*( P00_OUT_type *) 0xF003B000U)	/* Port 10 Output Register */
#define P11_OUT	(*( P00_OUT_type *) 0xF003B100U)	/* Port 11 Output Register */
#define P12_OUT	(*( P00_OUT_type *) 0xF003B200U)	/* Port 12 Output Register */
#define P13_OUT	(*( P00_OUT_type *) 0xF003B300U)	/* Port 13 Output Register */
#define P14_OUT	(*( P00_OUT_type *) 0xF003B400U)	/* Port 14 Output Register */
#define P15_OUT	(*( P00_OUT_type *) 0xF003B500U)	/* Port 15 Output Register */
#define P20_OUT	(*( P00_OUT_type *) 0xF003C000U)	/* Port 20 Output Register */
#define P21_OUT	(*( P00_OUT_type *) 0xF003C100U)	/* Port 21 Output Register */
#define P22_OUT	(*( P00_OUT_type *) 0xF003C200U)	/* Port 22 Output Register */
#define P23_OUT	(*( P00_OUT_type *) 0xF003C300U)	/* Port 23 Output Register */
#define P24_OUT	(*( P00_OUT_type *) 0xF003C400U)	/* Port 24 Output Register */
#define P25_OUT	(*( P00_OUT_type *) 0xF003C500U)	/* Port 25 Output Register */
#define P26_OUT	(*( P00_OUT_type *) 0xF003C600U)	/* Port 26 Output Register */
#define P30_OUT	(*( P00_OUT_type *) 0xF003D000U)	/* Port 30 Output Register */
#define P31_OUT	(*( P00_OUT_type *) 0xF003D100U)	/* Port 31 Output Register */
#define P32_OUT	(*( P00_OUT_type *) 0xF003D200U)	/* Port 32 Output Register */
#define P33_OUT	(*( P00_OUT_type *) 0xF003D300U)	/* Port 33 Output Register */
#define P34_OUT	(*( P00_OUT_type *) 0xF003D400U)	/* Port 34 Output Register */
#define P00_OMR	(*( P00_OMR_type *) 0xF003A004U)	/* Port 00 Output Modification Register */
#define P01_OMR	(*( P00_OMR_type *) 0xF003A104U)	/* Port 01 Output Modification Register */
#define P02_OMR	(*( P00_OMR_type *) 0xF003A204U)	/* Port 02 Output Modification Register */
#define P10_OMR	(*( P00_OMR_type *) 0xF003B004U)	/* Port 10 Output Modification Register */
#define P11_OMR	(*( P00_OMR_type *) 0xF003B104U)	/* Port 11 Output Modification Register */
#define P12_OMR	(*( P00_OMR_type *) 0xF003B204U)	/* Port 12 Output Modification Register */
#define P13_OMR	(*( P00_OMR_type *) 0xF003B304U)	/* Port 13 Output Modification Register */
#define P14_OMR	(*( P00_OMR_type *) 0xF003B404U)	/* Port 14 Output Modification Register */
#define P15_OMR	(*( P00_OMR_type *) 0xF003B504U)	/* Port 15 Output Modification Register */
#define P20_OMR	(*( P00_OMR_type *) 0xF003C004U)	/* Port 20 Output Modification Register */
#define P21_OMR	(*( P00_OMR_type *) 0xF003C104U)	/* Port 21 Output Modification Register */
#define P22_OMR	(*( P00_OMR_type *) 0xF003C204U)	/* Port 22 Output Modification Register */
#define P23_OMR	(*( P00_OMR_type *) 0xF003C304U)	/* Port 23 Output Modification Register */
#define P24_OMR	(*( P00_OMR_type *) 0xF003C404U)	/* Port 24 Output Modification Register */
#define P25_OMR	(*( P00_OMR_type *) 0xF003C504U)	/* Port 25 Output Modification Register */
#define P26_OMR	(*( P00_OMR_type *) 0xF003C604U)	/* Port 26 Output Modification Register */
#define P30_OMR	(*( P00_OMR_type *) 0xF003D004U)	/* Port 30 Output Modification Register */
#define P31_OMR	(*( P00_OMR_type *) 0xF003D104U)	/* Port 31 Output Modification Register */
#define P32_OMR	(*( P00_OMR_type *) 0xF003D204U)	/* Port 32 Output Modification Register */
#define P33_OMR	(*( P00_OMR_type *) 0xF003D304U)	/* Port 33 Output Modification Register */
#define P34_OMR	(*( P00_OMR_type *) 0xF003D404U)	/* Port 34 Output Modification Register */
#define P00_OMSR	(*( P00_OMSR_type *) 0xF003A090U)	/* Port 00 Output Modification Set Register */
#define P01_OMSR	(*( P00_OMSR_type *) 0xF003A190U)	/* Port 01 Output Modification Set Register */
#define P02_OMSR	(*( P00_OMSR_type *) 0xF003A290U)	/* Port 02 Output Modification Set Register */
#define P10_OMSR	(*( P00_OMSR_type *) 0xF003B090U)	/* Port 10 Output Modification Set Register */
#define P11_OMSR	(*( P00_OMSR_type *) 0xF003B190U)	/* Port 11 Output Modification Set Register */
#define P12_OMSR	(*( P00_OMSR_type *) 0xF003B290U)	/* Port 12 Output Modification Set Register */
#define P13_OMSR	(*( P00_OMSR_type *) 0xF003B390U)	/* Port 13 Output Modification Set Register */
#define P14_OMSR	(*( P00_OMSR_type *) 0xF003B490U)	/* Port 14 Output Modification Set Register */
#define P15_OMSR	(*( P00_OMSR_type *) 0xF003B590U)	/* Port 15 Output Modification Set Register */
#define P20_OMSR	(*( P00_OMSR_type *) 0xF003C090U)	/* Port 20 Output Modification Set Register */
#define P21_OMSR	(*( P00_OMSR_type *) 0xF003C190U)	/* Port 21 Output Modification Set Register */
#define P22_OMSR	(*( P00_OMSR_type *) 0xF003C290U)	/* Port 22 Output Modification Set Register */
#define P23_OMSR	(*( P00_OMSR_type *) 0xF003C390U)	/* Port 23 Output Modification Set Register */
#define P24_OMSR	(*( P00_OMSR_type *) 0xF003C490U)	/* Port 24 Output Modification Set Register */
#define P25_OMSR	(*( P00_OMSR_type *) 0xF003C590U)	/* Port 25 Output Modification Set Register */
#define P26_OMSR	(*( P00_OMSR_type *) 0xF003C690U)	/* Port 26 Output Modification Set Register */
#define P30_OMSR	(*( P00_OMSR_type *) 0xF003D090U)	/* Port 30 Output Modification Set Register */
#define P31_OMSR	(*( P00_OMSR_type *) 0xF003D190U)	/* Port 31 Output Modification Set Register */
#define P32_OMSR	(*( P00_OMSR_type *) 0xF003D290U)	/* Port 32 Output Modification Set Register */
#define P33_OMSR	(*( P00_OMSR_type *) 0xF003D390U)	/* Port 33 Output Modification Set Register */
#define P34_OMSR	(*( P00_OMSR_type *) 0xF003D490U)	/* Port 34 Output Modification Set Register */
#define P00_OMSR0	(*( P00_OMSR0_type *) 0xF003A070U)	/* Port 00 Output Modification Set Register 0 */
#define P01_OMSR0	(*( P00_OMSR0_type *) 0xF003A170U)	/* Port 01 Output Modification Set Register 0 */
#define P02_OMSR0	(*( P00_OMSR0_type *) 0xF003A270U)	/* Port 02 Output Modification Set Register 0 */
#define P10_OMSR0	(*( P00_OMSR0_type *) 0xF003B070U)	/* Port 10 Output Modification Set Register 0 */
#define P11_OMSR0	(*( P00_OMSR0_type *) 0xF003B170U)	/* Port 11 Output Modification Set Register 0 */
#define P12_OMSR0	(*( P00_OMSR0_type *) 0xF003B270U)	/* Port 12 Output Modification Set Register 0 */
#define P13_OMSR0	(*( P00_OMSR0_type *) 0xF003B370U)	/* Port 13 Output Modification Set Register 0 */
#define P14_OMSR0	(*( P00_OMSR0_type *) 0xF003B470U)	/* Port 14 Output Modification Set Register 0 */
#define P15_OMSR0	(*( P00_OMSR0_type *) 0xF003B570U)	/* Port 15 Output Modification Set Register 0 */
#define P20_OMSR0	(*( P00_OMSR0_type *) 0xF003C070U)	/* Port 20 Output Modification Set Register 0 */
#define P21_OMSR0	(*( P00_OMSR0_type *) 0xF003C170U)	/* Port 21 Output Modification Set Register 0 */
#define P22_OMSR0	(*( P00_OMSR0_type *) 0xF003C270U)	/* Port 22 Output Modification Set Register 0 */
#define P23_OMSR0	(*( P00_OMSR0_type *) 0xF003C370U)	/* Port 23 Output Modification Set Register 0 */
#define P24_OMSR0	(*( P00_OMSR0_type *) 0xF003C470U)	/* Port 24 Output Modification Set Register 0 */
#define P25_OMSR0	(*( P00_OMSR0_type *) 0xF003C570U)	/* Port 25 Output Modification Set Register 0 */
#define P26_OMSR0	(*( P00_OMSR0_type *) 0xF003C670U)	/* Port 26 Output Modification Set Register 0 */
#define P30_OMSR0	(*( P00_OMSR0_type *) 0xF003D070U)	/* Port 30 Output Modification Set Register 0 */
#define P31_OMSR0	(*( P00_OMSR0_type *) 0xF003D170U)	/* Port 31 Output Modification Set Register 0 */
#define P32_OMSR0	(*( P00_OMSR0_type *) 0xF003D270U)	/* Port 32 Output Modification Set Register 0 */
#define P33_OMSR0	(*( P00_OMSR0_type *) 0xF003D370U)	/* Port 33 Output Modification Set Register 0 */
#define P34_OMSR0	(*( P00_OMSR0_type *) 0xF003D470U)	/* Port 34 Output Modification Set Register 0 */
#define P00_OMSR4	(*( P00_OMSR4_type *) 0xF003A074U)	/* Port 00 Output Modification Set Register 4 */
#define P01_OMSR4	(*( P00_OMSR4_type *) 0xF003A174U)	/* Port 01 Output Modification Set Register 4 */
#define P02_OMSR4	(*( P00_OMSR4_type *) 0xF003A274U)	/* Port 02 Output Modification Set Register 4 */
#define P10_OMSR4	(*( P00_OMSR4_type *) 0xF003B074U)	/* Port 10 Output Modification Set Register 4 */
#define P11_OMSR4	(*( P00_OMSR4_type *) 0xF003B174U)	/* Port 11 Output Modification Set Register 4 */
#define P13_OMSR4	(*( P00_OMSR4_type *) 0xF003B374U)	/* Port 13 Output Modification Set Register 4 */
#define P14_OMSR4	(*( P00_OMSR4_type *) 0xF003B474U)	/* Port 14 Output Modification Set Register 4 */
#define P15_OMSR4	(*( P00_OMSR4_type *) 0xF003B574U)	/* Port 15 Output Modification Set Register 4 */
#define P20_OMSR4	(*( P00_OMSR4_type *) 0xF003C074U)	/* Port 20 Output Modification Set Register 4 */
#define P21_OMSR4	(*( P00_OMSR4_type *) 0xF003C174U)	/* Port 21 Output Modification Set Register 4 */
#define P22_OMSR4	(*( P00_OMSR4_type *) 0xF003C274U)	/* Port 22 Output Modification Set Register 4 */
#define P23_OMSR4	(*( P00_OMSR4_type *) 0xF003C374U)	/* Port 23 Output Modification Set Register 4 */
#define P24_OMSR4	(*( P00_OMSR4_type *) 0xF003C474U)	/* Port 24 Output Modification Set Register 4 */
#define P25_OMSR4	(*( P00_OMSR4_type *) 0xF003C574U)	/* Port 25 Output Modification Set Register 4 */
#define P30_OMSR4	(*( P00_OMSR4_type *) 0xF003D074U)	/* Port 30 Output Modification Set Register 4 */
#define P31_OMSR4	(*( P00_OMSR4_type *) 0xF003D174U)	/* Port 31 Output Modification Set Register 4 */
#define P32_OMSR4	(*( P00_OMSR4_type *) 0xF003D274U)	/* Port 32 Output Modification Set Register 4 */
#define P33_OMSR4	(*( P00_OMSR4_type *) 0xF003D374U)	/* Port 33 Output Modification Set Register 4 */
#define P34_OMSR4	(*( P00_OMSR4_type *) 0xF003D474U)	/* Port 34 Output Modification Set Register 4 */
#define P00_OMSR8	(*( P00_OMSR8_type *) 0xF003A078U)	/* Port 00 Output Modification Set Register 8 */
#define P01_OMSR8	(*( P00_OMSR8_type *) 0xF003A178U)	/* Port 01 Output Modification Set Register 8 */
#define P02_OMSR8	(*( P00_OMSR8_type *) 0xF003A278U)	/* Port 02 Output Modification Set Register 8 */
#define P10_OMSR8	(*( P00_OMSR8_type *) 0xF003B078U)	/* Port 10 Output Modification Set Register 8 */
#define P11_OMSR8	(*( P00_OMSR8_type *) 0xF003B178U)	/* Port 11 Output Modification Set Register 8 */
#define P13_OMSR8	(*( P00_OMSR8_type *) 0xF003B378U)	/* Port 13 Output Modification Set Register 8 */
#define P14_OMSR8	(*( P00_OMSR8_type *) 0xF003B478U)	/* Port 14 Output Modification Set Register 8 */
#define P15_OMSR8	(*( P00_OMSR8_type *) 0xF003B578U)	/* Port 15 Output Modification Set Register 8 */
#define P20_OMSR8	(*( P00_OMSR8_type *) 0xF003C078U)	/* Port 20 Output Modification Set Register 8 */
#define P22_OMSR8	(*( P00_OMSR8_type *) 0xF003C278U)	/* Port 22 Output Modification Set Register 8 */
#define P24_OMSR8	(*( P00_OMSR8_type *) 0xF003C478U)	/* Port 24 Output Modification Set Register 8 */
#define P25_OMSR8	(*( P00_OMSR8_type *) 0xF003C578U)	/* Port 25 Output Modification Set Register 8 */
#define P30_OMSR8	(*( P00_OMSR8_type *) 0xF003D078U)	/* Port 30 Output Modification Set Register 8 */
#define P31_OMSR8	(*( P00_OMSR8_type *) 0xF003D178U)	/* Port 31 Output Modification Set Register 8 */
#define P33_OMSR8	(*( P00_OMSR8_type *) 0xF003D378U)	/* Port 33 Output Modification Set Register 8 */
#define P00_OMSR12	(*( P00_OMSR12_type *) 0xF003A07CU)	/* Port 00 Output Modification Set Register 8 */
#define P01_OMSR12	(*( P00_OMSR12_type *) 0xF003A17CU)	/* Port 01 Output Modification Set Register 8 */
#define P02_OMSR12	(*( P00_OMSR12_type *) 0xF003A27CU)	/* Port 02 Output Modification Set Register 8 */
#define P10_OMSR12	(*( P00_OMSR12_type *) 0xF003B07CU)	/* Port 10 Output Modification Set Register 12 */
#define P11_OMSR12	(*( P00_OMSR12_type *) 0xF003B17CU)	/* Port 11 Output Modification Set Register 12 */
#define P13_OMSR12	(*( P00_OMSR12_type *) 0xF003B37CU)	/* Port 13 Output Modification Set Register 12 */
#define P14_OMSR12	(*( P00_OMSR12_type *) 0xF003B47CU)	/* Port 14 Output Modification Set Register 12 */
#define P15_OMSR12	(*( P00_OMSR12_type *) 0xF003B57CU)	/* Port 15 Output Modification Set Register 12 */
#define P20_OMSR12	(*( P00_OMSR12_type *) 0xF003C07CU)	/* Port 20 Output Modification Set Register 12 */
#define P24_OMSR12	(*( P00_OMSR12_type *) 0xF003C47CU)	/* Port 24 Output Modification Set Register 8 */
#define P25_OMSR12	(*( P00_OMSR12_type *) 0xF003C57CU)	/* Port 25 Output Modification Set Register 8 */
#define P30_OMSR12	(*( P00_OMSR12_type *) 0xF003D07CU)	/* Port 30 Output Modification Set Register 8 */
#define P31_OMSR12	(*( P00_OMSR12_type *) 0xF003D17CU)	/* Port 31 Output Modification Set Register 8 */
#define P33_OMSR12	(*( P00_OMSR12_type *) 0xF003D37CU)	/* Port 33 Output Modification Set Register 12 */
#define P00_OMCR	(*( P00_OMCR_type *) 0xF003A094U)	/* Port 00 Output Modification Clear Register */
#define P01_OMCR	(*( P00_OMCR_type *) 0xF003A194U)	/* Port 01 Output Modification Clear Register */
#define P02_OMCR	(*( P00_OMCR_type *) 0xF003A294U)	/* Port 02 Output Modification Clear Register */
#define P10_OMCR	(*( P00_OMCR_type *) 0xF003B094U)	/* Port 10 Output Modification Clear Register */
#define P11_OMCR	(*( P00_OMCR_type *) 0xF003B194U)	/* Port 11 Output Modification Clear Register */
#define P12_OMCR	(*( P00_OMCR_type *) 0xF003B294U)	/* Port 12 Output Modification Clear Register */
#define P13_OMCR	(*( P00_OMCR_type *) 0xF003B394U)	/* Port 13 Output Modification Clear Register */
#define P14_OMCR	(*( P00_OMCR_type *) 0xF003B494U)	/* Port 14 Output Modification Clear Register */
#define P15_OMCR	(*( P00_OMCR_type *) 0xF003B594U)	/* Port 15 Output Modification Clear Register */
#define P20_OMCR	(*( P00_OMCR_type *) 0xF003C094U)	/* Port 20 Output Modification Clear Register */
#define P21_OMCR	(*( P00_OMCR_type *) 0xF003C194U)	/* Port 21 Output Modification Clear Register */
#define P22_OMCR	(*( P00_OMCR_type *) 0xF003C294U)	/* Port 22 Output Modification Clear Register */
#define P23_OMCR	(*( P00_OMCR_type *) 0xF003C394U)	/* Port 23 Output Modification Clear Register */
#define P24_OMCR	(*( P00_OMCR_type *) 0xF003C494U)	/* Port 24 Output Modification Clear Register */
#define P25_OMCR	(*( P00_OMCR_type *) 0xF003C594U)	/* Port 25 Output Modification Clear Register */
#define P26_OMCR	(*( P00_OMCR_type *) 0xF003C694U)	/* Port 26 Output Modification Clear Register */
#define P30_OMCR	(*( P00_OMCR_type *) 0xF003D094U)	/* Port 30 Output Modification Clear Register */
#define P31_OMCR	(*( P00_OMCR_type *) 0xF003D194U)	/* Port 31 Output Modification Clear Register */
#define P32_OMCR	(*( P00_OMCR_type *) 0xF003D294U)	/* Port 32 Output Modification Clear Register */
#define P33_OMCR	(*( P00_OMCR_type *) 0xF003D394U)	/* Port 33 Output Modification Clear Register */
#define P34_OMCR	(*( P00_OMCR_type *) 0xF003D494U)	/* Port 34 Output Modification Clear Register */
#define P00_OMCR0	(*( P00_OMCR0_type *) 0xF003A080U)	/* Port 00 Output Modification Clear Register 0 */
#define P01_OMCR0	(*( P00_OMCR0_type *) 0xF003A180U)	/* Port 01 Output Modification Clear Register 0 */
#define P02_OMCR0	(*( P00_OMCR0_type *) 0xF003A280U)	/* Port 02 Output Modification Clear Register 0 */
#define P10_OMCR0	(*( P00_OMCR0_type *) 0xF003B080U)	/* Port 10 Output Modification Clear Register 0 */
#define P11_OMCR0	(*( P00_OMCR0_type *) 0xF003B180U)	/* Port 11 Output Modification Clear Register 0 */
#define P12_OMCR0	(*( P00_OMCR0_type *) 0xF003B280U)	/* Port 12 Output Modification Clear Register 0 */
#define P13_OMCR0	(*( P00_OMCR0_type *) 0xF003B380U)	/* Port 13 Output Modification Clear Register 0 */
#define P14_OMCR0	(*( P00_OMCR0_type *) 0xF003B480U)	/* Port 14 Output Modification Clear Register 0 */
#define P15_OMCR0	(*( P00_OMCR0_type *) 0xF003B580U)	/* Port 15 Output Modification Clear Register 0 */
#define P20_OMCR0	(*( P00_OMCR0_type *) 0xF003C080U)	/* Port 20 Output Modification Clear Register 0 */
#define P21_OMCR0	(*( P00_OMCR0_type *) 0xF003C180U)	/* Port 21 Output Modification Clear Register 0 */
#define P22_OMCR0	(*( P00_OMCR0_type *) 0xF003C280U)	/* Port 22 Output Modification Clear Register 0 */
#define P23_OMCR0	(*( P00_OMCR0_type *) 0xF003C380U)	/* Port 23 Output Modification Clear Register 0 */
#define P24_OMCR0	(*( P00_OMCR0_type *) 0xF003C480U)	/* Port 24 Output Modification Clear Register 0 */
#define P25_OMCR0	(*( P00_OMCR0_type *) 0xF003C580U)	/* Port 25 Output Modification Clear Register 0 */
#define P26_OMCR0	(*( P00_OMCR0_type *) 0xF003C680U)	/* Port 26 Output Modification Clear Register 0 */
#define P30_OMCR0	(*( P00_OMCR0_type *) 0xF003D080U)	/* Port 30 Output Modification Clear Register 0 */
#define P31_OMCR0	(*( P00_OMCR0_type *) 0xF003D180U)	/* Port 31 Output Modification Clear Register 0 */
#define P32_OMCR0	(*( P00_OMCR0_type *) 0xF003D280U)	/* Port 32 Output Modification Clear Register 0 */
#define P33_OMCR0	(*( P00_OMCR0_type *) 0xF003D380U)	/* Port 33 Output Modification Clear Register 0 */
#define P34_OMCR0	(*( P00_OMCR0_type *) 0xF003D480U)	/* Port 34 Output Modification Clear Register 0 */
#define P00_OMCR4	(*( P00_OMCR4_type *) 0xF003A084U)	/* Port 00 Output Modification Clear Register 4 */
#define P01_OMCR4	(*( P00_OMCR4_type *) 0xF003A184U)	/* Port 01 Output Modification Clear Register 4 */
#define P02_OMCR4	(*( P00_OMCR4_type *) 0xF003A284U)	/* Port 02 Output Modification Clear Register 4 */
#define P10_OMCR4	(*( P00_OMCR4_type *) 0xF003B084U)	/* Port 10 Output Modification Clear Register 4 */
#define P11_OMCR4	(*( P00_OMCR4_type *) 0xF003B184U)	/* Port 11 Output Modification Clear Register 4 */
#define P13_OMCR4	(*( P00_OMCR4_type *) 0xF003B384U)	/* Port 13 Output Modification Clear Register 4 */
#define P14_OMCR4	(*( P00_OMCR4_type *) 0xF003B484U)	/* Port 14 Output Modification Clear Register 4 */
#define P15_OMCR4	(*( P00_OMCR4_type *) 0xF003B584U)	/* Port 15 Output Modification Clear Register 4 */
#define P20_OMCR4	(*( P00_OMCR4_type *) 0xF003C084U)	/* Port 20 Output Modification Clear Register 4 */
#define P21_OMCR4	(*( P00_OMCR4_type *) 0xF003C184U)	/* Port 21 Output Modification Clear Register 4 */
#define P22_OMCR4	(*( P00_OMCR4_type *) 0xF003C284U)	/* Port 22 Output Modification Clear Register 4 */
#define P23_OMCR4	(*( P00_OMCR4_type *) 0xF003C384U)	/* Port 23 Output Modification Clear Register 4 */
#define P24_OMCR4	(*( P00_OMCR4_type *) 0xF003C484U)	/* Port 24 Output Modification Clear Register 4 */
#define P25_OMCR4	(*( P00_OMCR4_type *) 0xF003C584U)	/* Port 25 Output Modification Clear Register 4 */
#define P30_OMCR4	(*( P00_OMCR4_type *) 0xF003D084U)	/* Port 30 Output Modification Clear Register 4 */
#define P31_OMCR4	(*( P00_OMCR4_type *) 0xF003D184U)	/* Port 31 Output Modification Clear Register 4 */
#define P32_OMCR4	(*( P00_OMCR4_type *) 0xF003D284U)	/* Port 32 Output Modification Clear Register 4 */
#define P33_OMCR4	(*( P00_OMCR4_type *) 0xF003D384U)	/* Port 33 Output Modification Clear Register 4 */
#define P34_OMCR4	(*( P00_OMCR4_type *) 0xF003D484U)	/* Port 34 Output Modification Clear Register 4 */
#define P00_OMCR8	(*( P00_OMCR8_type *) 0xF003A088U)	/* Port 00 Output Modification Clear Register 8 */
#define P01_OMCR8	(*( P00_OMCR8_type *) 0xF003A188U)	/* Port 01 Output Modification Clear Register 8 */
#define P02_OMCR8	(*( P00_OMCR8_type *) 0xF003A288U)	/* Port 02 Output Modification Clear Register 8 */
#define P10_OMCR8	(*( P00_OMCR8_type *) 0xF003B088U)	/* Port 10 Output Modification Clear Register 8 */
#define P11_OMCR8	(*( P00_OMCR8_type *) 0xF003B188U)	/* Port 11 Output Modification Clear Register 8 */
#define P13_OMCR8	(*( P00_OMCR8_type *) 0xF003B388U)	/* Port 13 Output Modification Clear Register 8 */
#define P14_OMCR8	(*( P00_OMCR8_type *) 0xF003B488U)	/* Port 14 Output Modification Clear Register 8 */
#define P15_OMCR8	(*( P00_OMCR8_type *) 0xF003B588U)	/* Port 15 Output Modification Clear Register 8 */
#define P20_OMCR8	(*( P00_OMCR8_type *) 0xF003C088U)	/* Port 20 Output Modification Clear Register 8 */
#define P22_OMCR8	(*( P00_OMCR8_type *) 0xF003C288U)	/* Port 22 Output Modification Clear Register 8 */
#define P24_OMCR8	(*( P00_OMCR8_type *) 0xF003C488U)	/* Port 24 Output Modification Clear Register 8 */
#define P25_OMCR8	(*( P00_OMCR8_type *) 0xF003C588U)	/* Port 25 Output Modification Clear Register 8 */
#define P30_OMCR8	(*( P00_OMCR8_type *) 0xF003D088U)	/* Port 30 Output Modification Clear Register 8 */
#define P31_OMCR8	(*( P00_OMCR8_type *) 0xF003D188U)	/* Port 31 Output Modification Clear Register 8 */
#define P33_OMCR8	(*( P00_OMCR8_type *) 0xF003D388U)	/* Port 33 Output Modification Clear Register 8 */
#define P00_OMCR12	(*( P00_OMCR12_type *) 0xF003A08CU)	/* Port 00 Output Modification Clear Register 12 */
#define P01_OMCR12	(*( P00_OMCR12_type *) 0xF003A18CU)	/* Port 01 Output Modification Clear Register 12 */
#define P02_OMCR12	(*( P00_OMCR12_type *) 0xF003A28CU)	/* Port 02 Output Modification Clear Register 12 */
#define P10_OMCR12	(*( P00_OMCR12_type *) 0xF003B08CU)	/* Port 10 Output Modification Clear Register 12 */
#define P11_OMCR12	(*( P00_OMCR12_type *) 0xF003B18CU)	/* Port 11 Output Modification Clear Register 12 */
#define P13_OMCR12	(*( P00_OMCR12_type *) 0xF003B38CU)	/* Port 13 Output Modification Clear Register 12 */
#define P14_OMCR12	(*( P00_OMCR12_type *) 0xF003B48CU)	/* Port 14 Output Modification Clear Register 12 */
#define P15_OMCR12	(*( P00_OMCR12_type *) 0xF003B58CU)	/* Port 15 Output Modification Clear Register 12 */
#define P20_OMCR12	(*( P00_OMCR12_type *) 0xF003C08CU)	/* Port 20 Output Modification Clear Register 12 */
#define P24_OMCR12	(*( P00_OMCR12_type *) 0xF003C48CU)	/* Port 24 Output Modification Clear Register 12 */
#define P25_OMCR12	(*( P00_OMCR12_type *) 0xF003C58CU)	/* Port 25 Output Modification Clear Register 12 */
#define P30_OMCR12	(*( P00_OMCR12_type *) 0xF003D08CU)	/* Port 30 Output Modification Clear Register 12 */
#define P31_OMCR12	(*( P00_OMCR12_type *) 0xF003D18CU)	/* Port 31 Output Modification Clear Register 12 */
#define P33_OMCR12	(*( P00_OMCR12_type *) 0xF003D38CU)	/* Port 33 Output Modification Clear Register 12 */
#define P00_ESR	(*( P00_ESR_type *) 0xF003A050U)	/* Port 00 Emergency Stop Register */
#define P01_ESR	(*( P00_ESR_type *) 0xF003A150U)	/* Port 01 Emergency Stop Register */
#define P02_ESR	(*( P00_ESR_type *) 0xF003A250U)	/* Port 02 Emergency Stop Register */
#define P10_ESR	(*( P00_ESR_type *) 0xF003B050U)	/* Port 10 Emergency Stop Register */
#define P11_ESR	(*( P00_ESR_type *) 0xF003B150U)	/* Port 11 Emergency Stop Register */
#define P12_ESR	(*( P00_ESR_type *) 0xF003B250U)	/* Port 12 Emergency Stop Register */
#define P13_ESR	(*( P00_ESR_type *) 0xF003B350U)	/* Port 13 Emergency Stop Register */
#define P14_ESR	(*( P00_ESR_type *) 0xF003B450U)	/* Port 14 Emergency Stop Register */
#define P15_ESR	(*( P00_ESR_type *) 0xF003B550U)	/* Port 15 Emergency Stop Register */
#define P20_ESR	(*( P00_ESR_type *) 0xF003C050U)	/* Port 20 Emergency Stop Register */
#define P21_ESR	(*( P00_ESR_type *) 0xF003C150U)	/* Port 21 Emergency Stop Register */
#define P22_ESR	(*( P00_ESR_type *) 0xF003C250U)	/* Port 22 Emergency Stop Register */
#define P23_ESR	(*( P00_ESR_type *) 0xF003C350U)	/* Port 23 Emergency Stop Register */
#define P24_ESR	(*( P00_ESR_type *) 0xF003C450U)	/* Port 24 Emergency Stop Register */
#define P25_ESR	(*( P00_ESR_type *) 0xF003C550U)	/* Port 25 Emergency Stop Register */
#define P26_ESR	(*( P00_ESR_type *) 0xF003C650U)	/* Port 26 Emergency Stop Register */
#define P30_ESR	(*( P00_ESR_type *) 0xF003D050U)	/* Port 30 Emergency Stop Register */
#define P31_ESR	(*( P00_ESR_type *) 0xF003D150U)	/* Port 31 Emergency Stop Register */
#define P32_ESR	(*( P00_ESR_type *) 0xF003D250U)	/* Port 32 Emergency Stop Register */
#define P33_ESR	(*( P00_ESR_type *) 0xF003D350U)	/* Port 33 Emergency Stop Register */
#define P34_ESR	(*( P00_ESR_type *) 0xF003D450U)	/* Port 34 Emergency Stop Register */
#define P00_IN	(*( P00_IN_type *) 0xF003A024U)	/* Port 00 Input Register */
#define P01_IN	(*( P00_IN_type *) 0xF003A124U)	/* Port 01 Input Register */
#define P02_IN	(*( P00_IN_type *) 0xF003A224U)	/* Port 02 Input Register */
#define P10_IN	(*( P00_IN_type *) 0xF003B024U)	/* Port 10 Input Register */
#define P11_IN	(*( P00_IN_type *) 0xF003B124U)	/* Port 11 Input Register */
#define P12_IN	(*( P00_IN_type *) 0xF003B224U)	/* Port 12 Input Register */
#define P13_IN	(*( P00_IN_type *) 0xF003B324U)	/* Port 13 Input Register */
#define P14_IN	(*( P00_IN_type *) 0xF003B424U)	/* Port 14 Input Register */
#define P15_IN	(*( P00_IN_type *) 0xF003B524U)	/* Port 15 Input Register */
#define P20_IN	(*( P00_IN_type *) 0xF003C024U)	/* Port 20 Input Register */
#define P21_IN	(*( P00_IN_type *) 0xF003C124U)	/* Port 21 Input Register */
#define P22_IN	(*( P00_IN_type *) 0xF003C224U)	/* Port 22 Input Register */
#define P23_IN	(*( P00_IN_type *) 0xF003C324U)	/* Port 23 Input Register */
#define P24_IN	(*( P00_IN_type *) 0xF003C424U)	/* Port 24 Input Register */
#define P25_IN	(*( P00_IN_type *) 0xF003C524U)	/* Port 25 Input Register */
#define P26_IN	(*( P00_IN_type *) 0xF003C624U)	/* Port 26 Input Register */
#define P30_IN	(*( P00_IN_type *) 0xF003D024U)	/* Port 30 Input Register */
#define P31_IN	(*( P00_IN_type *) 0xF003D124U)	/* Port 31 Input Register */
#define P32_IN	(*( P00_IN_type *) 0xF003D224U)	/* Port 32 Input Register */
#define P33_IN	(*( P00_IN_type *) 0xF003D324U)	/* Port 33 Input Register */
#define P34_IN	(*( P00_IN_type *) 0xF003D424U)	/* Port 34 Input Register */
#define P40_IN	(*( P00_IN_type *) 0xF003E024U)	/* Port 40 Input Register */
#define P00_ACCEN0	(*( P00_ACCEN0_type *) 0xF003A0FCU)	/* Port 00 Access Enable Register 0 */
#define P01_ACCEN0	(*( P00_ACCEN0_type *) 0xF003A1FCU)	/* Port 01 Access Enable Register 0 */
#define P02_ACCEN0	(*( P00_ACCEN0_type *) 0xF003A2FCU)	/* Port 02 Access Enable Register 0 */
#define P10_ACCEN0	(*( P00_ACCEN0_type *) 0xF003B0FCU)	/* Port 10 Access Enable Register 0 */
#define P11_ACCEN0	(*( P00_ACCEN0_type *) 0xF003B1FCU)	/* Port 11 Access Enable Register 0 */
#define P12_ACCEN0	(*( P00_ACCEN0_type *) 0xF003B2FCU)	/* Port 12 Access Enable Register 0 */
#define P13_ACCEN0	(*( P00_ACCEN0_type *) 0xF003B3FCU)	/* Port 13 Access Enable Register 0 */
#define P14_ACCEN0	(*( P00_ACCEN0_type *) 0xF003B4FCU)	/* Port 14 Access Enable Register 0 */
#define P15_ACCEN0	(*( P00_ACCEN0_type *) 0xF003B5FCU)	/* Port 15 Access Enable Register 0 */
#define P20_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C0FCU)	/* Port 20 Access Enable Register 0 */
#define P21_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C1FCU)	/* Port 21 Access Enable Register 0 */
#define P22_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C2FCU)	/* Port 22 Access Enable Register 0 */
#define P23_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C3FCU)	/* Port 23 Access Enable Register 0 */
#define P24_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C4FCU)	/* Port 24 Access Enable Register 0 */
#define P25_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C5FCU)	/* Port 25 Access Enable Register 0 */
#define P26_ACCEN0	(*( P00_ACCEN0_type *) 0xF003C6FCU)	/* Port 26 Access Enable Register 0 */
#define P30_ACCEN0	(*( P00_ACCEN0_type *) 0xF003D0FCU)	/* Port 30 Access Enable Register 0 */
#define P31_ACCEN0	(*( P00_ACCEN0_type *) 0xF003D1FCU)	/* Port 31 Access Enable Register 0 */
#define P32_ACCEN0	(*( P00_ACCEN0_type *) 0xF003D2FCU)	/* Port 32 Access Enable Register 0 */
#define P33_ACCEN0	(*( P00_ACCEN0_type *) 0xF003D3FCU)	/* Port 33 Access Enable Register 0 */
#define P34_ACCEN0	(*( P00_ACCEN0_type *) 0xF003D4FCU)	/* Port 34 Access Enable Register 0 */
#define P40_ACCEN0	(*( P00_ACCEN0_type *) 0xF003E0FCU)	/* Port 40 Access Enable Register 0 */
#define P00_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003A0F8U)	/* Port 00 Access Enable Register 1 */
#define P01_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003A1F8U)	/* Port 01 Access Enable Register 1 */
#define P02_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003A2F8U)	/* Port 02 Access Enable Register 1 */
#define P10_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003B0F8U)	/* Port 10 Access Enable Register 1 */
#define P11_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003B1F8U)	/* Port 11 Access Enable Register 1 */
#define P12_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003B2F8U)	/* Port 12 Access Enable Register 1 */
#define P13_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003B3F8U)	/* Port 13 Access Enable Register 1 */
#define P14_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003B4F8U)	/* Port 14 Access Enable Register 1 */
#define P15_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003B5F8U)	/* Port 15 Access Enable Register 1 */
#define P20_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C0F8U)	/* Port 20 Access Enable Register 1 */
#define P21_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C1F8U)	/* Port 21 Access Enable Register 1 */
#define P22_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C2F8U)	/* Port 22 Access Enable Register 1 */
#define P23_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C3F8U)	/* Port 23 Access Enable Register 1 */
#define P24_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C4F8U)	/* Port 24 Access Enable Register 1 */
#define P25_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C5F8U)	/* Port 25 Access Enable Register 1 */
#define P26_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003C6F8U)	/* Port 26 Access Enable Register 1 */
#define P30_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003D0F8U)	/* Port 30 Access Enable Register 1 */
#define P31_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003D1F8U)	/* Port 31 Access Enable Register 1 */
#define P32_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003D2F8U)	/* Port 32 Access Enable Register 1 */
#define P33_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003D3F8U)	/* Port 33 Access Enable Register 1 */
#define P34_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003D4F8U)	/* Port 34 Access Enable Register 1 */
#define P40_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF003E0F8U)	/* Port 40 Access Enable Register 1 */
#define P00_PCSR	(*( P00_PCSR_type *) 0xF003A064U)	/* Port 00 Pin Controller Select Register */
#define P10_IOCR12	(*( P10_IOCR12_type *) 0xF003B01CU)	/* Port 10 Input/Output Control Register 12 */
#define P10_IOCR12_1	(*( P10_IOCR12_type *) 0xF003B01CU)	/* Port 10 Input/Output Control Register 12 */
#define P10_PDR1	(*( P10_PDR1_type *) 0xF003B044U)	/* Port 10 Pad Driver Mode 1 Register */
#define P11_PCSR	(*( P11_PCSR_type *) 0xF003B164U)	/* Port 11 Pin Controller Select Register */
#define P12_IOCR0	(*( P12_IOCR0_type *) 0xF003B210U)	/* Port 12 Input/Output Control Register 0 */
#define P12_IOCR0_1	(*( P12_IOCR0_type *) 0xF003B210U)	/* Port 12 Input/Output Control Register 0 */
#define P12_PDR0	(*( P12_PDR0_type *) 0xF003B240U)	/* Port 12 Pad Driver Mode 0 Register */
#define P13_IOCR8	(*( P13_IOCR8_type *) 0xF003B318U)	/* Port 13 Input/Output Control Register 8 */
#define P13_IOCR8_1	(*( P13_IOCR8_type *) 0xF003B318U)	/* Port 13 Input/Output Control Register 8 */
#define P13_PDR0	(*( P13_PDR0_type *) 0xF003B340U)	/* Port 13 Pad Driver Mode 0 Register */
#define P13_PDR1	(*( P13_PDR1_type *) 0xF003B344U)	/* Port 13 Pad Driver Mode 1 Register */
#define P13_LPCR0	(*( P13_LPCR0_type *) 0xF003B3A0U)	/* Port 13 LVDS Pad Control Register 0 */
#define P13_LPCR1	(*( P13_LPCR1_type *) 0xF003B3A4U)	/* Port 13 LVDS Pad Control Register 1 */
#define P13_LPCR2	(*( P13_LPCR2_type *) 0xF003B3A8U)	/* Port 13 LVDS Pad Control Register 2 */
#define P13_LPCR3	(*( P13_LPCR3_type *) 0xF003B3ACU)	/* Port 13 LVDS Pad Control Register 3 */
#define P15_IOCR8	(*( P15_IOCR8_type *) 0xF003B518U)	/* Port 15 Input/Output Control Register 8 */
#define P15_IOCR8_1	(*( P15_IOCR8_type *) 0xF003B518U)	/* Port 15 Input/Output Control Register 8 */
#define P15_PDR1	(*( P15_PDR1_type *) 0xF003B544U)	/* Port 15 Pad Driver Mode 1 Register */
#define P20_IOCR0	(*( P20_IOCR0_type *) 0xF003C010U)	/* Port 20 Input/Output Control Register 0 */
#define P20_IOCR0_1	(*( P20_IOCR0_type *) 0xF003C010U)	/* Port 20 Input/Output Control Register 0 */
#define P20_IOCR4	(*( P20_IOCR4_type *) 0xF003C014U)	/* Port 20 Input/Output Control Register 4 */
#define P20_IOCR4_1	(*( P20_IOCR4_type *) 0xF003C014U)	/* Port 20 Input/Output Control Register 4 */
#define P20_IOCR12	(*( P20_IOCR12_type *) 0xF003C01CU)	/* Port 20 Input/Output Control Register 12 */
#define P20_IOCR12_1	(*( P20_IOCR12_type *) 0xF003C01CU)	/* Port 20 Input/Output Control Register 12 */
#define P20_PDR0	(*( P20_PDR0_type *) 0xF003C040U)	/* Port 20 Pad Driver Mode 0 Register */
#define P20_PDR1	(*( P20_PDR1_type *) 0xF003C044U)	/* Port 20 Pad Driver Mode 1 Register */
#define P21_LPCR0	(*( P21_LPCR0_type *) 0xF003C1A0U)	/* Port 21 LVDS Pad Control Register 0 */
#define P21_LPCR1	(*( P21_LPCR0_type *) 0xF003C1A4U)	/* Port 21 LVDS Pad Control Register 1 */
#define P21_LPCR2	(*( P21_LPCR2_type *) 0xF003C1A8U)	/* Port 21 LVDS Pad Control Register 2 */
#define P22_PDR1	(*( P22_PDR1_type *) 0xF003C244U)	/* Port 22 Pad Driver Mode 1 Register */
#define P22_LPCR0	(*( P13_LPCR0_type *) 0xF003C2A0U)	/* Port 22 LVDS Pad Control Register 0 */
#define P22_LPCR1	(*( P13_LPCR1_type *) 0xF003C2A4U)	/* Port 22 LVDS Pad Control Register 1 */
#define P26_IOCR0	(*( P26_IOCR0_type *) 0xF003C610U)	/* Port 26 Input/Output Control Register 0 */
#define P26_IOCR0_1	(*( P26_IOCR0_type *) 0xF003C610U)	/* Port 26 Input/Output Control Register 0 */
#define P26_PDR0	(*( P26_PDR0_type *) 0xF003C640U)	/* Port 26 Pad Driver Mode 0 Register */
#define P34_IOCR0	(*( P34_IOCR0_type *) 0xF003D410U)	/* Port 34 Input/Output Control Register 0 */
#define P34_IOCR0_1	(*( P34_IOCR0_type *) 0xF003D410U)	/* Port 34 Input/Output Control Register 0 */
#define P34_IOCR4	(*( P34_IOCR4_type *) 0xF003D414U)	/* Port 34 Input/Output Control Register 4 */
#define P34_IOCR4_1	(*( P34_IOCR4_type *) 0xF003D414U)	/* Port 34 Input/Output Control Register 4 */
#define P34_PDR0	(*( P34_PDR0_type *) 0xF003D440U)	/* Port 34 Pad Driver Mode 0 Register */
#define P40_IOCR0	(*( P00_IOCR0_type *) 0xF003E010U)	/* Port 40 Input/Output Control Register 0 */
#define P40_IOCR4	(*( P00_IOCR4_type *) 0xF003E014U)	/* Port 40 Input/Output Control Register 4 */
#define P40_IOCR8	(*( P40_IOCR8_type *) 0xF003E018U)	/* Port 40 Input/Output Control Register 8 */
#define P40_IOCR12	(*( P40_IOCR12_type *) 0xF003E01CU)	/* Port 40 Input/Output Control Register 12 */
#define P40_PCSR	(*( P40_PCSR_type *) 0xF003E064U)	/* Port 40 Pin Controller Select Register */
#define SRC_CPU0SBSRC	(*( SRC_CPU0SBSRC_type *) 0xF0038000U)	/* CPU 0 Software Breakpoint Service Request */
#define SRC_CPU1SBSRC	(*( SRC_CPU0SBSRC_type *) 0xF0038004U)	/* CPU 1 Software Breakpoint Service Request */
#define SRC_CPU2SBSRC	(*( SRC_CPU0SBSRC_type *) 0xF0038008U)	/* CPU 2 Software Breakpoint Service Request */
#define SRC_EMEM	(*( SRC_CPU0SBSRC_type *) 0xF0038020U)	/* Emulation Memory Service Request */
#define SRC_AGBT	(*( SRC_CPU0SBSRC_type *) 0xF0038024U)	/* AGBT Service Request */
#define SRC_BCUSPBSBSRC	(*( SRC_CPU0SBSRC_type *) 0xF0038040U)	/* Bus Control Unit SPB Service Request */
#define SRC_XBARSRC	(*( SRC_CPU0SBSRC_type *) 0xF0038048U)	/* XBAR_SRI Service Request */
#define SRC_CERBERUS0	(*( SRC_CPU0SBSRC_type *) 0xF0038050U)	/* Cerberus Service Request 0 */
#define SRC_CERBERUS1	(*( SRC_CPU0SBSRC_type *) 0xF0038054U)	/* Cerberus Service Request 1 */
#define SRC_ASCLIN0TX	(*( SRC_CPU0SBSRC_type *) 0xF0038080U)	/* ASCLIN 0 Transmit Service Request */
#define SRC_ASCLIN1TX	(*( SRC_CPU0SBSRC_type *) 0xF003808CU)	/* ASCLIN 1 Transmit Service Request */
#define SRC_ASCLIN2TX	(*( SRC_CPU0SBSRC_type *) 0xF0038098U)	/* ASCLIN 2 Transmit Service Request */
#define SRC_ASCLIN3TX	(*( SRC_CPU0SBSRC_type *) 0xF00380A4U)	/* ASCLIN 3 Transmit Service Request */
#define SRC_ASCLIN0RX	(*( SRC_CPU0SBSRC_type *) 0xF0038084U)	/* ASCLIN 0 Receive Service Request */
#define SRC_ASCLIN1RX	(*( SRC_CPU0SBSRC_type *) 0xF0038090U)	/* ASCLIN 1 Receive Service Request */
#define SRC_ASCLIN2RX	(*( SRC_CPU0SBSRC_type *) 0xF003809CU)	/* ASCLIN 2 Receive Service Request */
#define SRC_ASCLIN3RX	(*( SRC_CPU0SBSRC_type *) 0xF00380A8U)	/* ASCLIN 3 Receive Service Request */
#define SRC_ASCLIN0ERR	(*( SRC_CPU0SBSRC_type *) 0xF0038088U)	/* ASCLIN 0 Error Service Request */
#define SRC_ASCLIN1ERR	(*( SRC_CPU0SBSRC_type *) 0xF0038094U)	/* ASCLIN 1 Error Service Request */
#define SRC_ASCLIN2ERR	(*( SRC_CPU0SBSRC_type *) 0xF00380A0U)	/* ASCLIN 2 Error Service Request */
#define SRC_ASCLIN3ERR	(*( SRC_CPU0SBSRC_type *) 0xF00380ACU)	/* ASCLIN 3 Error Service Request */
#define SRC_QSPI0TX	(*( SRC_CPU0SBSRC_type *) 0xF0038190U)	/* QSPI 0 Transmit Service Request */
#define SRC_QSPI1TX	(*( SRC_CPU0SBSRC_type *) 0xF00381A8U)	/* QSPI 1 Transmit Service Request */
#define SRC_QSPI2TX	(*( SRC_CPU0SBSRC_type *) 0xF00381C0U)	/* QSPI 2 Transmit Service Request */
#define SRC_QSPI3TX	(*( SRC_CPU0SBSRC_type *) 0xF00381D8U)	/* QSPI 3 Transmit Service Request */
#define SRC_QSPI4TX	(*( SRC_CPU0SBSRC_type *) 0xF00381F0U)	/* QSPI 4 Transmit Service Request */
#define SRC_QSPI5TX	(*( SRC_CPU0SBSRC_type *) 0xF0038208U)	/* QSPI 5 Transmit Service Request */
#define SRC_QSPI0RX	(*( SRC_CPU0SBSRC_type *) 0xF0038194U)	/* QSPI 0 Receive Service Request */
#define SRC_QSPI1RX	(*( SRC_CPU0SBSRC_type *) 0xF00381ACU)	/* QSPI 1 Receive Service Request */
#define SRC_QSPI2RX	(*( SRC_CPU0SBSRC_type *) 0xF00381C4U)	/* QSPI 2 Receive Service Request */
#define SRC_QSPI3RX	(*( SRC_CPU0SBSRC_type *) 0xF00381DCU)	/* QSPI 3 Receive Service Request */
#define SRC_QSPI4RX	(*( SRC_CPU0SBSRC_type *) 0xF00381F4U)	/* QSPI 4 Receive Service Request */
#define SRC_QSPI5RX	(*( SRC_CPU0SBSRC_type *) 0xF003820CU)	/* QSPI 5 Receive Service Request */
#define SRC_QSPI0ERR	(*( SRC_CPU0SBSRC_type *) 0xF0038198U)	/* QSPI 0 Error Service Request */
#define SRC_QSPI1ERR	(*( SRC_CPU0SBSRC_type *) 0xF00381B0U)	/* QSPI 1 Error Service Request */
#define SRC_QSPI2ERR	(*( SRC_CPU0SBSRC_type *) 0xF00381C8U)	/* QSPI 2 Error Service Request */
#define SRC_QSPI3ERR	(*( SRC_CPU0SBSRC_type *) 0xF00381E0U)	/* QSPI 3 Error Service Request */
#define SRC_QSPI4ERR	(*( SRC_CPU0SBSRC_type *) 0xF00381F8U)	/* QSPI 4 Error Service Request */
#define SRC_QSPI5ERR	(*( SRC_CPU0SBSRC_type *) 0xF0038210U)	/* QSPI 5 Error Service Request */
#define SRC_QSPI0PT	(*( SRC_CPU0SBSRC_type *) 0xF003819CU)	/* QSPI 0 Phase Transition Service Request */
#define SRC_QSPI1PT	(*( SRC_CPU0SBSRC_type *) 0xF00381B4U)	/* QSPI 1 Phase Transition Service Request */
#define SRC_QSPI2PT	(*( SRC_CPU0SBSRC_type *) 0xF00381CCU)	/* QSPI 2 Phase Transition Service Request */
#define SRC_QSPI3PT	(*( SRC_CPU0SBSRC_type *) 0xF00381E4U)	/* QSPI 3 Phase Transition Service Request */
#define SRC_QSPI4PT	(*( SRC_CPU0SBSRC_type *) 0xF00381FCU)	/* QSPI 4 Phase Transition Service Request */
#define SRC_QSPI5PT	(*( SRC_CPU0SBSRC_type *) 0xF0038214U)	/* QSPI 5 Phase Transition Service Request */
#define SRC_RESERVED10	(*( SRC_CPU0SBSRC_type *) 0xF00381A0U)	/* Reserved Service Request 10 */
#define SRC_RESERVED11	(*( SRC_CPU0SBSRC_type *) 0xF00381B8U)	/* Reserved Service Request 11 */
#define SRC_QSPI2HC	(*( SRC_CPU0SBSRC_type *) 0xF00381D0U)	/* QSPI 2 High Speed Capture Service Request */
#define SRC_QSPI3HC	(*( SRC_CPU0SBSRC_type *) 0xF00381E8U)	/* QSPI 3 High Speed Capture Service Request */
#define SRC_RESERVED14	(*( SRC_CPU0SBSRC_type *) 0xF0038200U)	/* Reserved Service Request 14 */
#define SRC_RESERVED15	(*( SRC_CPU0SBSRC_type *) 0xF0038218U)	/* Reserved Service Request 15 */
#define SRC_QSPI0U	(*( SRC_CPU0SBSRC_type *) 0xF00381A4U)	/* QSPI 0 User Defined Service Request */
#define SRC_QSPI1U	(*( SRC_CPU0SBSRC_type *) 0xF00381BCU)	/* QSPI 1 User Defined Service Request */
#define SRC_QSPI2U	(*( SRC_CPU0SBSRC_type *) 0xF00381D4U)	/* QSPI 2 User Defined Service Request */
#define SRC_QSPI3U	(*( SRC_CPU0SBSRC_type *) 0xF00381ECU)	/* QSPI 3 User Defined Service Request */
#define SRC_QSPI4U	(*( SRC_CPU0SBSRC_type *) 0xF0038204U)	/* QSPI 4 User Defined Service Request */
#define SRC_QSPI5U	(*( SRC_CPU0SBSRC_type *) 0xF003821CU)	/* QSPI 5 User Defined Service Request */
#define SRC_HSCT	(*( SRC_CPU0SBSRC_type *) 0xF0038290U)	/* HSCT Service Request */
#define SRC_HSSLCOK0	(*( SRC_CPU0SBSRC_type *) 0xF00382A0U)	/* Channel 0 OK Service Request m */
#define SRC_HSSLCOK1	(*( SRC_CPU0SBSRC_type *) 0xF00382B0U)	/* Channel 1 OK Service Request m */
#define SRC_HSSLCOK2	(*( SRC_CPU0SBSRC_type *) 0xF00382C0U)	/* Channel 2 OK Service Request m */
#define SRC_HSSLCOK3	(*( SRC_CPU0SBSRC_type *) 0xF00382D0U)	/* Channel 3 OK Service Request m */
#define SRC_HSSLRDI0	(*( SRC_CPU0SBSRC_type *) 0xF00382A4U)	/* Channel 0 Read Data Service Request m */
#define SRC_HSSLRDI1	(*( SRC_CPU0SBSRC_type *) 0xF00382B4U)	/* Channel 1 Read Data Service Request m */
#define SRC_HSSLRDI2	(*( SRC_CPU0SBSRC_type *) 0xF00382C4U)	/* Channel 2 Read Data Service Request m */
#define SRC_HSSLRDI3	(*( SRC_CPU0SBSRC_type *) 0xF00382D4U)	/* Channel 3 Read Data Service Request m */
#define SRC_HSSLERR0	(*( SRC_CPU0SBSRC_type *) 0xF00382A8U)	/* Channel 0 Error ServiceRequest m */
#define SRC_HSSLERR1	(*( SRC_CPU0SBSRC_type *) 0xF00382B8U)	/* Channel 1 Error ServiceRequest m */
#define SRC_HSSLERR2	(*( SRC_CPU0SBSRC_type *) 0xF00382C8U)	/* Channel 2 Error ServiceRequest m */
#define SRC_HSSLERR3	(*( SRC_CPU0SBSRC_type *) 0xF00382D8U)	/* Channel 3 Error ServiceRequest m */
#define SRC_HSSLTRG0	(*( SRC_CPU0SBSRC_type *) 0xF00382ACU)	/* Channel 0 Trigger Service Request m */
#define SRC_HSSLTRG1	(*( SRC_CPU0SBSRC_type *) 0xF00382BCU)	/* Channel 1 Trigger Service Request m */
#define SRC_HSSLTRG2	(*( SRC_CPU0SBSRC_type *) 0xF00382CCU)	/* Channel 2 Trigger Service Request m */
#define SRC_HSSLTRG3	(*( SRC_CPU0SBSRC_type *) 0xF00382DCU)	/* Channel 3 Trigger Service Request m */
#define SRC_HSSLEXI	(*( SRC_CPU0SBSRC_type *) 0xF00382E0U)	/* Exception Service Request */
#define SRC_I2C0BREQ	(*( SRC_CPU0SBSRC_type *) 0xF0038300U)	/* I2C 0 Burst Data Transfer Request */
#define SRC_I2C0LBREQ	(*( SRC_CPU0SBSRC_type *) 0xF0038304U)	/* I2C 0 Last Burst Data Transfer Service Request */
#define SRC_I2C0SREQ	(*( SRC_CPU0SBSRC_type *) 0xF0038308U)	/* I2C 0 Single Data Transfer Service Request */
#define SRC_I2C0LSREQ	(*( SRC_CPU0SBSRC_type *) 0xF003830CU)	/* I2C 0 Last Single Data Transfer Service Request */
#define SRC_I2C0ERR	(*( SRC_CPU0SBSRC_type *) 0xF0038310U)	/* I2C 0 Error Service Request */
#define SRC_I2C0P	(*( SRC_CPU0SBSRC_type *) 0xF0038314U)	/* I2C 0 Kernel Service Request */
#define SRC_I2C1BREQ	(*( SRC_CPU0SBSRC_type *) 0xF0038318U)	/* I2C 1 Burst Data Transfer Request */
#define SRC_I2C1LBREQ	(*( SRC_CPU0SBSRC_type *) 0xF003831CU)	/* I2C 1 Last Burst Data Transfer Service Request */
#define SRC_I2C1SREQ	(*( SRC_CPU0SBSRC_type *) 0xF0038320U)	/* I2C 1 Single Data Transfer Service Request */
#define SRC_I2C1LSREQ	(*( SRC_CPU0SBSRC_type *) 0xF0038324U)	/* I2C 1 Last Single Data Transfer Service Request */
#define SRC_I2C1ERR	(*( SRC_CPU0SBSRC_type *) 0xF0038328U)	/* I2C 1 Error Service Request */
#define SRC_I2C1P	(*( SRC_CPU0SBSRC_type *) 0xF003832CU)	/* I2C 1 Kernel Service Request */
#define SRC_SENT0	(*( SRC_CPU0SBSRC_type *) 0xF0038350U)	/* SENT TRIG0 Service Request */
#define SRC_SENT1	(*( SRC_CPU0SBSRC_type *) 0xF0038354U)	/* SENT TRIG1 Service Request */
#define SRC_SENT2	(*( SRC_CPU0SBSRC_type *) 0xF0038358U)	/* SENT TRIG2 Service Request */
#define SRC_SENT3	(*( SRC_CPU0SBSRC_type *) 0xF003835CU)	/* SENT TRIG3 Service Request */
#define SRC_SENT4	(*( SRC_CPU0SBSRC_type *) 0xF0038360U)	/* SENT TRIG4 Service Request */
#define SRC_SENT5	(*( SRC_CPU0SBSRC_type *) 0xF0038364U)	/* SENT TRIG5 Service Request */
#define SRC_SENT6	(*( SRC_CPU0SBSRC_type *) 0xF0038368U)	/* SENT TRIG6 Service Request */
#define SRC_SENT7	(*( SRC_CPU0SBSRC_type *) 0xF003836CU)	/* SENT TRIG7 Service Request */
#define SRC_SENT8	(*( SRC_CPU0SBSRC_type *) 0xF0038370U)	/* SENT TRIG8 Service Request */
#define SRC_SENT9	(*( SRC_CPU0SBSRC_type *) 0xF0038374U)	/* SENT TRIG9 Service Request */
#define SRC_SENT10	(*( SRC_CPU0SBSRC_type *) 0xF0038378U)	/* SENT TRIG10 Service Request */
#define SRC_SENT11	(*( SRC_CPU0SBSRC_type *) 0xF003837CU)	/* SENT TRIG11 Service Request */
#define SRC_SENT12	(*( SRC_CPU0SBSRC_type *) 0xF0038380U)	/* SENT TRIG12 Service Request */
#define SRC_SENT13	(*( SRC_CPU0SBSRC_type *) 0xF0038384U)	/* SENT TRIG13 Service Request */
#define SRC_SENT14	(*( SRC_CPU0SBSRC_type *) 0xF0038388U)	/* SENT TRIG14 Service Request */
#define SRC_MSC0SR0	(*( SRC_CPU0SBSRC_type *) 0xF00383E0U)	/* MSC 0 Service Request 0 */
#define SRC_MSC1SR0	(*( SRC_CPU0SBSRC_type *) 0xF00383F4U)	/* MSC 1 Service Request 0 */
#define SRC_MSC2SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038408U)	/* MSC 2 Service Request 0 */
#define SRC_MSC0SR1	(*( SRC_CPU0SBSRC_type *) 0xF00383E4U)	/* MSC 0 Service Request 1 */
#define SRC_MSC1SR1	(*( SRC_CPU0SBSRC_type *) 0xF00383F8U)	/* MSC 1 Service Request 1 */
#define SRC_MSC2SR1	(*( SRC_CPU0SBSRC_type *) 0xF003840CU)	/* MSC 2 Service Request 1 */
#define SRC_MSC0SR2	(*( SRC_CPU0SBSRC_type *) 0xF00383E8U)	/* MSC 0 Service Request 2 */
#define SRC_MSC1SR2	(*( SRC_CPU0SBSRC_type *) 0xF00383FCU)	/* MSC 1 Service Request 2 */
#define SRC_MSC2SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038410U)	/* MSC 2 Service Request 2 */
#define SRC_MSC0SR3	(*( SRC_CPU0SBSRC_type *) 0xF00383ECU)	/* MSC 0 Service Request 3 */
#define SRC_MSC1SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038400U)	/* MSC 1 Service Request 3 */
#define SRC_MSC2SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038414U)	/* MSC 2 Service Request 3 */
#define SRC_MSC0SR4	(*( SRC_CPU0SBSRC_type *) 0xF00383F0U)	/* MSC 0 Service Request 4 */
#define SRC_MSC1SR4	(*( SRC_CPU0SBSRC_type *) 0xF0038404U)	/* MSC 1 Service Request 4 */
#define SRC_MSC2SR4	(*( SRC_CPU0SBSRC_type *) 0xF0038418U)	/* MSC 2 Service Request 4 */
#define SRC_CCU60SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038420U)	/* CCU6 0 Service Request 0 */
#define SRC_CCU61SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038430U)	/* CCU6 1 Service Request 0 */
#define SRC_CCU60SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038424U)	/* CCU6 0 Service Request 1 */
#define SRC_CCU61SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038434U)	/* CCU6 1 Service Request 1 */
#define SRC_CCU60SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038428U)	/* CCU6 0 Service Request 2 */
#define SRC_CCU61SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038438U)	/* CCU6 1 Service Request 2 */
#define SRC_CCU60SR3	(*( SRC_CPU0SBSRC_type *) 0xF003842CU)	/* CCU6 0 Service Request 3 */
#define SRC_CCU61SR3	(*( SRC_CPU0SBSRC_type *) 0xF003843CU)	/* CCU6 1 Service Request 3 */
#define SRC_GPT120CIRQ	(*( SRC_CPU0SBSRC_type *) 0xF0038460U)	/* GPT120 CAPREL Service Request */
#define SRC_GPT120T2	(*( SRC_CPU0SBSRC_type *) 0xF0038464U)	/* GPT120 T2 Overflow/Underflow Service Request */
#define SRC_GPT120T3	(*( SRC_CPU0SBSRC_type *) 0xF0038468U)	/* GPT120 T3 Overflow/Underflow Service Request */
#define SRC_GPT120T4	(*( SRC_CPU0SBSRC_type *) 0xF003846CU)	/* GPT120 T4 Overflow/Underflow Service Request */
#define SRC_GPT120T5	(*( SRC_CPU0SBSRC_type *) 0xF0038470U)	/* GPT120 T5 Overflow/Underflow Service Request */
#define SRC_GPT120T6	(*( SRC_CPU0SBSRC_type *) 0xF0038474U)	/* GPT120 T6 Overflow/Underflow Service Request */
#define SRC_STM0SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038490U)	/* System Timer 0 Service Request 0 */
#define SRC_STM1SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038498U)	/* System Timer 1 Service Request 0 */
#define SRC_STM2SR0	(*( SRC_CPU0SBSRC_type *) 0xF00384A0U)	/* System Timer 2 Service Request 0 */
#define SRC_STM0SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038494U)	/* System Timer 0 Service Request 1 */
#define SRC_STM1SR1	(*( SRC_CPU0SBSRC_type *) 0xF003849CU)	/* System Timer 1 Service Request 1 */
#define SRC_STM2SR1	(*( SRC_CPU0SBSRC_type *) 0xF00384A4U)	/* System Timer 2 Service Request 1 */
#define SRC_FCE	(*( SRC_CPU0SBSRC_type *) 0xF00384B0U)	/* FCE Error Service Request */
#define SRC_DMAERR	(*( SRC_CPU0SBSRC_type *) 0xF00384F0U)	/* DMA Error Service Request */
#define SRC_DMACH0	(*( SRC_CPU0SBSRC_type *) 0xF0038500U)	/* DMA Channel 0 Service Request */
#define SRC_DMACH1	(*( SRC_CPU0SBSRC_type *) 0xF0038504U)	/* DMA Channel 1 Service Request */
#define SRC_DMACH2	(*( SRC_CPU0SBSRC_type *) 0xF0038508U)	/* DMA Channel 2 Service Request */
#define SRC_DMACH3	(*( SRC_CPU0SBSRC_type *) 0xF003850CU)	/* DMA Channel 3 Service Request */
#define SRC_DMACH4	(*( SRC_CPU0SBSRC_type *) 0xF0038510U)	/* DMA Channel 4 Service Request */
#define SRC_DMACH5	(*( SRC_CPU0SBSRC_type *) 0xF0038514U)	/* DMA Channel 5 Service Request */
#define SRC_DMACH6	(*( SRC_CPU0SBSRC_type *) 0xF0038518U)	/* DMA Channel 6 Service Request */
#define SRC_DMACH7	(*( SRC_CPU0SBSRC_type *) 0xF003851CU)	/* DMA Channel 7 Service Request */
#define SRC_DMACH8	(*( SRC_CPU0SBSRC_type *) 0xF0038520U)	/* DMA Channel 8 Service Request */
#define SRC_DMACH9	(*( SRC_CPU0SBSRC_type *) 0xF0038524U)	/* DMA Channel 9 Service Request */
#define SRC_DMACH10	(*( SRC_CPU0SBSRC_type *) 0xF0038528U)	/* DMA Channel 10 Service Request */
#define SRC_DMACH11	(*( SRC_CPU0SBSRC_type *) 0xF003852CU)	/* DMA Channel 11 Service Request */
#define SRC_DMACH12	(*( SRC_CPU0SBSRC_type *) 0xF0038530U)	/* DMA Channel 12 Service Request */
#define SRC_DMACH13	(*( SRC_CPU0SBSRC_type *) 0xF0038534U)	/* DMA Channel 13 Service Request */
#define SRC_DMACH14	(*( SRC_CPU0SBSRC_type *) 0xF0038538U)	/* DMA Channel 14 Service Request */
#define SRC_DMACH15	(*( SRC_CPU0SBSRC_type *) 0xF003853CU)	/* DMA Channel 15 Service Request */
#define SRC_DMACH16	(*( SRC_CPU0SBSRC_type *) 0xF0038540U)	/* DMA Channel 16 Service Request */
#define SRC_DMACH17	(*( SRC_CPU0SBSRC_type *) 0xF0038544U)	/* DMA Channel 17 Service Request */
#define SRC_DMACH18	(*( SRC_CPU0SBSRC_type *) 0xF0038548U)	/* DMA Channel 18 Service Request */
#define SRC_DMACH19	(*( SRC_CPU0SBSRC_type *) 0xF003854CU)	/* DMA Channel 19 Service Request */
#define SRC_DMACH20	(*( SRC_CPU0SBSRC_type *) 0xF0038550U)	/* DMA Channel 20 Service Request */
#define SRC_DMACH21	(*( SRC_CPU0SBSRC_type *) 0xF0038554U)	/* DMA Channel 21 Service Request */
#define SRC_DMACH22	(*( SRC_CPU0SBSRC_type *) 0xF0038558U)	/* DMA Channel 22 Service Request */
#define SRC_DMACH23	(*( SRC_CPU0SBSRC_type *) 0xF003855CU)	/* DMA Channel 23 Service Request */
#define SRC_DMACH24	(*( SRC_CPU0SBSRC_type *) 0xF0038560U)	/* DMA Channel 24 Service Request */
#define SRC_DMACH25	(*( SRC_CPU0SBSRC_type *) 0xF0038564U)	/* DMA Channel 25 Service Request */
#define SRC_DMACH26	(*( SRC_CPU0SBSRC_type *) 0xF0038568U)	/* DMA Channel 26 Service Request */
#define SRC_DMACH27	(*( SRC_CPU0SBSRC_type *) 0xF003856CU)	/* DMA Channel 27 Service Request */
#define SRC_DMACH28	(*( SRC_CPU0SBSRC_type *) 0xF0038570U)	/* DMA Channel 28 Service Request */
#define SRC_DMACH29	(*( SRC_CPU0SBSRC_type *) 0xF0038574U)	/* DMA Channel 29 Service Request */
#define SRC_DMACH30	(*( SRC_CPU0SBSRC_type *) 0xF0038578U)	/* DMA Channel 30 Service Request */
#define SRC_DMACH31	(*( SRC_CPU0SBSRC_type *) 0xF003857CU)	/* DMA Channel 31 Service Request */
#define SRC_DMACH32	(*( SRC_CPU0SBSRC_type *) 0xF0038580U)	/* DMA Channel 32 Service Request */
#define SRC_DMACH33	(*( SRC_CPU0SBSRC_type *) 0xF0038584U)	/* DMA Channel 33 Service Request */
#define SRC_DMACH34	(*( SRC_CPU0SBSRC_type *) 0xF0038588U)	/* DMA Channel 34 Service Request */
#define SRC_DMACH35	(*( SRC_CPU0SBSRC_type *) 0xF003858CU)	/* DMA Channel 35 Service Request */
#define SRC_DMACH36	(*( SRC_CPU0SBSRC_type *) 0xF0038590U)	/* DMA Channel 36 Service Request */
#define SRC_DMACH37	(*( SRC_CPU0SBSRC_type *) 0xF0038594U)	/* DMA Channel 37 Service Request */
#define SRC_DMACH38	(*( SRC_CPU0SBSRC_type *) 0xF0038598U)	/* DMA Channel 38 Service Request */
#define SRC_DMACH39	(*( SRC_CPU0SBSRC_type *) 0xF003859CU)	/* DMA Channel 39 Service Request */
#define SRC_DMACH40	(*( SRC_CPU0SBSRC_type *) 0xF00385A0U)	/* DMA Channel 40 Service Request */
#define SRC_DMACH41	(*( SRC_CPU0SBSRC_type *) 0xF00385A4U)	/* DMA Channel 41 Service Request */
#define SRC_DMACH42	(*( SRC_CPU0SBSRC_type *) 0xF00385A8U)	/* DMA Channel 42 Service Request */
#define SRC_DMACH43	(*( SRC_CPU0SBSRC_type *) 0xF00385ACU)	/* DMA Channel 43 Service Request */
#define SRC_DMACH44	(*( SRC_CPU0SBSRC_type *) 0xF00385B0U)	/* DMA Channel 44 Service Request */
#define SRC_DMACH45	(*( SRC_CPU0SBSRC_type *) 0xF00385B4U)	/* DMA Channel 45 Service Request */
#define SRC_DMACH46	(*( SRC_CPU0SBSRC_type *) 0xF00385B8U)	/* DMA Channel 46 Service Request */
#define SRC_DMACH47	(*( SRC_CPU0SBSRC_type *) 0xF00385BCU)	/* DMA Channel 47 Service Request */
#define SRC_DMACH48	(*( SRC_CPU0SBSRC_type *) 0xF00385C0U)	/* DMA Channel 48 Service Request */
#define SRC_DMACH49	(*( SRC_CPU0SBSRC_type *) 0xF00385C4U)	/* DMA Channel 49 Service Request */
#define SRC_DMACH50	(*( SRC_CPU0SBSRC_type *) 0xF00385C8U)	/* DMA Channel 50 Service Request */
#define SRC_DMACH51	(*( SRC_CPU0SBSRC_type *) 0xF00385CCU)	/* DMA Channel 51 Service Request */
#define SRC_DMACH52	(*( SRC_CPU0SBSRC_type *) 0xF00385D0U)	/* DMA Channel 52 Service Request */
#define SRC_DMACH53	(*( SRC_CPU0SBSRC_type *) 0xF00385D4U)	/* DMA Channel 53 Service Request */
#define SRC_DMACH54	(*( SRC_CPU0SBSRC_type *) 0xF00385D8U)	/* DMA Channel 54 Service Request */
#define SRC_DMACH55	(*( SRC_CPU0SBSRC_type *) 0xF00385DCU)	/* DMA Channel 55 Service Request */
#define SRC_DMACH56	(*( SRC_CPU0SBSRC_type *) 0xF00385E0U)	/* DMA Channel 56 Service Request */
#define SRC_DMACH57	(*( SRC_CPU0SBSRC_type *) 0xF00385E4U)	/* DMA Channel 57 Service Request */
#define SRC_DMACH58	(*( SRC_CPU0SBSRC_type *) 0xF00385E8U)	/* DMA Channel 58 Service Request */
#define SRC_DMACH59	(*( SRC_CPU0SBSRC_type *) 0xF00385ECU)	/* DMA Channel 59 Service Request */
#define SRC_DMACH60	(*( SRC_CPU0SBSRC_type *) 0xF00385F0U)	/* DMA Channel 60 Service Request */
#define SRC_DMACH61	(*( SRC_CPU0SBSRC_type *) 0xF00385F4U)	/* DMA Channel 61 Service Request */
#define SRC_DMACH62	(*( SRC_CPU0SBSRC_type *) 0xF00385F8U)	/* DMA Channel 62 Service Request */
#define SRC_DMACH63	(*( SRC_CPU0SBSRC_type *) 0xF00385FCU)	/* DMA Channel 63 Service Request */
#define SRC_DMACH64	(*( SRC_CPU0SBSRC_type *) 0xF0038600U)	/* DMA Channel 64 Service Request */
#define SRC_DMACH65	(*( SRC_CPU0SBSRC_type *) 0xF0038604U)	/* DMA Channel 65 Service Request */
#define SRC_DMACH66	(*( SRC_CPU0SBSRC_type *) 0xF0038608U)	/* DMA Channel 66 Service Request */
#define SRC_DMACH67	(*( SRC_CPU0SBSRC_type *) 0xF003860CU)	/* DMA Channel 67 Service Request */
#define SRC_DMACH68	(*( SRC_CPU0SBSRC_type *) 0xF0038610U)	/* DMA Channel 68 Service Request */
#define SRC_DMACH69	(*( SRC_CPU0SBSRC_type *) 0xF0038614U)	/* DMA Channel 69 Service Request */
#define SRC_DMACH70	(*( SRC_CPU0SBSRC_type *) 0xF0038618U)	/* DMA Channel 70 Service Request */
#define SRC_DMACH71	(*( SRC_CPU0SBSRC_type *) 0xF003861CU)	/* DMA Channel 71 Service Request */
#define SRC_DMACH72	(*( SRC_CPU0SBSRC_type *) 0xF0038620U)	/* DMA Channel 72 Service Request */
#define SRC_DMACH73	(*( SRC_CPU0SBSRC_type *) 0xF0038624U)	/* DMA Channel 73 Service Request */
#define SRC_DMACH74	(*( SRC_CPU0SBSRC_type *) 0xF0038628U)	/* DMA Channel 74 Service Request */
#define SRC_DMACH75	(*( SRC_CPU0SBSRC_type *) 0xF003862CU)	/* DMA Channel 75 Service Request */
#define SRC_DMACH76	(*( SRC_CPU0SBSRC_type *) 0xF0038630U)	/* DMA Channel 76 Service Request */
#define SRC_DMACH77	(*( SRC_CPU0SBSRC_type *) 0xF0038634U)	/* DMA Channel 77 Service Request */
#define SRC_DMACH78	(*( SRC_CPU0SBSRC_type *) 0xF0038638U)	/* DMA Channel 78 Service Request */
#define SRC_DMACH79	(*( SRC_CPU0SBSRC_type *) 0xF003863CU)	/* DMA Channel 79 Service Request */
#define SRC_DMACH80	(*( SRC_CPU0SBSRC_type *) 0xF0038640U)	/* DMA Channel 80 Service Request */
#define SRC_DMACH81	(*( SRC_CPU0SBSRC_type *) 0xF0038644U)	/* DMA Channel 81 Service Request */
#define SRC_DMACH82	(*( SRC_CPU0SBSRC_type *) 0xF0038648U)	/* DMA Channel 82 Service Request */
#define SRC_DMACH83	(*( SRC_CPU0SBSRC_type *) 0xF003864CU)	/* DMA Channel 83 Service Request */
#define SRC_DMACH84	(*( SRC_CPU0SBSRC_type *) 0xF0038650U)	/* DMA Channel 84 Service Request */
#define SRC_DMACH85	(*( SRC_CPU0SBSRC_type *) 0xF0038654U)	/* DMA Channel 85 Service Request */
#define SRC_DMACH86	(*( SRC_CPU0SBSRC_type *) 0xF0038658U)	/* DMA Channel 86 Service Request */
#define SRC_DMACH87	(*( SRC_CPU0SBSRC_type *) 0xF003865CU)	/* DMA Channel 87 Service Request */
#define SRC_DMACH88	(*( SRC_CPU0SBSRC_type *) 0xF0038660U)	/* DMA Channel 88 Service Request */
#define SRC_DMACH89	(*( SRC_CPU0SBSRC_type *) 0xF0038664U)	/* DMA Channel 89 Service Request */
#define SRC_DMACH90	(*( SRC_CPU0SBSRC_type *) 0xF0038668U)	/* DMA Channel 90 Service Request */
#define SRC_DMACH91	(*( SRC_CPU0SBSRC_type *) 0xF003866CU)	/* DMA Channel 91 Service Request */
#define SRC_DMACH92	(*( SRC_CPU0SBSRC_type *) 0xF0038670U)	/* DMA Channel 92 Service Request */
#define SRC_DMACH93	(*( SRC_CPU0SBSRC_type *) 0xF0038674U)	/* DMA Channel 93 Service Request */
#define SRC_DMACH94	(*( SRC_CPU0SBSRC_type *) 0xF0038678U)	/* DMA Channel 94 Service Request */
#define SRC_DMACH95	(*( SRC_CPU0SBSRC_type *) 0xF003867CU)	/* DMA Channel 95 Service Request */
#define SRC_DMACH96	(*( SRC_CPU0SBSRC_type *) 0xF0038680U)	/* DMA Channel 96 Service Request */
#define SRC_DMACH97	(*( SRC_CPU0SBSRC_type *) 0xF0038684U)	/* DMA Channel 97 Service Request */
#define SRC_DMACH98	(*( SRC_CPU0SBSRC_type *) 0xF0038688U)	/* DMA Channel 98 Service Request */
#define SRC_DMACH99	(*( SRC_CPU0SBSRC_type *) 0xF003868CU)	/* DMA Channel 99 Service Request */
#define SRC_DMACH100	(*( SRC_CPU0SBSRC_type *) 0xF0038690U)	/* DMA Channel 100 Service Request */
#define SRC_DMACH101	(*( SRC_CPU0SBSRC_type *) 0xF0038694U)	/* DMA Channel 101 Service Request */
#define SRC_DMACH102	(*( SRC_CPU0SBSRC_type *) 0xF0038698U)	/* DMA Channel 102 Service Request */
#define SRC_DMACH103	(*( SRC_CPU0SBSRC_type *) 0xF003869CU)	/* DMA Channel 103 Service Request */
#define SRC_DMACH104	(*( SRC_CPU0SBSRC_type *) 0xF00386A0U)	/* DMA Channel 104 Service Request */
#define SRC_DMACH105	(*( SRC_CPU0SBSRC_type *) 0xF00386A4U)	/* DMA Channel 105 Service Request */
#define SRC_DMACH106	(*( SRC_CPU0SBSRC_type *) 0xF00386A8U)	/* DMA Channel 106 Service Request */
#define SRC_DMACH107	(*( SRC_CPU0SBSRC_type *) 0xF00386ACU)	/* DMA Channel 107 Service Request */
#define SRC_DMACH108	(*( SRC_CPU0SBSRC_type *) 0xF00386B0U)	/* DMA Channel 108 Service Request */
#define SRC_DMACH109	(*( SRC_CPU0SBSRC_type *) 0xF00386B4U)	/* DMA Channel 109 Service Request */
#define SRC_DMACH110	(*( SRC_CPU0SBSRC_type *) 0xF00386B8U)	/* DMA Channel 110 Service Request */
#define SRC_DMACH111	(*( SRC_CPU0SBSRC_type *) 0xF00386BCU)	/* DMA Channel 111 Service Request */
#define SRC_DMACH112	(*( SRC_CPU0SBSRC_type *) 0xF00386C0U)	/* DMA Channel 112 Service Request */
#define SRC_DMACH113	(*( SRC_CPU0SBSRC_type *) 0xF00386C4U)	/* DMA Channel 113 Service Request */
#define SRC_DMACH114	(*( SRC_CPU0SBSRC_type *) 0xF00386C8U)	/* DMA Channel 114 Service Request */
#define SRC_DMACH115	(*( SRC_CPU0SBSRC_type *) 0xF00386CCU)	/* DMA Channel 115 Service Request */
#define SRC_DMACH116	(*( SRC_CPU0SBSRC_type *) 0xF00386D0U)	/* DMA Channel 116 Service Request */
#define SRC_DMACH117	(*( SRC_CPU0SBSRC_type *) 0xF00386D4U)	/* DMA Channel 117 Service Request */
#define SRC_DMACH118	(*( SRC_CPU0SBSRC_type *) 0xF00386D8U)	/* DMA Channel 118 Service Request */
#define SRC_DMACH119	(*( SRC_CPU0SBSRC_type *) 0xF00386DCU)	/* DMA Channel 119 Service Request */
#define SRC_DMACH120	(*( SRC_CPU0SBSRC_type *) 0xF00386E0U)	/* DMA Channel 120 Service Request */
#define SRC_DMACH121	(*( SRC_CPU0SBSRC_type *) 0xF00386E4U)	/* DMA Channel 121 Service Request */
#define SRC_DMACH122	(*( SRC_CPU0SBSRC_type *) 0xF00386E8U)	/* DMA Channel 122 Service Request */
#define SRC_DMACH123	(*( SRC_CPU0SBSRC_type *) 0xF00386ECU)	/* DMA Channel 123 Service Request */
#define SRC_DMACH124	(*( SRC_CPU0SBSRC_type *) 0xF00386F0U)	/* DMA Channel 124 Service Request */
#define SRC_DMACH125	(*( SRC_CPU0SBSRC_type *) 0xF00386F4U)	/* DMA Channel 125 Service Request */
#define SRC_DMACH126	(*( SRC_CPU0SBSRC_type *) 0xF00386F8U)	/* DMA Channel 126 Service Request */
#define SRC_DMACH127	(*( SRC_CPU0SBSRC_type *) 0xF00386FCU)	/* DMA Channel 127 Service Request */
#define SRC_ETH	(*( SRC_CPU0SBSRC_type *) 0xF00388F0U)	/* Ethernet Service Request */
#define SRC_CANINT0	(*( SRC_CPU0SBSRC_type *) 0xF0038900U)	/* MULTICAN+ Service Request 0 */
#define SRC_CANINT1	(*( SRC_CPU0SBSRC_type *) 0xF0038904U)	/* MULTICAN+ Service Request 1 */
#define SRC_CANINT2	(*( SRC_CPU0SBSRC_type *) 0xF0038908U)	/* MULTICAN+ Service Request 2 */
#define SRC_CANINT3	(*( SRC_CPU0SBSRC_type *) 0xF003890CU)	/* MULTICAN+ Service Request 3 */
#define SRC_CANINT4	(*( SRC_CPU0SBSRC_type *) 0xF0038910U)	/* MULTICAN+ Service Request 4 */
#define SRC_CANINT5	(*( SRC_CPU0SBSRC_type *) 0xF0038914U)	/* MULTICAN+ Service Request 5 */
#define SRC_CANINT6	(*( SRC_CPU0SBSRC_type *) 0xF0038918U)	/* MULTICAN+ Service Request 6 */
#define SRC_CANINT7	(*( SRC_CPU0SBSRC_type *) 0xF003891CU)	/* MULTICAN+ Service Request 7 */
#define SRC_CANINT8	(*( SRC_CPU0SBSRC_type *) 0xF0038920U)	/* MULTICAN+ Service Request 8 */
#define SRC_CANINT9	(*( SRC_CPU0SBSRC_type *) 0xF0038924U)	/* MULTICAN+ Service Request 9 */
#define SRC_CANINT10	(*( SRC_CPU0SBSRC_type *) 0xF0038928U)	/* MULTICAN+ Service Request 10 */
#define SRC_CANINT11	(*( SRC_CPU0SBSRC_type *) 0xF003892CU)	/* MULTICAN+ Service Request 11 */
#define SRC_CANINT12	(*( SRC_CPU0SBSRC_type *) 0xF0038930U)	/* MULTICAN+ Service Request 12 */
#define SRC_CANINT13	(*( SRC_CPU0SBSRC_type *) 0xF0038934U)	/* MULTICAN+ Service Request 13 */
#define SRC_CANINT14	(*( SRC_CPU0SBSRC_type *) 0xF0038938U)	/* MULTICAN+ Service Request 14 */
#define SRC_CANINT15	(*( SRC_CPU0SBSRC_type *) 0xF003893CU)	/* MULTICAN+ Service Request 15 */
#define SRC_CANRINT0	(*( SRC_CPU0SBSRC_type *) 0xF0038940U)	/* MULTICANr+ Service Request 0 */
#define SRC_CANRINT1	(*( SRC_CPU0SBSRC_type *) 0xF0038944U)	/* MULTICANr+ Service Request 1 */
#define SRC_CANRINT2	(*( SRC_CPU0SBSRC_type *) 0xF0038948U)	/* MULTICANr+ Service Request 2 */
#define SRC_CANRINT3	(*( SRC_CPU0SBSRC_type *) 0xF003894CU)	/* MULTICANr+ Service Request 3 */
#define SRC_CANRINT4	(*( SRC_CPU0SBSRC_type *) 0xF0038950U)	/* MULTICANr+ Service Request 4 */
#define SRC_CANRINT5	(*( SRC_CPU0SBSRC_type *) 0xF0038954U)	/* MULTICANr+ Service Request 5 */
#define SRC_CANRINT6	(*( SRC_CPU0SBSRC_type *) 0xF0038958U)	/* MULTICANr+ Service Request 6 */
#define SRC_CANRINT7	(*( SRC_CPU0SBSRC_type *) 0xF003895CU)	/* MULTICANr+ Service Request 7 */
#define SRC_VADCG0SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038980U)	/* VADC Group 0 Service Request 0 */
#define SRC_VADCG0SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038984U)	/* VADC Group 0 Service Request 1 */
#define SRC_VADCG0SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038988U)	/* VADC Group 0 Service Request 2 */
#define SRC_VADCG0SR3	(*( SRC_CPU0SBSRC_type *) 0xF003898CU)	/* VADC Group 0 Service Request 3 */
#define SRC_VADCG1SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038990U)	/* VADC Group 1 Service Request 0 */
#define SRC_VADCG1SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038994U)	/* VADC Group 1 Service Request 1 */
#define SRC_VADCG1SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038998U)	/* VADC Group 1 Service Request 2 */
#define SRC_VADCG1SR3	(*( SRC_CPU0SBSRC_type *) 0xF003899CU)	/* VADC Group 1 Service Request 3 */
#define SRC_VADCG2SR0	(*( SRC_CPU0SBSRC_type *) 0xF00389A0U)	/* VADC Group 2 Service Request 0 */
#define SRC_VADCG2SR1	(*( SRC_CPU0SBSRC_type *) 0xF00389A4U)	/* VADC Group 2 Service Request 1 */
#define SRC_VADCG2SR2	(*( SRC_CPU0SBSRC_type *) 0xF00389A8U)	/* VADC Group 2 Service Request 2 */
#define SRC_VADCG2SR3	(*( SRC_CPU0SBSRC_type *) 0xF00389ACU)	/* VADC Group 2 Service Request 3 */
#define SRC_VADCG3SR0	(*( SRC_CPU0SBSRC_type *) 0xF00389B0U)	/* VADC Group 3 Service Request 0 */
#define SRC_VADCG3SR1	(*( SRC_CPU0SBSRC_type *) 0xF00389B4U)	/* VADC Group 3 Service Request 1 */
#define SRC_VADCG3SR2	(*( SRC_CPU0SBSRC_type *) 0xF00389B8U)	/* VADC Group 3 Service Request 2 */
#define SRC_VADCG3SR3	(*( SRC_CPU0SBSRC_type *) 0xF00389BCU)	/* VADC Group 3 Service Request 3 */
#define SRC_VADCG4SR0	(*( SRC_CPU0SBSRC_type *) 0xF00389C0U)	/* VADC Group 4 Service Request 0 */
#define SRC_VADCG4SR1	(*( SRC_CPU0SBSRC_type *) 0xF00389C4U)	/* VADC Group 4 Service Request 1 */
#define SRC_VADCG4SR2	(*( SRC_CPU0SBSRC_type *) 0xF00389C8U)	/* VADC Group 4 Service Request 2 */
#define SRC_VADCG4SR3	(*( SRC_CPU0SBSRC_type *) 0xF00389CCU)	/* VADC Group 4 Service Request 3 */
#define SRC_VADCG5SR0	(*( SRC_CPU0SBSRC_type *) 0xF00389D0U)	/* VADC Group 5 Service Request 0 */
#define SRC_VADCG5SR1	(*( SRC_CPU0SBSRC_type *) 0xF00389D4U)	/* VADC Group 5 Service Request 1 */
#define SRC_VADCG5SR2	(*( SRC_CPU0SBSRC_type *) 0xF00389D8U)	/* VADC Group 5 Service Request 2 */
#define SRC_VADCG5SR3	(*( SRC_CPU0SBSRC_type *) 0xF00389DCU)	/* VADC Group 5 Service Request 3 */
#define SRC_VADCG6SR0	(*( SRC_CPU0SBSRC_type *) 0xF00389E0U)	/* VADC Group 6 Service Request 0 */
#define SRC_VADCG6SR1	(*( SRC_CPU0SBSRC_type *) 0xF00389E4U)	/* VADC Group 6 Service Request 1 */
#define SRC_VADCG6SR2	(*( SRC_CPU0SBSRC_type *) 0xF00389E8U)	/* VADC Group 6 Service Request 2 */
#define SRC_VADCG6SR3	(*( SRC_CPU0SBSRC_type *) 0xF00389ECU)	/* VADC Group 6 Service Request 3 */
#define SRC_VADCG7SR0	(*( SRC_CPU0SBSRC_type *) 0xF00389F0U)	/* VADC Group 7 Service Request 0 */
#define SRC_VADCG7SR1	(*( SRC_CPU0SBSRC_type *) 0xF00389F4U)	/* VADC Group 7 Service Request 1 */
#define SRC_VADCG7SR2	(*( SRC_CPU0SBSRC_type *) 0xF00389F8U)	/* VADC Group 7 Service Request 2 */
#define SRC_VADCG7SR3	(*( SRC_CPU0SBSRC_type *) 0xF00389FCU)	/* VADC Group 7 Service Request 3 */
#define SRC_VADCG8SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038A00U)	/* VADC Group 8 Service Request 0 */
#define SRC_VADCG8SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038A04U)	/* VADC Group 8 Service Request 1 */
#define SRC_VADCG8SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038A08U)	/* VADC Group 8 Service Request 2 */
#define SRC_VADCG8SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038A0CU)	/* VADC Group 8 Service Request 3 */
#define SRC_VADCG9SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038A10U)	/* VADC Group 9 Service Request 0 */
#define SRC_VADCG9SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038A14U)	/* VADC Group 9 Service Request 1 */
#define SRC_VADCG9SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038A18U)	/* VADC Group 9 Service Request 2 */
#define SRC_VADCG9SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038A1CU)	/* VADC Group 9 Service Request 3 */
#define SRC_VADCG10SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038A20U)	/* VADC Group 10 Service Request 0 */
#define SRC_VADCG10SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038A24U)	/* VADC Group 10 Service Request 1 */
#define SRC_VADCG10SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038A28U)	/* VADC Group 10 Service Request 2 */
#define SRC_VADCG10SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038A2CU)	/* VADC Group 10 Service Request 3 */
#define SRC_VADCCG0SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038AA0U)	/* VADC Common Group 0 Service Request 0 */
#define SRC_VADCCG0SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038AA4U)	/* VADC Common Group 0 Service Request 1 */
#define SRC_VADCCG0SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038AA8U)	/* VADC Common Group 0 Service Request 2 */
#define SRC_VADCCG0SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038AACU)	/* VADC Common Group 0 Service Request 3 */
#define SRC_VADCCG1SR0	(*( SRC_CPU0SBSRC_type *) 0xF0038AB0U)	/* VADC Common Group 1 Service Request 0 */
#define SRC_VADCCG1SR1	(*( SRC_CPU0SBSRC_type *) 0xF0038AB4U)	/* VADC Common Group 1 Service Request 1 */
#define SRC_VADCCG1SR2	(*( SRC_CPU0SBSRC_type *) 0xF0038AB8U)	/* VADC Common Group 1 Service Request 2 */
#define SRC_VADCCG1SR3	(*( SRC_CPU0SBSRC_type *) 0xF0038ABCU)	/* VADC Common Group 1 Service Request 3 */
#define SRC_DSADCSRM0	(*( SRC_CPU0SBSRC_type *) 0xF0038B50U)	/* DSADC SRM0 Service Request */
#define SRC_DSADCSRM1	(*( SRC_CPU0SBSRC_type *) 0xF0038B58U)	/* DSADC SRM1 Service Request */
#define SRC_DSADCSRM2	(*( SRC_CPU0SBSRC_type *) 0xF0038B60U)	/* DSADC SRM2 Service Request */
#define SRC_DSADCSRM3	(*( SRC_CPU0SBSRC_type *) 0xF0038B68U)	/* DSADC SRM3 Service Request */
#define SRC_DSADCSRM4	(*( SRC_CPU0SBSRC_type *) 0xF0038B70U)	/* DSADC SRM4 Service Request */
#define SRC_DSADCSRM5	(*( SRC_CPU0SBSRC_type *) 0xF0038B78U)	/* DSADC SRM5 Service Request */
#define SRC_DSADCSRM6	(*( SRC_CPU0SBSRC_type *) 0xF0038B80U)	/* DSADC SRM6 Service Request */
#define SRC_DSADCSRM7	(*( SRC_CPU0SBSRC_type *) 0xF0038B88U)	/* DSADC SRM7 Service Request */
#define SRC_DSADCSRM8	(*( SRC_CPU0SBSRC_type *) 0xF0038B90U)	/* DSADC SRM8 Service Request */
#define SRC_DSADCSRM9	(*( SRC_CPU0SBSRC_type *) 0xF0038B98U)	/* DSADC SRM9 Service Request */
#define SRC_DSADCSRA0	(*( SRC_CPU0SBSRC_type *) 0xF0038B54U)	/* DSADC SRA0 Service Request */
#define SRC_DSADCSRA1	(*( SRC_CPU0SBSRC_type *) 0xF0038B5CU)	/* DSADC SRA1 Service Request */
#define SRC_DSADCSRA2	(*( SRC_CPU0SBSRC_type *) 0xF0038B64U)	/* DSADC SRA2 Service Request */
#define SRC_DSADCSRA3	(*( SRC_CPU0SBSRC_type *) 0xF0038B6CU)	/* DSADC SRA3 Service Request */
#define SRC_DSADCSRA4	(*( SRC_CPU0SBSRC_type *) 0xF0038B74U)	/* DSADC SRA4 Service Request */
#define SRC_DSADCSRA5	(*( SRC_CPU0SBSRC_type *) 0xF0038B7CU)	/* DSADC SRA5 Service Request */
#define SRC_DSADCSRA6	(*( SRC_CPU0SBSRC_type *) 0xF0038B84U)	/* DSADC SRA6 Service Request */
#define SRC_DSADCSRA7	(*( SRC_CPU0SBSRC_type *) 0xF0038B8CU)	/* DSADC SRA7 Service Request */
#define SRC_DSADCSRA8	(*( SRC_CPU0SBSRC_type *) 0xF0038B94U)	/* DSADC SRA8 Service Request */
#define SRC_DSADCSRA9	(*( SRC_CPU0SBSRC_type *) 0xF0038B9CU)	/* DSADC SRA9 Service Request */
#define SRC_ERAY0INT0	(*( SRC_CPU0SBSRC_type *) 0xF0038BE0U)	/* E-RAY 0 Service Request 0 */
#define SRC_ERAY0INT1	(*( SRC_CPU0SBSRC_type *) 0xF0038BE4U)	/* E-RAY 0 Service Request 1 */
#define SRC_ERAY0TINT0	(*( SRC_CPU0SBSRC_type *) 0xF0038BE8U)	/* E-RAY 0 Timer Interrupt 0 Service Request */
#define SRC_ERAY0TINT1	(*( SRC_CPU0SBSRC_type *) 0xF0038BECU)	/* E-RAY 0 Timer Interrupt 1 Service Request */
#define SRC_ERAY0NDAT0	(*( SRC_CPU0SBSRC_type *) 0xF0038BF0U)	/* E-RAY 0 New Data 0 Service Request */
#define SRC_ERAY0NDAT1	(*( SRC_CPU0SBSRC_type *) 0xF0038BF4U)	/* E-RAY 0 New Data 1 Service Request */
#define SRC_ERAY0MBSC0	(*( SRC_CPU0SBSRC_type *) 0xF0038BF8U)	/* E-RAY 0 Message Buffer Status Changed 0 Service Request */
#define SRC_ERAY0MBSC1	(*( SRC_CPU0SBSRC_type *) 0xF0038BFCU)	/* E-RAY 0 Message Buffer Status Changed 1 Service Request */
#define SRC_ERAY0OBUSY	(*( SRC_CPU0SBSRC_type *) 0xF0038C00U)	/* E-RAY 0 Output Buffer Busy Service Request */
#define SRC_ERAY0IBUSY	(*( SRC_CPU0SBSRC_type *) 0xF0038C04U)	/* E-RAY 0 Input Buffer Busy Service Request */
#define SRC_ERAY1INT0	(*( SRC_CPU0SBSRC_type *) 0xF0038C08U)	/* E-RAY 1 Service Request 0 */
#define SRC_ERAY1INT1	(*( SRC_CPU0SBSRC_type *) 0xF0038C0CU)	/* E-RAY 1 Service Request 1 */
#define SRC_ERAY1TINT0	(*( SRC_CPU0SBSRC_type *) 0xF0038C10U)	/* E-RAY 1 Timer Interrupt 0 Service Request */
#define SRC_ERAY1TINT1	(*( SRC_CPU0SBSRC_type *) 0xF0038C14U)	/* E-RAY 1 Timer Interrupt 1 Service Request */
#define SRC_ERAY1NDAT0	(*( SRC_CPU0SBSRC_type *) 0xF0038C18U)	/* E-RAY 1 New Data 0 Service Request */
#define SRC_ERAY1NDAT1	(*( SRC_CPU0SBSRC_type *) 0xF0038C1CU)	/* E-RAY 1 New Data 1 Service Request */
#define SRC_ERAY1MBSC0	(*( SRC_CPU0SBSRC_type *) 0xF0038C20U)	/* E-RAY 1 Message Buffer Status Changed 0 Service Request */
#define SRC_ERAY1MBSC1	(*( SRC_CPU0SBSRC_type *) 0xF0038C24U)	/* E-RAY 1 Message Buffer Status Changed 1 Service Request */
#define SRC_ERAY1OBUSY	(*( SRC_CPU0SBSRC_type *) 0xF0038C28U)	/* E-RAY 1 Output Buffer Busy Service Request */
#define SRC_ERAY1IBUSY	(*( SRC_CPU0SBSRC_type *) 0xF0038C2CU)	/* E-RAY 1 Input Buffer Busy Service Request */
#define SRC_PMU00	(*( SRC_CPU0SBSRC_type *) 0xF0038C30U)	/* PMU 0 Service Request 0 */
#define SRC_PMU01	(*( SRC_CPU0SBSRC_type *) 0xF0038C34U)	/* PMU 0 Service Request 1 */
#define SRC_HSM0	(*( SRC_CPU0SBSRC_type *) 0xF0038CC0U)	/* HSM Service Request 0 */
#define SRC_HSM1	(*( SRC_CPU0SBSRC_type *) 0xF0038CC4U)	/* HSM Service Request 1 */
#define SRC_SCUDTS	(*( SRC_CPU0SBSRC_type *) 0xF0038CD0U)	/* SCU DTS Busy Service Request */
#define SRC_SCUERU0	(*( SRC_CPU0SBSRC_type *) 0xF0038CD4U)	/* SCU ERU Service Request 0 */
#define SRC_SCUERU1	(*( SRC_CPU0SBSRC_type *) 0xF0038CD8U)	/* SCU ERU Service Request 1 */
#define SRC_SCUERU2	(*( SRC_CPU0SBSRC_type *) 0xF0038CDCU)	/* SCU ERU Service Request 2 */
#define SRC_SCUERU3	(*( SRC_CPU0SBSRC_type *) 0xF0038CE0U)	/* SCU ERU Service Request 3 */
#define SRC_SMU0	(*( SRC_CPU0SBSRC_type *) 0xF0038D10U)	/* SMU Service Request 0 */
#define SRC_SMU1	(*( SRC_CPU0SBSRC_type *) 0xF0038D14U)	/* SMU Service Request 1 */
#define SRC_SMU2	(*( SRC_CPU0SBSRC_type *) 0xF0038D18U)	/* SMU Service Request 2 */
#define SRC_PSI50	(*( SRC_CPU0SBSRC_type *) 0xF0038D30U)	/* PSI5 Service Request 0 */
#define SRC_PSI51	(*( SRC_CPU0SBSRC_type *) 0xF0038D34U)	/* PSI5 Service Request 1 */
#define SRC_PSI52	(*( SRC_CPU0SBSRC_type *) 0xF0038D38U)	/* PSI5 Service Request 2 */
#define SRC_PSI53	(*( SRC_CPU0SBSRC_type *) 0xF0038D3CU)	/* PSI5 Service Request 3 */
#define SRC_PSI54	(*( SRC_CPU0SBSRC_type *) 0xF0038D40U)	/* PSI5 Service Request 4 */
#define SRC_PSI55	(*( SRC_CPU0SBSRC_type *) 0xF0038D44U)	/* PSI5 Service Request 5 */
#define SRC_PSI56	(*( SRC_CPU0SBSRC_type *) 0xF0038D48U)	/* PSI5 Service Request 6 */
#define SRC_PSI57	(*( SRC_CPU0SBSRC_type *) 0xF0038D4CU)	/* PSI5 Service Request 7 */
#define SRC_DAM0	(*( SRC_CPU0SBSRC_type *) 0xF0038D70U)	/* DAM Service Request 0 */
#define SRC_DAM1	(*( SRC_CPU0SBSRC_type *) 0xF0038D74U)	/* DAM Service Request 1 */
#define SRC_DAM2	(*( SRC_CPU0SBSRC_type *) 0xF0038D78U)	/* DAM Service Request 2 */
#define SRC_DAM3	(*( SRC_CPU0SBSRC_type *) 0xF0038D7CU)	/* DAM Service Request 3 */
#define SRC_DAM4	(*( SRC_CPU0SBSRC_type *) 0xF0038D80U)	/* DAM Service Request 4 */
#define SRC_DAM5	(*( SRC_CPU0SBSRC_type *) 0xF0038D84U)	/* DAM Service Request 5 */
#define SRC_CIFMI	(*( SRC_CPU0SBSRC_type *) 0xF0038DA0U)	/* CIF MI Service Request */
#define SRC_CIFMIEP	(*( SRC_CPU0SBSRC_type *) 0xF0038DA4U)	/* CIF MI EP Service Request */
#define SRC_CIFISP	(*( SRC_CPU0SBSRC_type *) 0xF0038DA8U)	/* CIF ISP Service Request */
#define SRC_CIFMJPEG	(*( SRC_CPU0SBSRC_type *) 0xF0038DACU)	/* CIF MJPEG Service Request */
#define SRC_LMU	(*( SRC_CPU0SBSRC_type *) 0xF0038DE0U)	/* LMU Service Request */
#define SRC_PSI5S0	(*( SRC_CPU0SBSRC_type *) 0xF0038DF0U)	/* PSI5-S Service Request 0 */
#define SRC_PSI5S1	(*( SRC_CPU0SBSRC_type *) 0xF0038DF4U)	/* PSI5-S Service Request 1 */
#define SRC_PSI5S2	(*( SRC_CPU0SBSRC_type *) 0xF0038DF8U)	/* PSI5-S Service Request 2 */
#define SRC_PSI5S3	(*( SRC_CPU0SBSRC_type *) 0xF0038DFCU)	/* PSI5-S Service Request 3 */
#define SRC_PSI5S4	(*( SRC_CPU0SBSRC_type *) 0xF0038E00U)	/* PSI5-S Service Request 4 */
#define SRC_PSI5S5	(*( SRC_CPU0SBSRC_type *) 0xF0038E04U)	/* PSI5-S Service Request 5 */
#define SRC_PSI5S6	(*( SRC_CPU0SBSRC_type *) 0xF0038E08U)	/* PSI5-S Service Request 6 */
#define SRC_PSI5S7	(*( SRC_CPU0SBSRC_type *) 0xF0038E0CU)	/* PSI5-S Service Request 7 */
#define SRC_FFTDONE	(*( SRC_CPU0SBSRC_type *) 0xF0038FC0U)	/* FFT Done Service Request */
#define SRC_FFTERR	(*( SRC_CPU0SBSRC_type *) 0xF0038FC4U)	/* FFT Error Service Request */
#define SRC_FFTRFS	(*( SRC_CPU0SBSRC_type *) 0xF0038FC8U)	/* FFT Ready For Start Service Request */
#define SRC_RESERVED0	(*( SRC_CPU0SBSRC_type *) 0xF0038FCCU)	/* Reserved Service Request 0 */
#define SRC_GPSR00	(*( SRC_CPU0SBSRC_type *) 0xF0039000U)	/* General Purpose Service Request 00 */
#define SRC_GPSR01	(*( SRC_CPU0SBSRC_type *) 0xF0039004U)	/* General Purpose Service Request 01 */
#define SRC_GPSR02	(*( SRC_CPU0SBSRC_type *) 0xF0039008U)	/* General Purpose Service Request 02 */
#define SRC_GPSR03	(*( SRC_CPU0SBSRC_type *) 0xF003900CU)	/* General Purpose Service Request 03 */
#define SRC_GPSR10	(*( SRC_CPU0SBSRC_type *) 0xF0039020U)	/* General Purpose Service Request 10 */
#define SRC_GPSR11	(*( SRC_CPU0SBSRC_type *) 0xF0039024U)	/* General Purpose Service Request 11 */
#define SRC_GPSR12	(*( SRC_CPU0SBSRC_type *) 0xF0039028U)	/* General Purpose Service Request 12 */
#define SRC_GPSR13	(*( SRC_CPU0SBSRC_type *) 0xF003902CU)	/* General Purpose Service Request 13 */
#define SRC_GPSR20	(*( SRC_CPU0SBSRC_type *) 0xF0039040U)	/* General Purpose Service Request 20 */
#define SRC_GPSR21	(*( SRC_CPU0SBSRC_type *) 0xF0039044U)	/* General Purpose Service Request 21 */
#define SRC_GPSR22	(*( SRC_CPU0SBSRC_type *) 0xF0039048U)	/* General Purpose Service Request 22 */
#define SRC_GPSR23	(*( SRC_CPU0SBSRC_type *) 0xF003904CU)	/* General Purpose Service Request 23 */
#define SRC_GTMAEIIRQ	(*( SRC_CPU0SBSRC_type *) 0xF0039600U)	/* GTM AEI Shared Service Request */
#define SRC_GTMARUIRQ0	(*( SRC_CPU0SBSRC_type *) 0xF0039604U)	/* GTM ARU Shared Service Request 0 */
#define SRC_GTMARUIRQ1	(*( SRC_CPU0SBSRC_type *) 0xF0039608U)	/* GTM ARU Shared Service Request 1 */
#define SRC_GTMARUIRQ2	(*( SRC_CPU0SBSRC_type *) 0xF003960CU)	/* GTM ARU Shared Service Request 2 */
#define SRC_GTMBRCIRQ	(*( SRC_CPU0SBSRC_type *) 0xF0039614U)	/* GTM BRC Shared Service Request */
#define SRC_GTMCMPIRQ	(*( SRC_CPU0SBSRC_type *) 0xF0039618U)	/* GTM CMP Shared Service Request */
#define SRC_GTMSPE0IRQ	(*( SRC_CPU0SBSRC_type *) 0xF003961CU)	/* GTM SPE0 Shared Service Request */
#define SRC_GTMSPE1IRQ	(*( SRC_CPU0SBSRC_type *) 0xF0039620U)	/* GTM SPE1 Shared Service Request */
#define SRC_GTMSPE2IRQ	(*( SRC_CPU0SBSRC_type *) 0xF0039624U)	/* GTM SPE2 Shared Service Request */
#define SRC_GTMSPE3IRQ	(*( SRC_CPU0SBSRC_type *) 0xF0039628U)	/* GTM SPE3 Shared Service Request */
#define SRC_GTMPSM00	(*( SRC_CPU0SBSRC_type *) 0xF003962CU)	/* GTM PSM0 Shared Service Request 0 */
#define SRC_GTMPSM01	(*( SRC_CPU0SBSRC_type *) 0xF0039630U)	/* GTM PSM0 Shared Service Request 1 */
#define SRC_GTMPSM02	(*( SRC_CPU0SBSRC_type *) 0xF0039634U)	/* GTM PSM0 Shared Service Request 2 */
#define SRC_GTMPSM03	(*( SRC_CPU0SBSRC_type *) 0xF0039638U)	/* GTM PSM0 Shared Service Request 3 */
#define SRC_GTMPSM04	(*( SRC_CPU0SBSRC_type *) 0xF003963CU)	/* GTM PSM0 Shared Service Request 4 */
#define SRC_GTMPSM05	(*( SRC_CPU0SBSRC_type *) 0xF0039640U)	/* GTM PSM0 Shared Service Request 5 */
#define SRC_GTMPSM06	(*( SRC_CPU0SBSRC_type *) 0xF0039644U)	/* GTM PSM0 Shared Service Request 6 */
#define SRC_GTMPSM07	(*( SRC_CPU0SBSRC_type *) 0xF0039648U)	/* GTM PSM0 Shared Service Request 7 */
#define SRC_GTMPSM10	(*( SRC_CPU0SBSRC_type *) 0xF003964CU)	/* GTM PSM1 Shared Service Request 0 */
#define SRC_GTMPSM11	(*( SRC_CPU0SBSRC_type *) 0xF0039650U)	/* GTM PSM1 Shared Service Request 1 */
#define SRC_GTMPSM12	(*( SRC_CPU0SBSRC_type *) 0xF0039654U)	/* GTM PSM1 Shared Service Request 2 */
#define SRC_GTMPSM13	(*( SRC_CPU0SBSRC_type *) 0xF0039658U)	/* GTM PSM1 Shared Service Request 3 */
#define SRC_GTMPSM14	(*( SRC_CPU0SBSRC_type *) 0xF003965CU)	/* GTM PSM1 Shared Service Request 4 */
#define SRC_GTMPSM15	(*( SRC_CPU0SBSRC_type *) 0xF0039660U)	/* GTM PSM1 Shared Service Request 5 */
#define SRC_GTMPSM16	(*( SRC_CPU0SBSRC_type *) 0xF0039664U)	/* GTM PSM1 Shared Service Request 6 */
#define SRC_GTMPSM17	(*( SRC_CPU0SBSRC_type *) 0xF0039668U)	/* GTM PSM1 Shared Service Request 7 */
#define SRC_GTMDPLL0	(*( SRC_CPU0SBSRC_type *) 0xF00396A4U)	/* GTM DPLL Service Request 0 */
#define SRC_GTMDPLL1	(*( SRC_CPU0SBSRC_type *) 0xF00396A8U)	/* GTM DPLL Service Request 1 */
#define SRC_GTMDPLL2	(*( SRC_CPU0SBSRC_type *) 0xF00396ACU)	/* GTM DPLL Service Request 2 */
#define SRC_GTMDPLL3	(*( SRC_CPU0SBSRC_type *) 0xF00396B0U)	/* GTM DPLL Service Request 3 */
#define SRC_GTMDPLL4	(*( SRC_CPU0SBSRC_type *) 0xF00396B4U)	/* GTM DPLL Service Request 4 */
#define SRC_GTMDPLL5	(*( SRC_CPU0SBSRC_type *) 0xF00396B8U)	/* GTM DPLL Service Request 5 */
#define SRC_GTMDPLL6	(*( SRC_CPU0SBSRC_type *) 0xF00396BCU)	/* GTM DPLL Service Request 6 */
#define SRC_GTMDPLL7	(*( SRC_CPU0SBSRC_type *) 0xF00396C0U)	/* GTM DPLL Service Request 7 */
#define SRC_GTMDPLL8	(*( SRC_CPU0SBSRC_type *) 0xF00396C4U)	/* GTM DPLL Service Request 8 */
#define SRC_GTMDPLL9	(*( SRC_CPU0SBSRC_type *) 0xF00396C8U)	/* GTM DPLL Service Request 9 */
#define SRC_GTMDPLL10	(*( SRC_CPU0SBSRC_type *) 0xF00396CCU)	/* GTM DPLL Service Request 10 */
#define SRC_GTMDPLL11	(*( SRC_CPU0SBSRC_type *) 0xF00396D0U)	/* GTM DPLL Service Request 11 */
#define SRC_GTMDPLL12	(*( SRC_CPU0SBSRC_type *) 0xF00396D4U)	/* GTM DPLL Service Request 12 */
#define SRC_GTMDPLL13	(*( SRC_CPU0SBSRC_type *) 0xF00396D8U)	/* GTM DPLL Service Request 13 */
#define SRC_GTMDPLL14	(*( SRC_CPU0SBSRC_type *) 0xF00396DCU)	/* GTM DPLL Service Request 14 */
#define SRC_GTMDPLL15	(*( SRC_CPU0SBSRC_type *) 0xF00396E0U)	/* GTM DPLL Service Request 15 */
#define SRC_GTMDPLL16	(*( SRC_CPU0SBSRC_type *) 0xF00396E4U)	/* GTM DPLL Service Request 16 */
#define SRC_GTMDPLL17	(*( SRC_CPU0SBSRC_type *) 0xF00396E8U)	/* GTM DPLL Service Request 17 */
#define SRC_GTMDPLL18	(*( SRC_CPU0SBSRC_type *) 0xF00396ECU)	/* GTM DPLL Service Request 18 */
#define SRC_GTMDPLL19	(*( SRC_CPU0SBSRC_type *) 0xF00396F0U)	/* GTM DPLL Service Request 19 */
#define SRC_GTMDPLL20	(*( SRC_CPU0SBSRC_type *) 0xF00396F4U)	/* GTM DPLL Service Request 20 */
#define SRC_GTMDPLL21	(*( SRC_CPU0SBSRC_type *) 0xF00396F8U)	/* GTM DPLL Service Request 21 */
#define SRC_GTMDPLL22	(*( SRC_CPU0SBSRC_type *) 0xF00396FCU)	/* GTM DPLL Service Request 22 */
#define SRC_GTMDPLL23	(*( SRC_CPU0SBSRC_type *) 0xF0039700U)	/* GTM DPLL Service Request 23 */
#define SRC_GTMDPLL24	(*( SRC_CPU0SBSRC_type *) 0xF0039704U)	/* GTM DPLL Service Request 24 */
#define SRC_GTMDPLL25	(*( SRC_CPU0SBSRC_type *) 0xF0039708U)	/* GTM DPLL Service Request 25 */
#define SRC_GTMDPLL26	(*( SRC_CPU0SBSRC_type *) 0xF003970CU)	/* GTM DPLL Service Request 26 */
#define SRC_GTMERR	(*( SRC_CPU0SBSRC_type *) 0xF0039770U)	/* GTM Error Service Request */
#define SRC_GTMTIM00	(*( SRC_CPU0SBSRC_type *) 0xF0039780U)	/* GTM TIM0 Shared Service Request 0 */
#define SRC_GTMTIM01	(*( SRC_CPU0SBSRC_type *) 0xF0039784U)	/* GTM TIM0 Shared Service Request 1 */
#define SRC_GTMTIM02	(*( SRC_CPU0SBSRC_type *) 0xF0039788U)	/* GTM TIM0 Shared Service Request 2 */
#define SRC_GTMTIM03	(*( SRC_CPU0SBSRC_type *) 0xF003978CU)	/* GTM TIM0 Shared Service Request 3 */
#define SRC_GTMTIM04	(*( SRC_CPU0SBSRC_type *) 0xF0039790U)	/* GTM TIM0 Shared Service Request 4 */
#define SRC_GTMTIM05	(*( SRC_CPU0SBSRC_type *) 0xF0039794U)	/* GTM TIM0 Shared Service Request 5 */
#define SRC_GTMTIM06	(*( SRC_CPU0SBSRC_type *) 0xF0039798U)	/* GTM TIM0 Shared Service Request 6 */
#define SRC_GTMTIM07	(*( SRC_CPU0SBSRC_type *) 0xF003979CU)	/* GTM TIM0 Shared Service Request 7 */
#define SRC_GTMTIM10	(*( SRC_CPU0SBSRC_type *) 0xF00397A0U)	/* GTM TIM1 Shared Service Request 0 */
#define SRC_GTMTIM11	(*( SRC_CPU0SBSRC_type *) 0xF00397A4U)	/* GTM TIM1 Shared Service Request 1 */
#define SRC_GTMTIM12	(*( SRC_CPU0SBSRC_type *) 0xF00397A8U)	/* GTM TIM1 Shared Service Request 2 */
#define SRC_GTMTIM13	(*( SRC_CPU0SBSRC_type *) 0xF00397ACU)	/* GTM TIM1 Shared Service Request 3 */
#define SRC_GTMTIM14	(*( SRC_CPU0SBSRC_type *) 0xF00397B0U)	/* GTM TIM1 Shared Service Request 4 */
#define SRC_GTMTIM15	(*( SRC_CPU0SBSRC_type *) 0xF00397B4U)	/* GTM TIM1 Shared Service Request 5 */
#define SRC_GTMTIM16	(*( SRC_CPU0SBSRC_type *) 0xF00397B8U)	/* GTM TIM1 Shared Service Request 6 */
#define SRC_GTMTIM17	(*( SRC_CPU0SBSRC_type *) 0xF00397BCU)	/* GTM TIM1 Shared Service Request 7 */
#define SRC_GTMTIM20	(*( SRC_CPU0SBSRC_type *) 0xF00397C0U)	/* GTM TIM2 Shared Service Request 0 */
#define SRC_GTMTIM21	(*( SRC_CPU0SBSRC_type *) 0xF00397C4U)	/* GTM TIM2 Shared Service Request 1 */
#define SRC_GTMTIM22	(*( SRC_CPU0SBSRC_type *) 0xF00397C8U)	/* GTM TIM2 Shared Service Request 2 */
#define SRC_GTMTIM23	(*( SRC_CPU0SBSRC_type *) 0xF00397CCU)	/* GTM TIM2 Shared Service Request 3 */
#define SRC_GTMTIM24	(*( SRC_CPU0SBSRC_type *) 0xF00397D0U)	/* GTM TIM2 Shared Service Request 4 */
#define SRC_GTMTIM25	(*( SRC_CPU0SBSRC_type *) 0xF00397D4U)	/* GTM TIM2 Shared Service Request 5 */
#define SRC_GTMTIM26	(*( SRC_CPU0SBSRC_type *) 0xF00397D8U)	/* GTM TIM2 Shared Service Request 6 */
#define SRC_GTMTIM27	(*( SRC_CPU0SBSRC_type *) 0xF00397DCU)	/* GTM TIM2 Shared Service Request 7 */
#define SRC_GTMTIM30	(*( SRC_CPU0SBSRC_type *) 0xF00397E0U)	/* GTM TIM3 Shared Service Request 0 */
#define SRC_GTMTIM31	(*( SRC_CPU0SBSRC_type *) 0xF00397E4U)	/* GTM TIM3 Shared Service Request 1 */
#define SRC_GTMTIM32	(*( SRC_CPU0SBSRC_type *) 0xF00397E8U)	/* GTM TIM3 Shared Service Request 2 */
#define SRC_GTMTIM33	(*( SRC_CPU0SBSRC_type *) 0xF00397ECU)	/* GTM TIM3 Shared Service Request 3 */
#define SRC_GTMTIM34	(*( SRC_CPU0SBSRC_type *) 0xF00397F0U)	/* GTM TIM3 Shared Service Request 4 */
#define SRC_GTMTIM35	(*( SRC_CPU0SBSRC_type *) 0xF00397F4U)	/* GTM TIM3 Shared Service Request 5 */
#define SRC_GTMTIM36	(*( SRC_CPU0SBSRC_type *) 0xF00397F8U)	/* GTM TIM3 Shared Service Request 6 */
#define SRC_GTMTIM37	(*( SRC_CPU0SBSRC_type *) 0xF00397FCU)	/* GTM TIM3 Shared Service Request 7 */
#define SRC_GTMTIM40	(*( SRC_CPU0SBSRC_type *) 0xF0039800U)	/* GTM TIM4 Shared Service Request 0 */
#define SRC_GTMTIM41	(*( SRC_CPU0SBSRC_type *) 0xF0039804U)	/* GTM TIM4 Shared Service Request 1 */
#define SRC_GTMTIM42	(*( SRC_CPU0SBSRC_type *) 0xF0039808U)	/* GTM TIM4 Shared Service Request 2 */
#define SRC_GTMTIM43	(*( SRC_CPU0SBSRC_type *) 0xF003980CU)	/* GTM TIM4 Shared Service Request 3 */
#define SRC_GTMTIM44	(*( SRC_CPU0SBSRC_type *) 0xF0039810U)	/* GTM TIM4 Shared Service Request 4 */
#define SRC_GTMTIM45	(*( SRC_CPU0SBSRC_type *) 0xF0039814U)	/* GTM TIM4 Shared Service Request 5 */
#define SRC_GTMTIM46	(*( SRC_CPU0SBSRC_type *) 0xF0039818U)	/* GTM TIM4 Shared Service Request 6 */
#define SRC_GTMTIM47	(*( SRC_CPU0SBSRC_type *) 0xF003981CU)	/* GTM TIM4 Shared Service Request 7 */
#define SRC_GTMTIM50	(*( SRC_CPU0SBSRC_type *) 0xF0039820U)	/* GTM TIM5 Shared Service Request 0 */
#define SRC_GTMTIM51	(*( SRC_CPU0SBSRC_type *) 0xF0039824U)	/* GTM TIM5 Shared Service Request 1 */
#define SRC_GTMTIM52	(*( SRC_CPU0SBSRC_type *) 0xF0039828U)	/* GTM TIM5 Shared Service Request 2 */
#define SRC_GTMTIM53	(*( SRC_CPU0SBSRC_type *) 0xF003982CU)	/* GTM TIM5 Shared Service Request 3 */
#define SRC_GTMTIM54	(*( SRC_CPU0SBSRC_type *) 0xF0039830U)	/* GTM TIM5 Shared Service Request 4 */
#define SRC_GTMTIM55	(*( SRC_CPU0SBSRC_type *) 0xF0039834U)	/* GTM TIM5 Shared Service Request 5 */
#define SRC_GTMTIM56	(*( SRC_CPU0SBSRC_type *) 0xF0039838U)	/* GTM TIM5 Shared Service Request 6 */
#define SRC_GTMTIM57	(*( SRC_CPU0SBSRC_type *) 0xF003983CU)	/* GTM TIM5 Shared Service Request 7 */
#define SRC_GTMMCS00	(*( SRC_CPU0SBSRC_type *) 0xF0039980U)	/* GTM MCS0 Shared Service Request 0 */
#define SRC_GTMMCS01	(*( SRC_CPU0SBSRC_type *) 0xF0039984U)	/* GTM MCS0 Shared Service Request 1 */
#define SRC_GTMMCS02	(*( SRC_CPU0SBSRC_type *) 0xF0039988U)	/* GTM MCS0 Shared Service Request 2 */
#define SRC_GTMMCS03	(*( SRC_CPU0SBSRC_type *) 0xF003998CU)	/* GTM MCS0 Shared Service Request 3 */
#define SRC_GTMMCS04	(*( SRC_CPU0SBSRC_type *) 0xF0039990U)	/* GTM MCS0 Shared Service Request 4 */
#define SRC_GTMMCS05	(*( SRC_CPU0SBSRC_type *) 0xF0039994U)	/* GTM MCS0 Shared Service Request 5 */
#define SRC_GTMMCS06	(*( SRC_CPU0SBSRC_type *) 0xF0039998U)	/* GTM MCS0 Shared Service Request 6 */
#define SRC_GTMMCS07	(*( SRC_CPU0SBSRC_type *) 0xF003999CU)	/* GTM MCS0 Shared Service Request 7 */
#define SRC_GTMMCS10	(*( SRC_CPU0SBSRC_type *) 0xF00399A0U)	/* GTM MCS1 Shared Service Request 0 */
#define SRC_GTMMCS11	(*( SRC_CPU0SBSRC_type *) 0xF00399A4U)	/* GTM MCS1 Shared Service Request 1 */
#define SRC_GTMMCS12	(*( SRC_CPU0SBSRC_type *) 0xF00399A8U)	/* GTM MCS1 Shared Service Request 2 */
#define SRC_GTMMCS13	(*( SRC_CPU0SBSRC_type *) 0xF00399ACU)	/* GTM MCS1 Shared Service Request 3 */
#define SRC_GTMMCS14	(*( SRC_CPU0SBSRC_type *) 0xF00399B0U)	/* GTM MCS1 Shared Service Request 4 */
#define SRC_GTMMCS15	(*( SRC_CPU0SBSRC_type *) 0xF00399B4U)	/* GTM MCS1 Shared Service Request 5 */
#define SRC_GTMMCS16	(*( SRC_CPU0SBSRC_type *) 0xF00399B8U)	/* GTM MCS1 Shared Service Request 6 */
#define SRC_GTMMCS17	(*( SRC_CPU0SBSRC_type *) 0xF00399BCU)	/* GTM MCS1 Shared Service Request 7 */
#define SRC_GTMMCS20	(*( SRC_CPU0SBSRC_type *) 0xF00399C0U)	/* GTM MCS2 Shared Service Request 0 */
#define SRC_GTMMCS21	(*( SRC_CPU0SBSRC_type *) 0xF00399C4U)	/* GTM MCS2 Shared Service Request 1 */
#define SRC_GTMMCS22	(*( SRC_CPU0SBSRC_type *) 0xF00399C8U)	/* GTM MCS2 Shared Service Request 2 */
#define SRC_GTMMCS23	(*( SRC_CPU0SBSRC_type *) 0xF00399CCU)	/* GTM MCS2 Shared Service Request 3 */
#define SRC_GTMMCS24	(*( SRC_CPU0SBSRC_type *) 0xF00399D0U)	/* GTM MCS2 Shared Service Request 4 */
#define SRC_GTMMCS25	(*( SRC_CPU0SBSRC_type *) 0xF00399D4U)	/* GTM MCS2 Shared Service Request 5 */
#define SRC_GTMMCS26	(*( SRC_CPU0SBSRC_type *) 0xF00399D8U)	/* GTM MCS2 Shared Service Request 6 */
#define SRC_GTMMCS27	(*( SRC_CPU0SBSRC_type *) 0xF00399DCU)	/* GTM MCS2 Shared Service Request 7 */
#define SRC_GTMMCS30	(*( SRC_CPU0SBSRC_type *) 0xF00399E0U)	/* GTM MCS3 Shared Service Request 0 */
#define SRC_GTMMCS31	(*( SRC_CPU0SBSRC_type *) 0xF00399E4U)	/* GTM MCS3 Shared Service Request 1 */
#define SRC_GTMMCS32	(*( SRC_CPU0SBSRC_type *) 0xF00399E8U)	/* GTM MCS3 Shared Service Request 2 */
#define SRC_GTMMCS33	(*( SRC_CPU0SBSRC_type *) 0xF00399ECU)	/* GTM MCS3 Shared Service Request 3 */
#define SRC_GTMMCS34	(*( SRC_CPU0SBSRC_type *) 0xF00399F0U)	/* GTM MCS3 Shared Service Request 4 */
#define SRC_GTMMCS35	(*( SRC_CPU0SBSRC_type *) 0xF00399F4U)	/* GTM MCS3 Shared Service Request 5 */
#define SRC_GTMMCS36	(*( SRC_CPU0SBSRC_type *) 0xF00399F8U)	/* GTM MCS3 Shared Service Request 6 */
#define SRC_GTMMCS37	(*( SRC_CPU0SBSRC_type *) 0xF00399FCU)	/* GTM MCS3 Shared Service Request 7 */
#define SRC_GTMMCS40	(*( SRC_CPU0SBSRC_type *) 0xF0039A00U)	/* GTM MCS4 Shared Service Request 0 */
#define SRC_GTMMCS41	(*( SRC_CPU0SBSRC_type *) 0xF0039A04U)	/* GTM MCS4 Shared Service Request 1 */
#define SRC_GTMMCS42	(*( SRC_CPU0SBSRC_type *) 0xF0039A08U)	/* GTM MCS4 Shared Service Request 2 */
#define SRC_GTMMCS43	(*( SRC_CPU0SBSRC_type *) 0xF0039A0CU)	/* GTM MCS4 Shared Service Request 3 */
#define SRC_GTMMCS44	(*( SRC_CPU0SBSRC_type *) 0xF0039A10U)	/* GTM MCS4 Shared Service Request 4 */
#define SRC_GTMMCS45	(*( SRC_CPU0SBSRC_type *) 0xF0039A14U)	/* GTM MCS4 Shared Service Request 5 */
#define SRC_GTMMCS46	(*( SRC_CPU0SBSRC_type *) 0xF0039A18U)	/* GTM MCS4 Shared Service Request 6 */
#define SRC_GTMMCS47	(*( SRC_CPU0SBSRC_type *) 0xF0039A1CU)	/* GTM MCS4 Shared Service Request 7 */
#define SRC_GTMMCS50	(*( SRC_CPU0SBSRC_type *) 0xF0039A20U)	/* GTM MCS5 Shared Service Request 0 */
#define SRC_GTMMCS51	(*( SRC_CPU0SBSRC_type *) 0xF0039A24U)	/* GTM MCS5 Shared Service Request 1 */
#define SRC_GTMMCS52	(*( SRC_CPU0SBSRC_type *) 0xF0039A28U)	/* GTM MCS5 Shared Service Request 2 */
#define SRC_GTMMCS53	(*( SRC_CPU0SBSRC_type *) 0xF0039A2CU)	/* GTM MCS5 Shared Service Request 3 */
#define SRC_GTMMCS54	(*( SRC_CPU0SBSRC_type *) 0xF0039A30U)	/* GTM MCS5 Shared Service Request 4 */
#define SRC_GTMMCS55	(*( SRC_CPU0SBSRC_type *) 0xF0039A34U)	/* GTM MCS5 Shared Service Request 5 */
#define SRC_GTMMCS56	(*( SRC_CPU0SBSRC_type *) 0xF0039A38U)	/* GTM MCS5 Shared Service Request 6 */
#define SRC_GTMMCS57	(*( SRC_CPU0SBSRC_type *) 0xF0039A3CU)	/* GTM MCS5 Shared Service Request 7 */
#define SRC_GTMTOM00	(*( SRC_CPU0SBSRC_type *) 0xF0039B80U)	/* GTM TOM0 Shared Service Request 0 */
#define SRC_GTMTOM01	(*( SRC_CPU0SBSRC_type *) 0xF0039B84U)	/* GTM TOM0 Shared Service Request 1 */
#define SRC_GTMTOM02	(*( SRC_CPU0SBSRC_type *) 0xF0039B88U)	/* GTM TOM0 Shared Service Request 2 */
#define SRC_GTMTOM03	(*( SRC_CPU0SBSRC_type *) 0xF0039B8CU)	/* GTM TOM0 Shared Service Request 3 */
#define SRC_GTMTOM04	(*( SRC_CPU0SBSRC_type *) 0xF0039B90U)	/* GTM TOM0 Shared Service Request 4 */
#define SRC_GTMTOM05	(*( SRC_CPU0SBSRC_type *) 0xF0039B94U)	/* GTM TOM0 Shared Service Request 5 */
#define SRC_GTMTOM06	(*( SRC_CPU0SBSRC_type *) 0xF0039B98U)	/* GTM TOM0 Shared Service Request 6 */
#define SRC_GTMTOM07	(*( SRC_CPU0SBSRC_type *) 0xF0039B9CU)	/* GTM TOM0 Shared Service Request 7 */
#define SRC_GTMTOM10	(*( SRC_CPU0SBSRC_type *) 0xF0039BA0U)	/* GTM TOM1 Shared Service Request 0 */
#define SRC_GTMTOM11	(*( SRC_CPU0SBSRC_type *) 0xF0039BA4U)	/* GTM TOM1 Shared Service Request 1 */
#define SRC_GTMTOM12	(*( SRC_CPU0SBSRC_type *) 0xF0039BA8U)	/* GTM TOM1 Shared Service Request 2 */
#define SRC_GTMTOM13	(*( SRC_CPU0SBSRC_type *) 0xF0039BACU)	/* GTM TOM1 Shared Service Request 3 */
#define SRC_GTMTOM14	(*( SRC_CPU0SBSRC_type *) 0xF0039BB0U)	/* GTM TOM1 Shared Service Request 4 */
#define SRC_GTMTOM15	(*( SRC_CPU0SBSRC_type *) 0xF0039BB4U)	/* GTM TOM1 Shared Service Request 5 */
#define SRC_GTMTOM16	(*( SRC_CPU0SBSRC_type *) 0xF0039BB8U)	/* GTM TOM1 Shared Service Request 6 */
#define SRC_GTMTOM17	(*( SRC_CPU0SBSRC_type *) 0xF0039BBCU)	/* GTM TOM1 Shared Service Request 7 */
#define SRC_GTMTOM20	(*( SRC_CPU0SBSRC_type *) 0xF0039BC0U)	/* GTM TOM2 Shared Service Request 0 */
#define SRC_GTMTOM21	(*( SRC_CPU0SBSRC_type *) 0xF0039BC4U)	/* GTM TOM2 Shared Service Request 1 */
#define SRC_GTMTOM22	(*( SRC_CPU0SBSRC_type *) 0xF0039BC8U)	/* GTM TOM2 Shared Service Request 2 */
#define SRC_GTMTOM23	(*( SRC_CPU0SBSRC_type *) 0xF0039BCCU)	/* GTM TOM2 Shared Service Request 3 */
#define SRC_GTMTOM24	(*( SRC_CPU0SBSRC_type *) 0xF0039BD0U)	/* GTM TOM2 Shared Service Request 4 */
#define SRC_GTMTOM25	(*( SRC_CPU0SBSRC_type *) 0xF0039BD4U)	/* GTM TOM2 Shared Service Request 5 */
#define SRC_GTMTOM26	(*( SRC_CPU0SBSRC_type *) 0xF0039BD8U)	/* GTM TOM2 Shared Service Request 6 */
#define SRC_GTMTOM27	(*( SRC_CPU0SBSRC_type *) 0xF0039BDCU)	/* GTM TOM2 Shared Service Request 7 */
#define SRC_GTMTOM30	(*( SRC_CPU0SBSRC_type *) 0xF0039BE0U)	/* GTM TOM3 Shared Service Request 0 */
#define SRC_GTMTOM31	(*( SRC_CPU0SBSRC_type *) 0xF0039BE4U)	/* GTM TOM3 Shared Service Request 1 */
#define SRC_GTMTOM32	(*( SRC_CPU0SBSRC_type *) 0xF0039BE8U)	/* GTM TOM3 Shared Service Request 2 */
#define SRC_GTMTOM33	(*( SRC_CPU0SBSRC_type *) 0xF0039BECU)	/* GTM TOM3 Shared Service Request 3 */
#define SRC_GTMTOM34	(*( SRC_CPU0SBSRC_type *) 0xF0039BF0U)	/* GTM TOM3 Shared Service Request 4 */
#define SRC_GTMTOM35	(*( SRC_CPU0SBSRC_type *) 0xF0039BF4U)	/* GTM TOM3 Shared Service Request 5 */
#define SRC_GTMTOM36	(*( SRC_CPU0SBSRC_type *) 0xF0039BF8U)	/* GTM TOM3 Shared Service Request 6 */
#define SRC_GTMTOM37	(*( SRC_CPU0SBSRC_type *) 0xF0039BFCU)	/* GTM TOM3 Shared Service Request 7 */
#define SRC_GTMTOM40	(*( SRC_CPU0SBSRC_type *) 0xF0039C00U)	/* GTM TOM4 Shared Service Request 0 */
#define SRC_GTMTOM41	(*( SRC_CPU0SBSRC_type *) 0xF0039C04U)	/* GTM TOM4 Shared Service Request 1 */
#define SRC_GTMTOM42	(*( SRC_CPU0SBSRC_type *) 0xF0039C08U)	/* GTM TOM4 Shared Service Request 2 */
#define SRC_GTMTOM43	(*( SRC_CPU0SBSRC_type *) 0xF0039C0CU)	/* GTM TOM4 Shared Service Request 3 */
#define SRC_GTMTOM44	(*( SRC_CPU0SBSRC_type *) 0xF0039C10U)	/* GTM TOM4 Shared Service Request 4 */
#define SRC_GTMTOM45	(*( SRC_CPU0SBSRC_type *) 0xF0039C14U)	/* GTM TOM4 Shared Service Request 5 */
#define SRC_GTMTOM46	(*( SRC_CPU0SBSRC_type *) 0xF0039C18U)	/* GTM TOM4 Shared Service Request 6 */
#define SRC_GTMTOM47	(*( SRC_CPU0SBSRC_type *) 0xF0039C1CU)	/* GTM TOM4 Shared Service Request 7 */
#define SRC_GTMATOM00	(*( SRC_CPU0SBSRC_type *) 0xF0039D80U)	/* GTM ATOM0 Shared Service Request 0 */
#define SRC_GTMATOM01	(*( SRC_CPU0SBSRC_type *) 0xF0039D84U)	/* GTM ATOM0 Shared Service Request 1 */
#define SRC_GTMATOM02	(*( SRC_CPU0SBSRC_type *) 0xF0039D88U)	/* GTM ATOM0 Shared Service Request 2 */
#define SRC_GTMATOM03	(*( SRC_CPU0SBSRC_type *) 0xF0039D8CU)	/* GTM ATOM0 Shared Service Request 3 */
#define SRC_GTMATOM10	(*( SRC_CPU0SBSRC_type *) 0xF0039D90U)	/* GTM ATOM1 Shared Service Request 0 */
#define SRC_GTMATOM11	(*( SRC_CPU0SBSRC_type *) 0xF0039D94U)	/* GTM ATOM1 Shared Service Request 1 */
#define SRC_GTMATOM12	(*( SRC_CPU0SBSRC_type *) 0xF0039D98U)	/* GTM ATOM1 Shared Service Request 2 */
#define SRC_GTMATOM13	(*( SRC_CPU0SBSRC_type *) 0xF0039D9CU)	/* GTM ATOM1 Shared Service Request 3 */
#define SRC_GTMATOM20	(*( SRC_CPU0SBSRC_type *) 0xF0039DA0U)	/* GTM ATOM2 Shared Service Request 0 */
#define SRC_GTMATOM21	(*( SRC_CPU0SBSRC_type *) 0xF0039DA4U)	/* GTM ATOM2 Shared Service Request 1 */
#define SRC_GTMATOM22	(*( SRC_CPU0SBSRC_type *) 0xF0039DA8U)	/* GTM ATOM2 Shared Service Request 2 */
#define SRC_GTMATOM23	(*( SRC_CPU0SBSRC_type *) 0xF0039DACU)	/* GTM ATOM2 Shared Service Request 3 */
#define SRC_GTMATOM30	(*( SRC_CPU0SBSRC_type *) 0xF0039DB0U)	/* GTM ATOM3 Shared Service Request 0 */
#define SRC_GTMATOM31	(*( SRC_CPU0SBSRC_type *) 0xF0039DB4U)	/* GTM ATOM3 Shared Service Request 1 */
#define SRC_GTMATOM32	(*( SRC_CPU0SBSRC_type *) 0xF0039DB8U)	/* GTM ATOM3 Shared Service Request 2 */
#define SRC_GTMATOM33	(*( SRC_CPU0SBSRC_type *) 0xF0039DBCU)	/* GTM ATOM3 Shared Service Request 3 */
#define SRC_GTMATOM40	(*( SRC_CPU0SBSRC_type *) 0xF0039DC0U)	/* GTM ATOM4 Shared Service Request 0 */
#define SRC_GTMATOM41	(*( SRC_CPU0SBSRC_type *) 0xF0039DC4U)	/* GTM ATOM4 Shared Service Request 1 */
#define SRC_GTMATOM42	(*( SRC_CPU0SBSRC_type *) 0xF0039DC8U)	/* GTM ATOM4 Shared Service Request 2 */
#define SRC_GTMATOM43	(*( SRC_CPU0SBSRC_type *) 0xF0039DCCU)	/* GTM ATOM4 Shared Service Request 3 */
#define SRC_GTMATOM50	(*( SRC_CPU0SBSRC_type *) 0xF0039DD0U)	/* GTM ATOM5 Shared Service Request 0 */
#define SRC_GTMATOM51	(*( SRC_CPU0SBSRC_type *) 0xF0039DD4U)	/* GTM ATOM5 Shared Service Request 1 */
#define SRC_GTMATOM52	(*( SRC_CPU0SBSRC_type *) 0xF0039DD8U)	/* GTM ATOM5 Shared Service Request 2 */
#define SRC_GTMATOM53	(*( SRC_CPU0SBSRC_type *) 0xF0039DDCU)	/* GTM ATOM5 Shared Service Request 3 */
#define SRC_GTMATOM60	(*( SRC_CPU0SBSRC_type *) 0xF0039DE0U)	/* GTM ATOM6 Shared Service Request 0 */
#define SRC_GTMATOM61	(*( SRC_CPU0SBSRC_type *) 0xF0039DE4U)	/* GTM ATOM6 Shared Service Request 1 */
#define SRC_GTMATOM62	(*( SRC_CPU0SBSRC_type *) 0xF0039DE8U)	/* GTM ATOM6 Shared Service Request 2 */
#define SRC_GTMATOM63	(*( SRC_CPU0SBSRC_type *) 0xF0039DECU)	/* GTM ATOM6 Shared Service Request 3 */
#define SRC_GTMATOM70	(*( SRC_CPU0SBSRC_type *) 0xF0039DF0U)	/* GTM ATOM7 Shared Service Request 0 */
#define SRC_GTMATOM71	(*( SRC_CPU0SBSRC_type *) 0xF0039DF4U)	/* GTM ATOM7 Shared Service Request 1 */
#define SRC_GTMATOM72	(*( SRC_CPU0SBSRC_type *) 0xF0039DF8U)	/* GTM ATOM7 Shared Service Request 2 */
#define SRC_GTMATOM73	(*( SRC_CPU0SBSRC_type *) 0xF0039DFCU)	/* GTM ATOM7 Shared Service Request 3 */
#define SRC_GTMATOM80	(*( SRC_CPU0SBSRC_type *) 0xF0039E00U)	/* GTM ATOM8 Shared Service Request 0 */
#define SRC_GTMATOM81	(*( SRC_CPU0SBSRC_type *) 0xF0039E04U)	/* GTM ATOM8 Shared Service Request 1 */
#define SRC_GTMATOM82	(*( SRC_CPU0SBSRC_type *) 0xF0039E08U)	/* GTM ATOM8 Shared Service Request 2 */
#define SRC_GTMATOM83	(*( SRC_CPU0SBSRC_type *) 0xF0039E0CU)	/* GTM ATOM8 Shared Service Request 3 */
#define SRC_GTMMCSW00	(*( SRC_CPU0SBSRC_type *) 0xF0039F00U)	/* GTM Multi Channel Sequencer 0 Service Request 0 */
#define SRC_GTMMCSW01	(*( SRC_CPU0SBSRC_type *) 0xF0039F04U)	/* GTM Multi Channel Sequencer 0 Service Request 1 */
#define SRC_GTMMCSW02	(*( SRC_CPU0SBSRC_type *) 0xF0039F08U)	/* GTM Multi Channel Sequencer 0 Service Request 2 */
#define SRC_GTMMCSW03	(*( SRC_CPU0SBSRC_type *) 0xF0039F0CU)	/* GTM Multi Channel Sequencer 0 Service Request 3 */
#define SRC_GTMMCSW04	(*( SRC_CPU0SBSRC_type *) 0xF0039F10U)	/* GTM Multi Channel Sequencer 0 Service Request 4 */
#define SRC_GTMMCSW05	(*( SRC_CPU0SBSRC_type *) 0xF0039F14U)	/* GTM Multi Channel Sequencer 0 Service Request 5 */
#define SRC_GTMMCSW10	(*( SRC_CPU0SBSRC_type *) 0xF0039F40U)	/* GTM Multi Channel Sequencer 1 Service Request 0 */
#define SRC_GTMMCSW11	(*( SRC_CPU0SBSRC_type *) 0xF0039F44U)	/* GTM Multi Channel Sequencer 1 Service Request 1 */
#define SRC_GTMMCSW12	(*( SRC_CPU0SBSRC_type *) 0xF0039F48U)	/* GTM Multi Channel Sequencer 1 Service Request 2 */
#define SRC_GTMMCSW13	(*( SRC_CPU0SBSRC_type *) 0xF0039F4CU)	/* GTM Multi Channel Sequencer 1 Service Request 3 */
#define SRC_GTMMCSW14	(*( SRC_CPU0SBSRC_type *) 0xF0039F50U)	/* GTM Multi Channel Sequencer 1 Service Request 4 */
#define SRC_GTMMCSW15	(*( SRC_CPU0SBSRC_type *) 0xF0039F54U)	/* GTM Multi Channel Sequencer 1 Service Request 5 */
#define STM0_CLC	(*( STM0_CLC_type *) 0xF0000000U)	/* Clock Control Register */
#define STM1_CLC	(*( STM0_CLC_type *) 0xF0000100U)	/* Clock Control Register */
#define STM2_CLC	(*( STM0_CLC_type *) 0xF0000200U)	/* Clock Control Register */
#define STM0_ID	(*( STM0_ID_type *) 0xF0000008U)	/* Module Identification Register */
#define STM1_ID	(*( STM0_ID_type *) 0xF0000108U)	/* Module Identification Register */
#define STM2_ID	(*( STM0_ID_type *) 0xF0000208U)	/* Module Identification Register */
#define STM0_TIM0	(*( STM0_TIM0_type *) 0xF0000010U)	/* Timer Register 0 */
#define STM1_TIM0	(*( STM0_TIM0_type *) 0xF0000110U)	/* Timer Register 0 */
#define STM2_TIM0	(*( STM0_TIM0_type *) 0xF0000210U)	/* Timer Register 0 */
#define STM0_TIM0SV	(*( STM0_TIM0_type *) 0xF0000050U)	/* Timer Register 0 Second View */
#define STM1_TIM0SV	(*( STM0_TIM0_type *) 0xF0000150U)	/* Timer Register 0 Second View */
#define STM2_TIM0SV	(*( STM0_TIM0_type *) 0xF0000250U)	/* Timer Register 0 Second View */
#define STM0_TIM1	(*( STM0_TIM1_type *) 0xF0000014U)	/* Timer Register 1 */
#define STM1_TIM1	(*( STM0_TIM1_type *) 0xF0000114U)	/* Timer Register 1 */
#define STM2_TIM1	(*( STM0_TIM1_type *) 0xF0000214U)	/* Timer Register 1 */
#define STM0_TIM2	(*( STM0_TIM2_type *) 0xF0000018U)	/* Timer Register 2 */
#define STM1_TIM2	(*( STM0_TIM2_type *) 0xF0000118U)	/* Timer Register 2 */
#define STM2_TIM2	(*( STM0_TIM2_type *) 0xF0000218U)	/* Timer Register 2 */
#define STM0_TIM3	(*( STM0_TIM3_type *) 0xF000001CU)	/* Timer Register 3 */
#define STM1_TIM3	(*( STM0_TIM3_type *) 0xF000011CU)	/* Timer Register 3 */
#define STM2_TIM3	(*( STM0_TIM3_type *) 0xF000021CU)	/* Timer Register 3 */
#define STM0_TIM4	(*( STM0_TIM4_type *) 0xF0000020U)	/* Timer Register 4 */
#define STM1_TIM4	(*( STM0_TIM4_type *) 0xF0000120U)	/* Timer Register 4 */
#define STM2_TIM4	(*( STM0_TIM4_type *) 0xF0000220U)	/* Timer Register 4 */
#define STM0_TIM5	(*( STM0_TIM5_type *) 0xF0000024U)	/* Timer Register 5 */
#define STM1_TIM5	(*( STM0_TIM5_type *) 0xF0000124U)	/* Timer Register 5 */
#define STM2_TIM5	(*( STM0_TIM5_type *) 0xF0000224U)	/* Timer Register 5 */
#define STM0_TIM6	(*( STM0_TIM6_type *) 0xF0000028U)	/* Timer Register 6 */
#define STM1_TIM6	(*( STM0_TIM6_type *) 0xF0000128U)	/* Timer Register 6 */
#define STM2_TIM6	(*( STM0_TIM6_type *) 0xF0000228U)	/* Timer Register 6 */
#define STM0_CAP	(*( STM0_CAP_type *) 0xF000002CU)	/* Timer Capture Register */
#define STM1_CAP	(*( STM0_CAP_type *) 0xF000012CU)	/* Timer Capture Register */
#define STM2_CAP	(*( STM0_CAP_type *) 0xF000022CU)	/* Timer Capture Register */
#define STM0_CAPSV	(*( STM0_CAP_type *) 0xF0000054U)	/* Timer Capture Register Second View */
#define STM1_CAPSV	(*( STM0_CAP_type *) 0xF0000154U)	/* Timer Capture Register Second View */
#define STM2_CAPSV	(*( STM0_CAP_type *) 0xF0000254U)	/* Timer Capture Register Second View */
#define STM0_CMP0	(*( STM0_CMP0_type *) 0xF0000030U)	/* Compare Register 0 */
#define STM0_CMP1	(*( STM0_CMP0_type *) 0xF0000034U)	/* Compare Register 1 */
#define STM1_CMP0	(*( STM0_CMP0_type *) 0xF0000130U)	/* Compare Register 0 */
#define STM1_CMP1	(*( STM0_CMP0_type *) 0xF0000134U)	/* Compare Register 1 */
#define STM2_CMP0	(*( STM0_CMP0_type *) 0xF0000230U)	/* Compare Register 0 */
#define STM2_CMP1	(*( STM0_CMP0_type *) 0xF0000234U)	/* Compare Register 1 */
#define STM0_CMCON	(*( STM0_CMCON_type *) 0xF0000038U)	/* Compare Match Control Register */
#define STM1_CMCON	(*( STM0_CMCON_type *) 0xF0000138U)	/* Compare Match Control Register */
#define STM2_CMCON	(*( STM0_CMCON_type *) 0xF0000238U)	/* Compare Match Control Register */
#define STM0_ICR	(*( STM0_ICR_type *) 0xF000003CU)	/* Interrupt Control Register */
#define STM1_ICR	(*( STM0_ICR_type *) 0xF000013CU)	/* Interrupt Control Register */
#define STM2_ICR	(*( STM0_ICR_type *) 0xF000023CU)	/* Interrupt Control Register */
#define STM0_ISCR	(*( STM0_ISCR_type *) 0xF0000040U)	/* Interrupt Set/Clear Register */
#define STM1_ISCR	(*( STM0_ISCR_type *) 0xF0000140U)	/* Interrupt Set/Clear Register */
#define STM2_ISCR	(*( STM0_ISCR_type *) 0xF0000240U)	/* Interrupt Set/Clear Register */
#define STM0_OCS	(*( STM0_OCS_type *) 0xF00000E8U)	/* OCDS Control and Status */
#define STM1_OCS	(*( STM0_OCS_type *) 0xF00001E8U)	/* OCDS Control and Status */
#define STM2_OCS	(*( STM0_OCS_type *) 0xF00002E8U)	/* OCDS Control and Status */
#define STM0_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00000FCU)	/* Access Enable Register 0 */
#define STM1_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00001FCU)	/* Access Enable Register 0 */
#define STM2_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00002FCU)	/* Access Enable Register 0 */
#define STM0_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00000F8U)	/* Access Enable Register 1 */
#define STM1_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00001F8U)	/* Access Enable Register 1 */
#define STM2_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00002F8U)	/* Access Enable Register 1 */
#define STM0_KRST0	(*( STM0_KRST0_type *) 0xF00000F4U)	/* Kernel Reset Register 0 */
#define STM1_KRST0	(*( STM0_KRST0_type *) 0xF00001F4U)	/* Kernel Reset Register 0 */
#define STM2_KRST0	(*( STM0_KRST0_type *) 0xF00002F4U)	/* Kernel Reset Register 0 */
#define STM0_KRST1	(*( STM0_KRST1_type *) 0xF00000F0U)	/* Kernel Reset Register 1 */
#define STM1_KRST1	(*( STM0_KRST1_type *) 0xF00001F0U)	/* Kernel Reset Register 1 */
#define STM2_KRST1	(*( STM0_KRST1_type *) 0xF00002F0U)	/* Kernel Reset Register 1 */
#define STM0_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00000ECU)	/* Kernel Reset Status Clear Register */
#define STM1_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00001ECU)	/* Kernel Reset Status Clear Register */
#define STM2_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00002ECU)	/* Kernel Reset Status Clear Register */
#define ASCLIN0_IOCR	(*( ASCLIN0_IOCR_type *) 0xF0000604U)	/* Input and Output Control Register */
#define ASCLIN1_IOCR	(*( ASCLIN0_IOCR_type *) 0xF0000704U)	/* Input and Output Control Register */
#define ASCLIN2_IOCR	(*( ASCLIN0_IOCR_type *) 0xF0000804U)	/* Input and Output Control Register */
#define ASCLIN3_IOCR	(*( ASCLIN0_IOCR_type *) 0xF0000904U)	/* Input and Output Control Register */
#define ASCLIN0_ID	(*( ASCLIN0_ID_type *) 0xF0000608U)	/* Module Identification Register */
#define ASCLIN1_ID	(*( ASCLIN0_ID_type *) 0xF0000708U)	/* Module Identification Register */
#define ASCLIN2_ID	(*( ASCLIN0_ID_type *) 0xF0000808U)	/* Module Identification Register */
#define ASCLIN3_ID	(*( ASCLIN0_ID_type *) 0xF0000908U)	/* Module Identification Register */
#define ASCLIN0_TXFIFOCON	(*( ASCLIN0_TXFIFOCON_type *) 0xF000060CU)	/* TX FIFO Configuration Register */
#define ASCLIN1_TXFIFOCON	(*( ASCLIN0_TXFIFOCON_type *) 0xF000070CU)	/* TX FIFO Configuration Register */
#define ASCLIN2_TXFIFOCON	(*( ASCLIN0_TXFIFOCON_type *) 0xF000080CU)	/* TX FIFO Configuration Register */
#define ASCLIN3_TXFIFOCON	(*( ASCLIN0_TXFIFOCON_type *) 0xF000090CU)	/* TX FIFO Configuration Register */
#define ASCLIN0_RXFIFOCON	(*( ASCLIN0_RXFIFOCON_type *) 0xF0000610U)	/* RX FIFO Configuration Register */
#define ASCLIN1_RXFIFOCON	(*( ASCLIN0_RXFIFOCON_type *) 0xF0000710U)	/* RX FIFO Configuration Register */
#define ASCLIN2_RXFIFOCON	(*( ASCLIN0_RXFIFOCON_type *) 0xF0000810U)	/* RX FIFO Configuration Register */
#define ASCLIN3_RXFIFOCON	(*( ASCLIN0_RXFIFOCON_type *) 0xF0000910U)	/* RX FIFO Configuration Register */
#define ASCLIN0_BITCON	(*( ASCLIN0_BITCON_type *) 0xF0000614U)	/* Bit Configuration Register */
#define ASCLIN1_BITCON	(*( ASCLIN0_BITCON_type *) 0xF0000714U)	/* Bit Configuration Register */
#define ASCLIN2_BITCON	(*( ASCLIN0_BITCON_type *) 0xF0000814U)	/* Bit Configuration Register */
#define ASCLIN3_BITCON	(*( ASCLIN0_BITCON_type *) 0xF0000914U)	/* Bit Configuration Register */
#define ASCLIN0_FRAMECON	(*( ASCLIN0_FRAMECON_type *) 0xF0000618U)	/* Frame Control Register */
#define ASCLIN1_FRAMECON	(*( ASCLIN0_FRAMECON_type *) 0xF0000718U)	/* Frame Control Register */
#define ASCLIN2_FRAMECON	(*( ASCLIN0_FRAMECON_type *) 0xF0000818U)	/* Frame Control Register */
#define ASCLIN3_FRAMECON	(*( ASCLIN0_FRAMECON_type *) 0xF0000918U)	/* Frame Control Register */
#define ASCLIN0_DATCON	(*( ASCLIN0_DATCON_type *) 0xF000061CU)	/* Data Configuration Register */
#define ASCLIN1_DATCON	(*( ASCLIN0_DATCON_type *) 0xF000071CU)	/* Data Configuration Register */
#define ASCLIN2_DATCON	(*( ASCLIN0_DATCON_type *) 0xF000081CU)	/* Data Configuration Register */
#define ASCLIN3_DATCON	(*( ASCLIN0_DATCON_type *) 0xF000091CU)	/* Data Configuration Register */
#define ASCLIN0_BRG	(*( ASCLIN0_BRG_type *) 0xF0000620U)	/* Baud Rate Generation Register */
#define ASCLIN1_BRG	(*( ASCLIN0_BRG_type *) 0xF0000720U)	/* Baud Rate Generation Register */
#define ASCLIN2_BRG	(*( ASCLIN0_BRG_type *) 0xF0000820U)	/* Baud Rate Generation Register */
#define ASCLIN3_BRG	(*( ASCLIN0_BRG_type *) 0xF0000920U)	/* Baud Rate Generation Register */
#define ASCLIN0_BRD	(*( ASCLIN0_BRD_type *) 0xF0000624U)	/* Baud Rate Detection Register */
#define ASCLIN1_BRD	(*( ASCLIN0_BRD_type *) 0xF0000724U)	/* Baud Rate Detection Register */
#define ASCLIN2_BRD	(*( ASCLIN0_BRD_type *) 0xF0000824U)	/* Baud Rate Detection Register */
#define ASCLIN3_BRD	(*( ASCLIN0_BRD_type *) 0xF0000924U)	/* Baud Rate Detection Register */
#define ASCLIN0_LINCON	(*( ASCLIN0_LINCON_type *) 0xF0000628U)	/* LIN Control Register */
#define ASCLIN1_LINCON	(*( ASCLIN0_LINCON_type *) 0xF0000728U)	/* LIN Control Register */
#define ASCLIN2_LINCON	(*( ASCLIN0_LINCON_type *) 0xF0000828U)	/* LIN Control Register */
#define ASCLIN3_LINCON	(*( ASCLIN0_LINCON_type *) 0xF0000928U)	/* LIN Control Register */
#define ASCLIN0_LINBTIMER	(*( ASCLIN0_LINBTIMER_type *) 0xF000062CU)	/* LIN Break Timer Register */
#define ASCLIN1_LINBTIMER	(*( ASCLIN0_LINBTIMER_type *) 0xF000072CU)	/* LIN Break Timer Register */
#define ASCLIN2_LINBTIMER	(*( ASCLIN0_LINBTIMER_type *) 0xF000082CU)	/* LIN Break Timer Register */
#define ASCLIN3_LINBTIMER	(*( ASCLIN0_LINBTIMER_type *) 0xF000092CU)	/* LIN Break Timer Register */
#define ASCLIN0_LINHTIMER	(*( ASCLIN0_LINHTIMER_type *) 0xF0000630U)	/* LIN Header Timer Register */
#define ASCLIN1_LINHTIMER	(*( ASCLIN0_LINHTIMER_type *) 0xF0000730U)	/* LIN Header Timer Register */
#define ASCLIN2_LINHTIMER	(*( ASCLIN0_LINHTIMER_type *) 0xF0000830U)	/* LIN Header Timer Register */
#define ASCLIN3_LINHTIMER	(*( ASCLIN0_LINHTIMER_type *) 0xF0000930U)	/* LIN Header Timer Register */
#define ASCLIN0_FLAGS	(*( ASCLIN0_FLAGS_type *) 0xF0000634U)	/* Flags Register */
#define ASCLIN1_FLAGS	(*( ASCLIN0_FLAGS_type *) 0xF0000734U)	/* Flags Register */
#define ASCLIN2_FLAGS	(*( ASCLIN0_FLAGS_type *) 0xF0000834U)	/* Flags Register */
#define ASCLIN3_FLAGS	(*( ASCLIN0_FLAGS_type *) 0xF0000934U)	/* Flags Register */
#define ASCLIN0_FLAGSSET	(*( ASCLIN0_FLAGSSET_type *) 0xF0000638U)	/* Flags Set Register */
#define ASCLIN1_FLAGSSET	(*( ASCLIN0_FLAGSSET_type *) 0xF0000738U)	/* Flags Set Register */
#define ASCLIN2_FLAGSSET	(*( ASCLIN0_FLAGSSET_type *) 0xF0000838U)	/* Flags Set Register */
#define ASCLIN3_FLAGSSET	(*( ASCLIN0_FLAGSSET_type *) 0xF0000938U)	/* Flags Set Register */
#define ASCLIN0_FLAGSCLEAR	(*( ASCLIN0_FLAGSCLEAR_type *) 0xF000063CU)	/* Flags Clear Register */
#define ASCLIN1_FLAGSCLEAR	(*( ASCLIN0_FLAGSCLEAR_type *) 0xF000073CU)	/* Flags Clear Register */
#define ASCLIN2_FLAGSCLEAR	(*( ASCLIN0_FLAGSCLEAR_type *) 0xF000083CU)	/* Flags Clear Register */
#define ASCLIN3_FLAGSCLEAR	(*( ASCLIN0_FLAGSCLEAR_type *) 0xF000093CU)	/* Flags Clear Register */
#define ASCLIN0_FLAGSENABLE	(*( ASCLIN0_FLAGSENABLE_type *) 0xF0000640U)	/* Flags Enable Register */
#define ASCLIN1_FLAGSENABLE	(*( ASCLIN0_FLAGSENABLE_type *) 0xF0000740U)	/* Flags Enable Register */
#define ASCLIN2_FLAGSENABLE	(*( ASCLIN0_FLAGSENABLE_type *) 0xF0000840U)	/* Flags Enable Register */
#define ASCLIN3_FLAGSENABLE	(*( ASCLIN0_FLAGSENABLE_type *) 0xF0000940U)	/* Flags Enable Register */
#define ASCLIN0_TXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000644U)	/* Transmit Data Register */
#define ASCLIN1_TXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000744U)	/* Transmit Data Register */
#define ASCLIN2_TXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000844U)	/* Transmit Data Register */
#define ASCLIN3_TXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000944U)	/* Transmit Data Register */
#define ASCLIN0_RXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000648U)	/* Receive Data Register */
#define ASCLIN1_RXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000748U)	/* Receive Data Register */
#define ASCLIN2_RXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000848U)	/* Receive Data Register */
#define ASCLIN3_RXDATA	(*( ASCLIN0_TXDATA_type *) 0xF0000948U)	/* Receive Data Register */
#define ASCLIN0_CSR	(*( ASCLIN0_CSR_type *) 0xF000064CU)	/* Clock Selection Register */
#define ASCLIN1_CSR	(*( ASCLIN0_CSR_type *) 0xF000074CU)	/* Clock Selection Register */
#define ASCLIN2_CSR	(*( ASCLIN0_CSR_type *) 0xF000084CU)	/* Clock Selection Register */
#define ASCLIN3_CSR	(*( ASCLIN0_CSR_type *) 0xF000094CU)	/* Clock Selection Register */
#define ASCLIN0_RXDATAD	(*( ASCLIN0_TXDATA_type *) 0xF0000650U)	/* Receive Data Debug Register */
#define ASCLIN1_RXDATAD	(*( ASCLIN0_TXDATA_type *) 0xF0000750U)	/* Receive Data Debug Register */
#define ASCLIN2_RXDATAD	(*( ASCLIN0_TXDATA_type *) 0xF0000850U)	/* Receive Data Debug Register */
#define ASCLIN3_RXDATAD	(*( ASCLIN0_TXDATA_type *) 0xF0000950U)	/* Receive Data Debug Register */
#define ASCLIN0_CLC	(*( STM0_CLC_type *) 0xF0000600U)	/* Clock Control Register */
#define ASCLIN1_CLC	(*( STM0_CLC_type *) 0xF0000700U)	/* Clock Control Register */
#define ASCLIN2_CLC	(*( STM0_CLC_type *) 0xF0000800U)	/* Clock Control Register */
#define ASCLIN3_CLC	(*( STM0_CLC_type *) 0xF0000900U)	/* Clock Control Register */
#define ASCLIN0_OCS	(*( STM0_OCS_type *) 0xF00006E8U)	/* OCDS Control and Status */
#define ASCLIN1_OCS	(*( STM0_OCS_type *) 0xF00007E8U)	/* OCDS Control and Status */
#define ASCLIN2_OCS	(*( STM0_OCS_type *) 0xF00008E8U)	/* OCDS Control and Status */
#define ASCLIN3_OCS	(*( STM0_OCS_type *) 0xF00009E8U)	/* OCDS Control and Status */
#define ASCLIN0_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00006FCU)	/* Access Enable Register 0 */
#define ASCLIN1_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00007FCU)	/* Access Enable Register 0 */
#define ASCLIN2_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00008FCU)	/* Access Enable Register 0 */
#define ASCLIN3_ACCEN0	(*( XBAR_ACCEN0_type *) 0xF00009FCU)	/* Access Enable Register 0 */
#define ASCLIN0_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00006F8U)	/* Access Enable Register 1 */
#define ASCLIN1_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00007F8U)	/* Access Enable Register 1 */
#define ASCLIN2_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00008F8U)	/* Access Enable Register 1 */
#define ASCLIN3_ACCEN1	(*( XBAR_ACCEN1_type *) 0xF00009F8U)	/* Access Enable Register 1 */
#define ASCLIN0_KRST0	(*( STM0_KRST0_type *) 0xF00006F4U)	/* Kernel Reset Register 0 */
#define ASCLIN1_KRST0	(*( STM0_KRST0_type *) 0xF00007F4U)	/* Kernel Reset Register 0 */
#define ASCLIN2_KRST0	(*( STM0_KRST0_type *) 0xF00008F4U)	/* Kernel Reset Register 0 */
#define ASCLIN3_KRST0	(*( STM0_KRST0_type *) 0xF00009F4U)	/* Kernel Reset Register 0 */
#define ASCLIN0_KRST1	(*( STM0_KRST1_type *) 0xF00006F0U)	/* Kernel Reset Register 1 */
#define ASCLIN1_KRST1	(*( STM0_KRST1_type *) 0xF00007F0U)	/* Kernel Reset Register 1 */
#define ASCLIN2_KRST1	(*( STM0_KRST1_type *) 0xF00008F0U)	/* Kernel Reset Register 1 */
#define ASCLIN3_KRST1	(*( STM0_KRST1_type *) 0xF00009F0U)	/* Kernel Reset Register 1 */
#define ASCLIN0_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00006ECU)	/* Kernel Reset Status Clear Register */
#define ASCLIN1_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00007ECU)	/* Kernel Reset Status Clear Register */
#define ASCLIN2_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00008ECU)	/* Kernel Reset Status Clear Register */
#define ASCLIN3_KRSTCLR	(*( STM0_KRSTCLR_type *) 0xF00009ECU)	/* Kernel Reset Status Clear Register */
/*lint -restore */
#endif /* Os_TC29x_DEFS_H */


/* These macros can be used to disable and enable individual interrupts by
 * SRC name or configuration name [$TargetHT 167] [$TargetHT 168] [$TargetHT 169]
 */
#define Os_Disable_SRC_GPSR02() SRC_GPSR02.U = 0x1400U
#define Os_Disable_Os_CrossCoreISR2() Os_Disable_SRC_GPSR02()
#define Os_Enable_SRC_GPSR02()  SRC_GPSR02.U = 0x1401U
#define Os_Enable_Os_CrossCoreISR2()  Os_Enable_SRC_GPSR02()
#define Os_Disable_SRC_GPSR01() SRC_GPSR01.U = 0xc00U
#define Os_Disable_Os_CrossCoreISR1() Os_Disable_SRC_GPSR01()
#define Os_Enable_SRC_GPSR01()  SRC_GPSR01.U = 0xc01U
#define Os_Enable_Os_CrossCoreISR1()  Os_Enable_SRC_GPSR01()
#define Os_Disable_SRC_GPSR00() SRC_GPSR00.U = 0x400U
#define Os_Disable_Os_CrossCoreISR0() Os_Disable_SRC_GPSR00()
#define Os_Enable_SRC_GPSR00()  SRC_GPSR00.U = 0x401U
#define Os_Enable_Os_CrossCoreISR0()  Os_Enable_SRC_GPSR00()
#define Os_Disable_SRC_STM0SR0() SRC_STM0SR0.U = 0x1400U
#define Os_Disable_OsKRN_SCHEDULER_MANAGE_IT() Os_Disable_SRC_STM0SR0()
#define Os_Enable_SRC_STM0SR0()  SRC_STM0SR0.U = 0x1402U
#define Os_Enable_OsKRN_SCHEDULER_MANAGE_IT()  Os_Enable_SRC_STM0SR0()
#define Os_Disable_SRC_GTMTIM17() SRC_GTMTIM17.U = 0x1400U
#define Os_Disable_OsCJ135_U2450_ICU_IRQ_ISR() Os_Disable_SRC_GTMTIM17()
#define Os_Enable_SRC_GTMTIM17()  SRC_GTMTIM17.U = 0x1403U
#define Os_Enable_OsCJ135_U2450_ICU_IRQ_ISR()  Os_Enable_SRC_GTMTIM17()
#define Os_Disable_SRC_GTMTOM12() SRC_GTMTOM12.U = 0x1400U
#define Os_Disable_OsCJ135_U2450_GPT_IRQ_ISR() Os_Disable_SRC_GTMTOM12()
#define Os_Enable_SRC_GTMTOM12()  SRC_GTMTOM12.U = 0x1404U
#define Os_Enable_OsCJ135_U2450_GPT_IRQ_ISR()  Os_Enable_SRC_GTMTOM12()
#define Os_Disable_SRC_ASCLIN1ERR() SRC_ASCLIN1ERR.U = 0xc00U
#define Os_Disable_OsSRC_ASCLIN_ASCLIN1_ERR_ISR() Os_Disable_SRC_ASCLIN1ERR()
#define Os_Enable_SRC_ASCLIN1ERR()  SRC_ASCLIN1ERR.U = 0xc05U
#define Os_Enable_OsSRC_ASCLIN_ASCLIN1_ERR_ISR()  Os_Enable_SRC_ASCLIN1ERR()
#define Os_Disable_SRC_ASCLIN1RX() SRC_ASCLIN1RX.U = 0xc00U
#define Os_Disable_OsSRC_ASCLIN_ASCLIN1_RX_ISR() Os_Disable_SRC_ASCLIN1RX()
#define Os_Enable_SRC_ASCLIN1RX()  SRC_ASCLIN1RX.U = 0xc06U
#define Os_Enable_OsSRC_ASCLIN_ASCLIN1_RX_ISR()  Os_Enable_SRC_ASCLIN1RX()
#define Os_Disable_SRC_ASCLIN1TX() SRC_ASCLIN1TX.U = 0xc00U
#define Os_Disable_OsSRC_ASCLIN_ASCLIN1_TX_ISR() Os_Disable_SRC_ASCLIN1TX()
#define Os_Enable_SRC_ASCLIN1TX()  SRC_ASCLIN1TX.U = 0xc07U
#define Os_Enable_OsSRC_ASCLIN_ASCLIN1_TX_ISR()  Os_Enable_SRC_ASCLIN1TX()
#define Os_Disable_SRC_CANINT8() SRC_CANINT8.U = 0xc00U
#define Os_Disable_OsCAN_0_BUS_OFF() Os_Disable_SRC_CANINT8()
#define Os_Enable_SRC_CANINT8()  SRC_CANINT8.U = 0xc08U
#define Os_Enable_OsCAN_0_BUS_OFF()  Os_Enable_SRC_CANINT8()
#define Os_Disable_SRC_CANINT4() SRC_CANINT4.U = 0xc00U
#define Os_Disable_OsCAN_0_RECEIVE() Os_Disable_SRC_CANINT4()
#define Os_Enable_SRC_CANINT4()  SRC_CANINT4.U = 0xc09U
#define Os_Enable_OsCAN_0_RECEIVE()  Os_Enable_SRC_CANINT4()
#define Os_Disable_SRC_CANINT0() SRC_CANINT0.U = 0xc00U
#define Os_Disable_OsCAN_0_TRANSMIT() Os_Disable_SRC_CANINT0()
#define Os_Enable_SRC_CANINT0()  SRC_CANINT0.U = 0xc0aU
#define Os_Enable_OsCAN_0_TRANSMIT()  Os_Enable_SRC_CANINT0()
#define Os_Disable_SRC_CANINT9() SRC_CANINT9.U = 0xc00U
#define Os_Disable_OsCAN_1_BUS_OFF() Os_Disable_SRC_CANINT9()
#define Os_Enable_SRC_CANINT9()  SRC_CANINT9.U = 0xc0bU
#define Os_Enable_OsCAN_1_BUS_OFF()  Os_Enable_SRC_CANINT9()
#define Os_Disable_SRC_CANINT5() SRC_CANINT5.U = 0xc00U
#define Os_Disable_OsCAN_1_RECEIVE() Os_Disable_SRC_CANINT5()
#define Os_Enable_SRC_CANINT5()  SRC_CANINT5.U = 0xc0cU
#define Os_Enable_OsCAN_1_RECEIVE()  Os_Enable_SRC_CANINT5()
#define Os_Disable_SRC_CANINT1() SRC_CANINT1.U = 0xc00U
#define Os_Disable_OsCAN_1_TRANSMIT() Os_Disable_SRC_CANINT1()
#define Os_Enable_SRC_CANINT1()  SRC_CANINT1.U = 0xc0dU
#define Os_Enable_OsCAN_1_TRANSMIT()  Os_Enable_SRC_CANINT1()
#define Os_Disable_SRC_CANINT10() SRC_CANINT10.U = 0xc00U
#define Os_Disable_OsCAN_2_BUS_OFF() Os_Disable_SRC_CANINT10()
#define Os_Enable_SRC_CANINT10()  SRC_CANINT10.U = 0xc0eU
#define Os_Enable_OsCAN_2_BUS_OFF()  Os_Enable_SRC_CANINT10()
#define Os_Disable_SRC_CANINT6() SRC_CANINT6.U = 0xc00U
#define Os_Disable_OsCAN_2_RECEIVE() Os_Disable_SRC_CANINT6()
#define Os_Enable_SRC_CANINT6()  SRC_CANINT6.U = 0xc0fU
#define Os_Enable_OsCAN_2_RECEIVE()  Os_Enable_SRC_CANINT6()
#define Os_Disable_SRC_CANINT2() SRC_CANINT2.U = 0xc00U
#define Os_Disable_OsCAN_2_TRANSMIT() Os_Disable_SRC_CANINT2()
#define Os_Enable_SRC_CANINT2()  SRC_CANINT2.U = 0xc10U
#define Os_Enable_OsCAN_2_TRANSMIT()  Os_Enable_SRC_CANINT2()
#define Os_Disable_SRC_CANINT11() SRC_CANINT11.U = 0xc00U
#define Os_Disable_OsCAN_3_BUS_OFF() Os_Disable_SRC_CANINT11()
#define Os_Enable_SRC_CANINT11()  SRC_CANINT11.U = 0xc11U
#define Os_Enable_OsCAN_3_BUS_OFF()  Os_Enable_SRC_CANINT11()
#define Os_Disable_SRC_CANINT7() SRC_CANINT7.U = 0xc00U
#define Os_Disable_OsCAN_3_RECEIVE() Os_Disable_SRC_CANINT7()
#define Os_Enable_SRC_CANINT7()  SRC_CANINT7.U = 0xc12U
#define Os_Enable_OsCAN_3_RECEIVE()  Os_Enable_SRC_CANINT7()
#define Os_Disable_SRC_CANINT3() SRC_CANINT3.U = 0xc00U
#define Os_Disable_OsCAN_3_TRANSMIT() Os_Disable_SRC_CANINT3()
#define Os_Enable_SRC_CANINT3()  SRC_CANINT3.U = 0xc13U
#define Os_Enable_OsCAN_3_TRANSMIT()  Os_Enable_SRC_CANINT3()
#define Os_Disable_SRC_DMACH10() SRC_DMACH10.U = 0x1400U
#define Os_Disable_OsDMA_ISR_MSC0RX() Os_Disable_SRC_DMACH10()
#define Os_Enable_SRC_DMACH10()  SRC_DMACH10.U = 0x1414U
#define Os_Enable_OsDMA_ISR_MSC0RX()  Os_Enable_SRC_DMACH10()
#define Os_Disable_SRC_GTMTOM26() SRC_GTMTOM26.U = 0x1400U
#define Os_Disable_OsTHRHAL_PAP_PLUS_IT() Os_Disable_SRC_GTMTOM26()
#define Os_Enable_SRC_GTMTOM26()  SRC_GTMTOM26.U = 0x1415U
#define Os_Enable_OsTHRHAL_PAP_PLUS_IT()  Os_Enable_SRC_GTMTOM26()
#define Os_Disable_SRC_MSC0SR4() SRC_MSC0SR4.U = 0x1400U
#define Os_Disable_OsTLE8718_CMD_RX_TIMEOUT_IT() Os_Disable_SRC_MSC0SR4()
#define Os_Enable_SRC_MSC0SR4()  SRC_MSC0SR4.U = 0x1416U
#define Os_Enable_OsTLE8718_CMD_RX_TIMEOUT_IT()  Os_Enable_SRC_MSC0SR4()
#define Os_Disable_SRC_MSC0SR0() SRC_MSC0SR0.U = 0x1400U
#define Os_Disable_OsTLE8718_CMD_TX_IT() Os_Disable_SRC_MSC0SR0()
#define Os_Enable_SRC_MSC0SR0()  SRC_MSC0SR0.U = 0x1417U
#define Os_Enable_OsTLE8718_CMD_TX_IT()  Os_Enable_SRC_MSC0SR0()
#define Os_Disable_SRC_DMACH0() SRC_DMACH0.U = 0x1400U
#define Os_Disable_OsDMA_ISR_QSPI0RX() Os_Disable_SRC_DMACH0()
#define Os_Enable_SRC_DMACH0()  SRC_DMACH0.U = 0x1418U
#define Os_Enable_OsDMA_ISR_QSPI0RX()  Os_Enable_SRC_DMACH0()
#define Os_Disable_SRC_DMACH4() SRC_DMACH4.U = 0x1400U
#define Os_Disable_OsDMA_ISR_QSPI2RX() Os_Disable_SRC_DMACH4()
#define Os_Enable_SRC_DMACH4()  SRC_DMACH4.U = 0x1419U
#define Os_Enable_OsDMA_ISR_QSPI2RX()  Os_Enable_SRC_DMACH4()
#define Os_Disable_SRC_DMACH8() SRC_DMACH8.U = 0x1400U
#define Os_Disable_OsDMA_ISR_QSPI4RX() Os_Disable_SRC_DMACH8()
#define Os_Enable_SRC_DMACH8()  SRC_DMACH8.U = 0x141aU
#define Os_Enable_OsDMA_ISR_QSPI4RX()  Os_Enable_SRC_DMACH8()
#define Os_Disable_SRC_DMACH1() SRC_DMACH1.U = 0x1400U
#define Os_Disable_OsDMA_ISR_QSPI0TX() Os_Disable_SRC_DMACH1()
#define Os_Enable_SRC_DMACH1()  SRC_DMACH1.U = 0x141bU
#define Os_Enable_OsDMA_ISR_QSPI0TX()  Os_Enable_SRC_DMACH1()
#define Os_Disable_SRC_DMACH5() SRC_DMACH5.U = 0x1400U
#define Os_Disable_OsDMA_ISR_QSPI2TX() Os_Disable_SRC_DMACH5()
#define Os_Enable_SRC_DMACH5()  SRC_DMACH5.U = 0x141cU
#define Os_Enable_OsDMA_ISR_QSPI2TX()  Os_Enable_SRC_DMACH5()
#define Os_Disable_SRC_DMACH9() SRC_DMACH9.U = 0x1400U
#define Os_Disable_OsDMA_ISR_QSPI4TX() Os_Disable_SRC_DMACH9()
#define Os_Enable_SRC_DMACH9()  SRC_DMACH9.U = 0x141dU
#define Os_Enable_OsDMA_ISR_QSPI4TX()  Os_Enable_SRC_DMACH9()
#define Os_Disable_SRC_QSPI0ERR() SRC_QSPI0ERR.U = 0x1400U
#define Os_Disable_OsSRC_SPI0_ERR_ISR() Os_Disable_SRC_QSPI0ERR()
#define Os_Enable_SRC_QSPI0ERR()  SRC_QSPI0ERR.U = 0x141eU
#define Os_Enable_OsSRC_SPI0_ERR_ISR()  Os_Enable_SRC_QSPI0ERR()
#define Os_Disable_SRC_QSPI0PT() SRC_QSPI0PT.U = 0x1400U
#define Os_Disable_OsSRC_SPI0_PHASE_T_ISR() Os_Disable_SRC_QSPI0PT()
#define Os_Enable_SRC_QSPI0PT()  SRC_QSPI0PT.U = 0x141fU
#define Os_Enable_OsSRC_SPI0_PHASE_T_ISR()  Os_Enable_SRC_QSPI0PT()
#define Os_Disable_SRC_QSPI0U() SRC_QSPI0U.U = 0x1400U
#define Os_Disable_OsSRC_SPI0_USER_ISR() Os_Disable_SRC_QSPI0U()
#define Os_Enable_SRC_QSPI0U()  SRC_QSPI0U.U = 0x1420U
#define Os_Enable_OsSRC_SPI0_USER_ISR()  Os_Enable_SRC_QSPI0U()
#define Os_Disable_SRC_QSPI2ERR() SRC_QSPI2ERR.U = 0x1400U
#define Os_Disable_OsSRC_SPI2_ERR_ISR() Os_Disable_SRC_QSPI2ERR()
#define Os_Enable_SRC_QSPI2ERR()  SRC_QSPI2ERR.U = 0x1421U
#define Os_Enable_OsSRC_SPI2_ERR_ISR()  Os_Enable_SRC_QSPI2ERR()
#define Os_Disable_SRC_QSPI2PT() SRC_QSPI2PT.U = 0x1400U
#define Os_Disable_OsSRC_SPI2_PHASE_T_ISR() Os_Disable_SRC_QSPI2PT()
#define Os_Enable_SRC_QSPI2PT()  SRC_QSPI2PT.U = 0x1422U
#define Os_Enable_OsSRC_SPI2_PHASE_T_ISR()  Os_Enable_SRC_QSPI2PT()
#define Os_Disable_SRC_QSPI2U() SRC_QSPI2U.U = 0x1400U
#define Os_Disable_OsSRC_SPI2_USER_ISR() Os_Disable_SRC_QSPI2U()
#define Os_Enable_SRC_QSPI2U()  SRC_QSPI2U.U = 0x1423U
#define Os_Enable_OsSRC_SPI2_USER_ISR()  Os_Enable_SRC_QSPI2U()
#define Os_Disable_SRC_QSPI4ERR() SRC_QSPI4ERR.U = 0x1400U
#define Os_Disable_OsSRC_SPI4_ERR_ISR() Os_Disable_SRC_QSPI4ERR()
#define Os_Enable_SRC_QSPI4ERR()  SRC_QSPI4ERR.U = 0x1424U
#define Os_Enable_OsSRC_SPI4_ERR_ISR()  Os_Enable_SRC_QSPI4ERR()
#define Os_Disable_SRC_QSPI4PT() SRC_QSPI4PT.U = 0x1400U
#define Os_Disable_OsSRC_SPI4_PHASE_T_ISR() Os_Disable_SRC_QSPI4PT()
#define Os_Enable_SRC_QSPI4PT()  SRC_QSPI4PT.U = 0x1425U
#define Os_Enable_OsSRC_SPI4_PHASE_T_ISR()  Os_Enable_SRC_QSPI4PT()
#define Os_Disable_SRC_QSPI4U() SRC_QSPI4U.U = 0x1400U
#define Os_Disable_OsSRC_SPI4_USER_ISR() Os_Disable_SRC_QSPI4U()
#define Os_Enable_SRC_QSPI4U()  SRC_QSPI4U.U = 0x1426U
#define Os_Enable_OsSRC_SPI4_USER_ISR()  Os_Enable_SRC_QSPI4U()
#define Os_Disable_SRC_GPSR10() SRC_GPSR10.U = 0x1400U
#define Os_Disable_OsTSKSRV_ACTIVATION_MANAGER_IT() Os_Disable_SRC_GPSR10()
#define Os_Enable_SRC_GPSR10()  SRC_GPSR10.U = 0x1427U
#define Os_Enable_OsTSKSRV_ACTIVATION_MANAGER_IT()  Os_Enable_SRC_GPSR10()
#define Os_Disable_SRC_GTMATOM31() SRC_GTMATOM31.U = 0x1400U
#define Os_Disable_ANGSCHED_ANGULAR_ALARM_1() Os_Disable_SRC_GTMATOM31()
#define Os_Enable_SRC_GTMATOM31()  SRC_GTMATOM31.U = 0x1428U
#define Os_Enable_ANGSCHED_ANGULAR_ALARM_1()  Os_Enable_SRC_GTMATOM31()
#define Os_Disable_SRC_GTMTIM03() SRC_GTMTIM03.U = 0x1400U
#define Os_Disable_CAMHAL_ANGULAR_ALARM_EXHAUST() Os_Disable_SRC_GTMTIM03()
#define Os_Enable_SRC_GTMTIM03()  SRC_GTMTIM03.U = 0x1429U
#define Os_Enable_CAMHAL_ANGULAR_ALARM_EXHAUST()  Os_Enable_SRC_GTMTIM03()
#define Os_Disable_SRC_GTMTIM04() SRC_GTMTIM04.U = 0x1400U
#define Os_Disable_CAMHAL_ANGULAR_ALARM_INTAKE() Os_Disable_SRC_GTMTIM04()
#define Os_Enable_SRC_GTMTIM04()  SRC_GTMTIM04.U = 0x142aU
#define Os_Enable_CAMHAL_ANGULAR_ALARM_INTAKE()  Os_Enable_SRC_GTMTIM04()
#define Os_Disable_SRC_GTMATOM03() SRC_GTMATOM03.U = 0x1400U
#define Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG() Os_Disable_SRC_GTMATOM03()
#define Os_Enable_SRC_GTMATOM03()  SRC_GTMATOM03.U = 0x142bU
#define Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG()  Os_Enable_SRC_GTMATOM03()
#define Os_Disable_SRC_GTMATOM01() SRC_GTMATOM01.U = 0x1400U
#define Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG() Os_Disable_SRC_GTMATOM01()
#define Os_Enable_SRC_GTMATOM01()  SRC_GTMATOM01.U = 0x142cU
#define Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG()  Os_Enable_SRC_GTMATOM01()
#define Os_Disable_SRC_GTMATOM02() SRC_GTMATOM02.U = 0x1400U
#define Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_C_CMD() Os_Disable_SRC_GTMATOM02()
#define Os_Enable_SRC_GTMATOM02()  SRC_GTMATOM02.U = 0x142dU
#define Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_C_CMD()  Os_Enable_SRC_GTMATOM02()
#define Os_Disable_SRC_GTMATOM00() SRC_GTMATOM00.U = 0x1400U
#define Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_C_WDG() Os_Disable_SRC_GTMATOM00()
#define Os_Enable_SRC_GTMATOM00()  SRC_GTMATOM00.U = 0x142eU
#define Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_C_WDG()  Os_Enable_SRC_GTMATOM00()
#define Os_Disable_SRC_GTMATOM30() SRC_GTMATOM30.U = 0x1400U
#define Os_Disable_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH() Os_Disable_SRC_GTMATOM30()
#define Os_Enable_SRC_GTMATOM30()  SRC_GTMATOM30.U = 0x142fU
#define Os_Enable_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH()  Os_Enable_SRC_GTMATOM30()
#define Os_Disable_SRC_GTMATOM11() SRC_GTMATOM11.U = 0x1400U
#define Os_Disable_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP() Os_Disable_SRC_GTMATOM11()
#define Os_Enable_SRC_GTMATOM11()  SRC_GTMATOM11.U = 0x1430U
#define Os_Enable_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP()  Os_Enable_SRC_GTMATOM11()
#define Os_Disable_SRC_GTMATOM12() SRC_GTMATOM12.U = 0x1400U
#define Os_Disable_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3() Os_Disable_SRC_GTMATOM12()
#define Os_Enable_SRC_GTMATOM12()  SRC_GTMATOM12.U = 0x1431U
#define Os_Enable_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3()  Os_Enable_SRC_GTMATOM12()
#define Os_Disable_SRC_GTMATOM22() SRC_GTMATOM22.U = 0x1400U
#define Os_Disable_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN() Os_Disable_SRC_GTMATOM22()
#define Os_Enable_SRC_GTMATOM22()  SRC_GTMATOM22.U = 0x1432U
#define Os_Enable_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN()  Os_Enable_SRC_GTMATOM22()
#define Os_Disable_SRC_GTMATOM13() SRC_GTMATOM13.U = 0x1400U
#define Os_Disable_PMPHAL_DELAY() Os_Disable_SRC_GTMATOM13()
#define Os_Enable_SRC_GTMATOM13()  SRC_GTMATOM13.U = 0x1433U
#define Os_Enable_PMPHAL_DELAY()  Os_Enable_SRC_GTMATOM13()
#define Os_Disable_SRC_GTMATOM32() SRC_GTMATOM32.U = 0x1400U
#define Os_Disable_PTMHAL_ANGULAR_ALARM_SPILL_EVENT() Os_Disable_SRC_GTMATOM32()
#define Os_Enable_SRC_GTMATOM32()  SRC_GTMATOM32.U = 0x1434U
#define Os_Enable_PTMHAL_ANGULAR_ALARM_SPILL_EVENT()  Os_Enable_SRC_GTMATOM32()
#define Os_Disable_SRC_GTMATOM23() SRC_GTMATOM23.U = 0x1400U
#define Os_Disable_TDCHAL_ANGULAR_ALARM_TDC() Os_Disable_SRC_GTMATOM23()
#define Os_Enable_SRC_GTMATOM23()  SRC_GTMATOM23.U = 0x1435U
#define Os_Enable_TDCHAL_ANGULAR_ALARM_TDC()  Os_Enable_SRC_GTMATOM23()
#define Os_Disable_SRC_GTMTOM03() SRC_GTMTOM03.U = 0x1400U
#define Os_Disable_L9781_DELAY() Os_Disable_SRC_GTMTOM03()
#define Os_Enable_SRC_GTMTOM03()  SRC_GTMTOM03.U = 0x1436U
#define Os_Enable_L9781_DELAY()  Os_Enable_SRC_GTMTOM03()
#define Os_Disable_SRC_GTMDPLL13() SRC_GTMDPLL13.U = 0x1400U
#define Os_Disable_CRKHAL_DPLL_GET_LOCK() Os_Disable_SRC_GTMDPLL13()
#define Os_Enable_SRC_GTMDPLL13()  SRC_GTMDPLL13.U = 0x1437U
#define Os_Enable_CRKHAL_DPLL_GET_LOCK()  Os_Enable_SRC_GTMDPLL13()
#define Os_Disable_SRC_GTMDPLL23() SRC_GTMDPLL23.U = 0x1400U
#define Os_Disable_CRKHAL_CRK_ON_MANAGEMENT() Os_Disable_SRC_GTMDPLL23()
#define Os_Enable_SRC_GTMDPLL23()  SRC_GTMDPLL23.U = 0x1438U
#define Os_Enable_CRKHAL_CRK_ON_MANAGEMENT()  Os_Enable_SRC_GTMDPLL23()
#define Os_Disable_SRC_GTMDPLL14() SRC_GTMDPLL14.U = 0x1400U
#define Os_Disable_CRKHAL_DPLL_LOST_LOCK() Os_Disable_SRC_GTMDPLL14()
#define Os_Enable_SRC_GTMDPLL14()  SRC_GTMDPLL14.U = 0x1439U
#define Os_Enable_CRKHAL_DPLL_LOST_LOCK()  Os_Enable_SRC_GTMDPLL14()
#define Os_Disable_SRC_GTMMCS00() SRC_GTMMCS00.U = 0x1400U
#define Os_Disable_CRKHAL_TOOTH_TASK_MANAGEMENT() Os_Disable_SRC_GTMMCS00()
#define Os_Enable_SRC_GTMMCS00()  SRC_GTMMCS00.U = 0x143aU
#define Os_Enable_CRKHAL_TOOTH_TASK_MANAGEMENT()  Os_Enable_SRC_GTMMCS00()
#define Os_Disable_SRC_GTMTIM01() SRC_GTMTIM01.U = 0x1400U
#define Os_Disable_CRKHAL_TIM_CRK_INPUT_TO_MCS() Os_Disable_SRC_GTMTIM01()
#define Os_Enable_SRC_GTMTIM01()  SRC_GTMTIM01.U = 0x143bU
#define Os_Enable_CRKHAL_TIM_CRK_INPUT_TO_MCS()  Os_Enable_SRC_GTMTIM01()
#define Os_Disable_SRC_GTMDPLL0() SRC_GTMDPLL0.U = 0x1400U
#define Os_Disable_CRKHAL_DPLL_CHANGE_DIRECTION() Os_Disable_SRC_GTMDPLL0()
#define Os_Enable_SRC_GTMDPLL0()  SRC_GTMDPLL0.U = 0x143cU
#define Os_Enable_CRKHAL_DPLL_CHANGE_DIRECTION()  Os_Enable_SRC_GTMDPLL0()
#define Os_Disable_SRC_GTMDPLL7() SRC_GTMDPLL7.U = 0x1400U
#define Os_Disable_CRKHAL_DPLL_LONG_TOOTH() Os_Disable_SRC_GTMDPLL7()
#define Os_Enable_SRC_GTMDPLL7()  SRC_GTMDPLL7.U = 0x143dU
#define Os_Enable_CRKHAL_DPLL_LONG_TOOTH()  Os_Enable_SRC_GTMDPLL7()
#define Os_Disable_SRC_GTMDPLL18() SRC_GTMDPLL18.U = 0x1400U
#define Os_Disable_CRKHAL_START_OF_SYNC_WIN() Os_Disable_SRC_GTMDPLL18()
#define Os_Enable_SRC_GTMDPLL18()  SRC_GTMDPLL18.U = 0x143eU
#define Os_Enable_CRKHAL_START_OF_SYNC_WIN()  Os_Enable_SRC_GTMDPLL18()
#define Os_Disable_SRC_GTMDPLL19() SRC_GTMDPLL19.U = 0x1400U
#define Os_Disable_CRKHAL_SYNC_SEARCH_AND_CTRL() Os_Disable_SRC_GTMDPLL19()
#define Os_Enable_SRC_GTMDPLL19()  SRC_GTMDPLL19.U = 0x143fU
#define Os_Enable_CRKHAL_SYNC_SEARCH_AND_CTRL()  Os_Enable_SRC_GTMDPLL19()
#define Os_Disable_SRC_GTMDPLL20() SRC_GTMDPLL20.U = 0x1400U
#define Os_Disable_CRKHAL_UPDATE_INT_ANGULAR_OFFSET() Os_Disable_SRC_GTMDPLL20()
#define Os_Enable_SRC_GTMDPLL20()  SRC_GTMDPLL20.U = 0x1440U
#define Os_Enable_CRKHAL_UPDATE_INT_ANGULAR_OFFSET()  Os_Enable_SRC_GTMDPLL20()
#define Os_Disable_SRC_GTMTIM00() SRC_GTMTIM00.U = 0x1400U
#define Os_Disable_CRKHAL_TIM_CRK_INPUT_TO_DPLL() Os_Disable_SRC_GTMTIM00()
#define Os_Enable_SRC_GTMTIM00()  SRC_GTMTIM00.U = 0x1441U
#define Os_Enable_CRKHAL_TIM_CRK_INPUT_TO_DPLL()  Os_Enable_SRC_GTMTIM00()

/* These macros can be used to disable and enable in one call, all of the
 * configured individual interrupts that are defined as Os_Disable_x and
 * Os_Enable_x above
 * [$TargetHT 170] [$TargetHT 171]
*/
#define Os_DisableAllConfiguredInterrupts() Os_Disable_OsKRN_SCHEDULER_MANAGE_IT();\
  Os_Disable_OsCJ135_U2450_ICU_IRQ_ISR();\
  Os_Disable_OsCJ135_U2450_GPT_IRQ_ISR();\
  Os_Disable_OsSRC_ASCLIN_ASCLIN1_ERR_ISR();\
  Os_Disable_OsSRC_ASCLIN_ASCLIN1_RX_ISR();\
  Os_Disable_OsSRC_ASCLIN_ASCLIN1_TX_ISR();\
  Os_Disable_OsCAN_0_BUS_OFF();\
  Os_Disable_OsCAN_0_RECEIVE();\
  Os_Disable_OsCAN_0_TRANSMIT();\
  Os_Disable_OsCAN_1_BUS_OFF();\
  Os_Disable_OsCAN_1_RECEIVE();\
  Os_Disable_OsCAN_1_TRANSMIT();\
  Os_Disable_OsCAN_2_BUS_OFF();\
  Os_Disable_OsCAN_2_RECEIVE();\
  Os_Disable_OsCAN_2_TRANSMIT();\
  Os_Disable_OsCAN_3_BUS_OFF();\
  Os_Disable_OsCAN_3_RECEIVE();\
  Os_Disable_OsCAN_3_TRANSMIT();\
  Os_Disable_OsDMA_ISR_MSC0RX();\
  Os_Disable_OsTHRHAL_PAP_PLUS_IT();\
  Os_Disable_OsTLE8718_CMD_RX_TIMEOUT_IT();\
  Os_Disable_OsTLE8718_CMD_TX_IT();\
  Os_Disable_OsDMA_ISR_QSPI0RX();\
  Os_Disable_OsDMA_ISR_QSPI2RX();\
  Os_Disable_OsDMA_ISR_QSPI4RX();\
  Os_Disable_OsDMA_ISR_QSPI0TX();\
  Os_Disable_OsDMA_ISR_QSPI2TX();\
  Os_Disable_OsDMA_ISR_QSPI4TX();\
  Os_Disable_OsSRC_SPI0_ERR_ISR();\
  Os_Disable_OsSRC_SPI0_PHASE_T_ISR();\
  Os_Disable_OsSRC_SPI0_USER_ISR();\
  Os_Disable_OsSRC_SPI2_ERR_ISR();\
  Os_Disable_OsSRC_SPI2_PHASE_T_ISR();\
  Os_Disable_OsSRC_SPI2_USER_ISR();\
  Os_Disable_OsSRC_SPI4_ERR_ISR();\
  Os_Disable_OsSRC_SPI4_PHASE_T_ISR();\
  Os_Disable_OsSRC_SPI4_USER_ISR();\
  Os_Disable_OsTSKSRV_ACTIVATION_MANAGER_IT();\
  Os_Disable_ANGSCHED_ANGULAR_ALARM_1();\
  Os_Disable_CAMHAL_ANGULAR_ALARM_EXHAUST();\
  Os_Disable_CAMHAL_ANGULAR_ALARM_INTAKE();\
  Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG();\
  Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG();\
  Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_C_CMD();\
  Os_Disable_IGNHAL_ANGULAR_ALARM_COIL_C_WDG();\
  Os_Disable_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH();\
  Os_Disable_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP();\
  Os_Disable_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3();\
  Os_Disable_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN();\
  Os_Disable_PMPHAL_DELAY();\
  Os_Disable_PTMHAL_ANGULAR_ALARM_SPILL_EVENT();\
  Os_Disable_TDCHAL_ANGULAR_ALARM_TDC();\
  Os_Disable_L9781_DELAY();\
  Os_Disable_CRKHAL_DPLL_GET_LOCK();\
  Os_Disable_CRKHAL_CRK_ON_MANAGEMENT();\
  Os_Disable_CRKHAL_DPLL_LOST_LOCK();\
  Os_Disable_CRKHAL_TOOTH_TASK_MANAGEMENT();\
  Os_Disable_CRKHAL_TIM_CRK_INPUT_TO_MCS();\
  Os_Disable_CRKHAL_DPLL_CHANGE_DIRECTION();\
  Os_Disable_CRKHAL_DPLL_LONG_TOOTH();\
  Os_Disable_CRKHAL_START_OF_SYNC_WIN();\
  Os_Disable_CRKHAL_SYNC_SEARCH_AND_CTRL();\
  Os_Disable_CRKHAL_UPDATE_INT_ANGULAR_OFFSET();\
  Os_Disable_CRKHAL_TIM_CRK_INPUT_TO_DPLL()
#define Os_EnableAllConfiguredInterrupts() Os_Enable_OsKRN_SCHEDULER_MANAGE_IT();\
  Os_Enable_OsCJ135_U2450_ICU_IRQ_ISR();\
  Os_Enable_OsCJ135_U2450_GPT_IRQ_ISR();\
  Os_Enable_OsSRC_ASCLIN_ASCLIN1_ERR_ISR();\
  Os_Enable_OsSRC_ASCLIN_ASCLIN1_RX_ISR();\
  Os_Enable_OsSRC_ASCLIN_ASCLIN1_TX_ISR();\
  Os_Enable_OsCAN_0_BUS_OFF();\
  Os_Enable_OsCAN_0_RECEIVE();\
  Os_Enable_OsCAN_0_TRANSMIT();\
  Os_Enable_OsCAN_1_BUS_OFF();\
  Os_Enable_OsCAN_1_RECEIVE();\
  Os_Enable_OsCAN_1_TRANSMIT();\
  Os_Enable_OsCAN_2_BUS_OFF();\
  Os_Enable_OsCAN_2_RECEIVE();\
  Os_Enable_OsCAN_2_TRANSMIT();\
  Os_Enable_OsCAN_3_BUS_OFF();\
  Os_Enable_OsCAN_3_RECEIVE();\
  Os_Enable_OsCAN_3_TRANSMIT();\
  Os_Enable_OsDMA_ISR_MSC0RX();\
  Os_Enable_OsTHRHAL_PAP_PLUS_IT();\
  Os_Enable_OsTLE8718_CMD_RX_TIMEOUT_IT();\
  Os_Enable_OsTLE8718_CMD_TX_IT();\
  Os_Enable_OsDMA_ISR_QSPI0RX();\
  Os_Enable_OsDMA_ISR_QSPI2RX();\
  Os_Enable_OsDMA_ISR_QSPI4RX();\
  Os_Enable_OsDMA_ISR_QSPI0TX();\
  Os_Enable_OsDMA_ISR_QSPI2TX();\
  Os_Enable_OsDMA_ISR_QSPI4TX();\
  Os_Enable_OsSRC_SPI0_ERR_ISR();\
  Os_Enable_OsSRC_SPI0_PHASE_T_ISR();\
  Os_Enable_OsSRC_SPI0_USER_ISR();\
  Os_Enable_OsSRC_SPI2_ERR_ISR();\
  Os_Enable_OsSRC_SPI2_PHASE_T_ISR();\
  Os_Enable_OsSRC_SPI2_USER_ISR();\
  Os_Enable_OsSRC_SPI4_ERR_ISR();\
  Os_Enable_OsSRC_SPI4_PHASE_T_ISR();\
  Os_Enable_OsSRC_SPI4_USER_ISR();\
  Os_Enable_OsTSKSRV_ACTIVATION_MANAGER_IT();\
  Os_Enable_ANGSCHED_ANGULAR_ALARM_1();\
  Os_Enable_CAMHAL_ANGULAR_ALARM_EXHAUST();\
  Os_Enable_CAMHAL_ANGULAR_ALARM_INTAKE();\
  Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_A_CMD_AND_B_WDG();\
  Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_B_CMD_AND_A_WDG();\
  Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_C_CMD();\
  Os_Enable_IGNHAL_ANGULAR_ALARM_COIL_C_WDG();\
  Os_Enable_IGNHAL_ANGULAR_ALARM_IGN_REF_TEETH();\
  Os_Enable_INJHAL_ANGULAR_ALARM_INJ_1_HP_PMP();\
  Os_Enable_INJHAL_ANGULAR_ALARM_INJ_2_AND_INJ3();\
  Os_Enable_KNWHAL_ANGULAR_ALARM_KNW_SAMPLING_WIN();\
  Os_Enable_PMPHAL_DELAY();\
  Os_Enable_PTMHAL_ANGULAR_ALARM_SPILL_EVENT();\
  Os_Enable_TDCHAL_ANGULAR_ALARM_TDC();\
  Os_Enable_L9781_DELAY();\
  Os_Enable_CRKHAL_DPLL_GET_LOCK();\
  Os_Enable_CRKHAL_CRK_ON_MANAGEMENT();\
  Os_Enable_CRKHAL_DPLL_LOST_LOCK();\
  Os_Enable_CRKHAL_TOOTH_TASK_MANAGEMENT();\
  Os_Enable_CRKHAL_TIM_CRK_INPUT_TO_MCS();\
  Os_Enable_CRKHAL_DPLL_CHANGE_DIRECTION();\
  Os_Enable_CRKHAL_DPLL_LONG_TOOTH();\
  Os_Enable_CRKHAL_START_OF_SYNC_WIN();\
  Os_Enable_CRKHAL_SYNC_SEARCH_AND_CTRL();\
  Os_Enable_CRKHAL_UPDATE_INT_ANGULAR_OFFSET();\
  Os_Enable_CRKHAL_TIM_CRK_INPUT_TO_DPLL()
#endif /* OS_DISABLEINTERRUPTS_H */
