#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    string str;

    cin >> str;

    int n = str.size(), cnt = 0;
    bool mode = true;

    for(int i = 0; i < n-1; i++) {
        if(str[i] != str[i+1] && mode == true) {
            cnt += 1;
            mode = false;
        }
        else if(str[i] != str[i+1] && mode == false) {
            mode = true;
        }
    }

    cout << cnt;
}