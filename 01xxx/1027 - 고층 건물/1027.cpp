#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n;
int building[55], cnt[55];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> building[i];
    }

    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            double tilt = (double)abs(building[j]-building[i])/(double)(j-i);
            int sw = 0;

            for(int k = i+1; k <= j-1; k++) {
                if(max(building[i], building[j]) <= building[k]) {
                    sw = 1;
                    break;
                }
                else if(min(building[i], building[j]) > building[k]) {
                    continue;
                }
                else if(building[i] < building[j]) {
                    double tilt_temp = (double)abs(building[k]-building[i])/(double)(k-i);

                    if(tilt_temp >= tilt) {
                        sw = 1;
                        break;
                    }
                }
                else if(building[i] > building[j]) {
                    double tilt_temp = (double)abs(building[j]-building[k])/(double)(j-k);

                    if(tilt_temp >= tilt) {
                        sw = 1;
                        break;
                    }
                }
                else if(building[i] == building[j]) {
                    if(building[k] >= building[i]) {
                        sw = 1;
                        break;
                    }
                }
            }

            if(sw == 0) {
                cnt[i] += 1;
                cnt[j] += 1;
            }
        }
    }

    int res = 0;

    for(int i = 0; i < n; i++) {
        res = max(res, cnt[i]);
    }

    cout << res;

    return 0;
}