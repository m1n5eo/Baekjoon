#include <iostream>
#include <string>
using namespace std;

int main() {
    string str[5];
    int lenMax = 0;
    for(int i = 0; i < 5; i++) {
        cin >> str[i];
        lenMax = max(lenMax, (int)str[i].length());
    }

    for(int i = 0; i < lenMax; i++) {
        for(int j = 0; j < 5; j++) {
            if((int)str[j].length() > i) {
                cout << str[j][i];
            }
        }
    }
}