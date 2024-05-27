#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, temp, cnt, root;
bool check[55];
vector<int> tree;
queue<int> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        tree.push_back(temp);
        
        if(temp == -1) root = i;
    }
    cin >> m;

    if(root == m) {
        cout << 0;
        return 0;
    }

    tree[m] = -2;
    q.push(m);

    while(q.size()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            if(now == tree[i]) {
                q.push(i);
                tree[i] = -2;
            }
        }
    }

    q.push(root);
    check[root] = true;

    while(q.size()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            if(now == tree[i]) {
                check[tree[i]] = false;
                check[i] = true;

                q.push(i);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(check[i] == true) cnt += 1;
    }

    cout << cnt;

    return 0;
}