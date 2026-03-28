#ifndef __CLSUPDATEPATIENTSCREEN_H__
#define __CLSUPDATEPATIENTSCREEN_H__

#include "clsScreen.h"
#include "clsPatientData.h"

class clsUpdatePatientScreen : public clsScreen
{
private:
    clsPatient _ReadPatientInfo()
    {

        string patientID = _readPatientID();
        int index = clsPatientData::findPatientIndex(patientID);
        if (index == -1)
        {
            cout << "\nPatient with ID " << patientID << " not found.\n";
        }
        else
        {
            clsPatient patient = clsPatientData::getPatients()[index];
            cout << "\nCurrent information:\n";
            patient.printInfo();

            cout << "\nEnter new information :\n";
            string firstName = clsInputValidate<string>::ReadString("Enter First Name (current: " + patient.getFirstName() + ") ");
            if (!firstName.empty()) patient.setFirstName(firstName);

            string lastName = clsInputValidate<string>::ReadString("Enter Last Name (current: " + patient.getLastName() + ") ");
            if (!lastName.empty()) patient.setLastName(lastName);

            string phone = clsInputValidate<string>::ReadString("Enter Phone (current: " + patient.getPhone() + ") ");
            if (!phone.empty()) patient.setPhone(phone);

            string email = clsInputValidate<string>::ReadString("Enter Email (current: " + patient.getEmail() + ") ");
            if (!email.empty()) patient.setEmail(email);

            // Age is numeric, we treat empty as no change
            string ageStr;
            cout << "Enter Age (current: " << patient.getAge() << ") ";
            ageStr = to_string(clsInputValidate<short>::ReadNumberBetween(0, 150));
            if (!ageStr.empty()) patient.setAge(stoi(ageStr));

            string diagnosis = clsInputValidate<string>::ReadString("Enter Diagnosis (current: " + patient.getDiagnosis() + ") ");
            if (!diagnosis.empty()) patient.setDiagnosis(diagnosis);

            string bloodType = clsInputValidate<string>::ReadString("Enter Blood Type (current: " + patient.getBloodType() + ") ");
            if (!bloodType.empty()) patient.setBloodType(bloodType);
            return patient;
        }
        return clsPatient();
    }
public:
    void show() override
    {
        _showHeader("Update Patient");


            if (clsPatientData::updatePatient(_ReadPatientInfo()))
            {
                cout << "\nPatient updated successfully.\n";
            }
            else
            {
                cout << "\nError: Could not update patient.\n";
            }
        

        _pauseScreen();
    }
};

#endif // __CLSUPDATEPATIENTSCREEN_H__