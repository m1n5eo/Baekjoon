#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, a, b, l, x, arr[111][111];
int ii = 1, jj = 1, t = 0, snakeDrt = 0;
char d;
queue<pair<int,char>> drt;
deque<pair<int,int>> snake;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = 4;
    }
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> x >> d;
        drt.push({x, d});
    }

    while(true) {
        if(ii < 1 || ii > n || jj < 1 || jj > n) break;
        else if(arr[ii][jj] == 1) break;

        if(arr[ii][jj] == 0) {
            arr[ii][jj] = 1;
            if(!snake.empty()) {
                arr[snake.front().first][snake.front().second] = 0;
                snake.pop_front();
            }
            snake.push_back({ii, jj});
        }
        else if(arr[ii][jj] == 4) {
            arr[ii][jj] = 1;
            snake.push_back({ii, jj});
        }

        if(drt.front().first == t) {
            if(drt.front().second == 'D') {
                if(0 <= snakeDrt && snakeDrt <= 2) snakeDrt += 1;
                else snakeDrt = 0;
            }
            else if(drt.front().second == 'L') {
                if(1 <= snakeDrt && snakeDrt <= 3) snakeDrt -= 1;
                else snakeDrt = 3;
            }
            drt.pop();
        }

        if(snakeDrt == 0) jj = jj+1;
        else if(snakeDrt == 1) ii = ii+1;
        else if(snakeDrt == 2) jj = jj-1;
        else if(snakeDrt == 3) ii = ii-1;

        t = t+1;
    }
    cout << t;
}