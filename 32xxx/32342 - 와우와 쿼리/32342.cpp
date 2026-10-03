#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int t;
    cin >> t;

    for(int _ = 0; _ < t; _++) {
        string str;
        cin >> str;

        int str_size = str.size(), cnt = 0;

        for(int i = 0; i < str_size-2; i++) {
            if(str[i] == 'W' && str[i+1] == 'O' && str[i+2] == 'W') {
                cnt += 1;
            }
        }

        cout << cnt << "\n";
    }
}