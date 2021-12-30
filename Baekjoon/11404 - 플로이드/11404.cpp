#include <bits/stdc++.h>
using namespace std;

int cityNum, busNum, startBus, endBus, cost;
int city[101][101];

int main() {
    cin >> cityNum >> busNum;
    for(int i = 0; i < busNum; i++) {
        cin >> startBus >> endBus >> cost;
        if(city[startBus][endBus] && city[startBus][endBus] > cost) city[startBus][endBus] = cost;
        else if(!city[startBus][endBus]) city[startBus][endBus] = cost;
    }
    for(int i = 1; i <= cityNum; i++) {
        for(int j = 1; j <= cityNum; j++) {
            if(!city[i][j] && i != j) city[i][j] = 123456789;
        }
    }
    for(int i = 1; i <= cityNum; i++) {
        for(int j = 1; j <= cityNum; j++) {
            for(int k = 1; k <= cityNum; k++) {
                if(city[j][k] > city[j][i] + city[i][k]) city[j][k] = city[j][i] + city[i][k];
            }
        }
    }
    for(int i = 1; i <= cityNum; i++) {
        for(int j = 1; j <= cityNum; j++) {
            if(city[i][j] == 123456789) cout << "0 ";
            else cout << city[i][j] << " ";
        }
        cout << endl;
    }
}