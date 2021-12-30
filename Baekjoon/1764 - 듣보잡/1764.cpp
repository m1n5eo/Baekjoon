#include <bits/stdc++.h>
using namespace std;

struct dataset {
    string name;
    int sw;
};

int n, m, cnt;
string print[1111111];
struct dataset arr[1111111];

bool compare(dataset a, dataset b) {
    if(a.name != b.name) return a.name < b.name;
    else return a.sw < b.sw;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].name;
        arr[i].sw = 0;
    }
    for(int i = n; i < n+m; i++) {
        cin >> arr[i].name;
        arr[i].sw = 1;
    }
    sort(arr, arr+n+m, compare);

    for(int i = 0; i < n+m; i++) {
        if(arr[i].name == arr[i+1].name && arr[i].sw != arr[i+1].sw) print[cnt++] = arr[i].name;
    }
    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++) cout << print[i] << "\n";
}