#include "AEROFLOT.h"

AEROFLOT::AEROFLOT(std::string dest, int num, std::string type)
	: destination(dest), flight_number(num), aircraft_type(type) {}

AEROFLOT::AEROFLOT() {
    destination = "";
    flight_number = 0;
    aircraft_type = "";
    std::cout << "Конструктор объекта класса \"AEROFLOT\" вызван" << std::endl;
    system("pause");
}

AEROFLOT::~AEROFLOT() {
    std::cout << "Деструктор объекта типа \"AEROFLOT\" вызван" << std::endl;
    system("pause");
}

std::ostream& operator << ( std::ostream& os, const AEROFLOT& aeroflot) {
    os << "Полёт №" << aeroflot.flight_number << " на " << aeroflot.aircraft_type
        << " в " << aeroflot.destination << std::endl << std::endl;
    return os;
}

std::istream& operator>> (std::istream& in, AEROFLOT& aeroflot) {
        std::string dest;
        int num;
        std::string type;
        std::cout << "Введите пункт назначения: ";
        in >> dest;
        std::cout << "Введите номер рейса: ";
        in >> num;
        std::cout << "Введите тип самолёта: ";
        in >> type;

        aeroflot.push(dest, num, type);
       
        return in;
}

bool operator<(const AEROFLOT& a, const AEROFLOT& b) {
    return a.flight_number < b.flight_number;
}

bool operator>(const AEROFLOT& a, const AEROFLOT& b) {
    return a.flight_number > b.flight_number;
}


void AEROFLOT::push(std::string dest, int num, std::string type) {
    destination = dest;
    flight_number = num;
    aircraft_type = type;
}

std::string AEROFLOT::getDestination() { return destination; }
int AEROFLOT::getFlightNumber() { return flight_number; }
std::string AEROFLOT::getAircraftType() { return aircraft_type; }

void AEROFLOT::load_in_file(std::ofstream& file) {
    file << "Пункт назначения: " << std::endl << destination << std::endl << std::endl
        << "Номер рейса: " << std::endl << flight_number << std::endl << std::endl
        << "Тип самолёта: " << std::endl << aircraft_type << std::endl
        << "________________________________________________" << std::endl;
}

void AEROFLOT::load_from_file(std::ifstream& file) {
    std::string line = "";
    getline(file, line);
    destination = line;
    getline(file, line);
    getline(file, line);
    getline(file, line);
    flight_number = { std::stoi(line) };
    getline(file, line);
    getline(file, line);
    getline(file, line);
    aircraft_type = line;
    getline(file, line);
}

