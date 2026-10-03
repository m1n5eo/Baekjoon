#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int main() {
    FASTIO

    int t;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int n, m, result = 0, block[MAX][MAX];
        string b;

        cin >> n >> m;

        for(int i = 0; i < n+2; i++) {
            block[i][0] = 0;
            block[i][m+1] = 0;
        }

        for(int j = 0; j < m+2; j++) {
            block[0][j] = 0;
            block[n+1][j] = 0;
        }

        for(int i = 1; i <= n; i++) {
            cin >> b;

            for(int j = 0; j < m; j++) {
                block[i][j+1] = b[j]-'0';
            }
        }
        
        for(int i = 0; i < n+2; i++) {
            for(int j = 0; j < m+2; j++) {
                if(i+1 < n+2) result += abs(block[i][j]-block[i+1][j]);
                if(j+1 < m+2) result += abs(block[i][j]-block[i][j+1]);
                if(block[i][j] != 0) result += 2;
            }
        }

        cout << result << "\n";
    }
}