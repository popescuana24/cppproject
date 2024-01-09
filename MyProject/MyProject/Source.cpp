#include <iostream>
#include <string>
#include<fstream>


using namespace std;


class Location {
private:
	int nr_seats;
	int nr_rows;//nr randuri
	char* zones;//zonele
	int nrOfSeatsPerRow;
	bool** seats;


public: static const int MIN_SEATS = 5;
	  static int totalLocations;
public:


	// Default constructor
	Location() {

		nr_seats = 0;
		nr_rows = 0;
		zones = nullptr;
		nrOfSeatsPerRow = 0;
		seats = nullptr;

		totalLocations++;
	}

	//constructor with parameters
	Location(int nr_seats, int nr_rows, const char* zones, int nrOfSeatsPerRow) {
		this->nr_seats = nr_seats;

		this->nr_rows = nr_rows;

		this->zones = new char[strlen(zones) + 1];
		strcpy_s(this->zones, strlen(zones) + 1, zones);



		this->seats = new bool* [nr_rows];
		for (int i = 0; i < nr_rows; ++i) {
			seats[i] = new bool[nr_seats];
			for (int j = 0; j < nr_seats; ++j) {
				seats[i][j] = false; // Initialize seats as unbooked 
			}
		}

		this->nrOfSeatsPerRow = nrOfSeatsPerRow;

	}

	//copy constructor
	Location(const Location& other) {

		this->nr_seats = other.nr_seats;
		this->nr_rows = other.nr_rows;

		if (other.zones != NULL) {

			this->zones = new char[strlen(other.zones) + 1];
			strcpy_s(this->zones, strlen(other.zones) + 1, other.zones);
		}
		else {

			this->zones = nullptr;
		}

		this->nrOfSeatsPerRow = other.nrOfSeatsPerRow;

	}

