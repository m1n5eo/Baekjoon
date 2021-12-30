#include <bits/stdc++.h>
using namespace std;

int main() {
    int score, sum = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &score);
        sum += score;
    }
    printf("%d", sum);
}
