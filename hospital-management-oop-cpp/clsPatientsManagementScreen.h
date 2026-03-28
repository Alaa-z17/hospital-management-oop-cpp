#ifndef __CLSPATIENTSMANAGEMENTSCREEN_H__
#define __CLSPATIENTSMANAGEMENTSCREEN_H__

#include "clsScreen.h"
#include "clsListPatientsScreen.h"
#include "clsAddPatientScreen.h"
#include "clsDeletePatientScreen.h"
#include "clsUpdatePatientScreen.h"
#include "clsFindPatientScreen.h"

class clsPatientsManagementScreen : public clsScreen
{
private:
    enum enPatientsMenuOptions
    {
        eListPatients = 1,
        eAddPatient,
        eDeletePatient,
        eUpdatePatient,
        eFindPatient,
        eBackToMainMenu
    };

    static enPatientsMenuOptions _showMenu()
    {
        _clearScreen();
        _showHeader("Patients Management");
        cout << " 1. List All Patients" << endl;
        cout << " 2. Add New Patient" << endl;
        cout << " 3. Delete Patient" << endl;
        cout << " 4. Update Patient" << endl;
        cout << " 5. Find Patient" << endl;
        cout << " 6. Back to Main Menu" << endl;
        cout << "===========================================" << endl;
        cout << "Choose option (1-6): ";
        short choice = clsInputValidate<short>::ReadNumberBetween(1, 6);
        return static_cast<enPatientsMenuOptions>(choice);
    }

public:
    void show() override
    {
        enPatientsMenuOptions choice;
        do {
            choice = _showMenu();
            switch (choice)
            {
            case eListPatients:
            {
                clsListPatientsScreen listScreen;
                listScreen.show();
                break;
            }
            case eAddPatient:
            {
                clsAddPatientScreen addScreen;
                addScreen.show();
                break;
            }
            case eDeletePatient:
            {
                clsDeletePatientScreen deleteScreen;
                deleteScreen.show();
                break;
            }
            case eUpdatePatient:
            {
                clsUpdatePatientScreen updateScreen;
                updateScreen.show();
                break;
            }
            case eFindPatient:
            {
                clsFindPatientScreen findScreen;
                findScreen.show();
                break;
            }
            case eBackToMainMenu:
                break;
            }
        } while (choice != eBackToMainMenu);
    }
};

#endif // __CLSPATIENTSMANAGEMENTSCREEN_H__