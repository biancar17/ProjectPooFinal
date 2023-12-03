#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Event {
	string nameEvent;
	string dateOfEvent;
	string timeOfEvent;

public:
	Event() {
		this->nameEvent = " ";
		this->dateOfEvent = " ";
		this->timeOfEvent = " ";
	
	}
	string getNameEvent() {
		return this->nameEvent;
	}
	string getDateOfEvent() {
		return this->dateOfEvent;
	}
	string getTimeOfEvent() {
		return this->timeOfEvent;
	}

	void setNameEvent(string nameEvent) {
		this->nameEvent = nameEvent;
	}
	void setDateOfEvent(string dateOfEvent) {
		this->dateOfEvent = dateOfEvent;
	}
	void setTimeOfEvent(string timeOfEvent) {
		this->timeOfEvent = timeOfEvent;
	}

	Event(string nameEvent, string dateOfEvent, string timeOfEvent) {
		this->nameEvent = nameEvent;
		this->dateOfEvent = dateOfEvent;
		this->timeOfEvent = timeOfEvent;
	}

	Event(const Event& c) {
		this->nameEvent = c.nameEvent;
		this->dateOfEvent = c.dateOfEvent;
		this->timeOfEvent = c.timeOfEvent;
	}

	friend istream& operator>>(istream& in, Event& c) {
		cout << "Name of Event: ";
		in >> c.nameEvent;
		cout << "Date of Event: ";
		in>> c.dateOfEvent;
		cout << "Time of Event: ";
		in>> c.timeOfEvent;

		return in;
	}
	friend ostream& operator<<(ostream& out, Event& c) {
		out <<"Name of Event: " << c.nameEvent << endl;
		out<<"Date of Event: "<< c.dateOfEvent << endl;
		out<<"Time of Event: "<< c.timeOfEvent << endl;

		return out;
	}

	Event& operator=(const Event& c) {
		if (this != &c) {
			this->nameEvent = c.nameEvent;
			this->dateOfEvent = c.dateOfEvent;
			this->timeOfEvent = c.timeOfEvent;
		}
		return *this;
	}
};

class Tickets {
	const int ticketId;
	int category;
	int price;
	int* pricesPerCategory;

	static const int maxNumberOfTickets = 1000;

public:
	Tickets() : ticketId(0){

		this->category = 0;
		this->price = 0;
		this->pricesPerCategory = 0;
	}
	int getMaxNumberOfTickets() {
		return this->maxNumberOfTickets;
	}
	int getTicketId() {
		return this->ticketId;
	}
	int getPrice() {
		return this->price;
	}
	int getCategory() {
		return this->category;
	}
	void setCategory(int category) {
		this->category = category;
	}
	void setPrice(int price) {
		this->price = price;
	}
	void setPricesPerCategory() {
		delete[] this->pricesPerCategory;
		this->pricesPerCategory = nullptr;
		this->pricesPerCategory = new int[category];
		for (int i = 0; i < category; i++) {
			cout << "Category: " << i + 1 << " ";
			cin >> pricesPerCategory[i];
			this->pricesPerCategory[i] = pricesPerCategory[i];
		}
		cout << endl;
	}

	Tickets(int category, int price, int pricesPerCategory) : ticketId(0) {

		this->category = category;
		this->price = price;
		this->pricesPerCategory = new int[category];
		for (int i = 0; i < this->category; i++)
		{
			this->pricesPerCategory[i] = 0;
		}
	}

	~Tickets() {
		if (this->pricesPerCategory != nullptr) {
			delete[] this->pricesPerCategory;
			this->pricesPerCategory = nullptr;
		}
	}

	Tickets(const Tickets& c):ticketId(c.ticketId) {
		this->category = c.category;
		this->price = c.price;
		this->pricesPerCategory = new int[c.category];
		for (int i = 0; i < this->category; i++)
		{
			this->pricesPerCategory[i] = c.pricesPerCategory[i];
		}

	}

