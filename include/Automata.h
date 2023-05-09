// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>

enum State {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
};

class Automata {
 public:
    Automata();
    void setState(State state);
    void setCash(int cash);
    int getCash();
    int insertCoin(int rub);
    int selectItem();
    int displayMenu();
    int verifyPayment();
    int prepareItem();
    State getState();
    int turnOn();
    int turnOff();

 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    State state;
    int initializeMenuWithPrices();
    int cancelTransaction();
    int finishTransaction();
};
#endif // INCLUDE_AUTOMATA_H_
