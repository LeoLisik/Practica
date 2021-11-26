#include <Windows.h>
#include "Header.h"
#include <fstream>
#include <locale.h>
#define ch enterStr.find_last_not_of("-0123456789.")
#define ch2 enterStr.find_last_of("-")
#define ch3  enterStr.find_last_of(".")-enterStr.find_first_of(".")

void CreateInput() { //Функция создания и ввода в input/output
    fstream File("input.txt");
    int enterInt = 9;
    string enterStr = " 1";
    string forInput;
    while (enterStr.find_first_of("0123456789") < -1) { //Пока в строке есть цифры
        cout << "Введите строку для записи в файл = ";
        getline(cin, enterStr);
        cout << endl << endl;
        if (enterStr.find_first_of("0123456789") < -1) { cout << "\x1b[31mПожалуйста введите строку без чисел\x1b[0m" << endl; } //Вывод ошибки при обнаружении чисел
        else { forInput = enterStr; enterStr.clear(); } //Сохранение строки в другой переменной и очищение вводной строки для дальнейшего использования
    }
    if (File) { //Если input открылся
        cout << "Файл input уже существует, хотите перезаписать его?" << endl;
        while (enterInt != 1 and enterInt != 2) { //Пока выбор пользователя некоректный
            cout << "1 - Да" << endl << "2 - Нет" << endl;
            getline(cin, enterStr);
            cout << endl << endl;
            if ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0)) { cout << "\x1b[31mПожалуйста введите допустимое число\x1b[0m" << endl; enterInt = 9; } //Проверка на буквы
            else { enterInt = atof(enterStr.c_str()); } 
            enterStr.clear(); //Очистка enterStr
            if (enterInt != 1 and enterInt != 2) { cout << "\x1b[31mПожалуйста введите допустимое число\x1b[0m" << endl; } //Проверка на допустимое число
            switch (enterInt) { //Переключатель выбора пользователя
            case 1: { File.close(); remove("input.txt"); File.open("input.txt", ios::out | ios::app); File << forInput; File.close(); } //Перезаписать input
            case 2: { File.close(); } //Закрыть input
            }
        }
    } else { File.open("input.txt", ios::in | ios::app); File << forInput;  File.close(); } //Если input не открылся - создать
    File.open("output.txt");
    if (!File) { File.open("output.txt", ios::in | ios::app); File.close(); } //Если output не открылся - создать
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
    int endProgram = 0;
    while (endProgram == 0) { //Öèêë ðàáîòû ïðîãðàììû
        int enterInt;
        string enterStr;
        cout << "1 - Ñîçäàòü ôàéë è çàïèñàòü â íåãî ñòðîêó" << endl << "2 - Çààðõèâèðîâàòü ôàéë" << endl << "3 - Ðàçàðõèâèðîâàòü ôàéë" << endl << "0 - Âûõîä èç ïðîãðàììû" << endl << "Âàø âûáîð = ";
        getline(cin, enterStr);
        cout << endl << endl;
        if ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0)) { enterInt = 9; }
        else { enterInt = atof(enterStr.c_str()); }
        switch (enterInt) { //Ïåðåêëþ÷àòåëü âûáîðîâ ïîëüçîâàòåëÿ
        case 1: { cout << endl << "Ôóíêöèÿ â ðàçðàáîòêå" << endl << endl << endl; break; } //Çàïóñê ôóíêöèþ ñîçäàíèÿ ôàéëîâ è çàïèñè â ôàéë
        case 2: { Encrypt(); break; } //Çàïóñê ôóíêöèè àðõèâàöèè ôàéëà
        case 3: { cout << endl << "Ôóíêöèÿ â ðàçðàáîòêå" << endl << endl << endl; break; } //Çàïóñê ôóíêöèè ðàçàðõèâàöèè ôàéëà
        case 0: { endProgram = 1; break; } //Âûõîä èç ïðîãðàììû
        }
    }
}