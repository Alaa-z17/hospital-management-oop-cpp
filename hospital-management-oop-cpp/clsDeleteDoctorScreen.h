#ifndef __CLSDELETEDOCTORSCREEN_H__
#define __CLSDELETEDOCTORSCREEN_H__

#include "clsScreen.h"
#include "clsDoctorData.h"

class clsDeleteDoctorScreen : public clsScreen
{

public:
    void show() override
    {
        _showHeader("Delete Doctor");

        string doctorID = _readDoctorID();
        int index = clsDoctorData::findDoctorIndex(doctorID);
        if (index == -1)
        {
            cout << "\nDoctor with ID " << doctorID << " not found.\n";
        }
        else
        {
            clsDoctor doctor = clsDoctorData::getDoctors()[index];
            cout << "\nDoctor found:\n";
            doctor.printInfo();

            char confirm;
            cout << "\nAre you sure you want to delete this doctor? (y/n): ";
            cin >> confirm;
            cin.ignore();

            if (tolower(confirm) == 'y')
            {
                if (clsDoctorData::deleteDoctor(doctorID))
                {
                    cout << "\nDoctor deleted successfully.\n";
                }
                else
                {
                    cout << "\nError: Could not delete doctor.\n";
                }
            }
            else
            {
                cout << "\nDeletion cancelled.\n";
            }
        }

        _pauseScreen();
    }
};

#endif // __CLSDELETEDOCTORSCREEN_H__