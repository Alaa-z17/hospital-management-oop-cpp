#ifndef __CLSCOMPLETEAPPOINTMENTSCREEN_H__
#define __CLSCOMPLETEAPPOINTMENTSCREEN_H__

#include "clsScreen.h"
#include "clsAppointmentData.h"
#include "clsAppointment.h"

class clsCompleteAppointmentScreen : public clsScreen
{
public:
    void show() override
    {
        _showHeader("Complete Appointment");

        string apptID = _readAppointmentID();
        int index = clsAppointmentData::findAppointmentIndex(apptID);

        if (index == -1)
        {
            cout << "\nAppointment with ID " << apptID << " not found.\n";
        }
        else
        {
            clsAppointment appt = clsAppointmentData::getAppointments()[index];

            // Show appointment details
            cout << "\nAppointment Details:\n";
            appt.printInfo();

            if (appt.getStatus() == clsAppointment::enAppointmentStatus::Completed)
            {
                cout << "\nThis appointment is already completed.\n";
            }
            else if (appt.getStatus() == clsAppointment::enAppointmentStatus::Cancelled)
            {
                cout << "\nCannot complete a cancelled appointment.\n";
            }
            else
            {
                char confirm;
                cout << "\nAre you sure you want to mark this appointment as completed? (y/n): ";
                cin >> confirm;
                cin.ignore();

                if (tolower(confirm) == 'y')
                {
                    
                    if (clsAppointmentData::completeAppointment(appt))
                        cout << "\nAppointment marked as completed successfully.\n";
                    else
                        cout << "\nError: Could not complete appointment (maybe already cancelled).\n";
                }
                else
                {
                    cout << "\nOperation aborted.\n";
                }
            }
        }

        _pauseScreen();
    }
};

#endif // __CLSCOMPLETEAPPOINTMENTSCREEN_H__