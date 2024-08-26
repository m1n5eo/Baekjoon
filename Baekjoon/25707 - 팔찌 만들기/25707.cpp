#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    int n;
    vector<int> v;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    int result = v[n-1]-v[0];

    for(int i = 0; i < n-1; i++) {
        result += v[i+1]-v[i];
    }

    cout << result;
}