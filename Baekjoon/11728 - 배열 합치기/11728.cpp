#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m;
vector<int> v;

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n+m; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < n+m; i++) {
        cout << v[i] << " ";
    }
}