#ifndef __CLSAPPOINTMENTSMANAGEMENTSCREEN_H__
#define __CLSAPPOINTMENTSMANAGEMENTSCREEN_H__

#include "clsScreen.h"
#include "clsListAppointmentsScreen.h"
#include "clsAddAppointmentScreen.h"
#include "clsCancelAppointmentScreen.h"
#include "clsCompleteAppointmentScreen.h"

class clsAppointmentsManagementScreen : public clsScreen
{
private:
    enum enAppointmentsMenuOptions
    {
        eListAppointments = 1,
        eAddAppointment,
        eCancelAppointment,
        eCompleteAppointment,
        eBackToMainMenu
    };

    static enAppointmentsMenuOptions _showMenu()
    {
        _clearScreen();
        _showHeader("Appointments Management");
        cout << " 1. List All Appointments" << endl;
        cout << " 2. Add New Appointment" << endl;
        cout << " 3. Cancel Appointment" << endl;
        cout << " 4. Mark Appointment as Completed" << endl;
        cout << " 5. Back to Main Menu" << endl;
        cout << "===========================================" << endl;
        cout << "Choose option (1-5): ";
        short choice = clsInputValidate<short>::ReadNumberBetween( 1, 5);
        return static_cast<enAppointmentsMenuOptions>(choice);
    }

public:
    void show() override
    {
        enAppointmentsMenuOptions choice;
        do {
            choice = _showMenu();
            switch (choice)
            {
            case eListAppointments:
            {
                clsListAppointmentsScreen listScreen;
                listScreen.show();
                break;
            }
            case eAddAppointment:
            {
                clsAddAppointmentScreen addScreen;
                addScreen.show();
                break;
            }
            case eCancelAppointment:
            {
                clsCancelAppointmentScreen cancelScreen;
                cancelScreen.show();
                break;
            }
            case eCompleteAppointment:
            {
                clsCompleteAppointmentScreen completeScreen;
                completeScreen.show();
                break;
            }
            case eBackToMainMenu:
                break;
            }
        } while (choice != eBackToMainMenu);
    }
};

#endif // __CLSAPPOINTMENTSMANAGEMENTSCREEN_H__