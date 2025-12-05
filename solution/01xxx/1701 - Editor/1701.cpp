#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int make_failure(string word) {
    int n = word.size(), ret = 0;
    vector<int> failure(n, 0);
    failure[0] = -1;
    for(int i = 1; i < n; i++) {
        int j = failure[i-1];
        while(word[i] != word[j+1] && j >= 0) j = failure[j];
        if(word[i] == word[j+1]) {
            failure[i] = j+1;
            ret = max(ret, j+2);
        }
        else {
            failure[i] = -1;
            ret = max(ret, 0);
        }
    }
    return ret;
}

int solve() {
    string word;
    cin >> word;

    string w = "";
    int n = word.size(), ret = 0;
    vector<int> failure;
    for(int i = n-1; i >= 0; i--) {
        w = word[i] + w;
        ret = max(ret, make_failure(w));
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}