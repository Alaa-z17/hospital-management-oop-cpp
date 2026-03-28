#ifndef __CLSPATIENTDATA_H__
#define __CLSPATIENTDATA_H__

#include "Global.h"
#include "clsPatient.h"
#include <vector>

class clsPatientData
{
private:
    static vector<clsPatient> _Patients;
    static string _PatientsFile;

    // Convert patient object to line (for saving)
    static string _convertPatientToLine(const clsPatient& patient)
    {
        string line = "";
        line += patient.getPatientID() + "|";
        line += patient.getFirstName() + "|";
        line += patient.getLastName() + "|";
        line += patient.getPhone() + "|";
        line += patient.getEmail() + "|";
        line += to_string(patient.getAge()) + "|";
        line += patient.getDiagnosis() + "|";
        line += patient.getBloodType();
        return line;
    }

    // Convert line from file to patient object
    static clsPatient _convertLineToPatient(const string& line)
    {
        vector<string> v = clsString::Split(line, "|");
        // v[0]=PatientID, v[1]=FirstName, v[2]=LastName, v[3]=Phone, v[4]=Email,
        // v[5]=Age, v[6]=Diagnosis, v[7]=BloodType
        return clsPatient(v[1], v[2], v[3], v[4], stoi(v[5]),
            v[0], v[6], v[7]);
    }

public:
    // Load patients from file
    static void loadPatients()
    {
        _Patients.clear();
        fstream file;
        file.open(_PatientsFile, ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                _Patients.push_back(_convertLineToPatient(line));
            }
            file.close();
        }
    }

    // Save patients to file
    static void savePatients()
    {
        fstream file;
        file.open(_PatientsFile, ios::out);
        if (file.is_open())
        {
            for (const auto& patient : _Patients)
            {
                file << _convertPatientToLine(patient) << endl;
            }
            file.close();
        }
    }

    // Get all patients (const reference)
    static const vector<clsPatient>& getPatients() { return _Patients; }

    // Find patient by ID
    static int findPatientIndex(const string& patientID)
    {
        for (int i = 0; i < _Patients.size(); i++)
        {
            if (_Patients[i].getPatientID() == patientID)
                return i;
        }
        return -1;
    }

    // Get patient by ID (returns copy or default)
    static clsPatient getPatientByID(const string& patientID)
    {
        int index = findPatientIndex(patientID);
        if (index != -1)
            return _Patients[index];
        return clsPatient(); // empty
    }

    // Add new patient
    static bool addPatient(const clsPatient& patient)
    {
        if (findPatientIndex(patient.getPatientID()) != -1)
            return false; // ID already exists
        _Patients.push_back(patient);
        savePatients();
        return true;
    }

    // Update existing patient
    static bool updatePatient(const clsPatient& patient)
    {
        int index = findPatientIndex(patient.getPatientID());
        if (index == -1)
            return false;
        _Patients[index] = patient;
        savePatients();
        return true;
    }

    // Delete patient by ID
    static bool deletePatient(const string& patientID)
    {
        int index = findPatientIndex(patientID);
        if (index == -1)
            return false;
        _Patients.erase(_Patients.begin() + index);
        savePatients();
        return true;
    }
};

#endif // __CLSPATIENTDATA_H__