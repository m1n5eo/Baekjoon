#include <iostream>
using namespace std;

int cnt[4][4], score[4], temp, n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> temp;
            score[j] += temp;
            cnt[j][temp]++;
        }
    }
    int win = 1;
    for(int i = 2; i <= 3; i++) {
        if(score[win] < score[i]) win = i;
        else if(score[win] == score[i] && cnt[win][3] < cnt[i][3]) win = i;
        else if(score[win] == score[i] && cnt[win][3] == cnt[i][3] && cnt[win][2] < cnt[i][2]) win = i;
    }
    for(int i = 1; i <= 3; i++) {
        if(win == i) continue;
        if(score[win] == score[i] && cnt[win][3] == cnt[i][3] && cnt[win][2] == cnt[i][2]) {
            cout << 0 << " " << score[i];
            return 0;
        }
    }
    cout << win << " " << score[win];
}