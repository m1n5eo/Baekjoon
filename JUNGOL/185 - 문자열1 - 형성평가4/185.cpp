#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char f;
    cin >> str >> f;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == f) {
            cout << i;
            return 0;
        }
    }
    cout << "No";
}