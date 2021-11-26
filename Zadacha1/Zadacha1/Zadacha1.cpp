#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

void Dearchive() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string CountStringOutput, CountOutput, SimvolCountOutput, StringNumbersLetter, Dearchive = "";
    int NumbersLetter, ProverkaNumbers = 0;
    char  SimvolCount;
    ifstream Read("output.txt"); //создаём поток файла + открываем файл output.txt для чтения 
    if (!Read.is_open()) {  //проверка на открытие файла
        cout << "Ошибка открытия файла output.txt. Возможно его не существует.";
        return;
    }
    while (getline(Read, CountStringOutput)) { //цикл, который работает, пока в файле не закончится строки + каждую строчку из файла вносим в строку CountStringOutput
        CountOutput = CountOutput + CountStringOutput; //объединяем все строки из файла в одну строку CountOutput
        CountStringOutput.erase(0); //очищаем строку CountStringOutput
    }
    cout << "Было:" << CountOutput << endl;
    Read.close();//закрываем файл
    for (int i = 0; i < CountOutput.length(); i++) { //цикл, повторяющийся столько раз, сколько в строке CountOutput символов
        SimvolCountOutput.replace(0, 2, CountOutput, i, 1); //заменяем символы в строке SimvolCountOutput на каждый следующий символ (i) из строки CountOutput
        SimvolCount = SimvolCountOutput[0]; //присваиваем символ из строки SimvolCountOutput в переменную символ SimvolCount
        //проверка№1 было ли прошлое число двухзначным(или больше):
        if (SimvolCount >= '0' and SimvolCount <= '9' and ProverkaNumbers == 1) { //условие, если SimvolCount является цифрой и ProverkaNumbers равняется одному, то..
            ProverkaNumbers = 0; //..то ProverkaNumbers приравнивается нулю
            continue; //цикл начинает работать сначала, при этом к i прибавляется 1, а не обнуляется
        }
        //защита - является ли первый символ в файле цифрой:
        if (SimvolCount >= '0' and SimvolCount <= '9' and i == 0) { //условие, если SimvolCount является цифрой и i равняется 0, то..
            cout << "Ошибка. Первый символ в файле - цифра. Такого не может быть.";
            return; //закончить работу функции
        }
        if (SimvolCount >= '0' and SimvolCount <= '9') { //условие, если SimvolCount является цифрой
            StringNumbersLetter += SimvolCountOutput; //добавляем к строке StringNumbersLetter строку SimvolCountOutput, состоящую из одного символа
            SimvolCountOutput.replace(0, 2, CountOutput, i + 1, 1); //заменяем символы в строке SimvolCountOutput на следующий символ (i+1) из строки CountOutput
            SimvolCount = SimvolCountOutput[0]; //присваиваем символ из строки SimvolCountOutput в переменную символ SimvolCount
            //проврка№2 является ли число двухзначным(или больше):
            for (int j = 1; SimvolCount >= '0' and SimvolCount <= '9'; j++) { //цикл, повторяющийся пока SimvolCount является числом
                ProverkaNumbers = 1; //приравниваем число ProverkaNumbers одному для проверки№1
                StringNumbersLetter += SimvolCountOutput; //добавляем к строке StringNumbersLetter строку SimvolCountOutput, состоящую из одного символа
                SimvolCountOutput.replace(0, 2, CountOutput, i + 2, 1); //заменяем символы в строке SimvolCountOutput на следующий символ (i+1) из строки CountOutput
                SimvolCount = SimvolCountOutput[0]; //присваиваем символ из строки SimvolCountOutput в переменную символ SimvolCount
            }
            //защита - если произошло исключение и в строке StringNumbersLetter есть символы, кроме цифр
            if (StringNumbersLetter.find_last_not_of("123456780") != -1) { //условие, если в строке StringNumbersLetter есть символы, кроме цифр
                cout << "Ошибка деархивации";
                return; //закончить работу функции
            }
            NumbersLetter = stoi(StringNumbersLetter); //переводим строку StringNumbersLetter в число NumbersLetter
            for (int j = 1; j < NumbersLetter; j++) { //цикл, повторяющийся NumbersLetter-раз
                Dearchive += CountOutput[i - 1]; //в строку Dearchive вставляем символ, который был до числа
            }
            StringNumbersLetter.clear(); //очищаем строку StringNumbersLetter
        }
        else { //иначе..
            Dearchive += SimvolCountOutput; //добавляем символ (по счётчику i) из строки SimvolCountOutput в строку Dearchive
        }
    }
    cout << "Итог:" << Dearchive;
    ofstream Write("output.txt", ios::trunc); //создаём поток файла + открываем файл output.txt для перезаписывания данных 
    //защита - на открытие файла:
    if (!Write.is_open()) { //условие, если файл не открылся, то..
        cout << "Ошибка открытия файла. Возможно его не существует.";
        return; //..завершения работы функции
    }
    Write << Dearchive; //запись строки Dearchive в файл output.txt
    Write.close(); //закрываем файла
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Dearchive();
}
