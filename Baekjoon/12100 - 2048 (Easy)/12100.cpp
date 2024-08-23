#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 22

int n, result;

vector<vector<int>> move(int mode, vector<vector<int>> map) {
    if(mode == 0) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            bool sw = true;

            for(int i = 0; i < n; i++) {
                if(map[i][j] != 0) {
                    if(cnt != 0 && map[i][j] == map[cnt-1][j] && sw == true) {
                        map[cnt-1][j] *= 2;
                        if(i != cnt-1) map[i][j] = 0;
                        sw = false;
                    }
                    else {
                        map[cnt][j] = map[i][j];
                        if(i != cnt) map[i][j] = 0;
                        cnt += 1;
                        sw = true;
                    }
                }

                result = max(result, map[i][j]);
            }
        }
    }
    else if(mode == 1) {
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            bool sw = true;

            for(int j = 0; j < n; j++) {
                if(map[i][j] != 0) {
                    if(cnt != 0 && map[i][j] == map[i][cnt-1] && sw == true) {
                        map[i][cnt-1] *= 2;
                        if(j != cnt-1) map[i][j] = 0;
                        sw = false;
                    }
                    else {
                        map[i][cnt] = map[i][j];
                        if(j != cnt) map[i][j] = 0;
                        cnt += 1;
                        sw = true;
                    }
                }

                result = max(result, map[i][j]);
            }
        }
    }
    else if(mode == 2) {
        for(int j = 0; j < n; j++) {
            int cnt = n-1;
            bool sw = true;

            for(int i = n-1; i >= 0; i--) {
                if(map[i][j] != 0) {
                    if(cnt != n-1 && map[i][j] == map[cnt+1][j] && sw == true) {
                        map[cnt+1][j] *= 2;
                        if(i != cnt+1) map[i][j] = 0;
                        sw = false;
                    }
                    else {
                        map[cnt][j] = map[i][j];
                        if(i != cnt) map[i][j] = 0;
                        cnt -= 1;
                        sw = true;
                    }
                }

                result = max(result, map[i][j]);
            }
        }
    }
    else if(mode == 3) {
        for(int i = 0; i < n; i++) {
            int cnt = n-1;
            bool sw = true;

            for(int j = n-1; j >= 0; j--) {
                if(map[i][j] != 0) {
                    if(cnt != n-1 && map[i][j] == map[i][cnt+1] && sw == true) {
                        map[i][cnt+1] *= 2;
                        if(j != cnt+1) map[i][j] = 0;
                        sw = false;
                    }
                    else {
                        map[i][cnt] = map[i][j];
                        if(j != cnt) map[i][j] = 0;
                        cnt -= 1;
                        sw = true;
                    }
                }

                result = max(result, map[i][j]);
            }
        }
    }
    
    return map;
}

void dfs(int cnt, vector<vector<int>> map) {
    if(cnt-1 == 5) return;

    for(int k = 0; k < 4; k++) {
        vector<vector<int>> next_map = move(k, map);
        dfs(cnt+1, next_map);
    }
}

int main() {
    FASTIO
    
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    dfs(0, map);

    cout << result;
}