#include <bits/stdc++.h>
using namespace std;

struct datainfo {
    int age, idx;
    char name[111];
};

bool compare(datainfo &a, datainfo &b) {
    if(a.age != b.age) return a.age < b.age;
    else return a.idx < b.idx;
}

struct datainfo arr[100001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].idx = i;
    }
    sort(arr, arr+n, compare);
    for(int i = 0; i < n; i++) printf("%d %s\n", arr[i].age, arr[i].name);
}
