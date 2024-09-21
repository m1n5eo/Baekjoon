#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MOD 1000000007

int n, result[5];

int main() {
    FASTIO

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        string temp;
        cin >> temp;

        temp += "XXXXX";

        if(temp[0] == 'U') {
            result[0] += 1;
            if(temp[1] == 'N') {
                result[1] += 1;
                if(temp[2] == 'I') {
                    result[2] += 1;
                    if(temp[3] == 'S') {
                        result[3] += 1;
                        if(temp[4] == 'T') {
                            result[4] += 1;
                        }
                    }
                }
            }
        }
        if(temp[0] == 'N') {
            result[1] += result[0];
            if(temp[1] == 'I') {
                result[2] += result[0];
                if(temp[2] == 'S') {
                    result[3] += result[0];
                    if(temp[3] == 'T') {
                        result[4] += result[0];
                    }
                }
            }
        }
        if(temp[0] == 'I') {
            result[2] += result[1];
            if(temp[1] == 'S') {
                result[3] += result[1];
                if(temp[2] == 'T') {
                    result[4] += result[1];
                }
            }
        }
        if(temp[0] == 'S') {
            result[3] += result[2];
            if(temp[1] == 'T') {
                result[4] += result[2];
            }
        }
        if(temp[0] == 'T') {
            result[4] += result[3];
        }

        for(int i = 0; i < 5; i++) {
            result[i] = result[i]%MOD;
        }
    }

    cout << result[4];
}