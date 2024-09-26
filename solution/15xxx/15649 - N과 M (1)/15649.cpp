#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

int n, m;
vector<int> v(MAX, 0);
vector<bool> check(MAX, 0);

void backtracking(int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(check[i] == false) {
            check[i] = true;
            v[idx] = i;
            
            backtracking(idx+1);

            check[i] = false;
        }
    }
}

int main() {
    FASTIO

    cin >> n >> m;

    backtracking(0);
}