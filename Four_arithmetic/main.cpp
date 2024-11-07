#include <iostream>
#include <string>
#include "expression_evaluator.h"

void testExpression(const std::string& expression) {
    try {
        double result = ExpressionEvaluator::evaluate(expression);
        std::cout << "Expression: " << expression << " = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Expression: " << expression << " is invalid (" << e.what() << ")" << std::endl;
    }
}

int main() {
    // Valid expressions
    std::cout << "Testing valid expressions:" << std::endl; //测试合法表达式
    testExpression("10+5");            // 基本加法
    testExpression("10-5");            // 基本减法
    testExpression("10+-5");           // 加负数
    testExpression("10+(-5)");         // 加带括号的负数
    testExpression("10-(-5)");         // 减带括号的负数
    testExpression("(10+5)*3");        // 括号在前的简单复合运算
    testExpression("10*(5+2)");        // 括号在后的简单复合运算
    testExpression("10/2");            // 除法
    testExpression("3.5*2");           // 乘法
    testExpression("-(-5+3)*2");       // 负的括号
    testExpression("5 + 3 * -2");      // 乘负数，且表达式带空格
    testExpression("5 + 3 / -2");      // 除负数，且表达式带空格
    testExpression("2-(-1+2.1e-2)");   // 科学计数法复合运算，负指数
    testExpression("2-(-1+2.1e2)");    // 科学计数法复合运算，正指数

    // Invalid expressions
    std::cout << "\nTesting invalid expressions:" << std::endl;//测试不合法表达式
    testExpression("10++5");           // 重复运算符
    testExpression("10+-+5");          
    testExpression("10---5");          // 双重负号
    testExpression("(10+5");           // 少括号
    testExpression("10+5)");           
    testExpression("5/0");             // 除0
    testExpression("10*/5");           
    testExpression("10+*5");           
    testExpression("5..5+3");          // 多个小数点
    testExpression("abc+5");           // 不合法字符

    // Edge cases
    std::cout << "\nTesting edge cases:" << std::endl; //极端情况测试
    testExpression("-5");              // 只有一个负数
    testExpression("-(-5)");            // 只有一个负的带括号的数字
    testExpression("-(19.4 + -5.1)");  // 负的括号，且括号内带小数点的负数
    testExpression("0");               // 0
    testExpression("(((((10)))))");    // 多重括号
    testExpression("(((()10)))");      // 多重括号，但括号内没有数字，不合法
    testExpression("5+-((-3.3))");       // 三重运算符，但用括号隔开，合法
    testExpression("5-(1-(3+6)*2)");   //括号内叠括号
    // 用户输入
    std::cout << "Enter an expression to evaluate: ";
    std::string expression;
    std::getline(std::cin, expression);
    testExpression(expression);
    return 0;
}
