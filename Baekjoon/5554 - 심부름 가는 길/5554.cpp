#include <bits/stdc++.h>
using namespace std;

int main() {
    int sec, sum = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &sec);
        sum += sec;
    }
    printf("%d\n%d", sum/60, sum%60);
}
