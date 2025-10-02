#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int n, k;
vector<string> word(MAX, "");
vector<bool> check(26, false);
vector<set<char>> have(MAX);
set<char> temp;
vector<char> appear;

int backtracking(int idx, vector<int> now) {
    int ret = 0;
    if(idx == appear.size() || k == now.size()) {
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(char h : have[i]) {
                if(check[h-'a']) cnt += 1;
                else break;
            }
            if(cnt == have[i].size()) ret += 1;
        }
    }
    else {
        for(int i = idx; i < appear.size(); i++) {
            if(check[appear[i]-'a'] == false) {
                now.push_back(i);
                check[appear[i]-'a'] = true;
                ret = max(ret, backtracking(i+1, now));
                now.pop_back();
                check[appear[i]-'a'] = false;
            }
        }
    }
    return ret;
}

int solve() {
    int ret = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> word[i];
    if(k < 5) return 0;
    for(int i = 0; i < n; i++) {
        for(char w : word[i]) {
            if(!(w == 'a' || w == 'c' || w == 'i' || w == 'n' || w == 't')) {
                have[i].insert(w);
                temp.insert(w);
            }
        }
        if(have[i].size() == 0) ret += 1;
    }
    for(char t : temp) appear.push_back(t);

    k -= 5;
    if(appear.size() <= k) ret = n;
    return max(ret, backtracking(0, {}));
}

int main() {
    FASTIO
    cout << solve();
}