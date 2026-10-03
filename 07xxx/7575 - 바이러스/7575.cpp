#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool Find(vector<int> now, vector<int> cmp, vector<int> fail) {
    int i = 0, j = 0;
    int n = now.size(), m = cmp.size();
    while(i < n && j < m) {
        if(now[i] == cmp[j]) {
            i += 1;
            j += 1;
        }
        else if(j == 0) i += 1;
        else j = fail[j-1]+1;
        if(j == m) return true;
    }
    return false;
}

vector<int> failure(vector<int> vec) {
    int n = vec.size(), j;
    vector<int> ret(n, 0);
    ret[0] = -1;
    for(int i = 1; i < n; i++) {
        j = ret[i-1];
        while(vec[i] != vec[j+1] && j >= 0) j = ret[j];
        if(vec[i] == vec[j+1]) ret[i] = j+1;
        else ret[i] = -1;
    }
    return ret;
}

string solve() {
    int n, m;
    vector<int> length;
    vector<vector<int>> virus;
    cin >> n >> m;
    for(int i = 0; i < n*2; i+=2) {
        int temp; cin >> temp;
        length.push_back(temp);
        virus.push_back(vector<int>(length.back(), 0));
        virus.push_back(vector<int>(length.back(), 0));
        for(int j = 0; j < length.back(); j++) {
            cin >> temp;
            virus[i][j] = temp;
            virus[i+1][length.back()-j-1] = temp;
        }
    }

    for(int idx = 0; idx <= length[0]-m; idx++) {
        vector<int> now, reversed;
        for(int i = idx; i < idx+m; i++) now.push_back(virus[0][i]);
        for(int i = idx+m-1; i >= idx; i--) reversed.push_back(virus[0][i]);
        for(int i = 2; i < n*2; i+=2) {
            vector<int> fn = failure(now), fr = failure(reversed);
            if(Find(virus[i], now, fn) || Find(virus[i], reversed, fr) || Find(virus[i+1], now, fn) || Find(virus[i+1], reversed, fr)) {
                if(i+1 == n*2-1) return "YES";
                else continue;
            }
            else break;
        }
    }
    return "NO";
}

int main() {
    FASTIO
    cout << solve();
}