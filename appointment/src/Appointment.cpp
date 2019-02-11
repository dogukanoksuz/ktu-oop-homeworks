//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#include "../include/Appointment.h"

#define SIZE 100

/*
 * Neden dosyaları her seferinde açıp kapattım?
 *
 * Üstüne yazma problemleri, karakter problemleri vs. yaşadığımdan
 * dosyaları her işlem yaptığımda açıp kapattım.
 */

Appointment::Appointment(string _Student, string _Academician, string _Appointment)
{
    // implement dynamic allocated array
    academicians = new Academician[SIZE];
    students = new Student[SIZE];
    appointments = new AppointmentTime[SIZE];

    StudentCounter = 0, AcademicianCounter = 0, AppointmentCounter = 0;

    Appointment::file_Student = _Student;
    Appointment::file_Academician = _Academician;
    Appointment::file_Appointment = _Appointment;

    // fetch from file and add to array
    fetchAcademicians();
    fetchStudents();
    fetchAppointments();
}

Appointment::~Appointment()
{
    delete[]academicians;
    delete[]students;
    delete[]appointments;

    if_Student.close();
    if_Academician.close();
    if_Appointment.close();

    of_Student.close();
    of_Academician.close();
    of_Appointment.close();
}

void Appointment::fetchAcademicians()
{
    // Akademisyenleri içeri alıp dosyayı kapatıyoruz.
    if_Academician.open(file_Academician);

    string temp;
    while (!if_Academician.eof())
    {
        if (if_Academician >> temp)
        {
            academicians[AcademicianCounter].setId(temp);
            if_Academician >> temp;
            academicians[AcademicianCounter].setName(temp);
            if_Academician >> temp;
            academicians[AcademicianCounter].setSurname(temp);
            if_Academician >> temp;
            academicians[AcademicianCounter].setDepartment(temp);
            if_Academician >> temp;
            academicians[AcademicianCounter].setMail(temp);
            if_Academician >> temp;
            academicians[AcademicianCounter].setPhonenumber(temp);
            if_Academician >> temp;
            academicians[AcademicianCounter].setDegree(temp);
        }
        AcademicianCounter++;
    }

    if_Academician.close();
}

void Appointment::fetchStudents()
{
    // Öğrencileri içeri alıp dosyayı kapatıyoruz.
    if_Student.open(file_Student);

    string temp;
    while (!if_Student.eof())
    {
        if (if_Student >> temp)
        {
            students[StudentCounter].setId(temp);
            if_Student >> temp;
            students[StudentCounter].setName(temp);
            if_Student >> temp;
            students[StudentCounter].setSurname(temp);
            if_Student >> temp;
            students[StudentCounter].setDepartment(temp);
            if_Student >> temp;
            students[StudentCounter].setJoindate(temp);
            if_Student >> temp;
            students[StudentCounter].setMail(temp);
            if_Student >> temp;
            students[StudentCounter].setPhonenumber(temp);
        }
        StudentCounter++;
    }

    if_Student.close();
}

void Appointment::fetchAppointments()
{
    // Randevuları içeri alıp dosyayı kapatıyoruz.
    if_Appointment.open(file_Appointment);

    string temp;
    string temp2;
    string temp3;
    while (!if_Appointment.eof())
    {
        if (if_Appointment >> temp)
        {
            appointments[AppointmentCounter].setStudentId(temp);
            if_Appointment >> temp;
            appointments[AppointmentCounter].setAcademicianId(temp);
            if_Appointment >> temp;
            if_Appointment >> temp2;
            if_Appointment >> temp3;
            appointments[AppointmentCounter].setTime(temp, temp2, temp3);
        }
        AppointmentCounter++;
    }

    if_Appointment.close();
}

