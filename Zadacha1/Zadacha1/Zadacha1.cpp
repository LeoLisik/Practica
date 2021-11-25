#include <Windows.h>
#include "Header.h"
#include <fstream>
#include <locale.h>
#define ch enterStr.find_last_not_of("-0123456789.")
#define ch2 enterStr.find_last_of("-")
#define ch3  enterStr.find_last_of(".")-enterStr.find_first_of(".")

void Encrypt() { //Функция зашифровки строки
    string inputString, outputString;
    fstream file ("input.txt"); //Открыть файла ввода
    if (!file.is_open()) {cout << "Ошибка 1: Файл не открылся. Попробуйте для начала его создать." << endl; return;} //Проверка открытия файла
    getline(file, inputString); //Считать строку из файла
    file.close(); //Закрыть файл
    for (int i = 0, counterSameSimbols; i < inputString.length(); i += counterSameSimbols - 1) { //Цикл получающий каждый раз новый символ
        counterSameSimbols = 0; 
        outputString += inputString[i]; //Запись символа в итоговую строку 
        for (int i1 = i++; inputString[i] == inputString[i1]; i1++, counterSameSimbols++) {} //Счётчик количества одинакового символа
        if (counterSameSimbols == 0) { counterSameSimbols++; } //Если символ всего один, то увеличить counterSameSimbols на 1
        if (counterSameSimbols > 1) { //Если повторов символа больше 1, то записывать цифру
            outputString += to_string(counterSameSimbols);
        }
    }
    file.open("output.txt"); //Открытие файла вывода
    if (!file.is_open()) { cout << "Ошибка 1: Файл не открылся. Попробуйте для начала его создать." << endl; return; } //Проверка открытия файла
    file << outputString; //Записать итог в файл
    file.close(); //Закрыть файл
    cout << endl << endl << endl << "Архивация успешно выполнена" << endl << endl << endl << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int endProgram = 0; 
    while (endProgram == 0) { //Цикл работы программы
        int enterInt;
        string enterStr;
        cout << "1 - Создать файл и записать в него строку" << endl << "2 - Заархивировать файл" << endl << "3 - Разархивировать файл" << endl << "0 - Выход из программы" << endl << "Ваш выбор = ";
        getline(cin, enterStr);
        if ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0)) { enterInt = 9; } else { enterInt = atof(enterStr.c_str()); }
        switch (enterInt) { //Переключатель выборов пользователя
        case 1: { cout << "Функция в разработке" << endl; break; } //Запуск функцию создания файлов и записи в файл
        case 2: { Encrypt(); break; } //Запуск функции архивации файла
        case 3: { cout << "Функция в разработке" << endl; break; } //Запуск функции разархивации файла
        case 0: { endProgram = 1; break; } //Выход из программы
        }
    }
}