#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, n;
    scanf ("%d", &n);
    int dap[51], kg[51], cm[51];
    for(i = 0; i < n; i++) {
        scanf ("%d %d", &kg[i], &cm[i]);
        dap[i] = 1;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(kg[i] < kg[j] && cm[i] < cm[j]) dap[i]++;
        }
    }

    for(i = 0; i < n; i++) printf ("%d ", dap[i]);
}
