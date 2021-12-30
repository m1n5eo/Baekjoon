#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, car, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &car);
        if(car == n) cnt++;
    }
    printf("%d", cnt);
}
