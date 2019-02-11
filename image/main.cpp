#include "include/Image.h"

/*
 * Doğukan Öksüz
 * root@dogukanoksuz.com.tr
 * 
 * Assignment No.4 : Basic image processing program
 * 
 * Sobel yapıldı, + * !, << >> operatorleri overload edildi,
 * duzgun sekilde filtrelemeleri yapıyor.
 *  
 */

int main(int argc, char **argv)
{
    ifstream if_Img1;
    ifstream if_Img2;

    if_Img1.open(argv[1]);
    if_Img2.open(argv[2]);

    Image img1, img2, img3;

    if_Img1 >> img1;
    if_Img2 >> img2;

    if_Img1.close();
    if_Img2.close();

    img1.sobel();
    img1.setThresoldValue(30);

    // thresold fonksiyonunun direkt çağırılması 0 ve 255'e dönüştürür direkt.

    // img3 = !img1;

    ofstream output;
    output.open(argv[3], ios::out);

    output << img1;
    output.close();

    return 0;
}
