#include <iostream>
using namespace std;

int n, m;
int triangle[33][33];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 1; i <= 30; i++) {
        triangle[i][i] = 1;
        triangle[i][1] = 1;
    }

    for(int i = 2; i <= 30; i++) {
        for(int j = 2; j <= i; j++) {
            triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
        }
    }

    cin >> n >> m;
    cout << triangle[n][m];

    return 0;
}