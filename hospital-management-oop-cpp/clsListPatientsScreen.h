#ifndef __CLSLISTPATIENTSSCREEN_H__
#define __CLSLISTPATIENTSSCREEN_H__

#include "clsScreen.h"
#include "clsPatientData.h"

class clsListPatientsScreen : public clsScreen
{
private:
    static void _printPatientRecord(const clsPatient& patient)
    {
        cout << "| " << setw(12) << left << patient.getPatientID();
        cout << "| " << setw(20) << left << patient.getFullName();
        cout << "| " << setw(15) << left << patient.getPhone();
        cout << "| " << setw(25) << left << patient.getEmail();
        cout << "| " << setw(5) << left << patient.getAge();
        cout << "| " << setw(10) << left << patient.getBloodType();
        cout << "| " << setw(20) << left << patient.getDiagnosis();
        cout << "|" << endl;
    }

public:
    void show() override
    {
        _showHeader("List All Patients");

        const auto& patients = clsPatientData::getPatients();

        if (patients.size() == 0)
        {
            cout << "\nNo patients found.\n";
        }
        else
        {
            cout << "\n_________________________________________________________________________________________________________________________\n";
            cout << "| " << left << setw(12) << "Patient ID";
            cout << "| " << setw(20) << "Name";
            cout << "| " << setw(15) << "Phone";
            cout << "| " << setw(25) << "Email";
            cout << "| " << setw(5) << "Age";
            cout << "| " << setw(10) << "Blood Type";
            cout << "| " << setw(20) << "Diagnosis";
            cout << "|" << endl;
            cout << "_________________________________________________________________________________________________________________________\n";

            for (const auto& patient : patients)
            {
                _printPatientRecord(patient);
            }
            cout << "_________________________________________________________________________________________________________________________\n";
            cout << "Total Patients: " << patients.size() << endl;
        }

        _pauseScreen();
    }
};

#endif // __CLSLISTPATIENTSSCREEN_H__