#include "include/Menu.h"

using namespace std;

/*
 * Akademisyen Randevu Programı
 *
 * Hazırlayan: Doğukan Öksüz
 *
 * Notlar:  Randevu dosyanızda günümüz tarihinden önceki randevu bulunmamalı.
 *          Program eski randevuları, eski öğrencileri hafızada tutup,
 *                  dosyalara yenilerini yazabilmekte.
 *
 *          Randevular için bir zaman limiti koymadım, her saatte alınabilir
 *          diye düşünerek yaptım ancak kısıtlanması gerekirse çok kolay şekilde
 *          kısıtlama yapılabilir.
 *
 *          Randevular bir bug olmadığı sürece çakışmıyor, testlerini gerçekleştirdim.
 *          Çağırma argümanları örnek;
 *
 *          ./a.out <Öğrenci dosyası> <Akademisyen dosyası> <Randevu dosyası>
 */

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        cout << "Yetersiz argüman. kullanım: öğrenci, akademisyen, randevu dosyaları" << endl;
        return 0;
    }

    // Menu classımızı çağırarak Appointment'i de construct ediyoruz.
    Menu randevuProgrami(argv[1], argv[2], argv[3]);
    return 0;
}
