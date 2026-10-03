#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    string str;

    cin >> str;

    int n = str.size(), cnt = 0;

    for(int i = 0; i <= n; i++) {
        if(i < n && str[i] == 'X') cnt += 1;
        else if(i == n || str[i] == '.') {
            if(cnt%4 == 0) {
                for(int j = 0; j < cnt; j++) str[i-j-1] = 'A';
            }
            else if(cnt%4 == 2) {
                for(int j = 0; j < 2; j++) str[i-j-1] = 'B';
                for(int j = 2; j < cnt; j++) str[i-j-1] = 'A';
            }
            else {
                cout << -1;
                exit(0);
            }

            cnt = 0;
        }
    }

    cout << str;
}