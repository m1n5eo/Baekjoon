#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(long long int a, long long int b) {
    return a < b;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    long long int temp;
    vector<long long int> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 1, max_cnt = 1;
    long long int res = v[0];

    for(int i = 1; i < n; i++) {
        if(v[i] == v[i-1]) {
            cnt += 1;
        }
        else if(v[i] != v[i-1]) {
            if(max_cnt < cnt) {
                max_cnt = cnt;
                res = v[i-1];
            }
            cnt = 1;
        }
    }

    if(max_cnt < cnt) res = v[n-1];

    cout << res;

    return 0;
}