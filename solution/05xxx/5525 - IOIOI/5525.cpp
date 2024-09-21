#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, len, cnt = -1;
    string str;
    vector<int> v;
    cin >> n >> len >> str;
    for(int i = 0; i < len; i++) {
        if(str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I') {
            if(str[i-2] == 'I' && str[i-1] == 'O') v[cnt]++;
            else {
                v.push_back(1);
                cnt++;
            }
        }
    }
    int print = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i]-n+1 > 0) print += v[i]-n+1;
    }
    printf("%d", print);
}
