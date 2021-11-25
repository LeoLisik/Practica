#include <Windows.h>
#include "Header.h"


string Encrypt(string inputString) { //Функция зашифровки строки
    string outputString;
    for (int i = 0, counterSameSimbols; i < inputString.length(); i += counterSameSimbols - 1) { //Цикл получающий каждый раз новый символ
        debug("Первый цикл"); 
        counterSameSimbols = 0; 
        outputString += inputString[i]; //Запись символа в итоговую строку 
        for (int i1 = i++; inputString[i] == inputString[i1]; i1++, counterSameSimbols++) { debug("Второй цикл"); } //Счётчик количества одинакового символа
        if (counterSameSimbols == 0) { counterSameSimbols++; } //Если символ всего один, то увеличить counterSameSimbols на 1
        if (counterSameSimbols > 1) { //Если повторов символа больше 1, то записывать цифру
            outputString += to_string(counterSameSimbols);
        }
    }
    return outputString; //Возврат зашифрованой строки
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s = "Борщщщщщщщщ"; 
    cout << Encrypt(s);
}