#ifndef __CLSADDPATIENTSCREEN_H__
#define __CLSADDPATIENTSCREEN_H__

#include "clsScreen.h"
#include "clsPatientData.h"

class clsAddPatientScreen : public clsScreen
{
private:
    clsPatient _ReadPatientInfo()
    {
        string patientID = _readPatientID();
        while (clsPatientData::findPatientIndex(patientID) != -1)
        {
            cout << "Patient ID already exists. Enter another ID: ";
            patientID = clsInputValidate<string>::ReadString();
        }
        string firstName = clsInputValidate<string>::ReadString("Enter First Name: ");
        string lastName = clsInputValidate<string>::ReadString("Enter Last Name: ");
      
        cout << "Enter Phone: ";
        string phone = clsInputValidate<string>::ReadPhone();
        cout << "Enter Email: ";
        string email = clsInputValidate<string>::ReadEmail();

        cout << "Enter Age (0-120): ";
        short age = clsInputValidate<short>::ReadNumberBetween(0, 120);

        string diagnosis = clsInputValidate<string>::ReadString("Enter Diagnosis: ");
        string bloodType = clsInputValidate<string>::ReadString("Enter Blood Type: ");
        return clsPatient(firstName, lastName, phone, email, age,
            patientID, diagnosis, bloodType);
    }

public:
    void show() override
    {
        _showHeader("Add New Patient");

        clsPatient newPatient = _ReadPatientInfo();

        if (clsPatientData::addPatient(newPatient))
        {
            cout << "\nPatient added successfully.\n";
        }
        else
        {
            cout << "\nError: Failed to add patient.\n";
        }

        _pauseScreen();
    }
};

#endif // __CLSADDPATIENTSCREEN_H__