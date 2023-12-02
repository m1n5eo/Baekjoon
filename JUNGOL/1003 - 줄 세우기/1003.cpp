#include <iostream>
#include <stack>
using namespace std;

int n, m, arr[111];
stack<int> res, temp;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        for(int j = 0; j < m; j++) {
            temp.push(res.top());
            res.pop();
        }
        res.push(i+1);
        for(int j = 0; j < m; j++) {
            res.push(temp.top());
            temp.pop();
        }
    }
    for(int i = 0; i < n; i++) {
        temp.push(res.top());
        res.pop();
    }
    for(int i = 0; i < n; i++) {
        cout << temp.top() << " ";
        temp.pop();
    }
}