void Appointment::addStudent()
{
    // Öğrenci ekleme fonksiyonu
    string buffer;
    string tempBuffer;

    if_Student.open(file_Student);
    // Tüm dosyayı içeri alıp bufferimize atıyoruz.
    while (getline(if_Student, tempBuffer))
        buffer += tempBuffer + '\n';
    if_Student.close();

    cout << "Öğrenci Ekleme: (Ekleyeceğiniz girdiler boşluksuz olmalıdır.)" << endl << endl;

    of_Student.open(file_Student, ios::app);

    string tempGet;
    // Bufferimizde öğrenci numarası yoksa öğrenci numarasını ekliyoruz.
    do
    {
        cout << "Öğrenci Numarasını giriniz:" << endl;
        cin >> tempGet;
        tempGet += ' ';
    } while (buffer.find(tempGet, 0) != string::npos && cout << "Öğrenci numarası kullanılıyor." << endl << endl);
    students[StudentCounter].setId(tempGet);
    of_Student << '\n' + tempGet;

    cout << "İsminizi giriniz:" << endl;
    cin >> tempGet;
    students[StudentCounter].setName(tempGet);
    of_Student << tempGet + ' ';

    cout << "Soyisminizi giriniz:" << endl;
    cin >> tempGet;
    students[StudentCounter].setSurname(tempGet);
    of_Student << tempGet + ' ';

    cout << "Bölümünüzü giriniz:" << endl;
    cin >> tempGet;
    students[StudentCounter].setDepartment(tempGet);
    of_Student << tempGet + ' ';

    cout << "Katıldığınız yılı giriniz:" << endl;
    cin >> tempGet;
    students[StudentCounter].setJoindate(tempGet);
    of_Student << tempGet + ' ';

    cout << "Email adresinizi giriniz:" << endl;
    cin >> tempGet;
    students[StudentCounter].setMail(tempGet);
    of_Student << tempGet + ' ';

    cout << "Telefon numaranızı giriniz:" << endl;
    cin >> tempGet;
    students[StudentCounter].setPhonenumber(tempGet);
    of_Student << tempGet;

    // Öğrenciyi ekledikten sonra dosyayı kapatıyoruz.
    of_Student.close();
    cout << "Öğrenci başarıyla eklendi..." << endl;
}

void Appointment::addAcademician()
{
    // Fonksiyon öğrenci ekleme fonksiyonunun aynısı.

    string buffer;
    string tempBuffer;

    if_Academician.open(file_Academician);
    while (getline(if_Academician, tempBuffer))
        buffer += tempBuffer + '\n';
    if_Academician.close();

    cout << "Akademisyen Ekleme: (Ekleyeceğiniz girdiler boşluksuz olmalıdır.)" << endl << endl;

    of_Academician.open(file_Academician, ios::app);

    string tempGet;
    do
    {
        cout << "Akademisyen id giriniz:" << endl;
        cin >> tempGet;
        tempGet += ' ';
    } while (buffer.find(tempGet, 0) != string::npos && cout << "Akademisyen id kullanılıyor." << endl << endl);
    academicians[AcademicianCounter].setId(tempGet);
    of_Academician << '\n' + tempGet;

    cout << "İsminizi giriniz:" << endl;
    cin >> tempGet;
    academicians[AcademicianCounter].setName(tempGet);
    of_Academician << tempGet + ' ';

    cout << "Soyisminizi giriniz:" << endl;
    cin >> tempGet;
    academicians[AcademicianCounter].setSurname(tempGet);
    of_Academician << tempGet + ' ';

    cout << "Bölümünüzü giriniz:" << endl;
    cin >> tempGet;
    academicians[AcademicianCounter].setDepartment(tempGet);
    of_Academician << tempGet + ' ';

    cout << "Email adresinizi giriniz:" << endl;
    cin >> tempGet;
    academicians[AcademicianCounter].setMail(tempGet);
    of_Academician << tempGet + ' ';

    cout << "Telefon numaranızı giriniz:" << endl;
    cin >> tempGet;
    academicians[AcademicianCounter].setPhonenumber(tempGet);
    of_Academician << tempGet + ' ';

    cout << "Ünvan giriniz:" << endl;
    cin >> tempGet;
    academicians[AcademicianCounter].setDegree(tempGet);
    of_Academician << tempGet;

    of_Academician.close();
    cout << "Akademisyen başarıyla eklendi..." << endl;
}

int Appointment::dupeChecker(string acId, string stId, string date1, string start, string end)
{
    // Çoklu girdi test etme fonksiyonu
    AppointmentTime at_Temp;
    at_Temp.setStudentId(stId);
    at_Temp.setAcademicianId(acId);
    at_Temp.setTime(date1, start, end);

    for (int i = 0; i < AppointmentCounter; i++)
    {
        // Bütün randevuları tek tek geziyor, akademisyen veya öğrenci id eşit ise operator
        // overloading kullanarak yaptığım zaman karşılaştırma fonksiyonuna gidiyor.
        // eğer eşit ise 0 döndürüyor, dupe var demek. Yoksa 1 döndürüyor.
        // Diğer fonksiyonların detaylı açıklaması Time/AppointmentTime.cpp dosyasında.
        if (acId == appointments[i].getAcademicianId() || stId == appointments[i].getStudentId())
        {
                if (at_Temp == appointments[i])
                    return 0;
        }
    }

    return 1;
}

