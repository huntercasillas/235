#include "ExpressionManager.h"

using namespace std;

ExpressionManager::ExpressionManager() {}
ExpressionManager::~ExpressionManager() {}


void ExpressionManager::print(stack <string> someStack) {
    stack <string> tempStack;
    tempStack = someStack;
    while (!tempStack.empty()) {
        cout << "contents of stack:" << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl << endl;
}

void ExpressionManager::clear(stack <string> someStack) {
    while (!someStack.empty()) {
        someStack.pop();
    }
}

bool ExpressionManager::isLeftParenthesis(string someString) {
    if (someString == "(" || someString == "[" || someString == "{") {
        return true;
    }
    else {
        return false;
    }
}

bool ExpressionManager::isRightParenthesis(string someString) {
    if (someString == ")" || someString == "]" || someString == "}") {
        return true;
    }
    else {
        return false;
    }
}

bool ExpressionManager::isLowOrder(string someString) {
    if (someString == "+" || someString == "-") {
        return true;
    }
    else {
        return false;
    }
}

bool ExpressionManager::isHighOrder(string someString) {
    if (someString == "*" || someString == "/" || someString == "%") {
        return true;
    }
    else {
        return false;
    }
}

bool ExpressionManager::isInt(string someString) {
    for (int i = 0; i < someString.size(); i++) {
        if (!isdigit(someString[i])) {
            return false;
        }
    }
    return true;
}

string ExpressionManager::parenthesesSwitch(string someString) {
    if (someString == ")") {
        return "(";
    }
    else if (someString == "]") {
        return "[";
    }
    else if (someString == "}") {
        return "{";
    }
}

bool ExpressionManager::isBalanced(string expression) {
    stringstream ss(expression);
    stack <string> balanceStack;
    string someString;
    
    while (ss >> someString) {
        if (isLeftParenthesis(someString)) {
            balanceStack.push(someString);
        }
        else if (isRightParenthesis(someString)) {
            if (balanceStack.empty()) {
                return false; 
            }
            if (balanceStack.top() == parenthesesSwitch(someString)) {
                balanceStack.pop();
            }
            else {
                return false;
            }
        }
    }
    
    if (balanceStack.empty()) {
        return true;
    }
    return false;
}

bool ExpressionManager::errorChecking(string expression) {
    if (!isBalanced(expression)) {
        return true;
    }
    
    stringstream firstss(expression);
    stringstream ss(expression);
    string someString;
    int numOperators = 0;
    int numInts = 0;
    string firstString;
    
    
    firstss >> firstString;
    if (isHighOrder(firstString) || isLowOrder(firstString)) {
        return true;
    }
    
    while (ss >> someString) {
        
        if (!isHighOrder(someString) && !isLowOrder(someString) && !isInt(someString) && !isLeftParenthesis(someString) && !isRightParenthesis(someString)) {
            return true;
        }
        
        if (isInt(someString)) {
            numInts += 1;
        }
        else if (isHighOrder(someString) || isLowOrder(someString)) {
            numOperators += 1;
        }
        
    }
    
    if (numOperators != (numInts - 1)) {
        return true;
    }
    
    return false;
}

string ExpressionManager::postfixToInfix(string postfixExpression) {
    if (errorChecking(postfixExpression)) {
        return "invalid";
    }
    
    string someString;
    stringstream ss(postfixExpression);
    stringstream out;
    string tempString;
    string infixExpression;
    string value1;
    string value2;
    
    stack <string> myStack;
    
    while (ss >> someString) {
        if (isInt(someString)) {
            myStack.push(someString);
        }
        else if (isHighOrder(someString) || isLowOrder(someString)) {
            if (myStack.size() < 2) {
                return "invalid";
            }
            value2 = myStack.top();
            myStack.pop();
            value1 = myStack.top();
            myStack.pop();
            out << "( " << value1 << " " << someString << " " << value2 << " )";
            tempString = out.str();
            myStack.push(tempString);
            out.str("");
            out.clear();
        }
    }
    
    while (!myStack.empty()) {
        if (isInt(myStack.top())) {
            return "invalid";
        }
        out << myStack.top();
        myStack.pop();
    }
    tempString = out.str();
    return tempString;
    
}

string ExpressionManager::infixToPostfix(string infixExpression) {
    if (errorChecking(infixExpression)) {
        return "invalid";
    }
    
    stringstream ss(infixExpression);
    string someString;
    string tempString;
    stack<string> myStack;
    stringstream out;
    
    cout << infixExpression << endl;
    while (ss >> someString) {
        if (isLeftParenthesis(someString)) {
            myStack.push(someString);
        }
        else if (isHighOrder(someString)) {
            while (!myStack.empty() && isHighOrder(myStack.top())) {
                out << myStack.top() << " ";
                myStack.pop();
            }
            myStack.push(someString);
        }
        else if (isInt(someString)) {
            out << someString << " ";
        }
        else if (isLowOrder(someString)) {
            while (!myStack.empty() && (isHighOrder(myStack.top()) || isLowOrder(myStack.top()))) {
                out << myStack.top() << " ";
                myStack.pop();
            }
            myStack.push(someString);
        }
        else if (isRightParenthesis(someString)) {
            while (!isLeftParenthesis(myStack.top())) {
                out << myStack.top() << " "; 
                myStack.pop();
            }
            myStack.pop();
        }
    }
    while (!myStack.empty()) {
        out << myStack.top() << " ";
        myStack.pop();
    }
    
    tempString = out.str();
    return tempString;
}

string ExpressionManager::doMath(string operand, int value1, int value2) {
    int final = 0;
    
    if (operand == "+") {
        final = (value1 + value2);
    }
    else if (operand == "-") {
        final = (value1 - value2);
    }
    else if (operand == "*") {
        final = (value1 * value2);
    }
    else if (operand == "/") {
        if (value2 == 0) {
            return "invalid";
        }
        final = (value1 / value2);
    }
    else if (operand == "%") {
        if (value2 == 0) {
            return "invalid";
        }
        final = (value1 % value2);
    }
    return to_string(final);
}
	
	
string ExpressionManager::postfixEvaluate(string postfixExpression) {
    if (errorChecking(postfixExpression)) {
        return "invalid";
    }
    
    stringstream ss(postfixExpression);
    stack <string> myStack;
    string someString;
    string tempString;
    int value1 = 0;
    int value2 = 0;
    int final = 0;
    
    cout << ss.str();
    while (ss >> someString) {
        if (isInt(someString)) {
            myStack.push(someString);
        }
        else if (isHighOrder(someString) || isLowOrder(someString)) {
            value2 = stoi(myStack.top());
            myStack.pop();
            value1 = stoi(myStack.top());
            myStack.pop();
            tempString = doMath(someString, value1, value2);
            if (tempString == "invalid") {
                return tempString;
            }
            myStack.push(tempString);
        }
    }
    
    if (myStack.size() == 1) {
        return myStack.top();
    }
    else {
        return "invalid";
    }
}
