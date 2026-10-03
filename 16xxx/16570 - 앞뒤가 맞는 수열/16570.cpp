#include <iostream>
using namespace std;

#define MAX 1111111

int n, j, arr[MAX], failure[MAX];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = n-1; i >= 0; i--) {
        cin >> arr[i];
    }

    failure[0] = -1;
    for(int i = 1; i < n; i++) {
        j = failure[i-1];

        while(arr[i] != arr[j+1] && j >= 0) j = failure[j];

        if(arr[i] == arr[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    int max_len = 0, cnt = 0;
    
    for(int i = 0; i < n; i++) {
        if(max_len == failure[i]+1) {
            cnt += 1;
        }
        else if(max_len < failure[i]+1) {
            max_len = failure[i]+1;
            cnt = 1;
        }
    }

    if(max_len == 0) cout << -1;
    else cout << max_len << " " << cnt;
}