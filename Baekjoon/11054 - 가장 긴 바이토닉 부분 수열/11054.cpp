#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
vector<int> LIS, LDS;
vector<int> hap;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        arr.push_back(k);
        LIS.push_back(1);
        LDS.push_back(1);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j] && LIS[i]+1 > LIS[j]) LIS[j] = LIS[i]+1;
        }
    }
    for(int i = n-1; i >= 0; i--) {
        for(int j = i-1; j >= 0; j--) {
            if(arr[i] < arr[j] && LDS[i]+1 > LDS[j]) LDS[j] = LDS[i]+1;
        }
    }
    for(int i = 0; i < n; i++) hap.push_back(LIS[i]+LDS[i]-1);
    sort(hap.begin(), hap.end());
    printf("%d", hap[n-1]);
}