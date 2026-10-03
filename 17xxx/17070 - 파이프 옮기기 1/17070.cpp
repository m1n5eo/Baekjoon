#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct type {
    int x, y;
};

int n, cnt, arr[22][22];
queue<pair<type, type>> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    q.push({{0, 0}, {0, 1}});

    while(q.size()) {
        int start_x = q.front().first.x, start_y = q.front().first.y;
        int end_x = q.front().second.x, end_y = q.front().second.y;

        q.pop();

        if(start_x == end_x && start_y+1 == end_y) {
            if(end_y+1 < n) {
                if(arr[end_x][end_y+1] == 0) {
                    if(end_x == n-1 && end_y+1 == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x, end_y+1}});
                }
            }
            if(end_x+1 < n && end_y+1 < n) {
                if(arr[end_x+1][end_y+1] == 0 && arr[end_x+1][end_y] == 0 && arr[end_x][end_y+1] == 0) {
                    if(end_x+1 == n-1 && end_y+1 == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x+1, end_y+1}});
                }
            }
        }

        if(start_x+1 == end_x && start_y == end_y) {
            if(end_x+1 < n) {
                if(arr[end_x+1][end_y] == 0) {
                    if(end_x+1 == n-1 && end_y == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x+1, end_y}});
                }
            }
            if(end_x+1 < n && end_y+1 < n) {
                if(arr[end_x+1][end_y+1] == 0 && arr[end_x+1][end_y] == 0 && arr[end_x][end_y+1] == 0) {
                    if(end_x+1 == n-1 && end_y+1 == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x+1, end_y+1}});
                }
            }
        }

        if(start_x+1 == end_x && start_y+1 == end_y) {
            if(end_x+1 < n) {
                if(arr[end_x+1][end_y] == 0) {
                    if(end_x+1 == n-1 && end_y == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x+1, end_y}});
                }
            }
            if(end_y+1 < n) {
                if(arr[end_x][end_y+1] == 0) {
                    if(end_x == n-1 && end_y+1 == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x, end_y+1}});
                }
            }
            if(end_x+1 < n && end_y+1 < n) {
                if(arr[end_x+1][end_y+1] == 0 && arr[end_x+1][end_y] == 0 && arr[end_x][end_y+1] == 0) {
                    if(end_x+1 == n-1 && end_y+1 == n-1) cnt += 1;
                    else q.push({{end_x, end_y}, {end_x+1, end_y+1}});
                }
            }
        }
    }

    cout << cnt;

    return 0;
}