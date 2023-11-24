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
	int category;
	int price;
	const int maxNumberOfTickets;
};
class Location {

	const int maxNumberOfSeats; //constant field
	int locationId;
	char* nameRoom; //dynamically allocated vector of characters
	int noOfname;
	string* nameZones;// "VIP", "Regular", "Premium"
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
		this->nameZones = NULL;
		this->numberOfSeatsPerRow = nullptr;
	}
	int getLocationId() {
		return this->locationId;
	}
	int getNumberOfRows() {
		return this->numberOfRows;
	}
	char* getname() {
		return this->nameRoom;
	}
	int getNoOfname() {
		return this->noOfname;
	}
	string* getNameZones() {
		return this->nameZones;
	}
	int* getNumberOfSeatsPerRow() {
		return this->numberOfSeatsPerRow;
	}
	int getTotalLocations() {
		return this->totalLocations;
	}


	Location(int locationId, int maxNumberOfSeats, int numberOfRows, const char* nameRoom, int noOfname, string* nameZones, int* numberOfSeatsPerRow) :maxNumberOfSeats(1000)
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
		strcpy(this->nameRoom, nameRoom);

		this->noOfname = noOfname;

		this->nameZones = new string[noOfname];
		for (int i = 0; i < noOfname; ++i)
		{
			this->nameZones[i] = nameZones[i];
		}

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

	e1.setNameEvent("Movie Night");
	e1.setDateOfEvent("17.09.2023");
	e1.setTimeOfEvent("20:00");

	cout << "Event name:  "<<e1.getNameEvent() << endl;
	cout << "Date of event: "<<e1.getDateOfEvent() << endl;
	cout << "Time of event: "<<e1.getTimeOfEvent() << endl;

	cout << "-------------------------------" << endl;

	Location l1;
	cout << "Initialization" << endl;
	cout << l1.getLocationId() << endl;
	cout << l1.getname() << endl;
	cout << l1.getNumberOfRows() << endl;
	cout << l1.getNoOfname() << endl;
	cout << l1.getNameZones() << endl;
	for (int i = 0; i < l1.getNumberOfRows(); i++) {
		cout << l1.getNumberOfSeatsPerRow()[i] << endl;
	}
	cout << l1.getTotalLocations() << endl;

	cout<<"------------------------------------------";
	cout << endl<<endl;
		
	int seats[3] = { 10,15,20 };
	char zoneLetter[3] = { 'A','B','C' };
	string zonesName[3] = { "VIP", "Regular", "Premium" };
	Location l2(1, 1000, 3, "Sala Palatului", 3, zonesName, seats);
	cout <<"Location ID: "<< l2.getLocationId() << endl;
	cout <<"Location: "<< l2.getname() << endl;
	cout <<"Number of rows: "<< l2.getNumberOfRows() << endl;
	cout <<"Number of zones in total: "<< l2.getNoOfname() << endl;
	for (int i = 0; i < l2.getNoOfname(); i++) {
		cout <<"Zone: "<< l2.getNameZones()[i] << endl;
	}
	for (int i = 0; i < l2.getNumberOfRows(); i++) {
		cout <<"Number of seats per row: "<< l2.getNumberOfSeatsPerRow()[i] << endl;
	}
	cout <<"The number of total locations: "<< l2.getTotalLocations() << endl;
	cout << endl;

}