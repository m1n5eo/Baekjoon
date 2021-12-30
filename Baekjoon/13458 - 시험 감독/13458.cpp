#include <bits/stdc++.h>
using namespace std;

int testroom, b, c;
int person[1000001];
long long int sum = 0;

int main() {
    scanf("%d", &testroom);
    for(int i = 0; i < testroom; i++) scanf("%d", &person[i]);
    scanf("%d %d", &b, &c);
    for(int i = 0; i < testroom; i++) {
        person[i] = person[i]-b;
        sum++;
        if(person[i] > 0) {
            sum += ((long long int)person[i]-1)/(long long int)c+1;
        }
    }
    printf("%lld", sum);
}