void Appointment::addAppointment()
{
    // Akademisyenleri bastırıyoruz ve ID istiyoruz.
    printAcademicians();
    string temp_AcademicianID;
    cout << endl << "Randevu almak istediğiniz akademisyenin IDsini giriniz." << endl;
    cin >> temp_AcademicianID;

    // Doğruluğu kontrol ediyoruz.
    int academicianCheck = 0;
    for (int i = 0; i < AcademicianCounter; i++)
    {
        if (academicians[i].getId() == temp_AcademicianID)
            academicianCheck = 1;
    }

    if (academicianCheck != 1)
    {
        cout << "Böyle bir akademisyen bulunmamakta." << endl;
        return;
    }

    cout << endl << "Hocanın randevu takvimi aşağıdaki gibidir:" << endl;
    getAcademiciansAppointments(temp_AcademicianID);

    cout << endl << endl;

    // Öğrencileri bastırıyoruz ve ID istiyoruz.
    printStudents();
    string temp_StudentID;
    cout << endl << "Öğrenci numaranızı giriniz." << endl;
    cin >> temp_StudentID;

    // ID doğruluğu kontrol ediyoruz.
    int studentCheck = 0;
    for (int i = 0; i < StudentCounter; i++)
    {
        if (students[i].getId() == temp_StudentID)
            studentCheck = 1;
    }

    if (studentCheck != 1)
    {
        cout << "Böyle bir öğrenci bulunmamakta." << endl;
        return;
    }

    string temp_AppointmentDate;
    cout << endl << "Randevu almak istediğiniz tarihi giriniz. (format: dd.mm.yyyy)" << endl;
    cin >> temp_AppointmentDate;

    string temp_AppointmentHour_start;
    cout << endl << "Randevu almak istediğiniz saati giriniz. (format: hh:mm)" << endl;
    cin >> temp_AppointmentHour_start;

    string temp_AppointmentHour_end;
    cout << endl << "Randevunuzun bitmesini istediğiniz saati giriniz. (format: hh:mm)" << endl;
    cin >> temp_AppointmentHour_end;

    // Tarih saat bilgilerimizi aldıktan sonra hemen çoklu girdi kontrolü yapıyoruz.
    if (dupeChecker(temp_AcademicianID, temp_StudentID, temp_AppointmentDate,
                    temp_AppointmentHour_start, temp_AppointmentHour_end) != 1)
    {
        cout << endl << "Bu saatlerde alınmış bir randevu var." << endl;
        return;
    }

    // Randevumuzu ekliyoruz.
    appointments[AppointmentCounter].setAcademicianId(temp_AcademicianID);
    appointments[AppointmentCounter].setStudentId(temp_StudentID);

    // Eğer zaman setleme fonksiyonum zaman parse ederken bir anomali görürse hata veriyor.
    if (appointments[AppointmentCounter].setTime(temp_AppointmentDate,
                                                 temp_AppointmentHour_start, temp_AppointmentHour_end) != 1)
    {
        return;
    }

    // Bu adıma kadar hatasız geçtiysek dosyayı açıp dosyaya randevuyu yazıyorum.
    of_Appointment.open(file_Appointment, ios::app);
    of_Appointment << "\n" + appointments[AppointmentCounter].getStudentId() << " "
                   << appointments[AppointmentCounter].getAcademicianId() << " "
                   << temp_AppointmentDate << " "
                   << temp_AppointmentHour_start << " "
                   << temp_AppointmentHour_end;
    of_Appointment.close();

    AppointmentCounter++;
    cout << "Randevu başarıyla eklendi." << endl;
    return;
}

void Appointment::printStudents()
{
    cout << "ID | İsim | Soyisim | Bölüm | Katılım | Mail | Telefon" << endl;
    for (int i = 0; i < StudentCounter; i++)
    {
        cout << students[i].getId() << " "
             << students[i].getName() << " "
             << students[i].getSurname() << " "
             << students[i].getDepartment() << " "
             << students[i].getJoindate() << " "
             << students[i].getMail() << " "
             << students[i].getPhonenumber() << " "
             << endl;
    }
}

void Appointment::printAcademicians()
{
    cout << "ID | Ünvan | İsim | Soyisim | Bölüm | Mail | Telefon" << endl;
    for (int i = 0; i < AcademicianCounter; i++)
    {
        cout << academicians[i].getId() << " "
             << academicians[i].getDegree() << " "
             << academicians[i].getName() << " "
             << academicians[i].getSurname() << " "
             << academicians[i].getDepartment() << " "
             << academicians[i].getMail() << " "
             << academicians[i].getPhonenumber() << " "
             << endl;
    }
}

