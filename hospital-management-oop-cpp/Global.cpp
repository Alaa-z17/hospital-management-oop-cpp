#include "Global.h"
#include "clsPatientData.h"
#include "clsDoctorData.h"
#include "clsAppointmentData.h"

void SystemBoot()
{
    // Load data from files
    clsPatientData::loadPatients();
    clsDoctorData::loadDoctors();
    clsAppointmentData::loadAppointments();
}
