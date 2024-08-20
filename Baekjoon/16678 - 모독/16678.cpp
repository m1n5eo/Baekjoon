#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    int n;
    lli result = 0;
    vector<int> v;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        int temp;

        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    if(v[0] != 1) {
        result += (lli)(v[0]-1);
        v[0] = 1;
    }

    for(int i = 0; i < n-1; i++) {
        if(0 <= v[i+1]-v[i] && v[i+1]-v[i] <= 1) {
            continue;
        }

        result += (lli)(v[i+1]-v[i]-1);
        v[i+1] = v[i]+1;
    }

    cout << result;
}