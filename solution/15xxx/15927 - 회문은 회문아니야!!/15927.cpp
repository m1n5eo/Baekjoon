#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    string str;
    cin >> str;
    int count = 0;
    int left = 0, right = str.size()-1;
    while(left <= right) {
        if(str[left] != str[right]) return str.size();
        if(str[0] == str[left]) count += 1;
        if(str[0] == str[right]) count += 1;
        left += 1;
        right -= 1;
    }
    if(count > str.size()) count = str.size();
    if(count == str.size()) return -1;
    else return str.size()-1;
}

int main() {
    FASTIO
    cout << solve();
}