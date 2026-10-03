#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555

int main() {
    FASTIO
    
    int n, m, a, b, t;
    vector<vector<int>> time(MAX, vector<int>(MAX, 0));

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> time[i][j];
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(!(i == j || j == k || k == i)) {
                    time[i][j] = min(time[i][k] + time[k][j], time[i][j]);
                }
            }
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;

        if(time[a][b] > t) cout << "Stay here" << "\n";
        else cout << "Enjoy other party" << "\n";
    }
}