#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Location {
	const int maxNumberOfSeats; //constant field
	int numberOfRows;
	char* name; //dynamically allocated vector of characters
	int noOfname;
	string* nameZones;// "VIP", "Regular", "Premium"
	int* numberOfSeatsPerRow;//dynamically allocated numeric vector
	static int totalLocations; //static field


public:
	Location() :maxNumberOfSeats(0) {
		this->numberOfRows = 0;
		this->name = new char[strlen("A") + 1];
		strcpy(this->name, "A");
		this->numberOfSeatsPerRow = nullptr;
	}

	int getNumberOfRows() {
		return this->numberOfRows ;
	}
	char* getname() {
		return this->name;
	}
	int* getNumberOfSeatsPerRow() {
		return this->numberOfSeatsPerRow;
	}

	Location(int numberOfRows, const char* name, int* numberOfSeatsPerRow) :maxNumberOfSeats(100)
	{
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
		if (numberOfSeatsPerRow !=nullptr && numberOfRows != 0)
		{
			this->numberOfSeatsPerRow = new int[this->numberOfRows];
			for (int i = 0;i < this->numberOfRows;i++)
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
	cout << l1.getname() << endl;
	cout << l1.getNumberOfRows()<<endl;
	for (int i = 0;i < l1.getNumberOfRows();i++) {
		cout << l1.getNumberOfSeatsPerRow()[i] << endl;
	}

	cout << endl;

	int seats[3] = { 10,15,20 };
	Location l2(3, "Sala Polivalenta", seats);
	cout << l2.getname() << endl;
	cout << l2.getNumberOfRows() << endl;
	for (int i = 0;i < l2.getNumberOfRows();i++) {
		cout << l2.getNumberOfSeatsPerRow()[i] << endl;
	}
}