#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        int res = 0;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> matrix[i][j];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) continue;
                else if(i == 0 || j == 0) matrix[i][j] = 1;
                else if(matrix[i-1][j-1] != 0 && matrix[i-1][j] != 0 && matrix[i][j-1] != 0) matrix[i][j] = min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]}) + 1;
                res = max(res, matrix[i][j]);
            }
        }
        cout << res << "\n";
    }
}