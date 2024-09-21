#include <iostream>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n, cnt = 0;
    string game, name;
    map<string, bool> m;

    cin >> n >> game;

    for(int _ = 0; _ < n; _++) {
        string temp;

        cin >> temp;

        if(m.find(temp) == m.end()) {
            m.insert({temp, true});
            cnt += 1;
        }
    }

    if(game == "Y") cout << cnt/1;
    else if(game == "F") cout << cnt/2;
    else if(game == "O") cout << cnt/3;
}