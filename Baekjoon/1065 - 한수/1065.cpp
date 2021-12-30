#include <bits/stdc++.h>
using namespace std;

int arr[1001];

bool HanSu(int num) {
    int imsi = num/10, k = num%10-(num/10)%10;
    while(imsi) {
        int on = imsi%10, tw = (imsi/10)%10;
        if(on-tw != k) {
            return 0;
        }
        imsi /= 10;
        if(imsi/10 == 0) break;
    }
    return 1;
}

int main() {
    for(int i = 1; i <= 99; i++) arr[i] = 1;
    for(int i = 100; i <= 1000; i++) {
        arr[i] = HanSu(i);
    }

    int n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(arr[i] == 1) cnt++;
    }
    cout << cnt;
}