#include <bits/stdc++.h>
using namespace std;

struct dataa {
    int x, y;
}arr[100001];

bool compare(dataa a, dataa b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
    sort(arr, arr+n, compare);
    for(int i = 0; i < n; i++) printf("%d %d\n", arr[i].x, arr[i].y);
}
