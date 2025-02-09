#pragma once

#include <string>
#include "bank.h"
#include <random>
class ThiefGang {
private:
    std::string gangName;
    int membersCount;
    int skillRating;


public:
    ThiefGang(const std::string& name, int membersCount, int skillRating);
    [[nodiscard]] std::string getGangName() const;
    [[nodiscard]] int getMembersCount() const;
    [[nodiscard]] int getSkillRating() const;

    void addMember();
    void increaseSkillRating();
    void displayGangInfo() const;
    bool attemptBankRobbery(Bank& bank);
};
