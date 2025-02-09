#include "../include/person.h"
#include <iostream>

Person::Person(const std::string& personName, int personAge)
    : name(personName), age(personAge) {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::displayInfo() const {
    std::cout << "Name: " << name << "\nAge: " << age << "\n";
}
