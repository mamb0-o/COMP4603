//
//  Operand.cpp
//  Assignment9P2
//
//  Created by GUW06 on 2023-03-23.
//
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <vector>
using namespace std;

class Operand {
public:
    virtual void calculate(stack<int>& nums) = 0;
    virtual string getOperator() const = 0;
    virtual ~Operand() {}
};

class numberOperand : public Operand {
public:
    numberOperand(int num) : number(num) {}
    void calculate(stack<int>& nums) override { nums.push(number); }
    string getOperator() const override { return to_string(number); }
private:
    int number;
};

class addOperand : public Operand {
public:
    void calculate(stack<int>& number) override {
        if (number.size() < 2) {
            throw runtime_error("amount of operand is less than needs to be");
        }
        int b = number.top();
        number.pop();
        int a = number.top();
        number.pop();
        number.push(a + b);
    }
    string getOperator() const override { return "+"; }
};

class subOperand : public Operand {
public:
    void calculate(stack<int>& number) override {
        if (number.size() < 2) {
            throw runtime_error("amount of operand is less than needs to be");
        }
        int b = number.top();
        number.pop();
        int a = number.top();
        number.pop();
        number.push(a - b);
    }
    string getOperator() const override { return "-"; }
};

class multiplyOperand : public Operand {
public:
    void calculate(stack<int>& number) override {
        if (number.size() < 2) {
            throw runtime_error("amount of operand is less than needs to be");
        }
        int b = number.top();
        number.pop();
        int a = number.top();
        number.pop();
        number.push(a * b);
    }
    string getOperator() const override { return "*"; }
};

class divisionOperand : public Operand {
public:
    void calculate(stack<int>& number) override {
        if (number.size() < 2) {
            throw runtime_error("amount of operand is less than needs to be");
        }
        int b = number.top();
        number.pop();
        int a = number.top();
        number.pop();
        number.push(a / b);
    }
    string getOperator() const override { return "/"; }
};
