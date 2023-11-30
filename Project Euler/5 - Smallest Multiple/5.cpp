#include <iostream>
using namespace std;

int main() {
    for(int i = 21; ; i++) {
        int cnt = 0;
        for(int j = 2; j <= 20; j++) {
            if(i%j == 0) cnt++;
            else break;
        }
        if(cnt == 19) {
            cout << i;
            break;
        }
    }
}