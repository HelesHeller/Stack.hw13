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
                return false; // Немає відповідної відкриваючої дужки
            }

            char top = parenthesesStack.top();
            parenthesesStack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // Дужки не відповідають одна одній
            }
        }
    }

    return parenthesesStack.empty(); // Всі дужки відповідають одна одній
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;

    std::cout << "Введіть рядок: ";
    std::getline(std::cin, str);

    if (CheckParentheses(str)) {
        std::cout << "Рядок містить коректне розташування дужок." << std::endl;
    }
    else {
        std::cout << "Рядок містить некоректне розташування дужок." << std::endl;
    }

    return 0;
}
