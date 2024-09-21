#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

vector<int> vec;
map<int, int> cnt;

bool compare(int a, int b) {
    if(cnt[a] != cnt[b]) return cnt[a] < cnt[b];
    else return a < b;
}

int main() {
    FASTIO
    
    int n, m, k, r = 3, c = 3, array[MAX][MAX];
    bool stop_point = true;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            array[i][j] = 0;
        }
    }
    
    cin >> n >> m >> k;

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> array[i][j];
        }
    }

    for(int t = 0; t <= 100 && stop_point; t++) {
        if(array[n][m] == k) {
            cout << t;
            stop_point = false;
            break;
        }

        if(r >= c) {
            int save = c;

            for(int i = 1; i <= r; i++) {
                vec.clear();
                cnt.clear();

                for(int j = 1; j <= save; j++) {
                    if(array[i][j] == 0) continue;
                    else if(cnt.find(array[i][j]) != cnt.end()) {
                        cnt[array[i][j]] += 1;
                    }
                    else {
                        cnt.insert({array[i][j], 1});
                        vec.push_back(array[i][j]);
                    }
                }

                sort(vec.begin(), vec.end(), compare);

                int vec_size = vec.size();

                for(int j = 1; j <= vec_size; j++) {
                    array[i][j*2-1] = vec[j-1];
                    array[i][j*2] = cnt[vec[j-1]];
                }

                for(int j = vec_size*2+1; j <= save; j++) array[i][j] = 0;

                if(i == 1) c = vec_size*2;
                else c = max(c, vec_size*2);
            }
        }
        else {
            int save = r;

            for(int j = 1; j <= c; j++) {
                vec.clear();
                cnt.clear();

                for(int i = 1; i <= save; i++) {
                    if(array[i][j] == 0) continue;
                    else if(cnt.find(array[i][j]) != cnt.end()) {
                        cnt[array[i][j]] += 1;
                    }
                    else {
                        cnt.insert({array[i][j], 1});
                        vec.push_back(array[i][j]);
                    }
                }

                sort(vec.begin(), vec.end(), compare);

                int vec_size = vec.size();

                for(int i = 1; i <= vec_size; i++) {
                    array[i*2-1][j] = vec[i-1];
                    array[i*2][j] = cnt[vec[i-1]];
                }

                for(int i = vec_size*2+1; i <= save; i++) array[i][j] = 0;

                if(j == 1) r = vec_size*2;
                else r = max(r, vec_size*2);
            }
        }

        if(r > 100) r = 100;
        if(c > 100) c = 100;
    }

    if(stop_point == true) {
        cout << -1 << "\n";
    }
}