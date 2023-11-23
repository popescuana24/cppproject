#include <iostream>
#include <string>


using namespace std;


class Location { 
private:
	int nr_seats;
	int nr_rows;
	char* zones;
	char* locationName;

	//adauga address
public:


	// Default constructor
	Location() {

		nr_seats = 0;
		nr_rows = 0;
		zones = nullptr;
		locationName = NULL;
	}

	//constructor with parameters
	Location(int nr_seats, int nr_rows, const char* zones,  const char* locationName) {
		this->nr_seats = nr_seats;

		this->nr_rows = nr_rows;

		this->zones = new char[strlen(zones) + 1];
		strcpy_s(this->zones, strlen(zones) + 1, zones);

		this->locationName = new char[strlen(locationName) + 1];
		strcpy_s(this->locationName, strlen(locationName) + 1, locationName);

	}   

	//copy constructor

	Location(const Location& other) {

		this->nr_seats = other.nr_seats;
		this->nr_rows = other.nr_rows;

		if (other.zones != NULL) {
			// Allocate new memory for zones
			this->zones = new char[strlen(other.zones) + 1];
			strcpy_s(this->zones, strlen(other.zones) + 1, other.zones);
		}
		else {
			// If other.zones is NULL, assign nullptr to this->zones
			this->zones = nullptr;
		}//////////de adaugat locationName

		if (other.locationName != NULL) {
			this->locationName = new char[strlen(other.locationName) + 1];
			strcpy_s(this->locationName, strlen(other.locationName) + 1, other.locationName);
		}
		else {
			this->locationName = nullptr;
		}

	}

	//destructor
	~Location() {
		if (this->zones != NULL) {
			delete[]this->zones;
			this->zones = nullptr;
		}
		if (this->locationName != NULL) {
			delete[]this->locationName;
			this->locationName = nullptr;
		}
	}

	//mathods:


	//getters
	int getnr_seats() {
		return this->nr_seats;
	}

	int getnr_rows() {
		return this->nr_rows;
	}

	const char* getzones() {
		char* zone = new char[strlen(this->zones) + 1];
		strcpy_s(zone, strlen(this->zones) + 1, this->zones);
		return zone;
	}

	const char* getlocationName() {
		char* locName = new char[strlen(this->locationName) + 1];
		strcpy_s(locName, strlen(locationName) + 1, this->locationName);
		return locName;
	}
	

	//setters

	void setnr_seats(int x) {
		if (x > 0) {
			nr_seats = x;
		}
		else {
			throw  exception("Invalid number of seats!");

		}
	}

	void setnr_rows(int y) {
		if (y > 0) {
			nr_rows = y;
		}
		else {
			cout << "Invalid number of rows!" << endl;

		}
	}


	void setzones(const char* newzone)
	{
		if (this->zones != nullptr) {
			{
				delete[] this->zones;
			}
			zones = new char[strlen(newzone) + 1];
			strcpy_s(zones, strlen(newzone) + 1, newzone);
		}
		else {
			cout << "Invalid!" << endl;
		}
	}

	void setlocationName(const char* newlocationName)
	{
		if (this->locationName != nullptr) {
			{
				delete[] this->locationName;
			}
			locationName = new char[strlen(newlocationName) + 1];
			strcpy_s(locationName, strlen(newlocationName) + 1, newlocationName);
		}
	}
	

	
	//////// de adaugat operator +=

};

class Event {
	//date
	//location :address
	//name of the event



};

class Ticket {

};
class Date {
private:
	int day;
	int month;
	int year;
	int hour;
	int minute;
public:
	//constructor
	Date(int d, int m, int y, int h, int mi) :day(d), month(m), year(y), hour(h), minute(mi) {}

	//setters
	void setDate(int d, int m, int y, int h, int mi) {
		day = d;
		month = m;
		year = y;
		hour = h;
		minute = mi;
	}

	//getters
	int getDay() const{
		return day;

	}

	int getMonth() const {
		return month;
	}

	int getYear() const {
		return year;
	}

	int getHour() {
		return hour;
    }
	int getMinute() {
		return minute;
	}

	//here we validate if the date is VALID
	bool isValidDate() const {
		//we check the day
		if (day < 1 || day>31)
			return false;
		//we check the month 
		if (month < 1 || month>12)
			return  false;
		//for months with 30 days
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			return false;
		//verification for month: february
		if (month == 2) 
		{
			// Check for leap year
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (day > 29)
					return false;
			}
			else {
				if (day > 28)
					return false;
			}
		}

		//check the hour
		if (hour < 1 || hour>24)
			return false;
		//check the minute
		if (minute < 1 || minute>60)
			return false;

		return true;
	}

};

//adaugat clasa pt date


int main() {

	//location object
	Location c1(200, 200, "vip","sala palatului");//constructor with parameters
	Location c2 = c1;//copy constructor
	Location c3;//default constructor

	cout << "Number of seats in c3 is: " << c3.getnr_seats() << endl; //test def ctor

	////location details
	cout << "Number of seats: " << c1.getnr_seats() << endl;
	cout << "Number of rows: " << c1.getnr_rows() << endl;
	cout << "Zones: " << c1.getzones() << endl;
	cout<<"Location name: "<<c1.getlocationName()<<endl;
	
	
	c1.setnr_seats(400);
	c1.setnr_rows(300);
	c1.setzones("normal");
	c1.setlocationName("tnb");
	

	////new values
	cout << "\nUpdated nr of seats: " << c1.getnr_seats() << endl;
	cout << "Updated nr of rows: " << c1.getnr_rows() << endl;
	cout << "Updated zone: " << c1.getzones() << endl;
	cout<<"Updated location name: "<<c1.getlocationName()<<endl;
	

	


	return 0;
}