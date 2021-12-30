#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, a[101], b[101], dg_a, dg_b, sum = 0;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for(int i = 0; i < k; i++) scanf("%d %d", &a[i], &b[i]);
    scanf("%d %d", &dg_a, &dg_b);

    for(int i = 0; i < k; i++) {
        if(a[i] == dg_a) { /// 11 22 33 44
            sum = sum + abs(dg_b-b[i]);
        }
        else if(a[i] == 1) {
            if(dg_a == 3) {
                sum = sum + abs(dg_b-0) + abs(b[i]-0);
            }
            else if(dg_a == 4) {
                sum = sum + abs(dg_b-0) + abs(b[i]-n);
            }
            else if(dg_a == 2) {
                sum = sum + min(abs(b[i]-0) + abs(dg_b-0) + m, abs(b[i]-n) + abs(dg_b-n) + m);
            }
        }
        else if(a[i] == 2) {
            if(dg_a == 3) {
                sum = sum + abs(dg_b-m) + abs(b[i]-0);
            }
            else if(dg_a == 4) {
                sum = sum + abs(dg_b-m) + abs(b[i]-n);
            }
            else if(dg_a == 1) {
                sum = sum + min(abs(b[i]-0) + abs(dg_b-0) + m, abs(b[i]-n) + abs(dg_b-n) + m);
            }
        }
        else if(a[i] == 3) {
            if(dg_a == 1) {
                sum = sum + abs(dg_b-0) + abs(b[i]-0);
            }
            else if(dg_a == 2) {
                sum = sum + abs(dg_b-0) + abs(b[i]-m);
            }
            else if(dg_a == 4) {
                sum = sum + min(abs(b[i]-0) + abs(dg_b-0) + n, abs(b[i]-m) + abs(dg_b-m) + n);
            }
        }
        else if(a[i] == 4) {
            if(dg_a == 1) {
                sum = sum + abs(dg_b-n) + abs(b[i]-0);
            }
            else if(dg_a == 2) {
                sum = sum + abs(dg_b-n) + abs(b[i]-m);
            }
            else if(dg_a == 3) {
                sum = sum + min(abs(b[i]-0) + abs(dg_b-0) + n, abs(b[i]-m) + abs(dg_b-m) + n);
            }
        }
    }
    printf("%d ", sum);
}