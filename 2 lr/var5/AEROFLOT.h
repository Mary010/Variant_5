#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

class AEROFLOT {
private:
	std::string destination;
	int flight_number;
	std::string aircraft_type;
public:
	AEROFLOT(std::string dest, int num, std::string type);
	AEROFLOT();

	~AEROFLOT();

	friend std::ostream& operator << (std::ostream& os, const AEROFLOT& aeroflot);

	friend std::istream& operator >> (std::istream& in, AEROFLOT& aeroflot);

	friend bool operator<(const AEROFLOT& a, const AEROFLOT& b);
	friend bool operator>(const AEROFLOT& a, const AEROFLOT& b);

	void push(std::string dest, int num, std::string type);
	
	std::string getDestination();
	int getFlightNumber();
	std::string getAircraftType();

	void load_in_file(std::ofstream& file) ;

	void load_from_file(std::ifstream& file);
};

