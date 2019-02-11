//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#ifndef APPOINTMENT_APPOINTMENT_H
#define APPOINTMENT_APPOINTMENT_H

#include <iostream>
#include <string>
#include <fstream>
#include "Time/AppointmentTime.h"
#include "Person/Academician.h"
#include "Person/Student.h"

using namespace std;

/*
 * Bu class neden var?
 *
 * Genel olarak randevuların işlediği sistem class'ımız bu.
 * Ekleme, bastırma vs. işlemleri burada yapıyoruz.
 * Ayrıca öğrencilerin, randevuların, akademisyenlerin bilgilerini
 * bu class içerisindeki arraylerde depoluyoruz.
 */

class Appointment
{
public:
    Appointment(string _Student, string _Academician, string _Appointment);
    virtual ~Appointment();

    // add person functions
    void addStudent();
    void addAcademician();
    void addAppointment();

    // print functions
    void printStudents();
    void printAcademicians();
    void printAppointments();
    void printStudentsAppointment();
    void printAcademiciansAppointment();

private:
    // private functions
    void fetchStudents();
    void fetchAcademicians();
    void fetchAppointments();
    int dupeChecker(string acId, string stId, string date1, string start, string end);
    void getAcademiciansAppointments(string Id);

    // file reading
    ifstream if_Student;
    ifstream if_Academician;
    ifstream if_Appointment;

    // file writing
    ofstream of_Student;
    ofstream of_Academician;
    ofstream of_Appointment;

    // file names
    string file_Student;
    string file_Academician;
    string file_Appointment;

    // arrays
    Academician *academicians;
    Student *students;
    AppointmentTime *appointments;

    // counters
    int StudentCounter;
    int AcademicianCounter;
    int AppointmentCounter;
};


#endif //APPOINTMENT_APPOINTMENT_H
