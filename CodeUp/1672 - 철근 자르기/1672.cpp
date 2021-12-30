#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, cnt = 1;
    scanf("%d %d", &n, &k);
    if(n/k > 9999) printf("번호 초과 오류");
    for(int i = 0; i < n/k && n/k < 10000; i++) printf("F-%04d\n", i+1);
}