	Tickets& operator=(const Tickets& c) {
		if (this != &c) {
			delete[] this->pricesPerCategory;
			this->category = c.category;
			this->price = c.price;
			this->pricesPerCategory = new int[c.category];
			for (int i = 0; i < this->category; i++) {
				this->pricesPerCategory[i] = c.pricesPerCategory[i];
			}
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Tickets& c) {
		cout << "Category: ";
		in >> c.category;
		cout << "Price: ";
		in >> c.price;
		for (int i = 0; i < c.category; i++)
		{
			in >> c.pricesPerCategory[i];
		}

		return in;
	}

	friend ostream& operator<<(ostream& out, Tickets& c) {
		out<<"Category: "<< c.category << endl;
		out<<"Price: "<< c.price << endl;
		out << "Prices Per Category: ";
		for (int i = 0; i < c.category; i++) {
			out << c.pricesPerCategory[i] << " ";
		}
		out << endl;

		return out;
	}

};

class Location {

	const int maxNumberOfSeats; //constant field
	int locationId;
	char* nameRoom; //dynamically allocated vector of characters
	int noOfname;
	const char* nameZones[3] = { "VIP", "Regular", "Premium" };// "VIP", "Regular", "Premium"
	char* nameZone;
	int numberOfRows;
	int* numberOfSeatsPerRow;//dynamically allocated numeric vector
	static int totalLocations; //static field

public:
	Location() :maxNumberOfSeats(0) {
		this->locationId = 0;
		this->numberOfRows = 0;
		this->nameRoom = new char[strlen("A") + 1];
		strcpy(this->nameRoom, "A");
		this->noOfname = 0;
		this->nameZone = new char[strlen("VIP") + 1];
		strcpy_s(this->nameZone, strlen("VIP") + 1, "VIP");
		this->numberOfSeatsPerRow = nullptr;
	}

	int getLocationId() {
		return this->locationId;
	}
	int getNumberOfRows() {
		int copyNumberOfRows = this->numberOfRows;
		return copyNumberOfRows;
	}
	char* getNameRoom() {
		return this->nameRoom;
	}
	int getNoOfname() {
		return this->noOfname;
	}
	char* getNameZone() {
		return this->nameZone;
	}
	int* getNumberOfSeatsPerRow() {
		return this->numberOfSeatsPerRow;
	}
	int getTotalLocations() {
		return this->totalLocations;
	}

	void setLocationId(int locationId) {
		this->locationId = locationId;
	}
	void setNumberOfRows(int numberOfRows) {
		this->numberOfRows = numberOfRows;
	}
	void setNameZone(const char* nameZone) {
		this->nameZone = new char[strlen(nameZone) + 1];
		strcpy_s(this->nameZone, strlen(nameZone) + 1, nameZone);
	}
	void setNameRoom(const char* nameRoom) {
		this->nameRoom = new char[strlen(nameRoom) + 1];
		strcpy_s(this->nameRoom, strlen(nameRoom) + 1, nameRoom);
	}
	void setNoOfname(int noOfname) {
		this->noOfname = noOfname;
	}
	void setNumberOfSeatsPerRow(int* numberOfSeatsPerRow, int numberOfRows) {
		// Delete the existing array to avoid memory leaks
		delete[] this->numberOfSeatsPerRow;

		// Set the pointer to nullptr after deletion
		this->numberOfSeatsPerRow = nullptr;

		// Allocate memory for the new array
		this->numberOfSeatsPerRow = new int[numberOfRows];

		// Copy the values from the input array to the member array
		for (int i = 0; i < numberOfRows; i++) {
			cout << "Row " << i + 1 << " ";
			cin >> numberOfSeatsPerRow[i];
			this->numberOfSeatsPerRow[i] = numberOfSeatsPerRow[i];
		}
		cout << endl;
	}

	Location(int locationId, int maxNumberOfSeats, int numberOfRows, const char* nameRoom, int noOfname, const char* nameZone, int* numberOfSeatsPerRow) :maxNumberOfSeats(1000)
	{
		this->locationId = locationId;

		if (numberOfRows > 0)
		{
			this->numberOfRows = numberOfRows;
		}
		else
		{
			this->numberOfRows = 0;
		}
		this->nameRoom = new char[strlen(nameRoom) + 1];
		strcpy_s(this->nameRoom, strlen(nameRoom) + 1, nameRoom);

		this->noOfname = noOfname;

		this->nameZone = new char[strlen(nameZone) + 1];
		strcpy_s(this->nameZone, strlen(nameZone) + 1, nameZone);
		if (numberOfSeatsPerRow != nullptr && numberOfRows > 0)
		{
			this->numberOfSeatsPerRow = new int[this->numberOfRows];
			for (int i = 0; i < this->numberOfRows; i++)
			{
				if (numberOfSeatsPerRow[i] < maxNumberOfSeats)
				{
					this->numberOfSeatsPerRow[i] = numberOfSeatsPerRow[i];
				}
				else
				{
					this->numberOfSeatsPerRow[i] = maxNumberOfSeats;
				}
			}
		}
		else
		{
			this->numberOfRows = numberOfRows;
			this->numberOfSeatsPerRow = nullptr;

		}

	}

