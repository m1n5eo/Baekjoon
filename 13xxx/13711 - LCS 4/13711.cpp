#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, save[MAX];
vector<int> arr, v, LIS;

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        save[temp] = i;
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(save[temp]);
    }

    for(int i = 0; i < n; i++) {
        if(i == 0 || v.back() < arr[i]) v.push_back(arr[i]);
        else v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
    }

    cout << v.size();
}