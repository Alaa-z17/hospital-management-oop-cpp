#ifndef __CLSLISTDOCTORSSCREEN_H__
#define __CLSLISTDOCTORSSCREEN_H__

#include "clsScreen.h"
#include "clsDoctorData.h"

class clsListDoctorsScreen : public clsScreen
{
private:
    static void _printDoctorRecord(const clsDoctor& doctor)
    {
        cout << "| " << setw(10) << left << doctor.getDoctorID();
        cout << "| " << setw(20) << left << doctor.getFullName();
        cout << "| " << setw(15) << left << doctor.getPhone();
        cout << "| " << setw(25) << left << doctor.getEmail();
        cout << "| " << setw(5) << left << doctor.getAge();
        cout << "| " << setw(20) << left << doctor.getSpecialization();
        cout << "| " << setw(10) << left << fixed << setprecision(2) << doctor.getConsultationFee();
        cout << "|" << endl;
    }

public:
    void show() override
    {
        _showHeader("List All Doctors");

        const auto& doctors = clsDoctorData::getDoctors();

        if (doctors.size() == 0)
        {
            cout << "\nNo doctors found.\n";
        }
        else
        {
            cout << "\n___________________________________________________________________________________________________________________\n";
            cout << "| " << left << setw(10) << "Doctor ID";
            cout << "| " << setw(20) << "Name";
            cout << "| " << setw(15) << "Phone";
            cout << "| " << setw(25) << "Email";
            cout << "| " << setw(5) << "Age";
            cout << "| " << setw(20) << "Specialization";
            cout << "| " << setw(10) << "Fee";
            cout << "|" << endl;
            cout << "___________________________________________________________________________________________________________________\n";

            for (const auto& doctor : doctors)
            {
                _printDoctorRecord(doctor);
            }
            cout << "___________________________________________________________________________________________________________________\n";
            cout << "Total Doctors: " << doctors.size() << endl;
        }

        _pauseScreen();
    }
};

#endif // __CLSLISTDOCTORSSCREEN_H__