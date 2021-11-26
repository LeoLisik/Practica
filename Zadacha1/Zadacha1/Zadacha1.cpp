#include <Windows.h>
#include "Header.h"
#include <fstream>
#include <locale.h>
#define ch enterStr.find_last_not_of("-0123456789.")
#define ch2 enterStr.find_last_of("-")
#define ch3  enterStr.find_last_of(".")-enterStr.find_first_of(".")

void CreateInput() {
    fstream File("input.txt");
    int enterInt = 9;
    string enterStr;
    if (File) {
        cout << "Файл input уже существует, хотите перезаписать его?" << endl;
        while (enterInt != 1 and enterInt != 2) {
            cout << "1 - Да" << endl << "2 - Нет" << endl;
            getline(cin, enterStr);
            cout << endl << endl;
            if ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0)) { cout << "\x1b[31mПожалуйста введите допустимое число\x1b[0m" << endl; enterInt = 9; }
            else { enterInt = atof(enterStr.c_str()); }
            if (enterInt != 1 and enterInt != 2) { cout << "\x1b[31mПожалуйста введите допустимое число\x1b[0m" << endl; }
            switch (enterInt) {
            case 1: { File.close(); remove("input.txt"); File.open("input.txt", ios::out | ios::app); }
            case 2: {}
            }
        }
    }
}

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
    cout << endl << "Архивация успешно выполнена" << endl << endl << endl << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CreateInput();
}