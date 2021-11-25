#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
void debug(string s) {
    cout << "Debug = " << s << endl;
}

void debug(int x) {
    cout << "Debug = " << x << endl;
}

string Encrypt(string inputString) { //Функция зашифровки строки
    string outputString;
    for (int i = 0, counterSameSimbols = 1; i < inputString.length(); i += counterSameSimbols) {
        debug("Первый цикл");
        char nowSymbol = inputString[i];
        outputString += nowSymbol;
        string resultSymbols;
        for (int i1 = i++; nowSymbol == inputString[i1]; i1++, counterSameSimbols++) {
            debug("Второй цикл");
        }
        cout << endl << counterSameSimbols--;
        outputString += counterSameSimbols--;
    }
    return outputString;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s = "aaaaaab";
    cout << Encrypt(s);
}