//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#ifndef APPOINTMENT_MENU_H
#define APPOINTMENT_MENU_H

#include <iostream>
#include "Appointment.h"
using namespace std;

/*
 * Bu class neden var?
 *
 * Modüler programlamaya uyup Appointment class'ındaki fonksiyonları çağırmak için.
 * Constructor olarak içeri üç veri alır, dosya bilgileri.
 *
 * Basit switch ile yazılmış menü.
 */

class Menu
{
public:
    Menu();
    Menu(string, string, string);
    virtual ~Menu();

private:
    void show();
    void start(Appointment& system);
};


#endif //APPOINTMENT_MENU_H
