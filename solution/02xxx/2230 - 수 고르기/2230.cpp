#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int solution() {
    int n, m;
    cin >> n >> m;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];
    sort(array.begin(), array.end());

    int left = 0, right = 0, ret = INF;
    while(right < n) {
        int diff = array[right] - array[left];
        if(diff >= m && diff < ret) ret = diff;

        if(left == right) right += 1;
        else if(diff == m) break;
        else if(diff > m) left += 1;
        else if(diff < m) right += 1;
    }
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}