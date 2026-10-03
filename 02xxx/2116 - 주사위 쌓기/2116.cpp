#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int n, result = 0;
vector<vector<int>> dice(MAX, vector<int>(6, 0));

int find_dice(int a, int b) {
    if((a == 6 || b == 6) && (a == 5 || b == 5)) return 4;
    else if(a == 6 || b == 6) return 5;
    else return 6;
}

void func(int cnt, int up, int down, int sum) {
    if(cnt == n-1) {
        result = max(result, sum);
        return;
    }

    for(int i = 0; i < 6; i++) {
        if(down == dice[cnt+1][i]) {
            if(i == 0) func(cnt+1, down, dice[cnt+1][5], sum+find_dice(down, dice[cnt+1][5]));
            else if(i == 1) func(cnt+1, down, dice[cnt+1][3], sum+find_dice(down, dice[cnt+1][3]));
            else if(i == 2) func(cnt+1, down, dice[cnt+1][4], sum+find_dice(down, dice[cnt+1][4]));
            else if(i == 3) func(cnt+1, down, dice[cnt+1][1], sum+find_dice(down, dice[cnt+1][1]));
            else if(i == 4) func(cnt+1, down, dice[cnt+1][2], sum+find_dice(down, dice[cnt+1][2]));
            else if(i == 5) func(cnt+1, down, dice[cnt+1][0], sum+find_dice(down, dice[cnt+1][0]));
            return;
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    func(0, dice[0][0], dice[0][5], find_dice(dice[0][0], dice[0][5]));
    func(0, dice[0][1], dice[0][3], find_dice(dice[0][1], dice[0][3]));
    func(0, dice[0][2], dice[0][4], find_dice(dice[0][2], dice[0][4]));
    func(0, dice[0][3], dice[0][1], find_dice(dice[0][3], dice[0][1]));
    func(0, dice[0][4], dice[0][2], find_dice(dice[0][4], dice[0][2]));
    func(0, dice[0][5], dice[0][0], find_dice(dice[0][5], dice[0][0]));

    cout << result;
}