#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "clsString.h"
#include "clsDate.h"
#include "clsInputValidate.h"

using namespace std;

// File paths
const string PATIENTS_FILE = "patients.txt";
const string DOCTORS_FILE = "doctors.txt";
const string APPOINTMENTS_FILE = "appointments.txt";

// System boot function declaration; implementation is in Global.cpp
void SystemBoot();

#endif // __GLOBAL_H__