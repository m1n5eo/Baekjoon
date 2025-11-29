#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<int> solve() {
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        vec.push_back(temp);
    }

    int cnt = 0;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n-1; i++) {
        if(vec[i]+1 == vec[i+1]) {
            int j = i+1;
            while(j < n && vec[i+1] == vec[j]) j += 1;
            if(j < n) swap(vec[i+1], vec[j]);
            else {
                int lb = lower_bound(vec.begin()+i+1, vec.end(), vec[i+1]) - vec.begin();
                int ub = upper_bound(vec.begin()+i+1, vec.end(), vec[i+1]) - vec.begin();
                int k = i-cnt;
                for(int i = lb; i < ub; i++) {
                    swap(vec[k], vec[i]);
                    k += 1;
                }
            }
        }
        else if(vec[i] == vec[i+1]) cnt += 1;
        else if(vec[i]+1 != vec[i+1]) cnt = 0;
    }
    return vec;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    for(int s : sol) cout << s << " ";
}