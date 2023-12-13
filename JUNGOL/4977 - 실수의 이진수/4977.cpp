#include <iostream>
#include <stack>
using namespace std;

int main() {
    float num;
    cin >> num;
    int integer = (int)num;
    float decimal = num-integer;

    stack<int> s;
    do {
        s.push(integer%2);
        integer = integer/2;
    } while(integer);

    int len = s.size();
    for(int i = 0; i < len; i++) {
        cout << s.top();
        s.pop();
    }
    cout << ".";

    for(int i = 0; i < 4; i++) {
        if(decimal*2 >= 1) {
            cout << 1;
            decimal = decimal*2-1;
        }
        else {
            cout << 0;
            decimal = decimal*2;
        }
    }
}