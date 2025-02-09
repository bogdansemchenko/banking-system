#include "../include/thiefgang.h"
#include <iostream>


ThiefGang::ThiefGang(const std::string& name, int membersCount, int skillRating)
    : gangName(name), membersCount(membersCount), skillRating(skillRating) {
    if (membersCount < 1) {
        membersCount = 1;
    } else if (membersCount > 10) {
        membersCount = 10;
    }
    if (skillRating < 1) {
        skillRating = 1;
    } else if (skillRating > 10) {
        skillRating = 10;
    }
}
std::string ThiefGang::getGangName() const {
    return gangName;
}

int ThiefGang::getMembersCount() const {
    return membersCount;
}

int ThiefGang::getSkillRating() const {
    return skillRating;
}

void ThiefGang::addMember() {
    if (membersCount < 10) {
        membersCount++;
        std::cout << "New member added to the gang. Total members: " << membersCount << "\n";
    } else {
        std::cout << "Cannot add more members. The gang is at full capacity.\n";
    }
}

void ThiefGang::increaseSkillRating() {
    if (skillRating < 10) {
        skillRating++;
        std::cout << "Skill rating increased to: " << skillRating << "\n";
    } else {
        std::cout << "Skill rating is already at the maximum.\n";
    }
}


void ThiefGang::displayGangInfo() const {
    std::cout << "Gang Name: " << gangName << "\n";
    std::cout << "Members Count: " << membersCount << "/10\n";
    std::cout << "Skill Rating: " << skillRating << "/10\n";
}

bool ThiefGang::attemptBankRobbery(Bank& bank) {
    double robberyChance = (membersCount * skillRating) / static_cast<double>(bank.getSafetyCoefficient() + 1);
    robberyChance = std::min(std::max(robberyChance, 1.0), 10.0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 12);
    int randomNumber = dis(gen);

    std::cout << "Robbery chance: " << robberyChance << "/12\n";
    std::cout << "Random number: " << randomNumber << "\n";

    if (randomNumber <= robberyChance) {
        std::cout << "The robbery was successful!" << std::endl;


        bank.setBankBudget(0);

        return true;
    } else {
        std::cout << "The robbery failed." << std::endl;
        delete this;
        return false;
    }
}

