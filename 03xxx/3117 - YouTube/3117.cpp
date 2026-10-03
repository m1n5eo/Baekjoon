#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX_M 1111111111
#define MAX_NK 111111

int n, k, m, result, cnt, t, temp;
vector<int> video, recommend(1, 0);
vector<vector<int>> sparseTable((int)(log(MAX_M)/log(2))+1, vector<int>(MAX_NK, 0));

int main() {
    FASTIO

    cin >> n >> k >> m;

    for(int _ = 0; _ < n; _++) {
        cin >> temp;
        video.push_back(temp);
    }

    for(int i = 1; i <= k; i++) {
        cin >> temp;
        recommend.push_back(temp);
    }

    for(int i = 0; i <= (int)(log(MAX_M)/log(2)); i++) {
        for(int j = 1; j <= k; j++) {
            sparseTable[i][j] = i != 0? sparseTable[i-1][sparseTable[i-1][j]] : recommend[j];
        }
    }

    for(int i = 0; i < n; i++) {
        t = m-1;
        result = video[i];
        cnt = 0;

        while(t) {
            if(t%2 == 1) {
                result = sparseTable[cnt][result];
            }

            t /= 2;
            cnt += 1;
        }

        cout << result << " ";
    }
}