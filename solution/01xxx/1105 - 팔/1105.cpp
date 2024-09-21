#include <bits/stdc++.h>
using namespace std;

int main() {
    char n[22], m[22];
    cin >> n >> m;
    if(strlen(n) != strlen(m)) {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < strlen(n); i++) {
        if(n[i] == m[i] && n[i] == '8') cnt++;
        else if(n[i] != m[i]) break;
    }
    cout << cnt;
}