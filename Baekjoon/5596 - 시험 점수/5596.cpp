#include <bits/stdc++.h>
using namespace std;

int main() {
    int temp, sum[2] = {0, 0};
    for(int i = 0; i < 4; i++) {
        cin >> temp;
        sum[0] += temp;
    }
    for(int i = 0; i < 4; i++) {
        cin >> temp;
        sum[1] += temp;
    }
    printf("%d", max(sum[0], sum[1]));
}