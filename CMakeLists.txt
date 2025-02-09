cmake_minimum_required(VERSION 3.29)
project(bank)

set(CMAKE_CXX_STANDARD 20)

add_executable(bank main.cpp
        include/card.h
        src/card.cpp
        "include/account .h"
        src/account.cpp
        include/person.h
        src/person.cpp
        include/client.h
        src/client.cpp
        include/currencyExchange.h
        src/currencyExchange.cpp
        include/atm.h
        src/atm.cpp
        include/transaction.h
        src/trahsaction.cpp
        include/credit.h
        src/credit.cpp
        include/employee.h
        src/employee.cpp
        include/bank.h
        src/bank.cpp
        include/database.h
        src/database.cpp
        include/thiefgang.h
        src/thiefgang.cpp
)


option(BUILD_TESTS "Build tests" ON)


if(BUILD_TESTS)

    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})


    add_executable(bank_tests
            include/card.h
            src/card.cpp
            "include/account .h"
            src/account.cpp
            include/person.h
            src/person.cpp
            include/client.h
            src/client.cpp
            include/currencyExchange.h
            src/currencyExchange.cpp
            include/atm.h
            src/atm.cpp
            include/transaction.h
            src/trahsaction.cpp
            include/credit.h
            src/credit.cpp
            include/employee.h
            src/employee.cpp
            include/bank.h
            src/bank.cpp
            include/database.h
            src/database.cpp
            include/thiefgang.h
            src/thiefgang.cpp

            tests/card_test.cpp
            tests/account_test.cpp
            tests/atm_test.cpp
            tests/bank_test.cpp
            tests/client_test.cpp
            tests/credit_test.cpp
            tests/test_currencyExchange.cpp
            tests/database_test.cpp
            tests/employee_test.cpp
            tests/thiefgang_test.cpp
            tests/transaction_test.cpp


    )


    target_link_libraries(bank_tests GTest::GTest GTest::Main)


    enable_testing()
    add_test(NAME bank_tests COMMAND bank_tests)

endif()