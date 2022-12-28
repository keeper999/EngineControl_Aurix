

#include "LibCore_Fabs.h"

float LibCore_Fabs_Float(float _in) {
	if (_in < 0.0F) {
		return (- _in);
	} else {
		return (_in);
	}
}
