#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <string>

class ExpressionEvaluator {
public:
    // 检查表达式是否合法
    static bool isValid(const std::string& expression);

    // 计算表达式的值
    static double evaluate(const std::string& expression);

private:
    static double applyOp(double a, double b, char op);//计算两个数的运算结果
    static std::string infixToPostfix(const std::string& expression);//中缀表达式转后缀表达式
};
double scientificToDecimal(const std::string& scientificstring);
#endif
