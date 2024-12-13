// Example of Infix to Postfix Conversion Algorithm
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s; // Stack to store operators and parentheses
    string postfix = ""; // Resultant postfix expression

    for (char ch : infix) {
        if (isalnum(ch)) {
            // Operand: Append to postfix
            postfix += ch;
        } else if (ch == '(') {
            // Opening parenthesis: Push onto stack
            s.push(ch);
        } else if (ch == ')') {
            // Closing parenthesis: Pop until matching '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        } else if (isOperator(ch)) {
            // Operator: Pop operators with higher or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch); // Push current operator
        }
    }

    // Pop remaining operators from stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}

