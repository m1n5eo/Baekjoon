#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321
#define MAX 1111

int n, m;
lli k = INF, sum, temp;

lli solve() {
    if(k == 0) return sum;
    else return sum-k;
}

int main() {
    FASTIO

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> temp;
            sum += temp;
            k = min(k, temp);
        }
    }

    cout << solve();
}