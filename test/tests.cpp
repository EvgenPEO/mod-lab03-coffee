// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata coffeeMachine;
    coffeeMachine.turnOn();
    coffeeMachine.insertCoin(50);
    State currentState = coffeeMachine.getState();
    EXPECT_EQ(ACCEPT, currentState);
}

TEST(task2, test2) {
    Automata coffeeMachine;
    coffeeMachine.turnOn();
    coffeeMachine.insertCoin(50);
    int currentCash = coffeeMachine.getCash();
    EXPECT_EQ(50, currentCash);
}

TEST(task3, test3) {
    Automata coffeeMachine;
    coffeeMachine.turnOn();
    coffeeMachine.insertCoin(50);
    coffeeMachine.selectItem();
    coffeeMachine.verifyPayment();
    int currentCash = coffeeMachine.getCash();
    EXPECT_EQ(30, currentCash);
}
