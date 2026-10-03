#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char str[55][55], print[55];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> str[i];
    int len = strlen(str[0]);
    for(int i = 0; i < len; i++) {
        int cnt = 0;
        for(int j = 0; j < n-1; j++) {
            if(str[j][i] == str[j+1][i]) cnt++;
        }
        if(cnt == n-1) print[i] = str[0][i];
        else print[i] = '?';
    }
    for(int i = 0; i < len; i++) cout << print[i];
}