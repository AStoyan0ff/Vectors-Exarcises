#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Проверка дали скобите съвпадат
static bool isMatch(char open, char close) {
    
    return 
        (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

// Проверка: вътрешна скоба дали е допустима за дадена външна
static bool isAllow(char outer, char inner) {
    
    if (outer == '{') return inner == '{' || inner == '[' || inner == '(';
    if (outer == '[') return inner == '[' || inner == '(';
    if (outer == '(') return inner == '(';
    
    return false; 
}

static bool bracketsValid(const string& expr) {
    vector<char> stack; 

    for (char c : expr) {
        if (c == '{' || c == '[' || c == '(') {
            // Дали текущата отваряща скоба е допустима... checked
            if (!stack.empty() && !isAllow(stack.back(), c)) {
                return false;
            }
            stack.push_back(c); // add отварящата скоба в стека
        }
        else if (c == '}' || c == ']' || c == ')') {
            // Проверка за съответстваща отваряща скоба
            if (stack.empty() || !isMatch(stack.back(), c)) {
                return false;
            }
            stack.pop_back(); //Oтварящата скоба от стека -> out
        }
        else {
           
            return false;
        }
    }

    return stack.empty();
}

int main() {
    
    string expr;
    getline(cin, expr);

    if (bracketsValid(expr)) {
        cout << "valid" << endl;
    }
    else {
        cout << "invalid" << endl;
    }

    return 0;
}
