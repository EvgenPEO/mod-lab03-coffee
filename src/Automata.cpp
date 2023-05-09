#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    setState(OFF);
    initializeMenuWithPrices();
}

void Automata::setState(State state) {
    this->state = state;
}

void Automata::setCash(int cash) {
    this->cash = cash;
}

int Automata::getCash() {
    return cash;
}

int Automata::turnOn() {
    std::cout << "Automata turned on" << std::endl;
    setState(WAIT);
    return 0;
}

int Automata::turnOff() {
    std::cout << "Automata turned off" << std::endl;
    setState(OFF);
    return 0;
}

int Automata::initializeMenuWithPrices() {
    std::string names[] = { "Cappucino", "Americano", "Fredo" };
    int priceList[] = { 50, 20, 10 };
    menu.insert(menu.begin(), names, names + 3);
    prices.insert(prices.begin(), priceList, priceList + 3);
    return 0;
}

int Automata::insertCoin(int rub) {
    if (state == WAIT || state == ACCEPT) {
        setCash(rub);
        setState(ACCEPT);
        return rub;
    }
    else {
        std::cout << "error " << std::endl;
        return 0;
    }
}

int Automata::displayMenu() {
    for (int i = 0; i < menu.size(); i++) {
        std::cout << menu[i] << ' ' << prices[i] << std::endl;
    }
    return 0;
}

State Automata::getState() {
    std::cout << state << std::endl;
    return state;
}

int Automata::selectItem() {
    if (state == ACCEPT) {
        std::cout << "Selected item: " << menu[1] << std::endl;
        setState(CHECK);
        return 1;
    }
    else {
        return 0;
    }
}

int Automata::verifyPayment() {
    if (state == CHECK) {
        if (cash >= prices[1]) {
            cash = cash - prices[1];
        }
        else {
            std::cout << "error " << std::endl;
        }
        return 0;
    }
    return 0;
}

int Automata::cancelTransaction() {
    setState(WAIT);
    return 0;
}

int Automata::prepareItem() {
    if (state == CHECK) {
        std::cout << "Preparing item" << std::endl;
        setState(COOK);
        if (cash > 0) {
            std::cout << "Take your change : " << cash << std::endl;
        }
        else {
            std::cout << "error " << std::endl;
        }
        finishTransaction();
    }
    return 0;
}

int Automata::finishTransaction() {
    setState(WAIT);
    return 0;
}