	~Location() {
		if (this->nameRoom != nullptr) {
			delete[] this->nameRoom;
			this->nameRoom = nullptr;
		}
		if (this->nameZone != nullptr) {
			delete[] this->nameZone;
			this->nameZone = nullptr;
		}
		if (this->numberOfSeatsPerRow != nullptr) {
			delete[] this->numberOfSeatsPerRow;
			this->numberOfSeatsPerRow = nullptr;
		}
	}

	Location(const Location& c) :maxNumberOfSeats(1000) {
		this->locationId = c.locationId;

		if (c.numberOfRows > 0)
		{
			this->numberOfRows = c.numberOfRows;
		}
		else
		{
			this->numberOfRows = 0;
		}
		this->nameRoom = new char[strlen(c.nameRoom) + 1];
		strcpy_s(this->nameRoom, strlen(c.nameRoom) + 1, c.nameRoom);

		this->noOfname = c.noOfname;

		this->nameZone = new char[strlen(c.nameZone) + 1];
		strcpy_s(this->nameZone, strlen(c.nameZone) + 1, c.nameZone);

		if (c.numberOfSeatsPerRow != nullptr && c.numberOfRows > 0)
		{
			this->numberOfSeatsPerRow = new int[c.numberOfRows];
			for (int i = 0; i < this->numberOfRows; i++)
			{
				if (c.numberOfSeatsPerRow[i] < c.maxNumberOfSeats)
				{
					this->numberOfSeatsPerRow[i] = c.numberOfSeatsPerRow[i];
				}
				else
				{
					this->numberOfSeatsPerRow[i] = c.maxNumberOfSeats;
				}
			}
		}
		else
		{
			this->numberOfRows = c.numberOfRows;
			this->numberOfSeatsPerRow = nullptr;

		}
	}

	friend istream& operator>>(istream& in, Location& c) {
		cout << "Location ID: ";
		in >> c.locationId;
		if (c.nameRoom != nullptr) {
			delete[] c.nameRoom;
		}
		char buffer[200];
		cout << "Name Room: "<<endl;
		in>>buffer; //write location without space
		c.setNameRoom(buffer);
		if (c.nameZone != nullptr) {
			delete[] c.nameZone;
		}
		char buffer1[200];
		cout << "Name Zone: "<<endl;
		in>>buffer1; //write location without space
		c.setNameZone(buffer1);
		cout << "Number of rows: ";
		in >> c.numberOfRows;
		if (c.numberOfSeatsPerRow != nullptr) {
			delete[] c.numberOfSeatsPerRow;
		}
		c.numberOfSeatsPerRow = new int[c.numberOfRows];
		for (int i = 0; i < c.numberOfRows; i++) {
			cout << "Row " << i << endl;
			in >> c.numberOfSeatsPerRow[i];
		}

		return in;
	}

	friend ostream& operator<<(ostream& out, const Location& c) {
		out << "Location Id: " << c.locationId << endl;
		out << "Name Room: " << c.nameRoom << endl;
		out << "Name Zone: " << c.nameZone << endl;
		out << "Number of Rows: " << c.numberOfRows << endl;
		for (int i = 0; i < c.numberOfRows; i++) {
			out << "Row " << i + 1 << ": " << c.numberOfSeatsPerRow[i] << " seats" << endl;
		}
		return out;
	}

