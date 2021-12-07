#include <iostream>
#include <string>
#include <Windows.h>
#include <stack>
using namespace std;

struct Post { //Создание структуры и экземпляра
	string input;
	string output;
}A;

void InputS(string s, Post& A) { //Функция проверяющая переданную строку на корректность и помещающая её в структуру
    if (s.empty() or s.find_first_of("-+*:") == -1 or s.find_first_of("0123456789") == -1) {
        cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m\n";
    } else {
        A.input = s;
        cout << "\n\n\n\x1b[32mПример успешно записан!\x1b[0m\n\n\n\n\n";
    }
}

void OutputS(Post& A) { //Функция перевода input в постфиксную форму
    if (A.input.empty()) {
        cout << "\x1b[31mОшибка 404: Пример не найден. Попробуйте выбрать ввод примера в структуру\x1b[0m\n";
        return;
    }
    stack <char> operands; //Объявление стека
    string output;
    int brackets = 0;
    for (int i = 0; i < A.input.length(); i++) { //Цикл считывает пример по символу
        if (isdigit(A.input[i])) { //Если символ цифра
            output += A.input[i];
        }
        if (A.input[i] == '+' or A.input[i] == '-' or A.input[i] == '*' or A.input[i] == ':') { //Если символ знак
            if (operands.empty() or operands.top() == '(') { //Если стек пуст или на его выршине открывающаяся скобка
                operands.push(A.input[i]); 
            } 
            else { 
                output += operands.top();
                operands.pop();
                operands.push(A.input[i]);
            }
        }
        if (A.input[i] == '(') { //Если символ открывающаяся скобка
            operands.push(A.input[i]);
            brackets++;
        }
        if (A.input[i] == ')') { //Если символ закрывающаяся скобка
            brackets--;
            if (brackets < 0) { //Если закрывающаяся скобка идет без открывающей
                cout << "\x1b[31mОшибка 1: Встречена закрывающая скобка без открывающей. Проверьте корректность примера\x1b[0m\n"; 
                return; 
            } 
            while(operands.top() != '(') { //Пока в стеке не найдена открывающаяся скобка, добавлять элементы стека в итог
                output += operands.top();
                operands.pop();
            }
            operands.pop();
        }
    }
    while (!operands.empty()) { //Пока стек не пуст, добавлять символы из него в итог
        output += operands.top();
        operands.pop();
    }
    A.output.clear(); //Очистка output, на случай если в нём что-то было
    A.output = output; //Запись итоговой строки в структуру
    cout << "\n\n\n\x1b[32mПреобразование успешно выполнено\x1b[0m\n\n\n\n\n";
}

void Display(Post& A) { //Функция выводит поля структуры
    if (A.input.empty() or A.output.empty()) {
        cout << "\x1b[31mОшибка 2: Инфиксная или постфиксная форма записи отсутствует, попробуйте последовательно запустить команды 1 и 2\x1b[0m\n";
    }
    else {
        cout << "\n\n\n\x1b[32mВаша структура:\nA.input = " << A.input << "\nA.output = " << A.output << "\x1b[0m\n\n\n\n\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int enterInt, endProgram = 0;
    string enterStr;
    while (endProgram == 0) { //Цикл работы программы
        cout << "1 - Ввести пример в структуру\n" << "2 - Перевести пример в постфиксную форму\n" << "3 - Вывести input и output\n" << "0 - Выход из программы\n" << "Ваш выбор = ";
        getline(cin, enterStr);
        cout << "\n\n";
        if ((enterStr.find_last_not_of("0123") != -1) or (enterStr.empty())) { //Если в строке обнаружены некоректные символы
            cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m\n"; 
            continue; 
        } else { 
            enterInt = atof(enterStr.c_str()); 
        }
        if (enterInt < 0 or enterInt > 3) { //Если введенное число недопустимо
            cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m\n"; 
            continue; 
        }
        switch (enterInt) { //Переключатель выбора пользователя
        case 1: { //Запуск функции ввода примера в структуру
            cout << "Введите пример = ";
            getline(cin, enterStr);
            InputS(enterStr, A);
            break; 
        } 
        case 2: { //Запуск функции перевода в постфиксную форму
            OutputS(A); 
            break; 
        } 
        case 3: { //Запуск функции отображения структуры
            Display(A); 
            break; 
        } 
        case 0: { //Выключение программы
            endProgram = 1; 
            break; 
        } 
        }
    }
}