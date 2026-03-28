#ifndef __CLSCANCELAPPOINTMENTSCREEN_H__
#define __CLSCANCELAPPOINTMENTSCREEN_H__

#include "clsScreen.h"
#include "clsAppointmentData.h"

class clsCancelAppointmentScreen : public clsScreen
{
  
public:
    void show() override
    {
        _showHeader("Cancel Appointment");

        string appointmentID = _readAppointmentID();
        int index = clsAppointmentData::findAppointmentIndex(appointmentID);
        if (index == -1)
        {
            cout << "\nAppointment with ID " << appointmentID << " not found.\n";
        }
        else
        {
            clsAppointment appointment = clsAppointmentData::getAppointments()[index];
            cout << "\nAppointment found:\n";
            appointment.printInfo();

            char confirm;
            cout << "\nAre you sure you want to cancel this appointment? (y/n): ";
            cin >> confirm;
            cin.ignore();

            if (tolower(confirm) == 'y')
            {
                
                if (clsAppointmentData::CancelAppoint(appointment))
                {
                    cout << "\nAppointment cancelled successfully.\n";
                }
                else
                {
                    cout << "\nError: Could not cancel appointment.\n";
                }
            }
            else
            {
                cout << "\nCancellation cancelled.\n";
            }
        }

        _pauseScreen();
    }
};

#endif // __CLSCANCELAPPOINTMENTSCREEN_H__