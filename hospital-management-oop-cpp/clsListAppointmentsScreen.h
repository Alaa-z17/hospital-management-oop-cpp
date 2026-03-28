#ifndef __CLSLISTAPPOINTMENTSSCREEN_H__
#define __CLSLISTAPPOINTMENTSSCREEN_H__

#include "clsScreen.h"
#include "clsAppointmentData.h"

class clsListAppointmentsScreen : public clsScreen
{
private:
    static void _printAppointmentRecord(const clsAppointment& appointment)
    {
        cout << "| " << setw(15) << left << appointment.getAppointmentID();
        cout << "| " << setw(12) << left << appointment.getDoctor().getDoctorID();
        cout << "| " << setw(20) << left << appointment.getDoctor().getFullName();
        cout << "| " << setw(12) << left << appointment.getPatient().getPatientID();
        cout << "| " << setw(20) << left << appointment.getPatient().getFullName();
        cout << "| " << setw(12) << left << appointment.getDate();
        cout << "| " << setw(12) << left << appointment.getStatusString();
        cout << "|" << endl;
    }

public:
    void show() override
    {
        _showHeader("List All Appointments");

        const auto& appointments = clsAppointmentData::getAppointments();

        if (appointments.size() == 0)
        {
            cout << "\nNo appointments found.\n";
        }
        else
        {
            cout << "\n___________________________________________________________________________________________________________\n";
            cout << "| " << left << setw(15) << "Appointment ID";
            cout << "| " << setw(12) << "Doctor ID";
            cout << "| " << setw(20) << "Doctor Name";
            cout << "| " << setw(12) << "Patient ID";
            cout << "| " << setw(20) << "Patient Name";
            cout << "| " << setw(12) << "Date";
            cout << "| " << setw(12) << "Status";
            cout << "|" << endl;
            cout << "___________________________________________________________________________________________________________\n";

            for (const auto& appointment : appointments)
            {
                _printAppointmentRecord(appointment);
            }
            cout << "___________________________________________________________________________________________________________\n";
            cout << "Total Appointments: " << appointments.size() << endl;
        }

        _pauseScreen();
    }
};

#endif // __CLSLISTAPPOINTMENTSSCREEN_H__