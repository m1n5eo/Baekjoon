#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
	cin.sync_with_stdio(false);

    int n, k;
    string str;
    queue <int> q;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "push") {
            cin >> k;
            q.push(k);
        }
        else if(str == "size") cout << q.size() << "\n";
        else if(str == "empty") cout << q.empty() << "\n";
        else if(str == "pop") {
            if(q.size() == 0) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(str == "front") {
            if(q.size() == 0) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(str == "back") {
            if(q.size() == 0) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
}