#include <iostream>
#include <stack>
#include <string>
#include<Windows.h>

bool CheckParentheses(const std::string& str) {
    std::stack<char> parenthesesStack;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            parenthesesStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (parenthesesStack.empty()) {
                return false; // ���� �������� ���������� �����
            }

            char top = parenthesesStack.top();
            parenthesesStack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // ����� �� ���������� ���� ����
            }
        }
    }

    return parenthesesStack.empty(); // �� ����� ���������� ���� ����
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;

    std::cout << "������ �����: ";
    std::getline(std::cin, str);

    if (CheckParentheses(str)) {
        std::cout << "����� ������ �������� ������������ �����." << std::endl;
    }
    else {
        std::cout << "����� ������ ���������� ������������ �����." << std::endl;
    }

    return 0;
}
