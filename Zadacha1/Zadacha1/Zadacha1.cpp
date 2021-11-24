#include <iostream>
#include <string>
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
        debug(1);
        char nowSymbol = inputString[i];
        for (int i1 = i++; true; i1++) {
            debug("abc");
            if (nowSymbol == inputString[i]) {
                
                counterSameSimbols++;
            } else {
                
                outputString += nowSymbol + counterSameSimbols;
            }
            break;
        }
    }
    return outputString;
}

int main()
{
    string s = "aaaaaa";
    cout << Encrypt(s);
}