#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 2222

int n, m, k, b0, b1, result = INF;
string str;
vector<vector<int>> black0(MAX, vector<int>(MAX, 0));
vector<vector<int>> black1(MAX, vector<int>(MAX, 0));

int main() {
    FASTIO

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) { // black[i][j][(i+j)%2]
        cin >> str;

        for(int j = 1; j <= m; j++) {
            black0[i][j] = (str[j-1] == 'B' && (i+j)%2 == 0? 1 : 0) + black0[i-1][j] + black0[i][j-1] - black0[i-1][j-1];
            black1[i][j] = (str[j-1] == 'B' && (i+j)%2 == 1? 1 : 0) + black1[i-1][j] + black1[i][j-1] - black1[i-1][j-1];
        }
    }

    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            b0 = black0[i][j] - black0[i-k][j] - black0[i][j-k] + black0[i-k][j-k];
            b1 = black1[i][j] - black1[i-k][j] - black1[i][j-k] + black1[i-k][j-k];

            result = min(result, b0 - b1 + k*k/2 + ((i+j) % 2 == 1 && k%2 == 1? 1 : 0));
            result = min(result, b1 - b0 + k*k/2 + ((i+j) % 2 == 0 && k%2 == 1? 1 : 0));
        }
    }

    cout << result;
}