#include <iostream>
#include <string>
#include <Windows.h>
#include <queue>
using namespace std;

queue <char> output;

struct Post {
	string input;
	string output;
}A;

void InputS(string s, Post& A) {
    if (s.empty() or s.find_first_of("-+*:") == -1 or s.find_first_of("0123456789") == -1) { 
        cout << "\x1b[31mОшибка\x1b[0m\n";
        return;
    }
	A.input = s;
}

void OutputS(Post& A) {
    for (int i = 0; i < A.input.length(); i++) {
        if (A.input[i] >= '0' and A.input[i] <= '9') {
            output.push(A.input[i]);
        }
        
    }
}

void Display(Post& A) {
    cout << "\nInput = " << A.input << "\nOutput = " << A.output << endl;
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
        if ((enterStr.find_last_not_of("0123") != -1) or (enterStr.empty())) { cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m" << endl; continue; }
        else { enterInt = atof(enterStr.c_str()); }
        if (enterInt < 0 or enterInt > 3) { cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m" << endl; continue; }
        switch (enterInt) { //Переключатель выбора пользователя
        case 1: { 
            cout << "Введите пример = ";
            getline(cin, enterStr);
            InputS(enterStr, A);
            break; 
        } //Запуск функции ввода примера в структуру
        case 2: { 
            OutputS(A); 
            break; 
        } //Запуск функции перевода в постфиксную форму
        case 3: { 
            Display(A); 
            break; 
        } //Запуск функции отображения структуры
        case 0: { 
            endProgram = 1; 
            break; 
        } //Выключение программы
        }
    }
}