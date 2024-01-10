#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class ManageServices {
public:
	virtual string showClassType() = 0;

	virtual int noOfPersonsForSecurity() {
		return 0;
	}

	virtual string eventType() = 0;

	virtual bool needsMedicalCrew() {
		return false;
	}


};

class Event : public ManageServices {
protected:
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

	bool operator==(const Event& ev) {
		return (nameEvent == ev.nameEvent) && (dateOfEvent == ev.dateOfEvent) && (timeOfEvent == ev.timeOfEvent);
	}

	bool operator!=(const Event& ev) {
		return !(*this == ev);
	}

	string showClassType() {
		return "Normal Event!";
	}

	int noOfPersonsForSecurity() {
		return 50;
	}

	string eventType() {
		return "N/A";
	}

	bool needsMedicalCrew() {
		return false;
	}
};

class Match : public Event {
private:
	bool hasFoodStands;
	bool isEuropeanCupMatch;

public:
	Match() : Event() {
		this->hasFoodStands = false;
		this->isEuropeanCupMatch = false;
	}

	Match(string nameEvent, string dateOfEvent, string timeOfEvent, bool hasFoodStands, bool isEuropeanCupMatch) : Event(nameEvent, dateOfEvent, timeOfEvent) {
		this->hasFoodStands = hasFoodStands;
		this->isEuropeanCupMatch = isEuropeanCupMatch;
	}

	Match(const Match& m) : Event(m) {
		this->hasFoodStands = m.hasFoodStands;
		this->isEuropeanCupMatch = m.isEuropeanCupMatch;
	}
	~Match() {
	}

	bool getHasFoodStands() {
		return hasFoodStands;
	}

	void setHasFoodStands(bool hasFoodStands) {
		this->hasFoodStands = hasFoodStands;
	}

	bool getIsEuropeanCupMatch() {
		return isEuropeanCupMatch;
	}

	void setIsEuropeanCupMatch(bool isEuropeanCupMatch) {
		this->isEuropeanCupMatch = isEuropeanCupMatch;
	}

	Match& operator=(const Match& m) {
		if (this != &m) {
			Event::operator=(m);
			hasFoodStands = m.hasFoodStands;
			isEuropeanCupMatch = m.isEuropeanCupMatch;
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Match& m) {
		in >> (Event&)m;
		cout << "Has Food Stands (1 for true, 0 for false): ";
		in >> m.hasFoodStands;
		cout << "Is European Cup Match (1 for true, 0 for false): ";
		in >> m.isEuropeanCupMatch;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Match& m) {
		out << (Event&)m;
		out << "Has Food Stands: " << (m.hasFoodStands ? "true" : "false") << endl;
		out << "Is European Cup Match: " << (m.isEuropeanCupMatch ? "true" : "false") << endl;
		return out;
	}

	string showClassType() {
		return "Match Event!";
	}

	int noOfPersonsForSecurity() {
		return 500;
	}

	string eventType() {
		return "Football";
	}

	bool needsMedicalCrew() {
		return true;
	}
};

class EventManager {
private:
	vector<Event> events;

public:
	EventManager() {

	}

	EventManager(int noEvents, Event* events) {
		for (int i = 0; i < noEvents; i++) {
			this->events.push_back(events[i]);
		}
	}

	~EventManager() {

	}

	void addEvent(Event eventAdd) {
		events.push_back(eventAdd);
	}

	void removeEvent(Event eventRmv) {
		for (int i = 0; i < events.size(); ++i) {
			if (events[i] == eventRmv) {
				events.erase(events.begin() + i);
			}
		}
	}

	vector<string> getAllEventNames() {
		vector<string> eventNames;
		for (size_t i = 0; i < events.size(); ++i) {
			eventNames.push_back(events[i].getNameEvent());
		}
		return eventNames;
	}

	void displayAllEvents() {
		for (int i = 0; i < events.size(); ++i) {
			cout << events[i] << endl;
		}
	}

