#ifndef __CLSADDDOCTORSCREEN_H__
#define __CLSADDDOCTORSCREEN_H__

#include "clsScreen.h"
#include "clsDoctorData.h"

class clsAddDoctorScreen : public clsScreen
{
private:

    clsDoctor _ReadDoctorInfo()
    {
        string doctorID = _readDoctorID();
        while (clsDoctorData::findDoctorIndex(doctorID) != -1)
        {
            cout << "Doctor ID already exists. Enter another ID: ";
            doctorID = clsInputValidate<string>::ReadString();
        }

        string firstName = clsInputValidate<string>::ReadString("Enter First Name: ");
        string lastName = clsInputValidate<string>::ReadString("Enter Last Name: ");

        cout << "Enter Phone: ";
        string phone = clsInputValidate<string>::ReadPhone();
        cout << "Enter Email: ";
        string email = clsInputValidate<string>::ReadEmail();

		cout << "Enter Age: ";
        short age = clsInputValidate<short>::ReadNumberBetween(0, 120);
        string specialization = clsInputValidate<string>::ReadString("Enter Specialization: ");

        cout << "Enter Consultation Fee: ";
        float fee = clsInputValidate<float>::ReadNumberBetween(0, 10000);
        return clsDoctor(firstName, lastName, phone, email, age,
            doctorID, specialization, fee);
	}

public:
    void show() override
    {
        _showHeader("Add New Doctor");

       

        clsDoctor newDoctor = _ReadDoctorInfo();

        if (clsDoctorData::addDoctor(newDoctor))
        {
            cout << "\nDoctor added successfully.\n";
        }
        else
        {
            cout << "\nError: Failed to add doctor.\n";
        }

        _pauseScreen();
    }
};

#endif // __CLSADDDOCTORSCREEN_H__