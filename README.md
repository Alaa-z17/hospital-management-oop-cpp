# 🏥 Hospital Management System – C++ OOP Project

A complete Hospital Management System built with C++ demonstrating advanced OOP principles. The system manages patients, doctors, and appointments, with data persistence using file I/O and a console-based menu interface.


## 🎥 Video Tutorial

[![Student Management System C++ Tutorial](https://img.youtube.com/vi/vaqheLim6QE/0.jpg)](https://youtu.be/vaqheLim6QE)

*Click the image above to watch a complete walkthrough of the Student Management System!*

## ✨ Features

- **Patient Management** – Add, update, delete, list, and search for patients.
- **Doctor Management** – Add, update, delete, list, and search for doctors.
- **Appointment Management** – Create, cancel, complete, and list appointments.
- **Validation** – Email, phone, date, and range validation.
- **Data Persistence** – Saves data to text files (`patients.txt`, `doctors.txt`, `appointments.txt`).
- **Modular Design** – Separation of business logic, data access, and presentation.
- **OOP Concepts** – Inheritance, polymorphism, encapsulation, static members, vectors.

## 🧠 OOP Concepts Used

```text
|Concept | Implementation |
|--------|----------------|

| **Inheritance** | `clsPatient` and `clsDoctor` inherit from `clsPerson` |
| **Polymorphism** | Virtual functions (`printInfo`, `getID`) |
| **Encapsulation** | Private members with getters/setters |
| **Static Members** | Counters for total patients, doctors, appointments |
| **File I/O** | Reading/writing data to text files |
| **Vectors** | Store dynamic lists of objects |
```

## 📁 Project Structure

```text
hospital-management-oop-cpp/
├── hospital-management-oop-cpp.cpp // Main entry point
├── Global.h / Global.cpp // Global includes, constants, boot function
├── DataStatics.cpp // Static member initializations
├── Data/ // Created at runtime for data files
│ ├── patients.txt
│ ├── doctors.txt
│ └── appointments.txt
├── Business Layer
│ ├── clsPerson.h // Base class
│ ├── clsPatient.h // Inherits clsPerson
│ ├── clsDoctor.h // Inherits clsPerson
│ └── clsAppointment.h // Contains doctor, patient, status
├── Data Layer
│ ├── clsPatientData.h // File operations for patients
│ ├── clsDoctorData.h // File operations for doctors
│ └── clsAppointmentData.h // File operations for appointments
├── Libraries/
│ ├── clsString.h // String utilities
│ ├── clsDate.h // Date handling
│ └── clsInputValidate.h // Input validation (template)
└── Presentation Layer (Screens)
├── clsScreen.h // Base screen class
├── clsMainScreen.h // Main menu
├── clsPatientsManagementScreen.h // Patients submenu
├── clsDoctorsManagementScreen.h // Doctors submenu
├── clsAppointmentsManagementScreen.h // Appointments submenu
└── PatientScreens/, DoctorScreens/, AppointmentScreens/
├── Add / List / Delete / Update / Find / Cancel / Complete
```

## 🚀 Setup & Compilation

### Prerequisites

- C++ compiler (g++, MSVC, or Clang)
- Windows (for `system("cls")`) – modify `clsScreen.h` for Linux/Mac (use `system("clear")`)

### Build and Run

```bash
# Clone the repository
git clone https://github.com/your-username/hospital-management-oop-cpp.git
cd hospital-management-oop-cpp

# Compile
g++ -o hospital-system *.cpp

# Run
./hospital-system
On Windows, you can open the project in Visual Studio and build directly.

📄 License
This project is licensed under the MIT License – see the LICENSE file for details.
