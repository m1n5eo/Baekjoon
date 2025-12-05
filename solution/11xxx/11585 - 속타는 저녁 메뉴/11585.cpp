#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

string solve() {
    int n;
    cin >> n;
    vector<char> word;
    for(int i = 0; i < n; i++) {
        char temp; cin >> temp;
        word.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        char temp; cin >> temp;
    }

    vector<int> failure(n, 0);
    failure[0] = -1;
    for(int i = 1; i < n; i++) {
        int j = failure[i-1];
        while(word[i] != word[j+1] && j >= 0) j = failure[j];
        if(word[i] == word[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    int a = failure.back()+1;
    int b = n-a;
    if(a == 0 || a%b != 0) return "1/" + to_string(n);
    else {
        int c = n/b, d = n;
        int k = gcd(c, d);
        c /= k, d /= k;
        return to_string(c) + "/" + to_string(d);
    }
}

int main() {
    // FASTIO
    cout << solve();
}