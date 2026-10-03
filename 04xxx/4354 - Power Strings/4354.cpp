#include <iostream>
#include <string>
#include <vector>
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

int solve(string word) {
    vector<int> failure = make_failure(word);
    int a = failure.back()+1; int b = word.size() - a;
    if(a%b == 0) return word.size()/b;
    else return 1;
}

int main() {
    FASTIO
    string word;
    while(cin >> word) {
        if(word == ".") break;
        else cout << solve(word) << "\n";
    }
}