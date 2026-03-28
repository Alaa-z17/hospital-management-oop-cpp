#ifndef __CLSAPPOINTMENTDATA_H__
#define __CLSAPPOINTMENTDATA_H__

#include "Global.h"
#include "clsAppointment.h"
#include "clsDoctorData.h"
#include "clsPatientData.h"
#include <vector>

class clsAppointmentData
{
private:
    static vector<clsAppointment> _Appointments;
    static string _AppointmentsFile;

    static string _convertAppointmentToLine(const clsAppointment& appointment)
    {
        string line = "";
        line += appointment.getAppointmentID() + "|";
        line += appointment.getDoctor().getDoctorID() + "|";
        line += appointment.getPatient().getPatientID() + "|";
        line += appointment.getDate() + "|";
        line += clsAppointment::statusToString(appointment.getStatus()); // convert enum to string
        return line;
    }
    static clsAppointment _convertLineToAppointment(const string line)
    {
        vector<string> v = clsString::Split(line, "|");
        if (v.size() >= 5)
        {
            string appointmentID = v[0];
            string doctorID = v[1];
            string patientID = v[2];
            string date = v[3];
            clsAppointment::enAppointmentStatus status = clsAppointment::stringToStatus(v[4]);

            clsDoctor doctor = clsDoctorData::getDoctorByID(doctorID);
            clsPatient patient = clsPatientData::getPatientByID(patientID);

            clsAppointment appointment(appointmentID, doctor, patient, date, status);
            return appointment;
        }
        
        return clsAppointment();
    }
public:
    static void loadAppointments()
    {
        _Appointments.clear();
        fstream file;
        file.open(_AppointmentsFile, ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                _Appointments.push_back(_convertLineToAppointment(line));
            }
            file.close();
        }
    }

    static void saveAppointments()
    {
        fstream file;
        file.open(_AppointmentsFile, ios::out);
        if (file.is_open())
        {
            for (const auto& appointment : _Appointments)
            {
                file << _convertAppointmentToLine(appointment) << endl;
            }
            file.close();
        }
    }

    static const vector<clsAppointment>& getAppointments() { return _Appointments; }

    static int findAppointmentIndex(const string& appointmentID)
    {
        for (int i = 0; i < _Appointments.size(); i++)
        {
            if (_Appointments[i].getAppointmentID() == appointmentID)
                return i;
        }
        return -1;
    }

    static clsAppointment getAppointmentByID(const string& appointmentID)
    {
        int index = findAppointmentIndex(appointmentID);
        if (index != -1)
            return _Appointments[index];
        return clsAppointment();
    }

    static bool addAppointment(const clsAppointment& appointment)
    {
        if (findAppointmentIndex(appointment.getAppointmentID()) != -1)
            return false;
        _Appointments.push_back(appointment);
        saveAppointments();
        return true;
    }

    static bool updateAppointment(const clsAppointment& appointment)
    {
        int index = findAppointmentIndex(appointment.getAppointmentID());
        if (index == -1)
            return false;
        _Appointments[index] = appointment;
        saveAppointments();
        return true;
    }

    static bool deleteAppointment(const string& appointmentID)
    {
        int index = findAppointmentIndex(appointmentID);
        if (index == -1)
            return false;
        _Appointments.erase(_Appointments.begin() + index);
        saveAppointments();
        return true;
    }
	static bool CancelAppoint(clsAppointment& appt)
    {
        if (appt.getStatus() == clsAppointment::enAppointmentStatus::Completed)
            return false; // cannot cancel completed
        appt.setStatus(clsAppointment::enAppointmentStatus::Cancelled);
        updateAppointment(appt);
        return true;
    }
    static bool completeAppointment(clsAppointment& appt)
    {
        if (appt.getStatus() == clsAppointment::enAppointmentStatus::Cancelled)
            return false; // cannot complete cancelled

        //if Scheduled we can make it complete
        appt.setStatus(clsAppointment::enAppointmentStatus::Completed);
        updateAppointment(appt);
        return true;
    }
    static bool hasScheduledAppointment(const string& doctorID, const string& patientID)
    {
        for (const auto& appt : _Appointments)
        {
            if (appt.getDoctor().getDoctorID() == doctorID &&
                appt.getPatient().getPatientID() == patientID &&
                appt.getStatus() == clsAppointment::enAppointmentStatus::Scheduled)
            {
                return true;
            }
        }
        return false;
    }
};

#endif // __CLSAPPOINTMENTDATA_H__