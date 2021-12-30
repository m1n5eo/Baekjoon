#include <bits/stdc++.h>
using namespace std;

int n, temp;
stack<int> s;
vector<int> v;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> print(n, -1);

    for(int i = 0; i < n; i++) {
        while(s.size() && v[s.top()] < v[i]) {
            print[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++) cout << print[i] << " ";
    cout << endl;
}