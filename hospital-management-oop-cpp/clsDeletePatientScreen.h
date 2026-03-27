#ifndef __CLSDELETEPATIENTSCREEN_H__
#define __CLSDELETEPATIENTSCREEN_H__

#include "clsScreen.h"
#include "clsPatientData.h"

class clsDeletePatientScreen : public clsScreen
{

public:
    void show() override
    {
        _showHeader("Delete Patient");

        string patientID = _readPatientID();
        int index = clsPatientData::findPatientIndex(patientID);
        if (index == -1)
        {
            cout << "\nPatient with ID " << patientID << " not found.\n";
        }
        else
        {
            // Show patient info before deleting
            clsPatient patient = clsPatientData::getPatients()[index];
            cout << "\nPatient found:\n";
            patient.printInfo();

            char confirm;
            cout << "\nAre you sure you want to delete this patient? (y/n): ";
            cin >> confirm;
            cin.ignore();

            if (tolower(confirm) == 'y')
            {
                if (clsPatientData::deletePatient(patientID))
                {
                    cout << "\nPatient deleted successfully.\n";
                }
                else
                {
                    cout << "\nError: Could not delete patient.\n";
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

#endif // __CLSDELETEPATIENTSCREEN_H__