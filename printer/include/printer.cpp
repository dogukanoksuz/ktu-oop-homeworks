#include "printer.h"

Buffer::Buffer ()
{
	init();								  // the real deal, user input function
										  // initializing our class with user input
	array      		   = new Data [size]; // creating memory space for our array
	head               = 0;				  // initializing integer values
	tail 	           = 0;
	datacount  		   = 0;
	timer      		   = 0;
	printingStarted	   = 0;
	pageCount     	   = 1;
}

Buffer::~Buffer () {
	input.close();						// free up the memory by deallocating
	delete []array;						// the space of ifstream and array
}

void Buffer::init () {
	// kullanıcıdan inputu alır, programın kurulumunu buna göre yapar
	string inputf;						// everything is obvious
	cout << endl << "Printer input dosyasını yazınız." << endl;
	cin >> inputf;
	input.open(inputf);

	cout << endl << "Array boyutunu tanımlayınız. (min=2)" << endl;
	cin >> size;
	size = size + 1;					// +1 tanımlama sebebim -1 şeklinde
										// overflowa karşı boşluk bırakıyorum
	if (size - 1 < 2) {
		cout << "Arrayin boyutu ikiden küçük olmamalıdır." << endl;
		exit(EXIT_FAILURE);
	}

	cout << endl << "Bilgisayarın belge ekleme sıklığı:" << endl;
	cin >> speed;

	cout << endl << "Yazıcının bir sayfayı kaç saniyede yazdığı:" << endl;
	cin >> printSpeed;

	cout << endl << endl << endl;
}

void Buffer::insert (Data & structure) {
	// veriyi içeri aktarır.
	// arrayimde bir boşluk dediğim kısım bu.
	if (datacount != size - 1) { 		// bir boşluk bırakıyoruz
        array[tail] = structure;
        tail = (tail + 1) % size;
        datacount++;
	}
}

void Buffer::remove () {
	// buffer'ın head'ındaki elemanı çıkartır.
	// fifo implementasyonunu da sağlar.
	if ( head != tail ) {				// veri var mı kontrol ediyoruz
        head = (head + 1) % size;
        datacount--;
	}
}

void Buffer::documentImporter () {
	// içeri verileri import eden fonksiyon
	Data temp1;								// verileri temp structureu ile içeri alıyoruz
	if ( (timer % speed == 0) && input >> temp1.file.fileName ) {
		input >> temp1.file.fileSize;		// ^ işlemin sebebi sonsuz loopa düşmemek
		input >> temp1.file.pageCount;

		input >> temp1.user.name;
		input >> temp1.user.surname;
		input >> temp1.user.username;
		input >> temp1.user.email;
		input >> temp1.user.birthday;

		input >> temp1.time.year;
		input >> temp1.time.day;
		input >> temp1.time.month;
		input >> temp1.time.hour;
		input >> temp1.time.minute;
		input >> temp1.time.second;

		cout << timer << setw(3)
			 << ".sn - PC belgeyi kuyruğa yazdı. - " << setw(35)
			 << temp1.file.fileName
			 << " ("
			 << temp1.file.pageCount
			 << ") "
			 << endl;
		insert(temp1);						// aldığımız verileri insert ediyoruz
	}
}

void Buffer::documentPrinter () {
	// dosya yazdırma işlemini gerçekler.
	// timer ile hızın modu 0 ise kod çalışır
	if ( (timer % printSpeed == 0) ) {
		if (printingStarted == 0) {			// yazıcı bastırma işlemine başladıysa çıktı ver
            temp = array[head];
            remove();
            cout << timer << setw(3)
				 << ".sn - Yazıcı belgeyi kuyruktan okudu. - " << setw(35)
				 << temp.file.fileName  << " ("
				 << temp.file.pageCount << ") "
				 << endl;
			printingStarted++;
		}
		temp.file.pageCount--;
		if ( temp.file.pageCount == 0 ) {	// bastırma işlemi bittiyse gerekli işlemi yap
            if (printSpeed != 1) {
				timer = (timer + printSpeed) - 1;
			}
			cout << timer + 1 << setw(3)
				 << ".sn - Yazıcı belgeyi yazma işini bitirdi. - " << setw(35)
				 << temp.file.fileName << " ("
				 << pageCount << ") "
				 << endl;
			printingStarted = 0;				// çıktı bitti değişkenini değiştir
			pageCount = 1;						// sayfa değişkenini yenile
		} else {
			pageCount++;						// sayfa değişkenini arttır.
		}
	}
}

void Buffer::boot () {
	// printeri çalıştırır, dosyaları kuyruklar ve iş bitince kapatır.
	do {
		if ( datacount < size - 1 ) {
			documentImporter();			// veri sayısı array sayısından 1 eksik ise
		}								// içeri belge alıyoruz
		if ( datacount != 0 || printingStarted != 0 ) {
			documentPrinter();			// veri sayısı 0 değilse veri bastırıyoruz
		}
        timer++;
	} while ( datacount != 0 || !input.eof() || temp.file.pageCount != 0 );
	cout << endl
		 << "Tüm yazdırma işlemleri tamamlandı."
		 << endl;
}
