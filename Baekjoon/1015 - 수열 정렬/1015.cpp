#include <bits/stdc++.h>
using namespace std;

int cnt[55];

int main() {
    int n, arr[55];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] > arr[j]) cnt[i]++;
            else if(arr[i] == arr[j] && i > j) cnt[i]++;
        }
    }
    for(int i = 0; i < n; i++) cout << cnt[i] << " ";
}