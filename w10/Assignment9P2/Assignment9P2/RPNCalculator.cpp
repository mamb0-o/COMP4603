//
//  RPNCalculator.cpp
//  Assignment9P2
//
//  Created by GUW06 on 2023-03-23.
//
#include <iostream>
#include "Operand.cpp"
using namespace std;

class RPNCalculator {
public:
    void calculator() {
        string input;
        while (getline(cin, input)) {
            try {
                vector<shared_ptr<Operand>> operands = inputOperation(input);
                cout << "[" << input << "] = " << calculate(operands) << endl;
            } catch (exception& e) {
                cout << "invalid input" << endl;
            }
        }
    }

private:
    vector<shared_ptr<Operand>> inputOperation(const string& input) {
        vector<shared_ptr<Operand>> operands;
        istringstream stream(input);
        string token;
        while (stream >> token) {
                shared_ptr<Operand> op;
                if (token == "+") {
                    op = make_shared<addOperand>();
                } else if (token == "-") {
                    op = make_shared<subOperand>();
                } else if (token == "*") {
                    op = make_shared<multiplyOperand>();
                } else if (token == "/") {
                    op = make_shared<divisionOperand>();
                } else {
                    int num;
                    try {
                        num = stoi(token);
                        op = make_shared<numberOperand>(num);
                    } catch (...) {
                        throw runtime_error("token error ");
                    }
                }
            operands.push_back(op);
            }
            return operands;
        }

    int calculate(const vector<shared_ptr<Operand>>& operands) {
        stack<int> nums;
        for (const auto& op : operands) {
            op->calculate(nums);
        }
        if (nums.size() != 1) {
            throw runtime_error("amounto of operands exceeded");
        }
        return nums.top();
    }
};
