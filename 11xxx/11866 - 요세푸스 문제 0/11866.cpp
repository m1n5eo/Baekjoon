#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n, k, temp;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) q.push(i);
    cout << "<";
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k-1; j++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front();
        if(i != n) cout << ", ";
        q.pop();
    }
    cout << ">";
}
