#ifndef __CLSDOCTORSMANAGEMENTSCREEN_H__
#define __CLSDOCTORSMANAGEMENTSCREEN_H__

#include "clsScreen.h"
#include "clsListDoctorsScreen.h"
#include "clsAddDoctorScreen.h"
#include "clsDeleteDoctorScreen.h"
#include "clsUpdateDoctorScreen.h"
#include "clsFindDoctorScreen.h"

class clsDoctorsManagementScreen : public clsScreen
{
private:
    enum enDoctorsMenuOptions
    {
        eListDoctors = 1,
        eAddDoctor,
        eDeleteDoctor,
        eUpdateDoctor,
        eFindDoctor,
        eBackToMainMenu
    };

    static enDoctorsMenuOptions _showMenu()
    {
        _clearScreen();
        _showHeader("Doctors Management");
        cout << " 1. List All Doctors" << endl;
        cout << " 2. Add New Doctor" << endl;
        cout << " 3. Delete Doctor" << endl;
        cout << " 4. Update Doctor" << endl;
        cout << " 5. Find Doctor" << endl;
        cout << " 6. Back to Main Menu" << endl;
        cout << "===========================================" << endl;
        cout << "Choose option (1-6): ";
        short choice = clsInputValidate<short>::ReadNumberBetween( 1, 6);
        return static_cast<enDoctorsMenuOptions>(choice);
    }

public:
    void show() override
    {
        enDoctorsMenuOptions choice;
        do {
            choice = _showMenu();
            switch (choice)
            {
            case eListDoctors:
            {
                clsListDoctorsScreen listScreen;
                listScreen.show();
                break;
            }
            case eAddDoctor:
            {
                clsAddDoctorScreen addScreen;
                addScreen.show();
                break;
            }
            case eDeleteDoctor:
            {
                clsDeleteDoctorScreen deleteScreen;
                deleteScreen.show();
                break;
            }
            case eUpdateDoctor:
            {
                clsUpdateDoctorScreen updateScreen;
                updateScreen.show();
                break;
            }
            case eFindDoctor:
            {
                clsFindDoctorScreen findScreen;
                findScreen.show();
                break;
            }
            case eBackToMainMenu:
                break;
            }
        } while (choice != eBackToMainMenu);
    }
};

#endif // __CLSDOCTORSMANAGEMENTSCREEN_H__