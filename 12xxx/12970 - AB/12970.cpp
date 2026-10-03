#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, k;
    string result = "";

    cin >> n >> k;

    int last = n%2 == 0? (n/2)*(n/2) : (n/2)*(n/2+1);

    if(last < k) {
        cout << -1;
        exit(0);
    }

    while(result.size() < n) {
        result += "B";
    }

    int cnt = 1, now = n-1;

    for(int i = 1; i <= k; i++) {
        if(now > 0 && result[now-1] == 'B') {
            result[now-1] = 'A';
            result[now] = 'B';
        }
        else {
            cnt += 1;
            now = n-cnt;

            result[now-1] = 'A';
        }

        now -= 1;
    }

    cout << result;
}