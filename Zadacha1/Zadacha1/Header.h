#include <iostream>
#include <string>
#define ch enterStr.find_last_not_of("-0123456789.")
#define ch2 enterStr.find_last_of("-")
#define ch3  enterStr.find_last_of(".")-enterStr.find_first_of(".")
using namespace std;
void debug(string s);
void debug(int x);