#include <iostream>
#include <map>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, cnt;
map<string, bool> m;

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if(temp == "ENTER") {
            m.clear();
        }
        else if(m.find(temp) == m.end()) {
            m.insert({temp, true});
            cnt += 1;
        }
    }

    cout << cnt;
}