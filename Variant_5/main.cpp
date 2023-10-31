#include "goodhero.h"
#include "villain.h"
#include "monster.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

void addHero(std::vector<Hero*>& heroes) {
    std::string name, weapon, skills;
    std::cout << "\n������� ��� �����: ";
    std::cin >> name;
    std::cout << "������� ��� ������ �����: ";
    std::cin >> weapon;
    std::cout << "������� �������� ������ ����� (����� ������): ";
    std::cin.ignore();
    std::getline(std::cin, skills);

    GoodHero* newHero = new GoodHero(name, weapon, skills);
    heroes.push_back(newHero);

    std::cout << "\n����� ������� ��������!\n" << std::endl;
}

void addVillain(std::vector<Hero*>& villains) {
    std::string name, weapon, skills, evilDeed, hideout;
    std::cout << "\n������� ��� ������: ";
    std::cin >> name;
    std::cout << "������� ��� ������ ������: ";
    std::cin >> weapon;
    std::cout << "������� �������� ������ ������ (����� ������): ";
    std::cin.ignore();
    std::getline(std::cin, skills);
    std::cout << "������� ����������� ���������: ";
    std::cin >> evilDeed;
    std::cout << "������� ����� �������� ������: ";
    std::cin >> hideout;

    Villain* newVillain = new Villain(name, weapon, skills, evilDeed, hideout);
    villains.push_back(newVillain);

    std::cout << "\n������ ������� ��������!\n" << std::endl;
}

void addMonster(std::vector<Hero*>& monsters) {
    std::string name, description;
    std::cout << "\n������� ������������ �������: ";
    std::cin >> name;
    std::cout << "������� �������� �������� ���� �������: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    Monster* newMonster = new Monster(name, description);
    monsters.push_back(newMonster);

    std::cout << "\n������ ������� ��������!\n" << std::endl;
}

void deleteCharacter(std::vector<Hero*>& characters) {
    if (characters.empty()) {
        std::cout << "\n��� ��������� ���������� ��� ��������." << std::endl;
        return;
    }

    std::cout << "\n�������� ����� ��������� ��� ��������:" << std::endl;
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
        std::cout << "\n�������� ������� ������!\n" << std::endl;
    }
    else {
        std::cout << "\n�������� �����.\n" << std::endl;
    }
}

void displayAllCharacters(const std::vector<Hero*>& characters) {
    if (characters.empty()) {
        std::cout << "\n��� ��������� ����������.\n" << std::endl;
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
        std::cout << "�������� ��������:" << std::endl;
        std::cout << "1. �������� �����" << std::endl;
        std::cout << "2. �������� ������" << std::endl;
        std::cout << "3. �������� �������" << std::endl;
        std::cout << "4. ������� ���������" << std::endl;
        std::cout << "5. ������� ���������� � ���� ����������" << std::endl;
        std::cout << "6. ��������� ������ � ����" << std::endl;
        std::cout << "7. ��������� ������ �� �����" << std::endl;
        std::cout << "8. ����� �� ���������" << std::endl;

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
            std::cout << "�������� ��� ��������� ��� ��������:" << std::endl;
            std::cout << "1. �����" << std::endl;
            std::cout << "2. ������" << std::endl;
            std::cout << "3. ������" << std::endl;

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
                std::cout << "\n�������� ����� ���� ���������.\n" << std::endl;
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
            std::cout << "\n�������� �����. ���������� ��� ���.\n" << std::endl;
        }
    }

    return 0;
}
