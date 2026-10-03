#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, temp, sum;
vector<int> v;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    // cin.tie(NULL); cout.tie(NULL);
    // ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    if(n == 1) {
        cout << v[0];
        return 0;
    }
    else if(n == 2) {
        cout << max(v[0]+v[1], v[0]*v[1]);
        return 0;
    }

    sort(v.begin(), v.end(), compare);

    int idx[2] = {0, n-1};

    while(idx[0]+1 < n) {
        if(v[idx[0]] < 0 && v[idx[0]+1] < 0) {
            sum += v[idx[0]]*v[idx[0]+1];
            idx[0] += 2;
        }
        else break;
    }
    
    while(idx[1]-1 >= 0) {
        if(v[idx[1]] > 0 && v[idx[1]-1] > 0) {
            sum += max(v[idx[1]]+v[idx[1]-1], v[idx[1]]*v[idx[1]-1]);
            idx[1] -= 2;
        }
        else break;
    }

    while(idx[0] <= idx[1]) {
        if(v[idx[0]] < 0 && v[idx[0]+1] == 0) {
            idx[0] += 2;
        }
        else if(v[idx[0]] < 0 && v[idx[0]+1] > 0) {
            sum += v[idx[0]];
            idx[0] += 1;
        }
        else if(v[idx[1]] >= 0) {
            sum += v[idx[1]];
            idx[1] -= 1;
        }
    }

    cout << sum;

    return 0;
}