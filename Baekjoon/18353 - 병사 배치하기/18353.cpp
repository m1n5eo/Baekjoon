#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2222

int n, arr[MAX];
vector<int> v;

int main() {
    FASTIO

    cin >> n;

    for(int i = n-1; i >= 0; i--) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        if(i == 0 || v.back() < arr[i]) v.push_back(arr[i]);
        else v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
    }

    cout << n-v.size();
}