#include <bits/stdc++.h>
using namespace std;

int numMax, idxMax;
int score[5][5];

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> score[i][j];
            score[i][4] += score[i][j];
        }
    }
    for(int i = 0; i < 5; i++) {
        if(score[i][4] > numMax) {
            numMax = score[i][4];
            idxMax = i+1;
        }
    }
    cout << idxMax << " " << numMax << endl;
}