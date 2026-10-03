#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

string solve() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++) cin >> vec[i];
    stack<int> st[4];
    for(int i = 0; i < n; i++) {
        int k = -1, comp = -1;
        for(int j = 0; j < 4; j++) {
            if(!st[j].empty() && st[j].top() < vec[i]) {
                if(comp == -1 || comp < st[j].top()) {
                    k = j;
                    comp = st[k].top();
                }
            }
        }
        for(int j = 0; j < 4 && k == -1; j++) {
            if(st[j].empty()) k = j;
        }
        if(k == -1) return "NO";
        else st[k].push(vec[i]);
    }
    return "YES";
}

int main() {
    FASTIO
    cout << solve();
}