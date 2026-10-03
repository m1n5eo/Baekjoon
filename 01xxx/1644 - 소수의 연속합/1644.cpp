#include <iostream>
using namespace std;

int sosu_temp[4444444], sosu[4444444];

int main() {
    for(int i = 2; i <= 4000000; i++) {
        if(sosu[i]) continue;
        else {
            sosu[i] = 1;
            for(int j = 2; i*j <= 4000000; j++) sosu[i*j] = 2;
        }
    }

    int temp = 0;
    for(int i = 2; i <= 4000000; i++) {
        if(sosu[i] == 1) sosu_temp[temp++] = i;
        else if(sosu[i] == 2) sosu[i] = 0;
    }
    for(int i = 0; i < temp; i++) {
        for(int j = i+1; j < temp; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += sosu_temp[k];
                if(sum > 4000000) {
                    j = temp;
                    break;
                }
                else if(k == j) sosu[sum]++;
            }
        }
    }

    int n;
    cin >> n;
    cout << sosu[n];
}