#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MOD 1000000009
#define MAX 1111111

int main() {
    FASTIO

    vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);

    for(int i = 4; i < MAX; i++) {
        v.push_back(((v[i-1]+v[i-2])%MOD+v[i-3])%MOD);
    }

    int t, n;
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        cout << v[n] << "\n";
    }
}