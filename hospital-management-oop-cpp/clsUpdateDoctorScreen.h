#ifndef __CLSUPDATEDOCTORSCREEN_H__
#define __CLSUPDATEDOCTORSCREEN_H__

#include "clsScreen.h"
#include "clsDoctorData.h"

class clsUpdateDoctorScreen : public clsScreen
{
private:
    clsDoctor _ReadDoctorInfo()
    {
        string doctorID = _readDoctorID();
        int index = clsDoctorData::findDoctorIndex(doctorID);
        if (index == -1)
        {
            cout << "\nDoctor with ID " << doctorID << " not found.\n";
        }
        else
        {
            clsDoctor doctor = clsDoctorData::getDoctors()[index];
            cout << "\nCurrent information:\n";
            doctor.printInfo();

            cout << "\nEnter new information (leave blank to keep current):\n";
            string firstName = clsInputValidate<string>::ReadString("Enter First Name (current: " + doctor.getFirstName() + "): ");
            if (!firstName.empty()) doctor.setFirstName(firstName);

            string lastName = clsInputValidate<string>::ReadString("Enter Last Name (current: " + doctor.getLastName() + "): ");
            if (!lastName.empty()) doctor.setLastName(lastName);

            string phone = clsInputValidate<string>::ReadPhone("Enter Phone (current: " + doctor.getPhone() + "): ");
            if (!phone.empty()) doctor.setPhone(phone);

            string email = clsInputValidate<string>::ReadEmail("Enter Email (current: " + doctor.getEmail() + "): ");
            if (!email.empty()) doctor.setEmail(email);

            string ageStr;
            cout << "Enter Age (current: " << doctor.getAge() << "): ";
            ageStr = to_string(clsInputValidate<short>::ReadNumberBetween("", 0, 150));
            if (!ageStr.empty()) doctor.setAge(stoi(ageStr));

            string specialization = clsInputValidate<string>::ReadString("Enter Specialization (current: " + doctor.getSpecialization() + "): ");
            if (!specialization.empty()) doctor.setSpecialization(specialization);

            string feeStr;
            cout << "Enter Consultation Fee (current: " << doctor.getConsultationFee() << "): ";
            feeStr = to_string(clsInputValidate<float>::ReadPositiveNumber());
            if (!feeStr.empty()) doctor.setConsultationFee(stof(feeStr));
            return doctor;
        }
    }
public:
    void show() override
    {
        _showHeader("Update Doctor");


        if (clsDoctorData::updateDoctor(_ReadDoctorInfo()))
        {
            cout << "\nDoctor updated successfully.\n";
        }
        else
        {
            cout << "\nError: Could not update doctor.\n";
        }
    
        _pauseScreen();
    }
};

#endif // __CLSUPDATEDOCTORSCREEN_H__