#include "src/box.h"
#include "src/space.h"

/*
 * Doğukan Öksüz
 * root@dogukanoksuz.com.tr
 * 
 * Assignment 2: Space simulation and center of mass calculation
 */

using namespace std;

int main()
{
    Space space(10, 10);
    space.fillRandomBox(20, 5, 5); // adet, max alan, max density

    // space.printBoxCoordinates();
    space.printSpace(); // uzayı bastır
    space.printCenterOfMass(); // ağırlık merkezini hesapla + bastır
    space.outputToFile(); // dosyaya bütün verileri çıkartıyoruz.
}
