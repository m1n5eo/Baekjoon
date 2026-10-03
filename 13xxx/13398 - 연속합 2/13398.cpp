#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solution() {
    int n;
    cin >> n;
    vector<int> array(n), left(n), right(n);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
        left[i] = array[i];
        right[i] = array[i];
    }

    int ret = array[0];
    for(int i = 1; i < n; i++) left[i] = max(left[i], left[i-1] + array[i]);
    for(int i = n-2; i >= 0; i--) right[i] = max(right[i], right[i+1] + array[i]);
    for(int i = 1; i < n-1; i++) ret = max(ret, left[i-1] + right[i+1]);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    return max(ret, max(left[n-1], right[n-1]));
}

int main() {
    FASTIO
    cout << solution();
}