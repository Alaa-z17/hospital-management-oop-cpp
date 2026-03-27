#ifndef __CLSDOCTOR_H__
#define __CLSDOCTOR_H__

#include "clsPerson.h"

class clsDoctor : public clsPerson
{
private:
    string _DoctorID;
    string _Specialization;
    float  _ConsultationFee;

    static int _TotalDoctors;   // static counter for doctors only

public:
    // Constructors
    clsDoctor() : clsPerson(), _DoctorID(""), _Specialization(""), _ConsultationFee(0)
    {
        _TotalDoctors++;
    }

    clsDoctor(string firstName, string lastName, string phone, string email, short age,
        string doctorID, string specialization, float consultationFee)
        : clsPerson(firstName, lastName, phone, email, age),
        _DoctorID(doctorID), _Specialization(specialization), _ConsultationFee(consultationFee)
    {
        _TotalDoctors++;
    }

    // Destructor
    ~clsDoctor()
    {
        _TotalDoctors--;
    }

    // Getters & Setters
    void setDoctorID(string doctorID) { _DoctorID = doctorID; }
    string getDoctorID() const { return _DoctorID; }

    void setSpecialization(string specialization) { _Specialization = specialization; }
    string getSpecialization() const { return _Specialization; }

    void setConsultationFee(float consultationFee) { _ConsultationFee = consultationFee; }
    float getConsultationFee() const { return _ConsultationFee; }

    // Implement pure virtual from clsPerson
    string getID() const override
    {
        return getDoctorID();
    }

    // Override printInfo to include doctor details
    void printInfo() const override
    {
        clsPerson::printInfo();   // call base class print
        cout << "Doctor ID      : " << _DoctorID << endl;
        cout << "Specialization : " << _Specialization << endl;
        cout << "Consultation Fee: $" << fixed << setprecision(2) << _ConsultationFee << endl;
    }

    // Static method to get total doctors count
    static int getTotalDoctors() { return _TotalDoctors; }
};

// Initialize static member
int clsDoctor::_TotalDoctors = 0;

#endif // __CLSDOCTOR_H__