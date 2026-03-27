#ifndef __CLSAPPOINTMENT_H__
#define __CLSAPPOINTMENT_H__

#include "Global.h"
#include "clsDoctor.h"
#include "clsPatient.h"

class clsAppointment
{
private:
    string _AppointmentID;
    clsDoctor  _Doctor;
    clsPatient _Patient;
    string _Date;      // Format: YYYY-MM-DD
    string _Status;    // "Scheduled", "Completed", "Cancelled"

    static int _TotalAppointments;

public:
    // Constructors
    clsAppointment() : _AppointmentID(""), _Doctor(), _Patient(), _Date(""), _Status("Scheduled")
    {
        _TotalAppointments++;
    }

    clsAppointment(string appointmentID, const clsDoctor& doctor, const clsPatient& patient, string date, string status)
        : _AppointmentID(appointmentID), _Doctor(doctor), _Patient(patient), _Date(date), _Status(status)
    {
        _TotalAppointments++;
    }

    ~clsAppointment()
    {
        _TotalAppointments--;
    }

    // Getters & Setters (getters return const references to avoid copying)
    void setAppointmentID(string appointmentID) { _AppointmentID = appointmentID; }
    string getAppointmentID() const { return _AppointmentID; }

    void setDoctor(const clsDoctor& doctor) { _Doctor = doctor; }
    const clsDoctor& getDoctor() const { return _Doctor; }

    void setPatient(const clsPatient& patient) { _Patient = patient; }
    const clsPatient& getPatient() const { return _Patient; }

    void setDate(string date) { _Date = date; }
    string getDate() const { return _Date; }

    void setStatus(string status) { _Status = status; }
    string getStatus() const { return _Status; }

#ifdef _MSC_VER
    // Microsoft-specific properties
    __declspec(property(get = getAppointmentID, put = setAppointmentID)) string AppointmentID;
    __declspec(property(get = getDate, put = setDate)) string Date;
    __declspec(property(get = getStatus, put = setStatus)) string Status;
    __declspec(property(get = getDoctor, put = setDoctor)) clsDoctor Doctor;
    __declspec(property(get = getPatient, put = setPatient)) clsPatient Patient;
#endif

    void printInfo() const
    {
        cout << "\n=================================" << endl;
        cout << "Appointment Information:" << endl;
        cout << "=================================" << endl;
        cout << "Appointment ID : " << _AppointmentID << endl;
        cout << "Date           : " << _Date << endl;
        cout << "Status         : " << _Status << endl;
        cout << "\n--- Doctor Details ---" << endl;
        _Doctor.printInfo();
        cout << "\n--- Patient Details ---" << endl;
        _Patient.printInfo();
    }

    static int getTotalAppointments() { return _TotalAppointments; }
};

int clsAppointment::_TotalAppointments = 0;

#endif // __CLSAPPOINTMENT_H__