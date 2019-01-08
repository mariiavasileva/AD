#ifndef AUTODIFF_A13X_BACK_H
#define AUTODIFF_A13X_BACK_H

#include "a13x.h"
#include <string>
#include "model.h"
#include "input.h"
#include <sstream>
#include <stdlib.h>


//string nodeValueToStr(node* n, bool useMapping, double &nodeValue);
//extern string nodeValueToStr(node* n, bool useMapping, double &nodeValue);
void ValBack(node* current_oper, node* prevOper, string strPrevDer, double retValue);

#endif //AUTODIFF_A13X_BACK_H