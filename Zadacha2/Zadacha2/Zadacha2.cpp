#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <Windows.h>
using namespace std;

int prior(char x) {
    if (x == '/' or x == '*') { return 2; }
    if (x == '-' or x == '+') { return 1; }
    if (x == '(' or x == ')') { return 0; }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    stack <char> steck;
    queue <char> queue;
    string inputString = "5*6";
    string x;
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] >= 0 or inputString[i] <= 9) { queue.push(inputString[i]); }
        if (prior(inputString[i]) > 0) {
            if (steck.empty() or steck.top() == '(' or (prior(steck.top()) < prior(inputString[i]))) { steck.push(inputString[i]); }
            else { 
                while ((prior(inputString[i])) >= prior(steck.top())) {
                    queue.push(steck.top());
                    steck.pop();
                }
                steck.push(inputString[i]);
            }
        }
        if (inputString[i] == '(') { steck.push(inputString[i]); }
        if (inputString[i] == ')') { 
            while (steck.top() != '(') {
                queue.push(steck.top());
                steck.pop();
            }
            steck.pop();
        }
        cout << "Итерация = " << i << "        В стеке = " << steck.top() << "        В очереди = " << queue.back() << endl;
    }
    while (!steck.empty()) {
        queue.push(steck.top());
        steck.pop();
    }
    while (!queue.empty()) {
        cout << queue.back();
        queue.pop();
    }
}
