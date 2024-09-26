#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 5555

bool compare(int x, int y) {
    return x < y;
}

int main() {
    FASTIO

    int n, k, temp, sum = 0;
    vector<int> v;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = n-1; i >= n-k; i--) {
        sum += v[i]-(n-i-1);
    }
    
    cout << sum;
}
