#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool reversed(int a, int b) {
    return a > b;
}

int solve() {
    int n, total = 0;
    cin >> n;
    vector<int> score(n);
    for(int i = 0; i < n; i++) {
        cin >> score[i];
        total += score[i];
    }

    if(n*(n-1)/2 != total) return -1;
    sort(score.begin(), score.end(), reversed);
    int sum = 0, now = 0;
    for(int i = 0; i < n; i++) {
        sum += n-i-1;
        now += score[i];
        if(now > sum) return -1;
    }
    return 1;
}

int main() {
    FASTIO
    cout << solve();
}