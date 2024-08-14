#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define psi pair<string, int>

int n, k;
map<string, int> m;

bool compare(psi a, psi b) {
    if(a.second != b.second) return a.second > b.second;
    else if(a.first.length() != b.first.length()) return a.first.length() > b.first.length();
    else return a.first < b.first;
}

int main() {
    FASTIO
    
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if(word.length() < k) continue;

        if(m.find(word) != m.end()) m[word] += 1;
        else m.insert({word, 1});
    }

    vector<psi> v(m.begin(), m.end());

    sort(v.begin(), v.end(), compare);

    for(auto iter : v) {
        cout << iter.first << "\n";
    }
}