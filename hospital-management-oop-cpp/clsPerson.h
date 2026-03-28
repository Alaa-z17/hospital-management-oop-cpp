#ifndef __CLSPERSON_H__
#define __CLSPERSON_H__

#include "Global.h"

class clsPerson
{
protected:
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;
    short  _Age;

    static int _TotalPersons;

public:
    // Constructors
    clsPerson() : _FirstName(""), _LastName(""), _Phone(""), _Email(""), _Age(0)
    {
        _TotalPersons++;
    }

    clsPerson(string firstName, string lastName, string phone, string email, short age)
        : _FirstName(firstName), _LastName(lastName), _Phone(phone), _Email(email), _Age(age)
    {
        _TotalPersons++;
    }

    virtual ~clsPerson()
    {
        _TotalPersons--;
    }

    // ----- Getters & Setters (standard methods) -----
    void setFirstName(string firstName) { _FirstName = firstName; }
    string getFirstName() const { return _FirstName; }

    void setLastName(string lastName) { _LastName = lastName; }
    string getLastName() const { return _LastName; }

    void setPhone(string phone) { _Phone = phone; }
    string getPhone() const { return _Phone; }

    void setEmail(string email) { _Email = email; }
    string getEmail() const { return _Email; }

    void setAge(short age) { _Age = age; }
    short getAge() const { return _Age; }

    string getFullName() const
    {
        return _FirstName + " " + _LastName;
    }

    // ----- Microsoft-specific properties (if using Visual C++) -----
#ifdef _MSC_VER
    __declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
    __declspec(property(get = getLastName, put = setLastName)) string LastName;
    __declspec(property(get = getPhone, put = setPhone)) string Phone;
    __declspec(property(get = getEmail, put = setEmail)) string Email;
    __declspec(property(get = getAge, put = setAge)) short Age;
    __declspec(property(get = getFullName)) string FullName;
#endif

    static int getTotalPersons() { return _TotalPersons; }

    virtual void printInfo() const
    {
        cout << "\n=================================" << endl;
        cout << "Person Information:" << endl;
        cout << "=================================" << endl;
        cout << "Name  : " << getFullName() << endl;
        cout << "Phone : " << _Phone << endl;
        cout << "Email : " << _Email << endl;
        cout << "Age   : " << _Age << endl;
    }

    virtual string getID() const = 0;
};

#endif // __CLSPERSON_H__