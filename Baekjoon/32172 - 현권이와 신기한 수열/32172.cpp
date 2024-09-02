#include <iostream>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, before = 0;
    map<int, bool> m;

    m.insert({0, true});
    
    cin >> n;

    for(int i = 1; i <= n; i++) {
        if(before-i < 0 || m.find(before-i) != m.end()) {
            m.insert({before+i, true});
            before = before+i;
        }
        else {
            m.insert({before-i, true});
            before = before-i;
        }
    }

    cout << before;
}