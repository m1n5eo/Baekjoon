#include <iostream>
#include <string>
using namespace std;

int n, temp_cnt, res[2], map[111][111];
string str;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < n; j++) {
            if(str[j] == '.') map[i][j] = 0;
            else if(str[j] == 'X') map[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 0) temp_cnt += 1;
            else temp_cnt = 0;

            if(temp_cnt == 2) res[0] += 1; 
        }
        temp_cnt = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[j][i] == 0) temp_cnt += 1;
            else temp_cnt = 0;

            if(temp_cnt == 2) res[1] += 1; 
        }
        temp_cnt = 0;
    }

    cout << res[0] << " " << res[1];

    return 0;
}