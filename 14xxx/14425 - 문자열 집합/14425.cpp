#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, k, result;
map<string, bool> m;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        m.insert({str, true});
    }
    for(int i =  0; i < k; i++) {
        string str;
        cin >> str;

        if(m.find(str) != m.end()) result += 1;
    }

    cout << result;
}