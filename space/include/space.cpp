#include "../src/space.h"
#include "../src/box.h"

#include <iostream>
#include <fstream>

using namespace std;

Space::Space()
{
    int w;
    int h;

    cout << "Uzayın genişliğini giriniz (width):";
    cin >> w;

    cout << "Uzayın yüksekliğini giriniz (height):";
    cin >> h;

    if (w < 1 || h < 1)
    {
        cout << "Space can't be constructed without valid values" << endl;
        exit(EXIT_FAILURE);
    }

    spaceWidth = w, spaceHeight = h, boxCounter = 0, usedSpace = 0, centerOfMass_x = 0, centerOfMass_y = 0;

    constructSpace();

    box = new Box[spaceWidth * spaceHeight]; // maksimum kutu sayısı uzay boyutunu geçemez.

    fp.open("centerofmass.txt", ios::out);

    cout << "Space is constructed properly."
         << endl
         << "Width: " << spaceWidth << endl
         << "Height: " << spaceHeight << endl;
}

Space::Space(int w, int h)
{
    if (w < 1 || h < 1)
    {
        cout << "Space can't be constructed without valid values" << endl;
        exit(EXIT_FAILURE);
    }

    spaceWidth = w, spaceHeight = h, boxCounter = 0, usedSpace = 0, centerOfMass_x = 0.0, centerOfMass_y = 0.0;

    constructSpace();

    // create box class
    box = new Box[spaceWidth * spaceHeight]; // maksimum kutu sayısı uzay boyutunu geçemez.

    // file open
    fp.open("centerofmass.txt", ios::out);

    cout << "Space is constructed properly."
         << endl
         << "Width: " << spaceWidth << endl
         << "Height: " << spaceHeight << endl;
}

void Space::constructSpace()
{
    // implementing dynamic 2d array
    space = new int *[spaceHeight];
    for (int i = 0; i < spaceHeight; i++)
    {
        space[i] = new int[spaceWidth];
    }

    // For random purposes
    srand(time(NULL));
}

Space::~Space()
{
    delete[] box;
    if (spaceHeight > 0)
    {
        for (int i = 0; i < spaceHeight; i++)
        {
            delete[] space[i];
        }
        delete[] space;
    }
    else
    {
        delete[] space;
    }
    fp.close();
}

int Space::checkSpace(int x, int y, int w, int h) const
{
    // arrayin o alanını tarayarak boş mu dolu mu bakıyoruz
    for (int i = y; i < y + h; i++)
    {
        for (int j = x; j < x + w; j++)
        {
            if (space[i][j] == 1)
            {
                return 0; // full
            }
        }
    }
    return 1; // empty
}

void Space::addBox(int x, int y, int w, int h, int d)
{
    // access violation kontrollerini yapıyoruz
    if ((usedSpace + (w * h) - 1) >= spaceWidth * spaceHeight)
    {
        cout << "Not enough space for your box." << endl;
        return;
    }

    if ((x + w > spaceWidth) || (y + h > spaceHeight))
    {
        cout << "Your box is bigger than the space" << endl;
        return;
    }

    if (w > spaceWidth || h > spaceHeight)
    {
        cout << "The box that you're trying to add is bigger than the space" << endl;
        return;
    }

    if (checkSpace(x, y, w, h) == 0)
    {
        cout << "The space for the box that you are trying to add is full!";
        return;
    }

    if (d < 1)
    {
        cout << "No way" << endl;
        return;
    }

    // kutuyu ekliyoruz kutu classımıza
    box[boxCounter] = Box(w, h);
    box[boxCounter].setCoordinates(x, y);
    box[boxCounter].setDensity(d);

    // o alanı kaplayan bölümü 1'e eşitleyerek işgal edildiğini anlıyoruz.
    for (int i = y; i < y + h; i++)
    {
        for (int j = x; j < x + w; j++)
        {
            space[i][j] = 1;
        }
    }

    boxCounter++;

    // kullanılan alanın çıktısını veriyoruz
    usedSpace += w * h;

    cout << "Box added with this properties:"
         << endl
         << "X = " << x
         << " Y = " << y
         << " W = " << w
         << " H = " << h
         << " Density = " << d
         << endl
         << endl;
}

