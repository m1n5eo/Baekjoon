#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> make_failure(vector<int> word) {
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

vector<int> caesar(vector<int> init, int x, int mod) {
    vector<int> ret;
    int n = init.size();
    for(int i = 0; i < n; i++) ret.push_back((init[i]+x)%mod);
    return ret;
}

vector<int> solve() {
    string ta, tw, ts;
    map<char, int> dict;
    vector<int> w, s;
    cin >> ta >> tw >> ts;

    int na = ta.size(), nw = tw.size(), ns = ts.size();
    for(int i = 0; i < na; i++) dict[ta[i]] = i;
    for(int i = 0; i < nw; i++) w.push_back(dict[tw[i]]);
    for(int i = 0; i < ns; i++) s.push_back(dict[ts[i]]);

    vector<int> ret;
    for(int x = 0; x < na; x++) {
        vector<int> cipher = caesar(w, x, na);
        vector<int> failure = make_failure(cipher);
        int i = 0, j = 0, count = 0;
        while(i < ns && j < nw) {
            if(s[i] == cipher[j]) {
                i += 1;
                j += 1;
            }
            else if(j == 0) i += 1;
            else j = failure[j-1]+1;
            if(j == nw) {
                count += 1;
                j = failure[j-1]+1;
            }
        }
        if(count == 1) ret.push_back(x);
    }
    return ret;
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) {
        vector<int> sol = solve();
        if(sol.size() == 0) cout << "no solution" << "\n";
        else if(sol.size() == 1) cout << "unique: " << sol[0] << "\n";
        else {
            cout << "ambiguous: ";
            for(int s : sol) cout << s << " ";
            cout << "\n";
        }
    }
}