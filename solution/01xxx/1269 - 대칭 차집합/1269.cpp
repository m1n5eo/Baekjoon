#include <iostream>
#include <map>
using namespace std;

int n, k;
map<int, bool> m;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        m.insert({temp, true});
    }

    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;

        if(m.find(temp) != m.end()) m.erase(temp);
        else m.insert({temp, true});
    }

    cout << m.size();
}