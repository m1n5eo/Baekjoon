#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> make_failure(string word) {
    int n = word.size();
    vector<int> failure(n, 0);
    failure[0] = -1;
    for(int i = 1; i < n; i++) {
        int j = failure[i-1];
        while(word[i] != word[j+1] && j >= 0) j = failure[j];
        if(word[i] == word[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }
    return failure;
}

vector<int> where(string init, string cmp) {
    int n = init.size(), m = cmp.size();
    vector<int> failure = make_failure(cmp), ret;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(init[i] == cmp[j]) {
            i += 1;
            j += 1;
        }
        else if(j == 0) i += 1;
        else j = failure[j-1]+1;
        if(j == m) {
            ret.push_back(i-m);
            j = failure[j-1]+1;
        }
    }
    return ret;
}

string solve() {
    string word;
    cin >> word;

    string w = word;
    while(true) {
        string next = "";
        vector<int> failure = make_failure(w);
        if(failure.back() == -1) return "-1";
        for(int i = 0; i <= failure.back(); i++) next += w[i];
        vector<int> whr = where(word, next);
        int count = 0, n = word.size(), m = next.size();
        for(int wh : whr) {
            if(wh != 0 && wh != n-m) {
                return next;
            }
        }
        w = next;
    }
}

int main() {
    FASTIO
    cout << solve();
}