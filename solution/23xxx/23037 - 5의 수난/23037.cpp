#include <bits/stdc++.h>
using namespace std;

int func(int num) {
    int rtn = 1;
    for(int i = 0; i < 5; i++) rtn *= num;
    return rtn;
}

int main() {
    int temp, sum = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%1d", &temp);
        sum += func(temp);
    }
    printf("%d", sum);
}