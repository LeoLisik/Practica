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
        if (enterStr.find_first_of("0123456789") < -1) { cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m" << endl; } //Вывод ошибки при обнаружении чисел
        else { forInput = enterStr; enterStr.clear(); } //Сохранение строки в другой переменной и очищение вводной строки для дальнейшего использования
    }
    if (File) { //Если input открылся
        cout << "Файл input уже существует, хотите перезаписать его?" << endl;
        while (enterInt != 1 and enterInt != 2) { //Пока выбор пользователя некоректный
            cout << "1 - Да" << endl << "2 - Нет" << endl << "Ваш выбор = ";
            getline(cin, enterStr);
            cout << endl << endl;
            if ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0)) { cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m"; enterInt = 9; } //Проверка на буквы
            else { enterInt = atof(enterStr.c_str()); } 
            enterStr.clear(); //Очистка enterStr
            if (enterInt != 1 and enterInt != 2) { cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m" << endl; } //Проверка на допустимое число
            switch (enterInt) { //Переключатель выбора пользователя
            case 1: { File.close(); remove("input.txt"); File.open("input.txt", ios::out | ios::app); File << forInput; File.close(); cout << "\n" << "\x1b[32mФайл успешно перезаписан\x1b[0m" << "\n\n\n\n"; break; } //Перезаписать input
            case 2: { File.close(); cout << "\n" << "\x1b[33mФайл остался без изменений\x1b[0m" << "\n\n\n\n"; break; } //Закрыть input
            }
        }
    }
    else { File.open("input.txt", ios::in | ios::app); File << forInput;  File.close(); cout << "\n" << "\x1b[32mФайл успешно записан\x1b[0m" << "\n\n\n\n"; } //Если input не открылся - создать
    File.open("output.txt");
    if (!File) { File.open("output.txt", ios::in | ios::app); File.close(); cout << "\n" << "\x1b[32moutput.txt успешно создан\x1b[0m" << "\n\n\n\n"; } //Если output не открылся - создать
}

void Archive() { //Функция зашифровки строки
    string inputString, outputString;
    fstream file ("input.txt"); //Открыть файла ввода
    if (!file.is_open()) {cout << "\n" << "\x1b[31mОшибка 1: Файл не открылся. Попробуйте для начала его создать.\x1b[0m" << "\n\n\n\n"; return;} //Проверка открытия файла
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
    if (!file.is_open()) { cout << "\n" << "\x1b[31mОшибка 1: Файл не открылся. Попробуйте для начала его создать.\x1b[0m" << "\n\n\n\n"; return; } //Проверка открытия файла
    file << outputString; //Записать итог в файл
    file.close(); //Закрыть файл
    cout << "\n" << "\x1b[32mАрхивация успешно выполнена\x1b[0m" << "\n\n\n\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int endProgram = 0;
    while (endProgram == 0) { //Цикл работы программы
        int enterInt;
        string enterStr;
        cout << "1 - Создать файлы и записать строку" << endl << "2 - Заархивировать файл" << endl << "3 - Разархивировать файл" << endl << "0 - Выход из программы" << endl << "Ваш выбор = ";
        getline(cin, enterStr);
        cout << endl << endl;
        if ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0) or (enterStr.empty()) or (ch2 == 0)) { cout << "\x1b[31mОшибка 0: Некоректный ввод данных\x1b[0m" << endl; enterInt = 9; }
        else { enterInt = atof(enterStr.c_str()); }
        if (enterInt < 0 or enterInt > 3 and enterInt != 9) { cout << "\x1b[31mОшибка 2: Такой команды не существует\x1b[0m" << endl; }
        switch (enterInt) { //Переключатель выбора пользователя
        case 1: { CreateInput(); break; } //Запуск функции создания файлов
        case 2: { Archive(); break; } //Запуск функции зашифровки файлов
        case 3: { cout << endl << "Функция в разработке" << endl << endl << endl; break; } //Запуск функции расшифровки файла
        case 0: { endProgram = 1; break; } //Выключение программы
        }
    }
}