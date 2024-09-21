#include <bits/stdc++.h>
using namespace std;

int n, m, b, save, block[255555];
long long int minTime = 1234567890;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d %d %d", &n, &m, &b);
    n = n*m;
    for(int i = 0; i < n; i++) scanf("%d", &block[i]);
    sort(block, block+n, compare);
    for(int k = 0; k <= 256; k++) {
        int temp = b;
        long long int Time = 0;
        for(int i = 0; i < n; i++) {
            if(block[i] > k) {
                Time += (block[i]-k)*2;
                temp += block[i]-k;
            }
            else if(block[i] < k) {
                if(temp-(k-block[i]) < 0) {
                    Time = 1234567890;
                    break;
                }
                Time += k-block[i];
                temp -= k-block[i];
            }
        }
        if(Time <= minTime) {
            minTime = Time;
            save = k;
        }
    }
    printf("%d %d", minTime, save);
}