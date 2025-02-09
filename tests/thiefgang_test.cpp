#include "gtest/gtest.h"
#include "../include/thiefgang.h"
#include "../include/bank.h"


class ThiefGangTest : public ::testing::Test {
protected:

    Bank bank{"National Bank", "John Smith", 2000, 1000000.0, 4.5, 2000000.0};
    ThiefGang gang{"The Robbers", 5, 7};

    ThiefGangTest() {
    }
};


TEST_F(ThiefGangTest, CreateThiefGangTest) {
    EXPECT_EQ(gang.getGangName(), "The Robbers");
    EXPECT_EQ(gang.getMembersCount(), 5);
    EXPECT_EQ(gang.getSkillRating(), 7);
}

TEST_F(ThiefGangTest, AddMemberTest) {
    gang.addMember();

    EXPECT_EQ(gang.getMembersCount(), 6);
}

TEST_F(ThiefGangTest, AddMemberMaxTest) {
    for (int i = 0; i < 5; ++i) {
        gang.addMember();
    }

    EXPECT_EQ(gang.getMembersCount(), 10);
    gang.addMember();
    EXPECT_EQ(gang.getMembersCount(), 10);
}

TEST_F(ThiefGangTest, IncreaseSkillRatingTest) {
    gang.increaseSkillRating();

    EXPECT_EQ(gang.getSkillRating(), 8);
}


TEST_F(ThiefGangTest, IncreaseSkillRatingMaxTest) {

    for (int i = 0; i < 3; ++i) {
        gang.increaseSkillRating();
    }

    EXPECT_EQ(gang.getSkillRating(), 10);

    gang.increaseSkillRating();
    EXPECT_EQ(gang.getSkillRating(), 10);
}


TEST_F(ThiefGangTest, DisplayGangInfoTest) {
    testing::internal::CaptureStdout();
    gang.displayGangInfo();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Gang Name: The Robbers"), std::string::npos);
    EXPECT_NE(output.find("Members Count: 5/10"), std::string::npos);
    EXPECT_NE(output.find("Skill Rating: 7/10"), std::string::npos);
}