	Location& operator=(const Location& c) {
		this->locationId = c.locationId;

		if (c.numberOfRows > 0)
		{
			this->numberOfRows = c.numberOfRows;
		}
		else
		{
			this->numberOfRows = 0;
		}
		this->nameRoom = new char[strlen(c.nameRoom) + 1];
		strcpy_s(this->nameRoom, strlen(c.nameRoom) + 1, c.nameRoom);

		this->noOfname = c.noOfname;

		this->nameZone = new char[strlen(c.nameZone) + 1];
		strcpy_s(this->nameZone, strlen(c.nameZone) + 1, c.nameZone);

		if (c.numberOfSeatsPerRow != nullptr && c.numberOfRows > 0)
		{
			this->numberOfSeatsPerRow = new int[c.numberOfRows];
			for (int i = 0; i < this->numberOfRows; i++)
			{
				if (c.numberOfSeatsPerRow[i] < c.maxNumberOfSeats)
				{
					this->numberOfSeatsPerRow[i] = c.numberOfSeatsPerRow[i];
				}
				else
				{
					this->numberOfSeatsPerRow[i] = c.maxNumberOfSeats;
				}
			}
		}
		else
		{
			this->numberOfRows = c.numberOfRows;
			this->numberOfSeatsPerRow = nullptr;

		}
		return *this;
	}
};

int Location::totalLocations = 10;

int main()
{
	Event e1;
	cout << "Initialization" << endl;
	cout << e1.getNameEvent() << endl;
	cout << e1.getDateOfEvent() << endl;
	cout << e1.getTimeOfEvent() << endl;

	e1.setNameEvent("Movie Night");
	e1.setDateOfEvent("17.09.2023");
	e1.setTimeOfEvent("20:00");

	cout << "Event name:  " << e1.getNameEvent() << endl;
	cout << "Date of event: " << e1.getDateOfEvent() << endl;
	cout << "Time of event: " << e1.getTimeOfEvent() << endl;

	Event e2("Movie Night", "17.09.2023", "20:00");

	cin >> e2;
	cout << e2;

	cout << "-------------------------------" << endl;

	Tickets t1;

	int pricesCategories[3] = { 100, 200, 300 };

	Tickets t2(1, 100, 100);

	cin >> t2;
	cout << t2;

	cout << "-------------------------------" << endl;

	Location l1;
	cout << "Initialization" << endl;
	cout << l1.getLocationId() << endl;
	cout << l1.getNameRoom() << endl;
	cout << l1.getNumberOfRows() << endl;
	cout << l1.getNoOfname() << endl;
	cout << l1.getNameZone() << endl;
	for (int i = 0; i < l1.getNumberOfRows(); i++) {
		cout << l1.getNumberOfSeatsPerRow()[i] << " " << endl;
	}
	cout << l1.getTotalLocations() << endl;

	cout << "------------------------------------------";
	cout << endl << endl;

	l1.setLocationId(123);
	l1.setNameRoom("Sala");
	l1.setNumberOfRows(5);
	l1.setNoOfname(3);
	int* seatsPerRow = new int[l1.getNumberOfRows()];
	l1.setNumberOfSeatsPerRow(seatsPerRow, l1.getNumberOfRows());

	cout << endl;
	cout << l1.getLocationId() << endl;
	cout << l1.getNameRoom() << endl;
	cout << l1.getNumberOfRows() << endl;
	cout << l1.getNoOfname() << endl;
	cout << l1.getNameZone() << endl;
	for (int i = 0; i < l1.getNumberOfRows(); i++) {
		cout <<"Row "<<i+1<<" "<< l1.getNumberOfSeatsPerRow()[i] << " ";
	}
	cout << endl;
	cout << l1.getTotalLocations() << endl;

	int rows[3] = { 10,15,20 };
	char zoneLetter[3] = { 'A','B','C' };

	cout << "-----------------------------" << endl;

	Location l2(1, 1000, 3, "Sala Palatului", 3, "VIP", rows);
	cout << "Location ID: " << l2.getLocationId() << endl;
	cout << "Location: " << l2.getNameRoom() << endl;
	cout << "Number of rows: " << l2.getNumberOfRows() << endl;
	cout << "Number of zones in total: " << l2.getNoOfname() << endl;
	for (int i = 0; i < l2.getNumberOfRows(); i++) {
		cout << "Number of seats per row: " << l2.getNumberOfSeatsPerRow()[i] << endl;
	}
	cout << "The number of total locations: " << l2.getTotalLocations() << endl;
	cout << endl;

	Location l3 = l2;

	cin >> l3;
	cout << l3;

}