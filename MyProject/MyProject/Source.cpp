#include <iostream>
#include <string>


using namespace std;


class Location { 
private:
	int nr_seats=0;//nr total locuri
	int nr_rows;//nr randuri
	char* zones;//zonele
	int nrOfSeatsPerRow;

	
public: static const int MIN_SEATS = 5;
public:


	// Default constructor
	Location() {

		nr_seats = 0;
		nr_rows = 0;
		zones = nullptr;
		nrOfSeatsPerRow=0;
	}

	//constructor with parameters
	Location(int nr_seats, int nr_rows, const char* zones,  int nrOfSeatsPerRow) {
		this->nr_seats = nr_seats;

		this->nr_rows = nr_rows;

		this->zones = new char[strlen(zones) + 1];
		strcpy_s(this->zones, strlen(zones) + 1, zones);

		this->nrOfSeatsPerRow = nrOfSeatsPerRow;

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

		this->nrOfSeatsPerRow = other.nrOfSeatsPerRow;

	}

	//destructor
	~Location() {
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
		if (x >=MIN_SEATS) {
			this->nr_seats = x;
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

	void setnrOfSeatsPerRow(int z) {
		if (z > 0) {
			nrOfSeatsPerRow = z;
		}
		else {
			cout << "Invalid number of rows!" << endl;

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
	

};
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
	// Overloading stream insertion operator <<
	friend ostream& operator<<(ostream&out, const Date& date) {
		out << "Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " " << date.getHour() << ":" << date.getMinute();
		return out;
	}

	// Overloading stream extraction operator >>
	friend istream& operator>>(istream& in, Date& date) {
		in >> date.day >> date.month >> date.year >> date.hour >> date.minute;
		return in;
	}
	};


class Event {
private:

	string eventName;
	Date eventDate;

	
public: 
	//default constructor 
	Event()   {
		eventName = "";
	}
	//constructor with parameters
	Event (string eventName): eventName(eventName) {}

	//copy constructor
	Event(const Event& other) {
		this->eventName = eventName;
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
		out << "Event Name: " << event.eventName << "\nEvent  " << event.eventDate;
		return out;
	}

	// Overloading stream extraction operator >>
	friend istream& operator>>(istream& in, Event& event) {
		cout << "\nEnter the event name: ";
		getline(in>> ws, event.eventName);

		cout << "\nEnter the event date: "<<endl;
		in >> event.eventDate;

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

	//overloading operator =
	generateticket& operator=(const generateticket& other) {
		if (this != &other) {
			ticketID = other.ticketID; // Copy the ticketID from 'other' object
		}
		return *this;
	}

	//overloading operator +
	generateticket operator+(const generateticket& other) const {
		int newID = ticketID + other.ticketID; // Combine ticketIDs
		return generateticket(newID); // Return a new generateticket 
	}
};



int main() {

	//location object
	Location c1(200, 50, "vip",4);//constructor with parameters
	Location c2 = c1;//copy constructor
	Location c3;//default constructor

	////location details
	cout << "Total number of seats: " << c1.getnr_seats() << endl;
	cout << "Total number of rows: " << c1.getnr_rows() << endl;
	cout << "Zones: " << c1.getzones() << endl;
	cout<<"Number of seats per row: "<<c1.getnrOfSeatsPerRow()<<endl; 

	cout << "\nNumber of seats in c3 is: " << c3.getnr_seats() << endl; //test default  constructor

	//operator +=
	Location c4;
	c4.setnr_seats(10);
	cout << "\nInitial number of seats: " << c4.getnr_seats() << endl;

	c4 += 5; // Adding 5 more seats
	cout << "Updated number of seats after adding: " << c4.getnr_seats() << endl;

	//operator -=
	Location c5;
	c5.setnr_seats(10);
	cout << "\nInitial number of seats: " << c5.getnr_seats() << endl;

	c5 -= 5;//removing 5 seats
	cout << "Updated number of seats after removing: " << c5.getnr_seats()<< endl;

	
	Date date(0, 0, 0, 0, 0);
	Date date1 = date;//copy constructor
	
	// Set the date
	int day, month, year, hour, minute;
	cout << "\nInput day: ";
	cin >> day;
	cout << "Input month: ";
	cin >> month;
	cout << "Input year: ";
	cin >> year;
	cout << "Input hour: ";
	cin >> hour;
	cout << "input minute: ";
	cin >> minute;

	date.setDate(day, month, year, hour, minute);

	// Get and display the date
	cout << "\nDate: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << ", " << date.getHour() <<":"<< date.getMinute() << endl;

	// Validate the date
	if (date.isValidDate())
		cout << "The date is valid." << endl;
	else
		cout << "The date is invalid." << endl;

	Event details(" ");
	string eventName;
	cout << "\nEnter the event name: ";
	cin >> eventName;

details.seteventName(eventName);
	cout << "Event name: " << details.geteventName();

	Event event;

	// Input using >>
	cin >> event;

	// Output using <<
	cout << "\nEVENT DETAILS\n" << event << endl;
	
    // Creating a generateticket object
	generateticket ticket;

    //test the constructor with parameters
	//generateticket ticket1(1001);

	// Creating another object using the copy constructor
	//generateticket ticket2(ticket1);

    // Displaying the ticket ID
	cout << "Ticket ID: " << ticket.getTicketID() << endl;

	//test the operator +
	generateticket ticket1(1001);
	generateticket ticket2(2002);

	generateticket ticket3 = ticket1 + ticket2;
    cout << "\nTicket ID 1: " << ticket1.getTicketID() << endl;
	cout << "Ticket ID 2: " << ticket2.getTicketID() << endl;
	cout << "The sum between ticket ID 1 and ticket ID 2: " << ticket3.getTicketID() << endl;

	//test the operator =
	ticket2 = ticket1;
	cout << "\nTicket 2 takes the ID of ticket 1" << endl;
	cout << "Ticket 1 ID: " << ticket1.getTicketID() << endl;
	cout << "Ticket 2 ID: " << ticket2.getTicketID() << endl;
	
	return 0;
}