#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int result;

void func(int idx, int sum, int n, int s, vector<int> v) {
    sum += v[idx];

    if(idx >= n) return;
    else if(sum == s) result += 1;

    func(idx+1, sum, n, s, v);
    func(idx+1, sum-v[idx], n, s, v);
}

int main() {
    FASTIO
    
    int n, s, temp;
    vector<int> v;

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    func(0, 0, n, s, v);

    cout << result;
}