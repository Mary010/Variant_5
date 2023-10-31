#include "goodhero.h"
#include "villain.h"
#include "monster.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

void addHero(std::vector<Hero*>& heroes) {
    std::string name, weapon, skills;
    std::cout << "\nВведите имя героя: ";
    std::cin >> name;
    std::cout << "Введите тип оружия героя: ";
    std::cin >> weapon;
    std::cout << "Введите основные навыки героя (через пробел): ";
    std::cin.ignore();
    std::getline(std::cin, skills);

    GoodHero* newHero = new GoodHero(name, weapon, skills);
    heroes.push_back(newHero);

    std::cout << "\nГерой успешно добавлен!\n" << std::endl;
}

void addVillain(std::vector<Hero*>& villains) {
    std::string name, weapon, skills, evilDeed, hideout;
    std::cout << "\nВведите имя злодея: ";
    std::cin >> name;
    std::cout << "Введите тип оружия злодея: ";
    std::cin >> weapon;
    std::cout << "Введите основные навыки злодея (через пробел): ";
    std::cin.ignore();
    std::getline(std::cin, skills);
    std::cout << "Введите совершенное злодеяние: ";
    std::cin >> evilDeed;
    std::cout << "Введите место обитания злодея: ";
    std::cin >> hideout;

    Villain* newVillain = new Villain(name, weapon, skills, evilDeed, hideout);
    villains.push_back(newVillain);

    std::cout << "\nЗлодей успешно добавлен!\n" << std::endl;
}

void addMonster(std::vector<Hero*>& monsters) {
    std::string name, description;
    std::cout << "\nВведите наименование монстра: ";
    std::cin >> name;
    std::cout << "Введите описание внешнего вида монстра: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    Monster* newMonster = new Monster(name, description);
    monsters.push_back(newMonster);

    std::cout << "\nМонстр успешно добавлен!\n" << std::endl;
}

void deleteCharacter(std::vector<Hero*>& characters) {
    if (characters.empty()) {
        std::cout << "\nНет доступных персонажей для удаления." << std::endl;
        return;
    }

    std::cout << "\nВыберите номер персонажа для удаления:" << std::endl;
    for (size_t i = 0; i < characters.size(); ++i) {
        std::cout << i + 1 << ". ";
        characters[i]->displayInfo();
        std::cout << std::endl;
    }

    int choice;
    std::cin >> choice;

    if (choice >= 1 && choice <= characters.size()) {
        delete characters[choice - 1];
        characters.erase(characters.begin() + choice - 1);
        std::cout << "\nПерсонаж успешно удален!\n" << std::endl;
    }
    else {
        std::cout << "\nНеверный выбор.\n" << std::endl;
    }
}

void displayAllCharacters(const std::vector<Hero*>& characters) {
    if (characters.empty()) {
        std::cout << "\nНет доступных персонажей.\n" << std::endl;
        return;
    }

    for (const auto& character : characters) {
        character->displayInfo();
        std::cout << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);

    std::vector<Hero*> heroes;
    std::vector<Hero*> villains;
    std::vector<Hero*> monsters;

    while (true) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить героя" << std::endl;
        std::cout << "2. Добавить злодея" << std::endl;
        std::cout << "3. Добавить монстра" << std::endl;
        std::cout << "4. Удалить персонажа" << std::endl;
        std::cout << "5. Вывести информацию о всех персонажах" << std::endl;
        std::cout << "6. Сохранить данные в файл" << std::endl;
        std::cout << "7. Загрузить данные из файла" << std::endl;
        std::cout << "8. Выйти из программы" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            addHero(heroes);
            break;
        case 2:
            addVillain(villains);
            break;
        case 3:
            addMonster(monsters);
            break;
        case 4:
            std::cout << "Выберите тип персонажа для удаления:" << std::endl;
            std::cout << "1. Герой" << std::endl;
            std::cout << "2. Злодей" << std::endl;
            std::cout << "3. Монстр" << std::endl;

            int characterType;
            std::cin >> characterType;

            switch (characterType) {
            case 1:
                deleteCharacter(heroes);
                break;
            case 2:
                deleteCharacter(villains);
                break;
            case 3:
                deleteCharacter(monsters);
                break;
            default:
                std::cout << "\nНеверный выбор типа персонажа.\n" << std::endl;
            }
        case 5:
            displayAllCharacters(heroes);
            displayAllCharacters(villains);
            displayAllCharacters(monsters);
            break;
        case 6:
            saveToFile(heroes, "heroes.txt");
            saveToFile(villains, "villains.txt");
            saveToFile(monsters, "monsters.txt");
            break;
        case 7:
            loadFromFile(heroes, "heroes.txt");
            loadFromFile(villains, "villains.txt");
            loadFromFile(monsters, "monsters.txt");
            break;
        case 8:
            for (auto& character : heroes) {
                delete character;
            }
            for (auto& character : villains) {
                delete character;
            }
            for (auto& character : monsters) {
                delete character;
            }
            return 0;
        default:
            std::cout << "\nНеверный выбор. Попробуйте еще раз.\n" << std::endl;
        }
    }

    return 0;
}
