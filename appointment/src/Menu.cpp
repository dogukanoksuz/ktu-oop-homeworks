//
// Created by divergent / Doğukan ÖKSÜZ on 12/18/18.
//

#include "../include/Menu.h"


Menu::Menu()
{

}

Menu::Menu(string _Student, string _Academician, string _Appointment)
{
    Appointment system(_Student, _Academician, _Appointment);
    start(system);
}

Menu::~Menu()
{

}

void Menu::show()
{
    cout << endl << "Akademisyen Randevu Programı" << endl;
    for (int i = 0; i < 35; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "1. Öğrenci ekle" << endl
         << "2. Akademisyen ekle" << endl
         << "3. Öğrencilerin listesini göster" << endl
         << "4. Akademisyenlerin listesini göster" << endl
         << "5. Randevu ekle" << endl
         << "6. Randevu listele" << endl
         << "7. Öğrenci randevusu listele" << endl
         << "8. Akademisyen randevusu listele" << endl
         << endl;
}

void Menu::start(Appointment &system)
{
    /*
     *  caselere göre fonksiyonları çağırıyoruz.
     */
    string Continue;

    do
    {
        show();
        int Selection;
        cin >> Selection;
        cout << endl;

        switch (Selection)
        {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.addAcademician();
                break;
            case 3:
                system.printStudents();
                break;
            case 4:
                system.printAcademicians();
                break;
            case 5:
                system.addAppointment();
                break;
            case 6:
                system.printAppointments();
                break;
            case 7:
                system.printStudentsAppointment();
                break;
            case 8:
                system.printAcademiciansAppointment();
                break;
            default:
                cout << "Seçiminiz menüde bulunmamakta." << endl;
                break;
        }

        cout << endl << "Başka işlem yapmak istiyor musunuz? (e/E || h/H)" << endl;
        cin >> Continue;
    } while (Continue == "e" || Continue == "E");
}