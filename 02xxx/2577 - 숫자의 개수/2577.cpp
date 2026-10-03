#include <bits/stdc++.h>
using namespace std;

int arr[11];

int main() {
    int a, b, c, sum;
    scanf("%d %d %d", &a, &b, &c);
    sum = a * b * c;

    while(sum) {
        arr[sum%10]++;
        sum = sum / 10;
    }

    for(int i = 0; i < 10; i++) printf("%d\n", arr[i]);
}
