#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct point {
    int x, y;
};

int n, m, result;
string in;
vector<vector<int>> paper;

void solve(point start, point end, int score) {
    if(start.x > end.x || start.y > end.y) return;

    if(start.y != end.y) {
        int s1 = 0, s2 = 0;
        for(int i = start.x; i <= end.x; i++) {
            s1 = s1*10 + paper[i][start.y];
            s2 = s2*10 + paper[i][end.y];
        }
        solve({start.x, start.y+1}, end, score + s1);
        solve(start, {end.x, end.y-1}, score + s2);
    }
    else if(start.y == end.y) {
        int s1 = 0, s2 = 0;
        for(int i = start.x; i <= end.x; i++) {
            s1 = s1*10 + paper[i][start.y];
            s2 = s2*10 + paper[i][end.y];
        }
        result = max(result, score + s1);
        result = max(result, score + s2);
    }

    if(start.x != end.x) {
        int s1 = 0, s2 = 0;
        for(int j = start.y; j <= end.y; j++) {
            s1 = s1*10 + paper[start.x][j];
            s2 = s2*10 + paper[end.x][j];
        }
        solve({start.x+1, start.y}, end, score + s1);
        solve(start, {end.x-1, end.y}, score + s2);
    }
    else {
        int s1 = 0, s2 = 0;
        for(int j = start.y; j <= end.y; j++) {
            s1 = s1*10 + paper[start.x][j];
            s2 = s2*10 + paper[end.x][j];
        }
        result = max(result, score + s1);
        result = max(result, score + s2);
    }
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> in;

        paper.push_back(vector<int>(0));
        for(int j = 0; j < m; j++) {
            paper[i].push_back(in[j] - '0');
        }
    }

    solve({0, 0}, {n-1, m-1}, 0);

    cout << (n == 1 && m == 1? paper[0][0] : result);
}