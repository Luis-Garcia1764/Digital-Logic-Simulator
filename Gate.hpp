#ifndef GATE_HPP
#define GATE_HPP

#include <string>

class LogicGate {
protected:
    std::string name;

public:
    LogicGate(const std::string& name);

    std::string getName() const;

    virtual int evaluate(int a, int b) const = 0;

    void printTable() const;

    virtual ~LogicGate() {}
};

class AndGate : public LogicGate {
public:
    AndGate(const std::string& name);
    int evaluate(int a, int b) const override;
};

class NorGate : public LogicGate {
public:
    NorGate(const std::string& name);
    int evaluate(int a, int b) const override;
};

class OrGate : public LogicGate {
public:
    OrGate(const std::string& name);
    int evaluate(int a, int b) const override;
};

class NotGate : public LogicGate {
public:
    NotGate(const std::string& name);

    // You had chosen to give NOT its own function
    int evaluateNot(int a) const;
    int evaluate(int a, int b) const override;

    void printNotTable() const;
};

class NandGate : public LogicGate {
public:
    NandGate(const std::string& name);
    int evaluate(int a, int b) const override;
};

class XorGate : public LogicGate {
public:
    XorGate(const std::string& name);
    int evaluate(int a, int b) const override;
};

#endif