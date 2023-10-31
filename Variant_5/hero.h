#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>

class Hero {
public:
    Hero();
    Hero(const std::string& name, const std::string& weapon, const std::string& skills);
    Hero(const Hero& other);
    virtual ~Hero();

    std::string getName() const;
    std::string getWeapon() const;
    std::string getSkills() const;

    void setName(const std::string& name);
    void setWeapon(const std::string& weapon);
    void setSkills(const std::string& skills);

    virtual void displayInfo() const;

private:
    std::string name;
    std::string weapon;
    std::string skills;
};

#endif