#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2222

int n, cnt;
map<string, bool> m;

int main() {
    FASTIO
    
    m.insert({"ChongChong", true});

    cin >> n;

    for(int i = 0; i < n; i++) {
        string name1, name2;
        cin >> name1 >> name2;

        if(m.find(name1) == m.end()) m.insert({name1, false});
        if(m.find(name2) == m.end()) m.insert({name2, false});

        if(m[name1] == true || m[name2] == true) {
            m[name1] = true;
            m[name2] = true;
        }
    }

    int result = 0;
    
    for(auto iter : m) {
        if(iter.second == true) result += 1;
    }

    cout << result;
}