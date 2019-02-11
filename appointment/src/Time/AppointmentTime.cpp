//
// Created by divergent / Doğukan ÖKSÜZ on 12/22/18.
//

#include "../../include/Time/AppointmentTime.h"

AppointmentTime::AppointmentTime()
{
    day = 0, month = 0, year = 0, start_hour = 0, end_hour = 0, start_minute = 0, end_minute = 0;
}

AppointmentTime::~AppointmentTime()
{

}

void AppointmentTime::parseDate(string _Date)
{
    // delimiterle her adımda arayıp parçalıyor ardından parçaladığı kısmı siliyor.
    string delimiter = ".";
    string date = _Date;
    string token;

    size_t pos;
    pos = date.find(delimiter);
    token = date.substr(0, pos);
    day = stoi(token);
    date.erase(0, pos + delimiter.length());

    pos = date.find(delimiter);
    token = date.substr(0, pos);
    month = stoi(token);
    date.erase(0, pos + delimiter.length());

    pos = date.find(delimiter);
    token = date.substr(0, pos);
    year = stoi(token);
}

void AppointmentTime::parseHour(string type, string _Hour)
{
    // bir parametre alıp parse ettiğim zamanı pointerlar ile
    // değiştiriyorum. geri kalan işleyiş aynı.
    int *hour1, *minute;
    hour1 = &end_hour;
    minute = &end_minute;

    if (type == "start")
    {
        hour1 = &start_hour;
        minute = &start_minute;
    }

    string delimiter = ":";
    string hour = _Hour;
    string token;

    size_t pos;
    pos = hour.find(delimiter);
    token = hour.substr(0, pos);
    *hour1 = stoi(token);
    hour.erase(0, pos + delimiter.length());

    pos = hour.find(delimiter);
    token = hour.substr(0, pos);
    *minute = stoi(token);
}

int AppointmentTime::setTime(string _Date, string _startTime, string _endTime)
{
    // ctime kütüphanesi için tm_Now ile günümüz tarihini alıyorum
    time_t now = time(0);
    tm *tm_Now = localtime(&now);

    // date parsing
    parseDate(_Date);

    // tm structu ile tarih ile ilgili olasılıkları tek tek karşılaştırıyorum.
    if (year > 2100 || day > 31 || month > 12)
    {
        cout << "Tarihte anomali mevcut" << endl;
        return 0;
    }

    if (tm_Now->tm_year + 1900 > year)
    {
        cout << "Önceki bir tarihe randevu alamazsınız." << endl;
        return 0;
    }

    // hour parsing
    parseHour("start", _startTime);
    parseHour("end", _endTime);

    if (start_hour > 23 || end_hour > 23 || start_minute > 59 || end_minute > 59)
    {
        cout << "Saat dakika formatı kurallara uygun değil." << endl;
        return 0;
    }

    if ((end_hour < start_hour))
    {
        cout << "Başlangıç saati bitiş saatinden önce olamaz." << endl;
        return 0;
    }

    if (start_hour == end_hour && (start_minute >= end_minute))
    {
        cout << "Saatlerde bi problem var?" << endl;
        return 0;
    }

    // Bu döngü biraz karmaşık ancak düzgün işlemi ancak böyle yaptırtabildim.
    if (tm_Now->tm_year + 1900 == year)
    {
        if (tm_Now->tm_mon + 1 > month)
        {
            cout << "Önceki bir tarihe randevu alamazsınız." << endl;
            return 0;
        }

        if (tm_Now->tm_mon + 1 == month)
        {
            if (tm_Now->tm_mday > day)
            {
                cout << "Önceki bir tarihe randevu alamazsınız." << endl;
                return 0;
            }

            if (tm_Now->tm_mday == day)
            {
                if (tm_Now->tm_hour > start_hour)
                {
                    cout << "Önceki bir tarihe randevu alamazsınız." << endl;
                    return 0;
                }

                if (tm_Now->tm_hour == start_hour)
                {
                    if (tm_Now->tm_min > start_minute)
                    {
                        cout << "Önceki bir tarihe randevu alamazsınız." << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

const string &AppointmentTime::getAcademicianId() const
{
    return AcademicianId;
}

void AppointmentTime::setAcademicianId(const string &AcademicianId)
{
    AppointmentTime::AcademicianId = AcademicianId;
}

const string &AppointmentTime::getStudentId() const
{
    return StudentId;
}

void AppointmentTime::setStudentId(const string &StudentId)
{
    AppointmentTime::StudentId = StudentId;
}

int AppointmentTime::getDay() const
{
    return day;
}

int AppointmentTime::getMonth() const
{
    return month;
}

int AppointmentTime::getYear() const
{
    return year;
}

int AppointmentTime::getStart_hour() const
{
    return start_hour;
}

int AppointmentTime::getStart_minute() const
{
    return start_minute;
}

int AppointmentTime::getEnd_hour() const
{
    return end_hour;
}

int AppointmentTime::getEnd_minute() const
{
    return end_minute;
}

bool AppointmentTime::operator==(AppointmentTime otherOne)
{
    if (day != otherOne.day || month != otherOne.month || year != otherOne.year)
    {
        return false;
        // gün ay yıl eşit değilse false döndür
    }
    int sumStart = start_hour * 60 + start_minute;
    int otherSumStart = otherOne.start_hour * 60 + otherOne.start_minute;
    // elimizdekini dakika cinsine çevirdik
    int sumEnd = end_hour * 60 + end_minute;
    int otherSumEnd = otherOne.end_hour * 60 + otherOne.end_minute;
    // parametredekini dakika cinsine çevirdik

    return duplicate(sumStart, sumEnd, otherSumStart, otherSumEnd);
}

bool AppointmentTime::duplicate(int a, int aEnd, int b, int bEnd)
{
    // karşılaştırmamızı yapıp o aralıkta bir randevu var mı bakıyoruz.
    if ((a < b && aEnd > b) || (a < bEnd && aEnd >= bEnd) || (b <= a && bEnd > a))
    {
        return true;
    }
    return false;
}