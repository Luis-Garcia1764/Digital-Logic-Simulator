#include "Gate.hpp"
#include <iostream>

LogicGate::LogicGate(const std::string& name) {
    this->name = name;
}

std::string LogicGate::getName() const {
    return name;
}

void LogicGate::printTable() const {
    std::cout << name << " Truth Table\n";
    std::cout << "A B | Output\n";

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            std::cout << a << " "
                      << b << " | "
                      << evaluate(a, b)
                      << std::endl;
        }
    }
}

AndGate::AndGate(const std::string& name) : LogicGate(name) {
}

int AndGate::evaluate(int a, int b) const {
    return a && b;
}

NorGate::NorGate(const std::string& name) : LogicGate(name) {
}

int NorGate::evaluate(int a, int b) const {
    return !(a || b);
}

OrGate::OrGate(const std::string& name) : LogicGate(name) {
}

int OrGate::evaluate(int a, int b) const {
    return a || b;
}

NotGate::NotGate(const std::string& name):LogicGate(name) {
}

int NotGate::evaluate(int a, int b) const {
    return !a;
}

int NotGate::evaluateNot(int a) const {
    return !a;
}

void NotGate::printNotTable() const {
    std::cout << name << " Truth Table\n";
    std::cout << "A | Output\n";

    for (int a = 0; a <= 1; a++) {
        std::cout << a << " | " 
            << evaluateNot(a) 
            << std::endl;
    }
}

NandGate::NandGate(const std::string& name) : LogicGate(name) {}

int NandGate::evaluate(int a, int b) const {
    return !(a && b);
}

XorGate::XorGate(const std::string& name) : LogicGate(name) {}

int XorGate::evaluate(int a, int b) const {
    return a != b;
}

HalfAdder::HalfAdder(const std::string& name) {
    this->name = name;
}

int HalfAdder::getSum() const {
    return sum;
}

int HalfAdder::getCarry() const {
    return carry;
}

std::string HalfAdder::getName() const {
    return name;
}

void HalfAdder::evaluate(int a, int b) {
    XorGate xorGate("XOR");
    AndGate andGate("AND");

    sum = xorGate.evaluate(a, b);
    carry = andGate.evaluate(a, b);
}

FullAdder::FullAdder(const std::string& name) {
    this->name = name;
}

std::string FullAdder::getName() const {
    return name;
}

int FullAdder::getSum() const {
    return sum;
}

int FullAdder::getCarry() const {
    return carry;
}



void FullAdder::evaluate(int a, int b, int CarryIn) {
    int sum1 = 0;
    int carry1 = 0;

    HalfAdder halfAdder1("HALFADDER1");
    HalfAdder halfAdder2("HALFADDER2");

    OrGate orGate("OR");

    halfAdder1.evaluate(a, b);

    sum = halfAdder1.getSum();    
    carry = halfAdder1.getCarry();

    halfAdder2.evaluate(sum, CarryIn);

    sum1 = halfAdder2.getSum();
    carry1 = halfAdder2.getCarry();

    int finalCarry = orGate.evaluate(carry, carry1);

    
}

int FullAdder::getFinalSum() const {
    return finalSum;
}

int FullAdder::getFinalCarry() const {
    return finalCarry;
}