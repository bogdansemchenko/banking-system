#pragma once

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& personName, int personAge);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getAge() const;

    virtual void displayInfo() const;
};
