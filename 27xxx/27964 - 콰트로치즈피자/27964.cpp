#include <iostream>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, cnt = 0;
    string toping;
    map<string, bool> m;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> toping;

        string cheese = toping;
        cheese.erase(0, cheese.size()-6);
        
        if(cheese == "Cheese" && m.find(toping) == m.end()) {
            m.insert({toping, true});
            cnt += 1;
        }
    }
    
    if(cnt >= 4) cout << "yummy";
    else cout << "sad";
}