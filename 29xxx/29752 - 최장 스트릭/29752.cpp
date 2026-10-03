#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0, cntMax = 0, arr[1111];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) {
            if(cntMax < cnt) {
                cntMax = cnt;
            }
            cnt = 0;
        }
        else {
            cnt += 1;
        }
    }

    if(cntMax < cnt) {
        cntMax = cnt;
    }
    cout << cntMax;
}