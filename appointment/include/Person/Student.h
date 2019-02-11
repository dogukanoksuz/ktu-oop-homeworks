//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#ifndef APPOINTMENT_STUDENT_H
#define APPOINTMENT_STUDENT_H

#include "../Person.h"

/*
 * Person inherit edilmiş bir class, farklı özellikleri implemente etmek için var.
 */

class Student : public Person
{
public:
    Student();
    virtual ~Student();

    const string &getJoindate() const;
    void setJoindate(const string &Joindate);

protected:
    string Joindate;
};


#endif //APPOINTMENT_STUDENT_H
