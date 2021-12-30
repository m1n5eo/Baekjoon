#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}

int main() {
    int n;
    string word[20001];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> word[i];
    sort(word, word+n, compare);
    for(int i = 0; i < n; i++) {
        if(i && word[i] == word[i-1]) continue;
        cout << word[i] << "\n";
    }
}