#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int building, start, goal, up, down;
bool visited[1111111];
queue<pair<int, int>> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> building >> start >> goal >> up >> down;

    q.push({start, 0});
    visited[start] = true;

    while(q.size()) {
        int now = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if(now == goal) {
            cout << cnt;

            return 0;
        }

        visited[now] = true;

        if(now+up <= building && visited[now+up] == false) {
            q.push({now+up, cnt+1});
            visited[now+up] = true;
        }
        if(now-down > 0 && visited[now-down] == false) {
            q.push({now-down, cnt+1});
            visited[now-down] = true;
        }
    }

    cout << "use the stairs";

    return 0;
}