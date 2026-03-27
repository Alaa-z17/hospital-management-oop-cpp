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
        string phone = clsInputValidate<string>::ReadPhone("Enter Phone: ");
        string email = clsInputValidate<string>::ReadEmail("Enter Email: ");
        short age = clsInputValidate<short>::ReadNumberBetween("Enter Age: ", 0, 120);
        string specialization = clsInputValidate<string>::ReadString("Enter Specialization: ");
        float fee = clsInputValidate<float>::ReadNumberBetween("Enter Consultation Fee: ", 0, 10000);
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