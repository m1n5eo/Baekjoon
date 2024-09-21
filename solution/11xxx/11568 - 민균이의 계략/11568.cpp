#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
vector<int> arr, LIS;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
        LIS.push_back(1);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                if(LIS[i]+1 > LIS[j]) {
                    LIS[j] = LIS[i] + 1;
                }
            }
        }
    }
    
    sort(LIS.begin(), LIS.end(), compare);

    cout << LIS[n-1];
}