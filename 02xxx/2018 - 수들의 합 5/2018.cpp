#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, start = 1, end = 1, sum = 1, cnt = 0;

    cin >> n;

    while(end <= n) {
        if(sum == n) cnt += 1;
        
        if(sum >= n) {
            sum -= start;
            start += 1;
        }
        else if(sum < n) {
            end += 1;
            sum += end;
        }
    }

    cout << cnt;
}