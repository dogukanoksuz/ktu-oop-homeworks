//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#include "../../include/Person/Student.h"


Student::Student() : Person()
{

}

Student::~Student()
{

}

const string &Student::getJoindate() const
{
    return Joindate;
}

void Student::setJoindate(const string &Joindate)
{
    Student::Joindate = Joindate;
}

