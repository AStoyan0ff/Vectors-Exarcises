#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// �������� ���� ������� ��������
static bool isMatch(char open, char close) {
    
    return 
        (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

// ��������: �������� ����� ���� � ��������� �� ������ ������
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
            // ���� �������� �������� ����� � ���������... checked
            if (!stack.empty() && !isAllow(stack.back(), c)) {
                return false;
            }
            stack.push_back(c); // add ���������� ����� � �����
        }
        else if (c == '}' || c == ']' || c == ')') {
            // �������� �� ������������� �������� �����
            if (stack.empty() || !isMatch(stack.back(), c)) {
                return false;
            }
            stack.pop_back(); //O��������� ����� �� ����� -> out
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
