#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int n, operation[4], minResult = INF, maxResult = -INF;
vector<int> v;

void backtracking(int idx, int sum) {
    if(idx == n-1) {
        minResult = min(minResult, sum);
        maxResult = max(maxResult, sum);

        return;
    }

    for(int i = 0; i < 4; i++) {
        if(operation[i] != 0) {
            if(i == 0) {
                operation[i] -= 1;
                backtracking(idx+1, sum+v[idx+1]);
                operation[i] += 1;
            }
            if(i == 1) {
                operation[i] -= 1;
                backtracking(idx+1, sum-v[idx+1]);
                operation[i] += 1;
            }
            if(i == 2) {
                operation[i] -= 1;
                backtracking(idx+1, sum*v[idx+1]);
                operation[i] += 1;
            }
            if(i == 3) {
                operation[i] -= 1;
                backtracking(idx+1, sum/v[idx+1]);
                operation[i] += 1;
            }
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    for(int i = 0; i < 4; i++) {
        cin >> operation[i];
    }

    backtracking(0, v[0]);

    cout << maxResult << "\n" << minResult;
}