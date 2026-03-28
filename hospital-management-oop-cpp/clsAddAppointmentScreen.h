#ifndef __CLSADDAPPOINTMENTSCREEN_H__
#define __CLSADDAPPOINTMENTSCREEN_H__

#include "clsScreen.h"
#include "clsAppointmentData.h"
#include "clsDoctorData.h"
#include "clsPatientData.h"

class clsAddAppointmentScreen : public clsScreen
{

    static clsDoctor _chooseDoctor()
    {
        string doctorID;
        clsDoctor doctor;
        do {
            cout << "Enter Doctor ID: ";
            doctorID = clsInputValidate<string>::ReadString();
            doctor = clsDoctorData::getDoctorByID(doctorID);
            if (doctor.getDoctorID() == "")
            {
                cout << "Doctor not found. Try again.\n";
            }
        } while (doctor.getDoctorID() == "");
        return doctor;
    }

    static clsPatient _choosePatient()
    {
        string patientID;
        clsPatient patient;
        do {
            cout << "Enter Patient ID: ";
            patientID = clsInputValidate<string>::ReadString();
            patient = clsPatientData::getPatientByID(patientID);
            if (patient.getPatientID() == "")
            {
                cout << "Patient not found. Try again.\n";
            }
        } while (patient.getPatientID() == "");
        return patient;
    }

public:
    void show() override
    {
        _showHeader("Add New Appointment");

        string appointmentID = _readAppointmentID();
        while (clsAppointmentData::findAppointmentIndex(appointmentID) != -1)
        {
            cout << "Appointment ID already exists. Enter another ID: ";
            appointmentID = clsInputValidate<string>::ReadString();
        }

        clsDoctor doctor = _chooseDoctor();
        clsPatient patient = _choosePatient();

        if (clsAppointmentData::hasScheduledAppointment(doctor.getDoctorID(), patient.getPatientID()))
        {
            cout << "\nError: There is already a scheduled appointment for this doctor and patient.\n";
            _pauseScreen();
            return;
        }

        string date = clsInputValidate<string>::ReadString("Enter Date (DD-MM-YYYY): ");
        // Validate date
        while (!clsDate::IsValidDate(date))
        {
            cout << "Invalid date format. Use DD-MM-YYYY.\n";
            date = clsInputValidate<string>::ReadString("Enter Date (DD-MM-YYYY): ");
        }

        clsAppointment newAppointment(appointmentID, doctor, patient, date,clsAppointment::enAppointmentStatus::Scheduled);

        if (clsAppointmentData::addAppointment(newAppointment))
        {
            cout << "\nAppointment added successfully.\n";
        }
        else
        {
            cout << "\nError: Failed to add appointment.\n";
        }

        _pauseScreen();
    }
};

#endif // __CLSADDAPPOINTMENTSCREEN_H__