#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/*
 *	Doğukan Öksüz
 *  365304
 *  OOP 1st Homework
 *
 *  The sources that i've used;
 *  https://www.youtube.com/watch?v=ia__kyuwGag
 *
 */

using namespace std;

struct File {						   // the struct of files
	string fileName;
	unsigned int fileSize;
	unsigned int pageCount;
	int priority;
};

struct User {					       // the struct of users
	string name;
	string surname;
	string username;
	string email;
	int birthday;
};

struct Time {						   // the struct of time
	int year;
	int day;
	int month;
	int hour;
	int minute;
	int second;
};

struct Data {						   // the main struct
	File file;
	User user;
	Time time;
    int active;
};

class Buffer
{
	public:
		Buffer();						// constructor*
		virtual ~Buffer();				// deconstructor (free up memory)*

		void boot();					// start printer*

	private:
		// buffer functions
		void insert(Data &);			// insert element to buffer*
		void remove();					// remove element from buffer*

		// printer simulator
		void init(); 					// take variables inside*
		
		void documentImporter();		// import documents to queue*
		void documentPrinter();			// print documents*
        Data temp;
		Data* array;					// array implementation (static)*
		ifstream input;					// input file*
		int size, speed, printSpeed, head, tail, datacount, timer, printingStarted, pageCount;
										// integer values that i'm using in Class*
};
