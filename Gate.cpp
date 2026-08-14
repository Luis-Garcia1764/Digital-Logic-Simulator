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