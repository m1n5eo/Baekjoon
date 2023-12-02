#include <iostream>
using namespace std;

bool prime[1111111] = {true, true, };

int main() {
    for(int i = 2; i < 1111111; i++) {
        if(prime[i] == false) {
            for(int j = i*2; j < 1111111; j+=i) {
                prime[j] = true;
            }
        }
    }

    int cnt, gop, temp, what = 0;
    for(int i = 1; ; i++) {
        what += i; temp = what; gop = 1;
        for(int j = 2; temp > 1; j++) {
            if(prime[j] == false && what%j == 0) {
                cnt = 0;
                while(temp%j == 0) {
                    temp = temp/j;
                    cnt = cnt+1;
                }
                gop = gop*(cnt+1);
            }
        }
        if(gop >= 500) {
            cout << what << " ";
            break;
        }
    }
}