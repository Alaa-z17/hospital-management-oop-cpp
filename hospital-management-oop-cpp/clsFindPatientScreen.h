#ifndef __CLSFINDPATIENTSCREEN_H__
#define __CLSFINDPATIENTSCREEN_H__

#include "clsScreen.h"
#include "clsPatientData.h"

class clsFindPatientScreen : public clsScreen
{
private:

public:
    void show() override
    {
        _showHeader("Find Patient");

        string patientID = _readPatientID();
        int index = clsPatientData::findPatientIndex(patientID);
        if (index == -1)
        {
            cout << "\nPatient with ID " << patientID << " not found.\n";
        }
        else
        {
            clsPatient patient = clsPatientData::getPatients()[index];
            patient.printInfo();
        }

        _pauseScreen();
    }
};

#endif // __CLSFINDPATIENTSCREEN_H__