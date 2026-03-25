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
            if(mode == 5) ax = t-x-1, ay = y;
            else if(mode == 6) ax = x, ay = t-y-1;
            else if(mode == 7) ax = t-y-1, ay = x;
            else if(mode == 8) ax = y, ay = t-x-1;
            for(int i = 0; i < k; i++) {
                for(int j = 0; j < k; j++) {
                    if(mode == 1) ret[i+dx][j+dy] = array[k-i-1+dx][j+dy];
                    else if(mode == 2) ret[i+dx][j+dy] = array[i+dx][k-j-1+dy];
                    else if(mode == 3) ret[i+dx][j+dy] = array[k-j-1+dx][i+dy];
                    else if(mode == 4) ret[i+dx][j+dy] = array[j+dx][k-i-1+dy];
                    else if(5 <= mode && mode <= 8) ret[i+dx][j+dy] = array[i+ax*k][j+ay*k];
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