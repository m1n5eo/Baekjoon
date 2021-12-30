#include <bits/stdc++.h>
using namespace std;

struct data {
    int idx;
    int math, infor;
};

bool compare(const data& a, const data& b) {
    if(a.math != b.math) return a.math > b.math;
    else {
        if(a.infor != b.infor) return a.infor > b.infor;
        else return a.idx < b.idx;
    }
}

int main() {
    struct data arr[1111];

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].math, &arr[i].infor);
        arr[i].idx = i+1;
    }
    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++) {
        printf("%d %d %d\n", arr[i].idx, arr[i].math, arr[i].infor);
    }
}