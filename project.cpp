#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Location {

	const int maxNumberOfSeats; //constant field
	int locationId;
	char* name; //dynamically allocated vector of characters
	int noOfname;
	string* nameZones;// "VIP", "Regular", "Premium"
	int numberOfRows;
	int* numberOfSeatsPerRow;//dynamically allocated numeric vector
	static int totalLocations; //static field


public:
	Location() :maxNumberOfSeats(0) {
		this->locationId = 0;
		this->numberOfRows = 0;
		this->name = new char[strlen("A") + 1];
		strcpy(this->name, "A");
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
		return this->name;
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
	Location(int locationId, int maxNumberOfSeats, int numberOfRows, const char* name, int noOfname, string* nameZones, int* numberOfSeatsPerRow) :maxNumberOfSeats(1000)
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
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

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
		if (this->name != nullptr) {
			delete[]this->name;
		}
		if (this->numberOfSeatsPerRow != nullptr) {
			delete[]this->numberOfSeatsPerRow;
		}
	}

};

int Location::totalLocations = 10;

int main()
{
	Location l1;
	cout << l1.getLocationId() << endl;
	cout << l1.getname() << endl;
	cout << l1.getNumberOfRows() << endl;
	cout << l1.getNoOfname() << endl;
	cout << l1.getNameZones() << endl;
	for (int i = 0; i < l1.getNumberOfRows(); i++) {
		cout << l1.getNumberOfSeatsPerRow()[i] << endl;
	}
	cout << l1.getTotalLocations() << endl;
	cout << endl;

	int seats[3] = { 10,15,20 };
	char zoneLetter[3] = { 'A','B','C' };
	string zonesName[3] = { "VIP", "Regular", "Premium" };
	Location l2(1, 1000, 3, "Sala Palatului", 3, zonesName, seats);
	cout << l2.getLocationId() << endl;
	cout << l2.getname() << endl;
	cout << l2.getNumberOfRows() << endl;
	cout << l2.getNoOfname() << endl;
	for (int i = 0; i < l2.getNoOfname(); i++) {
		cout << l2.getNameZones()[i] << endl;
	}
	for (int i = 0; i < l2.getNumberOfRows(); i++) {
		cout << l2.getNumberOfSeatsPerRow()[i] << endl;
	}
	cout << l2.getTotalLocations() << endl;
	cout << endl;

}