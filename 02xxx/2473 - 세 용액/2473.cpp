#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321

vector<lli> solve() {
    lli n;
    cin >> n;
    vector<lli> v(n);
    for(lli i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    lli k = INF;
    vector<lli> ret;
    for(lli i = 0; i < n-2; i++) {
        lli find = -v[i];
        lli left = i+1, right = n-1;
        while(left < right) {
            lli sum = v[left] + v[right];
            if(abs(sum-find) < k) {
                k = abs(sum-find);
                ret = {v[i], v[left], v[right]};
            }
            if(sum == find) return {v[i], v[left], v[right]};
            else if(sum < find) left += 1;
            else if(sum > find) right -= 1;
        }
    }
    return ret;
}

int main() {
    FASTIO
    for(lli s : solve()) cout << s << " ";
}