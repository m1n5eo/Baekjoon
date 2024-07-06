#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, k;
vector<int> v;

int main() {
    FASTIO

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    for(int i = 0; i < m; i++) {
        cout << v[i] << " ";
    }
    
    cout << k << " ";

    for(int i = m; i < n; i++) {
        cout << v[i] << " ";
    }
}