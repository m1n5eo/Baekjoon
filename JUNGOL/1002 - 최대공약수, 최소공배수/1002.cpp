#include <iostream>
using namespace std;

int main() {
    int n, res1, res2, arr[11];
    int small = 2100000000, large = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for(int i = small; i >= 1; i--) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j]%i == 0) {
                cnt += 1;
            }
        }
        if(cnt == n) {
            cout << i << " ";
            break;
        }
    }
    for(int i = 1; ; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if((large*i)%arr[j] == 0) {
                cnt += 1;
            }
        }
        if(cnt == n) {
            cout << large*i;
            break;
        }
    }
}