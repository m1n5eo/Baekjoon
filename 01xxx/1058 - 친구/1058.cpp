#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int n;
bool check[MAX][MAX], friends[MAX][MAX];

int main() {
    FASTIO

    cin >> n;

    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < n; j++) {
            if(str[j] == 'N') {
                check[i][j+1] = false;
                friends[i][j+1] = false;
            }
            else {
                check[i][j+1] = true;
                friends[i][j+1] = true;
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j && check[i][k] == true && check[k][j] == true) {
                    friends[i][j] = true;
                }
            }
        }
    }

    int result = 0;

    for(int i = 1; i <= n; i++) {
        int cnt = 0;

        for(int j = 1; j <= n; j++) {
            if(friends[i][j] == true) {
                cnt += 1;
            }
        }

        result = max(result, cnt);
    }

    cout << result;
}