#include <iostream>
#include "Automata.h"

int main() {
	setlocale(LC_ALL, "Russian");
	Automata coffeeMachine;
	coffeeMachine.turnOn();
	coffeeMachine.displayMenu();
	coffeeMachine.insertCoin(30);
	coffeeMachine.selectItem();
	coffeeMachine.verifyPayment();
	coffeeMachine.prepareItem();
	coffeeMachine.turnOff();
	return 0;
}