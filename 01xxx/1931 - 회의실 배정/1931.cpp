#include <bits/stdc++.h>
using namespace std;

struct dataSet {
    int startTime, endTime;
};

struct dataSet arr[100001];
int n, cnt = 0, save = -1234567890;

bool compare(dataSet& a, dataSet& b) {
    if(a.endTime != b.endTime) return a.endTime < b.endTime;
    else return a.startTime < b.startTime;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].startTime >> arr[i].endTime;
    sort(arr, arr+n, compare);
    // for(int i = 0; i < n; i++) printf("%d %d\n", arr[i].startTime, arr[i].endTime);
    for(int i = 0; i < n; i++) {
        if(save <= arr[i].startTime) {
            save = arr[i].endTime;
            cnt++;
        }
    }
    cout << cnt;
}