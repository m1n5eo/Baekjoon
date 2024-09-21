#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct point {
    double x, y;
};

int result = 0;

int ccw(point a, point b, point c) {
    double CrossProduct = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);

    if(CrossProduct > 0) return 1;
    else if(CrossProduct < 0) return -1;
    else return 0;
}

void backtracking(vector<int> save, vector<bool> check, vector<int> level) {
    if(save.size() == 8) {
        for(int i = 0; i < 8; i++) {
            point aa = {0.0, (double)level[save[i]]};
            point bb = {sqrt(level[save[(i+1)%8]]*level[save[(i+1)%8]]/2.0), sqrt(level[save[(i+1)%8]]*level[save[(i+1)%8]]/2.0)};
            point cc = {(double)level[save[(i+2)%8]], 0.0};

            int k = ccw(aa, bb, cc);

            if(k == 0 || k == -1) {
                if(i == 7) result += 1;
                continue;
            }
            else break;
        }

        return;
    }

    for(int i = 0; i < 8; i++) {
        if(check[i] == false) {
            save.push_back(i);
            check[i] = true;
            
            backtracking(save, check, level);

            save.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    FASTIO

    vector<int> level(8, 0);
    vector<bool> check(11, false);

    for(int i = 0; i < 8; i++) {
        cin >> level[i];
    }

    backtracking({}, check, level);

    cout << result;
}