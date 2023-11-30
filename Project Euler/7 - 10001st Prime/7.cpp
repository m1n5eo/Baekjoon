#include <iostream>
using namespace std;

bool arr[11111111] = {true, true, };

int main() {
    for(int i = 2; i < 11111111; i++) {
        if(arr[i] == false) {
            for(int j = i*2; j < 11111111; j+=i) {
                arr[j] = true;
            }
        }
    }
    int i, cnt = 0;
    for(i = 1; cnt < 10001; i++) {
        if(arr[i] == false) cnt++;
    }
    cout << i-1;
}