//
// Created by mariia on 26/09/16.
//

#ifndef AUTODIFF_INPUT_H
#define AUTODIFF_INPUT_H

#include <iostream>
#include <vector>
#include "exprtk.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "model.h"

using namespace std;

extern double masvar[10];
extern double funvar[10];
extern string funcname[10]; //All fuction names
extern string multi[10];  //All strings from file
extern string mas[10];
extern int con;

double Calculating(string astr, int num);
void Reading();
void Input(int a);

#endif //AUTODIFF_INPUT_H
