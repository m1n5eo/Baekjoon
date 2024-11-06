#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555555

int m, q, n, x, result, cnt, temp;
vector<int> f(1, 0);
vector<vector<int>> sqarseTable((int)(log(MAX)/log(2))+1, vector<int>(MAX, 0));

int main() {
    FASTIO

    cin >> m;

    for(int i = 1; i <= m; i++) {
        cin >> temp;
        f.push_back(temp);
    }

    for(int i = 0; i <= (int)(log(MAX)/log(2)); i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 0) sqarseTable[i][j] = f[j];
            else sqarseTable[i][j] = sqarseTable[i-1][sqarseTable[i-1][j]];
        }
    }

    cin >> q;

    for(int _ = 0; _ < q; _++) {
        cin >> n >> x;

        result = x;
        cnt = 0;

        while(n) {
            if(n%2 == 1) {
                result = sqarseTable[cnt][result];
            }

            n /= 2;
            cnt += 1;
        }

        cout << result << " ";
    }
}