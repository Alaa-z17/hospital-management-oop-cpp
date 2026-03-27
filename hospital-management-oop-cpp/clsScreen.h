#ifndef __CLSSCREEN_H__
#define __CLSSCREEN_H__

#include "Global.h"

class clsScreen
{
protected:
    // Common methods for all screens
    static void _clearScreen()
    {
        system("cls");  // For Windows
        // system("clear"); // For Linux/Mac
    }

    static void _pauseScreen()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    static void _showHeader(string title)
    {
        _clearScreen();
        cout << "\n===========================================" << endl;
        cout << "  " << title << endl;
        cout << "===========================================" << endl;
    }

    //Patient 
    static string _readPatientID()
    {
        string id;
        cout << "Enter Patient ID: ";
        id = clsInputValidate<string>::ReadString();
        return id;
    }
    //Doctor
    static string _readDoctorID()
    {
        string id;
        cout << "Enter Doctor ID: ";
        getline(cin, id);
        return id;
    }
public:
    // Pure virtual function to be overridden by each screen
    virtual void show() = 0;
};

#endif // __CLSSCREEN_H__