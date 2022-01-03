#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    string str;
    map<string, int> mapset;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str >> k;
        if(!mapset.empty()) mapset[str] += k;
        mapset.insert({str, k});
    }
    for(int i = 0; i < m; i++) {
        cin >> str;
        cout << mapset[str] << "\n";
    }
}