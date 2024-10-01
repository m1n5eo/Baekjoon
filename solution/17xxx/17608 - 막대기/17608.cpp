#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 111111

int main() {
    FASTIO
    
    int n;
    vector<int> v(MAX, 0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int big = -INF, cnt = 0;

    for(int i = n-1; i >= 0; i--) {
        if(big < v[i]) {
            big = v[i];
            cnt += 1;
        }
    }

    cout << cnt;
}