void Space::fillRandomBox(int boxCount, int maxSize, int d)
{
    // girdileri kontrol ediyoruz
    if (maxSize > 6)
    {
        cout << "I can't add boxes bigger than 6 blocks." << endl;
        exit(EXIT_FAILURE);
    }

    if (boxCount < 1 || maxSize < 1 || d < 1)
    {
        cout << "access violation" << endl;
        exit(EXIT_FAILURE);
    }

    int boxSize_X = 0;
    int boxSize_Y = 0;
    int coord_x = 0;
    int coord_y = 0;
    int density_random = 0;

    // kutu sayısı kadar döngüyü döndürüyoruz
    for (int tempCounter = 0; tempCounter != boxCount; tempCounter++)
    {
        if (spaceWidth < 3 || maxSize > spaceWidth || spaceHeight < 3)
        {
            cout << "I can't add boxes that bigger than " << spaceWidth << endl;
            exit(EXIT_FAILURE);
        }

        do
        {
            // ilk döngümüz boşluk doluluk kontrolü yapacaktır
            do
            {
                // bu döngümüz ise maksimum boyut kontrolünü yapacaktır
                boxSize_X = (rand() % maxSize) + 1;
                boxSize_Y = (rand() % maxSize) + 1;
                if (boxSize_X > 4)
                {
                    boxSize_Y = 1;
                }
            } while (boxSize_X * boxSize_Y > maxSize);

            // koordinatları ayarlayıp overflowa düşmesini engelliyoruz.
            coord_x = (rand() % spaceWidth + 1) - boxSize_X;
            if (coord_x < 0)
                coord_x = 0;

            coord_y = (rand() % spaceHeight + 1) - boxSize_Y;
            if (coord_y < 0)
                coord_y = 0;

            density_random = (rand() % d + 1);

            if ((usedSpace + (boxSize_X * boxSize_Y) - 1) == spaceWidth * spaceHeight)
            {
                boxSize_X = 1;
                boxSize_Y = 1;
            }

            if (usedSpace >= spaceWidth * spaceHeight)
            {
                cout << "I can add " << tempCounter << " boxes in this situation because space is full." << endl;
                return;
            }

        } while (!checkSpace(coord_x, coord_y, boxSize_X, boxSize_Y));

        // eğer döngü kırıldıysa kutuyu ekliyoruz.
        addBox(coord_x, coord_y, boxSize_X, boxSize_Y, density_random);
    }
}

void Space::printSpace() const
{
    // matrisin son halini yazdırıyoruz
    for (int i = spaceHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j < spaceWidth; j++)
        {
            if (space[i][j] == 1)
            {
                cout << "\033[1;31m1 \033[0m";
            }
            else
            {
                cout << "# ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Space::printBoxCoordinates()
{
    // kutuların bilgilerini bastırıyoruz.
    for (int i = 0; i < boxCounter; i++)
    {
        cout << "Box-"
             << i + 1
             << " located at ("
             << box[i].getX() << ", "
             << box[i].getY()
             << ") "
             << "Width and height info: ("
             << box[i].getW() << ", "
             << box[i].getH() << ") Density: "
             << box[i].getDensity()
             << endl;
    }
}

void Space::calculateCenterOfMass()
{
    // khanacademydeki formüle göre işlemi yapıyoruz.

    double xa = 0.0;
    double ya = 0.0;
    int m = 0;
    double mtemp = 0.0;

    for (int i = 0; i < boxCounter; i++)
    {
        xa = (box[i].getX()) + (box[i].getW() / 2);
        ya = (box[i].getY()) + (box[i].getH() / 2);
        m = box[i].getW() * box[i].getH() * box[i].getDensity();

        mtemp += m;
        centerOfMass_x += xa * m;
        centerOfMass_y += ya * m;
    }

    centerOfMass_x /= mtemp;
    centerOfMass_y /= mtemp;
}

void Space::printCenterOfMass()
{
    // hesaplatmayı çağırıp ardından bilgileri yazdırıyoruz
    calculateCenterOfMass();
    cout << "Center of mass's location is: ("
         << centerOfMass_x << ", "
         << centerOfMass_y << ")"
         << endl;
}

void Space::outputToFile()
{
    // dosyaya çıktı veriyoruz.
    fp << "x: coordinate_x, y: coordinate_y, w: width, h: height, d: density" << endl;
    fp << "(x, y) (w, h) d" << endl;
    for (int i = 0; i != boxCounter; i++)
    {
        fp << "(" << box[i].getX() << ", "
           << box[i].getY() << ") ("
           << box[i].getW() << ", "
           << box[i].getH() << ") "
           << box[i].getDensity() << endl;
    }
    fp << "Center of mass is pointed at: (" << centerOfMass_x << ", " << centerOfMass_y << ")" << endl;

    cout << "I write everything to the centerofmass.txt" << endl;
}
