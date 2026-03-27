#ifndef __CLSFINDDOCTORSCREEN_H__
#define __CLSFINDDOCTORSCREEN_H__

#include "clsScreen.h"
#include "clsDoctorData.h"

class clsFindDoctorScreen : public clsScreen
{

public:
    void show() override
    {
        _showHeader("Find Doctor");

        string doctorID = _readDoctorID();
        int index = clsDoctorData::findDoctorIndex(doctorID);
        if (index == -1)
        {
            cout << "\nDoctor with ID " << doctorID << " not found.\n";
        }
        else
        {
            clsDoctor doctor = clsDoctorData::getDoctors()[index];
            doctor.printInfo();
        }

        _pauseScreen();
    }
};

#endif // __CLSFINDDOCTORSCREEN_H__