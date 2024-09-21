#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

int result;

void bt(int* answer, int bbefore, int before, int cnt, int score) {
    if(cnt == 10) {
        if(score >= 5) result += 1;
        return;
    }

    for(int i = 1; i <= 5; i++) {
        if(bbefore == before && before == i) continue;

        if(answer[cnt] == i) bt(answer, before, i, cnt+1, score+1);
        else bt(answer, before, i, cnt+1, score);
    }
}

int main() {
    FASTIO

    int answer[11];

    for(int i = 0; i < 10; i++) {
        cin >> answer[i];
    }

    bt(answer, 0, 0, 0, 0);

    cout << result;
}