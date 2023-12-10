#include <iostream>
#include <windows.h>
#include "Keeper.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    while (true) {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Задание 1" << std::endl;
        std::cout << "2. Задание 2" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
         
        default: {
            std::cout << "Выберите цифру из списка, пожалуйста" << std::endl;
            system("pause");
            break;
        }
              
        }

    }   
}