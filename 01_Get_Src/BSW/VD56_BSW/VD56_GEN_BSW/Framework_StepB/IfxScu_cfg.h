/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSCU_CFG.h                                            */
/* !Description     : Confoguration of framework component managing SCU       */
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
 * %PID: P2017_BSW:0A111810.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSCU_CFG_H
#define IFXSCU_CFG_H
/******************************************************************************/
#include "Ifx_Cfg.h"
#include "IfxScu_bf.h"


/******************************************************************************/
/*                           Macro                                            */
/******************************************************************************/
#ifndef IFX_CFG_SCU_XTAL_FREQUENCY
#    define IFX_CFG_SCU_XTAL_FREQUENCY    (20000000.0)  /* External oscillator frequency */
#endif

#define IFXSCU_VCO_BASE_FREQUENCY (100000000.0) /* FIXME to be checked */
#define IFXSCU_EVR_OSC_FREQUENCY (100000000.0)  /* FIXME to be checked */

/*The following frequency is the PLL free running frequency */
/* FIXME is this not redundant to IFXSCU_VCO_BASE_FREQUENCY */
#define IFXSCU_PLL_FREERUNNING_FREQUENCY  (100000000.0)


/******************************************************************************/
/** \brief Macros to configure Pll steps,
 * Macros to configure the Pll steps for different profiles of Crystal frequency and
 * target frequencies. This configuration is important for the current jump controll
 * during clock throttling.
 * \ref IfxScu_PllStepsConfig
 */

