#include "expression_evaluator.h"
#include <stack>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cmath>
bool ExpressionEvaluator::isValid(const std::string& expression) {
    std::stringstream ss(expression);
    std::string temp;
    std::string t;
    while(ss >> t)
    {
        temp += t;
    }
    // std::cout << temp << std::endl;
    std::stack<char> s;
    bool lastWasOp = true;
    bool hasnum = false;
    // int minuscount = 0;
    for (size_t i = 0; i < temp.size(); i++) {
        char ch = temp[i];
        
        if (ch == '(') {
            s.push(ch);
            lastWasOp = true;
        } else if (ch == ')') {
            if (s.empty() || (i < temp.size() - 1 && isdigit(temp[i + 1]))) return false;
            s.pop();
            lastWasOp = false;
        } else if (ch == '.') {
            if (i == 0 || i == temp.size() - 1 || !isdigit(temp[i - 1]) || !isdigit(temp[i + 1])) {
                return false;
            }
        } else if (ch == 'e'){
            if (i == 0 || i == temp.size() - 1 || !isdigit(temp[i - 1]) || !(isdigit(temp[i + 1]) || temp[i + 1] == '-')) {
                if (temp[i+1] == 'e') lastWasOp = false;
                return false;
            }
        } else if (ch == '+' || ch == '*' || ch == '/') {
            if (lastWasOp || temp[i-1] == '-') return false;
            lastWasOp = true;
        } else if (ch == '-') {
            if (lastWasOp) {
                lastWasOp = false;
            } else {
                if (i > 0 && temp[i - 1] == '-') return false;
                lastWasOp = true;
            }
        } else if (isdigit(ch)) {
            lastWasOp = false;
            hasnum = true;
        } else {
            return false;
        }
    }

    return s.empty() && hasnum && !lastWasOp;
}


std::string ExpressionEvaluator::infixToPostfix(const std::string& expression) {
    std::stringstream ss(expression);
    std::string temp;
    std::string t;
    while(ss >> t)
    {
        temp += t;
    }
    std::stack<char> s;
    std::string postfix;
    std::string tempNumber;
    bool expectUnary = true;
    bool minus_flag = false;
    bool in_q_flag = false;
    bool Last_Is_e = false;
    for (size_t i = 0; i < temp.size(); i++) {
        char ch = temp[i];
        // std::cout <<tempNumber<<std::endl;
        if (ch == '(') {
            s.push(ch);
            expectUnary = true;
            in_q_flag = true;
        } else if (ch == ')') {
            if (!tempNumber.empty()) {
                if (in_q_flag && minus_flag){
                    if(tempNumber[0] != '-')
                        postfix += '-';
                    else {
                        tempNumber = tempNumber.substr(1,tempNumber.size()-1);
                        // double t1 = -1*std::stod(tempNumber);
                        // tempNumber = std::to_string(t1);
                    }
                }
                postfix += tempNumber + ' ';
                tempNumber.clear();
            }
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
            expectUnary = false;
            in_q_flag = false;
            minus_flag = false;
        } else if (isdigit(ch) || ch == '.' || ch == 'e') {
            // if(in_q_flag && minus_flag){
            //     if(tempNumber == "-")
            //         tempNumber.clear();
            //     else
            //         tempNumber += '-';
            // }
            tempNumber += ch;
            expectUnary = false;
            if (ch == 'e'){
                expectUnary = true;
                Last_Is_e = true;
            }
            
        } else if (ch == '+' || ch == '-') {
            if (!tempNumber.empty() && tempNumber != "-" && !Last_Is_e) {
                if (in_q_flag && minus_flag){
                    if(tempNumber[0] != '-')
                        postfix += '-';
                    else {
                        tempNumber = tempNumber.substr(1,tempNumber.size()-1);
                        // double t1 = -1*std::stod(tempNumber);
                        // tempNumber = std::to_string(t1);
                    }
                }
                postfix += tempNumber + ' ';
                tempNumber.clear();
            }
            if (expectUnary && ch == '-') {
                if (!isdigit(temp[i+1])) minus_flag = true;
                else tempNumber += '-';
            } else {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    postfix += ' ';
                    s.pop();
                }
                s.push(ch);
            }
            expectUnary = true;
        } else if (ch == '*' || ch == '/') {
            if (!tempNumber.empty()) {
                if (in_q_flag && minus_flag){
                    if(tempNumber[0] != '-')
                        postfix += '-';
                    else {
                        tempNumber = tempNumber.substr(1,tempNumber.size()-1);
                        // double t1 = -1*std::stod(tempNumber);
                        // tempNumber = std::to_string(t1);
                    }
                }
                postfix += tempNumber + ' ';
                tempNumber.clear();
            }
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(ch);
            expectUnary = true;
        }
    }

    if (!tempNumber.empty()) {
        if (in_q_flag && minus_flag){
                    if(tempNumber[0] != '-')
                        postfix += '-';
                    else {
                        tempNumber = tempNumber.substr(1,tempNumber.size()-1);
                        // double t1 = -1*std::stod(tempNumber);
                        // tempNumber = std::to_string(t1);
                    }
                }
        postfix += tempNumber + ' ';
    }
    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    return postfix;
}



double ExpressionEvaluator::applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("ILLEGAL");
            return a / b;
    }
    return 0;
}

double scientificToDecimal(const std::string& scientificstring)
{
    double a = stod(scientificstring.substr(0,scientificstring.find('e')));
    double b = stod(scientificstring.substr(scientificstring.find('e')+1));
    return a*pow(10,b);
}
double ExpressionEvaluator::evaluate(const std::string& expression) {
    if (!isValid(expression)) throw std::runtime_error("ILLEGAL");
    std::string postfix = infixToPostfix(expression);
    // std::cout << postfix << std::endl;
    std::stack<double> values;
    std::istringstream iss(postfix);
    // std::cout << postfix << std::endl;
    std::string token;
    
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double b = values.top();
            values.pop();
            double a = values.top();
            values.pop();
            values.push(applyOp(a, b, token[0]));
        } else {
            if (token.find('e') != std::string::npos){
                token = std::to_string(scientificToDecimal(token));
                // std::cout << token << std::endl;
            }
            values.push(std::stod(token));
        }
    }
    return values.top();
}
