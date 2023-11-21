#include <iostream> 
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Cinema {
private:
	int nr_seats;
	int nr_rows;
	char* zones;
	int nrOfSeatsPerRow;
public:

	// Default constructor
	Cinema() {
		nr_seats = 0;
		nr_rows = 0;
		zones = nullptr;
		nrOfSeatsPerRow = 0;
	}

	//constructor with parameters
	Cinema(int nr_seats, int nr_rows, const char* zones, int nrOfSeatsPerRow) {
		this->nr_seats = nr_seats;

		this->nr_rows = nr_rows;

		this->zones = new char[strlen(zones) + 1];
		strcpy_s(this->zones, strlen(zones) + 1, zones);

		this->nrOfSeatsPerRow = nrOfSeatsPerRow;
	}

	//copy constructor

	Cinema(const Cinema& other) {

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
		}

		this->nrOfSeatsPerRow = other.nrOfSeatsPerRow;
	}

	//destructor
	~Cinema() {
		if (this->zones != NULL) {
			delete[]this->zones;
			this->zones = nullptr;
		}
	}


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

	int getnrOfSeatsPerRow() {
		return this->nrOfSeatsPerRow;
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


	void setnrOfSeatsPerRow(int z) {
		if (z > 0) {
			nrOfSeatsPerRow = z;
		}
		else {
			cout << "Invalid number of seats per row!" << endl;

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

	//method 1 to calculate the total number of seats
	int TotalSeats() {
		return nrOfSeatsPerRow * nr_rows;
	}

	//method 2 
	bool CinemaFull() {
		return TotalSeats() == 0;
	}

	//negation operator "!"
	bool operator!() {
		return TotalSeats() == 0;
	}

};

int main() {

	//cinema object
	Cinema c1(200, 200, "vip", 200);//constructor with parameters
	Cinema c2 = c1;//copy constructor
	Cinema c3;//default constructor

	//cinema details
	cout << "Number of seats: " << c1.getnr_seats() << endl;
	cout << "Number of rows: " << c1.getnr_rows() << endl;
	cout << "Zones: " << c1.getzones() << endl;
	cout << "Number of seats per row: " << c1.getnrOfSeatsPerRow() << endl;

	c1.setnr_seats(400);
	c1.setnr_rows(300);
	c1.setzones("normal");
	c1.setnrOfSeatsPerRow(300);

	//new values
	cout << "\nUpdated nr of seats: " << c1.getnr_seats() << endl;
	cout << "Updated nr of rows: " << c1.getnr_rows() << endl;
	cout << "Updated zone: " << c1.getzones() << endl;
	cout << "Updated nrOfSeatsPerRow" << c1.getnrOfSeatsPerRow() << endl;

	//method 1 result
	cout << "\nTotal number of seats: " << c1.TotalSeats() << endl;

	//method 2 result
	cout << "\nIs cinema full? " << (c1.CinemaFull() ? "Yes" : "No") << endl;

	//negation operator "!"
	cout<<"\nIs cinema empty?"<<(!c1 ? "Yes" : "No") << endl;


	return 0;
}