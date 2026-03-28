#include "clsPatientData.h"
#include "clsDoctorData.h"
#include "clsAppointmentData.h"
#include "clsPatient.h"
#include "clsDoctor.h"
#include "clsAppointment.h"
#include "clsPerson.h"

// Static member definitions for data classes

std::vector<clsPatient> clsPatientData::_Patients;
std::string clsPatientData::_PatientsFile = PATIENTS_FILE;

std::vector<clsDoctor> clsDoctorData::_Doctors;
std::string clsDoctorData::_DoctorsFile = DOCTORS_FILE;

std::vector<clsAppointment> clsAppointmentData::_Appointments;
std::string clsAppointmentData::_AppointmentsFile = APPOINTMENTS_FILE;

// Static counters for classes
int clsPatient::_TotalPatients = 0;
int clsDoctor::_TotalDoctors = 0;
int clsAppointment::_TotalAppointments = 0;
int clsPerson::_TotalPersons = 0;
