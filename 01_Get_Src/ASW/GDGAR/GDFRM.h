
#ifndef _GDFRM_H_
#define _GDFRM_H_

#include "STD_TYPES.h"

typedef uint8 GDFRM_tenuGDUState;

#define GDU_ETAT_ABSENT                (GDFRM_tenuGDUState)(0)
#define GDU_ETAT_PCTL_PRESENT          (GDFRM_tenuGDUState)(1)
#define GDU_ETAT_PCTL_ABSENT           (GDFRM_tenuGDUState)(2)
#define GDU_ETAT_PRESENT               (GDFRM_tenuGDUState)(3)
#define GDU_ETAT_DEVALIDATION          (GDFRM_tenuGDUState)(4)
#define GDU_ETAT_FUGITIF               (GDFRM_tenuGDUState)(5)


#define GDU_ETAT_DEFAUT GDU_ETAT_ABSENT

typedef uint8 GDFRM_tenuGOBDState;

#define GOBD_ETAT_OK                (GDFRM_tenuGOBDState)(0)
#define GOBD_ETAT_PENDING1          (GDFRM_tenuGOBDState)(1)
#define GOBD_ETAT_PENDING2          (GDFRM_tenuGOBDState)(2)
#define GOBD_ETAT_ENREGISTRE        (GDFRM_tenuGOBDState)(3)
#define GOBD_ETAT_HISTORIQUE_ON     (GDFRM_tenuGOBDState)(4)
#define GOBD_ETAT_HISTORIQUE_OFF    (GDFRM_tenuGOBDState)(5)

#define GOBD_ETAT_DEFAUT GOBD_ETAT_OK

#endif /* _GDFRM_H_ */
