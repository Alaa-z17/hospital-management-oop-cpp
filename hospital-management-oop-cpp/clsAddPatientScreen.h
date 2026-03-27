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
        string phone = clsInputValidate<string>::ReadPhone("Enter Phone: ");
        string email = clsInputValidate<string>::ReadEmail("Enter Email: ");
        short age = clsInputValidate<short>::ReadNumberBetween("Enter Age: ", 0, 120);
        string diagnosis = clsInputValidate<string>::ReadString("Enter Diagnosis: ");
        string bloodType = clsInputValidate<string>::ReadString("Enter Blood Type: ");
        return clsPatient(firstName, lastName, phone, email, age,
            patientID, diagnosis, bloodType);
    }

public:
    void show() override
    {
        _showHeader("Add New Patient");

       
        string bloodType = clsInputValidate<string>::ReadString("Enter Blood Type: ");

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