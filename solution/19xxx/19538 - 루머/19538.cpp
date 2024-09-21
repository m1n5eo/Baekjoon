#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222222

int n, m, k, result[MAX];
vector<int> friends[MAX];
queue<int> bfs;

int main() {
    FASTIO

    cin >> n;

    for(int i = 1; i <= n; i++) {
        result[i] = -1;
    }

    for(int i = 1; i <= n; i++) {
        int temp;

        while(true) {
            cin >> temp;

            if(temp == 0) break;

            friends[i].push_back(temp);
        }
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        bfs.push(temp);

        result[temp] = 0;
    }
    
    while(bfs.size()) {
        stack<int> st;
        k += 1;

        int bfs_size = bfs.size();

        for(int i = 0; i < bfs_size; i++) {
            int now = bfs.front();

            bfs.pop();

            for(int i = 0; i < friends[now].size(); i++) {
                int next = friends[now][i];

                if(result[next] == -1) {
                    int cnt = 0;

                    for(int j = 0; j < friends[next].size(); j++) {
                        if(result[friends[next][j]] != -1) {
                            cnt += 1;
                        }
                    }

                    if(cnt*2 >= friends[next].size()) {
                        st.push(next);
                    }
                }
            }
        }

        while(st.size()) {
            bfs.push(st.top());

            result[st.top()] = k;
            st.pop();
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}