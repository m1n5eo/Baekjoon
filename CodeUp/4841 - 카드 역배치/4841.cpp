#include <bits/stdc++.h>
using namespace std;

int card[22], imsi[22];

int main() {
    int a, b, c;
    for(int i = 1; i <= 20; i++) card[i] = i;
    for(int i = 1; i <= 10; i++) {
        scanf("%d %d", &a, &b);
        c = b-a+1;
        for(int j = 1; j <= c; j++) imsi[j] = card[a+j-1];
        for(int j = 1; j <= c; j++) card[a+j-1] = imsi[c-j+1];
    }
    for(int k = 1; k <= 20; k++) printf("%d ", card[k]);
}