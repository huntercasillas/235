#pragma once
#include "ExpressionManagerInterface.h"
#include <sstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <iostream>


using namespace std;

class ExpressionManager : public ExpressionManagerInterface {
	
public:
	ExpressionManager();
	virtual ~ExpressionManager();
	
	void print(stack <string> someStack);
	
	void clear(stack <string> someStack);
	
	bool isLeftParenthesis(string someString);
	
	bool isRightParenthesis(string someString);
	
	bool isLowOrder(string someString);
	
	bool isHighOrder(string someString);
	
	bool isInt(string someString);
	
	bool errorChecking(string expression);
	
	string parenthesesSwitch(string someString);
	
	bool isBalanced(string expression);
	
	string doMath(string operand, int value1, int value2);
		 
	string postfixToInfix(string postfixExpression);
	
	string infixToPostfix(string infixExpression);
		
	string postfixEvaluate(string postfixExpression);
};