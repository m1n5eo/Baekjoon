#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q, res;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k-1; j++) {
            q.push(q.front());
            q.pop();
        }

        res.push(q.front());
        q.pop();
    }

    cout << "<";
    for(int i = 0; i < n-1; i++) {
        cout << res.front() << ", ";
        res.pop();
    }
    cout << res.front() << ">";

    return 0;
}