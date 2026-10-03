#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    string a, b, temp;
    map<string,string> site;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        site[a] = b;
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        cout << site[temp] << "\n";
    }
}