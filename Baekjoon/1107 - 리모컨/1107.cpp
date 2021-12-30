#include <bits/stdc++.h>
using namespace std;

int n, m;
int button[11], possible[12345700];

int func(int num) {
    if(num == 0) return 1;
    int cnt = 0;
    while(num) {
        cnt++;
        num = num/10;
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> button[i];
        possible[button[i]] = 1;
    }
    if(m == 10) {cout << abs(n-100); return 0;}
    else if(n == 100) {cout << 0; return 0;}
    for(int i = 10; i < 12345678; i++) {
        if(possible[i%10] == 1 || possible[i/10] == 1) possible[i] = 1;
        else possible[i] = 0;
    }
    int findChannel = 0, sw = 0, countNum;
    while(1) {
        if(n-findChannel >= 0 && possible[n-findChannel] == 0) {
            sw = 1;
            break;
        }
        else if(possible[n+findChannel] == 0) {
            sw = 2;
            break;
        }
        else findChannel++;
    }
    if(sw == 1) countNum = func(n-findChannel);
    else if(sw == 2) countNum = func(n+findChannel);
    cout << min(abs(n-100), countNum+findChannel);
}