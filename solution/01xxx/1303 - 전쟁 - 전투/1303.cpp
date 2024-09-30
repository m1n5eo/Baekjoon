#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int n, m;
char a;
vector<vector<int>> v(MAX, vector<int>(MAX, 0));

void dfs(int i, int j, int cnt, int k) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(v[i][j] != k) return;

    v[i][j] = cnt;

    dfs(i-1, j, cnt, k);
    dfs(i+1, j, cnt, k);
    dfs(i, j-1, cnt, k);
    dfs(i, j+1, cnt, k);
}

int main() {
    FASTIO

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a;

            if(a == 'W') v[i][j] = 0;
            else if(a == 'B') v[i][j] = 1;
        }
    }

    int cnt1 = 2;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 0) {
                dfs(i, j, cnt1, 0);
                cnt1 += 1;
            }
        }
    }

    int cnt2 = cnt1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 1) {
                dfs(i, j, cnt2, 1);
                cnt2 += 1;
            }
        }
    }

    int WhHap = 0, BlHap = 0, WhCnt, BlCnt;

    for(int k = 2; k < cnt1; k++) {
        WhCnt = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == k) {
                    WhCnt += 1;
                }
            }
        }

        WhHap += WhCnt*WhCnt;
    }

    for(int k = cnt1; k <= cnt2; k++) {
        BlCnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == k) {
                    BlCnt += 1;
                }
            }
        }

        BlHap += BlCnt*BlCnt;
    }

    cout << WhHap << " " << BlHap;
}
