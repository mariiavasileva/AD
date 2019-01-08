#ifndef AUTODIFF_A13X_H
#define AUTODIFF_A13X_H

#include <string>
#include "model.h"
#include "input.h"
#include <sstream>
#include <stdlib.h>

string Val(node* ad_oper, string varName, bool der, double &valResult);
string nodeValueToStr(node* n, bool useMapping, double &nodeValue, string varName);


#endif //AUTODIFF_A13X_H