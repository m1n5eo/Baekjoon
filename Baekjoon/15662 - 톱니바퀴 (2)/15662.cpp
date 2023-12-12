#include <iostream>
#include <string>
using namespace std;

int gear[1111][8], diff[1111];

void rotation(int num, int drt) {
    if(drt == -1) {
        int temp = gear[num][0];
        for(int i = 0; i < 7; i++) {
            gear[num][i] = gear[num][i+1];
        }
        gear[num][7] = temp;
    }
    else if(drt == 1) {
        int temp = gear[num][7];
        for(int i = 6; i >= 0; i--) {
            gear[num][i+1] = gear[num][i];
        }
        gear[num][0] = temp;
    }
}

int main() {
    int t;
    cin >> t;

    string s;
    for(int i = 1; i <= t; i++) {
        cin >> s;
        for(int j = 0; j < 8; j++) {
            gear[i][j] = s[j]-'0';
        }
    }

    int n, drt, c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        for(int i = 1; i <= t-1; i++) {
            if(gear[i][2] == gear[i+1][6]) {
                diff[i] = false;
            }
            else diff[i] = true;
        }

        cin >> n >> drt;
        int drtTemp = drt;

        rotation(n, drt);

        for(int i = n; i <= t-1; i++) {
            if(diff[i] == 0) break;
            drtTemp = -drtTemp;
            rotation(i+1, drtTemp);
        }
        drtTemp = drt;
        for(int i = n-1; i >= 1; i--) {
            if(diff[i] == 0) break;
            drtTemp = -drtTemp;
            rotation(i, drtTemp);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= t; i++) {
        if(gear[i][0] == 1) cnt++;
    }
    cout << cnt;
}