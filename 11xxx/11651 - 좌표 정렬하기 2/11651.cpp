#include <bits/stdc++.h>
using namespace std;

struct dataxy {
    int x, y;
};

bool compare(dataxy &a, dataxy &b) {
    if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

int main() {
    struct dataxy arr[100001];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
    sort(arr, arr+n, compare);
    for(int i = 0; i < n; i++) printf("%d %d\n", arr[i].x, arr[i].y);
}
