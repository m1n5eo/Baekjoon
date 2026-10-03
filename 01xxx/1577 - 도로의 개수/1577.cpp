#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct coordinate {
    int x1, y1, x2, y2;
};

int main() {
    FASTIO

    int n, m, k;

    cin >> n >> m;
    cin >> k;

    int a, b, c, d;
    vector<vector<lli>> route(n+1, vector<lli>(m+1, 0));
    vector<vector<vector<bool>>> check(n+1, vector<vector<bool>>(m+1, vector<bool>(2, false)));

    for(int _ = 0; _ < k; _++) {
        coordinate in;
        cin >> in.x1 >> in.y1 >> in.x2 >> in.y2;

        if(in.x1 > in.x2 || in.y1 > in.y2) {
            swap(in.x1, in.x2);
            swap(in.y1, in.y2);
        }

        if(in.x1 == in.x2) check[in.x1][in.y1][0] = true;
        else if(in.y1 == in.y2) check[in.x1][in.y1][1] = true;
    }

    route[0][0] = 1;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(j+1 <= m && check[i][j][0] == false) route[i][j+1] += route[i][j];
            if(i+1 <= n && check[i][j][1] == false) route[i+1][j] += route[i][j];
        }
    }
    
    cout << route[n][m];
}