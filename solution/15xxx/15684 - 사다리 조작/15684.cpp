#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 33

int n, m, h, answer = 4;
vector<vector<bool>> sadari(MAX, vector<bool>(MAX, false));

bool check() {
    for(int i = 1; i <= n; i++) {
        int start = i;
        for(int j = 1; j <= h; j++) {
            if(sadari[j][start-1]) start -= 1;
            else if(sadari[j][start]) start += 1;
        }
        if(i != start) return false;
    }
    return true;
}

void bt(int cnt, int x) {
    if(answer <= cnt) return;
    if(check()) {
        answer = min(answer, cnt);
        return;
    }
    if(cnt == 3) return;
    for(int i = x; i <= h; i++) {
        for(int j = 1; j < n; j++) {
            if(!sadari[i][j] && !sadari[i][j+1] && !sadari[i][j-1]) {
                sadari[i][j] = true;
                bt(cnt+1, i);
                sadari[i][j] = false;
            }
        }
    }
}

int solution() {
    cin >> n >> m >> h;
    for(int _ = 0; _ < m; _++) {
        int a, b; cin >> a >> b;
        sadari[a][b] = true;
    }
    bt(0, 1);
    return answer < 4? answer : -1;
}

int main() {
    FASTIO
    cout << solution();
}