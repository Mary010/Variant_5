#include <iostream>
#include <windows.h>
#include "Keeper.h"

void task_2(std::string filename) {
    std::string vowels = "aouieyAOUIEY";
    std::ifstream file(filename);
    if (!file.is_open())
        return;
    
    int i = 0;
    std::string buff;

    while (!file.eof()) {
        file >> buff;
        if (vowels.find(buff[0]) != std::string::npos) {
            std::cout << buff << "\t" << "\t";
            i++;
        }
        if (i == 4) {
            i = 0;
            std::cout << std::endl;
        }
    }
    
}


int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
A:
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
        case 1: {
            AEROFLOT buffer;
            Keeper keeper;
            std::string filename = "";
            while (true) {
                system("cls");
                std::cout << "Menu task 1: " << std::endl;
                std::cout << "1. Добавить объект " << std::endl;
                std::cout << "2. Загрузить данные из файла " << std::endl;
                std::cout << "3. Загрузить данные в файл" << std::endl;
                std::cout << "4. Отобразить все данные" << std::endl;
                std::cout << "5. Поиск" << std::endl;
                std::cout << "0. Назад" << std::endl;
                std::cout << "Ваш выбор: ";
                std::cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    std::cin >> buffer;
                    keeper.Push(buffer);
                    break;

                case 2:
                    std::cout << "Введите имя файла, откуда будут загружены данные: ";
                    std::cin >> filename;
                    keeper = keeper.LoadFromFile(filename);
                    break;

                case 3:
                    std::cout << "Введите имя файла, куда будут выгружены данные: ";
                    std::cin >> filename;
                    keeper.LoadInFile(filename);
                    break;
                    break;

                case 4:
                    keeper.DisplayAll();
                    system("pause");
                    break;

                case 5:
                    keeper.Search();
                    system("pause");
                    break;

                case 0:
                    goto A;

                default:
                    std::cout << "Выберите цифру из списка, пожалуйста" << std::endl;
                    system("pause");

                    break;
                }
            }
        }
        case 2: {
            std::string filename = "";
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            task_2(filename);
            system("pause");
            break;
        }

        case 0: {
            return 0;
        }

        default: {
            std::cout << "Выберите цифру из списка, пожалуйста" << std::endl;
            system("pause");
            break;
        }

        }

    }
}