/******************** Pll step for 16MHz crystal Configurations ********************************/
#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_80MHZ
/** \brief Macro for Pll step for profile with 16MHz Crystal and 80MHz target */
#define IFXSCU_CFG_PLL_STEPS_16MHZ_80MHZ 															\
{																									\
	{ /*Step 0 Config: 80MHz*/																		\
		(8 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_133MHZ
 /** \brief Macro for Pll step for profile with 16MHz Crystal and 133MHz target */
#define IFXSCU_CFG_PLL_STEPS_16MHZ_133MHZ 															\
{																									\
	{ /*Step 0 Config: 114MHz*/																		\
		(7 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 1 Config: 133MHz*/																		\
		(6 - 1),					/*uint8 k2Step;*/									    	\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_160MHZ
/** \brief Macro for Pll step for profile with 16MHz Crystal and 160MHz target */
#define IFXSCU_CFG_PLL_STEPS_16MHZ_160MHZ 															\
{																									\
	{ /*Step 1 Config: 128MHz*/																		\
		(5 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 2 Config: 160MHz*/																		\
		(4 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	}																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_160MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_200MHZ
 /** \brief Macro for Pll step for profile with 16MHz Crystal and 200MHz target */
#define IFXSCU_CFG_PLL_STEPS_16MHZ_200MHZ 															\
{																									\
	{ /*Step 0 Config: 120MHz*/																		\
		(6 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 1 Config: 150MHz*/																		\
		(5 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 2 Config: 200MHz*/																		\
		(4 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	}																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_200MHZ */

/******************** Pll step 20MHz crystal Configurations ********************************/
#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_80MHZ
/** \brief Macro for Pll step for profile with 20MHz Crystal and 80MHz target */
#define IFXSCU_CFG_PLL_STEPS_20MHZ_80MHZ 															\
{																									\
	{ /*Step 0 Config: 80MHz*/																		\
		(8 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_133MHZ
/** \brief Macro for Pll step for profile with 20MHz Crystal and 133MHz target */
#define IFXSCU_CFG_PLL_STEPS_20MHZ_133MHZ 															\
{																									\
	{ /*Step 0 Config: 114MHz*/																		\
		(7 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 1 Config: 133MHz*/																		\
		(6 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_160MHZ
/** \brief Macro for Pll step for profile with 20MHz Crystal and 160MHz target */
#define IFXSCU_CFG_PLL_STEPS_20MHZ_160MHZ 															\
{																									\
	{ /*Step 1 Config: 128MHz*/																		\
		(5 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 2 Config: 160MHz*/																		\
		(4 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	}																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_160MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_200MHZ
/** \brief Macro for Pll step for profile with 20MHz Crystal and 200MHz target */
#define IFXSCU_CFG_PLL_STEPS_20MHZ_200MHZ 															\
{																									\
	{ /*Step 0 Config: 120MHz*/																		\
		(5 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 1 Config: 150MHz*/																		\
		(4 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	},																								\
	{ /*Step 2 Config: 200MHz*/																		\
		(3 - 1),							/*uint8 k2Step;*/										\
		0.000100,							/*float32 waitTime;*/									\
		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
	}																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_200MHZ */

/******************** Pll step for 40MHz crystal Configurations ********************************/
#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_80MHZ
/** \brief Macro for Pll step for profile with 40MHz Crystal and 80MHz target */
#define IFXSCU_CFG_PLL_STEPS_40MHZ_80MHZ 															\
{																									\
	{ /*Step 0 Config: 80MHz*/																		\
 		(8 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	},																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_133MHZ
/** \brief Macro for Pll step for profile with 40MHz Crystal and 133MHz target */
#define IFXSCU_CFG_PLL_STEPS_40MHZ_133MHZ 															\
{																									\
	{ /*Step 0 Config: 114MHz*/																		\
 		(7 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	},																								\
 	{ /*Step 1 Config: 133MHz*/																		\
 		(6 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	},																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_160MHZ
 /** \brief Macro for Pll step for profile with 40MHz Crystal and 160MHz target */
#define IFXSCU_CFG_PLL_STEPS_40MHZ_160MHZ 															\
{																									\
	{ /*Step 1 Config: 128MHz*/																		\
 		(5 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	},																								\
 	{ /*Step 2 Config: 160MHz*/																		\
 		(4 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	}																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_160MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_200MHZ
 /** \brief Macro for Pll step for profile with 40MHz Crystal and 200MHz target */
#define IFXSCU_CFG_PLL_STEPS_40MHZ_200MHZ 															\
{																									\
 	{ /*Step 0 Config: 120MHz*/																		\
 		(5 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	},																								\
 	{ /*Step 1 Config: 150MHz*/																		\
 		(4 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	},																								\
 	{ /*Step 2 Config: 200MHz*/																		\
 		(3 - 1),							/*uint8 k2Step;*/										\
 		0.000100,							/*float32 waitTime;*/									\
 		0									/*IfxScu_PllStepsFunctionHook hookFunction;*/			\
 	}																								\
}
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_200MHZ */

/** \brief Macros to configure Initial Pll step.
 *  Macros to configure the Pll initial step, where the configuration of PDIV, NDIV and K2DIV are
 *  done for the internal Oscillator frequency.
 *  \ref IfxScu_InitialStepConfig
 */

/****************** Initial Pll step for 16MHz crystal Configurations ******************************/

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_80MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 80MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_80MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 1	- 1),			(40 - 1),			( 7	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_133MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 133MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_133MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 1	- 1),			(50 - 1),			( 8	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_160MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 160MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_160MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 1	- 1),			(40 - 1),			( 6	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_160MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 200MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_200MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 1 - 1),			(50	- 1),			( 8	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_16MHZ_200MHZ */

/****************** Initial Pll step for 20MHz crystal Configurations ******************************/

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_80MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 80MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_80MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 2	- 1),			(64 - 1),			( 7	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_133MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 133MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_133MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 2	- 1),			(80 - 1),			( 8	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_160MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 160MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_160MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 2	- 1),			(64 - 1),			( 6	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_160MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 200MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_200MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 2 - 1),			(60	- 1),			( 6	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_20MHZ_200MHZ */


/****************** Initial Pll step for 40MHz crystal Configurations ******************************/

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_80MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 80MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_80MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 4	- 1),			(64 - 1),			( 7	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_133MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 133MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_133MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 4	- 1),			(80 - 1),			( 8	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_160MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 160MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_160MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 4	- 1),			(64 - 1),			( 6	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_160MHZ */

#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 200MHz target */
#define IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_200MHZ  													\
/*{		uint8 pDivider, 	uint8 nDivider, 	uint8 k2Initial,	float32 waitTime	}*/			\
{		( 4 - 1),			(60	- 1),			( 6	- 1),			0.000200F			}
#endif /*#ifndef IFXSCU_CFG_PLL_INITIAL_STEP_40MHZ_200MHZ */


/** \brief Macros to configure CCUCON registers.
 *  Macros to configure the Pll initial step, where the configuration of PDIV, NDIV and K2DIV are
 *  done for the internal Oscillator frequency.
 *  \ref IfxScu_InitialStepConfig
 */

/** \brief Macros to configure CCUCON registers */


#ifndef IFXSCU_CFG_MAXDIV_80MHZ
/** brief Macro to configure MAXDIV at 80MHz target frequency */
#define IFXSCU_CFG_MAXDIV_80MHZ		(1)
#endif /*#ifndef IFXSCU_CFG_MAXDIV_80MHZ */

#ifndef IFXSCU_CFG_MAXDIV_133MHZ
/** brief Macro to configure MAXDIV at 133MHz target frequency */
#define IFXSCU_CFG_MAXDIV_133MHZ	(1)
#endif /*#ifndef IFXSCU_CFG_MAXDIV_133MHZ */

#ifndef IFXSCU_CFG_MAXDIV_160MHZ
/** brief Macro to configure MAXDIV at 160MHz target frequency */
#define IFXSCU_CFG_MAXDIV_160MHZ	(1)
#endif /*#ifndef IFXSCU_CFG_MAXDIV_160MHZ */

#ifndef IFXSCU_CFG_MAXDIV_200MHZ
/** brief Macro to configure MAXDIV at 200MHz target frequency */
#define IFXSCU_CFG_MAXDIV_200MHZ	(1)
#endif /*#ifndef IFXSCU_CFG_MAXDIV_200MHZ */



#ifndef IFXSCU_CFG_SRIDIV_80MHZ
/** brief Macro to configure SRIDIV at 80MHz target frequency */
#define IFXSCU_CFG_SRIDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_SRIDIV_80MHZ */

#ifndef IFXSCU_CFG_SRIDIV_133MHZ
/** brief Macro to configure SRIDIV at 133MHz target frequency */
#define IFXSCU_CFG_SRIDIV_133MHZ	(IFXSCU_CFG_MAXDIV_133MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_SRIDIV_133MHZ */

#ifndef IFXSCU_CFG_SRIDIV_160MHZ
/** brief Macro to configure SRIDIV at 160MHz target frequency */
#define IFXSCU_CFG_SRIDIV_160MHZ	(IFXSCU_CFG_MAXDIV_160MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_SRIDIV_160MHZ */

#ifndef IFXSCU_CFG_SRIDIV_200MHZ
/** brief Macro to configure SRIDIV at 200MHz target frequency */
#define IFXSCU_CFG_SRIDIV_200MHZ	(IFXSCU_CFG_MAXDIV_200MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_SRIDIV_200MHZ */



#ifndef IFXSCU_CFG_BAUD1DIV_80MHZ
/** brief Macro to configure BAUD1DIV at 80MHz target frequency */
#define IFXSCU_CFG_BAUD1DIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_BAUD1DIV_80MHZ */

#ifndef IFXSCU_CFG_BAUD1DIV_133MHZ
/** brief Macro to configure BAUD1DIV at 133MHz target frequency */
#define IFXSCU_CFG_BAUD1DIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_BAUD1DIV_133MHZ */

#ifndef IFXSCU_CFG_BAUD1DIV_160MHZ
/** brief Macro to configure BAUD1DIV at 160MHz target frequency */
#define IFXSCU_CFG_BAUD1DIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_BAUD1DIV_160MHZ */

#ifndef IFXSCU_CFG_BAUD1DIV_200MHZ
/** brief Macro to configure BAUD1DIV at 200MHz target frequency */
#define IFXSCU_CFG_BAUD1DIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_BAUD1DIV_200MHZ */



#ifndef IFXSCU_CFG_BAUD2DIV_80MHZ
/** brief Macro to configure BAUD2DIV at 80MHz target frequency */
#define IFXSCU_CFG_BAUD2DIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_BAUD2DIV_80MHZ */

#ifndef IFXSCU_CFG_BAUD2DIV_133MHZ
/** brief Macro to configure BAUD2DIV at 133MHz target frequency */
#define IFXSCU_CFG_BAUD2DIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_BAUD2DIV_133MHZ */

#ifndef IFXSCU_CFG_BAUD2DIV_160MHZ
/** brief Macro to configure BAUD2DIV at 160MHz target frequency */
#define IFXSCU_CFG_BAUD2DIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_BAUD2DIV_160MHZ */

#ifndef IFXSCU_CFG_BAUD2DIV_200MHZ
/** brief Macro to configure BAUD2DIV at 200MHz target frequency */
#define IFXSCU_CFG_BAUD2DIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_BAUD2DIV_200MHZ */



#ifndef IFXSCU_CFG_SPBDIV_80MHZ
/** brief Macro to configure SPBDIV at 80MHz target frequency */
#define IFXSCU_CFG_SPBDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_SPBDIV_80MHZ */

#ifndef IFXSCU_CFG_SPBDIV_133MHZ
/** brief Macro to configure SPBDIV at 133MHz target frequency */
#define IFXSCU_CFG_SPBDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_SPBDIV_133MHZ */

#ifndef IFXSCU_CFG_SPBDIV_160MHZ
/** brief Macro to configure SPBDIV at 160MHz target frequency */
#define IFXSCU_CFG_SPBDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_SPBDIV_160MHZ */

#ifndef IFXSCU_CFG_SPBDIV_200MHZ
/** brief Macro to configure SPBDIV at 200MHz target frequency */
#define IFXSCU_CFG_SPBDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_SPBDIV_200MHZ */



#ifndef IFXSCU_CFG_FSI2DIV_80MHZ
/** brief Macro to configure FSI2DIV at 80MHz target frequency */
#define IFXSCU_CFG_FSI2DIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_80MHZ */

#ifndef IFXSCU_CFG_FSI2DIV_133MHZ
/** brief Macro to configure FSI2DIV at 133MHz target frequency */
#define IFXSCU_CFG_FSI2DIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_133MHZ */

#ifndef IFXSCU_CFG_FSI2DIV_160MHZ
/** brief Macro to configure FSI2DIV at 160MHz target frequency */
#define IFXSCU_CFG_FSI2DIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_160MHZ */

#ifndef IFXSCU_CFG_FSI2DIV_200MHZ
/** brief Macro to configure FSI2DIV at 200MHz target frequency */
#define IFXSCU_CFG_FSI2DIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_200MHZ */



#ifndef IFXSCU_CFG_FSIDIV_80MHZ
/** brief Macro to configure FSIDIV at 80MHz target frequency */
#define IFXSCU_CFG_FSIDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_FSIDIV_80MHZ */

#ifndef IFXSCU_CFG_FSIDIV_133MHZ
/** brief Macro to configure FSIDIV at 133MHz target frequency */
#define IFXSCU_CFG_FSIDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_FSIDIV_133MHZ */

#ifndef IFXSCU_CFG_FSIDIV_160MHZ
/** brief Macro to configure FSIDIV at 160MHz target frequency */
#define IFXSCU_CFG_FSIDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_FSIDIV_160MHZ */

#ifndef IFXSCU_CFG_FSIDIV_200MHZ
/** brief Macro to configure FSIDIV at 200MHz target frequency */
#define IFXSCU_CFG_FSIDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_FSIDIV_200MHZ */



#ifndef IFXSCU_CFG_CANDIV_80MHZ
/** brief Macro to configure CANDIV at 80MHz target frequency */
#define IFXSCU_CFG_CANDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_CANDIV_80MHZ */

#ifndef IFXSCU_CFG_CANDIV_133MHZ
/** brief Macro to configure CANDIV at 133MHz target frequency */
#define IFXSCU_CFG_CANDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_CANDIV_133MHZ */

#ifndef IFXSCU_CFG_CANDIV_160MHZ
/** brief Macro to configure CANDIV at 160MHz target frequency */
#define IFXSCU_CFG_CANDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_CANDIV_160MHZ */

#ifndef IFXSCU_CFG_CANDIV_200MHZ
/** brief Macro to configure CANDIV at 200MHz target frequency */
#define IFXSCU_CFG_CANDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_CANDIV_200MHZ */



#ifndef IFXSCU_CFG_ERAYDIV_80MHZ
/** brief Macro to configure ERAYDIV at 80MHz target frequency */
#define IFXSCU_CFG_ERAYDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 80MHz*/
#endif /*#ifndef IFXSCU_CFG_ERAYDIV_80MHZ */

#ifndef IFXSCU_CFG_ERAYDIV_133MHZ
/** brief Macro to configure ERAYDIV at 133MHz target frequency */
#define IFXSCU_CFG_ERAYDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 80MHz*/
#endif /*#ifndef IFXSCU_CFG_ERAYDIV_133MHZ */

#ifndef IFXSCU_CFG_ERAYDIV_160MHZ
/** brief Macro to configure ERAYDIV at 160MHz target frequency */
#define IFXSCU_CFG_ERAYDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 80MHz*/
#endif /*#ifndef IFXSCU_CFG_ERAYDIV_160MHZ */

#ifndef IFXSCU_CFG_ERAYDIV_200MHZ
/** brief Macro to configure ERAYDIV at 200MHz target frequency */
#define IFXSCU_CFG_ERAYDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 3)	/*Max: 80MHz*/
#endif /*#ifndef IFXSCU_CFG_ERAYDIV_200MHZ */



#ifndef IFXSCU_CFG_STMDIV_80MHZ
/** brief Macro to configure STMDIV at 80MHz target frequency */
#define IFXSCU_CFG_STMDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_STMDIV_80MHZ */

#ifndef IFXSCU_CFG_STMDIV_133MHZ
/** brief Macro to configure STMDIV at 133MHz target frequency */
#define IFXSCU_CFG_STMDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_STMDIV_133MHZ */

#ifndef IFXSCU_CFG_STMDIV_160MHZ
/** brief Macro to configure STMDIV at 160MHz target frequency */
#define IFXSCU_CFG_STMDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_STMDIV_160MHZ */

#ifndef IFXSCU_CFG_STMDIV_200MHZ
/** brief Macro to configure STMDIV at 200MHz target frequency */
#define IFXSCU_CFG_STMDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_STMDIV_200MHZ */



#ifndef IFXSCU_CFG_GTMDIV_80MHZ
/** brief Macro to configure GTMDIV at 80MHz target frequency */
#define IFXSCU_CFG_GTMDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_GTMDIV_80MHZ */

#ifndef IFXSCU_CFG_GTMDIV_133MHZ
/** brief Macro to configure GTMDIV at 133MHz target frequency */
#define IFXSCU_CFG_GTMDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_GTMDIV_133MHZ */

#ifndef IFXSCU_CFG_GTMDIV_160MHZ
/** brief Macro to configure GTMDIV at 160MHz target frequency */
#define IFXSCU_CFG_GTMDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_GTMDIV_160MHZ */

#ifndef IFXSCU_CFG_GTMDIV_200MHZ
/** brief Macro to configure GTMDIV at 200MHz target frequency */
#define IFXSCU_CFG_GTMDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_GTMDIV_200MHZ */



#ifndef IFXSCU_CFG_ETHDIV_80MHZ
/** brief Macro to configure ETHDIV at 80MHz target frequency */
#define IFXSCU_CFG_ETHDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_ETHDIV_80MHZ */

#ifndef IFXSCU_CFG_ETHDIV_133MHZ
/** brief Macro to configure ETHDIV at 133MHz target frequency */
#define IFXSCU_CFG_ETHDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 3)
#endif /*#ifndef IFXSCU_CFG_ETHDIV_133MHZ */

#ifndef IFXSCU_CFG_ETHDIV_160MHZ
/** brief Macro to configure ETHDIV at 160MHz target frequency */
#define IFXSCU_CFG_ETHDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 4)
#endif /*#ifndef IFXSCU_CFG_ETHDIV_160MHZ */

#ifndef IFXSCU_CFG_ETHDIV_200MHZ
/** brief Macro to configure ETHDIV at 200MHz target frequency */
#define IFXSCU_CFG_ETHDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 4)
#endif /*#ifndef IFXSCU_CFG_ETHDIV_200MHZ */



#ifndef IFXSCU_CFG_ASCLINFDIV_80MHZ
/** brief Macro to configure ASCLINFDIV at 80MHz target frequency */
#define IFXSCU_CFG_ASCLINFDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_ASCLINFDIV_80MHZ */

#ifndef IFXSCU_CFG_ASCLINFDIV_133MHZ
/** brief Macro to configure ASCLINFDIV at 133MHz target frequency */
#define IFXSCU_CFG_ASCLINFDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_ASCLINFDIV_133MHZ */

#ifndef IFXSCU_CFG_ASCLINFDIV_160MHZ
/** brief Macro to configure ASCLINFDIV at 160MHz target frequency */
#define IFXSCU_CFG_ASCLINFDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_ASCLINFDIV_160MHZ */

#ifndef IFXSCU_CFG_ASCLINFDIV_200MHZ
/** brief Macro to configure ASCLINFDIV at 200MHz target frequency */
#define IFXSCU_CFG_ASCLINFDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ)	/*Same as MAXDIV*/
#endif /*#ifndef IFXSCU_CFG_ASCLINFDIV_200MHZ */



#ifndef IFXSCU_CFG_ASCLINSDIV_80MHZ
/** brief Macro to configure ASCLINSDIV at 80MHz target frequency */
#define IFXSCU_CFG_ASCLINSDIV_80MHZ		(IFXSCU_CFG_MAXDIV_80MHZ)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_ASCLINSDIV_80MHZ */

#ifndef IFXSCU_CFG_ASCLINSDIV_133MHZ
/** brief Macro to configure ASCLINSDIV at 133MHz target frequency */
#define IFXSCU_CFG_ASCLINSDIV_133MHZ		(IFXSCU_CFG_MAXDIV_133MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_ASCLINSDIV_133MHZ */

#ifndef IFXSCU_CFG_ASCLINSDIV_160MHZ
/** brief Macro to configure ASCLINSDIV at 160MHz target frequency */
#define IFXSCU_CFG_ASCLINSDIV_160MHZ		(IFXSCU_CFG_MAXDIV_160MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_ASCLINSDIV_160MHZ */

#ifndef IFXSCU_CFG_ASCLINSDIV_200MHZ
/** brief Macro to configure ASCLINSDIV at 200MHz target frequency */
#define IFXSCU_CFG_ASCLINSDIV_200MHZ		(IFXSCU_CFG_MAXDIV_200MHZ * 2)	/*Max: 100MHz*/
#endif /*#ifndef IFXSCU_CFG_ASCLINSDIV_200MHZ */



#ifndef IFXSCU_CFG_BBBDIV_80MHZ
/** brief Macro to configure BBBDIV at 80MHz target frequency */
#define IFXSCU_CFG_BBBDIV_80MHZ		(IFXSCU_CFG_SRIDIV_80MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_80MHZ */

#ifndef IFXSCU_CFG_BBBDIV_133MHZ
/** brief Macro to configure BBBDIV at 133MHz target frequency */
#define IFXSCU_CFG_BBBDIV_133MHZ		(IFXSCU_CFG_SRIDIV_133MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_133MHZ */

#ifndef IFXSCU_CFG_BBBDIV_160MHZ
/** brief Macro to configure BBBDIV at 160MHz target frequency */
#define IFXSCU_CFG_BBBDIV_160MHZ		(IFXSCU_CFG_SRIDIV_160MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_160MHZ */

#ifndef IFXSCU_CFG_BBBDIV_200MHZ
/** brief Macro to configure BBBDIV at 200MHz target frequency */
#define IFXSCU_CFG_BBBDIV_200MHZ		(IFXSCU_CFG_SRIDIV_200MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_200MHZ */



#ifndef IFXSCU_CFG_CPU0DIV_80MHZ
/** brief Macro to configure CPU0DIV at 80MHz target frequency */
#define IFXSCU_CFG_CPU0DIV_80MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_80MHZ */

#ifndef IFXSCU_CFG_CPU0DIV_133MHZ
/** brief Macro to configure CPU0DIV at 133MHz target frequency */
#define IFXSCU_CFG_CPU0DIV_133MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_133MHZ */

#ifndef IFXSCU_CFG_CPU0DIV_160MHZ
/** brief Macro to configure CPU0DIV at 160MHz target frequency */
#define IFXSCU_CFG_CPU0DIV_160MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_160MHZ */

#ifndef IFXSCU_CFG_CPU0DIV_200MHZ
/** brief Macro to configure CPU0DIV at 200MHz target frequency */
#define IFXSCU_CFG_CPU0DIV_200MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_200MHZ */



#ifndef IFXSCU_CFG_CPU1DIV_80MHZ
/** brief Macro to configure CPU1DIV at 80MHz target frequency */
#define IFXSCU_CFG_CPU1DIV_80MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_80MHZ */

#ifndef IFXSCU_CFG_CPU1DIV_133MHZ
/** brief Macro to configure CPU1DIV at 133MHz target frequency */
#define IFXSCU_CFG_CPU1DIV_133MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_133MHZ */

#ifndef IFXSCU_CFG_CPU1DIV_160MHZ
/** brief Macro to configure CPU1DIV at 160MHz target frequency */
#define IFXSCU_CFG_CPU1DIV_160MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_160MHZ */

#ifndef IFXSCU_CFG_CPU1DIV_200MHZ
/** brief Macro to configure CPU1DIV at 200MHz target frequency */
#define IFXSCU_CFG_CPU1DIV_200MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_200MHZ */



#ifndef IFXSCU_CFG_CPU2DIV_80MHZ
/** brief Macro to configure CPU2DIV at 80MHz target frequency */
#define IFXSCU_CFG_CPU2DIV_80MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_80MHZ */

#ifndef IFXSCU_CFG_CPU2DIV_133MHZ
/** brief Macro to configure CPU2DIV at 133MHz target frequency */
#define IFXSCU_CFG_CPU2DIV_133MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_133MHZ */

#ifndef IFXSCU_CFG_CPU2DIV_160MHZ
/** brief Macro to configure CPU2DIV at 160MHz target frequency */
#define IFXSCU_CFG_CPU2DIV_160MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_160MHZ */

#ifndef IFXSCU_CFG_CPU2DIV_200MHZ
/** brief Macro to configure CPU2DIV at 200MHz target frequency */
#define IFXSCU_CFG_CPU2DIV_200MHZ		(0)	/*Same as SRIDIV*/
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_200MHZ */



/** \brief Macros to configure CCUCON0 Clock distribution */
#define IFXSCU_CFG_CCUCON0_MASK (									  \
	(IFX_SCU_CCUCON0_BAUD1DIV_MSK << IFX_SCU_CCUCON0_BAUD1DIV_OFF)	| \
	(IFX_SCU_CCUCON0_BAUD2DIV_MSK << IFX_SCU_CCUCON0_BAUD2DIV_OFF)	| \
	(IFX_SCU_CCUCON0_SRIDIV_MSK << IFX_SCU_CCUCON0_SRIDIV_OFF)		| \
	(IFX_SCU_CCUCON0_SPBDIV_MSK << IFX_SCU_CCUCON0_SPBDIV_OFF)		| \
	(IFX_SCU_CCUCON0_FSI2DIV_MSK << IFX_SCU_CCUCON0_FSI2DIV_OFF)	| \
	(IFX_SCU_CCUCON0_FSIDIV_MSK << IFX_SCU_CCUCON0_FSIDIV_OFF))

#define IFXSCU_CFG_CCUCON0_BASIC_(pllFreq) (uint32)(				  \
	(IFXSCU_CFG_BAUD1DIV_##pllFreq << IFX_SCU_CCUCON0_BAUD1DIV_OFF)	| \
	(IFXSCU_CFG_BAUD2DIV_##pllFreq << IFX_SCU_CCUCON0_BAUD2DIV_OFF)	| \
	(IFXSCU_CFG_SRIDIV_##pllFreq << IFX_SCU_CCUCON0_SRIDIV_OFF)		| \
	(IFXSCU_CFG_SPBDIV_##pllFreq << IFX_SCU_CCUCON0_SPBDIV_OFF)		| \
	(IFXSCU_CFG_FSI2DIV_##pllFreq << IFX_SCU_CCUCON0_FSI2DIV_OFF)	| \
	(IFXSCU_CFG_FSIDIV_##pllFreq << IFX_SCU_CCUCON0_FSIDIV_OFF))

#define IFXSCU_CFG_CCUCON0_BASIC(pllFreq) IFXSCU_CFG_CCUCON0_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON0 IFXSCU_CFG_CCUCON0_BASIC(IFXSCU_CFG_PLL_FREQ)

/** \brief Macros to configure CCUCON1 Clock distribution */
#define IFXSCU_CFG_CCUCON1_MASK (									  \
	(IFX_SCU_CCUCON1_CANDIV_MSK  << IFX_SCU_CCUCON1_CANDIV_OFF)		| \
	(IFX_SCU_CCUCON1_ERAYDIV_MSK << IFX_SCU_CCUCON1_ERAYDIV_OFF)	| \
	(IFX_SCU_CCUCON1_STMDIV_MSK  <<  IFX_SCU_CCUCON1_STMDIV_OFF)	| \
	(IFX_SCU_CCUCON1_GTMDIV_MSK  <<  IFX_SCU_CCUCON1_GTMDIV_OFF)	| \
	(IFX_SCU_CCUCON1_ETHDIV_MSK  << IFX_SCU_CCUCON1_ETHDIV_OFF)		| \
	(IFX_SCU_CCUCON1_ASCLINFDIV_MSK <<  IFX_SCU_CCUCON1_ASCLINFDIV_OFF)	| \
	(IFX_SCU_CCUCON1_ASCLINSDIV_MSK <<  IFX_SCU_CCUCON1_ASCLINSDIV_OFF))

#define IFXSCU_CFG_CCUCON1_BASIC_(pllFreq) (uint32)(				 \
	(IFXSCU_CFG_CANDIV_##pllFreq  << IFX_SCU_CCUCON1_CANDIV_OFF)	| \
	(IFXSCU_CFG_ERAYDIV_##pllFreq << IFX_SCU_CCUCON1_ERAYDIV_OFF)	| \
	(IFXSCU_CFG_STMDIV_##pllFreq  <<  IFX_SCU_CCUCON1_STMDIV_OFF)	| \
	(IFXSCU_CFG_GTMDIV_##pllFreq  <<  IFX_SCU_CCUCON1_GTMDIV_OFF)	| \
	(IFXSCU_CFG_ETHDIV_##pllFreq  << IFX_SCU_CCUCON1_ETHDIV_OFF)	| \
	(IFXSCU_CFG_ASCLINFDIV_##pllFreq <<  IFX_SCU_CCUCON1_ASCLINFDIV_OFF)| \
	(IFXSCU_CFG_ASCLINSDIV_##pllFreq <<  IFX_SCU_CCUCON1_ASCLINSDIV_OFF))

#define IFXSCU_CFG_CCUCON1_BASIC(pllFreq) IFXSCU_CFG_CCUCON1_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON1 IFXSCU_CFG_CCUCON1_BASIC(IFXSCU_CFG_PLL_FREQ)

/** \brief Macros to configure CCUCON2 Clock distribution */
#define IFXSCU_CFG_CCUCON2_MASK (									  \
	(IFX_SCU_CCUCON2_BBBDIV_MSK  << IFX_SCU_CCUCON2_BBBDIV_OFF))

#define IFXSCU_CFG_CCUCON2_BASIC_(pllFreq) (uint32)(				 \
	(IFXSCU_CFG_BBBDIV_##pllFreq  << IFX_SCU_CCUCON2_BBBDIV_OFF))

#define IFXSCU_CFG_CCUCON2_BASIC(pllFreq) IFXSCU_CFG_CCUCON2_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON2 IFXSCU_CFG_CCUCON2_BASIC(IFXSCU_CFG_PLL_FREQ)

/** \brief Macros to configure CCUCON5 Clock distribution */
#define IFXSCU_CFG_CCUCON5_MASK (									  \
	(IFX_SCU_CCUCON5_MAXDIV_MSK  << IFX_SCU_CCUCON5_MAXDIV_OFF))

#define IFXSCU_CFG_CCUCON5_BASIC_(pllFreq) (uint32)(				 \
	(IFXSCU_CFG_MAXDIV_##pllFreq  << IFX_SCU_CCUCON5_MAXDIV_OFF))

#define IFXSCU_CFG_CCUCON5_BASIC(pllFreq) IFXSCU_CFG_CCUCON5_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON5 IFXSCU_CFG_CCUCON5_BASIC(IFXSCU_CFG_PLL_FREQ)

/** \brief Macros to configure CCUCON6 Clock distribution */
#define IFXSCU_CFG_CCUCON6_MASK (									  \
	(IFX_SCU_CCUCON6_CPU0DIV_MSK  << IFX_SCU_CCUCON6_CPU0DIV_OFF))

#define IFXSCU_CFG_CCUCON6_BASIC_(pllFreq) (uint32)(				 \
	(IFXSCU_CFG_CPU0DIV_##pllFreq  << IFX_SCU_CCUCON6_CPU0DIV_OFF))

#define IFXSCU_CFG_CCUCON6_BASIC(pllFreq) IFXSCU_CFG_CCUCON6_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON6 IFXSCU_CFG_CCUCON6_BASIC(IFXSCU_CFG_PLL_FREQ)

/** \brief Macros to configure CCUCON7 Clock distribution */
#define IFXSCU_CFG_CCUCON7_MASK (									  \
	(IFX_SCU_CCUCON7_CPU1DIV_MSK  << IFX_SCU_CCUCON7_CPU1DIV_OFF))

#define IFXSCU_CFG_CCUCON7_BASIC_(pllFreq) (uint32)(				 \
	(IFXSCU_CFG_CPU1DIV_##pllFreq  << IFX_SCU_CCUCON7_CPU1DIV_OFF))

#define IFXSCU_CFG_CCUCON7_BASIC(pllFreq) IFXSCU_CFG_CCUCON7_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON7 IFXSCU_CFG_CCUCON7_BASIC(IFXSCU_CFG_PLL_FREQ)

/** \brief Macros to configure CCUCON8 Clock distribution */
#define IFXSCU_CFG_CCUCON8_MASK (									  \
	(IFX_SCU_CCUCON8_CPU2DIV_MSK  << IFX_SCU_CCUCON8_CPU2DIV_OFF))

#define IFXSCU_CFG_CCUCON8_BASIC_(pllFreq) (uint32)(				 \
	(IFXSCU_CFG_CPU2DIV_##pllFreq  << IFX_SCU_CCUCON8_CPU2DIV_OFF))

#define IFXSCU_CFG_CCUCON8_BASIC(pllFreq) IFXSCU_CFG_CCUCON8_BASIC_(pllFreq)

#define IFXSCU_CFG_CCUCON8 IFXSCU_CFG_CCUCON8_BASIC(IFXSCU_CFG_PLL_FREQ)

#define IFXSCU_CFG_CLK_DISTRIBUTION																	\
{																									\
/*	{	uint32 value,			uint32 mask					}*/										\
	{	IFXSCU_CFG_CCUCON0,	IFXSCU_CFG_CCUCON0_MASK	},	/*IfxScuCcu_CcuconRegConfig ccucon0;*/		\
	{	IFXSCU_CFG_CCUCON1,	IFXSCU_CFG_CCUCON1_MASK	},	/*IfxScuCcu_CcuconRegConfig ccucon1;*/		\
	{	IFXSCU_CFG_CCUCON2,	IFXSCU_CFG_CCUCON2_MASK	},	/*IfxScuCcu_CcuconRegConfig ccucon2;*/		\
	{	IFXSCU_CFG_CCUCON5,	IFXSCU_CFG_CCUCON5_MASK	},	/*IfxScuCcu_CcuconRegConfig ccucon5;*/		\
	{	IFXSCU_CFG_CCUCON6,	IFXSCU_CFG_CCUCON6_MASK	},	/*IfxScuCcu_CcuconRegConfig ccucon6;*/		\
	{	IFXSCU_CFG_CCUCON7,	IFXSCU_CFG_CCUCON7_MASK	},	/*IfxScuCcu_CcuconRegConfig ccucon7;*/		\
	{	IFXSCU_CFG_CCUCON8,	IFXSCU_CFG_CCUCON8_MASK	}	/*IfxScuCcu_CcuconRegConfig ccucon8;*/		\
}

/*Utility macros for the configuration structure */
/*macro for pll steps configuration */
#define IFXSCU_CFG_PLL_STEPS_BASIC_(xtalFreq,pllFreq) IFXSCU_CFG_PLL_STEPS_##xtalFreq##_##pllFreq
#define IFXSCU_CFG_PLL_STEPS_BASIC(xtalFreq,pllFreq) IFXSCU_CFG_PLL_STEPS_BASIC_(xtalFreq,pllFreq)
#define IFXSCU_CFG_PLL_STEPS IFXSCU_CFG_PLL_STEPS_BASIC(IFXSCU_CFG_XTAL_FREQ, IFXSCU_CFG_PLL_FREQ)

/*macro for pll initial step configuration */
#define IFXSCU_CFG_PLL_INITIAL_STEP_BASIC_(xtalFreq,pllFreq) IFXSCU_CFG_PLL_INITIAL_STEP_##xtalFreq##_##pllFreq
#define IFXSCU_CFG_PLL_INITIAL_STEP_BASIC(xtalFreq,pllFreq) IFXSCU_CFG_PLL_INITIAL_STEP_BASIC_(xtalFreq,pllFreq)
#define IFXSCU_CFG_PLL_INITIAL_STEP IFXSCU_CFG_PLL_INITIAL_STEP_BASIC(IFXSCU_CFG_XTAL_FREQ, IFXSCU_CFG_PLL_FREQ)

#if (IFX_CFG_SCU_XTAL_FREQUENCY == (20000000))
#define IFXSCU_CFG_XTAL_FREQ 20MHZ
#elif (IFX_CFG_SCU_XTAL_FREQUENCY == (40000000))
#define IFXSCU_CFG_XTAL_FREQ 40MHZ
#elif (IFX_CFG_SCU_XTAL_FREQUENCY == (16000000))
#define IFXSCU_CFG_XTAL_FREQ 16MHZ
#else
#error "Wrong XTAL frequency configuration! check IFX_CFG_SCU_XTAL_FREQUENCY configuration in Ifx_Cfg.h."
#error "Aurix Triboard supported crystal frequencies are 16MHz, 20MHz and 40MHz"
#endif

#if (IFX_CFG_SCU_PLL_FREQUENCY == (80000000))
#define IFXSCU_CFG_PLL_FREQ		80MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (133000000))
#define IFXSCU_CFG_PLL_FREQ		133MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (160000000))
#define IFXSCU_CFG_PLL_FREQ		160MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (200000000))
#define IFXSCU_CFG_PLL_FREQ		200MHZ
#else
#error "Wrong PLL frequency configuration!, check IFX_CFG_SCU_PLL_FREQUENCY configuration in Ifx_Cfg.h."
#error "Supported PLL frequencies are 80MHz, 133MHz, 160Mhz, and 200MHz."
#endif

/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/
/** Clock selection  */
typedef enum
{
    IfxScu_CCUCON0_CLKSEL_fBack = 0,
    IfxScu_CCUCON0_CLKSEL_fPll = 1
} IfxScu_CCUCON0_CLKSEL;

/** Input selection for PLL and PLL ERAY */
typedef enum
{
    IfxScu_CCUCON1_INSEL_fOsc1 = 0,
    IfxScu_CCUCON1_INSEL_fOsc0 = 1
} IfxScu_CCUCON1_INSEL;

/** Input frequency request control */
typedef enum
{
    IfxScu_WDTCON1_IR_divBy16384 = 0,
    IfxScu_WDTCON1_IR_divBy256 = 1,
    IfxScu_WDTCON1_IR_divBy64 = 2
} IfxScu_WDTCON1_IR;


typedef enum
{
    IfxScu_PMCSR_REQSLP_Run = 0U,   /* 00 Request CPU Run Mode */
    IfxScu_PMCSR_REQSLP_Idle = 1U,  /* 01 Request CPU Idle Mode */
    IfxScu_PMCSR_REQSLP_Sleep = 2U, /* 10 Request CPU System Sleep Mode */
    IfxScu_PMCSR_REQSLP_Stby = 3U   /* 11 Request System Standby Mode */
} IfxScu_PMCSR_REQSLP;

/******************************************************************************/

#endif /* IFXSCU_CFG_H */

/*-------------------------------- end of file -------------------------------*/
