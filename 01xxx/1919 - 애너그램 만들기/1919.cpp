#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int cnt1[33] = {0, }, cnt2[33] = {0, };
    string str1, str2;

    cin >> str1 >> str2;

    int len1 = str1.length(), len2 = str2.length();

    for(int i = 0; i < len1; i++) cnt1[str1[i]-'a'] += 1;
    for(int i = 0; i < len2; i++) cnt2[str2[i]-'a'] += 1;

    int res = 0;

    for(int i = 'a'-'a'; i <= 'z'-'a'; i++) {
        res += abs(cnt1[i]-cnt2[i]);
    }

    cout << res;

    return 0;
}