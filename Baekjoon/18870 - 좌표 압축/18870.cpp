#include <bits/stdc++.h>
using namespace std;

struct dataSet {
    int num, idx, Sort;
};

struct dataSet arr[1000001];
int n, cnt;

bool compare1(dataSet& a, dataSet& b) {
    return a.num < b.num;
}

bool compare2(dataSet& a, dataSet& b) {
    return a.idx < b.idx;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].num;
        arr[i].idx = i;
    }
    sort(arr+1, arr+n+1, compare1);
    arr[0].num = -1234567890, cnt = -1;
    for(int i = 1; i <= n; i++) {
        if(arr[i].num != arr[i-1].num) cnt++;
        arr[i].Sort = cnt;
    }
    sort(arr+1, arr+n+1, compare2);
    for(int i = 1; i <= n; i++) cout << arr[i].Sort << " ";
    cout << endl;
}