#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222222

string str;
int n, cnt[MAX][33];

int main() {
    FASTIO

    cin >> str;

    int str_size = str.size();

    for(int i = 0; i < str_size; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == 0) cnt[i][j] = 0;
            else cnt[i][j] = cnt[i-1][j];

            if(str[i]-'a' == j) cnt[i][j] += 1;
        }
    }

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        char a;
        int l, r;
        cin >> a >> l >> r;

        if(l == 0) cout << cnt[r][a-'a'] << "\n";
        else cout << cnt[r][a-'a']-cnt[l-1][a-'a'] << "\n";
    }
}