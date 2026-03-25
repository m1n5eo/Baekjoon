#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<vector<int>> operation(vector<vector<int>> array, int n, int l, int mode) {
    int k = (1<<l), t = (1<<(n-l));
    vector<vector<int>> ret = array;
    for(int x = 0; x < t; x++) {
        for(int y = 0; y < t; y++) {
            int dx = x*k, dy = y*k, ax, ay;
            if(mode == 5) ax = (t-x-1)*k, ay = y*k;
            else if(mode == 6) ax = x*k, ay = (t-y-1)*k;
            else if(mode == 7) ax = (t-y-1)*k, ay = x*k;
            else if(mode == 8) ax = y*k, ay = (t-x-1)*k;
            for(int i = 0; i < k; i++) {
                for(int j = 0; j < k; j++) {
                    if(mode == 1) ax = dx+k-i-i-1, ay = dy;
                    else if(mode == 2) ax = dx, ay = dy+k-j-j-1;
                    else if(mode == 3) ax = dx+k-i-j-1, ay = dy+i-j;
                    else if(mode == 4) ax = dx-i+j, ay = dy+k-i-j-1;
                    ret[i+dx][j+dy] = array[i+ax][j+ay];
                }
            }
        }
    }
    return ret;
}

vector<vector<int>> solution() {
    int n, round;
    cin >> n >> round;
    vector<vector<int>> array((1<<n), vector<int>((1<<n)));
    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < (1<<n); j++) {
            cin >> array[i][j];
        }
    }
    for(int _ = 0; _ < round; _++) {
        int k, l; cin >> k >> l;
        array = operation(array, n, l, k);
    }
    return array;
}

int main() {
    FASTIO
    for(vector<int> sol : solution()) {
        for(int s : sol) cout << s << " ";
        cout << "\n";
    }
}