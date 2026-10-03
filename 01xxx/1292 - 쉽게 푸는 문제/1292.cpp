#include <iostream>
using namespace std;

int main() {
    int cnt = 1, idx = 1, arr[1111];
    while(true) {
        for(int i = 0; i < cnt; i++) {
            arr[idx] = cnt;
            idx += 1;
            if(idx > 1100) {
                break;
            }
        }
        if(idx > 1100) {
            break;
        }
        cnt += 1;
    }

    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = n; i <= m; i++) {
        sum += arr[i];
    }
    cout << sum;
}