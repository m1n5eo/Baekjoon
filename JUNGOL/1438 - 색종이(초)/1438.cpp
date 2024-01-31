#include <iostream>
using namespace std;

int paper[111][111];

int main() {
    int n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        for(int i = x; i < x+10; i++) {
            for(int j = y; j < y+10; j++) {
                paper[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(paper[i][j] == 1) {
                cnt += 1;
            }
        }
    }
    cout << cnt;
}