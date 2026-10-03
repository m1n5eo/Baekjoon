#include <iostream>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, result, num[4] = {1, 5, 10, 50};
map<int, bool> m;

void backtracking(int idx, int cnt, int now) {
    if(cnt == n) {
        if(m.find(now) == m.end()) {
            m.insert({now, true});
            result += 1;
        }
        return;
    }

    for(int i = idx; i < 4; i++) {
        backtracking(i, cnt+1, now+num[i]);
    }
}

int main() {
    FASTIO

    cin >> n;

    backtracking(0, 0, 0);

    cout << result;
}