#include <iostream>
#include <string>
using namespace std;

int gear[4][8];

void rotation(int n, int drt) {
    if(drt == -1) {
        int temp = gear[n][0];
        for(int i = 0; i < 7; i++) {
            gear[n][i] = gear[n][i+1];
        }
        gear[n][7] = temp;
    }
    else if(drt == 1) {
        int temp = gear[n][7];
        for(int i = 6; i >= 0; i--) {
            gear[n][i+1] = gear[n][i];
        }
        gear[n][0] = temp;
    }
}

int main() {
    string s;
    for(int i = 1; i <= 4; i++) {
        cin >> s;
        for(int j = 0; j < 8; j++) {
            gear[i][j] = s[j]-'0';
        }
    }

    int k, num, drt, drtTemp;
    bool diff[11];
    cin >> k;
    for(int c = 0; c < k; c++) {
        for(int i = 1; i <= 3; i++) {
            if(gear[i][2] == gear[i+1][6]) {
                diff[i] = false;
            }
            else {
                diff[i] = true;
            }
        }
        cin >> num >> drt;
        drtTemp = drt;

        rotation(num, drt);

        if(num == 1) {
            for(int i = 1; i <= 3; i++) {
                drtTemp = -drtTemp;
                if(diff[i] == true) {
                    rotation(i+1, drtTemp);
                }
                else {
                    break;
                }
            }
        }
        else if(num == 2) {
            if(diff[1] == true) {
                rotation(1, -drt);
            }
            if(diff[2] == true) {
                rotation(3, -drt);
                if(diff[3] == true) {
                    rotation(4, drt);
                }
            }
        }
        else if(num == 3) {
            if(diff[3] == true) {
                rotation(4, -drt);
            }
            if(diff[2] == true) {
                rotation(2, -drt);
                if(diff[1] == true) {
                    rotation(1, drt);
                }
            }
        }
        else if(num == 4) {
            for(int i = 3; i >= 1; i--) {
                drtTemp = -drtTemp;
                if(diff[i] == true) {
                    rotation(i, drtTemp);
                }
                else {
                    break;
                }
            }
        }
    }

    int sum = 0, temp = 1;
    for(int i = 1; i <= 4; i++) {
        sum += gear[i][0]*temp;
        temp *= 2;
    }
    cout << sum;
}