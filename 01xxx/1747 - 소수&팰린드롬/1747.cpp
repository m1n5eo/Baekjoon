#include <bits/stdc++.h>
using namespace std;

int n;
int prime[2000001] = {2, 2, }; // 1은 소수 2는 소수아님
int palindrome[1111], palindromeCnt[1111]; // 1은 팰린드롬수 0은 팰린드롬수아님

int reverseNum(int num) {
    int rtn = 0;
    while(num) {
        rtn = rtn*10;
        rtn = rtn+(num%10);
        num = num/10;
    }
    return rtn;
}

void settings() {
    for(int i = 2; i < 2000000; i++) {
        if(prime[i] == 0) {
            prime[i] = 1;
            for(int j = i+i; j < 2000000; j+=i) prime[j] = 2;
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    settings();

    cin >> n;
    for(int i = n; ; i++) {
        if(prime[i] == 1 && reverseNum(i) == i) {
            cout << i;
            break;
        }
    }
}