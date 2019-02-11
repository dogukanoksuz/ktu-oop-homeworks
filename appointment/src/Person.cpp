//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#include "../include/Person.h"

Person::Person()
{

}

Person::~Person()
{

}

const string &Person::getName() const
{
    return Name;
}

void Person::setName(const string &Name)
{
    Person::Name = Name;
}

const string &Person::getSurname() const
{
    return Surname;
}

void Person::setSurname(const string &Surname)
{
    Person::Surname = Surname;
}

const string &Person::getDepartment() const
{
    return Department;
}

void Person::setDepartment(const string &Department)
{
    Person::Department = Department;
}

const string &Person::getPhonenumber() const
{
    return Phonenumber;
}

void Person::setPhonenumber(const string &Phonenumber)
{
    Person::Phonenumber = Phonenumber;
}

const string &Person::getMail() const
{
    return Mail;
}

void Person::setMail(const string &Mail)
{
    Person::Mail = Mail;
}

const string &Person::getId() const
{
    return Id;
}

void Person::setId(const string &Id)
{
    Person::Id = Id;
}