	//destructor
	~Location() {
		if (zones != nullptr) {
			delete[] zones;
			zones = nullptr;
		}
		

		for (int i = 0; i < nr_rows; ++i) {
			delete[] seats[i];
		}
		delete[] seats;

		totalLocations--;
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

	virtual void setnr_seats(int x) {
		if (x > 0) {
			nr_seats = x; 
		}
		else {
			cout << "Invalid number of seats!" << endl;
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

	void setnrOfSeatsPerRow(int z) {
		if (z > 0) {
			nrOfSeatsPerRow = z;
		}
		else {
			cout << "Invalid number of rows!" << endl;

		}
	}




	// Method to book a specific seat
	bool bookSpecificSeat(int row, int seat) {
		if (row >= 0 && row < nr_rows && seat >= 0 && seat < nr_seats) {
			if (!seats[row][seat]) {
				seats[row][seat] = true; // Book the seat
				return true; // Successfully booked
			}
			else {
				return false; // Seat already booked
			}
		}
		else {
			return false; // Invalid row or seat
		}
	}

	// Method to check if a specific seat is booked
	bool isSeatBooked(int row, int seat) {
		if (row >= 0 && row < nr_rows && seat >= 0 && seat < nr_seats) {
			return seats[row][seat];
		}
		else {
			return false; // Invalid row or seat
		}
	}

	//overloading operator +=
	Location& operator+=(int addSeats) {
		if (addSeats > 0) {
			nr_seats += addSeats;
		}
		else {
			throw exception("Invalid number of additional seats!");
		}
		return *this;
	}

	//overloading operator-=
	Location& operator-=(int removeSeats) {
		if (removeSeats > 0) {
			nr_seats -= removeSeats;
		}
		else {
			throw exception("Invalid number of additional seats!");
		}
		return *this;
	}
	// Static method to get total locations
	static int getTotalLocations() {
		return totalLocations;
	}

	// Overloading  operator <<
	friend ostream& operator<<(ostream& out, const Location& loc) {
		out << "Number of seats: " << loc.nr_seats << "\nNumber of rows: " << loc.nr_rows << "\nZones: " << loc.zones << "\nNumber of seats per row: " << loc.nrOfSeatsPerRow;
		return out;
	}
	// Overloading  operator >>
	friend istream& operator>>(istream& in, Location& loc) {
		int seats, rows, seatsPerRow;
		char* zones = new char[100];

		cout << "Enter number of seats: ";
		in >> seats;
		loc.setnr_seats(seats);

		cout << "Enter number of rows: ";
		in >> rows;
		loc.setnr_rows(rows);

		cout << "Enter zones: ";
		in >> zones;
		loc.setzones(zones);

		cout << "Enter number of seats per row: ";
		in >> seatsPerRow;
		loc.setnrOfSeatsPerRow(seatsPerRow);

		loc.seats = new bool* [rows];
		for (int i = 0; i < rows; ++i) {
			loc.seats[i] = new bool[seats];
			for (int j = 0; j < seats; ++j) {
				loc.seats[i][j] = false; // Initialize seats as unbooked
			}
		}

		delete[] zones;

		return in;
	}

};

int Location::totalLocations = 0;


class Date {
private:
	int day;
	int month;
	int year;
	int hour;
	int minute;
public:
	//default constructor
	Date() {
		day = 0;
		month = 0;
		year = 0;
		hour = 0;
		minute = 0;
	}
	//constructor with parameters
	Date(int d, int m, int y, int h, int mi) :day(d), month(m), year(y), hour(h), minute(mi) {}

	//copy constructor

	Date(const Date& other) {

		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->hour = other.hour;
		this->minute = other.minute;
	}

	//setters
	void setDate(int day, int month, int year, int hour, int minute) {
		this->day = day;
		this->month = month;
		this->year = year;
		this->hour = hour;
		this->minute = minute;
	}

	//getters
	int getDay() const {
		return day;

	}

	int getMonth() const {
		return month;
	}

	int getYear() const {
		return year;
	}

	int getHour() const {
		return hour;
	}
	int getMinute() const {
		return minute;
	}

	// we validate if the date is VALID
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


	// Overloading stream insertion operator <<
	friend ostream& operator<<(ostream& out, const Date& date) {
		out << "Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " " << date.getHour() << ":" << date.getMinute();
		return out;
	}

	// Overloading stream extraction operator >>
	friend istream& operator>>(istream& in, Date& date) {
		in >> date.day >> date.month >> date.year >> date.hour >> date.minute;
		return in;
	}

	//operator ==
	bool operator==(const Date& other) const {
		return day == other.day &&
			month == other.month &&
			year == other.year &&
			hour == other.hour &&
			minute == other.minute;
	}

	//operator !=
	bool operator!=(const Date& other) const {
		return !(*this == other);
	}


};


class Event {
private:

	string eventName;
	Date eventDate;


public:
	//default constructor 
	Event() {
		eventName = "";
	}
	//constructor with parameters
	Event(string eventName) : eventName(eventName) {}

	//copy constructor
	Event(const Event& other) {
		this->eventName = other.eventName;
	}


	//setters
	void seteventName(const string& eventName) {
		this->eventName = eventName;


	}

	//getters
	string geteventName() const {
		return eventName;
	}
	const Date& geteventDate() const {
		return eventDate;
	}

	// Setter for eventDate
	void seteventDate(const Date& date) {
		eventDate = date;
	}
	// Overloading stream insertion operator <<
	friend ostream& operator<<(ostream& out, const Event& event) {
		out << "Event name: " << event.eventName << "\nEvent  " << event.eventDate;
		return out;
	}

	// Overloading  operator >>
	friend istream& operator>>(istream& in, Event& event) {
		cout << "\nEnter the event name: ";
		getline(in >> ws, event.eventName);

		int day, month, year, hour, minute;
		cout << "\nEnter the day: ";
		in >> day;
		cout << "Enter the month: ";
		in >> month;
		cout << "Enter the year: ";
		in >> year;
		cout << "Enter the hour: ";
		in >> hour;
		cout << "Enter the minute: ";
		in >> minute;

		// Constructing the eventDate using the provided components
		event.eventDate.setDate(day, month, year, hour, minute);

		return in;
	}


};


class generateticket {

private:
	int ticketID;

public:
	// Default constructor
	generateticket() {
		ticketID = generateID();
	}

	// Constructor  parameters
	generateticket(int id) : ticketID(id) {}

	// Copy constructor
	generateticket(const generateticket& other) {
		this->ticketID = other.ticketID;
	}

	// Function to generate a random ticket ID
	int generateID() {
		srand(static_cast<unsigned int>(time(0)));
		return rand() % 10000 + 1000; // Generate a random number between 1000 and 9999
	}

	// Getter 
	int getTicketID() const {
		return ticketID;
	}

	void setTicketID(int id) {
		ticketID = id;
	}


	//overloading operator =
	generateticket& operator=(const generateticket& other) {
		if (this != &other) {
			ticketID = other.ticketID;
		}
		return *this;
	}

	//overloading operator +
	generateticket operator+(const generateticket& other) const {
		int newID = ticketID + other.ticketID; // Combine ticketIDs
		return generateticket(newID); // Return a new generateticket 
	}




};

class ReservedLocation : public Location {
private:
	int reservations;

public:
	ReservedLocation() : reservations(0) {}

	ReservedLocation(int nr_seats, int nr_rows, const char* zones, int nrOfSeatsPerRow, int reservations)
		: Location(nr_seats, nr_rows, zones, nrOfSeatsPerRow), reservations(reservations) {}


	void addReservation(int num) {
		reservations += num;
	}

	// Override function from Location
	void setnr_seats(int x) override {
		if (x >= 5) {
			Location::setnr_seats(x); 
			reservations = 0; // Reset reservations if seats are updated
		}
		else {
			throw exception("Invalid number of seats!");
		}
	}

	//  functionality 
	void displayReservations() {
		cout << "Number of reservations: " << reservations << endl;
	}
};


int main() {



	// Display updated location details after booking
	//cout << "\nUpdated Location details:\n";
	//cout << c9 << endl;



	//location object
	//Location c1(50, 50, "vip", 10);//constructor with parameters
	//Location c2 = c1;//copy constructor
	//Location c3;//default constructor

	////location details
	/*cout << "Total number of seats: " << c1.getnr_seats() << endl;
	cout << "Total number of rows: " << c1.getnr_rows() << endl;
	cout << "Zones: " << c1.getzones() << endl;
	cout << "Number of seats per row: " << c1.getnrOfSeatsPerRow() << endl;

	c*///out << "\nNumber of seats in c3 is: " << c3.getnr_seats() << endl; //test default  constructor

	//operator +=
	//Location c4;
	//c4.setnr_seats(10);
	//cout << "\nInitial number of seats: " << c4.getnr_seats() << endl;

	//c4 += 5; // Adding 5 more seats
	//cout << "Updated number of seats after adding: " << c4.getnr_seats() << endl;

	//operator -=
	//Location c5;
	//c5.setnr_seats(10);
	//cout << "\nInitial number of seats: " << c5.getnr_seats() << endl;

	//c5 -= 5;//removing 5 seats
	//cout << "Updated number of seats after removing: " << c5.getnr_seats() << endl;



	//Date date(0, 0, 0, 0, 0);
	//Date date1 = date;//copy constructor

	// Set the date
	//int day, month, year, hour, minute;
	//cout << "\nInput day: ";
	//cin >> day;
	//cout << "Input month: ";
	//cin >> month;
	//cout << "Input year: ";
	//cin >> year;
	//cout << "Input hour: ";
	//cin >> hour;
	//cout << "input minute: ";
	//cin >> minute;

	//date.setDate(day, month, year, hour, minute);

	// Get and display the date
	//cout << "\nDate: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << ", " << date.getHour() << ":" << date.getMinute() << endl;

	// Validate the date
	//if (date.isValidDate())
		//cout << "The date is valid." << endl;
	//else
		//cout << "The date is invalid." << endl;

	//Event details(" ");
	//string eventName;
	//cout << "\nEnter the event name: ";
	//cin >> eventName;

	//details.seteventName(eventName);
	//cout << "Event name: " << details.geteventName();

	//Event event;

	// Input using >>
	//cin >> event;

	// Output using <<
	//cout << "\nEVENT DETAILS\n" << event << endl;

	// Creating a generateticket object
	//generateticket ticket;

	//test the constructor with parameters
	//generateticket ticket1(1001);

	// Creating another object using the copy constructor
	//generateticket ticket2(ticket1);

	// Displaying the ticket ID
	//cout << "Ticket ID: " << ticket.getTicketID() << endl;

	//test the operator +
	//generateticket ticket1(1001);
	//generateticket ticket2(2002);

	/*generateticket ticket3 = ticket1 + ticket2;
	cout << "\nTicket ID 1: " << ticket1.getTicketID() << endl;
	cout << "Ticket ID 2: " << ticket2.getTicketID() << endl;
	cout << "The sum between ticket ID 1 and ticket ID 2: " << ticket3.getTicketID() << endl;*/

	//test the operator =
	/*ticket2 = ticket1;
	cout << "\nTicket 2 takes the ID of ticket 1" << endl;
	cout << "Ticket 1 ID: " << ticket1.getTicketID() << endl;
	cout << "Ticket 2 ID: " << ticket2.getTicketID() << endl;*/

	//  setTicketID function
	//generateticket ticket4;
	//int newID = 9999; // Replace this with your desired ID
	//ticket.setTicketID(newID);

	


	int key;
	cout << "WELCOME TO THE MENU!\n";
	cout << "\nPRESS KEY 1 if you want to enter the data from the console\n";
	cout << "PRESS KEY 2 if you want to read the data from a text file\n";
	cout << "PRESS KEY 3 if you want to EXIT\n";
	
	cout << "\nEnter your choice: ";
	cin >> key;

	if (key == 1) {
		int seats, rows, seatsPerRow;
		char zones[100];

		cout << "\nLET'S ENTER THE LOCATION DETAILS!" << endl;
		cout << "Enter number of seats: ";
		cin >> seats;

		cout << "Enter number of rows: ";
		cin >> rows;

		cout << "Enter zones: ";
		cin.ignore();
		cin.getline(zones, 100);

		cout << "Enter number of seats per row: ";
		cin >> seatsPerRow;

		// Create a Location object 
		Location c9(seats, rows, zones, seatsPerRow);

		// Display  location details
		cout << "\n[ LOCATION DETAILS ]\n";
		cout << c9 << endl;

		cout << "\nCHOOSE YOUR ROW AND YOUR SEAT! " << endl;
		//  Booking specific seats
		int rowToBook, seatToBook;

		cout << "Enter row number you want to book: ";
		cin >> rowToBook;

		cout << "Enter seat number you want to book: ";
		cin >> seatToBook;

		// Book the specified seat using bool** seats
		if (c9.bookSpecificSeat(rowToBook, seatToBook)) {
			cout << "ROW " << rowToBook << " SEAT " << seatToBook << " successfully booked!" << endl;
		}
		else {
			cout << "ROW " << rowToBook << " SEAT " << seatToBook << " is already booked!" << endl;
		}


       // Check if a seat is booked
		int rowToCheck, seatToCheck;

		cout << "\nEnter another row number to check if it's available: ";
		cin >> rowToCheck;

		cout << "Enter another seat number to check if it's available: ";
		cin >> seatToCheck;

		// Check if the specified seat is booked
		if (c9.isSeatBooked(rowToCheck, seatToCheck)) {
			cout << "Row " << rowToCheck << " Seat " << seatToCheck << " is already booked." << endl;
		}
		else {
			cout << "Row " << rowToCheck << " Seat " << seatToCheck << " is available." << endl;
		}

		cout << "\nENTER THE EVENT DETAILS!" << endl;
		Event event;

		// Input using >>
		cin >> event;

		// Output using <<
		cout << "\n[ TICKET DETAILS ]\n" << event << endl;

		// Creating a generateticket object
		generateticket ticket;
		cout << "Ticket ID: " << ticket.getTicketID() << endl;

		//the seat and row
		cout << "Seat: " << seatToBook << endl;
		cout << "Row: " << rowToBook << endl;
	}
	else if (key == 2) {
		//READING FROM A TEXT FILE
		ifstream inFile("display_details.txt", ios::in);

		if (inFile.is_open()) {
			// Read data for Location
			int nr_seats, nr_rows, nrOfSeatsPerRow;
			string zones;

			inFile >> nr_seats >> nr_rows >> zones >> nrOfSeatsPerRow;
			Location location(nr_seats, nr_rows, zones.c_str(), nrOfSeatsPerRow);

			// Read data for Date
			int day, month, year, hour, minute;
			inFile >> day >> month >> year >> hour >> minute;
			Date eventDate(day, month, year, hour, minute);

			// Read data for Event
			inFile.ignore();
			string eventName;
			getline(inFile, eventName);

			Event event(eventName);
			event.seteventDate(eventDate);

			// Read data for generateticket
			int ticketID;
			inFile >> ticketID;
			generateticket ticket(ticketID);

			// read
			cout << "\nLocation details:\n" << location << endl;
			cout << "\nEvent details:\n";
			cout << "Event name: " << event.geteventName() << endl;
			cout << "Event date: " << event.geteventDate().getDay() << "/" << event.geteventDate().getMonth() << "/"
				<< event.geteventDate().getYear() << " " << event.geteventDate().getHour() << ":"
				<< event.geteventDate().getMinute() << endl;
			cout << "Ticket ID: " << ticket.getTicketID() << endl;



			inFile.close();
		}
		else {
			cout << "Unable to open file for reading." << endl;
		}
	}
	//EXIT THE PROGRAM
	else if (key == 3) {
		cout << "PRESS ANY KEY TO EXIT" << endl;
	}
	


	return 0;
}

