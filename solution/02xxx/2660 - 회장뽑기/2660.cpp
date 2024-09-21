#include <bits/stdc++.h>
using namespace std;

int friends[55][55], score[55];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, a, b;

    cin >> n;
    while(1) {
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j && friends[i][k] && friends[k][j]) {
                    if(friends[i][j] == 0) friends[i][j] = friends[i][k]+friends[k][j];
                    else if(friends[i][j] > friends[i][k]+friends[k][j]) friends[i][j] = friends[i][k]+friends[k][j];
                }
            }
        }
    }
    int minScore = 0x7fffffff, minScoreCnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(friends[i][j] && score[i] == 0) score[i] = friends[i][j];
            else if(friends[i][j] && score[i]) score[i] = max(friends[i][j], score[i]);
        }
        minScore = min(minScore, score[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(minScore == score[i]) minScoreCnt++;
    }
    cout << minScore << " " << minScoreCnt << "\n";
    for(int i = 1; i <= n; i++) {
        if(minScore == score[i]) cout << i << " ";
    }
}