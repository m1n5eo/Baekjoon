#include <bits/stdc++.h>
using namespace std;

int main() {
    char LastWin = 0;
    int scoreA = 0, scoreB = 0;
    int cardA[10], cardB[10];
    for(int i = 0; i < 10; i++) scanf("%d", &cardA[i]);
    for(int i = 0; i < 10; i++) scanf("%d", &cardB[i]);
    for(int i = 0; i < 10; i++) {
        if(cardA[i] > cardB[i]) {
            scoreA += 3;
            LastWin = 'A';
        }
        else if(cardA[i] < cardB[i]) {
            scoreB += 3;
            LastWin = 'B';
        }
        else {
            scoreA++;
            scoreB++;
        }
    }
    printf("%d %d\n", scoreA, scoreB);
    if(scoreA > scoreB || (scoreA == scoreB && LastWin == 'A')) printf("A");
    else if(scoreA < scoreB || (scoreA == scoreB && LastWin == 'B')) printf("B");
    else printf("D");
}
