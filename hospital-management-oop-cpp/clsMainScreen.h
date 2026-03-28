#ifndef __CLSMAINSCREEN_H__
#define __CLSMAINSCREEN_H__

#include "clsScreen.h"
#include "clsPatientsManagementScreen.h"
#include "clsDoctorsManagementScreen.h"
#include "clsAppointmentsManagementScreen.h"

class clsMainScreen : public clsScreen
{
private:
    enum enMainMenuOptions
    {
        ePatientsManagement = 1,
        eDoctorsManagement,
        eAppointmentsManagement,
        eExit
    };

    static enMainMenuOptions _showMainMenu()
    {
        _clearScreen();
        _showHeader("Hospital Management System");
        cout << "            Main Menu" << endl;
        cout << "===========================================" << endl;
        cout << " 1. Patients Management" << endl;
        cout << " 2. Doctors Management" << endl;
        cout << " 3. Appointments Management" << endl;
        cout << " 4. Exit" << endl;
        cout << "===========================================" << endl;
        cout << "Choose option (1-4): ";
        short choice = clsInputValidate<short>::ReadNumberBetween(1, 4);
        return static_cast<enMainMenuOptions>(choice);
    }

public:
    void show() override
    {
        enMainMenuOptions choice;
        do {
            choice = _showMainMenu();
            switch (choice)
            {
            case ePatientsManagement:
            {
                clsPatientsManagementScreen patientsScreen;
                patientsScreen.show();
                break;
            }
            case eDoctorsManagement:
            {
                clsDoctorsManagementScreen doctorsScreen;
                doctorsScreen.show();
                break;
            }
            case eAppointmentsManagement:
            {
                clsAppointmentsManagementScreen appointmentsScreen;
                appointmentsScreen.show();
                break;
            }
            case eExit:
                _clearScreen();
                cout << "Thank you for using the Hospital Management System. Goodbye!\n";
                break;
            }
        } while (choice != eExit);
    }
};

#endif // __CLSMAINSCREEN_H__