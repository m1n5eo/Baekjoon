#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

int n, k;
vector<int> v;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    int result = INF;

    for(int i = 0; i <= k; i++) {
        result = min(result, v[i+(n-k-1)]-v[i]);
    }

    cout << result;
}