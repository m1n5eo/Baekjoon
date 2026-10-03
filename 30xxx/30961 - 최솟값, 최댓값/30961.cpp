#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ulli unsigned long long int

ulli n, temp, result;
vector<ulli> v;

bool compare(ulli a, ulli b) {
    return a < b;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);

        result ^= (ulli)(temp*temp);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n-1; i++) {
        result ^= (ulli)(v[i]*v[i+1]);
    }

    cout << result;

    return 0;
}