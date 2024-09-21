#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> v;
    v.push_back(-1000000010);
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(v.back() < a) v.push_back(a);
        else *lower_bound(v.begin(), v.end(), a) = a;
    }
    cout << v.size()-1;
}