//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#ifndef APPOINTMENT_PERSON_H
#define APPOINTMENT_PERSON_H

#include <string>
using namespace std;

/*
 * Bu class neden var?
 *
 * DRY kuralına uyup, kişiden nitelikli kişiler türetmek için.
 */

class Person
{
public:
    Person();
    virtual ~Person();

    // getter and setter functions
    const string &getId() const;
    void setId(const string &Id);

    const string &getName() const;
    void setName(const string &Name);

    const string &getSurname() const;
    void setSurname(const string &Surname);

    const string &getDepartment() const;
    void setDepartment(const string &Department);

    const string &getPhonenumber() const;
    void setPhonenumber(const string &Phonenumber);

    const string &getMail() const;
    void setMail(const string &Mail);

protected:
    string Id;
    string Name;
    string Surname;
    string Department;
    string Mail;
    string Phonenumber;
};


#endif //APPOINTMENT_PERSON_H
