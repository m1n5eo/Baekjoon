#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

string n;
int n_size, result = INF;

void backtracking(int now, int cnt, vector<int> num, vector<bool> check) {
    if(cnt == n_size) {
        if(stoi(n) < now && result > now) result = now;
        return;
    }

    for(int i = 0; i < n_size; i++) {
        if(check[i] == false) {
            check[i] = true;
            backtracking(now*10 + num[i], cnt+1, num, check);
            check[i] = false;
        }
    }
}

int main() {
    FASTIO
    
    cin >> n;

    n_size = n.size();

    vector<int> num;
    vector<bool> check(n_size, false);

    for(int i = 0; i < n_size; i++) {
        num.push_back(n[i]-'0');
    }

    backtracking(0, 0, num, check);

    if(result != INF) cout << result;
    else cout << 0;
}