//
// Created by divergent / Doğukan ÖKSÜZ on 12/22/18.
//

#ifndef APPOINTMENT_APPOINTMENTTIME_H
#define APPOINTMENT_APPOINTMENTTIME_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
 * Bu class neden var?
 *
 * Randevu zamanını gerçeklemek için bir objeye daha ihtiyacımız vardı.
 */

class AppointmentTime
{
public:
    AppointmentTime();
    ~AppointmentTime();
    int setTime(string _Date, string _startTime, string _endTime);

    bool operator==(AppointmentTime otherOne);
    bool duplicate(int a, int aEnd, int b, int bEnd);

    const string &getAcademicianId() const;
    void setAcademicianId(const string &AcademicianId);

    const string &getStudentId() const;
    void setStudentId(const string &StudentId);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getStart_hour() const;
    int getStart_minute() const;
    int getEnd_hour() const;
    int getEnd_minute() const;

private:
    void parseDate(string _Date);
    void parseHour(string type, string _Hour);

    string AcademicianId;
    string StudentId;

    int day;
    int month;
    int year;

    int start_hour;
    int start_minute;

    int end_hour;
    int end_minute;
};

#endif //APPOINTMENT_APPOINTMENTTIME_H
