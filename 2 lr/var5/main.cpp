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
        std::cout << "1. ������� 1" << std::endl;
        std::cout << "2. ������� 2" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << "��� �����: ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
         
        default: {
            std::cout << "�������� ����� �� ������, ����������" << std::endl;
            system("pause");
            break;
        }
              
        }

    }   
}