#ifndef __CLSDOCTORDATA_H__
#define __CLSDOCTORDATA_H__

#include "Global.h"
#include "clsDoctor.h"
#include <vector>

class clsDoctorData
{
private:
    static vector<clsDoctor> _Doctors;
    static string _DoctorsFile;

    static string _convertDoctorToLine(const clsDoctor& doctor)
    {
        string line = "";
        line += doctor.getDoctorID() + "|";
        line += doctor.getFirstName() + "|";
        line += doctor.getLastName() + "|";
        line += doctor.getPhone() + "|";
        line += doctor.getEmail() + "|";
        line += to_string(doctor.getAge()) + "|";
        line += doctor.getSpecialization() + "|";
        line += to_string(doctor.getConsultationFee());
        return line;
    }

    static clsDoctor _convertLineToDoctor(const string& line)
    {
        vector<string> v = clsString::Split(line, "|");
        return clsDoctor(v[1], v[2], v[3], v[4], stoi(v[5]),
            v[0], v[6], stof(v[7]));
    }

public:
    static void loadDoctors()
    {
        _Doctors.clear();
        fstream file;
        file.open(_DoctorsFile, ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                _Doctors.push_back(_convertLineToDoctor(line));
            }
            file.close();
        }
    }

    static void saveDoctors()
    {
        fstream file;
        file.open(_DoctorsFile, ios::out);
        if (file.is_open())
        {
            for (const auto& doctor : _Doctors)
            {
                file << _convertDoctorToLine(doctor) << endl;
            }
            file.close();
        }
    }

    static const vector<clsDoctor>& getDoctors() { return _Doctors; }

    static int findDoctorIndex(const string& doctorID)
    {
        for (size_t i = 0; i < _Doctors.size(); i++)
        {
            if (_Doctors[i].getDoctorID() == doctorID)
                return i;
        }
        return -1;
    }

    static clsDoctor getDoctorByID(const string& doctorID)
    {
        int index = findDoctorIndex(doctorID);
        if (index != -1)
            return _Doctors[index];
        return clsDoctor();
    }

    static bool addDoctor(const clsDoctor& doctor)
    {
        if (findDoctorIndex(doctor.getDoctorID()) != -1)
            return false;
        _Doctors.push_back(doctor);
        saveDoctors();
        return true;
    }

    static bool updateDoctor(const clsDoctor& doctor)
    {
        int index = findDoctorIndex(doctor.getDoctorID());
        if (index == -1)
            return false;
        _Doctors[index] = doctor;
        saveDoctors();
        return true;
    }

    static bool deleteDoctor(const string& doctorID)
    {
        int index = findDoctorIndex(doctorID);
        if (index == -1)
            return false;
        _Doctors.erase(_Doctors.begin() + index);
        saveDoctors();
        return true;
    }
};

vector<clsDoctor> clsDoctorData::_Doctors;
string clsDoctorData::_DoctorsFile = DOCTORS_FILE;

#endif // __CLSDOCTORDATA_H__