void Appointment::printAppointments()
{
    cout << "Öğrenci | Akademisyen | Tarih | Başlangıç | Bitiş" << endl;
    string temp1, temp2;

    for (int i = 0; i < AppointmentCounter; i++)
    {
        // Değerler int tutulduğu için 0 / 00 dönüşümü yapıyorum.
        if (appointments[i].getYear() == 0)
        {
            continue;
        }

        if (appointments[i].getStart_minute() == 0)
        {
            temp1 = "00";
        } else
        {
            temp1 = to_string(appointments[i].getStart_minute());
        }

        if (appointments[i].getEnd_minute() == 0)
        {
            temp2 = "00";
        } else
        {
            temp2 = to_string(appointments[i].getEnd_minute());
        }

        cout << appointments[i].getStudentId() << " "
             << appointments[i].getAcademicianId() << " "
             << appointments[i].getDay() << "." << appointments[i].getMonth() << "." << appointments[i].getYear() << " "
             << appointments[i].getStart_hour() << ":" << temp1 << " "
             << appointments[i].getEnd_hour() << ":" << temp2 << " "
             << endl;
    }
}

void Appointment::printAcademiciansAppointment()
{
    printAcademicians();
    string temp, temp1, temp2;
    cout << endl << "Akademisyen ID giriniz." << endl;
    cin >> temp;

    cout << "Öğrenci | Akademisyen | Tarih | Başlangıç | Bitiş" << endl;
    for (int i = 0; i < AppointmentCounter; i++)
    {
        if (appointments[i].getAcademicianId() != temp)
        {
            continue;
        }

        // Değerler int tutulduğu için 0 / 00 dönüşümü yapıyorum.
        if (appointments[i].getYear() == 0)
        {
            continue;
        }

        if (appointments[i].getStart_minute() == 0)
        {
            temp1 = "00";
        } else
        {
            temp1 = to_string(appointments[i].getStart_minute());
        }

        if (appointments[i].getEnd_minute() == 0)
        {
            temp2 = "00";
        } else
        {
            temp2 = to_string(appointments[i].getEnd_minute());
        }

        cout << appointments[i].getStudentId() << " "
             << appointments[i].getAcademicianId() << " "
             << appointments[i].getDay() << "." << appointments[i].getMonth() << "." << appointments[i].getYear() << " "
             << appointments[i].getStart_hour() << ":" << temp1 << " "
             << appointments[i].getEnd_hour() << ":" << temp2 << " "
             << endl;
    }
}

void Appointment::printStudentsAppointment()
{
    printStudents();
    string temp, temp1, temp2;
    cout << endl << "Öğrenci ID giriniz." << endl;
    cin >> temp;

    cout << "Öğrenci | Akademisyen | Tarih | Başlangıç | Bitiş" << endl;
    for (int i = 0; i < AppointmentCounter; i++)
    {
        if (appointments[i].getStudentId() != temp)
        {
            continue;
        }

        // Değerler int tutulduğu için 0 / 00 dönüşümü yapıyorum.
        if (appointments[i].getYear() == 0)
        {
            continue;
        }

        if (appointments[i].getStart_minute() == 0)
        {
            temp1 = "00";
        } else
        {
            temp1 = to_string(appointments[i].getStart_minute());
        }

        if (appointments[i].getEnd_minute() == 0)
        {
            temp2 = "00";
        } else
        {
            temp2 = to_string(appointments[i].getEnd_minute());
        }

        cout << appointments[i].getStudentId() << " "
             << appointments[i].getAcademicianId() << " "
             << appointments[i].getDay() << "." << appointments[i].getMonth() << "." << appointments[i].getYear() << " "
             << appointments[i].getStart_hour() << ":" << temp1 << " "
             << appointments[i].getEnd_hour() << ":" << temp2 << " "
             << endl;
    }
}

void Appointment::getAcademiciansAppointments(string Id)
{
    string temp1, temp2;
    cout << "Öğrenci | Akademisyen | Tarih | Başlangıç | Bitiş" << endl;
    for (int i = 0; i < AppointmentCounter; i++)
    {
        if (appointments[i].getAcademicianId() != Id)
        {
            continue;
        }

        // Değerler int tutulduğu için 0 / 00 dönüşümü yapıyorum.
        if (appointments[i].getYear() == 0)
        {
            continue;
        }

        if (appointments[i].getStart_minute() == 0)
        {
            temp1 = "00";
        } else
        {
            temp1 = to_string(appointments[i].getStart_minute());
        }

        if (appointments[i].getEnd_minute() == 0)
        {
            temp2 = "00";
        } else
        {
            temp2 = to_string(appointments[i].getEnd_minute());
        }

        cout << appointments[i].getStudentId() << " "
             << appointments[i].getAcademicianId() << " "
             << appointments[i].getDay() << "." << appointments[i].getMonth() << "." << appointments[i].getYear() << " "
             << appointments[i].getStart_hour() << ":" << temp1 << " "
             << appointments[i].getEnd_hour() << ":" << temp2 << " "
             << endl;
    }
}