#include "Keeper.h"

Keeper::Keeper() {
	first = nullptr;
	last = nullptr;
	std::cout << "Конструктор объекта класса \"Keeper\" вызван" << std::endl;
	system("pause");
}
Keeper::~Keeper() {
	std::cout << "Деструктор объекта типа \"Keeper\" вызван" << std::endl;
	system("pause");
}
