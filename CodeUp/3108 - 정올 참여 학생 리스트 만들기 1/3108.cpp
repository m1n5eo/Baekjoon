#include <bits/stdc++.h>
using namespace std;

struct data {
    char code;
    int num;
    char name[44];
};

bool compare(const data& a, const data& b) {
    return a.num < b.num;
}

int main() {
    int n, k, cnt = 1, check[10001];
    struct data arr[10001];
    struct data dap[10001];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %c %d %s", &arr[i].code, &arr[i].num, arr[i].name);
        if(arr[i].code == 'I' && check[arr[i].num] == 0) {
            dap[cnt] = arr[i];
            check[arr[i].num] = cnt;
            cnt++;
        }
        else if(arr[i].code == 'D' && check[arr[i].num]) {
            dap[check[arr[i].num]].num += 20000;
            check[arr[i].num] = 0;
        }
    }
    sort(dap, dap+cnt, compare);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &k);
        printf("%d %s\n", dap[k].num, dap[k].name);
    }
}