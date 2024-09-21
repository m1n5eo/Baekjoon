#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n;
vector<lli> v;

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    lli result = 0;

    for(lli i = 1; i <= n; i++) {
        result += abs(v[i-1]-i);
    }

    cout << result;
}