	friend ostream& operator<<(ostream& out, EventManager em) {
		out << "Event Manager Contains:" << endl;
		for (int i = 0; i < em.events.size(); ++i) {
			out << em.events[i] << endl;
		}
		return out;
	}
};

class Tickets : public ManageServices {
protected:
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
	void setPricesPerCategory(int category, int* pricesPerCategory) {
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

	Tickets(int category, int price, int* pricesPerCategory) : ticketId(0) {

		this->category = category;
		this->price = price;
		this->pricesPerCategory = new int[category];
		for (int i = 0; i < this->category; i++)
		{
			this->pricesPerCategory[i] = pricesPerCategory[i];
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
		cout << "Prices per catergory: ";
		delete[]c.pricesPerCategory;
		c.pricesPerCategory = new int[c.category];
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

	Tickets operator+(const Tickets& t) {
		Tickets result(*this);
		result.price += t.price;
		return result;
	}

	Tickets operator-(const Tickets& t) {
		Tickets result(*this);
		result.price -= t.price;
		return result;
	}


	string showClassType() {
		return "Regular Ticket!";
	}

	string eventType() {
		return "Unknown";
	}
};

class Location {

	const int maxNumberOfSeats; 
	int locationId;
	char* nameRoom; 
	int noOfname;
	const char* nameZones[3] = { "VIP", "Regular", "Premium" };
	char* nameZone;
	int numberOfRows;
	int* numberOfSeatsPerRow;
	static int totalLocations; 

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
		delete[] this->numberOfSeatsPerRow;
		this->numberOfSeatsPerRow = nullptr;
		this->numberOfSeatsPerRow = new int[numberOfRows];
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
		in>>buffer; 
		c.setNameRoom(buffer);
		if (c.nameZone != nullptr) {
			delete[] c.nameZone;
		}
		char buffer1[200];
		cout << "Name Zone: "<<endl;
		in>>buffer1; 
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

	bool operator>(const Location& l) {
		return numberOfRows > l.numberOfRows;
	}

	bool operator<(const Location& l) {
		return !(*this > l);
	}

};



int Location::totalLocations = 10;

class ReducedTickets : public Tickets {
private:
	double discountPercentage;
	bool hasDiscount;

public:
	ReducedTickets() :Tickets() {
		this->discountPercentage = 0;
		this->hasDiscount = 0;
	}

	ReducedTickets(int category, int price, int* pricesPerCategory, double discountPercentage, bool hasDiscount) : Tickets (category, price, pricesPerCategory) {
		this->discountPercentage = discountPercentage;
		this->hasDiscount = hasDiscount;
	}

	ReducedTickets(const ReducedTickets& rt) : Tickets(rt) {
		this->discountPercentage = rt.discountPercentage;
		this->hasDiscount = rt.hasDiscount;
	}

	~ReducedTickets() {}

	double getDiscountPercentage() {
		return discountPercentage;
	}

	void setDiscountPercentage(double discountPercentage) {
		this->discountPercentage = discountPercentage;
	}

	bool getHasDiscount() const {
		return hasDiscount;
	}

	void setHasDiscount(bool hasDiscount) {
		this->hasDiscount = hasDiscount;
	}

	ReducedTickets& operator=(const ReducedTickets& rt) {
		if (this != &rt) {
			Tickets::operator=(rt);
			discountPercentage = rt.discountPercentage;
			hasDiscount = rt.hasDiscount;
		}
		return *this;
	}

	friend istream& operator>>(istream& in, ReducedTickets& rt) {
		in >> (Tickets&)rt;
		cout << "Discount Percentage: ";
		in >> rt.discountPercentage;
		cout << "Has Discount (1 for true, 0 for false): ";
		in >> rt.hasDiscount;
		return in;
	}


	friend ostream& operator<<(ostream& out, const ReducedTickets& rt) {
		out << (Tickets&)rt;
		out << "Discount Percentage: " << rt.discountPercentage << endl;
		out << "Has Discount: " << (rt.hasDiscount ? "true" : "false") << endl;
		return out;
	}


	string showClassType() {
		return "Reduced Ticket!";
	}

	string eventType() {
		return "Unknown, but the ticket is discounted!";
	}
};

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

	Tickets t2(1, 100, pricesCategories);

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

	int seatsPerRow[3] = { 100,200,100 };
	l1.setNumberOfSeatsPerRow(seatsPerRow, 3);

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

	cout << endl << endl;
	if (e1 == e2) {
		cout << "Events are the same." << endl;
	}
	else {
		cout << "Events are different." << endl;
	}


	cout << endl << endl;

	Tickets t3 = t1 + t2;
	cout << "Total price after addition: " << t3.getPrice() << endl;

	Tickets t4 = t3 - t1;
	cout << "Total price after subtraction: " << t4.getPrice() << endl;


	cout << endl << endl;

	if (l1 > l2) {
		cout << "L1 has more rows than L2." << endl;
	}
	else {
		cout << "L1 does not have more rows than L2." << endl;
	}

	cout << endl << endl;

	ReducedTickets rt1;
	cout << rt1 << endl;

	ReducedTickets rt2(2, 50, new int[2] {30, 25}, 10.0, true);
	cout << rt2 << endl;

	ReducedTickets rt3 = rt1;
	cout << rt3 << endl;


	rt3 = rt2;
	cout << rt3 << endl;


	cout << endl << endl;

	Match match1;
	cout << match1 << endl;

	Match match2("Romania vs England", "15/01/2024", "18:00", true, true);
	cout << match2 << endl;

	Match match3 = match1;

	cout << match3 << endl;

	match3 = match2;
	cout << match3 << endl;


	cout << endl << endl << endl;
	ManageServices* vMs[4];
	vMs[0] = &e1;
	vMs[1] = &match1;
	vMs[2] = &t2;
	vMs[3] = &rt3;

	for (int i = 0; i < 4; i++) {
		cout << vMs[i]->eventType() << endl;
		cout << vMs[i]->showClassType() << endl;
		cout << vMs[i]->noOfPersonsForSecurity() << endl;
		cout << vMs[i]->needsMedicalCrew() << endl;
		cout << "======================================" << endl;
	}

	cout << endl << endl << endl << endl;

	EventManager evM;
	cout << evM << endl;
	evM.addEvent(e1);
	evM.addEvent(match1);
	evM.addEvent(match2);
	evM.addEvent(e2);

	cout << evM << endl;

	evM.removeEvent(e1);
	evM.removeEvent(match1);
	cout << "--------------------------------------------" << endl;
	cout << evM << endl;

	cout << "==================================================" << endl << endl;

	string input;

	bool inMenu = false;

	while (true) {
		if (!inMenu) {
			cout << "Enter 'menu' to access the menu: ";
			cin >> input;

			if (input != "menu") {
				cout << "Invalid input. Try again." << endl;
				continue;
			}
			else {
				inMenu = true;
				system("cls");
				system("Color 3f");
			}
		}
		cout << endl << endl << endl << endl;
		cout << "MENU" << endl;
		cout << "1. Create an Event" << endl;
		cout << "2. Create a Location" << endl;
		cout << "3. Display Event" << endl;
		cout << "4. Display Location" << endl;
		cout << "5. Exit" << endl;
		cout << endl << endl << endl << endl;

		int choice;
		cout << "Select an option: ";
		cin >> choice;

		if (choice == 1) {
			cout << "You selected Create an Event." << endl;
			cin >> e1;

		}
		else if (choice == 2) {
			cout << "You selected Create a Location." << endl;
			cin >> l1;
		}
		else if (choice == 3) {
			cout << "You selected Display Event." << endl;
			cout << e1 << endl;
		}
		else if (choice == 4) {
			cout << "You selected Display Location." << endl;
			cout << l1 << endl;
		}
		else if (choice == 5) {
			cout << "Exiting the menu." << endl;
			system("Color F1");
			return 0;
		}
		else {
			cout << "Invalid choice. Try again." << endl;
		}

		cout << "Do you want to perform another action? (yes/no): ";
		cin >> input;

		if (input != "yes") {
			cout << "Exiting the menu." << endl;
			break;
		}
	}

	return 0;

}