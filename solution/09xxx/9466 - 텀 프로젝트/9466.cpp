#include <iostream>
using namespace std;

#define NUM 100001

int t, n, cnt, team[NUM];
bool visited[NUM], complete[NUM];

void dfs(int idx) {
    visited[idx] = true;

    if(visited[team[idx]] == false) {
        dfs(team[idx]);
    }
    else if(complete[team[idx]] == false) {
        for(int i = team[idx]; i != idx; i = team[i]) {
            cnt += 1;
        }
        cnt += 1;
    }

    complete[idx] = true;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> team[i];

            visited[i] = false;
            complete[i] = false;
        }

        cnt = 0;

        for(int i = 1; i <= n; i++) {
            if(visited[i] == false) {
                dfs(i);
            }
        }

        cout << n-cnt << "\n";
    }

    return 0;
}