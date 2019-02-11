//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#ifndef APPOINTMENT_ACADEMICIAN_H
#define APPOINTMENT_ACADEMICIAN_H

#include "../Person.h"

/*
 * Person inherit edilmiş bir class, farklı özellikleri implemente etmek için var.
 */

class Academician : public Person
{
public:
    Academician();
    virtual ~Academician();

    const string &getDegree() const;
    void setDegree(const string &Degree);

protected:
    string Degree;
};


#endif //APPOINTMENT_ACADEMICIAN_H
