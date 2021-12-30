#include <bits/stdc++.h>
using namespace std;

int n, arr[22];
int sumMax = -1234567890, sumMin = 1234567890;

void backtracking(int idx, int sum, int plus, int minus, int multiplication, int division) {
    if(plus < 0 || minus < 0 || multiplication < 0 || division < 0) return;
    if(idx == n) {
        sumMax = max(sumMax, sum);
        sumMin = min(sumMin, sum);
        return;
    }
    if(plus > 0) backtracking(idx+1, sum+arr[idx], plus-1, minus, multiplication, division);
    if(minus > 0)backtracking(idx+1, sum-arr[idx], plus, minus-1, multiplication, division);
    if(multiplication > 0) backtracking(idx+1, sum*arr[idx], plus, minus, multiplication-1, division);
    if(division > 0) backtracking(idx+1, sum/arr[idx], plus, minus, multiplication, division-1);
}

int main() {
    int symbol[4];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < 4; i++) scanf("%d", &symbol[i]); // 0.+ 1.- 2.× 3.÷

    backtracking(1, arr[0], symbol[0], symbol[1], symbol[2], symbol[3]);
    printf("%d\n%d", sumMax, sumMin);
}
