#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, k, cnt = 0, x = 0, y = 0;
    string s;

    cin >> n >> k;
    cin >> s;

    for(int _ = 0; _ < k && cnt < 2000; _++) {
        cnt += 1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'U') x += 1;
            else if(s[i] == 'D') x -= 1;
            else if(s[i] == 'L') y += 1;
            else if(s[i] == 'R') y -= 1;

            if(x == 0 && y == 0) {
                cout << "YES";
                exit(0);
            }
        }
    }

    cout << "NO";
}