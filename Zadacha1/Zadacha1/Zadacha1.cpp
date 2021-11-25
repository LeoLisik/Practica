#include <iostream>
using namespace std;

int main() {
    while (true) {
        int a;
        cout << "1 - Создать файл и записать в него строку" << endl << "2 - Заархивировать файл" << endl << "3 - Разархивировать файл" << endl << "Ваш выбор = ";
        cin >> a;
        switch (a) {
        case 1: { cout << "Функция в разработке" << endl; break; }
        case 2: { Encrypt(s); break; }
        case 3: { cout << "Функция в разработке" << endl; break; }
        }
    }
}
