/******************************************************************************/
/*                                                                            */
/* !Layer           : STD                                                     */
/*                                                                            */
/* !Component       : MEMMAP                                                  */
/* !Description     : MEMMAP Configuration                                    */
/*                                                                            */
/* !File            : CANSM_MEMMAP.H                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          :                                                         */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/******************************************************************************/
/* 11/10/14, 10:16:20: generated by Genecode  v2.6.0.0                        */
/* From Source Template : MSN_MEMMAP_H.TPL                                    */
/******************************************************************************/



/******************************************************************************/
/*          MEMMAP selected mode:  SAFE                                       */
/******************************************************************************/
#define MEMMAP_ERROR

/* The following if is used only due to automatic generation */
#if !defined MEMMAP_ERROR

/* Project section mappings */
/* !Comment: CANSM Section allocation */
#elif defined   CANSM_START_SEC_CODE
   #undef  CANSM_START_SEC_CODE
   #define START_SEC_CODE_SECTION
#elif defined   CANSM_STOP_SEC_CODE
   #undef  CANSM_STOP_SEC_CODE
   #define STOP_SEC_CODE_SECTION

#elif defined   CANSM_START_SEC_VAR_INIT_8
   #undef  CANSM_START_SEC_VAR_INIT_8
   #define START_SEC_VAR_INIT_8_SECTION
#elif defined   CANSM_STOP_SEC_VAR_INIT_8
   #undef  CANSM_STOP_SEC_VAR_INIT_8
   #define STOP_SEC_VAR_INIT_8_SECTION

#elif defined   CANSM_START_SEC_VAR_INIT_UNSPECIFIED
   #undef  CANSM_START_SEC_VAR_INIT_UNSPECIFIED
   #define START_SEC_VAR_INIT_UNSPECIFIED_SECTION
#elif defined   CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
   #undef  CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
   #define STOP_SEC_VAR_INIT_UNSPECIFIED_SECTION

#elif defined   CANSM_START_SEC_CONFIG_DATA_8
   #undef  CANSM_START_SEC_CONFIG_DATA_8
   #define START_SEC_CONFIG_DATA_8_SECTION
#elif defined   CANSM_STOP_SEC_CONFIG_DATA_8
   #undef  CANSM_STOP_SEC_CONFIG_DATA_8
   #define STOP_SEC_CONFIG_DATA_8_SECTION

#elif defined   CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #undef  CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #define START_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION
#elif defined   CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #undef  CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #define STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION

#elif defined   CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
   #undef  CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
   #define START_SEC_CONFIG_DATA_UNSPECIFIED_SECTION
#elif defined   CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #undef  CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #define STOP_SEC_CONFIG_DATA_UNSPECIFIED_SECTION


#endif

/* ECU specific section mappings */
#ifndef MEMMAP_START_DONE

/* The following if is used only due to automatic generation */

#if FALSE
/* !Comment: SEC_CODE Start Section treatment */
   #elif defined   START_SEC_CODE_SECTION
	  

      #pragma section ".text" ax

      #undef  MEMMAP_ERROR
      #define MEMMAP_START_DONE

/* !Comment: SEC_VAR_INIT_8 Start Section treatment */
   #elif defined   START_SEC_VAR_INIT_8_SECTION
	  

      #pragma section ".data" aw

      #undef  MEMMAP_ERROR
      #define MEMMAP_START_DONE

/* !Comment: SEC_VAR_INIT_UNSPECIFIED Start Section treatment */
   #elif defined   START_SEC_VAR_INIT_UNSPECIFIED_SECTION
	  

      #pragma section ".data" aw

      #undef  MEMMAP_ERROR
      #define MEMMAP_START_DONE

/* !Comment: SEC_CONFIG_DATA_8 Start Section treatment */
   #elif defined   START_SEC_CONFIG_DATA_8_SECTION
	  
      #undef  MEMMAP_ERROR
      #define MEMMAP_START_DONE

/* !Comment: SEC_VAR_NO_INIT_UNSPECIFIED Start Section treatment */
   #elif defined   START_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION
	  

      #pragma section ".power_on_cleared" aw

      #undef  MEMMAP_ERROR
      #define MEMMAP_START_DONE

/* !Comment: SEC_CONFIG_DATA_UNSPECIFIED Start Section treatment */
   #elif defined   START_SEC_CONFIG_DATA_UNSPECIFIED_SECTION
	  
      #undef  MEMMAP_ERROR
      #define MEMMAP_START_DONE


   #endif

#else   /* if MEMMAP_START_DONE is not defined */

/* The following if is used only due to automatic generation */

#if FALSE
/* !Comment: SEC_CODE Stop Section treatment */
   #elif defined   STOP_SEC_CODE_SECTION && defined  START_SEC_CODE_SECTION
	  

      #pragma section

      #undef START_SEC_CODE_SECTION
      #undef STOP_SEC_CODE_SECTION
      #undef MEMMAP_ERROR
      #undef MEMMAP_START_DONE

/* !Comment: SEC_VAR_INIT_8 Stop Section treatment */
   #elif defined   STOP_SEC_VAR_INIT_8_SECTION && defined  START_SEC_VAR_INIT_8_SECTION
	  

      #pragma section

      #undef START_SEC_VAR_INIT_8_SECTION
      #undef STOP_SEC_VAR_INIT_8_SECTION
      #undef MEMMAP_ERROR
      #undef MEMMAP_START_DONE

/* !Comment: SEC_VAR_INIT_UNSPECIFIED Stop Section treatment */
   #elif defined   STOP_SEC_VAR_INIT_UNSPECIFIED_SECTION && defined  START_SEC_VAR_INIT_UNSPECIFIED_SECTION
	  

      #pragma section

      #undef START_SEC_VAR_INIT_UNSPECIFIED_SECTION
      #undef STOP_SEC_VAR_INIT_UNSPECIFIED_SECTION
      #undef MEMMAP_ERROR
      #undef MEMMAP_START_DONE

/* !Comment: SEC_CONFIG_DATA_8 Stop Section treatment */
   #elif defined   STOP_SEC_CONFIG_DATA_8_SECTION && defined  START_SEC_CONFIG_DATA_8_SECTION
	  
      #undef START_SEC_CONFIG_DATA_8_SECTION
      #undef STOP_SEC_CONFIG_DATA_8_SECTION
      #undef MEMMAP_ERROR
      #undef MEMMAP_START_DONE

/* !Comment: SEC_VAR_NO_INIT_UNSPECIFIED Stop Section treatment */
   #elif defined   STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION && defined  START_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION
	  

      #pragma section

      #undef START_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION
      #undef STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SECTION
      #undef MEMMAP_ERROR
      #undef MEMMAP_START_DONE

/* !Comment: SEC_CONFIG_DATA_UNSPECIFIED Stop Section treatment */
   #elif defined   STOP_SEC_CONFIG_DATA_UNSPECIFIED_SECTION && defined  START_SEC_CONFIG_DATA_UNSPECIFIED_SECTION
	  
      #undef START_SEC_CONFIG_DATA_UNSPECIFIED_SECTION
      #undef STOP_SEC_CONFIG_DATA_UNSPECIFIED_SECTION
      #undef MEMMAP_ERROR
      #undef MEMMAP_START_DONE


   #endif
#endif

#if defined MEMMAP_ERROR
   #error MEMMAP-E201 : Bad memory allocation into CANSM_MemMap.h
#endif


/*------------------------------- end of file --------------------------------*/
