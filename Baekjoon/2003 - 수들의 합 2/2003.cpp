#include <iostream>
using namespace std;

#define MAX 10000

int n, m, cnt, sum, s, e, arr[MAX];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(e <= n) {
        if(sum >= m) {
            sum -= arr[s];
            s += 1;
        }
        else if(sum < m) {
            sum += arr[e];
            e += 1;
        }

        if(sum == m) {
            cnt += 1;
        }
    }

    cout << cnt;
}