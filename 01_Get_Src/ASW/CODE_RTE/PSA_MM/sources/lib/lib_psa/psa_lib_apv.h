/**************************************************************************************************\
 * 
 *                              P. C. A.
 * 
 *                       Peugeot Citroen Automobile
 * 
 *           This file is the property of PCA. All rights are reserved
 *           by PCA and this file must not be copied or disclosed
 *          (in whole or in part) without prior written consent of PCA.
 * 
 ***********************************************************************************
 * 
 *    %name: psa_lib_apv.h %
 * 
 *    %version: 1.1 %
 * 
 *    %date_modified: Wed Nov 30 11:51:18 2011 %
 * 
 * 
 *    %derived_by: u351307 %
 *    %release: Pack_Integrateur/4.0 %
 *    %full_filespec: psa_lib_apv.h-1.1:incl:1 %
 * 
 ***********************************************************************************/
 
#ifndef PSA_LIB_APV_H
#define PSA_LIB_APV_H

// Upstream requirement 01552_09_00391-SSTG-C006(4) :
#ifdef CST_NOAFTERSALEREQUEST
    #undef CST_NOAFTERSALEREQUEST
#endif
#define CST_NOAFTERSALEREQUEST 0	//0: default, no action, also called [CST_NOAFTERSALEREQUEST]
#ifdef CST_READ
    #undef CST_READ
#endif
#define CST_READ 1					//1: when a read service is called, also called [CST_READ]
#ifdef CST_WRITE
    #undef CST_WRITE
#endif
#define CST_WRITE 2					//2: when a writing service is called, also called [CST_WRITE]
#ifdef CST_WRITE_OK
    #undef CST_WRITE_OK
#endif
#define CST_WRITE_OK 3				//3: when a writing service is done, also called [CST_WRITE_OK]
#ifdef CST_RESET
    #undef CST_RESET
#endif
#define CST_RESET 4					//4: when a resetting service is called, also called [CST_RESET]
#ifdef CST_RESET_OK
    #undef CST_RESET_OK
#endif
#define CST_RESET_OK 5				//5: when a resetting service is done, also called [CST_RESET_OK]
#ifdef CST_RESET_NOK
    #undef CST_RESET_NOK
#endif
#define CST_RESET_NOK 6				//6: when a resetting service has troubles, also called [CST_RESET_NOK]
#ifdef CST_READWRITE_NOK
    #undef CST_READWRITE_NOK
#endif
#define CST_READWRITE_NOK 7			//7: when a read or writing service has troubles, also called [CST_READWRITE_NOK]

// Upstream requirement 01552_09_00391-SSTG-C094(2) :
#ifdef RTN_ST_NOT_STARTED
    #undef RTN_ST_NOT_STARTED
#endif
#define RTN_ST_NOT_STARTED	0
#ifdef RTN_ST_RUNNING
    #undef RTN_ST_RUNNING
#endif
#define RTN_ST_RUNNING		1
#ifdef RTN_ST_FINISHED_OK
    #undef RTN_ST_FINISHED_OK
#endif
#define RTN_ST_FINISHED_OK	2
#ifdef RTN_ST_FINISHED_NOK
    #undef RTN_ST_FINISHED_NOK
#endif
#define RTN_ST_FINISHED_NOK	3
#ifdef RTN_ST_RTN_STOPPED
    #undef RTN_ST_RTN_STOPPED
#endif
#define RTN_ST_RTN_STOPPED	4

// Upstream requirement 01552_09_00391-SSTG-C063(1) :
#ifndef E_OK
    #define E_OK 0
#endif

#ifndef E_NOT_OK
    #define E_NOT_OK 1
#endif

#ifndef E_SESSION_NOT_ALLOWED
    #define E_SESSION_NOT_ALLOWED 4
#endif

#ifndef E_PENDING
    #define E_PENDING 10
#endif

#ifndef E_FORCE_RCRRP
    #define E_FORCE_RCRRP 12
#endif

// Temporary definition before deinitive unuse of this message in SWC :
#ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
    #define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT 19
#endif


#endif
