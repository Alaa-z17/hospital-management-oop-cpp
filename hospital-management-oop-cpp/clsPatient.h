#ifndef __CLSPATIENT_H__
#define __CLSPATIENT_H__
#include "clsPerson.h"

class clsPatient : public clsPerson
{
private:
    string _PatientID;
    string _Diagnosis;
    string _BloodType;

    static int _TotalPatients;   // static counter for patients only

public:
    // Constructors
    clsPatient() : clsPerson(), _PatientID(""), _Diagnosis(""), _BloodType("")
    {
        _TotalPatients++;
    }

    clsPatient(string firstName, string lastName, string phone, string email, short age,
        string patientID, string diagnosis, string bloodType)
        : clsPerson(firstName, lastName, phone, email, age),
        _PatientID(patientID), _Diagnosis(diagnosis), _BloodType(bloodType)
    {
        _TotalPatients++;
    }

    // Destructor
    ~clsPatient()
    {
        _TotalPatients--;
    }

    // Getters & Setters
    void setPatientID(string patientID) { _PatientID = patientID; }
    string getPatientID() const { return _PatientID; }

    void setDiagnosis(string diagnosis) { _Diagnosis = diagnosis; }
    string getDiagnosis() const { return _Diagnosis; }

    void setBloodType(string bloodType) { _BloodType = bloodType; }
    string getBloodType() const { return _BloodType; }

    // Implement pure virtual from clsPerson
    string getID() const override
    {
        return getPatientID();
    }

    // Override printInfo to include patient details
    void printInfo() const override
    {
        clsPerson::printInfo();   // call base class print
        cout << "Patient ID  : " << _PatientID << endl;
        cout << "Blood Type  : " << _BloodType << endl;
        cout << "Diagnosis   : " << _Diagnosis << endl;
    }

    // Static method to get total patients count
    static int getTotalPatients() { return _TotalPatients; }
};

// Initialize static member
int clsPatient::_TotalPatients = 0;

#endif // __CLSPATIENT_H__