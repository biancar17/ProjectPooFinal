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
};

class Tickets {
	int ticketId;
	const char* category[3] = { "VIP","REGULAR","PREMIUM" };
	int price;
	const int maxNumberOfTickets;

public:
	Tickets():maxNumberOfTickets(100) {
		this->ticketId = 0;
		this->price = 0;
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
	void setTicketId(int ticketId) {
		this->ticketId = ticketId;
	}
	void setPrice(int price) {
		this->price = price;
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
		return this->numberOfRows;
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
	void setNameRoom(char* nameRoom) {
		this->nameRoom = nameRoom;
	}
	void setNoOfname(int noOfname) {
		this->noOfname = noOfname;
	}
	void setNumberOfSeatsPerRow(int* numberOfSeatsPerRow) {
		this->numberOfSeatsPerRow = new int[1];
		this->numberOfSeatsPerRow = numberOfSeatsPerRow;
	}

	Location(int locationId, int maxNumberOfSeats, int numberOfRows,const char* nameRoom, int noOfname,const char* nameZone, int* numberOfSeatsPerRow) :maxNumberOfSeats(1000)
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
			delete[]this->nameRoom;
		}
		if (this->numberOfSeatsPerRow != nullptr) {
			delete[]this->numberOfSeatsPerRow;
		}
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

	cout << "-------------------------------" << endl;

	e1.setNameEvent("Movie Night");
	e1.setDateOfEvent("17.09.2023");
	e1.setTimeOfEvent("20:00");

	cout << "Event name:  "<<e1.getNameEvent() << endl;
	cout << "Date of event: "<<e1.getDateOfEvent() << endl;
	cout << "Time of event: "<<e1.getTimeOfEvent() << endl;

	cout << "-------------------------------" << endl;

	Tickets t1;
	cout << "Initialization" << endl;
	cout << t1.getMaxNumberOfTickets() << endl;
	cout << t1.getTicketId() << endl;
	cout << t1.getPrice() << endl;

	t1.setTicketId(98);
	t1.setPrice(50);

	cout <<"Max number of tickets: "<< t1.getMaxNumberOfTickets() << endl;
	cout <<"Ticket ID: "<< t1.getTicketId() << endl;
	cout <<"Price of the ticket: "<< t1.getPrice() << endl;
	
	cout << "---------------------------------" << endl;

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

	cout<<"------------------------------------------";
	cout << endl;

	l1.setLocationId(123);
	l1.setNameRoom((char*)"Sala");
	l1.setNumberOfRows(15);
	l1.setNoOfname(3);
	l1.setNumberOfSeatsPerRow((int*)5);

	cout << l1.getLocationId() << endl;
	cout << l1.getNameRoom() << endl;
	cout << l1.getNumberOfRows() << endl;
	cout << l1.getNoOfname() << endl;
	cout << l1.getNameZone() << endl;
	for (int i = 0; i < l1.getNumberOfRows(); i++) {
		cout << l1.getNumberOfSeatsPerRow()[i] << " " << endl;
	}
	cout << l1.getTotalLocations() << endl;

	int rows[3] = { 10,15,20 };
	char zoneLetter[3] = { 'A','B','C' };
	Location l2(1, 1000, 3, "Sala Palatului", 3, "VIP", rows);
	cout <<"Location ID: "<< l2.getLocationId() << endl;
	cout <<"Location: "<< l2.getNameRoom() << endl;
	cout <<"Number of rows: "<< l2.getNumberOfRows() << endl;
	cout <<"Number of zones in total: "<< l2.getNoOfname() << endl;
	for (int i = 0; i < l2.getNumberOfRows(); i++) {
		cout <<"Number of seats per row: "<< l2.getNumberOfSeatsPerRow()[i] << endl;
	}
	cout <<"The number of total locations: "<< l2.getTotalLocations() << endl;
	cout << endl;

}