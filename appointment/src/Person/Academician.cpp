//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#include "../../include/Person/Academician.h"

Academician::Academician() : Person()
{

}

Academician::~Academician()
{

}

const string &Academician::getDegree() const
{
    return Degree;
}

void Academician::setDegree(const string &Degree)
{
    Academician::Degree = Degree;
}
