/**************************************************************************************************\
 ***
 *** Simulink model       : mdl_01552_09_00336_CoOptmEl
 *** TargetLink subsystem : mdl_01552_09_00336_CoOptmEl/ProdElEm_002
\**************************************************************************************************/

#ifndef _COOPTMEL_CUSTOM_H_
#define _COOPTMEL_CUSTOM_H_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
#define CMAXUINT8 255U
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
// Champ de bits des 65 besoins.
//typedef struct {
//	UInt8 bfConstElMgt1;
//	UInt8 bfConstElMgt2;
//	UInt8 bfConstElMgt3;
//	UInt8 bfConstFrntTra1;
//	UInt8 bfConstReTra1;
//	UInt8 bfConstEm1;
//	UInt8 bfConstEm2;
//	UInt8 bfConstEng1;
//	unsigned bfConstElMgtOld : 1;
//} bfConst;

typedef UInt8 bfConst[9];
typedef UInt8 idVect[65];
typedef UInt8 idVectSta[54];
typedef UInt8 idVectDyn[11];

/*----------------------------------------------------------------------------*\
  FUNCTIONS
\*----------------------------------------------------------------------------*/
// Opérations sur les champs de bits des contraintes.

//-- Opérations binaires.
void bfAnd(bfConst, bfConst, bfConst);
void bfOr(bfConst, bfConst, bfConst);
void bfXor(bfConst, bfConst, bfConst);
//-- Déterminer si tous les bits sont nuls..
UInt8 bfIsZero(bfConst);

// Opérations sur le vecteur d'indices.

//-- Voir si un indice est présent dans le vecteur.
UInt8 idContains(idVect, UInt8);
//-- Calculer le max/min dans un vecteur uniquement sur les indices contenus dans
//-- un vecteur d'indices.
void maxSta8(idVectSta, UInt8*, UInt8*, UInt8*);
void minSta8(idVectSta, UInt8*, UInt8*, UInt8*);
void maxSta16(idVectSta, UInt16*, UInt16*, UInt8*);
void minSta16(idVectSta, UInt16*, UInt16*, UInt8*);
void minDyn8(idVectDyn, UInt8*, UInt8*, UInt8*);
void maxDyn16(idVectDyn, UInt16*, UInt16*, UInt8*);
void minDyn16(idVectDyn, UInt16*, UInt16*, UInt8*);
//-- Calculer le max/min en prenant en compte la priorité.
void maxStaPrio(idVectSta, UInt16*, UInt8*, UInt8, UInt16*);
void minStaPrio(idVectSta, UInt16*, UInt8*, UInt8, UInt16*);
void maxDynPrio(idVectDyn, UInt16*, UInt8*, UInt8, UInt8, UInt16*);
void minDynPrio(idVectDyn, UInt16*, UInt8*, UInt8, UInt8, UInt16*);
// Déterminer si un besoin est dynamique.
Boolean isDynConstId(UInt8);

// Saturer une valeur.
UInt8 sat8(UInt8, UInt8, UInt8);
UInt16 sat16(UInt16, UInt16, UInt16);

#endif/*_COOPTMEL_CUSTOM_H_ */
